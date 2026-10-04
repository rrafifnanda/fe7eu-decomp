#!/usr/bin/env python3
"""Validate that FE7J C functions link to byte-identical EU code.

Approach: for every `refs/fe7j/src/*.c`, compile with agbcc +
`-ffunction-sections`, then link the whole object once with every mapped
function section placed at its EU address (other sections are left as orphans,
external symbols are provided via `PROVIDE`). Functions whose linked bytes match
the ROM are ready to replace the asm in the build.

Usage (inside `nix develop`):
    python3 scripts/validate_c_functions.py --fe7j refs/fe7j --rom rom/fe7eu.gba \
        --out config/c-validation-report.md
"""
import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

import port_symbols as ps

CC = "tools/agbcc/agbcc"
CFLAGS = ["-g", "-mthumb-interwork", "-Wimplicit", "-Wparentheses",
          "-fhex-asm", "-ffix-debug-line", "-ffunction-sections"]
O_FLAGS = {
    "irq.c": "-O0", "random.c": "-O0", "agb-sram.c": "-O1",
    "hardware.c": "-O0", "move-data.c": "-O0", "oam.c": "-O0",
}
SYMBOLS_LD = "build/c-validate/symbols.ld"


def compile_file(fe7j, src, build):
    asm = build / f"{src.stem}.s"
    obj = build / f"{src.stem}.o"
    cpp = subprocess.run(
        ["arm-none-eabi-cpp", f"-I{fe7j}/tools/agbcc/include",
         "-iquote", f"{fe7j}/include", "-iquote", str(fe7j),
         "-nostdinc", "-undef", str(src)],
        capture_output=True)
    if cpp.returncode != 0:
        return None, "cpp failed"
    iconv = subprocess.run(["iconv", "-f", "UTF-8", "-t", "CP932"],
                           input=cpp.stdout, capture_output=True)
    pp = iconv.stdout if iconv.returncode == 0 else cpp.stdout
    flags = [f for f in CFLAGS if not f.startswith("-O")]
    flags.append(O_FLAGS.get(src.name, "-O2"))
    cc = subprocess.run([CC, *flags, "-o", str(asm)], input=pp, capture_output=True)
    if cc.returncode != 0 or not asm.exists():
        return None, "agbcc failed"
    with asm.open("a") as fh:
        fh.write(".text\n\t.align\t2, 0\n")
    ret = subprocess.run(
        ["arm-none-eabi-as", "-mcpu=arm7tdmi", "-I", str(fe7j / "include"),
         str(asm), "-o", str(obj)], capture_output=True)
    if ret.returncode != 0:
        return None, "as failed"
    return obj, None


def sections(obj):
    out = subprocess.run(["arm-none-eabi-objdump", "-h", str(obj)],
                         capture_output=True, text=True).stdout
    result = {}
    for line in out.splitlines():
        m = re.match(r"\s*\d+\s+(\.text\.\S+)\s+([0-9a-f]+)", line)
        if m:
            result[m.group(1)] = int(m.group(2), 16)
    return result


def section_bytes(obj, name, out_path):
    if out_path.exists():
        out_path.unlink()
    ret = subprocess.run(["arm-none-eabi-objcopy", "-O", "binary",
                          f"--only-section={name}", str(obj), str(out_path)],
                         capture_output=True)
    if ret.returncode != 0 or not out_path.exists():
        return None
    return out_path.read_bytes()


def undefined_symbols(obj):
    out = subprocess.run(["arm-none-eabi-nm", "-u", str(obj)],
                         capture_output=True, text=True).stdout
    names = []
    for line in out.splitlines():
        parts = line.split()
        if parts:
            names.append(parts[-1])
    return [n for n in names if re.match(r"[A-Za-z_]\w*$", n)]


def link_object(obj, placed, build, placeholders):
    """placed: list of (input_section, addr, output_section)."""
    script = build / f"{obj.stem}_link.ld"
    lines = [f"OUTPUT_ARCH(arm)", f"INCLUDE {Path(SYMBOLS_LD).resolve()}"]
    for name, addr in placeholders.items():
        lines.append(f"PROVIDE({name} = 0x{addr:08X});")
    lines.append("SECTIONS {")
    for sec, addr, out in placed:
        lines.append(f"    {out} 0x{addr:08X} : ALIGN(4) {{ {obj}({sec}) }}")
    lines.append("    .orphans 0x08180000 : {"
                 " *(.text) *(.text.*) *(.rodata) *(.rodata.*)"
                 " *(.data) *(.data.*) *(.bss) *(.bss.*) }")
    lines.append("}")
    script.write_text("\n".join(lines) + "\n")

    elf = build / f"{obj.stem}.elf"
    ret = subprocess.run(["arm-none-eabi-ld", "-T", str(script), "-o", str(elf), str(obj)],
                         capture_output=True)
    if ret.returncode == 0:
        return elf, None
    missing = re.findall(r"undefined reference to `([^']+)'", ret.stderr.decode(errors="replace"))
    return None, missing


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--fe7j", default="refs/fe7j")
    ap.add_argument("--rom", default="rom/fe7eu.gba")
    ap.add_argument("--out", default="config/c-validation-report.md")
    ap.add_argument("--build", default="build/c-validate")
    args = ap.parse_args()

    fe7j = Path(args.fe7j)
    build = Path(args.build)
    build.mkdir(parents=True, exist_ok=True)
    rom = Path(args.rom).read_bytes()

    mapped = {}
    for line in Path("config/eu-symbols-all.txt").read_text().splitlines():
        m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);", line)
        if m:
            mapped[m.group(1)] = int(m.group(2), 16)

    provides = {}
    extra_path = Path("config/fe7j-symbols-extra.txt")
    if extra_path.exists():
        for line in extra_path.read_text().splitlines():
            m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);", line)
            if m:
                provides[m.group(1)] = int(m.group(2), 16)

    # mark Thumb functions with the low address bit so the linker emits direct
    # BL instructions instead of ARM/Thumb interworking veneers
    mode_by_name = {}
    for entry in json.load(open("config/eu-symbols.json")):
        if "mode" in entry:
            mode_by_name[entry["name"]] = entry["mode"]
    for line in Path("config/eu-symbols-c.txt").read_text().splitlines():
        m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);", line)
        if m:
            mode_by_name.setdefault(m.group(1), "thumb")
    for name, addr in mapped.items():
        if mode_by_name.get(name) != "arm" and addr >= 0x08000000:
            provides[name] = addr | 1
        else:
            provides[name] = addr
    Path(SYMBOLS_LD).write_text("".join(
        f"PROVIDE({name} = 0x{addr:08X});\n" for name, addr in sorted(provides.items())))

    direct, linked, diffs, errors = [], [], [], []
    files_ok = 0
    for src in sorted((fe7j / "src").glob("*.c")):
        obj, err = compile_file(fe7j, src, build)
        if obj is None:
            errors.append((src.name, err))
            continue
        files_ok += 1
        secs = sections(obj)
        placed = []
        info = {}
        for i, (sec, size) in enumerate(sorted(secs.items())):
            name = sec[len(".text."):]
            if name not in mapped or size < 4:
                continue
            out = f".f{i}"
            placed.append((sec, mapped[name], out))
            info[out] = (name, size, mapped[name])

        if not placed:
            continue

        # fast path: raw object bytes
        todo = {}
        for out, (name, size, addr) in info.items():
            raw = section_bytes(obj, f".text.{name}", build / "_raw.bin")
            want = rom[addr - ps.ROM_BASE: addr - ps.ROM_BASE + size]
            if raw == want:
                direct.append((name, src.name, size, addr))
            else:
                todo[out] = (name, size, addr)

        if not todo:
            continue

        elf, missing = link_object(obj, placed, build,
                                   {s: provides.get(s, ps.ROM_BASE)
                                    for s in undefined_symbols(obj)
                                    if s not in provides})
        if elf is None:
            for out, (name, size, addr) in todo.items():
                errors.append((name, f"{src.name}: link failed"))
            continue
        for out, (name, size, addr) in todo.items():
            got = section_bytes(elf, out, build / f"{out}.bin")
            want = rom[addr - ps.ROM_BASE: addr - ps.ROM_BASE + size]
            if got == want:
                linked.append((name, src.name, size, addr))
            else:
                diffs.append((name, src.name, size, addr, ",".join(missing[:3]) if missing else ""))

    lines = [
        "# FE7J C functions vs FE7 EU — validation report",
        "",
        f"- C files compiled          : {files_ok}",
        f"- **byte-identical raw**         : **{len(direct)}**",
        f"- **byte-identical after link**  : **{len(linked)}**",
        f"- differ                     : {len(diffs)}",
        f"- files/links failed         : {len(errors)}",
        "",
        "## Byte-identical functions (ready to replace asm)",
        "",
        "| function | source | size | EU address | mode |",
        "|---|---|---|---|---|",
    ]
    direct_set = {(n, f, s, a) for n, f, s, a in direct}
    for name, fname, size, addr in sorted(direct + linked, key=lambda e: e[3]):
        mode = "raw" if (name, fname, size, addr) in direct_set else "linked"
        lines.append(f"| {name} | {fname} | {size:#x} | 0x{addr:08X} | {mode} |")
    lines += ["", "## Differing", "", "| function | source | size | EU address | missing symbols |",
              "|---|---|---|---|---|"]
    for name, fname, size, addr, miss in sorted(diffs, key=lambda e: e[3])[:150]:
        lines.append(f"| {name} | {fname} | {size:#x} | 0x{addr:08X} | {miss} |")
    lines += ["", "## Failed", ""]
    for name, err in errors[:80]:
        lines.append(f"- {name}: {err}")
    Path(args.out).write_text("\n".join(lines) + "\n")

    with Path("config/c-validated.txt").open("w") as fh:
        for name, fname, size, addr in sorted(direct + linked, key=lambda e: e[3]):
            fh.write(f"{name} = 0x{addr:08X};  // {fname}\n")

    print(f"[*] files OK {files_ok}, raw {len(direct)}, linked {len(linked)}, "
          f"diff {len(diffs)}, failed {len(errors)}")
    print(f"[*] wrote {args.out} and config/c-validated.txt")
    return 0


if __name__ == "__main__":
    sys.exit(main())

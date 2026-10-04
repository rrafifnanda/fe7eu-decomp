#!/usr/bin/env python3
"""Generate the EU matching-build skeleton.

Produces:
  - build/gen/fill_NNNN.s : asm chunks copying the baserom regions that are not
    covered by an asm part or an integrated C function
  - fe7eu.lds             : linker script placing every chunk and every
    integrated C function section at its ROM address (VMA = 0x08000000 + offset,
    LMA = offset, so `objcopy -O binary` is exact)
  - fe7eu.sha1            : expected sha1 of the rebuilt ROM

Usage (inside `nix develop`):
    python3 scripts/gen_eu_build.py --rom rom/fe7eu.gba --asm-dir asm/eu \
        --integrated config/c-integrated.json
"""
import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

HEADER = re.compile(r"@ split-range: 0x([0-9A-Fa-f]+)-0x([0-9A-Fa-f]+)")


def sanitize(name):
    return re.sub(r"[^A-Za-z0-9_]", "_", name)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--rom", default="rom/fe7eu.gba")
    ap.add_argument("--asm-dir", default="asm/eu")
    ap.add_argument("--out", default=".")
    ap.add_argument("--integrated", default="config/c-integrated.json")
    ap.add_argument("--symbols", default="config/fe7j-symbols-extra.txt")
    ap.add_argument("--symbols-rom", default="config/eu-symbols-all.txt")
    ap.add_argument("--symbols-modes", default="config/eu-symbols.json")
    ap.add_argument("--symbols-c", default="config/eu-symbols-c.txt")
    ap.add_argument("--sha1", default="c37e3bae84b53e6972ed7608541a62896fa5d6a3")
    args = ap.parse_args()

    rom = Path(args.rom).read_bytes()
    out = Path(args.out)
    gen = out / "build" / "gen"
    gen.mkdir(parents=True, exist_ok=True)
    for stale in gen.glob("fill_*.s"):
        stale.unlink()

    units = []
    oversized = []
    for src in sorted(Path(args.asm_dir).glob("*.s")):
        lines = src.read_text().splitlines()
        m = HEADER.match(lines[1]) if len(lines) > 1 else None
        if not m:
            print(f"error: {src} has no split-range header")
            return 1
        units.append({"kind": "asm", "start": int(m.group(1), 16),
                      "end": int(m.group(2), 16),
                      "obj": f"build/asm/eu/{src.stem}.o",
                      "section": ".text", "name": sanitize(src.stem)})

    if Path(args.integrated).exists():
        manifest = json.load(open(args.integrated))
        # real section sizes from the compiled objects: a candidate whose
        # compiled code exceeds its EU hole (EU code longer than the JP
        # compile) cannot be placed without clobbering the next function
        real_size = {}
        for obj in sorted({e2["obj"] for e2 in
                           [{"obj": f"build/c/{Path(e['file']).stem}.o"}
                            for e in manifest]}):
            if not Path(obj).exists():
                continue
            out2 = subprocess.run(["arm-none-eabi-objdump", "-h", obj],
                                  capture_output=True, text=True).stdout
            for line2 in out2.splitlines():
                m2 = re.match(r"\s*\d+\s+\.text\.(\S+)\s+([0-9a-f]+)", line2)
                if m2:
                    real_size[m2.group(1)] = int(m2.group(2), 16)
        for e in manifest:
            start = e["addr"] - 0x08000000
            real = real_size.get(e["name"], e["size"])
            if real > e["size"]:
                oversized.append({"name": e["name"], "file": e["file"],
                                  "addr": e["addr"], "manifest_size": e["size"],
                                  "real_size": real})
                continue
            units.append({"kind": "c", "start": start,
                          "end": start + e["size"],
                          "obj": f"build/c/{Path(e['file']).stem}.o",
                          "section": f".text.{e['name']}",
                          "name": sanitize(e["name"])})
        if oversized:
            Path("config/c-oversized.json").write_text(
                json.dumps(oversized, indent=1) + "\n")
        elif Path("config/c-oversized.json").exists():
            Path("config/c-oversized.json").unlink()

    units.sort(key=lambda u: u["start"])
    prev_end = 0
    for u in units:
        if u["start"] < prev_end:
            print(f"error: overlap at 0x{u['start']:X} ({u['name']})")
            return 1
        prev_end = u["end"]

    # fill the complement
    layout = []
    fill_idx = 0
    pos = 0
    for u in units:
        if u["start"] > pos:
            chunk = gen / f"fill_{fill_idx:04d}.s"
            chunk.write_text(
                "    .section .text\n"
                f'    .incbin "{args.rom}", 0x{pos:X}, 0x{u["start"] - pos:X}\n')
            layout.append({"kind": "fill", "start": pos, "end": u["start"],
                           "obj": f"build/gen/{chunk.stem}.o",
                           "section": ".text", "name": f"fill_{fill_idx:04d}"})
            fill_idx += 1
        layout.append(u)
        pos = u["end"]
    if pos < len(rom):
        chunk = gen / f"fill_{fill_idx:04d}.s"
        chunk.write_text(
            "    .section .text\n"
            f'    .incbin "{args.rom}", 0x{pos:X}, 0x{len(rom) - pos:X}\n')
        layout.append({"kind": "fill", "start": pos, "end": len(rom),
                       "obj": f"build/gen/{chunk.stem}.o",
                       "section": ".text", "name": f"fill_{fill_idx:04d}"})

    # linker script
    lines = ["OUTPUT_ARCH(arm)"]
    extra = {}
    sym_path = Path(args.symbols)
    if sym_path.exists():
        for line in sym_path.read_text().splitlines():
            m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);", line)
            if m:
                extra[m.group(1)] = int(m.group(2), 16)
    for name, addr in extra.items():
        lines.append(f"PROVIDE({name} = 0x{addr:08X});")

    # mapped ROM functions, same scheme as build/c-validate/symbols.ld: a call
    # from integrated C to a not-yet-integrated function resolves at its mapped
    # EU address. The Thumb bit keeps ld from emitting interworking veneers,
    # which would shift the binary layout; wrong mappings make the patched
    # bytes differ and the differential loop drops the candidate.
    rom_syms = {}
    rom_path = Path(args.symbols_rom)
    if rom_path.exists():
        for line in rom_path.read_text().splitlines():
            m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);", line)
            if m:
                rom_syms[m.group(1)] = int(m.group(2), 16)
    mode_by_name = {}
    if Path(args.symbols_modes).exists():
        for entry in json.load(open(args.symbols_modes)):
            if "mode" in entry:
                mode_by_name[entry["name"]] = entry["mode"]
    if Path(args.symbols_c).exists():
        for line in Path(args.symbols_c).read_text().splitlines():
            m = re.match(r"(\S+) = 0x", line)
            if m:
                mode_by_name.setdefault(m.group(1), "thumb")
    for name, addr in rom_syms.items():
        if name in extra:
            continue
        if mode_by_name.get(name) != "arm" and addr >= 0x08000000:
            addr |= 1
        lines.append(f"PROVIDE({name} = 0x{addr:08X});")

    lines.append("SECTIONS")
    lines.append("{")
    for e in layout:
        lines.append(f"    . = 0x08000000 + 0x{e['start']:X};")
        lines.append(f"    .{e['name']} : AT(0x{e['start']:X}) "
                     f"{{ {e['obj']}({e['section']}) }}")
    lines.append("    /DISCARD/ : { *(*) }")
    lines.append("}")
    (out / "fe7eu.lds").write_text("\n".join(lines) + "\n")
    (out / "fe7eu.sha1").write_text(f"{args.sha1}  fe7eu.gba\n")

    covered = sum(e["end"] - e["start"] for e in layout)
    n_c = sum(1 for e in layout if e["kind"] == "c")
    print(f"[*] layout: {sum(1 for e in layout if e['kind'] == 'asm')} asm parts, "
          f"{n_c} C functions, {sum(1 for e in layout if e['kind'] == 'fill')} fill chunks "
          f"= {covered:,} bytes (ROM {len(rom):,})")
    return 0


if __name__ == "__main__":
    sys.exit(main())

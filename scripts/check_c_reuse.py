#!/usr/bin/env python3
"""Locate FE7J C-compiled functions inside the FE7 EU ROM.

FE7J's decompiled C functions no longer appear in its asm files, so they have
no JP address in `config/eu-symbols.json`. This tool therefore compiles each
`refs/fe7j/src/*.c` with the matching toolchain and searches the resulting
function bytes directly in the EU ROM (same normalized matcher as Phase 1).

Output: `config/c-reuse-report.md` with
  - functions that are byte-identical to the EU ROM at a known mapped address,
  - functions located by pattern matching (name -> EU address + score),
  - compile errors / unusable functions.

Usage (inside `nix develop`):
    python3 scripts/check_c_reuse.py --fe7j refs/fe7j --rom rom/fe7eu.gba \
        --out config/c-reuse-report.md
"""
import argparse
import bisect
import re
import subprocess
import sys
from pathlib import Path

import port_symbols as ps

CC = "tools/agbcc/agbcc"
CFLAGS = ["-g", "-mthumb-interwork", "-Wimplicit", "-Wparentheses",
          "-fhex-asm", "-ffix-debug-line"]
O_FLAGS = {
    "irq.c": "-O0", "random.c": "-O0", "agb-sram.c": "-O1",
    "hardware.c": "-O0", "move-data.c": "-O0", "oam.c": "-O0",
}


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
        return None, f"agbcc failed: {cc.stderr.decode(errors='replace').strip()[:160]}"

    with asm.open("a") as fh:
        fh.write(".text\n\t.align\t2, 0\n")

    asm_run = subprocess.run(
        ["arm-none-eabi-as", "-mcpu=arm7tdmi", "-I", str(fe7j / "include"),
         str(asm), "-o", str(obj)], capture_output=True)
    if asm_run.returncode != 0:
        return None, "arm-none-eabi-as failed"
    return obj, None


def load_symbols(obj, binpath):
    subprocess.run(["arm-none-eabi-objcopy", "-O", "binary",
                    "--only-section=.text", str(obj), str(binpath)],
                   check=True, capture_output=True)
    data = binpath.read_bytes()
    nm = subprocess.run(["arm-none-eabi-nm", "--defined-only", str(obj)],
                        capture_output=True, text=True).stdout
    syms = []
    for line in nm.splitlines():
        parts = line.split()
        if len(parts) >= 3 and parts[1] in ("t", "T"):
            try:
                addr = int(parts[0], 16)
            except ValueError:
                continue
            syms.append((addr, parts[-1]))
    syms.sort()
    return data, syms


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--fe7j", default="refs/fe7j")
    ap.add_argument("--rom", default="rom/fe7eu.gba")
    ap.add_argument("--build", default="build/c-reuse")
    ap.add_argument("--out", default="config/c-reuse-report.md")
    ap.add_argument("--min-score", type=float, default=0.9)
    ap.add_argument("--cand-score", type=float, default=0.65)
    args = ap.parse_args()

    fe7j = Path(args.fe7j)
    build = Path(args.build)
    build.mkdir(parents=True, exist_ok=True)
    rom = Path(args.rom).read_bytes()

    mapped = {}
    for line in Path("config/eu-symbols.txt").read_text().splitlines():
        m = re.match(r"(\S+) = 0x([0-9A-F]+);", line)
        if m:
            mapped[m.group(1)] = int(m.group(2), 16)

    found, weak, errors = [], [], []
    files_ok = 0
    for src in sorted((fe7j / "src").glob("*.c")):
        obj, err = compile_file(fe7j, src, build)
        if obj is None:
            errors.append((src.name, err))
            continue
        files_ok += 1
        data, syms = load_symbols(obj, build / f"{src.stem}.bin")
        bounds = sorted({a for a, _ in syms}) + [len(data)]
        pending = []
        for a, name in syms:
            if name.startswith(("_", ".")):
                continue
            nxt_idx = bisect.bisect_right(bounds, a)
            nxt = bounds[nxt_idx] if nxt_idx < len(bounds) else len(data)
            if nxt <= a:
                continue
            size = nxt - a
            if size < 4:
                continue
            code = data[a:nxt]
            if name in mapped:
                eu = mapped[name] - 0x08000000
                if code == rom[eu:eu + size]:
                    found.append((name, src.name, size, mapped[name], 1.0))
                continue
            toks = ps.token_list(code, "thumb")
            if len(toks) < 3:
                continue
            cands = ps.pattern_candidates(rom, code, "thumb", toks)
            if cands:
                pending.append((name, size, cands))

        # order-preserving assignment: functions of one translation unit appear
        # in the ROM in object order, which resolves near-identical functions
        if pending:
            chain = ps.best_chain([p[2] for p in pending], args.cand_score)
            for c in chain:
                name, size, _ = pending[c["jp_idx"]]
                entry = (name, src.name, size, c["eu_addr"], round(c["score"], 4))
                (found if c["score"] >= args.min_score else weak).append(entry)

    # de-duplicate by EU address, keeping the best score
    by_addr = {}
    for e in found:
        cur = by_addr.get(e[3])
        if cur is None or e[4] > cur[4]:
            by_addr[e[3]] = e
    found = list(by_addr.values())

    lines = [
        "# FE7J C sources vs FE7 EU — reuse check",
        "",
        f"- C files compiled OK : {files_ok}",
        f"- compile errors      : {len(errors)}",
        f"- functions located in EU (score >= {args.min_score}) : **{len(found)}**",
        f"- weak matches        : {len(weak)}",
        "",
        "## Located functions (reusable seeds for phase 3)",
        "",
        "| function | source | size | EU address | score |",
        "|---|---|---|---|---|",
    ]
    for name, fname, size, addr, score in sorted(found, key=lambda e: e[3]):
        lines.append(f"| {name} | {fname} | {size:#x} | 0x{addr:08X} | {score} |")
    lines += ["", "## Weak matches", "", "| function | source | size | EU address | score |", "|---|---|---|---|---|"]
    for name, fname, size, addr, score in sorted(weak, key=lambda e: -e[4])[:80]:
        lines.append(f"| {name} | {fname} | {size:#x} | 0x{addr:08X} | {score} |")
    lines += ["", "## Compile errors", ""]
    for fname, err in errors[:40]:
        lines.append(f"- {fname}: {err}")

    Path(args.out).write_text("\n".join(lines) + "\n")

    # also emit a splat-style symbol file for the located C functions
    with Path("config/eu-symbols-c.txt").open("w") as fh:
        for name, fname, size, addr, score in sorted(found, key=lambda e: e[3]):
            fh.write(f"{name} = 0x{addr:08X};  // {fname} (c, score {score})\n")

    print(f"[*] files OK {files_ok}, errors {len(errors)}")
    print(f"[*] located {len(found)} C functions, weak {len(weak)}")
    print(f"[*] report: {args.out}, symbols: config/eu-symbols-c.txt")
    return 0


if __name__ == "__main__":
    sys.exit(main())

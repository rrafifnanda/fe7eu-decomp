#!/usr/bin/env python3
"""Extract data/global symbol addresses from FE7J's linker script.

The FE7J `.lds` assigns every EWRAM/IWRAM/ROM data symbol an address
(`gBonusClaimData = .;` right after `. = 0x0000F4;`). RAM addresses are
region-independent, so they can be provided to the linker when validating C
functions; ROM data addresses are JP-specific but still useful to let links
succeed (differences then show up as byte mismatches instead of link errors).

Usage:
    python3 scripts/parse_fe7j_symbols.py --lds refs/fe7j/FireEmblem7J.lds \
        --out config/fe7j-symbols-extra.txt
"""
import argparse
import re
import sys
from pathlib import Path

SET_DOT = re.compile(r"\.\s*=\s*(0x[0-9A-Fa-f]+)\s*;")
SYM_DOT = re.compile(r"^([A-Za-z_]\w*)\s*=\s*\.\s*;")
SYM_VAL = re.compile(r"^([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--lds", default="refs/fe7j/FireEmblem7J.lds")
    ap.add_argument("--out", default="config/fe7j-symbols-extra.txt")
    args = ap.parse_args()

    cur = 0
    syms = {}
    for raw in Path(args.lds).open(encoding="utf-8", errors="replace"):
        line = raw.split("/*")[0]
        for stmt in line.split(";"):
            s = stmt.strip()
            if not s:
                continue
            m = re.match(r"\.\s*=\s*(0x[0-9A-Fa-f]+)\s*$", s)
            if m:
                cur = int(m.group(1), 16)
                continue
            m = re.match(r"\.\s*=\s*([A-Za-z_]\w*)\s*$", s)
            if m and m.group(1) in syms:
                cur = syms[m.group(1)]
                continue
            m = re.match(r"([A-Za-z_]\w*)\s*=\s*\.\s*$", s)
            if m:
                syms.setdefault(m.group(1), cur)
                continue
            m = re.match(r"([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+)\s*$", s)
            if m:
                syms.setdefault(m.group(1), int(m.group(2), 16))
                continue
            m = re.match(r"([A-Za-z_]\w*)\s*=\s*([A-Za-z_]\w*)\s*$", s)
            if m and m.group(2) in syms:
                syms.setdefault(m.group(1), syms[m.group(2)])

    with Path(args.out).open("w") as fh:
        for name, addr in sorted(syms.items(), key=lambda kv: (kv[1], kv[0])):
            fh.write(f"{name} = 0x{addr:08X};\n")

    ram = sum(1 for a in syms.values() if a < 0x08000000)
    print(f"[*] {len(syms)} symbols ({ram} RAM, {len(syms) - ram} ROM) -> {args.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())

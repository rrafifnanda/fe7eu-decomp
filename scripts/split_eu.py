#!/usr/bin/env python3
"""Split the FE7 EU ROM into per-module assembly using the mapped symbols.

Supports *exclusions*: functions listed in `--integrate` (a JSON manifest of
validated C functions) are left out of the assembly (the module is split into
parts around the holes); their bytes are provided by compiled C objects placed
at the same address by `scripts/gen_eu_build.py`.

Each emitted part starts with:
    @ split-range: 0xSTART-0xEND
which the verifier and the build generator parse.

Usage (inside `nix develop`):
    python3 scripts/split_eu.py --rom rom/fe7eu.gba \
        --symbols config/eu-symbols.json --out asm/eu \
        --integrate config/c-integrated.json
"""
import argparse
import json
import sys
from collections import defaultdict
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_LITTLE_ENDIAN, CS_MODE_THUMB

ROM_BASE = 0x08000000
MODE_MAP = {"thumb": CS_MODE_THUMB, "arm": CS_MODE_ARM}


def emit_code(fh, data, mode):
    md = Cs(CS_ARCH_ARM, MODE_MAP[mode] | CS_MODE_LITTLE_ENDIAN)
    pos = 0
    while pos < len(data):
        ins = next(md.disasm(data[pos:], 0), None)
        if ins is None or ins.size <= 0:
            fh.write(f"    .byte 0x{data[pos]:02X}\n")
            pos += 1
            continue
        raw = data[pos:pos + ins.size]
        if ins.size == 2:
            fh.write(f"    .hword 0x{int.from_bytes(raw, 'little'):04X}"
                     f"  @ {ins.mnemonic} {ins.op_str}\n")
        elif ins.size == 4:
            fh.write(f"    .word 0x{int.from_bytes(raw, 'little'):08X}"
                     f"  @ {ins.mnemonic} {ins.op_str}\n")
        else:
            for b in raw:
                fh.write(f"    .byte 0x{b:02X}\n")
        pos += ins.size


def subtract(ranges, excluded):
    """Subtract sorted excluded ranges from a single (start, end) range."""
    start, end = ranges
    out = []
    cur = start
    for xs, xe in excluded:
        if xe <= cur or xs >= end:
            continue
        if xs > cur:
            out.append((cur, min(xs, end)))
        cur = max(cur, xe)
        if cur >= end:
            break
    if cur < end:
        out.append((cur, end))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--rom", default="rom/fe7eu.gba")
    ap.add_argument("--symbols", default="config/eu-symbols.json")
    ap.add_argument("--out", default="asm/eu")
    ap.add_argument("--integrate", default=None,
                    help="JSON manifest of C functions to exclude (integration)")
    args = ap.parse_args()

    rom = Path(args.rom).read_bytes()
    symbols = json.load(open(args.symbols))
    mapped = [s for s in symbols if "eu_addr" in s and s.get("method") in ("chain",)]
    mapped.sort(key=lambda s: s["eu_addr"])

    excluded = []
    if args.integrate:
        for e in json.load(open(args.integrate)):
            start = e["addr"] - ROM_BASE
            excluded.append((start, start + e["size"]))
    excluded.sort()

    # global next-address limit so the split partitions the ROM exactly
    next_off = {}
    for i, s in enumerate(mapped):
        if i + 1 < len(mapped):
            nxt = mapped[i + 1]["eu_addr"] - ROM_BASE
        else:
            nxt = s["eu_addr"] - ROM_BASE + s["size"]
        next_off[id(s)] = nxt

    by_file = defaultdict(list)
    for s in mapped:
        by_file[s["file"]].append(s)

    out = Path(args.out)
    out.mkdir(parents=True, exist_ok=True)
    for stale in out.glob("*.s"):
        stale.unlink()

    total_bytes = 0
    total_parts = 0
    for module, funcs in sorted(by_file.items()):
        funcs.sort(key=lambda s: s["eu_addr"])
        module_start = funcs[0]["eu_addr"] - ROM_BASE

        # 1. build the ordered chunk list of the module
        chunks = []
        prev_end = module_start
        for s in funcs:
            off = s["eu_addr"] - ROM_BASE
            size = min(s["size"], max(0, next_off[id(s)] - off))
            if off > prev_end:
                chunks.append([prev_end, off, "gap", None])
            chunks.append([off, off + size, "func", s])
            prev_end = off + size

        # 2. subtract the integrated C ranges
        final = []
        for start, end, kind, s in chunks:
            for a, b in subtract((start, end), excluded):
                if kind == "func" and (a, b) == (start, end):
                    final.append([a, b, "func", s])
                else:
                    final.append([a, b, "gap", None])

        # 3. group into contiguous parts
        parts = []
        for chunk in final:
            if parts and parts[-1][-1][1] == chunk[0]:
                parts[-1].append(chunk)
            else:
                parts.append([chunk])

        stem = Path(module).stem
        for idx, part in enumerate(parts):
            name = f"{stem}.s" if len(parts) == 1 else f"{stem}_p{idx}.s"
            start = part[0][0]
            end = part[-1][1]
            with (out / name).open("w") as f:
                f.write("@ Auto-generated by scripts/split_eu.py — do not edit by hand.\n")
                f.write(f"@ split-range: 0x{start:08X}-0x{end:08X}\n")
                f.write("    .syntax unified\n\n")
                for a, b, kind, s in part:
                    if kind == "gap":
                        f.write(f'    .incbin "{args.rom}", 0x{a:X}, 0x{b - a:X}\n\n')
                    else:
                        f.write(f"    .global {s['name']}\n")
                        f.write(f"    .type {s['name']}, %function\n")
                        if s["mode"] == "thumb":
                            f.write("    .thumb\n    .thumb_func\n")
                        else:
                            f.write("    .arm\n")
                        f.write(f"{s['name']}:  @ 0x{s['eu_addr']:08X} "
                                f"(jp 0x{s['jp_addr']:08X}, score {s.get('score')})\n")
                        emit_code(f, rom[a:b], s["mode"])
                        f.write("\n")
                        total_bytes += b - a
            total_parts += 1

    print(f"[*] split {len(mapped)} functions ({total_bytes:,} bytes) into "
          f"{total_parts} parts ({len(by_file)} modules), "
          f"{len(excluded)} C ranges excluded")
    return 0


if __name__ == "__main__":
    sys.exit(main())

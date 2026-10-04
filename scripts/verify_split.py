#!/usr/bin/env python3
"""Verify that every split module reassembles to the exact ROM bytes.

For each `asm/eu/*.s`, read the `@ split-range: START-END` header, assemble the
file with arm-none-eabi-as and compare the resulting .text with
rom[START-END].

Usage (inside `nix develop`):
    python3 scripts/verify_split.py --rom rom/fe7eu.gba --dir asm/eu
"""
import argparse
import re
import subprocess
import sys
import tempfile
from pathlib import Path

HEADER = re.compile(r"^@ split-range: 0x([0-9A-Fa-f]+)-0x([0-9A-Fa-f]+)")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--rom", default="rom/fe7eu.gba")
    ap.add_argument("--dir", default="asm/eu")
    args = ap.parse_args()

    rom = Path(args.rom).read_bytes()
    files = sorted(Path(args.dir).glob("*.s"))
    ok = bad = 0
    with tempfile.TemporaryDirectory() as tmp:
        for src in files:
            first = src.open().readline()
            # header is the second line in generated files
            if "@ split-range" not in first:
                first = src.open().readlines()[1]
            m = HEADER.match(first)
            if not m:
                print(f"  ?? {src.name}: no split-range header")
                bad += 1
                continue
            start, end = int(m.group(1), 16), int(m.group(2), 16)
            obj = Path(tmp) / (src.stem + ".o")
            proc = subprocess.run(
                ["arm-none-eabi-as", "-mcpu=arm7tdmi", "-I", ".", str(src), "-o", str(obj)],
                capture_output=True, text=True)
            if proc.returncode != 0:
                print(f"  FAIL {src.name}: assemble error\n{proc.stderr[:400]}")
                bad += 1
                continue
            binpath = Path(tmp) / (src.stem + ".bin")
            subprocess.run(["arm-none-eabi-objcopy", "-O", "binary",
                            "--only-section=.text", str(obj), str(binpath)], check=True)
            got = binpath.read_bytes()
            want = rom[start:end]
            if got == want:
                ok += 1
            else:
                print(f"  FAIL {src.name}: {len(got)} bytes vs {len(want)} expected")
                for i, (a, b) in enumerate(zip(got, want)):
                    if a != b:
                        print(f"       first diff at +0x{i:X}: got {a:02X}, want {b:02X}")
                        break
                bad += 1

    print(f"[*] verified {ok} files, {bad} failed")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())

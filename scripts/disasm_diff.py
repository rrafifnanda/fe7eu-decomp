#!/usr/bin/env python3
"""Disassemble ROM vs freshly-built candidate around each differing offset.

Usage:  disasm_diff.py <stem> <function-name>
Shows 12 bytes of Thumb disassembly around every diff site, ROM first.
"""
import re
import subprocess
import sys
from pathlib import Path

rom = Path("rom/fe7eu.gba").read_bytes()


def disasm(data, vma):
    Path("/tmp/_dd.bin").write_bytes(data)
    r = subprocess.run(["arm-none-eabi-objdump", "-D", "-b", "binary", "-m", "arm",
                        "-M", "force-thumb", f"--adjust-vma={vma}", "/tmp/_dd.bin"],
                       capture_output=True, text=True)
    return [l.split("\t", 1)[-1].replace("\t", " ")
            for l in r.stdout.splitlines() if re.match(r"^\s*[0-9a-f]+:", l)]


stem, name = sys.argv[1], sys.argv[2]
addr = None
for line in open("config/eu-symbols-c.txt"):
    m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);\s*//\s*(\S+)", line)
    if m and m.group(1) == name:
        addr, file = int(m.group(2), 16), m.group(3)
subprocess.run(["arm-none-eabi-objcopy", "-O", "binary", "--only-section=.text." + name,
                f"/tmp/chk/{stem}.o", "/tmp/_dd_ours.bin"], check=True)
ours = open("/tmp/_dd_ours.bin", "rb").read()
base = addr - 0x08000000
want = rom[base:base + len(ours)]
diffs = sorted({i & ~1 for i, (a, b) in enumerate(zip(ours, want)) if a != b})
print(f"{name} @ {addr:#010x} size {len(ours):#x}")
for o in diffs:
    lo = max(0, o - 8)
    rl = disasm(want[lo:o + 6], addr + lo)
    ol = disasm(ours[lo:o + 6], addr + lo)
    print(f"--- site {o:#x} ---")
    for a, b in zip(rl, ol):
        mark = "   <<<" if a.split(maxsplit=1)[-1] != b.split(maxsplit=1)[-1] else ""
        print("  R " + a)
        print("  O " + b + mark)

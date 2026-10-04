#!/usr/bin/env python3
"""Emit gas `.set` definitions for a C object's undefined symbols.

binutils ld treats R_ARM_THM_CALL relocations against linker-script (absolute)
symbols as ARM calls and appends interworking stubs to the calling section,
which breaks the fixed AT() layout of the matching build. Resolving the
references at assembly time avoids relocations entirely: this script reads
undefined symbol names (one per line, as printed by `nm -u`) and writes
`.set name, value` lines for every name known in the EU symbol map, using the
same Thumb-bit scheme as the PROVIDEs in fe7eu.lds. Names unknown to the map
are left undefined so the link fails loudly instead of silently misplacing
code.

Usage:  nm -u object.o | gen_symbol_defs.py > defs.s
"""
import json
import re
import sys
from pathlib import Path


def load_map():
    syms = {}
    for path in ("config/fe7j-symbols-extra.txt", "config/eu-symbols-all.txt"):
        p = Path(path)
        if not p.exists():
            continue
        for line in p.read_text().splitlines():
            m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);", line)
            if m:
                syms.setdefault(m.group(1), int(m.group(2), 16))

    mode = {}
    p = Path("config/eu-symbols.json")
    if p.exists():
        for e in json.load(open(p)):
            if "mode" in e:
                mode[e["name"]] = e["mode"]
    p = Path("config/eu-symbols-c.txt")
    if p.exists():
        for line in p.read_text().splitlines():
            m = re.match(r"(\S+) = 0x", line)
            if m:
                mode.setdefault(m.group(1), "thumb")

    for name, addr in syms.items():
        if mode.get(name) != "arm" and addr >= 0x08000000:
            syms[name] = addr | 1
    return syms


def main():
    syms = load_map()
    out = []
    for line in sys.stdin.read().splitlines():
        name = line.strip().split()[-1] if line.strip() else ""
        # section symbols (.rodata) cannot be given an address here; candidates
        # referencing them are dropped before the build
        if not name or name.startswith((".", "@")):
            continue
        if name in syms:
            out.append(f"\t.set\t{name}, 0x{syms[name]:08X}")
    if out:
        sys.stdout.write("\n".join(out) + "\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())

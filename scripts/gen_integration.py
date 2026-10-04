#!/usr/bin/env python3
"""Build the integration manifest for validated C functions.

Reads `config/c-validated.txt` (name = 0xADDR; // file.c), fills in the function
size from the compiled object in `build/c-validate/`, and writes:

    config/c-integrated.json    [{name, file, size, addr}, ...]
    config/c-integrated-files.txt   source files to compile in the Makefile

Usage (inside `nix develop`):
    python3 scripts/gen_integration.py
"""
import json
import re
import subprocess
import sys
from pathlib import Path

MANIFEST = "config/c-integrated.json"
FILES = "config/c-integrated-files.txt"


def section_sizes(obj):
    out = subprocess.run(["arm-none-eabi-objdump", "-h", str(obj)],
                         capture_output=True, text=True).stdout
    sizes = {}
    for line in out.splitlines():
        m = re.match(r"\s*\d+\s+(\.text\.\S+)\s+([0-9a-f]+)", line)
        if m:
            sizes[m.group(1)[len(".text."):]] = int(m.group(2), 16)
    return sizes


def main():
    entries = []
    missing = []
    for line in Path("config/c-validated.txt").read_text().splitlines():
        m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);\s*//\s*(\S+)", line)
        if not m:
            continue
        name, addr, file = m.group(1), int(m.group(2), 16), m.group(3)
        obj = Path("build/c-validate") / (Path(file).stem + ".o")
        size = section_sizes(obj).get(name) if obj.exists() else None
        if size is None:
            missing.append(name)
            continue
        entries.append({"name": name, "file": file, "size": size, "addr": addr})

    entries.sort(key=lambda e: e["addr"])
    Path(MANIFEST).write_text(json.dumps(entries, indent=1) + "\n")

    files = sorted({f"refs/fe7j/src/{e['file']}" for e in entries})
    Path(FILES).write_text("\n".join(files) + "\n")

    total = sum(e["size"] for e in entries)
    print(f"[*] integrated: {len(entries)} functions, {total:,} bytes, "
          f"{len(files)} source files"
          + (f" ({len(missing)} missing sizes)" if missing else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())

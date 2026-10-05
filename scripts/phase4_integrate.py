#!/usr/bin/env python3
"""Integrate Phase 4 byte-exact matches: copy src-auto/<name>.c to src/,
register the object for size analysis, and append to eu-symbols-c.txt.
Safe to re-run (skips already-registered names)."""
import json
import shutil
from pathlib import Path

results = json.load(open("config/phase4-results.json"))
matches = [r for r in results if r.get("match")]
registered = set()
for line in open("config/eu-symbols-c.txt"):
    if " = " in line:
        registered.add(line.split(" = ")[0])

added = []
for m in matches:
    name = m["name"]
    if name in registered:
        continue
    shutil.copy(f"src-auto/{name}.c", f"src/{name}.c")
    obj = Path(f"build/p4/{name}.o")
    if obj.exists():
        shutil.copy(obj, f"build/c-validate/{name}.o")
    with open("config/eu-symbols-c.txt", "a") as fh:
        fh.write(f"{name} = 0x{m['eu_addr']:08X};  // {name}.c (c, score 1.0)\n")
    added.append(name)
print("integrated:", len(added), added)

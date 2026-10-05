#!/usr/bin/env python3
"""Generate objdiff.json + per-file target objects for decomp.dev progress.

For every C source file that has integrated functions, two objects exist:
  - target: build/target/<stem>.o — assembled from the original ROM bytes of
    each integrated function (the "original" side of the diff)
  - base:   build/c/<stem>.o       — the C-built object (the "current" side)

objdiff-cli then diffs them symbol-by-symbol into progress/report.json.
Section sizes use the compiled (base) object's real sizes so EU-divergent
functions whose code is longer than the JP hole are compared fully.

Usage (inside nix develop):  python3 scripts/gen_objdiff.py [--assemble-only]
"""
import json
import re
import subprocess
import sys
from pathlib import Path

ROM = Path("rom/fe7eu.gba").read_bytes()


def section_sizes(obj):
    out = subprocess.run(["arm-none-eabi-objdump", "-h", str(obj)],
                         capture_output=True, text=True).stdout
    sizes = {}
    for line in out.splitlines():
        m = re.match(r"\s*\d+\s+\.text\.(\S+)\s+([0-9a-f]+)", line)
        if m:
            sizes[m.group(1)] = int(m.group(2), 16)
    return sizes


def main():
    assemble_only = "--assemble-only" in sys.argv
    manifest = json.load(open("config/c-integrated.json"))
    per_file = {}
    for e in manifest:
        per_file.setdefault(Path(e["file"]).stem, []).append(e)

    target_dir = Path("build/target")
    target_dir.mkdir(parents=True, exist_ok=True)

    units = []
    for stem, fns in sorted(per_file.items()):
        base_obj = Path(f"build/c/{stem}.o")
        sizes = section_sizes(base_obj) if base_obj.exists() else {}
        # one .text section with symbols at real intra-object offsets, like a
        # real asm build — objdiff aligns the target/base streams by symbol
        # address, so per-function sections (all at address 0) would collapse.
        # .thumb_func markers are required: without them objdiff disassembles
        # the target as ARM and every instruction mismatches
        lines = ["\t.syntax unified", "\t.thumb", "\t.text", "$t:"]
        prev_end = None
        for e in sorted(fns, key=lambda x: x["addr"]):
            size = sizes.get(e["name"], e["size"])
            off = e["addr"] - 0x08000000
            if prev_end is not None and off > prev_end:
                lines.append(f"\t.skip\t0x{off - prev_end:X}")
            lines += [f"\t.global\t{e['name']}",
                      f"{e['name']}:",
                      f'\t.incbin\t"rom/fe7eu.gba", 0x{off:X}, 0x{size:X}',
                      f"\t.size\t{e['name']}, 0x{size:X}"]
            prev_end = off + size
        src = target_dir / f"{stem}.s"
        src.write_text("\n".join(lines) + "\n")
        obj = target_dir / f"{stem}.o"
        ret = subprocess.run(["arm-none-eabi-as", "-mcpu=arm7tdmi", str(src),
                              "-o", str(obj)], capture_output=True, text=True)
        if ret.returncode != 0:
            print(f"[!] {stem}: {ret.stderr.strip()[:200]}")
            continue
        units.append({"name": stem,
                      "target_path": f"build/target/{stem}.o",
                      "base_path": f"build/c/{stem}.o"})

    if assemble_only:
        print(f"[*] assembled {len(units)} target objects")
        return

    config = {
        "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
        "custom_make": "make",
        "target_dir": "build/target",
        "base_dir": "build/c",
        "build_target": False,
        "build_base": False,
        "watch_patterns": ["src/**/*.c", "include/**/*.h", "asm/**/*.s"],
        "units": units,
    }
    Path("objdiff.json").write_text(json.dumps(config, indent=2) + "\n")
    print(f"[*] objdiff.json: {len(units)} units")
    return 0


if __name__ == "__main__":
    sys.exit(main())

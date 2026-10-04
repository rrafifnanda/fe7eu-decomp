#!/usr/bin/env python3
"""Integrate located C functions into the matching build, keeping only matches.

Strategy (differential build loop):

  1. candidates = every C function located in the EU ROM (config/eu-symbols-c.txt)
     with its size taken from the compiled object;
  2. keep only candidates whose relocations all target symbols that are either
     mapped (asm parts / other candidates) or provided RAM globals;
  3. write the integration manifest, re-split the asm modules around the
     candidates, regenerate the build skeleton and build;
  4. compare the rebuilt ROM with the baserom: every differing byte is caused by
     a wrong candidate, so all candidates covering differing offsets are removed
     and the loop repeats until the ROM matches sha1.

Usage (inside `nix develop`):
    python3 scripts/integrate_all.py
"""
import json
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

BUILD = Path("build")
VALIDATE = BUILD / "c-validate"


def run(cmd, check=False):
    return subprocess.run(cmd, capture_output=True, text=True, check=check)


def object_info(obj):
    """Return (sizes by function name, references by function name)."""
    sizes = {}
    out = run(["arm-none-eabi-objdump", "-h", str(obj)]).stdout
    for line in out.splitlines():
        m = re.match(r"\s*\d+\s+\.text\.(\S+)\s+([0-9a-f]+)", line)
        if m:
            sizes[m.group(1)] = int(m.group(2), 16)

    refs = defaultdict(set)
    cur = None
    out = run(["arm-none-eabi-objdump", "-r", str(obj)]).stdout
    for line in out.splitlines():
        m = re.match(r"RELOCATION RECORDS FOR \[\.text\.([^\]]+)\]", line)
        if m:
            cur = m.group(1)
            continue
        m = re.match(r"[0-9a-f]{8}\s+\S+\s+(\S+?)(?:\+0x[0-9a-f]+)?$", line.strip())
        if m and cur:
            refs[cur].add(m.group(1))
    return sizes, refs


def load_names(path):
    names = set()
    for line in Path(path).read_text().splitlines():
        m = re.match(r"(\S+) = 0x", line)
        if m:
            names.add(m.group(1))
    return names


def write_manifest(candidates):
    manifest = [{"name": c["name"], "file": c["file"], "size": c["size"],
                 "addr": c["addr"]} for c in candidates]
    files = sorted({f"refs/fe7j/src/{c['file']}" for c in candidates})
    # only rewrite on content change: build/c/*.o depends on the manifest, so
    # an unchanged file saves recompiling every C object in the next iteration
    txt = json.dumps(manifest, indent=1) + "\n"
    p = Path("config/c-integrated.json")
    if p.read_text() != txt:
        p.write_text(txt)
    ftxt = "\n".join(files) + "\n"
    fp = Path("config/c-integrated-files.txt")
    if fp.read_text() != ftxt:
        fp.write_text(ftxt)
    return files


def build_and_diff():
    for step in (["python3", "scripts/split_eu.py", "--rom", "rom/fe7eu.gba",
                  "--symbols", "config/eu-symbols.json", "--out", "asm/eu",
                  "--integrate", "config/c-integrated.json"],
                 ["python3", "scripts/gen_eu_build.py", "--rom", "rom/fe7eu.gba",
                  "--asm-dir", "asm/eu", "--integrated", "config/c-integrated.json"]):
        ret = run(step)
        if ret.returncode != 0:
            print(ret.stdout, ret.stderr)
            raise SystemExit(f"step failed: {' '.join(step)}")

    Path("fe7eu.gba").unlink(missing_ok=True)
    ret = run(["make", "-j", str(len(__import__('os').sched_getaffinity(0)))])
    if ret.returncode != 0 or not Path("fe7eu.gba").exists():
        print("\n".join(ret.stderr.splitlines()[-8:]))
        raise SystemExit("build failed")

    got = Path("fe7eu.gba").read_bytes()
    want = Path("rom/fe7eu.gba").read_bytes()
    if len(got) != len(want):
        raise SystemExit(f"size mismatch: {len(got)} vs {len(want)}")
    return [i for i, (a, b) in enumerate(zip(got, want)) if a != b]


def filter_linkable(candidates, mapped, ram):
    """Transitively drop candidates whose references are not all known."""
    while True:
        names = {c["name"] for c in candidates}
        known = mapped | ram | names
        bad = {c["name"] for c in candidates
               if any(not r.startswith((".", "@")) and r not in known
                      for r in c["refs"])}
        if not bad:
            return candidates
        candidates = [c for c in candidates if c["name"] not in bad]


def main():
    # ---- candidates -------------------------------------------------------
    candidates = []
    for line in Path("config/eu-symbols-c.txt").read_text().splitlines():
        m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);\s*//\s*(\S+)", line)
        if not m:
            continue
        name, addr, file = m.group(1), int(m.group(2), 16), m.group(3)
        obj = VALIDATE / (Path(file).stem + ".o")
        if not obj.exists():
            continue
        sizes, refs = object_info(obj)
        if name not in sizes:
            continue
        candidates.append({"name": name, "addr": addr, "size": sizes[name],
                           "file": file, "refs": refs.get(name, set())})

    # drop overlapping candidates (keep the first / lower address)
    candidates.sort(key=lambda c: c["addr"])
    kept = []
    end = -1
    for c in candidates:
        if c["addr"] < end:
            continue
        kept.append(c)
        end = c["addr"] + c["size"]
    candidates = kept
    print(f"[*] candidates: {len(candidates)}")

    # functions referencing a bare section (.rodata strings/jump tables, .data)
    # cannot link: those sections are discarded by the build skeleton
    before = len(candidates)
    candidates = [c for c in candidates
                  if not any(r.startswith(".") for r in c["refs"])]
    print(f"[*] no section refs: {len(candidates)} "
          f"(dropped {before - len(candidates)})")

    # ---- keep only linkable ones (all referenced symbols known) -----------
    mapped = load_names("config/eu-symbols-all.txt")
    ram = load_names("config/fe7j-symbols-extra.txt")
    before = len(candidates)
    candidates = filter_linkable(candidates, mapped, ram)
    print(f"[*] linkable: {len(candidates)} (dropped {before - len(candidates)} with unknown refs)")

    # ---- differential build loop -----------------------------------------
    removed_total = 0
    for iteration in range(1, 8):
        write_manifest(candidates)
        diff = build_and_diff()
        print(f"[*] iteration {iteration}: {len(candidates)} candidates, "
              f"{len(diff)} differing bytes")
        if not diff:
            break
        bad = set()
        for c in candidates:
            start = c["addr"] - 0x08000000
            end = start + c["size"]
            # binary search for the first differing offset >= start
            lo, hi = 0, len(diff)
            while lo < hi:
                mid = (lo + hi) // 2
                if diff[mid] < start:
                    lo = mid + 1
                else:
                    hi = mid
            if lo < len(diff) and diff[lo] < end:
                bad.add(c["name"])
        if not bad:
            print("[!] differing bytes outside any candidate; stopping")
            break
        candidates = [c for c in candidates if c["name"] not in bad]
        removed_total += len(bad)
        before = len(candidates)
        candidates = filter_linkable(candidates, mapped, ram)
        cascade = before - len(candidates)
        removed_total += cascade
        print(f"    removed {len(bad)} mismatching functions"
              + (f" + {cascade} cascaded" if cascade else ""))

    write_manifest(candidates)
    diff = build_and_diff()
    ok = not diff

    # ---- report -----------------------------------------------------------
    total_functions = 6248 + 1443
    lines = [
        "# C integration report",
        "",
        f"- candidates considered : {len(candidates) + removed_total}",
        f"- removed (mismatch)    : {removed_total}",
        f"- **integrated C functions** : **{len(candidates)}**",
        f"- bytes                   : {sum(c['size'] for c in candidates):,}",
        f"- final ROM sha1 match    : {'YES' if ok else 'NO'}",
        f"- game functions total (FE7J estimate): {total_functions}",
        f"- progress (integrated C / total): {len(candidates) / total_functions:.2%}",
    ]
    Path("config/c-integration-report.md").write_text("\n".join(lines) + "\n")
    print(f"[*] final: {len(candidates)} integrated, sha1 {'OK' if ok else 'MISMATCH'}")
    print(f"[*] report: config/c-integration-report.md")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())

#!/usr/bin/env python3
"""Fast per-file candidate check: run the whole C pipeline for one source file
with a temp manifest that keeps every located candidate of that file, then diff
each candidate section against the baserom. Source-level fixes can be iterated
in seconds without touching the real build or running the integration loop.

Usage:  check_candidates.py <source-stem> [...]
"""
import json
import re
import subprocess
import sys
from pathlib import Path

rom = Path("rom/fe7eu.gba").read_bytes()
cands = []
for line in open("config/eu-symbols-c.txt"):
    m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);\s*//\s*(\S+)", line)
    if m:
        cands.append({"name": m.group(1), "addr": int(m.group(2), 16),
                      "file": m.group(3)})
integrated = {e["name"] for e in json.load(open("config/c-integrated.json"))}

CC1 = "tools/agbcc/agbcc"


def disasm(data, vma):
    Path("/tmp/_d.bin").write_bytes(data)
    r = subprocess.run(["arm-none-eabi-objdump", "-D", "-b", "binary", "-m", "arm",
                        "-M", "force-thumb", f"--adjust-vma={vma}", "/tmp/_d.bin"],
                       capture_output=True, text=True)
    return [l.split("\t", 1)[-1].replace("\t", " ")
            for l in r.stdout.splitlines() if re.match(r"^\s*[0-9a-f]+:", l)]


total_ok = total = 0
for stem in sys.argv[1:]:
    mine = [c for c in cands if Path(c["file"]).stem == stem]
    if not mine:
        print(f"[{stem}] no located candidates")
        continue
    src = Path(f"src/{stem}.c")
    if not src.exists():
        src = Path(f"refs/fe7j/src/{stem}.c")
    cpp = subprocess.run(["arm-none-eabi-cpp", "-Irefs/fe7j/tools/agbcc/include",
                          "-iquote", "include", "-iquote", "refs/fe7j/include",
                          "-iquote", "refs/fe7j", "-nostdinc", "-undef", str(src)],
                         capture_output=True)
    if cpp.returncode != 0:
        print(f"[{stem}] cpp failed"); continue
    pp = subprocess.run(["iconv", "-f", "UTF-8", "-t", "CP932"],
                        input=cpp.stdout, capture_output=True).stdout
    Path("/tmp/_cc.s").write_bytes(pp)
    oflags = {"irq": "-O0", "random": "-O0", "agb-sram": "-O1", "hardware": "-O0",
              "move-data": "-O0", "oam": "-O0"}.get(stem, "-O2")
    cc = subprocess.run([CC1, "-g", "-mthumb-interwork", "-Wimplicit", "-Wparentheses",
                         "-fhex-asm", "-ffix-debug-line", "-ffunction-sections",
                         oflags, "-o", "/tmp/_cc1.s"], input=pp, capture_output=True)
    if cc.returncode != 0:
        print(f"[{stem}] agbcc failed"); continue
    with open("/tmp/_cc1.s", "a") as fh:
        fh.write(".text\n\t.align\t2, 0\n")
    Path("/tmp/_cc-manifest.json").write_text(json.dumps(
        [{"name": c["name"], "file": c["file"], "addr": c["addr"], "size": 0}
         for c in mine]))
    keep = subprocess.run(["python3", "scripts/filter_c_sections.py",
                           "--manifest", "/tmp/_cc-manifest.json", "--file", stem],
                          stdin=open("/tmp/_cc1.s", "rb"), capture_output=True)
    Path("/tmp/_cc-keep.s").write_bytes(keep.stdout)
    ret = subprocess.run(["arm-none-eabi-as", "-mcpu=arm7tdmi", "-I", "refs/fe7j/include",
                          "/tmp/_cc-keep.s", "-o", "/tmp/_cc.o"], capture_output=True, text=True)
    if ret.returncode != 0:
        print(f"[{stem}] as failed: {ret.stderr[-300:]}"); continue
    subprocess.run(["python3", "scripts/patch_relocs_from_rom.py",
                    "--manifest", "/tmp/_cc-manifest.json", "--rom", "rom/fe7eu.gba",
                    "--file", stem, "/tmp/_cc.o"], check=True, capture_output=True)
    Path("/tmp/chk").mkdir(exist_ok=True)
    Path(f"/tmp/chk/{stem}.o").write_bytes(Path("/tmp/_cc.o").read_bytes())

    ok_n = 0
    for c in mine:
        total += 1
        subprocess.run(["arm-none-eabi-objcopy", "-O", "binary",
                        "--only-section=.text." + c["name"], "/tmp/_cc.o", "/tmp/_cc.bin"],
                       check=True)
        data = open("/tmp/_cc.bin", "rb").read()
        base = c["addr"] - 0x08000000
        want = rom[base:base + len(data)]
        ok = data == want
        ok_n += ok
        tag = "MATCH " if ok else "DIFFER"
        extra = " (integrated)" if c["name"] in integrated else ""
        if not ok:
            diffs = [i for i, (a, b) in enumerate(zip(data, want)) if a != b]
            rngs = []
            for d in diffs:
                if rngs and d - rngs[-1][1] <= 3:
                    rngs[-1][1] = d
                else:
                    rngs.append([d, d])
            rr = ",".join(f"{a:x}" + (f"-{b:x}" if b > a else "")
                          for a, b in rngs[:12])
            extra += f"  diffs@ {rr} ({len(diffs)}B)"
        print(f"  {tag} {c['name']:44s} {c['addr']:#010x} {len(data):#6x}{extra}")
    total_ok += ok_n
    print(f"[{src}] {ok_n}/{len(mine)} candidates match")
print(f"[total] {total_ok}/{total} candidates match")

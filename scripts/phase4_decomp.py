#!/usr/bin/env python3
"""Phase 4 pipeline: decompile EU functions from FE7J asm via m2c and check
which ones compile byte-identical against the EU ROM.

Per function:
  1. extract the JP assembly block from refs/fe7j/asm/<file>
  2. decompile it with m2c (-t gba, context = preprocessed gbafe.h)
  3. compile the C with agbcc into build/p4/<name>.o
  4. patch every relocation from the baserom at the same offset (same trick
     as the integration pipeline) and compare the section bytes against the
     EU ROM at the function's mapped address

Usage:
  phase4_decomp.py inventory                       # rebuild the candidate list
  phase4_decomp.py one <name>                      # single function, verbose
  phase4_decomp.py batch [--limit N] [--min-score S] [--workers N] [--retry]
"""
import argparse
import json
import re
import subprocess
import sys
from concurrent.futures import ProcessPoolExecutor, as_completed
from pathlib import Path

def strip_gccisms(text):
    """Remove GCC extensions m2c's C parser cannot handle."""
    text = re.sub(r"__attribute__\s*\(\([^()]*(?:\([^()]*\)[^()]*)*\)\)", "", text)
    text = re.sub(r"__attribute__\s*\(\([^()]*(?:\([^()]*\)[^()]*)*\)\)", "", text)
    text = re.sub(r"__asm__\s*\([^;]*\)", "", text)
    text = re.sub(r"\b__inline__?\b", "", text)
    text = re.sub(r"\b__extension__\b", "", text)
    text = re.sub(r"\b__restrict__?\b", "", text)
    text = re.sub(r"\b__volatile__\b", " volatile ", text)
    text = re.sub(r"\b__signed__\b", "signed", text)
    text = re.sub(r"\b__builtin_va_list\b", "char*", text)
    text = re.sub(r"\b__builtin_\w+\s*\(", "0 & (", text)
    return text


def prepare_context():
    """Preprocess gbafe.h into an m2c context file (cached), augmented with
    unprototyped declarations for every mapped symbol so m2c does not have to
    invent types for cross-function calls."""
    dst = Path("build/m2c-ctx-clean.c")
    src_ctx = Path("build/m2c-ctx.c")
    if dst.exists() and src_ctx.exists():
        return str(dst)
    raw = strip_gccisms(src_ctx.read_text(errors="replace"))
    known = set(re.findall(r"\b([A-Za-z_]\w*)\s*\(", raw))
    decls = []
    for line in Path("config/eu-symbols-all.txt").read_text().splitlines():
        m = re.match(r"(\S+) = 0x", line)
        if not m:
            continue
        name = m.group(1)
        if name in known or not re.match(r"^[A-Za-z_]\w*$", name):
            continue
        decls.append(f"void {name}();")
    dst.write_text(raw + "\n/* mapped-symbol declarations */\n" + "\n".join(decls) + "\n")
    return str(dst)


def clean_m2c_output(text):
    """Make m2c output compilable by agbcc: resolve unknown-type markers."""
    text = re.sub(r"\? \*", "void *", text)
    text = re.sub(r"\*\?", "void *", text)
    text = re.sub(r"\b\? \(", "s32 (", text)
    text = re.sub(r"\(\?\)", "(void)", text)
    text = re.sub(r"(?<![\w.])\?(?!\w)", "s32", text)
    text = re.sub(r"M2C_ERROR\([^;]*\)", "0", text)
    return text


ROM = Path("rom/fe7eu.gba").read_bytes()
INTEGRATED = {e["name"] for e in json.load(open("config/c-integrated.json"))}
CTX = "build/m2c-ctx.c"
CPP_FLAGS = ["-Irefs/fe7j/tools/agbcc/include", "-iquote", "include",
             "-iquote", "refs/fe7j/include", "-iquote", "refs/fe7j",
             "-nostdinc", "-undef"]
START_RE = re.compile(r"^\s*(thumb_func_start|arm_func_start)\s+(\S+)")
END_RE = re.compile(r"^\s*(thumb_func_end|arm_func_end)\b")
LABEL_RE = re.compile(r"^(\S+):")


def build_inventory():
    syms = json.load(open("config/eu-symbols.json"))
    cands = []
    for s in syms:
        if s.get("mode") != "thumb" or s.get("size", 0) < 4:
            continue
        if s.get("eu_addr") is None or s.get("jp_addr") is None:
            continue
        if s["name"] in INTEGRATED:
            continue
        if not (0x08000000 <= s["eu_addr"] < 0x08800000):
            continue
        cands.append({"name": s["name"], "file": s["file"],
                      "jp_addr": s["jp_addr"], "eu_addr": s["eu_addr"],
                      "size": s["size"], "score": s.get("score", 0)})
    cands.sort(key=lambda c: (-c["score"], c["size"]))
    Path("config/phase4-inventory.json").write_text(json.dumps(cands, indent=1))
    print(f"inventory: {len(cands)} candidates "
          f"(score>=0.9: {sum(1 for c in cands if c['score'] >= 0.9)}, "
          f"score>=0.7: {sum(1 for c in cands if c['score'] >= 0.7)})")
    return cands


def extract_asm(cand):
    path = Path("refs/fe7j/asm") / cand["file"]
    lines = path.read_text(errors="replace").splitlines()
    start = None
    name_re = re.compile(r"^" + re.escape(cand["name"]) + r":")
    for i, line in enumerate(lines):
        if name_re.match(line):
            start = i
            break
    if start is None:
        return None
    body = [f"\t.global {cand['name']}", "\t.thumb_func", lines[start]]
    for line in lines[start + 1:]:
        if START_RE.match(line) or END_RE.match(line):
            break
        m = LABEL_RE.match(line)
        if m and not line.startswith("\t") and m.group(1) != cand["name"]:
            # next function-like label (pool labels are _0800...; keep them)
            if not m.group(1).startswith("_"):
                break
        body.append(line)
    while body and not body[-1].strip():
        body.pop()
    header = ["\t.syntax unified", "\t.thumb"]
    return "\n".join(header + body) + "\n"


def run_m2c(asm_text, name):
    Path("/tmp/p4.s").write_text(asm_text)
    ret = subprocess.run(["m2c", "-t", "gba", "--context", prepare_context(),
                          "--globals", "used", "-f", name, "/tmp/p4.s"],
                         capture_output=True, text=True)
    if ret.returncode != 0:
        return None, ret.stderr.strip().splitlines()[-1] if ret.stderr else "m2c failed"
    return ret.stdout, None


def compile_and_match(cand, c_text):
    name, eu_addr, size = cand["name"], cand["eu_addr"], cand["size"]
    out = Path(f"src-auto/{name}.c")
    out.parent.mkdir(exist_ok=True)
    out.write_text('#include "gbafe.h"\n\n' + clean_m2c_output(c_text))
    cpp = subprocess.run(["arm-none-eabi-cpp", *CPP_FLAGS, str(out)],
                         capture_output=True)
    if cpp.returncode != 0:
        return {"status": "cpp-fail"}
    pp = subprocess.run(["iconv", "-f", "UTF-8", "-t", "CP932"],
                        input=cpp.stdout, capture_output=True).stdout
    cc = subprocess.run(["tools/agbcc/agbcc", "-mthumb-interwork", "-Wimplicit",
                         "-Wparentheses", "-fhex-asm", "-ffix-debug-line",
                         "-ffunction-sections", "-O2", "-o", f"/tmp/p4_{name}.s"],
                        input=pp, capture_output=True)
    if cc.returncode != 0:
        err = cc.stderr.decode(errors="replace").strip().splitlines()[-1] if cc.stderr else ""
        return {"status": "cc-fail", "err": err[:120]}
    asm_file = Path(f"/tmp/p4_{name}.s")
    with asm_file.open("a") as fh:
        fh.write(".text\n\t.align\t2, 0\n")
    obj = Path(f"build/p4/{name}.o")
    obj.parent.mkdir(exist_ok=True)
    ret = subprocess.run(["arm-none-eabi-as", "-mcpu=arm7tdmi", "-I", "refs/fe7j/include",
                          str(asm_file), "-o", str(obj)], capture_output=True, text=True)
    if ret.returncode != 0:
        return {"status": "as-fail"}
    man = Path("/tmp/p4-manifest.json")
    man.write_text(json.dumps([{"name": name, "file": name + ".c",
                                "addr": eu_addr, "size": size}]))
    ret = subprocess.run(["python3", "scripts/patch_relocs_from_rom.py",
                          "--manifest", str(man), "--rom", "rom/fe7eu.gba",
                          "--file", name, str(obj)], capture_output=True, text=True)
    if ret.returncode != 0:
        return {"status": "patch-fail", "err": ret.stdout[-120:]}
    subprocess.run(["arm-none-eabi-objcopy", "-O", "binary",
                    "--only-section=.text." + name, str(obj), "/tmp/p4.bin"],
                   check=True)
    data = Path("/tmp/p4.bin").read_bytes()
    base = eu_addr - 0x08000000
    want = ROM[base:base + size]
    n = min(len(data), size)
    same = sum(1 for i in range(n) if data[i] == want[i])
    return {"status": "ok", "match": same == size and len(data) == size,
            "ratio": round(same / max(size, 1), 3),
            "compiled": len(data), "hole": size}


def process(cand):
    name = cand["name"]
    try:
        asm = extract_asm(cand)
        if asm is None:
            return {**cand, "status": "no-asm"}
        c_text, err = run_m2c(asm, name)
        if c_text is None:
            return {**cand, "status": "m2c-fail", "err": (err or "")[:120]}
        res = compile_and_match(cand, c_text)
        return {**cand, **res}
    except Exception as exc:  # noqa: BLE001
        return {**cand, "status": "error", "err": str(exc)[:120]}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("cmd", choices=["inventory", "one", "batch"])
    ap.add_argument("name", nargs="?")
    ap.add_argument("--limit", type=int, default=200)
    ap.add_argument("--offset", type=int, default=0)
    ap.add_argument("--min-score", type=float, default=0.9)
    ap.add_argument("--workers", type=int, default=8)
    ap.add_argument("--max-size", type=int, default=0x400)
    args = ap.parse_args()

    if args.cmd == "inventory":
        build_inventory()
        return

    cands = json.load(open("config/phase4-inventory.json"))
    if args.cmd == "one":
        cand = next((c for c in cands if c["name"] == args.name), None)
        if cand is None:
            print("not in inventory"); return 1
        res = process(cand)
        print(json.dumps(res, indent=1))
        return 0

    # batch
    todo = [c for c in cands if c["score"] >= args.min_score
            and c["size"] <= args.max_size][args.offset:args.offset + args.limit]
    print(f"[*] batch: {len(todo)} functions "
          f"(score>={args.min_score}, size<={args.max_size:#x})")
    results = []
    with ProcessPoolExecutor(max_workers=args.workers) as pool:
        futures = {pool.submit(process, c): c for c in todo}
        for i, fut in enumerate(as_completed(futures)):
            res = fut.result()
            results.append(res)
            if (i + 1) % 25 == 0:
                m = sum(1 for r in results if r.get("match"))
                print(f"  [{i+1}/{len(todo)}] matches so far: {m}")
    matches = [r for r in results if r.get("match")]
    close = [r for r in results if r.get("status") == "ok" and not r.get("match")
             and r.get("ratio", 0) >= 0.9]
    print(f"[*] done: {len(results)} processed, {len(matches)} byte-exact, "
          f"{len(close)} >=90%")
    # merge with previous runs (keep the best ratio seen per function)
    out_path = Path("config/phase4-results.json")
    merged = {}
    if out_path.exists():
        for r in json.load(open(out_path)):
            merged[r["name"]] = r
    for r in results:
        old = merged.get(r["name"])
        if old is None or r.get("ratio", 0) >= old.get("ratio", 0) \
                or r.get("match") or old.get("status") != "ok":
            merged[r["name"]] = r
    out_path.write_text(json.dumps(list(merged.values()), indent=1))
    for r in matches:
        print(f"  MATCH {r['name']:40s} {r['eu_addr']:#010x} {r['size']:#x} score={r['score']}")
    return 0


if __name__ == "__main__":
    sys.exit(main())

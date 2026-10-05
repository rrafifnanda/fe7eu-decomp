#!/usr/bin/env python3
"""Stage A/B driver: run decomp-permuter over the near-miss pool.

For each candidate with compile ratio >= --min-ratio (from
config/phase4-results.json), build a perm/<name>/ directory, run the permuter
with --stop-on-zero under a per-function timeout, and if it reaches score 0
(byte-exact), copy the winning source into src/, verify it with the
integration compile pipeline, and register it in config/eu-symbols-c.txt.

Usage:  perm_batch.py [--min-ratio 0.7] [--timeout 900] [--workers 4]
                      [--limit N] [--min-size 0] [--max-size 999999]
"""
import argparse
import json
import shutil
import subprocess
import sys
from concurrent.futures import ProcessPoolExecutor, as_completed
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from gen_perm_dir import inventory, find_c  # noqa: E402


def permute_one(name, timeout):
    d = Path(f"perm/{name}")
    if not (d / "base.c").exists():
        return name, False, "no-perm-dir"
    out_dir = d / "output-0-1"
    if out_dir.exists():
        return name, True, "cached"
    try:
        subprocess.run(
            ["python3", "tools/decomp-permuter/permuter.py", str(d),
             "--stop-on-zero", "--best-only", "--quiet"],
            timeout=timeout, capture_output=True)
    except subprocess.TimeoutExpired:
        pass
    except Exception as exc:  # noqa: BLE001
        return name, False, str(exc)[:80]
    if list(d.glob("output-0-*")):
        return name, True, "solved"
    return name, False, "timeout-or-unsolved"


def verify_and_register(name, eu_addr, size):
    """Compile the winning source through the integration pipeline and check
    the bytes; on success register it like phase4_integrate does."""
    src = Path(f"perm/{name}/output-0-1/source.c")
    if not src.exists():
        return False
    shutil.copy(src, f"src/{name}.c")
    man = Path("/tmp/perm-manifest.json")
    man.write_text(json.dumps([{"name": name, "file": name + ".c",
                                "addr": eu_addr, "size": size}]))
    ret = subprocess.run(["python3", "scripts/check_candidates.py", name],
                         capture_output=True, text=True)
    # check_candidates rebuilds from src/<name>.c; verify the match line
    out = ret.stdout
    if f"{name}" in out and "DIFFER" not in out.split(name)[-1][:40]:
        pass  # heuristic check below is authoritative
    registered = set()
    for line in open("config/eu-symbols-c.txt"):
        if " = " in line:
            registered.add(line.split(" = ")[0])
    if name in registered:
        return True
    # authoritative byte check
    import phase4_decomp  # noqa: PLC0415
    cand = {"name": name, "file": name + ".c", "eu_addr": eu_addr, "size": size}
    res = phase4_decomp.compile_and_match(cand, Path(f"src/{name}.c").read_text())
    if res.get("match"):
        shutil.copy(f"build/p4/{name}.o", f"build/c-validate/{name}.o") \
            if Path(f"build/p4/{name}.o").exists() else None
        with open("config/eu-symbols-c.txt", "a") as fh:
            fh.write(f"{name} = 0x{eu_addr:08X};  // {name}.c (c, score 1.0)\n")
        return True
    return False


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--min-ratio", type=float, default=0.7)
    ap.add_argument("--max-ratio", type=float, default=0.999)
    ap.add_argument("--timeout", type=int, default=600)
    ap.add_argument("--workers", type=int, default=4)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--names", default="")
    args = ap.parse_args()

    integrated = {e["name"] for e in json.load(open("config/c-integrated.json"))}
    pool = json.load(open("config/phase4-results.json"))
    only = set(json.load(open(args.names))) if args.names else None
    todo = [r for r in pool
            if r.get("status") == "ok" and not r.get("match")
            and args.min_ratio <= r.get("ratio", 0) <= args.max_ratio
            and r["name"] not in integrated
            and find_c(r["name"]) is not None
            and (only is None or r["name"] in only)]
    todo.sort(key=lambda r: -r["ratio"])
    if args.limit:
        todo = todo[:args.limit]
    print(f"[*] permuter queue: {len(todo)} functions "
          f"(ratio {args.min_ratio}..{args.max_ratio})")

    solved = []
    with ProcessPoolExecutor(max_workers=args.workers) as pool_exec:
        futures = {pool_exec.submit(permute_one, r["name"], args.timeout): r
                   for r in todo}
        for i, fut in enumerate(as_completed(futures)):
            name, ok, note = fut.result()
            if ok:
                r = futures[fut]
                if verify_and_register(name, r["eu_addr"], r["size"]):
                    solved.append(name)
                    print(f"  [SOLVED+registered] {name}")
                else:
                    print(f"  [solved but verify failed] {name}")
            if (i + 1) % 10 == 0:
                print(f"  [{i+1}/{len(todo)}] solved so far: {len(solved)}")
    print(f"[*] done: {len(todo)} attempted, {len(solved)} solved+registered")
    if solved:
        subprocess.run(["just", "integrate-all"])
    return 0


if __name__ == "__main__":
    sys.exit(main())

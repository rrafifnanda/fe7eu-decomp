#!/usr/bin/env python3
"""Map FE7J (Japan) symbols onto the FE7 EU (En,Fr,De) ROM by code matching.

Algorithm (v3):

  1. For every FE7J asm function, collect EU candidate addresses using a masked
     byte pattern (branches / PC-relative loads are wildcards) + normalized
     instruction comparison (Capstone).
  2. Choose a globally consistent assignment with a weighted, order-preserving
     chain (dynamic programming over candidates, Fenwick max). This resolves
     near-identical functions (e.g. Read/Write/VerifySramFast) correctly,
     because the JP and EU functions appear in the same order.
  3. Fill the remaining functions with a local search around the address
     interpolated from the assigned neighbours, then re-run the chain.

Usage (inside `nix develop`):

    python3 scripts/port_symbols.py --fe7j refs/fe7j --rom rom/fe7eu.gba --out config

Outputs in --out:
    jp-symbols.json, eu-symbols.json, eu-symbols.txt (splat),
    eu-symbols-ghidra.csv, phase1-report.md
"""
import argparse
import bisect
import json
import re
import subprocess
import sys
from collections import Counter, defaultdict
from pathlib import Path

try:
    from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_LITTLE_ENDIAN, CS_MODE_THUMB
    from capstone.arm import ARM_OP_MEM, ARM_OP_REG, ARM_REG_PC
except ImportError:
    print("error: capstone is not installed (uv pip install capstone)", file=sys.stderr)
    raise

ROM_BASE = 0x08000000
MIN_NEEDLE = 6
MAX_CANDIDATES = 400
TOKEN_LIMIT = 32
MAX_CANDS_PER_FUNC = 8
COND = {"eq", "ne", "cs", "hs", "cc", "lo", "mi", "pl", "vs", "vc",
        "hi", "ls", "ge", "lt", "gt", "le", "al"}
MODE_MAP = {"thumb": CS_MODE_THUMB, "arm": CS_MODE_ARM}
_MD_CACHE = {}


def md_for(mode):
    if isinstance(mode, str):
        mode = MODE_MAP[mode]
    if mode not in _MD_CACHE:
        md = Cs(CS_ARCH_ARM, mode | CS_MODE_LITTLE_ENDIAN)
        md.detail = True
        _MD_CACHE[mode] = md
    return _MD_CACHE[mode]


def branch_kind(ins):
    mn = ins.mnemonic
    if mn in ("b", "bl", "blx"):
        return "bl" if mn in ("bl", "blx") else "b"
    if mn.startswith("b") and mn[1:] in COND:
        return "b"
    return None


def is_pc_relative(ins):
    for op in ins.operands:
        if op.type == ARM_OP_REG and op.reg == ARM_REG_PC:
            return True
        if op.type == ARM_OP_MEM and op.mem.base == ARM_REG_PC:
            return True
    return False


def normalize(ins):
    br = branch_kind(ins)
    if br:
        return "BL" if br == "bl" else "B"
    if is_pc_relative(ins):
        return ins.mnemonic + " ?"
    return ins.mnemonic + " " + ins.op_str.replace(" ", "")


def token_list(code, mode, limit=TOKEN_LIMIT):
    toks = []
    for ins in md_for(mode).disasm(code, 0):
        toks.append(normalize(ins))
        if len(toks) >= limit:
            break
    return toks


def similarity(jp_toks, eu_toks):
    n = min(len(jp_toks), len(eu_toks), TOKEN_LIMIT)
    if n == 0:
        return 0.0
    return sum(1 for a, b in zip(jp_toks[:n], eu_toks[:n]) if a == b) / n


def build_pattern(code, mode, max_insns=14):
    chunks = []
    for ins in md_for(mode).disasm(code, 0):
        volatile = bool(branch_kind(ins)) or is_pc_relative(ins)
        chunks.append((ins.address, ins.size, volatile))
        if len(chunks) >= max_insns or ins.address + ins.size >= len(code):
            break
    if not chunks:
        return None

    runs = []
    run_start = None
    buf = bytearray()
    for off, size, volatile in chunks:
        if volatile:
            if buf:
                runs.append((run_start, bytes(buf)))
                buf = bytearray()
                run_start = None
        else:
            if run_start is None:
                run_start = off
            buf += code[off:off + size]
    if buf:
        runs.append((run_start, bytes(buf)))
    if not runs:
        return None

    run_off, needle = max(runs, key=lambda r: len(r[1]))
    if len(needle) < MIN_NEEDLE:
        return None
    return {"needle": needle, "run_off": run_off}


def pattern_candidates(rom, code, mode, jp_toks):
    pat = build_pattern(code, mode)
    if pat is None:
        return []
    step = 2 if mode == "thumb" else 4
    out = {}
    cand = 0
    pos = 0
    while cand < MAX_CANDIDATES:
        hit = rom.find(pat["needle"], pos)
        if hit < 0:
            break
        cand += 1
        start = hit - pat["run_off"]
        if start >= 0 and start % step == 0:
            prev = out.get(start)
            if prev is None:
                eu_toks = token_list(rom[start:start + len(code) + 16], mode)
                out[start] = similarity(jp_toks, eu_toks)
        pos = hit + 1
    ranked = sorted(out.items(), key=lambda kv: -kv[1])[:MAX_CANDS_PER_FUNC]
    return [(score, off) for off, score in ranked]


def local_candidates(rom, code, mode, center, window, jp_toks):
    pat = build_pattern(code, mode, max_insns=60)
    step = 2 if mode == "thumb" else 4
    out = {}
    if pat is not None:
        lo = max(0, center - window)
        hi = min(len(rom), center + window)
        cand = 0
        pos = lo
        while cand < 300:
            hit = rom.find(pat["needle"], pos, hi)
            if hit < 0:
                break
            cand += 1
            start = hit - pat["run_off"]
            if start >= 0 and start % step == 0 and start not in out:
                eu_toks = token_list(rom[start:start + len(code) + 16], mode)
                out[start] = similarity(jp_toks, eu_toks)
            pos = hit + 1

    # small first-token scan as a fallback
    md = md_for(mode)
    if not out:
        for pos in range(max(0, center - 0x200), min(len(rom) - 4, center + 0x200), step):
            first = next(md.disasm(rom[pos:pos + 4], 0), None)
            if first is None or normalize(first) != jp_toks[0]:
                continue
            eu_toks = token_list(rom[pos:pos + len(code) + 16], mode)
            out[pos] = similarity(jp_toks, eu_toks)

    ranked = sorted(out.items(), key=lambda kv: -kv[1])[:MAX_CANDS_PER_FUNC]
    return [(score, off) for off, score in ranked]


def best_chain(cands, min_score):
    pairs = []
    for j, lst in enumerate(cands):
        for sc, off in lst:
            if sc >= min_score:
                pairs.append((off, j, sc))
    if not pairs:
        return []
    pairs.sort()

    n = len(cands)
    tree = [float("-inf")] * (n + 2)
    tree_idx = [-1] * (n + 2)

    def query(i):
        best_v, best_k = float("-inf"), -1
        i += 1
        while i > 0:
            if tree[i] > best_v:
                best_v, best_k = tree[i], tree_idx[i]
            i -= i & (-i)
        return best_v, best_k

    def update(i, value, idx):
        i += 1
        while i <= n:
            if value > tree[i]:
                tree[i], tree_idx[i] = value, idx
            i += i & (-i)

    dp = []
    prev = []
    i = 0
    while i < len(pairs):
        j = i
        while j < len(pairs) and pairs[j][0] == pairs[i][0]:
            j += 1
        for k in range(i, j):
            _, ji, sc = pairs[k]
            base, back = query(ji - 1)
            if base == float("-inf"):
                base, back = 0.0, -1
            dp.append(base + sc)
            prev.append(back)
        for k in range(i, j):
            _, ji, _ = pairs[k]
            update(ji, dp[k], k)
        i = j

    k = max(range(len(pairs)), key=lambda x: dp[x])
    chain = []
    while k != -1:
        off, ji, sc = pairs[k]
        chain.append({"jp_idx": ji, "eu_addr": off + ROM_BASE, "score": round(sc, 4)})
        k = prev[k]
    return list(reversed(chain))


def lis_anchors(items):
    """Monotonic anchors from final assignments (safety net)."""
    if not items:
        return []
    vals = [x["eu_addr"] for x in items]
    tails, tails_idx = [], []
    prev = [-1] * len(items)
    for i, v in enumerate(vals):
        j = bisect.bisect_left(tails, v)
        if j > 0:
            prev[i] = tails_idx[j - 1]
        if j == len(tails):
            tails.append(v)
            tails_idx.append(i)
        else:
            tails[j] = v
            tails_idx[j] = i
    out = []
    k = tails_idx[-1]
    while k != -1:
        out.append(items[k])
        k = prev[k]
    return list(reversed(out))


def estimate_addr(anchors, jp_addr):
    js = [a["jp_addr"] for a in anchors]
    i = bisect.bisect_left(js, jp_addr)
    if i == 0:
        a = anchors[0]
        return a["eu_addr"] - (a["jp_addr"] - jp_addr)
    if i == len(anchors):
        a = anchors[-1]
        return a["eu_addr"] + (jp_addr - a["jp_addr"])
    lo, hi = anchors[i - 1], anchors[i]
    span = max(1, hi["jp_addr"] - lo["jp_addr"])
    frac = (jp_addr - lo["jp_addr"]) / span
    return int(lo["eu_addr"] + frac * (hi["eu_addr"] - lo["eu_addr"]))


def parse_asm_file(path):
    syms = []
    mode = "thumb"
    for raw in path.open(encoding="utf-8", errors="replace"):
        s = raw.strip()
        if s.startswith("arm_func_start") or s == ".arm":
            mode = "arm"
        elif (s.startswith("thumb_func_start") or s == ".thumb"
              or s.startswith("non_word_aligned_thumb_func_start")):
            mode = "thumb"
        m = re.match(r"^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*(0x[0-9A-Fa-f]+)", s)
        if m:
            syms.append({"name": m.group(1), "jp_addr": int(m.group(2), 16), "mode": mode})
    return syms


def object_symbols(obj_path, tmp_path):
    subprocess.run(["arm-none-eabi-objcopy", "-O", "binary",
                    "--only-section=.text", str(obj_path), str(tmp_path)],
                   check=True)
    data = tmp_path.read_bytes()
    nm = subprocess.run(["arm-none-eabi-nm", "--defined-only", str(obj_path)],
                        check=True, capture_output=True, text=True).stdout
    syms = []
    for line in nm.splitlines():
        parts = line.split()
        if len(parts) >= 3:
            try:
                addr = int(parts[0], 16)
            except ValueError:
                continue
            syms.append((addr, parts[-1]))
    syms.sort()
    return data, syms


def assemble_asm_files(fe7j, build_dir):
    build_dir.mkdir(parents=True, exist_ok=True)
    objects = {}
    for src in sorted((fe7j / "asm").rglob("*.s")):
        obj = build_dir / (src.stem + ".o")
        if not obj.exists() or obj.stat().st_mtime < src.stat().st_mtime:
            cmd = ["arm-none-eabi-as", "-mcpu=arm7tdmi",
                   "-I", str(fe7j / "asm" / "include"),
                   "-I", str(fe7j / "include"),
                   "-I", str(fe7j / "asm"),
                   str(src), "-o", str(obj)]
            subprocess.run(cmd, check=True, capture_output=True)
        objects[src] = obj
    return objects


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--fe7j", default="refs/fe7j")
    ap.add_argument("--rom", default="rom/fe7eu.gba")
    ap.add_argument("--out", default="config")
    ap.add_argument("--cand-score", type=float, default=0.65)
    ap.add_argument("--accept-score", type=float, default=0.75)
    args = ap.parse_args()

    fe7j = Path(args.fe7j)
    out = Path(args.out)
    out.mkdir(parents=True, exist_ok=True)
    rom = Path(args.rom).read_bytes()

    print(f"[*] FE7J at {fe7j}, ROM {args.rom} ({len(rom):,} bytes)")
    print("[*] assembling FE7J asm files ...")
    objects = assemble_asm_files(fe7j, Path("build/jp-obj"))

    print("[*] parsing symbols ...")
    tmp = Path("build/_text.bin")
    file_syms_map = {src.name: parse_asm_file(src) for src in objects}
    symbols = []
    for src, obj in objects.items():
        file_syms = file_syms_map[src.name]
        if not file_syms:
            continue
        data, obj_syms = object_symbols(obj, tmp)
        index = {}
        for off, name in obj_syms:
            index.setdefault(name, off)
        bounds = sorted(index[s["name"]] for s in file_syms if s["name"] in index)
        bounds.append(len(data))
        for s in file_syms:
            off = index.get(s["name"])
            if off is None:
                continue
            nxt = bounds[bisect.bisect_right(bounds, off)]
            symbols.append({**s, "file": src.name, "size": nxt - off,
                            "code": data[off:nxt]})
    symbols.sort(key=lambda s: (s["jp_addr"], s["file"]))
    print(f"[*] {len(symbols)} JP symbols")

    print("[*] stage 1: candidate search ...")
    cands = []
    for i, s in enumerate(symbols):
        jp_toks = token_list(s["code"], s["mode"])
        if len(jp_toks) < 3:
            cands.append([])
        else:
            cands.append(pattern_candidates(rom, s["code"], s["mode"], jp_toks))
        if (i + 1) % 1000 == 0:
            print(f"    {i + 1}/{len(symbols)}")

    def run_chain(tag):
        chain = best_chain(cands, args.cand_score)
        assigned = [c for c in chain if c["score"] >= args.accept_score]
        print(f"    {tag}: chain={len(chain)}, accepted={len(assigned)}")
        return assigned

    assigned = run_chain("chain 1")
    anchors = lis_anchors(sorted(assigned, key=lambda a: symbols[a["jp_idx"]]["jp_addr"]))

    for width in (0x600, 0x3000, 0xc000):
        have = {a["jp_idx"] for a in assigned}
        filled = 0
        for i, s in enumerate(symbols):
            if i in have:
                continue
            jp_toks = token_list(s["code"], s["mode"])
            if len(jp_toks) < 3:
                continue
            est = estimate_addr([{**a, "jp_addr": symbols[a["jp_idx"]]["jp_addr"],
                                  "eu_addr": a["eu_addr"]} for a in anchors],
                                s["jp_addr"]) - ROM_BASE
            for sc, off in local_candidates(rom, s["code"], s["mode"], est, width, jp_toks):
                if sc >= args.cand_score:
                    cands[i].append((sc, off))
            filled += 1
        names = {symbols[a["jp_idx"]]["name"] for a in assigned}
        chain = best_chain(cands, args.cand_score)
        assigned = [c for c in chain if c["score"] >= args.accept_score]
        anchors = lis_anchors(sorted(assigned, key=lambda a: symbols[a["jp_idx"]]["jp_addr"]))
        print(f"    width {width:#x}: examined {filled}, chain={len(chain)}, accepted={len(assigned)}")

    # Context-validated fill: near-identical neighbours may crowd a correct
    # candidate out of the chain; accept it when it sits where the neighbours
    # predict and does not break the order.
    accepted_idx = {a["jp_idx"] for a in assigned}
    anchors_pts = sorted(
        [{"jp_addr": symbols[a["jp_idx"]]["jp_addr"], "eu_addr": a["eu_addr"]}
         for a in assigned], key=lambda a: a["jp_addr"])
    changed = True
    while changed:
        changed = False
        for i, s in enumerate(symbols):
            if i in accepted_idx or not cands[i]:
                continue
            score, off = max(cands[i], key=lambda c: c[0])
            if score < 0.68:
                continue
            eu = off + ROM_BASE
            est = estimate_addr(anchors_pts, s["jp_addr"])
            if abs(eu - est) > 0x300:
                continue
            prev_eu = max([a["eu_addr"] for a in assigned
                           if symbols[a["jp_idx"]]["jp_addr"] < s["jp_addr"]], default=-1)
            next_eu = min([a["eu_addr"] for a in assigned
                           if symbols[a["jp_idx"]]["jp_addr"] > s["jp_addr"]], default=1 << 40)
            if not (prev_eu < eu < next_eu):
                continue
            assigned.append({"jp_idx": i, "eu_addr": eu, "score": round(score, 4)})
            accepted_idx.add(i)
            anchors_pts = sorted(anchors_pts + [{"jp_addr": s["jp_addr"], "eu_addr": eu}],
                                 key=lambda a: a["jp_addr"])
            changed = True

    # de-duplicate (should not happen, but keep the highest score)
    best_by_addr = {}
    for a in assigned:
        cur = best_by_addr.get(a["eu_addr"])
        if cur is None or a["score"] > cur["score"]:
            best_by_addr[a["eu_addr"]] = a
    assigned = list(best_by_addr.values())

    final = sorted(assigned, key=lambda a: a["eu_addr"])
    mapped_names = {symbols[a["jp_idx"]]["name"] for a in final}

    # Build result records
    results = []
    for i, s in enumerate(symbols):
        entry = {"name": s["name"], "file": s["file"], "mode": s["mode"],
                 "jp_addr": s["jp_addr"], "size": s["size"]}
        hit = next((a for a in final if a["jp_idx"] == i), None)
        if hit:
            entry.update({"eu_addr": hit["eu_addr"], "score": hit["score"],
                          "method": "chain"})
            entry["delta"] = hit["eu_addr"] - s["jp_addr"]
        else:
            best = max(cands[i], key=lambda c: c[0]) if cands[i] else None
            if best and best[0] >= 0.5:
                entry.update({"eu_addr": best[1] + ROM_BASE, "score": round(best[0], 4),
                              "method": "uncertain"})
                entry["delta"] = entry["eu_addr"] - s["jp_addr"]
            else:
                entry["error"] = "not-found"
        results.append(entry)

    print(f"[*] final: {len(final)} mapped / {len(symbols)} ({len(final)/len(symbols):.1%})")

    (out / "jp-symbols.json").write_text(json.dumps(
        [{k: v for k, v in s.items() if k != "code"} for s in symbols], indent=1))
    (out / "eu-symbols.json").write_text(json.dumps(results, indent=1))

    with (out / "eu-symbols.txt").open("w") as fh:
        for a in final:
            s = symbols[a["jp_idx"]]
            fh.write(f"{s['name']} = 0x{a['eu_addr']:08X};  // {s['file']}\n")

    with (out / "eu-symbols-ghidra.csv").open("w") as fh:
        fh.write("name,address\n")
        for a in final:
            fh.write(f"{symbols[a['jp_idx']]['name']},0x{a['eu_addr']:08x}\n")

    # ---------- report ----------
    by_file = defaultdict(lambda: [0, 0])
    for s in symbols:
        by_file[s["file"]][1] += 1
    for a in final:
        by_file[symbols[a["jp_idx"]]["file"]][0] += 1
    uncertain = [r for r in results if r.get("method") == "uncertain"]
    missing = [r for r in results if r.get("error")]

    lines = [
        "# Phase 1 report — FE7J symbols mapped to FE7 EU (AE7X)",
        "",
        f"- JP symbols parsed  : **{len(symbols)}**",
        f"- EU symbols mapped  : **{len(final)}** ({len(final)/len(symbols):.1%})",
        f"- uncertain          : {len(uncertain)}",
        f"- not found          : {len(missing)}",
        "",
        "- JP reference sha1  : 037702b1febd5c9535262165bf030551d153de81",
        "- EU target sha1     : c37e3bae84b53e6972ed7608541a62896fa5d6a3",
        "",
        "## Coverage per asm file",
        "",
        "| file | mapped | total |",
        "|---|---|---|",
    ]
    for name, (m, t) in sorted(by_file.items()):
        lines.append(f"| {name} | {m} | {t} |")
    lines += ["", "## Uncertain (candidate exists, below accept score)", ""]
    for r in sorted(uncertain, key=lambda r: r.get("score", 0))[:50]:
        lines.append(f"- {r['name']} ({r['file']}) score={r.get('score')} "
                     f"jp=0x{r['jp_addr']:08X} eu=0x{r['eu_addr']:08X}")
    lines += ["", "## Not found", ""]
    for r in missing[:80]:
        lines.append(f"- {r['name']} ({r['file']}) jp=0x{r['jp_addr']:08X} size={r['size']:#x}")
    lines += ["", "## Most common JP->EU deltas", ""]
    deltas = Counter(r["delta"] for r in results if "delta" in r)
    for delta, count in deltas.most_common(15):
        lines.append(f"- {delta:+#x}: {count}")

    (out / "phase1-report.md").write_text("\n".join(lines) + "\n")
    print(f"[*] wrote outputs to {out}/")
    return 0


if __name__ == "__main__":
    sys.exit(main())

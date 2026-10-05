#!/usr/bin/env python3
"""Build permuter target.s from the EU ROM disassembly (for EU-diverged
functions whose JP asm does not match the EU bytes).

Branch targets and pointer literals are mapped back to symbol names via the
sorted eu-symbols-all map so the permuter's text scoring matches the
symbolic references the C side uses. objdiff/permuter option
ign_branch_targets handles residual address-text differences.

Usage:  gen_perm_eu_target.py <function-name> [...]
"""
import bisect
import json
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from gen_perm_dir import find_c  # noqa: E402

ROM = Path("rom/fe7eu.gba").read_bytes()


def load_symbols():
    addrs, names = [], {}
    for line in Path("config/eu-symbols-all.txt").read_text().splitlines():
        m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);", line)
        if m:
            a = int(m.group(2), 16)
            addrs.append(a)
            names.setdefault(a, m.group(1))
    addrs.sort()
    return addrs, names


def symbolize(addr, addrs, names):
    i = bisect.bisect_right(addrs, addr) - 1
    if i < 0:
        return None
    base = addrs[i]
    if addr - base > 0x400:
        return None
    sym = names[base]
    return sym if addr == base else f"{sym}+{addr - base}"


def eu_disasm(name, eu_addr, size):
    blob = ROM[eu_addr - 0x08000000: eu_addr - 0x08000000 + size]
    Path("/tmp/eu_fn.bin").write_bytes(blob)
    r = subprocess.run(
        ["arm-none-eabi-objdump", "-d", "-z", "-m", "arm", "-M",
         "force-thumb", f"--adjust-vma={eu_addr}", "/tmp/eu_fn.bin"],
        capture_output=True, text=True)
    out = []
    for line in r.stdout.splitlines():
        m = re.match(r"^\s*([0-9a-f]+):\s+([0-9a-f ]+?)\s+(\S+)\s*(.*)$", line)
        if not m:
            continue
        addr_s, _raw, mnem, args = m.groups()
        addr = int(addr_s, 16)
        args = re.sub(r"\s*@(0x[0-9a-f]+|\.data.*|\.text.*)$", "", args).strip()
        if mnem in ("b", "bl", "blx") or mnem.startswith("b"):
            t = re.search(r"(0x[0-9a-f]+)", args)
            if t:
                args = re.sub(r"0x[0-9a-f]+", f"0x{int(t.group(1),16):x}", args)
        out.append((addr, f"\t{mnem}\t{args}" if args else f"\t{mnem}"))
    return out


def main():
    addrs, names = load_symbols()
    inventory = {c["name"]: c for c in json.load(open("config/phase4-inventory.json"))}
    built = 0
    for name in sys.argv[1:]:
        cand = inventory.get(name)
        c_path = find_c(name)
        if not cand or not c_path:
            print(f"[!] {name}: missing inventory/C")
            continue
        eu, size = cand["eu_addr"], cand["size"]
        d = Path(f"perm/{name}")
        d.mkdir(parents=True, exist_ok=True)
        insns = eu_disasm(name, eu, size)
        lines = ["\t.syntax unified", "\t.thumb", "\t.text", "$t:"]
        for addr, text in insns:
            # symbolize branch targets and word literals
            def repl(m):
                v = int(m.group(0), 16)
                if 0x08000000 <= v < 0x08800000:
                    sym = symbolize(v, addrs, names)
                    if sym:
                        return sym
                return m.group(0)
            if re.match(r"\t(b|bl|blx)\b", text):
                text = re.sub(r"0x[0-9a-f]{7,8}", repl, text)
            if re.match(r"\t\.word\b", text):
                text = re.sub(r"0x[0-9a-f]{7,8}", repl, text)
            label = f"{name}_{addr - eu:X}:" if addr != eu else f"{name}:"
            lines.append(label)
            lines.append(text)
        lines.append(f"\t.size\t{name}, 0x{size:X}")
        (d / "target.s").write_text("\n".join(lines) + "\n")
        shutil_copy_if_needed(d)
        ret = subprocess.run(["arm-none-eabi-as", "-mcpu=arm7tdmi",
                              str(d / "target.s"), "-o", str(d / "target.o")],
                             capture_output=True, text=True)
        if ret.returncode != 0:
            print(f"[!] {name}: {ret.stderr.strip()[:150]}")
            continue
        (d / "base.c").write_text(c_path.read_text())
        built += 1
        print(f"[+] perm/{name} (EU target)")
    print(f"built: {built}")


def shutil_copy_if_needed(d):
    src = Path("scripts/perm_compile.sh")
    dst = d / "compile.sh"
    if not dst.exists():
        dst.write_text(src.read_text().replace("__PERM_ROOT__", str(Path.cwd())))
        dst.chmod(0o755)
    if not (d / "settings.toml").exists():
        (d / "settings.toml").write_text('compiler_type = "gcc"\n')


if __name__ == "__main__":
    sys.exit(main())

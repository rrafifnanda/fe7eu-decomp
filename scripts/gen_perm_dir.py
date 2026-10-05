#!/usr/bin/env python3
"""Build a decomp-permuter directory for one function:
  perm/<name>/base.c       — the current C (from src-auto/ or src/)
  perm/<name>/target.o     — the JP asm block assembled (symbolic refs);
                             byte-equal to the EU ROM for score-1.0 mappings
  perm/<name>/compile.sh   — agbcc pipeline wrapper
  perm/<name>/settings.toml

Usage:  gen_perm_dir.py <function-name> [...]
"""
import json
import re
import shutil
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, "tools/decomp-permuter/src")
from phase4_decomp import extract_asm, strip_gccisms  # noqa: E402
from preprocess import preprocess  # noqa: E402  (permuter's own cpp wrapper)

CPP_FLAGS = ["-Irefs/fe7j/tools/agbcc/include", "-iquote", "include",
             "-iquote", "refs/fe7j/include", "-iquote", "refs/fe7j",
             "-nostdinc", "-undef"]

inventory = {c["name"]: c for c in json.load(open("config/phase4-inventory.json"))}


def find_c(name):
    for p in (Path(f"src-auto/{name}.c"), Path(f"src/{name}.c")):
        if p.exists():
            return p
    return None


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 1
    built = []
    for name in sys.argv[1:]:
        cand = inventory.get(name)
        if cand is None:
            print(f"[!] {name}: not in inventory")
            continue
        c_path = find_c(name)
        if c_path is None:
            print(f"[!] {name}: no C file (run phase4 batch first)")
            continue
        asm = extract_asm(cand)
        if asm is None:
            print(f"[!] {name}: no JP asm")
            continue
        d = Path(f"perm/{name}")
        d.mkdir(parents=True, exist_ok=True)
        # base.c = fully preprocessed, GCC-isms stripped, only the target
        # function kept — self-contained so the permuter's own cpp call works
        pp = strip_gccisms(preprocess(str(c_path), CPP_FLAGS))
        pp = re.sub(r"\n\n+", "\n\n", pp)
        (d / "base_all.c").write_text(pp)
        ret = subprocess.run(["python3", "tools/decomp-permuter/strip_other_fns.py",
                              str(d / "base_all.c"), name],
                             capture_output=True, text=True)
        shutil.move(str(d / "base_all.c"), str(d / "base.c"))
        if ret.returncode != 0:
            print(f"[!] {name}: strip_other_fns failed: {ret.stderr.strip()[:150]}")
            continue
        (d / "target.s").write_text(asm)
        ret = subprocess.run(["arm-none-eabi-as", "-mcpu=arm7tdmi",
                              "-I", "refs/fe7j/include",
                              str(d / "target.s"), "-o", str(d / "target.o")],
                             capture_output=True, text=True)
        if ret.returncode != 0:
            print(f"[!] {name}: target.s failed: {ret.stderr.strip()[:150]}")
            continue
        shutil_copy_compile_sh(d)
        (d / "settings.toml").write_text(
            'compiler_type = "gcc"\n'
            f'function_name = "{name}"\n'
        )
        built.append(name)
        print(f"[+] perm/{name}")
    print(f"built: {len(built)}")
    return 0


def shutil_copy_compile_sh(d):
    src = Path("scripts/perm_compile.sh")
    dst = d / "compile.sh"
    dst.write_text(src.read_text().replace("__PERM_ROOT__", str(Path.cwd())))
    dst.chmod(0o755)


if __name__ == "__main__":
    sys.exit(main())

#!/usr/bin/env python3
"""Keep only the integrated function blocks in an agbcc-generated .s file.

agbcc compiles a whole C file with -ffunction-sections: every function of the
file becomes a `.section .text.<name>` block. Only the functions integrated in
the matching build (config/c-integrated.json) may define symbols — a definition
in a discarded section would shadow the PROVIDE'd symbol for that function's
mapped EU address (ld only honours PROVIDE for symbols not defined by any
input object, and a definition in a discarded section is neither placed nor
overridable). Every other block (.text.<other>, .data, .rodata, .bss) is
dropped, so references from kept functions become plain undefined symbols that
the linker resolves through the mapped-symbol PROVIDEs in fe7eu.lds.

Usage:  filter_c_sections.py --manifest config/c-integrated.json \
            --file <source-stem> < in.s > out.s
"""
import argparse
import json
import re
import sys

SEC = re.compile(r"^\t\.section\s+(\S+?)[,\s]")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--manifest", default="config/c-integrated.json")
    ap.add_argument("--file", required=True, help="source stem, e.g. sysutil")
    args = ap.parse_args()

    keep = {e["name"] for e in json.load(open(args.manifest))
            if e["file"] == args.file + ".c"}

    out, dropping = [], False
    for line in sys.stdin.read().splitlines(keepends=True):
        m = SEC.match(line)
        if m:
            if not dropping:
                # close the finished block with explicit zero padding: gas
                # otherwise pads the section end to 4 with Thumb NOPs
                # (0x46C0) where the ROM uses 0x0000
                out.append("\t.align\t2, 0\n")
            fn = re.match(r"^\.text\.(.+)$", m.group(1))
            dropping = not (fn and fn.group(1) in keep)
        if not dropping:
            out.append(line)
    if not dropping:
        out.append("\t.align\t2, 0\n")
    sys.stdout.write("".join(out))
    return 0


if __name__ == "__main__":
    sys.exit(main())

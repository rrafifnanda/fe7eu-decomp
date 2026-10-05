#!/bin/bash
# Permuter compile wrapper: compile.sh <input.c> -o <output.o>
# Compiles an agbcc-style single-function C file into a .o (no
# -ffunction-sections: the whole .text is the function).
set -e
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
IN="$1"
OUT="$3"
TMP="$(mktemp /tmp/perm_XXXXXX)"
trap 'rm -f "$TMP" "$TMP.s"' EXIT
arm-none-eabi-cpp -Irefs/fe7j/tools/agbcc/include -iquote include \
	-iquote refs/fe7j/include -iquote refs/fe7j -nostdinc -undef "$IN" \
	| iconv -f UTF-8 -t CP932 \
	| tools/agbcc/agbcc -mthumb-interwork -Wimplicit -Wparentheses \
		-fhex-asm -ffix-debug-line -O2 -o "$TMP.s"
printf '.text\n\t.align\t2, 0\n' >> "$TMP.s"
arm-none-eabi-as -mcpu=arm7tdmi -I refs/fe7j/include "$TMP.s" -o "$OUT"

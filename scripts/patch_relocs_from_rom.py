#!/usr/bin/env python3
"""Resolve every relocation of an integrated C function from the ROM itself.

Each candidate is placed at the exact EU address of the original function, so
the final bytes for every relocation are already present in the baserom at the
same offset: branch targets, literal-pool entries, string pointers, RAM-data
pointers — all correct by construction, including references the symbol map
cannot resolve (.rodata literals, statics, unmapped functions). Patching the
section bytes from the ROM and then deactivating the relocation sections
(sh_type = SHT_NULL) leaves ld with plain placement work: no stubs, no layout
shifts, no undefined-reference failures.

agbcc output only produces R_ARM_ABS32 (4 bytes) and R_ARM_THM_CALL (4 bytes)
relocations; anything else fails loudly.

Usage:  patch_relocs_from_rom.py --manifest config/c-integrated.json \
            --rom rom/fe7eu.gba build/c/<file>.o [...]
"""
import argparse
import json
import struct
import sys
from pathlib import Path

SHT_REL = 9
R_ARM_ABS32 = 2
R_ARM_THM_CALL = 10
RELOC_SIZE = {R_ARM_ABS32: 4, R_ARM_THM_CALL: 4}


def patch_object(path, sections, rom):
    """sections: {func_name: rom_addr} for this object's integrated functions."""
    data = bytearray(path.read_bytes())
    e_shoff, = struct.unpack_from("<I", data, 0x20)
    e_shentsize, e_shnum, e_shstrndx = struct.unpack_from("<HHH", data, 0x2E)

    def header(i):
        return e_shoff + i * e_shentsize

    str_off, str_size = struct.unpack_from("<II", data, header(e_shstrndx) + 16)
    strtab = data[str_off:str_off + str_size]

    def name(sh_name):
        return strtab[sh_name:strtab.index(b"\0", sh_name)].decode()

    secs = []
    for i in range(e_shnum):
        h = header(i)
        sh_name, sh_type, _, _, sh_offset, sh_size, _, sh_info = \
            struct.unpack_from("<IIIIIIII", data, h)
        secs.append({"idx": i, "h": h, "name": name(sh_name), "type": sh_type,
                     "off": sh_offset, "size": sh_size, "info": sh_info})

    by_name = {s["name"]: s for s in secs}
    patched = unsupported = 0
    for rel in secs:
        if rel["type"] != SHT_REL:
            continue
        target = secs[rel["info"]]
        fname = target["name"]
        if not fname.startswith(".text."):
            continue
        func = fname[len(".text."):]
        if func not in sections:
            print(f"  [!] {path.name}: relocs for non-integrated {fname}")
            continue
        addr = sections[func]
        n_entries = rel["size"] // 8
        for e in range(n_entries):
            r_offset, r_info = struct.unpack_from(
                "<II", data, rel["off"] + e * 8)
            rtype = r_info & 0xFF
            size = RELOC_SIZE.get(rtype)
            if size is None or r_offset + size > target["size"]:
                unsupported += 1
                continue
            rom_off = addr - 0x08000000 + r_offset
            data[target["off"] + r_offset:target["off"] + r_offset + size] = \
                rom[rom_off:rom_off + size]
            patched += 1
        # deactivate the relocation section: ld then ignores it entirely
        struct.pack_into("<I", data, rel["h"] + 4, 0)   # sh_type = SHT_NULL
        struct.pack_into("<I", data, rel["h"] + 20, 0)  # sh_size = 0

    path.write_bytes(data)
    return patched, unsupported


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--manifest", default="config/c-integrated.json")
    ap.add_argument("--rom", default="rom/fe7eu.gba")
    ap.add_argument("--file", default=None,
                    help="source stem override (when the object name does not "
                         "match the source file, e.g. temp objects)")
    ap.add_argument("objects", nargs="+")
    args = ap.parse_args()

    per_file = {}
    for e in json.load(open(args.manifest)):
        per_file.setdefault(Path(e["file"]).stem, {})[e["name"]] = e["addr"]
    rom = Path(args.rom).read_bytes()

    total_patched = total_bad = 0
    for obj in args.objects:
        path = Path(obj)
        stem = args.file or path.stem
        patched, unsupported = patch_object(path, per_file.get(stem, {}), rom)
        total_patched += patched
        total_bad += unsupported
        print(f"{path}: patched {patched} relocs"
              + (f", UNSUPPORTED {unsupported}" if unsupported else ""))
    if total_bad:
        print(f"[!] {total_bad} unsupported relocations left unpatched")
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())

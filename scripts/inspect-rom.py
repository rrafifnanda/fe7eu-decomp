#!/usr/bin/env python3
"""Identify a GBA ROM: header fields, checksum and sha1.

Usage: python3 scripts/inspect-rom.py <rom.gba>

The sha1 is what matching-decompilation projects document, so compare it with the
project's README to confirm you dumped the exact supported revision.
"""
import hashlib
import sys

KNOWN = {
    "AFEJ": "Fire Emblem: Fūin no Tsurugi (FE6, Japan)",
    "AE7E": "Fire Emblem (FE7, USA)",
    "AE7J": "Fire Emblem: Rekka no Ken (FE7, Japan)",
    "AE7P": "Fire Emblem (FE7, Europe)",
    "BE8E": "Fire Emblem: The Sacred Stones (FE8, USA)",
    "BE8J": "Fire Emblem: Seima no Kōseki (FE8, Japan)",
    "BE8P": "Fire Emblem: The Sacred Stones (FE8, Europe)",
}


def main() -> int:
    if len(sys.argv) != 2:
        print(__doc__)
        return 2

    data = open(sys.argv[1], "rb").read()
    if len(data) < 0xC0:
        print("file is too small to be a GBA ROM")
        return 1

    print(f"size     : {len(data):,} bytes")
    print(f"sha1     : {hashlib.sha1(data).hexdigest()}")
    title = data[0xA0:0xAC].decode("ascii", "replace").rstrip("\0 ")
    code = data[0xAC:0xB0].decode("ascii", "replace")
    maker = data[0xB0:0xB2].decode("ascii", "replace")
    print(f"title    : {title}")
    print(f"game code: {code}   maker: {maker}   version: {data[0xBC]}")
    print(f"guess    : {KNOWN.get(code, 'unknown game code')}")

    checksum = (-(sum(data[0xA0:0xBD]) + 0x19)) & 0xFF
    stored = data[0xBD]
    print(f"checksum : stored 0x{stored:02X}, computed 0x{checksum:02X} -> "
          f"{'OK' if checksum == stored else 'BAD (corrupt or not a GBA ROM)'}")

    if len(data) & (len(data) - 1):
        print("note     : size is not a power of two (unusual for GBA dumps)")
    return 0


if __name__ == "__main__":
    sys.exit(main())

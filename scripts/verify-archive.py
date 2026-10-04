#!/usr/bin/env python3
"""Verify a 7z download before trusting it.

Checks:
  * 7z signature at the start (detects HTML error pages prepended by the server)
  * start-header CRC and expected file size (detects truncation)
  * long runs of zero bytes (detects preallocated/aborted downloads)
  * torrent7z trailer

Usage: python3 scripts/verify-archive.py <file.7z>
"""
import os
import struct
import sys
import zlib

MAGIC = b"7z\xbc\xaf\x27\x1c"


def scan_zero_runs(path: str, run_len: int = 4096):
    """Yield offsets of runs of at least run_len zero bytes (C-level search)."""
    needle = b"\x00" * run_len
    carry = b""
    base = 0
    with open(path, "rb") as fh:
        while True:
            chunk = fh.read(1 << 20)
            if not chunk:
                return
            buf = carry + chunk
            off = buf.find(needle)
            if off >= 0:
                yield base - len(carry) + off
            carry = buf[-(run_len - 1):]
            base += len(chunk)


def main() -> int:
    if len(sys.argv) != 2:
        print(__doc__)
        return 2

    path = sys.argv[1]
    size = os.path.getsize(path)
    head = open(path, "rb").read(32)
    print(f"file : {path}")
    print(f"size : {size:,} bytes")

    ok = True

    if head[:6] != MAGIC:
        print(f"FAIL : no 7z signature at start (first bytes: {head[:8]!r})")
        off = open(path, "rb").read(4096).find(MAGIC)
        if off >= 0:
            print(f"       magic found at offset {off} — archive is HTML-prefixed, not usable as-is")
        else:
            print("       archive header is missing entirely — not recoverable")
        ok = False
    else:
        crc_stored = struct.unpack("<I", head[8:12])[0]
        next_off, next_size = struct.unpack("<QQ", head[12:28])
        crc_calc = zlib.crc32(head[12:32]) & 0xFFFFFFFF
        expected = 32 + next_off + next_size
        print(f"7z header CRC : {'OK' if crc_stored == crc_calc else 'MISMATCH'}")
        print(f"expected size : {expected:,} bytes")
        if size < expected:
            print(f"FAIL : truncated by {expected - size:,} bytes")
            ok = False
        elif size > expected:
            print(f"note : {size - expected:,} trailing bytes (torrent7z trailer or junk)")
        if crc_stored != crc_calc:
            ok = False

    for i, off in enumerate(scan_zero_runs(path)):
        if i == 0:
            print(f"FAIL : zero-filled region starts at offset {off:,} — download was aborted/zero-padded")
            ok = False
        if i >= 4:
            print("       ...")
            break

    tail = open(path, "rb").read()[-64:] if size > 64 else b""
    print(f"torrent7z trailer : {'yes' if b'torrent7z' in tail else 'no'}")

    print("RESULT :", "looks usable" if ok else "DO NOT USE — re-download or re-dump")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())

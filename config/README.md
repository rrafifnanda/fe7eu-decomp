# splat configuration

Note: splat does **not** support the GBA platform (only n64/psx/ps2/psp), so the EU ROM
split is produced by `scripts/split_eu.py` instead — see the Phase 1 section in the
root README.

This directory holds the phase 1 outputs:

- `jp-symbols.json` — FE7J reference symbols (name + JP address)
- `eu-symbols.txt` — mapped EU symbols, `name = 0xADDR;`
- `eu-symbols.json` — full mapping with scores/methods
- `eu-symbols-ghidra.csv` — Ghidra label import
- `phase1-report.md` — coverage report

For future from-scratch work, splat configs would live here too.

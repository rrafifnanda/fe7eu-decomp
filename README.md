# Fire Emblem (GBA) — Decompilation Workbench

Personal-use workbench for decompiling / studying the Game Boy Advance *Fire Emblem* games.
It provides the matching toolchain (agbcc + `arm-none-eabi` + armips), an emulator with a GDB
stub (mGBA), and the usual reverse-engineering tools (Ghidra, splat, m2c, permuter).

> **Legal:** no ROM is included. Use a dump of your own cartridge and never redistribute it.
> Decompilation is done for interoperability/study of a game you own.

## Status

- [x] Nix workbench (ARM7TDMI toolchain, agbcc, mGBA, Ghidra, splat/m2c/permuter)
- [x] ROM dump verified: **Fire Emblem (Europe) (En,Fr,De)**, code `AE7X`,
      sha1 `c37e3bae84b53e6972ed7608541a62896fa5d6a3`
- [x] **Phase 1 complete** — FE7J symbols mapped onto the EU ROM, split and round-trip verified
- [x] **Phase 2 complete** — matching build skeleton rebuilds the ROM byte-identically
      (`sha1sum -c` OK) and 872 FE7J C functions are located in the EU ROM
- [ ] Phase 3 — decompile module by module (in progress)

## Quick start

```sh
cd ~/fire-emblem-decomp
nix develop                 # enter the workbench

just fetch-tools            # clone splat/m2c/permuter/agbcc (already done once)
just agbcc                  # build the agbcc compiler (one-time, ~10 min)

cp /path/to/your/dump.gba rom/baserom.gba
just inspect                # title, game code, revision + sha1
just run                    # play it in mGBA

# Pick the matching decomp project and build:
just project https://github.com/FireEmblemUniverse/fireemblem8u
cp rom/baserom.gba game/baserom.gba
just agbcc-install game
cd game && make -j"$(nproc)"
```

## Which Fire Emblem?

| Game | Region | Decomp project |
|---|---|---|
| FE6 — Fūin no Tsurugi | JP | `FireEmblemUniverse/fireemblem6j` |
| FE7 — Rekka no Ken | JP | `MokhaLeee/FireEmblem7J` |
| FE8 — Seima no Kōseki | JP | `laqieer/fireemblem8j` |
| FE8 — The Sacred Stones | US | `FireEmblemUniverse/fireemblem8u` (most mature) |

Full list: <https://laqieer.github.io/fe-decomp-portal/>

Matching decompilation requires the **exact revision** of the cartridge. Compare the sha1
printed by `just inspect` with the sha1 documented in the project's README.

## Phase 1 — cross-region symbol map (done)

No FE7 EU/US decompilation exists publicly; the only FE7 project is
`MokhaLeee/FireEmblem7J` (Japan, partial). Its `asm/` files still carry the original JP
addresses in comments (`Name: @ 0x080C05B8`), so it can be used as a reference to locate
every function in the EU ROM — even without the Japanese ROM.

```sh
just port-symbols   # map FE7J symbols onto the EU ROM (config/eu-symbols.*)
just split-eu       # split the EU ROM into asm/eu/*.s
just verify-split   # reassemble and compare with the ROM
```

| metric | value |
|---|---|
| JP symbols parsed | 6,248 |
| mapped to EU | **4,837 (77.4%)** |
| split modules | 87 |
| round-trip verification | **87/87 files byte-exact** |

Artifacts:

- `config/eu-symbols.txt` — symbol file (`name = 0xADDR;`)
- `config/eu-symbols.json` — full results with scores/methods
- `config/eu-symbols-ghidra.csv` — labels for Ghidra import
- `config/phase1-report.md` — coverage per module and remaining failures
- `asm/eu/*.s` — split, reassemblable EU assembly

The ~1,400 unmapped symbols are mostly EU-specific code (extra languages/menus),
functions whose code changed too much, and tiny BIOS wrappers; they are listed in the
report. Spot checks: `ReadSramFast_Core`=0x080C0640, `WriteSramFast`=0x080C0680,
`VerifySramFast_Core`=0x080C06C0, `SetSramFastFunc`=0x080C070C.

## Phase 2 — matching build skeleton (done)

The EU ROM is rebuilt from `asm/eu` plus baserom fill chunks through the same toolchain
that matching decompilation uses (`arm-none-eabi-as` → `ld` → `objcopy`):

```sh
just build-skeleton   # generate fe7eu.lds + fill chunks + fe7eu.sha1
just build-rom        # make -j
just compare          # sha1sum -c fe7eu.sha1
```

Result: `fe7eu.gba` (16,777,216 bytes) is byte-identical to the original dump.

### C reuse seed

`scripts/check_c_reuse.py` compiles every FE7J `src/*.c` with agbcc (the same pipeline
as its makefile) and locates the resulting functions in the EU ROM:

| metric | value |
|---|---|
| C files compiled | 84/84 |
| functions located (score >= 0.9) | **872** |
| weak matches | 244 |

Outputs: `config/c-reuse-report.md`, `config/eu-symbols-c.txt`, merged into
`config/eu-symbols-all.txt`. These functions are the first candidates to wire into the
build in Phase 3.

## Phase 3 — C functions into the matching build (in progress)

Progress so far:

| step | result |
|---|---|
| FE7J C files compiled with agbcc (`-ffunction-sections`) | 84/84 |
| C functions located in the EU ROM (order-preserving chain per source file) | **885** |
| merged symbol map (`config/eu-symbols-all.txt`) | 5,724 symbols |
| candidates linkable without unresolved references | 342 |
| **functions integrated into the matching build** | **257** ✅ |
| C bytes replacing assembly in the ROM | 12,948 |

The integration runs as a differential build loop (`just integrate-all`,
`scripts/integrate_all.py`): every linkable candidate is placed at its EU
address, the ROM is rebuilt, and any candidate whose bytes differ is dropped
(together with candidates that referenced it) until the rebuild matches the
baserom sha1 exactly. The final ROM is byte-identical to the original dump.

Two toolchain pitfalls the pipeline works around (binutils 15.3):

- `ld` appends interworking stubs to any section whose `bl` targets a
  linker-script symbol, shifting the fixed `AT()` layout — so external
  references are resolved at *assembly* time instead: `gen_symbol_defs.py`
  emits `.set name, address` definitions (with the Thumb bit) into each C
  object, and gas resolves the calls itself.
- `gas` pads section ends to 4 bytes with Thumb NOPs (`0x46C0`) where the ROM
  uses zeros — `filter_c_sections.py` appends an explicit `.align 2, 0` to
  every kept function block.

Not yet integratable: 71 located functions reference discarded `.rodata`
(string literals / jump tables — needs rodata placement first) and 472 more
reference symbols absent from the map.

Tools added in this phase:

- `scripts/check_c_reuse.py` — compile FE7J C sources and locate the functions in the EU
  ROM (`just check-c-reuse`).
- `scripts/validate_c_functions.py` — compile + link each function at its EU address and
  compare with the ROM (`just validate-c`).
- `scripts/parse_fe7j_symbols.py` — extract RAM/data symbol addresses from FE7J's linker
  script so C relocations can be resolved.
- `scripts/gen_integration.py` — build `config/c-integrated.json` from the validated list.
- `scripts/split_eu.py --integrate` — split the asm modules into parts around the
  integrated functions (holes).
- `scripts/gen_eu_build.py --integrated` — place every C `.text.<func>` section at its ROM
  address in the linker script.

The Makefile now compiles the integrated C files with the agbcc pipeline
(`cpp | iconv | agbcc -ffunction-sections | as | strip`) and links them into
`fe7eu.gba`, which still matches the baserom sha1 exactly.

How to re-run the integration (idempotent):

```sh
just integrate-all     # candidates -> differential build loop -> manifest
make -j && sha1sum -c fe7eu.sha1
```

Next steps: unlock the remaining located candidates — place `.rodata` so the 71
string/jump-table users can link, and extend the symbol map for the 472 with
unknown references — then decompile the ~81% of functions that FE7J never
converted to C with Ghidra + m2c + permuter.

## Tools in the shell

| Tool | Purpose |
|---|---|
| `gcc-arm-embedded` (`arm-none-eabi-*`) | assembler/linker/GCC/gdb for ARM7TDMI |
| `agbcc` | matching C compiler (GCC 2.95-based) built in `tools/agbcc` |
| `armips` | assembler used by pret-style build systems |
| `mgba` | emulator + GDB stub (`mgba -g rom.gba`) |
| `ghidra` | interactive ARM/Thumb decompiler |
| `rizin` | CLI disassembly |
| `splat` | binary splitting, symbols, GBA platform support |
| `m2c` | ARM/Thumb → C decompiler |
| `tools/decomp-permuter/permuter.py` | brute-forces matching C |
| `uv` | Python tooling venv (`.venv/`) |

## Layout

```
config/    splat configurations
asm/       disassembly output
src/       decompiled C sources
include/   headers (game structs, hardware regs)
rom/       your ROM dumps (git-ignored)
game/      cloned decompilation project (git-ignored)
scripts/   helper scripts
tools/     external tools: splat, m2c, decomp-permuter, agbcc (git-ignored)
```

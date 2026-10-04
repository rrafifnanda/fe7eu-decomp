set shell := ["bash", "-uc"]

# List recipes
default:
    @just --list

# Enter the Nix development shell
shell:
    nix develop

# Set up the Python tooling venv (auto-run by the shell hook)
tools:
    uv venv --python python3 .venv
    uv pip install "./tools/splat[mips]" "./tools/m2c"

# Clone external tools that are not vendored
fetch-tools:
    test -d tools/splat || git clone --depth 1 https://github.com/ethteck/splat tools/splat
    test -d tools/m2c || git clone --depth 1 https://github.com/matt-kempster/m2c tools/m2c
    test -d tools/decomp-permuter || git clone --depth 1 https://github.com/simonlindholm/decomp-permuter tools/decomp-permuter
    test -d tools/agbcc || git clone --depth 1 https://github.com/pret/agbcc tools/agbcc

# Build the agbcc matching compiler (one-time, takes a while)
agbcc:
    cd tools/agbcc && ./build.sh

# Install agbcc into a cloned decomp project
agbcc-install project:
    cd tools/agbcc && ./install.sh ../../{{project}}

# Identify a GBA ROM (title, game code, version, sha1, header checksum)
inspect rom="rom/baserom.gba":
    python3 scripts/inspect-rom.py "{{rom}}"

# Run a ROM in mGBA
run rom="rom/baserom.gba":
    mgba "{{rom}}"

# Clone a decomp project into game/
project url:
    git clone "{{url}}" game

# ---- Phase 1: FE7 EU symbol map ----

# Map FE7J symbols onto the FE7 EU ROM (configure refs/fe7j first)
port-symbols:
    python3 scripts/port_symbols.py --fe7j refs/fe7j --rom rom/fe7eu.gba --out config

# Split the EU ROM using the mapped symbols
split-eu:
    python3 scripts/split_eu.py --rom rom/fe7eu.gba --symbols config/eu-symbols.json --out asm/eu --integrate config/c-integrated.json

# Build the integration manifest for validated C functions
gen-integration:
    python3 scripts/gen_integration.py

# Full phase 3 integration: manifest -> split with holes -> build skeleton
integrate-c: gen-integration
    python3 scripts/split_eu.py --rom rom/fe7eu.gba --symbols config/eu-symbols.json --out asm/eu --integrate config/c-integrated.json
    python3 scripts/gen_eu_build.py --rom rom/fe7eu.gba --asm-dir asm/eu --integrated config/c-integrated.json

# Integrate every linkable located C function (differential build loop)
integrate-all:
    python3 scripts/integrate_all.py

# Verify that every split file reassembles byte-exactly
verify-split:
    python3 scripts/verify_split.py --rom rom/fe7eu.gba --dir asm/eu

# Run the whole phase 1 pipeline
phase1: port-symbols split-eu verify-split

# ---- Phase 2: matching build skeleton ----

# Generate fill chunks + linker script + sha1 target
build-skeleton:
    python3 scripts/gen_eu_build.py --rom rom/fe7eu.gba --asm-dir asm/eu --integrated config/c-integrated.json

# Rebuild the EU ROM from the split artifacts
build-rom:
    make -j

# Rebuild and verify against the baserom sha1
compare: build-rom
    sha1sum -c fe7eu.sha1

# Locate FE7J C-compiled functions in the EU ROM (phase 3 seed)
check-c-reuse:
    python3 scripts/check_c_reuse.py --fe7j refs/fe7j --rom rom/fe7eu.gba --out config/c-reuse-report.md

# Validate that C functions compile+link byte-identically to the ROM
validate-c:
    python3 scripts/validate_c_functions.py --fe7j refs/fe7j --rom rom/fe7eu.gba --out config/c-validation-report.md

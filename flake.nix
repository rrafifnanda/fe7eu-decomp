{
  description = "Fire Emblem (GBA) decompilation workbench";

  inputs.nixpkgs.url = "https://channels.nixos.org/nixpkgs-unstable/nixexprs.tar.zst";

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };

      # manylinux wheels in the uv venv (e.g. Levenshtein) need the C++ runtime
      libstdcpp = pkgs.stdenv.cc.cc.lib;
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        name = "fire-emblem-decomp";

        packages = with pkgs; [
          # Binary analysis
          ghidra
          rizin
          hexyl
          unixtools.xxd
          file
          binutils

          # ARM7TDMI toolchain (GBA)
          gcc-arm-embedded # arm-none-eabi-{gcc,as,ld,objcopy,ar,gdb}
          armips # assembler used by pret-style build systems

          # Emulation / debugging (mGBA also exposes a GDB stub: mgba -g)
          mgba

          # Build tooling
          gcc
          gnumake
          cmake
          ninja
          pkg-config
          libpng
          zlib
          git
          curl
          wget
          unzip
          which
          jq
          just
          p7zip

          # Python tooling
          python312
          uv
          libstdcpp
        ];

        shellHook = ''
          export PROJECT_ROOT="$(git rev-parse --show-toplevel 2>/dev/null || pwd)"

          # Let manylinux wheels in .venv find the Nix C++ runtime.
          export LD_LIBRARY_PATH="${libstdcpp}/lib''${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"

          # splat, m2c and the permuter's Python deps live in a uv-managed venv.
          if [ ! -x "$PROJECT_ROOT/.venv/bin/splat" ] \
             || ! "$PROJECT_ROOT/.venv/bin/python" -c 'import toml' >/dev/null 2>&1; then
            echo "[setup] creating/updating Python tool venv (first run downloads from PyPI)..."
            uv venv --python ${pkgs.python312}/bin/python3 "$PROJECT_ROOT/.venv" >/dev/null
            uv pip install --python "$PROJECT_ROOT/.venv/bin/python" \
              "$PROJECT_ROOT/tools/splat[mips]" "$PROJECT_ROOT/tools/m2c" \
              toml Levenshtein ply pynacl docker
          fi

          export PATH="$PROJECT_ROOT/.venv/bin:$PROJECT_ROOT/tools/agbcc:$PROJECT_ROOT/tools/decomp-permuter''${PATH:+:$PATH}"

          echo ""
          echo "Fire Emblem (GBA) decomp workbench"
          echo "  arm-none-eabi-as : $(command -v arm-none-eabi-as || echo MISSING)"
          echo "  armips           : $(command -v armips || echo MISSING)"
          echo "  mgba             : $(command -v mgba || echo MISSING)"
          echo "  splat / m2c      : $(command -v splat || echo MISSING) / $(command -v m2c || echo MISSING)"
          echo "  ghidra           : $(command -v ghidra || echo MISSING)"
          if [ -x "$PROJECT_ROOT/tools/agbcc/agbcc" ]; then
            echo "  agbcc            : built"
          else
            echo "  agbcc            : not built yet (run: just agbcc)"
          fi
          echo ""
        '';
      };
    };
}

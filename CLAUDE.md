# CLAUDE.md — working notes for this repo

A native PC port of **The New Tiptris** (N64 game by H2O) via N64Recomp. See
`README.md` for the project overview and build-from-source steps.

> **Naming/legal:** never say "Tetris" in commits/docs/comms — call it **The New
> Tiptris** by **H2O**. Functional symbol names in generated code (e.g.
> `Tetris_Update`) are fine. **Never commit the ROM or any game data** (graphics,
> audio, level data, rendered frames); only recompiled *code* is committed.

## Build & test

```bash
# Configure + build the app (Linux/WSL2)
cmake -S . -B build-cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build-cmake -j

# One-command green/red gate: symbol invariant + cmake configure + build+link.
# The definitive headless check after any rename/reorg/code change.
./tools/verify.sh            # add --boot for a Dozen runtime smoke test
```

## RE / source-navigation tools (`tools/`)

The recompiled game code is in `RecompiledFuncs/<domain>/<subsystem>.c` (register-
level MIPS-in-C: `ctx->rN`, `MEM_W/H/B`, absolute addrs as `lui`+offset).
`tnt.syms.toml` is the canonical symbol map — rename/regroup there (see the memory
`tnt-source-improvement-model`).

- `tools/callgraph.py <fn> [--callers|--callees -d N]` — a function's callers/callees
  and call tree. **The fastest way to map a subsystem** before naming/hooking it.
- `tools/complexity.py` — rank functions by cyclomatic complexity.
- `tools/coverage.py [--domains]` — named-vs-placeholder progress.
- `tools/reorganize_recompiled.py` — re-bucket functions into the domain hierarchy
  (rerun after a regen or a prefix-changing rename).

## Mods (`mods/`)

Full mod system ships in the cloned libs (librecomp loader + recompui menu +
RecompModTool). See `mods/README.md`.

- **Build a mod:** `./mods/build_mod.sh <dir>` → `mods/<dir>/build/<id>.nrm`
  (clang `-target mips` → `mips-linux-gnu-ld` → RecompModTool). **No ROM needed** —
  builds against `tnt.syms.toml`.
- **RecompModTool** isn't in the main CMake; build once:
  `cmake -S lib/N64ModernRuntime/N64Recomp -B build-modtool -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -G Ninja -DCMAKE_BUILD_TYPE=Release && cmake --build build-modtool --target RecompModTool`
- **Author a mod:** include **only `modding.h`**; hook/patch with
  `RECOMP_HOOK("GameFn")` / `RECOMP_PATCH`; reach game RAM via raw KSEG0 pointers
  (`*(volatile unsigned int*)0x800CF928`). Hooked names must exist in `tnt.syms.toml`.
- ⚠️ **This runtime does NOT export `recomp_printf`** (or the rest of
  `recomputils.h`). Including `recomputils.h` makes a mod fail to load
  ("Imported function not found"). No mod-side logging is available.
- Install: drop the `.nrm` in `~/.local/share/N64Recomp/TheNewTiptris/mods/`
  (or use the in-game Mods menu). `enabled_by_default = true` auto-enables it.

## Headless run + screenshot harness (WSL2)

Used to visually verify rendering/menu/gameplay/intro changes without the user.

```bash
# Auto-boot straight into the game (TNT_ROM skips the launcher click), Dozen GPU:
TNT_ROM="$HOME/.local/share/N64Recomp/TheNewTiptris/tnt.n64.us.z64" \
  VK_ICD_FILENAMES="$PWD/dzn/dzn_icd.json" ./build-cmake/TntRecompiled > /tmp/tnt.log 2>&1 &
```

Capture the game window **from the Windows side** (WSL2 has no Linux capture tools;
WSLg apps are real Windows windows). Helper scripts live in `C:\Users\Public\`:
- `winburst.ps1 <titleMatch> <outdir> <count> <delayMs>` — poll for the window
  (EnumWindows, title contains "Tiptris"), then burst-capture the window rect.
- `montage.ps1 <indir> <out> <cols> <tw> <th>` — contact sheet of frames.
- `compare.ps1` — labeled before/after. `winrect.ps1` — print the window rect.

Then copy frames from `/mnt/c/Users/Public/...` and view with the Read tool.

**Gotchas:**
- Linux `sleep` is SIGSTKFLT-blocked (exit 144) — pace loops with PowerShell
  `Start-Sleep` (Windows side), not Linux `sleep`.
- The app exits 139 (segfault) on window close under Dozen — **not** a real failure.
- Launch the game with `run_in_background: true`; kill with
  `kill -9 $(pgrep -f build-cmake/TntRecompiled)`.
- `zip` isn't installed; `build_mod.sh` has a Python zip fallback (`.nrm` is a zip).

## Persistent memory

Longer-lived project context lives in the memory dir (loaded via `MEMORY.md`):
`tnt-mods-infrastructure`, `tnt-source-improvement-model`, `tnt-callgraph-tool-idea`.
Check there for the mod scene-machine addresses, RE findings, and workflow details.

# CLAUDE.md — working notes for this repo

A native PC port of **The New T64ris** (N64 game by H2O) via N64Recomp. See
`README.md` for the project overview and build-from-source steps.

> **Naming/legal:** never say "Tetris" in commits/docs/comms — call it **The New
> T64ris** by **H2O**. Functional symbol names in generated code (e.g.
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

**Names are living — refine as you learn.** Whenever you work with a function or
global whose current name is vague, generic, or turns out to be *wrong* (RE or live
testing reveals its real role), immediately rename it to something more accurate via
`tools/rename_sym.py` (functions gated by `verify.sh`, datasyms by `datacoverage.py
--check`). Cross-validated corrections are the best kind (e.g. static RE + an E2E
RAM-diff both pointing at the same role). Don't leave a known-imprecise name in place
"for later" — fix it in the same pass, and note the old→new in the commit.

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
- ✅ **recompui IS available to mods** (enabled in `src/main.cpp` via
  `recompui::register_ui_exports()` + a `recomp_run_ui_callbacks` base export). Include
  `recompui.h` (in `mods/common/include/`) to build REAL UI screens — element trees, styled
  text/buttons, images, click callbacks, and **input capture** (the game behind gets no input,
  the clean fix for the overlay input-leak). This is the framework for new menus/screens/states;
  see `docs/MODDING-UI.md` and the reference mod `mods/recompui-demo`. The in-game-aesthetic
  (block-background + native fade) path is separate — see `docs/STAGE_SELECT_ENHANCEMENTS.md`.
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
  (EnumWindows, title contains the match; window title is "The New T64ris :
  Recompiled" — the helpers default to the rebrand-proof substring "Recompiled"),
  then burst-capture the window rect.
- `montage.ps1 <indir> <out> <cols> <tw> <th>` — contact sheet of frames.
- `compare.ps1` — labeled before/after. `winrect.ps1` — print the window rect.

Then copy frames from `/mnt/c/Users/Public/...` and view with the Read tool.

**What you can/can't drive:**
- The game **auto-boots** into the attract flythrough → title → cycling attract
  **demos** (auto-played gameplay). All of that is capturable with **no input**.
- **Input injection WORKS via the in-app `TNT_INPUT` overlay** (RecompFrontend-0003
  dep patch). WSLg/Wayland blocks *external* synthetic input (Windows SendKeys/
  PostMessage hit the RAIL proxy, not the Wayland stream; xdotool is X11-only;
  ydotool needs root uinput the compositor ignores) — so input is injected from
  *inside* the app instead. Launch with `TNT_INPUT=/path/to/file`; while set,
  `poll_inputs()` uses the SDL scancodes in that file as the SOLE key state each
  controller poll — the **real keyboard is ignored**, so tests get exclusive control
  and a stray physical keypress can't corrupt a run.
  Drive it from bash: write scancodes to hold keys, empty the file to release
  (pace with PowerShell `Start-Sleep`). Key scancodes: **Start=40** (RETURN),
  **A=29** (Z, accept), **B=27** (X, back), **D-pad Up/Down/Left/Right=82/81/80/79**.
  Tip: hold ~1-2s to land the press on the intended screen (a brief tap can fall in
  a transition). Verified: holding Start on the title advances to the main menu. So
  menus, level select, data/options submenus, and real gameplay ARE now drivable and
  self-verifiable.
- **Graphics settings ARE verifiable without input:** edit
  `~/.local/share/N64Recomp/TheNewTiptris/graphics.json` (keys: `msaa_option`
  None/MSAA2X/4X/8X, `res_option` Original/Original2x/Auto, `hr_option`
  Original/Clamp16x9/Full, `ds_option`, `ar_option`), relaunch, and screenshot the
  flythrough. NOTE: the RmlUi launcher/menus always render at native window res —
  only the **game** rendering reflects `res_option`, so capture a game frame.
- `controls.json` holds keyboard mappings (SDL scancodes; input_type 1 = keyboard).

**Gotchas:**
- Linux `sleep` is SIGSTKFLT-blocked (exit 144) — pace loops with PowerShell
  `Start-Sleep` (Windows side), not Linux `sleep`.
- **`dzn/dzn_icd.json` hardcodes an ABSOLUTE `library_path` to `dzn/libvulkan_dzn.so`.**
  It is gitignored, so a `git grep` for the repo path won't find it. If the repo
  folder is moved/renamed, update this path or Vulkan init fails with "Missing
  required extension: VK_KHR_surface" → the game aborts at startup (SIGABRT in
  `ultramodern::init_events`). Fix: point `library_path` at the current
  `$PWD/dzn/libvulkan_dzn.so`.
- Repeated Dozen/Vulkan **startup crashes can wedge the WSLg display** for the rest
  of the shell session: subsequent launches then fail instantly (exit 1, no log
  written at all). If that happens, the headless harness / `TNT_INDIRECT_TRACE`
  tracer is unusable until a fresh session with a clean display — not a code fault.
- The app exits 139 (segfault) on window close under Dozen — **not** a real failure.
- Launch the game **alone** in `run_in_background: true` (combining a `kill`/`&`
  in the same backgrounded command trips exit 144/1). Kill separately with
  `ps aux | grep '[b]uild-cmake/TntRecompiled' | awk '{print $2}' | xargs -r kill -9`.
- `zip` isn't installed; `build_mod.sh` has a Python zip fallback (`.nrm` is a zip).

## E2E test harness (`tools/e2e/`)

Drive the headless game from Python to iterate/regression-test: launch, **wait on
game RAM**, assert properties, **inject input**. Three inert-by-default runtime
channels (app side in `src/main.cpp` + the TNT_INPUT patch):
`TNT_STATE_OUT`/`TNT_STATE_WATCH` (per-frame RAM dump + `_frame` heartbeat),
`TNT_STATE_POKE` (force RAM), `TNT_INPUT` (inject scancodes).

```python
from harness import Game, Keys
with Game(mods=["tnt_scene_crash_guard"]) as g:   # optional mod A/B
    g.wait_alive(); g.wait_for("scene", lambda v: v==3)   # attract
    g.press(Keys.START, hold=3.0)                          # -> menu (scene 4)
    g.poke(0x800CFEE8, 1, 4)                               # force state
```
`tools/e2e/run.sh` runs `test_*.py`. The harness forces SDL **dummy audio** (flaky
WSLg PulseAudio otherwise stalls boot) and paces with `select()` (SIGSTKFLT-safe).
Validated: smoke (boot→attract) + navigate (START→scene 4) pass; the crash test
**reproduces the scene-4 SIGSEGV** deterministically. See `tools/e2e/README.md`.

## Persistent memory

Longer-lived project context lives in the memory dir (loaded via `MEMORY.md`):
`tnt-mods-infrastructure`, `tnt-source-improvement-model`, `tnt-callgraph-tool-idea`.
Check there for the mod scene-machine addresses, RE findings, and workflow details.

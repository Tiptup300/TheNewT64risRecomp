# Testing — the full suite, how it's organized, and what each test confirms

This project has **three layers of automated checking**. From fastest/most-fundamental to
slowest/most-integrated:

1. **`tools/verify.sh`** — the green/red **build gate** (no GPU, seconds).
2. **`tests/`** — the **pytest suite**: structured, mod-isolated integration tests that drive the
   real headless game and assert on live RAM (proper framework, fixtures, `.venv-test`).
3. **`tools/e2e/`** — **E2E driver scripts**: standalone `test_*.py` each with a `main()` returning
   an exit code, run by `tools/e2e/run.sh`. Older/looser than the pytest suite; some are also
   investigation harnesses.

Plus two **lint gates** on the symbol maps: `datacoverage.py --check` (data symbols) and the
symbol-set invariant inside `verify.sh` (functions).

---

## Layer 1 — `tools/verify.sh` (the gate)

Run: `./tools/verify.sh` (add `--boot` for a Dozen runtime smoke test). One command, prints a single
**GREEN / RED**. Checks, in order:

| step | what it confirms |
|---|---|
| recompiled symbol set | every `RECOMP_FUNC` is defined **exactly once** — no duplicate/missing symbols (a rename that drops or doubles a symbol fails here). Currently **1430 functions**. |
| cmake configure | the build configures (refreshes the file glob) |
| build + link | the whole `TntRecompiled` app compiles and links |

This is the definitive headless check after any rename/reorg/code change. It does **not** run the
game — it proves the recompiled C still forms a valid, buildable program.

**Data-symbol lint** (`python3 tools/datacoverage.py --check`): no duplicate vram, valid names.
Currently **963 symbols, 838 named, no dup vram**. Gates datasym renames.

---

## Layer 2 — `tests/` (pytest suite)

Run: `tests/run.sh` (whole suite) · `tests/run.sh tests/test_menu.py` (one file) ·
`tests/run.sh -k gameplay -x` (filter + stop on first fail). Uses a project-local `.venv-test`.

**Config** (`pytest.ini`): `testpaths = tests`, `python_files = test_*`, `python_functions = test_*`,
`addopts = -v -ra --tb=short`.

**Naming convention:** one file per area `test_<area>.py`; each check is a top-level function
`test_<behavior>(game)` with a docstring stating what it proves; internal helpers are `_prefixed`
(not collected).

**The `game` fixture** (`conftest.py`): factory `game(mods=(), **Game_kwargs)` → a *started* `Game`
(the `tools/e2e/harness.py` object), stopped at teardown. **Mod-isolated**: every test runs with
`HOME`+`XDG_DATA_HOME` redirected to a throwaway `tmp_path`, so it never reads/writes your real
`~/.local/share/N64Recomp` mods or saves. Default = **zero mods**; opt in with `game(mods=["intro-skip"])`
(built on demand, cached by mtime). Seeds a known-good `graphics.json`/`controls.json` so the game
boots under Dozen.

**Tests (9 total across 5 files):**

| file · test | what it confirms |
|---|---|
| `test_boot.py :: test_boots_to_attract` | the game boots headless and reaches the attract flythrough (scene 3) |
| `test_boot.py :: test_no_mods_loaded_by_default` | a default run loads **zero** mods — isolation proof (doesn't inherit your installed mods) |
| `test_menu.py :: test_three_selectable_items_one_pad` | main menu (scene 4): with 1 pad, DOWN cycles the 3 selectable items 3→5→6 (MULTI PLAYER @4 greyed/skipped) |
| `test_menu.py :: test_multiplayer_unlocked_with_two_pads` | MULTI PLAYER (cursor 4) becomes selectable with a 2nd controller |
| `test_gameplay.py :: test_one_player_start_reaches_gameplay` | full path ONE PLAYER → START → gameplay (scene 9); also a **Controller-Pak crash regression guard** (fresh isolated mem-pak, the sign-extension SIGSEGV must not recur) |
| `test_mod_isolation.py :: test_requested_mod_is_loaded` | a test that asks for a mod gets exactly that mod loaded/enabled |
| `test_mod_isolation.py :: test_user_installed_mods_do_not_leak` | when a test requests one mod, your *other* installed mods are absent — isolation proof |
| `test_mempak.py :: test_mempak_created_at_config_dir` | booting creates the mem-pak at the config dir as a valid empty 32 KB image (relocated off `$HOME`) |
| `test_mempak.py :: test_seeded_pak_survives_relaunch` | a seeded pak persists across a relaunch and loads crash-free — write/load/persist round-trip + the sign-extension-crash regression |

---

## Layer 3 — `tools/e2e/` (E2E driver scripts)

Run: `tools/e2e/run.sh` (all) · `tools/e2e/run.sh test_smoke` (one). Each is a standalone script
whose `main()` returns exit 0=pass / 1=fail; the runner reports `N passed, M failed`.

**Naming convention:** `test_<scenario>.py` with a module docstring + a `main()`. (These predate the
pytest suite; the pytest layer is the more structured home for new regression tests.)

**Tests (6):**

| script | what it confirms |
|---|---|
| `test_smoke.py` | boots headless → attract (scene 3); validates the whole E2E pipeline (launch → RAM heartbeat → scene progression) |
| `test_navigate.py` | input injection works E2E — holding START advances the scene machine; logs the scene transitions |
| `test_menu.py` | scene-4 cursor cycles 3/5/6 with 1 pad (4 selectable with 2); A enters a submenu, B backs out, no crash |
| `test_to_gameplay.py` | full menu → ONE PLAYER → SINGLE → ACCEPT → gameplay (scene 9), screenshotting each transition |
| `test_new_screen.py` | a mod can CALL a game function (`displayText_XY_RGBA_2` via indirect jalr) from a hook and draw text without crashing (`mods/new-screen-poc`) |
| `test_crash_guard.py` | A/B: forcing scene 4 without its resource load SIGSEGVs **without** `mods/scene-crash-guard` and **survives with** it |

### Not tests — investigation harnesses in `tools/e2e/`
The rest of `tools/e2e/*.py` are tools, not pass/fail tests: `harness.py`/`e2e_helpers.py`/`states.py`
(the framework), `probe_*`/`drive_*`/`dump_*`/`explore_*`/`map_themes.py` (RE probes), and
`verify_*` one-offs (`verify_stage_load.py`, `verify_recompui_demo.py`, `verify_recompui_click.py`,
`probe_native*.py`) that check a specific mod/feature during development.

---

## Results (last full run, 2026-08-16)

**Everything green — 15 game-driven tests + 2 static gates all pass.**

- **`verify.sh` gate**: ✅ GREEN — 1430 functions (no dup/missing), configure + build + link ok.
- **`datacoverage.py --check`**: ✅ OK — 963 symbols, 838 named, no dup vram.
- **pytest suite (`tests/`)**: ✅ **9 passed** in 274s (4m34s) — test_boot ··, test_gameplay ·,
  test_mempak ··, test_menu ··, test_mod_isolation ··.
- **e2e suite (`tools/e2e/`)**: ✅ **6 passed, 0 failed** — test_smoke, test_menu, test_navigate,
  test_new_screen, test_to_gameplay, test_crash_guard.

## Gotchas
- Each game boot is ~20–40 s under Dozen, so the pytest + e2e suites take a few minutes each.
- Repeated Dozen/Vulkan crashes can wedge WSLg for the session; `wsl --shutdown` clears it.
- Launches need `VK_ICD_FILENAMES=$PWD/dzn/dzn_icd.json`; the harness forces SDL dummy audio and
  uses `select()`-based waits (Linux `sleep` is SIGSTKFLT-blocked here).

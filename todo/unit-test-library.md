# TODO ★ TOP PRIORITY — Python unit-test library (pytest), mod-isolated, headless

**Status:** proposed / not started
**Priority:** #1 (user-set 2026-08-08)
**Rough size:** ~½ day (extends the existing `tools/e2e/` harness; ~70% already exists)

## Goal

A real **pytest**-based unit/integration test library for the game that:
1. **Runs headless** (CI-able; no manual interaction) — already true of the harness.
2. **Does NOT interfere with the user's installed mods / saves** — tests run in a
   fully isolated data dir; the real `~/.local/share/N64Recomp/...` is never touched.
3. **Explicitly selects which mods a test loads** — a test declares its mod set;
   only those mods are present/enabled for that run (default = *no* mods).

## Why the current harness isn't enough (the gap)

`tools/e2e/harness.py` is Python + headless and takes `Game(mods=[...])`, but its
`_apply_mods()` **edits the user's real `~/.local/.../mods.json` in place** and
restores it on `stop()`. Problems: (a) it *mutates the user's actual config* (racy;
left dirty if a test dies before restore), and (b) the user's installed mods are still
**scanned and present** — it only toggles their enabled flag. So tests today inherit
`tnt_wonders_rebalance`, `tnt_intro_skip`, etc. (visible in boot logs). That is exactly
the interference to eliminate.

## Isolation design (verified against librecomp)

The config + mods directory is `SDL_GetPrefPath("N64Recomp","TheNewTiptris")` =
`$XDG_DATA_HOME/N64Recomp/TheNewTiptris/` (see `src/main.cpp:437`,
`recomp.cpp:register_config_path`); mods are scanned from `<config>/mods/` and enabled
via `<config>/mods.json` (`mods.cpp:scan_mod_folder`). **Therefore:**

- **Redirect `XDG_DATA_HOME`** (per test session) to a throwaway temp dir → the game
  gets a pristine config/mods/saves tree, completely separate from the user's.
- **Also redirect `HOME`** for the same run, because `pak.cpp` currently derives
  `mempak.bin` from `$HOME` directly (not the config path). *(Alternative/cleaner:
  fix `pak.cpp` to place `mempak.bin` under the config dir like other saves — then a
  single `XDG_DATA_HOME` override isolates everything, including the pak. Recommended
  small refactor.)*
- The **ROM** stays reachable: `TNT_ROM` is an absolute path, so isolating
  `XDG_DATA_HOME`/`HOME` doesn't break ROM loading. `graphics.json`/`controls.json`
  are absent in the fresh dir → the game writes defaults (fine; Dozen comes from
  `VK_ICD_FILENAMES`).
- **Seed the isolated `mods/`** with ONLY the requested built `.nrm` files + a
  `mods.json` whose `enabled_mods` is exactly that list. Default = empty (no mods).

## Proposed structure

```
tests/                         # pytest root (separate from tools/e2e discovery tools)
  conftest.py                  # fixtures: isolated_data_dir, game factory, mod builder
  pytest.ini / pyproject.toml  # testpaths=tests, markers, etc.
  test_boot.py                 # boots to attract (no mods)
  test_menu.py                 # main-menu nav (port from tools/e2e/test_menu.py)
  test_gameplay.py             # ONE PLAYER -> START -> scene 9 (port test_to_gameplay)
  test_mempak.py               # create profile -> name entry -> save survives relaunch
  test_mods/
    test_crash_guard.py        # A/B a specific mod via the mod-selection fixture
```

- **`game` fixture / factory:** wraps the existing `Game` class but forces an isolated
  `XDG_DATA_HOME`+`HOME` (tmp dir, auto-removed) and seeds the mod set. Yields a
  started `Game`; tears down on exit. Reuses all existing state/input/watch plumbing.
- **Mod selection:** a `@pytest.mark.mods("tnt_scene_crash_guard", ...)` marker (or a
  parametrized fixture) → conftest builds each named mod if stale
  (`mods/build_mod.sh`) and copies its `.nrm` into the isolated `mods/`. No mark ⇒ no
  mods.
- **Headless runner:** `pytest tests/` (or a thin `tools/e2e/run.sh` replacement).
  Keep SDL dummy audio + `select()` pacing (SIGSTKFLT-safe) from the harness.

## Work items

1. Extend `Game` (or add an `IsolatedGame` subclass) to accept an isolated data dir +
   a concrete mod list, seeding `mods/` + `mods.json` instead of editing the real one.
   Remove/deprecate the in-place `_apply_mods` mutation for tests.
2. *(recommended)* `pak.cpp`: place `mempak.bin` under the config dir, not `$HOME`.
3. `tests/conftest.py`: `isolated_data_dir`, `game` factory, `mods` marker + builder.
4. `pytest.ini`/`pyproject.toml`: testpaths, markers registry, sane timeouts.
5. Port `test_smoke` / `test_menu` / `test_to_gameplay` into `tests/` as pytest tests;
   add a mem-pak persistence test and a mod A/B test.
6. Docs: `tests/README.md` + a CLAUDE.md note; wire into `tools/verify.sh --tests`?

## Acceptance
- `pytest tests/` runs headless and green with **zero** of the user's installed mods
  loaded (boot log shows no `Opening mod …` unless a test asked for it).
- A test can request a specific mod and observe its effect; another test in the same
  run sees none.
- Running the suite never modifies `~/.local/share/N64Recomp/...` (verify mtimes).

## Notes / risks
- Keep the isolated tmp dir on a real fs (not a weird overlay) so SDL pref path works.
- WSLg still opens a window; "headless" here = scriptable + no human input, same as
  the current harness (true offscreen would need a separate effort).
- One mod build the first time is slow; cache by mtime.

# `tests/` — headless, mod-isolated pytest suite

Integration tests that drive the real recompiled game headlessly and assert on live
RAM + boot behavior. Built on the `tools/e2e/` harness; run under a project-local
pytest venv (`.venv-test`).

## Run

```bash
tests/run.sh                      # whole suite (creates .venv-test + installs pytest on first run)
tests/run.sh tests/test_menu.py   # one file
tests/run.sh -k gameplay -x       # filter + stop on first failure
tests/run.sh -q                   # quiet
```

`tests/run.sh` uses `./.venv-test/bin/python -m pytest`. To use pytest directly:
`./.venv-test/bin/python -m pytest`.

## What makes it safe (mod isolation)

Every test runs the game with **`HOME` + `XDG_DATA_HOME` redirected to a throwaway
per-test dir** (pytest's `tmp_path`). That isolates the game's *entire* config/mods/
saves tree — including the `mempak.bin` — from your real
`~/.local/share/N64Recomp/...`. Tests **never** read or write your installed mods or
saves. (Verified: `test_no_mods_loaded_by_default` + `test_user_installed_mods_do_not_leak`.)

The fixture seeds the isolated config from your machine's known-good
`graphics.json`/`controls.json` (read-only copy) so the game boots with proven
settings — a *fresh* config would emit `res_option:"Auto"` / `rr_option:"Display"`
defaults that crash under Dozen/WSLg.

## Selecting mods per test

Default = **zero mods**. Opt in explicitly with directory names under `mods/`:

```python
def test_default(game):
    g = game()                        # no mods loaded at all

def test_with_mod(game):
    g = game(mods=["intro-skip"])     # builds mods/intro-skip, seeds+enables only it
```

Named mods are built on demand (`mods/build_mod.sh`, cached by mtime), their `.nrm`
copied into the isolated `mods/`, and a `mods.json` written enabling exactly them.

## The `game` fixture

`game(mods=(), **Game_kwargs)` returns a **started** `Game` (see
`tools/e2e/harness.py`) and stops it at teardown. Kwargs pass through, e.g.
`game(controllers=2)`. Use the harness API on the returned object:
`wait_alive()`, `wait_for("scene", pred)`, `read("menu_cursor")`, `tap(Keys.DOWN)`,
`press(Keys.START, hold=3.0)`, `crashed()`, `log_path`.

## Tests

| file | covers |
|---|---|
| `test_boot.py` | boots to attract; **zero mods by default** (isolation) |
| `test_menu.py` | main-menu nav: 3 items w/ 1 pad, MULTI PLAYER unlocked w/ 2 |
| `test_gameplay.py` | ONE PLAYER → START → gameplay (scene 9); also a **Controller-Pak crash regression guard** (fresh isolated mem-pak) |
| `test_mod_isolation.py` | a requested mod loads; the user's other mods don't leak in |
| `test_mempak.py` | Controller-Pak created at the config dir; a seeded pak **survives a relaunch** and the game loads it crash-free (write/load/persist round-trip) |

## Notes / gotchas
- Each game boot takes ~20–40s under Dozen, so the full suite is a few minutes.
- Headless here = scriptable + no human input (WSLg still opens a window).
- `.venv-test/` and `.pytest_cache/` are git-ignored.
- Uses SDL dummy audio + `select()`-based waits (SIGSTKFLT-safe), inherited from the harness.

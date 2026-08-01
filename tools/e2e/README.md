# E2E test harness

Drive the headless game end-to-end from Python: **launch**, **wait on game state**,
**assert properties**, and **inject controller input** to navigate menus / play — so
we can actually iterate and regression-test.

## How it works

Three runtime channels (all inert unless their env var is set — zero release cost):

| Channel | Env var | Direction | Where |
|---|---|---|---|
| **State export** | `TNT_STATE_OUT` + `TNT_STATE_WATCH` | game → harness | `src/main.cpp` (`tnt_state_dump`, per frame) |
| **State poke** | `TNT_STATE_POKE` | harness → game | `src/main.cpp` (`tnt_state_poke`, per frame) |
| **Input inject** | `TNT_INPUT` | harness → game | RecompFrontend patch (`poll_inputs`) |

Each frame the app atomically rewrites `TNT_STATE_OUT` with `name=value` lines for the
watched addresses plus a `_frame` heartbeat. The harness polls that file to wait on /
read state. `TNT_STATE_POKE` forces RAM (level-triggered). `TNT_INPUT` ORs SDL scancodes
onto the keyboard (level-triggered: write to hold, empty to release). Audio is forced to
SDL `dummy` so a flaky WSLg PulseAudio can't block boot.

## Usage

```bash
tools/e2e/run.sh                 # run all tests
tools/e2e/run.sh test_smoke      # run one
python3 tools/e2e/test_smoke.py  # or directly
```

```python
from harness import Game, Keys
with Game() as g:                       # auto-boots to attract
    g.wait_alive()                      # heartbeat advancing
    g.wait_for("scene", lambda v: v == 3, desc="attract")
    g.press(Keys.START, hold=3.0)       # inject START for 3s, then release
    g.wait_for("scene", lambda v: v == 4, desc="menu hub")
    assert g.read("obj_slot_buf") != 0
    g.poke(0x800CFEE8, 1, 4)            # force a value (held until clear_pokes())
```

### `Game(...)` options
- `rom=` path to the ROM (default: the installed copy).
- `watches=` `{name: (addr, width)}` (default: `DEFAULT_WATCHES` — scene, song, game
  flags, frame counters, the crash-critical `obj_slot_buf` @0x80129200, …).
- `mods=` list of mod ids to enable for this run (backs up + restores `mods.json`),
  e.g. `mods=["tnt_scene_crash_guard"]`. `None` = leave installed config untouched.
- `no_autoboot=True` to start at the launcher instead of auto-booting.

### Methods
`wait_alive()`, `wait_for(name, pred, timeout, desc)`, `read(name)`, `state()`,
`frame()`, `wait_frames(n)`, `press(*keys, hold, release)`, `hold(*keys)`, `release()`,
`poke(addr,width,value)`, `poke_lines([...])`, `clear_pokes()`, `alive()`, `crashed()`.

Scancodes (`Keys`): `START`(40) `A`(29) `B`(27) `UP`(82) `DOWN`(81) `LEFT`(80) `RIGHT`(79).

## Tests
- `test_smoke.py` — boots headless and reaches the attract flythrough (scene 3).
- `test_navigate.py` — proves input injection reaches the game (START advances the
  scene) and logs the scene machine.
- `test_crash_guard.py` — A/B the scene-4 crash with/without `mods/scene-crash-guard`.

## Requirements / gotchas
- `build-cmake/TntRecompiled` built; a ROM installed; a working WSLg display.
- Pace with the harness (it uses `select()`, immune to this env's SIGSTKFLT `sleep`).
- Repeated GPU crashes can wedge WSLg for the session → launches fail instantly;
  `wsl --shutdown` + relaunch clears it. The app's exit 139 on window close is benign.

# GAME_STATE_MAP.md — the game's state and how input drives it

The reference behind the modding framework. Every address here was **reproduced** —
driven by an input and watched to change (via `tools/e2e/probe_inputs.py`), or read
across a known transition — not guessed. The machine-readable twin is
`tools/e2e/states.py` (`GLOBALS`, `SCENES`, `STATE_KEYS`); keep the two in sync.

> Method: `probe_inputs.py <state>` drives to a state, taps each input, and reports the
> RAM addresses it *reliably* moves, after subtracting a control-noise floor (addresses
> that change on their own) and keeping only addresses that move on **every** repeat.
> That filter is what makes results legible under the menu/gameplay 3D animation.

---

## 1. The scene machine — `g_currentScene` @ `0x800CFEE8` (u8)

One byte selects the top-level state; `Scene_Update` dispatches on it. Setting
`g_sceneChanged` @ `0x800CFD48` = 1 asks the game to run the transition.

| value | scene | notes |
|---|---|---|
| 0 | branding (N64 logo) | boot |
| 1 | branding (publisher) | boot |
| 2 | intro cube-tiles | animated intro |
| 3 | attract flythrough / title | **self-contained & safe to jump to**; START → menu |
| 4 | main menu hub | widget engine (`Scene_Main` @ `0x80099674`) |
| 7 | wonders hall | |
| 8 | wonders (sub) | |
| 9 | gameplay (active) | the falling-cubes game |
| 10 | game over | |
| 11 | pause menu | reached from 9 via START |
| 12, 13 | attract demo | auto-played gameplay (no input) |
| 14 | options / data | scores / controller-pak / audio / credits |
| 16 | credits | |

**Transition safety.** Advancing to a *self-contained* scene (3 attract) by writing the
byte is safe. **Never blindly write `g_currentScene = 4`** (or 9): those scenes need a
resource-load step first, and skipping it leaves scene-object buffers null →
`Scene_SetupObjectMatrices` faults. Go through the game's own transition instead. See
§5 and `mods/scene-crash-guard`.

---

## 2. Session / mode globals

| name | addr | w | meaning |
|---|---|---|---|
| `g_currentSong` | `0x8011E4F8` | 1 | music track 0..7 (forced by `mods/map-select`) |
| `g_gameMode` | `0x80110A01` | 1 | game mode |
| `g_gameInitialized` | `0x80110A02` | 1 | 1 after `Game_Init` |
| `g_playercount` | `0x8011EF20` | 1 | 1 or 2 |
| `g_selectedGameType` | `0x8011EEEC` | 1 | selected mode from the menu |
| `g_gameFrameCounter` | `0x801109F4` | 4 | advances every gameplay frame (a timer signal) |

---

## 3. The menu widget engine (scene 4)

`Scene_Main` @ `0x80099674` runs a table-driven menu. Item table at `sceneCtx+0x124`;
each item is a 0x38-byte struct (`+0x24` flags [`0x8000` = selectable], `+0x28`
callback, `+0x30` callback arg, `+0x0C` value id). Cursor and sub-state live in fixed
globals that the probe moves with the D-pad and A:

| name | addr | w | driven by |
|---|---|---|---|
| `g_sceneMenuCursor` | `0x800D3D00` | 4 | **UP / DOWN** — the highlighted item index |
| `g_sceneMenuPrevCursor` | `0x800D3D10` | 4 | trails the cursor |
| `g_sceneMainState` | `0x800D3D24` | 4 | **A** — advances into a submenu |
| `g_menuHubState` | `0x800D7520` | 4 | hub sub-state |
| `g_sceneObjRenderEnable` | `0x800D3D94` | 4 | input/render lock during transitions |

Main-menu item order (cursor value): the reach-helpers use **ONE PLAYER = 3**,
**WONDERS = 5** (see `tools/e2e/e2e_helpers.py`). The full screen-by-screen tree with
screenshots is `docs/MENU_MAP.md`; code binding is `docs/MENU_TREE.md`.

### Data / profile (controller-pak) screen (scene 14)
| name | addr | w | meaning |
|---|---|---|---|
| `g_saveDataScreenCursor` | `0x800D3DEC` | 1 | file-list highlight |
| `g_dataMenuPakFileCount` | `0x80110580` | 4 | number of pak files present |

---

## 4. Gameplay (scene 9)

Input during play is edge-triggered through **`g_buttonsPressed` @ `0x8011EF54`** (u32
mask), and the live piece/board hang off three pointers:

| name | addr | w | meaning |
|---|---|---|---|
| `g_currentPiece_ptr` | `0x8011FB70` | 4 | → active piece struct (position / rotation / gate / alpha) |
| `g_mobileCubes_ptr` | `0x8011FBF0` | 4 | → locked / board cubes |
| `g_minos_ptr` | `0x8011FC10` | 4 | → mino set |
| `g_buttonsPressed` | `0x8011EF54` | 4 | per-frame edge-triggered input mask |

### Active-piece fields — input → what moves
<!-- PROBE-GAMEPLAY: filled from probe_inputs.py gameplay (reproducibility-filtered,
     gravity subtracted as control noise). Each row = an address the input reliably
     moves during play, with the field role inferred from the driving input. -->
_(Pending the gameplay probe pass; populated with the exact `*g_currentPiece_ptr`
field offsets that LEFT/RIGHT move (column), that A/B move (rotation), and that DOWN
moves (row/drop), each confirmed by driving the input and watching it change. Gravity —
which moves the row on its own — is filtered out as control noise so only
input-attributable fields remain.)_

---

## 5. The scene-4 / start-without-setup crash (know this before you touch scenes)

`Scene_SetupObjectMatrices` (`0x8009EED4`) writes 16 object-slot matrices into the
buffer pointed to by `g_sceneObjSlotMatrixBuf` @ `0x80129200`. That buffer is allocated
only by the normal scene resource-load path and NULLed at teardown. Enter scene 4 (or a
game) without that load — by forcing the scene byte, or the attract demo starting a
game — and the pointer is null; the unmasked store folds ~2 GB into the runtime's guard
region → SIGSEGV. Repointing that one pointer (`mods/scene-crash-guard`) stops the first
fault but the state has more uninitialized pointers, so the crash moves downstream. The
real fix is to **not enter the scene without its load step**. `obj_slot_buf` @
`0x80129200` (== 0 in the broken state) is the tell.

---

## 6. Using this map

- Watch/read any of these live: `tools/e2e/harness.py` (`Game.read(name)` /
  `region=` snapshots) — names come from `DEFAULT_WATCHES`, kept in sync with
  `states.py:GLOBALS`.
- Re-derive input→address for any state: `python tools/e2e/probe_inputs.py <state>`
  (`--list` for states; `--region logic|gameplay|full`).
- Turn a found address into a mod: `docs/MODDING.md` §2 (reach RAM by pointer or
  datasym name), §6 (hook-point catalog).

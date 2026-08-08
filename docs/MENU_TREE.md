# The New T64ris — front-end / menu tree (code-bound map)

**Authoritative code map of the front-end.** Behavior ground truth is in
[`MENU_OBSERVED.md`](MENU_OBSERVED.md) (what the screens *do*, from live play); this
file binds that behavior to concrete **functions and globals** (addresses verified by
static RE + the E2E harness, cross-checked 2026-08-08). When behavior and code
disagree, `MENU_OBSERVED.md` wins — fix the mapping here.

All code cited is in `RecompiledFuncs/misc/Scene.c` unless noted. Addresses are guest
KSEG0 (`0x8xxxxxxx`). Function/global names are the current `tnt.syms.toml` /
`tnt.datasyms.toml` names.

---

## 1. Scene dispatch (`g_currentScene` @0x800CFEE8, u8)

`Scene_Update` dispatches per-frame on `g_currentScene`:

| scene | handler | meaning |
|---:|---|---|
| 2 | CubeTiles_SceneUpdate | intro cube-tiles animation (A skips) |
| 3 | Gfx_CubeSceneUpdate | attract flythrough / title → A/Start sets scene 4 |
| 4 | `MenuHub_StartPlaying` (0x80090E08) **+** `Scene_Main` (0x80099674) | **MENU HUB** — the whole front-end widget engine (MENU, SINGLE, MULTI, OPTIONS all live here) |
| 7 | wonders1_Update/Draw | WONDERS game mode (main-menu item) |
| 8 | wonders3 | Wonders hall/viewer |
| 9 | GameMode_PlayingTick | **active gameplay** |
| 10 | game_over_display… | game over / results |
| 11 | GameMode_PausedTick | pause (PauseMenu_*) |
| 12/13 | GameMode_AttractCountdown/AdvanceGdl | attract demo |
| 14 | OptionsDataMenu_Process (0x8004AD7C) | OPTIONS / DATA (Controller-Pak) menu |
| 16 | Credits_Update | credits |

The front-end is a **data-driven widget engine**, not per-screen state code: MENU,
SINGLE, MULTI and OPTIONS are all **scene 4**, distinguished by which menu-object
table is loaded, not by the scene id.

## 2. The scene-4 widget engine (`Scene_Main` @0x80099674)

`Scene_Main` (misc/Scene.c:26629, size 0x3D8C) is the per-frame driver. Each frame it
loops over the scene's **menu objects** (player loop `s2 < 4`) from the item table at
`sceneCtx->0x124`. Every item is a **0x38-byte struct**:

| off | field | meaning |
|---:|---|---|
| +0x00 | count | option count / max (used by value spinners) |
| +0x0C | value id | game-mode / value id byte (the "Play item" payload) |
| +0x24 | input-response mask (halfword) | which inputs this item reacts to; **bit 0x8000 = active/selectable** (cleared ⇒ greyed & skipped). Direction/confirm bits drive nav & spinners. *(Exact per-bit direction map has minor trace disagreement — verify against code for a specific bit.)* |
| +0x28 | callback ptr | invoked via `LOOKUP_FUNC(item+0x28)` on action |
| +0x30 | arg / value-object ptr | callback arg; for spinners, ptr to the value object |

**Cursor:** `g_sceneMenuCursor` @0x800D3D00 is an **int32 array indexed by screen/
player id** (`cursor[id*4]`), not a scalar. Main-menu items take values 3/4/5/6.
Previous cursor saved in `g_sceneMenuPrevCursor` @0x800D3D10.

**Cursor movement between items:** `Scene_ShowObjectsForward` @0x80091744 /
`Scene_ShowObjectsReverse` @0x80091440 scan entries by 0x38 stride, **skip any item
with `+0x24 & 0x8000` clear (greyed)**, and return the next selectable index (written
back into `g_sceneMenuCursor[id]`).

**A / accept dispatch:** for the highlighted item, `LOOKUP_FUNC(item+0x28)(item+0x30,
osc)` where `osc = g_sceneMainOscValue` @0x800D3E2C. SFX via `Audio2_Play_SFX`.

## 3. MAIN MENU (screenshot: "MENU") — 4 items

```
ONE PLAYER   (cursor 3)  → MenuHub_StartPlaying path → SINGLE screen (scene 4)
MULTI PLAYER (cursor 4)  → greyed unless a 2nd controller is present (see below)
WONDERS      (cursor 5)  → g_currentScene = 7   (write @0x80091094)
OPTIONS      (cursor 6)  → OptionsDataMenu_Process (scene 14): SCORES/DATA/AUDIO/CREDITS
```

**MULTI PLAYER greying (fully traced, `Scene_Main` @0x80099820–0x8009987C):** every
frame, if `g_sceneMainActiveFlag` @0x800D3D30 is set, it calls
`Controller_GetErrNo(controller_queues[1], 1)` — i.e. polls **controller channel 1
(the 2nd pad)**; `controller_queues` @0x8010DE30, channel 1 = `+0x10` = 0x8010DE40. If
the errno is **nonzero** (2nd pad absent) and the cursor is on 4, it saves 4 into
`g_sceneMenuPrevCursor` and forces `g_sceneMenuCursor = 3` (ONE PLAYER). So MULTI
PLAYER is *live-polled* per frame, not gated by a count global.
`g_controllerPresentMask` @0x800D4498 exists but is **not** consulted here.

**ONE/MULTI PLAYER launch half — `MenuHub_StartPlaying` @0x80090E08:** keys on
`g_sceneLoadFlag` @0x800D3CF0 and the game-mode byte @0x800CF838 to set
`g_currentScene` (9 gameplay default; 0xC/3/0xD/0x10 for other modes), loads music
(`PFGFX_SelectAndStartMusic`) + SFX. State: `g_menuHubState` @0x800D7520,
`g_menuHubStartFlag` @0x800D3D9C, handicap @0x800D3D98.

## 4. ONE PLAYER → "SINGLE" screen (still scene 4)

Rows: **NAME** (profile dropdown), **OPPONENT** (spinner), **GAME** (spinner),
**START** (button, appears once a name is accepted). Prompt legend: "Ⓐ ACCEPT Ⓑ BACK".

### 4a. NAME row + name entry — `Scene_SaveDataScreen` @0x80091D60

The NAME row is a **profile widget** (menu object with widget-type byte
`obj+0x60 == 0xFD`). `Scene_Main` delegates that object to **`Scene_SaveDataScreen`**
(misc/Scene.c:7849, size 0x7914 — a monolithic multi-screen handler: profile dropdown
+ name-entry keyboard + Controller-Pak save/load; **its only caller is
`Scene_Main`**). Args: `(obj, item, playerIndex a2, osc a3)`.

> **Naming note:** `Scene_SaveDataScreen` is *narrow* — it is really the
> **profile-select / name-entry / pak-save widget processor**, not just a "save data
> screen." Kept as-is for now (defensible + central symbol); the breadth is
> documented here. The list-cursor work (§below) is this screen's *own* slot list.

**Widget object fields** (base = `obj`):

| off | field | notes |
|---:|---|---|
| +0x04 | name write cursor | 0..8 |
| +0x05 | keyboard grid cursor | 0..44 |
| +0x08 | ptr → 8-char name buffer | commit dest = `*(obj+0x08) + 0x0C` |
| +0x5C | per-player PV slot index | ×**0xB8** into `g_PV_arr` @0x8011EF30 (+0x28) |
| +0x5D | **menu sub-state byte** | **==1 ⇒ name-entry keyboard live**; also 0xFE/0xFB/0xF6/0xFF/0x00 for other states |
| +0x60 | widget-type byte | 0xFD = profile widget (the dispatch key from `Scene_Main`) |
| +0x61 | name-committed flag | set on OK |
| +0x62 | menu mode | must == 2 to run this section |

**Profile roster:** **GUEST** = always-present index-0 default (no pak file needed);
**"NEW NAME"** = always-present sentinel entry → selecting it sets `obj+0x5D = 1`
(enter keyboard). Saved profiles are enumerated from **Controller-Pak files**
(`Pfs_NumFiles`/`Pfs_FindFile`/`Pfs_ReadFile`) plus the internal SRAM save block
`g_sram_ptr` @0x8011FCF0 (0x1900 bytes; loaded by `SaveData_Load` @0x8007C0EC). The
roster is assembled at runtime (pak file list + synthetic GUEST / NEW-NAME ends), so
its exact stride/max count is not statically fixed. Selected profile index =
`g_saveSlotIndex` @0x8011EEF8 (rendered on the NAME row by `displayText_SaveSlot`
@0x8007A078). List navigation uses `g_sceneMenuCursor[a2]` +
`Scene_ShowObjectsForward/Reverse`.

### 4b. Name-entry keyboard (sub-state `obj+0x5D == 1`, block 0x80098478–0x8009947C)

A **3 rows × 15 cols = 45-cell** on-screen keyboard. Reachable in normal play via
NAME → **NEW NAME** — **not** Controller-Pak-gated (the whole block does pure-RAM
writes + SFX, zero `osPfs`/`Pfs_*` calls).

- Alphabet glyph table `g_nameEntryAlphabet` @0x800D3DA0 (48-byte region, 45 used;
  flat `alphabet[index]` byte table, initialized from ROM `.data`, never written).
- Grid cursor `obj+0x05` (0..44): **index 43 = DEL/backspace, index 44 = OK/END**
  (these are *cell indices*, not glyph byte values).
- Name buffer max **8 chars**; when the write cursor hits 8 the grid cursor auto-jumps
  to OK (44).

Input (D-pad from `g_PV_arr[p]+0xAC` repeat word; A/B/Start from `g_buttonsPressed`
@0x8011EF54):

| input | mask | effect |
|---|---|---|
| D-Right | 0x100 | grid +1, **wrap within row** (14→0, 29→15, 44→30) |
| D-Left | 0x200 | grid −1, wrap within row |
| D-Up | 0x800 | grid −15 (wrap to bottom row if <0) |
| D-Down | 0x400 | grid +15 (wrap to top row if ≥45) |
| Start | 0x1000 | jump highlight to OK (44); does **not** auto-commit |
| A | 0x8000 | select cell (char → append; 43 → backspace; 44 → commit) |
| B | 0x4000 | backspace if name non-empty, else **cancel/close** |

**OK commit** (0x80098984): copy 8 bytes buffer→`buffer+0x0C`, set `obj+0x61=1`,
`obj+0x5D=0`. (Two hard-coded easter-egg name comparisons after commit only tweak
`g_sceneLoadFlag` @0x800D3CF0 — a hidden/cheat-name feature.)

**Menu SFX** via `Audio2_Play_SFX(g_sfxContext@0x801235B0, g_menuSfxBank@0x800D3988,
id)`: **1**=move, **2**=confirm, **3**=error/back, **4**=type, **5**=cancel.

### 4c. OPPONENT / GAME value spinners (inline in `Scene_Main`, 0x8009C664–0x8009C874)

Generic clamp spinner (no wrap). The value object = `item+0x30`: `+0x00` = option
count, `+0x3B0` = current index (byte). **Left**: if index>0, index−−. **Right**: if
index<count−1, index++. On change: fire `item+0x28` callback + SFX. Labels
(OFF/EASY/…, MARATHON/SPRINT/…) are game data, not static C.

| row | menu-item struct | selected-value global (`item+0x0C`) |
|---|---|---|
| GAME | `g_singleGameMenuItem` @0x800D567C | **`g_selectedGameMode`** @0x800D5688 |
| OPPONENT | `g_singleOpponentMenuItem` @0x800D5794 | **`g_selectedOpponentDifficulty`** @0x800D57A0 |

- **GAME mode ids** (from `Tetris_SetGameHandicap` @0x80054760): **0=MARATHON,
  1=SPRINT, 2=ULTRA**, ≥3 = default/none.
- **OPPONENT ids:** **0=OFF**; else AI enabled with difficulty = `value−1`
  (1=EASY, 2=MEDIUM, …).

### 4d. START → `Scene_SingleStartGame` @0x800A2884

(Renamed from `Scene_SaveSlotStartGame` — it takes the profile object but *launches
the game*.) The START-row `+0x28` callback:

1. Read `g_selectedOpponentDifficulty` @0x800D57A0.
   - **Opponent ON** (≠0): `g_activePlayfieldCount` @0x800CFED4 = **2** (halfword);
     `g_gameStartFlag` @0x8011EAED = 2; `g_saveSlotGameStartFlag` @0x8011ECE4 = 1;
     `OpponentPlayer_Init(2, gameMode@0x800D5688, oppValue−1)`.
   - **Opponent OFF** (0): `g_activePlayfieldCount` = **1**; `g_gameStartFlag` = 0.
2. Copy `g_selectedGameMode` @0x800D5688 → **`g_selectedGameType`** @0x8011EEEC.
3. `g_sceneLoadFlag` @0x800D3CF0 = 1 → load into gameplay **scene 9**.

`g_playercount` @0x8011EF20 is derived later in `core/Game.c`. Sibling menu callbacks:
`Scene_SetSelectedGameType` @0x800A286C (`g_selectedGameType = item+0xC`),
`Scene_SetGameStartFlag` @0x800A2A94 (`g_gameStartFlag = item+0xC`),
`Scene_SetLoadFlag2` @0x800A0480 / `Scene_SetLoadFlag5` @0x800A0494.

## 5. MULTI PLAYER → "MULTI" screen (needs ≥2 controllers)
Two profile dropdowns (GUEST/GUEST), GAME, and GARBAGE rows — same widget engine
(NAME rows are `obj+0x60==0xFD` profile widgets; GAME/GARBAGE are spinners).

## 6. OPTIONS → scene 14 (`OptionsDataMenu_Process` @0x8004AD7C)
Items: SCORES / DATA / AUDIO / CREDITS. **DATA** = the Controller-Pak / profile save
screen (same `Scene_SaveDataScreen` machinery + `Pfs_*`). State:
`g_optionsDataMenuState` @0x800CFE50 (0=Data/Pak list, 1=Options),
`g_optionsDataCursorMoveState` @0x800CFEA8, `g_optionsDataSlotCursor` @0x800CFEA4.
CREDITS → scene 16.

## 7. Input → N64 buttons (edge-pressed `g_buttonsPressed` @0x8011EF54)

| N64 bit | button | keyboard | menu action |
|---:|---|---|---|
| 0x8000 | A | Z | confirm / enter / select cell |
| 0x4000 | B | X | back / cancel / backspace |
| 0x1000 | Start | Enter | advance (title→menu) / jump to OK |
| 0x0800 | D-Up | ↑ | cursor up / grid −15 |
| 0x0400 | D-Down | ↓ | cursor down / grid +15 |
| 0x0200 | D-Left | ← | prev value / grid −1 |
| 0x0100 | D-Right | → | next value / grid +1 |

## 8. Symbol quick-reference (front-end)

**Functions:** `Scene_Main` @0x80099674 · `MenuHub_StartPlaying` @0x80090E08 ·
`Scene_SaveDataScreen` @0x80091D60 (profile/name/save widget) ·
`Scene_ShowObjectsForward` @0x80091744 · `Scene_ShowObjectsReverse` @0x80091440 ·
`Scene_SingleStartGame` @0x800A2884 · `Scene_SetSelectedGameType` @0x800A286C ·
`OptionsDataMenu_Process` @0x8004AD7C · `displayText_SaveSlot` @0x8007A078 ·
`Tetris_SetGameHandicap` @0x80054760 · `Controller_GetErrNo` @0x8003B66C.

**Globals:** `g_currentScene` @0x800CFEE8 · `g_sceneMenuCursor` @0x800D3D00 (array) ·
`g_sceneMenuPrevCursor` @0x800D3D10 · `g_sceneMainActiveFlag` @0x800D3D30 ·
`g_sceneMainOscValue` @0x800D3E2C · `g_sceneLoadFlag` @0x800D3CF0 ·
`g_menuHubState` @0x800D7520 · `g_nameEntryAlphabet` @0x800D3DA0 ·
`g_saveSlotIndex` @0x8011EEF8 · `g_singleGameMenuItem` @0x800D567C ·
`g_selectedGameMode` @0x800D5688 · `g_singleOpponentMenuItem` @0x800D5794 ·
`g_selectedOpponentDifficulty` @0x800D57A0 · `g_selectedGameType` @0x8011EEEC ·
`g_activePlayfieldCount` @0x800CFED4 · `g_gameStartFlag` @0x8011EAED ·
`g_PV_arr` @0x8011EF30 · `g_buttonsPressed` @0x8011EF54 ·
`g_sfxContext` @0x801235B0 · `g_menuSfxBank` @0x800D3988 ·
`controller_queues` @0x8010DE30 · `g_sram_ptr` @0x8011FCF0.

## 9. Runtime-only / still-open (verify with `tools/e2e/`)
1. Profile-roster exact stride / max count (assembled from live Pfs enumeration).
2. The OPPONENT/GAME spinner **value objects** (`item+0x30`) are runtime BSS — their
   label tables and full option lists need a RAM capture.
3. Whether *committing/saving* a new profile (vs merely typing a name) requires a
   Controller-Pak. Typing the name does **not** (§4b).
4. `g_gameStartFlag` looks like a **mode selector** (2=vs / 0=single), not a bare
   flag — candidate future rename `g_versusModeFlag` (needs more xref evidence).

## 10. E2E coverage (`tools/e2e/`)
- `test_menu.py` — main menu: cursor 3→5→6 wrap (1 pad), MULTI unlocked (2 pads), A/B nav.
- `test_to_gameplay.py` — ONE PLAYER → SINGLE → START → gameplay (scene 9), no crash.
- `shots_tree.py` / `explore_*` — the discovery tools that produced this map.

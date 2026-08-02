# The New T64ris — front-end / menu tree

Combined **static RE** (reading `RecompiledFuncs/**`) + **dynamic E2E** (driving the
game via `tools/e2e/` and diffing RAM). ✅ = confirmed live in the harness.

The front-end is a **data-driven widget engine**, not a hand-coded screen state
machine. `Scene_Update` dispatches on `g_currentScene` (u8 @0x800CFEE8); the menu hub
(scene 4) runs `Scene_Main`, a per-frame widget driver. Each menu item is a 0x38-byte
struct: `+0x24` button-mask, `+0x28` callback ptr, `+0x30` arg, `+0x0C` game-mode id.
The concrete "item → target" table is game **data** (`param->0x124`), so exact option
labels/order are only knowable at runtime — which is what the harness is for.

## Scene dispatch (`g_currentScene` @0x800CFEE8)

| scene | handler | meaning |
|---:|---|---|
| 2 | CubeTiles_SceneUpdate | intro cube-tiles animation (A skips) |
| 3 | Gfx_CubeSceneUpdate | **attract flythrough / title** → A/Start sets scene 4 ✅ |
| 4 | MenuHub_StartPlaying + Scene_Main | **MENU HUB** (widget engine) ✅ |
| 7 | wonders1_Update/Draw | Wonders game mode ✅ (reached from main-menu item @cursor 5) |
| 8 | wonders3 | Wonders hall/viewer |
| 9 | GameMode_PlayingTick | **active gameplay** |
| 10 | game_over_display… | game over / results |
| 11 | GameMode_PausedTick | pause (PauseMenu_*) |
| 12/13 | GameMode_AttractCountdown/AdvanceGdl | attract demo |
| 14 | OptionsDataMenu_Process | **Options / Data (Controller-Pak) menu** |
| 16 | Credits_Update | credits |

## Tree (screens → options)

```
Attract/title (scene 3)  ── A / START ──►  MENU HUB (scene 4)   ✅
  📷 SCREENSHOT-CONFIRMED: the menu DISPLAYS 4 items:
       ONE PLAYER   (cursor 3)   → 1P game
       MULTI PLAYER (cursor 4)   → VS  — GREYED/UNSELECTABLE with only 1 controller (skipped in nav)
       WONDERS      (cursor 5)   → scene 7 (Wonders game mode) ✅
       OPTIONS      (cursor 6)   → Options/Data (name entry lives under here)
  cursor = g_sceneMenuCursor @0x800D3D00. With 1 controller, DOWN cycles the 3
  SELECTABLE items 3→5→6→3 (skips MULTI PLAYER@4); UP reverses. A (Z)=select, B (X)=back.
  (Connect a 2nd controller and MULTI PLAYER becomes selectable → cursor also visits 4.)
  A/B enter/leave submenus within scene 4 — no crash (crash only on starting a game).

  Play item      → Scene_SetSelectedGameType → g_selectedGameType@0x8011EEEC,
                   g_playercount@0x8011EF20, g_sceneLoadFlag@0x800D3CF0=1 → scene 9 (gameplay)
  Data/Save item → Scene_InitScreenState → Controller-Pak FILE BROWSER (Scene_SaveDataScreen):
                   cursor g_saveDataScreenCursor@0x800D3DEC + scroll @0x800D3DE8
                   (file index = cursor+scroll; slots skipped if descriptor==0xFF);
                   Up/Down highlight, A=create/load/copy, B=back; pak-error states 0xFB–0xFF
  Options/Data   → scene 14 (OptionsDataMenu_Process):
                   g_optionsDataMenuState@0x800CFE50 (0=Data/Pak list, 1=Options)
                   sub-state g_optionsDataCursorMoveState@0x800CFEA8 (0..12; 0=list, 3=exit)
                   slot cursor g_optionsDataSlotCursor@0x800CFEA4 (0..15, wraps, skips empty)
                   Down=next slot, Up=prev, A=confirm(→1), B=exit(→3 → scene 0xF or 2)
  Records        → Scene_DrawRecordsScreen (display-only: time rows + wonder-lines total)
  Credits        → scene 16 (Credits_Update)
```

## Input → action (edge-pressed mask `g_buttonsPressed` @0x8011EF54)

| N64 bit | button | keyboard | menu action |
|---:|---|---|---|
| 0x8000 | A | Z | confirm / enter item (fires callback, starts fade) |
| 0x4000 | B | X | back / cancel |
| 0x1000 | Start | Enter | confirm / advance (title→menu) ✅ |
| 0x0800 | D-Up | ↑ | cursor up / prev ✅ |
| 0x0400 | D-Down | ↓ | cursor down / next ✅ |
| 0x0200/0x0100 | D-Left/Right | ←/→ | widget-defined (save-file paging) |

Nav drivers: main menu `Scene_Main` (input block 0x8009C390–0x8009D000, per-item masks
→ `LOOKUP_FUNC(item+0x28)`); Options `OptionsDataMenu_Process`; save browser `Scene_SaveDataScreen`.

## Key globals to watch (in the harness `DEFAULT_WATCHES`)

`g_currentScene`@0x800CFEE8, `g_sceneMenuCursor`@0x800D3D00 (main cursor),
`g_sceneMainState`@0x800D3D24, `g_menuHubState`@0x800D7520, `g_sceneLoadFlag`@0x800D3CF0,
`g_selectedGameType`@0x8011EEEC, `g_playercount`@0x8011EF20, `g_optionsDataMenuState`@0x800CFE50,
`g_optionsDataSlotCursor`@0x800CFEA4, `g_saveDataScreenCursor`@0x800D3DEC.

## ⚠️ There is NO name-entry / keyboard-initials screen

A tree-wide static search (alphabet/"ABC" tables, per-char buffer writes, X/Y grid
cursors, A-append/B-delete logic) found **none**. Controller-Pak save names are **fixed
ROM constants** (via `Pfs_AllocateFile`/`Pfs_FindFile`); the player only *selects* among
existing save files and confirms create/load/copy/delete — they never type a name. So the
"enter names via keyboard" flow does not exist in this game. (If the harness ever observes
a letter grid at save/high-score time, it would contradict this — none expected.)

## Covered by E2E tests (`tools/e2e/`)
- `test_menu.py` ✅ — reach main menu, cursor 3→5→6 wrap, UP reverses, A submenu / B back.
- `explore_menu.py` / `probe_cursor.py` / `explore_submenus.py` — discovery tools that
  produced this map (RAM-diff per input; per-item submenu signatures).

## Runtime-only items (data-driven; verify with the harness)
1. Concrete item→target labels/order per screen (widget data table).
2. `g_selectedGameType` value each Play item yields (byte from item+0x0C).
3. Per-screen cursor min/max (no generic clamp in code).
4. Save-pak file-count bound (dynamic = live file count).

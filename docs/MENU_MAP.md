# MENU_MAP.md — every menu screen, mapped

One entry per reachable front-end screen: what it shows, its scene/sub-state, the driver
function, the input path to reach it, and its on-screen options. Captured by driving the
headless game and screenshotting each screen (`tools/e2e/shots_tree.py` +
`e2e_helpers.py`), 2026-08-15, with the window unoccluded.

> **No screenshots are committed** (repo policy: never commit rendered game frames).
> This map is the durable, textual record; regenerate frames any time with
> `tools/e2e/shots_tree.py` (they land in the harness workdir, e.g. `/tmp/tnt_e2e/*.png`).
> Code binding lives in `docs/MENU_TREE.md`; behavior ground truth in
> `docs/MENU_OBSERVED.md`; state addresses in `docs/GAME_STATE_MAP.md`.

---

## The tree

```
attract/title (scene 3)  ──START──►  MENU  (scene 4 hub)
                                       ├─ ONE PLAYER  (cursor 3) ─A─► SINGLE  (scene 4)
                                       │                                ├ NAME (profile dropdown / NEW NAME keyboard)
                                       │                                ├ OPPONENT (spinner: OFF/…)
                                       │                                ├ GAME (spinner: MARATHON/…)
                                       │                                └ START (appears after NAME accepted) ─► gameplay (scene 9)
                                       ├─ MULTI PLAYER (cursor 4) ─A─► MULTI setup (needs 2 pads; greyed w/ 1)
                                       ├─ WONDERS     (cursor 5) ─A─► WONDERS hall (scene 7)  [Ⓐ HALL Ⓑ EXIT]
                                       └─ OPTIONS     (cursor 6) ─A─► OPTIONS (SCORES/DATA/AUDIO/CREDITS)
gameplay (scene 9) ──START──► PAUSE (scene 11);  top-out ──► GAME OVER (scene 10)
attract, idle ──► attract DEMO (scene 12/13, auto-play)
```

---

## Screens

### Attract / title — scene 3
- **Driver:** `Gfx_CubeSceneUpdate`. **Reach:** boot (auto), or `e2e_helpers.reach_attract`.
- Flythrough of the stone-block world, then the title. **A / START → MENU** (scene 4).
- Idle cycles into **attract demos** (scenes 12/13, auto-played gameplay).

### MENU (main hub) — scene 4
- **Driver:** `MenuHub_StartPlaying` (0x80090E08) + `Scene_Main` (0x80099674).
  **Reach:** `reach_menu` (hold START on scene 3). **Prompt:** "Ⓐ ACCEPT".
- Title "MENU" over a stone-block frame. Four items (cursor value in
  `g_sceneMenuCursor` @0x800D3D00):
  - **ONE PLAYER** (3) — highlighted pink when selected → SINGLE.
  - **MULTI PLAYER** (4) — greyed & auto-skipped unless a 2nd controller is present
    (live-polled each frame; see `MENU_TREE.md` §3).
  - **WONDERS** (5) → sets scene 7.
  - **OPTIONS** (6) → OPTIONS screen.
- UP/DOWN move the cursor; A enters (advances `g_sceneMainState` @0x800D3D24).

### SINGLE (one-player setup) — scene 4
- **Reach:** MENU → ONE PLAYER → A. **Prompt:** "Ⓐ ACCEPT Ⓑ BACK".
- Title "SINGLE". Rows:
  - **NAME:** a profile dropdown (default **GUEST**; boxed/red when focused). Opening it
    lists Controller-Pak profiles + a **NEW NAME** sentinel → name-entry keyboard
    (handled by `Scene_SaveDataScreen` @0x80091D60; see `MENU_TREE.md` §4a).
  - **OPPONENT:** spinner (shown **OFF**).
  - **GAME:** spinner (shown **MARATHON**).
  - **START:** button, appears once a name is accepted → launches gameplay (scene 9).

### MULTI PLAYER setup — scene 4
- **Reach:** MENU → MULTI PLAYER → A (only selectable with **2 controllers**; use
  `Game(controllers=2)`). With one pad the hub forces the cursor back to ONE PLAYER.
- Two-player variant of the SINGLE setup. (Captured with 2 pads via `shots_tree.py`.)

### WONDERS hall — scene 7
- **Driver:** `wonders1_Update/Draw`. **Reach:** MENU → WONDERS → A. **Prompt:**
  "Ⓐ HALL Ⓑ EXIT".
- A wintry 3D scene (snowman, ice castle). A enters the hall/viewer (scene 8), B exits
  to MENU. Wonders line-requirements are the table `g_wonderLineThresholds` @0x800CF928
  (rebalanced by `mods/wonders-rebalance`).

### OPTIONS — scene 4 → scene 14
- **Driver:** menu item → `OptionsDataMenu_Process` (0x8004AD7C). **Reach:** MENU →
  OPTIONS → A. **Prompt:** "Ⓐ ACCEPT Ⓑ BACK".
- Title "OPTIONS". Four items:
  - **SCORES** — high-scores / records.
  - **DATA** — Controller-Pak management (file list; `g_saveDataScreenCursor`
    @0x800D3DEC, `g_dataMenuPakFileCount` @0x80110580). Pak persistence is covered by
    the pytest suite (`tests/`).
  - **AUDIO** — sound settings (not audibly verifiable headless; dummy audio driver).
  - **CREDITS** — scene 16 (`Credits_Update`).

### Gameplay — scene 9
- **Driver:** `GameMode_PlayingTick`. **Reach:** `reach_gameplay` (SINGLE → START).
- The falling-cubes game. Logical piece state at `*g_currentPiece_ptr` (col/row/rot/
  type — see `GAME_STATE_MAP.md`). START → PAUSE.

### Pause — scene 11
- **Driver:** `GameMode_PausedTick` (`PauseMenu_*`). **Reach:** `reach_pause` (gameplay
  → START).

### Game over — scene 10
- **Driver:** `game_over_display…`. Reached on top-out.

### Credits — scene 16
- **Driver:** `Credits_Update`. **Reach:** OPTIONS → CREDITS.

---

## Coverage notes
- Captured & viewed this run: attract, MENU (+ each highlight), SINGLE, MULTI (entered),
  WONDERS, OPTIONS, and each item's "inside" peek (`shots_tree.py`).
- Deeper leaves (name-entry keyboard, OPTIONS sub-tabs as scene 14, pause, game-over)
  are documented from `MENU_TREE.md`/`MENU_OBSERVED.md` + the scene machine; regenerate
  live frames with the reach-helpers when a visual is needed.

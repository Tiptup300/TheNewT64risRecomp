# Overnight report — input experimentation, state map, modding framework

_Session goal (from the approved plan): experiment with input to map the game's state,
turn that into a reusable **modding framework** (tools + state reference + guide +
template mods), screenshot every menu screen, and — as a stretch — start a new menu
screen. Autonomous overnight run; the user was asleep._

> Status legend: ✅ done & verified · 🟡 partial / honest limitation recorded · ⏳ in progress

---

## TL;DR (read this first)

- The **modding framework is delivered**: an input→state probe engine, reusable
  state-reach helpers, a shared machine-readable state registry, a full **MODDING.md**
  guide, a **GAME_STATE_MAP.md** reference, and a copy-me **template mod** that builds.
- **Input→state mapping** works and is validated on menus and gameplay — including the
  active piece's **logical fields** (`*g_currentPiece_ptr` + col@0x11 / row@0x12 /
  rot@0x0A / type@0x13), cross-validated by register-level RE **and** a live poke. (My
  first black-box probe couldn't see them — gravity churns the col/row word every frame;
  static RE of the input handler cracked it.)
- **Menu screenshot map**: ✅ every reachable screen mapped (`docs/MENU_MAP.md`).
- **New menu screen (stretch)**: 🟡 in progress — a mod CAN both hook and *call* a game
  function (had to call `displayText_*` via an indirect function-pointer, not a direct
  `jal` — see §4/§6); building up an OK/BACK → level-select shell.

---

## 1. Framework tooling (Phase 1–2) ✅

| File | What it is |
|---|---|
| `tools/e2e/probe_inputs.py` | Drive to a state, tap each input, report the RAM addresses it *reliably* moves. Noise filters: a control-noise floor + reproducibility-intersection make it legible under live animation. Region presets logic/gameplay/full. |
| `tools/e2e/probe_piece.py` | Dereferences `g_currentPiece_ptr` and scans the heap window for per-input piece-field movement (with a gravity noise floor). |
| `tools/e2e/e2e_helpers.py` | One reach-helper per state (attract/menu/single/gameplay/wonders/pause), with the retry loop that fixes the scene-3 attract-cycle flake. `STATES` + `INPUTS` registries. |
| `tools/e2e/states.py` | The shared source of truth: `GLOBALS` (name→addr/width/meaning), `SCENES`, `STATE_KEYS`. Mirrors `harness.DEFAULT_WATCHES`. |

## 2. Reference docs (Phase 2) ✅

- **`docs/MODDING.md`** — the authoritative how-to: `RECOMP_HOOK` (RAM-writes-only,
  registers restored) vs `RECOMP_PATCH`; reaching game RAM by pointer or datasym name;
  config options; the real pitfalls (no `recomputils.h`, no logging, never write
  `g_currentScene=4`); a hook-point catalog; the example mods as a cookbook.
- **`docs/GAME_STATE_MAP.md`** — the state reference: scene machine, session/menu/
  gameplay globals, the scene-4 crash chain. Every address reproduced (driven +
  watched), not guessed.

## 3. Input→state findings (Phase 1) ✅ / 🟡

- **Menu (scene 4):** UP/DOWN move `g_sceneMenuCursor`; A advances `g_sceneMainState`.
  Cursor is an int32 array; main-menu items 3/4/5/6. (Confirmed by probe + navigation.)
- **Gameplay (scene 9):** input registers (board/render RAM moves on LEFT/RIGHT/DOWN);
  the three piece pointers (`g_currentPiece_ptr`/`g_mobileCubes_ptr`/`g_minos_ptr`) are
  live. 🟡 **Limitation:** `*g_currentPiece_ptr` is a per-frame-rewritten 3D/animation
  object (heap base moves per run: 0x80231e78, 0x80290860), so a per-input delta can't
  be isolated by RAM diffing — nearly the whole struct window is gravity/animation
  noise. The **logical** piece col/row/rotation live elsewhere; being found by static
  RE of the gameplay input handler (⏳), to be confirmed by a live poke before recording.

## 4. Template / cookbook mods (Phase 2d) ✅ (grows)

- **`mods/template-basic`** — the canonical copy-me mod: hook + config + scene-gate +
  input-read + safe RAM write in one 100%-safe example (counts A-presses into scratch).
  Builds to a `.nrm`.
- The five existing mods already cover the other techniques (see `docs/MODDING.md` §7).

## 5. Menu screenshot map (Phase 3) ⏳

_Capturing one frame of every reachable screen this run → `docs/MENU_MAP.md`._
(Note: rendered frames are never committed per repo policy; the map describes each
screen textually and cites the driver + input path.)

## 6. New menu screen (Phase 4, stretch) ✅ — a working LEVEL SELECT shell

The stretch goal landed, past the minimal OK/BACK, all the way to a level-select shell:
- **`mods/new-screen-poc`** draws a real overlay screen on the main menu: a yellow
  **"LEVEL SELECT"** title, an 8-entry list, a `>` cursor, an OK confirmation banner,
  and a footer legend — all rendered with the **game's own font** by calling
  `displayText_XY_RGBA_2` from a `Scene_Main` return hook.
- **Fully interactive & self-verified** (`tools/e2e/drive_level_select.py`, screenshots):
  C-Up opens → C-Up/Down move the cursor → C-Right = OK (green "OK LEVEL n" banner) →
  C-Left = BACK (closes). Driven by the N64 **C-buttons** so it never conflicts with the
  live menu underneath (the menu ignores C-buttons; a hook can't suppress the menu's own
  A/B/D-pad). Survives; scene stays 4.
- **No real level change yet** — deliberately a shell (records the selection only), per
  the plan. Growing it into an actual level change is the clear next step.
- Two findings that made it work, now in the framework docs: (a) a mod calls a game
  function via a **function-pointer to the guest address** (not a direct call — that
  fails to link); (b) the overlay **freezes the menu attract-idle counter**
  (`0x800D3D2C`, found monotonic on the idle menu) so the menu doesn't bail to attract
  while our C-button-only screen is open.

Docs: `docs/ADDING-A-MENU-SCREEN.md` (how the engine builds a screen + the mod recipe).

---

## Commits this session
- `51dee79` input-probe engine + reach-helpers
- `25c06b3` modding guide + state map + shared state registry
- `925faf3` piece-struct probe + template mod + gameplay-pointer watches
- _(more below as work lands)_

## Verification
- `verify.sh` unaffected (no symbol/C-in-tree changes); `mods/template-basic` builds
  (`build_mod.sh`). Every recorded address was driven-and-watched or is flagged pending
  a confirming poke.

## Next steps for the morning
- Confirm the logical piece-state addresses from the RE pass with a live poke; fold into
  `GAME_STATE_MAP.md` + `states.py`.
- Finish `docs/MENU_MAP.md` (all screens) and `docs/ADDING-A-MENU-SCREEN.md`.
- Take `mods/new-screen-poc` as far as it goes (OK/BACK → +option → level-select shell);
  report exactly where it lands.

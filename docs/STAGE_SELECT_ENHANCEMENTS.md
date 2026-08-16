# Stage-select enhancements — status, blockers, and proven recipes

Follow-up investigations for `mods/stage-select` on two requested enhancements:
**(1) baked per-stage art thumbnails**, and **(2) a real screen transition (block
background, not an overlay)**. This records exactly what was tried, what's verified, what's
blocked, and the concrete recipes so a future session can pick up without re-deriving.

## Baseline that ships and works (`mods/stage-select`, committed)
In-flow SELECT STAGE screen: after ONE PLAYER → SINGLE, Accept opens it (game held via the
`g_sceneLoadFlag` latch); Up/Down navigate the 8 real culture themes; Accept picks one and
**launches into that actual themed level**; Back returns to SINGLE. Each row has a
**color-coded swatch icon**. Verified end-to-end (`tools/e2e/verify_stage_load.py`).

## CORRECTION — the real environment selector is `0x8011EEF8`, not `g_currentSong`
Earlier notes said `g_currentSong` @0x8011E4F8 loads the level. **Wrong** — that byte is the
MUSIC only. The visible themed 3D environment is chosen by a **separate byte at `0x8011EEF8`**
(a field of the `g_game` struct @0x80110A00). `MenuHub_StartPlaying` randomizes it; `Game_Init`
reads it at 0x80052248 → `PFGFX_GameInit`, whose 8-way jump table (0x800DD37C) loads that
theme's CubeTiles/scene. The prior "0x80052248 reads g_currentSong" was an address-arithmetic
misread (base is `$s0=g_game=0x80110A00`, so `0x7FFF+0x64F9` = **0x8011EEF8**). The mod now
forces `0x8011EEF8` at the `Game_Init` hook → picking a stage loads that stage's environment,
**confirmed E2E** (`0x8011EEF8 == picked index` every run, distinct themed level each). Residual
non-determinism (decorative grid particles, exact song roll) does not change which of the 8
themed scenes loads.

## KNOWN LIMITATION — overlay input leak (the SINGLE menu behind still reacts)
The screen is an overlay on the live SINGLE screen, and Up/Down still moves the SINGLE menu
behind it. RE traced *why a `RECOMP_HOOK` can't fix it*: Scene_Main re-polls the controller
mid-frame (`Controller_SendRecvMsg` @0x800997CC), and the menu's nav **populates + consumes +
clears `g_buttonsPressed` INLINE** in Scene_Main's logic — captures placed at Scene_Main entry,
`Gfx_SetupRenderState` (after the poll), and `Scene_SaveDataScreen` entry all either miss the
window or get overwritten before the nav reads the mask. There is no function boundary between
the populate and the consume to hook. Options: (a) a `RECOMP_PATCH` of the menu logic, or
(b) the engine-native transition below (hide SINGLE entirely → no live menu → nothing to leak).
Option (b) is the same build the user asked for ("transition + blocks background"), so it is the
recommended path and subsumes this fix.

---

## (1) Baked art thumbnails — BLOCKED (with a proven partial)

**What works (verified):** a mod CAN decode and blit a real game sprite from the resident
archive (base `0x00273A00`) into the menu. Proof: `Sprite_LoadImage(&slot, 0x96)` +
`Sprite_DrawScaled` rendered the game-over "WIN" image, scaled, in the menu — no crash.

**Paletted-blit recipe (proven by RE, ready to use):**
- `Sprite_LoadImagePair(&obj, imageId, paletteId)` @0x800571D4 decodes image→`obj+0x0`,
  **palette→`obj+0x4`**, and defaults x/y=0, scale=`0x400`(=1.0), rgba=0xFF.
- sprite-obj (0x14 bytes): `+0 img, +4 palette, +8 x(s16), +0xA y(s16), +0xC scaleX(s16),
  +0xE scaleY(s16), +0x10..13 rgba`.
- `Sprite_DrawScaled(&obj)` @0x80057338 with scale<`0x400` routes to `Color_DrawTexRect`
  @0x8005DB90, which (format-3/CI path) loads `obj+0x4` as the TLUT → paletted art renders.
- Per-theme ids (per RE): `imageId = *(u32*)(0x800D0930 + t*0x60)`,
  `paletteId = *(u32*)(0x800D0930 + t*0x60 + 0x1C)`; `g_pfDrawParamPresetTbl` @0x800D0930.

**Why it's blocked for actual stage backdrops (tested):**
1. **Backdrop textures don't blit as clean thumbnails.** Decoding theme 0's backdrop id
   `0x4D` — with *and* without its palette `0x4E` — rendered **blank** in the menu, while the
   UI sprite `0x96` rendered fine. The backdrops are paletted tiles composited in 3D with
   specific render setup, not standalone blittable images.
2. **Per-theme ids aren't valid at menu time.** A live dump of `0x800D0930` at the menu showed
   **only theme 0 populated** (`0x4D`/`0x4E`); themes 1–7 were all zero. That address is a
   per-game *working copy* filled by `PFGFX_GameInit` when a game of that theme loads — so
   before you've played a theme, its backdrop ids aren't available to read. The true 8-entry
   source is ROM `.data`, not present in this checkout.

**What a full solution would require (next session):** a "learn ids as you play" cache — read
`0x800D0930`'s ids at `Game_Init` each time a theme is played and persist them — **and** solving
the backdrop blit (likely needs the exact CI format/tiling setup the 3D scene uses, beyond the
simple `Sprite_DrawScaled` path). Both are real work; #1 (the blit) is the deeper unknown.
Fully-doable alternative the user rejected: bake **custom** thumbnail art into the mod (draw
your own image buffer with a w/h/format header + texels and feed `Color_DrawTexRect`).

---

## (3) PARASITE approach to in-game menus (in progress — mods/stage-native)

Design (user's): don't REPLACE a hub screen (impossible cleanly — see below); instead sit on an
existing scene-4 host, **disable its input**, **disable its foreground rendering (keep the
background)**, and draw our own screen (parasite) on top with the game font — then abstract it
into a reusable "add a menu" primitive.

**Validated (screenshots, `tools/e2e/probe_native.py`):**
- Step 1 (hold the launch) + Step 4 (draw parasite via `displayText_XY_RGBA_2` @0x80077960 in a
  `RECOMP_HOOK_RETURN("Scene_Main")`) WORK — "PARASITE SCREEN" text renders on top in the game font.
- `Scene_LoadScreen(gameoverTableA)` from a mod runs without crashing but does NOT replace SINGLE
  (the hub keeps drawing it) — table swap alone is insufficient.

**Blocker — Step 3 (disable foreground, keep background):**
- `g_sceneObjRenderEnable @0x800D3D94 = 0` does NOT blank the foreground; it left SINGLE fully
  visible and spilled garbled debug stats → it gates a debug overlay, not the menu foreground.
- Structural finding: **neither `Scene_Init` nor `Scene_Main` renders a separate 3D world** — the
  menu's stone-wall/wooden-frame BACKGROUND is drawn as SPRITES *inside* `Scene_Main`, in the same
  per-item draw loop (0x800999EC computes 0x38·i into the item iterator `s0`, type-branches per
  item) that also draws the SINGLE title/rows. So background and foreground are interleaved items
  in one loop; there is no single global that disables just the foreground.
- The SINGLE "title/frame/OPPONENT/GAME/footer" are NOT hidden by zeroing item RGB/alpha (proven)
  — they're likely drawn via a sprite path or inline, not the RGB-tinted text path.

**Next steps to crack Step 3 (multi-cycle, live-iterated):**
1. Dump the active item table at runtime (`*(sceneCtx+0x124)`, sceneCtx=0x801290D0 → ptr @0x801291F4)
   on the SINGLE screen: enumerate the 0x38-byte items and classify each as background vs foreground
   (by its `+0x24` flags / sprite id). If the title/frame ARE items, Step 3 = blank the foreground
   items (leave background items) — tractable.
2. If title/frame are truly inline (not items), find the inline draw call(s) in `Scene_Main`'s
   foreground region (after 0x80099A28) and gate them with a targeted `RECOMP_PATCH`, OR pick a
   host screen whose foreground is pure item-objects.
3. Input disable: freeze the host's cursor/state and intercept its accept so it can't act while the
   parasite owns input (the menu consumes `g_buttonsPressed` inline, so full hook-suppression isn't
   possible — freeze state instead).
Then abstract 1–3 into a reusable primitive (pick host, blank foreground items, own input, draw).

## (2) Real transition + non-overlay screen — NOT DONE (proven recipe, large build)

**Current limitation:** the SELECT STAGE screen is drawn *over* the (frozen) SINGLE screen; it
is not a hard cut but it does overlay SINGLE rather than replacing it on the block background.

**Lightweight attempt (tested, insufficient):** calling `Gfx_BeginScreenFade0(9.0)`
@0x8007E9F8 on enter/exit + zeroing the SINGLE item rows' color/alpha in the active item table
(`sceneCtx+0x124`, 0x38-byte items, RGB@+0x10/14/18, alpha@+0x1C) did **not** hide SINGLE — its
title/values/frame stayed fully visible (those elements aren't all in that table, or the engine
rewrites them before drawing). So the simple approach doesn't achieve the clean-background look.

**The proven engine-native recipe (from RE — this is the real path):**
- The scene-4 screens (MENU/SINGLE/OPTIONS) are the same scene id 4 with different **item
  tables**; a "screen change" = install a different table + run the fade + object reveal.
- The active table pointer (`sceneCtx+0x124`, sceneCtx=`0x801290D0`) is set only by
  `Scene_ProcessObjectList` @0x8008F360; the clean wrapper is **`Scene_LoadScreen` @0x8009035C**
  `(table, spriteSrcTbl)` — the same call Credits/Game-Over use to show their own screens.
- Transition primitives: `Gfx_BeginScreenFade0(9.0)` + `Gfx_DrawScreenFade0` (auto each frame);
  reveal/hide via `Scene_ShowObjectsForward` @0x80091744 / `Scene_ShowObjectsReverse`
  @0x80091440; direction global `g_sceneMainDecayActive` @0x800D3E34 (2=enter, 1=back);
  reload request `g_sceneInitFlag` @0x800D3D88.
- **The block background is drawn independently of the item table**, so any table shown while
  `g_currentScene==4` sits on the block background automatically.
- Recipe: build a 0x38-byte item table for SELECT STAGE (0x8000-sentinel terminated) + a sprite
  source table; on SINGLE-Accept `Scene_LoadScreen(myTable, mySrc)`, set
  `g_sceneMainDecayActive=2`, `Gfx_BeginScreenFade0(9.0)`; drive the reveal via
  `Scene_ShowObjectsForward`. Back: re-install SINGLE's table, `g_sceneMainDecayActive=1`,
  fade, `Scene_ShowObjectsReverse`.
- **Friction:** `Scene_Init`'s reload is hard-wired to reinstall `g_sceneViewObjBuf`
  (@0x800D4E1C) with fixed sprite/font descriptors, so a mod must either build SELECT STAGE
  *into* that buffer with the existing resource set, or install its own table via
  `Scene_LoadScreen` and drive the reveal directly (not via `g_sceneInitFlag`). Authoring valid
  0x38-byte item structs (with working callbacks/sprite refs) is the substantial, crash-prone
  part — hence a real build, not a quick change.

**Verdict:** achievable, but it's an engine-native screen build (mod-authored item table +
transition driving), best done interactively where each iteration can be watched — not safely
completed unattended in one pass.

---

## Diagnostic tools left behind
- `tools/e2e/dump_preset.py` — dumps `g_pfDrawParamPresetTbl` per-theme descriptor fields.
- `tools/e2e/drive_stage_select.py` / `drive_stage_full.py` — drive + screenshot the flow.

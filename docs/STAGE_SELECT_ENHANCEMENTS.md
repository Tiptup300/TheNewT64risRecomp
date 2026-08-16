# Stage-select enhancements — status, blockers, and proven recipes

Follow-up investigations for `mods/stage-select` on two requested enhancements:
**(1) baked per-stage art thumbnails**, and **(2) a real screen transition (block
background, not an overlay)**. This records exactly what was tried, what's verified, what's
blocked, and the concrete recipes so a future session can pick up without re-deriving.

## Baseline that ships and works (`mods/stage-select`, committed)
In-flow SELECT STAGE screen: after ONE PLAYER → SINGLE, Accept opens it (game held via the
`g_sceneLoadFlag` latch); Up/Down navigate the 8 real culture themes; Accept picks one and
**launches into that actual level** (`g_currentSong` forced at `Game_Init`); Back returns to
SINGLE. Each row has a **color-coded swatch icon**. All verified end-to-end by screenshots +
RAM checks (`tools/e2e/drive_stage_select.py`, `drive_stage_full.py`).

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

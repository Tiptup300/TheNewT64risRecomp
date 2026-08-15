# ADDING-A-MENU-SCREEN.md — how to draw your own menu screen (mod)

How the scene-4 front-end is built, and the concrete recipe for a mod to draw its own
screen on top of it and respond to A/B. Grounded in a register-level RE pass over
`RecompiledFuncs/misc/Scene.c` and `RecompiledFuncs/graphics/displayText.c`
(cross-checked against `tnt.syms.toml` / `tnt.datasyms.toml`).

> This is the exploratory stretch path. The **overlay** approach below (draw our own
> text each frame + read the input mask) is the simplest thing that works with a mod;
> it does **not** require adding a real item to the game's item table. Growing it into
> a true engine-native screen is discussed in §5.

---

## 1. How a scene-4 screen actually works

The front-end is a **data-driven widget engine**, run once per frame:

```
Scene_Update (0x8006CF14, per frame)
  -> MenuHub_StartPlaying (0x80090E08)     # scene-4 hub driver; runs ControllerRepeat_Update first
    -> Scene_Init (0x8009D5E4)             # per-frame setup; installs the item table
      -> Scene_Main (0x80099674)           # THE widget/menu engine — draws + handles input
```

- `Scene_Main`'s `sceneCtx` (`a0`) is the fixed global **`0x801290D0`** (`Scene_Init`
  calls it with that base). It is **not** a blocking loop — one body, once per frame.
- The per-screen **item table** is installed by `Scene_ProcessObjectList`
  (`0x8008F360`), which writes `*(sceneCtx + 0x124) = itemTable`. For the hub the table
  is **`g_sceneViewObjBuf` @ 0x800D4E1C** — a RAM buffer filled *programmatically* in
  the object-load path (there is **no** flat const array of items to copy).
- Each item is a **0x38-byte struct**: `+0x0C` value id, `+0x24` flags
  (`0x8000` = slot present/selectable — the iterator stops at the first slot *without*
  it, so the "count" is the number of leading `0x8000` slots; `0x800` = has a per-frame
  while-selected callback), `+0x28` callback fn ptr, `+0x30` callback arg.
- Cursor: **`g_sceneMenuCursor` @ 0x800D3D00** (word item index). State machine:
  **`g_sceneMainState` @ 0x800D3D24**. Per-frame anim value passed to callbacks:
  `g_sceneMainDecayValue` @ 0x800D3E2C.

**Caveat:** `Scene_Main` / `Scene_Init` are shared with **Credits** and **Game-Over**
too. Any scene-4-only mod code MUST gate on **`g_currentScene @ 0x800CFEE8 == 4`**.

---

## 2. The hook point

**`RECOMP_HOOK_RETURN("Scene_Main")`** — fires after the menu engine has run for the
frame, which is the safe moment to draw an overlay (the menu's own text is already
issued). `RECOMP_HOOK("Scene_Main")` (entry) also works but drawing after is safer.

At this point everything a menu mod needs is live: the render context `g_gdl`, the
font object, the item table, the cursor, and a **fresh input mask** (the hub runs
`ControllerRepeat_Update` before `Scene_Main`, so `g_buttonsPressed` is current).

```c
#define G_CURRENT_SCENE (*(volatile unsigned char*)0x800CFEE8)
RECOMP_HOOK_RETURN("Scene_Main") void my_overlay(void) {
    if (G_CURRENT_SCENE != 4) return;   // shared with Credits/Game-Over
    /* draw + input here */
}
```

---

## 3. Drawing text with the game's own font

**`displayText_XY_RGBA_2` @ 0x80077960** — the engine's text drawer. o32 ABI recovered
from its call site (`Scene.c:9510`) and body:

```c
// a0, a1 are fixed globals; a2/a3 are coords; the rest are stack args.
void displayText_XY_RGBA_2(void* gdl,        // &g_gdl          = 0x800E20C0
                           void* fontObj,     // &g_sceneFontObj8 = 0x80128F28
                           int x, int y,      // screen coords
                           const char* str,   // 5th arg (stack) — a mod-owned C string works
                           int r, int g, int b, int a);  // each 0..0xFF
```

So to render text a mod declares the prototype + the two font/gdl globals and calls it:

```c
extern void displayText_XY_RGBA_2(void* gdl, void* font, int x, int y,
                                   const char* s, int r, int g, int b, int a);
#define G_GDL   ((void*)0x800E20C0)
#define G_FONT8 ((void*)0x80128F28)

static const char OK_STR[]   = "OK";
static const char BACK_STR[] = "BACK";
displayText_XY_RGBA_2(G_GDL, G_FONT8, 120, 100, OK_STR,   0xFF,0xFF,0xFF,0xFF);
displayText_XY_RGBA_2(G_GDL, G_FONT8, 120, 130, BACK_STR, 0xFF,0xFF,0xFF,0xFF);
```

The mod's `static const char[]` lives in mod memory that the loader maps into guest
RAM, so the recompiled `displayText_*` can read it. Siblings in
`RecompiledFuncs/graphics/displayText.c` (same `(gdl,font,x,y,str,r,g,b,a)` family):
`displayText_XY_RGBA_1` @0x80077818, `_3` @0x80077AA8 (returns text width in `v0`,
useful for centering), `_4` @0x80077BA8. For centering also see `Font_GetTextWidth`
(`RecompiledFuncs/graphics/Font.c`).

> **Unverified until we run it:** whether `displayText_*` draws immediately or enqueues
> into `g_gdl` for a later flush. Drawing from the **return** hook is the safe choice.
> Also unconfirmed until runtime: that a MIPS mod may *call* (not just hook) a game
> function like `displayText_XY_RGBA_2`. If the call doesn't link/load, fall back to
> setting item/state RAM (§5) instead of drawing directly. **`mods/new-screen-poc`
> exists to test exactly this.**

---

## 4. Reading input (A / BACK / cursor)

`g_buttonsPressed` @ **0x8011EF54** (u32), the per-frame edge mask, with the bits
`Scene_Main` itself tests:

| button | bit | button | bit |
|---|---|---|---|
| A | `0x8000` | START | `0x1000` |
| B | `0x4000` | LEFT | `0x0200` |
| | | RIGHT | `0x0100` |

```c
#define BTN_PRESSED (*(volatile unsigned int*)0x8011EF54)
unsigned int b = BTN_PRESSED;
if (b & 0x8000) { /* A / OK  */ }
if (b & 0x4000) { /* B / BACK */ }
```

Track your own previous-frame mask to get clean edges (see `mods/template-basic`).

---

## 5. The staged plan (`mods/new-screen-poc`)

- **4a — minimal overlay:** on the main menu, when a mod-owned flag/hotkey is set, draw
  "OK / BACK" and read A/B (A clears the flag = "OK", B clears it = "BACK"). Proves we
  can render our own text on a menu and respond. *(This is the overlay recipe above.)*
- **4b — one option + cursor:** draw two lines, a `>` cursor, move it with UP/DOWN, A
  on each line does something distinct. Cursor is just a mod-owned int.
- **4c — LEVEL SELECT shell:** a titled screen, a scrollable list of level entries, a
  cursor, OK/BACK. Selection state only — **no real level change** yet.

If calling `displayText_*` from a mod turns out not to link/load, the fallback that is
guaranteed to work is to influence the game's **own** engine via RAM: flip an item's
`+0x24` flags / `+0x28` callback / cursor in the item table `*(0x801290D0 + 0x124)` =
`g_sceneViewObjBuf @ 0x800D4E1C`. That reuses the engine's drawing instead of doing our
own. It's more invasive but avoids the "can a mod call a game function" question.

---

## 6. Settled at runtime (via `mods/new-screen-poc`)

- **Can a MIPS mod call `displayText_XY_RGBA_2`? YES** — but not by a direct
  extern-symbol call (that fails to link: `R_MIPS_26 relocation truncated`). Call it
  **through a function pointer at the absolute guest address** (`((fn)0x80077960)(...)`),
  which emits an indirect `jalr` the runtime dispatches by guest address. Verified: the
  text renders on the menu in the game font, no crash. (General recipe — see
  `docs/MODDING.md` §2b.)
- **Draw timing:** drawing from `RECOMP_HOOK_RETURN("Scene_Main")` renders correctly
  (the text appears composited over the menu), so the return hook is the right place —
  no separate flush handling was needed.

### Still open
- Meaning of item flag bit `0x8` and sceneCtx fields `+0x114/+0x11C/+0x120/+0x128/
  +0x134` (not determinable statically) — only relevant if you grow this into a true
  engine-native item rather than an overlay.

_See `docs/GAME_STATE_MAP.md` for the addresses, `docs/MODDING.md` for hook/patch rules._

# Modding UI — building real screens with recompui

This is the **framework for adding new menus / screens / states to The New T64ris** — real UI,
not an overlay drawn over the live menu. A mod builds a genuine UI layer (flexbox layout, styled
text, buttons, images, click callbacks) that **captures input** (the game behind it gets none),
using the same `recompui` system the app's own launcher/config menus use and that Zelda64Recomp
mods use.

> For screens that must look *exactly* like the in-game menu (the block-background 3D look with
> the game's pixel font and native fade), see the engine-native path in
> `docs/STAGE_SELECT_ENHANCEMENTS.md`. recompui is the general, reusable path and the right
> default for new screens and anything that loads new content; the engine-native path is a
> specialist tool for in-game-aesthetic screens.

## What makes this work (host wiring)

Stock N64ModernRuntime ships the entire `recompui_*` mod API but **never turns it on**. This
project enables it in `src/main.cpp`, before `recomp::start()` loads mods:

```cpp
namespace recompui { void register_ui_exports(); }
extern "C" void recomp_run_ui_callbacks(uint8_t*, recomp_context*);
...
recompui::register_ui_exports();   // registers ~130 recompui_* guest exports
recomp::overlays::register_base_export("recomp_run_ui_callbacks", recomp_run_ui_callbacks);
```

Without this, a mod importing `recompui_*` fails to load with *"Imported function not found."*
(This is our code in `src/`, not a `patches/deps/` patch — it survives a deps re-clone.)

## Authoring a screen

Include **only** `modding.h` + `recompui.h` (never `recomputils.h`). See
`mods/recompui-demo/src/demo.c` for a complete, working reference.

1. **Build the context once** (lazily on the first frame). Between `recompui_open_context` and
   `recompui_close_context`, create an element tree under the context root and style it:

   ```c
   s_ctx = recompui_create_context();
   recompui_open_context(s_ctx);
   RecompuiResource root  = recompui_context_root(s_ctx);
   recompui_set_display(root, RECOMPUI_DISPLAY_FLEX);
   recompui_set_justify_content(root, RECOMPUI_JUSTIFY_CENTER);
   recompui_set_align_items(root, RECOMPUI_ALIGN_CENTER);
   recompui_set_width(root, 100.0f, RECOMPUI_UNIT_PERCENT);
   recompui_set_height(root, 100.0f, RECOMPUI_UNIT_PERCENT);

   RecompuiResource panel = recompui_create_element(s_ctx, root);
   /* ...flex column, padding, background_color, border... */
   RecompuiResource title = recompui_create_label(s_ctx, panel, "MY SCREEN", RECOMPUI_LABEL_LARGE);
   RecompuiResource btn   = recompui_create_button(s_ctx, panel, "PLAY", RECOMPUI_BUTTON_PRIMARY);
   recompui_register_callback(btn, on_play, 0);   // must be called while the context is open
   recompui_close_context(s_ctx);
   ```

2. **Show / hide** it in response to game state or input, and **capture input** so the game
   behind it stops reacting (this is the clean fix for the overlay input-leak problem):

   ```c
   recompui_set_context_captures_input(s_ctx, 1);
   recompui_show_context(s_ctx);
   /* later */ recompui_hide_context(s_ctx);
   ```

3. **Pump callbacks every frame** so clicks reach your handlers. There is no built-in per-frame
   event in this runtime, so hook a function that runs each frame (e.g. `Scene_Update`) and call
   `recomp_run_ui_callbacks()`:

   ```c
   RECOMP_HOOK("Scene_Update") void tick(void) {
       if (!built) build_ui();
       recomp_run_ui_callbacks();     // dispatch queued clicks -> your callbacks
       /* toggle show/hide based on game state */
   }
   ```

Callback signature (invoked in guest context by the pump):

```c
static void on_play(RecompuiResource res, RecompuiEventData *e, void *userdata) {
    if (e->type != UI_EVENT_CLICK) return;
    /* react: change a label (recompui_set_text), hide the context, set game RAM, etc. */
}
```

## API surface (in `mods/common/include/recompui.h`)

- **Context:** `recompui_create_context`, `open`/`close_context`, `context_root`,
  `show`/`hide_context`, `set_context_captures_input`/`_mouse`.
- **Elements:** `recompui_create_element` (generic container), `create_button`, `create_label`,
  `destroy_element`.
- **Layout/style (on a resource):** `set_display`, `set_flex_direction`, `set_justify_content`,
  `set_align_items`, `set_width`/`height`/`min_width` (+ `_auto`), `set_padding`, `set_margin`
  (+ `_auto`), `set_gap`, `set_border_width`/`_radius`/`_color`, `set_background_color`,
  `set_color`, `set_font_size`, `set_text`, `set_opacity`, `set_nav_auto`. Dimension setters take
  `(res, float value, RecompuiUnit unit)`; colour setters take a `const RecompuiColor*`.
- **Callbacks:** `recompui_register_callback` + `recomp_run_ui_callbacks`.
- Enums: `RecompuiButtonStyle`, `RecompuiLabelStyle`, `RecompuiDisplay`, `RecompuiFlexDirection`,
  `RecompuiJustifyContent`, `RecompuiAlignItems`, `RecompuiUnit`, `RecompuiNavDirection`;
  event structs `RecompuiEventData`/`RecompuiEventType`.

The runtime exposes more (`create_span`, text inputs, sliders, radios, images from bytes, and
many more setters); add them to `recompui.h` as `RECOMP_IMPORT("*", <prototype>)` when needed —
derive the exact prototype from `lib/RecompFrontend/recompui/src/api/ui_api.cpp`.

## Loading new content (images)

The runtime exports `recompui_create_texture_rgba32` / `recompui_create_texture_image_bytes`
(PNG/DDS) → `recompui_create_imageview`, so a mod can display its own art (e.g. stage
thumbnails). Bake the image bytes into the mod's `.rodata` (mods have no file IO and
`build_mod.sh` currently strips `additional_files` from the `.nrm`), or extend `build_mod.sh` +
add a runtime file-read export if you need external asset files. These image imports aren't in
`recompui.h` yet — add them the same way when you build a content-loading screen.

## Input flow & the leak fix

When any shown context has `captures_input`, the frontend routes keyboard/gamepad input to it
and **suppresses the game's controller** (`recompui/src/base/ui_state.cpp:686`,
`recompinput/src/input_events.cpp:48`). So a recompui screen has no input-leak problem — unlike
an overlay drawn over the live menu, where the menu consumes `g_buttonsPressed` inline and a
`RECOMP_HOOK` can't reliably suppress it.

## Testing note (WSLg headless)

The headless harness injects input into the **game's** controller (`TNT_INPUT`), which recompui
does not read — recompui takes input from the app's SDL/UI layer. So the headless rig can verify
a mod screen **loads and renders** (see `tools/e2e/verify_recompui_demo.py`) but **cannot drive
clicks**; interactivity is confirmed by the context-agnostic input routing in the frontend and
works with real keyboard/gamepad. `mods/recompui-demo` renders its panel over the menu (verified
screenshot) and is the reference implementation.

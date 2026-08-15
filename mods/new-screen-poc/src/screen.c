#include "modding.h"

// new-screen-poc — proof of concept for drawing our OWN content on a menu screen.
//
// STAGE 1 (this file): the open question from docs/ADDING-A-MENU-SCREEN.md — "can a
// MIPS mod CALL a game function (not just hook one)?" We test it the cheapest way:
// hook Scene_Main's RETURN (fires after the menu engine has drawn, once per frame
// during scene 4) and call the game's own text drawer to render a custom string on
// the main menu. If our text shows up in a screenshot, the whole mechanism works and
// we can grow this into an OK/BACK screen (stage 2) and a level-select shell (stage 3).
//
// Grounded in the scene-4 RE:
//   - hook point: Scene_Main @ 0x80099674 (shared with Credits/Game-Over -> gate on
//     g_currentScene==4).
//   - text drawer: displayText_XY_RGBA_2 @ 0x80077960, o32 args
//       (void* gdl=&g_gdl, void* font=&g_sceneFontObj8, int x, int y,
//        const char* str, int r, int g, int b, int a).
//   - fixed globals: g_gdl @ 0x800E20C0, g_sceneFontObj8 @ 0x80128F28.
//
// A mod's `static const char[]` lives in mod memory the loader maps into guest RAM, so
// the recompiled drawer can read it. Only modding.h is included (no recomputils.h).

// Call the game's text drawer THROUGH A FUNCTION POINTER at its absolute guest address.
// A direct extern-symbol call emits a `jal` (R_MIPS_26) the mod linker can't reach the
// game with ("relocation truncated to fit"); an indirect call through a constant address
// emits `jalr`, which the recomp runtime dispatches by guest address — the same way the
// game itself does its LOOKUP_FUNC(item+0x28) indirect calls.
typedef void (*displayText_fn)(void *gdl, void *font, int x, int y,
                               const char *str, int r, int g, int b, int a);
#define displayText_XY_RGBA_2 ((displayText_fn)0x80077960)

#define G_CURRENT_SCENE (*(volatile unsigned char *)0x800CFEE8)
#define G_GDL           ((void *)0x800E20C0)   // g_gdl
#define G_FONT8         ((void *)0x80128F28)   // g_sceneFontObj8
#define SCENE_MENU_HUB  4

static const char POC_STR[] = "MOD SCREEN POC";

// RECOMP_HOOK_RETURN fires at the function's return — after Scene_Main has issued the
// menu's own draws for this frame, which is the safe moment to overlay our text.
RECOMP_HOOK_RETURN("Scene_Main") void tnt_poc_draw(void) {
    if (G_CURRENT_SCENE != SCENE_MENU_HUB) {
        return;  // Scene_Main is shared with Credits/Game-Over
    }
    // Draw our string near the top-left in solid white. If this shows on the menu, a
    // mod can both hook AND call game functions, and render with the game's font.
    displayText_XY_RGBA_2(G_GDL, G_FONT8, 20, 20, POC_STR, 0xFF, 0xFF, 0xFF, 0xFF);
}

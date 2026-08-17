#include "modding.h"

// stage-native — PARASITE approach to in-game menus (test: NO scratch-RAM writes).
//
// Hypothesis under test (user's): the mystery "garbled" held-state text is our own doing -- the
// mod was writing scratch at 0x807FF000 / 0x807FFF00, which sit at the very TOP of RDRAM where the
// N64 stack / high structures live. Writing there can corrupt live game memory. This version
// removes ALL scratch writes: it only holds the launch, hides the SINGLE foreground items, and
// draws the parasite. If the garbled text is gone, the scratch was the cause and the fix is to use
// real allocation (recomp_alloc / mod static memory) for any mod state -- never raw high-RAM.

typedef void (*displayText_fn)(void *gdl, void *font, int x, int y,
                               const char *str, int r, int g, int b, int a);
#define DrawText ((displayText_fn)0x80077960)          // displayText_XY_RGBA_2

#define G_CURRENT_SCENE (*(volatile unsigned char *)0x800CFEE8) // g_currentScene (4 = menu hub)
#define G_LOAD_FLAG     (*(volatile unsigned char *)0x800D3CF0) // g_sceneLoadFlag (launch latch)
#define G_MENU_IDLE     (*(volatile unsigned int  *)0x800D3D2C) // g_sceneMainTimer (attract idle)
#define G_GDL           ((void *)0x800E20C0)                    // g_gdl
#define G_FONT8         ((void *)0x80128F28)                    // g_sceneFontObj8
#define SCENE_CTX_TABLE_PTR (*(volatile unsigned int *)0x801291F4) // active item table pointer

#define SCENE_MENU_HUB 4
#define ST_IDLE 0
#define ST_SHOWING 1

// All mod state lives in the mod's OWN static memory (loader-allocated) -- never raw high RAM.
static int s_state = ST_IDLE;

// 1. Hold the launch + enter parasite mode.
RECOMP_HOOK("MenuHub_StartPlaying") void tnt_native_intercept(void) {
    if (G_CURRENT_SCENE != SCENE_MENU_HUB) return;
    if (s_state == ST_IDLE) {
        if (G_LOAD_FLAG == 1) { s_state = ST_SHOWING; G_LOAD_FLAG = 0; }
    } else if (s_state == ST_SHOWING) {
        G_LOAD_FLAG = 0;                    // keep holding
    }
}

// 3. Blank the SINGLE foreground: keep item 0 (stone-block background), hide items 1..7 (frame,
//    title, NAME/OPPONENT/GAME rows, footer) by zeroing each item's alpha (+0x1C).
RECOMP_HOOK("Scene_Update") void tnt_native_blank(void) {
    if (G_CURRENT_SCENE == SCENE_MENU_HUB && s_state == ST_SHOWING) {
        G_MENU_IDLE = 0;                    // don't idle out to attract
        unsigned int tbl = SCENE_CTX_TABLE_PTR;
        for (int i = 1; i < 12; i++) {      // item 0 = background: keep
            volatile unsigned char *it = (volatile unsigned char *)(tbl + i * 0x38);
            unsigned int flags = *(volatile unsigned short *)(it + 0x24);
            if (flags & 0x8000) break;      // terminator
            *(volatile unsigned int *)(it + 0x1C) = 0;   // alpha = 0 (hide)
        }
    }
}

// 4. Draw our parasite on top with the game's font (after the whole menu frame).
RECOMP_HOOK_RETURN("Scene_Main") void tnt_native_draw(void) {
    if (G_CURRENT_SCENE != SCENE_MENU_HUB || s_state != ST_SHOWING) return;
    DrawText(G_GDL, G_FONT8, 40, 30, "PARASITE SCREEN", 0xFF, 0xF0, 0x40, 0xFF);
    DrawText(G_GDL, G_FONT8, 40, 60, "no scratch writes", 0xC0, 0xC0, 0xC0, 0xFF);
}

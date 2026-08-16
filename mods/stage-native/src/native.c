#include "modding.h"

// stage-native — the PARASITE approach to in-game menus.
//
// Idea (per design): don't try to REPLACE a hub screen (impossible cleanly — SINGLE's title/
// frame are drawn inline by Scene_Main). Instead:
//   1. sit on an existing scene-4 screen (host) that already renders the block background,
//   2. disable the host's INPUT (freeze it so it can't act on buttons),
//   3. disable the host's FOREGROUND rendering, keeping only the block background,
//   4. draw our OWN screen (parasite) on top with the game's own font.
// Get it working once, then abstract into a reusable "add a menu" primitive.
//
// STATUS (working): step 3 is SOLVED via the item table. The scene-4 screen is drawn from an
// item table at sceneCtx+0x124 (sceneCtx=0x801290D0 -> ptr @0x801291F4), 0x38-byte items,
// terminator = (+0x24 & 0x8000). For the SINGLE host the map is: item 0 = the stone-block
// BACKGROUND (keep); items 1..7 = the wooden frame + "SINGLE" title + NAME/OPPONENT/GAME rows +
// footer = the FOREGROUND (hide). We hide an item by zeroing its alpha (+0x1C) every frame. So:
// keep item 0, hide the rest -> a clean stone-block background, then draw our own screen on top.
//
// REMAINING: (i) a debug/stats text overlay ("VOWZ VX 4(6..3%..)") appears in the HELD-launch
// state (present even with zero item-hiding; stage-select happened to cover it with its list) --
// still hunting what draws it. (ii) input ownership. (iii) the real SELECT STAGE list. (iv)
// abstract steps 1-4 into a reusable "add a menu" primitive.
//
// HIDE_FROM/HIDE_TO below select which item indices to blank (mapping knob).

typedef void (*displayText_fn)(void *gdl, void *font, int x, int y,
                               const char *str, int r, int g, int b, int a);
#define DrawText ((displayText_fn)0x80077960)          // displayText_XY_RGBA_2

#define G_CURRENT_SCENE (*(volatile unsigned char *)0x800CFEE8) // g_currentScene (4 = menu hub)
#define G_LOAD_FLAG     (*(volatile unsigned char *)0x800D3CF0) // g_sceneLoadFlag (launch latch)
#define G_OBJ_RENDER    (*(volatile unsigned int  *)0x800D3D94) // g_sceneObjRenderEnable
#define G_MENU_IDLE     (*(volatile unsigned int  *)0x800D3D2C) // g_sceneMainTimer (attract idle)
#define G_GDL           ((void *)0x800E20C0)                    // g_gdl
#define G_FONT8         ((void *)0x80128F28)                    // g_sceneFontObj8
#define G_STATE         (*(volatile unsigned int  *)0x807FFF14) // scratch: state (for tests)

#define SCENE_MENU_HUB 4
#define ST_IDLE 0
#define ST_SHOWING 1

static int s_state = ST_IDLE;
static unsigned int s_saved_render = 0;   // remember host's render flag to restore on exit

// Hold the launch + enter parasite mode.
RECOMP_HOOK("MenuHub_StartPlaying") void tnt_native_intercept(void) {
    if (G_CURRENT_SCENE != SCENE_MENU_HUB) return;
    if (s_state == ST_IDLE) {
        if (G_LOAD_FLAG == 1) {
            s_state = ST_SHOWING;
            s_saved_render = G_OBJ_RENDER;
            G_LOAD_FLAG = 0;                // hold the launch
        }
    } else if (s_state == ST_SHOWING) {
        G_LOAD_FLAG = 0;                    // keep holding
    }
    G_STATE = (unsigned int)s_state;
}

// Step 3 experiment: blank the host foreground each frame (candidate lever).
// ALSO: dump the active item table so we can classify items (bg vs fg). Table pointer lives at
// sceneCtx+0x124 (sceneCtx = 0x801290D0 -> 0x801291F4). Each item is 0x38 bytes; terminator has
// +0x24 & 0x8000. Dump to a scratch region the probe reads: 0x807FF000.
#define SCENE_CTX_TABLE_PTR (*(volatile unsigned int *)0x801291F4)
#define DUMP ((volatile unsigned int *)0x807FF000)
static int s_dumped = 0;

// Which item indices to hide (alpha=0). Configured here for mapping experiments.
// 0xFF in the mask position means "hide". We hide ALL items first to see what's item-driven.
#define HIDE_FROM 1     // hide items [HIDE_FROM .. HIDE_TO]
#define HIDE_TO   7

#define G_DEBUG_PRINT_ACTIVE (*(volatile unsigned char *)0x800D38F0)

RECOMP_HOOK("Scene_Update") void tnt_native_blank(void) {
    if (G_CURRENT_SCENE == SCENE_MENU_HUB && s_state == ST_SHOWING) {
        G_MENU_IDLE = 0;                    // don't idle out to attract
        G_DEBUG_PRINT_ACTIVE = 0;           // try to kill the held-state debug stats overlay
        unsigned int tbl = SCENE_CTX_TABLE_PTR;
        if (!s_dumped) { s_dumped = 1; DUMP[0] = tbl; }
        // Blank foreground items by zeroing alpha (+0x1C) each frame, up to the terminator.
        for (int i = 0; i < 12; i++) {
            volatile unsigned char *it = (volatile unsigned char *)(tbl + i * 0x38);
            unsigned int flags = *(volatile unsigned short *)(it + 0x24);
            if (flags & 0x8000) break;      // terminator
            if (i >= HIDE_FROM && i <= HIDE_TO) {
                *(volatile unsigned int *)(it + 0x1C) = 0;   // alpha = 0 (hide)
            }
        }
    }
}

// Step 4: draw our parasite on top with the game's font (after the whole menu frame).
RECOMP_HOOK_RETURN("Scene_Main") void tnt_native_draw(void) {
    if (G_CURRENT_SCENE != SCENE_MENU_HUB || s_state != ST_SHOWING) return;
    DrawText(G_GDL, G_FONT8, 40, 30, "PARASITE SCREEN", 0xFF, 0xF0, 0x40, 0xFF);
    DrawText(G_GDL, G_FONT8, 40, 60, "block bg should remain,", 0xC0, 0xC0, 0xC0, 0xFF);
    DrawText(G_GDL, G_FONT8, 40, 78, "host foreground gone", 0xC0, 0xC0, 0xC0, 0xFF);
}

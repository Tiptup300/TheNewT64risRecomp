#include "modding.h"

// new-screen-poc — a mod-drawn menu SCREEN, built up in stages.
//   Stage 1 (proven): a mod can hook Scene_Main's return AND call the game's own text
//     drawer (via an indirect function-pointer to the guest address) to render text on
//     the menu. See the commit "stage 1 PROVEN" + docs/ADDING-A-MENU-SCREEN.md.
//   Stage 2/3 (this file): a real overlay screen — a titled LEVEL SELECT list with a
//     movable cursor and OK/BACK, driven entirely by the N64 C-buttons so it NEVER
//     conflicts with the live main menu underneath (the menu ignores C-buttons; a mod
//     hook can't suppress the menu's own A/B/D-pad handling, so we avoid those).
//
// Controls (only while g_currentScene==4, the menu hub):
//   closed:  C-Up            -> open the LEVEL SELECT overlay
//   open:    C-Up / C-Down   -> move the cursor up / down (wraps)
//            C-Right         -> OK (confirm the highlighted level; shows a banner)
//            C-Left          -> BACK (close the overlay)
//
// This is a *shell*: OK only records the selection (a mod-owned int + on-screen
// banner). It does NOT change the real game level yet — that's deliberately left for
// later, per the plan. Draws only; disabled by default; changes nothing when closed.

// --- call the game's text drawer via a function pointer at its guest address ---
// (A direct extern call emits a jal the mod linker can't reach the game with; an
// indirect jalr is dispatched by the recomp runtime. This is the general recipe for a
// mod to call ANY game function — see docs/MODDING.md.)
typedef void (*displayText_fn)(void *gdl, void *font, int x, int y,
                               const char *str, int r, int g, int b, int a);
#define DrawText ((displayText_fn)0x80077960)   // displayText_XY_RGBA_2

#define G_CURRENT_SCENE (*(volatile unsigned char *)0x800CFEE8)  // g_currentScene
#define G_BUTTONS       (*(volatile unsigned int *)0x8011EF54)   // g_buttonsPressed (menu edge mask)
#define G_MENU_IDLE     (*(volatile unsigned int *)0x800D3D2C)   // menu attract-idle counter
                                                                 // (found monotonic on idle scene 4)
#define G_GDL           ((void *)0x800E20C0)   // g_gdl
#define G_FONT8         ((void *)0x80128F28)   // g_sceneFontObj8
#define SCENE_MENU_HUB  4

// N64 controller C-button bits (OS_CONT layout).
#define BTN_C_RIGHT 0x0001u
#define BTN_C_LEFT  0x0002u
#define BTN_C_DOWN  0x0004u
#define BTN_C_UP    0x0008u

#define N_LEVELS 8
static const char *const LEVEL_NAMES[N_LEVELS] = {
    "LEVEL 1", "LEVEL 2", "LEVEL 3", "LEVEL 4",
    "LEVEL 5", "LEVEL 6", "LEVEL 7", "LEVEL 8",
};
// (The game font has no '-' glyph — it renders as a box — so labels use only
// letters, digits and spaces.)
static const char *const OK_BANNERS[N_LEVELS] = {
    "OK  LEVEL 1", "OK  LEVEL 2", "OK  LEVEL 3", "OK  LEVEL 4",
    "OK  LEVEL 5", "OK  LEVEL 6", "OK  LEVEL 7", "OK  LEVEL 8",
};

// mod-owned screen state
static int   s_open = 0;
static int   s_cursor = 0;
static int   s_selected = -1;      // last OK'd level (-1 = none)
static unsigned int s_prev = 0;    // previous frame's button mask (own edge detection)
static int   s_cooldown = 0;       // frames to ignore input after an action

static void draw_overlay(void) {
    DrawText(G_GDL, G_FONT8, 30, 28, "LEVEL SELECT", 0xFF, 0xF0, 0x40, 0xFF);
    // The level list; the highlighted row is drawn brighter with a '>' marker.
    int y = 54;
    for (int i = 0; i < N_LEVELS; i++) {
        if (i == s_cursor) {
            DrawText(G_GDL, G_FONT8, 22, y, ">", 0xFF, 0xF0, 0x40, 0xFF);
            DrawText(G_GDL, G_FONT8, 40, y, LEVEL_NAMES[i], 0xFF, 0xF0, 0x40, 0xFF);
        } else {
            DrawText(G_GDL, G_FONT8, 40, y, LEVEL_NAMES[i], 0xC0, 0xC0, 0xC0, 0xFF);
        }
        y += 17;
    }
    // Confirmation banner (after OK), below the list.
    if (s_selected >= 0 && s_selected < N_LEVELS) {
        DrawText(G_GDL, G_FONT8, 30, y + 4, OK_BANNERS[s_selected], 0x60, 0xFF, 0x60, 0xFF);
    }
    // Footer legend (letters/digits/spaces only — no '-' glyph in the font).
    DrawText(G_GDL, G_FONT8, 30, 216, "CUP CDN MOVE   CRIGHT OK   CLEFT BACK",
             0xA0, 0xA0, 0xA0, 0xFF);
}

RECOMP_HOOK_RETURN("Scene_Main") void tnt_level_select(void) {
    if (G_CURRENT_SCENE != SCENE_MENU_HUB) {   // shared with Credits/Game-Over
        s_open = 0;
        return;
    }

    // rising edges since last frame (our own edge detection, robust to hold/repeat)
    unsigned int now = G_BUTTONS;
    unsigned int edge = now & ~s_prev;
    s_prev = now;
    if (s_cooldown > 0) { s_cooldown--; edge = 0; }

    if (!s_open) {
        if (edge & BTN_C_UP) { s_open = 1; s_cooldown = 6; }
        return;   // draw nothing while closed
    }

    // While our overlay owns the screen, keep the menu from idling out to the attract
    // demo (our C-buttons aren't "real" menu input, so they don't reset this counter).
    G_MENU_IDLE = 0;

    // open: handle navigation
    if (edge & BTN_C_DOWN) { s_cursor = (s_cursor + 1) % N_LEVELS; s_cooldown = 6; }
    else if (edge & BTN_C_UP) { s_cursor = (s_cursor + N_LEVELS - 1) % N_LEVELS; s_cooldown = 6; }
    else if (edge & BTN_C_RIGHT) { s_selected = s_cursor; s_cooldown = 6; }
    else if (edge & BTN_C_LEFT) { s_open = 0; s_cooldown = 6; return; }

    draw_overlay();
}

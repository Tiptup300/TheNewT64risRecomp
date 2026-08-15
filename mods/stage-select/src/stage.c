#include "modding.h"

// stage-select — a REAL in-flow menu screen inserted into the ONE PLAYER flow.
//
// Flow: MENU -> ONE PLAYER -> SINGLE (name/opponent/game) -> press Accept, then INSTEAD
// of the game starting you see a new "SELECT STAGE" screen. Up/Down move between the 8
// stage themes, Accept picks one and starts the game, Back returns to the SINGLE screen.
//
// The 8 stages are the game's REAL named culture themes (the wonders-of-the-world
// motif the whole game is built around): Africa, Celtic, Egypt, Greek, Japan, Mayan,
// Russia, and the bonus Industrial. (Sourced from the game's documented theme set.)
//
// HOW THE FLOW INTERCEPT WORKS (from RE of the launch path):
//   - Pressing Accept on SINGLE runs Scene_SingleStartGame, which only ARMS a latch:
//     g_sceneLoadFlag (0x800D3CF0) = 1. The game doesn't start yet.
//   - On the NEXT scene-4 frame, MenuHub_StartPlaying sees the latch and commits
//     (sets g_currentScene = 9 + Game_Init). MenuHub is a no-op while the latch is 0.
//   So this mod hooks MenuHub_StartPlaying: when the latch is armed (==1) and we
//   haven't shown our screen yet, it HOLDS the latch at 0 (game waits) and opens our
//   screen. When the player picks a stage we re-arm the latch (=1) and the next
//   MenuHub tick launches normally. Back leaves the latch at 0 -> stays on SINGLE.
//
// INPUT OWNERSHIP: while our screen is up we zero g_buttonsPressed at Scene_Main's
// ENTRY (after capturing it), so the SINGLE screen behind us ignores input; our screen
// reads the captured buttons in Scene_Main's RETURN hook. That lets us use the REAL
// Up/Down + A/B buttons without the SINGLE menu also reacting.
//
// Draws with the game's own text drawer via a function pointer at its guest address
// (a direct call can't link from a mod; see docs/MODDING.md). Disabled by default.

typedef void (*displayText_fn)(void *gdl, void *font, int x, int y,
                               const char *str, int r, int g, int b, int a);
#define DrawText ((displayText_fn)0x80077960)          // displayText_XY_RGBA_2

#define G_CURRENT_SCENE (*(volatile unsigned char *)0x800CFEE8) // g_currentScene
#define G_LOAD_FLAG     (*(volatile unsigned char *)0x800D3CF0) // g_sceneLoadFlag (launch latch)
#define G_BUTTONS       (*(volatile unsigned int  *)0x8011EF54) // g_buttonsPressed (menu edge mask)
#define G_CURRENT_SONG  (*(volatile unsigned char *)0x8011E4F8) // g_currentSong (0..7) — best-effort theme
#define G_MENU_IDLE     (*(volatile unsigned int  *)0x800D3D2C) // menu attract-idle counter
#define G_GDL           ((void *)0x800E20C0)                    // g_gdl
#define G_FONT8         ((void *)0x80128F28)                    // g_sceneFontObj8
#define G_STAGE_CHOICE  (*(volatile unsigned int  *)0x807FFF10) // mod scratch: last-picked stage (for tests)
#define G_STAGE_STATE   (*(volatile unsigned int  *)0x807FFF14) // mod scratch: current state machine value (for tests)
#define G_STAGE_CURSOR  (*(volatile unsigned int  *)0x807FFF18) // mod scratch: current cursor index (for tests)

#define SCENE_MENU_HUB 4
#define SCENE_GAMEPLAY 9

// N64 button bits (OS_CONT).
#define BTN_A     0x8000u   // accept
#define BTN_B     0x4000u   // back
#define BTN_UP    0x0800u
#define BTN_DOWN  0x0400u

// State machine.
#define ST_IDLE    0   // not intercepting
#define ST_SHOWING 1   // our screen is up, launch held
#define ST_DONE    2   // stage chosen, let the launch proceed

#define N_STAGES 8
static const char *const STAGE_NAMES[N_STAGES] = {
    "AFRICA", "CELTIC", "EGYPT", "GREEK",
    "JAPAN", "MAYAN", "RUSSIA", "INDUSTRIAL",
};
// Per-stage swatch colors (a color-coded "icon" per row). The game font has no picture
// glyphs, but it renders '-' as a solid box, so a short run of them drawn in these
// colors makes a small colored bar next to each name.
static const unsigned char STAGE_RGB[N_STAGES][3] = {
    {0xE0, 0x80, 0x20},  // Africa     - earthy orange
    {0x30, 0xC0, 0x40},  // Celtic     - green
    {0xE0, 0xC0, 0x30},  // Egypt      - gold
    {0x70, 0x90, 0xF0},  // Greek      - marble blue
    {0xE0, 0x30, 0x30},  // Japan      - red
    {0x20, 0xC0, 0xB0},  // Mayan      - jade
    {0xA0, 0x50, 0xE0},  // Russia     - royal purple
    {0x90, 0x90, 0x90},  // Industrial - steel gray
};
#define SWATCH "----"   // '-' renders as a solid box in the game font -> a colored bar

static int s_state = ST_IDLE;
static int s_cursor = 0;
static int s_chosen = -1;             // stage picked this launch (-1 = none), forced at Game_Init
static unsigned int s_captured = 0;   // buttons captured at Scene_Main entry this frame
static unsigned int s_prev = 0;       // previous frame's captured mask (edge detection)
static int s_cooldown = 0;            // ignore input briefly after opening (swallow the launch press)

// --- 1. Launch interceptor: hold the latch and open our screen. ---
RECOMP_HOOK("MenuHub_StartPlaying") void tnt_stage_intercept(void) {
    if (G_CURRENT_SCENE != SCENE_MENU_HUB) return;
    if (s_state == ST_IDLE) {
        // g_sceneLoadFlag == 1 is the single-player / default gameplay launch path.
        if (G_LOAD_FLAG == 1) {
            s_state = ST_SHOWING;
            s_cursor = 0;
            s_prev = 0xFFFFFFFFu;   // treat everything as "already held" so the Accept
            s_cooldown = 12;        // press that launched us doesn't leak into our screen
            G_LOAD_FLAG = 0;        // hold the launch
        }
    } else if (s_state == ST_SHOWING) {
        G_LOAD_FLAG = 0;            // keep holding while our screen is up
    }
    // ST_DONE: leave the (re-armed) latch alone so MenuHub commits the launch.
    G_STAGE_STATE = (unsigned int)s_state;   // expose state for tests
    G_STAGE_CURSOR = (unsigned int)s_cursor;
}

// --- 2. Input ownership: freeze the SINGLE screen behind us. ---
RECOMP_HOOK("Scene_Main") void tnt_stage_capture(void) {
    if (G_CURRENT_SCENE == SCENE_MENU_HUB && s_state == ST_SHOWING) {
        s_captured = G_BUTTONS;    // remember the real input for our own use
        G_BUTTONS = 0;             // the SINGLE menu sees nothing this frame
        G_MENU_IDLE = 0;           // don't let the menu idle out to attract
    }
}

static void draw_screen(void) {
    DrawText(G_GDL, G_FONT8, 30, 26, "SELECT STAGE", 0xFF, 0xF0, 0x40, 0xFF);
    int y = 52;
    for (int i = 0; i < N_STAGES; i++) {
        const unsigned char *c = STAGE_RGB[i];
        // cursor marker
        if (i == s_cursor) {
            DrawText(G_GDL, G_FONT8, 18, y, ">", 0xFF, 0xF0, 0x40, 0xFF);
        }
        // color-coded swatch "icon" (brighter for the highlighted row)
        int hi = (i == s_cursor);
        DrawText(G_GDL, G_FONT8, 34, y, SWATCH,
                 c[0], c[1], c[2], hi ? 0xFF : 0xC0);
        // stage name
        if (hi) {
            DrawText(G_GDL, G_FONT8, 74, y, STAGE_NAMES[i], 0xFF, 0xF0, 0x40, 0xFF);
        } else {
            DrawText(G_GDL, G_FONT8, 74, y, STAGE_NAMES[i], 0xC0, 0xC0, 0xC0, 0xFF);
        }
        y += 17;
    }
    DrawText(G_GDL, G_FONT8, 30, 214, "UP DN MOVE   A OK   B BACK", 0xA0, 0xA0, 0xA0, 0xFF);
}

// --- 3. Draw + navigate our screen (runs after the SINGLE menu has drawn). ---
RECOMP_HOOK_RETURN("Scene_Main") void tnt_stage_screen(void) {
    if (G_CURRENT_SCENE != SCENE_MENU_HUB || s_state != ST_SHOWING) return;

    unsigned int edge = s_captured & ~s_prev;
    s_prev = s_captured;
    if (s_cooldown > 0) { s_cooldown--; edge = 0; }

    if (edge & BTN_DOWN)      s_cursor = (s_cursor + 1) % N_STAGES;
    else if (edge & BTN_UP)   s_cursor = (s_cursor + N_STAGES - 1) % N_STAGES;
    else if (edge & BTN_A) {                 // OK: pick this stage and let the game start
        G_STAGE_CHOICE = (unsigned int)s_cursor;
        s_chosen = s_cursor;                 // forced again at Game_Init (after the game's
                                             // own randomize) so the theme actually sticks
        G_CURRENT_SONG = (unsigned char)s_cursor;
        s_state = ST_DONE;
        G_LOAD_FLAG = 1;                     // re-arm; next MenuHub tick launches
        return;                              // stop drawing this frame
    } else if (edge & BTN_B) {               // BACK: return to the SINGLE screen
        s_state = ST_IDLE;                   // latch stays 0 -> no launch; SINGLE resumes
        return;
    }
    draw_screen();
}

// --- 4. At launch: force the chosen theme (after the game's own randomize) and reset. ---
RECOMP_HOOK("Game_Init") void tnt_stage_reset(void) {
    if (s_chosen >= 0) {
        G_CURRENT_SONG = (unsigned char)s_chosen;   // stick the picked theme past MenuHub's rand
    }
    s_chosen = -1;
    s_state = ST_IDLE;
}

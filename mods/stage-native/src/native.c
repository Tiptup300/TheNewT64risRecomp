#include "modding.h"

// stage-native — an IN-GAME SELECT STAGE menu via the PARASITE technique.
//
// Flow: ONE PLAYER -> SINGLE -> press A. Instead of launching, we sit on the SINGLE screen as a
// host: blank its foreground (keep the block-stone background), own the input, and draw our own
// SELECT STAGE list in the game's own font on that background. Up/Down move; A picks the stage and
// starts the game IN that stage; B goes back and RESTORES the SINGLE screen exactly (no state drift).
//
// Why parasite (not replace): the scene-4 screens are drawn item-by-item by Scene_Main; SINGLE's
// title/frame/rows are items in the active table (sceneCtx+0x124 -> ptr @0x801291F4, 0x38-byte
// items, terminator +0x24&0x8000). Item 0 = the stone-block BACKGROUND (keep); items 1..7 = the
// foreground (hide by zeroing alpha +0x1C). We save/restore those alphas so Back leaves SINGLE intact.
//
// MEMORY SAFETY: all mod state lives in the mod's own static memory (the loader places mod globals
// at 0x81000000+, a safe region). We never write raw high-RAM scratch (0x807F...) — that is the
// game's own stack/heap and corrupts it. We only read/write documented GAME globals + the item table.
//
// INPUT OWNERSHIP: the host consumes g_buttonsPressed inline, so we (a) capture it at Scene_Main
// entry for our own nav then zero it (denies B=back-out / A=stray-launch to the host), and (b)
// re-assert the host's saved menu state (cursor / g_sceneMainState / decay) in the Scene_Main
// return hook to undo anything leaked input still managed to do. Result: Back returns to SINGLE
// intact, Up/Down don't drift the host, and the earlier held-state text artifact is gone.
// Verified end to end by tools/e2e/test_stage_select.py (open / back-safe / pick -> gameplay).

typedef void (*displayText_fn)(void *gdl, void *font, int x, int y,
                               const char *str, int r, int g, int b, int a);
#define DrawText ((displayText_fn)0x80077960)          // displayText_XY_RGBA_2

#define G_CURRENT_SCENE (*(volatile unsigned char *)0x800CFEE8) // g_currentScene (4 = menu hub)
#define G_LOAD_FLAG     (*(volatile unsigned char *)0x800D3CF0) // g_sceneLoadFlag (launch latch)
#define G_MENU_IDLE     (*(volatile unsigned int  *)0x800D3D2C) // g_sceneMainTimer (attract idle)
#define G_MENU_CURSOR   (*(volatile int           *)0x800D3D00) // g_sceneMenuCursor (host cursor)
#define G_DECAY_ACTIVE  (*(volatile unsigned char *)0x800D3E34) // g_sceneMainDecayActive (transition dir)
#define G_SCENE_MAIN_ST (*(volatile unsigned int  *)0x800D3D24) // g_sceneMainState
#define G_BUTTONS       (*(volatile unsigned int  *)0x8011EF54) // g_buttonsPressed (edge mask)
#define G_THEME_INDEX   (*(volatile unsigned char *)0x8011EEF8) // real environment/theme selector (0..7)
#define G_CURRENT_SONG  (*(volatile unsigned char *)0x8011E4F8) // g_currentSong (music)
#define G_GDL           ((void *)0x800E20C0)                    // g_gdl
#define G_FONT8         ((void *)0x80128F28)                    // g_sceneFontObj8
#define SCENE_CTX_TABLE_PTR (*(volatile unsigned int *)0x801291F4)

#define SCENE_MENU_HUB 4
#define BTN_A 0x8000u
#define BTN_B 0x4000u
#define BTN_UP 0x0800u
#define BTN_DOWN 0x0400u

#define ST_IDLE 0
#define ST_SHOWING 1
#define ST_DONE 2

#define N_STAGES 8
// Engine theme order (index == 0x8011EEF8), verified by tools/e2e/map_themes.py.
static const char *const STAGE_NAMES[N_STAGES] = {
    "MAYAN", "GREEK", "EGYPT", "CELTIC", "AFRICA", "JAPAN", "RUSSIA", "INDUSTRIAL",
};
static const unsigned char STAGE_RGB[N_STAGES][3] = {
    {0x20, 0xC0, 0xB0}, {0x70, 0x90, 0xF0}, {0xE0, 0xC0, 0x30}, {0x30, 0xC0, 0x40},
    {0xE0, 0x80, 0x20}, {0xE0, 0x30, 0x30}, {0xA0, 0x50, 0xE0}, {0x90, 0x90, 0x90},
};
#define SWATCH "----"   // '-' renders as a solid box in the game font -> a colored bar

// --- all mod state: mod static memory (loader-placed at 0x81000000+, safe) ---
static int s_state = ST_IDLE;
static int s_cursor = 0;
static int s_chosen = -1;
static unsigned int s_prev = 0;         // previous frame's captured buttons (edge detect)
static unsigned int s_frameacc = 0;     // this frame's captured buttons (from Scene_Main entry)
static int s_cooldown = 0;              // swallow the launch press for a few frames
static int s_saved = 0;                 // have we saved the host's foreground state?
static unsigned int s_saved_alpha[12];  // original item alphas (+0x1C) for Back-restore
static int s_saved_cursor = 0;          // host cursor at entry (frozen while shown, for Back-safety)
static unsigned int s_saved_state = 0;  // host g_sceneMainState at entry
static unsigned char s_saved_decay = 0; // host g_sceneMainDecayActive at entry

static void save_foreground(unsigned int tbl) {
    s_saved_cursor = G_MENU_CURSOR;
    s_saved_state  = G_SCENE_MAIN_ST;
    s_saved_decay  = G_DECAY_ACTIVE;
    for (int i = 0; i < 12; i++) {
        volatile unsigned char *it = (volatile unsigned char *)(tbl + i * 0x38);
        unsigned int flags = *(volatile unsigned short *)(it + 0x24);
        if (flags & 0x8000) { s_saved_alpha[i] = 0xFFFFFFFFu; break; }  // terminator sentinel
        s_saved_alpha[i] = *(volatile unsigned int *)(it + 0x1C);
    }
    s_saved = 1;
}

// Re-assert the host's saved menu state — undoes any nav/back-transition the leaked input
// started this frame (the game consumes g_buttonsPressed inline; we can't zero it in time, so
// we revert its effects here, after Scene_Main has run).
static void freeze_host_state(void) {
    G_MENU_CURSOR   = s_saved_cursor;
    G_SCENE_MAIN_ST = s_saved_state;
    G_DECAY_ACTIVE  = s_saved_decay;
}

static void restore_foreground(unsigned int tbl) {
    for (int i = 0; i < 12; i++) {
        if (s_saved_alpha[i] == 0xFFFFFFFFu) break;
        volatile unsigned char *it = (volatile unsigned char *)(tbl + i * 0x38);
        *(volatile unsigned int *)(it + 0x1C) = s_saved_alpha[i];
    }
    freeze_host_state();
    s_saved = 0;
}

// --- 1. Launch interceptor: hold the latch, enter parasite mode. ---
RECOMP_HOOK("MenuHub_StartPlaying") void tnt_native_intercept(void) {
    if (G_CURRENT_SCENE != SCENE_MENU_HUB) return;
    if (s_state == ST_IDLE) {
        if (G_LOAD_FLAG == 1) {             // single-player launch armed
            s_state = ST_SHOWING;
            s_cursor = 0;
            s_prev = 0xFFFFFFFFu;           // swallow the launch A-press
            s_cooldown = 10;
            s_saved = 0;
            G_LOAD_FLAG = 0;                // hold the launch
        }
    } else if (s_state == ST_SHOWING) {
        G_LOAD_FLAG = 0;                    // keep holding
    }
}

// --- 2. Capture input BEFORE the host consumes it (Scene_Main entry), for our own nav. ---
RECOMP_HOOK("Scene_Main") void tnt_native_capture(void) {
    if (G_CURRENT_SCENE == SCENE_MENU_HUB && s_state == ST_SHOWING) {
        s_frameacc = G_BUTTONS;   // keep the real input for our own nav
        G_BUTTONS = 0;            // best-effort: deny it to the host (esp. B = back-out)
    }
}

// --- 3. Blank the SINGLE foreground + freeze host state (keep the block background). ---
RECOMP_HOOK("Scene_Update") void tnt_native_blank(void) {
    if (G_CURRENT_SCENE == SCENE_MENU_HUB && s_state == ST_SHOWING) {
        G_MENU_IDLE = 0;                    // don't idle out to attract
        unsigned int tbl = SCENE_CTX_TABLE_PTR;
        if (!s_saved) save_foreground(tbl);
        for (int i = 1; i < 12; i++) {      // item 0 = background: keep
            volatile unsigned char *it = (volatile unsigned char *)(tbl + i * 0x38);
            unsigned int flags = *(volatile unsigned short *)(it + 0x24);
            if (flags & 0x8000) break;      // terminator
            *(volatile unsigned int *)(it + 0x1C) = 0;   // alpha = 0 (hide)
        }
    }
}

static void draw_screen(void) {
    DrawText(G_GDL, G_FONT8, 30, 26, "SELECT STAGE", 0xFF, 0xF0, 0x40, 0xFF);
    int y = 52;
    for (int i = 0; i < N_STAGES; i++) {
        const unsigned char *c = STAGE_RGB[i];
        int hi = (i == s_cursor);
        if (hi) DrawText(G_GDL, G_FONT8, 18, y, ">", 0xFF, 0xF0, 0x40, 0xFF);
        DrawText(G_GDL, G_FONT8, 34, y, SWATCH, c[0], c[1], c[2], hi ? 0xFF : 0xC0);
        if (hi) DrawText(G_GDL, G_FONT8, 74, y, STAGE_NAMES[i], 0xFF, 0xF0, 0x40, 0xFF);
        else    DrawText(G_GDL, G_FONT8, 74, y, STAGE_NAMES[i], 0xC0, 0xC0, 0xC0, 0xFF);
        y += 17;
    }
    DrawText(G_GDL, G_FONT8, 30, 214, "UP DN MOVE   A OK   B BACK", 0xA0, 0xA0, 0xA0, 0xFF);
}

// --- 4. Navigate + draw our screen (after the host menu frame). ---
RECOMP_HOOK_RETURN("Scene_Main") void tnt_native_screen(void) {
    if (G_CURRENT_SCENE != SCENE_MENU_HUB || s_state != ST_SHOWING) return;

    // Undo any nav/back-transition the leaked input made the host do this frame (input is
    // consumed inline by the host; we revert its effects here so Back can't back out of SINGLE
    // and Up/Down can't drift the host cursor).
    if (s_saved) freeze_host_state();

    unsigned int edge = s_frameacc & ~s_prev;
    s_prev = s_frameacc;
    if (s_cooldown > 0) { s_cooldown--; edge = 0; }

    if (edge & BTN_DOWN)      s_cursor = (s_cursor + 1) % N_STAGES;
    else if (edge & BTN_UP)   s_cursor = (s_cursor + N_STAGES - 1) % N_STAGES;
    else if (edge & BTN_A) {                 // pick this stage, start the game in it
        s_chosen = s_cursor;
        G_THEME_INDEX  = (unsigned char)s_cursor;   // real environment selector
        G_CURRENT_SONG = (unsigned char)s_cursor;   // music (best-effort)
        restore_foreground(SCENE_CTX_TABLE_PTR);     // put SINGLE back (it fades out on launch)
        s_state = ST_DONE;
        G_LOAD_FLAG = 1;                     // re-arm; next MenuHub tick launches
        return;
    } else if (edge & BTN_B) {               // back: restore SINGLE exactly, stay on it
        restore_foreground(SCENE_CTX_TABLE_PTR);
        s_state = ST_IDLE;                   // latch stays 0 -> no launch
        return;
    }
    draw_screen();
}

// --- 5. At launch: stick the chosen theme past MenuHub's randomize; reset. ---
RECOMP_HOOK("Game_Init") void tnt_native_reset(void) {
    if (s_chosen >= 0) {
        G_THEME_INDEX  = (unsigned char)s_chosen;
        G_CURRENT_SONG = (unsigned char)s_chosen;
    }
    s_chosen = -1;
    s_state = ST_IDLE;
    s_saved = 0;
}

#include "modding.h"
#include "recompui.h"

// recompui-demo: the first mod to build a REAL recompui screen in TheNewT64ris.
//
// This is the reference for the "new screen" framework. Unlike the stage-select overlay (which
// draws over the live SINGLE menu and can't fully suppress its input), a recompui context is a
// genuine UI layer: set_context_captures_input(1) makes the runtime route input to it and away
// from the game, so there is no leak. It renders via the app's UI stack (the same one the
// config/launcher menus use), supports flexbox layout, styled text/buttons, images, and click
// callbacks. Toggle it with Z on the main menu.

#define G_CURRENT_SCENE (*(volatile unsigned char *)0x800CFEE8) // g_currentScene (4 = menu hub)
#define G_BUTTONS       (*(volatile unsigned int  *)0x8011EF54) // g_buttonsPressed (edge mask)
#define SCENE_MENU_HUB 4
#define BTN_Z 0x2000u

static RecompuiContext s_ctx;
static RecompuiResource s_status;      // the live "Clicks: N" label
static int s_built = 0;
static int s_shown = 0;
static int s_count = 0;
static int s_autoshown = 0;             // one-shot: pop the panel on first menu entry
static unsigned int s_prev = 0;        // previous button mask (edge detect for the toggle)

static void show_panel(void) {
    recompui_set_context_captures_input(s_ctx, 1);  // steal input from the game menu
    recompui_show_context(s_ctx);
    s_shown = 1;
}

// Tiny libc-free "Clicks: <n>" formatter (mods link -nostdlib).
static void update_status(void) {
    char buf[24];
    const char *pre = "Clicks: ";
    int i = 0;
    while (pre[i]) { buf[i] = pre[i]; i++; }
    char tmp[12];
    int n = s_count, j = 0;
    if (n == 0) tmp[j++] = '0';
    while (n > 0) { tmp[j++] = (char)('0' + (n % 10)); n /= 10; }
    while (j > 0) buf[i++] = tmp[--j];
    buf[i] = 0;
    recompui_set_text(s_status, buf);
}

static void on_count(RecompuiResource res, RecompuiEventData *e, void *ud) {
    (void)res; (void)ud;
    if (e->type != UI_EVENT_CLICK) return;
    s_count++;
    update_status();
}

static void on_close(RecompuiResource res, RecompuiEventData *e, void *ud) {
    (void)res; (void)ud;
    if (e->type != UI_EVENT_CLICK) return;
    recompui_hide_context(s_ctx);
    s_shown = 0;
}

static void build_ui(void) {
    s_ctx = recompui_create_context();
    recompui_open_context(s_ctx);

    // Root fills the screen and centers our panel.
    RecompuiResource root = recompui_context_root(s_ctx);
    recompui_set_display(root, RECOMPUI_DISPLAY_FLEX);
    recompui_set_justify_content(root, RECOMPUI_JUSTIFY_CENTER);
    recompui_set_align_items(root, RECOMPUI_ALIGN_CENTER);
    recompui_set_width(root, 100.0f, RECOMPUI_UNIT_PERCENT);
    recompui_set_height(root, 100.0f, RECOMPUI_UNIT_PERCENT);

    // The panel: a column of title / status / buttons.
    RecompuiResource panel = recompui_create_element(s_ctx, root);
    recompui_set_display(panel, RECOMPUI_DISPLAY_FLEX);
    recompui_set_flex_direction(panel, RECOMPUI_FLEX_COLUMN);
    recompui_set_align_items(panel, RECOMPUI_ALIGN_CENTER);
    recompui_set_gap(panel, 16.0f, RECOMPUI_UNIT_DP);
    recompui_set_padding(panel, 32.0f, RECOMPUI_UNIT_DP);
    recompui_set_border_radius(panel, 12.0f, RECOMPUI_UNIT_DP);
    recompui_set_border_width(panel, 2.0f, RECOMPUI_UNIT_DP);
    RecompuiColor bg = RECOMPUI_RGBA(20, 24, 40, 235);
    recompui_set_background_color(panel, &bg);
    RecompuiColor border = RECOMPUI_RGBA(120, 160, 255, 255);
    recompui_set_border_color(panel, &border);

    RecompuiResource title = recompui_create_label(s_ctx, panel, "RECOMPUI MOD DEMO", RECOMPUI_LABEL_LARGE);
    RecompuiColor gold = RECOMPUI_RGBA(255, 240, 120, 255);
    recompui_set_color(title, &gold);

    s_status = recompui_create_label(s_ctx, panel, "Clicks: 0", RECOMPUI_LABEL_NORMAL);

    RecompuiResource b_count = recompui_create_button(s_ctx, panel, "COUNT +1", RECOMPUI_BUTTON_PRIMARY);
    recompui_register_callback(b_count, on_count, 0);
    RecompuiResource b_close = recompui_create_button(s_ctx, panel, "CLOSE", RECOMPUI_BUTTON_DANGER);
    recompui_register_callback(b_close, on_close, 0);

    recompui_close_context(s_ctx);
    s_built = 1;
}

// Scene_Update runs every frame (it's the scene dispatcher). Build the UI lazily on the first
// frame, pump queued click callbacks, and toggle the panel with Z while on the menu hub.
RECOMP_HOOK("Scene_Update") void tnt_demo_tick(void) {
    if (!s_built) build_ui();
    recomp_run_ui_callbacks();

    // One-shot: show the panel the first time we land on the menu hub (discoverability +
    // lets an automated test screenshot it without a special injected button).
    if (!s_autoshown && G_CURRENT_SCENE == SCENE_MENU_HUB) {
        s_autoshown = 1;
        show_panel();
    }

    unsigned int edge = G_BUTTONS & ~s_prev;
    s_prev = G_BUTTONS;

    if ((edge & BTN_Z) && G_CURRENT_SCENE == SCENE_MENU_HUB) {
        if (s_shown) {
            recompui_hide_context(s_ctx);
            s_shown = 0;
        } else {
            show_panel();
        }
    }
}

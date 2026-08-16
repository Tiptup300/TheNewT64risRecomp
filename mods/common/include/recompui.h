#ifndef __RECOMPUI_H__
#define __RECOMPUI_H__

// Mod-facing recompui API for TheNewT64risRecomp.
//
// This declares the runtime's recompui_* guest exports so a mod can build a REAL UI screen
// (element tree, flexbox layout, styled text/buttons, images, input capture, callbacks) --
// the same UI system the app's own launcher/config menus use, and the one Zelda64Recomp mods
// use. Include ONLY this + modding.h. Do NOT include recomputils.h (its recomp_printf import
// is not registered and will make the mod fail to load).
//
// ENABLEMENT: these exports only exist because src/main.cpp calls recompui::register_ui_exports()
// (and registers recomp_run_ui_callbacks) at startup. Stock N64ModernRuntime does neither, so this
// header only works against this project's patched app. If you see "Imported function not found"
// at load, the app wasn't built with that wiring.
//
// USAGE (typical): build the screen ONCE (e.g. lazily on first open), then show/hide it and pump
// callbacks each frame from a per-frame game hook:
//
//   #include "modding.h"
//   #include "recompui.h"
//   static unsigned int ctx, built;
//   static void build(void){ ctx=recompui_create_context(); recompui_open_context(ctx);
//       unsigned int root=recompui_context_root(ctx); ... recompui_close_context(ctx); built=1; }
//   RECOMP_HOOK("Scene_Update") void tick(void){
//       if(!built) build();
//       recomp_run_ui_callbacks();          // dispatch queued clicks to our handlers
//       /* show/hide ctx based on game state / input */
//   }
//
// The colour setters take a POINTER to a 4-byte RGBA (the runtime reads r,g,b,a bytes).

#include "modding.h"

typedef unsigned int RecompuiContext;    // opaque context id
typedef unsigned int RecompuiResource;   // opaque element/style id

typedef struct { unsigned char r, g, b, a; } RecompuiColor;
#define RECOMPUI_RGBA(R,G,B,A) ((RecompuiColor){ (unsigned char)(R),(unsigned char)(G),(unsigned char)(B),(unsigned char)(A) })

// --- enums (values match recompui/src/elements/ui_types.h; keep in sync) ---
typedef enum { RECOMPUI_BUTTON_PRIMARY, RECOMPUI_BUTTON_SECONDARY, RECOMPUI_BUTTON_TERTIARY,
               RECOMPUI_BUTTON_SUCCESS, RECOMPUI_BUTTON_WARNING, RECOMPUI_BUTTON_DANGER } RecompuiButtonStyle;
typedef enum { RECOMPUI_LABEL_ANNOTATION, RECOMPUI_LABEL_SMALL, RECOMPUI_LABEL_NORMAL,
               RECOMPUI_LABEL_LARGE } RecompuiLabelStyle;
typedef enum { RECOMPUI_DISPLAY_NONE, RECOMPUI_DISPLAY_BLOCK, RECOMPUI_DISPLAY_INLINE,
               RECOMPUI_DISPLAY_INLINE_BLOCK, RECOMPUI_DISPLAY_FLOW_ROOT, RECOMPUI_DISPLAY_FLEX } RecompuiDisplay;
typedef enum { RECOMPUI_FLEX_ROW, RECOMPUI_FLEX_COLUMN, RECOMPUI_FLEX_ROW_REVERSE,
               RECOMPUI_FLEX_COLUMN_REVERSE } RecompuiFlexDirection;
typedef enum { RECOMPUI_JUSTIFY_FLEX_START, RECOMPUI_JUSTIFY_FLEX_END, RECOMPUI_JUSTIFY_CENTER,
               RECOMPUI_JUSTIFY_SPACE_BETWEEN, RECOMPUI_JUSTIFY_SPACE_AROUND,
               RECOMPUI_JUSTIFY_SPACE_EVENLY } RecompuiJustifyContent;
typedef enum { RECOMPUI_ALIGN_FLEX_START, RECOMPUI_ALIGN_FLEX_END, RECOMPUI_ALIGN_CENTER,
               RECOMPUI_ALIGN_BASELINE, RECOMPUI_ALIGN_STRETCH } RecompuiAlignItems;
typedef enum { RECOMPUI_UNIT_PX, RECOMPUI_UNIT_DP, RECOMPUI_UNIT_PERCENT } RecompuiUnit;
typedef enum { RECOMPUI_POSITION_ABSOLUTE, RECOMPUI_POSITION_RELATIVE } RecompuiPosition;
typedef enum { RECOMPUI_NAV_UP, RECOMPUI_NAV_RIGHT, RECOMPUI_NAV_DOWN, RECOMPUI_NAV_LEFT } RecompuiNavDirection;

// --- event structs (must match recompui/include/recompui/event_structs.h) ---
typedef enum {
    UI_EVENT_NONE, UI_EVENT_CLICK, UI_EVENT_FOCUS, UI_EVENT_HOVER, UI_EVENT_ENABLE,
    UI_EVENT_DRAG, UI_EVENT_RESERVED1, UI_EVENT_UPDATE, UI_EVENT_NAVIGATE,
    UI_EVENT_MOUSE_BUTTON, UI_EVENT_MENU_ACTION, UI_EVENT_COUNT
} RecompuiEventType;
typedef enum { UI_DRAG_NONE, UI_DRAG_START, UI_DRAG_MOVE, UI_DRAG_END } RecompuiDragPhase;
typedef enum { UI_MENU_ACTION_NONE, UI_MENU_ACTION_ACCEPT, UI_MENU_ACTION_APPLY,
               UI_MENU_ACTION_BACK, UI_MENU_ACTION_TOGGLE, UI_MENU_ACTION_TAB_LEFT,
               UI_MENU_ACTION_TAB_RIGHT } RecompuiMenuAction;
typedef struct {
    RecompuiEventType type;
    union {
        struct { float x, y; } click;
        struct { unsigned char active; } focus;
        struct { unsigned char active; } hover;
        struct { unsigned char active; } enable;
        struct { float x, y; RecompuiDragPhase phase; } drag;
        struct { RecompuiMenuAction action; } menu_action;
    } data;
} RecompuiEventData;

typedef void (*RecompuiCallback)(RecompuiResource resource, RecompuiEventData* event, void* userdata);

// --- context lifecycle ---
RECOMP_IMPORT("*", RecompuiContext recompui_create_context(void))
RECOMP_IMPORT("*", void recompui_open_context(RecompuiContext ctx))
RECOMP_IMPORT("*", void recompui_close_context(RecompuiContext ctx))
RECOMP_IMPORT("*", RecompuiResource recompui_context_root(RecompuiContext ctx))
RECOMP_IMPORT("*", void recompui_show_context(RecompuiContext ctx))
RECOMP_IMPORT("*", void recompui_hide_context(RecompuiContext ctx))
RECOMP_IMPORT("*", void recompui_set_context_captures_input(RecompuiContext ctx, int captures))
RECOMP_IMPORT("*", void recompui_set_context_captures_mouse(RecompuiContext ctx, int captures))

// --- element creation (return a resource id) ---
RECOMP_IMPORT("*", RecompuiResource recompui_create_element(RecompuiContext ctx, RecompuiResource parent))
RECOMP_IMPORT("*", RecompuiResource recompui_create_button(RecompuiContext ctx, RecompuiResource parent, const char* text, RecompuiButtonStyle style))
RECOMP_IMPORT("*", RecompuiResource recompui_create_label(RecompuiContext ctx, RecompuiResource parent, const char* text, RecompuiLabelStyle style))
RECOMP_IMPORT("*", void recompui_destroy_element(RecompuiContext ctx, RecompuiResource resource))

// --- layout / style setters (operate on a resource) ---
RECOMP_IMPORT("*", void recompui_set_display(RecompuiResource res, RecompuiDisplay display))
RECOMP_IMPORT("*", void recompui_set_flex_direction(RecompuiResource res, RecompuiFlexDirection dir))
RECOMP_IMPORT("*", void recompui_set_justify_content(RecompuiResource res, RecompuiJustifyContent jc))
RECOMP_IMPORT("*", void recompui_set_align_items(RecompuiResource res, RecompuiAlignItems ai))
RECOMP_IMPORT("*", void recompui_set_width(RecompuiResource res, float v, RecompuiUnit unit))
RECOMP_IMPORT("*", void recompui_set_height(RecompuiResource res, float v, RecompuiUnit unit))
RECOMP_IMPORT("*", void recompui_set_min_width(RecompuiResource res, float v, RecompuiUnit unit))
RECOMP_IMPORT("*", void recompui_set_width_auto(RecompuiResource res))
RECOMP_IMPORT("*", void recompui_set_height_auto(RecompuiResource res))
RECOMP_IMPORT("*", void recompui_set_padding(RecompuiResource res, float v, RecompuiUnit unit))
RECOMP_IMPORT("*", void recompui_set_margin(RecompuiResource res, float v, RecompuiUnit unit))
RECOMP_IMPORT("*", void recompui_set_margin_auto(RecompuiResource res))
RECOMP_IMPORT("*", void recompui_set_gap(RecompuiResource res, float v, RecompuiUnit unit))
RECOMP_IMPORT("*", void recompui_set_border_width(RecompuiResource res, float v, RecompuiUnit unit))
RECOMP_IMPORT("*", void recompui_set_border_radius(RecompuiResource res, float v, RecompuiUnit unit))
RECOMP_IMPORT("*", void recompui_set_background_color(RecompuiResource res, const RecompuiColor* color))
RECOMP_IMPORT("*", void recompui_set_border_color(RecompuiResource res, const RecompuiColor* color))
RECOMP_IMPORT("*", void recompui_set_color(RecompuiResource res, const RecompuiColor* color))
RECOMP_IMPORT("*", void recompui_set_font_size(RecompuiResource res, float v, RecompuiUnit unit))
RECOMP_IMPORT("*", void recompui_set_text(RecompuiResource res, const char* text))
RECOMP_IMPORT("*", void recompui_set_opacity(RecompuiResource res, float opacity))
RECOMP_IMPORT("*", void recompui_set_nav_auto(RecompuiResource res, RecompuiNavDirection dir))

// --- callbacks ---
// Register a handler for an element's events (click/focus/etc). The handler runs in guest
// context when recomp_run_ui_callbacks() is pumped. `userdata` is passed back verbatim.
RECOMP_IMPORT("*", void recompui_register_callback(RecompuiResource res, RecompuiCallback callback, void* userdata))
// Pump queued UI callbacks -> invoke registered handlers. Call once per frame (from a hook).
RECOMP_IMPORT("*", void recomp_run_ui_callbacks(void))

#endif // __RECOMPUI_H__

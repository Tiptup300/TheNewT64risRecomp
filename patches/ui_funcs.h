#ifndef __UI_FUNCS_H__
#define __UI_FUNCS_H__

// Game-provided UI function declarations, force-included by RecompFrontend's
// recompui (src/api/ui_api_events.cpp). It must expose the recompui C-API event
// types (RecompuiEventData/Type/DragPhase). The New T64ris has no custom UI patch
// functions yet, so we only pull in those types.
#include "recompui/event_structs.h"

#endif

# Front-end menu — OBSERVED GROUND TRUTH (user-verified, live play)

> This file is the **authoritative behavioral record** of the front-end, captured by
> the user driving the real game on 2026-08-08. It is intentionally kept as raw
> observation (what the screens do), separate from the code mapping in
> `MENU_TREE.md` (which binds these behaviors to functions/globals). When code RE and
> this file disagree, **this file wins** — it is ground truth; fix the code mapping.
>
> Screenshots backing every claim below are in the user's image set (main menu,
> SINGLE with GUEST, SINGLE with NEW NAME, SINGLE after a user is chosen).

## MAIN MENU  (title bar: "MENU")

Four items, top to bottom:

1. **ONE PLAYER**
2. **MULTI PLAYER** — *greyed / not selectable* unless **more controllers are
   plugged in**. With a single controller it is skipped by the cursor.
3. **WONDERS**
4. **OPTIONS**

Controls: **Up / Down** move the highlight, **Accept (A)** enters the highlighted item.

## ONE PLAYER  →  "SINGLE" screen

Header reads **SINGLE**. The screen is a small form. On entry the cursor is on the
**NAME** row.

### NAME row — a profile dropdown
- Shows the currently-selected profile, e.g. **GUEST**, in a red-outlined dropdown box
  with an up/down arrow glyph.
- **Up / Down** cycles through the list of saved users.
  - **GUEST** is always present and **cannot be deleted** (the default profile).
  - **NEW NAME** is **always present** as a list entry (in addition to any saved
    users). Selecting it starts name entry (below).
- **Accept (A)** = accept the currently-selected user and move focus into the form
  (OPPONENT / GAME / START become selectable).
- **Back (B)** = return to the MAIN MENU.

### NEW NAME  →  name-entry keyboard
Selecting **NEW NAME** and accepting shows an **on-screen keyboard / character grid**:
- **Up / Down / Left / Right** move the keyboard-position highlight.
- **Accept (A)** = add the currently-highlighted character to the name.
- **Back (B)** = cancel adding a new user (return to the NAME dropdown).
- The keyboard includes a **BACKSPACE** key and an **OK** key (OK commits the name).

### After a user is selected — the form rows
Once a name is accepted, the NAME row shows the chosen user (screenshot shows a short
name plus a small **save-block icon with a "1"** — the controller-pak/save indicator),
and the cursor can move with **Up / Down** between three rows:

- **OPPONENT:** — value row. **Left / Right** cycles the value: **OFF → EASY →
  MEDIUM → …** (AI opponent difficulty; OFF = no opponent).
- **GAME:** — value row. **Left / Right** cycles the mode: **MARATHON → SPRINT →
  ULTRA → …**
- **START** — **Accept (A)** here launches the game with the chosen settings.

**Back (B)** from the form cancels back to the player (NAME) select.

On-screen prompt legend on this screen: **"Ⓐ ACCEPT   Ⓑ BACK"**.

## MULTI PLAYER  →  "MULTI" screen
Requires ≥2 controllers to be selectable. (Two profile dropdowns + GAME + GARBAGE
rows — see `MENU_TREE.md`.)

## Notes / open items
- **Name entry is reachable in normal play** via ONE PLAYER → SINGLE → NAME → NEW
  NAME. It does **not** require a physical/emulated Controller-Pak to *reach the
  keyboard* (earlier code-only analysis wrongly concluded it was pak-gated —
  corrected here). Whether *committing/saving* a new profile needs a pak is a
  separate question to verify.
- **Mods menu instability (2026-08-08):** opening the in-app **Mods** menu (the
  RmlUi/recompui front-end menu) wedged the app — required killing the task several
  times. **Root cause identified from the log:** the final line before the wedge is
  `vkGetQueryPoolResults failed with error code 0x1` with **no segfault/abort and
  audio still advancing** — i.e. the render thread hung on a Vulkan GPU query that
  **Dozen** (the D3D12-on-Vulkan translation layer used under WSL2, which logs
  "dzn is not a conformant Vulkan implementation") could not satisfy. This is a
  **WSLg/Dozen rendering hang, not a fault in the recompiled game code or the mods**
  — it matches the documented WSLg/Dozen instability gotcha. It would not occur on a
  conformant native Vulkan driver. Nothing to fix in game code; tracked as an
  environment limitation.

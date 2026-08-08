# TODO: State-snapshot annotator ("freeze + annotate a single moment")

**Status:** proposed / not started
**Rough size:** MVP ≈ ½–1 day (≈80% reuses existing infra); stretch goal = multi-day
**Owner:** —

## Goal

Press a special key → the game **locks up at the current state** (freezes, keeps the
last frame on screen) → then **add annotations with screen positions** and a freeform
**write-up**, producing a **single point-in-time record** (like a trace log, but one
frozen moment instead of a stream). For inspecting/documenting exactly what's on
screen + what's in RAM at an interesting instant, and for building durable RE notes.

## The three capabilities (and how much already exists)

| # | Capability | What it needs | Status |
|---|---|---|---|
| 1 | **Freeze on a hotkey** | a `g_frozen` flag; in `update_gfx`, when set, stop stepping the game (block at the frame boundary, `select()`-paced so it's SIGSTKFLT-safe) while SDL keeps the window alive presenting the last frame. Toggle via a dedicated scancode in the input path. | ~40 LOC in `src/main.cpp`; **hook already exists** (`update_gfx` @ main.cpp:214, `poll_inputs` patch) |
| 2 | **Capture the single state** | on the freeze *edge*: dump RDRAM (reuse `tnt_state_region`) + decode the named watch-globals to JSON (reuse harness `DEFAULT_WATCHES`) + trigger a `winburst.ps1` screenshot → one numbered snapshot folder | ~60 LOC; **~90% reuse** (state bridge + `g_state_rdram` already stashed) |
| 3 | **Annotate with positions + write-up** | load a snapshot (PNG + RAM + globals), click the frame to drop positioned markers, type notes per marker, add freeform text → save annotated JSON + marked-up PNG + a markdown report | **New** ~200-LOC Python tool |

## Existing infrastructure this builds on (verified 2026-08-08)

- `src/main.cpp:214` `update_gfx()` runs every frame and **already** calls the E2E
  state bridge (`tnt_state_poke` / `tnt_state_dump` / `tnt_state_region`). This is the
  freeze + snapshot hook.
- `g_state_rdram` (main.cpp) is the stashed guest RDRAM base — snapshotting reads
  straight from it.
- `tnt_state_region()` already dumps an arbitrary `0xADDR LEN` RAM range to
  `<TNT_STATE_OUT>.region`. Reusable verbatim for the RAM dump.
- Input interception exists (`recompinput::poll_inputs`, TNT_INPUT patch) — the freeze
  hotkey slots in here.
- `tools/e2e/harness.py` `DEFAULT_WATCHES` = the named-global address/width map;
  reuse it to decode the snapshot's globals into readable name→value JSON.
- `winburst.ps1` (Windows side) is the working WSL2 window-capture path for the PNG.

## The one genuine wrinkle: the screenshot

The modern renderer translates GBI → host GPU, so **there is no plain RDRAM
framebuffer to dump as a PNG** (RT64-style translation; the native game may not keep a
full color image in RDRAM). Therefore the **visual** capture stays **host-side**
(`winburst.ps1`), not self-contained in-process. The RAM/globals capture *is*
self-contained.

## Recommended architecture

**Freeze at the frame boundary, annotate host-side after the fact.**

1. **In-app (C++, `src/main.cpp`)** — inert unless enabled (env `TNT_SNAPSHOT_DIR`),
   matching the existing opt-in-by-env pattern:
   - Dedicated freeze scancode detected in the input path toggles `g_frozen`.
   - In `update_gfx`: `while (g_frozen) { pump SDL events; present last frame; select()-sleep }`
     so the game halts deterministically at a poll boundary and the window stays live.
   - On the freeze edge, write snapshot `NNN/`: `ram.region` (RDRAM dump via existing
     `tnt_state_region` logic) + `globals.json` (decoded watch-list) + a `meta.json`
     (frame counter, scene, timestamp passed in) + fire the screenshot.
2. **Host-side annotator (`tools/snapshot/annotate.py`, NEW)**:
   - Load snapshot `NNN/` (PNG + `ram.region` + `globals.json`).
   - Show the frame; **click to drop positioned markers**; per-marker text notes;
     a freeform write-up box; decoded RAM values shown side-by-side.
   - Save: `annotations.json` (markers w/ x,y + notes), `annotated.png`
     (frame + markers), `report.md` (the written-up single-state record).
   - Can reopen a snapshot later and **diff** two snapshots' globals.

### Why host-side annotation (design fork — decided)

- **Host-side Python viewer (CHOSEN):** annotation happens after freeze, on the dumped
  frame. Gives click-to-place markers, per-marker notes, decoded RAM side-by-side, and
  reopen/diff. **Sidesteps WSL2 entirely** — no Wayland mouse quirks and, critically,
  **no Dozen/Vulkan overlay** (the same overlay path that wedges the in-app Mods menu:
  `vkGetQueryPoolResults` hang). ~½–1 day.
- **In-app overlay (REJECTED for now):** render crosshair/notes on the frozen frame
  via recompui/RmlUi. Nicer "live" feel but rides the exact Dozen path that hangs under
  WSL2 + Wayland mouse issues. Higher risk, ~2–3 days, fragile on this setup.

**Sub-choice still open:** annotator UI = **Tk desktop window** (zero-setup if
python3-tk present) vs **tiny self-contained local web page** (nicer, portable HTML).

## File / change plan

- `src/main.cpp` — `g_frozen` + freeze loop in `update_gfx`; freeze-edge snapshot
  writer; env `TNT_SNAPSHOT_DIR` (+ optional `TNT_SNAPSHOT_KEY`). Inert by default.
- `tools/snapshot/annotate.py` — the host-side annotator (NEW).
- `tools/snapshot/README.md` — usage.
- (reuse) `tools/e2e/harness.py:DEFAULT_WATCHES` for global decoding — factor the map
  into a small shared module if cleaner.
- CLAUDE.md — document the freeze/snapshot channel next to the E2E harness section.

## MVP acceptance

1. Launch with `TNT_SNAPSHOT_DIR=…`; play to any screen; press the freeze key.
2. Game visibly locks on the current frame; window stays responsive; press again to
   resume.
3. A numbered snapshot folder appears with PNG + RAM dump + decoded globals.
4. `annotate.py <snapshot>` opens the frame; can place ≥1 positioned marker with a
   note + a write-up; saves `report.md` + `annotated.png`.

## Stretch goals (later, not MVP)

- **Screen-position → game object/RAM struct:** click a spot → identify *what* is
  rendered there (reverse the display-list → object mapping). The expensive research
  part; layer on using already-mapped tables (`obj` slot buffer @0x80129200, scene
  menu-item structs, etc.).
- **Live RAM browser** in the frozen state (poke/watch arbitrary addresses).
- **Snapshot diff report** (two frozen moments → what changed in named globals).
- Fold the freeze channel into `tools/e2e/harness.py` so tests can freeze + assert.

## Risks / notes

- WSL2/Dozen: keep the freeze loop off the GPU-query path; present-last-frame only.
- Freezing the guest thread mid-instruction is unsafe — freeze **at the poll/frame
  boundary** only (state is quiescent there), same discipline as the E2E harness.
- Pace any in-freeze sleeps with `select()`, never Linux `sleep` (SIGSTKFLT / exit 144).

#!/usr/bin/env bash
# Reapplies our required fixes to the (gitignored, externally-cloned) deps under lib/.
# Run once after cloning the deps at the pinned commits (see README "Dependencies").
#
#   N64ModernRuntime-0001-controller-status-swizzle    -> ultramodern/src/input.cpp
#       OSContStatus is written per-byte with the game's memory swizzle so the
#       controller-connected check reads the correct port. Without this the game
#       reports "NO CONTROLLER" (contstat array lands at a 2-mod-4 address).
#   N64ModernRuntime-0002-sdl2-audio-buffer-offset      -> ultramodern/src/audio.cpp
#       Use the SDL2 buffer_offset_frames value (1.0) instead of the Godot value
#       (0.5) so the game generates enough samples and the SDL queue does not
#       chronically underrun (periodic audio buzz/crackle).
#   RecompFrontend-0001-keyboard-mapping                -> recompinput/src/input_mapping.cpp
#       Default keyboard layout mapped to this game's controls (arrows -> D-pad, etc.).
#   N64ModernRuntime-0003-nonfatal-missing-function     -> librecomp/src/overlays.cpp
#       get_function() no longer assert/std::exit on an unresolved address; it logs
#       once and returns a no-op. Some libultra debug funcs (rmonPrintf) are omitted
#       from the func table, so an INDIRECT call to one used to crash the game
#       (e.g. an audio-error path on the gameplay screen). Now it degrades safely.
#       ALSO adds the indirect-call tracer (a naming aid): inert unless the
#       TNT_INDIRECT_TRACE env var names an output file, in which case every indirect
#       call logs its target vram + native call stack (nearest named ancestor) so
#       tools/tracemap.py can attribute jump-table-reached residue to a subsystem.
#   rt64-0001-crop-right-edge-garbage                   -> src/hle/rt64_vi.cpp
#       VI::cropRectangle() crops ~2px off the framebuffer's right edge. That column
#       is uninitialized on the N64 (a TV's overscan hid it); presenting the full
#       width showed it as flickering garbage every other frame.
#   RecompFrontend-0003-virtual-input                   -> recompinput/src/input_state.cpp
#       Debug virtual-input overlay: when the TNT_INPUT env var names a file, poll_inputs
#       uses the SDL scancodes listed in it as the SOLE key state each poll (the real
#       keyboard is IGNORED while TNT_INPUT is set, so tests get exclusive control and a
#       stray physical keypress can't corrupt a run). Lets a script drive menus/gameplay
#       headless — WSLg/Wayland forbids external synthetic key injection, so this in-app
#       channel is the only reliable path. Inert unless TNT_INPUT is set.
#       Scancodes: Start=40(RETURN), A=29(Z), B=27(X), D-pad=79-82(arrows).
#   RecompFrontend-0002-restart-button                  -> recompui/src/config/ui_config.cpp
#       Adds a "Restart" (Reset.svg) button to the config-menu header, shown only
#       while a game is running. Re-execs the app with TNT_NO_AUTOBOOT so it lands
#       at the launcher, where mods can be toggled (mods only toggle pre-game), then
#       the player can Start Game again. The runtime has no in-place return-to-menu.
set -euo pipefail
here="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
root="$(cd "$here/../.." && pwd)"

apply() { # <repo-subdir> <patch>
  local dir="$root/$1" patch="$here/$2"
  if git -C "$dir" apply --reverse --check "$patch" 2>/dev/null; then
    echo "already applied: $2"
  else
    git -C "$dir" apply "$patch" && echo "applied: $2"
  fi
}

apply lib/N64ModernRuntime N64ModernRuntime-0001-controller-status-swizzle.patch
apply lib/N64ModernRuntime N64ModernRuntime-0002-sdl2-audio-buffer-offset.patch
apply lib/N64ModernRuntime N64ModernRuntime-0003-nonfatal-missing-function.patch
apply lib/RecompFrontend   RecompFrontend-0001-keyboard-mapping.patch
apply lib/RecompFrontend   RecompFrontend-0002-restart-button.patch
apply lib/RecompFrontend   RecompFrontend-0003-virtual-input.patch
apply lib/rt64             rt64-0001-crop-right-edge-garbage.patch
echo "done."

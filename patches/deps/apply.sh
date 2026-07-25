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
#   rt64-0001-crop-right-edge-garbage                   -> src/hle/rt64_vi.cpp
#       VI::cropRectangle() crops ~2px off the framebuffer's right edge. That column
#       is uninitialized on the N64 (a TV's overscan hid it); presenting the full
#       width showed it as flickering garbage every other frame.
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
apply lib/rt64             rt64-0001-crop-right-edge-garbage.patch
echo "done."

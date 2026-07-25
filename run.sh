#!/usr/bin/env bash
#
# Run The New Tiptris : Recompiled.
#
#   ./run.sh                 # launch (auto-boots if a ROM is already stored)
#   ./run.sh --rom PATH      # point at a ROM (first run, or to switch ROMs)
#   ./run.sh --menu          # start at the launcher (to enable/disable mods)
#   TNT_NO_AUTOBOOT=1 ./run.sh   # force the launcher instead of auto-booting
#
# Any extra args are passed through to the executable.
#
set -euo pipefail
here="$(cd "$(dirname "$0")" && pwd)"   # POSIX-safe (works with sh and bash)
cd "$here"

bin="build-cmake/TntRecompiled"
if [ ! -x "$bin" ]; then
    echo "error: $bin not built. Build it with:" >&2
    echo "  cmake -S . -B build-cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -G Ninja -DCMAKE_BUILD_TYPE=Release" >&2
    echo "  cmake --build build-cmake -j" >&2
    exit 1
fi

# --menu -> start at the launcher (don't auto-boot) so mods can be enabled/disabled
if [ "${1:-}" = "--menu" ]; then
    export TNT_NO_AUTOBOOT=1
    shift
fi

# --rom PATH -> TNT_ROM (dev/auto-boot path that validates + stores the ROM)
if [ "${1:-}" = "--rom" ] && [ -n "${2:-}" ]; then
    export TNT_ROM="$2"
    shift 2
fi

# WSL2: use the extracted Mesa "Dozen" (Vulkan-on-D3D12) driver if it's present,
# so RT64 gets the real GPU instead of the slow llvmpipe software rasterizer.
# On a native Linux desktop with a normal Vulkan driver, this file won't exist
# and the system ICD is used.
if [ -f "dzn/dzn_icd.json" ]; then
    export VK_ICD_FILENAMES="$here/dzn/dzn_icd.json"
fi

exec "$bin" "$@"

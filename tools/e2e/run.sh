#!/usr/bin/env bash
# Run the E2E test suite (each test launches the headless game and drives it).
# Usage: tools/e2e/run.sh [test_name ...]   (default: all test_*.py)
#
# Requires: build-cmake/TntRecompiled built, a ROM installed, and a working WSLg
# display. Audio is forced to SDL 'dummy' by the harness so a flaky PulseAudio can't
# block boot. Repeated GPU crashes can wedge WSLg for the session — if launches start
# failing instantly, `wsl --shutdown` (Windows) + relaunch clears it.
set -uo pipefail
here="$(cd "$(dirname "$0")" && pwd)"
cd "$here"

# make sure nothing is already holding the window/GPU
ps aux | grep '[b]uild-cmake/TntRecompiled' | awk '{print $2}' | xargs -r kill -9 2>/dev/null

tests=("$@")
if [ ${#tests[@]} -eq 0 ]; then
    mapfile -t tests < <(ls test_*.py | sed 's/\.py$//')
fi

pass=0; fail=0; failed=()
for t in "${tests[@]}"; do
    f="${t%.py}.py"; [ "${f#test_}" = "$f" ] && f="test_${f}"
    echo "======================================================================"
    echo "RUN  $f"
    echo "----------------------------------------------------------------------"
    if python3 "$f"; then
        echo "---> PASS $f"; pass=$((pass+1))
    else
        echo "---> FAIL $f"; fail=$((fail+1)); failed+=("$f")
    fi
    ps aux | grep '[b]uild-cmake/TntRecompiled' | awk '{print $2}' | xargs -r kill -9 2>/dev/null
done

echo "======================================================================"
echo "E2E: $pass passed, $fail failed"
[ $fail -gt 0 ] && printf '  failed: %s\n' "${failed[@]}"
exit $fail

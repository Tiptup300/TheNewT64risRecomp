#!/usr/bin/env bash
# Headless test runner. Uses the project's pytest venv (.venv-test) so no system
# Python packages are needed. Any args are passed through to pytest, e.g.:
#   tests/run.sh                       # whole suite
#   tests/run.sh tests/test_menu.py    # one file
#   tests/run.sh -k gameplay -x        # filter + stop on first failure
set -euo pipefail
cd "$(dirname "$0")/.."

VENV="./.venv-test"
if [ ! -x "$VENV/bin/python" ]; then
    echo "test venv missing — creating $VENV and installing pytest..." >&2
    python3 -m venv "$VENV"
    "$VENV/bin/pip" install --quiet --upgrade pip
    "$VENV/bin/pip" install --quiet pytest
fi

exec "$VENV/bin/python" -m pytest "$@"

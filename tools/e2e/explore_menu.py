#!/usr/bin/env python3
"""Empirically map the menu: reach the menu hub, then find which global each input
moves via baseline-subtracted RAM diff (filters per-frame animation noise).

Run:  python3 tools/e2e/explore_menu.py
Prints, for each input (DOWN/UP/START/B), the words that changed *because of* the
input (not the continuous animations), annotated with known datasym names.
"""
import re
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep

REPO = Path(__file__).resolve().parent.parent.parent
REGION = (0x800CE000, 0x51000)  # covers scene/menu-hub/options/config bss


def load_names():
    names = {}
    for line in (REPO / "tnt.datasyms.toml").read_text().splitlines():
        m = re.search(r'name = "([^"]+)", vram = (0x[0-9A-Fa-f]+)', line)
        if m and not m.group(1).startswith("D_"):
            names[int(m.group(2), 16)] = m.group(1)
    return names


def nearest(names, addr):
    """Return 'name(+off)' for the named datasym at or just below addr."""
    best = None
    for a in names:
        if a <= addr and (best is None or a > best):
            best = a
    if best is None or addr - best > 0x40:
        return "?"
    return names[best] + (f"+0x{addr-best:X}" if addr != best else "")


def main():
    names = load_names()
    with Game(region=REGION) as g:
        g.wait_alive(timeout=40)
        g.wait_for("scene", lambda v: v == 3, timeout=40, desc="attract")
        print("holding START to reach the menu hub...")
        g.press(Keys.START, hold=3.0)
        try:
            g.wait_for("scene", lambda v: v == 4, timeout=15, desc="menu hub (scene 4)")
        except TimeoutError:
            print(f"WARN: did not reach scene 4 (scene={g.read('scene')}); exploring anyway")
        _sleep(1.0)
        print(f"at scene={g.read('scene')} menuHubState={g.read('menu_hub_state') if 'menu_hub_state' in g.watches else '?'}")

        # Baseline: what changes with NO input (animations/timers) over the same window.
        base = g.find_changes(lambda: _sleep(0.4))
        base_addrs = {a for a, _, _ in base}
        print(f"baseline (per-frame noise): {len(base_addrs)} words change without input")

        for label, keys in [("DOWN", (Keys.DOWN,)), ("UP", (Keys.UP,)),
                            ("A", (Keys.A,)), ("B", (Keys.B,)), ("START", (Keys.START,))]:
            if g.crashed():
                print(f"\n(game exited before {label}; stopping)")
                break
            chg = g.find_changes(lambda k=keys: g.press(*k, hold=0.4))
            if g.crashed():
                print(f"\n== {label}: game CRASHED (code {g.proc.poll()}) — likely started "
                      f"a game/entered a scene that isn't set up. ==")
                break
            hits = [(a, o, n) for (a, o, n) in chg if a not in base_addrs]
            print(f"\n== {label}: {len(hits)} input-specific word change(s) "
                  f"(scene now {g.read('scene')}) ==")
            for a, o, n in sorted(hits)[:20]:
                print(f"   0x{a:08X} {o:>10} -> {n:<10}  [{nearest(names, a)}]")
            _sleep(0.6)
    print("\ndone.")
    return 0


if __name__ == "__main__":
    sys.exit(main())

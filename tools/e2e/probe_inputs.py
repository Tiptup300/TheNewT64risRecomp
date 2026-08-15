#!/usr/bin/env python3
"""Input -> state experimentation engine.

Drive the game to a named state, then tap each input and report which RAM addresses
it *reliably* moves. Two noise filters make this legible even with live animation:
  1. control noise floor: addresses that change on their own (no input) over many
     intervals are subtracted.
  2. reproducibility: an address is attributed to an input only if it moves on EVERY
     repeat of that input (one-off animation flicker is dropped).

Usage:
    python3 tools/e2e/probe_inputs.py <state> [--region logic|gameplay|full|0xB:LEN]
                                              [--repeat N] [--control N] [--mods a,b]
    python3 tools/e2e/probe_inputs.py --list

States come from e2e_helpers.STATES. Output: a printed table + JSON under /tmp/tnt_probe.
"""
import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep, DEFAULT_WATCHES
from e2e_helpers import INPUTS, STATES

# Named region presets. "logic" excludes the heavy matrix/3D animation bands
# (0x800E1xxx, 0x8012xxxx) so menu/scene LOGIC state stands out.
REGIONS = {
    "logic":    (0x800C0000, 0x00020000),   # 0x800C0000 .. 0x800E0000 (scene/menu state)
    "gameplay": (0x8011C000, 0x00009000),   # 0x8011C000 .. 0x80125000 (piece/board/input)
    "full":     (0x800C0000, 0x00090000),   # everything (noisy; matrices included)
}


def _named(addr):
    best = None
    for name, (a, w) in DEFAULT_WATCHES.items():
        if a == addr:
            return name
        if a < addr < a + 0x40 and (best is None or a > best[1]):
            best = (name, a)
    return f"{best[0]}+0x{addr-best[1]:X}" if best else ""


def _control_noise(g, samples, settle=0.4):
    """Union of addresses that change on their own (no input) over `samples` waits."""
    noise = set()
    for _ in range(samples):
        noise |= {c[0] for c in g.find_changes(lambda: _sleep(settle), settle=settle)}
    return noise


def probe(state, region, mods, repeat, control):
    reach, desc = STATES[state]
    report = {"state": state, "desc": desc, "region": [hex(region[0]), region[1]],
              "repeat": repeat, "inputs": {}}
    with Game(region=region, mods=mods) as g:
        reach(g)
        scene0 = g.read("scene")
        print(f"# state={state} ({desc}) scene={scene0} region={hex(region[0])}:{region[1]:#x}")
        noise = _control_noise(g, control)
        print(f"# control noise: {len(noise)} addrs over {control} samples (subtracted)\n")

        for name, sc in INPUTS.items():
            sets = []
            transitioned = False
            for _ in range(repeat):
                changed = {c[0]: (c[1], c[2]) for c in g.find_changes(lambda: g.tap(sc), settle=0.4)}
                sets.append(changed)
                if g.read("scene") != scene0:
                    transitioned = True
                    g.tap(Keys.B); _sleep(0.8)
                    if g.read("scene") != scene0:
                        try:
                            reach(g)
                        except Exception:
                            break
            if not sets:
                continue
            # reproducible movers = changed on EVERY repeat, minus the noise floor
            common = set(sets[0])
            for s in sets[1:]:
                common &= set(s)
            attributed = sorted(a for a in common if a not in noise)
            report["inputs"][name] = {
                "transitioned": transitioned,
                "changed": [{"addr": f"0x{a:08X}", "name": _named(a),
                             "old": sets[-1][a][0], "new": sets[-1][a][1]} for a in attributed],
            }
            tag = " (scene transition)" if transitioned else ""
            print(f"[{name}]{tag}  {len(attributed)} reliable addr(s)")
            for a in attributed[:14]:
                o, n = sets[-1][a]
                print(f"    0x{a:08X} {_named(a):<22} {o:#x} -> {n:#x}")
            if len(attributed) > 14:
                print(f"    ... +{len(attributed)-14} more")

    out = Path("/tmp/tnt_probe") / f"probe_{state}.json"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(report, indent=2))
    print(f"\n# report -> {out}")
    return report


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("state", nargs="?", help="one of: " + ", ".join(STATES))
    ap.add_argument("--region", default="logic", help="logic|gameplay|full|0xBASE:LEN")
    ap.add_argument("--repeat", type=int, default=2, help="taps per input (intersect); default 2")
    ap.add_argument("--control", type=int, default=6, help="no-input noise samples; default 6")
    ap.add_argument("--mods", help="comma-separated mod dirs to enable")
    ap.add_argument("--list", action="store_true")
    args = ap.parse_args()
    if args.list or not args.state:
        for k, (_, d) in STATES.items():
            print(f"  {k:<10} {d}")
        return 0
    if args.region in REGIONS:
        region = REGIONS[args.region]
    else:
        b, _, l = args.region.partition(":")
        region = (int(b, 16), int(l, 0))
    mods = args.mods.split(",") if args.mods else None
    probe(args.state, region, mods, args.repeat, args.control)
    return 0


if __name__ == "__main__":
    sys.exit(main())

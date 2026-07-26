#!/usr/bin/env python3
"""Analyze an indirect-call trace (from the TNT_INDIRECT_TRACE runtime tracer) to
surface naming evidence for jump-table-reached residue functions.

The trace file has lines `0xTARGETVRAM<TAB>callerName` — one per unique dynamic
indirect-call edge. This maps each target vram to its symbol name (via tnt.syms.toml)
and reports, for the PLACEHOLDER targets, their dynamic callers (which the static call
graph could not see). A placeholder target with a NAMED caller is now nameable.

Usage:
    tools/tracemap.py <tracefile>            # placeholder targets + their callers
    tools/tracemap.py <tracefile> --all      # every traced target
"""

import argparse
import re
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SYMS = ROOT / "tnt.syms.toml"
PLACEHOLDER = re.compile(r"[89A-Fa-f][0-9A-Fa-f]{7}|^func_|^FUN_|^D_")


def load_syms():
    m = {}
    for line in SYMS.read_text().splitlines():
        g = re.search(r'name\s*=\s*"([^"]+)"\s*,\s*vram\s*=\s*(0x[0-9A-Fa-f]+)', line)
        if g:
            m[int(g.group(2), 16)] = g.group(1)
    return m


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("tracefile")
    ap.add_argument("--all", action="store_true", help="show all targets, not just placeholders")
    args = ap.parse_args()

    p = Path(args.tracefile)
    if not p.exists():
        sys.exit(f"no trace file: {p}")
    syms = load_syms()

    # Each line: 0xTARGET \t frame0 \t frame1 \t ...  (native call stack, innermost first)
    stacks = {}  # target vram -> [frame symbol names]
    for line in p.read_text().splitlines():
        parts = line.split("\t")
        if len(parts) < 2:
            continue
        try:
            addr = int(parts[0], 16)
        except ValueError:
            continue
        stacks[addr] = parts[1:]

    def nearest_named(frames):
        """First stack frame that is a meaningfully-named game function."""
        for fr in frames:
            if fr and not PLACEHOLDER.search(fr) and fr in name_set:
                return fr
        return None

    name_set = set(syms.values())
    rows = []
    for addr, frames in stacks.items():
        name = syms.get(addr, "—")
        is_ph = name == "—" or bool(PLACEHOLDER.search(name))
        if not args.all and not is_ph:
            continue
        anchor = nearest_named(frames)
        rows.append((bool(anchor), addr, name, anchor, frames))

    rows.sort(key=lambda r: (-r[0], r[1]))
    print(f"{len(stacks)} distinct indirect-call targets traced; "
          f"{sum(1 for r in rows if r[0])} placeholder(s) have a NAMED ancestor on the stack\n")
    for has_anchor, addr, name, anchor, frames in rows:
        mark = "*" if has_anchor else " "
        if anchor:
            print(f" {mark} 0x{addr:08X}  {name:<32}  under {anchor}")
        else:
            chain = " -> ".join(f for f in frames[:4] if f)
            print(f" {mark} 0x{addr:08X}  {name:<32}  ({chain})")


if __name__ == "__main__":
    main()

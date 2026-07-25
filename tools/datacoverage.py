#!/usr/bin/env python3
"""Variable (data-symbol) naming coverage for tnt.datasyms.toml — the variable-side
analogue of tools/coverage.py. Tracks progress toward the >=50% named target and
lints the file (the datasym gate, since datasyms are NOT in the build/link).

Usage:
    tools/datacoverage.py          # named/total (%), and count needed to cross 50%
    tools/datacoverage.py --check  # lint: parses clean, no dup name, no dup vram
"""

import argparse
import re
import sys
import tomllib
from pathlib import Path

DATASYMS = Path(__file__).resolve().parent.parent / "tnt.datasyms.toml"
PLACEHOLDER = re.compile(r"^D_[0-9A-Fa-f]{8}$")


def load():
    with open(DATASYMS, "rb") as fh:
        data = tomllib.load(fh)
    syms = []
    for sec in data.get("section", []):
        syms.extend(sec.get("symbols", []))
    return syms


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="lint the file, exit 1 on error")
    args = ap.parse_args()

    try:
        syms = load()
    except Exception as e:
        print(f"FAIL: {DATASYMS.name} does not parse: {e}")
        sys.exit(1)

    total = len(syms)
    named = sum(1 for s in syms if not PLACEHOLDER.match(s["name"]))

    if args.check:
        # Hard error: a vram mapped to two different names (structural corruption,
        # e.g. a botched rename). Duplicate NAMES across different vrams exist in the
        # baseline (generic libultra/splat symbols like `zero`, `pihi`) — report as a
        # warning but don't fail. A NEW meaningful-name collision is prevented at
        # rename time by rename_sym.py's "NEW is free" preflight.
        errs, warns = [], []
        seen_vram, name_addrs = {}, {}
        for s in syms:
            n, v = s["name"], s["vram"]
            if v in seen_vram and seen_vram[v] != n:
                errs.append(f"duplicate vram 0x{v:08X}: {seen_vram[v]} vs {n}")
            seen_vram[v] = n
            name_addrs.setdefault(n, []).append(v)
        for n, addrs in name_addrs.items():
            if len(addrs) > 1 and not PLACEHOLDER.match(n):
                warns.append(f"name '{n}' at {len(addrs)} addresses")
        if errs:
            print("datasym lint FAILED:")
            for e in sorted(set(errs)):
                print(f"  - {e}")
            sys.exit(1)
        print(f"datasym lint OK: {total} symbols, {named} named, no dup vram")
        if warns:
            print(f"  ({len(warns)} pre-existing duplicate-name warnings — baseline noise)")
        return

    pct = 100 * named / total if total else 0
    print(f"DATA SYMBOLS: {named}/{total} named ({pct:.1f}%), {total - named} placeholders")
    need50 = -(-total // 2) - named  # ceil(total/2) - named
    if need50 > 0:
        print(f"  {need50} more named to cross 50%")
    else:
        print(f"  >=50% target met (+{-need50} past the line)")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Guarded symbol rename for the naming loop.

Functions: whole-word (\\bOLD\\b) token substitution across every artifact that
carries the name — tnt.syms.toml, RecompiledFuncs/funcs.h, recomp_overlays.inl,
lookup.cpp, and RecompiledFuncs/**/*.c (definition + all call sites). No ROM.
tools/verify.sh (the build+link) is the definitive check afterward.

Variables: edits only the matching `{ name = "OLD", vram = ... }` entry in
tnt.datasyms.toml (never regenerates; merge-safe).

Preflights refuse any rename that would collide (dup symbol) or that can't find its
source, and a --map batch is ATOMIC: all preflights must pass or nothing is written.

Usage:
    tools/rename_sym.py --func OLD NEW
    tools/rename_sym.py --data OLD NEW
    tools/rename_sym.py --map FILE          # lines: "func OLD NEW" | "data OLD NEW"
    tools/rename_sym.py ... --dry-run

If a function's subsystem prefix (identifier before the first '_') changes, the tool
prints NEEDS-REORG; run tools/reorganize_recompiled.py once, then tools/verify.sh.
"""

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
FUNCS_DIR = ROOT / "RecompiledFuncs"
SYMS = ROOT / "tnt.syms.toml"
DATASYMS = ROOT / "tnt.datasyms.toml"

DEF_RE = re.compile(r"^RECOMP_FUNC\s+\S+\s+(\w+)\(", re.M)
SYM_NAME_RE = re.compile(r'name\s*=\s*"([^"]+)"')
PLACEHOLDER = re.compile(r"[89A-Fa-f][0-9A-Fa-f]{7}|^func_|^FUN_|^D_")
IDENT_RE = re.compile(r"^[A-Za-z_]\w*$")


def func_artifacts():
    arts = [SYMS, FUNCS_DIR / "funcs.h", FUNCS_DIR / "recomp_overlays.inl",
            FUNCS_DIR / "lookup.cpp"]
    arts += sorted(FUNCS_DIR.rglob("*.c"))
    return [p for p in arts if p.exists()]


def load_func_names():
    """All known function symbol names (tnt.syms.toml names + RECOMP_FUNC defs)."""
    names = set(SYM_NAME_RE.findall(SYMS.read_text()))
    def_counts = {}
    for f in FUNCS_DIR.rglob("*.c"):
        for m in DEF_RE.finditer(f.read_text()):
            def_counts[m.group(1)] = def_counts.get(m.group(1), 0) + 1
    names |= set(def_counts)
    return names, def_counts


def load_data_syms():
    """name -> count and name -> vram, from tnt.datasyms.toml."""
    counts, name_vram = {}, {}
    for line in DATASYMS.read_text().splitlines():
        m = re.search(r'name\s*=\s*"([^"]+)".*vram\s*=\s*(0[xX][0-9A-Fa-f]+)', line)
        if m:
            n = m.group(1)
            counts[n] = counts.get(n, 0) + 1
            name_vram[n] = int(m.group(2), 16)
    return counts, name_vram


def prefix(name):
    return name.split("_", 1)[0] if "_" in name else name


def preflight_func(old, new, func_names, def_counts, batch_news, errs):
    if not IDENT_RE.match(new):
        errs.append(f"func {old}->{new}: NEW is not a valid C identifier")
    if PLACEHOLDER.search(new):
        errs.append(f"func {old}->{new}: NEW looks like a placeholder")
    if def_counts.get(old, 0) != 1:
        errs.append(f"func {old}->{new}: OLD has {def_counts.get(old,0)} RECOMP_FUNC defs (need exactly 1)")
    if old not in func_names:
        errs.append(f"func {old}->{new}: OLD not found in symbol set")
    if new in func_names:
        errs.append(f"func {old}->{new}: NEW already exists (would duplicate a symbol)")
    if new in batch_news:
        errs.append(f"func {old}->{new}: NEW targeted twice in this batch")
    batch_news.add(new)


def preflight_data(old, new, data_counts, batch_news, errs):
    if not IDENT_RE.match(new):
        errs.append(f"data {old}->{new}: NEW is not a valid C identifier")
    if PLACEHOLDER.search(new):
        errs.append(f"data {old}->{new}: NEW looks like a placeholder")
    if data_counts.get(old, 0) != 1:
        errs.append(f"data {old}->{new}: OLD has {data_counts.get(old,0)} entries (need exactly 1)")
    if new in data_counts:
        errs.append(f"data {old}->{new}: NEW already exists in datasyms")
    if new in batch_news:
        errs.append(f"data {old}->{new}: NEW targeted twice in this batch")
    batch_news.add(new)


def apply_func_renames(renames, dry):
    """renames: list of (old,new). Returns (per_artifact_hits, needs_reorg set)."""
    hits = {}
    needs_reorg = set()
    patterns = [(o, n, re.compile(r"\b" + re.escape(o) + r"\b")) for o, n in renames]
    for o, n in renames:
        if prefix(o) != prefix(n):
            needs_reorg.add((o, n))
    for art in func_artifacts():
        text = art.read_text()
        new_text = text
        art_hits = 0
        for o, n, pat in patterns:
            new_text, c = pat.subn(n, new_text)
            art_hits += c
        if art_hits:
            hits[art.relative_to(ROOT).as_posix()] = art_hits
        if not dry and new_text != text:
            art.write_text(new_text)
    return hits, needs_reorg


def apply_data_renames(renames, dry):
    text = DATASYMS.read_text()
    total = 0
    for o, n in renames:
        pat = re.compile(r'(name\s*=\s*")' + re.escape(o) + r'(")')
        text, c = pat.subn(r"\g<1>" + n + r"\g<2>", text)
        total += c
    if not dry and total:
        DATASYMS.write_text(text)
    return total


def parse_map(path):
    ops = []
    for ln, raw in enumerate(Path(path).read_text().splitlines(), 1):
        line = raw.split("#", 1)[0].strip()
        if not line:
            continue
        parts = line.split()
        if len(parts) != 3 or parts[0] not in ("func", "data"):
            sys.exit(f"map line {ln}: expected 'func OLD NEW' or 'data OLD NEW', got: {raw!r}")
        ops.append(tuple(parts))
    return ops


def main():
    ap = argparse.ArgumentParser()
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--func", nargs=2, metavar=("OLD", "NEW"))
    g.add_argument("--data", nargs=2, metavar=("OLD", "NEW"))
    g.add_argument("--map", metavar="FILE")
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    if args.func:
        ops = [("func", *args.func)]
    elif args.data:
        ops = [("data", *args.data)]
    else:
        ops = parse_map(args.map)

    func_ren = [(o, n) for k, o, n in ops if k == "func"]
    data_ren = [(o, n) for k, o, n in ops if k == "data"]

    func_names, def_counts = load_func_names() if func_ren else (set(), {})
    data_counts, _ = load_data_syms() if data_ren else ({}, {})

    errs, batch_news = [], set()
    for o, n in func_ren:
        preflight_func(o, n, func_names, def_counts, batch_news, errs)
    for o, n in data_ren:
        preflight_data(o, n, data_counts, batch_news, errs)
    # A NEW must not also be an OLD in the same batch (no chaining under atomic apply).
    olds = {o for _, o, _ in ops}
    for _, o, n in ops:
        if n in olds:
            errs.append(f"{o}->{n}: NEW is also an OLD in this batch (chaining not allowed)")

    if errs:
        print("PREFLIGHT FAILED — nothing written:")
        for e in errs:
            print(f"  - {e}")
        sys.exit(1)

    tag = "[dry-run] " if args.dry_run else ""
    if func_ren:
        hits, needs_reorg = apply_func_renames(func_ren, args.dry_run)
        print(f"{tag}functions: {len(func_ren)} rename(s) across {len(hits)} artifact(s)")
        for a, c in sorted(hits.items()):
            print(f"    {c:>5}  {a}")
        if needs_reorg:
            print("  NEEDS-REORG (prefix changed) — run tools/reorganize_recompiled.py then verify.sh:")
            for o, n in sorted(needs_reorg):
                print(f"    {o} -> {n}  ({prefix(o)} -> {prefix(n)})")
    if data_ren:
        total = apply_data_renames(data_ren, args.dry_run)
        print(f"{tag}data: {len(data_ren)} rename(s), {total} entr(y/ies) updated")
        if total != len(data_ren):
            print("  WARNING: updated count != rename count — inspect tnt.datasyms.toml")

    if args.dry_run:
        print("(dry-run: no files modified)")


if __name__ == "__main__":
    main()

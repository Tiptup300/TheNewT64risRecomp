#!/usr/bin/env python3
"""Data cross-reference: which global addresses each recompiled function touches.

The variable-naming engine for the recursive naming loop (see
docs/naming-campaign-plan.md). Recompiled data accesses are never symbolized —
they appear as a `lui` (high half) plus a load/store at a signed offset. This tool
reconstructs the absolute address from the verbatim `// 0xADDR: <mips>` comments
(the C expression's operand order is asymmetric between loads and stores, so the
comments are the source of truth), and joins it against tnt.datasyms.toml so a
named function reveals — and cross-confirms — the globals it uses.

Usage:
    tools/dataxref.py --func NAME        # globals a function reads/writes
    tools/dataxref.py --file PATH        # all globals in a .c, grouped by function
    tools/dataxref.py --addr 0x800E1F10  # every function that touches an address
    tools/dataxref.py --all [--unnamed]  # full xref (--unnamed = only D_/unknown)

Read-only. Columns: ADDR | datasym | R/W/A | width | off | function
  R=read  W=write  A=address-of (lui+addiu, e.g. passed as a pointer arg)
A '*' after ADDR marks a pointer-holding global (load dest == base); its later
dereferences are dynamic and intentionally NOT reported (runtime-tracing residue).
"""

import argparse
import re
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
FUNCS_DIR = ROOT / "RecompiledFuncs"
DATASYMS = ROOT / "tnt.datasyms.toml"

DEF_RE = re.compile(r"^RECOMP_FUNC\s+\S+\s+(\w+)\(", re.M)
# A verbatim MIPS line: "    // 0x8007BAD4: lui         $t0, 0x800E"
ASM_RE = re.compile(r"//\s*0x[0-9A-Fa-f]+:\s*(\S+)\s*(.*)")
LABEL_RE = re.compile(r"^\s*[A-Za-z_]\w*:\s*$")

MEM_RE = re.compile(r"\$(\w+),\s*(-?0[xX][0-9A-Fa-f]+)\((\$\w+)\)")
LUI_RE = re.compile(r"\$(\w+),\s*(0[xX][0-9A-Fa-f]+)")
ADDI_RE = re.compile(r"\$(\w+),\s*\$(\w+),\s*(-?0[xX][0-9A-Fa-f]+)")

# Game RAM (KSEG0) range. Addresses outside this are not data globals — they are
# immediate float/GBI constants a `lui` happens to build (e.g. 0x3F80<<16 = 1.0f,
# 0xE700<<16 = an RDP command word). Gating on this range prevents fabricating
# bogus datasyms from constant-building lui sites.
RAM_LO, RAM_HI = 0x80000000, 0x80800000

LOADS = {"lb", "lbu", "lh", "lhu", "lw", "lwu", "lwc1", "ldc1", "ll",
         "lwl", "lwr", "ld"}
STORES = {"sb", "sh", "sw", "swc1", "sdc1", "sc", "swl", "swr", "sd"}
# Instructions whose FIRST operand is a written GPR — clear its tracked state.
WRITERS = {"addu", "subu", "and", "or", "xor", "nor", "slt", "sltu", "slti",
           "sltiu", "sll", "srl", "sra", "sllv", "srlv", "srav", "mflo", "mfhi",
           "move", "li", "negu", "not", "mul", "andi", "xori", "lhu", "seb", "seh"}


def width_of(mnem):
    core = mnem.lstrip("ls").rstrip("u")
    if core.endswith("c1"):
        core = core[:-2]
    return {"b": 1, "h": 2, "w": 4, "d": 8, "wl": 4, "wr": 4}.get(core, 4)


def parse_function(name, body, out):
    """Walk a function body's asm comments; append (addr, rw, width, off, ptr) to out."""
    hi = {}    # reg -> high 16 bits from a live lui
    addr = {}  # reg -> full computed address (lui+addiu)

    def clear(reg):
        hi.pop(reg, None)
        addr.pop(reg, None)

    for line in body.splitlines():
        if LABEL_RE.match(line):        # branch target: state may be entered mid-stream
            hi.clear(); addr.clear()
            continue
        m = ASM_RE.search(line)
        if not m:
            continue
        mnem, ops = m.group(1), m.group(2)

        if mnem == "lui":
            g = LUI_RE.search(ops)
            if g:
                r = g.group(1)
                hi[r] = int(g.group(2), 16) & 0xFFFF
                addr.pop(r, None)
            continue

        if mnem in ("addiu", "ori"):
            g = ADDI_RE.search(ops)
            if g:
                rd, rs, imm = g.group(1), g.group(2), int(g.group(3), 16)
                base = (hi[rs] << 16) if rs in hi else addr.get(rs)
                if base is not None:
                    a = (base + imm) & 0xFFFFFFFF
                    addr[rd] = a
                    hi.pop(rd, None)
                    if RAM_LO <= a < RAM_HI:   # R7: skip constant-building lui (floats/GBI cmds)
                        out.append((a, "A", 0, imm, False))
                else:
                    clear(rd)
            else:
                clear(mnem_dest(ops))
            continue

        if mnem in LOADS or mnem in STORES:
            g = MEM_RE.search(ops)
            if g:
                rt, off, rb = g.group(1), int(g.group(2), 16), g.group(3)[1:]
                base = (hi[rb] << 16) if rb in hi else addr.get(rb)
                if base is not None:
                    a = (base + off) & 0xFFFFFFFF
                    ptr = (mnem in LOADS and rt == rb)
                    if RAM_LO <= a < RAM_HI:   # R7: only real RAM addresses are data globals
                        out.append((a, "W" if mnem in STORES else "R", width_of(mnem), off, ptr))
                    if mnem in LOADS:
                        clear(rt)     # rt now holds loaded data (or a pointer)
                else:
                    if mnem in LOADS:
                        clear(rt)
            continue

        if mnem in WRITERS:
            clear(mnem_dest(ops))
    return out


def mnem_dest(ops):
    m = re.match(r"\$(\w+)", ops.strip())
    return m.group(1) if m else "\0"


def load_datasyms():
    names = {}
    if DATASYMS.exists():
        for line in DATASYMS.read_text().splitlines():
            m = re.search(r'name\s*=\s*"([^"]+)".*vram\s*=\s*(0[xX][0-9A-Fa-f]+)', line)
            if m:
                names[int(m.group(2), 16)] = m.group(1)
    return names


def is_placeholder_sym(nm):
    return nm is None or re.match(r"^D_[0-9A-Fa-f]{8}$", nm or "")


def collect():
    """Return {func_name: [(addr,rw,width,off,ptr),...]} and func->file map."""
    per_func = {}
    func_file = {}
    for f in sorted(FUNCS_DIR.rglob("*.c")):
        text = f.read_text()
        marks = [(m.start(), m.group(1)) for m in DEF_RE.finditer(text)]
        for i, (pos, name) in enumerate(marks):
            end = marks[i + 1][0] if i + 1 < len(marks) else len(text)
            refs = []
            parse_function(name, text[pos:end], refs)
            per_func[name] = refs
            func_file[name] = f.relative_to(ROOT).as_posix()
    return per_func, func_file


def fmt_rows(rows, names, show_func=True):
    out = []
    for addr, rw, width, off, ptr, *rest in rows:
        fn = rest[0] if rest and show_func else ""
        nm = names.get(addr, "—") or "—"
        star = "*" if ptr else " "
        w = str(width) if width else "-"
        out.append(f"  0x{addr:08X}{star} {nm:<28} {rw:<2} {w:<2} {off:>#8x}  {fn}")
    return out


def main():
    ap = argparse.ArgumentParser()
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--func", metavar="NAME")
    g.add_argument("--funcs", metavar="F1,F2,...",
                   help="comma-separated function list (scope a batch without reading a monster .c)")
    g.add_argument("--file", metavar="PATH")
    g.add_argument("--addr", metavar="0xADDR")
    g.add_argument("--all", action="store_true")
    g.add_argument("--rank-funcs", action="store_true",
                   help="rank functions by # distinct globals touched (drives the variable harvest)")
    ap.add_argument("--unnamed", action="store_true",
                    help="with --all: only addresses whose datasym is D_/unknown")
    args = ap.parse_args()

    names = load_datasyms()
    per_func, func_file = collect()

    if args.func:
        rows = per_func.get(args.func)
        if rows is None:
            print(f"no such function: {args.func}")
            return
        seen = dict()  # addr -> (rw set) dedup, keep first meta
        for a, rw, w, off, ptr in rows:
            seen.setdefault((a, off, rw), (a, rw, w, off, ptr))
        print(f"{args.func}  ({func_file.get(args.func)})")
        for line in fmt_rows(sorted(seen.values()), names, show_func=False):
            print(line)
        return

    if args.funcs:
        for name in [s.strip() for s in args.funcs.split(",") if s.strip()]:
            rows = per_func.get(name)
            if rows is None:
                print(f"{name}: (no such function)")
                continue
            uniq = sorted({(a, off, rw): (a, rw, w, off, ptr)
                           for a, rw, w, off, ptr in rows}.values())
            print(f"{name}  ({func_file.get(name)})")
            for line in fmt_rows(uniq, names, show_func=False):
                print(line)
        return

    if args.file:
        target = args.file
        printed = False
        for fn, ff in sorted(func_file.items()):
            if not (ff.endswith(target) or ff == target or Path(ff).name == Path(target).name):
                continue
            rows = per_func[fn]
            if not rows:
                continue
            printed = True
            uniq = sorted({(a, off, rw): (a, rw, w, off, ptr)
                           for a, rw, w, off, ptr in rows}.values())
            print(f"{fn}::{fn}" if False else f"{fn}")
            for line in fmt_rows(uniq, names, show_func=False):
                print(line)
        if not printed:
            print(f"no functions found for file: {target}")
        return

    if args.addr:
        want = int(args.addr, 16)
        print(f"functions touching 0x{want:08X}  ({names.get(want, '—')})")
        hits = {}  # (fn, rw) -> representative row (collapses delay-slot/repeat dupes)
        for fn, rows in per_func.items():
            for a, rw, w, off, ptr in rows:
                if a == want:
                    hits.setdefault((fn, rw, off), (a, rw, w, off, ptr, fn))
        for line in fmt_rows(sorted(hits.values(), key=lambda r: (r[5], r[1])), names):
            print(line)
        if not hits:
            print("  (none)")
        return

    if args.rank_funcs:
        rows = []
        for fn, rs in per_func.items():
            addrs = {a for a, rw, w, off, ptr in rs}
            unnamed = {a for a in addrs if is_placeholder_sym(names.get(a))}
            if addrs:
                rows.append((len(addrs), len(unnamed), fn, func_file.get(fn)))
        print(f"{'#glob':>5} {'#unnamed':>8}  function  (file)")
        for tot, un, fn, ff in sorted(rows, reverse=True)[:60]:
            print(f"{tot:>5} {un:>8}  {fn}  ({ff})")
        return

    if args.all:
        rows = {}  # (addr, fn, rw, off) -> row (dedup)
        for fn, rs in per_func.items():
            for a, rw, w, off, ptr in rs:
                if args.unnamed and not is_placeholder_sym(names.get(a)):
                    continue
                rows.setdefault((a, fn, rw, off), (a, rw, w, off, ptr, fn))
        vals = sorted(rows.values(), key=lambda r: (r[0], r[5]))
        for line in fmt_rows(vals, names):
            print(line)
        print(f"\n{len({r[0] for r in vals})} distinct addresses, {len(vals)} references")


if __name__ == "__main__":
    main()

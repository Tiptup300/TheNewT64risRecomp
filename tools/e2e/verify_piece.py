#!/usr/bin/env python3
"""verify_piece.py — live-confirm the logical piece-state offsets found by static RE.

Static RE (RecompiledFuncs/gameplay/CurrentPiece.c) says the active piece's logical
fields live at *g_currentPiece_ptr + {0x0A rot, 0x11 col(s8), 0x12 row(s8), 0x13 type}.
This drives real input and watches those exact bytes, then POKES the column to shift the
piece on screen — the cross-validation the state map requires before recording.

    python3 tools/e2e/verify_piece.py
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep
from e2e_helpers import reach_gameplay

REGION = (0x80200000, 0x100000)   # covers the gameplay heap (~0x8029xxxx)
OFF = {"rot": 0x0A, "col": 0x11, "row": 0x12, "type": 0x13}


def rd(g, snap, P, off, signed=False):
    i = (P + off) - REGION[0]
    if not (0 <= i < len(snap)):
        return None
    return int.from_bytes(snap[i:i+1], "little", signed=signed)


def fields(g, P):
    s = g.snapshot()
    return {k: rd(g, s, P, o, signed=(k in ("col", "row"))) for k, o in OFF.items()}


def main():
    with Game(region=REGION) as g:
        reach_gameplay(g)
        P = g.read("piece_ptr")
        print(f"# gameplay scene={g.read('scene')}  piece_base=0x{P:08X}\n")
        print(f"  initial: {fields(g, P)}")

        # LEFT should decrement column (if the move is legal).
        g.tap(Keys.LEFT); _sleep(0.25)
        P = g.read("piece_ptr"); print(f"  after LEFT:  {fields(g, P)}  (col expected -1)")
        # RIGHT twice should increment column.
        g.tap(Keys.RIGHT); _sleep(0.2); g.tap(Keys.RIGHT); _sleep(0.25)
        P = g.read("piece_ptr"); print(f"  after RIGHTx2: {fields(g, P)}  (col expected +2 vs above)")
        # A should change rotation (mod 4).
        r0 = fields(g, P)["rot"]
        g.tap(Keys.A); _sleep(0.25)
        P = g.read("piece_ptr"); f = fields(g, P)
        print(f"  after A(rotate): {f}  (rot {r0} -> {f['rot']})")

        # Visual proof: poke the column left, screenshot; poke right, screenshot.
        P = g.read("piece_ptr"); base = fields(g, P)
        col = base["col"]
        if col is not None:
            g.poke(P + OFF["col"], 1, (col - 3) & 0xFF); _sleep(0.3); g.clear_pokes()
            _sleep(0.2); g.shot("piece_col_minus3")
            print(f"  poked col {col} -> {col-3}; shot piece_col_minus3")
            P = g.read("piece_ptr")
            g.poke(P + OFF["col"], 1, (col + 3) & 0xFF); _sleep(0.3); g.clear_pokes()
            _sleep(0.2); g.shot("piece_col_plus3")
            print(f"  poked col -> {col+3}; shot piece_col_plus3")
    print("done.")
    return 0


if __name__ == "__main__":
    sys.exit(main())

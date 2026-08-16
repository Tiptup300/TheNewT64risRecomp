#!/usr/bin/env python3
"""Verify the recompui-demo mod: it must LOAD (no "Imported function not found") and render a
real recompui panel on the menu. Reach the menu hub (scene 4); the mod auto-shows its panel;
screenshot it; scan the log for import/load errors."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from harness import Game, Keys, _sleep
from e2e_helpers import reach_menu


def main():
    with Game(mods=["tnt_intro_skip", "tnt_recompui_demo"]) as g:
        reach_menu(g)
        _sleep(2.0)                 # let the one-shot auto-show fire + render
        shot = g.shot("recompui_demo")
        _sleep(0.2)
        log = Path(g.log_path).read_text(errors="ignore")
        bad = [l for l in log.splitlines()
               if ("Imported function not found" in l or "Failed to load mod" in l
                   or "recompui_demo" in l.lower() and "error" in l.lower())]
        print("shot:", shot)
        print("scene:", g.read("scene"))
        if bad:
            print("LOAD ERROR(S):")
            for l in bad[:10]:
                print("  ", l)
            return 1
        print("no import/load errors detected")
        return 0


if __name__ == "__main__":
    sys.exit(main())

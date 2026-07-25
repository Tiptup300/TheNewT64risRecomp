# The New Tiptris — cheat codes & secrets (catalog)

These are the game's **built-in** cheats, entered as a **player name** on the
single-player name-entry screen (type the name, highlight **OK**, press **A/Accept**),
except where noted. They already work in our port — this catalog is to decide which
to surface as convenient toggles/mods so players don't have to type name codes.

Sourced from community cheat lists (see Sources). Effects are as documented there;
**not yet verified in-game** in our build (name-entry needs input the headless
harness can't drive — flag for a play-test).

| Code (enter as name) | Effect | Mod candidate? |
|---|---|---|
| `2FAST4U` | **Turbo mode** — *your* blocks eventually fall very fast (faster wins, but rank drops faster). | ✅ Good toggle mod (speed). Hook the fall-speed/gravity for the human player. |
| `AI2EZ4U` | **Turbo CPU** — the *CPU's* blocks fall very fast; yours stay normal (easy wins vs AI). | ✅ Good toggle mod (AI handicap). |
| `HALUCI` | **Music kaleidoscope** Easter egg. First set Audio options: song = `Haluci`, music mode = `Choose`. Then enter `HALUCI` as a name. A kaleidoscope replaces the game; **must reset to exit**. | ⚠️ Novelty; the reset-to-exit makes it a poor mod unless we also add an exit path. |
| `O1DERS` | **Delete line totals & reset Wonders** progress. | ❌ Destructive save edit — not a mod (belongs in a data/reset menu, if anywhere). |
| `1N175R4M` | **Delete ALL save data.** | ❌ Destructive — never a bundled mod. |

## Unlockables (not codes)
- **Wonders** unlock by cumulative lines cleared; the seven thresholds are the ones
  our **Rebalanced Wonder Requirements** mod adjusts (stock top end ~500k lines →
  "The Finale" cutscene of all Wonders). See `mods/wonders-rebalance`.

## Notes for implementation
- The name-entry cheats live in the same **name-entry / "transfer name"** flow that
  the TODO wants tidied (hide "transfer name" / "dump lines to game pak" in the data
  menu) — worth keeping in mind when touching that menu.
- The two speed cheats (`2FAST4U`, `AI2EZ4U`) are the clean mod candidates: expose
  them as toggleable mods (or a single "speed options" mod) instead of name codes.
  Implementation would hook the per-player fall-speed/gravity update; the exact
  function needs an RE pass (gameplay/`KeySpin` / drop-timer logic).

## Sources
- [Neoseeker — The New Tetris cheats](https://www.neoseeker.com/newtetris/cheats/n64/)
- [GameFAQs — The New Tetris cheats](https://gamefaqs.gamespot.com/n64/198976-the-new-tetris/cheats)
- [SuperCheats — The New Tetris](https://www.supercheats.com/nintendo64/thenewtetris.htm)

# TODO roadmap

Index of open/proposed work for **The New T64ris** recomp. Each item links to a spec
in this `todo/` folder (where one exists). Keep newest/most-active near the top;
mark items done rather than deleting (so the history stays readable).

Legend: 🟢 ready to start · 🟡 needs a decision · 🔵 research-heavy · ✅ done

---

## Tooling / dev-experience

### 🟢 State-snapshot annotator — "freeze + annotate a single moment"
Press a hotkey → game locks at the current state → add positioned annotations + a
write-up → save a single point-in-time record (PNG + RAM + decoded globals + notes).
- **Spec:** [`state-snapshot-annotator.md`](state-snapshot-annotator.md)
- **Size:** MVP ≈ ½–1 day (~80% reuses existing `update_gfx` state bridge + E2E
  harness); host-side Python annotator sidesteps the WSL2/Dozen overlay hang.
- **Open sub-choice:** annotator UI = Tk desktop window vs self-contained local web page.
- **Stretch:** click a screen position → identify the game object/RAM struct there.

## Runtime / emulation

### 🟡 Controller-Pak (osPfs) emulation — IMPLEMENTED; crash fixed; needs commit + polish
`lib/N64ModernRuntime/librecomp/src/pak.cpp` now has a full mem-pak HLE (16-file note
table persisted to a 32KB `mempak.bin`). **It was crashing the game** (SIGSEGV in
`osPfsInitPak` on game start / save-data access) because the guest-RAM helpers
**zero-extended** the 32-bit KSEG0 pointer instead of sign-extending it, landing ~4GB
out of bounds. **Fixed 2026-08-08** (`(gpr)(int32_t)gaddr`); verified: reaches
gameplay + menu profile listing with no crash, image created.
- **Still to do:** (a) **commit** the pak.cpp changes — they live *uncommitted* in the
  `lib/N64ModernRuntime` submodule working tree (prior attempt was lost this way);
  (b) place `mempak.bin` under the config dir instead of `$HOME` (helps test
  isolation — see unit-test-library spec); (c) verify create-profile → name save →
  survives relaunch end-to-end. (Was task #28.)

## Project / legal

### 🟡 Add a GPL license for the project's own code
Add a `LICENSE` (GPL — confirm **v2 vs v3**) covering *this project's original code*
(the tooling in `tools/`, `src/main.cpp` glue, docs, mod sources under `mods/`).
- **Caveats to resolve before dropping a LICENSE file:**
  - **Bundled third-party** under `lib/` (N64ModernRuntime, RmlUi, SDL, the JSON lib,
    RT64/Dozen, etc.) each keep **their own** licenses — a repo GPL must not claim to
    relicense those. Scope the GPL to first-party files (headers/`.reuse` or a clear
    "Scope" section), keep third-party notices intact, and check GPL-compatibility of
    each dep (SDL=zlib ok; RmlUi=MIT ok; verify the rest).
  - **Recompiled game code** in `RecompiledFuncs/**` derives from a copyrighted ROM
    and is *not* ours to license — exclude it explicitly (it's already never
    distributed as game *data*; but the recompiled C is a derivative — keep the repo's
    existing "code only, no ROM/assets" posture and don't slap GPL on it).
  - Confirm N64Recomp/N64ModernRuntime's own license doesn't impose terms on our glue.
- **Deliverable:** `LICENSE` + a short `docs/LICENSING.md` explaining the scope split.
  (Recorded per user request 2026-08-08; "iff possible" — needs the scope decision.)

## RE / naming (living-names practice — refine as we learn)

### 🔵 `g_gameStartFlag` @0x8011EAED → likely `g_versusModeFlag`
`Scene_SingleStartGame` writes 2 (opponent/vs) vs 0 (single); looks like a mode
selector, not a bare flag. Needs more xref evidence before renaming. See
`docs/MENU_TREE.md` §9.

### 🔵 SINGLE-screen spinner value-objects (OPPONENT/GAME option lists)
The spinner value objects (`item+0x30`: count @+0x00, index @+0x3B0) are runtime BSS;
their full label/option tables aren't static. Capture with `tools/e2e/` to enumerate
the OFF/EASY/MEDIUM… and MARATHON/SPRINT/ULTRA… sets + any modes beyond index 2.

### 🔵 Profile-roster storage (stride / max count)
Assembled at runtime from live Pfs file enumeration + synthetic GUEST/NEW-NAME ends;
exact array stride/max not statically pinned. Pin with the E2E RAM harness.

---

## Done
- ✅ **Python unit-test library (pytest), mod-isolated, headless** — `tests/` +
  `tests/run.sh` (project `.venv-test`). Isolates HOME/XDG per test (never touches the
  user's mods/saves), explicit per-test mod selection (default none), seeds known-good
  graphics to avoid the Dozen first-run-defaults crash. 7 tests green (boot, isolation,
  menu, gameplay). Spec: [`unit-test-library.md`](unit-test-library.md). (2026-08-08)
- ✅ Controller-Pak crash fixed — sign-extension bug in `pak.cpp` guest-RAM helpers;
  game now runs (start-game + menu profile listing stable). *(commit still pending —
  see mem-pak item above.)* (2026-08-08)
- ✅ Front-end menu fully mapped + code-bound (`docs/MENU_TREE.md`,
  `docs/MENU_OBSERVED.md`); symbol refinements committed. (2026-08-08)
- ✅ E2E harness (launch / wait-on-RAM / assert / inject input / screenshot);
  `test_menu`, `test_to_gameplay` pass. (`tools/e2e/`)
- ✅ Name-entry / create-profile screen found + fully RE'd. (was task #27)
- ✅ Functions 100% named; variables ~87%.

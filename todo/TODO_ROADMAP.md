# TODO roadmap

Index of open/proposed work for **The New T64ris** recomp. Each item links to a spec
in this `todo/` folder (where one exists). Keep newest/most-active near the top;
mark items done rather than deleting (so the history stays readable).

Legend: 🟢 ready to start · 🟡 needs a decision · 🔵 research-heavy · ✅ done

---

## Mods

### 🟢 Rework "Skip Intro Logos" → "press any key to skip any intro screen"
Turn the current mod (an *automatic* config-driven fast-forward that jumps scene ≤2 →
3) into a **player-driven universal skip**: on ANY intro/pre-menu screen, pressing
**any button at any time** skips that screen and advances toward the menu.
- **Current:** `mods/intro-skip/src/intro.c` hooks `Scene_Update`; if `skip_to != Off`
  it forces `SCENE`(0x800CFEE8) from ≤2 to 3 automatically (no input).
- **Target behavior:** hook `Scene_Update` (or the input poll); when the current scene
  is an intro phase — **0/1/2** (N64 logo, publisher/H2O, cube-tiles animation) or
  **3** (attract flythrough/title) — and **any** controller button was just pressed
  (`g_buttonsPressed` @0x8011EF54 edge-mask ≠ 0), advance that screen: branding/logos
  → attract (or straight through), attract → menu.
- **Hard constraint (known bug):** do NOT force `SCENE = 4` directly — it segfaults
  (`MenuHub_StartPlaying`→`Scene_SetupObjectMatrices` on an unset object-slot buffer;
  see [[tnt-scene-and-crash-re]]). Safe route: advance logos to the attract scene (3),
  which is self-contained, and let the game's own A/Start handle 3→4 with proper setup
  — OR fix the scene-4 setup path so a direct skip-to-menu is safe (bigger).
- **"Any key" caveat:** a mod sees N64 button state in RAM, not raw SDL keys, so
  "any key" = any *mapped* button. Literal any-keyboard-key would need a small runtime
  hook (out of mod scope). D-pad/A/B/Start/Z/C all count via the edge mask.
- **Config:** replace the `skip_to` enum with a simple on/off (default on), or keep
  `enabled_by_default` and drop the enum entirely.

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

### 🟡 Controller-Pak (osPfs) emulation — DONE (one documented UI-automation gap)
`lib/N64ModernRuntime/librecomp/src/pak.cpp` has a full mem-pak HLE (16-file note table
persisted to a 32KB `mempak.bin`). Complete 2026-08-08:
- **Crash fixed + committed** (nested repo `509f428`): guest-RAM helpers were
  zero-extending the 32-bit KSEG0 pointer → ~4GB OOB SIGSEGV in `osPfsInitPak`; now
  sign-extend (`(gpr)(int32_t)gaddr`). Game runs.
- **Relocated** (`d1a1a66`): `mempak.bin` now lives in the config dir
  (`recomp::get_config_path()`), not hardcoded `$HOME`.
- **Persistence verified** (`tests/test_mempak.py`, 2 tests green): boot creates a
  valid 32KB pak at the config dir; a seeded pak survives a relaunch and the game
  loads it (osPfsInitPak→pak_load) without crashing or corrupting it — proving the
  write/load/persist layer round-trips through the real binary.
- **Remaining gap (documented, not a blocker):** the *interactive* create-profile →
  name-entry keyboard → save flow is verified by RE (`docs/MENU_TREE.md`) but is not
  UI-automatable in this WSLg setup (screenshots are occluded by overlapping windows;
  blind keyboard/menu nav is unreliable). Would need a small runtime input hook to
  drive the on-screen keyboard deterministically. The persistence layer that flow
  depends on is fully covered above.

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
- ✅ **Controller-Pak (osPfs) HLE** — crash fixed + mem-pak relocated to config dir +
  persistence verified (`tests/test_mempak.py`). One documented UI-automation gap
  (interactive create-profile). See mem-pak item above. (2026-08-08)
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

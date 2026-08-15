# TODO roadmap — single source of truth

The one place for open/proposed work on **The New T64ris** recomp. This supersedes the
old root `TODO.md` (now a pointer here). Specs for larger items live beside this file
in `todo/`. Completed *plans* (naming, reorg) live in `docs/` and are linked at the
bottom — don't duplicate their content here.

Legend: 🟢 ready to start · 🟡 needs a decision · 🔵 research-heavy · 🚧 partially done · ✅ done

---

## Priorities / active specs

### 🟢 Rework "Skip Intro Logos" → "press any key to skip any intro screen"
Turn the current mod (an *automatic* config-driven fast-forward that jumps scene ≤2 →
3) into a **player-driven universal skip**: on ANY intro/pre-menu screen, pressing
**any button at any time** skips that screen and advances toward the menu.
- **Current:** `mods/intro-skip/src/intro.c` hooks `Scene_Update`; if `skip_to != Off`
  it forces `SCENE`(0x800CFEE8) from ≤2 to 3 automatically (no input).
- **Target:** hook `Scene_Update` (or the input poll); when the current scene is an
  intro phase — **0/1/2** (N64 logo, publisher/H2O, cube-tiles) or **3** (attract/
  title) — and **any** controller button was just pressed (`g_buttonsPressed`
  @0x8011EF54 edge-mask ≠ 0), advance that screen: logos → attract, attract → menu.
- **Hard constraint (known bug):** do NOT force `SCENE = 4` directly — segfault
  (`MenuHub_StartPlaying`→`Scene_SetupObjectMatrices` on an unset object-slot buffer;
  see the crash item under *In progress*). Safe route: advance logos to attract (3)
  and let the game's own A/Start take 3→4 with proper setup.
- **"Any key" caveat:** a mod sees N64 button state in RAM, not raw SDL keys → "any
  key" = any *mapped* button. Literal any-key would need a small runtime hook.
- **Config:** replace the `skip_to` enum with a simple on/off (default on).

### 🟢 State-snapshot annotator — "freeze + annotate a single moment"
Press a hotkey → game locks at the current state → add positioned annotations + a
write-up → save a single point-in-time record (PNG + RAM + decoded globals + notes).
- **Spec:** [`state-snapshot-annotator.md`](state-snapshot-annotator.md)
- **Size:** MVP ≈ ½–1 day (~80% reuses the `update_gfx` state bridge + E2E harness);
  host-side Python annotator sidesteps the WSL2/Dozen overlay hang.
- **Open sub-choice:** annotator UI = Tk desktop window vs self-contained local web page.

### 🟡 Add a GPL license for the project's own code
Add a `LICENSE` (GPL — confirm **v2 vs v3**) covering *this project's original code*
(`tools/`, `src/main.cpp` glue, docs, `mods/` sources).
- **Bundled third-party** under `lib/` (N64ModernRuntime, RmlUi, SDL, JSON, RT64/Dozen)
  keep **their own** licenses — scope the GPL to first-party files, keep third-party
  notices, verify GPL-compat (SDL=zlib ok; RmlUi=MIT ok; verify the rest).
- **Recompiled code** in `RecompiledFuncs/**` derives from a copyrighted ROM — exclude
  it; keep the "code only, no ROM/assets" posture.
- **Deliverable:** `LICENSE` + short `docs/LICENSING.md` explaining the scope split.
- Also folds in the release-hygiene "license + credits pass" (harness license,
  dependency licenses, tnt-splat credit).

---

## Rendering / graphics
- 🐛 **BUG (RAPTOR level):** on the last level (steampunk/industrial map), the active
  falling piece isn't rendered until it's placed — only locked pieces show. Real render
  bug (persists without the unlock mod). Investigate `MobilePiece_*` rendering / why
  this level differs.
- [ ] implement 16:9 widescreen mode; verify hi-res/widescreen across ALL screens
  (intro 3D "N", menus, gameplay, wonders, multiplayer).
- [ ] exercise the graphics settings tab end-to-end (upscaling, vsync).
- [ ] confirm MSAA anti-aliasing actually works.
- [ ] explore implementing custom framerates.

## Controls / input
- [ ] **multiplayer not working** — allow configuring multiple controllers (see also
  MULTI PLAYER greying in `docs/MENU_TREE.md` §3).
- [ ] controls screen has an **unlabeled slider** — identify what it does (seems to
  show the menu controllers) and label it.
- [ ] curate sensible **gamepad** default mappings to game actions (not just keyboard).
- [ ] confirm rotate CW vs CCW direction matches the game (current mapping inferred).
- [ ] rumble / haptics if the game uses the Rumble Pak.
- [ ] separate menu vs gameplay controls (context-interpret buttons — arrows navigate
  menus, rotate in gameplay); build as a built-in native remap.

## UI / fonts
- [ ] replace the placeholder primary UI font (`primary.ttf` is a renamed Ubuntu
  placeholder) with a real display face; add a bold weight for headers.
- [ ] ship a real icon/emoji face if needed (NotoEmoji is the only real extra face;
  promptfont is the real controller-glyph font).
- [ ] review menu transition/navigation animations — ensure smooth, not janky/missing.

## Audio
- [ ] verify Windows audio actually outputs (forced-pulseaudio guarded to Linux).
- [ ] confirm the buzz fix holds across all music/SFX on Linux (device buffer 256).
- [ ] avoid the SDL device close/reopen on `set_frequency` when the rate is unchanged
  (glitch on the 48000→36000 switch at boot).
- [ ] consider resampling to a fixed device rate for robustness across hardware.
- [ ] remove debug audio instrumentation before release (`TNT_AUDIO_DUMP`, per-200-call
  queue-stats logging, the "buffer=N frames" line).

## Windows / platform
- [ ] full runtime pass: controller input, ROM picker (native Win32 dialog), saves,
  full gameplay.
- [ ] app icon (`.ico` + `.rc`).
- [ ] crash diagnostics on Windows (current backtrace handler is Linux-only).
- [ ] with `/SUBSYSTEM:WINDOWS` there's no console — surface errors (log file / message
  box) instead of silently exiting.
- [ ] optional: code signing to reduce SmartScreen friction.

## Mods
- [ ] the "Skip Intro" rework (top of file).
- [ ] default mod that hides "transfer name" and "dump lines to game pak" options in
  the Data menu.
- [ ] HD texture-pack mod (not enabled by default).
- [ ] explore extracting all texture files from the game data (dump ROM textures →
  enables the HD pack + asset understanding).
- [ ] finish the **song/playlist selector** (the old map-select mod is now a basic
  Music Track Selector that pokes `g_currentSong` @0x8011E4F8 each `Scene_Update`).
  Verify the per-frame poke actually switches the *playing* track (may be mistimed);
  the robust form is a `RECOMP_PATCH` of `PFGFX_SelectAndStartMusic` overriding `a0`
  at the selection point. List all songs; disable the in-game "select music" option
  when enabled. (Needs real audio to verify — WSLg often on dummy.)
- [ ] **open-mods-folder button** does nothing under WSLg (no xdg-open/Windows shell
  bridge). Wire per-OS folder open (xdg-open / explorer.exe / open), or hide where
  unsupported.
- [ ] EXTEND skip-intro dropdown targets (if keeping the enum form): Off/Attract work;
  Publisher didn't skip (wrong scene value); Start-menu/Menu **crash** (forcing
  `g_currentScene=4` bypasses hub setup → the segfault below). Also add skip-straight-
  into Sprint / Marathon. Blocked on the crash + finding correct scene/mode values.

## Packaging / release
- [ ] cut a release: Linux (tar.gz) + Windows (zip), once Windows runtime/audio verified.
- [ ] flatpak for Fedora COSMIC Atomic (sandbox + portal file picker).
- [ ] optional AppImage for Linux (single-file), alongside tar.gz.
- [ ] macOS build (deferred).
- [ ] README: Windows download/run instructions + per-OS requirements.
- [ ] re-verify the repo contains **no ROM / game data** before each release.

## Code cleanup / release hygiene
- [ ] strip `TRACE()` / stray fprintf diagnostics from `src/main.cpp`.
- [ ] review the `n_aspMain_safe` RSP wrapper (belt-and-suspenders) — keep or trim.

## RE / naming follow-ups (living-names practice)
- 🔵 `g_gameStartFlag` @0x8011EAED → likely `g_versusModeFlag` (`Scene_SingleStartGame`
  writes 2=vs / 0=single). Needs more xref evidence. `docs/MENU_TREE.md` §9.
- 🔵 SINGLE-screen spinner value-objects (OPPONENT/GAME lists) — runtime BSS
  (`item+0x30`: count @+0x00, index @+0x3B0); enumerate the OFF/EASY/… and MARATHON/
  SPRINT/ULTRA/… sets + modes beyond index 2 via `tools/e2e/`.
- 🔵 Profile-roster storage stride / max count — assembled at runtime from Pfs
  enumeration + synthetic GUEST/NEW-NAME ends; pin with the E2E RAM harness.
- 🔵 Variable naming residue (~13–24% of datasyms) is parked at the honest **static**
  ceiling — heap-struct interior fields + ROM `.rodata` strings can't be named from
  code alone. Would need runtime/behavioral RE. See `docs/naming-parking-list.md`.

---

## In progress / partially done
- 🚧 **Scene-4 "start without setup" SIGSEGV** — ROOT CAUSE FOUND; guard mod shipped
  but proven INSUFFICIENT. Chain: `MenuHub_StartPlaying`(0x80090E08) → `Scene_Init`
  (0x8009D5E4) → `Scene_SetupCameraAndObjects`(0x800A0228) → `Scene_SetupObjectMatrices`
  (0x8009EED4), which writes 16 matrices into `g_sceneObjSlotMatrixBuf`@0x80129200
  (null when scene 4 is entered without the resource load, e.g. attract-demo game
  start / forcing the scene byte) → PROT_NONE guard region → SIGSEGV. `mods/scene-
  crash-guard` clears the first crash but E2E showed it MOVES to
  `Scene_SetupObjectRenderState+0xc5d` (multiple uninitialized pointers). **Real fix =
  prevent the bad scene entry / run the resource-load path.** Reproduces deterministically
  via `tools/e2e/test_crash_guard.py`. See `tnt-scene-and-crash-re` memory. *(Note:
  starting a game the NORMAL way does NOT crash — this is only forced/attract entry.)*
- 🚧 **Configure mods without hand-relaunching** — DONE via the in-game "Restart"
  button (re-execs with `TNT_NO_AUTOBOOT` → launcher → toggle mods → Start Game). Still
  open: a true IN-PLACE return-to-launcher (tear down the game thread without a full
  process restart) + a Windows re-exec path (Linux-only `/proc/self/exe` today).

---

## Reference — executed plans (not active TODO)
- `docs/recompiled-hierarchy-plan.md` — **EXECUTED** (2026-07-19): 1430 funcs
  re-bucketed into 54 subsystem files.
- `docs/naming-campaign-plan.md` — the naming methodology (executed).
- `docs/naming-parking-list.md` — the honest naming residue (parked; needs runtime
  tracing). Functions 100% named; variables ~87% (static ceiling).
- `docs/MENU_TREE.md` + `docs/MENU_OBSERVED.md` — front-end code map + ground truth.
- `docs/cheat-codes.md` — RE'd cheat/easter-egg names.

---

## Done
- ✅ **Controller-Pak (osPfs) HLE** — crash fixed (nested `509f428`, sign-extend guest
  pointers), mem-pak relocated to the config dir (`d1a1a66`), persistence verified
  (`tests/test_mempak.py`). One documented gap: interactive create-profile isn't
  UI-automatable in WSLg (occluded screenshots + unreliable blind nav). (2026-08-08)
- ✅ **Python unit-test library (pytest), mod-isolated, headless** — `tests/` +
  `tests/run.sh` (project `.venv-test`); isolates HOME/XDG per test, explicit per-test
  mod selection (default none), seeds known-good graphics. 9 tests green. Spec:
  [`unit-test-library.md`](unit-test-library.md). (2026-08-08)
- ✅ **Front-end menu fully mapped + code-bound** (`docs/MENU_TREE.md`,
  `docs/MENU_OBSERVED.md`); symbol refinements committed. (2026-08-08)
- ✅ **E2E harness** (launch / wait-on-RAM / assert / inject input / screenshot) —
  `tools/e2e/`. (2026-08-08)
- ✅ Name-entry / create-profile screen found + fully RE'd.
- ✅ Functions 100% named; variables ~87% (honest static ceiling).
- ✅ **App branding pass** — renamed "The New T64ris" (window titles, program/display
  name, packaging, screenshot-harness title match). Data-dir key + ROM header kept to
  avoid orphaning saves / breaking ROM detection.
- ✅ **Map-selector investigation** — RESOLVED: 0x8011E4F8 = `g_currentSong` (music
  index from `Scene_RandRange(0,7)` in `MenuHub_StartPlaying`), NOT the map; there is
  NO discrete map global — the 3D background is procedurally generated each game
  (`Gfx_RandomizeBackgroundGrid`). Mod rewritten as a Music Track Selector.

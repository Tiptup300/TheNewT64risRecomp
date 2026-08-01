# The New T64ris : Recompiled — TODO

// move these to where they should be when you see them.

## Rendering / graphics
- [ ] explor implementing custom framerates
- [ ] confirm ms anti-aliasing actually works
- [ ] implement 16:9 mode
- [ ] exercise the graphics settings tab end-to-end (upscaling, vsync)
- [ ] verify high-res / widescreen across all screens (intro 3D "N", menus, gameplay, wonders, multiplayer)
- [ ] BUG: on the last level (steampunk/industrial map, "RAPTOR"), the active falling piece isn't rendered until it's placed — only locked pieces show. Real render bug (NOT the unlock mod — persists without it). Investigate MobilePiece_* rendering / why this level differs.

## Controls / input
- [ ] multiplayer is not working, allow to configure mutilple controllers
- [ ] in the controls screen there is an unlabeled slider, what does this do, it seems like it shows the menu controllers, but it's unlabeled
- [ ] curate sensible gamepad default mappings to the game actions (not just keyboard)
- [ ] confirm rotate CW vs CCW direction matches the game (current mapping was inferred)
- [ ] rumble / haptics if the game uses the Rumble Pak
- [ ] separate menu vs gameplay controls (interpret buttons by context — arrows navigate menus, rotate in gameplay); build as a built-in native remap

## UI / fonts
- [ ] replace the placeholder primary UI font (primary.ttf is a renamed Ubuntu placeholder) with a real display face; add a bold weight for headers (theme requests bold the single-weight font can't provide)
- [ ] ship a real icon/emoji face if needed (NotoEmoji is the only real extra face; promptfont is now the real controller-glyph font)
- [x] custom window title / app branding pass — app renamed "The New T64ris"
      (window titles, program name, display name, packaging, screenshot-harness
      title match). Data-dir key + ROM header kept as-is to avoid orphaning saves /
      breaking ROM detection.
- [ ] look at the animations when jumping through menus (menu transitions/navigation — check they're smooth and not janky/missing)

## Audio
- [ ] verify Windows audio actually outputs (forced-pulseaudio was guarded to Linux; needs a Windows test)
- [ ] confirm the buzz fix holds across all music/SFX on Linux (SDL device buffer now 256, under the queue floor)
- [ ] avoid the SDL device close/reopen on set_frequency when the rate is unchanged (glitch on the 48000->36000 switch at boot)
- [ ] consider resampling to a fixed device rate for robustness across hardware
- [ ] remove debug audio instrumentation before release (TNT_AUDIO_DUMP, per-200-call queue-stats logging, the "buffer=N frames" line)

## Windows
- [ ] full runtime pass: verify controller input, ROM picker (native Win32 dialog), saves, and full gameplay
- [ ] app icon (.ico + .rc)
- [ ] crash diagnostics on Windows (current backtrace handler is Linux-only)
- [ ] with /SUBSYSTEM:WINDOWS there is no console — surface errors (log file / message box) instead of silently exiting
- [ ] optional: code signing to reduce SmartScreen friction

## Mods
- [ ] add default mod that hides "transfer name" and "dump lines to game pak" menu options in data
- [ ] include a mod thats not enabled by default that does a hd texture pack on the game
- [ ] explore options to extract all texture files from the game data (dump the ROM's textures — enables the HD texture pack + asset understanding)
- [x] map-selector mod — RESOLVED. Two findings: (1) 0x8011E4F8 = g_currentSong
      (the music index picked by Scene_RandRange(0,7) in MenuHub_StartPlaying and
      passed to PFGFX_SelectAndStartMusic), NOT the map. (2) There is NO discrete
      map/background global at all — a dedicated hunt found the 3D background is
      procedurally generated each game (Gfx_RandomizeBackgroundGrid), not chosen
      from ~8 presets. So a map selector isn't possible. Rewrote the mod as a
      "Music Track Selector" that forces g_currentSong by name (config `song`).
- [ ] song/playlist selector — the map-select mod is now a basic Music Track
      Selector (forces g_currentSong each Scene_Update). Still TODO: verify the
      per-frame poke actually switches the *playing* track (may be mistimed); the
      robust form is RECOMP_PATCH of PFGFX_SelectAndStartMusic overriding a0 at the
      selection point. Also: list all songs + disable the in-game "select music"
      option when enabled. (Real audio needed to verify — WSLg often on dummy.)
- [ ] EXTEND skip-intro dropdown targets — currently safe options are Off / Attract (confirmed working). Publisher target didn't skip (wrong scene value); Start menu / Menu targets CRASH (forcing scene byte g_currentScene 0x800CFEE8=4 bypasses the hub's setup -> Scene_SetupObjectMatrices segfault). Also add: skip straight into Single-Game Sprint and Single-Game Marathon. All of these are blocked on the crash below + finding the correct scene/mode values (needs user testing).
- [~] FIX crash — ROOT CAUSE FOUND + guard mod shipped (experimental, needs runtime test).
      Chain: MenuHub_StartPlaying (0x80090E08) -> Scene_Init (0x8009D5E4) ->
      Scene_SetupCameraAndObjects (0x800A0228) -> Scene_SetupObjectMatrices (0x8009EED4).
      It writes 16 matrices into g_sceneObjSlotMatrixBuf @0x80129200 (scene-obj table
      0x801290D0 + 0x130), which Scene_AllocObjectBuffers allocs on the normal load
      path and Scene_Init frees+nulls at teardown. Entering scene 4 without the load
      (attract-demo game start) leaves it null -> store folds into the recomp's
      PROT_NONE guard region -> SIGSEGV. Genuine game bug (not a masking artifact).
      GUARD: mods/scene-crash-guard (RECOMP_HOOK on Scene_SetupObjectMatrices, points
      the null ptr at unused RAM 0x80900000; acts only in the null/broken state).
      STILL OPEN: verify the guard at runtime (clean display needed); the real fix is
      to route scene-4 entry through the resource-load path. RECOMP_PATCH can't be used
      (replaces the whole function, no delegate-to-original). See tnt-scene-and-crash-re memory.
- [ ] open-mods-folder button does nothing under WSLg (no xdg-open/Windows shell bridge). Wire it to the right per-OS folder-open (xdg-open / explorer.exe / open) or hide it where unsupported.
- [ ] song/playlist selector mod — list all available songs and let the user choose which songs play; when enabled, disable the in-game Audio "select music" menu option
- [~] configure mods without hand-relaunching — DONE via the in-game "Restart" button (config-menu header, shown while playing): re-execs the app with TNT_NO_AUTOBOOT so it lands at the launcher to toggle mods, then Start Game again. Still open: a true IN-PLACE return-to-launcher (tear down the game thread without a full process restart) + a Windows re-exec path (Linux-only /proc/self/exe today).

## Packaging / release
- [ ] cut a release with both Linux (tar.gz) + Windows (zip) once Windows runtime/audio are verified
- [ ] flatpak for Fedora COSMIC Atomic (sandbox + portal file picker)
- [ ] optional: AppImage for Linux (single-file), alongside the tar.gz
- [ ] macOS build (deferred)
- [ ] README: Windows download/run instructions + per-OS requirements

## Code cleanup / release hygiene
- [ ] strip TRACE() / stray fprintf diagnostics from src/main.cpp
- [ ] review the n_aspMain_safe RSP wrapper (belt-and-suspenders) — keep or trim
- [ ] license + credits pass (harness license, dependency licenses, tnt-splat credit)
- [ ] re-verify the repo contains no ROM / game data before each release

# The New Tiptris : Recompiled — TODO

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
- [ ] custom window title / app branding pass
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
- [ ] FIX map-selector mod — built but non-functional and MISTARGETED. It pokes 0x8011E4F8, but RE shows that byte is the SONG/music index (0..7), not the map: func_80090E08 fills it via func_800A35EC(0,7) then passes it straight to FUN_027BF0_check_music_settings_and_play (0x80061B18). The actual map/background global is still unidentified — need to find where the game stores/reads the background index (grep the wonder/background renderer + attract setup), then force it at its consume site. Verify with the user driving gameplay (no headless input).
- [ ] song/playlist selector groundwork: 0x8011E4F8 = song index (0..7), consumed by FUN_027BF0_check_music_settings_and_play in func_80090E08. A RECOMP_HOOK on FUN_027BF0 overriding ctx->r4 (a0 = song index) is the correct, correctly-timed way to force the track. (Real audio needed to verify — WSLg is on dummy.)
- [ ] EXTEND skip-intro dropdown targets — currently safe options are Off / Attract (confirmed working). Publisher target didn't skip (wrong scene value); Start menu / Menu targets CRASH (forcing scene byte 0x800CFEE8=4 bypasses the hub's setup -> func_8009EED4 segfault). Also add: skip straight into Single-Game Sprint and Single-Game Marathon. All of these are blocked on the func_8009EED4 crash + finding the correct scene/mode values (needs user testing).
- [ ] FIX crash: func_80090E08 -> func_8009D5E4 -> func_800A0228 -> func_8009EED4+0x128 (jal guTranslate on a bad scene-object pointer). Triggered whenever the menu-hub / start-playing scene (byte 0x800CFEE8 = 4) is entered without its normal setup — e.g. skip-intro forcing scene 4, or the attract demo starting a game. This is the central blocker for skip-to-menu and reliable gameplay boot. Needs RE of func_8009EED4's scene-object init.
- [ ] open-mods-folder button does nothing under WSLg (no xdg-open/Windows shell bridge). Wire it to the right per-OS folder-open (xdg-open / explorer.exe / open) or hide it where unsupported.
- [ ] song/playlist selector mod — list all available songs and let the user choose which songs play; when enabled, disable the in-game Audio "select music" menu option
- [ ] a way to configure mods without relaunching — mods only toggle at the launcher, but auto-start skips it and in-game Quit exits the app (needs an in-game "return to launcher"/stop-game, or launch with TNT_NO_AUTOBOOT)

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

#include "modding.h"
#include "recompconfig.h"

// Song / music-track selector.
//
// CORRECTION (RE-confirmed): the byte at 0x8011E4F8 that this mod forces is the
// SONG index, NOT the map/background. In the scene-setup path a rand(0,7) result
// is stored there and then read back and passed to PFGFX_SelectAndStartMusic
// (the music-start routine, a0 = song index). It is the data symbol
// `g_currentSong`. The old "map selector" framing was a misunderstanding — this
// mod forces the music track. The real map/background global is still
// unidentified (open TODO), so a true map selector isn't possible yet.
//
// We reference the game variable BY NAME via the mod's data_reference_syms_files
// (cleaner and safer than a raw pointer — the mod recompiler resolves the name to
// the game address), matching the wonders-rebalance mod's pattern.
//
// CAVEAT (timing): this forces g_currentSong every Scene_Update. If the song is
// only selected/started once per game (not re-read per frame), forcing the byte
// here may not switch the *currently playing* track — verify in-game and, if
// needed, retarget to a RECOMP_PATCH of PFGFX_SelectAndStartMusic overriding the
// song argument at the actual selection point.
extern volatile unsigned char g_currentSong;

RECOMP_HOOK("Scene_Update") void tnt_force_song(void) {
    unsigned long sel = recomp_get_config_u32("song");   // 0 = Random/off, 1..8 => song 0..7
    if (sel >= 1 && sel <= 8) {
        g_currentSong = (unsigned char)(sel - 1);
    }
}

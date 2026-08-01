# The New T64ris — function index

Auto-generated from `tnt.syms.toml` (1587 symbols). Grouped by subsystem (prefix before the first `_`).
`calls` = how many other functions this one calls (its out-degree) — **high = orchestrator, 0 = leaf/helper**.
Sorted within each group by address. `*` = has a recompiled C body.

## Minos  (30 funcs, top out-degree 9)

| function | addr | size | calls |
|---|---|---|---|
| `Minos_8006f260_eightliner_calls_8007641c_4_times` | 0x8006F260 | 0xA0 | 4 |
| `Minos_8006f300_eightliner_calls_80076458_4_times` | 0x8006F300 | 0x9C | 4 |
| `Minos_8006f4b4_thirtyliner_interesting` | 0x8006F4B4 | 0x334 | 2 |
| `Minos_8006f7f0_sets_struct_0_to_0x11` | 0x8006F7F0 | 0x1A4 | 0 |
| `Minos_8006f994_sets_struct_0_to_0x23` | 0x8006F994 | 0x2F8 | 0 |
| `Minos_8006fc8c_twentyfive_liner` | 0x8006FC8C | 0x1AC | 0 |
| `Minos_Mino_Render` | 0x8006FE38 | 0x4AC | 9 |
| `Minos_800702e4_nineliner` | 0x800702E4 | 0xB4 | 2 |
| `Minos_80070398_fourteenliner` | 0x80070398 | 0x148 | 1 |
| `Minos_800704e0_threeliner_sets_0x130` | 0x800704E0 | 0x48 | 1 |
| `Minos_80070528_Morph` | 0x80070528 | 0x2F0 | 4 |
| `Minos_80070818_oneliner_sets_arg0_0x130_to_arg1` | 0x80070818 | 0x8 | 0 |
| `Minos_80070820_fiveliner_sets_arg0_2_4_8_12_to_arg1` | 0x80070820 | 0x40 | 0 |
| `Minos_80070860_fortyliner` | 0x80070860 | 0x178 | 0 |
| `Minos_800709d8_threeliner_sets_arg0_1c_1e_1d` | 0x800709D8 | 0x14 | 0 |
| `Minos_800709EC` | 0x800709EC | 0x48 | 0 |
| `Minos_80070a34_twentyliner` | 0x80070A34 | 0x20C | 0 |
| `Minos_80070c40_twoliner_set_OR_1` | 0x80070C40 | 0x30 | 0 |
| `Minos_80070c70_threeliner_set_OR_8` | 0x80070C70 | 0x48 | 0 |
| `Minos_80070cb8_threeliner_set_OR_4` | 0x80070CB8 | 0x48 | 0 |
| `Minos_SetScale` | 0x80070D00 | 0x30 | 0 |
| `Minos_SetAlpha` | 0x80070D30 | 0x10 | 0 |
| `Minos_Init` | 0x80070D40 | 0x180 | 7 |
| `Minos_Deinit_doesnothing` | 0x80070EC0 | 0x8 | 0 |
| `Minos_BeginRender` | 0x80070EC8 | 0xA8 | 1 |
| `Minos_EndRender` | 0x80070F70 | 0x68 | 0 |
| `Minos_80070fd8_notcalled_q` | 0x80070FD8 | 0x74 | 0 |
| `Minos_8007104c_fiveliner_nuts` | 0x8007104C | 0xB4 | 0 |
| `Minos_80071100_fiveliner_nuts2` | 0x80071100 | 0x6C | 0 |
| `Minos_SetVtxTransform` | 0x8007116C | 0x74 | 0 |

## Audio2  (29 funcs, top out-degree 17)

| function | addr | size | calls |
|---|---|---|---|
| `Audio2_AllocDcmHeader` | 0x80085F8C | 0x1AC | 7 |
| `Audio2_80086138_largeliner_channels` | 0x80086138 | 0x37C | 11 |
| `Audio2_AllocDcmScratch8` | 0x800864B4 | 0xFC4 | 17 |
| `Audio2_80087478_oneliner_calls_fun` | 0x80087478 | 0x34 | 1 |
| `Audio2_800874ac_sevenliner` | 0x800874AC | 0xC0 | 1 |
| `Audio2_8008756c_eightliner` | 0x8008756C | 0x78 | 1 |
| `Audio2_80087618_fourteenliner_loops_256t` | 0x80087618 | 0x158 | 1 |
| `Audio2_80087770_oneliner_turn_on` | 0x80087770 | 0xC | 0 |
| `Audio2_8008777c_oneliner_turn_off` | 0x8008777C | 0x8 | 0 |
| `Audio2_GFXDone_SendPlayMessage` | 0x80087784 | 0x88 | 3 |
| `Audio2_8008780c_sixliner_v1` | 0x8008780C | 0x70 | 4 |
| `Audio2_8008787c_sixliner_v2` | 0x8008787C | 0x74 | 4 |
| `Audio2_80088ba4_fiveliner` | 0x80088BA4 | 0x70 | 2 |
| `Audio2_GFXDone_SendStopMessage` | 0x80088C14 | 0x70 | 4 |
| `Audio2_80088c84_largeliner` | 0x80088C84 | 0x3AC | 3 |
| `Audio2_80089030_hugeliner_SFX_Channel` | 0x80089030 | 0xD2C | 9 |
| `Audio2_80089d5c_twentyfourliner_sendstop` | 0x80089D5C | 0x180 | 4 |
| `Audio2_80089edc_thirtyfourliner_loops` | 0x80089EDC | 0x1AC | 0 |
| `Audio2_Play_SFX_Bank_Channel` | 0x8008A088 | 0x540 | 4 |
| `Audio2_Play_SFX` | 0x8008A5C8 | 0x54 | 1 |
| `Audio2_8008a61c_twelveliner` | 0x8008A61C | 0xD0 | 1 |
| `Audio2_8008a6ec_nineliner` | 0x8008A6EC | 0xD4 | 0 |
| `Audio2_8008a7c0_fiveliner` | 0x8008A7C0 | 0x4C | 0 |
| `Audio2_8008bf58_eightliner` | 0x8008BF58 | 0xBC | 3 |
| `Audio2_8008c014_tenliner` | 0x8008C014 | 0xCC | 5 |
| `Audio2_8008c0e0_oneliner_arg0_math` | 0x8008C0E0 | 0x24 | 0 |
| `Audio2_8008c104_oneliner_arg0_math_2` | 0x8008C104 | 0x2C | 0 |
| `Audio2_8008c130_oneliner_arg0_math_3` | 0x8008C130 | 0x2C | 0 |
| `Audio2_SFX_Debug_Print` | 0x8008C15C | 0x194 | 14 |

## BoardP  (26 funcs, top out-degree 10)

| function | addr | size | calls |
|---|---|---|---|
| `BoardP_8006d3c0_fourliner` | 0x8006D3C0 | 0x90 | 2 |
| `BoardP_8006d450_fourteenliner_pf_logic_cell_loops` | 0x8006D450 | 0xB0 | 2 |
| `BoardP_8006d500_tenliner_pf_logic_cells_loops` | 0x8006D500 | 0xBC | 3 |
| `BoardP_8006d5bc_sixliner_calls_UpdateQueue_AddEntry` | 0x8006D5BC | 0xB8 | 5 |
| `BoardP_8006d674_tenliner_alloc_fallingcubes` | 0x8006D674 | 0xB4 | 3 |
| `BoardP_8006d728_checkAndSetSurroundingCells` | 0x8006D728 | 0x1E8 | 9 |
| `BoardP_8006d910_sevenliner_loopThroughConnectedMinos` | 0x8006D910 | 0x88 | 3 |
| `BoardP_8006d998_sixliner_loops` | 0x8006D998 | 0x40 | 0 |
| `BoardP_8006d9d8_calls_pf_xy_to_logic_cell_loops` | 0x8006D9D8 | 0xB4 | 1 |
| `BoardP_8006da8c_sixliner_sets_stuff_9` | 0x8006DA8C | 0x64 | 1 |
| `BoardP_8006daf0_sixliner_sets_stuff_7` | 0x8006DAF0 | 0x64 | 1 |
| `BoardP_UpdateQueueEntry_Update` | 0x8006DB54 | 0x64 | 2 |
| `BoardP_8006dbb8_eightliner_calls_UPDQueueEntry_Update_loops` | 0x8006DBB8 | 0x64 | 1 |
| `BoardP_UpdateQueue_AddEntry` | 0x8006DC1C | 0xA4 | 1 |
| `BoardP_8006dcc0_twoliner_sets_to_600_0` | 0x8006DCC0 | 0x10 | 0 |
| `BoardP_8006dcd0_eightliner_loops_upto_19_times_increment` | 0x8006DCD0 | 0x4C | 1 |
| `BoardP_8006dd1c_eightliner_loops_upto_19_times_decrement` | 0x8006DD1C | 0x48 | 1 |
| `BoardP_8006dd64_check_for_nonempty_cell_downwards` | 0x8006DD64 | 0x6C | 0 |
| `BoardP_8006ddd0_check_for_nonempty_cell_upwards` | 0x8006DDD0 | 0x70 | 0 |
| `BoardP_8006de40_nineliner` | 0x8006DE40 | 0xF8 | 4 |
| `BoardP_8006df38_twentyfiveliner_3_loops` | 0x8006DF38 | 0x1B0 | 3 |
| `BoardP_8006e288_adds_8_entries_and_swaps_cubes` | 0x8006E288 | 0xC4 | 10 |
| `BoardP_IsPositionEmpty` | 0x8006E498 | 0x50 | 1 |
| `BoardP_IsPointEmpty` | 0x8006E4E8 | 0xF8 | 4 |
| `BoardP_playfield_xy_to_logic_cell_struct_8006e5e0` | 0x8006E5E0 | 0x6C | 0 |
| `BoardP_8006e64c_calls_UpdateQueue_AddEntry` | 0x8006E64C | 0xA8 | 1 |

## Game  (24 funcs, top out-degree 30)

| function | addr | size | calls |
|---|---|---|---|
| `Game_SetGlobalPointers` | 0x80050520 | 0xFC | 0 |
| `Game_calls_SETGP_magic_7` | 0x80050AC4 | 0x90 | 3 |
| `Game_SetAlpha` | 0x80050B54 | 0x154 | 2 |
| `Game_isGameWinner` | 0x80050E60 | 0x1CC | 7 |
| `Game_countWinners` | 0x8005102C | 0x78 | 1 |
| `Game_800510a4_eightliner` | 0x800510A4 | 0x60 | 0 |
| `Game_80051104_sevenliner_num_players` | 0x80051104 | 0x60 | 0 |
| `Game_game_over_related` | 0x80051164 | 0x88 | 2 |
| `Game_80051320_fiveliner` | 0x80051320 | 0x9C | 3 |
| `Game_800513bc_tenliner_num_players` | 0x800513BC | 0xA8 | 2 |
| `Game_QueryGameOver` | 0x80051464 | 0x194 | 8 |
| `Game_800515f8_twoliner` | 0x800515F8 | 0x20 | 0 |
| `Game_80051618_twentyliner` | 0x80051618 | 0x178 | 3 |
| `Game_80051790_twelveliner` | 0x80051790 | 0xF0 | 1 |
| `Game_80051880_sixliner` | 0x80051880 | 0x70 | 1 |
| `Game_ControllerRepeat_Update` | 0x800518F0 | 0xC4 | 2 |
| `Game_800519b4_thirtyliner` | 0x800519B4 | 0x1F4 | 3 |
| `Game_Update` | 0x80051BA8 | 0x108 | 7 |
| `Game_line_782_game_c` | 0x80051CB0 | 0x280 | 11 |
| `Game_render_stuff_line_850` | 0x80051F30 | 0x160 | 12 |
| `Game_80052090_calls_3_functions` | 0x80052090 | 0x40 | 3 |
| `Game_800520d0_calls_cubetiles_init` | 0x800520D0 | 0x44 | 3 |
| `Game_Init` | 0x80052114 | 0x45C | 30 |
| `Game_Deinit` | 0x80052570 | 0x220 | 23 |

## KeySpin  (23 funcs, top out-degree 12)

| function | addr | size | calls |
|---|---|---|---|
| `KeySpin_8006b3b0_tenliner_nested_loop_10t` | 0x8006B3B0 | 0xA4 | 3 |
| `KeySpin_8006b454_fourliner_sets_arg0_struct` | 0x8006B454 | 0x24 | 0 |
| `KeySpin_8006b478_eightliner` | 0x8006B478 | 0xC4 | 1 |
| `KeySpin_8006b53c_uses_pf_logic_cell_loops_10t_1` | 0x8006B53C | 0xCC | 2 |
| `KeySpin_8006b608_uses_pf_logic_cell_loops_10t_2` | 0x8006B608 | 0xAC | 2 |
| `KeySpin_8006b6b4_twelveliner_ifs_elses_1` | 0x8006B6B4 | 0x100 | 2 |
| `KeySpin_8006b7b4_twelveliner_ifs_elses_2` | 0x8006B7B4 | 0x104 | 2 |
| `KeySpin_8006b8b8_fiveliner_calls_b6b4_b7b4` | 0x8006B8B8 | 0x80 | 2 |
| `KeySpin_8006b938_thirteenliner_sets_arg0_struct` | 0x8006B938 | 0xEC | 2 |
| `KeySpin_8006ba24_thirtysixliner_sets_arg0_struct` | 0x8006BA24 | 0x268 | 1 |
| `KeySpin_8006bc8c_twelveliner_uses_pf_logic_cell_1` | 0x8006BC8C | 0x108 | 1 |
| `KeySpin_8006bd94_twelveliner_uses_pf_logic_cell_2` | 0x8006BD94 | 0x108 | 1 |
| `KeySpin_8006be9c_fifteenliner_uses_pflcell_loopts_10t` | 0x8006BE9C | 0xF4 | 2 |
| `KeySpin_8006BF90` | 0x8006BF90 | 0x10C | 3 |
| `KeySpin_8006c09c_tenliner_loops_lcv_arg0_unk58` | 0x8006C09C | 0xC4 | 2 |
| `KeySpin_8006c160_twentyfiveliner_loops_lcv_arg0_unk58` | 0x8006C160 | 0x1B8 | 1 |
| `KeySpin_InitVPulse` | 0x8006C318 | 0x2AC | 8 |
| `KeySpin_8006c5c4_sevenliner_sets_arg0_struct_1` | 0x8006C5C4 | 0x80 | 1 |
| `KeySpin_8006c644_fourliner_sets_arg0_struct` | 0x8006C644 | 0x4C | 1 |
| `KeySpin_8006c690_sevenliner_sets_arg0_struct_2` | 0x8006C690 | 0x80 | 1 |
| `KeySpin_8006c710_medliner_interesting_calls_pf_xy_to_lgc` | 0x8006C710 | 0x380 | 12 |
| `KeySpin_8006ca90_nineliner_sets_arg0_struct` | 0x8006CA90 | 0x80 | 1 |
| `KeySpin_8006cb10_switch_arg0_2_to_8_playsfx_35` | 0x8006CB10 | 0x170 | 11 |

## CurrentPiece  (22 funcs, top out-degree 15)

| function | addr | size | calls |
|---|---|---|---|
| `CurrentPiece_80066920_sixteenliner` | 0x80066920 | 0x188 | 9 |
| `CurrentPiece_80066cc8_fourliner` | 0x80066CC8 | 0x44 | 1 |
| `CurrentPiece_80066d0c_calls_pf_xy_2_struct_loops4times_retbool` | 0x80066D0C | 0x80 | 2 |
| `CurrentPiece_80066d8c_maybeRotCkw_retbool` | 0x80066D8C | 0x148 | 1 |
| `CurrentPiece_80066ed4_maybeRotCCkw_retbool` | 0x80066ED4 | 0x14C | 1 |
| `CurrentPiece_80067020_twoliner_retbool` | 0x80067020 | 0x3C | 0 |
| `CurrentPiece_8006705c_twoliner_setstuff_0x30_0x04` | 0x8006705C | 0x1C | 0 |
| `CurrentPiece_80067078_twelveliner_retbool` | 0x80067078 | 0xE4 | 5 |
| `CurrentPiece_8006715c_twelveliner_plays_SFX` | 0x8006715C | 0xF8 | 4 |
| `CurrentPiece_80067254_twelveliner_plays_SFX` | 0x80067254 | 0xF8 | 4 |
| `CurrentPiece_8006734c_thirtyliner_looks_interesting` | 0x8006734C | 0x25C | 10 |
| `CurrentPiece_800675a8_fiveliner_loops4times` | 0x800675A8 | 0x5C | 1 |
| `CurrentPiece_80067604_fourteenliner_loops4times` | 0x80067604 | 0xA8 | 3 |
| `CurrentPiece_800676ac_fourliner_looper` | 0x800676AC | 0x5C | 2 |
| `CurrentPiece_80067708_eightliner_interesting_1_2_8_10` | 0x80067708 | 0xB0 | 4 |
| `CurrentPiece_800677b8_twohundredliner_doit_last` | 0x800677B8 | 0x408 | 9 |
| `CurrentPiece_80067bc0_sixliner_loops4times` | 0x80067BC0 | 0x5C | 0 |
| `CurrentPiece_80067c1c_fifteenliner_loops3times` | 0x80067C1C | 0x100 | 1 |
| `CurrentPiece_80067d1c_twoliner` | 0x80067D1C | 0x34 | 1 |
| `CurrentPiece_Render` | 0x80067D50 | 0x88 | 3 |
| `CurrentPiece_80067dd8_big_fiftyliner` | 0x80067DD8 | 0x2B8 | 15 |
| `CurrentPiece_80068090_oneliner_sets_0x538_to_1` | 0x80068090 | 0x10 | 0 |

## gamefinish  (21 funcs, top out-degree 7)

| function | addr | size | calls |
|---|---|---|---|
| `gamefinish_80052AA0_tenliner` | 0x80052AA0 | 0x90 | 0 |
| `gamefinish_80052B30_tenliner` | 0x80052B30 | 0xB4 | 4 |
| `gamefinish_c_line_127` | 0x80052BE4 | 0x140 | 1 |
| `gamefinish_80052D24_oneliner` | 0x80052D24 | 0x1C | 0 |
| `gamefinish_80052D40_doesnothing` | 0x80052D40 | 0x8 | 0 |
| `gamefinish_80052D48_twoliner` | 0x80052D48 | 0x14 | 0 |
| `gamefinish_magic_number_180_sprint_twoliner` | 0x80052D5C | 0x14 | 0 |
| `gamefinish_80052D70_twoliner` | 0x80052D70 | 0x1C | 0 |
| `gamefinish_80052D8C_nevercalled` | 0x80052D8C | 0x14 | 0 |
| `gamefinish_80052DA0_oneliner` | 0x80052DA0 | 0xC | 0 |
| `gamefinish_80052DAC_read_playfield_logic_cell` | 0x80052DAC | 0x190 | 4 |
| `gamefinish_80052F3C_eightliner` | 0x80052F3C | 0x8C | 1 |
| `gamefinish_80052FC8_eightliner` | 0x80052FC8 | 0x78 | 1 |
| `gamefinish_c_line_383` | 0x80053040 | 0x240 | 7 |
| `gamefinish_80053280_twoliner` | 0x80053280 | 0x5C | 1 |
| `gamefinish_800532DC_nevercalled` | 0x800532DC | 0x8 | 0 |
| `gamefinish_something2` | 0x800532E4 | 0xAC | 2 |
| `gamefinish_80053390_fiveliner` | 0x80053390 | 0x70 | 2 |
| `gamefinish_80053400_fiveliner` | 0x80053400 | 0x4C | 1 |
| `gamefinish_8005344C_fiveliner` | 0x8005344C | 0x58 | 3 |
| `gamefinish_800534A4_fiveliner` | 0x800534A4 | 0x5C | 3 |

## wonders1  (20 funcs, top out-degree 37)

| function | addr | size | calls |
|---|---|---|---|
| `wonders1_80043810_eightliner` | 0x80043810 | 0x98 | 1 |
| `wonders1_800438a8_mediumliner_loop` | 0x800438A8 | 0x3D4 | 12 |
| `wonders1_80043c7c_thirtyliner_loop` | 0x80043C7C | 0x25C | 10 |
| `wonders1_80043ed8_thirtyliner_loop` | 0x80043ED8 | 0x244 | 8 |
| `wonders1_8004411c_tenliner_loop` | 0x8004411C | 0xFC | 2 |
| `wonders1_80044218_tenliner_loop` | 0x80044218 | 0xE0 | 3 |
| `wonders1_checks_num_wonders_completed_q` | 0x800442F8 | 0x12C | 7 |
| `wonders1_80044424_threeliner` | 0x80044424 | 0x40 | 1 |
| `wonders1_80044464_threeliner` | 0x80044464 | 0x40 | 1 |
| `wonders1_case6_calls_music_magic` | 0x800444A4 | 0x138 | 12 |
| `wonders1_800445dc_calls_4_funcs` | 0x800445DC | 0x4C | 4 |
| `wonders1_80044628_eightliner` | 0x80044628 | 0x84 | 3 |
| `wonders1_800446ac_eightliner` | 0x800446AC | 0x9C | 0 |
| `wonders1_hall_or_exit` | 0x80044748 | 0x788 | 37 |
| `wonders1_display_complete_message` | 0x80044ED0 | 0x2C0 | 11 |
| `wonders1_finale_or_hall` | 0x80045190 | 0x42C | 17 |
| `wonders1_800455bc_inc_won_compl_q` | 0x800455BC | 0x3AC | 17 |
| `wonders1_something_hall_or_exit_case` | 0x80045968 | 0x274 | 24 |
| `wonders1_anim_related` | 0x80045BDC | 0xC0 | 5 |
| `wonders1_calls_music_400x300_magic` | 0x80045C9C | 0x1B4 | 11 |

## FrameAct  (18 funcs, top out-degree 8)

| function | addr | size | calls |
|---|---|---|---|
| `FrameAct_set_state` | 0x80053670 | 0x14 | 0 |
| `FrameAct_80053684_threeliner` | 0x80053684 | 0x38 | 1 |
| `FrameAct_calls_increment_game_time_seconds2` | 0x800536BC | 0xA4 | 2 |
| `FrameAct_80053760_mediumliner` | 0x80053760 | 0x108 | 3 |
| `FrameAct_80053868_twentyliner` | 0x80053868 | 0xCC | 3 |
| `FrameAct_80053934_tenliner` | 0x80053934 | 0xB0 | 2 |
| `FrameAct_line_253` | 0x800539E4 | 0xCC | 5 |
| `FrameAct_NextPieces_Update` | 0x80053AB0 | 0xD4 | 6 |
| `FrameAct_calls_gamefinish_something2` | 0x80053B84 | 0x90 | 2 |
| `FrameAct_calls_gamefinish_something` | 0x80053C14 | 0x5C | 1 |
| `FrameAct_ScheduleEvents` | 0x80053C70 | 0x150 | 8 |
| `FrameAct_Render` | 0x80053DC0 | 0x38 | 1 |
| `FrameAct_Init` | 0x80053DF8 | 0x78 | 1 |
| `FrameAct_Deinit` | 0x80053E70 | 0x30 | 1 |
| `FrameAct_80053EA0_threeliner` | 0x80053EA0 | 0x24 | 0 |
| `FrameAct_80053EC4_tenliner` | 0x80053EC4 | 0x7C | 1 |
| `FrameAct_80053F40_oneliner` | 0x80053F40 | 0x8 | 0 |
| `FrameAct_Deinit_doesnothing` | 0x80053F48 | 0x8 | 0 |

## Multisquare  (18 funcs, top out-degree 9)

| function | addr | size | calls |
|---|---|---|---|
| `Multisquare_8006a050_extralarge_manyloops_interesting` | 0x8006A050 | 0x39C | 9 |
| `Multisquare_8006a3ec_twoliner` | 0x8006A3EC | 0x24 | 0 |
| `Multisquare_8006a410_fourliner` | 0x8006A410 | 0x6C | 1 |
| `Multisquare_pGetColor` | 0x8006A47C | 0x70 | 1 |
| `Multisquare_8006a6bc_oneliner_calls_fun` | 0x8006A6BC | 0x34 | 1 |
| `Multisquare_8006a6f0_threeliner_sets_arg0_stuff` | 0x8006A6F0 | 0x18 | 0 |
| `Multisquare_8006a708_fiveliner_sets_arg0_stuff` | 0x8006A708 | 0x38 | 0 |
| `Multisquare_8006a740_thirtyfiveliner` | 0x8006A740 | 0x264 | 7 |
| `Multisquare_8006a9bc_fiveliner_sets_arg0_struct` | 0x8006A9BC | 0x38 | 0 |
| `Multisquare_8006a9f4_twentyliner_loops_t7_t17` | 0x8006A9F4 | 0x190 | 4 |
| `Multisquare_isArg0_lessthan_44` | 0x8006AB84 | 0x20 | 0 |
| `Multisquare_8006aba4_loops_44_times_1` | 0x8006ABA4 | 0x50 | 0 |
| `Multisquare_8006abf4_loops_44_times_2` | 0x8006ABF4 | 0x38 | 0 |
| `Multisquare_8006ac2c_loops_10_times` | 0x8006AC2C | 0xE0 | 3 |
| `Multisquare_8006ad0c_checks_1_2_3_4` | 0x8006AD0C | 0x98 | 4 |
| `Multisquare_8006ada4_Init` | 0x8006ADA4 | 0x40 | 0 |
| `Multisquare_Deinit_doesnothing` | 0x8006ADE4 | 0x8 | 0 |
| `Multisquare_8006aebc_loops_44_times_4` | 0x8006AEBC | 0x44 | 0 |

## MobilePiece  (17 funcs, top out-degree 12)

| function | addr | size | calls |
|---|---|---|---|
| `MobilePiece_Minos_setUpdateFlag` | 0x80064CE0 | 0x130 | 2 |
| `MobilePiece_80064e10_similar_to_Minos_setUpdFlag` | 0x80064E10 | 0x144 | 2 |
| `MobilePiece_80064f54_fourliner_loops_4_times` | 0x80064F54 | 0x5C | 1 |
| `MobilePiece_Render` | 0x80064FB0 | 0x1A4 | 12 |
| `MobilePiece_80065154_sevenliner_loops_4_times_v1_retbool` | 0x80065154 | 0x74 | 1 |
| `MobilePiece_800651c8_sevenliner_loops_4_times_v2_retbool` | 0x800651C8 | 0x70 | 2 |
| `MobilePiece_80065238_sevenliner_loops_4_times` | 0x80065238 | 0xAC | 2 |
| `MobilePiece_800652e4_sets_arg0_struct_to_arg1_struct` | 0x800652E4 | 0x38 | 0 |
| `MobilePiece_8006531c_fourliner_calls_fun_loops_4_times_v1` | 0x8006531C | 0x60 | 1 |
| `MobilePiece_8006537c_fourliner_calls_fun_loops_4_times_v2` | 0x8006537C | 0x68 | 1 |
| `MobilePiece_800653e4_eightliner_sets_arg0_struct_to_other_args_loops_4_times` | 0x800653E4 | 0xCC | 2 |
| `MobilePiece_800654b0_sixliner_if_zero_if_one` | 0x800654B0 | 0x8C | 2 |
| `MobilePiece_8006553c_nineliner_sets_arg0_struct` | 0x8006553C | 0x88 | 0 |
| `MobilePiece_800655c4_oneliner_if_calls_fun` | 0x800655C4 | 0x5C | 1 |
| `MobilePiece_80065620_threeliner_if_zero_calls_fun_537c` | 0x80065620 | 0x5C | 1 |
| `MobilePiece_8006567c_threeliner_if_notzero_calls_fun_537c` | 0x8006567C | 0x50 | 1 |
| `MobilePiece_SetAlternateColor` | 0x800656CC | 0x44 | 0 |

## NextPieces  (16 funcs, top out-degree 4)

| function | addr | size | calls |
|---|---|---|---|
| `NextPieces_800680a0_sixliner` | 0x800680A0 | 0xB8 | 2 |
| `NextPieces_80068158_sevenliner_sets_arg0_struct_to_arg1` | 0x80068158 | 0xAC | 0 |
| `NextPieces_80068204_fourliner_sets_arg0_struct_math` | 0x80068204 | 0x44 | 0 |
| `NextPieces_8006832c_sixliner_shift_0xe` | 0x8006832C | 0xB8 | 2 |
| `NextPieces_800684e0_sevenliner_sets_arg0_struct_math` | 0x800684E0 | 0xCC | 1 |
| `NextPieces_800685ac_lg_interesting_arg3_is_nextpiecepos` | 0x800685AC | 0x290 | 4 |
| `NextPieces_8006883c_tenliner_loops_4_times_sets_glb_var` | 0x8006883C | 0xA4 | 1 |
| `NextPieces_800688e0_sets_global_var_element` | 0x800688E0 | 0x24 | 0 |
| `NextPieces_80068904_twoliner_if_fb80_eq_1_call_fun` | 0x80068904 | 0x3C | 1 |
| `NextPieces_Render` | 0x80068940 | 0x84 | 3 |
| `NextPieces_800689c4_tenliner_loops_4_times` | 0x800689C4 | 0xC0 | 1 |
| `NextPieces_80068a84_calls_Bag63_GetNextPiece` | 0x80068A84 | 0x94 | 3 |
| `NextPieces_80068b18_threeliner` | 0x80068B18 | 0x64 | 1 |
| `NextPieces_80068b7c_largeliner_sets_lots_of_struct_elems` | 0x80068B7C | 0x394 | 0 |
| `NextPieces_Init` | 0x80068F10 | 0xCC | 3 |
| `NextPieces_Deinit` | 0x80068FDC | 0x14 | 0 |

## PieceHold  (16 funcs, top out-degree 9)

| function | addr | size | calls |
|---|---|---|---|
| `PieceHold_80065710_twoliner_sets_to_0_and_0xff` | 0x80065710 | 0x10 | 0 |
| `PieceHold_80065720_fiveliner_two_traps` | 0x80065720 | 0x4C | 0 |
| `PieceHold_8006593c_nineliner_sets_struct_stuff` | 0x8006593C | 0x84 | 0 |
| `PieceHold_80065a0c_tenliner_adds_sets_struct` | 0x80065A0C | 0xD0 | 0 |
| `PieceHold_80065e20_lots_of_ifs_and_traps` | 0x80065E20 | 0x19C | 0 |
| `PieceHold_80065fbc_oneliner_calls_fun1` | 0x80065FBC | 0x34 | 1 |
| `PieceHold_80065ff8_oneliner_calls_fun2_wunk518` | 0x80065FF8 | 0x28 | 1 |
| `PieceHold_80066020_oneliner_calls_fun3_wunk518` | 0x80066020 | 0x28 | 1 |
| `PieceHold_80066048_tenliner_checks_numplayers` | 0x80066048 | 0x118 | 2 |
| `PieceHold_Update` | 0x80066160 | 0x40 | 2 |
| `PieceHold_Render` | 0x800661A0 | 0x34 | 2 |
| `PieceHold_Swap` | 0x800661D4 | 0x290 | 9 |
| `PieceHold_Enable` | 0x80066464 | 0x5C | 1 |
| `PieceHold_Disable` | 0x800664C0 | 0x58 | 1 |
| `PieceHold_Init` | 0x80066518 | 0x190 | 8 |
| `PieceHold_Deinit` | 0x800666A8 | 0x28 | 1 |

## Audio  (13 funcs, top out-degree 31)

| function | addr | size | calls |
|---|---|---|---|
| `Audio_InitAudio` | 0x80084700 | 0x3B0 | 26 |
| `Audio_ChangeSong` | 0x80084AB0 | 0x1E0 | 17 |
| `Audio_FreeAudio` | 0x80084C98 | 0x188 | 8 |
| `Audio_80084e20_twentyliner` | 0x80084E20 | 0x160 | 7 |
| `Audio_UnloadSFX` | 0x80084F80 | 0xB0 | 5 |
| `Audio_LoadSFX` | 0x80085030 | 0x3D8 | 31 |
| `Audio_80085408_oneliner_calls_allocdcm` | 0x80085408 | 0x28 | 1 |
| `Audio_ALManager` | 0x80085430 | 0x388 | 13 |
| `Audio_PreNmiAudio` | 0x800857B8 | 0x16C | 8 |
| `Audio_80085924_fortyliner_sets_arg0_struct` | 0x80085924 | 0x278 | 6 |
| `Audio_80085b9c_threeliner` | 0x80085B9C | 0x50 | 1 |
| `Audio_80085bec_tenliner` | 0x80085BEC | 0x108 | 2 |
| `Audio_Wrap` | 0x80085D04 | 0x4C | 1 |

## LineEffect  (13 funcs, top out-degree 7)

| function | addr | size | calls |
|---|---|---|---|
| `LineEffect_80068ff0_elevenliner` | 0x80068FF0 | 0xF4 | 4 |
| `LineEffect_800690e4_eightliner_loops_10_times` | 0x800690E4 | 0x7C | 1 |
| `LineEffect_80069160_seventeen_liner` | 0x80069160 | 0x19C | 7 |
| `LineEffect_800692fc_sixteenliner_loops_10_times` | 0x800692FC | 0x130 | 4 |
| `LineEffect_8006942c_sixliner` | 0x8006942C | 0x84 | 1 |
| `LineEffect_800694b0_sevenliner_loops_10_times` | 0x800694B0 | 0x7C | 1 |
| `LineEffect_Update` | 0x8006952C | 0x13C | 7 |
| `LineEffect_80069668_fourliner_sets_arg0_struct_v1` | 0x80069668 | 0x1C | 0 |
| `LineEffect_80069684_threeliner_sets_arg0_struct_v2` | 0x80069684 | 0x18 | 0 |
| `LineEffect_8006969c_fourliner_sets_arg0_struct_v3` | 0x8006969C | 0x1C | 0 |
| `LineEffect_800696b8_fiveliner_sets_arg0_struct_v4` | 0x800696B8 | 0x20 | 0 |
| `LineEffect_800696d8_fourliner_sets_arg0_struct_v5` | 0x800696D8 | 0x1C | 0 |
| `LineEffect_Init` | 0x800696F4 | 0x13C | 5 |

## wonders3  (12 funcs, top out-degree 29)

| function | addr | size | calls |
|---|---|---|---|
| `wonders3_80046400_twentyliner` | 0x80046400 | 0x210 | 1 |
| `wonders3_80046610_fifteenliner` | 0x80046610 | 0x188 | 3 |
| `wonders3_80046798_threeliner` | 0x80046798 | 0x60 | 1 |
| `wonders3_800467f8_threeliner` | 0x800467F8 | 0x48 | 2 |
| `wonders3_init_tuples` | 0x80046840 | 0x1F4 | 13 |
| `wonders3_switch_0to7_6and7are_same` | 0x80046A34 | 0xF4 | 8 |
| `wonders3_display_wonders_hall_text` | 0x80046B28 | 0x4EC | 29 |
| `wonders3_related` | 0x80047014 | 0x50 | 2 |
| `wonders3_no_idea_menu_img_button` | 0x80047064 | 0x194 | 4 |
| `wonders3_switch_0to3_2and3are_same` | 0x800471F8 | 0xF8 | 6 |
| `wonders3_wonder_viewer` | 0x800472F0 | 0x16C | 13 |
| `wonders3_8004745c_medium_liner_has_audio` | 0x8004745C | 0x294 | 21 |

## PFGFX  (11 funcs, top out-degree 9)

| function | addr | size | calls |
|---|---|---|---|
| `PFGFX_8005fa80_twoliner_calls_fun` | 0x8005FA80 | 0x38 | 1 |
| `PFGFX_8005fab8_oneliner_calls_fun` | 0x8005FAB8 | 0x28 | 1 |
| `PFGFX_Sets_x58_x59_Checks_NumPlayers_CurrPlayer` | 0x8005FAE0 | 0x190 | 0 |
| `PFGFX_8005fc70_doesnothing` | 0x8005FC70 | 0x8 | 0 |
| `PFGFX_Init` | 0x8005FE68 | 0x38 | 0 |
| `PFGFX_SetTextDisplayPos_1p` | 0x8005FEA0 | 0x1BC | 9 |
| `PFGFX_SetTextDisplayPos_2p` | 0x8006005C | 0x228 | 9 |
| `PFGFX_SetTextDisplayPos_3p` | 0x80060284 | 0x174 | 5 |
| `PFGFX_SetTextDisplayPos_4p` | 0x800603F8 | 0x1A0 | 5 |
| `PFGFX_Playfield_Init` | 0x80060598 | 0xBC | 6 |
| `PFGFX_80060654_doesnothing` | 0x80060654 | 0x2C | 1 |

## LineScan  (10 funcs, top out-degree 25)

| function | addr | size | calls |
|---|---|---|---|
| `LineScan_80069830_elevenliner_loops_20_times` | 0x80069830 | 0xB0 | 1 |
| `LineScan_800698e0_largeliner_loops_20_times_plays_sfx` | 0x800698E0 | 0x410 | 25 |
| `LineScan_80069cf0_eighliner_loops_10_times_retbool` | 0x80069CF0 | 0x70 | 0 |
| `LineScan_80069d60_fifteenliner_loops_20_times` | 0x80069D60 | 0xCC | 1 |
| `LineScan_80069e2c_fiveliner` | 0x80069E2C | 0x58 | 1 |
| `LineScan_80069e84_sevenliner_loops_20_times` | 0x80069E84 | 0x3C | 0 |
| `LineScan_80069ec0_sevenliner_loops_4_times` | 0x80069EC0 | 0x50 | 0 |
| `LineScan_80069f10_threeliner_lowestscanableline` | 0x80069F10 | 0x58 | 1 |
| `LineScan_Init` | 0x80069F68 | 0x50 | 0 |
| `LineScan_80069fb8_elevenliner_case_and_loop_interesting` | 0x80069FB8 | 0x98 | 3 |

## Tetris  (10 funcs, top out-degree 24)

| function | addr | size | calls |
|---|---|---|---|
| `Tetris_CheckButtons` | 0x80053F50 | 0x2D0 | 7 |
| `Tetris_FUN_80054220_fourliner` | 0x80054220 | 0x1C | 0 |
| `Tetris_Update` | 0x8005423C | 0x240 | 15 |
| `Tetris_Render` | 0x8005447C | 0x10C | 16 |
| `Tetris_SetMarathonHandicap` | 0x80054588 | 0xC4 | 3 |
| `Tetris_SetSprintHandicap` | 0x8005464C | 0xC4 | 3 |
| `Tetris_SetUltraHandicap` | 0x80054710 | 0x50 | 1 |
| `Tetris_SetGameHandicap` | 0x80054760 | 0x90 | 3 |
| `Tetris_Init` | 0x800547F0 | 0x304 | 24 |
| `Tetris_Deinit` | 0x80054AF4 | 0x8C | 9 |

## frametime  (10 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `frametime_clear` | 0x800A39B0 | 0x24 | 0 |
| `frametime_reset` | 0x800A39D4 | 0x28 | 1 |
| `frametime_add` | 0x800A39FC | 0x90 | 0 |
| `frametime_update` | 0x800A3A8C | 0x28 | 1 |
| `frametime_count` | 0x800A3AB4 | 0xC | 0 |
| `frametime_jiffies` | 0x800A3AC0 | 0xC | 0 |
| `frametime_seconds` | 0x800A3ACC | 0xC | 0 |
| `frametime_minutes` | 0x800A3AD8 | 0xC | 0 |
| `frametime_hours` | 0x800A3AE4 | 0xC | 0 |
| `frametime_delta` | 0x800A3AF0 | 0x10 | 0 |

## lzo  (10 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `lzo_assert` | 0x80080FE0 | 0x20 | 0 |
| `lzo_copyright` | 0x80081000 | 0xC | 0 |
| `lzo_version` | 0x8008100C | 0x8 | 0 |
| `lzo_version_string` | 0x80081014 | 0xC | 0 |
| `lzo_version_date` | 0x80081020 | 0xC | 0 |
| `lzo_adler32` | 0x80081044 | 0x280 | 0 |
| `lzo_memcmp` | 0x800812C4 | 0x64 | 0 |
| `lzo_memcpy` | 0x80081328 | 0x68 | 0 |
| `lzo_memmove` | 0x80081390 | 0xC8 | 0 |
| `lzo_memset` | 0x80081458 | 0x38 | 0 |

## EndScroller  (9 funcs, top out-degree 10)

| function | addr | size | calls |
|---|---|---|---|
| `EndScroller_8007fdb0_returns_0_1_2` | 0x8007FDB0 | 0xA4 | 0 |
| `EndScroller_8007fe54_twoliner` | 0x8007FE54 | 0xA0 | 1 |
| `EndScroller_font_size_scrolltext` | 0x8007FEF4 | 0xBC | 2 |
| `EndScroller_8007ffb0_doesnothing` | 0x8007FFB0 | 0x8 | 0 |
| `EndScroller_8007ffb8_oneliner_if` | 0x8007FFB8 | 0x2C | 0 |
| `EndScroller_Init` | 0x8007FFE4 | 0x178 | 10 |
| `EndScroller_Deinit` | 0x8008015C | 0xE0 | 7 |
| `EndScroller_8008023c_line_452` | 0x8008023C | 0x1C4 | 4 |
| `EndScroller_80080400_line_502` | 0x80080400 | 0xF0 | 5 |

## aisquarelist  (9 funcs, top out-degree 17)

| function | addr | size | calls |
|---|---|---|---|
| `aisquarelist_8003e1e0_sevenliner_loops_6t` | 0x8003E1E0 | 0x4C | 0 |
| `aisquarelist_8003e22c_tenliner_loops_6t` | 0x8003E22C | 0x9C | 0 |
| `aisquarelist_8003e2c8_sevenliner` | 0x8003E2C8 | 0x84 | 0 |
| `aisquarelist_8003e34c_thirteenliner_loops_arg0_t` | 0x8003E34C | 0x10C | 0 |
| `aisquarelist_8003e458_thirteenliner_loops_7t` | 0x8003E458 | 0x104 | 3 |
| `aisquarelist_8003e55c_eightliner_loops_arg0_t_1` | 0x8003E55C | 0xAC | 1 |
| `aisquarelist_8003e608_eightliner_loops_arg0_t_2` | 0x8003E608 | 0x84 | 0 |
| `aisquarelist_8003e68c_hugeliner_many_loops` | 0x8003E68C | 0x6B4 | 17 |
| `aisquarelist_8003ed40_largeliner_many_loops` | 0x8003ED40 | 0x5C0 | 12 |

## MobileCubes  (7 funcs, top out-degree 7)

| function | addr | size | calls |
|---|---|---|---|
| `MobileCubes_Move` | 0x8006EA40 | 0x20C | 0 |
| `MobileCubes_Update` | 0x8006EC4C | 0x74 | 1 |
| `MobileCubes_Render` | 0x8006ECC0 | 0xD4 | 7 |
| `MobileCubes_Alloc` | 0x8006ED94 | 0x7C | 0 |
| `MobileCubes_Unalloc` | 0x8006EE10 | 0x24 | 0 |
| `MobileCubes_Init` | 0x8006EE34 | 0xA4 | 1 |
| `MobileCubes_Deinit` | 0x8006EED8 | 0x68 | 1 |

## PieceHoldPiece  (7 funcs, top out-degree 9)

| function | addr | size | calls |
|---|---|---|---|
| `PieceHoldPiece_MakeShadowActive` | 0x8006576C | 0x128 | 2 |
| `PieceHoldPiece_RenderShadow` | 0x80065894 | 0xA8 | 2 |
| `PieceHoldPiece_FinishSwap` | 0x800659C0 | 0x4C | 1 |
| `PieceHoldPiece_Update` | 0x80065ADC | 0xF8 | 9 |
| `PieceHoldPiece_Render` | 0x80065BD4 | 0xA0 | 3 |
| `PieceHoldPiece_MakeActive` | 0x80065C74 | 0x1AC | 5 |
| `PieceHoldPiece_Init` | 0x80065FF0 | 0x8 | 0 |

## displayText  (7 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `displayText_XY_RGBA_1` | 0x80077818 | 0x148 | 1 |
| `displayText_XY_RGBA_2` | 0x80077960 | 0x148 | 1 |
| `displayText_XY_RGBA_3` | 0x80077AA8 | 0x100 | 1 |
| `displayText_XY_RGBA_4` | 0x80077BA8 | 0x190 | 1 |
| `displayText_80077ee0_5` | 0x80077EE0 | 0x14C | 1 |
| `displayText_80078094_6` | 0x80078094 | 0x114 | 1 |
| `displayText_80078244_7` | 0x80078244 | 0xBC | 2 |

## wonders2  (7 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `wonders2_80045e50_sets_num_won_compl_q` | 0x80045E50 | 0x18C | 1 |
| `wonders2_80045fdc_sets_num_won_compl_q` | 0x80045FDC | 0x1C0 | 1 |
| `wonders2_8004619c_sixliner_crazy_if` | 0x8004619C | 0x7C | 0 |
| `wonders2_divide_by_seven` | 0x80046218 | 0x34 | 0 |
| `wonders2_8004624c_mult_7_add_6_etc` | 0x8004624C | 0x34 | 0 |
| `wonders2_80046280_tenliner_trap` | 0x80046280 | 0x108 | 1 |
| `wonders2_80046388_fiveliner` | 0x80046388 | 0x78 | 1 |

## Board  (6 funcs, top out-degree 5)

| function | addr | size | calls |
|---|---|---|---|
| `Board_Update` | 0x8006D1B0 | 0x30 | 1 |
| `Board_8006D1E0_doesnothing1` | 0x8006D1E0 | 0xC | 0 |
| `Board_8006D1EC_doesnothing2` | 0x8006D1EC | 0xC | 0 |
| `Board_8006D1F8_doesnothing3` | 0x8006D1F8 | 0x8 | 0 |
| `Board_Init` | 0x8006D200 | 0x78 | 5 |
| `Board_Deinit` | 0x8006D278 | 0x48 | 4 |

## FallingCubes  (6 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `FallingCubes_Drop` | 0x8006EF40 | 0xAC | 1 |
| `FallingCubes_Update` | 0x8006EFEC | 0x78 | 2 |
| `FallingCubes_SetAlpha` | 0x8006F064 | 0x7C | 1 |
| `FallingCubes_Alloc` | 0x8006F0E0 | 0xB8 | 1 |
| `FallingCubes_Init` | 0x8006F198 | 0x84 | 1 |
| `FallingCubes_Deinit` | 0x8006F21C | 0x44 | 1 |

## Font  (6 funcs, top out-degree 4)

| function | addr | size | calls |
|---|---|---|---|
| `Font_Deinit` | 0x800773D0 | 0x38 | 1 |
| `Font_Init46Char` | 0x80077408 | 0x208 | 4 |
| `Font_Init51Char` | 0x80077610 | 0x208 | 4 |
| `Font_80077e18_fifteenliner` | 0x80077E18 | 0xC8 | 0 |
| `Font_8007802c_fiveliner` | 0x8007802C | 0x68 | 0 |
| `Font_800781a8_elevenliner_loops_arg2_t` | 0x800781A8 | 0x9C | 1 |

## aiplayer  (6 funcs, top out-degree 26)

| function | addr | size | calls |
|---|---|---|---|
| `aiplayer_gameinit_related` | 0x80042800 | 0x33C | 7 |
| `aiplayer_80042b3c_calls_heap_unalloc` | 0x80042B3C | 0x4C | 3 |
| `aiplayer_80042b88_largefunction` | 0x80042B88 | 0x594 | 26 |
| `aiplayer_8004311c_largefunction` | 0x8004311C | 0x5F0 | 13 |
| `aiplayer_8004370c_threeliner` | 0x8004370C | 0x60 | 0 |
| `aiplayer_8004376c_fiveliner` | 0x8004376C | 0xA4 | 0 |

## get  (6 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `get_board_size` | 0x8006D2E4 | 0x48 | 0 |
| `get_board_location` | 0x8006D32C | 0x18 | 0 |
| `get_board_center` | 0x8006D344 | 0x7C | 2 |
| `get_char_width` | 0x80077D38 | 0x50 | 0 |
| `get_text_width` | 0x80077D88 | 0x90 | 0 |
| `get_total_wonder_lines` | 0x8007BCB4 | 0x10 | 0 |

## Bag63  (5 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `Bag63_FillBag` | 0x800711E0 | 0x58 | 0 |
| `Bag63_RefillQueue` | 0x80071238 | 0x15C | 2 |
| `Bag63_GetNextPiece` | 0x80071394 | 0x5C | 1 |
| `Bag63_Init` | 0x800713F0 | 0x80 | 2 |
| `Bag63_Deinit` | 0x80071470 | 0x10 | 0 |

## BoardPieces  (5 funcs, top out-degree 7)

| function | addr | size | calls |
|---|---|---|---|
| `BoardPieces_SwapCubes` | 0x8006E0E8 | 0x1A0 | 4 |
| `BoardPieces_RemoveLine` | 0x8006E34C | 0x14C | 5 |
| `BoardPieces_Update` | 0x8006E6F4 | 0x30 | 1 |
| `BoardPieces_Init` | 0x8006E724 | 0x148 | 7 |
| `BoardPieces_Deinit` | 0x8006E86C | 0x44 | 2 |

## Cube  (5 funcs, top out-degree 5)

| function | addr | size | calls |
|---|---|---|---|
| `Cube_8006e8b0_sets_struct_0x02_to_0x12_to_mostly_zeros` | 0x8006E8B0 | 0x48 | 0 |
| `Cube_8006e8f8_sets_struct_0x14_to_0x24_to_mostly_zeros` | 0x8006E8F8 | 0x48 | 0 |
| `Cube_Alloc` | 0x8006E940 | 0x88 | 5 |
| `Cube_NewCellInfo` | 0x8006E9C8 | 0x50 | 1 |
| `Cube_NextCellId` | 0x8006EA18 | 0x28 | 0 |

## Dcm  (5 funcs, top out-degree 31)

| function | addr | size | calls |
|---|---|---|---|
| `Dcm_Init` | 0x80085D50 | 0x23C | 3 |
| `Dcm_VoiceHandler` | 0x800878F0 | 0x12B4 | 31 |
| `Dcm_VoiceHandler_2` | 0x8008A80C | 0x14CC | 28 |
| `Dcm_SetPitch_2` | 0x8008BCD8 | 0x140 | 2 |
| `Dcm_SetPitch` | 0x8008BE18 | 0x140 | 2 |

## GameStats  (5 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `GameStats_saveCurrentPieceFallVelocity` | 0x80052904 | 0xA4 | 1 |
| `GameStats_Update` | 0x800529BC | 0x44 | 1 |
| `GameStats_Render` | 0x80052A00 | 0x28 | 1 |
| `GameStats_Init` | 0x80052A28 | 0x68 | 2 |
| `GameStats_Deinit` | 0x80052A90 | 0x10 | 0 |

## GhostPiece  (5 funcs, top out-degree 3)

| function | addr | size | calls |
|---|---|---|---|
| `GhostPiece_800666d0_sixliner_loops_arg1_times` | 0x800666D0 | 0x60 | 2 |
| `GhostPiece_Render` | 0x80066730 | 0x4C | 2 |
| `GhostPiece_8006677c_fourliner_loops` | 0x8006677C | 0x60 | 1 |
| `GhostPiece_800667dc_twelveliner_sets_struct` | 0x800667DC | 0x110 | 3 |
| `GhostPiece_800668ec_sixliner_inits_struct` | 0x800668EC | 0x34 | 0 |

## Landfill  (5 funcs, top out-degree 10)

| function | addr | size | calls |
|---|---|---|---|
| `Landfill_800723a0_calls_garbage_fun` | 0x800723A0 | 0x6C | 2 |
| `Landfill_8007240c_fiveliner` | 0x8007240C | 0x88 | 1 |
| `Landfill_Garbage` | 0x8007283C | 0x40 | 0 |
| `Landfill_Init` | 0x8007287C | 0x10C | 10 |
| `Landfill_Deinit` | 0x80072988 | 0xFC | 9 |

## MultisquareGlow  (5 funcs, top out-degree 11)

| function | addr | size | calls |
|---|---|---|---|
| `MultisquareGlow_8006af00_eightliner` | 0x8006AF00 | 0x70 | 0 |
| `MultisquareGlow_8006af70_nineliner` | 0x8006AF70 | 0xE0 | 4 |
| `MultisquareGlow_Init` | 0x8006B050 | 0x1F8 | 1 |
| `MultisquareGlow_InitStaticMembers` | 0x8006B248 | 0x13C | 11 |
| `MultisquareGlow_8006b384_oneliner_calls_fun` | 0x8006B384 | 0x2C | 1 |

## main  (5 funcs, top out-degree 15)

| function | addr | size | calls |
|---|---|---|---|
| `main_infinite_loop_at_end` | 0x80049C70 | 0x70 | 4 |
| `main_infinite_loop_at_end_3` | 0x8004A0A0 | 0x1E0 | 11 |
| `main_maybe_audio_related` | 0x8004A280 | 0xCC | 5 |
| `main_8004A34C_threeliner` | 0x8004A34C | 0x58 | 1 |
| `main_another_but_diff_400x300` | 0x8004A3A4 | 0x1FC | 15 |

## vec3  (5 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `vec3_dot` | 0x800AFF04 | 0x30 | 0 |
| `vec3_cross` | 0x800AFF34 | 0x70 | 0 |
| `vec3_squared` | 0x800AFFA4 | 0x28 | 0 |
| `vec3_length` | 0x800AFFCC | 0x24 | 1 |
| `vec3_normalize` | 0x800B0040 | 0x7C | 1 |

## CubeTiles  (4 funcs, top out-degree 4)

| function | addr | size | calls |
|---|---|---|---|
| `CubeTiles_CopyPartialTile` | 0x800758B0 | 0x1D4 | 1 |
| `CubeTiles_80075a84_thirteenliner` | 0x80075A84 | 0x214 | 4 |
| `CubeTiles_Init` | 0x80075C98 | 0x11C | 2 |
| `CubeTiles_Deinit` | 0x80075DB4 | 0x8 | 0 |

## Color  (3 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `Color_Tint` | 0x80054B80 | 0x128 | 0 |
| `Color_Brighten` | 0x80054CA8 | 0xF8 | 0 |
| `Color_Blend` | 0x80054DA0 | 0x130 | 0 |

## Credits  (3 funcs, top out-degree 7)

| function | addr | size | calls |
|---|---|---|---|
| `Credits_Init` | 0x80083320 | 0x130 | 6 |
| `Credits_80083450_oneliner_calls_80090a44` | 0x80083450 | 0x20 | 1 |
| `Credits_StateMachine_q` | 0x80083470 | 0xF0 | 7 |

## Garbage  (3 funcs, top out-degree 4)

| function | addr | size | calls |
|---|---|---|---|
| `Garbage_Init` | 0x80072D38 | 0xEC | 4 |
| `Garbage_Deinit` | 0x80072E24 | 0x8 | 0 |
| `Garbage_80072e2c_set_arg0p_to_arg1` | 0x80072E2C | 0x8 | 0 |

## Multisquares  (3 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `Multisquares_Test4x4byType` | 0x8006A4EC | 0x1D0 | 1 |
| `Multisquares_UpdateGlows` | 0x8006ADEC | 0x6C | 1 |
| `Multisquares_RenderGlows` | 0x8006AE58 | 0x64 | 1 |

## debug  (3 funcs, top out-degree 7)

| function | addr | size | calls |
|---|---|---|---|
| `debug_print_reason_routine_linenum` | 0x8004A5A0 | 0x50 | 2 |
| `debug_print2` | 0x8006CF08 | 0xC | 0 |
| `debug_print_reason_routine` | 0x80083560 | 0x13C | 7 |

## lzo1x  (3 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `lzo1x_1_compress` | 0x800825B0 | 0x23C | 1 |
| `lzo1x_decompress` | 0x800827EC | 0x380 | 0 |
| `lzo1x_decompress_safe` | 0x80082B6C | 0x594 | 0 |

## strutil  (3 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `strutil_nextline` | 0x80080A70 | 0x48 | 0 |
| `strutil_linelen` | 0x80080AB8 | 0x50 | 0 |
| `strutil_linecnt` | 0x80080B08 | 0x48 | 0 |

## wonders4  (3 funcs, top out-degree 23)

| function | addr | size | calls |
|---|---|---|---|
| `wonders4_800476f0_thirtyliner` | 0x800476F0 | 0x1D0 | 1 |
| `wonders4_display_contributors` | 0x800478C0 | 0x398 | 23 |
| `wonders4_display_contribs_or_story` | 0x80047C58 | 0x3C8 | 10 |

## Ids  (2 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `Ids_Init` | 0x80050650 | 0x80 | 1 |
| `Ids_Deinit` | 0x800506D0 | 0x44 | 1 |

## basic  (2 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `basic_integral_check` | 0x80081490 | 0xA0 | 0 |
| `basic_ptr_check` | 0x80081530 | 0x78 | 0 |

## corrupted  (2 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `corrupted_init` (data?) | 0x800BD668 | 0x2CC |  |
| `corrupted` (data?) | 0x800BD934 | 0x19C |  |

## has  (2 funcs, top out-degree 23)

| function | addr | size | calls |
|---|---|---|---|
| `has_rounds_and_floors_large_liner` | 0x80048B64 | 0x798 | 16 |
| `has_rounds_and_floors_2_large_liner` | 0x800492FC | 0x7D4 | 23 |

## BoardInfo  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `BoardInfo_Init` | 0x8006D2C0 | 0x24 | 0 |

## GameCamera  (1 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `GameCamera_Render` | 0x8005FC78 | 0x1F0 | 2 |

## NextPiece  (1 funcs, top out-degree 5)

| function | addr | size | calls |
|---|---|---|---|
| `NextPiece_Render` | 0x800683E4 | 0xFC | 5 |

## NextPieceShadow  (1 funcs, top out-degree 4)

| function | addr | size | calls |
|---|---|---|---|
| `NextPieceShadow_Render` | 0x80068248 | 0xE4 | 4 |

## PV  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `PV_set_controller_no` | 0x800535A0 | 0x18 | 0 |

## PlayerVars  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `PlayerVars_SetGlobalPointers` | 0x8005061C | 0x34 | 0 |

## alAdpcmPull  (1 funcs, top out-degree 3)

| function | addr | size | calls |
|---|---|---|---|
| `alAdpcmPull` | 0x800C146C | 0x4A4 | 3 |

## alAudioFrame  (1 funcs, top out-degree 4)

| function | addr | size | calls |
|---|---|---|---|
| `alAudioFrame` | 0x8008EAAC | 0x258 | 4 |

## alAuxBusNew  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `alAuxBusNew` | 0x800B8FD8 | 0x54 | 1 |

## alAuxBusParam  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alAuxBusParam` | 0x800B9BD0 | 0x30 | 0 |

## alAuxBusPull  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alAuxBusPull` | 0x800B9C00 | 0xE0 | 0 |

## alClose  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `alClose` | 0x800B8734 | 0x38 | 1 |

## alCopy  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alCopy` | 0x800C3100 | 0x80 | 0 |

## alEnvmixerNew  (1 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `alEnvmixerNew` | 0x800B915C | 0xA4 | 2 |

## alEnvmixerParam  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alEnvmixerParam` | 0x8008CB88 | 0x194 | 0 |

## alEnvmixerPull  (1 funcs, top out-degree 8)

| function | addr | size | calls |
|---|---|---|---|
| `alEnvmixerPull` | 0x8008C2F0 | 0x898 | 8 |

## alFilterNew  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alFilterNew` | 0x800C0150 | 0x20 | 0 |

## alFxNew  (1 funcs, top out-degree 8)

| function | addr | size | calls |
|---|---|---|---|
| `alFxNew` | 0x800B92A0 | 0x440 | 8 |

## alFxParam  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alFxParam` | 0x800C0A64 | 0x18 | 0 |

## alFxParamHdl  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `alFxParamHdl` | 0x800C0808 | 0x25C | 1 |

## alFxPull  (1 funcs, top out-degree 7)

| function | addr | size | calls |
|---|---|---|---|
| `alFxPull` | 0x800C0A7C | 0x344 | 7 |

## alHeapDBAlloc  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alHeapDBAlloc` | 0x800B8530 | 0x60 | 0 |

## alHeapInit  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alHeapInit` | 0x800B84F0 | 0x40 | 0 |

## alInit  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `alInit` | 0x800B876C | 0x34 | 1 |

## alLink  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alLink` | 0x800B8710 | 0x24 | 0 |

## alLoadNew  (1 funcs, top out-degree 3)

| function | addr | size | calls |
|---|---|---|---|
| `alLoadNew` | 0x800B90B4 | 0xA8 | 3 |

## alLoadParam  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `alLoadParam` | 0x800C0DC0 | 0x1D4 | 1 |

## alMainBusNew  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `alMainBusNew` | 0x800B8F84 | 0x54 | 1 |

## alMainBusParam  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alMainBusParam` | 0x800B9780 | 0x30 | 0 |

## alMainBusPull  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alMainBusPull` | 0x800B97B0 | 0x120 | 0 |

## alRaw16Pull  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alRaw16Pull` | 0x800C0F94 | 0x3AC | 0 |

## alResampleNew  (1 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `alResampleNew` | 0x800B902C | 0x88 | 2 |

## alResampleParam  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alResampleParam` | 0x800B98D0 | 0xEC | 0 |

## alResamplePull  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `alResamplePull` | 0x800B99BC | 0x214 | 1 |

## alSaveNew  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `alSaveNew` | 0x800B8F40 | 0x44 | 1 |

## alSaveParam  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alSaveParam` | 0x800B9CE0 | 0x34 | 0 |

## alSavePull  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alSavePull` | 0x800B9D14 | 0x8C | 0 |

## alSynAddPlayer  (1 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `alSynAddPlayer` | 0x800B88E0 | 0x50 | 2 |

## alSynAllocFX  (1 funcs, top out-degree 3)

| function | addr | size | calls |
|---|---|---|---|
| `alSynAllocFX` | 0x800B96E0 | 0xA0 | 3 |

## alSynAllocVoice  (1 funcs, top out-degree 3)

| function | addr | size | calls |
|---|---|---|---|
| `alSynAllocVoice` | 0x800B8A18 | 0x148 | 3 |

## alSynDelete  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alSynDelete` | 0x800C0050 | 0x10 | 0 |

## alSynNew  (1 funcs, top out-degree 21)

| function | addr | size | calls |
|---|---|---|---|
| `alSynNew` | 0x8008E690 | 0x41C | 21 |

## alSynSetPan  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `alSynSetPan` | 0x800B8D30 | 0x90 | 1 |

## alSynSetPitch  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `alSynSetPitch` | 0x800B8EB0 | 0x90 | 1 |

## alSynSetVol  (1 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `alSynSetVol` | 0x8008E5A0 | 0xF0 | 2 |

## alSynStartVoiceParams  (1 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `alSynStartVoiceParams` | 0x800B8DC0 | 0xF0 | 2 |

## alSynStopVoice  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `alSynStopVoice` | 0x800B8B60 | 0x80 | 1 |

## alUnlink  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `alUnlink` | 0x800B86E0 | 0x30 | 0 |

## bcmp  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `bcmp` (data?) | 0x800B80B0 | 0x120 |  |

## boot  (1 funcs, top out-degree 6)

| function | addr | size | calls |
|---|---|---|---|
| `boot` | 0x80049CE0 | 0x98 | 6 |

## calls  (1 funcs, top out-degree 17)

| function | addr | size | calls |
|---|---|---|---|
| `calls_game_deinit` | 0x80055524 | 0x1E0 | 17 |

## can  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `can_run_out_of_ids` | 0x80050714 | 0xD0 | 1 |

## check  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `check_square_completion` | 0x80041B48 | 0x258 | 0 |

## cosf  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `cosf` (data?) | 0x800B81D0 | 0x170 |  |

## coss  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `coss` | 0x800B8080 | 0x30 | 1 |

## createSpeedParam  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `createSpeedParam` | 0x800B6DF0 | 0xA0 | 0 |

## createSuperThread  (1 funcs, top out-degree 10)

| function | addr | size | calls |
|---|---|---|---|
| `createSuperThread` | 0x8003ADD0 | 0x13C | 10 |

## display  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `display_one_text_character_rgb` | 0x80059048 | 0x1A54 | 0 |

## displayLineCount  (1 funcs, top out-degree 5)

| function | addr | size | calls |
|---|---|---|---|
| `displayLineCount` | 0x80052860 | 0xA4 | 5 |

## displayPausePopupMenu  (1 funcs, top out-degree 8)

| function | addr | size | calls |
|---|---|---|---|
| `displayPausePopupMenu` | 0x80071BF0 | 0x1FC | 8 |

## displayTimeFormatted  (1 funcs, top out-degree 5)

| function | addr | size | calls |
|---|---|---|---|
| `displayTimeFormatted_XY_RGBA` | 0x80071480 | 0x2B0 | 5 |

## four  (1 funcs, top out-degree 16)

| function | addr | size | calls |
|---|---|---|---|
| `four_arguments_get_debug_printed` | 0x80049AD0 | 0x1A0 | 16 |

## game  (1 funcs, top out-degree 90)

| function | addr | size | calls |
|---|---|---|---|
| `game_over_display_stuff_huge_function_q` | 0x80055744 | 0x193C | 90 |

## getCurPieceSpawnOffsetAsPoint  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `getCurPieceSpawnOffsetAsPoint` | 0x80054ED0 | 0x38 | 0 |

## getCurPieceSpawnPoint  (1 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `getCurPieceSpawnPoint` | 0x80066AA8 | 0x94 | 2 |

## getLineCount  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `getLineCount` | 0x8005282C | 0x10 | 0 |

## getMaxPlayerLines  (1 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `getMaxPlayerLines` | 0x80050D08 | 0xAC | 2 |

## getMinPlayerTime  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `getMinPlayerTime` | 0x80050DB4 | 0xAC | 1 |

## getPlayerTopOutOrder  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `getPlayerTopOutOrder` | 0x80050CA8 | 0x60 | 0 |

## getStartingOriginOfRotationPoint  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `getStartingOriginOfRotationPoint` | 0x80066B3C | 0x78 | 1 |

## getStartingRotOriginAsPoint  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `getStartingRotOriginAsPoint` | 0x80054F08 | 0x54 | 0 |

## getStartingRotationAngle  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `getStartingRotationAngle` | 0x80066BB4 | 0x34 | 0 |

## getStartingRotationState  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `getStartingRotationState` | 0x80066BE8 | 0x28 | 0 |

## gets  (1 funcs, top out-degree 9)

| function | addr | size | calls |
|---|---|---|---|
| `gets_lineCounts_loops_numPlayers_checks_gametype` | 0x80055000 | 0x524 | 9 |

## h2oLoadParam  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `h2oLoadParam` | 0x8008E368 | 0x238 | 0 |

## h2oRaw16Pull  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `h2oRaw16Pull` | 0x8008D770 | 0x5A8 | 0 |

## h2oRaw8Pull  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `h2oRaw8Pull` | 0x8008DD18 | 0x650 | 0 |

## hasPlayerToppedOut  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `hasPlayerToppedOut` | 0x80050A64 | 0x60 | 0 |

## idle  (1 funcs, top out-degree 16)

| function | addr | size | calls |
|---|---|---|---|
| `idle` | 0x80049D78 | 0x328 | 16 |

## init  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `init_lpfilter` | 0x800B9200 | 0xA0 | 0 |

## initLinesInfo  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `initLinesInfo` | 0x80052790 | 0x1C | 0 |

## initPieceColorsScale16  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `initPieceColorsScale16` | 0x80054F5C | 0xA4 | 0 |

## inits  (1 funcs, top out-degree 5)

| function | addr | size | calls |
|---|---|---|---|
| `inits_bunch_of_stuff_q_allocs_heap` | 0x800484B4 | 0x480 | 5 |

## isGoalCompleted  (1 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `isGoalCompleted` | 0x800511EC | 0x134 | 2 |

## ldiv  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `ldiv` (data?) | 0x800C3280 | 0x90 |  |

## lldiv  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `lldiv` (data?) | 0x800C3180 | 0x100 |  |

## load  (1 funcs, top out-degree 33)

| function | addr | size | calls |
|---|---|---|---|
| `load_from_sram` | 0x8007C0EC | 0x4E0 | 33 |

## mtx4  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `mtx4_mult` | 0x800AF558 | 0x404 | 0 |

## n64HeapAlloc  (1 funcs, top out-degree 3)

| function | addr | size | calls |
|---|---|---|---|
| `n64HeapAlloc` | 0x8007E03C | 0x1A0 | 3 |

## n64HeapAllocAppend  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `n64HeapAllocAppend` | 0x8007E1DC | 0x14C | 0 |

## n64HeapGetAllocCumulative  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `n64HeapGetAllocCumulative` | 0x8007E740 | 0x10 | 0 |

## n64HeapGetMaxFreeBlockSize  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `n64HeapGetMaxFreeBlockSize` | 0x8007E4F4 | 0x5C | 0 |

## n64HeapGetNumFragments  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `n64HeapGetNumFragments` | 0x8007E550 | 0x54 | 0 |

## n64HeapGetTotalHandles  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `n64HeapGetTotalHandles` | 0x8007E5A4 | 0x30 | 0 |

## n64HeapGetTotalMemFree  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `n64HeapGetTotalMemFree` | 0x8007E4A4 | 0x50 | 0 |

## n64HeapGetTotalMemUsed  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `n64HeapGetTotalMemUsed` | 0x8007E45C | 0x48 | 0 |

## n64HeapInit  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `n64HeapInit` | 0x8007DFC0 | 0x7C | 0 |

## n64HeapResetAllocCumulative  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `n64HeapResetAllocCumulative` | 0x8007E734 | 0xC | 0 |

## n64HeapStats  (1 funcs, top out-degree 10)

| function | addr | size | calls |
|---|---|---|---|
| `n64HeapStats` | 0x8007E5D4 | 0x160 | 10 |

## n64HeapUnalloc  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `n64HeapUnalloc` | 0x8007E328 | 0x134 | 0 |

## proutSprintf  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `proutSprintf` | 0x800B62B0 | 0x24 | 1 |

## ptr  (1 funcs, top out-degree 5)

| function | addr | size | calls |
|---|---|---|---|
| `ptr_check` | 0x800815A8 | 0x4C0 | 5 |

## rmonPrintf  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `rmonPrintf` (data?) | 0x800B3BFC | 0x24 |  |

## rotate  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `rotate_and_translate_mino` | 0x80066C10 | 0xB8 | 0 |

## schedule  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `schedule_insns_bug` | 0x80081C74 | 0x54 | 0 |

## send  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `send_mesg` (data?) | 0x800BBD04 | 0xE8 |  |

## set  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `set_total_wonder_lines` | 0x8007BC90 | 0x24 | 0 |

## setLineCount  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `setLineCount` | 0x8005283C | 0x24 | 0 |

## setPlayerTopOutOrder  (1 funcs, top out-degree 1)

| function | addr | size | calls |
|---|---|---|---|
| `setPlayerTopOutOrder` | 0x800509C0 | 0xA4 | 1 |

## sinf  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `sinf` (data?) | 0x800B7B40 | 0x1C0 |  |

## sins  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `sins` | 0x800B8010 | 0x70 | 0 |

## strength  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `strength_reduce_bug` | 0x80081CC8 | 0x54 | 0 |

## updateLineCount  (1 funcs, top out-degree 2)

| function | addr | size | calls |
|---|---|---|---|
| `updateLineCount` | 0x800527AC | 0x80 | 2 |

## updateLinesToBeAdded  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `updateLinesToBeAdded` | 0x800529A8 | 0x14 | 0 |

## vec4  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `vec4_dot` | 0x800B1078 | 0x48 | 0 |

## viMgrMain  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `viMgrMain` (data?) | 0x800B71E0 | 0x190 |  |

## weird  (1 funcs, top out-degree 0)

| function | addr | size | calls |
|---|---|---|---|
| `weird_lots_of_magic_number_setting_66xrefs` | 0x80057460 | 0x1BE8 | 0 |

## ~unlabeled (FUN_/func_)  (696 funcs, top out-degree 351)

| function | addr | size | calls |
|---|---|---|---|
| `func_8003AD80` (data?) | 0x8003AD80 | 0x50 |  |
| `FUN_001050_checkEepromSize_and_AllocHeap` | 0x8003AF0C | 0x19C | 3 |
| `FUN_001050_eepromWrite` | 0x8003B0A8 | 0x184 | 1 |
| `FUN_001050_eepromRead` | 0x8003B22C | 0x70 | 1 |
| `FUN_001500_motorInit` | 0x8003B29C | 0x148 | 3 |
| `FUN_001050_8003b3e4_motor_sendrecvmsg_3` | 0x8003B3E4 | 0x84 | 2 |
| `FUN_001050_8003b468_motor_sendmsg_0` | 0x8003B468 | 0x6C | 1 |
| `FUN_001050_8003b4d4_motor_sendmsg_1` | 0x8003B4D4 | 0x70 | 1 |
| `FUN_001050_8003b544_motor_sendmsg_2` | 0x8003B544 | 0x8C | 1 |
| `FUN_001050_8003b5d0_controller_sendrecvmsg` | 0x8003B5D0 | 0x6C | 2 |
| `FUN_001050_getControllerType` | 0x8003B63C | 0x18 | 0 |
| `FUN_001050_getControllerStatus` | 0x8003B654 | 0x18 | 0 |
| `FUN_001050_getControllerErrNo` | 0x8003B66C | 0x18 | 0 |
| `FUN_001050_cpakInit` | 0x8003B684 | 0x64 | 2 |
| `FUN_001050_cpakRead` | 0x8003B6E8 | 0xC0 | 2 |
| `FUN_001050_cpakWrite` | 0x8003B7A8 | 0xC0 | 2 |
| `FUN_001050_cpakAllocFile` | 0x8003B868 | 0x8C | 2 |
| `FUN_001050_cpakFindFile` | 0x8003B8F4 | 0x8C | 2 |
| `FUN_001050_cpakDeleteFile` | 0x8003B980 | 0x8C | 2 |
| `FUN_001050_cpakNumFiles` | 0x8003BA0C | 0x78 | 2 |
| `FUN_001050_cpakFileState` | 0x8003BA84 | 0xA0 | 2 |
| `FUN_001050_cpakRepairId` | 0x8003BB24 | 0x8C | 2 |
| `FUN_001050_cpakFreeBlocks` | 0x8003BBB0 | 0x8C | 2 |
| `FUN_001050_gbpakInit` | 0x8003BC3C | 0x74 | 2 |
| `FUN_001050_gbpakReadId` | 0x8003BCB0 | 0x78 | 2 |
| `FUN_001050_gbpakReadWrite_a` | 0x8003BD28 | 0x78 | 2 |
| `FUN_001050_gbpakReadWrite_b` | 0x8003BDA0 | 0x78 | 2 |
| `FUN_001050_gbpakReadWrite_c` | 0x8003BE18 | 0xBC | 2 |
| `FUN_001050_gbpakReadWrite_d` | 0x8003BED4 | 0xBC | 2 |
| `FUN_001050_ControllerThread` | 0x8003BF90 | 0x1BD0 | 88 |
| `FUN_001050_Create_and_Start_ControllerThread` | 0x8003DB60 | 0x60 | 2 |
| `FUN_003E40_8003dbc0_twentyliner_nested_loops` | 0x8003DBC0 | 0x1E8 | 6 |
| `FUN_003E40_8003dda8_twentyfiveliner_nested_loops` | 0x8003DDA8 | 0x1F8 | 6 |
| `FUN_004220_8003dfa0_sixliner_allocs_heap_x962` | 0x8003DFA0 | 0x64 | 1 |
| `FUN_004220_8003e004_threeliner_unallocs_heap` | 0x8003E004 | 0x34 | 1 |
| `FUN_004220_8003e038_twentytwoliner_nested_loops` | 0x8003E038 | 0x1A8 | 3 |
| `FUN_005580_8003f300_fourteenliner_recursive` | 0x8003F300 | 0x1F4 | 4 |
| `FUN_005580_8003f4f4_thirtyliner_nested_loops` | 0x8003F4F4 | 0x22C | 0 |
| `FUN_005580_8003f720_fiveliner_sets_arg0_elems_to_args1to4` | 0x8003F720 | 0x40 | 0 |
| `FUN_005580_8003f760_twoliner_calls_fun` | 0x8003F760 | 0x4C | 1 |
| `FUN_005580_8003f7ac_hugefun_currpiece_stuff_recursive` | 0x8003F7AC | 0x950 | 26 |
| `FUN_005580_800400fc_largefun_more_currpiece_stuff` | 0x800400FC | 0x404 | 9 |
| `FUN_006780_80040500_twentyfiveliner_loops` | 0x80040500 | 0x1B0 | 9 |
| `FUN_006930_800406b0_fifteenliner_two_loops` | 0x800406B0 | 0xD4 | 0 |
| `FUN_006930_80040784_nested_loop_20t_inside_loop_10t` | 0x80040784 | 0x12C | 0 |
| `FUN_006B30_800408b0_fiveliner_loops_4t` | 0x800408B0 | 0x80 | 0 |
| `FUN_006BB0_80040930_large_eightyliner` | 0x80040930 | 0x66C | 1 |
| `FUN_006BB0_80040f9c_twentyfiveliner_loops_200t` | 0x80040F9C | 0x1D4 | 7 |
| `FUN_0073F0_80041170_fifteenliner_pf_logic_cell` | 0x80041170 | 0xF0 | 1 |
| `FUN_80041260_twoliner` | 0x80041260 | 0x3C | 2 |
| `FUN_8004129c_fourliner` | 0x8004129C | 0x44 | 2 |
| `FUN_800412e0_fifteenliner_logic_cell` | 0x800412E0 | 0xE0 | 2 |
| `FUN_800413c0_twentyfive_liner` | 0x800413C0 | 0x30C | 3 |
| `FUN_800416cc_fourliner` | 0x800416CC | 0x60 | 2 |
| `FUN_8004172c_twentyliner` | 0x8004172C | 0xE4 | 2 |
| `FUN_80041810_twentyliner` | 0x80041810 | 0x10C | 4 |
| `FUN_8004191c_sixliner_loop_shift_right` | 0x8004191C | 0x80 | 0 |
| `FUN_8004199c_twentyliner_loop` | 0x8004199C | 0x118 | 3 |
| `FUN_80041ab4_tenliner_loop` | 0x80041AB4 | 0x94 | 0 |
| `FUN_80041da0_threeliner` | 0x80041DA0 | 0x30 | 0 |
| `FUN_008050_80041dd0_alloc_heap_4_and_x640` | 0x80041DD0 | 0x54 | 2 |
| `FUN_008050_80041e24_maybe_calls_unalloc_heap` | 0x80041E24 | 0x64 | 2 |
| `FUN_008050_80041e88_loops_200_times` | 0x80041E88 | 0x68 | 0 |
| `FUN_008050_80041ef0_twentyliner` | 0x80041EF0 | 0xDC | 0 |
| `FUN_008050_80041fcc_twentyliner_case4` | 0x80041FCC | 0x10C | 1 |
| `FUN_008050_800420d8_fifteenliner` | 0x800420D8 | 0xAC | 0 |
| `FUN_008050_80042184_fifteenliner_loop` | 0x80042184 | 0x170 | 6 |
| `FUN_008050_800422f4_threeliner` | 0x800422F4 | 0x74 | 3 |
| `FUN_008050_80042368_threeliner` | 0x80042368 | 0x88 | 3 |
| `FUN_008050_800423f0_uses_dat_800e1f40_ptr` | 0x800423F0 | 0x348 | 4 |
| `FUN_008050_80042738_passes_dat_800e1f40_ptr` | 0x80042738 | 0x80 | 1 |
| `FUN_008050_800427b8_passes_dat_800e1f40_ptr` | 0x800427B8 | 0x48 | 1 |
| `FUN_80048020_eightliner` | 0x80048020 | 0xB8 | 0 |
| `func_800480D8_nevercalled` | 0x800480D8 | 0x8 | 0 |
| `FUN_800480E0_threeliner_glist` | 0x800480E0 | 0x70 | 2 |
| `FUN_80048150_threeliner_vlist` | 0x80048150 | 0x70 | 2 |
| `FUN_800481C0_allocs_heap` | 0x800481C0 | 0x15C | 9 |
| `FUN_8004831C_allocs_heap` | 0x8004831C | 0xCC | 5 |
| `FUN_800483E8_allocs_heap` | 0x800483E8 | 0xCC | 5 |
| `FUN_80048934_inits_struct_q` | 0x80048934 | 0x138 | 0 |
| `FUN_80048A6C_inits_struct_q` | 0x80048A6C | 0xF8 | 0 |
| `FUN_010870_interesting_stuff_large_liner` | 0x8004A5F0 | 0x5F8 | 21 |
| `FUN_010870_8004abe8_fifteenliner_1` | 0x8004ABE8 | 0xC8 | 0 |
| `FUN_010870_8004acb0_fifteenliner_2` | 0x8004ACB0 | 0xCC | 0 |
| `FUN_010870_OptionsDataMenu` | 0x8004AD7C | 0x57A4 | 302 |
| `FUN_800507e4_twoliner` | 0x800507E4 | 0x1C | 0 |
| `FUN_80050800_oneliner` | 0x80050800 | 0x20 | 0 |
| `FUN_80050820_oneliner` | 0x80050820 | 0x20 | 0 |
| `FUN_80050840_fiveliner` | 0x80050840 | 0x68 | 1 |
| `FUN_800508a8_fiveliner` | 0x800508A8 | 0x44 | 0 |
| `FUN_800508ec_fifteen_liner_allocs_heap` | 0x800508EC | 0xD4 | 2 |
| `FUN_80053500_fiveliner` | 0x80053500 | 0x38 | 3 |
| `FUN_80053538_fiveliner` | 0x80053538 | 0x68 | 1 |
| `FUN_800535B8_fiveliner` | 0x800535B8 | 0x54 | 2 |
| `func_8005360C` | 0x8005360C | 0x64 | 1 |
| `FUN_80055704_threeliner` | 0x80055704 | 0x40 | 3 |
| `FUN_01D300_80057080_nevercalled` | 0x80057080 | 0x30 | 0 |
| `FUN_01D300_800570b0_fiveliner` | 0x800570B0 | 0x64 | 4 |
| `FUN_01D300_n64HeapUnalloc` | 0x80057114 | 0x2C | 1 |
| `FUN_01D300_80057140_sixliner` | 0x80057140 | 0x94 | 1 |
| `FUN_01D300_800571d4_twentyliner` | 0x800571D4 | 0x124 | 7 |
| `FUN_01D300_800572f8_twoliner` | 0x800572F8 | 0x40 | 2 |
| `FUN_01D300_80057338_fifteenliner` | 0x80057338 | 0x128 | 2 |
| `FUN_8005aa9c_prob_display_text_rgb_as_well` | 0x8005AA9C | 0x1160 | 0 |
| `func_8005BBFC` | 0x8005BBFC | 0x244 | 0 |
| `func_8005BE40` | 0x8005BE40 | 0xA0 | 0 |
| `func_8005BEE0` | 0x8005BEE0 | 0x1CB0 | 0 |
| `func_8005DB90` | 0x8005DB90 | 0x1080 | 0 |
| `func_80060680` | 0x80060680 | 0x84 | 0 |
| `func_80060704` | 0x80060704 | 0x38 | 0 |
| `FUN_026900_sets_arg0_struct_to_arg1_arg2` | 0x8006073C | 0x34 | 0 |
| `FUN_026900_80060770_sevenliner` | 0x80060770 | 0xA4 | 0 |
| `FUN_026900_PRNG_1` | 0x80060814 | 0x7C | 0 |
| `FUN_026900_sets_g8011FA70_to_arg0` | 0x80060890 | 0xC | 0 |
| `FUN_026900_PRNG_2` | 0x8006089C | 0x58 | 0 |
| `FUN_026900_800608f4_oneliner_shift6_1` | 0x800608F4 | 0x20 | 0 |
| `FUN_026900_80060914_oneliner_shift6_2` | 0x80060914 | 0x28 | 0 |
| `FUN_026900_8006093c_rounds_floors_loops_1024t` | 0x8006093C | 0xC4 | 1 |
| `FUN_026C80_80060a00_fourliner_sets_arg0_e0123` | 0x80060A00 | 0x1C | 0 |
| `FUN_026C80_80060a1c_twoliner_sets_arg0_e01` | 0x80060A1C | 0xC | 0 |
| `FUN_026C80_80060a28_twelveliner_retbool` | 0x80060A28 | 0xAC | 0 |
| `FUN_026C80_80060ad4_oneliner_calls_fun` | 0x80060AD4 | 0x30 | 1 |
| `FUN_026C80_80060b04_twelveliner_loops_32t` | 0x80060B04 | 0xD0 | 1 |
| `FUN_026C80_GU_or_ControllerRepeat_Update` | 0x80060BD4 | 0xCC | 2 |
| `FUN_026C80_nineliner_loops_32t` | 0x80060CA0 | 0x70 | 1 |
| `func_80060D10` | 0x80060D10 | 0x48 | 1 |
| `func_80060D58` | 0x80060D58 | 0xD8 | 2 |
| `func_80060E30` | 0x80060E30 | 0x2DC | 9 |
| `func_8006110C` | 0x8006110C | 0x18 | 0 |
| `func_80061124` | 0x80061124 | 0x10 | 0 |
| `func_80061134` | 0x80061134 | 0x64 | 0 |
| `func_80061198` | 0x80061198 | 0x48 | 3 |
| `func_800611E0` | 0x800611E0 | 0x2C8 | 1 |
| `func_800614A8` | 0x800614A8 | 0x298 | 2 |
| `FUN_0279C0_80061740_switch_0to8_1to6_same` | 0x80061740 | 0x230 | 16 |
| `FUN_027BF0_convert_decimal_q` | 0x80061970 | 0xC4 | 5 |
| `FUN_027BF0_80061A34_does_nothing` | 0x80061A34 | 0x8 | 0 |
| `FUN_027BF0_80061a3c_tenliner_allocs_heap` | 0x80061A3C | 0xDC | 6 |
| `FUN_027BF0_check_music_settings_and_play` | 0x80061B18 | 0xC70 | 99 |
| `FUN_027BF0_Init` | 0x80062788 | 0x8F4 | 65 |
| `FUN_027BF0_8006307c_sixliner` | 0x8006307C | 0x70 | 2 |
| `FUN_027BF0_Deinit` | 0x800630EC | 0x240 | 31 |
| `FUN_027BF0_8006332c_thirtyfiveliner` | 0x8006332C | 0x2EC | 6 |
| `func_80063618` | 0x80063618 | 0x34 | 0 |
| `func_8006364C` | 0x8006364C | 0x74 | 0 |
| `FUN_027BF0_800636C0_display_game_stats_screen_q` | 0x800636C0 | 0x1620 | 143 |
| `func_8006A9A4` | 0x8006A9A4 | 0x18 | 0 |
| `FUN_032F00_8006cc80_twentyliner_checks_pnum_1_2_4` | 0x8006CC80 | 0x118 | 11 |
| `FUN_032F00_8006cd98_tenliner_checks_12` | 0x8006CD98 | 0x98 | 5 |
| `FUN_032F00_8006ce30_tenliner_magic_4000` | 0x8006CE30 | 0xAC | 5 |
| `FUN_032F00_8006cedc_sets_glb_to_fun_call_glb` | 0x8006CEDC | 0x2C | 1 |
| `FUN_032F00_MVC_control_menu_choice_process` | 0x8006CF14 | 0x17C | 17 |
| `FUN_033310_setPieceDef` | 0x8006D090 | 0x1C | 0 |
| `FUN_033310_getPhysicalCurPieceSpawnPos` | 0x8006D0AC | 0x70 | 1 |
| `FUN_033310_getPhysicalStartingRotOrigin` | 0x8006D11C | 0x60 | 1 |
| `FUN_033310_Init` | 0x8006D17C | 0x18 | 0 |
| `FUN_033310_Deinit` | 0x8006D194 | 0x1C | 0 |
| `func_8006F39C` | 0x8006F39C | 0x118 | 0 |
| `func_8006F7E8` | 0x8006F7E8 | 0x8 | 0 |
| `func_80071730` | 0x80071730 | 0x10C | 1 |
| `func_8007183C` | 0x8007183C | 0x204 | 0 |
| `func_80071A40` | 0x80071A40 | 0xC8 | 1 |
| `func_80071B08` | 0x80071B08 | 0x24 | 0 |
| `func_80071B2C` | 0x80071B2C | 0x18 | 0 |
| `func_80071B44` | 0x80071B44 | 0x44 | 3 |
| `func_80071B88` | 0x80071B88 | 0x34 | 1 |
| `func_80071BBC` | 0x80071BBC | 0x34 | 1 |
| `func_80071DEC` | 0x80071DEC | 0x6C | 6 |
| `func_80071E58` | 0x80071E58 | 0x268 | 11 |
| `func_800720C0` | 0x800720C0 | 0x80 | 2 |
| `func_80072140` | 0x80072140 | 0x64 | 1 |
| `func_800721A4` | 0x800721A4 | 0x34 | 2 |
| `func_800721D8` | 0x800721D8 | 0x70 | 2 |
| `func_80072248` | 0x80072248 | 0x98 | 3 |
| `func_800722E0` | 0x800722E0 | 0x20 | 0 |
| `func_80072300` | 0x80072300 | 0x2C | 0 |
| `func_8007232C` | 0x8007232C | 0x74 | 0 |
| `func_80072494` | 0x80072494 | 0x2C | 0 |
| `func_800724C0` | 0x800724C0 | 0x48 | 1 |
| `func_80072508` | 0x80072508 | 0x74 | 3 |
| `func_8007257C` | 0x8007257C | 0x94 | 3 |
| `func_80072610` | 0x80072610 | 0x94 | 3 |
| `func_800726A4` | 0x800726A4 | 0x198 | 4 |
| `func_80072A84` | 0x80072A84 | 0xAC | 5 |
| `func_80072B30` | 0x80072B30 | 0x28 | 0 |
| `func_80072B58` | 0x80072B58 | 0x54 | 1 |
| `func_80072BAC` | 0x80072BAC | 0x11C | 4 |
| `func_80072CC8` | 0x80072CC8 | 0x5C | 1 |
| `func_80072D24` | 0x80072D24 | 0x14 | 0 |
| `func_80072E34` | 0x80072E34 | 0x8 | 0 |
| `func_80072E3C` | 0x80072E3C | 0xE0 | 3 |
| `func_80072F1C` | 0x80072F1C | 0x94 | 1 |
| `func_80072FB0` | 0x80072FB0 | 0x14 | 0 |
| `func_80072FC4` | 0x80072FC4 | 0x50 | 0 |
| `func_80073014` | 0x80073014 | 0x1C | 0 |
| `func_80073030` | 0x80073030 | 0x100 | 1 |
| `func_80073130` | 0x80073130 | 0x40 | 0 |
| `func_80073170` | 0x80073170 | 0x8 | 0 |
| `func_80073178` | 0x80073178 | 0x14 | 0 |
| `func_8007318C` | 0x8007318C | 0x60 | 1 |
| `func_800731EC` | 0x800731EC | 0x204 | 2 |
| `func_800733F0` | 0x800733F0 | 0x1E8 | 0 |
| `func_800735D8` | 0x800735D8 | 0xB0 | 4 |
| `func_80073688` | 0x80073688 | 0x8 | 0 |
| `func_80073690` | 0x80073690 | 0x50 | 1 |
| `func_800736E0` | 0x800736E0 | 0xA4 | 2 |
| `func_80073784` | 0x80073784 | 0x78 | 1 |
| `func_800737FC` | 0x800737FC | 0x144 | 0 |
| `func_80073940` | 0x80073940 | 0x184 | 6 |
| `func_80073AC4` | 0x80073AC4 | 0x84 | 2 |
| `func_80073B48` | 0x80073B48 | 0x5C | 4 |
| `func_80073BA4` | 0x80073BA4 | 0x2C | 1 |
| `func_80073BD0` | 0x80073BD0 | 0x90 | 0 |
| `func_80073C60` | 0x80073C60 | 0x110 | 6 |
| `func_80073D70` | 0x80073D70 | 0x2B4 | 1 |
| `func_80074024` | 0x80074024 | 0x328 | 1 |
| `func_8007434C` | 0x8007434C | 0xAC | 4 |
| `func_800743F8` | 0x800743F8 | 0xC8 | 1 |
| `func_800744C0` | 0x800744C0 | 0x10 | 0 |
| `func_800744D0` | 0x800744D0 | 0x10C | 6 |
| `func_800745DC` | 0x800745DC | 0xE4 | 4 |
| `FUN_03A750_800746c0_twentyliner` | 0x800746C0 | 0x1C8 | 11 |
| `FUN_03A750_80074888_twelveliner` | 0x80074888 | 0x118 | 6 |
| `func_800749A0` | 0x800749A0 | 0x1E0 | 7 |
| `func_80074B80` | 0x80074B80 | 0x100 | 1 |
| `func_80074C80` | 0x80074C80 | 0xFC | 1 |
| `func_80074D7C` | 0x80074D7C | 0xC0 | 0 |
| `func_80074E3C` | 0x80074E3C | 0x88 | 1 |
| `func_80074EC4` | 0x80074EC4 | 0x78 | 3 |
| `func_80074F3C` | 0x80074F3C | 0x244 | 0 |
| `func_80075180` | 0x80075180 | 0x40 | 0 |
| `func_800751C0` | 0x800751C0 | 0x58 | 0 |
| `func_80075218` | 0x80075218 | 0x24 | 0 |
| `func_8007523C` | 0x8007523C | 0x1C4 | 7 |
| `func_80075400` | 0x80075400 | 0x80 | 3 |
| `func_80075480` | 0x80075480 | 0x228 | 1 |
| `func_800756A8` | 0x800756A8 | 0x38 | 1 |
| `func_800756E0` | 0x800756E0 | 0x20 | 0 |
| `func_80075700` | 0x80075700 | 0x60 | 0 |
| `func_80075760` | 0x80075760 | 0x5C | 0 |
| `func_800757BC` | 0x800757BC | 0x74 | 0 |
| `func_80075830` | 0x80075830 | 0x40 | 3 |
| `func_80075870` | 0x80075870 | 0x40 | 2 |
| `func_80075DBC` | 0x80075DBC | 0x38 | 0 |
| `func_80075DF4` | 0x80075DF4 | 0xBC | 13 |
| `FUN_03C130_80075EB0_nineliner_allocs_heap` | 0x80075EB0 | 0xAC | 8 |
| `func_80075F5C` | 0x80075F5C | 0x44 | 2 |
| `func_80075FA0` | 0x80075FA0 | 0xC | 0 |
| `func_80075FAC` | 0x80075FAC | 0x148 | 2 |
| `func_800760F4` | 0x800760F4 | 0xDC | 1 |
| `func_800761D0` | 0x800761D0 | 0x11C | 1 |
| `func_800762EC` | 0x800762EC | 0x70 | 0 |
| `func_8007635C` | 0x8007635C | 0x58 | 4 |
| `func_800763B4` | 0x800763B4 | 0x38 | 2 |
| `func_800763EC` | 0x800763EC | 0x30 | 1 |
| `func_8007641C` | 0x8007641C | 0x3C | 0 |
| `func_80076458` | 0x80076458 | 0x48 | 1 |
| `func_800764A0` | 0x800764A0 | 0x18 | 0 |
| `func_800764B8` | 0x800764B8 | 0x210 | 9 |
| `func_800766C8` | 0x800766C8 | 0xF8 | 4 |
| `func_800767C0` | 0x800767C0 | 0x6E0 | 6 |
| `func_80076EA0` | 0x80076EA0 | 0x8 | 0 |
| `func_80076EA8` | 0x80076EA8 | 0x18 | 0 |
| `func_80076EC0` | 0x80076EC0 | 0x60 | 3 |
| `func_80076F20` | 0x80076F20 | 0x108 | 6 |
| `func_80077028` | 0x80077028 | 0x70 | 2 |
| `func_80077098` | 0x80077098 | 0x30C | 7 |
| `func_800773A4` | 0x800773A4 | 0x14 | 0 |
| `func_800773B8` | 0x800773B8 | 0x18 | 0 |
| `FUN_SRAM_80078300_twelveliner_div60_loop_30t_a` | 0x80078300 | 0x124 | 0 |
| `FUN_SRAM_80078424_twelveliner_div60_loop_30t_b` | 0x80078424 | 0x110 | 0 |
| `FUN_SRAM_80078534_tenliner_loops` | 0x80078534 | 0xAC | 1 |
| `FUN_SRAM_800785e0_sixliner_loop_arg0_t` | 0x800785E0 | 0xAC | 1 |
| `FUN_SRAM_8007868c_tenliner_loop_arg0_t` | 0x8007868C | 0xD0 | 1 |
| `FUN_SRAM_8007875c_check_gameover_conditions` | 0x8007875C | 0xE7C | 5 |
| `FUN_SRAM_800795d8_fourteenliner_loops_8t` | 0x800795D8 | 0x78 | 0 |
| `func_80079650` | 0x80079650 | 0x78 | 0 |
| `func_800796C8` | 0x800796C8 | 0x228 | 2 |
| `func_800798F0` | 0x800798F0 | 0x684 | 13 |
| `func_80079F74` | 0x80079F74 | 0x1C | 0 |
| `func_80079F90` | 0x80079F90 | 0xE8 | 1 |
| `func_8007A078` | 0x8007A078 | 0x428 | 14 |
| `func_8007A4A0` | 0x8007A4A0 | 0x68 | 0 |
| `func_8007A508` | 0x8007A508 | 0x30 | 0 |
| `func_8007A538` | 0x8007A538 | 0x2C | 0 |
| `func_8007A564` | 0x8007A564 | 0x70 | 0 |
| `func_8007A5D4` | 0x8007A5D4 | 0x58 | 0 |
| `func_8007A62C` | 0x8007A62C | 0x1C | 0 |
| `func_8007A648` | 0x8007A648 | 0x18 | 0 |
| `func_8007A660` | 0x8007A660 | 0x64 | 0 |
| `func_8007A6C4` | 0x8007A6C4 | 0x74 | 0 |
| `func_8007A738` | 0x8007A738 | 0x318 | 7 |
| `func_8007AA50` | 0x8007AA50 | 0xC | 0 |
| `func_8007AA5C` | 0x8007AA5C | 0x80 | 0 |
| `func_8007AADC` | 0x8007AADC | 0x34 | 0 |
| `func_8007AB10` | 0x8007AB10 | 0x3A0 | 0 |
| `func_8007AEB0` | 0x8007AEB0 | 0xD8 | 2 |
| `func_8007AF88` | 0x8007AF88 | 0x404 | 25 |
| `func_8007B38C` | 0x8007B38C | 0x94 | 6 |
| `func_8007B420` | 0x8007B420 | 0x10 | 0 |
| `func_8007B430` | 0x8007B430 | 0x478 | 22 |
| `func_8007B8A8` | 0x8007B8A8 | 0xBC | 0 |
| `func_8007B964` | 0x8007B964 | 0xD4 | 0 |
| `func_8007BA38` | 0x8007BA38 | 0x4C | 0 |
| `func_8007BA84` | 0x8007BA84 | 0xD0 | 3 |
| `func_8007BB54` | 0x8007BB54 | 0x13C | 2 |
| `func_8007BCC4` | 0x8007BCC4 | 0x84 | 0 |
| `func_8007BD48` | 0x8007BD48 | 0x90 | 0 |
| `func_8007BDD8` | 0x8007BDD8 | 0x314 | 15 |
| `func_8007C5CC` | 0x8007C5CC | 0x84 | 5 |
| `func_8007C650` | 0x8007C650 | 0x260 | 1 |
| `func_8007C8B0` | 0x8007C8B0 | 0x214 | 8 |
| `func_8007CAC4` | 0x8007CAC4 | 0x150 | 2 |
| `func_8007CC14` | 0x8007CC14 | 0x32C | 3 |
| `func_8007CF40` | 0x8007CF40 | 0x2D4 | 7 |
| `func_8007D214` | 0x8007D214 | 0x48 | 3 |
| `func_8007D25C` | 0x8007D25C | 0x1FC | 4 |
| `func_8007D458` | 0x8007D458 | 0xB8 | 0 |
| `func_8007D510` | 0x8007D510 | 0x198 | 3 |
| `func_8007D6A8` | 0x8007D6A8 | 0x358 | 4 |
| `func_8007DA00` | 0x8007DA00 | 0x5C0 | 13 |
| `func_8007E750` | 0x8007E750 | 0x2A8 | 1 |
| `func_8007E9F8` | 0x8007E9F8 | 0x34 | 0 |
| `func_8007EA2C` | 0x8007EA2C | 0x29C | 1 |
| `func_8007ECC8` | 0x8007ECC8 | 0x38 | 0 |
| `func_8007ED00` | 0x8007ED00 | 0x2B0 | 1 |
| `func_8007EFB0` | 0x8007EFB0 | 0x34 | 0 |
| `func_8007EFE4` | 0x8007EFE4 | 0x2A4 | 1 |
| `func_8007F288` | 0x8007F288 | 0x38 | 0 |
| `func_8007F2C0` | 0x8007F2C0 | 0x60 | 4 |
| `func_8007F320` | 0x8007F320 | 0x24 | 1 |
| `func_8007F344` | 0x8007F344 | 0x86C | 44 |
| `func_8007FBB0` | 0x8007FBB0 | 0x64 | 4 |
| `func_8007FC14` | 0x8007FC14 | 0x60 | 0 |
| `func_8007FC74` | 0x8007FC74 | 0xA0 | 3 |
| `func_8007FD14` | 0x8007FD14 | 0x60 | 0 |
| `func_8007FD74` | 0x8007FD74 | 0x10 | 0 |
| `func_8007FD84` | 0x8007FD84 | 0x2C | 1 |
| `FUN_046770_800804f0_many_heapallocs_for_arg0_elems` | 0x800804F0 | 0x25C | 19 |
| `FUN_046770_8008074c_nineliner_calls_9funcs_warg0_elems` | 0x8008074C | 0xC0 | 9 |
| `FUN_046770_8008080c_threeliner_sets_arg0` | 0x8008080C | 0x50 | 0 |
| `FUN_046770_magic_150_is_it_ultra_related` | 0x8008085C | 0x214 | 7 |
| `func_80080B50` | 0x80080B50 | 0x300 | 19 |
| `func_80080E50` | 0x80080E50 | 0x5C | 1 |
| `func_80080EAC` | 0x80080EAC | 0x8 | 0 |
| `func_80080EB4` | 0x80080EB4 | 0x14 | 0 |
| `func_80080EC8` | 0x80080EC8 | 0x40 | 1 |
| `func_80080F08` | 0x80080F08 | 0x28 | 1 |
| `func_80080F30` | 0x80080F30 | 0x30 | 1 |
| `func_80083100` | 0x80083100 | 0x3C | 2 |
| `func_8008313C` | 0x8008313C | 0x24 | 1 |
| `func_80083160` | 0x80083160 | 0x1C0 | 10 |
| `func_8008369C` | 0x8008369C | 0x160 | 1 |
| `func_800837FC` | 0x800837FC | 0x114 | 3 |
| `func_80083910` | 0x80083910 | 0xA80 | 51 |
| `func_80084390` | 0x80084390 | 0x100 | 3 |
| `func_80084490` | 0x80084490 | 0xEC | 5 |
| `func_8008457C` | 0x8008457C | 0xB4 | 5 |
| `func_80084630` | 0x80084630 | 0xD0 | 3 |
| `func_80084C90` | 0x80084C90 | 0x8 | 0 |
| `func_80085CF4` | 0x80085CF4 | 0x10 | 0 |
| `func_800875E4` | 0x800875E4 | 0x8 | 0 |
| `func_800875EC` | 0x800875EC | 0x14 | 0 |
| `func_80087600` | 0x80087600 | 0x18 | 0 |
| `func_8008EFA0` | 0x8008EFA0 | 0x130 | 0 |
| `func_8008F0D0` | 0x8008F0D0 | 0x1B0 | 0 |
| `func_8008F280` | 0x8008F280 | 0xE0 | 4 |
| `func_8008F360` | 0x8008F360 | 0xC18 | 34 |
| `func_8008FF78` | 0x8008FF78 | 0x3E4 | 11 |
| `func_8009035C` | 0x8009035C | 0x28C | 15 |
| `func_800905E8` | 0x800905E8 | 0x3A4 | 19 |
| `func_8009098C` | 0x8009098C | 0xB8 | 6 |
| `func_80090A44` | 0x80090A44 | 0x7C | 4 |
| `func_80090AC0` | 0x80090AC0 | 0x348 | 11 |
| `func_80090E08` | 0x80090E08 | 0x638 | 30 |
| `func_80091440` | 0x80091440 | 0x304 | 5 |
| `func_80091744` | 0x80091744 | 0x348 | 5 |
| `func_80091A8C` | 0x80091A8C | 0x2D4 | 5 |
| `func_80091D60` | 0x80091D60 | 0x7914 | 351 |
| `func_80099674` | 0x80099674 | 0x3D8C | 90 |
| `func_8009D400` | 0x8009D400 | 0x1E4 | 15 |
| `func_8009D5E4` | 0x8009D5E4 | 0x35C | 21 |
| `func_8009D940` | 0x8009D940 | 0x8 | 0 |
| `func_8009D948` | 0x8009D948 | 0x2A4 | 0 |
| `func_8009DBEC` | 0x8009DBEC | 0x208 | 2 |
| `func_8009DDF4` | 0x8009DDF4 | 0x4C | 1 |
| `func_8009DE40` | 0x8009DE40 | 0x1B8 | 0 |
| `func_8009DFF8` | 0x8009DFF8 | 0x454 | 0 |
| `func_8009E44C` | 0x8009E44C | 0xA88 | 0 |
| `func_8009EED4` | 0x8009EED4 | 0x408 | 16 |
| `func_8009F2DC` | 0x8009F2DC | 0x5C | 4 |
| `func_8009F338` | 0x8009F338 | 0x70 | 2 |
| `func_8009F3A8` | 0x8009F3A8 | 0x19C | 0 |
| `func_8009F544` | 0x8009F544 | 0x4E8 | 16 |
| `func_8009FA2C` | 0x8009FA2C | 0x4DC | 16 |
| `func_8009FF08` | 0x8009FF08 | 0x320 | 1 |
| `func_800A0228` | 0x800A0228 | 0x258 | 5 |
| `func_800A0480` | 0x800A0480 | 0x14 | 0 |
| `func_800A0494` | 0x800A0494 | 0x14 | 0 |
| `func_800A04A8` | 0x800A04A8 | 0x4C | 0 |
| `func_800A04F4` | 0x800A04F4 | 0x1DC | 6 |
| `func_800A06D0` | 0x800A06D0 | 0x1D0 | 6 |
| `func_800A08A0` | 0x800A08A0 | 0x4C | 0 |
| `func_800A08EC` | 0x800A08EC | 0x90 | 2 |
| `func_800A097C` | 0x800A097C | 0x8C | 2 |
| `func_800A0A08` | 0x800A0A08 | 0x3C | 1 |
| `func_800A0A44` | 0x800A0A44 | 0x61C | 16 |
| `func_800A1060` | 0x800A1060 | 0x61C | 16 |
| `func_800A167C` | 0x800A167C | 0x61C | 16 |
| `func_800A1C98` | 0x800A1C98 | 0x4B0 | 15 |
| `func_800A2148` | 0x800A2148 | 0x674 | 24 |
| `func_800A27BC` | 0x800A27BC | 0xB0 | 4 |
| `func_800A286C` | 0x800A286C | 0x10 | 0 |
| `func_800A287C` | 0x800A287C | 0x8 | 0 |
| `func_800A2884` | 0x800A2884 | 0x210 | 6 |
| `func_800A2A94` | 0x800A2A94 | 0x10 | 0 |
| `func_800A2AA4` | 0x800A2AA4 | 0x388 | 9 |
| `func_800A2E2C` | 0x800A2E2C | 0xC4 | 0 |
| `func_800A2EF0` | 0x800A2EF0 | 0x10 | 0 |
| `func_800A2F00` | 0x800A2F00 | 0x30 | 0 |
| `func_800A2F30` | 0x800A2F30 | 0x20 | 0 |
| `func_800A2F50` | 0x800A2F50 | 0x60 | 0 |
| `func_800A2FB0` | 0x800A2FB0 | 0x140 | 0 |
| `func_800A30F0` | 0x800A30F0 | 0x1C0 | 0 |
| `func_800A32B0` | 0x800A32B0 | 0x30 | 0 |
| `func_800A32E0` | 0x800A32E0 | 0x20 | 0 |
| `FUN_069580_800A3300_nineliner_mod300` | 0x800A3300 | 0xE4 | 0 |
| `func_800A33E4` | 0x800A33E4 | 0x7C | 2 |
| `func_800A3460` | 0x800A3460 | 0x48 | 2 |
| `FUN_069580_800A34A8_tenliner_allocs_heap` | 0x800A34A8 | 0x84 | 5 |
| `func_800A352C` | 0x800A352C | 0x8 | 0 |
| `func_800A3534` | 0x800A3534 | 0x1C | 0 |
| `func_800A3550` | 0x800A3550 | 0x5C | 1 |
| `func_800A35AC` | 0x800A35AC | 0x40 | 0 |
| `func_800A35EC` | 0x800A35EC | 0x6C | 1 |
| `func_800A3658` | 0x800A3658 | 0x34 | 1 |
| `func_800A368C` | 0x800A368C | 0x64 | 1 |
| `func_800A36F0` | 0x800A36F0 | 0x68 | 1 |
| `func_800A3758` | 0x800A3758 | 0x98 | 1 |
| `func_800A37F0` | 0x800A37F0 | 0x50 | 0 |
| `func_800A3840` | 0x800A3840 | 0x78 | 1 |
| `func_800A38B8` | 0x800A38B8 | 0x70 | 1 |
| `func_800A3928` | 0x800A3928 | 0x88 | 1 |
| `func_800A3B00` | 0x800A3B00 | 0x20 | 0 |
| `func_800A3B20` | 0x800A3B20 | 0x38 | 0 |
| `func_800A3B58` | 0x800A3B58 | 0xA0 | 0 |
| `func_800A3BF8` | 0x800A3BF8 | 0x38 | 1 |
| `func_800A3C30` | 0x800A3C30 | 0x84 | 2 |
| `func_800A3CB4` | 0x800A3CB4 | 0x28 | 1 |
| `func_800A3CDC` | 0x800A3CDC | 0x78 | 2 |
| `func_800A3D54` | 0x800A3D54 | 0x80 | 4 |
| `func_800A3DD4` | 0x800A3DD4 | 0x38 | 1 |
| `func_800A3E0C` | 0x800A3E0C | 0x94 | 1 |
| `func_800A3EA0` | 0x800A3EA0 | 0x20 | 0 |
| `func_800A3EC0` | 0x800A3EC0 | 0x38 | 0 |
| `func_800A3EF8` | 0x800A3EF8 | 0xA0 | 0 |
| `func_800A3F98` | 0x800A3F98 | 0x38 | 1 |
| `func_800A3FD0` | 0x800A3FD0 | 0x84 | 2 |
| `func_800A4054` | 0x800A4054 | 0x3C | 0 |
| `func_800A4090` | 0x800A4090 | 0x10 | 0 |
| `func_800A40A0` | 0x800A40A0 | 0x14 | 0 |
| `func_800A40B4` | 0x800A40B4 | 0x10 | 0 |
| `func_800A40C4` | 0x800A40C4 | 0x14 | 0 |
| `func_800A40D8` | 0x800A40D8 | 0x24 | 0 |
| `func_800A40FC` | 0x800A40FC | 0x208 | 3 |
| `func_800A4304` | 0x800A4304 | 0x60 | 1 |
| `func_800A4364` | 0x800A4364 | 0x20 | 0 |
| `func_800A4384` | 0x800A4384 | 0x2C | 0 |
| `func_800A43B0` | 0x800A43B0 | 0x30 | 0 |
| `func_800A43E0` | 0x800A43E0 | 0x2C | 0 |
| `func_800A440C` | 0x800A440C | 0x2C | 0 |
| `func_800A4438` | 0x800A4438 | 0x20 | 0 |
| `func_800A4458` | 0x800A4458 | 0x28 | 0 |
| `func_800A4480` | 0x800A4480 | 0x20 | 0 |
| `func_800A44A0` | 0x800A44A0 | 0x28 | 0 |
| `func_800A44C8` | 0x800A44C8 | 0xA8 | 0 |
| `func_800A4570` | 0x800A4570 | 0x20 | 0 |
| `func_800A4590` | 0x800A4590 | 0x10 | 0 |
| `func_800A45A0` | 0x800A45A0 | 0x14 | 0 |
| `func_800A45B4` | 0x800A45B4 | 0x10 | 0 |
| `func_800A45C4` | 0x800A45C4 | 0x14 | 0 |
| `func_800A45D8` | 0x800A45D8 | 0x10 | 0 |
| `func_800A45E8` | 0x800A45E8 | 0x14 | 0 |
| `func_800A45FC` | 0x800A45FC | 0x10 | 0 |
| `func_800A460C` | 0x800A460C | 0x14 | 0 |
| `func_800A4620` | 0x800A4620 | 0x10 | 0 |
| `func_800A4630` | 0x800A4630 | 0x14 | 0 |
| `func_800A4644` | 0x800A4644 | 0x10 | 0 |
| `func_800A4654` | 0x800A4654 | 0x14 | 0 |
| `func_800A4668` | 0x800A4668 | 0x10 | 0 |
| `func_800A4678` | 0x800A4678 | 0x14 | 0 |
| `func_800A468C` | 0x800A468C | 0xC | 0 |
| `func_800A4698` | 0x800A4698 | 0x28 | 1 |
| `func_800A46C0` | 0x800A46C0 | 0x8 | 0 |
| `func_800A46C8` | 0x800A46C8 | 0x14 | 0 |
| `func_800A46DC` | 0x800A46DC | 0x38 | 0 |
| `func_800A4714` | 0x800A4714 | 0x2C | 0 |
| `func_800A4740` | 0x800A4740 | 0x10C | 0 |
| `func_800A484C` | 0x800A484C | 0x80 | 0 |
| `func_800A48CC` | 0x800A48CC | 0x3C | 0 |
| `func_800A4908` | 0x800A4908 | 0x10 | 0 |
| `func_800A4918` | 0x800A4918 | 0x14 | 0 |
| `func_800A492C` | 0x800A492C | 0x84 | 0 |
| `func_800A49B0` | 0x800A49B0 | 0xD8 | 0 |
| `func_800A4A88` | 0x800A4A88 | 0xD0 | 0 |
| `func_800A4B58` | 0x800A4B58 | 0x10 | 0 |
| `func_800A4B68` | 0x800A4B68 | 0x18 | 0 |
| `func_800A4B80` | 0x800A4B80 | 0xC | 0 |
| `func_800A4B8C` | 0x800A4B8C | 0xC | 0 |
| `func_800A4B98` | 0x800A4B98 | 0x88 | 2 |
| `func_800A4C20` | 0x800A4C20 | 0xD0 | 3 |
| `func_800A4CF0` | 0x800A4CF0 | 0x1D0 | 6 |
| `func_800A4EC0` | 0x800A4EC0 | 0x254 | 6 |
| `func_800A5114` | 0x800A5114 | 0x1D0 | 6 |
| `func_800A52E4` | 0x800A52E4 | 0xFC | 1 |
| `func_800A53E0` | 0x800A53E0 | 0x280 | 4 |
| `func_800A5660` | 0x800A5660 | 0x84 | 5 |
| `func_800A56E4` | 0x800A56E4 | 0xC0 | 0 |
| `func_800A57A4` | 0x800A57A4 | 0x58 | 0 |
| `func_800A57FC` | 0x800A57FC | 0xA8 | 4 |
| `func_800A58A4` | 0x800A58A4 | 0x8C | 2 |
| `func_800A5930` | 0x800A5930 | 0x90 | 2 |
| `func_800A59C0` | 0x800A59C0 | 0x4C0 | 20 |
| `func_800A5E80` | 0x800A5E80 | 0x80 | 1 |
| `func_800A5F00` | 0x800A5F00 | 0x1FC | 0 |
| `func_800A60FC` | 0x800A60FC | 0x264 | 0 |
| `func_800A6360` | 0x800A6360 | 0x1CC | 0 |
| `func_800A652C` | 0x800A652C | 0x208 | 2 |
| `func_800A6734` | 0x800A6734 | 0x58 | 2 |
| `func_800A678C` | 0x800A678C | 0x60 | 1 |
| `func_800A67EC` | 0x800A67EC | 0xB0 | 3 |
| `func_800A689C` | 0x800A689C | 0xD8 | 0 |
| `func_800A6974` | 0x800A6974 | 0x1C | 0 |
| `func_800A6990` | 0x800A6990 | 0x9C | 7 |
| `func_800A6A2C` | 0x800A6A2C | 0x48 | 3 |
| `func_800A6A74` | 0x800A6A74 | 0x34 | 3 |
| `func_800A6AA8` | 0x800A6AA8 | 0x20 | 1 |
| `func_800A6AC8` | 0x800A6AC8 | 0x4C | 0 |
| `func_800A6B14` | 0x800A6B14 | 0x4C | 2 |
| `func_800A6B60` | 0x800A6B60 | 0x50 | 0 |
| `func_800A6BB0` | 0x800A6BB0 | 0x158 | 0 |
| `func_800A6D08` | 0x800A6D08 | 0x88 | 0 |
| `func_800A6D90` | 0x800A6D90 | 0x48 | 1 |
| `func_800A6DD8` | 0x800A6DD8 | 0x70 | 1 |
| `func_800A6E48` | 0x800A6E48 | 0x260 | 3 |
| `func_800A70A8` | 0x800A70A8 | 0x134 | 3 |
| `func_800A71DC` | 0x800A71DC | 0x70 | 1 |
| `func_800A724C` | 0x800A724C | 0x3C | 3 |
| `func_800A7288` | 0x800A7288 | 0x30 | 2 |
| `func_800A72B8` | 0x800A72B8 | 0xBC | 3 |
| `func_800A7374` | 0x800A7374 | 0x168 | 0 |
| `func_800A74DC` | 0x800A74DC | 0xA20 | 0 |
| `func_800A7EFC` | 0x800A7EFC | 0x10A4 | 11 |
| `func_800A8FA0` | 0x800A8FA0 | 0x28 | 0 |
| `func_800A8FC8` | 0x800A8FC8 | 0x20 | 0 |
| `func_800A8FE8` | 0x800A8FE8 | 0x28 | 0 |
| `func_800A9010` | 0x800A9010 | 0x38C | 8 |
| `func_800A939C` | 0x800A939C | 0x10C | 1 |
| `func_800A94A8` | 0x800A94A8 | 0x70 | 1 |
| `func_800A9518` | 0x800A9518 | 0x74 | 2 |
| `func_800A958C` | 0x800A958C | 0x6C | 1 |
| `func_800A95F8` | 0x800A95F8 | 0x70 | 2 |
| `func_800A9668` | 0x800A9668 | 0x8C | 1 |
| `func_800A96F4` | 0x800A96F4 | 0x64 | 1 |
| `func_800A9758` | 0x800A9758 | 0xFC | 2 |
| `func_800A9854` | 0x800A9854 | 0x24 | 0 |
| `func_800A9878` | 0x800A9878 | 0x24 | 0 |
| `func_800A989C` | 0x800A989C | 0x24 | 0 |
| `func_800A98C0` | 0x800A98C0 | 0x24 | 0 |
| `func_800A98E4` | 0x800A98E4 | 0x46C | 11 |
| `func_800A9D50` | 0x800A9D50 | 0x10 | 0 |
| `func_800A9D60` | 0x800A9D60 | 0xC | 0 |
| `func_800A9D6C` | 0x800A9D6C | 0xC | 0 |
| `func_800A9D78` | 0x800A9D78 | 0x60 | 2 |
| `func_800A9DD8` | 0x800A9DD8 | 0x6C | 3 |
| `func_800A9E44` | 0x800A9E44 | 0xAC | 2 |
| `func_800A9EF0` | 0x800A9EF0 | 0xAC | 2 |
| `func_800A9F9C` | 0x800A9F9C | 0x9C | 5 |
| `func_800AA038` | 0x800AA038 | 0x74 | 2 |
| `func_800AA0AC` | 0x800AA0AC | 0x88 | 2 |
| `func_800AA134` | 0x800AA134 | 0x18 | 0 |
| `func_800AA14C` | 0x800AA14C | 0x290 | 5 |
| `func_800AA3DC` | 0x800AA3DC | 0x18 | 0 |
| `func_800AA3F4` | 0x800AA3F4 | 0x7C | 1 |
| `func_800AA470` | 0x800AA470 | 0xA4 | 5 |
| `func_800AA514` | 0x800AA514 | 0x94 | 1 |
| `func_800AA5A8` | 0x800AA5A8 | 0x14 | 0 |
| `func_800AA5BC` | 0x800AA5BC | 0xC | 0 |
| `func_800AA5C8` | 0x800AA5C8 | 0x40 | 2 |
| `func_800AA608` | 0x800AA608 | 0x24 | 0 |
| `func_800AA62C` | 0x800AA62C | 0xC | 0 |
| `func_800AA638` | 0x800AA638 | 0x40 | 2 |
| `func_800AA678` | 0x800AA678 | 0x1EC | 0 |
| `func_800AA864` | 0x800AA864 | 0x10 | 0 |
| `func_800AA874` | 0x800AA874 | 0x54 | 3 |
| `func_800AA8C8` | 0x800AA8C8 | 0x8 | 0 |
| `func_800AA8D0` | 0x800AA8D0 | 0xC | 0 |
| `func_800AA8DC` | 0x800AA8DC | 0x40 | 2 |
| `func_800AA91C` | 0x800AA91C | 0x18 | 0 |
| `func_800AA934` | 0x800AA934 | 0xC | 0 |
| `func_800AA940` | 0x800AA940 | 0x40 | 2 |
| `func_800AA980` | 0x800AA980 | 0x18C | 1 |
| `func_800AAB0C` | 0x800AAB0C | 0xAD4 | 6 |
| `func_800AB5E0` | 0x800AB5E0 | 0x120 | 9 |
| `func_800AB700` | 0x800AB700 | 0x94 | 0 |
| `func_800AB794` | 0x800AB794 | 0x1A0 | 1 |
| `func_800AB934` | 0x800AB934 | 0x80 | 5 |
| `func_800AB9B4` | 0x800AB9B4 | 0x104 | 0 |
| `func_800ABAB8` | 0x800ABAB8 | 0x2AC | 1 |
| `func_800ABD64` | 0x800ABD64 | 0x78 | 1 |
| `func_800ABDDC` | 0x800ABDDC | 0x24 | 1 |
| `func_800ABE00` | 0x800ABE00 | 0x1F0 | 11 |
| `func_800ABFF0` | 0x800ABFF0 | 0x7C | 3 |
| `func_800AC06C` | 0x800AC06C | 0x8C | 4 |
| `func_800AC0F8` | 0x800AC0F8 | 0xB0 | 3 |
| `func_800AC1A8` | 0x800AC1A8 | 0x84 | 3 |
| `func_800AC22C` | 0x800AC22C | 0x84 | 3 |
| `func_800AC2B0` | 0x800AC2B0 | 0x58 | 0 |
| `func_800AC308` | 0x800AC308 | 0x2C | 0 |
| `func_800AC334` | 0x800AC334 | 0x1C | 0 |
| `func_800AC350` | 0x800AC350 | 0x190 | 0 |
| `func_800AC4E0` | 0x800AC4E0 | 0x228 | 1 |
| `func_800AC708` | 0x800AC708 | 0x248 | 1 |
| `func_800AC950` | 0x800AC950 | 0x70 | 1 |
| `func_800AC9C0` | 0x800AC9C0 | 0x31C | 3 |
| `func_800ACCDC` | 0x800ACCDC | 0x34 | 1 |
| `func_800ACD10` | 0x800ACD10 | 0x3C | 0 |
| `func_800ACD4C` | 0x800ACD4C | 0x48 | 0 |
| `func_800ACD94` | 0x800ACD94 | 0x50 | 0 |
| `func_800ACDE4` | 0x800ACDE4 | 0xBC | 0 |
| `func_800ACEA0` | 0x800ACEA0 | 0x280 | 2 |
| `func_800AD120` | 0x800AD120 | 0x20 | 1 |
| `func_800AD140` | 0x800AD140 | 0xA4 | 0 |
| `func_800AD1E4` | 0x800AD1E4 | 0x118 | 0 |
| `func_800AD2FC` | 0x800AD2FC | 0x674 | 3 |
| `func_800AD970` | 0x800AD970 | 0x3C | 1 |
| `func_800AD9AC` | 0x800AD9AC | 0x88 | 2 |
| `func_800ADA34` | 0x800ADA34 | 0x14 | 0 |
| `func_800ADA48` | 0x800ADA48 | 0x14 | 0 |
| `func_800ADA5C` | 0x800ADA5C | 0x14 | 0 |
| `func_800ADA70` | 0x800ADA70 | 0x14 | 0 |
| `func_800ADA84` | 0x800ADA84 | 0x14 | 0 |
| `func_800ADA98` | 0x800ADA98 | 0x8 | 0 |
| `func_800ADAA0` | 0x800ADAA0 | 0x20 | 0 |
| `func_800ADAC0` | 0x800ADAC0 | 0x10 | 0 |
| `func_800ADAD0` | 0x800ADAD0 | 0x38C | 0 |
| `func_800ADE5C` | 0x800ADE5C | 0x3C4 | 3 |
| `func_800AE220` | 0x800AE220 | 0x4A8 | 2 |
| `func_800AE6C8` | 0x800AE6C8 | 0x1C | 0 |
| `func_800AE6E4` | 0x800AE6E4 | 0x1C | 0 |
| `func_800AE700` | 0x800AE700 | 0xC | 0 |
| `func_800AE70C` | 0x800AE70C | 0x174 | 4 |
| `func_800AE880` | 0x800AE880 | 0x200 | 0 |
| `func_800AEA80` | 0x800AEA80 | 0x1D4 | 0 |
| `func_800AEC54` | 0x800AEC54 | 0xA8 | 0 |
| `func_800AECFC` | 0x800AECFC | 0x150 | 10 |
| `func_800AEE4C` | 0x800AEE4C | 0x278 | 0 |
| `func_800AF0C4` | 0x800AF0C4 | 0x2E0 | 0 |
| `func_800AF3A4` | 0x800AF3A4 | 0x1B4 | 0 |
| `func_800AF95C` | 0x800AF95C | 0x1B4 | 0 |
| `func_800AFB10` | 0x800AFB10 | 0xAC | 0 |
| `func_800AFBBC` | 0x800AFBBC | 0x94 | 0 |
| `func_800AFC50` | 0x800AFC50 | 0xCC | 4 |
| `func_800AFD1C` | 0x800AFD1C | 0x130 | 5 |
| `func_800AFE4C` | 0x800AFE4C | 0xB8 | 0 |
| `func_800AFFF0` | 0x800AFFF0 | 0x50 | 1 |
| `func_800B00BC` | 0x800B00BC | 0x84 | 1 |
| `func_800B0140` | 0x800B0140 | 0x1B0 | 2 |
| `func_800B02F0` | 0x800B02F0 | 0x7C | 2 |
| `func_800B036C` | 0x800B036C | 0x150 | 6 |
| `func_800B04BC` | 0x800B04BC | 0x60 | 1 |
| `func_800B051C` | 0x800B051C | 0x88 | 0 |
| `func_800B05A4` | 0x800B05A4 | 0x15C | 0 |
| `func_800B0700` | 0x800B0700 | 0x190 | 2 |
| `func_800B0890` | 0x800B0890 | 0x84 | 0 |
| `func_800B0914` | 0x800B0914 | 0x94 | 0 |
| `func_800B09A8` | 0x800B09A8 | 0x84 | 0 |
| `func_800B0A2C` | 0x800B0A2C | 0x6C | 1 |
| `func_800B0A98` | 0x800B0A98 | 0x304 | 1 |
| `func_800B0D9C` | 0x800B0D9C | 0xB4 | 3 |
| `func_800B0E50` | 0x800B0E50 | 0xB8 | 0 |
| `func_800B0F08` | 0x800B0F08 | 0x6C | 0 |
| `func_800B0F74` | 0x800B0F74 | 0x104 | 0 |
| `func_800B10C0` | 0x800B10C0 | 0x4C | 1 |
| `func_800B110C` | 0x800B110C | 0xB8 | 1 |
| `func_800B11C4` | 0x800B11C4 | 0x1E4 | 4 |
| `func_800B13A8` | 0x800B13A8 | 0x330 | 0 |
| `func_800B16D8` | 0x800B16D8 | 0x98 | 0 |
| `func_800B1770` | 0x800B1770 | 0x30C | 0 |
| `func_800B1A7C` | 0x800B1A7C | 0x34 | 1 |
| `func_800B1AB0` | 0x800B1AB0 | 0xB4 | 3 |
| `func_800B1B64` | 0x800B1B64 | 0x98 | 1 |
| `func_800B1BFC` | 0x800B1BFC | 0xC14 | 2 |
| `func_800B2810` | 0x800B2810 | 0x550 | 1 |
| `func_800B2D60` | 0x800B2D60 | 0x2DC | 0 |
| `func_800B303C` | 0x800B303C | 0x44 | 1 |

## ~N64 library / OS  (203 funcs, top out-degree 8)

| function | addr | size | calls |
|---|---|---|---|
| `osCreateScheduler` | 0x8005EC10 | 0x148 | 8 |
| `osScAddClient` | 0x8005ED58 | 0x6C | 2 |
| `osScRemoveClient` | 0x8005EDC4 | 0xC0 | 2 |
| `osScGetCmdQ` | 0x8005EE84 | 0x8 | 0 |
| `__scMain` | 0x8005EE8C | 0x134 | 6 |
| `__scHandleRetrace` | 0x8005EFC0 | 0x158 | 7 |
| `__scHandleRSP` | 0x8005F118 | 0x1B8 | 5 |
| `__scHandleRDP` | 0x8005F2D0 | 0xB8 | 3 |
| `__scTaskReady` | 0x8005F388 | 0x68 | 2 |
| `__scTaskComplete` | 0x8005F3F0 | 0x120 | 3 |
| `__scAppendList` | 0x8005F510 | 0x88 | 0 |
| `__scExec` | 0x8005F598 | 0x114 | 5 |
| `__scYield` | 0x8005F6AC | 0x4C | 1 |
| `__scSchedule` | 0x8005F6F8 | 0x388 | 2 |
| `osCreateMesgQueue` (data?) | 0x800B3080 | 0x30 |  |
| `osSetEventMesg` (data?) | 0x800B30B0 | 0x70 |  |
| `osContInit` (data?) | 0x800B3120 | 0x170 |  |
| `__osContGetInitData` (data?) | 0x800B3290 | 0xD0 |  |
| `__osPackRequestData` (data?) | 0x800B3360 | 0x100 |  |
| `osEepromProbe` (data?) | 0x800B3460 | 0x70 |  |
| `osSendMesg` (data?) | 0x800B34D0 | 0x150 |  |
| `osPfsInitPak` (data?) | 0x800B3620 | 0x1F0 |  |
| `__osMotorAccess` (data?) | 0x800B3810 | 0x168 |  |
| `__osMakeMotorData` | 0x800B3978 | 0x10C | 1 |
| `osMotorInit` (data?) | 0x800B3A84 | 0x15C |  |
| `osSyncPrintf` | 0x800B3BE0 | 0x1C | 0 |
| `osRecvMesg` (data?) | 0x800B3C20 | 0x140 |  |
| `osContStartReadData` (data?) | 0x800B3D60 | 0x84 |  |
| `osContGetReadData` (data?) | 0x800B3DE4 | 0x8C |  |
| `__osPackReadData` (data?) | 0x800B3E70 | 0xD0 |  |
| `osContStartQuery` (data?) | 0x800B3F40 | 0x84 |  |
| `osContGetQuery` (data?) | 0x800B3FC4 | 0x2C |  |
| `osEepromWrite` (data?) | 0x800B3FF0 | 0x178 |  |
| `__osPackEepWriteData` (data?) | 0x800B4168 | 0xAC |  |
| `__osEepStatus` (data?) | 0x800B4214 | 0x1AC |  |
| `osEepromRead` (data?) | 0x800B43C0 | 0x1C4 |  |
| `__osPackEepReadData` (data?) | 0x800B4584 | 0x8C |  |
| `__osPfsGetNextPage` (data?) | 0x800B4610 | 0xD4 |  |
| `osPfsReadWriteFile` (data?) | 0x800B46E4 | 0x37C |  |
| `osPfsAllocateFile` (data?) | 0x800B4A60 | 0x334 |  |
| `__osPfsDeclearPage` | 0x800B4D94 | 0x14C | 0 |
| `osPfsFindFile` (data?) | 0x800B4EE0 | 0x1B0 |  |
| `osPfsDeleteFile` (data?) | 0x800B5090 | 0x1D8 |  |
| `__osPfsReleasePages` | 0x800B5268 | 0x98 | 0 |
| `osPfsNumFiles` (data?) | 0x800B5300 | 0x120 |  |
| `osPfsFileState` (data?) | 0x800B5420 | 0x1E0 |  |
| `osPfsRepairId` (data?) | 0x800B5600 | 0x60 |  |
| `osPfsFreeBlocks` (data?) | 0x800B5660 | 0x1A0 |  |
| `osGbpakInit` | 0x800B5800 | 0x220 | 8 |
| `osGbpakPower` | 0x800B5A20 | 0x110 | 5 |
| `osGbpakReadId` | 0x800B5B30 | 0x1C0 | 7 |
| `osGbpakGetStatus` | 0x800B5CF0 | 0x160 | 3 |
| `osGbpakReadWrite` | 0x800B5E50 | 0x1C0 | 5 |
| `osCreateThread` (data?) | 0x800B6010 | 0x150 |  |
| `osStartThread` (data?) | 0x800B6160 | 0x150 |  |
| `sprintf` (data?) | 0x800B62D4 | 0x5C |  |
| `osViSetSpecialFeatures` (data?) | 0x800B6330 | 0x1C0 |  |
| `osViSwapBuffer` (data?) | 0x800B64F0 | 0x50 |  |
| `osGetCount` (data?) | 0x800B6540 | 0x10 |  |
| `osGetTime` (data?) | 0x800B6550 | 0x90 |  |
| `osViSetEvent` (data?) | 0x800B65E0 | 0x70 |  |
| `osWritebackDCacheAll` (data?) | 0x800B6650 | 0x30 |  |
| `osSpTaskLoad` (data?) | 0x800B679C | 0x190 |  |
| `osSpTaskStartGo` (data?) | 0x800B692C | 0x44 |  |
| `osDpSetNextBuffer` (data?) | 0x800B6970 | 0xB0 |  |
| `osViSetMode` (data?) | 0x800B6A20 | 0x70 |  |
| `osSetIntMask` (data?) | 0x800B6A90 | 0xA0 |  |
| `osInitialize` (data?) | 0x800B6B30 | 0x2C0 |  |
| `osCreatePiManager` (data?) | 0x800B6E90 | 0x1D0 |  |
| `osCreateViManager` (data?) | 0x800B7060 | 0x180 |  |
| `osSetThreadPri` (data?) | 0x800B7370 | 0xE0 |  |
| `bzero` (data?) | 0x800B7450 | 0xA0 |  |
| `__ll_lshift` (data?) | 0x800B7594 | 0x2C |  |
| `__ll_rem` (data?) | 0x800B75C0 | 0x3C |  |
| `__ll_div` (data?) | 0x800B75FC | 0x5C |  |
| `__ll_mul` (data?) | 0x800B7658 | 0x30 |  |
| `__ll_mod` (data?) | 0x800B76E8 | 0x9C |  |
| `__ll_rshift` (data?) | 0x800B7784 | 0x2C |  |
| `osSpTaskYielded` (data?) | 0x800B77B0 | 0x80 |  |
| `osViGetCurrentFramebuffer` (data?) | 0x800B7830 | 0x40 |  |
| `osViGetNextFramebuffer` (data?) | 0x800B7870 | 0x40 |  |
| `osSpTaskYield` (data?) | 0x800B78B0 | 0x20 |  |
| `guMtxF2L` | 0x800B78D0 | 0x100 | 0 |
| `guMtxIdentF` | 0x800B79D0 | 0x88 | 0 |
| `guMtxIdent` | 0x800B7A58 | 0x30 | 2 |
| `guMtxL2F` | 0x800B7A88 | 0xB8 | 0 |
| `bcopy` (data?) | 0x800B7D00 | 0x310 |  |
| `sqrtf` (data?) | 0x800B8340 | 0x10 |  |
| `memcpy` (data?) | 0x800B8350 | 0x2C |  |
| `strlen` (data?) | 0x800B837C | 0x28 |  |
| `strchr` (data?) | 0x800B83A4 | 0x4C |  |
| `osStopThread` (data?) | 0x800B83F0 | 0xC0 |  |
| `osSetTime` (data?) | 0x800B84B0 | 0x30 |  |
| `__osGetCurrFaultedThread` | 0x800B84E0 | 0x10 | 0 |
| `osAiSetFrequency` (data?) | 0x800B8590 | 0x150 |  |
| `osVirtualToPhysical` (data?) | 0x800B87A0 | 0x80 |  |
| `osAiSetNextBuffer` (data?) | 0x800B8820 | 0xB0 |  |
| `osAiGetLength` (data?) | 0x800B88D0 | 0x10 |  |
| `osJamMesg` (data?) | 0x800B8BE0 | 0x150 |  |
| `guTranslateF` | 0x800B9DA0 | 0x48 | 1 |
| `guTranslate` | 0x800B9DE8 | 0x58 | 2 |
| `guRotateRPYF` | 0x800B9E40 | 0x14C | 7 |
| `guRotateRPY` | 0x800B9F8C | 0x54 | 2 |
| `guLookAtF` | 0x800B9FE0 | 0x2B8 | 4 |
| `guLookAt` | 0x800BA298 | 0x78 | 2 |
| `guPerspectiveF` | 0x800BA310 | 0x230 | 3 |
| `guPerspective` | 0x800BA540 | 0x60 | 2 |
| `guMtxXFML` | 0x800BA5A0 | 0x60 | 2 |
| `guMtxCatL` | 0x800BA600 | 0x60 | 4 |
| `guNormalize` | 0x800BA660 | 0x90 | 1 |
| `guAlignF` | 0x800BA6F0 | 0x1C0 | 5 |
| `guAlign` | 0x800BA8B0 | 0x50 | 2 |
| `guLookAtReflectF` | 0x800BA900 | 0x40C | 4 |
| `guLookAtReflect` | 0x800BAD0C | 0x84 | 2 |
| `__d_to_ll` (data?) | 0x800BAD90 | 0x1C |  |
| `__d_to_ull` (data?) | 0x800BADC8 | 0xA0 |  |
| `__ll_to_d` (data?) | 0x800BAF04 | 0x18 |  |
| `__ll_to_f` (data?) | 0x800BAF1C | 0x18 |  |
| `osInvalDCache` (data?) | 0x800BAFA0 | 0xB0 |  |
| `osPiStartDma` (data?) | 0x800BB050 | 0x110 |  |
| `osWritebackDCache` (data?) | 0x800BB160 | 0x80 |  |
| `osEPiStartDma` (data?) | 0x800BB1E0 | 0xE0 |  |
| `osEPiLinkHandle` | 0x800BB2C0 | 0x50 | 2 |
| `guOrthoF` | 0x800BB310 | 0x154 | 1 |
| `guOrtho` | 0x800BB464 | 0x6C | 2 |
| `guRandom` | 0x800BB4D0 | 0x30 | 0 |
| `__osDequeueThread` (data?) | 0x800BB500 | 0x40 |  |
| `__osDisableInt` (data?) | 0x800BB540 | 0x20 |  |
| `__osRestoreInt` (data?) | 0x800BB560 | 0x20 |  |
| `osSetTimer` (data?) | 0x800BB580 | 0xE0 |  |
| `__osSiRawStartDma` (data?) | 0x800BB660 | 0xB0 |  |
| `__osSiCreateAccessQueue` (data?) | 0x800BB710 | 0x50 |  |
| `__osSiGetAccess` (data?) | 0x800BB760 | 0x44 |  |
| `__osSiRelAccess` (data?) | 0x800BB7A4 | 0x2C |  |
| `__osExceptionPreamble` (data?) | 0x800BB7D0 | 0x10 |  |
| `__osException` (data?) | 0x800BB7E0 | 0x524 |  |
| `__osEnqueueAndYield` (data?) | 0x800BBDEC | 0x100 |  |
| `__osEnqueueThread` (data?) | 0x800BBEEC | 0x48 |  |
| `__osPopThread` (data?) | 0x800BBF34 | 0x10 |  |
| `__osDispatchThread` (data?) | 0x800BBF44 | 0x17C |  |
| `__osCleanupThread` (data?) | 0x800BC0C0 | 0x10 |  |
| `__osPfsGetStatus` (data?) | 0x800BC0D0 | 0xD0 |  |
| `__osPfsRequestOneChannel` (data?) | 0x800BC1A0 | 0xC4 |  |
| `__osPfsGetOneChannelData` (data?) | 0x800BC264 | 0x9C |  |
| `__osPfsSelectBank` (data?) | 0x800BC300 | 0x80 |  |
| `__osContRamRead` (data?) | 0x800BC380 | 0x230 |  |
| `__osSumcalc` | 0x800BC5B0 | 0x74 | 0 |
| `__osIdCheckSum` | 0x800BC624 | 0xFC | 0 |
| `__osRepairPackId` (data?) | 0x800BC720 | 0x350 |  |
| `__osCheckPackId` (data?) | 0x800BCA70 | 0x164 |  |
| `__osGetId` (data?) | 0x800BCBD4 | 0x1AC |  |
| `__osCheckId` (data?) | 0x800BCD80 | 0xD4 |  |
| `__osPfsRWInode` (data?) | 0x800BCE54 | 0x2DC |  |
| `osPfsChecker` (data?) | 0x800BD130 | 0x538 |  |
| `__osContAddressCrc` (data?) | 0x800BDAD0 | 0xD0 |  |
| `__osContDataCrc` (data?) | 0x800BDBA0 | 0xA0 |  |
| `__osContRamWrite` (data?) | 0x800BDC40 | 0x250 |  |
| `__osGbpakSetBank` | 0x800BDE90 | 0xD0 | 3 |
| `__osViInit` (data?) | 0x800BEC20 | 0x140 |  |
| `__osTimerServicesInit` (data?) | 0x800BED60 | 0x8C |  |
| `__osTimerInterrupt` (data?) | 0x800BEDEC | 0x178 |  |
| `__osSetTimerIntr` (data?) | 0x800BEF64 | 0x74 |  |
| `__osInsertTimer` (data?) | 0x800BEFD8 | 0x188 |  |
| `__osSpSetStatus` (data?) | 0x800BF160 | 0x10 |  |
| `__osSpSetPc` (data?) | 0x800BF170 | 0x40 |  |
| `__osSpRawStartDma` (data?) | 0x800BF1B0 | 0x90 |  |
| `__osSpDeviceBusy` (data?) | 0x800BF240 | 0x30 |  |
| `__osDpDeviceBusy` (data?) | 0x800BF270 | 0x30 |  |
| `__osSetSR` (data?) | 0x800BF2A0 | 0x10 |  |
| `__osGetSR` (data?) | 0x800BF2B0 | 0x10 |  |
| `__osSetFpcCsr` (data?) | 0x800BF2C0 | 0x10 |  |
| `__osSpRawReadIo` (data?) | 0x800BF2D0 | 0x50 |  |
| `__osSpRawWriteIo` (data?) | 0x800BF320 | 0x50 |  |
| `osInvalICache` (data?) | 0x800BF370 | 0x80 |  |
| `osUnmapTLBAll` (data?) | 0x800BF3F0 | 0x50 |  |
| `osMapTLBRdb` (data?) | 0x800BF440 | 0x60 |  |
| `__osPiRawReadIo` (data?) | 0x800BF4A0 | 0x60 |  |
| `__osPiCreateAccessQueue` (data?) | 0x800BF500 | 0x50 |  |
| `__osPiGetAccess` (data?) | 0x800BF550 | 0x44 |  |
| `__osPiRelAccess` (data?) | 0x800BF594 | 0x2C |  |
| `osGetThreadPri` (data?) | 0x800BF5C0 | 0x20 |  |
| `__osPiRawStartDma` (data?) | 0x800BF5E0 | 0xE0 |  |
| `__osEPiRawStartDma` (data?) | 0x800BF6C0 | 0x1E0 |  |
| `__osDevMgrMain` (data?) | 0x800BF8A0 | 0x490 |  |
| `__osViGetCurrentContext` (data?) | 0x800BFD30 | 0x10 |  |
| `__osViSwapContext` (data?) | 0x800BFD40 | 0x300 |  |
| `__osSpGetStatus` (data?) | 0x800C0040 | 0x10 |  |
| `__osProbeTLB` (data?) | 0x800C0060 | 0xC0 |  |
| `__osAiDeviceBusy` (data?) | 0x800C0120 | 0x30 |  |
| `guMtxXFMF` | 0x800C1910 | 0xA0 | 0 |
| `guMtxCatF` | 0x800C19B0 | 0x170 | 0 |
| `osPiGetCmdQueue` (data?) | 0x800C1B20 | 0x30 |  |
| `osDestroyThread` (data?) | 0x800C1B50 | 0x110 |  |
| `osPfsIsPlug` (data?) | 0x800C1C60 | 0x1A0 |  |
| `__osPfsRequestData` (data?) | 0x800C1E00 | 0xD0 |  |
| `__osPfsGetInitData` (data?) | 0x800C1ED0 | 0xD0 |  |
| `__osSetCompare` (data?) | 0x800C2D00 | 0x10 |  |
| `__osSiDeviceBusy` (data?) | 0x800C2D10 | 0x30 |  |
| `__osResetGlobalIntMask` (data?) | 0x800C2D40 | 0x60 |  |
| `osEPiRawWriteIo` (data?) | 0x800C2DA0 | 0x160 |  |
| `osEPiRawReadIo` (data?) | 0x800C2F00 | 0x160 |  |
| `__osSetGlobalIntMask` (data?) | 0x800C3060 | 0x50 |  |
| `osYieldThread` (data?) | 0x800C30B0 | 0x50 |  |

## ~misc  (40 funcs, top out-degree 8)

| function | addr | size | calls |
|---|---|---|---|
| `__lzo_ptr_linear` | 0x80080F60 | 0x14 | 0 |
| `__lzo_align_gap` | 0x80080F74 | 0x6C | 1 |
| `_lzo_version_string` | 0x8008102C | 0xC | 0 |
| `_lzo_version_date` | 0x80081038 | 0xC | 0 |
| `_lzo_config_check` | 0x80081A68 | 0x20C | 8 |
| `__lzo_init2` | 0x80081D1C | 0x1F0 | 1 |
| `_lzo1x_1_do_compress` | 0x80081F0C | 0x6A4 | 0 |
| `_pullSubFrame` | 0x8008CD1C | 0x40C | 4 |
| `_frexpf` | 0x8008D128 | 0x168 | 0 |
| `_ldexpf` | 0x8008D290 | 0x30 | 0 |
| `_getRate` | 0x8008D2C0 | 0x3D0 | 4 |
| `_getVol` | 0x8008D690 | 0xE0 | 0 |
| `__allocParam` | 0x8008ED04 | 0x54 | 0 |
| `__freeParam` | 0x8008ED58 | 0x2C | 0 |
| `_collectPVoices` | 0x8008ED84 | 0x64 | 2 |
| `_freePVoice` | 0x8008EDE8 | 0x3C | 2 |
| `_timeToSamples` | 0x8008EE24 | 0x74 | 0 |
| `_samplesToTime` | 0x8008EE98 | 0x64 | 0 |
| `__nextSampleTime` | 0x8008EEFC | 0xA4 | 0 |
| `_VirtualToPhysicalTask` | 0x800B6680 | 0x11C | 8 |
| `__ull_rshift` (data?) | 0x800B74F0 | 0x2C |  |
| `__ull_rem` (data?) | 0x800B751C | 0x3C |  |
| `__ull_div` (data?) | 0x800B7558 | 0x3C |  |
| `__ull_divremi` (data?) | 0x800B7688 | 0x60 |  |
| `_allocatePVoice` | 0x800B8930 | 0xE8 | 4 |
| `__f_to_ll` (data?) | 0x800BADAC | 0x1C |  |
| `__f_to_ull` (data?) | 0x800BAE68 | 0x9C |  |
| `__ull_to_d` (data?) | 0x800BAF34 | 0x34 |  |
| `__ull_to_f` (data?) | 0x800BAF68 | 0x38 |  |
| `_Putfld` | 0x800BDF60 | 0x670 | 5 |
| `_Printf` | 0x800BE5D0 | 0x650 | 4 |
| `_doModFunc` | 0x800C0170 | 0xA8 | 0 |
| `_filterBuffer` | 0x800C0218 | 0xB8 | 2 |
| `_saveBuffer` | 0x800C02D0 | 0x188 | 3 |
| `_loadBuffer` | 0x800C0458 | 0x18C | 3 |
| `_loadOutputBuffer` | 0x800C05E4 | 0x224 | 4 |
| `_decodeChunk` | 0x800C1340 | 0x12C | 0 |
| `_Litob` | 0x800C1FA0 | 0x2A0 | 4 |
| `_Genld` | 0x800C2240 | 0x570 | 5 |
| `_Ldtob` | 0x800C27B0 | 0x550 | 3 |

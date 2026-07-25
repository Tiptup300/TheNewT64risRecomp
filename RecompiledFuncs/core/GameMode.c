#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void GameMode_PausedTick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006CC84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006CC88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006CC8C: jal         0x800721D8
    // 0x8006CC90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    PauseMenu_Process(rdram, ctx);
        goto after_0;
    // 0x8006CC90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006CC94: jal         0x800A3AF0
    // 0x8006CC98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    frametime_delta(rdram, ctx);
        goto after_1;
    // 0x8006CC98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x8006CC9C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8006CCA0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8006CCA4: sw          $v0, 0x9F4($at)
    MEM_W(0X9F4, ctx->r1) = ctx->r2;
    // 0x8006CCA8: jal         0x80051CB0
    // 0x8006CCAC: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    Game_Tick(rdram, ctx);
        goto after_2;
    // 0x8006CCAC: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    after_2:
    // 0x8006CCB0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8006CCB4: jal         0x80051F30
    // 0x8006CCB8: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    Game_Draw(rdram, ctx);
        goto after_3;
    // 0x8006CCB8: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    after_3:
    // 0x8006CCBC: jal         0x80072248
    // 0x8006CCC0: nop

    PauseMenu_Draw(rdram, ctx);
        goto after_4;
    // 0x8006CCC0: nop

    after_4:
    // 0x8006CCC4: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x8006CCC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CCCC: beq         $s1, $at, L_8006CCEC
    if (ctx->r17 == ctx->r1) {
        // 0x8006CCD0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006CCEC;
    }
    // 0x8006CCD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006CCD4: beq         $s1, $at, L_8006CD1C
    if (ctx->r17 == ctx->r1) {
        // 0x8006CCD8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8006CD1C;
    }
    // 0x8006CCD8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006CCDC: beq         $s1, $at, L_8006CD74
    if (ctx->r17 == ctx->r1) {
        // 0x8006CCE0: nop
    
            goto L_8006CD74;
    }
    // 0x8006CCE0: nop

    // 0x8006CCE4: b           L_8006CD84
    // 0x8006CCE8: nop

        goto L_8006CD84;
    // 0x8006CCE8: nop

L_8006CCEC:
    // 0x8006CCEC: jal         0x800721A4
    // 0x8006CCF0: nop

    PauseMenu_Destroy(rdram, ctx);
        goto after_5;
    // 0x8006CCF0: nop

    after_5:
    // 0x8006CCF4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8006CCF8: jal         0x80051618
    // 0x8006CCFC: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    Game_StartRound(rdram, ctx);
        goto after_6;
    // 0x8006CCFC: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    after_6:
    // 0x8006CD00: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8006CD04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CD08: sb          $t6, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r14;
    // 0x8006CD0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CD10: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006CD14: b           L_8006CD84
    // 0x8006CD18: sb          $t7, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r15;
        goto L_8006CD84;
    // 0x8006CD18: sb          $t7, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r15;
L_8006CD1C:
    // 0x8006CD1C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8006CD20: lw          $t8, 0x5C0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5C0);
    // 0x8006CD24: nop

    // 0x8006CD28: lbu         $s0, 0x89($t8)
    ctx->r16 = MEM_BU(ctx->r24, 0X89);
    // 0x8006CD2C: jal         0x800721A4
    // 0x8006CD30: nop

    PauseMenu_Destroy(rdram, ctx);
        goto after_7;
    // 0x8006CD30: nop

    after_7:
    // 0x8006CD34: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8006CD38: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8006CD3C: sb          $t9, 0x9F0($at)
    MEM_B(0X9F0, ctx->r1) = ctx->r25;
    // 0x8006CD40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CD44: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8006CD48: sb          $t0, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r8;
    // 0x8006CD4C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8006CD50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CD54: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006CD58: lb          $a0, -0x7C8($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X7C8);
    // 0x8006CD5C: sb          $t1, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r9;
    // 0x8006CD60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006CD64: jal         0x800472F0
    // 0x8006CD68: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    wonders3_wonder_viewer(rdram, ctx);
        goto after_8;
    // 0x8006CD68: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_8:
    // 0x8006CD6C: b           L_8006CD84
    // 0x8006CD70: nop

        goto L_8006CD84;
    // 0x8006CD70: nop

L_8006CD74:
    // 0x8006CD74: jal         0x800721A4
    // 0x8006CD78: nop

    PauseMenu_Destroy(rdram, ctx);
        goto after_9;
    // 0x8006CD78: nop

    after_9:
    // 0x8006CD7C: jal         0x80055000
    // 0x8006CD80: nop

    gets_lineCounts_loops_numPlayers_checks_gametype(rdram, ctx);
        goto after_10;
    // 0x8006CD80: nop

    after_10:
L_8006CD84:
    // 0x8006CD84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CD88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006CD8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006CD90: jr          $ra
    // 0x8006CD94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006CD94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void GameMode_PlayingTick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CD98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006CD9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006CDA0: jal         0x800A3AF0
    // 0x8006CDA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    frametime_delta(rdram, ctx);
        goto after_0;
    // 0x8006CDA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006CDA8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8006CDAC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8006CDB0: sw          $v0, 0x9F4($at)
    MEM_W(0X9F4, ctx->r1) = ctx->r2;
    // 0x8006CDB4: jal         0x80051CB0
    // 0x8006CDB8: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    Game_Tick(rdram, ctx);
        goto after_1;
    // 0x8006CDB8: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    after_1:
    // 0x8006CDBC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8006CDC0: jal         0x80051F30
    // 0x8006CDC4: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    Game_Draw(rdram, ctx);
        goto after_2;
    // 0x8006CDC4: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    after_2:
    // 0x8006CDC8: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8006CDCC: lbu         $s0, 0xA01($s0)
    ctx->r16 = MEM_BU(ctx->r16, 0XA01);
    // 0x8006CDD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CDD4: beq         $s0, $at, L_8006CDF4
    if (ctx->r16 == ctx->r1) {
        // 0x8006CDD8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006CDF4;
    }
    // 0x8006CDD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006CDDC: bne         $s0, $at, L_8006CE20
    if (ctx->r16 != ctx->r1) {
        // 0x8006CDE0: nop
    
            goto L_8006CE20;
    }
    // 0x8006CDE0: nop

    // 0x8006CDE4: jal         0x80055000
    // 0x8006CDE8: nop

    gets_lineCounts_loops_numPlayers_checks_gametype(rdram, ctx);
        goto after_3;
    // 0x8006CDE8: nop

    after_3:
    // 0x8006CDEC: b           L_8006CE20
    // 0x8006CDF0: nop

        goto L_8006CE20;
    // 0x8006CDF0: nop

L_8006CDF4:
    // 0x8006CDF4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8006CDF8: lbu         $a0, 0xA04($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XA04);
    // 0x8006CDFC: jal         0x80072140
    // 0x8006CE00: nop

    PauseMenu_Create(rdram, ctx);
        goto after_4;
    // 0x8006CE00: nop

    after_4:
    // 0x8006CE04: beq         $v0, $zero, L_8006CE20
    if (ctx->r2 == 0) {
        // 0x8006CE08: nop
    
            goto L_8006CE20;
    }
    // 0x8006CE08: nop

    // 0x8006CE0C: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x8006CE10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CE14: sb          $t6, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r14;
    // 0x8006CE18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CE1C: sb          $zero, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = 0;
L_8006CE20:
    // 0x8006CE20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CE24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006CE28: jr          $ra
    // 0x8006CE2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006CE2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void GameMode_AttractCountdownTick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CE30: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006CE34: lw          $t6, 0x550($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X550);
    // 0x8006CE38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CE3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CE40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CE44: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8006CE48: jal         0x800A3AF0
    // 0x8006CE4C: sw          $t7, 0x550($at)
    MEM_W(0X550, ctx->r1) = ctx->r15;
    frametime_delta(rdram, ctx);
        goto after_0;
    // 0x8006CE4C: sw          $t7, 0x550($at)
    MEM_W(0X550, ctx->r1) = ctx->r15;
    after_0:
    // 0x8006CE50: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8006CE54: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8006CE58: sw          $v0, 0x9F4($at)
    MEM_W(0X9F4, ctx->r1) = ctx->r2;
    // 0x8006CE5C: jal         0x80051CB0
    // 0x8006CE60: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    Game_Tick(rdram, ctx);
        goto after_1;
    // 0x8006CE60: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    after_1:
    // 0x8006CE64: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8006CE68: jal         0x80051F30
    // 0x8006CE6C: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    Game_Draw(rdram, ctx);
        goto after_2;
    // 0x8006CE6C: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    after_2:
    // 0x8006CE70: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8006CE74: lbu         $t8, 0xA01($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0XA01);
    // 0x8006CE78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006CE7C: bne         $t8, $at, L_8006CE90
    if (ctx->r24 != ctx->r1) {
        // 0x8006CE80: nop
    
            goto L_8006CE90;
    }
    // 0x8006CE80: nop

    // 0x8006CE84: addiu       $t9, $zero, 0xFA0
    ctx->r25 = ADD32(0, 0XFA0);
    // 0x8006CE88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CE8C: sw          $t9, 0x550($at)
    MEM_W(0X550, ctx->r1) = ctx->r25;
L_8006CE90:
    // 0x8006CE90: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006CE94: lw          $t0, 0x550($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X550);
    // 0x8006CE98: nop

    // 0x8006CE9C: slti        $at, $t0, 0xFA0
    ctx->r1 = SIGNED(ctx->r8) < 0XFA0 ? 1 : 0;
    // 0x8006CEA0: bne         $at, $zero, L_8006CECC
    if (ctx->r1 != 0) {
        // 0x8006CEA4: nop
    
            goto L_8006CECC;
    }
    // 0x8006CEA4: nop

    // 0x8006CEA8: jal         0x8004A34C
    // 0x8006CEAC: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_3;
    // 0x8006CEAC: nop

    after_3:
    // 0x8006CEB0: jal         0x80052570
    // 0x8006CEB4: nop

    Game_Deinit(rdram, ctx);
        goto after_4;
    // 0x8006CEB4: nop

    after_4:
    // 0x8006CEB8: addiu       $t1, $zero, 0x11
    ctx->r9 = ADD32(0, 0X11);
    // 0x8006CEBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CEC0: sb          $t1, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r9;
    // 0x8006CEC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CEC8: sw          $zero, 0x550($at)
    MEM_W(0X550, ctx->r1) = 0;
L_8006CECC:
    // 0x8006CECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CED4: jr          $ra
    // 0x8006CED8: nop

    return;
    // 0x8006CED8: nop

;}

RECOMP_FUNC void FUN_032F00_8006cedc_sets_glb_to_fun_call_glb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CEDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CEE0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CEE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CEE8: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x8006CEEC: jal         0x8007DA00
    // 0x8006CEF0: nop

    func_8007DA00(rdram, ctx);
        goto after_0;
    // 0x8006CEF0: nop

    after_0:
    // 0x8006CEF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CEF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CEFC: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
    // 0x8006CF00: jr          $ra
    // 0x8006CF04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006CF04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

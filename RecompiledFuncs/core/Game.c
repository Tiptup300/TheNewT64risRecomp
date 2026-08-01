#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Game_SetGlobalPointers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050520: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80050524: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80050528: addiu       $a1, $a1, 0xA00
    ctx->r5 = ADD32(ctx->r5, 0XA00);
    // 0x8005052C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80050530: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050534: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80050538: sb          $a0, -0x10DF($at)
    MEM_B(-0X10DF, ctx->r1) = ctx->r4;
    // 0x8005053C: addiu       $t8, $t7, 0x7FFF
    ctx->r24 = ADD32(ctx->r15, 0X7FFF);
    // 0x80050540: lw          $t8, 0x612D($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X612D);
    // 0x80050544: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050548: sw          $t8, -0xDD0($at)
    MEM_W(-0XDD0, ctx->r1) = ctx->r24;
    // 0x8005054C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050550: addiu       $t9, $a1, 0x80
    ctx->r25 = ADD32(ctx->r5, 0X80);
    // 0x80050554: sw          $t9, -0x350($at)
    MEM_W(-0X350, ctx->r1) = ctx->r25;
    // 0x80050558: ori         $at, $zero, 0xE0E8
    ctx->r1 = 0 | 0XE0E8;
    // 0x8005055C: addu        $t0, $a1, $at
    ctx->r8 = ADD32(ctx->r5, ctx->r1);
    // 0x80050560: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050564: sw          $t0, -0x390($at)
    MEM_W(-0X390, ctx->r1) = ctx->r8;
    // 0x80050568: lw          $t1, 0x674C($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X674C);
    // 0x8005056C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050570: sw          $t1, -0x380($at)
    MEM_W(-0X380, ctx->r1) = ctx->r9;
    // 0x80050574: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050578: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x8005057C: sw          $t2, -0xDE0($at)
    MEM_W(-0XDE0, ctx->r1) = ctx->r10;
    // 0x80050580: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050584: addiu       $t3, $t8, 0x7D0
    ctx->r11 = ADD32(ctx->r24, 0X7D0);
    // 0x80050588: sw          $t3, -0x3F0($at)
    MEM_W(-0X3F0, ctx->r1) = ctx->r11;
    // 0x8005058C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050590: addiu       $t4, $t8, 0x54
    ctx->r12 = ADD32(ctx->r24, 0X54);
    // 0x80050594: sw          $t4, -0x470($at)
    MEM_W(-0X470, ctx->r1) = ctx->r12;
    // 0x80050598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005059C: addiu       $t5, $t8, 0x44C
    ctx->r13 = ADD32(ctx->r24, 0X44C);
    // 0x800505A0: sw          $t5, -0x460($at)
    MEM_W(-0X460, ctx->r1) = ctx->r13;
    // 0x800505A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800505A8: addiu       $t6, $t8, 0x768
    ctx->r14 = ADD32(ctx->r24, 0X768);
    // 0x800505AC: sw          $t6, -0x440($at)
    MEM_W(-0X440, ctx->r1) = ctx->r14;
    // 0x800505B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800505B4: addiu       $t7, $t8, 0x6750
    ctx->r15 = ADD32(ctx->r24, 0X6750);
    // 0x800505B8: sw          $t7, -0xDA0($at)
    MEM_W(-0XDA0, ctx->r1) = ctx->r15;
    // 0x800505BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800505C0: addiu       $t9, $t8, 0x6808
    ctx->r25 = ADD32(ctx->r24, 0X6808);
    // 0x800505C4: sw          $t9, -0x10F0($at)
    MEM_W(-0X10F0, ctx->r1) = ctx->r25;
    // 0x800505C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800505CC: addiu       $t0, $t8, 0x3BC0
    ctx->r8 = ADD32(ctx->r24, 0X3BC0);
    // 0x800505D0: sw          $t0, -0x410($at)
    MEM_W(-0X410, ctx->r1) = ctx->r8;
    // 0x800505D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800505D8: addiu       $t1, $t8, 0x3BCC
    ctx->r9 = ADD32(ctx->r24, 0X3BCC);
    // 0x800505DC: sw          $t1, -0x400($at)
    MEM_W(-0X400, ctx->r1) = ctx->r9;
    // 0x800505E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800505E4: addiu       $t2, $t8, 0x3BD4
    ctx->r10 = ADD32(ctx->r24, 0X3BD4);
    // 0x800505E8: sw          $t2, -0x420($at)
    MEM_W(-0X420, ctx->r1) = ctx->r10;
    // 0x800505EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800505F0: addiu       $t3, $t8, 0x3BD8
    ctx->r11 = ADD32(ctx->r24, 0X3BD8);
    // 0x800505F4: sw          $t3, -0x430($at)
    MEM_W(-0X430, ctx->r1) = ctx->r11;
    // 0x800505F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800505FC: addiu       $t4, $t8, 0x830
    ctx->r12 = ADD32(ctx->r24, 0X830);
    // 0x80050600: sw          $t4, -0x490($at)
    MEM_W(-0X490, ctx->r1) = ctx->r12;
    // 0x80050604: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80050608: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005060C: addiu       $t5, $t8, 0x12A0
    ctx->r13 = ADD32(ctx->r24, 0X12A0);
    // 0x80050610: sw          $t5, -0x480($at)
    MEM_W(-0X480, ctx->r1) = ctx->r13;
    // 0x80050614: jr          $ra
    // 0x80050618: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80050618: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void PlayerVars_SetGlobalPointers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005061C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80050620: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80050624: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80050628: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8005062C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80050630: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80050634: addiu       $t7, $t7, -0x10D0
    ctx->r15 = ADD32(ctx->r15, -0X10D0);
    // 0x80050638: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8005063C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80050640: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050644: jr          $ra
    // 0x80050648: sw          $t8, -0xDF0($at)
    MEM_W(-0XDF0, ctx->r1) = ctx->r24;
    return;
    // 0x80050648: sw          $t8, -0xDF0($at)
    MEM_W(-0XDF0, ctx->r1) = ctx->r24;
    // 0x8005064C: nop

;}

RECOMP_FUNC void Game_AnyBoardCubeInRows7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050AC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80050AC8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80050ACC: lbu         $t6, -0x10E0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X10E0);
    // 0x80050AD0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80050AD4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80050AD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80050ADC: sltu        $at, $s1, $t6
    ctx->r1 = ctx->r17 < ctx->r14 ? 1 : 0;
    // 0x80050AE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050AE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80050AE8: beq         $at, $zero, L_80050B3C
    if (ctx->r1 == 0) {
        // 0x80050AEC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80050B3C;
    }
    // 0x80050AEC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80050AF0: bne         $s0, $zero, L_80050B3C
    if (ctx->r16 != 0) {
        // 0x80050AF4: nop
    
            goto L_80050B3C;
    }
    // 0x80050AF4: nop

L_80050AF8:
    // 0x80050AF8: jal         0x80050520
    // 0x80050AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Game_SetGlobalPointers(rdram, ctx);
        goto after_0;
    // 0x80050AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80050B00: jal         0x8005061C
    // 0x80050B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerVars_SetGlobalPointers(rdram, ctx);
        goto after_1;
    // 0x80050B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80050B08: jal         0x8006DDD0
    // 0x80050B0C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    BoardP_AnyCubeInRowsUpTo(rdram, ctx);
        goto after_2;
    // 0x80050B0C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x80050B10: beq         $v0, $zero, L_80050B1C
    if (ctx->r2 == 0) {
        // 0x80050B14: nop
    
            goto L_80050B1C;
    }
    // 0x80050B14: nop

    // 0x80050B18: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80050B1C:
    // 0x80050B1C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80050B20: lbu         $t7, -0x10E0($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X10E0);
    // 0x80050B24: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80050B28: sltu        $at, $s1, $t7
    ctx->r1 = ctx->r17 < ctx->r15 ? 1 : 0;
    // 0x80050B2C: beq         $at, $zero, L_80050B3C
    if (ctx->r1 == 0) {
        // 0x80050B30: nop
    
            goto L_80050B3C;
    }
    // 0x80050B30: nop

    // 0x80050B34: beq         $s0, $zero, L_80050AF8
    if (ctx->r16 == 0) {
        // 0x80050B38: nop
    
            goto L_80050AF8;
    }
    // 0x80050B38: nop

L_80050B3C:
    // 0x80050B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80050B40: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80050B44: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80050B48: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80050B4C: jr          $ra
    // 0x80050B50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80050B50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Game_SetAlpha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050B54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80050B58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80050B5C: lbu         $t6, -0x10E0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X10E0);
    // 0x80050B60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050B64: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80050B68: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80050B6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050B70: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80050B74: beq         $at, $zero, L_80050C98
    if (ctx->r1 == 0) {
        // 0x80050B78: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80050C98;
    }
    // 0x80050B78: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
L_80050B7C:
    // 0x80050B7C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80050B80: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80050B84: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80050B88: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x80050B8C: lw          $t1, 0x612D($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X612D);
    // 0x80050B90: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
    // 0x80050B94: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80050B98: sb          $t7, 0x844($t1)
    MEM_B(0X844, ctx->r9) = ctx->r15;
    // 0x80050B9C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80050BA0: lbu         $t2, 0x2F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2F);
    // 0x80050BA4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80050BA8: addiu       $t6, $t5, 0x7FFF
    ctx->r14 = ADD32(ctx->r13, 0X7FFF);
    // 0x80050BAC: lw          $t6, 0x612D($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X612D);
    // 0x80050BB0: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80050BB4: sb          $t2, 0x3BC6($t6)
    MEM_B(0X3BC6, ctx->r14) = ctx->r10;
    // 0x80050BB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80050BBC: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x80050BC0: addu        $t7, $t9, $t0
    ctx->r15 = ADD32(ctx->r25, ctx->r8);
    // 0x80050BC4: addiu       $t1, $t7, 0x7FFF
    ctx->r9 = ADD32(ctx->r15, 0X7FFF);
    // 0x80050BC8: lw          $t1, 0x612D($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X612D);
    // 0x80050BCC: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80050BD0: sb          $t8, 0x3BBA($t1)
    MEM_B(0X3BBA, ctx->r9) = ctx->r24;
    // 0x80050BD4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80050BD8: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x80050BDC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80050BE0: addiu       $a0, $t5, 0x7FFF
    ctx->r4 = ADD32(ctx->r13, 0X7FFF);
    // 0x80050BE4: lw          $a0, 0x612D($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X612D);
    // 0x80050BE8: jal         0x8006F064
    // 0x80050BEC: addiu       $a0, $a0, 0x3BCC
    ctx->r4 = ADD32(ctx->r4, 0X3BCC);
    FallingCubes_SetAlpha(rdram, ctx);
        goto after_0;
    // 0x80050BEC: addiu       $a0, $a0, 0x3BCC
    ctx->r4 = ADD32(ctx->r4, 0X3BCC);
    after_0:
    // 0x80050BF0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80050BF4: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80050BF8: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80050BFC: addiu       $t7, $t0, 0x7FFF
    ctx->r15 = ADD32(ctx->r8, 0X7FFF);
    // 0x80050C00: lw          $t7, 0x612D($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X612D);
    // 0x80050C04: lbu         $t2, 0x2F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2F);
    // 0x80050C08: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80050C0C: sb          $t2, 0x5210($t7)
    MEM_B(0X5210, ctx->r15) = ctx->r10;
    // 0x80050C10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80050C14: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x80050C18: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80050C1C: addiu       $t5, $t4, 0x7FFF
    ctx->r13 = ADD32(ctx->r12, 0X7FFF);
    // 0x80050C20: lw          $t5, 0x612D($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X612D);
    // 0x80050C24: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80050C28: sb          $t8, 0x5729($t5)
    MEM_B(0X5729, ctx->r13) = ctx->r24;
    // 0x80050C2C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80050C30: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x80050C34: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80050C38: addiu       $t7, $t2, 0x7FFF
    ctx->r15 = ADD32(ctx->r10, 0X7FFF);
    // 0x80050C3C: lw          $t7, 0x612D($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X612D);
    // 0x80050C40: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80050C44: sb          $t6, 0x5C58($t7)
    MEM_B(0X5C58, ctx->r15) = ctx->r14;
    // 0x80050C48: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80050C4C: lbu         $t1, 0x2F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2F);
    // 0x80050C50: addu        $t8, $t3, $t4
    ctx->r24 = ADD32(ctx->r11, ctx->r12);
    // 0x80050C54: addiu       $t5, $t8, 0x7FFF
    ctx->r13 = ADD32(ctx->r24, 0X7FFF);
    // 0x80050C58: lw          $t5, 0x612D($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X612D);
    // 0x80050C5C: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80050C60: sb          $t1, 0x6171($t5)
    MEM_B(0X6171, ctx->r13) = ctx->r9;
    // 0x80050C64: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80050C68: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x80050C6C: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80050C70: addiu       $a0, $t2, 0x7FFF
    ctx->r4 = ADD32(ctx->r10, 0X7FFF);
    // 0x80050C74: lw          $a0, 0x612D($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X612D);
    // 0x80050C78: jal         0x8006AEBC
    // 0x80050C7C: addiu       $a0, $a0, 0x44C
    ctx->r4 = ADD32(ctx->r4, 0X44C);
    Multisquare_8006aebc_loops_44_times_4(rdram, ctx);
        goto after_1;
    // 0x80050C7C: addiu       $a0, $a0, 0x44C
    ctx->r4 = ADD32(ctx->r4, 0X44C);
    after_1:
    // 0x80050C80: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80050C84: lbu         $t6, -0x10E0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X10E0);
    // 0x80050C88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80050C8C: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80050C90: bne         $at, $zero, L_80050B7C
    if (ctx->r1 != 0) {
        // 0x80050C94: nop
    
            goto L_80050B7C;
    }
    // 0x80050C94: nop

L_80050C98:
    // 0x80050C98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80050C9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050CA0: jr          $ra
    // 0x80050CA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80050CA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void getPlayerTopOutOrder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050CA8: addiu       $t6, $a0, 0x7FFF
    ctx->r14 = ADD32(ctx->r4, 0X7FFF);
    // 0x80050CAC: lbu         $t6, 0x6510($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X6510);
    // 0x80050CB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80050CB4: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80050CB8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80050CBC: beq         $at, $zero, L_80050CFC
    if (ctx->r1 == 0) {
        // 0x80050CC0: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_80050CFC;
    }
    // 0x80050CC0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_80050CC4:
    // 0x80050CC4: addu        $t7, $a0, $a2
    ctx->r15 = ADD32(ctx->r4, ctx->r6);
    // 0x80050CC8: addiu       $t8, $t7, 0x7FFF
    ctx->r24 = ADD32(ctx->r15, 0X7FFF);
    // 0x80050CCC: lbu         $t8, 0x650C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X650C);
    // 0x80050CD0: nop

    // 0x80050CD4: bne         $t8, $a1, L_80050CE4
    if (ctx->r24 != ctx->r5) {
        // 0x80050CD8: nop
    
            goto L_80050CE4;
    }
    // 0x80050CD8: nop

    // 0x80050CDC: b           L_80050D00
    // 0x80050CE0: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
        goto L_80050D00;
    // 0x80050CE0: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
L_80050CE4:
    // 0x80050CE4: addiu       $t9, $a0, 0x7FFF
    ctx->r25 = ADD32(ctx->r4, 0X7FFF);
    // 0x80050CE8: lbu         $t9, 0x6510($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X6510);
    // 0x80050CEC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80050CF0: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80050CF4: bne         $at, $zero, L_80050CC4
    if (ctx->r1 != 0) {
        // 0x80050CF8: nop
    
            goto L_80050CC4;
    }
    // 0x80050CF8: nop

L_80050CFC:
    // 0x80050CFC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80050D00:
    // 0x80050D00: jr          $ra
    // 0x80050D04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80050D04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void getMaxPlayerLines(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050D08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80050D0C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80050D10: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80050D14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80050D18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80050D1C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80050D20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050D24: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x80050D28: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80050D2C: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80050D30: beq         $at, $zero, L_80050D98
    if (ctx->r1 == 0) {
        // 0x80050D34: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80050D98;
    }
    // 0x80050D34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80050D38:
    // 0x80050D38: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050D3C: jal         0x80050CA8
    // 0x80050D40: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    getPlayerTopOutOrder(rdram, ctx);
        goto after_0;
    // 0x80050D40: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80050D44: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80050D48: bne         $v0, $at, L_80050D7C
    if (ctx->r2 != ctx->r1) {
        // 0x80050D4C: nop
    
            goto L_80050D7C;
    }
    // 0x80050D4C: nop

    // 0x80050D50: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80050D54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80050D58: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80050D5C: lw          $a0, -0x14D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X14D4);
    // 0x80050D60: jal         0x8005282C
    // 0x80050D64: addiu       $a0, $a0, 0x681C
    ctx->r4 = ADD32(ctx->r4, 0X681C);
    getLineCount(rdram, ctx);
        goto after_1;
    // 0x80050D64: addiu       $a0, $a0, 0x681C
    ctx->r4 = ADD32(ctx->r4, 0X681C);
    after_1:
    // 0x80050D68: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80050D6C: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80050D70: beq         $at, $zero, L_80050D7C
    if (ctx->r1 == 0) {
        // 0x80050D74: nop
    
            goto L_80050D7C;
    }
    // 0x80050D74: nop

    // 0x80050D78: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80050D7C:
    // 0x80050D7C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80050D80: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80050D84: lbu         $t0, 0x5($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X5);
    // 0x80050D88: nop

    // 0x80050D8C: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80050D90: bne         $at, $zero, L_80050D38
    if (ctx->r1 != 0) {
        // 0x80050D94: nop
    
            goto L_80050D38;
    }
    // 0x80050D94: nop

L_80050D98:
    // 0x80050D98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80050D9C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80050DA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050DA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80050DA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80050DAC: jr          $ra
    // 0x80050DB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80050DB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void getMinPlayerTime(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050DB4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80050DB8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80050DBC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80050DC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80050DC4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80050DC8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80050DCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050DD0: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x80050DD4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80050DD8: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80050DDC: beq         $at, $zero, L_80050E44
    if (ctx->r1 == 0) {
        // 0x80050DE0: addiu       $s0, $zero, -0x1
        ctx->r16 = ADD32(0, -0X1);
            goto L_80050E44;
    }
    // 0x80050DE0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_80050DE4:
    // 0x80050DE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80050DE8: jal         0x80050CA8
    // 0x80050DEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    getPlayerTopOutOrder(rdram, ctx);
        goto after_0;
    // 0x80050DEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80050DF0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80050DF4: bne         $v0, $at, L_80050E28
    if (ctx->r2 != ctx->r1) {
        // 0x80050DF8: nop
    
            goto L_80050E28;
    }
    // 0x80050DF8: nop

    // 0x80050DFC: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80050E00: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80050E04: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80050E08: lw          $t9, -0x14D4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X14D4);
    // 0x80050E0C: nop

    // 0x80050E10: lw          $s2, 0x6818($t9)
    ctx->r18 = MEM_W(ctx->r25, 0X6818);
    // 0x80050E14: nop

    // 0x80050E18: sltu        $at, $s2, $s0
    ctx->r1 = ctx->r18 < ctx->r16 ? 1 : 0;
    // 0x80050E1C: beq         $at, $zero, L_80050E28
    if (ctx->r1 == 0) {
        // 0x80050E20: nop
    
            goto L_80050E28;
    }
    // 0x80050E20: nop

    // 0x80050E24: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80050E28:
    // 0x80050E28: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80050E2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80050E30: lbu         $t1, 0x5($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X5);
    // 0x80050E34: nop

    // 0x80050E38: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80050E3C: bne         $at, $zero, L_80050DE4
    if (ctx->r1 != 0) {
        // 0x80050E40: nop
    
            goto L_80050DE4;
    }
    // 0x80050E40: nop

L_80050E44:
    // 0x80050E44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80050E48: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80050E4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050E50: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80050E54: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80050E58: jr          $ra
    // 0x80050E5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80050E5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Game_isGameWinner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050E60: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80050E64: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80050E68: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80050E6C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80050E70: lbu         $a1, 0x4F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X4F);
    // 0x80050E74: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80050E78: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80050E7C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80050E80: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80050E84: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80050E88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80050E8C: jal         0x80050CA8
    // 0x80050E90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    getPlayerTopOutOrder(rdram, ctx);
        goto after_0;
    // 0x80050E90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80050E94: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80050E98: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x80050E9C: lbu         $t8, 0x5($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X5);
    // 0x80050EA0: addiu       $t6, $s0, 0x1
    ctx->r14 = ADD32(ctx->r16, 0X1);
    // 0x80050EA4: bne         $t6, $t8, L_80050EB4
    if (ctx->r14 != ctx->r24) {
        // 0x80050EA8: nop
    
            goto L_80050EB4;
    }
    // 0x80050EA8: nop

    // 0x80050EAC: b           L_80051008
    // 0x80050EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051008;
    // 0x80050EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80050EB4:
    // 0x80050EB4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80050EB8: beq         $s0, $at, L_80050EC8
    if (ctx->r16 == ctx->r1) {
        // 0x80050EBC: nop
    
            goto L_80050EC8;
    }
    // 0x80050EBC: nop

    // 0x80050EC0: b           L_80051008
    // 0x80050EC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80051008;
    // 0x80050EC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050EC8:
    // 0x80050EC8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80050ECC: nop

    // 0x80050ED0: addiu       $s5, $t9, 0x7FFF
    ctx->r21 = ADD32(ctx->r25, 0X7FFF);
    // 0x80050ED4: lbu         $s5, 0x64ED($s5)
    ctx->r21 = MEM_BU(ctx->r21, 0X64ED);
    // 0x80050ED8: nop

    // 0x80050EDC: beq         $s5, $zero, L_80050EFC
    if (ctx->r21 == 0) {
        // 0x80050EE0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80050EFC;
    }
    // 0x80050EE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80050EE4: beq         $s5, $at, L_80050F04
    if (ctx->r21 == ctx->r1) {
        // 0x80050EE8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80050F04;
    }
    // 0x80050EE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80050EEC: beq         $s5, $at, L_80050F44
    if (ctx->r21 == ctx->r1) {
        // 0x80050EF0: nop
    
            goto L_80050F44;
    }
    // 0x80050EF0: nop

    // 0x80050EF4: b           L_80050FEC
    // 0x80050EF8: nop

        goto L_80050FEC;
    // 0x80050EF8: nop

L_80050EFC:
    // 0x80050EFC: b           L_80051008
    // 0x80050F00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051008;
    // 0x80050F00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80050F04:
    // 0x80050F04: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80050F08: jal         0x80050D08
    // 0x80050F0C: nop

    getMaxPlayerLines(rdram, ctx);
        goto after_1;
    // 0x80050F0C: nop

    after_1:
    // 0x80050F10: lbu         $t0, 0x4F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4F);
    // 0x80050F14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80050F18: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80050F1C: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80050F20: lw          $a0, -0x14D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X14D4);
    // 0x80050F24: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80050F28: jal         0x8005282C
    // 0x80050F2C: addiu       $a0, $a0, 0x681C
    ctx->r4 = ADD32(ctx->r4, 0X681C);
    getLineCount(rdram, ctx);
        goto after_2;
    // 0x80050F2C: addiu       $a0, $a0, 0x681C
    ctx->r4 = ADD32(ctx->r4, 0X681C);
    after_2:
    // 0x80050F30: xor         $v0, $v0, $s1
    ctx->r2 = ctx->r2 ^ ctx->r17;
    // 0x80050F34: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80050F38: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x80050F3C: b           L_80051008
    // 0x80050F40: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_80051008;
    // 0x80050F40: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80050F44:
    // 0x80050F44: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80050F48: jal         0x80050DB4
    // 0x80050F4C: nop

    getMinPlayerTime(rdram, ctx);
        goto after_3;
    // 0x80050F4C: nop

    after_3:
    // 0x80050F50: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80050F54: jal         0x80050D08
    // 0x80050F58: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    getMaxPlayerLines(rdram, ctx);
        goto after_4;
    // 0x80050F58: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_4:
    // 0x80050F5C: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x80050F60: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80050F64: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80050F68: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80050F6C: lw          $a0, -0x14D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X14D4);
    // 0x80050F70: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80050F74: jal         0x8005282C
    // 0x80050F78: addiu       $a0, $a0, 0x681C
    ctx->r4 = ADD32(ctx->r4, 0X681C);
    getLineCount(rdram, ctx);
        goto after_5;
    // 0x80050F78: addiu       $a0, $a0, 0x681C
    ctx->r4 = ADD32(ctx->r4, 0X681C);
    after_5:
    // 0x80050F7C: lbu         $t5, 0x4F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4F);
    // 0x80050F80: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80050F84: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80050F88: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80050F8C: lw          $t6, -0x14D4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X14D4);
    // 0x80050F90: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80050F94: lw          $t8, 0x6834($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X6834);
    // 0x80050F98: nop

    // 0x80050F9C: sltu        $s5, $s4, $t8
    ctx->r21 = ctx->r20 < ctx->r24 ? 1 : 0;
    // 0x80050FA0: xori        $s5, $s5, 0x1
    ctx->r21 = ctx->r21 ^ 0X1;
    // 0x80050FA4: bne         $s5, $zero, L_80050FBC
    if (ctx->r21 != 0) {
        // 0x80050FA8: nop
    
            goto L_80050FBC;
    }
    // 0x80050FA8: nop

    // 0x80050FAC: sltu        $s5, $s4, $s3
    ctx->r21 = ctx->r20 < ctx->r19 ? 1 : 0;
    // 0x80050FB0: xori        $s5, $s5, 0x1
    ctx->r21 = ctx->r21 ^ 0X1;
    // 0x80050FB4: beq         $s5, $zero, L_80050FE4
    if (ctx->r21 == 0) {
        // 0x80050FB8: nop
    
            goto L_80050FE4;
    }
    // 0x80050FB8: nop

L_80050FBC:
    // 0x80050FBC: lbu         $t9, 0x4F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4F);
    // 0x80050FC0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80050FC4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80050FC8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80050FCC: lw          $t1, -0x14D4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X14D4);
    // 0x80050FD0: nop

    // 0x80050FD4: lw          $t2, 0x6818($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X6818);
    // 0x80050FD8: nop

    // 0x80050FDC: xor         $s5, $t2, $s2
    ctx->r21 = ctx->r10 ^ ctx->r18;
    // 0x80050FE0: sltiu       $s5, $s5, 0x1
    ctx->r21 = ctx->r21 < 0X1 ? 1 : 0;
L_80050FE4:
    // 0x80050FE4: b           L_80051008
    // 0x80050FE8: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
        goto L_80051008;
    // 0x80050FE8: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
L_80050FEC:
    // 0x80050FEC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80050FF0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80050FF4: addiu       $a1, $a1, -0x3548
    ctx->r5 = ADD32(ctx->r5, -0X3548);
    // 0x80050FF8: addiu       $a0, $a0, -0x355C
    ctx->r4 = ADD32(ctx->r4, -0X355C);
    // 0x80050FFC: jal         0x8004A5A0
    // 0x80051000: addiu       $a2, $zero, 0x124
    ctx->r6 = ADD32(0, 0X124);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_6;
    // 0x80051000: addiu       $a2, $zero, 0x124
    ctx->r6 = ADD32(0, 0X124);
    after_6:
    // 0x80051004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80051008:
    // 0x80051008: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005100C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80051010: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80051014: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80051018: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8005101C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80051020: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80051024: jr          $ra
    // 0x80051028: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80051028: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void Game_countWinners(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005102C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80051030: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80051034: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80051038: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005103C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80051040: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80051044: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x80051048: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005104C: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80051050: beq         $at, $zero, L_8005108C
    if (ctx->r1 == 0) {
        // 0x80051054: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8005108C;
    }
    // 0x80051054: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80051058:
    // 0x80051058: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8005105C: jal         0x80050E60
    // 0x80051060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    Game_isGameWinner(rdram, ctx);
        goto after_0;
    // 0x80051060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80051064: beq         $v0, $zero, L_80051070
    if (ctx->r2 == 0) {
        // 0x80051068: nop
    
            goto L_80051070;
    }
    // 0x80051068: nop

    // 0x8005106C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80051070:
    // 0x80051070: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80051074: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80051078: lbu         $t9, 0x5($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X5);
    // 0x8005107C: nop

    // 0x80051080: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80051084: bne         $at, $zero, L_80051058
    if (ctx->r1 != 0) {
        // 0x80051088: nop
    
            goto L_80051058;
    }
    // 0x80051088: nop

L_8005108C:
    // 0x8005108C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80051090: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80051094: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80051098: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005109C: jr          $ra
    // 0x800510A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800510A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Game_CountPlayersPlaying(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800510A4: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x800510A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800510AC: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800510B0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800510B4: beq         $at, $zero, L_800510F8
    if (ctx->r1 == 0) {
        // 0x800510B8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800510F8;
    }
    // 0x800510B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800510BC:
    // 0x800510BC: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800510C0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800510C4: addiu       $t9, $t8, 0x7FFF
    ctx->r25 = ADD32(ctx->r24, 0X7FFF);
    // 0x800510C8: lw          $t9, 0x612D($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X612D);
    // 0x800510CC: nop

    // 0x800510D0: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x800510D4: nop

    // 0x800510D8: beq         $t0, $zero, L_800510E4
    if (ctx->r8 == 0) {
        // 0x800510DC: nop
    
            goto L_800510E4;
    }
    // 0x800510DC: nop

    // 0x800510E0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800510E4:
    // 0x800510E4: lbu         $t1, 0x5($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X5);
    // 0x800510E8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800510EC: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800510F0: bne         $at, $zero, L_800510BC
    if (ctx->r1 != 0) {
        // 0x800510F4: nop
    
            goto L_800510BC;
    }
    // 0x800510F4: nop

L_800510F8:
    // 0x800510F8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800510FC: jr          $ra
    // 0x80051100: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80051100: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Game_CountAlivePlayers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051104: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80051108: lbu         $a3, -0x10E0($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X10E0);
    // 0x8005110C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80051110: sltu        $at, $a1, $a3
    ctx->r1 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x80051114: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80051118: beq         $at, $zero, L_80051158
    if (ctx->r1 == 0) {
        // 0x8005111C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80051158;
    }
    // 0x8005111C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80051120:
    // 0x80051120: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80051124: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80051128: addiu       $t8, $t7, 0x7FFF
    ctx->r24 = ADD32(ctx->r15, 0X7FFF);
    // 0x8005112C: lw          $t8, 0x612D($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X612D);
    // 0x80051130: nop

    // 0x80051134: lbu         $t9, 0x2($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2);
    // 0x80051138: nop

    // 0x8005113C: beq         $t9, $zero, L_80051148
    if (ctx->r25 == 0) {
        // 0x80051140: nop
    
            goto L_80051148;
    }
    // 0x80051140: nop

    // 0x80051144: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80051148:
    // 0x80051148: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005114C: sltu        $at, $a1, $a3
    ctx->r1 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x80051150: bne         $at, $zero, L_80051120
    if (ctx->r1 != 0) {
        // 0x80051154: nop
    
            goto L_80051120;
    }
    // 0x80051154: nop

L_80051158:
    // 0x80051158: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8005115C: jr          $ra
    // 0x80051160: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80051160: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void Game_game_over_related(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051168: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005116C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80051170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80051174: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80051178: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005117C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80051180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051184: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80051188: addiu       $a0, $t9, 0x7FFF
    ctx->r4 = ADD32(ctx->r25, 0X7FFF);
    // 0x8005118C: lw          $a0, 0x612D($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X612D);
    // 0x80051190: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80051194: jal         0x80053B84
    // 0x80051198: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    FrameAct_calls_gamefinish_something2(rdram, ctx);
        goto after_0;
    // 0x80051198: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8005119C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800511A0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800511A4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800511A8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800511AC: addiu       $t4, $t3, 0x7FFF
    ctx->r12 = ADD32(ctx->r11, 0X7FFF);
    // 0x800511B0: lw          $t4, 0x612D($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X612D);
    // 0x800511B4: ori         $at, $zero, 0xE0E8
    ctx->r1 = 0 | 0XE0E8;
    // 0x800511B8: sb          $zero, 0x2($t4)
    MEM_B(0X2, ctx->r12) = 0;
    // 0x800511BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800511C0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800511C4: jal         0x800726A4
    // 0x800511C8: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    Landfill_ClearColumn(rdram, ctx);
        goto after_1;
    // 0x800511C8: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_1:
    // 0x800511CC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800511D0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800511D4: addiu       $at, $t7, 0x7FFF
    ctx->r1 = ADD32(ctx->r15, 0X7FFF);
    // 0x800511D8: sb          $t5, 0x650B($at)
    MEM_B(0X650B, ctx->r1) = ctx->r13;
    // 0x800511DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800511E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800511E4: jr          $ra
    // 0x800511E8: nop

    return;
    // 0x800511E8: nop

;}

RECOMP_FUNC void isGoalCompleted(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800511EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800511F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800511F4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800511F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800511FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80051200: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80051204: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80051208: addiu       $s2, $t6, 0x7FFF
    ctx->r18 = ADD32(ctx->r14, 0X7FFF);
    // 0x8005120C: lbu         $s2, 0x64ED($s2)
    ctx->r18 = MEM_BU(ctx->r18, 0X64ED);
    // 0x80051210: nop

    // 0x80051214: beq         $s2, $zero, L_80051234
    if (ctx->r18 == 0) {
        // 0x80051218: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80051234;
    }
    // 0x80051218: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005121C: beq         $s2, $at, L_8005123C
    if (ctx->r18 == ctx->r1) {
        // 0x80051220: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005123C;
    }
    // 0x80051220: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051224: beq         $s2, $at, L_80051278
    if (ctx->r18 == ctx->r1) {
        // 0x80051228: nop
    
            goto L_80051278;
    }
    // 0x80051228: nop

    // 0x8005122C: b           L_800512F0
    // 0x80051230: nop

        goto L_800512F0;
    // 0x80051230: nop

L_80051234:
    // 0x80051234: b           L_80051308
    // 0x80051238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80051308;
    // 0x80051238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005123C:
    // 0x8005123C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80051240: nop

    // 0x80051244: addiu       $t8, $t7, 0x7FFF
    ctx->r24 = ADD32(ctx->r15, 0X7FFF);
    // 0x80051248: addiu       $t9, $t7, 0x7FFF
    ctx->r25 = ADD32(ctx->r15, 0X7FFF);
    // 0x8005124C: lw          $t9, 0x64F1($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X64F1);
    // 0x80051250: lw          $t8, 0x64E9($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X64E9);
    // 0x80051254: nop

    // 0x80051258: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x8005125C: bne         $at, $zero, L_80051270
    if (ctx->r1 != 0) {
        // 0x80051260: addiu       $at, $t7, 0x7FFF
        ctx->r1 = ADD32(ctx->r15, 0X7FFF);
            goto L_80051270;
    }
    // 0x80051260: addiu       $at, $t7, 0x7FFF
    ctx->r1 = ADD32(ctx->r15, 0X7FFF);
    // 0x80051264: sw          $t9, 0x64E9($at)
    MEM_W(0X64E9, ctx->r1) = ctx->r25;
    // 0x80051268: b           L_80051308
    // 0x8005126C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051308;
    // 0x8005126C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80051270:
    // 0x80051270: b           L_80051308
    // 0x80051274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80051308;
    // 0x80051274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80051278:
    // 0x80051278: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8005127C: lbu         $s1, -0x10E0($s1)
    ctx->r17 = MEM_BU(ctx->r17, -0X10E0);
    // 0x80051280: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80051284: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80051288: beq         $at, $zero, L_800512E8
    if (ctx->r1 == 0) {
        // 0x8005128C: nop
    
            goto L_800512E8;
    }
    // 0x8005128C: nop

L_80051290:
    // 0x80051290: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80051294: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80051298: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8005129C: lw          $a0, -0x14D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X14D4);
    // 0x800512A0: jal         0x8005282C
    // 0x800512A4: addiu       $a0, $a0, 0x681C
    ctx->r4 = ADD32(ctx->r4, 0X681C);
    getLineCount(rdram, ctx);
        goto after_0;
    // 0x800512A4: addiu       $a0, $a0, 0x681C
    ctx->r4 = ADD32(ctx->r4, 0X681C);
    after_0:
    // 0x800512A8: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800512AC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800512B0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800512B4: lw          $t2, -0x14D4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X14D4);
    // 0x800512B8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800512BC: lw          $t3, 0x6834($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X6834);
    // 0x800512C0: nop

    // 0x800512C4: sltu        $at, $s2, $t3
    ctx->r1 = ctx->r18 < ctx->r11 ? 1 : 0;
    // 0x800512C8: bne         $at, $zero, L_800512D8
    if (ctx->r1 != 0) {
        // 0x800512CC: nop
    
            goto L_800512D8;
    }
    // 0x800512CC: nop

    // 0x800512D0: b           L_80051308
    // 0x800512D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051308;
    // 0x800512D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800512D8:
    // 0x800512D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800512DC: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800512E0: bne         $at, $zero, L_80051290
    if (ctx->r1 != 0) {
        // 0x800512E4: nop
    
            goto L_80051290;
    }
    // 0x800512E4: nop

L_800512E8:
    // 0x800512E8: b           L_80051308
    // 0x800512EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80051308;
    // 0x800512EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800512F0:
    // 0x800512F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800512F4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800512F8: addiu       $a1, $a1, -0x3530
    ctx->r5 = ADD32(ctx->r5, -0X3530);
    // 0x800512FC: addiu       $a0, $a0, -0x3540
    ctx->r4 = ADD32(ctx->r4, -0X3540);
    // 0x80051300: jal         0x8004A5A0
    // 0x80051304: addiu       $a2, $zero, 0x195
    ctx->r6 = ADD32(0, 0X195);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_1;
    // 0x80051304: addiu       $a2, $zero, 0x195
    ctx->r6 = ADD32(0, 0X195);
    after_1:
L_80051308:
    // 0x80051308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005130C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80051310: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80051314: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80051318: jr          $ra
    // 0x8005131C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005131C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Game_HandlePlayerTopOut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051320: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80051324: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80051328: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
    // 0x8005132C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80051330: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80051334: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80051338: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005133C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80051340: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80051344: addiu       $s0, $t9, 0x7FFF
    ctx->r16 = ADD32(ctx->r25, 0X7FFF);
    // 0x80051348: lw          $s0, 0x612D($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X612D);
    // 0x8005134C: nop

    // 0x80051350: lbu         $t0, 0xB($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XB);
    // 0x80051354: nop

    // 0x80051358: beq         $t0, $zero, L_800513AC
    if (ctx->r8 == 0) {
        // 0x8005135C: nop
    
            goto L_800513AC;
    }
    // 0x8005135C: nop

    // 0x80051360: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80051364: lbu         $t1, -0x10E0($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X10E0);
    // 0x80051368: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005136C: bne         $t1, $at, L_8005138C
    if (ctx->r9 != ctx->r1) {
        // 0x80051370: nop
    
            goto L_8005138C;
    }
    // 0x80051370: nop

    // 0x80051374: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80051378: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8005137C: jal         0x80051164
    // 0x80051380: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    Game_game_over_related(rdram, ctx);
        goto after_0;
    // 0x80051380: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80051384: b           L_8005139C
    // 0x80051388: nop

        goto L_8005139C;
    // 0x80051388: nop

L_8005138C:
    // 0x8005138C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80051390: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x80051394: jal         0x80051164
    // 0x80051398: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Game_game_over_related(rdram, ctx);
        goto after_1;
    // 0x80051398: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_8005139C:
    // 0x8005139C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800513A0: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x800513A4: jal         0x800509C0
    // 0x800513A8: nop

    setPlayerTopOutOrder(rdram, ctx);
        goto after_2;
    // 0x800513A8: nop

    after_2:
L_800513AC:
    // 0x800513AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800513B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800513B4: jr          $ra
    // 0x800513B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800513B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Game_HandleLastPlayerStanding(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800513BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800513C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800513C4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800513C8: lbu         $s0, -0x10E0($s0)
    ctx->r16 = MEM_BU(ctx->r16, -0X10E0);
    // 0x800513CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800513D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800513D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800513D8: beq         $s0, $at, L_80051450
    if (ctx->r16 == ctx->r1) {
        // 0x800513DC: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_80051450;
    }
    // 0x800513DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800513E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800513E4: jal         0x80051104
    // 0x800513E8: nop

    Game_CountAlivePlayers(rdram, ctx);
        goto after_0;
    // 0x800513E8: nop

    after_0:
    // 0x800513EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800513F0: bne         $v0, $at, L_80051450
    if (ctx->r2 != ctx->r1) {
        // 0x800513F4: nop
    
            goto L_80051450;
    }
    // 0x800513F4: nop

    // 0x800513F8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800513FC: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80051400: beq         $at, $zero, L_80051450
    if (ctx->r1 == 0) {
        // 0x80051404: nop
    
            goto L_80051450;
    }
    // 0x80051404: nop

L_80051408:
    // 0x80051408: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005140C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80051410: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80051414: addiu       $t9, $t8, 0x7FFF
    ctx->r25 = ADD32(ctx->r24, 0X7FFF);
    // 0x80051418: lw          $t9, 0x612D($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X612D);
    // 0x8005141C: nop

    // 0x80051420: lbu         $t0, 0x2($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2);
    // 0x80051424: nop

    // 0x80051428: beq         $t0, $zero, L_80051440
    if (ctx->r8 == 0) {
        // 0x8005142C: nop
    
            goto L_80051440;
    }
    // 0x8005142C: nop

    // 0x80051430: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80051434: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80051438: jal         0x80051164
    // 0x8005143C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Game_game_over_related(rdram, ctx);
        goto after_1;
    // 0x8005143C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80051440:
    // 0x80051440: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80051444: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80051448: bne         $at, $zero, L_80051408
    if (ctx->r1 != 0) {
        // 0x8005144C: nop
    
            goto L_80051408;
    }
    // 0x8005144C: nop

L_80051450:
    // 0x80051450: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80051454: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80051458: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005145C: jr          $ra
    // 0x80051460: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80051460: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Game_QueryGameOver(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051464: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80051468: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8005146C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80051470: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80051474: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80051478: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005147C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80051480: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80051484: lbu         $s1, 0x5($t6)
    ctx->r17 = MEM_BU(ctx->r14, 0X5);
    // 0x80051488: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005148C: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80051490: beq         $at, $zero, L_800514DC
    if (ctx->r1 == 0) {
        // 0x80051494: nop
    
            goto L_800514DC;
    }
    // 0x80051494: nop

L_80051498:
    // 0x80051498: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005149C: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x800514A0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800514A4: addiu       $s2, $t9, 0x7FFF
    ctx->r18 = ADD32(ctx->r25, 0X7FFF);
    // 0x800514A8: lw          $s2, 0x612D($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X612D);
    // 0x800514AC: nop

    // 0x800514B0: lbu         $t0, 0x2($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X2);
    // 0x800514B4: nop

    // 0x800514B8: beq         $t0, $zero, L_800514CC
    if (ctx->r8 == 0) {
        // 0x800514BC: nop
    
            goto L_800514CC;
    }
    // 0x800514BC: nop

    // 0x800514C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800514C4: jal         0x80051320
    // 0x800514C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Game_HandlePlayerTopOut(rdram, ctx);
        goto after_0;
    // 0x800514C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
L_800514CC:
    // 0x800514CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800514D0: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800514D4: bne         $at, $zero, L_80051498
    if (ctx->r1 != 0) {
        // 0x800514D8: nop
    
            goto L_80051498;
    }
    // 0x800514D8: nop

L_800514DC:
    // 0x800514DC: sltiu       $at, $s1, 0x2
    ctx->r1 = ctx->r17 < 0X2 ? 1 : 0;
    // 0x800514E0: bne         $at, $zero, L_800514F4
    if (ctx->r1 != 0) {
        // 0x800514E4: nop
    
            goto L_800514F4;
    }
    // 0x800514E4: nop

    // 0x800514E8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800514EC: jal         0x800513BC
    // 0x800514F0: nop

    Game_HandleLastPlayerStanding(rdram, ctx);
        goto after_1;
    // 0x800514F0: nop

    after_1:
L_800514F4:
    // 0x800514F4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800514F8: jal         0x800511EC
    // 0x800514FC: nop

    isGoalCompleted(rdram, ctx);
        goto after_2;
    // 0x800514FC: nop

    after_2:
    // 0x80051500: beq         $v0, $zero, L_800515A4
    if (ctx->r2 == 0) {
        // 0x80051504: nop
    
            goto L_800515A4;
    }
    // 0x80051504: nop

    // 0x80051508: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005150C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80051510: lbu         $t2, 0x5($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5);
    // 0x80051514: nop

    // 0x80051518: slt         $at, $s3, $t2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8005151C: beq         $at, $zero, L_800515A4
    if (ctx->r1 == 0) {
        // 0x80051520: nop
    
            goto L_800515A4;
    }
    // 0x80051520: nop

L_80051524:
    // 0x80051524: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80051528: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x8005152C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80051530: addiu       $t6, $t5, 0x7FFF
    ctx->r14 = ADD32(ctx->r13, 0X7FFF);
    // 0x80051534: lw          $t6, 0x612D($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X612D);
    // 0x80051538: nop

    // 0x8005153C: lbu         $t7, 0x2($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2);
    // 0x80051540: nop

    // 0x80051544: beq         $t7, $zero, L_80051588
    if (ctx->r15 == 0) {
        // 0x80051548: nop
    
            goto L_80051588;
    }
    // 0x80051548: nop

    // 0x8005154C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051550: jal         0x80050E60
    // 0x80051554: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    Game_isGameWinner(rdram, ctx);
        goto after_3;
    // 0x80051554: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x80051558: beq         $v0, $zero, L_80051578
    if (ctx->r2 == 0) {
        // 0x8005155C: nop
    
            goto L_80051578;
    }
    // 0x8005155C: nop

    // 0x80051560: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051564: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80051568: jal         0x80051164
    // 0x8005156C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Game_game_over_related(rdram, ctx);
        goto after_4;
    // 0x8005156C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80051570: b           L_80051588
    // 0x80051574: nop

        goto L_80051588;
    // 0x80051574: nop

L_80051578:
    // 0x80051578: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8005157C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80051580: jal         0x80051164
    // 0x80051584: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Game_game_over_related(rdram, ctx);
        goto after_5;
    // 0x80051584: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
L_80051588:
    // 0x80051588: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8005158C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80051590: lbu         $t9, 0x5($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X5);
    // 0x80051594: nop

    // 0x80051598: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8005159C: bne         $at, $zero, L_80051524
    if (ctx->r1 != 0) {
        // 0x800515A0: nop
    
            goto L_80051524;
    }
    // 0x800515A0: nop

L_800515A4:
    // 0x800515A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800515A8: jal         0x800510A4
    // 0x800515AC: nop

    Game_CountPlayersPlaying(rdram, ctx);
        goto after_6;
    // 0x800515AC: nop

    after_6:
    // 0x800515B0: bne         $v0, $zero, L_800515DC
    if (ctx->r2 != 0) {
        // 0x800515B4: nop
    
            goto L_800515DC;
    }
    // 0x800515B4: nop

    // 0x800515B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800515BC: jal         0x800B3BFC
    // 0x800515C0: addiu       $a0, $a0, -0x3528
    ctx->r4 = ADD32(ctx->r4, -0X3528);
    rmonPrintf_recomp(rdram, ctx);
        goto after_7;
    // 0x800515C0: addiu       $a0, $a0, -0x3528
    ctx->r4 = ADD32(ctx->r4, -0X3528);
    after_7:
    // 0x800515C4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800515C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800515CC: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x800515D0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800515D4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800515D8: sb          $t2, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r10;
L_800515DC:
    // 0x800515DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800515E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800515E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800515E8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800515EC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800515F0: jr          $ra
    // 0x800515F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800515F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Game_LatchEndState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800515F8: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x800515FC: nop

    // 0x80051600: beq         $t6, $zero, L_80051610
    if (ctx->r14 == 0) {
        // 0x80051604: nop
    
            goto L_80051610;
    }
    // 0x80051604: nop

    // 0x80051608: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005160C: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
L_80051610:
    // 0x80051610: jr          $ra
    // 0x80051614: nop

    return;
    // 0x80051614: nop

;}

RECOMP_FUNC void Game_StartRound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051618: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005161C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80051620: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80051624: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80051628: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005162C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80051630: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80051634: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x80051638: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005163C: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80051640: beq         $at, $zero, L_80051680
    if (ctx->r1 == 0) {
        // 0x80051644: nop
    
            goto L_80051680;
    }
    // 0x80051644: nop

L_80051648:
    // 0x80051648: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8005164C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80051650: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80051654: addiu       $a0, $t0, 0x7FFF
    ctx->r4 = ADD32(ctx->r8, 0X7FFF);
    // 0x80051658: lw          $a0, 0x612D($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X612D);
    // 0x8005165C: jal         0x80054220
    // 0x80051660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Tetris_FUN_80054220_fourliner(rdram, ctx);
        goto after_0;
    // 0x80051660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80051664: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80051668: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005166C: lbu         $t2, 0x5($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5);
    // 0x80051670: nop

    // 0x80051674: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80051678: bne         $at, $zero, L_80051648
    if (ctx->r1 != 0) {
        // 0x8005167C: nop
    
            goto L_80051648;
    }
    // 0x8005167C: nop

L_80051680:
    // 0x80051680: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80051684: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80051688: sb          $zero, 0x3($t3)
    MEM_B(0X3, ctx->r11) = 0;
    // 0x8005168C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80051690: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80051694: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x80051698: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005169C: nop

    // 0x800516A0: sb          $t5, 0x6($t6)
    MEM_B(0X6, ctx->r14) = ctx->r13;
    // 0x800516A4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800516A8: nop

    // 0x800516AC: lbu         $t8, 0x5($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X5);
    // 0x800516B0: nop

    // 0x800516B4: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800516B8: beq         $at, $zero, L_80051718
    if (ctx->r1 == 0) {
        // 0x800516BC: nop
    
            goto L_80051718;
    }
    // 0x800516BC: nop

L_800516C0:
    // 0x800516C0: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x800516C4: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x800516C8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800516CC: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x800516D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800516D4: addiu       $t0, $t0, -0x10D0
    ctx->r8 = ADD32(ctx->r8, -0X10D0);
    // 0x800516D8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800516DC: addu        $s1, $t9, $t0
    ctx->r17 = ADD32(ctx->r25, ctx->r8);
    // 0x800516E0: addiu       $s2, $s1, 0x28
    ctx->r18 = ADD32(ctx->r17, 0X28);
    // 0x800516E4: sw          $zero, 0x88($s2)
    MEM_W(0X88, ctx->r18) = 0;
    // 0x800516E8: sw          $zero, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = 0;
    // 0x800516EC: jal         0x80060CA0
    // 0x800516F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    ControllerRepeat_Reset(rdram, ctx);
        goto after_1;
    // 0x800516F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800516F4: jal         0x800A3460
    // 0x800516F8: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    Minos_Reset(rdram, ctx);
        goto after_2;
    // 0x800516F8: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    after_2:
    // 0x800516FC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80051700: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80051704: lbu         $t2, 0x5($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5);
    // 0x80051708: nop

    // 0x8005170C: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80051710: bne         $at, $zero, L_800516C0
    if (ctx->r1 != 0) {
        // 0x80051714: nop
    
            goto L_800516C0;
    }
    // 0x80051714: nop

L_80051718:
    // 0x80051718: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8005171C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80051720: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80051724: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80051728: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8005172C: swc1        $f4, -0x1AFC($at)
    MEM_W(-0X1AFC, ctx->r1) = ctx->f4.u32l;
    // 0x80051730: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80051734: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80051738: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8005173C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80051740: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80051744: lwc1        $f8, -0x1B04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1B04);
    // 0x80051748: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8005174C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80051750: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80051754: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80051758: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8005175C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80051760: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80051764: swc1        $f18, -0x1B00($at)
    MEM_W(-0X1B00, ctx->r1) = ctx->f18.u32l;
    // 0x80051768: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005176C: nop

    // 0x80051770: addiu       $at, $t6, 0x7FFF
    ctx->r1 = ADD32(ctx->r14, 0X7FFF);
    // 0x80051774: sb          $t5, 0x6509($at)
    MEM_B(0X6509, ctx->r1) = ctx->r13;
    // 0x80051778: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005177C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80051780: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80051784: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80051788: jr          $ra
    // 0x8005178C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005178C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Game_BeginEndSequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051790: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80051794: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80051798: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005179C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800517A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800517A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800517A8: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x800517AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800517B0: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800517B4: beq         $at, $zero, L_800517F4
    if (ctx->r1 == 0) {
        // 0x800517B8: nop
    
            goto L_800517F4;
    }
    // 0x800517B8: nop

L_800517BC:
    // 0x800517BC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800517C0: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x800517C4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800517C8: addiu       $a0, $t0, 0x7FFF
    ctx->r4 = ADD32(ctx->r8, 0X7FFF);
    // 0x800517CC: lw          $a0, 0x612D($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X612D);
    // 0x800517D0: jal         0x80054220
    // 0x800517D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Tetris_FUN_80054220_fourliner(rdram, ctx);
        goto after_0;
    // 0x800517D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800517D8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800517DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800517E0: lbu         $t2, 0x5($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5);
    // 0x800517E4: nop

    // 0x800517E8: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800517EC: bne         $at, $zero, L_800517BC
    if (ctx->r1 != 0) {
        // 0x800517F0: nop
    
            goto L_800517BC;
    }
    // 0x800517F0: nop

L_800517F4:
    // 0x800517F4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800517F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800517FC: sb          $t3, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r11;
    // 0x80051800: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80051804: lbu         $t5, 0x2F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2F);
    // 0x80051808: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8005180C: sb          $t5, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r13;
    // 0x80051810: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80051814: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051818: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8005181C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80051820: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80051824: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80051828: swc1        $f4, -0x1AFC($at)
    MEM_W(-0X1AFC, ctx->r1) = ctx->f4.u32l;
    // 0x8005182C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80051830: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80051834: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80051838: lwc1        $f8, -0x1B04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1B04);
    // 0x8005183C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80051840: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80051844: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80051848: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8005184C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80051850: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80051854: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80051858: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005185C: swc1        $f18, -0x1B00($at)
    MEM_W(-0X1B00, ctx->r1) = ctx->f18.u32l;
    // 0x80051860: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80051864: nop

    // 0x80051868: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x8005186C: sb          $t1, 0x6509($at)
    MEM_B(0X6509, ctx->r1) = ctx->r9;
    // 0x80051870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80051874: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80051878: jr          $ra
    // 0x8005187C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005187C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Game_FinishAllBoards(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051880: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80051884: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80051888: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005188C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80051890: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80051894: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x80051898: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005189C: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800518A0: beq         $at, $zero, L_800518E0
    if (ctx->r1 == 0) {
        // 0x800518A4: nop
    
            goto L_800518E0;
    }
    // 0x800518A4: nop

L_800518A8:
    // 0x800518A8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800518AC: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x800518B0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800518B4: addiu       $a0, $t0, 0x7FFF
    ctx->r4 = ADD32(ctx->r8, 0X7FFF);
    // 0x800518B8: lw          $a0, 0x612D($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X612D);
    // 0x800518BC: jal         0x80052D48
    // 0x800518C0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    gamefinish_SetPhase4(rdram, ctx);
        goto after_0;
    // 0x800518C0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x800518C4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800518C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800518CC: lbu         $t2, 0x5($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5);
    // 0x800518D0: nop

    // 0x800518D4: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800518D8: bne         $at, $zero, L_800518A8
    if (ctx->r1 != 0) {
        // 0x800518DC: nop
    
            goto L_800518A8;
    }
    // 0x800518DC: nop

L_800518E0:
    // 0x800518E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800518E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800518E8: jr          $ra
    // 0x800518EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800518EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Game_ControllerRepeat_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800518F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800518F4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800518F8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800518FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80051900: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80051904: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80051908: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005190C: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x80051910: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80051914: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80051918: beq         $at, $zero, L_8005199C
    if (ctx->r1 == 0) {
        // 0x8005191C: nop
    
            goto L_8005199C;
    }
    // 0x8005191C: nop

L_80051920:
    // 0x80051920: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80051924: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x80051928: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8005192C: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x80051930: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80051934: addiu       $t9, $t9, -0x10D0
    ctx->r25 = ADD32(ctx->r25, -0X10D0);
    // 0x80051938: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8005193C: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x80051940: lw          $t0, 0x1C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1C);
    // 0x80051944: addiu       $s2, $s1, 0x28
    ctx->r18 = ADD32(ctx->r17, 0X28);
    // 0x80051948: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8005194C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80051950: sw          $t1, 0x88($s2)
    MEM_W(0X88, ctx->r18) = ctx->r9;
    // 0x80051954: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    // 0x80051958: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005195C: addiu       $a1, $a1, -0x34DC
    ctx->r5 = ADD32(ctx->r5, -0X34DC);
    // 0x80051960: addiu       $a0, $a0, -0x34F4
    ctx->r4 = ADD32(ctx->r4, -0X34F4);
    // 0x80051964: jal         0x8006CF08
    // 0x80051968: sw          $t2, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = ctx->r10;
    debug_print2(rdram, ctx);
        goto after_0;
    // 0x80051968: sw          $t2, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = ctx->r10;
    after_0:
    // 0x8005196C: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80051970: lw          $a2, 0x9F4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X9F4);
    // 0x80051974: lw          $a1, 0x88($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X88);
    // 0x80051978: jal         0x80060BD4
    // 0x8005197C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    ControllerRepeat_Update(rdram, ctx);
        goto after_1;
    // 0x8005197C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80051980: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80051984: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80051988: lbu         $t4, 0x5($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X5);
    // 0x8005198C: nop

    // 0x80051990: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80051994: bne         $at, $zero, L_80051920
    if (ctx->r1 != 0) {
        // 0x80051998: nop
    
            goto L_80051920;
    }
    // 0x80051998: nop

L_8005199C:
    // 0x8005199C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800519A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800519A4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800519A8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800519AC: jr          $ra
    // 0x800519B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800519B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Game_HandleEndGameInput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800519B4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800519B8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800519BC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800519C0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800519C4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800519C8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800519CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800519D0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800519D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800519D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800519DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800519E0: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x800519E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800519E8: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800519EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800519F0: beq         $at, $zero, L_80051A90
    if (ctx->r1 == 0) {
        // 0x800519F4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80051A90;
    }
    // 0x800519F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800519F8:
    // 0x800519F8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800519FC: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80051A00: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80051A04: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x80051A08: lw          $t1, 0x612D($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X612D);
    // 0x80051A0C: nop

    // 0x80051A10: lbu         $t2, 0x2($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2);
    // 0x80051A14: nop

    // 0x80051A18: beq         $t2, $zero, L_80051A74
    if (ctx->r10 == 0) {
        // 0x80051A1C: nop
    
            goto L_80051A74;
    }
    // 0x80051A1C: nop

    // 0x80051A20: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x80051A24: subu        $t3, $t3, $s2
    ctx->r11 = SUB32(ctx->r11, ctx->r18);
    // 0x80051A28: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80051A2C: subu        $t3, $t3, $s2
    ctx->r11 = SUB32(ctx->r11, ctx->r18);
    // 0x80051A30: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80051A34: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80051A38: addiu       $t5, $t5, -0x10D0
    ctx->r13 = ADD32(ctx->r13, -0X10D0);
    // 0x80051A3C: addiu       $t4, $t3, 0x28
    ctx->r12 = ADD32(ctx->r11, 0X28);
    // 0x80051A40: addu        $s3, $t4, $t5
    ctx->r19 = ADD32(ctx->r12, ctx->r13);
    // 0x80051A44: lw          $t6, 0x8C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X8C);
    // 0x80051A48: nop

    // 0x80051A4C: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x80051A50: beq         $t7, $zero, L_80051A74
    if (ctx->r15 == 0) {
        // 0x80051A54: nop
    
            goto L_80051A74;
    }
    // 0x80051A54: nop

    // 0x80051A58: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80051A5C: lbu         $t8, -0xB0($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0XB0);
    // 0x80051A60: nop

    // 0x80051A64: beq         $t8, $zero, L_80051A74
    if (ctx->r24 == 0) {
        // 0x80051A68: nop
    
            goto L_80051A74;
    }
    // 0x80051A68: nop

    // 0x80051A6C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80051A70: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80051A74:
    // 0x80051A74: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80051A78: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80051A7C: lbu         $t0, 0x5($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X5);
    // 0x80051A80: nop

    // 0x80051A84: slt         $at, $s2, $t0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80051A88: bne         $at, $zero, L_800519F8
    if (ctx->r1 != 0) {
        // 0x80051A8C: nop
    
            goto L_800519F8;
    }
    // 0x80051A8C: nop

L_80051A90:
    // 0x80051A90: beq         $s0, $zero, L_80051AAC
    if (ctx->r16 == 0) {
        // 0x80051A94: nop
    
            goto L_80051AAC;
    }
    // 0x80051A94: nop

    // 0x80051A98: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80051A9C: jal         0x80051790
    // 0x80051AA0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    Game_BeginEndSequence(rdram, ctx);
        goto after_0;
    // 0x80051AA0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80051AA4: b           L_80051B80
    // 0x80051AA8: nop

        goto L_80051B80;
    // 0x80051AA8: nop

L_80051AAC:
    // 0x80051AAC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80051AB0: jal         0x80051104
    // 0x80051AB4: nop

    Game_CountAlivePlayers(rdram, ctx);
        goto after_1;
    // 0x80051AB4: nop

    after_1:
    // 0x80051AB8: bne         $v0, $zero, L_80051B80
    if (ctx->r2 != 0) {
        // 0x80051ABC: nop
    
            goto L_80051B80;
    }
    // 0x80051ABC: nop

    // 0x80051AC0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80051AC4: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80051AC8: lw          $t3, 0x9F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X9F4);
    // 0x80051ACC: lbu         $t2, 0x7($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X7);
    // 0x80051AD0: nop

    // 0x80051AD4: sltu        $at, $t3, $t2
    ctx->r1 = ctx->r11 < ctx->r10 ? 1 : 0;
    // 0x80051AD8: beq         $at, $zero, L_80051AEC
    if (ctx->r1 == 0) {
        // 0x80051ADC: nop
    
            goto L_80051AEC;
    }
    // 0x80051ADC: nop

    // 0x80051AE0: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80051AE4: b           L_80051B80
    // 0x80051AE8: sb          $t4, 0x7($t1)
    MEM_B(0X7, ctx->r9) = ctx->r12;
        goto L_80051B80;
    // 0x80051AE8: sb          $t4, 0x7($t1)
    MEM_B(0X7, ctx->r9) = ctx->r12;
L_80051AEC:
    // 0x80051AEC: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80051AF0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80051AF4: lbu         $t6, 0x5($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X5);
    // 0x80051AF8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80051AFC: slt         $at, $s5, $t6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80051B00: beq         $at, $zero, L_80051B60
    if (ctx->r1 == 0) {
        // 0x80051B04: nop
    
            goto L_80051B60;
    }
    // 0x80051B04: nop

L_80051B08:
    // 0x80051B08: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x80051B0C: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x80051B10: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80051B14: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x80051B18: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80051B1C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80051B20: addiu       $t9, $t9, -0x10D0
    ctx->r25 = ADD32(ctx->r25, -0X10D0);
    // 0x80051B24: addiu       $t8, $t7, 0x28
    ctx->r24 = ADD32(ctx->r15, 0X28);
    // 0x80051B28: addu        $s6, $t8, $t9
    ctx->r22 = ADD32(ctx->r24, ctx->r25);
    // 0x80051B2C: lw          $t0, 0x8C($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X8C);
    // 0x80051B30: nop

    // 0x80051B34: andi        $t2, $t0, 0x9000
    ctx->r10 = ctx->r8 & 0X9000;
    // 0x80051B38: beq         $t2, $zero, L_80051B44
    if (ctx->r10 == 0) {
        // 0x80051B3C: nop
    
            goto L_80051B44;
    }
    // 0x80051B3C: nop

    // 0x80051B40: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80051B44:
    // 0x80051B44: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80051B48: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80051B4C: lbu         $t4, 0x5($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X5);
    // 0x80051B50: nop

    // 0x80051B54: slt         $at, $s5, $t4
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80051B58: bne         $at, $zero, L_80051B08
    if (ctx->r1 != 0) {
        // 0x80051B5C: nop
    
            goto L_80051B08;
    }
    // 0x80051B5C: nop

L_80051B60:
    // 0x80051B60: beq         $s4, $zero, L_80051B74
    if (ctx->r20 == 0) {
        // 0x80051B64: nop
    
            goto L_80051B74;
    }
    // 0x80051B64: nop

    // 0x80051B68: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80051B6C: jal         0x80051880
    // 0x80051B70: nop

    Game_FinishAllBoards(rdram, ctx);
        goto after_2;
    // 0x80051B70: nop

    after_2:
L_80051B74:
    // 0x80051B74: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80051B78: nop

    // 0x80051B7C: sb          $zero, 0x7($t1)
    MEM_B(0X7, ctx->r9) = 0;
L_80051B80:
    // 0x80051B80: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80051B84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80051B88: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80051B8C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80051B90: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80051B94: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80051B98: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80051B9C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80051BA0: jr          $ra
    // 0x80051BA4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80051BA4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}

RECOMP_FUNC void Game_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051BA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80051BAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80051BB0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80051BB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80051BB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80051BBC: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x80051BC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80051BC4: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80051BC8: beq         $at, $zero, L_80051CA0
    if (ctx->r1 == 0) {
        // 0x80051BCC: nop
    
            goto L_80051CA0;
    }
    // 0x80051BCC: nop

L_80051BD0:
    // 0x80051BD0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80051BD4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80051BD8: addiu       $a1, $a1, -0x34C0
    ctx->r5 = ADD32(ctx->r5, -0X34C0);
    // 0x80051BDC: jal         0x8006CF08
    // 0x80051BE0: addiu       $a0, $a0, -0x34D8
    ctx->r4 = ADD32(ctx->r4, -0X34D8);
    debug_print2(rdram, ctx);
        goto after_0;
    // 0x80051BE0: addiu       $a0, $a0, -0x34D8
    ctx->r4 = ADD32(ctx->r4, -0X34D8);
    after_0:
    // 0x80051BE4: jal         0x80050520
    // 0x80051BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Game_SetGlobalPointers(rdram, ctx);
        goto after_1;
    // 0x80051BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80051BEC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80051BF0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80051BF4: addiu       $a1, $a1, -0x349C
    ctx->r5 = ADD32(ctx->r5, -0X349C);
    // 0x80051BF8: jal         0x8006CF08
    // 0x80051BFC: addiu       $a0, $a0, -0x34BC
    ctx->r4 = ADD32(ctx->r4, -0X34BC);
    debug_print2(rdram, ctx);
        goto after_2;
    // 0x80051BFC: addiu       $a0, $a0, -0x34BC
    ctx->r4 = ADD32(ctx->r4, -0X34BC);
    after_2:
    // 0x80051C00: jal         0x8005061C
    // 0x80051C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerVars_SetGlobalPointers(rdram, ctx);
        goto after_3;
    // 0x80051C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80051C08: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80051C0C: lbu         $t8, -0x118($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X118);
    // 0x80051C10: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80051C14: bne         $t8, $at, L_80051C40
    if (ctx->r24 != ctx->r1) {
        // 0x80051C18: nop
    
            goto L_80051C40;
    }
    // 0x80051C18: nop

    // 0x80051C1C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80051C20: addiu       $t9, $t9, -0x10D0
    ctx->r25 = ADD32(ctx->r25, -0X10D0);
    // 0x80051C24: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x80051C28: nop

    // 0x80051C2C: beq         $t0, $zero, L_80051C40
    if (ctx->r8 == 0) {
        // 0x80051C30: nop
    
            goto L_80051C40;
    }
    // 0x80051C30: nop

    // 0x80051C34: addiu       $t1, $zero, 0xFA0
    ctx->r9 = ADD32(0, 0XFA0);
    // 0x80051C38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051C3C: sw          $t1, 0x550($at)
    MEM_W(0X550, ctx->r1) = ctx->r9;
L_80051C40:
    // 0x80051C40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80051C44: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80051C48: addiu       $a1, $a1, -0x3480
    ctx->r5 = ADD32(ctx->r5, -0X3480);
    // 0x80051C4C: jal         0x8006CF08
    // 0x80051C50: addiu       $a0, $a0, -0x3498
    ctx->r4 = ADD32(ctx->r4, -0X3498);
    debug_print2(rdram, ctx);
        goto after_4;
    // 0x80051C50: addiu       $a0, $a0, -0x3498
    ctx->r4 = ADD32(ctx->r4, -0X3498);
    after_4:
    // 0x80051C54: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80051C58: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80051C5C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80051C60: addiu       $a0, $t4, 0x7FFF
    ctx->r4 = ADD32(ctx->r12, 0X7FFF);
    // 0x80051C64: lw          $a0, 0x612D($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X612D);
    // 0x80051C68: jal         0x8005423C
    // 0x80051C6C: nop

    Tetris_Update(rdram, ctx);
        goto after_5;
    // 0x80051C6C: nop

    after_5:
    // 0x80051C70: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80051C74: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80051C78: addiu       $a1, $a1, -0x3454
    ctx->r5 = ADD32(ctx->r5, -0X3454);
    // 0x80051C7C: jal         0x8006CF08
    // 0x80051C80: addiu       $a0, $a0, -0x3470
    ctx->r4 = ADD32(ctx->r4, -0X3470);
    debug_print2(rdram, ctx);
        goto after_6;
    // 0x80051C80: addiu       $a0, $a0, -0x3470
    ctx->r4 = ADD32(ctx->r4, -0X3470);
    after_6:
    // 0x80051C84: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80051C88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80051C8C: lbu         $t6, 0x5($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X5);
    // 0x80051C90: nop

    // 0x80051C94: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80051C98: bne         $at, $zero, L_80051BD0
    if (ctx->r1 != 0) {
        // 0x80051C9C: nop
    
            goto L_80051BD0;
    }
    // 0x80051C9C: nop

L_80051CA0:
    // 0x80051CA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80051CA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80051CA8: jr          $ra
    // 0x80051CAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80051CAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Game_Tick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051CB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051CB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80051CB8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80051CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051CC0: lbu         $t7, 0x2($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2);
    // 0x80051CC4: nop

    // 0x80051CC8: bne         $t7, $zero, L_80051CE8
    if (ctx->r15 != 0) {
        // 0x80051CCC: nop
    
            goto L_80051CE8;
    }
    // 0x80051CCC: nop

    // 0x80051CD0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80051CD4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80051CD8: addiu       $a1, $a1, -0x343C
    ctx->r5 = ADD32(ctx->r5, -0X343C);
    // 0x80051CDC: addiu       $a0, $a0, -0x3444
    ctx->r4 = ADD32(ctx->r4, -0X3444);
    // 0x80051CE0: jal         0x8004A5A0
    // 0x80051CE4: addiu       $a2, $zero, 0x30E
    ctx->r6 = ADD32(0, 0X30E);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_0;
    // 0x80051CE4: addiu       $a2, $zero, 0x30E
    ctx->r6 = ADD32(0, 0X30E);
    after_0:
L_80051CE8:
    // 0x80051CE8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80051CEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051CF0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80051CF4: nop

    // 0x80051CF8: beq         $t9, $at, L_80051F20
    if (ctx->r25 == ctx->r1) {
        // 0x80051CFC: nop
    
            goto L_80051F20;
    }
    // 0x80051CFC: nop

    // 0x80051D00: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80051D04: nop

    // 0x80051D08: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x80051D0C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80051D10: nop

    // 0x80051D14: addiu       $t2, $t1, 0x7FFF
    ctx->r10 = ADD32(ctx->r9, 0X7FFF);
    // 0x80051D18: lbu         $t2, 0x6509($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X6509);
    // 0x80051D1C: nop

    // 0x80051D20: beq         $t2, $zero, L_80051E2C
    if (ctx->r10 == 0) {
        // 0x80051D24: nop
    
            goto L_80051E2C;
    }
    // 0x80051D24: nop

    // 0x80051D28: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80051D2C: lw          $t3, 0x9F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X9F4);
    // 0x80051D30: ori         $at, $zero, 0xE4FC
    ctx->r1 = 0 | 0XE4FC;
    // 0x80051D34: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80051D38: addu        $a0, $t1, $at
    ctx->r4 = ADD32(ctx->r9, ctx->r1);
    // 0x80051D3C: bgez        $t3, L_80051D54
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80051D40: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80051D54;
    }
    // 0x80051D40: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80051D44: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80051D48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80051D4C: nop

    // 0x80051D50: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80051D54:
    // 0x80051D54: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80051D58: jal         0x80060770
    // 0x80051D5C: nop

    PFGFX_StepValueToTarget(rdram, ctx);
        goto after_1;
    // 0x80051D5C: nop

    after_1:
    // 0x80051D60: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80051D64: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80051D68: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80051D6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80051D70: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80051D74: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80051D78: lwc1        $f8, -0x1B04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1B04);
    // 0x80051D7C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80051D80: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80051D84: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80051D88: nop

    // 0x80051D8C: andi        $at, $a1, 0x4
    ctx->r1 = ctx->r5 & 0X4;
    // 0x80051D90: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80051D94: beq         $a1, $zero, L_80051DE4
    if (ctx->r5 == 0) {
        // 0x80051D98: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80051DE4;
    }
    // 0x80051D98: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80051D9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80051DA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80051DA4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80051DA8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80051DAC: nop

    // 0x80051DB0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80051DB4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80051DB8: nop

    // 0x80051DBC: andi        $at, $a1, 0x4
    ctx->r1 = ctx->r5 & 0X4;
    // 0x80051DC0: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80051DC4: bne         $a1, $zero, L_80051DDC
    if (ctx->r5 != 0) {
        // 0x80051DC8: nop
    
            goto L_80051DDC;
    }
    // 0x80051DC8: nop

    // 0x80051DCC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80051DD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80051DD4: b           L_80051DF4
    // 0x80051DD8: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_80051DF4;
    // 0x80051DD8: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_80051DDC:
    // 0x80051DDC: b           L_80051DF4
    // 0x80051DE0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_80051DF4;
    // 0x80051DE0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80051DE4:
    // 0x80051DE4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80051DE8: nop

    // 0x80051DEC: bltz        $a1, L_80051DDC
    if (SIGNED(ctx->r5) < 0) {
        // 0x80051DF0: nop
    
            goto L_80051DDC;
    }
    // 0x80051DF0: nop

L_80051DF4:
    // 0x80051DF4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80051DF8: jal         0x80050B54
    // 0x80051DFC: nop

    Game_SetAlpha(rdram, ctx);
        goto after_2;
    // 0x80051DFC: nop

    after_2:
    // 0x80051E00: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80051E04: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80051E08: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80051E0C: lwc1        $f16, -0x1B00($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1B00);
    // 0x80051E10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80051E14: nop

    // 0x80051E18: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80051E1C: nop

    // 0x80051E20: bc1f        L_80051E2C
    if (!c1cs) {
        // 0x80051E24: addiu       $at, $t6, 0x7FFF
        ctx->r1 = ADD32(ctx->r14, 0X7FFF);
            goto L_80051E2C;
    }
    // 0x80051E24: addiu       $at, $t6, 0x7FFF
    ctx->r1 = ADD32(ctx->r14, 0X7FFF);
    // 0x80051E28: sb          $zero, 0x6509($at)
    MEM_B(0X6509, ctx->r1) = 0;
L_80051E2C:
    // 0x80051E2C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80051E30: nop

    // 0x80051E34: lbu         $t8, 0x3($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X3);
    // 0x80051E38: nop

    // 0x80051E3C: bne         $t8, $zero, L_80051F20
    if (ctx->r24 != 0) {
        // 0x80051E40: nop
    
            goto L_80051F20;
    }
    // 0x80051E40: nop

    // 0x80051E44: jal         0x80051104
    // 0x80051E48: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    Game_CountAlivePlayers(rdram, ctx);
        goto after_3;
    // 0x80051E48: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_3:
    // 0x80051E4C: beq         $v0, $zero, L_80051E74
    if (ctx->r2 == 0) {
        // 0x80051E50: nop
    
            goto L_80051E74;
    }
    // 0x80051E50: nop

    // 0x80051E54: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80051E58: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x80051E5C: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x80051E60: lw          $t0, 0x64E9($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X64E9);
    // 0x80051E64: lw          $t2, 0x9F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X9F4);
    // 0x80051E68: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80051E6C: addu        $t1, $t0, $t2
    ctx->r9 = ADD32(ctx->r8, ctx->r10);
    // 0x80051E70: sw          $t1, 0x64E9($at)
    MEM_W(0X64E9, ctx->r1) = ctx->r9;
L_80051E74:
    // 0x80051E74: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80051E78: lw          $a0, 0x9F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X9F4);
    // 0x80051E7C: jal         0x800763EC
    // 0x80051E80: nop

    CubeTiles_UpdateGrid(rdram, ctx);
        goto after_4;
    // 0x80051E80: nop

    after_4:
    // 0x80051E84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80051E88: jal         0x800518F0
    // 0x80051E8C: nop

    Game_ControllerRepeat_Update(rdram, ctx);
        goto after_5;
    // 0x80051E8C: nop

    after_5:
    // 0x80051E90: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80051E94: nop

    // 0x80051E98: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80051E9C: nop

    // 0x80051EA0: bne         $t4, $zero, L_80051EB0
    if (ctx->r12 != 0) {
        // 0x80051EA4: nop
    
            goto L_80051EB0;
    }
    // 0x80051EA4: nop

    // 0x80051EA8: jal         0x8004311C
    // 0x80051EAC: nop

    OpponentPlayer_Update(rdram, ctx);
        goto after_6;
    // 0x80051EAC: nop

    after_6:
L_80051EB0:
    // 0x80051EB0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80051EB4: lbu         $t5, -0x118($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X118);
    // 0x80051EB8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80051EBC: beq         $t5, $at, L_80051ED0
    if (ctx->r13 == ctx->r1) {
        // 0x80051EC0: nop
    
            goto L_80051ED0;
    }
    // 0x80051EC0: nop

    // 0x80051EC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80051EC8: jal         0x800519B4
    // 0x80051ECC: nop

    Game_HandleEndGameInput(rdram, ctx);
        goto after_7;
    // 0x80051ECC: nop

    after_7:
L_80051ED0:
    // 0x80051ED0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80051ED4: jal         0x800515F8
    // 0x80051ED8: nop

    Game_LatchEndState(rdram, ctx);
        goto after_8;
    // 0x80051ED8: nop

    after_8:
    // 0x80051EDC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80051EE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051EE4: lbu         $t8, 0x1($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1);
    // 0x80051EE8: nop

    // 0x80051EEC: beq         $t8, $at, L_80051F20
    if (ctx->r24 == ctx->r1) {
        // 0x80051EF0: nop
    
            goto L_80051F20;
    }
    // 0x80051EF0: nop

    // 0x80051EF4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80051EF8: nop

    // 0x80051EFC: lbu         $t0, 0x0($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X0);
    // 0x80051F00: nop

    // 0x80051F04: bne         $t0, $zero, L_80051F14
    if (ctx->r8 != 0) {
        // 0x80051F08: nop
    
            goto L_80051F14;
    }
    // 0x80051F08: nop

    // 0x80051F0C: jal         0x80051BA8
    // 0x80051F10: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    Game_Update(rdram, ctx);
        goto after_9;
    // 0x80051F10: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_9:
L_80051F14:
    // 0x80051F14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80051F18: jal         0x80051464
    // 0x80051F1C: nop

    Game_QueryGameOver(rdram, ctx);
        goto after_10;
    // 0x80051F1C: nop

    after_10:
L_80051F20:
    // 0x80051F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051F28: jr          $ra
    // 0x80051F2C: nop

    return;
    // 0x80051F2C: nop

;}

RECOMP_FUNC void Game_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051F30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80051F34: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80051F38: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80051F3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80051F40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80051F44: lbu         $t7, 0x2($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2);
    // 0x80051F48: nop

    // 0x80051F4C: bne         $t7, $zero, L_80051F6C
    if (ctx->r15 != 0) {
        // 0x80051F50: nop
    
            goto L_80051F6C;
    }
    // 0x80051F50: nop

    // 0x80051F54: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80051F58: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80051F5C: addiu       $a1, $a1, -0x342C
    ctx->r5 = ADD32(ctx->r5, -0X342C);
    // 0x80051F60: addiu       $a0, $a0, -0x3434
    ctx->r4 = ADD32(ctx->r4, -0X3434);
    // 0x80051F64: jal         0x8004A5A0
    // 0x80051F68: addiu       $a2, $zero, 0x352
    ctx->r6 = ADD32(0, 0X352);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_0;
    // 0x80051F68: addiu       $a2, $zero, 0x352
    ctx->r6 = ADD32(0, 0X352);
    after_0:
L_80051F6C:
    // 0x80051F6C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80051F70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051F74: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80051F78: nop

    // 0x80051F7C: beq         $t9, $at, L_80052080
    if (ctx->r25 == ctx->r1) {
        // 0x80051F80: nop
    
            goto L_80052080;
    }
    // 0x80051F80: nop

    // 0x80051F84: jal         0x800636C0
    // 0x80051F88: nop

    PFGFX_DrawPlayfield(rdram, ctx);
        goto after_1;
    // 0x80051F88: nop

    after_1:
    // 0x80051F8C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80051F90: ori         $at, $zero, 0xE0E8
    ctx->r1 = 0 | 0XE0E8;
    // 0x80051F94: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x80051F98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80051F9C: jal         0x80072A84
    // 0x80051FA0: sw          $t1, -0x390($at)
    MEM_W(-0X390, ctx->r1) = ctx->r9;
    Landfill_Update(rdram, ctx);
        goto after_2;
    // 0x80051FA0: sw          $t1, -0x390($at)
    MEM_W(-0X390, ctx->r1) = ctx->r9;
    after_2:
    // 0x80051FA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80051FA8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80051FAC: addiu       $a1, $a1, -0x341C
    ctx->r5 = ADD32(ctx->r5, -0X341C);
    // 0x80051FB0: jal         0x8006CF08
    // 0x80051FB4: addiu       $a0, $a0, -0x3424
    ctx->r4 = ADD32(ctx->r4, -0X3424);
    debug_print2(rdram, ctx);
        goto after_3;
    // 0x80051FB4: addiu       $a0, $a0, -0x3424
    ctx->r4 = ADD32(ctx->r4, -0X3424);
    after_3:
    // 0x80051FB8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80051FBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80051FC0: lbu         $t3, 0x5($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X5);
    // 0x80051FC4: nop

    // 0x80051FC8: sltu        $at, $s0, $t3
    ctx->r1 = ctx->r16 < ctx->r11 ? 1 : 0;
    // 0x80051FCC: beq         $at, $zero, L_80052058
    if (ctx->r1 == 0) {
        // 0x80051FD0: nop
    
            goto L_80052058;
    }
    // 0x80051FD0: nop

L_80051FD4:
    // 0x80051FD4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80051FD8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80051FDC: addiu       $a1, $a1, -0x3408
    ctx->r5 = ADD32(ctx->r5, -0X3408);
    // 0x80051FE0: jal         0x8006CF08
    // 0x80051FE4: addiu       $a0, $a0, -0x3410
    ctx->r4 = ADD32(ctx->r4, -0X3410);
    debug_print2(rdram, ctx);
        goto after_4;
    // 0x80051FE4: addiu       $a0, $a0, -0x3410
    ctx->r4 = ADD32(ctx->r4, -0X3410);
    after_4:
    // 0x80051FE8: jal         0x80050520
    // 0x80051FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Game_SetGlobalPointers(rdram, ctx);
        goto after_5;
    // 0x80051FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80051FF0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80051FF4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80051FF8: addiu       $a1, $a1, -0x33F8
    ctx->r5 = ADD32(ctx->r5, -0X33F8);
    // 0x80051FFC: jal         0x8006CF08
    // 0x80052000: addiu       $a0, $a0, -0x3400
    ctx->r4 = ADD32(ctx->r4, -0X3400);
    debug_print2(rdram, ctx);
        goto after_6;
    // 0x80052000: addiu       $a0, $a0, -0x3400
    ctx->r4 = ADD32(ctx->r4, -0X3400);
    after_6:
    // 0x80052004: jal         0x8005061C
    // 0x80052008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerVars_SetGlobalPointers(rdram, ctx);
        goto after_7;
    // 0x80052008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8005200C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052010: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80052014: addiu       $a1, $a1, -0x33E8
    ctx->r5 = ADD32(ctx->r5, -0X33E8);
    // 0x80052018: jal         0x8006CF08
    // 0x8005201C: addiu       $a0, $a0, -0x33F0
    ctx->r4 = ADD32(ctx->r4, -0X33F0);
    debug_print2(rdram, ctx);
        goto after_8;
    // 0x8005201C: addiu       $a0, $a0, -0x33F0
    ctx->r4 = ADD32(ctx->r4, -0X33F0);
    after_8:
    // 0x80052020: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80052024: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80052028: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8005202C: addiu       $a0, $t6, 0x7FFF
    ctx->r4 = ADD32(ctx->r14, 0X7FFF);
    // 0x80052030: lw          $a0, 0x612D($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X612D);
    // 0x80052034: jal         0x8005447C
    // 0x80052038: nop

    Tetris_Render(rdram, ctx);
        goto after_9;
    // 0x80052038: nop

    after_9:
    // 0x8005203C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80052040: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80052044: lbu         $t8, 0x5($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X5);
    // 0x80052048: nop

    // 0x8005204C: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x80052050: bne         $at, $zero, L_80051FD4
    if (ctx->r1 != 0) {
        // 0x80052054: nop
    
            goto L_80051FD4;
    }
    // 0x80052054: nop

L_80052058:
    // 0x80052058: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005205C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80052060: addiu       $a1, $a1, -0x33D8
    ctx->r5 = ADD32(ctx->r5, -0X33D8);
    // 0x80052064: jal         0x8006CF08
    // 0x80052068: addiu       $a0, $a0, -0x33E0
    ctx->r4 = ADD32(ctx->r4, -0X33E0);
    debug_print2(rdram, ctx);
        goto after_10;
    // 0x80052068: addiu       $a0, $a0, -0x33E0
    ctx->r4 = ADD32(ctx->r4, -0X33E0);
    after_10:
    // 0x8005206C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052070: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80052074: addiu       $a1, $a1, -0x33C8
    ctx->r5 = ADD32(ctx->r5, -0X33C8);
    // 0x80052078: jal         0x8006CF08
    // 0x8005207C: addiu       $a0, $a0, -0x33D0
    ctx->r4 = ADD32(ctx->r4, -0X33D0);
    debug_print2(rdram, ctx);
        goto after_11;
    // 0x8005207C: addiu       $a0, $a0, -0x33D0
    ctx->r4 = ADD32(ctx->r4, -0X33D0);
    after_11:
L_80052080:
    // 0x80052080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80052084: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80052088: jr          $ra
    // 0x8005208C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005208C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Game_DeinitCubeTiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052090: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80052094: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80052098: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8005209C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800520A0: addiu       $s0, $s0, 0xA00
    ctx->r16 = ADD32(ctx->r16, 0XA00);
    // 0x800520A4: ori         $at, $zero, 0xE080
    ctx->r1 = 0 | 0XE080;
    // 0x800520A8: jal         0x80075F5C
    // 0x800520AC: addu        $a0, $s0, $at
    ctx->r4 = ADD32(ctx->r16, ctx->r1);
    CubeTiles_Free(rdram, ctx);
        goto after_0;
    // 0x800520AC: addu        $a0, $s0, $at
    ctx->r4 = ADD32(ctx->r16, ctx->r1);
    after_0:
    // 0x800520B0: jal         0x80075DB4
    // 0x800520B4: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    CubeTiles_Deinit(rdram, ctx);
        goto after_1;
    // 0x800520B4: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    after_1:
    // 0x800520B8: jal         0x8006B384
    // 0x800520BC: nop

    MultisquareGlow_FreeStaticMembers(rdram, ctx);
        goto after_2;
    // 0x800520BC: nop

    after_2:
    // 0x800520C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800520C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800520C8: jr          $ra
    // 0x800520CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800520CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Game_InitCubeTiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800520D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800520D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800520D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800520DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800520E0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800520E4: lbu         $a0, -0x10E0($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X10E0);
    // 0x800520E8: jal         0x8006B248
    // 0x800520EC: addiu       $s0, $s0, 0xA00
    ctx->r16 = ADD32(ctx->r16, 0XA00);
    MultisquareGlow_InitStaticMembers(rdram, ctx);
        goto after_0;
    // 0x800520EC: addiu       $s0, $s0, 0xA00
    ctx->r16 = ADD32(ctx->r16, 0XA00);
    after_0:
    // 0x800520F0: ori         $at, $zero, 0xE080
    ctx->r1 = 0 | 0XE080;
    // 0x800520F4: jal         0x80075EB0
    // 0x800520F8: addu        $a0, $s0, $at
    ctx->r4 = ADD32(ctx->r16, ctx->r1);
    CubeTiles_Alloc(rdram, ctx);
        goto after_1;
    // 0x800520F8: addu        $a0, $s0, $at
    ctx->r4 = ADD32(ctx->r16, ctx->r1);
    after_1:
    // 0x800520FC: jal         0x80075C98
    // 0x80052100: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    CubeTiles_Init(rdram, ctx);
        goto after_2;
    // 0x80052100: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    after_2:
    // 0x80052104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80052108: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005210C: jr          $ra
    // 0x80052110: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80052110: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Game_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052114: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80052118: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005211C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80052120: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80052124: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80052128: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8005212C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80052130: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80052134: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80052138: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005213C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80052140: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80052144: addiu       $s0, $s0, 0xA00
    ctx->r16 = ADD32(ctx->r16, 0XA00);
    // 0x80052148: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005214C: sb          $t6, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r14;
    // 0x80052150: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80052154: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052158: lbu         $a1, 0x73($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X73);
    // 0x8005215C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052160: sb          $t7, -0xB0($at)
    MEM_B(-0XB0, ctx->r1) = ctx->r15;
    // 0x80052164: jal         0x800B3BFC
    // 0x80052168: addiu       $a0, $a0, -0x33BC
    ctx->r4 = ADD32(ctx->r4, -0X33BC);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80052168: addiu       $a0, $a0, -0x33BC
    ctx->r4 = ADD32(ctx->r4, -0X33BC);
    after_0:
    // 0x8005216C: lbu         $t8, 0x73($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X73);
    // 0x80052170: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80052174: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80052178: beq         $at, $zero, L_800521B0
    if (ctx->r1 == 0) {
        // 0x8005217C: nop
    
            goto L_800521B0;
    }
    // 0x8005217C: nop

L_80052180:
    // 0x80052180: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80052184: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052188: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x8005218C: lbu         $a2, 0x0($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X0);
    // 0x80052190: addiu       $a0, $a0, -0x3398
    ctx->r4 = ADD32(ctx->r4, -0X3398);
    // 0x80052194: jal         0x800B3BFC
    // 0x80052198: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x80052198: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8005219C: lbu         $t1, 0x73($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X73);
    // 0x800521A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800521A4: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800521A8: bne         $at, $zero, L_80052180
    if (ctx->r1 != 0) {
        // 0x800521AC: nop
    
            goto L_80052180;
    }
    // 0x800521AC: nop

L_800521B0:
    // 0x800521B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800521B4: jal         0x800B3BFC
    // 0x800521B8: addiu       $a0, $a0, -0x3388
    ctx->r4 = ADD32(ctx->r4, -0X3388);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800521B8: addiu       $a0, $a0, -0x3388
    ctx->r4 = ADD32(ctx->r4, -0X3388);
    after_2:
    // 0x800521BC: lbu         $t2, 0x73($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X73);
    // 0x800521C0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800521C4: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800521C8: beq         $at, $zero, L_8005223C
    if (ctx->r1 == 0) {
        // 0x800521CC: nop
    
            goto L_8005223C;
    }
    // 0x800521CC: nop

L_800521D0:
    // 0x800521D0: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x800521D4: nop

    // 0x800521D8: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800521DC: lbu         $s3, 0x0($t4)
    ctx->r19 = MEM_BU(ctx->r12, 0X0);
    // 0x800521E0: nop

    // 0x800521E4: bgez        $s3, L_80052204
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800521E8: nop
    
            goto L_80052204;
    }
    // 0x800521E8: nop

    // 0x800521EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800521F0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800521F4: addiu       $a1, $a1, -0x336C
    ctx->r5 = ADD32(ctx->r5, -0X336C);
    // 0x800521F8: addiu       $a0, $a0, -0x3384
    ctx->r4 = ADD32(ctx->r4, -0X3384);
    // 0x800521FC: jal         0x8004A5A0
    // 0x80052200: addiu       $a2, $zero, 0x3DC
    ctx->r6 = ADD32(0, 0X3DC);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_3;
    // 0x80052200: addiu       $a2, $zero, 0x3DC
    ctx->r6 = ADD32(0, 0X3DC);
    after_3:
L_80052204:
    // 0x80052204: slti        $at, $s3, 0xA
    ctx->r1 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x80052208: bne         $at, $zero, L_80052228
    if (ctx->r1 != 0) {
        // 0x8005220C: nop
    
            goto L_80052228;
    }
    // 0x8005220C: nop

    // 0x80052210: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052214: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80052218: addiu       $a1, $a1, -0x334C
    ctx->r5 = ADD32(ctx->r5, -0X334C);
    // 0x8005221C: addiu       $a0, $a0, -0x3364
    ctx->r4 = ADD32(ctx->r4, -0X3364);
    // 0x80052220: jal         0x8004A5A0
    // 0x80052224: addiu       $a2, $zero, 0x3DF
    ctx->r6 = ADD32(0, 0X3DF);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_4;
    // 0x80052224: addiu       $a2, $zero, 0x3DF
    ctx->r6 = ADD32(0, 0X3DF);
    after_4:
L_80052228:
    // 0x80052228: lbu         $t5, 0x73($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X73);
    // 0x8005222C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80052230: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80052234: bne         $at, $zero, L_800521D0
    if (ctx->r1 != 0) {
        // 0x80052238: nop
    
            goto L_800521D0;
    }
    // 0x80052238: nop

L_8005223C:
    // 0x8005223C: lbu         $t6, 0x73($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X73);
    // 0x80052240: addiu       $a0, $s0, 0x7FFF
    ctx->r4 = ADD32(ctx->r16, 0X7FFF);
    // 0x80052244: sb          $t6, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r14;
    // 0x80052248: lbu         $a0, 0x64F9($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X64F9);
    // 0x8005224C: jal         0x80062788
    // 0x80052250: nop

    PFGFX_GameInit(rdram, ctx);
        goto after_5;
    // 0x80052250: nop

    after_5:
    // 0x80052254: addiu       $at, $s0, 0x7FFF
    ctx->r1 = ADD32(ctx->r16, 0X7FFF);
    // 0x80052258: sw          $zero, 0x64E9($at)
    MEM_W(0X64E9, ctx->r1) = 0;
    // 0x8005225C: addiu       $at, $s0, 0x7FFF
    ctx->r1 = ADD32(ctx->r16, 0X7FFF);
    // 0x80052260: sb          $zero, 0x6510($at)
    MEM_B(0X6510, ctx->r1) = 0;
    // 0x80052264: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x80052268: sb          $t7, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r15;
    // 0x8005226C: addiu       $s6, $s0, 0x7FFF
    ctx->r22 = ADD32(ctx->r16, 0X7FFF);
    // 0x80052270: lbu         $s6, 0x64ED($s6)
    ctx->r22 = MEM_BU(ctx->r22, 0X64ED);
    // 0x80052274: nop

    // 0x80052278: beq         $s6, $zero, L_800522D0
    if (ctx->r22 == 0) {
        // 0x8005227C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800522D0;
    }
    // 0x8005227C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052280: beq         $s6, $at, L_80052298
    if (ctx->r22 == ctx->r1) {
        // 0x80052284: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80052298;
    }
    // 0x80052284: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052288: beq         $s6, $at, L_800522A8
    if (ctx->r22 == ctx->r1) {
        // 0x8005228C: nop
    
            goto L_800522A8;
    }
    // 0x8005228C: nop

    // 0x80052290: b           L_800522B8
    // 0x80052294: nop

        goto L_800522B8;
    // 0x80052294: nop

L_80052298:
    // 0x80052298: addiu       $t8, $zero, 0x2A30
    ctx->r24 = ADD32(0, 0X2A30);
    // 0x8005229C: addiu       $at, $s0, 0x7FFF
    ctx->r1 = ADD32(ctx->r16, 0X7FFF);
    // 0x800522A0: b           L_800522D0
    // 0x800522A4: sw          $t8, 0x64F1($at)
    MEM_W(0X64F1, ctx->r1) = ctx->r24;
        goto L_800522D0;
    // 0x800522A4: sw          $t8, 0x64F1($at)
    MEM_W(0X64F1, ctx->r1) = ctx->r24;
L_800522A8:
    // 0x800522A8: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x800522AC: addiu       $at, $s0, 0x7FFF
    ctx->r1 = ADD32(ctx->r16, 0X7FFF);
    // 0x800522B0: b           L_800522D0
    // 0x800522B4: sw          $t9, 0x64F5($at)
    MEM_W(0X64F5, ctx->r1) = ctx->r25;
        goto L_800522D0;
    // 0x800522B4: sw          $t9, 0x64F5($at)
    MEM_W(0X64F5, ctx->r1) = ctx->r25;
L_800522B8:
    // 0x800522B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800522BC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800522C0: addiu       $a1, $a1, -0x3330
    ctx->r5 = ADD32(ctx->r5, -0X3330);
    // 0x800522C4: addiu       $a0, $a0, -0x3344
    ctx->r4 = ADD32(ctx->r4, -0X3344);
    // 0x800522C8: jal         0x8004A5A0
    // 0x800522CC: addiu       $a2, $zero, 0x419
    ctx->r6 = ADD32(0, 0X419);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_6;
    // 0x800522CC: addiu       $a2, $zero, 0x419
    ctx->r6 = ADD32(0, 0X419);
    after_6:
L_800522D0:
    // 0x800522D0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800522D4: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800522D8: lbu         $t0, 0x73($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X73);
    // 0x800522DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800522E0: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    // 0x800522E4: jal         0x80075C98
    // 0x800522E8: sb          $t0, -0x10E0($at)
    MEM_B(-0X10E0, ctx->r1) = ctx->r8;
    CubeTiles_Init(rdram, ctx);
        goto after_7;
    // 0x800522E8: sb          $t0, -0x10E0($at)
    MEM_B(-0X10E0, ctx->r1) = ctx->r8;
    after_7:
    // 0x800522EC: ori         $at, $zero, 0xE080
    ctx->r1 = 0 | 0XE080;
    // 0x800522F0: jal         0x80075EB0
    // 0x800522F4: addu        $a0, $s0, $at
    ctx->r4 = ADD32(ctx->r16, ctx->r1);
    CubeTiles_Alloc(rdram, ctx);
        goto after_8;
    // 0x800522F4: addu        $a0, $s0, $at
    ctx->r4 = ADD32(ctx->r16, ctx->r1);
    after_8:
    // 0x800522F8: ori         $at, $zero, 0xE0E8
    ctx->r1 = 0 | 0XE0E8;
    // 0x800522FC: jal         0x8007287C
    // 0x80052300: addu        $a0, $s0, $at
    ctx->r4 = ADD32(ctx->r16, ctx->r1);
    Landfill_Init(rdram, ctx);
        goto after_9;
    // 0x80052300: addu        $a0, $s0, $at
    ctx->r4 = ADD32(ctx->r16, ctx->r1);
    after_9:
    // 0x80052304: jal         0x8007635C
    // 0x80052308: nop

    CubeTiles_AllocGrid(rdram, ctx);
        goto after_10;
    // 0x80052308: nop

    after_10:
    // 0x8005230C: lbu         $a0, 0x73($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X73);
    // 0x80052310: jal         0x8006B248
    // 0x80052314: nop

    MultisquareGlow_InitStaticMembers(rdram, ctx);
        goto after_11;
    // 0x80052314: nop

    after_11:
    // 0x80052318: lbu         $a0, 0x73($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X73);
    // 0x8005231C: jal         0x8005344C
    // 0x80052320: nop

    gamefinish_LoadResultImages(rdram, ctx);
        goto after_12;
    // 0x80052320: nop

    after_12:
    // 0x80052324: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80052328: jal         0x80077408
    // 0x8005232C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    Font_Init46Char(rdram, ctx);
        goto after_13;
    // 0x8005232C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_13:
    // 0x80052330: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80052334: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80052338: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8005233C: swc1        $f4, -0x1B04($at)
    MEM_W(-0X1B04, ctx->r1) = ctx->f4.u32l;
    // 0x80052340: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80052344: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80052348: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8005234C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80052350: swc1        $f6, -0x1AFC($at)
    MEM_W(-0X1AFC, ctx->r1) = ctx->f6.u32l;
    // 0x80052354: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80052358: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005235C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80052360: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80052364: lwc1        $f10, -0x1B04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1B04);
    // 0x80052368: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8005236C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80052370: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80052374: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80052378: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8005237C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80052380: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80052384: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80052388: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8005238C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80052390: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x80052394: swc1        $f4, -0x1B00($at)
    MEM_W(-0X1B00, ctx->r1) = ctx->f4.u32l;
    // 0x80052398: addiu       $at, $s0, 0x7FFF
    ctx->r1 = ADD32(ctx->r16, 0X7FFF);
    // 0x8005239C: sb          $t1, 0x6509($at)
    MEM_B(0X6509, ctx->r1) = ctx->r9;
    // 0x800523A0: lw          $t2, -0x310($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X310);
    // 0x800523A4: nop

    // 0x800523A8: lw          $t3, 0x18F4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18F4);
    // 0x800523AC: jal         0x800B7658
    // 0x800523B0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_14;
    // 0x800523B0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_14:
    // 0x800523B4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800523B8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800523BC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800523C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800523C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800523C8: jal         0x800B7558
    // 0x800523CC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    __ull_div_recomp(rdram, ctx);
        goto after_15;
    // 0x800523CC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_15:
    // 0x800523D0: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x800523D4: jal         0x800B6550
    // 0x800523D8: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    osGetTime_recomp(rdram, ctx);
        goto after_16;
    // 0x800523D8: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    after_16:
    // 0x800523DC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800523E0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800523E4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800523E8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800523EC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800523F0: jal         0x800B7658
    // 0x800523F4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_17;
    // 0x800523F4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_17:
    // 0x800523F8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800523FC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80052400: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80052404: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80052408: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005240C: jal         0x800B7558
    // 0x80052410: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    __ull_div_recomp(rdram, ctx);
        goto after_18;
    // 0x80052410: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_18:
    // 0x80052414: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80052418: lw          $t6, -0x310($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X310);
    // 0x8005241C: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x80052420: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80052424: sw          $t5, 0x18F4($t6)
    MEM_W(0X18F4, ctx->r14) = ctx->r13;
    // 0x80052428: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x8005242C: jal         0x8007C5CC
    // 0x80052430: nop

    SaveData_Save(rdram, ctx);
        goto after_19;
    // 0x80052430: nop

    after_19:
    // 0x80052434: ori         $at, $zero, 0xE080
    ctx->r1 = 0 | 0XE080;
    // 0x80052438: addu        $t7, $s0, $at
    ctx->r15 = ADD32(ctx->r16, ctx->r1);
    // 0x8005243C: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x80052440: addiu       $t8, $s0, 0x7FFF
    ctx->r24 = ADD32(ctx->r16, 0X7FFF);
    // 0x80052444: lbu         $t8, 0x64F9($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X64F9);
    // 0x80052448: lbu         $t0, 0x73($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X73);
    // 0x8005244C: addiu       $t9, $s0, 0x7FFF
    ctx->r25 = ADD32(ctx->r16, 0X7FFF);
    // 0x80052450: sb          $t8, 0x5C($sp)
    MEM_B(0X5C, ctx->r29) = ctx->r24;
    // 0x80052454: lbu         $t9, 0x64ED($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X64ED);
    // 0x80052458: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8005245C: slt         $at, $s4, $t0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80052460: beq         $at, $zero, L_8005252C
    if (ctx->r1 == 0) {
        // 0x80052464: sb          $t9, 0x5E($sp)
        MEM_B(0X5E, ctx->r29) = ctx->r25;
            goto L_8005252C;
    }
    // 0x80052464: sb          $t9, 0x5E($sp)
    MEM_B(0X5E, ctx->r29) = ctx->r25;
L_80052468:
    // 0x80052468: jal         0x8007E03C
    // 0x8005246C: addiu       $a0, $zero, 0x6848
    ctx->r4 = ADD32(0, 0X6848);
    n64HeapAlloc(rdram, ctx);
        goto after_20;
    // 0x8005246C: addiu       $a0, $zero, 0x6848
    ctx->r4 = ADD32(0, 0X6848);
    after_20:
    // 0x80052470: sll         $t1, $s4, 2
    ctx->r9 = S32(ctx->r20 << 2);
    // 0x80052474: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x80052478: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x8005247C: sw          $v0, 0x612D($at)
    MEM_W(0X612D, ctx->r1) = ctx->r2;
    // 0x80052480: jal         0x80050520
    // 0x80052484: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Game_SetGlobalPointers(rdram, ctx);
        goto after_21;
    // 0x80052484: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_21:
    // 0x80052488: jal         0x8005061C
    // 0x8005248C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    PlayerVars_SetGlobalPointers(rdram, ctx);
        goto after_22;
    // 0x8005248C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_22:
    // 0x80052490: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80052494: lw          $s5, -0xDF0($s5)
    ctx->r21 = MEM_W(ctx->r21, -0XDF0);
    // 0x80052498: nop

    // 0x8005249C: addiu       $s5, $s5, 0x28
    ctx->r21 = ADD32(ctx->r21, 0X28);
    // 0x800524A0: jal         0x80060AD4
    // 0x800524A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    ControllerRepeat_ArmAll(rdram, ctx);
        goto after_23;
    // 0x800524A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_23:
    // 0x800524A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800524AC: addiu       $a1, $zero, 0xF00
    ctx->r5 = ADD32(0, 0XF00);
    // 0x800524B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800524B4: jal         0x80060B04
    // 0x800524B8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    ControllerRepeat_Arm(rdram, ctx);
        goto after_24;
    // 0x800524B8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_24:
    // 0x800524BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800524C0: ori         $a1, $zero, 0xC000
    ctx->r5 = 0 | 0XC000;
    // 0x800524C4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800524C8: jal         0x80060B04
    // 0x800524CC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    ControllerRepeat_Arm(rdram, ctx);
        goto after_25;
    // 0x800524CC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_25:
    // 0x800524D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800524D4: lw          $t3, -0xDF0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XDF0);
    // 0x800524D8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800524DC: sw          $zero, 0x24($t3)
    MEM_W(0X24, ctx->r11) = 0;
    // 0x800524E0: lw          $t4, -0xDF0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XDF0);
    // 0x800524E4: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x800524E8: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x800524EC: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x800524F0: sw          $t5, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r13;
    // 0x800524F4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800524F8: addiu       $a0, $t0, 0x7FFF
    ctx->r4 = ADD32(ctx->r8, 0X7FFF);
    // 0x800524FC: addu        $t7, $t6, $s4
    ctx->r15 = ADD32(ctx->r14, ctx->r20);
    // 0x80052500: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80052504: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80052508: sb          $t8, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = ctx->r24;
    // 0x8005250C: lw          $a0, 0x612D($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X612D);
    // 0x80052510: jal         0x800547F0
    // 0x80052514: nop

    Tetris_Init(rdram, ctx);
        goto after_26;
    // 0x80052514: nop

    after_26:
    // 0x80052518: lbu         $t1, 0x73($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X73);
    // 0x8005251C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80052520: slt         $at, $s4, $t1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80052524: bne         $at, $zero, L_80052468
    if (ctx->r1 != 0) {
        // 0x80052528: nop
    
            goto L_80052468;
    }
    // 0x80052528: nop

L_8005252C:
    // 0x8005252C: jal         0x80041260
    // 0x80052530: nop

    aisquarelist_CreateState(rdram, ctx);
        goto after_27;
    // 0x80052530: nop

    after_27:
    // 0x80052534: jal         0x800B6650
    // 0x80052538: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_28;
    // 0x80052538: nop

    after_28:
    // 0x8005253C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052540: jal         0x800B3BFC
    // 0x80052544: addiu       $a0, $a0, -0x3328
    ctx->r4 = ADD32(ctx->r4, -0X3328);
    rmonPrintf_recomp(rdram, ctx);
        goto after_29;
    // 0x80052544: addiu       $a0, $a0, -0x3328
    ctx->r4 = ADD32(ctx->r4, -0X3328);
    after_29:
    // 0x80052548: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8005254C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80052550: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80052554: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80052558: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005255C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80052560: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80052564: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80052568: jr          $ra
    // 0x8005256C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8005256C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}

RECOMP_FUNC void Game_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052570: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80052574: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80052578: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8005257C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80052580: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80052584: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80052588: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005258C: addiu       $s0, $s0, 0xA00
    ctx->r16 = ADD32(ctx->r16, 0XA00);
    // 0x80052590: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x80052594: nop

    // 0x80052598: bne         $t6, $zero, L_800525B8
    if (ctx->r14 != 0) {
        // 0x8005259C: nop
    
            goto L_800525B8;
    }
    // 0x8005259C: nop

    // 0x800525A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800525A4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800525A8: addiu       $a1, $a1, -0x330C
    ctx->r5 = ADD32(ctx->r5, -0X330C);
    // 0x800525AC: addiu       $a0, $a0, -0x3314
    ctx->r4 = ADD32(ctx->r4, -0X3314);
    // 0x800525B0: jal         0x8004A5A0
    // 0x800525B4: addiu       $a2, $zero, 0x48D
    ctx->r6 = ADD32(0, 0X48D);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_0;
    // 0x800525B4: addiu       $a2, $zero, 0x48D
    ctx->r6 = ADD32(0, 0X48D);
    after_0:
L_800525B8:
    // 0x800525B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800525BC: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x800525C0: jal         0x800B3BFC
    // 0x800525C4: addiu       $a0, $a0, -0x3304
    ctx->r4 = ADD32(ctx->r4, -0X3304);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800525C4: addiu       $a0, $a0, -0x3304
    ctx->r4 = ADD32(ctx->r4, -0X3304);
    after_1:
    // 0x800525C8: lbu         $t7, 0x5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5);
    // 0x800525CC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800525D0: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800525D4: beq         $at, $zero, L_8005262C
    if (ctx->r1 == 0) {
        // 0x800525D8: nop
    
            goto L_8005262C;
    }
    // 0x800525D8: nop

L_800525DC:
    // 0x800525DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800525E0: jal         0x80050E60
    // 0x800525E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    Game_isGameWinner(rdram, ctx);
        goto after_2;
    // 0x800525E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800525E8: beq         $v0, $zero, L_80052608
    if (ctx->r2 == 0) {
        // 0x800525EC: nop
    
            goto L_80052608;
    }
    // 0x800525EC: nop

    // 0x800525F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800525F4: addiu       $a0, $a0, -0x32E0
    ctx->r4 = ADD32(ctx->r4, -0X32E0);
    // 0x800525F8: jal         0x800B3BFC
    // 0x800525FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x800525FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80052600: b           L_80052618
    // 0x80052604: nop

        goto L_80052618;
    // 0x80052604: nop

L_80052608:
    // 0x80052608: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005260C: addiu       $a0, $a0, -0x32C8
    ctx->r4 = ADD32(ctx->r4, -0X32C8);
    // 0x80052610: jal         0x800B3BFC
    // 0x80052614: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_4;
    // 0x80052614: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
L_80052618:
    // 0x80052618: lbu         $t8, 0x5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X5);
    // 0x8005261C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80052620: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80052624: bne         $at, $zero, L_800525DC
    if (ctx->r1 != 0) {
        // 0x80052628: nop
    
            goto L_800525DC;
    }
    // 0x80052628: nop

L_8005262C:
    // 0x8005262C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052630: jal         0x800B3BFC
    // 0x80052634: addiu       $a0, $a0, -0x32B0
    ctx->r4 = ADD32(ctx->r4, -0X32B0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_5;
    // 0x80052634: addiu       $a0, $a0, -0x32B0
    ctx->r4 = ADD32(ctx->r4, -0X32B0);
    after_5:
    // 0x80052638: lbu         $t9, 0x5($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X5);
    // 0x8005263C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80052640: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80052644: beq         $at, $zero, L_80052684
    if (ctx->r1 == 0) {
        // 0x80052648: nop
    
            goto L_80052684;
    }
    // 0x80052648: nop

L_8005264C:
    // 0x8005264C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80052650: jal         0x80050E60
    // 0x80052654: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    Game_isGameWinner(rdram, ctx);
        goto after_6;
    // 0x80052654: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x80052658: beq         $v0, $zero, L_80052670
    if (ctx->r2 == 0) {
        // 0x8005265C: nop
    
            goto L_80052670;
    }
    // 0x8005265C: nop

    // 0x80052660: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052664: addiu       $a0, $a0, -0x3298
    ctx->r4 = ADD32(ctx->r4, -0X3298);
    // 0x80052668: jal         0x800B3BFC
    // 0x8005266C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_7;
    // 0x8005266C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
L_80052670:
    // 0x80052670: lbu         $t0, 0x5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X5);
    // 0x80052674: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80052678: slt         $at, $s2, $t0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8005267C: bne         $at, $zero, L_8005264C
    if (ctx->r1 != 0) {
        // 0x80052680: nop
    
            goto L_8005264C;
    }
    // 0x80052680: nop

L_80052684:
    // 0x80052684: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052688: jal         0x800B3BFC
    // 0x8005268C: addiu       $a0, $a0, -0x328C
    ctx->r4 = ADD32(ctx->r4, -0X328C);
    rmonPrintf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005268C: addiu       $a0, $a0, -0x328C
    ctx->r4 = ADD32(ctx->r4, -0X328C);
    after_8:
    // 0x80052690: jal         0x800630EC
    // 0x80052694: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    PFGFX_GameDeinit(rdram, ctx);
        goto after_9;
    // 0x80052694: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80052698: jal         0x80042B3C
    // 0x8005269C: nop

    OpponentPlayer_Deinit(rdram, ctx);
        goto after_10;
    // 0x8005269C: nop

    after_10:
    // 0x800526A0: jal         0x8004129C
    // 0x800526A4: nop

    aisquarelist_DestroyState(rdram, ctx);
        goto after_11;
    // 0x800526A4: nop

    after_11:
    // 0x800526A8: lbu         $t1, 0x5($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X5);
    // 0x800526AC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800526B0: slt         $at, $s3, $t1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800526B4: beq         $at, $zero, L_80052718
    if (ctx->r1 == 0) {
        // 0x800526B8: nop
    
            goto L_80052718;
    }
    // 0x800526B8: nop

L_800526BC:
    // 0x800526BC: jal         0x80050520
    // 0x800526C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Game_SetGlobalPointers(rdram, ctx);
        goto after_12;
    // 0x800526C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x800526C4: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x800526C8: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800526CC: addiu       $a0, $t3, 0x7FFF
    ctx->r4 = ADD32(ctx->r11, 0X7FFF);
    // 0x800526D0: lw          $a0, 0x612D($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X612D);
    // 0x800526D4: jal         0x80054AF4
    // 0x800526D8: nop

    Tetris_Deinit(rdram, ctx);
        goto after_13;
    // 0x800526D8: nop

    after_13:
    // 0x800526DC: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x800526E0: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x800526E4: addiu       $a0, $t5, 0x7FFF
    ctx->r4 = ADD32(ctx->r13, 0X7FFF);
    // 0x800526E8: lw          $a0, 0x612D($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X612D);
    // 0x800526EC: jal         0x8007E328
    // 0x800526F0: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_14;
    // 0x800526F0: nop

    after_14:
    // 0x800526F4: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x800526F8: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800526FC: addiu       $at, $t7, 0x7FFF
    ctx->r1 = ADD32(ctx->r15, 0X7FFF);
    // 0x80052700: sw          $zero, 0x612D($at)
    MEM_W(0X612D, ctx->r1) = 0;
    // 0x80052704: lbu         $t8, 0x5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X5);
    // 0x80052708: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8005270C: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80052710: bne         $at, $zero, L_800526BC
    if (ctx->r1 != 0) {
        // 0x80052714: nop
    
            goto L_800526BC;
    }
    // 0x80052714: nop

L_80052718:
    // 0x80052718: jal         0x800534A4
    // 0x8005271C: nop

    gamefinish_FreeResultImages(rdram, ctx);
        goto after_15;
    // 0x8005271C: nop

    after_15:
    // 0x80052720: jal         0x8006B384
    // 0x80052724: nop

    MultisquareGlow_FreeStaticMembers(rdram, ctx);
        goto after_16;
    // 0x80052724: nop

    after_16:
    // 0x80052728: jal         0x800763B4
    // 0x8005272C: nop

    CubeTiles_FreeGrid(rdram, ctx);
        goto after_17;
    // 0x8005272C: nop

    after_17:
    // 0x80052730: jal         0x800773D0
    // 0x80052734: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    Font_Deinit(rdram, ctx);
        goto after_18;
    // 0x80052734: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_18:
    // 0x80052738: ori         $at, $zero, 0xE0E8
    ctx->r1 = 0 | 0XE0E8;
    // 0x8005273C: jal         0x80072988
    // 0x80052740: addu        $a0, $s0, $at
    ctx->r4 = ADD32(ctx->r16, ctx->r1);
    Landfill_Deinit(rdram, ctx);
        goto after_19;
    // 0x80052740: addu        $a0, $s0, $at
    ctx->r4 = ADD32(ctx->r16, ctx->r1);
    after_19:
    // 0x80052744: jal         0x80075DB4
    // 0x80052748: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    CubeTiles_Deinit(rdram, ctx);
        goto after_20;
    // 0x80052748: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    after_20:
    // 0x8005274C: ori         $at, $zero, 0xE080
    ctx->r1 = 0 | 0XE080;
    // 0x80052750: jal         0x80075F5C
    // 0x80052754: addu        $a0, $s0, $at
    ctx->r4 = ADD32(ctx->r16, ctx->r1);
    CubeTiles_Free(rdram, ctx);
        goto after_21;
    // 0x80052754: addu        $a0, $s0, $at
    ctx->r4 = ADD32(ctx->r16, ctx->r1);
    after_21:
    // 0x80052758: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005275C: sb          $zero, -0x10E0($at)
    MEM_B(-0X10E0, ctx->r1) = 0;
    // 0x80052760: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80052764: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052768: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x8005276C: jal         0x800B3BFC
    // 0x80052770: addiu       $a0, $a0, -0x3288
    ctx->r4 = ADD32(ctx->r4, -0X3288);
    rmonPrintf_recomp(rdram, ctx);
        goto after_22;
    // 0x80052770: addiu       $a0, $a0, -0x3288
    ctx->r4 = ADD32(ctx->r4, -0X3288);
    after_22:
    // 0x80052774: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80052778: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005277C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80052780: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80052784: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80052788: jr          $ra
    // 0x8005278C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005278C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void initLinesInfo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052790: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80052794: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80052798: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8005279C: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800527A0: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x800527A4: jr          $ra
    // 0x800527A8: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    return;
    // 0x800527A8: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
;}

RECOMP_FUNC void updateLineCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800527AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800527B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800527B4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800527B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800527BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800527C0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800527C4: nop

    // 0x800527C8: beq         $t7, $zero, L_8005281C
    if (ctx->r15 == 0) {
        // 0x800527CC: nop
    
            goto L_8005281C;
    }
    // 0x800527CC: nop

    // 0x800527D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800527D4: jal         0x8005282C
    // 0x800527D8: nop

    getLineCount(rdram, ctx);
        goto after_0;
    // 0x800527D8: nop

    after_0:
    // 0x800527DC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800527E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800527E4: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800527E8: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x800527EC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800527F0: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800527F4: mflo        $t1
    ctx->r9 = lo;
    // 0x800527F8: addu        $a1, $s0, $t1
    ctx->r5 = ADD32(ctx->r16, ctx->r9);
    // 0x800527FC: jal         0x8005283C
    // 0x80052800: nop

    setLineCount(rdram, ctx);
        goto after_1;
    // 0x80052800: nop

    after_1:
    // 0x80052804: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80052808: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005280C: sw          $t2, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r10;
    // 0x80052810: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80052814: nop

    // 0x80052818: sw          $zero, 0xC($t4)
    MEM_W(0XC, ctx->r12) = 0;
L_8005281C:
    // 0x8005281C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80052820: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80052824: jr          $ra
    // 0x80052828: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80052828: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void getLineCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005282C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80052830: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80052834: jr          $ra
    // 0x80052838: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    return;
    // 0x80052838: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
;}

RECOMP_FUNC void setLineCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005283C: lui         $at, 0xAAAA
    ctx->r1 = S32(0XAAAA << 16);
    // 0x80052840: ori         $at, $at, 0xAAAA
    ctx->r1 = ctx->r1 | 0XAAAA;
    // 0x80052844: and         $t6, $a1, $at
    ctx->r14 = ctx->r5 & ctx->r1;
    // 0x80052848: lui         $at, 0x5555
    ctx->r1 = S32(0X5555 << 16);
    // 0x8005284C: ori         $at, $at, 0x5555
    ctx->r1 = ctx->r1 | 0X5555;
    // 0x80052850: and         $t7, $a1, $at
    ctx->r15 = ctx->r5 & ctx->r1;
    // 0x80052854: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80052858: jr          $ra
    // 0x8005285C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    return;
    // 0x8005285C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void displayLineCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052860: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80052864: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80052868: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8005286C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80052870: jal         0x8005282C
    // 0x80052874: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    getLineCount(rdram, ctx);
        goto after_0;
    // 0x80052874: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    after_0:
    // 0x80052878: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005287C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80052880: addiu       $a1, $a1, -0x3270
    ctx->r5 = ADD32(ctx->r5, -0X3270);
    // 0x80052884: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80052888: jal         0x800B62D4
    // 0x8005288C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8005288C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80052890: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052894: jal         0x8005BBFC
    // 0x80052898: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_2;
    // 0x80052898: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_2:
    // 0x8005289C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800528A0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800528A4: lh          $a2, 0x0($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X0);
    // 0x800528A8: lh          $a3, 0x2($t6)
    ctx->r7 = MEM_H(ctx->r14, 0X2);
    // 0x800528AC: addiu       $a1, $a1, 0xA00
    ctx->r5 = ADD32(ctx->r5, 0XA00);
    // 0x800528B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800528B4: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x800528B8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800528BC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800528C0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800528C4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800528C8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800528CC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800528D0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800528D4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800528D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800528DC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800528E0: jal         0x80077960
    // 0x800528E4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_3;
    // 0x800528E4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_3:
    // 0x800528E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800528EC: jal         0x8005BE40
    // 0x800528F0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_4;
    // 0x800528F0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_4:
    // 0x800528F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800528F8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800528FC: jr          $ra
    // 0x80052900: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80052900: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void PieceHoldPiece_MakeShadowActive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006576C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065770: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065774: lh          $t6, 0x28($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X28);
    // 0x80065778: lh          $t8, 0x2A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A);
    // 0x8006577C: addiu       $t7, $t6, 0x80
    ctx->r15 = ADD32(ctx->r14, 0X80);
    // 0x80065780: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x80065784: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80065788: sh          $t7, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r15;
    // 0x8006578C: sh          $t9, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r25;
    // 0x80065790: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80065794: lwl         $t2, 0x28($sp)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r29, 0X28);
    // 0x80065798: lwl         $t3, 0x2C($sp)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r29, 0X2C);
    // 0x8006579C: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x800657A0: lwr         $t2, 0x2B($sp)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r29, 0X2B);
    // 0x800657A4: lwr         $t3, 0x2F($sp)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r29, 0X2F);
    // 0x800657A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800657AC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800657B0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800657B4: swl         $t2, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r10);
    // 0x800657B8: swl         $t3, 0xC($sp)
    do_swl(rdram, 0XC, ctx->r29, ctx->r11);
    // 0x800657BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800657C0: lhu         $t4, 0x32($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X32);
    // 0x800657C4: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x800657C8: swr         $t2, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r10);
    // 0x800657CC: swr         $t3, 0xF($sp)
    do_swr(rdram, 0XF, ctx->r29, ctx->r11);
    // 0x800657D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800657D4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x800657D8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x800657DC: lw          $a1, 0x110($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X110);
    // 0x800657E0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800657E4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800657E8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800657EC: jal         0x800653E4
    // 0x800657F0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    MobilePiece_Init(rdram, ctx);
        goto after_0;
    // 0x800657F0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
    // 0x800657F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800657F8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800657FC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80065800: jal         0x8006531C
    // 0x80065804: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    MobilePiece_SetCubesPosition(rdram, ctx);
        goto after_1;
    // 0x80065804: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
    // 0x80065808: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8006580C: addiu       $t7, $zero, 0xAA0
    ctx->r15 = ADD32(0, 0XAA0);
    // 0x80065810: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
    // 0x80065814: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80065818: nop

    // 0x8006581C: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    // 0x80065820: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80065824: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80065828: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x8006582C: lh          $t1, 0x2($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X2);
    // 0x80065830: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80065834: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80065838: div         $zero, $t2, $t3
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r11)));
    // 0x8006583C: bne         $t3, $zero, L_80065848
    if (ctx->r11 != 0) {
        // 0x80065840: nop
    
            goto L_80065848;
    }
    // 0x80065840: nop

    // 0x80065844: break       7
    do_break(2147899460);
L_80065848:
    // 0x80065848: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006584C: bne         $t3, $at, L_80065860
    if (ctx->r11 != ctx->r1) {
        // 0x80065850: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80065860;
    }
    // 0x80065850: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065854: bne         $t2, $at, L_80065860
    if (ctx->r10 != ctx->r1) {
        // 0x80065858: nop
    
            goto L_80065860;
    }
    // 0x80065858: nop

    // 0x8006585C: break       6
    do_break(2147899484);
L_80065860:
    // 0x80065860: mflo        $t4
    ctx->r12 = lo;
    // 0x80065864: sh          $t4, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r12;
    // 0x80065868: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8006586C: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x80065870: nop

    // 0x80065874: sh          $t5, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r13;
    // 0x80065878: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8006587C: nop

    // 0x80065880: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80065884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065888: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006588C: jr          $ra
    // 0x80065890: nop

    return;
    // 0x80065890: nop

;}

RECOMP_FUNC void PieceHoldPiece_RenderShadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065894: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065898: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006589C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800658A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800658A4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800658A8: nop

    // 0x800658AC: beq         $t7, $zero, L_8006592C
    if (ctx->r15 == 0) {
        // 0x800658B0: nop
    
            goto L_8006592C;
    }
    // 0x800658B0: nop

    // 0x800658B4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800658B8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800658BC: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800658C0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800658C4: lbu         $t0, 0x1($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X1);
    // 0x800658C8: nop

    // 0x800658CC: bne         $t0, $at, L_800658E8
    if (ctx->r8 != ctx->r1) {
        // 0x800658D0: nop
    
            goto L_800658E8;
    }
    // 0x800658D0: nop

    // 0x800658D4: lh          $t1, 0x2($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X2);
    // 0x800658D8: nop

    // 0x800658DC: sra         $t2, $t1, 4
    ctx->r10 = S32(SIGNED(ctx->r9) >> 4);
    // 0x800658E0: b           L_8006590C
    // 0x800658E4: sb          $t2, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r10;
        goto L_8006590C;
    // 0x800658E4: sb          $t2, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r10;
L_800658E8:
    // 0x800658E8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800658EC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800658F0: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x800658F4: lbu         $t5, 0x1($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X1);
    // 0x800658F8: nop

    // 0x800658FC: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065900: mflo        $t6
    ctx->r14 = lo;
    // 0x80065904: sra         $t7, $t6, 12
    ctx->r15 = S32(SIGNED(ctx->r14) >> 12);
    // 0x80065908: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
L_8006590C:
    // 0x8006590C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80065910: nop

    // 0x80065914: lhu         $a0, 0x8($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X8);
    // 0x80065918: jal         0x80070D00
    // 0x8006591C: nop

    Minos_SetScale(rdram, ctx);
        goto after_0;
    // 0x8006591C: nop

    after_0:
    // 0x80065920: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80065924: jal         0x80064FB0
    // 0x80065928: nop

    MobilePiece_Render(rdram, ctx);
        goto after_1;
    // 0x80065928: nop

    after_1:
L_8006592C:
    // 0x8006592C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065930: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065934: jr          $ra
    // 0x80065938: nop

    return;
    // 0x80065938: nop

;}

RECOMP_FUNC void PieceHoldPiece_FinishSwap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800659C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800659C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800659C8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800659CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800659D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800659D4: lbu         $t7, 0x1A($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1A);
    // 0x800659D8: nop

    // 0x800659DC: bne         $t7, $zero, L_800659FC
    if (ctx->r15 != 0) {
        // 0x800659E0: nop
    
            goto L_800659FC;
    }
    // 0x800659E0: nop

    // 0x800659E4: lbu         $a0, 0x1($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X1);
    // 0x800659E8: jal         0x80067DD8
    // 0x800659EC: nop

    CurrentPiece_Spawn(rdram, ctx);
        goto after_0;
    // 0x800659EC: nop

    after_0:
    // 0x800659F0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800659F4: nop

    // 0x800659F8: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
L_800659FC:
    // 0x800659FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065A00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065A04: jr          $ra
    // 0x80065A08: nop

    return;
    // 0x80065A08: nop

;}

RECOMP_FUNC void PieceHoldPiece_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065ADC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80065AE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80065AE4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80065AE8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80065AEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065AF0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80065AF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80065AF8: jal         0x8006593C
    // 0x80065AFC: addiu       $a0, $a0, 0x538
    ctx->r4 = ADD32(ctx->r4, 0X538);
    PieceHold_AdvanceTween(rdram, ctx);
        goto after_0;
    // 0x80065AFC: addiu       $a0, $a0, 0x538
    ctx->r4 = ADD32(ctx->r4, 0X538);
    after_0:
    // 0x80065B00: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80065B04: nop

    // 0x80065B08: lbu         $s0, 0x0($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0X0);
    // 0x80065B0C: nop

    // 0x80065B10: beq         $s0, $zero, L_80065BC4
    if (ctx->r16 == 0) {
        // 0x80065B14: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80065BC4;
    }
    // 0x80065B14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80065B18: beq         $s0, $at, L_80065B30
    if (ctx->r16 == ctx->r1) {
        // 0x80065B1C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80065B30;
    }
    // 0x80065B1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80065B20: beq         $s0, $at, L_80065B68
    if (ctx->r16 == ctx->r1) {
        // 0x80065B24: nop
    
            goto L_80065B68;
    }
    // 0x80065B24: nop

    // 0x80065B28: b           L_80065BB0
    // 0x80065B2C: nop

        goto L_80065BB0;
    // 0x80065B2C: nop

L_80065B30:
    // 0x80065B30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80065B34: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80065B38: jal         0x800655C4
    // 0x80065B3C: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    MobilePiece_UpdateAltColor(rdram, ctx);
        goto after_1;
    // 0x80065B3C: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    after_1:
    // 0x80065B40: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80065B44: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80065B48: jal         0x80064F54
    // 0x80065B4C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    MobilePiece_MorphCubes(rdram, ctx);
        goto after_2;
    // 0x80065B4C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_2:
    // 0x80065B50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80065B54: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80065B58: jal         0x80065A0C
    // 0x80065B5C: nop

    PieceHold_AdvanceSlide(rdram, ctx);
        goto after_3;
    // 0x80065B5C: nop

    after_3:
    // 0x80065B60: b           L_80065BC4
    // 0x80065B64: nop

        goto L_80065BC4;
    // 0x80065B64: nop

L_80065B68:
    // 0x80065B68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80065B6C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80065B70: jal         0x800655C4
    // 0x80065B74: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    MobilePiece_UpdateAltColor(rdram, ctx);
        goto after_4;
    // 0x80065B74: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    after_4:
    // 0x80065B78: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80065B7C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80065B80: jal         0x80064F54
    // 0x80065B84: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    MobilePiece_MorphCubes(rdram, ctx);
        goto after_5;
    // 0x80065B84: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_5:
    // 0x80065B88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80065B8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80065B90: jal         0x80065A0C
    // 0x80065B94: nop

    PieceHold_AdvanceSlide(rdram, ctx);
        goto after_6;
    // 0x80065B94: nop

    after_6:
    // 0x80065B98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80065B9C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80065BA0: jal         0x800659C0
    // 0x80065BA4: nop

    PieceHoldPiece_FinishSwap(rdram, ctx);
        goto after_7;
    // 0x80065BA4: nop

    after_7:
    // 0x80065BA8: b           L_80065BC4
    // 0x80065BAC: nop

        goto L_80065BC4;
    // 0x80065BAC: nop

L_80065BB0:
    // 0x80065BB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80065BB4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80065BB8: addiu       $a1, $a1, -0x2B28
    ctx->r5 = ADD32(ctx->r5, -0X2B28);
    // 0x80065BBC: jal         0x80083560
    // 0x80065BC0: addiu       $a0, $a0, -0x2B40
    ctx->r4 = ADD32(ctx->r4, -0X2B40);
    debug_print_reason_routine(rdram, ctx);
        goto after_8;
    // 0x80065BC0: addiu       $a0, $a0, -0x2B40
    ctx->r4 = ADD32(ctx->r4, -0X2B40);
    after_8:
L_80065BC4:
    // 0x80065BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065BC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80065BCC: jr          $ra
    // 0x80065BD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065BD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void PieceHoldPiece_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065BD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80065BD8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80065BDC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80065BE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065BE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80065BE8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80065BEC: nop

    // 0x80065BF0: beq         $t7, $zero, L_80065C64
    if (ctx->r15 == 0) {
        // 0x80065BF4: nop
    
            goto L_80065C64;
    }
    // 0x80065BF4: nop

    // 0x80065BF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80065BFC: jal         0x80065894
    // 0x80065C00: addiu       $a0, $a0, 0x538
    ctx->r4 = ADD32(ctx->r4, 0X538);
    PieceHoldPiece_RenderShadow(rdram, ctx);
        goto after_0;
    // 0x80065C00: addiu       $a0, $a0, 0x538
    ctx->r4 = ADD32(ctx->r4, 0X538);
    after_0:
    // 0x80065C04: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80065C08: nop

    // 0x80065C0C: lh          $a0, 0x6($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X6);
    // 0x80065C10: jal         0x80070D00
    // 0x80065C14: nop

    Minos_SetScale(rdram, ctx);
        goto after_1;
    // 0x80065C14: nop

    after_1:
    // 0x80065C18: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80065C1C: nop

    // 0x80065C20: lwl         $at, 0xA($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0XA);
    // 0x80065C24: lwr         $at, 0xD($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0XD);
    // 0x80065C28: addiu       $s0, $t9, 0x20
    ctx->r16 = ADD32(ctx->r25, 0X20);
    // 0x80065C2C: swl         $at, 0xA($s0)
    do_swl(rdram, 0XA, ctx->r16, ctx->r1);
    // 0x80065C30: swr         $at, 0xD($s0)
    do_swr(rdram, 0XD, ctx->r16, ctx->r1);
    // 0x80065C34: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80065C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80065C3C: lwl         $at, 0x12($t2)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r10, 0X12);
    // 0x80065C40: lwr         $at, 0x15($t2)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r10, 0X15);
    // 0x80065C44: nop

    // 0x80065C48: swl         $at, 0xE($s0)
    do_swl(rdram, 0XE, ctx->r16, ctx->r1);
    // 0x80065C4C: swr         $at, 0x11($s0)
    do_swr(rdram, 0X11, ctx->r16, ctx->r1);
    // 0x80065C50: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80065C54: nop

    // 0x80065C58: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x80065C5C: jal         0x80064FB0
    // 0x80065C60: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    MobilePiece_Render(rdram, ctx);
        goto after_2;
    // 0x80065C60: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    after_2:
L_80065C64:
    // 0x80065C64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065C68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80065C6C: jr          $ra
    // 0x80065C70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065C70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void PieceHoldPiece_MakeActive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065C74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80065C78: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80065C7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065C80: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80065C84: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80065C88: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80065C8C: addiu       $t7, $sp, 0x38
    ctx->r15 = ADD32(ctx->r29, 0X38);
    // 0x80065C90: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80065C94: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80065C98: addiu       $t3, $sp, 0x3C
    ctx->r11 = ADD32(ctx->r29, 0X3C);
    // 0x80065C9C: swl         $at, 0x12($t6)
    do_swl(rdram, 0X12, ctx->r14, ctx->r1);
    // 0x80065CA0: swr         $at, 0x15($t6)
    do_swr(rdram, 0X15, ctx->r14, ctx->r1);
    // 0x80065CA4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80065CA8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80065CAC: sh          $zero, 0x16($t0)
    MEM_H(0X16, ctx->r8) = 0;
    // 0x80065CB0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80065CB4: nop

    // 0x80065CB8: sh          $zero, 0x18($t1)
    MEM_H(0X18, ctx->r9) = 0;
    // 0x80065CBC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80065CC0: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80065CC4: nop

    // 0x80065CC8: swl         $at, 0xA($t2)
    do_swl(rdram, 0XA, ctx->r10, ctx->r1);
    // 0x80065CCC: swr         $at, 0xD($t2)
    do_swr(rdram, 0XD, ctx->r10, ctx->r1);
    // 0x80065CD0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80065CD4: nop

    // 0x80065CD8: sh          $zero, 0xE($t8)
    MEM_H(0XE, ctx->r24) = 0;
    // 0x80065CDC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80065CE0: nop

    // 0x80065CE4: sh          $zero, 0x10($t6)
    MEM_H(0X10, ctx->r14) = 0;
    // 0x80065CE8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80065CEC: lh          $t7, 0x46($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X46);
    // 0x80065CF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80065CF4: sh          $t7, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r15;
    // 0x80065CF8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80065CFC: nop

    // 0x80065D00: sh          $zero, 0x8($t0)
    MEM_H(0X8, ctx->r8) = 0;
    // 0x80065D04: lhu         $t1, 0x42($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X42);
    // 0x80065D08: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80065D0C: nop

    // 0x80065D10: sh          $t1, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r9;
    // 0x80065D14: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80065D18: nop

    // 0x80065D1C: sh          $zero, 0x4($t2)
    MEM_H(0X4, ctx->r10) = 0;
    // 0x80065D20: lbu         $t3, 0x37($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X37);
    // 0x80065D24: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80065D28: nop

    // 0x80065D2C: sb          $t3, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r11;
    // 0x80065D30: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80065D34: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80065D38: sb          $zero, 0x1A($t8)
    MEM_B(0X1A, ctx->r24) = 0;
    // 0x80065D3C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80065D40: nop

    // 0x80065D44: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80065D48: lwl         $t1, 0x38($sp)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r29, 0X38);
    // 0x80065D4C: lwl         $t4, 0x3C($sp)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r29, 0X3C);
    // 0x80065D50: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x80065D54: lwr         $t1, 0x3B($sp)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r29, 0X3B);
    // 0x80065D58: lwr         $t4, 0x3F($sp)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r29, 0X3F);
    // 0x80065D5C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80065D60: swl         $t1, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r9);
    // 0x80065D64: swl         $t4, 0xC($sp)
    do_swl(rdram, 0XC, ctx->r29, ctx->r12);
    // 0x80065D68: lhu         $t2, 0x42($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X42);
    // 0x80065D6C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80065D70: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80065D74: swr         $t1, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r9);
    // 0x80065D78: swr         $t4, 0xF($sp)
    do_swr(rdram, 0XF, ctx->r29, ctx->r12);
    // 0x80065D7C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80065D80: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80065D84: lw          $a1, 0x110($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X110);
    // 0x80065D88: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80065D8C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80065D90: jal         0x800653E4
    // 0x80065D94: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    MobilePiece_Init(rdram, ctx);
        goto after_0;
    // 0x80065D94: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x80065D98: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80065D9C: nop

    // 0x80065DA0: addiu       $a0, $t5, 0x518
    ctx->r4 = ADD32(ctx->r13, 0X518);
    // 0x80065DA4: jal         0x8006553C
    // 0x80065DA8: addiu       $a1, $t5, 0x20
    ctx->r5 = ADD32(ctx->r13, 0X20);
    MobilePiece_InitFromPiece(rdram, ctx);
        goto after_1;
    // 0x80065DA8: addiu       $a1, $t5, 0x20
    ctx->r5 = ADD32(ctx->r13, 0X20);
    after_1:
    // 0x80065DAC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80065DB0: addiu       $t8, $sp, 0x24
    ctx->r24 = ADD32(ctx->r29, 0X24);
    // 0x80065DB4: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80065DB8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80065DBC: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80065DC0: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x80065DC4: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x80065DC8: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x80065DCC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80065DD0: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80065DD4: lwl         $t4, 0x4($t9)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r25, 0X4);
    // 0x80065DD8: lwr         $t4, 0x7($t9)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r25, 0X7);
    // 0x80065DDC: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80065DE0: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x80065DE4: lwl         $at, 0x8($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X8);
    // 0x80065DE8: lwr         $at, 0xB($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0XB);
    // 0x80065DEC: jal         0x80054DA0
    // 0x80065DF0: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    Color_Blend(rdram, ctx);
        goto after_2;
    // 0x80065DF0: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    after_2:
    // 0x80065DF4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80065DF8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80065DFC: jal         0x800656CC
    // 0x80065E00: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    MobilePiece_SetAlternateColor(rdram, ctx);
        goto after_3;
    // 0x80065E00: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    after_3:
    // 0x80065E04: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80065E08: jal         0x80065710
    // 0x80065E0C: addiu       $a0, $a0, 0x538
    ctx->r4 = ADD32(ctx->r4, 0X538);
    PieceHold_ClearSlot(rdram, ctx);
        goto after_4;
    // 0x80065E0C: addiu       $a0, $a0, 0x538
    ctx->r4 = ADD32(ctx->r4, 0X538);
    after_4:
    // 0x80065E10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065E14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80065E18: jr          $ra
    // 0x80065E1C: nop

    return;
    // 0x80065E1C: nop

;}

RECOMP_FUNC void PieceHoldPiece_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065FF0: jr          $ra
    // 0x80065FF4: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x80065FF4: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}

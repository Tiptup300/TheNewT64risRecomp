#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Tetris_CheckButtons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053F50: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80053F54: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80053F58: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80053F5C: lw          $s0, -0xDD0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0XDD0);
    // 0x80053F60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80053F64: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80053F68: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80053F6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80053F70: lbu         $t6, 0x4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X4);
    // 0x80053F74: nop

    // 0x80053F78: blez        $t6, L_80053F94
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80053F7C: nop
    
            goto L_80053F94;
    }
    // 0x80053F7C: nop

    // 0x80053F80: lbu         $t7, 0x4($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4);
    // 0x80053F84: nop

    // 0x80053F88: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80053F8C: b           L_80054204
    // 0x80053F90: sb          $t8, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r24;
        goto L_80054204;
    // 0x80053F90: sb          $t8, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r24;
L_80053F94:
    // 0x80053F94: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80053F98: addiu       $s3, $s0, 0x830
    ctx->r19 = ADD32(ctx->r16, 0X830);
    // 0x80053F9C: lw          $s1, -0xDF0($s1)
    ctx->r17 = MEM_W(ctx->r17, -0XDF0);
    // 0x80053FA0: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
    // 0x80053FA4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80053FA8: lbu         $s2, -0x10DF($s2)
    ctx->r18 = MEM_BU(ctx->r18, -0X10DF);
    // 0x80053FAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053FB0: bne         $t9, $at, L_80054198
    if (ctx->r25 != ctx->r1) {
        // 0x80053FB4: addiu       $s1, $s1, 0x28
        ctx->r17 = ADD32(ctx->r17, 0X28);
            goto L_80054198;
    }
    // 0x80053FB4: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x80053FB8: lw          $t0, 0x8C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8C);
    // 0x80053FBC: nop

    // 0x80053FC0: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x80053FC4: beq         $t1, $zero, L_80053FF0
    if (ctx->r9 == 0) {
        // 0x80053FC8: nop
    
            goto L_80053FF0;
    }
    // 0x80053FC8: nop

    // 0x80053FCC: addiu       $a0, $s0, 0x51F0
    ctx->r4 = ADD32(ctx->r16, 0X51F0);
    // 0x80053FD0: jal         0x800661D4
    // 0x80053FD4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    PieceHold_Swap(rdram, ctx);
        goto after_0;
    // 0x80053FD4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x80053FD8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80053FDC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80053FE0: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80053FE4: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80053FE8: jal         0x8008A5C8
    // 0x80053FEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Audio2_Play_SFX(rdram, ctx);
        goto after_1;
    // 0x80053FEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80053FF0:
    // 0x80053FF0: lw          $t2, 0x84($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X84);
    // 0x80053FF4: nop

    // 0x80053FF8: andi        $t3, $t2, 0x200
    ctx->r11 = ctx->r10 & 0X200;
    // 0x80053FFC: beq         $t3, $zero, L_80054014
    if (ctx->r11 == 0) {
        // 0x80054000: nop
    
            goto L_80054014;
    }
    // 0x80054000: nop

    // 0x80054004: lbu         $t4, 0x2($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X2);
    // 0x80054008: nop

    // 0x8005400C: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80054010: sb          $t5, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r13;
L_80054014:
    // 0x80054014: lw          $t6, 0x84($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X84);
    // 0x80054018: nop

    // 0x8005401C: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x80054020: beq         $t7, $zero, L_80054038
    if (ctx->r15 == 0) {
        // 0x80054024: nop
    
            goto L_80054038;
    }
    // 0x80054024: nop

    // 0x80054028: lbu         $t8, 0x2($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X2);
    // 0x8005402C: nop

    // 0x80054030: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80054034: sb          $t9, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r25;
L_80054038:
    // 0x80054038: lw          $t0, 0x84($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X84);
    // 0x8005403C: nop

    // 0x80054040: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80054044: beq         $t1, $zero, L_8005405C
    if (ctx->r9 == 0) {
        // 0x80054048: nop
    
            goto L_8005405C;
    }
    // 0x80054048: nop

    // 0x8005404C: lbu         $t2, 0x2($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X2);
    // 0x80054050: nop

    // 0x80054054: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x80054058: sb          $t3, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r11;
L_8005405C:
    // 0x8005405C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
    // 0x80054060: nop

    // 0x80054064: andi        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 & 0X4000;
    // 0x80054068: beq         $t5, $zero, L_80054080
    if (ctx->r13 == 0) {
        // 0x8005406C: nop
    
            goto L_80054080;
    }
    // 0x8005406C: nop

    // 0x80054070: lbu         $t6, 0x2($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X2);
    // 0x80054074: nop

    // 0x80054078: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8005407C: sb          $t7, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r15;
L_80054080:
    // 0x80054080: lw          $t8, 0x88($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X88);
    // 0x80054084: nop

    // 0x80054088: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x8005408C: bne         $t9, $zero, L_800540A4
    if (ctx->r25 != 0) {
        // 0x80054090: nop
    
            goto L_800540A4;
    }
    // 0x80054090: nop

    // 0x80054094: lbu         $t0, 0x2($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X2);
    // 0x80054098: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8005409C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800540A0: sb          $t1, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r9;
L_800540A4:
    // 0x800540A4: lw          $t2, 0x88($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X88);
    // 0x800540A8: nop

    // 0x800540AC: andi        $t3, $t2, 0x100
    ctx->r11 = ctx->r10 & 0X100;
    // 0x800540B0: bne         $t3, $zero, L_800540C8
    if (ctx->r11 != 0) {
        // 0x800540B4: nop
    
            goto L_800540C8;
    }
    // 0x800540B4: nop

    // 0x800540B8: lbu         $t4, 0x2($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X2);
    // 0x800540BC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800540C0: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800540C4: sb          $t5, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r13;
L_800540C8:
    // 0x800540C8: lw          $t6, 0x88($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X88);
    // 0x800540CC: nop

    // 0x800540D0: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x800540D4: bne         $t7, $zero, L_800540EC
    if (ctx->r15 != 0) {
        // 0x800540D8: nop
    
            goto L_800540EC;
    }
    // 0x800540D8: nop

    // 0x800540DC: lbu         $t8, 0x2($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X2);
    // 0x800540E0: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800540E4: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800540E8: sb          $t9, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r25;
L_800540EC:
    // 0x800540EC: lw          $t0, 0x88($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X88);
    // 0x800540F0: nop

    // 0x800540F4: andi        $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 & 0X4000;
    // 0x800540F8: bne         $t1, $zero, L_80054110
    if (ctx->r9 != 0) {
        // 0x800540FC: nop
    
            goto L_80054110;
    }
    // 0x800540FC: nop

    // 0x80054100: lbu         $t2, 0x2($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X2);
    // 0x80054104: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80054108: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8005410C: sb          $t3, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r11;
L_80054110:
    // 0x80054110: lw          $t4, 0x8C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X8C);
    // 0x80054114: nop

    // 0x80054118: andi        $t5, $t4, 0x400
    ctx->r13 = ctx->r12 & 0X400;
    // 0x8005411C: beq         $t5, $zero, L_80054144
    if (ctx->r13 == 0) {
        // 0x80054120: nop
    
            goto L_80054144;
    }
    // 0x80054120: nop

    // 0x80054124: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x80054128: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005412C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80054130: sh          $t6, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r14;
    // 0x80054134: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80054138: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8005413C: jal         0x8008A5C8
    // 0x80054140: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    Audio2_Play_SFX(rdram, ctx);
        goto after_2;
    // 0x80054140: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_2:
L_80054144:
    // 0x80054144: lw          $t7, 0x88($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X88);
    // 0x80054148: nop

    // 0x8005414C: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x80054150: bne         $t8, $zero, L_80054164
    if (ctx->r24 != 0) {
        // 0x80054154: nop
    
            goto L_80054164;
    }
    // 0x80054154: nop

    // 0x80054158: lh          $t9, 0x8($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X8);
    // 0x8005415C: nop

    // 0x80054160: sh          $t9, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r25;
L_80054164:
    // 0x80054164: lw          $t0, 0x8C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8C);
    // 0x80054168: nop

    // 0x8005416C: andi        $t1, $t0, 0x800
    ctx->r9 = ctx->r8 & 0X800;
    // 0x80054170: beq         $t1, $zero, L_80054198
    if (ctx->r9 == 0) {
        // 0x80054174: nop
    
            goto L_80054198;
    }
    // 0x80054174: nop

    // 0x80054178: jal         0x800676AC
    // 0x8005417C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    CurrentPiece_HardDrop(rdram, ctx);
        goto after_3;
    // 0x8005417C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80054180: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80054184: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80054188: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x8005418C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80054190: jal         0x8008A5C8
    // 0x80054194: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    Audio2_Play_SFX(rdram, ctx);
        goto after_4;
    // 0x80054194: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_4:
L_80054198:
    // 0x80054198: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8005419C: lbu         $t2, -0x10E0($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X10E0);
    // 0x800541A0: nop

    // 0x800541A4: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800541A8: bne         $at, $zero, L_80054204
    if (ctx->r1 != 0) {
        // 0x800541AC: nop
    
            goto L_80054204;
    }
    // 0x800541AC: nop

    // 0x800541B0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800541B4: lw          $t3, -0x390($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X390);
    // 0x800541B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800541BC: lbu         $t4, 0x5($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X5);
    // 0x800541C0: nop

    // 0x800541C4: bne         $t4, $at, L_80054204
    if (ctx->r12 != ctx->r1) {
        // 0x800541C8: nop
    
            goto L_80054204;
    }
    // 0x800541C8: nop

    // 0x800541CC: lw          $t5, 0x8C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8C);
    // 0x800541D0: nop

    // 0x800541D4: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x800541D8: beq         $t6, $zero, L_800541E8
    if (ctx->r14 == 0) {
        // 0x800541DC: nop
    
            goto L_800541E8;
    }
    // 0x800541DC: nop

    // 0x800541E0: jal         0x80072508
    // 0x800541E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Landfill_ShrinkRowToTopFilled(rdram, ctx);
        goto after_5;
    // 0x800541E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
L_800541E8:
    // 0x800541E8: lw          $t7, 0x8C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8C);
    // 0x800541EC: nop

    // 0x800541F0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800541F4: beq         $t8, $zero, L_80054204
    if (ctx->r24 == 0) {
        // 0x800541F8: nop
    
            goto L_80054204;
    }
    // 0x800541F8: nop

    // 0x800541FC: jal         0x8007257C
    // 0x80054200: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Landfill_GrowRowToNextFilled(rdram, ctx);
        goto after_6;
    // 0x80054200: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
L_80054204:
    // 0x80054204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80054208: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005420C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80054210: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80054214: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80054218: jr          $ra
    // 0x8005421C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005421C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Tetris_FUN_80054220_fourliner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054220: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80054224: bne         $a1, $zero, L_80054234
    if (ctx->r5 != 0) {
        // 0x80054228: sb          $a1, 0x3($a0)
        MEM_B(0X3, ctx->r4) = ctx->r5;
            goto L_80054234;
    }
    // 0x80054228: sb          $a1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r5;
    // 0x8005422C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80054230: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
L_80054234:
    // 0x80054234: jr          $ra
    // 0x80054238: nop

    return;
    // 0x80054238: nop

;}

RECOMP_FUNC void Tetris_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005423C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80054240: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80054244: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80054248: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005424C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80054250: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x80054254: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80054258: nop

    // 0x8005425C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80054260: nop

    // 0x80054264: bne         $t8, $zero, L_8005427C
    if (ctx->r24 != 0) {
        // 0x80054268: nop
    
            goto L_8005427C;
    }
    // 0x80054268: nop

    // 0x8005426C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80054270: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x80054274: b           L_8005446C
    // 0x80054278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005446C;
    // 0x80054278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005427C:
    // 0x8005427C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80054280: nop

    // 0x80054284: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x80054288: nop

    // 0x8005428C: beq         $t1, $zero, L_800542B0
    if (ctx->r9 == 0) {
        // 0x80054290: nop
    
            goto L_800542B0;
    }
    // 0x80054290: nop

    // 0x80054294: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80054298: lbu         $t2, -0x118($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X118);
    // 0x8005429C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800542A0: beq         $t2, $at, L_800542B0
    if (ctx->r10 == ctx->r1) {
        // 0x800542A4: nop
    
            goto L_800542B0;
    }
    // 0x800542A4: nop

    // 0x800542A8: jal         0x80053F50
    // 0x800542AC: nop

    Tetris_CheckButtons(rdram, ctx);
        goto after_0;
    // 0x800542AC: nop

    after_0:
L_800542B0:
    // 0x800542B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800542B4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800542B8: lw          $a1, 0x9F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X9F4);
    // 0x800542BC: jal         0x80053C70
    // 0x800542C0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    FrameAct_ScheduleEvents(rdram, ctx);
        goto after_1;
    // 0x800542C0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x800542C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800542C8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800542CC: addiu       $a1, $a1, -0x3150
    ctx->r5 = ADD32(ctx->r5, -0X3150);
    // 0x800542D0: jal         0x8006CF08
    // 0x800542D4: addiu       $a0, $a0, -0x3160
    ctx->r4 = ADD32(ctx->r4, -0X3160);
    debug_print2(rdram, ctx);
        goto after_2;
    // 0x800542D4: addiu       $a0, $a0, -0x3160
    ctx->r4 = ADD32(ctx->r4, -0X3160);
    after_2:
    // 0x800542D8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800542DC: lw          $t3, -0xDE0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XDE0);
    // 0x800542E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800542E4: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x800542E8: nop

    // 0x800542EC: bne         $t4, $at, L_80054300
    if (ctx->r12 != ctx->r1) {
        // 0x800542F0: nop
    
            goto L_80054300;
    }
    // 0x800542F0: nop

    // 0x800542F4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800542F8: nop

    // 0x800542FC: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
L_80054300:
    // 0x80054300: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80054304: nop

    // 0x80054308: lbu         $t8, 0x2($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X2);
    // 0x8005430C: nop

    // 0x80054310: beq         $t8, $zero, L_8005441C
    if (ctx->r24 == 0) {
        // 0x80054314: nop
    
            goto L_8005441C;
    }
    // 0x80054314: nop

    // 0x80054318: lbu         $t9, 0x3($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X3);
    // 0x8005431C: nop

    // 0x80054320: bne         $t9, $zero, L_8005441C
    if (ctx->r25 != 0) {
        // 0x80054324: nop
    
            goto L_8005441C;
    }
    // 0x80054324: nop

    // 0x80054328: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8005432C: lw          $a1, 0x9F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X9F4);
    // 0x80054330: jal         0x80066160
    // 0x80054334: addiu       $a0, $t6, 0x51F0
    ctx->r4 = ADD32(ctx->r14, 0X51F0);
    PieceHold_Update(rdram, ctx);
        goto after_3;
    // 0x80054334: addiu       $a0, $t6, 0x51F0
    ctx->r4 = ADD32(ctx->r14, 0X51F0);
    after_3:
    // 0x80054338: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005433C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80054340: addiu       $a1, $a1, -0x3128
    ctx->r5 = ADD32(ctx->r5, -0X3128);
    // 0x80054344: jal         0x8006CF08
    // 0x80054348: addiu       $a0, $a0, -0x3138
    ctx->r4 = ADD32(ctx->r4, -0X3138);
    debug_print2(rdram, ctx);
        goto after_4;
    // 0x80054348: addiu       $a0, $a0, -0x3138
    ctx->r4 = ADD32(ctx->r4, -0X3138);
    after_4:
    // 0x8005434C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80054350: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80054354: lw          $a1, 0x9F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X9F4);
    // 0x80054358: jal         0x8006D1B0
    // 0x8005435C: addiu       $a0, $a0, 0x830
    ctx->r4 = ADD32(ctx->r4, 0X830);
    Board_Update(rdram, ctx);
        goto after_5;
    // 0x8005435C: addiu       $a0, $a0, 0x830
    ctx->r4 = ADD32(ctx->r4, 0X830);
    after_5:
    // 0x80054360: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80054364: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80054368: addiu       $a1, $a1, -0x3104
    ctx->r5 = ADD32(ctx->r5, -0X3104);
    // 0x8005436C: jal         0x8006CF08
    // 0x80054370: addiu       $a0, $a0, -0x3114
    ctx->r4 = ADD32(ctx->r4, -0X3114);
    debug_print2(rdram, ctx);
        goto after_6;
    // 0x80054370: addiu       $a0, $a0, -0x3114
    ctx->r4 = ADD32(ctx->r4, -0X3114);
    after_6:
    // 0x80054374: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80054378: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8005437C: lw          $a1, 0x9F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X9F4);
    // 0x80054380: jal         0x800529BC
    // 0x80054384: addiu       $a0, $a0, 0x6808
    ctx->r4 = ADD32(ctx->r4, 0X6808);
    GameStats_Update(rdram, ctx);
        goto after_7;
    // 0x80054384: addiu       $a0, $a0, 0x6808
    ctx->r4 = ADD32(ctx->r4, 0X6808);
    after_7:
    // 0x80054388: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005438C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80054390: addiu       $a1, $a1, -0x30E4
    ctx->r5 = ADD32(ctx->r5, -0X30E4);
    // 0x80054394: jal         0x8006CF08
    // 0x80054398: addiu       $a0, $a0, -0x30F4
    ctx->r4 = ADD32(ctx->r4, -0X30F4);
    debug_print2(rdram, ctx);
        goto after_8;
    // 0x80054398: addiu       $a0, $a0, -0x30F4
    ctx->r4 = ADD32(ctx->r4, -0X30F4);
    after_8:
    // 0x8005439C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800543A0: lw          $s0, 0x9F4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X9F4);
    // 0x800543A4: nop

    // 0x800543A8: blez        $s0, L_800543F4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800543AC: nop
    
            goto L_800543F4;
    }
    // 0x800543AC: nop

L_800543B0:
    // 0x800543B0: jal         0x8006EFEC
    // 0x800543B4: nop

    FallingCubes_Update(rdram, ctx);
        goto after_9;
    // 0x800543B4: nop

    after_9:
    // 0x800543B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800543BC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800543C0: addiu       $a1, $a1, -0x30C0
    ctx->r5 = ADD32(ctx->r5, -0X30C0);
    // 0x800543C4: jal         0x8006CF08
    // 0x800543C8: addiu       $a0, $a0, -0x30D0
    ctx->r4 = ADD32(ctx->r4, -0X30D0);
    debug_print2(rdram, ctx);
        goto after_10;
    // 0x800543C8: addiu       $a0, $a0, -0x30D0
    ctx->r4 = ADD32(ctx->r4, -0X30D0);
    after_10:
    // 0x800543CC: jal         0x8006EC4C
    // 0x800543D0: nop

    MobileCubes_Update(rdram, ctx);
        goto after_11;
    // 0x800543D0: nop

    after_11:
    // 0x800543D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800543D8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800543DC: addiu       $a1, $a1, -0x309C
    ctx->r5 = ADD32(ctx->r5, -0X309C);
    // 0x800543E0: jal         0x8006CF08
    // 0x800543E4: addiu       $a0, $a0, -0x30AC
    ctx->r4 = ADD32(ctx->r4, -0X30AC);
    debug_print2(rdram, ctx);
        goto after_12;
    // 0x800543E4: addiu       $a0, $a0, -0x30AC
    ctx->r4 = ADD32(ctx->r4, -0X30AC);
    after_12:
    // 0x800543E8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800543EC: bgtz        $s0, L_800543B0
    if (SIGNED(ctx->r16) > 0) {
        // 0x800543F0: nop
    
            goto L_800543B0;
    }
    // 0x800543F0: nop

L_800543F4:
    // 0x800543F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800543F8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800543FC: lw          $a1, 0x9F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X9F4);
    // 0x80054400: jal         0x8006ADEC
    // 0x80054404: addiu       $a0, $a0, 0x44C
    ctx->r4 = ADD32(ctx->r4, 0X44C);
    Multisquares_UpdateGlows(rdram, ctx);
        goto after_13;
    // 0x80054404: addiu       $a0, $a0, 0x44C
    ctx->r4 = ADD32(ctx->r4, 0X44C);
    after_13:
    // 0x80054408: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005440C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80054410: addiu       $a1, $a1, -0x3078
    ctx->r5 = ADD32(ctx->r5, -0X3078);
    // 0x80054414: jal         0x8006CF08
    // 0x80054418: addiu       $a0, $a0, -0x3088
    ctx->r4 = ADD32(ctx->r4, -0X3088);
    debug_print2(rdram, ctx);
        goto after_14;
    // 0x80054418: addiu       $a0, $a0, -0x3088
    ctx->r4 = ADD32(ctx->r4, -0X3088);
    after_14:
L_8005441C:
    // 0x8005441C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80054420: nop

    // 0x80054424: lbu         $t0, 0x3($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X3);
    // 0x80054428: nop

    // 0x8005442C: beq         $t0, $zero, L_8005443C
    if (ctx->r8 == 0) {
        // 0x80054430: nop
    
            goto L_8005443C;
    }
    // 0x80054430: nop

    // 0x80054434: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80054438: sb          $t1, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r9;
L_8005443C:
    // 0x8005443C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80054440: nop

    // 0x80054444: lbu         $t3, 0xB($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XB);
    // 0x80054448: nop

    // 0x8005444C: beq         $t3, $zero, L_8005445C
    if (ctx->r11 == 0) {
        // 0x80054450: nop
    
            goto L_8005445C;
    }
    // 0x80054450: nop

    // 0x80054454: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80054458: sb          $t4, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r12;
L_8005445C:
    // 0x8005445C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80054460: nop

    // 0x80054464: lbu         $v0, 0x1($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X1);
    // 0x80054468: nop

L_8005446C:
    // 0x8005446C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80054470: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80054474: jr          $ra
    // 0x80054478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80054478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Tetris_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005447C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80054484: jal         0x8005FC78
    // 0x80054488: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    GameCamera_Render(rdram, ctx);
        goto after_0;
    // 0x80054488: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005448C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80054490: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80054494: addiu       $a1, $a1, -0x3054
    ctx->r5 = ADD32(ctx->r5, -0X3054);
    // 0x80054498: jal         0x8006CF08
    // 0x8005449C: addiu       $a0, $a0, -0x305C
    ctx->r4 = ADD32(ctx->r4, -0X305C);
    debug_print2(rdram, ctx);
        goto after_1;
    // 0x8005449C: addiu       $a0, $a0, -0x305C
    ctx->r4 = ADD32(ctx->r4, -0X305C);
    after_1:
    // 0x800544A0: jal         0x8006ECC0
    // 0x800544A4: nop

    MobileCubes_Render(rdram, ctx);
        goto after_2;
    // 0x800544A4: nop

    after_2:
    // 0x800544A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800544AC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800544B0: addiu       $a1, $a1, -0x3038
    ctx->r5 = ADD32(ctx->r5, -0X3038);
    // 0x800544B4: jal         0x8006CF08
    // 0x800544B8: addiu       $a0, $a0, -0x3040
    ctx->r4 = ADD32(ctx->r4, -0X3040);
    debug_print2(rdram, ctx);
        goto after_3;
    // 0x800544B8: addiu       $a0, $a0, -0x3040
    ctx->r4 = ADD32(ctx->r4, -0X3040);
    after_3:
    // 0x800544BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800544C0: jal         0x80067D50
    // 0x800544C4: addiu       $a0, $a0, 0x830
    ctx->r4 = ADD32(ctx->r4, 0X830);
    CurrentPiece_Render(rdram, ctx);
        goto after_4;
    // 0x800544C4: addiu       $a0, $a0, 0x830
    ctx->r4 = ADD32(ctx->r4, 0X830);
    after_4:
    // 0x800544C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800544CC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800544D0: addiu       $a1, $a1, -0x301C
    ctx->r5 = ADD32(ctx->r5, -0X301C);
    // 0x800544D4: jal         0x8006CF08
    // 0x800544D8: addiu       $a0, $a0, -0x3024
    ctx->r4 = ADD32(ctx->r4, -0X3024);
    debug_print2(rdram, ctx);
        goto after_5;
    // 0x800544D8: addiu       $a0, $a0, -0x3024
    ctx->r4 = ADD32(ctx->r4, -0X3024);
    after_5:
    // 0x800544DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800544E0: jal         0x800661A0
    // 0x800544E4: addiu       $a0, $a0, 0x51F0
    ctx->r4 = ADD32(ctx->r4, 0X51F0);
    PieceHold_Render(rdram, ctx);
        goto after_6;
    // 0x800544E4: addiu       $a0, $a0, 0x51F0
    ctx->r4 = ADD32(ctx->r4, 0X51F0);
    after_6:
    // 0x800544E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800544EC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800544F0: addiu       $a1, $a1, -0x3000
    ctx->r5 = ADD32(ctx->r5, -0X3000);
    // 0x800544F4: jal         0x8006CF08
    // 0x800544F8: addiu       $a0, $a0, -0x3008
    ctx->r4 = ADD32(ctx->r4, -0X3008);
    debug_print2(rdram, ctx);
        goto after_7;
    // 0x800544F8: addiu       $a0, $a0, -0x3008
    ctx->r4 = ADD32(ctx->r4, -0X3008);
    after_7:
    // 0x800544FC: jal         0x80068940
    // 0x80054500: nop

    NextPieces_Render(rdram, ctx);
        goto after_8;
    // 0x80054500: nop

    after_8:
    // 0x80054504: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80054508: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005450C: addiu       $a1, $a1, -0x2FE4
    ctx->r5 = ADD32(ctx->r5, -0X2FE4);
    // 0x80054510: jal         0x8006CF08
    // 0x80054514: addiu       $a0, $a0, -0x2FEC
    ctx->r4 = ADD32(ctx->r4, -0X2FEC);
    debug_print2(rdram, ctx);
        goto after_9;
    // 0x80054514: addiu       $a0, $a0, -0x2FEC
    ctx->r4 = ADD32(ctx->r4, -0X2FEC);
    after_9:
    // 0x80054518: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005451C: jal         0x80052A00
    // 0x80054520: addiu       $a0, $a0, 0x6808
    ctx->r4 = ADD32(ctx->r4, 0X6808);
    GameStats_Render(rdram, ctx);
        goto after_10;
    // 0x80054520: addiu       $a0, $a0, 0x6808
    ctx->r4 = ADD32(ctx->r4, 0X6808);
    after_10:
    // 0x80054524: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80054528: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005452C: addiu       $a1, $a1, -0x2FC8
    ctx->r5 = ADD32(ctx->r5, -0X2FC8);
    // 0x80054530: jal         0x8006CF08
    // 0x80054534: addiu       $a0, $a0, -0x2FD0
    ctx->r4 = ADD32(ctx->r4, -0X2FD0);
    debug_print2(rdram, ctx);
        goto after_11;
    // 0x80054534: addiu       $a0, $a0, -0x2FD0
    ctx->r4 = ADD32(ctx->r4, -0X2FD0);
    after_11:
    // 0x80054538: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005453C: jal         0x8006AE58
    // 0x80054540: addiu       $a0, $a0, 0x44C
    ctx->r4 = ADD32(ctx->r4, 0X44C);
    Multisquares_RenderGlows(rdram, ctx);
        goto after_12;
    // 0x80054540: addiu       $a0, $a0, 0x44C
    ctx->r4 = ADD32(ctx->r4, 0X44C);
    after_12:
    // 0x80054544: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80054548: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005454C: addiu       $a1, $a1, -0x2FAC
    ctx->r5 = ADD32(ctx->r5, -0X2FAC);
    // 0x80054550: jal         0x8006CF08
    // 0x80054554: addiu       $a0, $a0, -0x2FB4
    ctx->r4 = ADD32(ctx->r4, -0X2FB4);
    debug_print2(rdram, ctx);
        goto after_13;
    // 0x80054554: addiu       $a0, $a0, -0x2FB4
    ctx->r4 = ADD32(ctx->r4, -0X2FB4);
    after_13:
    // 0x80054558: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005455C: jal         0x80053DC0
    // 0x80054560: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    FrameAct_Render(rdram, ctx);
        goto after_14;
    // 0x80054560: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_14:
    // 0x80054564: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80054568: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005456C: addiu       $a1, $a1, -0x2F88
    ctx->r5 = ADD32(ctx->r5, -0X2F88);
    // 0x80054570: jal         0x8006CF08
    // 0x80054574: addiu       $a0, $a0, -0x2F90
    ctx->r4 = ADD32(ctx->r4, -0X2F90);
    debug_print2(rdram, ctx);
        goto after_15;
    // 0x80054574: addiu       $a0, $a0, -0x2F90
    ctx->r4 = ADD32(ctx->r4, -0X2F90);
    after_15:
    // 0x80054578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005457C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80054580: jr          $ra
    // 0x80054584: nop

    return;
    // 0x80054584: nop

;}

RECOMP_FUNC void Tetris_SetMarathonHandicap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054588: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005458C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80054590: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80054594: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80054598: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8005459C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800545A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800545A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800545A8: lbu         $t7, 0x9($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X9);
    // 0x800545AC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800545B0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800545B4: lbu         $t8, -0x100($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X100);
    // 0x800545B8: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x800545BC: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800545C0: subu        $s0, $t9, $t8
    ctx->r16 = SUB32(ctx->r25, ctx->r24);
    // 0x800545C4: beq         $s0, $at, L_80054634
    if (ctx->r16 == ctx->r1) {
        // 0x800545C8: nop
    
            goto L_80054634;
    }
    // 0x800545C8: nop

    // 0x800545CC: jal         0x80069F10
    // 0x800545D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LineScan_SetScanLimit(rdram, ctx);
        goto after_0;
    // 0x800545D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800545D4: addiu       $s1, $s0, 0x1
    ctx->r17 = ADD32(ctx->r16, 0X1);
    // 0x800545D8: slti        $at, $s1, 0x14
    ctx->r1 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
    // 0x800545DC: beq         $at, $zero, L_80054624
    if (ctx->r1 == 0) {
        // 0x800545E0: nop
    
            goto L_80054624;
    }
    // 0x800545E0: nop

L_800545E4:
    // 0x800545E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800545E8: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x800545EC: beq         $at, $zero, L_80054614
    if (ctx->r1 == 0) {
        // 0x800545F0: nop
    
            goto L_80054614;
    }
    // 0x800545F0: nop

L_800545F4:
    // 0x800545F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800545F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800545FC: jal         0x8006DE40
    // 0x80054600: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    BoardP_SetCubeAt(rdram, ctx);
        goto after_1;
    // 0x80054600: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x80054604: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80054608: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x8005460C: bne         $at, $zero, L_800545F4
    if (ctx->r1 != 0) {
        // 0x80054610: nop
    
            goto L_800545F4;
    }
    // 0x80054610: nop

L_80054614:
    // 0x80054614: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80054618: slti        $at, $s1, 0x14
    ctx->r1 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
    // 0x8005461C: bne         $at, $zero, L_800545E4
    if (ctx->r1 != 0) {
        // 0x80054620: nop
    
            goto L_800545E4;
    }
    // 0x80054620: nop

L_80054624:
    // 0x80054624: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80054628: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005462C: jal         0x80053F40
    // 0x80054630: addiu       $a0, $a0, 0x6840
    ctx->r4 = ADD32(ctx->r4, 0X6840);
    FrameAct_SetTimer(rdram, ctx);
        goto after_2;
    // 0x80054630: addiu       $a0, $a0, 0x6840
    ctx->r4 = ADD32(ctx->r4, 0X6840);
    after_2:
L_80054634:
    // 0x80054634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80054638: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005463C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80054640: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80054644: jr          $ra
    // 0x80054648: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80054648: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Tetris_SetSprintHandicap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005464C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80054650: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80054654: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80054658: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005465C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80054660: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80054664: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80054668: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005466C: lbu         $t7, 0x9($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X9);
    // 0x80054670: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80054674: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80054678: lbu         $t8, -0x100($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X100);
    // 0x8005467C: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x80054680: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80054684: subu        $s0, $t9, $t8
    ctx->r16 = SUB32(ctx->r25, ctx->r24);
    // 0x80054688: beq         $s0, $at, L_800546F8
    if (ctx->r16 == ctx->r1) {
        // 0x8005468C: nop
    
            goto L_800546F8;
    }
    // 0x8005468C: nop

    // 0x80054690: jal         0x80069F10
    // 0x80054694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LineScan_SetScanLimit(rdram, ctx);
        goto after_0;
    // 0x80054694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80054698: addiu       $s1, $s0, 0x1
    ctx->r17 = ADD32(ctx->r16, 0X1);
    // 0x8005469C: slti        $at, $s1, 0x14
    ctx->r1 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
    // 0x800546A0: beq         $at, $zero, L_800546E8
    if (ctx->r1 == 0) {
        // 0x800546A4: nop
    
            goto L_800546E8;
    }
    // 0x800546A4: nop

L_800546A8:
    // 0x800546A8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800546AC: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x800546B0: beq         $at, $zero, L_800546D8
    if (ctx->r1 == 0) {
        // 0x800546B4: nop
    
            goto L_800546D8;
    }
    // 0x800546B4: nop

L_800546B8:
    // 0x800546B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800546BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800546C0: jal         0x8006DE40
    // 0x800546C4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    BoardP_SetCubeAt(rdram, ctx);
        goto after_1;
    // 0x800546C4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x800546C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800546CC: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x800546D0: bne         $at, $zero, L_800546B8
    if (ctx->r1 != 0) {
        // 0x800546D4: nop
    
            goto L_800546B8;
    }
    // 0x800546D4: nop

L_800546D8:
    // 0x800546D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800546DC: slti        $at, $s1, 0x14
    ctx->r1 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
    // 0x800546E0: bne         $at, $zero, L_800546A8
    if (ctx->r1 != 0) {
        // 0x800546E4: nop
    
            goto L_800546A8;
    }
    // 0x800546E4: nop

L_800546E8:
    // 0x800546E8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800546EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800546F0: jal         0x80053F40
    // 0x800546F4: addiu       $a0, $a0, 0x6840
    ctx->r4 = ADD32(ctx->r4, 0X6840);
    FrameAct_SetTimer(rdram, ctx);
        goto after_2;
    // 0x800546F4: addiu       $a0, $a0, 0x6840
    ctx->r4 = ADD32(ctx->r4, 0X6840);
    after_2:
L_800546F8:
    // 0x800546F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800546FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80054700: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80054704: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80054708: jr          $ra
    // 0x8005470C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005470C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Tetris_SetUltraHandicap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054710: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054714: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80054718: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005471C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80054720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80054724: lbu         $t7, 0x9($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X9);
    // 0x80054728: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8005472C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80054730: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80054734: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80054738: addiu       $t9, $t8, 0x96
    ctx->r25 = ADD32(ctx->r24, 0X96);
    // 0x8005473C: sw          $t9, 0x6834($t0)
    MEM_W(0X6834, ctx->r8) = ctx->r25;
    // 0x80054740: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80054744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80054748: jal         0x80053F40
    // 0x8005474C: addiu       $a0, $a0, 0x6840
    ctx->r4 = ADD32(ctx->r4, 0X6840);
    FrameAct_SetTimer(rdram, ctx);
        goto after_0;
    // 0x8005474C: addiu       $a0, $a0, 0x6840
    ctx->r4 = ADD32(ctx->r4, 0X6840);
    after_0:
    // 0x80054750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80054754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80054758: jr          $ra
    // 0x8005475C: nop

    return;
    // 0x8005475C: nop

;}

RECOMP_FUNC void Tetris_SetGameHandicap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054760: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80054764: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80054768: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8005476C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80054770: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80054774: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80054778: lbu         $s0, 0xA($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0XA);
    // 0x8005477C: nop

    // 0x80054780: beq         $s0, $zero, L_800547A0
    if (ctx->r16 == 0) {
        // 0x80054784: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800547A0;
    }
    // 0x80054784: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80054788: beq         $s0, $at, L_800547B8
    if (ctx->r16 == ctx->r1) {
        // 0x8005478C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800547B8;
    }
    // 0x8005478C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80054790: beq         $s0, $at, L_800547D0
    if (ctx->r16 == ctx->r1) {
        // 0x80054794: nop
    
            goto L_800547D0;
    }
    // 0x80054794: nop

    // 0x80054798: b           L_800547E0
    // 0x8005479C: nop

        goto L_800547E0;
    // 0x8005479C: nop

L_800547A0:
    // 0x800547A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800547A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800547A8: jal         0x80054588
    // 0x800547AC: nop

    Tetris_SetMarathonHandicap(rdram, ctx);
        goto after_0;
    // 0x800547AC: nop

    after_0:
    // 0x800547B0: b           L_800547E0
    // 0x800547B4: nop

        goto L_800547E0;
    // 0x800547B4: nop

L_800547B8:
    // 0x800547B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800547BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800547C0: jal         0x8005464C
    // 0x800547C4: nop

    Tetris_SetSprintHandicap(rdram, ctx);
        goto after_1;
    // 0x800547C4: nop

    after_1:
    // 0x800547C8: b           L_800547E0
    // 0x800547CC: nop

        goto L_800547E0;
    // 0x800547CC: nop

L_800547D0:
    // 0x800547D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800547D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800547D8: jal         0x80054710
    // 0x800547DC: nop

    Tetris_SetUltraHandicap(rdram, ctx);
        goto after_2;
    // 0x800547DC: nop

    after_2:
L_800547E0:
    // 0x800547E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800547E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800547E8: jr          $ra
    // 0x800547EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800547EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Tetris_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800547F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800547F4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800547F8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800547FC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80054800: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80054804: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80054808: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005480C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80054810: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80054814: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80054818: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005481C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80054820: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x80054824: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80054828: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005482C: sb          $t0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r8;
    // 0x80054830: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80054834: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80054838: sb          $zero, 0x3($t2)
    MEM_B(0X3, ctx->r10) = 0;
    // 0x8005483C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80054840: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80054844: sb          $t3, 0x4($t4)
    MEM_B(0X4, ctx->r12) = ctx->r11;
    // 0x80054848: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005484C: jal         0x800713F0
    // 0x80054850: addiu       $a0, $a0, 0x6690
    ctx->r4 = ADD32(ctx->r4, 0X6690);
    Bag63_Init(rdram, ctx);
        goto after_0;
    // 0x80054850: addiu       $a0, $a0, 0x6690
    ctx->r4 = ADD32(ctx->r4, 0X6690);
    after_0:
    // 0x80054854: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80054858: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005485C: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    // 0x80054860: jal         0x80070D40
    // 0x80054864: addiu       $a0, $a0, 0x7D0
    ctx->r4 = ADD32(ctx->r4, 0X7D0);
    Minos_Init(rdram, ctx);
        goto after_1;
    // 0x80054864: addiu       $a0, $a0, 0x7D0
    ctx->r4 = ADD32(ctx->r4, 0X7D0);
    after_1:
    // 0x80054868: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8005486C: nop

    // 0x80054870: lbu         $a0, 0x8($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X8);
    // 0x80054874: jal         0x80060598
    // 0x80054878: nop

    PFGFX_Playfield_Init(rdram, ctx);
        goto after_2;
    // 0x80054878: nop

    after_2:
    // 0x8005487C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80054880: nop

    // 0x80054884: addiu       $a0, $t7, 0x830
    ctx->r4 = ADD32(ctx->r15, 0X830);
    // 0x80054888: addiu       $a1, $t7, 0x6690
    ctx->r5 = ADD32(ctx->r15, 0X6690);
    // 0x8005488C: jal         0x8006D200
    // 0x80054890: addiu       $a2, $t7, 0x7D0
    ctx->r6 = ADD32(ctx->r15, 0X7D0);
    Board_Init(rdram, ctx);
        goto after_3;
    // 0x80054890: addiu       $a2, $t7, 0x7D0
    ctx->r6 = ADD32(ctx->r15, 0X7D0);
    after_3:
    // 0x80054894: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80054898: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005489C: lbu         $t9, 0x8($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X8);
    // 0x800548A0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800548A4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800548A8: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x800548AC: addiu       $a0, $a0, 0x51F0
    ctx->r4 = ADD32(ctx->r4, 0X51F0);
    // 0x800548B0: jal         0x80066518
    // 0x800548B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    PieceHold_Init(rdram, ctx);
        goto after_4;
    // 0x800548B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_4:
    // 0x800548B8: jal         0x8006ADA4
    // 0x800548BC: nop

    Multisquare_Init(rdram, ctx);
        goto after_5;
    // 0x800548BC: nop

    after_5:
    // 0x800548C0: jal         0x80069F68
    // 0x800548C4: nop

    LineScan_Init(rdram, ctx);
        goto after_6;
    // 0x800548C4: nop

    after_6:
    // 0x800548C8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800548CC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800548D0: jal         0x80054760
    // 0x800548D4: nop

    Tetris_SetGameHandicap(rdram, ctx);
        goto after_7;
    // 0x800548D4: nop

    after_7:
    // 0x800548D8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800548DC: jal         0x80052A28
    // 0x800548E0: addiu       $a0, $a0, 0x6808
    ctx->r4 = ADD32(ctx->r4, 0X6808);
    GameStats_Init(rdram, ctx);
        goto after_8;
    // 0x800548E0: addiu       $a0, $a0, 0x6808
    ctx->r4 = ADD32(ctx->r4, 0X6808);
    after_8:
    // 0x800548E4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800548E8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800548EC: jal         0x8005FE68
    // 0x800548F0: addiu       $a1, $a1, 0x6750
    ctx->r5 = ADD32(ctx->r5, 0X6750);
    PFGFX_Init(rdram, ctx);
        goto after_9;
    // 0x800548F0: addiu       $a1, $a1, 0x6750
    ctx->r5 = ADD32(ctx->r5, 0X6750);
    after_9:
    // 0x800548F4: lwl         $t0, 0x34($sp)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r29, 0X34);
    // 0x800548F8: lwr         $t0, 0x37($sp)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r29, 0X37);
    // 0x800548FC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80054900: lw          $t1, -0x3F0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3F0);
    // 0x80054904: swl         $t0, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r8);
    // 0x80054908: swr         $t0, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r8);
    // 0x8005490C: lhu         $a2, 0x2($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X2);
    // 0x80054910: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80054914: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80054918: sra         $t2, $a2, 8
    ctx->r10 = S32(SIGNED(ctx->r6) >> 8);
    // 0x8005491C: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x80054920: jal         0x8006D2C0
    // 0x80054924: addiu       $a0, $a0, 0x6838
    ctx->r4 = ADD32(ctx->r4, 0X6838);
    BoardInfo_Init(rdram, ctx);
        goto after_10;
    // 0x80054924: addiu       $a0, $a0, 0x6838
    ctx->r4 = ADD32(ctx->r4, 0X6838);
    after_10:
    // 0x80054928: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8005492C: nop

    // 0x80054930: addiu       $a0, $t3, 0x8
    ctx->r4 = ADD32(ctx->r11, 0X8);
    // 0x80054934: addiu       $a1, $t3, 0x51F0
    ctx->r5 = ADD32(ctx->r11, 0X51F0);
    // 0x80054938: addiu       $a2, $t3, 0x6840
    ctx->r6 = ADD32(ctx->r11, 0X6840);
    // 0x8005493C: jal         0x80053DF8
    // 0x80054940: addiu       $a3, $t3, 0x6838
    ctx->r7 = ADD32(ctx->r11, 0X6838);
    FrameAct_Init(rdram, ctx);
        goto after_11;
    // 0x80054940: addiu       $a3, $t3, 0x6838
    ctx->r7 = ADD32(ctx->r11, 0X6838);
    after_11:
    // 0x80054944: jal         0x8007283C
    // 0x80054948: nop

    Landfill_AppendRow(rdram, ctx);
        goto after_12;
    // 0x80054948: nop

    after_12:
    // 0x8005494C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80054950: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054954: sw          $v0, 0x674C($t4)
    MEM_W(0X674C, ctx->r12) = ctx->r2;
    // 0x80054958: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8005495C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80054960: lw          $t6, 0x674C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X674C);
    // 0x80054964: nop

    // 0x80054968: sw          $t6, -0x380($at)
    MEM_W(-0X380, ctx->r1) = ctx->r14;
    // 0x8005496C: lw          $a0, 0x674C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X674C);
    // 0x80054970: jal         0x80072D38
    // 0x80054974: nop

    Garbage_Init(rdram, ctx);
        goto after_13;
    // 0x80054974: nop

    after_13:
    // 0x80054978: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8005497C: lw          $t7, -0x390($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X390);
    // 0x80054980: nop

    // 0x80054984: lbu         $s2, 0x5($t7)
    ctx->r18 = MEM_BU(ctx->r15, 0X5);
    // 0x80054988: nop

    // 0x8005498C: beq         $s2, $zero, L_800549AC
    if (ctx->r18 == 0) {
        // 0x80054990: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800549AC;
    }
    // 0x80054990: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80054994: beq         $s2, $at, L_80054A80
    if (ctx->r18 == ctx->r1) {
        // 0x80054998: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80054A80;
    }
    // 0x80054998: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005499C: beq         $s2, $at, L_800549C4
    if (ctx->r18 == ctx->r1) {
        // 0x800549A0: nop
    
            goto L_800549C4;
    }
    // 0x800549A0: nop

    // 0x800549A4: b           L_80054AB4
    // 0x800549A8: nop

        goto L_80054AB4;
    // 0x800549A8: nop

L_800549AC:
    // 0x800549AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800549B0: lw          $a0, -0x380($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X380);
    // 0x800549B4: jal         0x80072E2C
    // 0x800549B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Garbage_SetActive(rdram, ctx);
        goto after_14;
    // 0x800549B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x800549BC: b           L_80054ACC
    // 0x800549C0: nop

        goto L_80054ACC;
    // 0x800549C0: nop

L_800549C4:
    // 0x800549C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800549C8: lw          $a0, -0x380($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X380);
    // 0x800549CC: jal         0x80072E2C
    // 0x800549D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Garbage_SetActive(rdram, ctx);
        goto after_15;
    // 0x800549D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x800549D4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800549D8: lbu         $s0, -0x10DF($s0)
    ctx->r16 = MEM_BU(ctx->r16, -0X10DF);
    // 0x800549DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800549E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800549E4: jal         0x800723A0
    // 0x800549E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Landfill_SetCell(rdram, ctx);
        goto after_16;
    // 0x800549E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x800549EC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800549F0: lbu         $t9, -0x10E0($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X10E0);
    // 0x800549F4: addiu       $t8, $s0, 0x1
    ctx->r24 = ADD32(ctx->r16, 0X1);
    // 0x800549F8: div         $zero, $t8, $t9
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r25)));
    // 0x800549FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80054A00: bne         $t9, $zero, L_80054A0C
    if (ctx->r25 != 0) {
        // 0x80054A04: nop
    
            goto L_80054A0C;
    }
    // 0x80054A04: nop

    // 0x80054A08: break       7
    do_break(2147830280);
L_80054A0C:
    // 0x80054A0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054A10: bne         $t9, $at, L_80054A24
    if (ctx->r25 != ctx->r1) {
        // 0x80054A14: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80054A24;
    }
    // 0x80054A14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80054A18: bne         $t8, $at, L_80054A24
    if (ctx->r24 != ctx->r1) {
        // 0x80054A1C: nop
    
            goto L_80054A24;
    }
    // 0x80054A1C: nop

    // 0x80054A20: break       6
    do_break(2147830304);
L_80054A24:
    // 0x80054A24: mfhi        $a1
    ctx->r5 = hi;
    // 0x80054A28: jal         0x8007240C
    // 0x80054A2C: nop

    Landfill_SetRowLength(rdram, ctx);
        goto after_17;
    // 0x80054A2C: nop

    after_17:
    // 0x80054A30: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80054A34: lbu         $t0, -0x10E0($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X10E0);
    // 0x80054A38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80054A3C: bne         $t0, $at, L_80054ACC
    if (ctx->r8 != ctx->r1) {
        // 0x80054A40: nop
    
            goto L_80054ACC;
    }
    // 0x80054A40: nop

    // 0x80054A44: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80054A48: lbu         $t1, -0x10DF($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X10DF);
    // 0x80054A4C: nop

    // 0x80054A50: bne         $t1, $zero, L_80054A6C
    if (ctx->r9 != 0) {
        // 0x80054A54: nop
    
            goto L_80054A6C;
    }
    // 0x80054A54: nop

    // 0x80054A58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80054A5C: jal         0x8007240C
    // 0x80054A60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Landfill_SetRowLength(rdram, ctx);
        goto after_18;
    // 0x80054A60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80054A64: b           L_80054ACC
    // 0x80054A68: nop

        goto L_80054ACC;
    // 0x80054A68: nop

L_80054A6C:
    // 0x80054A6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80054A70: jal         0x8007240C
    // 0x80054A74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Landfill_SetRowLength(rdram, ctx);
        goto after_19;
    // 0x80054A74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80054A78: b           L_80054ACC
    // 0x80054A7C: nop

        goto L_80054ACC;
    // 0x80054A7C: nop

L_80054A80:
    // 0x80054A80: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80054A84: lw          $a0, -0x380($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X380);
    // 0x80054A88: jal         0x80072E2C
    // 0x80054A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Garbage_SetActive(rdram, ctx);
        goto after_20;
    // 0x80054A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x80054A90: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80054A94: lw          $t2, -0x390($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X390);
    // 0x80054A98: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80054A9C: lbu         $s1, 0x30($t2)
    ctx->r17 = MEM_BU(ctx->r10, 0X30);
    // 0x80054AA0: lbu         $a0, -0x10DF($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X10DF);
    // 0x80054AA4: jal         0x8007240C
    // 0x80054AA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    Landfill_SetRowLength(rdram, ctx);
        goto after_21;
    // 0x80054AA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_21:
    // 0x80054AAC: b           L_80054ACC
    // 0x80054AB0: nop

        goto L_80054ACC;
    // 0x80054AB0: nop

L_80054AB4:
    // 0x80054AB4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80054AB8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80054ABC: addiu       $a1, $a1, -0x2F6C
    ctx->r5 = ADD32(ctx->r5, -0X2F6C);
    // 0x80054AC0: addiu       $a0, $a0, -0x2F78
    ctx->r4 = ADD32(ctx->r4, -0X2F78);
    // 0x80054AC4: jal         0x8004A5A0
    // 0x80054AC8: addiu       $a2, $zero, 0x1F8
    ctx->r6 = ADD32(0, 0X1F8);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_22;
    // 0x80054AC8: addiu       $a2, $zero, 0x1F8
    ctx->r6 = ADD32(0, 0X1F8);
    after_22:
L_80054ACC:
    // 0x80054ACC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80054AD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80054AD4: jal         0x80053670
    // 0x80054AD8: sw          $zero, 0x6818($t3)
    MEM_W(0X6818, ctx->r11) = 0;
    FrameAct_SetState(rdram, ctx);
        goto after_23;
    // 0x80054AD8: sw          $zero, 0x6818($t3)
    MEM_W(0X6818, ctx->r11) = 0;
    after_23:
    // 0x80054ADC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80054AE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80054AE4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80054AE8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80054AEC: jr          $ra
    // 0x80054AF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80054AF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void Tetris_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054AF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054AF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80054AFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80054B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80054B04: jal         0x80053F48
    // 0x80054B08: addiu       $a0, $a0, 0x6840
    ctx->r4 = ADD32(ctx->r4, 0X6840);
    FrameAct_Deinit_doesnothing(rdram, ctx);
        goto after_0;
    // 0x80054B08: addiu       $a0, $a0, 0x6840
    ctx->r4 = ADD32(ctx->r4, 0X6840);
    after_0:
    // 0x80054B0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80054B10: jal         0x80053E70
    // 0x80054B14: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    FrameAct_Deinit(rdram, ctx);
        goto after_1;
    // 0x80054B14: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x80054B18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80054B1C: jal         0x800666A8
    // 0x80054B20: addiu       $a0, $a0, 0x51F0
    ctx->r4 = ADD32(ctx->r4, 0X51F0);
    PieceHold_Deinit(rdram, ctx);
        goto after_2;
    // 0x80054B20: addiu       $a0, $a0, 0x51F0
    ctx->r4 = ADD32(ctx->r4, 0X51F0);
    after_2:
    // 0x80054B24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80054B28: jal         0x8006D278
    // 0x80054B2C: addiu       $a0, $a0, 0x830
    ctx->r4 = ADD32(ctx->r4, 0X830);
    Board_Deinit(rdram, ctx);
        goto after_3;
    // 0x80054B2C: addiu       $a0, $a0, 0x830
    ctx->r4 = ADD32(ctx->r4, 0X830);
    after_3:
    // 0x80054B30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80054B34: jal         0x80070EC0
    // 0x80054B38: addiu       $a0, $a0, 0x7D0
    ctx->r4 = ADD32(ctx->r4, 0X7D0);
    Minos_Deinit_doesnothing(rdram, ctx);
        goto after_4;
    // 0x80054B38: addiu       $a0, $a0, 0x7D0
    ctx->r4 = ADD32(ctx->r4, 0X7D0);
    after_4:
    // 0x80054B3C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80054B40: nop

    // 0x80054B44: lw          $a0, 0x674C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X674C);
    // 0x80054B48: jal         0x80072E24
    // 0x80054B4C: nop

    Garbage_Deinit(rdram, ctx);
        goto after_5;
    // 0x80054B4C: nop

    after_5:
    // 0x80054B50: jal         0x8006ADE4
    // 0x80054B54: nop

    Multisquare_Deinit_doesnothing(rdram, ctx);
        goto after_6;
    // 0x80054B54: nop

    after_6:
    // 0x80054B58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80054B5C: jal         0x80071470
    // 0x80054B60: addiu       $a0, $a0, 0x6690
    ctx->r4 = ADD32(ctx->r4, 0X6690);
    Bag63_Deinit(rdram, ctx);
        goto after_7;
    // 0x80054B60: addiu       $a0, $a0, 0x6690
    ctx->r4 = ADD32(ctx->r4, 0X6690);
    after_7:
    // 0x80054B64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80054B68: jal         0x80052A90
    // 0x80054B6C: addiu       $a0, $a0, 0x6808
    ctx->r4 = ADD32(ctx->r4, 0X6808);
    GameStats_Deinit(rdram, ctx);
        goto after_8;
    // 0x80054B6C: addiu       $a0, $a0, 0x6808
    ctx->r4 = ADD32(ctx->r4, 0X6808);
    after_8:
    // 0x80054B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80054B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80054B78: jr          $ra
    // 0x80054B7C: nop

    return;
    // 0x80054B7C: nop

;}

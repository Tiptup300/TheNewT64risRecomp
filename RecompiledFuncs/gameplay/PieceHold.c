#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void PieceHold_80065710_twoliner_sets_to_0_and_0xff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065710: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80065714: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80065718: jr          $ra
    // 0x8006571C: sb          $t6, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r14;
    return;
    // 0x8006571C: sb          $t6, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r14;
;}

RECOMP_FUNC void PieceHold_80065720_fiveliner_two_traps(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065720: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x80065724: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80065728: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x8006572C: nop

    // 0x80065730: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80065734: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80065738: bne         $a1, $zero, L_80065744
    if (ctx->r5 != 0) {
        // 0x8006573C: nop
    
            goto L_80065744;
    }
    // 0x8006573C: nop

    // 0x80065740: break       7
    do_break(2147899200);
L_80065744:
    // 0x80065744: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80065748: bne         $a1, $at, L_8006575C
    if (ctx->r5 != ctx->r1) {
        // 0x8006574C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006575C;
    }
    // 0x8006574C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065750: bne         $t8, $at, L_8006575C
    if (ctx->r24 != ctx->r1) {
        // 0x80065754: nop
    
            goto L_8006575C;
    }
    // 0x80065754: nop

    // 0x80065758: break       6
    do_break(2147899224);
L_8006575C:
    // 0x8006575C: mflo        $t9
    ctx->r25 = lo;
    // 0x80065760: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
    // 0x80065764: jr          $ra
    // 0x80065768: nop

    return;
    // 0x80065768: nop

;}

RECOMP_FUNC void PieceHold_8006593c_nineliner_sets_struct_stuff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006593C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80065940: nop

    // 0x80065944: beq         $t6, $zero, L_800659B8
    if (ctx->r14 == 0) {
        // 0x80065948: nop
    
            goto L_800659B8;
    }
    // 0x80065948: nop

    // 0x8006594C: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x80065950: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80065954: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065958: lh          $t1, 0x4($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4);
    // 0x8006595C: mflo        $t9
    ctx->r25 = lo;
    // 0x80065960: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80065964: blez        $t1, L_80065994
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80065968: sh          $t0, 0x2($a0)
        MEM_H(0X2, ctx->r4) = ctx->r8;
            goto L_80065994;
    }
    // 0x80065968: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x8006596C: lh          $t2, 0x2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2);
    // 0x80065970: lh          $t3, 0x6($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X6);
    // 0x80065974: nop

    // 0x80065978: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8006597C: bne         $at, $zero, L_800659B8
    if (ctx->r1 != 0) {
        // 0x80065980: nop
    
            goto L_800659B8;
    }
    // 0x80065980: nop

    // 0x80065984: lh          $t4, 0x6($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X6);
    // 0x80065988: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x8006598C: jr          $ra
    // 0x80065990: sh          $t4, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r12;
    return;
    // 0x80065990: sh          $t4, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r12;
L_80065994:
    // 0x80065994: lh          $t5, 0x2($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2);
    // 0x80065998: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8006599C: nop

    // 0x800659A0: slt         $at, $t6, $t5
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800659A4: bne         $at, $zero, L_800659B8
    if (ctx->r1 != 0) {
        // 0x800659A8: nop
    
            goto L_800659B8;
    }
    // 0x800659A8: nop

    // 0x800659AC: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x800659B0: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x800659B4: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
L_800659B8:
    // 0x800659B8: jr          $ra
    // 0x800659BC: nop

    return;
    // 0x800659BC: nop

;}

RECOMP_FUNC void PieceHold_80065a0c_tenliner_adds_sets_struct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065A0C: lbu         $t6, 0x1A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1A);
    // 0x80065A10: nop

    // 0x80065A14: beq         $t6, $zero, L_80065AD4
    if (ctx->r14 == 0) {
        // 0x80065A18: nop
    
            goto L_80065AD4;
    }
    // 0x80065A18: nop

    // 0x80065A1C: lbu         $t7, 0x1A($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1A);
    // 0x80065A20: nop

    // 0x80065A24: sltu        $at, $t7, $a1
    ctx->r1 = ctx->r15 < ctx->r5 ? 1 : 0;
    // 0x80065A28: beq         $at, $zero, L_80065A38
    if (ctx->r1 == 0) {
        // 0x80065A2C: nop
    
            goto L_80065A38;
    }
    // 0x80065A2C: nop

    // 0x80065A30: lbu         $a1, 0x1A($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X1A);
    // 0x80065A34: nop

L_80065A38:
    // 0x80065A38: lh          $t9, 0x16($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X16);
    // 0x80065A3C: lh          $t3, 0x18($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X18);
    // 0x80065A40: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065A44: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x80065A48: lh          $t8, 0x12($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X12);
    // 0x80065A4C: lh          $t2, 0x14($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X14);
    // 0x80065A50: lh          $t6, 0xA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XA);
    // 0x80065A54: mflo        $t0
    ctx->r8 = lo;
    // 0x80065A58: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80065A5C: sh          $t1, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r9;
    // 0x80065A60: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065A64: lh          $t1, 0x10($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X10);
    // 0x80065A68: lh          $t0, 0xC($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XC);
    // 0x80065A6C: mflo        $t4
    ctx->r12 = lo;
    // 0x80065A70: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80065A74: sh          $t5, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r13;
    // 0x80065A78: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065A7C: lh          $t5, 0x8($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X8);
    // 0x80065A80: lh          $t4, 0x6($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X6);
    // 0x80065A84: mflo        $t9
    ctx->r25 = lo;
    // 0x80065A88: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80065A8C: sh          $t8, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r24;
    // 0x80065A90: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065A94: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x80065A98: lhu         $t9, 0x2($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X2);
    // 0x80065A9C: mflo        $t3
    ctx->r11 = lo;
    // 0x80065AA0: addu        $t2, $t0, $t3
    ctx->r10 = ADD32(ctx->r8, ctx->r11);
    // 0x80065AA4: lbu         $t3, 0x1A($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X1A);
    // 0x80065AA8: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065AAC: sh          $t2, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r10;
    // 0x80065AB0: subu        $t2, $t3, $a1
    ctx->r10 = SUB32(ctx->r11, ctx->r5);
    // 0x80065AB4: sb          $t2, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r10;
    // 0x80065AB8: mflo        $t7
    ctx->r15 = lo;
    // 0x80065ABC: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x80065AC0: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    // 0x80065AC4: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065AC8: mflo        $t1
    ctx->r9 = lo;
    // 0x80065ACC: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x80065AD0: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
L_80065AD4:
    // 0x80065AD4: jr          $ra
    // 0x80065AD8: nop

    return;
    // 0x80065AD8: nop

;}

RECOMP_FUNC void PieceHold_80065e20_lots_of_ifs_and_traps(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E20: lhu         $t6, 0x16($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X16);
    // 0x80065E24: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80065E28: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80065E2C: sb          $t6, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r14;
    // 0x80065E30: lh          $t7, 0x4($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4);
    // 0x80065E34: lh          $t8, 0x12($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X12);
    // 0x80065E38: lhu         $t0, 0x16($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X16);
    // 0x80065E3C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80065E40: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x80065E44: lh          $t3, 0x14($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X14);
    // 0x80065E48: lh          $t8, 0xA($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XA);
    // 0x80065E4C: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x80065E50: bne         $t0, $zero, L_80065E5C
    if (ctx->r8 != 0) {
        // 0x80065E54: nop
    
            goto L_80065E5C;
    }
    // 0x80065E54: nop

    // 0x80065E58: break       7
    do_break(2147901016);
L_80065E5C:
    // 0x80065E5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80065E60: bne         $t0, $at, L_80065E74
    if (ctx->r8 != ctx->r1) {
        // 0x80065E64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80065E74;
    }
    // 0x80065E64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065E68: bne         $t9, $at, L_80065E74
    if (ctx->r25 != ctx->r1) {
        // 0x80065E6C: nop
    
            goto L_80065E74;
    }
    // 0x80065E6C: nop

    // 0x80065E70: break       6
    do_break(2147901040);
L_80065E74:
    // 0x80065E74: mflo        $t1
    ctx->r9 = lo;
    // 0x80065E78: sh          $t1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r9;
    // 0x80065E7C: lh          $t2, 0x6($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X6);
    // 0x80065E80: lhu         $t5, 0x16($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X16);
    // 0x80065E84: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80065E88: div         $zero, $t4, $t5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r13)));
    // 0x80065E8C: lh          $t3, 0xC($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XC);
    // 0x80065E90: bne         $t5, $zero, L_80065E9C
    if (ctx->r13 != 0) {
        // 0x80065E94: nop
    
            goto L_80065E9C;
    }
    // 0x80065E94: nop

    // 0x80065E98: break       7
    do_break(2147901080);
L_80065E9C:
    // 0x80065E9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80065EA0: bne         $t5, $at, L_80065EB4
    if (ctx->r13 != ctx->r1) {
        // 0x80065EA4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80065EB4;
    }
    // 0x80065EA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065EA8: bne         $t4, $at, L_80065EB4
    if (ctx->r12 != ctx->r1) {
        // 0x80065EAC: nop
    
            goto L_80065EB4;
    }
    // 0x80065EAC: nop

    // 0x80065EB0: break       6
    do_break(2147901104);
L_80065EB4:
    // 0x80065EB4: mflo        $t6
    ctx->r14 = lo;
    // 0x80065EB8: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x80065EBC: lh          $t7, 0x8($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8);
    // 0x80065EC0: lhu         $t0, 0x16($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X16);
    // 0x80065EC4: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80065EC8: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x80065ECC: bne         $t0, $zero, L_80065ED8
    if (ctx->r8 != 0) {
        // 0x80065ED0: nop
    
            goto L_80065ED8;
    }
    // 0x80065ED0: nop

    // 0x80065ED4: break       7
    do_break(2147901140);
L_80065ED8:
    // 0x80065ED8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80065EDC: bne         $t0, $at, L_80065EF0
    if (ctx->r8 != ctx->r1) {
        // 0x80065EE0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80065EF0;
    }
    // 0x80065EE0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065EE4: bne         $t9, $at, L_80065EF0
    if (ctx->r25 != ctx->r1) {
        // 0x80065EE8: nop
    
            goto L_80065EF0;
    }
    // 0x80065EE8: nop

    // 0x80065EEC: break       6
    do_break(2147901164);
L_80065EF0:
    // 0x80065EF0: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x80065EF4: mflo        $t1
    ctx->r9 = lo;
    // 0x80065EF8: sh          $t1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r9;
    // 0x80065EFC: lh          $t2, 0xA($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XA);
    // 0x80065F00: lhu         $t5, 0x16($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X16);
    // 0x80065F04: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80065F08: div         $zero, $t4, $t5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r13)));
    // 0x80065F0C: lhu         $t2, 0x2($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X2);
    // 0x80065F10: bne         $t5, $zero, L_80065F1C
    if (ctx->r13 != 0) {
        // 0x80065F14: nop
    
            goto L_80065F1C;
    }
    // 0x80065F14: nop

    // 0x80065F18: break       7
    do_break(2147901208);
L_80065F1C:
    // 0x80065F1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80065F20: bne         $t5, $at, L_80065F34
    if (ctx->r13 != ctx->r1) {
        // 0x80065F24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80065F34;
    }
    // 0x80065F24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065F28: bne         $t4, $at, L_80065F34
    if (ctx->r12 != ctx->r1) {
        // 0x80065F2C: nop
    
            goto L_80065F34;
    }
    // 0x80065F2C: nop

    // 0x80065F30: break       6
    do_break(2147901232);
L_80065F34:
    // 0x80065F34: subu        $t3, $a3, $t2
    ctx->r11 = SUB32(ctx->r7, ctx->r10);
    // 0x80065F38: mflo        $t6
    ctx->r14 = lo;
    // 0x80065F3C: sh          $t6, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r14;
    // 0x80065F40: lh          $t7, 0x12($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X12);
    // 0x80065F44: lhu         $t0, 0x16($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X16);
    // 0x80065F48: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80065F4C: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x80065F50: bne         $t0, $zero, L_80065F5C
    if (ctx->r8 != 0) {
        // 0x80065F54: nop
    
            goto L_80065F5C;
    }
    // 0x80065F54: nop

    // 0x80065F58: break       7
    do_break(2147901272);
L_80065F5C:
    // 0x80065F5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80065F60: bne         $t0, $at, L_80065F74
    if (ctx->r8 != ctx->r1) {
        // 0x80065F64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80065F74;
    }
    // 0x80065F64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065F68: bne         $t9, $at, L_80065F74
    if (ctx->r25 != ctx->r1) {
        // 0x80065F6C: nop
    
            goto L_80065F74;
    }
    // 0x80065F6C: nop

    // 0x80065F70: break       6
    do_break(2147901296);
L_80065F74:
    // 0x80065F74: mflo        $t1
    ctx->r9 = lo;
    // 0x80065F78: sh          $t1, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r9;
    // 0x80065F7C: lhu         $t4, 0x16($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X16);
    // 0x80065F80: nop

    // 0x80065F84: div         $zero, $t3, $t4
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r12)));
    // 0x80065F88: bne         $t4, $zero, L_80065F94
    if (ctx->r12 != 0) {
        // 0x80065F8C: nop
    
            goto L_80065F94;
    }
    // 0x80065F8C: nop

    // 0x80065F90: break       7
    do_break(2147901328);
L_80065F94:
    // 0x80065F94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80065F98: bne         $t4, $at, L_80065FAC
    if (ctx->r12 != ctx->r1) {
        // 0x80065F9C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80065FAC;
    }
    // 0x80065F9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065FA0: bne         $t3, $at, L_80065FAC
    if (ctx->r11 != ctx->r1) {
        // 0x80065FA4: nop
    
            goto L_80065FAC;
    }
    // 0x80065FA4: nop

    // 0x80065FA8: break       6
    do_break(2147901352);
L_80065FAC:
    // 0x80065FAC: mflo        $t5
    ctx->r13 = lo;
    // 0x80065FB0: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x80065FB4: jr          $ra
    // 0x80065FB8: nop

    return;
    // 0x80065FB8: nop

;}

RECOMP_FUNC void PieceHold_CopyPiece(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065FBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065FC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80065FC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80065FCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80065FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065FD4: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x80065FD8: jal         0x80065238
    // 0x80065FDC: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    MobilePiece_Copy(rdram, ctx);
        goto after_0;
    // 0x80065FDC: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x80065FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065FE8: jr          $ra
    // 0x80065FEC: nop

    return;
    // 0x80065FEC: nop

;}

RECOMP_FUNC void PieceHold_EnableAltColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065FF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065FFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80066000: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80066004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066008: jal         0x80065620
    // 0x8006600C: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    MobilePiece_EnableAltColor(rdram, ctx);
        goto after_0;
    // 0x8006600C: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    after_0:
    // 0x80066010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066018: jr          $ra
    // 0x8006601C: nop

    return;
    // 0x8006601C: nop

;}

RECOMP_FUNC void PieceHold_DisableAltColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066024: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80066028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006602C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066030: jal         0x8006567C
    // 0x80066034: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    MobilePiece_DisableAltColor(rdram, ctx);
        goto after_0;
    // 0x80066034: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    after_0:
    // 0x80066038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006603C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066040: jr          $ra
    // 0x80066044: nop

    return;
    // 0x80066044: nop

;}

RECOMP_FUNC void PieceHold_80066048_tenliner_checks_numplayers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066048: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006604C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80066050: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066054: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80066058: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006605C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066060: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80066064: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80066068: beq         $s0, $at, L_80066094
    if (ctx->r16 == ctx->r1) {
        // 0x8006606C: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_80066094;
    }
    // 0x8006606C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80066070: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80066074: beq         $s0, $at, L_800660E0
    if (ctx->r16 == ctx->r1) {
        // 0x80066078: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800660E0;
    }
    // 0x80066078: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006607C: beq         $s0, $at, L_80066138
    if (ctx->r16 == ctx->r1) {
        // 0x80066080: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80066138;
    }
    // 0x80066080: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80066084: beq         $s0, $at, L_80066138
    if (ctx->r16 == ctx->r1) {
        // 0x80066088: nop
    
            goto L_80066138;
    }
    // 0x80066088: nop

    // 0x8006608C: b           L_80066150
    // 0x80066090: nop

        goto L_80066150;
    // 0x80066090: nop

L_80066094:
    // 0x80066094: lbu         $t7, 0x37($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X37);
    // 0x80066098: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8006609C: addiu       $t9, $t9, 0x4C0
    ctx->r25 = ADD32(ctx->r25, 0X4C0);
    // 0x800660A0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800660A4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800660A8: lwl         $at, 0x0($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, 0X0);
    // 0x800660AC: lwr         $at, 0x3($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, 0X3);
    // 0x800660B0: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x800660B4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800660B8: lh          $a2, 0x26($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X26);
    // 0x800660BC: lh          $a1, 0x24($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X24);
    // 0x800660C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800660C4: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x800660C8: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x800660CC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800660D0: jal         0x8007104C
    // 0x800660D4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    Minos_TransformCoords(rdram, ctx);
        goto after_0;
    // 0x800660D4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_0:
    // 0x800660D8: b           L_80066150
    // 0x800660DC: nop

        goto L_80066150;
    // 0x800660DC: nop

L_800660E0:
    // 0x800660E0: lbu         $t7, 0x37($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X37);
    // 0x800660E4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800660E8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800660EC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800660F0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800660F4: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800660F8: addiu       $t0, $t0, 0x4E0
    ctx->r8 = ADD32(ctx->r8, 0X4E0);
    // 0x800660FC: addu        $t2, $t6, $t0
    ctx->r10 = ADD32(ctx->r14, ctx->r8);
    // 0x80066100: lwl         $at, 0x0($t2)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r10, 0X0);
    // 0x80066104: lwr         $at, 0x3($t2)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r10, 0X3);
    // 0x80066108: addiu       $t5, $sp, 0x24
    ctx->r13 = ADD32(ctx->r29, 0X24);
    // 0x8006610C: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80066110: lh          $a2, 0x26($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X26);
    // 0x80066114: lh          $a1, 0x24($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X24);
    // 0x80066118: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8006611C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80066120: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80066124: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80066128: jal         0x8007104C
    // 0x8006612C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    Minos_TransformCoords(rdram, ctx);
        goto after_1;
    // 0x8006612C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_1:
    // 0x80066130: b           L_80066150
    // 0x80066134: nop

        goto L_80066150;
    // 0x80066134: nop

L_80066138:
    // 0x80066138: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8006613C: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x80066140: sh          $t8, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r24;
    // 0x80066144: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80066148: addiu       $t6, $zero, -0x240
    ctx->r14 = ADD32(0, -0X240);
    // 0x8006614C: sh          $t6, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r14;
L_80066150:
    // 0x80066150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066154: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066158: jr          $ra
    // 0x8006615C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006615C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void PieceHold_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066164: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80066168: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006616C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066170: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80066174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80066178: jal         0x80065ADC
    // 0x8006617C: nop

    PieceHoldPiece_Update(rdram, ctx);
        goto after_0;
    // 0x8006617C: nop

    after_0:
    // 0x80066180: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80066184: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80066188: jal         0x80065ADC
    // 0x8006618C: addiu       $a0, $a0, 0xA48
    ctx->r4 = ADD32(ctx->r4, 0XA48);
    PieceHoldPiece_Update(rdram, ctx);
        goto after_1;
    // 0x8006618C: addiu       $a0, $a0, 0xA48
    ctx->r4 = ADD32(ctx->r4, 0XA48);
    after_1:
    // 0x80066190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066194: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066198: jr          $ra
    // 0x8006619C: nop

    return;
    // 0x8006619C: nop

;}

RECOMP_FUNC void PieceHold_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800661A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800661A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800661A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800661AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800661B0: jal         0x80065BD4
    // 0x800661B4: nop

    PieceHoldPiece_Render(rdram, ctx);
        goto after_0;
    // 0x800661B4: nop

    after_0:
    // 0x800661B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800661BC: jal         0x80065BD4
    // 0x800661C0: addiu       $a0, $a0, 0xA48
    ctx->r4 = ADD32(ctx->r4, 0XA48);
    PieceHoldPiece_Render(rdram, ctx);
        goto after_1;
    // 0x800661C0: addiu       $a0, $a0, 0xA48
    ctx->r4 = ADD32(ctx->r4, 0XA48);
    after_1:
    // 0x800661C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800661C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800661CC: jr          $ra
    // 0x800661D0: nop

    return;
    // 0x800661D0: nop

;}

RECOMP_FUNC void PieceHold_Swap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800661D4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800661D8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800661DC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800661E0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800661E4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800661E8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800661EC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800661F0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800661F4: lbu         $t7, 0x1495($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1495);
    // 0x800661F8: nop

    // 0x800661FC: beq         $t7, $zero, L_8006644C
    if (ctx->r15 == 0) {
        // 0x80066200: nop
    
            goto L_8006644C;
    }
    // 0x80066200: nop

    // 0x80066204: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80066208: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8006620C: lbu         $t9, 0x1494($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1494);
    // 0x80066210: addiu       $a0, $t8, 0x1498
    ctx->r4 = ADD32(ctx->r24, 0X1498);
    // 0x80066214: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80066218: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8006621C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80066220: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80066224: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80066228: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8006622C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80066230: addu        $s0, $t8, $t0
    ctx->r16 = ADD32(ctx->r24, ctx->r8);
    // 0x80066234: lbu         $t1, 0x1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1);
    // 0x80066238: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x8006623C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80066240: addu        $s1, $s1, $t2
    ctx->r17 = ADD32(ctx->r17, ctx->r10);
    // 0x80066244: lw          $s1, 0x110($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X110);
    // 0x80066248: jal         0x8006D090
    // 0x8006624C: nop

    CurPiece_SetDef(rdram, ctx);
        goto after_0;
    // 0x8006624C: nop

    after_0:
    // 0x80066250: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80066254: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80066258: jal         0x8006D0AC
    // 0x8006625C: addiu       $a1, $a1, 0x1498
    ctx->r5 = ADD32(ctx->r5, 0X1498);
    CurPiece_GetPhysicalSpawnPos(rdram, ctx);
        goto after_1;
    // 0x8006625C: addiu       $a1, $a1, 0x1498
    ctx->r5 = ADD32(ctx->r5, 0X1498);
    after_1:
    // 0x80066260: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80066264: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80066268: jal         0x8006D11C
    // 0x8006626C: addiu       $a1, $a1, 0x1498
    ctx->r5 = ADD32(ctx->r5, 0X1498);
    CurPiece_GetPhysicalRotOrigin(rdram, ctx);
        goto after_2;
    // 0x8006626C: addiu       $a1, $a1, 0x1498
    ctx->r5 = ADD32(ctx->r5, 0X1498);
    after_2:
    // 0x80066270: lwl         $t3, 0x38($sp)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r29, 0X38);
    // 0x80066274: lwl         $t4, 0x3C($sp)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r29, 0X3C);
    // 0x80066278: lwr         $t3, 0x3B($sp)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r29, 0X3B);
    // 0x8006627C: lwr         $t4, 0x3F($sp)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r29, 0X3F);
    // 0x80066280: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80066284: swl         $t3, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r11);
    // 0x80066288: swl         $t4, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r12);
    // 0x8006628C: swr         $t3, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r11);
    // 0x80066290: swr         $t4, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r12);
    // 0x80066294: lw          $t6, 0x1498($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1498);
    // 0x80066298: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x8006629C: lbu         $a3, 0x1E($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X1E);
    // 0x800662A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800662A4: lbu         $t0, 0x1496($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X1496);
    // 0x800662A8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x800662AC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x800662B0: sll         $t7, $a3, 14
    ctx->r15 = S32(ctx->r7 << 14);
    // 0x800662B4: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800662B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800662BC: jal         0x80065E20
    // 0x800662C0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    PieceHold_80065e20_lots_of_ifs_and_traps(rdram, ctx);
        goto after_3;
    // 0x800662C0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_3:
    // 0x800662C4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800662C8: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    // 0x800662CC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800662D0: addiu       $a0, $s0, 0x538
    ctx->r4 = ADD32(ctx->r16, 0X538);
    // 0x800662D4: lbu         $a1, 0x1496($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X1496);
    // 0x800662D8: jal         0x80065720
    // 0x800662DC: nop

    PieceHold_80065720_fiveliner_two_traps(rdram, ctx);
        goto after_4;
    // 0x800662DC: nop

    after_4:
    // 0x800662E0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800662E4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800662E8: lbu         $t3, 0x1494($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X1494);
    // 0x800662EC: addiu       $s2, $t7, 0x20
    ctx->r18 = ADD32(ctx->r15, 0X20);
    // 0x800662F0: lwl         $at, 0xE($s2)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r18, 0XE);
    // 0x800662F4: lwr         $at, 0x11($s2)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r18, 0X11);
    // 0x800662F8: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x800662FC: lbu         $t9, 0x13($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X13);
    // 0x80066300: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80066304: lbu         $a1, 0x13($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X13);
    // 0x80066308: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8006630C: swl         $at, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r1);
    // 0x80066310: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80066314: swr         $at, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r1);
    // 0x80066318: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8006631C: lwl         $at, 0xA($s2)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r18, 0XA);
    // 0x80066320: lwr         $at, 0xD($s2)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r18, 0XD);
    // 0x80066324: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80066328: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8006632C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80066330: swl         $at, 0xC($sp)
    do_swl(rdram, 0XC, ctx->r29, ctx->r1);
    // 0x80066334: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80066338: addu        $s0, $t8, $t6
    ctx->r16 = ADD32(ctx->r24, ctx->r14);
    // 0x8006633C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80066340: swr         $at, 0xF($sp)
    do_swr(rdram, 0XF, ctx->r29, ctx->r1);
    // 0x80066344: lhu         $t4, 0x8($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X8);
    // 0x80066348: addu        $s1, $s1, $t5
    ctx->r17 = ADD32(ctx->r17, ctx->r13);
    // 0x8006634C: addiu       $s0, $s0, 0xA48
    ctx->r16 = ADD32(ctx->r16, 0XA48);
    // 0x80066350: lw          $s1, 0x110($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X110);
    // 0x80066354: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80066358: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x8006635C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80066360: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80066364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066368: jal         0x80065C74
    // 0x8006636C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    PieceHoldPiece_MakeActive(rdram, ctx);
        goto after_5;
    // 0x8006636C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_5:
    // 0x80066370: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80066374: addiu       $t2, $zero, 0xC0
    ctx->r10 = ADD32(0, 0XC0);
    // 0x80066378: lwl         $at, 0x1490($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X1490);
    // 0x8006637C: lwr         $at, 0x1493($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X1493);
    // 0x80066380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066384: swl         $at, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r1);
    // 0x80066388: swr         $at, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r1);
    // 0x8006638C: lwl         $at, 0xA($s1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r17, 0XA);
    // 0x80066390: lwr         $at, 0xD($s1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r17, 0XD);
    // 0x80066394: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80066398: swl         $at, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r1);
    // 0x8006639C: swr         $at, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r1);
    // 0x800663A0: lbu         $a3, 0x1E($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X1E);
    // 0x800663A4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800663A8: lbu         $t3, 0x1496($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X1496);
    // 0x800663AC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x800663B0: sll         $t1, $a3, 14
    ctx->r9 = S32(ctx->r7 << 14);
    // 0x800663B4: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800663B8: jal         0x80065E20
    // 0x800663BC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    PieceHold_80065e20_lots_of_ifs_and_traps(rdram, ctx);
        goto after_6;
    // 0x800663BC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_6:
    // 0x800663C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800663C4: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800663C8: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800663CC: addiu       $t4, $zero, 0xC0
    ctx->r12 = ADD32(0, 0XC0);
    // 0x800663D0: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x800663D4: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800663D8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800663DC: lwl         $at, 0x1490($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0X1490);
    // 0x800663E0: lwr         $at, 0x1493($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0X1493);
    // 0x800663E4: lbu         $a1, 0x13($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X13);
    // 0x800663E8: swl         $at, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r1);
    // 0x800663EC: swr         $at, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r1);
    // 0x800663F0: lwl         $at, 0xA($s1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r17, 0XA);
    // 0x800663F4: lwr         $at, 0xD($s1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r17, 0XD);
    // 0x800663F8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x800663FC: swl         $at, 0xC($sp)
    do_swl(rdram, 0XC, ctx->r29, ctx->r1);
    // 0x80066400: swr         $at, 0xF($sp)
    do_swr(rdram, 0XF, ctx->r29, ctx->r1);
    // 0x80066404: lbu         $t6, 0x1E($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1E);
    // 0x80066408: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8006640C: sll         $t3, $t6, 14
    ctx->r11 = S32(ctx->r14 << 14);
    // 0x80066410: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80066414: lbu         $t8, 0x1496($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X1496);
    // 0x80066418: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8006641C: addiu       $a0, $s0, 0x538
    ctx->r4 = ADD32(ctx->r16, 0X538);
    // 0x80066420: jal         0x8006576C
    // 0x80066424: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    PieceHoldPiece_MakeShadowActive(rdram, ctx);
        goto after_7;
    // 0x80066424: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_7:
    // 0x80066428: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8006642C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80066430: lbu         $t7, 0x1494($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X1494);
    // 0x80066434: nop

    // 0x80066438: subu        $t1, $t0, $t7
    ctx->r9 = SUB32(ctx->r8, ctx->r15);
    // 0x8006643C: sb          $t1, 0x1494($t9)
    MEM_B(0X1494, ctx->r25) = ctx->r9;
    // 0x80066440: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80066444: jal         0x800664C0
    // 0x80066448: nop

    PieceHold_Disable(rdram, ctx);
        goto after_8;
    // 0x80066448: nop

    after_8:
L_8006644C:
    // 0x8006644C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80066450: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80066454: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80066458: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8006645C: jr          $ra
    // 0x80066460: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80066460: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}

RECOMP_FUNC void PieceHold_Enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066468: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006646C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80066470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066474: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80066478: sb          $t6, 0x1495($t7)
    MEM_B(0X1495, ctx->r15) = ctx->r14;
    // 0x8006647C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80066480: nop

    // 0x80066484: lbu         $t9, 0x1494($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1494);
    // 0x80066488: nop

    // 0x8006648C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80066490: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80066494: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80066498: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8006649C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800664A0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800664A4: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800664A8: jal         0x80066020
    // 0x800664AC: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    PieceHold_DisableAltColor(rdram, ctx);
        goto after_0;
    // 0x800664AC: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    after_0:
    // 0x800664B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800664B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800664B8: jr          $ra
    // 0x800664BC: nop

    return;
    // 0x800664BC: nop

;}

RECOMP_FUNC void PieceHold_Disable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800664C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800664C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800664C8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800664CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800664D0: sb          $zero, 0x1495($t6)
    MEM_B(0X1495, ctx->r14) = 0;
    // 0x800664D4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800664D8: nop

    // 0x800664DC: lbu         $t8, 0x1494($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1494);
    // 0x800664E0: nop

    // 0x800664E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800664E8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800664EC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800664F0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800664F4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800664F8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800664FC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80066500: jal         0x80065FF8
    // 0x80066504: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    PieceHold_EnableAltColor(rdram, ctx);
        goto after_0;
    // 0x80066504: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x80066508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006650C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066510: jr          $ra
    // 0x80066514: nop

    return;
    // 0x80066514: nop

;}

RECOMP_FUNC void PieceHold_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066518: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006651C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80066520: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80066524: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80066528: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8006652C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80066530: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80066534: lbu         $a2, 0x47($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X47);
    // 0x80066538: lbu         $a1, 0x43($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X43);
    // 0x8006653C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80066540: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80066544: jal         0x8006D17C
    // 0x80066548: addiu       $a0, $a0, 0x1498
    ctx->r4 = ADD32(ctx->r4, 0X1498);
    CurPiece_Init(rdram, ctx);
        goto after_0;
    // 0x80066548: addiu       $a0, $a0, 0x1498
    ctx->r4 = ADD32(ctx->r4, 0X1498);
    after_0:
    // 0x8006654C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80066550: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80066554: sb          $t6, 0x1496($t7)
    MEM_B(0X1496, ctx->r15) = ctx->r14;
    // 0x80066558: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8006655C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80066560: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80066564: lbu         $a2, -0x10DF($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X10DF);
    // 0x80066568: lbu         $a1, -0x10E0($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X10E0);
    // 0x8006656C: lbu         $a3, 0x4B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X4B);
    // 0x80066570: jal         0x80066048
    // 0x80066574: addiu       $a0, $a0, 0x1490
    ctx->r4 = ADD32(ctx->r4, 0X1490);
    PieceHold_80066048_tenliner_checks_numplayers(rdram, ctx);
        goto after_1;
    // 0x80066574: addiu       $a0, $a0, 0x1490
    ctx->r4 = ADD32(ctx->r4, 0X1490);
    after_1:
    // 0x80066578: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006657C: nop

    // 0x80066580: sb          $zero, 0x1494($t8)
    MEM_B(0X1494, ctx->r24) = 0;
    // 0x80066584: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80066588: jal         0x80065FF0
    // 0x8006658C: nop

    PieceHoldPiece_Init(rdram, ctx);
        goto after_2;
    // 0x8006658C: nop

    after_2:
    // 0x80066590: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80066594: jal         0x80065FF0
    // 0x80066598: addiu       $a0, $a0, 0xA48
    ctx->r4 = ADD32(ctx->r4, 0XA48);
    PieceHoldPiece_Init(rdram, ctx);
        goto after_3;
    // 0x80066598: addiu       $a0, $a0, 0xA48
    ctx->r4 = ADD32(ctx->r4, 0XA48);
    after_3:
    // 0x8006659C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800665A0: nop

    // 0x800665A4: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x800665A8: jal         0x8006089C
    // 0x800665AC: nop

    Rand_Hash(rdram, ctx);
        goto after_4;
    // 0x800665AC: nop

    after_4:
    // 0x800665B0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800665B4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800665B8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800665BC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800665C0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800665C4: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x800665C8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800665CC: divu        $zero, $s0, $at
    lo = S32(U32(ctx->r16) / U32(ctx->r1)); hi = S32(U32(ctx->r16) % U32(ctx->r1));
    // 0x800665D0: lwl         $at, 0x1490($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0X1490);
    // 0x800665D4: lwr         $at, 0x1493($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0X1493);
    // 0x800665D8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800665DC: swl         $at, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r1);
    // 0x800665E0: swr         $at, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r1);
    // 0x800665E4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x800665E8: mfhi        $t2
    ctx->r10 = hi;
    // 0x800665EC: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800665F0: andi        $t3, $s0, 0xFF
    ctx->r11 = ctx->r16 & 0XFF;
    // 0x800665F4: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x800665F8: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800665FC: addu        $s1, $s1, $t4
    ctx->r17 = ADD32(ctx->r17, ctx->r12);
    // 0x80066600: lw          $s1, 0x110($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X110);
    // 0x80066604: addiu       $t2, $zero, 0xC0
    ctx->r10 = ADD32(0, 0XC0);
    // 0x80066608: lwl         $at, 0xA($s1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r17, 0XA);
    // 0x8006660C: lwr         $at, 0xD($s1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r17, 0XD);
    // 0x80066610: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80066614: swl         $at, 0xC($sp)
    do_swl(rdram, 0XC, ctx->r29, ctx->r1);
    // 0x80066618: swr         $at, 0xF($sp)
    do_swr(rdram, 0XF, ctx->r29, ctx->r1);
    // 0x8006661C: lbu         $t0, 0x1E($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1E);
    // 0x80066620: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80066624: sll         $t1, $t0, 14
    ctx->r9 = S32(ctx->r8 << 14);
    // 0x80066628: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8006662C: jal         0x80065C74
    // 0x80066630: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    PieceHoldPiece_MakeActive(rdram, ctx);
        goto after_5;
    // 0x80066630: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_5:
    // 0x80066634: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80066638: addiu       $t0, $zero, 0xC0
    ctx->r8 = ADD32(0, 0XC0);
    // 0x8006663C: lwl         $at, 0x1490($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0X1490);
    // 0x80066640: lwr         $at, 0x1493($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0X1493);
    // 0x80066644: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80066648: swl         $at, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r1);
    // 0x8006664C: swr         $at, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r1);
    // 0x80066650: lwl         $at, 0xA($s1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r17, 0XA);
    // 0x80066654: lwr         $at, 0xD($s1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r17, 0XD);
    // 0x80066658: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8006665C: swl         $at, 0xC($sp)
    do_swl(rdram, 0XC, ctx->r29, ctx->r1);
    // 0x80066660: swr         $at, 0xF($sp)
    do_swr(rdram, 0XF, ctx->r29, ctx->r1);
    // 0x80066664: lbu         $t8, 0x1E($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1E);
    // 0x80066668: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8006666C: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x80066670: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80066674: lbu         $t1, 0x1496($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X1496);
    // 0x80066678: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8006667C: addiu       $a0, $t3, 0x538
    ctx->r4 = ADD32(ctx->r11, 0X538);
    // 0x80066680: jal         0x8006576C
    // 0x80066684: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    PieceHoldPiece_MakeShadowActive(rdram, ctx);
        goto after_6;
    // 0x80066684: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_6:
    // 0x80066688: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8006668C: jal         0x80066464
    // 0x80066690: nop

    PieceHold_Enable(rdram, ctx);
        goto after_7;
    // 0x80066690: nop

    after_7:
    // 0x80066694: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80066698: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8006669C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800666A0: jr          $ra
    // 0x800666A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800666A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void PieceHold_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800666A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800666AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800666B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800666B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800666B8: jal         0x8006D194
    // 0x800666BC: addiu       $a0, $a0, 0x1498
    ctx->r4 = ADD32(ctx->r4, 0X1498);
    CurPiece_Deinit(rdram, ctx);
        goto after_0;
    // 0x800666BC: addiu       $a0, $a0, 0x1498
    ctx->r4 = ADD32(ctx->r4, 0X1498);
    after_0:
    // 0x800666C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800666C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800666C8: jr          $ra
    // 0x800666CC: nop

    return;
    // 0x800666CC: nop

;}

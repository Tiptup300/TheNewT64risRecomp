#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void LineScan_UpdateLineEffects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069830: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80069834: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80069838: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006983C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80069840: sltiu       $at, $s0, 0x14
    ctx->r1 = ctx->r16 < 0X14 ? 1 : 0;
    // 0x80069844: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80069848: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006984C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80069850: beq         $at, $zero, L_8006989C
    if (ctx->r1 == 0) {
        // 0x80069854: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8006989C;
    }
    // 0x80069854: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80069858:
    // 0x80069858: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8006985C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80069860: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80069864: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80069868: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8006986C: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x80069870: jal         0x8006952C
    // 0x80069874: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LineEffect_Update(rdram, ctx);
        goto after_0;
    // 0x80069874: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80069878: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8006987C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80069880: beq         $s2, $at, L_8006988C
    if (ctx->r18 == ctx->r1) {
        // 0x80069884: nop
    
            goto L_8006988C;
    }
    // 0x80069884: nop

    // 0x80069888: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8006988C:
    // 0x8006988C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80069890: sltiu       $at, $s0, 0x14
    ctx->r1 = ctx->r16 < 0X14 ? 1 : 0;
    // 0x80069894: bne         $at, $zero, L_80069858
    if (ctx->r1 != 0) {
        // 0x80069898: nop
    
            goto L_80069858;
    }
    // 0x80069898: nop

L_8006989C:
    // 0x8006989C: beq         $s1, $zero, L_800698C8
    if (ctx->r17 == 0) {
        // 0x800698A0: nop
    
            goto L_800698C8;
    }
    // 0x800698A0: nop

    // 0x800698A4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800698A8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800698AC: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x800698B0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800698B4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800698B8: sb          $t9, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r25;
    // 0x800698BC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800698C0: nop

    // 0x800698C4: sb          $t1, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r9;
L_800698C8:
    // 0x800698C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800698CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800698D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800698D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800698D8: jr          $ra
    // 0x800698DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800698DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void LineScan_ExecuteLineClears(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800698E0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800698E4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800698E8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800698EC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800698F0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800698F4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800698F8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800698FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80069900: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80069904: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80069908: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006990C: lw          $t7, 0x3F0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3F0);
    // 0x80069910: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80069914: bne         $t7, $at, L_80069958
    if (ctx->r15 != ctx->r1) {
        // 0x80069918: nop
    
            goto L_80069958;
    }
    // 0x80069918: nop

    // 0x8006991C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069920: lw          $t8, -0x490($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X490);
    // 0x80069924: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80069928: lbu         $t9, 0x13($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X13);
    // 0x8006992C: nop

    // 0x80069930: bne         $t9, $at, L_80069958
    if (ctx->r25 != ctx->r1) {
        // 0x80069934: nop
    
            goto L_80069958;
    }
    // 0x80069934: nop

    // 0x80069938: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006993C: lw          $a0, -0x10F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X10F0);
    // 0x80069940: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80069944: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80069948: jal         0x800529A8
    // 0x8006994C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    updateLinesToBeAdded(rdram, ctx);
        goto after_0;
    // 0x8006994C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_0:
    // 0x80069950: b           L_8006995C
    // 0x80069954: nop

        goto L_8006995C;
    // 0x80069954: nop

L_80069958:
    // 0x80069958: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8006995C:
    // 0x8006995C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80069960: nop

    // 0x80069964: lw          $t1, 0x3F0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X3F0);
    // 0x80069968: nop

    // 0x8006996C: sltiu       $at, $t1, 0x4
    ctx->r1 = ctx->r9 < 0X4 ? 1 : 0;
    // 0x80069970: beq         $at, $zero, L_80069990
    if (ctx->r1 == 0) {
        // 0x80069974: sltiu       $at, $t1, 0x2
        ctx->r1 = ctx->r9 < 0X2 ? 1 : 0;
            goto L_80069990;
    }
    // 0x80069974: sltiu       $at, $t1, 0x2
    ctx->r1 = ctx->r9 < 0X2 ? 1 : 0;
    // 0x80069978: bne         $at, $zero, L_800699A4
    if (ctx->r1 != 0) {
        // 0x8006997C: nop
    
            goto L_800699A4;
    }
    // 0x8006997C: nop

    // 0x80069980: jal         0x80073030
    // 0x80069984: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
    Garbage_ApplyIncoming(rdram, ctx);
        goto after_1;
    // 0x80069984: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
    after_1:
    // 0x80069988: b           L_800699A4
    // 0x8006998C: nop

        goto L_800699A4;
    // 0x8006998C: nop

L_80069990:
    // 0x80069990: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80069994: nop

    // 0x80069998: lw          $a0, 0x3F0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X3F0);
    // 0x8006999C: jal         0x80073030
    // 0x800699A0: nop

    Garbage_ApplyIncoming(rdram, ctx);
        goto after_2;
    // 0x800699A0: nop

    after_2:
L_800699A4:
    // 0x800699A4: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x800699A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800699AC: sltiu       $at, $s1, 0x14
    ctx->r1 = ctx->r17 < 0X14 ? 1 : 0;
    // 0x800699B0: beq         $at, $zero, L_80069B4C
    if (ctx->r1 == 0) {
        // 0x800699B4: addiu       $s0, $s0, 0x3
        ctx->r16 = ADD32(ctx->r16, 0X3);
            goto L_80069B4C;
    }
    // 0x800699B4: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
L_800699B8:
    // 0x800699B8: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x800699BC: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800699C0: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x800699C4: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800699C8: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x800699CC: jal         0x80069668
    // 0x800699D0: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    LineEffect_ResetIdle(rdram, ctx);
        goto after_3;
    // 0x800699D0: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_3:
    // 0x800699D4: lbu         $t5, 0x1($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1);
    // 0x800699D8: nop

    // 0x800699DC: beq         $t5, $zero, L_80069B3C
    if (ctx->r13 == 0) {
        // 0x800699E0: nop
    
            goto L_80069B3C;
    }
    // 0x800699E0: nop

    // 0x800699E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800699E8: lw          $a0, -0x10F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X10F0);
    // 0x800699EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800699F0: jal         0x800529A8
    // 0x800699F4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    updateLinesToBeAdded(rdram, ctx);
        goto after_4;
    // 0x800699F4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_4:
    // 0x800699F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800699FC: jal         0x8006AC2C
    // 0x80069A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Multisquare_FlagMatches(rdram, ctx);
        goto after_5;
    // 0x80069A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80069A04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069A08: lw          $a0, -0x10F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X10F0);
    // 0x80069A0C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80069A10: sll         $a1, $s5, 2
    ctx->r5 = S32(ctx->r21 << 2);
    // 0x80069A14: addu        $a1, $a1, $s5
    ctx->r5 = ADD32(ctx->r5, ctx->r21);
    // 0x80069A18: jal         0x800529A8
    // 0x80069A1C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    updateLinesToBeAdded(rdram, ctx);
        goto after_6;
    // 0x80069A1C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_6:
    // 0x80069A20: slt         $s2, $zero, $s5
    ctx->r18 = SIGNED(0) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80069A24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80069A28: jal         0x8006AC2C
    // 0x80069A2C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Multisquare_FlagMatches(rdram, ctx);
        goto after_7;
    // 0x80069A2C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80069A30: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80069A34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069A38: lw          $a0, -0x10F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X10F0);
    // 0x80069A3C: sll         $a1, $s5, 2
    ctx->r5 = S32(ctx->r21 << 2);
    // 0x80069A40: addu        $a1, $a1, $s5
    ctx->r5 = ADD32(ctx->r5, ctx->r21);
    // 0x80069A44: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x80069A48: jal         0x800529A8
    // 0x80069A4C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    updateLinesToBeAdded(rdram, ctx);
        goto after_8;
    // 0x80069A4C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_8:
    // 0x80069A50: bne         $s2, $zero, L_80069A60
    if (ctx->r18 != 0) {
        // 0x80069A54: slt         $s3, $zero, $s5
        ctx->r19 = SIGNED(0) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_80069A60;
    }
    // 0x80069A54: slt         $s3, $zero, $s5
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80069A58: beq         $s3, $zero, L_80069A7C
    if (ctx->r19 == 0) {
        // 0x80069A5C: nop
    
            goto L_80069A7C;
    }
    // 0x80069A5C: nop

L_80069A60:
    // 0x80069A60: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80069A64: lbu         $t6, 0x540($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X540);
    // 0x80069A68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80069A6C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80069A70: sb          $t7, 0x540($at)
    MEM_B(0X540, ctx->r1) = ctx->r15;
    // 0x80069A74: jal         0x80073030
    // 0x80069A78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Garbage_ApplyIncoming(rdram, ctx);
        goto after_9;
    // 0x80069A78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
L_80069A7C:
    // 0x80069A7C: beq         $s3, $zero, L_80069AB0
    if (ctx->r19 == 0) {
        // 0x80069A80: nop
    
            goto L_80069AB0;
    }
    // 0x80069A80: nop

    // 0x80069A84: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80069A88: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80069A8C: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x80069A90: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80069A94: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80069A98: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x80069A9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80069AA0: jal         0x800696F4
    // 0x80069AA4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LineEffect_Init(rdram, ctx);
        goto after_10;
    // 0x80069AA4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_10:
    // 0x80069AA8: b           L_80069B3C
    // 0x80069AAC: nop

        goto L_80069B3C;
    // 0x80069AAC: nop

L_80069AB0:
    // 0x80069AB0: beq         $s2, $zero, L_80069AE4
    if (ctx->r18 == 0) {
        // 0x80069AB4: nop
    
            goto L_80069AE4;
    }
    // 0x80069AB4: nop

    // 0x80069AB8: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80069ABC: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80069AC0: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x80069AC4: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80069AC8: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x80069ACC: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x80069AD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80069AD4: jal         0x800696F4
    // 0x80069AD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LineEffect_Init(rdram, ctx);
        goto after_11;
    // 0x80069AD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_11:
    // 0x80069ADC: b           L_80069B3C
    // 0x80069AE0: nop

        goto L_80069B3C;
    // 0x80069AE0: nop

L_80069AE4:
    // 0x80069AE4: beq         $s4, $zero, L_80069B18
    if (ctx->r20 == 0) {
        // 0x80069AE8: nop
    
            goto L_80069B18;
    }
    // 0x80069AE8: nop

    // 0x80069AEC: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80069AF0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80069AF4: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x80069AF8: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80069AFC: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x80069B00: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x80069B04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80069B08: jal         0x800696F4
    // 0x80069B0C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    LineEffect_Init(rdram, ctx);
        goto after_12;
    // 0x80069B0C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
    // 0x80069B10: b           L_80069B3C
    // 0x80069B14: nop

        goto L_80069B3C;
    // 0x80069B14: nop

L_80069B18:
    // 0x80069B18: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80069B1C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80069B20: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x80069B24: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80069B28: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x80069B2C: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x80069B30: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80069B34: jal         0x800696F4
    // 0x80069B38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LineEffect_Init(rdram, ctx);
        goto after_13;
    // 0x80069B38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
L_80069B3C:
    // 0x80069B3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80069B40: sltiu       $at, $s1, 0x14
    ctx->r1 = ctx->r17 < 0X14 ? 1 : 0;
    // 0x80069B44: bne         $at, $zero, L_800699B8
    if (ctx->r1 != 0) {
        // 0x80069B48: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_800699B8;
    }
    // 0x80069B48: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80069B4C:
    // 0x80069B4C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80069B50: lbu         $t6, 0x540($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X540);
    // 0x80069B54: nop

    // 0x80069B58: beq         $t6, $zero, L_80069CA0
    if (ctx->r14 == 0) {
        // 0x80069B5C: nop
    
            goto L_80069CA0;
    }
    // 0x80069B5C: nop

    // 0x80069B60: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x80069B64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80069B68: beq         $s6, $at, L_80069B90
    if (ctx->r22 == ctx->r1) {
        // 0x80069B6C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80069B90;
    }
    // 0x80069B6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80069B70: beq         $s6, $at, L_80069BB0
    if (ctx->r22 == ctx->r1) {
        // 0x80069B74: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80069BB0;
    }
    // 0x80069B74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80069B78: beq         $s6, $at, L_80069BE8
    if (ctx->r22 == ctx->r1) {
        // 0x80069B7C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80069BE8;
    }
    // 0x80069B7C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80069B80: beq         $s6, $at, L_80069C38
    if (ctx->r22 == ctx->r1) {
        // 0x80069B84: nop
    
            goto L_80069C38;
    }
    // 0x80069B84: nop

    // 0x80069B88: b           L_80069C98
    // 0x80069B8C: nop

        goto L_80069C98;
    // 0x80069B8C: nop

L_80069B90:
    // 0x80069B90: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069B94: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069B98: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80069B9C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80069BA0: jal         0x8008A5C8
    // 0x80069BA4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    Audio2_Play_SFX(rdram, ctx);
        goto after_14;
    // 0x80069BA4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_14:
    // 0x80069BA8: b           L_80069C98
    // 0x80069BAC: nop

        goto L_80069C98;
    // 0x80069BAC: nop

L_80069BB0:
    // 0x80069BB0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069BB4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069BB8: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80069BBC: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80069BC0: jal         0x8008A5C8
    // 0x80069BC4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    Audio2_Play_SFX(rdram, ctx);
        goto after_15;
    // 0x80069BC4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_15:
    // 0x80069BC8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069BCC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069BD0: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80069BD4: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80069BD8: jal         0x8008A5C8
    // 0x80069BDC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    Audio2_Play_SFX(rdram, ctx);
        goto after_16;
    // 0x80069BDC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_16:
    // 0x80069BE0: b           L_80069C98
    // 0x80069BE4: nop

        goto L_80069C98;
    // 0x80069BE4: nop

L_80069BE8:
    // 0x80069BE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069BEC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069BF0: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80069BF4: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80069BF8: jal         0x8008A5C8
    // 0x80069BFC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    Audio2_Play_SFX(rdram, ctx);
        goto after_17;
    // 0x80069BFC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_17:
    // 0x80069C00: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069C04: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069C08: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80069C0C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80069C10: jal         0x8008A5C8
    // 0x80069C14: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    Audio2_Play_SFX(rdram, ctx);
        goto after_18;
    // 0x80069C14: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_18:
    // 0x80069C18: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069C1C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069C20: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80069C24: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80069C28: jal         0x8008A5C8
    // 0x80069C2C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    Audio2_Play_SFX(rdram, ctx);
        goto after_19;
    // 0x80069C2C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    after_19:
    // 0x80069C30: b           L_80069C98
    // 0x80069C34: nop

        goto L_80069C98;
    // 0x80069C34: nop

L_80069C38:
    // 0x80069C38: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069C3C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069C40: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80069C44: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80069C48: jal         0x8008A5C8
    // 0x80069C4C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    Audio2_Play_SFX(rdram, ctx);
        goto after_20;
    // 0x80069C4C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_20:
    // 0x80069C50: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069C54: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069C58: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80069C5C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80069C60: jal         0x8008A5C8
    // 0x80069C64: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    Audio2_Play_SFX(rdram, ctx);
        goto after_21;
    // 0x80069C64: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_21:
    // 0x80069C68: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069C6C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069C70: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80069C74: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80069C78: jal         0x8008A5C8
    // 0x80069C7C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    Audio2_Play_SFX(rdram, ctx);
        goto after_22;
    // 0x80069C7C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_22:
    // 0x80069C80: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069C84: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069C88: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80069C8C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80069C90: jal         0x8008A5C8
    // 0x80069C94: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    Audio2_Play_SFX(rdram, ctx);
        goto after_23;
    // 0x80069C94: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    after_23:
L_80069C98:
    // 0x80069C98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80069C9C: sb          $zero, 0x540($at)
    MEM_B(0X540, ctx->r1) = 0;
L_80069CA0:
    // 0x80069CA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069CA4: lbu         $a0, -0x10DF($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X10DF);
    // 0x80069CA8: jal         0x80072300
    // 0x80069CAC: nop

    Landfill_FlagIfCurrentPlayer(rdram, ctx);
        goto after_24;
    // 0x80069CAC: nop

    after_24:
    // 0x80069CB0: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80069CB4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80069CB8: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80069CBC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80069CC0: nop

    // 0x80069CC4: sb          $zero, 0x2($t9)
    MEM_B(0X2, ctx->r25) = 0;
    // 0x80069CC8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80069CCC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80069CD0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80069CD4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80069CD8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80069CDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80069CE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80069CE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80069CE8: jr          $ra
    // 0x80069CEC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80069CEC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}

RECOMP_FUNC void LineScan_IsRowFull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069CF0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80069CF4: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x80069CF8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069CFC: lw          $t6, -0x430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X430);
    // 0x80069D00: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80069D04: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80069D08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80069D0C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80069D10: slti        $at, $a2, 0xA
    ctx->r1 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x80069D14: addu        $a3, $t6, $t8
    ctx->r7 = ADD32(ctx->r14, ctx->r24);
    // 0x80069D18: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80069D1C: beq         $at, $zero, L_80069D54
    if (ctx->r1 == 0) {
        // 0x80069D20: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80069D54;
    }
    // 0x80069D20: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80069D24:
    // 0x80069D24: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80069D28: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80069D2C: lbu         $t0, 0x1($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1);
    // 0x80069D30: nop

    // 0x80069D34: bne         $t0, $at, L_80069D44
    if (ctx->r8 != ctx->r1) {
        // 0x80069D38: nop
    
            goto L_80069D44;
    }
    // 0x80069D38: nop

    // 0x80069D3C: b           L_80069D58
    // 0x80069D40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80069D58;
    // 0x80069D40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80069D44:
    // 0x80069D44: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80069D48: slti        $at, $a2, 0xA
    ctx->r1 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x80069D4C: bne         $at, $zero, L_80069D24
    if (ctx->r1 != 0) {
        // 0x80069D50: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80069D24;
    }
    // 0x80069D50: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80069D54:
    // 0x80069D54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80069D58:
    // 0x80069D58: jr          $ra
    // 0x80069D5C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80069D5C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void LineScan_DetectFullLines(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069D60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80069D64: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80069D68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80069D6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80069D70: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80069D74: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80069D78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80069D7C: slti        $at, $s2, 0x14
    ctx->r1 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
    // 0x80069D80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80069D84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80069D88: beq         $at, $zero, L_80069DF0
    if (ctx->r1 == 0) {
        // 0x80069D8C: addiu       $s1, $s1, 0x3
        ctx->r17 = ADD32(ctx->r17, 0X3);
            goto L_80069DF0;
    }
    // 0x80069D8C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
L_80069D90:
    // 0x80069D90: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x80069D94: sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
    // 0x80069D98: beq         $t6, $zero, L_80069DE0
    if (ctx->r14 == 0) {
        // 0x80069D9C: nop
    
            goto L_80069DE0;
    }
    // 0x80069D9C: nop

    // 0x80069DA0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80069DA4: nop

    // 0x80069DA8: lbu         $t8, 0x3F4($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X3F4);
    // 0x80069DAC: nop

    // 0x80069DB0: slt         $at, $t8, $s2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80069DB4: bne         $at, $zero, L_80069DE0
    if (ctx->r1 != 0) {
        // 0x80069DB8: nop
    
            goto L_80069DE0;
    }
    // 0x80069DB8: nop

    // 0x80069DBC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80069DC0: jal         0x80069CF0
    // 0x80069DC4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LineScan_IsRowFull(rdram, ctx);
        goto after_0;
    // 0x80069DC4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80069DC8: beq         $v0, $zero, L_80069DDC
    if (ctx->r2 == 0) {
        // 0x80069DCC: nop
    
            goto L_80069DDC;
    }
    // 0x80069DCC: nop

    // 0x80069DD0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80069DD4: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x80069DD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80069DDC:
    // 0x80069DDC: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_80069DE0:
    // 0x80069DE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80069DE4: slti        $at, $s2, 0x14
    ctx->r1 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
    // 0x80069DE8: bne         $at, $zero, L_80069D90
    if (ctx->r1 != 0) {
        // 0x80069DEC: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_80069D90;
    }
    // 0x80069DEC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_80069DF0:
    // 0x80069DF0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80069DF4: nop

    // 0x80069DF8: sw          $s0, 0x3F0($t0)
    MEM_W(0X3F0, ctx->r8) = ctx->r16;
    // 0x80069DFC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80069E00: nop

    // 0x80069E04: lw          $t2, 0x3EC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X3EC);
    // 0x80069E08: nop

    // 0x80069E0C: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80069E10: sw          $t3, 0x3EC($t1)
    MEM_W(0X3EC, ctx->r9) = ctx->r11;
    // 0x80069E14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80069E18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80069E1C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80069E20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80069E24: jr          $ra
    // 0x80069E28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80069E28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void LineScan_BeginLineClear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069E2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069E30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80069E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069E38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80069E3C: jal         0x80069D60
    // 0x80069E40: nop

    LineScan_DetectFullLines(rdram, ctx);
        goto after_0;
    // 0x80069E40: nop

    after_0:
    // 0x80069E44: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80069E48: nop

    // 0x80069E4C: lw          $t7, 0x3F0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3F0);
    // 0x80069E50: nop

    // 0x80069E54: bne         $t7, $zero, L_80069E68
    if (ctx->r15 != 0) {
        // 0x80069E58: nop
    
            goto L_80069E68;
    }
    // 0x80069E58: nop

    // 0x80069E5C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80069E60: b           L_80069E74
    // 0x80069E64: sb          $t8, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r24;
        goto L_80069E74;
    // 0x80069E64: sb          $t8, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r24;
L_80069E68:
    // 0x80069E68: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80069E6C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80069E70: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
L_80069E74:
    // 0x80069E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069E7C: jr          $ra
    // 0x80069E80: nop

    return;
    // 0x80069E80: nop

;}

RECOMP_FUNC void LineScan_MarkAllRowsDirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069E84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069E88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80069E8C: lw          $a0, -0x470($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X470);
    // 0x80069E90: slti        $at, $a1, 0x14
    ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    // 0x80069E94: beq         $at, $zero, L_80069EB8
    if (ctx->r1 == 0) {
        // 0x80069E98: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_80069EB8;
    }
    // 0x80069E98: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
L_80069E9C:
    // 0x80069E9C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80069EA0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80069EA4: slti        $at, $a1, 0x14
    ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    // 0x80069EA8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80069EAC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80069EB0: bne         $at, $zero, L_80069E9C
    if (ctx->r1 != 0) {
        // 0x80069EB4: sb          $t6, 0x3($t8)
        MEM_B(0X3, ctx->r24) = ctx->r14;
            goto L_80069E9C;
    }
    // 0x80069EB4: sb          $t6, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r14;
L_80069EB8:
    // 0x80069EB8: jr          $ra
    // 0x80069EBC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80069EBC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void LineScan_MarkRowsDirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069EC0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069EC4: lw          $a1, -0x490($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X490);
    // 0x80069EC8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069ECC: lw          $a0, -0x470($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X470);
    // 0x80069ED0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80069ED4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80069ED8: blez        $a2, L_80069F08
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80069EDC: addiu       $a1, $a1, 0x15
        ctx->r5 = ADD32(ctx->r5, 0X15);
            goto L_80069F08;
    }
    // 0x80069EDC: addiu       $a1, $a1, 0x15
    ctx->r5 = ADD32(ctx->r5, 0X15);
L_80069EE0:
    // 0x80069EE0: lb          $t8, 0x1($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X1);
    // 0x80069EE4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80069EE8: lw          $t7, -0x470($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X470);
    // 0x80069EEC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80069EF0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80069EF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80069EF8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80069EFC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80069F00: bgtz        $a2, L_80069EE0
    if (SIGNED(ctx->r6) > 0) {
        // 0x80069F04: sb          $t6, 0x3($t0)
        MEM_B(0X3, ctx->r8) = ctx->r14;
            goto L_80069EE0;
    }
    // 0x80069F04: sb          $t6, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r14;
L_80069F08:
    // 0x80069F08: jr          $ra
    // 0x80069F0C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80069F0C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void LineScan_SetScanLimit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069F14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80069F18: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x80069F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069F20: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x80069F24: bne         $at, $zero, L_80069F44
    if (ctx->r1 != 0) {
        // 0x80069F28: nop
    
            goto L_80069F44;
    }
    // 0x80069F28: nop

    // 0x80069F2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80069F30: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80069F34: addiu       $a1, $a1, -0x29A4
    ctx->r5 = ADD32(ctx->r5, -0X29A4);
    // 0x80069F38: addiu       $a0, $a0, -0x29C0
    ctx->r4 = ADD32(ctx->r4, -0X29C0);
    // 0x80069F3C: jal         0x8004A5A0
    // 0x80069F40: addiu       $a2, $zero, 0x129
    ctx->r6 = ADD32(0, 0X129);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_0;
    // 0x80069F40: addiu       $a2, $zero, 0x129
    ctx->r6 = ADD32(0, 0X129);
    after_0:
L_80069F44:
    // 0x80069F44: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069F48: lw          $t8, -0x470($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X470);
    // 0x80069F4C: lbu         $t7, 0x1B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1B);
    // 0x80069F50: nop

    // 0x80069F54: sb          $t7, 0x3F4($t8)
    MEM_B(0X3F4, ctx->r24) = ctx->r15;
    // 0x80069F58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069F5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069F60: jr          $ra
    // 0x80069F64: nop

    return;
    // 0x80069F64: nop

;}

RECOMP_FUNC void LineScan_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069F68: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069F6C: lw          $a0, -0x470($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X470);
    // 0x80069F70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80069F74: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x80069F78: slti        $at, $a1, 0x14
    ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    // 0x80069F7C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80069F80: sb          $t6, 0x3F4($a0)
    MEM_B(0X3F4, ctx->r4) = ctx->r14;
    // 0x80069F84: sw          $zero, 0x3EC($a0)
    MEM_W(0X3EC, ctx->r4) = 0;
    // 0x80069F88: sw          $zero, 0x3F0($a0)
    MEM_W(0X3F0, ctx->r4) = 0;
    // 0x80069F8C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80069F90: beq         $at, $zero, L_80069FB0
    if (ctx->r1 == 0) {
        // 0x80069F94: sb          $zero, 0x1($a0)
        MEM_B(0X1, ctx->r4) = 0;
            goto L_80069FB0;
    }
    // 0x80069F94: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_80069F98:
    // 0x80069F98: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80069F9C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80069FA0: slti        $at, $a1, 0x14
    ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    // 0x80069FA4: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80069FA8: bne         $at, $zero, L_80069F98
    if (ctx->r1 != 0) {
        // 0x80069FAC: sb          $zero, 0x3($t8)
        MEM_B(0X3, ctx->r24) = 0;
            goto L_80069F98;
    }
    // 0x80069FAC: sb          $zero, 0x3($t8)
    MEM_B(0X3, ctx->r24) = 0;
L_80069FB0:
    // 0x80069FB0: jr          $ra
    // 0x80069FB4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80069FB4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void LineScan_ProcessLineClears(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069FB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80069FBC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80069FC0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80069FC4: lw          $s0, -0x470($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X470);
    // 0x80069FC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80069FCC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80069FD0: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_80069FD4:
    // 0x80069FD4: lbu         $s1, 0x0($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X0);
    // 0x80069FD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80069FDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80069FE0: beq         $s1, $at, L_8006A004
    if (ctx->r17 == ctx->r1) {
        // 0x80069FE4: sb          $t6, 0x2($s0)
        MEM_B(0X2, ctx->r16) = ctx->r14;
            goto L_8006A004;
    }
    // 0x80069FE4: sb          $t6, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r14;
    // 0x80069FE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80069FEC: beq         $s1, $at, L_8006A014
    if (ctx->r17 == ctx->r1) {
        // 0x80069FF0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8006A014;
    }
    // 0x80069FF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80069FF4: beq         $s1, $at, L_8006A024
    if (ctx->r17 == ctx->r1) {
        // 0x80069FF8: nop
    
            goto L_8006A024;
    }
    // 0x80069FF8: nop

    // 0x80069FFC: b           L_8006A02C
    // 0x8006A000: nop

        goto L_8006A02C;
    // 0x8006A000: nop

L_8006A004:
    // 0x8006A004: jal         0x80069E2C
    // 0x8006A008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LineScan_BeginLineClear(rdram, ctx);
        goto after_0;
    // 0x8006A008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006A00C: b           L_8006A02C
    // 0x8006A010: nop

        goto L_8006A02C;
    // 0x8006A010: nop

L_8006A014:
    // 0x8006A014: jal         0x800698E0
    // 0x8006A018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LineScan_ExecuteLineClears(rdram, ctx);
        goto after_1;
    // 0x8006A018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8006A01C: b           L_8006A02C
    // 0x8006A020: nop

        goto L_8006A02C;
    // 0x8006A020: nop

L_8006A024:
    // 0x8006A024: jal         0x80069830
    // 0x8006A028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LineScan_UpdateLineEffects(rdram, ctx);
        goto after_2;
    // 0x8006A028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8006A02C:
    // 0x8006A02C: lbu         $t7, 0x2($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2);
    // 0x8006A030: nop

    // 0x8006A034: beq         $t7, $zero, L_80069FD4
    if (ctx->r15 == 0) {
        // 0x8006A038: nop
    
            goto L_80069FD4;
    }
    // 0x8006A038: nop

    // 0x8006A03C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A040: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006A044: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006A048: jr          $ra
    // 0x8006A04C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006A04C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

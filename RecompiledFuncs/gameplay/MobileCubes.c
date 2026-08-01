#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void MobileCubes_Move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EA40: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x8006EA44: lh          $t7, 0x14($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X14);
    // 0x8006EA48: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006EA4C: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    // 0x8006EA50: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8006EA54: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8006EA58: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006EA5C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8006EA60: slti        $at, $a1, -0x40
    ctx->r1 = SIGNED(ctx->r5) < -0X40 ? 1 : 0;
    // 0x8006EA64: bne         $at, $zero, L_8006EA84
    if (ctx->r1 != 0) {
        // 0x8006EA68: sb          $zero, 0x26($a0)
        MEM_B(0X26, ctx->r4) = 0;
            goto L_8006EA84;
    }
    // 0x8006EA68: sb          $zero, 0x26($a0)
    MEM_B(0X26, ctx->r4) = 0;
    // 0x8006EA6C: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x8006EA70: beq         $at, $zero, L_8006EA84
    if (ctx->r1 == 0) {
        // 0x8006EA74: nop
    
            goto L_8006EA84;
    }
    // 0x8006EA74: nop

    // 0x8006EA78: lh          $t0, 0x14($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X14);
    // 0x8006EA7C: b           L_8006EA8C
    // 0x8006EA80: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
        goto L_8006EA8C;
    // 0x8006EA80: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
L_8006EA84:
    // 0x8006EA84: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006EA88: sb          $t1, 0x26($a0)
    MEM_B(0X26, ctx->r4) = ctx->r9;
L_8006EA8C:
    // 0x8006EA8C: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x8006EA90: bne         $at, $zero, L_8006EAA8
    if (ctx->r1 != 0) {
        // 0x8006EA94: nop
    
            goto L_8006EAA8;
    }
    // 0x8006EA94: nop

    // 0x8006EA98: lh          $t2, 0x2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2);
    // 0x8006EA9C: nop

    // 0x8006EAA0: addiu       $t3, $t2, -0x40
    ctx->r11 = ADD32(ctx->r10, -0X40);
    // 0x8006EAA4: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
L_8006EAA8:
    // 0x8006EAA8: slti        $at, $a1, -0x40
    ctx->r1 = SIGNED(ctx->r5) < -0X40 ? 1 : 0;
    // 0x8006EAAC: beq         $at, $zero, L_8006EAC4
    if (ctx->r1 == 0) {
        // 0x8006EAB0: nop
    
            goto L_8006EAC4;
    }
    // 0x8006EAB0: nop

    // 0x8006EAB4: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x8006EAB8: nop

    // 0x8006EABC: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x8006EAC0: sh          $t5, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r13;
L_8006EAC4:
    // 0x8006EAC4: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x8006EAC8: lh          $t7, 0x1A($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1A);
    // 0x8006EACC: nop

    // 0x8006EAD0: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    // 0x8006EAD4: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8006EAD8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8006EADC: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006EAE0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8006EAE4: slti        $at, $a1, -0x40
    ctx->r1 = SIGNED(ctx->r5) < -0X40 ? 1 : 0;
    // 0x8006EAE8: bne         $at, $zero, L_8006EB04
    if (ctx->r1 != 0) {
        // 0x8006EAEC: slti        $at, $a1, 0x41
        ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
            goto L_8006EB04;
    }
    // 0x8006EAEC: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x8006EAF0: beq         $at, $zero, L_8006EB04
    if (ctx->r1 == 0) {
        // 0x8006EAF4: nop
    
            goto L_8006EB04;
    }
    // 0x8006EAF4: nop

    // 0x8006EAF8: lh          $t0, 0x1A($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X1A);
    // 0x8006EAFC: b           L_8006EB0C
    // 0x8006EB00: sh          $t0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r8;
        goto L_8006EB0C;
    // 0x8006EB00: sh          $t0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r8;
L_8006EB04:
    // 0x8006EB04: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006EB08: sb          $t1, 0x26($a0)
    MEM_B(0X26, ctx->r4) = ctx->r9;
L_8006EB0C:
    // 0x8006EB0C: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x8006EB10: bne         $at, $zero, L_8006EB28
    if (ctx->r1 != 0) {
        // 0x8006EB14: nop
    
            goto L_8006EB28;
    }
    // 0x8006EB14: nop

    // 0x8006EB18: lh          $t2, 0x8($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X8);
    // 0x8006EB1C: nop

    // 0x8006EB20: addiu       $t3, $t2, -0x40
    ctx->r11 = ADD32(ctx->r10, -0X40);
    // 0x8006EB24: sh          $t3, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r11;
L_8006EB28:
    // 0x8006EB28: slti        $at, $a1, -0x40
    ctx->r1 = SIGNED(ctx->r5) < -0X40 ? 1 : 0;
    // 0x8006EB2C: beq         $at, $zero, L_8006EB44
    if (ctx->r1 == 0) {
        // 0x8006EB30: nop
    
            goto L_8006EB44;
    }
    // 0x8006EB30: nop

    // 0x8006EB34: lh          $t4, 0x8($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X8);
    // 0x8006EB38: nop

    // 0x8006EB3C: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x8006EB40: sh          $t5, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r13;
L_8006EB44:
    // 0x8006EB44: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8006EB48: lh          $t7, 0x16($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X16);
    // 0x8006EB4C: nop

    // 0x8006EB50: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    // 0x8006EB54: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8006EB58: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8006EB5C: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006EB60: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8006EB64: slti        $at, $a1, -0x40
    ctx->r1 = SIGNED(ctx->r5) < -0X40 ? 1 : 0;
    // 0x8006EB68: bne         $at, $zero, L_8006EB84
    if (ctx->r1 != 0) {
        // 0x8006EB6C: slti        $at, $a1, 0x41
        ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
            goto L_8006EB84;
    }
    // 0x8006EB6C: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x8006EB70: beq         $at, $zero, L_8006EB84
    if (ctx->r1 == 0) {
        // 0x8006EB74: nop
    
            goto L_8006EB84;
    }
    // 0x8006EB74: nop

    // 0x8006EB78: lh          $t0, 0x16($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X16);
    // 0x8006EB7C: b           L_8006EB8C
    // 0x8006EB80: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
        goto L_8006EB8C;
    // 0x8006EB80: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
L_8006EB84:
    // 0x8006EB84: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006EB88: sb          $t1, 0x26($a0)
    MEM_B(0X26, ctx->r4) = ctx->r9;
L_8006EB8C:
    // 0x8006EB8C: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x8006EB90: bne         $at, $zero, L_8006EBA8
    if (ctx->r1 != 0) {
        // 0x8006EB94: nop
    
            goto L_8006EBA8;
    }
    // 0x8006EB94: nop

    // 0x8006EB98: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x8006EB9C: nop

    // 0x8006EBA0: addiu       $t3, $t2, -0x40
    ctx->r11 = ADD32(ctx->r10, -0X40);
    // 0x8006EBA4: sh          $t3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r11;
L_8006EBA8:
    // 0x8006EBA8: slti        $at, $a1, -0x40
    ctx->r1 = SIGNED(ctx->r5) < -0X40 ? 1 : 0;
    // 0x8006EBAC: beq         $at, $zero, L_8006EBC4
    if (ctx->r1 == 0) {
        // 0x8006EBB0: nop
    
            goto L_8006EBC4;
    }
    // 0x8006EBB0: nop

    // 0x8006EBB4: lh          $t4, 0x4($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4);
    // 0x8006EBB8: nop

    // 0x8006EBBC: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x8006EBC0: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
L_8006EBC4:
    // 0x8006EBC4: lh          $t6, 0xA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XA);
    // 0x8006EBC8: lh          $t7, 0x1C($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1C);
    // 0x8006EBCC: nop

    // 0x8006EBD0: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    // 0x8006EBD4: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8006EBD8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8006EBDC: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006EBE0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8006EBE4: slti        $at, $a1, -0x40
    ctx->r1 = SIGNED(ctx->r5) < -0X40 ? 1 : 0;
    // 0x8006EBE8: bne         $at, $zero, L_8006EC04
    if (ctx->r1 != 0) {
        // 0x8006EBEC: slti        $at, $a1, 0x41
        ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
            goto L_8006EC04;
    }
    // 0x8006EBEC: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x8006EBF0: beq         $at, $zero, L_8006EC04
    if (ctx->r1 == 0) {
        // 0x8006EBF4: nop
    
            goto L_8006EC04;
    }
    // 0x8006EBF4: nop

    // 0x8006EBF8: lh          $t0, 0x1C($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X1C);
    // 0x8006EBFC: b           L_8006EC0C
    // 0x8006EC00: sh          $t0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r8;
        goto L_8006EC0C;
    // 0x8006EC00: sh          $t0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r8;
L_8006EC04:
    // 0x8006EC04: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006EC08: sb          $t1, 0x26($a0)
    MEM_B(0X26, ctx->r4) = ctx->r9;
L_8006EC0C:
    // 0x8006EC0C: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x8006EC10: bne         $at, $zero, L_8006EC28
    if (ctx->r1 != 0) {
        // 0x8006EC14: nop
    
            goto L_8006EC28;
    }
    // 0x8006EC14: nop

    // 0x8006EC18: lh          $t2, 0xA($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XA);
    // 0x8006EC1C: nop

    // 0x8006EC20: addiu       $t3, $t2, -0x40
    ctx->r11 = ADD32(ctx->r10, -0X40);
    // 0x8006EC24: sh          $t3, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r11;
L_8006EC28:
    // 0x8006EC28: slti        $at, $a1, -0x40
    ctx->r1 = SIGNED(ctx->r5) < -0X40 ? 1 : 0;
    // 0x8006EC2C: beq         $at, $zero, L_8006EC44
    if (ctx->r1 == 0) {
        // 0x8006EC30: nop
    
            goto L_8006EC44;
    }
    // 0x8006EC30: nop

    // 0x8006EC34: lh          $t4, 0xA($a0)
    ctx->r12 = MEM_H(ctx->r4, 0XA);
    // 0x8006EC38: nop

    // 0x8006EC3C: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x8006EC40: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
L_8006EC44:
    // 0x8006EC44: jr          $ra
    // 0x8006EC48: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006EC48: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void MobileCubes_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EC4C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006EC50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006EC54: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006EC58: lw          $s0, -0x410($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X410);
    // 0x8006EC5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006EC60: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006EC64: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006EC68: lbu         $s2, 0x5($s0)
    ctx->r18 = MEM_BU(ctx->r16, 0X5);
    // 0x8006EC6C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8006EC70: beq         $s2, $zero, L_8006ECA8
    if (ctx->r18 == 0) {
        // 0x8006EC74: nop
    
            goto L_8006ECA8;
    }
    // 0x8006EC74: nop

L_8006EC78:
    // 0x8006EC78: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x8006EC7C: nop

    // 0x8006EC80: bne         $t6, $zero, L_8006EC90
    if (ctx->r14 != 0) {
        // 0x8006EC84: nop
    
            goto L_8006EC90;
    }
    // 0x8006EC84: nop

    // 0x8006EC88: b           L_8006ECA0
    // 0x8006EC8C: addiu       $s1, $s1, 0x160
    ctx->r17 = ADD32(ctx->r17, 0X160);
        goto L_8006ECA0;
    // 0x8006EC8C: addiu       $s1, $s1, 0x160
    ctx->r17 = ADD32(ctx->r17, 0X160);
L_8006EC90:
    // 0x8006EC90: jal         0x8006EA40
    // 0x8006EC94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    MobileCubes_Move(rdram, ctx);
        goto after_0;
    // 0x8006EC94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8006EC98: addiu       $s1, $s1, 0x160
    ctx->r17 = ADD32(ctx->r17, 0X160);
    // 0x8006EC9C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8006ECA0:
    // 0x8006ECA0: bne         $s2, $zero, L_8006EC78
    if (ctx->r18 != 0) {
        // 0x8006ECA4: nop
    
            goto L_8006EC78;
    }
    // 0x8006ECA4: nop

L_8006ECA8:
    // 0x8006ECA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006ECAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006ECB0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ECB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006ECB8: jr          $ra
    // 0x8006ECBC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006ECBC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void MobileCubes_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECC0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006ECC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006ECC8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006ECCC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006ECD0: lw          $s0, -0x410($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X410);
    // 0x8006ECD4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006ECD8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006ECDC: jal         0x80070D00
    // 0x8006ECE0: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    Minos_SetScale(rdram, ctx);
        goto after_0;
    // 0x8006ECE0: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_0:
    // 0x8006ECE4: lbu         $a0, 0x6($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X6);
    // 0x8006ECE8: jal         0x80070D30
    // 0x8006ECEC: nop

    Minos_SetAlpha(rdram, ctx);
        goto after_1;
    // 0x8006ECEC: nop

    after_1:
    // 0x8006ECF0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8006ECF4: jal         0x80070EC8
    // 0x8006ECF8: nop

    Minos_BeginRender(rdram, ctx);
        goto after_2;
    // 0x8006ECF8: nop

    after_2:
    // 0x8006ECFC: jal         0x8007116C
    // 0x8006ED00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Minos_SetVtxTransform(rdram, ctx);
        goto after_3;
    // 0x8006ED00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8006ED04: lbu         $s2, 0x5($s0)
    ctx->r18 = MEM_BU(ctx->r16, 0X5);
    // 0x8006ED08: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8006ED0C: beq         $s2, $zero, L_8006ED70
    if (ctx->r18 == 0) {
        // 0x8006ED10: nop
    
            goto L_8006ED70;
    }
    // 0x8006ED10: nop

L_8006ED14:
    // 0x8006ED14: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x8006ED18: nop

    // 0x8006ED1C: bne         $t6, $zero, L_8006ED2C
    if (ctx->r14 != 0) {
        // 0x8006ED20: nop
    
            goto L_8006ED2C;
    }
    // 0x8006ED20: nop

    // 0x8006ED24: b           L_8006ED68
    // 0x8006ED28: addiu       $s1, $s1, 0x160
    ctx->r17 = ADD32(ctx->r17, 0X160);
        goto L_8006ED68;
    // 0x8006ED28: addiu       $s1, $s1, 0x160
    ctx->r17 = ADD32(ctx->r17, 0X160);
L_8006ED2C:
    // 0x8006ED2C: lbu         $t7, 0x26($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X26);
    // 0x8006ED30: nop

    // 0x8006ED34: beq         $t7, $zero, L_8006ED4C
    if (ctx->r15 == 0) {
        // 0x8006ED38: nop
    
            goto L_8006ED4C;
    }
    // 0x8006ED38: nop

    // 0x8006ED3C: lbu         $t8, 0x29($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X29);
    // 0x8006ED40: nop

    // 0x8006ED44: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8006ED48: sb          $t9, 0x29($s1)
    MEM_B(0X29, ctx->r17) = ctx->r25;
L_8006ED4C:
    // 0x8006ED4C: jal         0x80070528
    // 0x8006ED50: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    Minos_Mino_Morph(rdram, ctx);
        goto after_4;
    // 0x8006ED50: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    after_4:
    // 0x8006ED54: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x8006ED58: jal         0x8006FE38
    // 0x8006ED5C: addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    Minos_Mino_Render(rdram, ctx);
        goto after_5;
    // 0x8006ED5C: addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    after_5:
    // 0x8006ED60: addiu       $s1, $s1, 0x160
    ctx->r17 = ADD32(ctx->r17, 0X160);
    // 0x8006ED64: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8006ED68:
    // 0x8006ED68: bne         $s2, $zero, L_8006ED14
    if (ctx->r18 != 0) {
        // 0x8006ED6C: nop
    
            goto L_8006ED14;
    }
    // 0x8006ED6C: nop

L_8006ED70:
    // 0x8006ED70: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8006ED74: jal         0x80070F70
    // 0x8006ED78: nop

    Minos_EndRender(rdram, ctx);
        goto after_6;
    // 0x8006ED78: nop

    after_6:
    // 0x8006ED7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006ED80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006ED84: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ED88: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006ED8C: jr          $ra
    // 0x8006ED90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006ED90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void MobileCubes_Alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED94: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006ED98: lw          $a0, -0x410($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X410);
    // 0x8006ED9C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8006EDA0: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8006EDA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006EDA8: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x8006EDAC: nop

    // 0x8006EDB0: beq         $t6, $zero, L_8006EDF0
    if (ctx->r14 == 0) {
        // 0x8006EDB4: nop
    
            goto L_8006EDF0;
    }
    // 0x8006EDB4: nop

    // 0x8006EDB8: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x8006EDBC: nop

    // 0x8006EDC0: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8006EDC4: beq         $at, $zero, L_8006EDF0
    if (ctx->r1 == 0) {
        // 0x8006EDC8: nop
    
            goto L_8006EDF0;
    }
    // 0x8006EDC8: nop

L_8006EDCC:
    // 0x8006EDCC: lbu         $t8, 0x160($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X160);
    // 0x8006EDD0: addiu       $a2, $a2, 0x160
    ctx->r6 = ADD32(ctx->r6, 0X160);
    // 0x8006EDD4: beq         $t8, $zero, L_8006EDF0
    if (ctx->r24 == 0) {
        // 0x8006EDD8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8006EDF0;
    }
    // 0x8006EDD8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006EDDC: lbu         $t9, 0x4($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X4);
    // 0x8006EDE0: nop

    // 0x8006EDE4: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8006EDE8: bne         $at, $zero, L_8006EDCC
    if (ctx->r1 != 0) {
        // 0x8006EDEC: nop
    
            goto L_8006EDCC;
    }
    // 0x8006EDEC: nop

L_8006EDF0:
    // 0x8006EDF0: lbu         $t0, 0x5($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X5);
    // 0x8006EDF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006EDF8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8006EDFC: sb          $t1, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r9;
    // 0x8006EE00: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8006EE04: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8006EE08: jr          $ra
    // 0x8006EE0C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x8006EE0C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
;}

RECOMP_FUNC void MobileCubes_Unalloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE10: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006EE14: lw          $a1, -0x410($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X410);
    // 0x8006EE18: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8006EE1C: lbu         $t6, 0x5($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X5);
    // 0x8006EE20: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006EE24: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006EE28: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8006EE2C: jr          $ra
    // 0x8006EE30: sb          $t7, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r15;
    return;
    // 0x8006EE30: sb          $t7, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r15;
;}

RECOMP_FUNC void MobileCubes_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE34: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006EE38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006EE3C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006EE40: lw          $s0, -0x410($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X410);
    // 0x8006EE44: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8006EE48: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8006EE4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006EE50: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006EE54: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006EE58: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006EE5C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8006EE60: sb          $t7, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r15;
    // 0x8006EE64: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x8006EE68: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    // 0x8006EE6C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006EE70: nop

    // 0x8006EE74: sb          $t8, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r24;
    // 0x8006EE78: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8006EE7C: nop

    // 0x8006EE80: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8006EE84: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8006EE88: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8006EE8C: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8006EE90: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8006EE94: jal         0x8007E03C
    // 0x8006EE98: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8006EE98: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x8006EE9C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8006EEA0: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8006EEA4: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x8006EEA8: blez        $s1, L_8006EEC0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8006EEAC: nop
    
            goto L_8006EEC0;
    }
    // 0x8006EEAC: nop

L_8006EEB0:
    // 0x8006EEB0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8006EEB4: addiu       $s2, $s2, 0x160
    ctx->r18 = ADD32(ctx->r18, 0X160);
    // 0x8006EEB8: bgtz        $s1, L_8006EEB0
    if (SIGNED(ctx->r17) > 0) {
        // 0x8006EEBC: sb          $zero, -0x160($s2)
        MEM_B(-0X160, ctx->r18) = 0;
            goto L_8006EEB0;
    }
    // 0x8006EEBC: sb          $zero, -0x160($s2)
    MEM_B(-0X160, ctx->r18) = 0;
L_8006EEC0:
    // 0x8006EEC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006EEC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006EEC8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EECC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006EED0: jr          $ra
    // 0x8006EED4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006EED4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void MobileCubes_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EED8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006EEDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006EEE0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006EEE4: lw          $s0, -0x410($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X410);
    // 0x8006EEE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006EEEC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006EEF0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006EEF4: lbu         $s1, 0x4($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X4);
    // 0x8006EEF8: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x8006EEFC: blez        $s1, L_8006EF10
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8006EF00: nop
    
            goto L_8006EF10;
    }
    // 0x8006EF00: nop

L_8006EF04:
    // 0x8006EF04: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8006EF08: bgtz        $s1, L_8006EF04
    if (SIGNED(ctx->r17) > 0) {
        // 0x8006EF0C: addiu       $s2, $s2, 0x160
        ctx->r18 = ADD32(ctx->r18, 0X160);
            goto L_8006EF04;
    }
    // 0x8006EF0C: addiu       $s2, $s2, 0x160
    ctx->r18 = ADD32(ctx->r18, 0X160);
L_8006EF10:
    // 0x8006EF10: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006EF14: jal         0x8007E328
    // 0x8006EF18: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x8006EF18: nop

    after_0:
    // 0x8006EF1C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8006EF20: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x8006EF24: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x8006EF28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006EF2C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006EF30: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EF34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006EF38: jr          $ra
    // 0x8006EF3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006EF3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

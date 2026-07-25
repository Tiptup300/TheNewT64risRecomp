#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void EndScroller_AdvanceLineScroll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FDB0: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x8007FDB4: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x8007FDB8: nop

    // 0x8007FDBC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007FDC0: bgez        $t8, L_8007FDD0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007FDC4: nop
    
            goto L_8007FDD0;
    }
    // 0x8007FDC4: nop

    // 0x8007FDC8: jr          $ra
    // 0x8007FDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007FDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007FDD0:
    // 0x8007FDD0: lw          $t9, 0x18($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X18);
    // 0x8007FDD4: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x8007FDD8: nop

    // 0x8007FDDC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8007FDE0: slti        $at, $t1, 0x12C
    ctx->r1 = SIGNED(ctx->r9) < 0X12C ? 1 : 0;
    // 0x8007FDE4: bne         $at, $zero, L_8007FE1C
    if (ctx->r1 != 0) {
        // 0x8007FDE8: nop
    
            goto L_8007FE1C;
    }
    // 0x8007FDE8: nop

    // 0x8007FDEC: lw          $t2, 0x18($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X18);
    // 0x8007FDF0: lw          $t5, 0x10($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X10);
    // 0x8007FDF4: subu        $t3, $t2, $a1
    ctx->r11 = SUB32(ctx->r10, ctx->r5);
    // 0x8007FDF8: sw          $t3, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r11;
    // 0x8007FDFC: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x8007FE00: nop

    // 0x8007FE04: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8007FE08: slti        $at, $t6, 0x12C
    ctx->r1 = SIGNED(ctx->r14) < 0X12C ? 1 : 0;
    // 0x8007FE0C: beq         $at, $zero, L_8007FE48
    if (ctx->r1 == 0) {
        // 0x8007FE10: nop
    
            goto L_8007FE48;
    }
    // 0x8007FE10: nop

    // 0x8007FE14: jr          $ra
    // 0x8007FE18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x8007FE18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8007FE1C:
    // 0x8007FE1C: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x8007FE20: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x8007FE24: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x8007FE28: sw          $t8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r24;
    // 0x8007FE2C: lw          $t9, 0x18($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X18);
    // 0x8007FE30: nop

    // 0x8007FE34: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8007FE38: bgez        $t1, L_8007FE48
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8007FE3C: nop
    
            goto L_8007FE48;
    }
    // 0x8007FE3C: nop

    // 0x8007FE40: jr          $ra
    // 0x8007FE44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8007FE44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007FE48:
    // 0x8007FE48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007FE4C: jr          $ra
    // 0x8007FE50: nop

    return;
    // 0x8007FE50: nop

;}

RECOMP_FUNC void EndScroller_DrawLine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FE54: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007FE58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007FE5C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007FE60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007FE64: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x8007FE68: nop

    // 0x8007FE6C: slti        $at, $t7, 0x12C
    ctx->r1 = SIGNED(ctx->r15) < 0X12C ? 1 : 0;
    // 0x8007FE70: beq         $at, $zero, L_8007FEE4
    if (ctx->r1 == 0) {
        // 0x8007FE74: nop
    
            goto L_8007FEE4;
    }
    // 0x8007FE74: nop

    // 0x8007FE78: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007FE7C: nop

    // 0x8007FE80: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8007FE84: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x8007FE88: nop

    // 0x8007FE8C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8007FE90: bltz        $t1, L_8007FEE4
    if (SIGNED(ctx->r9) < 0) {
        // 0x8007FE94: nop
    
            goto L_8007FEE4;
    }
    // 0x8007FE94: nop

    // 0x8007FE98: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007FE9C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8007FEA0: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x8007FEA4: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8007FEA8: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    // 0x8007FEAC: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x8007FEB0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8007FEB4: lw          $t4, 0x18($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X18);
    // 0x8007FEB8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8007FEBC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8007FEC0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8007FEC4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8007FEC8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8007FECC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8007FED0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8007FED4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8007FED8: addiu       $a3, $a3, 0x20C0
    ctx->r7 = ADD32(ctx->r7, 0X20C0);
    // 0x8007FEDC: jal         0x80078244
    // 0x8007FEE0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    displayText_DrawStringN(rdram, ctx);
        goto after_0;
    // 0x8007FEE0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_0:
L_8007FEE4:
    // 0x8007FEE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007FEE8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007FEEC: jr          $ra
    // 0x8007FEF0: nop

    return;
    // 0x8007FEF0: nop

;}

RECOMP_FUNC void EndScroller_font_size_scrolltext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FEF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007FEF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007FEFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007FF00: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007FF04: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8007FF08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FF0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007FF10: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8007FF14: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007FF18: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8007FF1C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8007FF20: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8007FF24: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8007FF28: jal         0x80080AB8
    // 0x8007FF2C: nop

    strutil_linelen(rdram, ctx);
        goto after_0;
    // 0x8007FF2C: nop

    after_0:
    // 0x8007FF30: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8007FF34: nop

    // 0x8007FF38: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x8007FF3C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8007FF40: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8007FF44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007FF48: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x8007FF4C: jal         0x800781A8
    // 0x8007FF50: nop

    Font_MeasureChars(rdram, ctx);
        goto after_1;
    // 0x8007FF50: nop

    after_1:
    // 0x8007FF54: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8007FF58: addiu       $t9, $zero, 0x190
    ctx->r25 = ADD32(0, 0X190);
    // 0x8007FF5C: sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
    // 0x8007FF60: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8007FF64: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8007FF68: lh          $t4, 0x76($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X76);
    // 0x8007FF6C: addiu       $t2, $zero, 0x12C
    ctx->r10 = ADD32(0, 0X12C);
    // 0x8007FF70: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x8007FF74: sw          $t5, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r13;
    // 0x8007FF78: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8007FF7C: nop

    // 0x8007FF80: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8007FF84: nop

    // 0x8007FF88: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x8007FF8C: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007FF90: sw          $t1, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r9;
    // 0x8007FF94: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8007FF98: nop

    // 0x8007FF9C: sw          $t2, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r10;
    // 0x8007FFA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FFA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007FFA8: jr          $ra
    // 0x8007FFAC: nop

    return;
    // 0x8007FFAC: nop

;}

RECOMP_FUNC void EndScroller_DeinitLine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FFB0: jr          $ra
    // 0x8007FFB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8007FFB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

RECOMP_FUNC void EndScroller_CheckSkipInput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FFB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007FFBC: addiu       $t6, $t6, -0x10D0
    ctx->r14 = ADD32(ctx->r14, -0X10D0);
    // 0x8007FFC0: lw          $a1, 0x24($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X24);
    // 0x8007FFC4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007FFC8: andi        $t7, $a1, 0x8000
    ctx->r15 = ctx->r5 & 0X8000;
    // 0x8007FFCC: beq         $t7, $zero, L_8007FFDC
    if (ctx->r15 == 0) {
        // 0x8007FFD0: nop
    
            goto L_8007FFDC;
    }
    // 0x8007FFD0: nop

    // 0x8007FFD4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007FFD8: sb          $t8, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r24;
L_8007FFDC:
    // 0x8007FFDC: jr          $ra
    // 0x8007FFE0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007FFE0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void EndScroller_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FFE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007FFE8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007FFEC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8007FFF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007FFF4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8007FFF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007FFFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80080000: jal         0x800804F0
    // 0x80080004: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    EndScroller_InitBackground(rdram, ctx);
        goto after_0;
    // 0x80080004: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    after_0:
    // 0x80080008: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008000C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80080010: jal         0x80077408
    // 0x80080014: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    Font_Init46Char(rdram, ctx);
        goto after_1;
    // 0x80080014: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80080018: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008001C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80080020: jal         0x80077408
    // 0x80080024: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    Font_Init46Char(rdram, ctx);
        goto after_2;
    // 0x80080024: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    after_2:
    // 0x80080028: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8008002C: jal         0x80080B08
    // 0x80080030: nop

    strutil_linecnt(rdram, ctx);
        goto after_3;
    // 0x80080030: nop

    after_3:
    // 0x80080034: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80080038: nop

    // 0x8008003C: sw          $v0, 0xF4($t6)
    MEM_W(0XF4, ctx->r14) = ctx->r2;
    // 0x80080040: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80080044: nop

    // 0x80080048: lw          $a0, 0xF4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XF4);
    // 0x8008004C: nop

    // 0x80080050: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x80080054: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80080058: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008005C: jal         0x8007E03C
    // 0x80080060: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x80080060: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_4:
    // 0x80080064: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80080068: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008006C: sw          $v0, 0xF8($t9)
    MEM_W(0XF8, ctx->r25) = ctx->r2;
    // 0x80080070: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80080074: addiu       $a0, $a0, -0x16F0
    ctx->r4 = ADD32(ctx->r4, -0X16F0);
    // 0x80080078: lw          $a1, 0xF4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XF4);
    // 0x8008007C: jal         0x800B3BFC
    // 0x80080080: nop

    rmonPrintf_recomp(rdram, ctx);
        goto after_5;
    // 0x80080080: nop

    after_5:
    // 0x80080084: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80080088: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008008C: lw          $a1, 0xF8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XF8);
    // 0x80080090: jal         0x800B3BFC
    // 0x80080094: addiu       $a0, $a0, -0x16CC
    ctx->r4 = ADD32(ctx->r4, -0X16CC);
    rmonPrintf_recomp(rdram, ctx);
        goto after_6;
    // 0x80080094: addiu       $a0, $a0, -0x16CC
    ctx->r4 = ADD32(ctx->r4, -0X16CC);
    after_6:
    // 0x80080098: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8008009C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800800A0: lw          $s1, 0xF8($t2)
    ctx->r17 = MEM_W(ctx->r10, 0XF8);
    // 0x800800A4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800800A8: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x800800AC: nop

    // 0x800800B0: beq         $t3, $zero, L_80080118
    if (ctx->r11 == 0) {
        // 0x800800B4: nop
    
            goto L_80080118;
    }
    // 0x800800B4: nop

L_800800B8:
    // 0x800800B8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800800BC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800800C0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800800C4: lbu         $t6, 0x3200($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3200);
    // 0x800800C8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800800CC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800800D0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800800D4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800800D8: addu        $a2, $t4, $t7
    ctx->r6 = ADD32(ctx->r12, ctx->r15);
    // 0x800800DC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800800E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800800E4: jal         0x8007FEF4
    // 0x800800E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    EndScroller_font_size_scrolltext(rdram, ctx);
        goto after_7;
    // 0x800800E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800800EC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800800F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800800F4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800800F8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800800FC: jal         0x80080A70
    // 0x80080100: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    strutil_nextline(rdram, ctx);
        goto after_8;
    // 0x80080100: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_8:
    // 0x80080104: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80080108: lbu         $t0, 0x1($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1);
    // 0x8008010C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80080110: bne         $t0, $zero, L_800800B8
    if (ctx->r8 != 0) {
        // 0x80080114: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_800800B8;
    }
    // 0x80080114: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_80080118:
    // 0x80080118: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8008011C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80080120: sw          $zero, 0xFC($t1)
    MEM_W(0XFC, ctx->r9) = 0;
    // 0x80080124: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80080128: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008012C: sw          $zero, 0x100($t2)
    MEM_W(0X100, ctx->r10) = 0;
    // 0x80080130: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80080134: addiu       $a0, $a0, -0x16B0
    ctx->r4 = ADD32(ctx->r4, -0X16B0);
    // 0x80080138: sb          $t3, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r11;
    // 0x8008013C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80080140: jal         0x800B3BFC
    // 0x80080144: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_9;
    // 0x80080144: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    after_9:
    // 0x80080148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008014C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80080150: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80080154: jr          $ra
    // 0x80080158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80080158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void EndScroller_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008015C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80080160: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80080164: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80080168: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008016C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80080170: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80080174: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80080178: nop

    // 0x8008017C: bne         $t7, $zero, L_8008019C
    if (ctx->r15 != 0) {
        // 0x80080180: nop
    
            goto L_8008019C;
    }
    // 0x80080180: nop

    // 0x80080184: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080188: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008018C: addiu       $a1, $a1, -0x167C
    ctx->r5 = ADD32(ctx->r5, -0X167C);
    // 0x80080190: addiu       $a0, $a0, -0x1694
    ctx->r4 = ADD32(ctx->r4, -0X1694);
    // 0x80080194: jal         0x8004A5A0
    // 0x80080198: addiu       $a2, $zero, 0x1A0
    ctx->r6 = ADD32(0, 0X1A0);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_0;
    // 0x80080198: addiu       $a2, $zero, 0x1A0
    ctx->r6 = ADD32(0, 0X1A0);
    after_0:
L_8008019C:
    // 0x8008019C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800801A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800801A4: lw          $t9, 0xF4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XF4);
    // 0x800801A8: lw          $s1, 0xF8($t8)
    ctx->r17 = MEM_W(ctx->r24, 0XF8);
    // 0x800801AC: sltu        $at, $s0, $t9
    ctx->r1 = ctx->r16 < ctx->r25 ? 1 : 0;
    // 0x800801B0: beq         $at, $zero, L_800801DC
    if (ctx->r1 == 0) {
        // 0x800801B4: nop
    
            goto L_800801DC;
    }
    // 0x800801B4: nop

L_800801B8:
    // 0x800801B8: jal         0x8007FFB0
    // 0x800801BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    EndScroller_DeinitLine(rdram, ctx);
        goto after_1;
    // 0x800801BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800801C0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800801C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800801C8: lw          $t1, 0xF4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XF4);
    // 0x800801CC: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x800801D0: sltu        $at, $s0, $t1
    ctx->r1 = ctx->r16 < ctx->r9 ? 1 : 0;
    // 0x800801D4: bne         $at, $zero, L_800801B8
    if (ctx->r1 != 0) {
        // 0x800801D8: nop
    
            goto L_800801B8;
    }
    // 0x800801D8: nop

L_800801DC:
    // 0x800801DC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800801E0: nop

    // 0x800801E4: lw          $a0, 0xF8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XF8);
    // 0x800801E8: jal         0x8007E328
    // 0x800801EC: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_2;
    // 0x800801EC: nop

    after_2:
    // 0x800801F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800801F4: jal         0x800773D0
    // 0x800801F8: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    Font_Deinit(rdram, ctx);
        goto after_3;
    // 0x800801F8: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    after_3:
    // 0x800801FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80080200: jal         0x800773D0
    // 0x80080204: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    Font_Deinit(rdram, ctx);
        goto after_4;
    // 0x80080204: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x80080208: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008020C: jal         0x8008074C
    // 0x80080210: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    EndScroller_DeinitBackground(rdram, ctx);
        goto after_5;
    // 0x80080210: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    after_5:
    // 0x80080214: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80080218: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008021C: addiu       $a0, $a0, -0x166C
    ctx->r4 = ADD32(ctx->r4, -0X166C);
    // 0x80080220: jal         0x800B3BFC
    // 0x80080224: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_6;
    // 0x80080224: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
    after_6:
    // 0x80080228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008022C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80080230: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80080234: jr          $ra
    // 0x80080238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80080238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void EndScroller_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008023C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80080240: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80080244: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80080248: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008024C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80080250: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80080254: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80080258: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008025C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80080260: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80080264: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80080268: nop

    // 0x8008026C: bne         $t7, $zero, L_8008028C
    if (ctx->r15 != 0) {
        // 0x80080270: nop
    
            goto L_8008028C;
    }
    // 0x80080270: nop

    // 0x80080274: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080278: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008027C: addiu       $a1, $a1, -0x1634
    ctx->r5 = ADD32(ctx->r5, -0X1634);
    // 0x80080280: addiu       $a0, $a0, -0x164C
    ctx->r4 = ADD32(ctx->r4, -0X164C);
    // 0x80080284: jal         0x8004A5A0
    // 0x80080288: addiu       $a2, $zero, 0x1C4
    ctx->r6 = ADD32(0, 0X1C4);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_0;
    // 0x80080288: addiu       $a2, $zero, 0x1C4
    ctx->r6 = ADD32(0, 0X1C4);
    after_0:
L_8008028C:
    // 0x8008028C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80080290: jal         0x8007FFB8
    // 0x80080294: nop

    EndScroller_CheckSkipInput(rdram, ctx);
        goto after_1;
    // 0x80080294: nop

    after_1:
    // 0x80080298: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008029C: nop

    // 0x800802A0: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x800802A4: nop

    // 0x800802A8: beq         $t9, $zero, L_800802B8
    if (ctx->r25 == 0) {
        // 0x800802AC: nop
    
            goto L_800802B8;
    }
    // 0x800802AC: nop

    // 0x800802B0: b           L_800803E4
    // 0x800802B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800803E4;
    // 0x800802B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800802B8:
    // 0x800802B8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800802BC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800802C0: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    // 0x800802C4: jal         0x8008080C
    // 0x800802C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    EndScroller_AdvanceBackgroundRotation(rdram, ctx);
        goto after_2;
    // 0x800802C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_2:
    // 0x800802CC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800802D0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800802D4: nop

    // 0x800802D8: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800802DC: beq         $at, $zero, L_800803E0
    if (ctx->r1 == 0) {
        // 0x800802E0: nop
    
            goto L_800803E0;
    }
    // 0x800802E0: nop

L_800802E4:
    // 0x800802E4: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800802E8: nop

    // 0x800802EC: lw          $s0, 0xFC($t2)
    ctx->r16 = MEM_W(ctx->r10, 0XFC);
    // 0x800802F0: lw          $t5, 0x100($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X100);
    // 0x800802F4: sll         $t4, $s0, 3
    ctx->r12 = S32(ctx->r16 << 3);
    // 0x800802F8: lw          $t3, 0xF8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XF8);
    // 0x800802FC: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x80080300: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80080304: sltu        $at, $t5, $s0
    ctx->r1 = ctx->r13 < ctx->r16 ? 1 : 0;
    // 0x80080308: bne         $at, $zero, L_800803A0
    if (ctx->r1 != 0) {
        // 0x8008030C: addu        $s1, $t3, $t4
        ctx->r17 = ADD32(ctx->r11, ctx->r12);
            goto L_800803A0;
    }
    // 0x8008030C: addu        $s1, $t3, $t4
    ctx->r17 = ADD32(ctx->r11, ctx->r12);
L_80080310:
    // 0x80080310: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80080314: jal         0x8007FDB0
    // 0x80080318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    EndScroller_AdvanceLineScroll(rdram, ctx);
        goto after_3;
    // 0x80080318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8008031C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80080320: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x80080324: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80080328: beq         $s3, $at, L_80080340
    if (ctx->r19 == ctx->r1) {
        // 0x8008032C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80080340;
    }
    // 0x8008032C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80080330: beq         $s3, $at, L_8008035C
    if (ctx->r19 == ctx->r1) {
        // 0x80080334: nop
    
            goto L_8008035C;
    }
    // 0x80080334: nop

    // 0x80080338: b           L_80080384
    // 0x8008033C: nop

        goto L_80080384;
    // 0x8008033C: nop

L_80080340:
    // 0x80080340: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80080344: nop

    // 0x80080348: lw          $t7, 0xFC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XFC);
    // 0x8008034C: nop

    // 0x80080350: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80080354: b           L_80080384
    // 0x80080358: sw          $t8, 0xFC($t6)
    MEM_W(0XFC, ctx->r14) = ctx->r24;
        goto L_80080384;
    // 0x80080358: sw          $t8, 0xFC($t6)
    MEM_W(0XFC, ctx->r14) = ctx->r24;
L_8008035C:
    // 0x8008035C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80080360: nop

    // 0x80080364: lw          $t1, 0xF4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XF4);
    // 0x80080368: lw          $t0, 0x100($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X100);
    // 0x8008036C: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x80080370: sltu        $at, $t0, $t3
    ctx->r1 = ctx->r8 < ctx->r11 ? 1 : 0;
    // 0x80080374: beq         $at, $zero, L_80080384
    if (ctx->r1 == 0) {
        // 0x80080378: nop
    
            goto L_80080384;
    }
    // 0x80080378: nop

    // 0x8008037C: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x80080380: sw          $t4, 0x100($t9)
    MEM_W(0X100, ctx->r25) = ctx->r12;
L_80080384:
    // 0x80080384: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80080388: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008038C: lw          $t5, 0x100($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X100);
    // 0x80080390: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x80080394: sltu        $at, $t5, $s0
    ctx->r1 = ctx->r13 < ctx->r16 ? 1 : 0;
    // 0x80080398: beq         $at, $zero, L_80080310
    if (ctx->r1 == 0) {
        // 0x8008039C: nop
    
            goto L_80080310;
    }
    // 0x8008039C: nop

L_800803A0:
    // 0x800803A0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800803A4: nop

    // 0x800803A8: lw          $t8, 0xFC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XFC);
    // 0x800803AC: lw          $t6, 0x100($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X100);
    // 0x800803B0: nop

    // 0x800803B4: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x800803B8: beq         $at, $zero, L_800803C8
    if (ctx->r1 == 0) {
        // 0x800803BC: nop
    
            goto L_800803C8;
    }
    // 0x800803BC: nop

    // 0x800803C0: b           L_800803E4
    // 0x800803C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800803E4;
    // 0x800803C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800803C8:
    // 0x800803C8: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800803CC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800803D0: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x800803D4: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800803D8: bne         $at, $zero, L_800802E4
    if (ctx->r1 != 0) {
        // 0x800803DC: sw          $t3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r11;
            goto L_800802E4;
    }
    // 0x800803DC: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
L_800803E0:
    // 0x800803E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800803E4:
    // 0x800803E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800803E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800803EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800803F0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800803F4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800803F8: jr          $ra
    // 0x800803FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800803FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void EndScroller_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080400: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80080404: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80080408: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008040C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80080410: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80080414: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80080418: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8008041C: nop

    // 0x80080420: bne         $t7, $zero, L_80080440
    if (ctx->r15 != 0) {
        // 0x80080424: nop
    
            goto L_80080440;
    }
    // 0x80080424: nop

    // 0x80080428: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008042C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80080430: addiu       $a1, $a1, -0x160C
    ctx->r5 = ADD32(ctx->r5, -0X160C);
    // 0x80080434: addiu       $a0, $a0, -0x1624
    ctx->r4 = ADD32(ctx->r4, -0X1624);
    // 0x80080438: jal         0x8004A5A0
    // 0x8008043C: addiu       $a2, $zero, 0x1F6
    ctx->r6 = ADD32(0, 0X1F6);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_0;
    // 0x8008043C: addiu       $a2, $zero, 0x1F6
    ctx->r6 = ADD32(0, 0X1F6);
    after_0:
L_80080440:
    // 0x80080440: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80080444: nop

    // 0x80080448: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x8008044C: nop

    // 0x80080450: bne         $t9, $zero, L_800804D8
    if (ctx->r25 != 0) {
        // 0x80080454: nop
    
            goto L_800804D8;
    }
    // 0x80080454: nop

    // 0x80080458: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008045C: jal         0x8008085C
    // 0x80080460: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    EndScroller_DrawBackground(rdram, ctx);
        goto after_1;
    // 0x80080460: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    after_1:
    // 0x80080464: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80080468: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008046C: lw          $s0, 0xFC($t0)
    ctx->r16 = MEM_W(ctx->r8, 0XFC);
    // 0x80080470: lw          $t1, 0xF8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XF8);
    // 0x80080474: sll         $t2, $s0, 3
    ctx->r10 = S32(ctx->r16 << 3);
    // 0x80080478: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x8008047C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80080480: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80080484: jal         0x8005BBFC
    // 0x80080488: addu        $s1, $t1, $t2
    ctx->r17 = ADD32(ctx->r9, ctx->r10);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_2;
    // 0x80080488: addu        $s1, $t1, $t2
    ctx->r17 = ADD32(ctx->r9, ctx->r10);
    after_2:
    // 0x8008048C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80080490: nop

    // 0x80080494: lw          $t4, 0x100($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X100);
    // 0x80080498: nop

    // 0x8008049C: sltu        $at, $t4, $s0
    ctx->r1 = ctx->r12 < ctx->r16 ? 1 : 0;
    // 0x800804A0: bne         $at, $zero, L_800804CC
    if (ctx->r1 != 0) {
        // 0x800804A4: nop
    
            goto L_800804CC;
    }
    // 0x800804A4: nop

L_800804A8:
    // 0x800804A8: jal         0x8007FE54
    // 0x800804AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    EndScroller_DrawLine(rdram, ctx);
        goto after_3;
    // 0x800804AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800804B0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800804B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800804B8: lw          $t6, 0x100($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X100);
    // 0x800804BC: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x800804C0: sltu        $at, $t6, $s0
    ctx->r1 = ctx->r14 < ctx->r16 ? 1 : 0;
    // 0x800804C4: beq         $at, $zero, L_800804A8
    if (ctx->r1 == 0) {
        // 0x800804C8: nop
    
            goto L_800804A8;
    }
    // 0x800804C8: nop

L_800804CC:
    // 0x800804CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800804D0: jal         0x8005BE40
    // 0x800804D4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_4;
    // 0x800804D4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_4:
L_800804D8:
    // 0x800804D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800804DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800804E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800804E4: jr          $ra
    // 0x800804E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800804E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800804EC: nop

;}

RECOMP_FUNC void EndScroller_InitBackground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800804F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800804F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800804F8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800804FC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80080500: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80080504: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80080508: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008050C: jal         0x8007E03C
    // 0x80080510: addiu       $a0, $zero, 0x7530
    ctx->r4 = ADD32(0, 0X7530);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80080510: addiu       $a0, $zero, 0x7530
    ctx->r4 = ADD32(0, 0X7530);
    after_0:
    // 0x80080514: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80080518: jal         0x8007E03C
    // 0x8008051C: ori         $a0, $zero, 0xEA60
    ctx->r4 = 0 | 0XEA60;
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8008051C: ori         $a0, $zero, 0xEA60
    ctx->r4 = 0 | 0XEA60;
    after_1:
    // 0x80080520: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80080524: addiu       $a0, $zero, 0x7530
    ctx->r4 = ADD32(0, 0X7530);
    // 0x80080528: jal         0x8007E03C
    // 0x8008052C: sw          $v0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r2;
    n64HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8008052C: sw          $v0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r2;
    after_2:
    // 0x80080530: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80080534: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x80080538: jal         0x8007E03C
    // 0x8008053C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    n64HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x8008053C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    after_3:
    // 0x80080540: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80080544: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    // 0x80080548: jal         0x8007E03C
    // 0x8008054C: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    n64HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x8008054C: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    after_4:
    // 0x80080550: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80080554: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x80080558: jal         0x8007E03C
    // 0x8008055C: sw          $v0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r2;
    n64HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x8008055C: sw          $v0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r2;
    after_5:
    // 0x80080560: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80080564: ori         $a0, $zero, 0xEA68
    ctx->r4 = 0 | 0XEA68;
    // 0x80080568: jal         0x8007E03C
    // 0x8008056C: sw          $v0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r2;
    n64HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x8008056C: sw          $v0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r2;
    after_6:
    // 0x80080570: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80080574: ori         $a0, $zero, 0xEA68
    ctx->r4 = 0 | 0XEA68;
    // 0x80080578: jal         0x8007E03C
    // 0x8008057C: sw          $v0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r2;
    n64HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x8008057C: sw          $v0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r2;
    after_7:
    // 0x80080580: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80080584: jal         0x8004A34C
    // 0x80080588: sw          $v0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r2;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_8;
    // 0x80080588: sw          $v0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r2;
    after_8:
    // 0x8008058C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80080590: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80080594: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80080598: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x8008059C: jal         0x800746C0
    // 0x800805A0: addiu       $a2, $zero, 0x43
    ctx->r6 = ADD32(0, 0X43);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_9;
    // 0x800805A0: addiu       $a2, $zero, 0x43
    ctx->r6 = ADD32(0, 0X43);
    after_9:
    // 0x800805A4: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800805A8: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x800805AC: lw          $a1, 0x4($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X4);
    // 0x800805B0: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x800805B4: jal         0x800746C0
    // 0x800805B8: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_10;
    // 0x800805B8: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_10:
    // 0x800805BC: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x800805C0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800805C4: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x800805C8: jal         0x800746C0
    // 0x800805CC: addiu       $a2, $zero, 0x45
    ctx->r6 = ADD32(0, 0X45);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_11;
    // 0x800805CC: addiu       $a2, $zero, 0x45
    ctx->r6 = ADD32(0, 0X45);
    after_11:
    // 0x800805D0: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800805D4: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x800805D8: lw          $a1, 0xC($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC);
    // 0x800805DC: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x800805E0: jal         0x800746C0
    // 0x800805E4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_12;
    // 0x800805E4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_12:
    // 0x800805E8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800805EC: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x800805F0: lw          $a1, 0x10($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X10);
    // 0x800805F4: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x800805F8: jal         0x800746C0
    // 0x800805FC: addiu       $a2, $zero, 0x47
    ctx->r6 = ADD32(0, 0X47);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_13;
    // 0x800805FC: addiu       $a2, $zero, 0x47
    ctx->r6 = ADD32(0, 0X47);
    after_13:
    // 0x80080600: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80080604: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80080608: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8008060C: slti        $at, $s1, 0x95
    ctx->r1 = SIGNED(ctx->r17) < 0X95 ? 1 : 0;
    // 0x80080610: lw          $s2, 0x8($t7)
    ctx->r18 = MEM_W(ctx->r15, 0X8);
    // 0x80080614: beq         $at, $zero, L_8008067C
    if (ctx->r1 == 0) {
        // 0x80080618: nop
    
            goto L_8008067C;
    }
    // 0x80080618: nop

L_8008061C:
    // 0x8008061C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80080620: slti        $at, $s0, 0xC7
    ctx->r1 = SIGNED(ctx->r16) < 0XC7 ? 1 : 0;
    // 0x80080624: beq         $at, $zero, L_80080660
    if (ctx->r1 == 0) {
        // 0x80080628: nop
    
            goto L_80080660;
    }
    // 0x80080628: nop

L_8008062C:
    // 0x8008062C: lbu         $t8, 0x0($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X0);
    // 0x80080630: lbu         $t9, 0xC8($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0XC8);
    // 0x80080634: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80080638: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8008063C: sb          $t0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r8;
    // 0x80080640: lbu         $t2, 0x1($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X1);
    // 0x80080644: lbu         $t1, 0x0($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X0);
    // 0x80080648: slti        $at, $s0, 0xC7
    ctx->r1 = SIGNED(ctx->r16) < 0XC7 ? 1 : 0;
    // 0x8008064C: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80080650: sb          $t3, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r11;
    // 0x80080654: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80080658: bne         $at, $zero, L_8008062C
    if (ctx->r1 != 0) {
        // 0x8008065C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8008062C;
    }
    // 0x8008065C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80080660:
    // 0x80080660: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80080664: slti        $at, $s1, 0x95
    ctx->r1 = SIGNED(ctx->r17) < 0X95 ? 1 : 0;
    // 0x80080668: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x8008066C: sb          $zero, 0x1($s2)
    MEM_B(0X1, ctx->r18) = 0;
    // 0x80080670: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80080674: bne         $at, $zero, L_8008061C
    if (ctx->r1 != 0) {
        // 0x80080678: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8008061C;
    }
    // 0x80080678: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8008067C:
    // 0x8008067C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80080680: jal         0x8007E328
    // 0x80080684: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_14;
    // 0x80080684: nop

    after_14:
    // 0x80080688: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8008068C: addiu       $t4, $zero, 0x100
    ctx->r12 = ADD32(0, 0X100);
    // 0x80080690: sb          $zero, 0x38($sp)
    MEM_B(0X38, ctx->r29) = 0;
    // 0x80080694: sh          $t4, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r12;
    // 0x80080698: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8008069C: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x800806A0: sb          $zero, 0x30($sp)
    MEM_B(0X30, ctx->r29) = 0;
    // 0x800806A4: sh          $t7, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r15;
    // 0x800806A8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800806AC: lw          $t8, 0x10($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X10);
    // 0x800806B0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800806B4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800806B8: sb          $zero, 0x2C($t5)
    MEM_B(0X2C, ctx->r13) = 0;
    // 0x800806BC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800806C0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800806C4: sb          $t9, 0x2D($t0)
    MEM_B(0X2D, ctx->r8) = ctx->r25;
    // 0x800806C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800806CC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x800806D0: jal         0x80075480
    // 0x800806D4: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    GarbageImg_BlendRGB565(rdram, ctx);
        goto after_15;
    // 0x800806D4: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_15:
    // 0x800806D8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800806DC: jal         0x80075830
    // 0x800806E0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    ImageRect_Init(rdram, ctx);
        goto after_16;
    // 0x800806E0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_16:
    // 0x800806E4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800806E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800806EC: jal         0x80075760
    // 0x800806F0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    ImageRect_SetMode(rdram, ctx);
        goto after_17;
    // 0x800806F0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_17:
    // 0x800806F4: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800806F8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800806FC: lw          $a1, 0xC($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC);
    // 0x80080700: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x80080704: jal         0x800757BC
    // 0x80080708: addiu       $a0, $t1, 0x1C
    ctx->r4 = ADD32(ctx->r9, 0X1C);
    ImageRect_SetSource(rdram, ctx);
        goto after_18;
    // 0x80080708: addiu       $a0, $t1, 0x1C
    ctx->r4 = ADD32(ctx->r9, 0X1C);
    after_18:
    // 0x8008070C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80080710: nop

    // 0x80080714: sh          $zero, 0x7C($t2)
    MEM_H(0X7C, ctx->r10) = 0;
    // 0x80080718: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8008071C: nop

    // 0x80080720: sh          $zero, 0x7E($t3)
    MEM_H(0X7E, ctx->r11) = 0;
    // 0x80080724: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80080728: nop

    // 0x8008072C: sh          $zero, 0x80($t4)
    MEM_H(0X80, ctx->r12) = 0;
    // 0x80080730: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80080734: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80080738: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8008073C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80080740: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80080744: jr          $ra
    // 0x80080748: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80080748: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}

RECOMP_FUNC void EndScroller_DeinitBackground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008074C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80080750: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80080754: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80080758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008075C: jal         0x800756A8
    // 0x80080760: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    GarbageImg_FreeBlend(rdram, ctx);
        goto after_0;
    // 0x80080760: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_0:
    // 0x80080764: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80080768: nop

    // 0x8008076C: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x80080770: jal         0x8007E328
    // 0x80080774: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x80080774: nop

    after_1:
    // 0x80080778: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008077C: nop

    // 0x80080780: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    // 0x80080784: jal         0x8007E328
    // 0x80080788: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_2;
    // 0x80080788: nop

    after_2:
    // 0x8008078C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80080790: nop

    // 0x80080794: lw          $a0, 0x18($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X18);
    // 0x80080798: jal         0x8007E328
    // 0x8008079C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_3;
    // 0x8008079C: nop

    after_3:
    // 0x800807A0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800807A4: nop

    // 0x800807A8: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800807AC: jal         0x8007E328
    // 0x800807B0: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_4;
    // 0x800807B0: nop

    after_4:
    // 0x800807B4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800807B8: nop

    // 0x800807BC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800807C0: jal         0x8007E328
    // 0x800807C4: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_5;
    // 0x800807C4: nop

    after_5:
    // 0x800807C8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800807CC: nop

    // 0x800807D0: lw          $a0, 0xC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XC);
    // 0x800807D4: jal         0x8007E328
    // 0x800807D8: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_6;
    // 0x800807D8: nop

    after_6:
    // 0x800807DC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800807E0: nop

    // 0x800807E4: lw          $a0, 0x10($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X10);
    // 0x800807E8: jal         0x8007E328
    // 0x800807EC: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_7;
    // 0x800807EC: nop

    after_7:
    // 0x800807F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800807F4: jal         0x80075870
    // 0x800807F8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    ImageRect_Reset(rdram, ctx);
        goto after_8;
    // 0x800807F8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_8:
    // 0x800807FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80080800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80080804: jr          $ra
    // 0x80080808: nop

    return;
    // 0x80080808: nop

;}

RECOMP_FUNC void EndScroller_AdvanceBackgroundRotation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008080C: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80080810: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x80080814: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80080818: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x8008081C: lhu         $t6, 0x7C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X7C);
    // 0x80080820: lhu         $t9, 0x7E($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X7E);
    // 0x80080824: lhu         $t2, 0x80($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X80);
    // 0x80080828: sll         $t7, $a1, 7
    ctx->r15 = S32(ctx->r5 << 7);
    // 0x8008082C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80080830: sll         $t3, $a1, 4
    ctx->r11 = S32(ctx->r5 << 4);
    // 0x80080834: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x80080838: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x8008083C: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x80080840: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80080844: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80080848: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8008084C: sh          $t8, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r24;
    // 0x80080850: sh          $t1, 0x7E($a0)
    MEM_H(0X7E, ctx->r4) = ctx->r9;
    // 0x80080854: jr          $ra
    // 0x80080858: sh          $t4, 0x80($a0)
    MEM_H(0X80, ctx->r4) = ctx->r12;
    return;
    // 0x80080858: sh          $t4, 0x80($a0)
    MEM_H(0X80, ctx->r4) = ctx->r12;
;}

RECOMP_FUNC void EndScroller_DrawBackground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008085C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80080860: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80080864: lhu         $t7, 0x20B0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X20B0);
    // 0x80080868: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8008086C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80080870: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80080874: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80080878: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8008087C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80080880: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80080884: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80080888: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8008088C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80080890: lw          $s1, 0x14($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X14);
    // 0x80080894: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x80080898: addiu       $t1, $zero, 0x96
    ctx->r9 = ADD32(0, 0X96);
    // 0x8008089C: sh          $t0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r8;
    // 0x800808A0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800808A4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800808A8: sh          $t1, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r9;
    // 0x800808AC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800808B0: sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    // 0x800808B4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800808B8: addiu       $s0, $t6, 0x30
    ctx->r16 = ADD32(ctx->r14, 0X30);
    // 0x800808BC: sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    // 0x800808C0: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x800808C4: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800808C8: nop

    // 0x800808CC: lhu         $a0, 0x7C($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X7C);
    // 0x800808D0: jal         0x800B8010
    // 0x800808D4: nop

    sins(rdram, ctx);
        goto after_0;
    // 0x800808D4: nop

    after_0:
    // 0x800808D8: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800808DC: sll         $s2, $v0, 7
    ctx->r18 = S32(ctx->r2 << 7);
    // 0x800808E0: lhu         $a0, 0x7E($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X7E);
    // 0x800808E4: jal         0x800B8080
    // 0x800808E8: nop

    coss(rdram, ctx);
        goto after_1;
    // 0x800808E8: nop

    after_1:
    // 0x800808EC: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x800808F0: sll         $s3, $v0, 7
    ctx->r19 = S32(ctx->r2 << 7);
    // 0x800808F4: lhu         $a0, 0x80($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X80);
    // 0x800808F8: jal         0x800B8010
    // 0x800808FC: nop

    sins(rdram, ctx);
        goto after_2;
    // 0x800808FC: nop

    after_2:
    // 0x80080900: sll         $s4, $v0, 7
    ctx->r20 = S32(ctx->r2 << 7);
    // 0x80080904: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x80080908: addu        $s4, $s4, $at
    ctx->r20 = ADD32(ctx->r20, ctx->r1);
    // 0x8008090C: sra         $t5, $s3, 1
    ctx->r13 = S32(SIGNED(ctx->r19) >> 1);
    // 0x80080910: addu        $s2, $s2, $t5
    ctx->r18 = ADD32(ctx->r18, ctx->r13);
    // 0x80080914: addu        $t8, $s2, $s4
    ctx->r24 = ADD32(ctx->r18, ctx->r20);
    // 0x80080918: addu        $t7, $s2, $s4
    ctx->r15 = ADD32(ctx->r18, ctx->r20);
    // 0x8008091C: addu        $t6, $s3, $s4
    ctx->r14 = ADD32(ctx->r19, ctx->r20);
    // 0x80080920: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80080924: sw          $s2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r18;
    // 0x80080928: sw          $s3, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r19;
    // 0x8008092C: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x80080930: sw          $s3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r19;
    // 0x80080934: sw          $t6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r14;
    // 0x80080938: sw          $s2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r18;
    // 0x8008093C: sw          $t9, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r25;
    // 0x80080940: bgez        $s4, L_80080950
    if (SIGNED(ctx->r20) >= 0) {
        // 0x80080944: sra         $t0, $s4, 1
        ctx->r8 = S32(SIGNED(ctx->r20) >> 1);
            goto L_80080950;
    }
    // 0x80080944: sra         $t0, $s4, 1
    ctx->r8 = S32(SIGNED(ctx->r20) >> 1);
    // 0x80080948: addiu       $at, $s4, 0x1
    ctx->r1 = ADD32(ctx->r20, 0X1);
    // 0x8008094C: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_80080950:
    // 0x80080950: addu        $t1, $t0, $s3
    ctx->r9 = ADD32(ctx->r8, ctx->r19);
    // 0x80080954: sw          $t1, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r9;
    // 0x80080958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008095C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80080960: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80080964: jal         0x80075700
    // 0x80080968: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    ImageRect_SetDims(rdram, ctx);
        goto after_3;
    // 0x80080968: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x8008096C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80080970: nop

    // 0x80080974: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80080978: nop

    // 0x8008097C: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x80080980: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80080984: nop

    // 0x80080988: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8008098C: nop

    // 0x80080990: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80080994: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80080998: nop

    // 0x8008099C: lw          $t9, 0x74($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X74);
    // 0x800809A0: addiu       $a0, $t7, 0x1C
    ctx->r4 = ADD32(ctx->r15, 0X1C);
    // 0x800809A4: jalr        $t9
    // 0x800809A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800809A8: nop

    after_4:
    // 0x800809AC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800809B0: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x800809B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800809B8: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x800809BC: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800809C0: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x800809C4: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x800809C8: lui         $t0, 0xED00
    ctx->r8 = S32(0XED00 << 16);
    // 0x800809CC: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800809D0: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800809D4: lui         $t2, 0x63
    ctx->r10 = S32(0X63 << 16);
    // 0x800809D8: ori         $t2, $t2, 0xC4AC
    ctx->r10 = ctx->r10 | 0XC4AC;
    // 0x800809DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800809E0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800809E4: jal         0x8005BBFC
    // 0x800809E8: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    Gfx_SetupRenderState(rdram, ctx);
        goto after_5;
    // 0x800809E8: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    after_5:
    // 0x800809EC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800809F0: lhu         $t5, 0x20B0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X20B0);
    // 0x800809F4: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x800809F8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800809FC: addu        $t9, $t4, $t7
    ctx->r25 = ADD32(ctx->r12, ctx->r15);
    // 0x80080A00: lw          $a1, 0x14($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X14);
    // 0x80080A04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080A08: addiu       $t6, $zero, 0x46
    ctx->r14 = ADD32(0, 0X46);
    // 0x80080A0C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80080A10: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80080A14: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80080A18: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80080A1C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80080A20: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80080A24: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80080A28: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80080A2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80080A30: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80080A34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80080A38: jal         0x80057460
    // 0x80080A3C: addiu       $a3, $zero, 0x67
    ctx->r7 = ADD32(0, 0X67);
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_6;
    // 0x80080A3C: addiu       $a3, $zero, 0x67
    ctx->r7 = ADD32(0, 0X67);
    after_6:
    // 0x80080A40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080A44: jal         0x8005BE40
    // 0x80080A48: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_7;
    // 0x80080A48: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_7:
    // 0x80080A4C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80080A50: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80080A54: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80080A58: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80080A5C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80080A60: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80080A64: jr          $ra
    // 0x80080A68: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80080A68: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80080A6C: nop

;}

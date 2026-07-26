#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void strutil_nextline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080A70: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80080A74: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80080A78: beq         $t6, $a1, L_80080AB0
    if (ctx->r14 == ctx->r5) {
        // 0x80080A7C: nop
    
            goto L_80080AB0;
    }
    // 0x80080A7C: nop

    // 0x80080A80: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80080A84: nop

    // 0x80080A88: beq         $t7, $zero, L_80080AB0
    if (ctx->r15 == 0) {
        // 0x80080A8C: nop
    
            goto L_80080AB0;
    }
    // 0x80080A8C: nop

L_80080A90:
    // 0x80080A90: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x80080A94: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80080A98: beq         $t8, $a1, L_80080AB0
    if (ctx->r24 == ctx->r5) {
        // 0x80080A9C: nop
    
            goto L_80080AB0;
    }
    // 0x80080A9C: nop

    // 0x80080AA0: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80080AA4: nop

    // 0x80080AA8: bne         $t9, $zero, L_80080A90
    if (ctx->r25 != 0) {
        // 0x80080AAC: nop
    
            goto L_80080A90;
    }
    // 0x80080AAC: nop

L_80080AB0:
    // 0x80080AB0: jr          $ra
    // 0x80080AB4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80080AB4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}

RECOMP_FUNC void strutil_linelen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080AB8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80080ABC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80080AC0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80080AC4: beq         $t6, $a1, L_80080AFC
    if (ctx->r14 == ctx->r5) {
        // 0x80080AC8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80080AFC;
    }
    // 0x80080AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80080ACC: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80080AD0: nop

    // 0x80080AD4: beq         $t7, $zero, L_80080AFC
    if (ctx->r15 == 0) {
        // 0x80080AD8: nop
    
            goto L_80080AFC;
    }
    // 0x80080AD8: nop

L_80080ADC:
    // 0x80080ADC: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x80080AE0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80080AE4: beq         $t8, $a1, L_80080AFC
    if (ctx->r24 == ctx->r5) {
        // 0x80080AE8: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80080AFC;
    }
    // 0x80080AE8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80080AEC: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80080AF0: nop

    // 0x80080AF4: bne         $t9, $zero, L_80080ADC
    if (ctx->r25 != 0) {
        // 0x80080AF8: nop
    
            goto L_80080ADC;
    }
    // 0x80080AF8: nop

L_80080AFC:
    // 0x80080AFC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80080B00: jr          $ra
    // 0x80080B04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80080B04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void strutil_linecnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080B08: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80080B0C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80080B10: beq         $t6, $zero, L_80080B3C
    if (ctx->r14 == 0) {
        // 0x80080B14: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80080B3C;
    }
    // 0x80080B14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80080B18:
    // 0x80080B18: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80080B1C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80080B20: bne         $t7, $at, L_80080B2C
    if (ctx->r15 != ctx->r1) {
        // 0x80080B24: nop
    
            goto L_80080B2C;
    }
    // 0x80080B24: nop

    // 0x80080B28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80080B2C:
    // 0x80080B2C: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x80080B30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80080B34: bne         $t8, $zero, L_80080B18
    if (ctx->r24 != 0) {
        // 0x80080B38: nop
    
            goto L_80080B18;
    }
    // 0x80080B38: nop

L_80080B3C:
    // 0x80080B3C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80080B40: jr          $ra
    // 0x80080B44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80080B44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80080B48: nop

    // 0x80080B4C: nop

;}

RECOMP_FUNC void strutil_lzo_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080E50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80080E54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80080E58: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80080E5C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80080E60: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80080E64: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80080E68: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80080E6C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80080E70: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80080E74: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80080E78: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80080E7C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80080E80: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80080E84: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80080E88: addiu       $a0, $zero, 0x1040
    ctx->r4 = ADD32(0, 0X1040);
    // 0x80080E8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80080E90: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80080E94: jal         0x80081D1C
    // 0x80080E98: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    __lzo_init2(rdram, ctx);
        goto after_0;
    // 0x80080E98: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x80080E9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80080EA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80080EA4: jr          $ra
    // 0x80080EA8: nop

    return;
    // 0x80080EA8: nop

;}

RECOMP_FUNC void func_80080EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080EAC: jr          $ra
    // 0x80080EB0: nop

    return;
    // 0x80080EB0: nop

;}

RECOMP_FUNC void func_80080EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080EB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80080EB8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80080EBC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80080EC0: jr          $ra
    // 0x80080EC4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x80080EC4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}

RECOMP_FUNC void strutil_lzo_decompress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080EC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80080ECC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80080ED0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80080ED4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80080ED8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80080EDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80080EE0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80080EE4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80080EE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80080EEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80080EF0: jal         0x800827EC
    // 0x80080EF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    lzo1x_decompress(rdram, ctx);
        goto after_0;
    // 0x80080EF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80080EF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80080EFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80080F00: jr          $ra
    // 0x80080F04: nop

    return;
    // 0x80080F04: nop

;}

RECOMP_FUNC void strutil_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080F08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80080F0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80080F10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080F14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80080F18: jal         0x8007E03C
    // 0x80080F1C: nop

    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80080F1C: nop

    after_0:
    // 0x80080F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80080F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80080F28: jr          $ra
    // 0x80080F2C: nop

    return;
    // 0x80080F2C: nop

;}

RECOMP_FUNC void strutil_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80080F34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80080F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80080F40: jal         0x8007E328
    // 0x80080F44: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x80080F44: nop

    after_0:
    // 0x80080F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80080F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80080F50: jr          $ra
    // 0x80080F54: nop

    return;
    // 0x80080F54: nop

    // 0x80080F58: nop

    // 0x80080F5C: nop

;}

RECOMP_FUNC void strutil_charindex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC2B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800AC2B4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800AC2B8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800AC2BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AC2C0: beq         $v0, $zero, L_800AC2EC
    if (ctx->r2 == 0) {
        // 0x800AC2C4: nop
    
            goto L_800AC2EC;
    }
    // 0x800AC2C4: nop

    // 0x800AC2C8: beq         $t6, $v0, L_800AC2EC
    if (ctx->r14 == ctx->r2) {
        // 0x800AC2CC: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_800AC2EC;
    }
    // 0x800AC2CC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800AC2D0: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
L_800AC2D4:
    // 0x800AC2D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AC2D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AC2DC: beq         $v0, $zero, L_800AC2EC
    if (ctx->r2 == 0) {
        // 0x800AC2E0: nop
    
            goto L_800AC2EC;
    }
    // 0x800AC2E0: nop

    // 0x800AC2E4: bnel        $a2, $v0, L_800AC2D4
    if (ctx->r6 != ctx->r2) {
        // 0x800AC2E8: lbu         $v0, 0x1($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X1);
            goto L_800AC2D4;
    }
    goto skip_0;
    // 0x800AC2E8: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    skip_0:
L_800AC2EC:
    // 0x800AC2EC: beql        $v0, $zero, L_800AC300
    if (ctx->r2 == 0) {
        // 0x800AC2F0: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800AC300;
    }
    goto skip_1;
    // 0x800AC2F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x800AC2F4: jr          $ra
    // 0x800AC2F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800AC2F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800AC2FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AC300:
    // 0x800AC300: jr          $ra
    // 0x800AC304: nop

    return;
    // 0x800AC304: nop

;}

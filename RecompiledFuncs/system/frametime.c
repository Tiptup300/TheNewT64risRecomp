#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void frametime_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A39B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A39B4: addiu       $v0, $v0, -0x6C90
    ctx->r2 = ADD32(ctx->r2, -0X6C90);
    // 0x800A39B8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800A39BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A39C0: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800A39C4: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800A39C8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800A39CC: jr          $ra
    // 0x800A39D0: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    return;
    // 0x800A39D0: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
;}

RECOMP_FUNC void frametime_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A39D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A39D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A39DC: jal         0x800A39B0
    // 0x800A39E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    frametime_clear(rdram, ctx);
        goto after_0;
    // 0x800A39E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A39E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A39E8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A39EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A39F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A39F4: jr          $ra
    // 0x800A39F8: sw          $t6, -0x6C90($at)
    MEM_W(-0X6C90, ctx->r1) = ctx->r14;
    return;
    // 0x800A39F8: sw          $t6, -0x6C90($at)
    MEM_W(-0X6C90, ctx->r1) = ctx->r14;
;}

RECOMP_FUNC void frametime_add(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A39FC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800A3A00: addiu       $v1, $v1, -0x6C90
    ctx->r3 = ADD32(ctx->r3, -0X6C90);
    // 0x800A3A04: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800A3A08: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800A3A0C: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800A3A10: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x800A3A14: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x800A3A18: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800A3A1C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800A3A20: bne         $at, $zero, L_800A3A84
    if (ctx->r1 != 0) {
        // 0x800A3A24: sw          $v0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r2;
            goto L_800A3A84;
    }
    // 0x800A3A24: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800A3A28: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x800A3A2C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800A3A30: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
L_800A3A34:
    // 0x800A3A34: addiu       $t0, $v0, -0x3C
    ctx->r8 = ADD32(ctx->r2, -0X3C);
    // 0x800A3A38: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x800A3A3C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800A3A40: bne         $a0, $t2, L_800A3A74
    if (ctx->r4 != ctx->r10) {
        // 0x800A3A44: sw          $t2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r10;
            goto L_800A3A74;
    }
    // 0x800A3A44: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800A3A48: lw          $t4, 0x10($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X10);
    // 0x800A3A4C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x800A3A50: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800A3A54: bne         $a0, $t5, L_800A3A74
    if (ctx->r4 != ctx->r13) {
        // 0x800A3A58: sw          $t5, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r13;
            goto L_800A3A74;
    }
    // 0x800A3A58: sw          $t5, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r13;
    // 0x800A3A5C: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x800A3A60: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x800A3A64: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800A3A68: bne         $a1, $t8, L_800A3A74
    if (ctx->r5 != ctx->r24) {
        // 0x800A3A6C: sw          $t8, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r24;
            goto L_800A3A74;
    }
    // 0x800A3A6C: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    // 0x800A3A70: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
L_800A3A74:
    // 0x800A3A74: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800A3A78: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x800A3A7C: beql        $at, $zero, L_800A3A34
    if (ctx->r1 == 0) {
        // 0x800A3A80: lw          $t1, 0xC($v1)
        ctx->r9 = MEM_W(ctx->r3, 0XC);
            goto L_800A3A34;
    }
    goto skip_0;
    // 0x800A3A80: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    skip_0:
L_800A3A84:
    // 0x800A3A84: jr          $ra
    // 0x800A3A88: nop

    return;
    // 0x800A3A88: nop

;}

RECOMP_FUNC void frametime_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3A8C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800A3A90: lw          $t6, -0x6C90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C90);
    // 0x800A3A94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3A9C: jal         0x800A39FC
    // 0x800A3AA0: subu        $a0, $a0, $t6
    ctx->r4 = SUB32(ctx->r4, ctx->r14);
    frametime_add(rdram, ctx);
        goto after_0;
    // 0x800A3AA0: subu        $a0, $a0, $t6
    ctx->r4 = SUB32(ctx->r4, ctx->r14);
    after_0:
    // 0x800A3AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3AA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3AAC: jr          $ra
    // 0x800A3AB0: nop

    return;
    // 0x800A3AB0: nop

;}

RECOMP_FUNC void frametime_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3AB4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A3AB8: jr          $ra
    // 0x800A3ABC: lw          $v0, -0x6C90($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C90);
    return;
    // 0x800A3ABC: lw          $v0, -0x6C90($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C90);
;}

RECOMP_FUNC void frametime_jiffies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3AC0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A3AC4: jr          $ra
    // 0x800A3AC8: lw          $v0, -0x6C88($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C88);
    return;
    // 0x800A3AC8: lw          $v0, -0x6C88($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C88);
;}

RECOMP_FUNC void frametime_seconds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3ACC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A3AD0: jr          $ra
    // 0x800A3AD4: lw          $v0, -0x6C84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C84);
    return;
    // 0x800A3AD4: lw          $v0, -0x6C84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C84);
;}

RECOMP_FUNC void frametime_minutes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3AD8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A3ADC: jr          $ra
    // 0x800A3AE0: lw          $v0, -0x6C80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C80);
    return;
    // 0x800A3AE0: lw          $v0, -0x6C80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C80);
;}

RECOMP_FUNC void frametime_hours(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3AE4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A3AE8: jr          $ra
    // 0x800A3AEC: lw          $v0, -0x6C7C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C7C);
    return;
    // 0x800A3AEC: lw          $v0, -0x6C7C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C7C);
;}

RECOMP_FUNC void frametime_delta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3AF0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A3AF4: jr          $ra
    // 0x800A3AF8: lw          $v0, -0x6C8C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C8C);
    return;
    // 0x800A3AF8: lw          $v0, -0x6C8C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C8C);
    // 0x800A3AFC: nop

;}

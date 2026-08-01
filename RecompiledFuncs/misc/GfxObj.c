#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void GfxObj_Free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACCDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ACCE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ACCE4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ACCE8: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x800ACCEC: beql        $t7, $zero, L_800ACD04
    if (ctx->r15 == 0) {
        // 0x800ACCF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800ACD04;
    }
    goto skip_0;
    // 0x800ACCF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800ACCF4: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800ACCF8: jal         0x8007E328
    // 0x800ACCFC: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800ACCFC: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    after_0:
    // 0x800ACD00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800ACD04:
    // 0x800ACD04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800ACD08: jr          $ra
    // 0x800ACD0C: nop

    return;
    // 0x800ACD0C: nop

;}

RECOMP_FUNC void GfxObj_SetCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACD10: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ACD14: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x800ACD18: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x800ACD1C: beq         $t7, $zero, L_800ACD44
    if (ctx->r15 == 0) {
        // 0x800ACD20: nop
    
            goto L_800ACD44;
    }
    // 0x800ACD20: nop

    // 0x800ACD24: bnel        $at, $zero, L_800ACD34
    if (ctx->r1 != 0) {
        // 0x800ACD28: lw          $t9, 0x8($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X8);
            goto L_800ACD34;
    }
    goto skip_0;
    // 0x800ACD28: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x800ACD2C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800ACD30: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
L_800ACD34:
    // 0x800ACD34: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x800ACD38: sw          $t8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r24;
    // 0x800ACD3C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800ACD40: sw          $a1, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r5;
L_800ACD44:
    // 0x800ACD44: jr          $ra
    // 0x800ACD48: nop

    return;
    // 0x800ACD48: nop

;}

RECOMP_FUNC void GfxObj_SetElemVec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACD4C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ACD50: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800ACD54: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800ACD58: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x800ACD5C: beq         $t7, $zero, L_800ACD8C
    if (ctx->r15 == 0) {
        // 0x800ACD60: nop
    
            goto L_800ACD8C;
    }
    // 0x800ACD60: nop

    // 0x800ACD64: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800ACD68: andi        $t8, $a1, 0x7
    ctx->r24 = ctx->r5 & 0X7;
    // 0x800ACD6C: addiu       $a1, $t8, 0x1
    ctx->r5 = ADD32(ctx->r24, 0X1);
    // 0x800ACD70: lw          $t0, 0x28($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X28);
    // 0x800ACD74: sll         $t1, $a1, 6
    ctx->r9 = S32(ctx->r5 << 6);
    // 0x800ACD78: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x800ACD7C: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    // 0x800ACD80: swc1        $f14, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f14.u32l;
    // 0x800ACD84: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800ACD88: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
L_800ACD8C:
    // 0x800ACD8C: jr          $ra
    // 0x800ACD90: nop

    return;
    // 0x800ACD90: nop

;}

RECOMP_FUNC void GfxObj_SetNodeVec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACD94: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ACD98: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800ACD9C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800ACDA0: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x800ACDA4: beq         $t7, $zero, L_800ACDDC
    if (ctx->r15 == 0) {
        // 0x800ACDA8: nop
    
            goto L_800ACDDC;
    }
    // 0x800ACDA8: nop

    // 0x800ACDAC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800ACDB0: andi        $t8, $a1, 0x7
    ctx->r24 = ctx->r5 & 0X7;
    // 0x800ACDB4: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x800ACDB8: lw          $t0, 0x38($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X38);
    // 0x800ACDBC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800ACDC0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800ACDC4: swc1        $f12, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f12.u32l;
    // 0x800ACDC8: swc1        $f14, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f14.u32l;
    // 0x800ACDCC: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800ACDD0: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x800ACDD4: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800ACDD8: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
L_800ACDDC:
    // 0x800ACDDC: jr          $ra
    // 0x800ACDE0: nop

    return;
    // 0x800ACDE0: nop

;}

RECOMP_FUNC void GfxObj_ComputeRect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACDE4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800ACDE8: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800ACDEC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800ACDF0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ACDF4: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800ACDF8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800ACDFC: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x800ACE00: beql        $t7, $zero, L_800ACE8C
    if (ctx->r15 == 0) {
        // 0x800ACE04: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_800ACE8C;
    }
    goto skip_0;
    // 0x800ACE04: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_0:
    // 0x800ACE08: sub.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800ACE0C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800ACE10: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800ACE14: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800ACE18: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x800ACE1C: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x800ACE20: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x800ACE24: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800ACE28: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x800ACE2C: nop

    // 0x800ACE30: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x800ACE34: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800ACE38: sub.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800ACE3C: add.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800ACE40: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x800ACE44: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800ACE48: add.d       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f16.d + ctx->f16.d;
    // 0x800ACE4C: add.d       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f18.d + ctx->f18.d;
    // 0x800ACE50: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800ACE54: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x800ACE58: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800ACE5C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800ACE60: sh          $t3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r11;
    // 0x800ACE64: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800ACE68: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800ACE6C: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800ACE70: cvt.d.s     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f20.d = CVT_D_S(ctx->f10.fl);
    // 0x800ACE74: add.d       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = ctx->f20.d + ctx->f20.d;
    // 0x800ACE78: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x800ACE7C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800ACE80: nop

    // 0x800ACE84: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x800ACE88: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
L_800ACE8C:
    // 0x800ACE8C: jr          $ra
    // 0x800ACE90: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800ACE90: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800ACE94: nop

    // 0x800ACE98: nop

    // 0x800ACE9C: nop

;}

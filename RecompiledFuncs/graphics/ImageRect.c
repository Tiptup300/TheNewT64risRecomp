#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ImageRect_SetDims(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075700: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80075704: divu        $zero, $t6, $a1
    lo = S32(U32(ctx->r14) / U32(ctx->r5)); hi = S32(U32(ctx->r14) % U32(ctx->r5));
    // 0x80075708: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8007570C: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    // 0x80075710: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
    // 0x80075714: sw          $a3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r7;
    // 0x80075718: bne         $a1, $zero, L_80075724
    if (ctx->r5 != 0) {
        // 0x8007571C: nop
    
            goto L_80075724;
    }
    // 0x8007571C: nop

    // 0x80075720: break       7
    do_break(2147964704);
L_80075724:
    // 0x80075724: mflo        $t7
    ctx->r15 = lo;
    // 0x80075728: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8007572C: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x80075730: divu        $zero, $t9, $a2
    lo = S32(U32(ctx->r25) / U32(ctx->r6)); hi = S32(U32(ctx->r25) % U32(ctx->r6));
    // 0x80075734: bne         $a2, $zero, L_80075740
    if (ctx->r6 != 0) {
        // 0x80075738: nop
    
            goto L_80075740;
    }
    // 0x80075738: nop

    // 0x8007573C: break       7
    do_break(2147964732);
L_80075740:
    // 0x80075740: mflo        $t0
    ctx->r8 = lo;
    // 0x80075744: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80075748: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8007574C: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80075750: mflo        $t2
    ctx->r10 = lo;
    // 0x80075754: sw          $t2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r10;
    // 0x80075758: jr          $ra
    // 0x8007575C: nop

    return;
    // 0x8007575C: nop

;}

RECOMP_FUNC void ImageRect_SetMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075760: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80075764: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80075768: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007576C: beq         $a2, $zero, L_80075790
    if (ctx->r6 == 0) {
        // 0x80075770: sb          $a1, 0x5C($a0)
        MEM_B(0X5C, ctx->r4) = ctx->r5;
            goto L_80075790;
    }
    // 0x80075770: sb          $a1, 0x5C($a0)
    MEM_B(0X5C, ctx->r4) = ctx->r5;
    // 0x80075774: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80075778: beq         $a2, $at, L_800757A8
    if (ctx->r6 == ctx->r1) {
        // 0x8007577C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800757A8;
    }
    // 0x8007577C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075780: beq         $a2, $at, L_80075798
    if (ctx->r6 == ctx->r1) {
        // 0x80075784: nop
    
            goto L_80075798;
    }
    // 0x80075784: nop

    // 0x80075788: b           L_800757B4
    // 0x8007578C: nop

        goto L_800757B4;
    // 0x8007578C: nop

L_80075790:
    // 0x80075790: b           L_800757B4
    // 0x80075794: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
        goto L_800757B4;
    // 0x80075794: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
L_80075798:
    // 0x80075798: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8007579C: addiu       $t6, $t6, 0x2FB0
    ctx->r14 = ADD32(ctx->r14, 0X2FB0);
    // 0x800757A0: b           L_800757B4
    // 0x800757A4: sw          $t6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r14;
        goto L_800757B4;
    // 0x800757A4: sw          $t6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r14;
L_800757A8:
    // 0x800757A8: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800757AC: addiu       $t7, $t7, 0x30F0
    ctx->r15 = ADD32(ctx->r15, 0X30F0);
    // 0x800757B0: sw          $t7, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r15;
L_800757B4:
    // 0x800757B4: jr          $ra
    // 0x800757B8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800757B8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void ImageRect_SetSource(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800757BC: lbu         $t0, 0x5C($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X5C);
    // 0x800757C0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800757C4: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800757C8: sh          $a2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r6;
    // 0x800757CC: beq         $t0, $zero, L_80075824
    if (ctx->r8 == 0) {
        // 0x800757D0: sh          $a3, 0x6($a0)
        MEM_H(0X6, ctx->r4) = ctx->r7;
            goto L_80075824;
    }
    // 0x800757D0: sh          $a3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r7;
    // 0x800757D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800757D8: beq         $t0, $at, L_80075800
    if (ctx->r8 == ctx->r1) {
        // 0x800757DC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80075800;
    }
    // 0x800757DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800757E0: bne         $t0, $at, L_8007581C
    if (ctx->r8 != ctx->r1) {
        // 0x800757E4: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_8007581C;
    }
    // 0x800757E4: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800757E8: bne         $a2, $at, L_800757F8
    if (ctx->r6 != ctx->r1) {
        // 0x800757EC: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_800757F8;
    }
    // 0x800757EC: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800757F0: beq         $a3, $at, L_80075824
    if (ctx->r7 == ctx->r1) {
        // 0x800757F4: nop
    
            goto L_80075824;
    }
    // 0x800757F4: nop

L_800757F8:
    // 0x800757F8: b           L_80075828
    // 0x800757FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80075828;
    // 0x800757FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80075800:
    // 0x80075800: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80075804: bne         $a2, $at, L_80075814
    if (ctx->r6 != ctx->r1) {
        // 0x80075808: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_80075814;
    }
    // 0x80075808: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8007580C: beq         $a3, $at, L_80075824
    if (ctx->r7 == ctx->r1) {
        // 0x80075810: nop
    
            goto L_80075824;
    }
    // 0x80075810: nop

L_80075814:
    // 0x80075814: b           L_80075828
    // 0x80075818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80075828;
    // 0x80075818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007581C:
    // 0x8007581C: b           L_80075828
    // 0x80075820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80075828;
    // 0x80075820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80075824:
    // 0x80075824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80075828:
    // 0x80075828: jr          $ra
    // 0x8007582C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007582C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void ImageRect_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075838: jal         0x800756E0
    // 0x8007583C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    GarbageImg_NoopStub(rdram, ctx);
        goto after_0;
    // 0x8007583C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80075840: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80075844: jal         0x80075760
    // 0x80075848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ImageRect_SetMode(rdram, ctx);
        goto after_1;
    // 0x80075848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8007584C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80075850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80075854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80075858: jal         0x800757BC
    // 0x8007585C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ImageRect_SetSource(rdram, ctx);
        goto after_2;
    // 0x8007585C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80075860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075868: jr          $ra
    // 0x8007586C: nop

    return;
    // 0x8007586C: nop

;}

RECOMP_FUNC void ImageRect_Reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075874: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80075878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007587C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80075880: jal         0x80075760
    // 0x80075884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ImageRect_SetMode(rdram, ctx);
        goto after_0;
    // 0x80075884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80075888: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007588C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80075890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80075894: jal         0x800757BC
    // 0x80075898: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ImageRect_SetSource(rdram, ctx);
        goto after_1;
    // 0x80075898: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8007589C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800758A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800758A4: jr          $ra
    // 0x800758A8: nop

    return;
    // 0x800758A8: nop

    // 0x800758AC: nop

;}

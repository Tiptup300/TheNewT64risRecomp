#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mtx3_print(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFC50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AFC54: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800AFC58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AFC5C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AFC60: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AFC64: jal         0x800B3BFC
    // 0x800AFC68: addiu       $a0, $a0, 0x1190
    ctx->r4 = ADD32(ctx->r4, 0X1190);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800AFC68: addiu       $a0, $a0, 0x1190
    ctx->r4 = ADD32(ctx->r4, 0X1190);
    after_0:
    // 0x800AFC6C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800AFC70: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800AFC74: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AFC78: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800AFC7C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800AFC80: sdc1        $f10, 0x10($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X10, ctx->r29);
    // 0x800AFC84: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AFC88: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800AFC8C: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x800AFC90: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800AFC94: addiu       $a0, $a0, 0x1194
    ctx->r4 = ADD32(ctx->r4, 0X1194);
    // 0x800AFC98: jal         0x800B3BFC
    // 0x800AFC9C: sdc1        $f18, 0x18($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X18, ctx->r29);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800AFC9C: sdc1        $f18, 0x18($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X18, ctx->r29);
    after_1:
    // 0x800AFCA0: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AFCA4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AFCA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AFCAC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800AFCB0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800AFCB4: sdc1        $f10, 0x10($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X10, ctx->r29);
    // 0x800AFCB8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800AFCBC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800AFCC0: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x800AFCC4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800AFCC8: addiu       $a0, $a0, 0x11B8
    ctx->r4 = ADD32(ctx->r4, 0X11B8);
    // 0x800AFCCC: jal         0x800B3BFC
    // 0x800AFCD0: sdc1        $f18, 0x18($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X18, ctx->r29);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800AFCD0: sdc1        $f18, 0x18($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X18, ctx->r29);
    after_2:
    // 0x800AFCD4: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800AFCD8: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800AFCDC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AFCE0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800AFCE4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800AFCE8: sdc1        $f10, 0x10($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X10, ctx->r29);
    // 0x800AFCEC: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800AFCF0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800AFCF4: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x800AFCF8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800AFCFC: addiu       $a0, $a0, 0x11DC
    ctx->r4 = ADD32(ctx->r4, 0X11DC);
    // 0x800AFD00: jal         0x800B3BFC
    // 0x800AFD04: sdc1        $f18, 0x18($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X18, ctx->r29);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x800AFD04: sdc1        $f18, 0x18($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X18, ctx->r29);
    after_3:
    // 0x800AFD08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AFD0C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AFD10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AFD14: jr          $ra
    // 0x800AFD18: nop

    return;
    // 0x800AFD18: nop

;}

RECOMP_FUNC void mtx3_mult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0890: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B0894: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800B0898: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800B089C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_800B08A0:
    // 0x800B08A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B08A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_800B08A8:
    // 0x800B08A8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800B08AC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_800B08B0:
    // 0x800B08B0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B08B4: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B08B8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B08BC: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x800B08C0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B08C4: sra         $t0, $t6, 16
    ctx->r8 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800B08C8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B08CC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x800B08D0: bne         $t0, $zero, L_800B08B0
    if (ctx->r8 != 0) {
        // 0x800B08D4: add.s       $f0, $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
            goto L_800B08B0;
    }
    // 0x800B08D4: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800B08D8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800B08DC: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x800B08E0: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800B08E4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800B08E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B08EC: addiu       $v1, $v1, -0xC
    ctx->r3 = ADD32(ctx->r3, -0XC);
    // 0x800B08F0: bne         $a1, $zero, L_800B08A8
    if (ctx->r5 != 0) {
        // 0x800B08F4: addiu       $a0, $a0, -0x20
        ctx->r4 = ADD32(ctx->r4, -0X20);
            goto L_800B08A8;
    }
    // 0x800B08F4: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x800B08F8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800B08FC: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x800B0900: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800B0904: bne         $a3, $zero, L_800B08A0
    if (ctx->r7 != 0) {
        // 0x800B0908: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_800B08A0;
    }
    // 0x800B0908: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800B090C: jr          $ra
    // 0x800B0910: nop

    return;
    // 0x800B0910: nop

;}

RECOMP_FUNC void mtx3_mult_vec3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0914: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B0918: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800B091C: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800B0920: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800B0924: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B0928: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800B092C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B0930: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B0934: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800B0938: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800B093C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800B0940: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800B0944: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800B0948: lwc1        $f18, 0xC($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800B094C: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800B0950: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800B0954: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800B0958: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800B095C: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800B0960: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B0964: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800B0968: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B096C: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800B0970: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800B0974: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800B0978: lwc1        $f8, 0x18($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800B097C: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800B0980: lwc1        $f18, 0x1C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800B0984: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800B0988: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800B098C: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B0990: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B0994: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B0998: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800B099C: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800B09A0: jr          $ra
    // 0x800B09A4: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800B09A4: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Mtx_FromEulerToGfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D6A8: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8007D6AC: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x8007D6B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D6B4: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D6B8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007D6BC: jal         0x800A4B98
    // 0x8007D6C0: addiu       $a1, $a1, 0x3044
    ctx->r5 = ADD32(ctx->r5, 0X3044);
    CubeTiles_EmitNodeSegmentDL(rdram, ctx);
        goto after_0;
    // 0x8007D6C0: addiu       $a1, $a1, 0x3044
    ctx->r5 = ADD32(ctx->r5, 0X3044);
    after_0:
    // 0x8007D6C4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007D6C8: lw          $t6, 0x3128($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3128);
    // 0x8007D6CC: sw          $v0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r2;
    // 0x8007D6D0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007D6D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D6D8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007D6DC: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D6E0: sw          $t7, 0x3128($at)
    MEM_W(0X3128, ctx->r1) = ctx->r15;
    // 0x8007D6E4: sw          $t8, 0x3128($at)
    MEM_W(0X3128, ctx->r1) = ctx->r24;
    // 0x8007D6E8: andi        $t1, $t8, 0xFFF
    ctx->r9 = ctx->r24 & 0XFFF;
    // 0x8007D6EC: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x8007D6F0: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8007D6F4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8007D6F8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8007D6FC: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8007D700: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8007D704: sw          $t0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r8;
    // 0x8007D708: or          $t4, $t3, $t1
    ctx->r12 = ctx->r11 | ctx->r9;
    // 0x8007D70C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8007D710: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8007D714: lui         $t0, 0xE300
    ctx->r8 = S32(0XE300 << 16);
    // 0x8007D718: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8007D71C: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D720: ori         $t0, $t0, 0xC00
    ctx->r8 = ctx->r8 | 0XC00;
    // 0x8007D724: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8007D728: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8007D72C: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8007D730: sw          $t9, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r25;
    // 0x8007D734: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8007D738: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8007D73C: lui         $t2, 0x8
    ctx->r10 = S32(0X8 << 16);
    // 0x8007D740: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8007D744: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D748: lui         $t5, 0xD9D8
    ctx->r13 = S32(0XD9D8 << 16);
    // 0x8007D74C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8007D750: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007D754: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x8007D758: sw          $t4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r12;
    // 0x8007D75C: ori         $t5, $t5, 0xF9FA
    ctx->r13 = ctx->r13 | 0XF9FA;
    // 0x8007D760: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8007D764: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8007D768: lui         $t8, 0xD9FF
    ctx->r24 = S32(0XD9FF << 16);
    // 0x8007D76C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8007D770: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D774: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x8007D778: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8007D77C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8007D780: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8007D784: sw          $t0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r8;
    // 0x8007D788: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8007D78C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8007D790: lui         $t3, 0x20
    ctx->r11 = S32(0X20 << 16);
    // 0x8007D794: ori         $t3, $t3, 0x4
    ctx->r11 = ctx->r11 | 0X4;
    // 0x8007D798: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8007D79C: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D7A0: lui         $t6, 0xFC11
    ctx->r14 = S32(0XFC11 << 16);
    // 0x8007D7A4: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8007D7A8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007D7AC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8007D7B0: sw          $t5, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r13;
    // 0x8007D7B4: ori         $t6, $t6, 0x9623
    ctx->r14 = ctx->r14 | 0X9623;
    // 0x8007D7B8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8007D7BC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007D7C0: lui         $t9, 0xFF2F
    ctx->r25 = S32(0XFF2F << 16);
    // 0x8007D7C4: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8007D7C8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8007D7CC: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D7D0: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x8007D7D4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007D7D8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D7DC: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x8007D7E0: sw          $t2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r10;
    // 0x8007D7E4: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x8007D7E8: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8007D7EC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D7F0: lui         $t4, 0x50
    ctx->r12 = S32(0X50 << 16);
    // 0x8007D7F4: ori         $t4, $t4, 0x4240
    ctx->r12 = ctx->r12 | 0X4240;
    // 0x8007D7F8: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8007D7FC: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D800: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x8007D804: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8007D808: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007D80C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007D810: sw          $t7, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r15;
    // 0x8007D814: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x8007D818: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007D81C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007D820: lui         $t8, 0x10
    ctx->r24 = S32(0X10 << 16);
    // 0x8007D824: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8007D828: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D82C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8007D830: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8007D834: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007D838: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x8007D83C: sw          $t1, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r9;
    // 0x8007D840: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8007D844: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8007D848: addiu       $t6, $zero, -0x80
    ctx->r14 = ADD32(0, -0X80);
    // 0x8007D84C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8007D850: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8007D854: lw          $t9, 0x312C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X312C);
    // 0x8007D858: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x8007D85C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8007D860: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007D864: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007D868: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007D86C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8007D870: jal         0x800B04BC
    // 0x8007D874: nop

    mtx4_from_euler(rdram, ctx);
        goto after_1;
    // 0x8007D874: nop

    after_1:
    // 0x8007D878: addiu       $t8, $sp, 0xA0
    ctx->r24 = ADD32(ctx->r29, 0XA0);
    // 0x8007D87C: addiu       $t3, $t8, 0x3C
    ctx->r11 = ADD32(ctx->r24, 0X3C);
    // 0x8007D880: addiu       $t0, $sp, 0x60
    ctx->r8 = ADD32(ctx->r29, 0X60);
L_8007D884:
    // 0x8007D884: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8007D888: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8007D88C: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8007D890: lw          $at, -0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X8);
    // 0x8007D894: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8007D898: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x8007D89C: lw          $at, -0x4($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X4);
    // 0x8007D8A0: bne         $t8, $t3, L_8007D884
    if (ctx->r24 != ctx->r11) {
        // 0x8007D8A4: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_8007D884;
    }
    // 0x8007D8A4: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x8007D8A8: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8007D8AC: nop

    // 0x8007D8B0: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8007D8B4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8007D8B8:
    // 0x8007D8B8: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8007D8BC: lui         $at, 0x4030
    ctx->r1 = S32(0X4030 << 16);
    // 0x8007D8C0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8007D8C4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007D8C8: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8007D8CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007D8D0: lui         $at, 0xC050
    ctx->r1 = S32(0XC050 << 16);
    // 0x8007D8D4: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8007D8D8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007D8DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007D8E0: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
    // 0x8007D8E4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007D8E8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8007D8EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007D8F0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007D8F4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8007D8F8: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8007D8FC: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x8007D900: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8007D904: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    // 0x8007D908: jal         0x800AFBBC
    // 0x8007D90C: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    mtx4_mult_vec3(rdram, ctx);
        goto after_2;
    // 0x8007D90C: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8007D910: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8007D914: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007D918: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8007D91C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007D920: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007D924: addiu       $t6, $t6, -0x150
    ctx->r14 = ADD32(ctx->r14, -0X150);
    // 0x8007D928: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x8007D92C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8007D930: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8007D934: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x8007D938: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x8007D93C: jal         0x800B78D0
    // 0x8007D940: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    guMtxF2L(rdram, ctx);
        goto after_3;
    // 0x8007D940: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8007D944: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D948: lui         $t2, 0xDA38
    ctx->r10 = S32(0XDA38 << 16);
    // 0x8007D94C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8007D950: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8007D954: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8007D958: sw          $t9, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r25;
    // 0x8007D95C: ori         $t2, $t2, 0x3
    ctx->r10 = ctx->r10 | 0X3;
    // 0x8007D960: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8007D964: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8007D968: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8007D96C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007D970: addiu       $t1, $t1, -0x150
    ctx->r9 = ADD32(ctx->r9, -0X150);
    // 0x8007D974: sll         $t0, $t8, 6
    ctx->r8 = S32(ctx->r24 << 6);
    // 0x8007D978: addu        $t4, $t0, $t1
    ctx->r12 = ADD32(ctx->r8, ctx->r9);
    // 0x8007D97C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8007D980: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D984: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x8007D988: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8007D98C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D990: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007D994: sw          $t7, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r15;
    // 0x8007D998: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007D99C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D9A0: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8007D9A4: addiu       $t3, $t3, 0x3108
    ctx->r11 = ADD32(ctx->r11, 0X3108);
    // 0x8007D9A8: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8007D9AC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8007D9B0: nop

    // 0x8007D9B4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007D9B8: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x8007D9BC: bne         $at, $zero, L_8007D8B8
    if (ctx->r1 != 0) {
        // 0x8007D9C0: sw          $t1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r9;
            goto L_8007D8B8;
    }
    // 0x8007D9C0: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8007D9C4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8007D9C8: lw          $t4, 0x312C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X312C);
    // 0x8007D9CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D9D0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007D9D4: sw          $t5, 0x312C($at)
    MEM_W(0X312C, ctx->r1) = ctx->r13;
    // 0x8007D9D8: slti        $at, $t5, 0x169
    ctx->r1 = SIGNED(ctx->r13) < 0X169 ? 1 : 0;
    // 0x8007D9DC: bne         $at, $zero, L_8007D9F0
    if (ctx->r1 != 0) {
        // 0x8007D9E0: nop
    
            goto L_8007D9F0;
    }
    // 0x8007D9E0: nop

    // 0x8007D9E4: addiu       $t6, $t5, -0x168
    ctx->r14 = ADD32(ctx->r13, -0X168);
    // 0x8007D9E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D9EC: sw          $t6, 0x312C($at)
    MEM_W(0X312C, ctx->r1) = ctx->r14;
L_8007D9F0:
    // 0x8007D9F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D9F4: lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D9F8: jr          $ra
    // 0x8007D9FC: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8007D9FC: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}

RECOMP_FUNC void Mtx_AllocIdentityF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC9C0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800AC9C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AC9C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AC9CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AC9D0: jal         0x8007E03C
    // 0x800AC9D4: addiu       $a0, $a0, 0x150C
    ctx->r4 = ADD32(ctx->r4, 0X150C);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800AC9D4: addiu       $a0, $a0, 0x150C
    ctx->r4 = ADD32(ctx->r4, 0X150C);
    after_0:
    // 0x800AC9D8: bne         $v0, $zero, L_800AC9E8
    if (ctx->r2 != 0) {
        // 0x800AC9DC: addiu       $t3, $v0, 0x80
        ctx->r11 = ADD32(ctx->r2, 0X80);
            goto L_800AC9E8;
    }
    // 0x800AC9DC: addiu       $t3, $v0, 0x80
    ctx->r11 = ADD32(ctx->r2, 0X80);
    // 0x800AC9E0: b           L_800ACCC8
    // 0x800AC9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ACCC8;
    // 0x800AC9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AC9E8:
    // 0x800AC9E8: addiu       $v1, $t3, 0x100
    ctx->r3 = ADD32(ctx->r11, 0X100);
    // 0x800AC9EC: addiu       $t5, $v1, 0x20
    ctx->r13 = ADD32(ctx->r3, 0X20);
    // 0x800AC9F0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800AC9F4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800AC9F8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800AC9FC: addiu       $a1, $t5, 0x1E8
    ctx->r5 = ADD32(ctx->r13, 0X1E8);
    // 0x800ACA00: addiu       $t6, $zero, 0x818
    ctx->r14 = ADD32(0, 0X818);
    // 0x800ACA04: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ACA08: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x800ACA0C: sb          $zero, 0x4($t5)
    MEM_B(0X4, ctx->r13) = 0;
    // 0x800ACA10: sb          $zero, 0x5($t5)
    MEM_B(0X5, ctx->r13) = 0;
    // 0x800ACA14: sh          $t7, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r15;
    // 0x800ACA18: sw          $a1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r5;
    // 0x800ACA1C: addiu       $a2, $a1, 0x4C
    ctx->r6 = ADD32(ctx->r5, 0X4C);
    // 0x800ACA20: addiu       $a3, $a2, 0x240
    ctx->r7 = ADD32(ctx->r6, 0X240);
    // 0x800ACA24: addiu       $t0, $a3, 0x30
    ctx->r8 = ADD32(ctx->r7, 0X30);
    // 0x800ACA28: addiu       $t2, $t0, 0xE0
    ctx->r10 = ADD32(ctx->r8, 0XE0);
    // 0x800ACA2C: addiu       $v1, $t2, 0x20
    ctx->r3 = ADD32(ctx->r10, 0X20);
    // 0x800ACA30: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x800ACA34: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800ACA38: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800ACA3C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800ACA40: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x800ACA44: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x800ACA48: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800ACA4C: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x800ACA50: jal         0x800B79D0
    // 0x800ACA54: addiu       $a0, $t5, 0xC
    ctx->r4 = ADD32(ctx->r13, 0XC);
    guMtxIdentF(rdram, ctx);
        goto after_1;
    // 0x800ACA54: addiu       $a0, $t5, 0xC
    ctx->r4 = ADD32(ctx->r13, 0XC);
    after_1:
    // 0x800ACA58: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800ACA5C: jal         0x800B79D0
    // 0x800ACA60: addiu       $a0, $t5, 0x4C
    ctx->r4 = ADD32(ctx->r13, 0X4C);
    guMtxIdentF(rdram, ctx);
        goto after_2;
    // 0x800ACA60: addiu       $a0, $t5, 0x4C
    ctx->r4 = ADD32(ctx->r13, 0X4C);
    after_2:
    // 0x800ACA64: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800ACA68: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800ACA6C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800ACA70: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800ACA74: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800ACA78: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800ACA7C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800ACA80: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800ACA84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ACA88: addiu       $t4, $zero, 0x320
    ctx->r12 = ADD32(0, 0X320);
    // 0x800ACA8C: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x800ACA90: sb          $zero, 0x1D4($t5)
    MEM_B(0X1D4, ctx->r13) = 0;
    // 0x800ACA94: sb          $zero, 0x1D5($t5)
    MEM_B(0X1D5, ctx->r13) = 0;
    // 0x800ACA98: sb          $zero, 0x1D6($t5)
    MEM_B(0X1D6, ctx->r13) = 0;
    // 0x800ACA9C: sb          $v0, 0x1D7($t5)
    MEM_B(0X1D7, ctx->r13) = ctx->r2;
    // 0x800ACAA0: sw          $t4, 0x1D8($t5)
    MEM_W(0X1D8, ctx->r13) = ctx->r12;
    // 0x800ACAA4: sw          $t8, 0x1DC($t5)
    MEM_W(0X1DC, ctx->r13) = ctx->r24;
    // 0x800ACAA8: sw          $zero, 0x1D0($t5)
    MEM_W(0X1D0, ctx->r13) = 0;
    // 0x800ACAAC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800ACAB0: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x800ACAB4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800ACAB8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800ACABC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800ACAC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ACAC4: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x800ACAC8: sw          $t7, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r15;
    // 0x800ACACC: sw          $zero, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = 0;
    // 0x800ACAD0: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x800ACAD4: sw          $zero, 0x24($a1)
    MEM_W(0X24, ctx->r5) = 0;
    // 0x800ACAD8: sw          $zero, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = 0;
    // 0x800ACADC: sw          $zero, 0x48($a1)
    MEM_W(0X48, ctx->r5) = 0;
    // 0x800ACAE0: sw          $a2, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r6;
    // 0x800ACAE4: sw          $a3, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r7;
    // 0x800ACAE8: sw          $t2, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->r10;
    // 0x800ACAEC: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800ACAF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ACAF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800ACAF8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800ACAFC: sb          $v0, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r2;
    // 0x800ACB00: addiu       $ra, $zero, 0x100
    ctx->r31 = ADD32(0, 0X100);
    // 0x800ACB04: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x800ACB08: sh          $ra, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r31;
    // 0x800ACB0C: sb          $zero, 0x3($a2)
    MEM_B(0X3, ctx->r6) = 0;
    // 0x800ACB10: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x800ACB14: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800ACB18: sw          $t1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r9;
    // 0x800ACB1C: swc1        $f0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f0.u32l;
    // 0x800ACB20: swc1        $f0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f0.u32l;
    // 0x800ACB24: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800ACB28: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x800ACB2C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800ACB30: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x800ACB34: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x800ACB38: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800ACB3C: beq         $at, $zero, L_800ACB64
    if (ctx->r1 == 0) {
        // 0x800ACB40: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_800ACB64;
    }
    // 0x800ACB40: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800ACB44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800ACB48: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800ACB4C: nop

L_800ACB50:
    // 0x800ACB50: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800ACB54: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x800ACB58: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x800ACB5C: bne         $at, $zero, L_800ACB50
    if (ctx->r1 != 0) {
        // 0x800ACB60: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800ACB50;
    }
    // 0x800ACB60: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800ACB64:
    // 0x800ACB64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800ACB68: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800ACB6C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800ACB70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ACB74: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x800ACB78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ACB7C: sw          $s0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r16;
    // 0x800ACB80: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800ACB84: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
    // 0x800ACB88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACB8C: swc1        $f2, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f2.u32l;
    // 0x800ACB90: swc1        $f2, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f2.u32l;
    // 0x800ACB94: swc1        $f4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f4.u32l;
    // 0x800ACB98: swc1        $f6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f6.u32l;
    // 0x800ACB9C: lwc1        $f8, 0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1170);
    // 0x800ACBA0: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x800ACBA4: addiu       $t1, $t1, 0x188
    ctx->r9 = ADD32(ctx->r9, 0X188);
    // 0x800ACBA8: swc1        $f8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f8.u32l;
    // 0x800ACBAC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800ACBB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800ACBB4: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x800ACBB8: sw          $t9, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r25;
    // 0x800ACBBC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800ACBC0: addiu       $v1, $zero, 0x258
    ctx->r3 = ADD32(0, 0X258);
    // 0x800ACBC4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800ACBC8: sw          $t6, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r14;
L_800ACBCC:
    // 0x800ACBCC: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800ACBD0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800ACBD4: sh          $t4, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r12;
    // 0x800ACBD8: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
    // 0x800ACBDC: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800ACBE0: sh          $v1, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r3;
    // 0x800ACBE4: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800ACBE8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800ACBEC: sh          $a0, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r4;
    // 0x800ACBF0: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
    // 0x800ACBF4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800ACBF8: sh          $zero, 0x6($t6)
    MEM_H(0X6, ctx->r14) = 0;
    // 0x800ACBFC: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800ACC00: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800ACC04: sh          $t4, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r12;
    // 0x800ACC08: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
    // 0x800ACC0C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800ACC10: sh          $v1, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r3;
    // 0x800ACC14: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800ACC18: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800ACC1C: sh          $zero, 0xC($t8)
    MEM_H(0XC, ctx->r24) = 0;
    // 0x800ACC20: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
    // 0x800ACC24: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800ACC28: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800ACC2C: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800ACC30: bne         $at, $zero, L_800ACBCC
    if (ctx->r1 != 0) {
        // 0x800ACC34: sh          $zero, 0xE($t6)
        MEM_H(0XE, ctx->r14) = 0;
            goto L_800ACBCC;
    }
    // 0x800ACC34: sh          $zero, 0xE($t6)
    MEM_H(0XE, ctx->r14) = 0;
    // 0x800ACC38: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x800ACC3C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800ACC40: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800ACC44: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_800ACC48:
    // 0x800ACC48: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800ACC4C: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x800ACC50: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800ACC54: swc1        $f2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f2.u32l;
    // 0x800ACC58: swc1        $f2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f2.u32l;
    // 0x800ACC5C: swc1        $f2, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f2.u32l;
    // 0x800ACC60: swc1        $f2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f2.u32l;
    // 0x800ACC64: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    // 0x800ACC68: sh          $ra, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r31;
    // 0x800ACC6C: sb          $a3, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r7;
    // 0x800ACC70: sb          $zero, 0x3($a2)
    MEM_B(0X3, ctx->r6) = 0;
    // 0x800ACC74: sw          $t1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r9;
    // 0x800ACC78: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x800ACC7C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800ACC80: swc1        $f0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f0.u32l;
    // 0x800ACC84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800ACC88: addiu       $v0, $a2, 0x4
    ctx->r2 = ADD32(ctx->r6, 0X4);
L_800ACC8C:
    // 0x800ACC8C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800ACC90: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x800ACC94: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x800ACC98: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x800ACC9C: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x800ACCA0: bne         $v1, $a0, L_800ACC8C
    if (ctx->r3 != ctx->r4) {
        // 0x800ACCA4: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_800ACC8C;
    }
    // 0x800ACCA4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800ACCA8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800ACCAC: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x800ACCB0: addiu       $t0, $t0, 0x1C
    ctx->r8 = ADD32(ctx->r8, 0X1C);
    // 0x800ACCB4: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800ACCB8: addiu       $t1, $t1, 0x188
    ctx->r9 = ADD32(ctx->r9, 0X188);
    // 0x800ACCBC: bne         $a1, $zero, L_800ACC48
    if (ctx->r5 != 0) {
        // 0x800ACCC0: addiu       $t3, $t3, 0x20
        ctx->r11 = ADD32(ctx->r11, 0X20);
            goto L_800ACC48;
    }
    // 0x800ACCC0: addiu       $t3, $t3, 0x20
    ctx->r11 = ADD32(ctx->r11, 0X20);
    // 0x800ACCC4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800ACCC8:
    // 0x800ACCC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACCCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800ACCD0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800ACCD4: jr          $ra
    // 0x800ACCD8: nop

    return;
    // 0x800ACCD8: nop

;}

RECOMP_FUNC void Mtx_AllocIdentity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADE5C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800ADE60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800ADE64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ADE68: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ADE6C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ADE70: bgez        $a2, L_800ADE84
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800ADE74: andi        $t6, $a2, 0x3F
        ctx->r14 = ctx->r6 & 0X3F;
            goto L_800ADE84;
    }
    // 0x800ADE74: andi        $t6, $a2, 0x3F
    ctx->r14 = ctx->r6 & 0X3F;
    // 0x800ADE78: beq         $t6, $zero, L_800ADE84
    if (ctx->r14 == 0) {
        // 0x800ADE7C: nop
    
            goto L_800ADE84;
    }
    // 0x800ADE7C: nop

    // 0x800ADE80: addiu       $t6, $t6, -0x40
    ctx->r14 = ADD32(ctx->r14, -0X40);
L_800ADE84:
    // 0x800ADE84: blez        $t6, L_800ADE94
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800ADE88: addiu       $a0, $zero, 0x1E
        ctx->r4 = ADD32(0, 0X1E);
            goto L_800ADE94;
    }
    // 0x800ADE88: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x800ADE8C: b           L_800ADE98
    // 0x800ADE90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800ADE98;
    // 0x800ADE90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ADE94:
    // 0x800ADE94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ADE98:
    // 0x800ADE98: div         $zero, $a1, $a0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r4)));
    // 0x800ADE9C: bgez        $a2, L_800ADEAC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800ADEA0: sra         $t7, $a2, 6
        ctx->r15 = S32(SIGNED(ctx->r6) >> 6);
            goto L_800ADEAC;
    }
    // 0x800ADEA0: sra         $t7, $a2, 6
    ctx->r15 = S32(SIGNED(ctx->r6) >> 6);
    // 0x800ADEA4: addiu       $at, $a2, 0x3F
    ctx->r1 = ADD32(ctx->r6, 0X3F);
    // 0x800ADEA8: sra         $t7, $at, 6
    ctx->r15 = S32(SIGNED(ctx->r1) >> 6);
L_800ADEAC:
    // 0x800ADEAC: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x800ADEB0: bne         $a0, $zero, L_800ADEBC
    if (ctx->r4 != 0) {
        // 0x800ADEB4: nop
    
            goto L_800ADEBC;
    }
    // 0x800ADEB4: nop

    // 0x800ADEB8: break       7
    do_break(2148196024);
L_800ADEBC:
    // 0x800ADEBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800ADEC0: bne         $a0, $at, L_800ADED4
    if (ctx->r4 != ctx->r1) {
        // 0x800ADEC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800ADED4;
    }
    // 0x800ADEC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ADEC8: bne         $a1, $at, L_800ADED4
    if (ctx->r5 != ctx->r1) {
        // 0x800ADECC: nop
    
            goto L_800ADED4;
    }
    // 0x800ADECC: nop

    // 0x800ADED0: break       6
    do_break(2148196048);
L_800ADED4:
    // 0x800ADED4: mflo        $v1
    ctx->r3 = lo;
    // 0x800ADED8: mfhi        $t8
    ctx->r24 = hi;
    // 0x800ADEDC: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800ADEE0: blez        $t8, L_800ADEF0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800ADEE4: sll         $t9, $t5, 6
        ctx->r25 = S32(ctx->r13 << 6);
            goto L_800ADEF0;
    }
    // 0x800ADEE4: sll         $t9, $t5, 6
    ctx->r25 = S32(ctx->r13 << 6);
    // 0x800ADEE8: b           L_800ADEF4
    // 0x800ADEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800ADEF4;
    // 0x800ADEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ADEF0:
    // 0x800ADEF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ADEF4:
    // 0x800ADEF4: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800ADEF8: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADEFC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800ADF00: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800ADF04: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800ADF08: mflo        $a0
    ctx->r4 = lo;
    // 0x800ADF0C: addiu       $a0, $a0, 0x148
    ctx->r4 = ADD32(ctx->r4, 0X148);
    // 0x800ADF10: jal         0x8007E03C
    // 0x800ADF14: nop

    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800ADF14: nop

    after_0:
    // 0x800ADF18: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800ADF1C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADF20: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800ADF24: sll         $a2, $t0, 1
    ctx->r6 = S32(ctx->r8 << 1);
    // 0x800ADF28: sll         $a3, $t1, 1
    ctx->r7 = S32(ctx->r9 << 1);
    // 0x800ADF2C: addiu       $t6, $zero, 0x3FF
    ctx->r14 = ADD32(0, 0X3FF);
    // 0x800ADF30: addiu       $a1, $v0, 0x148
    ctx->r5 = ADD32(ctx->r2, 0X148);
    // 0x800ADF34: sw          $s0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r16;
    // 0x800ADF38: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800ADF3C: sh          $a2, 0x118($v0)
    MEM_H(0X118, ctx->r2) = ctx->r6;
    // 0x800ADF40: sh          $a3, 0x11A($v0)
    MEM_H(0X11A, ctx->r2) = ctx->r7;
    // 0x800ADF44: sh          $t6, 0x11C($v0)
    MEM_H(0X11C, ctx->r2) = ctx->r14;
    // 0x800ADF48: sh          $zero, 0x11E($v0)
    MEM_H(0X11E, ctx->r2) = 0;
    // 0x800ADF4C: sh          $a2, 0x120($v0)
    MEM_H(0X120, ctx->r2) = ctx->r6;
    // 0x800ADF50: sh          $a3, 0x122($v0)
    MEM_H(0X122, ctx->r2) = ctx->r7;
    // 0x800ADF54: sh          $zero, 0x124($v0)
    MEM_H(0X124, ctx->r2) = 0;
    // 0x800ADF58: sh          $zero, 0x126($v0)
    MEM_H(0X126, ctx->r2) = 0;
    // 0x800ADF5C: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    // 0x800ADF60: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800ADF64: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800ADF68: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800ADF6C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800ADF70: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x800ADF74: jal         0x800B7A58
    // 0x800ADF78: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    guMtxIdent(rdram, ctx);
        goto after_1;
    // 0x800ADF78: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    after_1:
    // 0x800ADF7C: jal         0x800B7A58
    // 0x800ADF80: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    guMtxIdent(rdram, ctx);
        goto after_2;
    // 0x800ADF80: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_2:
    // 0x800ADF84: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800ADF88: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800ADF8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ADF90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800ADF94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800ADF98: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800ADF9C: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800ADFA0: swc1        $f0, 0x128($s1)
    MEM_W(0X128, ctx->r17) = ctx->f0.u32l;
    // 0x800ADFA4: swc1        $f0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->f0.u32l;
    // 0x800ADFA8: swc1        $f0, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->f0.u32l;
    // 0x800ADFAC: swc1        $f0, 0x140($s1)
    MEM_W(0X140, ctx->r17) = ctx->f0.u32l;
    // 0x800ADFB0: swc1        $f2, 0x134($s1)
    MEM_W(0X134, ctx->r17) = ctx->f2.u32l;
    // 0x800ADFB4: swc1        $f2, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->f2.u32l;
    // 0x800ADFB8: blez        $s0, L_800AE208
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800ADFBC: swc1        $f2, 0x13C($s1)
        MEM_W(0X13C, ctx->r17) = ctx->f2.u32l;
            goto L_800AE208;
    }
    // 0x800ADFBC: swc1        $f2, 0x13C($s1)
    MEM_W(0X13C, ctx->r17) = ctx->f2.u32l;
    // 0x800ADFC0: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x800ADFC4: addiu       $t2, $zero, 0x741
    ctx->r10 = ADD32(0, 0X741);
    // 0x800ADFC8: addiu       $t1, $zero, 0xFC1
    ctx->r9 = ADD32(0, 0XFC1);
    // 0x800ADFCC: addiu       $a3, $zero, -0x3F
    ctx->r7 = ADD32(0, -0X3F);
    // 0x800ADFD0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800ADFD4:
    // 0x800ADFD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800ADFD8: blez        $t5, L_800AE1FC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800ADFDC: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_800AE1FC;
    }
    // 0x800ADFDC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800ADFE0: andi        $a0, $t5, 0x1
    ctx->r4 = ctx->r13 & 0X1;
    // 0x800ADFE4: beq         $a0, $zero, L_800AE09C
    if (ctx->r4 == 0) {
        // 0x800ADFE8: addiu       $a1, $t0, 0x1E
        ctx->r5 = ADD32(ctx->r8, 0X1E);
            goto L_800AE09C;
    }
    // 0x800ADFE8: addiu       $a1, $t0, 0x1E
    ctx->r5 = ADD32(ctx->r8, 0X1E);
    // 0x800ADFEC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800ADFF0: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800ADFF4: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
    // 0x800ADFF8: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x800ADFFC: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x800AE000: sh          $a3, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r7;
    // 0x800AE004: sh          $a3, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r7;
    // 0x800AE008: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x800AE00C: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // 0x800AE010: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x800AE014: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    // 0x800AE018: sh          $t4, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r12;
    // 0x800AE01C: sh          $t0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r8;
    // 0x800AE020: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x800AE024: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x800AE028: sh          $t1, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r9;
    // 0x800AE02C: sh          $a3, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r7;
    // 0x800AE030: sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
    // 0x800AE034: sb          $v0, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r2;
    // 0x800AE038: sb          $v0, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r2;
    // 0x800AE03C: sb          $v0, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = ctx->r2;
    // 0x800AE040: sh          $t4, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r12;
    // 0x800AE044: sh          $a1, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r5;
    // 0x800AE048: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x800AE04C: sh          $zero, 0x26($v1)
    MEM_H(0X26, ctx->r3) = 0;
    // 0x800AE050: sh          $t1, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r9;
    // 0x800AE054: sh          $t2, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r10;
    // 0x800AE058: sb          $v0, 0x2C($v1)
    MEM_B(0X2C, ctx->r3) = ctx->r2;
    // 0x800AE05C: sb          $v0, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = ctx->r2;
    // 0x800AE060: sb          $v0, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = ctx->r2;
    // 0x800AE064: sb          $v0, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = ctx->r2;
    // 0x800AE068: sh          $zero, 0x30($v1)
    MEM_H(0X30, ctx->r3) = 0;
    // 0x800AE06C: sh          $a1, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r5;
    // 0x800AE070: sh          $zero, 0x34($v1)
    MEM_H(0X34, ctx->r3) = 0;
    // 0x800AE074: sh          $zero, 0x36($v1)
    MEM_H(0X36, ctx->r3) = 0;
    // 0x800AE078: sh          $a3, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r7;
    // 0x800AE07C: sh          $t2, 0x3A($v1)
    MEM_H(0X3A, ctx->r3) = ctx->r10;
    // 0x800AE080: sb          $v0, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = ctx->r2;
    // 0x800AE084: sb          $v0, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = ctx->r2;
    // 0x800AE088: sb          $v0, 0x3E($v1)
    MEM_B(0X3E, ctx->r3) = ctx->r2;
    // 0x800AE08C: sb          $v0, 0x3F($v1)
    MEM_B(0X3F, ctx->r3) = ctx->r2;
    // 0x800AE090: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AE094: beq         $t3, $t5, L_800AE1FC
    if (ctx->r11 == ctx->r13) {
        // 0x800AE098: or          $a2, $t4, $zero
        ctx->r6 = ctx->r12 | 0;
            goto L_800AE1FC;
    }
    // 0x800AE098: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
L_800AE09C:
    // 0x800AE09C: addiu       $a1, $t0, 0x1E
    ctx->r5 = ADD32(ctx->r8, 0X1E);
L_800AE0A0:
    // 0x800AE0A0: addiu       $a0, $a2, 0x40
    ctx->r4 = ADD32(ctx->r6, 0X40);
    // 0x800AE0A4: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x800AE0A8: sh          $a2, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r6;
    // 0x800AE0AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800AE0B0: sh          $a0, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r4;
    // 0x800AE0B4: sh          $a0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r4;
    // 0x800AE0B8: sh          $a0, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r4;
    // 0x800AE0BC: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x800AE0C0: sh          $a2, 0x70($v1)
    MEM_H(0X70, ctx->r3) = ctx->r6;
    // 0x800AE0C4: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    // 0x800AE0C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800AE0CC: sh          $a0, 0x50($v1)
    MEM_H(0X50, ctx->r3) = ctx->r4;
    // 0x800AE0D0: sh          $a0, 0x60($v1)
    MEM_H(0X60, ctx->r3) = ctx->r4;
    // 0x800AE0D4: sh          $t0, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r8;
    // 0x800AE0D8: sh          $zero, 0x44($v1)
    MEM_H(0X44, ctx->r3) = 0;
    // 0x800AE0DC: sh          $zero, 0x46($v1)
    MEM_H(0X46, ctx->r3) = 0;
    // 0x800AE0E0: sh          $a3, 0x48($v1)
    MEM_H(0X48, ctx->r3) = ctx->r7;
    // 0x800AE0E4: sh          $a3, 0x4A($v1)
    MEM_H(0X4A, ctx->r3) = ctx->r7;
    // 0x800AE0E8: sb          $v0, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r2;
    // 0x800AE0EC: sb          $v0, 0x4D($v1)
    MEM_B(0X4D, ctx->r3) = ctx->r2;
    // 0x800AE0F0: sb          $v0, 0x4E($v1)
    MEM_B(0X4E, ctx->r3) = ctx->r2;
    // 0x800AE0F4: sb          $v0, 0x4F($v1)
    MEM_B(0X4F, ctx->r3) = ctx->r2;
    // 0x800AE0F8: sh          $t0, 0x52($v1)
    MEM_H(0X52, ctx->r3) = ctx->r8;
    // 0x800AE0FC: sh          $zero, 0x54($v1)
    MEM_H(0X54, ctx->r3) = 0;
    // 0x800AE100: sh          $zero, 0x56($v1)
    MEM_H(0X56, ctx->r3) = 0;
    // 0x800AE104: sh          $t1, 0x58($v1)
    MEM_H(0X58, ctx->r3) = ctx->r9;
    // 0x800AE108: sh          $a3, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = ctx->r7;
    // 0x800AE10C: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
    // 0x800AE110: sb          $v0, 0x5D($v1)
    MEM_B(0X5D, ctx->r3) = ctx->r2;
    // 0x800AE114: sb          $v0, 0x5E($v1)
    MEM_B(0X5E, ctx->r3) = ctx->r2;
    // 0x800AE118: sb          $v0, 0x5F($v1)
    MEM_B(0X5F, ctx->r3) = ctx->r2;
    // 0x800AE11C: sh          $a1, 0x62($v1)
    MEM_H(0X62, ctx->r3) = ctx->r5;
    // 0x800AE120: sh          $zero, 0x64($v1)
    MEM_H(0X64, ctx->r3) = 0;
    // 0x800AE124: sh          $zero, 0x66($v1)
    MEM_H(0X66, ctx->r3) = 0;
    // 0x800AE128: sh          $t1, 0x68($v1)
    MEM_H(0X68, ctx->r3) = ctx->r9;
    // 0x800AE12C: sh          $t2, 0x6A($v1)
    MEM_H(0X6A, ctx->r3) = ctx->r10;
    // 0x800AE130: sb          $v0, 0x6C($v1)
    MEM_B(0X6C, ctx->r3) = ctx->r2;
    // 0x800AE134: sb          $v0, 0x6D($v1)
    MEM_B(0X6D, ctx->r3) = ctx->r2;
    // 0x800AE138: sb          $v0, 0x6E($v1)
    MEM_B(0X6E, ctx->r3) = ctx->r2;
    // 0x800AE13C: sb          $v0, 0x6F($v1)
    MEM_B(0X6F, ctx->r3) = ctx->r2;
    // 0x800AE140: sh          $a1, 0x72($v1)
    MEM_H(0X72, ctx->r3) = ctx->r5;
    // 0x800AE144: sh          $zero, 0x74($v1)
    MEM_H(0X74, ctx->r3) = 0;
    // 0x800AE148: sh          $zero, 0x76($v1)
    MEM_H(0X76, ctx->r3) = 0;
    // 0x800AE14C: sh          $a3, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r7;
    // 0x800AE150: sh          $t2, 0x7A($v1)
    MEM_H(0X7A, ctx->r3) = ctx->r10;
    // 0x800AE154: sb          $v0, 0x7C($v1)
    MEM_B(0X7C, ctx->r3) = ctx->r2;
    // 0x800AE158: sb          $v0, 0x7D($v1)
    MEM_B(0X7D, ctx->r3) = ctx->r2;
    // 0x800AE15C: sb          $v0, 0x7E($v1)
    MEM_B(0X7E, ctx->r3) = ctx->r2;
    // 0x800AE160: sb          $v0, 0x7F($v1)
    MEM_B(0X7F, ctx->r3) = ctx->r2;
    // 0x800AE164: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800AE168: sh          $t0, -0x7E($v1)
    MEM_H(-0X7E, ctx->r3) = ctx->r8;
    // 0x800AE16C: sh          $zero, -0x7C($v1)
    MEM_H(-0X7C, ctx->r3) = 0;
    // 0x800AE170: sh          $zero, -0x7A($v1)
    MEM_H(-0X7A, ctx->r3) = 0;
    // 0x800AE174: sh          $a3, -0x78($v1)
    MEM_H(-0X78, ctx->r3) = ctx->r7;
    // 0x800AE178: sh          $a3, -0x76($v1)
    MEM_H(-0X76, ctx->r3) = ctx->r7;
    // 0x800AE17C: sb          $v0, -0x74($v1)
    MEM_B(-0X74, ctx->r3) = ctx->r2;
    // 0x800AE180: sb          $v0, -0x73($v1)
    MEM_B(-0X73, ctx->r3) = ctx->r2;
    // 0x800AE184: sb          $v0, -0x72($v1)
    MEM_B(-0X72, ctx->r3) = ctx->r2;
    // 0x800AE188: sb          $v0, -0x71($v1)
    MEM_B(-0X71, ctx->r3) = ctx->r2;
    // 0x800AE18C: sh          $t0, -0x6E($v1)
    MEM_H(-0X6E, ctx->r3) = ctx->r8;
    // 0x800AE190: sh          $zero, -0x6C($v1)
    MEM_H(-0X6C, ctx->r3) = 0;
    // 0x800AE194: sh          $zero, -0x6A($v1)
    MEM_H(-0X6A, ctx->r3) = 0;
    // 0x800AE198: sh          $t1, -0x68($v1)
    MEM_H(-0X68, ctx->r3) = ctx->r9;
    // 0x800AE19C: sh          $a3, -0x66($v1)
    MEM_H(-0X66, ctx->r3) = ctx->r7;
    // 0x800AE1A0: sb          $v0, -0x64($v1)
    MEM_B(-0X64, ctx->r3) = ctx->r2;
    // 0x800AE1A4: sb          $v0, -0x63($v1)
    MEM_B(-0X63, ctx->r3) = ctx->r2;
    // 0x800AE1A8: sb          $v0, -0x62($v1)
    MEM_B(-0X62, ctx->r3) = ctx->r2;
    // 0x800AE1AC: sb          $v0, -0x61($v1)
    MEM_B(-0X61, ctx->r3) = ctx->r2;
    // 0x800AE1B0: sh          $a1, -0x5E($v1)
    MEM_H(-0X5E, ctx->r3) = ctx->r5;
    // 0x800AE1B4: sh          $zero, -0x5C($v1)
    MEM_H(-0X5C, ctx->r3) = 0;
    // 0x800AE1B8: sh          $zero, -0x5A($v1)
    MEM_H(-0X5A, ctx->r3) = 0;
    // 0x800AE1BC: sh          $t1, -0x58($v1)
    MEM_H(-0X58, ctx->r3) = ctx->r9;
    // 0x800AE1C0: sh          $t2, -0x56($v1)
    MEM_H(-0X56, ctx->r3) = ctx->r10;
    // 0x800AE1C4: sb          $v0, -0x54($v1)
    MEM_B(-0X54, ctx->r3) = ctx->r2;
    // 0x800AE1C8: sb          $v0, -0x53($v1)
    MEM_B(-0X53, ctx->r3) = ctx->r2;
    // 0x800AE1CC: sb          $v0, -0x52($v1)
    MEM_B(-0X52, ctx->r3) = ctx->r2;
    // 0x800AE1D0: sb          $v0, -0x51($v1)
    MEM_B(-0X51, ctx->r3) = ctx->r2;
    // 0x800AE1D4: sh          $a1, -0x4E($v1)
    MEM_H(-0X4E, ctx->r3) = ctx->r5;
    // 0x800AE1D8: sh          $zero, -0x4C($v1)
    MEM_H(-0X4C, ctx->r3) = 0;
    // 0x800AE1DC: sh          $zero, -0x4A($v1)
    MEM_H(-0X4A, ctx->r3) = 0;
    // 0x800AE1E0: sh          $a3, -0x48($v1)
    MEM_H(-0X48, ctx->r3) = ctx->r7;
    // 0x800AE1E4: sh          $t2, -0x46($v1)
    MEM_H(-0X46, ctx->r3) = ctx->r10;
    // 0x800AE1E8: sb          $v0, -0x44($v1)
    MEM_B(-0X44, ctx->r3) = ctx->r2;
    // 0x800AE1EC: sb          $v0, -0x43($v1)
    MEM_B(-0X43, ctx->r3) = ctx->r2;
    // 0x800AE1F0: sb          $v0, -0x42($v1)
    MEM_B(-0X42, ctx->r3) = ctx->r2;
    // 0x800AE1F4: bne         $t3, $t5, L_800AE0A0
    if (ctx->r11 != ctx->r13) {
        // 0x800AE1F8: sb          $v0, -0x41($v1)
        MEM_B(-0X41, ctx->r3) = ctx->r2;
            goto L_800AE0A0;
    }
    // 0x800AE1F8: sb          $v0, -0x41($v1)
    MEM_B(-0X41, ctx->r3) = ctx->r2;
L_800AE1FC:
    // 0x800AE1FC: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800AE200: bne         $ra, $s0, L_800ADFD4
    if (ctx->r31 != ctx->r16) {
        // 0x800AE204: addiu       $t0, $t0, 0x1E
        ctx->r8 = ADD32(ctx->r8, 0X1E);
            goto L_800ADFD4;
    }
    // 0x800AE204: addiu       $t0, $t0, 0x1E
    ctx->r8 = ADD32(ctx->r8, 0X1E);
L_800AE208:
    // 0x800AE208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE20C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800AE210: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AE214: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AE218: jr          $ra
    // 0x800AE21C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800AE21C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Mtx_BuildRotationFixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE70C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800AE710: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AE714: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AE718: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AE71C: jal         0x800B81D0
    // 0x800AE720: lwc1        $f12, 0x140($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X140);
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x800AE720: lwc1        $f12, 0x140($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X140);
    after_0:
    // 0x800AE724: lwc1        $f12, 0x140($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X140);
    // 0x800AE728: jal         0x800B7B40
    // 0x800AE72C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800AE72C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800AE730: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800AE734: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800AE738: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800AE73C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800AE740: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800AE744: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AE748: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AE74C: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800AE750: lwc1        $f2, 0x134($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800AE754: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800AE758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AE75C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AE760: mul.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AE764: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AE768: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800AE76C: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AE770: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800AE774: mul.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800AE778: nop

    // 0x800AE77C: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AE780: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x800AE784: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x800AE788: lwc1        $f12, 0x138($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800AE78C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x800AE790: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800AE794: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800AE798: nop

    // 0x800AE79C: mul.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800AE7A0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x800AE7A4: jal         0x800A8FC8
    // 0x800AE7A8: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    CubeTiles_FillHalfwords(rdram, ctx);
        goto after_2;
    // 0x800AE7A8: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x800AE7AC: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800AE7B0: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AE7B4: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800AE7B8: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x800AE7BC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800AE7C0: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800AE7C4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800AE7C8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800AE7CC: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AE7D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AE7D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800AE7D8: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800AE7DC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800AE7E0: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x800AE7E4: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x800AE7E8: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800AE7EC: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x800AE7F0: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    // 0x800AE7F4: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x800AE7F8: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800AE7FC: lwc1        $f8, 0x128($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X128);
    // 0x800AE800: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AE804: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800AE808: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AE80C: add.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800AE810: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800AE814: sub.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f8.d - ctx->f0.d;
    // 0x800AE818: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x800AE81C: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800AE820: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800AE824: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x800AE828: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AE82C: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AE830: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800AE834: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AE838: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800AE83C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800AE840: sub.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f8.d - ctx->f0.d;
    // 0x800AE844: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800AE848: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x800AE84C: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x800AE850: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800AE854: addu        $a1, $s0, $t9
    ctx->r5 = ADD32(ctx->r16, ctx->r25);
    // 0x800AE858: jal         0x800B78D0
    // 0x800AE85C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    guMtxF2L(rdram, ctx);
        goto after_3;
    // 0x800AE85C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_3:
    // 0x800AE860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE864: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AE868: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x800AE86C: jr          $ra
    // 0x800AE870: nop

    return;
    // 0x800AE870: nop

    // 0x800AE874: nop

    // 0x800AE878: nop

    // 0x800AE87C: nop

;}

RECOMP_FUNC void Mtx_InvertAffineF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE880: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AE884: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800AE888: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AE88C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800AE890: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800AE894: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AE898: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800AE89C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800AE8A0: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800AE8A4: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AE8A8: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AE8AC: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800AE8B0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AE8B4: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800AE8B8: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AE8BC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800AE8C0: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AE8C4: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800AE8C8: nop

    // 0x800AE8CC: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800AE8D0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AE8D4: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800AE8D8: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800AE8DC: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AE8E0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800AE8E4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AE8E8: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AE8EC: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800AE8F0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800AE8F4: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800AE8F8: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800AE8FC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800AE900: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800AE904: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800AE908: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800AE90C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800AE910: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800AE914: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800AE918: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AE91C: add.s       $f20, $f8, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AE920: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800AE924: div.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x800AE928: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AE92C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800AE930: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x800AE934: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x800AE938: div.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x800AE93C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AE940: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800AE944: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AE948: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x800AE94C: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x800AE950: div.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x800AE954: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800AE958: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x800AE95C: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800AE960: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
    // 0x800AE964: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800AE968: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x800AE96C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800AE970: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800AE974: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AE978: swc1        $f10, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f10.u32l;
    // 0x800AE97C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AE980: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800AE984: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x800AE988: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AE98C: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800AE990: swc1        $f10, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f10.u32l;
    // 0x800AE994: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AE998: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800AE99C: swc1        $f4, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f4.u32l;
    // 0x800AE9A0: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AE9A4: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800AE9A8: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    // 0x800AE9AC: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800AE9B0: mul.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AE9B4: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AE9B8: swc1        $f4, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f4.u32l;
    // 0x800AE9BC: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800AE9C0: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x800AE9C4: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AE9C8: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800AE9CC: swc1        $f10, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f10.u32l;
    // 0x800AE9D0: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800AE9D4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AE9D8: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800AE9DC: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800AE9E0: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AE9E4: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800AE9E8: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800AE9EC: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AE9F0: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AE9F4: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800AE9F8: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x800AE9FC: swc1        $f4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f4.u32l;
    // 0x800AEA00: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800AEA04: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AEA08: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AEA0C: lwc1        $f8, 0x34($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800AEA10: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800AEA14: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AEA18: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AEA1C: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800AEA20: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800AEA24: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AEA28: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800AEA2C: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x800AEA30: swc1        $f8, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f8.u32l;
    // 0x800AEA34: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800AEA38: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AEA3C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AEA40: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800AEA44: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AEA48: lwc1        $f10, 0x28($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AEA4C: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800AEA50: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800AEA54: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x800AEA58: swc1        $f0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f0.u32l;
    // 0x800AEA5C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800AEA60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AEA64: swc1        $f0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f0.u32l;
    // 0x800AEA68: swc1        $f8, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f8.u32l;
    // 0x800AEA6C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AEA70: swc1        $f10, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f10.u32l;
    // 0x800AEA74: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800AEA78: jr          $ra
    // 0x800AEA7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AEA7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void Mtx_Cofactor3x3F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEA80: beq         $a1, $zero, L_800AEAA0
    if (ctx->r5 == 0) {
        // 0x800AEA84: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800AEAA0;
    }
    // 0x800AEA84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AEA88: beq         $a1, $v0, L_800AEB2C
    if (ctx->r5 == ctx->r2) {
        // 0x800AEA8C: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_800AEB2C;
    }
    // 0x800AEA8C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800AEA90: beq         $a1, $v1, L_800AEBC4
    if (ctx->r5 == ctx->r3) {
        // 0x800AEA94: nop
    
            goto L_800AEBC4;
    }
    // 0x800AEA94: nop

    // 0x800AEA98: jr          $ra
    // 0x800AEA9C: nop

    return;
    // 0x800AEA9C: nop

L_800AEAA0:
    // 0x800AEAA0: beq         $a2, $zero, L_800AEAC0
    if (ctx->r6 == 0) {
        // 0x800AEAA4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800AEAC0;
    }
    // 0x800AEAA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AEAA8: beq         $a2, $v0, L_800AEAE4
    if (ctx->r6 == ctx->r2) {
        // 0x800AEAAC: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_800AEAE4;
    }
    // 0x800AEAAC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800AEAB0: beql        $a2, $v1, L_800AEB0C
    if (ctx->r6 == ctx->r3) {
        // 0x800AEAB4: lwc1        $f4, 0xC($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
            goto L_800AEB0C;
    }
    goto skip_0;
    // 0x800AEAB4: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    skip_0:
    // 0x800AEAB8: b           L_800AEB2C
    // 0x800AEABC: nop

        goto L_800AEB2C;
    // 0x800AEABC: nop

L_800AEAC0:
    // 0x800AEAC0: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AEAC4: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AEAC8: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AEACC: lwc1        $f16, 0x1C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800AEAD0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AEAD4: nop

    // 0x800AEAD8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AEADC: jr          $ra
    // 0x800AEAE0: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
    return;
    // 0x800AEAE0: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
L_800AEAE4:
    // 0x800AEAE4: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AEAE8: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AEAEC: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800AEAF0: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AEAF4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AEAF8: nop

    // 0x800AEAFC: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800AEB00: jr          $ra
    // 0x800AEB04: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    return;
    // 0x800AEB04: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AEB08: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
L_800AEB0C:
    // 0x800AEB0C: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800AEB10: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AEB14: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AEB18: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AEB1C: nop

    // 0x800AEB20: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AEB24: jr          $ra
    // 0x800AEB28: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    return;
    // 0x800AEB28: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
L_800AEB2C:
    // 0x800AEB2C: beq         $a2, $zero, L_800AEB4C
    if (ctx->r6 == 0) {
        // 0x800AEB30: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_800AEB4C;
    }
    // 0x800AEB30: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800AEB34: beql        $a2, $v0, L_800AEB78
    if (ctx->r6 == ctx->r2) {
        // 0x800AEB38: lwc1        $f6, 0x8($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
            goto L_800AEB78;
    }
    goto skip_1;
    // 0x800AEB38: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x800AEB3C: beql        $a2, $v1, L_800AEBA0
    if (ctx->r6 == ctx->r3) {
        // 0x800AEB40: lwc1        $f8, 0x0($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800AEBA0;
    }
    goto skip_2;
    // 0x800AEB40: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x800AEB44: b           L_800AEBC4
    // 0x800AEB48: nop

        goto L_800AEBC4;
    // 0x800AEB48: nop

L_800AEB4C:
    // 0x800AEB4C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800AEB50: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AEB54: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800AEB58: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800AEB5C: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800AEB60: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AEB64: nop

    // 0x800AEB68: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AEB6C: jr          $ra
    // 0x800AEB70: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    return;
    // 0x800AEB70: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800AEB74: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
L_800AEB78:
    // 0x800AEB78: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AEB7C: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AEB80: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800AEB84: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AEB88: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AEB8C: nop

    // 0x800AEB90: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AEB94: jr          $ra
    // 0x800AEB98: add.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f6.fl;
    return;
    // 0x800AEB98: add.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800AEB9C: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
L_800AEBA0:
    // 0x800AEBA0: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800AEBA4: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800AEBA8: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x800AEBAC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AEBB0: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AEBB4: nop

    // 0x800AEBB8: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AEBBC: jr          $ra
    // 0x800AEBC0: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    return;
    // 0x800AEBC0: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
L_800AEBC4:
    // 0x800AEBC4: beql        $a2, $zero, L_800AEBE8
    if (ctx->r6 == 0) {
        // 0x800AEBC8: lwc1        $f16, 0x4($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
            goto L_800AEBE8;
    }
    goto skip_3;
    // 0x800AEBC8: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    skip_3:
    // 0x800AEBCC: beql        $a2, $v0, L_800AEC0C
    if (ctx->r6 == ctx->r2) {
        // 0x800AEBD0: lwc1        $f16, 0x8($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
            goto L_800AEC0C;
    }
    goto skip_4;
    // 0x800AEBD0: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    skip_4:
    // 0x800AEBD4: beql        $a2, $v1, L_800AEC30
    if (ctx->r6 == ctx->r3) {
        // 0x800AEBD8: lwc1        $f16, 0x0($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800AEC30;
    }
    goto skip_5;
    // 0x800AEBD8: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    skip_5:
    // 0x800AEBDC: jr          $ra
    // 0x800AEBE0: nop

    return;
    // 0x800AEBE0: nop

    // 0x800AEBE4: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
L_800AEBE8:
    // 0x800AEBE8: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AEBEC: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800AEBF0: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AEBF4: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AEBF8: nop

    // 0x800AEBFC: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AEC00: jr          $ra
    // 0x800AEC04: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    return;
    // 0x800AEC04: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800AEC08: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
L_800AEC0C:
    // 0x800AEC0C: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800AEC10: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AEC14: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AEC18: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AEC1C: nop

    // 0x800AEC20: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AEC24: jr          $ra
    // 0x800AEC28: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    return;
    // 0x800AEC28: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800AEC2C: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
L_800AEC30:
    // 0x800AEC30: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AEC34: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800AEC38: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800AEC3C: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AEC40: nop

    // 0x800AEC44: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AEC48: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800AEC4C: jr          $ra
    // 0x800AEC50: nop

    return;
    // 0x800AEC50: nop

;}

RECOMP_FUNC void Mtx_Determinant3x3F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEC54: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AEC58: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AEC5C: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AEC60: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AEC64: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800AEC68: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800AEC6C: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800AEC70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AEC74: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800AEC78: mul.s       $f2, $f4, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800AEC7C: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AEC80: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800AEC84: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x800AEC88: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800AEC8C: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AEC90: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800AEC94: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x800AEC98: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800AEC9C: nop

    // 0x800AECA0: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AECA4: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800AECA8: swc1        $f8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f8.u32l;
    // 0x800AECAC: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800AECB0: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800AECB4: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AECB8: nop

    // 0x800AECBC: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800AECC0: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800AECC4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800AECC8: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800AECCC: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800AECD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AECD4: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AECD8: nop

    // 0x800AECDC: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800AECE0: nop

    // 0x800AECE4: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800AECE8: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800AECEC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AECF0: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800AECF4: jr          $ra
    // 0x800AECF8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800AECF8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}

RECOMP_FUNC void Mtx_Invert3x3F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AECFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AED00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AED04: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800AED08: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800AED0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AED10: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800AED14: jal         0x800AEC54
    // 0x800AED18: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    Mtx_Determinant3x3F(rdram, ctx);
        goto after_0;
    // 0x800AED18: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x800AED1C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800AED20: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800AED24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED28: ldc1        $f4, 0x12B8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X12B8);
    // 0x800AED2C: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x800AED30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AED34: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x800AED38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AED3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AED40: bc1tl       L_800AEE38
    if (c1cs) {
        // 0x800AED44: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800AEE38;
    }
    goto skip_0;
    // 0x800AED44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800AED48: jal         0x800AEA80
    // 0x800AED4C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    Mtx_Cofactor3x3F(rdram, ctx);
        goto after_1;
    // 0x800AED4C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x800AED50: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AED54: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800AED58: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800AED5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AED60: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800AED64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AED68: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x800AED6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AED70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AED74: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x800AED78: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AED7C: jal         0x800AEA80
    // 0x800AED80: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    Mtx_Cofactor3x3F(rdram, ctx);
        goto after_2;
    // 0x800AED80: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    after_2:
    // 0x800AED84: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AED88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AED8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AED90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AED94: jal         0x800AEA80
    // 0x800AED98: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    Mtx_Cofactor3x3F(rdram, ctx);
        goto after_3;
    // 0x800AED98: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    after_3:
    // 0x800AED9C: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEDA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AEDA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AEDAC: jal         0x800AEA80
    // 0x800AEDB0: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    Mtx_Cofactor3x3F(rdram, ctx);
        goto after_4;
    // 0x800AEDB0: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    after_4:
    // 0x800AEDB4: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEDB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEDBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AEDC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AEDC4: jal         0x800AEA80
    // 0x800AEDC8: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    Mtx_Cofactor3x3F(rdram, ctx);
        goto after_5;
    // 0x800AEDC8: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    after_5:
    // 0x800AEDCC: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEDD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEDD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AEDD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AEDDC: jal         0x800AEA80
    // 0x800AEDE0: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
    Mtx_Cofactor3x3F(rdram, ctx);
        goto after_6;
    // 0x800AEDE0: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
    after_6:
    // 0x800AEDE4: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEDE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEDEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AEDF0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800AEDF4: jal         0x800AEA80
    // 0x800AEDF8: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    Mtx_Cofactor3x3F(rdram, ctx);
        goto after_7;
    // 0x800AEDF8: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    after_7:
    // 0x800AEDFC: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEE00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEE04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AEE08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800AEE0C: jal         0x800AEA80
    // 0x800AEE10: swc1        $f16, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f16.u32l;
    Mtx_Cofactor3x3F(rdram, ctx);
        goto after_8;
    // 0x800AEE10: swc1        $f16, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f16.u32l;
    after_8:
    // 0x800AEE14: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEE18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEE1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AEE20: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800AEE24: jal         0x800AEA80
    // 0x800AEE28: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    Mtx_Cofactor3x3F(rdram, ctx);
        goto after_9;
    // 0x800AEE28: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    after_9:
    // 0x800AEE2C: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEE30: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x800AEE34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800AEE38:
    // 0x800AEE38: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800AEE3C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEE40: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800AEE44: jr          $ra
    // 0x800AEE48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AEE48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void Mtx_MulAffineF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEE4C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AEE50: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AEE54: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AEE58: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AEE5C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AEE60: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AEE64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AEE68: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AEE6C: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AEE70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AEE74: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AEE78: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AEE7C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AEE80: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800AEE84: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AEE88: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AEE8C: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AEE90: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AEE94: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AEE98: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AEE9C: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AEEA0: lwc1        $f4, 0x18($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AEEA4: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AEEA8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AEEAC: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AEEB0: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800AEEB4: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AEEB8: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AEEBC: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AEEC0: lwc1        $f18, 0x10($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AEEC4: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AEEC8: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AEECC: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AEED0: lwc1        $f18, 0x28($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AEED4: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AEED8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AEEDC: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AEEE0: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800AEEE4: lwc1        $f6, 0x30($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AEEE8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AEEEC: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AEEF0: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AEEF4: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AEEF8: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AEEFC: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AEF00: lwc1        $f8, 0x38($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AEF04: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AEF08: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AEF0C: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800AEF10: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AEF14: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AEF18: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x800AEF1C: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AEF20: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AEF24: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AEF28: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AEF2C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AEF30: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AEF34: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AEF38: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AEF3C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800AEF40: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800AEF44: add.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AEF48: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x800AEF4C: lwc1        $f10, 0x10($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AEF50: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AEF54: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AEF58: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AEF5C: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AEF60: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AEF64: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800AEF68: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AEF6C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800AEF70: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AEF74: add.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AEF78: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800AEF7C: lwc1        $f10, 0x20($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AEF80: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AEF84: lwc1        $f4, 0x24($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AEF88: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AEF8C: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AEF90: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AEF94: mul.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AEF98: lwc1        $f6, 0x28($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AEF9C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AEFA0: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AEFA4: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800AEFA8: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x800AEFAC: lwc1        $f10, 0x30($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AEFB0: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AEFB4: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AEFB8: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AEFBC: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800AEFC0: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AEFC4: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AEFC8: lwc1        $f16, 0x38($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AEFCC: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AEFD0: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AEFD4: lwc1        $f8, 0x34($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800AEFD8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AEFDC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AEFE0: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
    // 0x800AEFE4: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AEFE8: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AEFEC: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AEFF0: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AEFF4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AEFF8: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AEFFC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AF000: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF004: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF008: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AF00C: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800AF010: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800AF014: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF018: lwc1        $f18, 0x10($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF01C: lwc1        $f16, 0x18($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF020: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF024: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800AF028: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF02C: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800AF030: lwc1        $f16, 0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF034: mul.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF038: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AF03C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF040: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x800AF044: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF048: lwc1        $f18, 0x20($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF04C: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF050: lwc1        $f8, 0x24($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF054: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AF058: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF05C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800AF060: lwc1        $f10, 0x28($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF064: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800AF068: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800AF06C: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AF070: swc1        $f16, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f16.u32l;
    // 0x800AF074: lwc1        $f18, 0x30($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AF078: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF07C: lwc1        $f8, 0x34($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AF080: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF084: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AF088: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF08C: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800AF090: lwc1        $f4, 0x38($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AF094: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AF098: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AF09C: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF0A0: lwc1        $f16, 0x38($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800AF0A4: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800AF0A8: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x800AF0AC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AF0B0: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x800AF0B4: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x800AF0B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF0BC: jr          $ra
    // 0x800AF0C0: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800AF0C0: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
;}

RECOMP_FUNC void Mtx_MulF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF0C4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF0C8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF0CC: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF0D0: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF0D4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF0D8: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF0DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AF0E0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF0E4: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF0E8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF0EC: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF0F0: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AF0F4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800AF0F8: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF0FC: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF100: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF104: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF108: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF10C: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF110: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AF114: lwc1        $f4, 0x18($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF118: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AF11C: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF120: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AF124: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800AF128: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF12C: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF130: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF134: lwc1        $f18, 0x10($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF138: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AF13C: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF140: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF144: lwc1        $f18, 0x28($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF148: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AF14C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AF150: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AF154: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800AF158: lwc1        $f6, 0x30($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AF15C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF160: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800AF164: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF168: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AF16C: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AF170: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AF174: lwc1        $f18, 0x1C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800AF178: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AF17C: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF180: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AF184: lwc1        $f6, 0x38($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AF188: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AF18C: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800AF190: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800AF194: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AF198: mul.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF19C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AF1A0: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800AF1A4: swc1        $f18, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f18.u32l;
    // 0x800AF1A8: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF1AC: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF1B0: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF1B4: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF1B8: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AF1BC: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF1C0: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AF1C4: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF1C8: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AF1CC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF1D0: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800AF1D4: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800AF1D8: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF1DC: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF1E0: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF1E4: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF1E8: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AF1EC: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF1F0: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AF1F4: lwc1        $f16, 0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF1F8: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AF1FC: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF200: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800AF204: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800AF208: lwc1        $f4, 0x20($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF20C: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF210: lwc1        $f6, 0x24($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF214: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF218: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800AF21C: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF220: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF224: lwc1        $f18, 0x28($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF228: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AF22C: add.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800AF230: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AF234: swc1        $f16, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f16.u32l;
    // 0x800AF238: lwc1        $f4, 0x30($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AF23C: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF240: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800AF244: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF248: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AF24C: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AF250: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AF254: lwc1        $f18, 0x1C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800AF258: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AF25C: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF260: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AF264: lwc1        $f4, 0x38($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AF268: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AF26C: lwc1        $f4, 0x34($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800AF270: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AF274: lwc1        $f6, 0x2C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AF278: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF27C: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800AF280: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800AF284: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x800AF288: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF28C: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF290: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF294: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF298: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800AF29C: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF2A0: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AF2A4: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF2A8: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AF2AC: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF2B0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AF2B4: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x800AF2B8: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF2BC: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF2C0: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF2C4: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF2C8: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF2CC: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF2D0: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AF2D4: lwc1        $f6, 0x18($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF2D8: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AF2DC: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF2E0: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AF2E4: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x800AF2E8: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF2EC: lwc1        $f16, 0x20($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF2F0: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF2F4: lwc1        $f4, 0x24($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF2F8: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AF2FC: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF300: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AF304: lwc1        $f18, 0x28($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF308: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AF30C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800AF310: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AF314: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x800AF318: lwc1        $f16, 0x30($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AF31C: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF320: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800AF324: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF328: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF32C: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AF330: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AF334: lwc1        $f18, 0x1C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800AF338: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF33C: lwc1        $f10, 0x28($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF340: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AF344: lwc1        $f16, 0x38($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AF348: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF34C: lwc1        $f16, 0x38($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800AF350: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AF354: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AF358: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AF35C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AF360: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF364: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
    // 0x800AF368: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800AF36C: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800AF370: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF374: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x800AF378: lwc1        $f16, 0x1C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x800AF37C: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800AF380: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF384: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AF388: swc1        $f18, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f18.u32l;
    // 0x800AF38C: lwc1        $f6, 0x2C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x800AF390: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AF394: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x800AF398: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF39C: jr          $ra
    // 0x800AF3A0: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800AF3A0: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
;}

RECOMP_FUNC void Mtx_Mul3x3F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF3A4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF3A8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF3AC: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF3B0: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF3B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF3B8: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF3BC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF3C0: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF3C4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF3C8: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF3CC: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AF3D0: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800AF3D4: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF3D8: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF3DC: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF3E0: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF3E4: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF3E8: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF3EC: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AF3F0: lwc1        $f4, 0x18($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF3F4: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AF3F8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF3FC: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AF400: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800AF404: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF408: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF40C: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF410: lwc1        $f18, 0x10($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF414: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AF418: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF41C: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF420: lwc1        $f18, 0x28($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF424: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AF428: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AF42C: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AF430: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800AF434: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF438: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF43C: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF440: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF444: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AF448: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF44C: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AF450: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF454: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AF458: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AF45C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF460: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800AF464: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF468: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF46C: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF470: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF474: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF478: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF47C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF480: lwc1        $f10, 0x18($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF484: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF488: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF48C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AF490: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x800AF494: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF498: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF49C: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF4A0: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF4A4: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF4A8: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF4AC: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AF4B0: lwc1        $f4, 0x28($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF4B4: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AF4B8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF4BC: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AF4C0: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x800AF4C4: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF4C8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF4CC: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF4D0: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF4D4: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AF4D8: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF4DC: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF4E0: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF4E4: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AF4E8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AF4EC: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AF4F0: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800AF4F4: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF4F8: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF4FC: lwc1        $f8, 0x18($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF500: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF504: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AF508: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF50C: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AF510: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF514: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AF518: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AF51C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF520: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800AF524: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF528: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF52C: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF530: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF534: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF538: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF53C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF540: lwc1        $f10, 0x28($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF544: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF548: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF54C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AF550: jr          $ra
    // 0x800AF554: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800AF554: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
;}

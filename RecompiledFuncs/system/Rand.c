#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Rand_Next(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060814: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80060818: lw          $t6, -0x590($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X590);
    // 0x8006081C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80060820: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80060824: sw          $t7, -0x590($at)
    MEM_W(-0X590, ctx->r1) = ctx->r15;
    // 0x80060828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006082C: slti        $at, $a1, 0x20
    ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x80060830: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80060834: beq         $at, $zero, L_8006087C
    if (ctx->r1 == 0) {
        // 0x80060838: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8006087C;
    }
    // 0x80060838: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8006083C:
    // 0x8006083C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80060840: lw          $t8, -0x590($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X590);
    // 0x80060844: lui         $at, 0x8050
    ctx->r1 = S32(0X8050 << 16);
    // 0x80060848: srl         $t0, $t8, 29
    ctx->r8 = S32(U32(ctx->r24) >> 29);
    // 0x8006084C: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x80060850: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80060854: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80060858: xor         $t3, $t2, $at
    ctx->r11 = ctx->r10 ^ ctx->r1;
    // 0x8006085C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80060860: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80060864: sllv        $t5, $t4, $a1
    ctx->r13 = S32(ctx->r12 << (ctx->r5 & 31));
    // 0x80060868: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006086C: sw          $t3, -0x590($at)
    MEM_W(-0X590, ctx->r1) = ctx->r11;
    // 0x80060870: slti        $at, $a1, 0x20
    ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x80060874: bne         $at, $zero, L_8006083C
    if (ctx->r1 != 0) {
        // 0x80060878: or          $a0, $a0, $t5
        ctx->r4 = ctx->r4 | ctx->r13;
            goto L_8006083C;
    }
    // 0x80060878: or          $a0, $a0, $t5
    ctx->r4 = ctx->r4 | ctx->r13;
L_8006087C:
    // 0x8006087C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80060880: sw          $a0, -0x590($at)
    MEM_W(-0X590, ctx->r1) = ctx->r4;
    // 0x80060884: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80060888: jr          $ra
    // 0x8006088C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006088C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Rand_SetSeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060890: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80060894: jr          $ra
    // 0x80060898: sw          $a0, -0x590($at)
    MEM_W(-0X590, ctx->r1) = ctx->r4;
    return;
    // 0x80060898: sw          $a0, -0x590($at)
    MEM_W(-0X590, ctx->r1) = ctx->r4;
;}

RECOMP_FUNC void Rand_Hash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006089C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800608A0: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800608A4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800608A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800608AC: beq         $at, $zero, L_800608E8
    if (ctx->r1 == 0) {
        // 0x800608B0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800608E8;
    }
    // 0x800608B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800608B4:
    // 0x800608B4: srl         $t7, $a0, 29
    ctx->r15 = S32(U32(ctx->r4) >> 29);
    // 0x800608B8: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x800608BC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800608C0: or          $a0, $t6, $t8
    ctx->r4 = ctx->r14 | ctx->r24;
    // 0x800608C4: lui         $at, 0x8050
    ctx->r1 = S32(0X8050 << 16);
    // 0x800608C8: xor         $t9, $a0, $at
    ctx->r25 = ctx->r4 ^ ctx->r1;
    // 0x800608CC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800608D0: andi        $t0, $a0, 0x1
    ctx->r8 = ctx->r4 & 0X1;
    // 0x800608D4: sllv        $t1, $t0, $a2
    ctx->r9 = S32(ctx->r8 << (ctx->r6 & 31));
    // 0x800608D8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800608DC: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800608E0: bne         $at, $zero, L_800608B4
    if (ctx->r1 != 0) {
        // 0x800608E4: or          $a1, $a1, $t1
        ctx->r5 = ctx->r5 | ctx->r9;
            goto L_800608B4;
    }
    // 0x800608E4: or          $a1, $a1, $t1
    ctx->r5 = ctx->r5 | ctx->r9;
L_800608E8:
    // 0x800608E8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800608EC: jr          $ra
    // 0x800608F0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800608F0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Rand_Float(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B10C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B10C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B10C8: jal         0x800BB4D0
    // 0x800B10CC: nop

    guRandom(rdram, ctx);
        goto after_0;
    // 0x800B10CC: nop

    after_0:
    // 0x800B10D0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800B10D4: lui         $at, 0x4E80
    ctx->r1 = S32(0X4E80 << 16);
    // 0x800B10D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B10DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B10E0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B10E4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B10E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B10EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B10F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B10F4: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B10F8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800B10FC: sub.d       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = ctx->f16.d - ctx->f18.d;
    // 0x800B1100: add.d       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f2.d + ctx->f2.d;
    // 0x800B1104: jr          $ra
    // 0x800B1108: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800B1108: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
;}

RECOMP_FUNC void func_800B110C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B110C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B1110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1114: jal         0x800B10C0
    // 0x800B1118: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    Rand_Float(rdram, ctx);
        goto after_0;
    // 0x800B1118: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800B111C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B1120: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800B1124: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1128: ldc1        $f6, 0x12E0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X12E0);
    // 0x800B112C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800B1130: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800B1134: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800B1138: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B113C: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x800B1140: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B1144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1148: add.d       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = ctx->f8.d + ctx->f10.d;
    // 0x800B114C: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x800B1150: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x800B1154: cvt.d.s     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.d = CVT_D_S(ctx->f2.fl);
    // 0x800B1158: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x800B115C: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x800B1160: nop

    // 0x800B1164: bc1fl       L_800B117C
    if (!c1cs) {
        // 0x800B1168: mtc1        $at, $f19
        ctx->f_odd[(19 - 1) * 2] = ctx->r1;
            goto L_800B117C;
    }
    goto skip_0;
    // 0x800B1168: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800B116C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B1170: b           L_800B11BC
    // 0x800B1174: nop

        goto L_800B11BC;
    // 0x800B1174: nop

    // 0x800B1178: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
L_800B117C:
    // 0x800B117C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B1180: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B1184: c.lt.d      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.d < ctx->f18.d;
    // 0x800B1188: nop

    // 0x800B118C: bc1fl       L_800B11A4
    if (!c1cs) {
        // 0x800B1190: cvt.d.s     $f4, $f14
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
            goto L_800B11A4;
    }
    goto skip_1;
    // 0x800B1190: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    skip_1:
    // 0x800B1194: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B1198: b           L_800B11BC
    // 0x800B119C: nop

        goto L_800B11BC;
    // 0x800B119C: nop

    // 0x800B11A0: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
L_800B11A4:
    // 0x800B11A4: sub.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d - ctx->f18.d;
    // 0x800B11A8: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x800B11AC: cvt.d.s     $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.d = CVT_D_S(ctx->f14.fl);
    // 0x800B11B0: add.d       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f2.d + ctx->f2.d;
    // 0x800B11B4: sub.d       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f16.d - ctx->f8.d;
    // 0x800B11B8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800B11BC:
    // 0x800B11BC: jr          $ra
    // 0x800B11C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B11C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void func_800B11C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B11C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B11C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B11CC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800B11D0: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B11D4: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x800B11D8: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x800B11DC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B11E0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B11E4: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x800B11E8: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x800B11EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B11F0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x800B11F4: cvt.d.s     $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f20.d = CVT_D_S(ctx->f12.fl);
    // 0x800B11F8: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800B11FC: nop

    // 0x800B1200: bc1fl       L_800B1228
    if (!c1cs) {
        // 0x800B1204: c.lt.d      $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
            goto L_800B1228;
    }
    goto skip_0;
    // 0x800B1204: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    skip_0:
    // 0x800B1208: sub.d       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f20.d - ctx->f2.d;
L_800B120C:
    // 0x800B120C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x800B1210: cvt.d.s     $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f20.d = CVT_D_S(ctx->f12.fl);
    // 0x800B1214: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800B1218: nop

    // 0x800B121C: bc1tl       L_800B120C
    if (c1cs) {
        // 0x800B1220: sub.d       $f10, $f20, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f20.d - ctx->f2.d;
            goto L_800B120C;
    }
    goto skip_1;
    // 0x800B1220: sub.d       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f20.d - ctx->f2.d;
    skip_1:
    // 0x800B1224: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
L_800B1228:
    // 0x800B1228: nop

    // 0x800B122C: bc1fl       L_800B1254
    if (!c1cs) {
        // 0x800B1230: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_800B1254;
    }
    goto skip_2;
    // 0x800B1230: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    skip_2:
    // 0x800B1234: add.d       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f20.d + ctx->f2.d;
L_800B1238:
    // 0x800B1238: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x800B123C: cvt.d.s     $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f20.d = CVT_D_S(ctx->f12.fl);
    // 0x800B1240: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800B1244: nop

    // 0x800B1248: bc1tl       L_800B1238
    if (c1cs) {
        // 0x800B124C: add.d       $f4, $f20, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f20.d + ctx->f2.d;
            goto L_800B1238;
    }
    goto skip_3;
    // 0x800B124C: add.d       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f20.d + ctx->f2.d;
    skip_3:
    // 0x800B1250: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
L_800B1254:
    // 0x800B1254: jal         0x800B110C
    // 0x800B1258: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_800B110C(rdram, ctx);
        goto after_0;
    // 0x800B1258: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x800B125C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x800B1260: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x800B1264: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B1268: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800B126C: sub.d       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f20.d - ctx->f2.d;
    // 0x800B1270: jal         0x800B110C
    // 0x800B1274: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    func_800B110C(rdram, ctx);
        goto after_1;
    // 0x800B1274: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_1:
    // 0x800B1278: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B127C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B1280: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800B1284: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B1288: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800B128C: sub.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f20.d - ctx->f4.d;
    // 0x800B1290: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x800B1294: jal         0x800B110C
    // 0x800B1298: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    func_800B110C(rdram, ctx);
        goto after_2;
    // 0x800B1298: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_2:
    // 0x800B129C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B12A0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B12A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B12A8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800B12AC: sub.d       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f20.d - ctx->f8.d;
    // 0x800B12B0: jal         0x800B110C
    // 0x800B12B4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    func_800B110C(rdram, ctx);
        goto after_3;
    // 0x800B12B4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_3:
    // 0x800B12B8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B12BC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B12C0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800B12C4: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800B12C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B12CC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800B12D0: cvt.d.s     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f20.d = CVT_D_S(ctx->f18.fl);
    // 0x800B12D4: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B12D8: c.le.d      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.d <= ctx->f4.d;
    // 0x800B12DC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B12E0: bc1fl       L_800B1328
    if (!c1cs) {
        // 0x800B12E4: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_800B1328;
    }
    goto skip_4;
    // 0x800B12E4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_4:
    // 0x800B12E8: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B12EC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B12F0: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x800B12F4: add.d       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f2.d + ctx->f2.d;
    // 0x800B12F8: mul.d       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f20.d, ctx->f8.d);
    // 0x800B12FC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x800B1300: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800B1304: nop

    // 0x800B1308: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800B130C: nop

    // 0x800B1310: mul.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800B1314: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x800B1318: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x800B131C: b           L_800B138C
    // 0x800B1320: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
        goto L_800B138C;
    // 0x800B1320: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    // 0x800B1324: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_800B1328:
    // 0x800B1328: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B132C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800B1330: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B1334: sub.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = ctx->f4.d - ctx->f6.d;
    // 0x800B1338: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B133C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B1340: add.d       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f2.d + ctx->f2.d;
    // 0x800B1344: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x800B1348: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B134C: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x800B1350: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x800B1354: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B1358: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B135C: mul.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800B1360: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x800B1364: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800B1368: add.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800B136C: mul.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800B1370: nop

    // 0x800B1374: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800B1378: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x800B137C: add.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x800B1380: add.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800B1384: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x800B1388: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
L_800B138C:
    // 0x800B138C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B1390: swc1        $f4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
    // 0x800B1394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1398: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800B139C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800B13A0: jr          $ra
    // 0x800B13A4: nop

    return;
    // 0x800B13A4: nop

;}

RECOMP_FUNC void func_800B13A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B13A8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B13AC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B13B0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800B13B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B13B8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B13BC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B13C0: c.lt.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d < ctx->f6.d;
    // 0x800B13C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B13C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B13CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B13D0: bc1f        L_800B13E8
    if (!c1cs) {
        // 0x800B13D4: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800B13E8;
    }
    // 0x800B13D4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800B13D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B13DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B13E0: nop

    // 0x800B13E4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
L_800B13E8:
    // 0x800B13E8: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800B13EC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800B13F0: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x800B13F4: nop

    // 0x800B13F8: bc1f        L_800B140C
    if (!c1cs) {
        // 0x800B13FC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800B140C;
    }
    // 0x800B13FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B1400: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B1404: nop

    // 0x800B1408: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
L_800B140C:
    // 0x800B140C: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B1410: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B1414: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x800B1418: nop

    // 0x800B141C: bc1f        L_800B1430
    if (!c1cs) {
        // 0x800B1420: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800B1430;
    }
    // 0x800B1420: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B1424: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B1428: nop

    // 0x800B142C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
L_800B1430:
    // 0x800B1430: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B1434: mtc1        $zero, $f15
    ctx->f_odd[(15 - 1) * 2] = 0;
    // 0x800B1438: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800B143C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x800B1440: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B1444: c.lt.d      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.d < ctx->f14.d;
    // 0x800B1448: nop

    // 0x800B144C: bc1fl       L_800B1464
    if (!c1cs) {
        // 0x800B1450: c.lt.d      $f18, $f14
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.d < ctx->f14.d;
            goto L_800B1464;
    }
    goto skip_0;
    // 0x800B1450: c.lt.d      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.d < ctx->f14.d;
    skip_0:
    // 0x800B1454: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x800B1458: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B145C: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x800B1460: c.lt.d      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.d < ctx->f14.d;
L_800B1464:
    // 0x800B1464: nop

    // 0x800B1468: bc1fl       L_800B1478
    if (!c1cs) {
        // 0x800B146C: lwc1        $f10, 0x8($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
            goto L_800B1478;
    }
    goto skip_1;
    // 0x800B146C: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x800B1470: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    // 0x800B1474: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
L_800B1478:
    // 0x800B1478: swc1        $f10, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f10.u32l;
    // 0x800B147C: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800B1480: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B1484: c.lt.d      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.d < ctx->f14.d;
    // 0x800B1488: nop

    // 0x800B148C: bc1fl       L_800B14A4
    if (!c1cs) {
        // 0x800B1490: lwc1        $f18, 0x0($a0)
        ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800B14A4;
    }
    goto skip_2;
    // 0x800B1490: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x800B1494: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x800B1498: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B149C: swc1        $f8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f8.u32l;
    // 0x800B14A0: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
L_800B14A4:
    // 0x800B14A4: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800B14A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B14AC: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x800B14B0: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x800B14B4: bc1fl       L_800B14C8
    if (!c1cs) {
        // 0x800B14B8: lwc1        $f4, 0x4($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
            goto L_800B14C8;
    }
    goto skip_3;
    // 0x800B14B8: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    skip_3:
    // 0x800B14BC: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x800B14C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800B14C4: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
L_800B14C8:
    // 0x800B14C8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B14CC: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800B14D0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800B14D4: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800B14D8: bc1fl       L_800B14EC
    if (!c1cs) {
        // 0x800B14DC: c.lt.s      $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
            goto L_800B14EC;
    }
    goto skip_4;
    // 0x800B14DC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    skip_4:
    // 0x800B14E0: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    // 0x800B14E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B14E8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
L_800B14EC:
    // 0x800B14EC: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800B14F0: bc1fl       L_800B1504
    if (!c1cs) {
        // 0x800B14F4: c.lt.s      $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
            goto L_800B1504;
    }
    goto skip_5;
    // 0x800B14F4: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    skip_5:
    // 0x800B14F8: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x800B14FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B1500: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
L_800B1504:
    // 0x800B1504: nop

    // 0x800B1508: bc1fl       L_800B1518
    if (!c1cs) {
        // 0x800B150C: c.lt.s      $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
            goto L_800B1518;
    }
    goto skip_6;
    // 0x800B150C: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    skip_6:
    // 0x800B1510: mov.s       $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = ctx->f18.fl;
    // 0x800B1514: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
L_800B1518:
    // 0x800B1518: nop

    // 0x800B151C: bc1fl       L_800B152C
    if (!c1cs) {
        // 0x800B1520: c.lt.s      $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
            goto L_800B152C;
    }
    goto skip_7;
    // 0x800B1520: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    skip_7:
    // 0x800B1524: mov.s       $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = ctx->f10.fl;
    // 0x800B1528: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
L_800B152C:
    // 0x800B152C: nop

    // 0x800B1530: bc1fl       L_800B1540
    if (!c1cs) {
        // 0x800B1534: add.s       $f18, $f0, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_800B1540;
    }
    goto skip_8;
    // 0x800B1534: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    skip_8:
    // 0x800B1538: mov.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
    // 0x800B153C: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
L_800B1540:
    // 0x800B1540: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B1544: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B1548: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B154C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x800B1550: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1554: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800B1558: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800B155C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x800B1560: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x800B1564: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x800B1568: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800B156C: ldc1        $f4, 0x12E8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X12E8);
    // 0x800B1570: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B1574: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B1578: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x800B157C: sdc1        $f10, 0x8($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X8, ctx->r29);
    // 0x800B1580: bc1fl       L_800B1598
    if (!c1cs) {
        // 0x800B1584: lwc1        $f8, 0x4($a1)
        ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
            goto L_800B1598;
    }
    goto skip_9;
    // 0x800B1584: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    skip_9:
    // 0x800B1588: swc1        $f12, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f12.u32l;
    // 0x800B158C: b           L_800B16C8
    // 0x800B1590: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
        goto L_800B16C8;
    // 0x800B1590: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    // 0x800B1594: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
L_800B1598:
    // 0x800B1598: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800B159C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B15A0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B15A4: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800B15A8: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x800B15AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B15B0: bc1fl       L_800B15C8
    if (!c1cs) {
        // 0x800B15B4: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_800B15C8;
    }
    goto skip_10;
    // 0x800B15B4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_10:
    // 0x800B15B8: div.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800B15BC: b           L_800B15EC
    // 0x800B15C0: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
        goto L_800B15EC;
    // 0x800B15C0: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x800B15C4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_800B15C8:
    // 0x800B15C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B15CC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800B15D0: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800B15D4: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x800B15D8: ldc1        $f10, 0x8($sp)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r29, 0X8);
    // 0x800B15DC: add.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d + ctx->f8.d;
    // 0x800B15E0: div.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f6.d);
    // 0x800B15E4: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800B15E8: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
L_800B15EC:
    // 0x800B15EC: beq         $v0, $zero, L_800B1610
    if (ctx->r2 == 0) {
        // 0x800B15F0: lwc1        $f0, 0x4($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
            goto L_800B1610;
    }
    // 0x800B15F0: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800B15F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B15F8: beq         $v0, $at, L_800B1628
    if (ctx->r2 == ctx->r1) {
        // 0x800B15FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B1628;
    }
    // 0x800B15FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1600: beql        $v0, $at, L_800B165C
    if (ctx->r2 == ctx->r1) {
        // 0x800B1604: lwc1        $f10, 0x0($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800B165C;
    }
    goto skip_11;
    // 0x800B1604: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    skip_11:
    // 0x800B1608: b           L_800B1688
    // 0x800B160C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
        goto L_800B1688;
    // 0x800B160C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
L_800B1610:
    // 0x800B1610: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800B1614: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B1618: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800B161C: div.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B1620: b           L_800B1684
    // 0x800B1624: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
        goto L_800B1684;
    // 0x800B1624: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_800B1628:
    // 0x800B1628: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B162C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B1630: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B1634: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800B1638: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800B163C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B1640: div.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B1644: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B1648: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x800B164C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800B1650: b           L_800B1684
    // 0x800B1654: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
        goto L_800B1684;
    // 0x800B1654: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x800B1658: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
L_800B165C:
    // 0x800B165C: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800B1660: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800B1664: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800B1668: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800B166C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B1670: div.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B1674: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B1678: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x800B167C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800B1680: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_800B1684:
    // 0x800B1684: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
L_800B1688:
    // 0x800B1688: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x800B168C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800B1690: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B1694: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x800B1698: div.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f4.d);
    // 0x800B169C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800B16A0: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x800B16A4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B16A8: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x800B16AC: c.lt.d      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.d < ctx->f14.d;
    // 0x800B16B0: nop

    // 0x800B16B4: bc1fl       L_800B16CC
    if (!c1cs) {
        // 0x800B16B8: lwc1        $f10, 0xC($a1)
        ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
            goto L_800B16CC;
    }
    goto skip_12;
    // 0x800B16B8: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    skip_12:
    // 0x800B16BC: add.d       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f0.d + ctx->f16.d;
    // 0x800B16C0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800B16C4: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_800B16C8:
    // 0x800B16C8: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
L_800B16CC:
    // 0x800B16CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B16D0: jr          $ra
    // 0x800B16D4: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x800B16D4: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
;}

RECOMP_FUNC void vec4_lerp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B16D8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800B16DC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B16E0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800B16E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B16E8: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x800B16EC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B16F0: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x800B16F4: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800B16F8: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800B16FC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800B1700: nop

    // 0x800B1704: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800B1708: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800B170C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800B1710: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800B1714: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800B1718: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800B171C: nop

    // 0x800B1720: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800B1724: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B1728: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x800B172C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800B1730: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B1734: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B1738: nop

    // 0x800B173C: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800B1740: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B1744: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x800B1748: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800B174C: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800B1750: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B1754: nop

    // 0x800B1758: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800B175C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B1760: jr          $ra
    // 0x800B1764: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x800B1764: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x800B1768: nop

    // 0x800B176C: nop

;}

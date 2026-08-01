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

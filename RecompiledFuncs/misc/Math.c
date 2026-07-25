#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Math_CosineRadialGrid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C650: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007C654: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C658: addiu       $t6, $t6, -0x2F0
    ctx->r14 = ADD32(ctx->r14, -0X2F0);
    // 0x8007C65C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C660: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8007C664: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8007C668:
    // 0x8007C668: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007C66C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8007C670: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8007C674: addiu       $t9, $t8, -0x10
    ctx->r25 = ADD32(ctx->r24, -0X10);
    // 0x8007C678: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8007C67C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007C680: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007C684: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8007C688: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007C68C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
L_8007C690:
    // 0x8007C690: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007C694: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8007C698: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8007C69C: addiu       $t2, $t1, -0x10
    ctx->r10 = ADD32(ctx->r9, -0X10);
    // 0x8007C6A0: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8007C6A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007C6A8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007C6AC: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007C6B0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007C6B4: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007C6B8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007C6BC: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8007C6C0: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8007C6C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007C6C8: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8007C6CC: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007C6D0: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007C6D4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8007C6D8: sub.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d - ctx->f4.d;
    // 0x8007C6DC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8007C6E0: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8007C6E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007C6E8: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8007C6EC: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8007C6F0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8007C6F4: bc1f        L_8007C708
    if (!c1cs) {
        // 0x8007C6F8: nop
    
            goto L_8007C708;
    }
    // 0x8007C6F8: nop

    // 0x8007C6FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007C700: nop

    // 0x8007C704: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
L_8007C708:
    // 0x8007C708: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8007C70C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007C710: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007C714: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C718: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8007C71C: lwc1        $f16, 0x30A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8007C720: jal         0x800B81D0
    // 0x8007C724: sub.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f16.fl;
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007C724: sub.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f16.fl;
    after_0:
    // 0x8007C728: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C72C: lwc1        $f7, -0x2110($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2110);
    // 0x8007C730: lwc1        $f6, -0x210C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X210C);
    // 0x8007C734: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8007C738: mul.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8007C73C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C740: lwc1        $f11, -0x2108($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2108);
    // 0x8007C744: lwc1        $f10, -0x2104($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2104);
    // 0x8007C748: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007C74C: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x8007C750: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C754: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8007C758: mul.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8007C75C: lwc1        $f16, -0x20FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X20FC);
    // 0x8007C760: lwc1        $f17, -0x2100($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X2100);
    // 0x8007C764: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007C768: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8007C76C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8007C770: mul.d       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8007C774: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8007C778: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8007C77C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8007C780: nop

    // 0x8007C784: cvt.w.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_D(ctx->f8.d);
    // 0x8007C788: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8007C78C: nop

    // 0x8007C790: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x8007C794: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8007C798: beq         $t4, $zero, L_8007C7EC
    if (ctx->r12 == 0) {
        // 0x8007C79C: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_8007C7EC;
    }
    // 0x8007C79C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8007C7A0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007C7A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007C7A8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007C7AC: sub.d       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f8.d - ctx->f18.d;
    // 0x8007C7B0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8007C7B4: nop

    // 0x8007C7B8: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x8007C7BC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8007C7C0: nop

    // 0x8007C7C4: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x8007C7C8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8007C7CC: bne         $t4, $zero, L_8007C7E4
    if (ctx->r12 != 0) {
        // 0x8007C7D0: nop
    
            goto L_8007C7E4;
    }
    // 0x8007C7D0: nop

    // 0x8007C7D4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8007C7D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C7DC: b           L_8007C7FC
    // 0x8007C7E0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8007C7FC;
    // 0x8007C7E0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8007C7E4:
    // 0x8007C7E4: b           L_8007C7FC
    // 0x8007C7E8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8007C7FC;
    // 0x8007C7E8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_8007C7EC:
    // 0x8007C7EC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8007C7F0: nop

    // 0x8007C7F4: bltz        $t4, L_8007C7E4
    if (SIGNED(ctx->r12) < 0) {
        // 0x8007C7F8: nop
    
            goto L_8007C7E4;
    }
    // 0x8007C7F8: nop

L_8007C7FC:
    // 0x8007C7FC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C800: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8007C804: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x8007C808: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8007C80C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C810: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007C814: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x8007C818: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8007C81C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8007C820: bne         $at, $zero, L_8007C690
    if (ctx->r1 != 0) {
        // 0x8007C824: sw          $t7, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r15;
            goto L_8007C690;
    }
    // 0x8007C824: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8007C828: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007C82C: nop

    // 0x8007C830: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007C834: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x8007C838: bne         $at, $zero, L_8007C668
    if (ctx->r1 != 0) {
        // 0x8007C83C: sw          $t1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r9;
            goto L_8007C668;
    }
    // 0x8007C83C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8007C840: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C844: lwc1        $f6, 0x30A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8007C848: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C84C: lwc1        $f11, -0x20F8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X20F8);
    // 0x8007C850: lwc1        $f10, -0x20F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X20F4);
    // 0x8007C854: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8007C858: add.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d + ctx->f10.d;
    // 0x8007C85C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C860: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8007C864: swc1        $f8, 0x30A8($at)
    MEM_W(0X30A8, ctx->r1) = ctx->f8.u32l;
    // 0x8007C868: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C86C: lwc1        $f7, -0x20F0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X20F0);
    // 0x8007C870: lwc1        $f6, -0x20EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X20EC);
    // 0x8007C874: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8007C878: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8007C87C: nop

    // 0x8007C880: bc1f        L_8007C8A0
    if (!c1cs) {
        // 0x8007C884: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007C8A0;
    }
    // 0x8007C884: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C888: lwc1        $f5, -0x20E8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X20E8);
    // 0x8007C88C: lwc1        $f4, -0x20E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X20E4);
    // 0x8007C890: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C894: sub.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f18.d - ctx->f4.d;
    // 0x8007C898: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8007C89C: swc1        $f16, 0x30A8($at)
    MEM_W(0X30A8, ctx->r1) = ctx->f16.u32l;
L_8007C8A0:
    // 0x8007C8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C8A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007C8A8: jr          $ra
    // 0x8007C8AC: nop

    return;
    // 0x8007C8AC: nop

;}

RECOMP_FUNC void func_8007C8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C8B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007C8B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007C8B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007C8BC: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8007C8C0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8007C8C4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8007C8C8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_8007C8CC:
    // 0x8007C8CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C8D0: lwc1        $f14, -0x20E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X20E0);
    // 0x8007C8D4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8007C8D8: jal         0x800A36F0
    // 0x8007C8DC: nop

    func_800A36F0(rdram, ctx);
        goto after_0;
    // 0x8007C8DC: nop

    after_0:
    // 0x8007C8E0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8007C8E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C8E8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8007C8EC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007C8F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007C8F4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007C8F8: swc1        $f0, -0x1EC($at)
    MEM_W(-0X1EC, ctx->r1) = ctx->f0.u32l;
    // 0x8007C8FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C900: lwc1        $f12, -0x20DC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X20DC);
    // 0x8007C904: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C908: lwc1        $f14, -0x20D8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X20D8);
    // 0x8007C90C: jal         0x800A36F0
    // 0x8007C910: nop

    func_800A36F0(rdram, ctx);
        goto after_1;
    // 0x8007C910: nop

    after_1:
    // 0x8007C914: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8007C918: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007C91C: jal         0x800A35EC
    // 0x8007C920: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A35EC(rdram, ctx);
        goto after_2;
    // 0x8007C920: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8007C924: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8007C928: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007C92C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8007C930: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007C934: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007C938: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8007C93C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8007C940: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8007C944: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007C948: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C94C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8007C950: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8007C954: swc1        $f10, -0x1E8($at)
    MEM_W(-0X1E8, ctx->r1) = ctx->f10.u32l;
    // 0x8007C958: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C95C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8007C960: lwc1        $f16, -0x20D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X20D4);
    // 0x8007C964: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007C968: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8007C96C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007C970: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C974: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8007C978: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8007C97C: swc1        $f16, -0x1F0($at)
    MEM_W(-0X1F0, ctx->r1) = ctx->f16.u32l;
    // 0x8007C980: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8007C984: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007C988: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C98C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8007C990: lwc1        $f12, -0x1EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1EC);
    // 0x8007C994: jal         0x800B81D0
    // 0x8007C998: nop

    cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8007C998: nop

    after_3:
    // 0x8007C99C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8007C9A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007C9A4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8007C9A8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007C9AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007C9B0: addiu       $t8, $t8, -0x1F0
    ctx->r24 = ADD32(ctx->r24, -0X1F0);
    // 0x8007C9B4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8007C9B8: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8007C9BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C9C0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8007C9C4: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x8007C9C8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007C9CC: nop

    // 0x8007C9D0: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8007C9D4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8007C9D8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007C9DC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8007C9E0: lwc1        $f12, -0x1EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1EC);
    // 0x8007C9E4: jal         0x800B7B40
    // 0x8007C9E8: nop

    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8007C9E8: nop

    after_4:
    // 0x8007C9EC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8007C9F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007C9F4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8007C9F8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8007C9FC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007CA00: addiu       $t4, $t4, -0x1F0
    ctx->r12 = ADD32(ctx->r12, -0X1F0);
    // 0x8007CA04: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8007CA08: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8007CA0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CA10: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007CA14: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8007CA18: swc1        $f8, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f8.u32l;
    // 0x8007CA1C: lwc1        $f14, -0x20D0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X20D0);
    // 0x8007CA20: jal         0x800A36F0
    // 0x8007CA24: nop

    func_800A36F0(rdram, ctx);
        goto after_5;
    // 0x8007CA24: nop

    after_5:
    // 0x8007CA28: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8007CA2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007CA30: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8007CA34: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007CA38: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007CA3C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007CA40: swc1        $f0, -0x1DC($at)
    MEM_W(-0X1DC, ctx->r1) = ctx->f0.u32l;
    // 0x8007CA44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CA48: lwc1        $f12, -0x20CC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X20CC);
    // 0x8007CA4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CA50: lwc1        $f14, -0x20C8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X20C8);
    // 0x8007CA54: jal         0x800A36F0
    // 0x8007CA58: nop

    func_800A36F0(rdram, ctx);
        goto after_6;
    // 0x8007CA58: nop

    after_6:
    // 0x8007CA5C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8007CA60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007CA64: jal         0x800A35EC
    // 0x8007CA68: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A35EC(rdram, ctx);
        goto after_7;
    // 0x8007CA68: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8007CA6C: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8007CA70: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007CA74: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8007CA78: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007CA7C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007CA80: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8007CA84: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8007CA88: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8007CA8C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8007CA90: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007CA94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007CA98: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8007CA9C: swc1        $f18, -0x1D8($at)
    MEM_W(-0X1D8, ctx->r1) = ctx->f18.u32l;
    // 0x8007CAA0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007CAA4: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x8007CAA8: bne         $at, $zero, L_8007C8CC
    if (ctx->r1 != 0) {
        // 0x8007CAAC: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_8007C8CC;
    }
    // 0x8007CAAC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8007CAB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CAB4: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8007CAB8: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8007CABC: jr          $ra
    // 0x8007CAC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007CAC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void Math_AdvanceWrapAngles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CAC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007CAC8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CACC: addiu       $t6, $t6, -0x1F0
    ctx->r14 = ADD32(ctx->r14, -0X1F0);
    // 0x8007CAD0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8007CAD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007CAD8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8007CADC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8007CAE0:
    // 0x8007CAE0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8007CAE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CAE8: lwc1        $f4, 0x14($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8007CAEC: lwc1        $f6, 0x18($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X18);
    // 0x8007CAF0: nop

    // 0x8007CAF4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007CAF8: swc1        $f8, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f8.u32l;
    // 0x8007CAFC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8007CB00: lwc1        $f18, -0x20BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X20BC);
    // 0x8007CB04: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8007CB08: lwc1        $f19, -0x20C0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X20C0);
    // 0x8007CB0C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8007CB10: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8007CB14: nop

    // 0x8007CB18: bc1f        L_8007CB38
    if (!c1cs) {
        // 0x8007CB1C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007CB38;
    }
    // 0x8007CB1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CB20: lwc1        $f5, -0x20B8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X20B8);
    // 0x8007CB24: lwc1        $f4, -0x20B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X20B4);
    // 0x8007CB28: nop

    // 0x8007CB2C: sub.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d - ctx->f4.d;
    // 0x8007CB30: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8007CB34: swc1        $f8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f8.u32l;
L_8007CB38:
    // 0x8007CB38: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8007CB3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CB40: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8007CB44: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8007CB48: nop

    // 0x8007CB4C: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007CB50: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8007CB54: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8007CB58: lwc1        $f8, -0x20AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X20AC);
    // 0x8007CB5C: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8007CB60: lwc1        $f9, -0x20B0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X20B0);
    // 0x8007CB64: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007CB68: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8007CB6C: nop

    // 0x8007CB70: bc1f        L_8007CB90
    if (!c1cs) {
        // 0x8007CB74: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007CB90;
    }
    // 0x8007CB74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CB78: lwc1        $f11, -0x20A8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X20A8);
    // 0x8007CB7C: lwc1        $f10, -0x20A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X20A4);
    // 0x8007CB80: nop

    // 0x8007CB84: sub.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d - ctx->f10.d;
    // 0x8007CB88: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8007CB8C: swc1        $f16, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f16.u32l;
L_8007CB90:
    // 0x8007CB90: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8007CB94: nop

    // 0x8007CB98: lwc1        $f12, 0x4($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8007CB9C: jal         0x800B81D0
    // 0x8007CBA0: nop

    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007CBA0: nop

    after_0:
    // 0x8007CBA4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8007CBA8: nop

    // 0x8007CBAC: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8007CBB0: nop

    // 0x8007CBB4: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007CBB8: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x8007CBBC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8007CBC0: nop

    // 0x8007CBC4: lwc1        $f12, 0x4($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8007CBC8: jal         0x800B7B40
    // 0x8007CBCC: nop

    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007CBCC: nop

    after_1:
    // 0x8007CBD0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8007CBD4: nop

    // 0x8007CBD8: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8007CBDC: nop

    // 0x8007CBE0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007CBE4: swc1        $f10, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f10.u32l;
    // 0x8007CBE8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8007CBEC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CBF0: addiu       $t9, $t8, 0x1C
    ctx->r25 = ADD32(ctx->r24, 0X1C);
    // 0x8007CBF4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007CBF8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8007CBFC: bne         $t7, $zero, L_8007CAE0
    if (ctx->r15 != 0) {
        // 0x8007CC00: sw          $t9, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r25;
            goto L_8007CAE0;
    }
    // 0x8007CC00: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8007CC04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007CC08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007CC0C: jr          $ra
    // 0x8007CC10: nop

    return;
    // 0x8007CC10: nop

;}

RECOMP_FUNC void Math_GridMagnitude(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CC14: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007CC18: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CC1C: addiu       $t6, $t6, -0x2F0
    ctx->r14 = ADD32(ctx->r14, -0X2F0);
    // 0x8007CC20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007CC24: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8007CC28: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8007CC2C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8007CC30: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_8007CC34:
    // 0x8007CC34: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8007CC38: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8007CC3C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8007CC40: addiu       $t9, $t8, -0x10
    ctx->r25 = ADD32(ctx->r24, -0X10);
    // 0x8007CC44: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8007CC48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007CC4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007CC50: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8007CC54: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007CC58: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
L_8007CC5C:
    // 0x8007CC5C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8007CC60: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8007CC64: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8007CC68: addiu       $t2, $t1, -0x10
    ctx->r10 = ADD32(ctx->r9, -0X10);
    // 0x8007CC6C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8007CC70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007CC74: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007CC78: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007CC7C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007CC80: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8007CC84: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8007CC88: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8007CC8C: jal         0x800B8340
    // 0x8007CC90: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007CC90: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    after_0:
    // 0x8007CC94: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8007CC98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CC9C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007CCA0: lwc1        $f7, -0x20A0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X20A0);
    // 0x8007CCA4: lwc1        $f6, -0x209C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X209C);
    // 0x8007CCA8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8007CCAC: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8007CCB0: nop

    // 0x8007CCB4: bc1f        L_8007CD1C
    if (!c1cs) {
        // 0x8007CCB8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007CD1C;
    }
    // 0x8007CCB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CCBC: lwc1        $f11, -0x2098($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2098);
    // 0x8007CCC0: lwc1        $f10, -0x2094($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2094);
    // 0x8007CCC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CCC8: sub.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d - ctx->f10.d;
    // 0x8007CCCC: lwc1        $f7, -0x2090($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2090);
    // 0x8007CCD0: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8007CCD4: lwc1        $f6, -0x208C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X208C);
    // 0x8007CCD8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8007CCDC: mul.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8007CCE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CCE4: lwc1        $f11, -0x2088($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2088);
    // 0x8007CCE8: lwc1        $f10, -0x2084($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2084);
    // 0x8007CCEC: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8007CCF0: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x8007CCF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CCF8: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8007CCFC: lwc1        $f7, -0x2080($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2080);
    // 0x8007CD00: lwc1        $f6, -0x207C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X207C);
    // 0x8007CD04: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8007CD08: mul.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8007CD0C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8007CD10: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8007CD14: b           L_8007CD58
    // 0x8007CD18: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
        goto L_8007CD58;
    // 0x8007CD18: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
L_8007CD1C:
    // 0x8007CD1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CD20: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007CD24: lwc1        $f19, -0x2078($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2078);
    // 0x8007CD28: lwc1        $f18, -0x2074($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2074);
    // 0x8007CD2C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8007CD30: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8007CD34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CD38: lwc1        $f9, -0x2070($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2070);
    // 0x8007CD3C: lwc1        $f8, -0x206C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X206C);
    // 0x8007CD40: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8007CD44: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8007CD48: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x8007CD4C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8007CD50: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8007CD54: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
L_8007CD58:
    // 0x8007CD58: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007CD5C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8007CD60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007CD64: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8007CD68: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x8007CD6C: nop

    // 0x8007CD70: bc1f        L_8007CD84
    if (!c1cs) {
        // 0x8007CD74: nop
    
            goto L_8007CD84;
    }
    // 0x8007CD74: nop

    // 0x8007CD78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007CD7C: nop

    // 0x8007CD80: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
L_8007CD84:
    // 0x8007CD84: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007CD88: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007CD8C: addiu       $t3, $t3, -0x1F0
    ctx->r11 = ADD32(ctx->r11, -0X1F0);
    // 0x8007CD90: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8007CD94: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8007CD98: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
L_8007CD9C:
    // 0x8007CD9C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8007CDA0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007CDA4: lwc1        $f18, 0xC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8007CDA8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007CDAC: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8007CDB0: lwc1        $f8, 0x10($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8007CDB4: lwc1        $f6, 0x14($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8007CDB8: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8007CDBC: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8007CDC0: jal         0x800B7B40
    // 0x8007CDC4: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007CDC4: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_1:
    // 0x8007CDC8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8007CDCC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8007CDD0: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007CDD4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8007CDD8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8007CDDC: add.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8007CDE0: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x8007CDE4: addiu       $t8, $t7, 0x1C
    ctx->r24 = ADD32(ctx->r15, 0X1C);
    // 0x8007CDE8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8007CDEC: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8007CDF0: bne         $at, $zero, L_8007CD9C
    if (ctx->r1 != 0) {
        // 0x8007CDF4: swc1        $f8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
            goto L_8007CD9C;
    }
    // 0x8007CDF4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8007CDF8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8007CDFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007CE00: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007CE04: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8007CE08: div.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8007CE0C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007CE10: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007CE14: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007CE18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CE1C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007CE20: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8007CE24: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8007CE28: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8007CE2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007CE30: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8007CE34: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007CE38: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8007CE3C: add.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f16.d + ctx->f18.d;
    // 0x8007CE40: lwc1        $f16, -0x2064($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2064);
    // 0x8007CE44: lwc1        $f17, -0x2068($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X2068);
    // 0x8007CE48: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8007CE4C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8007CE50: mul.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8007CE54: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8007CE58: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8007CE5C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007CE60: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8007CE64: nop

    // 0x8007CE68: cvt.w.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_D(ctx->f18.d);
    // 0x8007CE6C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8007CE70: nop

    // 0x8007CE74: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x8007CE78: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8007CE7C: beq         $t0, $zero, L_8007CED0
    if (ctx->r8 == 0) {
        // 0x8007CE80: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_8007CED0;
    }
    // 0x8007CE80: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8007CE84: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007CE88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CE8C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007CE90: sub.d       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f18.d - ctx->f6.d;
    // 0x8007CE94: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8007CE98: nop

    // 0x8007CE9C: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x8007CEA0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8007CEA4: nop

    // 0x8007CEA8: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x8007CEAC: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8007CEB0: bne         $t0, $zero, L_8007CEC8
    if (ctx->r8 != 0) {
        // 0x8007CEB4: nop
    
            goto L_8007CEC8;
    }
    // 0x8007CEB4: nop

    // 0x8007CEB8: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8007CEBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007CEC0: b           L_8007CEE0
    // 0x8007CEC4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8007CEE0;
    // 0x8007CEC4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8007CEC8:
    // 0x8007CEC8: b           L_8007CEE0
    // 0x8007CECC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8007CEE0;
    // 0x8007CECC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8007CED0:
    // 0x8007CED0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8007CED4: nop

    // 0x8007CED8: bltz        $t0, L_8007CEC8
    if (SIGNED(ctx->r8) < 0) {
        // 0x8007CEDC: nop
    
            goto L_8007CEC8;
    }
    // 0x8007CEDC: nop

L_8007CEE0:
    // 0x8007CEE0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8007CEE4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007CEE8: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x8007CEEC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8007CEF0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007CEF4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007CEF8: slti        $at, $t3, 0x10
    ctx->r1 = SIGNED(ctx->r11) < 0X10 ? 1 : 0;
    // 0x8007CEFC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007CF00: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8007CF04: bne         $at, $zero, L_8007CC5C
    if (ctx->r1 != 0) {
        // 0x8007CF08: sw          $t3, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r11;
            goto L_8007CC5C;
    }
    // 0x8007CF08: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8007CF0C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8007CF10: nop

    // 0x8007CF14: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8007CF18: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x8007CF1C: bne         $at, $zero, L_8007CC34
    if (ctx->r1 != 0) {
        // 0x8007CF20: sw          $t8, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r24;
            goto L_8007CC34;
    }
    // 0x8007CF20: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8007CF24: jal         0x8007CAC4
    // 0x8007CF28: nop

    Math_AdvanceWrapAngles(rdram, ctx);
        goto after_2;
    // 0x8007CF28: nop

    after_2:
    // 0x8007CF2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CF30: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8007CF34: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8007CF38: jr          $ra
    // 0x8007CF3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007CF3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void func_8007CF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CF40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007CF44: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8007CF48: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x8007CF4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007CF50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007CF54: jal         0x800AC9C0
    // 0x8007CF58: sw          $t6, 0x3040($at)
    MEM_W(0X3040, ctx->r1) = ctx->r14;
    func_800AC9C0(rdram, ctx);
        goto after_0;
    // 0x8007CF58: sw          $t6, 0x3040($at)
    MEM_W(0X3040, ctx->r1) = ctx->r14;
    after_0:
    // 0x8007CF5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007CF60: sw          $v0, -0x164($at)
    MEM_W(-0X164, ctx->r1) = ctx->r2;
    // 0x8007CF64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007CF68: lw          $a0, -0x164($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X164);
    // 0x8007CF6C: jal         0x800A4364
    // 0x8007CF70: lui         $a1, 0x42DC
    ctx->r5 = S32(0X42DC << 16);
    func_800A4364(rdram, ctx);
        goto after_1;
    // 0x8007CF70: lui         $a1, 0x42DC
    ctx->r5 = S32(0X42DC << 16);
    after_1:
    // 0x8007CF74: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007CF78: lw          $a0, -0x164($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X164);
    // 0x8007CF7C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x8007CF80: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x8007CF84: jal         0x800A43B0
    // 0x8007CF88: lui         $a2, 0x4280
    ctx->r6 = S32(0X4280 << 16);
    func_800A43B0(rdram, ctx);
        goto after_2;
    // 0x8007CF88: lui         $a2, 0x4280
    ctx->r6 = S32(0X4280 << 16);
    after_2:
    // 0x8007CF8C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007CF90: addiu       $a1, $a1, 0x3044
    ctx->r5 = ADD32(ctx->r5, 0X3044);
    // 0x8007CF94: jal         0x800ACEA0
    // 0x8007CF98: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800ACEA0(rdram, ctx);
        goto after_3;
    // 0x8007CF98: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_3:
    // 0x8007CF9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007CFA0: sw          $v0, -0x158($at)
    MEM_W(-0X158, ctx->r1) = ctx->r2;
    // 0x8007CFA4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007CFA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007CFAC: lw          $t7, -0x158($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X158);
    // 0x8007CFB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007CFB4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8007CFB8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007CFBC: swc1        $f4, 0x10C($t7)
    MEM_W(0X10C, ctx->r15) = ctx->f4.u32l;
    // 0x8007CFC0: lw          $t8, -0x158($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X158);
    // 0x8007CFC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007CFC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CFCC: swc1        $f6, 0x110($t8)
    MEM_W(0X110, ctx->r24) = ctx->f6.u32l;
    // 0x8007CFD0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007CFD4: lw          $t9, -0x158($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X158);
    // 0x8007CFD8: lwc1        $f8, -0x2060($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2060);
    // 0x8007CFDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CFE0: swc1        $f8, 0x104($t9)
    MEM_W(0X104, ctx->r25) = ctx->f8.u32l;
    // 0x8007CFE4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007CFE8: lw          $t0, -0x158($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X158);
    // 0x8007CFEC: lwc1        $f10, -0x205C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X205C);
    // 0x8007CFF0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8007CFF4: swc1        $f10, 0x108($t0)
    MEM_W(0X108, ctx->r8) = ctx->f10.u32l;
    // 0x8007CFF8: lw          $t1, -0x158($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X158);
    // 0x8007CFFC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007D000: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007D004: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007D008: swc1        $f16, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = ctx->f16.u32l;
    // 0x8007D00C: lw          $t2, -0x158($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X158);
    // 0x8007D010: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007D014: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007D018: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007D01C: swc1        $f18, 0xDC($t2)
    MEM_W(0XDC, ctx->r10) = ctx->f18.u32l;
    // 0x8007D020: lw          $t3, -0x158($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X158);
    // 0x8007D024: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007D028: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007D02C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007D030: swc1        $f4, 0xE0($t3)
    MEM_W(0XE0, ctx->r11) = ctx->f4.u32l;
    // 0x8007D034: lw          $t4, -0x158($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X158);
    // 0x8007D038: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007D03C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007D040: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8007D044: swc1        $f6, 0xE8($t4)
    MEM_W(0XE8, ctx->r12) = ctx->f6.u32l;
    // 0x8007D048: lw          $t5, -0x158($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X158);
    // 0x8007D04C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007D050: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007D054: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007D058: swc1        $f8, 0xEC($t5)
    MEM_W(0XEC, ctx->r13) = ctx->f8.u32l;
    // 0x8007D05C: lw          $t6, -0x158($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X158);
    // 0x8007D060: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007D064: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007D068: swc1        $f10, 0xF0($t6)
    MEM_W(0XF0, ctx->r14) = ctx->f10.u32l;
    // 0x8007D06C: lw          $t8, -0x158($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X158);
    // 0x8007D070: addiu       $t7, $zero, 0x15E
    ctx->r15 = ADD32(0, 0X15E);
    // 0x8007D074: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007D078: sw          $t7, 0xD4($t8)
    MEM_W(0XD4, ctx->r24) = ctx->r15;
    // 0x8007D07C: lw          $t9, -0x158($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X158);
    // 0x8007D080: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007D084: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007D088: addiu       $t1, $t1, 0x3060
    ctx->r9 = ADD32(ctx->r9, 0X3060);
    // 0x8007D08C: swc1        $f16, 0x114($t9)
    MEM_W(0X114, ctx->r25) = ctx->f16.u32l;
    // 0x8007D090: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D094: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007D098: addiu       $t0, $t0, -0x2F0
    ctx->r8 = ADD32(ctx->r8, -0X2F0);
    // 0x8007D09C: sw          $t0, 0x3058($at)
    MEM_W(0X3058, ctx->r1) = ctx->r8;
    // 0x8007D0A0: sw          $t1, 0x3054($at)
    MEM_W(0X3054, ctx->r1) = ctx->r9;
    // 0x8007D0A4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x8007D0A8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007D0AC: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x8007D0B0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8007D0B4: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8007D0B8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007D0BC: lui         $t3, 0xFD90
    ctx->r11 = S32(0XFD90 << 16);
    // 0x8007D0C0: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8007D0C4: addiu       $t4, $t4, -0x2F0
    ctx->r12 = ADD32(ctx->r12, -0X2F0);
    // 0x8007D0C8: addiu       $t5, $t5, 0x3044
    ctx->r13 = ADD32(ctx->r13, 0X3044);
    // 0x8007D0CC: lui         $at, 0xAFF
    ctx->r1 = S32(0XAFF << 16);
    // 0x8007D0D0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007D0D4: ori         $at, $at, 0xFFF8
    ctx->r1 = ctx->r1 | 0XFFF8;
    // 0x8007D0D8: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x8007D0DC: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x8007D0E0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8007D0E4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8007D0E8: lui         $t2, 0xF590
    ctx->r10 = S32(0XF590 << 16);
    // 0x8007D0EC: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8007D0F0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D0F4: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8007D0F8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8007D0FC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8007D100: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D104: lui         $t1, 0x701
    ctx->r9 = S32(0X701 << 16);
    // 0x8007D108: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x8007D10C: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x8007D110: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8007D114: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8007D118: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8007D11C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007D120: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8007D124: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8007D128: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8007D12C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007D130: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x8007D134: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8007D138: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007D13C: lui         $t4, 0x707
    ctx->r12 = S32(0X707 << 16);
    // 0x8007D140: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8007D144: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8007D148: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x8007D14C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x8007D150: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8007D154: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007D158: ori         $t4, $t4, 0xF400
    ctx->r12 = ctx->r12 | 0XF400;
    // 0x8007D15C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8007D160: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8007D164: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007D168: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8007D16C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8007D170: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007D174: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8007D178: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007D17C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8007D180: lui         $t1, 0xF588
    ctx->r9 = S32(0XF588 << 16);
    // 0x8007D184: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007D188: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8007D18C: ori         $t1, $t1, 0x400
    ctx->r9 = ctx->r9 | 0X400;
    // 0x8007D190: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8007D194: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D198: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8007D19C: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8007D1A0: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x8007D1A4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D1A8: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x8007D1AC: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x8007D1B0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8007D1B4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8007D1B8: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007D1BC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8007D1C0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8007D1C4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8007D1C8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8007D1CC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007D1D0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8007D1D4: lui         $t2, 0x3
    ctx->r10 = S32(0X3 << 16);
    // 0x8007D1D8: ori         $t2, $t2, 0xC03C
    ctx->r10 = ctx->r10 | 0XC03C;
    // 0x8007D1DC: jal         0x8007C8B0
    // 0x8007D1E0: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    func_8007C8B0(rdram, ctx);
        goto after_4;
    // 0x8007D1E0: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    after_4:
    // 0x8007D1E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007D1E8: lw          $a0, -0x158($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X158);
    // 0x8007D1EC: jal         0x8007D458
    // 0x8007D1F0: nop

    func_8007D458(rdram, ctx);
        goto after_5;
    // 0x8007D1F0: nop

    after_5:
    // 0x8007D1F4: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    // 0x8007D1F8: jal         0x800ADE5C
    // 0x8007D1FC: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    func_800ADE5C(rdram, ctx);
        goto after_6;
    // 0x8007D1FC: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_6:
    // 0x8007D200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007D208: sw          $v0, -0x154($at)
    MEM_W(-0X154, ctx->r1) = ctx->r2;
    // 0x8007D20C: jr          $ra
    // 0x8007D210: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007D210: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void func_8007D214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007D218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D21C: jal         0x8004A34C
    // 0x8007D220: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x8007D220: nop

    after_0:
    // 0x8007D224: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007D228: lw          $a0, -0x158($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X158);
    // 0x8007D22C: jal         0x800AD120
    // 0x8007D230: nop

    func_800AD120(rdram, ctx);
        goto after_1;
    // 0x8007D230: nop

    after_1:
    // 0x8007D234: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D238: sb          $zero, 0x3CF0($at)
    MEM_B(0X3CF0, ctx->r1) = 0;
    // 0x8007D23C: jal         0x800905E8
    // 0x8007D240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800905E8(rdram, ctx);
        goto after_2;
    // 0x8007D240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8007D244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D248: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8007D24C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D250: sb          $t6, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r14;
    // 0x8007D254: jr          $ra
    // 0x8007D258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007D258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void func_8007D25C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D25C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007D260: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D264: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007D268: lwc1        $f9, -0x2058($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2058);
    // 0x8007D26C: lwc1        $f8, -0x2054($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2054);
    // 0x8007D270: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007D274: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8007D278: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8007D27C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8007D280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D284: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8007D288: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8007D28C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8007D290: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8007D294: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x8007D298: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x8007D29C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D2A0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8007D2A4: lwc1        $f19, -0x2050($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2050);
    // 0x8007D2A8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8007D2AC: lwc1        $f18, -0x204C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X204C);
    // 0x8007D2B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007D2B4: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
    // 0x8007D2B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D2BC: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8007D2C0: nop

    // 0x8007D2C4: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8007D2C8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007D2CC: lwc1        $f8, -0x2044($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2044);
    // 0x8007D2D0: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8007D2D4: lw          $t8, 0xC4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC4);
    // 0x8007D2D8: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x8007D2DC: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8007D2E0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x8007D2E4: lwc1        $f9, -0x2048($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2048);
    // 0x8007D2E8: lw          $t9, 0xC0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC0);
    // 0x8007D2EC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8007D2F0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8007D2F4: nop

    // 0x8007D2F8: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x8007D2FC: nop

    // 0x8007D300: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8007D304: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8007D308: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8007D30C: lw          $t0, 0xC0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0XC0);
    // 0x8007D310: nop

    // 0x8007D314: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x8007D318: beq         $t1, $zero, L_8007D448
    if (ctx->r9 == 0) {
        // 0x8007D31C: sh          $t0, 0x4A($sp)
        MEM_H(0X4A, ctx->r29) = ctx->r8;
            goto L_8007D448;
    }
    // 0x8007D31C: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
L_8007D320:
    // 0x8007D320: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007D324: jal         0x800B81D0
    // 0x8007D328: nop

    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007D328: nop

    after_0:
    // 0x8007D32C: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007D330: jal         0x800B7B40
    // 0x8007D334: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007D334: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8007D338: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007D33C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007D340: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8007D344: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8007D348: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007D34C: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007D350: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8007D354: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8007D358: jal         0x800B7B40
    // 0x8007D35C: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007D35C: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8007D360: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8007D364: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D368: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007D36C: lwc1        $f17, -0x2040($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X2040);
    // 0x8007D370: lwc1        $f16, -0x203C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X203C);
    // 0x8007D374: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007D378: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007D37C: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8007D380: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8007D384: jal         0x800B81D0
    // 0x8007D388: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8007D388: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8007D38C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8007D390: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007D394: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007D398: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007D39C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D3A0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8007D3A4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007D3A8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007D3AC: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007D3B0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8007D3B4: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8007D3B8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8007D3BC: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007D3C0: nop

    // 0x8007D3C4: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007D3C8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8007D3CC: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
    // 0x8007D3D0: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007D3D4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007D3D8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D3DC: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007D3E0: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x8007D3E4: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007D3E8: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007D3EC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D3F0: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007D3F4: swc1        $f4, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f4.u32l;
    // 0x8007D3F8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D3FC: lhu         $t5, 0x4A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X4A);
    // 0x8007D400: nop

    // 0x8007D404: sw          $t5, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r13;
    // 0x8007D408: lhu         $t8, 0x4A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X4A);
    // 0x8007D40C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007D410: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007D414: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007D418: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007D41C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D420: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007D424: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007D428: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x8007D42C: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007D430: addiu       $t0, $t6, 0x28
    ctx->r8 = ADD32(ctx->r14, 0X28);
    // 0x8007D434: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8007D438: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8007D43C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8007D440: bne         $t1, $zero, L_8007D320
    if (ctx->r9 != 0) {
        // 0x8007D444: sh          $t9, 0x4A($sp)
        MEM_H(0X4A, ctx->r29) = ctx->r25;
            goto L_8007D320;
    }
    // 0x8007D444: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
L_8007D448:
    // 0x8007D448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D44C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8007D450: jr          $ra
    // 0x8007D454: nop

    return;
    // 0x8007D454: nop

;}

RECOMP_FUNC void func_8007D458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D458: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007D45C: sw          $t6, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->r14;
    // 0x8007D460: lw          $t7, 0xC4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC4);
    // 0x8007D464: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8007D468: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D46C: lwc1        $f4, -0x2038($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2038);
    // 0x8007D470: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8007D474: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8007D478: swc1        $f4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f4.u32l;
    // 0x8007D47C: lw          $t8, 0xC0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC0);
    // 0x8007D480: nop

    // 0x8007D484: blez        $t8, L_8007D508
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8007D488: nop
    
            goto L_8007D508;
    }
    // 0x8007D488: nop

L_8007D48C:
    // 0x8007D48C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8007D490: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8007D494: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D498: sw          $t9, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r25;
    // 0x8007D49C: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8007D4A0: lwc1        $f10, -0x202C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X202C);
    // 0x8007D4A4: lwc1        $f11, -0x2030($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2030);
    // 0x8007D4A8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8007D4AC: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8007D4B0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8007D4B4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8007D4B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D4BC: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x8007D4C0: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8007D4C4: lwc1        $f8, -0x2024($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2024);
    // 0x8007D4C8: lwc1        $f9, -0x2028($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2028);
    // 0x8007D4CC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007D4D0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8007D4D4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8007D4D8: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8007D4DC: addiu       $t5, $t4, 0x28
    ctx->r13 = ADD32(ctx->r12, 0X28);
    // 0x8007D4E0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007D4E4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8007D4E8: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x8007D4EC: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8007D4F0: swc1        $f16, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f16.u32l;
    // 0x8007D4F4: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x8007D4F8: nop

    // 0x8007D4FC: slt         $at, $t3, $t6
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007D500: bne         $at, $zero, L_8007D48C
    if (ctx->r1 != 0) {
        // 0x8007D504: nop
    
            goto L_8007D48C;
    }
    // 0x8007D504: nop

L_8007D508:
    // 0x8007D508: jr          $ra
    // 0x8007D50C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007D50C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void Math_ApplySineWave(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D510: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007D514: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8007D518: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007D51C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D520: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8007D524: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8007D528: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8007D52C: lw          $t7, 0xC4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC4);
    // 0x8007D530: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007D534: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007D538: lw          $t8, 0xC0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC0);
    // 0x8007D53C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8007D540: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8007D544: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007D548: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8007D54C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D550: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007D554: div.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x8007D558: lwc1        $f8, -0x201C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X201C);
    // 0x8007D55C: lwc1        $f9, -0x2020($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2020);
    // 0x8007D560: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8007D564: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007D568: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007D56C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8007D570: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8007D574: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8007D578: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8007D57C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8007D580: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007D584: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8007D588: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8007D58C: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8007D590: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8007D594: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8007D598: lw          $t9, 0xC0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC0);
    // 0x8007D59C: nop

    // 0x8007D5A0: blez        $t9, L_8007D698
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8007D5A4: nop
    
            goto L_8007D698;
    }
    // 0x8007D5A4: nop

L_8007D5A8:
    // 0x8007D5A8: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007D5AC: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007D5B0: nop

    // 0x8007D5B4: mul.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8007D5B8: jal         0x800B7B40
    // 0x8007D5BC: nop

    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007D5BC: nop

    after_0:
    // 0x8007D5C0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007D5C4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007D5C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007D5CC: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8007D5D0: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8007D5D4: add.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f18.d + ctx->f6.d;
    // 0x8007D5D8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007D5DC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8007D5E0: mul.d       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8007D5E4: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007D5E8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8007D5EC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8007D5F0: jal         0x800B81D0
    // 0x8007D5F4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007D5F4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x8007D5F8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007D5FC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007D600: mul.s       $f16, $f0, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007D604: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8007D608: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007D60C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007D610: nop

    // 0x8007D614: swc1        $f10, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f10.u32l;
    // 0x8007D618: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007D61C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007D620: jal         0x800B7B40
    // 0x8007D624: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007D624: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_2:
    // 0x8007D628: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007D62C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007D630: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8007D634: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D638: swc1        $f4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
    // 0x8007D63C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007D640: lwc1        $f18, -0x2014($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2014);
    // 0x8007D644: lwc1        $f19, -0x2018($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2018);
    // 0x8007D648: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8007D64C: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8007D650: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007D654: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007D658: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007D65C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8007D660: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8007D664: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8007D668: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8007D66C: addiu       $t7, $t5, 0x28
    ctx->r15 = ADD32(ctx->r13, 0X28);
    // 0x8007D670: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007D674: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8007D678: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007D67C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8007D680: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x8007D684: lw          $t6, 0xC0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC0);
    // 0x8007D688: nop

    // 0x8007D68C: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007D690: bne         $at, $zero, L_8007D5A8
    if (ctx->r1 != 0) {
        // 0x8007D694: nop
    
            goto L_8007D5A8;
    }
    // 0x8007D694: nop

L_8007D698:
    // 0x8007D698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D69C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007D6A0: jr          $ra
    // 0x8007D6A4: nop

    return;
    // 0x8007D6A4: nop

;}

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
    func_800A4B98(rdram, ctx);
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
    func_800AFBBC(rdram, ctx);
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

RECOMP_FUNC void func_8007DA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DA00: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007DA04: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007DA08: lw          $t6, 0x3040($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3040);
    // 0x8007DA0C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007DA10: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8007DA14: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8007DA18: beq         $t6, $zero, L_8007DAE0
    if (ctx->r14 == 0) {
        // 0x8007DA1C: swc1        $f20, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
            goto L_8007DAE0;
    }
    // 0x8007DA1C: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8007DA20: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8007DA24: addiu       $t8, $t8, 0x3150
    ctx->r24 = ADD32(ctx->r24, 0X3150);
    // 0x8007DA28: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8007DA2C: addiu       $t7, $sp, 0x38
    ctx->r15 = ADD32(ctx->r29, 0X38);
    // 0x8007DA30: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x8007DA34: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x8007DA38: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x8007DA3C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007DA40: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x8007DA44: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x8007DA48: lw          $a0, -0x154($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X154);
    // 0x8007DA4C: jal         0x800AE6E4
    // 0x8007DA50: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800AE6E4(rdram, ctx);
        goto after_0;
    // 0x8007DA50: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x8007DA54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007DA58: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007DA5C: lw          $a1, 0x3180($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3180);
    // 0x8007DA60: lw          $a0, -0x154($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X154);
    // 0x8007DA64: jal         0x800AE700
    // 0x8007DA68: nop

    func_800AE700(rdram, ctx);
        goto after_1;
    // 0x8007DA68: nop

    after_1:
    // 0x8007DA6C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007DA70: lhu         $t1, 0x20B0($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X20B0);
    // 0x8007DA74: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007DA78: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x8007DA7C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8007DA80: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8007DA84: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007DA88: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007DA8C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007DA90: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007DA94: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007DA98: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007DA9C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007DAA0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8007DAA4: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8007DAA8: addiu       $t4, $t4, -0x5300
    ctx->r12 = ADD32(ctx->r12, -0X5300);
    // 0x8007DAAC: sll         $t3, $t3, 7
    ctx->r11 = S32(ctx->r11 << 7);
    // 0x8007DAB0: lw          $a0, -0x154($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X154);
    // 0x8007DAB4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8007DAB8: addiu       $t5, $zero, 0xFA
    ctx->r13 = ADD32(0, 0XFA);
    // 0x8007DABC: addiu       $t6, $zero, 0xFA
    ctx->r14 = ADD32(0, 0XFA);
    // 0x8007DAC0: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x8007DAC4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8007DAC8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8007DACC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8007DAD0: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x8007DAD4: jal         0x800AE220
    // 0x8007DAD8: addiu       $a3, $zero, 0xFA
    ctx->r7 = ADD32(0, 0XFA);
    func_800AE220(rdram, ctx);
        goto after_2;
    // 0x8007DAD8: addiu       $a3, $zero, 0xFA
    ctx->r7 = ADD32(0, 0XFA);
    after_2:
    // 0x8007DADC: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
L_8007DAE0:
    // 0x8007DAE0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8007DAE4: lbu         $t7, -0x118($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X118);
    // 0x8007DAE8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8007DAEC: bne         $t7, $at, L_8007DB40
    if (ctx->r15 != ctx->r1) {
        // 0x8007DAF0: nop
    
            goto L_8007DB40;
    }
    // 0x8007DAF0: nop

    // 0x8007DAF4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007DAF8: addiu       $t8, $t8, -0x10D0
    ctx->r24 = ADD32(ctx->r24, -0X10D0);
    // 0x8007DAFC: lw          $t0, 0x1C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X1C);
    // 0x8007DB00: nop

    // 0x8007DB04: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8007DB08: nop

    // 0x8007DB0C: andi        $t2, $t1, 0x1000
    ctx->r10 = ctx->r9 & 0X1000;
    // 0x8007DB10: beq         $t2, $zero, L_8007DB40
    if (ctx->r10 == 0) {
        // 0x8007DB14: nop
    
            goto L_8007DB40;
    }
    // 0x8007DB14: nop

    // 0x8007DB18: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8007DB1C: nop

    // 0x8007DB20: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x8007DB24: bne         $t4, $zero, L_8007DB40
    if (ctx->r12 != 0) {
        // 0x8007DB28: nop
    
            goto L_8007DB40;
    }
    // 0x8007DB28: nop

    // 0x8007DB2C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8007DB30: lw          $t5, 0x3040($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3040);
    // 0x8007DB34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DB38: xori        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 ^ 0X1;
    // 0x8007DB3C: sw          $t6, 0x3040($at)
    MEM_W(0X3040, ctx->r1) = ctx->r14;
L_8007DB40:
    // 0x8007DB40: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007DB44: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007DB48: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007DB4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007DB50: lw          $a0, -0x164($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X164);
    // 0x8007DB54: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007DB58: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007DB5C: lui         $a3, 0xC0A0
    ctx->r7 = S32(0XC0A0 << 16);
    // 0x8007DB60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007DB64: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8007DB68: jal         0x800A4304
    // 0x8007DB6C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_800A4304(rdram, ctx);
        goto after_3;
    // 0x8007DB6C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8007DB70: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007DB74: lw          $a1, -0x164($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X164);
    // 0x8007DB78: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007DB7C: jal         0x800A724C
    // 0x8007DB80: nop

    func_800A724C(rdram, ctx);
        goto after_4;
    // 0x8007DB80: nop

    after_4:
    // 0x8007DB84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DB88: lwc1        $f12, 0x316C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X316C);
    // 0x8007DB8C: jal         0x800B7B40
    // 0x8007DB90: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x8007DB90: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_5:
    // 0x8007DB94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DB98: lwc1        $f10, 0x315C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X315C);
    // 0x8007DB9C: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8007DBA0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007DBA4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007DBA8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8007DBAC: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8007DBB0: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8007DBB4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007DBB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007DBBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DBC0: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8007DBC4: lwc1        $f4, -0x200C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X200C);
    // 0x8007DBC8: lwc1        $f5, -0x2010($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2010);
    // 0x8007DBCC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8007DBD0: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8007DBD4: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8007DBD8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007DBDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DBE0: lwc1        $f9, -0x2008($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2008);
    // 0x8007DBE4: lwc1        $f8, -0x2004($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2004);
    // 0x8007DBE8: lui         $at, 0x405E
    ctx->r1 = S32(0X405E << 16);
    // 0x8007DBEC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8007DBF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007DBF4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8007DBF8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8007DBFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007DC00: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x8007DC04: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8007DC08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007DC0C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007DC10: lw          $a0, -0x158($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X158);
    // 0x8007DC14: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8007DC18: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8007DC1C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8007DC20: lui         $a2, 0x40E0
    ctx->r6 = S32(0X40E0 << 16);
    // 0x8007DC24: jal         0x8007D510
    // 0x8007DC28: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Math_ApplySineWave(rdram, ctx);
        goto after_6;
    // 0x8007DC28: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8007DC2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DC30: lwc1        $f12, 0x316C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X316C);
    // 0x8007DC34: jal         0x800B81D0
    // 0x8007DC38: nop

    cosf_recomp(rdram, ctx);
        goto after_7;
    // 0x8007DC38: nop

    after_7:
    // 0x8007DC3C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8007DC40: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007DC44: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007DC48: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8007DC4C: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x8007DC50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DC54: lwc1        $f12, 0x3174($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X3174);
    // 0x8007DC58: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007DC5C: jal         0x800B81D0
    // 0x8007DC60: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    cosf_recomp(rdram, ctx);
        goto after_8;
    // 0x8007DC60: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x8007DC64: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8007DC68: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007DC6C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007DC70: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8007DC74: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8007DC78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DC7C: lwc1        $f12, 0x316C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X316C);
    // 0x8007DC80: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8007DC84: jal         0x800B7B40
    // 0x8007DC88: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    sinf_recomp(rdram, ctx);
        goto after_9;
    // 0x8007DC88: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x8007DC8C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8007DC90: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007DC94: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007DC98: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8007DC9C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8007DCA0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8007DCA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007DCA8: addiu       $a1, $a1, 0xB0
    ctx->r5 = ADD32(ctx->r5, 0XB0);
    // 0x8007DCAC: addiu       $a0, $a0, 0x3130
    ctx->r4 = ADD32(ctx->r4, 0X3130);
    // 0x8007DCB0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007DCB4: jal         0x800B11C4
    // 0x8007DCB8: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    func_800B11C4(rdram, ctx);
        goto after_10;
    // 0x8007DCB8: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x8007DCBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DCC0: lwc1        $f18, 0x3130($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3130);
    // 0x8007DCC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DCC8: lwc1        $f5, -0x2000($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2000);
    // 0x8007DCCC: lwc1        $f4, -0x1FFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1FFC);
    // 0x8007DCD0: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8007DCD4: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x8007DCD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DCDC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8007DCE0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007DCE4: swc1        $f8, 0x3130($at)
    MEM_W(0X3130, ctx->r1) = ctx->f8.u32l;
    // 0x8007DCE8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007DCEC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007DCF0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007DCF4: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8007DCF8: nop

    // 0x8007DCFC: bc1f        L_8007DD1C
    if (!c1cs) {
        // 0x8007DD00: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_8007DD1C;
    }
    // 0x8007DD00: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007DD04: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007DD08: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007DD0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DD10: sub.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f10.d - ctx->f16.d;
    // 0x8007DD14: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007DD18: swc1        $f6, 0x3130($at)
    MEM_W(0X3130, ctx->r1) = ctx->f6.u32l;
L_8007DD1C:
    // 0x8007DD1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DD20: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007DD24: lw          $t9, -0x158($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X158);
    // 0x8007DD28: lwc1        $f8, 0x3178($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3178);
    // 0x8007DD2C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007DD30: swc1        $f8, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->f8.u32l;
    // 0x8007DD34: lwc1        $f18, 0x3178($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3178);
    // 0x8007DD38: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8007DD3C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007DD40: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8007DD44: add.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f10.d + ctx->f16.d;
    // 0x8007DD48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007DD4C: lw          $t7, -0x158($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X158);
    // 0x8007DD50: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007DD54: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007DD58: swc1        $f6, 0xE8($t7)
    MEM_W(0XE8, ctx->r15) = ctx->f6.u32l;
    // 0x8007DD5C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007DD60: lw          $a2, -0x164($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X164);
    // 0x8007DD64: lw          $a1, -0x158($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X158);
    // 0x8007DD68: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007DD6C: jal         0x800AD970
    // 0x8007DD70: nop

    func_800AD970(rdram, ctx);
        goto after_11;
    // 0x8007DD70: nop

    after_11:
    // 0x8007DD74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DD78: lwc1        $f8, 0x315C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X315C);
    // 0x8007DD7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DD80: lwc1        $f18, 0x3160($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3160);
    // 0x8007DD84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DD88: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8007DD8C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8007DD90: swc1        $f10, 0x315C($at)
    MEM_W(0X315C, ctx->r1) = ctx->f10.u32l;
    // 0x8007DD94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007DD98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007DD9C: nop

    // 0x8007DDA0: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8007DDA4: nop

    // 0x8007DDA8: bc1t        L_8007DDC4
    if (c1cs) {
        // 0x8007DDAC: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8007DDC4;
    }
    // 0x8007DDAC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8007DDB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007DDB4: nop

    // 0x8007DDB8: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8007DDBC: nop

    // 0x8007DDC0: bc1f        L_8007DE00
    if (!c1cs) {
        // 0x8007DDC4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8007DE00;
    }
L_8007DDC4:
    // 0x8007DDC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DDC8: lwc1        $f6, 0x315C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X315C);
    // 0x8007DDCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DDD0: lwc1        $f8, 0x3160($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3160);
    // 0x8007DDD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DDD8: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8007DDDC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007DDE0: swc1        $f18, 0x315C($at)
    MEM_W(0X315C, ctx->r1) = ctx->f18.u32l;
    // 0x8007DDE4: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8007DDE8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007DDEC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8007DDF0: mul.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x8007DDF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DDF8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007DDFC: swc1        $f6, 0x3160($at)
    MEM_W(0X3160, ctx->r1) = ctx->f6.u32l;
L_8007DE00:
    // 0x8007DE00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE04: lwc1        $f18, 0x3164($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3164);
    // 0x8007DE08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE0C: lwc1        $f8, 0x3168($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3168);
    // 0x8007DE10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE14: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8007DE18: swc1        $f16, 0x3164($at)
    MEM_W(0X3164, ctx->r1) = ctx->f16.u32l;
    // 0x8007DE1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DE20: lwc1        $f5, -0x1FF8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1FF8);
    // 0x8007DE24: lwc1        $f4, -0x1FF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1FF4);
    // 0x8007DE28: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8007DE2C: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x8007DE30: nop

    // 0x8007DE34: bc1t        L_8007DE54
    if (c1cs) {
        // 0x8007DE38: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007DE54;
    }
    // 0x8007DE38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DE3C: lwc1        $f7, -0x1FF0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1FF0);
    // 0x8007DE40: lwc1        $f6, -0x1FEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1FEC);
    // 0x8007DE44: nop

    // 0x8007DE48: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x8007DE4C: nop

    // 0x8007DE50: bc1f        L_8007DE90
    if (!c1cs) {
        // 0x8007DE54: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8007DE90;
    }
L_8007DE54:
    // 0x8007DE54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE58: lwc1        $f18, 0x3164($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3164);
    // 0x8007DE5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE60: lwc1        $f8, 0x3168($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3168);
    // 0x8007DE64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE68: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8007DE6C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007DE70: swc1        $f16, 0x3164($at)
    MEM_W(0X3164, ctx->r1) = ctx->f16.u32l;
    // 0x8007DE74: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8007DE78: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007DE7C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8007DE80: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x8007DE84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE88: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8007DE8C: swc1        $f18, 0x3168($at)
    MEM_W(0X3168, ctx->r1) = ctx->f18.u32l;
L_8007DE90:
    // 0x8007DE90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE94: lwc1        $f16, 0x316C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X316C);
    // 0x8007DE98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE9C: lwc1        $f8, 0x3170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3170);
    // 0x8007DEA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DEA4: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8007DEA8: swc1        $f4, 0x316C($at)
    MEM_W(0X316C, ctx->r1) = ctx->f4.u32l;
    // 0x8007DEAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DEB0: lwc1        $f7, -0x1FE8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1FE8);
    // 0x8007DEB4: lwc1        $f6, -0x1FE4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1FE4);
    // 0x8007DEB8: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8007DEBC: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8007DEC0: nop

    // 0x8007DEC4: bc1f        L_8007DEE4
    if (!c1cs) {
        // 0x8007DEC8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007DEE4;
    }
    // 0x8007DEC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DECC: lwc1        $f19, -0x1FE0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1FE0);
    // 0x8007DED0: lwc1        $f18, -0x1FDC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1FDC);
    // 0x8007DED4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DED8: sub.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f10.d - ctx->f18.d;
    // 0x8007DEDC: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8007DEE0: swc1        $f8, 0x316C($at)
    MEM_W(0X316C, ctx->r1) = ctx->f8.u32l;
L_8007DEE4:
    // 0x8007DEE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DEE8: lwc1        $f4, 0x3174($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3174);
    // 0x8007DEEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DEF0: lwc1        $f11, -0x1FD8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1FD8);
    // 0x8007DEF4: lwc1        $f10, -0x1FD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1FD4);
    // 0x8007DEF8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007DEFC: add.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d + ctx->f10.d;
    // 0x8007DF00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DF04: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8007DF08: swc1        $f16, 0x3174($at)
    MEM_W(0X3174, ctx->r1) = ctx->f16.u32l;
    // 0x8007DF0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DF10: lwc1        $f5, -0x1FD0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1FD0);
    // 0x8007DF14: lwc1        $f4, -0x1FCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1FCC);
    // 0x8007DF18: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8007DF1C: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8007DF20: nop

    // 0x8007DF24: bc1f        L_8007DF44
    if (!c1cs) {
        // 0x8007DF28: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007DF44;
    }
    // 0x8007DF28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DF2C: lwc1        $f7, -0x1FC8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1FC8);
    // 0x8007DF30: lwc1        $f6, -0x1FC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1FC4);
    // 0x8007DF34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DF38: sub.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d - ctx->f6.d;
    // 0x8007DF3C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8007DF40: swc1        $f18, 0x3174($at)
    MEM_W(0X3174, ctx->r1) = ctx->f18.u32l;
L_8007DF44:
    // 0x8007DF44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DF48: lwc1        $f16, 0x3178($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3178);
    // 0x8007DF4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DF50: lwc1        $f4, 0x317C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X317C);
    // 0x8007DF54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DF58: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8007DF5C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007DF60: swc1        $f8, 0x3178($at)
    MEM_W(0X3178, ctx->r1) = ctx->f8.u32l;
    // 0x8007DF64: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007DF68: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007DF6C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8007DF70: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x8007DF74: nop

    // 0x8007DF78: bc1f        L_8007DF98
    if (!c1cs) {
        // 0x8007DF7C: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_8007DF98;
    }
    // 0x8007DF7C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007DF80: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007DF84: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007DF88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DF8C: sub.d       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f6.d - ctx->f18.d;
    // 0x8007DF90: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8007DF94: swc1        $f4, 0x3178($at)
    MEM_W(0X3178, ctx->r1) = ctx->f4.u32l;
L_8007DF98:
    // 0x8007DF98: jal         0x8007CC14
    // 0x8007DF9C: nop

    Math_GridMagnitude(rdram, ctx);
        goto after_12;
    // 0x8007DF9C: nop

    after_12:
    // 0x8007DFA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DFA4: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8007DFA8: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8007DFAC: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007DFB0: jr          $ra
    // 0x8007DFB4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007DFB4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8007DFB8: nop

    // 0x8007DFBC: nop

;}

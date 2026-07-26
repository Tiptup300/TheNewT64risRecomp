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

RECOMP_FUNC void Math_NormFloatToU8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0E50: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B0E54: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800B0E58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B0E5C: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x800B0E60: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800B0E64: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800B0E68: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800B0E6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B0E70: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800B0E74: bc1f        L_800B0E8C
    if (!c1cs) {
        // 0x800B0E78: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800B0E8C;
    }
    // 0x800B0E78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B0E7C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B0E80: nop

    // 0x800B0E84: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x800B0E88: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
L_800B0E8C:
    // 0x800B0E8C: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x800B0E90: nop

    // 0x800B0E94: bc1fl       L_800B0EAC
    if (!c1cs) {
        // 0x800B0E98: lw          $v1, 0x0($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X0);
            goto L_800B0EAC;
    }
    goto skip_0;
    // 0x800B0E98: lw          $v1, 0x0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X0);
    skip_0:
    // 0x800B0E9C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B0EA0: nop

    // 0x800B0EA4: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800B0EA8: lw          $v1, 0x0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X0);
L_800B0EAC:
    // 0x800B0EAC: lui         $at, 0x7F80
    ctx->r1 = S32(0X7F80 << 16);
    // 0x800B0EB0: and         $a0, $v1, $at
    ctx->r4 = ctx->r3 & ctx->r1;
    // 0x800B0EB4: sra         $t6, $a0, 23
    ctx->r14 = S32(SIGNED(ctx->r4) >> 23);
    // 0x800B0EB8: addiu       $v0, $t6, -0x7F
    ctx->r2 = ADD32(ctx->r14, -0X7F);
    // 0x800B0EBC: bne         $v0, $zero, L_800B0ECC
    if (ctx->r2 != 0) {
        // 0x800B0EC0: lui         $at, 0x7F
        ctx->r1 = S32(0X7F << 16);
            goto L_800B0ECC;
    }
    // 0x800B0EC0: lui         $at, 0x7F
    ctx->r1 = S32(0X7F << 16);
    // 0x800B0EC4: jr          $ra
    // 0x800B0EC8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x800B0EC8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800B0ECC:
    // 0x800B0ECC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B0ED0: and         $t7, $v1, $at
    ctx->r15 = ctx->r3 & ctx->r1;
    // 0x800B0ED4: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x800B0ED8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B0EDC: slti        $at, $v0, -0x8
    ctx->r1 = SIGNED(ctx->r2) < -0X8 ? 1 : 0;
    // 0x800B0EE0: beq         $at, $zero, L_800B0EF0
    if (ctx->r1 == 0) {
        // 0x800B0EE4: srl         $v1, $t8, 16
        ctx->r3 = S32(U32(ctx->r24) >> 16);
            goto L_800B0EF0;
    }
    // 0x800B0EE4: srl         $v1, $t8, 16
    ctx->r3 = S32(U32(ctx->r24) >> 16);
    // 0x800B0EE8: jr          $ra
    // 0x800B0EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B0EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B0EF0:
    // 0x800B0EF0: bgezl       $v0, L_800B0F00
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B0EF4: andi        $v0, $v1, 0xFF
        ctx->r2 = ctx->r3 & 0XFF;
            goto L_800B0F00;
    }
    goto skip_1;
    // 0x800B0EF4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    skip_1:
    // 0x800B0EF8: srlv        $v1, $v1, $v0
    ctx->r3 = S32(U32(ctx->r3) >> (ctx->r2 & 31));
    // 0x800B0EFC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
L_800B0F00:
    // 0x800B0F00: jr          $ra
    // 0x800B0F04: nop

    return;
    // 0x800B0F04: nop

;}

RECOMP_FUNC void func_800B0F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0F08: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800B0F0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B0F10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B0F14: mul.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800B0F18: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800B0F1C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B0F20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B0F24: swc1        $f12, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f12.u32l;
    // 0x800B0F28: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800B0F2C: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x800B0F30: mul.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800B0F34: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B0F38: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x800B0F3C: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x800B0F40: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x800B0F44: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x800B0F48: swc1        $f16, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f16.u32l;
    // 0x800B0F4C: mul.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800B0F50: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x800B0F54: swc1        $f16, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f16.u32l;
    // 0x800B0F58: swc1        $f16, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f16.u32l;
    // 0x800B0F5C: swc1        $f16, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f16.u32l;
    // 0x800B0F60: swc1        $f16, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f16.u32l;
    // 0x800B0F64: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
    // 0x800B0F68: swc1        $f14, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f14.u32l;
    // 0x800B0F6C: jr          $ra
    // 0x800B0F70: swc1        $f14, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x800B0F70: swc1        $f14, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f14.u32l;
;}

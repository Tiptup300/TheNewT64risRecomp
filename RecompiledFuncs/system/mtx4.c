#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mtx4_mult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF558: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF55C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF560: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF564: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF568: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF56C: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF570: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF574: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF578: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF57C: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800AF580: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF584: lwc1        $f18, 0x30($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800AF588: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF58C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AF590: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AF594: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800AF598: lwc1        $f18, 0x10($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF59C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF5A0: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF5A4: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF5A8: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AF5AC: lwc1        $f18, 0x20($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF5B0: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AF5B4: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF5B8: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AF5BC: lwc1        $f18, 0x1C($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x800AF5C0: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AF5C4: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800AF5C8: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AF5CC: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800AF5D0: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AF5D4: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x800AF5D8: lwc1        $f4, 0x20($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF5DC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF5E0: lwc1        $f8, 0x24($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF5E4: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF5E8: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AF5EC: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF5F0: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AF5F4: lwc1        $f6, 0x28($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF5F8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF5FC: lwc1        $f4, 0x2C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x800AF600: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AF604: lwc1        $f16, 0x30($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800AF608: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AF60C: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF610: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800AF614: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x800AF618: lwc1        $f16, 0x30($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AF61C: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF620: lwc1        $f6, 0x34($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AF624: lwc1        $f18, 0x10($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF628: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AF62C: lwc1        $f16, 0x20($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF630: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF634: lwc1        $f18, 0x38($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AF638: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AF63C: lwc1        $f16, 0x3C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x800AF640: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AF644: lwc1        $f10, 0x30($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800AF648: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF64C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AF650: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800AF654: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x800AF658: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF65C: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF660: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF664: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF668: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF66C: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF670: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AF674: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF678: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AF67C: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800AF680: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800AF684: lwc1        $f8, 0x34($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800AF688: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AF68C: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800AF690: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800AF694: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800AF698: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF69C: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF6A0: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF6A4: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF6A8: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AF6AC: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF6B0: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AF6B4: lwc1        $f16, 0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF6B8: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AF6BC: lwc1        $f8, 0x1C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x800AF6C0: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800AF6C4: lwc1        $f6, 0x34($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800AF6C8: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AF6CC: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AF6D0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF6D4: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800AF6D8: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF6DC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF6E0: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF6E4: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF6E8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF6EC: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF6F0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF6F4: lwc1        $f10, 0x28($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF6F8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF6FC: lwc1        $f6, 0x2C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x800AF700: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF704: lwc1        $f18, 0x34($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800AF708: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF70C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AF710: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AF714: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x800AF718: lwc1        $f18, 0x30($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AF71C: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF720: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AF724: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF728: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AF72C: lwc1        $f18, 0x24($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF730: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AF734: lwc1        $f8, 0x38($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AF738: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AF73C: lwc1        $f18, 0x3C($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x800AF740: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AF744: lwc1        $f4, 0x34($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800AF748: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AF74C: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800AF750: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AF754: swc1        $f16, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f16.u32l;
    // 0x800AF758: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF75C: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF760: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF764: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF768: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AF76C: lwc1        $f4, 0x28($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF770: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AF774: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF778: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF77C: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800AF780: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AF784: lwc1        $f16, 0x38($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800AF788: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AF78C: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF790: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800AF794: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800AF798: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF79C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF7A0: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF7A4: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF7A8: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AF7AC: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF7B0: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF7B4: lwc1        $f18, 0x18($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF7B8: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AF7BC: lwc1        $f16, 0x1C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x800AF7C0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AF7C4: lwc1        $f10, 0x38($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800AF7C8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF7CC: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AF7D0: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800AF7D4: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x800AF7D8: lwc1        $f10, 0x20($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF7DC: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF7E0: lwc1        $f18, 0x24($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF7E4: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF7E8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF7EC: lwc1        $f10, 0x28($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF7F0: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AF7F4: lwc1        $f4, 0x28($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF7F8: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AF7FC: lwc1        $f10, 0x2C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x800AF800: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800AF804: lwc1        $f8, 0x38($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800AF808: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AF80C: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800AF810: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800AF814: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x800AF818: lwc1        $f8, 0x30($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AF81C: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF820: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AF824: lwc1        $f16, 0x18($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF828: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AF82C: lwc1        $f8, 0x28($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF830: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AF834: lwc1        $f16, 0x38($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AF838: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AF83C: lwc1        $f8, 0x3C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x800AF840: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800AF844: lwc1        $f6, 0x38($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800AF848: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AF84C: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AF850: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF854: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
    // 0x800AF858: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800AF85C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF860: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800AF864: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF868: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF86C: lwc1        $f6, 0x2C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AF870: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF874: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF878: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF87C: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800AF880: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF884: lwc1        $f18, 0x3C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x800AF888: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF88C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AF890: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AF894: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800AF898: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800AF89C: lwc1        $f18, 0x10($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF8A0: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800AF8A4: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF8A8: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AF8AC: lwc1        $f18, 0x2C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AF8B0: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AF8B4: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF8B8: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AF8BC: lwc1        $f18, 0x1C($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x800AF8C0: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AF8C4: lwc1        $f4, 0x3C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x800AF8C8: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AF8CC: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800AF8D0: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AF8D4: swc1        $f16, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f16.u32l;
    // 0x800AF8D8: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800AF8DC: lwc1        $f4, 0x20($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF8E0: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800AF8E4: lwc1        $f8, 0x24($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF8E8: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AF8EC: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AF8F0: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AF8F4: lwc1        $f6, 0x28($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF8F8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF8FC: lwc1        $f4, 0x2C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x800AF900: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AF904: lwc1        $f16, 0x3C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x800AF908: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AF90C: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF910: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800AF914: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
    // 0x800AF918: lwc1        $f16, 0x30($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AF91C: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800AF920: lwc1        $f6, 0x34($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AF924: lwc1        $f18, 0x1C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800AF928: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AF92C: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AF930: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF934: lwc1        $f18, 0x38($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AF938: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AF93C: lwc1        $f16, 0x3C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x800AF940: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AF944: lwc1        $f10, 0x3C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x800AF948: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF94C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AF950: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800AF954: jr          $ra
    // 0x800AF958: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800AF958: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
;}

RECOMP_FUNC void func_800AF95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF95C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF960: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF964: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF968: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800AF96C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF970: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF974: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF978: lwc1        $f10, 0x18($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF97C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF980: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF984: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AF988: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800AF98C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF990: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF994: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF998: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF99C: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF9A0: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF9A4: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AF9A8: lwc1        $f4, 0x1C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x800AF9AC: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AF9B0: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF9B4: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AF9B8: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800AF9BC: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF9C0: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF9C4: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF9C8: lwc1        $f18, 0x10($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF9CC: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AF9D0: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF9D4: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF9D8: lwc1        $f18, 0x20($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF9DC: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AF9E0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AF9E4: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AF9E8: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800AF9EC: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF9F0: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF9F4: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800AF9F8: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF9FC: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AFA00: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AFA04: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AFA08: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AFA0C: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AFA10: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AFA14: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AFA18: swc1        $f18, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f18.u32l;
    // 0x800AFA1C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AFA20: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AFA24: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AFA28: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AFA2C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AFA30: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AFA34: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AFA38: lwc1        $f10, 0x1C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x800AFA3C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AFA40: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AFA44: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AFA48: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x800AFA4C: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AFA50: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AFA54: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AFA58: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AFA5C: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AFA60: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AFA64: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AFA68: lwc1        $f4, 0x20($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AFA6C: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AFA70: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AFA74: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AFA78: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800AFA7C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AFA80: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AFA84: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AFA88: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800AFA8C: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AFA90: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AFA94: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AFA98: lwc1        $f18, 0x18($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AFA9C: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AFAA0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AFAA4: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AFAA8: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x800AFAAC: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AFAB0: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AFAB4: lwc1        $f8, 0x18($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AFAB8: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AFABC: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AFAC0: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AFAC4: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AFAC8: lwc1        $f8, 0x1C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x800AFACC: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AFAD0: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AFAD4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AFAD8: swc1        $f18, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f18.u32l;
    // 0x800AFADC: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AFAE0: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AFAE4: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AFAE8: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AFAEC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AFAF0: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AFAF4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AFAF8: lwc1        $f10, 0x20($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AFAFC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AFB00: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AFB04: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AFB08: jr          $ra
    // 0x800AFB0C: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800AFB0C: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
;}

RECOMP_FUNC void mtx4_mult_point3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFB10: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AFB14: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AFB18: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AFB1C: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AFB20: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AFB24: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AFB28: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AFB2C: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AFB30: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AFB34: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AFB38: lwc1        $f18, 0x30($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800AFB3C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AFB40: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AFB44: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800AFB48: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AFB4C: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AFB50: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AFB54: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AFB58: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AFB5C: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AFB60: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800AFB64: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AFB68: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800AFB6C: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800AFB70: lwc1        $f6, 0x34($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800AFB74: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800AFB78: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800AFB7C: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x800AFB80: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AFB84: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AFB88: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AFB8C: lwc1        $f16, 0x18($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AFB90: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AFB94: lwc1        $f10, 0x28($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AFB98: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AFB9C: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AFBA0: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AFBA4: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AFBA8: lwc1        $f4, 0x38($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800AFBAC: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AFBB0: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AFBB4: jr          $ra
    // 0x800AFBB8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x800AFBB8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
;}

RECOMP_FUNC void mtx4_mult_vec3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFBBC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AFBC0: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AFBC4: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AFBC8: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AFBCC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AFBD0: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AFBD4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AFBD8: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AFBDC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AFBE0: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AFBE4: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AFBE8: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800AFBEC: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AFBF0: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AFBF4: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AFBF8: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AFBFC: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AFC00: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AFC04: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AFC08: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AFC0C: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AFC10: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AFC14: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AFC18: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800AFC1C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AFC20: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AFC24: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AFC28: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AFC2C: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AFC30: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AFC34: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AFC38: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AFC3C: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AFC40: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AFC44: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AFC48: jr          $ra
    // 0x800AFC4C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800AFC4C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
;}

RECOMP_FUNC void mtx4_print(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFD1C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AFD20: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800AFD24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AFD28: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800AFD2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AFD30: jal         0x800B3BFC
    // 0x800AFD34: addiu       $a0, $a0, 0x1200
    ctx->r4 = ADD32(ctx->r4, 0X1200);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800AFD34: addiu       $a0, $a0, 0x1200
    ctx->r4 = ADD32(ctx->r4, 0X1200);
    after_0:
    // 0x800AFD38: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AFD3C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800AFD40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AFD44: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800AFD48: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800AFD4C: sdc1        $f10, 0x10($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X10, ctx->r29);
    // 0x800AFD50: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800AFD54: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800AFD58: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x800AFD5C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800AFD60: addiu       $a0, $a0, 0x1204
    ctx->r4 = ADD32(ctx->r4, 0X1204);
    // 0x800AFD64: sdc1        $f18, 0x18($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X18, ctx->r29);
    // 0x800AFD68: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800AFD6C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800AFD70: jal         0x800B3BFC
    // 0x800AFD74: sdc1        $f6, 0x20($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X20, ctx->r29);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800AFD74: sdc1        $f6, 0x20($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X20, ctx->r29);
    after_1:
    // 0x800AFD78: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800AFD7C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800AFD80: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AFD84: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800AFD88: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800AFD8C: sdc1        $f18, 0x10($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X10, ctx->r29);
    // 0x800AFD90: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800AFD94: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800AFD98: mfc1        $a2, $f11
    ctx->r6 = (int32_t)ctx->f_odd[(11 - 1) * 2];
    // 0x800AFD9C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800AFDA0: addiu       $a0, $a0, 0x1230
    ctx->r4 = ADD32(ctx->r4, 0X1230);
    // 0x800AFDA4: sdc1        $f6, 0x18($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X18, ctx->r29);
    // 0x800AFDA8: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800AFDAC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800AFDB0: jal         0x800B3BFC
    // 0x800AFDB4: sdc1        $f10, 0x20($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X20, ctx->r29);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800AFDB4: sdc1        $f10, 0x20($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X20, ctx->r29);
    after_2:
    // 0x800AFDB8: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800AFDBC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AFDC0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AFDC4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800AFDC8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800AFDCC: sdc1        $f6, 0x10($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X10, ctx->r29);
    // 0x800AFDD0: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800AFDD4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800AFDD8: mfc1        $a2, $f19
    ctx->r6 = (int32_t)ctx->f_odd[(19 - 1) * 2];
    // 0x800AFDDC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800AFDE0: addiu       $a0, $a0, 0x125C
    ctx->r4 = ADD32(ctx->r4, 0X125C);
    // 0x800AFDE4: sdc1        $f10, 0x18($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X18, ctx->r29);
    // 0x800AFDE8: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800AFDEC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800AFDF0: jal         0x800B3BFC
    // 0x800AFDF4: sdc1        $f18, 0x20($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X20, ctx->r29);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x800AFDF4: sdc1        $f18, 0x20($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X20, ctx->r29);
    after_3:
    // 0x800AFDF8: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800AFDFC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AFE00: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AFE04: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800AFE08: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800AFE0C: sdc1        $f10, 0x10($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X10, ctx->r29);
    // 0x800AFE10: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800AFE14: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800AFE18: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x800AFE1C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800AFE20: addiu       $a0, $a0, 0x1288
    ctx->r4 = ADD32(ctx->r4, 0X1288);
    // 0x800AFE24: sdc1        $f18, 0x18($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X18, ctx->r29);
    // 0x800AFE28: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800AFE2C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800AFE30: jal         0x800B3BFC
    // 0x800AFE34: sdc1        $f6, 0x20($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X20, ctx->r29);
    rmonPrintf_recomp(rdram, ctx);
        goto after_4;
    // 0x800AFE34: sdc1        $f6, 0x20($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X20, ctx->r29);
    after_4:
    // 0x800AFE38: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800AFE3C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800AFE40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800AFE44: jr          $ra
    // 0x800AFE48: nop

    return;
    // 0x800AFE48: nop

;}

RECOMP_FUNC void mtx4_from_fixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFE4C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800AFE50: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AFE54: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800AFE58: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800AFE5C: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x800AFE60: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800AFE64: addiu       $a3, $a0, 0x8
    ctx->r7 = ADD32(ctx->r4, 0X8);
    // 0x800AFE68: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800AFE6C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800AFE70: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800AFE74: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
    // 0x800AFE78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800AFE7C:
    // 0x800AFE7C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800AFE80: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800AFE84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AFE88: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x800AFE8C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800AFE90: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x800AFE94: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800AFE98: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800AFE9C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AFEA0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AFEA4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x800AFEA8: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800AFEAC: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x800AFEB0: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800AFEB4: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x800AFEB8: or          $t1, $t9, $t6
    ctx->r9 = ctx->r25 | ctx->r14;
    // 0x800AFEBC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AFEC0: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800AFEC4: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800AFEC8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AFECC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AFED0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AFED4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800AFED8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800AFEDC: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800AFEE0: div.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800AFEE4: swc1        $f18, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->f18.u32l;
    // 0x800AFEE8: bne         $a0, $t3, L_800AFE7C
    if (ctx->r4 != ctx->r11) {
        // 0x800AFEEC: swc1        $f16, -0x8($a3)
        MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
            goto L_800AFE7C;
    }
    // 0x800AFEEC: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x800AFEF0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800AFEF4: bnel        $t0, $t4, L_800AFE7C
    if (ctx->r8 != ctx->r12) {
        // 0x800AFEF8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800AFE7C;
    }
    goto skip_0;
    // 0x800AFEF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x800AFEFC: jr          $ra
    // 0x800AFF00: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800AFF00: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void mtx4_rotate_axis(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0140: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800B0144: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800B0148: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B014C: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800B0150: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B0154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0158: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x800B015C: mul.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800B0160: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x800B0164: jal         0x800B81D0
    // 0x800B0168: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B0168: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x800B016C: swc1        $f0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f0.u32l;
    // 0x800B0170: jal         0x800B7B40
    // 0x800B0174: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800B0174: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x800B0178: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
    // 0x800B017C: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x800B0180: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B0184: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B0188: swc1        $f8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f8.u32l;
    // 0x800B018C: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800B0190: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800B0194: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800B0198: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x800B019C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800B01A0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B01A4: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800B01A8: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800B01AC: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800B01B0: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x800B01B4: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800B01B8: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x800B01BC: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800B01C0: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800B01C4: mul.s       $f10, $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800B01C8: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B01CC: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x800B01D0: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x800B01D4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B01D8: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x800B01DC: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B01E0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800B01E4: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800B01E8: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800B01EC: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x800B01F0: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x800B01F4: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x800B01F8: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800B01FC: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800B0200: add.d       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = ctx->f12.d + ctx->f12.d;
    // 0x800B0204: mul.d       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x800B0208: cvt.d.s     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f14.d = CVT_D_S(ctx->f6.fl);
    // 0x800B020C: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x800B0210: add.d       $f20, $f14, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f14.d); 
    ctx->f20.d = ctx->f14.d + ctx->f14.d;
    // 0x800B0214: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x800B0218: mul.d       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f20.d, ctx->f2.d);
    // 0x800B021C: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x800B0220: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x800B0224: mul.d       $f10, $f20, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f20.d, ctx->f0.d);
    // 0x800B0228: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B022C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800B0230: mul.d       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x800B0234: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x800B0238: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x800B023C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800B0240: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x800B0244: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B0248: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x800B024C: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x800B0250: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B0254: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B0258: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B025C: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800B0260: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B0264: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B0268: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B026C: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800B0270: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B0274: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B0278: mul.d       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f14.d);
    // 0x800B027C: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x800B0280: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800B0284: mul.d       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f2.d);
    // 0x800B0288: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x800B028C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800B0290: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x800B0294: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x800B0298: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800B029C: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x800B02A0: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x800B02A4: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B02A8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B02AC: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800B02B0: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800B02B4: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B02B8: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B02BC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B02C0: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x800B02C4: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B02C8: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800B02CC: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B02D0: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800B02D4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800B02D8: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x800B02DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B02E0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800B02E4: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // 0x800B02E8: jr          $ra
    // 0x800B02EC: nop

    return;
    // 0x800B02EC: nop

;}

RECOMP_FUNC void mtx4_from_axis(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B02F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B02F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B02F8: lw          $at, 0x0($a1)
    ctx->r1 = MEM_W(ctx->r5, 0X0);
    // 0x800B02FC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800B0300: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800B0304: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x800B0308: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x800B030C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800B0310: lw          $at, 0x8($a1)
    ctx->r1 = MEM_W(ctx->r5, 0X8);
    // 0x800B0314: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x800B0318: jal         0x800B0040
    // 0x800B031C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    vec3_normalize(rdram, ctx);
        goto after_0;
    // 0x800B031C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x800B0320: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B0324: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B0328: jal         0x800B0140
    // 0x800B032C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    mtx4_rotate_axis(rdram, ctx);
        goto after_1;
    // 0x800B032C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x800B0330: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800B0334: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B0338: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B033C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B0340: swc1        $f0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f0.u32l;
    // 0x800B0344: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
    // 0x800B0348: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
    // 0x800B034C: swc1        $f0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f0.u32l;
    // 0x800B0350: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x800B0354: swc1        $f0, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f0.u32l;
    // 0x800B0358: swc1        $f4, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f4.u32l;
    // 0x800B035C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B0360: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B0364: jr          $ra
    // 0x800B0368: nop

    return;
    // 0x800B0368: nop

;}

RECOMP_FUNC void mtx4_rotate_euler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B036C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800B0370: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0374: ldc1        $f0, 0x12D0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X12D0);
    // 0x800B0378: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800B037C: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800B0380: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B0384: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800B0388: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800B038C: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800B0390: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x800B0394: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B0398: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800B039C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B03A0: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x800B03A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B03A8: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x800B03AC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800B03B0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800B03B4: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x800B03B8: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    // 0x800B03BC: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
    // 0x800B03C0: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    // 0x800B03C4: jal         0x800B81D0
    // 0x800B03C8: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B03C8: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x800B03CC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800B03D0: jal         0x800B81D0
    // 0x800B03D4: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800B03D4: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x800B03D8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800B03DC: jal         0x800B81D0
    // 0x800B03E0: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x800B03E0: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_2:
    // 0x800B03E4: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B03E8: jal         0x800B7B40
    // 0x800B03EC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B03EC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800B03F0: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B03F4: jal         0x800B7B40
    // 0x800B03F8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x800B03F8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800B03FC: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B0400: jal         0x800B7B40
    // 0x800B0404: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x800B0404: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800B0408: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B040C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0410: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800B0414: neg.s       $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = -ctx->f20.fl;
    // 0x800B0418: mul.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800B041C: nop

    // 0x800B0420: mul.s       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800B0424: nop

    // 0x800B0428: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800B042C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B0430: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800B0434: nop

    // 0x800B0438: mul.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800B043C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800B0440: mul.s       $f10, $f14, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x800B0444: nop

    // 0x800B0448: mul.s       $f18, $f22, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800B044C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B0450: mul.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800B0454: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x800B0458: mul.s       $f12, $f20, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x800B045C: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x800B0460: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x800B0464: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
    // 0x800B0468: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x800B046C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800B0470: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800B0474: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x800B0478: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800B047C: nop

    // 0x800B0480: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800B0484: nop

    // 0x800B0488: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800B048C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800B0490: mul.s       $f18, $f20, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800B0494: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x800B0498: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B049C: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
    // 0x800B04A0: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x800B04A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B04A8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B04AC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800B04B0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800B04B4: jr          $ra
    // 0x800B04B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800B04B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void mtx4_from_euler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B04BC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800B04C0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800B04C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B04C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B04CC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800B04D0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800B04D4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800B04D8: jal         0x800B036C
    // 0x800B04DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mtx4_rotate_euler(rdram, ctx);
        goto after_0;
    // 0x800B04DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800B04E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B04E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B04E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B04EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B04F0: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x800B04F4: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x800B04F8: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x800B04FC: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800B0500: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x800B0504: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x800B0508: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x800B050C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B0510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B0514: jr          $ra
    // 0x800B0518: nop

    return;
    // 0x800B0518: nop

;}

RECOMP_FUNC void mtx4_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B051C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800B0520: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800B0524: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B0528: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800B052C: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B0530: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800B0534: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800B0538: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B053C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800B0540: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B0544: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800B0548: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800B054C: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800B0550: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800B0554: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800B0558: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800B055C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800B0560: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x800B0564: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800B0568: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x800B056C: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800B0570: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800B0574: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800B0578: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800B057C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B0580: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B0584: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x800B0588: lwc1        $f16, 0xC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800B058C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B0590: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x800B0594: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800B0598: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B059C: jr          $ra
    // 0x800B05A0: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800B05A0: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
;}

RECOMP_FUNC void mtx4_get_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B05A4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B05A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B05AC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B05B0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800B05B4: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800B05B8: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800B05BC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800B05C0: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B05C4: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800B05C8: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B05CC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800B05D0: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800B05D4: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B05D8: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800B05DC: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800B05E0: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B05E4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x800B05E8: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800B05EC: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B05F0: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B05F4: sqrt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = sqrtf(ctx->f2.fl);
    // 0x800B05F8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800B05FC: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800B0600: swc1        $f8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f8.u32l;
    // 0x800B0604: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800B0608: lwc1        $f16, 0x20($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800B060C: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800B0610: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800B0614: nop

    // 0x800B0618: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800B061C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B0620: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800B0624: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800B0628: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B062C: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x800B0630: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800B0634: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800B0638: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B063C: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800B0640: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800B0644: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800B0648: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800B064C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B0650: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B0654: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800B0658: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    // 0x800B065C: div.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f6.d);
    // 0x800B0660: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B0664: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B0668: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800B066C: sqrt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = sqrtf(ctx->f14.fl);
    // 0x800B0670: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x800B0674: div.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f6.d);
    // 0x800B0678: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B067C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B0680: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800B0684: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x800B0688: div.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f6.d);
    // 0x800B068C: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800B0690: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800B0694: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B0698: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x800B069C: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800B06A0: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x800B06A4: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800B06A8: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800B06AC: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x800B06B0: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800B06B4: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800B06B8: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x800B06BC: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800B06C0: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800B06C4: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800B06C8: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x800B06CC: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800B06D0: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800B06D4: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800B06D8: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800B06DC: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B06E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B06E4: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x800B06E8: mul.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800B06EC: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x800B06F0: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800B06F4: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x800B06F8: jr          $ra
    // 0x800B06FC: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800B06FC: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
;}

RECOMP_FUNC void mtx4_look_at(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0700: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B0704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0708: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B070C: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800B0710: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800B0714: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B0718: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800B071C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B0720: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800B0724: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800B0728: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800B072C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800B0730: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x800B0734: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800B0738: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B073C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800B0740: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B0744: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B0748: jal         0x800AFF04
    // 0x800B074C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    vec3_dot(rdram, ctx);
        goto after_0;
    // 0x800B074C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800B0750: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0754: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800B0758: jal         0x800AFF04
    // 0x800B075C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    vec3_dot(rdram, ctx);
        goto after_1;
    // 0x800B075C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800B0760: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800B0764: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0768: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B076C: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800B0770: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B0774: add.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B0778: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800B077C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800B0780: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800B0784: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800B0788: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800B078C: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800B0790: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800B0794: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B0798: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x800B079C: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800B07A0: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800B07A4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800B07A8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B07AC: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x800B07B0: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800B07B4: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800B07B8: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
    // 0x800B07BC: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800B07C0: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B07C4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800B07C8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B07CC: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x800B07D0: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800B07D4: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800B07D8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800B07DC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B07E0: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800B07E4: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800B07E8: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800B07EC: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800B07F0: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800B07F4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800B07F8: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x800B07FC: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800B0800: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800B0804: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    // 0x800B0808: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800B080C: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B0810: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800B0814: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800B0818: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x800B081C: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800B0820: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800B0824: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800B0828: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B082C: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x800B0830: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800B0834: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800B0838: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800B083C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B0840: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800B0844: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x800B0848: lwc1        $f16, 0x8($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800B084C: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800B0850: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    // 0x800B0854: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B0858: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800B085C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800B0860: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800B0864: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800B0868: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800B086C: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800B0870: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x800B0874: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800B0878: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x800B087C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0880: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0884: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800B0888: jr          $ra
    // 0x800B088C: nop

    return;
    // 0x800B088C: nop

;}

RECOMP_FUNC void mtx4_from_vectors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0D9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B0DA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0DA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B0DA8: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800B0DAC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800B0DB0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B0DB4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800B0DB8: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800B0DBC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800B0DC0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800B0DC4: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B0DC8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B0DCC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800B0DD0: jal         0x800AFF34
    // 0x800B0DD4: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    vec3_cross(rdram, ctx);
        goto after_0;
    // 0x800B0DD4: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800B0DD8: jal         0x800B0040
    // 0x800B0DDC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    vec3_normalize(rdram, ctx);
        goto after_1;
    // 0x800B0DDC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x800B0DE0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800B0DE4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800B0DE8: jal         0x800AFF34
    // 0x800B0DEC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    vec3_cross(rdram, ctx);
        goto after_2;
    // 0x800B0DEC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800B0DF0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B0DF4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B0DF8: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x800B0DFC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B0E00: swc1        $f16, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f16.u32l;
    // 0x800B0E04: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800B0E08: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
    // 0x800B0E0C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800B0E10: swc1        $f4, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f4.u32l;
    // 0x800B0E14: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800B0E18: swc1        $f6, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f6.u32l;
    // 0x800B0E1C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B0E20: swc1        $f8, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f8.u32l;
    // 0x800B0E24: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800B0E28: swc1        $f10, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f10.u32l;
    // 0x800B0E2C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B0E30: swc1        $f16, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f16.u32l;
    // 0x800B0E34: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B0E38: swc1        $f18, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f18.u32l;
    // 0x800B0E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0E40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0E44: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800B0E48: jr          $ra
    // 0x800B0E4C: nop

    return;
    // 0x800B0E4C: nop

;}

RECOMP_FUNC void func_800B0E50(uint8_t* rdram, recomp_context* ctx) {
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

RECOMP_FUNC void mtx4_mult_vec4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0F74: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B0F78: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800B0F7C: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800B0F80: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800B0F84: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B0F88: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800B0F8C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B0F90: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B0F94: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800B0F98: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800B0F9C: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800B0FA0: lwc1        $f18, 0x30($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800B0FA4: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800B0FA8: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800B0FAC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B0FB0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800B0FB4: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800B0FB8: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800B0FBC: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800B0FC0: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800B0FC4: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800B0FC8: lwc1        $f18, 0x24($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800B0FCC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B0FD0: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B0FD4: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800B0FD8: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800B0FDC: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B0FE0: lwc1        $f4, 0x34($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800B0FE4: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800B0FE8: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800B0FEC: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B0FF0: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x800B0FF4: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800B0FF8: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800B0FFC: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800B1000: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800B1004: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800B1008: lwc1        $f4, 0x28($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800B100C: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B1010: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B1014: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B1018: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800B101C: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800B1020: lwc1        $f16, 0x38($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800B1024: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800B1028: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B102C: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800B1030: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800B1034: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800B1038: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800B103C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800B1040: lwc1        $f18, 0x1C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800B1044: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800B1048: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800B104C: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800B1050: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B1054: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800B1058: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800B105C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800B1060: lwc1        $f10, 0x3C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x800B1064: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B1068: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B106C: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800B1070: jr          $ra
    // 0x800B1074: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800B1074: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
;}

RECOMP_FUNC void vec4_dot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1078: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B107C: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B1080: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800B1084: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800B1088: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B108C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B1090: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B1094: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800B1098: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800B109C: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800B10A0: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800B10A4: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B10A8: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800B10AC: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800B10B0: jr          $ra
    // 0x800B10B4: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    return;
    // 0x800B10B4: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B10B8: nop

    // 0x800B10BC: nop

;}

RECOMP_FUNC void func_800B10C0(uint8_t* rdram, recomp_context* ctx) {
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
    func_800B10C0(rdram, ctx);
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

RECOMP_FUNC void func_800B1770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1770: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800B1774: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B1778: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B177C: andi        $t0, $v0, 0x800
    ctx->r8 = ctx->r2 & 0X800;
    // 0x800B1780: xor         $t8, $t6, $at
    ctx->r24 = ctx->r14 ^ ctx->r1;
    // 0x800B1784: and         $t9, $t8, $v0
    ctx->r25 = ctx->r24 & ctx->r2;
    // 0x800B1788: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x800B178C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800B1790: beq         $t0, $zero, L_800B17A8
    if (ctx->r8 == 0) {
        // 0x800B1794: sw          $t6, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r14;
            goto L_800B17A8;
    }
    // 0x800B1794: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800B1798: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800B179C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B17A0: b           L_800B17AC
    // 0x800B17A4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
        goto L_800B17AC;
    // 0x800B17A4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
L_800B17A8:
    // 0x800B17A8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
L_800B17AC:
    // 0x800B17AC: andi        $t3, $v0, 0x400
    ctx->r11 = ctx->r2 & 0X400;
    // 0x800B17B0: beq         $t3, $zero, L_800B17C8
    if (ctx->r11 == 0) {
        // 0x800B17B4: andi        $t6, $v0, 0x100
        ctx->r14 = ctx->r2 & 0X100;
            goto L_800B17C8;
    }
    // 0x800B17B4: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x800B17B8: lw          $t4, 0x10($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X10);
    // 0x800B17BC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B17C0: b           L_800B17CC
    // 0x800B17C4: sw          $t5, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r13;
        goto L_800B17CC;
    // 0x800B17C4: sw          $t5, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r13;
L_800B17C8:
    // 0x800B17C8: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
L_800B17CC:
    // 0x800B17CC: beq         $t6, $zero, L_800B17E4
    if (ctx->r14 == 0) {
        // 0x800B17D0: andi        $t9, $v0, 0x200
        ctx->r25 = ctx->r2 & 0X200;
            goto L_800B17E4;
    }
    // 0x800B17D0: andi        $t9, $v0, 0x200
    ctx->r25 = ctx->r2 & 0X200;
    // 0x800B17D4: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x800B17D8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B17DC: b           L_800B17E8
    // 0x800B17E0: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
        goto L_800B17E8;
    // 0x800B17E0: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
L_800B17E4:
    // 0x800B17E4: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
L_800B17E8:
    // 0x800B17E8: beq         $t9, $zero, L_800B1800
    if (ctx->r25 == 0) {
        // 0x800B17EC: andi        $t2, $v0, 0x8
        ctx->r10 = ctx->r2 & 0X8;
            goto L_800B1800;
    }
    // 0x800B17EC: andi        $t2, $v0, 0x8
    ctx->r10 = ctx->r2 & 0X8;
    // 0x800B17F0: lw          $t0, 0x18($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X18);
    // 0x800B17F4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B17F8: b           L_800B1804
    // 0x800B17FC: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
        goto L_800B1804;
    // 0x800B17FC: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
L_800B1800:
    // 0x800B1800: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
L_800B1804:
    // 0x800B1804: beq         $t2, $zero, L_800B181C
    if (ctx->r10 == 0) {
        // 0x800B1808: andi        $t5, $v0, 0x4
        ctx->r13 = ctx->r2 & 0X4;
            goto L_800B181C;
    }
    // 0x800B1808: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x800B180C: lw          $t3, 0x1C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1C);
    // 0x800B1810: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B1814: b           L_800B1820
    // 0x800B1818: sw          $t4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r12;
        goto L_800B1820;
    // 0x800B1818: sw          $t4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r12;
L_800B181C:
    // 0x800B181C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
L_800B1820:
    // 0x800B1820: beq         $t5, $zero, L_800B1838
    if (ctx->r13 == 0) {
        // 0x800B1824: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_800B1838;
    }
    // 0x800B1824: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800B1828: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x800B182C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B1830: b           L_800B183C
    // 0x800B1834: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
        goto L_800B183C;
    // 0x800B1834: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
L_800B1838:
    // 0x800B1838: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
L_800B183C:
    // 0x800B183C: beq         $t8, $zero, L_800B1854
    if (ctx->r24 == 0) {
        // 0x800B1840: andi        $t1, $v0, 0x2
        ctx->r9 = ctx->r2 & 0X2;
            goto L_800B1854;
    }
    // 0x800B1840: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    // 0x800B1844: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x800B1848: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B184C: b           L_800B1858
    // 0x800B1850: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
        goto L_800B1858;
    // 0x800B1850: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
L_800B1854:
    // 0x800B1854: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
L_800B1858:
    // 0x800B1858: beq         $t1, $zero, L_800B1870
    if (ctx->r9 == 0) {
        // 0x800B185C: andi        $t4, $v0, 0x20
        ctx->r12 = ctx->r2 & 0X20;
            goto L_800B1870;
    }
    // 0x800B185C: andi        $t4, $v0, 0x20
    ctx->r12 = ctx->r2 & 0X20;
    // 0x800B1860: lw          $t2, 0x28($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X28);
    // 0x800B1864: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B1868: b           L_800B1874
    // 0x800B186C: sw          $t3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r11;
        goto L_800B1874;
    // 0x800B186C: sw          $t3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r11;
L_800B1870:
    // 0x800B1870: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
L_800B1874:
    // 0x800B1874: beq         $t4, $zero, L_800B188C
    if (ctx->r12 == 0) {
        // 0x800B1878: andi        $t7, $v0, 0x10
        ctx->r15 = ctx->r2 & 0X10;
            goto L_800B188C;
    }
    // 0x800B1878: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
    // 0x800B187C: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x800B1880: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800B1884: b           L_800B1890
    // 0x800B1888: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
        goto L_800B1890;
    // 0x800B1888: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
L_800B188C:
    // 0x800B188C: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
L_800B1890:
    // 0x800B1890: beq         $t7, $zero, L_800B18A8
    if (ctx->r15 == 0) {
        // 0x800B1894: andi        $t0, $v0, 0x2000
        ctx->r8 = ctx->r2 & 0X2000;
            goto L_800B18A8;
    }
    // 0x800B1894: andi        $t0, $v0, 0x2000
    ctx->r8 = ctx->r2 & 0X2000;
    // 0x800B1898: lw          $t8, 0x30($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X30);
    // 0x800B189C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B18A0: b           L_800B18AC
    // 0x800B18A4: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
        goto L_800B18AC;
    // 0x800B18A4: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
L_800B18A8:
    // 0x800B18A8: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
L_800B18AC:
    // 0x800B18AC: beq         $t0, $zero, L_800B18C4
    if (ctx->r8 == 0) {
        // 0x800B18B0: andi        $t3, $v0, 0x1000
        ctx->r11 = ctx->r2 & 0X1000;
            goto L_800B18C4;
    }
    // 0x800B18B0: andi        $t3, $v0, 0x1000
    ctx->r11 = ctx->r2 & 0X1000;
    // 0x800B18B4: lw          $t1, 0x34($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X34);
    // 0x800B18B8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B18BC: b           L_800B18C8
    // 0x800B18C0: sw          $t2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r10;
        goto L_800B18C8;
    // 0x800B18C0: sw          $t2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r10;
L_800B18C4:
    // 0x800B18C4: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
L_800B18C8:
    // 0x800B18C8: beq         $t3, $zero, L_800B18EC
    if (ctx->r11 == 0) {
        // 0x800B18CC: andi        $t8, $v0, 0x8000
        ctx->r24 = ctx->r2 & 0X8000;
            goto L_800B18EC;
    }
    // 0x800B18CC: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    // 0x800B18D0: lw          $t4, 0x38($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X38);
    // 0x800B18D4: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800B18D8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B18DC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B18E0: sw          $t5, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r13;
    // 0x800B18E4: b           L_800B18F4
    // 0x800B18E8: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
        goto L_800B18F4;
    // 0x800B18E8: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
L_800B18EC:
    // 0x800B18EC: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x800B18F0: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
L_800B18F4:
    // 0x800B18F4: beq         $t8, $zero, L_800B190C
    if (ctx->r24 == 0) {
        // 0x800B18F8: andi        $t1, $v0, 0x4000
        ctx->r9 = ctx->r2 & 0X4000;
            goto L_800B190C;
    }
    // 0x800B18F8: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x800B18FC: lw          $t9, 0x40($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X40);
    // 0x800B1900: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B1904: b           L_800B1910
    // 0x800B1908: sw          $t0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r8;
        goto L_800B1910;
    // 0x800B1908: sw          $t0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r8;
L_800B190C:
    // 0x800B190C: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
L_800B1910:
    // 0x800B1910: beql        $t1, $zero, L_800B192C
    if (ctx->r9 == 0) {
        // 0x800B1914: sw          $zero, 0x44($a0)
        MEM_W(0X44, ctx->r4) = 0;
            goto L_800B192C;
    }
    goto skip_0;
    // 0x800B1914: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
    skip_0:
    // 0x800B1918: lw          $t2, 0x44($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X44);
    // 0x800B191C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B1920: b           L_800B192C
    // 0x800B1924: sw          $t3, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r11;
        goto L_800B192C;
    // 0x800B1924: sw          $t3, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r11;
    // 0x800B1928: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
L_800B192C:
    // 0x800B192C: lb          $t4, 0x2($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X2);
    // 0x800B1930: sh          $t4, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r12;
    // 0x800B1934: lh          $v1, 0x4C($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4C);
    // 0x800B1938: lb          $t5, 0x3($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X3);
    // 0x800B193C: bltz        $v1, L_800B194C
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B1940: sh          $t5, 0x4E($a0)
        MEM_H(0X4E, ctx->r4) = ctx->r13;
            goto L_800B194C;
    }
    // 0x800B1940: sh          $t5, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r13;
    // 0x800B1944: b           L_800B1950
    // 0x800B1948: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B1950;
    // 0x800B1948: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B194C:
    // 0x800B194C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_800B1950:
    // 0x800B1950: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x800B1954: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B1958: beql        $at, $zero, L_800B1968
    if (ctx->r1 == 0) {
        // 0x800B195C: lh          $v1, 0x4E($a0)
        ctx->r3 = MEM_H(ctx->r4, 0X4E);
            goto L_800B1968;
    }
    goto skip_1;
    // 0x800B195C: lh          $v1, 0x4E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4E);
    skip_1:
    // 0x800B1960: sh          $zero, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = 0;
    // 0x800B1964: lh          $v1, 0x4E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4E);
L_800B1968:
    // 0x800B1968: bltz        $v1, L_800B1978
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B196C: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_800B1978;
    }
    // 0x800B196C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x800B1970: b           L_800B1978
    // 0x800B1974: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B1978;
    // 0x800B1974: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B1978:
    // 0x800B1978: lh          $t7, 0x4A($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4A);
    // 0x800B197C: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B1980: beq         $at, $zero, L_800B198C
    if (ctx->r1 == 0) {
        // 0x800B1984: addiu       $v0, $zero, 0x50
        ctx->r2 = ADD32(0, 0X50);
            goto L_800B198C;
    }
    // 0x800B1984: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800B1988: sh          $zero, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = 0;
L_800B198C:
    // 0x800B198C: lh          $t8, 0x4C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4C);
    // 0x800B1990: slti        $at, $t8, 0x51
    ctx->r1 = SIGNED(ctx->r24) < 0X51 ? 1 : 0;
    // 0x800B1994: bnel        $at, $zero, L_800B19A4
    if (ctx->r1 != 0) {
        // 0x800B1998: lh          $t9, 0x4E($a0)
        ctx->r25 = MEM_H(ctx->r4, 0X4E);
            goto L_800B19A4;
    }
    goto skip_2;
    // 0x800B1998: lh          $t9, 0x4E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4E);
    skip_2:
    // 0x800B199C: sh          $v0, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r2;
    // 0x800B19A0: lh          $t9, 0x4E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4E);
L_800B19A4:
    // 0x800B19A4: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800B19A8: slti        $at, $t9, 0x51
    ctx->r1 = SIGNED(ctx->r25) < 0X51 ? 1 : 0;
    // 0x800B19AC: bnel        $at, $zero, L_800B19BC
    if (ctx->r1 != 0) {
        // 0x800B19B0: lh          $t0, 0x4C($a0)
        ctx->r8 = MEM_H(ctx->r4, 0X4C);
            goto L_800B19BC;
    }
    goto skip_3;
    // 0x800B19B0: lh          $t0, 0x4C($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4C);
    skip_3:
    // 0x800B19B4: sh          $v0, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r2;
    // 0x800B19B8: lh          $t0, 0x4C($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4C);
L_800B19BC:
    // 0x800B19BC: slti        $at, $t0, -0x50
    ctx->r1 = SIGNED(ctx->r8) < -0X50 ? 1 : 0;
    // 0x800B19C0: beql        $at, $zero, L_800B19D4
    if (ctx->r1 == 0) {
        // 0x800B19C4: lh          $v1, 0x4E($a0)
        ctx->r3 = MEM_H(ctx->r4, 0X4E);
            goto L_800B19D4;
    }
    goto skip_4;
    // 0x800B19C4: lh          $v1, 0x4E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4E);
    skip_4:
    // 0x800B19C8: addiu       $t1, $zero, -0x50
    ctx->r9 = ADD32(0, -0X50);
    // 0x800B19CC: sh          $t1, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r9;
    // 0x800B19D0: lh          $v1, 0x4E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4E);
L_800B19D4:
    // 0x800B19D4: slti        $at, $v1, -0x50
    ctx->r1 = SIGNED(ctx->r3) < -0X50 ? 1 : 0;
    // 0x800B19D8: beql        $at, $zero, L_800B19F0
    if (ctx->r1 == 0) {
        // 0x800B19DC: lh          $t3, 0x4C($a0)
        ctx->r11 = MEM_H(ctx->r4, 0X4C);
            goto L_800B19F0;
    }
    goto skip_5;
    // 0x800B19DC: lh          $t3, 0x4C($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4C);
    skip_5:
    // 0x800B19E0: addiu       $t2, $zero, -0x50
    ctx->r10 = ADD32(0, -0X50);
    // 0x800B19E4: sh          $t2, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r10;
    // 0x800B19E8: lh          $v1, 0x4E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4E);
    // 0x800B19EC: lh          $t3, 0x4C($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4C);
L_800B19F0:
    // 0x800B19F0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800B19F4: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B19F8: mflo        $t4
    ctx->r12 = lo;
    // 0x800B19FC: nop

    // 0x800B1A00: nop

    // 0x800B1A04: div         $zero, $t4, $v0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r2)));
    // 0x800B1A08: mflo        $t5
    ctx->r13 = lo;
    // 0x800B1A0C: sh          $t5, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r13;
    // 0x800B1A10: bne         $v0, $zero, L_800B1A1C
    if (ctx->r2 != 0) {
        // 0x800B1A14: nop
    
            goto L_800B1A1C;
    }
    // 0x800B1A14: nop

    // 0x800B1A18: break       7
    do_break(2148211224);
L_800B1A1C:
    // 0x800B1A1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1A20: bne         $v0, $at, L_800B1A34
    if (ctx->r2 != ctx->r1) {
        // 0x800B1A24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B1A34;
    }
    // 0x800B1A24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1A28: bne         $t4, $at, L_800B1A34
    if (ctx->r12 != ctx->r1) {
        // 0x800B1A2C: nop
    
            goto L_800B1A34;
    }
    // 0x800B1A2C: nop

    // 0x800B1A30: break       6
    do_break(2148211248);
L_800B1A34:
    // 0x800B1A34: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1A38: mflo        $t6
    ctx->r14 = lo;
    // 0x800B1A3C: nop

    // 0x800B1A40: nop

    // 0x800B1A44: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800B1A48: mflo        $t7
    ctx->r15 = lo;
    // 0x800B1A4C: sh          $t7, 0x52($a0)
    MEM_H(0X52, ctx->r4) = ctx->r15;
    // 0x800B1A50: bne         $v0, $zero, L_800B1A5C
    if (ctx->r2 != 0) {
        // 0x800B1A54: nop
    
            goto L_800B1A5C;
    }
    // 0x800B1A54: nop

    // 0x800B1A58: break       7
    do_break(2148211288);
L_800B1A5C:
    // 0x800B1A5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1A60: bne         $v0, $at, L_800B1A74
    if (ctx->r2 != ctx->r1) {
        // 0x800B1A64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B1A74;
    }
    // 0x800B1A64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1A68: bne         $t6, $at, L_800B1A74
    if (ctx->r14 != ctx->r1) {
        // 0x800B1A6C: nop
    
            goto L_800B1A74;
    }
    // 0x800B1A6C: nop

    // 0x800B1A70: break       6
    do_break(2148211312);
L_800B1A74:
    // 0x800B1A74: jr          $ra
    // 0x800B1A78: nop

    return;
    // 0x800B1A78: nop

;}

RECOMP_FUNC void func_800B1A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1A7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B1A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1A84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B1A88: jal         0x800B7450
    // 0x800B1A8C: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x800B1A8C: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    after_0:
    // 0x800B1A90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B1A94: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800B1A98: sh          $v0, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r2;
    // 0x800B1A9C: sh          $v0, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r2;
    // 0x800B1AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B1AA8: jr          $ra
    // 0x800B1AAC: nop

    return;
    // 0x800B1AAC: nop

;}

RECOMP_FUNC void func_800B1AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1AB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B1AB4: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800B1AB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B1ABC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B1AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1AC4: blez        $t6, L_800B1AD8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B1AC8: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800B1AD8;
    }
    // 0x800B1AC8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800B1ACC: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x800B1AD0: bne         $at, $zero, L_800B1AF8
    if (ctx->r1 != 0) {
        // 0x800B1AD4: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800B1AF8;
    }
    // 0x800B1AD4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
L_800B1AD8:
    // 0x800B1AD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B1ADC: jal         0x800B3BFC
    // 0x800B1AE0: addiu       $a0, $a0, 0x1340
    ctx->r4 = ADD32(ctx->r4, 0X1340);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B1AE0: addiu       $a0, $a0, 0x1340
    ctx->r4 = ADD32(ctx->r4, 0X1340);
    after_0:
    // 0x800B1AE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B1AE8: jal         0x800B3BFC
    // 0x800B1AEC: addiu       $a0, $a0, 0x138C
    ctx->r4 = ADD32(ctx->r4, 0X138C);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800B1AEC: addiu       $a0, $a0, 0x138C
    ctx->r4 = ADD32(ctx->r4, 0X138C);
    after_1:
    // 0x800B1AF0: b           L_800B1B58
    // 0x800B1AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B1B58;
    // 0x800B1AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B1AF8:
    // 0x800B1AF8: addiu       $v1, $v1, -0x6E70
    ctx->r3 = ADD32(ctx->r3, -0X6E70);
    // 0x800B1AFC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800B1B00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B1B04: beq         $v0, $at, L_800B1B30
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B08: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_800B1B30;
    }
    // 0x800B1B08: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x800B1B0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1B10: beq         $v0, $at, L_800B1B40
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B14: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B1B40;
    }
    // 0x800B1B14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B1B18: beq         $v0, $at, L_800B1B40
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B1C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800B1B40;
    }
    // 0x800B1B1C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B1B20: beq         $v0, $at, L_800B1B40
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B24: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800B1B40;
    }
    // 0x800B1B24: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B1B28: b           L_800B1B4C
    // 0x800B1B2C: nop

        goto L_800B1B4C;
    // 0x800B1B2C: nop

L_800B1B30:
    // 0x800B1B30: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800B1B34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1B38: b           L_800B1B54
    // 0x800B1B3C: sw          $t7, -0x6E6C($at)
    MEM_W(-0X6E6C, ctx->r1) = ctx->r15;
        goto L_800B1B54;
    // 0x800B1B3C: sw          $t7, -0x6E6C($at)
    MEM_W(-0X6E6C, ctx->r1) = ctx->r15;
L_800B1B40:
    // 0x800B1B40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1B44: b           L_800B1B54
    // 0x800B1B48: sw          $zero, -0x6E6C($at)
    MEM_W(-0X6E6C, ctx->r1) = 0;
        goto L_800B1B54;
    // 0x800B1B48: sw          $zero, -0x6E6C($at)
    MEM_W(-0X6E6C, ctx->r1) = 0;
L_800B1B4C:
    // 0x800B1B4C: jal         0x800B3BFC
    // 0x800B1B50: addiu       $a0, $a0, 0x13A0
    ctx->r4 = ADD32(ctx->r4, 0X13A0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800B1B50: addiu       $a0, $a0, 0x13A0
    ctx->r4 = ADD32(ctx->r4, 0X13A0);
    after_2:
L_800B1B54:
    // 0x800B1B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B1B58:
    // 0x800B1B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B1B5C: jr          $ra
    // 0x800B1B60: nop

    return;
    // 0x800B1B60: nop

;}

RECOMP_FUNC void func_800B1B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1B64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B1B68: lhu         $v0, -0x6E70($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6E70);
    // 0x800B1B6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B1B70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B1B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1B78: beq         $v0, $at, L_800B1BAC
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B7C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800B1BAC;
    }
    // 0x800B1B7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B1B80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1B84: beq         $v0, $at, L_800B1BBC
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B88: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800B1BBC;
    }
    // 0x800B1B88: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B1B8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B1B90: beq         $v0, $at, L_800B1BC8
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B94: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_800B1BC8;
    }
    // 0x800B1B94: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B1B98: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B1B9C: beq         $v0, $at, L_800B1BD4
    if (ctx->r2 == ctx->r1) {
        // 0x800B1BA0: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800B1BD4;
    }
    // 0x800B1BA0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B1BA4: b           L_800B1BE0
    // 0x800B1BA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
        goto L_800B1BE0;
    // 0x800B1BA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
L_800B1BAC:
    // 0x800B1BAC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B1BB0: addiu       $t6, $t6, -0x6CF0
    ctx->r14 = ADD32(ctx->r14, -0X6CF0);
    // 0x800B1BB4: b           L_800B1BE8
    // 0x800B1BB8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
        goto L_800B1BE8;
    // 0x800B1BB8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800B1BBC:
    // 0x800B1BBC: addiu       $t7, $t7, -0x6C70
    ctx->r15 = ADD32(ctx->r15, -0X6C70);
    // 0x800B1BC0: b           L_800B1BE8
    // 0x800B1BC4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
        goto L_800B1BE8;
    // 0x800B1BC4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_800B1BC8:
    // 0x800B1BC8: addiu       $t8, $t8, -0x6BF0
    ctx->r24 = ADD32(ctx->r24, -0X6BF0);
    // 0x800B1BCC: b           L_800B1BE8
    // 0x800B1BD0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
        goto L_800B1BE8;
    // 0x800B1BD0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_800B1BD4:
    // 0x800B1BD4: addiu       $t9, $t9, -0x6B70
    ctx->r25 = ADD32(ctx->r25, -0X6B70);
    // 0x800B1BD8: b           L_800B1BE8
    // 0x800B1BDC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
        goto L_800B1BE8;
    // 0x800B1BDC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_800B1BE0:
    // 0x800B1BE0: jal         0x800B3BFC
    // 0x800B1BE4: addiu       $a0, $a0, 0x13F8
    ctx->r4 = ADD32(ctx->r4, 0X13F8);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B1BE4: addiu       $a0, $a0, 0x13F8
    ctx->r4 = ADD32(ctx->r4, 0X13F8);
    after_0:
L_800B1BE8:
    // 0x800B1BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1BEC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1BF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B1BF4: jr          $ra
    // 0x800B1BF8: nop

    return;
    // 0x800B1BF8: nop

;}

RECOMP_FUNC void func_800B1BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1BFC: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800B1C00: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x800B1C04: lhu         $t7, 0x10E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X10E);
    // 0x800B1C08: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x800B1C0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B1C10: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B1C14: divu        $zero, $t9, $t8
    lo = S32(U32(ctx->r25) / U32(ctx->r24)); hi = S32(U32(ctx->r25) % U32(ctx->r24));
    // 0x800B1C18: lhu         $s1, 0x112($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X112);
    // 0x800B1C1C: mflo        $v0
    ctx->r2 = lo;
    // 0x800B1C20: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x800B1C24: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800B1C28: div         $zero, $s1, $t0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r8)));
    // 0x800B1C2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B1C30: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800B1C34: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800B1C38: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800B1C3C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800B1C40: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800B1C44: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B1C48: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B1C4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B1C50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B1C54: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800B1C58: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    // 0x800B1C5C: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800B1C60: mflo        $v1
    ctx->r3 = lo;
    // 0x800B1C64: andi        $t1, $v1, 0xFFFF
    ctx->r9 = ctx->r3 & 0XFFFF;
    // 0x800B1C68: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
    // 0x800B1C6C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800B1C70: bne         $t8, $zero, L_800B1C7C
    if (ctx->r24 != 0) {
        // 0x800B1C74: nop
    
            goto L_800B1C7C;
    }
    // 0x800B1C74: nop

    // 0x800B1C78: break       7
    do_break(2148211832);
L_800B1C7C:
    // 0x800B1C7C: sh          $v0, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = ctx->r2;
    // 0x800B1C80: bne         $t0, $zero, L_800B1C8C
    if (ctx->r8 != 0) {
        // 0x800B1C84: nop
    
            goto L_800B1C8C;
    }
    // 0x800B1C84: nop

    // 0x800B1C88: break       7
    do_break(2148211848);
L_800B1C8C:
    // 0x800B1C8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1C90: bne         $t0, $at, L_800B1CA4
    if (ctx->r8 != ctx->r1) {
        // 0x800B1C94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B1CA4;
    }
    // 0x800B1C94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1C98: bne         $a1, $at, L_800B1CA4
    if (ctx->r5 != ctx->r1) {
        // 0x800B1C9C: nop
    
            goto L_800B1CA4;
    }
    // 0x800B1C9C: nop

    // 0x800B1CA0: break       6
    do_break(2148211872);
L_800B1CA4:
    // 0x800B1CA4: andi        $t2, $v1, 0xFFFF
    ctx->r10 = ctx->r3 & 0XFFFF;
    // 0x800B1CA8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800B1CAC: bne         $t1, $zero, L_800B1CC0
    if (ctx->r9 != 0) {
        // 0x800B1CB0: lui         $t7, 0xE700
        ctx->r15 = S32(0XE700 << 16);
            goto L_800B1CC0;
    }
    // 0x800B1CB0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B1CB4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1CB8: b           L_800B1CDC
    // 0x800B1CBC: sh          $s1, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = ctx->r17;
        goto L_800B1CDC;
    // 0x800B1CBC: sh          $s1, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = ctx->r17;
L_800B1CC0:
    // 0x800B1CC0: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1CC4: mflo        $v0
    ctx->r2 = lo;
    // 0x800B1CC8: beql        $a1, $v0, L_800B1CE0
    if (ctx->r5 == ctx->r2) {
        // 0x800B1CCC: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800B1CE0;
    }
    goto skip_0;
    // 0x800B1CCC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_0:
    // 0x800B1CD0: subu        $t3, $a1, $v0
    ctx->r11 = SUB32(ctx->r5, ctx->r2);
    // 0x800B1CD4: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x800B1CD8: or          $t3, $t6, $zero
    ctx->r11 = ctx->r14 | 0;
L_800B1CDC:
    // 0x800B1CDC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800B1CE0:
    // 0x800B1CE0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B1CE4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B1CE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B1CEC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B1CF0: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800B1CF4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B1CF8: lbu         $t6, 0x127($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X127);
    // 0x800B1CFC: lbu         $t8, 0x12B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X12B);
    // 0x800B1D00: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B1D04: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800B1D08: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800B1D0C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x800B1D10: lbu         $t7, 0x12F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X12F);
    // 0x800B1D14: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B1D18: or          $fp, $t2, $zero
    ctx->r30 = ctx->r10 | 0;
    // 0x800B1D1C: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800B1D20: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800B1D24: lbu         $t9, 0x133($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X133);
    // 0x800B1D28: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800B1D2C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800B1D30: blez        $t2, L_800B2250
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800B1D34: sh          $t3, 0xEA($sp)
        MEM_H(0XEA, ctx->r29) = ctx->r11;
            goto L_800B2250;
    }
    // 0x800B1D34: sh          $t3, 0xEA($sp)
    MEM_H(0XEA, ctx->r29) = ctx->r11;
    // 0x800B1D38: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800B1D3C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B1D40: lwc1        $f0, 0x114($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B1D44: sll         $s6, $v1, 1
    ctx->r22 = S32(ctx->r3 << 1);
    // 0x800B1D48: addiu       $s6, $s6, 0x7
    ctx->r22 = ADD32(ctx->r22, 0X7);
    // 0x800B1D4C: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x800B1D50: sll         $a2, $a0, 2
    ctx->r6 = S32(ctx->r4 << 2);
    // 0x800B1D54: sra         $t7, $s6, 3
    ctx->r15 = S32(SIGNED(ctx->r22) >> 3);
    // 0x800B1D58: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x800B1D5C: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x800B1D60: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800B1D64: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800B1D68: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B1D6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B1D70: lhu         $s1, 0xEC($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0XEC);
    // 0x800B1D74: sll         $s6, $t8, 9
    ctx->r22 = S32(ctx->r24 << 9);
    // 0x800B1D78: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B1D7C: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x800B1D80: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800B1D84: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B1D88: or          $t2, $t6, $t9
    ctx->r10 = ctx->r14 | ctx->r25;
    // 0x800B1D8C: or          $t3, $t7, $t9
    ctx->r11 = ctx->r15 | ctx->r25;
    // 0x800B1D90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B1D94: lhu         $s2, 0x11E($sp)
    ctx->r18 = MEM_HU(ctx->r29, 0X11E);
    // 0x800B1D98: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B1D9C: andi        $t1, $a0, 0xFFF
    ctx->r9 = ctx->r4 & 0XFFF;
    // 0x800B1DA0: sll         $ra, $s2, 2
    ctx->r31 = S32(ctx->r18 << 2);
    // 0x800B1DA4: andi        $t7, $ra, 0xFFF
    ctx->r15 = ctx->r31 & 0XFFF;
    // 0x800B1DA8: sll         $ra, $t7, 12
    ctx->r31 = S32(ctx->r15 << 12);
    // 0x800B1DAC: lwc1        $f2, 0x118($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800B1DB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B1DB4: lhu         $t0, 0x122($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X122);
    // 0x800B1DB8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B1DBC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B1DC0: nop

    // 0x800B1DC4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800B1DC8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B1DCC: nop

    // 0x800B1DD0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B1DD4: beql        $t6, $zero, L_800B1E24
    if (ctx->r14 == 0) {
        // 0x800B1DD8: mfc1        $t6, $f8
        ctx->r14 = (int32_t)ctx->f8.u32l;
            goto L_800B1E24;
    }
    goto skip_1;
    // 0x800B1DD8: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x800B1DDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B1DE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B1DE4: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800B1DE8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B1DEC: nop

    // 0x800B1DF0: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B1DF4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B1DF8: nop

    // 0x800B1DFC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B1E00: bne         $t6, $zero, L_800B1E18
    if (ctx->r14 != 0) {
        // 0x800B1E04: nop
    
            goto L_800B1E18;
    }
    // 0x800B1E04: nop

    // 0x800B1E08: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800B1E0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1E10: b           L_800B1E30
    // 0x800B1E14: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800B1E30;
    // 0x800B1E14: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800B1E18:
    // 0x800B1E18: b           L_800B1E30
    // 0x800B1E1C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800B1E30;
    // 0x800B1E1C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800B1E20: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
L_800B1E24:
    // 0x800B1E24: nop

    // 0x800B1E28: bltz        $t6, L_800B1E18
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B1E2C: nop
    
            goto L_800B1E18;
    }
    // 0x800B1E2C: nop

L_800B1E30:
    // 0x800B1E30: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B1E34: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B1E38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B1E3C: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x800B1E40: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B1E44: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800B1E48: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800B1E4C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B1E50: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B1E54: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B1E58: nop

    // 0x800B1E5C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B1E60: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B1E64: nop

    // 0x800B1E68: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B1E6C: beql        $t7, $zero, L_800B1EBC
    if (ctx->r15 == 0) {
        // 0x800B1E70: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_800B1EBC;
    }
    goto skip_2;
    // 0x800B1E70: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x800B1E74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B1E78: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B1E7C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B1E80: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B1E84: nop

    // 0x800B1E88: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B1E8C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B1E90: nop

    // 0x800B1E94: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B1E98: bne         $t7, $zero, L_800B1EB0
    if (ctx->r15 != 0) {
        // 0x800B1E9C: nop
    
            goto L_800B1EB0;
    }
    // 0x800B1E9C: nop

    // 0x800B1EA0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800B1EA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1EA8: b           L_800B1EC8
    // 0x800B1EAC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800B1EC8;
    // 0x800B1EAC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800B1EB0:
    // 0x800B1EB0: b           L_800B1EC8
    // 0x800B1EB4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800B1EC8;
    // 0x800B1EB4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B1EB8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_800B1EBC:
    // 0x800B1EBC: nop

    // 0x800B1EC0: bltz        $t7, L_800B1EB0
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B1EC4: nop
    
            goto L_800B1EB0;
    }
    // 0x800B1EC4: nop

L_800B1EC8:
    // 0x800B1EC8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B1ECC: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x800B1ED0: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x800B1ED4: lhu         $t8, 0x10E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X10E);
    // 0x800B1ED8: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800B1EDC: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800B1EE0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B1EE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B1EE8: bgez        $t8, L_800B1EFC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B1EEC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B1EFC;
    }
    // 0x800B1EEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B1EF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B1EF4: nop

    // 0x800B1EF8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800B1EFC:
    // 0x800B1EFC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B1F00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B1F04: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B1F08: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B1F0C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B1F10: nop

    // 0x800B1F14: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B1F18: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B1F1C: nop

    // 0x800B1F20: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B1F24: beql        $t6, $zero, L_800B1F74
    if (ctx->r14 == 0) {
        // 0x800B1F28: mfc1        $t6, $f16
        ctx->r14 = (int32_t)ctx->f16.u32l;
            goto L_800B1F74;
    }
    goto skip_3;
    // 0x800B1F28: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x800B1F2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B1F30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B1F34: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800B1F38: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B1F3C: nop

    // 0x800B1F40: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B1F44: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B1F48: nop

    // 0x800B1F4C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B1F50: bne         $t6, $zero, L_800B1F68
    if (ctx->r14 != 0) {
        // 0x800B1F54: nop
    
            goto L_800B1F68;
    }
    // 0x800B1F54: nop

    // 0x800B1F58: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800B1F5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1F60: b           L_800B1F80
    // 0x800B1F64: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800B1F80;
    // 0x800B1F64: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800B1F68:
    // 0x800B1F68: b           L_800B1F80
    // 0x800B1F6C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800B1F80;
    // 0x800B1F6C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800B1F70: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
L_800B1F74:
    // 0x800B1F74: nop

    // 0x800B1F78: bltz        $t6, L_800B1F68
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B1F7C: nop
    
            goto L_800B1F68;
    }
    // 0x800B1F7C: nop

L_800B1F80:
    // 0x800B1F80: or          $t7, $t6, $zero
    ctx->r15 = ctx->r14 | 0;
    // 0x800B1F84: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B1F88: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x800B1F8C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B1F90: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800B1F94: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B1F98: mtc1        $s1, $f18
    ctx->f18.u32l = ctx->r17;
    // 0x800B1F9C: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800B1FA0: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800B1FA4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800B1FA8: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800B1FAC: bgez        $s1, L_800B1FC4
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800B1FB0: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800B1FC4;
    }
    // 0x800B1FB0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B1FB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B1FB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B1FBC: nop

    // 0x800B1FC0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800B1FC4:
    // 0x800B1FC4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800B1FC8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B1FCC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B1FD0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B1FD4: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x800B1FD8: nop

    // 0x800B1FDC: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800B1FE0: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x800B1FE4: nop

    // 0x800B1FE8: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x800B1FEC: beql        $a3, $zero, L_800B203C
    if (ctx->r7 == 0) {
        // 0x800B1FF0: mfc1        $a3, $f10
        ctx->r7 = (int32_t)ctx->f10.u32l;
            goto L_800B203C;
    }
    goto skip_4;
    // 0x800B1FF0: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x800B1FF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B1FF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B1FFC: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800B2000: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x800B2004: nop

    // 0x800B2008: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B200C: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x800B2010: nop

    // 0x800B2014: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x800B2018: bne         $a3, $zero, L_800B2030
    if (ctx->r7 != 0) {
        // 0x800B201C: nop
    
            goto L_800B2030;
    }
    // 0x800B201C: nop

    // 0x800B2020: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800B2024: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2028: b           L_800B2048
    // 0x800B202C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_800B2048;
    // 0x800B202C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_800B2030:
    // 0x800B2030: b           L_800B2048
    // 0x800B2034: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_800B2048;
    // 0x800B2034: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800B2038: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
L_800B203C:
    // 0x800B203C: nop

    // 0x800B2040: bltz        $a3, L_800B2030
    if (SIGNED(ctx->r7) < 0) {
        // 0x800B2044: nop
    
            goto L_800B2030;
    }
    // 0x800B2044: nop

L_800B2048:
    // 0x800B2048: multu       $v1, $s1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B204C: andi        $t7, $a3, 0xFFFF
    ctx->r15 = ctx->r7 & 0XFFFF;
    // 0x800B2050: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2054: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800B2058: addiu       $s3, $s3, -0x6E6C
    ctx->r19 = ADD32(ctx->r19, -0X6E6C);
    // 0x800B205C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800B2060: addu        $t5, $t0, $t7
    ctx->r13 = ADD32(ctx->r8, ctx->r15);
    // 0x800B2064: lui         $s7, 0xF500
    ctx->r23 = S32(0XF500 << 16);
    // 0x800B2068: lui         $s4, 0x10
    ctx->r20 = S32(0X10 << 16);
    // 0x800B206C: mflo        $t4
    ctx->r12 = lo;
    // 0x800B2070: andi        $t8, $t4, 0xFFFF
    ctx->r24 = ctx->r12 & 0XFFFF;
    // 0x800B2074: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
L_800B2078:
    // 0x800B2078: multu       $a1, $a3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B207C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800B2080: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800B2084: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B2088: andi        $t6, $t9, 0x7
    ctx->r14 = ctx->r25 & 0X7;
    // 0x800B208C: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x800B2090: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B2094: or          $t9, $t8, $s4
    ctx->r25 = ctx->r24 | ctx->r20;
    // 0x800B2098: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x800B209C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B20A0: mflo        $s2
    ctx->r18 = lo;
    // 0x800B20A4: sh          $s2, 0xE8($sp)
    MEM_H(0XE8, ctx->r29) = ctx->r18;
    // 0x800B20A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B20AC: multu       $a1, $t4
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B20B0: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x800B20B4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B20B8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B20BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B20C0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B20C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800B20C8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B20CC: mflo        $t7
    ctx->r15 = lo;
    // 0x800B20D0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B20D4: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800B20D8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B20DC: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800B20E0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B20E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B20E8: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x800B20EC: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x800B20F0: or          $t6, $t9, $s7
    ctx->r14 = ctx->r25 | ctx->r23;
    // 0x800B20F4: or          $t7, $t6, $s4
    ctx->r15 = ctx->r14 | ctx->r20;
    // 0x800B20F8: or          $t8, $t7, $s6
    ctx->r24 = ctx->r15 | ctx->r22;
    // 0x800B20FC: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x800B2100: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800B2104: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800B2108: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800B210C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800B2110: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B2114: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800B2118: lui         $t7, 0xF400
    ctx->r15 = S32(0XF400 << 16);
    // 0x800B211C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B2120: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x800B2124: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800B2128: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B212C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B2130: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800B2134: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B2138: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B213C: andi        $t6, $t9, 0x7
    ctx->r14 = ctx->r25 & 0X7;
    // 0x800B2140: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x800B2144: or          $t8, $t7, $s7
    ctx->r24 = ctx->r15 | ctx->r23;
    // 0x800B2148: or          $t9, $t8, $s4
    ctx->r25 = ctx->r24 | ctx->r20;
    // 0x800B214C: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x800B2150: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800B2154: or          $t6, $t9, $s6
    ctx->r14 = ctx->r25 | ctx->r22;
    // 0x800B2158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B215C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800B2160: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800B2164: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800B2168: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B216C: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x800B2170: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2174: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800B2178: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x800B217C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800B2180: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800B2184: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B2188: lhu         $a0, -0x6E70($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6E70);
    // 0x800B218C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800B2190: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800B2194: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x800B2198: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800B219C: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x800B21A0: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x800B21A4: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x800B21A8: jal         0x800B1B64
    // 0x800B21AC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    func_800B1B64(rdram, ctx);
        goto after_0;
    // 0x800B21AC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x800B21B0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800B21B4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800B21B8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800B21BC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800B21C0: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800B21C4: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800B21C8: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800B21CC: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800B21D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800B21D4: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x800B21D8: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x800B21DC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800B21E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B21E4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B21E8: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800B21EC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800B21F0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B21F4: addu        $t9, $t0, $a1
    ctx->r25 = ADD32(ctx->r8, ctx->r5);
    // 0x800B21F8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B21FC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B2200: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800B2204: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B220C: or          $t8, $ra, $t7
    ctx->r24 = ctx->r31 | ctx->r15;
    // 0x800B2210: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B2214: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2218: lui         $t9, 0xE100
    ctx->r25 = S32(0XE100 << 16);
    // 0x800B221C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B2220: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800B2224: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800B2228: lui         $t6, 0xF100
    ctx->r14 = S32(0XF100 << 16);
    // 0x800B222C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800B2230: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800B2234: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800B2238: andi        $a1, $s5, 0xFFFF
    ctx->r5 = ctx->r21 & 0XFFFF;
    // 0x800B223C: slt         $at, $a1, $fp
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x800B2240: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800B2244: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2248: bne         $at, $zero, L_800B2078
    if (ctx->r1 != 0) {
        // 0x800B224C: sw          $t7, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r15;
            goto L_800B2078;
    }
    // 0x800B224C: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
L_800B2250:
    // 0x800B2250: lhu         $t3, 0xEA($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0XEA);
    // 0x800B2254: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800B2258: addiu       $s3, $s3, -0x6E6C
    ctx->r19 = ADD32(ctx->r19, -0X6E6C);
    // 0x800B225C: lui         $s4, 0x10
    ctx->r20 = S32(0X10 << 16);
    // 0x800B2260: beq         $t3, $zero, L_800B27D8
    if (ctx->r11 == 0) {
        // 0x800B2264: lui         $s7, 0xF500
        ctx->r23 = S32(0XF500 << 16);
            goto L_800B27D8;
    }
    // 0x800B2264: lui         $s7, 0xF500
    ctx->r23 = S32(0XF500 << 16);
    // 0x800B2268: lhu         $t4, 0xEC($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XEC);
    // 0x800B226C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x800B2270: lhu         $t3, 0x11E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X11E);
    // 0x800B2274: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800B2278: lwc1        $f4, 0x118($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800B227C: bgez        $t4, L_800B2294
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800B2280: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800B2294;
    }
    // 0x800B2280: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B2284: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B2288: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B228C: nop

    // 0x800B2290: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_800B2294:
    // 0x800B2294: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B2298: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B229C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B22A0: lhu         $t8, 0xE8($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XE8);
    // 0x800B22A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B22A8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B22AC: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x800B22B0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B22B4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B22B8: nop

    // 0x800B22BC: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800B22C0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B22C4: nop

    // 0x800B22C8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B22CC: beql        $t6, $zero, L_800B231C
    if (ctx->r14 == 0) {
        // 0x800B22D0: mfc1        $t6, $f10
        ctx->r14 = (int32_t)ctx->f10.u32l;
            goto L_800B231C;
    }
    goto skip_5;
    // 0x800B22D0: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    skip_5:
    // 0x800B22D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B22D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B22DC: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800B22E0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B22E4: nop

    // 0x800B22E8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B22EC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B22F0: nop

    // 0x800B22F4: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B22F8: bne         $t6, $zero, L_800B2310
    if (ctx->r14 != 0) {
        // 0x800B22FC: nop
    
            goto L_800B2310;
    }
    // 0x800B22FC: nop

    // 0x800B2300: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800B2304: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2308: b           L_800B2328
    // 0x800B230C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800B2328;
    // 0x800B230C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800B2310:
    // 0x800B2310: b           L_800B2328
    // 0x800B2314: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800B2328;
    // 0x800B2314: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800B2318: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
L_800B231C:
    // 0x800B231C: nop

    // 0x800B2320: bltz        $t6, L_800B2310
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B2324: nop
    
            goto L_800B2310;
    }
    // 0x800B2324: nop

L_800B2328:
    // 0x800B2328: multu       $a1, $t4
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B232C: or          $t7, $t6, $zero
    ctx->r15 = ctx->r14 | 0;
    // 0x800B2330: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2334: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800B2338: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800B233C: sh          $t9, 0xE8($sp)
    MEM_H(0XE8, ctx->r29) = ctx->r25;
    // 0x800B2340: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x800B2344: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800B2348: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800B234C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800B2350: or          $t6, $t9, $s4
    ctx->r14 = ctx->r25 | ctx->r20;
    // 0x800B2354: mflo        $t9
    ctx->r25 = lo;
    // 0x800B2358: andi        $t8, $a0, 0xFFF
    ctx->r24 = ctx->r4 & 0XFFF;
    // 0x800B235C: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800B2360: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800B2364: multu       $s5, $t6
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2368: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B236C: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x800B2370: sll         $s6, $a1, 1
    ctx->r22 = S32(ctx->r5 << 1);
    // 0x800B2374: addiu       $s6, $s6, 0x7
    ctx->r22 = ADD32(ctx->r22, 0X7);
    // 0x800B2378: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B237C: sll         $a2, $a0, 2
    ctx->r6 = S32(ctx->r4 << 2);
    // 0x800B2380: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2384: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B2388: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800B238C: mflo        $t8
    ctx->r24 = lo;
    // 0x800B2390: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800B2394: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800B2398: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B239C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800B23A0: sra         $t8, $s6, 3
    ctx->r24 = S32(SIGNED(ctx->r22) >> 3);
    // 0x800B23A4: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x800B23A8: sll         $s6, $t7, 9
    ctx->r22 = S32(ctx->r15 << 9);
    // 0x800B23AC: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x800B23B0: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800B23B4: or          $t9, $t7, $s7
    ctx->r25 = ctx->r15 | ctx->r23;
    // 0x800B23B8: or          $t6, $t9, $s4
    ctx->r14 = ctx->r25 | ctx->r20;
    // 0x800B23BC: or          $t8, $t6, $s6
    ctx->r24 = ctx->r14 | ctx->r22;
    // 0x800B23C0: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x800B23C4: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x800B23C8: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800B23CC: sll         $t2, $t6, 12
    ctx->r10 = S32(ctx->r14 << 12);
    // 0x800B23D0: or          $t1, $t2, $at
    ctx->r9 = ctx->r10 | ctx->r1;
    // 0x800B23D4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800B23D8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800B23DC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800B23E0: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800B23E4: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B23E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B23EC: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B23F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B23F4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B23F8: div.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800B23FC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B2400: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B2408: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B240C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B2410: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2414: sll         $ra, $t3, 2
    ctx->r31 = S32(ctx->r11 << 2);
    // 0x800B2418: andi        $t7, $ra, 0xFFF
    ctx->r15 = ctx->r31 & 0XFFF;
    // 0x800B241C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800B2420: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2424: sll         $ra, $t7, 12
    ctx->r31 = S32(ctx->r15 << 12);
    // 0x800B2428: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B242C: lhu         $t0, 0x122($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X122);
    // 0x800B2430: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2434: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2438: nop

    // 0x800B243C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B2440: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2444: nop

    // 0x800B2448: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800B244C: beql        $t8, $zero, L_800B249C
    if (ctx->r24 == 0) {
        // 0x800B2450: mfc1        $t8, $f4
        ctx->r24 = (int32_t)ctx->f4.u32l;
            goto L_800B249C;
    }
    goto skip_6;
    // 0x800B2450: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    skip_6:
    // 0x800B2454: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B2458: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B245C: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B2460: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2464: nop

    // 0x800B2468: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B246C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2470: nop

    // 0x800B2474: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800B2478: bne         $t8, $zero, L_800B2490
    if (ctx->r24 != 0) {
        // 0x800B247C: nop
    
            goto L_800B2490;
    }
    // 0x800B247C: nop

    // 0x800B2480: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800B2484: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2488: b           L_800B24A8
    // 0x800B248C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800B24A8;
    // 0x800B248C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800B2490:
    // 0x800B2490: b           L_800B24A8
    // 0x800B2494: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800B24A8;
    // 0x800B2494: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B2498: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
L_800B249C:
    // 0x800B249C: nop

    // 0x800B24A0: bltz        $t8, L_800B2490
    if (SIGNED(ctx->r24) < 0) {
        // 0x800B24A4: nop
    
            goto L_800B2490;
    }
    // 0x800B24A4: nop

L_800B24A8:
    // 0x800B24A8: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B24AC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B24B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B24B4: lwc1        $f10, 0x118($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800B24B8: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x800B24BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B24C0: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800B24C4: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800B24C8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B24CC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B24D0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B24D4: nop

    // 0x800B24D8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B24DC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B24E0: nop

    // 0x800B24E4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B24E8: beql        $t7, $zero, L_800B2538
    if (ctx->r15 == 0) {
        // 0x800B24EC: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_800B2538;
    }
    goto skip_7;
    // 0x800B24EC: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_7:
    // 0x800B24F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B24F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B24F8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B24FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2500: nop

    // 0x800B2504: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B2508: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B250C: nop

    // 0x800B2510: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2514: bne         $t7, $zero, L_800B252C
    if (ctx->r15 != 0) {
        // 0x800B2518: nop
    
            goto L_800B252C;
    }
    // 0x800B2518: nop

    // 0x800B251C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800B2520: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2524: b           L_800B2544
    // 0x800B2528: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800B2544;
    // 0x800B2528: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800B252C:
    // 0x800B252C: b           L_800B2544
    // 0x800B2530: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800B2544;
    // 0x800B2530: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B2534: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_800B2538:
    // 0x800B2538: nop

    // 0x800B253C: bltz        $t7, L_800B252C
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B2540: nop
    
            goto L_800B252C;
    }
    // 0x800B2540: nop

L_800B2544:
    // 0x800B2544: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2548: or          $t9, $t7, $zero
    ctx->r25 = ctx->r15 | 0;
    // 0x800B254C: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800B2550: lhu         $t9, 0x10E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X10E);
    // 0x800B2554: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800B2558: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800B255C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800B2560: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B2564: bgez        $t9, L_800B2578
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B2568: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B2578;
    }
    // 0x800B2568: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B256C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B2570: nop

    // 0x800B2574: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800B2578:
    // 0x800B2578: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B257C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B2580: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B2584: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2588: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B258C: nop

    // 0x800B2590: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2594: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2598: nop

    // 0x800B259C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800B25A0: beql        $t8, $zero, L_800B25F0
    if (ctx->r24 == 0) {
        // 0x800B25A4: mfc1        $t8, $f18
        ctx->r24 = (int32_t)ctx->f18.u32l;
            goto L_800B25F0;
    }
    goto skip_8;
    // 0x800B25A4: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    skip_8:
    // 0x800B25A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B25AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B25B0: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B25B4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B25B8: nop

    // 0x800B25BC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B25C0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B25C4: nop

    // 0x800B25C8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800B25CC: bne         $t8, $zero, L_800B25E4
    if (ctx->r24 != 0) {
        // 0x800B25D0: nop
    
            goto L_800B25E4;
    }
    // 0x800B25D0: nop

    // 0x800B25D4: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800B25D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B25DC: b           L_800B25FC
    // 0x800B25E0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800B25FC;
    // 0x800B25E0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800B25E4:
    // 0x800B25E4: b           L_800B25FC
    // 0x800B25E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800B25FC;
    // 0x800B25E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B25EC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
L_800B25F0:
    // 0x800B25F0: nop

    // 0x800B25F4: bltz        $t8, L_800B25E4
    if (SIGNED(ctx->r24) < 0) {
        // 0x800B25F8: nop
    
            goto L_800B25E4;
    }
    // 0x800B25F8: nop

L_800B25FC:
    // 0x800B25FC: or          $t7, $t8, $zero
    ctx->r15 = ctx->r24 | 0;
    // 0x800B2600: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x800B2604: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2608: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B260C: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x800B2610: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x800B2614: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800B2618: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800B261C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800B2620: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800B2624: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800B2628: lui         $t8, 0xF400
    ctx->r24 = S32(0XF400 << 16);
    // 0x800B262C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B2630: lhu         $v1, 0xEA($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0XEA);
    // 0x800B2634: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800B2638: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800B263C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800B2640: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800B2644: andi        $v1, $t7, 0xFFF
    ctx->r3 = ctx->r15 & 0XFFF;
    // 0x800B2648: or          $t6, $t1, $v1
    ctx->r14 = ctx->r9 | ctx->r3;
    // 0x800B264C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B2650: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800B2654: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B2658: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800B265C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B2660: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2664: andi        $t9, $t7, 0x7
    ctx->r25 = ctx->r15 & 0X7;
    // 0x800B2668: sll         $t6, $t9, 21
    ctx->r14 = S32(ctx->r25 << 21);
    // 0x800B266C: or          $t8, $t6, $s7
    ctx->r24 = ctx->r14 | ctx->r23;
    // 0x800B2670: or          $t7, $t8, $s4
    ctx->r15 = ctx->r24 | ctx->r20;
    // 0x800B2674: or          $t9, $t7, $s6
    ctx->r25 = ctx->r15 | ctx->r22;
    // 0x800B2678: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800B267C: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B2680: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800B2684: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800B2688: or          $t7, $t2, $v1
    ctx->r15 = ctx->r10 | ctx->r3;
    // 0x800B268C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800B2690: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800B2694: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x800B2698: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x800B269C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800B26A0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800B26A4: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x800B26A8: jal         0x800B1B64
    // 0x800B26AC: lhu         $a0, -0x6E70($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6E70);
    func_800B1B64(rdram, ctx);
        goto after_1;
    // 0x800B26AC: lhu         $a0, -0x6E70($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6E70);
    after_1:
    // 0x800B26B0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800B26B4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800B26B8: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x800B26BC: lhu         $t6, 0xEA($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XEA);
    // 0x800B26C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B26C4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B26C8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B26CC: lhu         $v1, 0xE8($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0XE8);
    // 0x800B26D0: bgez        $t6, L_800B26E8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B26D4: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B26E8;
    }
    // 0x800B26D4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B26D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B26DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B26E0: nop

    // 0x800B26E4: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_800B26E8:
    // 0x800B26E8: lwc1        $f8, 0x118($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800B26EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B26F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B26F4: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800B26F8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B26FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800B2700: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B2704: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2708: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B270C: nop

    // 0x800B2710: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2714: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2718: nop

    // 0x800B271C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2720: beql        $t7, $zero, L_800B2770
    if (ctx->r15 == 0) {
        // 0x800B2724: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_800B2770;
    }
    goto skip_9;
    // 0x800B2724: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_9:
    // 0x800B2728: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B272C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2730: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B2734: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2738: nop

    // 0x800B273C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B2740: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2744: nop

    // 0x800B2748: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B274C: bne         $t7, $zero, L_800B2764
    if (ctx->r15 != 0) {
        // 0x800B2750: nop
    
            goto L_800B2764;
    }
    // 0x800B2750: nop

    // 0x800B2754: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800B2758: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B275C: b           L_800B277C
    // 0x800B2760: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800B277C;
    // 0x800B2760: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800B2764:
    // 0x800B2764: b           L_800B277C
    // 0x800B2768: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800B277C;
    // 0x800B2768: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B276C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_800B2770:
    // 0x800B2770: nop

    // 0x800B2774: bltz        $t7, L_800B2764
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B2778: nop
    
            goto L_800B2764;
    }
    // 0x800B2778: nop

L_800B277C:
    // 0x800B277C: or          $t9, $t7, $zero
    ctx->r25 = ctx->r15 | 0;
    // 0x800B2780: addu        $t6, $t0, $t9
    ctx->r14 = ADD32(ctx->r8, ctx->r25);
    // 0x800B2784: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2788: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800B278C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800B2790: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800B2794: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x800B2798: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800B279C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800B27A0: addu        $t9, $t0, $v1
    ctx->r25 = ADD32(ctx->r8, ctx->r3);
    // 0x800B27A4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800B27A8: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x800B27AC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B27B0: or          $t7, $ra, $t6
    ctx->r15 = ctx->r31 | ctx->r14;
    // 0x800B27B4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800B27B8: lui         $t9, 0xE100
    ctx->r25 = S32(0XE100 << 16);
    // 0x800B27BC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800B27C0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800B27C4: lui         $t8, 0xF100
    ctx->r24 = S32(0XF100 << 16);
    // 0x800B27C8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800B27CC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800B27D0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B27D4: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
L_800B27D8:
    // 0x800B27D8: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x800B27DC: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x800B27E0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800B27E4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800B27E8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800B27EC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800B27F0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800B27F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B27F8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B27FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B2800: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2804: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B2808: jr          $ra
    // 0x800B280C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x800B280C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}

RECOMP_FUNC void func_800B2810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2810: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B2814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2818: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B281C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B2820: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B2824: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B2828: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B282C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B2830: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800B2834: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B2838: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800B283C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B2840: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800B2844: lbu         $t6, 0x67($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X67);
    // 0x800B2848: lbu         $t9, 0x6B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X6B);
    // 0x800B284C: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x800B2850: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800B2854: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800B2858: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B285C: lbu         $t7, 0x6F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X6F);
    // 0x800B2860: addiu       $v1, $t2, 0x8
    ctx->r3 = ADD32(ctx->r10, 0X8);
    // 0x800B2864: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B2868: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800B286C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800B2870: lbu         $t8, 0x73($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X73);
    // 0x800B2874: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800B2878: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800B287C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800B2880: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x800B2884: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800B2888: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B288C: jal         0x800B1B64
    // 0x800B2890: lhu         $a0, -0x6E70($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6E70);
    func_800B1B64(rdram, ctx);
        goto after_0;
    // 0x800B2890: lhu         $a0, -0x6E70($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6E70);
    after_0:
    // 0x800B2894: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2898: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B289C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B28A0: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x800B28A4: lhu         $t1, 0x52($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X52);
    // 0x800B28A8: lhu         $a3, 0x4E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X4E);
    // 0x800B28AC: addiu       $t5, $t5, -0x6E6C
    ctx->r13 = ADD32(ctx->r13, -0X6E6C);
    // 0x800B28B0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B28B4: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B28B8: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800B28BC: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x800B28C0: lui         $ra, 0x10
    ctx->r31 = S32(0X10 << 16);
    // 0x800B28C4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B28C8: sll         $t4, $a3, 4
    ctx->r12 = S32(ctx->r7 << 4);
    // 0x800B28CC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B28D0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800B28D4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B28D8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B28DC: mflo        $t0
    ctx->r8 = lo;
    // 0x800B28E0: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x800B28E4: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x800B28E8: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x800B28EC: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800B28F0: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x800B28F4: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800B28F8: or          $t6, $t8, $ra
    ctx->r14 = ctx->r24 | ctx->r31;
    // 0x800B28FC: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800B2900: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B2904: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800B2908: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B290C: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x800B2910: lw          $t6, 0x14($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X14);
    // 0x800B2914: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B2918: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B291C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800B2920: bgez        $t4, L_800B2930
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800B2924: sra         $t9, $t4, 6
        ctx->r25 = S32(SIGNED(ctx->r12) >> 6);
            goto L_800B2930;
    }
    // 0x800B2924: sra         $t9, $t4, 6
    ctx->r25 = S32(SIGNED(ctx->r12) >> 6);
    // 0x800B2928: addiu       $at, $t4, 0x3F
    ctx->r1 = ADD32(ctx->r12, 0X3F);
    // 0x800B292C: sra         $t9, $at, 6
    ctx->r25 = S32(SIGNED(ctx->r1) >> 6);
L_800B2930:
    // 0x800B2930: or          $t8, $t9, $zero
    ctx->r24 = ctx->r25 | 0;
    // 0x800B2934: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800B2938: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x800B293C: sll         $t4, $t7, 9
    ctx->r12 = S32(ctx->r15 << 9);
    // 0x800B2940: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x800B2944: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800B2948: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800B294C: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800B2950: or          $t9, $t6, $ra
    ctx->r25 = ctx->r14 | ctx->r31;
    // 0x800B2954: or          $t8, $t9, $t4
    ctx->r24 = ctx->r25 | ctx->r12;
    // 0x800B2958: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800B295C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800B2960: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800B2964: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B2968: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B296C: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800B2970: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x800B2974: beq         $at, $zero, L_800B2984
    if (ctx->r1 == 0) {
        // 0x800B2978: sw          $t6, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r14;
            goto L_800B2984;
    }
    // 0x800B2978: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B297C: b           L_800B2988
    // 0x800B2980: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
        goto L_800B2988;
    // 0x800B2980: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
L_800B2984:
    // 0x800B2984: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
L_800B2988:
    // 0x800B2988: andi        $t9, $t2, 0xFFF
    ctx->r25 = ctx->r10 & 0XFFF;
    // 0x800B298C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800B2990: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x800B2994: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B2998: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B299C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B29A0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B29A4: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800B29A8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B29AC: andi        $t9, $t6, 0x7
    ctx->r25 = ctx->r14 & 0X7;
    // 0x800B29B0: sll         $t8, $t9, 21
    ctx->r24 = S32(ctx->r25 << 21);
    // 0x800B29B4: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800B29B8: or          $t6, $t7, $ra
    ctx->r14 = ctx->r15 | ctx->r31;
    // 0x800B29BC: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x800B29C0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B29C4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B29C8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800B29CC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B29D0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800B29D4: lbu         $a2, 0xF($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0XF);
    // 0x800B29D8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B29DC: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x800B29E0: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x800B29E4: sll         $t6, $t7, 14
    ctx->r14 = S32(ctx->r15 << 14);
    // 0x800B29E8: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800B29EC: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800B29F0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800B29F4: addiu       $t6, $a3, -0x1
    ctx->r14 = ADD32(ctx->r7, -0X1);
    // 0x800B29F8: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800B29FC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800B2A00: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800B2A04: addiu       $t7, $t1, -0x1
    ctx->r15 = ADD32(ctx->r9, -0X1);
    // 0x800B2A08: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x800B2A0C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800B2A10: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800B2A14: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800B2A18: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800B2A1C: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B2A20: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800B2A24: lui         $t7, 0xD700
    ctx->r15 = S32(0XD700 << 16);
    // 0x800B2A28: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800B2A2C: ori         $t8, $t8, 0x8000
    ctx->r24 = ctx->r24 | 0X8000;
    // 0x800B2A30: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800B2A34: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800B2A38: lhu         $t6, 0x4E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4E);
    // 0x800B2A3C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B2A40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B2A44: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B2A48: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B2A4C: lhu         $a1, 0x62($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X62);
    // 0x800B2A50: lhu         $a0, 0x5E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X5E);
    // 0x800B2A54: bgez        $t6, L_800B2A6C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B2A58: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B2A6C;
    }
    // 0x800B2A58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2A5C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B2A60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B2A64: nop

    // 0x800B2A68: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800B2A6C:
    // 0x800B2A6C: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800B2A70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2A74: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B2A78: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2A7C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2A80: nop

    // 0x800B2A84: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B2A88: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2A8C: nop

    // 0x800B2A90: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2A94: beql        $t7, $zero, L_800B2AE4
    if (ctx->r15 == 0) {
        // 0x800B2A98: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_800B2AE4;
    }
    goto skip_0;
    // 0x800B2A98: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x800B2A9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B2AA0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2AA4: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800B2AA8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2AAC: nop

    // 0x800B2AB0: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2AB4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2AB8: nop

    // 0x800B2ABC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2AC0: bne         $t7, $zero, L_800B2AD8
    if (ctx->r15 != 0) {
        // 0x800B2AC4: nop
    
            goto L_800B2AD8;
    }
    // 0x800B2AC4: nop

    // 0x800B2AC8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800B2ACC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2AD0: b           L_800B2AF0
    // 0x800B2AD4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800B2AF0;
    // 0x800B2AD4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800B2AD8:
    // 0x800B2AD8: b           L_800B2AF0
    // 0x800B2ADC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800B2AF0;
    // 0x800B2ADC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B2AE0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_800B2AE4:
    // 0x800B2AE4: nop

    // 0x800B2AE8: bltz        $t7, L_800B2AD8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B2AEC: nop
    
            goto L_800B2AD8;
    }
    // 0x800B2AEC: nop

L_800B2AF0:
    // 0x800B2AF0: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x800B2AF4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2AF8: addu        $t6, $a0, $t8
    ctx->r14 = ADD32(ctx->r4, ctx->r24);
    // 0x800B2AFC: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800B2B00: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800B2B04: lhu         $t9, 0x52($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X52);
    // 0x800B2B08: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800B2B0C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800B2B10: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800B2B14: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800B2B18: bgez        $t9, L_800B2B30
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B2B1C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800B2B30;
    }
    // 0x800B2B1C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B2B20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B2B24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B2B28: nop

    // 0x800B2B2C: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800B2B30:
    // 0x800B2B30: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800B2B34: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B2B38: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B2B3C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2B40: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2B44: nop

    // 0x800B2B48: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800B2B4C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2B50: nop

    // 0x800B2B54: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800B2B58: beql        $t8, $zero, L_800B2BA8
    if (ctx->r24 == 0) {
        // 0x800B2B5C: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_800B2BA8;
    }
    goto skip_1;
    // 0x800B2B5C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x800B2B60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B2B64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B2B68: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800B2B6C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2B70: nop

    // 0x800B2B74: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B2B78: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2B7C: nop

    // 0x800B2B80: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800B2B84: bne         $t8, $zero, L_800B2B9C
    if (ctx->r24 != 0) {
        // 0x800B2B88: nop
    
            goto L_800B2B9C;
    }
    // 0x800B2B88: nop

    // 0x800B2B8C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800B2B90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2B94: b           L_800B2BB4
    // 0x800B2B98: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800B2BB4;
    // 0x800B2B98: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800B2B9C:
    // 0x800B2B9C: b           L_800B2BB4
    // 0x800B2BA0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800B2BB4;
    // 0x800B2BA0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B2BA4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_800B2BA8:
    // 0x800B2BA8: nop

    // 0x800B2BAC: bltz        $t8, L_800B2B9C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800B2BB0: nop
    
            goto L_800B2B9C;
    }
    // 0x800B2BB0: nop

L_800B2BB4:
    // 0x800B2BB4: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B2BB8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2BBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B2BC0: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x800B2BC4: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x800B2BC8: div.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B2BCC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B2BD0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B2BD4: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800B2BD8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800B2BDC: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x800B2BE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B2BE4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800B2BE8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B2BEC: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x800B2BF0: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800B2BF4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B2BF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B2BFC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B2C00: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B2C04: lui         $t7, 0xE100
    ctx->r15 = S32(0XE100 << 16);
    // 0x800B2C08: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B2C0C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B2C10: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B2C14: lui         $t9, 0xF100
    ctx->r25 = S32(0XF100 << 16);
    // 0x800B2C18: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800B2C1C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B2C20: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B2C24: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2C28: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2C2C: nop

    // 0x800B2C30: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2C34: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2C38: nop

    // 0x800B2C3C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B2C40: beql        $t6, $zero, L_800B2C90
    if (ctx->r14 == 0) {
        // 0x800B2C44: mfc1        $t6, $f18
        ctx->r14 = (int32_t)ctx->f18.u32l;
            goto L_800B2C90;
    }
    goto skip_2;
    // 0x800B2C44: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x800B2C48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B2C4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B2C50: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B2C54: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2C58: nop

    // 0x800B2C5C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B2C60: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2C64: nop

    // 0x800B2C68: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B2C6C: bne         $t6, $zero, L_800B2C84
    if (ctx->r14 != 0) {
        // 0x800B2C70: nop
    
            goto L_800B2C84;
    }
    // 0x800B2C70: nop

    // 0x800B2C74: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800B2C78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2C7C: b           L_800B2C9C
    // 0x800B2C80: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800B2C9C;
    // 0x800B2C80: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800B2C84:
    // 0x800B2C84: b           L_800B2C9C
    // 0x800B2C88: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800B2C9C;
    // 0x800B2C88: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800B2C8C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
L_800B2C90:
    // 0x800B2C90: nop

    // 0x800B2C94: bltz        $t6, L_800B2C84
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B2C98: nop
    
            goto L_800B2C84;
    }
    // 0x800B2C98: nop

L_800B2C9C:
    // 0x800B2C9C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2CA0: or          $t9, $t6, $zero
    ctx->r25 = ctx->r14 | 0;
    // 0x800B2CA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2CA8: div.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800B2CAC: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800B2CB0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B2CB4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2CB8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2CBC: nop

    // 0x800B2CC0: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B2CC4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2CC8: nop

    // 0x800B2CCC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2CD0: beql        $t7, $zero, L_800B2D20
    if (ctx->r15 == 0) {
        // 0x800B2CD4: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_800B2D20;
    }
    goto skip_3;
    // 0x800B2CD4: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_3:
    // 0x800B2CD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B2CDC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2CE0: sub.s       $f4, $f8, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800B2CE4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2CE8: nop

    // 0x800B2CEC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B2CF0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2CF4: nop

    // 0x800B2CF8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2CFC: bne         $t7, $zero, L_800B2D14
    if (ctx->r15 != 0) {
        // 0x800B2D00: nop
    
            goto L_800B2D14;
    }
    // 0x800B2D00: nop

    // 0x800B2D04: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800B2D08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2D0C: b           L_800B2D2C
    // 0x800B2D10: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800B2D2C;
    // 0x800B2D10: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800B2D14:
    // 0x800B2D14: b           L_800B2D2C
    // 0x800B2D18: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800B2D2C;
    // 0x800B2D18: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B2D1C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_800B2D20:
    // 0x800B2D20: nop

    // 0x800B2D24: bltz        $t7, L_800B2D14
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B2D28: nop
    
            goto L_800B2D14;
    }
    // 0x800B2D28: nop

L_800B2D2C:
    // 0x800B2D2C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2D30: or          $t9, $t7, $zero
    ctx->r25 = ctx->r15 | 0;
    // 0x800B2D34: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800B2D38: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800B2D3C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800B2D40: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B2D44: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    // 0x800B2D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2D4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800B2D50: jr          $ra
    // 0x800B2D54: nop

    return;
    // 0x800B2D54: nop

    // 0x800B2D58: nop

    // 0x800B2D5C: nop

;}

RECOMP_FUNC void func_800B2D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2D60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B2D64: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x800B2D68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2D6C: ldc1        $f24, 0x1450($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, 0X1450);
    // 0x800B2D70: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800B2D74: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800B2D78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B2D7C: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x800B2D80: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B2D84: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B2D88: addiu       $v0, $v0, -0x3480
    ctx->r2 = ADD32(ctx->r2, -0X3480);
    // 0x800B2D8C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800B2D90: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800B2D94: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B2D98: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x800B2D9C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B2DA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B2DA4: addiu       $a1, $zero, -0x10
    ctx->r5 = ADD32(0, -0X10);
    // 0x800B2DA8: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x800B2DAC: addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // 0x800B2DB0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
L_800B2DB4:
    // 0x800B2DB4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800B2DB8: addiu       $a2, $zero, -0x10
    ctx->r6 = ADD32(0, -0X10);
    // 0x800B2DBC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2DC0: addiu       $a3, $zero, -0xE
    ctx->r7 = ADD32(0, -0XE);
    // 0x800B2DC4: div.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B2DC8: mul.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B2DCC: nop

L_800B2DD0:
    // 0x800B2DD0: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800B2DD4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800B2DD8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800B2DDC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B2DE0: div.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800B2DE4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B2DE8: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800B2DEC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B2DF0: sub.d       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f16.d - ctx->f8.d;
    // 0x800B2DF4: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x800B2DF8: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800B2DFC: c.lt.d      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.d < ctx->f20.d;
    // 0x800B2E00: nop

    // 0x800B2E04: bc1fl       L_800B2E14
    if (!c1cs) {
        // 0x800B2E08: cvt.d.s     $f6, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
            goto L_800B2E14;
    }
    goto skip_0;
    // 0x800B2E08: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    skip_0:
    // 0x800B2E0C: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
    // 0x800B2E10: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
L_800B2E14:
    // 0x800B2E14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2E18: mul.d       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f24.d);
    // 0x800B2E1C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2E20: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2E24: nop

    // 0x800B2E28: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800B2E2C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2E30: nop

    // 0x800B2E34: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2E38: beql        $t7, $zero, L_800B2E8C
    if (ctx->r15 == 0) {
        // 0x800B2E3C: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_800B2E8C;
    }
    goto skip_1;
    // 0x800B2E3C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x800B2E40: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B2E44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B2E48: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2E4C: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x800B2E50: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2E54: nop

    // 0x800B2E58: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x800B2E5C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2E60: nop

    // 0x800B2E64: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2E68: bne         $t7, $zero, L_800B2E80
    if (ctx->r15 != 0) {
        // 0x800B2E6C: nop
    
            goto L_800B2E80;
    }
    // 0x800B2E6C: nop

    // 0x800B2E70: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800B2E74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2E78: b           L_800B2E98
    // 0x800B2E7C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800B2E98;
    // 0x800B2E7C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800B2E80:
    // 0x800B2E80: b           L_800B2E98
    // 0x800B2E84: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800B2E98;
    // 0x800B2E84: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B2E88: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_800B2E8C:
    // 0x800B2E8C: nop

    // 0x800B2E90: bltz        $t7, L_800B2E80
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B2E94: nop
    
            goto L_800B2E80;
    }
    // 0x800B2E94: nop

L_800B2E98:
    // 0x800B2E98: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800B2E9C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2EA0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800B2EA4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B2EA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2EAC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800B2EB0: sb          $t7, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r15;
    // 0x800B2EB4: div.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B2EB8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B2EBC: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800B2EC0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800B2EC4: sub.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d - ctx->f4.d;
    // 0x800B2EC8: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x800B2ECC: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800B2ED0: c.lt.d      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.d < ctx->f20.d;
    // 0x800B2ED4: nop

    // 0x800B2ED8: bc1fl       L_800B2EE8
    if (!c1cs) {
        // 0x800B2EDC: cvt.d.s     $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
            goto L_800B2EE8;
    }
    goto skip_2;
    // 0x800B2EDC: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    skip_2:
    // 0x800B2EE0: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
    // 0x800B2EE4: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
L_800B2EE8:
    // 0x800B2EE8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B2EEC: mul.d       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f24.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f24.d);
    // 0x800B2EF0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2EF4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2EF8: nop

    // 0x800B2EFC: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800B2F00: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2F04: nop

    // 0x800B2F08: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800B2F0C: beql        $t9, $zero, L_800B2F60
    if (ctx->r25 == 0) {
        // 0x800B2F10: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_800B2F60;
    }
    goto skip_3;
    // 0x800B2F10: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x800B2F14: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800B2F18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B2F1C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B2F20: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x800B2F24: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2F28: nop

    // 0x800B2F2C: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800B2F30: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2F34: nop

    // 0x800B2F38: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800B2F3C: bne         $t9, $zero, L_800B2F54
    if (ctx->r25 != 0) {
        // 0x800B2F40: nop
    
            goto L_800B2F54;
    }
    // 0x800B2F40: nop

    // 0x800B2F44: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800B2F48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2F4C: b           L_800B2F6C
    // 0x800B2F50: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800B2F6C;
    // 0x800B2F50: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800B2F54:
    // 0x800B2F54: b           L_800B2F6C
    // 0x800B2F58: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800B2F6C;
    // 0x800B2F58: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800B2F5C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_800B2F60:
    // 0x800B2F60: nop

    // 0x800B2F64: bltz        $t9, L_800B2F54
    if (SIGNED(ctx->r25) < 0) {
        // 0x800B2F68: nop
    
            goto L_800B2F54;
    }
    // 0x800B2F68: nop

L_800B2F6C:
    // 0x800B2F6C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2F70: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x800B2F74: bne         $a3, $t0, L_800B2DD0
    if (ctx->r7 != ctx->r8) {
        // 0x800B2F78: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B2DD0;
    }
    // 0x800B2F78: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B2F7C: bnel        $a1, $t1, L_800B2DB4
    if (ctx->r5 != ctx->r9) {
        // 0x800B2F80: mtc1        $a1, $f4
        ctx->f4.u32l = ctx->r5;
            goto L_800B2DB4;
    }
    goto skip_4;
    // 0x800B2F80: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    skip_4:
    // 0x800B2F84: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B2F88: addiu       $a0, $a0, -0x6E48
    ctx->r4 = ADD32(ctx->r4, -0X6E48);
    // 0x800B2F8C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B2F90: addiu       $t3, $t3, -0x6E58
    ctx->r11 = ADD32(ctx->r11, -0X6E58);
    // 0x800B2F94: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x800B2F98: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x800B2F9C: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800B2FA0: lui         $t7, 0x701
    ctx->r15 = S32(0X701 << 16);
    // 0x800B2FA4: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x800B2FA8: lui         $t2, 0xFD90
    ctx->r10 = S32(0XFD90 << 16);
    // 0x800B2FAC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800B2FB0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x800B2FB4: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x800B2FB8: lui         $t6, 0xF590
    ctx->r14 = S32(0XF590 << 16);
    // 0x800B2FBC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B2FC0: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800B2FC4: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x800B2FC8: lui         $t7, 0x3
    ctx->r15 = S32(0X3 << 16);
    // 0x800B2FCC: lui         $t2, 0x707
    ctx->r10 = S32(0X707 << 16);
    // 0x800B2FD0: lui         $t4, 0xF588
    ctx->r12 = S32(0XF588 << 16);
    // 0x800B2FD4: addiu       $v1, $v1, -0x6E60
    ctx->r3 = ADD32(ctx->r3, -0X6E60);
    // 0x800B2FD8: ori         $t4, $t4, 0x400
    ctx->r12 = ctx->r12 | 0X400;
    // 0x800B2FDC: ori         $t2, $t2, 0xF400
    ctx->r10 = ctx->r10 | 0XF400;
    // 0x800B2FE0: ori         $t7, $t7, 0xC03C
    ctx->r15 = ctx->r15 | 0XC03C;
    // 0x800B2FE4: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x800B2FE8: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800B2FEC: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800B2FF0: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800B2FF4: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x800B2FF8: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800B2FFC: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x800B3000: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x800B3004: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x800B3008: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x800B300C: sw          $t9, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r25;
    // 0x800B3010: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x800B3014: sw          $t3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r11;
    // 0x800B3018: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x800B301C: sw          $t5, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r13;
    // 0x800B3020: sw          $t7, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r15;
    // 0x800B3024: sw          $t2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r10;
    // 0x800B3028: sw          $t4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r12;
    // 0x800B302C: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800B3030: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x800B3034: jr          $ra
    // 0x800B3038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B3038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void func_800B303C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B303C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B3040: lw          $t6, -0x6E00($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6E00);
    // 0x800B3044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B304C: beql        $t6, $zero, L_800B3068
    if (ctx->r14 == 0) {
        // 0x800B3050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B3068;
    }
    goto skip_0;
    // 0x800B3050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B3054: jal         0x800B2D60
    // 0x800B3058: nop

    func_800B2D60(rdram, ctx);
        goto after_0;
    // 0x800B3058: nop

    after_0:
    // 0x800B305C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3060: sw          $zero, -0x6E00($at)
    MEM_W(-0X6E00, ctx->r1) = 0;
    // 0x800B3064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B3068:
    // 0x800B3068: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B306C: addiu       $v0, $v0, -0x6E60
    ctx->r2 = ADD32(ctx->r2, -0X6E60);
    // 0x800B3070: jr          $ra
    // 0x800B3074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B3074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3078: nop

    // 0x800B307C: nop

;}

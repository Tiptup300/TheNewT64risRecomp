#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Stopwatch_Create(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A939C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A93A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A93A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A93A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A93AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A93B0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800A93B4: jal         0x8007E03C
    // 0x800A93B8: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800A93B8: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    after_0:
    // 0x800A93BC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A93C0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800A93C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A93C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800A93CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A93D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800A93D4:
    // 0x800A93D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A93D8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800A93DC: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x800A93E0: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x800A93E4: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x800A93E8: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x800A93EC: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x800A93F0: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x800A93F4: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x800A93F8: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x800A93FC: sh          $zero, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = 0;
    // 0x800A9400: sw          $t9, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r25;
    // 0x800A9404: sw          $t8, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r24;
    // 0x800A9408: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800A940C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800A9410: sh          $zero, 0x28($v1)
    MEM_H(0X28, ctx->r3) = 0;
    // 0x800A9414: sw          $t3, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r11;
    // 0x800A9418: sw          $t2, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r10;
    // 0x800A941C: sw          $t5, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r13;
    // 0x800A9420: bne         $a0, $a1, L_800A93D4
    if (ctx->r4 != ctx->r5) {
        // 0x800A9424: sw          $t4, 0x38($v1)
        MEM_W(0X38, ctx->r3) = ctx->r12;
            goto L_800A93D4;
    }
    // 0x800A9424: sw          $t4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r12;
    // 0x800A9428: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x800A942C: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x800A9430: sb          $zero, 0x38($v0)
    MEM_B(0X38, ctx->r2) = 0;
    // 0x800A9434: sb          $zero, 0x39($v0)
    MEM_B(0X39, ctx->r2) = 0;
    // 0x800A9438: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x800A943C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800A9440: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A9444: sb          $t7, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r15;
    // 0x800A9448: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800A944C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800A9450: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800A9454: sb          $t6, 0x71($v0)
    MEM_B(0X71, ctx->r2) = ctx->r14;
    // 0x800A9458: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x800A945C: sb          $t8, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r24;
    // 0x800A9460: lw          $t9, 0x7AF0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7AF0);
    // 0x800A9464: bne         $t9, $zero, L_800A947C
    if (ctx->r25 != 0) {
        // 0x800A9468: nop
    
            goto L_800A947C;
    }
    // 0x800A9468: nop

    // 0x800A946C: sw          $v0, 0x7AF0($at)
    MEM_W(0X7AF0, ctx->r1) = ctx->r2;
    // 0x800A9470: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A9474: b           L_800A948C
    // 0x800A9478: sw          $v0, 0x7AF4($at)
    MEM_W(0X7AF4, ctx->r1) = ctx->r2;
        goto L_800A948C;
    // 0x800A9478: sw          $v0, 0x7AF4($at)
    MEM_W(0X7AF4, ctx->r1) = ctx->r2;
L_800A947C:
    // 0x800A947C: lw          $t0, 0x7AF4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7AF4);
    // 0x800A9480: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A9484: sw          $v0, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r2;
    // 0x800A9488: sw          $v0, 0x7AF4($at)
    MEM_W(0X7AF4, ctx->r1) = ctx->r2;
L_800A948C:
    // 0x800A948C: lw          $t1, 0x7AF4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7AF4);
    // 0x800A9490: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800A9494: sw          $zero, 0x74($t1)
    MEM_W(0X74, ctx->r9) = 0;
    // 0x800A9498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A949C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A94A0: jr          $ra
    // 0x800A94A4: nop

    return;
    // 0x800A94A4: nop

;}

RECOMP_FUNC void Stopwatch_StartCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A94A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A94AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A94B0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A94B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A94B8: bnel        $t6, $at, L_800A950C
    if (ctx->r14 != ctx->r1) {
        // 0x800A94BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A950C;
    }
    goto skip_0;
    // 0x800A94BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A94C0: jal         0x800B6540
    // 0x800A94C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x800A94C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A94C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A94CC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x800A94D0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800A94D4: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800A94D8: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A94DC: mflo        $t0
    ctx->r8 = lo;
    // 0x800A94E0: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800A94E4: sw          $t8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r24;
    // 0x800A94E8: sw          $v0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r2;
    // 0x800A94EC: lbu         $t2, 0x4($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X4);
    // 0x800A94F0: multu       $t2, $a1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A94F4: mflo        $t3
    ctx->r11 = lo;
    // 0x800A94F8: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
    // 0x800A94FC: lhu         $t4, 0x8($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X8);
    // 0x800A9500: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x800A9504: sh          $t5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r13;
    // 0x800A9508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A950C:
    // 0x800A950C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9510: jr          $ra
    // 0x800A9514: nop

    return;
    // 0x800A9514: nop

;}

RECOMP_FUNC void Stopwatch_StopCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A951C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9520: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A9524: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9528: bnel        $t6, $at, L_800A9580
    if (ctx->r14 != ctx->r1) {
        // 0x800A952C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A9580;
    }
    goto skip_0;
    // 0x800A952C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A9530: jal         0x800B6540
    // 0x800A9534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x800A9534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A9538: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A953C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x800A9540: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800A9544: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800A9548: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A954C: mflo        $t0
    ctx->r8 = lo;
    // 0x800A9550: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800A9554: sw          $t8, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r24;
    // 0x800A9558: sw          $v0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r2;
    // 0x800A955C: lbu         $t2, 0x4($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X4);
    // 0x800A9560: multu       $t2, $a1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9564: mflo        $t3
    ctx->r11 = lo;
    // 0x800A9568: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
    // 0x800A956C: lhu         $t4, 0x8($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X8);
    // 0x800A9570: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x800A9574: jal         0x800A9854
    // 0x800A9578: sh          $t5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r13;
    Stopwatch_AdvanceSampleIndex(rdram, ctx);
        goto after_1;
    // 0x800A9578: sh          $t5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r13;
    after_1:
    // 0x800A957C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9580:
    // 0x800A9580: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9584: jr          $ra
    // 0x800A9588: nop

    return;
    // 0x800A9588: nop

;}

RECOMP_FUNC void Stopwatch_StartTime(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A958C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A9590: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9594: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A9598: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A959C: bnel        $t6, $at, L_800A95EC
    if (ctx->r14 != ctx->r1) {
        // 0x800A95A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A95EC;
    }
    goto skip_0;
    // 0x800A95A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A95A4: jal         0x800B6550
    // 0x800A95A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x800A95A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A95AC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800A95B0: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x800A95B4: lbu         $t7, 0x4($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X4);
    // 0x800A95B8: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A95BC: mflo        $t8
    ctx->r24 = lo;
    // 0x800A95C0: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800A95C4: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
    // 0x800A95C8: sw          $v1, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r3;
    // 0x800A95CC: lbu         $t0, 0x4($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X4);
    // 0x800A95D0: multu       $t0, $a2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A95D4: mflo        $t1
    ctx->r9 = lo;
    // 0x800A95D8: addu        $a0, $a1, $t1
    ctx->r4 = ADD32(ctx->r5, ctx->r9);
    // 0x800A95DC: lhu         $t2, 0x8($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X8);
    // 0x800A95E0: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x800A95E4: sh          $t3, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r11;
    // 0x800A95E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A95EC:
    // 0x800A95EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A95F0: jr          $ra
    // 0x800A95F4: nop

    return;
    // 0x800A95F4: nop

;}

RECOMP_FUNC void Stopwatch_StopTime(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A95F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A95FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9600: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A9604: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9608: bnel        $t6, $at, L_800A965C
    if (ctx->r14 != ctx->r1) {
        // 0x800A960C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A965C;
    }
    goto skip_0;
    // 0x800A960C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A9610: jal         0x800B6550
    // 0x800A9614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x800A9614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A9618: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A961C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x800A9620: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800A9624: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9628: mflo        $t8
    ctx->r24 = lo;
    // 0x800A962C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800A9630: sw          $v0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r2;
    // 0x800A9634: sw          $v1, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r3;
    // 0x800A9638: lbu         $t0, 0x4($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X4);
    // 0x800A963C: multu       $t0, $a2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9640: mflo        $t1
    ctx->r9 = lo;
    // 0x800A9644: addu        $a1, $a0, $t1
    ctx->r5 = ADD32(ctx->r4, ctx->r9);
    // 0x800A9648: lhu         $t2, 0x8($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0X8);
    // 0x800A964C: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x800A9650: jal         0x800A9854
    // 0x800A9654: sh          $t3, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r11;
    Stopwatch_AdvanceSampleIndex(rdram, ctx);
        goto after_1;
    // 0x800A9654: sh          $t3, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r11;
    after_1:
    // 0x800A9658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A965C:
    // 0x800A965C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9660: jr          $ra
    // 0x800A9664: nop

    return;
    // 0x800A9664: nop

;}

RECOMP_FUNC void Stopwatch_RecordTimeInterval(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9668: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A966C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9670: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A9674: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800A9678: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A967C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9680: bnel        $t6, $at, L_800A96E8
    if (ctx->r14 != ctx->r1) {
        // 0x800A9684: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A96E8;
    }
    goto skip_0;
    // 0x800A9684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A9688: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800A968C: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800A9690: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9694: mflo        $t0
    ctx->r8 = lo;
    // 0x800A9698: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800A969C: sw          $a2, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r6;
    // 0x800A96A0: sw          $a3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r7;
    // 0x800A96A4: lbu         $t4, 0x4($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X4);
    // 0x800A96A8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800A96AC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800A96B0: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A96B4: mflo        $t5
    ctx->r13 = lo;
    // 0x800A96B8: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x800A96BC: sw          $t3, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r11;
    // 0x800A96C0: sw          $t2, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r10;
    // 0x800A96C4: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800A96C8: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A96CC: mflo        $t0
    ctx->r8 = lo;
    // 0x800A96D0: addu        $v0, $a0, $t0
    ctx->r2 = ADD32(ctx->r4, ctx->r8);
    // 0x800A96D4: lhu         $t8, 0x8($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X8);
    // 0x800A96D8: ori         $t9, $t8, 0x3
    ctx->r25 = ctx->r24 | 0X3;
    // 0x800A96DC: jal         0x800A9854
    // 0x800A96E0: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    Stopwatch_AdvanceSampleIndex(rdram, ctx);
        goto after_0;
    // 0x800A96E0: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    after_0:
    // 0x800A96E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A96E8:
    // 0x800A96E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A96EC: jr          $ra
    // 0x800A96F0: nop

    return;
    // 0x800A96F0: nop

;}

RECOMP_FUNC void Stopwatch_RecordValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A96F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A96F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A96FC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A9700: bnel        $t6, $zero, L_800A974C
    if (ctx->r14 != 0) {
        // 0x800A9704: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A974C;
    }
    goto skip_0;
    // 0x800A9704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A9708: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800A970C: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800A9710: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800A9714: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9718: mflo        $t0
    ctx->r8 = lo;
    // 0x800A971C: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800A9720: sw          $t8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r24;
    // 0x800A9724: sw          $a1, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r5;
    // 0x800A9728: lbu         $t2, 0x4($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X4);
    // 0x800A972C: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9730: mflo        $t3
    ctx->r11 = lo;
    // 0x800A9734: addu        $v0, $a0, $t3
    ctx->r2 = ADD32(ctx->r4, ctx->r11);
    // 0x800A9738: lhu         $t4, 0x8($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X8);
    // 0x800A973C: ori         $t5, $t4, 0x3
    ctx->r13 = ctx->r12 | 0X3;
    // 0x800A9740: jal         0x800A9854
    // 0x800A9744: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    Stopwatch_AdvanceSampleIndex(rdram, ctx);
        goto after_0;
    // 0x800A9744: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    after_0:
    // 0x800A9748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A974C:
    // 0x800A974C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9750: jr          $ra
    // 0x800A9754: nop

    return;
    // 0x800A9754: nop

;}

RECOMP_FUNC void Stopwatch_CollectSamples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9758: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A975C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A9760: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800A9764: lw          $s0, 0x7AF0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7AF0);
    // 0x800A9768: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A976C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A9770: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800A9774: beq         $s0, $zero, L_800A9838
    if (ctx->r16 == 0) {
        // 0x800A9778: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_800A9838;
    }
    // 0x800A9778: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A977C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800A9780: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x800A9784: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // 0x800A9788: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
L_800A978C:
    // 0x800A978C: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9790: mflo        $t7
    ctx->r15 = lo;
    // 0x800A9794: addu        $v0, $s0, $t7
    ctx->r2 = ADD32(ctx->r16, ctx->r15);
    // 0x800A9798: lhu         $t8, 0x8($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X8);
    // 0x800A979C: bnel        $s2, $t8, L_800A9830
    if (ctx->r18 != ctx->r24) {
        // 0x800A97A0: lw          $s0, 0x74($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X74);
            goto L_800A9830;
    }
    goto skip_0;
    // 0x800A97A0: lw          $s0, 0x74($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x800A97A4: lbu         $t9, 0x38($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X38);
    // 0x800A97A8: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x800A97AC: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x800A97B0: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A97B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A97B8: mflo        $t2
    ctx->r10 = lo;
    // 0x800A97BC: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800A97C0: sw          $t0, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->r8;
    // 0x800A97C4: sw          $t1, 0x4C($t3)
    MEM_W(0X4C, ctx->r11) = ctx->r9;
    // 0x800A97C8: lbu         $t4, 0x5($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X5);
    // 0x800A97CC: lbu         $t7, 0x38($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X38);
    // 0x800A97D0: multu       $t4, $s1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A97D4: mflo        $t5
    ctx->r13 = lo;
    // 0x800A97D8: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800A97DC: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x800A97E0: multu       $t7, $s1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A97E4: lw          $t9, 0x1C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X1C);
    // 0x800A97E8: mflo        $t2
    ctx->r10 = lo;
    // 0x800A97EC: addu        $t0, $s0, $t2
    ctx->r8 = ADD32(ctx->r16, ctx->r10);
    // 0x800A97F0: sw          $t8, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->r24;
    // 0x800A97F4: sw          $t9, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r25;
    // 0x800A97F8: lbu         $t1, 0x5($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X5);
    // 0x800A97FC: multu       $t1, $s1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9800: mflo        $t3
    ctx->r11 = lo;
    // 0x800A9804: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x800A9808: sh          $zero, 0x8($t4)
    MEM_H(0X8, ctx->r12) = 0;
    // 0x800A980C: lbu         $t5, 0x38($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X38);
    // 0x800A9810: multu       $t5, $s1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9814: mflo        $t6
    ctx->r14 = lo;
    // 0x800A9818: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800A981C: jal         0x800A9878
    // 0x800A9820: sh          $s3, 0x40($t7)
    MEM_H(0X40, ctx->r15) = ctx->r19;
    Stopwatch_AdvanceSampleReadIndex(rdram, ctx);
        goto after_0;
    // 0x800A9820: sh          $s3, 0x40($t7)
    MEM_H(0X40, ctx->r15) = ctx->r19;
    after_0:
    // 0x800A9824: jal         0x800A989C
    // 0x800A9828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Stopwatch_AdvanceHistoryWriteIndex(rdram, ctx);
        goto after_1;
    // 0x800A9828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A982C: lw          $s0, 0x74($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X74);
L_800A9830:
    // 0x800A9830: bnel        $s0, $zero, L_800A978C
    if (ctx->r16 != 0) {
        // 0x800A9834: lbu         $t6, 0x5($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X5);
            goto L_800A978C;
    }
    goto skip_1;
    // 0x800A9834: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
    skip_1:
L_800A9838:
    // 0x800A9838: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A983C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A9840: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A9844: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9848: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800A984C: jr          $ra
    // 0x800A9850: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A9850: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Stopwatch_AdvanceSampleIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9854: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x800A9858: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A985C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A9860: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800A9864: bne         $t8, $at, L_800A9870
    if (ctx->r24 != ctx->r1) {
        // 0x800A9868: sb          $t7, 0x4($a0)
        MEM_B(0X4, ctx->r4) = ctx->r15;
            goto L_800A9870;
    }
    // 0x800A9868: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
    // 0x800A986C: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
L_800A9870:
    // 0x800A9870: jr          $ra
    // 0x800A9874: nop

    return;
    // 0x800A9874: nop

;}

RECOMP_FUNC void Stopwatch_AdvanceSampleReadIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9878: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x800A987C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9880: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A9884: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800A9888: bne         $t8, $at, L_800A9894
    if (ctx->r24 != ctx->r1) {
        // 0x800A988C: sb          $t7, 0x5($a0)
        MEM_B(0X5, ctx->r4) = ctx->r15;
            goto L_800A9894;
    }
    // 0x800A988C: sb          $t7, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r15;
    // 0x800A9890: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
L_800A9894:
    // 0x800A9894: jr          $ra
    // 0x800A9898: nop

    return;
    // 0x800A9898: nop

;}

RECOMP_FUNC void Stopwatch_AdvanceHistoryWriteIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A989C: lbu         $t6, 0x38($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X38);
    // 0x800A98A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A98A4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A98A8: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800A98AC: bne         $t8, $at, L_800A98B8
    if (ctx->r24 != ctx->r1) {
        // 0x800A98B0: sb          $t7, 0x38($a0)
        MEM_B(0X38, ctx->r4) = ctx->r15;
            goto L_800A98B8;
    }
    // 0x800A98B0: sb          $t7, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r15;
    // 0x800A98B4: sb          $zero, 0x38($a0)
    MEM_B(0X38, ctx->r4) = 0;
L_800A98B8:
    // 0x800A98B8: jr          $ra
    // 0x800A98BC: nop

    return;
    // 0x800A98BC: nop

;}

RECOMP_FUNC void Stopwatch_AdvanceHistoryReadIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A98C0: lbu         $t6, 0x39($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X39);
    // 0x800A98C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A98C8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A98CC: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800A98D0: bne         $t8, $at, L_800A98DC
    if (ctx->r24 != ctx->r1) {
        // 0x800A98D4: sb          $t7, 0x39($a0)
        MEM_B(0X39, ctx->r4) = ctx->r15;
            goto L_800A98DC;
    }
    // 0x800A98D4: sb          $t7, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r15;
    // 0x800A98D8: sb          $zero, 0x39($a0)
    MEM_B(0X39, ctx->r4) = 0;
L_800A98DC:
    // 0x800A98DC: jr          $ra
    // 0x800A98E0: nop

    return;
    // 0x800A98E0: nop

;}

RECOMP_FUNC void Stopwatch_FormatReport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A98E4: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x800A98E8: sdc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X58, ctx->r29);
    // 0x800A98EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A98F0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800A98F4: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800A98F8: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x800A98FC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800A9900: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800A9904: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800A9908: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x800A990C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A9910: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A9914: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A9918: addiu       $t2, $zero, 0x85
    ctx->r10 = ADD32(0, 0X85);
    // 0x800A991C: sw          $s5, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r21;
    // 0x800A9920: sw          $s4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r20;
    // 0x800A9924: sw          $s3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r19;
    // 0x800A9928: sw          $s2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r18;
    // 0x800A992C: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    // 0x800A9930: sw          $s0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r16;
    // 0x800A9934: sdc1        $f30, 0x60($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X60, ctx->r29);
    // 0x800A9938: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x800A993C: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x800A9940: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x800A9944: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800A9948: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800A994C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800A9950: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A9954: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800A9958: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800A995C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A9960: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A9964: addiu       $a2, $a2, 0x6228
    ctx->r6 = ADD32(ctx->r6, 0X6228);
    // 0x800A9968: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x800A996C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A9970: addiu       $a3, $zero, 0x120
    ctx->r7 = ADD32(0, 0X120);
    // 0x800A9974: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x800A9978: jal         0x800B1BFC
    // 0x800A997C: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    Minos_BuildTiledQuadDL(rdram, ctx);
        goto after_0;
    // 0x800A997C: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    after_0:
    // 0x800A9980: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A9984: lw          $v1, 0x7AF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7AF0);
    // 0x800A9988: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800A998C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A9990: addiu       $s2, $zero, 0xD9
    ctx->r18 = ADD32(0, 0XD9);
    // 0x800A9994: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x800A9998: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x800A999C: beq         $v1, $zero, L_800A9A2C
    if (ctx->r3 == 0) {
        // 0x800A99A0: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_800A9A2C;
    }
    // 0x800A99A0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800A99A4: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800A99A8: addiu       $s3, $zero, 0x18
    ctx->r19 = ADD32(0, 0X18);
    // 0x800A99AC: lbu         $v0, 0x39($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X39);
L_800A99B0:
    // 0x800A99B0: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A99B4: mflo        $t3
    ctx->r11 = lo;
    // 0x800A99B8: addu        $s0, $s1, $t3
    ctx->r16 = ADD32(ctx->r17, ctx->r11);
    // 0x800A99BC: lhu         $t6, 0x40($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X40);
    // 0x800A99C0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800A99C4: beql        $t7, $zero, L_800A9A20
    if (ctx->r15 == 0) {
        // 0x800A99C8: lw          $s1, 0x74($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X74);
            goto L_800A9A20;
    }
    goto skip_0;
    // 0x800A99C8: lw          $s1, 0x74($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X74);
    skip_0:
    // 0x800A99CC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800A99D0: bnel        $s4, $t8, L_800A9A20
    if (ctx->r20 != ctx->r24) {
        // 0x800A99D4: lw          $s1, 0x74($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X74);
            goto L_800A9A20;
    }
    goto skip_1;
    // 0x800A99D4: lw          $s1, 0x74($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X74);
    skip_1:
    // 0x800A99D8: lw          $t0, 0x48($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X48);
    // 0x800A99DC: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x800A99E0: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x800A99E4: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A99E8: sltu        $at, $t4, $t0
    ctx->r1 = ctx->r12 < ctx->r8 ? 1 : 0;
    // 0x800A99EC: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    // 0x800A99F0: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x800A99F4: sw          $t1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r9;
    // 0x800A99F8: bne         $at, $zero, L_800A9A1C
    if (ctx->r1 != 0) {
        // 0x800A99FC: or          $t3, $t1, $zero
        ctx->r11 = ctx->r9 | 0;
            goto L_800A9A1C;
    }
    // 0x800A99FC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
    // 0x800A9A00: sltu        $at, $t0, $t4
    ctx->r1 = ctx->r8 < ctx->r12 ? 1 : 0;
    // 0x800A9A04: bne         $at, $zero, L_800A9A14
    if (ctx->r1 != 0) {
        // 0x800A9A08: sltu        $at, $t1, $t5
        ctx->r1 = ctx->r9 < ctx->r13 ? 1 : 0;
            goto L_800A9A14;
    }
    // 0x800A9A08: sltu        $at, $t1, $t5
    ctx->r1 = ctx->r9 < ctx->r13 ? 1 : 0;
    // 0x800A9A0C: beql        $at, $zero, L_800A9A20
    if (ctx->r1 == 0) {
        // 0x800A9A10: lw          $s1, 0x74($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X74);
            goto L_800A9A20;
    }
    goto skip_2;
    // 0x800A9A10: lw          $s1, 0x74($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X74);
    skip_2:
L_800A9A14:
    // 0x800A9A14: sw          $t2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r10;
    // 0x800A9A18: sw          $t3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r11;
L_800A9A1C:
    // 0x800A9A1C: lw          $s1, 0x74($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X74);
L_800A9A20:
    // 0x800A9A20: bnel        $s1, $zero, L_800A99B0
    if (ctx->r17 != 0) {
        // 0x800A9A24: lbu         $v0, 0x39($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X39);
            goto L_800A99B0;
    }
    goto skip_3;
    // 0x800A9A24: lbu         $v0, 0x39($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X39);
    skip_3:
    // 0x800A9A28: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800A9A2C:
    // 0x800A9A2C: addiu       $s3, $zero, 0x18
    ctx->r19 = ADD32(0, 0X18);
    // 0x800A9A30: beq         $s1, $zero, L_800A9D08
    if (ctx->r17 == 0) {
        // 0x800A9A34: addiu       $s4, $zero, 0x2
        ctx->r20 = ADD32(0, 0X2);
            goto L_800A9D08;
    }
    // 0x800A9A34: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800A9A38: beq         $s2, $zero, L_800A9D08
    if (ctx->r18 == 0) {
        // 0x800A9A3C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800A9D08;
    }
    // 0x800A9A3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A9A40: ldc1        $f30, 0xA60($at)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r1, 0XA60);
    // 0x800A9A44: lui         $at, 0x4390
    ctx->r1 = S32(0X4390 << 16);
    // 0x800A9A48: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800A9A4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A9A50: ldc1        $f24, 0xA68($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, 0XA68);
    // 0x800A9A54: lwc1        $f22, 0xB8($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800A9A58: lwc1        $f20, 0xBC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800A9A5C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800A9A60: lbu         $v0, 0x39($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X39);
L_800A9A64:
    // 0x800A9A64: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9A68: mflo        $t9
    ctx->r25 = lo;
    // 0x800A9A6C: addu        $s0, $s1, $t9
    ctx->r16 = ADD32(ctx->r17, ctx->r25);
    // 0x800A9A70: lhu         $t6, 0x40($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X40);
    // 0x800A9A74: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800A9A78: beql        $t7, $zero, L_800A9CF0
    if (ctx->r15 == 0) {
        // 0x800A9A7C: lw          $s1, 0x74($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X74);
            goto L_800A9CF0;
    }
    goto skip_4;
    // 0x800A9A7C: lw          $s1, 0x74($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X74);
    skip_4:
    // 0x800A9A80: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A9A84: beql        $v0, $zero, L_800A9AA8
    if (ctx->r2 == 0) {
        // 0x800A9A88: lw          $a0, 0x48($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X48);
            goto L_800A9AA8;
    }
    goto skip_5;
    // 0x800A9A88: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    skip_5:
    // 0x800A9A8C: beql        $v0, $s5, L_800A9AD0
    if (ctx->r2 == ctx->r21) {
        // 0x800A9A90: lw          $t8, 0x50($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X50);
            goto L_800A9AD0;
    }
    goto skip_6;
    // 0x800A9A90: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    skip_6:
    // 0x800A9A94: beq         $v0, $s4, L_800A9B24
    if (ctx->r2 == ctx->r20) {
        // 0x800A9A98: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_800A9B24;
    }
    // 0x800A9A98: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A9A9C: b           L_800A9BDC
    // 0x800A9AA0: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
        goto L_800A9BDC;
    // 0x800A9AA0: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    // 0x800A9AA4: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
L_800A9AA8:
    // 0x800A9AA8: jal         0x800BAF34
    // 0x800A9AAC: lw          $a1, 0x4C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4C);
    __ull_to_d_recomp(rdram, ctx);
        goto after_1;
    // 0x800A9AAC: lw          $a1, 0x4C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4C);
    after_1:
    // 0x800A9AB0: lui         $at, 0x4050
    ctx->r1 = S32(0X4050 << 16);
    // 0x800A9AB4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A9AB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A9ABC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800A9AC0: mul.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800A9AC4: b           L_800A9BD8
    // 0x800A9AC8: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
        goto L_800A9BD8;
    // 0x800A9AC8: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x800A9ACC: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
L_800A9AD0:
    // 0x800A9AD0: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x800A9AD4: lw          $t0, 0x48($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X48);
    // 0x800A9AD8: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x800A9ADC: subu        $t4, $t8, $t0
    ctx->r12 = SUB32(ctx->r24, ctx->r8);
    // 0x800A9AE0: sltu        $at, $t9, $t1
    ctx->r1 = ctx->r25 < ctx->r9 ? 1 : 0;
    // 0x800A9AE4: subu        $a0, $t4, $at
    ctx->r4 = SUB32(ctx->r12, ctx->r1);
    // 0x800A9AE8: subu        $a1, $t9, $t1
    ctx->r5 = SUB32(ctx->r25, ctx->r9);
    // 0x800A9AEC: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x800A9AF0: jal         0x800BAF68
    // 0x800A9AF4: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    __ull_to_f_recomp(rdram, ctx);
        goto after_2;
    // 0x800A9AF4: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    after_2:
    // 0x800A9AF8: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800A9AFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A9B00: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800A9B04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A9B08: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800A9B0C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800A9B10: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A9B14: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800A9B18: div.d       $f6, $f4, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f30.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f30.d);
    // 0x800A9B1C: b           L_800A9BD8
    // 0x800A9B20: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
        goto L_800A9BD8;
    // 0x800A9B20: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
L_800A9B24:
    // 0x800A9B24: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x800A9B28: lw          $t3, 0x54($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X54);
    // 0x800A9B2C: lw          $t6, 0x48($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X48);
    // 0x800A9B30: lw          $t7, 0x4C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4C);
    // 0x800A9B34: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x800A9B38: subu        $t8, $t2, $t6
    ctx->r24 = SUB32(ctx->r10, ctx->r14);
    // 0x800A9B3C: sltu        $at, $t3, $t7
    ctx->r1 = ctx->r11 < ctx->r15 ? 1 : 0;
    // 0x800A9B40: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x800A9B44: subu        $a1, $t3, $t7
    ctx->r5 = SUB32(ctx->r11, ctx->r15);
    // 0x800A9B48: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x800A9B4C: jal         0x800B7658
    // 0x800A9B50: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    __ll_mul_recomp(rdram, ctx);
        goto after_3;
    // 0x800A9B50: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    after_3:
    // 0x800A9B54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A9B58: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800A9B5C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A9B60: jal         0x800B7558
    // 0x800A9B64: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    __ull_div_recomp(rdram, ctx);
        goto after_4;
    // 0x800A9B64: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_4:
    // 0x800A9B68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A9B6C: jal         0x800BAF34
    // 0x800A9B70: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_to_d_recomp(rdram, ctx);
        goto after_5;
    // 0x800A9B70: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_5:
    // 0x800A9B74: mul.d       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f24.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f24.d);
    // 0x800A9B78: lw          $t0, 0x48($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X48);
    // 0x800A9B7C: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x800A9B80: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x800A9B84: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A9B88: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A9B8C: subu        $t2, $t0, $t4
    ctx->r10 = SUB32(ctx->r8, ctx->r12);
    // 0x800A9B90: sltu        $at, $t1, $t5
    ctx->r1 = ctx->r9 < ctx->r13 ? 1 : 0;
    // 0x800A9B94: subu        $a0, $t2, $at
    ctx->r4 = SUB32(ctx->r10, ctx->r1);
    // 0x800A9B98: subu        $a1, $t1, $t5
    ctx->r5 = SUB32(ctx->r9, ctx->r13);
    // 0x800A9B9C: cvt.s.d     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f20.fl = CVT_S_D(ctx->f8.d);
    // 0x800A9BA0: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x800A9BA4: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x800A9BA8: jal         0x800B7658
    // 0x800A9BAC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_6;
    // 0x800A9BAC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_6:
    // 0x800A9BB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A9BB4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800A9BB8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A9BBC: jal         0x800B7558
    // 0x800A9BC0: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    __ull_div_recomp(rdram, ctx);
        goto after_7;
    // 0x800A9BC0: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_7:
    // 0x800A9BC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A9BC8: jal         0x800BAF34
    // 0x800A9BCC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_to_d_recomp(rdram, ctx);
        goto after_8;
    // 0x800A9BCC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_8:
    // 0x800A9BD0: mul.d       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f24.d);
    // 0x800A9BD4: cvt.s.d     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f22.fl = CVT_S_D(ctx->f10.d);
L_800A9BD8:
    // 0x800A9BD8: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
L_800A9BDC:
    // 0x800A9BDC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800A9BE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A9BE4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800A9BE8: bc1f        L_800A9BF8
    if (!c1cs) {
        // 0x800A9BEC: add.s       $f22, $f22, $f16
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
            goto L_800A9BF8;
    }
    // 0x800A9BEC: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x800A9BF0: b           L_800A9C0C
    // 0x800A9BF4: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
        goto L_800A9C0C;
    // 0x800A9BF4: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
L_800A9BF8:
    // 0x800A9BF8: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    // 0x800A9BFC: nop

    // 0x800A9C00: bc1fl       L_800A9C10
    if (!c1cs) {
        // 0x800A9C04: div.s       $f18, $f20, $f26
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f26.fl);
            goto L_800A9C10;
    }
    goto skip_7;
    // 0x800A9C04: div.s       $f18, $f20, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f26.fl);
    skip_7:
    // 0x800A9C08: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
L_800A9C0C:
    // 0x800A9C0C: div.s       $f18, $f20, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f26.fl);
L_800A9C10:
    // 0x800A9C10: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A9C14: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800A9C18: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800A9C1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A9C20: addiu       $a2, $a2, 0x7430
    ctx->r6 = ADD32(ctx->r6, 0X7430);
    // 0x800A9C24: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x800A9C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A9C2C: addiu       $a3, $zero, 0x120
    ctx->r7 = ADD32(0, 0X120);
    // 0x800A9C30: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    // 0x800A9C34: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A9C38: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A9C3C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800A9C40: cvt.w.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    ctx->f4.u32l = CVT_W_S(ctx->f22.fl);
    // 0x800A9C44: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A9C48: nop

    // 0x800A9C4C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800A9C50: beql        $t8, $zero, L_800A9CA0
    if (ctx->r24 == 0) {
        // 0x800A9C54: mfc1        $t8, $f4
        ctx->r24 = (int32_t)ctx->f4.u32l;
            goto L_800A9CA0;
    }
    goto skip_8;
    // 0x800A9C54: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    skip_8:
    // 0x800A9C58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A9C5C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A9C60: sub.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f4.fl;
    // 0x800A9C64: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A9C68: nop

    // 0x800A9C6C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9C70: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A9C74: nop

    // 0x800A9C78: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800A9C7C: bne         $t8, $zero, L_800A9C94
    if (ctx->r24 != 0) {
        // 0x800A9C80: nop
    
            goto L_800A9C94;
    }
    // 0x800A9C80: nop

    // 0x800A9C84: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800A9C88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A9C8C: b           L_800A9CAC
    // 0x800A9C90: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800A9CAC;
    // 0x800A9C90: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800A9C94:
    // 0x800A9C94: b           L_800A9CAC
    // 0x800A9C98: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800A9CAC;
    // 0x800A9C98: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800A9C9C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
L_800A9CA0:
    // 0x800A9CA0: nop

    // 0x800A9CA4: bltz        $t8, L_800A9C94
    if (SIGNED(ctx->r24) < 0) {
        // 0x800A9CA8: nop
    
            goto L_800A9C94;
    }
    // 0x800A9CA8: nop

L_800A9CAC:
    // 0x800A9CAC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800A9CB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A9CB4: lbu         $t9, 0x70($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X70);
    // 0x800A9CB8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A9CBC: addiu       $t4, $zero, 0x85
    ctx->r12 = ADD32(0, 0X85);
    // 0x800A9CC0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800A9CC4: lbu         $t0, 0x71($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X71);
    // 0x800A9CC8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A9CCC: lbu         $t1, 0x72($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X72);
    // 0x800A9CD0: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x800A9CD4: jal         0x800B1BFC
    // 0x800A9CD8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    Minos_BuildTiledQuadDL(rdram, ctx);
        goto after_9;
    // 0x800A9CD8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_9:
    // 0x800A9CDC: addiu       $s2, $s2, -0x3
    ctx->r18 = ADD32(ctx->r18, -0X3);
    // 0x800A9CE0: sh          $zero, 0x40($s0)
    MEM_H(0X40, ctx->r16) = 0;
    // 0x800A9CE4: jal         0x800A98C0
    // 0x800A9CE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Stopwatch_AdvanceHistoryReadIndex(rdram, ctx);
        goto after_10;
    // 0x800A9CE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x800A9CEC: lw          $s1, 0x74($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X74);
L_800A9CF0:
    // 0x800A9CF0: beql        $s1, $zero, L_800A9D0C
    if (ctx->r17 == 0) {
        // 0x800A9CF4: lw          $ra, 0x84($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X84);
            goto L_800A9D0C;
    }
    goto skip_9;
    // 0x800A9CF4: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    skip_9:
    // 0x800A9CF8: bnel        $s2, $zero, L_800A9A64
    if (ctx->r18 != 0) {
        // 0x800A9CFC: lbu         $v0, 0x39($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X39);
            goto L_800A9A64;
    }
    goto skip_10;
    // 0x800A9CFC: lbu         $v0, 0x39($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X39);
    skip_10:
    // 0x800A9D00: swc1        $f22, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f22.u32l;
    // 0x800A9D04: swc1        $f20, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f20.u32l;
L_800A9D08:
    // 0x800A9D08: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
L_800A9D0C:
    // 0x800A9D0C: lw          $v0, 0xD8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD8);
    // 0x800A9D10: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800A9D14: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x800A9D18: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x800A9D1C: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x800A9D20: ldc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X58);
    // 0x800A9D24: ldc1        $f30, 0x60($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X60);
    // 0x800A9D28: lw          $s0, 0x6C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X6C);
    // 0x800A9D2C: lw          $s1, 0x70($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X70);
    // 0x800A9D30: lw          $s2, 0x74($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X74);
    // 0x800A9D34: lw          $s3, 0x78($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X78);
    // 0x800A9D38: lw          $s4, 0x7C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X7C);
    // 0x800A9D3C: lw          $s5, 0x80($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X80);
    // 0x800A9D40: jr          $ra
    // 0x800A9D44: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x800A9D44: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x800A9D48: nop

    // 0x800A9D4C: nop

;}

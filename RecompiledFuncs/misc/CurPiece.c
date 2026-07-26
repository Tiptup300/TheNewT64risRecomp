#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void CurPiece_SetDef(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D090: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8006D094: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8006D098: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006D09C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006D0A0: lw          $t7, 0x110($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X110);
    // 0x8006D0A4: jr          $ra
    // 0x8006D0A8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x8006D0A8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void CurPiece_GetPhysicalSpawnPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D0AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006D0B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006D0B4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8006D0B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D0BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006D0C0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8006D0C4: jal         0x80054ED0
    // 0x8006D0C8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    getCurPieceSpawnOffsetAsPoint(rdram, ctx);
        goto after_0;
    // 0x8006D0C8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8006D0CC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8006D0D0: lh          $t7, 0x1C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1C);
    // 0x8006D0D4: lbu         $t9, 0x4($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4);
    // 0x8006D0D8: lh          $t3, 0x1E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X1E);
    // 0x8006D0DC: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8006D0E0: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8006D0E4: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x8006D0E8: addiu       $t4, $t3, -0x100
    ctx->r12 = ADD32(ctx->r11, -0X100);
    // 0x8006D0EC: sh          $t2, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r10;
    // 0x8006D0F0: sh          $t4, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r12;
    // 0x8006D0F4: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x8006D0F8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8006D0FC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8006D100: nop

    // 0x8006D104: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x8006D108: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x8006D10C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D110: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8006D114: jr          $ra
    // 0x8006D118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006D118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void CurPiece_GetPhysicalRotOrigin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D11C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006D120: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006D124: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8006D128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D12C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006D130: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8006D134: jal         0x80054F08
    // 0x8006D138: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    getStartingRotOriginAsPoint(rdram, ctx);
        goto after_0;
    // 0x8006D138: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8006D13C: lh          $t7, 0x1C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1C);
    // 0x8006D140: lh          $t9, 0x1E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X1E);
    // 0x8006D144: addiu       $t8, $t7, 0x80
    ctx->r24 = ADD32(ctx->r15, 0X80);
    // 0x8006D148: addiu       $t0, $t9, 0x80
    ctx->r8 = ADD32(ctx->r25, 0X80);
    // 0x8006D14C: sh          $t8, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r24;
    // 0x8006D150: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    // 0x8006D154: addiu       $t2, $sp, 0x1C
    ctx->r10 = ADD32(ctx->r29, 0X1C);
    // 0x8006D158: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8006D15C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8006D160: nop

    // 0x8006D164: swl         $at, 0x0($t1)
    do_swl(rdram, 0X0, ctx->r9, ctx->r1);
    // 0x8006D168: swr         $at, 0x3($t1)
    do_swr(rdram, 0X3, ctx->r9, ctx->r1);
    // 0x8006D16C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D170: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8006D174: jr          $ra
    // 0x8006D178: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006D178: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void CurPiece_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D17C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8006D180: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8006D184: sb          $a1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r5;
    // 0x8006D188: sb          $a2, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r6;
    // 0x8006D18C: jr          $ra
    // 0x8006D190: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x8006D190: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}

RECOMP_FUNC void CurPiece_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D194: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x8006D198: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    // 0x8006D19C: jr          $ra
    // 0x8006D1A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x8006D1A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8006D1A4: nop

    // 0x8006D1A8: nop

    // 0x8006D1AC: nop

;}

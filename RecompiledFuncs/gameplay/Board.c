#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Board_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D1B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D1B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006D1B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006D1BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006D1C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D1C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D1C8: jal         0x8006E6F4
    // 0x8006D1CC: addiu       $a0, $a0, 0x33A8
    ctx->r4 = ADD32(ctx->r4, 0X33A8);
    BoardPieces_Update(rdram, ctx);
        goto after_0;
    // 0x8006D1CC: addiu       $a0, $a0, 0x33A8
    ctx->r4 = ADD32(ctx->r4, 0X33A8);
    after_0:
    // 0x8006D1D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D1D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D1D8: jr          $ra
    // 0x8006D1DC: nop

    return;
    // 0x8006D1DC: nop

;}

RECOMP_FUNC void Board_EmptyStub1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D1E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006D1E4: jr          $ra
    // 0x8006D1E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8006D1E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}

RECOMP_FUNC void Board_EmptyStub2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D1EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006D1F0: jr          $ra
    // 0x8006D1F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8006D1F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}

RECOMP_FUNC void Board_EmptyStub3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D1F8: jr          $ra
    // 0x8006D1FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006D1FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

RECOMP_FUNC void Board_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D204: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006D208: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006D20C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D210: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006D214: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8006D218: jal         0x8006EE34
    // 0x8006D21C: addiu       $a0, $zero, 0xDC
    ctx->r4 = ADD32(0, 0XDC);
    MobileCubes_Init(rdram, ctx);
        goto after_0;
    // 0x8006D21C: addiu       $a0, $zero, 0xDC
    ctx->r4 = ADD32(0, 0XDC);
    after_0:
    // 0x8006D220: jal         0x8006F198
    // 0x8006D224: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    FallingCubes_Init(rdram, ctx);
        goto after_1;
    // 0x8006D224: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x8006D228: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006D22C: lw          $t6, -0x420($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X420);
    // 0x8006D230: nop

    // 0x8006D234: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8006D238: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006D23C: jal         0x8006E724
    // 0x8006D240: addiu       $a0, $a0, 0x33A8
    ctx->r4 = ADD32(ctx->r4, 0X33A8);
    BoardPieces_Init(rdram, ctx);
        goto after_2;
    // 0x8006D240: addiu       $a0, $a0, 0x33A8
    ctx->r4 = ADD32(ctx->r4, 0X33A8);
    after_2:
    // 0x8006D244: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D248: jal         0x80068F10
    // 0x8006D24C: nop

    NextPieces_Init(rdram, ctx);
        goto after_3;
    // 0x8006D24C: nop

    after_3:
    // 0x8006D250: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006D254: jal         0x80068090
    // 0x8006D258: nop

    CurrentPiece_EnableGhost(rdram, ctx);
        goto after_4;
    // 0x8006D258: nop

    after_4:
    // 0x8006D25C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006D260: nop

    // 0x8006D264: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8006D268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D26C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D270: jr          $ra
    // 0x8006D274: nop

    return;
    // 0x8006D274: nop

;}

RECOMP_FUNC void Board_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D27C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D280: jal         0x80068FDC
    // 0x8006D284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    NextPieces_Deinit(rdram, ctx);
        goto after_0;
    // 0x8006D284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006D288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006D28C: jal         0x8006E86C
    // 0x8006D290: addiu       $a0, $a0, 0x33A8
    ctx->r4 = ADD32(ctx->r4, 0X33A8);
    BoardPieces_Deinit(rdram, ctx);
        goto after_1;
    // 0x8006D290: addiu       $a0, $a0, 0x33A8
    ctx->r4 = ADD32(ctx->r4, 0X33A8);
    after_1:
    // 0x8006D294: jal         0x8006F21C
    // 0x8006D298: nop

    FallingCubes_Deinit(rdram, ctx);
        goto after_2;
    // 0x8006D298: nop

    after_2:
    // 0x8006D29C: jal         0x8006EED8
    // 0x8006D2A0: nop

    MobileCubes_Deinit(rdram, ctx);
        goto after_3;
    // 0x8006D2A0: nop

    after_3:
    // 0x8006D2A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D2A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D2AC: jr          $ra
    // 0x8006D2B0: nop

    return;
    // 0x8006D2B0: nop

    // 0x8006D2B4: nop

    // 0x8006D2B8: nop

    // 0x8006D2BC: nop

;}

RECOMP_FUNC void BoardInfo_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D2C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006D2C4: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x8006D2C8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8006D2CC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8006D2D0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006D2D4: swl         $at, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, ctx->r1);
    // 0x8006D2D8: sh          $a2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r6;
    // 0x8006D2DC: jr          $ra
    // 0x8006D2E0: swr         $at, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r1);
    return;
    // 0x8006D2E0: swr         $at, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r1);
;}

RECOMP_FUNC void Board_GetSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D2E4: lh          $t6, 0x4($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X4);
    // 0x8006D2E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006D2EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006D2F0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006D2F4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006D2F8: sh          $t7, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r15;
    // 0x8006D2FC: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x8006D300: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x8006D304: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006D308: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006D30C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8006D310: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x8006D314: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8006D318: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8006D31C: swl         $at, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, ctx->r1);
    // 0x8006D320: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006D324: jr          $ra
    // 0x8006D328: swr         $at, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r1);
    return;
    // 0x8006D328: swr         $at, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r1);
;}

RECOMP_FUNC void Board_GetLocation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D32C: lwl         $at, 0x0($a1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r5, 0X0);
    // 0x8006D330: lwr         $at, 0x3($a1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r5, 0X3);
    // 0x8006D334: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006D338: swl         $at, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, ctx->r1);
    // 0x8006D33C: jr          $ra
    // 0x8006D340: swr         $at, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r1);
    return;
    // 0x8006D340: swr         $at, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r1);
;}

RECOMP_FUNC void Board_GetCenter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D344: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006D348: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006D34C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D350: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006D354: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8006D358: jal         0x8006D32C
    // 0x8006D35C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    Board_GetLocation(rdram, ctx);
        goto after_0;
    // 0x8006D35C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8006D360: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8006D364: jal         0x8006D2E4
    // 0x8006D368: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    Board_GetSize(rdram, ctx);
        goto after_1;
    // 0x8006D368: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x8006D36C: lh          $t7, 0x20($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X20);
    // 0x8006D370: lh          $t1, 0x22($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X22);
    // 0x8006D374: lh          $t6, 0x1C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1C);
    // 0x8006D378: lh          $t0, 0x1E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1E);
    // 0x8006D37C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8006D380: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8006D384: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8006D388: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8006D38C: sh          $t9, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r25;
    // 0x8006D390: sh          $t3, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r11;
    // 0x8006D394: addiu       $t5, $sp, 0x24
    ctx->r13 = ADD32(ctx->r29, 0X24);
    // 0x8006D398: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x8006D39C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8006D3A0: nop

    // 0x8006D3A4: swl         $at, 0x0($t4)
    do_swl(rdram, 0X0, ctx->r12, ctx->r1);
    // 0x8006D3A8: swr         $at, 0x3($t4)
    do_swr(rdram, 0X3, ctx->r12, ctx->r1);
    // 0x8006D3AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D3B0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8006D3B4: jr          $ra
    // 0x8006D3B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006D3B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006D3BC: nop

;}

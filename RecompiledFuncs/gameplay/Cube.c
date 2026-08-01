#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Cube_InitPosBlock0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E8B0: lw          $a3, 0x4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X4);
    // 0x8006E8B4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006E8B8: sb          $a1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r5;
    // 0x8006E8BC: beq         $a3, $zero, L_8006E8F0
    if (ctx->r7 == 0) {
        // 0x8006E8C0: sb          $a2, 0x2($a0)
        MEM_B(0X2, ctx->r4) = ctx->r6;
            goto L_8006E8F0;
    }
    // 0x8006E8C0: sb          $a2, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r6;
    // 0x8006E8C4: sll         $t6, $a1, 8
    ctx->r14 = S32(ctx->r5 << 8);
    // 0x8006E8C8: sll         $t7, $a2, 8
    ctx->r15 = S32(ctx->r6 << 8);
    // 0x8006E8CC: sh          $zero, 0x2($a3)
    MEM_H(0X2, ctx->r7) = 0;
    // 0x8006E8D0: sh          $zero, 0x4($a3)
    MEM_H(0X4, ctx->r7) = 0;
    // 0x8006E8D4: sh          $zero, 0x6($a3)
    MEM_H(0X6, ctx->r7) = 0;
    // 0x8006E8D8: sh          $t7, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r15;
    // 0x8006E8DC: sh          $t6, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r14;
    // 0x8006E8E0: sh          $zero, 0xC($a3)
    MEM_H(0XC, ctx->r7) = 0;
    // 0x8006E8E4: sh          $zero, 0xE($a3)
    MEM_H(0XE, ctx->r7) = 0;
    // 0x8006E8E8: sh          $zero, 0x10($a3)
    MEM_H(0X10, ctx->r7) = 0;
    // 0x8006E8EC: sh          $zero, 0x12($a3)
    MEM_H(0X12, ctx->r7) = 0;
L_8006E8F0:
    // 0x8006E8F0: jr          $ra
    // 0x8006E8F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006E8F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Cube_InitPosBlock1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E8F8: lw          $a3, 0x4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X4);
    // 0x8006E8FC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006E900: sb          $a1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r5;
    // 0x8006E904: beq         $a3, $zero, L_8006E938
    if (ctx->r7 == 0) {
        // 0x8006E908: sb          $a2, 0x2($a0)
        MEM_B(0X2, ctx->r4) = ctx->r6;
            goto L_8006E938;
    }
    // 0x8006E908: sb          $a2, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r6;
    // 0x8006E90C: sll         $t6, $a1, 8
    ctx->r14 = S32(ctx->r5 << 8);
    // 0x8006E910: sll         $t7, $a2, 8
    ctx->r15 = S32(ctx->r6 << 8);
    // 0x8006E914: sh          $zero, 0x14($a3)
    MEM_H(0X14, ctx->r7) = 0;
    // 0x8006E918: sh          $zero, 0x16($a3)
    MEM_H(0X16, ctx->r7) = 0;
    // 0x8006E91C: sh          $zero, 0x18($a3)
    MEM_H(0X18, ctx->r7) = 0;
    // 0x8006E920: sh          $t7, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = ctx->r15;
    // 0x8006E924: sh          $t6, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r14;
    // 0x8006E928: sh          $zero, 0x1E($a3)
    MEM_H(0X1E, ctx->r7) = 0;
    // 0x8006E92C: sh          $zero, 0x20($a3)
    MEM_H(0X20, ctx->r7) = 0;
    // 0x8006E930: sh          $zero, 0x22($a3)
    MEM_H(0X22, ctx->r7) = 0;
    // 0x8006E934: sh          $zero, 0x24($a3)
    MEM_H(0X24, ctx->r7) = 0;
L_8006E938:
    // 0x8006E938: jr          $ra
    // 0x8006E93C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006E93C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Cube_Alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E948: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006E94C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006E950: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006E954: jal         0x8006ED94
    // 0x8006E958: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    MobileCubes_Alloc(rdram, ctx);
        goto after_0;
    // 0x8006E958: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8006E95C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006E960: nop

    // 0x8006E964: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    // 0x8006E968: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006E96C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006E970: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x8006E974: jal         0x80070820
    // 0x8006E978: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_Mino_SetPosition(rdram, ctx);
        goto after_1;
    // 0x8006E978: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
    // 0x8006E97C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006E980: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E984: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8006E988: jal         0x8006E8B0
    // 0x8006E98C: nop

    Cube_InitPosBlock0(rdram, ctx);
        goto after_2;
    // 0x8006E98C: nop

    after_2:
    // 0x8006E990: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006E994: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E998: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8006E99C: jal         0x8006E8F8
    // 0x8006E9A0: nop

    Cube_InitPosBlock1(rdram, ctx);
        goto after_3;
    // 0x8006E9A0: nop

    after_3:
    // 0x8006E9A4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006E9A8: nop

    // 0x8006E9AC: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x8006E9B0: jal         0x800702E4
    // 0x8006E9B4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_Mino_Init(rdram, ctx);
        goto after_4;
    // 0x8006E9B4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_4:
    // 0x8006E9B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E9BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E9C0: jr          $ra
    // 0x8006E9C4: nop

    return;
    // 0x8006E9C4: nop

;}

RECOMP_FUNC void Cube_NewCellInfo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E9C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E9CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E9D0: jal         0x8006EA18
    // 0x8006E9D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Cube_NextCellId(rdram, ctx);
        goto after_0;
    // 0x8006E9D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006E9D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006E9DC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8006E9E0: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x8006E9E4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006E9E8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8006E9EC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8006E9F0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8006E9F4: nop

    // 0x8006E9F8: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
    // 0x8006E9FC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006EA00: nop

    // 0x8006EA04: sb          $t0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r8;
    // 0x8006EA08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EA0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EA10: jr          $ra
    // 0x8006EA14: nop

    return;
    // 0x8006EA14: nop

;}

RECOMP_FUNC void Cube_NextCellId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EA18: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006EA1C: lw          $a0, -0x420($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X420);
    // 0x8006EA20: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006EA24: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x8006EA28: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8006EA2C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8006EA30: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8006EA34: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x8006EA38: jr          $ra
    // 0x8006EA3C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x8006EA3C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Pfs_InitPak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B688: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B68C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003B690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B694: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B698: sh          $zero, 0x2578($t6)
    MEM_H(0X2578, ctx->r14) = 0;
    // 0x8003B69C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8003B6A0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B6A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B6A8: sb          $t7, 0x2570($t8)
    MEM_B(0X2570, ctx->r24) = ctx->r15;
    // 0x8003B6AC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B6B0: nop

    // 0x8003B6B4: addiu       $a0, $t9, 0x1F8
    ctx->r4 = ADD32(ctx->r25, 0X1F8);
    // 0x8003B6B8: jal         0x800B34D0
    // 0x8003B6BC: addiu       $a1, $t9, 0x2570
    ctx->r5 = ADD32(ctx->r25, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B6BC: addiu       $a1, $t9, 0x2570
    ctx->r5 = ADD32(ctx->r25, 0X2570);
    after_0:
    // 0x8003B6C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B6C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B6C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B6CC: jal         0x800B3C20
    // 0x8003B6D0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B6D0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B6D4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B6DC: lw          $v0, 0x2580($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2580);
    // 0x8003B6E0: jr          $ra
    // 0x8003B6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003B6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Pfs_ReadFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B6E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B6EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B6F0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B6F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B6FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B700: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8003B704: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003B708: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003B70C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B710: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x8003B714: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B718: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003B71C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B720: nop

    // 0x8003B724: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003B728: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003B72C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B730: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003B734: nop

    // 0x8003B738: sb          $t2, 0x2571($t3)
    MEM_B(0X2571, ctx->r11) = ctx->r10;
    // 0x8003B73C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003B740: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8003B744: nop

    // 0x8003B748: sw          $t4, 0x2580($t5)
    MEM_W(0X2580, ctx->r13) = ctx->r12;
    // 0x8003B74C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B750: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8003B754: nop

    // 0x8003B758: sw          $t6, 0x2574($t7)
    MEM_W(0X2574, ctx->r15) = ctx->r14;
    // 0x8003B75C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B760: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8003B764: nop

    // 0x8003B768: sw          $t8, 0x257C($t9)
    MEM_W(0X257C, ctx->r25) = ctx->r24;
    // 0x8003B76C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B770: nop

    // 0x8003B774: addiu       $a0, $t1, 0x1F8
    ctx->r4 = ADD32(ctx->r9, 0X1F8);
    // 0x8003B778: jal         0x800B34D0
    // 0x8003B77C: addiu       $a1, $t1, 0x2570
    ctx->r5 = ADD32(ctx->r9, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B77C: addiu       $a1, $t1, 0x2570
    ctx->r5 = ADD32(ctx->r9, 0X2570);
    after_0:
    // 0x8003B780: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B788: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B78C: jal         0x800B3C20
    // 0x8003B790: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B790: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B794: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B79C: lw          $v0, 0x2580($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2580);
    // 0x8003B7A0: jr          $ra
    // 0x8003B7A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003B7A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Pfs_WriteFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B7A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B7AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B7B0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B7B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B7B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B7BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B7C0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8003B7C4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003B7C8: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003B7CC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B7D0: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x8003B7D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B7D8: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003B7DC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B7E0: nop

    // 0x8003B7E4: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003B7E8: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003B7EC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B7F0: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003B7F4: nop

    // 0x8003B7F8: sb          $t2, 0x2571($t3)
    MEM_B(0X2571, ctx->r11) = ctx->r10;
    // 0x8003B7FC: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003B800: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8003B804: nop

    // 0x8003B808: sw          $t4, 0x2580($t5)
    MEM_W(0X2580, ctx->r13) = ctx->r12;
    // 0x8003B80C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B810: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8003B814: nop

    // 0x8003B818: sw          $t6, 0x2574($t7)
    MEM_W(0X2574, ctx->r15) = ctx->r14;
    // 0x8003B81C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B820: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8003B824: nop

    // 0x8003B828: sw          $t8, 0x257C($t9)
    MEM_W(0X257C, ctx->r25) = ctx->r24;
    // 0x8003B82C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B830: nop

    // 0x8003B834: addiu       $a0, $t1, 0x1F8
    ctx->r4 = ADD32(ctx->r9, 0X1F8);
    // 0x8003B838: jal         0x800B34D0
    // 0x8003B83C: addiu       $a1, $t1, 0x2570
    ctx->r5 = ADD32(ctx->r9, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B83C: addiu       $a1, $t1, 0x2570
    ctx->r5 = ADD32(ctx->r9, 0X2570);
    after_0:
    // 0x8003B840: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B844: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B848: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B84C: jal         0x800B3C20
    // 0x8003B850: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B850: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B854: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B85C: lw          $v0, 0x2580($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2580);
    // 0x8003B860: jr          $ra
    // 0x8003B864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003B864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Pfs_AllocateFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B86C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B870: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B878: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B87C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B880: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8003B884: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003B888: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B88C: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x8003B890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B894: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003B898: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B89C: nop

    // 0x8003B8A0: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003B8A4: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003B8A8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B8AC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B8B0: nop

    // 0x8003B8B4: sw          $t2, 0x2588($t3)
    MEM_W(0X2588, ctx->r11) = ctx->r10;
    // 0x8003B8B8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003B8BC: nop

    // 0x8003B8C0: addiu       $a0, $t4, 0x1F8
    ctx->r4 = ADD32(ctx->r12, 0X1F8);
    // 0x8003B8C4: jal         0x800B34D0
    // 0x8003B8C8: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B8C8: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    after_0:
    // 0x8003B8CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B8D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B8D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B8D8: jal         0x800B3C20
    // 0x8003B8DC: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B8DC: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B8E0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003B8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B8E8: lw          $v0, 0x2580($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2580);
    // 0x8003B8EC: jr          $ra
    // 0x8003B8F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003B8F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Pfs_FindFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B8F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B8F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B8FC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B900: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B904: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B908: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B90C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8003B910: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003B914: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B918: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x8003B91C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B920: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003B924: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B928: nop

    // 0x8003B92C: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003B930: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003B934: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B938: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B93C: nop

    // 0x8003B940: sw          $t2, 0x2588($t3)
    MEM_W(0X2588, ctx->r11) = ctx->r10;
    // 0x8003B944: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003B948: nop

    // 0x8003B94C: addiu       $a0, $t4, 0x1F8
    ctx->r4 = ADD32(ctx->r12, 0X1F8);
    // 0x8003B950: jal         0x800B34D0
    // 0x8003B954: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B954: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    after_0:
    // 0x8003B958: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B95C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B960: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B964: jal         0x800B3C20
    // 0x8003B968: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B968: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B96C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003B970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B974: lw          $v0, 0x2580($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2580);
    // 0x8003B978: jr          $ra
    // 0x8003B97C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003B97C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Pfs_DeleteFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B988: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B98C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B990: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B994: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B998: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8003B99C: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003B9A0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9A4: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x8003B9A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B9AC: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003B9B0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9B4: nop

    // 0x8003B9B8: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003B9BC: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003B9C0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9C4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B9C8: nop

    // 0x8003B9CC: sw          $t2, 0x2588($t3)
    MEM_W(0X2588, ctx->r11) = ctx->r10;
    // 0x8003B9D0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9D4: nop

    // 0x8003B9D8: addiu       $a0, $t4, 0x1F8
    ctx->r4 = ADD32(ctx->r12, 0X1F8);
    // 0x8003B9DC: jal         0x800B34D0
    // 0x8003B9E0: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B9E0: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    after_0:
    // 0x8003B9E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B9EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B9F0: jal         0x800B3C20
    // 0x8003B9F4: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B9F4: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B9F8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BA00: lw          $v0, 0x2580($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2580);
    // 0x8003BA04: jr          $ra
    // 0x8003BA08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BA08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Pfs_NumFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BA0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BA10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BA14: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BA1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BA20: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8003BA24: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003BA28: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA2C: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003BA30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BA34: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003BA38: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA3C: nop

    // 0x8003BA40: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003BA44: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003BA48: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA4C: nop

    // 0x8003BA50: addiu       $a0, $t2, 0x1F8
    ctx->r4 = ADD32(ctx->r10, 0X1F8);
    // 0x8003BA54: jal         0x800B34D0
    // 0x8003BA58: addiu       $a1, $t2, 0x2570
    ctx->r5 = ADD32(ctx->r10, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BA58: addiu       $a1, $t2, 0x2570
    ctx->r5 = ADD32(ctx->r10, 0X2570);
    after_0:
    // 0x8003BA5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BA64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BA68: jal         0x800B3C20
    // 0x8003BA6C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BA6C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BA70: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BA78: lw          $v0, 0x2580($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2580);
    // 0x8003BA7C: jr          $ra
    // 0x8003BA80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BA80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Pfs_FileState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BA84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BA88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BA8C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BA94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BA98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003BA9C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8003BAA0: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8003BAA4: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003BAA8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BAAC: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x8003BAB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BAB4: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003BAB8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BABC: nop

    // 0x8003BAC0: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003BAC4: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003BAC8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BACC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BAD0: nop

    // 0x8003BAD4: sw          $t2, 0x2588($t3)
    MEM_W(0X2588, ctx->r11) = ctx->r10;
    // 0x8003BAD8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003BADC: lbu         $t4, 0x23($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X23);
    // 0x8003BAE0: nop

    // 0x8003BAE4: sb          $t4, 0x2571($t5)
    MEM_B(0X2571, ctx->r13) = ctx->r12;
    // 0x8003BAE8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003BAEC: nop

    // 0x8003BAF0: addiu       $a0, $t6, 0x1F8
    ctx->r4 = ADD32(ctx->r14, 0X1F8);
    // 0x8003BAF4: jal         0x800B34D0
    // 0x8003BAF8: addiu       $a1, $t6, 0x2570
    ctx->r5 = ADD32(ctx->r14, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BAF8: addiu       $a1, $t6, 0x2570
    ctx->r5 = ADD32(ctx->r14, 0X2570);
    after_0:
    // 0x8003BAFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BB04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BB08: jal         0x800B3C20
    // 0x8003BB0C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BB0C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BB10: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BB18: lw          $v0, 0x2580($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2580);
    // 0x8003BB1C: jr          $ra
    // 0x8003BB20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BB20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Pfs_RepairId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BB24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BB28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BB2C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BB34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BB38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003BB3C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8003BB40: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003BB44: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB48: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x8003BB4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BB50: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003BB54: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB58: nop

    // 0x8003BB5C: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003BB60: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003BB64: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB68: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BB6C: nop

    // 0x8003BB70: sw          $t2, 0x2588($t3)
    MEM_W(0X2588, ctx->r11) = ctx->r10;
    // 0x8003BB74: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB78: nop

    // 0x8003BB7C: addiu       $a0, $t4, 0x1F8
    ctx->r4 = ADD32(ctx->r12, 0X1F8);
    // 0x8003BB80: jal         0x800B34D0
    // 0x8003BB84: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BB84: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    after_0:
    // 0x8003BB88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BB90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BB94: jal         0x800B3C20
    // 0x8003BB98: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BB98: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BB9C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003BBA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BBA4: lw          $v0, 0x2580($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2580);
    // 0x8003BBA8: jr          $ra
    // 0x8003BBAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BBAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Pfs_FreeBlocks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BBB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BBB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BBB8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BBBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BBC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BBC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003BBC8: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8003BBCC: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003BBD0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BBD4: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x8003BBD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BBDC: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003BBE0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BBE4: nop

    // 0x8003BBE8: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003BBEC: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003BBF0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BBF4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BBF8: nop

    // 0x8003BBFC: sw          $t2, 0x2588($t3)
    MEM_W(0X2588, ctx->r11) = ctx->r10;
    // 0x8003BC00: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003BC04: nop

    // 0x8003BC08: addiu       $a0, $t4, 0x1F8
    ctx->r4 = ADD32(ctx->r12, 0X1F8);
    // 0x8003BC0C: jal         0x800B34D0
    // 0x8003BC10: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BC10: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    after_0:
    // 0x8003BC14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BC18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BC1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BC20: jal         0x800B3C20
    // 0x8003BC24: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BC24: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BC28: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003BC2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BC30: lw          $v0, 0x2580($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2580);
    // 0x8003BC34: jr          $ra
    // 0x8003BC38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BC38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

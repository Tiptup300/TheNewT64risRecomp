#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Motor_SendRecvMsg3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B3E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B3E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B3EC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B3F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B3F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B3F8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8003B3FC: sh          $t6, 0x254C($t7)
    MEM_H(0X254C, ctx->r15) = ctx->r14;
    // 0x8003B400: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B404: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B408: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B40C: sw          $t8, 0x2550($t9)
    MEM_W(0X2550, ctx->r25) = ctx->r24;
    // 0x8003B410: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B414: nop

    // 0x8003B418: sw          $zero, 0x2554($t0)
    MEM_W(0X2554, ctx->r8) = 0;
    // 0x8003B41C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B420: nop

    // 0x8003B424: addiu       $t2, $t1, 0x240
    ctx->r10 = ADD32(ctx->r9, 0X240);
    // 0x8003B428: sw          $t2, 0x255C($t1)
    MEM_W(0X255C, ctx->r9) = ctx->r10;
    // 0x8003B42C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B430: nop

    // 0x8003B434: addiu       $a0, $t3, 0x1E0
    ctx->r4 = ADD32(ctx->r11, 0X1E0);
    // 0x8003B438: jal         0x800B34D0
    // 0x8003B43C: addiu       $a1, $t3, 0x254C
    ctx->r5 = ADD32(ctx->r11, 0X254C);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B43C: addiu       $a1, $t3, 0x254C
    ctx->r5 = ADD32(ctx->r11, 0X254C);
    after_0:
    // 0x8003B440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B448: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B44C: jal         0x800B3C20
    // 0x8003B450: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B450: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B454: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003B458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B45C: lw          $v0, 0x2554($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2554);
    // 0x8003B460: jr          $ra
    // 0x8003B464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003B464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Motor_SendMsg0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B46C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B470: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003B474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B478: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B47C: lhu         $t7, 0x25AE($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X25AE);
    // 0x8003B480: nop

    // 0x8003B484: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8003B488: beq         $t8, $zero, L_8003B4C4
    if (ctx->r24 == 0) {
        // 0x8003B48C: nop
    
            goto L_8003B4C4;
    }
    // 0x8003B48C: nop

    // 0x8003B490: sh          $zero, 0x254C($t6)
    MEM_H(0X254C, ctx->r14) = 0;
    // 0x8003B494: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B498: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B49C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B4A0: sw          $t9, 0x2550($t0)
    MEM_W(0X2550, ctx->r8) = ctx->r25;
    // 0x8003B4A4: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B4A8: nop

    // 0x8003B4AC: sw          $zero, 0x2554($t1)
    MEM_W(0X2554, ctx->r9) = 0;
    // 0x8003B4B0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8003B4B4: nop

    // 0x8003B4B8: addiu       $a0, $t2, 0x1E0
    ctx->r4 = ADD32(ctx->r10, 0X1E0);
    // 0x8003B4BC: jal         0x800B34D0
    // 0x8003B4C0: addiu       $a1, $t2, 0x254C
    ctx->r5 = ADD32(ctx->r10, 0X254C);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B4C0: addiu       $a1, $t2, 0x254C
    ctx->r5 = ADD32(ctx->r10, 0X254C);
    after_0:
L_8003B4C4:
    // 0x8003B4C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B4C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B4CC: jr          $ra
    // 0x8003B4D0: nop

    return;
    // 0x8003B4D0: nop

;}

RECOMP_FUNC void Motor_SendMsg1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B4D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B4D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B4DC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003B4E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B4E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B4E8: lhu         $t7, 0x25AE($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X25AE);
    // 0x8003B4EC: nop

    // 0x8003B4F0: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8003B4F4: beq         $t8, $zero, L_8003B534
    if (ctx->r24 == 0) {
        // 0x8003B4F8: nop
    
            goto L_8003B534;
    }
    // 0x8003B4F8: nop

    // 0x8003B4FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003B500: sh          $t9, 0x254C($t6)
    MEM_H(0X254C, ctx->r14) = ctx->r25;
    // 0x8003B504: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B508: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B50C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B510: sw          $t0, 0x2550($t1)
    MEM_W(0X2550, ctx->r9) = ctx->r8;
    // 0x8003B514: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8003B518: nop

    // 0x8003B51C: sw          $zero, 0x2554($t2)
    MEM_W(0X2554, ctx->r10) = 0;
    // 0x8003B520: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B524: nop

    // 0x8003B528: addiu       $a0, $t3, 0x1E0
    ctx->r4 = ADD32(ctx->r11, 0X1E0);
    // 0x8003B52C: jal         0x800B34D0
    // 0x8003B530: addiu       $a1, $t3, 0x254C
    ctx->r5 = ADD32(ctx->r11, 0X254C);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B530: addiu       $a1, $t3, 0x254C
    ctx->r5 = ADD32(ctx->r11, 0X254C);
    after_0:
L_8003B534:
    // 0x8003B534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B53C: jr          $ra
    // 0x8003B540: nop

    return;
    // 0x8003B540: nop

;}

RECOMP_FUNC void Motor_SendMsg2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B544: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B548: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B54C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003B550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B554: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B558: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B55C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8003B560: lhu         $t7, 0x25AE($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X25AE);
    // 0x8003B564: nop

    // 0x8003B568: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8003B56C: beq         $t8, $zero, L_8003B5C0
    if (ctx->r24 == 0) {
        // 0x8003B570: nop
    
            goto L_8003B5C0;
    }
    // 0x8003B570: nop

    // 0x8003B574: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8003B578: sh          $t9, 0x254C($t6)
    MEM_H(0X254C, ctx->r14) = ctx->r25;
    // 0x8003B57C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B580: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B584: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B588: sw          $t0, 0x2550($t1)
    MEM_W(0X2550, ctx->r9) = ctx->r8;
    // 0x8003B58C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B590: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8003B594: nop

    // 0x8003B598: sw          $t2, 0x2554($t3)
    MEM_W(0X2554, ctx->r11) = ctx->r10;
    // 0x8003B59C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003B5A0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8003B5A4: nop

    // 0x8003B5A8: sw          $t4, 0x2558($t5)
    MEM_W(0X2558, ctx->r13) = ctx->r12;
    // 0x8003B5AC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B5B0: nop

    // 0x8003B5B4: addiu       $a0, $t7, 0x1E0
    ctx->r4 = ADD32(ctx->r15, 0X1E0);
    // 0x8003B5B8: jal         0x800B34D0
    // 0x8003B5BC: addiu       $a1, $t7, 0x254C
    ctx->r5 = ADD32(ctx->r15, 0X254C);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B5BC: addiu       $a1, $t7, 0x254C
    ctx->r5 = ADD32(ctx->r15, 0X254C);
    after_0:
L_8003B5C0:
    // 0x8003B5C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B5C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B5C8: jr          $ra
    // 0x8003B5CC: nop

    return;
    // 0x8003B5CC: nop

;}

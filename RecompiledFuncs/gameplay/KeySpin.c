#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void KeySpin_SettleColumns(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B3B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006B3B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006B3B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006B3BC: slti        $at, $s1, 0xA
    ctx->r1 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x8006B3C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006B3C4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006B3C8: beq         $at, $zero, L_8006B440
    if (ctx->r1 == 0) {
        // 0x8006B3CC: sw          $s2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r18;
            goto L_8006B440;
    }
    // 0x8006B3CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
L_8006B3D0:
    // 0x8006B3D0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006B3D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006B3D8: lb          $s2, 0x1($t6)
    ctx->r18 = MEM_B(ctx->r14, 0X1);
    // 0x8006B3DC: jal         0x8006E498
    // 0x8006B3E0: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    BoardP_IsPositionEmpty(rdram, ctx);
        goto after_0;
    // 0x8006B3E0: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    after_0:
    // 0x8006B3E4: beq         $v0, $zero, L_8006B404
    if (ctx->r2 == 0) {
        // 0x8006B3E8: nop
    
            goto L_8006B404;
    }
    // 0x8006B3E8: nop

L_8006B3EC:
    // 0x8006B3EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006B3F0: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    // 0x8006B3F4: jal         0x8006E498
    // 0x8006B3F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    BoardP_IsPositionEmpty(rdram, ctx);
        goto after_1;
    // 0x8006B3F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8006B3FC: bne         $v0, $zero, L_8006B3EC
    if (ctx->r2 != 0) {
        // 0x8006B400: nop
    
            goto L_8006B3EC;
    }
    // 0x8006B400: nop

L_8006B404:
    // 0x8006B404: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8006B408: nop

    // 0x8006B40C: lb          $t8, 0x1($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X1);
    // 0x8006B410: nop

    // 0x8006B414: beq         $t8, $s2, L_8006B430
    if (ctx->r24 == ctx->r18) {
        // 0x8006B418: nop
    
            goto L_8006B430;
    }
    // 0x8006B418: nop

    // 0x8006B41C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006B420: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8006B424: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8006B428: jal         0x8006E0E8
    // 0x8006B42C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    BoardPieces_SwapCubes(rdram, ctx);
        goto after_2;
    // 0x8006B42C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_2:
L_8006B430:
    // 0x8006B430: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006B434: slti        $at, $s1, 0xA
    ctx->r1 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x8006B438: bne         $at, $zero, L_8006B3D0
    if (ctx->r1 != 0) {
        // 0x8006B43C: nop
    
            goto L_8006B3D0;
    }
    // 0x8006B43C: nop

L_8006B440:
    // 0x8006B440: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006B444: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B448: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006B44C: jr          $ra
    // 0x8006B450: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006B450: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void KeySpin_InitDrop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B454: lb          $t7, 0x5($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X5);
    // 0x8006B458: lb          $t8, 0x5($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X5);
    // 0x8006B45C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006B460: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8006B464: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8006B468: sb          $t9, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r25;
    // 0x8006B46C: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x8006B470: jr          $ra
    // 0x8006B474: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
    return;
    // 0x8006B474: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
;}

RECOMP_FUNC void KeySpin_StepDrop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B47C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006B480: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006B484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B488: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006B48C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8006B490: nop

    // 0x8006B494: beq         $t7, $zero, L_8006B52C
    if (ctx->r15 == 0) {
        // 0x8006B498: nop
    
            goto L_8006B52C;
    }
    // 0x8006B498: nop

    // 0x8006B49C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006B4A0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B4A4: lbu         $t9, 0x3($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3);
    // 0x8006B4A8: nop

    // 0x8006B4AC: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8006B4B0: beq         $at, $zero, L_8006B4C4
    if (ctx->r1 == 0) {
        // 0x8006B4B4: nop
    
            goto L_8006B4C4;
    }
    // 0x8006B4B4: nop

    // 0x8006B4B8: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x8006B4BC: b           L_8006B52C
    // 0x8006B4C0: sb          $t1, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r9;
        goto L_8006B52C;
    // 0x8006B4C0: sb          $t1, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r9;
L_8006B4C4:
    // 0x8006B4C4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8006B4C8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B4CC: lbu         $t3, 0x3($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3);
    // 0x8006B4D0: nop

    // 0x8006B4D4: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8006B4D8: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x8006B4DC: sb          $t6, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r14;
    // 0x8006B4E0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006B4E4: nop

    // 0x8006B4E8: lb          $t9, 0x1($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X1);
    // 0x8006B4EC: nop

    // 0x8006B4F0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8006B4F4: sb          $t0, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r8;
    // 0x8006B4F8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006B4FC: nop

    // 0x8006B500: lb          $t8, 0x1($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X1);
    // 0x8006B504: lb          $t3, 0x4($t1)
    ctx->r11 = MEM_B(ctx->r9, 0X4);
    // 0x8006B508: nop

    // 0x8006B50C: slt         $at, $t8, $t3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8006B510: beq         $at, $zero, L_8006B520
    if (ctx->r1 == 0) {
        // 0x8006B514: nop
    
            goto L_8006B520;
    }
    // 0x8006B514: nop

    // 0x8006B518: b           L_8006B52C
    // 0x8006B51C: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
        goto L_8006B52C;
    // 0x8006B51C: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
L_8006B520:
    // 0x8006B520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006B524: jal         0x8006B3B0
    // 0x8006B528: nop

    KeySpin_SettleColumns(rdram, ctx);
        goto after_0;
    // 0x8006B528: nop

    after_0:
L_8006B52C:
    // 0x8006B52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B534: jr          $ra
    // 0x8006B538: nop

    return;
    // 0x8006B538: nop

;}

RECOMP_FUNC void KeySpin_LaunchColumnCells(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B53C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006B540: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8006B544: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8006B548: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B54C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006B550: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006B554: lw          $t6, -0x430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X430);
    // 0x8006B558: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B55C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006B560: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006B564: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006B568: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8006B56C: addu        $s0, $t6, $t9
    ctx->r16 = ADD32(ctx->r14, ctx->r25);
    // 0x8006B570: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006B574: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006B578: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006B57C: blez        $s2, L_8006B5F0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8006B580: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006B5F0;
    }
    // 0x8006B580: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006B584:
    // 0x8006B584: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8006B588: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006B58C: lbu         $t0, 0x1($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1);
    // 0x8006B590: nop

    // 0x8006B594: beq         $t0, $at, L_8006B5E4
    if (ctx->r8 == ctx->r1) {
        // 0x8006B598: nop
    
            goto L_8006B5E4;
    }
    // 0x8006B598: nop

    // 0x8006B59C: jal         0x8006D5BC
    // 0x8006B5A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    BoardP_SeparateCell(rdram, ctx);
        goto after_0;
    // 0x8006B5A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8006B5A4: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8006B5A8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006B5AC: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8006B5B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8006B5B4: jal         0x80070860
    // 0x8006B5B8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_80070860_fortyliner(rdram, ctx);
        goto after_1;
    // 0x8006B5B8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
    // 0x8006B5BC: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    // 0x8006B5C0: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
    // 0x8006B5C4: lh          $t2, 0x48($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X48);
    // 0x8006B5C8: nop

    // 0x8006B5CC: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8006B5D0: bgez        $t3, L_8006B5E0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8006B5D4: sra         $t4, $t3, 3
        ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
            goto L_8006B5E0;
    }
    // 0x8006B5D4: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8006B5D8: addiu       $at, $t3, 0x7
    ctx->r1 = ADD32(ctx->r11, 0X7);
    // 0x8006B5DC: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_8006B5E0:
    // 0x8006B5E0: sh          $t4, 0x4A($t5)
    MEM_H(0X4A, ctx->r13) = ctx->r12;
L_8006B5E4:
    // 0x8006B5E4: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8006B5E8: bgtz        $s2, L_8006B584
    if (SIGNED(ctx->r18) > 0) {
        // 0x8006B5EC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006B584;
    }
    // 0x8006B5EC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006B5F0:
    // 0x8006B5F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006B5F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006B5F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B5FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006B600: jr          $ra
    // 0x8006B604: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006B604: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void KeySpin_RefreshColumnCells(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B608: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006B60C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8006B610: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8006B614: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B618: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006B61C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006B620: lw          $t6, -0x430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X430);
    // 0x8006B624: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B628: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006B62C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006B630: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006B634: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x8006B638: addu        $s0, $t6, $t9
    ctx->r16 = ADD32(ctx->r14, ctx->r25);
    // 0x8006B63C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006B640: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006B644: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006B648: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006B64C: blez        $s3, L_8006B698
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8006B650: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006B698;
    }
    // 0x8006B650: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006B654:
    // 0x8006B654: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8006B658: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006B65C: lbu         $t0, 0x1($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1);
    // 0x8006B660: nop

    // 0x8006B664: beq         $t0, $at, L_8006B68C
    if (ctx->r8 == ctx->r1) {
        // 0x8006B668: nop
    
            goto L_8006B68C;
    }
    // 0x8006B668: nop

    // 0x8006B66C: jal         0x8006D3C0
    // 0x8006B670: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    BoardP_GetCellColor(rdram, ctx);
        goto after_0;
    // 0x8006B670: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8006B674: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8006B678: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8006B67C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8006B680: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8006B684: jal         0x80070860
    // 0x8006B688: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_80070860_fortyliner(rdram, ctx);
        goto after_1;
    // 0x8006B688: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
L_8006B68C:
    // 0x8006B68C: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x8006B690: bgtz        $s3, L_8006B654
    if (SIGNED(ctx->r19) > 0) {
        // 0x8006B694: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006B654;
    }
    // 0x8006B694: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006B698:
    // 0x8006B698: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006B69C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006B6A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006B6A4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B6A8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006B6AC: jr          $ra
    // 0x8006B6B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006B6B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void KeySpin_StepSlideX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B6B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B6B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006B6BC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006B6C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B6C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006B6C8: lbu         $t7, 0x3($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3);
    // 0x8006B6CC: nop

    // 0x8006B6D0: beq         $t7, $zero, L_8006B7A4
    if (ctx->r15 == 0) {
        // 0x8006B6D4: nop
    
            goto L_8006B7A4;
    }
    // 0x8006B6D4: nop

    // 0x8006B6D8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006B6DC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B6E0: lbu         $t9, 0x5($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X5);
    // 0x8006B6E4: nop

    // 0x8006B6E8: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8006B6EC: beq         $at, $zero, L_8006B700
    if (ctx->r1 == 0) {
        // 0x8006B6F0: nop
    
            goto L_8006B700;
    }
    // 0x8006B6F0: nop

    // 0x8006B6F4: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x8006B6F8: b           L_8006B7A4
    // 0x8006B6FC: sb          $t1, 0x5($t8)
    MEM_B(0X5, ctx->r24) = ctx->r9;
        goto L_8006B7A4;
    // 0x8006B6FC: sb          $t1, 0x5($t8)
    MEM_B(0X5, ctx->r24) = ctx->r9;
L_8006B700:
    // 0x8006B700: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8006B704: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B708: lbu         $t3, 0x5($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X5);
    // 0x8006B70C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8006B710: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8006B714: addiu       $t6, $t5, 0x6
    ctx->r14 = ADD32(ctx->r13, 0X6);
    // 0x8006B718: sb          $t6, 0x5($t2)
    MEM_B(0X5, ctx->r10) = ctx->r14;
    // 0x8006B71C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006B720: nop

    // 0x8006B724: lb          $t9, 0x1($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X1);
    // 0x8006B728: nop

    // 0x8006B72C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8006B730: sb          $t0, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r8;
    // 0x8006B734: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006B738: nop

    // 0x8006B73C: lb          $t8, 0x1($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X1);
    // 0x8006B740: nop

    // 0x8006B744: bne         $t8, $at, L_8006B754
    if (ctx->r24 != ctx->r1) {
        // 0x8006B748: nop
    
            goto L_8006B754;
    }
    // 0x8006B748: nop

    // 0x8006B74C: b           L_8006B7A4
    // 0x8006B750: sb          $zero, 0x3($t1)
    MEM_B(0X3, ctx->r9) = 0;
        goto L_8006B7A4;
    // 0x8006B750: sb          $zero, 0x3($t1)
    MEM_B(0X3, ctx->r9) = 0;
L_8006B754:
    // 0x8006B754: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8006B758: nop

    // 0x8006B75C: lb          $t4, 0x1($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X1);
    // 0x8006B760: nop

    // 0x8006B764: bltz        $t4, L_8006B778
    if (SIGNED(ctx->r12) < 0) {
        // 0x8006B768: nop
    
            goto L_8006B778;
    }
    // 0x8006B768: nop

    // 0x8006B76C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8006B770: jal         0x8006B53C
    // 0x8006B774: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    KeySpin_LaunchColumnCells(rdram, ctx);
        goto after_0;
    // 0x8006B774: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_0:
L_8006B778:
    // 0x8006B778: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8006B77C: nop

    // 0x8006B780: lb          $t2, 0x1($t5)
    ctx->r10 = MEM_B(ctx->r13, 0X1);
    // 0x8006B784: lbu         $t6, 0x7($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X7);
    // 0x8006B788: addiu       $t9, $t2, 0x2
    ctx->r25 = ADD32(ctx->r10, 0X2);
    // 0x8006B78C: slt         $at, $t6, $t9
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8006B790: bne         $at, $zero, L_8006B7A4
    if (ctx->r1 != 0) {
        // 0x8006B794: nop
    
            goto L_8006B7A4;
    }
    // 0x8006B794: nop

    // 0x8006B798: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8006B79C: jal         0x8006B608
    // 0x8006B7A0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    KeySpin_RefreshColumnCells(rdram, ctx);
        goto after_1;
    // 0x8006B7A0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_1:
L_8006B7A4:
    // 0x8006B7A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B7A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B7AC: jr          $ra
    // 0x8006B7B0: nop

    return;
    // 0x8006B7B0: nop

;}

RECOMP_FUNC void KeySpin_StepSlideY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B7B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B7B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006B7BC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006B7C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B7C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006B7C8: lbu         $t7, 0x4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4);
    // 0x8006B7CC: nop

    // 0x8006B7D0: beq         $t7, $zero, L_8006B8A8
    if (ctx->r15 == 0) {
        // 0x8006B7D4: nop
    
            goto L_8006B8A8;
    }
    // 0x8006B7D4: nop

    // 0x8006B7D8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006B7DC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B7E0: lbu         $t9, 0x6($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X6);
    // 0x8006B7E4: nop

    // 0x8006B7E8: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8006B7EC: beq         $at, $zero, L_8006B800
    if (ctx->r1 == 0) {
        // 0x8006B7F0: nop
    
            goto L_8006B800;
    }
    // 0x8006B7F0: nop

    // 0x8006B7F4: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x8006B7F8: b           L_8006B8A8
    // 0x8006B7FC: sb          $t1, 0x6($t8)
    MEM_B(0X6, ctx->r24) = ctx->r9;
        goto L_8006B8A8;
    // 0x8006B7FC: sb          $t1, 0x6($t8)
    MEM_B(0X6, ctx->r24) = ctx->r9;
L_8006B800:
    // 0x8006B800: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8006B804: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B808: lbu         $t3, 0x6($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X6);
    // 0x8006B80C: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8006B810: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8006B814: addiu       $t6, $t5, 0x6
    ctx->r14 = ADD32(ctx->r13, 0X6);
    // 0x8006B818: sb          $t6, 0x6($t2)
    MEM_B(0X6, ctx->r10) = ctx->r14;
    // 0x8006B81C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006B820: nop

    // 0x8006B824: lb          $t9, 0x2($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X2);
    // 0x8006B828: nop

    // 0x8006B82C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8006B830: sb          $t0, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r8;
    // 0x8006B834: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006B838: nop

    // 0x8006B83C: lb          $t8, 0x2($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X2);
    // 0x8006B840: nop

    // 0x8006B844: bne         $t8, $at, L_8006B854
    if (ctx->r24 != ctx->r1) {
        // 0x8006B848: nop
    
            goto L_8006B854;
    }
    // 0x8006B848: nop

    // 0x8006B84C: b           L_8006B8A8
    // 0x8006B850: sb          $zero, 0x4($t1)
    MEM_B(0X4, ctx->r9) = 0;
        goto L_8006B8A8;
    // 0x8006B850: sb          $zero, 0x4($t1)
    MEM_B(0X4, ctx->r9) = 0;
L_8006B854:
    // 0x8006B854: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8006B858: nop

    // 0x8006B85C: lb          $t4, 0x2($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X2);
    // 0x8006B860: nop

    // 0x8006B864: slti        $at, $t4, 0x14
    ctx->r1 = SIGNED(ctx->r12) < 0X14 ? 1 : 0;
    // 0x8006B868: beq         $at, $zero, L_8006B87C
    if (ctx->r1 == 0) {
        // 0x8006B86C: nop
    
            goto L_8006B87C;
    }
    // 0x8006B86C: nop

    // 0x8006B870: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8006B874: jal         0x8006B53C
    // 0x8006B878: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    KeySpin_LaunchColumnCells(rdram, ctx);
        goto after_0;
    // 0x8006B878: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_0:
L_8006B87C:
    // 0x8006B87C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8006B880: nop

    // 0x8006B884: lb          $t2, 0x2($t5)
    ctx->r10 = MEM_B(ctx->r13, 0X2);
    // 0x8006B888: lbu         $t6, 0x8($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X8);
    // 0x8006B88C: addiu       $t9, $t2, -0x2
    ctx->r25 = ADD32(ctx->r10, -0X2);
    // 0x8006B890: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B894: bne         $at, $zero, L_8006B8A8
    if (ctx->r1 != 0) {
        // 0x8006B898: nop
    
            goto L_8006B8A8;
    }
    // 0x8006B898: nop

    // 0x8006B89C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8006B8A0: jal         0x8006B608
    // 0x8006B8A4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    KeySpin_RefreshColumnCells(rdram, ctx);
        goto after_1;
    // 0x8006B8A4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_1:
L_8006B8A8:
    // 0x8006B8A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B8AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B8B0: jr          $ra
    // 0x8006B8B4: nop

    return;
    // 0x8006B8B4: nop

;}

RECOMP_FUNC void KeySpin_StepSlide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B8B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B8BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006B8C0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006B8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B8C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006B8CC: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8006B8D0: nop

    // 0x8006B8D4: beq         $t7, $zero, L_8006B928
    if (ctx->r15 == 0) {
        // 0x8006B8D8: nop
    
            goto L_8006B928;
    }
    // 0x8006B8D8: nop

    // 0x8006B8DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006B8E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B8E4: jal         0x8006B6B4
    // 0x8006B8E8: nop

    KeySpin_StepSlideX(rdram, ctx);
        goto after_0;
    // 0x8006B8E8: nop

    after_0:
    // 0x8006B8EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006B8F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B8F4: jal         0x8006B7B4
    // 0x8006B8F8: nop

    KeySpin_StepSlideY(rdram, ctx);
        goto after_1;
    // 0x8006B8F8: nop

    after_1:
    // 0x8006B8FC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006B900: nop

    // 0x8006B904: lbu         $t9, 0x3($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3);
    // 0x8006B908: nop

    // 0x8006B90C: bne         $t9, $zero, L_8006B928
    if (ctx->r25 != 0) {
        // 0x8006B910: nop
    
            goto L_8006B928;
    }
    // 0x8006B910: nop

    // 0x8006B914: lbu         $t0, 0x4($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X4);
    // 0x8006B918: nop

    // 0x8006B91C: bne         $t0, $zero, L_8006B928
    if (ctx->r8 != 0) {
        // 0x8006B920: nop
    
            goto L_8006B928;
    }
    // 0x8006B920: nop

    // 0x8006B924: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
L_8006B928:
    // 0x8006B928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B92C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B930: jr          $ra
    // 0x8006B934: nop

    return;
    // 0x8006B934: nop

;}

RECOMP_FUNC void KeySpin_InitVPulseState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B93C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006B940: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006B944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B948: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006B94C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006B950: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8006B954: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006B958: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8006B95C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B960: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8006B964: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8006B968: sb          $t8, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r24;
    // 0x8006B96C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006B970: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006B974: nop

    // 0x8006B978: sb          $t0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r8;
    // 0x8006B97C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8006B980: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8006B984: nop

    // 0x8006B988: sb          $t2, 0x7($t3)
    MEM_B(0X7, ctx->r11) = ctx->r10;
    // 0x8006B98C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8006B990: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8006B994: sb          $t4, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r12;
    // 0x8006B998: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006B99C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8006B9A0: nop

    // 0x8006B9A4: sb          $t6, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r14;
    // 0x8006B9A8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8006B9AC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006B9B0: nop

    // 0x8006B9B4: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
    // 0x8006B9B8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006B9BC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8006B9C0: nop

    // 0x8006B9C4: sb          $t0, 0x8($t1)
    MEM_B(0X8, ctx->r9) = ctx->r8;
    // 0x8006B9C8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8006B9CC: nop

    // 0x8006B9D0: sb          $t2, 0x6($t3)
    MEM_B(0X6, ctx->r11) = ctx->r10;
    // 0x8006B9D4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B9D8: nop

    // 0x8006B9DC: beq         $t4, $zero, L_8006B9F4
    if (ctx->r12 == 0) {
        // 0x8006B9E0: nop
    
            goto L_8006B9F4;
    }
    // 0x8006B9E0: nop

    // 0x8006B9E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006B9E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8006B9EC: jal         0x8006B53C
    // 0x8006B9F0: nop

    KeySpin_LaunchColumnCells(rdram, ctx);
        goto after_0;
    // 0x8006B9F0: nop

    after_0:
L_8006B9F4:
    // 0x8006B9F4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8006B9F8: nop

    // 0x8006B9FC: beq         $t5, $zero, L_8006BA14
    if (ctx->r13 == 0) {
        // 0x8006BA00: nop
    
            goto L_8006BA14;
    }
    // 0x8006BA00: nop

    // 0x8006BA04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006BA08: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8006BA0C: jal         0x8006B53C
    // 0x8006BA10: nop

    KeySpin_LaunchColumnCells(rdram, ctx);
        goto after_1;
    // 0x8006BA10: nop

    after_1:
L_8006BA14:
    // 0x8006BA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BA18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BA1C: jr          $ra
    // 0x8006BA20: nop

    return;
    // 0x8006BA20: nop

;}

RECOMP_FUNC void KeySpin_InitCellPulse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BA24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006BA28: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006BA2C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8006BA30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006BA34: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8006BA38: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8006BA3C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006BA40: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006BA44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006BA48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006BA4C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8006BA50: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006BA54: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8006BA58: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    // 0x8006BA5C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006BA60: lh          $t9, 0x3E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3E);
    // 0x8006BA64: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BA68: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
    // 0x8006BA6C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8006BA70: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8006BA74: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
    // 0x8006BA78: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8006BA7C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8006BA80: beq         $at, $zero, L_8006BB0C
    if (ctx->r1 == 0) {
        // 0x8006BA84: sb          $t3, 0x4($t4)
        MEM_B(0X4, ctx->r12) = ctx->r11;
            goto L_8006BB0C;
    }
    // 0x8006BA84: sb          $t3, 0x4($t4)
    MEM_B(0X4, ctx->r12) = ctx->r11;
L_8006BA88:
    // 0x8006BA88: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8006BA8C: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x8006BA90: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8006BA94: lb          $t8, 0x16($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X16);
    // 0x8006BA98: lh          $t9, 0x3E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3E);
    // 0x8006BA9C: nop

    // 0x8006BAA0: bne         $t8, $t9, L_8006BAFC
    if (ctx->r24 != ctx->r25) {
        // 0x8006BAA4: nop
    
            goto L_8006BAFC;
    }
    // 0x8006BAA4: nop

    // 0x8006BAA8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006BAAC: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x8006BAB0: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8006BAB4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8006BAB8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8006BABC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8006BAC0: lb          $s1, 0x15($t3)
    ctx->r17 = MEM_B(ctx->r11, 0X15);
    // 0x8006BAC4: lb          $t5, 0x3($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X3);
    // 0x8006BAC8: nop

    // 0x8006BACC: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8006BAD0: beq         $at, $zero, L_8006BADC
    if (ctx->r1 == 0) {
        // 0x8006BAD4: nop
    
            goto L_8006BADC;
    }
    // 0x8006BAD4: nop

    // 0x8006BAD8: sb          $s1, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r17;
L_8006BADC:
    // 0x8006BADC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006BAE0: nop

    // 0x8006BAE4: lb          $t7, 0x4($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X4);
    // 0x8006BAE8: nop

    // 0x8006BAEC: slt         $at, $t7, $s1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8006BAF0: beq         $at, $zero, L_8006BAFC
    if (ctx->r1 == 0) {
        // 0x8006BAF4: nop
    
            goto L_8006BAFC;
    }
    // 0x8006BAF4: nop

    // 0x8006BAF8: sb          $s1, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r17;
L_8006BAFC:
    // 0x8006BAFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006BB00: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8006BB04: bne         $at, $zero, L_8006BA88
    if (ctx->r1 != 0) {
        // 0x8006BB08: nop
    
            goto L_8006BA88;
    }
    // 0x8006BB08: nop

L_8006BB0C:
    // 0x8006BB0C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006BB10: nop

    // 0x8006BB14: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8006BB18: nop

    // 0x8006BB1C: bne         $t9, $zero, L_8006BC74
    if (ctx->r25 != 0) {
        // 0x8006BB20: nop
    
            goto L_8006BC74;
    }
    // 0x8006BB20: nop

    // 0x8006BB24: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006BB28: addiu       $t6, $zero, -0x100
    ctx->r14 = ADD32(0, -0X100);
    // 0x8006BB2C: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x8006BB30: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8006BB34: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8006BB38: lb          $t2, 0x3($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X3);
    // 0x8006BB3C: nop

    // 0x8006BB40: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x8006BB44: addiu       $t5, $t3, 0x80
    ctx->r13 = ADD32(ctx->r11, 0X80);
    // 0x8006BB48: sh          $t5, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r13;
    // 0x8006BB4C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8006BB50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006BB54: lh          $t7, 0x6($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X6);
    // 0x8006BB58: nop

    // 0x8006BB5C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8006BB60: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x8006BB64: mflo        $t9
    ctx->r25 = lo;
    // 0x8006BB68: sh          $t9, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r25;
    // 0x8006BB6C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006BB70: nop

    // 0x8006BB74: lb          $t2, 0x3($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X3);
    // 0x8006BB78: nop

    // 0x8006BB7C: sb          $t2, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r10;
    // 0x8006BB80: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8006BB84: addiu       $t0, $zero, 0xA00
    ctx->r8 = ADD32(0, 0XA00);
    // 0x8006BB88: sb          $t3, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r11;
    // 0x8006BB8C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8006BB90: nop

    // 0x8006BB94: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8006BB98: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006BB9C: nop

    // 0x8006BBA0: lb          $t7, 0x4($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X4);
    // 0x8006BBA4: nop

    // 0x8006BBA8: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8006BBAC: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x8006BBB0: sh          $t9, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r25;
    // 0x8006BBB4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8006BBB8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006BBBC: lh          $t2, 0x8($t4)
    ctx->r10 = MEM_H(ctx->r12, 0X8);
    // 0x8006BBC0: nop

    // 0x8006BBC4: subu        $t3, $t0, $t2
    ctx->r11 = SUB32(ctx->r8, ctx->r10);
    // 0x8006BBC8: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x8006BBCC: mflo        $t5
    ctx->r13 = lo;
    // 0x8006BBD0: sh          $t5, 0xC($t4)
    MEM_H(0XC, ctx->r12) = ctx->r13;
    // 0x8006BBD4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8006BBD8: nop

    // 0x8006BBDC: lb          $t7, 0x4($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X4);
    // 0x8006BBE0: nop

    // 0x8006BBE4: sb          $t7, 0xF($t1)
    MEM_B(0XF, ctx->r9) = ctx->r15;
    // 0x8006BBE8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8006BBEC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006BBF0: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x8006BBF4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006BBF8: nop

    // 0x8006BBFC: sb          $zero, 0x13($t6)
    MEM_B(0X13, ctx->r14) = 0;
    // 0x8006BC00: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006BC04: lw          $t1, -0x430($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X430);
    // 0x8006BC08: lb          $t3, 0x2($t0)
    ctx->r11 = MEM_B(ctx->r8, 0X2);
    // 0x8006BC0C: lb          $t2, 0x3($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X3);
    // 0x8006BC10: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8006BC14: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8006BC18: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8006BC1C: lb          $s0, 0x3($t0)
    ctx->r16 = MEM_B(ctx->r8, 0X3);
    // 0x8006BC20: lb          $t8, 0x4($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X4);
    // 0x8006BC24: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x8006BC28: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8006BC2C: addu        $s2, $t1, $t7
    ctx->r18 = ADD32(ctx->r9, ctx->r15);
    // 0x8006BC30: slt         $at, $t8, $s0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8006BC34: bne         $at, $zero, L_8006BC74
    if (ctx->r1 != 0) {
        // 0x8006BC38: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8006BC74;
    }
    // 0x8006BC38: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8006BC3C:
    // 0x8006BC3C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8006BC40: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006BC44: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    // 0x8006BC48: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8006BC4C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8006BC50: jal         0x80070860
    // 0x8006BC54: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_80070860_fortyliner(rdram, ctx);
        goto after_0;
    // 0x8006BC54: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x8006BC58: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006BC5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006BC60: lb          $t3, 0x4($t6)
    ctx->r11 = MEM_B(ctx->r14, 0X4);
    // 0x8006BC64: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8006BC68: slt         $at, $t3, $s0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8006BC6C: beq         $at, $zero, L_8006BC3C
    if (ctx->r1 == 0) {
        // 0x8006BC70: nop
    
            goto L_8006BC3C;
    }
    // 0x8006BC70: nop

L_8006BC74:
    // 0x8006BC74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006BC78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006BC7C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BC80: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006BC84: jr          $ra
    // 0x8006BC88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006BC88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void KeySpin_StepCellPulseX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BC8C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006BC90: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006BC94: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006BC98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006BC9C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8006BCA0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006BCA4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8006BCA8: lbu         $t7, 0x10($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X10);
    // 0x8006BCAC: nop

    // 0x8006BCB0: beq         $t7, $zero, L_8006BD80
    if (ctx->r15 == 0) {
        // 0x8006BCB4: nop
    
            goto L_8006BD80;
    }
    // 0x8006BCB4: nop

    // 0x8006BCB8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006BCBC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8006BCC0: lh          $t9, 0xA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XA);
    // 0x8006BCC4: lh          $t2, 0x6($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X6);
    // 0x8006BCC8: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BCCC: mflo        $t1
    ctx->r9 = lo;
    // 0x8006BCD0: addu        $t3, $t2, $t1
    ctx->r11 = ADD32(ctx->r10, ctx->r9);
    // 0x8006BCD4: sh          $t3, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r11;
    // 0x8006BCD8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8006BCDC: nop

    // 0x8006BCE0: lh          $s2, 0x6($t4)
    ctx->r18 = MEM_H(ctx->r12, 0X6);
    // 0x8006BCE4: lb          $t6, 0xE($t4)
    ctx->r14 = MEM_B(ctx->r12, 0XE);
    // 0x8006BCE8: sra         $t5, $s2, 8
    ctx->r13 = S32(SIGNED(ctx->r18) >> 8);
    // 0x8006BCEC: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x8006BCF0: beq         $t6, $s2, L_8006BD80
    if (ctx->r14 == ctx->r18) {
        // 0x8006BCF4: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8006BD80;
    }
    // 0x8006BCF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BCF8: bne         $s2, $at, L_8006BD18
    if (ctx->r18 != ctx->r1) {
        // 0x8006BCFC: sb          $s2, 0xE($t4)
        MEM_B(0XE, ctx->r12) = ctx->r18;
            goto L_8006BD18;
    }
    // 0x8006BCFC: sb          $s2, 0xE($t4)
    MEM_B(0XE, ctx->r12) = ctx->r18;
    // 0x8006BD00: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8006BD04: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006BD08: sb          $t7, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r15;
    // 0x8006BD0C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006BD10: b           L_8006BD80
    // 0x8006BD14: sb          $zero, 0x10($t0)
    MEM_B(0X10, ctx->r8) = 0;
        goto L_8006BD80;
    // 0x8006BD14: sb          $zero, 0x10($t0)
    MEM_B(0X10, ctx->r8) = 0;
L_8006BD18:
    // 0x8006BD18: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8006BD1C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006BD20: lb          $t3, 0x2($t1)
    ctx->r11 = MEM_B(ctx->r9, 0X2);
    // 0x8006BD24: lw          $t2, -0x430($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X430);
    // 0x8006BD28: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8006BD2C: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x8006BD30: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006BD34: addu        $t5, $s2, $t8
    ctx->r13 = ADD32(ctx->r18, ctx->r24);
    // 0x8006BD38: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006BD3C: addu        $t4, $t2, $t6
    ctx->r12 = ADD32(ctx->r10, ctx->r14);
    // 0x8006BD40: lw          $s0, 0x4($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X4);
    // 0x8006BD44: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006BD48: lbu         $t7, 0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1);
    // 0x8006BD4C: nop

    // 0x8006BD50: bne         $t7, $at, L_8006BD68
    if (ctx->r15 != ctx->r1) {
        // 0x8006BD54: nop
    
            goto L_8006BD68;
    }
    // 0x8006BD54: nop

    // 0x8006BD58: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8006BD5C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8006BD60: b           L_8006BD80
    // 0x8006BD64: sb          $zero, 0x10($t9)
    MEM_B(0X10, ctx->r25) = 0;
        goto L_8006BD80;
    // 0x8006BD64: sb          $zero, 0x10($t9)
    MEM_B(0X10, ctx->r25) = 0;
L_8006BD68:
    // 0x8006BD68: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8006BD6C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006BD70: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8006BD74: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8006BD78: jal         0x80070860
    // 0x8006BD7C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_80070860_fortyliner(rdram, ctx);
        goto after_0;
    // 0x8006BD7C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
L_8006BD80:
    // 0x8006BD80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006BD84: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BD88: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006BD8C: jr          $ra
    // 0x8006BD90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006BD90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void KeySpin_StepCellPulseY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD94: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006BD98: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006BD9C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006BDA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006BDA4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8006BDA8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006BDAC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8006BDB0: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x8006BDB4: nop

    // 0x8006BDB8: beq         $t7, $zero, L_8006BE88
    if (ctx->r15 == 0) {
        // 0x8006BDBC: nop
    
            goto L_8006BE88;
    }
    // 0x8006BDBC: nop

    // 0x8006BDC0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006BDC4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8006BDC8: lh          $t9, 0xC($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XC);
    // 0x8006BDCC: lh          $t2, 0x8($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X8);
    // 0x8006BDD0: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BDD4: mflo        $t1
    ctx->r9 = lo;
    // 0x8006BDD8: addu        $t3, $t2, $t1
    ctx->r11 = ADD32(ctx->r10, ctx->r9);
    // 0x8006BDDC: sh          $t3, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r11;
    // 0x8006BDE0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8006BDE4: nop

    // 0x8006BDE8: lh          $s2, 0x8($t4)
    ctx->r18 = MEM_H(ctx->r12, 0X8);
    // 0x8006BDEC: lb          $t6, 0xF($t4)
    ctx->r14 = MEM_B(ctx->r12, 0XF);
    // 0x8006BDF0: sra         $t5, $s2, 8
    ctx->r13 = S32(SIGNED(ctx->r18) >> 8);
    // 0x8006BDF4: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x8006BDF8: beq         $t6, $s2, L_8006BE88
    if (ctx->r14 == ctx->r18) {
        // 0x8006BDFC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8006BE88;
    }
    // 0x8006BDFC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8006BE00: bne         $s2, $at, L_8006BE20
    if (ctx->r18 != ctx->r1) {
        // 0x8006BE04: sb          $s2, 0xF($t4)
        MEM_B(0XF, ctx->r12) = ctx->r18;
            goto L_8006BE20;
    }
    // 0x8006BE04: sb          $s2, 0xF($t4)
    MEM_B(0XF, ctx->r12) = ctx->r18;
    // 0x8006BE08: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8006BE0C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006BE10: sb          $t7, 0x13($t9)
    MEM_B(0X13, ctx->r25) = ctx->r15;
    // 0x8006BE14: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006BE18: b           L_8006BE88
    // 0x8006BE1C: sb          $zero, 0x11($t0)
    MEM_B(0X11, ctx->r8) = 0;
        goto L_8006BE88;
    // 0x8006BE1C: sb          $zero, 0x11($t0)
    MEM_B(0X11, ctx->r8) = 0;
L_8006BE20:
    // 0x8006BE20: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8006BE24: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006BE28: lb          $t3, 0x2($t1)
    ctx->r11 = MEM_B(ctx->r9, 0X2);
    // 0x8006BE2C: lw          $t2, -0x430($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X430);
    // 0x8006BE30: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8006BE34: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x8006BE38: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006BE3C: addu        $t5, $s2, $t8
    ctx->r13 = ADD32(ctx->r18, ctx->r24);
    // 0x8006BE40: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006BE44: addu        $t4, $t2, $t6
    ctx->r12 = ADD32(ctx->r10, ctx->r14);
    // 0x8006BE48: lw          $s0, 0x4($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X4);
    // 0x8006BE4C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006BE50: lbu         $t7, 0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1);
    // 0x8006BE54: nop

    // 0x8006BE58: bne         $t7, $at, L_8006BE70
    if (ctx->r15 != ctx->r1) {
        // 0x8006BE5C: nop
    
            goto L_8006BE70;
    }
    // 0x8006BE5C: nop

    // 0x8006BE60: sb          $zero, 0x13($t1)
    MEM_B(0X13, ctx->r9) = 0;
    // 0x8006BE64: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8006BE68: b           L_8006BE88
    // 0x8006BE6C: sb          $zero, 0x11($t9)
    MEM_B(0X11, ctx->r25) = 0;
        goto L_8006BE88;
    // 0x8006BE6C: sb          $zero, 0x11($t9)
    MEM_B(0X11, ctx->r25) = 0;
L_8006BE70:
    // 0x8006BE70: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8006BE74: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006BE78: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8006BE7C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8006BE80: jal         0x80070860
    // 0x8006BE84: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_80070860_fortyliner(rdram, ctx);
        goto after_0;
    // 0x8006BE84: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
L_8006BE88:
    // 0x8006BE88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006BE8C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BE90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006BE94: jr          $ra
    // 0x8006BE98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006BE98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void KeySpin_FinishCellPulses(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BE9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006BEA0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006BEA4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8006BEA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006BEAC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006BEB0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006BEB4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006BEB8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006BEBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006BEC0: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8006BEC4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006BEC8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006BECC: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    // 0x8006BED0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8006BED4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8006BED8: sb          $zero, 0x10($t9)
    MEM_B(0X10, ctx->r25) = 0;
    // 0x8006BEDC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006BEE0: slti        $at, $s3, 0xA
    ctx->r1 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x8006BEE4: sb          $zero, 0x12($t0)
    MEM_B(0X12, ctx->r8) = 0;
    // 0x8006BEE8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8006BEEC: nop

    // 0x8006BEF0: sb          $zero, 0x11($t1)
    MEM_B(0X11, ctx->r9) = 0;
    // 0x8006BEF4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8006BEF8: nop

    // 0x8006BEFC: sb          $zero, 0x13($t2)
    MEM_B(0X13, ctx->r10) = 0;
    // 0x8006BF00: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8006BF04: lw          $t3, -0x430($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X430);
    // 0x8006BF08: lb          $t5, 0x2($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X2);
    // 0x8006BF0C: nop

    // 0x8006BF10: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006BF14: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8006BF18: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8006BF1C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006BF20: addu        $s0, $t3, $t7
    ctx->r16 = ADD32(ctx->r11, ctx->r15);
    // 0x8006BF24: beq         $at, $zero, L_8006BF74
    if (ctx->r1 == 0) {
        // 0x8006BF28: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006BF74;
    }
    // 0x8006BF28: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006BF2C:
    // 0x8006BF2C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8006BF30: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006BF34: lbu         $t8, 0x1($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1);
    // 0x8006BF38: nop

    // 0x8006BF3C: beq         $t8, $at, L_8006BF64
    if (ctx->r24 == ctx->r1) {
        // 0x8006BF40: nop
    
            goto L_8006BF64;
    }
    // 0x8006BF40: nop

    // 0x8006BF44: jal         0x8006D3C0
    // 0x8006BF48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    BoardP_GetCellColor(rdram, ctx);
        goto after_0;
    // 0x8006BF48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8006BF4C: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8006BF50: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8006BF54: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8006BF58: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8006BF5C: jal         0x80070860
    // 0x8006BF60: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_80070860_fortyliner(rdram, ctx);
        goto after_1;
    // 0x8006BF60: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
L_8006BF64:
    // 0x8006BF64: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8006BF68: slti        $at, $s3, 0xA
    ctx->r1 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x8006BF6C: bne         $at, $zero, L_8006BF2C
    if (ctx->r1 != 0) {
        // 0x8006BF70: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006BF2C;
    }
    // 0x8006BF70: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006BF74:
    // 0x8006BF74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006BF78: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006BF7C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006BF80: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BF84: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006BF88: jr          $ra
    // 0x8006BF8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006BF8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void KeySpin_StepCellPulse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BF94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006BF98: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006BF9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BFA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006BFA4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8006BFA8: nop

    // 0x8006BFAC: bne         $t7, $zero, L_8006C08C
    if (ctx->r15 != 0) {
        // 0x8006BFB0: nop
    
            goto L_8006C08C;
    }
    // 0x8006BFB0: nop

    // 0x8006BFB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006BFB8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BFBC: jal         0x8006BC8C
    // 0x8006BFC0: nop

    KeySpin_StepCellPulseX(rdram, ctx);
        goto after_0;
    // 0x8006BFC0: nop

    after_0:
    // 0x8006BFC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006BFC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BFCC: jal         0x8006BD94
    // 0x8006BFD0: nop

    KeySpin_StepCellPulseY(rdram, ctx);
        goto after_1;
    // 0x8006BFD0: nop

    after_1:
    // 0x8006BFD4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006BFD8: nop

    // 0x8006BFDC: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x8006BFE0: nop

    // 0x8006BFE4: bne         $t9, $zero, L_8006BFFC
    if (ctx->r25 != 0) {
        // 0x8006BFE8: nop
    
            goto L_8006BFFC;
    }
    // 0x8006BFE8: nop

    // 0x8006BFEC: lbu         $t0, 0x12($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X12);
    // 0x8006BFF0: nop

    // 0x8006BFF4: beq         $t0, $zero, L_8006C024
    if (ctx->r8 == 0) {
        // 0x8006BFF8: nop
    
            goto L_8006C024;
    }
    // 0x8006BFF8: nop

L_8006BFFC:
    // 0x8006BFFC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006C000: nop

    // 0x8006C004: lbu         $t2, 0x11($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X11);
    // 0x8006C008: nop

    // 0x8006C00C: bne         $t2, $zero, L_8006C030
    if (ctx->r10 != 0) {
        // 0x8006C010: nop
    
            goto L_8006C030;
    }
    // 0x8006C010: nop

    // 0x8006C014: lbu         $t3, 0x13($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X13);
    // 0x8006C018: nop

    // 0x8006C01C: bne         $t3, $zero, L_8006C030
    if (ctx->r11 != 0) {
        // 0x8006C020: nop
    
            goto L_8006C030;
    }
    // 0x8006C020: nop

L_8006C024:
    // 0x8006C024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006C028: jal         0x8006BE9C
    // 0x8006C02C: nop

    KeySpin_FinishCellPulses(rdram, ctx);
        goto after_2;
    // 0x8006C02C: nop

    after_2:
L_8006C030:
    // 0x8006C030: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8006C034: nop

    // 0x8006C038: lbu         $t5, 0x10($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X10);
    // 0x8006C03C: nop

    // 0x8006C040: bne         $t5, $zero, L_8006C08C
    if (ctx->r13 != 0) {
        // 0x8006C044: nop
    
            goto L_8006C08C;
    }
    // 0x8006C044: nop

    // 0x8006C048: lbu         $t6, 0x12($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X12);
    // 0x8006C04C: nop

    // 0x8006C050: beq         $t6, $zero, L_8006C08C
    if (ctx->r14 == 0) {
        // 0x8006C054: nop
    
            goto L_8006C08C;
    }
    // 0x8006C054: nop

    // 0x8006C058: lbu         $t7, 0x11($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X11);
    // 0x8006C05C: nop

    // 0x8006C060: bne         $t7, $zero, L_8006C08C
    if (ctx->r15 != 0) {
        // 0x8006C064: nop
    
            goto L_8006C08C;
    }
    // 0x8006C064: nop

    // 0x8006C068: lbu         $t9, 0x13($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X13);
    // 0x8006C06C: nop

    // 0x8006C070: beq         $t9, $zero, L_8006C08C
    if (ctx->r25 == 0) {
        // 0x8006C074: nop
    
            goto L_8006C08C;
    }
    // 0x8006C074: nop

    // 0x8006C078: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006C07C: sb          $t8, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r24;
    // 0x8006C080: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8006C084: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8006C088: sb          $t0, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r8;
L_8006C08C:
    // 0x8006C08C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C094: jr          $ra
    // 0x8006C098: nop

    return;
    // 0x8006C098: nop

;}

RECOMP_FUNC void KeySpin_InitPulseAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C09C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C0A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006C0A4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006C0A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C0AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006C0B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006C0B4: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x8006C0B8: jal         0x80067BC0
    // 0x8006C0BC: nop

    CurrentPiece_GetTopMinoRow(rdram, ctx);
        goto after_0;
    // 0x8006C0BC: nop

    after_0:
    // 0x8006C0C0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006C0C4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8006C0C8: sb          $t7, 0x58($t8)
    MEM_B(0X58, ctx->r24) = ctx->r15;
    // 0x8006C0CC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8006C0D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006C0D4: lbu         $t0, 0x58($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X58);
    // 0x8006C0D8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8006C0DC: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8006C0E0: beq         $at, $zero, L_8006C128
    if (ctx->r1 == 0) {
        // 0x8006C0E4: nop
    
            goto L_8006C128;
    }
    // 0x8006C0E4: nop

L_8006C0E8:
    // 0x8006C0E8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8006C0EC: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8006C0F0: addu        $t2, $t2, $s0
    ctx->r10 = ADD32(ctx->r10, ctx->r16);
    // 0x8006C0F4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8006C0F8: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x8006C0FC: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x8006C100: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8006C104: jal         0x8006BA24
    // 0x8006C108: addu        $a1, $s1, $s0
    ctx->r5 = ADD32(ctx->r17, ctx->r16);
    KeySpin_InitCellPulse(rdram, ctx);
        goto after_1;
    // 0x8006C108: addu        $a1, $s1, $s0
    ctx->r5 = ADD32(ctx->r17, ctx->r16);
    after_1:
    // 0x8006C10C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8006C110: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006C114: lbu         $t4, 0x58($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X58);
    // 0x8006C118: nop

    // 0x8006C11C: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8006C120: bne         $at, $zero, L_8006C0E8
    if (ctx->r1 != 0) {
        // 0x8006C124: nop
    
            goto L_8006C0E8;
    }
    // 0x8006C124: nop

L_8006C128:
    // 0x8006C128: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006C12C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8006C130: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x8006C134: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8006C138: nop

    // 0x8006C13C: sb          $zero, 0x1($t7)
    MEM_B(0X1, ctx->r15) = 0;
    // 0x8006C140: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006C144: nop

    // 0x8006C148: sb          $zero, 0x2($t8)
    MEM_B(0X2, ctx->r24) = 0;
    // 0x8006C14C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C150: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006C154: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006C158: jr          $ra
    // 0x8006C15C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006C15C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void KeySpin_StepPulseAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C160: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006C164: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006C168: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006C16C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006C170: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8006C174: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006C178: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006C17C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006C180: lbu         $t7, 0x58($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X58);
    // 0x8006C184: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006C188: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8006C18C: beq         $at, $zero, L_8006C1D0
    if (ctx->r1 == 0) {
        // 0x8006C190: nop
    
            goto L_8006C1D0;
    }
    // 0x8006C190: nop

L_8006C194:
    // 0x8006C194: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8006C198: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006C19C: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x8006C1A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8006C1A4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8006C1A8: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8006C1AC: jal         0x8006BF90
    // 0x8006C1B0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    KeySpin_StepCellPulse(rdram, ctx);
        goto after_0;
    // 0x8006C1B0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8006C1B4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006C1B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006C1BC: lbu         $t1, 0x58($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X58);
    // 0x8006C1C0: nop

    // 0x8006C1C4: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8006C1C8: bne         $at, $zero, L_8006C194
    if (ctx->r1 != 0) {
        // 0x8006C1CC: nop
    
            goto L_8006C194;
    }
    // 0x8006C1CC: nop

L_8006C1D0:
    // 0x8006C1D0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8006C1D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006C1D8: lbu         $t3, 0x58($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X58);
    // 0x8006C1DC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8006C1E0: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8006C1E4: beq         $at, $zero, L_8006C230
    if (ctx->r1 == 0) {
        // 0x8006C1E8: nop
    
            goto L_8006C230;
    }
    // 0x8006C1E8: nop

L_8006C1EC:
    // 0x8006C1EC: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8006C1F0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8006C1F4: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x8006C1F8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8006C1FC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8006C200: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x8006C204: nop

    // 0x8006C208: bne         $t7, $zero, L_8006C214
    if (ctx->r15 != 0) {
        // 0x8006C20C: nop
    
            goto L_8006C214;
    }
    // 0x8006C20C: nop

    // 0x8006C210: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8006C214:
    // 0x8006C214: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006C218: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006C21C: lbu         $t9, 0x58($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X58);
    // 0x8006C220: nop

    // 0x8006C224: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8006C228: bne         $at, $zero, L_8006C1EC
    if (ctx->r1 != 0) {
        // 0x8006C22C: nop
    
            goto L_8006C1EC;
    }
    // 0x8006C22C: nop

L_8006C230:
    // 0x8006C230: beq         $s1, $zero, L_8006C2E8
    if (ctx->r17 == 0) {
        // 0x8006C234: nop
    
            goto L_8006C2E8;
    }
    // 0x8006C234: nop

    // 0x8006C238: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006C23C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006C240: lbu         $t1, 0x58($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X58);
    // 0x8006C244: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006C248: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8006C24C: beq         $at, $zero, L_8006C298
    if (ctx->r1 == 0) {
        // 0x8006C250: nop
    
            goto L_8006C298;
    }
    // 0x8006C250: nop

L_8006C254:
    // 0x8006C254: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8006C258: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8006C25C: addu        $t3, $t3, $s0
    ctx->r11 = ADD32(ctx->r11, ctx->r16);
    // 0x8006C260: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8006C264: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8006C268: lbu         $t5, 0x9($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X9);
    // 0x8006C26C: nop

    // 0x8006C270: beq         $t5, $zero, L_8006C27C
    if (ctx->r13 == 0) {
        // 0x8006C274: nop
    
            goto L_8006C27C;
    }
    // 0x8006C274: nop

    // 0x8006C278: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8006C27C:
    // 0x8006C27C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006C280: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006C284: lbu         $t7, 0x58($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X58);
    // 0x8006C288: nop

    // 0x8006C28C: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8006C290: bne         $at, $zero, L_8006C254
    if (ctx->r1 != 0) {
        // 0x8006C294: nop
    
            goto L_8006C254;
    }
    // 0x8006C294: nop

L_8006C298:
    // 0x8006C298: beq         $s2, $zero, L_8006C2C4
    if (ctx->r18 == 0) {
        // 0x8006C29C: nop
    
            goto L_8006C2C4;
    }
    // 0x8006C29C: nop

    // 0x8006C2A0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8006C2A4: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8006C2A8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8006C2AC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006C2B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006C2B4: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x8006C2B8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8006C2BC: b           L_8006C300
    // 0x8006C2C0: sb          $t1, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r9;
        goto L_8006C300;
    // 0x8006C2C0: sb          $t1, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r9;
L_8006C2C4:
    // 0x8006C2C4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8006C2C8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8006C2CC: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
    // 0x8006C2D0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8006C2D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006C2D8: sb          $t4, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r12;
    // 0x8006C2DC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8006C2E0: b           L_8006C300
    // 0x8006C2E4: sb          $t6, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r14;
        goto L_8006C300;
    // 0x8006C2E4: sb          $t6, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r14;
L_8006C2E8:
    // 0x8006C2E8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006C2EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006C2F0: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    // 0x8006C2F4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006C2F8: nop

    // 0x8006C2FC: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
L_8006C300:
    // 0x8006C300: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006C304: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C308: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C30C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006C310: jr          $ra
    // 0x8006C314: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006C314: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void KeySpin_InitVPulse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C318: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006C31C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8006C320: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8006C324: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8006C328: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8006C32C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8006C330: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006C334: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8006C338: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006C33C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006C340: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006C344: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x8006C348: jal         0x80067D1C
    // 0x8006C34C: nop

    CurrentPiece_GetHeight(rdram, ctx);
        goto after_0;
    // 0x8006C34C: nop

    after_0:
    // 0x8006C350: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8006C354: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8006C358: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x8006C35C: jal         0x80067BC0
    // 0x8006C360: nop

    CurrentPiece_GetTopMinoRow(rdram, ctx);
        goto after_1;
    // 0x8006C360: nop

    after_1:
    // 0x8006C364: or          $s6, $s0, $zero
    ctx->r22 = ctx->r16 | 0;
    // 0x8006C368: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006C36C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8006C370: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006C374: beq         $s6, $at, L_8006C3A0
    if (ctx->r22 == ctx->r1) {
        // 0x8006C378: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8006C3A0;
    }
    // 0x8006C378: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8006C37C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006C380: beq         $s6, $at, L_8006C3AC
    if (ctx->r22 == ctx->r1) {
        // 0x8006C384: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8006C3AC;
    }
    // 0x8006C384: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006C388: beq         $s6, $at, L_8006C3F0
    if (ctx->r22 == ctx->r1) {
        // 0x8006C38C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8006C3F0;
    }
    // 0x8006C38C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006C390: beq         $s6, $at, L_8006C454
    if (ctx->r22 == ctx->r1) {
        // 0x8006C394: nop
    
            goto L_8006C454;
    }
    // 0x8006C394: nop

    // 0x8006C398: b           L_8006C4D8
    // 0x8006C39C: nop

        goto L_8006C4D8;
    // 0x8006C39C: nop

L_8006C3A0:
    // 0x8006C3A0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8006C3A4: b           L_8006C4EC
    // 0x8006C3A8: or          $s5, $s1, $zero
    ctx->r21 = ctx->r17 | 0;
        goto L_8006C4EC;
    // 0x8006C3A8: or          $s5, $s1, $zero
    ctx->r21 = ctx->r17 | 0;
L_8006C3AC:
    // 0x8006C3AC: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006C3B0: nop

    // 0x8006C3B4: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x8006C3B8: nop

    // 0x8006C3BC: beq         $t9, $zero, L_8006C3CC
    if (ctx->r25 == 0) {
        // 0x8006C3C0: nop
    
            goto L_8006C3CC;
    }
    // 0x8006C3C0: nop

    // 0x8006C3C4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8006C3C8: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
L_8006C3CC:
    // 0x8006C3CC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8006C3D0: nop

    // 0x8006C3D4: lbu         $t1, 0x1D($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1D);
    // 0x8006C3D8: nop

    // 0x8006C3DC: beq         $t1, $zero, L_8006C4EC
    if (ctx->r9 == 0) {
        // 0x8006C3E0: nop
    
            goto L_8006C4EC;
    }
    // 0x8006C3E0: nop

    // 0x8006C3E4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8006C3E8: b           L_8006C4EC
    // 0x8006C3EC: addiu       $s5, $s1, 0x1
    ctx->r21 = ADD32(ctx->r17, 0X1);
        goto L_8006C4EC;
    // 0x8006C3EC: addiu       $s5, $s1, 0x1
    ctx->r21 = ADD32(ctx->r17, 0X1);
L_8006C3F0:
    // 0x8006C3F0: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8006C3F4: nop

    // 0x8006C3F8: lbu         $t3, 0x9($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X9);
    // 0x8006C3FC: nop

    // 0x8006C400: beq         $t3, $zero, L_8006C410
    if (ctx->r11 == 0) {
        // 0x8006C404: nop
    
            goto L_8006C410;
    }
    // 0x8006C404: nop

    // 0x8006C408: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8006C40C: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
L_8006C410:
    // 0x8006C410: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8006C414: nop

    // 0x8006C418: lbu         $t5, 0x31($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X31);
    // 0x8006C41C: nop

    // 0x8006C420: beq         $t5, $zero, L_8006C430
    if (ctx->r13 == 0) {
        // 0x8006C424: nop
    
            goto L_8006C430;
    }
    // 0x8006C424: nop

    // 0x8006C428: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8006C42C: addiu       $s5, $s1, 0x2
    ctx->r21 = ADD32(ctx->r17, 0X2);
L_8006C430:
    // 0x8006C430: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8006C434: nop

    // 0x8006C438: lbu         $t7, 0x1D($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1D);
    // 0x8006C43C: nop

    // 0x8006C440: beq         $t7, $zero, L_8006C4EC
    if (ctx->r15 == 0) {
        // 0x8006C444: nop
    
            goto L_8006C4EC;
    }
    // 0x8006C444: nop

    // 0x8006C448: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8006C44C: b           L_8006C4EC
    // 0x8006C450: addiu       $s5, $s1, 0x1
    ctx->r21 = ADD32(ctx->r17, 0X1);
        goto L_8006C4EC;
    // 0x8006C450: addiu       $s5, $s1, 0x1
    ctx->r21 = ADD32(ctx->r17, 0X1);
L_8006C454:
    // 0x8006C454: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006C458: nop

    // 0x8006C45C: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x8006C460: nop

    // 0x8006C464: beq         $t9, $zero, L_8006C474
    if (ctx->r25 == 0) {
        // 0x8006C468: nop
    
            goto L_8006C474;
    }
    // 0x8006C468: nop

    // 0x8006C46C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8006C470: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
L_8006C474:
    // 0x8006C474: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8006C478: nop

    // 0x8006C47C: lbu         $t1, 0x1D($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1D);
    // 0x8006C480: nop

    // 0x8006C484: beq         $t1, $zero, L_8006C494
    if (ctx->r9 == 0) {
        // 0x8006C488: nop
    
            goto L_8006C494;
    }
    // 0x8006C488: nop

    // 0x8006C48C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8006C490: addiu       $s4, $s1, 0x1
    ctx->r20 = ADD32(ctx->r17, 0X1);
L_8006C494:
    // 0x8006C494: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8006C498: nop

    // 0x8006C49C: lbu         $t3, 0x45($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X45);
    // 0x8006C4A0: nop

    // 0x8006C4A4: beq         $t3, $zero, L_8006C4B4
    if (ctx->r11 == 0) {
        // 0x8006C4A8: nop
    
            goto L_8006C4B4;
    }
    // 0x8006C4A8: nop

    // 0x8006C4AC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8006C4B0: addiu       $s5, $s1, 0x3
    ctx->r21 = ADD32(ctx->r17, 0X3);
L_8006C4B4:
    // 0x8006C4B4: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8006C4B8: nop

    // 0x8006C4BC: lbu         $t5, 0x31($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X31);
    // 0x8006C4C0: nop

    // 0x8006C4C4: beq         $t5, $zero, L_8006C4EC
    if (ctx->r13 == 0) {
        // 0x8006C4C8: nop
    
            goto L_8006C4EC;
    }
    // 0x8006C4C8: nop

    // 0x8006C4CC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8006C4D0: b           L_8006C4EC
    // 0x8006C4D4: addiu       $s5, $s1, 0x2
    ctx->r21 = ADD32(ctx->r17, 0X2);
        goto L_8006C4EC;
    // 0x8006C4D4: addiu       $s5, $s1, 0x2
    ctx->r21 = ADD32(ctx->r17, 0X2);
L_8006C4D8:
    // 0x8006C4D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C4DC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006C4E0: addiu       $a1, $a1, -0x286C
    ctx->r5 = ADD32(ctx->r5, -0X286C);
    // 0x8006C4E4: jal         0x80083560
    // 0x8006C4E8: addiu       $a0, $a0, -0x2880
    ctx->r4 = ADD32(ctx->r4, -0X2880);
    debug_print_reason_routine(rdram, ctx);
        goto after_2;
    // 0x8006C4E8: addiu       $a0, $a0, -0x2880
    ctx->r4 = ADD32(ctx->r4, -0X2880);
    after_2:
L_8006C4EC:
    // 0x8006C4EC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8006C4F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8006C4F4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8006C4F8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8006C4FC: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x8006C500: jal         0x8006B938
    // 0x8006C504: addiu       $a0, $a0, 0x59
    ctx->r4 = ADD32(ctx->r4, 0X59);
    KeySpin_InitVPulseState(rdram, ctx);
        goto after_3;
    // 0x8006C504: addiu       $a0, $a0, 0x59
    ctx->r4 = ADD32(ctx->r4, 0X59);
    after_3:
    // 0x8006C508: beq         $s2, $zero, L_8006C538
    if (ctx->r18 == 0) {
        // 0x8006C50C: nop
    
            goto L_8006C538;
    }
    // 0x8006C50C: nop

    // 0x8006C510: beq         $s3, $zero, L_8006C538
    if (ctx->r19 == 0) {
        // 0x8006C514: nop
    
            goto L_8006C538;
    }
    // 0x8006C514: nop

    // 0x8006C518: jal         0x8006DCD0
    // 0x8006C51C: nop

    BoardP_FindFirstOccupiedRow(rdram, ctx);
        goto after_4;
    // 0x8006C51C: nop

    after_4:
    // 0x8006C520: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8006C524: jal         0x8006DD1C
    // 0x8006C528: sb          $v0, 0x66($t6)
    MEM_B(0X66, ctx->r14) = ctx->r2;
    BoardP_FindLastOccupiedRow(rdram, ctx);
        goto after_5;
    // 0x8006C528: sb          $v0, 0x66($t6)
    MEM_B(0X66, ctx->r14) = ctx->r2;
    after_5:
    // 0x8006C52C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8006C530: b           L_8006C578
    // 0x8006C534: sb          $v0, 0x67($t7)
    MEM_B(0X67, ctx->r15) = ctx->r2;
        goto L_8006C578;
    // 0x8006C534: sb          $v0, 0x67($t7)
    MEM_B(0X67, ctx->r15) = ctx->r2;
L_8006C538:
    // 0x8006C538: beq         $s2, $zero, L_8006C560
    if (ctx->r18 == 0) {
        // 0x8006C53C: nop
    
            goto L_8006C560;
    }
    // 0x8006C53C: nop

    // 0x8006C540: jal         0x8006DCD0
    // 0x8006C544: nop

    BoardP_FindFirstOccupiedRow(rdram, ctx);
        goto after_6;
    // 0x8006C544: nop

    after_6:
    // 0x8006C548: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006C54C: nop

    // 0x8006C550: sb          $v0, 0x66($t8)
    MEM_B(0X66, ctx->r24) = ctx->r2;
    // 0x8006C554: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8006C558: b           L_8006C578
    // 0x8006C55C: sb          $s4, 0x67($t9)
    MEM_B(0X67, ctx->r25) = ctx->r20;
        goto L_8006C578;
    // 0x8006C55C: sb          $s4, 0x67($t9)
    MEM_B(0X67, ctx->r25) = ctx->r20;
L_8006C560:
    // 0x8006C560: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8006C564: jal         0x8006DD1C
    // 0x8006C568: sb          $s5, 0x66($t0)
    MEM_B(0X66, ctx->r8) = ctx->r21;
    BoardP_FindLastOccupiedRow(rdram, ctx);
        goto after_7;
    // 0x8006C568: sb          $s5, 0x66($t0)
    MEM_B(0X66, ctx->r8) = ctx->r21;
    after_7:
    // 0x8006C56C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8006C570: nop

    // 0x8006C574: sb          $v0, 0x67($t1)
    MEM_B(0X67, ctx->r9) = ctx->r2;
L_8006C578:
    // 0x8006C578: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8006C57C: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8006C580: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x8006C584: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8006C588: nop

    // 0x8006C58C: sb          $zero, 0x1($t4)
    MEM_B(0X1, ctx->r12) = 0;
    // 0x8006C590: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8006C594: nop

    // 0x8006C598: sb          $zero, 0x2($t5)
    MEM_B(0X2, ctx->r13) = 0;
    // 0x8006C59C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8006C5A0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8006C5A4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8006C5A8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8006C5AC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8006C5B0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8006C5B4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8006C5B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006C5BC: jr          $ra
    // 0x8006C5C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006C5C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}

RECOMP_FUNC void KeySpin_StepSlideState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C5C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C5C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006C5CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006C5D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006C5D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C5D8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C5DC: jal         0x8006B8B8
    // 0x8006C5E0: addiu       $a0, $a0, 0x59
    ctx->r4 = ADD32(ctx->r4, 0X59);
    KeySpin_StepSlide(rdram, ctx);
        goto after_0;
    // 0x8006C5E0: addiu       $a0, $a0, 0x59
    ctx->r4 = ADD32(ctx->r4, 0X59);
    after_0:
    // 0x8006C5E4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006C5E8: nop

    // 0x8006C5EC: lbu         $t7, 0x59($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X59);
    // 0x8006C5F0: nop

    // 0x8006C5F4: beq         $t7, $zero, L_8006C610
    if (ctx->r15 == 0) {
        // 0x8006C5F8: nop
    
            goto L_8006C610;
    }
    // 0x8006C5F8: nop

    // 0x8006C5FC: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x8006C600: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8006C604: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006C608: b           L_8006C634
    // 0x8006C60C: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
        goto L_8006C634;
    // 0x8006C60C: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
L_8006C610:
    // 0x8006C610: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006C614: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x8006C618: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x8006C61C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8006C620: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006C624: sb          $zero, 0x1($t2)
    MEM_B(0X1, ctx->r10) = 0;
    // 0x8006C628: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8006C62C: nop

    // 0x8006C630: sb          $t3, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r11;
L_8006C634:
    // 0x8006C634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C63C: jr          $ra
    // 0x8006C640: nop

    return;
    // 0x8006C640: nop

;}

RECOMP_FUNC void KeySpin_EnterDrop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006C64C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006C650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C654: jal         0x8006B454
    // 0x8006C658: addiu       $a0, $a0, 0x62
    ctx->r4 = ADD32(ctx->r4, 0X62);
    KeySpin_InitDrop(rdram, ctx);
        goto after_0;
    // 0x8006C658: addiu       $a0, $a0, 0x62
    ctx->r4 = ADD32(ctx->r4, 0X62);
    after_0:
    // 0x8006C65C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006C660: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8006C664: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8006C668: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006C66C: nop

    // 0x8006C670: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    // 0x8006C674: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8006C678: nop

    // 0x8006C67C: sb          $zero, 0x2($t9)
    MEM_B(0X2, ctx->r25) = 0;
    // 0x8006C680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C688: jr          $ra
    // 0x8006C68C: nop

    return;
    // 0x8006C68C: nop

;}

RECOMP_FUNC void KeySpin_UpdateDrop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006C698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006C69C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006C6A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C6A4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C6A8: jal         0x8006B478
    // 0x8006C6AC: addiu       $a0, $a0, 0x62
    ctx->r4 = ADD32(ctx->r4, 0X62);
    KeySpin_StepDrop(rdram, ctx);
        goto after_0;
    // 0x8006C6AC: addiu       $a0, $a0, 0x62
    ctx->r4 = ADD32(ctx->r4, 0X62);
    after_0:
    // 0x8006C6B0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006C6B4: nop

    // 0x8006C6B8: lbu         $t7, 0x62($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X62);
    // 0x8006C6BC: nop

    // 0x8006C6C0: beq         $t7, $zero, L_8006C6DC
    if (ctx->r15 == 0) {
        // 0x8006C6C4: nop
    
            goto L_8006C6DC;
    }
    // 0x8006C6C4: nop

    // 0x8006C6C8: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x8006C6CC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8006C6D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006C6D4: b           L_8006C700
    // 0x8006C6D8: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
        goto L_8006C700;
    // 0x8006C6D8: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
L_8006C6DC:
    // 0x8006C6DC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8006C6E0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8006C6E4: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8006C6E8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8006C6EC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006C6F0: sb          $t1, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r9;
    // 0x8006C6F4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8006C6F8: nop

    // 0x8006C6FC: sb          $t3, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r11;
L_8006C700:
    // 0x8006C700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C708: jr          $ra
    // 0x8006C70C: nop

    return;
    // 0x8006C70C: nop

;}

RECOMP_FUNC void KeySpin_CheckCellsMatched(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C710: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006C714: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8006C718: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8006C71C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006C720: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006C724: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8006C728: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8006C72C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8006C730: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8006C734: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006C738: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006C73C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006C740: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006C744: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8006C748: lw          $s0, 0x4($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X4);
    // 0x8006C74C: beq         $at, $zero, L_8006C810
    if (ctx->r1 == 0) {
        // 0x8006C750: nop
    
            goto L_8006C810;
    }
    // 0x8006C750: nop

L_8006C754:
    // 0x8006C754: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    // 0x8006C758: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x8006C75C: lbu         $at, 0x15($t9)
    ctx->r1 = MEM_BU(ctx->r25, 0X15);
    // 0x8006C760: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x8006C764: sb          $at, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r1;
    // 0x8006C768: lbu         $t1, 0x16($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X16);
    // 0x8006C76C: nop

    // 0x8006C770: sb          $t1, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r9;
    // 0x8006C774: lb          $a0, 0x50($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X50);
    // 0x8006C778: lb          $a1, 0x51($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X51);
    // 0x8006C77C: jal         0x8006E5E0
    // 0x8006C780: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_0;
    // 0x8006C780: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_0:
    // 0x8006C784: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8006C788: lbu         $t2, 0x0($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X0);
    // 0x8006C78C: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8006C790: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8006C794: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
    // 0x8006C798: lb          $a1, 0x51($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X51);
    // 0x8006C79C: lb          $a0, 0x50($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X50);
    // 0x8006C7A0: jal         0x8006E5E0
    // 0x8006C7A4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_1;
    // 0x8006C7A4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_1:
    // 0x8006C7A8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8006C7AC: lbu         $t4, 0x0($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X0);
    // 0x8006C7B0: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8006C7B4: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8006C7B8: sb          $t5, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r13;
    // 0x8006C7BC: lb          $a0, 0x50($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X50);
    // 0x8006C7C0: lb          $a1, 0x51($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X51);
    // 0x8006C7C4: jal         0x8006E5E0
    // 0x8006C7C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_2;
    // 0x8006C7C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_2:
    // 0x8006C7CC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8006C7D0: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x8006C7D4: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8006C7D8: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8006C7DC: sb          $t8, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r24;
    // 0x8006C7E0: lb          $a1, 0x51($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X51);
    // 0x8006C7E4: lb          $a0, 0x50($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X50);
    // 0x8006C7E8: jal         0x8006E5E0
    // 0x8006C7EC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_3;
    // 0x8006C7EC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_3:
    // 0x8006C7F0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8006C7F4: lbu         $t0, 0x0($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X0);
    // 0x8006C7F8: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8006C7FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006C800: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x8006C804: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8006C808: bne         $at, $zero, L_8006C754
    if (ctx->r1 != 0) {
        // 0x8006C80C: sb          $t7, 0x0($s2)
        MEM_B(0X0, ctx->r18) = ctx->r15;
            goto L_8006C754;
    }
    // 0x8006C80C: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
L_8006C810:
    // 0x8006C810: lb          $t9, 0x16($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X16);
    // 0x8006C814: lb          $t2, 0x15($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X15);
    // 0x8006C818: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8006C81C: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8006C820: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006C824: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006C828: lw          $t5, -0x430($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X430);
    // 0x8006C82C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8006C830: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8006C834: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x8006C838: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8006C83C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8006C840: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8006C844: lbu         $s4, 0x2($t8)
    ctx->r20 = MEM_BU(ctx->r24, 0X2);
    // 0x8006C848: beq         $at, $zero, L_8006C9A0
    if (ctx->r1 == 0) {
        // 0x8006C84C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8006C9A0;
    }
    // 0x8006C84C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8006C850:
    // 0x8006C850: sll         $t7, $s5, 1
    ctx->r15 = S32(ctx->r21 << 1);
    // 0x8006C854: addu        $t9, $s0, $t7
    ctx->r25 = ADD32(ctx->r16, ctx->r15);
    // 0x8006C858: lbu         $at, 0x15($t9)
    ctx->r1 = MEM_BU(ctx->r25, 0X15);
    // 0x8006C85C: addiu       $t0, $sp, 0x3C
    ctx->r8 = ADD32(ctx->r29, 0X3C);
    // 0x8006C860: sb          $at, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r1;
    // 0x8006C864: lbu         $t2, 0x16($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X16);
    // 0x8006C868: nop

    // 0x8006C86C: sb          $t2, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r10;
    // 0x8006C870: lb          $a0, 0x3C($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X3C);
    // 0x8006C874: lb          $a1, 0x3D($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X3D);
    // 0x8006C878: jal         0x8006E5E0
    // 0x8006C87C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_4;
    // 0x8006C87C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_4:
    // 0x8006C880: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8006C884: lbu         $t3, 0x2($s6)
    ctx->r11 = MEM_BU(ctx->r22, 0X2);
    // 0x8006C888: nop

    // 0x8006C88C: beq         $t3, $s4, L_8006C8B8
    if (ctx->r11 == ctx->r20) {
        // 0x8006C890: nop
    
            goto L_8006C8B8;
    }
    // 0x8006C890: nop

    // 0x8006C894: lbu         $t5, 0x0($s6)
    ctx->r13 = MEM_BU(ctx->r22, 0X0);
    // 0x8006C898: nop

    // 0x8006C89C: andi        $t4, $t5, 0x4
    ctx->r12 = ctx->r13 & 0X4;
    // 0x8006C8A0: bne         $t4, $zero, L_8006C8B8
    if (ctx->r12 != 0) {
        // 0x8006C8A4: nop
    
            goto L_8006C8B8;
    }
    // 0x8006C8A4: nop

    // 0x8006C8A8: lbu         $t6, 0x0($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X0);
    // 0x8006C8AC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8006C8B0: ori         $t8, $t6, 0x4
    ctx->r24 = ctx->r14 | 0X4;
    // 0x8006C8B4: sb          $t8, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r24;
L_8006C8B8:
    // 0x8006C8B8: lb          $a1, 0x3D($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X3D);
    // 0x8006C8BC: lb          $a0, 0x3C($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X3C);
    // 0x8006C8C0: jal         0x8006E5E0
    // 0x8006C8C4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_5;
    // 0x8006C8C4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_5:
    // 0x8006C8C8: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8006C8CC: lbu         $t7, 0x2($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X2);
    // 0x8006C8D0: nop

    // 0x8006C8D4: beq         $t7, $s4, L_8006C900
    if (ctx->r15 == ctx->r20) {
        // 0x8006C8D8: nop
    
            goto L_8006C900;
    }
    // 0x8006C8D8: nop

    // 0x8006C8DC: lbu         $t1, 0x0($s6)
    ctx->r9 = MEM_BU(ctx->r22, 0X0);
    // 0x8006C8E0: nop

    // 0x8006C8E4: andi        $t0, $t1, 0x4
    ctx->r8 = ctx->r9 & 0X4;
    // 0x8006C8E8: bne         $t0, $zero, L_8006C900
    if (ctx->r8 != 0) {
        // 0x8006C8EC: nop
    
            goto L_8006C900;
    }
    // 0x8006C8EC: nop

    // 0x8006C8F0: lbu         $t9, 0x0($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X0);
    // 0x8006C8F4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8006C8F8: ori         $t2, $t9, 0x4
    ctx->r10 = ctx->r25 | 0X4;
    // 0x8006C8FC: sb          $t2, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r10;
L_8006C900:
    // 0x8006C900: lb          $a0, 0x3C($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X3C);
    // 0x8006C904: lb          $a1, 0x3D($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X3D);
    // 0x8006C908: jal         0x8006E5E0
    // 0x8006C90C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_6;
    // 0x8006C90C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_6:
    // 0x8006C910: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8006C914: lbu         $t3, 0x2($s6)
    ctx->r11 = MEM_BU(ctx->r22, 0X2);
    // 0x8006C918: nop

    // 0x8006C91C: beq         $t3, $s4, L_8006C948
    if (ctx->r11 == ctx->r20) {
        // 0x8006C920: nop
    
            goto L_8006C948;
    }
    // 0x8006C920: nop

    // 0x8006C924: lbu         $t5, 0x0($s6)
    ctx->r13 = MEM_BU(ctx->r22, 0X0);
    // 0x8006C928: nop

    // 0x8006C92C: andi        $t4, $t5, 0x4
    ctx->r12 = ctx->r13 & 0X4;
    // 0x8006C930: bne         $t4, $zero, L_8006C948
    if (ctx->r12 != 0) {
        // 0x8006C934: nop
    
            goto L_8006C948;
    }
    // 0x8006C934: nop

    // 0x8006C938: lbu         $t6, 0x0($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X0);
    // 0x8006C93C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8006C940: ori         $t8, $t6, 0x4
    ctx->r24 = ctx->r14 | 0X4;
    // 0x8006C944: sb          $t8, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r24;
L_8006C948:
    // 0x8006C948: lb          $a1, 0x3D($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X3D);
    // 0x8006C94C: lb          $a0, 0x3C($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X3C);
    // 0x8006C950: jal         0x8006E5E0
    // 0x8006C954: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_7;
    // 0x8006C954: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_7:
    // 0x8006C958: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8006C95C: lbu         $t7, 0x2($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X2);
    // 0x8006C960: nop

    // 0x8006C964: beq         $t7, $s4, L_8006C990
    if (ctx->r15 == ctx->r20) {
        // 0x8006C968: nop
    
            goto L_8006C990;
    }
    // 0x8006C968: nop

    // 0x8006C96C: lbu         $t1, 0x0($s6)
    ctx->r9 = MEM_BU(ctx->r22, 0X0);
    // 0x8006C970: nop

    // 0x8006C974: andi        $t0, $t1, 0x4
    ctx->r8 = ctx->r9 & 0X4;
    // 0x8006C978: bne         $t0, $zero, L_8006C990
    if (ctx->r8 != 0) {
        // 0x8006C97C: nop
    
            goto L_8006C990;
    }
    // 0x8006C97C: nop

    // 0x8006C980: lbu         $t9, 0x0($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X0);
    // 0x8006C984: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8006C988: ori         $t2, $t9, 0x4
    ctx->r10 = ctx->r25 | 0X4;
    // 0x8006C98C: sb          $t2, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r10;
L_8006C990:
    // 0x8006C990: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8006C994: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8006C998: bne         $at, $zero, L_8006C850
    if (ctx->r1 != 0) {
        // 0x8006C99C: nop
    
            goto L_8006C850;
    }
    // 0x8006C99C: nop

L_8006C9A0:
    // 0x8006C9A0: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8006C9A4: beq         $at, $zero, L_8006C9B4
    if (ctx->r1 == 0) {
        // 0x8006C9A8: nop
    
            goto L_8006C9B4;
    }
    // 0x8006C9A8: nop

    // 0x8006C9AC: b           L_8006CA64
    // 0x8006C9B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006CA64;
    // 0x8006C9B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006C9B4:
    // 0x8006C9B4: lb          $t3, 0x16($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X16);
    // 0x8006C9B8: lb          $t4, 0x15($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X15);
    // 0x8006C9BC: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8006C9C0: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8006C9C4: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8006C9C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006C9CC: lw          $t7, -0x430($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X430);
    // 0x8006C9D0: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x8006C9D4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8006C9D8: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8006C9DC: lw          $s7, 0x4($t1)
    ctx->r23 = MEM_W(ctx->r9, 0X4);
    // 0x8006C9E0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006C9E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006C9E8: jal         0x8006D9D8
    // 0x8006C9EC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    BoardP_CanGroupMove(rdram, ctx);
        goto after_8;
    // 0x8006C9EC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_8:
    // 0x8006C9F0: beq         $v0, $zero, L_8006CA00
    if (ctx->r2 == 0) {
        // 0x8006C9F4: nop
    
            goto L_8006CA00;
    }
    // 0x8006C9F4: nop

    // 0x8006C9F8: b           L_8006CA64
    // 0x8006C9FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006CA64;
    // 0x8006C9FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006CA00:
    // 0x8006CA00: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8006CA04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006CA08: jal         0x8006D9D8
    // 0x8006CA0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    BoardP_CanGroupMove(rdram, ctx);
        goto after_9;
    // 0x8006CA0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8006CA10: beq         $v0, $zero, L_8006CA20
    if (ctx->r2 == 0) {
        // 0x8006CA14: nop
    
            goto L_8006CA20;
    }
    // 0x8006CA14: nop

    // 0x8006CA18: b           L_8006CA64
    // 0x8006CA1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006CA64;
    // 0x8006CA1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006CA20:
    // 0x8006CA20: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8006CA24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006CA28: jal         0x8006D9D8
    // 0x8006CA2C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    BoardP_CanGroupMove(rdram, ctx);
        goto after_10;
    // 0x8006CA2C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_10:
    // 0x8006CA30: beq         $v0, $zero, L_8006CA40
    if (ctx->r2 == 0) {
        // 0x8006CA34: nop
    
            goto L_8006CA40;
    }
    // 0x8006CA34: nop

    // 0x8006CA38: b           L_8006CA64
    // 0x8006CA3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006CA64;
    // 0x8006CA3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006CA40:
    // 0x8006CA40: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8006CA44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006CA48: jal         0x8006D9D8
    // 0x8006CA4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    BoardP_CanGroupMove(rdram, ctx);
        goto after_11;
    // 0x8006CA4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x8006CA50: beq         $v0, $zero, L_8006CA60
    if (ctx->r2 == 0) {
        // 0x8006CA54: nop
    
            goto L_8006CA60;
    }
    // 0x8006CA54: nop

    // 0x8006CA58: b           L_8006CA64
    // 0x8006CA5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006CA64;
    // 0x8006CA5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006CA60:
    // 0x8006CA60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006CA64:
    // 0x8006CA64: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006CA68: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006CA6C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006CA70: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CA74: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006CA78: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8006CA7C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8006CA80: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CA84: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8006CA88: jr          $ra
    // 0x8006CA8C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006CA8C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}

RECOMP_FUNC void KeySpin_EvalSpin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CA90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CA94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006CA98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CA9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006CAA0: jal         0x8006C710
    // 0x8006CAA4: nop

    KeySpin_CheckCellsMatched(rdram, ctx);
        goto after_0;
    // 0x8006CAA4: nop

    after_0:
    // 0x8006CAA8: beq         $v0, $zero, L_8006CADC
    if (ctx->r2 == 0) {
        // 0x8006CAAC: nop
    
            goto L_8006CADC;
    }
    // 0x8006CAAC: nop

    // 0x8006CAB0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006CAB4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8006CAB8: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8006CABC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006CAC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CAC4: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    // 0x8006CAC8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8006CACC: nop

    // 0x8006CAD0: sb          $zero, 0x2($t9)
    MEM_B(0X2, ctx->r25) = 0;
    // 0x8006CAD4: b           L_8006CB00
    // 0x8006CAD8: sb          $zero, -0xB0($at)
    MEM_B(-0XB0, ctx->r1) = 0;
        goto L_8006CB00;
    // 0x8006CAD8: sb          $zero, -0xB0($at)
    MEM_B(-0XB0, ctx->r1) = 0;
L_8006CADC:
    // 0x8006CADC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8006CAE0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006CAE4: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8006CAE8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8006CAEC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006CAF0: sb          $t1, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r9;
    // 0x8006CAF4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8006CAF8: nop

    // 0x8006CAFC: sb          $t3, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r11;
L_8006CB00:
    // 0x8006CB00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CB04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CB08: jr          $ra
    // 0x8006CB0C: nop

    return;
    // 0x8006CB0C: nop

;}

RECOMP_FUNC void KeySpin_Process(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CB10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CB14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CB18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006CB1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_8006CB20:
    // 0x8006CB20: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006CB24: nop

    // 0x8006CB28: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8006CB2C: nop

    // 0x8006CB30: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x8006CB34: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x8006CB38: beq         $at, $zero, L_8006CC4C
    if (ctx->r1 == 0) {
        // 0x8006CB3C: nop
    
            goto L_8006CC4C;
    }
    // 0x8006CB3C: nop

    // 0x8006CB40: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006CB44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CB48: addu        $at, $at, $t8
    gpr jr_addend_8006CB54 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8006CB4C: lw          $t8, -0x2860($at)
    ctx->r24 = ADD32(ctx->r1, -0X2860);
    // 0x8006CB50: nop

    // 0x8006CB54: jr          $t8
    // 0x8006CB58: nop

    switch (jr_addend_8006CB54 >> 2) {
        case 0: goto L_8006CB5C; break;
        case 1: goto L_8006CB70; break;
        case 2: goto L_8006CBB4; break;
        case 3: goto L_8006CBCC; break;
        case 4: goto L_8006CC10; break;
        case 5: goto L_8006CC28; break;
        case 6: goto L_8006CC3C; break;
        default: switch_error(__func__, 0x8006CB54, 0x800DD7A0);
    }
    // 0x8006CB58: nop

L_8006CB5C:
    // 0x8006CB5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006CB60: jal         0x8006CA90
    // 0x8006CB64: nop

    KeySpin_EvalSpin(rdram, ctx);
        goto after_0;
    // 0x8006CB64: nop

    after_0:
    // 0x8006CB68: b           L_8006CC4C
    // 0x8006CB6C: nop

        goto L_8006CC4C;
    // 0x8006CB6C: nop

L_8006CB70:
    // 0x8006CB70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006CB74: jal         0x8006C09C
    // 0x8006CB78: nop

    KeySpin_InitPulseAll(rdram, ctx);
        goto after_1;
    // 0x8006CB78: nop

    after_1:
    // 0x8006CB7C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CB80: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006CB84: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x8006CB88: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8006CB8C: jal         0x8008A5C8
    // 0x8006CB90: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Audio2_Play_SFX(rdram, ctx);
        goto after_2;
    // 0x8006CB90: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x8006CB94: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CB98: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006CB9C: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x8006CBA0: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8006CBA4: jal         0x8008A5C8
    // 0x8006CBA8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    Audio2_Play_SFX(rdram, ctx);
        goto after_3;
    // 0x8006CBA8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_3:
    // 0x8006CBAC: b           L_8006CC4C
    // 0x8006CBB0: nop

        goto L_8006CC4C;
    // 0x8006CBB0: nop

L_8006CBB4:
    // 0x8006CBB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006CBB8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CBBC: jal         0x8006C160
    // 0x8006CBC0: nop

    KeySpin_StepPulseAll(rdram, ctx);
        goto after_4;
    // 0x8006CBC0: nop

    after_4:
    // 0x8006CBC4: b           L_8006CC4C
    // 0x8006CBC8: nop

        goto L_8006CC4C;
    // 0x8006CBC8: nop

L_8006CBCC:
    // 0x8006CBCC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CBD0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006CBD4: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x8006CBD8: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8006CBDC: jal         0x8008A5C8
    // 0x8006CBE0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Audio2_Play_SFX(rdram, ctx);
        goto after_5;
    // 0x8006CBE0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x8006CBE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CBE8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006CBEC: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x8006CBF0: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8006CBF4: jal         0x8008A5C8
    // 0x8006CBF8: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    Audio2_Play_SFX(rdram, ctx);
        goto after_6;
    // 0x8006CBF8: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    after_6:
    // 0x8006CBFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006CC00: jal         0x8006C318
    // 0x8006CC04: nop

    KeySpin_InitVPulse(rdram, ctx);
        goto after_7;
    // 0x8006CC04: nop

    after_7:
    // 0x8006CC08: b           L_8006CC4C
    // 0x8006CC0C: nop

        goto L_8006CC4C;
    // 0x8006CC0C: nop

L_8006CC10:
    // 0x8006CC10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006CC14: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CC18: jal         0x8006C5C4
    // 0x8006CC1C: nop

    KeySpin_StepSlideState(rdram, ctx);
        goto after_8;
    // 0x8006CC1C: nop

    after_8:
    // 0x8006CC20: b           L_8006CC4C
    // 0x8006CC24: nop

        goto L_8006CC4C;
    // 0x8006CC24: nop

L_8006CC28:
    // 0x8006CC28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006CC2C: jal         0x8006C644
    // 0x8006CC30: nop

    KeySpin_EnterDrop(rdram, ctx);
        goto after_9;
    // 0x8006CC30: nop

    after_9:
    // 0x8006CC34: b           L_8006CC4C
    // 0x8006CC38: nop

        goto L_8006CC4C;
    // 0x8006CC38: nop

L_8006CC3C:
    // 0x8006CC3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006CC40: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CC44: jal         0x8006C690
    // 0x8006CC48: nop

    KeySpin_UpdateDrop(rdram, ctx);
        goto after_10;
    // 0x8006CC48: nop

    after_10:
L_8006CC4C:
    // 0x8006CC4C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8006CC50: nop

    // 0x8006CC54: lbu         $t0, 0x2($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2);
    // 0x8006CC58: nop

    // 0x8006CC5C: beq         $t0, $zero, L_8006CB20
    if (ctx->r8 == 0) {
        // 0x8006CC60: nop
    
            goto L_8006CB20;
    }
    // 0x8006CC60: nop

    // 0x8006CC64: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006CC68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CC6C: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x8006CC70: jr          $ra
    // 0x8006CC74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006CC74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CC78: nop

    // 0x8006CC7C: nop

;}

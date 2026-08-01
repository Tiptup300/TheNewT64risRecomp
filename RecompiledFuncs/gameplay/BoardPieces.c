#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void BoardPieces_SwapCubes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E0E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006E0EC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006E0F0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006E0F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006E0F8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8006E0FC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8006E100: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8006E104: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006E108: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006E10C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006E110: bltz        $t6, L_8006E13C
    if (SIGNED(ctx->r14) < 0) {
        // 0x8006E114: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8006E13C;
    }
    // 0x8006E114: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006E118: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x8006E11C: beq         $at, $zero, L_8006E13C
    if (ctx->r1 == 0) {
        // 0x8006E120: nop
    
            goto L_8006E13C;
    }
    // 0x8006E120: nop

    // 0x8006E124: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8006E128: nop

    // 0x8006E12C: bltz        $t7, L_8006E13C
    if (SIGNED(ctx->r15) < 0) {
        // 0x8006E130: slti        $at, $t7, 0x14
        ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
            goto L_8006E13C;
    }
    // 0x8006E130: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x8006E134: bne         $at, $zero, L_8006E150
    if (ctx->r1 != 0) {
        // 0x8006E138: nop
    
            goto L_8006E150;
    }
    // 0x8006E138: nop

L_8006E13C:
    // 0x8006E13C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006E140: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006E144: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    // 0x8006E148: jal         0x80083560
    // 0x8006E14C: addiu       $a0, $a0, -0x277C
    ctx->r4 = ADD32(ctx->r4, -0X277C);
    debug_print_reason_routine(rdram, ctx);
        goto after_0;
    // 0x8006E14C: addiu       $a0, $a0, -0x277C
    ctx->r4 = ADD32(ctx->r4, -0X277C);
    after_0:
L_8006E150:
    // 0x8006E150: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8006E154: nop

    // 0x8006E158: bltz        $t8, L_8006E180
    if (SIGNED(ctx->r24) < 0) {
        // 0x8006E15C: slti        $at, $t8, 0xA
        ctx->r1 = SIGNED(ctx->r24) < 0XA ? 1 : 0;
            goto L_8006E180;
    }
    // 0x8006E15C: slti        $at, $t8, 0xA
    ctx->r1 = SIGNED(ctx->r24) < 0XA ? 1 : 0;
    // 0x8006E160: beq         $at, $zero, L_8006E180
    if (ctx->r1 == 0) {
        // 0x8006E164: nop
    
            goto L_8006E180;
    }
    // 0x8006E164: nop

    // 0x8006E168: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8006E16C: nop

    // 0x8006E170: bltz        $t9, L_8006E180
    if (SIGNED(ctx->r25) < 0) {
        // 0x8006E174: slti        $at, $t9, 0x14
        ctx->r1 = SIGNED(ctx->r25) < 0X14 ? 1 : 0;
            goto L_8006E180;
    }
    // 0x8006E174: slti        $at, $t9, 0x14
    ctx->r1 = SIGNED(ctx->r25) < 0X14 ? 1 : 0;
    // 0x8006E178: bne         $at, $zero, L_8006E194
    if (ctx->r1 != 0) {
        // 0x8006E17C: nop
    
            goto L_8006E194;
    }
    // 0x8006E17C: nop

L_8006E180:
    // 0x8006E180: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006E184: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006E188: addiu       $a1, $a1, -0x273C
    ctx->r5 = ADD32(ctx->r5, -0X273C);
    // 0x8006E18C: jal         0x80083560
    // 0x8006E190: addiu       $a0, $a0, -0x2754
    ctx->r4 = ADD32(ctx->r4, -0X2754);
    debug_print_reason_routine(rdram, ctx);
        goto after_1;
    // 0x8006E190: addiu       $a0, $a0, -0x2754
    ctx->r4 = ADD32(ctx->r4, -0X2754);
    after_1:
L_8006E194:
    // 0x8006E194: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8006E198: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8006E19C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8006E1A0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006E1A4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006E1A8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8006E1AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006E1B0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8006E1B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006E1B8: lw          $t5, -0x430($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X430);
    // 0x8006E1BC: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8006E1C0: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006E1C4: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8006E1C8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8006E1CC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8006E1D0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8006E1D4: addu        $s0, $t5, $t4
    ctx->r16 = ADD32(ctx->r13, ctx->r12);
    // 0x8006E1D8: addu        $s1, $t5, $t1
    ctx->r17 = ADD32(ctx->r13, ctx->r9);
    // 0x8006E1DC: lw          $s2, 0x4($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X4);
    // 0x8006E1E0: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x8006E1E4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006E1E8: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x8006E1EC: sw          $s2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r18;
    // 0x8006E1F0: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8006E1F4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8006E1F8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8006E1FC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006E200: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8006E204: lw          $t8, -0x430($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X430);
    // 0x8006E208: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x8006E20C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8006E210: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8006E214: lw          $s3, 0x4($t9)
    ctx->r19 = MEM_W(ctx->r25, 0X4);
    // 0x8006E218: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8006E21C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8006E220: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8006E224: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8006E228: jal         0x8006E8F8
    // 0x8006E22C: addiu       $a0, $s3, 0x8
    ctx->r4 = ADD32(ctx->r19, 0X8);
    Cube_InitPosBlock1(rdram, ctx);
        goto after_2;
    // 0x8006E22C: addiu       $a0, $s3, 0x8
    ctx->r4 = ADD32(ctx->r19, 0X8);
    after_2:
    // 0x8006E230: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8006E234: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8006E238: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x8006E23C: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x8006E240: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8006E244: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006E248: lw          $t8, -0x430($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X430);
    // 0x8006E24C: addu        $t4, $t5, $t0
    ctx->r12 = ADD32(ctx->r13, ctx->r8);
    // 0x8006E250: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8006E254: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8006E258: lw          $s3, 0x4($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X4);
    // 0x8006E25C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8006E260: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8006E264: jal         0x8006E8F8
    // 0x8006E268: addiu       $a0, $s3, 0x8
    ctx->r4 = ADD32(ctx->r19, 0X8);
    Cube_InitPosBlock1(rdram, ctx);
        goto after_3;
    // 0x8006E268: addiu       $a0, $s3, 0x8
    ctx->r4 = ADD32(ctx->r19, 0X8);
    after_3:
    // 0x8006E26C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006E270: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006E274: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006E278: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E27C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006E280: jr          $ra
    // 0x8006E284: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006E284: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void BoardPieces_RemoveLine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E34C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006E350: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006E354: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006E358: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006E35C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006E360: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006E364: bltz        $t6, L_8006E378
    if (SIGNED(ctx->r14) < 0) {
        // 0x8006E368: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8006E378;
    }
    // 0x8006E368: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006E36C: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x8006E370: bne         $at, $zero, L_8006E38C
    if (ctx->r1 != 0) {
        // 0x8006E374: nop
    
            goto L_8006E38C;
    }
    // 0x8006E374: nop

L_8006E378:
    // 0x8006E378: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006E37C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006E380: addiu       $a1, $a1, -0x2714
    ctx->r5 = ADD32(ctx->r5, -0X2714);
    // 0x8006E384: jal         0x80083560
    // 0x8006E388: addiu       $a0, $a0, -0x272C
    ctx->r4 = ADD32(ctx->r4, -0X272C);
    debug_print_reason_routine(rdram, ctx);
        goto after_0;
    // 0x8006E388: addiu       $a0, $a0, -0x272C
    ctx->r4 = ADD32(ctx->r4, -0X272C);
    after_0:
L_8006E38C:
    // 0x8006E38C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006E390: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006E394: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006E398: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006E39C: lw          $t7, -0x430($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X430);
    // 0x8006E3A0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8006E3A4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006E3A8: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x8006E3AC: addu        $s2, $t7, $t0
    ctx->r18 = ADD32(ctx->r15, ctx->r8);
    // 0x8006E3B0: blez        $s0, L_8006E3D0
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8006E3B4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8006E3D0;
    }
    // 0x8006E3B4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8006E3B8:
    // 0x8006E3B8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8006E3BC: jal         0x8006D674
    // 0x8006E3C0: nop

    BoardP_ConvertCellToFalling(rdram, ctx);
        goto after_1;
    // 0x8006E3C0: nop

    after_1:
    // 0x8006E3C4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006E3C8: bgtz        $s0, L_8006E3B8
    if (SIGNED(ctx->r16) > 0) {
        // 0x8006E3CC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8006E3B8;
    }
    // 0x8006E3CC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8006E3D0:
    // 0x8006E3D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006E3D4: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8006E3D8: beq         $at, $zero, L_8006E400
    if (ctx->r1 == 0) {
        // 0x8006E3DC: nop
    
            goto L_8006E400;
    }
    // 0x8006E3DC: nop

L_8006E3E0:
    // 0x8006E3E0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8006E3E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E3E8: jal         0x8006E64C
    // 0x8006E3EC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_2;
    // 0x8006E3EC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_2:
    // 0x8006E3F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006E3F4: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8006E3F8: bne         $at, $zero, L_8006E3E0
    if (ctx->r1 != 0) {
        // 0x8006E3FC: nop
    
            goto L_8006E3E0;
    }
    // 0x8006E3FC: nop

L_8006E400:
    // 0x8006E400: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006E404: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8006E408: beq         $at, $zero, L_8006E430
    if (ctx->r1 == 0) {
        // 0x8006E40C: nop
    
            goto L_8006E430;
    }
    // 0x8006E40C: nop

L_8006E410:
    // 0x8006E410: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8006E414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E418: jal         0x8006E64C
    // 0x8006E41C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_3;
    // 0x8006E41C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_3:
    // 0x8006E420: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006E424: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8006E428: bne         $at, $zero, L_8006E410
    if (ctx->r1 != 0) {
        // 0x8006E42C: nop
    
            goto L_8006E410;
    }
    // 0x8006E42C: nop

L_8006E430:
    // 0x8006E430: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8006E434: nop

    // 0x8006E438: blez        $s1, L_8006E480
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8006E43C: nop
    
            goto L_8006E480;
    }
    // 0x8006E43C: nop

L_8006E440:
    // 0x8006E440: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006E444: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8006E448: beq         $at, $zero, L_8006E474
    if (ctx->r1 == 0) {
        // 0x8006E44C: nop
    
            goto L_8006E474;
    }
    // 0x8006E44C: nop

L_8006E450:
    // 0x8006E450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E454: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8006E458: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8006E45C: jal         0x8006E0E8
    // 0x8006E460: addiu       $a3, $s1, -0x1
    ctx->r7 = ADD32(ctx->r17, -0X1);
    BoardPieces_SwapCubes(rdram, ctx);
        goto after_4;
    // 0x8006E460: addiu       $a3, $s1, -0x1
    ctx->r7 = ADD32(ctx->r17, -0X1);
    after_4:
    // 0x8006E464: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006E468: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8006E46C: bne         $at, $zero, L_8006E450
    if (ctx->r1 != 0) {
        // 0x8006E470: nop
    
            goto L_8006E450;
    }
    // 0x8006E470: nop

L_8006E474:
    // 0x8006E474: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8006E478: bgtz        $s1, L_8006E440
    if (SIGNED(ctx->r17) > 0) {
        // 0x8006E47C: nop
    
            goto L_8006E440;
    }
    // 0x8006E47C: nop

L_8006E480:
    // 0x8006E480: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006E484: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006E488: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E48C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006E490: jr          $ra
    // 0x8006E494: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006E494: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void BoardPieces_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E6F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E6F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006E6FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006E700: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006E704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E708: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E70C: jal         0x8006DBB8
    // 0x8006E710: addiu       $a0, $a0, 0x344
    ctx->r4 = ADD32(ctx->r4, 0X344);
    BoardP_UpdateQueue_ProcessAll(rdram, ctx);
        goto after_0;
    // 0x8006E710: addiu       $a0, $a0, 0x344
    ctx->r4 = ADD32(ctx->r4, 0X344);
    after_0:
    // 0x8006E714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E71C: jr          $ra
    // 0x8006E720: nop

    return;
    // 0x8006E720: nop

;}

RECOMP_FUNC void BoardPieces_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E724: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006E728: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8006E72C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8006E730: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006E734: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006E738: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006E73C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006E740: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006E744: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006E748: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x8006E74C: sh          $t6, 0x1614($t7)
    MEM_H(0X1614, ctx->r15) = ctx->r14;
    // 0x8006E750: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8006E754: jal         0x8006DCC0
    // 0x8006E758: addiu       $a0, $a0, 0x344
    ctx->r4 = ADD32(ctx->r4, 0X344);
    BoardP_UpdateQueue_Init(rdram, ctx);
        goto after_0;
    // 0x8006E758: addiu       $a0, $a0, 0x344
    ctx->r4 = ADD32(ctx->r4, 0X344);
    after_0:
    // 0x8006E75C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8006E760: nop

    // 0x8006E764: lhu         $a1, 0x1614($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X1614);
    // 0x8006E768: addiu       $a0, $t8, 0x1608
    ctx->r4 = ADD32(ctx->r24, 0X1608);
    // 0x8006E76C: jal         0x80050650
    // 0x8006E770: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    Ids_Init(rdram, ctx);
        goto after_1;
    // 0x8006E770: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_1:
    // 0x8006E774: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8006E778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006E77C: jal         0x80050800
    // 0x8006E780: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    Ids_IncRef(rdram, ctx);
        goto after_2;
    // 0x8006E780: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    after_2:
    // 0x8006E784: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8006E788: nop

    // 0x8006E78C: lhu         $a0, 0x1614($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X1614);
    // 0x8006E790: nop

    // 0x8006E794: sll         $t0, $a0, 4
    ctx->r8 = S32(ctx->r4 << 4);
    // 0x8006E798: jal         0x8007E03C
    // 0x8006E79C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x8006E79C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_3:
    // 0x8006E7A0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8006E7A4: nop

    // 0x8006E7A8: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8006E7AC: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8006E7B0: nop

    // 0x8006E7B4: lhu         $s1, 0x1614($t2)
    ctx->r17 = MEM_HU(ctx->r10, 0X1614);
    // 0x8006E7B8: lw          $s0, 0x0($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X0);
    // 0x8006E7BC: blez        $s1, L_8006E7D8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8006E7C0: nop
    
            goto L_8006E7D8;
    }
    // 0x8006E7C0: nop

L_8006E7C4:
    // 0x8006E7C4: jal         0x8006DAF0
    // 0x8006E7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    BoardP_InitEmptyCell(rdram, ctx);
        goto after_4;
    // 0x8006E7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8006E7CC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8006E7D0: bgtz        $s1, L_8006E7C4
    if (SIGNED(ctx->r17) > 0) {
        // 0x8006E7D4: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8006E7C4;
    }
    // 0x8006E7D4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_8006E7D8:
    // 0x8006E7D8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8006E7DC: jal         0x8006DA8C
    // 0x8006E7E0: addiu       $a0, $a0, 0x324
    ctx->r4 = ADD32(ctx->r4, 0X324);
    BoardP_InitCellType9(rdram, ctx);
        goto after_5;
    // 0x8006E7E0: addiu       $a0, $a0, 0x324
    ctx->r4 = ADD32(ctx->r4, 0X324);
    after_5:
    // 0x8006E7E4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8006E7E8: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x8006E7EC: sb          $t3, 0x325($t4)
    MEM_B(0X325, ctx->r12) = ctx->r11;
    // 0x8006E7F0: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8006E7F4: nop

    // 0x8006E7F8: lbu         $t6, 0x324($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X324);
    // 0x8006E7FC: nop

    // 0x8006E800: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8006E804: sb          $t7, 0x324($t5)
    MEM_B(0X324, ctx->r13) = ctx->r15;
    // 0x8006E808: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8006E80C: jal         0x8006DA8C
    // 0x8006E810: addiu       $a0, $a0, 0x334
    ctx->r4 = ADD32(ctx->r4, 0X334);
    BoardP_InitCellType9(rdram, ctx);
        goto after_6;
    // 0x8006E810: addiu       $a0, $a0, 0x334
    ctx->r4 = ADD32(ctx->r4, 0X334);
    after_6:
    // 0x8006E814: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8006E818: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8006E81C: sb          $t8, 0x335($t9)
    MEM_B(0X335, ctx->r25) = ctx->r24;
    // 0x8006E820: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8006E824: nop

    // 0x8006E828: lhu         $s4, 0x1614($t0)
    ctx->r20 = MEM_HU(ctx->r8, 0X1614);
    // 0x8006E82C: lw          $s3, 0x0($t0)
    ctx->r19 = MEM_W(ctx->r8, 0X0);
    // 0x8006E830: blez        $s4, L_8006E84C
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8006E834: addiu       $s2, $t0, 0x4
        ctx->r18 = ADD32(ctx->r8, 0X4);
            goto L_8006E84C;
    }
    // 0x8006E834: addiu       $s2, $t0, 0x4
    ctx->r18 = ADD32(ctx->r8, 0X4);
L_8006E838:
    // 0x8006E838: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x8006E83C: sw          $s3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r19;
    // 0x8006E840: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x8006E844: bgtz        $s4, L_8006E838
    if (SIGNED(ctx->r20) > 0) {
        // 0x8006E848: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8006E838;
    }
    // 0x8006E848: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8006E84C:
    // 0x8006E84C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E850: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006E854: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E858: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006E85C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006E860: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006E864: jr          $ra
    // 0x8006E868: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006E868: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void BoardPieces_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E86C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E870: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006E874: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006E878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E87C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8006E880: jal         0x8007E328
    // 0x8006E884: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x8006E884: nop

    after_0:
    // 0x8006E888: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006E88C: nop

    // 0x8006E890: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8006E894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006E898: jal         0x800506D0
    // 0x8006E89C: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    Ids_Deinit(rdram, ctx);
        goto after_1;
    // 0x8006E89C: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    after_1:
    // 0x8006E8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E8A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E8A8: jr          $ra
    // 0x8006E8AC: nop

    return;
    // 0x8006E8AC: nop

;}

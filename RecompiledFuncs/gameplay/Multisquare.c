#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Multisquare_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A050: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8006A054: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006A058: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006A05C: lw          $s0, -0x460($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X460);
    // 0x8006A060: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006A064: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8006A068: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8006A06C: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x8006A070: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8006A074: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8006A078: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8006A07C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8006A080: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006A084: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006A088: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006A08C: lbu         $t6, 0x4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X4);
    // 0x8006A090: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006A094: beq         $t6, $zero, L_8006A0C4
    if (ctx->r14 == 0) {
        // 0x8006A098: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006A0C4;
    }
    // 0x8006A098: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8006A09C: slti        $at, $s1, 0x2C
    ctx->r1 = SIGNED(ctx->r17) < 0X2C ? 1 : 0;
    // 0x8006A0A0: beq         $at, $zero, L_8006A0C4
    if (ctx->r1 == 0) {
        // 0x8006A0A4: nop
    
            goto L_8006A0C4;
    }
    // 0x8006A0A4: nop

L_8006A0A8:
    // 0x8006A0A8: lbu         $t7, 0x12($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X12);
    // 0x8006A0AC: addiu       $s0, $s0, 0x12
    ctx->r16 = ADD32(ctx->r16, 0X12);
    // 0x8006A0B0: beq         $t7, $zero, L_8006A0C4
    if (ctx->r15 == 0) {
        // 0x8006A0B4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8006A0C4;
    }
    // 0x8006A0B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006A0B8: slti        $at, $s1, 0x2C
    ctx->r1 = SIGNED(ctx->r17) < 0X2C ? 1 : 0;
    // 0x8006A0BC: bne         $at, $zero, L_8006A0A8
    if (ctx->r1 != 0) {
        // 0x8006A0C0: nop
    
            goto L_8006A0A8;
    }
    // 0x8006A0C0: nop

L_8006A0C4:
    // 0x8006A0C4: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x8006A0C8: bne         $s1, $at, L_8006A0E4
    if (ctx->r17 != ctx->r1) {
        // 0x8006A0CC: nop
    
            goto L_8006A0E4;
    }
    // 0x8006A0CC: nop

    // 0x8006A0D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006A0D4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006A0D8: addiu       $a1, $a1, -0x2980
    ctx->r5 = ADD32(ctx->r5, -0X2980);
    // 0x8006A0DC: jal         0x80083560
    // 0x8006A0E0: addiu       $a0, $a0, -0x2990
    ctx->r4 = ADD32(ctx->r4, -0X2990);
    debug_print_reason_routine(rdram, ctx);
        goto after_0;
    // 0x8006A0E0: addiu       $a0, $a0, -0x2990
    ctx->r4 = ADD32(ctx->r4, -0X2990);
    after_0:
L_8006A0E4:
    // 0x8006A0E4: lbu         $t8, 0x93($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X93);
    // 0x8006A0E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006A0EC: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x8006A0F0: lbu         $t9, 0x93($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X93);
    // 0x8006A0F4: nop

    // 0x8006A0F8: beq         $t9, $at, L_8006A134
    if (ctx->r25 == ctx->r1) {
        // 0x8006A0FC: sw          $t9, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r25;
            goto L_8006A134;
    }
    // 0x8006A0FC: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8006A100: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006A104: bne         $t9, $at, L_8006A158
    if (ctx->r25 != ctx->r1) {
        // 0x8006A108: nop
    
            goto L_8006A158;
    }
    // 0x8006A108: nop

    // 0x8006A10C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8006A110: addiu       $t1, $t1, -0x10
    ctx->r9 = ADD32(ctx->r9, -0X10);
    // 0x8006A114: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8006A118: addiu       $t0, $sp, 0x78
    ctx->r8 = ADD32(ctx->r29, 0X78);
    // 0x8006A11C: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8006A120: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x8006A124: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8006A128: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x8006A12C: b           L_8006A158
    // 0x8006A130: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
        goto L_8006A158;
    // 0x8006A130: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
L_8006A134:
    // 0x8006A134: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8006A138: addiu       $t5, $t5, -0x1C
    ctx->r13 = ADD32(ctx->r13, -0X1C);
    // 0x8006A13C: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x8006A140: addiu       $t4, $sp, 0x78
    ctx->r12 = ADD32(ctx->r29, 0X78);
    // 0x8006A144: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x8006A148: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x8006A14C: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8006A150: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x8006A154: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
L_8006A158:
    // 0x8006A158: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8006A15C: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8006A160: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8006A164: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8006A168: addiu       $t3, $t1, -0x80
    ctx->r11 = ADD32(ctx->r9, -0X80);
    // 0x8006A16C: addiu       $t2, $t9, -0x80
    ctx->r10 = ADD32(ctx->r25, -0X80);
    // 0x8006A170: sh          $t2, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r10;
    // 0x8006A174: sh          $t3, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r11;
    // 0x8006A178: sh          $zero, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = 0;
    // 0x8006A17C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x8006A180: jal         0x80071100
    // 0x8006A184: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    Minos_TransformVecRot(rdram, ctx);
        goto after_1;
    // 0x8006A184: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_1:
    // 0x8006A188: lwl         $t6, 0x70($sp)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r29, 0X70);
    // 0x8006A18C: lwr         $t6, 0x73($sp)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r29, 0X73);
    // 0x8006A190: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006A194: lw          $t4, -0x3F0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3F0);
    // 0x8006A198: swl         $t6, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r14);
    // 0x8006A19C: swr         $t6, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r14);
    // 0x8006A1A0: lhu         $a2, 0x2($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X2);
    // 0x8006A1A4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8006A1A8: sra         $t5, $a2, 8
    ctx->r13 = S32(SIGNED(ctx->r6) >> 8);
    // 0x8006A1AC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8006A1B0: jal         0x8006B050
    // 0x8006A1B4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    MultisquareGlow_Init(rdram, ctx);
        goto after_2;
    // 0x8006A1B4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x8006A1B8: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8006A1BC: lbu         $s4, 0x2($s0)
    ctx->r20 = MEM_BU(ctx->r16, 0X2);
    // 0x8006A1C0: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
    // 0x8006A1C4: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8006A1C8: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006A1CC: beq         $at, $zero, L_8006A284
    if (ctx->r1 == 0) {
        // 0x8006A1D0: nop
    
            goto L_8006A284;
    }
    // 0x8006A1D0: nop

L_8006A1D4:
    // 0x8006A1D4: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8006A1D8: nop

    // 0x8006A1DC: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x8006A1E0: addiu       $t2, $t9, 0x4
    ctx->r10 = ADD32(ctx->r25, 0X4);
    // 0x8006A1E4: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8006A1E8: beq         $at, $zero, L_8006A26C
    if (ctx->r1 == 0) {
        // 0x8006A1EC: nop
    
            goto L_8006A26C;
    }
    // 0x8006A1EC: nop

L_8006A1F0:
    // 0x8006A1F0: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x8006A1F4: addu        $t1, $t1, $s3
    ctx->r9 = ADD32(ctx->r9, ctx->r19);
    // 0x8006A1F8: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006A1FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006A200: lw          $t0, -0x430($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X430);
    // 0x8006A204: addu        $t3, $s2, $t1
    ctx->r11 = ADD32(ctx->r18, ctx->r9);
    // 0x8006A208: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8006A20C: addu        $t4, $t0, $t6
    ctx->r12 = ADD32(ctx->r8, ctx->r14);
    // 0x8006A210: lw          $s5, 0x4($t4)
    ctx->r21 = MEM_W(ctx->r12, 0X4);
    // 0x8006A214: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8006A218: lw          $t5, 0xC($s5)
    ctx->r13 = MEM_W(ctx->r21, 0XC);
    // 0x8006A21C: sb          $s4, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r20;
    // 0x8006A220: lh          $t7, 0x48($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X48);
    // 0x8006A224: lw          $t1, 0xC($s5)
    ctx->r9 = MEM_W(ctx->r21, 0XC);
    // 0x8006A228: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x8006A22C: bgez        $t9, L_8006A23C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8006A230: sra         $t2, $t9, 4
        ctx->r10 = S32(SIGNED(ctx->r25) >> 4);
            goto L_8006A23C;
    }
    // 0x8006A230: sra         $t2, $t9, 4
    ctx->r10 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8006A234: addiu       $at, $t9, 0xF
    ctx->r1 = ADD32(ctx->r25, 0XF);
    // 0x8006A238: sra         $t2, $at, 4
    ctx->r10 = S32(SIGNED(ctx->r1) >> 4);
L_8006A23C:
    // 0x8006A23C: sh          $t2, 0x4A($t1)
    MEM_H(0X4A, ctx->r9) = ctx->r10;
    // 0x8006A240: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x8006A244: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8006A248: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8006A24C: jal         0x80070860
    // 0x8006A250: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_Mino_StartSlide(rdram, ctx);
        goto after_3;
    // 0x8006A250: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x8006A254: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8006A258: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006A25C: addiu       $t0, $t3, 0x4
    ctx->r8 = ADD32(ctx->r11, 0X4);
    // 0x8006A260: slt         $at, $s2, $t0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8006A264: bne         $at, $zero, L_8006A1F0
    if (ctx->r1 != 0) {
        // 0x8006A268: nop
    
            goto L_8006A1F0;
    }
    // 0x8006A268: nop

L_8006A26C:
    // 0x8006A26C: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8006A270: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8006A274: addiu       $t4, $t6, 0x4
    ctx->r12 = ADD32(ctx->r14, 0X4);
    // 0x8006A278: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8006A27C: bne         $at, $zero, L_8006A1D4
    if (ctx->r1 != 0) {
        // 0x8006A280: nop
    
            goto L_8006A1D4;
    }
    // 0x8006A280: nop

L_8006A284:
    // 0x8006A284: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8006A288: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8006A28C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8006A290: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8006A294: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006A298: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006A29C: lw          $t1, -0x430($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X430);
    // 0x8006A2A0: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8006A2A4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8006A2A8: addu        $s7, $t1, $t2
    ctx->r23 = ADD32(ctx->r9, ctx->r10);
    // 0x8006A2AC: lw          $s6, 0x4($s7)
    ctx->r22 = MEM_W(ctx->r23, 0X4);
    // 0x8006A2B0: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8006A2B4: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8006A2B8: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
L_8006A2BC:
    // 0x8006A2BC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8006A2C0: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_8006A2C4:
    // 0x8006A2C4: lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X0);
    // 0x8006A2C8: jal         0x8006D450
    // 0x8006A2CC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    BoardP_MergeGroups(rdram, ctx);
        goto after_4;
    // 0x8006A2CC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_4:
    // 0x8006A2D0: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8006A2D4: nop

    // 0x8006A2D8: lb          $t4, 0x9($t6)
    ctx->r12 = MEM_B(ctx->r14, 0X9);
    // 0x8006A2DC: nop

    // 0x8006A2E0: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x8006A2E4: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8006A2E8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8006A2EC: lb          $t5, 0xA($t8)
    ctx->r13 = MEM_B(ctx->r24, 0XA);
    // 0x8006A2F0: nop

    // 0x8006A2F4: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x8006A2F8: jal         0x8006E64C
    // 0x8006A2FC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_5;
    // 0x8006A2FC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_5:
    // 0x8006A300: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A304: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8006A308: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x8006A30C: bgtz        $t9, L_8006A2C4
    if (SIGNED(ctx->r25) > 0) {
        // 0x8006A310: sw          $t9, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r25;
            goto L_8006A2C4;
    }
    // 0x8006A310: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x8006A314: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8006A318: addiu       $s7, $s7, 0x18
    ctx->r23 = ADD32(ctx->r23, 0X18);
    // 0x8006A31C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8006A320: bgtz        $t2, L_8006A2BC
    if (SIGNED(ctx->r10) > 0) {
        // 0x8006A324: sw          $t2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r10;
            goto L_8006A2BC;
    }
    // 0x8006A324: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x8006A328: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8006A32C: sb          $t3, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r11;
    // 0x8006A330: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006A334: lw          $t0, -0x460($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X460);
    // 0x8006A338: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006A33C: lbu         $t6, 0x3($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X3);
    // 0x8006A340: nop

    // 0x8006A344: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8006A348: sb          $t8, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r24;
    // 0x8006A34C: lbu         $t4, 0x93($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X93);
    // 0x8006A350: nop

    // 0x8006A354: bne         $t4, $at, L_8006A37C
    if (ctx->r12 != ctx->r1) {
        // 0x8006A358: nop
    
            goto L_8006A37C;
    }
    // 0x8006A358: nop

    // 0x8006A35C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A360: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006A364: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x8006A368: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8006A36C: jal         0x8008A5C8
    // 0x8006A370: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    Audio2_Play_SFX(rdram, ctx);
        goto after_6;
    // 0x8006A370: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_6:
    // 0x8006A374: b           L_8006A3BC
    // 0x8006A378: nop

        goto L_8006A3BC;
    // 0x8006A378: nop

L_8006A37C:
    // 0x8006A37C: lbu         $t5, 0x93($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X93);
    // 0x8006A380: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006A384: bne         $t5, $at, L_8006A3BC
    if (ctx->r13 != ctx->r1) {
        // 0x8006A388: nop
    
            goto L_8006A3BC;
    }
    // 0x8006A388: nop

    // 0x8006A38C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A390: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006A394: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x8006A398: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8006A39C: jal         0x8008A5C8
    // 0x8006A3A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    Audio2_Play_SFX(rdram, ctx);
        goto after_7;
    // 0x8006A3A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_7:
    // 0x8006A3A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A3A8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006A3AC: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x8006A3B0: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8006A3B4: jal         0x8008A5C8
    // 0x8006A3B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio2_Play_SFX(rdram, ctx);
        goto after_8;
    // 0x8006A3B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_8:
L_8006A3BC:
    // 0x8006A3BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006A3C0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8006A3C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006A3C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006A3CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A3D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006A3D4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8006A3D8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8006A3DC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A3E0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8006A3E4: jr          $ra
    // 0x8006A3E8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8006A3E8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}

RECOMP_FUNC void Multisquare_Free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A3EC: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8006A3F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A3F4: lw          $t6, -0x460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X460);
    // 0x8006A3F8: nop

    // 0x8006A3FC: lbu         $t7, 0x3($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3);
    // 0x8006A400: nop

    // 0x8006A404: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8006A408: jr          $ra
    // 0x8006A40C: sb          $t8, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r24;
    return;
    // 0x8006A40C: sb          $t8, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r24;
;}

RECOMP_FUNC void Multisquare_TickLifetime(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A414: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006A418: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006A41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A420: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006A424: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8006A428: nop

    // 0x8006A42C: beq         $t7, $zero, L_8006A46C
    if (ctx->r15 == 0) {
        // 0x8006A430: nop
    
            goto L_8006A46C;
    }
    // 0x8006A430: nop

    // 0x8006A434: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006A438: nop

    // 0x8006A43C: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x8006A440: nop

    // 0x8006A444: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8006A448: sb          $t0, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r8;
    // 0x8006A44C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006A450: nop

    // 0x8006A454: lbu         $t2, 0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1);
    // 0x8006A458: nop

    // 0x8006A45C: bne         $t2, $zero, L_8006A46C
    if (ctx->r10 != 0) {
        // 0x8006A460: nop
    
            goto L_8006A46C;
    }
    // 0x8006A460: nop

    // 0x8006A464: jal         0x8006A3EC
    // 0x8006A468: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    Multisquare_Free(rdram, ctx);
        goto after_0;
    // 0x8006A468: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_0:
L_8006A46C:
    // 0x8006A46C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A470: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A474: jr          $ra
    // 0x8006A478: nop

    return;
    // 0x8006A478: nop

;}

RECOMP_FUNC void Multisquare_pGetColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A47C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006A480: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006A484: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006A488: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A48C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A490: lbu         $s0, 0x0($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0X0);
    // 0x8006A494: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006A498: beq         $s0, $at, L_8006A4B0
    if (ctx->r16 == ctx->r1) {
        // 0x8006A49C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006A4B0;
    }
    // 0x8006A49C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006A4A0: beq         $s0, $at, L_8006A4BC
    if (ctx->r16 == ctx->r1) {
        // 0x8006A4A4: nop
    
            goto L_8006A4BC;
    }
    // 0x8006A4A4: nop

    // 0x8006A4A8: b           L_8006A4C8
    // 0x8006A4AC: nop

        goto L_8006A4C8;
    // 0x8006A4AC: nop

L_8006A4B0:
    // 0x8006A4B0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006A4B4: b           L_8006A4DC
    // 0x8006A4B8: addiu       $v0, $v0, -0x1C
    ctx->r2 = ADD32(ctx->r2, -0X1C);
        goto L_8006A4DC;
    // 0x8006A4B8: addiu       $v0, $v0, -0x1C
    ctx->r2 = ADD32(ctx->r2, -0X1C);
L_8006A4BC:
    // 0x8006A4BC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006A4C0: b           L_8006A4DC
    // 0x8006A4C4: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
        goto L_8006A4DC;
    // 0x8006A4C4: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
L_8006A4C8:
    // 0x8006A4C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006A4CC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006A4D0: addiu       $a1, $a1, -0x2954
    ctx->r5 = ADD32(ctx->r5, -0X2954);
    // 0x8006A4D4: jal         0x80083560
    // 0x8006A4D8: addiu       $a0, $a0, -0x296C
    ctx->r4 = ADD32(ctx->r4, -0X296C);
    debug_print_reason_routine(rdram, ctx);
        goto after_0;
    // 0x8006A4D8: addiu       $a0, $a0, -0x296C
    ctx->r4 = ADD32(ctx->r4, -0X296C);
    after_0:
L_8006A4DC:
    // 0x8006A4DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A4E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A4E4: jr          $ra
    // 0x8006A4E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006A4E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Multisquare_TestCell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A6BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A6C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006A6C4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006A6C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A6CC: lbu         $a2, 0x1($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X1);
    // 0x8006A6D0: lb          $a1, 0xA($t6)
    ctx->r5 = MEM_B(ctx->r14, 0XA);
    // 0x8006A6D4: lb          $a0, 0x9($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X9);
    // 0x8006A6D8: jal         0x8006A4EC
    // 0x8006A6DC: nop

    Multisquares_Test4x4byType(rdram, ctx);
        goto after_0;
    // 0x8006A6DC: nop

    after_0:
    // 0x8006A6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A6E8: jr          $ra
    // 0x8006A6EC: nop

    return;
    // 0x8006A6EC: nop

;}

RECOMP_FUNC void Multisquare_BeginState2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A6F0: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x8006A6F4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8006A6F8: sb          $t6, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r14;
    // 0x8006A6FC: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x8006A700: jr          $ra
    // 0x8006A704: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    return;
    // 0x8006A704: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
;}

RECOMP_FUNC void Multisquare_UpdateState2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A708: lbu         $t6, 0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2);
    // 0x8006A70C: nop

    // 0x8006A710: bne         $t6, $zero, L_8006A728
    if (ctx->r14 != 0) {
        // 0x8006A714: nop
    
            goto L_8006A728;
    }
    // 0x8006A714: nop

    // 0x8006A718: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8006A71C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8006A720: jr          $ra
    // 0x8006A724: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    return;
    // 0x8006A724: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
L_8006A728:
    // 0x8006A728: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x8006A72C: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x8006A730: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8006A734: sb          $t9, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r25;
    // 0x8006A738: jr          $ra
    // 0x8006A73C: nop

    return;
    // 0x8006A73C: nop

;}

RECOMP_FUNC void Multisquare_ScanNearPiece(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A740: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006A744: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8006A748: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A74C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A750: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x8006A754: jal         0x80067C1C
    // 0x8006A758: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    CurrentPiece_GetMinoBounds(rdram, ctx);
        goto after_0;
    // 0x8006A758: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8006A75C: lh          $t6, 0x34($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X34);
    // 0x8006A760: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x8006A764: addiu       $t7, $t6, -0x3
    ctx->r15 = ADD32(ctx->r14, -0X3);
    // 0x8006A768: lh          $t0, 0x30($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X30);
    // 0x8006A76C: lh          $t1, 0x32($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X32);
    // 0x8006A770: sll         $t2, $t7, 16
    ctx->r10 = S32(ctx->r15 << 16);
    // 0x8006A774: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8006A778: addiu       $t9, $t8, -0x3
    ctx->r25 = ADD32(ctx->r24, -0X3);
    // 0x8006A77C: sh          $t7, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r15;
    // 0x8006A780: sh          $t9, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r25;
    // 0x8006A784: sh          $t0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r8;
    // 0x8006A788: bgez        $t3, L_8006A794
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8006A78C: sh          $t1, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r9;
            goto L_8006A794;
    }
    // 0x8006A78C: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    // 0x8006A790: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
L_8006A794:
    // 0x8006A794: lh          $t4, 0x2C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2C);
    // 0x8006A798: nop

    // 0x8006A79C: slti        $at, $t4, 0x7
    ctx->r1 = SIGNED(ctx->r12) < 0X7 ? 1 : 0;
    // 0x8006A7A0: bne         $at, $zero, L_8006A7B0
    if (ctx->r1 != 0) {
        // 0x8006A7A4: nop
    
            goto L_8006A7B0;
    }
    // 0x8006A7A4: nop

    // 0x8006A7A8: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8006A7AC: sh          $t5, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r13;
L_8006A7B0:
    // 0x8006A7B0: lh          $t6, 0x2A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2A);
    // 0x8006A7B4: nop

    // 0x8006A7B8: bgez        $t6, L_8006A7C4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006A7BC: nop
    
            goto L_8006A7C4;
    }
    // 0x8006A7BC: nop

    // 0x8006A7C0: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
L_8006A7C4:
    // 0x8006A7C4: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x8006A7C8: nop

    // 0x8006A7CC: slti        $at, $t8, 0x11
    ctx->r1 = SIGNED(ctx->r24) < 0X11 ? 1 : 0;
    // 0x8006A7D0: bne         $at, $zero, L_8006A7E0
    if (ctx->r1 != 0) {
        // 0x8006A7D4: nop
    
            goto L_8006A7E0;
    }
    // 0x8006A7D4: nop

    // 0x8006A7D8: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8006A7DC: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
L_8006A7E0:
    // 0x8006A7E0: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x8006A7E4: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x8006A7E8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8006A7EC: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8006A7F0: bne         $at, $zero, L_8006A880
    if (ctx->r1 != 0) {
        // 0x8006A7F4: nop
    
            goto L_8006A880;
    }
    // 0x8006A7F4: nop

L_8006A7F8:
    // 0x8006A7F8: lh          $t7, 0x28($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X28);
    // 0x8006A7FC: lh          $t2, 0x2C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2C);
    // 0x8006A800: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8006A804: slt         $at, $t2, $t7
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8006A808: bne         $at, $zero, L_8006A858
    if (ctx->r1 != 0) {
        // 0x8006A80C: nop
    
            goto L_8006A858;
    }
    // 0x8006A80C: nop

L_8006A810:
    // 0x8006A810: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006A814: lw          $t3, -0x490($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X490);
    // 0x8006A818: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8006A81C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8006A820: lbu         $a2, 0x13($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X13);
    // 0x8006A824: jal         0x8006A4EC
    // 0x8006A828: nop

    Multisquares_Test4x4byType(rdram, ctx);
        goto after_1;
    // 0x8006A828: nop

    after_1:
    // 0x8006A82C: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x8006A830: lbu         $t4, 0x1F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1F);
    // 0x8006A834: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006A838: beq         $t4, $at, L_8006A858
    if (ctx->r12 == ctx->r1) {
        // 0x8006A83C: nop
    
            goto L_8006A858;
    }
    // 0x8006A83C: nop

    // 0x8006A840: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8006A844: lh          $t8, 0x2C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2C);
    // 0x8006A848: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8006A84C: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006A850: beq         $at, $zero, L_8006A810
    if (ctx->r1 == 0) {
        // 0x8006A854: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_8006A810;
    }
    // 0x8006A854: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8006A858:
    // 0x8006A858: lbu         $t9, 0x1F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1F);
    // 0x8006A85C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006A860: beq         $t9, $at, L_8006A880
    if (ctx->r25 == ctx->r1) {
        // 0x8006A864: nop
    
            goto L_8006A880;
    }
    // 0x8006A864: nop

    // 0x8006A868: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006A86C: lh          $t7, 0x2E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2E);
    // 0x8006A870: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8006A874: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8006A878: beq         $at, $zero, L_8006A7F8
    if (ctx->r1 == 0) {
        // 0x8006A87C: sw          $t1, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r9;
            goto L_8006A7F8;
    }
    // 0x8006A87C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
L_8006A880:
    // 0x8006A880: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x8006A884: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006A888: bne         $t2, $at, L_8006A8B4
    if (ctx->r10 != ctx->r1) {
        // 0x8006A88C: nop
    
            goto L_8006A8B4;
    }
    // 0x8006A88C: nop

    // 0x8006A890: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8006A894: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8006A898: jal         0x8006A050
    // 0x8006A89C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    Multisquare_Spawn(rdram, ctx);
        goto after_2;
    // 0x8006A89C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x8006A8A0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8006A8A4: jal         0x8006A6F0
    // 0x8006A8A8: nop

    Multisquare_BeginState2(rdram, ctx);
        goto after_3;
    // 0x8006A8A8: nop

    after_3:
    // 0x8006A8AC: b           L_8006A994
    // 0x8006A8B0: nop

        goto L_8006A994;
    // 0x8006A8B0: nop

L_8006A8B4:
    // 0x8006A8B4: lh          $t3, 0x2A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2A);
    // 0x8006A8B8: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x8006A8BC: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8006A8C0: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8006A8C4: bne         $at, $zero, L_8006A954
    if (ctx->r1 != 0) {
        // 0x8006A8C8: nop
    
            goto L_8006A954;
    }
    // 0x8006A8C8: nop

L_8006A8CC:
    // 0x8006A8CC: lh          $t5, 0x28($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X28);
    // 0x8006A8D0: lh          $t6, 0x2C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2C);
    // 0x8006A8D4: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8006A8D8: slt         $at, $t6, $t5
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8006A8DC: bne         $at, $zero, L_8006A92C
    if (ctx->r1 != 0) {
        // 0x8006A8E0: nop
    
            goto L_8006A92C;
    }
    // 0x8006A8E0: nop

L_8006A8E4:
    // 0x8006A8E4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006A8E8: lw          $t8, -0x490($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X490);
    // 0x8006A8EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8006A8F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8006A8F4: lbu         $a2, 0x13($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X13);
    // 0x8006A8F8: jal         0x8006A4EC
    // 0x8006A8FC: nop

    Multisquares_Test4x4byType(rdram, ctx);
        goto after_4;
    // 0x8006A8FC: nop

    after_4:
    // 0x8006A900: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x8006A904: lbu         $t9, 0x1F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1F);
    // 0x8006A908: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006A90C: beq         $t9, $at, L_8006A92C
    if (ctx->r25 == ctx->r1) {
        // 0x8006A910: nop
    
            goto L_8006A92C;
    }
    // 0x8006A910: nop

    // 0x8006A914: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8006A918: lh          $t7, 0x2C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2C);
    // 0x8006A91C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8006A920: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8006A924: beq         $at, $zero, L_8006A8E4
    if (ctx->r1 == 0) {
        // 0x8006A928: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_8006A8E4;
    }
    // 0x8006A928: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_8006A92C:
    // 0x8006A92C: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x8006A930: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006A934: beq         $t2, $at, L_8006A954
    if (ctx->r10 == ctx->r1) {
        // 0x8006A938: nop
    
            goto L_8006A954;
    }
    // 0x8006A938: nop

    // 0x8006A93C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8006A940: lh          $t5, 0x2E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2E);
    // 0x8006A944: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8006A948: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8006A94C: beq         $at, $zero, L_8006A8CC
    if (ctx->r1 == 0) {
        // 0x8006A950: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_8006A8CC;
    }
    // 0x8006A950: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
L_8006A954:
    // 0x8006A954: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8006A958: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006A95C: bne         $t6, $at, L_8006A988
    if (ctx->r14 != ctx->r1) {
        // 0x8006A960: nop
    
            goto L_8006A988;
    }
    // 0x8006A960: nop

    // 0x8006A964: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8006A968: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8006A96C: jal         0x8006A050
    // 0x8006A970: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Multisquare_Spawn(rdram, ctx);
        goto after_5;
    // 0x8006A970: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8006A974: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8006A978: jal         0x8006A6F0
    // 0x8006A97C: nop

    Multisquare_BeginState2(rdram, ctx);
        goto after_6;
    // 0x8006A97C: nop

    after_6:
    // 0x8006A980: b           L_8006A994
    // 0x8006A984: nop

        goto L_8006A994;
    // 0x8006A984: nop

L_8006A988:
    // 0x8006A988: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8006A98C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006A990: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
L_8006A994:
    // 0x8006A994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A998: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8006A99C: jr          $ra
    // 0x8006A9A0: nop

    return;
    // 0x8006A9A0: nop

;}

RECOMP_FUNC void Multisquare_BeginState4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A9A4: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x8006A9A8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8006A9AC: sb          $t6, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r14;
    // 0x8006A9B0: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x8006A9B4: jr          $ra
    // 0x8006A9B8: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    return;
    // 0x8006A9B8: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
;}

RECOMP_FUNC void Multisquare_UpdateState4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A9BC: lbu         $t6, 0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2);
    // 0x8006A9C0: nop

    // 0x8006A9C4: bne         $t6, $zero, L_8006A9DC
    if (ctx->r14 != 0) {
        // 0x8006A9C8: nop
    
            goto L_8006A9DC;
    }
    // 0x8006A9C8: nop

    // 0x8006A9CC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8006A9D0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8006A9D4: jr          $ra
    // 0x8006A9D8: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    return;
    // 0x8006A9D8: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
L_8006A9DC:
    // 0x8006A9DC: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x8006A9E0: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x8006A9E4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8006A9E8: sb          $t9, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r25;
    // 0x8006A9EC: jr          $ra
    // 0x8006A9F0: nop

    return;
    // 0x8006A9F0: nop

;}

RECOMP_FUNC void Multisquare_UpdateExpand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A9F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006A9F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006A9FC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006AA00: slti        $at, $s2, 0x11
    ctx->r1 = SIGNED(ctx->r18) < 0X11 ? 1 : 0;
    // 0x8006AA04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006AA08: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006AA0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006AA10: beq         $at, $zero, L_8006AAB4
    if (ctx->r1 == 0) {
        // 0x8006AA14: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8006AAB4;
    }
    // 0x8006AA14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_8006AA18:
    // 0x8006AA18: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006AA1C: slti        $at, $s1, 0x7
    ctx->r1 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x8006AA20: beq         $at, $zero, L_8006AAA4
    if (ctx->r1 == 0) {
        // 0x8006AA24: nop
    
            goto L_8006AAA4;
    }
    // 0x8006AA24: nop

L_8006AA28:
    // 0x8006AA28: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8006AA2C: addu        $t7, $t7, $s2
    ctx->r15 = ADD32(ctx->r15, ctx->r18);
    // 0x8006AA30: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006AA34: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006AA38: lw          $t6, -0x430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X430);
    // 0x8006AA3C: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8006AA40: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006AA44: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x8006AA48: lw          $s0, 0x4($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X4);
    // 0x8006AA4C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006AA50: lbu         $t1, 0x1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1);
    // 0x8006AA54: nop

    // 0x8006AA58: beq         $t1, $at, L_8006AA94
    if (ctx->r9 == ctx->r1) {
        // 0x8006AA5C: nop
    
            goto L_8006AA94;
    }
    // 0x8006AA5C: nop

    // 0x8006AA60: lbu         $t2, 0x3($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X3);
    // 0x8006AA64: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006AA68: bne         $t2, $at, L_8006AA94
    if (ctx->r10 != ctx->r1) {
        // 0x8006AA6C: nop
    
            goto L_8006AA94;
    }
    // 0x8006AA6C: nop

    // 0x8006AA70: jal         0x8006A6BC
    // 0x8006AA74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Multisquare_TestCell(rdram, ctx);
        goto after_0;
    // 0x8006AA74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006AA78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006AA7C: bne         $v0, $at, L_8006AA94
    if (ctx->r2 != ctx->r1) {
        // 0x8006AA80: nop
    
            goto L_8006AA94;
    }
    // 0x8006AA80: nop

    // 0x8006AA84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006AA88: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8006AA8C: jal         0x8006A050
    // 0x8006AA90: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    Multisquare_Spawn(rdram, ctx);
        goto after_1;
    // 0x8006AA90: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
L_8006AA94:
    // 0x8006AA94: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006AA98: slti        $at, $s1, 0x7
    ctx->r1 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x8006AA9C: bne         $at, $zero, L_8006AA28
    if (ctx->r1 != 0) {
        // 0x8006AAA0: nop
    
            goto L_8006AA28;
    }
    // 0x8006AAA0: nop

L_8006AAA4:
    // 0x8006AAA4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006AAA8: slti        $at, $s2, 0x11
    ctx->r1 = SIGNED(ctx->r18) < 0X11 ? 1 : 0;
    // 0x8006AAAC: bne         $at, $zero, L_8006AA18
    if (ctx->r1 != 0) {
        // 0x8006AAB0: nop
    
            goto L_8006AA18;
    }
    // 0x8006AAB0: nop

L_8006AAB4:
    // 0x8006AAB4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006AAB8: slti        $at, $s2, 0x11
    ctx->r1 = SIGNED(ctx->r18) < 0X11 ? 1 : 0;
    // 0x8006AABC: beq         $at, $zero, L_8006AB60
    if (ctx->r1 == 0) {
        // 0x8006AAC0: nop
    
            goto L_8006AB60;
    }
    // 0x8006AAC0: nop

L_8006AAC4:
    // 0x8006AAC4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006AAC8: slti        $at, $s1, 0x7
    ctx->r1 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x8006AACC: beq         $at, $zero, L_8006AB50
    if (ctx->r1 == 0) {
        // 0x8006AAD0: nop
    
            goto L_8006AB50;
    }
    // 0x8006AAD0: nop

L_8006AAD4:
    // 0x8006AAD4: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x8006AAD8: addu        $t4, $t4, $s2
    ctx->r12 = ADD32(ctx->r12, ctx->r18);
    // 0x8006AADC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8006AAE0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006AAE4: lw          $t3, -0x430($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X430);
    // 0x8006AAE8: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x8006AAEC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8006AAF0: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x8006AAF4: lw          $s0, 0x4($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X4);
    // 0x8006AAF8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006AAFC: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x8006AB00: nop

    // 0x8006AB04: beq         $t6, $at, L_8006AB40
    if (ctx->r14 == ctx->r1) {
        // 0x8006AB08: nop
    
            goto L_8006AB40;
    }
    // 0x8006AB08: nop

    // 0x8006AB0C: lbu         $t9, 0x3($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X3);
    // 0x8006AB10: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006AB14: bne         $t9, $at, L_8006AB40
    if (ctx->r25 != ctx->r1) {
        // 0x8006AB18: nop
    
            goto L_8006AB40;
    }
    // 0x8006AB18: nop

    // 0x8006AB1C: jal         0x8006A6BC
    // 0x8006AB20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Multisquare_TestCell(rdram, ctx);
        goto after_2;
    // 0x8006AB20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8006AB24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006AB28: bne         $v0, $at, L_8006AB40
    if (ctx->r2 != ctx->r1) {
        // 0x8006AB2C: nop
    
            goto L_8006AB40;
    }
    // 0x8006AB2C: nop

    // 0x8006AB30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006AB34: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8006AB38: jal         0x8006A050
    // 0x8006AB3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Multisquare_Spawn(rdram, ctx);
        goto after_3;
    // 0x8006AB3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_8006AB40:
    // 0x8006AB40: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006AB44: slti        $at, $s1, 0x7
    ctx->r1 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x8006AB48: bne         $at, $zero, L_8006AAD4
    if (ctx->r1 != 0) {
        // 0x8006AB4C: nop
    
            goto L_8006AAD4;
    }
    // 0x8006AB4C: nop

L_8006AB50:
    // 0x8006AB50: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006AB54: slti        $at, $s2, 0x11
    ctx->r1 = SIGNED(ctx->r18) < 0X11 ? 1 : 0;
    // 0x8006AB58: bne         $at, $zero, L_8006AAC4
    if (ctx->r1 != 0) {
        // 0x8006AB5C: nop
    
            goto L_8006AAC4;
    }
    // 0x8006AB5C: nop

L_8006AB60:
    // 0x8006AB60: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8006AB64: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8006AB68: sb          $t0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r8;
    // 0x8006AB6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006AB70: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006AB74: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AB78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006AB7C: jr          $ra
    // 0x8006AB80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006AB80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Multisquare_IsValidIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AB84: sltiu       $at, $a0, 0x2C
    ctx->r1 = ctx->r4 < 0X2C ? 1 : 0;
    // 0x8006AB88: beq         $at, $zero, L_8006AB98
    if (ctx->r1 == 0) {
        // 0x8006AB8C: nop
    
            goto L_8006AB98;
    }
    // 0x8006AB8C: nop

    // 0x8006AB90: jr          $ra
    // 0x8006AB94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8006AB94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006AB98:
    // 0x8006AB98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006AB9C: jr          $ra
    // 0x8006ABA0: nop

    return;
    // 0x8006ABA0: nop

;}

RECOMP_FUNC void Multisquare_CountMatched(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ABA4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006ABA8: lw          $a0, -0x460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X460);
    // 0x8006ABAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006ABB0: sltiu       $at, $a2, 0x2C
    ctx->r1 = ctx->r6 < 0X2C ? 1 : 0;
    // 0x8006ABB4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8006ABB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006ABBC: beq         $at, $zero, L_8006ABE8
    if (ctx->r1 == 0) {
        // 0x8006ABC0: addiu       $a1, $a0, 0x4
        ctx->r5 = ADD32(ctx->r4, 0X4);
            goto L_8006ABE8;
    }
    // 0x8006ABC0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
L_8006ABC4:
    // 0x8006ABC4: lbu         $t6, 0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3);
    // 0x8006ABC8: nop

    // 0x8006ABCC: beq         $t6, $zero, L_8006ABD8
    if (ctx->r14 == 0) {
        // 0x8006ABD0: nop
    
            goto L_8006ABD8;
    }
    // 0x8006ABD0: nop

    // 0x8006ABD4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8006ABD8:
    // 0x8006ABD8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006ABDC: sltiu       $at, $a2, 0x2C
    ctx->r1 = ctx->r6 < 0X2C ? 1 : 0;
    // 0x8006ABE0: bne         $at, $zero, L_8006ABC4
    if (ctx->r1 != 0) {
        // 0x8006ABE4: addiu       $a1, $a1, 0x12
        ctx->r5 = ADD32(ctx->r5, 0X12);
            goto L_8006ABC4;
    }
    // 0x8006ABE4: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
L_8006ABE8:
    // 0x8006ABE8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8006ABEC: jr          $ra
    // 0x8006ABF0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8006ABF0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void Multisquare_ClearFlags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ABF4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006ABF8: lw          $a0, -0x460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X460);
    // 0x8006ABFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006AC00: sltiu       $at, $a2, 0x2C
    ctx->r1 = ctx->r6 < 0X2C ? 1 : 0;
    // 0x8006AC04: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8006AC08: beq         $at, $zero, L_8006AC24
    if (ctx->r1 == 0) {
        // 0x8006AC0C: addiu       $a1, $a0, 0x4
        ctx->r5 = ADD32(ctx->r4, 0X4);
            goto L_8006AC24;
    }
    // 0x8006AC0C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
L_8006AC10:
    // 0x8006AC10: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006AC14: sltiu       $at, $a2, 0x2C
    ctx->r1 = ctx->r6 < 0X2C ? 1 : 0;
    // 0x8006AC18: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x8006AC1C: bne         $at, $zero, L_8006AC10
    if (ctx->r1 != 0) {
        // 0x8006AC20: sb          $zero, -0xF($a1)
        MEM_B(-0XF, ctx->r5) = 0;
            goto L_8006AC10;
    }
    // 0x8006AC20: sb          $zero, -0xF($a1)
    MEM_B(-0XF, ctx->r5) = 0;
L_8006AC24:
    // 0x8006AC24: jr          $ra
    // 0x8006AC28: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8006AC28: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void Multisquare_FlagMatches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AC2C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006AC30: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006AC34: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8006AC38: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8006AC3C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006AC40: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006AC44: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006AC48: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006AC4C: jal         0x8006ABF4
    // 0x8006AC50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    Multisquare_ClearFlags(rdram, ctx);
        goto after_0;
    // 0x8006AC50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006AC54: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8006AC58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006AC5C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006AC60: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006AC64: lw          $t6, -0x430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X430);
    // 0x8006AC68: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006AC6C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006AC70: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8006AC74: slti        $at, $s3, 0xA
    ctx->r1 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x8006AC78: addu        $s0, $t6, $t9
    ctx->r16 = ADD32(ctx->r14, ctx->r25);
    // 0x8006AC7C: beq         $at, $zero, L_8006ACE4
    if (ctx->r1 == 0) {
        // 0x8006AC80: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006ACE4;
    }
    // 0x8006AC80: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006AC84:
    // 0x8006AC84: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8006AC88: nop

    // 0x8006AC8C: lbu         $s4, 0x3($s1)
    ctx->r20 = MEM_BU(ctx->r17, 0X3);
    // 0x8006AC90: jal         0x8006AB84
    // 0x8006AC94: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Multisquare_IsValidIndex(rdram, ctx);
        goto after_1;
    // 0x8006AC94: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x8006AC98: beq         $v0, $zero, L_8006ACD4
    if (ctx->r2 == 0) {
        // 0x8006AC9C: nop
    
            goto L_8006ACD4;
    }
    // 0x8006AC9C: nop

    // 0x8006ACA0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006ACA4: sll         $t1, $s4, 3
    ctx->r9 = S32(ctx->r20 << 3);
    // 0x8006ACA8: lw          $t0, -0x460($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X460);
    // 0x8006ACAC: addu        $t1, $t1, $s4
    ctx->r9 = ADD32(ctx->r9, ctx->r20);
    // 0x8006ACB0: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006ACB4: addu        $s2, $t0, $t1
    ctx->r18 = ADD32(ctx->r8, ctx->r9);
    // 0x8006ACB8: lbu         $t2, 0x4($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X4);
    // 0x8006ACBC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8006ACC0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8006ACC4: bne         $t2, $t3, L_8006ACD4
    if (ctx->r10 != ctx->r11) {
        // 0x8006ACC8: nop
    
            goto L_8006ACD4;
    }
    // 0x8006ACC8: nop

    // 0x8006ACCC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8006ACD0: sb          $t4, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r12;
L_8006ACD4:
    // 0x8006ACD4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8006ACD8: slti        $at, $s3, 0xA
    ctx->r1 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x8006ACDC: bne         $at, $zero, L_8006AC84
    if (ctx->r1 != 0) {
        // 0x8006ACE0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006AC84;
    }
    // 0x8006ACE0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006ACE4:
    // 0x8006ACE4: jal         0x8006ABA4
    // 0x8006ACE8: nop

    Multisquare_CountMatched(rdram, ctx);
        goto after_2;
    // 0x8006ACE8: nop

    after_2:
    // 0x8006ACEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006ACF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006ACF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ACF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006ACFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006AD00: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006AD04: jr          $ra
    // 0x8006AD08: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006AD08: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void Multisquare_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AD0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006AD10: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006AD14: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006AD18: lw          $s0, -0x460($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X460);
    // 0x8006AD1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006AD20: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006AD24: lbu         $s1, 0x0($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X0);
    // 0x8006AD28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006AD2C: beq         $s1, $at, L_8006AD54
    if (ctx->r17 == ctx->r1) {
        // 0x8006AD30: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006AD54;
    }
    // 0x8006AD30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006AD34: beq         $s1, $at, L_8006AD64
    if (ctx->r17 == ctx->r1) {
        // 0x8006AD38: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8006AD64;
    }
    // 0x8006AD38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006AD3C: beq         $s1, $at, L_8006AD74
    if (ctx->r17 == ctx->r1) {
        // 0x8006AD40: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8006AD74;
    }
    // 0x8006AD40: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006AD44: beq         $s1, $at, L_8006AD84
    if (ctx->r17 == ctx->r1) {
        // 0x8006AD48: nop
    
            goto L_8006AD84;
    }
    // 0x8006AD48: nop

    // 0x8006AD4C: b           L_8006AD8C
    // 0x8006AD50: nop

        goto L_8006AD8C;
    // 0x8006AD50: nop

L_8006AD54:
    // 0x8006AD54: jal         0x8006A740
    // 0x8006AD58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Multisquare_ScanNearPiece(rdram, ctx);
        goto after_0;
    // 0x8006AD58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006AD5C: b           L_8006AD8C
    // 0x8006AD60: nop

        goto L_8006AD8C;
    // 0x8006AD60: nop

L_8006AD64:
    // 0x8006AD64: jal         0x8006A708
    // 0x8006AD68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Multisquare_UpdateState2(rdram, ctx);
        goto after_1;
    // 0x8006AD68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8006AD6C: b           L_8006AD8C
    // 0x8006AD70: nop

        goto L_8006AD8C;
    // 0x8006AD70: nop

L_8006AD74:
    // 0x8006AD74: jal         0x8006A9F4
    // 0x8006AD78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Multisquare_UpdateExpand(rdram, ctx);
        goto after_2;
    // 0x8006AD78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8006AD7C: b           L_8006AD8C
    // 0x8006AD80: nop

        goto L_8006AD8C;
    // 0x8006AD80: nop

L_8006AD84:
    // 0x8006AD84: jal         0x8006A9BC
    // 0x8006AD88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Multisquare_UpdateState4(rdram, ctx);
        goto after_3;
    // 0x8006AD88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8006AD8C:
    // 0x8006AD8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AD90: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8006AD94: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006AD98: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006AD9C: jr          $ra
    // 0x8006ADA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006ADA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Multisquare_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ADA4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006ADA8: lw          $a0, -0x460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X460);
    // 0x8006ADAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006ADB0: sltiu       $at, $a2, 0x2C
    ctx->r1 = ctx->r6 < 0X2C ? 1 : 0;
    // 0x8006ADB4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8006ADB8: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x8006ADBC: beq         $at, $zero, L_8006ADDC
    if (ctx->r1 == 0) {
        // 0x8006ADC0: addiu       $a1, $a0, 0x4
        ctx->r5 = ADD32(ctx->r4, 0X4);
            goto L_8006ADDC;
    }
    // 0x8006ADC0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
L_8006ADC4:
    // 0x8006ADC4: sb          $a2, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r6;
    // 0x8006ADC8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006ADCC: sltiu       $at, $a2, 0x2C
    ctx->r1 = ctx->r6 < 0X2C ? 1 : 0;
    // 0x8006ADD0: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x8006ADD4: bne         $at, $zero, L_8006ADC4
    if (ctx->r1 != 0) {
        // 0x8006ADD8: sb          $zero, -0x12($a1)
        MEM_B(-0X12, ctx->r5) = 0;
            goto L_8006ADC4;
    }
    // 0x8006ADD8: sb          $zero, -0x12($a1)
    MEM_B(-0X12, ctx->r5) = 0;
L_8006ADDC:
    // 0x8006ADDC: jr          $ra
    // 0x8006ADE0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8006ADE0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void Multisquare_Deinit_doesnothing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ADE4: jr          $ra
    // 0x8006ADE8: nop

    return;
    // 0x8006ADE8: nop

;}

RECOMP_FUNC void Multisquare_SetActiveCellsAlpha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AEBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006AEC0: sltiu       $at, $a3, 0x2C
    ctx->r1 = ctx->r7 < 0X2C ? 1 : 0;
    // 0x8006AEC4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006AEC8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8006AECC: beq         $at, $zero, L_8006AEF8
    if (ctx->r1 == 0) {
        // 0x8006AED0: addiu       $a2, $a0, 0x4
        ctx->r6 = ADD32(ctx->r4, 0X4);
            goto L_8006AEF8;
    }
    // 0x8006AED0: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
L_8006AED4:
    // 0x8006AED4: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x8006AED8: nop

    // 0x8006AEDC: beq         $t6, $zero, L_8006AEE8
    if (ctx->r14 == 0) {
        // 0x8006AEE0: nop
    
            goto L_8006AEE8;
    }
    // 0x8006AEE0: nop

    // 0x8006AEE4: sb          $a1, 0x10($a2)
    MEM_B(0X10, ctx->r6) = ctx->r5;
L_8006AEE8:
    // 0x8006AEE8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006AEEC: sltiu       $at, $a3, 0x2C
    ctx->r1 = ctx->r7 < 0X2C ? 1 : 0;
    // 0x8006AEF0: bne         $at, $zero, L_8006AED4
    if (ctx->r1 != 0) {
        // 0x8006AEF4: addiu       $a2, $a2, 0x12
        ctx->r6 = ADD32(ctx->r6, 0X12);
            goto L_8006AED4;
    }
    // 0x8006AEF4: addiu       $a2, $a2, 0x12
    ctx->r6 = ADD32(ctx->r6, 0X12);
L_8006AEF8:
    // 0x8006AEF8: jr          $ra
    // 0x8006AEFC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006AEFC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void OpponentPlayer_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042800: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80042804: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80042808: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8004280C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80042810: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80042814: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80042818: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8004281C: jal         0x8007E03C
    // 0x80042820: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80042820: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    after_0:
    // 0x80042824: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80042828: sw          $v0, 0x5E04($at)
    MEM_W(0X5E04, ctx->r1) = ctx->r2;
    // 0x8004282C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80042830: lw          $t6, 0x5E04($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5E04);
    // 0x80042834: nop

    // 0x80042838: beq         $t6, $zero, L_80042B28
    if (ctx->r14 == 0) {
        // 0x8004283C: nop
    
            goto L_80042B28;
    }
    // 0x8004283C: nop

    // 0x80042840: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80042844: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80042848: beq         $at, $zero, L_8004289C
    if (ctx->r1 == 0) {
        // 0x8004284C: nop
    
            goto L_8004289C;
    }
    // 0x8004284C: nop

L_80042850:
    // 0x80042850: lbu         $t7, 0x3B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3B);
    // 0x80042854: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80042858: sllv        $t9, $t8, $s0
    ctx->r25 = S32(ctx->r24 << (ctx->r16 & 31));
    // 0x8004285C: and         $t0, $t7, $t9
    ctx->r8 = ctx->r15 & ctx->r25;
    // 0x80042860: beq         $t0, $zero, L_80042878
    if (ctx->r8 == 0) {
        // 0x80042864: nop
    
            goto L_80042878;
    }
    // 0x80042864: nop

    // 0x80042868: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004286C: addu        $t2, $sp, $s0
    ctx->r10 = ADD32(ctx->r29, ctx->r16);
    // 0x80042870: b           L_80042880
    // 0x80042874: sb          $t1, 0x30($t2)
    MEM_B(0X30, ctx->r10) = ctx->r9;
        goto L_80042880;
    // 0x80042874: sb          $t1, 0x30($t2)
    MEM_B(0X30, ctx->r10) = ctx->r9;
L_80042878:
    // 0x80042878: addu        $t3, $sp, $s0
    ctx->r11 = ADD32(ctx->r29, ctx->r16);
    // 0x8004287C: sb          $zero, 0x30($t3)
    MEM_B(0X30, ctx->r11) = 0;
L_80042880:
    // 0x80042880: addu        $t4, $sp, $s0
    ctx->r12 = ADD32(ctx->r29, ctx->r16);
    // 0x80042884: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80042888: andi        $t5, $s0, 0xFF
    ctx->r13 = ctx->r16 & 0XFF;
    // 0x8004288C: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x80042890: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80042894: bne         $at, $zero, L_80042850
    if (ctx->r1 != 0) {
        // 0x80042898: sb          $zero, 0x2C($t4)
        MEM_B(0X2C, ctx->r12) = 0;
            goto L_80042850;
    }
    // 0x80042898: sb          $zero, 0x2C($t4)
    MEM_B(0X2C, ctx->r12) = 0;
L_8004289C:
    // 0x8004289C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800428A0: addu        $t6, $sp, $s1
    ctx->r14 = ADD32(ctx->r29, ctx->r17);
    // 0x800428A4: lbu         $t6, 0x30($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X30);
    // 0x800428A8: nop

    // 0x800428AC: beq         $t6, $zero, L_800428C8
    if (ctx->r14 == 0) {
        // 0x800428B0: nop
    
            goto L_800428C8;
    }
    // 0x800428B0: nop

    // 0x800428B4: addu        $t8, $sp, $s1
    ctx->r24 = ADD32(ctx->r29, ctx->r17);
    // 0x800428B8: lbu         $t8, 0x2C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2C);
    // 0x800428BC: nop

    // 0x800428C0: beq         $t8, $zero, L_800428FC
    if (ctx->r24 == 0) {
        // 0x800428C4: nop
    
            goto L_800428FC;
    }
    // 0x800428C4: nop

L_800428C8:
    // 0x800428C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800428CC: andi        $t7, $s1, 0xFF
    ctx->r15 = ctx->r17 & 0XFF;
    // 0x800428D0: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800428D4: addu        $t9, $sp, $s1
    ctx->r25 = ADD32(ctx->r29, ctx->r17);
    // 0x800428D8: lbu         $t9, 0x30($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X30);
    // 0x800428DC: nop

    // 0x800428E0: beq         $t9, $zero, L_800428C8
    if (ctx->r25 == 0) {
        // 0x800428E4: nop
    
            goto L_800428C8;
    }
    // 0x800428E4: nop

    // 0x800428E8: addu        $t0, $sp, $s1
    ctx->r8 = ADD32(ctx->r29, ctx->r17);
    // 0x800428EC: lbu         $t0, 0x2C($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X2C);
    // 0x800428F0: nop

    // 0x800428F4: bne         $t0, $zero, L_800428C8
    if (ctx->r8 != 0) {
        // 0x800428F8: nop
    
            goto L_800428C8;
    }
    // 0x800428F8: nop

L_800428FC:
    // 0x800428FC: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80042900: lw          $t1, 0x5E04($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5E04);
    // 0x80042904: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80042908: sb          $s1, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r17;
    // 0x8004290C: lbu         $t2, 0x43($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X43);
    // 0x80042910: nop

    // 0x80042914: bne         $t2, $at, L_8004292C
    if (ctx->r10 != ctx->r1) {
        // 0x80042918: nop
    
            goto L_8004292C;
    }
    // 0x80042918: nop

    // 0x8004291C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80042920: jal         0x800A35EC
    // 0x80042924: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    Scene_RandRange(rdram, ctx);
        goto after_1;
    // 0x80042924: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80042928: sb          $v0, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r2;
L_8004292C:
    // 0x8004292C: lbu         $t3, 0x43($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X43);
    // 0x80042930: nop

    // 0x80042934: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x80042938: bne         $at, $zero, L_80042954
    if (ctx->r1 != 0) {
        // 0x8004293C: nop
    
            goto L_80042954;
    }
    // 0x8004293C: nop

    // 0x80042940: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80042944: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80042948: addiu       $a1, $a1, -0x4B90
    ctx->r5 = ADD32(ctx->r5, -0X4B90);
    // 0x8004294C: jal         0x80083560
    // 0x80042950: addiu       $a0, $a0, -0x4BA0
    ctx->r4 = ADD32(ctx->r4, -0X4BA0);
    debug_print_reason_routine(rdram, ctx);
        goto after_2;
    // 0x80042950: addiu       $a0, $a0, -0x4BA0
    ctx->r4 = ADD32(ctx->r4, -0X4BA0);
    after_2:
L_80042954:
    // 0x80042954: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80042958: lbu         $t4, 0x1F50($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X1F50);
    // 0x8004295C: nop

    // 0x80042960: beq         $t4, $zero, L_80042984
    if (ctx->r12 == 0) {
        // 0x80042964: nop
    
            goto L_80042984;
    }
    // 0x80042964: nop

    // 0x80042968: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8004296C: addiu       $t5, $t5, 0x5E00
    ctx->r13 = ADD32(ctx->r13, 0X5E00);
    // 0x80042970: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80042974: lw          $t8, 0x5E04($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5E04);
    // 0x80042978: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8004297C: b           L_800429AC
    // 0x80042980: sb          $t6, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r14;
        goto L_800429AC;
    // 0x80042980: sb          $t6, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r14;
L_80042984:
    // 0x80042984: lbu         $t7, 0x43($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X43);
    // 0x80042988: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8004298C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80042990: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80042994: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80042998: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8004299C: lw          $t1, 0x5E04($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5E04);
    // 0x800429A0: lbu         $t0, 0x5DF0($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X5DF0);
    // 0x800429A4: nop

    // 0x800429A8: sb          $t0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r8;
L_800429AC:
    // 0x800429AC: lbu         $t2, 0x3F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3F);
    // 0x800429B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800429B4: bne         $t2, $at, L_800429D8
    if (ctx->r10 != ctx->r1) {
        // 0x800429B8: nop
    
            goto L_800429D8;
    }
    // 0x800429B8: nop

    // 0x800429BC: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x800429C0: lw          $t3, 0x5E04($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5E04);
    // 0x800429C4: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800429C8: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x800429CC: nop

    // 0x800429D0: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800429D4: sb          $t5, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r13;
L_800429D8:
    // 0x800429D8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800429DC: lbu         $t6, 0x1F50($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1F50);
    // 0x800429E0: nop

    // 0x800429E4: beq         $t6, $zero, L_80042A20
    if (ctx->r14 == 0) {
        // 0x800429E8: nop
    
            goto L_80042A20;
    }
    // 0x800429E8: nop

    // 0x800429EC: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x800429F0: addiu       $t8, $t8, 0x5E00
    ctx->r24 = ADD32(ctx->r24, 0X5E00);
    // 0x800429F4: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800429F8: lw          $t9, 0x5E04($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5E04);
    // 0x800429FC: lbu         $t7, 0x1($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X1);
    // 0x80042A00: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80042A04: sb          $t7, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r15;
    // 0x80042A08: addiu       $t0, $t0, 0x5E00
    ctx->r8 = ADD32(ctx->r8, 0X5E00);
    // 0x80042A0C: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80042A10: lw          $t2, 0x5E04($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5E04);
    // 0x80042A14: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x80042A18: b           L_80042A6C
    // 0x80042A1C: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
        goto L_80042A6C;
    // 0x80042A1C: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
L_80042A20:
    // 0x80042A20: lbu         $t4, 0x43($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X43);
    // 0x80042A24: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80042A28: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80042A2C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80042A30: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80042A34: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80042A38: lw          $t6, 0x5E04($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5E04);
    // 0x80042A3C: lbu         $t3, 0x5DF1($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X5DF1);
    // 0x80042A40: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80042A44: sb          $t3, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r11;
    // 0x80042A48: lbu         $t8, 0x43($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X43);
    // 0x80042A4C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80042A50: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80042A54: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x80042A58: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80042A5C: lbu         $t9, 0x5DF2($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X5DF2);
    // 0x80042A60: lw          $t0, 0x5E04($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5E04);
    // 0x80042A64: nop

    // 0x80042A68: sb          $t9, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r25;
L_80042A6C:
    // 0x80042A6C: lbu         $t1, 0x3B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3B);
    // 0x80042A70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042A74: bne         $t1, $at, L_80042AA4
    if (ctx->r9 != ctx->r1) {
        // 0x80042A78: nop
    
            goto L_80042AA4;
    }
    // 0x80042A78: nop

    // 0x80042A7C: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80042A80: lw          $t2, 0x5E04($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5E04);
    // 0x80042A84: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80042A88: lbu         $t4, 0x1($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X1);
    // 0x80042A8C: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80042A90: ori         $t5, $t4, 0x18
    ctx->r13 = ctx->r12 | 0X18;
    // 0x80042A94: sb          $t5, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r13;
    // 0x80042A98: lw          $t6, 0x5E04($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5E04);
    // 0x80042A9C: nop

    // 0x80042AA0: sb          $t3, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r11;
L_80042AA4:
    // 0x80042AA4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80042AA8: lw          $t8, 0x5E04($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5E04);
    // 0x80042AAC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80042AB0: sb          $zero, 0x4($t8)
    MEM_B(0X4, ctx->r24) = 0;
    // 0x80042AB4: lw          $a0, 0x5E04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5E04);
    // 0x80042AB8: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80042ABC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80042AC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042AC4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80042AC8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80042ACC: jal         0x8003F760
    // 0x80042AD0: addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
    aisquarelist_ResetMoveList(rdram, ctx);
        goto after_3;
    // 0x80042AD0: addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
    after_3:
    // 0x80042AD4: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80042AD8: lw          $t9, 0x5E04($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5E04);
    // 0x80042ADC: nop

    // 0x80042AE0: lbu         $t0, 0x1($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1);
    // 0x80042AE4: nop

    // 0x80042AE8: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x80042AEC: beq         $t1, $zero, L_80042AFC
    if (ctx->r9 == 0) {
        // 0x80042AF0: nop
    
            goto L_80042AFC;
    }
    // 0x80042AF0: nop

    // 0x80042AF4: jal         0x8003E1E0
    // 0x80042AF8: addiu       $a0, $t9, 0x2E
    ctx->r4 = ADD32(ctx->r25, 0X2E);
    aisquarelist_Reset(rdram, ctx);
        goto after_4;
    // 0x80042AF8: addiu       $a0, $t9, 0x2E
    ctx->r4 = ADD32(ctx->r25, 0X2E);
    after_4:
L_80042AFC:
    // 0x80042AFC: jal         0x80041DD0
    // 0x80042B00: nop

    aisquarelist_AllocList(rdram, ctx);
        goto after_5;
    // 0x80042B00: nop

    after_5:
    // 0x80042B04: jal         0x8003DFA0
    // 0x80042B08: nop

    aisquarelist_AllocSquareBuffer(rdram, ctx);
        goto after_6;
    // 0x80042B08: nop

    after_6:
    // 0x80042B0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80042B10: sb          $zero, 0x1F52($at)
    MEM_B(0X1F52, ctx->r1) = 0;
    // 0x80042B14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80042B18: sb          $zero, 0x1F51($at)
    MEM_B(0X1F51, ctx->r1) = 0;
    // 0x80042B1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80042B20: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80042B24: sb          $t4, 0x1F55($at)
    MEM_B(0X1F55, ctx->r1) = ctx->r12;
L_80042B28:
    // 0x80042B28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80042B2C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80042B30: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80042B34: jr          $ra
    // 0x80042B38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80042B38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void OpponentPlayer_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042B3C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80042B40: lw          $t6, 0x5E04($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5E04);
    // 0x80042B44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042B48: beq         $t6, $zero, L_80042B78
    if (ctx->r14 == 0) {
        // 0x80042B4C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80042B78;
    }
    // 0x80042B4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042B50: jal         0x8003E004
    // 0x80042B54: nop

    aisquarelist_FreeSquareBuffer(rdram, ctx);
        goto after_0;
    // 0x80042B54: nop

    after_0:
    // 0x80042B58: jal         0x80041E24
    // 0x80042B5C: nop

    aisquarelist_FreeList(rdram, ctx);
        goto after_1;
    // 0x80042B5C: nop

    after_1:
    // 0x80042B60: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80042B64: lw          $a0, 0x5E04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5E04);
    // 0x80042B68: jal         0x8007E328
    // 0x80042B6C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_2;
    // 0x80042B6C: nop

    after_2:
    // 0x80042B70: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80042B74: sw          $zero, 0x5E04($at)
    MEM_W(0X5E04, ctx->r1) = 0;
L_80042B78:
    // 0x80042B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042B7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042B80: jr          $ra
    // 0x80042B84: nop

    return;
    // 0x80042B84: nop

;}

RECOMP_FUNC void OpponentPlayer_DecideMove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042B88: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80042B8C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80042B90: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80042B94: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80042B98: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80042B9C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80042BA0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80042BA4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80042BA8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80042BAC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80042BB0: jal         0x800412E0
    // 0x80042BB4: addiu       $a0, $sp, 0x4F
    ctx->r4 = ADD32(ctx->r29, 0X4F);
    aisquarelist_BuildBoardModel(rdram, ctx);
        goto after_0;
    // 0x80042BB4: addiu       $a0, $sp, 0x4F
    ctx->r4 = ADD32(ctx->r29, 0X4F);
    after_0:
    // 0x80042BB8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80042BBC: lw          $t7, 0x5E04($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5E04);
    // 0x80042BC0: sb          $v0, 0x4E($sp)
    MEM_B(0X4E, ctx->r29) = ctx->r2;
    // 0x80042BC4: lbu         $t6, 0x4E($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4E);
    // 0x80042BC8: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x80042BCC: nop

    // 0x80042BD0: slt         $s0, $t8, $t6
    ctx->r16 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80042BD4: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x80042BD8: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80042BDC: bne         $s0, $zero, L_80042C10
    if (ctx->r16 != 0) {
        // 0x80042BE0: nop
    
            goto L_80042C10;
    }
    // 0x80042BE0: nop

    // 0x80042BE4: lbu         $t0, 0x4F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4F);
    // 0x80042BE8: nop

    // 0x80042BEC: slti        $at, $t0, 0x7
    ctx->r1 = SIGNED(ctx->r8) < 0X7 ? 1 : 0;
    // 0x80042BF0: bne         $at, $zero, L_80042C0C
    if (ctx->r1 != 0) {
        // 0x80042BF4: nop
    
            goto L_80042C0C;
    }
    // 0x80042BF4: nop

    // 0x80042BF8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80042BFC: lb          $t1, 0x1F55($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X1F55);
    // 0x80042C00: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80042C04: beq         $t1, $at, L_80042C10
    if (ctx->r9 == ctx->r1) {
        // 0x80042C08: nop
    
            goto L_80042C10;
    }
    // 0x80042C08: nop

L_80042C0C:
    // 0x80042C0C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80042C10:
    // 0x80042C10: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x80042C14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80042C18: slti        $t3, $t2, 0x4
    ctx->r11 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80042C1C: lbu         $t4, 0x4E($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4E);
    // 0x80042C20: sb          $t3, 0x1F53($at)
    MEM_B(0X1F53, ctx->r1) = ctx->r11;
    // 0x80042C24: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80042C28: slt         $t5, $at, $t4
    ctx->r13 = SIGNED(ctx->r1) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80042C2C: bne         $t5, $zero, L_80042C40
    if (ctx->r13 != 0) {
        // 0x80042C30: sw          $t5, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r13;
            goto L_80042C40;
    }
    // 0x80042C30: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80042C34: andi        $t7, $t3, 0xFF
    ctx->r15 = ctx->r11 & 0XFF;
    // 0x80042C38: sltu        $t6, $zero, $t7
    ctx->r14 = 0 < ctx->r15 ? 1 : 0;
    // 0x80042C3C: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
L_80042C40:
    // 0x80042C40: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80042C44: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80042C48: lw          $t9, 0x5E04($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5E04);
    // 0x80042C4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80042C50: sb          $t8, 0x1F54($at)
    MEM_B(0X1F54, ctx->r1) = ctx->r24;
    // 0x80042C54: lbu         $t0, 0x1($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1);
    // 0x80042C58: nop

    // 0x80042C5C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80042C60: beq         $t1, $zero, L_80042C70
    if (ctx->r9 == 0) {
        // 0x80042C64: nop
    
            goto L_80042C70;
    }
    // 0x80042C64: nop

    // 0x80042C68: b           L_80042C9C
    // 0x80042C6C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80042C9C;
    // 0x80042C6C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80042C70:
    // 0x80042C70: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80042C74: lw          $t2, 0x5E04($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5E04);
    // 0x80042C78: nop

    // 0x80042C7C: lbu         $t4, 0x1($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X1);
    // 0x80042C80: nop

    // 0x80042C84: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x80042C88: beq         $t5, $zero, L_80042C98
    if (ctx->r13 == 0) {
        // 0x80042C8C: nop
    
            goto L_80042C98;
    }
    // 0x80042C8C: nop

    // 0x80042C90: b           L_80042C9C
    // 0x80042C94: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80042C9C;
    // 0x80042C94: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80042C98:
    // 0x80042C98: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_80042C9C:
    // 0x80042C9C: beq         $s0, $zero, L_80042CA8
    if (ctx->r16 == 0) {
        // 0x80042CA0: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80042CA8;
    }
    // 0x80042CA0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80042CA4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80042CA8:
    // 0x80042CA8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80042CAC: lw          $t3, -0x490($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X490);
    // 0x80042CB0: sb          $zero, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = 0;
    // 0x80042CB4: lbu         $t7, 0x13($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X13);
    // 0x80042CB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80042CBC: lw          $t6, -0xDD0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XDD0);
    // 0x80042CC0: sb          $t7, 0x4E($sp)
    MEM_B(0X4E, ctx->r29) = ctx->r15;
    // 0x80042CC4: lbu         $t8, 0x6684($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X6684);
    // 0x80042CC8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80042CCC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80042CD0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80042CD4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80042CD8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80042CDC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80042CE0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80042CE4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80042CE8: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80042CEC: lbu         $s2, 0x51F1($t0)
    ctx->r18 = MEM_BU(ctx->r8, 0X51F1);
    // 0x80042CF0: lbu         $a1, 0x1F53($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X1F53);
    // 0x80042CF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80042CF8: jal         0x8003E038
    // 0x80042CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    aisquarelist_BuildDropTable(rdram, ctx);
        goto after_1;
    // 0x80042CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80042D00: jal         0x80067DD8
    // 0x80042D04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    CurrentPiece_Spawn(rdram, ctx);
        goto after_2;
    // 0x80042D04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80042D08: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80042D0C: lbu         $a1, 0x1F53($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X1F53);
    // 0x80042D10: jal         0x8003E038
    // 0x80042D14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    aisquarelist_BuildDropTable(rdram, ctx);
        goto after_3;
    // 0x80042D14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80042D18: lbu         $a0, 0x4E($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4E);
    // 0x80042D1C: jal         0x80067DD8
    // 0x80042D20: nop

    CurrentPiece_Spawn(rdram, ctx);
        goto after_4;
    // 0x80042D20: nop

    after_4:
    // 0x80042D24: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80042D28: lw          $t1, 0x5E04($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5E04);
    // 0x80042D2C: nop

    // 0x80042D30: lbu         $t2, 0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1);
    // 0x80042D34: nop

    // 0x80042D38: andi        $t4, $t2, 0x8
    ctx->r12 = ctx->r10 & 0X8;
    // 0x80042D3C: beq         $t4, $zero, L_80042E38
    if (ctx->r12 == 0) {
        // 0x80042D40: nop
    
            goto L_80042E38;
    }
    // 0x80042D40: nop

    // 0x80042D44: bne         $s0, $zero, L_80042E38
    if (ctx->r16 != 0) {
        // 0x80042D48: nop
    
            goto L_80042E38;
    }
    // 0x80042D48: nop

    // 0x80042D4C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80042D50: lbu         $a1, 0x1F53($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X1F53);
    // 0x80042D54: jal         0x80040500
    // 0x80042D58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    aisquarelist_EvaluateSquareMoves(rdram, ctx);
        goto after_5;
    // 0x80042D58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80042D5C: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x80042D60: beq         $s1, $zero, L_80042D94
    if (ctx->r17 == 0) {
        // 0x80042D64: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_80042D94;
    }
    // 0x80042D64: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80042D68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80042D6C: jal         0x800427B8
    // 0x80042D70: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    aisquarelist_CopyMoveAt(rdram, ctx);
        goto after_6;
    // 0x80042D70: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_6:
    // 0x80042D74: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80042D78: lw          $t5, 0x1F40($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F40);
    // 0x80042D7C: sll         $t7, $s4, 3
    ctx->r15 = S32(ctx->r20 << 3);
    // 0x80042D80: lw          $t3, 0x0($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X0);
    // 0x80042D84: nop

    // 0x80042D88: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80042D8C: lh          $s5, 0x0($t8)
    ctx->r21 = MEM_H(ctx->r24, 0X0);
    // 0x80042D90: nop

L_80042D94:
    // 0x80042D94: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80042D98: beq         $s5, $at, L_80042E38
    if (ctx->r21 == ctx->r1) {
        // 0x80042D9C: nop
    
            goto L_80042E38;
    }
    // 0x80042D9C: nop

    // 0x80042DA0: lbu         $t6, 0x4E($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4E);
    // 0x80042DA4: nop

    // 0x80042DA8: beq         $t6, $s2, L_80042E38
    if (ctx->r14 == ctx->r18) {
        // 0x80042DAC: nop
    
            goto L_80042E38;
    }
    // 0x80042DAC: nop

    // 0x80042DB0: jal         0x80067DD8
    // 0x80042DB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    CurrentPiece_Spawn(rdram, ctx);
        goto after_7;
    // 0x80042DB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x80042DB8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80042DBC: lbu         $a1, 0x1F53($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X1F53);
    // 0x80042DC0: jal         0x80040500
    // 0x80042DC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    aisquarelist_EvaluateSquareMoves(rdram, ctx);
        goto after_8;
    // 0x80042DC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80042DC8: beq         $v0, $zero, L_80042E2C
    if (ctx->r2 == 0) {
        // 0x80042DCC: nop
    
            goto L_80042E2C;
    }
    // 0x80042DCC: nop

    // 0x80042DD0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80042DD4: lw          $t9, 0x1F40($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1F40);
    // 0x80042DD8: sll         $t1, $s4, 3
    ctx->r9 = S32(ctx->r20 << 3);
    // 0x80042DDC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80042DE0: nop

    // 0x80042DE4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80042DE8: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x80042DEC: nop

    // 0x80042DF0: slt         $at, $s5, $t4
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80042DF4: beq         $at, $zero, L_80042E18
    if (ctx->r1 == 0) {
        // 0x80042DF8: nop
    
            goto L_80042E18;
    }
    // 0x80042DF8: nop

    // 0x80042DFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80042E00: jal         0x800427B8
    // 0x80042E04: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    aisquarelist_CopyMoveAt(rdram, ctx);
        goto after_9;
    // 0x80042E04: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_9:
    // 0x80042E08: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80042E0C: sb          $t5, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r13;
    // 0x80042E10: b           L_80042E38
    // 0x80042E14: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80042E38;
    // 0x80042E14: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80042E18:
    // 0x80042E18: lbu         $a0, 0x4E($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4E);
    // 0x80042E1C: jal         0x80067DD8
    // 0x80042E20: nop

    CurrentPiece_Spawn(rdram, ctx);
        goto after_10;
    // 0x80042E20: nop

    after_10:
    // 0x80042E24: b           L_80042E38
    // 0x80042E28: nop

        goto L_80042E38;
    // 0x80042E28: nop

L_80042E2C:
    // 0x80042E2C: lbu         $a0, 0x4E($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4E);
    // 0x80042E30: jal         0x80067DD8
    // 0x80042E34: nop

    CurrentPiece_Spawn(rdram, ctx);
        goto after_11;
    // 0x80042E34: nop

    after_11:
L_80042E38:
    // 0x80042E38: bne         $s0, $zero, L_80042E48
    if (ctx->r16 != 0) {
        // 0x80042E3C: nop
    
            goto L_80042E48;
    }
    // 0x80042E3C: nop

    // 0x80042E40: bne         $s1, $zero, L_80042EF8
    if (ctx->r17 != 0) {
        // 0x80042E44: nop
    
            goto L_80042EF8;
    }
    // 0x80042E44: nop

L_80042E48:
    // 0x80042E48: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80042E4C: lb          $a2, 0x1F55($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X1F55);
    // 0x80042E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80042E54: jal         0x80040F9C
    // 0x80042E58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    aisquarelist_BuildCandidateMoves(rdram, ctx);
        goto after_12;
    // 0x80042E58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80042E5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80042E60: jal         0x800427B8
    // 0x80042E64: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    aisquarelist_CopyMoveAt(rdram, ctx);
        goto after_13;
    // 0x80042E64: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_13:
    // 0x80042E68: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80042E6C: lw          $t3, 0x1F40($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F40);
    // 0x80042E70: sll         $t8, $s3, 3
    ctx->r24 = S32(ctx->r19 << 3);
    // 0x80042E74: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x80042E78: lbu         $t9, 0x4E($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4E);
    // 0x80042E7C: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x80042E80: lh          $s5, 0x0($t6)
    ctx->r21 = MEM_H(ctx->r14, 0X0);
    // 0x80042E84: beq         $t9, $s2, L_80042EF8
    if (ctx->r25 == ctx->r18) {
        // 0x80042E88: nop
    
            goto L_80042EF8;
    }
    // 0x80042E88: nop

    // 0x80042E8C: jal         0x80067DD8
    // 0x80042E90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    CurrentPiece_Spawn(rdram, ctx);
        goto after_14;
    // 0x80042E90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x80042E94: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80042E98: lb          $a2, 0x1F55($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X1F55);
    // 0x80042E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80042EA0: jal         0x80040F9C
    // 0x80042EA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    aisquarelist_BuildCandidateMoves(rdram, ctx);
        goto after_15;
    // 0x80042EA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80042EA8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80042EAC: lw          $t0, 0x1F40($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F40);
    // 0x80042EB0: sll         $t2, $s3, 3
    ctx->r10 = S32(ctx->r19 << 3);
    // 0x80042EB4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80042EB8: nop

    // 0x80042EBC: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x80042EC0: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80042EC4: nop

    // 0x80042EC8: slt         $at, $s5, $t5
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80042ECC: beq         $at, $zero, L_80042EEC
    if (ctx->r1 == 0) {
        // 0x80042ED0: nop
    
            goto L_80042EEC;
    }
    // 0x80042ED0: nop

    // 0x80042ED4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80042ED8: jal         0x800427B8
    // 0x80042EDC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    aisquarelist_CopyMoveAt(rdram, ctx);
        goto after_16;
    // 0x80042EDC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_16:
    // 0x80042EE0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80042EE4: b           L_80042EF8
    // 0x80042EE8: sb          $t3, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r11;
        goto L_80042EF8;
    // 0x80042EE8: sb          $t3, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r11;
L_80042EEC:
    // 0x80042EEC: lbu         $a0, 0x4E($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4E);
    // 0x80042EF0: jal         0x80067DD8
    // 0x80042EF4: nop

    CurrentPiece_Spawn(rdram, ctx);
        goto after_17;
    // 0x80042EF4: nop

    after_17:
L_80042EF8:
    // 0x80042EF8: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x80042EFC: lw          $s6, 0x5E04($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X5E04);
    // 0x80042F00: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80042F04: addiu       $s6, $s6, 0x5
    ctx->r22 = ADD32(ctx->r22, 0X5);
    // 0x80042F08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80042F0C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80042F10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042F14: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80042F18: jal         0x8003F760
    // 0x80042F1C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    aisquarelist_ResetMoveList(rdram, ctx);
        goto after_18;
    // 0x80042F1C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_18:
    // 0x80042F20: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80042F24: sb          $t8, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r24;
    // 0x80042F28: sb          $zero, 0x8($s6)
    MEM_B(0X8, ctx->r22) = 0;
    // 0x80042F2C: beq         $s1, $zero, L_80042F48
    if (ctx->r17 == 0) {
        // 0x80042F30: addiu       $s7, $s6, 0x5
        ctx->r23 = ADD32(ctx->r22, 0X5);
            goto L_80042F48;
    }
    // 0x80042F30: addiu       $s7, $s6, 0x5
    ctx->r23 = ADD32(ctx->r22, 0X5);
    // 0x80042F34: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80042F38: jal         0x80041DA0
    // 0x80042F3C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    aisquarelist_CopyEntry3(rdram, ctx);
        goto after_19;
    // 0x80042F3C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_19:
    // 0x80042F40: b           L_80042F54
    // 0x80042F44: nop

        goto L_80042F54;
    // 0x80042F44: nop

L_80042F48:
    // 0x80042F48: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80042F4C: jal         0x80041DA0
    // 0x80042F50: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    aisquarelist_CopyEntry3(rdram, ctx);
        goto after_20;
    // 0x80042F50: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_20:
L_80042F54:
    // 0x80042F54: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80042F58: lw          $t6, 0x5E04($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5E04);
    // 0x80042F5C: nop

    // 0x80042F60: lbu         $t9, 0x1($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X1);
    // 0x80042F64: nop

    // 0x80042F68: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x80042F6C: beq         $t0, $zero, L_80043050
    if (ctx->r8 == 0) {
        // 0x80042F70: nop
    
            goto L_80043050;
    }
    // 0x80042F70: nop

    // 0x80042F74: lbu         $a0, 0x0($s7)
    ctx->r4 = MEM_BU(ctx->r23, 0X0);
    // 0x80042F78: lb          $a1, 0x1($s7)
    ctx->r5 = MEM_B(ctx->r23, 0X1);
    // 0x80042F7C: lbu         $a2, 0x2($s7)
    ctx->r6 = MEM_BU(ctx->r23, 0X2);
    // 0x80042F80: jal         0x800413C0
    // 0x80042F84: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_21;
    // 0x80042F84: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_21:
    // 0x80042F88: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80042F8C: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x80042F90: beq         $at, $zero, L_8004303C
    if (ctx->r1 == 0) {
        // 0x80042F94: nop
    
            goto L_8004303C;
    }
    // 0x80042F94: nop

L_80042F98:
    // 0x80042F98: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80042F9C: slti        $at, $s3, 0xA
    ctx->r1 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x80042FA0: beq         $at, $zero, L_80042FFC
    if (ctx->r1 == 0) {
        // 0x80042FA4: nop
    
            goto L_80042FFC;
    }
    // 0x80042FA4: nop

L_80042FA8:
    // 0x80042FA8: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x80042FAC: addu        $t2, $t2, $s4
    ctx->r10 = ADD32(ctx->r10, ctx->r20);
    // 0x80042FB0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80042FB4: addu        $t4, $s3, $t2
    ctx->r12 = ADD32(ctx->r19, ctx->r10);
    // 0x80042FB8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80042FBC: lw          $t1, 0x1F30($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1F30);
    // 0x80042FC0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80042FC4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80042FC8: addu        $t3, $t1, $t5
    ctx->r11 = ADD32(ctx->r9, ctx->r13);
    // 0x80042FCC: lbu         $t7, 0x0($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X0);
    // 0x80042FD0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80042FD4: beq         $t7, $at, L_80042FFC
    if (ctx->r15 == ctx->r1) {
        // 0x80042FD8: nop
    
            goto L_80042FFC;
    }
    // 0x80042FD8: nop

    // 0x80042FDC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80042FE0: sll         $t8, $s3, 24
    ctx->r24 = S32(ctx->r19 << 24);
    // 0x80042FE4: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x80042FE8: sra         $t6, $s3, 24
    ctx->r14 = S32(SIGNED(ctx->r19) >> 24);
    // 0x80042FEC: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x80042FF0: slti        $at, $s3, 0xA
    ctx->r1 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x80042FF4: bne         $at, $zero, L_80042FA8
    if (ctx->r1 != 0) {
        // 0x80042FF8: nop
    
            goto L_80042FA8;
    }
    // 0x80042FF8: nop

L_80042FFC:
    // 0x80042FFC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80043000: bne         $s3, $at, L_8004301C
    if (ctx->r19 != ctx->r1) {
        // 0x80043004: nop
    
            goto L_8004301C;
    }
    // 0x80043004: nop

    // 0x80043008: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8004300C: lw          $a0, 0x5E04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5E04);
    // 0x80043010: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80043014: jal         0x8003E608
    // 0x80043018: addiu       $a0, $a0, 0x2E
    ctx->r4 = ADD32(ctx->r4, 0X2E);
    aisquarelist_ShiftSquaresDown(rdram, ctx);
        goto after_22;
    // 0x80043018: addiu       $a0, $a0, 0x2E
    ctx->r4 = ADD32(ctx->r4, 0X2E);
    after_22:
L_8004301C:
    // 0x8004301C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80043020: sll         $t9, $s4, 24
    ctx->r25 = S32(ctx->r20 << 24);
    // 0x80043024: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
    // 0x80043028: sra         $t0, $s4, 24
    ctx->r8 = S32(SIGNED(ctx->r20) >> 24);
    // 0x8004302C: or          $s4, $t0, $zero
    ctx->r20 = ctx->r8 | 0;
    // 0x80043030: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x80043034: bne         $at, $zero, L_80042F98
    if (ctx->r1 != 0) {
        // 0x80043038: nop
    
            goto L_80042F98;
    }
    // 0x80043038: nop

L_8004303C:
    // 0x8004303C: lbu         $a0, 0x0($s7)
    ctx->r4 = MEM_BU(ctx->r23, 0X0);
    // 0x80043040: lb          $a1, 0x1($s7)
    ctx->r5 = MEM_B(ctx->r23, 0X1);
    // 0x80043044: lbu         $a2, 0x2($s7)
    ctx->r6 = MEM_BU(ctx->r23, 0X2);
    // 0x80043048: jal         0x800413C0
    // 0x8004304C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_23;
    // 0x8004304C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_23:
L_80043050:
    // 0x80043050: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80043054: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x80043058: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004305C: lbu         $a1, 0x1F53($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X1F53);
    // 0x80043060: lb          $s3, 0x11($t2)
    ctx->r19 = MEM_B(ctx->r10, 0X11);
    // 0x80043064: lb          $s4, 0x12($t2)
    ctx->r20 = MEM_B(ctx->r10, 0X12);
    // 0x80043068: lbu         $s5, 0xA($t2)
    ctx->r21 = MEM_BU(ctx->r10, 0XA);
    // 0x8004306C: jal         0x800400FC
    // 0x80043070: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    aisquarelist_FindReachableMoves(rdram, ctx);
        goto after_24;
    // 0x80043070: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_24:
    // 0x80043074: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80043078: lw          $t4, -0x490($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X490);
    // 0x8004307C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80043080: sb          $s3, 0x11($t4)
    MEM_B(0X11, ctx->r12) = ctx->r19;
    // 0x80043084: lw          $t1, -0x490($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X490);
    // 0x80043088: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004308C: sb          $s4, 0x12($t1)
    MEM_B(0X12, ctx->r9) = ctx->r20;
    // 0x80043090: lw          $t5, -0x490($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X490);
    // 0x80043094: nop

    // 0x80043098: sb          $s5, 0xA($t5)
    MEM_B(0XA, ctx->r13) = ctx->r21;
    // 0x8004309C: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x800430A0: nop

    // 0x800430A4: beq         $t3, $zero, L_800430F0
    if (ctx->r11 == 0) {
        // 0x800430A8: nop
    
            goto L_800430F0;
    }
    // 0x800430A8: nop

    // 0x800430AC: lbu         $a0, 0x4E($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4E);
    // 0x800430B0: jal         0x80067DD8
    // 0x800430B4: nop

    CurrentPiece_Spawn(rdram, ctx);
        goto after_25;
    // 0x800430B4: nop

    after_25:
    // 0x800430B8: lb          $t7, 0x0($s6)
    ctx->r15 = MEM_B(ctx->r22, 0X0);
    // 0x800430BC: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800430C0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800430C4: sb          $t8, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r24;
    // 0x800430C8: lb          $t9, 0x0($s6)
    ctx->r25 = MEM_B(ctx->r22, 0X0);
    // 0x800430CC: nop

    // 0x800430D0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800430D4: addu        $t2, $s6, $t0
    ctx->r10 = ADD32(ctx->r22, ctx->r8);
    // 0x800430D8: sb          $t6, 0x4($t2)
    MEM_B(0X4, ctx->r10) = ctx->r14;
    // 0x800430DC: lb          $t1, 0x0($s6)
    ctx->r9 = MEM_B(ctx->r22, 0X0);
    // 0x800430E0: lbu         $t4, 0x4E($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4E);
    // 0x800430E4: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x800430E8: addu        $t3, $s6, $t5
    ctx->r11 = ADD32(ctx->r22, ctx->r13);
    // 0x800430EC: sb          $t4, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r12;
L_800430F0:
    // 0x800430F0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800430F4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800430F8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800430FC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80043100: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80043104: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80043108: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8004310C: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80043110: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80043114: jr          $ra
    // 0x80043118: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80043118: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}

RECOMP_FUNC void OpponentPlayer_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004311C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80043120: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80043124: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80043128: lw          $t6, -0xDF0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XDF0);
    // 0x8004312C: lw          $t7, 0x5E04($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5E04);
    // 0x80043130: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80043134: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80043138: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004313C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80043140: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80043144: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043148: beq         $t7, $zero, L_800436EC
    if (ctx->r15 == 0) {
        // 0x8004314C: addiu       $s3, $t6, 0x28
        ctx->r19 = ADD32(ctx->r14, 0X28);
            goto L_800436EC;
    }
    // 0x8004314C: addiu       $s3, $t6, 0x28
    ctx->r19 = ADD32(ctx->r14, 0X28);
    // 0x80043150: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80043154: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80043158: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8004315C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80043160: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80043164: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80043168: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004316C: addiu       $t0, $t0, -0x10D0
    ctx->r8 = ADD32(ctx->r8, -0X10D0);
    // 0x80043170: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80043174: bne         $t1, $t6, L_800436EC
    if (ctx->r9 != ctx->r14) {
        // 0x80043178: nop
    
            goto L_800436EC;
    }
    // 0x80043178: nop

    // 0x8004317C: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80043180: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80043184: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80043188: lw          $t3, -0x14D4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X14D4);
    // 0x8004318C: nop

    // 0x80043190: lbu         $t4, 0x2($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X2);
    // 0x80043194: nop

    // 0x80043198: beq         $t4, $zero, L_800436EC
    if (ctx->r12 == 0) {
        // 0x8004319C: nop
    
            goto L_800436EC;
    }
    // 0x8004319C: nop

    // 0x800431A0: lbu         $t5, 0x4($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X4);
    // 0x800431A4: nop

    // 0x800431A8: beq         $t5, $zero, L_800436EC
    if (ctx->r13 == 0) {
        // 0x800431AC: nop
    
            goto L_800436EC;
    }
    // 0x800431AC: nop

    // 0x800431B0: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800431B4: lw          $t9, 0x5E04($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5E04);
    // 0x800431B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800431BC: lbu         $t0, 0x4($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X4);
    // 0x800431C0: nop

    // 0x800431C4: bne         $t0, $at, L_800431E4
    if (ctx->r8 != ctx->r1) {
        // 0x800431C8: nop
    
            goto L_800431E4;
    }
    // 0x800431C8: nop

    // 0x800431CC: jal         0x80042B88
    // 0x800431D0: nop

    OpponentPlayer_DecideMove(rdram, ctx);
        goto after_0;
    // 0x800431D0: nop

    after_0:
    // 0x800431D4: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800431D8: lw          $t6, 0x5E04($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5E04);
    // 0x800431DC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800431E0: sb          $t1, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r9;
L_800431E4:
    // 0x800431E4: lw          $t8, 0x88($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X88);
    // 0x800431E8: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x800431EC: beq         $t8, $at, L_8004320C
    if (ctx->r24 == ctx->r1) {
        // 0x800431F0: nop
    
            goto L_8004320C;
    }
    // 0x800431F0: nop

    // 0x800431F4: lw          $t2, 0x8C($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X8C);
    // 0x800431F8: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x800431FC: beq         $t2, $at, L_8004320C
    if (ctx->r10 == ctx->r1) {
        // 0x80043200: nop
    
            goto L_8004320C;
    }
    // 0x80043200: nop

    // 0x80043204: jal         0x80060CA0
    // 0x80043208: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    FUN_026C80_nineliner_loops_32t(rdram, ctx);
        goto after_1;
    // 0x80043208: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
L_8004320C:
    // 0x8004320C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80043210: lw          $t3, 0x5E04($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5E04);
    // 0x80043214: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80043218: lb          $t4, 0x5($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X5);
    // 0x8004321C: lbu         $t5, 0x1F51($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X1F51);
    // 0x80043220: lbu         $t9, 0x3($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X3);
    // 0x80043224: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80043228: addu        $s1, $t3, $t7
    ctx->r17 = ADD32(ctx->r11, ctx->r15);
    // 0x8004322C: slt         $at, $t5, $t9
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80043230: beq         $at, $zero, L_8004325C
    if (ctx->r1 == 0) {
        // 0x80043234: addiu       $s1, $s1, 0x6
        ctx->r17 = ADD32(ctx->r17, 0X6);
            goto L_8004325C;
    }
    // 0x80043234: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x80043238: jal         0x800A3AF0
    // 0x8004323C: nop

    frametime_delta(rdram, ctx);
        goto after_2;
    // 0x8004323C: nop

    after_2:
    // 0x80043240: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80043244: lbu         $t0, 0x1F51($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X1F51);
    // 0x80043248: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8004324C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043250: addu        $t1, $t0, $s4
    ctx->r9 = ADD32(ctx->r8, ctx->r20);
    // 0x80043254: b           L_800436EC
    // 0x80043258: sb          $t1, 0x1F51($at)
    MEM_B(0X1F51, ctx->r1) = ctx->r9;
        goto L_800436EC;
    // 0x80043258: sb          $t1, 0x1F51($at)
    MEM_B(0X1F51, ctx->r1) = ctx->r9;
L_8004325C:
    // 0x8004325C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043260: sb          $zero, 0x1F51($at)
    MEM_B(0X1F51, ctx->r1) = 0;
    // 0x80043264: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80043268: lw          $t6, -0x490($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X490);
    // 0x8004326C: lbu         $t8, 0x3($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X3);
    // 0x80043270: lh          $s2, 0x8($t6)
    ctx->r18 = MEM_H(ctx->r14, 0X8);
    // 0x80043274: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x80043278: beq         $at, $zero, L_800436EC
    if (ctx->r1 == 0) {
        // 0x8004327C: nop
    
            goto L_800436EC;
    }
    // 0x8004327C: nop

    // 0x80043280: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80043284: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043288: addu        $at, $at, $t8
    gpr jr_addend_80043294 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8004328C: lw          $t8, -0x4B84($at)
    ctx->r24 = ADD32(ctx->r1, -0X4B84);
    // 0x80043290: nop

    // 0x80043294: jr          $t8
    // 0x80043298: nop

    switch (jr_addend_80043294 >> 2) {
        case 0: goto L_80043410; break;
        case 1: goto L_800434D0; break;
        case 2: goto L_80043590; break;
        case 3: goto L_80043650; break;
        case 4: goto L_800436A0; break;
        case 5: goto L_8004329C; break;
        case 6: goto L_80043324; break;
        default: switch_error(__func__, 0x80043294, 0x800DB47C);
    }
    // 0x80043298: nop

L_8004329C:
    // 0x8004329C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800432A0: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x800432A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800432A8: lbu         $t4, 0x0($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X0);
    // 0x800432AC: nop

    // 0x800432B0: bne         $t4, $at, L_800432E8
    if (ctx->r12 != ctx->r1) {
        // 0x800432B4: nop
    
            goto L_800432E8;
    }
    // 0x800432B4: nop

    // 0x800432B8: lbu         $t7, 0x13($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X13);
    // 0x800432BC: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    // 0x800432C0: nop

    // 0x800432C4: bne         $t7, $t3, L_800432E8
    if (ctx->r15 != ctx->r11) {
        // 0x800432C8: nop
    
            goto L_800432E8;
    }
    // 0x800432C8: nop

    // 0x800432CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800432D0: lw          $a0, -0xDD0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XDD0);
    // 0x800432D4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800432D8: jal         0x800661D4
    // 0x800432DC: addiu       $a0, $a0, 0x51F0
    ctx->r4 = ADD32(ctx->r4, 0X51F0);
    PieceHold_Swap(rdram, ctx);
        goto after_3;
    // 0x800432DC: addiu       $a0, $a0, 0x51F0
    ctx->r4 = ADD32(ctx->r4, 0X51F0);
    after_3:
    // 0x800432E0: b           L_800436EC
    // 0x800432E4: nop

        goto L_800436EC;
    // 0x800432E4: nop

L_800432E8:
    // 0x800432E8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800432EC: lw          $t5, -0x490($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X490);
    // 0x800432F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800432F4: lbu         $t9, 0x0($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X0);
    // 0x800432F8: nop

    // 0x800432FC: bne         $t9, $at, L_800436EC
    if (ctx->r25 != ctx->r1) {
        // 0x80043300: nop
    
            goto L_800436EC;
    }
    // 0x80043300: nop

    // 0x80043304: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80043308: lw          $t0, 0x5E04($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5E04);
    // 0x8004330C: nop

    // 0x80043310: lb          $t1, 0x5($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X5);
    // 0x80043314: nop

    // 0x80043318: addiu       $t6, $t1, -0x1
    ctx->r14 = ADD32(ctx->r9, -0X1);
    // 0x8004331C: b           L_800436EC
    // 0x80043320: sb          $t6, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r14;
        goto L_800436EC;
    // 0x80043320: sb          $t6, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r14;
L_80043324:
    // 0x80043324: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80043328: lbu         $t8, 0x1F54($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1F54);
    // 0x8004332C: nop

    // 0x80043330: bne         $t8, $zero, L_80043358
    if (ctx->r24 != 0) {
        // 0x80043334: nop
    
            goto L_80043358;
    }
    // 0x80043334: nop

    // 0x80043338: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8004333C: lw          $t4, 0x5E04($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5E04);
    // 0x80043340: nop

    // 0x80043344: lbu         $t7, 0x1($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X1);
    // 0x80043348: nop

    // 0x8004334C: andi        $t3, $t7, 0x10
    ctx->r11 = ctx->r15 & 0X10;
    // 0x80043350: beq         $t3, $zero, L_80043370
    if (ctx->r11 == 0) {
        // 0x80043354: nop
    
            goto L_80043370;
    }
    // 0x80043354: nop

L_80043358:
    // 0x80043358: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004335C: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x80043360: jal         0x800676AC
    // 0x80043364: nop

    CurrentPiece_HardDrop(rdram, ctx);
        goto after_4;
    // 0x80043364: nop

    after_4:
    // 0x80043368: b           L_800436EC
    // 0x8004336C: nop

        goto L_800436EC;
    // 0x8004336C: nop

L_80043370:
    // 0x80043370: slti        $at, $s2, 0x3C
    ctx->r1 = SIGNED(ctx->r18) < 0X3C ? 1 : 0;
    // 0x80043374: beq         $at, $zero, L_800436EC
    if (ctx->r1 == 0) {
        // 0x80043378: nop
    
            goto L_800436EC;
    }
    // 0x80043378: nop

    // 0x8004337C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80043380: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x80043384: lb          $t9, 0x1($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1);
    // 0x80043388: lb          $t5, 0x12($t2)
    ctx->r13 = MEM_B(ctx->r10, 0X12);
    // 0x8004338C: nop

    // 0x80043390: slt         $at, $t5, $t9
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80043394: beq         $at, $zero, L_800436EC
    if (ctx->r1 == 0) {
        // 0x80043398: nop
    
            goto L_800436EC;
    }
    // 0x80043398: nop

    // 0x8004339C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x800433A0: lw          $t1, 0x5E04($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5E04);
    // 0x800433A4: nop

    // 0x800433A8: lbu         $t6, 0x1($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X1);
    // 0x800433AC: nop

    // 0x800433B0: andi        $t0, $t6, 0x20
    ctx->r8 = ctx->r14 & 0X20;
    // 0x800433B4: beq         $t0, $zero, L_800433C8
    if (ctx->r8 == 0) {
        // 0x800433B8: nop
    
            goto L_800433C8;
    }
    // 0x800433B8: nop

    // 0x800433BC: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x800433C0: b           L_800436EC
    // 0x800433C4: sh          $t8, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r24;
        goto L_800436EC;
    // 0x800433C4: sh          $t8, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r24;
L_800433C8:
    // 0x800433C8: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x800433CC: lw          $t4, 0x5E04($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5E04);
    // 0x800433D0: nop

    // 0x800433D4: lbu         $t7, 0x1($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X1);
    // 0x800433D8: nop

    // 0x800433DC: andi        $t3, $t7, 0x40
    ctx->r11 = ctx->r15 & 0X40;
    // 0x800433E0: beq         $t3, $zero, L_800436EC
    if (ctx->r11 == 0) {
        // 0x800433E4: nop
    
            goto L_800436EC;
    }
    // 0x800433E4: nop

    // 0x800433E8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800433EC: lw          $t9, -0x490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X490);
    // 0x800433F0: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x800433F4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800433F8: sh          $t5, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r13;
    // 0x800433FC: lw          $t1, -0x490($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X490);
    // 0x80043400: nop

    // 0x80043404: lh          $t6, 0x8($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X8);
    // 0x80043408: b           L_800436EC
    // 0x8004340C: sh          $t6, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r14;
        goto L_800436EC;
    // 0x8004340C: sh          $t6, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r14;
L_80043410:
    // 0x80043410: slti        $at, $s2, 0x3C
    ctx->r1 = SIGNED(ctx->r18) < 0X3C ? 1 : 0;
    // 0x80043414: beq         $at, $zero, L_80043490
    if (ctx->r1 == 0) {
        // 0x80043418: nop
    
            goto L_80043490;
    }
    // 0x80043418: nop

    // 0x8004341C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80043420: lbu         $t0, 0x1F54($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X1F54);
    // 0x80043424: nop

    // 0x80043428: bne         $t0, $zero, L_80043450
    if (ctx->r8 != 0) {
        // 0x8004342C: nop
    
            goto L_80043450;
    }
    // 0x8004342C: nop

    // 0x80043430: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80043434: lw          $t8, 0x5E04($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5E04);
    // 0x80043438: nop

    // 0x8004343C: lbu         $t2, 0x1($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X1);
    // 0x80043440: nop

    // 0x80043444: andi        $t4, $t2, 0x40
    ctx->r12 = ctx->r10 & 0X40;
    // 0x80043448: beq         $t4, $zero, L_80043490
    if (ctx->r12 == 0) {
        // 0x8004344C: nop
    
            goto L_80043490;
    }
    // 0x8004344C: nop

L_80043450:
    // 0x80043450: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80043454: lw          $t7, -0x490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X490);
    // 0x80043458: lb          $t5, 0x1($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X1);
    // 0x8004345C: lb          $t3, 0x12($t7)
    ctx->r11 = MEM_B(ctx->r15, 0X12);
    // 0x80043460: nop

    // 0x80043464: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80043468: beq         $at, $zero, L_80043490
    if (ctx->r1 == 0) {
        // 0x8004346C: nop
    
            goto L_80043490;
    }
    // 0x8004346C: nop

    // 0x80043470: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x80043474: sh          $t9, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r25;
    // 0x80043478: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004347C: lw          $t6, -0x490($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X490);
    // 0x80043480: nop

    // 0x80043484: lh          $t1, 0x8($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X8);
    // 0x80043488: b           L_800436EC
    // 0x8004348C: sh          $t1, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r9;
        goto L_800436EC;
    // 0x8004348C: sh          $t1, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r9;
L_80043490:
    // 0x80043490: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80043494: lw          $t0, -0x490($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X490);
    // 0x80043498: lb          $t2, 0x1($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X1);
    // 0x8004349C: lb          $t8, 0x12($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X12);
    // 0x800434A0: nop

    // 0x800434A4: slt         $at, $t8, $t2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800434A8: bne         $at, $zero, L_800436EC
    if (ctx->r1 != 0) {
        // 0x800434AC: nop
    
            goto L_800436EC;
    }
    // 0x800434AC: nop

    // 0x800434B0: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x800434B4: lw          $t4, 0x5E04($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5E04);
    // 0x800434B8: nop

    // 0x800434BC: lb          $t3, 0x5($t4)
    ctx->r11 = MEM_B(ctx->r12, 0X5);
    // 0x800434C0: nop

    // 0x800434C4: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x800434C8: b           L_800436EC
    // 0x800434CC: sb          $t5, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r13;
        goto L_800436EC;
    // 0x800434CC: sb          $t5, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r13;
L_800434D0:
    // 0x800434D0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800434D4: lw          $t7, -0x490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X490);
    // 0x800434D8: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x800434DC: lb          $t1, 0x11($t7)
    ctx->r9 = MEM_B(ctx->r15, 0X11);
    // 0x800434E0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800434E4: subu        $s0, $t9, $t1
    ctx->r16 = SUB32(ctx->r25, ctx->r9);
    // 0x800434E8: sll         $t6, $s0, 24
    ctx->r14 = S32(ctx->r16 << 24);
    // 0x800434EC: lbu         $t8, 0x1F54($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1F54);
    // 0x800434F0: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800434F4: sra         $t0, $s0, 24
    ctx->r8 = S32(SIGNED(ctx->r16) >> 24);
    // 0x800434F8: bne         $t8, $zero, L_8004351C
    if (ctx->r24 != 0) {
        // 0x800434FC: or          $s0, $t0, $zero
        ctx->r16 = ctx->r8 | 0;
            goto L_8004351C;
    }
    // 0x800434FC: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80043500: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80043504: lw          $t2, 0x5E04($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5E04);
    // 0x80043508: nop

    // 0x8004350C: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x80043510: nop

    // 0x80043514: andi        $t5, $t3, 0x80
    ctx->r13 = ctx->r11 & 0X80;
    // 0x80043518: beq         $t5, $zero, L_80043550
    if (ctx->r13 == 0) {
        // 0x8004351C: slti        $at, $s0, 0x2
        ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_80043550;
    }
L_8004351C:
    // 0x8004351C: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80043520: bne         $at, $zero, L_80043550
    if (ctx->r1 != 0) {
        // 0x80043524: nop
    
            goto L_80043550;
    }
    // 0x80043524: nop

    // 0x80043528: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004352C: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x80043530: jal         0x80067254
    // 0x80043534: nop

    CurrentPiece_MoveRight(rdram, ctx);
        goto after_5;
    // 0x80043534: nop

    after_5:
    // 0x80043538: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004353C: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x80043540: jal         0x80067254
    // 0x80043544: nop

    CurrentPiece_MoveRight(rdram, ctx);
        goto after_6;
    // 0x80043544: nop

    after_6:
    // 0x80043548: b           L_800436EC
    // 0x8004354C: nop

        goto L_800436EC;
    // 0x8004354C: nop

L_80043550:
    // 0x80043550: blez        $s0, L_80043570
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80043554: nop
    
            goto L_80043570;
    }
    // 0x80043554: nop

    // 0x80043558: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004355C: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x80043560: jal         0x80067254
    // 0x80043564: nop

    CurrentPiece_MoveRight(rdram, ctx);
        goto after_7;
    // 0x80043564: nop

    after_7:
    // 0x80043568: b           L_800436EC
    // 0x8004356C: nop

        goto L_800436EC;
    // 0x8004356C: nop

L_80043570:
    // 0x80043570: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80043574: lw          $t4, 0x5E04($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5E04);
    // 0x80043578: nop

    // 0x8004357C: lb          $t7, 0x5($t4)
    ctx->r15 = MEM_B(ctx->r12, 0X5);
    // 0x80043580: nop

    // 0x80043584: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80043588: b           L_800436EC
    // 0x8004358C: sb          $t9, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r25;
        goto L_800436EC;
    // 0x8004358C: sb          $t9, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r25;
L_80043590:
    // 0x80043590: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80043594: lw          $t1, -0x490($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X490);
    // 0x80043598: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
    // 0x8004359C: lb          $t6, 0x11($t1)
    ctx->r14 = MEM_B(ctx->r9, 0X11);
    // 0x800435A0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800435A4: subu        $s0, $t6, $t0
    ctx->r16 = SUB32(ctx->r14, ctx->r8);
    // 0x800435A8: sll         $t8, $s0, 24
    ctx->r24 = S32(ctx->r16 << 24);
    // 0x800435AC: lbu         $t3, 0x1F54($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X1F54);
    // 0x800435B0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800435B4: sra         $t2, $s0, 24
    ctx->r10 = S32(SIGNED(ctx->r16) >> 24);
    // 0x800435B8: bne         $t3, $zero, L_800435DC
    if (ctx->r11 != 0) {
        // 0x800435BC: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_800435DC;
    }
    // 0x800435BC: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800435C0: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x800435C4: lw          $t5, 0x5E04($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5E04);
    // 0x800435C8: nop

    // 0x800435CC: lbu         $t7, 0x1($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X1);
    // 0x800435D0: nop

    // 0x800435D4: andi        $t9, $t7, 0x80
    ctx->r25 = ctx->r15 & 0X80;
    // 0x800435D8: beq         $t9, $zero, L_80043610
    if (ctx->r25 == 0) {
        // 0x800435DC: slti        $at, $s0, 0x2
        ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_80043610;
    }
L_800435DC:
    // 0x800435DC: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x800435E0: bne         $at, $zero, L_80043610
    if (ctx->r1 != 0) {
        // 0x800435E4: nop
    
            goto L_80043610;
    }
    // 0x800435E4: nop

    // 0x800435E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800435EC: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x800435F0: jal         0x8006715C
    // 0x800435F4: nop

    CurrentPiece_MoveLeft(rdram, ctx);
        goto after_8;
    // 0x800435F4: nop

    after_8:
    // 0x800435F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800435FC: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x80043600: jal         0x8006715C
    // 0x80043604: nop

    CurrentPiece_MoveLeft(rdram, ctx);
        goto after_9;
    // 0x80043604: nop

    after_9:
    // 0x80043608: b           L_800436EC
    // 0x8004360C: nop

        goto L_800436EC;
    // 0x8004360C: nop

L_80043610:
    // 0x80043610: blez        $s0, L_80043630
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80043614: nop
    
            goto L_80043630;
    }
    // 0x80043614: nop

    // 0x80043618: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004361C: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x80043620: jal         0x8006715C
    // 0x80043624: nop

    CurrentPiece_MoveLeft(rdram, ctx);
        goto after_10;
    // 0x80043624: nop

    after_10:
    // 0x80043628: b           L_800436EC
    // 0x8004362C: nop

        goto L_800436EC;
    // 0x8004362C: nop

L_80043630:
    // 0x80043630: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80043634: lw          $t4, 0x5E04($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5E04);
    // 0x80043638: nop

    // 0x8004363C: lb          $t1, 0x5($t4)
    ctx->r9 = MEM_B(ctx->r12, 0X5);
    // 0x80043640: nop

    // 0x80043644: addiu       $t6, $t1, -0x1
    ctx->r14 = ADD32(ctx->r9, -0X1);
    // 0x80043648: b           L_800436EC
    // 0x8004364C: sb          $t6, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r14;
        goto L_800436EC;
    // 0x8004364C: sb          $t6, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r14;
L_80043650:
    // 0x80043650: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80043654: lw          $t0, -0x490($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X490);
    // 0x80043658: lbu         $t2, 0x2($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X2);
    // 0x8004365C: lbu         $t8, 0xA($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XA);
    // 0x80043660: nop

    // 0x80043664: beq         $t8, $t2, L_80043680
    if (ctx->r24 == ctx->r10) {
        // 0x80043668: nop
    
            goto L_80043680;
    }
    // 0x80043668: nop

    // 0x8004366C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80043670: jal         0x8006734C
    // 0x80043674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    CurrentPiece_TryRotate(rdram, ctx);
        goto after_11;
    // 0x80043674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80043678: b           L_800436EC
    // 0x8004367C: nop

        goto L_800436EC;
    // 0x8004367C: nop

L_80043680:
    // 0x80043680: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80043684: lw          $t3, 0x5E04($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5E04);
    // 0x80043688: nop

    // 0x8004368C: lb          $t5, 0x5($t3)
    ctx->r13 = MEM_B(ctx->r11, 0X5);
    // 0x80043690: nop

    // 0x80043694: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x80043698: b           L_800436EC
    // 0x8004369C: sb          $t7, 0x5($t3)
    MEM_B(0X5, ctx->r11) = ctx->r15;
        goto L_800436EC;
    // 0x8004369C: sb          $t7, 0x5($t3)
    MEM_B(0X5, ctx->r11) = ctx->r15;
L_800436A0:
    // 0x800436A0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800436A4: lw          $t9, -0x490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X490);
    // 0x800436A8: lbu         $t6, 0x2($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X2);
    // 0x800436AC: lbu         $t1, 0xA($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0XA);
    // 0x800436B0: nop

    // 0x800436B4: beq         $t1, $t6, L_800436D0
    if (ctx->r9 == ctx->r14) {
        // 0x800436B8: nop
    
            goto L_800436D0;
    }
    // 0x800436B8: nop

    // 0x800436BC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800436C0: jal         0x8006734C
    // 0x800436C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    CurrentPiece_TryRotate(rdram, ctx);
        goto after_12;
    // 0x800436C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_12:
    // 0x800436C8: b           L_800436EC
    // 0x800436CC: nop

        goto L_800436EC;
    // 0x800436CC: nop

L_800436D0:
    // 0x800436D0: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x800436D4: lw          $t4, 0x5E04($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5E04);
    // 0x800436D8: nop

    // 0x800436DC: lb          $t8, 0x5($t4)
    ctx->r24 = MEM_B(ctx->r12, 0X5);
    // 0x800436E0: nop

    // 0x800436E4: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x800436E8: sb          $t2, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r10;
L_800436EC:
    // 0x800436EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800436F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800436F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800436F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800436FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80043700: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80043704: jr          $ra
    // 0x80043708: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80043708: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void OpponentPlayer_RequestDecision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004370C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80043710: lw          $t6, 0x5E04($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5E04);
    // 0x80043714: nop

    // 0x80043718: beq         $t6, $zero, L_80043764
    if (ctx->r14 == 0) {
        // 0x8004371C: nop
    
            goto L_80043764;
    }
    // 0x8004371C: nop

    // 0x80043720: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80043724: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80043728: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004372C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80043730: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80043734: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80043738: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8004373C: lw          $t1, -0xDF0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XDF0);
    // 0x80043740: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80043744: addiu       $t9, $t9, -0x10D0
    ctx->r25 = ADD32(ctx->r25, -0X10D0);
    // 0x80043748: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8004374C: bne         $t0, $t1, L_80043764
    if (ctx->r8 != ctx->r9) {
        // 0x80043750: nop
    
            goto L_80043764;
    }
    // 0x80043750: nop

    // 0x80043754: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80043758: lw          $t3, 0x5E04($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5E04);
    // 0x8004375C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80043760: sb          $t2, 0x4($t3)
    MEM_B(0X4, ctx->r11) = ctx->r10;
L_80043764:
    // 0x80043764: jr          $ra
    // 0x80043768: nop

    return;
    // 0x80043768: nop

;}

RECOMP_FUNC void OpponentPlayer_UpdateTarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004376C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80043770: lw          $t6, 0x5E04($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5E04);
    // 0x80043774: nop

    // 0x80043778: beq         $t6, $zero, L_800437FC
    if (ctx->r14 == 0) {
        // 0x8004377C: nop
    
            goto L_800437FC;
    }
    // 0x8004377C: nop

    // 0x80043780: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80043784: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80043788: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004378C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80043790: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80043794: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80043798: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8004379C: lw          $t1, -0xDF0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XDF0);
    // 0x800437A0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800437A4: addiu       $t9, $t9, -0x10D0
    ctx->r25 = ADD32(ctx->r25, -0X10D0);
    // 0x800437A8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800437AC: beq         $t0, $t1, L_800437C4
    if (ctx->r8 == ctx->r9) {
        // 0x800437B0: nop
    
            goto L_800437C4;
    }
    // 0x800437B0: nop

    // 0x800437B4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800437B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800437BC: jr          $ra
    // 0x800437C0: sb          $t2, 0x1F55($at)
    MEM_B(0X1F55, ctx->r1) = ctx->r10;
    return;
    // 0x800437C0: sb          $t2, 0x1F55($at)
    MEM_B(0X1F55, ctx->r1) = ctx->r10;
L_800437C4:
    // 0x800437C4: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x800437C8: lw          $t3, 0x5E04($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5E04);
    // 0x800437CC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800437D0: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800437D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800437D8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800437DC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800437E0: lw          $t6, -0x14D4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X14D4);
    // 0x800437E4: nop

    // 0x800437E8: lw          $t7, 0x674C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X674C);
    // 0x800437EC: nop

    // 0x800437F0: lbu         $t8, 0x15($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X15);
    // 0x800437F4: nop

    // 0x800437F8: sb          $t8, 0x1F55($at)
    MEM_B(0X1F55, ctx->r1) = ctx->r24;
L_800437FC:
    // 0x800437FC: jr          $ra
    // 0x80043800: nop

    return;
    // 0x80043800: nop

    // 0x80043804: nop

    // 0x80043808: nop

    // 0x8004380C: nop

;}

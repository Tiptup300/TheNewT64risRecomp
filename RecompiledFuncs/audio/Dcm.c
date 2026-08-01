#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Dcm_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80085D54: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80085D58: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80085D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085D60: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80085D64: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80085D68: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80085D6C: sb          $zero, 0x454($t6)
    MEM_B(0X454, ctx->r14) = 0;
    // 0x80085D70: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80085D74: lw          $t7, -0x4FB0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4FB0);
    // 0x80085D78: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80085D7C: addiu       $t9, $zero, 0x4E20
    ctx->r25 = ADD32(0, 0X4E20);
    // 0x80085D80: sw          $t7, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r15;
    // 0x80085D84: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80085D88: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80085D8C: sw          $t9, 0x1578($t0)
    MEM_W(0X1578, ctx->r8) = ctx->r25;
    // 0x80085D90: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80085D94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085D98: sb          $zero, 0x1570($t1)
    MEM_B(0X1570, ctx->r9) = 0;
    // 0x80085D9C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80085DA0: nop

    // 0x80085DA4: sb          $t2, 0x1571($t3)
    MEM_B(0X1571, ctx->r11) = ctx->r10;
    // 0x80085DA8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80085DAC: nop

    // 0x80085DB0: sb          $zero, 0x1587($t4)
    MEM_B(0X1587, ctx->r12) = 0;
    // 0x80085DB4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80085DB8: nop

    // 0x80085DBC: sb          $zero, 0x158C($t5)
    MEM_B(0X158C, ctx->r13) = 0;
    // 0x80085DC0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80085DC4: addiu       $t5, $zero, 0x7FFF
    ctx->r13 = ADD32(0, 0X7FFF);
    // 0x80085DC8: sb          $zero, 0x1584($t6)
    MEM_B(0X1584, ctx->r14) = 0;
    // 0x80085DCC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80085DD0: nop

    // 0x80085DD4: sb          $zero, 0x1572($t7)
    MEM_B(0X1572, ctx->r15) = 0;
    // 0x80085DD8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80085DDC: nop

    // 0x80085DE0: sh          $zero, 0x157E($t8)
    MEM_H(0X157E, ctx->r24) = 0;
    // 0x80085DE4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80085DE8: nop

    // 0x80085DEC: sh          $zero, 0x1580($t9)
    MEM_H(0X1580, ctx->r25) = 0;
    // 0x80085DF0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80085DF4: nop

    // 0x80085DF8: sb          $zero, 0x1585($t0)
    MEM_B(0X1585, ctx->r8) = 0;
    // 0x80085DFC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80085E00: nop

    // 0x80085E04: sh          $zero, 0x1582($t1)
    MEM_H(0X1582, ctx->r9) = 0;
    // 0x80085E08: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80085E0C: nop

    // 0x80085E10: sb          $zero, 0x1586($t2)
    MEM_B(0X1586, ctx->r10) = 0;
    // 0x80085E14: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80085E18: lh          $t3, 0x3A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X3A);
    // 0x80085E1C: nop

    // 0x80085E20: sh          $t3, 0x157C($t4)
    MEM_H(0X157C, ctx->r12) = ctx->r11;
    // 0x80085E24: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80085E28: nop

    // 0x80085E2C: sh          $t5, 0x158A($t6)
    MEM_H(0X158A, ctx->r14) = ctx->r13;
    // 0x80085E30: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80085E34: nop

    // 0x80085E38: sh          $zero, 0x1588($t7)
    MEM_H(0X1588, ctx->r15) = 0;
    // 0x80085E3C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80085E40: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80085E44: sb          $zero, 0x1598($t8)
    MEM_B(0X1598, ctx->r24) = 0;
    // 0x80085E48: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80085E4C: addiu       $t7, $t7, 0x78F0
    ctx->r15 = ADD32(ctx->r15, 0X78F0);
    // 0x80085E50: sb          $zero, 0x1599($t9)
    MEM_B(0X1599, ctx->r25) = 0;
    // 0x80085E54: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80085E58: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80085E5C: nop

    // 0x80085E60: sw          $t0, 0x438($t1)
    MEM_W(0X438, ctx->r9) = ctx->r8;
    // 0x80085E64: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80085E68: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80085E6C: nop

    // 0x80085E70: sw          $t2, 0x43C($t3)
    MEM_W(0X43C, ctx->r11) = ctx->r10;
    // 0x80085E74: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80085E78: lbu         $t4, 0x3F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3F);
    // 0x80085E7C: nop

    // 0x80085E80: sb          $t4, 0x158E($t5)
    MEM_B(0X158E, ctx->r13) = ctx->r12;
    // 0x80085E84: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80085E88: nop

    // 0x80085E8C: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80085E90: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80085E94: nop

    // 0x80085E98: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x80085E9C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80085EA0: nop

    // 0x80085EA4: sw          $t9, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r25;
    // 0x80085EA8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80085EAC: nop

    // 0x80085EB0: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x80085EB4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80085EB8: lw          $a0, -0x4FB0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4FB0);
    // 0x80085EBC: jal         0x800B88E0
    // 0x80085EC0: nop

    alSynAddPlayer(rdram, ctx);
        goto after_0;
    // 0x80085EC0: nop

    after_0:
    // 0x80085EC4: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80085EC8: sh          $t1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r9;
    // 0x80085ECC: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
    // 0x80085ED0: sb          $zero, 0x20($sp)
    MEM_B(0X20, ctx->r29) = 0;
    // 0x80085ED4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80085ED8:
    // 0x80085ED8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80085EDC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80085EE0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80085EE4: lw          $t3, 0x438($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X438);
    // 0x80085EE8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80085EEC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80085EF0: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80085EF4: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80085EF8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80085EFC: nop

    // 0x80085F00: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80085F04: slti        $at, $t8, 0x42
    ctx->r1 = SIGNED(ctx->r24) < 0X42 ? 1 : 0;
    // 0x80085F08: bne         $at, $zero, L_80085ED8
    if (ctx->r1 != 0) {
        // 0x80085F0C: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_80085ED8;
    }
    // 0x80085F0C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80085F10: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x80085F14: nop

    // 0x80085F18: beq         $t9, $zero, L_80085F70
    if (ctx->r25 == 0) {
        // 0x80085F1C: nop
    
            goto L_80085F70;
    }
    // 0x80085F1C: nop

    // 0x80085F20: blez        $t9, L_80085F70
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80085F24: sw          $zero, 0x24($sp)
        MEM_W(0X24, ctx->r29) = 0;
            goto L_80085F70;
    }
    // 0x80085F24: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80085F28:
    // 0x80085F28: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80085F2C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80085F30: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80085F34: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x80085F38: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80085F3C: lw          $t1, 0x43C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X43C);
    // 0x80085F40: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x80085F44: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80085F48: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x80085F4C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80085F50: jal         0x800B8A18
    // 0x80085F54: addu        $a1, $t1, $t4
    ctx->r5 = ADD32(ctx->r9, ctx->r12);
    alSynAllocVoice(rdram, ctx);
        goto after_1;
    // 0x80085F54: addu        $a1, $t1, $t4
    ctx->r5 = ADD32(ctx->r9, ctx->r12);
    after_1:
    // 0x80085F58: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80085F5C: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x80085F60: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80085F64: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80085F68: bne         $at, $zero, L_80085F28
    if (ctx->r1 != 0) {
        // 0x80085F6C: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80085F28;
    }
    // 0x80085F6C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_80085F70:
    // 0x80085F70: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085F74: jal         0x800B3BFC
    // 0x80085F78: addiu       $a0, $a0, -0x9C0
    ctx->r4 = ADD32(ctx->r4, -0X9C0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x80085F78: addiu       $a0, $a0, -0x9C0
    ctx->r4 = ADD32(ctx->r4, -0X9C0);
    after_2:
    // 0x80085F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085F80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80085F84: jr          $ra
    // 0x80085F88: nop

    return;
    // 0x80085F88: nop

;}

RECOMP_FUNC void Dcm_VoiceHandler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878F0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800878F4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800878F8: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800878FC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80087900: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80087904: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80087908: addiu       $a0, $a0, -0x7320
    ctx->r4 = ADD32(ctx->r4, -0X7320);
    // 0x8008790C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80087910: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087914: jal         0x800B3C20
    // 0x80087918: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80087918: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8008791C: bne         $v0, $zero, L_80087AC4
    if (ctx->r2 != 0) {
        // 0x80087920: nop
    
            goto L_80087AC4;
    }
    // 0x80087920: nop

    // 0x80087924: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80087928: nop

    // 0x8008792C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80087930: nop

    // 0x80087934: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x80087938: lh          $s0, 0x0($t7)
    ctx->r16 = MEM_H(ctx->r15, 0X0);
    // 0x8008793C: nop

    // 0x80087940: beq         $s0, $zero, L_80087960
    if (ctx->r16 == 0) {
        // 0x80087944: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80087960;
    }
    // 0x80087944: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80087948: beq         $s0, $at, L_80087A2C
    if (ctx->r16 == ctx->r1) {
        // 0x8008794C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80087A2C;
    }
    // 0x8008794C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80087950: beq         $s0, $at, L_80087A5C
    if (ctx->r16 == ctx->r1) {
        // 0x80087954: nop
    
            goto L_80087A5C;
    }
    // 0x80087954: nop

    // 0x80087958: b           L_80087AB8
    // 0x8008795C: nop

        goto L_80087AB8;
    // 0x8008795C: nop

L_80087960:
    // 0x80087960: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80087964: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80087968: lw          $t0, 0x440($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X440);
    // 0x8008796C: nop

    // 0x80087970: blez        $t0, L_800879EC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80087974: nop
    
            goto L_800879EC;
    }
    // 0x80087974: nop

L_80087978:
    // 0x80087978: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8008797C: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80087980: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80087984: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80087988: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008798C: lw          $t2, 0x43C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X43C);
    // 0x80087990: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80087994: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80087998: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8008799C: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x800879A0: lbu         $t6, 0x27($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X27);
    // 0x800879A4: nop

    // 0x800879A8: beq         $t6, $zero, L_800879C8
    if (ctx->r14 == 0) {
        // 0x800879AC: nop
    
            goto L_800879C8;
    }
    // 0x800879AC: nop

    // 0x800879B0: sb          $zero, 0x27($t5)
    MEM_B(0X27, ctx->r13) = 0;
    // 0x800879B4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800879B8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800879BC: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x800879C0: jal         0x800B8B60
    // 0x800879C4: nop

    alSynStopVoice(rdram, ctx);
        goto after_1;
    // 0x800879C4: nop

    after_1:
L_800879C8:
    // 0x800879C8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800879CC: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800879D0: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800879D4: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800879D8: lw          $t1, 0x440($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X440);
    // 0x800879DC: nop

    // 0x800879E0: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800879E4: bne         $at, $zero, L_80087978
    if (ctx->r1 != 0) {
        // 0x800879E8: nop
    
            goto L_80087978;
    }
    // 0x800879E8: nop

L_800879EC:
    // 0x800879EC: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800879F0: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800879F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800879F8: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x800879FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087A00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087A04: jal         0x800B34D0
    // 0x80087A08: sb          $t3, 0x454($t2)
    MEM_B(0X454, ctx->r10) = ctx->r11;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80087A08: sb          $t3, 0x454($t2)
    MEM_B(0X454, ctx->r10) = ctx->r11;
    after_2:
    // 0x80087A0C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80087A10: nop

    // 0x80087A14: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
    // 0x80087A18: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80087A1C: nop

    // 0x80087A20: lw          $v0, 0x1578($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1578);
    // 0x80087A24: b           L_80088B94
    // 0x80087A28: nop

        goto L_80088B94;
    // 0x80087A28: nop

L_80087A2C:
    // 0x80087A2C: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80087A30: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80087A34: sb          $t5, 0x454($t8)
    MEM_B(0X454, ctx->r24) = ctx->r13;
    // 0x80087A38: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80087A3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80087A40: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x80087A44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087A48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087A4C: jal         0x800B34D0
    // 0x80087A50: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80087A50: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    after_3:
    // 0x80087A54: b           L_80087AC4
    // 0x80087A58: nop

        goto L_80087AC4;
    // 0x80087A58: nop

L_80087A5C:
    // 0x80087A5C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80087A60: nop

    // 0x80087A64: sb          $zero, 0x1586($t0)
    MEM_B(0X1586, ctx->r8) = 0;
    // 0x80087A68: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80087A6C: nop

    // 0x80087A70: lw          $a0, 0x444($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X444);
    // 0x80087A74: jal         0x8008EFA0
    // 0x80087A78: addiu       $a1, $t9, 0x458
    ctx->r5 = ADD32(ctx->r25, 0X458);
    Dcm_InitDecoder(rdram, ctx);
        goto after_4;
    // 0x80087A78: addiu       $a1, $t9, 0x458
    ctx->r5 = ADD32(ctx->r25, 0X458);
    after_4:
    // 0x80087A7C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80087A80: jal         0x8008756C
    // 0x80087A84: nop

    Audio2_FillDecodeBuffer(rdram, ctx);
        goto after_5;
    // 0x80087A84: nop

    after_5:
    // 0x80087A88: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80087A8C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80087A90: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x80087A94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087A98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087A9C: jal         0x800B34D0
    // 0x80087AA0: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80087AA0: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    after_6:
    // 0x80087AA4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80087AA8: nop

    // 0x80087AAC: lw          $v0, 0x1578($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X1578);
    // 0x80087AB0: b           L_80088B94
    // 0x80087AB4: nop

        goto L_80088B94;
    // 0x80087AB4: nop

L_80087AB8:
    // 0x80087AB8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80087ABC: nop

    // 0x80087AC0: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
L_80087AC4:
    // 0x80087AC4: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80087AC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80087ACC: lbu         $t6, 0x454($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X454);
    // 0x80087AD0: nop

    // 0x80087AD4: bne         $t6, $at, L_80087AE8
    if (ctx->r14 != ctx->r1) {
        // 0x80087AD8: nop
    
            goto L_80087AE8;
    }
    // 0x80087AD8: nop

    // 0x80087ADC: lw          $v0, 0x1578($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X1578);
    // 0x80087AE0: b           L_80088B94
    // 0x80087AE4: nop

        goto L_80088B94;
    // 0x80087AE4: nop

L_80087AE8:
    // 0x80087AE8: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80087AEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80087AF0: lbu         $t8, 0x454($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X454);
    // 0x80087AF4: nop

    // 0x80087AF8: bne         $t8, $at, L_80088B84
    if (ctx->r24 != ctx->r1) {
        // 0x80087AFC: nop
    
            goto L_80088B84;
    }
    // 0x80087AFC: nop

    // 0x80087B00: lw          $t7, 0x156C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X156C);
    // 0x80087B04: lw          $t0, 0x450($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X450);
    // 0x80087B08: nop

    // 0x80087B0C: sltu        $at, $t7, $t0
    ctx->r1 = ctx->r15 < ctx->r8 ? 1 : 0;
    // 0x80087B10: bne         $at, $zero, L_80087C40
    if (ctx->r1 != 0) {
        // 0x80087B14: nop
    
            goto L_80087C40;
    }
    // 0x80087B14: nop

    // 0x80087B18: lbu         $t9, 0x158E($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X158E);
    // 0x80087B1C: nop

    // 0x80087B20: beq         $t9, $zero, L_80087C20
    if (ctx->r25 == 0) {
        // 0x80087B24: nop
    
            goto L_80087C20;
    }
    // 0x80087B24: nop

    // 0x80087B28: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80087B2C: lw          $a1, -0x7224($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7224);
    // 0x80087B30: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087B34: lhu         $a2, 0x1580($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X1580);
    // 0x80087B38: jal         0x800B3BFC
    // 0x80087B3C: addiu       $a0, $a0, -0x794
    ctx->r4 = ADD32(ctx->r4, -0X794);
    rmonPrintf_recomp(rdram, ctx);
        goto after_7;
    // 0x80087B3C: addiu       $a0, $a0, -0x794
    ctx->r4 = ADD32(ctx->r4, -0X794);
    after_7:
    // 0x80087B40: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80087B44: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80087B48: lw          $t3, 0x440($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X440);
    // 0x80087B4C: nop

    // 0x80087B50: blez        $t3, L_80087BD8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80087B54: nop
    
            goto L_80087BD8;
    }
    // 0x80087B54: nop

L_80087B58:
    // 0x80087B58: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80087B5C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80087B60: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80087B64: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x80087B68: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80087B6C: lw          $t6, 0x43C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X43C);
    // 0x80087B70: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x80087B74: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80087B78: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80087B7C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80087B80: lbu         $t0, 0x27($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X27);
    // 0x80087B84: nop

    // 0x80087B88: beq         $t0, $zero, L_80087BA8
    if (ctx->r8 == 0) {
        // 0x80087B8C: nop
    
            goto L_80087BA8;
    }
    // 0x80087B8C: nop

    // 0x80087B90: sb          $zero, 0x27($t7)
    MEM_B(0X27, ctx->r15) = 0;
    // 0x80087B94: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80087B98: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80087B9C: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    // 0x80087BA0: jal         0x800B8B60
    // 0x80087BA4: nop

    alSynStopVoice(rdram, ctx);
        goto after_8;
    // 0x80087BA4: nop

    after_8:
L_80087BA8:
    // 0x80087BA8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80087BAC: nop

    // 0x80087BB0: sh          $zero, 0x14($t5)
    MEM_H(0X14, ctx->r13) = 0;
    // 0x80087BB4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80087BB8: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80087BBC: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80087BC0: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x80087BC4: lw          $t4, 0x440($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X440);
    // 0x80087BC8: nop

    // 0x80087BCC: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80087BD0: bne         $at, $zero, L_80087B58
    if (ctx->r1 != 0) {
        // 0x80087BD4: nop
    
            goto L_80087B58;
    }
    // 0x80087BD4: nop

L_80087BD8:
    // 0x80087BD8: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80087BDC: nop

    // 0x80087BE0: lw          $t8, 0x448($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X448);
    // 0x80087BE4: nop

    // 0x80087BE8: sw          $t8, 0x444($t6)
    MEM_W(0X444, ctx->r14) = ctx->r24;
    // 0x80087BEC: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80087BF0: nop

    // 0x80087BF4: lw          $a0, 0x444($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X444);
    // 0x80087BF8: jal         0x8008EFA0
    // 0x80087BFC: addiu       $a1, $t0, 0x458
    ctx->r5 = ADD32(ctx->r8, 0X458);
    Dcm_InitDecoder(rdram, ctx);
        goto after_9;
    // 0x80087BFC: addiu       $a1, $t0, 0x458
    ctx->r5 = ADD32(ctx->r8, 0X458);
    after_9:
    // 0x80087C00: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80087C04: jal         0x8008756C
    // 0x80087C08: nop

    Audio2_FillDecodeBuffer(rdram, ctx);
        goto after_10;
    // 0x80087C08: nop

    after_10:
    // 0x80087C0C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80087C10: nop

    // 0x80087C14: lw          $v0, 0x1578($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X1578);
    // 0x80087C18: b           L_80088B94
    // 0x80087C1C: nop

        goto L_80088B94;
    // 0x80087C1C: nop

L_80087C20:
    // 0x80087C20: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80087C24: nop

    // 0x80087C28: sb          $zero, 0x454($t9)
    MEM_B(0X454, ctx->r25) = 0;
    // 0x80087C2C: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80087C30: nop

    // 0x80087C34: lw          $v0, 0x1578($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X1578);
    // 0x80087C38: b           L_80088B94
    // 0x80087C3C: nop

        goto L_80088B94;
    // 0x80087C3C: nop

L_80087C40:
    // 0x80087C40: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80087C44: jal         0x800874AC
    // 0x80087C48: nop

    Audio2_RefillDecodeBuffer(rdram, ctx);
        goto after_11;
    // 0x80087C48: nop

    after_11:
    // 0x80087C4C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80087C50: nop

    // 0x80087C54: lbu         $t2, 0x1587($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1587);
    // 0x80087C58: nop

    // 0x80087C5C: beq         $t2, $zero, L_80087DE8
    if (ctx->r10 == 0) {
        // 0x80087C60: nop
    
            goto L_80087DE8;
    }
    // 0x80087C60: nop

    // 0x80087C64: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80087C68: lw          $t3, 0x440($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X440);
    // 0x80087C6C: nop

    // 0x80087C70: blez        $t3, L_80087DDC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80087C74: nop
    
            goto L_80087DDC;
    }
    // 0x80087C74: nop

L_80087C78:
    // 0x80087C78: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80087C7C: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80087C80: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80087C84: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x80087C88: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80087C8C: lw          $t8, 0x43C($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X43C);
    // 0x80087C90: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x80087C94: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80087C98: addu        $t7, $t8, $t0
    ctx->r15 = ADD32(ctx->r24, ctx->r8);
    // 0x80087C9C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80087CA0: lbu         $t9, 0x27($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X27);
    // 0x80087CA4: nop

    // 0x80087CA8: beq         $t9, $zero, L_80087DB8
    if (ctx->r25 == 0) {
        // 0x80087CAC: nop
    
            goto L_80087DB8;
    }
    // 0x80087CAC: nop

    // 0x80087CB0: lh          $t5, 0x28($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X28);
    // 0x80087CB4: nop

    // 0x80087CB8: bne         $t5, $zero, L_80087CC8
    if (ctx->r13 != 0) {
        // 0x80087CBC: nop
    
            goto L_80087CC8;
    }
    // 0x80087CBC: nop

    // 0x80087CC0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80087CC4: sh          $t2, 0x28($t7)
    MEM_H(0X28, ctx->r15) = ctx->r10;
L_80087CC8:
    // 0x80087CC8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80087CCC: nop

    // 0x80087CD0: lh          $t3, 0x28($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X28);
    // 0x80087CD4: nop

    // 0x80087CD8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80087CDC: jal         0x800B8340
    // 0x80087CE0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    sqrtf_recomp(rdram, ctx);
        goto after_12;
    // 0x80087CE0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_12:
    // 0x80087CE4: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80087CE8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80087CEC: lh          $t6, 0x157C($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X157C);
    // 0x80087CF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80087CF4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80087CF8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80087CFC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80087D00: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80087D04: nop

    // 0x80087D08: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80087D0C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80087D10: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80087D14: nop

    // 0x80087D18: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80087D1C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80087D20: nop

    // 0x80087D24: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x80087D28: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80087D2C: beq         $t0, $zero, L_80087D7C
    if (ctx->r8 == 0) {
        // 0x80087D30: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80087D7C;
    }
    // 0x80087D30: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80087D34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80087D38: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80087D3C: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80087D40: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80087D44: nop

    // 0x80087D48: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80087D4C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80087D50: nop

    // 0x80087D54: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x80087D58: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80087D5C: bne         $t0, $zero, L_80087D74
    if (ctx->r8 != 0) {
        // 0x80087D60: nop
    
            goto L_80087D74;
    }
    // 0x80087D60: nop

    // 0x80087D64: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80087D68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80087D6C: b           L_80087D8C
    // 0x80087D70: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80087D8C;
    // 0x80087D70: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80087D74:
    // 0x80087D74: b           L_80087D8C
    // 0x80087D78: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80087D8C;
    // 0x80087D78: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_80087D7C:
    // 0x80087D7C: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80087D80: nop

    // 0x80087D84: bltz        $t0, L_80087D74
    if (SIGNED(ctx->r8) < 0) {
        // 0x80087D88: nop
    
            goto L_80087D74;
    }
    // 0x80087D88: nop

L_80087D8C:
    // 0x80087D8C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80087D90: andi        $t9, $t0, 0xFFFF
    ctx->r25 = ctx->r8 & 0XFFFF;
    // 0x80087D94: sh          $t9, 0x24($t5)
    MEM_H(0X24, ctx->r13) = ctx->r25;
    // 0x80087D98: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80087D9C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80087DA0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80087DA4: lh          $a2, 0x24($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X24);
    // 0x80087DA8: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x80087DAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80087DB0: jal         0x8008E5A0
    // 0x80087DB4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    alSynSetVol(rdram, ctx);
        goto after_13;
    // 0x80087DB4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_13:
L_80087DB8:
    // 0x80087DB8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80087DBC: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80087DC0: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80087DC4: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x80087DC8: lw          $t6, 0x440($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X440);
    // 0x80087DCC: nop

    // 0x80087DD0: slt         $at, $t3, $t6
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80087DD4: bne         $at, $zero, L_80087C78
    if (ctx->r1 != 0) {
        // 0x80087DD8: nop
    
            goto L_80087C78;
    }
    // 0x80087DD8: nop

L_80087DDC:
    // 0x80087DDC: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80087DE0: nop

    // 0x80087DE4: sb          $zero, 0x1587($t8)
    MEM_B(0X1587, ctx->r24) = 0;
L_80087DE8:
    // 0x80087DE8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80087DEC: nop

    // 0x80087DF0: lbu         $t9, 0x158C($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X158C);
    // 0x80087DF4: nop

    // 0x80087DF8: beq         $t9, $zero, L_80087EA0
    if (ctx->r25 == 0) {
        // 0x80087DFC: nop
    
            goto L_80087EA0;
    }
    // 0x80087DFC: nop

    // 0x80087E00: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80087E04: lw          $t5, 0x440($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X440);
    // 0x80087E08: nop

    // 0x80087E0C: blez        $t5, L_80087E94
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80087E10: nop
    
            goto L_80087E94;
    }
    // 0x80087E10: nop

L_80087E14:
    // 0x80087E14: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80087E18: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80087E1C: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x80087E20: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x80087E24: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80087E28: lw          $t7, 0x43C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X43C);
    // 0x80087E2C: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x80087E30: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80087E34: addu        $t3, $t7, $t4
    ctx->r11 = ADD32(ctx->r15, ctx->r12);
    // 0x80087E38: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x80087E3C: lbu         $t6, 0x27($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X27);
    // 0x80087E40: nop

    // 0x80087E44: beq         $t6, $zero, L_80087E70
    if (ctx->r14 == 0) {
        // 0x80087E48: nop
    
            goto L_80087E70;
    }
    // 0x80087E48: nop

    // 0x80087E4C: lb          $t8, 0x158D($t2)
    ctx->r24 = MEM_B(ctx->r10, 0X158D);
    // 0x80087E50: nop

    // 0x80087E54: sb          $t8, 0x26($t3)
    MEM_B(0X26, ctx->r11) = ctx->r24;
    // 0x80087E58: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80087E5C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80087E60: lb          $a2, 0x26($t0)
    ctx->r6 = MEM_B(ctx->r8, 0X26);
    // 0x80087E64: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    // 0x80087E68: jal         0x800B8D30
    // 0x80087E6C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    alSynSetPan(rdram, ctx);
        goto after_14;
    // 0x80087E6C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_14:
L_80087E70:
    // 0x80087E70: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80087E74: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80087E78: addiu       $t1, $t5, 0x1
    ctx->r9 = ADD32(ctx->r13, 0X1);
    // 0x80087E7C: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80087E80: lw          $t4, 0x440($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X440);
    // 0x80087E84: nop

    // 0x80087E88: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80087E8C: bne         $at, $zero, L_80087E14
    if (ctx->r1 != 0) {
        // 0x80087E90: nop
    
            goto L_80087E14;
    }
    // 0x80087E90: nop

L_80087E94:
    // 0x80087E94: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80087E98: nop

    // 0x80087E9C: sb          $zero, 0x158C($t6)
    MEM_B(0X158C, ctx->r14) = 0;
L_80087EA0:
    // 0x80087EA0: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80087EA4: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80087EA8: lw          $t8, 0x440($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X440);
    // 0x80087EAC: nop

    // 0x80087EB0: blez        $t8, L_80088B84
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80087EB4: nop
    
            goto L_80088B84;
    }
    // 0x80087EB4: nop

L_80087EB8:
    // 0x80087EB8: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80087EBC: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80087EC0: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x80087EC4: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x80087EC8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80087ECC: lw          $t9, 0x43C($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X43C);
    // 0x80087ED0: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x80087ED4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80087ED8: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x80087EDC: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80087EE0: lbu         $t1, 0x1586($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X1586);
    // 0x80087EE4: nop

    // 0x80087EE8: beq         $t1, $zero, L_80087EFC
    if (ctx->r9 == 0) {
        // 0x80087EEC: nop
    
            goto L_80087EFC;
    }
    // 0x80087EEC: nop

    // 0x80087EF0: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x80087EF4: b           L_80088B60
    // 0x80087EF8: sb          $t4, 0x1586($t3)
    MEM_B(0X1586, ctx->r11) = ctx->r12;
        goto L_80088B60;
    // 0x80087EF8: sb          $t4, 0x1586($t3)
    MEM_B(0X1586, ctx->r11) = ctx->r12;
L_80087EFC:
    // 0x80087EFC: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80087F00: nop

    // 0x80087F04: lhu         $t2, 0x1568($t6)
    ctx->r10 = MEM_HU(ctx->r14, 0X1568);
    // 0x80087F08: nop

    // 0x80087F0C: andi        $t8, $t2, 0xFF
    ctx->r24 = ctx->r10 & 0XFF;
    // 0x80087F10: andi        $t0, $t8, 0xFF
    ctx->r8 = ctx->r24 & 0XFF;
    // 0x80087F14: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x80087F18: lbu         $t5, 0x1468($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X1468);
    // 0x80087F1C: nop

    // 0x80087F20: sb          $t5, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r13;
    // 0x80087F24: lhu         $t7, 0x1568($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X1568);
    // 0x80087F28: nop

    // 0x80087F2C: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x80087F30: sh          $t1, 0x1568($t6)
    MEM_H(0X1568, ctx->r14) = ctx->r9;
    // 0x80087F34: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80087F38: nop

    // 0x80087F3C: lw          $t3, 0x156C($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X156C);
    // 0x80087F40: nop

    // 0x80087F44: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x80087F48: sw          $t2, 0x156C($t4)
    MEM_W(0X156C, ctx->r12) = ctx->r10;
    // 0x80087F4C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80087F50: nop

    // 0x80087F54: lbu         $t0, 0x1598($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X1598);
    // 0x80087F58: nop

    // 0x80087F5C: bne         $t0, $zero, L_80087F70
    if (ctx->r8 != 0) {
        // 0x80087F60: nop
    
            goto L_80087F70;
    }
    // 0x80087F60: nop

    // 0x80087F64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80087F68: jal         0x800B6650
    // 0x80087F6C: sb          $t9, 0x1598($t8)
    MEM_B(0X1598, ctx->r24) = ctx->r25;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_15;
    // 0x80087F6C: sb          $t9, 0x1598($t8)
    MEM_B(0X1598, ctx->r24) = ctx->r25;
    after_15:
L_80087F70:
    // 0x80087F70: lbu         $t5, 0x57($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X57);
    // 0x80087F74: nop

    // 0x80087F78: andi        $t7, $t5, 0x80
    ctx->r15 = ctx->r13 & 0X80;
    // 0x80087F7C: beq         $t7, $zero, L_80087F94
    if (ctx->r15 == 0) {
        // 0x80087F80: nop
    
            goto L_80087F94;
    }
    // 0x80087F80: nop

    // 0x80087F84: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80087F88: andi        $t1, $t5, 0x7F
    ctx->r9 = ctx->r13 & 0X7F;
    // 0x80087F8C: b           L_80088B60
    // 0x80087F90: sb          $t1, 0x1586($t6)
    MEM_B(0X1586, ctx->r14) = ctx->r9;
        goto L_80088B60;
    // 0x80087F90: sb          $t1, 0x1586($t6)
    MEM_B(0X1586, ctx->r14) = ctx->r9;
L_80087F94:
    // 0x80087F94: lbu         $t3, 0x57($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X57);
    // 0x80087F98: nop

    // 0x80087F9C: andi        $t2, $t3, 0x40
    ctx->r10 = ctx->r11 & 0X40;
    // 0x80087FA0: beq         $t2, $zero, L_80088060
    if (ctx->r10 == 0) {
        // 0x80087FA4: nop
    
            goto L_80088060;
    }
    // 0x80087FA4: nop

    // 0x80087FA8: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80087FAC: nop

    // 0x80087FB0: lhu         $t0, 0x1568($t4)
    ctx->r8 = MEM_HU(ctx->r12, 0X1568);
    // 0x80087FB4: nop

    // 0x80087FB8: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x80087FBC: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x80087FC0: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x80087FC4: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x80087FC8: andi        $t2, $t3, 0xFF
    ctx->r10 = ctx->r11 & 0XFF;
    // 0x80087FCC: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x80087FD0: lbu         $t1, 0x1468($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X1468);
    // 0x80087FD4: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x80087FD8: lbu         $t8, 0x1468($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X1468);
    // 0x80087FDC: sll         $t6, $t1, 8
    ctx->r14 = S32(ctx->r9 << 8);
    // 0x80087FE0: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80087FE4: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x80087FE8: lw          $t5, 0x156C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X156C);
    // 0x80087FEC: nop

    // 0x80087FF0: addiu       $t1, $t5, 0x2
    ctx->r9 = ADD32(ctx->r13, 0X2);
    // 0x80087FF4: sw          $t1, 0x156C($t4)
    MEM_W(0X156C, ctx->r12) = ctx->r9;
    // 0x80087FF8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80087FFC: nop

    // 0x80088000: lhu         $t3, 0x1568($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X1568);
    // 0x80088004: nop

    // 0x80088008: addiu       $t2, $t3, 0x2
    ctx->r10 = ADD32(ctx->r11, 0X2);
    // 0x8008800C: sh          $t2, 0x1568($t0)
    MEM_H(0X1568, ctx->r8) = ctx->r10;
    // 0x80088010: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80088014: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80088018: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8008801C: srl         $t8, $t6, 14
    ctx->r24 = S32(U32(ctx->r14) >> 14);
    // 0x80088020: sb          $t8, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r24;
    // 0x80088024: lbu         $t5, 0x43($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X43);
    // 0x80088028: andi        $t7, $t6, 0x3FFF
    ctx->r15 = ctx->r14 & 0X3FFF;
    // 0x8008802C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80088030: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x80088034: lw          $t3, 0x3B40($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3B40);
    // 0x80088038: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8008803C: sllv        $t1, $t7, $t5
    ctx->r9 = S32(ctx->r15 << (ctx->r13 & 31));
    // 0x80088040: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x80088044: addu        $t2, $t3, $t1
    ctx->r10 = ADD32(ctx->r11, ctx->r9);
    // 0x80088048: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x8008804C: jal         0x8008BE18
    // 0x80088050: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    Dcm_SetPitch(rdram, ctx);
        goto after_16;
    // 0x80088050: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_16:
    // 0x80088054: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80088058: nop

    // 0x8008805C: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
L_80088060:
    // 0x80088060: lbu         $t9, 0x57($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X57);
    // 0x80088064: nop

    // 0x80088068: andi        $t8, $t9, 0x20
    ctx->r24 = ctx->r25 & 0X20;
    // 0x8008806C: beq         $t8, $zero, L_800881D8
    if (ctx->r24 == 0) {
        // 0x80088070: nop
    
            goto L_800881D8;
    }
    // 0x80088070: nop

    // 0x80088074: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80088078: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8008807C: lhu         $t7, 0x1568($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X1568);
    // 0x80088080: nop

    // 0x80088084: andi        $t5, $t7, 0xFF
    ctx->r13 = ctx->r15 & 0XFF;
    // 0x80088088: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
    // 0x8008808C: addu        $t3, $t6, $t4
    ctx->r11 = ADD32(ctx->r14, ctx->r12);
    // 0x80088090: lbu         $t1, 0x1468($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X1468);
    // 0x80088094: nop

    // 0x80088098: sh          $t1, 0x28($t2)
    MEM_H(0X28, ctx->r10) = ctx->r9;
    // 0x8008809C: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800880A0: nop

    // 0x800880A4: lhu         $t9, 0x1568($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X1568);
    // 0x800880A8: nop

    // 0x800880AC: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x800880B0: sh          $t8, 0x1568($t0)
    MEM_H(0X1568, ctx->r8) = ctx->r24;
    // 0x800880B4: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800880B8: nop

    // 0x800880BC: lw          $t5, 0x156C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X156C);
    // 0x800880C0: nop

    // 0x800880C4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800880C8: sw          $t6, 0x156C($t7)
    MEM_W(0X156C, ctx->r15) = ctx->r14;
    // 0x800880CC: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800880D0: nop

    // 0x800880D4: lh          $t3, 0x28($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X28);
    // 0x800880D8: nop

    // 0x800880DC: andi        $t1, $t3, 0xFF
    ctx->r9 = ctx->r11 & 0XFF;
    // 0x800880E0: sh          $t1, 0x28($t4)
    MEM_H(0X28, ctx->r12) = ctx->r9;
    // 0x800880E4: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800880E8: nop

    // 0x800880EC: lh          $t9, 0x28($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X28);
    // 0x800880F0: nop

    // 0x800880F4: bne         $t9, $zero, L_80088104
    if (ctx->r25 != 0) {
        // 0x800880F8: nop
    
            goto L_80088104;
    }
    // 0x800880F8: nop

    // 0x800880FC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80088100: sh          $t8, 0x28($t2)
    MEM_H(0X28, ctx->r10) = ctx->r24;
L_80088104:
    // 0x80088104: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80088108: nop

    // 0x8008810C: lh          $t5, 0x28($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X28);
    // 0x80088110: nop

    // 0x80088114: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80088118: jal         0x800B8340
    // 0x8008811C: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    sqrtf_recomp(rdram, ctx);
        goto after_17;
    // 0x8008811C: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_17:
    // 0x80088120: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80088124: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80088128: lh          $t7, 0x157C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X157C);
    // 0x8008812C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80088130: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80088134: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80088138: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008813C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80088140: nop

    // 0x80088144: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80088148: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8008814C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80088150: nop

    // 0x80088154: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80088158: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8008815C: nop

    // 0x80088160: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80088164: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80088168: beq         $t1, $zero, L_800881B8
    if (ctx->r9 == 0) {
        // 0x8008816C: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_800881B8;
    }
    // 0x8008816C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80088170: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80088174: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80088178: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8008817C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80088180: nop

    // 0x80088184: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80088188: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8008818C: nop

    // 0x80088190: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80088194: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80088198: bne         $t1, $zero, L_800881B0
    if (ctx->r9 != 0) {
        // 0x8008819C: nop
    
            goto L_800881B0;
    }
    // 0x8008819C: nop

    // 0x800881A0: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800881A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800881A8: b           L_800881C8
    // 0x800881AC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800881C8;
    // 0x800881AC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800881B0:
    // 0x800881B0: b           L_800881C8
    // 0x800881B4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800881C8;
    // 0x800881B4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_800881B8:
    // 0x800881B8: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800881BC: nop

    // 0x800881C0: bltz        $t1, L_800881B0
    if (SIGNED(ctx->r9) < 0) {
        // 0x800881C4: nop
    
            goto L_800881B0;
    }
    // 0x800881C4: nop

L_800881C8:
    // 0x800881C8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800881CC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800881D0: andi        $t4, $t1, 0xFFFF
    ctx->r12 = ctx->r9 & 0XFFFF;
    // 0x800881D4: sh          $t4, 0x24($t9)
    MEM_H(0X24, ctx->r25) = ctx->r12;
L_800881D8:
    // 0x800881D8: lbu         $t8, 0x57($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X57);
    // 0x800881DC: nop

    // 0x800881E0: andi        $t2, $t8, 0x10
    ctx->r10 = ctx->r24 & 0X10;
    // 0x800881E4: beq         $t2, $zero, L_80088248
    if (ctx->r10 == 0) {
        // 0x800881E8: nop
    
            goto L_80088248;
    }
    // 0x800881E8: nop

    // 0x800881EC: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800881F0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800881F4: lhu         $t5, 0x1568($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0X1568);
    // 0x800881F8: nop

    // 0x800881FC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80088200: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80088204: addu        $t3, $t0, $t7
    ctx->r11 = ADD32(ctx->r8, ctx->r15);
    // 0x80088208: lbu         $t1, 0x1468($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X1468);
    // 0x8008820C: nop

    // 0x80088210: sra         $t4, $t1, 1
    ctx->r12 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80088214: sb          $t4, 0x26($t9)
    MEM_B(0X26, ctx->r25) = ctx->r12;
    // 0x80088218: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8008821C: nop

    // 0x80088220: lhu         $t2, 0x1568($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X1568);
    // 0x80088224: nop

    // 0x80088228: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x8008822C: sh          $t5, 0x1568($t8)
    MEM_H(0X1568, ctx->r24) = ctx->r13;
    // 0x80088230: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80088234: nop

    // 0x80088238: lw          $t0, 0x156C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X156C);
    // 0x8008823C: nop

    // 0x80088240: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x80088244: sw          $t7, 0x156C($t6)
    MEM_W(0X156C, ctx->r14) = ctx->r15;
L_80088248:
    // 0x80088248: lbu         $t3, 0x57($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X57);
    // 0x8008824C: nop

    // 0x80088250: andi        $t1, $t3, 0x8
    ctx->r9 = ctx->r11 & 0X8;
    // 0x80088254: beq         $t1, $zero, L_80088414
    if (ctx->r9 == 0) {
        // 0x80088258: nop
    
            goto L_80088414;
    }
    // 0x80088258: nop

    // 0x8008825C: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80088260: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088264: lhu         $t9, 0x1568($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X1568);
    // 0x80088268: nop

    // 0x8008826C: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x80088270: andi        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 & 0XFF;
    // 0x80088274: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x80088278: lbu         $t0, 0x1468($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X1468);
    // 0x8008827C: nop

    // 0x80088280: sb          $t0, 0x56($sp)
    MEM_B(0X56, ctx->r29) = ctx->r8;
    // 0x80088284: lhu         $t7, 0x1568($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X1568);
    // 0x80088288: nop

    // 0x8008828C: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80088290: sh          $t6, 0x1568($t4)
    MEM_H(0X1568, ctx->r12) = ctx->r14;
    // 0x80088294: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80088298: nop

    // 0x8008829C: lw          $t1, 0x156C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X156C);
    // 0x800882A0: nop

    // 0x800882A4: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x800882A8: sw          $t9, 0x156C($t3)
    MEM_W(0X156C, ctx->r11) = ctx->r25;
    // 0x800882AC: lbu         $t8, 0x56($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X56);
    // 0x800882B0: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800882B4: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800882B8: lw          $t5, 0x438($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X438);
    // 0x800882BC: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800882C0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800882C4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800882C8: addu        $t7, $t5, $t0
    ctx->r15 = ADD32(ctx->r13, ctx->r8);
    // 0x800882CC: sw          $t7, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r15;
    // 0x800882D0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800882D4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800882D8: lbu         $t4, 0x56($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X56);
    // 0x800882DC: addu        $t3, $t1, $t9
    ctx->r11 = ADD32(ctx->r9, ctx->r25);
    // 0x800882E0: sb          $t4, 0x428($t3)
    MEM_B(0X428, ctx->r11) = ctx->r12;
    // 0x800882E4: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800882E8: nop

    // 0x800882EC: lbu         $t8, 0x27($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X27);
    // 0x800882F0: nop

    // 0x800882F4: bne         $t8, $at, L_80088414
    if (ctx->r24 != ctx->r1) {
        // 0x800882F8: nop
    
            goto L_80088414;
    }
    // 0x800882F8: nop

    // 0x800882FC: lw          $t5, 0x8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8);
    // 0x80088300: nop

    // 0x80088304: beq         $t5, $zero, L_80088414
    if (ctx->r13 == 0) {
        // 0x80088308: nop
    
            goto L_80088414;
    }
    // 0x80088308: nop

    // 0x8008830C: lw          $t0, 0xC($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC);
    // 0x80088310: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x80088314: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80088318: lw          $t6, 0x8($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X8);
    // 0x8008831C: jal         0x8008ED04
    // 0x80088320: sw          $t7, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = ctx->r15;
    __allocParam(rdram, ctx);
        goto after_18;
    // 0x80088320: sw          $t7, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = ctx->r15;
    after_18:
    // 0x80088324: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80088328: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8008832C: nop

    // 0x80088330: beq         $t1, $zero, L_800883A4
    if (ctx->r9 == 0) {
        // 0x80088334: nop
    
            goto L_800883A4;
    }
    // 0x80088334: nop

    // 0x80088338: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8008833C: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x80088340: lw          $t4, 0x14($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X14);
    // 0x80088344: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80088348: lw          $t3, 0x1C($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X1C);
    // 0x8008834C: nop

    // 0x80088350: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80088354: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80088358: nop

    // 0x8008835C: sh          $t8, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r24;
    // 0x80088360: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80088364: nop

    // 0x80088368: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x8008836C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80088370: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80088374: lw          $t7, 0x8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X8);
    // 0x80088378: nop

    // 0x8008837C: lw          $t6, 0xD8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XD8);
    // 0x80088380: nop

    // 0x80088384: addiu       $t9, $t6, -0x40
    ctx->r25 = ADD32(ctx->r14, -0X40);
    // 0x80088388: sw          $t9, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r25;
    // 0x8008838C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80088390: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80088394: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x80088398: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8008839C: jalr        $t9
    // 0x800883A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_19;
    // 0x800883A0: nop

    after_19:
L_800883A4:
    // 0x800883A4: jal         0x8008ED04
    // 0x800883A8: nop

    __allocParam(rdram, ctx);
        goto after_20;
    // 0x800883A8: nop

    after_20:
    // 0x800883AC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800883B0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800883B4: nop

    // 0x800883B8: beq         $t1, $zero, L_80088414
    if (ctx->r9 == 0) {
        // 0x800883BC: nop
    
            goto L_80088414;
    }
    // 0x800883BC: nop

    // 0x800883C0: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800883C4: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800883C8: lw          $t5, 0x14($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X14);
    // 0x800883CC: lw          $t7, 0x8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X8);
    // 0x800883D0: lw          $t0, 0x1C($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X1C);
    // 0x800883D4: lw          $t6, 0xD8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XD8);
    // 0x800883D8: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x800883DC: addu        $t4, $t0, $t6
    ctx->r12 = ADD32(ctx->r8, ctx->r14);
    // 0x800883E0: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x800883E4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800883E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800883EC: sh          $t3, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r11;
    // 0x800883F0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800883F4: nop

    // 0x800883F8: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800883FC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80088400: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80088404: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x80088408: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8008840C: jalr        $t9
    // 0x80088410: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_21;
    // 0x80088410: nop

    after_21:
L_80088414:
    // 0x80088414: lbu         $t2, 0x57($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X57);
    // 0x80088418: nop

    // 0x8008841C: andi        $t7, $t2, 0x4
    ctx->r15 = ctx->r10 & 0X4;
    // 0x80088420: beq         $t7, $zero, L_8008861C
    if (ctx->r15 == 0) {
        // 0x80088424: nop
    
            goto L_8008861C;
    }
    // 0x80088424: nop

    // 0x80088428: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8008842C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088430: lhu         $t6, 0x1568($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X1568);
    // 0x80088434: nop

    // 0x80088438: andi        $t4, $t6, 0xFF
    ctx->r12 = ctx->r14 & 0XFF;
    // 0x8008843C: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80088440: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x80088444: lbu         $t8, 0x1468($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X1468);
    // 0x80088448: nop

    // 0x8008844C: sll         $t5, $t8, 8
    ctx->r13 = S32(ctx->r24 << 8);
    // 0x80088450: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x80088454: lhu         $t9, 0x1568($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X1568);
    // 0x80088458: nop

    // 0x8008845C: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80088460: sh          $t2, 0x1568($t0)
    MEM_H(0X1568, ctx->r8) = ctx->r10;
    // 0x80088464: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80088468: nop

    // 0x8008846C: lw          $t6, 0x156C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X156C);
    // 0x80088470: nop

    // 0x80088474: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x80088478: sw          $t4, 0x156C($t7)
    MEM_W(0X156C, ctx->r15) = ctx->r12;
    // 0x8008847C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80088480: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80088484: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80088488: addu        $t8, $t1, $t3
    ctx->r24 = ADD32(ctx->r9, ctx->r11);
    // 0x8008848C: lbu         $t5, 0x428($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X428);
    // 0x80088490: lw          $t2, 0x438($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X438);
    // 0x80088494: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80088498: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8008849C: addu        $t0, $t2, $t9
    ctx->r8 = ADD32(ctx->r10, ctx->r25);
    // 0x800884A0: lw          $t6, 0x528($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X528);
    // 0x800884A4: lw          $t8, 0x1C($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X1C);
    // 0x800884A8: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x800884AC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800884B0: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800884B4: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800884B8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800884BC: addu        $t2, $t5, $t1
    ctx->r10 = ADD32(ctx->r13, ctx->r9);
    // 0x800884C0: lbu         $t9, 0x428($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X428);
    // 0x800884C4: lw          $t6, 0x438($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X438);
    // 0x800884C8: lw          $t1, 0x1C($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X1C);
    // 0x800884CC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800884D0: addu        $t4, $t6, $t0
    ctx->r12 = ADD32(ctx->r14, ctx->r8);
    // 0x800884D4: lw          $t7, 0x528($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X528);
    // 0x800884D8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800884DC: lw          $t3, 0x630($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X630);
    // 0x800884E0: subu        $t9, $t2, $t7
    ctx->r25 = SUB32(ctx->r10, ctx->r15);
    // 0x800884E4: subu        $t5, $t3, $t9
    ctx->r13 = SUB32(ctx->r11, ctx->r25);
    // 0x800884E8: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800884EC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800884F0: nop

    // 0x800884F4: lbu         $t0, 0x27($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X27);
    // 0x800884F8: nop

    // 0x800884FC: bne         $t0, $at, L_8008861C
    if (ctx->r8 != ctx->r1) {
        // 0x80088500: nop
    
            goto L_8008861C;
    }
    // 0x80088500: nop

    // 0x80088504: lw          $t4, 0x8($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X8);
    // 0x80088508: nop

    // 0x8008850C: beq         $t4, $zero, L_8008861C
    if (ctx->r12 == 0) {
        // 0x80088510: nop
    
            goto L_8008861C;
    }
    // 0x80088510: nop

    // 0x80088514: lw          $t8, 0xC($t4)
    ctx->r24 = MEM_W(ctx->r12, 0XC);
    // 0x80088518: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
    // 0x8008851C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80088520: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80088524: jal         0x8008ED04
    // 0x80088528: sw          $t2, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = ctx->r10;
    __allocParam(rdram, ctx);
        goto after_22;
    // 0x80088528: sw          $t2, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = ctx->r10;
    after_22:
    // 0x8008852C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80088530: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80088534: nop

    // 0x80088538: beq         $t3, $zero, L_800885AC
    if (ctx->r11 == 0) {
        // 0x8008853C: nop
    
            goto L_800885AC;
    }
    // 0x8008853C: nop

    // 0x80088540: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80088544: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x80088548: lw          $t5, 0x14($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X14);
    // 0x8008854C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80088550: lw          $t1, 0x1C($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X1C);
    // 0x80088554: nop

    // 0x80088558: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x8008855C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80088560: nop

    // 0x80088564: sh          $t0, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r8;
    // 0x80088568: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8008856C: nop

    // 0x80088570: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    // 0x80088574: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80088578: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8008857C: lw          $t2, 0x8($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X8);
    // 0x80088580: nop

    // 0x80088584: lw          $t7, 0xD8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0XD8);
    // 0x80088588: nop

    // 0x8008858C: addiu       $t9, $t7, -0x40
    ctx->r25 = ADD32(ctx->r15, -0X40);
    // 0x80088590: sw          $t9, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r25;
    // 0x80088594: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80088598: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8008859C: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x800885A0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800885A4: jalr        $t9
    // 0x800885A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_23;
    // 0x800885A8: nop

    after_23:
L_800885AC:
    // 0x800885AC: jal         0x8008ED04
    // 0x800885B0: nop

    __allocParam(rdram, ctx);
        goto after_24;
    // 0x800885B0: nop

    after_24:
    // 0x800885B4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800885B8: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800885BC: nop

    // 0x800885C0: beq         $t3, $zero, L_8008861C
    if (ctx->r11 == 0) {
        // 0x800885C4: nop
    
            goto L_8008861C;
    }
    // 0x800885C4: nop

    // 0x800885C8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800885CC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800885D0: lw          $t4, 0x14($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X14);
    // 0x800885D4: lw          $t2, 0x8($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X8);
    // 0x800885D8: lw          $t8, 0x1C($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X1C);
    // 0x800885DC: lw          $t7, 0xD8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0XD8);
    // 0x800885E0: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x800885E4: addu        $t5, $t8, $t7
    ctx->r13 = ADD32(ctx->r24, ctx->r15);
    // 0x800885E8: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800885EC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800885F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800885F4: sh          $t1, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r9;
    // 0x800885F8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800885FC: nop

    // 0x80088600: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80088604: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80088608: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8008860C: lw          $t9, 0x8($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X8);
    // 0x80088610: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80088614: jalr        $t9
    // 0x80088618: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_25;
    // 0x80088618: nop

    after_25:
L_8008861C:
    // 0x8008861C: lbu         $t6, 0x57($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X57);
    // 0x80088620: nop

    // 0x80088624: andi        $t2, $t6, 0x2
    ctx->r10 = ctx->r14 & 0X2;
    // 0x80088628: beq         $t2, $zero, L_80088820
    if (ctx->r10 == 0) {
        // 0x8008862C: nop
    
            goto L_80088820;
    }
    // 0x8008862C: nop

    // 0x80088630: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80088634: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088638: lbu         $t7, 0x27($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X27);
    // 0x8008863C: nop

    // 0x80088640: bne         $t7, $at, L_80088760
    if (ctx->r15 != ctx->r1) {
        // 0x80088644: nop
    
            goto L_80088760;
    }
    // 0x80088644: nop

    // 0x80088648: lw          $t5, 0x8($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X8);
    // 0x8008864C: nop

    // 0x80088650: beq         $t5, $zero, L_80088760
    if (ctx->r13 == 0) {
        // 0x80088654: nop
    
            goto L_80088760;
    }
    // 0x80088654: nop

    // 0x80088658: lw          $t3, 0xC($t5)
    ctx->r11 = MEM_W(ctx->r13, 0XC);
    // 0x8008865C: addiu       $t1, $zero, 0x140
    ctx->r9 = ADD32(0, 0X140);
    // 0x80088660: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80088664: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80088668: jal         0x8008ED04
    // 0x8008866C: sw          $t1, 0xD8($t0)
    MEM_W(0XD8, ctx->r8) = ctx->r9;
    __allocParam(rdram, ctx);
        goto after_26;
    // 0x8008866C: sw          $t1, 0xD8($t0)
    MEM_W(0XD8, ctx->r8) = ctx->r9;
    after_26:
    // 0x80088670: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80088674: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80088678: nop

    // 0x8008867C: beq         $t4, $zero, L_800886F0
    if (ctx->r12 == 0) {
        // 0x80088680: nop
    
            goto L_800886F0;
    }
    // 0x80088680: nop

    // 0x80088684: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80088688: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8008868C: lw          $t6, 0x14($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X14);
    // 0x80088690: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80088694: lw          $t2, 0x1C($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X1C);
    // 0x80088698: nop

    // 0x8008869C: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800886A0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800886A4: nop

    // 0x800886A8: sh          $t7, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r15;
    // 0x800886AC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800886B0: nop

    // 0x800886B4: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
    // 0x800886B8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800886BC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800886C0: lw          $t1, 0x8($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X8);
    // 0x800886C4: nop

    // 0x800886C8: lw          $t0, 0xD8($t1)
    ctx->r8 = MEM_W(ctx->r9, 0XD8);
    // 0x800886CC: nop

    // 0x800886D0: addiu       $t9, $t0, -0x40
    ctx->r25 = ADD32(ctx->r8, -0X40);
    // 0x800886D4: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x800886D8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800886DC: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800886E0: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x800886E4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800886E8: jalr        $t9
    // 0x800886EC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_27;
    // 0x800886EC: nop

    after_27:
L_800886F0:
    // 0x800886F0: jal         0x8008ED04
    // 0x800886F4: nop

    __allocParam(rdram, ctx);
        goto after_28;
    // 0x800886F4: nop

    after_28:
    // 0x800886F8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800886FC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80088700: nop

    // 0x80088704: beq         $t4, $zero, L_80088760
    if (ctx->r12 == 0) {
        // 0x80088708: nop
    
            goto L_80088760;
    }
    // 0x80088708: nop

    // 0x8008870C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80088710: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80088714: lw          $t5, 0x14($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X14);
    // 0x80088718: lw          $t1, 0x8($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X8);
    // 0x8008871C: lw          $t3, 0x1C($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X1C);
    // 0x80088720: lw          $t0, 0xD8($t1)
    ctx->r8 = MEM_W(ctx->r9, 0XD8);
    // 0x80088724: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x80088728: addu        $t6, $t3, $t0
    ctx->r14 = ADD32(ctx->r11, ctx->r8);
    // 0x8008872C: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80088730: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80088734: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80088738: sh          $t2, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r10;
    // 0x8008873C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80088740: nop

    // 0x80088744: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80088748: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008874C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80088750: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x80088754: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80088758: jalr        $t9
    // 0x8008875C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_29;
    // 0x8008875C: nop

    after_29:
L_80088760:
    // 0x80088760: lbu         $t8, 0x57($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X57);
    // 0x80088764: nop

    // 0x80088768: andi        $t1, $t8, 0x4
    ctx->r9 = ctx->r24 & 0X4;
    // 0x8008876C: beq         $t1, $zero, L_800887DC
    if (ctx->r9 == 0) {
        // 0x80088770: nop
    
            goto L_800887DC;
    }
    // 0x80088770: nop

    // 0x80088774: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80088778: nop

    // 0x8008877C: lw          $t0, 0x14($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X14);
    // 0x80088780: nop

    // 0x80088784: beq         $t0, $zero, L_80088814
    if (ctx->r8 == 0) {
        // 0x80088788: nop
    
            goto L_80088814;
    }
    // 0x80088788: nop

    // 0x8008878C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80088790: nop

    // 0x80088794: lw          $t4, 0x1C($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X1C);
    // 0x80088798: nop

    // 0x8008879C: beq         $t4, $zero, L_80088814
    if (ctx->r12 == 0) {
        // 0x800887A0: nop
    
            goto L_80088814;
    }
    // 0x800887A0: nop

    // 0x800887A4: lh          $t2, 0x24($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X24);
    // 0x800887A8: lw          $a3, 0x20($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X20);
    // 0x800887AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800887B0: lb          $t7, 0x26($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X26);
    // 0x800887B4: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x800887B8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800887BC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800887C0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800887C4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800887C8: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x800887CC: jal         0x800B8DC0
    // 0x800887D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    alSynStartVoiceParams(rdram, ctx);
        goto after_30;
    // 0x800887D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_30:
    // 0x800887D4: b           L_80088814
    // 0x800887D8: nop

        goto L_80088814;
    // 0x800887D8: nop

L_800887DC:
    // 0x800887DC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800887E0: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800887E4: lh          $t1, 0x24($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X24);
    // 0x800887E8: lw          $a2, 0x1C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X1C);
    // 0x800887EC: lw          $a3, 0x20($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X20);
    // 0x800887F0: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    // 0x800887F4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800887F8: lb          $t3, 0x26($t8)
    ctx->r11 = MEM_B(ctx->r24, 0X26);
    // 0x800887FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80088800: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80088804: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80088808: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8008880C: jal         0x800B8DC0
    // 0x80088810: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    alSynStartVoiceParams(rdram, ctx);
        goto after_31;
    // 0x80088810: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_31:
L_80088814:
    // 0x80088814: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80088818: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008881C: sb          $t4, 0x27($t2)
    MEM_B(0X27, ctx->r10) = ctx->r12;
L_80088820:
    // 0x80088820: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80088824: nop

    // 0x80088828: lbu         $t7, 0x27($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X27);
    // 0x8008882C: nop

    // 0x80088830: beq         $t7, $zero, L_8008886C
    if (ctx->r15 == 0) {
        // 0x80088834: nop
    
            goto L_8008886C;
    }
    // 0x80088834: nop

    // 0x80088838: lbu         $t5, 0x57($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X57);
    // 0x8008883C: nop

    // 0x80088840: andi        $t9, $t5, 0x40
    ctx->r25 = ctx->r13 & 0X40;
    // 0x80088844: beq         $t9, $zero, L_8008886C
    if (ctx->r25 == 0) {
        // 0x80088848: nop
    
            goto L_8008886C;
    }
    // 0x80088848: nop

    // 0x8008884C: andi        $t1, $t5, 0x2
    ctx->r9 = ctx->r13 & 0X2;
    // 0x80088850: bne         $t1, $zero, L_8008886C
    if (ctx->r9 != 0) {
        // 0x80088854: nop
    
            goto L_8008886C;
    }
    // 0x80088854: nop

    // 0x80088858: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8008885C: lw          $a2, 0x20($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X20);
    // 0x80088860: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x80088864: jal         0x800B8EB0
    // 0x80088868: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    alSynSetPitch(rdram, ctx);
        goto after_32;
    // 0x80088868: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_32:
L_8008886C:
    // 0x8008886C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80088870: nop

    // 0x80088874: lbu         $t0, 0x27($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0X27);
    // 0x80088878: nop

    // 0x8008887C: beq         $t0, $zero, L_800889C0
    if (ctx->r8 == 0) {
        // 0x80088880: nop
    
            goto L_800889C0;
    }
    // 0x80088880: nop

    // 0x80088884: lbu         $t4, 0x57($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X57);
    // 0x80088888: nop

    // 0x8008888C: andi        $t2, $t4, 0x20
    ctx->r10 = ctx->r12 & 0X20;
    // 0x80088890: beq         $t2, $zero, L_800889C0
    if (ctx->r10 == 0) {
        // 0x80088894: nop
    
            goto L_800889C0;
    }
    // 0x80088894: nop

    // 0x80088898: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x8008889C: bne         $t7, $zero, L_800889C0
    if (ctx->r15 != 0) {
        // 0x800888A0: nop
    
            goto L_800889C0;
    }
    // 0x800888A0: nop

    // 0x800888A4: lh          $t9, 0x28($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X28);
    // 0x800888A8: nop

    // 0x800888AC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800888B0: jal         0x800B8340
    // 0x800888B4: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    sqrtf_recomp(rdram, ctx);
        goto after_33;
    // 0x800888B4: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_33:
    // 0x800888B8: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800888BC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800888C0: lh          $t1, 0x157C($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X157C);
    // 0x800888C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800888C8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800888CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800888D0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800888D4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800888D8: nop

    // 0x800888DC: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800888E0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800888E4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800888E8: nop

    // 0x800888EC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800888F0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800888F4: nop

    // 0x800888F8: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x800888FC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80088900: beq         $t6, $zero, L_80088950
    if (ctx->r14 == 0) {
        // 0x80088904: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80088950;
    }
    // 0x80088904: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80088908: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008890C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80088910: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80088914: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80088918: nop

    // 0x8008891C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80088920: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80088924: nop

    // 0x80088928: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x8008892C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80088930: bne         $t6, $zero, L_80088948
    if (ctx->r14 != 0) {
        // 0x80088934: nop
    
            goto L_80088948;
    }
    // 0x80088934: nop

    // 0x80088938: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8008893C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80088940: b           L_80088960
    // 0x80088944: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80088960;
    // 0x80088944: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80088948:
    // 0x80088948: b           L_80088960
    // 0x8008894C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80088960;
    // 0x8008894C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80088950:
    // 0x80088950: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80088954: nop

    // 0x80088958: bltz        $t6, L_80088948
    if (SIGNED(ctx->r14) < 0) {
        // 0x8008895C: nop
    
            goto L_80088948;
    }
    // 0x8008895C: nop

L_80088960:
    // 0x80088960: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80088964: andi        $t0, $t6, 0xFFFF
    ctx->r8 = ctx->r14 & 0XFFFF;
    // 0x80088968: sh          $t0, 0x24($t2)
    MEM_H(0X24, ctx->r10) = ctx->r8;
    // 0x8008896C: lbu         $t4, 0x57($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X57);
    // 0x80088970: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80088974: andi        $t7, $t4, 0x4
    ctx->r15 = ctx->r12 & 0X4;
    // 0x80088978: beq         $t7, $zero, L_800889A4
    if (ctx->r15 == 0) {
        // 0x8008897C: nop
    
            goto L_800889A4;
    }
    // 0x8008897C: nop

    // 0x80088980: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80088984: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80088988: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    // 0x8008898C: lh          $a2, 0x24($t9)
    ctx->r6 = MEM_H(ctx->r25, 0X24);
    // 0x80088990: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x80088994: jal         0x8008E5A0
    // 0x80088998: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    alSynSetVol(rdram, ctx);
        goto after_34;
    // 0x80088998: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_34:
    // 0x8008899C: b           L_800889C0
    // 0x800889A0: nop

        goto L_800889C0;
    // 0x800889A0: nop

L_800889A4:
    // 0x800889A4: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800889A8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800889AC: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    // 0x800889B0: lh          $a2, 0x24($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X24);
    // 0x800889B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800889B8: jal         0x8008E5A0
    // 0x800889BC: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    alSynSetVol(rdram, ctx);
        goto after_35;
    // 0x800889BC: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_35:
L_800889C0:
    // 0x800889C0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800889C4: nop

    // 0x800889C8: lbu         $t6, 0x27($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X27);
    // 0x800889CC: nop

    // 0x800889D0: beq         $t6, $zero, L_80088A0C
    if (ctx->r14 == 0) {
        // 0x800889D4: nop
    
            goto L_80088A0C;
    }
    // 0x800889D4: nop

    // 0x800889D8: lbu         $t0, 0x57($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X57);
    // 0x800889DC: nop

    // 0x800889E0: andi        $t2, $t0, 0x10
    ctx->r10 = ctx->r8 & 0X10;
    // 0x800889E4: beq         $t2, $zero, L_80088A0C
    if (ctx->r10 == 0) {
        // 0x800889E8: nop
    
            goto L_80088A0C;
    }
    // 0x800889E8: nop

    // 0x800889EC: andi        $t4, $t0, 0x2
    ctx->r12 = ctx->r8 & 0X2;
    // 0x800889F0: bne         $t4, $zero, L_80088A0C
    if (ctx->r12 != 0) {
        // 0x800889F4: nop
    
            goto L_80088A0C;
    }
    // 0x800889F4: nop

    // 0x800889F8: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800889FC: lb          $a2, 0x26($t8)
    ctx->r6 = MEM_B(ctx->r24, 0X26);
    // 0x80088A00: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    // 0x80088A04: jal         0x800B8D30
    // 0x80088A08: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    alSynSetPan(rdram, ctx);
        goto after_36;
    // 0x80088A08: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_36:
L_80088A0C:
    // 0x80088A0C: lbu         $t3, 0x57($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X57);
    // 0x80088A10: nop

    // 0x80088A14: andi        $t9, $t3, 0x1
    ctx->r25 = ctx->r11 & 0X1;
    // 0x80088A18: beq         $t9, $zero, L_80088B60
    if (ctx->r25 == 0) {
        // 0x80088A1C: nop
    
            goto L_80088B60;
    }
    // 0x80088A1C: nop

    // 0x80088A20: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80088A24: nop

    // 0x80088A28: lhu         $t1, 0x1568($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X1568);
    // 0x80088A2C: nop

    // 0x80088A30: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x80088A34: andi        $t2, $t6, 0xFF
    ctx->r10 = ctx->r14 & 0XFF;
    // 0x80088A38: addu        $t0, $t5, $t2
    ctx->r8 = ADD32(ctx->r13, ctx->r10);
    // 0x80088A3C: lbu         $t4, 0x1468($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X1468);
    // 0x80088A40: nop

    // 0x80088A44: sb          $t4, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r12;
    // 0x80088A48: lhu         $t7, 0x1568($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X1568);
    // 0x80088A4C: nop

    // 0x80088A50: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80088A54: sh          $t8, 0x1568($t5)
    MEM_H(0X1568, ctx->r13) = ctx->r24;
    // 0x80088A58: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80088A5C: nop

    // 0x80088A60: lw          $t9, 0x156C($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X156C);
    // 0x80088A64: nop

    // 0x80088A68: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80088A6C: sw          $t1, 0x156C($t3)
    MEM_W(0X156C, ctx->r11) = ctx->r9;
    // 0x80088A70: lbu         $t6, 0x57($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X57);
    // 0x80088A74: nop

    // 0x80088A78: andi        $t2, $t6, 0x40
    ctx->r10 = ctx->r14 & 0X40;
    // 0x80088A7C: beq         $t2, $zero, L_80088B1C
    if (ctx->r10 == 0) {
        // 0x80088A80: nop
    
            goto L_80088B1C;
    }
    // 0x80088A80: nop

    // 0x80088A84: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80088A88: lui         $t3, 0x773
    ctx->r11 = S32(0X773 << 16);
    // 0x80088A8C: lhu         $t4, 0x1568($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X1568);
    // 0x80088A90: ori         $t3, $t3, 0x5940
    ctx->r11 = ctx->r11 | 0X5940;
    // 0x80088A94: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x80088A98: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80088A9C: addu        $t5, $t0, $t8
    ctx->r13 = ADD32(ctx->r8, ctx->r24);
    // 0x80088AA0: lbu         $t9, 0x1468($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X1468);
    // 0x80088AA4: nop

    // 0x80088AA8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80088AAC: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x80088AB0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80088AB4: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x80088AB8: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80088ABC: div         $zero, $t3, $t1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r9)));
    // 0x80088AC0: bne         $t1, $zero, L_80088ACC
    if (ctx->r9 != 0) {
        // 0x80088AC4: nop
    
            goto L_80088ACC;
    }
    // 0x80088AC4: nop

    // 0x80088AC8: break       7
    do_break(2148043464);
L_80088ACC:
    // 0x80088ACC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80088AD0: bne         $t1, $at, L_80088AE4
    if (ctx->r9 != ctx->r1) {
        // 0x80088AD4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80088AE4;
    }
    // 0x80088AD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80088AD8: bne         $t3, $at, L_80088AE4
    if (ctx->r11 != ctx->r1) {
        // 0x80088ADC: nop
    
            goto L_80088AE4;
    }
    // 0x80088ADC: nop

    // 0x80088AE0: break       6
    do_break(2148043488);
L_80088AE4:
    // 0x80088AE4: mflo        $t6
    ctx->r14 = lo;
    // 0x80088AE8: sw          $t6, 0x1578($t0)
    MEM_W(0X1578, ctx->r8) = ctx->r14;
    // 0x80088AEC: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80088AF0: nop

    // 0x80088AF4: lhu         $t4, 0x1568($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X1568);
    // 0x80088AF8: nop

    // 0x80088AFC: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x80088B00: sh          $t7, 0x1568($t2)
    MEM_H(0X1568, ctx->r10) = ctx->r15;
    // 0x80088B04: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80088B08: nop

    // 0x80088B0C: lw          $t5, 0x156C($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X156C);
    // 0x80088B10: nop

    // 0x80088B14: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x80088B18: sw          $t9, 0x156C($t8)
    MEM_W(0X156C, ctx->r24) = ctx->r25;
L_80088B1C:
    // 0x80088B1C: lbu         $t3, 0x57($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X57);
    // 0x80088B20: nop

    // 0x80088B24: andi        $t1, $t3, 0x20
    ctx->r9 = ctx->r11 & 0X20;
    // 0x80088B28: beq         $t1, $zero, L_80088B60
    if (ctx->r9 == 0) {
        // 0x80088B2C: nop
    
            goto L_80088B60;
    }
    // 0x80088B2C: nop

    // 0x80088B30: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80088B34: nop

    // 0x80088B38: lhu         $t0, 0x1568($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X1568);
    // 0x80088B3C: nop

    // 0x80088B40: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x80088B44: sh          $t4, 0x1568($t6)
    MEM_H(0X1568, ctx->r14) = ctx->r12;
    // 0x80088B48: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80088B4C: nop

    // 0x80088B50: lw          $t2, 0x156C($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X156C);
    // 0x80088B54: nop

    // 0x80088B58: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x80088B5C: sw          $t5, 0x156C($t7)
    MEM_W(0X156C, ctx->r15) = ctx->r13;
L_80088B60:
    // 0x80088B60: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80088B64: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80088B68: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80088B6C: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80088B70: lw          $t1, 0x440($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X440);
    // 0x80088B74: nop

    // 0x80088B78: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80088B7C: bne         $at, $zero, L_80087EB8
    if (ctx->r1 != 0) {
        // 0x80088B80: nop
    
            goto L_80087EB8;
    }
    // 0x80088B80: nop

L_80088B84:
    // 0x80088B84: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80088B88: nop

    // 0x80088B8C: lw          $v0, 0x1578($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X1578);
    // 0x80088B90: nop

L_80088B94:
    // 0x80088B94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80088B98: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80088B9C: jr          $ra
    // 0x80088BA0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80088BA0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}

RECOMP_FUNC void Dcm_VoiceHandler_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A80C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008A810: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8008A814: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8008A818: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008A81C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008A820: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8008A824: addiu       $a0, $a0, -0x72B0
    ctx->r4 = ADD32(ctx->r4, -0X72B0);
    // 0x8008A828: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8008A82C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A830: jal         0x800B3C20
    // 0x8008A834: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8008A834: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    after_0:
    // 0x8008A838: bne         $v0, $zero, L_8008A974
    if (ctx->r2 != 0) {
        // 0x8008A83C: nop
    
            goto L_8008A974;
    }
    // 0x8008A83C: nop

    // 0x8008A840: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008A844: nop

    // 0x8008A848: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8008A84C: nop

    // 0x8008A850: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8008A854: lh          $s0, 0x0($t7)
    ctx->r16 = MEM_H(ctx->r15, 0X0);
    // 0x8008A858: nop

    // 0x8008A85C: beq         $s0, $zero, L_8008A874
    if (ctx->r16 == 0) {
        // 0x8008A860: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008A874;
    }
    // 0x8008A860: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A864: beq         $s0, $at, L_8008A938
    if (ctx->r16 == ctx->r1) {
        // 0x8008A868: nop
    
            goto L_8008A938;
    }
    // 0x8008A868: nop

    // 0x8008A86C: b           L_8008A968
    // 0x8008A870: nop

        goto L_8008A968;
    // 0x8008A870: nop

L_8008A874:
    // 0x8008A874: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8008A878: sb          $zero, 0x56($sp)
    MEM_B(0X56, ctx->r29) = 0;
    // 0x8008A87C: lw          $t0, 0x8C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8C);
    // 0x8008A880: nop

    // 0x8008A884: beq         $t0, $zero, L_8008A900
    if (ctx->r8 == 0) {
        // 0x8008A888: nop
    
            goto L_8008A900;
    }
    // 0x8008A888: nop

L_8008A88C:
    // 0x8008A88C: lbu         $t3, 0x56($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X56);
    // 0x8008A890: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8008A894: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8008A898: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008A89C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008A8A0: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x8008A8A4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008A8A8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008A8AC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8008A8B0: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x8008A8B4: lbu         $t6, 0x27($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X27);
    // 0x8008A8B8: nop

    // 0x8008A8BC: beq         $t6, $zero, L_8008A8DC
    if (ctx->r14 == 0) {
        // 0x8008A8C0: nop
    
            goto L_8008A8DC;
    }
    // 0x8008A8C0: nop

    // 0x8008A8C4: sb          $zero, 0x27($t5)
    MEM_B(0X27, ctx->r13) = 0;
    // 0x8008A8C8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8008A8CC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8008A8D0: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x8008A8D4: jal         0x800B8B60
    // 0x8008A8D8: nop

    alSynStopVoice(rdram, ctx);
        goto after_1;
    // 0x8008A8D8: nop

    after_1:
L_8008A8DC:
    // 0x8008A8DC: lbu         $t7, 0x56($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X56);
    // 0x8008A8E0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8008A8E4: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8008A8E8: sb          $t9, 0x56($sp)
    MEM_B(0X56, ctx->r29) = ctx->r25;
    // 0x8008A8EC: lw          $t3, 0x8C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8C);
    // 0x8008A8F0: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8008A8F4: sltu        $at, $t0, $t3
    ctx->r1 = ctx->r8 < ctx->r11 ? 1 : 0;
    // 0x8008A8F8: bne         $at, $zero, L_8008A88C
    if (ctx->r1 != 0) {
        // 0x8008A8FC: nop
    
            goto L_8008A88C;
    }
    // 0x8008A8FC: nop

L_8008A900:
    // 0x8008A900: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8008A904: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8008A908: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008A90C: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x8008A910: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008A914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A918: jal         0x800B34D0
    // 0x8008A91C: sw          $t2, 0x88($t4)
    MEM_W(0X88, ctx->r12) = ctx->r10;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8008A91C: sw          $t2, 0x88($t4)
    MEM_W(0X88, ctx->r12) = ctx->r10;
    after_2:
    // 0x8008A920: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8008A924: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8008A928: sh          $zero, 0x0($t6)
    MEM_H(0X0, ctx->r14) = 0;
    // 0x8008A92C: lw          $v0, 0x3940($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3940);
    // 0x8008A930: b           L_8008BCC8
    // 0x8008A934: nop

        goto L_8008BCC8;
    // 0x8008A934: nop

L_8008A938:
    // 0x8008A938: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8008A93C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8008A940: sw          $t5, 0x88($t8)
    MEM_W(0X88, ctx->r24) = ctx->r13;
    // 0x8008A944: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008A948: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008A94C: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x8008A950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008A954: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A958: jal         0x800B34D0
    // 0x8008A95C: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8008A95C: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    after_3:
    // 0x8008A960: b           L_8008A974
    // 0x8008A964: nop

        goto L_8008A974;
    // 0x8008A964: nop

L_8008A968:
    // 0x8008A968: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008A96C: nop

    // 0x8008A970: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
L_8008A974:
    // 0x8008A974: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8008A978: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008A97C: lw          $t0, 0x88($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X88);
    // 0x8008A980: nop

    // 0x8008A984: bne         $t0, $at, L_8008A99C
    if (ctx->r8 != ctx->r1) {
        // 0x8008A988: nop
    
            goto L_8008A99C;
    }
    // 0x8008A988: nop

    // 0x8008A98C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8008A990: lw          $v0, 0x3940($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3940);
    // 0x8008A994: b           L_8008BCC8
    // 0x8008A998: nop

        goto L_8008BCC8;
    // 0x8008A998: nop

L_8008A99C:
    // 0x8008A99C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8008A9A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A9A4: lw          $t2, 0x88($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X88);
    // 0x8008A9A8: nop

    // 0x8008A9AC: bne         $t2, $at, L_8008BCBC
    if (ctx->r10 != ctx->r1) {
        // 0x8008A9B0: nop
    
            goto L_8008BCBC;
    }
    // 0x8008A9B0: nop

    // 0x8008A9B4: jal         0x8008A61C
    // 0x8008A9B8: nop

    Audio2_UpdateScheduledSFX(rdram, ctx);
        goto after_4;
    // 0x8008A9B8: nop

    after_4:
    // 0x8008A9BC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8008A9C0: sb          $zero, 0x56($sp)
    MEM_B(0X56, ctx->r29) = 0;
    // 0x8008A9C4: lw          $t6, 0x8C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8C);
    // 0x8008A9C8: nop

    // 0x8008A9CC: beq         $t6, $zero, L_8008AF70
    if (ctx->r14 == 0) {
        // 0x8008A9D0: nop
    
            goto L_8008AF70;
    }
    // 0x8008A9D0: nop

L_8008A9D4:
    // 0x8008A9D4: lbu         $t7, 0x56($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X56);
    // 0x8008A9D8: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8008A9DC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8008A9E0: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8008A9E4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008A9E8: sra         $t0, $t7, 1
    ctx->r8 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8008A9EC: lw          $t8, 0x1C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X1C);
    // 0x8008A9F0: sll         $t3, $t0, 3
    ctx->r11 = S32(ctx->r8 << 3);
    // 0x8008A9F4: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8008A9F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008A9FC: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x8008AA00: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008AA04: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8008AA08: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8008AA0C: addu        $t2, $t5, $t3
    ctx->r10 = ADD32(ctx->r13, ctx->r11);
    // 0x8008AA10: lbu         $t4, 0x124($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X124);
    // 0x8008AA14: nop

    // 0x8008AA18: beq         $t4, $zero, L_8008ABF0
    if (ctx->r12 == 0) {
        // 0x8008AA1C: nop
    
            goto L_8008ABF0;
    }
    // 0x8008AA1C: nop

    // 0x8008AA20: lbu         $t8, 0x56($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X56);
    // 0x8008AA24: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008AA28: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8008AA2C: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x8008AA30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008AA34: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8008AA38: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8008AA3C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008AA40: sb          $zero, 0x3B98($at)
    MEM_B(0X3B98, ctx->r1) = 0;
    // 0x8008AA44: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x8008AA48: sb          $zero, 0x124($t7)
    MEM_B(0X124, ctx->r15) = 0;
    // 0x8008AA4C: lbu         $t3, 0x56($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X56);
    // 0x8008AA50: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8008AA54: sra         $t2, $t3, 1
    ctx->r10 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8008AA58: sll         $t4, $t2, 3
    ctx->r12 = S32(ctx->r10 << 3);
    // 0x8008AA5C: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x8008AA60: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008AA64: addu        $t0, $t5, $t4
    ctx->r8 = ADD32(ctx->r13, ctx->r12);
    // 0x8008AA68: lw          $t8, 0x11C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X11C);
    // 0x8008AA6C: lw          $t9, 0x128($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X128);
    // 0x8008AA70: nop

    // 0x8008AA74: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x8008AA78: sw          $t6, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->r14;
    // 0x8008AA7C: lbu         $t3, 0x56($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X56);
    // 0x8008AA80: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8008AA84: sra         $t2, $t3, 1
    ctx->r10 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8008AA88: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8008AA8C: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x8008AA90: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008AA94: lw          $t7, 0x1C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X1C);
    // 0x8008AA98: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x8008AA9C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008AAA0: addu        $t4, $t7, $t5
    ctx->r12 = ADD32(ctx->r15, ctx->r13);
    // 0x8008AAA4: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x8008AAA8: lbu         $t8, 0x27($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X27);
    // 0x8008AAAC: nop

    // 0x8008AAB0: beq         $t8, $zero, L_8008ABF0
    if (ctx->r24 == 0) {
        // 0x8008AAB4: nop
    
            goto L_8008ABF0;
    }
    // 0x8008AAB4: nop

    // 0x8008AAB8: lw          $t9, 0x8($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X8);
    // 0x8008AABC: nop

    // 0x8008AAC0: beq         $t9, $zero, L_8008ABD0
    if (ctx->r25 == 0) {
        // 0x8008AAC4: nop
    
            goto L_8008ABD0;
    }
    // 0x8008AAC4: nop

    // 0x8008AAC8: lw          $t6, 0xC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0XC);
    // 0x8008AACC: addiu       $t0, $zero, 0x240
    ctx->r8 = ADD32(0, 0X240);
    // 0x8008AAD0: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x8008AAD4: lw          $t1, 0x8($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X8);
    // 0x8008AAD8: jal         0x8008ED04
    // 0x8008AADC: sw          $t0, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = ctx->r8;
    __allocParam(rdram, ctx);
        goto after_5;
    // 0x8008AADC: sw          $t0, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = ctx->r8;
    after_5:
    // 0x8008AAE0: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8008AAE4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8008AAE8: nop

    // 0x8008AAEC: beq         $t3, $zero, L_8008AB60
    if (ctx->r11 == 0) {
        // 0x8008AAF0: nop
    
            goto L_8008AB60;
    }
    // 0x8008AAF0: nop

    // 0x8008AAF4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8008AAF8: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x8008AAFC: lw          $t7, 0x14($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X14);
    // 0x8008AB00: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008AB04: lw          $t5, 0x1C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X1C);
    // 0x8008AB08: nop

    // 0x8008AB0C: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8008AB10: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8008AB14: nop

    // 0x8008AB18: sh          $t8, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r24;
    // 0x8008AB1C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8008AB20: nop

    // 0x8008AB24: sw          $zero, 0xC($t6)
    MEM_W(0XC, ctx->r14) = 0;
    // 0x8008AB28: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8008AB2C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8008AB30: lw          $t0, 0x8($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X8);
    // 0x8008AB34: nop

    // 0x8008AB38: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x8008AB3C: nop

    // 0x8008AB40: addiu       $t2, $t1, -0x40
    ctx->r10 = ADD32(ctx->r9, -0X40);
    // 0x8008AB44: sw          $t2, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r10;
    // 0x8008AB48: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8008AB4C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008AB50: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x8008AB54: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8008AB58: jalr        $t9
    // 0x8008AB5C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8008AB5C: nop

    after_6:
L_8008AB60:
    // 0x8008AB60: jal         0x8008ED04
    // 0x8008AB64: nop

    __allocParam(rdram, ctx);
        goto after_7;
    // 0x8008AB64: nop

    after_7:
    // 0x8008AB68: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8008AB6C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8008AB70: nop

    // 0x8008AB74: beq         $t3, $zero, L_8008ABD0
    if (ctx->r11 == 0) {
        // 0x8008AB78: nop
    
            goto L_8008ABD0;
    }
    // 0x8008AB78: nop

    // 0x8008AB7C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8008AB80: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8008AB84: lw          $t6, 0x14($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X14);
    // 0x8008AB88: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8008AB8C: lw          $t4, 0x1C($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X1C);
    // 0x8008AB90: lw          $t2, 0xD8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XD8);
    // 0x8008AB94: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x8008AB98: addu        $t7, $t4, $t2
    ctx->r15 = ADD32(ctx->r12, ctx->r10);
    // 0x8008AB9C: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8008ABA0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8008ABA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008ABA8: sh          $t5, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r13;
    // 0x8008ABAC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8008ABB0: nop

    // 0x8008ABB4: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8008ABB8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8008ABBC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008ABC0: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x8008ABC4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8008ABC8: jalr        $t9
    // 0x8008ABCC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8008ABCC: nop

    after_8:
L_8008ABD0:
    // 0x8008ABD0: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8008ABD4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8008ABD8: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x8008ABDC: jal         0x800B8B60
    // 0x8008ABE0: nop

    alSynStopVoice(rdram, ctx);
        goto after_9;
    // 0x8008ABE0: nop

    after_9:
    // 0x8008ABE4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8008ABE8: nop

    // 0x8008ABEC: sb          $zero, 0x27($t1)
    MEM_B(0X27, ctx->r9) = 0;
L_8008ABF0:
    // 0x8008ABF0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8008ABF4: lbu         $t2, 0x56($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X56);
    // 0x8008ABF8: nop

    // 0x8008ABFC: addu        $t7, $t4, $t2
    ctx->r15 = ADD32(ctx->r12, ctx->r10);
    // 0x8008AC00: lbu         $t3, 0x354($t7)
    ctx->r11 = MEM_BU(ctx->r15, 0X354);
    // 0x8008AC04: nop

    // 0x8008AC08: beq         $t3, $zero, L_8008AF4C
    if (ctx->r11 == 0) {
        // 0x8008AC0C: nop
    
            goto L_8008AF4C;
    }
    // 0x8008AC0C: nop

    // 0x8008AC10: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8008AC14: lbu         $t6, 0x56($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X56);
    // 0x8008AC18: sra         $t5, $t2, 1
    ctx->r13 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8008AC1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008AC20: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8008AC24: sb          $zero, 0x3B98($at)
    MEM_B(0X3B98, ctx->r1) = 0;
    // 0x8008AC28: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8008AC2C: lbu         $t0, 0x354($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X354);
    // 0x8008AC30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008AC34: beq         $t0, $at, L_8008AC50
    if (ctx->r8 == ctx->r1) {
        // 0x8008AC38: nop
    
            goto L_8008AC50;
    }
    // 0x8008AC38: nop

    // 0x8008AC3C: sra         $t4, $t6, 1
    ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8008AC40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008AC44: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8008AC48: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8008AC4C: sb          $t1, -0x7220($at)
    MEM_B(-0X7220, ctx->r1) = ctx->r9;
L_8008AC50:
    // 0x8008AC50: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8008AC54: lbu         $t3, 0x56($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X56);
    // 0x8008AC58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008AC5C: addu        $t2, $t7, $t3
    ctx->r10 = ADD32(ctx->r15, ctx->r11);
    // 0x8008AC60: sb          $zero, 0x354($t2)
    MEM_B(0X354, ctx->r10) = 0;
    // 0x8008AC64: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8008AC68: nop

    // 0x8008AC6C: lbu         $t8, 0x27($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X27);
    // 0x8008AC70: nop

    // 0x8008AC74: bne         $t8, $at, L_8008ADB4
    if (ctx->r24 != ctx->r1) {
        // 0x8008AC78: nop
    
            goto L_8008ADB4;
    }
    // 0x8008AC78: nop

    // 0x8008AC7C: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x8008AC80: nop

    // 0x8008AC84: beq         $t9, $zero, L_8008AD94
    if (ctx->r25 == 0) {
        // 0x8008AC88: nop
    
            goto L_8008AD94;
    }
    // 0x8008AC88: nop

    // 0x8008AC8C: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8008AC90: addiu       $t6, $zero, 0x240
    ctx->r14 = ADD32(0, 0X240);
    // 0x8008AC94: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8008AC98: lw          $t1, 0x8($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X8);
    // 0x8008AC9C: jal         0x8008ED04
    // 0x8008ACA0: sw          $t6, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = ctx->r14;
    __allocParam(rdram, ctx);
        goto after_10;
    // 0x8008ACA0: sw          $t6, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = ctx->r14;
    after_10:
    // 0x8008ACA4: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8008ACA8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8008ACAC: nop

    // 0x8008ACB0: beq         $t4, $zero, L_8008AD24
    if (ctx->r12 == 0) {
        // 0x8008ACB4: nop
    
            goto L_8008AD24;
    }
    // 0x8008ACB4: nop

    // 0x8008ACB8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8008ACBC: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x8008ACC0: lw          $t3, 0x14($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X14);
    // 0x8008ACC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008ACC8: lw          $t2, 0x1C($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X1C);
    // 0x8008ACCC: nop

    // 0x8008ACD0: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x8008ACD4: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8008ACD8: nop

    // 0x8008ACDC: sh          $t8, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r24;
    // 0x8008ACE0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8008ACE4: nop

    // 0x8008ACE8: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x8008ACEC: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8008ACF0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8008ACF4: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8008ACF8: nop

    // 0x8008ACFC: lw          $t1, 0xD8($t6)
    ctx->r9 = MEM_W(ctx->r14, 0XD8);
    // 0x8008AD00: nop

    // 0x8008AD04: addiu       $t7, $t1, -0x40
    ctx->r15 = ADD32(ctx->r9, -0X40);
    // 0x8008AD08: sw          $t7, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r15;
    // 0x8008AD0C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8008AD10: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008AD14: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x8008AD18: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8008AD1C: jalr        $t9
    // 0x8008AD20: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x8008AD20: nop

    after_11:
L_8008AD24:
    // 0x8008AD24: jal         0x8008ED04
    // 0x8008AD28: nop

    __allocParam(rdram, ctx);
        goto after_12;
    // 0x8008AD28: nop

    after_12:
    // 0x8008AD2C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8008AD30: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8008AD34: nop

    // 0x8008AD38: beq         $t4, $zero, L_8008AD94
    if (ctx->r12 == 0) {
        // 0x8008AD3C: nop
    
            goto L_8008AD94;
    }
    // 0x8008AD3C: nop

    // 0x8008AD40: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8008AD44: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8008AD48: lw          $t0, 0x14($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X14);
    // 0x8008AD4C: lw          $t1, 0x8($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X8);
    // 0x8008AD50: lw          $t5, 0x1C($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X1C);
    // 0x8008AD54: lw          $t7, 0xD8($t1)
    ctx->r15 = MEM_W(ctx->r9, 0XD8);
    // 0x8008AD58: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x8008AD5C: addu        $t3, $t5, $t7
    ctx->r11 = ADD32(ctx->r13, ctx->r15);
    // 0x8008AD60: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8008AD64: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8008AD68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008AD6C: sh          $t2, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r10;
    // 0x8008AD70: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8008AD74: nop

    // 0x8008AD78: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8008AD7C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8008AD80: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008AD84: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x8008AD88: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8008AD8C: jalr        $t9
    // 0x8008AD90: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x8008AD90: nop

    after_13:
L_8008AD94:
    // 0x8008AD94: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008AD98: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8008AD9C: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x8008ADA0: jal         0x800B8B60
    // 0x8008ADA4: nop

    alSynStopVoice(rdram, ctx);
        goto after_14;
    // 0x8008ADA4: nop

    after_14:
    // 0x8008ADA8: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8008ADAC: b           L_8008AF4C
    // 0x8008ADB0: sb          $zero, 0x27($t1)
    MEM_B(0X27, ctx->r9) = 0;
        goto L_8008AF4C;
    // 0x8008ADB0: sb          $zero, 0x27($t1)
    MEM_B(0X27, ctx->r9) = 0;
L_8008ADB4:
    // 0x8008ADB4: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8008ADB8: nop

    // 0x8008ADBC: lw          $t7, 0x14($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X14);
    // 0x8008ADC0: nop

    // 0x8008ADC4: beq         $t7, $zero, L_8008AE0C
    if (ctx->r15 == 0) {
        // 0x8008ADC8: nop
    
            goto L_8008AE0C;
    }
    // 0x8008ADC8: nop

    // 0x8008ADCC: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8008ADD0: nop

    // 0x8008ADD4: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x8008ADD8: nop

    // 0x8008ADDC: beq         $t4, $zero, L_8008AE0C
    if (ctx->r12 == 0) {
        // 0x8008ADE0: nop
    
            goto L_8008AE0C;
    }
    // 0x8008ADE0: nop

    // 0x8008ADE4: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x8008ADE8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8008ADEC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8008ADF0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8008ADF4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8008ADF8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8008ADFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008AE00: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008AE04: jal         0x800B8DC0
    // 0x8008AE08: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    alSynStartVoiceParams(rdram, ctx);
        goto after_15;
    // 0x8008AE08: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_15:
L_8008AE0C:
    // 0x8008AE0C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8008AE10: nop

    // 0x8008AE14: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8008AE18: nop

    // 0x8008AE1C: beq         $t0, $zero, L_8008AF2C
    if (ctx->r8 == 0) {
        // 0x8008AE20: nop
    
            goto L_8008AF2C;
    }
    // 0x8008AE20: nop

    // 0x8008AE24: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x8008AE28: addiu       $t6, $zero, 0x240
    ctx->r14 = ADD32(0, 0X240);
    // 0x8008AE2C: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x8008AE30: lw          $t1, 0x8($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X8);
    // 0x8008AE34: jal         0x8008ED04
    // 0x8008AE38: sw          $t6, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = ctx->r14;
    __allocParam(rdram, ctx);
        goto after_16;
    // 0x8008AE38: sw          $t6, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = ctx->r14;
    after_16:
    // 0x8008AE3C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8008AE40: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8008AE44: nop

    // 0x8008AE48: beq         $t5, $zero, L_8008AEBC
    if (ctx->r13 == 0) {
        // 0x8008AE4C: nop
    
            goto L_8008AEBC;
    }
    // 0x8008AE4C: nop

    // 0x8008AE50: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8008AE54: addiu       $t2, $zero, 0xB
    ctx->r10 = ADD32(0, 0XB);
    // 0x8008AE58: lw          $t3, 0x14($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X14);
    // 0x8008AE5C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008AE60: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x8008AE64: nop

    // 0x8008AE68: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8008AE6C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8008AE70: nop

    // 0x8008AE74: sh          $t2, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r10;
    // 0x8008AE78: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8008AE7C: nop

    // 0x8008AE80: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
    // 0x8008AE84: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8008AE88: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8008AE8C: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x8008AE90: nop

    // 0x8008AE94: lw          $t1, 0xD8($t6)
    ctx->r9 = MEM_W(ctx->r14, 0XD8);
    // 0x8008AE98: nop

    // 0x8008AE9C: addiu       $t7, $t1, -0x40
    ctx->r15 = ADD32(ctx->r9, -0X40);
    // 0x8008AEA0: sw          $t7, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r15;
    // 0x8008AEA4: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8008AEA8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008AEAC: lw          $t9, 0x8($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X8);
    // 0x8008AEB0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8008AEB4: jalr        $t9
    // 0x8008AEB8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_17;
    // 0x8008AEB8: nop

    after_17:
L_8008AEBC:
    // 0x8008AEBC: jal         0x8008ED04
    // 0x8008AEC0: nop

    __allocParam(rdram, ctx);
        goto after_18;
    // 0x8008AEC0: nop

    after_18:
    // 0x8008AEC4: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8008AEC8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8008AECC: nop

    // 0x8008AED0: beq         $t5, $zero, L_8008AF2C
    if (ctx->r13 == 0) {
        // 0x8008AED4: nop
    
            goto L_8008AF2C;
    }
    // 0x8008AED4: nop

    // 0x8008AED8: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8008AEDC: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8008AEE0: lw          $t0, 0x14($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X14);
    // 0x8008AEE4: lw          $t1, 0x8($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X8);
    // 0x8008AEE8: lw          $t8, 0x1C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X1C);
    // 0x8008AEEC: lw          $t7, 0xD8($t1)
    ctx->r15 = MEM_W(ctx->r9, 0XD8);
    // 0x8008AEF0: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x8008AEF4: addu        $t3, $t8, $t7
    ctx->r11 = ADD32(ctx->r24, ctx->r15);
    // 0x8008AEF8: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x8008AEFC: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8008AF00: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008AF04: sh          $t4, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r12;
    // 0x8008AF08: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8008AF0C: nop

    // 0x8008AF10: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x8008AF14: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8008AF18: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008AF1C: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x8008AF20: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8008AF24: jalr        $t9
    // 0x8008AF28: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_19;
    // 0x8008AF28: nop

    after_19:
L_8008AF2C:
    // 0x8008AF2C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008AF30: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8008AF34: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x8008AF38: jal         0x800B8B60
    // 0x8008AF3C: nop

    alSynStopVoice(rdram, ctx);
        goto after_20;
    // 0x8008AF3C: nop

    after_20:
    // 0x8008AF40: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8008AF44: nop

    // 0x8008AF48: sb          $zero, 0x27($t1)
    MEM_B(0X27, ctx->r9) = 0;
L_8008AF4C:
    // 0x8008AF4C: lbu         $t8, 0x56($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X56);
    // 0x8008AF50: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8008AF54: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8008AF58: sb          $t7, 0x56($sp)
    MEM_B(0X56, ctx->r29) = ctx->r15;
    // 0x8008AF5C: lw          $t4, 0x8C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X8C);
    // 0x8008AF60: andi        $t3, $t7, 0xFF
    ctx->r11 = ctx->r15 & 0XFF;
    // 0x8008AF64: sltu        $at, $t3, $t4
    ctx->r1 = ctx->r11 < ctx->r12 ? 1 : 0;
    // 0x8008AF68: bne         $at, $zero, L_8008A9D4
    if (ctx->r1 != 0) {
        // 0x8008AF6C: nop
    
            goto L_8008A9D4;
    }
    // 0x8008AF6C: nop

L_8008AF70:
    // 0x8008AF70: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8008AF74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008AF78: sb          $zero, 0x3BA0($at)
    MEM_B(0X3BA0, ctx->r1) = 0;
    // 0x8008AF7C: lw          $t0, 0x8C($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X8C);
    // 0x8008AF80: nop

    // 0x8008AF84: srl         $t9, $t0, 1
    ctx->r25 = S32(U32(ctx->r8) >> 1);
    // 0x8008AF88: beq         $t9, $zero, L_8008BCBC
    if (ctx->r25 == 0) {
        // 0x8008AF8C: nop
    
            goto L_8008BCBC;
    }
    // 0x8008AF8C: nop

L_8008AF90:
    // 0x8008AF90: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008AF94: lbu         $t1, 0x3BA0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X3BA0);
    // 0x8008AF98: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008AF9C: sll         $t8, $t1, 3
    ctx->r24 = S32(ctx->r9 << 3);
    // 0x8008AFA0: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x8008AFA4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008AFA8: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x8008AFAC: lw          $t5, 0x118($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X118);
    // 0x8008AFB0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8008AFB4: addu        $t4, $t6, $t3
    ctx->r12 = ADD32(ctx->r14, ctx->r11);
    // 0x8008AFB8: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8008AFBC: lw          $t2, 0x20($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X20);
    // 0x8008AFC0: nop

    // 0x8008AFC4: beq         $t2, $zero, L_8008BC8C
    if (ctx->r10 == 0) {
        // 0x8008AFC8: nop
    
            goto L_8008BC8C;
    }
    // 0x8008AFC8: nop

    // 0x8008AFCC: beq         $t5, $zero, L_8008BC8C
    if (ctx->r13 == 0) {
        // 0x8008AFD0: nop
    
            goto L_8008BC8C;
    }
    // 0x8008AFD0: nop

    // 0x8008AFD4: lw          $t0, 0x110($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X110);
    // 0x8008AFD8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008AFDC: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x8008AFE0: nop

    // 0x8008AFE4: bne         $t9, $at, L_8008AFFC
    if (ctx->r25 != ctx->r1) {
        // 0x8008AFE8: nop
    
            goto L_8008AFFC;
    }
    // 0x8008AFE8: nop

    // 0x8008AFEC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008AFF0: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8008AFF4: jal         0x800B3BFC
    // 0x8008AFF8: addiu       $a0, $a0, -0x670
    ctx->r4 = ADD32(ctx->r4, -0X670);
    rmonPrintf_recomp(rdram, ctx);
        goto after_21;
    // 0x8008AFF8: addiu       $a0, $a0, -0x670
    ctx->r4 = ADD32(ctx->r4, -0X670);
    after_21:
L_8008AFFC:
    // 0x8008AFFC: sb          $zero, 0x56($sp)
    MEM_B(0X56, ctx->r29) = 0;
L_8008B000:
    // 0x8008B000: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008B004: lbu         $t1, 0x3BA0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X3BA0);
    // 0x8008B008: lbu         $t8, 0x56($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X56);
    // 0x8008B00C: sll         $t6, $t1, 1
    ctx->r14 = S32(ctx->r9 << 1);
    // 0x8008B010: addu        $t3, $t8, $t6
    ctx->r11 = ADD32(ctx->r24, ctx->r14);
    // 0x8008B014: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8008B018: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8008B01C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008B020: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008B024: lw          $t5, 0x1C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X1C);
    // 0x8008B028: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008B02C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008B030: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8008B034: addiu       $t9, $t9, 0x3B98
    ctx->r25 = ADD32(ctx->r25, 0X3B98);
    // 0x8008B038: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x8008B03C: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x8008B040: addu        $t0, $t1, $t9
    ctx->r8 = ADD32(ctx->r9, ctx->r25);
    // 0x8008B044: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x8008B048: nop

    // 0x8008B04C: beq         $t8, $zero, L_8008B060
    if (ctx->r24 == 0) {
        // 0x8008B050: nop
    
            goto L_8008B060;
    }
    // 0x8008B050: nop

    // 0x8008B054: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x8008B058: b           L_8008BC70
    // 0x8008B05C: sb          $t6, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r14;
        goto L_8008BC70;
    // 0x8008B05C: sb          $t6, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r14;
L_8008B060:
    // 0x8008B060: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8008B064: lbu         $t2, 0x3BA0($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X3BA0);
    // 0x8008B068: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8008B06C: sll         $t5, $t2, 3
    ctx->r13 = S32(ctx->r10 << 3);
    // 0x8008B070: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x8008B074: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008B078: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x8008B07C: lw          $t7, 0x118($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X118);
    // 0x8008B080: lw          $t1, 0x11C($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X11C);
    // 0x8008B084: nop

    // 0x8008B088: sltu        $at, $t7, $t1
    ctx->r1 = ctx->r15 < ctx->r9 ? 1 : 0;
    // 0x8008B08C: bne         $at, $zero, L_8008B110
    if (ctx->r1 != 0) {
        // 0x8008B090: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8008B110;
    }
    // 0x8008B090: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008B094: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B098: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8008B09C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008B0A0: sb          $t9, -0x7220($at)
    MEM_B(-0X7220, ctx->r1) = ctx->r25;
    // 0x8008B0A4: sb          $zero, 0x27($t8)
    MEM_B(0X27, ctx->r24) = 0;
    // 0x8008B0A8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8008B0AC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8008B0B0: lbu         $t6, 0x3BA0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3BA0);
    // 0x8008B0B4: lbu         $t3, 0x3BA0($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3BA0);
    // 0x8008B0B8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8008B0BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008B0C0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008B0C4: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8008B0C8: sb          $zero, 0x3B98($at)
    MEM_B(0X3B98, ctx->r1) = 0;
    // 0x8008B0CC: addu        $t4, $t0, $t5
    ctx->r12 = ADD32(ctx->r8, ctx->r13);
    // 0x8008B0D0: sw          $zero, 0x20($t4)
    MEM_W(0X20, ctx->r12) = 0;
    // 0x8008B0D4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8008B0D8: lbu         $t9, 0x3BA0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X3BA0);
    // 0x8008B0DC: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8008B0E0: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x8008B0E4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008B0E8: addu        $t8, $t1, $t2
    ctx->r24 = ADD32(ctx->r9, ctx->r10);
    // 0x8008B0EC: sb          $t7, 0x354($t8)
    MEM_B(0X354, ctx->r24) = ctx->r15;
    // 0x8008B0F0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8008B0F4: lbu         $t0, 0x3BA0($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X3BA0);
    // 0x8008B0F8: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8008B0FC: sll         $t5, $t0, 1
    ctx->r13 = S32(ctx->r8 << 1);
    // 0x8008B100: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008B104: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x8008B108: b           L_8008BC70
    // 0x8008B10C: sb          $t6, 0x355($t4)
    MEM_B(0X355, ctx->r12) = ctx->r14;
        goto L_8008BC70;
    // 0x8008B10C: sb          $t6, 0x355($t4)
    MEM_B(0X355, ctx->r12) = ctx->r14;
L_8008B110:
    // 0x8008B110: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008B114: lbu         $t1, 0x3BA0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X3BA0);
    // 0x8008B118: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8008B11C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8008B120: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8008B124: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008B128: addu        $t7, $t9, $t2
    ctx->r15 = ADD32(ctx->r25, ctx->r10);
    // 0x8008B12C: lw          $t8, 0x118($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X118);
    // 0x8008B130: nop

    // 0x8008B134: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x8008B138: nop

    // 0x8008B13C: sb          $t0, 0x55($sp)
    MEM_B(0X55, ctx->r29) = ctx->r8;
    // 0x8008B140: lw          $t3, 0x118($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X118);
    // 0x8008B144: nop

    // 0x8008B148: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x8008B14C: sw          $t5, 0x118($t7)
    MEM_W(0X118, ctx->r15) = ctx->r13;
    // 0x8008B150: lbu         $t6, 0x55($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X55);
    // 0x8008B154: nop

    // 0x8008B158: andi        $t4, $t6, 0x80
    ctx->r12 = ctx->r14 & 0X80;
    // 0x8008B15C: beq         $t4, $zero, L_8008B180
    if (ctx->r12 == 0) {
        // 0x8008B160: nop
    
            goto L_8008B180;
    }
    // 0x8008B160: nop

    // 0x8008B164: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8008B168: lbu         $t9, 0x3BA0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X3BA0);
    // 0x8008B16C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008B170: andi        $t1, $t6, 0x7F
    ctx->r9 = ctx->r14 & 0X7F;
    // 0x8008B174: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8008B178: b           L_8008BC70
    // 0x8008B17C: sb          $t1, 0x3B98($at)
    MEM_B(0X3B98, ctx->r1) = ctx->r9;
        goto L_8008BC70;
    // 0x8008B17C: sb          $t1, 0x3B98($at)
    MEM_B(0X3B98, ctx->r1) = ctx->r9;
L_8008B180:
    // 0x8008B180: lbu         $t2, 0x55($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X55);
    // 0x8008B184: nop

    // 0x8008B188: andi        $t8, $t2, 0x40
    ctx->r24 = ctx->r10 & 0X40;
    // 0x8008B18C: beq         $t8, $zero, L_8008B23C
    if (ctx->r24 == 0) {
        // 0x8008B190: nop
    
            goto L_8008B23C;
    }
    // 0x8008B190: nop

    // 0x8008B194: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8008B198: lbu         $t3, 0x3BA0($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3BA0);
    // 0x8008B19C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8008B1A0: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x8008B1A4: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8008B1A8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008B1AC: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x8008B1B0: lw          $a0, 0x118($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X118);
    // 0x8008B1B4: jal         0x8008C0E0
    // 0x8008B1B8: nop

    Audio2_ReadS16LE(rdram, ctx);
        goto after_22;
    // 0x8008B1B8: nop

    after_22:
    // 0x8008B1BC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8008B1C0: lbu         $t6, 0x3BA0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3BA0);
    // 0x8008B1C4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8008B1C8: sll         $t1, $t6, 3
    ctx->r9 = S32(ctx->r14 << 3);
    // 0x8008B1CC: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x8008B1D0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008B1D4: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8008B1D8: addu        $t9, $t4, $t1
    ctx->r25 = ADD32(ctx->r12, ctx->r9);
    // 0x8008B1DC: lw          $t2, 0x118($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X118);
    // 0x8008B1E0: nop

    // 0x8008B1E4: addiu       $t8, $t2, 0x2
    ctx->r24 = ADD32(ctx->r10, 0X2);
    // 0x8008B1E8: sw          $t8, 0x118($t9)
    MEM_W(0X118, ctx->r25) = ctx->r24;
    // 0x8008B1EC: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8008B1F0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8008B1F4: andi        $t0, $t3, 0xFFFF
    ctx->r8 = ctx->r11 & 0XFFFF;
    // 0x8008B1F8: srl         $t5, $t0, 14
    ctx->r13 = S32(U32(ctx->r8) >> 14);
    // 0x8008B1FC: sb          $t5, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r13;
    // 0x8008B200: lbu         $t6, 0x57($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X57);
    // 0x8008B204: andi        $t7, $t0, 0x3FFF
    ctx->r15 = ctx->r8 & 0X3FFF;
    // 0x8008B208: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x8008B20C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8008B210: lw          $t2, 0x3B40($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3B40);
    // 0x8008B214: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x8008B218: sllv        $t4, $t7, $t6
    ctx->r12 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8008B21C: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x8008B220: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x8008B224: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x8008B228: jal         0x8008BCD8
    // 0x8008B22C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    Dcm_SetPitch_2(rdram, ctx);
        goto after_23;
    // 0x8008B22C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_23:
    // 0x8008B230: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B234: nop

    // 0x8008B238: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
L_8008B23C:
    // 0x8008B23C: lbu         $t3, 0x55($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X55);
    // 0x8008B240: nop

    // 0x8008B244: andi        $t5, $t3, 0x20
    ctx->r13 = ctx->r11 & 0X20;
    // 0x8008B248: beq         $t5, $zero, L_8008B300
    if (ctx->r13 == 0) {
        // 0x8008B24C: nop
    
            goto L_8008B300;
    }
    // 0x8008B24C: nop

    // 0x8008B250: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008B254: lbu         $t7, 0x3BA0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X3BA0);
    // 0x8008B258: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8008B25C: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x8008B260: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8008B264: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008B268: addu        $t1, $t0, $t6
    ctx->r9 = ADD32(ctx->r8, ctx->r14);
    // 0x8008B26C: lw          $t2, 0x118($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X118);
    // 0x8008B270: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8008B274: lbu         $t4, 0x0($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X0);
    // 0x8008B278: nop

    // 0x8008B27C: sb          $t4, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r12;
    // 0x8008B280: lw          $t8, 0x118($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X118);
    // 0x8008B284: nop

    // 0x8008B288: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008B28C: sw          $t9, 0x118($t1)
    MEM_W(0X118, ctx->r9) = ctx->r25;
    // 0x8008B290: lbu         $t5, 0x3BA0($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X3BA0);
    // 0x8008B294: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8008B298: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x8008B29C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8008B2A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008B2A4: addu        $t0, $t3, $t7
    ctx->r8 = ADD32(ctx->r11, ctx->r15);
    // 0x8008B2A8: lw          $t6, 0x110($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X110);
    // 0x8008B2AC: nop

    // 0x8008B2B0: lbu         $t2, 0x2($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X2);
    // 0x8008B2B4: nop

    // 0x8008B2B8: beq         $t2, $zero, L_8008B2E0
    if (ctx->r10 == 0) {
        // 0x8008B2BC: nop
    
            goto L_8008B2E0;
    }
    // 0x8008B2BC: nop

    // 0x8008B2C0: lbu         $t4, 0x1($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X1);
    // 0x8008B2C4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8008B2C8: sll         $t8, $t4, 1
    ctx->r24 = S32(ctx->r12 << 1);
    // 0x8008B2CC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008B2D0: lhu         $t9, -0x7528($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X7528);
    // 0x8008B2D4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B2D8: b           L_8008B300
    // 0x8008B2DC: sh          $t9, 0x24($t1)
    MEM_H(0X24, ctx->r9) = ctx->r25;
        goto L_8008B300;
    // 0x8008B2DC: sh          $t9, 0x24($t1)
    MEM_H(0X24, ctx->r9) = ctx->r25;
L_8008B2E0:
    // 0x8008B2E0: lbu         $t5, 0x3B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X3B);
    // 0x8008B2E4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8008B2E8: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x8008B2EC: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8008B2F0: lhu         $t7, -0x7528($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X7528);
    // 0x8008B2F4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B2F8: nop

    // 0x8008B2FC: sh          $t7, 0x24($t0)
    MEM_H(0X24, ctx->r8) = ctx->r15;
L_8008B300:
    // 0x8008B300: lbu         $t2, 0x55($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X55);
    // 0x8008B304: nop

    // 0x8008B308: andi        $t6, $t2, 0x10
    ctx->r14 = ctx->r10 & 0X10;
    // 0x8008B30C: beq         $t6, $zero, L_8008B370
    if (ctx->r14 == 0) {
        // 0x8008B310: nop
    
            goto L_8008B370;
    }
    // 0x8008B310: nop

    // 0x8008B314: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8008B318: lbu         $t8, 0x3BA0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X3BA0);
    // 0x8008B31C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8008B320: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8008B324: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008B328: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008B32C: addu        $t1, $t4, $t9
    ctx->r9 = ADD32(ctx->r12, ctx->r25);
    // 0x8008B330: lw          $t5, 0x118($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X118);
    // 0x8008B334: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B338: lbu         $t3, 0x0($t5)
    ctx->r11 = MEM_BU(ctx->r13, 0X0);
    // 0x8008B33C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8008B340: sra         $t7, $t3, 1
    ctx->r15 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8008B344: sb          $t7, 0x26($t0)
    MEM_B(0X26, ctx->r8) = ctx->r15;
    // 0x8008B348: lbu         $t6, 0x3BA0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3BA0);
    // 0x8008B34C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8008B350: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x8008B354: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8008B358: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008B35C: addu        $t4, $t2, $t8
    ctx->r12 = ADD32(ctx->r10, ctx->r24);
    // 0x8008B360: lw          $t9, 0x118($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X118);
    // 0x8008B364: nop

    // 0x8008B368: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8008B36C: sw          $t1, 0x118($t4)
    MEM_W(0X118, ctx->r12) = ctx->r9;
L_8008B370:
    // 0x8008B370: lbu         $t5, 0x55($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X55);
    // 0x8008B374: nop

    // 0x8008B378: andi        $t3, $t5, 0x8
    ctx->r11 = ctx->r13 & 0X8;
    // 0x8008B37C: beq         $t3, $zero, L_8008B55C
    if (ctx->r11 == 0) {
        // 0x8008B380: nop
    
            goto L_8008B55C;
    }
    // 0x8008B380: nop

    // 0x8008B384: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8008B388: lbu         $t0, 0x3BA0($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X3BA0);
    // 0x8008B38C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8008B390: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x8008B394: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x8008B398: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008B39C: addu        $t2, $t7, $t6
    ctx->r10 = ADD32(ctx->r15, ctx->r14);
    // 0x8008B3A0: lw          $t8, 0x118($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X118);
    // 0x8008B3A4: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8008B3A8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8008B3AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008B3B0: sb          $t9, 0x54($sp)
    MEM_B(0X54, ctx->r29) = ctx->r25;
    // 0x8008B3B4: lw          $t1, 0x118($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X118);
    // 0x8008B3B8: nop

    // 0x8008B3BC: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x8008B3C0: sw          $t4, 0x118($t2)
    MEM_W(0X118, ctx->r10) = ctx->r12;
    // 0x8008B3C4: lbu         $t3, 0x3BA0($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3BA0);
    // 0x8008B3C8: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8008B3CC: sll         $t0, $t3, 3
    ctx->r8 = S32(ctx->r11 << 3);
    // 0x8008B3D0: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x8008B3D4: lbu         $t6, 0x54($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X54);
    // 0x8008B3D8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8008B3DC: addu        $t7, $t5, $t0
    ctx->r15 = ADD32(ctx->r13, ctx->r8);
    // 0x8008B3E0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8008B3E4: lbu         $t9, 0x12C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X12C);
    // 0x8008B3E8: lw          $t4, 0x18($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X18);
    // 0x8008B3EC: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8008B3F0: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8008B3F4: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B3F8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008B3FC: addu        $t2, $t4, $t1
    ctx->r10 = ADD32(ctx->r12, ctx->r9);
    // 0x8008B400: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8008B404: sw          $t2, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r10;
    // 0x8008B408: lbu         $t6, 0x3BA0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3BA0);
    // 0x8008B40C: lbu         $t7, 0x56($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X56);
    // 0x8008B410: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8008B414: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8008B418: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8008B41C: lbu         $t0, 0x54($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X54);
    // 0x8008B420: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8008B424: addu        $t1, $t4, $t5
    ctx->r9 = ADD32(ctx->r12, ctx->r13);
    // 0x8008B428: sw          $t0, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->r8;
    // 0x8008B42C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B430: nop

    // 0x8008B434: lbu         $t3, 0x27($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X27);
    // 0x8008B438: nop

    // 0x8008B43C: bne         $t3, $at, L_8008B55C
    if (ctx->r11 != ctx->r1) {
        // 0x8008B440: nop
    
            goto L_8008B55C;
    }
    // 0x8008B440: nop

    // 0x8008B444: lw          $t6, 0x8($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X8);
    // 0x8008B448: nop

    // 0x8008B44C: beq         $t6, $zero, L_8008B55C
    if (ctx->r14 == 0) {
        // 0x8008B450: nop
    
            goto L_8008B55C;
    }
    // 0x8008B450: nop

    // 0x8008B454: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8008B458: addiu       $t8, $zero, 0x240
    ctx->r24 = ADD32(0, 0X240);
    // 0x8008B45C: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8008B460: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x8008B464: jal         0x8008ED04
    // 0x8008B468: sw          $t8, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->r24;
    __allocParam(rdram, ctx);
        goto after_24;
    // 0x8008B468: sw          $t8, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->r24;
    after_24:
    // 0x8008B46C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8008B470: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8008B474: nop

    // 0x8008B478: beq         $t4, $zero, L_8008B4EC
    if (ctx->r12 == 0) {
        // 0x8008B47C: nop
    
            goto L_8008B4EC;
    }
    // 0x8008B47C: nop

    // 0x8008B480: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8008B484: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8008B488: lw          $t0, 0x14($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X14);
    // 0x8008B48C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008B490: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x8008B494: nop

    // 0x8008B498: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x8008B49C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8008B4A0: nop

    // 0x8008B4A4: sh          $t3, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r11;
    // 0x8008B4A8: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8008B4AC: nop

    // 0x8008B4B0: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    // 0x8008B4B4: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B4B8: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8008B4BC: lw          $t8, 0x8($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X8);
    // 0x8008B4C0: nop

    // 0x8008B4C4: lw          $t9, 0xD8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XD8);
    // 0x8008B4C8: nop

    // 0x8008B4CC: addiu       $t5, $t9, -0x40
    ctx->r13 = ADD32(ctx->r25, -0X40);
    // 0x8008B4D0: sw          $t5, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r13;
    // 0x8008B4D4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8008B4D8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008B4DC: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x8008B4E0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8008B4E4: jalr        $t9
    // 0x8008B4E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_25;
    // 0x8008B4E8: nop

    after_25:
L_8008B4EC:
    // 0x8008B4EC: jal         0x8008ED04
    // 0x8008B4F0: nop

    __allocParam(rdram, ctx);
        goto after_26;
    // 0x8008B4F0: nop

    after_26:
    // 0x8008B4F4: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8008B4F8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8008B4FC: nop

    // 0x8008B500: beq         $t4, $zero, L_8008B55C
    if (ctx->r12 == 0) {
        // 0x8008B504: nop
    
            goto L_8008B55C;
    }
    // 0x8008B504: nop

    // 0x8008B508: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8008B50C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B510: lw          $t6, 0x14($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X14);
    // 0x8008B514: lw          $t8, 0x8($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X8);
    // 0x8008B518: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x8008B51C: lw          $t5, 0xD8($t8)
    ctx->r13 = MEM_W(ctx->r24, 0XD8);
    // 0x8008B520: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8008B524: addu        $t0, $t7, $t5
    ctx->r8 = ADD32(ctx->r15, ctx->r13);
    // 0x8008B528: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x8008B52C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8008B530: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008B534: sh          $t1, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r9;
    // 0x8008B538: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8008B53C: nop

    // 0x8008B540: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8008B544: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8008B548: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008B54C: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x8008B550: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8008B554: jalr        $t9
    // 0x8008B558: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_27;
    // 0x8008B558: nop

    after_27:
L_8008B55C:
    // 0x8008B55C: lbu         $t2, 0x55($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X55);
    // 0x8008B560: nop

    // 0x8008B564: andi        $t8, $t2, 0x4
    ctx->r24 = ctx->r10 & 0X4;
    // 0x8008B568: beq         $t8, $zero, L_8008B680
    if (ctx->r24 == 0) {
        // 0x8008B56C: nop
    
            goto L_8008B680;
    }
    // 0x8008B56C: nop

    // 0x8008B570: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8008B574: lbu         $t5, 0x3BA0($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X3BA0);
    // 0x8008B578: lbu         $t1, 0x56($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X56);
    // 0x8008B57C: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x8008B580: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8008B584: addu        $t6, $t1, $t3
    ctx->r14 = ADD32(ctx->r9, ctx->r11);
    // 0x8008B588: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8008B58C: sll         $t0, $t5, 3
    ctx->r8 = S32(ctx->r13 << 3);
    // 0x8008B590: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x8008B594: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x8008B598: lw          $t8, 0xD0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XD0);
    // 0x8008B59C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8008B5A0: addu        $t4, $t7, $t0
    ctx->r12 = ADD32(ctx->r15, ctx->r8);
    // 0x8008B5A4: addu        $t0, $t4, $t8
    ctx->r8 = ADD32(ctx->r12, ctx->r24);
    // 0x8008B5A8: lbu         $t5, 0x12C($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X12C);
    // 0x8008B5AC: lw          $t2, 0x118($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X118);
    // 0x8008B5B0: lw          $t3, 0x18($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X18);
    // 0x8008B5B4: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x8008B5B8: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B5BC: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x8008B5C0: addu        $t6, $t3, $t1
    ctx->r14 = ADD32(ctx->r11, ctx->r9);
    // 0x8008B5C4: lw          $t9, 0x528($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X528);
    // 0x8008B5C8: lw          $t3, 0x1C($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X1C);
    // 0x8008B5CC: sll         $t0, $t8, 8
    ctx->r8 = S32(ctx->r24 << 8);
    // 0x8008B5D0: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
    // 0x8008B5D4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8008B5D8: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8008B5DC: lbu         $t6, 0x3BA0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3BA0);
    // 0x8008B5E0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8008B5E4: sll         $t4, $t6, 3
    ctx->r12 = S32(ctx->r14 << 3);
    // 0x8008B5E8: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8008B5EC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008B5F0: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x8008B5F4: lw          $t8, 0x118($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X118);
    // 0x8008B5F8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008B5FC: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8008B600: sw          $t0, 0x118($t2)
    MEM_W(0X118, ctx->r10) = ctx->r8;
    // 0x8008B604: lbu         $t7, 0x3BA0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X3BA0);
    // 0x8008B608: lbu         $t6, 0x56($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X56);
    // 0x8008B60C: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x8008B610: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8008B614: addu        $t4, $t6, $t1
    ctx->r12 = ADD32(ctx->r14, ctx->r9);
    // 0x8008B618: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8008B61C: sll         $t5, $t7, 3
    ctx->r13 = S32(ctx->r15 << 3);
    // 0x8008B620: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8008B624: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x8008B628: lw          $t2, 0xD0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XD0);
    // 0x8008B62C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008B630: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x8008B634: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x8008B638: lbu         $t7, 0x12C($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X12C);
    // 0x8008B63C: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8008B640: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8008B644: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x8008B648: lw          $t8, 0x630($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X630);
    // 0x8008B64C: addu        $t0, $t3, $t2
    ctx->r8 = ADD32(ctx->r11, ctx->r10);
    // 0x8008B650: lbu         $t5, 0x12C($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X12C);
    // 0x8008B654: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B658: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8008B65C: lw          $t3, 0x1C($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X1C);
    // 0x8008B660: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x8008B664: lw          $t6, 0x528($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X528);
    // 0x8008B668: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x8008B66C: nop

    // 0x8008B670: subu        $t0, $t2, $t6
    ctx->r8 = SUB32(ctx->r10, ctx->r14);
    // 0x8008B674: subu        $t5, $t8, $t0
    ctx->r13 = SUB32(ctx->r24, ctx->r8);
    // 0x8008B678: b           L_8008B748
    // 0x8008B67C: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
        goto L_8008B748;
    // 0x8008B67C: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
L_8008B680:
    // 0x8008B680: lbu         $t1, 0x55($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X55);
    // 0x8008B684: nop

    // 0x8008B688: andi        $t7, $t1, 0x2
    ctx->r15 = ctx->r9 & 0X2;
    // 0x8008B68C: beq         $t7, $zero, L_8008B748
    if (ctx->r15 == 0) {
        // 0x8008B690: nop
    
            goto L_8008B748;
    }
    // 0x8008B690: nop

    // 0x8008B694: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8008B698: lbu         $t4, 0x3BA0($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X3BA0);
    // 0x8008B69C: lbu         $t8, 0x56($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X56);
    // 0x8008B6A0: sll         $t0, $t4, 1
    ctx->r8 = S32(ctx->r12 << 1);
    // 0x8008B6A4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8008B6A8: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x8008B6AC: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8008B6B0: sll         $t2, $t4, 3
    ctx->r10 = S32(ctx->r12 << 3);
    // 0x8008B6B4: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8008B6B8: addu        $t1, $t9, $t3
    ctx->r9 = ADD32(ctx->r25, ctx->r11);
    // 0x8008B6BC: lw          $t7, 0xD0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0XD0);
    // 0x8008B6C0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008B6C4: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8008B6C8: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x8008B6CC: lbu         $t4, 0x12C($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X12C);
    // 0x8008B6D0: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x8008B6D4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B6D8: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8008B6DC: addu        $t5, $t0, $t8
    ctx->r13 = ADD32(ctx->r8, ctx->r24);
    // 0x8008B6E0: lw          $t3, 0x528($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X528);
    // 0x8008B6E4: lw          $t6, 0x1C($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X1C);
    // 0x8008B6E8: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8008B6EC: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8008B6F0: lbu         $t2, 0x3BA0($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X3BA0);
    // 0x8008B6F4: lbu         $t0, 0x56($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X56);
    // 0x8008B6F8: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x8008B6FC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8008B700: addu        $t5, $t0, $t8
    ctx->r13 = ADD32(ctx->r8, ctx->r24);
    // 0x8008B704: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x8008B708: sll         $t4, $t2, 3
    ctx->r12 = S32(ctx->r10 << 3);
    // 0x8008B70C: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x8008B710: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x8008B714: lw          $t6, 0xD0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0XD0);
    // 0x8008B718: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008B71C: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x8008B720: addu        $t4, $t9, $t6
    ctx->r12 = ADD32(ctx->r25, ctx->r14);
    // 0x8008B724: lbu         $t2, 0x12C($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X12C);
    // 0x8008B728: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8008B72C: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B730: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8008B734: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x8008B738: lw          $t1, 0x630($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X630);
    // 0x8008B73C: lw          $t9, 0x1C($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X1C);
    // 0x8008B740: nop

    // 0x8008B744: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
L_8008B748:
    // 0x8008B748: lbu         $t6, 0x55($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X55);
    // 0x8008B74C: nop

    // 0x8008B750: andi        $t4, $t6, 0x2
    ctx->r12 = ctx->r14 & 0X2;
    // 0x8008B754: beq         $t4, $zero, L_8008B8F8
    if (ctx->r12 == 0) {
        // 0x8008B758: nop
    
            goto L_8008B8F8;
    }
    // 0x8008B758: nop

    // 0x8008B75C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B760: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008B764: lbu         $t7, 0x27($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X27);
    // 0x8008B768: nop

    // 0x8008B76C: bne         $t7, $at, L_8008B88C
    if (ctx->r15 != ctx->r1) {
        // 0x8008B770: nop
    
            goto L_8008B88C;
    }
    // 0x8008B770: nop

    // 0x8008B774: lw          $t8, 0x8($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X8);
    // 0x8008B778: nop

    // 0x8008B77C: beq         $t8, $zero, L_8008B88C
    if (ctx->r24 == 0) {
        // 0x8008B780: nop
    
            goto L_8008B88C;
    }
    // 0x8008B780: nop

    // 0x8008B784: lw          $t0, 0xC($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC);
    // 0x8008B788: addiu       $t5, $zero, 0x240
    ctx->r13 = ADD32(0, 0X240);
    // 0x8008B78C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8008B790: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8008B794: jal         0x8008ED04
    // 0x8008B798: sw          $t5, 0xD8($t3)
    MEM_W(0XD8, ctx->r11) = ctx->r13;
    __allocParam(rdram, ctx);
        goto after_28;
    // 0x8008B798: sw          $t5, 0xD8($t3)
    MEM_W(0XD8, ctx->r11) = ctx->r13;
    after_28:
    // 0x8008B79C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8008B7A0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8008B7A4: nop

    // 0x8008B7A8: beq         $t1, $zero, L_8008B81C
    if (ctx->r9 == 0) {
        // 0x8008B7AC: nop
    
            goto L_8008B81C;
    }
    // 0x8008B7AC: nop

    // 0x8008B7B0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8008B7B4: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8008B7B8: lw          $t6, 0x14($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X14);
    // 0x8008B7BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008B7C0: lw          $t4, 0x1C($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X1C);
    // 0x8008B7C4: nop

    // 0x8008B7C8: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x8008B7CC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8008B7D0: nop

    // 0x8008B7D4: sh          $t7, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r15;
    // 0x8008B7D8: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8008B7DC: nop

    // 0x8008B7E0: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x8008B7E4: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B7E8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8008B7EC: lw          $t5, 0x8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8);
    // 0x8008B7F0: nop

    // 0x8008B7F4: lw          $t3, 0xD8($t5)
    ctx->r11 = MEM_W(ctx->r13, 0XD8);
    // 0x8008B7F8: nop

    // 0x8008B7FC: addiu       $t9, $t3, -0x40
    ctx->r25 = ADD32(ctx->r11, -0X40);
    // 0x8008B800: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8008B804: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8008B808: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008B80C: lw          $t9, 0x8($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X8);
    // 0x8008B810: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8008B814: jalr        $t9
    // 0x8008B818: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_29;
    // 0x8008B818: nop

    after_29:
L_8008B81C:
    // 0x8008B81C: jal         0x8008ED04
    // 0x8008B820: nop

    __allocParam(rdram, ctx);
        goto after_30;
    // 0x8008B820: nop

    after_30:
    // 0x8008B824: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8008B828: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8008B82C: nop

    // 0x8008B830: beq         $t1, $zero, L_8008B88C
    if (ctx->r9 == 0) {
        // 0x8008B834: nop
    
            goto L_8008B88C;
    }
    // 0x8008B834: nop

    // 0x8008B838: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8008B83C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B840: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8008B844: lw          $t5, 0x8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8);
    // 0x8008B848: lw          $t0, 0x1C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X1C);
    // 0x8008B84C: lw          $t3, 0xD8($t5)
    ctx->r11 = MEM_W(ctx->r13, 0XD8);
    // 0x8008B850: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x8008B854: addu        $t6, $t0, $t3
    ctx->r14 = ADD32(ctx->r8, ctx->r11);
    // 0x8008B858: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8008B85C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8008B860: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008B864: sh          $t4, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r12;
    // 0x8008B868: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8008B86C: nop

    // 0x8008B870: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8008B874: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8008B878: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008B87C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8008B880: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8008B884: jalr        $t9
    // 0x8008B888: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_31;
    // 0x8008B888: nop

    after_31:
L_8008B88C:
    // 0x8008B88C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8008B890: nop

    // 0x8008B894: lw          $t5, 0x14($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X14);
    // 0x8008B898: nop

    // 0x8008B89C: beq         $t5, $zero, L_8008B8EC
    if (ctx->r13 == 0) {
        // 0x8008B8A0: nop
    
            goto L_8008B8EC;
    }
    // 0x8008B8A0: nop

    // 0x8008B8A4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B8A8: nop

    // 0x8008B8AC: lw          $t3, 0x1C($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X1C);
    // 0x8008B8B0: nop

    // 0x8008B8B4: beq         $t3, $zero, L_8008B8EC
    if (ctx->r11 == 0) {
        // 0x8008B8B8: nop
    
            goto L_8008B8EC;
    }
    // 0x8008B8B8: nop

    // 0x8008B8BC: lh          $t6, 0x24($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X24);
    // 0x8008B8C0: lw          $a3, 0x20($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X20);
    // 0x8008B8C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008B8C8: lb          $t1, 0x26($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X26);
    // 0x8008B8CC: addiu       $t4, $zero, 0x1F4
    ctx->r12 = ADD32(0, 0X1F4);
    // 0x8008B8D0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8008B8D4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008B8D8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8008B8DC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8008B8E0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8008B8E4: jal         0x800B8DC0
    // 0x8008B8E8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    alSynStartVoiceParams(rdram, ctx);
        goto after_32;
    // 0x8008B8E8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_32:
L_8008B8EC:
    // 0x8008B8EC: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B8F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008B8F4: sb          $t7, 0x27($t8)
    MEM_B(0X27, ctx->r24) = ctx->r15;
L_8008B8F8:
    // 0x8008B8F8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B8FC: nop

    // 0x8008B900: lbu         $t2, 0x27($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X27);
    // 0x8008B904: nop

    // 0x8008B908: beq         $t2, $zero, L_8008B944
    if (ctx->r10 == 0) {
        // 0x8008B90C: nop
    
            goto L_8008B944;
    }
    // 0x8008B90C: nop

    // 0x8008B910: lbu         $t5, 0x55($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X55);
    // 0x8008B914: nop

    // 0x8008B918: andi        $t3, $t5, 0x40
    ctx->r11 = ctx->r13 & 0X40;
    // 0x8008B91C: beq         $t3, $zero, L_8008B944
    if (ctx->r11 == 0) {
        // 0x8008B920: nop
    
            goto L_8008B944;
    }
    // 0x8008B920: nop

    // 0x8008B924: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x8008B928: bne         $t6, $zero, L_8008B944
    if (ctx->r14 != 0) {
        // 0x8008B92C: nop
    
            goto L_8008B944;
    }
    // 0x8008B92C: nop

    // 0x8008B930: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8008B934: lw          $a2, 0x20($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X20);
    // 0x8008B938: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x8008B93C: jal         0x800B8EB0
    // 0x8008B940: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    alSynSetPitch(rdram, ctx);
        goto after_33;
    // 0x8008B940: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_33:
L_8008B944:
    // 0x8008B944: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B948: nop

    // 0x8008B94C: lbu         $t4, 0x27($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X27);
    // 0x8008B950: nop

    // 0x8008B954: beq         $t4, $zero, L_8008B994
    if (ctx->r12 == 0) {
        // 0x8008B958: nop
    
            goto L_8008B994;
    }
    // 0x8008B958: nop

    // 0x8008B95C: lbu         $t7, 0x55($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X55);
    // 0x8008B960: nop

    // 0x8008B964: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x8008B968: beq         $t8, $zero, L_8008B994
    if (ctx->r24 == 0) {
        // 0x8008B96C: nop
    
            goto L_8008B994;
    }
    // 0x8008B96C: nop

    // 0x8008B970: andi        $t2, $t7, 0x2
    ctx->r10 = ctx->r15 & 0X2;
    // 0x8008B974: bne         $t2, $zero, L_8008B994
    if (ctx->r10 != 0) {
        // 0x8008B978: nop
    
            goto L_8008B994;
    }
    // 0x8008B978: nop

    // 0x8008B97C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8008B980: lh          $a2, 0x24($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X24);
    // 0x8008B984: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    // 0x8008B988: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8008B98C: jal         0x8008E5A0
    // 0x8008B990: addiu       $a3, $zero, 0x1F4
    ctx->r7 = ADD32(0, 0X1F4);
    alSynSetVol(rdram, ctx);
        goto after_34;
    // 0x8008B990: addiu       $a3, $zero, 0x1F4
    ctx->r7 = ADD32(0, 0X1F4);
    after_34:
L_8008B994:
    // 0x8008B994: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B998: nop

    // 0x8008B99C: lbu         $t6, 0x27($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X27);
    // 0x8008B9A0: nop

    // 0x8008B9A4: beq         $t6, $zero, L_8008B9E0
    if (ctx->r14 == 0) {
        // 0x8008B9A8: nop
    
            goto L_8008B9E0;
    }
    // 0x8008B9A8: nop

    // 0x8008B9AC: lbu         $t0, 0x55($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X55);
    // 0x8008B9B0: nop

    // 0x8008B9B4: andi        $t9, $t0, 0x10
    ctx->r25 = ctx->r8 & 0X10;
    // 0x8008B9B8: beq         $t9, $zero, L_8008B9E0
    if (ctx->r25 == 0) {
        // 0x8008B9BC: nop
    
            goto L_8008B9E0;
    }
    // 0x8008B9BC: nop

    // 0x8008B9C0: andi        $t4, $t0, 0x2
    ctx->r12 = ctx->r8 & 0X2;
    // 0x8008B9C4: bne         $t4, $zero, L_8008B9E0
    if (ctx->r12 != 0) {
        // 0x8008B9C8: nop
    
            goto L_8008B9E0;
    }
    // 0x8008B9C8: nop

    // 0x8008B9CC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8008B9D0: lb          $a2, 0x26($t5)
    ctx->r6 = MEM_B(ctx->r13, 0X26);
    // 0x8008B9D4: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x8008B9D8: jal         0x800B8D30
    // 0x8008B9DC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    alSynSetPan(rdram, ctx);
        goto after_35;
    // 0x8008B9DC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_35:
L_8008B9E0:
    // 0x8008B9E0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8008B9E4: nop

    // 0x8008B9E8: lbu         $t2, 0x27($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X27);
    // 0x8008B9EC: nop

    // 0x8008B9F0: beq         $t2, $zero, L_8008BA60
    if (ctx->r10 == 0) {
        // 0x8008B9F4: nop
    
            goto L_8008BA60;
    }
    // 0x8008B9F4: nop

    // 0x8008B9F8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008B9FC: lbu         $t1, 0x3BA0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X3BA0);
    // 0x8008BA00: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8008BA04: sll         $t6, $t1, 3
    ctx->r14 = S32(ctx->r9 << 3);
    // 0x8008BA08: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8008BA0C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008BA10: addu        $t9, $t3, $t6
    ctx->r25 = ADD32(ctx->r11, ctx->r14);
    // 0x8008BA14: lw          $t0, 0x110($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X110);
    // 0x8008BA18: nop

    // 0x8008BA1C: lbu         $t4, 0x2($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X2);
    // 0x8008BA20: nop

    // 0x8008BA24: beq         $t4, $zero, L_8008BA60
    if (ctx->r12 == 0) {
        // 0x8008BA28: nop
    
            goto L_8008BA60;
    }
    // 0x8008BA28: nop

    // 0x8008BA2C: lbu         $t8, 0x1($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X1);
    // 0x8008BA30: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8008BA34: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x8008BA38: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x8008BA3C: lhu         $t2, -0x7528($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X7528);
    // 0x8008BA40: addiu       $a3, $zero, 0x1F4
    ctx->r7 = ADD32(0, 0X1F4);
    // 0x8008BA44: sh          $t2, 0x24($t7)
    MEM_H(0X24, ctx->r15) = ctx->r10;
    // 0x8008BA48: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8008BA4C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8008BA50: lh          $a2, 0x24($t3)
    ctx->r6 = MEM_H(ctx->r11, 0X24);
    // 0x8008BA54: lw          $a0, 0x14($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X14);
    // 0x8008BA58: jal         0x8008E5A0
    // 0x8008BA5C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    alSynSetVol(rdram, ctx);
        goto after_36;
    // 0x8008BA5C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_36:
L_8008BA60:
    // 0x8008BA60: lbu         $t6, 0x55($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X55);
    // 0x8008BA64: nop

    // 0x8008BA68: andi        $t9, $t6, 0x1
    ctx->r25 = ctx->r14 & 0X1;
    // 0x8008BA6C: beq         $t9, $zero, L_8008BC70
    if (ctx->r25 == 0) {
        // 0x8008BA70: nop
    
            goto L_8008BC70;
    }
    // 0x8008BA70: nop

    // 0x8008BA74: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8008BA78: lbu         $t0, 0x3BA0($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X3BA0);
    // 0x8008BA7C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8008BA80: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
    // 0x8008BA84: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x8008BA88: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008BA8C: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    // 0x8008BA90: lw          $t2, 0x118($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X118);
    // 0x8008BA94: nop

    // 0x8008BA98: lbu         $t7, 0x0($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X0);
    // 0x8008BA9C: nop

    // 0x8008BAA0: sb          $t7, 0x55($sp)
    MEM_B(0X55, ctx->r29) = ctx->r15;
    // 0x8008BAA4: lw          $t1, 0x118($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X118);
    // 0x8008BAA8: nop

    // 0x8008BAAC: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8008BAB0: sw          $t3, 0x118($t5)
    MEM_W(0X118, ctx->r13) = ctx->r11;
    // 0x8008BAB4: lbu         $t6, 0x55($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X55);
    // 0x8008BAB8: nop

    // 0x8008BABC: andi        $t9, $t6, 0x40
    ctx->r25 = ctx->r14 & 0X40;
    // 0x8008BAC0: beq         $t9, $zero, L_8008BB98
    if (ctx->r25 == 0) {
        // 0x8008BAC4: nop
    
            goto L_8008BB98;
    }
    // 0x8008BAC4: nop

    // 0x8008BAC8: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8008BACC: lbu         $t4, 0x3BA0($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X3BA0);
    // 0x8008BAD0: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8008BAD4: sll         $t8, $t4, 3
    ctx->r24 = S32(ctx->r12 << 3);
    // 0x8008BAD8: addu        $t8, $t8, $t4
    ctx->r24 = ADD32(ctx->r24, ctx->r12);
    // 0x8008BADC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008BAE0: addu        $t2, $t0, $t8
    ctx->r10 = ADD32(ctx->r8, ctx->r24);
    // 0x8008BAE4: lw          $t7, 0x118($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X118);
    // 0x8008BAE8: nop

    // 0x8008BAEC: lbu         $t1, 0x0($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X0);
    // 0x8008BAF0: nop

    // 0x8008BAF4: beq         $t1, $zero, L_8008BB60
    if (ctx->r9 == 0) {
        // 0x8008BAF8: nop
    
            goto L_8008BB60;
    }
    // 0x8008BAF8: nop

    // 0x8008BAFC: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8008BB00: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8008BB04: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8008BB08: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8008BB0C: lui         $t5, 0x773
    ctx->r13 = S32(0X773 << 16);
    // 0x8008BB10: ori         $t5, $t5, 0x5940
    ctx->r13 = ctx->r13 | 0X5940;
    // 0x8008BB14: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8008BB18: div         $zero, $t5, $t3
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r11)));
    // 0x8008BB1C: bne         $t3, $zero, L_8008BB28
    if (ctx->r11 != 0) {
        // 0x8008BB20: nop
    
            goto L_8008BB28;
    }
    // 0x8008BB20: nop

    // 0x8008BB24: break       7
    do_break(2148055844);
L_8008BB28:
    // 0x8008BB28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008BB2C: bne         $t3, $at, L_8008BB40
    if (ctx->r11 != ctx->r1) {
        // 0x8008BB30: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008BB40;
    }
    // 0x8008BB30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008BB34: bne         $t5, $at, L_8008BB40
    if (ctx->r13 != ctx->r1) {
        // 0x8008BB38: nop
    
            goto L_8008BB40;
    }
    // 0x8008BB38: nop

    // 0x8008BB3C: break       6
    do_break(2148055868);
L_8008BB40:
    // 0x8008BB40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008BB44: mflo        $t6
    ctx->r14 = lo;
    // 0x8008BB48: sw          $t6, 0x3940($at)
    MEM_W(0X3940, ctx->r1) = ctx->r14;
    // 0x8008BB4C: lw          $t9, 0x118($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X118);
    // 0x8008BB50: nop

    // 0x8008BB54: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x8008BB58: b           L_8008BB98
    // 0x8008BB5C: sw          $t4, 0x118($t2)
    MEM_W(0X118, ctx->r10) = ctx->r12;
        goto L_8008BB98;
    // 0x8008BB5C: sw          $t4, 0x118($t2)
    MEM_W(0X118, ctx->r10) = ctx->r12;
L_8008BB60:
    // 0x8008BB60: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008BB64: jal         0x800B3BFC
    // 0x8008BB68: addiu       $a0, $a0, -0x650
    ctx->r4 = ADD32(ctx->r4, -0X650);
    rmonPrintf_recomp(rdram, ctx);
        goto after_37;
    // 0x8008BB68: addiu       $a0, $a0, -0x650
    ctx->r4 = ADD32(ctx->r4, -0X650);
    after_37:
    // 0x8008BB6C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8008BB70: lbu         $t8, 0x3BA0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X3BA0);
    // 0x8008BB74: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8008BB78: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x8008BB7C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8008BB80: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008BB84: addu        $t1, $t0, $t7
    ctx->r9 = ADD32(ctx->r8, ctx->r15);
    // 0x8008BB88: lw          $t5, 0x118($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X118);
    // 0x8008BB8C: nop

    // 0x8008BB90: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x8008BB94: sw          $t3, 0x118($t1)
    MEM_W(0X118, ctx->r9) = ctx->r11;
L_8008BB98:
    // 0x8008BB98: lbu         $t6, 0x55($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X55);
    // 0x8008BB9C: nop

    // 0x8008BBA0: andi        $t9, $t6, 0x20
    ctx->r25 = ctx->r14 & 0X20;
    // 0x8008BBA4: beq         $t9, $zero, L_8008BC70
    if (ctx->r25 == 0) {
        // 0x8008BBA8: nop
    
            goto L_8008BC70;
    }
    // 0x8008BBA8: nop

    // 0x8008BBAC: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8008BBB0: lbu         $t2, 0x3BA0($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X3BA0);
    // 0x8008BBB4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8008BBB8: sll         $t8, $t2, 3
    ctx->r24 = S32(ctx->r10 << 3);
    // 0x8008BBBC: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8008BBC0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008BBC4: addu        $t0, $t4, $t8
    ctx->r8 = ADD32(ctx->r12, ctx->r24);
    // 0x8008BBC8: lw          $t7, 0x118($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X118);
    // 0x8008BBCC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8008BBD0: lbu         $t5, 0x0($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X0);
    // 0x8008BBD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008BBD8: sb          $t5, 0x55($sp)
    MEM_B(0X55, ctx->r29) = ctx->r13;
    // 0x8008BBDC: lw          $t3, 0x118($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X118);
    // 0x8008BBE0: nop

    // 0x8008BBE4: addiu       $t1, $t3, 0x1
    ctx->r9 = ADD32(ctx->r11, 0X1);
    // 0x8008BBE8: sw          $t1, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->r9;
    // 0x8008BBEC: lbu         $t9, 0x3BA0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X3BA0);
    // 0x8008BBF0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008BBF4: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x8008BBF8: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8008BBFC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008BC00: addu        $t4, $t6, $t2
    ctx->r12 = ADD32(ctx->r14, ctx->r10);
    // 0x8008BC04: lw          $t8, 0x110($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X110);
    // 0x8008BC08: nop

    // 0x8008BC0C: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x8008BC10: nop

    // 0x8008BC14: bne         $t7, $at, L_8008BC70
    if (ctx->r15 != ctx->r1) {
        // 0x8008BC18: nop
    
            goto L_8008BC70;
    }
    // 0x8008BC18: nop

    // 0x8008BC1C: lbu         $t5, 0x55($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X55);
    // 0x8008BC20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008BC24: bne         $t5, $at, L_8008BC38
    if (ctx->r13 != ctx->r1) {
        // 0x8008BC28: nop
    
            goto L_8008BC38;
    }
    // 0x8008BC28: nop

    // 0x8008BC2C: lw          $t3, 0x118($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X118);
    // 0x8008BC30: nop

    // 0x8008BC34: sw          $t3, 0x120($t4)
    MEM_W(0X120, ctx->r12) = ctx->r11;
L_8008BC38:
    // 0x8008BC38: lbu         $t1, 0x55($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X55);
    // 0x8008BC3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008BC40: bne         $t1, $at, L_8008BC70
    if (ctx->r9 != ctx->r1) {
        // 0x8008BC44: nop
    
            goto L_8008BC70;
    }
    // 0x8008BC44: nop

    // 0x8008BC48: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8008BC4C: lbu         $t9, 0x3BA0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X3BA0);
    // 0x8008BC50: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8008BC54: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x8008BC58: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8008BC5C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008BC60: addu        $t2, $t0, $t6
    ctx->r10 = ADD32(ctx->r8, ctx->r14);
    // 0x8008BC64: lw          $t8, 0x120($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X120);
    // 0x8008BC68: nop

    // 0x8008BC6C: sw          $t8, 0x118($t2)
    MEM_W(0X118, ctx->r10) = ctx->r24;
L_8008BC70:
    // 0x8008BC70: lbu         $t7, 0x56($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X56);
    // 0x8008BC74: nop

    // 0x8008BC78: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x8008BC7C: andi        $t3, $t5, 0xFF
    ctx->r11 = ctx->r13 & 0XFF;
    // 0x8008BC80: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8008BC84: bne         $at, $zero, L_8008B000
    if (ctx->r1 != 0) {
        // 0x8008BC88: sb          $t5, 0x56($sp)
        MEM_B(0X56, ctx->r29) = ctx->r13;
            goto L_8008B000;
    }
    // 0x8008BC88: sb          $t5, 0x56($sp)
    MEM_B(0X56, ctx->r29) = ctx->r13;
L_8008BC8C:
    // 0x8008BC8C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8008BC90: lbu         $t4, 0x3BA0($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X3BA0);
    // 0x8008BC94: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8008BC98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008BC9C: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8008BCA0: sb          $t1, 0x3BA0($at)
    MEM_B(0X3BA0, ctx->r1) = ctx->r9;
    // 0x8008BCA4: lw          $t6, 0x8C($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8C);
    // 0x8008BCA8: andi        $t9, $t1, 0xFF
    ctx->r25 = ctx->r9 & 0XFF;
    // 0x8008BCAC: srl         $t8, $t6, 1
    ctx->r24 = S32(U32(ctx->r14) >> 1);
    // 0x8008BCB0: sltu        $at, $t9, $t8
    ctx->r1 = ctx->r25 < ctx->r24 ? 1 : 0;
    // 0x8008BCB4: bne         $at, $zero, L_8008AF90
    if (ctx->r1 != 0) {
        // 0x8008BCB8: nop
    
            goto L_8008AF90;
    }
    // 0x8008BCB8: nop

L_8008BCBC:
    // 0x8008BCBC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8008BCC0: lw          $v0, 0x3940($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3940);
    // 0x8008BCC4: nop

L_8008BCC8:
    // 0x8008BCC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008BCCC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8008BCD0: jr          $ra
    // 0x8008BCD4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8008BCD4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}

RECOMP_FUNC void Dcm_SetPitch_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BCD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008BCDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008BCE0: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x8008BCE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BCE8: bgtz        $t6, L_8008BCFC
    if (SIGNED(ctx->r14) > 0) {
        // 0x8008BCEC: nop
    
            goto L_8008BCFC;
    }
    // 0x8008BCEC: nop

    // 0x8008BCF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8008BCF4: b           L_8008BE08
    // 0x8008BCF8: nop

        goto L_8008BE08;
    // 0x8008BCF8: nop

L_8008BCFC:
    // 0x8008BCFC: lh          $t7, 0x22($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X22);
    // 0x8008BD00: lui         $t8, 0xDA
    ctx->r24 = S32(0XDA << 16);
    // 0x8008BD04: ori         $t8, $t8, 0x7A68
    ctx->r24 = ctx->r24 | 0X7A68;
    // 0x8008BD08: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x8008BD0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BD10: lwc1        $f5, -0x508($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X508);
    // 0x8008BD14: lwc1        $f4, -0x504($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X504);
    // 0x8008BD18: bne         $t7, $zero, L_8008BD24
    if (ctx->r15 != 0) {
        // 0x8008BD1C: nop
    
            goto L_8008BD24;
    }
    // 0x8008BD1C: nop

    // 0x8008BD20: break       7
    do_break(2148056352);
L_8008BD24:
    // 0x8008BD24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008BD28: bne         $t7, $at, L_8008BD3C
    if (ctx->r15 != ctx->r1) {
        // 0x8008BD2C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008BD3C;
    }
    // 0x8008BD2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008BD30: bne         $t8, $at, L_8008BD3C
    if (ctx->r24 != ctx->r1) {
        // 0x8008BD34: nop
    
            goto L_8008BD3C;
    }
    // 0x8008BD34: nop

    // 0x8008BD38: break       6
    do_break(2148056376);
L_8008BD3C:
    // 0x8008BD3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BD40: lwc1        $f19, -0x500($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X500);
    // 0x8008BD44: lwc1        $f18, -0x4FC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4FC);
    // 0x8008BD48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BD4C: mflo        $t9
    ctx->r25 = lo;
    // 0x8008BD50: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8008BD54: nop

    // 0x8008BD58: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008BD5C: lwc1        $f9, -0x4F8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X4F8);
    // 0x8008BD60: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8008BD64: nop

    // 0x8008BD68: div.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x8008BD6C: lwc1        $f8, -0x4F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4F4);
    // 0x8008BD70: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008BD74: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8008BD78: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008BD7C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008BD80: div.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8008BD84: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8008BD88: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8008BD8C: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8008BD90: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8008BD94: bc1f        L_8008BDC0
    if (!c1cs) {
        // 0x8008BD98: nop
    
            goto L_8008BDC0;
    }
    // 0x8008BD98: nop

    // 0x8008BD9C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008BDA0: mfc1        $a2, $f17
    ctx->r6 = (int32_t)ctx->f_odd[(17 - 1) * 2];
    // 0x8008BDA4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8008BDA8: jal         0x800B3BFC
    // 0x8008BDAC: addiu       $a0, $a0, -0x628
    ctx->r4 = ADD32(ctx->r4, -0X628);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8008BDAC: addiu       $a0, $a0, -0x628
    ctx->r4 = ADD32(ctx->r4, -0X628);
    after_0:
    // 0x8008BDB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008BDB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008BDB8: nop

    // 0x8008BDBC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
L_8008BDC0:
    // 0x8008BDC0: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008BDC4: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8008BDC8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008BDCC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8008BDD0: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x8008BDD4: nop

    // 0x8008BDD8: bc1f        L_8008BE00
    if (!c1cs) {
        // 0x8008BDDC: lui         $at, 0xBFF0
        ctx->r1 = S32(0XBFF0 << 16);
            goto L_8008BE00;
    }
    // 0x8008BDDC: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8008BDE0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008BDE4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008BDE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008BDEC: mul.d       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x8008BDF0: addiu       $a0, $a0, -0x610
    ctx->r4 = ADD32(ctx->r4, -0X610);
    // 0x8008BDF4: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8008BDF8: jal         0x800B3BFC
    // 0x8008BDFC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8008BDFC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_1:
L_8008BE00:
    // 0x8008BE00: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008BE04: nop

L_8008BE08:
    // 0x8008BE08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BE0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008BE10: jr          $ra
    // 0x8008BE14: nop

    return;
    // 0x8008BE14: nop

;}

RECOMP_FUNC void Dcm_SetPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BE18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008BE1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008BE20: lhu         $t6, 0x22($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X22);
    // 0x8008BE24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BE28: bgtz        $t6, L_8008BE3C
    if (SIGNED(ctx->r14) > 0) {
        // 0x8008BE2C: nop
    
            goto L_8008BE3C;
    }
    // 0x8008BE2C: nop

    // 0x8008BE30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8008BE34: b           L_8008BF48
    // 0x8008BE38: nop

        goto L_8008BF48;
    // 0x8008BE38: nop

L_8008BE3C:
    // 0x8008BE3C: lhu         $t7, 0x22($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X22);
    // 0x8008BE40: lui         $t8, 0xDA
    ctx->r24 = S32(0XDA << 16);
    // 0x8008BE44: ori         $t8, $t8, 0x7A68
    ctx->r24 = ctx->r24 | 0X7A68;
    // 0x8008BE48: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x8008BE4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BE50: lwc1        $f5, -0x4F0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X4F0);
    // 0x8008BE54: lwc1        $f4, -0x4EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4EC);
    // 0x8008BE58: bne         $t7, $zero, L_8008BE64
    if (ctx->r15 != 0) {
        // 0x8008BE5C: nop
    
            goto L_8008BE64;
    }
    // 0x8008BE5C: nop

    // 0x8008BE60: break       7
    do_break(2148056672);
L_8008BE64:
    // 0x8008BE64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008BE68: bne         $t7, $at, L_8008BE7C
    if (ctx->r15 != ctx->r1) {
        // 0x8008BE6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008BE7C;
    }
    // 0x8008BE6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008BE70: bne         $t8, $at, L_8008BE7C
    if (ctx->r24 != ctx->r1) {
        // 0x8008BE74: nop
    
            goto L_8008BE7C;
    }
    // 0x8008BE74: nop

    // 0x8008BE78: break       6
    do_break(2148056696);
L_8008BE7C:
    // 0x8008BE7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BE80: lwc1        $f19, -0x4E8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X4E8);
    // 0x8008BE84: lwc1        $f18, -0x4E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4E4);
    // 0x8008BE88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BE8C: mflo        $t9
    ctx->r25 = lo;
    // 0x8008BE90: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8008BE94: nop

    // 0x8008BE98: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008BE9C: lwc1        $f9, -0x4E0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X4E0);
    // 0x8008BEA0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8008BEA4: nop

    // 0x8008BEA8: div.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x8008BEAC: lwc1        $f8, -0x4DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4DC);
    // 0x8008BEB0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008BEB4: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8008BEB8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008BEBC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008BEC0: div.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8008BEC4: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8008BEC8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8008BECC: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8008BED0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8008BED4: bc1f        L_8008BF00
    if (!c1cs) {
        // 0x8008BED8: nop
    
            goto L_8008BF00;
    }
    // 0x8008BED8: nop

    // 0x8008BEDC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008BEE0: mfc1        $a2, $f17
    ctx->r6 = (int32_t)ctx->f_odd[(17 - 1) * 2];
    // 0x8008BEE4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8008BEE8: jal         0x800B3BFC
    // 0x8008BEEC: addiu       $a0, $a0, -0x5FC
    ctx->r4 = ADD32(ctx->r4, -0X5FC);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8008BEEC: addiu       $a0, $a0, -0x5FC
    ctx->r4 = ADD32(ctx->r4, -0X5FC);
    after_0:
    // 0x8008BEF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008BEF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008BEF8: nop

    // 0x8008BEFC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
L_8008BF00:
    // 0x8008BF00: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008BF04: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8008BF08: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008BF0C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8008BF10: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x8008BF14: nop

    // 0x8008BF18: bc1f        L_8008BF40
    if (!c1cs) {
        // 0x8008BF1C: lui         $at, 0xBFF0
        ctx->r1 = S32(0XBFF0 << 16);
            goto L_8008BF40;
    }
    // 0x8008BF1C: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8008BF20: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008BF24: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008BF28: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008BF2C: mul.d       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x8008BF30: addiu       $a0, $a0, -0x5E4
    ctx->r4 = ADD32(ctx->r4, -0X5E4);
    // 0x8008BF34: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8008BF38: jal         0x800B3BFC
    // 0x8008BF3C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8008BF3C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_1:
L_8008BF40:
    // 0x8008BF40: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008BF44: nop

L_8008BF48:
    // 0x8008BF48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BF4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008BF50: jr          $ra
    // 0x8008BF54: nop

    return;
    // 0x8008BF54: nop

;}

RECOMP_FUNC void Dcm_InitDecoder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EFA0: sw          $zero, 0x1004($a1)
    MEM_W(0X1004, ctx->r5) = 0;
    // 0x8008EFA4: lw          $t6, 0x1004($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1004);
    // 0x8008EFA8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008EFAC: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8008EFB0: sw          $t6, 0x1008($a1)
    MEM_W(0X1008, ctx->r5) = ctx->r14;
    // 0x8008EFB4: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
L_8008EFB8:
    // 0x8008EFB8: lh          $t7, 0x6($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6);
    // 0x8008EFBC: nop

    // 0x8008EFC0: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8008EFC4: sb          $t7, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r15;
    // 0x8008EFC8: lh          $t9, 0x6($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6);
    // 0x8008EFCC: nop

    // 0x8008EFD0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008EFD4: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8008EFD8: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8008EFDC: slti        $at, $t2, 0x100
    ctx->r1 = SIGNED(ctx->r10) < 0X100 ? 1 : 0;
    // 0x8008EFE0: bne         $at, $zero, L_8008EFB8
    if (ctx->r1 != 0) {
        // 0x8008EFE4: sh          $t0, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r8;
            goto L_8008EFB8;
    }
    // 0x8008EFE4: sh          $t0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r8;
    // 0x8008EFE8: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x8008EFEC: sh          $t3, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r11;
L_8008EFF0:
    // 0x8008EFF0: lh          $t4, 0x6($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X6);
    // 0x8008EFF4: addiu       $t5, $zero, 0x1FF
    ctx->r13 = ADD32(0, 0X1FF);
    // 0x8008EFF8: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x8008EFFC: addu        $t7, $a1, $t4
    ctx->r15 = ADD32(ctx->r5, ctx->r12);
    // 0x8008F000: sb          $t6, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r14;
    // 0x8008F004: lh          $t8, 0x6($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6);
    // 0x8008F008: nop

    // 0x8008F00C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008F010: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x8008F014: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8008F018: slti        $at, $t1, 0x200
    ctx->r1 = SIGNED(ctx->r9) < 0X200 ? 1 : 0;
    // 0x8008F01C: bne         $at, $zero, L_8008EFF0
    if (ctx->r1 != 0) {
        // 0x8008F020: sh          $t9, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r25;
            goto L_8008EFF0;
    }
    // 0x8008F020: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x8008F024: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
L_8008F028:
    // 0x8008F028: sh          $zero, 0x4($sp)
    MEM_H(0X4, ctx->r29) = 0;
L_8008F02C:
    // 0x8008F02C: lh          $t2, 0x6($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X6);
    // 0x8008F030: lh          $t5, 0x4($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X4);
    // 0x8008F034: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8008F038: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x8008F03C: addu        $t6, $a1, $t4
    ctx->r14 = ADD32(ctx->r5, ctx->r12);
    // 0x8008F040: sb          $t2, 0x204($t6)
    MEM_B(0X204, ctx->r14) = ctx->r10;
    // 0x8008F044: lh          $t7, 0x4($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4);
    // 0x8008F048: nop

    // 0x8008F04C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008F050: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8008F054: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8008F058: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8008F05C: bne         $at, $zero, L_8008F02C
    if (ctx->r1 != 0) {
        // 0x8008F060: sh          $t8, 0x4($sp)
        MEM_H(0X4, ctx->r29) = ctx->r24;
            goto L_8008F02C;
    }
    // 0x8008F060: sh          $t8, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r24;
    // 0x8008F064: lh          $t1, 0x6($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X6);
    // 0x8008F068: nop

    // 0x8008F06C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8008F070: sll         $t5, $t3, 16
    ctx->r13 = S32(ctx->r11 << 16);
    // 0x8008F074: sra         $t4, $t5, 16
    ctx->r12 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8008F078: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x8008F07C: bne         $at, $zero, L_8008F028
    if (ctx->r1 != 0) {
        // 0x8008F080: sh          $t3, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r11;
            goto L_8008F028;
    }
    // 0x8008F080: sh          $t3, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r11;
    // 0x8008F084: addiu       $t2, $zero, 0x600
    ctx->r10 = ADD32(0, 0X600);
    // 0x8008F088: sh          $t2, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r10;
L_8008F08C:
    // 0x8008F08C: lh          $t6, 0x6($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6);
    // 0x8008F090: nop

    // 0x8008F094: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8008F098: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x8008F09C: sb          $t7, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r15;
    // 0x8008F0A0: lh          $t9, 0x6($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6);
    // 0x8008F0A4: nop

    // 0x8008F0A8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F0AC: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8008F0B0: sra         $t3, $t1, 16
    ctx->r11 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8008F0B4: slti        $at, $t3, 0x1000
    ctx->r1 = SIGNED(ctx->r11) < 0X1000 ? 1 : 0;
    // 0x8008F0B8: bne         $at, $zero, L_8008F08C
    if (ctx->r1 != 0) {
        // 0x8008F0BC: sh          $t0, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r8;
            goto L_8008F08C;
    }
    // 0x8008F0BC: sh          $t0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r8;
    // 0x8008F0C0: sb          $zero, 0x100C($a1)
    MEM_B(0X100C, ctx->r5) = 0;
    // 0x8008F0C4: sh          $zero, 0x100E($a1)
    MEM_H(0X100E, ctx->r5) = 0;
    // 0x8008F0C8: jr          $ra
    // 0x8008F0CC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008F0CC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Dcm_DecodeSample(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F0D0: lbu         $t6, 0x100C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X100C);
    // 0x8008F0D4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008F0D8: bne         $t6, $zero, L_8008F170
    if (ctx->r14 != 0) {
        // 0x8008F0DC: nop
    
            goto L_8008F170;
    }
    // 0x8008F0DC: nop

    // 0x8008F0E0: lw          $t7, 0x1004($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1004);
    // 0x8008F0E4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8008F0E8: lw          $t1, 0x1004($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1004);
    // 0x8008F0EC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8008F0F0: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8008F0F4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008F0F8: sb          $t0, 0x100D($a0)
    MEM_B(0X100D, ctx->r4) = ctx->r8;
    // 0x8008F0FC: lbu         $t3, 0x100D($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X100D);
    // 0x8008F100: sw          $t2, 0x1004($a0)
    MEM_W(0X1004, ctx->r4) = ctx->r10;
    // 0x8008F104: andi        $t4, $t3, 0xF0
    ctx->r12 = ctx->r11 & 0XF0;
    // 0x8008F108: bne         $t4, $zero, L_8008F128
    if (ctx->r12 != 0) {
        // 0x8008F10C: nop
    
            goto L_8008F128;
    }
    // 0x8008F10C: nop

    // 0x8008F110: lbu         $t6, 0x100D($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X100D);
    // 0x8008F114: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8008F118: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8008F11C: sb          $t5, 0x100C($a0)
    MEM_B(0X100C, ctx->r4) = ctx->r13;
    // 0x8008F120: b           L_8008F170
    // 0x8008F124: sb          $t7, 0x100D($a0)
    MEM_B(0X100D, ctx->r4) = ctx->r15;
        goto L_8008F170;
    // 0x8008F124: sb          $t7, 0x100D($a0)
    MEM_B(0X100D, ctx->r4) = ctx->r15;
L_8008F128:
    // 0x8008F128: lw          $t9, 0x1004($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1004);
    // 0x8008F12C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8008F130: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8008F134: sb          $t8, 0x100C($a0)
    MEM_B(0X100C, ctx->r4) = ctx->r24;
    // 0x8008F138: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8008F13C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x8008F140: lbu         $t3, 0x100D($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X100D);
    // 0x8008F144: lbu         $t9, 0x100D($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X100D);
    // 0x8008F148: lw          $t7, 0x1004($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1004);
    // 0x8008F14C: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x8008F150: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x8008F154: sra         $t0, $t9, 4
    ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8008F158: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x8008F15C: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x8008F160: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008F164: sw          $t8, 0x1004($a0)
    MEM_W(0X1004, ctx->r4) = ctx->r24;
    // 0x8008F168: sh          $t6, 0x100E($a0)
    MEM_H(0X100E, ctx->r4) = ctx->r14;
    // 0x8008F16C: sb          $t1, 0x100D($a0)
    MEM_B(0X100D, ctx->r4) = ctx->r9;
L_8008F170:
    // 0x8008F170: lbu         $t3, 0x100C($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X100C);
    // 0x8008F174: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008F178: bne         $t3, $at, L_8008F1D8
    if (ctx->r11 != ctx->r1) {
        // 0x8008F17C: nop
    
            goto L_8008F1D8;
    }
    // 0x8008F17C: nop

    // 0x8008F180: lw          $t4, 0x1004($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1004);
    // 0x8008F184: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8008F188: nop

    // 0x8008F18C: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x8008F190: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8008F194: nop

    // 0x8008F198: sb          $t6, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r14;
    // 0x8008F19C: lw          $t7, 0x1004($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1004);
    // 0x8008F1A0: lw          $t0, 0x1008($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1008);
    // 0x8008F1A4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008F1A8: sw          $t8, 0x1004($a0)
    MEM_W(0X1004, ctx->r4) = ctx->r24;
    // 0x8008F1AC: lbu         $t9, 0x7($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X7);
    // 0x8008F1B0: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8008F1B4: sb          $t9, 0x4($t1)
    MEM_B(0X4, ctx->r9) = ctx->r25;
    // 0x8008F1B8: lw          $t3, 0x1008($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1008);
    // 0x8008F1BC: nop

    // 0x8008F1C0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008F1C4: sw          $t4, 0x1008($a0)
    MEM_W(0X1008, ctx->r4) = ctx->r12;
    // 0x8008F1C8: lw          $t2, 0x1008($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1008);
    // 0x8008F1CC: nop

    // 0x8008F1D0: andi        $t5, $t2, 0xFFF
    ctx->r13 = ctx->r10 & 0XFFF;
    // 0x8008F1D4: sw          $t5, 0x1008($a0)
    MEM_W(0X1008, ctx->r4) = ctx->r13;
L_8008F1D8:
    // 0x8008F1D8: lbu         $t6, 0x100C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X100C);
    // 0x8008F1DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008F1E0: bne         $t6, $at, L_8008F24C
    if (ctx->r14 != ctx->r1) {
        // 0x8008F1E4: nop
    
            goto L_8008F24C;
    }
    // 0x8008F1E4: nop

    // 0x8008F1E8: lhu         $t7, 0x100E($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X100E);
    // 0x8008F1EC: nop

    // 0x8008F1F0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008F1F4: lbu         $t0, 0x4($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X4);
    // 0x8008F1F8: nop

    // 0x8008F1FC: sb          $t0, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r8;
    // 0x8008F200: lhu         $t9, 0x100E($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X100E);
    // 0x8008F204: lw          $t5, 0x1008($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1008);
    // 0x8008F208: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8008F20C: sh          $t1, 0x100E($a0)
    MEM_H(0X100E, ctx->r4) = ctx->r9;
    // 0x8008F210: lhu         $t3, 0x100E($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X100E);
    // 0x8008F214: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x8008F218: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x8008F21C: sh          $t4, 0x100E($a0)
    MEM_H(0X100E, ctx->r4) = ctx->r12;
    // 0x8008F220: lbu         $t2, 0x7($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X7);
    // 0x8008F224: nop

    // 0x8008F228: sb          $t2, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r10;
    // 0x8008F22C: lw          $t7, 0x1008($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1008);
    // 0x8008F230: nop

    // 0x8008F234: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008F238: sw          $t8, 0x1008($a0)
    MEM_W(0X1008, ctx->r4) = ctx->r24;
    // 0x8008F23C: lw          $t0, 0x1008($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1008);
    // 0x8008F240: nop

    // 0x8008F244: andi        $t9, $t0, 0xFFF
    ctx->r25 = ctx->r8 & 0XFFF;
    // 0x8008F248: sw          $t9, 0x1008($a0)
    MEM_W(0X1008, ctx->r4) = ctx->r25;
L_8008F24C:
    // 0x8008F24C: lbu         $t1, 0x100D($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X100D);
    // 0x8008F250: nop

    // 0x8008F254: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x8008F258: sb          $t3, 0x100D($a0)
    MEM_B(0X100D, ctx->r4) = ctx->r11;
    // 0x8008F25C: lbu         $t4, 0x100D($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X100D);
    // 0x8008F260: nop

    // 0x8008F264: bne         $t4, $zero, L_8008F270
    if (ctx->r12 != 0) {
        // 0x8008F268: nop
    
            goto L_8008F270;
    }
    // 0x8008F268: nop

    // 0x8008F26C: sb          $zero, 0x100C($a0)
    MEM_B(0X100C, ctx->r4) = 0;
L_8008F270:
    // 0x8008F270: lbu         $v0, 0x7($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X7);
    // 0x8008F274: jr          $ra
    // 0x8008F278: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008F278: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8008F27C: nop

;}

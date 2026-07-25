#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void wonders2_InitWonderProgress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045E50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80045E54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80045E58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80045E5C: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x80045E60: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80045E64: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80045E68: jal         0x8007BCB4
    // 0x80045E6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    SaveData_GetTotalWonderLines(rdram, ctx);
        goto after_0;
    // 0x80045E6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80045E70: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80045E74: slti        $at, $s0, 0x30
    ctx->r1 = SIGNED(ctx->r16) < 0X30 ? 1 : 0;
    // 0x80045E78: beq         $at, $zero, L_80045EE0
    if (ctx->r1 == 0) {
        // 0x80045E7C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80045EE0;
    }
    // 0x80045E7C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80045E80: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80045E84: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80045E88: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80045E8C: lw          $t7, -0x798($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X798);
    // 0x80045E90: nop

    // 0x80045E94: sltu        $at, $s2, $t7
    ctx->r1 = ctx->r18 < ctx->r15 ? 1 : 0;
    // 0x80045E98: bne         $at, $zero, L_80045EE0
    if (ctx->r1 != 0) {
        // 0x80045E9C: nop
    
            goto L_80045EE0;
    }
    // 0x80045E9C: nop

L_80045EA0:
    // 0x80045EA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80045EA4: sll         $t8, $s0, 24
    ctx->r24 = S32(ctx->r16 << 24);
    // 0x80045EA8: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80045EAC: sra         $t9, $s0, 24
    ctx->r25 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80045EB0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80045EB4: slti        $at, $s0, 0x30
    ctx->r1 = SIGNED(ctx->r16) < 0X30 ? 1 : 0;
    // 0x80045EB8: beq         $at, $zero, L_80045EE0
    if (ctx->r1 == 0) {
        // 0x80045EBC: nop
    
            goto L_80045EE0;
    }
    // 0x80045EBC: nop

    // 0x80045EC0: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80045EC4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80045EC8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80045ECC: lw          $t1, -0x798($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X798);
    // 0x80045ED0: nop

    // 0x80045ED4: sltu        $at, $s2, $t1
    ctx->r1 = ctx->r18 < ctx->r9 ? 1 : 0;
    // 0x80045ED8: beq         $at, $zero, L_80045EA0
    if (ctx->r1 == 0) {
        // 0x80045EDC: nop
    
            goto L_80045EA0;
    }
    // 0x80045EDC: nop

L_80045EE0:
    // 0x80045EE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045EE4: sb          $s0, -0x7D0($at)
    MEM_B(-0X7D0, ctx->r1) = ctx->r16;
    // 0x80045EE8: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80045EEC: lb          $t2, -0x7D0($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X7D0);
    // 0x80045EF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045EF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80045EF8: sb          $t2, -0x7CC($at)
    MEM_B(-0X7CC, ctx->r1) = ctx->r10;
    // 0x80045EFC: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x80045F00: beq         $at, $zero, L_80045F60
    if (ctx->r1 == 0) {
        // 0x80045F04: nop
    
            goto L_80045F60;
    }
    // 0x80045F04: nop

    // 0x80045F08: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80045F0C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80045F10: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80045F14: lw          $t4, -0x6D8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6D8);
    // 0x80045F18: nop

    // 0x80045F1C: sltu        $at, $s2, $t4
    ctx->r1 = ctx->r18 < ctx->r12 ? 1 : 0;
    // 0x80045F20: bne         $at, $zero, L_80045F60
    if (ctx->r1 != 0) {
        // 0x80045F24: nop
    
            goto L_80045F60;
    }
    // 0x80045F24: nop

L_80045F28:
    // 0x80045F28: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80045F2C: andi        $t5, $s1, 0xFF
    ctx->r13 = ctx->r17 & 0XFF;
    // 0x80045F30: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x80045F34: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x80045F38: beq         $at, $zero, L_80045F60
    if (ctx->r1 == 0) {
        // 0x80045F3C: nop
    
            goto L_80045F60;
    }
    // 0x80045F3C: nop

    // 0x80045F40: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80045F44: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80045F48: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80045F4C: lw          $t7, -0x6D8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6D8);
    // 0x80045F50: nop

    // 0x80045F54: sltu        $at, $s2, $t7
    ctx->r1 = ctx->r18 < ctx->r15 ? 1 : 0;
    // 0x80045F58: beq         $at, $zero, L_80045F28
    if (ctx->r1 == 0) {
        // 0x80045F5C: nop
    
            goto L_80045F28;
    }
    // 0x80045F5C: nop

L_80045F60:
    // 0x80045F60: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80045F64: bne         $s1, $at, L_80045F9C
    if (ctx->r17 != ctx->r1) {
        // 0x80045F68: nop
    
            goto L_80045F9C;
    }
    // 0x80045F68: nop

    // 0x80045F6C: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80045F70: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80045F74: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80045F78: lw          $t9, -0x6D8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6D8);
    // 0x80045F7C: nop

    // 0x80045F80: sltu        $at, $s2, $t9
    ctx->r1 = ctx->r18 < ctx->r25 ? 1 : 0;
    // 0x80045F84: bne         $at, $zero, L_80045F9C
    if (ctx->r1 != 0) {
        // 0x80045F88: nop
    
            goto L_80045F9C;
    }
    // 0x80045F88: nop

    // 0x80045F8C: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80045F90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045F94: b           L_80045FA4
    // 0x80045F98: sb          $t0, -0x7C8($at)
    MEM_B(-0X7C8, ctx->r1) = ctx->r8;
        goto L_80045FA4;
    // 0x80045F98: sb          $t0, -0x7C8($at)
    MEM_B(-0X7C8, ctx->r1) = ctx->r8;
L_80045F9C:
    // 0x80045F9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045FA0: sb          $s1, -0x7C8($at)
    MEM_B(-0X7C8, ctx->r1) = ctx->r17;
L_80045FA4:
    // 0x80045FA4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80045FA8: lb          $t1, -0x7C8($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X7C8);
    // 0x80045FAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045FB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80045FB4: sb          $t1, -0x7C4($at)
    MEM_B(-0X7C4, ctx->r1) = ctx->r9;
    // 0x80045FB8: xori        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 ^ 0X7;
    // 0x80045FBC: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80045FC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045FC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80045FC8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80045FCC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80045FD0: sb          $t2, -0x7C0($at)
    MEM_B(-0X7C0, ctx->r1) = ctx->r10;
    // 0x80045FD4: jr          $ra
    // 0x80045FD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80045FD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void wonders2_UpdateWonderProgress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045FDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80045FE0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80045FE4: lb          $t6, -0x7D0($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X7D0);
    // 0x80045FE8: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80045FEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80045FF0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80045FF4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80045FF8: bne         $t6, $at, L_80046008
    if (ctx->r14 != ctx->r1) {
        // 0x80045FFC: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80046008;
    }
    // 0x80045FFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80046000: b           L_80046184
    // 0x80046004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046184;
    // 0x80046004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046008:
    // 0x80046008: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004600C: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x80046010: jal         0x8007BCB4
    // 0x80046014: nop

    SaveData_GetTotalWonderLines(rdram, ctx);
        goto after_0;
    // 0x80046014: nop

    after_0:
    // 0x80046018: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8004601C: lb          $t7, -0x7D0($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X7D0);
    // 0x80046020: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046024: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80046028: sb          $t7, -0x7CC($at)
    MEM_B(-0X7CC, ctx->r1) = ctx->r15;
    // 0x8004602C: slti        $at, $s0, 0x30
    ctx->r1 = SIGNED(ctx->r16) < 0X30 ? 1 : 0;
    // 0x80046030: beq         $at, $zero, L_80046098
    if (ctx->r1 == 0) {
        // 0x80046034: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80046098;
    }
    // 0x80046034: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80046038: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8004603C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80046040: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80046044: lw          $t9, -0x798($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X798);
    // 0x80046048: nop

    // 0x8004604C: sltu        $at, $s2, $t9
    ctx->r1 = ctx->r18 < ctx->r25 ? 1 : 0;
    // 0x80046050: bne         $at, $zero, L_80046098
    if (ctx->r1 != 0) {
        // 0x80046054: nop
    
            goto L_80046098;
    }
    // 0x80046054: nop

L_80046058:
    // 0x80046058: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004605C: sll         $t0, $s0, 24
    ctx->r8 = S32(ctx->r16 << 24);
    // 0x80046060: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80046064: sra         $t1, $s0, 24
    ctx->r9 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80046068: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x8004606C: slti        $at, $s0, 0x30
    ctx->r1 = SIGNED(ctx->r16) < 0X30 ? 1 : 0;
    // 0x80046070: beq         $at, $zero, L_80046098
    if (ctx->r1 == 0) {
        // 0x80046074: nop
    
            goto L_80046098;
    }
    // 0x80046074: nop

    // 0x80046078: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8004607C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80046080: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80046084: lw          $t3, -0x798($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X798);
    // 0x80046088: nop

    // 0x8004608C: sltu        $at, $s2, $t3
    ctx->r1 = ctx->r18 < ctx->r11 ? 1 : 0;
    // 0x80046090: beq         $at, $zero, L_80046058
    if (ctx->r1 == 0) {
        // 0x80046094: nop
    
            goto L_80046058;
    }
    // 0x80046094: nop

L_80046098:
    // 0x80046098: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004609C: sb          $s0, -0x7D0($at)
    MEM_B(-0X7D0, ctx->r1) = ctx->r16;
    // 0x800460A0: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800460A4: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800460A8: lb          $t5, -0x7D0($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X7D0);
    // 0x800460AC: lb          $t4, -0x7CC($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X7CC);
    // 0x800460B0: nop

    // 0x800460B4: beq         $t4, $t5, L_80046180
    if (ctx->r12 == ctx->r13) {
        // 0x800460B8: nop
    
            goto L_80046180;
    }
    // 0x800460B8: nop

    // 0x800460BC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800460C0: lb          $t6, -0x7C8($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X7C8);
    // 0x800460C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800460C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800460CC: sb          $t6, -0x7C4($at)
    MEM_B(-0X7C4, ctx->r1) = ctx->r14;
    // 0x800460D0: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x800460D4: beq         $at, $zero, L_80046134
    if (ctx->r1 == 0) {
        // 0x800460D8: nop
    
            goto L_80046134;
    }
    // 0x800460D8: nop

    // 0x800460DC: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800460E0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800460E4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800460E8: lw          $t8, -0x6D8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6D8);
    // 0x800460EC: nop

    // 0x800460F0: sltu        $at, $s2, $t8
    ctx->r1 = ctx->r18 < ctx->r24 ? 1 : 0;
    // 0x800460F4: bne         $at, $zero, L_80046134
    if (ctx->r1 != 0) {
        // 0x800460F8: nop
    
            goto L_80046134;
    }
    // 0x800460F8: nop

L_800460FC:
    // 0x800460FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80046100: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
    // 0x80046104: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80046108: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x8004610C: beq         $at, $zero, L_80046134
    if (ctx->r1 == 0) {
        // 0x80046110: nop
    
            goto L_80046134;
    }
    // 0x80046110: nop

    // 0x80046114: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80046118: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8004611C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80046120: lw          $t1, -0x6D8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6D8);
    // 0x80046124: nop

    // 0x80046128: sltu        $at, $s2, $t1
    ctx->r1 = ctx->r18 < ctx->r9 ? 1 : 0;
    // 0x8004612C: beq         $at, $zero, L_800460FC
    if (ctx->r1 == 0) {
        // 0x80046130: nop
    
            goto L_800460FC;
    }
    // 0x80046130: nop

L_80046134:
    // 0x80046134: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80046138: bne         $s1, $at, L_80046170
    if (ctx->r17 != ctx->r1) {
        // 0x8004613C: nop
    
            goto L_80046170;
    }
    // 0x8004613C: nop

    // 0x80046140: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80046144: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80046148: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8004614C: lw          $t3, -0x6D8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6D8);
    // 0x80046150: nop

    // 0x80046154: sltu        $at, $s2, $t3
    ctx->r1 = ctx->r18 < ctx->r11 ? 1 : 0;
    // 0x80046158: bne         $at, $zero, L_80046170
    if (ctx->r1 != 0) {
        // 0x8004615C: nop
    
            goto L_80046170;
    }
    // 0x8004615C: nop

    // 0x80046160: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x80046164: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046168: b           L_80046178
    // 0x8004616C: sb          $t4, -0x7C8($at)
    MEM_B(-0X7C8, ctx->r1) = ctx->r12;
        goto L_80046178;
    // 0x8004616C: sb          $t4, -0x7C8($at)
    MEM_B(-0X7C8, ctx->r1) = ctx->r12;
L_80046170:
    // 0x80046170: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046174: sb          $s1, -0x7C8($at)
    MEM_B(-0X7C8, ctx->r1) = ctx->r17;
L_80046178:
    // 0x80046178: b           L_80046184
    // 0x8004617C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80046184;
    // 0x8004617C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80046180:
    // 0x80046180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046184:
    // 0x80046184: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80046188: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004618C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80046190: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80046194: jr          $ra
    // 0x80046198: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80046198: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void wonders2_IsLastColumnOfWonder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004619C: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x800461A0: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x800461A4: xori        $a1, $a0, 0x6
    ctx->r5 = ctx->r4 ^ 0X6;
    // 0x800461A8: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x800461AC: bne         $a1, $zero, L_8004620C
    if (ctx->r5 != 0) {
        // 0x800461B0: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_8004620C;
    }
    // 0x800461B0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800461B4: xori        $a1, $a0, 0xD
    ctx->r5 = ctx->r4 ^ 0XD;
    // 0x800461B8: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x800461BC: bne         $a1, $zero, L_8004620C
    if (ctx->r5 != 0) {
        // 0x800461C0: nop
    
            goto L_8004620C;
    }
    // 0x800461C0: nop

    // 0x800461C4: xori        $a1, $a0, 0x14
    ctx->r5 = ctx->r4 ^ 0X14;
    // 0x800461C8: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x800461CC: bne         $a1, $zero, L_8004620C
    if (ctx->r5 != 0) {
        // 0x800461D0: nop
    
            goto L_8004620C;
    }
    // 0x800461D0: nop

    // 0x800461D4: xori        $a1, $a0, 0x1B
    ctx->r5 = ctx->r4 ^ 0X1B;
    // 0x800461D8: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x800461DC: bne         $a1, $zero, L_8004620C
    if (ctx->r5 != 0) {
        // 0x800461E0: nop
    
            goto L_8004620C;
    }
    // 0x800461E0: nop

    // 0x800461E4: xori        $a1, $a0, 0x22
    ctx->r5 = ctx->r4 ^ 0X22;
    // 0x800461E8: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x800461EC: bne         $a1, $zero, L_8004620C
    if (ctx->r5 != 0) {
        // 0x800461F0: nop
    
            goto L_8004620C;
    }
    // 0x800461F0: nop

    // 0x800461F4: xori        $a1, $a0, 0x29
    ctx->r5 = ctx->r4 ^ 0X29;
    // 0x800461F8: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x800461FC: bne         $a1, $zero, L_8004620C
    if (ctx->r5 != 0) {
        // 0x80046200: nop
    
            goto L_8004620C;
    }
    // 0x80046200: nop

    // 0x80046204: xori        $a1, $a0, 0x30
    ctx->r5 = ctx->r4 ^ 0X30;
    // 0x80046208: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
L_8004620C:
    // 0x8004620C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80046210: jr          $ra
    // 0x80046214: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80046214: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void wonders2_ColumnToWonderIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046218: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8004621C: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80046220: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80046224: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80046228: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8004622C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80046230: mflo        $a1
    ctx->r5 = lo;
    // 0x80046234: sll         $t6, $a1, 24
    ctx->r14 = S32(ctx->r5 << 24);
    // 0x80046238: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8004623C: sra         $t7, $a1, 24
    ctx->r15 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80046240: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80046244: jr          $ra
    // 0x80046248: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80046248: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}

RECOMP_FUNC void wonders2_WonderIndexToLastColumn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004624C: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80046250: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80046254: sll         $a1, $a0, 3
    ctx->r5 = S32(ctx->r4 << 3);
    // 0x80046258: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    // 0x8004625C: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x80046260: sll         $t6, $a1, 24
    ctx->r14 = S32(ctx->r5 << 24);
    // 0x80046264: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80046268: sra         $t7, $a1, 24
    ctx->r15 = S32(SIGNED(ctx->r5) >> 24);
    // 0x8004626C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80046270: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80046274: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80046278: jr          $ra
    // 0x8004627C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8004627C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void wonders2_GetWonderProgressPercent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046280: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80046284: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80046288: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004628C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80046290: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x80046294: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80046298: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8004629C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800462A0: jal         0x8007BCB4
    // 0x800462A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    SaveData_GetTotalWonderLines(rdram, ctx);
        goto after_0;
    // 0x800462A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800462A8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800462AC: lb          $t7, -0x7C8($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X7C8);
    // 0x800462B0: lb          $t6, 0x3B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X3B);
    // 0x800462B4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800462B8: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800462BC: beq         $at, $zero, L_800462CC
    if (ctx->r1 == 0) {
        // 0x800462C0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800462CC;
    }
    // 0x800462C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800462C4: b           L_80046368
    // 0x800462C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80046368;
    // 0x800462C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800462CC:
    // 0x800462CC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800462D0: lb          $t9, -0x7C8($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X7C8);
    // 0x800462D4: lb          $t8, 0x3B($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X3B);
    // 0x800462D8: nop

    // 0x800462DC: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800462E0: beq         $at, $zero, L_800462F0
    if (ctx->r1 == 0) {
        // 0x800462E4: nop
    
            goto L_800462F0;
    }
    // 0x800462E4: nop

    // 0x800462E8: b           L_80046368
    // 0x800462EC: addiu       $s0, $zero, 0x64
    ctx->r16 = ADD32(0, 0X64);
        goto L_80046368;
    // 0x800462EC: addiu       $s0, $zero, 0x64
    ctx->r16 = ADD32(0, 0X64);
L_800462F0:
    // 0x800462F0: lb          $t0, 0x3B($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X3B);
    // 0x800462F4: nop

    // 0x800462F8: beq         $t0, $zero, L_80046318
    if (ctx->r8 == 0) {
        // 0x800462FC: nop
    
            goto L_80046318;
    }
    // 0x800462FC: nop

    // 0x80046300: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80046304: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80046308: addu        $s1, $s1, $t1
    ctx->r17 = ADD32(ctx->r17, ctx->r9);
    // 0x8004630C: lw          $s1, -0x6DC($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X6DC);
    // 0x80046310: b           L_8004631C
    // 0x80046314: nop

        goto L_8004631C;
    // 0x80046314: nop

L_80046318:
    // 0x80046318: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8004631C:
    // 0x8004631C: lb          $t2, 0x3B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3B);
    // 0x80046320: subu        $t5, $s3, $s1
    ctx->r13 = SUB32(ctx->r19, ctx->r17);
    // 0x80046324: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80046328: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8004632C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80046330: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80046334: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80046338: lw          $t4, -0x6D8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6D8);
    // 0x8004633C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80046340: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80046344: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80046348: subu        $s2, $t4, $s1
    ctx->r18 = SUB32(ctx->r12, ctx->r17);
    // 0x8004634C: divu        $zero, $t6, $s2
    lo = S32(U32(ctx->r14) / U32(ctx->r18)); hi = S32(U32(ctx->r14) % U32(ctx->r18));
    // 0x80046350: bne         $s2, $zero, L_8004635C
    if (ctx->r18 != 0) {
        // 0x80046354: nop
    
            goto L_8004635C;
    }
    // 0x80046354: nop

    // 0x80046358: break       7
    do_break(2147771224);
L_8004635C:
    // 0x8004635C: mflo        $s0
    ctx->r16 = lo;
    // 0x80046360: andi        $t7, $s0, 0xFF
    ctx->r15 = ctx->r16 & 0XFF;
    // 0x80046364: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_80046368:
    // 0x80046368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004636C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80046370: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80046374: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80046378: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8004637C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80046380: jr          $ra
    // 0x80046384: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80046384: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void wonders2_GetLinesRemainingToWonder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046388: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004638C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80046390: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80046394: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80046398: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x8004639C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800463A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800463A4: jal         0x8007BCB4
    // 0x800463A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    SaveData_GetTotalWonderLines(rdram, ctx);
        goto after_0;
    // 0x800463A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800463AC: lb          $t6, 0x3B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X3B);
    // 0x800463B0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800463B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800463B8: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x800463BC: lw          $s0, -0x6D8($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X6D8);
    // 0x800463C0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800463C4: sltu        $at, $s2, $s0
    ctx->r1 = ctx->r18 < ctx->r16 ? 1 : 0;
    // 0x800463C8: bne         $at, $zero, L_800463D8
    if (ctx->r1 != 0) {
        // 0x800463CC: nop
    
            goto L_800463D8;
    }
    // 0x800463CC: nop

    // 0x800463D0: b           L_800463DC
    // 0x800463D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_800463DC;
    // 0x800463D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800463D8:
    // 0x800463D8: subu        $s1, $s0, $s2
    ctx->r17 = SUB32(ctx->r16, ctx->r18);
L_800463DC:
    // 0x800463DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800463E0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800463E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800463E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800463EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800463F0: jr          $ra
    // 0x800463F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800463F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800463F8: nop

    // 0x800463FC: nop

;}

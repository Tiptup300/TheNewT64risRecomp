#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Garbage_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072D38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80072D3C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80072D40: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80072D44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072D48: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80072D4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072D50: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x80072D54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80072D58: jal         0x80072E2C
    // 0x80072D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Garbage_SetActive(rdram, ctx);
        goto after_0;
    // 0x80072D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80072D60: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80072D64: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80072D68: sb          $zero, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = 0;
    // 0x80072D6C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80072D70: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80072D74: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
    // 0x80072D78: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80072D7C: nop

    // 0x80072D80: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
    // 0x80072D84: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80072D88: nop

    // 0x80072D8C: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x80072D90: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80072D94: lbu         $t2, -0x10DF($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X10DF);
    // 0x80072D98: nop

    // 0x80072D9C: sb          $t2, 0x1D($t3)
    MEM_B(0X1D, ctx->r11) = ctx->r10;
    // 0x80072DA0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80072DA4: nop

    // 0x80072DA8: sb          $zero, 0x3($t4)
    MEM_B(0X3, ctx->r12) = 0;
    // 0x80072DAC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80072DB0: nop

    // 0x80072DB4: sb          $zero, 0x4($t5)
    MEM_B(0X4, ctx->r13) = 0;
    // 0x80072DB8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80072DBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80072DC0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80072DC4: jal         0x80072B30
    // 0x80072DC8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    Landfill_InitHoleColumn(rdram, ctx);
        goto after_1;
    // 0x80072DC8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x80072DCC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80072DD0: nop

    // 0x80072DD4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80072DD8: jal         0x8006089C
    // 0x80072DDC: nop

    Rand_Hash(rdram, ctx);
        goto after_2;
    // 0x80072DDC: nop

    after_2:
    // 0x80072DE0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80072DE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80072DE8: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80072DEC: beq         $at, $zero, L_80072E14
    if (ctx->r1 == 0) {
        // 0x80072DF0: sw          $v0, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r2;
            goto L_80072E14;
    }
    // 0x80072DF0: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
L_80072DF4:
    // 0x80072DF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80072DF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80072DFC: jal         0x80072CC8
    // 0x80072E00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Landfill_SetRowCell(rdram, ctx);
        goto after_3;
    // 0x80072E00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80072E04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80072E08: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80072E0C: bne         $at, $zero, L_80072DF4
    if (ctx->r1 != 0) {
        // 0x80072E10: nop
    
            goto L_80072DF4;
    }
    // 0x80072E10: nop

L_80072E14:
    // 0x80072E14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072E18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80072E1C: jr          $ra
    // 0x80072E20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80072E20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Garbage_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072E24: jr          $ra
    // 0x80072E28: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    return;
    // 0x80072E28: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
;}

RECOMP_FUNC void Garbage_SetActive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072E2C: jr          $ra
    // 0x80072E30: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    return;
    // 0x80072E30: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
;}

RECOMP_FUNC void Garbage_SetColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072E34: jr          $ra
    // 0x80072E38: sb          $a1, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r5;
    return;
    // 0x80072E38: sb          $a1, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r5;
;}

RECOMP_FUNC void Garbage_StepDrop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072E3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80072E40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072E44: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80072E48: lw          $s0, -0x380($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X380);
    // 0x80072E4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072E50: lbu         $t6, 0x3($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X3);
    // 0x80072E54: nop

    // 0x80072E58: beq         $t6, $zero, L_80072E7C
    if (ctx->r14 == 0) {
        // 0x80072E5C: nop
    
            goto L_80072E7C;
    }
    // 0x80072E5C: nop

    // 0x80072E60: jal         0x8006DDD0
    // 0x80072E64: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    BoardP_AnyCubeInRowsUpTo(rdram, ctx);
        goto after_0;
    // 0x80072E64: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80072E68: beq         $v0, $zero, L_80072E98
    if (ctx->r2 == 0) {
        // 0x80072E6C: nop
    
            goto L_80072E98;
    }
    // 0x80072E6C: nop

    // 0x80072E70: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80072E74: b           L_80072F0C
    // 0x80072E78: sb          $t7, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r15;
        goto L_80072F0C;
    // 0x80072E78: sb          $t7, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r15;
L_80072E7C:
    // 0x80072E7C: jal         0x8006DD64
    // 0x80072E80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    BoardP_RowHasCube(rdram, ctx);
        goto after_1;
    // 0x80072E80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80072E84: beq         $v0, $zero, L_80072E98
    if (ctx->r2 == 0) {
        // 0x80072E88: nop
    
            goto L_80072E98;
    }
    // 0x80072E88: nop

    // 0x80072E8C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80072E90: b           L_80072F0C
    // 0x80072E94: sb          $t8, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r24;
        goto L_80072F0C;
    // 0x80072E94: sb          $t8, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r24;
L_80072E98:
    // 0x80072E98: lbu         $t9, 0x6($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6);
    // 0x80072E9C: nop

    // 0x80072EA0: bne         $t9, $zero, L_80072EFC
    if (ctx->r25 != 0) {
        // 0x80072EA4: nop
    
            goto L_80072EFC;
    }
    // 0x80072EA4: nop

    // 0x80072EA8: jal         0x80072BAC
    // 0x80072EAC: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    Landfill_ScrollUp(rdram, ctx);
        goto after_2;
    // 0x80072EAC: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_2:
    // 0x80072EB0: lbu         $t0, 0x1C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1C);
    // 0x80072EB4: lbu         $t2, 0x5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X5);
    // 0x80072EB8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80072EBC: sb          $t1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r9;
    // 0x80072EC0: lbu         $t5, 0x1C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1C);
    // 0x80072EC4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80072EC8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80072ECC: sb          $t3, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r11;
    // 0x80072ED0: beq         $t5, $zero, L_80072EF0
    if (ctx->r13 == 0) {
        // 0x80072ED4: sb          $t4, 0x6($s0)
        MEM_B(0X6, ctx->r16) = ctx->r12;
            goto L_80072EF0;
    }
    // 0x80072ED4: sb          $t4, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r12;
    // 0x80072ED8: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
    // 0x80072EDC: lbu         $t7, 0x10($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X10);
    // 0x80072EE0: nop

    // 0x80072EE4: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80072EE8: bne         $at, $zero, L_80072F0C
    if (ctx->r1 != 0) {
        // 0x80072EEC: nop
    
            goto L_80072F0C;
    }
    // 0x80072EEC: nop

L_80072EF0:
    // 0x80072EF0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80072EF4: b           L_80072F0C
    // 0x80072EF8: sb          $t8, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r24;
        goto L_80072F0C;
    // 0x80072EF8: sb          $t8, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r24;
L_80072EFC:
    // 0x80072EFC: lbu         $t9, 0x6($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6);
    // 0x80072F00: nop

    // 0x80072F04: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80072F08: sb          $t0, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r8;
L_80072F0C:
    // 0x80072F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072F10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80072F14: jr          $ra
    // 0x80072F18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80072F18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Garbage_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072F1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80072F20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072F24: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80072F28: lw          $s0, -0x380($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X380);
    // 0x80072F2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072F30: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80072F34: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x80072F38: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x80072F3C: beq         $t6, $zero, L_80072F54
    if (ctx->r14 == 0) {
        // 0x80072F40: nop
    
            goto L_80072F54;
    }
    // 0x80072F40: nop

    // 0x80072F44: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80072F48: nop

    // 0x80072F4C: bne         $t7, $zero, L_80072F68
    if (ctx->r15 != 0) {
        // 0x80072F50: nop
    
            goto L_80072F68;
    }
    // 0x80072F50: nop

L_80072F54:
    // 0x80072F54: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80072F58: sb          $t8, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r24;
    // 0x80072F5C: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80072F60: b           L_80072FA0
    // 0x80072F64: nop

        goto L_80072FA0;
    // 0x80072F64: nop

L_80072F68:
    // 0x80072F68: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x80072F6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80072F70: bne         $t9, $at, L_80072F80
    if (ctx->r25 != ctx->r1) {
        // 0x80072F74: nop
    
            goto L_80072F80;
    }
    // 0x80072F74: nop

    // 0x80072F78: jal         0x80072E3C
    // 0x80072F7C: nop

    Garbage_StepDrop(rdram, ctx);
        goto after_0;
    // 0x80072F7C: nop

    after_0:
L_80072F80:
    // 0x80072F80: lbu         $t0, 0x4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4);
    // 0x80072F84: nop

    // 0x80072F88: beq         $t0, $zero, L_80072F98
    if (ctx->r8 == 0) {
        // 0x80072F8C: nop
    
            goto L_80072F98;
    }
    // 0x80072F8C: nop

    // 0x80072F90: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80072F94: sb          $t1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r9;
L_80072F98:
    // 0x80072F98: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80072F9C: nop

L_80072FA0:
    // 0x80072FA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072FA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80072FA8: jr          $ra
    // 0x80072FAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80072FAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Garbage_GetState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072FB0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072FB4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80072FB8: lw          $a0, -0x380($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X380);
    // 0x80072FBC: jr          $ra
    // 0x80072FC0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80072FC0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Garbage_UpdatePending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072FC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072FC8: lw          $a0, -0x380($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X380);
    // 0x80072FCC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80072FD0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80072FD4: nop

    // 0x80072FD8: bne         $t6, $zero, L_80072FE4
    if (ctx->r14 != 0) {
        // 0x80072FDC: nop
    
            goto L_80072FE4;
    }
    // 0x80072FDC: nop

    // 0x80072FE0: sb          $zero, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = 0;
L_80072FE4:
    // 0x80072FE4: lbu         $t7, 0x1C($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1C);
    // 0x80072FE8: nop

    // 0x80072FEC: bne         $t7, $zero, L_80072FFC
    if (ctx->r15 != 0) {
        // 0x80072FF0: nop
    
            goto L_80072FFC;
    }
    // 0x80072FF0: nop

    // 0x80072FF4: b           L_8007300C
    // 0x80072FF8: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
        goto L_8007300C;
    // 0x80072FF8: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_80072FFC:
    // 0x80072FFC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80073000: sb          $t8, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r24;
    // 0x80073004: sb          $zero, 0x6($a0)
    MEM_B(0X6, ctx->r4) = 0;
    // 0x80073008: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
L_8007300C:
    // 0x8007300C: jr          $ra
    // 0x80073010: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80073010: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Garbage_AddRowOffset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073014: lbu         $t6, 0x1C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1C);
    // 0x80073018: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8007301C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80073020: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80073024: sb          $t7, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r15;
    // 0x80073028: jr          $ra
    // 0x8007302C: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    return;
    // 0x8007302C: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
;}

RECOMP_FUNC void Garbage_ApplyIncoming(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073030: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80073034: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80073038: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8007303C: lw          $s0, -0x380($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X380);
    // 0x80073040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80073044: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80073048: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007304C: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80073050: nop

    // 0x80073054: beq         $t6, $zero, L_80073118
    if (ctx->r14 == 0) {
        // 0x80073058: nop
    
            goto L_80073118;
    }
    // 0x80073058: nop

    // 0x8007305C: lbu         $t7, 0x1D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1D);
    // 0x80073060: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80073064: beq         $t7, $at, L_80073118
    if (ctx->r15 == ctx->r1) {
        // 0x80073068: nop
    
            goto L_80073118;
    }
    // 0x80073068: nop

    // 0x8007306C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80073070: nop

    // 0x80073074: beq         $t8, $zero, L_80073118
    if (ctx->r24 == 0) {
        // 0x80073078: nop
    
            goto L_80073118;
    }
    // 0x80073078: nop

    // 0x8007307C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80073080: lbu         $t0, -0x10DF($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X10DF);
    // 0x80073084: lbu         $t9, 0x1D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1D);
    // 0x80073088: nop

    // 0x8007308C: beq         $t9, $t0, L_80073118
    if (ctx->r25 == ctx->r8) {
        // 0x80073090: nop
    
            goto L_80073118;
    }
    // 0x80073090: nop

    // 0x80073094: lbu         $t1, 0x1C($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1C);
    // 0x80073098: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007309C: nop

    // 0x800730A0: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
    // 0x800730A4: beq         $at, $zero, L_800730C4
    if (ctx->r1 == 0) {
        // 0x800730A8: nop
    
            goto L_800730C4;
    }
    // 0x800730A8: nop

    // 0x800730AC: lbu         $t3, 0x1C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1C);
    // 0x800730B0: nop

    // 0x800730B4: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x800730B8: sb          $t4, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r12;
    // 0x800730BC: b           L_800730DC
    // 0x800730C0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
        goto L_800730DC;
    // 0x800730C0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_800730C4:
    // 0x800730C4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800730C8: lbu         $t6, 0x1C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1C);
    // 0x800730CC: nop

    // 0x800730D0: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x800730D4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800730D8: sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
L_800730DC:
    // 0x800730DC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800730E0: nop

    // 0x800730E4: beq         $t8, $zero, L_80073118
    if (ctx->r24 == 0) {
        // 0x800730E8: nop
    
            goto L_80073118;
    }
    // 0x800730E8: nop

    // 0x800730EC: lbu         $t1, 0x1D($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1D);
    // 0x800730F0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800730F4: lw          $t9, -0x390($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X390);
    // 0x800730F8: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x800730FC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80073100: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80073104: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80073108: addu        $s1, $t0, $t3
    ctx->r17 = ADD32(ctx->r8, ctx->r11);
    // 0x8007310C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80073110: jal         0x80073014
    // 0x80073114: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    Garbage_AddRowOffset(rdram, ctx);
        goto after_0;
    // 0x80073114: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_0:
L_80073118:
    // 0x80073118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007311C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80073120: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80073124: jr          $ra
    // 0x80073128: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80073128: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007312C: nop

;}

RECOMP_FUNC void Garbage_LoadTexture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073B48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80073B4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80073B50: jal         0x8004A34C
    // 0x80073B54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    Main_DrainMessageQueue(rdram, ctx);
        goto after_0;
    // 0x80073B54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80073B58: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80073B5C: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x80073B60: jal         0x80074888
    // 0x80073B64: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_1;
    // 0x80073B64: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_1:
    // 0x80073B68: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80073B6C: jal         0x8007E03C
    // 0x80073B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80073B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80073B74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073B78: sw          $v0, -0x370($at)
    MEM_W(-0X370, ctx->r1) = ctx->r2;
    // 0x80073B7C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80073B80: lw          $a1, -0x370($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X370);
    // 0x80073B84: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80073B88: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x80073B8C: jal         0x800746C0
    // 0x80073B90: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_3;
    // 0x80073B90: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_3:
    // 0x80073B94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80073B98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80073B9C: jr          $ra
    // 0x80073BA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80073BA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Garbage_FreeTexture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073BA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80073BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073BB0: lw          $a0, -0x370($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X370);
    // 0x80073BB4: jal         0x8007E328
    // 0x80073BB8: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x80073BB8: nop

    after_0:
    // 0x80073BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073BC4: jr          $ra
    // 0x80073BC8: nop

    return;
    // 0x80073BC8: nop

    // 0x80073BCC: nop

;}

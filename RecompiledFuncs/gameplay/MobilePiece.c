#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void MobilePiece_Minos_setUpdateFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064CE0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80064CE4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80064CE8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80064CEC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80064CF0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80064CF4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80064CF8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80064CFC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80064D00: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80064D04: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80064D08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064D0C: lhu         $a0, 0x8($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X8);
    // 0x80064D10: jal         0x800608F4
    // 0x80064D14: nop

    Math_SinLookup(rdram, ctx);
        goto after_0;
    // 0x80064D14: nop

    after_0:
    // 0x80064D18: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80064D1C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80064D20: lhu         $a0, 0x8($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X8);
    // 0x80064D24: jal         0x80060914
    // 0x80064D28: nop

    Math_CosLookup(rdram, ctx);
        goto after_1;
    // 0x80064D28: nop

    after_1:
    // 0x80064D2C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80064D30: lbu         $t0, 0x4F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4F);
    // 0x80064D34: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80064D38: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80064D3C: addu        $s2, $t9, $t1
    ctx->r18 = ADD32(ctx->r25, ctx->r9);
    // 0x80064D40: lb          $t2, 0x1($s2)
    ctx->r10 = MEM_B(ctx->r18, 0X1);
    // 0x80064D44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80064D48: lw          $t0, -0x3F0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3F0);
    // 0x80064D4C: lh          $t4, 0xA($t8)
    ctx->r12 = MEM_H(ctx->r24, 0XA);
    // 0x80064D50: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80064D54: lhu         $t9, 0x6($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X6);
    // 0x80064D58: subu        $s0, $t3, $t4
    ctx->r16 = SUB32(ctx->r11, ctx->r12);
    // 0x80064D5C: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x80064D60: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064D64: lb          $t5, 0x2($s2)
    ctx->r13 = MEM_B(ctx->r18, 0X2);
    // 0x80064D68: lh          $t7, 0xC($t8)
    ctx->r15 = MEM_H(ctx->r24, 0XC);
    // 0x80064D6C: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x80064D70: lhu         $t2, 0x6($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X6);
    // 0x80064D74: subu        $s1, $t6, $t7
    ctx->r17 = SUB32(ctx->r14, ctx->r15);
    // 0x80064D78: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x80064D7C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80064D80: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80064D84: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80064D88: mflo        $s0
    ctx->r16 = lo;
    // 0x80064D8C: sra         $t1, $s0, 8
    ctx->r9 = S32(SIGNED(ctx->r16) >> 8);
    // 0x80064D90: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80064D94: multu       $t2, $s1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064D98: mflo        $s1
    ctx->r17 = lo;
    // 0x80064D9C: sra         $t3, $s1, 8
    ctx->r11 = S32(SIGNED(ctx->r17) >> 8);
    // 0x80064DA0: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80064DA4: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064DA8: mflo        $t4
    ctx->r12 = lo;
    // 0x80064DAC: nop

    // 0x80064DB0: nop

    // 0x80064DB4: multu       $s1, $s3
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064DB8: mflo        $t5
    ctx->r13 = lo;
    // 0x80064DBC: subu        $t8, $t4, $t5
    ctx->r24 = SUB32(ctx->r12, ctx->r13);
    // 0x80064DC0: sra         $t6, $t8, 14
    ctx->r14 = S32(SIGNED(ctx->r24) >> 14);
    // 0x80064DC4: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064DC8: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x80064DCC: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80064DD0: mflo        $t9
    ctx->r25 = lo;
    // 0x80064DD4: nop

    // 0x80064DD8: nop

    // 0x80064DDC: multu       $s1, $s4
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064DE0: mflo        $t1
    ctx->r9 = lo;
    // 0x80064DE4: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x80064DE8: sra         $t2, $t0, 14
    ctx->r10 = S32(SIGNED(ctx->r8) >> 14);
    // 0x80064DEC: sh          $t2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r10;
    // 0x80064DF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80064DF4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80064DF8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80064DFC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80064E00: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80064E04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064E08: jr          $ra
    // 0x80064E0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80064E0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void MobilePiece_GetCubeBoardPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E10: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80064E14: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80064E18: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80064E1C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80064E20: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80064E24: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80064E28: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80064E2C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80064E30: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80064E34: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80064E38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064E3C: lhu         $a0, 0x8($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X8);
    // 0x80064E40: jal         0x800608F4
    // 0x80064E44: nop

    Math_SinLookup(rdram, ctx);
        goto after_0;
    // 0x80064E44: nop

    after_0:
    // 0x80064E48: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80064E4C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80064E50: lhu         $a0, 0x8($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X8);
    // 0x80064E54: jal         0x80060914
    // 0x80064E58: nop

    Math_CosLookup(rdram, ctx);
        goto after_1;
    // 0x80064E58: nop

    after_1:
    // 0x80064E5C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80064E60: lbu         $t0, 0x4F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4F);
    // 0x80064E64: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80064E68: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80064E6C: addu        $s2, $t9, $t1
    ctx->r18 = ADD32(ctx->r25, ctx->r9);
    // 0x80064E70: lb          $t2, 0x1($s2)
    ctx->r10 = MEM_B(ctx->r18, 0X1);
    // 0x80064E74: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80064E78: lw          $t0, -0x3F0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3F0);
    // 0x80064E7C: lh          $t4, 0xA($t8)
    ctx->r12 = MEM_H(ctx->r24, 0XA);
    // 0x80064E80: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80064E84: lhu         $t9, 0x6($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X6);
    // 0x80064E88: subu        $s0, $t3, $t4
    ctx->r16 = SUB32(ctx->r11, ctx->r12);
    // 0x80064E8C: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x80064E90: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064E94: lb          $t5, 0x2($s2)
    ctx->r13 = MEM_B(ctx->r18, 0X2);
    // 0x80064E98: lh          $t7, 0xC($t8)
    ctx->r15 = MEM_H(ctx->r24, 0XC);
    // 0x80064E9C: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x80064EA0: lhu         $t2, 0x6($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X6);
    // 0x80064EA4: subu        $s1, $t6, $t7
    ctx->r17 = SUB32(ctx->r14, ctx->r15);
    // 0x80064EA8: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x80064EAC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80064EB0: lh          $t9, 0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XE);
    // 0x80064EB4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80064EB8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80064EBC: mflo        $s0
    ctx->r16 = lo;
    // 0x80064EC0: sra         $t1, $s0, 8
    ctx->r9 = S32(SIGNED(ctx->r16) >> 8);
    // 0x80064EC4: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80064EC8: multu       $t2, $s1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064ECC: mflo        $s1
    ctx->r17 = lo;
    // 0x80064ED0: sra         $t3, $s1, 8
    ctx->r11 = S32(SIGNED(ctx->r17) >> 8);
    // 0x80064ED4: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80064ED8: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064EDC: mflo        $t4
    ctx->r12 = lo;
    // 0x80064EE0: nop

    // 0x80064EE4: nop

    // 0x80064EE8: multu       $s1, $s3
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064EEC: mflo        $t5
    ctx->r13 = lo;
    // 0x80064EF0: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80064EF4: sra         $t7, $t6, 14
    ctx->r15 = S32(SIGNED(ctx->r14) >> 14);
    // 0x80064EF8: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064EFC: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x80064F00: sh          $t1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r9;
    // 0x80064F04: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80064F08: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80064F0C: lh          $t8, 0x10($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X10);
    // 0x80064F10: mflo        $t2
    ctx->r10 = lo;
    // 0x80064F14: nop

    // 0x80064F18: nop

    // 0x80064F1C: multu       $s1, $s4
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064F20: mflo        $t3
    ctx->r11 = lo;
    // 0x80064F24: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80064F28: sra         $t5, $t4, 14
    ctx->r13 = S32(SIGNED(ctx->r12) >> 14);
    // 0x80064F2C: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x80064F30: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x80064F34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80064F38: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80064F3C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80064F40: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80064F44: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80064F48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064F4C: jr          $ra
    // 0x80064F50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80064F50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void MobilePiece_MorphCubes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80064F58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064F5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80064F60: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80064F64: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80064F68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80064F6C:
    // 0x80064F6C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80064F70: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x80064F74: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80064F78: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80064F7C: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80064F80: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80064F84: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80064F88: jal         0x80070528
    // 0x80064F8C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    Minos_80070528_Morph(rdram, ctx);
        goto after_0;
    // 0x80064F8C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x80064F90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80064F94: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80064F98: bne         $at, $zero, L_80064F6C
    if (ctx->r1 != 0) {
        // 0x80064F9C: nop
    
            goto L_80064F6C;
    }
    // 0x80064F9C: nop

    // 0x80064FA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80064FA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064FA8: jr          $ra
    // 0x80064FAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80064FAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void MobilePiece_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064FB0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80064FB4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80064FB8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80064FBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80064FC0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80064FC4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80064FC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064FCC: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x80064FD0: jal         0x80070D30
    // 0x80064FD4: nop

    Minos_SetAlpha(rdram, ctx);
        goto after_0;
    // 0x80064FD4: nop

    after_0:
    // 0x80064FD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80064FDC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80064FE0: addiu       $a1, $a1, -0x2BD8
    ctx->r5 = ADD32(ctx->r5, -0X2BD8);
    // 0x80064FE4: jal         0x8006CF08
    // 0x80064FE8: addiu       $a0, $a0, -0x2BE0
    ctx->r4 = ADD32(ctx->r4, -0X2BE0);
    debug_print2(rdram, ctx);
        goto after_1;
    // 0x80064FE8: addiu       $a0, $a0, -0x2BE0
    ctx->r4 = ADD32(ctx->r4, -0X2BE0);
    after_1:
    // 0x80064FEC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80064FF0: lw          $a0, -0x3F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3F0);
    // 0x80064FF4: jal         0x80070EC8
    // 0x80064FF8: nop

    Minos_BeginRender(rdram, ctx);
        goto after_2;
    // 0x80064FF8: nop

    after_2:
    // 0x80064FFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80065000: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80065004: addiu       $a1, $a1, -0x2BC0
    ctx->r5 = ADD32(ctx->r5, -0X2BC0);
    // 0x80065008: jal         0x8006CF08
    // 0x8006500C: addiu       $a0, $a0, -0x2BC8
    ctx->r4 = ADD32(ctx->r4, -0X2BC8);
    debug_print2(rdram, ctx);
        goto after_3;
    // 0x8006500C: addiu       $a0, $a0, -0x2BC8
    ctx->r4 = ADD32(ctx->r4, -0X2BC8);
    after_3:
    // 0x80065010: jal         0x8007116C
    // 0x80065014: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Minos_SetVtxTransform(rdram, ctx);
        goto after_4;
    // 0x80065014: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80065018: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006501C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80065020: addiu       $a1, $a1, -0x2BA4
    ctx->r5 = ADD32(ctx->r5, -0X2BA4);
    // 0x80065024: jal         0x8006CF08
    // 0x80065028: addiu       $a0, $a0, -0x2BAC
    ctx->r4 = ADD32(ctx->r4, -0X2BAC);
    debug_print2(rdram, ctx);
        goto after_5;
    // 0x80065028: addiu       $a0, $a0, -0x2BAC
    ctx->r4 = ADD32(ctx->r4, -0X2BAC);
    after_5:
    // 0x8006502C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80065030: addiu       $at, $zero, -0x4000
    ctx->r1 = ADD32(0, -0X4000);
    // 0x80065034: lh          $t8, 0xE($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XE);
    // 0x80065038: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006503C: sh          $t8, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r24;
    // 0x80065040: lh          $t9, 0x10($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X10);
    // 0x80065044: sh          $zero, 0x46($sp)
    MEM_H(0X46, ctx->r29) = 0;
    // 0x80065048: sh          $zero, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = 0;
    // 0x8006504C: sh          $zero, 0x48($sp)
    MEM_H(0X48, ctx->r29) = 0;
    // 0x80065050: sh          $t9, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r25;
    // 0x80065054: lhu         $t0, 0x8($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X8);
    // 0x80065058: nop

    // 0x8006505C: andi        $t1, $t0, 0x3FFF
    ctx->r9 = ctx->r8 & 0X3FFF;
    // 0x80065060: sh          $t1, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r9;
    // 0x80065064: lhu         $t2, 0x8($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X8);
    // 0x80065068: lhu         $s0, 0x8($t7)
    ctx->r16 = MEM_HU(ctx->r15, 0X8);
    // 0x8006506C: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80065070: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80065074: beq         $at, $zero, L_80065110
    if (ctx->r1 == 0) {
        // 0x80065078: sh          $t3, 0x8($t7)
        MEM_H(0X8, ctx->r15) = ctx->r11;
            goto L_80065110;
    }
    // 0x80065078: sh          $t3, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r11;
L_8006507C:
    // 0x8006507C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80065080: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80065084: jal         0x80064CE0
    // 0x80065088: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    MobilePiece_Minos_setUpdateFlag(rdram, ctx);
        goto after_6;
    // 0x80065088: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_6:
    // 0x8006508C: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80065090: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80065094: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80065098: lh          $t4, 0x38($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X38);
    // 0x8006509C: lh          $t5, 0x3A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X3A);
    // 0x800650A0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800650A4: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x800650A8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800650AC: sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    // 0x800650B0: sh          $t4, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r12;
    // 0x800650B4: sh          $t5, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r13;
    // 0x800650B8: addu        $s2, $t6, $t8
    ctx->r18 = ADD32(ctx->r14, ctx->r24);
    // 0x800650BC: lbu         $t9, 0x19($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X19);
    // 0x800650C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800650C4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800650C8: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800650CC: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x800650D0: sb          $t0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r8;
    // 0x800650D4: addiu       $a1, $a1, -0x2B84
    ctx->r5 = ADD32(ctx->r5, -0X2B84);
    // 0x800650D8: jal         0x8006CF08
    // 0x800650DC: addiu       $a0, $a0, -0x2B8C
    ctx->r4 = ADD32(ctx->r4, -0X2B8C);
    debug_print2(rdram, ctx);
        goto after_7;
    // 0x800650DC: addiu       $a0, $a0, -0x2B8C
    ctx->r4 = ADD32(ctx->r4, -0X2B8C);
    after_7:
    // 0x800650E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800650E4: jal         0x8006FE38
    // 0x800650E8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    Minos_Mino_Render(rdram, ctx);
        goto after_8;
    // 0x800650E8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_8:
    // 0x800650EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800650F0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800650F4: addiu       $a1, $a1, -0x2B68
    ctx->r5 = ADD32(ctx->r5, -0X2B68);
    // 0x800650F8: jal         0x8006CF08
    // 0x800650FC: addiu       $a0, $a0, -0x2B70
    ctx->r4 = ADD32(ctx->r4, -0X2B70);
    debug_print2(rdram, ctx);
        goto after_9;
    // 0x800650FC: addiu       $a0, $a0, -0x2B70
    ctx->r4 = ADD32(ctx->r4, -0X2B70);
    after_9:
    // 0x80065100: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80065104: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80065108: bne         $at, $zero, L_8006507C
    if (ctx->r1 != 0) {
        // 0x8006510C: nop
    
            goto L_8006507C;
    }
    // 0x8006510C: nop

L_80065110:
    // 0x80065110: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80065114: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80065118: sh          $s0, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r16;
    // 0x8006511C: lw          $a0, -0x3F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3F0);
    // 0x80065120: jal         0x80070F70
    // 0x80065124: nop

    Minos_EndRender(rdram, ctx);
        goto after_10;
    // 0x80065124: nop

    after_10:
    // 0x80065128: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006512C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80065130: addiu       $a1, $a1, -0x2B54
    ctx->r5 = ADD32(ctx->r5, -0X2B54);
    // 0x80065134: jal         0x8006CF08
    // 0x80065138: addiu       $a0, $a0, -0x2B5C
    ctx->r4 = ADD32(ctx->r4, -0X2B5C);
    debug_print2(rdram, ctx);
        goto after_11;
    // 0x80065138: addiu       $a0, $a0, -0x2B5C
    ctx->r4 = ADD32(ctx->r4, -0X2B5C);
    after_11:
    // 0x8006513C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80065140: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80065144: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80065148: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006514C: jr          $ra
    // 0x80065150: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80065150: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}

RECOMP_FUNC void MobilePiece_AnyCubeAboveRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065154: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80065158: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006515C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80065160: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80065164: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065168: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006516C: beq         $at, $zero, L_800651B4
    if (ctx->r1 == 0) {
        // 0x80065170: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_800651B4;
    }
    // 0x80065170: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
L_80065174:
    // 0x80065174: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80065178: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006517C: jal         0x80064E10
    // 0x80065180: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    MobilePiece_GetCubeBoardPos(rdram, ctx);
        goto after_0;
    // 0x80065180: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80065184: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x80065188: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8006518C: nop

    // 0x80065190: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80065194: beq         $at, $zero, L_800651A4
    if (ctx->r1 == 0) {
        // 0x80065198: nop
    
            goto L_800651A4;
    }
    // 0x80065198: nop

    // 0x8006519C: b           L_800651B8
    // 0x800651A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800651B8;
    // 0x800651A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800651A4:
    // 0x800651A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800651A8: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x800651AC: bne         $at, $zero, L_80065174
    if (ctx->r1 != 0) {
        // 0x800651B0: nop
    
            goto L_80065174;
    }
    // 0x800651B0: nop

L_800651B4:
    // 0x800651B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800651B8:
    // 0x800651B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800651BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800651C0: jr          $ra
    // 0x800651C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800651C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void MobilePiece_CanPlace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800651C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800651CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800651D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800651D4: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x800651D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800651DC: beq         $at, $zero, L_80065224
    if (ctx->r1 == 0) {
        // 0x800651E0: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_80065224;
    }
    // 0x800651E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
L_800651E4:
    // 0x800651E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800651E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800651EC: jal         0x80064E10
    // 0x800651F0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    MobilePiece_GetCubeBoardPos(rdram, ctx);
        goto after_0;
    // 0x800651F0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800651F4: lh          $a0, 0x20($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X20);
    // 0x800651F8: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    // 0x800651FC: jal         0x8006E4E8
    // 0x80065200: nop

    BoardP_IsPointEmpty(rdram, ctx);
        goto after_1;
    // 0x80065200: nop

    after_1:
    // 0x80065204: bne         $v0, $zero, L_80065214
    if (ctx->r2 != 0) {
        // 0x80065208: nop
    
            goto L_80065214;
    }
    // 0x80065208: nop

    // 0x8006520C: b           L_80065228
    // 0x80065210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80065228;
    // 0x80065210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80065214:
    // 0x80065214: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80065218: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8006521C: bne         $at, $zero, L_800651E4
    if (ctx->r1 != 0) {
        // 0x80065220: nop
    
            goto L_800651E4;
    }
    // 0x80065220: nop

L_80065224:
    // 0x80065224: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80065228:
    // 0x80065228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006522C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80065230: jr          $ra
    // 0x80065234: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065234: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void MobilePiece_Copy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065238: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006523C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80065240: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80065244: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065248: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8006524C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80065250: jal         0x800652E4
    // 0x80065254: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    MobilePiece_CopyTransform(rdram, ctx);
        goto after_0;
    // 0x80065254: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80065258: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8006525C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80065260: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80065264: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80065268: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8006526C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80065270: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80065274: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80065278: nop

    // 0x8006527C: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
L_80065280:
    // 0x80065280: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80065284: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80065288: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x8006528C: addu        $t3, $t3, $s0
    ctx->r11 = ADD32(ctx->r11, ctx->r16);
    // 0x80065290: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80065294: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80065298: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8006529C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800652A0: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x800652A4: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x800652A8: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800652AC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800652B0: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x800652B4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800652B8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x800652BC: jal         0x80070398
    // 0x800652C0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    Minos_Mino_Copy(rdram, ctx);
        goto after_1;
    // 0x800652C0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_1:
    // 0x800652C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800652C8: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x800652CC: bne         $at, $zero, L_80065280
    if (ctx->r1 != 0) {
        // 0x800652D0: nop
    
            goto L_80065280;
    }
    // 0x800652D0: nop

    // 0x800652D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800652D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800652DC: jr          $ra
    // 0x800652E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800652E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void MobilePiece_CopyTransform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800652E4: lhu         $t6, 0x8($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X8);
    // 0x800652E8: nop

    // 0x800652EC: sh          $t6, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r14;
    // 0x800652F0: lwl         $at, 0xA($a1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r5, 0XA);
    // 0x800652F4: lwr         $at, 0xD($a1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r5, 0XD);
    // 0x800652F8: nop

    // 0x800652FC: swl         $at, 0xA($a0)
    do_swl(rdram, 0XA, ctx->r4, ctx->r1);
    // 0x80065300: swr         $at, 0xD($a0)
    do_swr(rdram, 0XD, ctx->r4, ctx->r1);
    // 0x80065304: lwl         $at, 0xE($a1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r5, 0XE);
    // 0x80065308: lwr         $at, 0x11($a1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r5, 0X11);
    // 0x8006530C: nop

    // 0x80065310: swl         $at, 0xE($a0)
    do_swl(rdram, 0XE, ctx->r4, ctx->r1);
    // 0x80065314: jr          $ra
    // 0x80065318: swr         $at, 0x11($a0)
    do_swr(rdram, 0X11, ctx->r4, ctx->r1);
    return;
    // 0x80065318: swr         $at, 0x11($a0)
    do_swr(rdram, 0X11, ctx->r4, ctx->r1);
;}

RECOMP_FUNC void MobilePiece_8006531c_fourliner_calls_fun_loops_4_times_v1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006531C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80065320: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80065324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065328: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006532C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80065330: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80065334:
    // 0x80065334: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80065338: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x8006533C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80065340: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80065344: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80065348: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8006534C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80065350: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80065354: jal         0x80070820
    // 0x80065358: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    Minos_80070820_fiveliner_sets_arg0_2_4_8_12_to_arg1(rdram, ctx);
        goto after_0;
    // 0x80065358: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x8006535C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80065360: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80065364: bne         $at, $zero, L_80065334
    if (ctx->r1 != 0) {
        // 0x80065368: nop
    
            goto L_80065334;
    }
    // 0x80065368: nop

    // 0x8006536C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065370: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80065374: jr          $ra
    // 0x80065378: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065378: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void MobilePiece_SetCubesColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006537C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80065380: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80065384: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065388: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006538C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80065390: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80065394: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80065398:
    // 0x80065398: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8006539C: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x800653A0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800653A4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800653A8: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x800653AC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800653B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800653B4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800653B8: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800653BC: jal         0x80070860
    // 0x800653C0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    Minos_80070860_fortyliner(rdram, ctx);
        goto after_0;
    // 0x800653C0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x800653C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800653C8: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x800653CC: bne         $at, $zero, L_80065398
    if (ctx->r1 != 0) {
        // 0x800653D0: nop
    
            goto L_80065398;
    }
    // 0x800653D0: nop

    // 0x800653D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800653D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800653DC: jr          $ra
    // 0x800653E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800653E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void MobilePiece_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800653E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800653E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800653EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800653F0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800653F4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800653F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800653FC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80065400: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80065404: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80065408: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8006540C: addiu       $t9, $sp, 0x30
    ctx->r25 = ADD32(ctx->r29, 0X30);
    // 0x80065410: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80065414: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80065418: addiu       $t3, $sp, 0x34
    ctx->r11 = ADD32(ctx->r29, 0X34);
    // 0x8006541C: swl         $at, 0xE($t8)
    do_swl(rdram, 0XE, ctx->r24, ctx->r1);
    // 0x80065420: swr         $at, 0x11($t8)
    do_swr(rdram, 0X11, ctx->r24, ctx->r1);
    // 0x80065424: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80065428: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8006542C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80065430: swl         $at, 0xA($t2)
    do_swl(rdram, 0XA, ctx->r10, ctx->r1);
    // 0x80065434: swr         $at, 0xD($t2)
    do_swr(rdram, 0XD, ctx->r10, ctx->r1);
    // 0x80065438: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8006543C: lhu         $t6, 0x3A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3A);
    // 0x80065440: nop

    // 0x80065444: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x80065448: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006544C: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x80065450: nop

    // 0x80065454: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
L_80065458:
    // 0x80065458: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x8006545C: addu        $t1, $t1, $s0
    ctx->r9 = ADD32(ctx->r9, ctx->r16);
    // 0x80065460: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80065464: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80065468: subu        $t1, $t1, $s0
    ctx->r9 = SUB32(ctx->r9, ctx->r16);
    // 0x8006546C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80065470: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x80065474: jal         0x800702E4
    // 0x80065478: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    Minos_800702e4_nineliner(rdram, ctx);
        goto after_0;
    // 0x80065478: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x8006547C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80065480: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80065484: bne         $at, $zero, L_80065458
    if (ctx->r1 != 0) {
        // 0x80065488: nop
    
            goto L_80065458;
    }
    // 0x80065488: nop

    // 0x8006548C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80065490: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80065494: lw          $a1, 0x18($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X18);
    // 0x80065498: jal         0x8006531C
    // 0x8006549C: nop

    MobilePiece_8006531c_fourliner_calls_fun_loops_4_times_v1(rdram, ctx);
        goto after_1;
    // 0x8006549C: nop

    after_1:
    // 0x800654A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800654A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800654A8: jr          $ra
    // 0x800654AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800654AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void MobilePiece_ToggleAltColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800654B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800654B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800654B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800654BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800654C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800654C4: lbu         $s0, 0x1($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0X1);
    // 0x800654C8: nop

    // 0x800654CC: beq         $s0, $zero, L_800654E4
    if (ctx->r16 == 0) {
        // 0x800654D0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800654E4;
    }
    // 0x800654D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800654D4: beq         $s0, $at, L_8006550C
    if (ctx->r16 == ctx->r1) {
        // 0x800654D8: nop
    
            goto L_8006550C;
    }
    // 0x800654D8: nop

    // 0x800654DC: b           L_8006552C
    // 0x800654E0: nop

        goto L_8006552C;
    // 0x800654E0: nop

L_800654E4:
    // 0x800654E4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800654E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800654EC: sb          $t7, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r15;
    // 0x800654F0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800654F4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x800654F8: lw          $a0, 0x1C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X1C);
    // 0x800654FC: jal         0x8006537C
    // 0x80065500: addiu       $a1, $t9, 0x2
    ctx->r5 = ADD32(ctx->r25, 0X2);
    MobilePiece_SetCubesColor(rdram, ctx);
        goto after_0;
    // 0x80065500: addiu       $a1, $t9, 0x2
    ctx->r5 = ADD32(ctx->r25, 0X2);
    after_0:
    // 0x80065504: b           L_8006552C
    // 0x80065508: nop

        goto L_8006552C;
    // 0x80065508: nop

L_8006550C:
    // 0x8006550C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80065510: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80065514: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x80065518: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8006551C: nop

    // 0x80065520: lw          $a0, 0x1C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X1C);
    // 0x80065524: jal         0x8006537C
    // 0x80065528: addiu       $a1, $t1, 0xE
    ctx->r5 = ADD32(ctx->r9, 0XE);
    MobilePiece_SetCubesColor(rdram, ctx);
        goto after_1;
    // 0x80065528: addiu       $a1, $t1, 0xE
    ctx->r5 = ADD32(ctx->r9, 0XE);
    after_1:
L_8006552C:
    // 0x8006552C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065530: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80065534: jr          $ra
    // 0x80065538: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065538: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void MobilePiece_InitFromPiece(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006553C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80065540: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    // 0x80065544: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80065548: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006554C: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80065550: addiu       $t0, $t0, -0x4
    ctx->r8 = ADD32(ctx->r8, -0X4);
    // 0x80065554: lwl         $at, 0x0($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X0);
    // 0x80065558: lwr         $at, 0x3($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0X3);
    // 0x8006555C: nop

    // 0x80065560: swl         $at, 0xE($a0)
    do_swl(rdram, 0XE, ctx->r4, ctx->r1);
    // 0x80065564: swr         $at, 0x11($a0)
    do_swr(rdram, 0X11, ctx->r4, ctx->r1);
    // 0x80065568: lwl         $t9, 0x4($t7)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r15, 0X4);
    // 0x8006556C: lwr         $t9, 0x7($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, 0X7);
    // 0x80065570: nop

    // 0x80065574: swl         $t9, 0x12($a0)
    do_swl(rdram, 0X12, ctx->r4, ctx->r25);
    // 0x80065578: swr         $t9, 0x15($a0)
    do_swr(rdram, 0X15, ctx->r4, ctx->r25);
    // 0x8006557C: lwl         $at, 0x8($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X8);
    // 0x80065580: lwr         $at, 0xB($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0XB);
    // 0x80065584: nop

    // 0x80065588: swl         $at, 0x16($a0)
    do_swl(rdram, 0X16, ctx->r4, ctx->r1);
    // 0x8006558C: swr         $at, 0x19($a0)
    do_swr(rdram, 0X19, ctx->r4, ctx->r1);
    // 0x80065590: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80065594: nop

    // 0x80065598: swl         $at, 0x2($a0)
    do_swl(rdram, 0X2, ctx->r4, ctx->r1);
    // 0x8006559C: swr         $at, 0x5($a0)
    do_swr(rdram, 0X5, ctx->r4, ctx->r1);
    // 0x800655A0: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x800655A4: nop

    // 0x800655A8: swl         $t2, 0x6($a0)
    do_swl(rdram, 0X6, ctx->r4, ctx->r10);
    // 0x800655AC: swr         $t2, 0x9($a0)
    do_swr(rdram, 0X9, ctx->r4, ctx->r10);
    // 0x800655B0: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x800655B4: nop

    // 0x800655B8: swl         $at, 0xA($a0)
    do_swl(rdram, 0XA, ctx->r4, ctx->r1);
    // 0x800655BC: jr          $ra
    // 0x800655C0: swr         $at, 0xD($a0)
    do_swr(rdram, 0XD, ctx->r4, ctx->r1);
    return;
    // 0x800655C0: swr         $at, 0xD($a0)
    do_swr(rdram, 0XD, ctx->r4, ctx->r1);
;}

RECOMP_FUNC void MobilePiece_UpdateAltColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800655C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800655C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800655CC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800655D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800655D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800655D8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800655DC: nop

    // 0x800655E0: beq         $t7, $zero, L_80065610
    if (ctx->r15 == 0) {
        // 0x800655E4: nop
    
            goto L_80065610;
    }
    // 0x800655E4: nop

    // 0x800655E8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800655EC: nop

    // 0x800655F0: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x800655F4: nop

    // 0x800655F8: lbu         $t0, 0x1A($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1A);
    // 0x800655FC: nop

    // 0x80065600: bne         $t0, $zero, L_80065610
    if (ctx->r8 != 0) {
        // 0x80065604: nop
    
            goto L_80065610;
    }
    // 0x80065604: nop

    // 0x80065608: jal         0x800654B0
    // 0x8006560C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    MobilePiece_ToggleAltColor(rdram, ctx);
        goto after_0;
    // 0x8006560C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
L_80065610:
    // 0x80065610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065618: jr          $ra
    // 0x8006561C: nop

    return;
    // 0x8006561C: nop

;}

RECOMP_FUNC void MobilePiece_EnableAltColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065624: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065628: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006562C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065630: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80065634: nop

    // 0x80065638: bne         $t7, $zero, L_8006566C
    if (ctx->r15 != 0) {
        // 0x8006563C: nop
    
            goto L_8006566C;
    }
    // 0x8006563C: nop

    // 0x80065640: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80065644: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80065648: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8006564C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80065650: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80065654: sb          $t0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r8;
    // 0x80065658: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8006565C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80065660: lw          $a0, 0x1C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X1C);
    // 0x80065664: jal         0x8006537C
    // 0x80065668: addiu       $a1, $t2, 0x2
    ctx->r5 = ADD32(ctx->r10, 0X2);
    MobilePiece_SetCubesColor(rdram, ctx);
        goto after_0;
    // 0x80065668: addiu       $a1, $t2, 0x2
    ctx->r5 = ADD32(ctx->r10, 0X2);
    after_0:
L_8006566C:
    // 0x8006566C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065674: jr          $ra
    // 0x80065678: nop

    return;
    // 0x80065678: nop

;}

RECOMP_FUNC void MobilePiece_DisableAltColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006567C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065684: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80065688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006568C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80065690: nop

    // 0x80065694: beq         $t7, $zero, L_800656BC
    if (ctx->r15 == 0) {
        // 0x80065698: nop
    
            goto L_800656BC;
    }
    // 0x80065698: nop

    // 0x8006569C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800656A0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800656A4: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x800656A8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800656AC: nop

    // 0x800656B0: lw          $a0, 0x1C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X1C);
    // 0x800656B4: jal         0x8006537C
    // 0x800656B8: addiu       $a1, $t9, 0xE
    ctx->r5 = ADD32(ctx->r25, 0XE);
    MobilePiece_SetCubesColor(rdram, ctx);
        goto after_0;
    // 0x800656B8: addiu       $a1, $t9, 0xE
    ctx->r5 = ADD32(ctx->r25, 0XE);
    after_0:
L_800656BC:
    // 0x800656BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800656C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800656C4: jr          $ra
    // 0x800656C8: nop

    return;
    // 0x800656C8: nop

;}

RECOMP_FUNC void MobilePiece_SetAlternateColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800656CC: lwl         $at, 0x0($a1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r5, 0X0);
    // 0x800656D0: lwr         $at, 0x3($a1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r5, 0X3);
    // 0x800656D4: nop

    // 0x800656D8: swl         $at, 0x2($a0)
    do_swl(rdram, 0X2, ctx->r4, ctx->r1);
    // 0x800656DC: swr         $at, 0x5($a0)
    do_swr(rdram, 0X5, ctx->r4, ctx->r1);
    // 0x800656E0: lwl         $t8, 0x4($a1)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r5, 0X4);
    // 0x800656E4: lwr         $t8, 0x7($a1)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r5, 0X7);
    // 0x800656E8: nop

    // 0x800656EC: swl         $t8, 0x6($a0)
    do_swl(rdram, 0X6, ctx->r4, ctx->r24);
    // 0x800656F0: swr         $t8, 0x9($a0)
    do_swr(rdram, 0X9, ctx->r4, ctx->r24);
    // 0x800656F4: lwl         $at, 0x8($a1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r5, 0X8);
    // 0x800656F8: lwr         $at, 0xB($a1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r5, 0XB);
    // 0x800656FC: nop

    // 0x80065700: swl         $at, 0xA($a0)
    do_swl(rdram, 0XA, ctx->r4, ctx->r1);
    // 0x80065704: jr          $ra
    // 0x80065708: swr         $at, 0xD($a0)
    do_swr(rdram, 0XD, ctx->r4, ctx->r1);
    return;
    // 0x80065708: swr         $at, 0xD($a0)
    do_swr(rdram, 0XD, ctx->r4, ctx->r1);
    // 0x8006570C: nop

;}

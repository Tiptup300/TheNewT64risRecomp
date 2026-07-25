#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Smoke_Diffuse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074D7C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80074D80: lhu         $t6, 0x20B0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X20B0);
    // 0x80074D84: lbu         $t0, 0x15($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X15);
    // 0x80074D88: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80074D8C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80074D90: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80074D94: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80074D98: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80074D9C: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    // 0x80074DA0: lw          $a2, 0xC($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XC);
    // 0x80074DA4: lbu         $t1, 0x14($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X14);
    // 0x80074DA8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80074DAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074DB0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80074DB4: blez        $t0, L_80074E34
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80074DB8: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80074E34;
    }
    // 0x80074DB8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80074DBC:
    // 0x80074DBC: lbu         $a3, 0x14($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X14);
    // 0x80074DC0: nop

    // 0x80074DC4: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    // 0x80074DC8: blez        $a3, L_80074E24
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80074DCC: nop
    
            goto L_80074E24;
    }
    // 0x80074DCC: nop

L_80074DD0:
    // 0x80074DD0: addu        $t5, $a1, $t1
    ctx->r13 = ADD32(ctx->r5, ctx->r9);
    // 0x80074DD4: addu        $t8, $a1, $t1
    ctx->r24 = ADD32(ctx->r5, ctx->r9);
    // 0x80074DD8: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x80074DDC: lbu         $t7, -0x1($t5)
    ctx->r15 = MEM_BU(ctx->r13, -0X1);
    // 0x80074DE0: addu        $t3, $a1, $t1
    ctx->r11 = ADD32(ctx->r5, ctx->r9);
    // 0x80074DE4: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80074DE8: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x80074DEC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80074DF0: addu        $t5, $t6, $t4
    ctx->r13 = ADD32(ctx->r14, ctx->r12);
    // 0x80074DF4: addu        $t2, $t8, $t5
    ctx->r10 = ADD32(ctx->r24, ctx->r13);
    // 0x80074DF8: sra         $t7, $t2, 2
    ctx->r15 = S32(SIGNED(ctx->r10) >> 2);
    // 0x80074DFC: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x80074E00: addiu       $t2, $t2, -0x4
    ctx->r10 = ADD32(ctx->r10, -0X4);
    // 0x80074E04: bgez        $t2, L_80074E10
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80074E08: nop
    
            goto L_80074E10;
    }
    // 0x80074E08: nop

    // 0x80074E0C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_80074E10:
    // 0x80074E10: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80074E14: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80074E18: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80074E1C: bgtz        $a3, L_80074DD0
    if (SIGNED(ctx->r7) > 0) {
        // 0x80074E20: sb          $t2, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r10;
            goto L_80074DD0;
    }
    // 0x80074E20: sb          $t2, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r10;
L_80074E24:
    // 0x80074E24: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80074E28: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80074E2C: bgtz        $t0, L_80074DBC
    if (SIGNED(ctx->r8) > 0) {
        // 0x80074E30: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_80074DBC;
    }
    // 0x80074E30: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_80074E34:
    // 0x80074E34: jr          $ra
    // 0x80074E38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80074E38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Smoke_SeedRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074E3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80074E40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80074E44: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80074E48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074E4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80074E50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80074E54: lbu         $t2, 0x15($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X15);
    // 0x80074E58: lbu         $t1, 0x14($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X14);
    // 0x80074E5C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80074E60: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80074E64: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80074E68: lhu         $t7, 0x20B0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X20B0);
    // 0x80074E6C: lbu         $s1, 0x14($t6)
    ctx->r17 = MEM_BU(ctx->r14, 0X14);
    // 0x80074E70: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x80074E74: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80074E78: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80074E7C: lw          $s0, 0xC($t0)
    ctx->r16 = MEM_W(ctx->r8, 0XC);
    // 0x80074E80: addiu       $s1, $s1, -0x2
    ctx->r17 = ADD32(ctx->r17, -0X2);
    // 0x80074E84: mflo        $t4
    ctx->r12 = lo;
    // 0x80074E88: addu        $s0, $s0, $t4
    ctx->r16 = ADD32(ctx->r16, ctx->r12);
    // 0x80074E8C: blez        $s1, L_80074EB0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80074E90: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80074EB0;
    }
    // 0x80074E90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80074E94:
    // 0x80074E94: jal         0x80060814
    // 0x80074E98: nop

    Rand_Next(rdram, ctx);
        goto after_0;
    // 0x80074E98: nop

    after_0:
    // 0x80074E9C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80074EA0: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x80074EA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074EA8: bgtz        $s1, L_80074E94
    if (SIGNED(ctx->r17) > 0) {
        // 0x80074EAC: sb          $t5, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r13;
            goto L_80074E94;
    }
    // 0x80074EAC: sb          $t5, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r13;
L_80074EB0:
    // 0x80074EB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074EB4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80074EB8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80074EBC: jr          $ra
    // 0x80074EC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80074EC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Smoke_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074EC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80074EC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80074ECC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074ED0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80074ED4: jal         0x80074D7C
    // 0x80074ED8: nop

    Smoke_Diffuse(rdram, ctx);
        goto after_0;
    // 0x80074ED8: nop

    after_0:
    // 0x80074EDC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80074EE0: nop

    // 0x80074EE4: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x80074EE8: lhu         $a1, 0x4($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X4);
    // 0x80074EEC: lbu         $a2, 0x14($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X14);
    // 0x80074EF0: lbu         $a3, 0x15($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X15);
    // 0x80074EF4: jal         0x80074B80
    // 0x80074EF8: nop

    Particle_Update(rdram, ctx);
        goto after_1;
    // 0x80074EF8: nop

    after_1:
    // 0x80074EFC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80074F00: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80074F04: lhu         $t8, 0x20B0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X20B0);
    // 0x80074F08: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x80074F0C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80074F10: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80074F14: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80074F18: lhu         $a1, 0x4($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X4);
    // 0x80074F1C: lbu         $a2, 0x14($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X14);
    // 0x80074F20: lbu         $a3, 0x15($t7)
    ctx->r7 = MEM_BU(ctx->r15, 0X15);
    // 0x80074F24: jal         0x80074C80
    // 0x80074F28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    Particle_Render(rdram, ctx);
        goto after_2;
    // 0x80074F28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_2:
    // 0x80074F2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074F30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80074F34: jr          $ra
    // 0x80074F38: nop

    return;
    // 0x80074F38: nop

;}

RECOMP_FUNC void Smoke_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074F3C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80074F40: lw          $a1, 0x20C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X20C0);
    // 0x80074F44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074F48: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80074F4C: lbu         $t6, 0x14($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X14);
    // 0x80074F50: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80074F54: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80074F58: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80074F5C: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x80074F60: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80074F64: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80074F68: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80074F6C: lhu         $t1, 0x20B0($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X20B0);
    // 0x80074F70: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80074F74: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80074F78: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80074F7C: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80074F80: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80074F84: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x80074F88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80074F8C: lbu         $t6, 0x14($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X14);
    // 0x80074F90: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80074F94: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x80074F98: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80074F9C: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80074FA0: sll         $t0, $t9, 9
    ctx->r8 = S32(ctx->r25 << 9);
    // 0x80074FA4: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x80074FA8: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80074FAC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80074FB0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80074FB4: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x80074FB8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80074FBC: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80074FC0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80074FC4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80074FC8: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x80074FCC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80074FD0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80074FD4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80074FD8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80074FDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80074FE0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80074FE4: lui         $t8, 0xF400
    ctx->r24 = S32(0XF400 << 16);
    // 0x80074FE8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80074FEC: lbu         $t0, 0x14($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X14);
    // 0x80074FF0: lbu         $t6, 0x15($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15);
    // 0x80074FF4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80074FF8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80074FFC: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x80075000: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80075004: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80075008: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x8007500C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80075010: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80075014: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80075018: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8007501C: or          $t0, $t5, $t9
    ctx->r8 = ctx->r13 | ctx->r25;
    // 0x80075020: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80075024: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80075028: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8007502C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80075030: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80075034: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80075038: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8007503C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80075040: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80075044: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x80075048: lbu         $t6, 0x14($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X14);
    // 0x8007504C: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80075050: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x80075054: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80075058: andi        $t5, $t8, 0x1FF
    ctx->r13 = ctx->r24 & 0X1FF;
    // 0x8007505C: sll         $t9, $t5, 9
    ctx->r25 = S32(ctx->r13 << 9);
    // 0x80075060: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x80075064: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x80075068: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8007506C: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x80075070: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80075074: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80075078: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x8007507C: lw          $t4, 0x10($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10);
    // 0x80075080: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x80075084: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80075088: lbu         $t6, 0x14($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X14);
    // 0x8007508C: lbu         $t0, 0x15($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X15);
    // 0x80075090: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80075094: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80075098: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8007509C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800750A0: andi        $t5, $t8, 0xFFF
    ctx->r13 = ctx->r24 & 0XFFF;
    // 0x800750A4: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800750A8: sll         $t9, $t5, 12
    ctx->r25 = S32(ctx->r13 << 12);
    // 0x800750AC: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x800750B0: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x800750B4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800750B8: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x800750BC: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x800750C0: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800750C4: lbu         $t8, 0x14($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X14);
    // 0x800750C8: lh          $t3, 0x2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2);
    // 0x800750CC: lbu         $t4, 0x15($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X15);
    // 0x800750D0: addu        $t5, $t7, $t8
    ctx->r13 = ADD32(ctx->r15, ctx->r24);
    // 0x800750D4: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x800750D8: andi        $t1, $t0, 0xFFF
    ctx->r9 = ctx->r8 & 0XFFF;
    // 0x800750DC: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x800750E0: addiu       $t7, $t6, -0x3
    ctx->r15 = ADD32(ctx->r14, -0X3);
    // 0x800750E4: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x800750E8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800750EC: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800750F0: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800750F4: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x800750F8: andi        $t5, $t8, 0xFFF
    ctx->r13 = ctx->r24 & 0XFFF;
    // 0x800750FC: or          $t0, $t9, $t5
    ctx->r8 = ctx->r25 | ctx->r13;
    // 0x80075100: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80075104: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x80075108: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x8007510C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80075110: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x80075114: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80075118: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8007511C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80075120: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x80075124: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x80075128: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8007512C: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x80075130: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
    // 0x80075134: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x80075138: lui         $t1, 0xE100
    ctx->r9 = S32(0XE100 << 16);
    // 0x8007513C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80075140: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x80075144: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80075148: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8007514C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80075150: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80075154: lui         $t4, 0xF100
    ctx->r12 = S32(0XF100 << 16);
    // 0x80075158: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8007515C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80075160: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80075164: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80075168: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8007516C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80075170: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80075174: sw          $a1, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r5;
    // 0x80075178: jr          $ra
    // 0x8007517C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007517C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void Smoke_SetOrigin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075218: lbu         $t6, 0x14($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X14);
    // 0x8007521C: lbu         $t9, 0x15($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X15);
    // 0x80075220: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80075224: subu        $t0, $a2, $t9
    ctx->r8 = SUB32(ctx->r6, ctx->r25);
    // 0x80075228: subu        $t8, $a1, $t7
    ctx->r24 = SUB32(ctx->r5, ctx->r15);
    // 0x8007522C: addiu       $t1, $t0, 0x3
    ctx->r9 = ADD32(ctx->r8, 0X3);
    // 0x80075230: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x80075234: jr          $ra
    // 0x80075238: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    return;
    // 0x80075238: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
;}

RECOMP_FUNC void Smoke_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007523C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80075240: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80075244: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80075248: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007524C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80075250: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80075254: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80075258: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x8007525C: nop

    // 0x80075260: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x80075264: sb          $t8, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r24;
    // 0x80075268: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007526C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80075270: lbu         $at, 0x0($t0)
    ctx->r1 = MEM_BU(ctx->r8, 0X0);
    // 0x80075274: nop

    // 0x80075278: sb          $at, 0x14($t9)
    MEM_B(0X14, ctx->r25) = ctx->r1;
    // 0x8007527C: lbu         $t2, 0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X1);
    // 0x80075280: nop

    // 0x80075284: sb          $t2, 0x15($t9)
    MEM_B(0X15, ctx->r25) = ctx->r10;
    // 0x80075288: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007528C: nop

    // 0x80075290: lbu         $t4, 0x14($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X14);
    // 0x80075294: lbu         $t5, 0x15($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X15);
    // 0x80075298: nop

    // 0x8007529C: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800752A0: mflo        $t7
    ctx->r15 = lo;
    // 0x800752A4: sh          $t7, 0x16($t3)
    MEM_H(0X16, ctx->r11) = ctx->r15;
    // 0x800752A8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800752AC: nop

    // 0x800752B0: lhu         $t6, 0x16($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X16);
    // 0x800752B4: nop

    // 0x800752B8: sh          $t6, 0x18($t8)
    MEM_H(0X18, ctx->r24) = ctx->r14;
    // 0x800752BC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800752C0: nop

    // 0x800752C4: lhu         $t9, 0x18($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X18);
    // 0x800752C8: nop

    // 0x800752CC: slti        $at, $t9, 0x1000
    ctx->r1 = SIGNED(ctx->r25) < 0X1000 ? 1 : 0;
    // 0x800752D0: bne         $at, $zero, L_800752E0
    if (ctx->r1 != 0) {
        // 0x800752D4: nop
    
            goto L_800752E0;
    }
    // 0x800752D4: nop

    // 0x800752D8: b           L_800753EC
    // 0x800752DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800753EC;
    // 0x800752DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800752E0:
    // 0x800752E0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800752E4: nop

    // 0x800752E8: lhu         $a0, 0x18($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X18);
    // 0x800752EC: jal         0x8007E03C
    // 0x800752F0: nop

    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800752F0: nop

    after_0:
    // 0x800752F4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800752F8: nop

    // 0x800752FC: sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
    // 0x80075300: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80075304: nop

    // 0x80075308: lhu         $a0, 0x18($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X18);
    // 0x8007530C: jal         0x8007E03C
    // 0x80075310: nop

    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80075310: nop

    after_1:
    // 0x80075314: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80075318: nop

    // 0x8007531C: sw          $v0, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r2;
    // 0x80075320: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80075324: nop

    // 0x80075328: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    // 0x8007532C: lhu         $a1, 0x18($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X18);
    // 0x80075330: jal         0x800B7450
    // 0x80075334: nop

    bzero_recomp(rdram, ctx);
        goto after_2;
    // 0x80075334: nop

    after_2:
    // 0x80075338: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007533C: nop

    // 0x80075340: lw          $a0, 0x10($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X10);
    // 0x80075344: lhu         $a1, 0x18($t3)
    ctx->r5 = MEM_HU(ctx->r11, 0X18);
    // 0x80075348: jal         0x800B7450
    // 0x8007534C: nop

    bzero_recomp(rdram, ctx);
        goto after_3;
    // 0x8007534C: nop

    after_3:
    // 0x80075350: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80075354: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80075358: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x8007535C: nop

    // 0x80075360: sh          $t8, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r24;
    // 0x80075364: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80075368: nop

    // 0x8007536C: lhu         $a0, 0x4($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X4);
    // 0x80075370: nop

    // 0x80075374: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80075378: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8007537C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80075380: jal         0x8007E03C
    // 0x80075384: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x80075384: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_4:
    // 0x80075388: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007538C: nop

    // 0x80075390: sw          $v0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r2;
    // 0x80075394: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80075398: nop

    // 0x8007539C: lhu         $s0, 0x4($t4)
    ctx->r16 = MEM_HU(ctx->r12, 0X4);
    // 0x800753A0: lw          $s1, 0x8($t4)
    ctx->r17 = MEM_W(ctx->r12, 0X8);
    // 0x800753A4: blez        $s0, L_800753D0
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800753A8: nop
    
            goto L_800753D0;
    }
    // 0x800753A8: nop

L_800753AC:
    // 0x800753AC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800753B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800753B4: lbu         $a1, 0x14($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X14);
    // 0x800753B8: lbu         $a2, 0x15($t5)
    ctx->r6 = MEM_BU(ctx->r13, 0X15);
    // 0x800753BC: jal         0x800749A0
    // 0x800753C0: nop

    Particle_Spawn(rdram, ctx);
        goto after_5;
    // 0x800753C0: nop

    after_5:
    // 0x800753C4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800753C8: bgtz        $s0, L_800753AC
    if (SIGNED(ctx->r16) > 0) {
        // 0x800753CC: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_800753AC;
    }
    // 0x800753CC: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_800753D0:
    // 0x800753D0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800753D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800753D8: lh          $a1, 0x2($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X2);
    // 0x800753DC: lh          $a2, 0x4($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X4);
    // 0x800753E0: jal         0x80075218
    // 0x800753E4: nop

    Smoke_SetOrigin(rdram, ctx);
        goto after_6;
    // 0x800753E4: nop

    after_6:
    // 0x800753E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800753EC:
    // 0x800753EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800753F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800753F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800753F8: jr          $ra
    // 0x800753FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800753FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Smoke_Free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075404: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80075408: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8007540C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075410: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x80075414: jal         0x8007E328
    // 0x80075418: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x80075418: nop

    after_0:
    // 0x8007541C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80075420: nop

    // 0x80075424: sw          $zero, 0x8($t7)
    MEM_W(0X8, ctx->r15) = 0;
    // 0x80075428: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8007542C: nop

    // 0x80075430: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    // 0x80075434: jal         0x8007E328
    // 0x80075438: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x80075438: nop

    after_1:
    // 0x8007543C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80075440: nop

    // 0x80075444: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    // 0x80075448: jal         0x8007E328
    // 0x8007544C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_2;
    // 0x8007544C: nop

    after_2:
    // 0x80075450: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80075454: nop

    // 0x80075458: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x8007545C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80075460: nop

    // 0x80075464: sw          $zero, 0x10($t1)
    MEM_W(0X10, ctx->r9) = 0;
    // 0x80075468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007546C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075470: jr          $ra
    // 0x80075474: nop

    return;
    // 0x80075474: nop

    // 0x80075478: nop

    // 0x8007547C: nop

;}

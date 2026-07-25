#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void main_infinite_loop_at_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049C70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80049C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049C78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049C7C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80049C80: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80049C84: sb          $zero, -0x1CC($at)
    MEM_B(-0X1CC, ctx->r1) = 0;
    // 0x80049C88: addiu       $a0, $a0, 0x558
    ctx->r4 = ADD32(ctx->r4, 0X558);
    // 0x80049C8C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80049C90: jal         0x800B3C20
    // 0x80049C94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80049C94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80049C98: lui         $a0, 0x8
    ctx->r4 = S32(0X8 << 16);
    // 0x80049C9C: jal         0x800B6A90
    // 0x80049CA0: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80049CA0: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    after_1:
    // 0x80049CA4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80049CA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049CAC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80049CB0: jal         0x80061198
    // 0x80049CB4: sb          $t6, -0x1CC($at)
    MEM_B(-0X1CC, ctx->r1) = ctx->r14;
    func_80061198(rdram, ctx);
        goto after_2;
    // 0x80049CB4: sb          $t6, -0x1CC($at)
    MEM_B(-0X1CC, ctx->r1) = ctx->r14;
    after_2:
    // 0x80049CB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80049CBC: jal         0x800B6A90
    // 0x80049CC0: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x80049CC0: nop

    after_3:
L_80049CC4:
    // 0x80049CC4: b           L_80049CC4
    pause_self(rdram);
    // 0x80049CC8: nop

    // 0x80049CCC: nop

    // 0x80049CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049CD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80049CD8: jr          $ra
    // 0x80049CDC: nop

    return;
    // 0x80049CDC: nop

;}

RECOMP_FUNC void boot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049CE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80049CE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80049CE8: jal         0x800B6B30
    // 0x80049CEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    osInitialize_recomp(rdram, ctx);
        goto after_0;
    // 0x80049CEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80049CF0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80049CF4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80049CF8: addiu       $a1, $a1, 0x458
    ctx->r5 = ADD32(ctx->r5, 0X458);
    // 0x80049CFC: addiu       $a0, $a0, 0x558
    ctx->r4 = ADD32(ctx->r4, 0X558);
    // 0x80049D00: jal         0x800B3080
    // 0x80049D04: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80049D04: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_1:
    // 0x80049D08: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80049D0C: addiu       $a1, $a1, 0x558
    ctx->r5 = ADD32(ctx->r5, 0X558);
    // 0x80049D10: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80049D14: jal         0x800B30B0
    // 0x80049D18: addiu       $a2, $zero, 0x309
    ctx->r6 = ADD32(0, 0X309);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80049D18: addiu       $a2, $zero, 0x309
    ctx->r6 = ADD32(0, 0X309);
    after_2:
    // 0x80049D1C: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    // 0x80049D20: jal         0x80061134
    // 0x80049D24: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    PFGFX_ClearCellGrids(rdram, ctx);
        goto after_3;
    // 0x80049D24: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_3:
    // 0x80049D28: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80049D2C: addiu       $t6, $t6, 0x76D0
    ctx->r14 = ADD32(ctx->r14, 0X76D0);
    // 0x80049D30: addiu       $t7, $t6, 0x2000
    ctx->r15 = ADD32(ctx->r14, 0X2000);
    // 0x80049D34: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80049D38: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80049D3C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80049D40: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80049D44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80049D48: addiu       $a2, $a2, -0x6288
    ctx->r6 = ADD32(ctx->r6, -0X6288);
    // 0x80049D4C: addiu       $a0, $a0, 0x3370
    ctx->r4 = ADD32(ctx->r4, 0X3370);
    // 0x80049D50: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80049D54: jal         0x800B6010
    // 0x80049D58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    osCreateThread_recomp(rdram, ctx);
        goto after_4;
    // 0x80049D58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80049D5C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80049D60: jal         0x800B6160
    // 0x80049D64: addiu       $a0, $a0, 0x3370
    ctx->r4 = ADD32(ctx->r4, 0X3370);
    osStartThread_recomp(rdram, ctx);
        goto after_5;
    // 0x80049D64: addiu       $a0, $a0, 0x3370
    ctx->r4 = ADD32(ctx->r4, 0X3370);
    after_5:
    // 0x80049D68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80049D6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80049D70: jr          $ra
    // 0x80049D74: nop

    return;
    // 0x80049D74: nop

;}

RECOMP_FUNC void idle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049D78: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80049D7C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80049D80: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80049D84: addiu       $t6, $t6, -0x6930
    ctx->r14 = ADD32(ctx->r14, -0X6930);
    // 0x80049D88: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80049D8C: addiu       $t7, $t6, 0x2000
    ctx->r15 = ADD32(ctx->r14, 0X2000);
    // 0x80049D90: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80049D94: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80049D98: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x80049D9C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80049DA0: addiu       $a2, $a2, -0x6390
    ctx->r6 = ADD32(ctx->r6, -0X6390);
    // 0x80049DA4: addiu       $a0, $a0, 0x3520
    ctx->r4 = ADD32(ctx->r4, 0X3520);
    // 0x80049DA8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80049DAC: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x80049DB0: jal         0x800B6010
    // 0x80049DB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80049DB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80049DB8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80049DBC: jal         0x800B6160
    // 0x80049DC0: addiu       $a0, $a0, 0x3520
    ctx->r4 = ADD32(ctx->r4, 0X3520);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80049DC0: addiu       $a0, $a0, 0x3520
    ctx->r4 = ADD32(ctx->r4, 0X3520);
    after_1:
    // 0x80049DC4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80049DC8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80049DCC: addiu       $a2, $a2, -0x4930
    ctx->r6 = ADD32(ctx->r6, -0X4930);
    // 0x80049DD0: addiu       $a1, $a1, -0x4530
    ctx->r5 = ADD32(ctx->r5, -0X4530);
    // 0x80049DD4: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80049DD8: jal         0x800B6E90
    // 0x80049DDC: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_2;
    // 0x80049DDC: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_2:
    // 0x80049DE0: jal         0x800611E0
    // 0x80049DE4: nop

    func_800611E0(rdram, ctx);
        goto after_3;
    // 0x80049DE4: nop

    after_3:
    // 0x80049DE8: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80049DEC: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x80049DF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049DF4: bne         $t9, $at, L_80049E60
    if (ctx->r25 != ctx->r1) {
        // 0x80049DF8: nop
    
            goto L_80049E60;
    }
    // 0x80049DF8: nop

    // 0x80049DFC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80049E00: addiu       $t0, $t0, -0x5910
    ctx->r8 = ADD32(ctx->r8, -0X5910);
    // 0x80049E04: addiu       $t2, $t0, 0x48
    ctx->r10 = ADD32(ctx->r8, 0X48);
    // 0x80049E08: or          $t3, $sp, $zero
    ctx->r11 = ctx->r29 | 0;
L_80049E0C:
    // 0x80049E0C: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80049E10: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80049E14: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80049E18: lw          $at, -0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X8);
    // 0x80049E1C: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80049E20: sw          $at, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r1;
    // 0x80049E24: lw          $at, -0x4($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X4);
    // 0x80049E28: bne         $t0, $t2, L_80049E0C
    if (ctx->r8 != ctx->r10) {
        // 0x80049E2C: sw          $at, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r1;
            goto L_80049E0C;
    }
    // 0x80049E2C: sw          $at, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r1;
    // 0x80049E30: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80049E34: nop

    // 0x80049E38: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80049E3C: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x80049E40: nop

    // 0x80049E44: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x80049E48: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80049E4C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80049E50: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80049E54: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x80049E58: jal         0x80060D10
    // 0x80049E5C: nop

    func_80060D10(rdram, ctx);
        goto after_4;
    // 0x80049E5C: nop

    after_4:
L_80049E60:
    // 0x80049E60: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80049E64: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x80049E68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80049E6C: bne         $t4, $at, L_80049ED8
    if (ctx->r12 != ctx->r1) {
        // 0x80049E70: nop
    
            goto L_80049ED8;
    }
    // 0x80049E70: nop

    // 0x80049E74: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80049E78: addiu       $t5, $t5, -0x5870
    ctx->r13 = ADD32(ctx->r13, -0X5870);
    // 0x80049E7C: addiu       $t7, $t5, 0x48
    ctx->r15 = ADD32(ctx->r13, 0X48);
    // 0x80049E80: or          $t8, $sp, $zero
    ctx->r24 = ctx->r29 | 0;
L_80049E84:
    // 0x80049E84: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x80049E88: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80049E8C: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80049E90: lw          $at, -0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, -0X8);
    // 0x80049E94: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x80049E98: sw          $at, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r1;
    // 0x80049E9C: lw          $at, -0x4($t5)
    ctx->r1 = MEM_W(ctx->r13, -0X4);
    // 0x80049EA0: bne         $t5, $t7, L_80049E84
    if (ctx->r13 != ctx->r15) {
        // 0x80049EA4: sw          $at, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r1;
            goto L_80049E84;
    }
    // 0x80049EA4: sw          $at, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r1;
    // 0x80049EA8: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x80049EAC: nop

    // 0x80049EB0: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80049EB4: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x80049EB8: nop

    // 0x80049EBC: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80049EC0: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80049EC4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80049EC8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80049ECC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x80049ED0: jal         0x80060D10
    // 0x80049ED4: nop

    func_80060D10(rdram, ctx);
        goto after_5;
    // 0x80049ED4: nop

    after_5:
L_80049ED8:
    // 0x80049ED8: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80049EDC: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x80049EE0: nop

    // 0x80049EE4: bne         $t9, $zero, L_80049F50
    if (ctx->r25 != 0) {
        // 0x80049EE8: nop
    
            goto L_80049F50;
    }
    // 0x80049EE8: nop

    // 0x80049EEC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80049EF0: addiu       $t1, $t1, -0x5820
    ctx->r9 = ADD32(ctx->r9, -0X5820);
    // 0x80049EF4: addiu       $t0, $t1, 0x48
    ctx->r8 = ADD32(ctx->r9, 0X48);
    // 0x80049EF8: or          $t3, $sp, $zero
    ctx->r11 = ctx->r29 | 0;
L_80049EFC:
    // 0x80049EFC: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80049F00: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80049F04: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80049F08: lw          $at, -0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X8);
    // 0x80049F0C: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80049F10: sw          $at, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r1;
    // 0x80049F14: lw          $at, -0x4($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X4);
    // 0x80049F18: bne         $t1, $t0, L_80049EFC
    if (ctx->r9 != ctx->r8) {
        // 0x80049F1C: sw          $at, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r1;
            goto L_80049EFC;
    }
    // 0x80049F1C: sw          $at, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r1;
    // 0x80049F20: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80049F24: nop

    // 0x80049F28: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80049F2C: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x80049F30: nop

    // 0x80049F34: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x80049F38: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80049F3C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80049F40: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80049F44: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x80049F48: jal         0x80060D10
    // 0x80049F4C: nop

    func_80060D10(rdram, ctx);
        goto after_6;
    // 0x80049F4C: nop

    after_6:
L_80049F50:
    // 0x80049F50: jal         0x800B7060
    // 0x80049F54: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_7;
    // 0x80049F54: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_7:
    // 0x80049F58: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    // 0x80049F5C: jal         0x80061134
    // 0x80049F60: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    PFGFX_ClearCellGrids(rdram, ctx);
        goto after_8;
    // 0x80049F60: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_8:
    // 0x80049F64: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80049F68: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x80049F6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049F70: bne         $t4, $at, L_80049FA0
    if (ctx->r12 != ctx->r1) {
        // 0x80049F74: nop
    
            goto L_80049FA0;
    }
    // 0x80049F74: nop

    // 0x80049F78: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80049F7C: addiu       $a1, $a1, -0x41D8
    ctx->r5 = ADD32(ctx->r5, -0X41D8);
    // 0x80049F80: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80049F84: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80049F88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80049F8C: addiu       $a0, $a0, -0x4460
    ctx->r4 = ADD32(ctx->r4, -0X4460);
    // 0x80049F90: addiu       $a1, $a1, 0x2000
    ctx->r5 = ADD32(ctx->r5, 0X2000);
    // 0x80049F94: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80049F98: jal         0x8005EC10
    // 0x80049F9C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    osCreateScheduler(rdram, ctx);
        goto after_9;
    // 0x80049F9C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_9:
L_80049FA0:
    // 0x80049FA0: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80049FA4: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80049FA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80049FAC: bne         $t7, $at, L_80049FDC
    if (ctx->r15 != ctx->r1) {
        // 0x80049FB0: nop
    
            goto L_80049FDC;
    }
    // 0x80049FB0: nop

    // 0x80049FB4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80049FB8: addiu       $a1, $a1, -0x41D8
    ctx->r5 = ADD32(ctx->r5, -0X41D8);
    // 0x80049FBC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80049FC0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80049FC4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80049FC8: addiu       $a0, $a0, -0x4460
    ctx->r4 = ADD32(ctx->r4, -0X4460);
    // 0x80049FCC: addiu       $a1, $a1, 0x2000
    ctx->r5 = ADD32(ctx->r5, 0X2000);
    // 0x80049FD0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80049FD4: jal         0x8005EC10
    // 0x80049FD8: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    osCreateScheduler(rdram, ctx);
        goto after_10;
    // 0x80049FD8: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_10:
L_80049FDC:
    // 0x80049FDC: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80049FE0: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x80049FE4: nop

    // 0x80049FE8: bne         $t8, $zero, L_8004A018
    if (ctx->r24 != 0) {
        // 0x80049FEC: nop
    
            goto L_8004A018;
    }
    // 0x80049FEC: nop

    // 0x80049FF0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80049FF4: addiu       $a1, $a1, -0x41D8
    ctx->r5 = ADD32(ctx->r5, -0X41D8);
    // 0x80049FF8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80049FFC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004A000: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8004A004: addiu       $a0, $a0, -0x4460
    ctx->r4 = ADD32(ctx->r4, -0X4460);
    // 0x8004A008: addiu       $a1, $a1, 0x2000
    ctx->r5 = ADD32(ctx->r5, 0X2000);
    // 0x8004A00C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8004A010: jal         0x8005EC10
    // 0x8004A014: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    osCreateScheduler(rdram, ctx);
        goto after_11;
    // 0x8004A014: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_11:
L_8004A018:
    // 0x8004A018: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8004A01C: addiu       $a1, $a1, -0x5300
    ctx->r5 = ADD32(ctx->r5, -0X5300);
    // 0x8004A020: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004A024: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004A028: jal         0x80084630
    // 0x8004A02C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Debug_FaultInit(rdram, ctx);
        goto after_12;
    // 0x8004A02C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x8004A030: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x8004A034: addiu       $t2, $t2, 0x56D0
    ctx->r10 = ADD32(ctx->r10, 0X56D0);
    // 0x8004A038: addiu       $t0, $t2, 0x2000
    ctx->r8 = ADD32(ctx->r10, 0X2000);
    // 0x8004A03C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8004A040: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8004A044: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004A048: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8004A04C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8004A050: addiu       $a2, $a2, -0x5F60
    ctx->r6 = ADD32(ctx->r6, -0X5F60);
    // 0x8004A054: addiu       $a0, $a0, 0x31C0
    ctx->r4 = ADD32(ctx->r4, 0X31C0);
    // 0x8004A058: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8004A05C: jal         0x800B6010
    // 0x8004A060: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    osCreateThread_recomp(rdram, ctx);
        goto after_13;
    // 0x8004A060: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_13:
    // 0x8004A064: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8004A068: jal         0x800B6160
    // 0x8004A06C: addiu       $a0, $a0, 0x31C0
    ctx->r4 = ADD32(ctx->r4, 0X31C0);
    osStartThread_recomp(rdram, ctx);
        goto after_14;
    // 0x8004A06C: addiu       $a0, $a0, 0x31C0
    ctx->r4 = ADD32(ctx->r4, 0X31C0);
    after_14:
    // 0x8004A070: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004A074: jal         0x800B7370
    // 0x8004A078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_15;
    // 0x8004A078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
L_8004A07C:
    // 0x8004A07C: b           L_8004A07C
    pause_self(rdram);
    // 0x8004A080: nop

    // 0x8004A084: nop

    // 0x8004A088: nop

    // 0x8004A08C: nop

    // 0x8004A090: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8004A094: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8004A098: jr          $ra
    // 0x8004A09C: nop

    return;
    // 0x8004A09C: nop

;}

RECOMP_FUNC void main_infinite_loop_at_end_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A0A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004A0A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004A0A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004A0AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004A0B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8004A0B4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8004A0B8: jal         0x800AC06C
    // 0x8004A0BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    Main_StartRomDmaThread(rdram, ctx);
        goto after_0;
    // 0x8004A0BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x8004A0C0: jal         0x8004A3A4
    // 0x8004A0C4: nop

    main_another_but_diff_400x300(rdram, ctx);
        goto after_1;
    // 0x8004A0C4: nop

    after_1:
    // 0x8004A0C8: jal         0x800AC0F8
    // 0x8004A0CC: nop

    Main_InitCartPiHandle(rdram, ctx);
        goto after_2;
    // 0x8004A0CC: nop

    after_2:
    // 0x8004A0D0: jal         0x8007C0EC
    // 0x8004A0D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    SaveData_Load(rdram, ctx);
        goto after_3;
    // 0x8004A0D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8004A0D8: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8004A0DC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8004A0E0: addiu       $t7, $t7, -0x5230
    ctx->r15 = ADD32(ctx->r15, -0X5230);
    // 0x8004A0E4: addiu       $t6, $t6, 0x5590
    ctx->r14 = ADD32(ctx->r14, 0X5590);
    // 0x8004A0E8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8004A0EC: beq         $t8, $zero, L_8004A140
    if (ctx->r24 == 0) {
        // 0x8004A0F0: sw          $zero, 0x28($sp)
        MEM_W(0X28, ctx->r29) = 0;
            goto L_8004A140;
    }
    // 0x8004A0F0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_8004A0F4:
    // 0x8004A0F4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8004A0F8: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8004A0FC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8004A100: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8004A104: lbu         $t1, -0x5230($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X5230);
    // 0x8004A108: lw          $t9, -0x1C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1C4);
    // 0x8004A10C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8004A110: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8004A114: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8004A118: addiu       $t6, $t6, -0x5230
    ctx->r14 = ADD32(ctx->r14, -0X5230);
    // 0x8004A11C: addiu       $t5, $t5, 0x5590
    ctx->r13 = ADD32(ctx->r13, 0X5590);
    // 0x8004A120: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A124: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8004A128: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8004A12C: sw          $t2, -0x1C4($at)
    MEM_W(-0X1C4, ctx->r1) = ctx->r10;
    // 0x8004A130: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8004A134: sltu        $at, $t4, $t7
    ctx->r1 = ctx->r12 < ctx->r15 ? 1 : 0;
    // 0x8004A138: bne         $at, $zero, L_8004A0F4
    if (ctx->r1 != 0) {
        // 0x8004A13C: sw          $t4, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r12;
            goto L_8004A0F4;
    }
    // 0x8004A13C: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
L_8004A140:
    // 0x8004A140: jal         0x80060E30
    // 0x8004A144: nop

    PFGFX_ApplyViMode(rdram, ctx);
        goto after_4;
    // 0x8004A144: nop

    after_4:
L_8004A148:
    // 0x8004A148: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A14C: addiu       $a0, $a0, -0x44F8
    ctx->r4 = ADD32(ctx->r4, -0X44F8);
    // 0x8004A150: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8004A154: jal         0x800B3C20
    // 0x8004A158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8004A158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8004A15C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8004A160: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004A164: lh          $s0, 0x0($t8)
    ctx->r16 = MEM_H(ctx->r24, 0X0);
    // 0x8004A168: nop

    // 0x8004A16C: beq         $s0, $at, L_8004A18C
    if (ctx->r16 == ctx->r1) {
        // 0x8004A170: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004A18C;
    }
    // 0x8004A170: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004A174: beq         $s0, $at, L_8004A1E0
    if (ctx->r16 == ctx->r1) {
        // 0x8004A178: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8004A1E0;
    }
    // 0x8004A178: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004A17C: beq         $s0, $at, L_8004A20C
    if (ctx->r16 == ctx->r1) {
        // 0x8004A180: nop
    
            goto L_8004A20C;
    }
    // 0x8004A180: nop

    // 0x8004A184: b           L_8004A148
    // 0x8004A188: nop

        goto L_8004A148;
    // 0x8004A188: nop

L_8004A18C:
    // 0x8004A18C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8004A190: lw          $t0, -0x1C8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1C8);
    // 0x8004A194: nop

    // 0x8004A198: sltiu       $at, $t0, 0x2
    ctx->r1 = ctx->r8 < 0X2 ? 1 : 0;
    // 0x8004A19C: beq         $at, $zero, L_8004A148
    if (ctx->r1 == 0) {
        // 0x8004A1A0: nop
    
            goto L_8004A148;
    }
    // 0x8004A1A0: nop

    // 0x8004A1A4: jal         0x80048B64
    // 0x8004A1A8: nop

    has_rounds_and_floors_large_liner(rdram, ctx);
        goto after_6;
    // 0x8004A1A8: nop

    after_6:
    // 0x8004A1AC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8004A1B0: lw          $t9, -0x1C8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1C8);
    // 0x8004A1B4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8004A1B8: lhu         $t2, 0x20B0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X20B0);
    // 0x8004A1BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A1C0: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8004A1C4: sw          $t1, -0x1C8($at)
    MEM_W(-0X1C8, ctx->r1) = ctx->r9;
    // 0x8004A1C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004A1CC: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x8004A1D0: sh          $t3, 0x20B0($at)
    MEM_H(0X20B0, ctx->r1) = ctx->r11;
    // 0x8004A1D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A1D8: b           L_8004A148
    // 0x8004A1DC: sw          $zero, -0x1C0($at)
    MEM_W(-0X1C0, ctx->r1) = 0;
        goto L_8004A148;
    // 0x8004A1DC: sw          $zero, -0x1C0($at)
    MEM_W(-0X1C0, ctx->r1) = 0;
L_8004A1E0:
    // 0x8004A1E0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8004A1E4: lw          $t5, -0x114($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X114);
    // 0x8004A1E8: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8004A1EC: lw          $t4, -0x1C8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1C8);
    // 0x8004A1F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A1F4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8004A1F8: sw          $t6, -0x114($at)
    MEM_W(-0X114, ctx->r1) = ctx->r14;
    // 0x8004A1FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A200: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x8004A204: b           L_8004A148
    // 0x8004A208: sw          $t7, -0x1C8($at)
    MEM_W(-0X1C8, ctx->r1) = ctx->r15;
        goto L_8004A148;
    // 0x8004A208: sw          $t7, -0x1C8($at)
    MEM_W(-0X1C8, ctx->r1) = ctx->r15;
L_8004A20C:
    // 0x8004A20C: jal         0x80061198
    // 0x8004A210: nop

    func_80061198(rdram, ctx);
        goto after_7;
    // 0x8004A210: nop

    after_7:
    // 0x8004A214: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004A218: jal         0x80088C14
    // 0x8004A21C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    Audio2_GFXDone_SendStopMessage(rdram, ctx);
        goto after_8;
    // 0x8004A21C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    after_8:
    // 0x8004A220: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004A224: jal         0x8008780C
    // 0x8004A228: addiu       $a0, $a0, 0x2010
    ctx->r4 = ADD32(ctx->r4, 0X2010);
    Audio2_GFXDone_SendSyncMessage(rdram, ctx);
        goto after_9;
    // 0x8004A228: addiu       $a0, $a0, 0x2010
    ctx->r4 = ADD32(ctx->r4, 0X2010);
    after_9:
    // 0x8004A22C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004A230: jal         0x8008780C
    // 0x8004A234: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    Audio2_GFXDone_SendSyncMessage(rdram, ctx);
        goto after_10;
    // 0x8004A234: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    after_10:
    // 0x8004A238: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8004A23C: lw          $t8, -0x1C8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1C8);
    // 0x8004A240: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8004A244: ori         $at, $at, 0x423F
    ctx->r1 = ctx->r1 | 0X423F;
    // 0x8004A248: addu        $t0, $t8, $at
    ctx->r8 = ADD32(ctx->r24, ctx->r1);
    // 0x8004A24C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A250: b           L_8004A148
    // 0x8004A254: sw          $t0, -0x1C8($at)
    MEM_W(-0X1C8, ctx->r1) = ctx->r8;
        goto L_8004A148;
    // 0x8004A254: sw          $t0, -0x1C8($at)
    MEM_W(-0X1C8, ctx->r1) = ctx->r8;
    // 0x8004A258: nop

    // 0x8004A25C: nop

    // 0x8004A260: nop

    // 0x8004A264: nop

    // 0x8004A268: nop

    // 0x8004A26C: nop

    // 0x8004A270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A274: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004A278: jr          $ra
    // 0x8004A27C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8004A27C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void main_maybe_audio_related(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A280: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004A284: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004A288: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A28C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004A290: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8004A294: addiu       $a0, $a0, -0x44F8
    ctx->r4 = ADD32(ctx->r4, -0X44F8);
    // 0x8004A298: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8004A29C: jal         0x800B3C20
    // 0x8004A2A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8004A2A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8004A2A4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8004A2A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004A2AC: lh          $s0, 0x0($t6)
    ctx->r16 = MEM_H(ctx->r14, 0X0);
    // 0x8004A2B0: nop

    // 0x8004A2B4: beq         $s0, $at, L_8004A2CC
    if (ctx->r16 == ctx->r1) {
        // 0x8004A2B8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8004A2CC;
    }
    // 0x8004A2B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004A2BC: beq         $s0, $at, L_8004A2F8
    if (ctx->r16 == ctx->r1) {
        // 0x8004A2C0: nop
    
            goto L_8004A2F8;
    }
    // 0x8004A2C0: nop

    // 0x8004A2C4: b           L_8004A33C
    // 0x8004A2C8: nop

        goto L_8004A33C;
    // 0x8004A2C8: nop

L_8004A2CC:
    // 0x8004A2CC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8004A2D0: lw          $t7, -0x114($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X114);
    // 0x8004A2D4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8004A2D8: lw          $t9, -0x1C8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1C8);
    // 0x8004A2DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A2E0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8004A2E4: sw          $t8, -0x114($at)
    MEM_W(-0X114, ctx->r1) = ctx->r24;
    // 0x8004A2E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A2EC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8004A2F0: b           L_8004A33C
    // 0x8004A2F4: sw          $t0, -0x1C8($at)
    MEM_W(-0X1C8, ctx->r1) = ctx->r8;
        goto L_8004A33C;
    // 0x8004A2F4: sw          $t0, -0x1C8($at)
    MEM_W(-0X1C8, ctx->r1) = ctx->r8;
L_8004A2F8:
    // 0x8004A2F8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8004A2FC: lw          $t1, -0x1C8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1C8);
    // 0x8004A300: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8004A304: ori         $at, $at, 0x423F
    ctx->r1 = ctx->r1 | 0X423F;
    // 0x8004A308: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x8004A30C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A310: jal         0x80061198
    // 0x8004A314: sw          $t2, -0x1C8($at)
    MEM_W(-0X1C8, ctx->r1) = ctx->r10;
    func_80061198(rdram, ctx);
        goto after_1;
    // 0x8004A314: sw          $t2, -0x1C8($at)
    MEM_W(-0X1C8, ctx->r1) = ctx->r10;
    after_1:
    // 0x8004A318: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004A31C: jal         0x80088C14
    // 0x8004A320: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    Audio2_GFXDone_SendStopMessage(rdram, ctx);
        goto after_2;
    // 0x8004A320: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    after_2:
    // 0x8004A324: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004A328: jal         0x8008780C
    // 0x8004A32C: addiu       $a0, $a0, 0x2010
    ctx->r4 = ADD32(ctx->r4, 0X2010);
    Audio2_GFXDone_SendSyncMessage(rdram, ctx);
        goto after_3;
    // 0x8004A32C: addiu       $a0, $a0, 0x2010
    ctx->r4 = ADD32(ctx->r4, 0X2010);
    after_3:
    // 0x8004A330: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004A334: jal         0x8008780C
    // 0x8004A338: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    Audio2_GFXDone_SendSyncMessage(rdram, ctx);
        goto after_4;
    // 0x8004A338: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    after_4:
L_8004A33C:
    // 0x8004A33C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A340: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004A344: jr          $ra
    // 0x8004A348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004A348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void main_8004A34C_threeliner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A34C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8004A350: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8004A354: lw          $t7, -0x114($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X114);
    // 0x8004A358: lw          $t6, -0x110($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X110);
    // 0x8004A35C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004A360: sltu        $at, $t7, $t6
    ctx->r1 = ctx->r15 < ctx->r14 ? 1 : 0;
    // 0x8004A364: beq         $at, $zero, L_8004A394
    if (ctx->r1 == 0) {
        // 0x8004A368: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8004A394;
    }
    // 0x8004A368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_8004A36C:
    // 0x8004A36C: jal         0x8004A280
    // 0x8004A370: nop

    main_maybe_audio_related(rdram, ctx);
        goto after_0;
    // 0x8004A370: nop

    after_0:
    // 0x8004A374: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8004A378: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8004A37C: lw          $t9, -0x114($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X114);
    // 0x8004A380: lw          $t8, -0x110($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X110);
    // 0x8004A384: nop

    // 0x8004A388: sltu        $at, $t9, $t8
    ctx->r1 = ctx->r25 < ctx->r24 ? 1 : 0;
    // 0x8004A38C: bne         $at, $zero, L_8004A36C
    if (ctx->r1 != 0) {
        // 0x8004A390: nop
    
            goto L_8004A36C;
    }
    // 0x8004A390: nop

L_8004A394:
    // 0x8004A394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004A398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004A39C: jr          $ra
    // 0x8004A3A0: nop

    return;
    // 0x8004A3A0: nop

;}

RECOMP_FUNC void main_another_but_diff_400x300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A3A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004A3A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004A3AC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A3B0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8004A3B4: addiu       $a1, $a1, -0x4500
    ctx->r5 = ADD32(ctx->r5, -0X4500);
    // 0x8004A3B8: addiu       $a0, $a0, -0x4518
    ctx->r4 = ADD32(ctx->r4, -0X4518);
    // 0x8004A3BC: jal         0x800B3080
    // 0x8004A3C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8004A3C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8004A3C4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A3C8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8004A3CC: addiu       $a1, $a1, -0x44E0
    ctx->r5 = ADD32(ctx->r5, -0X44E0);
    // 0x8004A3D0: addiu       $a0, $a0, -0x44F8
    ctx->r4 = ADD32(ctx->r4, -0X44F8);
    // 0x8004A3D4: jal         0x800B3080
    // 0x8004A3D8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8004A3D8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_1:
    // 0x8004A3DC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A3E0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8004A3E4: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8004A3E8: addiu       $a2, $a2, -0x44F8
    ctx->r6 = ADD32(ctx->r6, -0X44F8);
    // 0x8004A3EC: addiu       $a1, $a1, -0x21D8
    ctx->r5 = ADD32(ctx->r5, -0X21D8);
    // 0x8004A3F0: jal         0x8005ED58
    // 0x8004A3F4: addiu       $a0, $a0, -0x4460
    ctx->r4 = ADD32(ctx->r4, -0X4460);
    osScAddClient(rdram, ctx);
        goto after_2;
    // 0x8004A3F4: addiu       $a0, $a0, -0x4460
    ctx->r4 = ADD32(ctx->r4, -0X4460);
    after_2:
    // 0x8004A3F8: addiu       $t6, $zero, 0x190
    ctx->r14 = ADD32(0, 0X190);
    // 0x8004A3FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A400: sw          $t6, -0x2B0($at)
    MEM_W(-0X2B0, ctx->r1) = ctx->r14;
    // 0x8004A404: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A408: addiu       $t7, $zero, 0x12C
    ctx->r15 = ADD32(0, 0X12C);
    // 0x8004A40C: sw          $t7, -0x2AC($at)
    MEM_W(-0X2AC, ctx->r1) = ctx->r15;
    // 0x8004A410: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A414: sw          $zero, -0x2A0($at)
    MEM_W(-0X2A0, ctx->r1) = 0;
    // 0x8004A418: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A41C: sw          $zero, -0x29C($at)
    MEM_W(-0X29C, ctx->r1) = 0;
    // 0x8004A420: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A424: addiu       $t8, $zero, 0x190
    ctx->r24 = ADD32(0, 0X190);
    // 0x8004A428: sw          $t8, -0x298($at)
    MEM_W(-0X298, ctx->r1) = ctx->r24;
    // 0x8004A42C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A430: addiu       $t9, $zero, 0x12C
    ctx->r25 = ADD32(0, 0X12C);
    // 0x8004A434: sw          $t9, -0x294($at)
    MEM_W(-0X294, ctx->r1) = ctx->r25;
    // 0x8004A438: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    // 0x8004A43C: jal         0x8006110C
    // 0x8004A440: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    PFGFX_RequestViModeChange(rdram, ctx);
        goto after_3;
    // 0x8004A440: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_3:
    // 0x8004A444: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8004A448: lui         $t1, 0x8035
    ctx->r9 = S32(0X8035 << 16);
    // 0x8004A44C: addiu       $t1, $t1, -0x5300
    ctx->r9 = ADD32(ctx->r9, -0X5300);
    // 0x8004A450: addiu       $t0, $t0, -0x830
    ctx->r8 = ADD32(ctx->r8, -0X830);
    // 0x8004A454: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8004A458: jal         0x8007DFC0
    // 0x8004A45C: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    n64HeapInit(rdram, ctx);
        goto after_4;
    // 0x8004A45C: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    after_4:
    // 0x8004A460: lui         $a0, 0xB
    ctx->r4 = S32(0XB << 16);
    // 0x8004A464: lui         $a1, 0xB
    ctx->r5 = S32(0XB << 16);
    // 0x8004A468: addiu       $a1, $a1, -0x2520
    ctx->r5 = ADD32(ctx->r5, -0X2520);
    // 0x8004A46C: jal         0x800A9E44
    // 0x8004A470: addiu       $a0, $a0, -0x7E70
    ctx->r4 = ADD32(ctx->r4, -0X7E70);
    func_800A9E44(rdram, ctx);
        goto after_5;
    // 0x8004A470: addiu       $a0, $a0, -0x7E70
    ctx->r4 = ADD32(ctx->r4, -0X7E70);
    after_5:
    // 0x8004A474: jal         0x80053538
    // 0x8004A478: nop

    PV_ClearAllPlayers(rdram, ctx);
        goto after_6;
    // 0x8004A478: nop

    after_6:
    // 0x8004A47C: jal         0x80053500
    // 0x8004A480: nop

    gamefinish_InitResultScreen(rdram, ctx);
        goto after_7;
    // 0x8004A480: nop

    after_7:
    // 0x8004A484: jal         0x800484B4
    // 0x8004A488: nop

    inits_bunch_of_stuff_q_allocs_heap(rdram, ctx);
        goto after_8;
    // 0x8004A488: nop

    after_8:
    // 0x8004A48C: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
L_8004A490:
    // 0x8004A490: lh          $t2, 0x1E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1E);
    // 0x8004A494: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004A498: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8004A49C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8004A4A0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8004A4A4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8004A4A8: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8004A4AC: addiu       $t4, $t4, -0x10D0
    ctx->r12 = ADD32(ctx->r12, -0X10D0);
    // 0x8004A4B0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004A4B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004A4B8: sw          $t5, -0xDF0($at)
    MEM_W(-0XDF0, ctx->r1) = ctx->r13;
    // 0x8004A4BC: jal         0x800A34A8
    // 0x8004A4C0: addiu       $a0, $t5, 0x4
    ctx->r4 = ADD32(ctx->r13, 0X4);
    FUN_069580_800A34A8_tenliner_allocs_heap(rdram, ctx);
        goto after_9;
    // 0x8004A4C0: addiu       $a0, $t5, 0x4
    ctx->r4 = ADD32(ctx->r13, 0X4);
    after_9:
    // 0x8004A4C4: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    // 0x8004A4C8: jal         0x800535A0
    // 0x8004A4CC: nop

    PV_set_controller_no(rdram, ctx);
        goto after_10;
    // 0x8004A4CC: nop

    after_10:
    // 0x8004A4D0: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x8004A4D4: nop

    // 0x8004A4D8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004A4DC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8004A4E0: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004A4E4: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x8004A4E8: bne         $at, $zero, L_8004A490
    if (ctx->r1 != 0) {
        // 0x8004A4EC: sh          $t7, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r15;
            goto L_8004A490;
    }
    // 0x8004A4EC: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
    // 0x8004A4F0: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
L_8004A4F4:
    // 0x8004A4F4: lh          $t1, 0x1E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X1E);
    // 0x8004A4F8: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x8004A4FC: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x8004A500: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x8004A504: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004A508: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x8004A50C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004A510: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004A514: addiu       $t3, $t3, -0x10D0
    ctx->r11 = ADD32(ctx->r11, -0X10D0);
    // 0x8004A518: addiu       $t2, $t0, 0x4
    ctx->r10 = ADD32(ctx->r8, 0X4);
    // 0x8004A51C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8004A520: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x8004A524: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004A528: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8004A52C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8004A530: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004A534: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004A538: sw          $t4, -0x21D0($at)
    MEM_W(-0X21D0, ctx->r1) = ctx->r12;
    // 0x8004A53C: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x8004A540: bne         $at, $zero, L_8004A4F4
    if (ctx->r1 != 0) {
        // 0x8004A544: sh          $t7, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r15;
            goto L_8004A4F4;
    }
    // 0x8004A544: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
    // 0x8004A548: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A54C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8004A550: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8004A554: addiu       $a2, $a2, -0x21D0
    ctx->r6 = ADD32(ctx->r6, -0X21D0);
    // 0x8004A558: addiu       $a1, $a1, -0x4460
    ctx->r5 = ADD32(ctx->r5, -0X4460);
    // 0x8004A55C: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    // 0x8004A560: jal         0x8003ADD0
    // 0x8004A564: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    createSuperThread(rdram, ctx);
        goto after_11;
    // 0x8004A564: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_11:
    // 0x8004A568: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A56C: jal         0x8003B29C
    // 0x8004A570: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    FUN_001500_motorInit(rdram, ctx);
        goto after_12;
    // 0x8004A570: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_12:
    // 0x8004A574: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A578: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    // 0x8004A57C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8004A580: jal         0x8003DB60
    // 0x8004A584: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    Controller_CreateThread(rdram, ctx);
        goto after_13;
    // 0x8004A584: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_13:
    // 0x8004A588: jal         0x80084700
    // 0x8004A58C: nop

    Audio_InitAudio(rdram, ctx);
        goto after_14;
    // 0x8004A58C: nop

    after_14:
    // 0x8004A590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004A594: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004A598: jr          $ra
    // 0x8004A59C: nop

    return;
    // 0x8004A59C: nop

;}

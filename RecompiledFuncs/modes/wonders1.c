#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void wonders1_HandleButtonInput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043810: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80043814: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80043818: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004381C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80043820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043824: addiu       $t6, $t6, -0x10D0
    ctx->r14 = ADD32(ctx->r14, -0X10D0);
    // 0x80043828: lw          $s0, 0x24($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X24);
    // 0x8004382C: nop

    // 0x80043830: andi        $t7, $s0, 0x8000
    ctx->r15 = ctx->r16 & 0X8000;
    // 0x80043834: beq         $t7, $zero, L_80043880
    if (ctx->r15 == 0) {
        // 0x80043838: nop
    
            goto L_80043880;
    }
    // 0x80043838: nop

    // 0x8004383C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80043840: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80043844: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80043848: nop

    // 0x8004384C: bne         $t9, $at, L_80043870
    if (ctx->r25 != ctx->r1) {
        // 0x80043850: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80043870;
    }
    // 0x80043850: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80043854: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80043858: jal         0x8007E9F8
    // 0x8004385C: nop

    Gfx_BeginScreenFade0(rdram, ctx);
        goto after_0;
    // 0x8004385C: nop

    after_0:
    // 0x80043860: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80043864: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x80043868: b           L_80043898
    // 0x8004386C: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
        goto L_80043898;
    // 0x8004386C: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
L_80043870:
    // 0x80043870: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80043874: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x80043878: b           L_80043898
    // 0x8004387C: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
        goto L_80043898;
    // 0x8004387C: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
L_80043880:
    // 0x80043880: andi        $t4, $s0, 0x4000
    ctx->r12 = ctx->r16 & 0X4000;
    // 0x80043884: beq         $t4, $zero, L_80043898
    if (ctx->r12 == 0) {
        // 0x80043888: nop
    
            goto L_80043898;
    }
    // 0x80043888: nop

    // 0x8004388C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80043890: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80043894: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
L_80043898:
    // 0x80043898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004389C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800438A0: jr          $ra
    // 0x800438A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800438A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders1_AnimateWonderTiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800438A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800438AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800438B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800438B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800438B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800438BC: lb          $t7, 0x1($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X1);
    // 0x800438C0: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800438C4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800438C8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800438CC: lw          $t9, -0xB28($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB28);
    // 0x800438D0: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800438D4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x800438D8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800438DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800438E0: lb          $t1, 0x1($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X1);
    // 0x800438E4: nop

    // 0x800438E8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800438EC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800438F0: lw          $t3, -0x8F4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X8F4);
    // 0x800438F4: nop

    // 0x800438F8: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x800438FC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80043900: sb          $zero, 0x1F70($at)
    MEM_B(0X1F70, ctx->r1) = 0;
    // 0x80043904: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80043908: nop

    // 0x8004390C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80043910: nop

    // 0x80043914: beq         $t7, $zero, L_80043C6C
    if (ctx->r15 == 0) {
        // 0x80043918: nop
    
            goto L_80043C6C;
    }
    // 0x80043918: nop

L_8004391C:
    // 0x8004391C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80043920: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80043924: lbu         $t6, 0x1F70($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1F70);
    // 0x80043928: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8004392C: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80043930: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80043934: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80043938: jal         0x80076EC0
    // 0x8004393C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    CubeTiles_ObjCreate(rdram, ctx);
        goto after_0;
    // 0x8004393C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80043940: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80043944: nop

    // 0x80043948: lb          $a0, 0x1($t3)
    ctx->r4 = MEM_B(ctx->r11, 0X1);
    // 0x8004394C: jal         0x80046218
    // 0x80043950: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_1;
    // 0x80043950: nop

    after_1:
    // 0x80043954: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80043958: bne         $at, $zero, L_80043A50
    if (ctx->r1 != 0) {
        // 0x8004395C: nop
    
            goto L_80043A50;
    }
    // 0x8004395C: nop

    // 0x80043960: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80043964: lbu         $t0, 0x1F70($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X1F70);
    // 0x80043968: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004396C: beq         $t0, $at, L_8004399C
    if (ctx->r8 == ctx->r1) {
        // 0x80043970: nop
    
            goto L_8004399C;
    }
    // 0x80043970: nop

    // 0x80043974: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80043978: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8004397C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80043980: nop

    // 0x80043984: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80043988: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8004398C: nop

    // 0x80043990: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80043994: jal         0x800A4620
    // 0x80043998: nop

    wonders1_ObjSetFlag40(rdram, ctx);
        goto after_2;
    // 0x80043998: nop

    after_2:
L_8004399C:
    // 0x8004399C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800439A0: lbu         $t9, 0x1F70($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1F70);
    // 0x800439A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800439A8: bne         $t9, $at, L_800439E0
    if (ctx->r25 != ctx->r1) {
        // 0x800439AC: nop
    
            goto L_800439E0;
    }
    // 0x800439AC: nop

    // 0x800439B0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800439B4: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x800439B8: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800439BC: nop

    // 0x800439C0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800439C4: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x800439C8: nop

    // 0x800439CC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800439D0: jal         0x800A4654
    // 0x800439D4: nop

    wonders1_ObjClearFlag80(rdram, ctx);
        goto after_3;
    // 0x800439D4: nop

    after_3:
    // 0x800439D8: b           L_80043A0C
    // 0x800439DC: nop

        goto L_80043A0C;
    // 0x800439DC: nop

L_800439E0:
    // 0x800439E0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800439E4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800439E8: lbu         $t8, 0x1F70($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1F70);
    // 0x800439EC: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x800439F0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800439F4: addu        $t1, $t7, $t6
    ctx->r9 = ADD32(ctx->r15, ctx->r14);
    // 0x800439F8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800439FC: nop

    // 0x80043A00: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80043A04: jal         0x800A4644
    // 0x80043A08: nop

    wonders1_ObjSetFlag80(rdram, ctx);
        goto after_4;
    // 0x80043A08: nop

    after_4:
L_80043A0C:
    // 0x80043A0C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80043A10: lbu         $t2, 0x1F70($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X1F70);
    // 0x80043A14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80043A18: bne         $t2, $at, L_80043B3C
    if (ctx->r10 != ctx->r1) {
        // 0x80043A1C: nop
    
            goto L_80043B3C;
    }
    // 0x80043A1C: nop

    // 0x80043A20: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80043A24: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x80043A28: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80043A2C: nop

    // 0x80043A30: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80043A34: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80043A38: nop

    // 0x80043A3C: lbu         $t7, 0x20($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X20);
    // 0x80043A40: nop

    // 0x80043A44: ori         $t6, $t7, 0x4
    ctx->r14 = ctx->r15 | 0X4;
    // 0x80043A48: b           L_80043B3C
    // 0x80043A4C: sb          $t6, 0x20($t8)
    MEM_B(0X20, ctx->r24) = ctx->r14;
        goto L_80043B3C;
    // 0x80043A4C: sb          $t6, 0x20($t8)
    MEM_B(0X20, ctx->r24) = ctx->r14;
L_80043A50:
    // 0x80043A50: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80043A54: lbu         $t1, 0x1F70($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1F70);
    // 0x80043A58: nop

    // 0x80043A5C: beq         $t1, $zero, L_80043A8C
    if (ctx->r9 == 0) {
        // 0x80043A60: nop
    
            goto L_80043A8C;
    }
    // 0x80043A60: nop

    // 0x80043A64: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80043A68: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80043A6C: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x80043A70: nop

    // 0x80043A74: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x80043A78: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x80043A7C: nop

    // 0x80043A80: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80043A84: jal         0x800A4620
    // 0x80043A88: nop

    wonders1_ObjSetFlag40(rdram, ctx);
        goto after_5;
    // 0x80043A88: nop

    after_5:
L_80043A8C:
    // 0x80043A8C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80043A90: lbu         $t5, 0x1F70($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X1F70);
    // 0x80043A94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80043A98: bne         $t5, $at, L_80043ACC
    if (ctx->r13 != ctx->r1) {
        // 0x80043A9C: nop
    
            goto L_80043ACC;
    }
    // 0x80043A9C: nop

    // 0x80043AA0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80043AA4: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80043AA8: lw          $t6, 0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X8);
    // 0x80043AAC: nop

    // 0x80043AB0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80043AB4: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80043AB8: nop

    // 0x80043ABC: lbu         $t3, 0x20($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X20);
    // 0x80043AC0: nop

    // 0x80043AC4: ori         $t2, $t3, 0x4
    ctx->r10 = ctx->r11 | 0X4;
    // 0x80043AC8: sb          $t2, 0x20($t1)
    MEM_B(0X20, ctx->r9) = ctx->r10;
L_80043ACC:
    // 0x80043ACC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80043AD0: lbu         $t4, 0x1F70($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X1F70);
    // 0x80043AD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043AD8: bne         $t4, $at, L_80043B10
    if (ctx->r12 != ctx->r1) {
        // 0x80043ADC: nop
    
            goto L_80043B10;
    }
    // 0x80043ADC: nop

    // 0x80043AE0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80043AE4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80043AE8: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x80043AEC: nop

    // 0x80043AF0: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x80043AF4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80043AF8: nop

    // 0x80043AFC: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80043B00: jal         0x800A4654
    // 0x80043B04: nop

    wonders1_ObjClearFlag80(rdram, ctx);
        goto after_6;
    // 0x80043B04: nop

    after_6:
    // 0x80043B08: b           L_80043B3C
    // 0x80043B0C: nop

        goto L_80043B3C;
    // 0x80043B0C: nop

L_80043B10:
    // 0x80043B10: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80043B14: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80043B18: lbu         $t2, 0x1F70($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X1F70);
    // 0x80043B1C: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x80043B20: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x80043B24: addu        $t0, $t3, $t1
    ctx->r8 = ADD32(ctx->r11, ctx->r9);
    // 0x80043B28: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80043B2C: nop

    // 0x80043B30: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80043B34: jal         0x800A4644
    // 0x80043B38: nop

    wonders1_ObjSetFlag80(rdram, ctx);
        goto after_7;
    // 0x80043B38: nop

    after_7:
L_80043B3C:
    // 0x80043B3C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80043B40: nop

    // 0x80043B44: lb          $a0, 0x1($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X1);
    // 0x80043B48: jal         0x80046218
    // 0x80043B4C: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_8;
    // 0x80043B4C: nop

    after_8:
    // 0x80043B50: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80043B54: bne         $at, $zero, L_80043B74
    if (ctx->r1 != 0) {
        // 0x80043B58: nop
    
            goto L_80043B74;
    }
    // 0x80043B58: nop

    // 0x80043B5C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80043B60: lbu         $t5, 0x1F70($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X1F70);
    // 0x80043B64: nop

    // 0x80043B68: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80043B6C: beq         $at, $zero, L_80043BAC
    if (ctx->r1 == 0) {
        // 0x80043B70: nop
    
            goto L_80043BAC;
    }
    // 0x80043B70: nop

L_80043B74:
    // 0x80043B74: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80043B78: nop

    // 0x80043B7C: lb          $a0, 0x1($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X1);
    // 0x80043B80: jal         0x80046218
    // 0x80043B84: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_9;
    // 0x80043B84: nop

    after_9:
    // 0x80043B88: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80043B8C: beq         $at, $zero, L_80043C0C
    if (ctx->r1 == 0) {
        // 0x80043B90: nop
    
            goto L_80043C0C;
    }
    // 0x80043B90: nop

    // 0x80043B94: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80043B98: lbu         $t8, 0x1F70($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1F70);
    // 0x80043B9C: nop

    // 0x80043BA0: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x80043BA4: bne         $at, $zero, L_80043C0C
    if (ctx->r1 != 0) {
        // 0x80043BA8: nop
    
            goto L_80043C0C;
    }
    // 0x80043BA8: nop

L_80043BAC:
    // 0x80043BAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80043BB0: jal         0x800A35EC
    // 0x80043BB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    Scene_RandRange(rdram, ctx);
        goto after_10;
    // 0x80043BB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80043BB8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80043BBC: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80043BC0: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80043BC4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80043BC8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80043BCC: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80043BD0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80043BD4: lbu         $t3, 0x1F70($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X1F70);
    // 0x80043BD8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80043BDC: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x80043BE0: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x80043BE4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80043BE8: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x80043BEC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80043BF0: addu        $t0, $t2, $t1
    ctx->r8 = ADD32(ctx->r10, ctx->r9);
    // 0x80043BF4: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80043BF8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80043BFC: lwc1        $f4, 0x14($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X14);
    // 0x80043C00: nop

    // 0x80043C04: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80043C08: swc1        $f10, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f10.u32l;
L_80043C0C:
    // 0x80043C0C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80043C10: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80043C14: lbu         $t8, 0x1F70($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1F70);
    // 0x80043C18: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80043C1C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80043C20: addu        $t3, $t6, $t9
    ctx->r11 = ADD32(ctx->r14, ctx->r25);
    // 0x80043C24: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80043C28: jal         0x800773B8
    // 0x80043C2C: nop

    CubeTiles_ObjClearAnimating(rdram, ctx);
        goto after_11;
    // 0x80043C2C: nop

    after_11:
    // 0x80043C30: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80043C34: lbu         $t2, 0x1F70($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X1F70);
    // 0x80043C38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043C3C: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x80043C40: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80043C44: sb          $t1, 0x1F70($at)
    MEM_B(0X1F70, ctx->r1) = ctx->r9;
    // 0x80043C48: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80043C4C: lbu         $t4, 0x1F70($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X1F70);
    // 0x80043C50: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x80043C54: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80043C58: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x80043C5C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80043C60: nop

    // 0x80043C64: bne         $t6, $zero, L_8004391C
    if (ctx->r14 != 0) {
        // 0x80043C68: nop
    
            goto L_8004391C;
    }
    // 0x80043C68: nop

L_80043C6C:
    // 0x80043C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80043C70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043C74: jr          $ra
    // 0x80043C78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80043C78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders1_BuildWonderDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043C7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80043C80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80043C84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80043C88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80043C8C: jal         0x8004A34C
    // 0x80043C90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    Main_DrainMessageQueue(rdram, ctx);
        goto after_0;
    // 0x80043C90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80043C94: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80043C98: nop

    // 0x80043C9C: lb          $a0, 0x1($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X1);
    // 0x80043CA0: jal         0x80046218
    // 0x80043CA4: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_1;
    // 0x80043CA4: nop

    after_1:
    // 0x80043CA8: sll         $s1, $v0, 24
    ctx->r17 = S32(ctx->r2 << 24);
    // 0x80043CAC: sra         $t7, $s1, 24
    ctx->r15 = S32(SIGNED(ctx->r17) >> 24);
    // 0x80043CB0: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80043CB4: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80043CB8: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80043CBC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80043CC0: lw          $t9, -0xA64($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XA64);
    // 0x80043CC4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80043CC8: nop

    // 0x80043CCC: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80043CD0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80043CD4: nop

    // 0x80043CD8: lb          $a0, 0x1($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X1);
    // 0x80043CDC: jal         0x80046218
    // 0x80043CE0: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_2;
    // 0x80043CE0: nop

    after_2:
    // 0x80043CE4: sll         $s1, $v0, 24
    ctx->r17 = S32(ctx->r2 << 24);
    // 0x80043CE8: sra         $t2, $s1, 24
    ctx->r10 = S32(SIGNED(ctx->r17) >> 24);
    // 0x80043CEC: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x80043CF0: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80043CF4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80043CF8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80043CFC: lw          $t4, -0x830($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X830);
    // 0x80043D00: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80043D04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80043D08: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x80043D0C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80043D10: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80043D14: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80043D18: nop

    // 0x80043D1C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80043D20: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80043D24: nop

    // 0x80043D28: beq         $t0, $zero, L_80043E98
    if (ctx->r8 == 0) {
        // 0x80043D2C: nop
    
            goto L_80043E98;
    }
    // 0x80043D2C: nop

L_80043D30:
    // 0x80043D30: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80043D34: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80043D38: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80043D3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80043D40: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80043D44: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80043D48: jal         0x80076EC0
    // 0x80043D4C: nop

    CubeTiles_ObjCreate(rdram, ctx);
        goto after_3;
    // 0x80043D4C: nop

    after_3:
    // 0x80043D50: beq         $s0, $zero, L_80043D80
    if (ctx->r16 == 0) {
        // 0x80043D54: nop
    
            goto L_80043D80;
    }
    // 0x80043D54: nop

    // 0x80043D58: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80043D5C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80043D60: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80043D64: nop

    // 0x80043D68: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80043D6C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80043D70: nop

    // 0x80043D74: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80043D78: jal         0x800A4620
    // 0x80043D7C: nop

    wonders1_ObjSetFlag40(rdram, ctx);
        goto after_4;
    // 0x80043D7C: nop

    after_4:
L_80043D80:
    // 0x80043D80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043D84: bne         $s0, $at, L_80043DBC
    if (ctx->r16 != ctx->r1) {
        // 0x80043D88: nop
    
            goto L_80043DBC;
    }
    // 0x80043D88: nop

    // 0x80043D8C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80043D90: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80043D94: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80043D98: nop

    // 0x80043D9C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80043DA0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80043DA4: nop

    // 0x80043DA8: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80043DAC: jal         0x800A4654
    // 0x80043DB0: nop

    wonders1_ObjClearFlag80(rdram, ctx);
        goto after_5;
    // 0x80043DB0: nop

    after_5:
    // 0x80043DB4: b           L_80043DE4
    // 0x80043DB8: nop

        goto L_80043DE4;
    // 0x80043DB8: nop

L_80043DBC:
    // 0x80043DBC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80043DC0: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80043DC4: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80043DC8: nop

    // 0x80043DCC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80043DD0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80043DD4: nop

    // 0x80043DD8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80043DDC: jal         0x800A4644
    // 0x80043DE0: nop

    wonders1_ObjSetFlag80(rdram, ctx);
        goto after_6;
    // 0x80043DE0: nop

    after_6:
L_80043DE4:
    // 0x80043DE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80043DE8: bne         $s0, $at, L_80043E4C
    if (ctx->r16 != ctx->r1) {
        // 0x80043DEC: nop
    
            goto L_80043E4C;
    }
    // 0x80043DEC: nop

    // 0x80043DF0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80043DF4: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80043DF8: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80043DFC: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80043E00: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80043E04: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80043E08: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x80043E0C: lbu         $t5, 0x20($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X20);
    // 0x80043E10: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80043E14: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x80043E18: sb          $t6, 0x20($t9)
    MEM_B(0X20, ctx->r25) = ctx->r14;
    // 0x80043E1C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80043E20: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80043E24: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80043E28: nop

    // 0x80043E2C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80043E30: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80043E34: nop

    // 0x80043E38: lw          $t1, 0x0($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X0);
    // 0x80043E3C: nop

    // 0x80043E40: lw          $t7, 0x8($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X8);
    // 0x80043E44: nop

    // 0x80043E48: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
L_80043E4C:
    // 0x80043E4C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80043E50: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80043E54: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x80043E58: nop

    // 0x80043E5C: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80043E60: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80043E64: jal         0x800773B8
    // 0x80043E68: nop

    CubeTiles_ObjClearAnimating(rdram, ctx);
        goto after_7;
    // 0x80043E68: nop

    after_7:
    // 0x80043E6C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80043E70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80043E74: andi        $t2, $s0, 0xFF
    ctx->r10 = ctx->r16 & 0XFF;
    // 0x80043E78: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80043E7C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80043E80: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80043E84: addu        $t1, $t4, $t5
    ctx->r9 = ADD32(ctx->r12, ctx->r13);
    // 0x80043E88: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80043E8C: nop

    // 0x80043E90: bne         $t7, $zero, L_80043D30
    if (ctx->r15 != 0) {
        // 0x80043E94: nop
    
            goto L_80043D30;
    }
    // 0x80043E94: nop

L_80043E98:
    // 0x80043E98: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80043E9C: nop

    // 0x80043EA0: lb          $a0, 0x1($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X1);
    // 0x80043EA4: jal         0x80046218
    // 0x80043EA8: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_8;
    // 0x80043EA8: nop

    after_8:
    // 0x80043EAC: sll         $s1, $v0, 24
    ctx->r17 = S32(ctx->r2 << 24);
    // 0x80043EB0: sra         $t6, $s1, 24
    ctx->r14 = S32(SIGNED(ctx->r17) >> 24);
    // 0x80043EB4: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80043EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80043EBC: jal         0x800476F0
    // 0x80043EC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wonders4_SetupWonderTextBox(rdram, ctx);
        goto after_9;
    // 0x80043EC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80043EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80043EC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80043ECC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80043ED0: jr          $ra
    // 0x80043ED4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80043ED4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders1_SetupWonderColumn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043ED8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80043EDC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80043EE0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80043EE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80043EE8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80043EEC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80043EF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043EF4: lb          $a0, 0x1($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X1);
    // 0x80043EF8: jal         0x80046218
    // 0x80043EFC: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_0;
    // 0x80043EFC: nop

    after_0:
    // 0x80043F00: sll         $s1, $v0, 24
    ctx->r17 = S32(ctx->r2 << 24);
    // 0x80043F04: sra         $t7, $s1, 24
    ctx->r15 = S32(SIGNED(ctx->r17) >> 24);
    // 0x80043F08: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80043F0C: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80043F10: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80043F14: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80043F18: lw          $t9, -0xA48($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XA48);
    // 0x80043F1C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80043F20: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80043F24: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80043F28: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80043F2C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80043F30: lw          $t2, -0x814($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X814);
    // 0x80043F34: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80043F38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80043F3C: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x80043F40: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80043F44: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80043F48: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80043F4C: nop

    // 0x80043F50: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80043F54: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80043F58: nop

    // 0x80043F5C: beq         $t8, $zero, L_800440D8
    if (ctx->r24 == 0) {
        // 0x80043F60: nop
    
            goto L_800440D8;
    }
    // 0x80043F60: nop

L_80043F64:
    // 0x80043F64: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80043F68: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x80043F6C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80043F70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80043F74: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80043F78: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80043F7C: jal         0x80076EC0
    // 0x80043F80: nop

    CubeTiles_ObjCreate(rdram, ctx);
        goto after_1;
    // 0x80043F80: nop

    after_1:
    // 0x80043F84: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80043F88: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80043F8C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80043F90: nop

    // 0x80043F94: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80043F98: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80043F9C: nop

    // 0x80043FA0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80043FA4: jal         0x800A4654
    // 0x80043FA8: nop

    wonders1_ObjClearFlag80(rdram, ctx);
        goto after_2;
    // 0x80043FA8: nop

    after_2:
    // 0x80043FAC: bne         $s1, $zero, L_80043FF0
    if (ctx->r17 != 0) {
        // 0x80043FB0: nop
    
            goto L_80043FF0;
    }
    // 0x80043FB0: nop

    // 0x80043FB4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80043FB8: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80043FBC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80043FC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80043FC4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80043FC8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80043FCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80043FD0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80043FD4: addiu       $a0, $zero, 0x574
    ctx->r4 = ADD32(0, 0X574);
    // 0x80043FD8: lw          $t4, 0x1D0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1D0);
    // 0x80043FDC: jal         0x800A6A74
    // 0x80043FE0: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
    CubeTiles_ObjInstantiateScoped(rdram, ctx);
        goto after_3;
    // 0x80043FE0: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
    after_3:
    // 0x80043FE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043FE8: b           L_80044040
    // 0x80043FEC: sw          $v0, 0x1F68($at)
    MEM_W(0X1F68, ctx->r1) = ctx->r2;
        goto L_80044040;
    // 0x80043FEC: sw          $v0, 0x1F68($at)
    MEM_W(0X1F68, ctx->r1) = ctx->r2;
L_80043FF0:
    // 0x80043FF0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80043FF4: bne         $s1, $at, L_80044038
    if (ctx->r17 != ctx->r1) {
        // 0x80043FF8: nop
    
            goto L_80044038;
    }
    // 0x80043FF8: nop

    // 0x80043FFC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80044000: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80044004: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80044008: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004400C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80044010: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80044014: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80044018: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004401C: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x80044020: lw          $t1, 0x1D0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1D0);
    // 0x80044024: jal         0x800A6A74
    // 0x80044028: swc1        $f6, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f6.u32l;
    CubeTiles_ObjInstantiateScoped(rdram, ctx);
        goto after_4;
    // 0x80044028: swc1        $f6, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f6.u32l;
    after_4:
    // 0x8004402C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044030: b           L_80044040
    // 0x80044034: sw          $v0, 0x1F68($at)
    MEM_W(0X1F68, ctx->r1) = ctx->r2;
        goto L_80044040;
    // 0x80044034: sw          $v0, 0x1F68($at)
    MEM_W(0X1F68, ctx->r1) = ctx->r2;
L_80044038:
    // 0x80044038: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004403C: sw          $zero, 0x1F68($at)
    MEM_W(0X1F68, ctx->r1) = 0;
L_80044040:
    // 0x80044040: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80044044: lw          $t2, 0x1F68($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1F68);
    // 0x80044048: nop

    // 0x8004404C: beq         $t2, $zero, L_800440AC
    if (ctx->r10 == 0) {
        // 0x80044050: nop
    
            goto L_800440AC;
    }
    // 0x80044050: nop

    // 0x80044054: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80044058: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8004405C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80044060: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80044064: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80044068: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8004406C: nop

    // 0x80044070: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80044074: jal         0x800A678C
    // 0x80044078: nop

    CubeTiles_ObjLinkChild(rdram, ctx);
        goto after_5;
    // 0x80044078: nop

    after_5:
    // 0x8004407C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80044080: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80044084: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80044088: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004408C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80044090: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80044094: nop

    // 0x80044098: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8004409C: nop

    // 0x800440A0: lw          $t5, 0x1D0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1D0);
    // 0x800440A4: nop

    // 0x800440A8: swc1        $f8, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f8.u32l;
L_800440AC:
    // 0x800440AC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800440B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800440B4: andi        $t6, $s0, 0xFF
    ctx->r14 = ctx->r16 & 0XFF;
    // 0x800440B8: lw          $t2, 0x8($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X8);
    // 0x800440BC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800440C0: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x800440C4: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x800440C8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800440CC: nop

    // 0x800440D0: bne         $t0, $zero, L_80043F64
    if (ctx->r8 != 0) {
        // 0x800440D4: nop
    
            goto L_80043F64;
    }
    // 0x800440D4: nop

L_800440D8:
    // 0x800440D8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800440DC: nop

    // 0x800440E0: lb          $a0, 0x1($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X1);
    // 0x800440E4: jal         0x80046218
    // 0x800440E8: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_6;
    // 0x800440E8: nop

    after_6:
    // 0x800440EC: sll         $s2, $v0, 24
    ctx->r18 = S32(ctx->r2 << 24);
    // 0x800440F0: sra         $t3, $s2, 24
    ctx->r11 = S32(SIGNED(ctx->r18) >> 24);
    // 0x800440F4: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x800440F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800440FC: jal         0x800476F0
    // 0x80044100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    wonders4_SetupWonderTextBox(rdram, ctx);
        goto after_7;
    // 0x80044100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80044104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80044108: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004410C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80044110: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80044114: jr          $ra
    // 0x80044118: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80044118: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void wonders1_CreateColumnTiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004411C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80044120: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80044124: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80044128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004412C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80044130: lb          $t7, 0x1($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X1);
    // 0x80044134: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80044138: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004413C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80044140: lw          $t9, -0xAF0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XAF0);
    // 0x80044144: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80044148: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8004414C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80044150: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80044154: lb          $t1, 0x1($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X1);
    // 0x80044158: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8004415C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80044160: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80044164: lw          $t3, -0x8BC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X8BC);
    // 0x80044168: nop

    // 0x8004416C: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80044170: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80044174: nop

    // 0x80044178: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8004417C: nop

    // 0x80044180: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80044184: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80044188: nop

    // 0x8004418C: beq         $t9, $zero, L_80044208
    if (ctx->r25 == 0) {
        // 0x80044190: nop
    
            goto L_80044208;
    }
    // 0x80044190: nop

L_80044194:
    // 0x80044194: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80044198: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8004419C: lw          $t1, 0x8($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X8);
    // 0x800441A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800441A4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800441A8: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800441AC: jal         0x80076EC0
    // 0x800441B0: nop

    CubeTiles_ObjCreate(rdram, ctx);
        goto after_0;
    // 0x800441B0: nop

    after_0:
    // 0x800441B4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800441B8: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x800441BC: lw          $t4, 0x8($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X8);
    // 0x800441C0: nop

    // 0x800441C4: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800441C8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800441CC: nop

    // 0x800441D0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800441D4: jal         0x800A4654
    // 0x800441D8: nop

    wonders1_ObjClearFlag80(rdram, ctx);
        goto after_1;
    // 0x800441D8: nop

    after_1:
    // 0x800441DC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800441E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800441E4: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x800441E8: lw          $t1, 0x8($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X8);
    // 0x800441EC: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x800441F0: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800441F4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800441F8: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800441FC: nop

    // 0x80044200: bne         $t0, $zero, L_80044194
    if (ctx->r8 != 0) {
        // 0x80044204: nop
    
            goto L_80044194;
    }
    // 0x80044204: nop

L_80044208:
    // 0x80044208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004420C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80044210: jr          $ra
    // 0x80044214: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80044214: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders1_FreeColumnTiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004421C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80044220: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80044224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80044228: beq         $t6, $zero, L_800442E8
    if (ctx->r14 == 0) {
        // 0x8004422C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800442E8;
    }
    // 0x8004422C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80044230: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80044234: nop

    // 0x80044238: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8004423C: nop

    // 0x80044240: beq         $t8, $zero, L_800442E8
    if (ctx->r24 == 0) {
        // 0x80044244: nop
    
            goto L_800442E8;
    }
    // 0x80044244: nop

    // 0x80044248: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8004424C: lw          $t9, 0x1F68($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1F68);
    // 0x80044250: nop

    // 0x80044254: beq         $t9, $zero, L_8004426C
    if (ctx->r25 == 0) {
        // 0x80044258: nop
    
            goto L_8004426C;
    }
    // 0x80044258: nop

    // 0x8004425C: jal         0x800A6AA8
    // 0x80044260: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    CubeTiles_ObjReleaseNode(rdram, ctx);
        goto after_0;
    // 0x80044260: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x80044264: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044268: sw          $zero, 0x1F68($at)
    MEM_W(0X1F68, ctx->r1) = 0;
L_8004426C:
    // 0x8004426C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80044270: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80044274: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80044278: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8004427C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80044280: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80044284: nop

    // 0x80044288: beq         $t4, $zero, L_800442DC
    if (ctx->r12 == 0) {
        // 0x8004428C: nop
    
            goto L_800442DC;
    }
    // 0x8004428C: nop

L_80044290:
    // 0x80044290: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80044294: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80044298: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8004429C: nop

    // 0x800442A0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800442A4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800442A8: jal         0x80077028
    // 0x800442AC: nop

    CubeTiles_ObjFree(rdram, ctx);
        goto after_1;
    // 0x800442AC: nop

    after_1:
    // 0x800442B0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800442B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800442B8: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x800442BC: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800442C0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x800442C4: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800442C8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800442CC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800442D0: nop

    // 0x800442D4: bne         $t4, $zero, L_80044290
    if (ctx->r12 != 0) {
        // 0x800442D8: nop
    
            goto L_80044290;
    }
    // 0x800442D8: nop

L_800442DC:
    // 0x800442DC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800442E0: jal         0x8004A34C
    // 0x800442E4: sw          $zero, 0x8($t5)
    MEM_W(0X8, ctx->r13) = 0;
    Main_DrainMessageQueue(rdram, ctx);
        goto after_2;
    // 0x800442E4: sw          $zero, 0x8($t5)
    MEM_W(0X8, ctx->r13) = 0;
    after_2:
L_800442E8:
    // 0x800442E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800442EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800442F0: jr          $ra
    // 0x800442F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800442F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders1_CheckWonderProgress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800442F8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800442FC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80044300: lb          $t7, -0x7D0($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X7D0);
    // 0x80044304: lb          $t6, -0x7CC($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X7CC);
    // 0x80044308: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004430C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80044310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80044314: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80044318: beq         $t6, $t7, L_8004434C
    if (ctx->r14 == ctx->r15) {
        // 0x8004431C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8004434C;
    }
    // 0x8004431C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80044320: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80044324: nop

    // 0x80044328: sb          $t7, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r15;
    // 0x8004432C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80044330: jal         0x800438A8
    // 0x80044334: nop

    wonders1_AnimateWonderTiles(rdram, ctx);
        goto after_0;
    // 0x80044334: nop

    after_0:
    // 0x80044338: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8004433C: lb          $t9, -0x7D0($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X7D0);
    // 0x80044340: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044344: b           L_800443EC
    // 0x80044348: sb          $t9, -0x7CC($at)
    MEM_B(-0X7CC, ctx->r1) = ctx->r25;
        goto L_800443EC;
    // 0x80044348: sb          $t9, -0x7CC($at)
    MEM_B(-0X7CC, ctx->r1) = ctx->r25;
L_8004434C:
    // 0x8004434C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80044350: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80044354: lb          $t1, -0x7C8($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X7C8);
    // 0x80044358: lb          $t0, -0x7C4($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X7C4);
    // 0x8004435C: nop

    // 0x80044360: beq         $t0, $t1, L_800443B0
    if (ctx->r8 == ctx->r9) {
        // 0x80044364: nop
    
            goto L_800443B0;
    }
    // 0x80044364: nop

    // 0x80044368: jal         0x8004624C
    // 0x8004436C: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
    wonders2_WonderIndexToLastColumn(rdram, ctx);
        goto after_1;
    // 0x8004436C: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
    after_1:
    // 0x80044370: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80044374: nop

    // 0x80044378: sb          $v0, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r2;
    // 0x8004437C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80044380: jal         0x80043ED8
    // 0x80044384: nop

    wonders1_SetupWonderColumn(rdram, ctx);
        goto after_2;
    // 0x80044384: nop

    after_2:
    // 0x80044388: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8004438C: lb          $t3, -0x7C8($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X7C8);
    // 0x80044390: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044394: sb          $t3, -0x7C4($at)
    MEM_B(-0X7C4, ctx->r1) = ctx->r11;
    // 0x80044398: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8004439C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800443A0: jal         0x8007ECC8
    // 0x800443A4: nop

    Gfx_BeginScreenFade1(rdram, ctx);
        goto after_3;
    // 0x800443A4: nop

    after_3:
    // 0x800443A8: b           L_800443EC
    // 0x800443AC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800443EC;
    // 0x800443AC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800443B0:
    // 0x800443B0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800443B4: nop

    // 0x800443B8: lb          $a0, 0x1($t4)
    ctx->r4 = MEM_B(ctx->r12, 0X1);
    // 0x800443BC: jal         0x8004619C
    // 0x800443C0: nop

    wonders2_IsLastColumnOfWonder(rdram, ctx);
        goto after_4;
    // 0x800443C0: nop

    after_4:
    // 0x800443C4: beq         $v0, $zero, L_800443E0
    if (ctx->r2 == 0) {
        // 0x800443C8: nop
    
            goto L_800443E0;
    }
    // 0x800443C8: nop

    // 0x800443CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800443D0: jal         0x80043ED8
    // 0x800443D4: nop

    wonders1_SetupWonderColumn(rdram, ctx);
        goto after_5;
    // 0x800443D4: nop

    after_5:
    // 0x800443D8: b           L_800443EC
    // 0x800443DC: nop

        goto L_800443EC;
    // 0x800443DC: nop

L_800443E0:
    // 0x800443E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800443E4: jal         0x800438A8
    // 0x800443E8: nop

    wonders1_AnimateWonderTiles(rdram, ctx);
        goto after_6;
    // 0x800443E8: nop

    after_6:
L_800443EC:
    // 0x800443EC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800443F0: beq         $s0, $zero, L_80044408
    if (ctx->r16 == 0) {
        // 0x800443F4: sh          $zero, 0x2($t5)
        MEM_H(0X2, ctx->r13) = 0;
            goto L_80044408;
    }
    // 0x800443F4: sh          $zero, 0x2($t5)
    MEM_H(0X2, ctx->r13) = 0;
    // 0x800443F8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800443FC: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80044400: b           L_80044414
    // 0x80044404: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
        goto L_80044414;
    // 0x80044404: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
L_80044408:
    // 0x80044408: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8004440C: nop

    // 0x80044410: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
L_80044414:
    // 0x80044414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80044418: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004441C: jr          $ra
    // 0x80044420: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80044420: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders1_ShowWonderDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044428: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004442C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044430: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80044434: jal         0x80043C7C
    // 0x80044438: nop

    wonders1_BuildWonderDisplay(rdram, ctx);
        goto after_0;
    // 0x80044438: nop

    after_0:
    // 0x8004443C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80044440: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80044444: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
    // 0x80044448: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8004444C: nop

    // 0x80044450: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80044454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004445C: jr          $ra
    // 0x80044460: nop

    return;
    // 0x80044460: nop

;}

RECOMP_FUNC void wonders1_ShowColumnTiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044468: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004446C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044470: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80044474: jal         0x8004411C
    // 0x80044478: nop

    wonders1_CreateColumnTiles(rdram, ctx);
        goto after_0;
    // 0x80044478: nop

    after_0:
    // 0x8004447C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80044480: nop

    // 0x80044484: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
    // 0x80044488: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8004448C: nop

    // 0x80044490: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x80044494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004449C: jr          $ra
    // 0x800444A0: nop

    return;
    // 0x800444A0: nop

;}

RECOMP_FUNC void wonders1_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800444A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800444A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800444AC: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x800444B0: lw          $s0, 0x5E10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5E10);
    // 0x800444B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800444B8: beq         $s0, $zero, L_800445CC
    if (ctx->r16 == 0) {
        // 0x800444BC: nop
    
            goto L_800445CC;
    }
    // 0x800444BC: nop

    // 0x800444C0: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x800444C4: nop

    // 0x800444C8: sltiu       $at, $t6, 0x10
    ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
    // 0x800444CC: beq         $at, $zero, L_800445CC
    if (ctx->r1 == 0) {
        // 0x800444D0: nop
    
            goto L_800445CC;
    }
    // 0x800444D0: nop

    // 0x800444D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800444D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800444DC: addu        $at, $at, $t6
    gpr jr_addend_800444E8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800444E0: lw          $t6, -0x4AA8($at)
    ctx->r14 = ADD32(ctx->r1, -0X4AA8);
    // 0x800444E4: nop

    // 0x800444E8: jr          $t6
    // 0x800444EC: nop

    switch (jr_addend_800444E8 >> 2) {
        case 0: goto L_800444F0; break;
        case 1: goto L_80044500; break;
        case 2: goto L_800445CC; break;
        case 3: goto L_800445CC; break;
        case 4: goto L_800445CC; break;
        case 5: goto L_8004454C; break;
        case 6: goto L_800445CC; break;
        case 7: goto L_800445CC; break;
        case 8: goto L_800445CC; break;
        case 9: goto L_80044534; break;
        case 10: goto L_800444F0; break;
        case 11: goto L_800445CC; break;
        case 12: goto L_800445CC; break;
        case 13: goto L_80044564; break;
        case 14: goto L_800445C4; break;
        case 15: goto L_800445C4; break;
        default: switch_error(__func__, 0x800444E8, 0x800DB558);
    }
    // 0x800444EC: nop

L_800444F0:
    // 0x800444F0: jal         0x80043810
    // 0x800444F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders1_HandleButtonInput(rdram, ctx);
        goto after_0;
    // 0x800444F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800444F8: b           L_800445CC
    // 0x800444FC: nop

        goto L_800445CC;
    // 0x800444FC: nop

L_80044500:
    // 0x80044500: lb          $t7, 0x1($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1);
    // 0x80044504: nop

    // 0x80044508: slti        $at, $t7, 0x31
    ctx->r1 = SIGNED(ctx->r15) < 0X31 ? 1 : 0;
    // 0x8004450C: beq         $at, $zero, L_80044524
    if (ctx->r1 == 0) {
        // 0x80044510: nop
    
            goto L_80044524;
    }
    // 0x80044510: nop

    // 0x80044514: jal         0x800442F8
    // 0x80044518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders1_CheckWonderProgress(rdram, ctx);
        goto after_1;
    // 0x80044518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8004451C: b           L_800445CC
    // 0x80044520: nop

        goto L_800445CC;
    // 0x80044520: nop

L_80044524:
    // 0x80044524: jal         0x80044464
    // 0x80044528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders1_ShowColumnTiles(rdram, ctx);
        goto after_2;
    // 0x80044528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8004452C: b           L_800445CC
    // 0x80044530: nop

        goto L_800445CC;
    // 0x80044530: nop

L_80044534:
    // 0x80044534: jal         0x80044218
    // 0x80044538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders1_FreeColumnTiles(rdram, ctx);
        goto after_3;
    // 0x80044538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8004453C: jal         0x800442F8
    // 0x80044540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders1_CheckWonderProgress(rdram, ctx);
        goto after_4;
    // 0x80044540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80044544: b           L_800445CC
    // 0x80044548: nop

        goto L_800445CC;
    // 0x80044548: nop

L_8004454C:
    // 0x8004454C: jal         0x80044218
    // 0x80044550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders1_FreeColumnTiles(rdram, ctx);
        goto after_5;
    // 0x80044550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80044554: jal         0x80044424
    // 0x80044558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders1_ShowWonderDisplay(rdram, ctx);
        goto after_6;
    // 0x80044558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8004455C: b           L_800445CC
    // 0x80044560: nop

        goto L_800445CC;
    // 0x80044560: nop

L_80044564:
    // 0x80044564: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80044568: lbu         $t8, -0x7C0($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X7C0);
    // 0x8004456C: nop

    // 0x80044570: bne         $t8, $zero, L_800445AC
    if (ctx->r24 != 0) {
        // 0x80044574: nop
    
            goto L_800445AC;
    }
    // 0x80044574: nop

    // 0x80044578: lb          $t9, 0x1($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1);
    // 0x8004457C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80044580: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80044584: sb          $t0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r8;
    // 0x80044588: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004458C: sb          $t1, -0x7C0($at)
    MEM_B(-0X7C0, ctx->r1) = ctx->r9;
    // 0x80044590: jal         0x80044218
    // 0x80044594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders1_FreeColumnTiles(rdram, ctx);
        goto after_7;
    // 0x80044594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80044598: jal         0x80044464
    // 0x8004459C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders1_ShowColumnTiles(rdram, ctx);
        goto after_8;
    // 0x8004459C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800445A0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800445A4: b           L_800445CC
    // 0x800445A8: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
        goto L_800445CC;
    // 0x800445A8: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
L_800445AC:
    // 0x800445AC: jal         0x80044218
    // 0x800445B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders1_FreeColumnTiles(rdram, ctx);
        goto after_9;
    // 0x800445B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800445B4: jal         0x80044464
    // 0x800445B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders1_ShowColumnTiles(rdram, ctx);
        goto after_10;
    // 0x800445B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800445BC: b           L_800445CC
    // 0x800445C0: nop

        goto L_800445CC;
    // 0x800445C0: nop

L_800445C4:
    // 0x800445C4: jal         0x80045C9C
    // 0x800445C8: nop

    wonders1_Exit(rdram, ctx);
        goto after_11;
    // 0x800445C8: nop

    after_11:
L_800445CC:
    // 0x800445CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800445D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800445D4: jr          $ra
    // 0x800445D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800445D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders1_ConfigTileObject(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800445DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800445E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800445E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800445E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800445EC: jal         0x800A4590
    // 0x800445F0: nop

    CubeTiles_ObjSetFlags_0x04(rdram, ctx);
        goto after_0;
    // 0x800445F0: nop

    after_0:
    // 0x800445F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800445F8: jal         0x800A45D8
    // 0x800445FC: nop

    CubeTiles_ObjSetFlags_0x10(rdram, ctx);
        goto after_1;
    // 0x800445FC: nop

    after_1:
    // 0x80044600: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80044604: jal         0x800A4620
    // 0x80044608: nop

    wonders1_ObjSetFlag40(rdram, ctx);
        goto after_2;
    // 0x80044608: nop

    after_2:
    // 0x8004460C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80044610: jal         0x800A4644
    // 0x80044614: nop

    wonders1_ObjSetFlag80(rdram, ctx);
        goto after_3;
    // 0x80044614: nop

    after_3:
    // 0x80044618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004461C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044620: jr          $ra
    // 0x80044624: nop

    return;
    // 0x80044624: nop

;}

RECOMP_FUNC void wonders1_CreateColumnTileObject(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004462C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80044630: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80044634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044638: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8004463C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80044640: addiu       $at, $zero, 0x3EF
    ctx->r1 = ADD32(0, 0X3EF);
    // 0x80044644: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80044648: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8004464C: nop

    // 0x80044650: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80044654: nop

    // 0x80044658: bne         $t9, $at, L_80044674
    if (ctx->r25 != ctx->r1) {
        // 0x8004465C: nop
    
            goto L_80044674;
    }
    // 0x8004465C: nop

    // 0x80044660: jal         0x800A6990
    // 0x80044664: addiu       $a0, $zero, 0x421
    ctx->r4 = ADD32(0, 0X421);
    CubeTiles_ObjInstanceAlloc(rdram, ctx);
        goto after_0;
    // 0x80044664: addiu       $a0, $zero, 0x421
    ctx->r4 = ADD32(0, 0X421);
    after_0:
    // 0x80044668: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8004466C: b           L_80044688
    // 0x80044670: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
        goto L_80044688;
    // 0x80044670: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
L_80044674:
    // 0x80044674: jal         0x800A6990
    // 0x80044678: addiu       $a0, $zero, 0x42A
    ctx->r4 = ADD32(0, 0X42A);
    CubeTiles_ObjInstanceAlloc(rdram, ctx);
        goto after_1;
    // 0x80044678: addiu       $a0, $zero, 0x42A
    ctx->r4 = ADD32(0, 0X42A);
    after_1:
    // 0x8004467C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80044680: nop

    // 0x80044684: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_80044688:
    // 0x80044688: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8004468C: nop

    // 0x80044690: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80044694: jal         0x800445DC
    // 0x80044698: nop

    wonders1_ConfigTileObject(rdram, ctx);
        goto after_2;
    // 0x80044698: nop

    after_2:
    // 0x8004469C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800446A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800446A4: jr          $ra
    // 0x800446A8: nop

    return;
    // 0x800446A8: nop

;}

RECOMP_FUNC void wonders1_UpdatePulseAlpha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800446AC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800446B0: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x800446B4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x800446B8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800446BC: lbu         $t7, 0x1F6F($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1F6F);
    // 0x800446C0: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x800446C4: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x800446C8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800446CC: beq         $t7, $zero, L_8004470C
    if (ctx->r15 == 0) {
        // 0x800446D0: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_8004470C;
    }
    // 0x800446D0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800446D4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800446D8: lbu         $t8, 0x1F6E($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1F6E);
    // 0x800446DC: nop

    // 0x800446E0: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800446E4: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x800446E8: beq         $at, $zero, L_80044700
    if (ctx->r1 == 0) {
        // 0x800446EC: nop
    
            goto L_80044700;
    }
    // 0x800446EC: nop

    // 0x800446F0: addu        $t0, $t8, $a1
    ctx->r8 = ADD32(ctx->r24, ctx->r5);
    // 0x800446F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800446F8: b           L_80044740
    // 0x800446FC: sb          $t0, 0x1F6E($at)
    MEM_B(0X1F6E, ctx->r1) = ctx->r8;
        goto L_80044740;
    // 0x800446FC: sb          $t0, 0x1F6E($at)
    MEM_B(0X1F6E, ctx->r1) = ctx->r8;
L_80044700:
    // 0x80044700: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044704: b           L_80044740
    // 0x80044708: sb          $zero, 0x1F6F($at)
    MEM_B(0X1F6F, ctx->r1) = 0;
        goto L_80044740;
    // 0x80044708: sb          $zero, 0x1F6F($at)
    MEM_B(0X1F6F, ctx->r1) = 0;
L_8004470C:
    // 0x8004470C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80044710: lbu         $t1, 0x1F6E($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1F6E);
    // 0x80044714: nop

    // 0x80044718: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8004471C: bne         $at, $zero, L_80044734
    if (ctx->r1 != 0) {
        // 0x80044720: nop
    
            goto L_80044734;
    }
    // 0x80044720: nop

    // 0x80044724: subu        $t2, $t1, $a1
    ctx->r10 = SUB32(ctx->r9, ctx->r5);
    // 0x80044728: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004472C: b           L_80044740
    // 0x80044730: sb          $t2, 0x1F6E($at)
    MEM_B(0X1F6E, ctx->r1) = ctx->r10;
        goto L_80044740;
    // 0x80044730: sb          $t2, 0x1F6E($at)
    MEM_B(0X1F6E, ctx->r1) = ctx->r10;
L_80044734:
    // 0x80044734: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80044738: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004473C: sb          $t3, 0x1F6F($at)
    MEM_B(0X1F6F, ctx->r1) = ctx->r11;
L_80044740:
    // 0x80044740: jr          $ra
    // 0x80044744: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80044744: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void wonders1_hall_or_exit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044748: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8004474C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80044750: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80044754: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80044758: lw          $s0, 0x5E10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5E10);
    // 0x8004475C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x80044760: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80044764: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80044768: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8004476C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80044770: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80044774: jal         0x800A3AF0
    // 0x80044778: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    frametime_delta(rdram, ctx);
        goto after_0;
    // 0x80044778: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    after_0:
    // 0x8004477C: lhu         $t6, 0x2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2);
    // 0x80044780: andi        $s4, $v0, 0xFF
    ctx->r20 = ctx->r2 & 0XFF;
    // 0x80044784: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80044788: addu        $t7, $t6, $s4
    ctx->r15 = ADD32(ctx->r14, ctx->r20);
    // 0x8004478C: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80044790: beq         $at, $zero, L_800447AC
    if (ctx->r1 == 0) {
        // 0x80044794: nop
    
            goto L_800447AC;
    }
    // 0x80044794: nop

    // 0x80044798: lhu         $t8, 0x2($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X2);
    // 0x8004479C: nop

    // 0x800447A0: addu        $t9, $t8, $s4
    ctx->r25 = ADD32(ctx->r24, ctx->r20);
    // 0x800447A4: b           L_800447B4
    // 0x800447A8: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
        goto L_800447B4;
    // 0x800447A8: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
L_800447AC:
    // 0x800447AC: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x800447B0: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
L_800447B4:
    // 0x800447B4: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x800447B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800447BC: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x800447C0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800447C4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800447C8: nop

    // 0x800447CC: beq         $t4, $zero, L_80044C0C
    if (ctx->r12 == 0) {
        // 0x800447D0: nop
    
            goto L_80044C0C;
    }
    // 0x800447D0: nop

L_800447D4:
    // 0x800447D4: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x800447D8: nop

    // 0x800447DC: beq         $t5, $zero, L_800447F4
    if (ctx->r13 == 0) {
        // 0x800447E0: nop
    
            goto L_800447F4;
    }
    // 0x800447E0: nop

    // 0x800447E4: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x800447E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800447EC: bne         $t6, $at, L_80044BCC
    if (ctx->r14 != ctx->r1) {
        // 0x800447F0: nop
    
            goto L_80044BCC;
    }
    // 0x800447F0: nop

L_800447F4:
    // 0x800447F4: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800447F8: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x800447FC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80044800: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80044804: nop

    // 0x80044808: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8004480C: nop

    // 0x80044810: beq         $t1, $zero, L_80044BCC
    if (ctx->r9 == 0) {
        // 0x80044814: nop
    
            goto L_80044BCC;
    }
    // 0x80044814: nop

    // 0x80044818: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x8004481C: jal         0x80046218
    // 0x80044820: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_1;
    // 0x80044820: nop

    after_1:
    // 0x80044824: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80044828: bne         $at, $zero, L_80044838
    if (ctx->r1 != 0) {
        // 0x8004482C: slti        $at, $s1, 0x4
        ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
            goto L_80044838;
    }
    // 0x8004482C: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80044830: beq         $at, $zero, L_80044858
    if (ctx->r1 == 0) {
        // 0x80044834: nop
    
            goto L_80044858;
    }
    // 0x80044834: nop

L_80044838:
    // 0x80044838: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x8004483C: jal         0x80046218
    // 0x80044840: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_2;
    // 0x80044840: nop

    after_2:
    // 0x80044844: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80044848: beq         $at, $zero, L_8004490C
    if (ctx->r1 == 0) {
        // 0x8004484C: slti        $at, $s1, 0x3
        ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
            goto L_8004490C;
    }
    // 0x8004484C: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x80044850: bne         $at, $zero, L_8004490C
    if (ctx->r1 != 0) {
        // 0x80044854: nop
    
            goto L_8004490C;
    }
    // 0x80044854: nop

L_80044858:
    // 0x80044858: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8004485C: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80044860: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80044864: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80044868: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8004486C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80044870: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x80044874: lwc1        $f4, 0x24($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X24);
    // 0x80044878: nop

    // 0x8004487C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80044880: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x80044884: nop

    // 0x80044888: andi        $at, $s2, 0x4
    ctx->r1 = ctx->r18 & 0X4;
    // 0x8004488C: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x80044890: beq         $s2, $zero, L_800448E0
    if (ctx->r18 == 0) {
        // 0x80044894: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_800448E0;
    }
    // 0x80044894: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80044898: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004489C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800448A0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800448A4: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x800448A8: nop

    // 0x800448AC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800448B0: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x800448B4: nop

    // 0x800448B8: andi        $at, $s2, 0x4
    ctx->r1 = ctx->r18 & 0X4;
    // 0x800448BC: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x800448C0: bne         $s2, $zero, L_800448D8
    if (ctx->r18 != 0) {
        // 0x800448C4: nop
    
            goto L_800448D8;
    }
    // 0x800448C4: nop

    // 0x800448C8: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x800448CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800448D0: b           L_800448F0
    // 0x800448D4: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
        goto L_800448F0;
    // 0x800448D4: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
L_800448D8:
    // 0x800448D8: b           L_800448F0
    // 0x800448DC: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
        goto L_800448F0;
    // 0x800448DC: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_800448E0:
    // 0x800448E0: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x800448E4: nop

    // 0x800448E8: bltz        $s2, L_800448D8
    if (SIGNED(ctx->r18) < 0) {
        // 0x800448EC: nop
    
            goto L_800448D8;
    }
    // 0x800448EC: nop

L_800448F0:
    // 0x800448F0: andi        $t7, $s2, 0xFFFF
    ctx->r15 = ctx->r18 & 0XFFFF;
    // 0x800448F4: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800448F8: addiu       $s3, $s2, 0xBE
    ctx->r19 = ADD32(ctx->r18, 0XBE);
    // 0x800448FC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80044900: andi        $t8, $s3, 0xFFFF
    ctx->r24 = ctx->r19 & 0XFFFF;
    // 0x80044904: b           L_80044938
    // 0x80044908: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
        goto L_80044938;
    // 0x80044908: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_8004490C:
    // 0x8004490C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80044910: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80044914: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80044918: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8004491C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80044920: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80044924: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80044928: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8004492C: lhu         $s2, 0x0($t2)
    ctx->r18 = MEM_HU(ctx->r10, 0X0);
    // 0x80044930: lhu         $s3, 0x2($t6)
    ctx->r19 = MEM_HU(ctx->r14, 0X2);
    // 0x80044934: nop

L_80044938:
    // 0x80044938: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8004493C: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80044940: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80044944: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80044948: nop

    // 0x8004494C: lbu         $t1, 0x20($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X20);
    // 0x80044950: nop

    // 0x80044954: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80044958: bne         $t2, $zero, L_80044A3C
    if (ctx->r10 != 0) {
        // 0x8004495C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80044A3C;
    }
    // 0x8004495C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80044960: beq         $s2, $at, L_80044A3C
    if (ctx->r18 == ctx->r1) {
        // 0x80044964: nop
    
            goto L_80044A3C;
    }
    // 0x80044964: nop

    // 0x80044968: lhu         $t3, 0x2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X2);
    // 0x8004496C: nop

    // 0x80044970: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80044974: beq         $at, $zero, L_80044A3C
    if (ctx->r1 == 0) {
        // 0x80044978: nop
    
            goto L_80044A3C;
    }
    // 0x80044978: nop

    // 0x8004497C: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
    // 0x80044980: nop

    // 0x80044984: slt         $at, $t4, $s2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80044988: bne         $at, $zero, L_80044A3C
    if (ctx->r1 != 0) {
        // 0x8004498C: nop
    
            goto L_80044A3C;
    }
    // 0x8004498C: nop

    // 0x80044990: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80044994: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80044998: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8004499C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800449A0: jal         0x800773A4
    // 0x800449A4: nop

    CubeTiles_ObjSetAnimating(rdram, ctx);
        goto after_3;
    // 0x800449A4: nop

    after_3:
    // 0x800449A8: lhu         $t8, 0x2($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X2);
    // 0x800449AC: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x800449B0: subu        $t9, $t8, $s4
    ctx->r25 = SUB32(ctx->r24, ctx->r20);
    // 0x800449B4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800449B8: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x800449BC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800449C0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800449C4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800449C8: nop

    // 0x800449CC: swc1        $f10, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f10.u32l;
    // 0x800449D0: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x800449D4: jal         0x80046218
    // 0x800449D8: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_4;
    // 0x800449D8: nop

    after_4:
    // 0x800449DC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800449E0: bne         $at, $zero, L_80044A3C
    if (ctx->r1 != 0) {
        // 0x800449E4: nop
    
            goto L_80044A3C;
    }
    // 0x800449E4: nop

    // 0x800449E8: bne         $s1, $zero, L_80044A3C
    if (ctx->r17 != 0) {
        // 0x800449EC: nop
    
            goto L_80044A3C;
    }
    // 0x800449EC: nop

    // 0x800449F0: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x800449F4: nop

    // 0x800449F8: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800449FC: nop

    // 0x80044A00: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80044A04: jal         0x800A4620
    // 0x80044A08: nop

    wonders1_ObjSetFlag40(rdram, ctx);
        goto after_5;
    // 0x80044A08: nop

    after_5:
    // 0x80044A0C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80044A10: nop

    // 0x80044A14: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80044A18: nop

    // 0x80044A1C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80044A20: jal         0x800A4630
    // 0x80044A24: nop

    wonders1_ObjClearFlag40(rdram, ctx);
        goto after_6;
    // 0x80044A24: nop

    after_6:
    // 0x80044A28: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80044A2C: nop

    // 0x80044A30: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x80044A34: jal         0x800773B8
    // 0x80044A38: nop

    CubeTiles_ObjClearAnimating(rdram, ctx);
        goto after_7;
    // 0x80044A38: nop

    after_7:
L_80044A3C:
    // 0x80044A3C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80044A40: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80044A44: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80044A48: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80044A4C: nop

    // 0x80044A50: lbu         $t3, 0x20($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X20);
    // 0x80044A54: nop

    // 0x80044A58: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80044A5C: beq         $t4, $zero, L_80044BCC
    if (ctx->r12 == 0) {
        // 0x80044A60: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80044BCC;
    }
    // 0x80044A60: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80044A64: beq         $s3, $at, L_80044BCC
    if (ctx->r19 == ctx->r1) {
        // 0x80044A68: nop
    
            goto L_80044BCC;
    }
    // 0x80044A68: nop

    // 0x80044A6C: lhu         $t5, 0x2($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X2);
    // 0x80044A70: nop

    // 0x80044A74: slt         $at, $t5, $s3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80044A78: bne         $at, $zero, L_80044BCC
    if (ctx->r1 != 0) {
        // 0x80044A7C: nop
    
            goto L_80044BCC;
    }
    // 0x80044A7C: nop

    // 0x80044A80: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80044A84: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80044A88: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80044A8C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80044A90: jal         0x800773B8
    // 0x80044A94: nop

    CubeTiles_ObjClearAnimating(rdram, ctx);
        goto after_8;
    // 0x80044A94: nop

    after_8:
    // 0x80044A98: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x80044A9C: jal         0x80046218
    // 0x80044AA0: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_9;
    // 0x80044AA0: nop

    after_9:
    // 0x80044AA4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80044AA8: bne         $at, $zero, L_80044AB8
    if (ctx->r1 != 0) {
        // 0x80044AAC: slti        $at, $s1, 0x4
        ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
            goto L_80044AB8;
    }
    // 0x80044AAC: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80044AB0: beq         $at, $zero, L_80044AD8
    if (ctx->r1 == 0) {
        // 0x80044AB4: nop
    
            goto L_80044AD8;
    }
    // 0x80044AB4: nop

L_80044AB8:
    // 0x80044AB8: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x80044ABC: jal         0x80046218
    // 0x80044AC0: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_10;
    // 0x80044AC0: nop

    after_10:
    // 0x80044AC4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80044AC8: beq         $at, $zero, L_80044B60
    if (ctx->r1 == 0) {
        // 0x80044ACC: slti        $at, $s1, 0x3
        ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
            goto L_80044B60;
    }
    // 0x80044ACC: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x80044AD0: bne         $at, $zero, L_80044B60
    if (ctx->r1 != 0) {
        // 0x80044AD4: nop
    
            goto L_80044B60;
    }
    // 0x80044AD4: nop

L_80044AD8:
    // 0x80044AD8: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80044ADC: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80044AE0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80044AE4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80044AE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044AEC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80044AF0: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80044AF4: sw          $t3, 0x1F64($at)
    MEM_W(0X1F64, ctx->r1) = ctx->r11;
    // 0x80044AF8: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x80044AFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044B00: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80044B04: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80044B08: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80044B0C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80044B10: nop

    // 0x80044B14: sw          $t8, 0x1F60($at)
    MEM_W(0X1F60, ctx->r1) = ctx->r24;
    // 0x80044B18: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80044B1C: nop

    // 0x80044B20: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80044B24: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80044B28: jal         0x80044628
    // 0x80044B2C: nop

    wonders1_CreateColumnTileObject(rdram, ctx);
        goto after_11;
    // 0x80044B2C: nop

    after_11:
    // 0x80044B30: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80044B34: lw          $a0, 0x1F64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F64);
    // 0x80044B38: jal         0x800A6AA8
    // 0x80044B3C: nop

    CubeTiles_ObjReleaseNode(rdram, ctx);
        goto after_12;
    // 0x80044B3C: nop

    after_12:
    // 0x80044B40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80044B44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044B48: lw          $a0, 0x1F60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F60);
    // 0x80044B4C: jal         0x800A6A2C
    // 0x80044B50: sw          $zero, 0x1F64($at)
    MEM_W(0X1F64, ctx->r1) = 0;
    CubeTiles_ObjInstanceFree(rdram, ctx);
        goto after_13;
    // 0x80044B50: sw          $zero, 0x1F64($at)
    MEM_W(0X1F64, ctx->r1) = 0;
    after_13:
    // 0x80044B54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044B58: jal         0x8004A34C
    // 0x80044B5C: sw          $zero, 0x1F60($at)
    MEM_W(0X1F60, ctx->r1) = 0;
    Main_DrainMessageQueue(rdram, ctx);
        goto after_14;
    // 0x80044B5C: sw          $zero, 0x1F60($at)
    MEM_W(0X1F60, ctx->r1) = 0;
    after_14:
L_80044B60:
    // 0x80044B60: lb          $t2, 0x1($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1);
    // 0x80044B64: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80044B68: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80044B6C: lbu         $t3, -0xA10($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0XA10);
    // 0x80044B70: nop

    // 0x80044B74: bne         $t3, $s1, L_80044BCC
    if (ctx->r11 != ctx->r17) {
        // 0x80044B78: nop
    
            goto L_80044BCC;
    }
    // 0x80044B78: nop

    // 0x80044B7C: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x80044B80: jal         0x8004619C
    // 0x80044B84: nop

    wonders2_IsLastColumnOfWonder(rdram, ctx);
        goto after_15;
    // 0x80044B84: nop

    after_15:
    // 0x80044B88: beq         $v0, $zero, L_80044BCC
    if (ctx->r2 == 0) {
        // 0x80044B8C: nop
    
            goto L_80044BCC;
    }
    // 0x80044B8C: nop

    // 0x80044B90: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x80044B94: jal         0x80046218
    // 0x80044B98: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_16;
    // 0x80044B98: nop

    after_16:
    // 0x80044B9C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80044BA0: bne         $at, $zero, L_80044BB4
    if (ctx->r1 != 0) {
        // 0x80044BA4: nop
    
            goto L_80044BB4;
    }
    // 0x80044BA4: nop

    // 0x80044BA8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80044BAC: b           L_80044BCC
    // 0x80044BB0: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
        goto L_80044BCC;
    // 0x80044BB0: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
L_80044BB4:
    // 0x80044BB4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80044BB8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80044BBC: jal         0x8007EFB0
    // 0x80044BC0: nop

    Gfx_BeginScreenFade2(rdram, ctx);
        goto after_17;
    // 0x80044BC0: nop

    after_17:
    // 0x80044BC4: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80044BC8: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
L_80044BCC:
    // 0x80044BCC: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80044BD0: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80044BD4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80044BD8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80044BDC: jal         0x80077098
    // 0x80044BE0: nop

    CubeTiles_ObjDraw(rdram, ctx);
        goto after_18;
    // 0x80044BE0: nop

    after_18:
    // 0x80044BE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80044BE8: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x80044BEC: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x80044BF0: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80044BF4: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80044BF8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80044BFC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80044C00: nop

    // 0x80044C04: bne         $t3, $zero, L_800447D4
    if (ctx->r11 != 0) {
        // 0x80044C08: nop
    
            goto L_800447D4;
    }
    // 0x80044C08: nop

L_80044C0C:
    // 0x80044C0C: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x80044C10: jal         0x80046218
    // 0x80044C14: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_19;
    // 0x80044C14: nop

    after_19:
    // 0x80044C18: sb          $v0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r2;
    // 0x80044C1C: lb          $a0, 0x57($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X57);
    // 0x80044C20: jal         0x80046388
    // 0x80044C24: nop

    wonders2_GetLinesRemainingToWonder(rdram, ctx);
        goto after_20;
    // 0x80044C24: nop

    after_20:
    // 0x80044C28: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80044C2C: bne         $s5, $zero, L_80044C54
    if (ctx->r21 != 0) {
        // 0x80044C30: nop
    
            goto L_80044C54;
    }
    // 0x80044C30: nop

    // 0x80044C34: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044C38: addiu       $a1, $a1, -0x4B60
    ctx->r5 = ADD32(ctx->r5, -0X4B60);
    // 0x80044C3C: jal         0x800B62D4
    // 0x80044C40: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_21;
    // 0x80044C40: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_21:
    // 0x80044C44: jal         0x800446AC
    // 0x80044C48: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    wonders1_UpdatePulseAlpha(rdram, ctx);
        goto after_22;
    // 0x80044C48: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_22:
    // 0x80044C4C: b           L_80044C8C
    // 0x80044C50: nop

        goto L_80044C8C;
    // 0x80044C50: nop

L_80044C54:
    // 0x80044C54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80044C58: bne         $s5, $at, L_80044C78
    if (ctx->r21 != ctx->r1) {
        // 0x80044C5C: nop
    
            goto L_80044C78;
    }
    // 0x80044C5C: nop

    // 0x80044C60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044C64: addiu       $a1, $a1, -0x4B50
    ctx->r5 = ADD32(ctx->r5, -0X4B50);
    // 0x80044C68: jal         0x800B62D4
    // 0x80044C6C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_23;
    // 0x80044C6C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_23:
    // 0x80044C70: b           L_80044C8C
    // 0x80044C74: nop

        goto L_80044C8C;
    // 0x80044C74: nop

L_80044C78:
    // 0x80044C78: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044C7C: addiu       $a1, $a1, -0x4B40
    ctx->r5 = ADD32(ctx->r5, -0X4B40);
    // 0x80044C80: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80044C84: jal         0x800B62D4
    // 0x80044C88: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_24;
    // 0x80044C88: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_24:
L_80044C8C:
    // 0x80044C8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80044C90: jal         0x8005BBFC
    // 0x80044C94: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_25;
    // 0x80044C94: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_25:
    // 0x80044C98: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x80044C9C: jal         0x80077D88
    // 0x80044CA0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    Font_GetTextWidth(rdram, ctx);
        goto after_26;
    // 0x80044CA0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_26:
    // 0x80044CA4: bgez        $v0, L_80044CB4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80044CA8: sra         $t4, $v0, 1
        ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80044CB4;
    }
    // 0x80044CA8: sra         $t4, $v0, 1
    ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80044CAC: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80044CB0: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80044CB4:
    // 0x80044CB4: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x80044CB8: subu        $s1, $t5, $t4
    ctx->r17 = SUB32(ctx->r13, ctx->r12);
    // 0x80044CBC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80044CC0: lbu         $t1, 0x1F6E($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1F6E);
    // 0x80044CC4: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x80044CC8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80044CCC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80044CD0: addiu       $t7, $sp, 0x58
    ctx->r15 = ADD32(ctx->r29, 0X58);
    // 0x80044CD4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80044CD8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80044CDC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80044CE0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80044CE4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80044CE8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80044CEC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80044CF0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80044CF4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80044CF8: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80044CFC: addiu       $a3, $zero, 0xFA
    ctx->r7 = ADD32(0, 0XFA);
    // 0x80044D00: jal         0x80077960
    // 0x80044D04: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_27;
    // 0x80044D04: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_27:
    // 0x80044D08: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x80044D0C: nop

    // 0x80044D10: bne         $t2, $zero, L_80044E98
    if (ctx->r10 != 0) {
        // 0x80044D14: nop
    
            goto L_80044E98;
    }
    // 0x80044D14: nop

    // 0x80044D18: lh          $t3, 0xF8($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XF8);
    // 0x80044D1C: lhu         $s6, 0x80($s0)
    ctx->r22 = MEM_HU(ctx->r16, 0X80);
    // 0x80044D20: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80044D24: addu        $s7, $s6, $t5
    ctx->r23 = ADD32(ctx->r22, ctx->r13);
    // 0x80044D28: andi        $t4, $s7, 0xFFFF
    ctx->r12 = ctx->r23 & 0XFFFF;
    // 0x80044D2C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044D30: or          $s7, $t4, $zero
    ctx->r23 = ctx->r12 | 0;
    // 0x80044D34: addiu       $s1, $zero, 0x82
    ctx->r17 = ADD32(0, 0X82);
    // 0x80044D38: addiu       $a1, $a1, -0x4B30
    ctx->r5 = ADD32(ctx->r5, -0X4B30);
    // 0x80044D3C: jal         0x800B62D4
    // 0x80044D40: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_28;
    // 0x80044D40: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_28:
    // 0x80044D44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80044D48: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x80044D4C: addiu       $t7, $zero, 0x7F
    ctx->r15 = ADD32(0, 0X7F);
    // 0x80044D50: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x80044D54: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80044D58: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80044D5C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80044D60: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80044D64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80044D68: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80044D6C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80044D70: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80044D74: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80044D78: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80044D7C: jal         0x80077960
    // 0x80044D80: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_29;
    // 0x80044D80: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    after_29:
    // 0x80044D84: addu        $s1, $s1, $s6
    ctx->r17 = ADD32(ctx->r17, ctx->r22);
    // 0x80044D88: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x80044D8C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044D90: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80044D94: addiu       $a1, $a1, -0x4B2C
    ctx->r5 = ADD32(ctx->r5, -0X4B2C);
    // 0x80044D98: jal         0x800B62D4
    // 0x80044D9C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_30;
    // 0x80044D9C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_30:
    // 0x80044DA0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80044DA4: addiu       $t2, $sp, 0x58
    ctx->r10 = ADD32(ctx->r29, 0X58);
    // 0x80044DA8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80044DAC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80044DB0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80044DB4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80044DB8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80044DBC: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80044DC0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80044DC4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80044DC8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80044DCC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80044DD0: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x80044DD4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80044DD8: jal         0x80077960
    // 0x80044DDC: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_31;
    // 0x80044DDC: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    after_31:
    // 0x80044DE0: addu        $s1, $s1, $s7
    ctx->r17 = ADD32(ctx->r17, ctx->r23);
    // 0x80044DE4: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x80044DE8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044DEC: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80044DF0: addiu       $a1, $a1, -0x4B24
    ctx->r5 = ADD32(ctx->r5, -0X4B24);
    // 0x80044DF4: jal         0x800B62D4
    // 0x80044DF8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_32;
    // 0x80044DF8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_32:
    // 0x80044DFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80044E00: addiu       $t8, $sp, 0x58
    ctx->r24 = ADD32(ctx->r29, 0X58);
    // 0x80044E04: addiu       $t9, $zero, 0x7F
    ctx->r25 = ADD32(0, 0X7F);
    // 0x80044E08: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80044E0C: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x80044E10: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80044E14: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80044E18: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80044E1C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80044E20: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80044E24: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80044E28: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80044E2C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80044E30: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80044E34: jal         0x80077960
    // 0x80044E38: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_33;
    // 0x80044E38: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    after_33:
    // 0x80044E3C: addu        $s1, $s1, $s6
    ctx->r17 = ADD32(ctx->r17, ctx->r22);
    // 0x80044E40: andi        $t3, $s1, 0xFFFF
    ctx->r11 = ctx->r17 & 0XFFFF;
    // 0x80044E44: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044E48: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80044E4C: addiu       $a1, $a1, -0x4B20
    ctx->r5 = ADD32(ctx->r5, -0X4B20);
    // 0x80044E50: jal         0x800B62D4
    // 0x80044E54: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_34;
    // 0x80044E54: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_34:
    // 0x80044E58: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80044E5C: addiu       $t5, $sp, 0x58
    ctx->r13 = ADD32(ctx->r29, 0X58);
    // 0x80044E60: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80044E64: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80044E68: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80044E6C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80044E70: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80044E74: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80044E78: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80044E7C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80044E80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80044E84: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80044E88: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x80044E8C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80044E90: jal         0x80077960
    // 0x80044E94: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_35;
    // 0x80044E94: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    after_35:
L_80044E98:
    // 0x80044E98: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80044E9C: jal         0x8005BE40
    // 0x80044EA0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_36;
    // 0x80044EA0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_36:
    // 0x80044EA4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80044EA8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80044EAC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80044EB0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80044EB4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80044EB8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80044EBC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80044EC0: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80044EC4: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80044EC8: jr          $ra
    // 0x80044ECC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80044ECC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}

RECOMP_FUNC void wonders1_display_complete_message(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044ED0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80044ED4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80044ED8: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80044EDC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80044EE0: lw          $s0, 0x5E10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5E10);
    // 0x80044EE4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80044EE8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80044EEC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80044EF0: jal         0x800A3AF0
    // 0x80044EF4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    frametime_delta(rdram, ctx);
        goto after_0;
    // 0x80044EF4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    after_0:
    // 0x80044EF8: lhu         $t6, 0x2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2);
    // 0x80044EFC: andi        $s4, $v0, 0xFF
    ctx->r20 = ctx->r2 & 0XFF;
    // 0x80044F00: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80044F04: addu        $t7, $t6, $s4
    ctx->r15 = ADD32(ctx->r14, ctx->r20);
    // 0x80044F08: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80044F0C: beq         $at, $zero, L_80044F28
    if (ctx->r1 == 0) {
        // 0x80044F10: nop
    
            goto L_80044F28;
    }
    // 0x80044F10: nop

    // 0x80044F14: lhu         $t8, 0x2($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X2);
    // 0x80044F18: nop

    // 0x80044F1C: addu        $t9, $t8, $s4
    ctx->r25 = ADD32(ctx->r24, ctx->r20);
    // 0x80044F20: b           L_80044F30
    // 0x80044F24: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
        goto L_80044F30;
    // 0x80044F24: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
L_80044F28:
    // 0x80044F28: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x80044F2C: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
L_80044F30:
    // 0x80044F30: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x80044F34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80044F38: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80044F3C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80044F40: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80044F44: nop

    // 0x80044F48: beq         $t4, $zero, L_800450C8
    if (ctx->r12 == 0) {
        // 0x80044F4C: nop
    
            goto L_800450C8;
    }
    // 0x80044F4C: nop

L_80044F50:
    // 0x80044F50: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80044F54: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80044F58: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80044F5C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80044F60: nop

    // 0x80044F64: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80044F68: nop

    // 0x80044F6C: beq         $t9, $zero, L_80045088
    if (ctx->r25 == 0) {
        // 0x80044F70: nop
    
            goto L_80045088;
    }
    // 0x80044F70: nop

    // 0x80044F74: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80044F78: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80044F7C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80044F80: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80044F84: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80044F88: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80044F8C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80044F90: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80044F94: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80044F98: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80044F9C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80044FA0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80044FA4: lbu         $t2, 0x20($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X20);
    // 0x80044FA8: lhu         $s2, 0x0($t3)
    ctx->r18 = MEM_HU(ctx->r11, 0X0);
    // 0x80044FAC: lhu         $s3, 0x2($t7)
    ctx->r19 = MEM_HU(ctx->r15, 0X2);
    // 0x80044FB0: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80044FB4: bne         $t3, $zero, L_8004502C
    if (ctx->r11 != 0) {
        // 0x80044FB8: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004502C;
    }
    // 0x80044FB8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80044FBC: beq         $s2, $at, L_8004502C
    if (ctx->r18 == ctx->r1) {
        // 0x80044FC0: nop
    
            goto L_8004502C;
    }
    // 0x80044FC0: nop

    // 0x80044FC4: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
    // 0x80044FC8: nop

    // 0x80044FCC: slt         $at, $t4, $s3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80044FD0: beq         $at, $zero, L_8004502C
    if (ctx->r1 == 0) {
        // 0x80044FD4: nop
    
            goto L_8004502C;
    }
    // 0x80044FD4: nop

    // 0x80044FD8: lhu         $t5, 0x2($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X2);
    // 0x80044FDC: nop

    // 0x80044FE0: slt         $at, $t5, $s2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80044FE4: bne         $at, $zero, L_8004502C
    if (ctx->r1 != 0) {
        // 0x80044FE8: nop
    
            goto L_8004502C;
    }
    // 0x80044FE8: nop

    // 0x80044FEC: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80044FF0: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80044FF4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80044FF8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80044FFC: jal         0x800773A4
    // 0x80045000: nop

    CubeTiles_ObjSetAnimating(rdram, ctx);
        goto after_1;
    // 0x80045000: nop

    after_1:
    // 0x80045004: lhu         $t9, 0x2($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2);
    // 0x80045008: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x8004500C: subu        $t0, $t9, $s4
    ctx->r8 = SUB32(ctx->r25, ctx->r20);
    // 0x80045010: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80045014: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80045018: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004501C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80045020: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80045024: nop

    // 0x80045028: swc1        $f6, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f6.u32l;
L_8004502C:
    // 0x8004502C: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80045030: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80045034: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80045038: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8004503C: nop

    // 0x80045040: lbu         $t9, 0x20($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X20);
    // 0x80045044: nop

    // 0x80045048: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8004504C: beq         $t0, $zero, L_80045088
    if (ctx->r8 == 0) {
        // 0x80045050: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80045088;
    }
    // 0x80045050: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80045054: beq         $s3, $at, L_80045088
    if (ctx->r19 == ctx->r1) {
        // 0x80045058: nop
    
            goto L_80045088;
    }
    // 0x80045058: nop

    // 0x8004505C: lhu         $t1, 0x2($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X2);
    // 0x80045060: nop

    // 0x80045064: slt         $at, $t1, $s3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80045068: bne         $at, $zero, L_80045088
    if (ctx->r1 != 0) {
        // 0x8004506C: nop
    
            goto L_80045088;
    }
    // 0x8004506C: nop

    // 0x80045070: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80045074: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80045078: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004507C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80045080: jal         0x800773B8
    // 0x80045084: nop

    CubeTiles_ObjClearAnimating(rdram, ctx);
        goto after_2;
    // 0x80045084: nop

    after_2:
L_80045088:
    // 0x80045088: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8004508C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80045090: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80045094: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80045098: jal         0x80077098
    // 0x8004509C: nop

    CubeTiles_ObjDraw(rdram, ctx);
        goto after_3;
    // 0x8004509C: nop

    after_3:
    // 0x800450A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800450A4: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x800450A8: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800450AC: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x800450B0: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x800450B4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800450B8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800450BC: nop

    // 0x800450C0: bne         $t2, $zero, L_80044F50
    if (ctx->r10 != 0) {
        // 0x800450C4: nop
    
            goto L_80044F50;
    }
    // 0x800450C4: nop

L_800450C8:
    // 0x800450C8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800450CC: addiu       $a1, $a1, -0x4B18
    ctx->r5 = ADD32(ctx->r5, -0X4B18);
    // 0x800450D0: jal         0x800B62D4
    // 0x800450D4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x800450D4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x800450D8: jal         0x800446AC
    // 0x800450DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    wonders1_UpdatePulseAlpha(rdram, ctx);
        goto after_5;
    // 0x800450DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x800450E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800450E4: jal         0x8005BBFC
    // 0x800450E8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_6;
    // 0x800450E8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_6:
    // 0x800450EC: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x800450F0: jal         0x80077D88
    // 0x800450F4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    Font_GetTextWidth(rdram, ctx);
        goto after_7;
    // 0x800450F4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_7:
    // 0x800450F8: bgez        $v0, L_80045108
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800450FC: sra         $t3, $v0, 1
        ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80045108;
    }
    // 0x800450FC: sra         $t3, $v0, 1
    ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80045100: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80045104: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80045108:
    // 0x80045108: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x8004510C: subu        $s1, $t4, $t3
    ctx->r17 = SUB32(ctx->r12, ctx->r11);
    // 0x80045110: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80045114: lbu         $t0, 0x1F6E($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X1F6E);
    // 0x80045118: andi        $t5, $s1, 0xFFFF
    ctx->r13 = ctx->r17 & 0XFFFF;
    // 0x8004511C: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x80045120: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80045124: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x80045128: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8004512C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80045130: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80045134: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80045138: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8004513C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80045140: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80045144: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80045148: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004514C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80045150: addiu       $a3, $zero, 0xFA
    ctx->r7 = ADD32(0, 0XFA);
    // 0x80045154: jal         0x80077960
    // 0x80045158: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_8;
    // 0x80045158: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_8:
    // 0x8004515C: jal         0x80047C58
    // 0x80045160: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    wonders4_display_contribs_or_story(rdram, ctx);
        goto after_9;
    // 0x80045160: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    after_9:
    // 0x80045164: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80045168: jal         0x8005BE40
    // 0x8004516C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_10;
    // 0x8004516C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_10:
    // 0x80045170: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80045174: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80045178: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8004517C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80045180: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80045184: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80045188: jr          $ra
    // 0x8004518C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8004518C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}

RECOMP_FUNC void wonders1_finale_or_hall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045190: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80045194: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80045198: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8004519C: lw          $s0, 0x5E10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5E10);
    // 0x800451A0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800451A4: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800451A8: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800451AC: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800451B0: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800451B4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800451B8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x800451BC: nop

    // 0x800451C0: bne         $t6, $zero, L_80045200
    if (ctx->r14 != 0) {
        // 0x800451C4: nop
    
            goto L_80045200;
    }
    // 0x800451C4: nop

    // 0x800451C8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800451CC: nop

    // 0x800451D0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800451D4: nop

    // 0x800451D8: lbu         $t9, 0x20($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X20);
    // 0x800451DC: nop

    // 0x800451E0: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800451E4: bne         $t0, $zero, L_80045200
    if (ctx->r8 != 0) {
        // 0x800451E8: nop
    
            goto L_80045200;
    }
    // 0x800451E8: nop

    // 0x800451EC: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x800451F0: nop

    // 0x800451F4: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800451F8: jal         0x800773A4
    // 0x800451FC: nop

    CubeTiles_ObjSetAnimating(rdram, ctx);
        goto after_0;
    // 0x800451FC: nop

    after_0:
L_80045200:
    // 0x80045200: jal         0x800A3AF0
    // 0x80045204: nop

    frametime_delta(rdram, ctx);
        goto after_1;
    // 0x80045204: nop

    after_1:
    // 0x80045208: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
    // 0x8004520C: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x80045210: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80045214: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80045218: slt         $at, $t3, $at
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004521C: beq         $at, $zero, L_80045238
    if (ctx->r1 == 0) {
        // 0x80045220: nop
    
            goto L_80045238;
    }
    // 0x80045220: nop

    // 0x80045224: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
    // 0x80045228: nop

    // 0x8004522C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80045230: b           L_80045240
    // 0x80045234: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
        goto L_80045240;
    // 0x80045234: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
L_80045238:
    // 0x80045238: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x8004523C: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
L_80045240:
    // 0x80045240: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x80045244: jal         0x80046218
    // 0x80045248: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_2;
    // 0x80045248: nop

    after_2:
    // 0x8004524C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80045250: andi        $s2, $v0, 0xFFFF
    ctx->r18 = ctx->r2 & 0XFFFF;
    // 0x80045254: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80045258: nop

    // 0x8004525C: lbu         $t9, 0x20($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X20);
    // 0x80045260: nop

    // 0x80045264: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80045268: beq         $t0, $zero, L_80045344
    if (ctx->r8 == 0) {
        // 0x8004526C: nop
    
            goto L_80045344;
    }
    // 0x8004526C: nop

    // 0x80045270: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80045274: lhu         $t1, 0x2($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X2);
    // 0x80045278: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8004527C: nop

    // 0x80045280: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x80045284: nop

    // 0x80045288: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8004528C: bne         $at, $zero, L_80045344
    if (ctx->r1 != 0) {
        // 0x80045290: nop
    
            goto L_80045344;
    }
    // 0x80045290: nop

    // 0x80045294: beq         $s2, $zero, L_800452A4
    if (ctx->r18 == 0) {
        // 0x80045298: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_800452A4;
    }
    // 0x80045298: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004529C: bne         $s2, $at, L_800452F4
    if (ctx->r18 != ctx->r1) {
        // 0x800452A0: nop
    
            goto L_800452F4;
    }
    // 0x800452A0: nop

L_800452A4:
    // 0x800452A4: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x800452A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800452AC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800452B0: nop

    // 0x800452B4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800452B8: nop

    // 0x800452BC: lw          $s3, 0x1D0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X1D0);
    // 0x800452C0: nop

    // 0x800452C4: lwc1        $f4, 0x18($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X18);
    // 0x800452C8: nop

    // 0x800452CC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800452D0: nop

    // 0x800452D4: bc1f        L_80045308
    if (!c1cs) {
        // 0x800452D8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80045308;
    }
    // 0x800452D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800452DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800452E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800452E4: lw          $t8, 0xC($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XC);
    // 0x800452E8: swc1        $f8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f8.u32l;
    // 0x800452EC: b           L_80045308
    // 0x800452F0: swc1        $f10, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f10.u32l;
        goto L_80045308;
    // 0x800452F0: swc1        $f10, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f10.u32l;
L_800452F4:
    // 0x800452F4: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800452F8: nop

    // 0x800452FC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80045300: jal         0x800773B8
    // 0x80045304: nop

    CubeTiles_ObjClearAnimating(rdram, ctx);
        goto after_3;
    // 0x80045304: nop

    after_3:
L_80045308:
    // 0x80045308: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
    // 0x8004530C: nop

    // 0x80045310: bne         $t0, $zero, L_80045344
    if (ctx->r8 != 0) {
        // 0x80045314: nop
    
            goto L_80045344;
    }
    // 0x80045314: nop

    // 0x80045318: lb          $t2, 0x1($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1);
    // 0x8004531C: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80045320: bne         $t2, $at, L_80045344
    if (ctx->r10 != ctx->r1) {
        // 0x80045324: nop
    
            goto L_80045344;
    }
    // 0x80045324: nop

    // 0x80045328: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8004532C: lbu         $t3, -0x7C0($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X7C0);
    // 0x80045330: nop

    // 0x80045334: bne         $t3, $zero, L_80045344
    if (ctx->r11 != 0) {
        // 0x80045338: nop
    
            goto L_80045344;
    }
    // 0x80045338: nop

    // 0x8004533C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80045340: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
L_80045344:
    // 0x80045344: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x80045348: nop

    // 0x8004534C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80045350: jal         0x80077098
    // 0x80045354: nop

    CubeTiles_ObjDraw(rdram, ctx);
        goto after_4;
    // 0x80045354: nop

    after_4:
    // 0x80045358: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x8004535C: nop

    // 0x80045360: beq         $t5, $zero, L_80045378
    if (ctx->r13 == 0) {
        // 0x80045364: nop
    
            goto L_80045378;
    }
    // 0x80045364: nop

    // 0x80045368: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8004536C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80045370: bne         $t6, $at, L_80045598
    if (ctx->r14 != ctx->r1) {
        // 0x80045374: nop
    
            goto L_80045598;
    }
    // 0x80045374: nop

L_80045378:
    // 0x80045378: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8004537C: jal         0x8005BBFC
    // 0x80045380: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_5;
    // 0x80045380: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_5:
    // 0x80045384: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80045388: nop

    // 0x8004538C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80045390: nop

    // 0x80045394: lbu         $t9, 0x20($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X20);
    // 0x80045398: nop

    // 0x8004539C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800453A0: beq         $t0, $zero, L_800453E0
    if (ctx->r8 == 0) {
        // 0x800453A4: nop
    
            goto L_800453E0;
    }
    // 0x800453A4: nop

    // 0x800453A8: bne         $s2, $zero, L_800453C0
    if (ctx->r18 != 0) {
        // 0x800453AC: nop
    
            goto L_800453C0;
    }
    // 0x800453AC: nop

    // 0x800453B0: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
    // 0x800453B4: nop

    // 0x800453B8: slti        $at, $t2, 0xABD
    ctx->r1 = SIGNED(ctx->r10) < 0XABD ? 1 : 0;
    // 0x800453BC: beq         $at, $zero, L_800453E0
    if (ctx->r1 == 0) {
        // 0x800453C0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_800453E0;
    }
L_800453C0:
    // 0x800453C0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800453C4: bne         $s2, $at, L_800453E8
    if (ctx->r18 != ctx->r1) {
        // 0x800453C8: nop
    
            goto L_800453E8;
    }
    // 0x800453C8: nop

    // 0x800453CC: lhu         $t3, 0x2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X2);
    // 0x800453D0: nop

    // 0x800453D4: slti        $at, $t3, 0xF9F
    ctx->r1 = SIGNED(ctx->r11) < 0XF9F ? 1 : 0;
    // 0x800453D8: bne         $at, $zero, L_800453E8
    if (ctx->r1 != 0) {
        // 0x800453DC: nop
    
            goto L_800453E8;
    }
    // 0x800453DC: nop

L_800453E0:
    // 0x800453E0: jal         0x80047C58
    // 0x800453E4: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    wonders4_display_contribs_or_story(rdram, ctx);
        goto after_6;
    // 0x800453E4: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_6:
L_800453E8:
    // 0x800453E8: lh          $t1, 0xF8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XF8);
    // 0x800453EC: lhu         $s4, 0x80($s0)
    ctx->r20 = MEM_HU(ctx->r16, 0X80);
    // 0x800453F0: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800453F4: addu        $s5, $s4, $t4
    ctx->r21 = ADD32(ctx->r20, ctx->r12);
    // 0x800453F8: andi        $t5, $s5, 0xFFFF
    ctx->r13 = ctx->r21 & 0XFFFF;
    // 0x800453FC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80045400: or          $s5, $t5, $zero
    ctx->r21 = ctx->r13 | 0;
    // 0x80045404: addiu       $s2, $zero, 0x82
    ctx->r18 = ADD32(0, 0X82);
    // 0x80045408: addiu       $a1, $a1, -0x4B08
    ctx->r5 = ADD32(ctx->r5, -0X4B08);
    // 0x8004540C: jal         0x800B62D4
    // 0x80045410: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x80045410: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_7:
    // 0x80045414: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80045418: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x8004541C: addiu       $t7, $zero, 0x7F
    ctx->r15 = ADD32(0, 0X7F);
    // 0x80045420: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x80045424: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80045428: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8004542C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80045430: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80045434: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80045438: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8004543C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80045440: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80045444: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80045448: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8004544C: jal         0x80077960
    // 0x80045450: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_8;
    // 0x80045450: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    after_8:
    // 0x80045454: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x80045458: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
    // 0x8004545C: andi        $t2, $s2, 0xFFFF
    ctx->r10 = ctx->r18 & 0XFFFF;
    // 0x80045460: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80045464: bne         $t3, $at, L_80045484
    if (ctx->r11 != ctx->r1) {
        // 0x80045468: or          $s2, $t2, $zero
        ctx->r18 = ctx->r10 | 0;
            goto L_80045484;
    }
    // 0x80045468: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x8004546C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80045470: addiu       $a1, $a1, -0x4B04
    ctx->r5 = ADD32(ctx->r5, -0X4B04);
    // 0x80045474: jal         0x800B62D4
    // 0x80045478: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    sprintf_recomp(rdram, ctx);
        goto after_9;
    // 0x80045478: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_9:
    // 0x8004547C: b           L_80045494
    // 0x80045480: nop

        goto L_80045494;
    // 0x80045480: nop

L_80045484:
    // 0x80045484: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80045488: addiu       $a1, $a1, -0x4AFC
    ctx->r5 = ADD32(ctx->r5, -0X4AFC);
    // 0x8004548C: jal         0x800B62D4
    // 0x80045490: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    sprintf_recomp(rdram, ctx);
        goto after_10;
    // 0x80045490: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_10:
L_80045494:
    // 0x80045494: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80045498: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
    // 0x8004549C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800454A0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800454A4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800454A8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800454AC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800454B0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800454B4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800454B8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800454BC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800454C0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800454C4: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x800454C8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800454CC: jal         0x80077960
    // 0x800454D0: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_11;
    // 0x800454D0: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    after_11:
    // 0x800454D4: addu        $s2, $s2, $s5
    ctx->r18 = ADD32(ctx->r18, ctx->r21);
    // 0x800454D8: andi        $t8, $s2, 0xFFFF
    ctx->r24 = ctx->r18 & 0XFFFF;
    // 0x800454DC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800454E0: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800454E4: addiu       $a1, $a1, -0x4AF4
    ctx->r5 = ADD32(ctx->r5, -0X4AF4);
    // 0x800454E8: jal         0x800B62D4
    // 0x800454EC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    sprintf_recomp(rdram, ctx);
        goto after_12;
    // 0x800454EC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_12:
    // 0x800454F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800454F4: addiu       $t9, $sp, 0x4C
    ctx->r25 = ADD32(ctx->r29, 0X4C);
    // 0x800454F8: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x800454FC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80045500: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x80045504: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80045508: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8004550C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80045510: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80045514: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80045518: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8004551C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80045520: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80045524: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80045528: jal         0x80077960
    // 0x8004552C: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_13;
    // 0x8004552C: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    after_13:
    // 0x80045530: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
    // 0x80045534: andi        $t4, $s2, 0xFFFF
    ctx->r12 = ctx->r18 & 0XFFFF;
    // 0x80045538: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004553C: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
    // 0x80045540: addiu       $a1, $a1, -0x4AF0
    ctx->r5 = ADD32(ctx->r5, -0X4AF0);
    // 0x80045544: jal         0x800B62D4
    // 0x80045548: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    sprintf_recomp(rdram, ctx);
        goto after_14;
    // 0x80045548: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_14:
    // 0x8004554C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80045550: addiu       $t5, $sp, 0x4C
    ctx->r13 = ADD32(ctx->r29, 0X4C);
    // 0x80045554: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80045558: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8004555C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80045560: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80045564: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80045568: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8004556C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80045570: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80045574: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80045578: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x8004557C: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x80045580: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80045584: jal         0x80077960
    // 0x80045588: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_15;
    // 0x80045588: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    after_15:
    // 0x8004558C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80045590: jal         0x8005BE40
    // 0x80045594: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_16;
    // 0x80045594: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_16:
L_80045598:
    // 0x80045598: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8004559C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800455A0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800455A4: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800455A8: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800455AC: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x800455B0: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x800455B4: jr          $ra
    // 0x800455B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800455B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}

RECOMP_FUNC void wonders1_RenderWonderStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800455BC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800455C0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800455C4: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x800455C8: lw          $s0, 0x5E10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5E10);
    // 0x800455CC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800455D0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800455D4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800455D8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800455DC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800455E0: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x800455E4: nop

    // 0x800455E8: bne         $t6, $zero, L_80045628
    if (ctx->r14 != 0) {
        // 0x800455EC: nop
    
            goto L_80045628;
    }
    // 0x800455EC: nop

    // 0x800455F0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800455F4: nop

    // 0x800455F8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800455FC: nop

    // 0x80045600: lbu         $t9, 0x20($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X20);
    // 0x80045604: nop

    // 0x80045608: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8004560C: bne         $t0, $zero, L_80045628
    if (ctx->r8 != 0) {
        // 0x80045610: nop
    
            goto L_80045628;
    }
    // 0x80045610: nop

    // 0x80045614: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x80045618: nop

    // 0x8004561C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80045620: jal         0x800773A4
    // 0x80045624: nop

    CubeTiles_ObjSetAnimating(rdram, ctx);
        goto after_0;
    // 0x80045624: nop

    after_0:
L_80045628:
    // 0x80045628: jal         0x800A3AF0
    // 0x8004562C: nop

    frametime_delta(rdram, ctx);
        goto after_1;
    // 0x8004562C: nop

    after_1:
    // 0x80045630: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
    // 0x80045634: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x80045638: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004563C: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80045640: slt         $at, $t3, $at
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80045644: beq         $at, $zero, L_80045660
    if (ctx->r1 == 0) {
        // 0x80045648: nop
    
            goto L_80045660;
    }
    // 0x80045648: nop

    // 0x8004564C: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
    // 0x80045650: nop

    // 0x80045654: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80045658: b           L_80045668
    // 0x8004565C: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
        goto L_80045668;
    // 0x8004565C: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
L_80045660:
    // 0x80045660: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80045664: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
L_80045668:
    // 0x80045668: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8004566C: nop

    // 0x80045670: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80045674: nop

    // 0x80045678: lbu         $t9, 0x20($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X20);
    // 0x8004567C: nop

    // 0x80045680: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80045684: beq         $t0, $zero, L_800456FC
    if (ctx->r8 == 0) {
        // 0x80045688: nop
    
            goto L_800456FC;
    }
    // 0x80045688: nop

    // 0x8004568C: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80045690: lhu         $t1, 0x2($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X2);
    // 0x80045694: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80045698: nop

    // 0x8004569C: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x800456A0: nop

    // 0x800456A4: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800456A8: bne         $at, $zero, L_800456FC
    if (ctx->r1 != 0) {
        // 0x800456AC: nop
    
            goto L_800456FC;
    }
    // 0x800456AC: nop

    // 0x800456B0: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x800456B4: nop

    // 0x800456B8: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800456BC: jal         0x800773B8
    // 0x800456C0: nop

    CubeTiles_ObjClearAnimating(rdram, ctx);
        goto after_2;
    // 0x800456C0: nop

    after_2:
    // 0x800456C4: lb          $t6, 0x1($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1);
    // 0x800456C8: nop

    // 0x800456CC: slti        $at, $t6, 0x37
    ctx->r1 = SIGNED(ctx->r14) < 0X37 ? 1 : 0;
    // 0x800456D0: beq         $at, $zero, L_800456EC
    if (ctx->r1 == 0) {
        // 0x800456D4: nop
    
            goto L_800456EC;
    }
    // 0x800456D4: nop

    // 0x800456D8: lb          $t7, 0x1($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1);
    // 0x800456DC: nop

    // 0x800456E0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800456E4: b           L_800456F4
    // 0x800456E8: sb          $t8, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r24;
        goto L_800456F4;
    // 0x800456E8: sb          $t8, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r24;
L_800456EC:
    // 0x800456EC: addiu       $t9, $zero, 0x31
    ctx->r25 = ADD32(0, 0X31);
    // 0x800456F0: sb          $t9, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r25;
L_800456F4:
    // 0x800456F4: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x800456F8: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
L_800456FC:
    // 0x800456FC: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80045700: nop

    // 0x80045704: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80045708: jal         0x80077098
    // 0x8004570C: nop

    CubeTiles_ObjDraw(rdram, ctx);
        goto after_3;
    // 0x8004570C: nop

    after_3:
    // 0x80045710: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80045714: jal         0x8005BBFC
    // 0x80045718: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_4;
    // 0x80045718: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_4:
    // 0x8004571C: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x80045720: nop

    // 0x80045724: bne         $t3, $zero, L_800457BC
    if (ctx->r11 != 0) {
        // 0x80045728: nop
    
            goto L_800457BC;
    }
    // 0x80045728: nop

    // 0x8004572C: lb          $t1, 0x1($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1);
    // 0x80045730: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80045734: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x80045738: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8004573C: lw          $a2, -0x880($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X880);
    // 0x80045740: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80045744: addiu       $a1, $a1, -0x4AE8
    ctx->r5 = ADD32(ctx->r5, -0X4AE8);
    // 0x80045748: jal         0x800B62D4
    // 0x8004574C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x8004574C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x80045750: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x80045754: jal         0x80077D88
    // 0x80045758: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    Font_GetTextWidth(rdram, ctx);
        goto after_6;
    // 0x80045758: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_6:
    // 0x8004575C: bgez        $v0, L_8004576C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80045760: sra         $t5, $v0, 1
        ctx->r13 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8004576C;
    }
    // 0x80045760: sra         $t5, $v0, 1
    ctx->r13 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80045764: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80045768: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8004576C:
    // 0x8004576C: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x80045770: subu        $s4, $t6, $t5
    ctx->r20 = SUB32(ctx->r14, ctx->r13);
    // 0x80045774: andi        $t7, $s4, 0xFFFF
    ctx->r15 = ctx->r20 & 0XFFFF;
    // 0x80045778: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x8004577C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80045780: addiu       $t8, $sp, 0x48
    ctx->r24 = ADD32(ctx->r29, 0X48);
    // 0x80045784: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80045788: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8004578C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80045790: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80045794: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80045798: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8004579C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800457A0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800457A4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800457A8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800457AC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800457B0: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x800457B4: jal         0x80077960
    // 0x800457B8: addiu       $a3, $zero, 0xFA
    ctx->r7 = ADD32(0, 0XFA);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_7;
    // 0x800457B8: addiu       $a3, $zero, 0xFA
    ctx->r7 = ADD32(0, 0XFA);
    after_7:
L_800457BC:
    // 0x800457BC: lh          $t1, 0xF8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XF8);
    // 0x800457C0: lhu         $s2, 0x80($s0)
    ctx->r18 = MEM_HU(ctx->r16, 0X80);
    // 0x800457C4: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800457C8: addu        $s3, $s2, $t4
    ctx->r19 = ADD32(ctx->r18, ctx->r12);
    // 0x800457CC: andi        $t6, $s3, 0xFFFF
    ctx->r14 = ctx->r19 & 0XFFFF;
    // 0x800457D0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800457D4: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x800457D8: addiu       $s4, $zero, 0x82
    ctx->r20 = ADD32(0, 0X82);
    // 0x800457DC: addiu       $a1, $a1, -0x4AE4
    ctx->r5 = ADD32(ctx->r5, -0X4AE4);
    // 0x800457E0: jal         0x800B62D4
    // 0x800457E4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x800457E4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_8:
    // 0x800457E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800457EC: addiu       $t5, $sp, 0x48
    ctx->r13 = ADD32(ctx->r29, 0X48);
    // 0x800457F0: addiu       $t7, $zero, 0x7F
    ctx->r15 = ADD32(0, 0X7F);
    // 0x800457F4: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x800457F8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800457FC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80045800: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80045804: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80045808: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8004580C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80045810: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80045814: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80045818: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8004581C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80045820: jal         0x80077960
    // 0x80045824: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_9;
    // 0x80045824: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    after_9:
    // 0x80045828: addu        $s4, $s4, $s2
    ctx->r20 = ADD32(ctx->r20, ctx->r18);
    // 0x8004582C: andi        $t2, $s4, 0xFFFF
    ctx->r10 = ctx->r20 & 0XFFFF;
    // 0x80045830: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80045834: or          $s4, $t2, $zero
    ctx->r20 = ctx->r10 | 0;
    // 0x80045838: addiu       $a1, $a1, -0x4AE0
    ctx->r5 = ADD32(ctx->r5, -0X4AE0);
    // 0x8004583C: jal         0x800B62D4
    // 0x80045840: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_10;
    // 0x80045840: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_10:
    // 0x80045844: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80045848: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
    // 0x8004584C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80045850: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80045854: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80045858: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8004585C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80045860: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80045864: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80045868: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8004586C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80045870: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80045874: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x80045878: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8004587C: jal         0x80077960
    // 0x80045880: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_11;
    // 0x80045880: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    after_11:
    // 0x80045884: addu        $s4, $s4, $s3
    ctx->r20 = ADD32(ctx->r20, ctx->r19);
    // 0x80045888: andi        $t7, $s4, 0xFFFF
    ctx->r15 = ctx->r20 & 0XFFFF;
    // 0x8004588C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80045890: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x80045894: addiu       $a1, $a1, -0x4AD8
    ctx->r5 = ADD32(ctx->r5, -0X4AD8);
    // 0x80045898: jal         0x800B62D4
    // 0x8004589C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_12;
    // 0x8004589C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_12:
    // 0x800458A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800458A4: addiu       $t8, $sp, 0x48
    ctx->r24 = ADD32(ctx->r29, 0X48);
    // 0x800458A8: addiu       $t9, $zero, 0x7F
    ctx->r25 = ADD32(0, 0X7F);
    // 0x800458AC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800458B0: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x800458B4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800458B8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800458BC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800458C0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800458C4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800458C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800458CC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800458D0: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x800458D4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800458D8: jal         0x80077960
    // 0x800458DC: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_13;
    // 0x800458DC: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    after_13:
    // 0x800458E0: addu        $s4, $s4, $s2
    ctx->r20 = ADD32(ctx->r20, ctx->r18);
    // 0x800458E4: andi        $t1, $s4, 0xFFFF
    ctx->r9 = ctx->r20 & 0XFFFF;
    // 0x800458E8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800458EC: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
    // 0x800458F0: addiu       $a1, $a1, -0x4AD4
    ctx->r5 = ADD32(ctx->r5, -0X4AD4);
    // 0x800458F4: jal         0x800B62D4
    // 0x800458F8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_14;
    // 0x800458F8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_14:
    // 0x800458FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80045900: addiu       $t4, $sp, 0x48
    ctx->r12 = ADD32(ctx->r29, 0X48);
    // 0x80045904: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80045908: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8004590C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80045910: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80045914: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80045918: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8004591C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80045920: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80045924: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80045928: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x8004592C: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x80045930: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80045934: jal         0x80077960
    // 0x80045938: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_15;
    // 0x80045938: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    after_15:
    // 0x8004593C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80045940: jal         0x8005BE40
    // 0x80045944: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_16;
    // 0x80045944: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_16:
    // 0x80045948: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8004594C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80045950: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80045954: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80045958: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8004595C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80045960: jr          $ra
    // 0x80045964: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80045964: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}

RECOMP_FUNC void wonders1_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045968: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004596C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80045970: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80045974: lw          $s0, 0x5E10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5E10);
    // 0x80045978: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004597C: beq         $s0, $zero, L_80045BC8
    if (ctx->r16 == 0) {
        // 0x80045980: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_80045BC8;
    }
    // 0x80045980: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80045984: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80045988: nop

    // 0x8004598C: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80045990: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x80045994: beq         $at, $zero, L_80045B5C
    if (ctx->r1 == 0) {
        // 0x80045998: nop
    
            goto L_80045B5C;
    }
    // 0x80045998: nop

    // 0x8004599C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800459A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800459A4: addu        $at, $at, $t7
    gpr jr_addend_800459B0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800459A8: lw          $t7, -0x4A68($at)
    ctx->r15 = ADD32(ctx->r1, -0X4A68);
    // 0x800459AC: nop

    // 0x800459B0: jr          $t7
    // 0x800459B4: nop

    switch (jr_addend_800459B0 >> 2) {
        case 0: goto L_800459B8; break;
        case 1: goto L_800459EC; break;
        case 2: goto L_80045A1C; break;
        case 3: goto L_80045B5C; break;
        case 4: goto L_80045A80; break;
        case 5: goto L_80045ABC; break;
        case 6: goto L_80045AEC; break;
        case 7: goto L_80045B5C; break;
        case 8: goto L_80045B5C; break;
        case 9: goto L_80045B0C; break;
        case 10: goto L_80045B3C; break;
        default: switch_error(__func__, 0x800459B0, 0x800DB598);
    }
    // 0x800459B4: nop

L_800459B8:
    // 0x800459B8: jal         0x80044748
    // 0x800459BC: nop

    wonders1_hall_or_exit(rdram, ctx);
        goto after_0;
    // 0x800459BC: nop

    after_0:
    // 0x800459C0: lhu         $t8, 0x2($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X2);
    // 0x800459C4: nop

    // 0x800459C8: slti        $at, $t8, 0x5D2
    ctx->r1 = SIGNED(ctx->r24) < 0X5D2 ? 1 : 0;
    // 0x800459CC: bne         $at, $zero, L_80045BC8
    if (ctx->r1 != 0) {
        // 0x800459D0: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80045BC8;
    }
    // 0x800459D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800459D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800459D8: jal         0x8007EFB0
    // 0x800459DC: nop

    Gfx_BeginScreenFade2(rdram, ctx);
        goto after_1;
    // 0x800459DC: nop

    after_1:
    // 0x800459E0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800459E4: b           L_80045BC8
    // 0x800459E8: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
        goto L_80045BC8;
    // 0x800459E8: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_800459EC:
    // 0x800459EC: jal         0x80044748
    // 0x800459F0: nop

    wonders1_hall_or_exit(rdram, ctx);
        goto after_2;
    // 0x800459F0: nop

    after_2:
    // 0x800459F4: jal         0x8007ED00
    // 0x800459F8: nop

    Gfx_DrawScreenFade2(rdram, ctx);
        goto after_3;
    // 0x800459F8: nop

    after_3:
    // 0x800459FC: beq         $v0, $zero, L_80045BC8
    if (ctx->r2 == 0) {
        // 0x80045A00: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_80045BC8;
    }
    // 0x80045A00: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80045A04: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80045A08: jal         0x8007F288
    // 0x80045A0C: nop

    Gfx_BeginScreenFade3(rdram, ctx);
        goto after_4;
    // 0x80045A0C: nop

    after_4:
    // 0x80045A10: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80045A14: b           L_80045BC8
    // 0x80045A18: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
        goto L_80045BC8;
    // 0x80045A18: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
L_80045A1C:
    // 0x80045A1C: jal         0x80044ED0
    // 0x80045A20: nop

    wonders1_display_complete_message(rdram, ctx);
        goto after_5;
    // 0x80045A20: nop

    after_5:
    // 0x80045A24: jal         0x8007EFE4
    // 0x80045A28: nop

    Gfx_DrawScreenFade3(rdram, ctx);
        goto after_6;
    // 0x80045A28: nop

    after_6:
    // 0x80045A2C: beq         $v0, $zero, L_80045BC8
    if (ctx->r2 == 0) {
        // 0x80045A30: nop
    
            goto L_80045BC8;
    }
    // 0x80045A30: nop

    // 0x80045A34: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80045A38: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x80045A3C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80045A40: jal         0x80046218
    // 0x80045A44: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_7;
    // 0x80045A44: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    after_7:
    // 0x80045A48: sll         $s1, $v0, 24
    ctx->r17 = S32(ctx->r2 << 24);
    // 0x80045A4C: sra         $t2, $s1, 24
    ctx->r10 = S32(SIGNED(ctx->r17) >> 24);
    // 0x80045A50: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x80045A54: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80045A58: addu        $t3, $t3, $s1
    ctx->r11 = ADD32(ctx->r11, ctx->r17);
    // 0x80045A5C: lbu         $t3, -0x4A0($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X4A0);
    // 0x80045A60: lh          $t5, 0xFA($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XFA);
    // 0x80045A64: addiu       $t4, $t3, -0x2
    ctx->r12 = ADD32(ctx->r11, -0X2);
    // 0x80045A68: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80045A6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80045A70: mflo        $t6
    ctx->r14 = lo;
    // 0x80045A74: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80045A78: b           L_80045BC8
    // 0x80045A7C: sh          $t7, 0x1F6C($at)
    MEM_H(0X1F6C, ctx->r1) = ctx->r15;
        goto L_80045BC8;
    // 0x80045A7C: sh          $t7, 0x1F6C($at)
    MEM_H(0X1F6C, ctx->r1) = ctx->r15;
L_80045A80:
    // 0x80045A80: jal         0x80044ED0
    // 0x80045A84: nop

    wonders1_display_complete_message(rdram, ctx);
        goto after_8;
    // 0x80045A84: nop

    after_8:
    // 0x80045A88: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80045A8C: lhu         $t9, 0x1F6C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X1F6C);
    // 0x80045A90: lhu         $t8, 0x2($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X2);
    // 0x80045A94: nop

    // 0x80045A98: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80045A9C: bne         $at, $zero, L_80045BC8
    if (ctx->r1 != 0) {
        // 0x80045AA0: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80045BC8;
    }
    // 0x80045AA0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80045AA4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80045AA8: jal         0x8007E9F8
    // 0x80045AAC: nop

    Gfx_BeginScreenFade0(rdram, ctx);
        goto after_9;
    // 0x80045AAC: nop

    after_9:
    // 0x80045AB0: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80045AB4: b           L_80045BC8
    // 0x80045AB8: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
        goto L_80045BC8;
    // 0x80045AB8: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
L_80045ABC:
    // 0x80045ABC: jal         0x80044ED0
    // 0x80045AC0: nop

    wonders1_display_complete_message(rdram, ctx);
        goto after_10;
    // 0x80045AC0: nop

    after_10:
    // 0x80045AC4: jal         0x8007E750
    // 0x80045AC8: nop

    Gfx_DrawScreenFade0(rdram, ctx);
        goto after_11;
    // 0x80045AC8: nop

    after_11:
    // 0x80045ACC: beq         $v0, $zero, L_80045BC8
    if (ctx->r2 == 0) {
        // 0x80045AD0: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80045BC8;
    }
    // 0x80045AD0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80045AD4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80045AD8: jal         0x8007ECC8
    // 0x80045ADC: nop

    Gfx_BeginScreenFade1(rdram, ctx);
        goto after_12;
    // 0x80045ADC: nop

    after_12:
    // 0x80045AE0: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80045AE4: b           L_80045BC8
    // 0x80045AE8: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
        goto L_80045BC8;
    // 0x80045AE8: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
L_80045AEC:
    // 0x80045AEC: jal         0x80045190
    // 0x80045AF0: nop

    wonders1_finale_or_hall(rdram, ctx);
        goto after_13;
    // 0x80045AF0: nop

    after_13:
    // 0x80045AF4: jal         0x8007EA2C
    // 0x80045AF8: nop

    Gfx_DrawScreenFade1(rdram, ctx);
        goto after_14;
    // 0x80045AF8: nop

    after_14:
    // 0x80045AFC: beq         $v0, $zero, L_80045BC8
    if (ctx->r2 == 0) {
        // 0x80045B00: nop
    
            goto L_80045BC8;
    }
    // 0x80045B00: nop

    // 0x80045B04: b           L_80045BC8
    // 0x80045B08: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_80045BC8;
    // 0x80045B08: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80045B0C:
    // 0x80045B0C: jal         0x80045190
    // 0x80045B10: nop

    wonders1_finale_or_hall(rdram, ctx);
        goto after_15;
    // 0x80045B10: nop

    after_15:
    // 0x80045B14: jal         0x8007E750
    // 0x80045B18: nop

    Gfx_DrawScreenFade0(rdram, ctx);
        goto after_16;
    // 0x80045B18: nop

    after_16:
    // 0x80045B1C: beq         $v0, $zero, L_80045BC8
    if (ctx->r2 == 0) {
        // 0x80045B20: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80045BC8;
    }
    // 0x80045B20: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80045B24: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80045B28: jal         0x8007ECC8
    // 0x80045B2C: nop

    Gfx_BeginScreenFade1(rdram, ctx);
        goto after_17;
    // 0x80045B2C: nop

    after_17:
    // 0x80045B30: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x80045B34: b           L_80045BC8
    // 0x80045B38: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
        goto L_80045BC8;
    // 0x80045B38: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
L_80045B3C:
    // 0x80045B3C: jal         0x800455BC
    // 0x80045B40: nop

    wonders1_RenderWonderStats(rdram, ctx);
        goto after_18;
    // 0x80045B40: nop

    after_18:
    // 0x80045B44: jal         0x8007EA2C
    // 0x80045B48: nop

    Gfx_DrawScreenFade1(rdram, ctx);
        goto after_19;
    // 0x80045B48: nop

    after_19:
    // 0x80045B4C: beq         $v0, $zero, L_80045BC8
    if (ctx->r2 == 0) {
        // 0x80045B50: nop
    
            goto L_80045BC8;
    }
    // 0x80045B50: nop

    // 0x80045B54: b           L_80045BC8
    // 0x80045B58: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_80045BC8;
    // 0x80045B58: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80045B5C:
    // 0x80045B5C: lb          $t3, 0x1($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1);
    // 0x80045B60: nop

    // 0x80045B64: slti        $at, $t3, 0x31
    ctx->r1 = SIGNED(ctx->r11) < 0X31 ? 1 : 0;
    // 0x80045B68: bne         $at, $zero, L_80045B80
    if (ctx->r1 != 0) {
        // 0x80045B6C: nop
    
            goto L_80045B80;
    }
    // 0x80045B6C: nop

    // 0x80045B70: jal         0x800455BC
    // 0x80045B74: nop

    wonders1_RenderWonderStats(rdram, ctx);
        goto after_20;
    // 0x80045B74: nop

    after_20:
    // 0x80045B78: b           L_80045BC8
    // 0x80045B7C: nop

        goto L_80045BC8;
    // 0x80045B7C: nop

L_80045B80:
    // 0x80045B80: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80045B84: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80045B88: lb          $t5, -0x7C8($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X7C8);
    // 0x80045B8C: lb          $t4, -0x7C4($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X7C4);
    // 0x80045B90: nop

    // 0x80045B94: bne         $t4, $t5, L_80045BC0
    if (ctx->r12 != ctx->r13) {
        // 0x80045B98: nop
    
            goto L_80045BC0;
    }
    // 0x80045B98: nop

    // 0x80045B9C: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x80045BA0: jal         0x8004619C
    // 0x80045BA4: nop

    wonders2_IsLastColumnOfWonder(rdram, ctx);
        goto after_21;
    // 0x80045BA4: nop

    after_21:
    // 0x80045BA8: beq         $v0, $zero, L_80045BC0
    if (ctx->r2 == 0) {
        // 0x80045BAC: nop
    
            goto L_80045BC0;
    }
    // 0x80045BAC: nop

    // 0x80045BB0: jal         0x80045190
    // 0x80045BB4: nop

    wonders1_finale_or_hall(rdram, ctx);
        goto after_22;
    // 0x80045BB4: nop

    after_22:
    // 0x80045BB8: b           L_80045BC8
    // 0x80045BBC: nop

        goto L_80045BC8;
    // 0x80045BBC: nop

L_80045BC0:
    // 0x80045BC0: jal         0x80044748
    // 0x80045BC4: nop

    wonders1_hall_or_exit(rdram, ctx);
        goto after_23;
    // 0x80045BC4: nop

    after_23:
L_80045BC8:
    // 0x80045BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80045BCC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80045BD0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80045BD4: jr          $ra
    // 0x80045BD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80045BD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders1_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045BDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80045BE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80045BE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80045BE8: jal         0x8004A34C
    // 0x80045BEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    Main_DrainMessageQueue(rdram, ctx);
        goto after_0;
    // 0x80045BEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80045BF0: jal         0x8007E03C
    // 0x80045BF4: addiu       $a0, $zero, 0xFC
    ctx->r4 = ADD32(0, 0XFC);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80045BF4: addiu       $a0, $zero, 0xFC
    ctx->r4 = ADD32(0, 0XFC);
    after_1:
    // 0x80045BF8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80045BFC: sw          $v0, 0x5E10($at)
    MEM_W(0X5E10, ctx->r1) = ctx->r2;
    // 0x80045C00: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80045C04: lw          $s0, 0x5E10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5E10);
    // 0x80045C08: nop

    // 0x80045C0C: bne         $s0, $zero, L_80045C28
    if (ctx->r16 != 0) {
        // 0x80045C10: nop
    
            goto L_80045C28;
    }
    // 0x80045C10: nop

    // 0x80045C14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80045C18: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80045C1C: addiu       $a1, $a1, -0x4AB8
    ctx->r5 = ADD32(ctx->r5, -0X4AB8);
    // 0x80045C20: jal         0x80083560
    // 0x80045C24: addiu       $a0, $a0, -0x4ACC
    ctx->r4 = ADD32(ctx->r4, -0X4ACC);
    debug_print_reason_routine(rdram, ctx);
        goto after_2;
    // 0x80045C24: addiu       $a0, $a0, -0x4ACC
    ctx->r4 = ADD32(ctx->r4, -0X4ACC);
    after_2:
L_80045C28:
    // 0x80045C28: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80045C2C: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x80045C30: jal         0x80077408
    // 0x80045C34: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    Font_Init46Char(rdram, ctx);
        goto after_3;
    // 0x80045C34: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80045C38: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x80045C3C: jal         0x80077408
    // 0x80045C40: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    Font_Init46Char(rdram, ctx);
        goto after_4;
    // 0x80045C40: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x80045C44: lb          $t6, 0x2B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X2B);
    // 0x80045C48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80045C4C: bne         $t6, $at, L_80045C64
    if (ctx->r14 != ctx->r1) {
        // 0x80045C50: nop
    
            goto L_80045C64;
    }
    // 0x80045C50: nop

    // 0x80045C54: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x80045C58: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x80045C5C: b           L_80045C78
    // 0x80045C60: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
        goto L_80045C78;
    // 0x80045C60: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_80045C64:
    // 0x80045C64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80045C68: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x80045C6C: lb          $t9, 0x2B($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X2B);
    // 0x80045C70: nop

    // 0x80045C74: sb          $t9, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r25;
L_80045C78:
    // 0x80045C78: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80045C7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80045C80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80045C84: sb          $t0, 0x1F6E($at)
    MEM_B(0X1F6E, ctx->r1) = ctx->r8;
    // 0x80045C88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80045C8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80045C90: sb          $zero, 0x1F6F($at)
    MEM_B(0X1F6F, ctx->r1) = 0;
    // 0x80045C94: jr          $ra
    // 0x80045C98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80045C98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders1_Exit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045C9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80045CA0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80045CA4: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80045CA8: lw          $s0, 0x5E10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5E10);
    // 0x80045CAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80045CB0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80045CB4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80045CB8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80045CBC: jal         0x800773D0
    // 0x80045CC0: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    Font_Deinit(rdram, ctx);
        goto after_0;
    // 0x80045CC0: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_0:
    // 0x80045CC4: jal         0x800773D0
    // 0x80045CC8: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    Font_Deinit(rdram, ctx);
        goto after_1;
    // 0x80045CC8: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    after_1:
    // 0x80045CCC: jal         0x80044218
    // 0x80045CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders1_FreeColumnTiles(rdram, ctx);
        goto after_2;
    // 0x80045CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80045CD4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80045CD8: lbu         $s1, 0x0($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X0);
    // 0x80045CDC: lbu         $s2, 0x1($s0)
    ctx->r18 = MEM_BU(ctx->r16, 0X1);
    // 0x80045CE0: lw          $a0, 0x5E10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5E10);
    // 0x80045CE4: jal         0x8007E328
    // 0x80045CE8: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_3;
    // 0x80045CE8: nop

    after_3:
    // 0x80045CEC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80045CF0: jal         0x8004A34C
    // 0x80045CF4: sw          $zero, 0x5E10($at)
    MEM_W(0X5E10, ctx->r1) = 0;
    Main_DrainMessageQueue(rdram, ctx);
        goto after_4;
    // 0x80045CF4: sw          $zero, 0x5E10($at)
    MEM_W(0X5E10, ctx->r1) = 0;
    after_4:
    // 0x80045CF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045CFC: sb          $zero, 0x3CF0($at)
    MEM_B(0X3CF0, ctx->r1) = 0;
    // 0x80045D00: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80045D04: bne         $s1, $at, L_80045D44
    if (ctx->r17 != ctx->r1) {
        // 0x80045D08: nop
    
            goto L_80045D44;
    }
    // 0x80045D08: nop

    // 0x80045D0C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80045D10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045D14: sb          $t6, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r14;
    // 0x80045D18: jal         0x80046218
    // 0x80045D1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_5;
    // 0x80045D1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80045D20: sll         $s3, $v0, 24
    ctx->r19 = S32(ctx->r2 << 24);
    // 0x80045D24: sra         $t7, $s3, 24
    ctx->r15 = S32(SIGNED(ctx->r19) >> 24);
    // 0x80045D28: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
    // 0x80045D2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80045D30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80045D34: jal         0x800472F0
    // 0x80045D38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    wonders3_LoadWonderViewer(rdram, ctx);
        goto after_6;
    // 0x80045D38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80045D3C: b           L_80045E28
    // 0x80045D40: nop

        goto L_80045E28;
    // 0x80045D40: nop

L_80045D44:
    // 0x80045D44: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80045D48: lbu         $t8, 0x9F0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X9F0);
    // 0x80045D4C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80045D50: bne         $t8, $at, L_80045D88
    if (ctx->r24 != ctx->r1) {
        // 0x80045D54: nop
    
            goto L_80045D88;
    }
    // 0x80045D54: nop

    // 0x80045D58: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80045D5C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80045D60: addiu       $a1, $a1, 0x5808
    ctx->r5 = ADD32(ctx->r5, 0X5808);
    // 0x80045D64: jal         0x8009035C
    // 0x80045D68: addiu       $a0, $a0, 0x5850
    ctx->r4 = ADD32(ctx->r4, 0X5850);
    Scene_LoadScreen(rdram, ctx);
        goto after_7;
    // 0x80045D68: addiu       $a0, $a0, 0x5850
    ctx->r4 = ADD32(ctx->r4, 0X5850);
    after_7:
    // 0x80045D6C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80045D70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045D74: sb          $t9, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r25;
    // 0x80045D78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045D7C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80045D80: b           L_80045E28
    // 0x80045D84: sb          $t0, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r8;
        goto L_80045E28;
    // 0x80045D84: sb          $t0, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r8;
L_80045D88:
    // 0x80045D88: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80045D8C: lbu         $t1, 0x9F0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X9F0);
    // 0x80045D90: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80045D94: bne         $t1, $at, L_80045DCC
    if (ctx->r9 != ctx->r1) {
        // 0x80045D98: nop
    
            goto L_80045DCC;
    }
    // 0x80045D98: nop

    // 0x80045D9C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80045DA0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80045DA4: addiu       $a1, $a1, 0x5CE8
    ctx->r5 = ADD32(ctx->r5, 0X5CE8);
    // 0x80045DA8: jal         0x8009035C
    // 0x80045DAC: addiu       $a0, $a0, 0x5D48
    ctx->r4 = ADD32(ctx->r4, 0X5D48);
    Scene_LoadScreen(rdram, ctx);
        goto after_8;
    // 0x80045DAC: addiu       $a0, $a0, 0x5D48
    ctx->r4 = ADD32(ctx->r4, 0X5D48);
    after_8:
    // 0x80045DB0: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80045DB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045DB8: sb          $t2, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r10;
    // 0x80045DBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045DC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80045DC4: b           L_80045E28
    // 0x80045DC8: sb          $t3, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r11;
        goto L_80045E28;
    // 0x80045DC8: sb          $t3, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r11;
L_80045DCC:
    // 0x80045DCC: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x80045DD0: lbu         $t4, 0x9F0($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X9F0);
    // 0x80045DD4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80045DD8: bne         $t4, $at, L_80045E04
    if (ctx->r12 != ctx->r1) {
        // 0x80045DDC: nop
    
            goto L_80045E04;
    }
    // 0x80045DDC: nop

    // 0x80045DE0: jal         0x800905E8
    // 0x80045DE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Scene_LoadResources(rdram, ctx);
        goto after_9;
    // 0x80045DE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x80045DE8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80045DEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045DF0: sb          $t5, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r13;
    // 0x80045DF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045DF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80045DFC: b           L_80045E28
    // 0x80045E00: sb          $t6, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r14;
        goto L_80045E28;
    // 0x80045E00: sb          $t6, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r14;
L_80045E04:
    // 0x80045E04: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80045E08: jal         0x80051618
    // 0x80045E0C: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    Game_StartRound(rdram, ctx);
        goto after_10;
    // 0x80045E0C: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    after_10:
    // 0x80045E10: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x80045E14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045E18: sb          $t7, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r15;
    // 0x80045E1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045E20: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80045E24: sb          $t8, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r24;
L_80045E28:
    // 0x80045E28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80045E2C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80045E30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80045E34: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80045E38: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80045E3C: jr          $ra
    // 0x80045E40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80045E40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80045E44: nop

    // 0x80045E48: nop

    // 0x80045E4C: nop

;}

RECOMP_FUNC void wonders1_ObjSetFlag40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4620: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4624: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x800A4628: jr          $ra
    // 0x800A462C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A462C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void wonders1_ObjClearFlag40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4630: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4634: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800A4638: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800A463C: jr          $ra
    // 0x800A4640: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A4640: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void wonders1_ObjSetFlag80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4644: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4648: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x800A464C: jr          $ra
    // 0x800A4650: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A4650: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void wonders1_ObjClearFlag80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4654: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4658: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800A465C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800A4660: jr          $ra
    // 0x800A4664: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A4664: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void wonders1_ObjSetFlag200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4668: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A466C: ori         $t7, $t6, 0x200
    ctx->r15 = ctx->r14 | 0X200;
    // 0x800A4670: jr          $ra
    // 0x800A4674: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A4674: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void wonders1_ObjClearFlag200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4678: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A467C: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800A4680: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800A4684: jr          $ra
    // 0x800A4688: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A4688: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void wonders1_ObjSetByte4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A468C: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x800A4690: jr          $ra
    // 0x800A4694: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
    return;
    // 0x800A4694: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
;}

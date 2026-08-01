#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void displayText_XY_RGBA_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077818: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007781C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80077820: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80077824: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80077828: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8007782C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80077830: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80077834: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80077838: nop

    // 0x8007783C: beq         $t7, $zero, L_80077950
    if (ctx->r15 == 0) {
        // 0x80077840: nop
    
            goto L_80077950;
    }
    // 0x80077840: nop

    // 0x80077844: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80077848: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8007784C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80077850: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80077854: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80077858: nop

    // 0x8007785C: beq         $t0, $zero, L_80077950
    if (ctx->r8 == 0) {
        // 0x80077860: nop
    
            goto L_80077950;
    }
    // 0x80077860: nop

L_80077864:
    // 0x80077864: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80077868: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8007786C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80077870: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80077874: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80077878: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007787C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80077880: lbu         $t6, 0x2D10($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2D10);
    // 0x80077884: lh          $t7, 0x76($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X76);
    // 0x80077888: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x8007788C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077890: addu        $t0, $t1, $t9
    ctx->r8 = ADD32(ctx->r9, ctx->r25);
    // 0x80077894: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x80077898: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8007789C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800778A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800778A4: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800778A8: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800778AC: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800778B0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800778B4: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800778B8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800778BC: mflo        $t8
    ctx->r24 = lo;
    // 0x800778C0: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x800778C4: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800778C8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800778CC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800778D0: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800778D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800778D8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x800778DC: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800778E0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800778E4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800778E8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800778EC: jal         0x80059048
    // 0x800778F0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    display_one_text_character_rgb(rdram, ctx);
        goto after_0;
    // 0x800778F0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x800778F4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800778F8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800778FC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80077900: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x80077904: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80077908: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8007790C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80077910: lbu         $t6, 0x2D10($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2D10);
    // 0x80077914: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x80077918: sll         $t1, $t6, 1
    ctx->r9 = S32(ctx->r14 << 1);
    // 0x8007791C: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x80077920: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x80077924: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80077928: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8007792C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80077930: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80077934: addu        $t8, $t3, $t2
    ctx->r24 = ADD32(ctx->r11, ctx->r10);
    // 0x80077938: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8007793C: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80077940: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x80077944: nop

    // 0x80077948: bne         $t1, $zero, L_80077864
    if (ctx->r9 != 0) {
        // 0x8007794C: nop
    
            goto L_80077864;
    }
    // 0x8007794C: nop

L_80077950:
    // 0x80077950: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80077954: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80077958: jr          $ra
    // 0x8007795C: nop

    return;
    // 0x8007795C: nop

;}

RECOMP_FUNC void displayText_XY_RGBA_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077960: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80077964: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80077968: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8007796C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80077970: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80077974: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80077978: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8007797C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80077980: nop

    // 0x80077984: beq         $t7, $zero, L_80077A98
    if (ctx->r15 == 0) {
        // 0x80077988: nop
    
            goto L_80077A98;
    }
    // 0x80077988: nop

    // 0x8007798C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80077990: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80077994: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80077998: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8007799C: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x800779A0: nop

    // 0x800779A4: beq         $t0, $zero, L_80077A98
    if (ctx->r8 == 0) {
        // 0x800779A8: nop
    
            goto L_80077A98;
    }
    // 0x800779A8: nop

L_800779AC:
    // 0x800779AC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800779B0: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800779B4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800779B8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800779BC: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800779C0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800779C4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800779C8: lbu         $t6, 0x2CD0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2CD0);
    // 0x800779CC: lh          $t7, 0x76($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X76);
    // 0x800779D0: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800779D4: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800779D8: addu        $t0, $t1, $t9
    ctx->r8 = ADD32(ctx->r9, ctx->r25);
    // 0x800779DC: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x800779E0: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800779E4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800779E8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800779EC: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800779F0: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800779F4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800779F8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800779FC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80077A00: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80077A04: mflo        $t8
    ctx->r24 = lo;
    // 0x80077A08: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x80077A0C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80077A10: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80077A14: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80077A18: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80077A1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80077A20: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80077A24: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80077A28: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80077A2C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80077A30: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80077A34: jal         0x80059048
    // 0x80077A38: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    display_one_text_character_rgb(rdram, ctx);
        goto after_0;
    // 0x80077A38: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80077A3C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80077A40: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80077A44: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80077A48: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x80077A4C: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80077A50: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80077A54: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80077A58: lbu         $t6, 0x2CD0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2CD0);
    // 0x80077A5C: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x80077A60: sll         $t1, $t6, 1
    ctx->r9 = S32(ctx->r14 << 1);
    // 0x80077A64: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x80077A68: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x80077A6C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80077A70: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x80077A74: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80077A78: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80077A7C: addu        $t8, $t3, $t2
    ctx->r24 = ADD32(ctx->r11, ctx->r10);
    // 0x80077A80: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80077A84: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80077A88: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x80077A8C: nop

    // 0x80077A90: bne         $t1, $zero, L_800779AC
    if (ctx->r9 != 0) {
        // 0x80077A94: nop
    
            goto L_800779AC;
    }
    // 0x80077A94: nop

L_80077A98:
    // 0x80077A98: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80077A9C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80077AA0: jr          $ra
    // 0x80077AA4: nop

    return;
    // 0x80077AA4: nop

;}

RECOMP_FUNC void displayText_XY_RGBA_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077AA8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80077AAC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80077AB0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80077AB4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80077AB8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80077ABC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80077AC0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80077AC4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80077AC8: nop

    // 0x80077ACC: bne         $t7, $zero, L_80077ADC
    if (ctx->r15 != 0) {
        // 0x80077AD0: nop
    
            goto L_80077ADC;
    }
    // 0x80077AD0: nop

    // 0x80077AD4: b           L_80077B98
    // 0x80077AD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077B98;
    // 0x80077AD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077ADC:
    // 0x80077ADC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80077AE0: lbu         $t0, 0x53($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X53);
    // 0x80077AE4: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80077AE8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80077AEC: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80077AF0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80077AF4: lbu         $t1, 0x2CD0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2CD0);
    // 0x80077AF8: lh          $t2, 0x76($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X76);
    // 0x80077AFC: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x80077B00: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077B04: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x80077B08: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x80077B0C: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80077B10: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80077B14: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80077B18: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80077B1C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80077B20: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80077B24: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80077B28: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80077B2C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80077B30: mflo        $t3
    ctx->r11 = lo;
    // 0x80077B34: addu        $t0, $t3, $t2
    ctx->r8 = ADD32(ctx->r11, ctx->r10);
    // 0x80077B38: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80077B3C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80077B40: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x80077B44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80077B48: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80077B4C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80077B50: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80077B54: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80077B58: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80077B5C: jal         0x80059048
    // 0x80077B60: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    display_one_text_character_rgb(rdram, ctx);
        goto after_0;
    // 0x80077B60: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_0:
    // 0x80077B64: lbu         $t2, 0x53($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X53);
    // 0x80077B68: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80077B6C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80077B70: lbu         $t0, 0x2CD0($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X2CD0);
    // 0x80077B74: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80077B78: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80077B7C: addu        $t8, $t3, $t1
    ctx->r24 = ADD32(ctx->r11, ctx->r9);
    // 0x80077B80: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x80077B84: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80077B88: nop

    // 0x80077B8C: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x80077B90: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x80077B94: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80077B98:
    // 0x80077B98: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80077B9C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80077BA0: jr          $ra
    // 0x80077BA4: nop

    return;
    // 0x80077BA4: nop

;}

RECOMP_FUNC void displayText_XY_RGBA_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077BA8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80077BAC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80077BB0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80077BB4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80077BB8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80077BBC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80077BC0: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80077BC4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80077BC8: nop

    // 0x80077BCC: beq         $t7, $zero, L_80077D28
    if (ctx->r15 == 0) {
        // 0x80077BD0: nop
    
            goto L_80077D28;
    }
    // 0x80077BD0: nop

    // 0x80077BD4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80077BD8: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80077BDC: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80077BE0: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80077BE4: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80077BE8: nop

    // 0x80077BEC: beq         $t0, $zero, L_80077D28
    if (ctx->r8 == 0) {
        // 0x80077BF0: nop
    
            goto L_80077D28;
    }
    // 0x80077BF0: nop

L_80077BF4:
    // 0x80077BF4: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80077BF8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80077BFC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80077C00: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80077C04: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80077C08: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80077C0C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80077C10: lbu         $t6, 0x2CD0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2CD0);
    // 0x80077C14: lh          $t7, 0x76($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X76);
    // 0x80077C18: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80077C1C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077C20: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x80077C24: addu        $t0, $t1, $t9
    ctx->r8 = ADD32(ctx->r9, ctx->r25);
    // 0x80077C28: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80077C2C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80077C30: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80077C34: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80077C38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80077C3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80077C40: mflo        $t8
    ctx->r24 = lo;
    // 0x80077C44: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80077C48: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x80077C4C: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x80077C50: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80077C54: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80077C58: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80077C5C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80077C60: lh          $t7, 0x76($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X76);
    // 0x80077C64: lh          $t8, 0x76($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X76);
    // 0x80077C68: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80077C6C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80077C70: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80077C74: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80077C78: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80077C7C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80077C80: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80077C84: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80077C88: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80077C8C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80077C90: jal         0x8005AA9C
    // 0x80077C94: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    FUN_8005aa9c_prob_display_text_rgb_as_well(rdram, ctx);
        goto after_0;
    // 0x80077C94: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_0:
    // 0x80077C98: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80077C9C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80077CA0: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80077CA4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80077CA8: lbu         $t1, 0x0($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X0);
    // 0x80077CAC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80077CB0: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x80077CB4: lbu         $t9, 0x2CD0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X2CD0);
    // 0x80077CB8: lh          $t4, 0x76($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X76);
    // 0x80077CBC: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80077CC0: addu        $t3, $t2, $t0
    ctx->r11 = ADD32(ctx->r10, ctx->r8);
    // 0x80077CC4: lh          $t8, 0x4($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X4);
    // 0x80077CC8: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x80077CCC: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80077CD0: div         $zero, $t7, $t4
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r12)));
    // 0x80077CD4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80077CD8: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x80077CDC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80077CE0: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80077CE4: bne         $t4, $zero, L_80077CF0
    if (ctx->r12 != 0) {
        // 0x80077CE8: nop
    
            goto L_80077CF0;
    }
    // 0x80077CE8: nop

    // 0x80077CEC: break       7
    do_break(2147974380);
L_80077CF0:
    // 0x80077CF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80077CF4: bne         $t4, $at, L_80077D08
    if (ctx->r12 != ctx->r1) {
        // 0x80077CF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80077D08;
    }
    // 0x80077CF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80077CFC: bne         $t7, $at, L_80077D08
    if (ctx->r15 != ctx->r1) {
        // 0x80077D00: nop
    
            goto L_80077D08;
    }
    // 0x80077D00: nop

    // 0x80077D04: break       6
    do_break(2147974404);
L_80077D08:
    // 0x80077D08: addu        $t8, $t0, $t3
    ctx->r24 = ADD32(ctx->r8, ctx->r11);
    // 0x80077D0C: mflo        $t6
    ctx->r14 = lo;
    // 0x80077D10: addu        $t9, $t1, $t6
    ctx->r25 = ADD32(ctx->r9, ctx->r14);
    // 0x80077D14: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x80077D18: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x80077D1C: nop

    // 0x80077D20: bne         $t7, $zero, L_80077BF4
    if (ctx->r15 != 0) {
        // 0x80077D24: nop
    
            goto L_80077BF4;
    }
    // 0x80077D24: nop

L_80077D28:
    // 0x80077D28: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80077D2C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80077D30: jr          $ra
    // 0x80077D34: nop

    return;
    // 0x80077D34: nop

;}

RECOMP_FUNC void displayText_DrawString(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077EE0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80077EE4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80077EE8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80077EEC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80077EF0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80077EF4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80077EF8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80077EFC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80077F00: nop

    // 0x80077F04: beq         $t7, $zero, L_8007801C
    if (ctx->r15 == 0) {
        // 0x80077F08: nop
    
            goto L_8007801C;
    }
    // 0x80077F08: nop

    // 0x80077F0C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80077F10: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80077F14: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80077F18: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80077F1C: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80077F20: nop

    // 0x80077F24: beq         $t0, $zero, L_8007801C
    if (ctx->r8 == 0) {
        // 0x80077F28: nop
    
            goto L_8007801C;
    }
    // 0x80077F28: nop

L_80077F2C:
    // 0x80077F2C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80077F30: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80077F34: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80077F38: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80077F3C: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80077F40: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80077F44: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80077F48: lbu         $t6, 0x2CD0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2CD0);
    // 0x80077F4C: lh          $t7, 0x76($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X76);
    // 0x80077F50: sll         $t0, $t6, 1
    ctx->r8 = S32(ctx->r14 << 1);
    // 0x80077F54: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077F58: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80077F5C: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x80077F60: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80077F64: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80077F68: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x80077F6C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80077F70: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80077F74: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80077F78: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80077F7C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80077F80: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80077F84: mflo        $t8
    ctx->r24 = lo;
    // 0x80077F88: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x80077F8C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80077F90: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80077F94: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x80077F98: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80077F9C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80077FA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80077FA4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80077FA8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80077FAC: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80077FB0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80077FB4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80077FB8: jal         0x80059048
    // 0x80077FBC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    display_one_text_character_rgb(rdram, ctx);
        goto after_0;
    // 0x80077FBC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_0:
    // 0x80077FC0: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80077FC4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80077FC8: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80077FCC: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    // 0x80077FD0: lbu         $t7, 0x0($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X0);
    // 0x80077FD4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80077FD8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80077FDC: lbu         $t9, 0x2CD0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X2CD0);
    // 0x80077FE0: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x80077FE4: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80077FE8: addu        $t0, $t1, $t6
    ctx->r8 = ADD32(ctx->r9, ctx->r14);
    // 0x80077FEC: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x80077FF0: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80077FF4: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80077FF8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80077FFC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80078000: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x80078004: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x80078008: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x8007800C: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x80078010: nop

    // 0x80078014: bne         $t6, $zero, L_80077F2C
    if (ctx->r14 != 0) {
        // 0x80078018: nop
    
            goto L_80077F2C;
    }
    // 0x80078018: nop

L_8007801C:
    // 0x8007801C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80078020: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80078024: jr          $ra
    // 0x80078028: nop

    return;
    // 0x80078028: nop

;}

RECOMP_FUNC void displayText_DrawChar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078094: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80078098: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8007809C: lbu         $t6, 0x3F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3F);
    // 0x800780A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800780A4: slti        $at, $t6, 0x61
    ctx->r1 = SIGNED(ctx->r14) < 0X61 ? 1 : 0;
    // 0x800780A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800780AC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800780B0: bne         $at, $zero, L_800780CC
    if (ctx->r1 != 0) {
        // 0x800780B4: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_800780CC;
    }
    // 0x800780B4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800780B8: slti        $at, $t6, 0x7B
    ctx->r1 = SIGNED(ctx->r14) < 0X7B ? 1 : 0;
    // 0x800780BC: beq         $at, $zero, L_800780CC
    if (ctx->r1 == 0) {
        // 0x800780C0: nop
    
            goto L_800780CC;
    }
    // 0x800780C0: nop

    // 0x800780C4: addiu       $t7, $t6, -0x20
    ctx->r15 = ADD32(ctx->r14, -0X20);
    // 0x800780C8: sb          $t7, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r15;
L_800780CC:
    // 0x800780CC: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x800780D0: nop

    // 0x800780D4: slti        $at, $t8, 0x20
    ctx->r1 = SIGNED(ctx->r24) < 0X20 ? 1 : 0;
    // 0x800780D8: bne         $at, $zero, L_80078198
    if (ctx->r1 != 0) {
        // 0x800780DC: slti        $at, $t8, 0x60
        ctx->r1 = SIGNED(ctx->r24) < 0X60 ? 1 : 0;
            goto L_80078198;
    }
    // 0x800780DC: slti        $at, $t8, 0x60
    ctx->r1 = SIGNED(ctx->r24) < 0X60 ? 1 : 0;
    // 0x800780E0: beq         $at, $zero, L_80078198
    if (ctx->r1 == 0) {
        // 0x800780E4: nop
    
            goto L_80078198;
    }
    // 0x800780E4: nop

    // 0x800780E8: lbu         $t9, 0x3F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3F);
    // 0x800780EC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800780F0: addiu       $t0, $t9, -0x20
    ctx->r8 = ADD32(ctx->r25, -0X20);
    // 0x800780F4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800780F8: sb          $t0, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r8;
    // 0x800780FC: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x80078100: addiu       $t3, $t3, 0x2CF0
    ctx->r11 = ADD32(ctx->r11, 0X2CF0);
    // 0x80078104: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80078108: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8007810C: lh          $t6, 0x76($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X76);
    // 0x80078110: andi        $t7, $t0, 0xFF
    ctx->r15 = ctx->r8 & 0XFF;
    // 0x80078114: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80078118: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x8007811C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80078120: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x80078124: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x80078128: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8007812C: lh          $t5, 0x4($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X4);
    // 0x80078130: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80078134: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x80078138: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8007813C: addu        $t9, $t8, $t3
    ctx->r25 = ADD32(ctx->r24, ctx->r11);
    // 0x80078140: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x80078144: mflo        $a3
    ctx->r7 = lo;
    // 0x80078148: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8007814C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80078150: multu       $t1, $t6
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80078154: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80078158: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8007815C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80078160: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80078164: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80078168: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007816C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80078170: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80078174: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80078178: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8007817C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80078180: mflo        $t2
    ctx->r10 = lo;
    // 0x80078184: addu        $t4, $t2, $t6
    ctx->r12 = ADD32(ctx->r10, ctx->r14);
    // 0x80078188: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8007818C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80078190: jal         0x80059048
    // 0x80078194: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    display_one_text_character_rgb(rdram, ctx);
        goto after_0;
    // 0x80078194: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
L_80078198:
    // 0x80078198: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8007819C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800781A0: jr          $ra
    // 0x800781A4: nop

    return;
    // 0x800781A4: nop

;}

RECOMP_FUNC void displayText_DrawStringN(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078244: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80078248: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8007824C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80078250: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80078254: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80078258: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8007825C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80078260: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80078264: blez        $t6, L_800782EC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80078268: sw          $s0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r16;
            goto L_800782EC;
    }
    // 0x80078268: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
L_8007826C:
    // 0x8007826C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80078270: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80078274: lbu         $s0, 0x0($t7)
    ctx->r16 = MEM_BU(ctx->r15, 0X0);
    // 0x80078278: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8007827C: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80078280: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80078284: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80078288: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8007828C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80078290: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80078294: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80078298: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8007829C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800782A0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800782A4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800782A8: jal         0x80078094
    // 0x800782AC: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    displayText_DrawChar(rdram, ctx);
        goto after_0;
    // 0x800782AC: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_0:
    // 0x800782B0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800782B4: jal         0x8007802C
    // 0x800782B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Font_GetCharWidthUpper(rdram, ctx);
        goto after_1;
    // 0x800782B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800782BC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800782C0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800782C4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800782C8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800782CC: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x800782D0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800782D4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800782D8: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800782DC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800782E0: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x800782E4: bgtz        $t9, L_8007826C
    if (SIGNED(ctx->r25) > 0) {
        // 0x800782E8: sw          $t6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r14;
            goto L_8007826C;
    }
    // 0x800782E8: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_800782EC:
    // 0x800782EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800782F0: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800782F4: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800782F8: jr          $ra
    // 0x800782FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800782FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void displayText_ComputeBarLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078300: lhu         $t6, 0xC0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC0);
    // 0x80078304: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80078308: beq         $t6, $zero, L_80078418
    if (ctx->r14 == 0) {
        // 0x8007830C: nop
    
            goto L_80078418;
    }
    // 0x8007830C: nop

    // 0x80078310: lhu         $t7, 0xC0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XC0);
    // 0x80078314: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80078318: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x8007831C: mflo        $t8
    ctx->r24 = lo;
    // 0x80078320: beq         $t8, $zero, L_80078418
    if (ctx->r24 == 0) {
        // 0x80078324: nop
    
            goto L_80078418;
    }
    // 0x80078324: nop

    // 0x80078328: lhu         $t9, 0xC0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0XC0);
    // 0x8007832C: nop

    // 0x80078330: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80078334: bgez        $t9, L_8007834C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80078338: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8007834C;
    }
    // 0x80078338: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007833C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80078340: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80078344: nop

    // 0x80078348: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8007834C:
    // 0x8007834C: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x80078350: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80078354: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80078358: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8007835C: nop

    // 0x80078360: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x80078364: lhu         $t0, 0xC2($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0XC2);
    // 0x80078368: nop

    // 0x8007836C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80078370: nop

    // 0x80078374: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80078378: bgez        $t0, L_80078390
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007837C: cvt.s.d     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
            goto L_80078390;
    }
    // 0x8007837C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80078380: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80078384: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80078388: nop

    // 0x8007838C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80078390:
    // 0x80078390: nop

    // 0x80078394: div.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80078398: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x8007839C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800783A0: nop

    // 0x800783A4: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800783A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800783AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800783B0: nop

    // 0x800783B4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800783B8: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800783BC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800783C0: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x800783C4: nop

L_800783C8:
    // 0x800783C8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800783CC: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800783D0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800783D4: lbu         $t5, 0x2DFC($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X2DFC);
    // 0x800783D8: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x800783DC: nop

    // 0x800783E0: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800783E4: beq         $at, $zero, L_800783F8
    if (ctx->r1 == 0) {
        // 0x800783E8: nop
    
            goto L_800783F8;
    }
    // 0x800783E8: nop

    // 0x800783EC: lbu         $v0, 0x7($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X7);
    // 0x800783F0: b           L_8007841C
    // 0x800783F4: nop

        goto L_8007841C;
    // 0x800783F4: nop

L_800783F8:
    // 0x800783F8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800783FC: nop

    // 0x80078400: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80078404: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x80078408: bne         $at, $zero, L_800783C8
    if (ctx->r1 != 0) {
        // 0x8007840C: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800783C8;
    }
    // 0x8007840C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80078410: b           L_8007841C
    // 0x80078414: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
        goto L_8007841C;
    // 0x80078414: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_80078418:
    // 0x80078418: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007841C:
    // 0x8007841C: jr          $ra
    // 0x80078420: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80078420: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void displayText_ValueToBarLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078424: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80078428: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007842C: beq         $a0, $zero, L_80078528
    if (ctx->r4 == 0) {
        // 0x80078430: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_80078528;
    }
    // 0x80078430: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80078434: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80078438: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x8007843C: mflo        $t6
    ctx->r14 = lo;
    // 0x80078440: beq         $t6, $zero, L_80078528
    if (ctx->r14 == 0) {
        // 0x80078444: nop
    
            goto L_80078528;
    }
    // 0x80078444: nop

    // 0x80078448: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8007844C: bgez        $a0, L_80078464
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80078450: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80078464;
    }
    // 0x80078450: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80078454: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80078458: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007845C: nop

    // 0x80078460: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80078464:
    // 0x80078464: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x80078468: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007846C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80078470: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80078474: nop

    // 0x80078478: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8007847C: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x80078480: nop

    // 0x80078484: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80078488: bgez        $a1, L_800784A0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8007848C: cvt.s.d     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
            goto L_800784A0;
    }
    // 0x8007848C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80078490: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80078494: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80078498: nop

    // 0x8007849C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800784A0:
    // 0x800784A0: nop

    // 0x800784A4: div.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800784A8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800784AC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800784B0: nop

    // 0x800784B4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800784B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800784BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800784C0: nop

    // 0x800784C4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800784C8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800784CC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800784D0: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x800784D4: nop

L_800784D8:
    // 0x800784D8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800784DC: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800784E0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800784E4: lbu         $t1, 0x2DFC($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2DFC);
    // 0x800784E8: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800784EC: nop

    // 0x800784F0: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800784F4: beq         $at, $zero, L_80078508
    if (ctx->r1 == 0) {
        // 0x800784F8: nop
    
            goto L_80078508;
    }
    // 0x800784F8: nop

    // 0x800784FC: lbu         $v0, 0x7($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X7);
    // 0x80078500: b           L_8007852C
    // 0x80078504: nop

        goto L_8007852C;
    // 0x80078504: nop

L_80078508:
    // 0x80078508: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8007850C: nop

    // 0x80078510: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80078514: slti        $at, $t3, 0x1E
    ctx->r1 = SIGNED(ctx->r11) < 0X1E ? 1 : 0;
    // 0x80078518: bne         $at, $zero, L_800784D8
    if (ctx->r1 != 0) {
        // 0x8007851C: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_800784D8;
    }
    // 0x8007851C: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x80078520: b           L_8007852C
    // 0x80078524: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
        goto L_8007852C;
    // 0x80078524: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_80078528:
    // 0x80078528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007852C:
    // 0x8007852C: jr          $ra
    // 0x80078530: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80078530: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void displayText_RemoveEntriesByType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078534: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80078538: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007853C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80078540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078544: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80078548: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_8007854C:
    // 0x8007854C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80078550: nop

    // 0x80078554: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80078558: nop

    // 0x8007855C: beq         $t8, $zero, L_800785AC
    if (ctx->r24 == 0) {
        // 0x80078560: nop
    
            goto L_800785AC;
    }
    // 0x80078560: nop

    // 0x80078564: lbu         $t9, 0xD4($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XD4);
    // 0x80078568: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x8007856C: nop

    // 0x80078570: bne         $t9, $t0, L_800785AC
    if (ctx->r25 != ctx->r8) {
        // 0x80078574: nop
    
            goto L_800785AC;
    }
    // 0x80078574: nop

    // 0x80078578: jal         0x8007AEB0
    // 0x8007857C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    displayText_RemoveEntry(rdram, ctx);
        goto after_0;
    // 0x8007857C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x80078580: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80078584: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80078588: nop

    // 0x8007858C: bne         $t1, $t2, L_800785A0
    if (ctx->r9 != ctx->r10) {
        // 0x80078590: nop
    
            goto L_800785A0;
    }
    // 0x80078590: nop

    // 0x80078594: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80078598: nop

    // 0x8007859C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
L_800785A0:
    // 0x800785A0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800785A4: nop

    // 0x800785A8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
L_800785AC:
    // 0x800785AC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800785B0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800785B4: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x800785B8: nop

    // 0x800785BC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800785C0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800785C4: nop

    // 0x800785C8: bne         $t8, $t9, L_8007854C
    if (ctx->r24 != ctx->r25) {
        // 0x800785CC: nop
    
            goto L_8007854C;
    }
    // 0x800785CC: nop

    // 0x800785D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800785D4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800785D8: jr          $ra
    // 0x800785DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800785DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void displayText_ClearNonPersistentEntries(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800785E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800785E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800785E8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800785EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800785F0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800785F4:
    // 0x800785F4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800785F8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800785FC: lbu         $t8, 0xB($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XB);
    // 0x80078600: nop

    // 0x80078604: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x80078608: beq         $t9, $at, L_80078658
    if (ctx->r25 == ctx->r1) {
        // 0x8007860C: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80078658;
    }
    // 0x8007860C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80078610: beq         $t9, $at, L_80078658
    if (ctx->r25 == ctx->r1) {
        // 0x80078614: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80078658;
    }
    // 0x80078614: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80078618: beq         $t9, $at, L_80078658
    if (ctx->r25 == ctx->r1) {
        // 0x8007861C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80078658;
    }
    // 0x8007861C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80078620: beq         $t9, $at, L_80078658
    if (ctx->r25 == ctx->r1) {
        // 0x80078624: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80078658;
    }
    // 0x80078624: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80078628: beq         $t9, $at, L_80078658
    if (ctx->r25 == ctx->r1) {
        // 0x8007862C: nop
    
            goto L_80078658;
    }
    // 0x8007862C: nop

    // 0x80078630: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80078634: nop

    // 0x80078638: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8007863C: nop

    // 0x80078640: lbu         $t2, 0xD0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XD0);
    // 0x80078644: nop

    // 0x80078648: bne         $t2, $zero, L_80078658
    if (ctx->r10 != 0) {
        // 0x8007864C: nop
    
            goto L_80078658;
    }
    // 0x8007864C: nop

    // 0x80078650: jal         0x8007AEB0
    // 0x80078654: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    displayText_RemoveEntry(rdram, ctx);
        goto after_0;
    // 0x80078654: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_0:
L_80078658:
    // 0x80078658: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8007865C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80078660: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x80078664: nop

    // 0x80078668: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8007866C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80078670: nop

    // 0x80078674: bne         $t5, $t6, L_800785F4
    if (ctx->r13 != ctx->r14) {
        // 0x80078678: nop
    
            goto L_800785F4;
    }
    // 0x80078678: nop

    // 0x8007867C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078680: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80078684: jr          $ra
    // 0x80078688: nop

    return;
    // 0x80078688: nop

;}

RECOMP_FUNC void FUN_SRAM_8007868c_tenliner_loop_arg0_t(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007868C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80078690: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80078694: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80078698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007869C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800786A0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800786A4:
    // 0x800786A4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800786A8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800786AC: lbu         $t8, 0xB($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XB);
    // 0x800786B0: nop

    // 0x800786B4: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x800786B8: beq         $t9, $at, L_80078700
    if (ctx->r25 == ctx->r1) {
        // 0x800786BC: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80078700;
    }
    // 0x800786BC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800786C0: beq         $t9, $at, L_80078700
    if (ctx->r25 == ctx->r1) {
        // 0x800786C4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80078700;
    }
    // 0x800786C4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800786C8: beq         $t9, $at, L_80078700
    if (ctx->r25 == ctx->r1) {
        // 0x800786CC: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80078700;
    }
    // 0x800786CC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800786D0: beq         $t9, $at, L_80078700
    if (ctx->r25 == ctx->r1) {
        // 0x800786D4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80078700;
    }
    // 0x800786D4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800786D8: beq         $t9, $at, L_80078700
    if (ctx->r25 == ctx->r1) {
        // 0x800786DC: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80078700;
    }
    // 0x800786DC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800786E0: beq         $t9, $at, L_80078700
    if (ctx->r25 == ctx->r1) {
        // 0x800786E4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80078700;
    }
    // 0x800786E4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800786E8: beq         $t9, $at, L_80078700
    if (ctx->r25 == ctx->r1) {
        // 0x800786EC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80078700;
    }
    // 0x800786EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800786F0: beq         $t9, $at, L_80078700
    if (ctx->r25 == ctx->r1) {
        // 0x800786F4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80078700;
    }
    // 0x800786F4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800786F8: bne         $t9, $at, L_8007871C
    if (ctx->r25 != ctx->r1) {
        // 0x800786FC: nop
    
            goto L_8007871C;
    }
    // 0x800786FC: nop

L_80078700:
    // 0x80078700: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80078704: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80078708: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007870C: bne         $t1, $at, L_80078728
    if (ctx->r9 != ctx->r1) {
        // 0x80078710: sw          $t1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r9;
            goto L_80078728;
    }
    // 0x80078710: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80078714: b           L_8007874C
    // 0x80078718: nop

        goto L_8007874C;
    // 0x80078718: nop

L_8007871C:
    // 0x8007871C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80078720: jal         0x8007AEB0
    // 0x80078724: nop

    displayText_RemoveEntry(rdram, ctx);
        goto after_0;
    // 0x80078724: nop

    after_0:
L_80078728:
    // 0x80078728: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8007872C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80078730: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80078734: nop

    // 0x80078738: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8007873C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80078740: nop

    // 0x80078744: bne         $t4, $t5, L_800786A4
    if (ctx->r12 != ctx->r13) {
        // 0x80078748: nop
    
            goto L_800786A4;
    }
    // 0x80078748: nop

L_8007874C:
    // 0x8007874C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078750: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80078754: jr          $ra
    // 0x80078758: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80078758: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void displayText_TallyWonderProgress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007875C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80078760: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80078764: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80078768: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007876C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80078770: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80078774: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80078778: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8007877C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80078780: jal         0x80078300
    // 0x80078784: sb          $t7, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r15;
    displayText_ComputeBarLevel(rdram, ctx);
        goto after_0;
    // 0x80078784: sb          $t7, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r15;
    after_0:
    // 0x80078788: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
    // 0x8007878C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80078790: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80078794: sb          $v0, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r2;
    // 0x80078798: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8007879C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800787A0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800787A4: lhu         $t4, 0xC0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XC0);
    // 0x800787A8: nop

    // 0x800787AC: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x800787B0: sh          $t5, 0xC0($t3)
    MEM_H(0XC0, ctx->r11) = ctx->r13;
    // 0x800787B4: lbu         $t7, 0x4B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4B);
    // 0x800787B8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800787BC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800787C0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800787C4: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800787C8: lw          $t0, 0x18($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X18);
    // 0x800787CC: lhu         $t4, 0xC2($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0XC2);
    // 0x800787D0: nop

    // 0x800787D4: addu        $t2, $t4, $t0
    ctx->r10 = ADD32(ctx->r12, ctx->r8);
    // 0x800787D8: sh          $t2, 0xC2($t1)
    MEM_H(0XC2, ctx->r9) = ctx->r10;
    // 0x800787DC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800787E0: nop

    // 0x800787E4: lhu         $t3, 0xC0($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0XC0);
    // 0x800787E8: nop

    // 0x800787EC: slti        $at, $t3, 0x384
    ctx->r1 = SIGNED(ctx->r11) < 0X384 ? 1 : 0;
    // 0x800787F0: bne         $at, $zero, L_8007882C
    if (ctx->r1 != 0) {
        // 0x800787F4: nop
    
            goto L_8007882C;
    }
    // 0x800787F4: nop

    // 0x800787F8: lhu         $t7, 0xC2($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0XC2);
    // 0x800787FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80078800: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80078804: mflo        $t6
    ctx->r14 = lo;
    // 0x80078808: sh          $t6, 0xC2($t5)
    MEM_H(0XC2, ctx->r13) = ctx->r14;
    // 0x8007880C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80078810: nop

    // 0x80078814: lhu         $t8, 0xC0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0XC0);
    // 0x80078818: nop

    // 0x8007881C: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80078820: mflo        $t4
    ctx->r12 = lo;
    // 0x80078824: sh          $t4, 0xC0($t9)
    MEM_H(0XC0, ctx->r25) = ctx->r12;
    // 0x80078828: nop

L_8007882C:
    // 0x8007882C: lbu         $t2, 0x4B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078830: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80078834: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80078838: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x8007883C: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x80078840: lw          $t7, 0x28($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X28);
    // 0x80078844: lw          $t5, 0xC8($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC8);
    // 0x80078848: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007884C: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x80078850: sltu        $at, $t8, $at
    ctx->r1 = ctx->r24 < ctx->r1 ? 1 : 0;
    // 0x80078854: beq         $at, $zero, L_80078868
    if (ctx->r1 == 0) {
        // 0x80078858: nop
    
            goto L_80078868;
    }
    // 0x80078858: nop

    // 0x8007885C: addu        $t4, $t5, $t7
    ctx->r12 = ADD32(ctx->r13, ctx->r15);
    // 0x80078860: b           L_80078874
    // 0x80078864: sw          $t4, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r12;
        goto L_80078874;
    // 0x80078864: sw          $t4, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r12;
L_80078868:
    // 0x80078868: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8007886C: lui         $t9, 0x4000
    ctx->r25 = S32(0X4000 << 16);
    // 0x80078870: sw          $t9, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r25;
L_80078874:
    // 0x80078874: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078878: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8007887C: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80078880: addu        $t8, $t0, $t3
    ctx->r24 = ADD32(ctx->r8, ctx->r11);
    // 0x80078884: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80078888: lw          $t5, 0x18($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X18);
    // 0x8007888C: lw          $t7, 0x28($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X28);
    // 0x80078890: lw          $t9, 0xCC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XCC);
    // 0x80078894: subu        $t4, $t5, $t7
    ctx->r12 = SUB32(ctx->r13, ctx->r15);
    // 0x80078898: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007889C: addu        $t2, $t4, $t9
    ctx->r10 = ADD32(ctx->r12, ctx->r25);
    // 0x800788A0: sltu        $at, $t2, $at
    ctx->r1 = ctx->r10 < ctx->r1 ? 1 : 0;
    // 0x800788A4: beq         $at, $zero, L_800788B8
    if (ctx->r1 == 0) {
        // 0x800788A8: nop
    
            goto L_800788B8;
    }
    // 0x800788A8: nop

    // 0x800788AC: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x800788B0: b           L_800788C4
    // 0x800788B4: sw          $t1, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->r9;
        goto L_800788C4;
    // 0x800788B4: sw          $t1, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->r9;
L_800788B8:
    // 0x800788B8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800788BC: lui         $t0, 0x4000
    ctx->r8 = S32(0X4000 << 16);
    // 0x800788C0: sw          $t0, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->r8;
L_800788C4:
    // 0x800788C4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800788C8: lbu         $s0, -0x1114($s0)
    ctx->r16 = MEM_BU(ctx->r16, -0X1114);
    // 0x800788CC: nop

    // 0x800788D0: beq         $s0, $zero, L_800788F0
    if (ctx->r16 == 0) {
        // 0x800788D4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800788F0;
    }
    // 0x800788D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800788D8: beq         $s0, $at, L_80078CC8
    if (ctx->r16 == ctx->r1) {
        // 0x800788DC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80078CC8;
    }
    // 0x800788DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800788E0: beq         $s0, $at, L_800790F0
    if (ctx->r16 == ctx->r1) {
        // 0x800788E4: nop
    
            goto L_800790F0;
    }
    // 0x800788E4: nop

    // 0x800788E8: b           L_800794EC
    // 0x800788EC: nop

        goto L_800794EC;
    // 0x800788EC: nop

L_800788F0:
    // 0x800788F0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_800788F4:
    // 0x800788F4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800788F8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800788FC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80078900: lbu         $t0, 0x4B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078904: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x80078908: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8007890C: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80078910: lw          $t9, 0xC($t2)
    ctx->r25 = MEM_W(ctx->r10, 0XC);
    // 0x80078914: lw          $t4, 0x20($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X20);
    // 0x80078918: addu        $t8, $t6, $t3
    ctx->r24 = ADD32(ctx->r14, ctx->r11);
    // 0x8007891C: lw          $t7, 0x18($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X18);
    // 0x80078920: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x80078924: sltu        $at, $t1, $t7
    ctx->r1 = ctx->r9 < ctx->r15 ? 1 : 0;
    // 0x80078928: beq         $at, $zero, L_80078A30
    if (ctx->r1 == 0) {
        // 0x8007892C: nop
    
            goto L_80078A30;
    }
    // 0x8007892C: nop

    // 0x80078930: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80078934: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80078938: beq         $at, $zero, L_800789AC
    if (ctx->r1 == 0) {
        // 0x8007893C: sw          $t2, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r10;
            goto L_800789AC;
    }
    // 0x8007893C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80078940:
    // 0x80078940: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80078944: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80078948: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x8007894C: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x80078950: lw          $t3, 0xC($t6)
    ctx->r11 = MEM_W(ctx->r14, 0XC);
    // 0x80078954: nop

    // 0x80078958: sw          $t3, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r11;
    // 0x8007895C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80078960: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80078964: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x80078968: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x8007896C: lw          $t5, 0x20($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X20);
    // 0x80078970: nop

    // 0x80078974: sw          $t5, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r13;
    // 0x80078978: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8007897C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80078980: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80078984: addu        $t3, $t4, $t0
    ctx->r11 = ADD32(ctx->r12, ctx->r8);
    // 0x80078988: lw          $t6, 0x34($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X34);
    // 0x8007898C: nop

    // 0x80078990: sw          $t6, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->r14;
    // 0x80078994: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80078998: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8007899C: addiu       $t8, $t1, -0x1
    ctx->r24 = ADD32(ctx->r9, -0X1);
    // 0x800789A0: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800789A4: beq         $at, $zero, L_80078940
    if (ctx->r1 == 0) {
        // 0x800789A8: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_80078940;
    }
    // 0x800789A8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_800789AC:
    // 0x800789AC: lbu         $t2, 0x4B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4B);
    // 0x800789B0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800789B4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800789B8: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x800789BC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800789C0: addu        $t4, $t5, $t9
    ctx->r12 = ADD32(ctx->r13, ctx->r25);
    // 0x800789C4: lw          $t0, 0x28($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X28);
    // 0x800789C8: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x800789CC: addu        $t8, $t6, $t1
    ctx->r24 = ADD32(ctx->r14, ctx->r9);
    // 0x800789D0: sw          $t0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r8;
    // 0x800789D4: lbu         $t2, 0x4B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4B);
    // 0x800789D8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800789DC: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x800789E0: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x800789E4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800789E8: lw          $t4, 0x18($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X18);
    // 0x800789EC: lw          $t3, 0x28($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X28);
    // 0x800789F0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800789F4: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800789F8: subu        $t6, $t4, $t3
    ctx->r14 = SUB32(ctx->r12, ctx->r11);
    // 0x800789FC: addu        $t2, $t1, $t8
    ctx->r10 = ADD32(ctx->r9, ctx->r24);
    // 0x80078A00: sw          $t6, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r14;
    // 0x80078A04: lbu         $t5, 0x4B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078A08: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80078A0C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80078A10: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80078A14: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80078A18: addu        $t4, $t7, $t9
    ctx->r12 = ADD32(ctx->r15, ctx->r25);
    // 0x80078A1C: lw          $t3, 0x8($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X8);
    // 0x80078A20: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80078A24: addu        $t6, $t0, $t8
    ctx->r14 = ADD32(ctx->r8, ctx->r24);
    // 0x80078A28: b           L_80078A48
    // 0x80078A2C: sw          $t3, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r11;
        goto L_80078A48;
    // 0x80078A2C: sw          $t3, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r11;
L_80078A30:
    // 0x80078A30: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80078A34: nop

    // 0x80078A38: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x80078A3C: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x80078A40: bne         $at, $zero, L_800788F4
    if (ctx->r1 != 0) {
        // 0x80078A44: sw          $t5, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r13;
            goto L_800788F4;
    }
    // 0x80078A44: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
L_80078A48:
    // 0x80078A48: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_80078A4C:
    // 0x80078A4C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80078A50: lbu         $t3, 0x4B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078A54: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80078A58: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x80078A5C: lw          $t7, -0x310($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X310);
    // 0x80078A60: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80078A64: subu        $t4, $t4, $t9
    ctx->r12 = SUB32(ctx->r12, ctx->r25);
    // 0x80078A68: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80078A6C: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80078A70: addu        $t1, $t7, $t4
    ctx->r9 = ADD32(ctx->r15, ctx->r12);
    // 0x80078A74: addu        $t2, $t8, $t6
    ctx->r10 = ADD32(ctx->r24, ctx->r14);
    // 0x80078A78: lw          $t5, 0x18($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X18);
    // 0x80078A7C: lw          $t0, 0xF18($t1)
    ctx->r8 = MEM_W(ctx->r9, 0XF18);
    // 0x80078A80: nop

    // 0x80078A84: sltu        $at, $t0, $t5
    ctx->r1 = ctx->r8 < ctx->r13 ? 1 : 0;
    // 0x80078A88: beq         $at, $zero, L_80078CA8
    if (ctx->r1 == 0) {
        // 0x80078A8C: nop
    
            goto L_80078CA8;
    }
    // 0x80078A8C: nop

    // 0x80078A90: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80078A94: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80078A98: beq         $at, $zero, L_80078BA8
    if (ctx->r1 == 0) {
        // 0x80078A9C: sw          $t7, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r15;
            goto L_80078BA8;
    }
    // 0x80078A9C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80078AA0:
    // 0x80078AA0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80078AA4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80078AA8: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80078AAC: lw          $t4, -0x310($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X310);
    // 0x80078AB0: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x80078AB4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80078AB8: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x80078ABC: addiu       $t6, $t8, 0xF0C
    ctx->r14 = ADD32(ctx->r24, 0XF0C);
    // 0x80078AC0: addiu       $t2, $t8, 0xF24
    ctx->r10 = ADD32(ctx->r24, 0XF24);
    // 0x80078AC4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80078AC8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80078ACC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80078AD0:
    // 0x80078AD0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80078AD4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80078AD8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80078ADC: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x80078AE0: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x80078AE4: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x80078AE8: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
    // 0x80078AEC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80078AF0: nop

    // 0x80078AF4: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x80078AF8: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80078AFC: bne         $at, $zero, L_80078AD0
    if (ctx->r1 != 0) {
        // 0x80078B00: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_80078AD0;
    }
    // 0x80078B00: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80078B04: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80078B08: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80078B0C: nop

    // 0x80078B10: addu        $t0, $t8, $t2
    ctx->r8 = ADD32(ctx->r24, ctx->r10);
    // 0x80078B14: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x80078B18: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80078B1C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80078B20: lbu         $t1, 0xA($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0XA);
    // 0x80078B24: nop

    // 0x80078B28: sb          $t1, 0xA($t5)
    MEM_B(0XA, ctx->r13) = ctx->r9;
    // 0x80078B2C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80078B30: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80078B34: lbu         $t4, 0xB($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0XB);
    // 0x80078B38: nop

    // 0x80078B3C: sb          $t4, 0xB($t3)
    MEM_B(0XB, ctx->r11) = ctx->r12;
    // 0x80078B40: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80078B44: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80078B48: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x80078B4C: nop

    // 0x80078B50: sw          $t8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r24;
    // 0x80078B54: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80078B58: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80078B5C: lw          $t7, 0x10($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X10);
    // 0x80078B60: nop

    // 0x80078B64: sw          $t7, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r15;
    // 0x80078B68: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80078B6C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80078B70: lhu         $t9, 0x14($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X14);
    // 0x80078B74: nop

    // 0x80078B78: sh          $t9, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r25;
    // 0x80078B7C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80078B80: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80078B84: lhu         $t6, 0x16($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X16);
    // 0x80078B88: nop

    // 0x80078B8C: sh          $t6, 0x16($t8)
    MEM_H(0X16, ctx->r24) = ctx->r14;
    // 0x80078B90: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80078B94: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80078B98: addiu       $t0, $t2, -0x1
    ctx->r8 = ADD32(ctx->r10, -0X1);
    // 0x80078B9C: slt         $at, $t0, $t7
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80078BA0: beq         $at, $zero, L_80078AA0
    if (ctx->r1 == 0) {
        // 0x80078BA4: sw          $t0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r8;
            goto L_80078AA0;
    }
    // 0x80078BA4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80078BA8:
    // 0x80078BA8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80078BAC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80078BB0: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80078BB4: lw          $t1, -0x310($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X310);
    // 0x80078BB8: subu        $t9, $t9, $t5
    ctx->r25 = SUB32(ctx->r25, ctx->r13);
    // 0x80078BBC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80078BC0: addu        $t4, $t1, $t9
    ctx->r12 = ADD32(ctx->r9, ctx->r25);
    // 0x80078BC4: addiu       $t3, $t4, 0xF0C
    ctx->r11 = ADD32(ctx->r12, 0XF0C);
    // 0x80078BC8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80078BCC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80078BD0:
    // 0x80078BD0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80078BD4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80078BD8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80078BDC: addu        $t2, $t6, $t8
    ctx->r10 = ADD32(ctx->r14, ctx->r24);
    // 0x80078BE0: lbu         $t0, 0x0($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X0);
    // 0x80078BE4: addu        $t5, $t7, $t8
    ctx->r13 = ADD32(ctx->r15, ctx->r24);
    // 0x80078BE8: sb          $t0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r8;
    // 0x80078BEC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80078BF0: nop

    // 0x80078BF4: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x80078BF8: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x80078BFC: bne         $at, $zero, L_80078BD0
    if (ctx->r1 != 0) {
        // 0x80078C00: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_80078BD0;
    }
    // 0x80078C00: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80078C04: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80078C08: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80078C0C: nop

    // 0x80078C10: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x80078C14: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80078C18: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80078C1C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80078C20: lbu         $t7, 0x9($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X9);
    // 0x80078C24: nop

    // 0x80078C28: sb          $t7, 0xA($t8)
    MEM_B(0XA, ctx->r24) = ctx->r15;
    // 0x80078C2C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80078C30: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80078C34: lbu         $t5, 0xA($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XA);
    // 0x80078C38: nop

    // 0x80078C3C: sb          $t5, 0xB($t1)
    MEM_B(0XB, ctx->r9) = ctx->r13;
    // 0x80078C40: lbu         $t4, 0x4B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078C44: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80078C48: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80078C4C: addu        $t6, $t9, $t3
    ctx->r14 = ADD32(ctx->r25, ctx->r11);
    // 0x80078C50: lw          $t2, 0x18($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X18);
    // 0x80078C54: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80078C58: nop

    // 0x80078C5C: sw          $t2, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r10;
    // 0x80078C60: lbu         $t0, 0x4B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078C64: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80078C68: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x80078C6C: addu        $t1, $t8, $t5
    ctx->r9 = ADD32(ctx->r24, ctx->r13);
    // 0x80078C70: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x80078C74: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80078C78: nop

    // 0x80078C7C: sw          $t4, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r12;
    // 0x80078C80: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80078C84: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80078C88: lhu         $t6, 0xC0($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0XC0);
    // 0x80078C8C: nop

    // 0x80078C90: sh          $t6, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r14;
    // 0x80078C94: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80078C98: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80078C9C: lhu         $t0, 0xC2($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0XC2);
    // 0x80078CA0: b           L_800794EC
    // 0x80078CA4: sh          $t0, 0x16($t8)
    MEM_H(0X16, ctx->r24) = ctx->r8;
        goto L_800794EC;
    // 0x80078CA4: sh          $t0, 0x16($t8)
    MEM_H(0X16, ctx->r24) = ctx->r8;
L_80078CA8:
    // 0x80078CA8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80078CAC: nop

    // 0x80078CB0: addiu       $t1, $t5, 0x1
    ctx->r9 = ADD32(ctx->r13, 0X1);
    // 0x80078CB4: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x80078CB8: bne         $at, $zero, L_80078A4C
    if (ctx->r1 != 0) {
        // 0x80078CBC: sw          $t1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r9;
            goto L_80078A4C;
    }
    // 0x80078CBC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80078CC0: b           L_800794EC
    // 0x80078CC4: nop

        goto L_800794EC;
    // 0x80078CC4: nop

L_80078CC8:
    // 0x80078CC8: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078CCC: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80078CD0: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80078CD4: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x80078CD8: lw          $t2, 0x8($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X8);
    // 0x80078CDC: nop

    // 0x80078CE0: sltiu       $at, $t2, 0xB3
    ctx->r1 = ctx->r10 < 0XB3 ? 1 : 0;
    // 0x80078CE4: bne         $at, $zero, L_80078CF4
    if (ctx->r1 != 0) {
        // 0x80078CE8: nop
    
            goto L_80078CF4;
    }
    // 0x80078CE8: nop

    // 0x80078CEC: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x80078CF0: sw          $t7, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r15;
L_80078CF4:
    // 0x80078CF4: lbu         $t8, 0x4B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078CF8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80078CFC: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80078D00: addu        $t1, $t0, $t5
    ctx->r9 = ADD32(ctx->r8, ctx->r13);
    // 0x80078D04: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x80078D08: nop

    // 0x80078D0C: sltiu       $at, $t9, 0xB4
    ctx->r1 = ctx->r25 < 0XB4 ? 1 : 0;
    // 0x80078D10: bne         $at, $zero, L_800794EC
    if (ctx->r1 != 0) {
        // 0x80078D14: nop
    
            goto L_800794EC;
    }
    // 0x80078D14: nop

    // 0x80078D18: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_80078D1C:
    // 0x80078D1C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80078D20: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80078D24: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80078D28: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078D2C: addu        $t7, $t4, $t2
    ctx->r15 = ADD32(ctx->r12, ctx->r10);
    // 0x80078D30: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80078D34: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x80078D38: lw          $t6, 0x84($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X84);
    // 0x80078D3C: lw          $t8, 0x98($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X98);
    // 0x80078D40: addu        $t4, $t5, $t9
    ctx->r12 = ADD32(ctx->r13, ctx->r25);
    // 0x80078D44: lw          $t2, 0x18($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X18);
    // 0x80078D48: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x80078D4C: sltu        $at, $t0, $t2
    ctx->r1 = ctx->r8 < ctx->r10 ? 1 : 0;
    // 0x80078D50: beq         $at, $zero, L_80078E58
    if (ctx->r1 == 0) {
        // 0x80078D54: nop
    
            goto L_80078E58;
    }
    // 0x80078D54: nop

    // 0x80078D58: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80078D5C: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80078D60: beq         $at, $zero, L_80078DD4
    if (ctx->r1 == 0) {
        // 0x80078D64: sw          $t7, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r15;
            goto L_80078DD4;
    }
    // 0x80078D64: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80078D68:
    // 0x80078D68: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80078D6C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80078D70: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80078D74: addu        $t5, $t6, $t1
    ctx->r13 = ADD32(ctx->r14, ctx->r9);
    // 0x80078D78: lw          $t9, 0x84($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X84);
    // 0x80078D7C: nop

    // 0x80078D80: sw          $t9, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->r25;
    // 0x80078D84: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80078D88: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80078D8C: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80078D90: addu        $t7, $t4, $t2
    ctx->r15 = ADD32(ctx->r12, ctx->r10);
    // 0x80078D94: lw          $t3, 0x98($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X98);
    // 0x80078D98: nop

    // 0x80078D9C: sw          $t3, 0x9C($t7)
    MEM_W(0X9C, ctx->r15) = ctx->r11;
    // 0x80078DA0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80078DA4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80078DA8: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80078DAC: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x80078DB0: lw          $t5, 0xAC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XAC);
    // 0x80078DB4: nop

    // 0x80078DB8: sw          $t5, 0xB0($t9)
    MEM_W(0XB0, ctx->r25) = ctx->r13;
    // 0x80078DBC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80078DC0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80078DC4: addiu       $t4, $t0, -0x1
    ctx->r12 = ADD32(ctx->r8, -0X1);
    // 0x80078DC8: slt         $at, $t4, $t2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80078DCC: beq         $at, $zero, L_80078D68
    if (ctx->r1 == 0) {
        // 0x80078DD0: sw          $t4, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r12;
            goto L_80078D68;
    }
    // 0x80078DD0: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80078DD4:
    // 0x80078DD4: lbu         $t7, 0x4B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078DD8: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80078DDC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80078DE0: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80078DE4: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80078DE8: addu        $t8, $t3, $t6
    ctx->r24 = ADD32(ctx->r11, ctx->r14);
    // 0x80078DEC: lw          $t1, 0x28($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X28);
    // 0x80078DF0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80078DF4: addu        $t4, $t5, $t0
    ctx->r12 = ADD32(ctx->r13, ctx->r8);
    // 0x80078DF8: sw          $t1, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->r9;
    // 0x80078DFC: lbu         $t7, 0x4B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078E00: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80078E04: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x80078E08: addu        $t6, $t2, $t3
    ctx->r14 = ADD32(ctx->r10, ctx->r11);
    // 0x80078E0C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80078E10: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x80078E14: lw          $t9, 0x28($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X28);
    // 0x80078E18: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80078E1C: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x80078E20: subu        $t5, $t8, $t9
    ctx->r13 = SUB32(ctx->r24, ctx->r25);
    // 0x80078E24: addu        $t7, $t0, $t4
    ctx->r15 = ADD32(ctx->r8, ctx->r12);
    // 0x80078E28: sw          $t5, 0x98($t7)
    MEM_W(0X98, ctx->r15) = ctx->r13;
    // 0x80078E2C: lbu         $t3, 0x4B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078E30: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80078E34: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80078E38: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80078E3C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80078E40: addu        $t8, $t2, $t6
    ctx->r24 = ADD32(ctx->r10, ctx->r14);
    // 0x80078E44: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80078E48: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x80078E4C: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80078E50: b           L_80078E70
    // 0x80078E54: sw          $t9, 0xAC($t5)
    MEM_W(0XAC, ctx->r13) = ctx->r25;
        goto L_80078E70;
    // 0x80078E54: sw          $t9, 0xAC($t5)
    MEM_W(0XAC, ctx->r13) = ctx->r25;
L_80078E58:
    // 0x80078E58: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80078E5C: nop

    // 0x80078E60: addiu       $t3, $t7, 0x1
    ctx->r11 = ADD32(ctx->r15, 0X1);
    // 0x80078E64: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x80078E68: bne         $at, $zero, L_80078D1C
    if (ctx->r1 != 0) {
        // 0x80078E6C: sw          $t3, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r11;
            goto L_80078D1C;
    }
    // 0x80078E6C: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
L_80078E70:
    // 0x80078E70: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_80078E74:
    // 0x80078E74: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80078E78: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078E7C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80078E80: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80078E84: lw          $t2, -0x310($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X310);
    // 0x80078E88: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80078E8C: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x80078E90: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80078E94: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80078E98: addu        $t0, $t2, $t8
    ctx->r8 = ADD32(ctx->r10, ctx->r24);
    // 0x80078E9C: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x80078EA0: lw          $t3, 0x18($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X18);
    // 0x80078EA4: lw          $t1, 0x1008($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1008);
    // 0x80078EA8: nop

    // 0x80078EAC: sltu        $at, $t1, $t3
    ctx->r1 = ctx->r9 < ctx->r11 ? 1 : 0;
    // 0x80078EB0: beq         $at, $zero, L_800790D0
    if (ctx->r1 == 0) {
        // 0x80078EB4: nop
    
            goto L_800790D0;
    }
    // 0x80078EB4: nop

    // 0x80078EB8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80078EBC: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80078EC0: beq         $at, $zero, L_80078FD0
    if (ctx->r1 == 0) {
        // 0x80078EC4: sw          $t2, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r10;
            goto L_80078FD0;
    }
    // 0x80078EC4: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80078EC8:
    // 0x80078EC8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80078ECC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80078ED0: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80078ED4: lw          $t8, -0x310($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X310);
    // 0x80078ED8: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x80078EDC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80078EE0: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x80078EE4: addiu       $t5, $t4, 0xFFC
    ctx->r13 = ADD32(ctx->r12, 0XFFC);
    // 0x80078EE8: addiu       $t7, $t4, 0x1014
    ctx->r15 = ADD32(ctx->r12, 0X1014);
    // 0x80078EEC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80078EF0: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80078EF4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80078EF8:
    // 0x80078EF8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80078EFC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80078F00: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80078F04: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x80078F08: lbu         $t6, 0x0($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X0);
    // 0x80078F0C: addu        $t8, $t0, $t3
    ctx->r24 = ADD32(ctx->r8, ctx->r11);
    // 0x80078F10: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x80078F14: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80078F18: nop

    // 0x80078F1C: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x80078F20: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x80078F24: bne         $at, $zero, L_80078EF8
    if (ctx->r1 != 0) {
        // 0x80078F28: sw          $t5, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r13;
            goto L_80078EF8;
    }
    // 0x80078F28: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x80078F2C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80078F30: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80078F34: nop

    // 0x80078F38: addu        $t1, $t4, $t7
    ctx->r9 = ADD32(ctx->r12, ctx->r15);
    // 0x80078F3C: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80078F40: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80078F44: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80078F48: lbu         $t0, 0xA($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0XA);
    // 0x80078F4C: nop

    // 0x80078F50: sb          $t0, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r8;
    // 0x80078F54: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80078F58: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80078F5C: lbu         $t8, 0xB($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0XB);
    // 0x80078F60: nop

    // 0x80078F64: sb          $t8, 0xB($t9)
    MEM_B(0XB, ctx->r25) = ctx->r24;
    // 0x80078F68: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80078F6C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80078F70: lw          $t4, 0xC($t5)
    ctx->r12 = MEM_W(ctx->r13, 0XC);
    // 0x80078F74: nop

    // 0x80078F78: sw          $t4, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r12;
    // 0x80078F7C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80078F80: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80078F84: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x80078F88: nop

    // 0x80078F8C: sw          $t2, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r10;
    // 0x80078F90: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80078F94: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80078F98: lhu         $t6, 0x14($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X14);
    // 0x80078F9C: nop

    // 0x80078FA0: sh          $t6, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r14;
    // 0x80078FA4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80078FA8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80078FAC: lhu         $t5, 0x16($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0X16);
    // 0x80078FB0: nop

    // 0x80078FB4: sh          $t5, 0x16($t4)
    MEM_H(0X16, ctx->r12) = ctx->r13;
    // 0x80078FB8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80078FBC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80078FC0: addiu       $t1, $t7, -0x1
    ctx->r9 = ADD32(ctx->r15, -0X1);
    // 0x80078FC4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80078FC8: beq         $at, $zero, L_80078EC8
    if (ctx->r1 == 0) {
        // 0x80078FCC: sw          $t1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r9;
            goto L_80078EC8;
    }
    // 0x80078FCC: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_80078FD0:
    // 0x80078FD0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80078FD4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80078FD8: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80078FDC: lw          $t0, -0x310($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X310);
    // 0x80078FE0: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80078FE4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80078FE8: addu        $t8, $t0, $t6
    ctx->r24 = ADD32(ctx->r8, ctx->r14);
    // 0x80078FEC: addiu       $t9, $t8, 0xFFC
    ctx->r25 = ADD32(ctx->r24, 0XFFC);
    // 0x80078FF0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80078FF4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80078FF8:
    // 0x80078FF8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80078FFC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80079000: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80079004: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80079008: lbu         $t1, 0x0($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X0);
    // 0x8007900C: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80079010: sb          $t1, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r9;
    // 0x80079014: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80079018: nop

    // 0x8007901C: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x80079020: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80079024: bne         $at, $zero, L_80078FF8
    if (ctx->r1 != 0) {
        // 0x80079028: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_80078FF8;
    }
    // 0x80079028: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8007902C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80079030: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80079034: nop

    // 0x80079038: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x8007903C: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x80079040: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80079044: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80079048: lbu         $t2, 0x9($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X9);
    // 0x8007904C: nop

    // 0x80079050: sb          $t2, 0xA($t4)
    MEM_B(0XA, ctx->r12) = ctx->r10;
    // 0x80079054: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80079058: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007905C: lbu         $t3, 0xA($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0XA);
    // 0x80079060: nop

    // 0x80079064: sb          $t3, 0xB($t0)
    MEM_B(0XB, ctx->r8) = ctx->r11;
    // 0x80079068: lbu         $t8, 0x4B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4B);
    // 0x8007906C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80079070: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80079074: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x80079078: lw          $t7, 0x18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18);
    // 0x8007907C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80079080: nop

    // 0x80079084: sw          $t7, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r15;
    // 0x80079088: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
    // 0x8007908C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80079090: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80079094: addu        $t0, $t4, $t3
    ctx->r8 = ADD32(ctx->r12, ctx->r11);
    // 0x80079098: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x8007909C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800790A0: nop

    // 0x800790A4: sw          $t8, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r24;
    // 0x800790A8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800790AC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800790B0: lhu         $t5, 0xC0($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0XC0);
    // 0x800790B4: nop

    // 0x800790B8: sh          $t5, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r13;
    // 0x800790BC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800790C0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800790C4: lhu         $t1, 0xC2($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0XC2);
    // 0x800790C8: b           L_800794EC
    // 0x800790CC: sh          $t1, 0x16($t4)
    MEM_H(0X16, ctx->r12) = ctx->r9;
        goto L_800794EC;
    // 0x800790CC: sh          $t1, 0x16($t4)
    MEM_H(0X16, ctx->r12) = ctx->r9;
L_800790D0:
    // 0x800790D0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800790D4: nop

    // 0x800790D8: addiu       $t0, $t3, 0x1
    ctx->r8 = ADD32(ctx->r11, 0X1);
    // 0x800790DC: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x800790E0: bne         $at, $zero, L_80078E74
    if (ctx->r1 != 0) {
        // 0x800790E4: sw          $t0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r8;
            goto L_80078E74;
    }
    // 0x800790E4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800790E8: b           L_800794EC
    // 0x800790EC: nop

        goto L_800794EC;
    // 0x800790EC: nop

L_800790F0:
    // 0x800790F0: lbu         $t6, 0x4B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4B);
    // 0x800790F4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800790F8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800790FC: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x80079100: lw          $t7, 0x18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18);
    // 0x80079104: nop

    // 0x80079108: sltiu       $at, $t7, 0x96
    ctx->r1 = ctx->r15 < 0X96 ? 1 : 0;
    // 0x8007910C: bne         $at, $zero, L_800794EC
    if (ctx->r1 != 0) {
        // 0x80079110: nop
    
            goto L_800794EC;
    }
    // 0x80079110: nop

    // 0x80079114: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_80079118:
    // 0x80079118: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8007911C: lbu         $t8, 0x4B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4B);
    // 0x80079120: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80079124: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80079128: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8007912C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80079130: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80079134: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x80079138: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8007913C: lw          $t0, 0x70($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X70);
    // 0x80079140: nop

    // 0x80079144: sltu        $at, $t7, $t0
    ctx->r1 = ctx->r15 < ctx->r8 ? 1 : 0;
    // 0x80079148: bne         $at, $zero, L_80079158
    if (ctx->r1 != 0) {
        // 0x8007914C: nop
    
            goto L_80079158;
    }
    // 0x8007914C: nop

    // 0x80079150: bne         $t0, $zero, L_8007925C
    if (ctx->r8 != 0) {
        // 0x80079154: nop
    
            goto L_8007925C;
    }
    // 0x80079154: nop

L_80079158:
    // 0x80079158: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8007915C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80079160: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80079164: beq         $at, $zero, L_800791D8
    if (ctx->r1 == 0) {
        // 0x80079168: sw          $t1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r9;
            goto L_800791D8;
    }
    // 0x80079168: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_8007916C:
    // 0x8007916C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80079170: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80079174: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80079178: addu        $t6, $t4, $t8
    ctx->r14 = ADD32(ctx->r12, ctx->r24);
    // 0x8007917C: lw          $t9, 0x48($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X48);
    // 0x80079180: nop

    // 0x80079184: sw          $t9, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->r25;
    // 0x80079188: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8007918C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80079190: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80079194: addu        $t1, $t5, $t0
    ctx->r9 = ADD32(ctx->r13, ctx->r8);
    // 0x80079198: lw          $t2, 0x5C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X5C);
    // 0x8007919C: nop

    // 0x800791A0: sw          $t2, 0x60($t1)
    MEM_W(0X60, ctx->r9) = ctx->r10;
    // 0x800791A4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800791A8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800791AC: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x800791B0: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x800791B4: lw          $t6, 0x70($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X70);
    // 0x800791B8: nop

    // 0x800791BC: sw          $t6, 0x74($t9)
    MEM_W(0X74, ctx->r25) = ctx->r14;
    // 0x800791C0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800791C4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800791C8: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x800791CC: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800791D0: beq         $at, $zero, L_8007916C
    if (ctx->r1 == 0) {
        // 0x800791D4: sw          $t5, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r13;
            goto L_8007916C;
    }
    // 0x800791D4: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_800791D8:
    // 0x800791D8: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
    // 0x800791DC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800791E0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800791E4: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800791E8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800791EC: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x800791F0: lw          $t8, 0x28($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X28);
    // 0x800791F4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800791F8: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x800791FC: sw          $t8, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->r24;
    // 0x80079200: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
    // 0x80079204: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80079208: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8007920C: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x80079210: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80079214: lw          $t3, 0x18($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X18);
    // 0x80079218: lw          $t9, 0x28($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X28);
    // 0x8007921C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80079220: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80079224: subu        $t6, $t3, $t9
    ctx->r14 = SUB32(ctx->r11, ctx->r25);
    // 0x80079228: addu        $t1, $t7, $t5
    ctx->r9 = ADD32(ctx->r15, ctx->r13);
    // 0x8007922C: sw          $t6, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->r14;
    // 0x80079230: lbu         $t2, 0x4B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4B);
    // 0x80079234: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80079238: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8007923C: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80079240: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80079244: addu        $t3, $t0, $t4
    ctx->r11 = ADD32(ctx->r8, ctx->r12);
    // 0x80079248: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x8007924C: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x80079250: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x80079254: b           L_80079274
    // 0x80079258: sw          $t9, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->r25;
        goto L_80079274;
    // 0x80079258: sw          $t9, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->r25;
L_8007925C:
    // 0x8007925C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80079260: nop

    // 0x80079264: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80079268: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x8007926C: bne         $at, $zero, L_80079118
    if (ctx->r1 != 0) {
        // 0x80079270: sw          $t2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r10;
            goto L_80079118;
    }
    // 0x80079270: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
L_80079274:
    // 0x80079274: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_80079278:
    // 0x80079278: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8007927C: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
    // 0x80079280: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80079284: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80079288: lw          $t0, -0x310($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X310);
    // 0x8007928C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80079290: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x80079294: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80079298: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8007929C: addu        $t7, $t0, $t3
    ctx->r15 = ADD32(ctx->r8, ctx->r11);
    // 0x800792A0: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x800792A4: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800792A8: lw          $t8, 0xF94($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XF94);
    // 0x800792AC: nop

    // 0x800792B0: sltu        $at, $t2, $t8
    ctx->r1 = ctx->r10 < ctx->r24 ? 1 : 0;
    // 0x800792B4: beq         $at, $zero, L_800794D4
    if (ctx->r1 == 0) {
        // 0x800792B8: nop
    
            goto L_800794D4;
    }
    // 0x800792B8: nop

    // 0x800792BC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800792C0: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800792C4: beq         $at, $zero, L_800793D4
    if (ctx->r1 == 0) {
        // 0x800792C8: sw          $t0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r8;
            goto L_800793D4;
    }
    // 0x800792C8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_800792CC:
    // 0x800792CC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800792D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800792D4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800792D8: lw          $t3, -0x310($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X310);
    // 0x800792DC: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800792E0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800792E4: addu        $t5, $t3, $t9
    ctx->r13 = ADD32(ctx->r11, ctx->r25);
    // 0x800792E8: addiu       $t6, $t5, 0xF84
    ctx->r14 = ADD32(ctx->r13, 0XF84);
    // 0x800792EC: addiu       $t1, $t5, 0xF9C
    ctx->r9 = ADD32(ctx->r13, 0XF9C);
    // 0x800792F0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800792F4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800792F8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800792FC:
    // 0x800792FC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80079300: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80079304: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80079308: addu        $t0, $t8, $t2
    ctx->r8 = ADD32(ctx->r24, ctx->r10);
    // 0x8007930C: lbu         $t4, 0x0($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X0);
    // 0x80079310: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x80079314: sb          $t4, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r12;
    // 0x80079318: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007931C: nop

    // 0x80079320: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80079324: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80079328: bne         $at, $zero, L_800792FC
    if (ctx->r1 != 0) {
        // 0x8007932C: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_800792FC;
    }
    // 0x8007932C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80079330: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80079334: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80079338: nop

    // 0x8007933C: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x80079340: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x80079344: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80079348: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007934C: lbu         $t7, 0xA($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0XA);
    // 0x80079350: nop

    // 0x80079354: sb          $t7, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r15;
    // 0x80079358: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007935C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80079360: lbu         $t3, 0xB($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0XB);
    // 0x80079364: nop

    // 0x80079368: sb          $t3, 0xB($t9)
    MEM_B(0XB, ctx->r25) = ctx->r11;
    // 0x8007936C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80079370: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80079374: lw          $t5, 0xC($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC);
    // 0x80079378: nop

    // 0x8007937C: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x80079380: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80079384: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80079388: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x8007938C: nop

    // 0x80079390: sw          $t0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r8;
    // 0x80079394: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80079398: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007939C: lhu         $t4, 0x14($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X14);
    // 0x800793A0: nop

    // 0x800793A4: sh          $t4, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r12;
    // 0x800793A8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800793AC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800793B0: lhu         $t6, 0x16($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X16);
    // 0x800793B4: nop

    // 0x800793B8: sh          $t6, 0x16($t5)
    MEM_H(0X16, ctx->r13) = ctx->r14;
    // 0x800793BC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800793C0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800793C4: addiu       $t8, $t1, -0x1
    ctx->r24 = ADD32(ctx->r9, -0X1);
    // 0x800793C8: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800793CC: beq         $at, $zero, L_800792CC
    if (ctx->r1 == 0) {
        // 0x800793D0: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_800792CC;
    }
    // 0x800793D0: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_800793D4:
    // 0x800793D4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800793D8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800793DC: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800793E0: lw          $t7, -0x310($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X310);
    // 0x800793E4: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x800793E8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800793EC: addu        $t3, $t7, $t4
    ctx->r11 = ADD32(ctx->r15, ctx->r12);
    // 0x800793F0: addiu       $t9, $t3, 0xF84
    ctx->r25 = ADD32(ctx->r11, 0XF84);
    // 0x800793F4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800793F8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_800793FC:
    // 0x800793FC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80079400: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80079404: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80079408: addu        $t1, $t6, $t5
    ctx->r9 = ADD32(ctx->r14, ctx->r13);
    // 0x8007940C: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x80079410: addu        $t2, $t0, $t5
    ctx->r10 = ADD32(ctx->r8, ctx->r13);
    // 0x80079414: sb          $t8, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r24;
    // 0x80079418: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8007941C: nop

    // 0x80079420: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x80079424: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x80079428: bne         $at, $zero, L_800793FC
    if (ctx->r1 != 0) {
        // 0x8007942C: sw          $t4, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r12;
            goto L_800793FC;
    }
    // 0x8007942C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80079430: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80079434: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80079438: nop

    // 0x8007943C: addu        $t6, $t3, $t9
    ctx->r14 = ADD32(ctx->r11, ctx->r25);
    // 0x80079440: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80079444: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80079448: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007944C: lbu         $t0, 0x9($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X9);
    // 0x80079450: nop

    // 0x80079454: sb          $t0, 0xA($t5)
    MEM_B(0XA, ctx->r13) = ctx->r8;
    // 0x80079458: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8007945C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80079460: lbu         $t2, 0xA($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0XA);
    // 0x80079464: nop

    // 0x80079468: sb          $t2, 0xB($t7)
    MEM_B(0XB, ctx->r15) = ctx->r10;
    // 0x8007946C: lbu         $t3, 0x4B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4B);
    // 0x80079470: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80079474: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80079478: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8007947C: lw          $t1, 0x18($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X18);
    // 0x80079480: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80079484: nop

    // 0x80079488: sw          $t1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r9;
    // 0x8007948C: lbu         $t8, 0x4B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4B);
    // 0x80079490: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80079494: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80079498: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x8007949C: lw          $t3, 0x8($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X8);
    // 0x800794A0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800794A4: nop

    // 0x800794A8: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    // 0x800794AC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800794B0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800794B4: lhu         $t6, 0xC0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0XC0);
    // 0x800794B8: nop

    // 0x800794BC: sh          $t6, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r14;
    // 0x800794C0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800794C4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800794C8: lhu         $t8, 0xC2($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0XC2);
    // 0x800794CC: b           L_800794EC
    // 0x800794D0: sh          $t8, 0x16($t5)
    MEM_H(0X16, ctx->r13) = ctx->r24;
        goto L_800794EC;
    // 0x800794D0: sh          $t8, 0x16($t5)
    MEM_H(0X16, ctx->r13) = ctx->r24;
L_800794D4:
    // 0x800794D4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800794D8: nop

    // 0x800794DC: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x800794E0: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x800794E4: bne         $at, $zero, L_80079278
    if (ctx->r1 != 0) {
        // 0x800794E8: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_80079278;
    }
    // 0x800794E8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_800794EC:
    // 0x800794EC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800794F0: lbu         $t4, 0x4B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4B);
    // 0x800794F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800794F8: addu        $t9, $t3, $t4
    ctx->r25 = ADD32(ctx->r11, ctx->r12);
    // 0x800794FC: lbu         $t6, 0x1($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X1);
    // 0x80079500: nop

    // 0x80079504: bne         $t6, $at, L_800795C8
    if (ctx->r14 != ctx->r1) {
        // 0x80079508: nop
    
            goto L_800795C8;
    }
    // 0x80079508: nop

    // 0x8007950C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80079510: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80079514: lbu         $s0, 0xD4($t1)
    ctx->r16 = MEM_BU(ctx->r9, 0XD4);
    // 0x80079518: nop

    // 0x8007951C: andi        $t0, $s0, 0xF
    ctx->r8 = ctx->r16 & 0XF;
    // 0x80079520: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80079524: beq         $s0, $at, L_80079568
    if (ctx->r16 == ctx->r1) {
        // 0x80079528: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80079568;
    }
    // 0x80079528: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8007952C: bne         $s0, $at, L_800795B8
    if (ctx->r16 != ctx->r1) {
        // 0x80079530: nop
    
            goto L_800795B8;
    }
    // 0x80079530: nop

    // 0x80079534: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80079538: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007953C: lw          $a1, -0x310($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X310);
    // 0x80079540: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80079544: lw          $a2, 0x38($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X38);
    // 0x80079548: jal         0x800798F0
    // 0x8007954C: nop

    displayText_DrawWonderProgress(rdram, ctx);
        goto after_1;
    // 0x8007954C: nop

    after_1:
    // 0x80079550: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80079554: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x80079558: jal         0x8007C5CC
    // 0x8007955C: nop

    SaveData_Save(rdram, ctx);
        goto after_2;
    // 0x8007955C: nop

    after_2:
    // 0x80079560: b           L_800795C8
    // 0x80079564: nop

        goto L_800795C8;
    // 0x80079564: nop

L_80079568:
    // 0x80079568: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8007956C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80079570: lw          $t2, 0xC4($t5)
    ctx->r10 = MEM_W(ctx->r13, 0XC4);
    // 0x80079574: lw          $t3, 0x38($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X38);
    // 0x80079578: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8007957C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80079580: sltu        $at, $t4, $at
    ctx->r1 = ctx->r12 < ctx->r1 ? 1 : 0;
    // 0x80079584: beq         $at, $zero, L_80079594
    if (ctx->r1 == 0) {
        // 0x80079588: nop
    
            goto L_80079594;
    }
    // 0x80079588: nop

    // 0x8007958C: b           L_800795A0
    // 0x80079590: sw          $t4, 0xC4($t5)
    MEM_W(0XC4, ctx->r13) = ctx->r12;
        goto L_800795A0;
    // 0x80079590: sw          $t4, 0xC4($t5)
    MEM_W(0XC4, ctx->r13) = ctx->r12;
L_80079594:
    // 0x80079594: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80079598: lui         $t9, 0x10
    ctx->r25 = S32(0X10 << 16);
    // 0x8007959C: sw          $t9, 0xC4($t6)
    MEM_W(0XC4, ctx->r14) = ctx->r25;
L_800795A0:
    // 0x800795A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800795A4: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x800795A8: jal         0x8007C5CC
    // 0x800795AC: nop

    SaveData_Save(rdram, ctx);
        goto after_3;
    // 0x800795AC: nop

    after_3:
    // 0x800795B0: b           L_800795C8
    // 0x800795B4: nop

        goto L_800795C8;
    // 0x800795B4: nop

L_800795B8:
    // 0x800795B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800795BC: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x800795C0: jal         0x8007C5CC
    // 0x800795C4: nop

    SaveData_Save(rdram, ctx);
        goto after_4;
    // 0x800795C4: nop

    after_4:
L_800795C8:
    // 0x800795C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800795CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800795D0: jr          $ra
    // 0x800795D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800795D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void displayText_CopyEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800795D8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800795DC: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x800795E0: beq         $at, $zero, L_8007960C
    if (ctx->r1 == 0) {
        // 0x800795E4: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_8007960C;
    }
    // 0x800795E4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
L_800795E8:
    // 0x800795E8: addu        $t6, $a0, $t0
    ctx->r14 = ADD32(ctx->r4, ctx->r8);
    // 0x800795EC: addu        $t8, $a1, $t0
    ctx->r24 = ADD32(ctx->r5, ctx->r8);
    // 0x800795F0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800795F4: andi        $t9, $t0, 0xFF
    ctx->r25 = ctx->r8 & 0XFF;
    // 0x800795F8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800795FC: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x80079600: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x80079604: bne         $at, $zero, L_800795E8
    if (ctx->r1 != 0) {
        // 0x80079608: sb          $t7, 0x0($t8)
        MEM_B(0X0, ctx->r24) = ctx->r15;
            goto L_800795E8;
    }
    // 0x80079608: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_8007960C:
    // 0x8007960C: lbu         $t1, 0x9($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X9);
    // 0x80079610: lw          $t3, 0xC($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XC);
    // 0x80079614: sb          $t1, 0xA($a1)
    MEM_B(0XA, ctx->r5) = ctx->r9;
    // 0x80079618: lbu         $t2, 0xA($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XA);
    // 0x8007961C: lw          $t5, 0x10($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X10);
    // 0x80079620: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x80079624: addu        $t6, $t5, $a3
    ctx->r14 = ADD32(ctx->r13, ctx->r7);
    // 0x80079628: sw          $t4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r12;
    // 0x8007962C: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x80079630: sb          $t2, 0xB($a1)
    MEM_B(0XB, ctx->r5) = ctx->r10;
    // 0x80079634: lhu         $t7, 0xC0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XC0);
    // 0x80079638: nop

    // 0x8007963C: sh          $t7, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r15;
    // 0x80079640: lhu         $t8, 0xC2($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC2);
    // 0x80079644: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80079648: jr          $ra
    // 0x8007964C: sh          $t8, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r24;
    return;
    // 0x8007964C: sh          $t8, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r24;
;}

RECOMP_FUNC void displayText_FindEntryIndexByXY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079650: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80079654: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80079658:
    // 0x80079658: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8007965C: lbu         $t6, 0x9($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9);
    // 0x80079660: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80079664: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80079668: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8007966C: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x80079670: lbu         $t0, 0x170E($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X170E);
    // 0x80079674: nop

    // 0x80079678: bne         $t6, $t0, L_800796A4
    if (ctx->r14 != ctx->r8) {
        // 0x8007967C: nop
    
            goto L_800796A4;
    }
    // 0x8007967C: nop

    // 0x80079680: addu        $t2, $a1, $t8
    ctx->r10 = ADD32(ctx->r5, ctx->r24);
    // 0x80079684: lbu         $t3, 0x170F($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X170F);
    // 0x80079688: lbu         $t1, 0xA($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XA);
    // 0x8007968C: nop

    // 0x80079690: bne         $t1, $t3, L_800796A4
    if (ctx->r9 != ctx->r11) {
        // 0x80079694: nop
    
            goto L_800796A4;
    }
    // 0x80079694: nop

    // 0x80079698: lb          $v0, 0x7($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X7);
    // 0x8007969C: b           L_800796C0
    // 0x800796A0: nop

        goto L_800796C0;
    // 0x800796A0: nop

L_800796A4:
    // 0x800796A4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800796A8: nop

    // 0x800796AC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800796B0: slti        $at, $t5, 0x14
    ctx->r1 = SIGNED(ctx->r13) < 0X14 ? 1 : 0;
    // 0x800796B4: bne         $at, $zero, L_80079658
    if (ctx->r1 != 0) {
        // 0x800796B8: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_80079658;
    }
    // 0x800796B8: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800796BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800796C0:
    // 0x800796C0: jr          $ra
    // 0x800796C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800796C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void displayText_InsertEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800796C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800796CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800796D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800796D4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800796D8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800796DC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800796E0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800796E4:
    // 0x800796E4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800796E8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800796EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800796F0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800796F4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800796F8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800796FC: lbu         $t0, 0x170E($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X170E);
    // 0x80079700: nop

    // 0x80079704: bne         $t0, $zero, L_80079738
    if (ctx->r8 != 0) {
        // 0x80079708: nop
    
            goto L_80079738;
    }
    // 0x80079708: nop

    // 0x8007970C: lbu         $t1, 0x170F($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X170F);
    // 0x80079710: nop

    // 0x80079714: bne         $t1, $zero, L_80079738
    if (ctx->r9 != 0) {
        // 0x80079718: nop
    
            goto L_80079738;
    }
    // 0x80079718: nop

    // 0x8007971C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80079720: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80079724: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80079728: jal         0x800795D8
    // 0x8007972C: addiu       $a1, $t9, 0x1704
    ctx->r5 = ADD32(ctx->r25, 0X1704);
    displayText_CopyEntry(rdram, ctx);
        goto after_0;
    // 0x8007972C: addiu       $a1, $t9, 0x1704
    ctx->r5 = ADD32(ctx->r25, 0X1704);
    after_0:
    // 0x80079730: b           L_80079750
    // 0x80079734: nop

        goto L_80079750;
    // 0x80079734: nop

L_80079738:
    // 0x80079738: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8007973C: nop

    // 0x80079740: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80079744: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x80079748: bne         $at, $zero, L_800796E4
    if (ctx->r1 != 0) {
        // 0x8007974C: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_800796E4;
    }
    // 0x8007974C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80079750:
    // 0x80079750: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80079754: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80079758: bne         $t4, $at, L_800798E0
    if (ctx->r12 != ctx->r1) {
        // 0x8007975C: nop
    
            goto L_800798E0;
    }
    // 0x8007975C: nop

    // 0x80079760: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80079764:
    // 0x80079764: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80079768: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8007976C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80079770: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80079774: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80079778: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x8007977C: lw          $t0, 0x1710($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X1710);
    // 0x80079780: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80079784: nop

    // 0x80079788: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x8007978C: beq         $at, $zero, L_800798C8
    if (ctx->r1 == 0) {
        // 0x80079790: nop
    
            goto L_800798C8;
    }
    // 0x80079790: nop

    // 0x80079794: addiu       $t9, $zero, 0x12
    ctx->r25 = ADD32(0, 0X12);
    // 0x80079798: slti        $at, $t7, 0x13
    ctx->r1 = SIGNED(ctx->r15) < 0X13 ? 1 : 0;
    // 0x8007979C: beq         $at, $zero, L_80079894
    if (ctx->r1 == 0) {
        // 0x800797A0: sw          $t9, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r25;
            goto L_80079894;
    }
    // 0x800797A0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_800797A4:
    // 0x800797A4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800797A8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800797AC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800797B0: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800797B4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800797B8: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800797BC: addiu       $t6, $t5, 0x1704
    ctx->r14 = ADD32(ctx->r13, 0X1704);
    // 0x800797C0: addiu       $t8, $t5, 0x171C
    ctx->r24 = ADD32(ctx->r13, 0X171C);
    // 0x800797C4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800797C8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800797CC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800797D0:
    // 0x800797D0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800797D4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800797D8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800797DC: addu        $t9, $t0, $t1
    ctx->r25 = ADD32(ctx->r8, ctx->r9);
    // 0x800797E0: lbu         $t7, 0x0($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X0);
    // 0x800797E4: addu        $t2, $t3, $t1
    ctx->r10 = ADD32(ctx->r11, ctx->r9);
    // 0x800797E8: sb          $t7, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r15;
    // 0x800797EC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800797F0: nop

    // 0x800797F4: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800797F8: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800797FC: bne         $at, $zero, L_800797D0
    if (ctx->r1 != 0) {
        // 0x80079800: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_800797D0;
    }
    // 0x80079800: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80079804: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80079808: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007980C: lbu         $t8, 0xA($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0XA);
    // 0x80079810: nop

    // 0x80079814: sb          $t8, 0xA($t0)
    MEM_B(0XA, ctx->r8) = ctx->r24;
    // 0x80079818: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8007981C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80079820: lbu         $t3, 0xB($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0XB);
    // 0x80079824: nop

    // 0x80079828: sb          $t3, 0xB($t1)
    MEM_B(0XB, ctx->r9) = ctx->r11;
    // 0x8007982C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80079830: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80079834: lw          $t2, 0xC($t7)
    ctx->r10 = MEM_W(ctx->r15, 0XC);
    // 0x80079838: nop

    // 0x8007983C: sw          $t2, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r10;
    // 0x80079840: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80079844: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80079848: lw          $t5, 0x10($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X10);
    // 0x8007984C: nop

    // 0x80079850: sw          $t5, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r13;
    // 0x80079854: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80079858: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8007985C: lhu         $t9, 0x14($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X14);
    // 0x80079860: nop

    // 0x80079864: sh          $t9, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r25;
    // 0x80079868: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007986C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80079870: lhu         $t7, 0x16($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X16);
    // 0x80079874: nop

    // 0x80079878: sh          $t7, 0x16($t2)
    MEM_H(0X16, ctx->r10) = ctx->r15;
    // 0x8007987C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80079880: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80079884: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80079888: slt         $at, $t6, $t5
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007988C: beq         $at, $zero, L_800797A4
    if (ctx->r1 == 0) {
        // 0x80079890: sw          $t6, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r14;
            goto L_800797A4;
    }
    // 0x80079890: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80079894:
    // 0x80079894: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80079898: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8007989C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800798A0: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x800798A4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800798A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800798AC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800798B0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800798B4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x800798B8: jal         0x800795D8
    // 0x800798BC: addiu       $a1, $a1, 0x1704
    ctx->r5 = ADD32(ctx->r5, 0X1704);
    displayText_CopyEntry(rdram, ctx);
        goto after_1;
    // 0x800798BC: addiu       $a1, $a1, 0x1704
    ctx->r5 = ADD32(ctx->r5, 0X1704);
    after_1:
    // 0x800798C0: b           L_800798E0
    // 0x800798C4: nop

        goto L_800798E0;
    // 0x800798C4: nop

L_800798C8:
    // 0x800798C8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800798CC: nop

    // 0x800798D0: addiu       $t1, $t3, 0x1
    ctx->r9 = ADD32(ctx->r11, 0X1);
    // 0x800798D4: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x800798D8: bne         $at, $zero, L_80079764
    if (ctx->r1 != 0) {
        // 0x800798DC: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_80079764;
    }
    // 0x800798DC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_800798E0:
    // 0x800798E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800798E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800798E8: jr          $ra
    // 0x800798EC: nop

    return;
    // 0x800798EC: nop

;}

RECOMP_FUNC void displayText_DrawWonderProgress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800798F0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800798F4: lb          $t6, -0x7C8($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X7C8);
    // 0x800798F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800798FC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80079900: sw          $t6, -0x304($at)
    MEM_W(-0X304, ctx->r1) = ctx->r14;
    // 0x80079904: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80079908: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007990C: sw          $t7, -0x308($at)
    MEM_W(-0X308, ctx->r1) = ctx->r15;
    // 0x80079910: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x80079914: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80079918: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8007991C: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80079920: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x80079924: beq         $at, $zero, L_80079F3C
    if (ctx->r1 == 0) {
        // 0x80079928: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80079F3C;
    }
    // 0x80079928: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_8007992C:
    // 0x8007992C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80079930: lw          $a0, -0x304($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X304);
    // 0x80079934: jal         0x80046388
    // 0x80079938: nop

    wonders2_GetLinesRemainingToWonder(rdram, ctx);
        goto after_0;
    // 0x80079938: nop

    after_0:
    // 0x8007993C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80079940: sw          $v0, -0x30C($at)
    MEM_W(-0X30C, ctx->r1) = ctx->r2;
    // 0x80079944: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80079948: lw          $t9, -0x30C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X30C);
    // 0x8007994C: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80079950: nop

    // 0x80079954: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x80079958: bne         $at, $zero, L_80079E88
    if (ctx->r1 != 0) {
        // 0x8007995C: nop
    
            goto L_80079E88;
    }
    // 0x8007995C: nop

    // 0x80079960: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80079964: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80079968: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x8007996C: jal         0x8007BCB4
    // 0x80079970: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    SaveData_GetTotalWonderLines(rdram, ctx);
        goto after_1;
    // 0x80079970: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    after_1:
    // 0x80079974: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80079978: lw          $t1, -0x30C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X30C);
    // 0x8007997C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80079980: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x80079984: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80079988: jal         0x8007BC90
    // 0x8007998C: addu        $a1, $s0, $t1
    ctx->r5 = ADD32(ctx->r16, ctx->r9);
    SaveData_SetTotalWonderLines(rdram, ctx);
        goto after_2;
    // 0x8007998C: addu        $a1, $s0, $t1
    ctx->r5 = ADD32(ctx->r16, ctx->r9);
    after_2:
    // 0x80079990: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80079994: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x80079998: jal         0x80079650
    // 0x8007999C: nop

    displayText_FindEntryIndexByXY(rdram, ctx);
        goto after_3;
    // 0x8007999C: nop

    after_3:
    // 0x800799A0: sb          $v0, 0x8F($sp)
    MEM_B(0X8F, ctx->r29) = ctx->r2;
    // 0x800799A4: lb          $t2, 0x8F($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X8F);
    // 0x800799A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800799AC: bne         $t2, $at, L_800799D4
    if (ctx->r10 != ctx->r1) {
        // 0x800799B0: nop
    
            goto L_800799D4;
    }
    // 0x800799B0: nop

    // 0x800799B4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800799B8: lw          $a2, -0x30C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X30C);
    // 0x800799BC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800799C0: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800799C4: jal         0x800796C8
    // 0x800799C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    displayText_InsertEntry(rdram, ctx);
        goto after_4;
    // 0x800799C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x800799CC: b           L_80079A04
    // 0x800799D0: nop

        goto L_80079A04;
    // 0x800799D0: nop

L_800799D4:
    // 0x800799D4: lb          $t4, 0x8F($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X8F);
    // 0x800799D8: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x800799DC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800799E0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800799E4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800799E8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800799EC: lw          $a2, -0x30C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X30C);
    // 0x800799F0: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800799F4: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    // 0x800799F8: addiu       $a1, $a1, 0x1704
    ctx->r5 = ADD32(ctx->r5, 0X1704);
    // 0x800799FC: jal         0x800795D8
    // 0x80079A00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    displayText_CopyEntry(rdram, ctx);
        goto after_5;
    // 0x80079A00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
L_80079A04:
    // 0x80079A04: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
L_80079A08:
    // 0x80079A08: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x80079A0C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80079A10: addu        $t8, $sp, $t6
    ctx->r24 = ADD32(ctx->r29, ctx->r14);
    // 0x80079A14: sb          $t7, 0x78($t8)
    MEM_B(0X78, ctx->r24) = ctx->r15;
    // 0x80079A18: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x80079A1C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80079A20: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80079A24: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80079A28: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80079A2C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80079A30: lw          $t4, 0x1710($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X1710);
    // 0x80079A34: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80079A38: addu        $t5, $sp, $t3
    ctx->r13 = ADD32(ctx->r29, ctx->r11);
    // 0x80079A3C: sw          $t4, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r12;
    // 0x80079A40: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80079A44: nop

    // 0x80079A48: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80079A4C: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x80079A50: bne         $at, $zero, L_80079A08
    if (ctx->r1 != 0) {
        // 0x80079A54: sw          $t6, 0x9C($sp)
        MEM_W(0X9C, ctx->r29) = ctx->r14;
            goto L_80079A08;
    }
    // 0x80079A54: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x80079A58: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
L_80079A5C:
    // 0x80079A5C: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x80079A60: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
L_80079A64:
    // 0x80079A64: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x80079A68: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x80079A6C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80079A70: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80079A74: lw          $t2, 0x28($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X28);
    // 0x80079A78: nop

    // 0x80079A7C: sltu        $at, $t8, $t2
    ctx->r1 = ctx->r24 < ctx->r10 ? 1 : 0;
    // 0x80079A80: beq         $at, $zero, L_80079A98
    if (ctx->r1 == 0) {
        // 0x80079A84: nop
    
            goto L_80079A98;
    }
    // 0x80079A84: nop

    // 0x80079A88: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x80079A8C: sw          $t2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r10;
    // 0x80079A90: addu        $t4, $sp, $t0
    ctx->r12 = ADD32(ctx->r29, ctx->r8);
    // 0x80079A94: sb          $t9, 0x78($t4)
    MEM_B(0X78, ctx->r12) = ctx->r25;
L_80079A98:
    // 0x80079A98: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x80079A9C: nop

    // 0x80079AA0: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80079AA4: slti        $at, $t5, 0x14
    ctx->r1 = SIGNED(ctx->r13) < 0X14 ? 1 : 0;
    // 0x80079AA8: bne         $at, $zero, L_80079A64
    if (ctx->r1 != 0) {
        // 0x80079AAC: sw          $t5, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->r13;
            goto L_80079A64;
    }
    // 0x80079AAC: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
    // 0x80079AB0: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80079AB4: nop

    // 0x80079AB8: addu        $t6, $sp, $t7
    ctx->r14 = ADD32(ctx->r29, ctx->r15);
    // 0x80079ABC: lb          $t6, 0x78($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X78);
    // 0x80079AC0: nop

    // 0x80079AC4: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80079AC8: addu        $t8, $sp, $t1
    ctx->r24 = ADD32(ctx->r29, ctx->r9);
    // 0x80079ACC: sw          $zero, 0x28($t8)
    MEM_W(0X28, ctx->r24) = 0;
    // 0x80079AD0: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x80079AD4: nop

    // 0x80079AD8: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x80079ADC: slti        $at, $t9, 0x14
    ctx->r1 = SIGNED(ctx->r25) < 0X14 ? 1 : 0;
    // 0x80079AE0: bne         $at, $zero, L_80079A5C
    if (ctx->r1 != 0) {
        // 0x80079AE4: sw          $t9, 0x9C($sp)
        MEM_W(0X9C, ctx->r29) = ctx->r25;
            goto L_80079A5C;
    }
    // 0x80079AE4: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x80079AE8: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
L_80079AEC:
    // 0x80079AEC: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
L_80079AF0:
    // 0x80079AF0: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80079AF4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80079AF8: addu        $t3, $sp, $t4
    ctx->r11 = ADD32(ctx->r29, ctx->r12);
    // 0x80079AFC: lb          $t3, 0x78($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X78);
    // 0x80079B00: lw          $t2, -0x304($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X304);
    // 0x80079B04: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80079B08: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x80079B0C: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80079B10: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80079B14: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80079B18: sll         $t9, $t2, 4
    ctx->r25 = S32(ctx->r10 << 4);
    // 0x80079B1C: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x80079B20: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80079B24: subu        $t9, $t9, $t2
    ctx->r25 = SUB32(ctx->r25, ctx->r10);
    // 0x80079B28: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80079B2C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80079B30: addu        $t1, $t7, $t6
    ctx->r9 = ADD32(ctx->r15, ctx->r14);
    // 0x80079B34: lbu         $t8, 0x1704($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1704);
    // 0x80079B38: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80079B3C: addu        $t3, $t0, $t9
    ctx->r11 = ADD32(ctx->r8, ctx->r25);
    // 0x80079B40: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80079B44: addu        $t1, $t7, $t6
    ctx->r9 = ADD32(ctx->r15, ctx->r14);
    // 0x80079B48: sb          $t8, 0x1074($t1)
    MEM_B(0X1074, ctx->r9) = ctx->r24;
    // 0x80079B4C: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x80079B50: nop

    // 0x80079B54: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x80079B58: sltiu       $at, $t0, 0x8
    ctx->r1 = ctx->r8 < 0X8 ? 1 : 0;
    // 0x80079B5C: bne         $at, $zero, L_80079AF0
    if (ctx->r1 != 0) {
        // 0x80079B60: sw          $t0, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r8;
            goto L_80079AF0;
    }
    // 0x80079B60: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    // 0x80079B64: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80079B68: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80079B6C: addu        $t3, $sp, $t4
    ctx->r11 = ADD32(ctx->r29, ctx->r12);
    // 0x80079B70: lb          $t3, 0x78($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X78);
    // 0x80079B74: lw          $t8, -0x304($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X304);
    // 0x80079B78: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80079B7C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80079B80: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80079B84: sll         $t1, $t8, 4
    ctx->r9 = S32(ctx->r24 << 4);
    // 0x80079B88: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80079B8C: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x80079B90: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x80079B94: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80079B98: subu        $t0, $t0, $t4
    ctx->r8 = SUB32(ctx->r8, ctx->r12);
    // 0x80079B9C: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x80079BA0: lbu         $t6, 0x170E($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X170E);
    // 0x80079BA4: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80079BA8: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80079BAC: addu        $t3, $t2, $t0
    ctx->r11 = ADD32(ctx->r10, ctx->r8);
    // 0x80079BB0: sb          $t6, 0x107E($t3)
    MEM_B(0X107E, ctx->r11) = ctx->r14;
    // 0x80079BB4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80079BB8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80079BBC: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x80079BC0: lb          $t8, 0x78($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X78);
    // 0x80079BC4: lw          $t2, -0x304($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X304);
    // 0x80079BC8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80079BCC: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x80079BD0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80079BD4: sll         $t0, $t2, 4
    ctx->r8 = S32(ctx->r10 << 4);
    // 0x80079BD8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80079BDC: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x80079BE0: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x80079BE4: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80079BE8: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x80079BEC: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x80079BF0: lbu         $t4, 0x170F($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X170F);
    // 0x80079BF4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80079BF8: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x80079BFC: addu        $t8, $t6, $t3
    ctx->r24 = ADD32(ctx->r14, ctx->r11);
    // 0x80079C00: sb          $t4, 0x107F($t8)
    MEM_B(0X107F, ctx->r24) = ctx->r12;
    // 0x80079C04: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x80079C08: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80079C0C: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80079C10: lb          $t2, 0x78($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X78);
    // 0x80079C14: lw          $t6, -0x304($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X304);
    // 0x80079C18: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80079C1C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80079C20: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x80079C24: sll         $t3, $t6, 4
    ctx->r11 = S32(ctx->r14 << 4);
    // 0x80079C28: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80079C2C: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80079C30: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x80079C34: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80079C38: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x80079C3C: addu        $t0, $t9, $t5
    ctx->r8 = ADD32(ctx->r25, ctx->r13);
    // 0x80079C40: lw          $t7, 0x1710($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1710);
    // 0x80079C44: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80079C48: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80079C4C: addu        $t2, $t4, $t8
    ctx->r10 = ADD32(ctx->r12, ctx->r24);
    // 0x80079C50: sw          $t7, 0x1080($t2)
    MEM_W(0X1080, ctx->r10) = ctx->r15;
    // 0x80079C54: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x80079C58: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80079C5C: addu        $t6, $sp, $t0
    ctx->r14 = ADD32(ctx->r29, ctx->r8);
    // 0x80079C60: lb          $t6, 0x78($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X78);
    // 0x80079C64: lw          $t4, -0x304($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X304);
    // 0x80079C68: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80079C6C: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x80079C70: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80079C74: sll         $t8, $t4, 4
    ctx->r24 = S32(ctx->r12 << 4);
    // 0x80079C78: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80079C7C: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80079C80: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x80079C84: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80079C88: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x80079C8C: addu        $t3, $t5, $t9
    ctx->r11 = ADD32(ctx->r13, ctx->r25);
    // 0x80079C90: lw          $t1, 0x1714($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X1714);
    // 0x80079C94: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80079C98: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x80079C9C: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x80079CA0: sw          $t1, 0x1084($t6)
    MEM_W(0X1084, ctx->r14) = ctx->r9;
    // 0x80079CA4: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80079CA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80079CAC: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x80079CB0: lb          $t4, 0x78($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X78);
    // 0x80079CB4: lw          $t7, -0x304($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X304);
    // 0x80079CB8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80079CBC: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80079CC0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80079CC4: sll         $t2, $t7, 4
    ctx->r10 = S32(ctx->r15 << 4);
    // 0x80079CC8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80079CCC: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80079CD0: subu        $t2, $t2, $t7
    ctx->r10 = SUB32(ctx->r10, ctx->r15);
    // 0x80079CD4: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80079CD8: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80079CDC: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x80079CE0: lhu         $t0, 0x1718($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X1718);
    // 0x80079CE4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80079CE8: addu        $t1, $t9, $t2
    ctx->r9 = ADD32(ctx->r25, ctx->r10);
    // 0x80079CEC: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x80079CF0: sh          $t0, 0x1088($t4)
    MEM_H(0X1088, ctx->r12) = ctx->r8;
    // 0x80079CF4: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80079CF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80079CFC: addu        $t7, $sp, $t8
    ctx->r15 = ADD32(ctx->r29, ctx->r24);
    // 0x80079D00: lb          $t7, 0x78($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X78);
    // 0x80079D04: lw          $t1, -0x304($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X304);
    // 0x80079D08: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80079D0C: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x80079D10: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80079D14: sll         $t6, $t1, 4
    ctx->r14 = S32(ctx->r9 << 4);
    // 0x80079D18: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80079D1C: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x80079D20: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x80079D24: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80079D28: subu        $t4, $t4, $t8
    ctx->r12 = SUB32(ctx->r12, ctx->r24);
    // 0x80079D2C: addu        $t2, $t5, $t9
    ctx->r10 = ADD32(ctx->r13, ctx->r25);
    // 0x80079D30: lhu         $t3, 0x171A($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X171A);
    // 0x80079D34: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80079D38: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x80079D3C: addu        $t7, $t0, $t4
    ctx->r15 = ADD32(ctx->r8, ctx->r12);
    // 0x80079D40: sh          $t3, 0x108A($t7)
    MEM_H(0X108A, ctx->r15) = ctx->r11;
    // 0x80079D44: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80079D48: nop

    // 0x80079D4C: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80079D50: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x80079D54: bne         $at, $zero, L_80079AEC
    if (ctx->r1 != 0) {
        // 0x80079D58: sw          $t2, 0x9C($sp)
        MEM_W(0X9C, ctx->r29) = ctx->r10;
            goto L_80079AEC;
    }
    // 0x80079D58: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    // 0x80079D5C: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
L_80079D60:
    // 0x80079D60: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
L_80079D64:
    // 0x80079D64: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x80079D68: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x80079D6C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80079D70: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80079D74: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80079D78: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80079D7C: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x80079D80: addu        $t4, $t8, $t0
    ctx->r12 = ADD32(ctx->r24, ctx->r8);
    // 0x80079D84: sb          $zero, 0x1704($t4)
    MEM_B(0X1704, ctx->r12) = 0;
    // 0x80079D88: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x80079D8C: nop

    // 0x80079D90: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x80079D94: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80079D98: bne         $at, $zero, L_80079D64
    if (ctx->r1 != 0) {
        // 0x80079D9C: sw          $t7, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r15;
            goto L_80079D64;
    }
    // 0x80079D9C: sw          $t7, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r15;
    // 0x80079DA0: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x80079DA4: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80079DA8: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80079DAC: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x80079DB0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80079DB4: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x80079DB8: sb          $zero, 0x170E($t1)
    MEM_B(0X170E, ctx->r9) = 0;
    // 0x80079DBC: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80079DC0: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x80079DC4: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80079DC8: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80079DCC: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80079DD0: addu        $t4, $t6, $t0
    ctx->r12 = ADD32(ctx->r14, ctx->r8);
    // 0x80079DD4: sb          $zero, 0x170F($t4)
    MEM_B(0X170F, ctx->r12) = 0;
    // 0x80079DD8: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80079DDC: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x80079DE0: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x80079DE4: subu        $t2, $t2, $t7
    ctx->r10 = SUB32(ctx->r10, ctx->r15);
    // 0x80079DE8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80079DEC: addu        $t9, $t3, $t2
    ctx->r25 = ADD32(ctx->r11, ctx->r10);
    // 0x80079DF0: sw          $zero, 0x1710($t9)
    MEM_W(0X1710, ctx->r25) = 0;
    // 0x80079DF4: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x80079DF8: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x80079DFC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80079E00: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x80079E04: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80079E08: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x80079E0C: sw          $zero, 0x1714($t6)
    MEM_W(0X1714, ctx->r14) = 0;
    // 0x80079E10: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80079E14: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x80079E18: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80079E1C: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x80079E20: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80079E24: addu        $t3, $t0, $t7
    ctx->r11 = ADD32(ctx->r8, ctx->r15);
    // 0x80079E28: sh          $zero, 0x1718($t3)
    MEM_H(0X1718, ctx->r11) = 0;
    // 0x80079E2C: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80079E30: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x80079E34: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80079E38: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x80079E3C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80079E40: addu        $t5, $t2, $t1
    ctx->r13 = ADD32(ctx->r10, ctx->r9);
    // 0x80079E44: sh          $zero, 0x171A($t5)
    MEM_H(0X171A, ctx->r13) = 0;
    // 0x80079E48: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80079E4C: nop

    // 0x80079E50: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80079E54: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x80079E58: bne         $at, $zero, L_80079D60
    if (ctx->r1 != 0) {
        // 0x80079E5C: sw          $t6, 0x9C($sp)
        MEM_W(0X9C, ctx->r29) = ctx->r14;
            goto L_80079D60;
    }
    // 0x80079E5C: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x80079E60: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80079E64: lw          $t4, -0x304($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X304);
    // 0x80079E68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80079E6C: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x80079E70: sw          $t0, -0x304($at)
    MEM_W(-0X304, ctx->r1) = ctx->r8;
    // 0x80079E74: slti        $at, $t0, 0x7
    ctx->r1 = SIGNED(ctx->r8) < 0X7 ? 1 : 0;
    // 0x80079E78: bne         $at, $zero, L_80079F28
    if (ctx->r1 != 0) {
        // 0x80079E7C: nop
    
            goto L_80079F28;
    }
    // 0x80079E7C: nop

    // 0x80079E80: b           L_80079F3C
    // 0x80079E84: nop

        goto L_80079F3C;
    // 0x80079E84: nop

L_80079E88:
    // 0x80079E88: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80079E8C: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x80079E90: jal         0x8007BCB4
    // 0x80079E94: nop

    SaveData_GetTotalWonderLines(rdram, ctx);
        goto after_6;
    // 0x80079E94: nop

    after_6:
    // 0x80079E98: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80079E9C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80079EA0: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x80079EA4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80079EA8: jal         0x8007BC90
    // 0x80079EAC: addu        $a1, $s0, $t7
    ctx->r5 = ADD32(ctx->r16, ctx->r15);
    SaveData_SetTotalWonderLines(rdram, ctx);
        goto after_7;
    // 0x80079EAC: addu        $a1, $s0, $t7
    ctx->r5 = ADD32(ctx->r16, ctx->r15);
    after_7:
    // 0x80079EB0: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80079EB4: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x80079EB8: jal         0x80079650
    // 0x80079EBC: nop

    displayText_FindEntryIndexByXY(rdram, ctx);
        goto after_8;
    // 0x80079EBC: nop

    after_8:
    // 0x80079EC0: sb          $v0, 0x8F($sp)
    MEM_B(0X8F, ctx->r29) = ctx->r2;
    // 0x80079EC4: lb          $t3, 0x8F($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X8F);
    // 0x80079EC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80079ECC: bne         $t3, $at, L_80079EF0
    if (ctx->r11 != ctx->r1) {
        // 0x80079ED0: nop
    
            goto L_80079EF0;
    }
    // 0x80079ED0: nop

    // 0x80079ED4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80079ED8: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x80079EDC: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x80079EE0: jal         0x800796C8
    // 0x80079EE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    displayText_InsertEntry(rdram, ctx);
        goto after_9;
    // 0x80079EE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80079EE8: b           L_80079F1C
    // 0x80079EEC: nop

        goto L_80079F1C;
    // 0x80079EEC: nop

L_80079EF0:
    // 0x80079EF0: lb          $t2, 0x8F($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X8F);
    // 0x80079EF4: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80079EF8: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x80079EFC: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x80079F00: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80079F04: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80079F08: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x80079F0C: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    // 0x80079F10: addiu       $a1, $a1, 0x1704
    ctx->r5 = ADD32(ctx->r5, 0X1704);
    // 0x80079F14: jal         0x800795D8
    // 0x80079F18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    displayText_CopyEntry(rdram, ctx);
        goto after_10;
    // 0x80079F18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
L_80079F1C:
    // 0x80079F1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80079F20: sw          $zero, -0x308($at)
    MEM_W(-0X308, ctx->r1) = 0;
    // 0x80079F24: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
L_80079F28:
    // 0x80079F28: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80079F2C: lw          $t5, -0x308($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X308);
    // 0x80079F30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80079F34: beq         $t5, $at, L_8007992C
    if (ctx->r13 == ctx->r1) {
        // 0x80079F38: nop
    
            goto L_8007992C;
    }
    // 0x80079F38: nop

L_80079F3C:
    // 0x80079F3C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80079F40: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x80079F44: jal         0x8007BCB4
    // 0x80079F48: nop

    SaveData_GetTotalWonderLines(rdram, ctx);
        goto after_11;
    // 0x80079F48: nop

    after_11:
    // 0x80079F4C: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80079F50: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80079F54: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x80079F58: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80079F5C: jal         0x8007BC90
    // 0x80079F60: addu        $a1, $s0, $t8
    ctx->r5 = ADD32(ctx->r16, ctx->r24);
    SaveData_SetTotalWonderLines(rdram, ctx);
        goto after_12;
    // 0x80079F60: addu        $a1, $s0, $t8
    ctx->r5 = ADD32(ctx->r16, ctx->r24);
    after_12:
    // 0x80079F64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80079F68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80079F6C: jr          $ra
    // 0x80079F70: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80079F70: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}

RECOMP_FUNC void displayText_GetEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079F74: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80079F78: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x80079F7C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80079F80: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80079F84: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x80079F88: jr          $ra
    // 0x80079F8C: addiu       $v0, $v0, 0x1074
    ctx->r2 = ADD32(ctx->r2, 0X1074);
    return;
    // 0x80079F8C: addiu       $v0, $v0, 0x1074
    ctx->r2 = ADD32(ctx->r2, 0X1074);
;}

RECOMP_FUNC void displayText_AddEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079F90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80079F94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80079F98: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80079F9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079FA0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80079FA4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80079FA8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80079FAC: nop

    // 0x80079FB0: beq         $t7, $t6, L_8007A020
    if (ctx->r15 == ctx->r14) {
        // 0x80079FB4: nop
    
            goto L_8007A020;
    }
    // 0x80079FB4: nop

L_80079FB8:
    // 0x80079FB8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80079FBC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80079FC0: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x80079FC4: lbu         $t1, 0x9($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X9);
    // 0x80079FC8: nop

    // 0x80079FCC: bne         $t9, $t1, L_80079FFC
    if (ctx->r25 != ctx->r9) {
        // 0x80079FD0: nop
    
            goto L_80079FFC;
    }
    // 0x80079FD0: nop

    // 0x80079FD4: lbu         $t2, 0xA($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0XA);
    // 0x80079FD8: lbu         $t3, 0xA($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XA);
    // 0x80079FDC: nop

    // 0x80079FE0: bne         $t2, $t3, L_80079FFC
    if (ctx->r10 != ctx->r11) {
        // 0x80079FE4: nop
    
            goto L_80079FFC;
    }
    // 0x80079FE4: nop

    // 0x80079FE8: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x80079FEC: jal         0x8007B420
    // 0x80079FF0: nop

    displayText_DeserializeTable(rdram, ctx);
        goto after_0;
    // 0x80079FF0: nop

    after_0:
    // 0x80079FF4: b           L_8007A068
    // 0x80079FF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007A068;
    // 0x80079FF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80079FFC:
    // 0x80079FFC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A000: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007A004: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x8007A008: nop

    // 0x8007A00C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8007A010: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8007A014: nop

    // 0x8007A018: bne         $t7, $t6, L_80079FB8
    if (ctx->r15 != ctx->r14) {
        // 0x8007A01C: nop
    
            goto L_80079FB8;
    }
    // 0x8007A01C: nop

L_8007A020:
    // 0x8007A020: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8007A024: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8007A028: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8007A02C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007A030: sw          $t1, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r9;
    // 0x8007A034: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8007A038: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007A03C: nop

    // 0x8007A040: sw          $t2, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r10;
    // 0x8007A044: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007A048: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8007A04C: nop

    // 0x8007A050: sw          $t0, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r8;
    // 0x8007A054: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007A058: nop

    // 0x8007A05C: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8007A060: nop

    // 0x8007A064: sw          $t5, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r13;
L_8007A068:
    // 0x8007A068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A06C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007A070: jr          $ra
    // 0x8007A074: nop

    return;
    // 0x8007A074: nop

;}

RECOMP_FUNC void displayText_SaveSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A078: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007A07C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007A080: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007A084: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007A088: addiu       $t6, $t6, 0x2D98
    ctx->r14 = ADD32(ctx->r14, 0X2D98);
    // 0x8007A08C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007A090: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8007A094: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007A098: beq         $t6, $t7, L_8007A0B0
    if (ctx->r14 == ctx->r15) {
        // 0x8007A09C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8007A0B0;
    }
    // 0x8007A09C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007A0A0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8007A0A4: addiu       $t8, $t8, 0x2D80
    ctx->r24 = ADD32(ctx->r24, 0X2D80);
    // 0x8007A0A8: bne         $t8, $t7, L_8007A2C8
    if (ctx->r24 != ctx->r15) {
        // 0x8007A0AC: nop
    
            goto L_8007A2C8;
    }
    // 0x8007A0AC: nop

L_8007A0B0:
    // 0x8007A0B0: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
    // 0x8007A0B4: jal         0x8007E03C
    // 0x8007A0B8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8007A0B8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_0:
    // 0x8007A0BC: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8007A0C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A0C4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8007A0C8: sb          $t9, -0x300($at)
    MEM_B(-0X300, ctx->r1) = ctx->r25;
    // 0x8007A0CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007A0D0: jal         0x800A35EC
    // 0x8007A0D4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    Scene_RandRange(rdram, ctx);
        goto after_1;
    // 0x8007A0D4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_1:
    // 0x8007A0D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007A0DC: lbu         $t0, -0x1108($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X1108);
    // 0x8007A0E0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8007A0E4: slti        $at, $t0, 0x7
    ctx->r1 = SIGNED(ctx->r8) < 0X7 ? 1 : 0;
    // 0x8007A0E8: beq         $at, $zero, L_8007A0F8
    if (ctx->r1 == 0) {
        // 0x8007A0EC: nop
    
            goto L_8007A0F8;
    }
    // 0x8007A0EC: nop

    // 0x8007A0F0: b           L_8007A0FC
    // 0x8007A0F4: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
        goto L_8007A0FC;
    // 0x8007A0F4: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
L_8007A0F8:
    // 0x8007A0F8: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_8007A0FC:
    // 0x8007A0FC: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x8007A100: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8007A104: lhu         $t5, 0x2E1C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X2E1C);
    // 0x8007A108: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007A10C: bne         $s0, $zero, L_8007A118
    if (ctx->r16 != 0) {
        // 0x8007A110: nop
    
            goto L_8007A118;
    }
    // 0x8007A110: nop

    // 0x8007A114: break       7
    do_break(2147983636);
L_8007A118:
    // 0x8007A118: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007A11C: bne         $s0, $at, L_8007A130
    if (ctx->r16 != ctx->r1) {
        // 0x8007A120: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007A130;
    }
    // 0x8007A120: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007A124: bne         $s1, $at, L_8007A130
    if (ctx->r17 != ctx->r1) {
        // 0x8007A128: nop
    
            goto L_8007A130;
    }
    // 0x8007A128: nop

    // 0x8007A12C: break       6
    do_break(2147983660);
L_8007A130:
    // 0x8007A130: mfhi        $t1
    ctx->r9 = hi;
    // 0x8007A134: sh          $t1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r9;
    // 0x8007A138: lhu         $t2, 0x2A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2A);
    // 0x8007A13C: nop

    // 0x8007A140: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x8007A144: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8007A148: beq         $t6, $zero, L_8007A1F8
    if (ctx->r14 == 0) {
        // 0x8007A14C: nop
    
            goto L_8007A1F8;
    }
    // 0x8007A14C: nop

L_8007A150:
    // 0x8007A150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007A154: jal         0x800A35EC
    // 0x8007A158: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    Scene_RandRange(rdram, ctx);
        goto after_2;
    // 0x8007A158: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_2:
    // 0x8007A15C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007A160: lbu         $t8, -0x1108($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X1108);
    // 0x8007A164: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8007A168: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x8007A16C: beq         $at, $zero, L_8007A17C
    if (ctx->r1 == 0) {
        // 0x8007A170: nop
    
            goto L_8007A17C;
    }
    // 0x8007A170: nop

    // 0x8007A174: b           L_8007A180
    // 0x8007A178: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
        goto L_8007A180;
    // 0x8007A178: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
L_8007A17C:
    // 0x8007A17C: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_8007A180:
    // 0x8007A180: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x8007A184: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007A188: bne         $s0, $zero, L_8007A194
    if (ctx->r16 != 0) {
        // 0x8007A18C: nop
    
            goto L_8007A194;
    }
    // 0x8007A18C: nop

    // 0x8007A190: break       7
    do_break(2147983760);
L_8007A194:
    // 0x8007A194: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007A198: bne         $s0, $at, L_8007A1AC
    if (ctx->r16 != ctx->r1) {
        // 0x8007A19C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007A1AC;
    }
    // 0x8007A19C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007A1A0: bne         $s1, $at, L_8007A1AC
    if (ctx->r17 != ctx->r1) {
        // 0x8007A1A4: nop
    
            goto L_8007A1AC;
    }
    // 0x8007A1A4: nop

    // 0x8007A1A8: break       6
    do_break(2147983784);
L_8007A1AC:
    // 0x8007A1AC: lbu         $t9, -0x300($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X300);
    // 0x8007A1B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A1B4: sltiu       $s0, $t9, 0x1
    ctx->r16 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007A1B8: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8007A1BC: sb          $t0, -0x300($at)
    MEM_B(-0X300, ctx->r1) = ctx->r8;
    // 0x8007A1C0: mfhi        $t7
    ctx->r15 = hi;
    // 0x8007A1C4: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    // 0x8007A1C8: beq         $s0, $zero, L_8007A1D8
    if (ctx->r16 == 0) {
        // 0x8007A1CC: nop
    
            goto L_8007A1D8;
    }
    // 0x8007A1CC: nop

    // 0x8007A1D0: b           L_8007A1F8
    // 0x8007A1D4: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
        goto L_8007A1F8;
    // 0x8007A1D4: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
L_8007A1D8:
    // 0x8007A1D8: lhu         $t1, 0x2A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2A);
    // 0x8007A1DC: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8007A1E0: lhu         $t4, 0x2E1C($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X2E1C);
    // 0x8007A1E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007A1E8: sllv        $t2, $t3, $t1
    ctx->r10 = S32(ctx->r11 << (ctx->r9 & 31));
    // 0x8007A1EC: and         $t5, $t2, $t4
    ctx->r13 = ctx->r10 & ctx->r12;
    // 0x8007A1F0: bne         $t5, $zero, L_8007A150
    if (ctx->r13 != 0) {
        // 0x8007A1F4: nop
    
            goto L_8007A150;
    }
    // 0x8007A1F4: nop

L_8007A1F8:
    // 0x8007A1F8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007A1FC: lbu         $t3, -0x1108($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X1108);
    // 0x8007A200: lhu         $t8, 0x2A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2A);
    // 0x8007A204: sll         $t1, $t3, 3
    ctx->r9 = S32(ctx->r11 << 3);
    // 0x8007A208: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x8007A20C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007A210: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007A214: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x8007A218: lhu         $t6, 0x2E1C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X2E1C);
    // 0x8007A21C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007A220: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8007A224: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8007A228: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8007A22C: sllv        $t9, $t7, $t8
    ctx->r25 = S32(ctx->r15 << (ctx->r24 & 31));
    // 0x8007A230: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007A234: lw          $a2, 0x2E20($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2E20);
    // 0x8007A238: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A23C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007A240: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x8007A244: sh          $t0, 0x2E1C($at)
    MEM_H(0X2E1C, ctx->r1) = ctx->r8;
    // 0x8007A248: jal         0x800B62D4
    // 0x8007A24C: addiu       $a1, $a1, -0x21FC
    ctx->r5 = ADD32(ctx->r5, -0X21FC);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8007A24C: addiu       $a1, $a1, -0x21FC
    ctx->r5 = ADD32(ctx->r5, -0X21FC);
    after_3:
    // 0x8007A250: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A254: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007A258: sb          $zero, 0x9($t5)
    MEM_B(0X9, ctx->r13) = 0;
    // 0x8007A25C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A260: nop

    // 0x8007A264: sb          $zero, 0xA($t7)
    MEM_B(0XA, ctx->r15) = 0;
    // 0x8007A268: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x8007A26C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A270: sllv        $t0, $t9, $t6
    ctx->r8 = S32(ctx->r25 << (ctx->r14 & 31));
    // 0x8007A274: sll         $t3, $t0, 4
    ctx->r11 = S32(ctx->r8 << 4);
    // 0x8007A278: ori         $t8, $t3, 0xE
    ctx->r24 = ctx->r11 | 0XE;
    // 0x8007A27C: sb          $t8, 0xB($t1)
    MEM_B(0XB, ctx->r9) = ctx->r24;
    // 0x8007A280: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A284: nop

    // 0x8007A288: sw          $zero, 0x10($t2)
    MEM_W(0X10, ctx->r10) = 0;
    // 0x8007A28C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A290: nop

    // 0x8007A294: sw          $zero, 0x14($t4)
    MEM_W(0X14, ctx->r12) = 0;
    // 0x8007A298: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A29C: nop

    // 0x8007A2A0: sw          $zero, 0xC($t5)
    MEM_W(0XC, ctx->r13) = 0;
    // 0x8007A2A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A2A8: lbu         $a0, 0x37($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X37);
    // 0x8007A2AC: jal         0x8007AB10
    // 0x8007A2B0: nop

    displayText_SetSlotData(rdram, ctx);
        goto after_4;
    // 0x8007A2B0: nop

    after_4:
    // 0x8007A2B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A2B8: jal         0x8007E328
    // 0x8007A2BC: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_5;
    // 0x8007A2BC: nop

    after_5:
    // 0x8007A2C0: b           L_8007A48C
    // 0x8007A2C4: nop

        goto L_8007A48C;
    // 0x8007A2C4: nop

L_8007A2C8:
    // 0x8007A2C8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007A2CC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A2D0: lbu         $t9, 0xB($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0XB);
    // 0x8007A2D4: nop

    // 0x8007A2D8: sra         $t6, $t9, 4
    ctx->r14 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8007A2DC: andi        $t0, $t6, 0xF
    ctx->r8 = ctx->r14 & 0XF;
    // 0x8007A2E0: sb          $t0, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r8;
    // 0x8007A2E4: lbu         $s0, 0xB($t7)
    ctx->r16 = MEM_BU(ctx->r15, 0XB);
    // 0x8007A2E8: nop

    // 0x8007A2EC: andi        $t3, $s0, 0xF
    ctx->r11 = ctx->r16 & 0XF;
    // 0x8007A2F0: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x8007A2F4: beq         $s0, $at, L_8007A34C
    if (ctx->r16 == ctx->r1) {
        // 0x8007A2F8: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8007A34C;
    }
    // 0x8007A2F8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8007A2FC: beq         $s0, $at, L_8007A450
    if (ctx->r16 == ctx->r1) {
        // 0x8007A300: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_8007A450;
    }
    // 0x8007A300: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8007A304: bne         $s0, $at, L_8007A48C
    if (ctx->r16 != ctx->r1) {
        // 0x8007A308: nop
    
            goto L_8007A48C;
    }
    // 0x8007A308: nop

    // 0x8007A30C: lbu         $a0, 0x37($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X37);
    // 0x8007A310: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8007A314: jal         0x8007AB10
    // 0x8007A318: nop

    displayText_SetSlotData(rdram, ctx);
        goto after_6;
    // 0x8007A318: nop

    after_6:
    // 0x8007A31C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007A320: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007A324: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8007A328: nop

    // 0x8007A32C: sb          $t8, 0xD0($t2)
    MEM_B(0XD0, ctx->r10) = ctx->r24;
    // 0x8007A330: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007A334: nop

    // 0x8007A338: lbu         $t5, 0xB($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0XB);
    // 0x8007A33C: nop

    // 0x8007A340: andi        $t9, $t5, 0xF
    ctx->r25 = ctx->r13 & 0XF;
    // 0x8007A344: b           L_8007A48C
    // 0x8007A348: sb          $t9, 0xB($t4)
    MEM_B(0XB, ctx->r12) = ctx->r25;
        goto L_8007A48C;
    // 0x8007A348: sb          $t9, 0xB($t4)
    MEM_B(0XB, ctx->r12) = ctx->r25;
L_8007A34C:
    // 0x8007A34C: lbu         $t6, 0x29($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X29);
    // 0x8007A350: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8007A354: sll         $t0, $t6, 4
    ctx->r8 = S32(ctx->r14 << 4);
    // 0x8007A358: ori         $t7, $t0, 0xD
    ctx->r15 = ctx->r8 | 0XD;
    // 0x8007A35C: sb          $t7, 0xB($t3)
    MEM_B(0XB, ctx->r11) = ctx->r15;
    // 0x8007A360: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007A364: lbu         $t1, 0x29($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X29);
    // 0x8007A368: lw          $t9, 0xC($t5)
    ctx->r25 = MEM_W(ctx->r13, 0XC);
    // 0x8007A36C: sll         $t8, $t1, 4
    ctx->r24 = S32(ctx->r9 << 4);
    // 0x8007A370: ori         $t2, $t8, 0xD
    ctx->r10 = ctx->r24 | 0XD;
    // 0x8007A374: sb          $t2, 0xD4($t9)
    MEM_B(0XD4, ctx->r25) = ctx->r10;
    // 0x8007A378: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007A37C: nop

    // 0x8007A380: lbu         $t6, 0x9($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X9);
    // 0x8007A384: lw          $t0, 0xC($t4)
    ctx->r8 = MEM_W(ctx->r12, 0XC);
    // 0x8007A388: nop

    // 0x8007A38C: sb          $t6, 0x9($t0)
    MEM_B(0X9, ctx->r8) = ctx->r14;
    // 0x8007A390: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007A394: nop

    // 0x8007A398: lbu         $t3, 0xA($t7)
    ctx->r11 = MEM_BU(ctx->r15, 0XA);
    // 0x8007A39C: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x8007A3A0: nop

    // 0x8007A3A4: sb          $t3, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r11;
    // 0x8007A3A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8007A3AC: lbu         $a0, 0x37($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X37);
    // 0x8007A3B0: jal         0x8007AB10
    // 0x8007A3B4: nop

    displayText_SetSlotData(rdram, ctx);
        goto after_7;
    // 0x8007A3B4: nop

    after_7:
    // 0x8007A3B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007A3BC: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x8007A3C0: jal         0x8007A5D4
    // 0x8007A3C4: nop

    displayText_FindFirstSetBit(rdram, ctx);
        goto after_8;
    // 0x8007A3C4: nop

    after_8:
    // 0x8007A3C8: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x8007A3CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007A3D0: sll         $t5, $t8, 3
    ctx->r13 = S32(ctx->r24 << 3);
    // 0x8007A3D4: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x8007A3D8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007A3DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A3E0: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x8007A3E4: lw          $a1, -0x310($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X310);
    // 0x8007A3E8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8007A3EC: sll         $a2, $s0, 4
    ctx->r6 = S32(ctx->r16 << 4);
    // 0x8007A3F0: ori         $at, $zero, 0xE13C
    ctx->r1 = 0 | 0XE13C;
    // 0x8007A3F4: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8007A3F8: addiu       $t9, $t9, 0xA00
    ctx->r25 = ADD32(ctx->r25, 0XA00);
    // 0x8007A3FC: addu        $t2, $t5, $at
    ctx->r10 = ADD32(ctx->r13, ctx->r1);
    // 0x8007A400: subu        $a2, $a2, $s0
    ctx->r6 = SUB32(ctx->r6, ctx->r16);
    // 0x8007A404: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x8007A408: addu        $a0, $t2, $t9
    ctx->r4 = ADD32(ctx->r10, ctx->r25);
    // 0x8007A40C: jal         0x8007AF88
    // 0x8007A410: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    displayText_EncodeEntry(rdram, ctx);
        goto after_9;
    // 0x8007A410: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_9:
    // 0x8007A414: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007A418: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x8007A41C: jal         0x8007A5D4
    // 0x8007A420: nop

    displayText_FindFirstSetBit(rdram, ctx);
        goto after_10;
    // 0x8007A420: nop

    after_10:
    // 0x8007A424: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007A428: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x8007A42C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007A430: jal         0x8007A648
    // 0x8007A434: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    displayText_SetBit(rdram, ctx);
        goto after_11;
    // 0x8007A434: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x8007A438: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007A43C: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x8007A440: jal         0x8007C5CC
    // 0x8007A444: nop

    SaveData_Save(rdram, ctx);
        goto after_12;
    // 0x8007A444: nop

    after_12:
    // 0x8007A448: b           L_8007A48C
    // 0x8007A44C: nop

        goto L_8007A48C;
    // 0x8007A44C: nop

L_8007A450:
    // 0x8007A450: lbu         $a0, 0x37($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X37);
    // 0x8007A454: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8007A458: jal         0x8007AB10
    // 0x8007A45C: nop

    displayText_SetSlotData(rdram, ctx);
        goto after_13;
    // 0x8007A45C: nop

    after_13:
    // 0x8007A460: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007A464: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007A468: lbu         $t6, 0xB($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0XB);
    // 0x8007A46C: nop

    // 0x8007A470: andi        $t0, $t6, 0xF
    ctx->r8 = ctx->r14 & 0XF;
    // 0x8007A474: sb          $t0, 0xB($t4)
    MEM_B(0XB, ctx->r12) = ctx->r8;
    // 0x8007A478: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8007A47C: nop

    // 0x8007A480: lw          $t1, 0xC($t3)
    ctx->r9 = MEM_W(ctx->r11, 0XC);
    // 0x8007A484: nop

    // 0x8007A488: sb          $t7, 0xD0($t1)
    MEM_B(0XD0, ctx->r9) = ctx->r15;
L_8007A48C:
    // 0x8007A48C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A490: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007A494: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007A498: jr          $ra
    // 0x8007A49C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007A49C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void displayText_FindClearTableBit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A4A0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007A4A4: lw          $t6, 0x1F10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F10);
    // 0x8007A4A8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007A4AC: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8007A4B0: lbu         $t8, -0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, -0X1);
    // 0x8007A4B4: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x8007A4B8: sb          $t8, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r24;
L_8007A4BC:
    // 0x8007A4BC: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8007A4C0: lbu         $t9, 0x7($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X7);
    // 0x8007A4C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007A4C8: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x8007A4CC: and         $t3, $t9, $t2
    ctx->r11 = ctx->r25 & ctx->r10;
    // 0x8007A4D0: bne         $t3, $zero, L_8007A4E4
    if (ctx->r11 != 0) {
        // 0x8007A4D4: nop
    
            goto L_8007A4E4;
    }
    // 0x8007A4D4: nop

    // 0x8007A4D8: lb          $v0, 0x3($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X3);
    // 0x8007A4DC: b           L_8007A500
    // 0x8007A4E0: nop

        goto L_8007A500;
    // 0x8007A4E0: nop

L_8007A4E4:
    // 0x8007A4E4: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8007A4E8: nop

    // 0x8007A4EC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007A4F0: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x8007A4F4: bne         $at, $zero, L_8007A4BC
    if (ctx->r1 != 0) {
        // 0x8007A4F8: sw          $t5, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r13;
            goto L_8007A4BC;
    }
    // 0x8007A4F8: sw          $t5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r13;
    // 0x8007A4FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007A500:
    // 0x8007A500: jr          $ra
    // 0x8007A504: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007A504: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void displayText_ClearTableBit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A508: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007A50C: lw          $t6, 0x1F10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F10);
    // 0x8007A510: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8007A514: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007A518: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8007A51C: lbu         $t8, -0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, -0X1);
    // 0x8007A520: sllv        $t0, $t9, $a1
    ctx->r8 = S32(ctx->r25 << (ctx->r5 & 31));
    // 0x8007A524: nor         $t1, $t0, $zero
    ctx->r9 = ~(ctx->r8 | 0);
    // 0x8007A528: addu        $t3, $a0, $t6
    ctx->r11 = ADD32(ctx->r4, ctx->r14);
    // 0x8007A52C: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8007A530: jr          $ra
    // 0x8007A534: sb          $t2, -0x1($t3)
    MEM_B(-0X1, ctx->r11) = ctx->r10;
    return;
    // 0x8007A534: sb          $t2, -0x1($t3)
    MEM_B(-0X1, ctx->r11) = ctx->r10;
;}

RECOMP_FUNC void displayText_SetTableBit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A538: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007A53C: lw          $t6, 0x1F10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F10);
    // 0x8007A540: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8007A544: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8007A548: lbu         $t8, -0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, -0X1);
    // 0x8007A54C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007A550: sllv        $t0, $t9, $a1
    ctx->r8 = S32(ctx->r25 << (ctx->r5 & 31));
    // 0x8007A554: addu        $t2, $a0, $t6
    ctx->r10 = ADD32(ctx->r4, ctx->r14);
    // 0x8007A558: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8007A55C: jr          $ra
    // 0x8007A560: sb          $t1, -0x1($t2)
    MEM_B(-0X1, ctx->r10) = ctx->r9;
    return;
    // 0x8007A560: sb          $t1, -0x1($t2)
    MEM_B(-0X1, ctx->r10) = ctx->r9;
;}

RECOMP_FUNC void displayText_CountSetBits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A564: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007A568: lw          $t6, 0x1F10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F10);
    // 0x8007A56C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8007A570: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8007A574: lbu         $t8, -0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, -0X1);
    // 0x8007A578: sb          $zero, 0x7($sp)
    MEM_B(0X7, ctx->r29) = 0;
    // 0x8007A57C: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8007A580: sb          $t8, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r24;
L_8007A584:
    // 0x8007A584: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x8007A588: lbu         $t9, 0xF($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XF);
    // 0x8007A58C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007A590: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x8007A594: and         $t3, $t9, $t2
    ctx->r11 = ctx->r25 & ctx->r10;
    // 0x8007A598: beq         $t3, $zero, L_8007A5B0
    if (ctx->r11 == 0) {
        // 0x8007A59C: nop
    
            goto L_8007A5B0;
    }
    // 0x8007A59C: nop

    // 0x8007A5A0: lbu         $t4, 0x7($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X7);
    // 0x8007A5A4: nop

    // 0x8007A5A8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007A5AC: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
L_8007A5B0:
    // 0x8007A5B0: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8007A5B4: nop

    // 0x8007A5B8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007A5BC: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x8007A5C0: bne         $at, $zero, L_8007A584
    if (ctx->r1 != 0) {
        // 0x8007A5C4: sw          $t7, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r15;
            goto L_8007A584;
    }
    // 0x8007A5C4: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8007A5C8: lbu         $v0, 0x7($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X7);
    // 0x8007A5CC: jr          $ra
    // 0x8007A5D0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007A5D0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void displayText_FindFirstSetBit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A5D4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007A5D8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007A5DC: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x8007A5E0: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_8007A5E4:
    // 0x8007A5E4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8007A5E8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8007A5EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007A5F0: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x8007A5F4: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8007A5F8: bne         $t1, $zero, L_8007A608
    if (ctx->r9 != 0) {
        // 0x8007A5FC: nop
    
            goto L_8007A608;
    }
    // 0x8007A5FC: nop

    // 0x8007A600: b           L_8007A624
    // 0x8007A604: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8007A624;
    // 0x8007A604: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8007A608:
    // 0x8007A608: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8007A60C: nop

    // 0x8007A610: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007A614: slti        $at, $t3, 0x20
    ctx->r1 = SIGNED(ctx->r11) < 0X20 ? 1 : 0;
    // 0x8007A618: bne         $at, $zero, L_8007A5E4
    if (ctx->r1 != 0) {
        // 0x8007A61C: sw          $t3, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r11;
            goto L_8007A5E4;
    }
    // 0x8007A61C: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x8007A620: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007A624:
    // 0x8007A624: jr          $ra
    // 0x8007A628: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007A628: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void displayText_ClearBit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A62C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007A630: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007A634: sllv        $t8, $t7, $a1
    ctx->r24 = S32(ctx->r15 << (ctx->r5 & 31));
    // 0x8007A638: nor         $t9, $t8, $zero
    ctx->r25 = ~(ctx->r24 | 0);
    // 0x8007A63C: and         $t0, $t6, $t9
    ctx->r8 = ctx->r14 & ctx->r25;
    // 0x8007A640: jr          $ra
    // 0x8007A644: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    return;
    // 0x8007A644: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
;}

RECOMP_FUNC void displayText_SetBit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A648: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007A64C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007A650: sllv        $t8, $t7, $a1
    ctx->r24 = S32(ctx->r15 << (ctx->r5 & 31));
    // 0x8007A654: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8007A658: jr          $ra
    // 0x8007A65C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    return;
    // 0x8007A65C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
;}

RECOMP_FUNC void displayText_CountSetBitsInWord(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A660: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007A664: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8007A668: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8007A66C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x8007A670: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
L_8007A674:
    // 0x8007A674: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8007A678: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8007A67C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007A680: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x8007A684: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8007A688: beq         $t1, $zero, L_8007A6A0
    if (ctx->r9 == 0) {
        // 0x8007A68C: nop
    
            goto L_8007A6A0;
    }
    // 0x8007A68C: nop

    // 0x8007A690: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8007A694: nop

    // 0x8007A698: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007A69C: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_8007A6A0:
    // 0x8007A6A0: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x8007A6A4: nop

    // 0x8007A6A8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007A6AC: sltiu       $at, $t5, 0x20
    ctx->r1 = ctx->r13 < 0X20 ? 1 : 0;
    // 0x8007A6B0: bne         $at, $zero, L_8007A674
    if (ctx->r1 != 0) {
        // 0x8007A6B4: sw          $t5, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r13;
            goto L_8007A674;
    }
    // 0x8007A6B4: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x8007A6B8: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8007A6BC: jr          $ra
    // 0x8007A6C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007A6C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void displayText_InitEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A6C4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007A6C8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8007A6CC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8007A6D0:
    // 0x8007A6D0: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007A6D4: nop

    // 0x8007A6D8: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8007A6DC: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8007A6E0: addu        $t9, $a1, $t6
    ctx->r25 = ADD32(ctx->r5, ctx->r14);
    // 0x8007A6E4: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8007A6E8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8007A6EC: nop

    // 0x8007A6F0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007A6F4: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x8007A6F8: bne         $at, $zero, L_8007A6D0
    if (ctx->r1 != 0) {
        // 0x8007A6FC: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_8007A6D0;
    }
    // 0x8007A6FC: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8007A700: sb          $zero, 0x8($a1)
    MEM_B(0X8, ctx->r5) = 0;
    // 0x8007A704: lbu         $t2, 0x9($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X9);
    // 0x8007A708: nop

    // 0x8007A70C: sb          $t2, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r10;
    // 0x8007A710: lbu         $t3, 0xA($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA);
    // 0x8007A714: sw          $a0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r4;
    // 0x8007A718: lw          $t4, 0xC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XC);
    // 0x8007A71C: sb          $a2, 0xB($a1)
    MEM_B(0XB, ctx->r5) = ctx->r6;
    // 0x8007A720: sb          $t3, 0xA($a1)
    MEM_B(0XA, ctx->r5) = ctx->r11;
    // 0x8007A724: sb          $a2, 0xD4($t4)
    MEM_B(0XD4, ctx->r12) = ctx->r6;
    // 0x8007A728: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x8007A72C: sw          $zero, 0x14($a1)
    MEM_W(0X14, ctx->r5) = 0;
    // 0x8007A730: jr          $ra
    // 0x8007A734: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007A734: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void displayText_AddTimestampedEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A738: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007A73C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A740: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8007A744: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8007A748: jal         0x8007E03C
    // 0x8007A74C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8007A74C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_0:
    // 0x8007A750: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8007A754: jal         0x8007E03C
    // 0x8007A758: addiu       $a0, $zero, 0xD8
    ctx->r4 = ADD32(0, 0XD8);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8007A758: addiu       $a0, $zero, 0xD8
    ctx->r4 = ADD32(0, 0XD8);
    after_1:
    // 0x8007A75C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007A760: nop

    // 0x8007A764: sw          $v0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r2;
    // 0x8007A768: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007A76C: nop

    // 0x8007A770: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8007A774: jal         0x800B6550
    // 0x8007A778: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    osGetTime_recomp(rdram, ctx);
        goto after_2;
    // 0x8007A778: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_2:
    // 0x8007A77C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007A780: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8007A784: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A788: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007A78C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007A790: jal         0x800B7658
    // 0x8007A794: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_3;
    // 0x8007A794: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_3:
    // 0x8007A798: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007A79C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8007A7A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8007A7A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007A7A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007A7AC: jal         0x800B7558
    // 0x8007A7B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    __ull_div_recomp(rdram, ctx);
        goto after_4;
    // 0x8007A7B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_4:
    // 0x8007A7B4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007A7B8: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
    // 0x8007A7BC: srl         $t0, $t9, 4
    ctx->r8 = S32(U32(ctx->r25) >> 4);
    // 0x8007A7C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007A7C4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8007A7C8: jal         0x800A35EC
    // 0x8007A7CC: sb          $t0, 0x9($t1)
    MEM_B(0X9, ctx->r9) = ctx->r8;
    Scene_RandRange(rdram, ctx);
        goto after_5;
    // 0x8007A7CC: sb          $t0, 0x9($t1)
    MEM_B(0X9, ctx->r9) = ctx->r8;
    after_5:
    // 0x8007A7D0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007A7D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007A7D8: sb          $v0, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r2;
    // 0x8007A7DC: lbu         $t3, 0x3F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3F);
    // 0x8007A7E0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007A7E4: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x8007A7E8: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8007A7EC: ori         $t7, $t6, 0xB
    ctx->r15 = ctx->r14 | 0XB;
    // 0x8007A7F0: sb          $t7, 0xB($t8)
    MEM_B(0XB, ctx->r24) = ctx->r15;
    // 0x8007A7F4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007A7F8: addiu       $t9, $zero, 0x41
    ctx->r25 = ADD32(0, 0X41);
    // 0x8007A7FC: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x8007A800: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007A804: nop

    // 0x8007A808: sb          $zero, 0x1($t1)
    MEM_B(0X1, ctx->r9) = 0;
    // 0x8007A80C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007A810: nop

    // 0x8007A814: sb          $zero, 0x2($t2)
    MEM_B(0X2, ctx->r10) = 0;
    // 0x8007A818: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007A81C: nop

    // 0x8007A820: sb          $zero, 0x3($t4)
    MEM_B(0X3, ctx->r12) = 0;
    // 0x8007A824: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8007A828: nop

    // 0x8007A82C: sb          $zero, 0x4($t3)
    MEM_B(0X4, ctx->r11) = 0;
    // 0x8007A830: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007A834: nop

    // 0x8007A838: sb          $zero, 0x5($t5)
    MEM_B(0X5, ctx->r13) = 0;
    // 0x8007A83C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007A840: nop

    // 0x8007A844: sb          $zero, 0x6($t6)
    MEM_B(0X6, ctx->r14) = 0;
    // 0x8007A848: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007A84C: nop

    // 0x8007A850: sb          $zero, 0x7($t7)
    MEM_B(0X7, ctx->r15) = 0;
    // 0x8007A854: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007A858: nop

    // 0x8007A85C: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
    // 0x8007A860: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007A864: nop

    // 0x8007A868: sw          $zero, 0x10($t9)
    MEM_W(0X10, ctx->r25) = 0;
    // 0x8007A86C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007A870: nop

    // 0x8007A874: sw          $zero, 0x14($t0)
    MEM_W(0X14, ctx->r8) = 0;
    // 0x8007A878: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007A87C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A880: lbu         $t2, 0x9($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X9);
    // 0x8007A884: nop

    // 0x8007A888: sb          $t2, 0x9($t4)
    MEM_B(0X9, ctx->r12) = ctx->r10;
    // 0x8007A88C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8007A890: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A894: lbu         $t5, 0xA($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0XA);
    // 0x8007A898: nop

    // 0x8007A89C: sb          $t5, 0xA($t6)
    MEM_B(0XA, ctx->r14) = ctx->r13;
    // 0x8007A8A0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A8A4: nop

    // 0x8007A8A8: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8007A8AC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A8B0: nop

    // 0x8007A8B4: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    // 0x8007A8B8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A8BC: nop

    // 0x8007A8C0: sb          $zero, 0x2($t9)
    MEM_B(0X2, ctx->r25) = 0;
    // 0x8007A8C4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A8C8: nop

    // 0x8007A8CC: sb          $zero, 0x3($t0)
    MEM_B(0X3, ctx->r8) = 0;
    // 0x8007A8D0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A8D4: nop

    // 0x8007A8D8: sb          $zero, 0x4($t1)
    MEM_B(0X4, ctx->r9) = 0;
    // 0x8007A8DC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A8E0: nop

    // 0x8007A8E4: sb          $zero, 0x5($t2)
    MEM_B(0X5, ctx->r10) = 0;
    // 0x8007A8E8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A8EC: nop

    // 0x8007A8F0: sb          $zero, 0x6($t4)
    MEM_B(0X6, ctx->r12) = 0;
    // 0x8007A8F4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A8F8: nop

    // 0x8007A8FC: sb          $zero, 0x7($t3)
    MEM_B(0X7, ctx->r11) = 0;
    // 0x8007A900: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A904: nop

    // 0x8007A908: sb          $zero, 0x8($t5)
    MEM_B(0X8, ctx->r13) = 0;
    // 0x8007A90C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A910: nop

    // 0x8007A914: sb          $zero, 0xB($t6)
    MEM_B(0XB, ctx->r14) = 0;
    // 0x8007A918: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8007A91C:
    // 0x8007A91C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8007A920: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A924: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007A928: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007A92C: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x8007A930: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8007A934: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A938: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8007A93C: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x8007A940: sw          $zero, 0x20($t3)
    MEM_W(0X20, ctx->r11) = 0;
    // 0x8007A944: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8007A948: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A94C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8007A950: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x8007A954: sw          $zero, 0x34($t7)
    MEM_W(0X34, ctx->r15) = 0;
    // 0x8007A958: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007A95C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A960: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8007A964: addu        $t1, $t9, $t2
    ctx->r9 = ADD32(ctx->r25, ctx->r10);
    // 0x8007A968: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
    // 0x8007A96C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8007A970: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A974: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8007A978: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x8007A97C: sw          $zero, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = 0;
    // 0x8007A980: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8007A984: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A988: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8007A98C: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x8007A990: sw          $zero, 0x70($t9)
    MEM_W(0X70, ctx->r25) = 0;
    // 0x8007A994: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8007A998: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A99C: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8007A9A0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8007A9A4: sw          $zero, 0x84($t4)
    MEM_W(0X84, ctx->r12) = 0;
    // 0x8007A9A8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8007A9AC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A9B0: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8007A9B4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007A9B8: sw          $zero, 0x98($t8)
    MEM_W(0X98, ctx->r24) = 0;
    // 0x8007A9BC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8007A9C0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A9C4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8007A9C8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8007A9CC: sw          $zero, 0xAC($t2)
    MEM_W(0XAC, ctx->r10) = 0;
    // 0x8007A9D0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8007A9D4: nop

    // 0x8007A9D8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007A9DC: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8007A9E0: bne         $at, $zero, L_8007A91C
    if (ctx->r1 != 0) {
        // 0x8007A9E4: sw          $t4, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r12;
            goto L_8007A91C;
    }
    // 0x8007A9E4: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8007A9E8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A9EC: nop

    // 0x8007A9F0: sh          $zero, 0xC0($t5)
    MEM_H(0XC0, ctx->r13) = 0;
    // 0x8007A9F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A9F8: nop

    // 0x8007A9FC: sh          $zero, 0xC2($t6)
    MEM_H(0XC2, ctx->r14) = 0;
    // 0x8007AA00: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007AA04: nop

    // 0x8007AA08: sw          $zero, 0xC4($t7)
    MEM_W(0XC4, ctx->r15) = 0;
    // 0x8007AA0C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007AA10: nop

    // 0x8007AA14: sw          $zero, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = 0;
    // 0x8007AA18: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007AA1C: nop

    // 0x8007AA20: sw          $zero, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = 0;
    // 0x8007AA24: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007AA28: nop

    // 0x8007AA2C: sb          $zero, 0xD0($t0)
    MEM_B(0XD0, ctx->r8) = 0;
    // 0x8007AA30: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8007AA34: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8007AA38: jal         0x80079F90
    // 0x8007AA3C: nop

    displayText_AddEntry(rdram, ctx);
        goto after_6;
    // 0x8007AA3C: nop

    after_6:
    // 0x8007AA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007AA44: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8007AA48: jr          $ra
    // 0x8007AA4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007AA4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void displayText_SerializeTable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AA50: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007AA54: jr          $ra
    // 0x8007AA58: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8007AA58: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}

RECOMP_FUNC void displayText_FindEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AA5C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007AA60: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
L_8007AA64:
    // 0x8007AA64: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8007AA68: lbu         $t6, 0x9($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X9);
    // 0x8007AA6C: lbu         $t8, 0x9($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X9);
    // 0x8007AA70: nop

    // 0x8007AA74: bne         $t6, $t8, L_8007AAAC
    if (ctx->r14 != ctx->r24) {
        // 0x8007AA78: nop
    
            goto L_8007AAAC;
    }
    // 0x8007AA78: nop

    // 0x8007AA7C: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x8007AA80: lbu         $t0, 0xA($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0XA);
    // 0x8007AA84: nop

    // 0x8007AA88: bne         $t9, $t0, L_8007AAAC
    if (ctx->r25 != ctx->r8) {
        // 0x8007AA8C: nop
    
            goto L_8007AAAC;
    }
    // 0x8007AA8C: nop

    // 0x8007AA90: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x8007AA94: lbu         $t2, 0x0($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X0);
    // 0x8007AA98: nop

    // 0x8007AA9C: bne         $t1, $t2, L_8007AAAC
    if (ctx->r9 != ctx->r10) {
        // 0x8007AAA0: nop
    
            goto L_8007AAAC;
    }
    // 0x8007AAA0: nop

    // 0x8007AAA4: b           L_8007AAD4
    // 0x8007AAA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8007AAD4;
    // 0x8007AAA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8007AAAC:
    // 0x8007AAAC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8007AAB0: nop

    // 0x8007AAB4: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8007AAB8: nop

    // 0x8007AABC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8007AAC0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8007AAC4: nop

    // 0x8007AAC8: bne         $t5, $a0, L_8007AA64
    if (ctx->r13 != ctx->r4) {
        // 0x8007AACC: nop
    
            goto L_8007AA64;
    }
    // 0x8007AACC: nop

    // 0x8007AAD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007AAD4:
    // 0x8007AAD4: jr          $ra
    // 0x8007AAD8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007AAD8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void displayText_MatchXY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AADC: lbu         $t6, 0x6($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X6);
    // 0x8007AAE0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8007AAE4: bne         $t6, $a1, L_8007AB04
    if (ctx->r14 != ctx->r5) {
        // 0x8007AAE8: andi        $a2, $a2, 0xFF
        ctx->r6 = ctx->r6 & 0XFF;
            goto L_8007AB04;
    }
    // 0x8007AAE8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8007AAEC: lbu         $t7, 0x7($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7);
    // 0x8007AAF0: nop

    // 0x8007AAF4: bne         $t7, $a2, L_8007AB04
    if (ctx->r15 != ctx->r6) {
        // 0x8007AAF8: nop
    
            goto L_8007AB04;
    }
    // 0x8007AAF8: nop

    // 0x8007AAFC: jr          $ra
    // 0x8007AB00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8007AB00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007AB04:
    // 0x8007AB04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007AB08: jr          $ra
    // 0x8007AB0C: nop

    return;
    // 0x8007AB0C: nop

;}

RECOMP_FUNC void displayText_SetSlotData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AB10: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8007AB14: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8007AB18: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8007AB1C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8007AB20: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8007AB24: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8007AB28: ori         $at, $zero, 0xE13C
    ctx->r1 = 0 | 0XE13C;
    // 0x8007AB2C: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8007AB30: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007AB34: addiu       $t8, $t8, 0xA00
    ctx->r24 = ADD32(ctx->r24, 0XA00);
    // 0x8007AB38: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x8007AB3C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8007AB40: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x8007AB44: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8007AB48:
    // 0x8007AB48: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8007AB4C: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8007AB50: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x8007AB54: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x8007AB58: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x8007AB5C: sb          $t2, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r10;
    // 0x8007AB60: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8007AB64: nop

    // 0x8007AB68: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8007AB6C: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x8007AB70: bne         $at, $zero, L_8007AB48
    if (ctx->r1 != 0) {
        // 0x8007AB74: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_8007AB48;
    }
    // 0x8007AB74: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8007AB78: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8007AB7C: nop

    // 0x8007AB80: sb          $zero, 0x8($t7)
    MEM_B(0X8, ctx->r15) = 0;
    // 0x8007AB84: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8007AB88: lbu         $t8, 0x9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X9);
    // 0x8007AB8C: nop

    // 0x8007AB90: sb          $t8, 0x9($t9)
    MEM_B(0X9, ctx->r25) = ctx->r24;
    // 0x8007AB94: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8007AB98: lbu         $t1, 0xA($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XA);
    // 0x8007AB9C: nop

    // 0x8007ABA0: sb          $t1, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r9;
    // 0x8007ABA4: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8007ABA8: lbu         $t0, 0xB($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XB);
    // 0x8007ABAC: nop

    // 0x8007ABB0: sb          $t0, 0xD4($t2)
    MEM_B(0XD4, ctx->r10) = ctx->r8;
    // 0x8007ABB4: lw          $t4, 0xC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XC);
    // 0x8007ABB8: nop

    // 0x8007ABBC: beq         $t4, $zero, L_8007AD84
    if (ctx->r12 == 0) {
        // 0x8007ABC0: nop
    
            goto L_8007AD84;
    }
    // 0x8007ABC0: nop

    // 0x8007ABC4: lw          $t5, 0xC($a1)
    ctx->r13 = MEM_W(ctx->r5, 0XC);
    // 0x8007ABC8: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8007ABCC: lbu         $t6, 0xB($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XB);
    // 0x8007ABD0: nop

    // 0x8007ABD4: sb          $t6, 0xB($t7)
    MEM_B(0XB, ctx->r15) = ctx->r14;
    // 0x8007ABD8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8007ABDC:
    // 0x8007ABDC: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8007ABE0: lw          $t8, 0xC($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XC);
    // 0x8007ABE4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8007ABE8: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8007ABEC: addu        $t3, $t8, $t1
    ctx->r11 = ADD32(ctx->r24, ctx->r9);
    // 0x8007ABF0: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x8007ABF4: addu        $t4, $t2, $t1
    ctx->r12 = ADD32(ctx->r10, ctx->r9);
    // 0x8007ABF8: sw          $t0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r8;
    // 0x8007ABFC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007AC00: lw          $t5, 0xC($a1)
    ctx->r13 = MEM_W(ctx->r5, 0XC);
    // 0x8007AC04: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007AC08: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8007AC0C: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8007AC10: lw          $t8, 0x20($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X20);
    // 0x8007AC14: addu        $t2, $t3, $t7
    ctx->r10 = ADD32(ctx->r11, ctx->r15);
    // 0x8007AC18: sw          $t8, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r24;
    // 0x8007AC1C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8007AC20: lw          $t1, 0xC($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XC);
    // 0x8007AC24: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x8007AC28: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8007AC2C: addu        $t6, $t1, $t4
    ctx->r14 = ADD32(ctx->r9, ctx->r12);
    // 0x8007AC30: lw          $t5, 0x34($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X34);
    // 0x8007AC34: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x8007AC38: sw          $t5, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r13;
    // 0x8007AC3C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8007AC40: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x8007AC44: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x8007AC48: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8007AC4C: addu        $t0, $t7, $t2
    ctx->r8 = ADD32(ctx->r15, ctx->r10);
    // 0x8007AC50: lw          $t1, 0x48($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X48);
    // 0x8007AC54: addu        $t9, $t6, $t2
    ctx->r25 = ADD32(ctx->r14, ctx->r10);
    // 0x8007AC58: sw          $t1, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->r9;
    // 0x8007AC5C: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8007AC60: lw          $t4, 0xC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XC);
    // 0x8007AC64: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8007AC68: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8007AC6C: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x8007AC70: lw          $t7, 0x5C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X5C);
    // 0x8007AC74: addu        $t6, $t0, $t3
    ctx->r14 = ADD32(ctx->r8, ctx->r11);
    // 0x8007AC78: sw          $t7, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->r15;
    // 0x8007AC7C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8007AC80: lw          $t2, 0xC($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XC);
    // 0x8007AC84: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8007AC88: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007AC8C: addu        $t5, $t2, $t9
    ctx->r13 = ADD32(ctx->r10, ctx->r25);
    // 0x8007AC90: lw          $t4, 0x70($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X70);
    // 0x8007AC94: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8007AC98: sw          $t4, 0x70($t0)
    MEM_W(0X70, ctx->r8) = ctx->r12;
    // 0x8007AC9C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8007ACA0: lw          $t3, 0xC($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XC);
    // 0x8007ACA4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8007ACA8: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8007ACAC: addu        $t1, $t3, $t6
    ctx->r9 = ADD32(ctx->r11, ctx->r14);
    // 0x8007ACB0: lw          $t2, 0x84($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X84);
    // 0x8007ACB4: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x8007ACB8: sw          $t2, 0x84($t8)
    MEM_W(0X84, ctx->r24) = ctx->r10;
    // 0x8007ACBC: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8007ACC0: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x8007ACC4: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x8007ACC8: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8007ACCC: addu        $t7, $t9, $t0
    ctx->r15 = ADD32(ctx->r25, ctx->r8);
    // 0x8007ACD0: lw          $t3, 0x98($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X98);
    // 0x8007ACD4: addu        $t5, $t1, $t0
    ctx->r13 = ADD32(ctx->r9, ctx->r8);
    // 0x8007ACD8: sw          $t3, 0x98($t5)
    MEM_W(0X98, ctx->r13) = ctx->r11;
    // 0x8007ACDC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8007ACE0: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x8007ACE4: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8007ACE8: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8007ACEC: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x8007ACF0: lw          $t9, 0xAC($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XAC);
    // 0x8007ACF4: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8007ACF8: sw          $t9, 0xAC($t1)
    MEM_W(0XAC, ctx->r9) = ctx->r25;
    // 0x8007ACFC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8007AD00: nop

    // 0x8007AD04: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x8007AD08: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x8007AD0C: bne         $at, $zero, L_8007ABDC
    if (ctx->r1 != 0) {
        // 0x8007AD10: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_8007ABDC;
    }
    // 0x8007AD10: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8007AD14: lw          $t5, 0xC($a1)
    ctx->r13 = MEM_W(ctx->r5, 0XC);
    // 0x8007AD18: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8007AD1C: lhu         $t2, 0xC0($t5)
    ctx->r10 = MEM_HU(ctx->r13, 0XC0);
    // 0x8007AD20: nop

    // 0x8007AD24: sh          $t2, 0xC0($t6)
    MEM_H(0XC0, ctx->r14) = ctx->r10;
    // 0x8007AD28: lw          $t4, 0xC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XC);
    // 0x8007AD2C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007AD30: lhu         $t7, 0xC2($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0XC2);
    // 0x8007AD34: nop

    // 0x8007AD38: sh          $t7, 0xC2($t8)
    MEM_H(0XC2, ctx->r24) = ctx->r15;
    // 0x8007AD3C: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x8007AD40: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8007AD44: lw          $t1, 0xC4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC4);
    // 0x8007AD48: nop

    // 0x8007AD4C: sw          $t1, 0xC4($t0)
    MEM_W(0XC4, ctx->r8) = ctx->r9;
    // 0x8007AD50: lw          $t3, 0xC($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XC);
    // 0x8007AD54: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8007AD58: lw          $t5, 0xC8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC8);
    // 0x8007AD5C: nop

    // 0x8007AD60: sw          $t5, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r13;
    // 0x8007AD64: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x8007AD68: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8007AD6C: lw          $t4, 0xCC($t6)
    ctx->r12 = MEM_W(ctx->r14, 0XCC);
    // 0x8007AD70: nop

    // 0x8007AD74: sw          $t4, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->r12;
    // 0x8007AD78: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007AD7C: b           L_8007AEA8
    // 0x8007AD80: sb          $zero, 0xD0($t8)
    MEM_B(0XD0, ctx->r24) = 0;
        goto L_8007AEA8;
    // 0x8007AD80: sb          $zero, 0xD0($t8)
    MEM_B(0XD0, ctx->r24) = 0;
L_8007AD84:
    // 0x8007AD84: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8007AD88: nop

    // 0x8007AD8C: sb          $zero, 0xB($t9)
    MEM_B(0XB, ctx->r25) = 0;
    // 0x8007AD90: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8007AD94:
    // 0x8007AD94: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8007AD98: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8007AD9C: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8007ADA0: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x8007ADA4: sw          $zero, 0xC($t5)
    MEM_W(0XC, ctx->r13) = 0;
    // 0x8007ADA8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007ADAC: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8007ADB0: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x8007ADB4: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x8007ADB8: sw          $zero, 0x20($t7)
    MEM_W(0X20, ctx->r15) = 0;
    // 0x8007ADBC: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8007ADC0: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007ADC4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8007ADC8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8007ADCC: sw          $zero, 0x34($t1)
    MEM_W(0X34, ctx->r9) = 0;
    // 0x8007ADD0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8007ADD4: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8007ADD8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8007ADDC: addu        $t2, $t3, $t6
    ctx->r10 = ADD32(ctx->r11, ctx->r14);
    // 0x8007ADE0: sw          $zero, 0x48($t2)
    MEM_W(0X48, ctx->r10) = 0;
    // 0x8007ADE4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8007ADE8: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8007ADEC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007ADF0: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x8007ADF4: sw          $zero, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = 0;
    // 0x8007ADF8: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8007ADFC: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8007AE00: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x8007AE04: addu        $t3, $t0, $t5
    ctx->r11 = ADD32(ctx->r8, ctx->r13);
    // 0x8007AE08: sw          $zero, 0x70($t3)
    MEM_W(0X70, ctx->r11) = 0;
    // 0x8007AE0C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8007AE10: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8007AE14: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8007AE18: addu        $t4, $t6, $t7
    ctx->r12 = ADD32(ctx->r14, ctx->r15);
    // 0x8007AE1C: sw          $zero, 0x84($t4)
    MEM_W(0X84, ctx->r12) = 0;
    // 0x8007AE20: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8007AE24: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8007AE28: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8007AE2C: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x8007AE30: sw          $zero, 0x98($t0)
    MEM_W(0X98, ctx->r8) = 0;
    // 0x8007AE34: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8007AE38: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8007AE3C: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x8007AE40: addu        $t6, $t5, $t2
    ctx->r14 = ADD32(ctx->r13, ctx->r10);
    // 0x8007AE44: sw          $zero, 0xAC($t6)
    MEM_W(0XAC, ctx->r14) = 0;
    // 0x8007AE48: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8007AE4C: nop

    // 0x8007AE50: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x8007AE54: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8007AE58: bne         $at, $zero, L_8007AD94
    if (ctx->r1 != 0) {
        // 0x8007AE5C: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8007AD94;
    }
    // 0x8007AE5C: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8007AE60: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007AE64: nop

    // 0x8007AE68: sh          $zero, 0xC0($t8)
    MEM_H(0XC0, ctx->r24) = 0;
    // 0x8007AE6C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8007AE70: nop

    // 0x8007AE74: sh          $zero, 0xC2($t9)
    MEM_H(0XC2, ctx->r25) = 0;
    // 0x8007AE78: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8007AE7C: nop

    // 0x8007AE80: sw          $zero, 0xC4($t1)
    MEM_W(0XC4, ctx->r9) = 0;
    // 0x8007AE84: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8007AE88: nop

    // 0x8007AE8C: sw          $zero, 0xC8($t0)
    MEM_W(0XC8, ctx->r8) = 0;
    // 0x8007AE90: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8007AE94: nop

    // 0x8007AE98: sw          $zero, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = 0;
    // 0x8007AE9C: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8007AEA0: nop

    // 0x8007AEA4: sb          $zero, 0xD0($t5)
    MEM_B(0XD0, ctx->r13) = 0;
L_8007AEA8:
    // 0x8007AEA8: jr          $ra
    // 0x8007AEAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007AEAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void displayText_RemoveEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AEB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007AEB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007AEB8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007AEBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007AEC0: lbu         $t7, 0xB($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XB);
    // 0x8007AEC4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8007AEC8: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8007AECC: beq         $t8, $at, L_8007AF70
    if (ctx->r24 == ctx->r1) {
        // 0x8007AED0: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8007AF70;
    }
    // 0x8007AED0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8007AED4: beq         $t8, $at, L_8007AF70
    if (ctx->r24 == ctx->r1) {
        // 0x8007AED8: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8007AF70;
    }
    // 0x8007AED8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007AEDC: beq         $t8, $at, L_8007AF70
    if (ctx->r24 == ctx->r1) {
        // 0x8007AEE0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8007AF70;
    }
    // 0x8007AEE0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007AEE4: beq         $t8, $at, L_8007AF70
    if (ctx->r24 == ctx->r1) {
        // 0x8007AEE8: nop
    
            goto L_8007AF70;
    }
    // 0x8007AEE8: nop

    // 0x8007AEEC: lw          $t9, 0x10($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X10);
    // 0x8007AEF0: lw          $t0, 0x14($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X14);
    // 0x8007AEF4: nop

    // 0x8007AEF8: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x8007AEFC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007AF00: nop

    // 0x8007AF04: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x8007AF08: nop

    // 0x8007AF0C: beq         $t2, $zero, L_8007AF20
    if (ctx->r10 == 0) {
        // 0x8007AF10: nop
    
            goto L_8007AF20;
    }
    // 0x8007AF10: nop

    // 0x8007AF14: lw          $t3, 0x14($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X14);
    // 0x8007AF18: nop

    // 0x8007AF1C: sw          $t3, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r11;
L_8007AF20:
    // 0x8007AF20: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8007AF24: nop

    // 0x8007AF28: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x8007AF2C: nop

    // 0x8007AF30: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8007AF34: lw          $t7, 0xC($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC);
    // 0x8007AF38: nop

    // 0x8007AF3C: beq         $t7, $zero, L_8007AF58
    if (ctx->r15 == 0) {
        // 0x8007AF40: nop
    
            goto L_8007AF58;
    }
    // 0x8007AF40: nop

    // 0x8007AF44: jal         0x8007E328
    // 0x8007AF48: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x8007AF48: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x8007AF4C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8007AF50: nop

    // 0x8007AF54: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
L_8007AF58:
    // 0x8007AF58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007AF5C: jal         0x8007E328
    // 0x8007AF60: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x8007AF60: nop

    after_1:
    // 0x8007AF64: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8007AF68: b           L_8007AF78
    // 0x8007AF6C: nop

        goto L_8007AF78;
    // 0x8007AF6C: nop

L_8007AF70:
    // 0x8007AF70: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8007AF74: nop

L_8007AF78:
    // 0x8007AF78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007AF7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007AF80: jr          $ra
    // 0x8007AF84: nop

    return;
    // 0x8007AF84: nop

;}

RECOMP_FUNC void displayText_EncodeEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AF88: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007AF8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007AF90: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007AF94: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8007AF98: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8007AF9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007AFA0: jal         0x8007E03C
    // 0x8007AFA4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8007AFA4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_0:
    // 0x8007AFA8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8007AFAC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007AFB0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8007AFB4: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8007AFB8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007AFBC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8007AFC0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8007AFC4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007AFC8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8007AFCC: nop

    // 0x8007AFD0: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x8007AFD4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007AFD8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8007AFDC: nop

    // 0x8007AFE0: sw          $t1, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r9;
    // 0x8007AFE4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8007AFE8: jal         0x8007BD48
    // 0x8007AFEC: nop

    SaveData_ComputeChecksum16(rdram, ctx);
        goto after_1;
    // 0x8007AFEC: nop

    after_1:
    // 0x8007AFF0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007AFF4: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x8007AFF8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8007AFFC: sh          $t3, 0xD2($t4)
    MEM_H(0XD2, ctx->r12) = ctx->r11;
    // 0x8007B000: lw          $t5, -0x310($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X310);
    // 0x8007B004: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007B008: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x8007B00C: jal         0x800B3BFC
    // 0x8007B010: addiu       $a0, $a0, -0x21F8
    ctx->r4 = ADD32(ctx->r4, -0X21F8);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007B010: addiu       $a0, $a0, -0x21F8
    ctx->r4 = ADD32(ctx->r4, -0X21F8);
    after_2:
    // 0x8007B014: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8007B018:
    // 0x8007B018: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007B01C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B020: nop

    // 0x8007B024: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007B028: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8007B02C: nop

    // 0x8007B030: beq         $t9, $zero, L_8007B040
    if (ctx->r25 == 0) {
        // 0x8007B034: nop
    
            goto L_8007B040;
    }
    // 0x8007B034: nop

    // 0x8007B038: b           L_8007B058
    // 0x8007B03C: addiu       $s0, $t9, -0x20
    ctx->r16 = ADD32(ctx->r25, -0X20);
        goto L_8007B058;
    // 0x8007B03C: addiu       $s0, $t9, -0x20
    ctx->r16 = ADD32(ctx->r25, -0X20);
L_8007B040:
    // 0x8007B040: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007B044: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B048: nop

    // 0x8007B04C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8007B050: lbu         $s0, 0x0($t2)
    ctx->r16 = MEM_BU(ctx->r10, 0X0);
    // 0x8007B054: nop

L_8007B058:
    // 0x8007B058: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B05C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x8007B060: jal         0x8007B8A8
    // 0x8007B064: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    Bitstream_WriteBits(rdram, ctx);
        goto after_3;
    // 0x8007B064: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_3:
    // 0x8007B068: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B06C: nop

    // 0x8007B070: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007B074: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x8007B078: bne         $at, $zero, L_8007B018
    if (ctx->r1 != 0) {
        // 0x8007B07C: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_8007B018;
    }
    // 0x8007B07C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8007B080: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007B084: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B088: lbu         $a1, 0x9($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X9);
    // 0x8007B08C: jal         0x8007B8A8
    // 0x8007B090: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Bitstream_WriteBits(rdram, ctx);
        goto after_4;
    // 0x8007B090: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x8007B094: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007B098: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B09C: lbu         $a1, 0xA($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0XA);
    // 0x8007B0A0: jal         0x8007B8A8
    // 0x8007B0A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Bitstream_WriteBits(rdram, ctx);
        goto after_5;
    // 0x8007B0A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x8007B0A8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007B0AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B0B0: lbu         $a1, 0xB($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0XB);
    // 0x8007B0B4: jal         0x8007B8A8
    // 0x8007B0B8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    Bitstream_WriteBits(rdram, ctx);
        goto after_6;
    // 0x8007B0B8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_6:
    // 0x8007B0BC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8007B0C0:
    // 0x8007B0C0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B0C4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007B0C8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8007B0CC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8007B0D0: lw          $a1, 0xC($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC);
    // 0x8007B0D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B0D8: jal         0x8007B8A8
    // 0x8007B0DC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    Bitstream_WriteBits(rdram, ctx);
        goto after_7;
    // 0x8007B0DC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_7:
    // 0x8007B0E0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B0E4: nop

    // 0x8007B0E8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007B0EC: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x8007B0F0: bne         $at, $zero, L_8007B0C0
    if (ctx->r1 != 0) {
        // 0x8007B0F4: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_8007B0C0;
    }
    // 0x8007B0F4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8007B0F8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8007B0FC:
    // 0x8007B0FC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B100: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007B104: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8007B108: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8007B10C: lw          $a1, 0x20($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X20);
    // 0x8007B110: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B114: jal         0x8007B8A8
    // 0x8007B118: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    Bitstream_WriteBits(rdram, ctx);
        goto after_8;
    // 0x8007B118: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_8:
    // 0x8007B11C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B120: nop

    // 0x8007B124: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8007B128: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8007B12C: bne         $at, $zero, L_8007B0FC
    if (ctx->r1 != 0) {
        // 0x8007B130: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_8007B0FC;
    }
    // 0x8007B130: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007B134: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8007B138:
    // 0x8007B138: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B13C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007B140: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8007B144: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8007B148: lw          $a1, 0x34($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X34);
    // 0x8007B14C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B150: jal         0x8007B8A8
    // 0x8007B154: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    Bitstream_WriteBits(rdram, ctx);
        goto after_9;
    // 0x8007B154: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_9:
    // 0x8007B158: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B15C: nop

    // 0x8007B160: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8007B164: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8007B168: bne         $at, $zero, L_8007B138
    if (ctx->r1 != 0) {
        // 0x8007B16C: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_8007B138;
    }
    // 0x8007B16C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8007B170: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8007B174:
    // 0x8007B174: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B178: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007B17C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007B180: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8007B184: lw          $a1, 0x48($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X48);
    // 0x8007B188: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B18C: jal         0x8007B8A8
    // 0x8007B190: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    Bitstream_WriteBits(rdram, ctx);
        goto after_10;
    // 0x8007B190: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_10:
    // 0x8007B194: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B198: nop

    // 0x8007B19C: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8007B1A0: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x8007B1A4: bne         $at, $zero, L_8007B174
    if (ctx->r1 != 0) {
        // 0x8007B1A8: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_8007B174;
    }
    // 0x8007B1A8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8007B1AC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8007B1B0:
    // 0x8007B1B0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B1B4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007B1B8: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8007B1BC: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x8007B1C0: lw          $a1, 0x5C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X5C);
    // 0x8007B1C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B1C8: jal         0x8007B8A8
    // 0x8007B1CC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    Bitstream_WriteBits(rdram, ctx);
        goto after_11;
    // 0x8007B1CC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_11:
    // 0x8007B1D0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B1D4: nop

    // 0x8007B1D8: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x8007B1DC: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x8007B1E0: bne         $at, $zero, L_8007B1B0
    if (ctx->r1 != 0) {
        // 0x8007B1E4: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_8007B1B0;
    }
    // 0x8007B1E4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007B1E8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8007B1EC:
    // 0x8007B1EC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B1F0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007B1F4: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8007B1F8: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x8007B1FC: lw          $a1, 0x70($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X70);
    // 0x8007B200: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B204: jal         0x8007B8A8
    // 0x8007B208: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    Bitstream_WriteBits(rdram, ctx);
        goto after_12;
    // 0x8007B208: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_12:
    // 0x8007B20C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B210: nop

    // 0x8007B214: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x8007B218: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x8007B21C: bne         $at, $zero, L_8007B1EC
    if (ctx->r1 != 0) {
        // 0x8007B220: sw          $t2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r10;
            goto L_8007B1EC;
    }
    // 0x8007B220: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8007B224: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8007B228:
    // 0x8007B228: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B22C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007B230: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8007B234: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8007B238: lw          $a1, 0x84($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X84);
    // 0x8007B23C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B240: jal         0x8007B8A8
    // 0x8007B244: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    Bitstream_WriteBits(rdram, ctx);
        goto after_13;
    // 0x8007B244: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_13:
    // 0x8007B248: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B24C: nop

    // 0x8007B250: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8007B254: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x8007B258: bne         $at, $zero, L_8007B228
    if (ctx->r1 != 0) {
        // 0x8007B25C: sw          $t9, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r25;
            goto L_8007B228;
    }
    // 0x8007B25C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8007B260: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8007B264:
    // 0x8007B264: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B268: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007B26C: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8007B270: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x8007B274: lw          $a1, 0x98($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X98);
    // 0x8007B278: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B27C: jal         0x8007B8A8
    // 0x8007B280: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    Bitstream_WriteBits(rdram, ctx);
        goto after_14;
    // 0x8007B280: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_14:
    // 0x8007B284: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B288: nop

    // 0x8007B28C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007B290: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x8007B294: bne         $at, $zero, L_8007B264
    if (ctx->r1 != 0) {
        // 0x8007B298: sw          $t5, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r13;
            goto L_8007B264;
    }
    // 0x8007B298: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8007B29C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8007B2A0:
    // 0x8007B2A0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B2A4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007B2A8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8007B2AC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8007B2B0: lw          $a1, 0xAC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XAC);
    // 0x8007B2B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B2B8: jal         0x8007B8A8
    // 0x8007B2BC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    Bitstream_WriteBits(rdram, ctx);
        goto after_15;
    // 0x8007B2BC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_15:
    // 0x8007B2C0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B2C4: nop

    // 0x8007B2C8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007B2CC: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8007B2D0: bne         $at, $zero, L_8007B2A0
    if (ctx->r1 != 0) {
        // 0x8007B2D4: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_8007B2A0;
    }
    // 0x8007B2D4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8007B2D8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8007B2DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B2E0: lhu         $a1, 0xC0($t3)
    ctx->r5 = MEM_HU(ctx->r11, 0XC0);
    // 0x8007B2E4: jal         0x8007B8A8
    // 0x8007B2E8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    Bitstream_WriteBits(rdram, ctx);
        goto after_16;
    // 0x8007B2E8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_16:
    // 0x8007B2EC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007B2F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B2F4: lhu         $a1, 0xC2($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0XC2);
    // 0x8007B2F8: jal         0x8007B8A8
    // 0x8007B2FC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    Bitstream_WriteBits(rdram, ctx);
        goto after_17;
    // 0x8007B2FC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_17:
    // 0x8007B300: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007B304: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B308: lw          $a1, 0xC4($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC4);
    // 0x8007B30C: jal         0x8007B8A8
    // 0x8007B310: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    Bitstream_WriteBits(rdram, ctx);
        goto after_18;
    // 0x8007B310: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_18:
    // 0x8007B314: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007B318: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B31C: lw          $a1, 0xC8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC8);
    // 0x8007B320: jal         0x8007B8A8
    // 0x8007B324: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    Bitstream_WriteBits(rdram, ctx);
        goto after_19;
    // 0x8007B324: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_19:
    // 0x8007B328: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007B32C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B330: lw          $a1, 0xCC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XCC);
    // 0x8007B334: jal         0x8007B8A8
    // 0x8007B338: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    Bitstream_WriteBits(rdram, ctx);
        goto after_20;
    // 0x8007B338: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_20:
    // 0x8007B33C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007B340: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B344: lbu         $a1, 0xD0($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0XD0);
    // 0x8007B348: jal         0x8007B8A8
    // 0x8007B34C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Bitstream_WriteBits(rdram, ctx);
        goto after_21;
    // 0x8007B34C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_21:
    // 0x8007B350: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007B354: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B358: lhu         $a1, 0xD2($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0XD2);
    // 0x8007B35C: jal         0x8007B8A8
    // 0x8007B360: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    Bitstream_WriteBits(rdram, ctx);
        goto after_22;
    // 0x8007B360: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_22:
    // 0x8007B364: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B368: jal         0x8007BA38
    // 0x8007B36C: nop

    Bitstream_Flush(rdram, ctx);
        goto after_23;
    // 0x8007B36C: nop

    after_23:
    // 0x8007B370: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007B374: jal         0x8007E328
    // 0x8007B378: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_24;
    // 0x8007B378: nop

    after_24:
    // 0x8007B37C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B380: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007B384: jr          $ra
    // 0x8007B388: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007B388: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void displayText_PrintEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B38C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007B390: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007B394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B398: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8007B39C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007B3A0: jal         0x800B3BFC
    // 0x8007B3A4: addiu       $a0, $a0, -0x21EC
    ctx->r4 = ADD32(ctx->r4, -0X21EC);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007B3A4: addiu       $a0, $a0, -0x21EC
    ctx->r4 = ADD32(ctx->r4, -0X21EC);
    after_0:
    // 0x8007B3A8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8007B3AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007B3B0: lbu         $a1, 0x9($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X9);
    // 0x8007B3B4: lbu         $a2, 0xA($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0XA);
    // 0x8007B3B8: jal         0x800B3BFC
    // 0x8007B3BC: addiu       $a0, $a0, -0x21E0
    ctx->r4 = ADD32(ctx->r4, -0X21E0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007B3BC: addiu       $a0, $a0, -0x21E0
    ctx->r4 = ADD32(ctx->r4, -0X21E0);
    after_1:
    // 0x8007B3C0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8007B3C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007B3C8: lbu         $a1, 0xB($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0XB);
    // 0x8007B3CC: jal         0x800B3BFC
    // 0x8007B3D0: addiu       $a0, $a0, -0x21D0
    ctx->r4 = ADD32(ctx->r4, -0X21D0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007B3D0: addiu       $a0, $a0, -0x21D0
    ctx->r4 = ADD32(ctx->r4, -0X21D0);
    after_2:
    // 0x8007B3D4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8007B3D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007B3DC: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    // 0x8007B3E0: jal         0x800B3BFC
    // 0x8007B3E4: addiu       $a0, $a0, -0x21C4
    ctx->r4 = ADD32(ctx->r4, -0X21C4);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8007B3E4: addiu       $a0, $a0, -0x21C4
    ctx->r4 = ADD32(ctx->r4, -0X21C4);
    after_3:
    // 0x8007B3E8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8007B3EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007B3F0: lw          $a1, 0x10($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X10);
    // 0x8007B3F4: jal         0x800B3BFC
    // 0x8007B3F8: addiu       $a0, $a0, -0x21B8
    ctx->r4 = ADD32(ctx->r4, -0X21B8);
    rmonPrintf_recomp(rdram, ctx);
        goto after_4;
    // 0x8007B3F8: addiu       $a0, $a0, -0x21B8
    ctx->r4 = ADD32(ctx->r4, -0X21B8);
    after_4:
    // 0x8007B3FC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8007B400: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007B404: lw          $a1, 0x14($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X14);
    // 0x8007B408: jal         0x800B3BFC
    // 0x8007B40C: addiu       $a0, $a0, -0x21AC
    ctx->r4 = ADD32(ctx->r4, -0X21AC);
    rmonPrintf_recomp(rdram, ctx);
        goto after_5;
    // 0x8007B40C: addiu       $a0, $a0, -0x21AC
    ctx->r4 = ADD32(ctx->r4, -0X21AC);
    after_5:
    // 0x8007B410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007B418: jr          $ra
    // 0x8007B41C: nop

    return;
    // 0x8007B41C: nop

;}

RECOMP_FUNC void displayText_DeserializeTable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B420: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007B424: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x8007B428: jr          $ra
    // 0x8007B42C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007B42C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void displayText_DecodeEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B430: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007B434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B438: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007B43C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007B440: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007B444: jal         0x8007E03C
    // 0x8007B448: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8007B448: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_0:
    // 0x8007B44C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007B450: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8007B454: nop

    // 0x8007B458: sw          $zero, 0x14($t6)
    MEM_W(0X14, ctx->r14) = 0;
    // 0x8007B45C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8007B460: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007B464: nop

    // 0x8007B468: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x8007B46C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8007B470: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007B474: nop

    // 0x8007B478: sw          $t9, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r25;
    // 0x8007B47C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8007B480: nop

    // 0x8007B484: sw          $zero, 0x10($t1)
    MEM_W(0X10, ctx->r9) = 0;
    // 0x8007B488: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8007B48C:
    // 0x8007B48C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B490: jal         0x8007B964
    // 0x8007B494: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    Bitstream_ReadBits(rdram, ctx);
        goto after_1;
    // 0x8007B494: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x8007B498: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8007B49C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B4A0: andi        $t2, $v0, 0x3F
    ctx->r10 = ctx->r2 & 0X3F;
    // 0x8007B4A4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8007B4A8: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x8007B4AC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B4B0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007B4B4: nop

    // 0x8007B4B8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007B4BC: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8007B4C0: nop

    // 0x8007B4C4: addiu       $t0, $t9, 0x20
    ctx->r8 = ADD32(ctx->r25, 0X20);
    // 0x8007B4C8: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
    // 0x8007B4CC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B4D0: nop

    // 0x8007B4D4: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8007B4D8: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x8007B4DC: bne         $at, $zero, L_8007B48C
    if (ctx->r1 != 0) {
        // 0x8007B4E0: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_8007B48C;
    }
    // 0x8007B4E0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8007B4E4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8007B4E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8007B4EC: sb          $zero, 0x8($t4)
    MEM_B(0X8, ctx->r12) = 0;
    // 0x8007B4F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B4F4: jal         0x8007B964
    // 0x8007B4F8: nop

    Bitstream_ReadBits(rdram, ctx);
        goto after_2;
    // 0x8007B4F8: nop

    after_2:
    // 0x8007B4FC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007B500: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x8007B504: sb          $t2, 0x9($t5)
    MEM_B(0X9, ctx->r13) = ctx->r10;
    // 0x8007B508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B50C: jal         0x8007B964
    // 0x8007B510: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    Bitstream_ReadBits(rdram, ctx);
        goto after_3;
    // 0x8007B510: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x8007B514: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8007B518: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8007B51C: sb          $t6, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r14;
    // 0x8007B520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B524: jal         0x8007B964
    // 0x8007B528: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    Bitstream_ReadBits(rdram, ctx);
        goto after_4;
    // 0x8007B528: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x8007B52C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8007B530: andi        $t9, $v0, 0x1F
    ctx->r25 = ctx->r2 & 0X1F;
    // 0x8007B534: sb          $t9, 0xB($t0)
    MEM_B(0XB, ctx->r8) = ctx->r25;
    // 0x8007B538: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8007B53C:
    // 0x8007B53C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B540: jal         0x8007B964
    // 0x8007B544: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    Bitstream_ReadBits(rdram, ctx);
        goto after_5;
    // 0x8007B544: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_5:
    // 0x8007B548: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B54C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007B550: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007B554: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007B558: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007B55C: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x8007B560: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x8007B564: sw          $t8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r24;
    // 0x8007B568: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B56C: nop

    // 0x8007B570: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8007B574: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x8007B578: bne         $at, $zero, L_8007B53C
    if (ctx->r1 != 0) {
        // 0x8007B57C: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_8007B53C;
    }
    // 0x8007B57C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8007B580: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8007B584:
    // 0x8007B584: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B588: jal         0x8007B964
    // 0x8007B58C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    Bitstream_ReadBits(rdram, ctx);
        goto after_6;
    // 0x8007B58C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_6:
    // 0x8007B590: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B594: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8007B598: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007B59C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007B5A0: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8007B5A4: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x8007B5A8: addu        $t1, $t9, $t3
    ctx->r9 = ADD32(ctx->r25, ctx->r11);
    // 0x8007B5AC: sw          $t7, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->r15;
    // 0x8007B5B0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B5B4: nop

    // 0x8007B5B8: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x8007B5BC: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8007B5C0: bne         $at, $zero, L_8007B584
    if (ctx->r1 != 0) {
        // 0x8007B5C4: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_8007B584;
    }
    // 0x8007B5C4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8007B5C8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8007B5CC:
    // 0x8007B5CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B5D0: jal         0x8007B964
    // 0x8007B5D4: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    Bitstream_ReadBits(rdram, ctx);
        goto after_7;
    // 0x8007B5D4: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_7:
    // 0x8007B5D8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B5DC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007B5E0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007B5E4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007B5E8: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8007B5EC: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x8007B5F0: addu        $t9, $t5, $t0
    ctx->r25 = ADD32(ctx->r13, ctx->r8);
    // 0x8007B5F4: sw          $t2, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r10;
    // 0x8007B5F8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B5FC: nop

    // 0x8007B600: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x8007B604: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x8007B608: bne         $at, $zero, L_8007B5CC
    if (ctx->r1 != 0) {
        // 0x8007B60C: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8007B5CC;
    }
    // 0x8007B60C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8007B610: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8007B614:
    // 0x8007B614: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B618: jal         0x8007B964
    // 0x8007B61C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    Bitstream_ReadBits(rdram, ctx);
        goto after_8;
    // 0x8007B61C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_8:
    // 0x8007B620: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B624: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8007B628: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007B62C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007B630: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8007B634: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x8007B638: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x8007B63C: sw          $t1, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->r9;
    // 0x8007B640: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B644: nop

    // 0x8007B648: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8007B64C: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x8007B650: bne         $at, $zero, L_8007B614
    if (ctx->r1 != 0) {
        // 0x8007B654: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_8007B614;
    }
    // 0x8007B654: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8007B658: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8007B65C:
    // 0x8007B65C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B660: jal         0x8007B964
    // 0x8007B664: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    Bitstream_ReadBits(rdram, ctx);
        goto after_9;
    // 0x8007B664: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_9:
    // 0x8007B668: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B66C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8007B670: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007B674: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007B678: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007B67C: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x8007B680: addu        $t4, $t3, $t8
    ctx->r12 = ADD32(ctx->r11, ctx->r24);
    // 0x8007B684: sw          $t9, 0x5C($t4)
    MEM_W(0X5C, ctx->r12) = ctx->r25;
    // 0x8007B688: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B68C: nop

    // 0x8007B690: addiu       $t1, $t6, 0x1
    ctx->r9 = ADD32(ctx->r14, 0X1);
    // 0x8007B694: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8007B698: bne         $at, $zero, L_8007B65C
    if (ctx->r1 != 0) {
        // 0x8007B69C: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_8007B65C;
    }
    // 0x8007B69C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8007B6A0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8007B6A4:
    // 0x8007B6A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B6A8: jal         0x8007B964
    // 0x8007B6AC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    Bitstream_ReadBits(rdram, ctx);
        goto after_10;
    // 0x8007B6AC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_10:
    // 0x8007B6B0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B6B4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8007B6B8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007B6BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007B6C0: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8007B6C4: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x8007B6C8: addu        $t3, $t0, $t7
    ctx->r11 = ADD32(ctx->r8, ctx->r15);
    // 0x8007B6CC: sw          $t5, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->r13;
    // 0x8007B6D0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B6D4: nop

    // 0x8007B6D8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8007B6DC: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x8007B6E0: bne         $at, $zero, L_8007B6A4
    if (ctx->r1 != 0) {
        // 0x8007B6E4: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_8007B6A4;
    }
    // 0x8007B6E4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8007B6E8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8007B6EC:
    // 0x8007B6EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B6F0: jal         0x8007B964
    // 0x8007B6F4: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    Bitstream_ReadBits(rdram, ctx);
        goto after_11;
    // 0x8007B6F4: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_11:
    // 0x8007B6F8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B6FC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007B700: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007B704: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007B708: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8007B70C: and         $t4, $v0, $at
    ctx->r12 = ctx->r2 & ctx->r1;
    // 0x8007B710: addu        $t0, $t6, $t2
    ctx->r8 = ADD32(ctx->r14, ctx->r10);
    // 0x8007B714: sw          $t4, 0x84($t0)
    MEM_W(0X84, ctx->r8) = ctx->r12;
    // 0x8007B718: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B71C: nop

    // 0x8007B720: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x8007B724: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x8007B728: bne         $at, $zero, L_8007B6EC
    if (ctx->r1 != 0) {
        // 0x8007B72C: sw          $t5, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r13;
            goto L_8007B6EC;
    }
    // 0x8007B72C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8007B730: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8007B734:
    // 0x8007B734: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B738: jal         0x8007B964
    // 0x8007B73C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    Bitstream_ReadBits(rdram, ctx);
        goto after_12;
    // 0x8007B73C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_12:
    // 0x8007B740: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B744: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8007B748: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007B74C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007B750: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8007B754: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x8007B758: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x8007B75C: sw          $t3, 0x98($t6)
    MEM_W(0X98, ctx->r14) = ctx->r11;
    // 0x8007B760: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B764: nop

    // 0x8007B768: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8007B76C: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8007B770: bne         $at, $zero, L_8007B734
    if (ctx->r1 != 0) {
        // 0x8007B774: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_8007B734;
    }
    // 0x8007B774: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8007B778: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8007B77C:
    // 0x8007B77C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B780: jal         0x8007B964
    // 0x8007B784: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    Bitstream_ReadBits(rdram, ctx);
        goto after_13;
    // 0x8007B784: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_13:
    // 0x8007B788: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B78C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8007B790: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007B794: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007B798: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8007B79C: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x8007B7A0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8007B7A4: sw          $t0, 0xAC($t8)
    MEM_W(0XAC, ctx->r24) = ctx->r8;
    // 0x8007B7A8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B7AC: nop

    // 0x8007B7B0: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8007B7B4: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x8007B7B8: bne         $at, $zero, L_8007B77C
    if (ctx->r1 != 0) {
        // 0x8007B7BC: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_8007B77C;
    }
    // 0x8007B7BC: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8007B7C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B7C4: jal         0x8007B964
    // 0x8007B7C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Bitstream_ReadBits(rdram, ctx);
        goto after_14;
    // 0x8007B7C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_14:
    // 0x8007B7CC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007B7D0: andi        $t6, $v0, 0x3FF
    ctx->r14 = ctx->r2 & 0X3FF;
    // 0x8007B7D4: sh          $t6, 0xC0($t2)
    MEM_H(0XC0, ctx->r10) = ctx->r14;
    // 0x8007B7D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B7DC: jal         0x8007B964
    // 0x8007B7E0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    Bitstream_ReadBits(rdram, ctx);
        goto after_15;
    // 0x8007B7E0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_15:
    // 0x8007B7E4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007B7E8: andi        $t4, $v0, 0xFFF
    ctx->r12 = ctx->r2 & 0XFFF;
    // 0x8007B7EC: sh          $t4, 0xC2($t5)
    MEM_H(0XC2, ctx->r13) = ctx->r12;
    // 0x8007B7F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B7F4: jal         0x8007B964
    // 0x8007B7F8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Bitstream_ReadBits(rdram, ctx);
        goto after_16;
    // 0x8007B7F8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_16:
    // 0x8007B7FC: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8007B800: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8007B804: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007B808: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x8007B80C: sw          $t7, 0xC4($t9)
    MEM_W(0XC4, ctx->r25) = ctx->r15;
    // 0x8007B810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B814: jal         0x8007B964
    // 0x8007B818: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Bitstream_ReadBits(rdram, ctx);
        goto after_17;
    // 0x8007B818: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_17:
    // 0x8007B81C: lui         $at, 0x3FFF
    ctx->r1 = S32(0X3FFF << 16);
    // 0x8007B820: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8007B824: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007B828: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x8007B82C: sw          $t0, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r8;
    // 0x8007B830: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B834: jal         0x8007B964
    // 0x8007B838: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Bitstream_ReadBits(rdram, ctx);
        goto after_18;
    // 0x8007B838: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_18:
    // 0x8007B83C: lui         $at, 0x3FFF
    ctx->r1 = S32(0X3FFF << 16);
    // 0x8007B840: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8007B844: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007B848: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x8007B84C: sw          $t1, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->r9;
    // 0x8007B850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B854: jal         0x8007B964
    // 0x8007B858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Bitstream_ReadBits(rdram, ctx);
        goto after_19;
    // 0x8007B858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x8007B85C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007B860: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8007B864: sb          $t6, 0xD0($t2)
    MEM_B(0XD0, ctx->r10) = ctx->r14;
    // 0x8007B868: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B86C: jal         0x8007B964
    // 0x8007B870: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    Bitstream_ReadBits(rdram, ctx);
        goto after_20;
    // 0x8007B870: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_20:
    // 0x8007B874: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007B878: andi        $t4, $v0, 0xFFFF
    ctx->r12 = ctx->r2 & 0XFFFF;
    // 0x8007B87C: sh          $t4, 0xD2($t5)
    MEM_H(0XD2, ctx->r13) = ctx->r12;
    // 0x8007B880: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8007B884: nop

    // 0x8007B888: sb          $zero, 0xD0($t7)
    MEM_B(0XD0, ctx->r15) = 0;
    // 0x8007B88C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007B890: jal         0x8007E328
    // 0x8007B894: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_21;
    // 0x8007B894: nop

    after_21:
    // 0x8007B898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B89C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007B8A0: jr          $ra
    // 0x8007B8A4: nop

    return;
    // 0x8007B8A4: nop

;}

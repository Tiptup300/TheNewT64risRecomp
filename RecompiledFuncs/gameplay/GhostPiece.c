#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void GhostPiece_800666d0_sixliner_loops_arg1_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800666D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800666D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800666D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800666DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800666E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800666E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800666E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800666EC: jal         0x800655C4
    // 0x800666F0: addiu       $a0, $a0, 0x500
    ctx->r4 = ADD32(ctx->r4, 0X500);
    MobilePiece_UpdateAltColor(rdram, ctx);
        goto after_0;
    // 0x800666F0: addiu       $a0, $a0, 0x500
    ctx->r4 = ADD32(ctx->r4, 0X500);
    after_0:
    // 0x800666F4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800666F8: nop

    // 0x800666FC: blez        $s0, L_80066720
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80066700: nop
    
            goto L_80066720;
    }
    // 0x80066700: nop

L_80066704:
    // 0x80066704: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80066708: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8006670C: jal         0x80064F54
    // 0x80066710: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    MobilePiece_MorphCubes(rdram, ctx);
        goto after_1;
    // 0x80066710: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x80066714: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80066718: bgtz        $s0, L_80066704
    if (SIGNED(ctx->r16) > 0) {
        // 0x8006671C: nop
    
            goto L_80066704;
    }
    // 0x8006671C: nop

L_80066720:
    // 0x80066720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066724: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066728: jr          $ra
    // 0x8006672C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006672C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void GhostPiece_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066730: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80066734: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80066738: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006673C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066740: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066744: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80066748: addiu       $s0, $t6, 0x8
    ctx->r16 = ADD32(ctx->r14, 0X8);
    // 0x8006674C: beq         $t7, $zero, L_8006676C
    if (ctx->r15 == 0) {
        // 0x80066750: nop
    
            goto L_8006676C;
    }
    // 0x80066750: nop

    // 0x80066754: jal         0x800651C8
    // 0x80066758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    MobilePiece_CanPlace(rdram, ctx);
        goto after_0;
    // 0x80066758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006675C: beq         $v0, $zero, L_8006676C
    if (ctx->r2 == 0) {
        // 0x80066760: nop
    
            goto L_8006676C;
    }
    // 0x80066760: nop

    // 0x80066764: jal         0x80064FB0
    // 0x80066768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    MobilePiece_Render(rdram, ctx);
        goto after_1;
    // 0x80066768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_8006676C:
    // 0x8006676C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066770: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066774: jr          $ra
    // 0x80066778: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80066778: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void GhostPiece_DropToLanding(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006677C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066784: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80066788:
    // 0x80066788: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006678C: nop

    // 0x80066790: lh          $t7, 0x18($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X18);
    // 0x80066794: nop

    // 0x80066798: addiu       $t8, $t7, 0x100
    ctx->r24 = ADD32(ctx->r15, 0X100);
    // 0x8006679C: sh          $t8, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r24;
    // 0x800667A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800667A4: jal         0x800651C8
    // 0x800667A8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    MobilePiece_CanPlace(rdram, ctx);
        goto after_0;
    // 0x800667A8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x800667AC: bne         $v0, $zero, L_80066788
    if (ctx->r2 != 0) {
        // 0x800667B0: nop
    
            goto L_80066788;
    }
    // 0x800667B0: nop

    // 0x800667B4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800667B8: nop

    // 0x800667BC: lh          $t0, 0x18($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X18);
    // 0x800667C0: nop

    // 0x800667C4: addiu       $t1, $t0, -0x100
    ctx->r9 = ADD32(ctx->r8, -0X100);
    // 0x800667C8: sh          $t1, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r9;
    // 0x800667CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800667D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800667D4: jr          $ra
    // 0x800667D8: nop

    return;
    // 0x800667D8: nop

;}

RECOMP_FUNC void GhostPiece_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800667DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800667E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800667E4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800667E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800667EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800667F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800667F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800667F8: sb          $zero, 0x52A($t6)
    MEM_B(0X52A, ctx->r14) = 0;
    // 0x800667FC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80066800: lhu         $t9, 0x2E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2E);
    // 0x80066804: lhu         $t8, 0x528($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X528);
    // 0x80066808: nop

    // 0x8006680C: bne         $t8, $t9, L_8006683C
    if (ctx->r24 != ctx->r25) {
        // 0x80066810: nop
    
            goto L_8006683C;
    }
    // 0x80066810: nop

    // 0x80066814: lh          $t0, 0x524($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X524);
    // 0x80066818: lh          $t1, 0x28($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X28);
    // 0x8006681C: nop

    // 0x80066820: bne         $t0, $t1, L_8006683C
    if (ctx->r8 != ctx->r9) {
        // 0x80066824: nop
    
            goto L_8006683C;
    }
    // 0x80066824: nop

    // 0x80066828: lh          $t2, 0x526($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X526);
    // 0x8006682C: lh          $t3, 0x24($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X24);
    // 0x80066830: nop

    // 0x80066834: beq         $t2, $t3, L_800668DC
    if (ctx->r10 == ctx->r11) {
        // 0x80066838: nop
    
            goto L_800668DC;
    }
    // 0x80066838: nop

L_8006683C:
    // 0x8006683C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80066840: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80066844: sb          $t4, 0x52A($t5)
    MEM_B(0X52A, ctx->r13) = ctx->r12;
    // 0x80066848: lhu         $t6, 0x2E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2E);
    // 0x8006684C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80066850: nop

    // 0x80066854: sh          $t6, 0x528($t8)
    MEM_H(0X528, ctx->r24) = ctx->r14;
    // 0x80066858: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006685C: lh          $t9, 0x28($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X28);
    // 0x80066860: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80066864: sh          $t9, 0x524($t0)
    MEM_H(0X524, ctx->r8) = ctx->r25;
    // 0x80066868: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8006686C: lh          $t1, 0x24($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X24);
    // 0x80066870: nop

    // 0x80066874: sh          $t1, 0x526($t7)
    MEM_H(0X526, ctx->r15) = ctx->r9;
    // 0x80066878: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8006687C: lwl         $t4, 0x28($sp)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r29, 0X28);
    // 0x80066880: lwl         $t3, 0x24($sp)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r29, 0X24);
    // 0x80066884: lwr         $t4, 0x2B($sp)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r29, 0X2B);
    // 0x80066888: lwr         $t3, 0x27($sp)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r29, 0X27);
    // 0x8006688C: lw          $a1, 0x520($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X520);
    // 0x80066890: swl         $t4, 0xC($sp)
    do_swl(rdram, 0XC, ctx->r29, ctx->r12);
    // 0x80066894: swl         $t3, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r11);
    // 0x80066898: lhu         $t5, 0x2E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X2E);
    // 0x8006689C: swr         $t4, 0xF($sp)
    do_swr(rdram, 0XF, ctx->r29, ctx->r12);
    // 0x800668A0: swr         $t3, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r11);
    // 0x800668A4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x800668A8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x800668AC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800668B0: addiu       $a0, $t2, 0x8
    ctx->r4 = ADD32(ctx->r10, 0X8);
    // 0x800668B4: jal         0x800653E4
    // 0x800668B8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    MobilePiece_Init(rdram, ctx);
        goto after_0;
    // 0x800668B8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_0:
    // 0x800668BC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800668C0: nop

    // 0x800668C4: addiu       $a0, $t8, 0x500
    ctx->r4 = ADD32(ctx->r24, 0X500);
    // 0x800668C8: jal         0x8006553C
    // 0x800668CC: addiu       $a1, $t8, 0x8
    ctx->r5 = ADD32(ctx->r24, 0X8);
    MobilePiece_InitFromPiece(rdram, ctx);
        goto after_1;
    // 0x800668CC: addiu       $a1, $t8, 0x8
    ctx->r5 = ADD32(ctx->r24, 0X8);
    after_1:
    // 0x800668D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800668D4: jal         0x8006677C
    // 0x800668D8: nop

    GhostPiece_DropToLanding(rdram, ctx);
        goto after_2;
    // 0x800668D8: nop

    after_2:
L_800668DC:
    // 0x800668DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800668E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800668E4: jr          $ra
    // 0x800668E8: nop

    return;
    // 0x800668E8: nop

;}

RECOMP_FUNC void GhostPiece_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800668EC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800668F0: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800668F4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800668F8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800668FC: sw          $a1, 0x520($a0)
    MEM_W(0X520, ctx->r4) = ctx->r5;
    // 0x80066900: sh          $t6, 0x528($a0)
    MEM_H(0X528, ctx->r4) = ctx->r14;
    // 0x80066904: sh          $t7, 0x524($a0)
    MEM_H(0X524, ctx->r4) = ctx->r15;
    // 0x80066908: sh          $t8, 0x526($a0)
    MEM_H(0X526, ctx->r4) = ctx->r24;
    // 0x8006690C: sb          $a2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r6;
    // 0x80066910: jr          $ra
    // 0x80066914: sb          $zero, 0x52A($a0)
    MEM_B(0X52A, ctx->r4) = 0;
    return;
    // 0x80066914: sb          $zero, 0x52A($a0)
    MEM_B(0X52A, ctx->r4) = 0;
    // 0x80066918: nop

    // 0x8006691C: nop

;}

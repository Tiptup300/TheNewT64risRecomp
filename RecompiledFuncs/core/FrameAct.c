#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FrameAct_SetState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053670: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80053674: lw          $t6, -0xDE0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XDE0);
    // 0x80053678: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8005367C: jr          $ra
    // 0x80053680: sb          $a0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r4;
    return;
    // 0x80053680: sb          $a0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r4;
;}

RECOMP_FUNC void FrameAct_StartNextPieceSlide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005368C: jal         0x800688E0
    // 0x80053690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    NextPieces_StartSlide(rdram, ctx);
        goto after_0;
    // 0x80053690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80053694: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80053698: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8005369C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800536A0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800536A4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800536A8: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
    // 0x800536AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800536B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800536B4: jr          $ra
    // 0x800536B8: nop

    return;
    // 0x800536B8: nop

;}

RECOMP_FUNC void FrameAct_UpdateFallingPiece(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800536BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800536C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800536C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800536C8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800536CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800536D0: lw          $a1, 0x9F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X9F4);
    // 0x800536D4: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x800536D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800536DC: jal         0x800677B8
    // 0x800536E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    CurrentPiece_Update(rdram, ctx);
        goto after_0;
    // 0x800536E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800536E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800536E8: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800536EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800536F0: beq         $s1, $at, L_80053708
    if (ctx->r17 == ctx->r1) {
        // 0x800536F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80053708;
    }
    // 0x800536F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800536F8: beq         $s1, $at, L_80053740
    if (ctx->r17 == ctx->r1) {
        // 0x800536FC: nop
    
            goto L_80053740;
    }
    // 0x800536FC: nop

    // 0x80053700: b           L_8005374C
    // 0x80053704: nop

        goto L_8005374C;
    // 0x80053704: nop

L_80053708:
    // 0x80053708: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005370C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80053710: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80053714: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80053718: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005371C: sb          $zero, 0x2($t8)
    MEM_B(0X2, ctx->r24) = 0;
    // 0x80053720: lw          $a0, -0x10F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X10F0);
    // 0x80053724: jal         0x80052904
    // 0x80053728: nop

    GameStats_saveCurrentPieceFallVelocity(rdram, ctx);
        goto after_1;
    // 0x80053728: nop

    after_1:
    // 0x8005372C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80053730: lw          $t0, -0x460($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X460);
    // 0x80053734: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80053738: b           L_8005374C
    // 0x8005373C: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
        goto L_8005374C;
    // 0x8005373C: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
L_80053740:
    // 0x80053740: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80053744: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80053748: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
L_8005374C:
    // 0x8005374C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80053750: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80053754: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80053758: jr          $ra
    // 0x8005375C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005375C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void FrameAct_UpdateMultisquare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053760: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80053764: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80053768: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005376C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80053770: jal         0x8006AD0C
    // 0x80053774: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    Multisquare_Update(rdram, ctx);
        goto after_0;
    // 0x80053774: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80053778: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005377C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80053780: beq         $s1, $zero, L_800537A8
    if (ctx->r17 == 0) {
        // 0x80053784: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800537A8;
    }
    // 0x80053784: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053788: beq         $s1, $at, L_800537B8
    if (ctx->r17 == ctx->r1) {
        // 0x8005378C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800537B8;
    }
    // 0x8005378C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053790: beq         $s1, $at, L_800537F4
    if (ctx->r17 == ctx->r1) {
        // 0x80053794: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800537F4;
    }
    // 0x80053794: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053798: beq         $s1, $at, L_80053820
    if (ctx->r17 == ctx->r1) {
        // 0x8005379C: nop
    
            goto L_80053820;
    }
    // 0x8005379C: nop

    // 0x800537A0: b           L_80053854
    // 0x800537A4: nop

        goto L_80053854;
    // 0x800537A4: nop

L_800537A8:
    // 0x800537A8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800537AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800537B0: b           L_80053854
    // 0x800537B4: sb          $t6, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r14;
        goto L_80053854;
    // 0x800537B4: sb          $t6, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r14;
L_800537B8:
    // 0x800537B8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800537BC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800537C0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800537C4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800537C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800537CC: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
    // 0x800537D0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800537D4: lw          $t2, -0x440($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X440);
    // 0x800537D8: lw          $t1, -0x490($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X490);
    // 0x800537DC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800537E0: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800537E4: lw          $t4, -0x440($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X440);
    // 0x800537E8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800537EC: b           L_80053854
    // 0x800537F0: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
        goto L_80053854;
    // 0x800537F0: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
L_800537F4:
    // 0x800537F4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800537F8: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x800537FC: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x80053800: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80053804: jal         0x80069EC0
    // 0x80053808: sb          $zero, 0x2($t7)
    MEM_B(0X2, ctx->r15) = 0;
    LineScan_MarkRowsDirty(rdram, ctx);
        goto after_1;
    // 0x80053808: sb          $zero, 0x2($t7)
    MEM_B(0X2, ctx->r15) = 0;
    after_1:
    // 0x8005380C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80053810: lw          $t9, -0x470($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X470);
    // 0x80053814: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80053818: b           L_80053854
    // 0x8005381C: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
        goto L_80053854;
    // 0x8005381C: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_80053820:
    // 0x80053820: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80053824: nop

    // 0x80053828: lbu         $t1, 0xC($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XC);
    // 0x8005382C: nop

    // 0x80053830: beq         $t1, $zero, L_80053844
    if (ctx->r9 == 0) {
        // 0x80053834: nop
    
            goto L_80053844;
    }
    // 0x80053834: nop

    // 0x80053838: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8005383C: b           L_80053854
    // 0x80053840: sb          $t2, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r10;
        goto L_80053854;
    // 0x80053840: sb          $t2, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r10;
L_80053844:
    // 0x80053844: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80053848: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x8005384C: jal         0x80072FC4
    // 0x80053850: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
    Garbage_UpdatePending(rdram, ctx);
        goto after_2;
    // 0x80053850: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
    after_2:
L_80053854:
    // 0x80053854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80053858: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005385C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80053860: jr          $ra
    // 0x80053864: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80053864: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void FrameAct_ProcessKeySpin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053868: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005386C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80053870: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80053874: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80053878: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005387C: lw          $a1, 0x9F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X9F4);
    // 0x80053880: lw          $a0, -0x440($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X440);
    // 0x80053884: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80053888: jal         0x8006CB10
    // 0x8005388C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    KeySpin_Process(rdram, ctx);
        goto after_0;
    // 0x8005388C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80053890: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80053894: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80053898: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005389C: beq         $s1, $at, L_800538B4
    if (ctx->r17 == ctx->r1) {
        // 0x800538A0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800538B4;
    }
    // 0x800538A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800538A4: beq         $s1, $at, L_800538EC
    if (ctx->r17 == ctx->r1) {
        // 0x800538A8: nop
    
            goto L_800538EC;
    }
    // 0x800538A8: nop

    // 0x800538AC: b           L_80053920
    // 0x800538B0: nop

        goto L_80053920;
    // 0x800538B0: nop

L_800538B4:
    // 0x800538B4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800538B8: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800538BC: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800538C0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800538C4: jal         0x80069EC0
    // 0x800538C8: sb          $zero, 0x2($t8)
    MEM_B(0X2, ctx->r24) = 0;
    LineScan_MarkRowsDirty(rdram, ctx);
        goto after_1;
    // 0x800538C8: sb          $zero, 0x2($t8)
    MEM_B(0X2, ctx->r24) = 0;
    after_1:
    // 0x800538CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800538D0: lw          $t0, -0x470($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X470);
    // 0x800538D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800538D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800538DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800538E0: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x800538E4: b           L_80053920
    // 0x800538E8: sb          $t1, -0xB0($at)
    MEM_B(-0XB0, ctx->r1) = ctx->r9;
        goto L_80053920;
    // 0x800538E8: sb          $t1, -0xB0($at)
    MEM_B(-0XB0, ctx->r1) = ctx->r9;
L_800538EC:
    // 0x800538EC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800538F0: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x800538F4: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x800538F8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800538FC: jal         0x80069E84
    // 0x80053900: sb          $zero, 0x2($t4)
    MEM_B(0X2, ctx->r12) = 0;
    LineScan_MarkAllRowsDirty(rdram, ctx);
        goto after_2;
    // 0x80053900: sb          $zero, 0x2($t4)
    MEM_B(0X2, ctx->r12) = 0;
    after_2:
    // 0x80053904: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80053908: lw          $t6, -0x470($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X470);
    // 0x8005390C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80053910: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80053914: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053918: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x8005391C: sb          $t7, -0xB0($at)
    MEM_B(-0XB0, ctx->r1) = ctx->r15;
L_80053920:
    // 0x80053920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80053924: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80053928: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005392C: jr          $ra
    // 0x80053930: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80053930: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void FrameAct_ProcessLineClears(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053934: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80053938: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005393C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80053940: jal         0x80069FB8
    // 0x80053944: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    LineScan_ProcessLineClears(rdram, ctx);
        goto after_0;
    // 0x80053944: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80053948: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8005394C: lw          $t6, -0x470($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X470);
    // 0x80053950: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053954: lbu         $s0, 0x1($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0X1);
    // 0x80053958: nop

    // 0x8005395C: beq         $s0, $at, L_80053974
    if (ctx->r16 == ctx->r1) {
        // 0x80053960: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80053974;
    }
    // 0x80053960: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053964: beq         $s0, $at, L_800539B8
    if (ctx->r16 == ctx->r1) {
        // 0x80053968: nop
    
            goto L_800539B8;
    }
    // 0x80053968: nop

    // 0x8005396C: b           L_800539D4
    // 0x80053970: nop

        goto L_800539D4;
    // 0x80053970: nop

L_80053974:
    // 0x80053974: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80053978: nop

    // 0x8005397C: lbu         $t8, 0xC($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XC);
    // 0x80053980: nop

    // 0x80053984: beq         $t8, $zero, L_80053998
    if (ctx->r24 == 0) {
        // 0x80053988: nop
    
            goto L_80053998;
    }
    // 0x80053988: nop

    // 0x8005398C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80053990: b           L_800539D4
    // 0x80053994: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
        goto L_800539D4;
    // 0x80053994: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
L_80053998:
    // 0x80053998: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005399C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800539A0: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x800539A4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800539A8: jal         0x80072FC4
    // 0x800539AC: sb          $zero, 0x2($t2)
    MEM_B(0X2, ctx->r10) = 0;
    Garbage_UpdatePending(rdram, ctx);
        goto after_1;
    // 0x800539AC: sb          $zero, 0x2($t2)
    MEM_B(0X2, ctx->r10) = 0;
    after_1:
    // 0x800539B0: b           L_800539D4
    // 0x800539B4: nop

        goto L_800539D4;
    // 0x800539B4: nop

L_800539B8:
    // 0x800539B8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800539BC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800539C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800539C4: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
    // 0x800539C8: lw          $t6, -0x460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X460);
    // 0x800539CC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800539D0: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
L_800539D4:
    // 0x800539D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800539D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800539DC: jr          $ra
    // 0x800539E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800539E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void FrameAct_UpdateGarbage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800539E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800539E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800539EC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800539F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800539F4: lw          $a0, 0x9F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X9F4);
    // 0x800539F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800539FC: jal         0x80072F1C
    // 0x80053A00: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    Garbage_Update(rdram, ctx);
        goto after_0;
    // 0x80053A00: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80053A04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80053A08: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80053A0C: beq         $s1, $zero, L_80053A9C
    if (ctx->r17 == 0) {
        // 0x80053A10: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80053A9C;
    }
    // 0x80053A10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053A14: beq         $s1, $at, L_80053A34
    if (ctx->r17 == ctx->r1) {
        // 0x80053A18: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80053A34;
    }
    // 0x80053A18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053A1C: beq         $s1, $at, L_80053A54
    if (ctx->r17 == ctx->r1) {
        // 0x80053A20: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80053A54;
    }
    // 0x80053A20: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053A24: beq         $s1, $at, L_80053A74
    if (ctx->r17 == ctx->r1) {
        // 0x80053A28: nop
    
            goto L_80053A74;
    }
    // 0x80053A28: nop

    // 0x80053A2C: b           L_80053A84
    // 0x80053A30: nop

        goto L_80053A84;
    // 0x80053A30: nop

L_80053A34:
    // 0x80053A34: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80053A38: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80053A3C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80053A40: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80053A44: jal         0x800688E0
    // 0x80053A48: sb          $zero, 0x2($t8)
    MEM_B(0X2, ctx->r24) = 0;
    NextPieces_StartSlide(rdram, ctx);
        goto after_1;
    // 0x80053A48: sb          $zero, 0x2($t8)
    MEM_B(0X2, ctx->r24) = 0;
    after_1:
    // 0x80053A4C: b           L_80053A9C
    // 0x80053A50: nop

        goto L_80053A9C;
    // 0x80053A50: nop

L_80053A54:
    // 0x80053A54: jal         0x8004376C
    // 0x80053A58: nop

    OpponentPlayer_UpdateTarget(rdram, ctx);
        goto after_2;
    // 0x80053A58: nop

    after_2:
    // 0x80053A5C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80053A60: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80053A64: jal         0x800688E0
    // 0x80053A68: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    NextPieces_StartSlide(rdram, ctx);
        goto after_3;
    // 0x80053A68: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    after_3:
    // 0x80053A6C: b           L_80053A9C
    // 0x80053A70: nop

        goto L_80053A9C;
    // 0x80053A70: nop

L_80053A74:
    // 0x80053A74: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80053A78: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80053A7C: b           L_80053A9C
    // 0x80053A80: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
        goto L_80053A9C;
    // 0x80053A80: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
L_80053A84:
    // 0x80053A84: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80053A88: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80053A8C: addiu       $a1, $a1, -0x31D0
    ctx->r5 = ADD32(ctx->r5, -0X31D0);
    // 0x80053A90: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    // 0x80053A94: jal         0x8004A5A0
    // 0x80053A98: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_4;
    // 0x80053A98: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    after_4:
L_80053A9C:
    // 0x80053A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80053AA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80053AA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80053AA8: jr          $ra
    // 0x80053AAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80053AAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void FrameAct_NextPieces_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053AB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80053AB4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80053AB8: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80053ABC: lw          $s0, 0x9F4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X9F4);
    // 0x80053AC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80053AC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80053AC8: blez        $s0, L_80053AE4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80053ACC: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_80053AE4;
    }
    // 0x80053ACC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
L_80053AD0:
    // 0x80053AD0: jal         0x80068904
    // 0x80053AD4: nop

    NextPieces_Update(rdram, ctx);
        goto after_0;
    // 0x80053AD4: nop

    after_0:
    // 0x80053AD8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80053ADC: bgtz        $s0, L_80053AD0
    if (SIGNED(ctx->r16) > 0) {
        // 0x80053AE0: nop
    
            goto L_80053AD0;
    }
    // 0x80053AE0: nop

L_80053AE4:
    // 0x80053AE4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80053AE8: lw          $t6, -0x480($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X480);
    // 0x80053AEC: nop

    // 0x80053AF0: lbu         $s1, 0x1($t6)
    ctx->r17 = MEM_BU(ctx->r14, 0X1);
    // 0x80053AF4: nop

    // 0x80053AF8: beq         $s1, $zero, L_80053B70
    if (ctx->r17 == 0) {
        // 0x80053AFC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80053B70;
    }
    // 0x80053AFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053B00: bne         $s1, $at, L_80053B5C
    if (ctx->r17 != ctx->r1) {
        // 0x80053B04: nop
    
            goto L_80053B5C;
    }
    // 0x80053B04: nop

    // 0x80053B08: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80053B0C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80053B10: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80053B14: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80053B18: nop

    // 0x80053B1C: sb          $zero, 0x1($t9)
    MEM_B(0X1, ctx->r25) = 0;
    // 0x80053B20: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80053B24: jal         0x80068B18
    // 0x80053B28: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
    NextPieces_PopNext(rdram, ctx);
        goto after_1;
    // 0x80053B28: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
    after_1:
    // 0x80053B2C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80053B30: jal         0x80067DD8
    // 0x80053B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    CurrentPiece_Spawn(rdram, ctx);
        goto after_2;
    // 0x80053B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80053B38: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80053B3C: nop

    // 0x80053B40: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x80053B44: jal         0x80066464
    // 0x80053B48: nop

    PieceHold_Enable(rdram, ctx);
        goto after_3;
    // 0x80053B48: nop

    after_3:
    // 0x80053B4C: jal         0x8004370C
    // 0x80053B50: nop

    OpponentPlayer_RequestDecision(rdram, ctx);
        goto after_4;
    // 0x80053B50: nop

    after_4:
    // 0x80053B54: b           L_80053B70
    // 0x80053B58: nop

        goto L_80053B70;
    // 0x80053B58: nop

L_80053B5C:
    // 0x80053B5C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80053B60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80053B64: addiu       $a1, $a1, -0x31AC
    ctx->r5 = ADD32(ctx->r5, -0X31AC);
    // 0x80053B68: jal         0x80083560
    // 0x80053B6C: addiu       $a0, $a0, -0x31C4
    ctx->r4 = ADD32(ctx->r4, -0X31C4);
    debug_print_reason_routine(rdram, ctx);
        goto after_5;
    // 0x80053B6C: addiu       $a0, $a0, -0x31C4
    ctx->r4 = ADD32(ctx->r4, -0X31C4);
    after_5:
L_80053B70:
    // 0x80053B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80053B74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80053B78: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80053B7C: jr          $ra
    // 0x80053B80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80053B80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void FrameAct_calls_gamefinish_something2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053B88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80053B8C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80053B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053B94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80053B98: lbu         $t7, 0xC($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XC);
    // 0x80053B9C: nop

    // 0x80053BA0: bne         $t7, $zero, L_80053C04
    if (ctx->r15 != 0) {
        // 0x80053BA4: nop
    
            goto L_80053C04;
    }
    // 0x80053BA4: nop

    // 0x80053BA8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80053BAC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80053BB0: sb          $t8, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r24;
    // 0x80053BB4: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80053BB8: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80053BBC: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80053BC0: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x80053BC4: lbu         $t2, -0x118($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X118);
    // 0x80053BC8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80053BCC: bne         $t2, $at, L_80053BF0
    if (ctx->r10 != ctx->r1) {
        // 0x80053BD0: nop
    
            goto L_80053BF0;
    }
    // 0x80053BD0: nop

    // 0x80053BD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053BD8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80053BDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80053BE0: jal         0x800532E4
    // 0x80053BE4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    gamefinish_Start(rdram, ctx);
        goto after_0;
    // 0x80053BE4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x80053BE8: b           L_80053C04
    // 0x80053BEC: nop

        goto L_80053C04;
    // 0x80053BEC: nop

L_80053BF0:
    // 0x80053BF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053BF4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80053BF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80053BFC: jal         0x800532E4
    // 0x80053C00: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    gamefinish_Start(rdram, ctx);
        goto after_1;
    // 0x80053C00: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
L_80053C04:
    // 0x80053C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053C0C: jr          $ra
    // 0x80053C10: nop

    return;
    // 0x80053C10: nop

;}

RECOMP_FUNC void FrameAct_calls_gamefinish_something(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053C14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80053C18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80053C1C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80053C20: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80053C24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80053C28: lw          $a1, 0x9F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X9F4);
    // 0x80053C2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80053C30: jal         0x80053040
    // 0x80053C34: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    gamefinish_Update(rdram, ctx);
        goto after_0;
    // 0x80053C34: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x80053C38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80053C3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053C40: bne         $s0, $at, L_80053C60
    if (ctx->r16 != ctx->r1) {
        // 0x80053C44: nop
    
            goto L_80053C60;
    }
    // 0x80053C44: nop

    // 0x80053C48: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80053C4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80053C50: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80053C54: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80053C58: nop

    // 0x80053C5C: sb          $t7, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r15;
L_80053C60:
    // 0x80053C60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80053C64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80053C68: jr          $ra
    // 0x80053C6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80053C6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void FrameAct_ScheduleEvents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053C70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053C78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80053C7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_80053C80:
    // 0x80053C80: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80053C84: lbu         $t6, -0x118($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X118);
    // 0x80053C88: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80053C8C: bne         $t6, $at, L_80053CAC
    if (ctx->r14 != ctx->r1) {
        // 0x80053C90: nop
    
            goto L_80053CAC;
    }
    // 0x80053C90: nop

    // 0x80053C94: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80053C98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053C9C: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x80053CA0: nop

    // 0x80053CA4: beq         $t8, $at, L_80053CB8
    if (ctx->r24 == ctx->r1) {
        // 0x80053CA8: nop
    
            goto L_80053CB8;
    }
    // 0x80053CA8: nop

L_80053CAC:
    // 0x80053CAC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80053CB0: nop

    // 0x80053CB4: sb          $zero, 0x1($t9)
    MEM_B(0X1, ctx->r25) = 0;
L_80053CB8:
    // 0x80053CB8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80053CBC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80053CC0: sb          $t0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r8;
    // 0x80053CC4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80053CC8: nop

    // 0x80053CCC: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80053CD0: nop

    // 0x80053CD4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80053CD8: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x80053CDC: beq         $at, $zero, L_80053D98
    if (ctx->r1 == 0) {
        // 0x80053CE0: nop
    
            goto L_80053D98;
    }
    // 0x80053CE0: nop

    // 0x80053CE4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80053CE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053CEC: addu        $at, $at, $t4
    gpr jr_addend_80053CF8 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80053CF0: lw          $t4, -0x318C($at)
    ctx->r12 = ADD32(ctx->r1, -0X318C);
    // 0x80053CF4: nop

    // 0x80053CF8: jr          $t4
    // 0x80053CFC: nop

    switch (jr_addend_80053CF8 >> 2) {
        case 0: goto L_80053D00; break;
        case 1: goto L_80053D14; break;
        case 2: goto L_80053D28; break;
        case 3: goto L_80053D3C; break;
        case 4: goto L_80053D50; break;
        case 5: goto L_80053D64; break;
        case 6: goto L_80053D78; break;
        case 7: goto L_80053D8C; break;
        default: switch_error(__func__, 0x80053CF8, 0x800DCE74);
    }
    // 0x80053CFC: nop

L_80053D00:
    // 0x80053D00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053D04: jal         0x80053684
    // 0x80053D08: nop

    FrameAct_StartNextPieceSlide(rdram, ctx);
        goto after_0;
    // 0x80053D08: nop

    after_0:
    // 0x80053D0C: b           L_80053D98
    // 0x80053D10: nop

        goto L_80053D98;
    // 0x80053D10: nop

L_80053D14:
    // 0x80053D14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053D18: jal         0x800536BC
    // 0x80053D1C: nop

    FrameAct_UpdateFallingPiece(rdram, ctx);
        goto after_1;
    // 0x80053D1C: nop

    after_1:
    // 0x80053D20: b           L_80053D98
    // 0x80053D24: nop

        goto L_80053D98;
    // 0x80053D24: nop

L_80053D28:
    // 0x80053D28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053D2C: jal         0x80053760
    // 0x80053D30: nop

    FrameAct_UpdateMultisquare(rdram, ctx);
        goto after_2;
    // 0x80053D30: nop

    after_2:
    // 0x80053D34: b           L_80053D98
    // 0x80053D38: nop

        goto L_80053D98;
    // 0x80053D38: nop

L_80053D3C:
    // 0x80053D3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053D40: jal         0x80053868
    // 0x80053D44: nop

    FrameAct_ProcessKeySpin(rdram, ctx);
        goto after_3;
    // 0x80053D44: nop

    after_3:
    // 0x80053D48: b           L_80053D98
    // 0x80053D4C: nop

        goto L_80053D98;
    // 0x80053D4C: nop

L_80053D50:
    // 0x80053D50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053D54: jal         0x80053934
    // 0x80053D58: nop

    FrameAct_ProcessLineClears(rdram, ctx);
        goto after_4;
    // 0x80053D58: nop

    after_4:
    // 0x80053D5C: b           L_80053D98
    // 0x80053D60: nop

        goto L_80053D98;
    // 0x80053D60: nop

L_80053D64:
    // 0x80053D64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053D68: jal         0x800539E4
    // 0x80053D6C: nop

    FrameAct_UpdateGarbage(rdram, ctx);
        goto after_5;
    // 0x80053D6C: nop

    after_5:
    // 0x80053D70: b           L_80053D98
    // 0x80053D74: nop

        goto L_80053D98;
    // 0x80053D74: nop

L_80053D78:
    // 0x80053D78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053D7C: jal         0x80053AB0
    // 0x80053D80: nop

    FrameAct_NextPieces_Update(rdram, ctx);
        goto after_6;
    // 0x80053D80: nop

    after_6:
    // 0x80053D84: b           L_80053D98
    // 0x80053D88: nop

        goto L_80053D98;
    // 0x80053D88: nop

L_80053D8C:
    // 0x80053D8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053D90: jal         0x80053C14
    // 0x80053D94: nop

    FrameAct_calls_gamefinish_something(rdram, ctx);
        goto after_7;
    // 0x80053D94: nop

    after_7:
L_80053D98:
    // 0x80053D98: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80053D9C: nop

    // 0x80053DA0: lbu         $t6, 0x2($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X2);
    // 0x80053DA4: nop

    // 0x80053DA8: beq         $t6, $zero, L_80053C80
    if (ctx->r14 == 0) {
        // 0x80053DAC: nop
    
            goto L_80053C80;
    }
    // 0x80053DAC: nop

    // 0x80053DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053DB8: jr          $ra
    // 0x80053DBC: nop

    return;
    // 0x80053DBC: nop

;}

RECOMP_FUNC void FrameAct_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053DC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80053DC8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80053DCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053DD0: lbu         $t7, 0xC($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XC);
    // 0x80053DD4: nop

    // 0x80053DD8: beq         $t7, $zero, L_80053DE8
    if (ctx->r15 == 0) {
        // 0x80053DDC: nop
    
            goto L_80053DE8;
    }
    // 0x80053DDC: nop

    // 0x80053DE0: jal         0x80053280
    // 0x80053DE4: addiu       $a0, $t6, 0x10
    ctx->r4 = ADD32(ctx->r14, 0X10);
    gamefinish_Draw(rdram, ctx);
        goto after_0;
    // 0x80053DE4: addiu       $a0, $t6, 0x10
    ctx->r4 = ADD32(ctx->r14, 0X10);
    after_0:
L_80053DE8:
    // 0x80053DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053DF0: jr          $ra
    // 0x80053DF4: nop

    return;
    // 0x80053DF4: nop

;}

RECOMP_FUNC void FrameAct_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053DFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80053E00: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80053E04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053E08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80053E0C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80053E10: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80053E14: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80053E18: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80053E1C: nop

    // 0x80053E20: sb          $zero, 0x3($t7)
    MEM_B(0X3, ctx->r15) = 0;
    // 0x80053E24: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80053E28: nop

    // 0x80053E2C: sb          $zero, 0xC($t8)
    MEM_B(0XC, ctx->r24) = 0;
    // 0x80053E30: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80053E34: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80053E38: nop

    // 0x80053E3C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80053E40: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80053E44: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80053E48: nop

    // 0x80053E4C: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80053E50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053E54: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80053E58: jal         0x80053390
    // 0x80053E5C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    gamefinish_StopAtBoardCenter(rdram, ctx);
        goto after_0;
    // 0x80053E5C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x80053E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053E64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053E68: jr          $ra
    // 0x80053E6C: nop

    return;
    // 0x80053E6C: nop

;}

RECOMP_FUNC void FrameAct_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053E70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053E74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80053E78: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80053E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053E80: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80053E84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053E88: jal         0x80053400
    // 0x80053E8C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    gamefinish_Stop(rdram, ctx);
        goto after_0;
    // 0x80053E8C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x80053E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053E98: jr          $ra
    // 0x80053E9C: nop

    return;
    // 0x80053E9C: nop

;}

RECOMP_FUNC void FrameAct_TimerExpired(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053EA0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80053EA4: nop

    // 0x80053EA8: bne         $t6, $zero, L_80053EB8
    if (ctx->r14 != 0) {
        // 0x80053EAC: nop
    
            goto L_80053EB8;
    }
    // 0x80053EAC: nop

    // 0x80053EB0: jr          $ra
    // 0x80053EB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80053EB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80053EB8:
    // 0x80053EB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80053EBC: jr          $ra
    // 0x80053EC0: nop

    return;
    // 0x80053EC0: nop

;}

RECOMP_FUNC void FrameAct_TimerTick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053EC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053EC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80053ECC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80053ED0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80053ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053ED8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80053EDC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80053EE0: nop

    // 0x80053EE4: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80053EE8: beq         $at, $zero, L_80053EF8
    if (ctx->r1 == 0) {
        // 0x80053EEC: nop
    
            goto L_80053EF8;
    }
    // 0x80053EEC: nop

    // 0x80053EF0: b           L_80053F10
    // 0x80053EF4: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
        goto L_80053F10;
    // 0x80053EF4: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_80053EF8:
    // 0x80053EF8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80053EFC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80053F00: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80053F04: nop

    // 0x80053F08: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80053F0C: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
L_80053F10:
    // 0x80053F10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053F14: jal         0x80053EA0
    // 0x80053F18: nop

    FrameAct_TimerExpired(rdram, ctx);
        goto after_0;
    // 0x80053F18: nop

    after_0:
    // 0x80053F1C: beq         $v0, $zero, L_80053F2C
    if (ctx->r2 == 0) {
        // 0x80053F20: nop
    
            goto L_80053F2C;
    }
    // 0x80053F20: nop

    // 0x80053F24: b           L_80053F30
    // 0x80053F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80053F30;
    // 0x80053F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80053F2C:
    // 0x80053F2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80053F30:
    // 0x80053F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053F38: jr          $ra
    // 0x80053F3C: nop

    return;
    // 0x80053F3C: nop

;}

RECOMP_FUNC void FrameAct_SetTimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053F40: jr          $ra
    // 0x80053F44: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    return;
    // 0x80053F44: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
;}

RECOMP_FUNC void FrameAct_Deinit_doesnothing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053F48: jr          $ra
    // 0x80053F4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80053F4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

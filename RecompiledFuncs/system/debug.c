#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void debug_print_reason_routine_linenum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A5A0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8004A5A4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8004A5A8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8004A5AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004A5B0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8004A5B4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8004A5B8: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8004A5BC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004A5C0: addiu       $a1, $a1, -0x3F70
    ctx->r5 = ADD32(ctx->r5, -0X3F70);
    // 0x8004A5C4: jal         0x800B62D4
    // 0x8004A5C8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8004A5C8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8004A5CC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8004A5D0: jal         0x80083560
    // 0x8004A5D4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    debug_print_reason_routine(rdram, ctx);
        goto after_1;
    // 0x8004A5D4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8004A5D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004A5DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8004A5E0: jr          $ra
    // 0x8004A5E4: nop

    return;
    // 0x8004A5E4: nop

    // 0x8004A5E8: nop

    // 0x8004A5EC: nop

;}

RECOMP_FUNC void FUN_010870_interesting_stuff_large_liner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A5F0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8004A5F4: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8004A5F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004A5FC: bne         $t6, $zero, L_8004A624
    if (ctx->r14 != 0) {
        // 0x8004A600: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8004A624;
    }
    // 0x8004A600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004A604: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8004A608: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A60C: sb          $t7, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r15;
    // 0x8004A610: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A614: sh          $zero, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = 0;
    // 0x8004A618: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A61C: b           L_8004ABD8
    // 0x8004A620: sw          $zero, -0x1AC($at)
    MEM_W(-0X1AC, ctx->r1) = 0;
        goto L_8004ABD8;
    // 0x8004A620: sw          $zero, -0x1AC($at)
    MEM_W(-0X1AC, ctx->r1) = 0;
L_8004A624:
    // 0x8004A624: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004A628: lw          $a0, -0xDF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XDF0);
    // 0x8004A62C: jal         0x800A3534
    // 0x8004A630: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800A3534(rdram, ctx);
        goto after_0;
    // 0x8004A630: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8004A634: beq         $v0, $zero, L_8004A664
    if (ctx->r2 == 0) {
        // 0x8004A638: nop
    
            goto L_8004A664;
    }
    // 0x8004A638: nop

L_8004A63C:
    // 0x8004A63C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004A640: lw          $a0, -0xDF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XDF0);
    // 0x8004A644: jal         0x800A33E4
    // 0x8004A648: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800A33E4(rdram, ctx);
        goto after_1;
    // 0x8004A648: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x8004A64C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004A650: lw          $a0, -0xDF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XDF0);
    // 0x8004A654: jal         0x800A3534
    // 0x8004A658: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800A3534(rdram, ctx);
        goto after_2;
    // 0x8004A658: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x8004A65C: bne         $v0, $zero, L_8004A63C
    if (ctx->r2 != 0) {
        // 0x8004A660: nop
    
            goto L_8004A63C;
    }
    // 0x8004A660: nop

L_8004A664:
    // 0x8004A664: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004A668: lw          $t8, -0xDF0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XDF0);
    // 0x8004A66C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004A670: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8004A674: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A678: sw          $t9, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r25;
    // 0x8004A67C: lw          $t0, -0xDF0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XDF0);
    // 0x8004A680: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004A684: lw          $t3, 0x1C($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X1C);
    // 0x8004A688: lw          $t1, 0x20($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20);
    // 0x8004A68C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8004A690: xor         $t2, $t1, $at
    ctx->r10 = ctx->r9 ^ ctx->r1;
    // 0x8004A694: and         $t5, $t2, $t4
    ctx->r13 = ctx->r10 & ctx->r12;
    // 0x8004A698: sw          $t5, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r13;
    // 0x8004A69C: lw          $t6, -0xDF0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XDF0);
    // 0x8004A6A0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8004A6A4: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x8004A6A8: nop

    // 0x8004A6AC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8004A6B0: nop

    // 0x8004A6B4: sw          $t9, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r25;
    // 0x8004A6B8: lw          $t8, -0x1AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1AC);
    // 0x8004A6BC: nop

    // 0x8004A6C0: beq         $t8, $zero, L_8004ABD8
    if (ctx->r24 == 0) {
        // 0x8004A6C4: nop
    
            goto L_8004ABD8;
    }
    // 0x8004A6C4: nop

    // 0x8004A6C8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8004A6CC: lbu         $t1, 0x1A0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1A0);
    // 0x8004A6D0: nop

    // 0x8004A6D4: andi        $t3, $t1, 0x1
    ctx->r11 = ctx->r9 & 0X1;
    // 0x8004A6D8: bne         $t3, $zero, L_8004A73C
    if (ctx->r11 != 0) {
        // 0x8004A6DC: nop
    
            goto L_8004A73C;
    }
    // 0x8004A6DC: nop

    // 0x8004A6E0: jal         0x80061124
    // 0x8004A6E4: nop

    PFGFX_SetViModeRequest(rdram, ctx);
        goto after_3;
    // 0x8004A6E4: nop

    after_3:
    // 0x8004A6E8: jal         0x80060D58
    // 0x8004A6EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80060D58(rdram, ctx);
        goto after_4;
    // 0x8004A6EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8004A6F0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004A6F4: addiu       $a1, $a1, 0xA70
    ctx->r5 = ADD32(ctx->r5, 0XA70);
    // 0x8004A6F8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8004A6FC: jal         0x80084E20
    // 0x8004A700: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Audio_StartSong(rdram, ctx);
        goto after_5;
    // 0x8004A700: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8004A704: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004A708: jal         0x80087784
    // 0x8004A70C: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    Audio2_GFXDone_SendPlayMessage(rdram, ctx);
        goto after_6;
    // 0x8004A70C: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    after_6:
    // 0x8004A710: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A714: sb          $zero, -0x118($at)
    MEM_B(-0X118, ctx->r1) = 0;
    // 0x8004A718: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A71C: sw          $zero, -0x1AC($at)
    MEM_W(-0X1AC, ctx->r1) = 0;
    // 0x8004A720: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    // 0x8004A724: jal         0x80061134
    // 0x8004A728: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    PFGFX_ClearCellGrids(rdram, ctx);
        goto after_7;
    // 0x8004A728: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_7:
    // 0x8004A72C: jal         0x80060D58
    // 0x8004A730: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80060D58(rdram, ctx);
        goto after_8;
    // 0x8004A730: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x8004A734: b           L_8004ABD8
    // 0x8004A738: nop

        goto L_8004ABD8;
    // 0x8004A738: nop

L_8004A73C:
    // 0x8004A73C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004A740: lw          $t4, -0xDF0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XDF0);
    // 0x8004A744: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8004A748: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8004A74C: lbu         $t2, -0x1A4($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X1A4);
    // 0x8004A750: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8004A754: sllv        $t7, $t0, $t5
    ctx->r15 = S32(ctx->r8 << (ctx->r13 & 31));
    // 0x8004A758: and         $t9, $t2, $t7
    ctx->r25 = ctx->r10 & ctx->r15;
    // 0x8004A75C: beq         $t9, $zero, L_8004ABAC
    if (ctx->r25 == 0) {
        // 0x8004A760: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_8004ABAC;
    }
    // 0x8004A760: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8004A764: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A768: sw          $t5, 0x584($at)
    MEM_W(0X584, ctx->r1) = ctx->r13;
    // 0x8004A76C: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    // 0x8004A770: jal         0x8003B654
    // 0x8004A774: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    Controller_GetStatus(rdram, ctx);
        goto after_9;
    // 0x8004A774: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_9:
    // 0x8004A778: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8004A77C: lw          $t8, 0x584($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X584);
    // 0x8004A780: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8004A784: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004A788: lbu         $t6, -0x1A4($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X1A4);
    // 0x8004A78C: sllv        $t3, $t1, $t8
    ctx->r11 = S32(ctx->r9 << (ctx->r24 & 31));
    // 0x8004A790: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8004A794: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x8004A798: sw          $v0, 0x588($at)
    MEM_W(0X588, ctx->r1) = ctx->r2;
    // 0x8004A79C: and         $t0, $t6, $t4
    ctx->r8 = ctx->r14 & ctx->r12;
    // 0x8004A7A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A7A4: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x8004A7A8: bne         $t2, $zero, L_8004A7BC
    if (ctx->r10 != 0) {
        // 0x8004A7AC: sb          $t0, -0x1A4($at)
        MEM_B(-0X1A4, ctx->r1) = ctx->r8;
            goto L_8004A7BC;
    }
    // 0x8004A7AC: sb          $t0, -0x1A4($at)
    MEM_B(-0X1A4, ctx->r1) = ctx->r8;
    // 0x8004A7B0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8004A7B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A7B8: sw          $t7, -0x1AC($at)
    MEM_W(-0X1AC, ctx->r1) = ctx->r15;
L_8004A7BC:
    // 0x8004A7BC: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8004A7C0: lw          $t9, 0x588($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X588);
    // 0x8004A7C4: nop

    // 0x8004A7C8: andi        $t5, $t9, 0x2
    ctx->r13 = ctx->r25 & 0X2;
    // 0x8004A7CC: beq         $t5, $zero, L_8004A82C
    if (ctx->r13 == 0) {
        // 0x8004A7D0: nop
    
            goto L_8004A82C;
    }
    // 0x8004A7D0: nop

    // 0x8004A7D4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A7D8: jal         0x8003B5D0
    // 0x8004A7DC: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    Controller_SendRecvMsg(rdram, ctx);
        goto after_10;
    // 0x8004A7DC: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_10:
    // 0x8004A7E0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A7E4: jal         0x8003B5D0
    // 0x8004A7E8: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    Controller_SendRecvMsg(rdram, ctx);
        goto after_11;
    // 0x8004A7E8: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_11:
    // 0x8004A7EC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A7F0: jal         0x8003B5D0
    // 0x8004A7F4: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    Controller_SendRecvMsg(rdram, ctx);
        goto after_12;
    // 0x8004A7F4: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_12:
    // 0x8004A7F8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8004A7FC: lw          $a1, 0x584($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X584);
    // 0x8004A800: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A804: jal         0x8003B654
    // 0x8004A808: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    Controller_GetStatus(rdram, ctx);
        goto after_13;
    // 0x8004A808: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_13:
    // 0x8004A80C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8004A810: sw          $v0, 0x588($at)
    MEM_W(0X588, ctx->r1) = ctx->r2;
    // 0x8004A814: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8004A818: lw          $t1, 0x588($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X588);
    // 0x8004A81C: nop

    // 0x8004A820: andi        $t8, $t1, 0x2
    ctx->r24 = ctx->r9 & 0X2;
    // 0x8004A824: bne         $t8, $zero, L_8004ABD8
    if (ctx->r24 != 0) {
        // 0x8004A828: nop
    
            goto L_8004ABD8;
    }
    // 0x8004A828: nop

L_8004A82C:
    // 0x8004A82C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8004A830: lw          $t3, 0x588($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X588);
    // 0x8004A834: nop

    // 0x8004A838: andi        $t6, $t3, 0x1
    ctx->r14 = ctx->r11 & 0X1;
    // 0x8004A83C: beq         $t6, $zero, L_8004AA00
    if (ctx->r14 == 0) {
        // 0x8004A840: nop
    
            goto L_8004AA00;
    }
    // 0x8004A840: nop

    // 0x8004A844: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x8004A848: bne         $t4, $zero, L_8004AA00
    if (ctx->r12 != 0) {
        // 0x8004A84C: nop
    
            goto L_8004AA00;
    }
    // 0x8004A84C: nop

    // 0x8004A850: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8004A854: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A858: lw          $a1, 0x584($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X584);
    // 0x8004A85C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A860: sb          $zero, -0x1B0($at)
    MEM_B(-0X1B0, ctx->r1) = 0;
    // 0x8004A864: jal         0x8003B684
    // 0x8004A868: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    Pfs_InitPak(rdram, ctx);
        goto after_14;
    // 0x8004A868: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_14:
    // 0x8004A86C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A870: sb          $v0, -0x1B0($at)
    MEM_B(-0X1B0, ctx->r1) = ctx->r2;
    // 0x8004A874: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8004A878: lbu         $t0, -0x1B0($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X1B0);
    // 0x8004A87C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004A880: sra         $t2, $t0, 4
    ctx->r10 = S32(SIGNED(ctx->r8) >> 4);
    // 0x8004A884: andi        $t7, $t2, 0xF
    ctx->r15 = ctx->r10 & 0XF;
    // 0x8004A888: beq         $t7, $at, L_8004A8A0
    if (ctx->r15 == ctx->r1) {
        // 0x8004A88C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004A8A0;
    }
    // 0x8004A88C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004A890: beq         $t7, $at, L_8004A8A0
    if (ctx->r15 == ctx->r1) {
        // 0x8004A894: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8004A8A0;
    }
    // 0x8004A894: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004A898: bne         $t7, $at, L_8004A93C
    if (ctx->r15 != ctx->r1) {
        // 0x8004A89C: nop
    
            goto L_8004A93C;
    }
    // 0x8004A89C: nop

L_8004A8A0:
    // 0x8004A8A0: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x8004A8A4: lw          $t5, 0x584($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X584);
    // 0x8004A8A8: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8004A8AC: lhu         $t9, 0x3EE($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X3EE);
    // 0x8004A8B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004A8B4: sllv        $t8, $t1, $t5
    ctx->r24 = S32(ctx->r9 << (ctx->r13 & 31));
    // 0x8004A8B8: and         $t6, $t9, $t8
    ctx->r14 = ctx->r25 & ctx->r24;
    // 0x8004A8BC: beq         $t6, $zero, L_8004A8CC
    if (ctx->r14 == 0) {
        // 0x8004A8C0: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8004A8CC;
    }
    // 0x8004A8C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A8C4: b           L_8004AA00
    // 0x8004A8C8: sb          $zero, -0x1B0($at)
    MEM_B(-0X1B0, ctx->r1) = 0;
        goto L_8004AA00;
    // 0x8004A8C8: sb          $zero, -0x1B0($at)
    MEM_B(-0X1B0, ctx->r1) = 0;
L_8004A8CC:
    // 0x8004A8CC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8004A8D0: lw          $a1, 0x584($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X584);
    // 0x8004A8D4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A8D8: jal         0x8003BC3C
    // 0x8004A8DC: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    Gbpak_Init(rdram, ctx);
        goto after_15;
    // 0x8004A8DC: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_15:
    // 0x8004A8E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8004A8E4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A8E8: nop

    // 0x8004A8EC: bne         $t3, $zero, L_8004A8FC
    if (ctx->r11 != 0) {
        // 0x8004A8F0: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8004A8FC;
    }
    // 0x8004A8F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A8F4: b           L_8004AA00
    // 0x8004A8F8: sb          $zero, -0x1B0($at)
    MEM_B(-0X1B0, ctx->r1) = 0;
        goto L_8004AA00;
    // 0x8004A8F8: sb          $zero, -0x1B0($at)
    MEM_B(-0X1B0, ctx->r1) = 0;
L_8004A8FC:
    // 0x8004A8FC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8004A900: lw          $a1, 0x584($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X584);
    // 0x8004A904: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A908: jal         0x8003B684
    // 0x8004A90C: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    Pfs_InitPak(rdram, ctx);
        goto after_16;
    // 0x8004A90C: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_16:
    // 0x8004A910: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A914: sb          $v0, -0x1B0($at)
    MEM_B(-0X1B0, ctx->r1) = ctx->r2;
    // 0x8004A918: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A91C: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x8004A920: sb          $t4, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r12;
    // 0x8004A924: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A928: sw          $zero, -0x1AC($at)
    MEM_W(-0X1AC, ctx->r1) = 0;
    // 0x8004A92C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A930: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8004A934: b           L_8004ABD8
    // 0x8004A938: sh          $t0, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r8;
        goto L_8004ABD8;
    // 0x8004A938: sh          $t0, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r8;
L_8004A93C:
    // 0x8004A93C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8004A940: lw          $a1, 0x584($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X584);
    // 0x8004A944: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A948: jal         0x8003BA0C
    // 0x8004A94C: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    Pfs_NumFiles(rdram, ctx);
        goto after_17;
    // 0x8004A94C: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_17:
    // 0x8004A950: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x8004A954: slti        $at, $t2, 0x10
    ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
    // 0x8004A958: beq         $at, $zero, L_8004A984
    if (ctx->r1 == 0) {
        // 0x8004A95C: nop
    
            goto L_8004A984;
    }
    // 0x8004A95C: nop

    // 0x8004A960: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8004A964: lw          $a2, 0x584($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X584);
    // 0x8004A968: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004A96C: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    // 0x8004A970: jal         0x8003BBB0
    // 0x8004A974: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Pfs_FreeBlocks(rdram, ctx);
        goto after_18;
    // 0x8004A974: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x8004A978: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x8004A97C: beq         $at, $zero, L_8004A9F8
    if (ctx->r1 == 0) {
        // 0x8004A980: nop
    
            goto L_8004A9F8;
    }
    // 0x8004A980: nop

L_8004A984:
    // 0x8004A984: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8004A988: lw          $t7, 0x584($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X584);
    // 0x8004A98C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004A990: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x8004A994: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x8004A998: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8004A99C: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x8004A9A0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8004A9A4: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x8004A9A8: lw          $t5, -0x10AC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X10AC);
    // 0x8004A9AC: nop

    // 0x8004A9B0: andi        $t9, $t5, 0x1000
    ctx->r25 = ctx->r13 & 0X1000;
    // 0x8004A9B4: beq         $t9, $zero, L_8004A9CC
    if (ctx->r25 == 0) {
        // 0x8004A9B8: nop
    
            goto L_8004A9CC;
    }
    // 0x8004A9B8: nop

    // 0x8004A9BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004A9C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A9C4: b           L_8004A9D4
    // 0x8004A9C8: sb          $t8, -0x1A8($at)
    MEM_B(-0X1A8, ctx->r1) = ctx->r24;
        goto L_8004A9D4;
    // 0x8004A9C8: sb          $t8, -0x1A8($at)
    MEM_B(-0X1A8, ctx->r1) = ctx->r24;
L_8004A9CC:
    // 0x8004A9CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A9D0: sb          $zero, -0x1A8($at)
    MEM_B(-0X1A8, ctx->r1) = 0;
L_8004A9D4:
    // 0x8004A9D4: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8004A9D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A9DC: sb          $t6, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r14;
    // 0x8004A9E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A9E4: sw          $zero, -0x1AC($at)
    MEM_W(-0X1AC, ctx->r1) = 0;
    // 0x8004A9E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A9EC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8004A9F0: b           L_8004ABD8
    // 0x8004A9F4: sh          $t3, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r11;
        goto L_8004ABD8;
    // 0x8004A9F4: sh          $t3, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r11;
L_8004A9F8:
    // 0x8004A9F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A9FC: sb          $zero, -0x1B0($at)
    MEM_B(-0X1B0, ctx->r1) = 0;
L_8004AA00:
    // 0x8004AA00: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8004AA04: lw          $t4, 0x584($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X584);
    // 0x8004AA08: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8004AA0C: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x8004AA10: subu        $t0, $t0, $t4
    ctx->r8 = SUB32(ctx->r8, ctx->r12);
    // 0x8004AA14: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004AA18: subu        $t0, $t0, $t4
    ctx->r8 = SUB32(ctx->r8, ctx->r12);
    // 0x8004AA1C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004AA20: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8004AA24: lw          $t2, -0x10AC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X10AC);
    // 0x8004AA28: nop

    // 0x8004AA2C: andi        $t7, $t2, 0x1000
    ctx->r15 = ctx->r10 & 0X1000;
    // 0x8004AA30: bne         $t7, $zero, L_8004AA4C
    if (ctx->r15 != 0) {
        // 0x8004AA34: nop
    
            goto L_8004AA4C;
    }
    // 0x8004AA34: nop

    // 0x8004AA38: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8004AA3C: lbu         $t1, -0x1B0($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X1B0);
    // 0x8004AA40: nop

    // 0x8004AA44: beq         $t1, $zero, L_8004ABAC
    if (ctx->r9 == 0) {
        // 0x8004AA48: nop
    
            goto L_8004ABAC;
    }
    // 0x8004AA48: nop

L_8004AA4C:
    // 0x8004AA4C: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x8004AA50: lw          $t5, 0x584($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X584);
    // 0x8004AA54: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004AA58: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8004AA5C: subu        $t9, $t9, $t5
    ctx->r25 = SUB32(ctx->r25, ctx->r13);
    // 0x8004AA60: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004AA64: subu        $t9, $t9, $t5
    ctx->r25 = SUB32(ctx->r25, ctx->r13);
    // 0x8004AA68: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004AA6C: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8004AA70: lw          $t8, -0x10AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X10AC);
    // 0x8004AA74: nop

    // 0x8004AA78: andi        $t6, $t8, 0x4000
    ctx->r14 = ctx->r24 & 0X4000;
    // 0x8004AA7C: bne         $t6, $zero, L_8004ABD8
    if (ctx->r14 != 0) {
        // 0x8004AA80: nop
    
            goto L_8004ABD8;
    }
    // 0x8004AA80: nop

    // 0x8004AA84: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004AA88: lw          $t4, -0xDF0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XDF0);
    // 0x8004AA8C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004AA90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004AA94: sb          $t3, -0x1A8($at)
    MEM_B(-0X1A8, ctx->r1) = ctx->r11;
    // 0x8004AA98: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8004AA9C: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x8004AAA0: lh          $t0, 0x0($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X0);
    // 0x8004AAA4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8004AAA8: bne         $t2, $zero, L_8004AAC8
    if (ctx->r10 != 0) {
        // 0x8004AAAC: sw          $t0, 0x584($at)
        MEM_W(0X584, ctx->r1) = ctx->r8;
            goto L_8004AAC8;
    }
    // 0x8004AAAC: sw          $t0, 0x584($at)
    MEM_W(0X584, ctx->r1) = ctx->r8;
    // 0x8004AAB0: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8004AAB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004AAB8: sb          $t7, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r15;
    // 0x8004AABC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004AAC0: b           L_8004ABD8
    // 0x8004AAC4: sh          $zero, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = 0;
        goto L_8004ABD8;
    // 0x8004AAC4: sh          $zero, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = 0;
L_8004AAC8:
    // 0x8004AAC8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8004AACC: lw          $t1, 0x588($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X588);
    // 0x8004AAD0: nop

    // 0x8004AAD4: andi        $t5, $t1, 0x1
    ctx->r13 = ctx->r9 & 0X1;
    // 0x8004AAD8: beq         $t5, $zero, L_8004AB9C
    if (ctx->r13 == 0) {
        // 0x8004AADC: nop
    
            goto L_8004AB9C;
    }
    // 0x8004AADC: nop

    // 0x8004AAE0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8004AAE4: lw          $a1, 0x584($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X584);
    // 0x8004AAE8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004AAEC: jal         0x8003B684
    // 0x8004AAF0: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    Pfs_InitPak(rdram, ctx);
        goto after_19;
    // 0x8004AAF0: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_19:
    // 0x8004AAF4: sra         $t9, $v0, 4
    ctx->r25 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8004AAF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8004AAFC: sw          $t9, 0x588($at)
    MEM_W(0X588, ctx->r1) = ctx->r25;
    // 0x8004AB00: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8004AB04: lw          $t8, 0x588($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X588);
    // 0x8004AB08: nop

    // 0x8004AB0C: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8004AB10: beq         $t6, $zero, L_8004AB88
    if (ctx->r14 == 0) {
        // 0x8004AB14: nop
    
            goto L_8004AB88;
    }
    // 0x8004AB14: nop

    // 0x8004AB18: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8004AB1C: lw          $a1, 0x584($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X584);
    // 0x8004AB20: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004AB24: jal         0x8003BC3C
    // 0x8004AB28: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    Gbpak_Init(rdram, ctx);
        goto after_20;
    // 0x8004AB28: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_20:
    // 0x8004AB2C: bne         $v0, $zero, L_8004AB4C
    if (ctx->r2 != 0) {
        // 0x8004AB30: nop
    
            goto L_8004AB4C;
    }
    // 0x8004AB30: nop

    // 0x8004AB34: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8004AB38: lw          $t3, -0x1AC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X1AC);
    // 0x8004AB3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004AB40: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8004AB44: b           L_8004ABD8
    // 0x8004AB48: sw          $t4, -0x1AC($at)
    MEM_W(-0X1AC, ctx->r1) = ctx->r12;
        goto L_8004ABD8;
    // 0x8004AB48: sw          $t4, -0x1AC($at)
    MEM_W(-0X1AC, ctx->r1) = ctx->r12;
L_8004AB4C:
    // 0x8004AB4C: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8004AB50: lw          $t2, 0x584($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X584);
    // 0x8004AB54: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8004AB58: lhu         $t0, 0x3EE($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X3EE);
    // 0x8004AB5C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004AB60: sllv        $t1, $t7, $t2
    ctx->r9 = S32(ctx->r15 << (ctx->r10 & 31));
    // 0x8004AB64: and         $t5, $t0, $t1
    ctx->r13 = ctx->r8 & ctx->r9;
    // 0x8004AB68: beq         $t5, $zero, L_8004ABD8
    if (ctx->r13 == 0) {
        // 0x8004AB6C: nop
    
            goto L_8004ABD8;
    }
    // 0x8004AB6C: nop

    // 0x8004AB70: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8004AB74: lw          $t9, -0x1AC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1AC);
    // 0x8004AB78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004AB7C: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x8004AB80: b           L_8004ABD8
    // 0x8004AB84: sw          $t8, -0x1AC($at)
    MEM_W(-0X1AC, ctx->r1) = ctx->r24;
        goto L_8004ABD8;
    // 0x8004AB84: sw          $t8, -0x1AC($at)
    MEM_W(-0X1AC, ctx->r1) = ctx->r24;
L_8004AB88:
    // 0x8004AB88: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8004AB8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004AB90: sb          $t6, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r14;
    // 0x8004AB94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004AB98: sw          $zero, -0x1AC($at)
    MEM_W(-0X1AC, ctx->r1) = 0;
L_8004AB9C:
    // 0x8004AB9C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8004ABA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004ABA4: b           L_8004ABD8
    // 0x8004ABA8: sh          $t3, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r11;
        goto L_8004ABD8;
    // 0x8004ABA8: sh          $t3, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r11;
L_8004ABAC:
    // 0x8004ABAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004ABB0: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8004ABB4: lw          $t4, -0x1AC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1AC);
    // 0x8004ABB8: sb          $zero, -0x1A8($at)
    MEM_B(-0X1A8, ctx->r1) = 0;
    // 0x8004ABBC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004ABC0: bne         $t4, $at, L_8004ABD8
    if (ctx->r12 != ctx->r1) {
        // 0x8004ABC4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8004ABD8;
    }
    // 0x8004ABC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004ABC8: sw          $zero, -0x1AC($at)
    MEM_W(-0X1AC, ctx->r1) = 0;
    // 0x8004ABCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004ABD0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8004ABD4: sb          $t7, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r15;
L_8004ABD8:
    // 0x8004ABD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004ABDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004ABE0: jr          $ra
    // 0x8004ABE4: nop

    return;
    // 0x8004ABE4: nop

;}

RECOMP_FUNC void debug_print2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF08: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006CF0C: jr          $ra
    // 0x8006CF10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8006CF10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}

RECOMP_FUNC void FUN_032F00_MVC_control_menu_choice_process(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF14: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006CF18: lbu         $t6, -0x118($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X118);
    // 0x8006CF1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006CF20: sltiu       $at, $t6, 0x12
    ctx->r1 = ctx->r14 < 0X12 ? 1 : 0;
    // 0x8006CF24: beq         $at, $zero, L_8006D07C
    if (ctx->r1 == 0) {
        // 0x8006CF28: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8006D07C;
    }
    // 0x8006CF28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006CF2C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006CF30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CF34: addu        $at, $at, $t6
    gpr jr_addend_8006CF40 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8006CF38: lw          $t6, -0x2840($at)
    ctx->r14 = ADD32(ctx->r1, -0X2840);
    // 0x8006CF3C: nop

    // 0x8006CF40: jr          $t6
    // 0x8006CF44: nop

    switch (jr_addend_8006CF40 >> 2) {
        case 0: goto L_8006CF48; break;
        case 1: goto L_8006CF68; break;
        case 2: goto L_8006CF78; break;
        case 3: goto L_8006CF88; break;
        case 4: goto L_8006CF98; break;
        case 5: goto L_8006D07C; break;
        case 6: goto L_8006D07C; break;
        case 7: goto L_8006CFA8; break;
        case 8: goto L_8006CFC0; break;
        case 9: goto L_8006CFE8; break;
        case 10: goto L_8006D028; break;
        case 11: goto L_8006CFD8; break;
        case 12: goto L_8006CFF8; break;
        case 13: goto L_8006D018; break;
        case 14: goto L_8006CF58; break;
        case 15: goto L_8006D07C; break;
        case 16: goto L_8006D008; break;
        case 17: goto L_8006D038; break;
        default: switch_error(__func__, 0x8006CF40, 0x800DD7C0);
    }
    // 0x8006CF44: nop

L_8006CF48:
    // 0x8006CF48: jal         0x80061740
    // 0x8006CF4C: nop

    FUN_0279C0_80061740_switch_0to8_1to6_same(rdram, ctx);
        goto after_0;
    // 0x8006CF4C: nop

    after_0:
    // 0x8006CF50: b           L_8006D07C
    // 0x8006CF54: nop

        goto L_8006D07C;
    // 0x8006CF54: nop

L_8006CF58:
    // 0x8006CF58: jal         0x8004AD7C
    // 0x8006CF5C: nop

    OptionsDataMenu_Process(rdram, ctx);
        goto after_1;
    // 0x8006CF5C: nop

    after_1:
    // 0x8006CF60: b           L_8006D07C
    // 0x8006CF64: nop

        goto L_8006D07C;
    // 0x8006CF64: nop

L_8006CF68:
    // 0x8006CF68: jal         0x80080B50
    // 0x8006CF6C: nop

    Gfx_DrawScreenFadeOverlay(rdram, ctx);
        goto after_2;
    // 0x8006CF6C: nop

    after_2:
    // 0x8006CF70: b           L_8006D07C
    // 0x8006CF74: nop

        goto L_8006D07C;
    // 0x8006CF74: nop

L_8006CF78:
    // 0x8006CF78: jal         0x80083160
    // 0x8006CF7C: nop

    func_80083160(rdram, ctx);
        goto after_3;
    // 0x8006CF7C: nop

    after_3:
    // 0x8006CF80: b           L_8006D07C
    // 0x8006CF84: nop

        goto L_8006D07C;
    // 0x8006CF84: nop

L_8006CF88:
    // 0x8006CF88: jal         0x8007F344
    // 0x8006CF8C: nop

    func_8007F344(rdram, ctx);
        goto after_4;
    // 0x8006CF8C: nop

    after_4:
    // 0x8006CF90: b           L_8006D07C
    // 0x8006CF94: nop

        goto L_8006D07C;
    // 0x8006CF94: nop

L_8006CF98:
    // 0x8006CF98: jal         0x80090E08
    // 0x8006CF9C: nop

    MenuHub_StartPlaying(rdram, ctx);
        goto after_5;
    // 0x8006CF9C: nop

    after_5:
    // 0x8006CFA0: b           L_8006D07C
    // 0x8006CFA4: nop

        goto L_8006D07C;
    // 0x8006CFA4: nop

L_8006CFA8:
    // 0x8006CFA8: jal         0x800444A4
    // 0x8006CFAC: nop

    wonders1_Update(rdram, ctx);
        goto after_6;
    // 0x8006CFAC: nop

    after_6:
    // 0x8006CFB0: jal         0x80045968
    // 0x8006CFB4: nop

    wonders1_Draw(rdram, ctx);
        goto after_7;
    // 0x8006CFB4: nop

    after_7:
    // 0x8006CFB8: b           L_8006D07C
    // 0x8006CFBC: nop

        goto L_8006D07C;
    // 0x8006CFBC: nop

L_8006CFC0:
    // 0x8006CFC0: jal         0x80046A34
    // 0x8006CFC4: nop

    wonders3_Update(rdram, ctx);
        goto after_8;
    // 0x8006CFC4: nop

    after_8:
    // 0x8006CFC8: jal         0x800471F8
    // 0x8006CFCC: nop

    wonders3_Draw(rdram, ctx);
        goto after_9;
    // 0x8006CFCC: nop

    after_9:
    // 0x8006CFD0: b           L_8006D07C
    // 0x8006CFD4: nop

        goto L_8006D07C;
    // 0x8006CFD4: nop

L_8006CFD8:
    // 0x8006CFD8: jal         0x8006CC80
    // 0x8006CFDC: nop

    GameMode_PausedTick(rdram, ctx);
        goto after_10;
    // 0x8006CFDC: nop

    after_10:
    // 0x8006CFE0: b           L_8006D07C
    // 0x8006CFE4: nop

        goto L_8006D07C;
    // 0x8006CFE4: nop

L_8006CFE8:
    // 0x8006CFE8: jal         0x8006CD98
    // 0x8006CFEC: nop

    GameMode_PlayingTick(rdram, ctx);
        goto after_11;
    // 0x8006CFEC: nop

    after_11:
    // 0x8006CFF0: b           L_8006D07C
    // 0x8006CFF4: nop

        goto L_8006D07C;
    // 0x8006CFF4: nop

L_8006CFF8:
    // 0x8006CFF8: jal         0x8006CE30
    // 0x8006CFFC: nop

    GameMode_AttractCountdownTick(rdram, ctx);
        goto after_12;
    // 0x8006CFFC: nop

    after_12:
    // 0x8006D000: b           L_8006D07C
    // 0x8006D004: nop

        goto L_8006D07C;
    // 0x8006D004: nop

L_8006D008:
    // 0x8006D008: jal         0x80083470
    // 0x8006D00C: nop

    Credits_Update(rdram, ctx);
        goto after_13;
    // 0x8006D00C: nop

    after_13:
    // 0x8006D010: b           L_8006D07C
    // 0x8006D014: nop

        goto L_8006D07C;
    // 0x8006D014: nop

L_8006D018:
    // 0x8006D018: jal         0x8006CEDC
    // 0x8006D01C: nop

    GameMode_AdvanceGdl(rdram, ctx);
        goto after_14;
    // 0x8006D01C: nop

    after_14:
    // 0x8006D020: b           L_8006D07C
    // 0x8006D024: nop

        goto L_8006D07C;
    // 0x8006D024: nop

L_8006D028:
    // 0x8006D028: jal         0x80055744
    // 0x8006D02C: nop

    game_over_display_stuff_huge_function_q(rdram, ctx);
        goto after_15;
    // 0x8006D02C: nop

    after_15:
    // 0x8006D030: b           L_8006D07C
    // 0x8006D034: nop

        goto L_8006D07C;
    // 0x8006D034: nop

L_8006D038:
    // 0x8006D038: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006D03C: lw          $t7, 0x554($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X554);
    // 0x8006D040: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D044: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8006D048: bne         $t8, $zero, L_8006D07C
    if (ctx->r24 != 0) {
        // 0x8006D04C: sw          $t8, 0x554($at)
        MEM_W(0X554, ctx->r1) = ctx->r24;
            goto L_8006D07C;
    }
    // 0x8006D04C: sw          $t8, 0x554($at)
    MEM_W(0X554, ctx->r1) = ctx->r24;
    // 0x8006D050: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8006D054: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D058: sw          $t9, 0x554($at)
    MEM_W(0X554, ctx->r1) = ctx->r25;
    // 0x8006D05C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D060: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8006D064: sb          $t0, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r8;
    // 0x8006D068: jal         0x800905E8
    // 0x8006D06C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800905E8(rdram, ctx);
        goto after_16;
    // 0x8006D06C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x8006D070: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006D074: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006D078: sb          $t1, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r9;
L_8006D07C:
    // 0x8006D07C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D080: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006D084: jr          $ra
    // 0x8006D088: nop

    return;
    // 0x8006D088: nop

    // 0x8006D08C: nop

;}

RECOMP_FUNC void FUN_033310_setPieceDef(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D090: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8006D094: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8006D098: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006D09C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006D0A0: lw          $t7, 0x110($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X110);
    // 0x8006D0A4: jr          $ra
    // 0x8006D0A8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x8006D0A8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void FUN_033310_getPhysicalCurPieceSpawnPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D0AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006D0B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006D0B4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8006D0B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D0BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006D0C0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8006D0C4: jal         0x80054ED0
    // 0x8006D0C8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    getCurPieceSpawnOffsetAsPoint(rdram, ctx);
        goto after_0;
    // 0x8006D0C8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8006D0CC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8006D0D0: lh          $t7, 0x1C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1C);
    // 0x8006D0D4: lbu         $t9, 0x4($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4);
    // 0x8006D0D8: lh          $t3, 0x1E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X1E);
    // 0x8006D0DC: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8006D0E0: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8006D0E4: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x8006D0E8: addiu       $t4, $t3, -0x100
    ctx->r12 = ADD32(ctx->r11, -0X100);
    // 0x8006D0EC: sh          $t2, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r10;
    // 0x8006D0F0: sh          $t4, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r12;
    // 0x8006D0F4: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x8006D0F8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8006D0FC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8006D100: nop

    // 0x8006D104: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x8006D108: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x8006D10C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D110: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8006D114: jr          $ra
    // 0x8006D118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006D118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void FUN_033310_getPhysicalStartingRotOrigin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D11C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006D120: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006D124: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8006D128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D12C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006D130: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8006D134: jal         0x80054F08
    // 0x8006D138: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    getStartingRotOriginAsPoint(rdram, ctx);
        goto after_0;
    // 0x8006D138: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8006D13C: lh          $t7, 0x1C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1C);
    // 0x8006D140: lh          $t9, 0x1E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X1E);
    // 0x8006D144: addiu       $t8, $t7, 0x80
    ctx->r24 = ADD32(ctx->r15, 0X80);
    // 0x8006D148: addiu       $t0, $t9, 0x80
    ctx->r8 = ADD32(ctx->r25, 0X80);
    // 0x8006D14C: sh          $t8, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r24;
    // 0x8006D150: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    // 0x8006D154: addiu       $t2, $sp, 0x1C
    ctx->r10 = ADD32(ctx->r29, 0X1C);
    // 0x8006D158: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8006D15C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8006D160: nop

    // 0x8006D164: swl         $at, 0x0($t1)
    do_swl(rdram, 0X0, ctx->r9, ctx->r1);
    // 0x8006D168: swr         $at, 0x3($t1)
    do_swr(rdram, 0X3, ctx->r9, ctx->r1);
    // 0x8006D16C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D170: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8006D174: jr          $ra
    // 0x8006D178: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006D178: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void FUN_033310_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D17C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8006D180: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8006D184: sb          $a1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r5;
    // 0x8006D188: sb          $a2, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r6;
    // 0x8006D18C: jr          $ra
    // 0x8006D190: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x8006D190: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}

RECOMP_FUNC void FUN_033310_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D194: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x8006D198: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    // 0x8006D19C: jr          $ra
    // 0x8006D1A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x8006D1A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8006D1A4: nop

    // 0x8006D1A8: nop

    // 0x8006D1AC: nop

;}

RECOMP_FUNC void debug_print_reason_routine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083560: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80083564: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80083568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008356C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80083570: jal         0x800B837C
    // 0x80083574: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    strlen_recomp(rdram, ctx);
        goto after_0;
    // 0x80083574: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80083578: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x8008357C: bne         $at, $zero, L_80083590
    if (ctx->r1 != 0) {
        // 0x80083580: nop
    
            goto L_80083590;
    }
    // 0x80083580: nop

    // 0x80083584: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80083588: nop

    // 0x8008358C: sb          $zero, 0x28($t6)
    MEM_B(0X28, ctx->r14) = 0;
L_80083590:
    // 0x80083590: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80083594: jal         0x800B837C
    // 0x80083598: nop

    strlen_recomp(rdram, ctx);
        goto after_1;
    // 0x80083598: nop

    after_1:
    // 0x8008359C: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x800835A0: bne         $at, $zero, L_800835B4
    if (ctx->r1 != 0) {
        // 0x800835A4: nop
    
            goto L_800835B4;
    }
    // 0x800835A4: nop

    // 0x800835A8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800835AC: nop

    // 0x800835B0: sb          $zero, 0x28($t7)
    MEM_B(0X28, ctx->r15) = 0;
L_800835B4:
    // 0x800835B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800835B8: jal         0x800B837C
    // 0x800835BC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    strlen_recomp(rdram, ctx);
        goto after_2;
    // 0x800835BC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_2:
    // 0x800835C0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800835C4: nop

    // 0x800835C8: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800835CC: beq         $at, $zero, L_80083630
    if (ctx->r1 == 0) {
        // 0x800835D0: nop
    
            goto L_80083630;
    }
    // 0x800835D0: nop

L_800835D4:
    // 0x800835D4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800835D8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800835DC: nop

    // 0x800835E0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800835E4: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800835E8: nop

    // 0x800835EC: slti        $at, $t2, 0x41
    ctx->r1 = SIGNED(ctx->r10) < 0X41 ? 1 : 0;
    // 0x800835F0: bne         $at, $zero, L_80083608
    if (ctx->r1 != 0) {
        // 0x800835F4: slti        $at, $t2, 0x60
        ctx->r1 = SIGNED(ctx->r10) < 0X60 ? 1 : 0;
            goto L_80083608;
    }
    // 0x800835F4: slti        $at, $t2, 0x60
    ctx->r1 = SIGNED(ctx->r10) < 0X60 ? 1 : 0;
    // 0x800835F8: beq         $at, $zero, L_80083608
    if (ctx->r1 == 0) {
        // 0x800835FC: nop
    
            goto L_80083608;
    }
    // 0x800835FC: nop

    // 0x80083600: addiu       $t3, $t2, 0x20
    ctx->r11 = ADD32(ctx->r10, 0X20);
    // 0x80083604: sb          $t3, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r11;
L_80083608:
    // 0x80083608: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8008360C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80083610: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80083614: jal         0x800B837C
    // 0x80083618: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    strlen_recomp(rdram, ctx);
        goto after_3;
    // 0x80083618: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_3:
    // 0x8008361C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80083620: nop

    // 0x80083624: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80083628: bne         $at, $zero, L_800835D4
    if (ctx->r1 != 0) {
        // 0x8008362C: nop
    
            goto L_800835D4;
    }
    // 0x8008362C: nop

L_80083630:
    // 0x80083630: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80083634: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083638: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008363C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80083640: addiu       $a1, $a1, -0x124C
    ctx->r5 = ADD32(ctx->r5, -0X124C);
    // 0x80083644: jal         0x800B62D4
    // 0x80083648: addiu       $a0, $a0, 0x9C8
    ctx->r4 = ADD32(ctx->r4, 0X9C8);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x80083648: addiu       $a0, $a0, 0x9C8
    ctx->r4 = ADD32(ctx->r4, 0X9C8);
    after_4:
    // 0x8008364C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80083650: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083654: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083658: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8008365C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80083660: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80083664: sw          $t7, 0x38F0($at)
    MEM_W(0X38F0, ctx->r1) = ctx->r15;
    // 0x80083668: addiu       $a3, $a3, 0x9C8
    ctx->r7 = ADD32(ctx->r7, 0X9C8);
    // 0x8008366C: jal         0x800B3BFC
    // 0x80083670: addiu       $a0, $a0, -0x1244
    ctx->r4 = ADD32(ctx->r4, -0X1244);
    rmonPrintf_recomp(rdram, ctx);
        goto after_5;
    // 0x80083670: addiu       $a0, $a0, -0x1244
    ctx->r4 = ADD32(ctx->r4, -0X1244);
    after_5:
    // 0x80083674: jal         0x800B6650
    // 0x80083678: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_6;
    // 0x80083678: nop

    after_6:
    // 0x8008367C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80083680: lw          $t8, 0x38F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X38F4);
    // 0x80083684: nop

    // 0x80083688: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8008368C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083690: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80083694: jr          $ra
    // 0x80083698: nop

    return;
    // 0x80083698: nop

;}

RECOMP_FUNC void Debug_DrawChar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008369C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800836A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800836A4: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x800836A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800836AC: slti        $at, $t6, 0x61
    ctx->r1 = SIGNED(ctx->r14) < 0X61 ? 1 : 0;
    // 0x800836B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800836B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800836B8: bne         $at, $zero, L_800836C8
    if (ctx->r1 != 0) {
        // 0x800836BC: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_800836C8;
    }
    // 0x800836BC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800836C0: addiu       $t7, $t6, -0x20
    ctx->r15 = ADD32(ctx->r14, -0X20);
    // 0x800836C4: sb          $t7, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r15;
L_800836C8:
    // 0x800836C8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800836CC: lbu         $t8, 0x2B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2B);
    // 0x800836D0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800836D4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800836D8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800836DC: addiu       $t9, $t8, -0x20
    ctx->r25 = ADD32(ctx->r24, -0X20);
    // 0x800836E0: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800836E4: sll         $t3, $t3, 6
    ctx->r11 = S32(ctx->r11 << 6);
    // 0x800836E8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800836EC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800836F0: sb          $t9, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r25;
    // 0x800836F4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800836F8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800836FC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_80083700:
    // 0x80083700: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80083704:
    // 0x80083704: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80083708: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008370C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80083710: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80083714: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80083718: lbu         $t7, 0x3718($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X3718);
    // 0x8008371C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80083720: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x80083724: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x80083728: and         $t3, $t7, $t2
    ctx->r11 = ctx->r15 & ctx->r10;
    // 0x8008372C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x80083730: beq         $t4, $zero, L_80083780
    if (ctx->r12 == 0) {
        // 0x80083734: nop
    
            goto L_80083780;
    }
    // 0x80083734: nop

    // 0x80083738: lbu         $t1, 0x3F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3F);
    // 0x8008373C: lbu         $t5, 0x3B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X3B);
    // 0x80083740: sll         $t0, $t1, 3
    ctx->r8 = S32(ctx->r9 << 3);
    // 0x80083744: andi        $t7, $t0, 0x7C0
    ctx->r15 = ctx->r8 & 0X7C0;
    // 0x80083748: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x8008374C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80083750: lbu         $t3, 0x43($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X43);
    // 0x80083754: andi        $t9, $t6, 0xF800
    ctx->r25 = ctx->r14 & 0XF800;
    // 0x80083758: or          $t2, $t9, $t7
    ctx->r10 = ctx->r25 | ctx->r15;
    // 0x8008375C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80083760: addu        $t0, $t1, $t8
    ctx->r8 = ADD32(ctx->r9, ctx->r24);
    // 0x80083764: sra         $t4, $t3, 2
    ctx->r12 = S32(SIGNED(ctx->r11) >> 2);
    // 0x80083768: andi        $t5, $t4, 0x3E
    ctx->r13 = ctx->r12 & 0X3E;
    // 0x8008376C: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x80083770: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x80083774: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x80083778: b           L_800837A0
    // 0x8008377C: sh          $t6, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r14;
        goto L_800837A0;
    // 0x8008377C: sh          $t6, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r14;
L_80083780:
    // 0x80083780: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80083784: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80083788: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8008378C: addu        $t1, $t2, $t5
    ctx->r9 = ADD32(ctx->r10, ctx->r13);
    // 0x80083790: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x80083794: ori         $t4, $zero, 0xFFFE
    ctx->r12 = 0 | 0XFFFE;
    // 0x80083798: addu        $t7, $t0, $t8
    ctx->r15 = ADD32(ctx->r8, ctx->r24);
    // 0x8008379C: sh          $t4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r12;
L_800837A0:
    // 0x800837A0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800837A4: nop

    // 0x800837A8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800837AC: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800837B0: bne         $at, $zero, L_80083704
    if (ctx->r1 != 0) {
        // 0x800837B4: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_80083704;
    }
    // 0x800837B4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800837B8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800837BC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800837C0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800837C4: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x800837C8: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x800837CC: addiu       $t2, $t3, 0x140
    ctx->r10 = ADD32(ctx->r11, 0X140);
    // 0x800837D0: addiu       $t1, $t5, 0x1
    ctx->r9 = ADD32(ctx->r13, 0X1);
    // 0x800837D4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800837D8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800837DC: bne         $at, $zero, L_80083700
    if (ctx->r1 != 0) {
        // 0x800837E0: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_80083700;
    }
    // 0x800837E0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800837E4: jal         0x800B6650
    // 0x800837E8: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x800837E8: nop

    after_0:
    // 0x800837EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800837F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800837F4: jr          $ra
    // 0x800837F8: nop

    return;
    // 0x800837F8: nop

;}

RECOMP_FUNC void Debug_DrawString(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80083800: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80083804: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80083808: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8008380C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80083810: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80083814: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80083818: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8008381C: sb          $zero, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = 0;
    // 0x80083820: sb          $zero, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = 0;
    // 0x80083824: jal         0x800B837C
    // 0x80083828: sb          $t6, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r14;
    strlen_recomp(rdram, ctx);
        goto after_0;
    // 0x80083828: sb          $t6, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8008382C: lbu         $t7, 0x2E($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2E);
    // 0x80083830: nop

    // 0x80083834: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80083838: beq         $at, $zero, L_800838F4
    if (ctx->r1 == 0) {
        // 0x8008383C: nop
    
            goto L_800838F4;
    }
    // 0x8008383C: nop

L_80083840:
    // 0x80083840: lbu         $t8, 0x2E($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2E);
    // 0x80083844: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80083848: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008384C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80083850: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80083854: nop

    // 0x80083858: bne         $t1, $at, L_80083880
    if (ctx->r9 != ctx->r1) {
        // 0x8008385C: sb          $t1, 0x2F($sp)
        MEM_B(0X2F, ctx->r29) = ctx->r9;
            goto L_80083880;
    }
    // 0x8008385C: sb          $t1, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r9;
    // 0x80083860: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80083864: lbu         $t5, 0x2C($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2C);
    // 0x80083868: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008386C: addiu       $t4, $t3, 0x9
    ctx->r12 = ADD32(ctx->r11, 0X9);
    // 0x80083870: sb          $t2, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r10;
    // 0x80083874: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80083878: b           L_800838C0
    // 0x8008387C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
        goto L_800838C0;
    // 0x8008387C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_80083880:
    // 0x80083880: lbu         $t7, 0x2D($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2D);
    // 0x80083884: lbu         $t6, 0x2C($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2C);
    // 0x80083888: lbu         $t0, 0x43($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X43);
    // 0x8008388C: lbu         $t1, 0x47($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X47);
    // 0x80083890: lbu         $t2, 0x4B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4B);
    // 0x80083894: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80083898: lbu         $a0, 0x2F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2F);
    // 0x8008389C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800838A0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800838A4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800838A8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x800838AC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800838B0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800838B4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800838B8: jal         0x8008369C
    // 0x800838BC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    Debug_DrawChar(rdram, ctx);
        goto after_1;
    // 0x800838BC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_1:
L_800838C0:
    // 0x800838C0: lbu         $t3, 0x2E($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X2E);
    // 0x800838C4: lbu         $t5, 0x2D($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2D);
    // 0x800838C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800838CC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800838D0: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x800838D4: sb          $t7, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r15;
    // 0x800838D8: jal         0x800B837C
    // 0x800838DC: sb          $t4, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r12;
    strlen_recomp(rdram, ctx);
        goto after_2;
    // 0x800838DC: sb          $t4, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r12;
    after_2:
    // 0x800838E0: lbu         $t6, 0x2E($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2E);
    // 0x800838E4: nop

    // 0x800838E8: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800838EC: bne         $at, $zero, L_80083840
    if (ctx->r1 != 0) {
        // 0x800838F0: nop
    
            goto L_80083840;
    }
    // 0x800838F0: nop

L_800838F4:
    // 0x800838F4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800838F8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800838FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80083900: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80083904: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80083908: jr          $ra
    // 0x8008390C: or          $v0, $t9, $t0
    ctx->r2 = ctx->r25 | ctx->r8;
    return;
    // 0x8008390C: or          $v0, $t9, $t0
    ctx->r2 = ctx->r25 | ctx->r8;
;}

RECOMP_FUNC void Debug_DrawFaultScreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083910: addiu       $sp, $sp, -0x890
    ctx->r29 = ADD32(ctx->r29, -0X890);
    // 0x80083914: sw          $a0, 0x890($sp)
    MEM_W(0X890, ctx->r29) = ctx->r4;
    // 0x80083918: lw          $t6, 0x890($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X890);
    // 0x8008391C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80083920: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x80083924: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80083928: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8008392C: addiu       $a0, $sp, 0x868
    ctx->r4 = ADD32(ctx->r29, 0X868);
    // 0x80083930: addiu       $a1, $sp, 0x880
    ctx->r5 = ADD32(ctx->r29, 0X880);
    // 0x80083934: jal         0x800B3080
    // 0x80083938: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80083938: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8008393C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80083940: addiu       $a1, $sp, 0x868
    ctx->r5 = ADD32(ctx->r29, 0X868);
    // 0x80083944: jal         0x800B30B0
    // 0x80083948: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80083948: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8008394C: jal         0x8007E5D4
    // 0x80083950: nop

    n64HeapStats(rdram, ctx);
        goto after_2;
    // 0x80083950: nop

    after_2:
    // 0x80083954: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083958: jal         0x800B3BFC
    // 0x8008395C: addiu       $a0, $a0, -0x121C
    ctx->r4 = ADD32(ctx->r4, -0X121C);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8008395C: addiu       $a0, $a0, -0x121C
    ctx->r4 = ADD32(ctx->r4, -0X121C);
    after_3:
    // 0x80083960: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80083964: lw          $a1, 0xA20($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XA20);
    // 0x80083968: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008396C: addiu       $a0, $a0, 0x9B0
    ctx->r4 = ADD32(ctx->r4, 0X9B0);
    // 0x80083970: jal         0x800B3080
    // 0x80083974: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x80083974: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x80083978: jal         0x800B78B0
    // 0x8008397C: nop

    osSpTaskYield_recomp(rdram, ctx);
        goto after_5;
    // 0x8008397C: nop

    after_5:
    // 0x80083980: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80083984: addiu       $a0, $a0, -0x4460
    ctx->r4 = ADD32(ctx->r4, -0X4460);
    // 0x80083988: jal         0x800B83F0
    // 0x8008398C: addiu       $a0, $a0, 0xB0
    ctx->r4 = ADD32(ctx->r4, 0XB0);
    osStopThread_recomp(rdram, ctx);
        goto after_6;
    // 0x8008398C: addiu       $a0, $a0, 0xB0
    ctx->r4 = ADD32(ctx->r4, 0XB0);
    after_6:
    // 0x80083990: jal         0x800B7060
    // 0x80083994: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_7;
    // 0x80083994: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_7:
    // 0x80083998: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8008399C: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800839A0: nop

    // 0x800839A4: bne         $t8, $zero, L_800839BC
    if (ctx->r24 != 0) {
        // 0x800839A8: nop
    
            goto L_800839BC;
    }
    // 0x800839A8: nop

    // 0x800839AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800839B0: addiu       $a0, $a0, -0x6A90
    ctx->r4 = ADD32(ctx->r4, -0X6A90);
    // 0x800839B4: jal         0x800B6A20
    // 0x800839B8: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    osViSetMode_recomp(rdram, ctx);
        goto after_8;
    // 0x800839B8: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_8:
L_800839BC:
    // 0x800839BC: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800839C0: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x800839C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800839C8: bne         $t9, $at, L_800839DC
    if (ctx->r25 != ctx->r1) {
        // 0x800839CC: nop
    
            goto L_800839DC;
    }
    // 0x800839CC: nop

    // 0x800839D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800839D4: jal         0x800B6A20
    // 0x800839D8: addiu       $a0, $a0, -0x6A90
    ctx->r4 = ADD32(ctx->r4, -0X6A90);
    osViSetMode_recomp(rdram, ctx);
        goto after_9;
    // 0x800839D8: addiu       $a0, $a0, -0x6A90
    ctx->r4 = ADD32(ctx->r4, -0X6A90);
    after_9:
L_800839DC:
    // 0x800839DC: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800839E0: lw          $t0, 0x300($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X300);
    // 0x800839E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800839E8: bne         $t0, $at, L_80083A00
    if (ctx->r8 != ctx->r1) {
        // 0x800839EC: nop
    
            goto L_80083A00;
    }
    // 0x800839EC: nop

    // 0x800839F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800839F4: addiu       $a0, $a0, -0x6A90
    ctx->r4 = ADD32(ctx->r4, -0X6A90);
    // 0x800839F8: jal         0x800B6A20
    // 0x800839FC: addiu       $a0, $a0, 0x8C0
    ctx->r4 = ADD32(ctx->r4, 0X8C0);
    osViSetMode_recomp(rdram, ctx);
        goto after_10;
    // 0x800839FC: addiu       $a0, $a0, 0x8C0
    ctx->r4 = ADD32(ctx->r4, 0X8C0);
    after_10:
L_80083A00:
    // 0x80083A00: jal         0x800B6330
    // 0x80083A04: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_11;
    // 0x80083A04: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_11:
    // 0x80083A08: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80083A0C: lw          $a0, 0x9A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X9A0);
    // 0x80083A10: jal         0x800B64F0
    // 0x80083A14: nop

    osViSwapBuffer_recomp(rdram, ctx);
        goto after_12;
    // 0x80083A14: nop

    after_12:
    // 0x80083A18: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80083A1C: addiu       $a0, $a0, 0x9B0
    ctx->r4 = ADD32(ctx->r4, 0X9B0);
    // 0x80083A20: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    // 0x80083A24: jal         0x800B65E0
    // 0x80083A28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osViSetEvent_recomp(rdram, ctx);
        goto after_13;
    // 0x80083A28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80083A2C: jal         0x800B6650
    // 0x80083A30: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_14;
    // 0x80083A30: nop

    after_14:
    // 0x80083A34: lw          $t1, 0x890($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X890);
    // 0x80083A38: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083A3C: lw          $a1, 0x14($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X14);
    // 0x80083A40: jal         0x800B3BFC
    // 0x80083A44: addiu       $a0, $a0, -0x1200
    ctx->r4 = ADD32(ctx->r4, -0X1200);
    rmonPrintf_recomp(rdram, ctx);
        goto after_15;
    // 0x80083A44: addiu       $a0, $a0, -0x1200
    ctx->r4 = ADD32(ctx->r4, -0X1200);
    after_15:
    // 0x80083A48: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80083A4C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083A50: lw          $a1, 0xFC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XFC);
    // 0x80083A54: jal         0x800B3BFC
    // 0x80083A58: addiu       $a0, $a0, -0x11E8
    ctx->r4 = ADD32(ctx->r4, -0X11E8);
    rmonPrintf_recomp(rdram, ctx);
        goto after_16;
    // 0x80083A58: addiu       $a0, $a0, -0x11E8
    ctx->r4 = ADD32(ctx->r4, -0X11E8);
    after_16:
    // 0x80083A5C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80083A60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083A64: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80083A68: lw          $a0, 0x100($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X100);
    // 0x80083A6C: addiu       $a2, $a2, 0x3340
    ctx->r6 = ADD32(ctx->r6, 0X3340);
    // 0x80083A70: jal         0x80084490
    // 0x80083A74: addiu       $a1, $a1, -0x11D8
    ctx->r5 = ADD32(ctx->r5, -0X11D8);
    Debug_PrintList(rdram, ctx);
        goto after_17;
    // 0x80083A74: addiu       $a1, $a1, -0x11D8
    ctx->r5 = ADD32(ctx->r5, -0X11D8);
    after_17:
    // 0x80083A78: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80083A7C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083A80: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80083A84: lw          $a0, 0xF8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XF8);
    // 0x80083A88: addiu       $a2, $a2, 0x3490
    ctx->r6 = ADD32(ctx->r6, 0X3490);
    // 0x80083A8C: jal         0x80084490
    // 0x80083A90: addiu       $a1, $a1, -0x11D0
    ctx->r5 = ADD32(ctx->r5, -0X11D0);
    Debug_PrintList(rdram, ctx);
        goto after_18;
    // 0x80083A90: addiu       $a1, $a1, -0x11D0
    ctx->r5 = ADD32(ctx->r5, -0X11D0);
    after_18:
    // 0x80083A94: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80083A98: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083A9C: lw          $a1, 0x104($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X104);
    // 0x80083AA0: jal         0x800B3BFC
    // 0x80083AA4: addiu       $a0, $a0, -0x11CC
    ctx->r4 = ADD32(ctx->r4, -0X11CC);
    rmonPrintf_recomp(rdram, ctx);
        goto after_19;
    // 0x80083AA4: addiu       $a0, $a0, -0x11CC
    ctx->r4 = ADD32(ctx->r4, -0X11CC);
    after_19:
    // 0x80083AA8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80083AAC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083AB0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80083AB4: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x80083AB8: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80083ABC: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x80083AC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80083AC4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80083AC8: lw          $t1, 0x14($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X14);
    // 0x80083ACC: lw          $t0, 0x10($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X10);
    // 0x80083AD0: addiu       $a0, $a0, -0x11B8
    ctx->r4 = ADD32(ctx->r4, -0X11B8);
    // 0x80083AD4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80083AD8: jal         0x800B3BFC
    // 0x80083ADC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    rmonPrintf_recomp(rdram, ctx);
        goto after_20;
    // 0x80083ADC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_20:
    // 0x80083AE0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80083AE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083AE8: lw          $t2, 0x20($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X20);
    // 0x80083AEC: lw          $t3, 0x24($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X24);
    // 0x80083AF0: lw          $a2, 0x18($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X18);
    // 0x80083AF4: lw          $a3, 0x1C($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X1C);
    // 0x80083AF8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80083AFC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80083B00: lw          $t5, 0x2C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X2C);
    // 0x80083B04: lw          $t4, 0x28($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X28);
    // 0x80083B08: addiu       $a0, $a0, -0x1190
    ctx->r4 = ADD32(ctx->r4, -0X1190);
    // 0x80083B0C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80083B10: jal         0x800B3BFC
    // 0x80083B14: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    rmonPrintf_recomp(rdram, ctx);
        goto after_21;
    // 0x80083B14: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_21:
    // 0x80083B18: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80083B1C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083B20: lw          $t6, 0x38($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X38);
    // 0x80083B24: lw          $t7, 0x3C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X3C);
    // 0x80083B28: lw          $a2, 0x30($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X30);
    // 0x80083B2C: lw          $a3, 0x34($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X34);
    // 0x80083B30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80083B34: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80083B38: lw          $t1, 0x44($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X44);
    // 0x80083B3C: lw          $t0, 0x40($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X40);
    // 0x80083B40: addiu       $a0, $a0, -0x1168
    ctx->r4 = ADD32(ctx->r4, -0X1168);
    // 0x80083B44: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80083B48: jal         0x800B3BFC
    // 0x80083B4C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    rmonPrintf_recomp(rdram, ctx);
        goto after_22;
    // 0x80083B4C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_22:
    // 0x80083B50: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80083B54: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083B58: lw          $t2, 0x50($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X50);
    // 0x80083B5C: lw          $t3, 0x54($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X54);
    // 0x80083B60: lw          $a2, 0x48($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X48);
    // 0x80083B64: lw          $a3, 0x4C($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4C);
    // 0x80083B68: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80083B6C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80083B70: lw          $t5, 0x5C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X5C);
    // 0x80083B74: lw          $t4, 0x58($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X58);
    // 0x80083B78: addiu       $a0, $a0, -0x1140
    ctx->r4 = ADD32(ctx->r4, -0X1140);
    // 0x80083B7C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80083B80: jal         0x800B3BFC
    // 0x80083B84: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    rmonPrintf_recomp(rdram, ctx);
        goto after_23;
    // 0x80083B84: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_23:
    // 0x80083B88: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80083B8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083B90: lw          $t8, 0x68($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X68);
    // 0x80083B94: lw          $t9, 0x6C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X6C);
    // 0x80083B98: lw          $a2, 0x60($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X60);
    // 0x80083B9C: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x80083BA0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80083BA4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80083BA8: lw          $t1, 0x74($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X74);
    // 0x80083BAC: lw          $t0, 0x70($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X70);
    // 0x80083BB0: addiu       $a0, $a0, -0x1118
    ctx->r4 = ADD32(ctx->r4, -0X1118);
    // 0x80083BB4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80083BB8: jal         0x800B3BFC
    // 0x80083BBC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    rmonPrintf_recomp(rdram, ctx);
        goto after_24;
    // 0x80083BBC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_24:
    // 0x80083BC0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80083BC4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083BC8: lw          $t2, 0x80($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X80);
    // 0x80083BCC: lw          $t3, 0x84($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X84);
    // 0x80083BD0: lw          $a2, 0x78($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X78);
    // 0x80083BD4: lw          $a3, 0x7C($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X7C);
    // 0x80083BD8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80083BDC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80083BE0: lw          $t5, 0x8C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X8C);
    // 0x80083BE4: lw          $t4, 0x88($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X88);
    // 0x80083BE8: addiu       $a0, $a0, -0x10F0
    ctx->r4 = ADD32(ctx->r4, -0X10F0);
    // 0x80083BEC: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80083BF0: jal         0x800B3BFC
    // 0x80083BF4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    rmonPrintf_recomp(rdram, ctx);
        goto after_25;
    // 0x80083BF4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_25:
    // 0x80083BF8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80083BFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083C00: lw          $t6, 0x98($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X98);
    // 0x80083C04: lw          $t7, 0x9C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X9C);
    // 0x80083C08: lw          $a2, 0x90($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X90);
    // 0x80083C0C: lw          $a3, 0x94($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X94);
    // 0x80083C10: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80083C14: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80083C18: lw          $t1, 0xA4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0XA4);
    // 0x80083C1C: lw          $t0, 0xA0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XA0);
    // 0x80083C20: addiu       $a0, $a0, -0x10C8
    ctx->r4 = ADD32(ctx->r4, -0X10C8);
    // 0x80083C24: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80083C28: jal         0x800B3BFC
    // 0x80083C2C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    rmonPrintf_recomp(rdram, ctx);
        goto after_26;
    // 0x80083C2C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_26:
    // 0x80083C30: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80083C34: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083C38: lw          $t2, 0xB0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XB0);
    // 0x80083C3C: lw          $t3, 0xB4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0XB4);
    // 0x80083C40: lw          $a2, 0xA8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0XA8);
    // 0x80083C44: lw          $a3, 0xAC($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XAC);
    // 0x80083C48: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80083C4C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80083C50: lw          $t5, 0xBC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XBC);
    // 0x80083C54: lw          $t4, 0xB8($t9)
    ctx->r12 = MEM_W(ctx->r25, 0XB8);
    // 0x80083C58: addiu       $a0, $a0, -0x10A0
    ctx->r4 = ADD32(ctx->r4, -0X10A0);
    // 0x80083C5C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80083C60: jal         0x800B3BFC
    // 0x80083C64: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    rmonPrintf_recomp(rdram, ctx);
        goto after_27;
    // 0x80083C64: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_27:
    // 0x80083C68: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80083C6C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083C70: lw          $t8, 0xC8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC8);
    // 0x80083C74: lw          $t9, 0xCC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XCC);
    // 0x80083C78: lw          $a2, 0xC0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XC0);
    // 0x80083C7C: lw          $a3, 0xC4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XC4);
    // 0x80083C80: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80083C84: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80083C88: lw          $t1, 0xD4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0XD4);
    // 0x80083C8C: lw          $t0, 0xD0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0XD0);
    // 0x80083C90: addiu       $a0, $a0, -0x1078
    ctx->r4 = ADD32(ctx->r4, -0X1078);
    // 0x80083C94: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80083C98: jal         0x800B3BFC
    // 0x80083C9C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    rmonPrintf_recomp(rdram, ctx);
        goto after_28;
    // 0x80083C9C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_28:
    // 0x80083CA0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80083CA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083CA8: lw          $t2, 0xE0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0XE0);
    // 0x80083CAC: lw          $t3, 0xE4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0XE4);
    // 0x80083CB0: lw          $a2, 0xD8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XD8);
    // 0x80083CB4: lw          $a3, 0xDC($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XDC);
    // 0x80083CB8: addiu       $a0, $a0, -0x1050
    ctx->r4 = ADD32(ctx->r4, -0X1050);
    // 0x80083CBC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80083CC0: jal         0x800B3BFC
    // 0x80083CC4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    rmonPrintf_recomp(rdram, ctx);
        goto after_29;
    // 0x80083CC4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_29:
    // 0x80083CC8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80083CCC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083CD0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80083CD4: lw          $a0, 0x10C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X10C);
    // 0x80083CD8: addiu       $a2, $a2, 0x3604
    ctx->r6 = ADD32(ctx->r6, 0X3604);
    // 0x80083CDC: jal         0x80084490
    // 0x80083CE0: addiu       $a1, $a1, -0x1034
    ctx->r5 = ADD32(ctx->r5, -0X1034);
    Debug_PrintList(rdram, ctx);
        goto after_30;
    // 0x80083CE0: addiu       $a1, $a1, -0x1034
    ctx->r5 = ADD32(ctx->r5, -0X1034);
    after_30:
    // 0x80083CE4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80083CE8: lw          $t5, 0xA28($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XA28);
    // 0x80083CEC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80083CF0: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x80083CF4: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x80083CF8: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
    // 0x80083CFC: sw          $zero, 0x88C($sp)
    MEM_W(0X88C, ctx->r29) = 0;
    // 0x80083D00: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
L_80083D04:
    // 0x80083D04: lw          $t1, 0x88C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88C);
    // 0x80083D08: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80083D0C: lw          $t0, 0x9A0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X9A0);
    // 0x80083D10: sll         $t7, $t1, 1
    ctx->r15 = S32(ctx->r9 << 1);
    // 0x80083D14: ori         $t6, $zero, 0xFFFE
    ctx->r14 = 0 | 0XFFFE;
    // 0x80083D18: addu        $t2, $t0, $t7
    ctx->r10 = ADD32(ctx->r8, ctx->r15);
    // 0x80083D1C: sh          $t6, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r14;
    // 0x80083D20: lw          $t3, 0x88C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88C);
    // 0x80083D24: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80083D28: ori         $at, $at, 0x2C00
    ctx->r1 = ctx->r1 | 0X2C00;
    // 0x80083D2C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80083D30: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80083D34: bne         $at, $zero, L_80083D04
    if (ctx->r1 != 0) {
        // 0x80083D38: sw          $t4, 0x88C($sp)
        MEM_W(0X88C, ctx->r29) = ctx->r12;
            goto L_80083D04;
    }
    // 0x80083D38: sw          $t4, 0x88C($sp)
    MEM_W(0X88C, ctx->r29) = ctx->r12;
L_80083D3C:
    // 0x80083D3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083D40: lwc1        $f4, 0x38F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X38F8);
    // 0x80083D44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083D48: lwc1        $f6, 0x38FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X38FC);
    // 0x80083D4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083D50: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80083D54: swc1        $f8, 0x38F8($at)
    MEM_W(0X38F8, ctx->r1) = ctx->f8.u32l;
    // 0x80083D58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083D5C: lwc1        $f10, 0x3900($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3900);
    // 0x80083D60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083D64: lwc1        $f16, 0x3904($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3904);
    // 0x80083D68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083D6C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80083D70: swc1        $f18, 0x3900($at)
    MEM_W(0X3900, ctx->r1) = ctx->f18.u32l;
    // 0x80083D74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083D78: lwc1        $f4, 0x3908($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3908);
    // 0x80083D7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083D80: lwc1        $f10, 0x390C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X390C);
    // 0x80083D84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083D88: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80083D8C: swc1        $f16, 0x3908($at)
    MEM_W(0X3908, ctx->r1) = ctx->f16.u32l;
    // 0x80083D90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083D94: lwc1        $f5, -0xF38($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0XF38);
    // 0x80083D98: lwc1        $f4, -0xF34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XF34);
    // 0x80083D9C: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80083DA0: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x80083DA4: nop

    // 0x80083DA8: bc1f        L_80083DD0
    if (!c1cs) {
        // 0x80083DAC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80083DD0;
    }
    // 0x80083DAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083DB0: lwc1        $f10, -0xF30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XF30);
    // 0x80083DB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083DB8: swc1        $f10, 0x38F8($at)
    MEM_W(0X38F8, ctx->r1) = ctx->f10.u32l;
    // 0x80083DBC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80083DC0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80083DC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083DC8: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80083DCC: swc1        $f8, 0x38FC($at)
    MEM_W(0X38FC, ctx->r1) = ctx->f8.u32l;
L_80083DD0:
    // 0x80083DD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083DD4: lwc1        $f18, 0x38F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X38F8);
    // 0x80083DD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083DDC: lwc1        $f11, -0xF28($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XF28);
    // 0x80083DE0: lwc1        $f10, -0xF24($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XF24);
    // 0x80083DE4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80083DE8: c.le.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d <= ctx->f10.d;
    // 0x80083DEC: nop

    // 0x80083DF0: bc1f        L_80083E20
    if (!c1cs) {
        // 0x80083DF4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80083E20;
    }
    // 0x80083DF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083DF8: lwc1        $f6, -0xF20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF20);
    // 0x80083DFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083E00: swc1        $f6, 0x38F8($at)
    MEM_W(0X38F8, ctx->r1) = ctx->f6.u32l;
    // 0x80083E04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083E08: lwc1        $f16, 0x38FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X38FC);
    // 0x80083E0C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80083E10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80083E14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083E18: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80083E1C: swc1        $f18, 0x38FC($at)
    MEM_W(0X38FC, ctx->r1) = ctx->f18.u32l;
L_80083E20:
    // 0x80083E20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083E24: lwc1        $f4, 0x3900($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3900);
    // 0x80083E28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083E2C: lwc1        $f7, -0xF18($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0XF18);
    // 0x80083E30: lwc1        $f6, -0xF14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF14);
    // 0x80083E34: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80083E38: c.le.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d <= ctx->f10.d;
    // 0x80083E3C: nop

    // 0x80083E40: bc1f        L_80083E70
    if (!c1cs) {
        // 0x80083E44: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80083E70;
    }
    // 0x80083E44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083E48: lwc1        $f16, -0xF10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF10);
    // 0x80083E4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083E50: swc1        $f16, 0x3900($at)
    MEM_W(0X3900, ctx->r1) = ctx->f16.u32l;
    // 0x80083E54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083E58: lwc1        $f8, 0x3904($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3904);
    // 0x80083E5C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80083E60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80083E64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083E68: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80083E6C: swc1        $f4, 0x3904($at)
    MEM_W(0X3904, ctx->r1) = ctx->f4.u32l;
L_80083E70:
    // 0x80083E70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083E74: lwc1        $f10, 0x3900($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3900);
    // 0x80083E78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083E7C: lwc1        $f17, -0xF08($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XF08);
    // 0x80083E80: lwc1        $f16, -0xF04($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF04);
    // 0x80083E84: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80083E88: c.le.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d <= ctx->f16.d;
    // 0x80083E8C: nop

    // 0x80083E90: bc1f        L_80083EC0
    if (!c1cs) {
        // 0x80083E94: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80083EC0;
    }
    // 0x80083E94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083E98: lwc1        $f8, -0xF00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XF00);
    // 0x80083E9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083EA0: swc1        $f8, 0x3900($at)
    MEM_W(0X3900, ctx->r1) = ctx->f8.u32l;
    // 0x80083EA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083EA8: lwc1        $f18, 0x3904($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3904);
    // 0x80083EAC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80083EB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80083EB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083EB8: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80083EBC: swc1        $f10, 0x3904($at)
    MEM_W(0X3904, ctx->r1) = ctx->f10.u32l;
L_80083EC0:
    // 0x80083EC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083EC4: lwc1        $f6, 0x3908($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3908);
    // 0x80083EC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083ECC: lwc1        $f9, -0xEF8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0XEF8);
    // 0x80083ED0: lwc1        $f8, -0xEF4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XEF4);
    // 0x80083ED4: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80083ED8: c.le.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d <= ctx->f16.d;
    // 0x80083EDC: nop

    // 0x80083EE0: bc1f        L_80083F10
    if (!c1cs) {
        // 0x80083EE4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80083F10;
    }
    // 0x80083EE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083EE8: lwc1        $f18, -0xEF0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XEF0);
    // 0x80083EEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083EF0: swc1        $f18, 0x3908($at)
    MEM_W(0X3908, ctx->r1) = ctx->f18.u32l;
    // 0x80083EF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083EF8: lwc1        $f4, 0x390C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X390C);
    // 0x80083EFC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80083F00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80083F04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083F08: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80083F0C: swc1        $f6, 0x390C($at)
    MEM_W(0X390C, ctx->r1) = ctx->f6.u32l;
L_80083F10:
    // 0x80083F10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083F14: lwc1        $f16, 0x3908($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3908);
    // 0x80083F18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083F1C: lwc1        $f19, -0xEE8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XEE8);
    // 0x80083F20: lwc1        $f18, -0xEE4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x80083F24: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80083F28: c.le.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d <= ctx->f18.d;
    // 0x80083F2C: nop

    // 0x80083F30: bc1f        L_80083F60
    if (!c1cs) {
        // 0x80083F34: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80083F60;
    }
    // 0x80083F34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083F38: lwc1        $f4, -0xEE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XEE0);
    // 0x80083F3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083F40: swc1        $f4, 0x3908($at)
    MEM_W(0X3908, ctx->r1) = ctx->f4.u32l;
    // 0x80083F44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083F48: lwc1        $f10, 0x390C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X390C);
    // 0x80083F4C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80083F50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80083F54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083F58: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80083F5C: swc1        $f16, 0x390C($at)
    MEM_W(0X390C, ctx->r1) = ctx->f16.u32l;
L_80083F60:
    // 0x80083F60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083F64: addiu       $a1, $a1, -0x102C
    ctx->r5 = ADD32(ctx->r5, -0X102C);
    // 0x80083F68: jal         0x800B62D4
    // 0x80083F6C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    sprintf_recomp(rdram, ctx);
        goto after_31;
    // 0x80083F6C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_31:
    // 0x80083F70: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80083F74: lw          $a3, 0x9A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X9A0);
    // 0x80083F78: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80083F7C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80083F80: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80083F84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80083F88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80083F8C: jal         0x800837FC
    // 0x80083F90: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    Debug_DrawString(rdram, ctx);
        goto after_32;
    // 0x80083F90: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_32:
    // 0x80083F94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083F98: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083F9C: sw          $v0, 0xA28($at)
    MEM_W(0XA28, ctx->r1) = ctx->r2;
    // 0x80083FA0: addiu       $a1, $a1, -0x1008
    ctx->r5 = ADD32(ctx->r5, -0X1008);
    // 0x80083FA4: jal         0x800B62D4
    // 0x80083FA8: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    sprintf_recomp(rdram, ctx);
        goto after_33;
    // 0x80083FA8: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_33:
    // 0x80083FAC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80083FB0: lw          $a3, 0x9A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X9A0);
    // 0x80083FB4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80083FB8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80083FBC: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80083FC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80083FC4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80083FC8: jal         0x800837FC
    // 0x80083FCC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    Debug_DrawString(rdram, ctx);
        goto after_34;
    // 0x80083FCC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_34:
    // 0x80083FD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083FD4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083FD8: sw          $v0, 0xA28($at)
    MEM_W(0XA28, ctx->r1) = ctx->r2;
    // 0x80083FDC: addiu       $a1, $a1, -0x1000
    ctx->r5 = ADD32(ctx->r5, -0X1000);
    // 0x80083FE0: jal         0x800B62D4
    // 0x80083FE4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    sprintf_recomp(rdram, ctx);
        goto after_35;
    // 0x80083FE4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_35:
    // 0x80083FE8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80083FEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80083FF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083FF4: lwc1        $f18, 0x38F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X38F8);
    // 0x80083FF8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80083FFC: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80084000: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80084004: lw          $a3, 0x9A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X9A0);
    // 0x80084008: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x8008400C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80084010: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80084014: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80084018: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8008401C: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80084020: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80084024: nop

    // 0x80084028: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8008402C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80084030: beq         $t8, $zero, L_80084080
    if (ctx->r24 == 0) {
        // 0x80084034: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80084080;
    }
    // 0x80084034: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80084038: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008403C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80084040: sub.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80084044: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80084048: nop

    // 0x8008404C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80084050: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80084054: nop

    // 0x80084058: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8008405C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80084060: bne         $t8, $zero, L_80084078
    if (ctx->r24 != 0) {
        // 0x80084064: nop
    
            goto L_80084078;
    }
    // 0x80084064: nop

    // 0x80084068: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8008406C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80084070: b           L_80084090
    // 0x80084074: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80084090;
    // 0x80084074: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80084078:
    // 0x80084078: b           L_80084090
    // 0x8008407C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80084090;
    // 0x8008407C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80084080:
    // 0x80084080: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80084084: nop

    // 0x80084088: bltz        $t8, L_80084078
    if (SIGNED(ctx->r24) < 0) {
        // 0x8008408C: nop
    
            goto L_80084078;
    }
    // 0x8008408C: nop

L_80084090:
    // 0x80084090: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80084094: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80084098: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008409C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800840A0: lwc1        $f16, 0x3900($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3900);
    // 0x800840A4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800840A8: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800840AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800840B0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800840B4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800840B8: nop

    // 0x800840BC: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800840C0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800840C4: nop

    // 0x800840C8: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800840CC: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800840D0: beq         $t1, $zero, L_80084120
    if (ctx->r9 == 0) {
        // 0x800840D4: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80084120;
    }
    // 0x800840D4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800840D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800840DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800840E0: sub.s       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800840E4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800840E8: nop

    // 0x800840EC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800840F0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800840F4: nop

    // 0x800840F8: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800840FC: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80084100: bne         $t1, $zero, L_80084118
    if (ctx->r9 != 0) {
        // 0x80084104: nop
    
            goto L_80084118;
    }
    // 0x80084104: nop

    // 0x80084108: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x8008410C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80084110: b           L_80084130
    // 0x80084114: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80084130;
    // 0x80084114: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80084118:
    // 0x80084118: b           L_80084130
    // 0x8008411C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80084130;
    // 0x8008411C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80084120:
    // 0x80084120: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80084124: nop

    // 0x80084128: bltz        $t1, L_80084118
    if (SIGNED(ctx->r9) < 0) {
        // 0x8008412C: nop
    
            goto L_80084118;
    }
    // 0x8008412C: nop

L_80084130:
    // 0x80084130: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80084134: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80084138: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008413C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80084140: lwc1        $f10, 0x3908($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3908);
    // 0x80084144: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80084148: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8008414C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80084150: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80084154: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80084158: nop

    // 0x8008415C: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80084160: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80084164: nop

    // 0x80084168: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x8008416C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80084170: beq         $t7, $zero, L_800841C0
    if (ctx->r15 == 0) {
        // 0x80084174: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_800841C0;
    }
    // 0x80084174: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80084178: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008417C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80084180: sub.s       $f16, $f6, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80084184: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80084188: nop

    // 0x8008418C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80084190: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80084194: nop

    // 0x80084198: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x8008419C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800841A0: bne         $t7, $zero, L_800841B8
    if (ctx->r15 != 0) {
        // 0x800841A4: nop
    
            goto L_800841B8;
    }
    // 0x800841A4: nop

    // 0x800841A8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800841AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800841B0: b           L_800841D0
    // 0x800841B4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800841D0;
    // 0x800841B4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800841B8:
    // 0x800841B8: b           L_800841D0
    // 0x800841BC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800841D0;
    // 0x800841BC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_800841C0:
    // 0x800841C0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800841C4: nop

    // 0x800841C8: bltz        $t7, L_800841B8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800841CC: nop
    
            goto L_800841B8;
    }
    // 0x800841CC: nop

L_800841D0:
    // 0x800841D0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800841D4: jal         0x800837FC
    // 0x800841D8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    Debug_DrawString(rdram, ctx);
        goto after_36;
    // 0x800841D8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_36:
    // 0x800841DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800841E0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800841E4: sw          $v0, 0xA28($at)
    MEM_W(0XA28, ctx->r1) = ctx->r2;
    // 0x800841E8: addiu       $a1, $a1, -0xFF8
    ctx->r5 = ADD32(ctx->r5, -0XFF8);
    // 0x800841EC: jal         0x800B62D4
    // 0x800841F0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    sprintf_recomp(rdram, ctx);
        goto after_37;
    // 0x800841F0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_37:
    // 0x800841F4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800841F8: lw          $a3, 0x9A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X9A0);
    // 0x800841FC: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80084200: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80084204: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80084208: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008420C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80084210: jal         0x800837FC
    // 0x80084214: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    Debug_DrawString(rdram, ctx);
        goto after_38;
    // 0x80084214: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_38:
    // 0x80084218: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008421C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80084220: sw          $v0, 0xA28($at)
    MEM_W(0XA28, ctx->r1) = ctx->r2;
    // 0x80084224: addiu       $a1, $a1, -0xFD8
    ctx->r5 = ADD32(ctx->r5, -0XFD8);
    // 0x80084228: jal         0x800B62D4
    // 0x8008422C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    sprintf_recomp(rdram, ctx);
        goto after_39;
    // 0x8008422C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_39:
    // 0x80084230: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80084234: lw          $a3, 0x9A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X9A0);
    // 0x80084238: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x8008423C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80084240: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80084244: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80084248: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008424C: jal         0x800837FC
    // 0x80084250: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    Debug_DrawString(rdram, ctx);
        goto after_40;
    // 0x80084250: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_40:
    // 0x80084254: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084258: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008425C: sw          $v0, 0xA28($at)
    MEM_W(0XA28, ctx->r1) = ctx->r2;
    // 0x80084260: addiu       $a1, $a1, -0xFB8
    ctx->r5 = ADD32(ctx->r5, -0XFB8);
    // 0x80084264: jal         0x800B62D4
    // 0x80084268: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    sprintf_recomp(rdram, ctx);
        goto after_41;
    // 0x80084268: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_41:
    // 0x8008426C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80084270: lw          $a3, 0x9A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X9A0);
    // 0x80084274: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80084278: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8008427C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80084280: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80084284: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80084288: jal         0x800837FC
    // 0x8008428C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    Debug_DrawString(rdram, ctx);
        goto after_42;
    // 0x8008428C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_42:
    // 0x80084290: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084294: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80084298: sw          $v0, 0xA28($at)
    MEM_W(0XA28, ctx->r1) = ctx->r2;
    // 0x8008429C: addiu       $a1, $a1, -0xF98
    ctx->r5 = ADD32(ctx->r5, -0XF98);
    // 0x800842A0: jal         0x800B62D4
    // 0x800842A4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    sprintf_recomp(rdram, ctx);
        goto after_43;
    // 0x800842A4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_43:
    // 0x800842A8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800842AC: lw          $a3, 0x9A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X9A0);
    // 0x800842B0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x800842B4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800842B8: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x800842BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800842C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800842C4: jal         0x800837FC
    // 0x800842C8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    Debug_DrawString(rdram, ctx);
        goto after_44;
    // 0x800842C8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_44:
    // 0x800842CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800842D0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800842D4: sw          $v0, 0xA28($at)
    MEM_W(0XA28, ctx->r1) = ctx->r2;
    // 0x800842D8: addiu       $a1, $a1, -0xF7C
    ctx->r5 = ADD32(ctx->r5, -0XF7C);
    // 0x800842DC: jal         0x800B62D4
    // 0x800842E0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    sprintf_recomp(rdram, ctx);
        goto after_45;
    // 0x800842E0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_45:
    // 0x800842E4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800842E8: lw          $a3, 0x9A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X9A0);
    // 0x800842EC: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x800842F0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800842F4: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x800842F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800842FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80084300: jal         0x800837FC
    // 0x80084304: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    Debug_DrawString(rdram, ctx);
        goto after_46;
    // 0x80084304: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_46:
    // 0x80084308: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8008430C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084310: sw          $v0, 0xA28($at)
    MEM_W(0XA28, ctx->r1) = ctx->r2;
    // 0x80084314: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80084318: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8008431C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80084320: jal         0x800B84B0
    // 0x80084324: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    osSetTime_recomp(rdram, ctx);
        goto after_47;
    // 0x80084324: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    after_47:
    // 0x80084328: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8008432C: nop

    // 0x80084330: bne         $t2, $zero, L_80083D3C
    if (ctx->r10 != 0) {
        // 0x80084334: nop
    
            goto L_80083D3C;
    }
    // 0x80084334: nop

    // 0x80084338: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8008433C: nop

    // 0x80084340: bne         $t3, $zero, L_80083D3C
    if (ctx->r11 != 0) {
        // 0x80084344: nop
    
            goto L_80083D3C;
    }
    // 0x80084344: nop

    // 0x80084348: jal         0x800B3D60
    // 0x8008434C: addiu       $a0, $sp, 0x868
    ctx->r4 = ADD32(ctx->r29, 0X868);
    osContStartReadData_recomp(rdram, ctx);
        goto after_48;
    // 0x8008434C: addiu       $a0, $sp, 0x868
    ctx->r4 = ADD32(ctx->r29, 0X868);
    after_48:
    // 0x80084350: addiu       $a0, $sp, 0x868
    ctx->r4 = ADD32(ctx->r29, 0X868);
    // 0x80084354: addiu       $a1, $sp, 0x880
    ctx->r5 = ADD32(ctx->r29, 0X880);
    // 0x80084358: jal         0x800B3C20
    // 0x8008435C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_49;
    // 0x8008435C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_49:
    // 0x80084360: jal         0x800B3DE4
    // 0x80084364: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    osContGetReadData_recomp(rdram, ctx);
        goto after_50;
    // 0x80084364: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_50:
    // 0x80084368: addiu       $t4, $sp, 0x30
    ctx->r12 = ADD32(ctx->r29, 0X30);
    // 0x8008436C: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80084370: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80084374: sh          $t5, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r13;
    // 0x80084378: b           L_80083D3C
    // 0x8008437C: sh          $t5, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r13;
        goto L_80083D3C;
    // 0x8008437C: sh          $t5, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r13;
    // 0x80084380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80084384: addiu       $sp, $sp, 0x890
    ctx->r29 = ADD32(ctx->r29, 0X890);
    // 0x80084388: jr          $ra
    // 0x8008438C: nop

    return;
    // 0x8008438C: nop

;}

RECOMP_FUNC void Debug_Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084390: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x80084394: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80084398: lw          $t7, 0x38F0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X38F0);
    // 0x8008439C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800843A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800843A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800843A8: sw          $a0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r4;
    // 0x800843AC: sw          $a1, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r5;
    // 0x800843B0: bne         $t7, $at, L_800843D8
    if (ctx->r15 != ctx->r1) {
        // 0x800843B4: sw          $t6, 0x12C($sp)
        MEM_W(0X12C, ctx->r29) = ctx->r14;
            goto L_800843D8;
    }
    // 0x800843B4: sw          $t6, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r14;
    // 0x800843B8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800843BC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800843C0: addiu       $a2, $a2, 0x9C8
    ctx->r6 = ADD32(ctx->r6, 0X9C8);
    // 0x800843C4: addiu       $a1, $a1, -0xF60
    ctx->r5 = ADD32(ctx->r5, -0XF60);
    // 0x800843C8: jal         0x800B62D4
    // 0x800843CC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800843CC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800843D0: b           L_80084448
    // 0x800843D4: nop

        goto L_80084448;
    // 0x800843D4: nop

L_800843D8:
    // 0x800843D8: lw          $t8, 0x134($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X134);
    // 0x800843DC: nop

    // 0x800843E0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800843E4: nop

    // 0x800843E8: beq         $t9, $zero, L_80084448
    if (ctx->r25 == 0) {
        // 0x800843EC: nop
    
            goto L_80084448;
    }
    // 0x800843EC: nop

L_800843F0:
    // 0x800843F0: lw          $t0, 0x134($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X134);
    // 0x800843F4: lw          $t2, 0x130($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X130);
    // 0x800843F8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800843FC: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x80084400: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80084404: bne         $t3, $t4, L_80084420
    if (ctx->r11 != ctx->r12) {
        // 0x80084408: nop
    
            goto L_80084420;
    }
    // 0x80084408: nop

    // 0x8008440C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80084410: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x80084414: addiu       $a1, $a1, -0xF5C
    ctx->r5 = ADD32(ctx->r5, -0XF5C);
    // 0x80084418: jal         0x800B62D4
    // 0x8008441C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8008441C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_1:
L_80084420:
    // 0x80084420: lw          $t5, 0x134($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X134);
    // 0x80084424: nop

    // 0x80084428: addiu       $t6, $t5, 0xC
    ctx->r14 = ADD32(ctx->r13, 0XC);
    // 0x8008442C: sw          $t6, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r14;
    // 0x80084430: lw          $t7, 0x134($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X134);
    // 0x80084434: nop

    // 0x80084438: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8008443C: nop

    // 0x80084440: bne         $t8, $zero, L_800843F0
    if (ctx->r24 != 0) {
        // 0x80084444: nop
    
            goto L_800843F0;
    }
    // 0x80084444: nop

L_80084448:
    // 0x80084448: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008444C: lw          $t9, 0xA28($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XA28);
    // 0x80084450: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80084454: lw          $a3, 0x9A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X9A0);
    // 0x80084458: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x8008445C: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    // 0x80084460: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80084464: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80084468: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8008446C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80084470: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80084474: jal         0x800837FC
    // 0x80084478: srl         $a1, $t9, 16
    ctx->r5 = S32(U32(ctx->r25) >> 16);
    Debug_DrawString(rdram, ctx);
        goto after_2;
    // 0x80084478: srl         $a1, $t9, 16
    ctx->r5 = S32(U32(ctx->r25) >> 16);
    after_2:
    // 0x8008447C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80084480: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084484: sw          $v0, 0xA28($at)
    MEM_W(0XA28, ctx->r1) = ctx->r2;
    // 0x80084488: jr          $ra
    // 0x8008448C: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x8008448C: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}

RECOMP_FUNC void Debug_PrintList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084490: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80084494: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80084498: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008449C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800844A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800844A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800844A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800844AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800844B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800844B4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800844B8: jal         0x800B3BFC
    // 0x800844BC: addiu       $a0, $a0, -0xF58
    ctx->r4 = ADD32(ctx->r4, -0XF58);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800844BC: addiu       $a0, $a0, -0xF58
    ctx->r4 = ADD32(ctx->r4, -0XF58);
    after_0:
    // 0x800844C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800844C4: jal         0x800B3BFC
    // 0x800844C8: addiu       $a0, $a0, -0xF4C
    ctx->r4 = ADD32(ctx->r4, -0XF4C);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800844C8: addiu       $a0, $a0, -0xF4C
    ctx->r4 = ADD32(ctx->r4, -0XF4C);
    after_1:
    // 0x800844CC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800844D0: nop

    // 0x800844D4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800844D8: nop

    // 0x800844DC: beq         $t8, $zero, L_80084560
    if (ctx->r24 == 0) {
        // 0x800844E0: nop
    
            goto L_80084560;
    }
    // 0x800844E0: nop

L_800844E4:
    // 0x800844E4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800844E8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800844EC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800844F0: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x800844F4: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x800844F8: bne         $t2, $t3, L_80084538
    if (ctx->r10 != ctx->r11) {
        // 0x800844FC: nop
    
            goto L_80084538;
    }
    // 0x800844FC: nop

    // 0x80084500: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80084504: nop

    // 0x80084508: beq         $t4, $zero, L_80084518
    if (ctx->r12 == 0) {
        // 0x8008450C: nop
    
            goto L_80084518;
    }
    // 0x8008450C: nop

    // 0x80084510: b           L_80084524
    // 0x80084514: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
        goto L_80084524;
    // 0x80084514: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80084518:
    // 0x80084518: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008451C: jal         0x800B3BFC
    // 0x80084520: addiu       $a0, $a0, -0xF48
    ctx->r4 = ADD32(ctx->r4, -0XF48);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x80084520: addiu       $a0, $a0, -0xF48
    ctx->r4 = ADD32(ctx->r4, -0XF48);
    after_2:
L_80084524:
    // 0x80084524: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80084528: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008452C: lw          $a1, 0x8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X8);
    // 0x80084530: jal         0x800B3BFC
    // 0x80084534: addiu       $a0, $a0, -0xF44
    ctx->r4 = ADD32(ctx->r4, -0XF44);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x80084534: addiu       $a0, $a0, -0xF44
    ctx->r4 = ADD32(ctx->r4, -0XF44);
    after_3:
L_80084538:
    // 0x80084538: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008453C: nop

    // 0x80084540: addiu       $t7, $t6, 0xC
    ctx->r15 = ADD32(ctx->r14, 0XC);
    // 0x80084544: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80084548: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8008454C: nop

    // 0x80084550: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80084554: nop

    // 0x80084558: bne         $t0, $zero, L_800844E4
    if (ctx->r8 != 0) {
        // 0x8008455C: nop
    
            goto L_800844E4;
    }
    // 0x8008455C: nop

L_80084560:
    // 0x80084560: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084564: jal         0x800B3BFC
    // 0x80084568: addiu       $a0, $a0, -0xF40
    ctx->r4 = ADD32(ctx->r4, -0XF40);
    rmonPrintf_recomp(rdram, ctx);
        goto after_4;
    // 0x80084568: addiu       $a0, $a0, -0xF40
    ctx->r4 = ADD32(ctx->r4, -0XF40);
    after_4:
    // 0x8008456C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084570: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80084574: jr          $ra
    // 0x80084578: nop

    return;
    // 0x80084578: nop

;}

RECOMP_FUNC void Debug_FaultThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008457C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80084580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084584: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084588: addiu       $a1, $a1, 0x980
    ctx->r5 = ADD32(ctx->r5, 0X980);
    // 0x8008458C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80084590: jal         0x800B30B0
    // 0x80084594: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80084594: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x80084598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008459C: sw          $zero, 0xA30($at)
    MEM_W(0XA30, ctx->r1) = 0;
L_800845A0:
    // 0x800845A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800845A4: addiu       $a0, $a0, 0x980
    ctx->r4 = ADD32(ctx->r4, 0X980);
    // 0x800845A8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800845AC: jal         0x800B3C20
    // 0x800845B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800845B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800845B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800845B8: lw          $t6, 0x99C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X99C);
    // 0x800845BC: nop

    // 0x800845C0: beq         $t6, $zero, L_800845E8
    if (ctx->r14 == 0) {
        // 0x800845C4: nop
    
            goto L_800845E8;
    }
    // 0x800845C4: nop

    // 0x800845C8: jalr        $t6
    // 0x800845CC: nop

    LOOKUP_FUNC(ctx->r14)(rdram, ctx);
        goto after_2;
    // 0x800845CC: nop

    after_2:
    // 0x800845D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800845D4: addiu       $a0, $a0, 0x3D0
    ctx->r4 = ADD32(ctx->r4, 0X3D0);
    // 0x800845D8: jal         0x800B7370
    // 0x800845DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_3;
    // 0x800845DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_800845E0:
    // 0x800845E0: b           L_800845E0
    pause_self(rdram);
    // 0x800845E4: nop

L_800845E8:
    // 0x800845E8: jal         0x800B84E0
    // 0x800845EC: nop

    __osGetCurrFaultedThread(rdram, ctx);
        goto after_4;
    // 0x800845EC: nop

    after_4:
    // 0x800845F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800845F4: sw          $v0, 0xA2C($at)
    MEM_W(0XA2C, ctx->r1) = ctx->r2;
    // 0x800845F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800845FC: lw          $t7, 0xA2C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XA2C);
    // 0x80084600: nop

    // 0x80084604: beq         $t7, $zero, L_800845A0
    if (ctx->r15 == 0) {
        // 0x80084608: nop
    
            goto L_800845A0;
    }
    // 0x80084608: nop

    // 0x8008460C: jal         0x80083910
    // 0x80084610: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    Debug_DrawFaultScreen(rdram, ctx);
        goto after_5;
    // 0x80084610: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_5:
L_80084614:
    // 0x80084614: b           L_80084614
    pause_self(rdram);
    // 0x80084618: nop

    // 0x8008461C: nop

    // 0x80084620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084624: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80084628: jr          $ra
    // 0x8008462C: nop

    return;
    // 0x8008462C: nop

;}

RECOMP_FUNC void Debug_FaultInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084630: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80084634: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80084638: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8008463C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80084640: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80084644: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80084648: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008464C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084650: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80084654: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80084658: addiu       $a0, $a0, 0x980
    ctx->r4 = ADD32(ctx->r4, 0X980);
    // 0x8008465C: addiu       $a1, $a1, 0x998
    ctx->r5 = ADD32(ctx->r5, 0X998);
    // 0x80084660: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80084664: jal         0x800B3080
    // 0x80084668: sw          $t6, 0x99C($at)
    MEM_W(0X99C, ctx->r1) = ctx->r14;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80084668: sw          $t6, 0x99C($at)
    MEM_W(0X99C, ctx->r1) = ctx->r14;
    after_0:
    // 0x8008466C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80084670: addiu       $t7, $t7, 0x580
    ctx->r15 = ADD32(ctx->r15, 0X580);
    // 0x80084674: addiu       $t8, $t7, 0x80
    ctx->r24 = ADD32(ctx->r15, 0X80);
    // 0x80084678: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008467C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80084680: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x80084684: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80084688: addiu       $a2, $a2, 0x457C
    ctx->r6 = ADD32(ctx->r6, 0X457C);
    // 0x8008468C: addiu       $a0, $a0, 0x3D0
    ctx->r4 = ADD32(ctx->r4, 0X3D0);
    // 0x80084690: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80084694: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80084698: jal         0x800B6010
    // 0x8008469C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x8008469C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800846A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800846A4: jal         0x800B6160
    // 0x800846A8: addiu       $a0, $a0, 0x3D0
    ctx->r4 = ADD32(ctx->r4, 0X3D0);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800846A8: addiu       $a0, $a0, 0x3D0
    ctx->r4 = ADD32(ctx->r4, 0X3D0);
    after_2:
    // 0x800846AC: lhu         $t1, 0x2A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2A);
    // 0x800846B0: lhu         $t2, 0x2E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2E);
    // 0x800846B4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800846B8: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800846BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800846C0: sw          $t0, 0x9A0($at)
    MEM_W(0X9A0, ctx->r1) = ctx->r8;
    // 0x800846C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800846C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800846CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800846D0: mflo        $t3
    ctx->r11 = lo;
    // 0x800846D4: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800846D8: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x800846DC: sw          $t5, 0x9A4($at)
    MEM_W(0X9A4, ctx->r1) = ctx->r13;
    // 0x800846E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800846E4: sh          $t1, 0x9A8($at)
    MEM_H(0X9A8, ctx->r1) = ctx->r9;
    // 0x800846E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800846EC: jr          $ra
    // 0x800846F0: sh          $t2, 0x9AA($at)
    MEM_H(0X9AA, ctx->r1) = ctx->r10;
    return;
    // 0x800846F0: sh          $t2, 0x9AA($at)
    MEM_H(0X9AA, ctx->r1) = ctx->r10;
    // 0x800846F4: nop

    // 0x800846F8: nop

    // 0x800846FC: nop

;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lzo1x_1_compress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800825B4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800825B8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800825BC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800825C0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800825C4: sltiu       $at, $t7, 0xE
    ctx->r1 = ctx->r15 < 0XE ? 1 : 0;
    // 0x800825C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800825CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800825D0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800825D4: beq         $at, $zero, L_800825E4
    if (ctx->r1 == 0) {
        // 0x800825D8: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_800825E4;
    }
    // 0x800825D8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800825DC: b           L_8008261C
    // 0x800825E0: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
        goto L_8008261C;
    // 0x800825E0: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_800825E4:
    // 0x800825E4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800825E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800825EC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800825F0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800825F4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800825F8: jal         0x80081F0C
    // 0x800825FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    _lzo1x_1_do_compress(rdram, ctx);
        goto after_0;
    // 0x800825FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x80082600: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80082604: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80082608: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8008260C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80082610: nop

    // 0x80082614: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80082618: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_8008261C:
    // 0x8008261C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80082620: nop

    // 0x80082624: beq         $t3, $zero, L_8008278C
    if (ctx->r11 == 0) {
        // 0x80082628: nop
    
            goto L_8008278C;
    }
    // 0x80082628: nop

    // 0x8008262C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80082630: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80082634: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80082638: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8008263C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80082640: subu        $t7, $t6, $t3
    ctx->r15 = SUB32(ctx->r14, ctx->r11);
    // 0x80082644: bne         $t8, $t0, L_80082674
    if (ctx->r24 != ctx->r8) {
        // 0x80082648: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_80082674;
    }
    // 0x80082648: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8008264C: sltiu       $at, $t3, 0xEF
    ctx->r1 = ctx->r11 < 0XEF ? 1 : 0;
    // 0x80082650: beq         $at, $zero, L_80082674
    if (ctx->r1 == 0) {
        // 0x80082654: nop
    
            goto L_80082674;
    }
    // 0x80082654: nop

    // 0x80082658: addiu       $t9, $t3, 0x11
    ctx->r25 = ADD32(ctx->r11, 0X11);
    // 0x8008265C: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x80082660: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80082664: nop

    // 0x80082668: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008266C: b           L_80082750
    // 0x80082670: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
        goto L_80082750;
    // 0x80082670: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_80082674:
    // 0x80082674: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80082678: nop

    // 0x8008267C: sltiu       $at, $t4, 0x4
    ctx->r1 = ctx->r12 < 0X4 ? 1 : 0;
    // 0x80082680: beq         $at, $zero, L_800826A4
    if (ctx->r1 == 0) {
        // 0x80082684: nop
    
            goto L_800826A4;
    }
    // 0x80082684: nop

    // 0x80082688: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8008268C: lbu         $t7, 0x2B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2B);
    // 0x80082690: lbu         $t6, -0x2($t5)
    ctx->r14 = MEM_BU(ctx->r13, -0X2);
    // 0x80082694: nop

    // 0x80082698: or          $t0, $t6, $t7
    ctx->r8 = ctx->r14 | ctx->r15;
    // 0x8008269C: b           L_80082750
    // 0x800826A0: sb          $t0, -0x2($t5)
    MEM_B(-0X2, ctx->r13) = ctx->r8;
        goto L_80082750;
    // 0x800826A0: sb          $t0, -0x2($t5)
    MEM_B(-0X2, ctx->r13) = ctx->r8;
L_800826A4:
    // 0x800826A4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800826A8: nop

    // 0x800826AC: sltiu       $at, $t3, 0x13
    ctx->r1 = ctx->r11 < 0X13 ? 1 : 0;
    // 0x800826B0: beq         $at, $zero, L_800826D8
    if (ctx->r1 == 0) {
        // 0x800826B4: nop
    
            goto L_800826D8;
    }
    // 0x800826B4: nop

    // 0x800826B8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800826BC: addiu       $t9, $t3, -0x3
    ctx->r25 = ADD32(ctx->r11, -0X3);
    // 0x800826C0: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800826C4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800826C8: nop

    // 0x800826CC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800826D0: b           L_80082750
    // 0x800826D4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
        goto L_80082750;
    // 0x800826D4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_800826D8:
    // 0x800826D8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800826DC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800826E0: addiu       $t6, $t4, -0x12
    ctx->r14 = ADD32(ctx->r12, -0X12);
    // 0x800826E4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800826E8: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x800826EC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800826F0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800826F4: addiu       $t5, $t0, 0x1
    ctx->r13 = ADD32(ctx->r8, 0X1);
    // 0x800826F8: sltiu       $at, $t3, 0x100
    ctx->r1 = ctx->r11 < 0X100 ? 1 : 0;
    // 0x800826FC: bne         $at, $zero, L_80082730
    if (ctx->r1 != 0) {
        // 0x80082700: sw          $t5, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r13;
            goto L_80082730;
    }
    // 0x80082700: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_80082704:
    // 0x80082704: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082708: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8008270C: addiu       $t8, $t9, -0xFF
    ctx->r24 = ADD32(ctx->r25, -0XFF);
    // 0x80082710: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80082714: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80082718: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8008271C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80082720: sltiu       $at, $t6, 0x100
    ctx->r1 = ctx->r14 < 0X100 ? 1 : 0;
    // 0x80082724: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80082728: beq         $at, $zero, L_80082704
    if (ctx->r1 == 0) {
        // 0x8008272C: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_80082704;
    }
    // 0x8008272C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_80082730:
    // 0x80082730: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80082734: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80082738: nop

    // 0x8008273C: sb          $t7, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r15;
    // 0x80082740: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80082744: nop

    // 0x80082748: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x8008274C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80082750:
    // 0x80082750: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80082754: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80082758: lbu         $t8, 0x0($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X0);
    // 0x8008275C: nop

    // 0x80082760: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
    // 0x80082764: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80082768: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8008276C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80082770: addiu       $t5, $t0, -0x1
    ctx->r13 = ADD32(ctx->r8, -0X1);
    // 0x80082774: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80082778: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8008277C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80082780: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80082784: bne         $t5, $zero, L_80082750
    if (ctx->r13 != 0) {
        // 0x80082788: sw          $t5, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r13;
            goto L_80082750;
    }
    // 0x80082788: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8008278C:
    // 0x8008278C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80082790: addiu       $t3, $zero, 0x11
    ctx->r11 = ADD32(0, 0X11);
    // 0x80082794: sb          $t3, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r11;
    // 0x80082798: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8008279C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800827A0: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x800827A4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800827A8: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x800827AC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800827B0: nop

    // 0x800827B4: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x800827B8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800827BC: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x800827C0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800827C4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800827C8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800827CC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800827D0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800827D4: subu        $t5, $t7, $t0
    ctx->r13 = SUB32(ctx->r15, ctx->r8);
    // 0x800827D8: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x800827DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800827E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800827E4: jr          $ra
    // 0x800827E8: nop

    return;
    // 0x800827E8: nop

;}

RECOMP_FUNC void lzo1x_decompress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800827F0: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x800827F4: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800827F8: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800827FC: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x80082800: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x80082804: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80082808: slti        $at, $t7, 0x12
    ctx->r1 = SIGNED(ctx->r15) < 0X12 ? 1 : 0;
    // 0x8008280C: bne         $at, $zero, L_8008284C
    if (ctx->r1 != 0) {
        // 0x80082810: nop
    
            goto L_8008284C;
    }
    // 0x80082810: nop

    // 0x80082814: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80082818: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8008281C: addiu       $t2, $t2, -0x11
    ctx->r10 = ADD32(ctx->r10, -0X11);
    // 0x80082820: sltiu       $at, $t2, 0x4
    ctx->r1 = ctx->r10 < 0X4 ? 1 : 0;
    // 0x80082824: bne         $at, $zero, L_80082AF8
    if (ctx->r1 != 0) {
        // 0x80082828: nop
    
            goto L_80082AF8;
    }
    // 0x80082828: nop

L_8008282C:
    // 0x8008282C: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x80082830: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80082834: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082838: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8008283C: bne         $t2, $zero, L_8008282C
    if (ctx->r10 != 0) {
        // 0x80082840: sb          $t8, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r24;
            goto L_8008282C;
    }
    // 0x80082840: sb          $t8, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r24;
    // 0x80082844: b           L_800828E0
    // 0x80082848: nop

        goto L_800828E0;
    // 0x80082848: nop

L_8008284C:
    // 0x8008284C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80082850: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082854: sltiu       $at, $t2, 0x10
    ctx->r1 = ctx->r10 < 0X10 ? 1 : 0;
    // 0x80082858: beq         $at, $zero, L_80082940
    if (ctx->r1 == 0) {
        // 0x8008285C: nop
    
            goto L_80082940;
    }
    // 0x8008285C: nop

    // 0x80082860: bne         $t2, $zero, L_80082898
    if (ctx->r10 != 0) {
        // 0x80082864: nop
    
            goto L_80082898;
    }
    // 0x80082864: nop

    // 0x80082868: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x8008286C: nop

    // 0x80082870: bne         $t9, $zero, L_80082888
    if (ctx->r25 != 0) {
        // 0x80082874: nop
    
            goto L_80082888;
    }
    // 0x80082874: nop

L_80082878:
    // 0x80082878: lbu         $t6, 0x1($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X1);
    // 0x8008287C: addiu       $t2, $t2, 0xFF
    ctx->r10 = ADD32(ctx->r10, 0XFF);
    // 0x80082880: beq         $t6, $zero, L_80082878
    if (ctx->r14 == 0) {
        // 0x80082884: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_80082878;
    }
    // 0x80082884: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80082888:
    // 0x80082888: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x8008288C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082890: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x80082894: addiu       $t2, $t2, 0xF
    ctx->r10 = ADD32(ctx->r10, 0XF);
L_80082898:
    // 0x80082898: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x8008289C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800828A0: sb          $t8, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r24;
    // 0x800828A4: lbu         $t9, 0x1($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X1);
    // 0x800828A8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800828AC: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x800828B0: lbu         $t6, 0x1($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X1);
    // 0x800828B4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800828B8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800828BC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800828C0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800828C4: sb          $t6, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r14;
L_800828C8:
    // 0x800828C8: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x800828CC: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800828D0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800828D4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800828D8: bne         $t2, $zero, L_800828C8
    if (ctx->r10 != 0) {
        // 0x800828DC: sb          $t7, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r15;
            goto L_800828C8;
    }
    // 0x800828DC: sb          $t7, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r15;
L_800828E0:
    // 0x800828E0: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800828E4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800828E8: sltiu       $at, $t2, 0x10
    ctx->r1 = ctx->r10 < 0X10 ? 1 : 0;
    // 0x800828EC: beq         $at, $zero, L_80082940
    if (ctx->r1 == 0) {
        // 0x800828F0: nop
    
            goto L_80082940;
    }
    // 0x800828F0: nop

    // 0x800828F4: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x800828F8: addiu       $t3, $t0, -0x801
    ctx->r11 = ADD32(ctx->r8, -0X801);
    // 0x800828FC: srl         $t8, $t2, 2
    ctx->r24 = S32(U32(ctx->r10) >> 2);
    // 0x80082900: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x80082904: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80082908: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x8008290C: lbu         $t7, 0x0($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X0);
    // 0x80082910: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082914: sb          $t7, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r15;
    // 0x80082918: lbu         $t8, 0x1($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X1);
    // 0x8008291C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082920: sb          $t8, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r24;
    // 0x80082924: lbu         $t9, 0x2($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X2);
    // 0x80082928: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8008292C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082930: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80082934: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082938: b           L_80082AE0
    // 0x8008293C: sb          $t9, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r25;
        goto L_80082AE0;
    // 0x8008293C: sb          $t9, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r25;
L_80082940:
    // 0x80082940: sltiu       $at, $t2, 0x40
    ctx->r1 = ctx->r10 < 0X40 ? 1 : 0;
    // 0x80082944: bne         $at, $zero, L_8008297C
    if (ctx->r1 != 0) {
        // 0x80082948: nop
    
            goto L_8008297C;
    }
    // 0x80082948: nop

    // 0x8008294C: srl         $t6, $t2, 2
    ctx->r14 = S32(U32(ctx->r10) >> 2);
    // 0x80082950: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x80082954: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80082958: addiu       $t3, $t0, -0x1
    ctx->r11 = ADD32(ctx->r8, -0X1);
    // 0x8008295C: srl         $t6, $t2, 5
    ctx->r14 = S32(U32(ctx->r10) >> 5);
    // 0x80082960: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x80082964: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x80082968: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8008296C: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x80082970: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082974: b           L_80082AA8
    // 0x80082978: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
        goto L_80082AA8;
    // 0x80082978: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
L_8008297C:
    // 0x8008297C: sltiu       $at, $t2, 0x20
    ctx->r1 = ctx->r10 < 0X20 ? 1 : 0;
    // 0x80082980: bne         $at, $zero, L_800829EC
    if (ctx->r1 != 0) {
        // 0x80082984: nop
    
            goto L_800829EC;
    }
    // 0x80082984: nop

    // 0x80082988: andi        $t7, $t2, 0x1F
    ctx->r15 = ctx->r10 & 0X1F;
    // 0x8008298C: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x80082990: bne         $t2, $zero, L_800829C8
    if (ctx->r10 != 0) {
        // 0x80082994: nop
    
            goto L_800829C8;
    }
    // 0x80082994: nop

    // 0x80082998: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x8008299C: nop

    // 0x800829A0: bne         $t8, $zero, L_800829B8
    if (ctx->r24 != 0) {
        // 0x800829A4: nop
    
            goto L_800829B8;
    }
    // 0x800829A4: nop

L_800829A8:
    // 0x800829A8: lbu         $t9, 0x1($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X1);
    // 0x800829AC: addiu       $t2, $t2, 0xFF
    ctx->r10 = ADD32(ctx->r10, 0XFF);
    // 0x800829B0: beq         $t9, $zero, L_800829A8
    if (ctx->r25 == 0) {
        // 0x800829B4: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800829A8;
    }
    // 0x800829B4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800829B8:
    // 0x800829B8: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x800829BC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800829C0: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x800829C4: addiu       $t2, $t2, 0x1F
    ctx->r10 = ADD32(ctx->r10, 0X1F);
L_800829C8:
    // 0x800829C8: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x800829CC: lbu         $t9, 0x1($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X1);
    // 0x800829D0: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x800829D4: sll         $t6, $t9, 6
    ctx->r14 = S32(ctx->r25 << 6);
    // 0x800829D8: addiu       $t3, $t0, -0x1
    ctx->r11 = ADD32(ctx->r8, -0X1);
    // 0x800829DC: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800829E0: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x800829E4: b           L_80082AA8
    // 0x800829E8: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
        goto L_80082AA8;
    // 0x800829E8: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
L_800829EC:
    // 0x800829EC: sltiu       $at, $t2, 0x10
    ctx->r1 = ctx->r10 < 0X10 ? 1 : 0;
    // 0x800829F0: bne         $at, $zero, L_80082A6C
    if (ctx->r1 != 0) {
        // 0x800829F4: nop
    
            goto L_80082A6C;
    }
    // 0x800829F4: nop

    // 0x800829F8: andi        $t9, $t2, 0x8
    ctx->r25 = ctx->r10 & 0X8;
    // 0x800829FC: andi        $t6, $t2, 0x7
    ctx->r14 = ctx->r10 & 0X7;
    // 0x80082A00: or          $t3, $t0, $zero
    ctx->r11 = ctx->r8 | 0;
    // 0x80082A04: sll         $t8, $t9, 11
    ctx->r24 = S32(ctx->r25 << 11);
    // 0x80082A08: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x80082A0C: bne         $t2, $zero, L_80082A44
    if (ctx->r10 != 0) {
        // 0x80082A10: subu        $t3, $t3, $t8
        ctx->r11 = SUB32(ctx->r11, ctx->r24);
            goto L_80082A44;
    }
    // 0x80082A10: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x80082A14: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x80082A18: nop

    // 0x80082A1C: bne         $t7, $zero, L_80082A34
    if (ctx->r15 != 0) {
        // 0x80082A20: nop
    
            goto L_80082A34;
    }
    // 0x80082A20: nop

L_80082A24:
    // 0x80082A24: lbu         $t9, 0x1($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X1);
    // 0x80082A28: addiu       $t2, $t2, 0xFF
    ctx->r10 = ADD32(ctx->r10, 0XFF);
    // 0x80082A2C: beq         $t9, $zero, L_80082A24
    if (ctx->r25 == 0) {
        // 0x80082A30: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_80082A24;
    }
    // 0x80082A30: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80082A34:
    // 0x80082A34: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x80082A38: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082A3C: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x80082A40: addiu       $t2, $t2, 0x7
    ctx->r10 = ADD32(ctx->r10, 0X7);
L_80082A44:
    // 0x80082A44: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x80082A48: lbu         $t9, 0x1($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X1);
    // 0x80082A4C: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80082A50: sll         $t8, $t9, 6
    ctx->r24 = S32(ctx->r25 << 6);
    // 0x80082A54: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x80082A58: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x80082A5C: beq         $t3, $t0, L_80082B1C
    if (ctx->r11 == ctx->r8) {
        // 0x80082A60: addiu       $t1, $t1, 0x2
        ctx->r9 = ADD32(ctx->r9, 0X2);
            goto L_80082B1C;
    }
    // 0x80082A60: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x80082A64: b           L_80082AA8
    // 0x80082A68: addiu       $t3, $t3, -0x4000
    ctx->r11 = ADD32(ctx->r11, -0X4000);
        goto L_80082AA8;
    // 0x80082A68: addiu       $t3, $t3, -0x4000
    ctx->r11 = ADD32(ctx->r11, -0X4000);
L_80082A6C:
    // 0x80082A6C: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x80082A70: addiu       $t3, $t0, -0x1
    ctx->r11 = ADD32(ctx->r8, -0X1);
    // 0x80082A74: srl         $t9, $t2, 2
    ctx->r25 = S32(U32(ctx->r10) >> 2);
    // 0x80082A78: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x80082A7C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80082A80: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x80082A84: lbu         $t6, 0x0($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X0);
    // 0x80082A88: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082A8C: sb          $t6, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r14;
    // 0x80082A90: lbu         $t9, 0x1($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X1);
    // 0x80082A94: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082A98: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082A9C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80082AA0: b           L_80082AE0
    // 0x80082AA4: sb          $t9, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r25;
        goto L_80082AE0;
    // 0x80082AA4: sb          $t9, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r25;
L_80082AA8:
    // 0x80082AA8: lbu         $t7, 0x0($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X0);
    // 0x80082AAC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082AB0: sb          $t7, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r15;
    // 0x80082AB4: lbu         $t8, 0x1($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X1);
    // 0x80082AB8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80082ABC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80082AC0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082AC4: sb          $t8, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r24;
L_80082AC8:
    // 0x80082AC8: lbu         $t6, 0x0($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X0);
    // 0x80082ACC: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80082AD0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082AD4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80082AD8: bne         $t2, $zero, L_80082AC8
    if (ctx->r10 != 0) {
        // 0x80082ADC: sb          $t6, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r14;
            goto L_80082AC8;
    }
    // 0x80082ADC: sb          $t6, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r14;
L_80082AE0:
    // 0x80082AE0: lbu         $t2, -0x2($t1)
    ctx->r10 = MEM_BU(ctx->r9, -0X2);
    // 0x80082AE4: nop

    // 0x80082AE8: andi        $t9, $t2, 0x3
    ctx->r25 = ctx->r10 & 0X3;
    // 0x80082AEC: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x80082AF0: beq         $t2, $zero, L_8008284C
    if (ctx->r10 == 0) {
        // 0x80082AF4: nop
    
            goto L_8008284C;
    }
    // 0x80082AF4: nop

L_80082AF8:
    // 0x80082AF8: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x80082AFC: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80082B00: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082B04: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082B08: bne         $t2, $zero, L_80082AF8
    if (ctx->r10 != 0) {
        // 0x80082B0C: sb          $t7, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r15;
            goto L_80082AF8;
    }
    // 0x80082B0C: sb          $t7, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r15;
    // 0x80082B10: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80082B14: b           L_80082940
    // 0x80082B18: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
        goto L_80082940;
    // 0x80082B18: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80082B1C:
    // 0x80082B1C: subu        $t8, $t0, $a2
    ctx->r24 = SUB32(ctx->r8, ctx->r6);
    // 0x80082B20: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80082B24: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80082B28: nop

    // 0x80082B2C: bne         $t1, $t6, L_80082B3C
    if (ctx->r9 != ctx->r14) {
        // 0x80082B30: nop
    
            goto L_80082B3C;
    }
    // 0x80082B30: nop

    // 0x80082B34: b           L_80082B60
    // 0x80082B38: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
        goto L_80082B60;
    // 0x80082B38: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_80082B3C:
    // 0x80082B3C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x80082B40: nop

    // 0x80082B44: sltu        $at, $t1, $t9
    ctx->r1 = ctx->r9 < ctx->r25 ? 1 : 0;
    // 0x80082B48: beq         $at, $zero, L_80082B58
    if (ctx->r1 == 0) {
        // 0x80082B4C: nop
    
            goto L_80082B58;
    }
    // 0x80082B4C: nop

    // 0x80082B50: b           L_80082B5C
    // 0x80082B54: addiu       $t5, $zero, -0x8
    ctx->r13 = ADD32(0, -0X8);
        goto L_80082B5C;
    // 0x80082B54: addiu       $t5, $zero, -0x8
    ctx->r13 = ADD32(0, -0X8);
L_80082B58:
    // 0x80082B58: addiu       $t5, $zero, -0x4
    ctx->r13 = ADD32(0, -0X4);
L_80082B5C:
    // 0x80082B5C: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
L_80082B60:
    // 0x80082B60: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80082B64: jr          $ra
    // 0x80082B68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80082B68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void lzo1x_decompress_safe(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082B70: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x80082B74: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x80082B78: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80082B7C: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x80082B80: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x80082B84: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x80082B88: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80082B8C: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x80082B90: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80082B94: slti        $at, $t9, 0x12
    ctx->r1 = SIGNED(ctx->r25) < 0X12 ? 1 : 0;
    // 0x80082B98: bne         $at, $zero, L_80082C08
    if (ctx->r1 != 0) {
        // 0x80082B9C: nop
    
            goto L_80082C08;
    }
    // 0x80082B9C: nop

    // 0x80082BA0: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80082BA4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082BA8: addiu       $t2, $t2, -0x11
    ctx->r10 = ADD32(ctx->r10, -0X11);
    // 0x80082BAC: sltiu       $at, $t2, 0x4
    ctx->r1 = ctx->r10 < 0X4 ? 1 : 0;
    // 0x80082BB0: bne         $at, $zero, L_80082FF8
    if (ctx->r1 != 0) {
        // 0x80082BB4: nop
    
            goto L_80082FF8;
    }
    // 0x80082BB4: nop

    // 0x80082BB8: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x80082BBC: nop

    // 0x80082BC0: subu        $t7, $t6, $t0
    ctx->r15 = SUB32(ctx->r14, ctx->r8);
    // 0x80082BC4: sltu        $at, $t7, $t2
    ctx->r1 = ctx->r15 < ctx->r10 ? 1 : 0;
    // 0x80082BC8: bne         $at, $zero, L_800830D8
    if (ctx->r1 != 0) {
        // 0x80082BCC: nop
    
            goto L_800830D8;
    }
    // 0x80082BCC: nop

    // 0x80082BD0: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80082BD4: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x80082BD8: subu        $t9, $t8, $t1
    ctx->r25 = SUB32(ctx->r24, ctx->r9);
    // 0x80082BDC: sltu        $at, $t9, $t6
    ctx->r1 = ctx->r25 < ctx->r14 ? 1 : 0;
    // 0x80082BE0: bne         $at, $zero, L_800830C8
    if (ctx->r1 != 0) {
        // 0x80082BE4: nop
    
            goto L_800830C8;
    }
    // 0x80082BE4: nop

L_80082BE8:
    // 0x80082BE8: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x80082BEC: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80082BF0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082BF4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082BF8: bne         $t2, $zero, L_80082BE8
    if (ctx->r10 != 0) {
        // 0x80082BFC: sb          $t7, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r15;
            goto L_80082BE8;
    }
    // 0x80082BFC: sb          $t7, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r15;
    // 0x80082C00: b           L_80082D08
    // 0x80082C04: nop

        goto L_80082D08;
    // 0x80082C04: nop

L_80082C08:
    // 0x80082C08: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80082C0C: nop

    // 0x80082C10: sltu        $at, $t1, $t8
    ctx->r1 = ctx->r9 < ctx->r24 ? 1 : 0;
    // 0x80082C14: beq         $at, $zero, L_8008306C
    if (ctx->r1 == 0) {
        // 0x80082C18: nop
    
            goto L_8008306C;
    }
    // 0x80082C18: nop

L_80082C1C:
    // 0x80082C1C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80082C20: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082C24: sltiu       $at, $t2, 0x10
    ctx->r1 = ctx->r10 < 0X10 ? 1 : 0;
    // 0x80082C28: beq         $at, $zero, L_80082D88
    if (ctx->r1 == 0) {
        // 0x80082C2C: nop
    
            goto L_80082D88;
    }
    // 0x80082C2C: nop

    // 0x80082C30: bne         $t2, $zero, L_80082C90
    if (ctx->r10 != 0) {
        // 0x80082C34: nop
    
            goto L_80082C90;
    }
    // 0x80082C34: nop

    // 0x80082C38: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x80082C3C: nop

    // 0x80082C40: subu        $t6, $t9, $t1
    ctx->r14 = SUB32(ctx->r25, ctx->r9);
    // 0x80082C44: beq         $t6, $zero, L_800830C8
    if (ctx->r14 == 0) {
        // 0x80082C48: nop
    
            goto L_800830C8;
    }
    // 0x80082C48: nop

    // 0x80082C4C: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x80082C50: nop

    // 0x80082C54: bne         $t7, $zero, L_80082C80
    if (ctx->r15 != 0) {
        // 0x80082C58: nop
    
            goto L_80082C80;
    }
    // 0x80082C58: nop

L_80082C5C:
    // 0x80082C5C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80082C60: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082C64: subu        $t9, $t8, $t1
    ctx->r25 = SUB32(ctx->r24, ctx->r9);
    // 0x80082C68: beq         $t9, $zero, L_800830C8
    if (ctx->r25 == 0) {
        // 0x80082C6C: addiu       $t2, $t2, 0xFF
        ctx->r10 = ADD32(ctx->r10, 0XFF);
            goto L_800830C8;
    }
    // 0x80082C6C: addiu       $t2, $t2, 0xFF
    ctx->r10 = ADD32(ctx->r10, 0XFF);
    // 0x80082C70: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x80082C74: nop

    // 0x80082C78: beq         $t6, $zero, L_80082C5C
    if (ctx->r14 == 0) {
        // 0x80082C7C: nop
    
            goto L_80082C5C;
    }
    // 0x80082C7C: nop

L_80082C80:
    // 0x80082C80: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x80082C84: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082C88: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x80082C8C: addiu       $t2, $t2, 0xF
    ctx->r10 = ADD32(ctx->r10, 0XF);
L_80082C90:
    // 0x80082C90: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x80082C94: addiu       $t6, $t2, 0x3
    ctx->r14 = ADD32(ctx->r10, 0X3);
    // 0x80082C98: subu        $t9, $t8, $t0
    ctx->r25 = SUB32(ctx->r24, ctx->r8);
    // 0x80082C9C: sltu        $at, $t9, $t6
    ctx->r1 = ctx->r25 < ctx->r14 ? 1 : 0;
    // 0x80082CA0: bne         $at, $zero, L_800830D8
    if (ctx->r1 != 0) {
        // 0x80082CA4: nop
    
            goto L_800830D8;
    }
    // 0x80082CA4: nop

    // 0x80082CA8: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80082CAC: addiu       $t9, $t2, 0x4
    ctx->r25 = ADD32(ctx->r10, 0X4);
    // 0x80082CB0: subu        $t8, $t7, $t1
    ctx->r24 = SUB32(ctx->r15, ctx->r9);
    // 0x80082CB4: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x80082CB8: bne         $at, $zero, L_800830C8
    if (ctx->r1 != 0) {
        // 0x80082CBC: nop
    
            goto L_800830C8;
    }
    // 0x80082CBC: nop

    // 0x80082CC0: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x80082CC4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082CC8: sb          $t6, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r14;
    // 0x80082CCC: lbu         $t7, 0x1($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X1);
    // 0x80082CD0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082CD4: sb          $t7, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r15;
    // 0x80082CD8: lbu         $t8, 0x1($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1);
    // 0x80082CDC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082CE0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082CE4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082CE8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082CEC: sb          $t8, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r24;
L_80082CF0:
    // 0x80082CF0: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x80082CF4: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80082CF8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082CFC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082D00: bne         $t2, $zero, L_80082CF0
    if (ctx->r10 != 0) {
        // 0x80082D04: sb          $t9, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r25;
            goto L_80082CF0;
    }
    // 0x80082D04: sb          $t9, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r25;
L_80082D08:
    // 0x80082D08: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80082D0C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082D10: sltiu       $at, $t2, 0x10
    ctx->r1 = ctx->r10 < 0X10 ? 1 : 0;
    // 0x80082D14: beq         $at, $zero, L_80082D88
    if (ctx->r1 == 0) {
        // 0x80082D18: nop
    
            goto L_80082D88;
    }
    // 0x80082D18: nop

    // 0x80082D1C: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x80082D20: addiu       $t3, $t0, -0x801
    ctx->r11 = ADD32(ctx->r8, -0X801);
    // 0x80082D24: srl         $t6, $t2, 2
    ctx->r14 = S32(U32(ctx->r10) >> 2);
    // 0x80082D28: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x80082D2C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80082D30: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x80082D34: sltu        $at, $t3, $a2
    ctx->r1 = ctx->r11 < ctx->r6 ? 1 : 0;
    // 0x80082D38: bne         $at, $zero, L_800830E8
    if (ctx->r1 != 0) {
        // 0x80082D3C: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800830E8;
    }
    // 0x80082D3C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082D40: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80082D44: nop

    // 0x80082D48: subu        $t6, $t9, $t0
    ctx->r14 = SUB32(ctx->r25, ctx->r8);
    // 0x80082D4C: sltiu       $at, $t6, 0x3
    ctx->r1 = ctx->r14 < 0X3 ? 1 : 0;
    // 0x80082D50: bne         $at, $zero, L_800830D8
    if (ctx->r1 != 0) {
        // 0x80082D54: nop
    
            goto L_800830D8;
    }
    // 0x80082D54: nop

    // 0x80082D58: lbu         $t7, 0x0($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X0);
    // 0x80082D5C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082D60: sb          $t7, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r15;
    // 0x80082D64: lbu         $t8, 0x1($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X1);
    // 0x80082D68: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082D6C: sb          $t8, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r24;
    // 0x80082D70: lbu         $t9, 0x2($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X2);
    // 0x80082D74: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80082D78: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80082D7C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082D80: b           L_80082FE0
    // 0x80082D84: sb          $t9, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r25;
        goto L_80082FE0;
    // 0x80082D84: sb          $t9, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r25;
L_80082D88:
    // 0x80082D88: sltiu       $at, $t2, 0x40
    ctx->r1 = ctx->r10 < 0X40 ? 1 : 0;
    // 0x80082D8C: bne         $at, $zero, L_80082DE8
    if (ctx->r1 != 0) {
        // 0x80082D90: nop
    
            goto L_80082DE8;
    }
    // 0x80082D90: nop

    // 0x80082D94: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x80082D98: srl         $t6, $t2, 2
    ctx->r14 = S32(U32(ctx->r10) >> 2);
    // 0x80082D9C: addiu       $t3, $t0, -0x1
    ctx->r11 = ADD32(ctx->r8, -0X1);
    // 0x80082DA0: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80082DA4: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x80082DA8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80082DAC: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x80082DB0: srl         $t6, $t2, 5
    ctx->r14 = S32(U32(ctx->r10) >> 5);
    // 0x80082DB4: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x80082DB8: sltu        $at, $t3, $a2
    ctx->r1 = ctx->r11 < ctx->r6 ? 1 : 0;
    // 0x80082DBC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082DC0: bne         $at, $zero, L_800830E8
    if (ctx->r1 != 0) {
        // 0x80082DC4: addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
            goto L_800830E8;
    }
    // 0x80082DC4: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80082DC8: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x80082DCC: addiu       $t9, $t2, 0x2
    ctx->r25 = ADD32(ctx->r10, 0X2);
    // 0x80082DD0: subu        $t8, $t7, $t0
    ctx->r24 = SUB32(ctx->r15, ctx->r8);
    // 0x80082DD4: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x80082DD8: beq         $at, $zero, L_80082FA8
    if (ctx->r1 == 0) {
        // 0x80082DDC: nop
    
            goto L_80082FA8;
    }
    // 0x80082DDC: nop

    // 0x80082DE0: b           L_800830D8
    // 0x80082DE4: nop

        goto L_800830D8;
    // 0x80082DE4: nop

L_80082DE8:
    // 0x80082DE8: sltiu       $at, $t2, 0x20
    ctx->r1 = ctx->r10 < 0X20 ? 1 : 0;
    // 0x80082DEC: bne         $at, $zero, L_80082E80
    if (ctx->r1 != 0) {
        // 0x80082DF0: nop
    
            goto L_80082E80;
    }
    // 0x80082DF0: nop

    // 0x80082DF4: andi        $t6, $t2, 0x1F
    ctx->r14 = ctx->r10 & 0X1F;
    // 0x80082DF8: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x80082DFC: bne         $t2, $zero, L_80082E5C
    if (ctx->r10 != 0) {
        // 0x80082E00: nop
    
            goto L_80082E5C;
    }
    // 0x80082E00: nop

    // 0x80082E04: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80082E08: nop

    // 0x80082E0C: subu        $t8, $t7, $t1
    ctx->r24 = SUB32(ctx->r15, ctx->r9);
    // 0x80082E10: beq         $t8, $zero, L_800830C8
    if (ctx->r24 == 0) {
        // 0x80082E14: nop
    
            goto L_800830C8;
    }
    // 0x80082E14: nop

    // 0x80082E18: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x80082E1C: nop

    // 0x80082E20: bne         $t9, $zero, L_80082E4C
    if (ctx->r25 != 0) {
        // 0x80082E24: nop
    
            goto L_80082E4C;
    }
    // 0x80082E24: nop

L_80082E28:
    // 0x80082E28: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80082E2C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082E30: subu        $t7, $t6, $t1
    ctx->r15 = SUB32(ctx->r14, ctx->r9);
    // 0x80082E34: beq         $t7, $zero, L_800830C8
    if (ctx->r15 == 0) {
        // 0x80082E38: addiu       $t2, $t2, 0xFF
        ctx->r10 = ADD32(ctx->r10, 0XFF);
            goto L_800830C8;
    }
    // 0x80082E38: addiu       $t2, $t2, 0xFF
    ctx->r10 = ADD32(ctx->r10, 0XFF);
    // 0x80082E3C: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x80082E40: nop

    // 0x80082E44: beq         $t8, $zero, L_80082E28
    if (ctx->r24 == 0) {
        // 0x80082E48: nop
    
            goto L_80082E28;
    }
    // 0x80082E48: nop

L_80082E4C:
    // 0x80082E4C: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x80082E50: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082E54: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80082E58: addiu       $t2, $t2, 0x1F
    ctx->r10 = ADD32(ctx->r10, 0X1F);
L_80082E5C:
    // 0x80082E5C: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x80082E60: lbu         $t8, 0x1($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1);
    // 0x80082E64: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80082E68: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x80082E6C: addiu       $t3, $t0, -0x1
    ctx->r11 = ADD32(ctx->r8, -0X1);
    // 0x80082E70: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80082E74: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x80082E78: b           L_80082F84
    // 0x80082E7C: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
        goto L_80082F84;
    // 0x80082E7C: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
L_80082E80:
    // 0x80082E80: sltiu       $at, $t2, 0x10
    ctx->r1 = ctx->r10 < 0X10 ? 1 : 0;
    // 0x80082E84: bne         $at, $zero, L_80082F28
    if (ctx->r1 != 0) {
        // 0x80082E88: nop
    
            goto L_80082F28;
    }
    // 0x80082E88: nop

    // 0x80082E8C: andi        $t8, $t2, 0x8
    ctx->r24 = ctx->r10 & 0X8;
    // 0x80082E90: andi        $t9, $t2, 0x7
    ctx->r25 = ctx->r10 & 0X7;
    // 0x80082E94: or          $t3, $t0, $zero
    ctx->r11 = ctx->r8 | 0;
    // 0x80082E98: sll         $t7, $t8, 11
    ctx->r15 = S32(ctx->r24 << 11);
    // 0x80082E9C: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x80082EA0: bne         $t2, $zero, L_80082F00
    if (ctx->r10 != 0) {
        // 0x80082EA4: subu        $t3, $t3, $t7
        ctx->r11 = SUB32(ctx->r11, ctx->r15);
            goto L_80082F00;
    }
    // 0x80082EA4: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x80082EA8: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80082EAC: nop

    // 0x80082EB0: subu        $t8, $t6, $t1
    ctx->r24 = SUB32(ctx->r14, ctx->r9);
    // 0x80082EB4: beq         $t8, $zero, L_800830C8
    if (ctx->r24 == 0) {
        // 0x80082EB8: nop
    
            goto L_800830C8;
    }
    // 0x80082EB8: nop

    // 0x80082EBC: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x80082EC0: nop

    // 0x80082EC4: bne         $t7, $zero, L_80082EF0
    if (ctx->r15 != 0) {
        // 0x80082EC8: nop
    
            goto L_80082EF0;
    }
    // 0x80082EC8: nop

L_80082ECC:
    // 0x80082ECC: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x80082ED0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082ED4: subu        $t6, $t9, $t1
    ctx->r14 = SUB32(ctx->r25, ctx->r9);
    // 0x80082ED8: beq         $t6, $zero, L_800830C8
    if (ctx->r14 == 0) {
        // 0x80082EDC: addiu       $t2, $t2, 0xFF
        ctx->r10 = ADD32(ctx->r10, 0XFF);
            goto L_800830C8;
    }
    // 0x80082EDC: addiu       $t2, $t2, 0xFF
    ctx->r10 = ADD32(ctx->r10, 0XFF);
    // 0x80082EE0: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x80082EE4: nop

    // 0x80082EE8: beq         $t8, $zero, L_80082ECC
    if (ctx->r24 == 0) {
        // 0x80082EEC: nop
    
            goto L_80082ECC;
    }
    // 0x80082EEC: nop

L_80082EF0:
    // 0x80082EF0: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x80082EF4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082EF8: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x80082EFC: addiu       $t2, $t2, 0x7
    ctx->r10 = ADD32(ctx->r10, 0X7);
L_80082F00:
    // 0x80082F00: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x80082F04: lbu         $t8, 0x1($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1);
    // 0x80082F08: sra         $t6, $t9, 2
    ctx->r14 = S32(SIGNED(ctx->r25) >> 2);
    // 0x80082F0C: sll         $t7, $t8, 6
    ctx->r15 = S32(ctx->r24 << 6);
    // 0x80082F10: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80082F14: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x80082F18: beq         $t3, $t0, L_8008307C
    if (ctx->r11 == ctx->r8) {
        // 0x80082F1C: addiu       $t1, $t1, 0x2
        ctx->r9 = ADD32(ctx->r9, 0X2);
            goto L_8008307C;
    }
    // 0x80082F1C: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x80082F20: b           L_80082F84
    // 0x80082F24: addiu       $t3, $t3, -0x4000
    ctx->r11 = ADD32(ctx->r11, -0X4000);
        goto L_80082F84;
    // 0x80082F24: addiu       $t3, $t3, -0x4000
    ctx->r11 = ADD32(ctx->r11, -0X4000);
L_80082F28:
    // 0x80082F28: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x80082F2C: addiu       $t3, $t0, -0x1
    ctx->r11 = ADD32(ctx->r8, -0X1);
    // 0x80082F30: srl         $t8, $t2, 2
    ctx->r24 = S32(U32(ctx->r10) >> 2);
    // 0x80082F34: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x80082F38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80082F3C: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x80082F40: sltu        $at, $t3, $a2
    ctx->r1 = ctx->r11 < ctx->r6 ? 1 : 0;
    // 0x80082F44: bne         $at, $zero, L_800830E8
    if (ctx->r1 != 0) {
        // 0x80082F48: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800830E8;
    }
    // 0x80082F48: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80082F4C: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80082F50: nop

    // 0x80082F54: subu        $t8, $t9, $t0
    ctx->r24 = SUB32(ctx->r25, ctx->r8);
    // 0x80082F58: sltiu       $at, $t8, 0x2
    ctx->r1 = ctx->r24 < 0X2 ? 1 : 0;
    // 0x80082F5C: bne         $at, $zero, L_800830D8
    if (ctx->r1 != 0) {
        // 0x80082F60: nop
    
            goto L_800830D8;
    }
    // 0x80082F60: nop

    // 0x80082F64: lbu         $t6, 0x0($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X0);
    // 0x80082F68: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082F6C: sb          $t6, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r14;
    // 0x80082F70: lbu         $t7, 0x1($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X1);
    // 0x80082F74: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082F78: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80082F7C: b           L_80082FE0
    // 0x80082F80: sb          $t7, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r15;
        goto L_80082FE0;
    // 0x80082F80: sb          $t7, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r15;
L_80082F84:
    // 0x80082F84: sltu        $at, $t3, $a2
    ctx->r1 = ctx->r11 < ctx->r6 ? 1 : 0;
    // 0x80082F88: bne         $at, $zero, L_800830E8
    if (ctx->r1 != 0) {
        // 0x80082F8C: nop
    
            goto L_800830E8;
    }
    // 0x80082F8C: nop

    // 0x80082F90: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80082F94: addiu       $t6, $t2, 0x2
    ctx->r14 = ADD32(ctx->r10, 0X2);
    // 0x80082F98: subu        $t8, $t9, $t0
    ctx->r24 = SUB32(ctx->r25, ctx->r8);
    // 0x80082F9C: sltu        $at, $t8, $t6
    ctx->r1 = ctx->r24 < ctx->r14 ? 1 : 0;
    // 0x80082FA0: bne         $at, $zero, L_800830D8
    if (ctx->r1 != 0) {
        // 0x80082FA4: nop
    
            goto L_800830D8;
    }
    // 0x80082FA4: nop

L_80082FA8:
    // 0x80082FA8: lbu         $t7, 0x0($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X0);
    // 0x80082FAC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082FB0: sb          $t7, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r15;
    // 0x80082FB4: lbu         $t9, 0x1($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X1);
    // 0x80082FB8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80082FBC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80082FC0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082FC4: sb          $t9, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r25;
L_80082FC8:
    // 0x80082FC8: lbu         $t8, 0x0($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X0);
    // 0x80082FCC: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80082FD0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082FD4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80082FD8: bne         $t2, $zero, L_80082FC8
    if (ctx->r10 != 0) {
        // 0x80082FDC: sb          $t8, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r24;
            goto L_80082FC8;
    }
    // 0x80082FDC: sb          $t8, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r24;
L_80082FE0:
    // 0x80082FE0: lbu         $t2, -0x2($t1)
    ctx->r10 = MEM_BU(ctx->r9, -0X2);
    // 0x80082FE4: nop

    // 0x80082FE8: andi        $t6, $t2, 0x3
    ctx->r14 = ctx->r10 & 0X3;
    // 0x80082FEC: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x80082FF0: beq         $t2, $zero, L_80083058
    if (ctx->r10 == 0) {
        // 0x80082FF4: nop
    
            goto L_80083058;
    }
    // 0x80082FF4: nop

L_80082FF8:
    // 0x80082FF8: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x80082FFC: nop

    // 0x80083000: subu        $t9, $t7, $t0
    ctx->r25 = SUB32(ctx->r15, ctx->r8);
    // 0x80083004: sltu        $at, $t9, $t2
    ctx->r1 = ctx->r25 < ctx->r10 ? 1 : 0;
    // 0x80083008: bne         $at, $zero, L_800830D8
    if (ctx->r1 != 0) {
        // 0x8008300C: nop
    
            goto L_800830D8;
    }
    // 0x8008300C: nop

    // 0x80083010: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80083014: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x80083018: subu        $t6, $t8, $t1
    ctx->r14 = SUB32(ctx->r24, ctx->r9);
    // 0x8008301C: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x80083020: bne         $at, $zero, L_800830C8
    if (ctx->r1 != 0) {
        // 0x80083024: nop
    
            goto L_800830C8;
    }
    // 0x80083024: nop

L_80083028:
    // 0x80083028: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x8008302C: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80083030: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80083034: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80083038: bne         $t2, $zero, L_80083028
    if (ctx->r10 != 0) {
        // 0x8008303C: sb          $t9, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r25;
            goto L_80083028;
    }
    // 0x8008303C: sb          $t9, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r25;
    // 0x80083040: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80083044: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80083048: lbu         $t2, -0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, -0X1);
    // 0x8008304C: sltu        $at, $t1, $t8
    ctx->r1 = ctx->r9 < ctx->r24 ? 1 : 0;
    // 0x80083050: bne         $at, $zero, L_80082D88
    if (ctx->r1 != 0) {
        // 0x80083054: nop
    
            goto L_80082D88;
    }
    // 0x80083054: nop

L_80083058:
    // 0x80083058: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8008305C: nop

    // 0x80083060: sltu        $at, $t1, $t6
    ctx->r1 = ctx->r9 < ctx->r14 ? 1 : 0;
    // 0x80083064: bne         $at, $zero, L_80082C1C
    if (ctx->r1 != 0) {
        // 0x80083068: nop
    
            goto L_80082C1C;
    }
    // 0x80083068: nop

L_8008306C:
    // 0x8008306C: subu        $t7, $t0, $a2
    ctx->r15 = SUB32(ctx->r8, ctx->r6);
    // 0x80083070: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80083074: b           L_800830F4
    // 0x80083078: addiu       $v0, $zero, -0x7
    ctx->r2 = ADD32(0, -0X7);
        goto L_800830F4;
    // 0x80083078: addiu       $v0, $zero, -0x7
    ctx->r2 = ADD32(0, -0X7);
L_8008307C:
    // 0x8008307C: subu        $t9, $t0, $a2
    ctx->r25 = SUB32(ctx->r8, ctx->r6);
    // 0x80083080: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80083084: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80083088: nop

    // 0x8008308C: bne         $t1, $t8, L_8008309C
    if (ctx->r9 != ctx->r24) {
        // 0x80083090: nop
    
            goto L_8008309C;
    }
    // 0x80083090: nop

    // 0x80083094: b           L_800830C0
    // 0x80083098: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
        goto L_800830C0;
    // 0x80083098: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8008309C:
    // 0x8008309C: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800830A0: nop

    // 0x800830A4: sltu        $at, $t1, $t6
    ctx->r1 = ctx->r9 < ctx->r14 ? 1 : 0;
    // 0x800830A8: beq         $at, $zero, L_800830B8
    if (ctx->r1 == 0) {
        // 0x800830AC: nop
    
            goto L_800830B8;
    }
    // 0x800830AC: nop

    // 0x800830B0: b           L_800830BC
    // 0x800830B4: addiu       $t5, $zero, -0x8
    ctx->r13 = ADD32(0, -0X8);
        goto L_800830BC;
    // 0x800830B4: addiu       $t5, $zero, -0x8
    ctx->r13 = ADD32(0, -0X8);
L_800830B8:
    // 0x800830B8: addiu       $t5, $zero, -0x4
    ctx->r13 = ADD32(0, -0X4);
L_800830BC:
    // 0x800830BC: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
L_800830C0:
    // 0x800830C0: b           L_800830F4
    // 0x800830C4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_800830F4;
    // 0x800830C4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_800830C8:
    // 0x800830C8: subu        $t7, $t0, $a2
    ctx->r15 = SUB32(ctx->r8, ctx->r6);
    // 0x800830CC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800830D0: b           L_800830F4
    // 0x800830D4: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
        goto L_800830F4;
    // 0x800830D4: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
L_800830D8:
    // 0x800830D8: subu        $t9, $t0, $a2
    ctx->r25 = SUB32(ctx->r8, ctx->r6);
    // 0x800830DC: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800830E0: b           L_800830F4
    // 0x800830E4: addiu       $v0, $zero, -0x5
    ctx->r2 = ADD32(0, -0X5);
        goto L_800830F4;
    // 0x800830E4: addiu       $v0, $zero, -0x5
    ctx->r2 = ADD32(0, -0X5);
L_800830E8:
    // 0x800830E8: subu        $t8, $t0, $a2
    ctx->r24 = SUB32(ctx->r8, ctx->r6);
    // 0x800830EC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800830F0: addiu       $v0, $zero, -0x6
    ctx->r2 = ADD32(0, -0X6);
L_800830F4:
    // 0x800830F4: jr          $ra
    // 0x800830F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800830F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800830FC: nop

;}

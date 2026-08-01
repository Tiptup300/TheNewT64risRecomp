#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void wonders3_UpdateBlockState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046400: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80046404: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80046408: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8004640C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80046410: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80046414: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x80046418: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8004641C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80046420: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80046424: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80046428: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8004642C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80046430: lbu         $t9, 0x2($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X2);
    // 0x80046434: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x80046438: lw          $s0, -0x10AC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X10AC);
    // 0x8004643C: beq         $t9, $zero, L_800464C8
    if (ctx->r25 == 0) {
        // 0x80046440: nop
    
            goto L_800464C8;
    }
    // 0x80046440: nop

    // 0x80046444: andi        $t0, $s0, 0x8000
    ctx->r8 = ctx->r16 & 0X8000;
    // 0x80046448: beq         $t0, $zero, L_800464C8
    if (ctx->r8 == 0) {
        // 0x8004644C: nop
    
            goto L_800464C8;
    }
    // 0x8004644C: nop

    // 0x80046450: lb          $t1, 0x3($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X3);
    // 0x80046454: nop

    // 0x80046458: slti        $at, $t1, 0x7
    ctx->r1 = SIGNED(ctx->r9) < 0X7 ? 1 : 0;
    // 0x8004645C: beq         $at, $zero, L_800464B8
    if (ctx->r1 == 0) {
        // 0x80046460: nop
    
            goto L_800464B8;
    }
    // 0x80046460: nop

    // 0x80046464: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80046468: lb          $t2, -0x7C8($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X7C8);
    // 0x8004646C: nop

    // 0x80046470: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80046474: bne         $at, $zero, L_800464B8
    if (ctx->r1 != 0) {
        // 0x80046478: nop
    
            goto L_800464B8;
    }
    // 0x80046478: nop

    // 0x8004647C: bne         $t1, $t2, L_800464C8
    if (ctx->r9 != ctx->r10) {
        // 0x80046480: nop
    
            goto L_800464C8;
    }
    // 0x80046480: nop

    // 0x80046484: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80046488: lb          $t3, -0x7D0($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X7D0);
    // 0x8004648C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046490: beq         $t3, $at, L_800464C8
    if (ctx->r11 == ctx->r1) {
        // 0x80046494: nop
    
            goto L_800464C8;
    }
    // 0x80046494: nop

    // 0x80046498: jal         0x80046218
    // 0x8004649C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_0;
    // 0x8004649C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_0:
    // 0x800464A0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800464A4: nop

    // 0x800464A8: lb          $t5, 0x3($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X3);
    // 0x800464AC: nop

    // 0x800464B0: bne         $v0, $t5, L_800464C8
    if (ctx->r2 != ctx->r13) {
        // 0x800464B4: nop
    
            goto L_800464C8;
    }
    // 0x800464B4: nop

L_800464B8:
    // 0x800464B8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800464BC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800464C0: b           L_80046600
    // 0x800464C4: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
        goto L_80046600;
    // 0x800464C4: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_800464C8:
    // 0x800464C8: andi        $t9, $s0, 0x4000
    ctx->r25 = ctx->r16 & 0X4000;
    // 0x800464CC: beq         $t9, $zero, L_800464E4
    if (ctx->r25 == 0) {
        // 0x800464D0: nop
    
            goto L_800464E4;
    }
    // 0x800464D0: nop

    // 0x800464D4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800464D8: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800464DC: b           L_80046600
    // 0x800464E0: sb          $t0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r8;
        goto L_80046600;
    // 0x800464E0: sb          $t0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r8;
L_800464E4:
    // 0x800464E4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800464E8: nop

    // 0x800464EC: lbu         $t2, 0x2($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2);
    // 0x800464F0: nop

    // 0x800464F4: beq         $t2, $zero, L_80046564
    if (ctx->r10 == 0) {
        // 0x800464F8: nop
    
            goto L_80046564;
    }
    // 0x800464F8: nop

    // 0x800464FC: andi        $t3, $s0, 0x200
    ctx->r11 = ctx->r16 & 0X200;
    // 0x80046500: beq         $t3, $zero, L_80046564
    if (ctx->r11 == 0) {
        // 0x80046504: nop
    
            goto L_80046564;
    }
    // 0x80046504: nop

    // 0x80046508: lb          $t4, 0x3($t1)
    ctx->r12 = MEM_B(ctx->r9, 0X3);
    // 0x8004650C: nop

    // 0x80046510: beq         $t4, $zero, L_80046524
    if (ctx->r12 == 0) {
        // 0x80046514: nop
    
            goto L_80046524;
    }
    // 0x80046514: nop

    // 0x80046518: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8004651C: b           L_80046554
    // 0x80046520: sb          $t5, 0x4($t1)
    MEM_B(0X4, ctx->r9) = ctx->r13;
        goto L_80046554;
    // 0x80046520: sb          $t5, 0x4($t1)
    MEM_B(0X4, ctx->r9) = ctx->r13;
L_80046524:
    // 0x80046524: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80046528: lbu         $t7, -0x7C0($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X7C0);
    // 0x8004652C: nop

    // 0x80046530: beq         $t7, $zero, L_80046548
    if (ctx->r15 == 0) {
        // 0x80046534: nop
    
            goto L_80046548;
    }
    // 0x80046534: nop

    // 0x80046538: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8004653C: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80046540: b           L_80046554
    // 0x80046544: sb          $t8, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r24;
        goto L_80046554;
    // 0x80046544: sb          $t8, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r24;
L_80046548:
    // 0x80046548: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8004654C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80046550: sb          $t0, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r8;
L_80046554:
    // 0x80046554: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80046558: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8004655C: b           L_80046600
    // 0x80046560: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
        goto L_80046600;
    // 0x80046560: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
L_80046564:
    // 0x80046564: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80046568: nop

    // 0x8004656C: lbu         $t5, 0x2($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X2);
    // 0x80046570: nop

    // 0x80046574: beq         $t5, $zero, L_80046600
    if (ctx->r13 == 0) {
        // 0x80046578: nop
    
            goto L_80046600;
    }
    // 0x80046578: nop

    // 0x8004657C: andi        $t1, $s0, 0x100
    ctx->r9 = ctx->r16 & 0X100;
    // 0x80046580: beq         $t1, $zero, L_80046600
    if (ctx->r9 == 0) {
        // 0x80046584: nop
    
            goto L_80046600;
    }
    // 0x80046584: nop

    // 0x80046588: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8004658C: lbu         $t7, -0x7C0($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X7C0);
    // 0x80046590: nop

    // 0x80046594: beq         $t7, $zero, L_800465B0
    if (ctx->r15 == 0) {
        // 0x80046598: nop
    
            goto L_800465B0;
    }
    // 0x80046598: nop

    // 0x8004659C: lb          $t8, 0x3($t4)
    ctx->r24 = MEM_B(ctx->r12, 0X3);
    // 0x800465A0: nop

    // 0x800465A4: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x800465A8: bne         $at, $zero, L_800465CC
    if (ctx->r1 != 0) {
        // 0x800465AC: nop
    
            goto L_800465CC;
    }
    // 0x800465AC: nop

L_800465B0:
    // 0x800465B0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800465B4: nop

    // 0x800465B8: lb          $t0, 0x3($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X3);
    // 0x800465BC: nop

    // 0x800465C0: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x800465C4: beq         $at, $zero, L_800465E8
    if (ctx->r1 == 0) {
        // 0x800465C8: nop
    
            goto L_800465E8;
    }
    // 0x800465C8: nop

L_800465CC:
    // 0x800465CC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800465D0: nop

    // 0x800465D4: lb          $t2, 0x3($t6)
    ctx->r10 = MEM_B(ctx->r14, 0X3);
    // 0x800465D8: nop

    // 0x800465DC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800465E0: b           L_800465F4
    // 0x800465E4: sb          $t3, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r11;
        goto L_800465F4;
    // 0x800465E4: sb          $t3, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r11;
L_800465E8:
    // 0x800465E8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800465EC: nop

    // 0x800465F0: sb          $zero, 0x4($t5)
    MEM_B(0X4, ctx->r13) = 0;
L_800465F4:
    // 0x800465F4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800465F8: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x800465FC: sb          $t1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r9;
L_80046600:
    // 0x80046600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80046604: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80046608: jr          $ra
    // 0x8004660C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004660C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders3_CreateBlockTile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80046618: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8004661C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046620: beq         $t6, $zero, L_80046788
    if (ctx->r14 == 0) {
        // 0x80046624: nop
    
            goto L_80046788;
    }
    // 0x80046624: nop

    // 0x80046628: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8004662C: nop

    // 0x80046630: lb          $t8, 0x3($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X3);
    // 0x80046634: nop

    // 0x80046638: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x8004663C: bne         $at, $zero, L_80046658
    if (ctx->r1 != 0) {
        // 0x80046640: nop
    
            goto L_80046658;
    }
    // 0x80046640: nop

    // 0x80046644: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80046648: addiu       $t9, $t9, -0x4D0
    ctx->r25 = ADD32(ctx->r25, -0X4D0);
    // 0x8004664C: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x80046650: b           L_80046714
    // 0x80046654: sw          $t0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r8;
        goto L_80046714;
    // 0x80046654: sw          $t0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r8;
L_80046658:
    // 0x80046658: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8004665C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80046660: lb          $t3, -0x7C8($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X7C8);
    // 0x80046664: lb          $t2, 0x3($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X3);
    // 0x80046668: nop

    // 0x8004666C: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80046670: beq         $at, $zero, L_80046690
    if (ctx->r1 == 0) {
        // 0x80046674: nop
    
            goto L_80046690;
    }
    // 0x80046674: nop

    // 0x80046678: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8004667C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80046680: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80046684: lw          $t5, -0x4D0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4D0);
    // 0x80046688: b           L_80046714
    // 0x8004668C: sw          $t5, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r13;
        goto L_80046714;
    // 0x8004668C: sw          $t5, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r13;
L_80046690:
    // 0x80046690: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80046694: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80046698: lb          $t9, -0x7C8($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X7C8);
    // 0x8004669C: lb          $t8, 0x3($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X3);
    // 0x800466A0: nop

    // 0x800466A4: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800466A8: beq         $at, $zero, L_800466C4
    if (ctx->r1 == 0) {
        // 0x800466AC: nop
    
            goto L_800466C4;
    }
    // 0x800466AC: nop

    // 0x800466B0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800466B4: addiu       $t0, $t0, -0x4D0
    ctx->r8 = ADD32(ctx->r8, -0X4D0);
    // 0x800466B8: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x800466BC: b           L_80046714
    // 0x800466C0: sw          $t7, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r15;
        goto L_80046714;
    // 0x800466C0: sw          $t7, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r15;
L_800466C4:
    // 0x800466C4: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800466C8: lb          $t3, -0x7D0($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X7D0);
    // 0x800466CC: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800466D0: bne         $t3, $at, L_800466FC
    if (ctx->r11 != ctx->r1) {
        // 0x800466D4: nop
    
            goto L_800466FC;
    }
    // 0x800466D4: nop

    // 0x800466D8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800466DC: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800466E0: lb          $t4, 0x3($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X3);
    // 0x800466E4: nop

    // 0x800466E8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800466EC: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x800466F0: lw          $t1, -0x4D0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4D0);
    // 0x800466F4: b           L_80046714
    // 0x800466F8: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
        goto L_80046714;
    // 0x800466F8: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
L_800466FC:
    // 0x800466FC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80046700: addiu       $t8, $t8, -0x4D0
    ctx->r24 = ADD32(ctx->r24, -0X4D0);
    // 0x80046704: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x80046708: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8004670C: nop

    // 0x80046710: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
L_80046714:
    // 0x80046714: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80046718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004671C: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x80046720: jal         0x80076EC0
    // 0x80046724: nop

    CubeTiles_ObjCreate(rdram, ctx);
        goto after_0;
    // 0x80046724: nop

    after_0:
    // 0x80046728: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8004672C: nop

    // 0x80046730: lw          $t3, 0x8($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X8);
    // 0x80046734: nop

    // 0x80046738: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8004673C: jal         0x800A4654
    // 0x80046740: nop

    wonders1_ObjClearFlag80(rdram, ctx);
        goto after_1;
    // 0x80046740: nop

    after_1:
    // 0x80046744: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80046748: nop

    // 0x8004674C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80046750: nop

    // 0x80046754: lw          $t1, 0x0($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X0);
    // 0x80046758: nop

    // 0x8004675C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80046760: nop

    // 0x80046764: sw          $zero, 0x30($t2)
    MEM_W(0X30, ctx->r10) = 0;
    // 0x80046768: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8004676C: nop

    // 0x80046770: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x80046774: jal         0x800773A4
    // 0x80046778: nop

    CubeTiles_ObjSetAnimating(rdram, ctx);
        goto after_2;
    // 0x80046778: nop

    after_2:
    // 0x8004677C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80046780: nop

    // 0x80046784: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
L_80046788:
    // 0x80046788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004678C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046790: jr          $ra
    // 0x80046794: nop

    return;
    // 0x80046794: nop

;}

RECOMP_FUNC void wonders3_FreeBlockTile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004679C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800467A0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800467A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800467A8: beq         $t6, $zero, L_800467E8
    if (ctx->r14 == 0) {
        // 0x800467AC: nop
    
            goto L_800467E8;
    }
    // 0x800467AC: nop

    // 0x800467B0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800467B4: nop

    // 0x800467B8: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800467BC: nop

    // 0x800467C0: beq         $t8, $zero, L_800467E8
    if (ctx->r24 == 0) {
        // 0x800467C4: nop
    
            goto L_800467E8;
    }
    // 0x800467C4: nop

    // 0x800467C8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800467CC: nop

    // 0x800467D0: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x800467D4: jal         0x80077028
    // 0x800467D8: nop

    CubeTiles_ObjFree(rdram, ctx);
        goto after_0;
    // 0x800467D8: nop

    after_0:
    // 0x800467DC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800467E0: nop

    // 0x800467E4: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
L_800467E8:
    // 0x800467E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800467EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800467F0: jr          $ra
    // 0x800467F4: nop

    return;
    // 0x800467F4: nop

;}

RECOMP_FUNC void wonders3_ReloadBlockTile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800467F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800467FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80046800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046804: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80046808: jal         0x80046798
    // 0x8004680C: nop

    wonders3_FreeBlockTile(rdram, ctx);
        goto after_0;
    // 0x8004680C: nop

    after_0:
    // 0x80046810: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80046814: nop

    // 0x80046818: lb          $t7, 0x4($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X4);
    // 0x8004681C: nop

    // 0x80046820: sb          $t7, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r15;
    // 0x80046824: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80046828: jal         0x80046610
    // 0x8004682C: nop

    wonders3_CreateBlockTile(rdram, ctx);
        goto after_1;
    // 0x8004682C: nop

    after_1:
    // 0x80046830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046838: jr          $ra
    // 0x8004683C: nop

    return;
    // 0x8004683C: nop

;}

RECOMP_FUNC void wonders3_LoadResources(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046840: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80046844: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80046848: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004684C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80046850: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80046854: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80046858: jal         0x80077408
    // 0x8004685C: addiu       $a0, $a0, 0xE8
    ctx->r4 = ADD32(ctx->r4, 0XE8);
    Font_Init46Char(rdram, ctx);
        goto after_0;
    // 0x8004685C: addiu       $a0, $a0, 0xE8
    ctx->r4 = ADD32(ctx->r4, 0XE8);
    after_0:
    // 0x80046860: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80046864: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80046868: jal         0x80077408
    // 0x8004686C: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    Font_Init46Char(rdram, ctx);
        goto after_1;
    // 0x8004686C: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    after_1:
    // 0x80046870: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80046874: addiu       $a1, $zero, 0x9A
    ctx->r5 = ADD32(0, 0X9A);
    // 0x80046878: addiu       $a2, $zero, 0x9B
    ctx->r6 = ADD32(0, 0X9B);
    // 0x8004687C: jal         0x800571D4
    // 0x80046880: addiu       $a0, $a0, 0xD4
    ctx->r4 = ADD32(ctx->r4, 0XD4);
    Sprite_LoadImagePair(rdram, ctx);
        goto after_2;
    // 0x80046880: addiu       $a0, $a0, 0xD4
    ctx->r4 = ADD32(ctx->r4, 0XD4);
    after_2:
    // 0x80046884: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80046888: nop

    // 0x8004688C: lbu         $t7, 0x2($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2);
    // 0x80046890: nop

    // 0x80046894: beq         $t7, $zero, L_800468C0
    if (ctx->r15 == 0) {
        // 0x80046898: nop
    
            goto L_800468C0;
    }
    // 0x80046898: nop

    // 0x8004689C: addiu       $a0, $t6, 0xC
    ctx->r4 = ADD32(ctx->r14, 0XC);
    // 0x800468A0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x800468A4: jal         0x800571D4
    // 0x800468A8: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    Sprite_LoadImagePair(rdram, ctx);
        goto after_3;
    // 0x800468A8: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    after_3:
    // 0x800468AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800468B0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800468B4: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x800468B8: jal         0x800571D4
    // 0x800468BC: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    Sprite_LoadImagePair(rdram, ctx);
        goto after_4;
    // 0x800468BC: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_4:
L_800468C0:
    // 0x800468C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800468C4: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    // 0x800468C8: addiu       $a2, $zero, 0x85
    ctx->r6 = ADD32(0, 0X85);
    // 0x800468CC: jal         0x800571D4
    // 0x800468D0: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    Sprite_LoadImagePair(rdram, ctx);
        goto after_5;
    // 0x800468D0: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_5:
    // 0x800468D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800468D8: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    // 0x800468DC: addiu       $a2, $zero, 0x87
    ctx->r6 = ADD32(0, 0X87);
    // 0x800468E0: jal         0x800571D4
    // 0x800468E4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    Sprite_LoadImagePair(rdram, ctx);
        goto after_6;
    // 0x800468E4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_6:
    // 0x800468E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800468EC: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x800468F0: addiu       $a2, $zero, 0x89
    ctx->r6 = ADD32(0, 0X89);
    // 0x800468F4: jal         0x800571D4
    // 0x800468F8: addiu       $a0, $a0, 0x5C
    ctx->r4 = ADD32(ctx->r4, 0X5C);
    Sprite_LoadImagePair(rdram, ctx);
        goto after_7;
    // 0x800468F8: addiu       $a0, $a0, 0x5C
    ctx->r4 = ADD32(ctx->r4, 0X5C);
    after_7:
    // 0x800468FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80046900: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    // 0x80046904: addiu       $a2, $zero, 0x8B
    ctx->r6 = ADD32(0, 0X8B);
    // 0x80046908: jal         0x800571D4
    // 0x8004690C: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    Sprite_LoadImagePair(rdram, ctx);
        goto after_8;
    // 0x8004690C: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_8:
    // 0x80046910: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80046914: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80046918: addiu       $a2, $zero, 0x8D
    ctx->r6 = ADD32(0, 0X8D);
    // 0x8004691C: jal         0x800571D4
    // 0x80046920: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    Sprite_LoadImagePair(rdram, ctx);
        goto after_9;
    // 0x80046920: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    after_9:
    // 0x80046924: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80046928: addiu       $a1, $zero, 0x8E
    ctx->r5 = ADD32(0, 0X8E);
    // 0x8004692C: addiu       $a2, $zero, 0x8F
    ctx->r6 = ADD32(0, 0X8F);
    // 0x80046930: jal         0x800571D4
    // 0x80046934: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    Sprite_LoadImagePair(rdram, ctx);
        goto after_10;
    // 0x80046934: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_10:
    // 0x80046938: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004693C: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    // 0x80046940: addiu       $a2, $zero, 0x91
    ctx->r6 = ADD32(0, 0X91);
    // 0x80046944: jal         0x800571D4
    // 0x80046948: addiu       $a0, $a0, 0xAC
    ctx->r4 = ADD32(ctx->r4, 0XAC);
    Sprite_LoadImagePair(rdram, ctx);
        goto after_11;
    // 0x80046948: addiu       $a0, $a0, 0xAC
    ctx->r4 = ADD32(ctx->r4, 0XAC);
    after_11:
    // 0x8004694C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80046950: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    // 0x80046954: addiu       $a2, $zero, 0x93
    ctx->r6 = ADD32(0, 0X93);
    // 0x80046958: jal         0x800571D4
    // 0x8004695C: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    Sprite_LoadImagePair(rdram, ctx);
        goto after_12;
    // 0x8004695C: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    after_12:
    // 0x80046960: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80046964: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80046968: sh          $t8, 0xDC($t9)
    MEM_H(0XDC, ctx->r25) = ctx->r24;
    // 0x8004696C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80046970: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x80046974: sh          $t0, 0xDE($t1)
    MEM_H(0XDE, ctx->r9) = ctx->r8;
    // 0x80046978: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8004697C: nop

    // 0x80046980: lbu         $t3, 0x2($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X2);
    // 0x80046984: nop

    // 0x80046988: beq         $t3, $zero, L_800469BC
    if (ctx->r11 == 0) {
        // 0x8004698C: nop
    
            goto L_800469BC;
    }
    // 0x8004698C: nop

    // 0x80046990: addiu       $t4, $zero, 0x37
    ctx->r12 = ADD32(0, 0X37);
    // 0x80046994: sh          $t4, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r12;
    // 0x80046998: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8004699C: addiu       $t5, $zero, 0x41
    ctx->r13 = ADD32(0, 0X41);
    // 0x800469A0: sh          $t5, 0x16($t7)
    MEM_H(0X16, ctx->r15) = ctx->r13;
    // 0x800469A4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800469A8: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x800469AC: sh          $t6, 0x28($t8)
    MEM_H(0X28, ctx->r24) = ctx->r14;
    // 0x800469B0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800469B4: addiu       $t9, $zero, 0x41
    ctx->r25 = ADD32(0, 0X41);
    // 0x800469B8: sh          $t9, 0x2A($t0)
    MEM_H(0X2A, ctx->r8) = ctx->r25;
L_800469BC:
    // 0x800469BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800469C0: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x800469C4: beq         $at, $zero, L_80046A18
    if (ctx->r1 == 0) {
        // 0x800469C8: nop
    
            goto L_80046A18;
    }
    // 0x800469C8: nop

L_800469CC:
    // 0x800469CC: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800469D0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800469D4: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x800469D8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800469DC: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x800469E0: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x800469E4: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x800469E8: addu        $t2, $t3, $t4
    ctx->r10 = ADD32(ctx->r11, ctx->r12);
    // 0x800469EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800469F0: sh          $t1, 0x3C($t2)
    MEM_H(0X3C, ctx->r10) = ctx->r9;
    // 0x800469F4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800469F8: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x800469FC: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80046A00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80046A04: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x80046A08: addiu       $t5, $zero, 0x96
    ctx->r13 = ADD32(0, 0X96);
    // 0x80046A0C: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80046A10: bne         $at, $zero, L_800469CC
    if (ctx->r1 != 0) {
        // 0x80046A14: sh          $t5, 0x3E($t8)
        MEM_H(0X3E, ctx->r24) = ctx->r13;
            goto L_800469CC;
    }
    // 0x80046A14: sh          $t5, 0x3E($t8)
    MEM_H(0X3E, ctx->r24) = ctx->r13;
L_80046A18:
    // 0x80046A18: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80046A1C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80046A20: sb          $t0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r8;
    // 0x80046A24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80046A28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80046A2C: jr          $ra
    // 0x80046A30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80046A30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders3_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046A34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80046A38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80046A3C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80046A40: lw          $s0, -0x4A4($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4A4);
    // 0x80046A44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80046A48: beq         $s0, $zero, L_80046B18
    if (ctx->r16 == 0) {
        // 0x80046A4C: nop
    
            goto L_80046B18;
    }
    // 0x80046A4C: nop

    // 0x80046A50: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80046A54: nop

    // 0x80046A58: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80046A5C: beq         $at, $zero, L_80046B18
    if (ctx->r1 == 0) {
        // 0x80046A60: nop
    
            goto L_80046B18;
    }
    // 0x80046A60: nop

    // 0x80046A64: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80046A68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80046A6C: addu        $at, $at, $t6
    gpr jr_addend_80046A78 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80046A70: lw          $t6, -0x4990($at)
    ctx->r14 = ADD32(ctx->r1, -0X4990);
    // 0x80046A74: nop

    // 0x80046A78: jr          $t6
    // 0x80046A7C: nop

    switch (jr_addend_80046A78 >> 2) {
        case 0: goto L_80046A80; break;
        case 1: goto L_80046A90; break;
        case 2: goto L_80046AD4; break;
        case 3: goto L_80046AE0; break;
        case 4: goto L_80046AF0; break;
        case 5: goto L_80046B00; break;
        case 6: goto L_80046B10; break;
        case 7: goto L_80046B10; break;
        default: switch_error(__func__, 0x80046A78, 0x800DB670);
    }
    // 0x80046A7C: nop

L_80046A80:
    // 0x80046A80: jal         0x80046400
    // 0x80046A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders3_UpdateBlockState(rdram, ctx);
        goto after_0;
    // 0x80046A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80046A88: b           L_80046B18
    // 0x80046A8C: nop

        goto L_80046B18;
    // 0x80046A8C: nop

L_80046A90:
    // 0x80046A90: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80046A94: lw          $t7, -0x6E1C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6E1C);
    // 0x80046A98: nop

    // 0x80046A9C: beq         $t7, $zero, L_80046B18
    if (ctx->r15 == 0) {
        // 0x80046AA0: nop
    
            goto L_80046B18;
    }
    // 0x80046AA0: nop

    // 0x80046AA4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80046AA8: lw          $a0, -0x6E24($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6E24);
    // 0x80046AAC: jal         0x8007E328
    // 0x80046AB0: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x80046AB0: nop

    after_1:
    // 0x80046AB4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80046AB8: jal         0x8009F338
    // 0x80046ABC: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    Scene_FreeObjectBuffers(rdram, ctx);
        goto after_2;
    // 0x80046ABC: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    after_2:
    // 0x80046AC0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80046AC4: jal         0x8004A34C
    // 0x80046AC8: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_3;
    // 0x80046AC8: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    after_3:
    // 0x80046ACC: b           L_80046B18
    // 0x80046AD0: nop

        goto L_80046B18;
    // 0x80046AD0: nop

L_80046AD4:
    // 0x80046AD4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80046AD8: b           L_80046B18
    // 0x80046ADC: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
        goto L_80046B18;
    // 0x80046ADC: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_80046AE0:
    // 0x80046AE0: jal         0x80046840
    // 0x80046AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders3_LoadResources(rdram, ctx);
        goto after_4;
    // 0x80046AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80046AE8: b           L_80046B18
    // 0x80046AEC: nop

        goto L_80046B18;
    // 0x80046AEC: nop

L_80046AF0:
    // 0x80046AF0: jal         0x80046610
    // 0x80046AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders3_CreateBlockTile(rdram, ctx);
        goto after_5;
    // 0x80046AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80046AF8: b           L_80046B18
    // 0x80046AFC: nop

        goto L_80046B18;
    // 0x80046AFC: nop

L_80046B00:
    // 0x80046B00: jal         0x800467F8
    // 0x80046B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders3_ReloadBlockTile(rdram, ctx);
        goto after_6;
    // 0x80046B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80046B08: b           L_80046B18
    // 0x80046B0C: nop

        goto L_80046B18;
    // 0x80046B0C: nop

L_80046B10:
    // 0x80046B10: jal         0x8004745C
    // 0x80046B14: nop

    wonders3_Deinit(rdram, ctx);
        goto after_7;
    // 0x80046B14: nop

    after_7:
L_80046B18:
    // 0x80046B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80046B1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80046B20: jr          $ra
    // 0x80046B24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80046B24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders3_RenderWondersHallText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046B28: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80046B2C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80046B30: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80046B34: lw          $s0, -0x4A4($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4A4);
    // 0x80046B38: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80046B3C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x80046B40: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80046B44: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80046B48: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80046B4C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80046B50: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80046B54: beq         $s0, $zero, L_80046FE8
    if (ctx->r16 == 0) {
        // 0x80046B58: sw          $s1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r17;
            goto L_80046FE8;
    }
    // 0x80046B58: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80046B5C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80046B60: jal         0x8005BBFC
    // 0x80046B64: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_0;
    // 0x80046B64: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_0:
    // 0x80046B68: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80046B6C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80046B70: lw          $a2, 0x1F84($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1F84);
    // 0x80046B74: lw          $a1, 0x1F80($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1F80);
    // 0x80046B78: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80046B7C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80046B80: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80046B84: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80046B88: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80046B8C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80046B90: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80046B94: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80046B98: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80046B9C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80046BA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80046BA4: jal         0x80057460
    // 0x80046BA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_1;
    // 0x80046BA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80046BAC: jal         0x80057338
    // 0x80046BB0: addiu       $a0, $s0, 0xD4
    ctx->r4 = ADD32(ctx->r16, 0XD4);
    Sprite_DrawScaled(rdram, ctx);
        goto after_2;
    // 0x80046BB0: addiu       $a0, $s0, 0xD4
    ctx->r4 = ADD32(ctx->r16, 0XD4);
    after_2:
    // 0x80046BB4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80046BB8: lb          $t1, -0x7C8($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X7C8);
    // 0x80046BBC: lb          $t0, 0x3($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X3);
    // 0x80046BC0: nop

    // 0x80046BC4: bne         $t0, $t1, L_80046BEC
    if (ctx->r8 != ctx->r9) {
        // 0x80046BC8: nop
    
            goto L_80046BEC;
    }
    // 0x80046BC8: nop

    // 0x80046BCC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80046BD0: lb          $a0, -0x7D0($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X7D0);
    // 0x80046BD4: jal         0x80046218
    // 0x80046BD8: nop

    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_3;
    // 0x80046BD8: nop

    after_3:
    // 0x80046BDC: lb          $t2, 0x3($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X3);
    // 0x80046BE0: nop

    // 0x80046BE4: beq         $v0, $t2, L_80046C08
    if (ctx->r2 == ctx->r10) {
        // 0x80046BE8: nop
    
            goto L_80046C08;
    }
    // 0x80046BE8: nop

L_80046BEC:
    // 0x80046BEC: lb          $a0, 0x3($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X3);
    // 0x80046BF0: jal         0x8004624C
    // 0x80046BF4: nop

    wonders2_WonderIndexToLastColumn(rdram, ctx);
        goto after_4;
    // 0x80046BF4: nop

    after_4:
    // 0x80046BF8: sll         $s1, $v0, 24
    ctx->r17 = S32(ctx->r2 << 24);
    // 0x80046BFC: sra         $t3, $s1, 24
    ctx->r11 = S32(SIGNED(ctx->r17) >> 24);
    // 0x80046C00: b           L_80046C14
    // 0x80046C04: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
        goto L_80046C14;
    // 0x80046C04: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
L_80046C08:
    // 0x80046C08: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80046C0C: lb          $s1, -0x7D0($s1)
    ctx->r17 = MEM_B(ctx->r17, -0X7D0);
    // 0x80046C10: nop

L_80046C14:
    // 0x80046C14: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80046C18: lb          $t4, -0x7D0($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X7D0);
    // 0x80046C1C: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80046C20: beq         $t4, $at, L_80046C98
    if (ctx->r12 == ctx->r1) {
        // 0x80046C24: slti        $at, $s1, 0x31
        ctx->r1 = SIGNED(ctx->r17) < 0X31 ? 1 : 0;
            goto L_80046C98;
    }
    // 0x80046C24: slti        $at, $s1, 0x31
    ctx->r1 = SIGNED(ctx->r17) < 0X31 ? 1 : 0;
    // 0x80046C28: beq         $at, $zero, L_80046C98
    if (ctx->r1 == 0) {
        // 0x80046C2C: nop
    
            goto L_80046C98;
    }
    // 0x80046C2C: nop

    // 0x80046C30: jal         0x80046218
    // 0x80046C34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_5;
    // 0x80046C34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80046C38: sll         $s7, $v0, 24
    ctx->r23 = S32(ctx->r2 << 24);
    // 0x80046C3C: sra         $t5, $s7, 24
    ctx->r13 = S32(SIGNED(ctx->r23) >> 24);
    // 0x80046C40: or          $s7, $t5, $zero
    ctx->r23 = ctx->r13 | 0;
    // 0x80046C44: jal         0x80046388
    // 0x80046C48: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    wonders2_GetLinesRemainingToWonder(rdram, ctx);
        goto after_6;
    // 0x80046C48: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_6:
    // 0x80046C4C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80046C50: lb          $t6, -0x7D0($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X7D0);
    // 0x80046C54: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80046C58: slt         $at, $t6, $s1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80046C5C: bne         $at, $zero, L_80046C90
    if (ctx->r1 != 0) {
        // 0x80046C60: nop
    
            goto L_80046C90;
    }
    // 0x80046C60: nop

    // 0x80046C64: jal         0x80046218
    // 0x80046C68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    wonders2_ColumnToWonderIndex(rdram, ctx);
        goto after_7;
    // 0x80046C68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80046C6C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80046C70: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80046C74: subu        $s2, $s1, $t7
    ctx->r18 = SUB32(ctx->r17, ctx->r15);
    // 0x80046C78: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80046C7C: sll         $t8, $s2, 24
    ctx->r24 = S32(ctx->r18 << 24);
    // 0x80046C80: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x80046C84: sra         $t9, $s2, 24
    ctx->r25 = S32(SIGNED(ctx->r18) >> 24);
    // 0x80046C88: b           L_80046CA0
    // 0x80046C8C: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
        goto L_80046CA0;
    // 0x80046C8C: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_80046C90:
    // 0x80046C90: b           L_80046CA0
    // 0x80046C94: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80046CA0;
    // 0x80046C94: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80046C98:
    // 0x80046C98: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80046C9C: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
L_80046CA0:
    // 0x80046CA0: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x80046CA4: addu        $t0, $t0, $s2
    ctx->r8 = ADD32(ctx->r8, ctx->r18);
    // 0x80046CA8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80046CAC: addu        $a0, $s0, $t0
    ctx->r4 = ADD32(ctx->r16, ctx->r8);
    // 0x80046CB0: jal         0x80057338
    // 0x80046CB4: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    Sprite_DrawScaled(rdram, ctx);
        goto after_8;
    // 0x80046CB4: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_8:
    // 0x80046CB8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80046CBC: addiu       $a1, $a1, -0x49E0
    ctx->r5 = ADD32(ctx->r5, -0X49E0);
    // 0x80046CC0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80046CC4: jal         0x800B62D4
    // 0x80046CC8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_9;
    // 0x80046CC8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_9:
    // 0x80046CCC: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x80046CD0: jal         0x80077D88
    // 0x80046CD4: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    Font_GetTextWidth(rdram, ctx);
        goto after_10;
    // 0x80046CD4: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_10:
    // 0x80046CD8: bgez        $v0, L_80046CE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80046CDC: sra         $t1, $v0, 1
        ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80046CE8;
    }
    // 0x80046CDC: sra         $t1, $v0, 1
    ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80046CE0: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80046CE4: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80046CE8:
    // 0x80046CE8: addiu       $t2, $zero, 0x46
    ctx->r10 = ADD32(0, 0X46);
    // 0x80046CEC: subu        $s4, $t2, $t1
    ctx->r20 = SUB32(ctx->r10, ctx->r9);
    // 0x80046CF0: andi        $t3, $s4, 0xFFFF
    ctx->r11 = ctx->r20 & 0XFFFF;
    // 0x80046CF4: or          $s4, $t3, $zero
    ctx->r20 = ctx->r11 | 0;
    // 0x80046CF8: addiu       $s5, $zero, 0xB4
    ctx->r21 = ADD32(0, 0XB4);
    // 0x80046CFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80046D00: addiu       $t4, $sp, 0x58
    ctx->r12 = ADD32(ctx->r29, 0X58);
    // 0x80046D04: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80046D08: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80046D0C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80046D10: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80046D14: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80046D18: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80046D1C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80046D20: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80046D24: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80046D28: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80046D2C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80046D30: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80046D34: jal         0x80077960
    // 0x80046D38: addiu       $a1, $s0, 0xE8
    ctx->r5 = ADD32(ctx->r16, 0XE8);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_11;
    // 0x80046D38: addiu       $a1, $s0, 0xE8
    ctx->r5 = ADD32(ctx->r16, 0XE8);
    after_11:
    // 0x80046D3C: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    // 0x80046D40: nop

    // 0x80046D44: beq         $t9, $zero, L_80046D5C
    if (ctx->r25 == 0) {
        // 0x80046D48: nop
    
            goto L_80046D5C;
    }
    // 0x80046D48: nop

    // 0x80046D4C: jal         0x80057338
    // 0x80046D50: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    Sprite_DrawScaled(rdram, ctx);
        goto after_12;
    // 0x80046D50: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_12:
    // 0x80046D54: jal         0x80057338
    // 0x80046D58: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    Sprite_DrawScaled(rdram, ctx);
        goto after_13;
    // 0x80046D58: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    after_13:
L_80046D5C:
    // 0x80046D5C: lb          $t0, 0x3($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X3);
    // 0x80046D60: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80046D64: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80046D68: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x80046D6C: lw          $a2, -0x7BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7BC);
    // 0x80046D70: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80046D74: addiu       $a1, $a1, -0x49DC
    ctx->r5 = ADD32(ctx->r5, -0X49DC);
    // 0x80046D78: jal         0x800B62D4
    // 0x80046D7C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_14;
    // 0x80046D7C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_14:
    // 0x80046D80: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x80046D84: jal         0x80077D88
    // 0x80046D88: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    Font_GetTextWidth(rdram, ctx);
        goto after_15;
    // 0x80046D88: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_15:
    // 0x80046D8C: bgez        $v0, L_80046D9C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80046D90: sra         $t1, $v0, 1
        ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80046D9C;
    }
    // 0x80046D90: sra         $t1, $v0, 1
    ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80046D94: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80046D98: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80046D9C:
    // 0x80046D9C: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x80046DA0: subu        $s4, $t3, $t1
    ctx->r20 = SUB32(ctx->r11, ctx->r9);
    // 0x80046DA4: andi        $t4, $s4, 0xFFFF
    ctx->r12 = ctx->r20 & 0XFFFF;
    // 0x80046DA8: or          $s4, $t4, $zero
    ctx->r20 = ctx->r12 | 0;
    // 0x80046DAC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80046DB0: addiu       $t5, $sp, 0x58
    ctx->r13 = ADD32(ctx->r29, 0X58);
    // 0x80046DB4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80046DB8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80046DBC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80046DC0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80046DC4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80046DC8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80046DCC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80046DD0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80046DD4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80046DD8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80046DDC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80046DE0: addiu       $a1, $s0, 0xE8
    ctx->r5 = ADD32(ctx->r16, 0XE8);
    // 0x80046DE4: jal         0x80077960
    // 0x80046DE8: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_16;
    // 0x80046DE8: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    after_16:
    // 0x80046DEC: lbu         $t0, 0x2($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X2);
    // 0x80046DF0: lhu         $s6, 0x15C($s0)
    ctx->r22 = MEM_HU(ctx->r16, 0X15C);
    // 0x80046DF4: addiu       $s4, $zero, 0x82
    ctx->r20 = ADD32(0, 0X82);
    // 0x80046DF8: beq         $t0, $zero, L_80046EEC
    if (ctx->r8 == 0) {
        // 0x80046DFC: addiu       $s5, $zero, 0x10E
        ctx->r21 = ADD32(0, 0X10E);
            goto L_80046EEC;
    }
    // 0x80046DFC: addiu       $s5, $zero, 0x10E
    ctx->r21 = ADD32(0, 0X10E);
    // 0x80046E00: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80046E04: addiu       $a1, $a1, -0x49D8
    ctx->r5 = ADD32(ctx->r5, -0X49D8);
    // 0x80046E08: jal         0x800B62D4
    // 0x80046E0C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_17;
    // 0x80046E0C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_17:
    // 0x80046E10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80046E14: addiu       $t2, $sp, 0x58
    ctx->r10 = ADD32(ctx->r29, 0X58);
    // 0x80046E18: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x80046E1C: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x80046E20: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80046E24: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80046E28: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80046E2C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80046E30: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80046E34: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80046E38: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80046E3C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80046E40: addiu       $a1, $s0, 0xE8
    ctx->r5 = ADD32(ctx->r16, 0XE8);
    // 0x80046E44: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80046E48: jal         0x80077960
    // 0x80046E4C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_18;
    // 0x80046E4C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_18:
    // 0x80046E50: addu        $s4, $s4, $s6
    ctx->r20 = ADD32(ctx->r20, ctx->r22);
    // 0x80046E54: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80046E58: andi        $t6, $s4, 0xFFFF
    ctx->r14 = ctx->r20 & 0XFFFF;
    // 0x80046E5C: andi        $t7, $s5, 0xFFFF
    ctx->r15 = ctx->r21 & 0XFFFF;
    // 0x80046E60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80046E64: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x80046E68: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
    // 0x80046E6C: addiu       $a1, $a1, -0x49D4
    ctx->r5 = ADD32(ctx->r5, -0X49D4);
    // 0x80046E70: jal         0x800B62D4
    // 0x80046E74: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_19;
    // 0x80046E74: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_19:
    // 0x80046E78: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80046E7C: addiu       $t8, $sp, 0x58
    ctx->r24 = ADD32(ctx->r29, 0X58);
    // 0x80046E80: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80046E84: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80046E88: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80046E8C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80046E90: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80046E94: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80046E98: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80046E9C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80046EA0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80046EA4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80046EA8: addiu       $a1, $s0, 0x160
    ctx->r5 = ADD32(ctx->r16, 0X160);
    // 0x80046EAC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80046EB0: jal         0x80077960
    // 0x80046EB4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_20;
    // 0x80046EB4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_20:
    // 0x80046EB8: addiu       $a0, $s0, 0x160
    ctx->r4 = ADD32(ctx->r16, 0X160);
    // 0x80046EBC: jal         0x80077D88
    // 0x80046EC0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    Font_GetTextWidth(rdram, ctx);
        goto after_21;
    // 0x80046EC0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_21:
    // 0x80046EC4: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80046EC8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80046ECC: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80046ED0: addu        $t4, $s6, $t1
    ctx->r12 = ADD32(ctx->r22, ctx->r9);
    // 0x80046ED4: addu        $s4, $s4, $t4
    ctx->r20 = ADD32(ctx->r20, ctx->r12);
    // 0x80046ED8: andi        $t5, $s4, 0xFFFF
    ctx->r13 = ctx->r20 & 0XFFFF;
    // 0x80046EDC: andi        $t6, $s5, 0xFFFF
    ctx->r14 = ctx->r21 & 0XFFFF;
    // 0x80046EE0: or          $s4, $t5, $zero
    ctx->r20 = ctx->r13 | 0;
    // 0x80046EE4: b           L_80046F24
    // 0x80046EE8: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
        goto L_80046F24;
    // 0x80046EE8: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
L_80046EEC:
    // 0x80046EEC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80046EF0: addiu       $a1, $a1, -0x49CC
    ctx->r5 = ADD32(ctx->r5, -0X49CC);
    // 0x80046EF4: jal         0x800B62D4
    // 0x80046EF8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_22;
    // 0x80046EF8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_22:
    // 0x80046EFC: addiu       $a0, $s0, 0x160
    ctx->r4 = ADD32(ctx->r16, 0X160);
    // 0x80046F00: jal         0x80077D88
    // 0x80046F04: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    Font_GetTextWidth(rdram, ctx);
        goto after_23;
    // 0x80046F04: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_23:
    // 0x80046F08: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80046F0C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80046F10: sll         $t7, $s6, 1
    ctx->r15 = S32(ctx->r22 << 1);
    // 0x80046F14: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80046F18: addu        $s4, $s4, $t9
    ctx->r20 = ADD32(ctx->r20, ctx->r25);
    // 0x80046F1C: andi        $t0, $s4, 0xFFFF
    ctx->r8 = ctx->r20 & 0XFFFF;
    // 0x80046F20: or          $s4, $t0, $zero
    ctx->r20 = ctx->r8 | 0;
L_80046F24:
    // 0x80046F24: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80046F28: addiu       $a1, $a1, -0x49C4
    ctx->r5 = ADD32(ctx->r5, -0X49C4);
    // 0x80046F2C: jal         0x800B62D4
    // 0x80046F30: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_24;
    // 0x80046F30: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_24:
    // 0x80046F34: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80046F38: addiu       $t2, $sp, 0x58
    ctx->r10 = ADD32(ctx->r29, 0X58);
    // 0x80046F3C: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x80046F40: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80046F44: addiu       $t4, $zero, 0x7F
    ctx->r12 = ADD32(0, 0X7F);
    // 0x80046F48: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80046F4C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80046F50: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80046F54: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80046F58: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80046F5C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80046F60: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80046F64: addiu       $a1, $s0, 0xE8
    ctx->r5 = ADD32(ctx->r16, 0XE8);
    // 0x80046F68: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80046F6C: jal         0x80077960
    // 0x80046F70: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_25;
    // 0x80046F70: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_25:
    // 0x80046F74: addu        $s4, $s4, $s6
    ctx->r20 = ADD32(ctx->r20, ctx->r22);
    // 0x80046F78: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80046F7C: andi        $t6, $s4, 0xFFFF
    ctx->r14 = ctx->r20 & 0XFFFF;
    // 0x80046F80: andi        $t7, $s5, 0xFFFF
    ctx->r15 = ctx->r21 & 0XFFFF;
    // 0x80046F84: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80046F88: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x80046F8C: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
    // 0x80046F90: addiu       $a1, $a1, -0x49C0
    ctx->r5 = ADD32(ctx->r5, -0X49C0);
    // 0x80046F94: jal         0x800B62D4
    // 0x80046F98: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_26;
    // 0x80046F98: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_26:
    // 0x80046F9C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80046FA0: addiu       $t8, $sp, 0x58
    ctx->r24 = ADD32(ctx->r29, 0X58);
    // 0x80046FA4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80046FA8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80046FAC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80046FB0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80046FB4: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80046FB8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80046FBC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80046FC0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80046FC4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80046FC8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80046FCC: addiu       $a1, $s0, 0x160
    ctx->r5 = ADD32(ctx->r16, 0X160);
    // 0x80046FD0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80046FD4: jal         0x80077960
    // 0x80046FD8: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_27;
    // 0x80046FD8: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_27:
    // 0x80046FDC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80046FE0: jal         0x8005BE40
    // 0x80046FE4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_28;
    // 0x80046FE4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_28:
L_80046FE8:
    // 0x80046FE8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80046FEC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80046FF0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80046FF4: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80046FF8: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80046FFC: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80047000: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80047004: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80047008: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x8004700C: jr          $ra
    // 0x80047010: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80047010: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}

RECOMP_FUNC void wonders3_RenderWondersHall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047014: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80047018: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004701C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80047020: lw          $s0, -0x4A4($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4A4);
    // 0x80047024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80047028: beq         $s0, $zero, L_80047054
    if (ctx->r16 == 0) {
        // 0x8004702C: nop
    
            goto L_80047054;
    }
    // 0x8004702C: nop

    // 0x80047030: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80047034: nop

    // 0x80047038: beq         $t6, $zero, L_80047054
    if (ctx->r14 == 0) {
        // 0x8004703C: nop
    
            goto L_80047054;
    }
    // 0x8004703C: nop

    // 0x80047040: jal         0x80046B28
    // 0x80047044: nop

    wonders3_RenderWondersHallText(rdram, ctx);
        goto after_0;
    // 0x80047044: nop

    after_0:
    // 0x80047048: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8004704C: jal         0x80077098
    // 0x80047050: nop

    CubeTiles_ObjDraw(rdram, ctx);
        goto after_1;
    // 0x80047050: nop

    after_1:
L_80047054:
    // 0x80047054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80047058: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004705C: jr          $ra
    // 0x80047060: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80047060: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void wonders3_DrawWonderViewer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047064: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80047068: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8004706C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80047070: lw          $s0, -0x4A4($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4A4);
    // 0x80047074: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80047078: beq         $s0, $zero, L_800471E8
    if (ctx->r16 == 0) {
        // 0x8004707C: nop
    
            goto L_800471E8;
    }
    // 0x8004707C: nop

    // 0x80047080: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80047084: jal         0x800A0228
    // 0x80047088: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    Scene_SetupCameraAndObjects(rdram, ctx);
        goto after_0;
    // 0x80047088: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    after_0:
    // 0x8004708C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047090: jal         0x8005BBFC
    // 0x80047094: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_1;
    // 0x80047094: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_1:
    // 0x80047098: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8004709C: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x800470A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800470A4: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800470A8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800470AC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800470B0: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x800470B4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800470B8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800470BC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800470C0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800470C4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800470C8: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x800470CC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800470D0: lw          $t3, -0x2B0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2B0);
    // 0x800470D4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800470D8: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x800470DC: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800470E0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800470E4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800470E8: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x800470EC: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x800470F0: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800470F4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800470F8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800470FC: lw          $t8, -0x6E24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6E24);
    // 0x80047100: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80047104: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80047108: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x8004710C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80047110: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047114: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80047118: lw          $a2, 0x1F84($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1F84);
    // 0x8004711C: lw          $a1, 0x1F80($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1F80);
    // 0x80047120: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80047124: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80047128: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8004712C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80047130: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047134: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80047138: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8004713C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80047140: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80047144: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80047148: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8004714C: jal         0x80057460
    // 0x80047150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_2;
    // 0x80047150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80047154: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80047158: lw          $t5, 0x20C0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20C0);
    // 0x8004715C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80047160: lw          $t7, -0x2B0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B0);
    // 0x80047164: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047168: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8004716C: sw          $t6, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r14;
    // 0x80047170: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80047174: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80047178: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8004717C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80047180: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x80047184: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x80047188: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8004718C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80047190: lhu         $t2, 0x20B0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X20B0);
    // 0x80047194: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80047198: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8004719C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800471A0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800471A4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800471A8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800471AC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800471B0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800471B4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800471B8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800471BC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800471C0: sll         $t3, $t3, 7
    ctx->r11 = S32(ctx->r11 << 7);
    // 0x800471C4: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x800471C8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800471CC: addiu       $t5, $t5, -0x5300
    ctx->r13 = ADD32(ctx->r13, -0X5300);
    // 0x800471D0: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x800471D4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800471D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800471DC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800471E0: jal         0x8005BE40
    // 0x800471E4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_3;
    // 0x800471E4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    after_3:
L_800471E8:
    // 0x800471E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800471EC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800471F0: jr          $ra
    // 0x800471F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800471F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void wonders3_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800471F8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800471FC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80047200: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80047204: lw          $s0, -0x4A4($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4A4);
    // 0x80047208: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8004720C: beq         $s0, $zero, L_800472E0
    if (ctx->r16 == 0) {
        // 0x80047210: nop
    
            goto L_800472E0;
    }
    // 0x80047210: nop

    // 0x80047214: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80047218: nop

    // 0x8004721C: bne         $t6, $zero, L_80047234
    if (ctx->r14 != 0) {
        // 0x80047220: nop
    
            goto L_80047234;
    }
    // 0x80047220: nop

    // 0x80047224: jal         0x80047014
    // 0x80047228: nop

    wonders3_RenderWondersHall(rdram, ctx);
        goto after_0;
    // 0x80047228: nop

    after_0:
    // 0x8004722C: b           L_800472E0
    // 0x80047230: nop

        goto L_800472E0;
    // 0x80047230: nop

L_80047234:
    // 0x80047234: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80047238: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004723C: bne         $t7, $at, L_80047254
    if (ctx->r15 != ctx->r1) {
        // 0x80047240: nop
    
            goto L_80047254;
    }
    // 0x80047240: nop

    // 0x80047244: jal         0x80047064
    // 0x80047248: nop

    wonders3_DrawWonderViewer(rdram, ctx);
        goto after_1;
    // 0x80047248: nop

    after_1:
    // 0x8004724C: b           L_800472E0
    // 0x80047250: nop

        goto L_800472E0;
    // 0x80047250: nop

L_80047254:
    // 0x80047254: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x80047258: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004725C: beq         $t8, $at, L_80047274
    if (ctx->r24 == ctx->r1) {
        // 0x80047260: nop
    
            goto L_80047274;
    }
    // 0x80047260: nop

    // 0x80047264: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x80047268: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004726C: bne         $t9, $at, L_800472D8
    if (ctx->r25 != ctx->r1) {
        // 0x80047270: nop
    
            goto L_800472D8;
    }
    // 0x80047270: nop

L_80047274:
    // 0x80047274: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047278: jal         0x8005BBFC
    // 0x8004727C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_2;
    // 0x8004727C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_2:
    // 0x80047280: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047284: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80047288: lw          $a2, 0x1F84($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1F84);
    // 0x8004728C: lw          $a1, 0x1F80($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1F80);
    // 0x80047290: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047294: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80047298: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8004729C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800472A0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800472A4: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800472A8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800472AC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800472B0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800472B4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800472B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800472BC: jal         0x80057460
    // 0x800472C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_3;
    // 0x800472C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x800472C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800472C8: jal         0x8005BE40
    // 0x800472CC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_4;
    // 0x800472CC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_4:
    // 0x800472D0: b           L_800472E0
    // 0x800472D4: nop

        goto L_800472E0;
    // 0x800472D4: nop

L_800472D8:
    // 0x800472D8: jal         0x80046B28
    // 0x800472DC: nop

    wonders3_RenderWondersHallText(rdram, ctx);
        goto after_5;
    // 0x800472DC: nop

    after_5:
L_800472E0:
    // 0x800472E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800472E4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800472E8: jr          $ra
    // 0x800472EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800472EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void wonders3_LoadWonderViewer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800472F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800472F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800472F8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800472FC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80047300: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80047304: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80047308: jal         0x8004A34C
    // 0x8004730C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x8004730C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80047310: jal         0x8007E03C
    // 0x80047314: addiu       $a0, $zero, 0x1D8
    ctx->r4 = ADD32(0, 0X1D8);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80047314: addiu       $a0, $zero, 0x1D8
    ctx->r4 = ADD32(0, 0X1D8);
    after_1:
    // 0x80047318: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004731C: sw          $v0, -0x4A4($at)
    MEM_W(-0X4A4, ctx->r1) = ctx->r2;
    // 0x80047320: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80047324: lw          $s0, -0x4A4($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4A4);
    // 0x80047328: nop

    // 0x8004732C: bne         $s0, $zero, L_80047348
    if (ctx->r16 != 0) {
        // 0x80047330: nop
    
            goto L_80047348;
    }
    // 0x80047330: nop

    // 0x80047334: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047338: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004733C: addiu       $a1, $a1, -0x49A4
    ctx->r5 = ADD32(ctx->r5, -0X49A4);
    // 0x80047340: jal         0x80083560
    // 0x80047344: addiu       $a0, $a0, -0x49B8
    ctx->r4 = ADD32(ctx->r4, -0X49B8);
    debug_print_reason_routine(rdram, ctx);
        goto after_2;
    // 0x80047344: addiu       $a0, $a0, -0x49B8
    ctx->r4 = ADD32(ctx->r4, -0X49B8);
    after_2:
L_80047348:
    // 0x80047348: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x8004734C: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // 0x80047350: sb          $t6, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r14;
    // 0x80047354: lb          $t7, 0x33($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X33);
    // 0x80047358: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8004735C: ori         $a0, $a0, 0xA988
    ctx->r4 = ctx->r4 | 0XA988;
    // 0x80047360: jal         0x8007E03C
    // 0x80047364: sb          $t7, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r15;
    n64HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x80047364: sb          $t7, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r15;
    after_3:
    // 0x80047368: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004736C: sw          $v0, -0x6E24($at)
    MEM_W(-0X6E24, ctx->r1) = ctx->r2;
    // 0x80047370: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80047374: lw          $a0, -0x6E24($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6E24);
    // 0x80047378: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8004737C: ori         $a1, $a1, 0xD4C0
    ctx->r5 = ctx->r5 | 0XD4C0;
    // 0x80047380: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80047384: jal         0x800A8FC8
    // 0x80047388: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    CubeTiles_FillHalfwords(rdram, ctx);
        goto after_4;
    // 0x80047388: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x8004738C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80047390: lw          $t8, -0x6E24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6E24);
    // 0x80047394: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80047398: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    // 0x8004739C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800473A0: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x800473A4: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    // 0x800473A8: jal         0x8008F280
    // 0x800473AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    Scene_LoadObjectSprite(rdram, ctx);
        goto after_5;
    // 0x800473AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_5:
    // 0x800473B0: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x800473B4: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x800473B8: jal         0x80074888
    // 0x800473BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_6;
    // 0x800473BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x800473C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800473C4: jal         0x8007E03C
    // 0x800473C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x800473C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x800473CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800473D0: sw          $v0, 0x1F80($at)
    MEM_W(0X1F80, ctx->r1) = ctx->r2;
    // 0x800473D4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800473D8: lw          $a1, 0x1F80($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1F80);
    // 0x800473DC: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x800473E0: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x800473E4: jal         0x800746C0
    // 0x800473E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_8;
    // 0x800473E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x800473EC: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x800473F0: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x800473F4: jal         0x80074888
    // 0x800473F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_9;
    // 0x800473F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x800473FC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80047400: jal         0x8007E03C
    // 0x80047404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_10;
    // 0x80047404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80047408: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004740C: sw          $v0, 0x1F84($at)
    MEM_W(0X1F84, ctx->r1) = ctx->r2;
    // 0x80047410: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047414: lw          $a1, 0x1F84($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1F84);
    // 0x80047418: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8004741C: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x80047420: jal         0x800746C0
    // 0x80047424: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_11;
    // 0x80047424: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_11:
    // 0x80047428: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004742C: jal         0x8009FA2C
    // 0x80047430: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    Scene_PlaceObjects(rdram, ctx);
        goto after_12;
    // 0x80047430: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    after_12:
    // 0x80047434: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80047438: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x8004743C: lbu         $t0, 0x37($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X37);
    // 0x80047440: nop

    // 0x80047444: sb          $t0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r8;
    // 0x80047448: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004744C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80047450: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80047454: jr          $ra
    // 0x80047458: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80047458: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void wonders3_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004745C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80047460: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80047464: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80047468: lw          $s0, -0x4A4($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4A4);
    // 0x8004746C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80047470: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80047474: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80047478: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004747C: jal         0x80046798
    // 0x80047480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wonders3_FreeBlockTile(rdram, ctx);
        goto after_0;
    // 0x80047480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80047484: jal         0x800773D0
    // 0x80047488: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    Font_Deinit(rdram, ctx);
        goto after_1;
    // 0x80047488: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    after_1:
    // 0x8004748C: jal         0x800773D0
    // 0x80047490: addiu       $a0, $s0, 0x160
    ctx->r4 = ADD32(ctx->r16, 0X160);
    Font_Deinit(rdram, ctx);
        goto after_2;
    // 0x80047490: addiu       $a0, $s0, 0x160
    ctx->r4 = ADD32(ctx->r16, 0X160);
    after_2:
    // 0x80047494: jal         0x800572F8
    // 0x80047498: addiu       $a0, $s0, 0xD4
    ctx->r4 = ADD32(ctx->r16, 0XD4);
    Sprite_FreeImagePair(rdram, ctx);
        goto after_3;
    // 0x80047498: addiu       $a0, $s0, 0xD4
    ctx->r4 = ADD32(ctx->r16, 0XD4);
    after_3:
    // 0x8004749C: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x800474A0: nop

    // 0x800474A4: beq         $t6, $zero, L_800474BC
    if (ctx->r14 == 0) {
        // 0x800474A8: nop
    
            goto L_800474BC;
    }
    // 0x800474A8: nop

    // 0x800474AC: jal         0x800572F8
    // 0x800474B0: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    Sprite_FreeImagePair(rdram, ctx);
        goto after_4;
    // 0x800474B0: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_4:
    // 0x800474B4: jal         0x800572F8
    // 0x800474B8: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    Sprite_FreeImagePair(rdram, ctx);
        goto after_5;
    // 0x800474B8: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    after_5:
L_800474BC:
    // 0x800474BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800474C0: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x800474C4: beq         $at, $zero, L_800474FC
    if (ctx->r1 == 0) {
        // 0x800474C8: nop
    
            goto L_800474FC;
    }
    // 0x800474C8: nop

L_800474CC:
    // 0x800474CC: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800474D0: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800474D4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800474D8: addu        $a0, $s0, $t7
    ctx->r4 = ADD32(ctx->r16, ctx->r15);
    // 0x800474DC: jal         0x800572F8
    // 0x800474E0: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    Sprite_FreeImagePair(rdram, ctx);
        goto after_6;
    // 0x800474E0: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_6:
    // 0x800474E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800474E8: andi        $t8, $s1, 0xFF
    ctx->r24 = ctx->r17 & 0XFF;
    // 0x800474EC: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x800474F0: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x800474F4: bne         $at, $zero, L_800474CC
    if (ctx->r1 != 0) {
        // 0x800474F8: nop
    
            goto L_800474CC;
    }
    // 0x800474F8: nop

L_800474FC:
    // 0x800474FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047500: lw          $a0, 0x1F80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F80);
    // 0x80047504: jal         0x8007E328
    // 0x80047508: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_7;
    // 0x80047508: nop

    after_7:
    // 0x8004750C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047510: lw          $a0, 0x1F84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F84);
    // 0x80047514: jal         0x8007E328
    // 0x80047518: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_8;
    // 0x80047518: nop

    after_8:
    // 0x8004751C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80047520: lbu         $s1, 0x3($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X3);
    // 0x80047524: lbu         $s2, 0x0($s0)
    ctx->r18 = MEM_BU(ctx->r16, 0X0);
    // 0x80047528: lw          $a0, -0x4A4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4A4);
    // 0x8004752C: jal         0x8007E328
    // 0x80047530: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_9;
    // 0x80047530: nop

    after_9:
    // 0x80047534: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047538: jal         0x8004A34C
    // 0x8004753C: sw          $zero, -0x4A4($at)
    MEM_W(-0X4A4, ctx->r1) = 0;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_10;
    // 0x8004753C: sw          $zero, -0x4A4($at)
    MEM_W(-0X4A4, ctx->r1) = 0;
    after_10:
    // 0x80047540: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047544: sb          $zero, 0x3CF0($at)
    MEM_B(0X3CF0, ctx->r1) = 0;
    // 0x80047548: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004754C: bne         $s2, $at, L_800475DC
    if (ctx->r18 != ctx->r1) {
        // 0x80047550: nop
    
            goto L_800475DC;
    }
    // 0x80047550: nop

    // 0x80047554: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80047558: lb          $t9, -0x7C8($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X7C8);
    // 0x8004755C: nop

    // 0x80047560: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80047564: beq         $at, $zero, L_80047590
    if (ctx->r1 == 0) {
        // 0x80047568: nop
    
            goto L_80047590;
    }
    // 0x80047568: nop

    // 0x8004756C: jal         0x8004624C
    // 0x80047570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    wonders2_WonderIndexToLastColumn(rdram, ctx);
        goto after_11;
    // 0x80047570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80047574: sll         $s3, $v0, 24
    ctx->r19 = S32(ctx->r2 << 24);
    // 0x80047578: sra         $t0, $s3, 24
    ctx->r8 = S32(SIGNED(ctx->r19) >> 24);
    // 0x8004757C: or          $s3, $t0, $zero
    ctx->r19 = ctx->r8 | 0;
    // 0x80047580: jal         0x80045BDC
    // 0x80047584: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    wonders1_Init(rdram, ctx);
        goto after_12;
    // 0x80047584: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x80047588: b           L_800475CC
    // 0x8004758C: nop

        goto L_800475CC;
    // 0x8004758C: nop

L_80047590:
    // 0x80047590: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80047594: lb          $t1, -0x7C8($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X7C8);
    // 0x80047598: nop

    // 0x8004759C: bne         $s1, $t1, L_800475CC
    if (ctx->r17 != ctx->r9) {
        // 0x800475A0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_800475CC;
    }
    // 0x800475A0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800475A4: bne         $s1, $at, L_800475BC
    if (ctx->r17 != ctx->r1) {
        // 0x800475A8: nop
    
            goto L_800475BC;
    }
    // 0x800475A8: nop

    // 0x800475AC: jal         0x80045BDC
    // 0x800475B0: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    wonders1_Init(rdram, ctx);
        goto after_13;
    // 0x800475B0: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    after_13:
    // 0x800475B4: b           L_800475CC
    // 0x800475B8: nop

        goto L_800475CC;
    // 0x800475B8: nop

L_800475BC:
    // 0x800475BC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800475C0: lb          $a0, -0x7D0($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X7D0);
    // 0x800475C4: jal         0x80045BDC
    // 0x800475C8: nop

    wonders1_Init(rdram, ctx);
        goto after_14;
    // 0x800475C8: nop

    after_14:
L_800475CC:
    // 0x800475CC: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x800475D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800475D4: b           L_800476D4
    // 0x800475D8: sb          $t2, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r10;
        goto L_800476D4;
    // 0x800475D8: sb          $t2, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r10;
L_800475DC:
    // 0x800475DC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800475E0: lbu         $t3, 0x9F0($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X9F0);
    // 0x800475E4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800475E8: bne         $t3, $at, L_80047620
    if (ctx->r11 != ctx->r1) {
        // 0x800475EC: nop
    
            goto L_80047620;
    }
    // 0x800475EC: nop

    // 0x800475F0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800475F4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800475F8: addiu       $a1, $a1, 0x5808
    ctx->r5 = ADD32(ctx->r5, 0X5808);
    // 0x800475FC: jal         0x8009035C
    // 0x80047600: addiu       $a0, $a0, 0x5850
    ctx->r4 = ADD32(ctx->r4, 0X5850);
    Scene_LoadScreen(rdram, ctx);
        goto after_15;
    // 0x80047600: addiu       $a0, $a0, 0x5850
    ctx->r4 = ADD32(ctx->r4, 0X5850);
    after_15:
    // 0x80047604: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80047608: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004760C: sb          $t4, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r12;
    // 0x80047610: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047614: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80047618: b           L_800476D4
    // 0x8004761C: sb          $t5, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r13;
        goto L_800476D4;
    // 0x8004761C: sb          $t5, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r13;
L_80047620:
    // 0x80047620: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80047624: lbu         $t6, 0x9F0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X9F0);
    // 0x80047628: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004762C: bne         $t6, $at, L_80047664
    if (ctx->r14 != ctx->r1) {
        // 0x80047630: nop
    
            goto L_80047664;
    }
    // 0x80047630: nop

    // 0x80047634: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80047638: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004763C: addiu       $a1, $a1, 0x5CE8
    ctx->r5 = ADD32(ctx->r5, 0X5CE8);
    // 0x80047640: jal         0x8009035C
    // 0x80047644: addiu       $a0, $a0, 0x5D48
    ctx->r4 = ADD32(ctx->r4, 0X5D48);
    Scene_LoadScreen(rdram, ctx);
        goto after_16;
    // 0x80047644: addiu       $a0, $a0, 0x5D48
    ctx->r4 = ADD32(ctx->r4, 0X5D48);
    after_16:
    // 0x80047648: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8004764C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047650: sb          $t7, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r15;
    // 0x80047654: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047658: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004765C: b           L_800476D4
    // 0x80047660: sb          $t8, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r24;
        goto L_800476D4;
    // 0x80047660: sb          $t8, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r24;
L_80047664:
    // 0x80047664: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80047668: lbu         $t9, 0x9F0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X9F0);
    // 0x8004766C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80047670: bne         $t9, $at, L_8004769C
    if (ctx->r25 != ctx->r1) {
        // 0x80047674: nop
    
            goto L_8004769C;
    }
    // 0x80047674: nop

    // 0x80047678: jal         0x800905E8
    // 0x8004767C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Scene_LoadResources(rdram, ctx);
        goto after_17;
    // 0x8004767C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x80047680: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80047684: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047688: sb          $t0, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r8;
    // 0x8004768C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047690: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80047694: b           L_800476D4
    // 0x80047698: sb          $t1, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r9;
        goto L_800476D4;
    // 0x80047698: sb          $t1, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r9;
L_8004769C:
    // 0x8004769C: jal         0x80084F80
    // 0x800476A0: nop

    Audio_UnloadSFX(rdram, ctx);
        goto after_18;
    // 0x800476A0: nop

    after_18:
    // 0x800476A4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800476A8: jal         0x80051618
    // 0x800476AC: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    Game_StartRound(rdram, ctx);
        goto after_19;
    // 0x800476AC: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    after_19:
    // 0x800476B0: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x800476B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800476B8: sb          $t2, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r10;
    // 0x800476BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800476C0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800476C4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800476C8: sb          $t3, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r11;
    // 0x800476CC: jal         0x80085030
    // 0x800476D0: addiu       $a0, $a0, 0x3A90
    ctx->r4 = ADD32(ctx->r4, 0X3A90);
    Audio_LoadSFX(rdram, ctx);
        goto after_20;
    // 0x800476D0: addiu       $a0, $a0, 0x3A90
    ctx->r4 = ADD32(ctx->r4, 0X3A90);
    after_20:
L_800476D4:
    // 0x800476D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800476D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800476DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800476E0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800476E4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800476E8: jr          $ra
    // 0x800476EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800476EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

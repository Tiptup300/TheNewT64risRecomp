#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void BoardP_GetCellColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D3C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006D3C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006D3C8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006D3CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006D3D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006D3D4: lbu         $a0, 0x3($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X3);
    // 0x8006D3D8: jal         0x8006AB84
    // 0x8006D3DC: nop

    Multisquare_IsValidIndex(rdram, ctx);
        goto after_0;
    // 0x8006D3DC: nop

    after_0:
    // 0x8006D3E0: bne         $v0, $zero, L_8006D414
    if (ctx->r2 != 0) {
        // 0x8006D3E4: nop
    
            goto L_8006D414;
    }
    // 0x8006D3E4: nop

    // 0x8006D3E8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8006D3EC: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006D3F0: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x8006D3F4: nop

    // 0x8006D3F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006D3FC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8006D400: lw          $t0, 0x110($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X110);
    // 0x8006D404: nop

    // 0x8006D408: lw          $v0, 0x18($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X18);
    // 0x8006D40C: b           L_8006D440
    // 0x8006D410: nop

        goto L_8006D440;
    // 0x8006D410: nop

L_8006D414:
    // 0x8006D414: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8006D418: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006D41C: lbu         $t3, 0x3($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3);
    // 0x8006D420: lw          $t1, -0x460($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X460);
    // 0x8006D424: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8006D428: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006D42C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8006D430: addu        $s0, $t1, $t4
    ctx->r16 = ADD32(ctx->r9, ctx->r12);
    // 0x8006D434: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8006D438: jal         0x8006A47C
    // 0x8006D43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Multisquare_pGetColor(rdram, ctx);
        goto after_1;
    // 0x8006D43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_8006D440:
    // 0x8006D440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D444: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006D448: jr          $ra
    // 0x8006D44C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006D44C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void BoardP_MergeGroups(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D450: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006D454: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006D458: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006D45C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006D460: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8006D464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006D468: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006D46C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006D470: lbu         $s1, 0x2($t6)
    ctx->r17 = MEM_BU(ctx->r14, 0X2);
    // 0x8006D474: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x8006D478: nop

    // 0x8006D47C: beq         $s1, $t8, L_8006D4EC
    if (ctx->r17 == ctx->r24) {
        // 0x8006D480: nop
    
            goto L_8006D4EC;
    }
    // 0x8006D480: nop

    // 0x8006D484: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8006D488: nop

L_8006D48C:
    // 0x8006D48C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D490: lw          $a0, -0x430($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X430);
    // 0x8006D494: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x8006D498: jal         0x80050840
    // 0x8006D49C: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    Ids_DecRef(rdram, ctx);
        goto after_0;
    // 0x8006D49C: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    after_0:
    // 0x8006D4A0: sb          $s1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r17;
    // 0x8006D4A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D4A8: lw          $a0, -0x430($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X430);
    // 0x8006D4AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8006D4B0: jal         0x80050800
    // 0x8006D4B4: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    Ids_IncRef(rdram, ctx);
        goto after_1;
    // 0x8006D4B4: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    after_1:
    // 0x8006D4B8: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x8006D4BC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8006D4C0: nop

    // 0x8006D4C4: bne         $s0, $t9, L_8006D48C
    if (ctx->r16 != ctx->r25) {
        // 0x8006D4C8: nop
    
            goto L_8006D48C;
    }
    // 0x8006D4C8: nop

    // 0x8006D4CC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8006D4D0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8006D4D4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8006D4D8: lw          $s0, 0x4($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X4);
    // 0x8006D4DC: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8006D4E0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8006D4E4: nop

    // 0x8006D4E8: sw          $s0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r16;
L_8006D4EC:
    // 0x8006D4EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D4F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006D4F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006D4F8: jr          $ra
    // 0x8006D4FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006D4FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void BoardP_SplitCellToNewGroup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D500: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006D504: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006D508: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006D50C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006D510: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006D514: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8006D518: nop

    // 0x8006D51C: beq         $t7, $t6, L_8006D5AC
    if (ctx->r15 == ctx->r14) {
        // 0x8006D520: nop
    
            goto L_8006D5AC;
    }
    // 0x8006D520: nop

    // 0x8006D524: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006D528: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D52C: lw          $a0, -0x430($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X430);
    // 0x8006D530: lbu         $a1, 0x2($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X2);
    // 0x8006D534: jal         0x80050840
    // 0x8006D538: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    Ids_DecRef(rdram, ctx);
        goto after_0;
    // 0x8006D538: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    after_0:
    // 0x8006D53C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D540: lw          $a0, -0x430($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X430);
    // 0x8006D544: jal         0x80050714
    // 0x8006D548: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    can_run_out_of_ids(rdram, ctx);
        goto after_1;
    // 0x8006D548: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    after_1:
    // 0x8006D54C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8006D550: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D554: sb          $v0, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r2;
    // 0x8006D558: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8006D55C: lw          $a0, -0x430($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X430);
    // 0x8006D560: lbu         $a1, 0x2($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X2);
    // 0x8006D564: jal         0x80050800
    // 0x8006D568: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    Ids_IncRef(rdram, ctx);
        goto after_2;
    // 0x8006D568: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    after_2:
    // 0x8006D56C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006D570: nop

L_8006D574:
    // 0x8006D574: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x8006D578: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8006D57C: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8006D580: nop

    // 0x8006D584: bne         $t1, $t2, L_8006D574
    if (ctx->r9 != ctx->r10) {
        // 0x8006D588: nop
    
            goto L_8006D574;
    }
    // 0x8006D588: nop

    // 0x8006D58C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8006D590: nop

    // 0x8006D594: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8006D598: nop

    // 0x8006D59C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x8006D5A0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8006D5A4: nop

    // 0x8006D5A8: sw          $t5, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r13;
L_8006D5AC:
    // 0x8006D5AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D5B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006D5B4: jr          $ra
    // 0x8006D5B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006D5B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void BoardP_SeparateCell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D5BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006D5C0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006D5C4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006D5C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006D5CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006D5D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006D5D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006D5D8: lbu         $a0, 0x3($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X3);
    // 0x8006D5DC: jal         0x8006AB84
    // 0x8006D5E0: nop

    Multisquare_IsValidIndex(rdram, ctx);
        goto after_0;
    // 0x8006D5E0: nop

    after_0:
    // 0x8006D5E4: beq         $v0, $zero, L_8006D628
    if (ctx->r2 == 0) {
        // 0x8006D5E8: nop
    
            goto L_8006D628;
    }
    // 0x8006D5E8: nop

    // 0x8006D5EC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006D5F0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006D5F4: lbu         $t9, 0x3($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3);
    // 0x8006D5F8: lw          $t7, -0x460($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X460);
    // 0x8006D5FC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8006D600: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8006D604: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8006D608: addu        $s0, $t7, $t0
    ctx->r16 = ADD32(ctx->r15, ctx->r8);
    // 0x8006D60C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8006D610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006D614: jal         0x8006A410
    // 0x8006D618: addiu       $a1, $t8, 0x8
    ctx->r5 = ADD32(ctx->r24, 0X8);
    Multisquare_TickLifetime(rdram, ctx);
        goto after_1;
    // 0x8006D618: addiu       $a1, $t8, 0x8
    ctx->r5 = ADD32(ctx->r24, 0X8);
    after_1:
    // 0x8006D61C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8006D620: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8006D624: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
L_8006D628:
    // 0x8006D628: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8006D62C: jal         0x8006D998
    // 0x8006D630: nop

    BoardP_MarkRingCells(rdram, ctx);
        goto after_2;
    // 0x8006D630: nop

    after_2:
    // 0x8006D634: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8006D638: jal         0x8006D500
    // 0x8006D63C: nop

    BoardP_SplitCellToNewGroup(rdram, ctx);
        goto after_3;
    // 0x8006D63C: nop

    after_3:
    // 0x8006D640: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8006D644: nop

    // 0x8006D648: lb          $s1, 0x9($t3)
    ctx->r17 = MEM_B(ctx->r11, 0X9);
    // 0x8006D64C: lb          $s2, 0xA($t3)
    ctx->r18 = MEM_B(ctx->r11, 0XA);
    // 0x8006D650: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006D654: jal         0x8006E64C
    // 0x8006D658: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_4;
    // 0x8006D658: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x8006D65C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006D660: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006D664: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D668: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006D66C: jr          $ra
    // 0x8006D670: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006D670: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void BoardP_ConvertCellToFalling(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D674: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006D678: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006D67C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006D680: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006D684: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006D688: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x8006D68C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006D690: beq         $t7, $at, L_8006D718
    if (ctx->r15 == ctx->r1) {
        // 0x8006D694: nop
    
            goto L_8006D718;
    }
    // 0x8006D694: nop

    // 0x8006D698: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8006D69C: jal         0x8006D5BC
    // 0x8006D6A0: nop

    BoardP_SeparateCell(rdram, ctx);
        goto after_0;
    // 0x8006D6A0: nop

    after_0:
    // 0x8006D6A4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006D6A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D6AC: lw          $a0, -0x430($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X430);
    // 0x8006D6B0: lbu         $a1, 0x2($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X2);
    // 0x8006D6B4: jal         0x80050840
    // 0x8006D6B8: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    Ids_DecRef(rdram, ctx);
        goto after_1;
    // 0x8006D6B8: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    after_1:
    // 0x8006D6BC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8006D6C0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8006D6C4: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x8006D6C8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8006D6CC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8006D6D0: sb          $t1, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r9;
    // 0x8006D6D4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8006D6D8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8006D6DC: sb          $zero, 0x2($t3)
    MEM_B(0X2, ctx->r11) = 0;
    // 0x8006D6E0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8006D6E4: nop

    // 0x8006D6E8: sb          $t4, 0x3($t5)
    MEM_B(0X3, ctx->r13) = ctx->r12;
    // 0x8006D6EC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006D6F0: jal         0x8006F0E0
    // 0x8006D6F4: sw          $t6, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r14;
    FallingCubes_Alloc(rdram, ctx);
        goto after_2;
    // 0x8006D6F4: sw          $t6, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r14;
    after_2:
    // 0x8006D6F8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8006D6FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8006D700: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8006D704: nop

    // 0x8006D708: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006D70C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8006D710: nop

    // 0x8006D714: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
L_8006D718:
    // 0x8006D718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D71C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006D720: jr          $ra
    // 0x8006D724: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006D724: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void BoardP_UpdateCellAutotile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D728: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006D72C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006D730: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006D734: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006D738: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006D73C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006D740: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006D744: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006D748: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8006D74C: nop

    // 0x8006D750: beq         $t7, $zero, L_8006D8F4
    if (ctx->r15 == 0) {
        // 0x8006D754: nop
    
            goto L_8006D8F4;
    }
    // 0x8006D754: nop

    // 0x8006D758: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006D75C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8006D760: lb          $s1, 0x9($t8)
    ctx->r17 = MEM_B(ctx->r24, 0X9);
    // 0x8006D764: lb          $s2, 0xA($t8)
    ctx->r18 = MEM_B(ctx->r24, 0XA);
    // 0x8006D768: lbu         $s0, 0x2($t8)
    ctx->r16 = MEM_BU(ctx->r24, 0X2);
    // 0x8006D76C: addiu       $a0, $s1, -0x1
    ctx->r4 = ADD32(ctx->r17, -0X1);
    // 0x8006D770: jal         0x8006E5E0
    // 0x8006D774: addiu       $a1, $s2, -0x1
    ctx->r5 = ADD32(ctx->r18, -0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_0;
    // 0x8006D774: addiu       $a1, $s2, -0x1
    ctx->r5 = ADD32(ctx->r18, -0X1);
    after_0:
    // 0x8006D778: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x8006D77C: nop

    // 0x8006D780: bne         $t9, $s0, L_8006D798
    if (ctx->r25 != ctx->r16) {
        // 0x8006D784: nop
    
            goto L_8006D798;
    }
    // 0x8006D784: nop

    // 0x8006D788: ori         $t0, $s3, 0x80
    ctx->r8 = ctx->r19 | 0X80;
    // 0x8006D78C: or          $s3, $t0, $zero
    ctx->r19 = ctx->r8 | 0;
    // 0x8006D790: andi        $t1, $s3, 0xFF
    ctx->r9 = ctx->r19 & 0XFF;
    // 0x8006D794: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
L_8006D798:
    // 0x8006D798: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006D79C: jal         0x8006E5E0
    // 0x8006D7A0: addiu       $a1, $s2, -0x1
    ctx->r5 = ADD32(ctx->r18, -0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_1;
    // 0x8006D7A0: addiu       $a1, $s2, -0x1
    ctx->r5 = ADD32(ctx->r18, -0X1);
    after_1:
    // 0x8006D7A4: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x8006D7A8: nop

    // 0x8006D7AC: bne         $t2, $s0, L_8006D7C4
    if (ctx->r10 != ctx->r16) {
        // 0x8006D7B0: nop
    
            goto L_8006D7C4;
    }
    // 0x8006D7B0: nop

    // 0x8006D7B4: ori         $t3, $s3, 0x1
    ctx->r11 = ctx->r19 | 0X1;
    // 0x8006D7B8: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x8006D7BC: andi        $t4, $s3, 0xFF
    ctx->r12 = ctx->r19 & 0XFF;
    // 0x8006D7C0: or          $s3, $t4, $zero
    ctx->r19 = ctx->r12 | 0;
L_8006D7C4:
    // 0x8006D7C4: addiu       $a0, $s1, 0x1
    ctx->r4 = ADD32(ctx->r17, 0X1);
    // 0x8006D7C8: jal         0x8006E5E0
    // 0x8006D7CC: addiu       $a1, $s2, -0x1
    ctx->r5 = ADD32(ctx->r18, -0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_2;
    // 0x8006D7CC: addiu       $a1, $s2, -0x1
    ctx->r5 = ADD32(ctx->r18, -0X1);
    after_2:
    // 0x8006D7D0: lbu         $t5, 0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2);
    // 0x8006D7D4: nop

    // 0x8006D7D8: bne         $t5, $s0, L_8006D7F0
    if (ctx->r13 != ctx->r16) {
        // 0x8006D7DC: nop
    
            goto L_8006D7F0;
    }
    // 0x8006D7DC: nop

    // 0x8006D7E0: ori         $t6, $s3, 0x10
    ctx->r14 = ctx->r19 | 0X10;
    // 0x8006D7E4: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x8006D7E8: andi        $t7, $s3, 0xFF
    ctx->r15 = ctx->r19 & 0XFF;
    // 0x8006D7EC: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_8006D7F0:
    // 0x8006D7F0: addiu       $a0, $s1, -0x1
    ctx->r4 = ADD32(ctx->r17, -0X1);
    // 0x8006D7F4: jal         0x8006E5E0
    // 0x8006D7F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_3;
    // 0x8006D7F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x8006D7FC: lbu         $t8, 0x2($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2);
    // 0x8006D800: nop

    // 0x8006D804: bne         $t8, $s0, L_8006D81C
    if (ctx->r24 != ctx->r16) {
        // 0x8006D808: nop
    
            goto L_8006D81C;
    }
    // 0x8006D808: nop

    // 0x8006D80C: ori         $t9, $s3, 0x8
    ctx->r25 = ctx->r19 | 0X8;
    // 0x8006D810: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x8006D814: andi        $t0, $s3, 0xFF
    ctx->r8 = ctx->r19 & 0XFF;
    // 0x8006D818: or          $s3, $t0, $zero
    ctx->r19 = ctx->r8 | 0;
L_8006D81C:
    // 0x8006D81C: addiu       $a0, $s1, 0x1
    ctx->r4 = ADD32(ctx->r17, 0X1);
    // 0x8006D820: jal         0x8006E5E0
    // 0x8006D824: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_4;
    // 0x8006D824: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x8006D828: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x8006D82C: nop

    // 0x8006D830: bne         $t1, $s0, L_8006D848
    if (ctx->r9 != ctx->r16) {
        // 0x8006D834: nop
    
            goto L_8006D848;
    }
    // 0x8006D834: nop

    // 0x8006D838: ori         $t2, $s3, 0x2
    ctx->r10 = ctx->r19 | 0X2;
    // 0x8006D83C: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
    // 0x8006D840: andi        $t3, $s3, 0xFF
    ctx->r11 = ctx->r19 & 0XFF;
    // 0x8006D844: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
L_8006D848:
    // 0x8006D848: addiu       $a0, $s1, -0x1
    ctx->r4 = ADD32(ctx->r17, -0X1);
    // 0x8006D84C: jal         0x8006E5E0
    // 0x8006D850: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_5;
    // 0x8006D850: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    after_5:
    // 0x8006D854: lbu         $t4, 0x2($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X2);
    // 0x8006D858: nop

    // 0x8006D85C: bne         $t4, $s0, L_8006D874
    if (ctx->r12 != ctx->r16) {
        // 0x8006D860: nop
    
            goto L_8006D874;
    }
    // 0x8006D860: nop

    // 0x8006D864: ori         $t5, $s3, 0x40
    ctx->r13 = ctx->r19 | 0X40;
    // 0x8006D868: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x8006D86C: andi        $t6, $s3, 0xFF
    ctx->r14 = ctx->r19 & 0XFF;
    // 0x8006D870: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_8006D874:
    // 0x8006D874: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006D878: jal         0x8006E5E0
    // 0x8006D87C: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_6;
    // 0x8006D87C: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    after_6:
    // 0x8006D880: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x8006D884: nop

    // 0x8006D888: bne         $t7, $s0, L_8006D8A0
    if (ctx->r15 != ctx->r16) {
        // 0x8006D88C: nop
    
            goto L_8006D8A0;
    }
    // 0x8006D88C: nop

    // 0x8006D890: ori         $t8, $s3, 0x4
    ctx->r24 = ctx->r19 | 0X4;
    // 0x8006D894: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x8006D898: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x8006D89C: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
L_8006D8A0:
    // 0x8006D8A0: addiu       $a0, $s1, 0x1
    ctx->r4 = ADD32(ctx->r17, 0X1);
    // 0x8006D8A4: jal         0x8006E5E0
    // 0x8006D8A8: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_7;
    // 0x8006D8A8: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    after_7:
    // 0x8006D8AC: lbu         $t0, 0x2($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2);
    // 0x8006D8B0: nop

    // 0x8006D8B4: bne         $t0, $s0, L_8006D8CC
    if (ctx->r8 != ctx->r16) {
        // 0x8006D8B8: nop
    
            goto L_8006D8CC;
    }
    // 0x8006D8B8: nop

    // 0x8006D8BC: ori         $t1, $s3, 0x20
    ctx->r9 = ctx->r19 | 0X20;
    // 0x8006D8C0: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x8006D8C4: andi        $t2, $s3, 0xFF
    ctx->r10 = ctx->r19 & 0XFF;
    // 0x8006D8C8: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
L_8006D8CC:
    // 0x8006D8CC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006D8D0: lw          $t4, -0x350($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X350);
    // 0x8006D8D4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8006D8D8: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x8006D8DC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8006D8E0: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x8006D8E4: addiu       $a1, $t6, 0x7FFF
    ctx->r5 = ADD32(ctx->r14, 0X7FFF);
    // 0x8006D8E8: lw          $a1, 0x5C01($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5C01);
    // 0x8006D8EC: jal         0x80070818
    // 0x8006D8F0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_Mino_SetGraphicHandle(rdram, ctx);
        goto after_8;
    // 0x8006D8F0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_8:
L_8006D8F4:
    // 0x8006D8F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006D8F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006D8FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006D900: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D904: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006D908: jr          $ra
    // 0x8006D90C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006D90C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void BoardP_RefreshGroupTiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D910: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006D914: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006D918: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006D91C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006D920: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006D924: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006D928: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x8006D92C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006D930: beq         $t7, $at, L_8006D984
    if (ctx->r15 == ctx->r1) {
        // 0x8006D934: nop
    
            goto L_8006D984;
    }
    // 0x8006D934: nop

    // 0x8006D938: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8006D93C: jal         0x800A35EC
    // 0x8006D940: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    Scene_RandRange(rdram, ctx);
        goto after_0;
    // 0x8006D940: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x8006D944: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8006D948: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D94C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006D950: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x8006D954: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8006D958: jal         0x8008A5C8
    // 0x8006D95C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    Audio2_Play_SFX(rdram, ctx);
        goto after_1;
    // 0x8006D95C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x8006D960: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006D964: nop

L_8006D968:
    // 0x8006D968: jal         0x8006D728
    // 0x8006D96C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    BoardP_UpdateCellAutotile(rdram, ctx);
        goto after_2;
    // 0x8006D96C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8006D970: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x8006D974: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006D978: nop

    // 0x8006D97C: bne         $s0, $t8, L_8006D968
    if (ctx->r16 != ctx->r24) {
        // 0x8006D980: nop
    
            goto L_8006D968;
    }
    // 0x8006D980: nop

L_8006D984:
    // 0x8006D984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D988: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006D98C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006D990: jr          $ra
    // 0x8006D994: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006D994: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void BoardP_MarkRingCells(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D998: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8006D99C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006D9A0: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x8006D9A4: bne         $t7, $zero, L_8006D9D0
    if (ctx->r15 != 0) {
        // 0x8006D9A8: nop
    
            goto L_8006D9D0;
    }
    // 0x8006D9A8: nop

    // 0x8006D9AC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8006D9B0:
    // 0x8006D9B0: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x8006D9B4: nop

    // 0x8006D9B8: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8006D9BC: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
    // 0x8006D9C0: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x8006D9C4: nop

    // 0x8006D9C8: bne         $a1, $a0, L_8006D9B0
    if (ctx->r5 != ctx->r4) {
        // 0x8006D9CC: nop
    
            goto L_8006D9B0;
    }
    // 0x8006D9CC: nop

L_8006D9D0:
    // 0x8006D9D0: jr          $ra
    // 0x8006D9D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006D9D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void BoardP_CanGroupMove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D9D8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006D9DC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8006D9E0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8006D9E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006D9E8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8006D9EC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8006D9F0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006D9F4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006D9F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006D9FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006DA00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006DA04: lbu         $s4, 0x2($t6)
    ctx->r20 = MEM_BU(ctx->r14, 0X2);
    // 0x8006DA08: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8006DA0C:
    // 0x8006DA0C: lb          $s2, 0x9($s0)
    ctx->r18 = MEM_B(ctx->r16, 0X9);
    // 0x8006DA10: lb          $s3, 0xA($s0)
    ctx->r19 = MEM_B(ctx->r16, 0XA);
    // 0x8006DA14: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8006DA18: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8006DA1C: addu        $a0, $s2, $t7
    ctx->r4 = ADD32(ctx->r18, ctx->r15);
    // 0x8006DA20: jal         0x8006E5E0
    // 0x8006DA24: addu        $a1, $s3, $t8
    ctx->r5 = ADD32(ctx->r19, ctx->r24);
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_0;
    // 0x8006DA24: addu        $a1, $s3, $t8
    ctx->r5 = ADD32(ctx->r19, ctx->r24);
    after_0:
    // 0x8006DA28: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8006DA2C: lbu         $t9, 0x1($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X1);
    // 0x8006DA30: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006DA34: beq         $t9, $at, L_8006DA54
    if (ctx->r25 == ctx->r1) {
        // 0x8006DA38: nop
    
            goto L_8006DA54;
    }
    // 0x8006DA38: nop

    // 0x8006DA3C: lbu         $t0, 0x2($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X2);
    // 0x8006DA40: nop

    // 0x8006DA44: beq         $t0, $s4, L_8006DA54
    if (ctx->r8 == ctx->r20) {
        // 0x8006DA48: nop
    
            goto L_8006DA54;
    }
    // 0x8006DA48: nop

    // 0x8006DA4C: b           L_8006DA6C
    // 0x8006DA50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006DA6C;
    // 0x8006DA50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006DA54:
    // 0x8006DA54: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x8006DA58: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8006DA5C: nop

    // 0x8006DA60: bne         $s0, $t1, L_8006DA0C
    if (ctx->r16 != ctx->r9) {
        // 0x8006DA64: nop
    
            goto L_8006DA0C;
    }
    // 0x8006DA64: nop

    // 0x8006DA68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006DA6C:
    // 0x8006DA6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DA70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006DA74: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DA78: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006DA7C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006DA80: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006DA84: jr          $ra
    // 0x8006DA88: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006DA88: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void BoardP_InitCellType9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DA8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DA90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006DA94: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006DA98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DA9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006DAA0: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8006DAA4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8006DAA8: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x8006DAAC: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
    // 0x8006DAB0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8006DAB4: addiu       $t1, $zero, 0xFE
    ctx->r9 = ADD32(0, 0XFE);
    // 0x8006DAB8: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
    // 0x8006DABC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8006DAC0: nop

    // 0x8006DAC4: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
    // 0x8006DAC8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8006DACC: nop

    // 0x8006DAD0: sw          $t3, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r11;
    // 0x8006DAD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006DAD8: jal         0x8006E9C8
    // 0x8006DADC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    Cube_NewCellInfo(rdram, ctx);
        goto after_0;
    // 0x8006DADC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8006DAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DAE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DAE8: jr          $ra
    // 0x8006DAEC: nop

    return;
    // 0x8006DAEC: nop

;}

RECOMP_FUNC void BoardP_InitEmptyCell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DAF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DAF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006DAF8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006DAFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DB00: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8006DB04: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8006DB08: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8006DB0C: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8006DB10: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
    // 0x8006DB14: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8006DB18: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8006DB1C: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
    // 0x8006DB20: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8006DB24: nop

    // 0x8006DB28: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
    // 0x8006DB2C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8006DB30: nop

    // 0x8006DB34: sw          $t3, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r11;
    // 0x8006DB38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006DB3C: jal         0x8006E9C8
    // 0x8006DB40: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    Cube_NewCellInfo(rdram, ctx);
        goto after_0;
    // 0x8006DB40: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8006DB44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DB48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DB4C: jr          $ra
    // 0x8006DB50: nop

    return;
    // 0x8006DB50: nop

;}

RECOMP_FUNC void BoardP_UpdateQueueEntry_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DB54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DB58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006DB5C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006DB60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DB64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006DB68: lbu         $t7, 0x4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4);
    // 0x8006DB6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006DB70: bne         $t7, $at, L_8006DB94
    if (ctx->r15 != ctx->r1) {
        // 0x8006DB74: nop
    
            goto L_8006DB94;
    }
    // 0x8006DB74: nop

    // 0x8006DB78: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006DB7C: nop

    // 0x8006DB80: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8006DB84: jal         0x8006D728
    // 0x8006DB88: nop

    BoardP_UpdateCellAutotile(rdram, ctx);
        goto after_0;
    // 0x8006DB88: nop

    after_0:
    // 0x8006DB8C: b           L_8006DBA8
    // 0x8006DB90: nop

        goto L_8006DBA8;
    // 0x8006DB90: nop

L_8006DB94:
    // 0x8006DB94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006DB98: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006DB9C: addiu       $a1, $a1, -0x27D4
    ctx->r5 = ADD32(ctx->r5, -0X27D4);
    // 0x8006DBA0: jal         0x80083560
    // 0x8006DBA4: addiu       $a0, $a0, -0x27F0
    ctx->r4 = ADD32(ctx->r4, -0X27F0);
    debug_print_reason_routine(rdram, ctx);
        goto after_1;
    // 0x8006DBA4: addiu       $a0, $a0, -0x27F0
    ctx->r4 = ADD32(ctx->r4, -0X27F0);
    after_1:
L_8006DBA8:
    // 0x8006DBA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DBAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DBB0: jr          $ra
    // 0x8006DBB4: nop

    return;
    // 0x8006DBB4: nop

;}

RECOMP_FUNC void BoardP_UpdateQueue_ProcessAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DBB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006DBBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006DBC0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006DBC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DBC8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006DBCC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006DBD0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006DBD4: lhu         $s0, 0x12C2($t6)
    ctx->r16 = MEM_HU(ctx->r14, 0X12C2);
    // 0x8006DBD8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8006DBDC: blez        $s0, L_8006DBFC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8006DBE0: nop
    
            goto L_8006DBFC;
    }
    // 0x8006DBE0: nop

L_8006DBE4:
    // 0x8006DBE4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DBE8: jal         0x8006DB54
    // 0x8006DBEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    BoardP_UpdateQueueEntry_Update(rdram, ctx);
        goto after_0;
    // 0x8006DBEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8006DBF0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006DBF4: bgtz        $s0, L_8006DBE4
    if (SIGNED(ctx->r16) > 0) {
        // 0x8006DBF8: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_8006DBE4;
    }
    // 0x8006DBF8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_8006DBFC:
    // 0x8006DBFC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8006DC00: nop

    // 0x8006DC04: sh          $zero, 0x12C2($t7)
    MEM_H(0X12C2, ctx->r15) = 0;
    // 0x8006DC08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DC0C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006DC10: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006DC14: jr          $ra
    // 0x8006DC18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006DC18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void BoardP_UpdateQueue_AddEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DC20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006DC24: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006DC28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DC2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006DC30: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006DC34: lhu         $t8, 0x12C0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X12C0);
    // 0x8006DC38: lhu         $t7, 0x12C2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X12C2);
    // 0x8006DC3C: nop

    // 0x8006DC40: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006DC44: bne         $at, $zero, L_8006DC60
    if (ctx->r1 != 0) {
        // 0x8006DC48: nop
    
            goto L_8006DC60;
    }
    // 0x8006DC48: nop

    // 0x8006DC4C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006DC50: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006DC54: addiu       $a1, $a1, -0x279C
    ctx->r5 = ADD32(ctx->r5, -0X279C);
    // 0x8006DC58: jal         0x80083560
    // 0x8006DC5C: addiu       $a0, $a0, -0x27BC
    ctx->r4 = ADD32(ctx->r4, -0X27BC);
    debug_print_reason_routine(rdram, ctx);
        goto after_0;
    // 0x8006DC5C: addiu       $a0, $a0, -0x27BC
    ctx->r4 = ADD32(ctx->r4, -0X27BC);
    after_0:
L_8006DC60:
    // 0x8006DC60: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8006DC64: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x8006DC68: lhu         $t1, 0x12C2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X12C2);
    // 0x8006DC6C: nop

    // 0x8006DC70: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8006DC74: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8006DC78: sb          $t9, 0x4($t3)
    MEM_B(0X4, ctx->r11) = ctx->r25;
    // 0x8006DC7C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8006DC80: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DC84: lhu         $t6, 0x12C2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X12C2);
    // 0x8006DC88: nop

    // 0x8006DC8C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8006DC90: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8006DC94: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8006DC98: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006DC9C: nop

    // 0x8006DCA0: lhu         $t0, 0x12C2($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X12C2);
    // 0x8006DCA4: nop

    // 0x8006DCA8: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8006DCAC: sh          $t2, 0x12C2($t1)
    MEM_H(0X12C2, ctx->r9) = ctx->r10;
    // 0x8006DCB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DCB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DCB8: jr          $ra
    // 0x8006DCBC: nop

    return;
    // 0x8006DCBC: nop

;}

RECOMP_FUNC void BoardP_UpdateQueue_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DCC0: addiu       $t6, $zero, 0x258
    ctx->r14 = ADD32(0, 0X258);
    // 0x8006DCC4: sh          $t6, 0x12C0($a0)
    MEM_H(0X12C0, ctx->r4) = ctx->r14;
    // 0x8006DCC8: jr          $ra
    // 0x8006DCCC: sh          $zero, 0x12C2($a0)
    MEM_H(0X12C2, ctx->r4) = 0;
    return;
    // 0x8006DCCC: sh          $zero, 0x12C2($a0)
    MEM_H(0X12C2, ctx->r4) = 0;
;}

RECOMP_FUNC void BoardP_FindFirstOccupiedRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DCD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006DCD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006DCD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DCDC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006DCE0:
    // 0x8006DCE0: jal         0x8006DD64
    // 0x8006DCE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    BoardP_RowHasCube(rdram, ctx);
        goto after_0;
    // 0x8006DCE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006DCE8: beq         $v0, $zero, L_8006DCF8
    if (ctx->r2 == 0) {
        // 0x8006DCEC: nop
    
            goto L_8006DCF8;
    }
    // 0x8006DCEC: nop

    // 0x8006DCF0: b           L_8006DD0C
    // 0x8006DCF4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8006DD0C;
    // 0x8006DCF4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8006DCF8:
    // 0x8006DCF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006DCFC: slti        $at, $s0, 0x13
    ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
    // 0x8006DD00: bne         $at, $zero, L_8006DCE0
    if (ctx->r1 != 0) {
        // 0x8006DD04: nop
    
            goto L_8006DCE0;
    }
    // 0x8006DD04: nop

    // 0x8006DD08: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_8006DD0C:
    // 0x8006DD0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DD10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006DD14: jr          $ra
    // 0x8006DD18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006DD18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void BoardP_FindLastOccupiedRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006DD20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006DD24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DD28: addiu       $s0, $zero, 0x13
    ctx->r16 = ADD32(0, 0X13);
L_8006DD2C:
    // 0x8006DD2C: jal         0x8006DD64
    // 0x8006DD30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    BoardP_RowHasCube(rdram, ctx);
        goto after_0;
    // 0x8006DD30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006DD34: beq         $v0, $zero, L_8006DD44
    if (ctx->r2 == 0) {
        // 0x8006DD38: nop
    
            goto L_8006DD44;
    }
    // 0x8006DD38: nop

    // 0x8006DD3C: b           L_8006DD54
    // 0x8006DD40: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8006DD54;
    // 0x8006DD40: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8006DD44:
    // 0x8006DD44: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006DD48: bgtz        $s0, L_8006DD2C
    if (SIGNED(ctx->r16) > 0) {
        // 0x8006DD4C: nop
    
            goto L_8006DD2C;
    }
    // 0x8006DD4C: nop

    // 0x8006DD50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006DD54:
    // 0x8006DD54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DD58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006DD5C: jr          $ra
    // 0x8006DD60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006DD60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void BoardP_RowHasCube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD64: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8006DD68: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8006DD6C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006DD70: lw          $t6, -0x430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X430);
    // 0x8006DD74: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006DD78: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006DD7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006DD80: slti        $at, $a2, 0xA
    ctx->r1 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x8006DD84: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    // 0x8006DD88: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006DD8C: beq         $at, $zero, L_8006DDC4
    if (ctx->r1 == 0) {
        // 0x8006DD90: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8006DDC4;
    }
    // 0x8006DD90: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8006DD94:
    // 0x8006DD94: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8006DD98: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006DD9C: lbu         $t0, 0x1($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1);
    // 0x8006DDA0: nop

    // 0x8006DDA4: beq         $t0, $at, L_8006DDB4
    if (ctx->r8 == ctx->r1) {
        // 0x8006DDA8: nop
    
            goto L_8006DDB4;
    }
    // 0x8006DDA8: nop

    // 0x8006DDAC: b           L_8006DDC8
    // 0x8006DDB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006DDC8;
    // 0x8006DDB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006DDB4:
    // 0x8006DDB4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006DDB8: slti        $at, $a2, 0xA
    ctx->r1 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x8006DDBC: bne         $at, $zero, L_8006DD94
    if (ctx->r1 != 0) {
        // 0x8006DDC0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8006DD94;
    }
    // 0x8006DDC0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8006DDC4:
    // 0x8006DDC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006DDC8:
    // 0x8006DDC8: jr          $ra
    // 0x8006DDCC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006DDCC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void BoardP_AnyCubeInRowsUpTo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DDD0: bgtz        $a0, L_8006DDE0
    if (SIGNED(ctx->r4) > 0) {
        // 0x8006DDD4: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_8006DDE0;
    }
    // 0x8006DDD4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006DDD8: b           L_8006DE38
    // 0x8006DDDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006DE38;
    // 0x8006DDDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006DDE0:
    // 0x8006DDE0: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8006DDE4: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8006DDE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006DDEC: lw          $t6, -0x430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X430);
    // 0x8006DDF0: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006DDF4: sll         $a2, $a0, 2
    ctx->r6 = S32(ctx->r4 << 2);
    // 0x8006DDF8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006DDFC: addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // 0x8006DE00: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8006DE04: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
L_8006DE08:
    // 0x8006DE08: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8006DE0C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006DE10: lbu         $t0, 0x1($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1);
    // 0x8006DE14: nop

    // 0x8006DE18: beq         $t0, $at, L_8006DE28
    if (ctx->r8 == ctx->r1) {
        // 0x8006DE1C: nop
    
            goto L_8006DE28;
    }
    // 0x8006DE1C: nop

    // 0x8006DE20: b           L_8006DE38
    // 0x8006DE24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006DE38;
    // 0x8006DE24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006DE28:
    // 0x8006DE28: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8006DE2C: bne         $a2, $zero, L_8006DE08
    if (ctx->r6 != 0) {
        // 0x8006DE30: addiu       $a1, $a1, -0x4
        ctx->r5 = ADD32(ctx->r5, -0X4);
            goto L_8006DE08;
    }
    // 0x8006DE30: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8006DE34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006DE38:
    // 0x8006DE38: jr          $ra
    // 0x8006DE3C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006DE3C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void BoardP_SetCubeAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DE40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006DE44: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006DE48: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006DE4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DE50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006DE54: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8006DE58: bltz        $t6, L_8006DF28
    if (SIGNED(ctx->r14) < 0) {
        // 0x8006DE5C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8006DF28;
    }
    // 0x8006DE5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006DE60: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x8006DE64: beq         $at, $zero, L_8006DF28
    if (ctx->r1 == 0) {
        // 0x8006DE68: nop
    
            goto L_8006DF28;
    }
    // 0x8006DE68: nop

    // 0x8006DE6C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DE70: nop

    // 0x8006DE74: bltz        $t7, L_8006DF28
    if (SIGNED(ctx->r15) < 0) {
        // 0x8006DE78: slti        $at, $t7, 0x14
        ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
            goto L_8006DF28;
    }
    // 0x8006DE78: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x8006DE7C: beq         $at, $zero, L_8006DF28
    if (ctx->r1 == 0) {
        // 0x8006DE80: nop
    
            goto L_8006DF28;
    }
    // 0x8006DE80: nop

    // 0x8006DE84: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DE88: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006DE8C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006DE90: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8006DE94: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8006DE98: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006DE9C: lw          $t3, -0x430($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X430);
    // 0x8006DEA0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8006DEA4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8006DEA8: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x8006DEAC: lw          $s0, 0x4($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X4);
    // 0x8006DEB0: lbu         $t5, 0x33($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X33);
    // 0x8006DEB4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DEB8: sb          $t5, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r13;
    // 0x8006DEBC: lw          $a0, -0x430($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X430);
    // 0x8006DEC0: jal         0x80050714
    // 0x8006DEC4: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    can_run_out_of_ids(rdram, ctx);
        goto after_0;
    // 0x8006DEC4: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    after_0:
    // 0x8006DEC8: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x8006DECC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DED0: lw          $a0, -0x430($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X430);
    // 0x8006DED4: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x8006DED8: jal         0x80050800
    // 0x8006DEDC: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    Ids_IncRef(rdram, ctx);
        goto after_1;
    // 0x8006DEDC: addiu       $a0, $a0, 0x1608
    ctx->r4 = ADD32(ctx->r4, 0X1608);
    after_1:
    // 0x8006DEE0: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8006DEE4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8006DEE8: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8006DEEC: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8006DEF0: lbu         $t9, 0x33($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X33);
    // 0x8006DEF4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006DEF8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8006DEFC: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8006DF00: lw          $t0, 0x110($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X110);
    // 0x8006DF04: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DF08: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8006DF0C: lw          $a3, 0x18($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X18);
    // 0x8006DF10: jal         0x8006E940
    // 0x8006DF14: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    Cube_Alloc(rdram, ctx);
        goto after_2;
    // 0x8006DF14: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_2:
    // 0x8006DF18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8006DF1C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DF20: jal         0x8006E64C
    // 0x8006DF24: nop

    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_3;
    // 0x8006DF24: nop

    after_3:
L_8006DF28:
    // 0x8006DF28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DF2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006DF30: jr          $ra
    // 0x8006DF34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006DF34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void BoardP_PlaceMultisquareCubes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DF38: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006DF3C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8006DF40: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8006DF44: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006DF48: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006DF4C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006DF50: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006DF54: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006DF58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006DF5C: lbu         $s2, 0x5($t6)
    ctx->r18 = MEM_BU(ctx->r14, 0X5);
    // 0x8006DF60: nop

    // 0x8006DF64: beq         $s2, $zero, L_8006E0C8
    if (ctx->r18 == 0) {
        // 0x8006DF68: nop
    
            goto L_8006E0C8;
    }
    // 0x8006DF68: nop

    // 0x8006DF6C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8006DF70: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x8006DF74: lw          $s1, 0x0($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X0);
    // 0x8006DF78: blez        $s3, L_8006DFD4
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8006DF7C: nop
    
            goto L_8006DFD4;
    }
    // 0x8006DF7C: nop

L_8006DF80:
    // 0x8006DF80: lb          $t8, 0x0($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X0);
    // 0x8006DF84: nop

    // 0x8006DF88: bltz        $t8, L_8006E0C8
    if (SIGNED(ctx->r24) < 0) {
        // 0x8006DF8C: nop
    
            goto L_8006E0C8;
    }
    // 0x8006DF8C: nop

    // 0x8006DF90: lb          $t9, 0x0($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X0);
    // 0x8006DF94: nop

    // 0x8006DF98: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x8006DF9C: beq         $at, $zero, L_8006E0C8
    if (ctx->r1 == 0) {
        // 0x8006DFA0: nop
    
            goto L_8006E0C8;
    }
    // 0x8006DFA0: nop

    // 0x8006DFA4: lb          $t0, 0x1($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X1);
    // 0x8006DFA8: nop

    // 0x8006DFAC: bltz        $t0, L_8006E0C8
    if (SIGNED(ctx->r8) < 0) {
        // 0x8006DFB0: nop
    
            goto L_8006E0C8;
    }
    // 0x8006DFB0: nop

    // 0x8006DFB4: lb          $t1, 0x1($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1);
    // 0x8006DFB8: nop

    // 0x8006DFBC: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x8006DFC0: beq         $at, $zero, L_8006E0C8
    if (ctx->r1 == 0) {
        // 0x8006DFC4: nop
    
            goto L_8006E0C8;
    }
    // 0x8006DFC4: nop

    // 0x8006DFC8: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x8006DFCC: bgtz        $s3, L_8006DF80
    if (SIGNED(ctx->r19) > 0) {
        // 0x8006DFD0: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_8006DF80;
    }
    // 0x8006DFD0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_8006DFD4:
    // 0x8006DFD4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8006DFD8: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8006DFDC: lbu         $t3, 0x4($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X4);
    // 0x8006DFE0: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x8006DFE4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8006DFE8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8006DFEC: lw          $t5, 0x110($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X110);
    // 0x8006DFF0: nop

    // 0x8006DFF4: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x8006DFF8: nop

    // 0x8006DFFC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8006E000: lw          $s1, 0x0($t2)
    ctx->r17 = MEM_W(ctx->r10, 0X0);
    // 0x8006E004: blez        $s3, L_8006E030
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8006E008: nop
    
            goto L_8006E030;
    }
    // 0x8006E008: nop

L_8006E00C:
    // 0x8006E00C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8006E010: lb          $a0, 0x0($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X0);
    // 0x8006E014: lb          $a1, 0x1($s1)
    ctx->r5 = MEM_B(ctx->r17, 0X1);
    // 0x8006E018: lbu         $a2, 0x4($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X4);
    // 0x8006E01C: jal         0x8006DE40
    // 0x8006E020: nop

    BoardP_SetCubeAt(rdram, ctx);
        goto after_0;
    // 0x8006E020: nop

    after_0:
    // 0x8006E024: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x8006E028: bgtz        $s3, L_8006E00C
    if (SIGNED(ctx->r19) > 0) {
        // 0x8006E02C: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_8006E00C;
    }
    // 0x8006E02C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_8006E030:
    // 0x8006E030: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x8006E034: bne         $at, $zero, L_8006E0C8
    if (ctx->r1 != 0) {
        // 0x8006E038: nop
    
            goto L_8006E0C8;
    }
    // 0x8006E038: nop

    // 0x8006E03C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8006E040: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006E044: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x8006E048: lw          $t5, -0x430($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X430);
    // 0x8006E04C: lb          $t0, 0x1($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X1);
    // 0x8006E050: lb          $t9, 0x0($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X0);
    // 0x8006E054: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8006E058: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8006E05C: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006E060: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x8006E064: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8006E068: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x8006E06C: lw          $s4, 0x4($t6)
    ctx->r20 = MEM_W(ctx->r14, 0X4);
    // 0x8006E070: addiu       $s3, $s2, -0x1
    ctx->r19 = ADD32(ctx->r18, -0X1);
    // 0x8006E074: blez        $s3, L_8006E0C0
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8006E078: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_8006E0C0;
    }
    // 0x8006E078: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_8006E07C:
    // 0x8006E07C: lb          $t7, 0x1($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1);
    // 0x8006E080: lb          $t2, 0x0($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X0);
    // 0x8006E084: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006E088: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006E08C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006E090: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E094: lw          $t1, -0x430($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X430);
    // 0x8006E098: addu        $t0, $t2, $t8
    ctx->r8 = ADD32(ctx->r10, ctx->r24);
    // 0x8006E09C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8006E0A0: addu        $t3, $t1, $t9
    ctx->r11 = ADD32(ctx->r9, ctx->r25);
    // 0x8006E0A4: lw          $s0, 0x4($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X4);
    // 0x8006E0A8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8006E0AC: jal         0x8006D450
    // 0x8006E0B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    BoardP_MergeGroups(rdram, ctx);
        goto after_1;
    // 0x8006E0B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8006E0B4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x8006E0B8: bgtz        $s3, L_8006E07C
    if (SIGNED(ctx->r19) > 0) {
        // 0x8006E0BC: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_8006E07C;
    }
    // 0x8006E0BC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_8006E0C0:
    // 0x8006E0C0: jal         0x8006D910
    // 0x8006E0C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    BoardP_RefreshGroupTiles(rdram, ctx);
        goto after_2;
    // 0x8006E0C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
L_8006E0C8:
    // 0x8006E0C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E0CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006E0D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E0D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006E0D8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006E0DC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006E0E0: jr          $ra
    // 0x8006E0E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006E0E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void BoardP_RemoveCubeAndCollapseColumn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E288: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006E28C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006E290: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006E294: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E298: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006E29C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006E2A0: lb          $s0, 0x9($t6)
    ctx->r16 = MEM_B(ctx->r14, 0X9);
    // 0x8006E2A4: lb          $s1, 0xA($t6)
    ctx->r17 = MEM_B(ctx->r14, 0XA);
    // 0x8006E2A8: jal         0x8006D674
    // 0x8006E2AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    BoardP_ConvertCellToFalling(rdram, ctx);
        goto after_0;
    // 0x8006E2AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8006E2B0: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x8006E2B4: jal         0x8006E64C
    // 0x8006E2B8: addiu       $a1, $s1, -0x1
    ctx->r5 = ADD32(ctx->r17, -0X1);
    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_1;
    // 0x8006E2B8: addiu       $a1, $s1, -0x1
    ctx->r5 = ADD32(ctx->r17, -0X1);
    after_1:
    // 0x8006E2BC: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x8006E2C0: jal         0x8006E64C
    // 0x8006E2C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_2;
    // 0x8006E2C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8006E2C8: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x8006E2CC: jal         0x8006E64C
    // 0x8006E2D0: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_3;
    // 0x8006E2D0: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    after_3:
    // 0x8006E2D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E2D8: jal         0x8006E64C
    // 0x8006E2DC: addiu       $a1, $s1, -0x1
    ctx->r5 = ADD32(ctx->r17, -0X1);
    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_4;
    // 0x8006E2DC: addiu       $a1, $s1, -0x1
    ctx->r5 = ADD32(ctx->r17, -0X1);
    after_4:
    // 0x8006E2E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E2E4: jal         0x8006E64C
    // 0x8006E2E8: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_5;
    // 0x8006E2E8: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    after_5:
    // 0x8006E2EC: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x8006E2F0: jal         0x8006E64C
    // 0x8006E2F4: addiu       $a1, $s1, -0x1
    ctx->r5 = ADD32(ctx->r17, -0X1);
    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_6;
    // 0x8006E2F4: addiu       $a1, $s1, -0x1
    ctx->r5 = ADD32(ctx->r17, -0X1);
    after_6:
    // 0x8006E2F8: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x8006E2FC: jal         0x8006E64C
    // 0x8006E300: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_7;
    // 0x8006E300: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x8006E304: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x8006E308: jal         0x8006E64C
    // 0x8006E30C: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    BoardP_QueueCellUpdate(rdram, ctx);
        goto after_8;
    // 0x8006E30C: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    after_8:
    // 0x8006E310: blez        $s1, L_8006E338
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8006E314: nop
    
            goto L_8006E338;
    }
    // 0x8006E314: nop

L_8006E318:
    // 0x8006E318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006E31C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8006E320: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8006E324: jal         0x8006E0E8
    // 0x8006E328: addiu       $a3, $s1, -0x1
    ctx->r7 = ADD32(ctx->r17, -0X1);
    BoardPieces_SwapCubes(rdram, ctx);
        goto after_9;
    // 0x8006E328: addiu       $a3, $s1, -0x1
    ctx->r7 = ADD32(ctx->r17, -0X1);
    after_9:
    // 0x8006E32C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8006E330: bgtz        $s1, L_8006E318
    if (SIGNED(ctx->r17) > 0) {
        // 0x8006E334: nop
    
            goto L_8006E318;
    }
    // 0x8006E334: nop

L_8006E338:
    // 0x8006E338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E33C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006E340: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006E344: jr          $ra
    // 0x8006E348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006E348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void BoardP_IsPositionEmpty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E498: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006E49C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006E4A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006E4A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E4A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E4AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8006E4B0: jal         0x8006E5E0
    // 0x8006E4B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_0;
    // 0x8006E4B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006E4B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8006E4BC: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x8006E4C0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006E4C4: bne         $t6, $at, L_8006E4D4
    if (ctx->r14 != ctx->r1) {
        // 0x8006E4C8: nop
    
            goto L_8006E4D4;
    }
    // 0x8006E4C8: nop

    // 0x8006E4CC: b           L_8006E4D8
    // 0x8006E4D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006E4D8;
    // 0x8006E4D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006E4D4:
    // 0x8006E4D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006E4D8:
    // 0x8006E4D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E4DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006E4E0: jr          $ra
    // 0x8006E4E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006E4E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void BoardP_IsPointEmpty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E4E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006E4EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006E4F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006E4F4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8006E4F8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8006E4FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E500: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8006E504: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x8006E508: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8006E50C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8006E510: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8006E514: jal         0x8006E498
    // 0x8006E518: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    BoardP_IsPositionEmpty(rdram, ctx);
        goto after_0;
    // 0x8006E518: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x8006E51C: bne         $v0, $zero, L_8006E52C
    if (ctx->r2 != 0) {
        // 0x8006E520: nop
    
            goto L_8006E52C;
    }
    // 0x8006E520: nop

    // 0x8006E524: b           L_8006E5D0
    // 0x8006E528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006E5D0;
    // 0x8006E528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006E52C:
    // 0x8006E52C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006E530: nop

    // 0x8006E534: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8006E538: beq         $t1, $zero, L_8006E560
    if (ctx->r9 == 0) {
        // 0x8006E53C: nop
    
            goto L_8006E560;
    }
    // 0x8006E53C: nop

    // 0x8006E540: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E544: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006E548: jal         0x8006E498
    // 0x8006E54C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    BoardP_IsPositionEmpty(rdram, ctx);
        goto after_1;
    // 0x8006E54C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_1:
    // 0x8006E550: bne         $v0, $zero, L_8006E560
    if (ctx->r2 != 0) {
        // 0x8006E554: nop
    
            goto L_8006E560;
    }
    // 0x8006E554: nop

    // 0x8006E558: b           L_8006E5D0
    // 0x8006E55C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006E5D0;
    // 0x8006E55C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006E560:
    // 0x8006E560: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8006E564: nop

    // 0x8006E568: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8006E56C: beq         $t3, $zero, L_8006E5CC
    if (ctx->r11 == 0) {
        // 0x8006E570: nop
    
            goto L_8006E5CC;
    }
    // 0x8006E570: nop

    // 0x8006E574: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006E578: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E57C: jal         0x8006E498
    // 0x8006E580: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    BoardP_IsPositionEmpty(rdram, ctx);
        goto after_2;
    // 0x8006E580: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_2:
    // 0x8006E584: bne         $v0, $zero, L_8006E594
    if (ctx->r2 != 0) {
        // 0x8006E588: nop
    
            goto L_8006E594;
    }
    // 0x8006E588: nop

    // 0x8006E58C: b           L_8006E5D0
    // 0x8006E590: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006E5D0;
    // 0x8006E590: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006E594:
    // 0x8006E594: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8006E598: nop

    // 0x8006E59C: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8006E5A0: beq         $t5, $zero, L_8006E5CC
    if (ctx->r13 == 0) {
        // 0x8006E5A4: nop
    
            goto L_8006E5CC;
    }
    // 0x8006E5A4: nop

    // 0x8006E5A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E5AC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006E5B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006E5B4: jal         0x8006E498
    // 0x8006E5B8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    BoardP_IsPositionEmpty(rdram, ctx);
        goto after_3;
    // 0x8006E5B8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_3:
    // 0x8006E5BC: bne         $v0, $zero, L_8006E5CC
    if (ctx->r2 != 0) {
        // 0x8006E5C0: nop
    
            goto L_8006E5CC;
    }
    // 0x8006E5C0: nop

    // 0x8006E5C4: b           L_8006E5D0
    // 0x8006E5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006E5D0;
    // 0x8006E5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006E5CC:
    // 0x8006E5CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006E5D0:
    // 0x8006E5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E5D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006E5D8: jr          $ra
    // 0x8006E5DC: nop

    return;
    // 0x8006E5DC: nop

;}

RECOMP_FUNC void BoardP_PlayfieldXYToLogicCell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E5E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006E5E4: lw          $a2, -0x430($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X430);
    // 0x8006E5E8: bltz        $a0, L_8006E604
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006E5EC: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_8006E604;
    }
    // 0x8006E5EC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006E5F0: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x8006E5F4: beq         $at, $zero, L_8006E604
    if (ctx->r1 == 0) {
        // 0x8006E5F8: slti        $at, $a1, 0x14
        ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
            goto L_8006E604;
    }
    // 0x8006E5F8: slti        $at, $a1, 0x14
    ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    // 0x8006E5FC: bne         $at, $zero, L_8006E60C
    if (ctx->r1 != 0) {
        // 0x8006E600: nop
    
            goto L_8006E60C;
    }
    // 0x8006E600: nop

L_8006E604:
    // 0x8006E604: b           L_8006E644
    // 0x8006E608: addiu       $v0, $a2, 0x334
    ctx->r2 = ADD32(ctx->r6, 0X334);
        goto L_8006E644;
    // 0x8006E608: addiu       $v0, $a2, 0x334
    ctx->r2 = ADD32(ctx->r6, 0X334);
L_8006E60C:
    // 0x8006E60C: bgez        $a1, L_8006E61C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8006E610: nop
    
            goto L_8006E61C;
    }
    // 0x8006E610: nop

    // 0x8006E614: b           L_8006E644
    // 0x8006E618: addiu       $v0, $a2, 0x324
    ctx->r2 = ADD32(ctx->r6, 0X324);
        goto L_8006E644;
    // 0x8006E618: addiu       $v0, $a2, 0x324
    ctx->r2 = ADD32(ctx->r6, 0X324);
L_8006E61C:
    // 0x8006E61C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8006E620: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8006E624: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006E628: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006E62C: lw          $t6, -0x430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X430);
    // 0x8006E630: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8006E634: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006E638: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x8006E63C: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x8006E640: nop

L_8006E644:
    // 0x8006E644: jr          $ra
    // 0x8006E648: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006E648: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void BoardP_QueueCellUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E64C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006E650: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006E654: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006E658: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E65C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006E660: bltz        $t6, L_8006E6E4
    if (SIGNED(ctx->r14) < 0) {
        // 0x8006E664: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8006E6E4;
    }
    // 0x8006E664: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006E668: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x8006E66C: beq         $at, $zero, L_8006E6E4
    if (ctx->r1 == 0) {
        // 0x8006E670: nop
    
            goto L_8006E6E4;
    }
    // 0x8006E670: nop

    // 0x8006E674: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E678: nop

    // 0x8006E67C: bltz        $t7, L_8006E6E4
    if (SIGNED(ctx->r15) < 0) {
        // 0x8006E680: slti        $at, $t7, 0x14
        ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
            goto L_8006E6E4;
    }
    // 0x8006E680: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x8006E684: beq         $at, $zero, L_8006E6E4
    if (ctx->r1 == 0) {
        // 0x8006E688: nop
    
            goto L_8006E6E4;
    }
    // 0x8006E688: nop

    // 0x8006E68C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E690: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006E694: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006E698: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8006E69C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8006E6A0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E6A4: lw          $t3, -0x430($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X430);
    // 0x8006E6A8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8006E6AC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8006E6B0: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x8006E6B4: lw          $s0, 0x4($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X4);
    // 0x8006E6B8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006E6BC: lbu         $t5, 0x1($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1);
    // 0x8006E6C0: nop

    // 0x8006E6C4: beq         $t5, $at, L_8006E6E4
    if (ctx->r13 == ctx->r1) {
        // 0x8006E6C8: nop
    
            goto L_8006E6E4;
    }
    // 0x8006E6C8: nop

    // 0x8006E6CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006E6D0: lw          $a0, -0x430($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X430);
    // 0x8006E6D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006E6D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006E6DC: jal         0x8006DC1C
    // 0x8006E6E0: addiu       $a0, $a0, 0x344
    ctx->r4 = ADD32(ctx->r4, 0X344);
    BoardP_UpdateQueue_AddEntry(rdram, ctx);
        goto after_0;
    // 0x8006E6E0: addiu       $a0, $a0, 0x344
    ctx->r4 = ADD32(ctx->r4, 0X344);
    after_0:
L_8006E6E4:
    // 0x8006E6E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E6E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006E6EC: jr          $ra
    // 0x8006E6F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006E6F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

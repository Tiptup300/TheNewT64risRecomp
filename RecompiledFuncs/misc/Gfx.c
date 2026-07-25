#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Gfx_SubmitFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800492FC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80049300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049304: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049308: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004930C: addiu       $a1, $a1, 0x2120
    ctx->r5 = ADD32(ctx->r5, 0X2120);
    // 0x80049310: addiu       $a0, $a0, 0x20D8
    ctx->r4 = ADD32(ctx->r4, 0X20D8);
    // 0x80049314: jal         0x800B3080
    // 0x80049318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80049318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8004931C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80049320: addiu       $a1, $a1, 0x20D8
    ctx->r5 = ADD32(ctx->r5, 0X20D8);
    // 0x80049324: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80049328: jal         0x800B30B0
    // 0x8004932C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8004932C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80049330: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049334: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80049338: addiu       $a1, $a1, 0x2124
    ctx->r5 = ADD32(ctx->r5, 0X2124);
    // 0x8004933C: addiu       $a0, $a0, 0x20F0
    ctx->r4 = ADD32(ctx->r4, 0X20F0);
    // 0x80049340: jal         0x800B3080
    // 0x80049344: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80049344: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80049348: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004934C: addiu       $a1, $a1, 0x20F0
    ctx->r5 = ADD32(ctx->r5, 0X20F0);
    // 0x80049350: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80049354: jal         0x800B30B0
    // 0x80049358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80049358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8004935C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049360: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80049364: addiu       $a1, $a1, 0x2128
    ctx->r5 = ADD32(ctx->r5, 0X2128);
    // 0x80049368: addiu       $a0, $a0, 0x2108
    ctx->r4 = ADD32(ctx->r4, 0X2108);
    // 0x8004936C: jal         0x800B3080
    // 0x80049370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x80049370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80049374: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049378: addiu       $a0, $a0, 0x2108
    ctx->r4 = ADD32(ctx->r4, 0X2108);
    // 0x8004937C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049380: jal         0x800B65E0
    // 0x80049384: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osViSetEvent_recomp(rdram, ctx);
        goto after_5;
    // 0x80049384: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
L_80049388:
    // 0x80049388: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8004938C: lhu         $t6, 0x20B0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X20B0);
    // 0x80049390: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80049394: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80049398: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004939C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800493A0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800493A4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800493A8: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x800493AC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800493B0: jal         0x800B6550
    // 0x800493B4: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    osGetTime_recomp(rdram, ctx);
        goto after_6;
    // 0x800493B4: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    after_6:
    // 0x800493B8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800493BC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800493C0: lw          $t1, 0x54($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X54);
    // 0x800493C4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800493C8: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x800493CC: sw          $v1, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r3;
    // 0x800493D0: lhu         $t2, 0x20B0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X20B0);
    // 0x800493D4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800493D8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800493DC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800493E0: lw          $t4, 0x20B8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20B8);
    // 0x800493E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800493E8: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x800493EC: lw          $t5, 0x20C8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20C8);
    // 0x800493F0: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x800493F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800493F8: sw          $t5, 0x20D0($at)
    MEM_W(0X20D0, ctx->r1) = ctx->r13;
    // 0x800493FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049400: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80049404: sw          $t6, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r14;
    // 0x80049408: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x8004940C: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x80049410: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80049414: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80049418: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8004941C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80049420: lw          $t9, 0x20C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20C0);
    // 0x80049424: lui         $t1, 0xDB06
    ctx->r9 = S32(0XDB06 << 16);
    // 0x80049428: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8004942C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80049430: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80049434: sw          $t0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r8;
    // 0x80049438: ori         $t1, $t1, 0x8
    ctx->r9 = ctx->r9 | 0X8;
    // 0x8004943C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80049440: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80049444: lhu         $t3, 0x20B0($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X20B0);
    // 0x80049448: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004944C: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x80049450: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80049454: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80049458: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8004945C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80049460: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80049464: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80049468: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8004946C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80049470: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80049474: sll         $t5, $t5, 7
    ctx->r13 = S32(ctx->r13 << 7);
    // 0x80049478: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8004947C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80049480: addiu       $t7, $t7, -0x5300
    ctx->r15 = ADD32(ctx->r15, -0X5300);
    // 0x80049484: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80049488: addu        $t4, $t6, $t7
    ctx->r12 = ADD32(ctx->r14, ctx->r15);
    // 0x8004948C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80049490: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x80049494: lw          $t9, 0x20C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20C0);
    // 0x80049498: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004949C: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x800494A0: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800494A4: lui         $t1, 0xDB06
    ctx->r9 = S32(0XDB06 << 16);
    // 0x800494A8: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800494AC: sw          $t0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r8;
    // 0x800494B0: ori         $t1, $t1, 0xC
    ctx->r9 = ctx->r9 | 0XC;
    // 0x800494B4: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800494B8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800494BC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800494C0: addiu       $t3, $t3, 0x400
    ctx->r11 = ADD32(ctx->r11, 0X400);
    // 0x800494C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800494C8: addu        $t5, $t3, $at
    ctx->r13 = ADD32(ctx->r11, ctx->r1);
    // 0x800494CC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800494D0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800494D4: lbu         $t7, -0x2B4($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2B4);
    // 0x800494D8: nop

    // 0x800494DC: beq         $t7, $zero, L_80049504
    if (ctx->r15 == 0) {
        // 0x800494E0: nop
    
            goto L_80049504;
    }
    // 0x800494E0: nop

    // 0x800494E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800494E8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800494EC: lhu         $a1, 0x20B0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X20B0);
    // 0x800494F0: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x800494F4: jal         0x80048A6C
    // 0x800494F8: nop

    wonders4_BuildScissoredFillRectDL(rdram, ctx);
        goto after_7;
    // 0x800494F8: nop

    after_7:
    // 0x800494FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049500: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
L_80049504:
    // 0x80049504: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80049508: lbu         $t4, -0x2B8($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2B8);
    // 0x8004950C: nop

    // 0x80049510: beq         $t4, $zero, L_80049538
    if (ctx->r12 == 0) {
        // 0x80049514: nop
    
            goto L_80049538;
    }
    // 0x80049514: nop

    // 0x80049518: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8004951C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80049520: lhu         $a1, 0x20B0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X20B0);
    // 0x80049524: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x80049528: jal         0x80048934
    // 0x8004952C: nop

    wonders4_BuildFillRectDL(rdram, ctx);
        goto after_8;
    // 0x8004952C: nop

    after_8:
    // 0x80049530: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049534: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
L_80049538:
    // 0x80049538: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8004953C: lw          $t8, 0x20C0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X20C0);
    // 0x80049540: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049544: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80049548: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8004954C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80049550: sw          $t9, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r25;
    // 0x80049554: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80049558: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8004955C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80049560: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80049564: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80049568: lw          $t3, 0x20C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20C0);
    // 0x8004956C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80049570: lw          $t6, -0x2B0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2B0);
    // 0x80049574: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x80049578: sw          $t5, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r13;
    // 0x8004957C: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80049580: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80049584: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80049588: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x8004958C: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x80049590: or          $t8, $t4, $at
    ctx->r24 = ctx->r12 | ctx->r1;
    // 0x80049594: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80049598: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8004959C: lhu         $t0, 0x20B0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X20B0);
    // 0x800495A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800495A4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800495A8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800495AC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800495B0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800495B4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800495B8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800495BC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800495C0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800495C4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800495C8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800495CC: sll         $t1, $t1, 7
    ctx->r9 = S32(ctx->r9 << 7);
    // 0x800495D0: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x800495D4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800495D8: addiu       $t3, $t3, -0x5300
    ctx->r11 = ADD32(ctx->r11, -0X5300);
    // 0x800495DC: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800495E0: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x800495E4: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800495E8: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800495EC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800495F0: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x800495F4: lw          $t8, -0x2A0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A0);
    // 0x800495F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800495FC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80049600: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x80049604: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x80049608: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004960C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80049610: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049614: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80049618: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004961C: lw          $t5, -0x29C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X29C);
    // 0x80049620: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80049624: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80049628: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8004962C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049630: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80049634: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80049638: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004963C: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80049640: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80049644: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80049648: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8004964C: andi        $t1, $t0, 0xFFF
    ctx->r9 = ctx->r8 & 0XFFF;
    // 0x80049650: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x80049654: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80049658: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8004965C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80049660: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80049664: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80049668: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004966C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80049670: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80049674: nop

    // 0x80049678: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8004967C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80049680: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80049684: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80049688: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8004968C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80049690: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80049694: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80049698: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x8004969C: or          $t8, $t3, $t4
    ctx->r24 = ctx->r11 | ctx->r12;
    // 0x800496A0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800496A4: lw          $t0, -0x298($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X298);
    // 0x800496A8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800496AC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800496B0: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800496B4: lw          $t3, -0x294($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X294);
    // 0x800496B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800496BC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800496C0: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800496C4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800496C8: lui         $t3, 0xFE00
    ctx->r11 = S32(0XFE00 << 16);
    // 0x800496CC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800496D0: nop

    // 0x800496D4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800496D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800496DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800496E0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800496E4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800496E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800496EC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800496F0: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800496F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800496F8: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x800496FC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80049700: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80049704: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80049708: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8004970C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80049710: nop

    // 0x80049714: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80049718: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004971C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80049720: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049724: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80049728: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8004972C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80049730: andi        $t0, $t9, 0xFFF
    ctx->r8 = ctx->r25 & 0XFFF;
    // 0x80049734: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80049738: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8004973C: lw          $t5, 0x20C0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20C0);
    // 0x80049740: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80049744: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80049748: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8004974C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80049750: sw          $t6, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r14;
    // 0x80049754: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80049758: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8004975C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80049760: addiu       $t8, $t8, 0x400
    ctx->r24 = ADD32(ctx->r24, 0X400);
    // 0x80049764: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80049768: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8004976C: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80049770: lw          $t0, 0x20C0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X20C0);
    // 0x80049774: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049778: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8004977C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80049780: lui         $t2, 0xDB04
    ctx->r10 = S32(0XDB04 << 16);
    // 0x80049784: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80049788: sw          $t1, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r9;
    // 0x8004978C: ori         $t2, $t2, 0x4
    ctx->r10 = ctx->r10 | 0X4;
    // 0x80049790: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x80049794: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80049798: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8004979C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800497A0: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x800497A4: lw          $t4, 0x20C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20C0);
    // 0x800497A8: lui         $t9, 0xDB04
    ctx->r25 = S32(0XDB04 << 16);
    // 0x800497AC: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800497B0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800497B4: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800497B8: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x800497BC: ori         $t9, $t9, 0xC
    ctx->r25 = ctx->r25 | 0XC;
    // 0x800497C0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800497C4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800497C8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800497CC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800497D0: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800497D4: lw          $t2, 0x20C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20C0);
    // 0x800497D8: lui         $t6, 0xDB04
    ctx->r14 = S32(0XDB04 << 16);
    // 0x800497DC: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x800497E0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800497E4: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800497E8: sw          $t5, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r13;
    // 0x800497EC: ori         $t6, $t6, 0x14
    ctx->r14 = ctx->r14 | 0X14;
    // 0x800497F0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800497F4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800497F8: ori         $t4, $zero, 0xFFFD
    ctx->r12 = 0 | 0XFFFD;
    // 0x800497FC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80049800: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x80049804: lw          $t9, 0x20C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20C0);
    // 0x80049808: lui         $t0, 0xDB04
    ctx->r8 = S32(0XDB04 << 16);
    // 0x8004980C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80049810: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80049814: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80049818: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x8004981C: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x80049820: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80049824: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80049828: ori         $t2, $zero, 0xFFFD
    ctx->r10 = 0 | 0XFFFD;
    // 0x8004982C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80049830: sw          $t2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r10;
    // 0x80049834: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80049838: lui         $t4, 0xD9D0
    ctx->r12 = S32(0XD9D0 << 16);
    // 0x8004983C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80049840: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80049844: addiu       $t3, $t6, 0x8
    ctx->r11 = ADD32(ctx->r14, 0X8);
    // 0x80049848: sw          $t3, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r11;
    // 0x8004984C: ori         $t4, $t4, 0xF9FA
    ctx->r12 = ctx->r12 | 0XF9FA;
    // 0x80049850: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80049854: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80049858: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004985C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80049860: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x80049864: lui         $t1, 0xD9FF
    ctx->r9 = S32(0XD9FF << 16);
    // 0x80049868: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8004986C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80049870: addiu       $t0, $t7, 0x8
    ctx->r8 = ADD32(ctx->r15, 0X8);
    // 0x80049874: sw          $t0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r8;
    // 0x80049878: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x8004987C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80049880: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80049884: lui         $t5, 0x22
    ctx->r13 = S32(0X22 << 16);
    // 0x80049888: ori         $t5, $t5, 0x5
    ctx->r13 = ctx->r13 | 0X5;
    // 0x8004988C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80049890: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80049894: lw          $t3, 0x20C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20C0);
    // 0x80049898: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x8004989C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800498A0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800498A4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800498A8: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x800498AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800498B0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800498B4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800498B8: addiu       $t7, $t7, -0x290
    ctx->r15 = ADD32(ctx->r15, -0X290);
    // 0x800498BC: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800498C0: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x800498C4: jal         0x8007DA00
    // 0x800498C8: nop

    func_8007DA00(rdram, ctx);
        goto after_9;
    // 0x800498C8: nop

    after_9:
    // 0x800498CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800498D0: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
    // 0x800498D4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800498D8: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x800498DC: lui         $t5, 0xE900
    ctx->r13 = S32(0XE900 << 16);
    // 0x800498E0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800498E4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800498E8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800498EC: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x800498F0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800498F4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800498F8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800498FC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80049900: lw          $t4, 0x20C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20C0);
    // 0x80049904: lui         $t9, 0xDF00
    ctx->r25 = S32(0XDF00 << 16);
    // 0x80049908: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8004990C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80049910: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x80049914: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x80049918: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8004991C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80049920: jal         0x80048020
    // 0x80049924: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    wonders4_UpdateMaxScroll(rdram, ctx);
        goto after_10;
    // 0x80049924: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_10:
    // 0x80049928: jal         0x800480E0
    // 0x8004992C: nop

    wonders4_DebugPrintGList(rdram, ctx);
        goto after_11;
    // 0x8004992C: nop

    after_11:
    // 0x80049930: jal         0x80048150
    // 0x80049934: nop

    wonders4_DebugPrintVList(rdram, ctx);
        goto after_12;
    // 0x80049934: nop

    after_12:
    // 0x80049938: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8004993C: lhu         $t2, 0x20B0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X20B0);
    // 0x80049940: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80049944: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80049948: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8004994C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80049950: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x80049954: lw          $t6, 0x20B8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20B8);
    // 0x80049958: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8004995C: subu        $t3, $t1, $t6
    ctx->r11 = SUB32(ctx->r9, ctx->r14);
    // 0x80049960: sw          $t3, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->r11;
    // 0x80049964: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80049968: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x8004996C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80049970: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80049974: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x80049978: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8004997C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80049980: nop

    // 0x80049984: sw          $t0, 0x60($t7)
    MEM_W(0X60, ctx->r15) = ctx->r8;
    // 0x80049988: jal         0x800B6650
    // 0x8004998C: sw          $t1, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->r9;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_13;
    // 0x8004998C: sw          $t1, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->r9;
    after_13:
    // 0x80049990: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80049994: jal         0x800B679C
    // 0x80049998: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_14;
    // 0x80049998: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_14:
    // 0x8004999C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800499A0: jal         0x800B692C
    // 0x800499A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_15;
    // 0x800499A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_15:
    // 0x800499A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800499AC: addiu       $a0, $a0, 0x20D8
    ctx->r4 = ADD32(ctx->r4, 0X20D8);
    // 0x800499B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800499B4: jal         0x800B3C20
    // 0x800499B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_16;
    // 0x800499B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x800499BC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800499C0: addiu       $t2, $t2, 0x31C0
    ctx->r10 = ADD32(ctx->r10, 0X31C0);
    // 0x800499C4: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x800499C8: lw          $a3, 0xC($t2)
    ctx->r7 = MEM_W(ctx->r10, 0XC);
    // 0x800499CC: jal         0x800B6970
    // 0x800499D0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    osDpSetNextBuffer_recomp(rdram, ctx);
        goto after_17;
    // 0x800499D0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_17:
    // 0x800499D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800499D8: addiu       $a0, $a0, 0x20F0
    ctx->r4 = ADD32(ctx->r4, 0X20F0);
    // 0x800499DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800499E0: jal         0x800B3C20
    // 0x800499E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_18;
    // 0x800499E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_18:
    // 0x800499E8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800499EC: lhu         $t5, 0x20B0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X20B0);
    // 0x800499F0: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x800499F4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800499F8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800499FC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80049A00: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80049A04: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80049A08: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80049A0C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80049A10: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80049A14: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80049A18: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80049A1C: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x80049A20: addiu       $t3, $t3, -0x5300
    ctx->r11 = ADD32(ctx->r11, -0X5300);
    // 0x80049A24: jal         0x800B64F0
    // 0x80049A28: addu        $a0, $t6, $t3
    ctx->r4 = ADD32(ctx->r14, ctx->r11);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_19;
    // 0x80049A28: addu        $a0, $t6, $t3
    ctx->r4 = ADD32(ctx->r14, ctx->r11);
    after_19:
    // 0x80049A2C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80049A30: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80049A34: lw          $t8, 0x2118($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2118);
    // 0x80049A38: lw          $t4, 0x2110($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2110);
    // 0x80049A3C: nop

    // 0x80049A40: slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80049A44: bne         $at, $zero, L_80049A60
    if (ctx->r1 != 0) {
        // 0x80049A48: nop
    
            goto L_80049A60;
    }
    // 0x80049A48: nop

    // 0x80049A4C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049A50: addiu       $a0, $a0, 0x2108
    ctx->r4 = ADD32(ctx->r4, 0X2108);
    // 0x80049A54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049A58: jal         0x800B3C20
    // 0x80049A5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_20;
    // 0x80049A5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
L_80049A60:
    // 0x80049A60: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049A64: addiu       $a0, $a0, 0x2108
    ctx->r4 = ADD32(ctx->r4, 0X2108);
    // 0x80049A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049A6C: jal         0x800B3C20
    // 0x80049A70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_21;
    // 0x80049A70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_21:
    // 0x80049A74: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80049A78: lhu         $t9, 0x20B0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X20B0);
    // 0x80049A7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049A80: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x80049A84: jal         0x800B6550
    // 0x80049A88: sh          $t0, 0x20B0($at)
    MEM_H(0X20B0, ctx->r1) = ctx->r8;
    osGetTime_recomp(rdram, ctx);
        goto after_22;
    // 0x80049A88: sh          $t0, 0x20B0($at)
    MEM_H(0X20B0, ctx->r1) = ctx->r8;
    after_22:
    // 0x80049A8C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80049A90: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80049A94: lw          $t7, 0x54($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X54);
    // 0x80049A98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049A9C: sw          $v0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r2;
    // 0x80049AA0: sw          $v1, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r3;
    // 0x80049AA4: lw          $t2, -0x128($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X128);
    // 0x80049AA8: nop

    // 0x80049AAC: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x80049AB0: b           L_80049388
    // 0x80049AB4: sw          $t5, -0x128($at)
    MEM_W(-0X128, ctx->r1) = ctx->r13;
        goto L_80049388;
    // 0x80049AB4: sw          $t5, -0x128($at)
    MEM_W(-0X128, ctx->r1) = ctx->r13;
    // 0x80049AB8: nop

    // 0x80049ABC: nop

    // 0x80049AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049AC4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80049AC8: jr          $ra
    // 0x80049ACC: nop

    return;
    // 0x80049ACC: nop

;}

RECOMP_FUNC void Gfx_InitViMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049AD0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80049AD4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80049AD8: jal         0x800614A8
    // 0x80049ADC: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    func_800614A8(rdram, ctx);
        goto after_0;
    // 0x80049ADC: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    after_0:
    // 0x80049AE0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049AE4: jal         0x800B3BFC
    // 0x80049AE8: addiu       $a0, $a0, -0x3FA0
    ctx->r4 = ADD32(ctx->r4, -0X3FA0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x80049AE8: addiu       $a0, $a0, -0x3FA0
    ctx->r4 = ADD32(ctx->r4, -0X3FA0);
    after_1:
    // 0x80049AEC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049AF0: addiu       $a0, $a0, -0x6A90
    ctx->r4 = ADD32(ctx->r4, -0X6A90);
    // 0x80049AF4: jal         0x800B6A20
    // 0x80049AF8: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    osViSetMode_recomp(rdram, ctx);
        goto after_2;
    // 0x80049AF8: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_2:
    // 0x80049AFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049B00: jal         0x800B3BFC
    // 0x80049B04: addiu       $a0, $a0, -0x3F98
    ctx->r4 = ADD32(ctx->r4, -0X3F98);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x80049B04: addiu       $a0, $a0, -0x3F98
    ctx->r4 = ADD32(ctx->r4, -0X3F98);
    after_3:
    // 0x80049B08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80049B0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049B10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049B14: sb          $t6, -0x1E0($at)
    MEM_B(-0X1E0, ctx->r1) = ctx->r14;
    // 0x80049B18: jal         0x800B3BFC
    // 0x80049B1C: addiu       $a0, $a0, -0x3F90
    ctx->r4 = ADD32(ctx->r4, -0X3F90);
    rmonPrintf_recomp(rdram, ctx);
        goto after_4;
    // 0x80049B1C: addiu       $a0, $a0, -0x3F90
    ctx->r4 = ADD32(ctx->r4, -0X3F90);
    after_4:
    // 0x80049B20: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80049B24: lw          $t8, 0xEB4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XEB4);
    // 0x80049B28: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80049B2C: addiu       $t7, $t7, -0x830
    ctx->r15 = ADD32(ctx->r15, -0X830);
    // 0x80049B30: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80049B34: jal         0x8007DFC0
    // 0x80049B38: subu        $a1, $t8, $t7
    ctx->r5 = SUB32(ctx->r24, ctx->r15);
    n64HeapInit(rdram, ctx);
        goto after_5;
    // 0x80049B38: subu        $a1, $t8, $t7
    ctx->r5 = SUB32(ctx->r24, ctx->r15);
    after_5:
    // 0x80049B3C: lui         $a0, 0xB
    ctx->r4 = S32(0XB << 16);
    // 0x80049B40: lui         $a1, 0xB
    ctx->r5 = S32(0XB << 16);
    // 0x80049B44: addiu       $a1, $a1, -0x2520
    ctx->r5 = ADD32(ctx->r5, -0X2520);
    // 0x80049B48: jal         0x800A9E44
    // 0x80049B4C: addiu       $a0, $a0, -0x7E70
    ctx->r4 = ADD32(ctx->r4, -0X7E70);
    func_800A9E44(rdram, ctx);
        goto after_6;
    // 0x80049B4C: addiu       $a0, $a0, -0x7E70
    ctx->r4 = ADD32(ctx->r4, -0X7E70);
    after_6:
    // 0x80049B50: jal         0x8007CF40
    // 0x80049B54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8007CF40(rdram, ctx);
        goto after_7;
    // 0x80049B54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80049B58: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049B5C: jal         0x800B3BFC
    // 0x80049B60: addiu       $a0, $a0, -0x3F88
    ctx->r4 = ADD32(ctx->r4, -0X3F88);
    rmonPrintf_recomp(rdram, ctx);
        goto after_8;
    // 0x80049B60: addiu       $a0, $a0, -0x3F88
    ctx->r4 = ADD32(ctx->r4, -0X3F88);
    after_8:
    // 0x80049B64: jal         0x80061124
    // 0x80049B68: nop

    PFGFX_SetViModeRequest(rdram, ctx);
        goto after_9;
    // 0x80049B68: nop

    after_9:
    // 0x80049B6C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80049B70: addiu       $t9, $t9, -0x5910
    ctx->r25 = ADD32(ctx->r25, -0X5910);
    // 0x80049B74: addiu       $t1, $t9, 0x48
    ctx->r9 = ADD32(ctx->r25, 0X48);
    // 0x80049B78: or          $t2, $sp, $zero
    ctx->r10 = ctx->r29 | 0;
L_80049B7C:
    // 0x80049B7C: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80049B80: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80049B84: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80049B88: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x80049B8C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80049B90: sw          $at, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r1;
    // 0x80049B94: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x80049B98: bne         $t9, $t1, L_80049B7C
    if (ctx->r25 != ctx->r9) {
        // 0x80049B9C: sw          $at, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r1;
            goto L_80049B7C;
    }
    // 0x80049B9C: sw          $at, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r1;
    // 0x80049BA0: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80049BA4: nop

    // 0x80049BA8: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80049BAC: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80049BB0: nop

    // 0x80049BB4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80049BB8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80049BBC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80049BC0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80049BC4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x80049BC8: jal         0x80060D10
    // 0x80049BCC: nop

    func_80060D10(rdram, ctx);
        goto after_10;
    // 0x80049BCC: nop

    after_10:
    // 0x80049BD0: addiu       $t3, $zero, 0x190
    ctx->r11 = ADD32(0, 0X190);
    // 0x80049BD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049BD8: sw          $t3, -0x2B0($at)
    MEM_W(-0X2B0, ctx->r1) = ctx->r11;
    // 0x80049BDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049BE0: addiu       $t4, $zero, 0x12C
    ctx->r12 = ADD32(0, 0X12C);
    // 0x80049BE4: sw          $t4, -0x2AC($at)
    MEM_W(-0X2AC, ctx->r1) = ctx->r12;
    // 0x80049BE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049BEC: sw          $zero, -0x2A0($at)
    MEM_W(-0X2A0, ctx->r1) = 0;
    // 0x80049BF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049BF4: sw          $zero, -0x29C($at)
    MEM_W(-0X29C, ctx->r1) = 0;
    // 0x80049BF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049BFC: addiu       $t5, $zero, 0x190
    ctx->r13 = ADD32(0, 0X190);
    // 0x80049C00: sw          $t5, -0x298($at)
    MEM_W(-0X298, ctx->r1) = ctx->r13;
    // 0x80049C04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049C08: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x80049C0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049C10: sw          $t6, -0x294($at)
    MEM_W(-0X294, ctx->r1) = ctx->r14;
    // 0x80049C14: jal         0x800B3BFC
    // 0x80049C18: addiu       $a0, $a0, -0x3F80
    ctx->r4 = ADD32(ctx->r4, -0X3F80);
    rmonPrintf_recomp(rdram, ctx);
        goto after_11;
    // 0x80049C18: addiu       $a0, $a0, -0x3F80
    ctx->r4 = ADD32(ctx->r4, -0X3F80);
    after_11:
    // 0x80049C1C: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    // 0x80049C20: jal         0x8006110C
    // 0x80049C24: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    PFGFX_RequestViModeChange(rdram, ctx);
        goto after_12;
    // 0x80049C24: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_12:
    // 0x80049C28: jal         0x80060E30
    // 0x80049C2C: nop

    PFGFX_ApplyViMode(rdram, ctx);
        goto after_13;
    // 0x80049C2C: nop

    after_13:
L_80049C30:
    // 0x80049C30: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80049C34: addiu       $a0, $a0, -0x44F8
    ctx->r4 = ADD32(ctx->r4, -0X44F8);
    // 0x80049C38: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80049C3C: jal         0x800B3C20
    // 0x80049C40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x80049C40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x80049C44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049C48: jal         0x800B3BFC
    // 0x80049C4C: addiu       $a0, $a0, -0x3F78
    ctx->r4 = ADD32(ctx->r4, -0X3F78);
    rmonPrintf_recomp(rdram, ctx);
        goto after_15;
    // 0x80049C4C: addiu       $a0, $a0, -0x3F78
    ctx->r4 = ADD32(ctx->r4, -0X3F78);
    after_15:
    // 0x80049C50: b           L_80049C30
    // 0x80049C54: nop

        goto L_80049C30;
    // 0x80049C54: nop

    // 0x80049C58: nop

    // 0x80049C5C: nop

    // 0x80049C60: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80049C64: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80049C68: jr          $ra
    // 0x80049C6C: nop

    return;
    // 0x80049C6C: nop

;}

RECOMP_FUNC void Gfx_SetupRenderState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BBFC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005BC00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005BC04: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8005BC08: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005BC0C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8005BC10: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8005BC14: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005BC18: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005BC1C: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x8005BC20: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8005BC24: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8005BC28: ori         $t5, $t5, 0xA01
    ctx->r13 = ctx->r13 | 0XA01;
    // 0x8005BC2C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8005BC30: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005BC34: lui         $t1, 0xD700
    ctx->r9 = S32(0XD700 << 16);
    // 0x8005BC38: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8005BC3C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005BC40: ori         $t1, $t1, 0x2
    ctx->r9 = ctx->r9 | 0X2;
    // 0x8005BC44: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8005BC48: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005BC4C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005BC50: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8005BC54: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8005BC58: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005BC5C: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x8005BC60: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8005BC64: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005BC68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005BC6C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8005BC70: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005BC74: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x8005BC78: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8005BC7C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8005BC80: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8005BC84: ori         $t8, $t8, 0x1E01
    ctx->r24 = ctx->r24 | 0X1E01;
    // 0x8005BC88: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8005BC8C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8005BC90: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005BC94: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8005BC98: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005BC9C: nop

    // 0x8005BCA0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8005BCA4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005BCA8: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x8005BCAC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005BCB0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005BCB4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8005BCB8: ori         $t5, $t5, 0xC00
    ctx->r13 = ctx->r13 | 0XC00;
    // 0x8005BCBC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8005BCC0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005BCC4: nop

    // 0x8005BCC8: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8005BCCC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005BCD0: lui         $t1, 0xE300
    ctx->r9 = S32(0XE300 << 16);
    // 0x8005BCD4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8005BCD8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005BCDC: ori         $t1, $t1, 0x1201
    ctx->r9 = ctx->r9 | 0X1201;
    // 0x8005BCE0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8005BCE4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005BCE8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005BCEC: addiu       $t3, $zero, 0x3000
    ctx->r11 = ADD32(0, 0X3000);
    // 0x8005BCF0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8005BCF4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005BCF8: nop

    // 0x8005BCFC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8005BD00: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005BD04: nop

    // 0x8005BD08: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8005BD0C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005BD10: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8005BD14: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8005BD18: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8005BD1C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005BD20: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x8005BD24: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8005BD28: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8005BD2C: addiu       $t0, $zero, 0xC00
    ctx->r8 = ADD32(0, 0XC00);
    // 0x8005BD30: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8005BD34: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005BD38: nop

    // 0x8005BD3C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005BD40: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005BD44: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x8005BD48: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005BD4C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005BD50: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8005BD54: ori         $t5, $t5, 0xD01
    ctx->r13 = ctx->r13 | 0XD01;
    // 0x8005BD58: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8005BD5C: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x8005BD60: nop

    // 0x8005BD64: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8005BD68: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005BD6C: lui         $t1, 0xE300
    ctx->r9 = S32(0XE300 << 16);
    // 0x8005BD70: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005BD74: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005BD78: ori         $t1, $t1, 0xF00
    ctx->r9 = ctx->r9 | 0XF00;
    // 0x8005BD7C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8005BD80: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005BD84: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8005BD88: nop

    // 0x8005BD8C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8005BD90: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x8005BD94: nop

    // 0x8005BD98: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8005BD9C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005BDA0: lui         $t7, 0xD9C0
    ctx->r15 = S32(0XD9C0 << 16);
    // 0x8005BDA4: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x8005BDA8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005BDAC: ori         $t7, $t7, 0xF9FA
    ctx->r15 = ctx->r15 | 0XF9FA;
    // 0x8005BDB0: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8005BDB4: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8005BDB8: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8005BDBC: nop

    // 0x8005BDC0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8005BDC4: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8005BDC8: nop

    // 0x8005BDCC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005BDD0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005BDD4: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x8005BDD8: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x8005BDDC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005BDE0: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x8005BDE4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8005BDE8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005BDEC: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8005BDF0: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x8005BDF4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005BDF8: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8005BDFC: ori         $t5, $t5, 0x4240
    ctx->r13 = ctx->r13 | 0X4240;
    // 0x8005BE00: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8005BE04: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8005BE08: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8005BE0C: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8005BE10: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005BE14: nop

    // 0x8005BE18: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8005BE1C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005BE20: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8005BE24: nop

    // 0x8005BE28: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8005BE2C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8005BE30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005BE34: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8005BE38: jr          $ra
    // 0x8005BE3C: sh          $t7, 0x164($at)
    MEM_H(0X164, ctx->r1) = ctx->r15;
    return;
    // 0x8005BE3C: sh          $t7, 0x164($at)
    MEM_H(0X164, ctx->r1) = ctx->r15;
;}

RECOMP_FUNC void Gfx_CallDisplayList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075180: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80075184: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x80075188: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007518C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80075190: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80075194: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x80075198: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8007519C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800751A0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800751A4: addiu       $t8, $t8, 0x610
    ctx->r24 = ADD32(ctx->r24, 0X610);
    // 0x800751A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800751AC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800751B0: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800751B4: sw          $a0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r4;
    // 0x800751B8: jr          $ra
    // 0x800751BC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800751BC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Gfx_PipeSyncSetOtherModeH(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800751C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800751C4: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x800751C8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800751CC: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x800751D0: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800751D4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800751D8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800751DC: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800751E0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800751E4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800751E8: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800751EC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800751F0: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800751F4: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x800751F8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800751FC: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80075200: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80075204: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80075208: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007520C: sw          $a0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r4;
    // 0x80075210: jr          $ra
    // 0x80075214: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80075214: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void Gfx_DrawScreenFade0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E750: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007E754: lwc1        $f4, 0x1E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1E4);
    // 0x8007E758: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007E75C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8007E760: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007E764: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007E768: c.le.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d <= ctx->f8.d;
    // 0x8007E76C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007E770: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007E774: bc1f        L_8007E9E4
    if (!c1cs) {
        // 0x8007E778: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8007E9E4;
    }
    // 0x8007E778: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007E77C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007E780: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x8007E784: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007E788: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8007E78C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8007E790: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007E794: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x8007E798: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007E79C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007E7A0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8007E7A4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007E7A8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007E7AC: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x8007E7B0: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x8007E7B4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8007E7B8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8007E7BC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007E7C0: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x8007E7C4: ori         $t3, $t3, 0xA01
    ctx->r11 = ctx->r11 | 0XA01;
    // 0x8007E7C8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007E7CC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8007E7D0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007E7D4: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8007E7D8: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x8007E7DC: lui         $t8, 0xD9C0
    ctx->r24 = S32(0XD9C0 << 16);
    // 0x8007E7E0: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8007E7E4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8007E7E8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007E7EC: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x8007E7F0: ori         $t8, $t8, 0xF9FA
    ctx->r24 = ctx->r24 | 0XF9FA;
    // 0x8007E7F4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007E7F8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8007E7FC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007E800: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007E804: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x8007E808: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x8007E80C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8007E810: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8007E814: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007E818: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x8007E81C: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x8007E820: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007E824: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007E828: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x8007E82C: ori         $t5, $t5, 0x4240
    ctx->r13 = ctx->r13 | 0X4240;
    // 0x8007E830: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007E834: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8007E838: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x8007E83C: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8007E840: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8007E844: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007E848: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8007E84C: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x8007E850: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8007E854: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007E858: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8007E85C: lui         $t1, 0xFFFD
    ctx->r9 = S32(0XFFFD << 16);
    // 0x8007E860: ori         $t1, $t1, 0xF6FB
    ctx->r9 = ctx->r9 | 0XF6FB;
    // 0x8007E864: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8007E868: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8007E86C: lw          $t3, 0x20C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20C0);
    // 0x8007E870: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8007E874: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8007E878: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8007E87C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007E880: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x8007E884: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007E888: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8007E88C: lwc1        $f10, 0x1E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1E4);
    // 0x8007E890: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8007E894: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007E898: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007E89C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007E8A0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007E8A4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007E8A8: nop

    // 0x8007E8AC: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007E8B0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007E8B4: nop

    // 0x8007E8B8: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8007E8BC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8007E8C0: beq         $t8, $zero, L_8007E910
    if (ctx->r24 == 0) {
        // 0x8007E8C4: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_8007E910;
    }
    // 0x8007E8C4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8007E8C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007E8CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007E8D0: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8007E8D4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007E8D8: nop

    // 0x8007E8DC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8007E8E0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007E8E4: nop

    // 0x8007E8E8: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8007E8EC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8007E8F0: bne         $t8, $zero, L_8007E908
    if (ctx->r24 != 0) {
        // 0x8007E8F4: nop
    
            goto L_8007E908;
    }
    // 0x8007E8F4: nop

    // 0x8007E8F8: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8007E8FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E900: b           L_8007E920
    // 0x8007E904: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8007E920;
    // 0x8007E904: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8007E908:
    // 0x8007E908: b           L_8007E920
    // 0x8007E90C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8007E920;
    // 0x8007E90C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8007E910:
    // 0x8007E910: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8007E914: nop

    // 0x8007E918: bltz        $t8, L_8007E908
    if (SIGNED(ctx->r24) < 0) {
        // 0x8007E91C: nop
    
            goto L_8007E908;
    }
    // 0x8007E91C: nop

L_8007E920:
    // 0x8007E920: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007E924: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8007E928: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007E92C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8007E930: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x8007E934: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007E938: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8007E93C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E940: lui         $t3, 0xF664
    ctx->r11 = S32(0XF664 << 16);
    // 0x8007E944: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007E948: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x8007E94C: ori         $t3, $t3, 0x4B0
    ctx->r11 = ctx->r11 | 0X4B0;
    // 0x8007E950: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007E954: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E958: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007E95C: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8007E960: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x8007E964: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007E968: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8007E96C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007E970: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007E974: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x8007E978: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007E97C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007E980: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007E984: jal         0x800A3AF0
    // 0x8007E988: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    frametime_delta(rdram, ctx);
        goto after_0;
    // 0x8007E988: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_0:
    // 0x8007E98C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007E990: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x8007E994: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007E998: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007E99C: lwc1        $f6, 0x1E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1E0);
    // 0x8007E9A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007E9A4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8007E9A8: lwc1        $f18, 0x1E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1E4);
    // 0x8007E9AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007E9B0: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8007E9B4: swc1        $f4, 0x1E4($at)
    MEM_W(0X1E4, ctx->r1) = ctx->f4.u32l;
    // 0x8007E9B8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007E9BC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007E9C0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8007E9C4: c.le.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d <= ctx->f8.d;
    // 0x8007E9C8: nop

    // 0x8007E9CC: bc1f        L_8007E9DC
    if (!c1cs) {
        // 0x8007E9D0: nop
    
            goto L_8007E9DC;
    }
    // 0x8007E9D0: nop

    // 0x8007E9D4: b           L_8007E9E8
    // 0x8007E9D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007E9E8;
    // 0x8007E9D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007E9DC:
    // 0x8007E9DC: b           L_8007E9E8
    // 0x8007E9E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007E9E8;
    // 0x8007E9E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007E9E4:
    // 0x8007E9E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007E9E8:
    // 0x8007E9E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E9EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007E9F0: jr          $ra
    // 0x8007E9F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007E9F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void func_8007E9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E9F8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007E9FC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8007EA00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007EA04: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8007EA08: nop

    // 0x8007EA0C: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8007EA10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007EA14: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007EA18: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007EA1C: swc1        $f10, 0x1E0($at)
    MEM_W(0X1E0, ctx->r1) = ctx->f10.u32l;
    // 0x8007EA20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007EA24: jr          $ra
    // 0x8007EA28: swc1        $f16, 0x1E4($at)
    MEM_W(0X1E4, ctx->r1) = ctx->f16.u32l;
    return;
    // 0x8007EA28: swc1        $f16, 0x1E4($at)
    MEM_W(0X1E4, ctx->r1) = ctx->f16.u32l;
;}

RECOMP_FUNC void Gfx_DrawScreenFade1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EA2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007EA30: lwc1        $f4, 0x1EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1EC);
    // 0x8007EA34: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007EA38: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007EA3C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007EA40: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8007EA44: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007EA48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007EA4C: bc1f        L_8007ECB4
    if (!c1cs) {
        // 0x8007EA50: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8007ECB4;
    }
    // 0x8007EA50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007EA54: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007EA58: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x8007EA5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007EA60: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8007EA64: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8007EA68: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007EA6C: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x8007EA70: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007EA74: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007EA78: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8007EA7C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007EA80: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007EA84: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x8007EA88: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x8007EA8C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8007EA90: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8007EA94: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007EA98: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x8007EA9C: ori         $t3, $t3, 0xA01
    ctx->r11 = ctx->r11 | 0XA01;
    // 0x8007EAA0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007EAA4: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8007EAA8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007EAAC: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8007EAB0: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x8007EAB4: lui         $t8, 0xD9C0
    ctx->r24 = S32(0XD9C0 << 16);
    // 0x8007EAB8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8007EABC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8007EAC0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007EAC4: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x8007EAC8: ori         $t8, $t8, 0xF9FA
    ctx->r24 = ctx->r24 | 0XF9FA;
    // 0x8007EACC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007EAD0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8007EAD4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007EAD8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007EADC: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x8007EAE0: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x8007EAE4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8007EAE8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8007EAEC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007EAF0: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x8007EAF4: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x8007EAF8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007EAFC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007EB00: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x8007EB04: ori         $t5, $t5, 0x4240
    ctx->r13 = ctx->r13 | 0X4240;
    // 0x8007EB08: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007EB0C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8007EB10: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x8007EB14: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8007EB18: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8007EB1C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007EB20: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8007EB24: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x8007EB28: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8007EB2C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007EB30: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8007EB34: lui         $t1, 0xFFFD
    ctx->r9 = S32(0XFFFD << 16);
    // 0x8007EB38: ori         $t1, $t1, 0xF6FB
    ctx->r9 = ctx->r9 | 0XF6FB;
    // 0x8007EB3C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8007EB40: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8007EB44: lw          $t3, 0x20C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20C0);
    // 0x8007EB48: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8007EB4C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8007EB50: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8007EB54: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007EB58: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x8007EB5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007EB60: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8007EB64: lwc1        $f10, 0x1EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1EC);
    // 0x8007EB68: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8007EB6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007EB70: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007EB74: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007EB78: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007EB7C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007EB80: nop

    // 0x8007EB84: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007EB88: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007EB8C: nop

    // 0x8007EB90: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8007EB94: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8007EB98: beq         $t8, $zero, L_8007EBE8
    if (ctx->r24 == 0) {
        // 0x8007EB9C: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_8007EBE8;
    }
    // 0x8007EB9C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8007EBA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007EBA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007EBA8: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8007EBAC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007EBB0: nop

    // 0x8007EBB4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8007EBB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007EBBC: nop

    // 0x8007EBC0: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8007EBC4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8007EBC8: bne         $t8, $zero, L_8007EBE0
    if (ctx->r24 != 0) {
        // 0x8007EBCC: nop
    
            goto L_8007EBE0;
    }
    // 0x8007EBCC: nop

    // 0x8007EBD0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8007EBD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007EBD8: b           L_8007EBF8
    // 0x8007EBDC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8007EBF8;
    // 0x8007EBDC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8007EBE0:
    // 0x8007EBE0: b           L_8007EBF8
    // 0x8007EBE4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8007EBF8;
    // 0x8007EBE4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8007EBE8:
    // 0x8007EBE8: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8007EBEC: nop

    // 0x8007EBF0: bltz        $t8, L_8007EBE0
    if (SIGNED(ctx->r24) < 0) {
        // 0x8007EBF4: nop
    
            goto L_8007EBE0;
    }
    // 0x8007EBF4: nop

L_8007EBF8:
    // 0x8007EBF8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007EBFC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8007EC00: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007EC04: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8007EC08: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x8007EC0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007EC10: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8007EC14: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EC18: lui         $t3, 0xF664
    ctx->r11 = S32(0XF664 << 16);
    // 0x8007EC1C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007EC20: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x8007EC24: ori         $t3, $t3, 0x4B0
    ctx->r11 = ctx->r11 | 0X4B0;
    // 0x8007EC28: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007EC2C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EC30: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007EC34: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8007EC38: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x8007EC3C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007EC40: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8007EC44: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007EC48: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007EC4C: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x8007EC50: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007EC54: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007EC58: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007EC5C: jal         0x800A3AF0
    // 0x8007EC60: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    frametime_delta(rdram, ctx);
        goto after_0;
    // 0x8007EC60: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_0:
    // 0x8007EC64: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007EC68: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x8007EC6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007EC70: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007EC74: lwc1        $f6, 0x1E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1E8);
    // 0x8007EC78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007EC7C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8007EC80: lwc1        $f18, 0x1EC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1EC);
    // 0x8007EC84: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007EC88: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007EC8C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8007EC90: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8007EC94: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8007EC98: swc1        $f4, 0x1EC($at)
    MEM_W(0X1EC, ctx->r1) = ctx->f4.u32l;
    // 0x8007EC9C: bc1f        L_8007ECAC
    if (!c1cs) {
        // 0x8007ECA0: nop
    
            goto L_8007ECAC;
    }
    // 0x8007ECA0: nop

    // 0x8007ECA4: b           L_8007ECB8
    // 0x8007ECA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007ECB8;
    // 0x8007ECA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007ECAC:
    // 0x8007ECAC: b           L_8007ECB8
    // 0x8007ECB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007ECB8;
    // 0x8007ECB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007ECB4:
    // 0x8007ECB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007ECB8:
    // 0x8007ECB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007ECBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007ECC0: jr          $ra
    // 0x8007ECC4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007ECC4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void func_8007ECC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ECC8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007ECCC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8007ECD0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007ECD4: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8007ECD8: nop

    // 0x8007ECDC: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8007ECE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ECE4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007ECE8: swc1        $f10, 0x1E8($at)
    MEM_W(0X1E8, ctx->r1) = ctx->f10.u32l;
    // 0x8007ECEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007ECF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007ECF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ECF8: jr          $ra
    // 0x8007ECFC: swc1        $f16, 0x1EC($at)
    MEM_W(0X1EC, ctx->r1) = ctx->f16.u32l;
    return;
    // 0x8007ECFC: swc1        $f16, 0x1EC($at)
    MEM_W(0X1EC, ctx->r1) = ctx->f16.u32l;
;}

RECOMP_FUNC void Gfx_DrawScreenFade2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ED00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ED04: lwc1        $f4, 0x1F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1F4);
    // 0x8007ED08: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007ED0C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8007ED10: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007ED14: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007ED18: c.le.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d <= ctx->f8.d;
    // 0x8007ED1C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007ED20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007ED24: bc1f        L_8007EF9C
    if (!c1cs) {
        // 0x8007ED28: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8007EF9C;
    }
    // 0x8007ED28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007ED2C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007ED30: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x8007ED34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007ED38: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8007ED3C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8007ED40: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007ED44: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x8007ED48: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007ED4C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007ED50: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8007ED54: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007ED58: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007ED5C: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x8007ED60: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x8007ED64: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8007ED68: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8007ED6C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007ED70: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x8007ED74: ori         $t3, $t3, 0xA01
    ctx->r11 = ctx->r11 | 0XA01;
    // 0x8007ED78: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007ED7C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8007ED80: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007ED84: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8007ED88: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x8007ED8C: lui         $t8, 0xD9C0
    ctx->r24 = S32(0XD9C0 << 16);
    // 0x8007ED90: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8007ED94: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8007ED98: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007ED9C: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x8007EDA0: ori         $t8, $t8, 0xF9FA
    ctx->r24 = ctx->r24 | 0XF9FA;
    // 0x8007EDA4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007EDA8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8007EDAC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007EDB0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007EDB4: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x8007EDB8: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x8007EDBC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8007EDC0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8007EDC4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007EDC8: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x8007EDCC: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x8007EDD0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007EDD4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007EDD8: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x8007EDDC: ori         $t5, $t5, 0x4240
    ctx->r13 = ctx->r13 | 0X4240;
    // 0x8007EDE0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007EDE4: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8007EDE8: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x8007EDEC: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8007EDF0: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8007EDF4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007EDF8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8007EDFC: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x8007EE00: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8007EE04: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007EE08: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8007EE0C: lui         $t1, 0xFFFD
    ctx->r9 = S32(0XFFFD << 16);
    // 0x8007EE10: ori         $t1, $t1, 0xF6FB
    ctx->r9 = ctx->r9 | 0XF6FB;
    // 0x8007EE14: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8007EE18: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8007EE1C: lw          $t3, 0x20C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20C0);
    // 0x8007EE20: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8007EE24: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8007EE28: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8007EE2C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007EE30: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x8007EE34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007EE38: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8007EE3C: lwc1        $f10, 0x1F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1F4);
    // 0x8007EE40: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8007EE44: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007EE48: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007EE4C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007EE50: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007EE54: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007EE58: nop

    // 0x8007EE5C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007EE60: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007EE64: nop

    // 0x8007EE68: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8007EE6C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8007EE70: beq         $t8, $zero, L_8007EEC0
    if (ctx->r24 == 0) {
        // 0x8007EE74: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_8007EEC0;
    }
    // 0x8007EE74: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8007EE78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007EE7C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007EE80: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8007EE84: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007EE88: nop

    // 0x8007EE8C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8007EE90: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007EE94: nop

    // 0x8007EE98: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8007EE9C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8007EEA0: bne         $t8, $zero, L_8007EEB8
    if (ctx->r24 != 0) {
        // 0x8007EEA4: nop
    
            goto L_8007EEB8;
    }
    // 0x8007EEA4: nop

    // 0x8007EEA8: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8007EEAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007EEB0: b           L_8007EED0
    // 0x8007EEB4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8007EED0;
    // 0x8007EEB4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8007EEB8:
    // 0x8007EEB8: b           L_8007EED0
    // 0x8007EEBC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8007EED0;
    // 0x8007EEBC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8007EEC0:
    // 0x8007EEC0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8007EEC4: nop

    // 0x8007EEC8: bltz        $t8, L_8007EEB8
    if (SIGNED(ctx->r24) < 0) {
        // 0x8007EECC: nop
    
            goto L_8007EEB8;
    }
    // 0x8007EECC: nop

L_8007EED0:
    // 0x8007EED0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007EED4: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8007EED8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8007EEDC: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x8007EEE0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007EEE4: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8007EEE8: lw          $t2, 0x20C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20C0);
    // 0x8007EEEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007EEF0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8007EEF4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EEF8: lui         $t4, 0xF664
    ctx->r12 = S32(0XF664 << 16);
    // 0x8007EEFC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8007EF00: sw          $t3, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r11;
    // 0x8007EF04: ori         $t4, $t4, 0x4B0
    ctx->r12 = ctx->r12 | 0X4B0;
    // 0x8007EF08: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8007EF0C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EF10: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007EF14: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007EF18: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8007EF1C: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x8007EF20: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007EF24: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007EF28: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007EF2C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8007EF30: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x8007EF34: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007EF38: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007EF3C: jal         0x800A3AF0
    // 0x8007EF40: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    frametime_delta(rdram, ctx);
        goto after_0;
    // 0x8007EF40: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_0:
    // 0x8007EF44: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007EF48: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x8007EF4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007EF50: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007EF54: lwc1        $f6, 0x1F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1F0);
    // 0x8007EF58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007EF5C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8007EF60: lwc1        $f18, 0x1F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1F4);
    // 0x8007EF64: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007EF68: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8007EF6C: swc1        $f4, 0x1F4($at)
    MEM_W(0X1F4, ctx->r1) = ctx->f4.u32l;
    // 0x8007EF70: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007EF74: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007EF78: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8007EF7C: c.le.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d <= ctx->f8.d;
    // 0x8007EF80: nop

    // 0x8007EF84: bc1f        L_8007EF94
    if (!c1cs) {
        // 0x8007EF88: nop
    
            goto L_8007EF94;
    }
    // 0x8007EF88: nop

    // 0x8007EF8C: b           L_8007EFA0
    // 0x8007EF90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007EFA0;
    // 0x8007EF90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007EF94:
    // 0x8007EF94: b           L_8007EFA0
    // 0x8007EF98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007EFA0;
    // 0x8007EF98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007EF9C:
    // 0x8007EF9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007EFA0:
    // 0x8007EFA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007EFA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007EFA8: jr          $ra
    // 0x8007EFAC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007EFAC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void func_8007EFB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EFB0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007EFB4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8007EFB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007EFBC: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8007EFC0: nop

    // 0x8007EFC4: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8007EFC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007EFCC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007EFD0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007EFD4: swc1        $f10, 0x1F0($at)
    MEM_W(0X1F0, ctx->r1) = ctx->f10.u32l;
    // 0x8007EFD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007EFDC: jr          $ra
    // 0x8007EFE0: swc1        $f16, 0x1F4($at)
    MEM_W(0X1F4, ctx->r1) = ctx->f16.u32l;
    return;
    // 0x8007EFE0: swc1        $f16, 0x1F4($at)
    MEM_W(0X1F4, ctx->r1) = ctx->f16.u32l;
;}

RECOMP_FUNC void Gfx_DrawScreenFade3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EFE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007EFE8: lwc1        $f4, 0x1FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1FC);
    // 0x8007EFEC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007EFF0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007EFF4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007EFF8: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8007EFFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007F000: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007F004: bc1f        L_8007F274
    if (!c1cs) {
        // 0x8007F008: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8007F274;
    }
    // 0x8007F008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007F00C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007F010: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x8007F014: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007F018: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8007F01C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8007F020: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007F024: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x8007F028: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007F02C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007F030: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8007F034: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007F038: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007F03C: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x8007F040: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x8007F044: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8007F048: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8007F04C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007F050: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x8007F054: ori         $t3, $t3, 0xA01
    ctx->r11 = ctx->r11 | 0XA01;
    // 0x8007F058: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007F05C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8007F060: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007F064: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8007F068: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x8007F06C: lui         $t8, 0xD9C0
    ctx->r24 = S32(0XD9C0 << 16);
    // 0x8007F070: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8007F074: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8007F078: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007F07C: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x8007F080: ori         $t8, $t8, 0xF9FA
    ctx->r24 = ctx->r24 | 0XF9FA;
    // 0x8007F084: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007F088: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8007F08C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007F090: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007F094: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x8007F098: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x8007F09C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8007F0A0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8007F0A4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007F0A8: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x8007F0AC: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x8007F0B0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007F0B4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007F0B8: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x8007F0BC: ori         $t5, $t5, 0x4240
    ctx->r13 = ctx->r13 | 0X4240;
    // 0x8007F0C0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007F0C4: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8007F0C8: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x8007F0CC: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8007F0D0: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8007F0D4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007F0D8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8007F0DC: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x8007F0E0: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8007F0E4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007F0E8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8007F0EC: lui         $t1, 0xFFFD
    ctx->r9 = S32(0XFFFD << 16);
    // 0x8007F0F0: ori         $t1, $t1, 0xF6FB
    ctx->r9 = ctx->r9 | 0XF6FB;
    // 0x8007F0F4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8007F0F8: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8007F0FC: lw          $t3, 0x20C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20C0);
    // 0x8007F100: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8007F104: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8007F108: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8007F10C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007F110: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x8007F114: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007F118: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8007F11C: lwc1        $f10, 0x1FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1FC);
    // 0x8007F120: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8007F124: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007F128: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007F12C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007F130: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007F134: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007F138: nop

    // 0x8007F13C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007F140: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007F144: nop

    // 0x8007F148: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8007F14C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8007F150: beq         $t8, $zero, L_8007F1A0
    if (ctx->r24 == 0) {
        // 0x8007F154: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_8007F1A0;
    }
    // 0x8007F154: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8007F158: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007F15C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007F160: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8007F164: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007F168: nop

    // 0x8007F16C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8007F170: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007F174: nop

    // 0x8007F178: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8007F17C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8007F180: bne         $t8, $zero, L_8007F198
    if (ctx->r24 != 0) {
        // 0x8007F184: nop
    
            goto L_8007F198;
    }
    // 0x8007F184: nop

    // 0x8007F188: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8007F18C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F190: b           L_8007F1B0
    // 0x8007F194: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8007F1B0;
    // 0x8007F194: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8007F198:
    // 0x8007F198: b           L_8007F1B0
    // 0x8007F19C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8007F1B0;
    // 0x8007F19C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8007F1A0:
    // 0x8007F1A0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8007F1A4: nop

    // 0x8007F1A8: bltz        $t8, L_8007F198
    if (SIGNED(ctx->r24) < 0) {
        // 0x8007F1AC: nop
    
            goto L_8007F198;
    }
    // 0x8007F1AC: nop

L_8007F1B0:
    // 0x8007F1B0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007F1B4: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8007F1B8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8007F1BC: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x8007F1C0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007F1C4: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8007F1C8: lw          $t2, 0x20C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20C0);
    // 0x8007F1CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007F1D0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8007F1D4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007F1D8: lui         $t4, 0xF664
    ctx->r12 = S32(0XF664 << 16);
    // 0x8007F1DC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8007F1E0: sw          $t3, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r11;
    // 0x8007F1E4: ori         $t4, $t4, 0x4B0
    ctx->r12 = ctx->r12 | 0X4B0;
    // 0x8007F1E8: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8007F1EC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007F1F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007F1F4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007F1F8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8007F1FC: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x8007F200: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007F204: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007F208: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007F20C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8007F210: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x8007F214: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007F218: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007F21C: jal         0x800A3AF0
    // 0x8007F220: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    frametime_delta(rdram, ctx);
        goto after_0;
    // 0x8007F220: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_0:
    // 0x8007F224: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F228: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x8007F22C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007F230: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007F234: lwc1        $f6, 0x1F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1F8);
    // 0x8007F238: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007F23C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8007F240: lwc1        $f18, 0x1FC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1FC);
    // 0x8007F244: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007F248: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007F24C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8007F250: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8007F254: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8007F258: swc1        $f4, 0x1FC($at)
    MEM_W(0X1FC, ctx->r1) = ctx->f4.u32l;
    // 0x8007F25C: bc1f        L_8007F26C
    if (!c1cs) {
        // 0x8007F260: nop
    
            goto L_8007F26C;
    }
    // 0x8007F260: nop

    // 0x8007F264: b           L_8007F278
    // 0x8007F268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007F278;
    // 0x8007F268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007F26C:
    // 0x8007F26C: b           L_8007F278
    // 0x8007F270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007F278;
    // 0x8007F270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007F274:
    // 0x8007F274: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007F278:
    // 0x8007F278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007F27C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007F280: jr          $ra
    // 0x8007F284: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007F284: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void func_8007F288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F288: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007F28C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8007F290: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007F294: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8007F298: nop

    // 0x8007F29C: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8007F2A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007F2A4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007F2A8: swc1        $f10, 0x1F8($at)
    MEM_W(0X1F8, ctx->r1) = ctx->f10.u32l;
    // 0x8007F2AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007F2B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007F2B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007F2B8: jr          $ra
    // 0x8007F2BC: swc1        $f16, 0x1FC($at)
    MEM_W(0X1FC, ctx->r1) = ctx->f16.u32l;
    return;
    // 0x8007F2BC: swc1        $f16, 0x1FC($at)
    MEM_W(0X1FC, ctx->r1) = ctx->f16.u32l;
;}

RECOMP_FUNC void func_8007F2C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F2C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007F2C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007F2C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007F2CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F2D0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8007F2D4: sb          $t6, -0x2B4($at)
    MEM_B(-0X2B4, ctx->r1) = ctx->r14;
    // 0x8007F2D8: addiu       $a0, $a0, 0x31A0
    ctx->r4 = ADD32(ctx->r4, 0X31A0);
    // 0x8007F2DC: jal         0x80076EC0
    // 0x8007F2E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    CubeTiles_ObjCreate(rdram, ctx);
        goto after_0;
    // 0x8007F2E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8007F2E4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8007F2E8: lw          $a0, 0x31A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31A0);
    // 0x8007F2EC: jal         0x800A4654
    // 0x8007F2F0: nop

    wonders1_ObjClearFlag80(rdram, ctx);
        goto after_1;
    // 0x8007F2F0: nop

    after_1:
    // 0x8007F2F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F2F8: jal         0x80087784
    // 0x8007F2FC: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    Audio2_GFXDone_SendPlayMessage(rdram, ctx);
        goto after_2;
    // 0x8007F2FC: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    after_2:
    // 0x8007F300: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8007F304: jal         0x80085030
    // 0x8007F308: addiu       $a0, $a0, 0x3B28
    ctx->r4 = ADD32(ctx->r4, 0X3B28);
    Audio_LoadSFX(rdram, ctx);
        goto after_3;
    // 0x8007F308: addiu       $a0, $a0, 0x3B28
    ctx->r4 = ADD32(ctx->r4, 0X3B28);
    after_3:
    // 0x8007F30C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007F310: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F314: sw          $zero, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = 0;
    // 0x8007F318: jr          $ra
    // 0x8007F31C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007F31C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void func_8007F320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007F324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007F328: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8007F32C: jal         0x80077028
    // 0x8007F330: addiu       $a0, $a0, 0x31A0
    ctx->r4 = ADD32(ctx->r4, 0X31A0);
    CubeTiles_ObjFree(rdram, ctx);
        goto after_0;
    // 0x8007F330: addiu       $a0, $a0, 0x31A0
    ctx->r4 = ADD32(ctx->r4, 0X31A0);
    after_0:
    // 0x8007F334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007F338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007F33C: jr          $ra
    // 0x8007F340: nop

    return;
    // 0x8007F340: nop

;}

RECOMP_FUNC void func_8007F344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F344: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007F348: lw          $t6, 0x31DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31DC);
    // 0x8007F34C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007F350: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007F354: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x8007F358: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8007F35C: beq         $at, $zero, L_8007F6DC
    if (ctx->r1 == 0) {
        // 0x8007F360: sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
            goto L_8007F6DC;
    }
    // 0x8007F360: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8007F364: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007F368: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007F36C: addu        $at, $at, $t7
    gpr jr_addend_8007F378 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007F370: lw          $t7, -0x1EB0($at)
    ctx->r15 = ADD32(ctx->r1, -0X1EB0);
    // 0x8007F374: nop

    // 0x8007F378: jr          $t7
    // 0x8007F37C: nop

    switch (jr_addend_8007F378 >> 2) {
        case 0: goto L_8007F380; break;
        case 1: goto L_8007F3C8; break;
        case 2: goto L_8007F410; break;
        case 3: goto L_8007F458; break;
        case 4: goto L_8007F4A0; break;
        case 5: goto L_8007F4E8; break;
        case 6: goto L_8007F530; break;
        case 7: goto L_8007F578; break;
        case 8: goto L_8007F5C0; break;
        case 9: goto L_8007F608; break;
        case 10: goto L_8007F650; break;
        case 11: goto L_8007F698; break;
        default: switch_error(__func__, 0x8007F378, 0x800DE150);
    }
    // 0x8007F37C: nop

L_8007F380:
    // 0x8007F380: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8007F384: lw          $t8, 0x31A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X31A0);
    // 0x8007F388: nop

    // 0x8007F38C: lhu         $t9, 0x6($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6);
    // 0x8007F390: nop

    // 0x8007F394: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x8007F398: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F39C: nop
    
            goto L_8007F6DC;
    }
    // 0x8007F39C: nop

    // 0x8007F3A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F3A4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007F3A8: addiu       $a1, $a1, 0x3B28
    ctx->r5 = ADD32(ctx->r5, 0X3B28);
    // 0x8007F3AC: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8007F3B0: jal         0x8008A5C8
    // 0x8007F3B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio2_Play_SFX(rdram, ctx);
        goto after_0;
    // 0x8007F3B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8007F3B8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8007F3BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F3C0: b           L_8007F6DC
    // 0x8007F3C4: sw          $t0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r8;
        goto L_8007F6DC;
    // 0x8007F3C4: sw          $t0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r8;
L_8007F3C8:
    // 0x8007F3C8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007F3CC: lw          $t1, 0x31A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X31A0);
    // 0x8007F3D0: nop

    // 0x8007F3D4: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8007F3D8: nop

    // 0x8007F3DC: slti        $at, $t2, 0x330
    ctx->r1 = SIGNED(ctx->r10) < 0X330 ? 1 : 0;
    // 0x8007F3E0: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F3E4: nop
    
            goto L_8007F6DC;
    }
    // 0x8007F3E4: nop

    // 0x8007F3E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F3EC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007F3F0: addiu       $a1, $a1, 0x3B28
    ctx->r5 = ADD32(ctx->r5, 0X3B28);
    // 0x8007F3F4: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8007F3F8: jal         0x8008A5C8
    // 0x8007F3FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Audio2_Play_SFX(rdram, ctx);
        goto after_1;
    // 0x8007F3FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8007F400: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8007F404: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F408: b           L_8007F6DC
    // 0x8007F40C: sw          $t3, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r11;
        goto L_8007F6DC;
    // 0x8007F40C: sw          $t3, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r11;
L_8007F410:
    // 0x8007F410: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8007F414: lw          $t4, 0x31A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X31A0);
    // 0x8007F418: nop

    // 0x8007F41C: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8007F420: nop

    // 0x8007F424: slti        $at, $t5, 0x42B
    ctx->r1 = SIGNED(ctx->r13) < 0X42B ? 1 : 0;
    // 0x8007F428: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F42C: nop
    
            goto L_8007F6DC;
    }
    // 0x8007F42C: nop

    // 0x8007F430: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F434: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007F438: addiu       $a1, $a1, 0x3B28
    ctx->r5 = ADD32(ctx->r5, 0X3B28);
    // 0x8007F43C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8007F440: jal         0x8008A5C8
    // 0x8007F444: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    Audio2_Play_SFX(rdram, ctx);
        goto after_2;
    // 0x8007F444: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x8007F448: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8007F44C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F450: b           L_8007F6DC
    // 0x8007F454: sw          $t6, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r14;
        goto L_8007F6DC;
    // 0x8007F454: sw          $t6, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r14;
L_8007F458:
    // 0x8007F458: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8007F45C: lw          $t7, 0x31A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X31A0);
    // 0x8007F460: nop

    // 0x8007F464: lhu         $t8, 0x6($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X6);
    // 0x8007F468: nop

    // 0x8007F46C: slti        $at, $t8, 0x4F8
    ctx->r1 = SIGNED(ctx->r24) < 0X4F8 ? 1 : 0;
    // 0x8007F470: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F474: nop
    
            goto L_8007F6DC;
    }
    // 0x8007F474: nop

    // 0x8007F478: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F47C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007F480: addiu       $a1, $a1, 0x3B28
    ctx->r5 = ADD32(ctx->r5, 0X3B28);
    // 0x8007F484: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8007F488: jal         0x8008A5C8
    // 0x8007F48C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    Audio2_Play_SFX(rdram, ctx);
        goto after_3;
    // 0x8007F48C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x8007F490: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8007F494: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F498: b           L_8007F6DC
    // 0x8007F49C: sw          $t9, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r25;
        goto L_8007F6DC;
    // 0x8007F49C: sw          $t9, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r25;
L_8007F4A0:
    // 0x8007F4A0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8007F4A4: lw          $t0, 0x31A0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X31A0);
    // 0x8007F4A8: nop

    // 0x8007F4AC: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x8007F4B0: nop

    // 0x8007F4B4: slti        $at, $t1, 0x645
    ctx->r1 = SIGNED(ctx->r9) < 0X645 ? 1 : 0;
    // 0x8007F4B8: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F4BC: nop
    
            goto L_8007F6DC;
    }
    // 0x8007F4BC: nop

    // 0x8007F4C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F4C4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007F4C8: addiu       $a1, $a1, 0x3B28
    ctx->r5 = ADD32(ctx->r5, 0X3B28);
    // 0x8007F4CC: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8007F4D0: jal         0x8008A5C8
    // 0x8007F4D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio2_Play_SFX(rdram, ctx);
        goto after_4;
    // 0x8007F4D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x8007F4D8: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8007F4DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F4E0: b           L_8007F6DC
    // 0x8007F4E4: sw          $t2, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r10;
        goto L_8007F6DC;
    // 0x8007F4E4: sw          $t2, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r10;
L_8007F4E8:
    // 0x8007F4E8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8007F4EC: lw          $t3, 0x31A0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X31A0);
    // 0x8007F4F0: nop

    // 0x8007F4F4: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x8007F4F8: nop

    // 0x8007F4FC: slti        $at, $t4, 0x75D
    ctx->r1 = SIGNED(ctx->r12) < 0X75D ? 1 : 0;
    // 0x8007F500: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F504: nop
    
            goto L_8007F6DC;
    }
    // 0x8007F504: nop

    // 0x8007F508: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F50C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007F510: addiu       $a1, $a1, 0x3B28
    ctx->r5 = ADD32(ctx->r5, 0X3B28);
    // 0x8007F514: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8007F518: jal         0x8008A5C8
    // 0x8007F51C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    Audio2_Play_SFX(rdram, ctx);
        goto after_5;
    // 0x8007F51C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_5:
    // 0x8007F520: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x8007F524: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F528: b           L_8007F6DC
    // 0x8007F52C: sw          $t5, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r13;
        goto L_8007F6DC;
    // 0x8007F52C: sw          $t5, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r13;
L_8007F530:
    // 0x8007F530: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007F534: lw          $t6, 0x31A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31A0);
    // 0x8007F538: nop

    // 0x8007F53C: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x8007F540: nop

    // 0x8007F544: slti        $at, $t7, 0x80C
    ctx->r1 = SIGNED(ctx->r15) < 0X80C ? 1 : 0;
    // 0x8007F548: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F54C: nop
    
            goto L_8007F6DC;
    }
    // 0x8007F54C: nop

    // 0x8007F550: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F554: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007F558: addiu       $a1, $a1, 0x3B28
    ctx->r5 = ADD32(ctx->r5, 0X3B28);
    // 0x8007F55C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8007F560: jal         0x8008A5C8
    // 0x8007F564: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    Audio2_Play_SFX(rdram, ctx);
        goto after_6;
    // 0x8007F564: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_6:
    // 0x8007F568: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8007F56C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F570: b           L_8007F6DC
    // 0x8007F574: sw          $t8, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r24;
        goto L_8007F6DC;
    // 0x8007F574: sw          $t8, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r24;
L_8007F578:
    // 0x8007F578: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8007F57C: lw          $t9, 0x31A0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X31A0);
    // 0x8007F580: nop

    // 0x8007F584: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8007F588: nop

    // 0x8007F58C: slti        $at, $t0, 0xAAD
    ctx->r1 = SIGNED(ctx->r8) < 0XAAD ? 1 : 0;
    // 0x8007F590: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F594: nop
    
            goto L_8007F6DC;
    }
    // 0x8007F594: nop

    // 0x8007F598: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F59C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007F5A0: addiu       $a1, $a1, 0x3B28
    ctx->r5 = ADD32(ctx->r5, 0X3B28);
    // 0x8007F5A4: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8007F5A8: jal         0x8008A5C8
    // 0x8007F5AC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    Audio2_Play_SFX(rdram, ctx);
        goto after_7;
    // 0x8007F5AC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_7:
    // 0x8007F5B0: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x8007F5B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F5B8: b           L_8007F6DC
    // 0x8007F5BC: sw          $t1, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r9;
        goto L_8007F6DC;
    // 0x8007F5BC: sw          $t1, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r9;
L_8007F5C0:
    // 0x8007F5C0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8007F5C4: lw          $t2, 0x31A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X31A0);
    // 0x8007F5C8: nop

    // 0x8007F5CC: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x8007F5D0: nop

    // 0x8007F5D4: slti        $at, $t3, 0xAE5
    ctx->r1 = SIGNED(ctx->r11) < 0XAE5 ? 1 : 0;
    // 0x8007F5D8: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F5DC: nop
    
            goto L_8007F6DC;
    }
    // 0x8007F5DC: nop

    // 0x8007F5E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F5E4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007F5E8: addiu       $a1, $a1, 0x3B28
    ctx->r5 = ADD32(ctx->r5, 0X3B28);
    // 0x8007F5EC: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8007F5F0: jal         0x8008A5C8
    // 0x8007F5F4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Audio2_Play_SFX(rdram, ctx);
        goto after_8;
    // 0x8007F5F4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_8:
    // 0x8007F5F8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8007F5FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F600: b           L_8007F6DC
    // 0x8007F604: sw          $t4, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r12;
        goto L_8007F6DC;
    // 0x8007F604: sw          $t4, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r12;
L_8007F608:
    // 0x8007F608: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8007F60C: lw          $t5, 0x31A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X31A0);
    // 0x8007F610: nop

    // 0x8007F614: lhu         $t6, 0x6($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X6);
    // 0x8007F618: nop

    // 0x8007F61C: slti        $at, $t6, 0xBAB
    ctx->r1 = SIGNED(ctx->r14) < 0XBAB ? 1 : 0;
    // 0x8007F620: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F624: nop
    
            goto L_8007F6DC;
    }
    // 0x8007F624: nop

    // 0x8007F628: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F62C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007F630: addiu       $a1, $a1, 0x3B28
    ctx->r5 = ADD32(ctx->r5, 0X3B28);
    // 0x8007F634: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8007F638: jal         0x8008A5C8
    // 0x8007F63C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    Audio2_Play_SFX(rdram, ctx);
        goto after_9;
    // 0x8007F63C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_9:
    // 0x8007F640: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8007F644: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F648: b           L_8007F6DC
    // 0x8007F64C: sw          $t7, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r15;
        goto L_8007F6DC;
    // 0x8007F64C: sw          $t7, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r15;
L_8007F650:
    // 0x8007F650: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8007F654: lw          $t8, 0x31A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X31A0);
    // 0x8007F658: nop

    // 0x8007F65C: lhu         $t9, 0x6($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6);
    // 0x8007F660: nop

    // 0x8007F664: slti        $at, $t9, 0xD0C
    ctx->r1 = SIGNED(ctx->r25) < 0XD0C ? 1 : 0;
    // 0x8007F668: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F66C: nop
    
            goto L_8007F6DC;
    }
    // 0x8007F66C: nop

    // 0x8007F670: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F674: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007F678: addiu       $a1, $a1, 0x3B28
    ctx->r5 = ADD32(ctx->r5, 0X3B28);
    // 0x8007F67C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8007F680: jal         0x8008A5C8
    // 0x8007F684: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    Audio2_Play_SFX(rdram, ctx);
        goto after_10;
    // 0x8007F684: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_10:
    // 0x8007F688: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8007F68C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F690: b           L_8007F6DC
    // 0x8007F694: sw          $t0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r8;
        goto L_8007F6DC;
    // 0x8007F694: sw          $t0, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r8;
L_8007F698:
    // 0x8007F698: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007F69C: lw          $t1, 0x31A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X31A0);
    // 0x8007F6A0: nop

    // 0x8007F6A4: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8007F6A8: nop

    // 0x8007F6AC: slti        $at, $t2, 0xEA6
    ctx->r1 = SIGNED(ctx->r10) < 0XEA6 ? 1 : 0;
    // 0x8007F6B0: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F6B4: nop
    
            goto L_8007F6DC;
    }
    // 0x8007F6B4: nop

    // 0x8007F6B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F6BC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007F6C0: addiu       $a1, $a1, 0x3B28
    ctx->r5 = ADD32(ctx->r5, 0X3B28);
    // 0x8007F6C4: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8007F6C8: jal         0x8008A5C8
    // 0x8007F6CC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    Audio2_Play_SFX(rdram, ctx);
        goto after_11;
    // 0x8007F6CC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_11:
    // 0x8007F6D0: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x8007F6D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F6D8: sw          $t3, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r11;
L_8007F6DC:
    // 0x8007F6DC: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8007F6E0: lw          $t4, 0x31D8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X31D8);
    // 0x8007F6E4: nop

    // 0x8007F6E8: bne         $t4, $zero, L_8007F7B4
    if (ctx->r12 != 0) {
        // 0x8007F6EC: nop
    
            goto L_8007F7B4;
    }
    // 0x8007F6EC: nop

    // 0x8007F6F0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8007F6F4: lw          $t5, 0x31E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X31E0);
    // 0x8007F6F8: nop

    // 0x8007F6FC: beq         $t5, $zero, L_8007F720
    if (ctx->r13 == 0) {
        // 0x8007F700: nop
    
            goto L_8007F720;
    }
    // 0x8007F700: nop

    // 0x8007F704: jal         0x8007F2C0
    // 0x8007F708: nop

    func_8007F2C0(rdram, ctx);
        goto after_12;
    // 0x8007F708: nop

    after_12:
    // 0x8007F70C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007F710: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F714: sw          $t6, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r14;
    // 0x8007F718: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F71C: sw          $zero, 0x31E0($at)
    MEM_W(0X31E0, ctx->r1) = 0;
L_8007F720:
    // 0x8007F720: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007F724: addiu       $t7, $t7, -0x10D0
    ctx->r15 = ADD32(ctx->r15, -0X10D0);
    // 0x8007F728: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x8007F72C: nop

    // 0x8007F730: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8007F734: bne         $t9, $zero, L_8007F768
    if (ctx->r25 != 0) {
        // 0x8007F738: nop
    
            goto L_8007F768;
    }
    // 0x8007F738: nop

    // 0x8007F73C: andi        $t0, $t8, 0x1000
    ctx->r8 = ctx->r24 & 0X1000;
    // 0x8007F740: bne         $t0, $zero, L_8007F768
    if (ctx->r8 != 0) {
        // 0x8007F744: nop
    
            goto L_8007F768;
    }
    // 0x8007F744: nop

    // 0x8007F748: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007F74C: lw          $t1, 0x31A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X31A0);
    // 0x8007F750: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8007F754: lw          $t3, 0x31D0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X31D0);
    // 0x8007F758: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8007F75C: nop

    // 0x8007F760: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007F764: bne         $at, $zero, L_8007F7A8
    if (ctx->r1 != 0) {
        // 0x8007F768: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8007F7A8;
    }
L_8007F768:
    // 0x8007F768: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8007F76C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8007F770: jal         0x8007EFB0
    // 0x8007F774: nop

    func_8007EFB0(rdram, ctx);
        goto after_13;
    // 0x8007F774: nop

    after_13:
    // 0x8007F778: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x8007F77C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F780: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007F784: sw          $t4, 0x31DC($at)
    MEM_W(0X31DC, ctx->r1) = ctx->r12;
    // 0x8007F788: jal         0x80088C14
    // 0x8007F78C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    Audio2_GFXDone_SendStopMessage(rdram, ctx);
        goto after_14;
    // 0x8007F78C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    after_14:
    // 0x8007F790: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007F794: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F798: sw          $t5, 0x31E0($at)
    MEM_W(0X31E0, ctx->r1) = ctx->r13;
    // 0x8007F79C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F7A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007F7A4: sw          $t6, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = ctx->r14;
L_8007F7A8:
    // 0x8007F7A8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8007F7AC: jal         0x80077098
    // 0x8007F7B0: addiu       $a0, $a0, 0x31A0
    ctx->r4 = ADD32(ctx->r4, 0X31A0);
    CubeTiles_ObjDraw(rdram, ctx);
        goto after_15;
    // 0x8007F7B0: addiu       $a0, $a0, 0x31A0
    ctx->r4 = ADD32(ctx->r4, 0X31A0);
    after_15:
L_8007F7B4:
    // 0x8007F7B4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8007F7B8: lw          $t7, 0x31D8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X31D8);
    // 0x8007F7BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007F7C0: bne         $t7, $at, L_8007F830
    if (ctx->r15 != ctx->r1) {
        // 0x8007F7C4: nop
    
            goto L_8007F830;
    }
    // 0x8007F7C4: nop

    // 0x8007F7C8: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8007F7CC: lw          $t9, 0x31E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X31E0);
    // 0x8007F7D0: nop

    // 0x8007F7D4: beq         $t9, $zero, L_8007F7E4
    if (ctx->r25 == 0) {
        // 0x8007F7D8: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8007F7E4;
    }
    // 0x8007F7D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F7DC: b           L_8007F7F0
    // 0x8007F7E0: sw          $zero, 0x31E0($at)
    MEM_W(0X31E0, ctx->r1) = 0;
        goto L_8007F7F0;
    // 0x8007F7E0: sw          $zero, 0x31E0($at)
    MEM_W(0X31E0, ctx->r1) = 0;
L_8007F7E4:
    // 0x8007F7E4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8007F7E8: jal         0x80077098
    // 0x8007F7EC: addiu       $a0, $a0, 0x31A0
    ctx->r4 = ADD32(ctx->r4, 0X31A0);
    CubeTiles_ObjDraw(rdram, ctx);
        goto after_16;
    // 0x8007F7EC: addiu       $a0, $a0, 0x31A0
    ctx->r4 = ADD32(ctx->r4, 0X31A0);
    after_16:
L_8007F7F0:
    // 0x8007F7F0: jal         0x8007ED00
    // 0x8007F7F4: nop

    Gfx_DrawScreenFade2(rdram, ctx);
        goto after_17;
    // 0x8007F7F4: nop

    after_17:
    // 0x8007F7F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007F7FC: bne         $v0, $at, L_8007F830
    if (ctx->r2 != ctx->r1) {
        // 0x8007F800: nop
    
            goto L_8007F830;
    }
    // 0x8007F800: nop

    // 0x8007F804: jal         0x8004A34C
    // 0x8007F808: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_18;
    // 0x8007F808: nop

    after_18:
    // 0x8007F80C: jal         0x8007F320
    // 0x8007F810: nop

    func_8007F320(rdram, ctx);
        goto after_19;
    // 0x8007F810: nop

    after_19:
    // 0x8007F814: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007F818: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F81C: sw          $t8, 0x31E0($at)
    MEM_W(0X31E0, ctx->r1) = ctx->r24;
    // 0x8007F820: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F824: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8007F828: b           L_8007FBA0
    // 0x8007F82C: sw          $t0, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = ctx->r8;
        goto L_8007FBA0;
    // 0x8007F82C: sw          $t0, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = ctx->r8;
L_8007F830:
    // 0x8007F830: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007F834: lw          $t1, 0x31D8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X31D8);
    // 0x8007F838: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007F83C: bne         $t1, $at, L_8007F910
    if (ctx->r9 != ctx->r1) {
        // 0x8007F840: nop
    
            goto L_8007F910;
    }
    // 0x8007F840: nop

    // 0x8007F844: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8007F848: lw          $t2, 0x31E0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X31E0);
    // 0x8007F84C: nop

    // 0x8007F850: beq         $t2, $zero, L_8007F910
    if (ctx->r10 == 0) {
        // 0x8007F854: nop
    
            goto L_8007F910;
    }
    // 0x8007F854: nop

    // 0x8007F858: jal         0x8004A34C
    // 0x8007F85C: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_20;
    // 0x8007F85C: nop

    after_20:
    // 0x8007F860: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8007F864: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x8007F868: jal         0x80074888
    // 0x8007F86C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_21;
    // 0x8007F86C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x8007F870: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F874: jal         0x8007E03C
    // 0x8007F878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_22;
    // 0x8007F878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8007F87C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007F880: sw          $v0, 0x200($at)
    MEM_W(0X200, ctx->r1) = ctx->r2;
    // 0x8007F884: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007F888: lw          $a1, 0x200($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X200);
    // 0x8007F88C: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8007F890: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x8007F894: jal         0x800746C0
    // 0x8007F898: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_23;
    // 0x8007F898: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x8007F89C: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8007F8A0: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x8007F8A4: jal         0x80074888
    // 0x8007F8A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_24;
    // 0x8007F8A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x8007F8AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F8B0: jal         0x8007E03C
    // 0x8007F8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_25;
    // 0x8007F8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8007F8B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007F8BC: sw          $v0, 0x204($at)
    MEM_W(0X204, ctx->r1) = ctx->r2;
    // 0x8007F8C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007F8C4: lw          $a1, 0x204($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X204);
    // 0x8007F8C8: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8007F8CC: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x8007F8D0: jal         0x800746C0
    // 0x8007F8D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_26;
    // 0x8007F8D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_26:
    // 0x8007F8D8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007F8DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F8E0: sw          $t3, 0x31E0($at)
    MEM_W(0X31E0, ctx->r1) = ctx->r11;
    // 0x8007F8E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F8E8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8007F8EC: sw          $t4, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = ctx->r12;
    // 0x8007F8F0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8007F8F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8007F8F8: jal         0x8007F288
    // 0x8007F8FC: nop

    func_8007F288(rdram, ctx);
        goto after_27;
    // 0x8007F8FC: nop

    after_27:
    // 0x8007F900: jal         0x8007EFE4
    // 0x8007F904: nop

    Gfx_DrawScreenFade3(rdram, ctx);
        goto after_28;
    // 0x8007F904: nop

    after_28:
    // 0x8007F908: b           L_8007FBA0
    // 0x8007F90C: nop

        goto L_8007FBA0;
    // 0x8007F90C: nop

L_8007F910:
    // 0x8007F910: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8007F914: lw          $t5, 0x31D8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X31D8);
    // 0x8007F918: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007F91C: bne         $t5, $at, L_8007F9A8
    if (ctx->r13 != ctx->r1) {
        // 0x8007F920: nop
    
            goto L_8007F9A8;
    }
    // 0x8007F920: nop

    // 0x8007F924: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007F928: jal         0x8005BBFC
    // 0x8007F92C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_29;
    // 0x8007F92C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_29:
    // 0x8007F930: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007F934: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007F938: lw          $a2, 0x204($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X204);
    // 0x8007F93C: lw          $a1, 0x200($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X200);
    // 0x8007F940: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007F944: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8007F948: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8007F94C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8007F950: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8007F954: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8007F958: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8007F95C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8007F960: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8007F964: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x8007F968: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8007F96C: jal         0x80057460
    // 0x8007F970: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_30;
    // 0x8007F970: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_30:
    // 0x8007F974: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007F978: jal         0x8005BE40
    // 0x8007F97C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_31;
    // 0x8007F97C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_31:
    // 0x8007F980: jal         0x8007EFE4
    // 0x8007F984: nop

    Gfx_DrawScreenFade3(rdram, ctx);
        goto after_32;
    // 0x8007F984: nop

    after_32:
    // 0x8007F988: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007F98C: bne         $v0, $at, L_8007F9A8
    if (ctx->r2 != ctx->r1) {
        // 0x8007F990: nop
    
            goto L_8007F9A8;
    }
    // 0x8007F990: nop

    // 0x8007F994: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8007F998: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F99C: sw          $t0, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = ctx->r8;
    // 0x8007F9A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F9A4: sw          $zero, 0x31E4($at)
    MEM_W(0X31E4, ctx->r1) = 0;
L_8007F9A8:
    // 0x8007F9A8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007F9AC: lw          $t1, 0x31D8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X31D8);
    // 0x8007F9B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007F9B4: bne         $t1, $at, L_8007FB20
    if (ctx->r9 != ctx->r1) {
        // 0x8007F9B8: nop
    
            goto L_8007FB20;
    }
    // 0x8007F9B8: nop

    // 0x8007F9BC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007F9C0: addiu       $t2, $t2, -0x10D0
    ctx->r10 = ADD32(ctx->r10, -0X10D0);
    // 0x8007F9C4: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x8007F9C8: nop

    // 0x8007F9CC: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x8007F9D0: beq         $t4, $zero, L_8007F9F0
    if (ctx->r12 == 0) {
        // 0x8007F9D4: nop
    
            goto L_8007F9F0;
    }
    // 0x8007F9D4: nop

    // 0x8007F9D8: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8007F9DC: lw          $t5, 0x31E4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X31E4);
    // 0x8007F9E0: nop

    // 0x8007F9E4: slti        $at, $t5, 0x3C
    ctx->r1 = SIGNED(ctx->r13) < 0X3C ? 1 : 0;
    // 0x8007F9E8: beq         $at, $zero, L_8007FA3C
    if (ctx->r1 == 0) {
        // 0x8007F9EC: nop
    
            goto L_8007FA3C;
    }
    // 0x8007F9EC: nop

L_8007F9F0:
    // 0x8007F9F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007F9F4: addiu       $t6, $t6, -0x10D0
    ctx->r14 = ADD32(ctx->r14, -0X10D0);
    // 0x8007F9F8: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x8007F9FC: nop

    // 0x8007FA00: andi        $t9, $t7, 0x1000
    ctx->r25 = ctx->r15 & 0X1000;
    // 0x8007FA04: beq         $t9, $zero, L_8007FA24
    if (ctx->r25 == 0) {
        // 0x8007FA08: nop
    
            goto L_8007FA24;
    }
    // 0x8007FA08: nop

    // 0x8007FA0C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8007FA10: lw          $t8, 0x31E4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X31E4);
    // 0x8007FA14: nop

    // 0x8007FA18: slti        $at, $t8, 0x3C
    ctx->r1 = SIGNED(ctx->r24) < 0X3C ? 1 : 0;
    // 0x8007FA1C: beq         $at, $zero, L_8007FA3C
    if (ctx->r1 == 0) {
        // 0x8007FA20: nop
    
            goto L_8007FA3C;
    }
    // 0x8007FA20: nop

L_8007FA24:
    // 0x8007FA24: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8007FA28: lw          $t0, 0x31E4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X31E4);
    // 0x8007FA2C: nop

    // 0x8007FA30: slti        $at, $t0, 0x12C
    ctx->r1 = SIGNED(ctx->r8) < 0X12C ? 1 : 0;
    // 0x8007FA34: bne         $at, $zero, L_8007FAB0
    if (ctx->r1 != 0) {
        // 0x8007FA38: nop
    
            goto L_8007FAB0;
    }
    // 0x8007FA38: nop

L_8007FA3C:
    // 0x8007FA3C: jal         0x80060D58
    // 0x8007FA40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80060D58(rdram, ctx);
        goto after_33;
    // 0x8007FA40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_33:
    // 0x8007FA44: jal         0x8004A34C
    // 0x8007FA48: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_34;
    // 0x8007FA48: nop

    after_34:
    // 0x8007FA4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007FA50: lw          $a0, 0x200($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X200);
    // 0x8007FA54: jal         0x8007E328
    // 0x8007FA58: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_35;
    // 0x8007FA58: nop

    after_35:
    // 0x8007FA5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007FA60: lw          $a0, 0x204($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X204);
    // 0x8007FA64: jal         0x8007E328
    // 0x8007FA68: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_36;
    // 0x8007FA68: nop

    after_36:
    // 0x8007FA6C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8007FA70: jal         0x80085030
    // 0x8007FA74: addiu       $a0, $a0, 0x3988
    ctx->r4 = ADD32(ctx->r4, 0X3988);
    Audio_LoadSFX(rdram, ctx);
        goto after_37;
    // 0x8007FA74: addiu       $a0, $a0, 0x3988
    ctx->r4 = ADD32(ctx->r4, 0X3988);
    after_37:
    // 0x8007FA78: jal         0x800905E8
    // 0x8007FA7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800905E8(rdram, ctx);
        goto after_38;
    // 0x8007FA7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_38:
    // 0x8007FA80: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007FA84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FA88: sb          $t1, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r9;
    // 0x8007FA8C: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    // 0x8007FA90: jal         0x80061134
    // 0x8007FA94: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    PFGFX_ClearCellGrids(rdram, ctx);
        goto after_39;
    // 0x8007FA94: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_39:
    // 0x8007FA98: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8007FA9C: lw          $t2, 0x31D8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X31D8);
    // 0x8007FAA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FAA4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007FAA8: b           L_8007FBA0
    // 0x8007FAAC: sw          $t3, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = ctx->r11;
        goto L_8007FBA0;
    // 0x8007FAAC: sw          $t3, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = ctx->r11;
L_8007FAB0:
    // 0x8007FAB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007FAB4: jal         0x8005BBFC
    // 0x8007FAB8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_40;
    // 0x8007FAB8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_40:
    // 0x8007FABC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007FAC0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007FAC4: lw          $a2, 0x204($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X204);
    // 0x8007FAC8: lw          $a1, 0x200($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X200);
    // 0x8007FACC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007FAD0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8007FAD4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8007FAD8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8007FADC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8007FAE0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8007FAE4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8007FAE8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8007FAEC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8007FAF0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x8007FAF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8007FAF8: jal         0x80057460
    // 0x8007FAFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_41;
    // 0x8007FAFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_41:
    // 0x8007FB00: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007FB04: jal         0x8005BE40
    // 0x8007FB08: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_42;
    // 0x8007FB08: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_42:
    // 0x8007FB0C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8007FB10: lw          $t9, 0x31E4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X31E4);
    // 0x8007FB14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FB18: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8007FB1C: sw          $t8, 0x31E4($at)
    MEM_W(0X31E4, ctx->r1) = ctx->r24;
L_8007FB20:
    // 0x8007FB20: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8007FB24: lw          $t0, 0x31D8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X31D8);
    // 0x8007FB28: nop

    // 0x8007FB2C: addiu       $t1, $t0, -0x5
    ctx->r9 = ADD32(ctx->r8, -0X5);
    // 0x8007FB30: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x8007FB34: beq         $at, $zero, L_8007FBA0
    if (ctx->r1 == 0) {
        // 0x8007FB38: nop
    
            goto L_8007FBA0;
    }
    // 0x8007FB38: nop

    // 0x8007FB3C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007FB40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007FB44: addu        $at, $at, $t1
    gpr jr_addend_8007FB50 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8007FB48: lw          $t1, -0x1E80($at)
    ctx->r9 = ADD32(ctx->r1, -0X1E80);
    // 0x8007FB4C: nop

    // 0x8007FB50: jr          $t1
    // 0x8007FB54: nop

    switch (jr_addend_8007FB50 >> 2) {
        case 0: goto L_8007FB58; break;
        case 1: goto L_8007FB58; break;
        case 2: goto L_8007FB58; break;
        case 3: goto L_8007FB58; break;
        case 4: goto L_8007FB58; break;
        case 5: goto L_8007FB70; break;
        default: switch_error(__func__, 0x8007FB50, 0x800DE180);
    }
    // 0x8007FB54: nop

L_8007FB58:
    // 0x8007FB58: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8007FB5C: lw          $t2, 0x31D8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X31D8);
    // 0x8007FB60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FB64: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007FB68: b           L_8007FBA0
    // 0x8007FB6C: sw          $t3, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = ctx->r11;
        goto L_8007FBA0;
    // 0x8007FB6C: sw          $t3, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = ctx->r11;
L_8007FB70:
    // 0x8007FB70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FB74: sw          $zero, 0x31E4($at)
    MEM_W(0X31E4, ctx->r1) = 0;
    // 0x8007FB78: jal         0x80060D58
    // 0x8007FB7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80060D58(rdram, ctx);
        goto after_43;
    // 0x8007FB7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_43:
    // 0x8007FB80: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8007FB84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FB88: sb          $t4, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r12;
    // 0x8007FB8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FB90: sw          $zero, 0x31D8($at)
    MEM_W(0X31D8, ctx->r1) = 0;
    // 0x8007FB94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FB98: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007FB9C: sw          $t5, 0x31D4($at)
    MEM_W(0X31D4, ctx->r1) = ctx->r13;
L_8007FBA0:
    // 0x8007FBA0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8007FBA4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8007FBA8: jr          $ra
    // 0x8007FBAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007FBAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void func_8007FBB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FBB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007FBB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007FBB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007FBBC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007FBC0: jal         0x8004A34C
    // 0x8007FBC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x8007FBC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8007FBC8: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8007FBCC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007FBD0: jal         0x80074888
    // 0x8007FBD4: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_1;
    // 0x8007FBD4: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_1:
    // 0x8007FBD8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007FBDC: jal         0x8007E03C
    // 0x8007FBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8007FBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8007FBE4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007FBE8: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8007FBEC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8007FBF0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007FBF4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8007FBF8: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x8007FBFC: jal         0x800746C0
    // 0x8007FC00: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_3;
    // 0x8007FC00: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_3:
    // 0x8007FC04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007FC08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007FC0C: jr          $ra
    // 0x8007FC10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007FC10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_8007FC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FC14: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC18: nop

    // 0x8007FC1C: beq         $t6, $zero, L_8007FC6C
    if (ctx->r14 == 0) {
        // 0x8007FC20: nop
    
            goto L_8007FC6C;
    }
    // 0x8007FC20: nop

    // 0x8007FC24: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x8007FC28: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8007FC2C: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007FC30: mflo        $t9
    ctx->r25 = lo;
    // 0x8007FC34: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007FC38: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x8007FC3C: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x8007FC40: nop

    // 0x8007FC44: bgez        $t1, L_8007FC50
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8007FC48: nop
    
            goto L_8007FC50;
    }
    // 0x8007FC48: nop

    // 0x8007FC4C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
L_8007FC50:
    // 0x8007FC50: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x8007FC54: ori         $at, $zero, 0xFF01
    ctx->r1 = 0 | 0XFF01;
    // 0x8007FC58: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8007FC5C: bne         $at, $zero, L_8007FC6C
    if (ctx->r1 != 0) {
        // 0x8007FC60: nop
    
            goto L_8007FC6C;
    }
    // 0x8007FC60: nop

    // 0x8007FC64: ori         $t3, $zero, 0xFF00
    ctx->r11 = 0 | 0XFF00;
    // 0x8007FC68: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
L_8007FC6C:
    // 0x8007FC6C: jr          $ra
    // 0x8007FC70: nop

    return;
    // 0x8007FC70: nop

;}

RECOMP_FUNC void func_8007FC74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FC74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007FC78: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007FC7C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007FC80: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007FC84: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8007FC88: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8007FC8C: nop

    // 0x8007FC90: beq         $t7, $zero, L_8007FD04
    if (ctx->r15 == 0) {
        // 0x8007FC94: nop
    
            goto L_8007FD04;
    }
    // 0x8007FC94: nop

    // 0x8007FC98: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8007FC9C: nop

    // 0x8007FCA0: beq         $t8, $zero, L_8007FD04
    if (ctx->r24 == 0) {
        // 0x8007FCA4: nop
    
            goto L_8007FD04;
    }
    // 0x8007FCA4: nop

    // 0x8007FCA8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8007FCAC: jal         0x8005BBFC
    // 0x8007FCB0: nop

    Gfx_SetupRenderState(rdram, ctx);
        goto after_0;
    // 0x8007FCB0: nop

    after_0:
    // 0x8007FCB4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007FCB8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8007FCBC: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x8007FCC0: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x8007FCC4: lh          $a3, 0x4($t9)
    ctx->r7 = MEM_H(ctx->r25, 0X4);
    // 0x8007FCC8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8007FCCC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8007FCD0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8007FCD4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8007FCD8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8007FCDC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8007FCE0: lw          $t4, 0x8($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X8);
    // 0x8007FCE4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8007FCE8: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x8007FCEC: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8007FCF0: jal         0x80057460
    // 0x8007FCF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_1;
    // 0x8007FCF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8007FCF8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8007FCFC: jal         0x8005BE40
    // 0x8007FD00: nop

    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_2;
    // 0x8007FD00: nop

    after_2:
L_8007FD04:
    // 0x8007FD04: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007FD08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007FD0C: jr          $ra
    // 0x8007FD10: nop

    return;
    // 0x8007FD10: nop

;}

RECOMP_FUNC void func_8007FD14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FD14: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8007FD18: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x8007FD1C: addiu       $t6, $sp, 0x8
    ctx->r14 = ADD32(ctx->r29, 0X8);
    // 0x8007FD20: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8007FD24: ori         $t9, $zero, 0xFF00
    ctx->r25 = 0 | 0XFF00;
    // 0x8007FD28: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8007FD2C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8007FD30: swl         $at, 0x4($a0)
    do_swl(rdram, 0X4, ctx->r4, ctx->r1);
    // 0x8007FD34: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8007FD38: div         $zero, $t1, $a3
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r7)));
    // 0x8007FD3C: swr         $at, 0x7($a0)
    do_swr(rdram, 0X7, ctx->r4, ctx->r1);
    // 0x8007FD40: bne         $a3, $zero, L_8007FD4C
    if (ctx->r7 != 0) {
        // 0x8007FD44: nop
    
            goto L_8007FD4C;
    }
    // 0x8007FD44: nop

    // 0x8007FD48: break       7
    do_break(2148007240);
L_8007FD4C:
    // 0x8007FD4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007FD50: bne         $a3, $at, L_8007FD64
    if (ctx->r7 != ctx->r1) {
        // 0x8007FD54: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007FD64;
    }
    // 0x8007FD54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007FD58: bne         $t1, $at, L_8007FD64
    if (ctx->r9 != ctx->r1) {
        // 0x8007FD5C: nop
    
            goto L_8007FD64;
    }
    // 0x8007FD5C: nop

    // 0x8007FD60: break       6
    do_break(2148007264);
L_8007FD64:
    // 0x8007FD64: mflo        $t2
    ctx->r10 = lo;
    // 0x8007FD68: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x8007FD6C: jr          $ra
    // 0x8007FD70: nop

    return;
    // 0x8007FD70: nop

;}

RECOMP_FUNC void func_8007FD74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FD74: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8007FD78: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8007FD7C: jr          $ra
    // 0x8007FD80: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x8007FD80: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}

RECOMP_FUNC void func_8007FD84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FD84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007FD88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007FD8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FD90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007FD94: jal         0x8007FD74
    // 0x8007FD98: nop

    func_8007FD74(rdram, ctx);
        goto after_0;
    // 0x8007FD98: nop

    after_0:
    // 0x8007FD9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FDA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007FDA4: jr          $ra
    // 0x8007FDA8: nop

    return;
    // 0x8007FDA8: nop

    // 0x8007FDAC: nop

;}

RECOMP_FUNC void Gfx_DrawScreenFadeOverlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080B50: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80080B54: lw          $t6, 0x32C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X32C8);
    // 0x80080B58: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80080B5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80080B60: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80080B64: beq         $t6, $at, L_80080B80
    if (ctx->r14 == ctx->r1) {
        // 0x80080B68: sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
            goto L_80080B80;
    }
    // 0x80080B68: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80080B6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80080B70: beq         $t6, $at, L_80080B80
    if (ctx->r14 == ctx->r1) {
        // 0x80080B74: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80080B80;
    }
    // 0x80080B74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80080B78: bne         $t6, $at, L_80080BDC
    if (ctx->r14 != ctx->r1) {
        // 0x80080B7C: nop
    
            goto L_80080BDC;
    }
    // 0x80080B7C: nop

L_80080B80:
    // 0x80080B80: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080B84: jal         0x8005BBFC
    // 0x80080B88: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_0;
    // 0x80080B88: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_0:
    // 0x80080B8C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80080B90: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80080B94: lw          $a2, 0x214($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X214);
    // 0x80080B98: lw          $a1, 0x210($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X210);
    // 0x80080B9C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080BA0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80080BA4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80080BA8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80080BAC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80080BB0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80080BB4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80080BB8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80080BBC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80080BC0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80080BC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80080BC8: jal         0x80057460
    // 0x80080BCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_1;
    // 0x80080BCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80080BD0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080BD4: jal         0x8005BE40
    // 0x80080BD8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_2;
    // 0x80080BD8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_2:
L_80080BDC:
    // 0x80080BDC: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80080BE0: lw          $t1, 0x32C8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X32C8);
    // 0x80080BE4: nop

    // 0x80080BE8: sltiu       $at, $t1, 0x5
    ctx->r1 = ctx->r9 < 0X5 ? 1 : 0;
    // 0x80080BEC: beq         $at, $zero, L_80080E30
    if (ctx->r1 == 0) {
        // 0x80080BF0: nop
    
            goto L_80080E30;
    }
    // 0x80080BF0: nop

    // 0x80080BF4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80080BF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080BFC: addu        $at, $at, $t1
    gpr jr_addend_80080C08 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80080C00: lw          $t1, -0x15F0($at)
    ctx->r9 = ADD32(ctx->r1, -0X15F0);
    // 0x80080C04: nop

    // 0x80080C08: jr          $t1
    // 0x80080C0C: nop

    switch (jr_addend_80080C08 >> 2) {
        case 0: goto L_80080C10; break;
        case 1: goto L_80080D10; break;
        case 2: goto L_80080D40; break;
        case 3: goto L_80080D98; break;
        case 4: goto L_80080E18; break;
        default: switch_error(__func__, 0x80080C08, 0x800DEA10);
    }
    // 0x80080C0C: nop

L_80080C10:
    // 0x80080C10: jal         0x8004A34C
    // 0x80080C14: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_3;
    // 0x80080C14: nop

    after_3:
    // 0x80080C18: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80080C1C: lw          $t2, 0x32CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X32CC);
    // 0x80080C20: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80080C24: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80080C28: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x80080C2C: lw          $a1, 0x32C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X32C0);
    // 0x80080C30: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80080C34: jal         0x80074888
    // 0x80080C38: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_4;
    // 0x80080C38: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_4:
    // 0x80080C3C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80080C40: jal         0x8007E03C
    // 0x80080C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x80080C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80080C48: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80080C4C: lw          $t4, 0x32CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X32CC);
    // 0x80080C50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80080C54: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80080C58: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80080C5C: sw          $v0, 0x210($at)
    MEM_W(0X210, ctx->r1) = ctx->r2;
    // 0x80080C60: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x80080C64: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80080C68: lw          $a1, 0x210($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X210);
    // 0x80080C6C: lw          $a2, 0x32C0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X32C0);
    // 0x80080C70: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80080C74: jal         0x800746C0
    // 0x80080C78: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_6;
    // 0x80080C78: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_6:
    // 0x80080C7C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80080C80: lw          $t6, 0x32CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X32CC);
    // 0x80080C84: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80080C88: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80080C8C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80080C90: lw          $t8, 0x32C4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X32C4);
    // 0x80080C94: nop

    // 0x80080C98: beq         $t8, $zero, L_80080CF0
    if (ctx->r24 == 0) {
        // 0x80080C9C: nop
    
            goto L_80080CF0;
    }
    // 0x80080C9C: nop

    // 0x80080CA0: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80080CA4: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x80080CA8: jal         0x80074888
    // 0x80080CAC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_7;
    // 0x80080CAC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_7:
    // 0x80080CB0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80080CB4: jal         0x8007E03C
    // 0x80080CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x80080CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80080CBC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80080CC0: lw          $t9, 0x32CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X32CC);
    // 0x80080CC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80080CC8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80080CCC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80080CD0: sw          $v0, 0x214($at)
    MEM_W(0X214, ctx->r1) = ctx->r2;
    // 0x80080CD4: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x80080CD8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80080CDC: lw          $a1, 0x214($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X214);
    // 0x80080CE0: lw          $a2, 0x32C4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X32C4);
    // 0x80080CE4: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80080CE8: jal         0x800746C0
    // 0x80080CEC: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_9;
    // 0x80080CEC: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_9:
L_80080CF0:
    // 0x80080CF0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80080CF4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80080CF8: jal         0x8007ECC8
    // 0x80080CFC: nop

    func_8007ECC8(rdram, ctx);
        goto after_10;
    // 0x80080CFC: nop

    after_10:
    // 0x80080D00: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80080D04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080D08: b           L_80080E30
    // 0x80080D0C: sw          $t1, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r9;
        goto L_80080E30;
    // 0x80080D0C: sw          $t1, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r9;
L_80080D10:
    // 0x80080D10: jal         0x8007EA2C
    // 0x80080D14: nop

    Gfx_DrawScreenFade1(rdram, ctx);
        goto after_11;
    // 0x80080D14: nop

    after_11:
    // 0x80080D18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80080D1C: bne         $v0, $at, L_80080E30
    if (ctx->r2 != ctx->r1) {
        // 0x80080D20: nop
    
            goto L_80080E30;
    }
    // 0x80080D20: nop

    // 0x80080D24: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80080D28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080D2C: sw          $t2, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r10;
    // 0x80080D30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80080D34: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x80080D38: b           L_80080E30
    // 0x80080D3C: sw          $t3, 0x218($at)
    MEM_W(0X218, ctx->r1) = ctx->r11;
        goto L_80080E30;
    // 0x80080D3C: sw          $t3, 0x218($at)
    MEM_W(0X218, ctx->r1) = ctx->r11;
L_80080D40:
    // 0x80080D40: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80080D44: lw          $t4, 0x218($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X218);
    // 0x80080D48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80080D4C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80080D50: beq         $t5, $zero, L_80080D78
    if (ctx->r13 == 0) {
        // 0x80080D54: sw          $t5, 0x218($at)
        MEM_W(0X218, ctx->r1) = ctx->r13;
            goto L_80080D78;
    }
    // 0x80080D54: sw          $t5, 0x218($at)
    MEM_W(0X218, ctx->r1) = ctx->r13;
    // 0x80080D58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80080D5C: addiu       $t6, $t6, -0x10D0
    ctx->r14 = ADD32(ctx->r14, -0X10D0);
    // 0x80080D60: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80080D64: nop

    // 0x80080D68: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x80080D6C: beq         $t8, $zero, L_80080E30
    if (ctx->r24 == 0) {
        // 0x80080D70: slti        $at, $t5, 0xF0
        ctx->r1 = SIGNED(ctx->r13) < 0XF0 ? 1 : 0;
            goto L_80080E30;
    }
    // 0x80080D70: slti        $at, $t5, 0xF0
    ctx->r1 = SIGNED(ctx->r13) < 0XF0 ? 1 : 0;
    // 0x80080D74: beq         $at, $zero, L_80080E30
    if (ctx->r1 == 0) {
        // 0x80080D78: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80080E30;
    }
L_80080D78:
    // 0x80080D78: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80080D7C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80080D80: jal         0x8007E9F8
    // 0x80080D84: nop

    func_8007E9F8(rdram, ctx);
        goto after_12;
    // 0x80080D84: nop

    after_12:
    // 0x80080D88: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80080D8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080D90: b           L_80080E30
    // 0x80080D94: sw          $t9, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r25;
        goto L_80080E30;
    // 0x80080D94: sw          $t9, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r25;
L_80080D98:
    // 0x80080D98: jal         0x8007E750
    // 0x80080D9C: nop

    Gfx_DrawScreenFade0(rdram, ctx);
        goto after_13;
    // 0x80080D9C: nop

    after_13:
    // 0x80080DA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80080DA4: bne         $v0, $at, L_80080E30
    if (ctx->r2 != ctx->r1) {
        // 0x80080DA8: nop
    
            goto L_80080E30;
    }
    // 0x80080DA8: nop

    // 0x80080DAC: jal         0x8004A34C
    // 0x80080DB0: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_14;
    // 0x80080DB0: nop

    after_14:
    // 0x80080DB4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80080DB8: lw          $a0, 0x214($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X214);
    // 0x80080DBC: jal         0x8007E328
    // 0x80080DC0: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_15;
    // 0x80080DC0: nop

    after_15:
    // 0x80080DC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80080DC8: lw          $a0, 0x210($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X210);
    // 0x80080DCC: jal         0x8007E328
    // 0x80080DD0: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_16;
    // 0x80080DD0: nop

    after_16:
    // 0x80080DD4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80080DD8: lw          $t0, 0x32CC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X32CC);
    // 0x80080DDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080DE0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80080DE4: sw          $t1, 0x32CC($at)
    MEM_W(0X32CC, ctx->r1) = ctx->r9;
    // 0x80080DE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80080DEC: bne         $t1, $at, L_80080E0C
    if (ctx->r9 != ctx->r1) {
        // 0x80080DF0: nop
    
            goto L_80080E0C;
    }
    // 0x80080DF0: nop

    // 0x80080DF4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80080DF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080DFC: jal         0x8007E750
    // 0x80080E00: sw          $t2, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r10;
    Gfx_DrawScreenFade0(rdram, ctx);
        goto after_17;
    // 0x80080E00: sw          $t2, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r10;
    after_17:
    // 0x80080E04: b           L_80080E30
    // 0x80080E08: nop

        goto L_80080E30;
    // 0x80080E08: nop

L_80080E0C:
    // 0x80080E0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080E10: b           L_80080E30
    // 0x80080E14: sw          $zero, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = 0;
        goto L_80080E30;
    // 0x80080E14: sw          $zero, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = 0;
L_80080E18:
    // 0x80080E18: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80080E1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080E20: sb          $t3, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r11;
    // 0x80080E24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080E28: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80080E2C: sb          $t4, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r12;
L_80080E30:
    // 0x80080E30: jal         0x800722E0
    // 0x80080E34: nop

    func_800722E0(rdram, ctx);
        goto after_18;
    // 0x80080E34: nop

    after_18:
    // 0x80080E38: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80080E3C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80080E40: jr          $ra
    // 0x80080E44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80080E44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80080E48: nop

    // 0x80080E4C: nop

;}

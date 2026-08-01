#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Main_InitVideo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800484B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800484B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800484BC: jal         0x8007E03C
    // 0x800484C0: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800484C0: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    after_0:
    // 0x800484C4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800484C8: addiu       $t6, $t6, 0x20B8
    ctx->r14 = ADD32(ctx->r14, 0X20B8);
    // 0x800484CC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x800484D0: jal         0x8007E03C
    // 0x800484D4: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800484D4: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    after_1:
    // 0x800484D8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800484DC: addiu       $t7, $t7, 0x20B8
    ctx->r15 = ADD32(ctx->r15, 0X20B8);
    // 0x800484E0: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    // 0x800484E4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800484E8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800484EC: lw          $t1, -0x2B0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2B0);
    // 0x800484F0: lw          $t0, -0x2AC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AC);
    // 0x800484F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800484F8: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800484FC: sw          $zero, -0x2C0($at)
    MEM_W(-0X2C0, ctx->r1) = 0;
    // 0x80048500: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048504: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80048508: sw          $t8, 0x20C4($at)
    MEM_W(0X20C4, ctx->r1) = ctx->r24;
    // 0x8004850C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80048510: sw          $zero, -0x2BC($at)
    MEM_W(-0X2BC, ctx->r1) = 0;
    // 0x80048514: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80048518: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004851C: addiu       $t9, $t9, -0x5300
    ctx->r25 = ADD32(ctx->r25, -0X5300);
    // 0x80048520: sw          $zero, 0x20D4($at)
    MEM_W(0X20D4, ctx->r1) = 0;
    // 0x80048524: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80048528: mflo        $t2
    ctx->r10 = lo;
    // 0x8004852C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80048530: beq         $t2, $zero, L_80048560
    if (ctx->r10 == 0) {
        // 0x80048534: nop
    
            goto L_80048560;
    }
    // 0x80048534: nop

L_80048538:
    // 0x80048538: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8004853C: nop

    // 0x80048540: sh          $zero, 0x0($t3)
    MEM_H(0X0, ctx->r11) = 0;
    // 0x80048544: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80048548: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8004854C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80048550: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80048554: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80048558: bne         $t7, $zero, L_80048538
    if (ctx->r15 != 0) {
        // 0x8004855C: sw          $t5, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r13;
            goto L_80048538;
    }
    // 0x8004855C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
L_80048560:
    // 0x80048560: jal         0x800B6330
    // 0x80048564: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_2;
    // 0x80048564: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_2:
    // 0x80048568: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8004856C: jal         0x800B64F0
    // 0x80048570: addiu       $a0, $a0, -0x5300
    ctx->r4 = ADD32(ctx->r4, -0X5300);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x80048570: addiu       $a0, $a0, -0x5300
    ctx->r4 = ADD32(ctx->r4, -0X5300);
    after_3:
    // 0x80048574: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048578: addiu       $t9, $t9, 0x2070
    ctx->r25 = ADD32(ctx->r25, 0X2070);
    // 0x8004857C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80048580: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x80048584: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048588: addiu       $t0, $t0, 0x2070
    ctx->r8 = ADD32(ctx->r8, 0X2070);
    // 0x8004858C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80048590: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048594: sh          $zero, 0x2($t0)
    MEM_H(0X2, ctx->r8) = 0;
    // 0x80048598: addiu       $t2, $t2, 0x2070
    ctx->r10 = ADD32(ctx->r10, 0X2070);
    // 0x8004859C: addiu       $t1, $t1, 0x1FA0
    ctx->r9 = ADD32(ctx->r9, 0X1FA0);
    // 0x800485A0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800485A4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800485A8: addiu       $t4, $t4, 0x2070
    ctx->r12 = ADD32(ctx->r12, 0X2070);
    // 0x800485AC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800485B0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800485B4: sh          $t3, 0x20($t4)
    MEM_H(0X20, ctx->r12) = ctx->r11;
    // 0x800485B8: addiu       $t6, $t6, 0x2070
    ctx->r14 = ADD32(ctx->r14, 0X2070);
    // 0x800485BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800485C0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800485C4: sh          $t5, 0x22($t6)
    MEM_H(0X22, ctx->r14) = ctx->r13;
    // 0x800485C8: addiu       $t7, $t7, 0x1FA0
    ctx->r15 = ADD32(ctx->r15, 0X1FA0);
    // 0x800485CC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800485D0: addiu       $t9, $t9, 0x2070
    ctx->r25 = ADD32(ctx->r25, 0X2070);
    // 0x800485D4: addiu       $t8, $t7, 0x68
    ctx->r24 = ADD32(ctx->r15, 0X68);
    // 0x800485D8: sw          $t8, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r24;
    // 0x800485DC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800485E0: addiu       $t0, $t0, 0x1FA0
    ctx->r8 = ADD32(ctx->r8, 0X1FA0);
    // 0x800485E4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800485E8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800485EC: addiu       $t1, $t1, 0x1FA0
    ctx->r9 = ADD32(ctx->r9, 0X1FA0);
    // 0x800485F0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800485F4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800485F8: addiu       $t3, $t3, 0x1FA0
    ctx->r11 = ADD32(ctx->r11, 0X1FA0);
    // 0x800485FC: addiu       $t2, $zero, 0x63
    ctx->r10 = ADD32(0, 0X63);
    // 0x80048600: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80048604: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x80048608: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x8004860C: addiu       $t4, $t4, -0x5300
    ctx->r12 = ADD32(ctx->r12, -0X5300);
    // 0x80048610: addiu       $t5, $t5, 0x1FA0
    ctx->r13 = ADD32(ctx->r13, 0X1FA0);
    // 0x80048614: sw          $t4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r12;
    // 0x80048618: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004861C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80048620: addiu       $t6, $t6, -0x44F8
    ctx->r14 = ADD32(ctx->r14, -0X44F8);
    // 0x80048624: addiu       $t7, $t7, 0x1FA0
    ctx->r15 = ADD32(ctx->r15, 0X1FA0);
    // 0x80048628: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8004862C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048630: sw          $t6, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r14;
    // 0x80048634: addiu       $t9, $t9, 0x1FA0
    ctx->r25 = ADD32(ctx->r25, 0X1FA0);
    // 0x80048638: addiu       $t8, $t8, 0x2070
    ctx->r24 = ADD32(ctx->r24, 0X2070);
    // 0x8004863C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80048640: sw          $t8, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->r24;
    // 0x80048644: addiu       $t1, $t1, 0x1FA0
    ctx->r9 = ADD32(ctx->r9, 0X1FA0);
    // 0x80048648: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8004864C: sw          $t0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r8;
    // 0x80048650: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048654: addiu       $t2, $t2, 0x1FA0
    ctx->r10 = ADD32(ctx->r10, 0X1FA0);
    // 0x80048658: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8004865C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80048660: sw          $zero, 0x14($t2)
    MEM_W(0X14, ctx->r10) = 0;
    // 0x80048664: addiu       $t3, $t3, 0x3310
    ctx->r11 = ADD32(ctx->r11, 0X3310);
    // 0x80048668: addiu       $t4, $t4, 0x1FA0
    ctx->r12 = ADD32(ctx->r12, 0X1FA0);
    // 0x8004866C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80048670: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80048674: sw          $t3, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r11;
    // 0x80048678: addiu       $t5, $t5, 0x33E0
    ctx->r13 = ADD32(ctx->r13, 0X33E0);
    // 0x8004867C: addiu       $t6, $t6, 0x3310
    ctx->r14 = ADD32(ctx->r14, 0X3310);
    // 0x80048680: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80048684: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x80048688: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8004868C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048690: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80048694: sw          $t7, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r15;
    // 0x80048698: addiu       $t9, $t9, 0x33E0
    ctx->r25 = ADD32(ctx->r25, 0X33E0);
    // 0x8004869C: addiu       $t0, $t0, 0x1FA0
    ctx->r8 = ADD32(ctx->r8, 0X1FA0);
    // 0x800486A0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800486A4: sw          $t9, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r25;
    // 0x800486A8: addiu       $t2, $t2, 0x1FA0
    ctx->r10 = ADD32(ctx->r10, 0X1FA0);
    // 0x800486AC: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x800486B0: sw          $t1, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r9;
    // 0x800486B4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800486B8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800486BC: addiu       $t4, $t4, 0x1FA0
    ctx->r12 = ADD32(ctx->r12, 0X1FA0);
    // 0x800486C0: addiu       $t3, $t3, 0x1830
    ctx->r11 = ADD32(ctx->r11, 0X1830);
    // 0x800486C4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800486C8: sw          $t3, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r11;
    // 0x800486CC: addiu       $t6, $t6, 0x1FA0
    ctx->r14 = ADD32(ctx->r14, 0X1FA0);
    // 0x800486D0: addiu       $t5, $zero, 0x800
    ctx->r13 = ADD32(0, 0X800);
    // 0x800486D4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800486D8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800486DC: sw          $t5, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r13;
    // 0x800486E0: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x800486E4: addiu       $t7, $t7, 0x21C0
    ctx->r15 = ADD32(ctx->r15, 0X21C0);
    // 0x800486E8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800486EC: sw          $t7, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r15;
    // 0x800486F0: addiu       $t0, $t0, 0x1FA0
    ctx->r8 = ADD32(ctx->r8, 0X1FA0);
    // 0x800486F4: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x800486F8: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x800486FC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80048700: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048704: addiu       $t2, $t2, 0x1FA0
    ctx->r10 = ADD32(ctx->r10, 0X1FA0);
    // 0x80048708: addiu       $t1, $t1, 0x31C0
    ctx->r9 = ADD32(ctx->r9, 0X31C0);
    // 0x8004870C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80048710: sw          $t1, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->r9;
    // 0x80048714: addiu       $t3, $t3, 0x31C0
    ctx->r11 = ADD32(ctx->r11, 0X31C0);
    // 0x80048718: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8004871C: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80048720: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80048724: addiu       $t5, $t5, 0x1FA0
    ctx->r13 = ADD32(ctx->r13, 0X1FA0);
    // 0x80048728: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004872C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048730: sw          $t4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r12;
    // 0x80048734: addiu       $t6, $t6, 0x25C0
    ctx->r14 = ADD32(ctx->r14, 0X25C0);
    // 0x80048738: addiu       $t7, $t7, 0x1FA0
    ctx->r15 = ADD32(ctx->r15, 0X1FA0);
    // 0x8004873C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048740: sw          $t6, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->r14;
    // 0x80048744: addiu       $t9, $t9, 0x1FA0
    ctx->r25 = ADD32(ctx->r25, 0X1FA0);
    // 0x80048748: addiu       $t8, $zero, 0xC00
    ctx->r24 = ADD32(0, 0XC00);
    // 0x8004874C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048750: sw          $t8, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->r24;
    // 0x80048754: addiu       $t0, $t0, 0x20B8
    ctx->r8 = ADD32(ctx->r8, 0X20B8);
    // 0x80048758: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8004875C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048760: addiu       $t2, $t2, 0x1FA0
    ctx->r10 = ADD32(ctx->r10, 0X1FA0);
    // 0x80048764: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80048768: sw          $t1, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->r9;
    // 0x8004876C: addiu       $t3, $t3, 0x1FA0
    ctx->r11 = ADD32(ctx->r11, 0X1FA0);
    // 0x80048770: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80048774: sw          $zero, 0x44($t3)
    MEM_W(0X44, ctx->r11) = 0;
    // 0x80048778: addiu       $t4, $t4, 0x1FA0
    ctx->r12 = ADD32(ctx->r12, 0X1FA0);
    // 0x8004877C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80048780: sw          $zero, 0x68($t4)
    MEM_W(0X68, ctx->r12) = 0;
    // 0x80048784: addiu       $t5, $t5, 0x1FA0
    ctx->r13 = ADD32(ctx->r13, 0X1FA0);
    // 0x80048788: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004878C: sw          $zero, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = 0;
    // 0x80048790: addiu       $t7, $t7, 0x1FA0
    ctx->r15 = ADD32(ctx->r15, 0X1FA0);
    // 0x80048794: addiu       $t6, $zero, 0x63
    ctx->r14 = ADD32(0, 0X63);
    // 0x80048798: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8004879C: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x800487A0: sw          $t6, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->r14;
    // 0x800487A4: ori         $at, $at, 0xA980
    ctx->r1 = ctx->r1 | 0XA980;
    // 0x800487A8: addiu       $t8, $t8, -0x5300
    ctx->r24 = ADD32(ctx->r24, -0X5300);
    // 0x800487AC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800487B0: addiu       $t0, $t0, 0x1FA0
    ctx->r8 = ADD32(ctx->r8, 0X1FA0);
    // 0x800487B4: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800487B8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800487BC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800487C0: sw          $t9, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r25;
    // 0x800487C4: addiu       $t2, $t2, 0x1FA0
    ctx->r10 = ADD32(ctx->r10, 0X1FA0);
    // 0x800487C8: addiu       $t1, $t1, -0x44F8
    ctx->r9 = ADD32(ctx->r9, -0X44F8);
    // 0x800487CC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800487D0: sw          $t1, 0xB8($t2)
    MEM_W(0XB8, ctx->r10) = ctx->r9;
    // 0x800487D4: addiu       $t3, $t3, 0x2070
    ctx->r11 = ADD32(ctx->r11, 0X2070);
    // 0x800487D8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800487DC: addiu       $t5, $t5, 0x1FA0
    ctx->r13 = ADD32(ctx->r13, 0X1FA0);
    // 0x800487E0: addiu       $t4, $t3, 0x20
    ctx->r12 = ADD32(ctx->r11, 0X20);
    // 0x800487E4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800487E8: sw          $t4, 0xBC($t5)
    MEM_W(0XBC, ctx->r13) = ctx->r12;
    // 0x800487EC: addiu       $t7, $t7, 0x1FA0
    ctx->r15 = ADD32(ctx->r15, 0X1FA0);
    // 0x800487F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800487F4: sw          $t6, 0x78($t7)
    MEM_W(0X78, ctx->r15) = ctx->r14;
    // 0x800487F8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800487FC: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x80048800: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80048804: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048808: sw          $zero, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = 0;
    // 0x8004880C: addiu       $t0, $t0, 0x1FA0
    ctx->r8 = ADD32(ctx->r8, 0X1FA0);
    // 0x80048810: addiu       $t9, $t9, 0x3310
    ctx->r25 = ADD32(ctx->r25, 0X3310);
    // 0x80048814: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80048818: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8004881C: sw          $t9, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->r25;
    // 0x80048820: addiu       $t2, $t2, 0x3310
    ctx->r10 = ADD32(ctx->r10, 0X3310);
    // 0x80048824: addiu       $t1, $t1, 0x33E0
    ctx->r9 = ADD32(ctx->r9, 0X33E0);
    // 0x80048828: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8004882C: addiu       $t4, $t4, 0x1FA0
    ctx->r12 = ADD32(ctx->r12, 0X1FA0);
    // 0x80048830: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80048834: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048838: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8004883C: sw          $t3, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->r11;
    // 0x80048840: addiu       $t5, $t5, 0x33E0
    ctx->r13 = ADD32(ctx->r13, 0X33E0);
    // 0x80048844: addiu       $t6, $t6, 0x1FA0
    ctx->r14 = ADD32(ctx->r14, 0X1FA0);
    // 0x80048848: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8004884C: sw          $t5, 0x88($t6)
    MEM_W(0X88, ctx->r14) = ctx->r13;
    // 0x80048850: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x80048854: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x80048858: sw          $t7, 0x8C($t8)
    MEM_W(0X8C, ctx->r24) = ctx->r15;
    // 0x8004885C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048860: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048864: addiu       $t0, $t0, 0x1FA0
    ctx->r8 = ADD32(ctx->r8, 0X1FA0);
    // 0x80048868: addiu       $t9, $t9, 0x1830
    ctx->r25 = ADD32(ctx->r25, 0X1830);
    // 0x8004886C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048870: sw          $t9, 0x90($t0)
    MEM_W(0X90, ctx->r8) = ctx->r25;
    // 0x80048874: addiu       $t2, $t2, 0x1FA0
    ctx->r10 = ADD32(ctx->r10, 0X1FA0);
    // 0x80048878: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x8004887C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80048880: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80048884: sw          $t1, 0x94($t2)
    MEM_W(0X94, ctx->r10) = ctx->r9;
    // 0x80048888: addiu       $t4, $t4, 0x1FA0
    ctx->r12 = ADD32(ctx->r12, 0X1FA0);
    // 0x8004888C: addiu       $t3, $t3, 0x21C0
    ctx->r11 = ADD32(ctx->r11, 0X21C0);
    // 0x80048890: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048894: sw          $t3, 0x98($t4)
    MEM_W(0X98, ctx->r12) = ctx->r11;
    // 0x80048898: addiu       $t6, $t6, 0x1FA0
    ctx->r14 = ADD32(ctx->r14, 0X1FA0);
    // 0x8004889C: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x800488A0: sw          $t5, 0x9C($t6)
    MEM_W(0X9C, ctx->r14) = ctx->r13;
    // 0x800488A4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800488A8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800488AC: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x800488B0: addiu       $t7, $t7, 0x31C0
    ctx->r15 = ADD32(ctx->r15, 0X31C0);
    // 0x800488B4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800488B8: sw          $t7, 0xA0($t8)
    MEM_W(0XA0, ctx->r24) = ctx->r15;
    // 0x800488BC: addiu       $t9, $t9, 0x31C0
    ctx->r25 = ADD32(ctx->r25, 0X31C0);
    // 0x800488C0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800488C4: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800488C8: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x800488CC: addiu       $t1, $t1, 0x1FA0
    ctx->r9 = ADD32(ctx->r9, 0X1FA0);
    // 0x800488D0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800488D4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800488D8: sw          $t0, 0xA4($t1)
    MEM_W(0XA4, ctx->r9) = ctx->r8;
    // 0x800488DC: addiu       $t2, $t2, 0x25C0
    ctx->r10 = ADD32(ctx->r10, 0X25C0);
    // 0x800488E0: addiu       $t3, $t3, 0x1FA0
    ctx->r11 = ADD32(ctx->r11, 0X1FA0);
    // 0x800488E4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800488E8: sw          $t2, 0xB0($t3)
    MEM_W(0XB0, ctx->r11) = ctx->r10;
    // 0x800488EC: addiu       $t5, $t5, 0x1FA0
    ctx->r13 = ADD32(ctx->r13, 0X1FA0);
    // 0x800488F0: addiu       $t4, $zero, 0xC00
    ctx->r12 = ADD32(0, 0XC00);
    // 0x800488F4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800488F8: sw          $t4, 0xB4($t5)
    MEM_W(0XB4, ctx->r13) = ctx->r12;
    // 0x800488FC: addiu       $t6, $t6, 0x20B8
    ctx->r14 = ADD32(ctx->r14, 0X20B8);
    // 0x80048900: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80048904: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80048908: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x8004890C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048910: addiu       $t9, $t9, 0x1FA0
    ctx->r25 = ADD32(ctx->r25, 0X1FA0);
    // 0x80048914: sw          $t7, 0xA8($t8)
    MEM_W(0XA8, ctx->r24) = ctx->r15;
    // 0x80048918: sw          $zero, 0xAC($t9)
    MEM_W(0XAC, ctx->r25) = 0;
    // 0x8004891C: jal         0x80076EA0
    // 0x80048920: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80076EA0(rdram, ctx);
        goto after_4;
    // 0x80048920: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80048924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048928: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004892C: jr          $ra
    // 0x80048930: nop

    return;
    // 0x80048930: nop

;}

RECOMP_FUNC void Main_RunFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048B64: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80048B68: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80048B6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80048B70: lw          $a0, -0x41E4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X41E4);
    // 0x80048B74: jal         0x800A3A8C
    // 0x80048B78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    frametime_update(rdram, ctx);
        goto after_0;
    // 0x80048B78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80048B7C: jal         0x800B6540
    // 0x80048B80: nop

    osGetCount_recomp(rdram, ctx);
        goto after_1;
    // 0x80048B80: nop

    after_1:
    // 0x80048B84: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048B88: lhu         $t6, 0x20B0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X20B0);
    // 0x80048B8C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80048B90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80048B94: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80048B98: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80048B9C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80048BA0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80048BA4: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x80048BA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80048BAC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80048BB0: sw          $v0, -0x6A18($at)
    MEM_W(-0X6A18, ctx->r1) = ctx->r2;
    // 0x80048BB4: jal         0x800B6550
    // 0x80048BB8: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    osGetTime_recomp(rdram, ctx);
        goto after_2;
    // 0x80048BB8: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    after_2:
    // 0x80048BBC: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x80048BC0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048BC4: lw          $t1, 0x54($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X54);
    // 0x80048BC8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80048BCC: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x80048BD0: sw          $v1, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r3;
    // 0x80048BD4: lhu         $t2, 0x20B0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X20B0);
    // 0x80048BD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048BDC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80048BE0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80048BE4: lw          $t4, 0x20B8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20B8);
    // 0x80048BE8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80048BEC: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80048BF0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048BF4: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x80048BF8: lw          $t5, 0x20C8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20C8);
    // 0x80048BFC: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80048C00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048C04: sw          $t5, 0x20D0($at)
    MEM_W(0X20D0, ctx->r1) = ctx->r13;
    // 0x80048C08: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x80048C0C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80048C10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048C14: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80048C18: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x80048C1C: lui         $t8, 0xDB06
    ctx->r24 = S32(0XDB06 << 16);
    // 0x80048C20: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80048C24: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80048C28: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80048C2C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80048C30: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x80048C34: lui         $t4, 0xDB06
    ctx->r12 = S32(0XDB06 << 16);
    // 0x80048C38: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80048C3C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80048C40: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80048C44: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x80048C48: ori         $t4, $t4, 0x8
    ctx->r12 = ctx->r12 | 0X8;
    // 0x80048C4C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80048C50: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80048C54: lhu         $t5, 0x20B0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X20B0);
    // 0x80048C58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80048C5C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80048C60: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80048C64: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80048C68: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80048C6C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80048C70: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80048C74: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80048C78: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80048C7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80048C80: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80048C84: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x80048C88: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80048C8C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80048C90: addiu       $t8, $t8, -0x5300
    ctx->r24 = ADD32(ctx->r24, -0X5300);
    // 0x80048C94: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80048C98: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80048C9C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80048CA0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80048CA4: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x80048CA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048CAC: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // 0x80048CB0: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80048CB4: lui         $t4, 0xDB06
    ctx->r12 = S32(0XDB06 << 16);
    // 0x80048CB8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80048CBC: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x80048CC0: ori         $t4, $t4, 0xC
    ctx->r12 = ctx->r12 | 0XC;
    // 0x80048CC4: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80048CC8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80048CCC: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80048CD0: addiu       $t5, $t5, 0x400
    ctx->r13 = ADD32(ctx->r13, 0X400);
    // 0x80048CD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80048CD8: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80048CDC: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80048CE0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80048CE4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80048CE8: lhu         $a1, 0x20B0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X20B0);
    // 0x80048CEC: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x80048CF0: jal         0x80048A6C
    // 0x80048CF4: nop

    wonders4_BuildScissoredFillRectDL(rdram, ctx);
        goto after_3;
    // 0x80048CF4: nop

    after_3:
    // 0x80048CF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048CFC: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
    // 0x80048D00: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80048D04: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80048D08: lhu         $a1, 0x20B0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X20B0);
    // 0x80048D0C: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x80048D10: jal         0x80048934
    // 0x80048D14: nop

    wonders4_BuildFillRectDL(rdram, ctx);
        goto after_4;
    // 0x80048D14: nop

    after_4:
    // 0x80048D18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048D1C: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
    // 0x80048D20: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80048D24: lw          $t8, 0x20C0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X20C0);
    // 0x80048D28: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80048D2C: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x80048D30: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80048D34: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80048D38: sw          $t9, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r25;
    // 0x80048D3C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80048D40: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80048D44: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80048D48: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80048D4C: lw          $t4, 0x20C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20C0);
    // 0x80048D50: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80048D54: lw          $t5, -0x2B0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2B0);
    // 0x80048D58: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x80048D5C: sw          $t3, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r11;
    // 0x80048D60: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x80048D64: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80048D68: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80048D6C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80048D70: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x80048D74: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80048D78: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048D7C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80048D80: lhu         $t0, 0x20B0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X20B0);
    // 0x80048D84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80048D88: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80048D8C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80048D90: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80048D94: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80048D98: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80048D9C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80048DA0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80048DA4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80048DA8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80048DAC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80048DB0: sll         $t1, $t1, 7
    ctx->r9 = S32(ctx->r9 << 7);
    // 0x80048DB4: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x80048DB8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80048DBC: addiu       $t4, $t4, -0x5300
    ctx->r12 = ADD32(ctx->r12, -0X5300);
    // 0x80048DC0: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x80048DC4: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80048DC8: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80048DCC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80048DD0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048DD4: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80048DD8: lw          $t8, -0x2A0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A0);
    // 0x80048DDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048DE0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80048DE4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80048DE8: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x80048DEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80048DF0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80048DF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80048DF8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80048DFC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80048E00: lw          $t3, -0x29C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X29C);
    // 0x80048E04: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80048E08: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80048E0C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80048E10: nop

    // 0x80048E14: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80048E18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048E1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80048E20: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80048E24: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80048E28: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80048E2C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80048E30: andi        $t1, $t0, 0xFFF
    ctx->r9 = ctx->r8 & 0XFFF;
    // 0x80048E34: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x80048E38: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x80048E3C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80048E40: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80048E44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048E48: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80048E4C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80048E50: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80048E54: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80048E58: nop

    // 0x80048E5C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80048E60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048E64: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80048E68: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80048E6C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80048E70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048E74: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80048E78: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80048E7C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80048E80: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80048E84: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80048E88: lw          $t0, -0x298($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X298);
    // 0x80048E8C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80048E90: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80048E94: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80048E98: lw          $t4, -0x294($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X294);
    // 0x80048E9C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80048EA0: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x80048EA4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80048EA8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80048EAC: lui         $t4, 0xFE00
    ctx->r12 = S32(0XFE00 << 16);
    // 0x80048EB0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80048EB4: nop

    // 0x80048EB8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80048EBC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048EC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80048EC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80048EC8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80048ECC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80048ED0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80048ED4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80048ED8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80048EDC: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x80048EE0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80048EE4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80048EE8: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x80048EEC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80048EF0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80048EF4: nop

    // 0x80048EF8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80048EFC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048F00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80048F04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048F08: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80048F0C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80048F10: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80048F14: andi        $t0, $t9, 0xFFF
    ctx->r8 = ctx->r25 & 0XFFF;
    // 0x80048F18: or          $t1, $t6, $t0
    ctx->r9 = ctx->r14 | ctx->r8;
    // 0x80048F1C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80048F20: lw          $t3, 0x20C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20C0);
    // 0x80048F24: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80048F28: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x80048F2C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80048F30: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x80048F34: sw          $t5, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r13;
    // 0x80048F38: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x80048F3C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80048F40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80048F44: addiu       $t8, $t8, 0x400
    ctx->r24 = ADD32(ctx->r24, 0X400);
    // 0x80048F48: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80048F4C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048F50: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80048F54: lw          $t0, 0x20C0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X20C0);
    // 0x80048F58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048F5C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80048F60: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80048F64: lui         $t2, 0xDB04
    ctx->r10 = S32(0XDB04 << 16);
    // 0x80048F68: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80048F6C: sw          $t1, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r9;
    // 0x80048F70: ori         $t2, $t2, 0x4
    ctx->r10 = ctx->r10 | 0X4;
    // 0x80048F74: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80048F78: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80048F7C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80048F80: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80048F84: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x80048F88: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x80048F8C: lui         $t9, 0xDB04
    ctx->r25 = S32(0XDB04 << 16);
    // 0x80048F90: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x80048F94: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80048F98: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80048F9C: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x80048FA0: ori         $t9, $t9, 0xC
    ctx->r25 = ctx->r25 | 0XC;
    // 0x80048FA4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80048FA8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80048FAC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80048FB0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048FB4: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80048FB8: lw          $t2, 0x20C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20C0);
    // 0x80048FBC: lui         $t5, 0xDB04
    ctx->r13 = S32(0XDB04 << 16);
    // 0x80048FC0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80048FC4: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80048FC8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80048FCC: sw          $t3, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r11;
    // 0x80048FD0: ori         $t5, $t5, 0x14
    ctx->r13 = ctx->r13 | 0X14;
    // 0x80048FD4: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x80048FD8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80048FDC: ori         $t7, $zero, 0xFFFD
    ctx->r15 = 0 | 0XFFFD;
    // 0x80048FE0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048FE4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80048FE8: lw          $t9, 0x20C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20C0);
    // 0x80048FEC: lui         $t0, 0xDB04
    ctx->r8 = S32(0XDB04 << 16);
    // 0x80048FF0: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80048FF4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80048FF8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80048FFC: sw          $t6, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r14;
    // 0x80049000: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x80049004: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80049008: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8004900C: ori         $t2, $zero, 0xFFFD
    ctx->r10 = 0 | 0XFFFD;
    // 0x80049010: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80049014: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x80049018: lw          $t5, 0x20C0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20C0);
    // 0x8004901C: lui         $t7, 0xD9D0
    ctx->r15 = S32(0XD9D0 << 16);
    // 0x80049020: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80049024: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80049028: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x8004902C: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x80049030: ori         $t7, $t7, 0xF9FA
    ctx->r15 = ctx->r15 | 0XF9FA;
    // 0x80049034: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80049038: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8004903C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80049040: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80049044: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80049048: lui         $t1, 0xD9FF
    ctx->r9 = S32(0XD9FF << 16);
    // 0x8004904C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80049050: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80049054: addiu       $t0, $t6, 0x8
    ctx->r8 = ADD32(ctx->r14, 0X8);
    // 0x80049058: sw          $t0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r8;
    // 0x8004905C: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80049060: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80049064: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80049068: lui         $t3, 0x22
    ctx->r11 = S32(0X22 << 16);
    // 0x8004906C: ori         $t3, $t3, 0x5
    ctx->r11 = ctx->r11 | 0X5;
    // 0x80049070: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80049074: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80049078: lw          $t4, 0x20C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20C0);
    // 0x8004907C: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x80049080: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80049084: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80049088: addiu       $t7, $t4, 0x8
    ctx->r15 = ADD32(ctx->r12, 0X8);
    // 0x8004908C: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x80049090: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80049094: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80049098: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8004909C: addiu       $t6, $t6, -0x290
    ctx->r14 = ADD32(ctx->r14, -0X290);
    // 0x800490A0: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800490A4: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x800490A8: lbu         $t1, -0x1A4($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X1A4);
    // 0x800490AC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800490B0: beq         $t1, $zero, L_80049110
    if (ctx->r9 == 0) {
        // 0x800490B4: nop
    
            goto L_80049110;
    }
    // 0x800490B4: nop

    // 0x800490B8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800490BC:
    // 0x800490BC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800490C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800490C4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800490C8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800490CC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800490D0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800490D4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800490D8: addiu       $t5, $t5, -0x10D0
    ctx->r13 = ADD32(ctx->r13, -0X10D0);
    // 0x800490DC: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x800490E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800490E4: jal         0x8004A5F0
    // 0x800490E8: sw          $t4, -0xDF0($at)
    MEM_W(-0XDF0, ctx->r1) = ctx->r12;
    System_Init(rdram, ctx);
        goto after_5;
    // 0x800490E8: sw          $t4, -0xDF0($at)
    MEM_W(-0XDF0, ctx->r1) = ctx->r12;
    after_5:
    // 0x800490EC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800490F0: nop

    // 0x800490F4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800490F8: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800490FC: bne         $at, $zero, L_800490BC
    if (ctx->r1 != 0) {
        // 0x80049100: sw          $t8, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r24;
            goto L_800490BC;
    }
    // 0x80049100: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80049104: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049108: b           L_80049170
    // 0x8004910C: sb          $zero, -0x1DC($at)
    MEM_B(-0X1DC, ctx->r1) = 0;
        goto L_80049170;
    // 0x8004910C: sb          $zero, -0x1DC($at)
    MEM_B(-0X1DC, ctx->r1) = 0;
L_80049110:
    // 0x80049110: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80049114: lh          $t9, -0x12C($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X12C);
    // 0x80049118: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8004911C: blez        $t9, L_80049170
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80049120: nop
    
            goto L_80049170;
    }
    // 0x80049120: nop

L_80049124:
    // 0x80049124: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80049128: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004912C: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80049130: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x80049134: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80049138: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x8004913C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80049140: addiu       $t1, $t1, -0x10D0
    ctx->r9 = ADD32(ctx->r9, -0X10D0);
    // 0x80049144: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80049148: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004914C: jal         0x8004A5F0
    // 0x80049150: sw          $t2, -0xDF0($at)
    MEM_W(-0XDF0, ctx->r1) = ctx->r10;
    System_Init(rdram, ctx);
        goto after_6;
    // 0x80049150: sw          $t2, -0xDF0($at)
    MEM_W(-0XDF0, ctx->r1) = ctx->r10;
    after_6:
    // 0x80049154: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80049158: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8004915C: lh          $t4, -0x12C($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X12C);
    // 0x80049160: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80049164: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80049168: bne         $at, $zero, L_80049124
    if (ctx->r1 != 0) {
        // 0x8004916C: sw          $t5, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r13;
            goto L_80049124;
    }
    // 0x8004916C: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
L_80049170:
    // 0x80049170: jal         0x8006CF14
    // 0x80049174: nop

    Scene_Update(rdram, ctx);
        goto after_7;
    // 0x80049174: nop

    after_7:
    // 0x80049178: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8004917C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80049180: lw          $t8, 0x60($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X60);
    // 0x80049184: lw          $t9, 0x64($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X64);
    // 0x80049188: sw          $t8, -0x6A10($at)
    MEM_W(-0X6A10, ctx->r1) = ctx->r24;
    // 0x8004918C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80049190: jal         0x800B6540
    // 0x80049194: sw          $t9, -0x6A0C($at)
    MEM_W(-0X6A0C, ctx->r1) = ctx->r25;
    osGetCount_recomp(rdram, ctx);
        goto after_8;
    // 0x80049194: sw          $t9, -0x6A0C($at)
    MEM_W(-0X6A0C, ctx->r1) = ctx->r25;
    after_8:
    // 0x80049198: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004919C: sw          $v0, -0x6A1C($at)
    MEM_W(-0X6A1C, ctx->r1) = ctx->r2;
    // 0x800491A0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800491A4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800491A8: lw          $t6, -0x6A1C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6A1C);
    // 0x800491AC: lbu         $t0, -0x120($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X120);
    // 0x800491B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800491B4: beq         $t0, $zero, L_800491C8
    if (ctx->r8 == 0) {
        // 0x800491B8: sw          $t6, -0x6A14($at)
        MEM_W(-0X6A14, ctx->r1) = ctx->r14;
            goto L_800491C8;
    }
    // 0x800491B8: sw          $t6, -0x6A14($at)
    MEM_W(-0X6A14, ctx->r1) = ctx->r14;
    // 0x800491BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800491C0: jal         0x800A9010
    // 0x800491C4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    wonders4_ComputeClampedRatio(rdram, ctx);
        goto after_9;
    // 0x800491C4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_9:
L_800491C8:
    // 0x800491C8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800491CC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800491D0: lw          $t1, -0x6A1C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6A1C);
    // 0x800491D4: lw          $t2, 0x20C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20C0);
    // 0x800491D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800491DC: sw          $t1, -0x6A20($at)
    MEM_W(-0X6A20, ctx->r1) = ctx->r9;
    // 0x800491E0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800491E4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800491E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800491EC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800491F0: sw          $t3, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r11;
    // 0x800491F4: lui         $t5, 0xE900
    ctx->r13 = S32(0XE900 << 16);
    // 0x800491F8: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800491FC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80049200: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80049204: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80049208: lw          $t8, 0x20C0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X20C0);
    // 0x8004920C: lui         $t6, 0xDF00
    ctx->r14 = S32(0XDF00 << 16);
    // 0x80049210: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80049214: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80049218: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8004921C: sw          $t9, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r25;
    // 0x80049220: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80049224: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80049228: jal         0x80048020
    // 0x8004922C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    wonders4_UpdateMaxScroll(rdram, ctx);
        goto after_10;
    // 0x8004922C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_10:
    // 0x80049230: jal         0x800480E0
    // 0x80049234: nop

    wonders4_DebugPrintGList(rdram, ctx);
        goto after_11;
    // 0x80049234: nop

    after_11:
    // 0x80049238: jal         0x80048150
    // 0x8004923C: nop

    wonders4_DebugPrintVList(rdram, ctx);
        goto after_12;
    // 0x8004923C: nop

    after_12:
    // 0x80049240: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80049244: lhu         $t3, 0x20B0($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X20B0);
    // 0x80049248: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8004924C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80049250: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x80049254: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80049258: lw          $t2, 0x20C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20C0);
    // 0x8004925C: lw          $t4, 0x20B8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20B8);
    // 0x80049260: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80049264: subu        $t7, $t2, $t4
    ctx->r15 = SUB32(ctx->r10, ctx->r12);
    // 0x80049268: sw          $t7, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r15;
    // 0x8004926C: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80049270: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x80049274: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80049278: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8004927C: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80049280: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80049284: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80049288: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004928C: addiu       $a0, $a0, -0x4460
    ctx->r4 = ADD32(ctx->r4, -0X4460);
    // 0x80049290: sw          $t0, 0x60($t3)
    MEM_W(0X60, ctx->r11) = ctx->r8;
    // 0x80049294: jal         0x8005EE84
    // 0x80049298: sw          $t1, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->r9;
    osScGetCmdQ(rdram, ctx);
        goto after_13;
    // 0x80049298: sw          $t1, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->r9;
    after_13:
    // 0x8004929C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800492A0: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x800492A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800492A8: jal         0x800B34D0
    // 0x800492AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x800492AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x800492B0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800492B4: lw          $t5, -0x110($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X110);
    // 0x800492B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800492BC: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x800492C0: jal         0x800B6550
    // 0x800492C4: sw          $t2, -0x110($at)
    MEM_W(-0X110, ctx->r1) = ctx->r10;
    osGetTime_recomp(rdram, ctx);
        goto after_15;
    // 0x800492C4: sw          $t2, -0x110($at)
    MEM_W(-0X110, ctx->r1) = ctx->r10;
    after_15:
    // 0x800492C8: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x800492CC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800492D0: lw          $t7, 0x54($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X54);
    // 0x800492D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800492D8: sw          $v0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r2;
    // 0x800492DC: sw          $v1, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r3;
    // 0x800492E0: lw          $t8, -0x128($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X128);
    // 0x800492E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800492E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800492EC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800492F0: sw          $t9, -0x128($at)
    MEM_W(-0X128, ctx->r1) = ctx->r25;
    // 0x800492F4: jr          $ra
    // 0x800492F8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800492F8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}

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

    Main_RunFrame(rdram, ctx);
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
    Main_LoadRomAssetTable(rdram, ctx);
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

    Main_InitVideo(rdram, ctx);
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
    Minos_QueueInit(rdram, ctx);
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

RECOMP_FUNC void Main_LoadRomAssetTable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9E44: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A9E48: addiu       $v0, $v0, -0x6A00
    ctx->r2 = ADD32(ctx->r2, -0X6A00);
    // 0x800A9E4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A9E50: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800A9E54: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A9E58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9E5C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800A9E60: sw          $a1, -0x69FC($at)
    MEM_W(-0X69FC, ctx->r1) = ctx->r5;
    // 0x800A9E64: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A9E68: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800A9E6C: jal         0x800ABFF0
    // 0x800A9E70: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Main_RequestRomDma(rdram, ctx);
        goto after_0;
    // 0x800A9E70: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800A9E74: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800A9E78: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A9E7C: addiu       $a1, $a1, -0x69F8
    ctx->r5 = ADD32(ctx->r5, -0X69F8);
    // 0x800A9E80: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800A9E84: jal         0x8007E03C
    // 0x800A9E88: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800A9E88: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    after_1:
    // 0x800A9E8C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A9E90: addiu       $a1, $a1, -0x69F8
    ctx->r5 = ADD32(ctx->r5, -0X69F8);
    // 0x800A9E94: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A9E98: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A9E9C: addiu       $a0, $a0, 0x7B00
    ctx->r4 = ADD32(ctx->r4, 0X7B00);
    // 0x800A9EA0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800A9EA4: blez        $t7, L_800A9EE0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A9EA8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800A9EE0;
    }
    // 0x800A9EA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A9EAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A9EB0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
L_800A9EB4:
    // 0x800A9EB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A9EB8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800A9EBC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800A9EC0: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800A9EC4: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x800A9EC8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A9ECC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A9ED0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800A9ED4: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A9ED8: bnel        $at, $zero, L_800A9EB4
    if (ctx->r1 != 0) {
        // 0x800A9EDC: lw          $t8, 0x0($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X0);
            goto L_800A9EB4;
    }
    goto skip_0;
    // 0x800A9EDC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    skip_0:
L_800A9EE0:
    // 0x800A9EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9EE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A9EE8: jr          $ra
    // 0x800A9EEC: nop

    return;
    // 0x800A9EEC: nop

;}

RECOMP_FUNC void func_800A9EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9EF0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A9EF4: addiu       $v0, $v0, -0x6A00
    ctx->r2 = ADD32(ctx->r2, -0X6A00);
    // 0x800A9EF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A9EFC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800A9F00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A9F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9F08: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800A9F0C: sw          $a1, -0x69FC($at)
    MEM_W(-0X69FC, ctx->r1) = ctx->r5;
    // 0x800A9F10: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A9F14: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800A9F18: jal         0x800ABFF0
    // 0x800A9F1C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Main_RequestRomDma(rdram, ctx);
        goto after_0;
    // 0x800A9F1C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800A9F20: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800A9F24: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A9F28: addiu       $a1, $a1, -0x69F8
    ctx->r5 = ADD32(ctx->r5, -0X69F8);
    // 0x800A9F2C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800A9F30: jal         0x8007E03C
    // 0x800A9F34: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800A9F34: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    after_1:
    // 0x800A9F38: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A9F3C: addiu       $a1, $a1, -0x69F8
    ctx->r5 = ADD32(ctx->r5, -0X69F8);
    // 0x800A9F40: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A9F44: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A9F48: addiu       $a0, $a0, 0x7B00
    ctx->r4 = ADD32(ctx->r4, 0X7B00);
    // 0x800A9F4C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800A9F50: blez        $t7, L_800A9F8C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A9F54: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800A9F8C;
    }
    // 0x800A9F54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A9F58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A9F5C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
L_800A9F60:
    // 0x800A9F60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A9F64: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800A9F68: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800A9F6C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800A9F70: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x800A9F74: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A9F78: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A9F7C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800A9F80: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A9F84: bnel        $at, $zero, L_800A9F60
    if (ctx->r1 != 0) {
        // 0x800A9F88: lw          $t8, 0x0($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X0);
            goto L_800A9F60;
    }
    goto skip_0;
    // 0x800A9F88: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    skip_0:
L_800A9F8C:
    // 0x800A9F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9F90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A9F94: jr          $ra
    // 0x800A9F98: nop

    return;
    // 0x800A9F98: nop

;}

RECOMP_FUNC void Main_LoadRomAsset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9F9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A9FA0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800A9FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9FA8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A9FAC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800A9FB0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800A9FB4: beq         $t6, $zero, L_800A9FD0
    if (ctx->r14 == 0) {
        // 0x800A9FB8: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_800A9FD0;
    }
    // 0x800A9FB8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800A9FBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9FC0: beq         $t6, $at, L_800A9FE8
    if (ctx->r14 == ctx->r1) {
        // 0x800A9FC4: nop
    
            goto L_800A9FE8;
    }
    // 0x800A9FC4: nop

    // 0x800A9FC8: b           L_800AA02C
    // 0x800A9FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA02C;
    // 0x800A9FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9FD0:
    // 0x800A9FD0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A9FD4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800A9FD8: jal         0x800ABFF0
    // 0x800A9FDC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    Main_RequestRomDma(rdram, ctx);
        goto after_0;
    // 0x800A9FDC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x800A9FE0: b           L_800AA02C
    // 0x800A9FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA02C;
    // 0x800A9FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9FE8:
    // 0x800A9FE8: jal         0x8007E03C
    // 0x800A9FEC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800A9FEC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x800A9FF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800A9FF4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A9FF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800A9FFC: jal         0x800ABFF0
    // 0x800AA000: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    Main_RequestRomDma(rdram, ctx);
        goto after_2;
    // 0x800AA000: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x800AA004: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800AA008: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800AA00C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800AA010: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800AA014: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800AA018: jal         0x80080EC8
    // 0x800AA01C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    strutil_lzo_decompress(rdram, ctx);
        goto after_3;
    // 0x800AA01C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_3:
    // 0x800AA020: jal         0x8007E328
    // 0x800AA024: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    n64HeapUnalloc(rdram, ctx);
        goto after_4;
    // 0x800AA024: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x800AA028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA02C:
    // 0x800AA02C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AA030: jr          $ra
    // 0x800AA034: nop

    return;
    // 0x800AA034: nop

;}

RECOMP_FUNC void func_800AA038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA038: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AA03C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800AA040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA044: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AA048: lw          $a0, -0x6A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A00);
    // 0x800AA04C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800AA050: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800AA054: jal         0x800ABFF0
    // 0x800AA058: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Main_RequestRomDma(rdram, ctx);
        goto after_0;
    // 0x800AA058: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800AA05C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800AA060: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800AA064: bltz        $a3, L_800AA074
    if (SIGNED(ctx->r7) < 0) {
        // 0x800AA068: slt         $at, $a3, $t6
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_800AA074;
    }
    // 0x800AA068: slt         $at, $a3, $t6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AA06C: bne         $at, $zero, L_800AA07C
    if (ctx->r1 != 0) {
        // 0x800AA070: sll         $t7, $a3, 4
        ctx->r15 = S32(ctx->r7 << 4);
            goto L_800AA07C;
    }
    // 0x800AA070: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
L_800AA074:
    // 0x800AA074: b           L_800AA09C
    // 0x800AA078: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AA09C;
    // 0x800AA078: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AA07C:
    // 0x800AA07C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800AA080: lw          $t8, -0x6A00($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6A00);
    // 0x800AA084: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800AA088: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AA08C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800AA090: jal         0x800ABFF0
    // 0x800AA094: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    Main_RequestRomDma(rdram, ctx);
        goto after_1;
    // 0x800AA094: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x800AA098: lh          $v0, 0x20($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X20);
L_800AA09C:
    // 0x800AA09C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA0A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AA0A4: jr          $ra
    // 0x800AA0A8: nop

    return;
    // 0x800AA0A8: nop

;}

RECOMP_FUNC void func_800AA0AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA0AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AA0B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AA0B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA0B8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800AA0BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AA0C0: lw          $a0, -0x6A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A00);
    // 0x800AA0C4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800AA0C8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800AA0CC: jal         0x800ABFF0
    // 0x800AA0D0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Main_RequestRomDma(rdram, ctx);
        goto after_0;
    // 0x800AA0D0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800AA0D4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800AA0D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800AA0DC: bltz        $a3, L_800AA0EC
    if (SIGNED(ctx->r7) < 0) {
        // 0x800AA0E0: slt         $at, $a3, $t6
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_800AA0EC;
    }
    // 0x800AA0E0: slt         $at, $a3, $t6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AA0E4: bne         $at, $zero, L_800AA0F4
    if (ctx->r1 != 0) {
        // 0x800AA0E8: sll         $t7, $a3, 4
        ctx->r15 = S32(ctx->r7 << 4);
            goto L_800AA0F4;
    }
    // 0x800AA0E8: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
L_800AA0EC:
    // 0x800AA0EC: b           L_800AA124
    // 0x800AA0F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AA124;
    // 0x800AA0F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AA0F4:
    // 0x800AA0F4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800AA0F8: lw          $t8, -0x6A00($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6A00);
    // 0x800AA0FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800AA100: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AA104: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800AA108: jal         0x800ABFF0
    // 0x800AA10C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    Main_RequestRomDma(rdram, ctx);
        goto after_1;
    // 0x800AA10C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x800AA110: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800AA114: lb          $at, 0x0($t9)
    ctx->r1 = MEM_B(ctx->r25, 0X0);
    // 0x800AA118: lbu         $v0, 0x1($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X1);
    // 0x800AA11C: sll         $at, $at, 8
    ctx->r1 = S32(ctx->r1 << 8);
    // 0x800AA120: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_800AA124:
    // 0x800AA124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA128: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AA12C: jr          $ra
    // 0x800AA130: nop

    return;
    // 0x800AA130: nop

;}

RECOMP_FUNC void func_800AA134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA134: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800AA138: lw          $t6, 0x7B00($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B00);
    // 0x800AA13C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800AA140: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AA144: jr          $ra
    // 0x800AA148: lw          $v0, 0x4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X4);
    return;
    // 0x800AA148: lw          $v0, 0x4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X4);
;}

RECOMP_FUNC void Main_DoPiDma(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABE00: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800ABE04: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800ABE08: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800ABE0C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800ABE10: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800ABE14: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800ABE18: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800ABE1C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800ABE20: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800ABE24: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800ABE28: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800ABE2C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800ABE30: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800ABE34: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800ABE38: addiu       $s3, $s3, -0x35F0
    ctx->r19 = ADD32(ctx->r19, -0X35F0);
    // 0x800ABE3C: addiu       $s1, $s1, -0x3524
    ctx->r17 = ADD32(ctx->r17, -0X3524);
    // 0x800ABE40: addiu       $s0, $s0, -0x35B8
    ctx->r16 = ADD32(ctx->r16, -0X35B8);
    // 0x800ABE44: addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
    // 0x800ABE48: addiu       $s4, $sp, 0x70
    ctx->r20 = ADD32(ctx->r29, 0X70);
    // 0x800ABE4C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800ABE50: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800ABE54: addiu       $s7, $sp, 0x78
    ctx->r23 = ADD32(ctx->r29, 0X78);
    // 0x800ABE58: addiu       $fp, $sp, 0x74
    ctx->r30 = ADD32(ctx->r29, 0X74);
    // 0x800ABE5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800ABE60:
    // 0x800ABE60: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800ABE64: jal         0x800B3C20
    // 0x800ABE68: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800ABE68: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
    // 0x800ABE6C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800ABE70: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800ABE74: lbu         $v1, 0xC($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XC);
    // 0x800ABE78: beql        $v1, $zero, L_800ABE9C
    if (ctx->r3 == 0) {
        // 0x800ABE7C: lw          $a0, 0x4($t7)
        ctx->r4 = MEM_W(ctx->r15, 0X4);
            goto L_800ABE9C;
    }
    goto skip_0;
    // 0x800ABE7C: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    skip_0:
    // 0x800ABE80: beq         $v1, $s5, L_800ABEE8
    if (ctx->r3 == ctx->r21) {
        // 0x800ABE84: lw          $t1, 0x70($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X70);
            goto L_800ABEE8;
    }
    // 0x800ABE84: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800ABE88: beq         $v1, $s6, L_800ABF48
    if (ctx->r3 == ctx->r22) {
        // 0x800ABE8C: lw          $t7, 0x70($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X70);
            goto L_800ABF48;
    }
    // 0x800ABE8C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800ABE90: b           L_800ABFA4
    // 0x800ABE94: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
        goto L_800ABFA4;
    // 0x800ABE94: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800ABE98: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
L_800ABE9C:
    // 0x800ABE9C: jal         0x800BAFA0
    // 0x800ABEA0: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x800ABEA0: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    after_1:
    // 0x800ABEA4: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800ABEA8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800ABEAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800ABEB0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800ABEB4: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x800ABEB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800ABEBC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800ABEC0: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x800ABEC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ABEC8: jal         0x800BB050
    // 0x800ABECC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    osPiStartDma_recomp(rdram, ctx);
        goto after_2;
    // 0x800ABECC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_2:
    // 0x800ABED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ABED4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800ABED8: jal         0x800B3C20
    // 0x800ABEDC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800ABEDC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x800ABEE0: b           L_800ABFA4
    // 0x800ABEE4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
        goto L_800ABFA4;
    // 0x800ABEE4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
L_800ABEE8:
    // 0x800ABEE8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800ABEEC: jal         0x800BB160
    // 0x800ABEF0: lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X8);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_4;
    // 0x800ABEF0: lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X8);
    after_4:
    // 0x800ABEF4: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x800ABEF8: sb          $zero, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = 0;
    // 0x800ABEFC: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
    // 0x800ABF00: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800ABF04: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ABF08: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800ABF0C: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x800ABF10: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x800ABF14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800ABF18: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x800ABF1C: lw          $t5, 0x8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8);
    // 0x800ABF20: jal         0x800BB1E0
    // 0x800ABF24: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    osEPiStartDma_recomp(rdram, ctx);
        goto after_5;
    // 0x800ABF24: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    after_5:
    // 0x800ABF28: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800ABF2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ABF30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800ABF34: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800ABF38: jal         0x800B3C20
    // 0x800ABF3C: sw          $v0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r2;
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800ABF3C: sw          $v0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r2;
    after_6:
    // 0x800ABF40: b           L_800ABFA4
    // 0x800ABF44: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
        goto L_800ABFA4;
    // 0x800ABF44: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
L_800ABF48:
    // 0x800ABF48: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800ABF4C: jal         0x800BB160
    // 0x800ABF50: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_7;
    // 0x800ABF50: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    after_7:
    // 0x800ABF54: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800ABF58: sb          $zero, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = 0;
    // 0x800ABF5C: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
    // 0x800ABF60: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800ABF64: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ABF68: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800ABF6C: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800ABF70: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800ABF74: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800ABF78: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x800ABF7C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x800ABF80: jal         0x800BB1E0
    // 0x800ABF84: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    osEPiStartDma_recomp(rdram, ctx);
        goto after_8;
    // 0x800ABF84: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    after_8:
    // 0x800ABF88: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800ABF8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ABF90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800ABF94: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800ABF98: jal         0x800B3C20
    // 0x800ABF9C: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    osRecvMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x800ABF9C: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    after_9:
    // 0x800ABFA0: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
L_800ABFA4:
    // 0x800ABFA4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800ABFA8: jal         0x800B34D0
    // 0x800ABFAC: lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X10);
    osSendMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x800ABFAC: lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X10);
    after_10:
    // 0x800ABFB0: b           L_800ABE60
    // 0x800ABFB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_800ABE60;
    // 0x800ABFB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800ABFB8: nop

    // 0x800ABFBC: nop

    // 0x800ABFC0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800ABFC4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800ABFC8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800ABFCC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800ABFD0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800ABFD4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800ABFD8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800ABFDC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800ABFE0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800ABFE4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800ABFE8: jr          $ra
    // 0x800ABFEC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800ABFEC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}

RECOMP_FUNC void Main_RequestRomDma(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABFF0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800ABFF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ABFF8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800ABFFC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800AC000: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800AC004: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC008: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800AC00C: jal         0x800B3080
    // 0x800AC010: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800AC010: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x800AC014: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800AC018: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800AC01C: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800AC020: addiu       $t9, $sp, 0x38
    ctx->r25 = ADD32(ctx->r29, 0X38);
    // 0x800AC024: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC028: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800AC02C: sb          $zero, 0x28($sp)
    MEM_B(0X28, ctx->r29) = 0;
    // 0x800AC030: addiu       $a0, $a0, -0x35F0
    ctx->r4 = ADD32(ctx->r4, -0X35F0);
    // 0x800AC034: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800AC038: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC03C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800AC040: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800AC044: jal         0x800B34D0
    // 0x800AC048: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800AC048: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_1:
    // 0x800AC04C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800AC050: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800AC054: jal         0x800B3C20
    // 0x800AC058: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800AC058: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800AC05C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AC060: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800AC064: jr          $ra
    // 0x800AC068: nop

    return;
    // 0x800AC068: nop

;}

RECOMP_FUNC void Main_StartRomDmaThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC06C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AC070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AC074: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800AC078: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AC07C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800AC080: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC084: addiu       $a0, $a0, -0x35B8
    ctx->r4 = ADD32(ctx->r4, -0X35B8);
    // 0x800AC088: addiu       $a1, $a1, -0x35A0
    ctx->r5 = ADD32(ctx->r5, -0X35A0);
    // 0x800AC08C: jal         0x800B3080
    // 0x800AC090: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800AC090: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800AC094: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC098: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800AC09C: addiu       $a1, $a1, -0x35D8
    ctx->r5 = ADD32(ctx->r5, -0X35D8);
    // 0x800AC0A0: addiu       $a0, $a0, -0x35F0
    ctx->r4 = ADD32(ctx->r4, -0X35F0);
    // 0x800AC0A4: jal         0x800B3080
    // 0x800AC0A8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x800AC0A8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800AC0AC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800AC0B0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800AC0B4: addiu       $t6, $t6, -0x51F0
    ctx->r14 = ADD32(ctx->r14, -0X51F0);
    // 0x800AC0B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC0BC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800AC0C0: addiu       $a2, $a2, -0x4200
    ctx->r6 = ADD32(ctx->r6, -0X4200);
    // 0x800AC0C4: addiu       $a0, $a0, -0x57A0
    ctx->r4 = ADD32(ctx->r4, -0X57A0);
    // 0x800AC0C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800AC0CC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800AC0D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AC0D4: jal         0x800B6010
    // 0x800AC0D8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    osCreateThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800AC0D8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x800AC0DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC0E0: jal         0x800B6160
    // 0x800AC0E4: addiu       $a0, $a0, -0x57A0
    ctx->r4 = ADD32(ctx->r4, -0X57A0);
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x800AC0E4: addiu       $a0, $a0, -0x57A0
    ctx->r4 = ADD32(ctx->r4, -0X57A0);
    after_3:
    // 0x800AC0E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC0EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AC0F0: jr          $ra
    // 0x800AC0F4: nop

    return;
    // 0x800AC0F4: nop

;}

RECOMP_FUNC void Main_InitCartPiHandle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC0F8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800AC0FC: addiu       $a2, $a2, -0x3598
    ctx->r6 = ADD32(ctx->r6, -0X3598);
    // 0x800AC100: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x800AC104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AC108: lui         $v0, 0xA800
    ctx->r2 = S32(0XA800 << 16);
    // 0x800AC10C: bne         $v0, $t6, L_800AC124
    if (ctx->r2 != ctx->r14) {
        // 0x800AC110: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AC124;
    }
    // 0x800AC110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AC114: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC118: addiu       $v0, $v0, -0x3524
    ctx->r2 = ADD32(ctx->r2, -0X3524);
    // 0x800AC11C: b           L_800AC198
    // 0x800AC120: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_800AC198;
    // 0x800AC120: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_800AC124:
    // 0x800AC124: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800AC128: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800AC12C: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x800AC130: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x800AC134: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800AC138: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AC13C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC140: sb          $t7, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r15;
    // 0x800AC144: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x800AC148: sb          $t8, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r24;
    // 0x800AC14C: sb          $t9, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r25;
    // 0x800AC150: sb          $t0, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r8;
    // 0x800AC154: sb          $t1, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r9;
    // 0x800AC158: sb          $t2, 0x9($a2)
    MEM_B(0X9, ctx->r6) = ctx->r10;
    // 0x800AC15C: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x800AC160: addiu       $a0, $a0, -0x3584
    ctx->r4 = ADD32(ctx->r4, -0X3584);
    // 0x800AC164: jal         0x800B7450
    // 0x800AC168: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x800AC168: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_0:
    // 0x800AC16C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800AC170: jal         0x800BB2C0
    // 0x800AC174: addiu       $a0, $a2, -0x3598
    ctx->r4 = ADD32(ctx->r6, -0X3598);
    osEPiLinkHandle(rdram, ctx);
        goto after_1;
    // 0x800AC174: addiu       $a0, $a2, -0x3598
    ctx->r4 = ADD32(ctx->r6, -0X3598);
    after_1:
    // 0x800AC178: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC17C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800AC180: addiu       $a1, $a2, -0x3598
    ctx->r5 = ADD32(ctx->r6, -0X3598);
    // 0x800AC184: addiu       $v0, $v0, -0x3524
    ctx->r2 = ADD32(ctx->r2, -0X3524);
    // 0x800AC188: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AC18C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x800AC190: jal         0x800B3BFC
    // 0x800AC194: addiu       $a0, $a0, 0x1150
    ctx->r4 = ADD32(ctx->r4, 0X1150);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800AC194: addiu       $a0, $a0, 0x1150
    ctx->r4 = ADD32(ctx->r4, 0X1150);
    after_2:
L_800AC198:
    // 0x800AC198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AC19C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AC1A0: jr          $ra
    // 0x800AC1A4: nop

    return;
    // 0x800AC1A4: nop

;}

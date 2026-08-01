#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void GarbageImg_ExtractSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800744D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800744D4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800744D8: lw          $t6, 0x600($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X600);
    // 0x800744DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800744E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800744E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800744E8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800744EC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800744F0: beq         $t6, $zero, L_8007452C
    if (ctx->r14 == 0) {
        // 0x800744F4: sw          $zero, -0x360($at)
        MEM_W(-0X360, ctx->r1) = 0;
            goto L_8007452C;
    }
    // 0x800744F4: sw          $zero, -0x360($at)
    MEM_W(-0X360, ctx->r1) = 0;
L_800744F8:
    // 0x800744F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800744FC: lw          $t7, -0x360($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X360);
    // 0x80074500: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80074504: beq         $t7, $at, L_8007452C
    if (ctx->r15 == ctx->r1) {
        // 0x80074508: nop
    
            goto L_8007452C;
    }
    // 0x80074508: nop

    // 0x8007450C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80074510: lw          $t8, -0x360($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X360);
    // 0x80074514: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80074518: lw          $t0, 0x600($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X600);
    // 0x8007451C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80074520: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80074524: bne         $t0, $zero, L_800744F8
    if (ctx->r8 != 0) {
        // 0x80074528: sw          $t9, -0x360($at)
        MEM_W(-0X360, ctx->r1) = ctx->r25;
            goto L_800744F8;
    }
    // 0x80074528: sw          $t9, -0x360($at)
    MEM_W(-0X360, ctx->r1) = ctx->r25;
L_8007452C:
    // 0x8007452C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80074530: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80074534: jal         0x800B6650
    // 0x80074538: sw          $t1, 0x600($at)
    MEM_W(0X600, ctx->r1) = ctx->r9;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80074538: sw          $t1, 0x600($at)
    MEM_W(0X600, ctx->r1) = ctx->r9;
    after_0:
    // 0x8007453C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80074540: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80074544: jal         0x800ABFF0
    // 0x80074548: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    Main_RequestRomDma(rdram, ctx);
        goto after_1;
    // 0x80074548: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x8007454C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80074550: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80074554: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80074558: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    // 0x8007455C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80074560: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80074564: jal         0x800ABFF0
    // 0x80074568: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Main_RequestRomDma(rdram, ctx);
        goto after_2;
    // 0x80074568: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8007456C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80074570: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80074574: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80074578: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007457C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80074580: addu        $a0, $t5, $t8
    ctx->r4 = ADD32(ctx->r13, ctx->r24);
    // 0x80074584: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80074588: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8007458C: jal         0x800ABFF0
    // 0x80074590: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Main_RequestRomDma(rdram, ctx);
        goto after_3;
    // 0x80074590: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x80074594: addiu       $t9, $sp, 0x18
    ctx->r25 = ADD32(ctx->r29, 0X18);
    // 0x80074598: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x8007459C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800745A0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800745A4: subu        $t3, $t0, $t1
    ctx->r11 = SUB32(ctx->r8, ctx->r9);
    // 0x800745A8: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x800745AC: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x800745B0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800745B4: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800745B8: jal         0x800ABFF0
    // 0x800745BC: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    Main_RequestRomDma(rdram, ctx);
        goto after_4;
    // 0x800745BC: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    after_4:
    // 0x800745C0: jal         0x800B6650
    // 0x800745C4: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_5;
    // 0x800745C4: nop

    after_5:
    // 0x800745C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800745CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800745D0: sw          $zero, 0x600($at)
    MEM_W(0X600, ctx->r1) = 0;
    // 0x800745D4: jr          $ra
    // 0x800745D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800745D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void GarbageImg_GetSpriteSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800745DC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800745E0: lw          $t6, 0x600($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X600);
    // 0x800745E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800745E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800745EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800745F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800745F4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800745F8: beq         $t6, $zero, L_80074634
    if (ctx->r14 == 0) {
        // 0x800745FC: sw          $zero, -0x35C($at)
        MEM_W(-0X35C, ctx->r1) = 0;
            goto L_80074634;
    }
    // 0x800745FC: sw          $zero, -0x35C($at)
    MEM_W(-0X35C, ctx->r1) = 0;
L_80074600:
    // 0x80074600: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80074604: lw          $t7, -0x35C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X35C);
    // 0x80074608: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8007460C: beq         $t7, $at, L_80074634
    if (ctx->r15 == ctx->r1) {
        // 0x80074610: nop
    
            goto L_80074634;
    }
    // 0x80074610: nop

    // 0x80074614: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80074618: lw          $t8, -0x35C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X35C);
    // 0x8007461C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80074620: lw          $t0, 0x600($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X600);
    // 0x80074624: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80074628: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8007462C: bne         $t0, $zero, L_80074600
    if (ctx->r8 != 0) {
        // 0x80074630: sw          $t9, -0x35C($at)
        MEM_W(-0X35C, ctx->r1) = ctx->r25;
            goto L_80074600;
    }
    // 0x80074630: sw          $t9, -0x35C($at)
    MEM_W(-0X35C, ctx->r1) = ctx->r25;
L_80074634:
    // 0x80074634: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80074638: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007463C: jal         0x800B6650
    // 0x80074640: sw          $t1, 0x600($at)
    MEM_W(0X600, ctx->r1) = ctx->r9;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80074640: sw          $t1, 0x600($at)
    MEM_W(0X600, ctx->r1) = ctx->r9;
    after_0:
    // 0x80074644: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80074648: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8007464C: jal         0x800ABFF0
    // 0x80074650: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    Main_RequestRomDma(rdram, ctx);
        goto after_1;
    // 0x80074650: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80074654: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80074658: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007465C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80074660: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    // 0x80074664: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80074668: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8007466C: jal         0x800ABFF0
    // 0x80074670: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Main_RequestRomDma(rdram, ctx);
        goto after_2;
    // 0x80074670: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80074674: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80074678: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007467C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80074680: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80074684: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80074688: addu        $a0, $t5, $t8
    ctx->r4 = ADD32(ctx->r13, ctx->r24);
    // 0x8007468C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80074690: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80074694: jal         0x800ABFF0
    // 0x80074698: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Main_RequestRomDma(rdram, ctx);
        goto after_3;
    // 0x80074698: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x8007469C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800746A0: sw          $zero, 0x600($at)
    MEM_W(0X600, ctx->r1) = 0;
    // 0x800746A4: addiu       $t9, $sp, 0x18
    ctx->r25 = ADD32(ctx->r29, 0X18);
    // 0x800746A8: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800746AC: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800746B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800746B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800746B8: jr          $ra
    // 0x800746BC: subu        $v0, $t0, $t1
    ctx->r2 = SUB32(ctx->r8, ctx->r9);
    return;
    // 0x800746BC: subu        $v0, $t0, $t1
    ctx->r2 = SUB32(ctx->r8, ctx->r9);
;}

RECOMP_FUNC void GarbageImg_DecodeSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800746C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800746C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800746C8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800746CC: lw          $t6, 0x600($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X600);
    // 0x800746D0: sb          $zero, -0x2B4($at)
    MEM_B(-0X2B4, ctx->r1) = 0;
    // 0x800746D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800746D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800746DC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800746E0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800746E4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800746E8: beq         $t6, $zero, L_80074724
    if (ctx->r14 == 0) {
        // 0x800746EC: sw          $zero, -0x358($at)
        MEM_W(-0X358, ctx->r1) = 0;
            goto L_80074724;
    }
    // 0x800746EC: sw          $zero, -0x358($at)
    MEM_W(-0X358, ctx->r1) = 0;
L_800746F0:
    // 0x800746F0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800746F4: lw          $t7, -0x358($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X358);
    // 0x800746F8: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800746FC: beq         $t7, $at, L_80074724
    if (ctx->r15 == ctx->r1) {
        // 0x80074700: nop
    
            goto L_80074724;
    }
    // 0x80074700: nop

    // 0x80074704: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80074708: lw          $t8, -0x358($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X358);
    // 0x8007470C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80074710: lw          $t0, 0x600($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X600);
    // 0x80074714: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80074718: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8007471C: bne         $t0, $zero, L_800746F0
    if (ctx->r8 != 0) {
        // 0x80074720: sw          $t9, -0x358($at)
        MEM_W(-0X358, ctx->r1) = ctx->r25;
            goto L_800746F0;
    }
    // 0x80074720: sw          $t9, -0x358($at)
    MEM_W(-0X358, ctx->r1) = ctx->r25;
L_80074724:
    // 0x80074724: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80074728: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007472C: jal         0x800B6650
    // 0x80074730: sw          $t1, 0x600($at)
    MEM_W(0X600, ctx->r1) = ctx->r9;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80074730: sw          $t1, 0x600($at)
    MEM_W(0X600, ctx->r1) = ctx->r9;
    after_0:
    // 0x80074734: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80074738: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8007473C: jal         0x800ABFF0
    // 0x80074740: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    Main_RequestRomDma(rdram, ctx);
        goto after_1;
    // 0x80074740: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80074744: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80074748: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8007474C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80074750: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    // 0x80074754: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80074758: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8007475C: jal         0x800ABFF0
    // 0x80074760: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Main_RequestRomDma(rdram, ctx);
        goto after_2;
    // 0x80074760: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80074764: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80074768: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8007476C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80074770: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80074774: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80074778: addu        $a0, $t5, $t8
    ctx->r4 = ADD32(ctx->r13, ctx->r24);
    // 0x8007477C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80074780: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80074784: jal         0x800ABFF0
    // 0x80074788: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Main_RequestRomDma(rdram, ctx);
        goto after_3;
    // 0x80074788: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x8007478C: addiu       $t9, $sp, 0x30
    ctx->r25 = ADD32(ctx->r29, 0X30);
    // 0x80074790: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80074794: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80074798: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8007479C: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x800747A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800747A4: jal         0x800ABFF0
    // 0x800747A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Main_RequestRomDma(rdram, ctx);
        goto after_4;
    // 0x800747A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x800747AC: addiu       $t3, $sp, 0x30
    ctx->r11 = ADD32(ctx->r29, 0X30);
    // 0x800747B0: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x800747B4: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800747B8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800747BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800747C0: jal         0x800ABFF0
    // 0x800747C4: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    Main_RequestRomDma(rdram, ctx);
        goto after_5;
    // 0x800747C4: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    after_5:
    // 0x800747C8: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x800747CC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800747D0: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x800747D4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800747D8: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800747DC: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x800747E0: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x800747E4: subu        $t8, $t7, $t5
    ctx->r24 = SUB32(ctx->r15, ctx->r13);
    // 0x800747E8: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800747EC: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800747F0: bne         $t1, $at, L_80074838
    if (ctx->r9 != ctx->r1) {
        // 0x800747F4: sw          $t9, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r25;
            goto L_80074838;
    }
    // 0x800747F4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800747F8: lw          $t3, 0x0($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X0);
    // 0x800747FC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80074800: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80074804: ori         $a1, $a1, 0x400
    ctx->r5 = ctx->r5 | 0X400;
    // 0x80074808: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8007480C: jal         0x800ABFF0
    // 0x80074810: addu        $a0, $t3, $t2
    ctx->r4 = ADD32(ctx->r11, ctx->r10);
    Main_RequestRomDma(rdram, ctx);
        goto after_6;
    // 0x80074810: addu        $a0, $t3, $t2
    ctx->r4 = ADD32(ctx->r11, ctx->r10);
    after_6:
    // 0x80074814: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80074818: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8007481C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80074820: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80074824: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80074828: jal         0x80080EC8
    // 0x8007482C: addiu       $a3, $a3, -0x8
    ctx->r7 = ADD32(ctx->r7, -0X8);
    strutil_lzo_decompress(rdram, ctx);
        goto after_7;
    // 0x8007482C: addiu       $a3, $a3, -0x8
    ctx->r7 = ADD32(ctx->r7, -0X8);
    after_7:
    // 0x80074830: b           L_8007485C
    // 0x80074834: nop

        goto L_8007485C;
    // 0x80074834: nop

L_80074838:
    // 0x80074838: addiu       $t4, $sp, 0x30
    ctx->r12 = ADD32(ctx->r29, 0X30);
    // 0x8007483C: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x80074840: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80074844: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80074848: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8007484C: addu        $a0, $t7, $t5
    ctx->r4 = ADD32(ctx->r15, ctx->r13);
    // 0x80074850: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80074854: jal         0x800ABFF0
    // 0x80074858: addiu       $a2, $a2, -0x8
    ctx->r6 = ADD32(ctx->r6, -0X8);
    Main_RequestRomDma(rdram, ctx);
        goto after_8;
    // 0x80074858: addiu       $a2, $a2, -0x8
    ctx->r6 = ADD32(ctx->r6, -0X8);
    after_8:
L_8007485C:
    // 0x8007485C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80074860: jal         0x800B6650
    // 0x80074864: sw          $zero, 0x600($at)
    MEM_W(0X600, ctx->r1) = 0;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_9;
    // 0x80074864: sw          $zero, 0x600($at)
    MEM_W(0X600, ctx->r1) = 0;
    after_9:
    // 0x80074868: jal         0x8004A34C
    // 0x8007486C: nop

    Main_DrainMessageQueue(rdram, ctx);
        goto after_10;
    // 0x8007486C: nop

    after_10:
    // 0x80074870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074874: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80074878: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007487C: sb          $t9, -0x2B4($at)
    MEM_B(-0X2B4, ctx->r1) = ctx->r25;
    // 0x80074880: jr          $ra
    // 0x80074884: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80074884: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}

RECOMP_FUNC void GarbageImg_GetDecodedSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074888: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007488C: lw          $t6, 0x600($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X600);
    // 0x80074890: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80074894: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80074898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007489C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800748A0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800748A4: beq         $t6, $zero, L_800748E0
    if (ctx->r14 == 0) {
        // 0x800748A8: sw          $zero, -0x354($at)
        MEM_W(-0X354, ctx->r1) = 0;
            goto L_800748E0;
    }
    // 0x800748A8: sw          $zero, -0x354($at)
    MEM_W(-0X354, ctx->r1) = 0;
L_800748AC:
    // 0x800748AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800748B0: lw          $t7, -0x354($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X354);
    // 0x800748B4: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800748B8: beq         $t7, $at, L_800748E0
    if (ctx->r15 == ctx->r1) {
        // 0x800748BC: nop
    
            goto L_800748E0;
    }
    // 0x800748BC: nop

    // 0x800748C0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800748C4: lw          $t8, -0x354($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X354);
    // 0x800748C8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800748CC: lw          $t0, 0x600($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X600);
    // 0x800748D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800748D4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800748D8: bne         $t0, $zero, L_800748AC
    if (ctx->r8 != 0) {
        // 0x800748DC: sw          $t9, -0x354($at)
        MEM_W(-0X354, ctx->r1) = ctx->r25;
            goto L_800748AC;
    }
    // 0x800748DC: sw          $t9, -0x354($at)
    MEM_W(-0X354, ctx->r1) = ctx->r25;
L_800748E0:
    // 0x800748E0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800748E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800748E8: jal         0x800B6650
    // 0x800748EC: sw          $t1, 0x600($at)
    MEM_W(0X600, ctx->r1) = ctx->r9;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x800748EC: sw          $t1, 0x600($at)
    MEM_W(0X600, ctx->r1) = ctx->r9;
    after_0:
    // 0x800748F0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800748F4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800748F8: jal         0x800ABFF0
    // 0x800748FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    Main_RequestRomDma(rdram, ctx);
        goto after_1;
    // 0x800748FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80074900: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80074904: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80074908: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007490C: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    // 0x80074910: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80074914: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80074918: jal         0x800ABFF0
    // 0x8007491C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Main_RequestRomDma(rdram, ctx);
        goto after_2;
    // 0x8007491C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80074920: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80074924: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80074928: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007492C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80074930: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80074934: addu        $a0, $t5, $t8
    ctx->r4 = ADD32(ctx->r13, ctx->r24);
    // 0x80074938: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8007493C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80074940: jal         0x800ABFF0
    // 0x80074944: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Main_RequestRomDma(rdram, ctx);
        goto after_3;
    // 0x80074944: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x80074948: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x8007494C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80074950: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80074954: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80074958: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x8007495C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80074960: jal         0x800ABFF0
    // 0x80074964: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Main_RequestRomDma(rdram, ctx);
        goto after_4;
    // 0x80074964: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x80074968: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x8007496C: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x80074970: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80074974: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80074978: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007497C: jal         0x800ABFF0
    // 0x80074980: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    Main_RequestRomDma(rdram, ctx);
        goto after_5;
    // 0x80074980: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    after_5:
    // 0x80074984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074988: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007498C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80074990: sw          $zero, 0x600($at)
    MEM_W(0X600, ctx->r1) = 0;
    // 0x80074994: jr          $ra
    // 0x80074998: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80074998: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8007499C: nop

;}

RECOMP_FUNC void GarbageImg_BlendRGB565(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075480: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80075484: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80075488: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8007548C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80075490: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80075494: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80075498: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8007549C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800754A0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800754A4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800754A8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800754AC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800754B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800754B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800754B8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800754BC: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x800754C0: nop

    // 0x800754C4: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    // 0x800754C8: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x800754CC: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800754D0: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x800754D4: nop

    // 0x800754D8: sh          $t0, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r8;
    // 0x800754DC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800754E0: nop

    // 0x800754E4: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x800754E8: lh          $t4, 0x6($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X6);
    // 0x800754EC: lbu         $t6, 0x9($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X9);
    // 0x800754F0: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800754F4: mflo        $t5
    ctx->r13 = lo;
    // 0x800754F8: nop

    // 0x800754FC: nop

    // 0x80075500: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80075504: mflo        $s0
    ctx->r16 = lo;
    // 0x80075508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007550C: jal         0x8007E03C
    // 0x80075510: nop

    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80075510: nop

    after_0:
    // 0x80075514: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80075518: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8007551C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80075520: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80075524: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80075528: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8007552C: lw          $s5, 0x0($t9)
    ctx->r21 = MEM_W(ctx->r25, 0X0);
    // 0x80075530: lw          $s3, 0x0($t8)
    ctx->r19 = MEM_W(ctx->r24, 0X0);
    // 0x80075534: slt         $at, $s2, $t0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80075538: beq         $at, $zero, L_80075678
    if (ctx->r1 == 0) {
        // 0x8007553C: nop
    
            goto L_80075678;
    }
    // 0x8007553C: nop

L_80075540:
    // 0x80075540: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80075544: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80075548: lhu         $t3, 0x6($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X6);
    // 0x8007554C: lw          $s4, 0x0($t1)
    ctx->r20 = MEM_W(ctx->r9, 0X0);
    // 0x80075550: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80075554: beq         $at, $zero, L_8007565C
    if (ctx->r1 == 0) {
        // 0x80075558: nop
    
            goto L_8007565C;
    }
    // 0x80075558: nop

L_8007555C:
    // 0x8007555C: lbu         $t2, 0x0($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X0);
    // 0x80075560: lbu         $t4, 0x0($s5)
    ctx->r12 = MEM_BU(ctx->r21, 0X0);
    // 0x80075564: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80075568: subu        $t6, $t5, $t2
    ctx->r14 = SUB32(ctx->r13, ctx->r10);
    // 0x8007556C: multu       $t4, $t6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80075570: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80075574: lbu         $t9, 0x1($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X1);
    // 0x80075578: lbu         $t8, 0x1($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X1);
    // 0x8007557C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80075580: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x80075584: lbu         $t2, 0x2($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X2);
    // 0x80075588: lbu         $t5, 0x2($s5)
    ctx->r13 = MEM_BU(ctx->r21, 0X2);
    // 0x8007558C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80075590: subu        $t6, $t4, $t2
    ctx->r14 = SUB32(ctx->r12, ctx->r10);
    // 0x80075594: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80075598: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x8007559C: mflo        $s6
    ctx->r22 = lo;
    // 0x800755A0: addiu       $s4, $s4, 0x3
    ctx->r20 = ADD32(ctx->r20, 0X3);
    // 0x800755A4: nop

    // 0x800755A8: div         $zero, $s6, $at
    lo = S32(S64(S32(ctx->r22)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r22)) % S64(S32(ctx->r1)));
    // 0x800755AC: mflo        $t7
    ctx->r15 = lo;
    // 0x800755B0: or          $s6, $t7, $zero
    ctx->r22 = ctx->r15 | 0;
    // 0x800755B4: nop

    // 0x800755B8: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800755BC: mflo        $s7
    ctx->r23 = lo;
    // 0x800755C0: nop

    // 0x800755C4: nop

    // 0x800755C8: div         $zero, $s7, $at
    lo = S32(S64(S32(ctx->r23)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r23)) % S64(S32(ctx->r1)));
    // 0x800755CC: mflo        $t3
    ctx->r11 = lo;
    // 0x800755D0: or          $s7, $t3, $zero
    ctx->r23 = ctx->r11 | 0;
    // 0x800755D4: nop

    // 0x800755D8: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800755DC: mflo        $t7
    ctx->r15 = lo;
    // 0x800755E0: nop

    // 0x800755E4: nop

    // 0x800755E8: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800755EC: mflo        $t0
    ctx->r8 = lo;
    // 0x800755F0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800755F4: lbu         $t9, -0x3($s4)
    ctx->r25 = MEM_BU(ctx->r20, -0X3);
    // 0x800755F8: lbu         $t8, -0x2($s4)
    ctx->r24 = MEM_BU(ctx->r20, -0X2);
    // 0x800755FC: lbu         $t1, -0x1($s4)
    ctx->r9 = MEM_BU(ctx->r20, -0X1);
    // 0x80075600: addu        $s6, $s6, $t9
    ctx->r22 = ADD32(ctx->r22, ctx->r25);
    // 0x80075604: addu        $s7, $s7, $t8
    ctx->r23 = ADD32(ctx->r23, ctx->r24);
    // 0x80075608: srl         $t5, $s7, 3
    ctx->r13 = S32(U32(ctx->r23) >> 3);
    // 0x8007560C: srl         $t4, $s6, 3
    ctx->r12 = S32(U32(ctx->r22) >> 3);
    // 0x80075610: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x80075614: srl         $t9, $t3, 3
    ctx->r25 = S32(U32(ctx->r11) >> 3);
    // 0x80075618: sll         $t2, $t4, 11
    ctx->r10 = S32(ctx->r12 << 11);
    // 0x8007561C: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x80075620: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x80075624: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x80075628: or          $t0, $t7, $t8
    ctx->r8 = ctx->r15 | ctx->r24;
    // 0x8007562C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80075630: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80075634: sh          $t1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r9;
    // 0x80075638: andi        $t4, $t1, 0xFFFF
    ctx->r12 = ctx->r9 & 0XFFFF;
    // 0x8007563C: sh          $t4, -0x2($s3)
    MEM_H(-0X2, ctx->r19) = ctx->r12;
    // 0x80075640: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80075644: nop

    // 0x80075648: lhu         $t2, 0x6($t5)
    ctx->r10 = MEM_HU(ctx->r13, 0X6);
    // 0x8007564C: nop

    // 0x80075650: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80075654: bne         $at, $zero, L_8007555C
    if (ctx->r1 != 0) {
        // 0x80075658: nop
    
            goto L_8007555C;
    }
    // 0x80075658: nop

L_8007565C:
    // 0x8007565C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80075660: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80075664: lhu         $t3, 0x6($t6)
    ctx->r11 = MEM_HU(ctx->r14, 0X6);
    // 0x80075668: addiu       $s5, $s5, 0x3
    ctx->r21 = ADD32(ctx->r21, 0X3);
    // 0x8007566C: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80075670: bne         $at, $zero, L_80075540
    if (ctx->r1 != 0) {
        // 0x80075674: nop
    
            goto L_80075540;
    }
    // 0x80075674: nop

L_80075678:
    // 0x80075678: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8007567C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80075680: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80075684: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80075688: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007568C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80075690: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80075694: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80075698: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8007569C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800756A0: jr          $ra
    // 0x800756A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800756A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void GarbageImg_FreeBlend(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800756A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800756AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800756B0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800756B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800756B8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800756BC: jal         0x8007E328
    // 0x800756C0: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800756C0: nop

    after_0:
    // 0x800756C4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800756C8: nop

    // 0x800756CC: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800756D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800756D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800756D8: jr          $ra
    // 0x800756DC: nop

    return;
    // 0x800756DC: nop

;}

RECOMP_FUNC void GarbageImg_NoopStub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800756E0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800756E4: addiu       $t6, $sp, 0x8
    ctx->r14 = ADD32(ctx->r29, 0X8);
    // 0x800756E8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800756EC: addiu       $t8, $t6, 0x14
    ctx->r24 = ADD32(ctx->r14, 0X14);
    // 0x800756F0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800756F4: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x800756F8: jr          $ra
    // 0x800756FC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800756FC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}

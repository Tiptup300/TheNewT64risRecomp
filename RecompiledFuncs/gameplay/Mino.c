#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Minos_800702e4_nineliner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800702E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800702E8: lw          $t6, -0x350($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X350);
    // 0x800702EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800702F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800702F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800702F8: addiu       $a1, $t6, 0x7FFF
    ctx->r5 = ADD32(ctx->r14, 0X7FFF);
    // 0x800702FC: lw          $a1, 0x5C01($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5C01);
    // 0x80070300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80070304: jal         0x80070818
    // 0x80070308: nop

    Minos_Mino_SetGraphicHandle(rdram, ctx);
        goto after_0;
    // 0x80070308: nop

    after_0:
    // 0x8007030C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80070310: nop

    // 0x80070314: lw          $a1, 0x130($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X130);
    // 0x80070318: jal         0x800A2F30
    // 0x8007031C: addiu       $a0, $t7, 0x24
    ctx->r4 = ADD32(ctx->r15, 0X24);
    Minos_CopyGrid(rdram, ctx);
        goto after_1;
    // 0x8007031C: addiu       $a0, $t7, 0x24
    ctx->r4 = ADD32(ctx->r15, 0X24);
    after_1:
    // 0x80070320: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80070324: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80070328: sb          $t8, 0x1C($t9)
    MEM_B(0X1C, ctx->r25) = ctx->r24;
    // 0x8007032C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80070330: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80070334: lbu         $t1, 0x1C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1C);
    // 0x80070338: nop

    // 0x8007033C: sb          $t1, 0x1E($t0)
    MEM_B(0X1E, ctx->r8) = ctx->r9;
    // 0x80070340: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80070344: nop

    // 0x80070348: sb          $zero, 0x1D($t2)
    MEM_B(0X1D, ctx->r10) = 0;
    // 0x8007034C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80070350: nop

    // 0x80070354: sh          $zero, 0x20($t3)
    MEM_H(0X20, ctx->r11) = 0;
    // 0x80070358: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8007035C: nop

    // 0x80070360: sh          $zero, 0x22($t4)
    MEM_H(0X22, ctx->r12) = 0;
    // 0x80070364: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80070368: nop

    // 0x8007036C: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x80070370: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80070374: nop

    // 0x80070378: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x8007037C: nop

    // 0x80070380: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80070384: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x80070388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007038C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070390: jr          $ra
    // 0x80070394: nop

    return;
    // 0x80070394: nop

;}

RECOMP_FUNC void Minos_Mino_Copy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007039C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800703A0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800703A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800703A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800703AC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800703B0: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800703B4: nop

    // 0x800703B8: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800703BC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800703C0: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800703C4: lbu         $t0, 0x1($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1);
    // 0x800703C8: nop

    // 0x800703CC: sb          $t0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r8;
    // 0x800703D0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800703D4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800703D8: lh          $t3, 0x20($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X20);
    // 0x800703DC: nop

    // 0x800703E0: sh          $t3, 0x20($t4)
    MEM_H(0X20, ctx->r12) = ctx->r11;
    // 0x800703E4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800703E8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800703EC: lh          $t6, 0x22($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X22);
    // 0x800703F0: nop

    // 0x800703F4: sh          $t6, 0x22($t7)
    MEM_H(0X22, ctx->r15) = ctx->r14;
    // 0x800703F8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800703FC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80070400: lw          $t9, 0x130($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X130);
    // 0x80070404: nop

    // 0x80070408: sw          $t9, 0x130($t0)
    MEM_W(0X130, ctx->r8) = ctx->r25;
    // 0x8007040C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80070410: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80070414: lbu         $t2, 0x1C($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1C);
    // 0x80070418: nop

    // 0x8007041C: sb          $t2, 0x1C($t3)
    MEM_B(0X1C, ctx->r11) = ctx->r10;
    // 0x80070420: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80070424: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80070428: lbu         $t5, 0x2($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X2);
    // 0x8007042C: nop

    // 0x80070430: sb          $t5, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r13;
    // 0x80070434: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80070438: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8007043C: lwl         $at, 0x4($t8)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r24, 0X4);
    // 0x80070440: lwr         $at, 0x7($t8)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r24, 0X7);
    // 0x80070444: nop

    // 0x80070448: swl         $at, 0x4($t7)
    do_swl(rdram, 0X4, ctx->r15, ctx->r1);
    // 0x8007044C: swr         $at, 0x7($t7)
    do_swr(rdram, 0X7, ctx->r15, ctx->r1);
    // 0x80070450: lwl         $t0, 0x8($t8)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r24, 0X8);
    // 0x80070454: lwr         $t0, 0xB($t8)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r24, 0XB);
    // 0x80070458: nop

    // 0x8007045C: swl         $t0, 0x8($t7)
    do_swl(rdram, 0X8, ctx->r15, ctx->r8);
    // 0x80070460: swr         $t0, 0xB($t7)
    do_swr(rdram, 0XB, ctx->r15, ctx->r8);
    // 0x80070464: lwl         $at, 0xC($t8)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r24, 0XC);
    // 0x80070468: lwr         $at, 0xF($t8)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r24, 0XF);
    // 0x8007046C: nop

    // 0x80070470: swl         $at, 0xC($t7)
    do_swl(rdram, 0XC, ctx->r15, ctx->r1);
    // 0x80070474: swr         $at, 0xF($t7)
    do_swr(rdram, 0XF, ctx->r15, ctx->r1);
    // 0x80070478: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8007047C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80070480: lwl         $at, 0x10($t2)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r10, 0X10);
    // 0x80070484: lwr         $at, 0x13($t2)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r10, 0X13);
    // 0x80070488: nop

    // 0x8007048C: swl         $at, 0x10($t1)
    do_swl(rdram, 0X10, ctx->r9, ctx->r1);
    // 0x80070490: swr         $at, 0x13($t1)
    do_swr(rdram, 0X13, ctx->r9, ctx->r1);
    // 0x80070494: lwl         $t4, 0x14($t2)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r10, 0X14);
    // 0x80070498: lwr         $t4, 0x17($t2)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r10, 0X17);
    // 0x8007049C: nop

    // 0x800704A0: swl         $t4, 0x14($t1)
    do_swl(rdram, 0X14, ctx->r9, ctx->r12);
    // 0x800704A4: swr         $t4, 0x17($t1)
    do_swr(rdram, 0X17, ctx->r9, ctx->r12);
    // 0x800704A8: lwl         $at, 0x18($t2)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r10, 0X18);
    // 0x800704AC: lwr         $at, 0x1B($t2)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r10, 0X1B);
    // 0x800704B0: nop

    // 0x800704B4: swl         $at, 0x18($t1)
    do_swl(rdram, 0X18, ctx->r9, ctx->r1);
    // 0x800704B8: swr         $at, 0x1B($t1)
    do_swr(rdram, 0X1B, ctx->r9, ctx->r1);
    // 0x800704BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800704C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800704C4: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    // 0x800704C8: jal         0x800A2F30
    // 0x800704CC: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    Minos_CopyGrid(rdram, ctx);
        goto after_0;
    // 0x800704CC: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_0:
    // 0x800704D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800704D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800704D8: jr          $ra
    // 0x800704DC: nop

    return;
    // 0x800704DC: nop

;}

RECOMP_FUNC void Minos_800704e0_threeliner_sets_0x130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800704E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800704E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800704E8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800704EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800704F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800704F4: lw          $a0, 0x130($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X130);
    // 0x800704F8: jal         0x800A2F50
    // 0x800704FC: addiu       $a1, $t6, 0x24
    ctx->r5 = ADD32(ctx->r14, 0X24);
    func_800A2F50(rdram, ctx);
        goto after_0;
    // 0x800704FC: addiu       $a1, $t6, 0x24
    ctx->r5 = ADD32(ctx->r14, 0X24);
    after_0:
    // 0x80070500: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80070504: bne         $s0, $zero, L_80070518
    if (ctx->r16 != 0) {
        // 0x80070508: nop
    
            goto L_80070518;
    }
    // 0x80070508: nop

    // 0x8007050C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80070510: nop

    // 0x80070514: sw          $zero, 0x130($t7)
    MEM_W(0X130, ctx->r15) = 0;
L_80070518:
    // 0x80070518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007051C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80070520: jr          $ra
    // 0x80070524: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80070524: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Minos_80070528_Morph(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070528: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007052C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80070530: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80070534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80070538: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007053C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80070540: lw          $t7, 0x130($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X130);
    // 0x80070544: nop

    // 0x80070548: beq         $t7, $zero, L_800705E8
    if (ctx->r15 == 0) {
        // 0x8007054C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800705E8;
    }
    // 0x8007054C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070550: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80070554: sltu        $at, $t7, $at
    ctx->r1 = ctx->r15 < ctx->r1 ? 1 : 0;
    // 0x80070558: bne         $at, $zero, L_80070590
    if (ctx->r1 != 0) {
        // 0x8007055C: lui         $at, 0x8040
        ctx->r1 = S32(0X8040 << 16);
            goto L_80070590;
    }
    // 0x8007055C: lui         $at, 0x8040
    ctx->r1 = S32(0X8040 << 16);
    // 0x80070560: sltu        $at, $t7, $at
    ctx->r1 = ctx->r15 < ctx->r1 ? 1 : 0;
    // 0x80070564: beq         $at, $zero, L_80070590
    if (ctx->r1 == 0) {
        // 0x80070568: nop
    
            goto L_80070590;
    }
    // 0x80070568: nop

    // 0x8007056C: jal         0x800704E0
    // 0x80070570: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    Minos_800704e0_threeliner_sets_0x130(rdram, ctx);
        goto after_0;
    // 0x80070570: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80070574: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80070578: nop

    // 0x8007057C: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x80070580: nop

    // 0x80070584: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80070588: b           L_800705E8
    // 0x8007058C: sb          $t0, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r8;
        goto L_800705E8;
    // 0x8007058C: sb          $t0, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r8;
L_80070590:
    // 0x80070590: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80070594: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80070598: lw          $a1, 0x130($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X130);
    // 0x8007059C: addiu       $a0, $a0, -0x26E0
    ctx->r4 = ADD32(ctx->r4, -0X26E0);
    // 0x800705A0: jal         0x800B3BFC
    // 0x800705A4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800705A4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_1:
    // 0x800705A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800705AC: lw          $t2, -0x350($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X350);
    // 0x800705B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800705B4: addiu       $a1, $t2, 0x7FFF
    ctx->r5 = ADD32(ctx->r10, 0X7FFF);
    // 0x800705B8: lw          $a1, 0x5C3D($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5C3D);
    // 0x800705BC: jal         0x80070818
    // 0x800705C0: nop

    Minos_Mino_SetGraphicHandle(rdram, ctx);
        goto after_2;
    // 0x800705C0: nop

    after_2:
    // 0x800705C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800705C8: jal         0x800704E0
    // 0x800705CC: nop

    Minos_800704e0_threeliner_sets_0x130(rdram, ctx);
        goto after_3;
    // 0x800705CC: nop

    after_3:
    // 0x800705D0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800705D4: nop

    // 0x800705D8: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x800705DC: nop

    // 0x800705E0: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x800705E4: sb          $t5, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r13;
L_800705E8:
    // 0x800705E8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800705EC: nop

    // 0x800705F0: lbu         $t6, 0x2($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X2);
    // 0x800705F4: nop

    // 0x800705F8: beq         $t6, $zero, L_800706B8
    if (ctx->r14 == 0) {
        // 0x800705FC: nop
    
            goto L_800706B8;
    }
    // 0x800705FC: nop

    // 0x80070600: lh          $t9, 0x4($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X4);
    // 0x80070604: lh          $t0, 0x10($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X10);
    // 0x80070608: nop

    // 0x8007060C: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x80070610: sh          $t8, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r24;
    // 0x80070614: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80070618: nop

    // 0x8007061C: lh          $t2, 0x6($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X6);
    // 0x80070620: lh          $t4, 0x12($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X12);
    // 0x80070624: nop

    // 0x80070628: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8007062C: sh          $t5, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r13;
    // 0x80070630: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80070634: nop

    // 0x80070638: lh          $t6, 0x8($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X8);
    // 0x8007063C: lh          $t9, 0x14($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X14);
    // 0x80070640: nop

    // 0x80070644: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80070648: sh          $t0, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r8;
    // 0x8007064C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80070650: nop

    // 0x80070654: lh          $t7, 0xA($t8)
    ctx->r15 = MEM_H(ctx->r24, 0XA);
    // 0x80070658: lh          $t2, 0x16($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X16);
    // 0x8007065C: nop

    // 0x80070660: addu        $t4, $t7, $t2
    ctx->r12 = ADD32(ctx->r15, ctx->r10);
    // 0x80070664: sh          $t4, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r12;
    // 0x80070668: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8007066C: nop

    // 0x80070670: lh          $t1, 0xC($t5)
    ctx->r9 = MEM_H(ctx->r13, 0XC);
    // 0x80070674: lh          $t6, 0x18($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X18);
    // 0x80070678: nop

    // 0x8007067C: addu        $t9, $t1, $t6
    ctx->r25 = ADD32(ctx->r9, ctx->r14);
    // 0x80070680: sh          $t9, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r25;
    // 0x80070684: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80070688: nop

    // 0x8007068C: lh          $t3, 0xE($t0)
    ctx->r11 = MEM_H(ctx->r8, 0XE);
    // 0x80070690: lh          $t7, 0x1A($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X1A);
    // 0x80070694: nop

    // 0x80070698: addu        $t2, $t3, $t7
    ctx->r10 = ADD32(ctx->r11, ctx->r15);
    // 0x8007069C: sh          $t2, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r10;
    // 0x800706A0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800706A4: nop

    // 0x800706A8: lbu         $t8, 0x2($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X2);
    // 0x800706AC: nop

    // 0x800706B0: addiu       $t1, $t8, -0x1
    ctx->r9 = ADD32(ctx->r24, -0X1);
    // 0x800706B4: sb          $t1, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r9;
L_800706B8:
    // 0x800706B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800706BC: nop

    // 0x800706C0: lbu         $t9, 0x1C($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X1C);
    // 0x800706C4: lbu         $t5, 0x1E($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X1E);
    // 0x800706C8: nop

    // 0x800706CC: beq         $t9, $t5, L_80070784
    if (ctx->r25 == ctx->r13) {
        // 0x800706D0: nop
    
            goto L_80070784;
    }
    // 0x800706D0: nop

    // 0x800706D4: lb          $t3, 0x1D($t6)
    ctx->r11 = MEM_B(ctx->r14, 0X1D);
    // 0x800706D8: lbu         $s1, 0x1E($t6)
    ctx->r17 = MEM_BU(ctx->r14, 0X1E);
    // 0x800706DC: blez        $t3, L_80070728
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800706E0: or          $s0, $t9, $zero
        ctx->r16 = ctx->r25 | 0;
            goto L_80070728;
    }
    // 0x800706E0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x800706E4: addu        $t7, $t3, $s0
    ctx->r15 = ADD32(ctx->r11, ctx->r16);
    // 0x800706E8: slt         $at, $t7, $s1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800706EC: bne         $at, $zero, L_8007070C
    if (ctx->r1 != 0) {
        // 0x800706F0: nop
    
            goto L_8007070C;
    }
    // 0x800706F0: nop

    // 0x800706F4: lbu         $t2, 0x1E($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X1E);
    // 0x800706F8: nop

    // 0x800706FC: sb          $t2, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r10;
    // 0x80070700: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80070704: b           L_80070728
    // 0x80070708: sb          $zero, 0x1D($t0)
    MEM_B(0X1D, ctx->r8) = 0;
        goto L_80070728;
    // 0x80070708: sb          $zero, 0x1D($t0)
    MEM_B(0X1D, ctx->r8) = 0;
L_8007070C:
    // 0x8007070C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80070710: nop

    // 0x80070714: lbu         $t1, 0x1C($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X1C);
    // 0x80070718: lb          $t4, 0x1D($t8)
    ctx->r12 = MEM_B(ctx->r24, 0X1D);
    // 0x8007071C: nop

    // 0x80070720: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80070724: sb          $t5, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r13;
L_80070728:
    // 0x80070728: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007072C: nop

    // 0x80070730: lb          $t3, 0x1D($t9)
    ctx->r11 = MEM_B(ctx->r25, 0X1D);
    // 0x80070734: nop

    // 0x80070738: bgez        $t3, L_80070784
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007073C: nop
    
            goto L_80070784;
    }
    // 0x8007073C: nop

    // 0x80070740: addu        $t7, $t3, $s0
    ctx->r15 = ADD32(ctx->r11, ctx->r16);
    // 0x80070744: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80070748: bne         $at, $zero, L_80070768
    if (ctx->r1 != 0) {
        // 0x8007074C: nop
    
            goto L_80070768;
    }
    // 0x8007074C: nop

    // 0x80070750: lbu         $t2, 0x1E($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X1E);
    // 0x80070754: nop

    // 0x80070758: sb          $t2, 0x1C($t9)
    MEM_B(0X1C, ctx->r25) = ctx->r10;
    // 0x8007075C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80070760: b           L_80070784
    // 0x80070764: sb          $zero, 0x1D($t6)
    MEM_B(0X1D, ctx->r14) = 0;
        goto L_80070784;
    // 0x80070764: sb          $zero, 0x1D($t6)
    MEM_B(0X1D, ctx->r14) = 0;
L_80070768:
    // 0x80070768: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007076C: nop

    // 0x80070770: lbu         $t1, 0x1C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1C);
    // 0x80070774: lb          $t4, 0x1D($t0)
    ctx->r12 = MEM_B(ctx->r8, 0X1D);
    // 0x80070778: nop

    // 0x8007077C: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80070780: sb          $t5, 0x1C($t0)
    MEM_B(0X1C, ctx->r8) = ctx->r13;
L_80070784:
    // 0x80070784: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80070788: nop

    // 0x8007078C: lh          $t3, 0x22($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X22);
    // 0x80070790: nop

    // 0x80070794: beq         $t3, $zero, L_80070804
    if (ctx->r11 == 0) {
        // 0x80070798: nop
    
            goto L_80070804;
    }
    // 0x80070798: nop

    // 0x8007079C: lh          $t7, 0x20($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X20);
    // 0x800707A0: nop

    // 0x800707A4: addu        $t2, $t7, $t3
    ctx->r10 = ADD32(ctx->r15, ctx->r11);
    // 0x800707A8: sh          $t2, 0x20($t8)
    MEM_H(0X20, ctx->r24) = ctx->r10;
    // 0x800707AC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800707B0: nop

    // 0x800707B4: lh          $t6, 0x20($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X20);
    // 0x800707B8: nop

    // 0x800707BC: bgez        $t6, L_800707D4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800707C0: nop
    
            goto L_800707D4;
    }
    // 0x800707C0: nop

    // 0x800707C4: sh          $zero, 0x20($t9)
    MEM_H(0X20, ctx->r25) = 0;
    // 0x800707C8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800707CC: nop

    // 0x800707D0: sh          $zero, 0x22($t1)
    MEM_H(0X22, ctx->r9) = 0;
L_800707D4:
    // 0x800707D4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800707D8: nop

    // 0x800707DC: lh          $t5, 0x20($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X20);
    // 0x800707E0: nop

    // 0x800707E4: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x800707E8: bne         $at, $zero, L_80070804
    if (ctx->r1 != 0) {
        // 0x800707EC: nop
    
            goto L_80070804;
    }
    // 0x800707EC: nop

    // 0x800707F0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800707F4: sh          $t0, 0x20($t4)
    MEM_H(0X20, ctx->r12) = ctx->r8;
    // 0x800707F8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800707FC: nop

    // 0x80070800: sh          $zero, 0x22($t7)
    MEM_H(0X22, ctx->r15) = 0;
L_80070804:
    // 0x80070804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80070808: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007080C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80070810: jr          $ra
    // 0x80070814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80070814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Minos_Mino_SetGraphicHandle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070818: jr          $ra
    // 0x8007081C: sw          $a1, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r5;
    return;
    // 0x8007081C: sw          $a1, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r5;
;}

RECOMP_FUNC void Minos_80070820_fiveliner_sets_arg0_2_4_8_12_to_arg1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070820: lwl         $at, 0x0($a1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r5, 0X0);
    // 0x80070824: lwr         $at, 0x3($a1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r5, 0X3);
    // 0x80070828: nop

    // 0x8007082C: swl         $at, 0x4($a0)
    do_swl(rdram, 0X4, ctx->r4, ctx->r1);
    // 0x80070830: swr         $at, 0x7($a0)
    do_swr(rdram, 0X7, ctx->r4, ctx->r1);
    // 0x80070834: lwl         $t8, 0x4($a1)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r5, 0X4);
    // 0x80070838: lwr         $t8, 0x7($a1)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r5, 0X7);
    // 0x8007083C: nop

    // 0x80070840: swl         $t8, 0x8($a0)
    do_swl(rdram, 0X8, ctx->r4, ctx->r24);
    // 0x80070844: swr         $t8, 0xB($a0)
    do_swr(rdram, 0XB, ctx->r4, ctx->r24);
    // 0x80070848: lwl         $at, 0x8($a1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r5, 0X8);
    // 0x8007084C: lwr         $at, 0xB($a1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r5, 0XB);
    // 0x80070850: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80070854: swl         $at, 0xC($a0)
    do_swl(rdram, 0XC, ctx->r4, ctx->r1);
    // 0x80070858: jr          $ra
    // 0x8007085C: swr         $at, 0xF($a0)
    do_swr(rdram, 0XF, ctx->r4, ctx->r1);
    return;
    // 0x8007085C: swr         $at, 0xF($a0)
    do_swr(rdram, 0XF, ctx->r4, ctx->r1);
;}

RECOMP_FUNC void Minos_80070860_fortyliner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070860: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80070864: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x80070868: lh          $t1, 0x6($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X6);
    // 0x8007086C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80070870: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x80070874: lh          $t5, 0x8($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X8);
    // 0x80070878: bne         $a2, $zero, L_80070884
    if (ctx->r6 != 0) {
        // 0x8007087C: nop
    
            goto L_80070884;
    }
    // 0x8007087C: nop

    // 0x80070880: break       7
    do_break(2147944576);
L_80070884:
    // 0x80070884: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80070888: bne         $a2, $at, L_8007089C
    if (ctx->r6 != ctx->r1) {
        // 0x8007088C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007089C;
    }
    // 0x8007088C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070890: bne         $t8, $at, L_8007089C
    if (ctx->r24 != ctx->r1) {
        // 0x80070894: nop
    
            goto L_8007089C;
    }
    // 0x80070894: nop

    // 0x80070898: break       6
    do_break(2147944600);
L_8007089C:
    // 0x8007089C: mflo        $t9
    ctx->r25 = lo;
    // 0x800708A0: sh          $t9, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r25;
    // 0x800708A4: lh          $t0, 0x2($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X2);
    // 0x800708A8: lh          $t9, 0xA($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XA);
    // 0x800708AC: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x800708B0: div         $zero, $t2, $a2
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r6)));
    // 0x800708B4: bne         $a2, $zero, L_800708C0
    if (ctx->r6 != 0) {
        // 0x800708B8: nop
    
            goto L_800708C0;
    }
    // 0x800708B8: nop

    // 0x800708BC: break       7
    do_break(2147944636);
L_800708C0:
    // 0x800708C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800708C4: bne         $a2, $at, L_800708D8
    if (ctx->r6 != ctx->r1) {
        // 0x800708C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800708D8;
    }
    // 0x800708C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800708CC: bne         $t2, $at, L_800708D8
    if (ctx->r10 != ctx->r1) {
        // 0x800708D0: nop
    
            goto L_800708D8;
    }
    // 0x800708D0: nop

    // 0x800708D4: break       6
    do_break(2147944660);
L_800708D8:
    // 0x800708D8: mflo        $t3
    ctx->r11 = lo;
    // 0x800708DC: sh          $t3, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r11;
    // 0x800708E0: lh          $t4, 0x4($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X4);
    // 0x800708E4: lh          $t3, 0xC($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XC);
    // 0x800708E8: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800708EC: div         $zero, $t6, $a2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r6)));
    // 0x800708F0: bne         $a2, $zero, L_800708FC
    if (ctx->r6 != 0) {
        // 0x800708F4: nop
    
            goto L_800708FC;
    }
    // 0x800708F4: nop

    // 0x800708F8: break       7
    do_break(2147944696);
L_800708FC:
    // 0x800708FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80070900: bne         $a2, $at, L_80070914
    if (ctx->r6 != ctx->r1) {
        // 0x80070904: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80070914;
    }
    // 0x80070904: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070908: bne         $t6, $at, L_80070914
    if (ctx->r14 != ctx->r1) {
        // 0x8007090C: nop
    
            goto L_80070914;
    }
    // 0x8007090C: nop

    // 0x80070910: break       6
    do_break(2147944720);
L_80070914:
    // 0x80070914: mflo        $t7
    ctx->r15 = lo;
    // 0x80070918: sh          $t7, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r15;
    // 0x8007091C: lh          $t8, 0x6($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X6);
    // 0x80070920: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x80070924: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80070928: div         $zero, $t0, $a2
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r6)));
    // 0x8007092C: bne         $a2, $zero, L_80070938
    if (ctx->r6 != 0) {
        // 0x80070930: nop
    
            goto L_80070938;
    }
    // 0x80070930: nop

    // 0x80070934: break       7
    do_break(2147944756);
L_80070938:
    // 0x80070938: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007093C: bne         $a2, $at, L_80070950
    if (ctx->r6 != ctx->r1) {
        // 0x80070940: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80070950;
    }
    // 0x80070940: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070944: bne         $t0, $at, L_80070950
    if (ctx->r8 != ctx->r1) {
        // 0x80070948: nop
    
            goto L_80070950;
    }
    // 0x80070948: nop

    // 0x8007094C: break       6
    do_break(2147944780);
L_80070950:
    // 0x80070950: mflo        $t1
    ctx->r9 = lo;
    // 0x80070954: sh          $t1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r9;
    // 0x80070958: lh          $t2, 0x8($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X8);
    // 0x8007095C: nop

    // 0x80070960: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80070964: div         $zero, $t4, $a2
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r6)));
    // 0x80070968: bne         $a2, $zero, L_80070974
    if (ctx->r6 != 0) {
        // 0x8007096C: nop
    
            goto L_80070974;
    }
    // 0x8007096C: nop

    // 0x80070970: break       7
    do_break(2147944816);
L_80070974:
    // 0x80070974: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80070978: bne         $a2, $at, L_8007098C
    if (ctx->r6 != ctx->r1) {
        // 0x8007097C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007098C;
    }
    // 0x8007097C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070980: bne         $t4, $at, L_8007098C
    if (ctx->r12 != ctx->r1) {
        // 0x80070984: nop
    
            goto L_8007098C;
    }
    // 0x80070984: nop

    // 0x80070988: break       6
    do_break(2147944840);
L_8007098C:
    // 0x8007098C: mflo        $t5
    ctx->r13 = lo;
    // 0x80070990: sh          $t5, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r13;
    // 0x80070994: lh          $t6, 0xA($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XA);
    // 0x80070998: sb          $a2, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r6;
    // 0x8007099C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800709A0: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x800709A4: bne         $a2, $zero, L_800709B0
    if (ctx->r6 != 0) {
        // 0x800709A8: nop
    
            goto L_800709B0;
    }
    // 0x800709A8: nop

    // 0x800709AC: break       7
    do_break(2147944876);
L_800709B0:
    // 0x800709B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800709B4: bne         $a2, $at, L_800709C8
    if (ctx->r6 != ctx->r1) {
        // 0x800709B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800709C8;
    }
    // 0x800709B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800709BC: bne         $t8, $at, L_800709C8
    if (ctx->r24 != ctx->r1) {
        // 0x800709C0: nop
    
            goto L_800709C8;
    }
    // 0x800709C0: nop

    // 0x800709C4: break       6
    do_break(2147944900);
L_800709C8:
    // 0x800709C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800709CC: sh          $t9, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r25;
    // 0x800709D0: jr          $ra
    // 0x800709D4: nop

    return;
    // 0x800709D4: nop

;}

RECOMP_FUNC void Minos_Mino_SetBrightness(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800709D8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800709DC: sb          $a1, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r5;
    // 0x800709E0: sb          $a1, 0x1E($a0)
    MEM_B(0X1E, ctx->r4) = ctx->r5;
    // 0x800709E4: jr          $ra
    // 0x800709E8: sb          $zero, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = 0;
    return;
    // 0x800709E8: sb          $zero, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = 0;
;}

RECOMP_FUNC void Minos_Mino_FadeBrightness(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800709EC: lbu         $t6, 0x1C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1C);
    // 0x800709F0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800709F4: subu        $t7, $a1, $t6
    ctx->r15 = SUB32(ctx->r5, ctx->r14);
    // 0x800709F8: div         $zero, $t7, $a2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r6)));
    // 0x800709FC: sb          $a1, 0x1E($a0)
    MEM_B(0X1E, ctx->r4) = ctx->r5;
    // 0x80070A00: bne         $a2, $zero, L_80070A0C
    if (ctx->r6 != 0) {
        // 0x80070A04: nop
    
            goto L_80070A0C;
    }
    // 0x80070A04: nop

    // 0x80070A08: break       7
    do_break(2147944968);
L_80070A0C:
    // 0x80070A0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80070A10: bne         $a2, $at, L_80070A24
    if (ctx->r6 != ctx->r1) {
        // 0x80070A14: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80070A24;
    }
    // 0x80070A14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070A18: bne         $t7, $at, L_80070A24
    if (ctx->r15 != ctx->r1) {
        // 0x80070A1C: nop
    
            goto L_80070A24;
    }
    // 0x80070A1C: nop

    // 0x80070A20: break       6
    do_break(2147944992);
L_80070A24:
    // 0x80070A24: mflo        $t8
    ctx->r24 = lo;
    // 0x80070A28: sb          $t8, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r24;
    // 0x80070A2C: jr          $ra
    // 0x80070A30: nop

    return;
    // 0x80070A30: nop

;}

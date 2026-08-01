#include "recomp.h"
#include "funcs.h"

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

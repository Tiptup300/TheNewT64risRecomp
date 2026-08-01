#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void NextPieceShadow_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800680A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800680A4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800680A8: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x800680AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800680B0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800680B4: lw          $t8, 0x530($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X530);
    // 0x800680B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800680BC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800680C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800680C4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800680C8: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x800680CC: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x800680D0: lw          $s0, 0x110($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X110);
    // 0x800680D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800680D8: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800680DC: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x800680E0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800680E4: lbu         $t1, 0x1E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1E);
    // 0x800680E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800680EC: sb          $t1, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r9;
    // 0x800680F0: lwl         $t3, 0x28($sp)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r29, 0X28);
    // 0x800680F4: lwr         $t3, 0x2B($sp)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r29, 0X2B);
    // 0x800680F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800680FC: swl         $t3, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r11);
    // 0x80068100: swr         $t3, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r11);
    // 0x80068104: lwl         $at, 0xA($s0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r16, 0XA);
    // 0x80068108: lwr         $at, 0xD($s0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r16, 0XD);
    // 0x8006810C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80068110: swl         $at, 0xC($sp)
    do_swl(rdram, 0XC, ctx->r29, ctx->r1);
    // 0x80068114: swr         $at, 0xF($sp)
    do_swr(rdram, 0XF, ctx->r29, ctx->r1);
    // 0x80068118: lbu         $t6, 0x1E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1E);
    // 0x8006811C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80068120: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80068124: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80068128: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8006812C: jal         0x800653E4
    // 0x80068130: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    MobilePiece_Init(rdram, ctx);
        goto after_0;
    // 0x80068130: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x80068134: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80068138: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006813C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80068140: jal         0x8006531C
    // 0x80068144: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    MobilePiece_SetCubesPosition(rdram, ctx);
        goto after_1;
    // 0x80068144: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_1:
    // 0x80068148: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006814C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80068150: jr          $ra
    // 0x80068154: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80068154: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void NextPieceShadow_InitSlide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068158: lwl         $at, 0x0($a1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r5, 0X0);
    // 0x8006815C: lwr         $at, 0x3($a1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r5, 0X3);
    // 0x80068160: nop

    // 0x80068164: swl         $at, 0x2($a0)
    do_swl(rdram, 0X2, ctx->r4, ctx->r1);
    // 0x80068168: swr         $at, 0x5($a0)
    do_swr(rdram, 0X5, ctx->r4, ctx->r1);
    // 0x8006816C: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80068170: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x80068174: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80068178: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x8006817C: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80068180: mflo        $t2
    ctx->r10 = lo;
    // 0x80068184: sh          $t2, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r10;
    // 0x80068188: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8006818C: lh          $t3, 0x6($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X6);
    // 0x80068190: nop

    // 0x80068194: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80068198: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8006819C: mflo        $t7
    ctx->r15 = lo;
    // 0x800681A0: sh          $t7, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r15;
    // 0x800681A4: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x800681A8: nop

    // 0x800681AC: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800681B0: sh          $t8, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r24;
    // 0x800681B4: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x800681B8: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x800681BC: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800681C0: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800681C4: subu        $t3, $t0, $t2
    ctx->r11 = SUB32(ctx->r8, ctx->r10);
    // 0x800681C8: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x800681CC: mflo        $t4
    ctx->r12 = lo;
    // 0x800681D0: sh          $t4, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r12;
    // 0x800681D4: lhu         $t5, 0xA($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0XA);
    // 0x800681D8: nop

    // 0x800681DC: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
    // 0x800681E0: lhu         $t6, 0xA($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XA);
    // 0x800681E4: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x800681E8: nop

    // 0x800681EC: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800681F0: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800681F4: mflo        $t9
    ctx->r25 = lo;
    // 0x800681F8: sh          $t9, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r25;
    // 0x800681FC: jr          $ra
    // 0x80068200: nop

    return;
    // 0x80068200: nop

;}

RECOMP_FUNC void NextPieceShadow_StepSlide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068204: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80068208: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8006820C: lh          $t9, 0x4($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4);
    // 0x80068210: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80068214: lh          $t0, 0x8($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X8);
    // 0x80068218: lh          $t2, 0xE($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XE);
    // 0x8006821C: lh          $t3, 0x10($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X10);
    // 0x80068220: lh          $t6, 0xC($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC);
    // 0x80068224: lhu         $t5, 0xA($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0XA);
    // 0x80068228: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8006822C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80068230: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80068234: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
    // 0x80068238: sh          $t1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r9;
    // 0x8006823C: sh          $t4, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r12;
    // 0x80068240: jr          $ra
    // 0x80068244: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
    return;
    // 0x80068244: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void NextPieceShadow_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068248: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006824C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80068250: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80068254: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068258: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006825C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068260: lwl         $at, 0x2($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X2);
    // 0x80068264: lwr         $at, 0x5($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X5);
    // 0x80068268: addiu       $s0, $t6, 0x18
    ctx->r16 = ADD32(ctx->r14, 0X18);
    // 0x8006826C: swl         $at, 0xE($s0)
    do_swl(rdram, 0XE, ctx->r16, ctx->r1);
    // 0x80068270: swr         $at, 0x11($s0)
    do_swr(rdram, 0X11, ctx->r16, ctx->r1);
    // 0x80068274: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
    // 0x80068278: lh          $t1, 0x10($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X10);
    // 0x8006827C: addiu       $t0, $t9, 0x80
    ctx->r8 = ADD32(ctx->r25, 0X80);
    // 0x80068280: addiu       $t2, $t1, 0x80
    ctx->r10 = ADD32(ctx->r9, 0X80);
    // 0x80068284: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    // 0x80068288: sh          $t2, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r10;
    // 0x8006828C: lbu         $t3, 0x2F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X2F);
    // 0x80068290: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80068294: bne         $t3, $at, L_800682B8
    if (ctx->r11 != ctx->r1) {
        // 0x80068298: nop
    
            goto L_800682B8;
    }
    // 0x80068298: nop

    // 0x8006829C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800682A0: nop

    // 0x800682A4: lh          $t5, 0xE($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XE);
    // 0x800682A8: nop

    // 0x800682AC: sra         $t7, $t5, 4
    ctx->r15 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800682B0: b           L_800682D8
    // 0x800682B4: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
        goto L_800682D8;
    // 0x800682B4: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
L_800682B8:
    // 0x800682B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800682BC: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x800682C0: lh          $t8, 0xE($t6)
    ctx->r24 = MEM_H(ctx->r14, 0XE);
    // 0x800682C4: nop

    // 0x800682C8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800682CC: mflo        $t0
    ctx->r8 = lo;
    // 0x800682D0: srl         $t1, $t0, 12
    ctx->r9 = S32(U32(ctx->r8) >> 12);
    // 0x800682D4: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
L_800682D8:
    // 0x800682D8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800682DC: nop

    // 0x800682E0: lhu         $a0, 0xA($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0XA);
    // 0x800682E4: jal         0x80070D00
    // 0x800682E8: nop

    Minos_SetScale(rdram, ctx);
        goto after_0;
    // 0x800682E8: nop

    after_0:
    // 0x800682EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800682F0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800682F4: addiu       $a1, $a1, -0x2AF4
    ctx->r5 = ADD32(ctx->r5, -0X2AF4);
    // 0x800682F8: jal         0x8006CF08
    // 0x800682FC: addiu       $a0, $a0, -0x2B10
    ctx->r4 = ADD32(ctx->r4, -0X2B10);
    debug_print2(rdram, ctx);
        goto after_1;
    // 0x800682FC: addiu       $a0, $a0, -0x2B10
    ctx->r4 = ADD32(ctx->r4, -0X2B10);
    after_1:
    // 0x80068300: jal         0x80064FB0
    // 0x80068304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    MobilePiece_Render(rdram, ctx);
        goto after_2;
    // 0x80068304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80068308: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006830C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80068310: addiu       $a1, $a1, -0x2AC8
    ctx->r5 = ADD32(ctx->r5, -0X2AC8);
    // 0x80068314: jal         0x8006CF08
    // 0x80068318: addiu       $a0, $a0, -0x2AE4
    ctx->r4 = ADD32(ctx->r4, -0X2AE4);
    debug_print2(rdram, ctx);
        goto after_3;
    // 0x80068318: addiu       $a0, $a0, -0x2AE4
    ctx->r4 = ADD32(ctx->r4, -0X2AE4);
    after_3:
    // 0x8006831C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80068320: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068324: jr          $ra
    // 0x80068328: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80068328: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

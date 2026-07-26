#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void gamefinish_StepResultSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052AA0: lh          $t7, 0x12($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X12);
    // 0x80052AA4: lh          $t6, 0x10($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X10);
    // 0x80052AA8: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80052AAC: mflo        $t8
    ctx->r24 = lo;
    // 0x80052AB0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80052AB4: sh          $t9, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r25;
    // 0x80052AB8: lh          $t0, 0x10($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X10);
    // 0x80052ABC: nop

    // 0x80052AC0: slti        $at, $t0, 0x500
    ctx->r1 = SIGNED(ctx->r8) < 0X500 ? 1 : 0;
    // 0x80052AC4: beq         $at, $zero, L_80052AD8
    if (ctx->r1 == 0) {
        // 0x80052AC8: nop
    
            goto L_80052AD8;
    }
    // 0x80052AC8: nop

    // 0x80052ACC: addiu       $t1, $zero, 0x500
    ctx->r9 = ADD32(0, 0X500);
    // 0x80052AD0: sh          $t1, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r9;
    // 0x80052AD4: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
L_80052AD8:
    // 0x80052AD8: lh          $t3, 0xE($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XE);
    // 0x80052ADC: lh          $t6, 0x16($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X16);
    // 0x80052AE0: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80052AE4: lh          $t7, 0x14($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X14);
    // 0x80052AE8: lhu         $t2, 0xC($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0XC);
    // 0x80052AEC: mflo        $t4
    ctx->r12 = lo;
    // 0x80052AF0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80052AF4: sh          $t5, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r13;
    // 0x80052AF8: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80052AFC: mflo        $t8
    ctx->r24 = lo;
    // 0x80052B00: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80052B04: sh          $t9, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r25;
    // 0x80052B08: lh          $t0, 0x14($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X14);
    // 0x80052B0C: nop

    // 0x80052B10: slti        $at, $t0, 0xFF0
    ctx->r1 = SIGNED(ctx->r8) < 0XFF0 ? 1 : 0;
    // 0x80052B14: bne         $at, $zero, L_80052B28
    if (ctx->r1 != 0) {
        // 0x80052B18: nop
    
            goto L_80052B28;
    }
    // 0x80052B18: nop

    // 0x80052B1C: addiu       $t1, $zero, 0xFF0
    ctx->r9 = ADD32(0, 0XFF0);
    // 0x80052B20: sh          $t1, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r9;
    // 0x80052B24: sh          $zero, 0x16($a0)
    MEM_H(0X16, ctx->r4) = 0;
L_80052B28:
    // 0x80052B28: jr          $ra
    // 0x80052B2C: nop

    return;
    // 0x80052B2C: nop

;}

RECOMP_FUNC void gamefinish_DrawResultSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052B30: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80052B34: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80052B38: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80052B3C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80052B40: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80052B44: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x80052B48: nop

    // 0x80052B4C: sh          $t7, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r15;
    // 0x80052B50: lhu         $a0, 0xC($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0XC);
    // 0x80052B54: jal         0x80060914
    // 0x80052B58: nop

    FUN_026900_80060914_oneliner_shift6_2(rdram, ctx);
        goto after_0;
    // 0x80052B58: nop

    after_0:
    // 0x80052B5C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80052B60: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80052B64: lh          $t0, 0x10($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X10);
    // 0x80052B68: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x80052B6C: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80052B70: mflo        $t1
    ctx->r9 = lo;
    // 0x80052B74: sra         $t2, $t1, 22
    ctx->r10 = S32(SIGNED(ctx->r9) >> 22);
    // 0x80052B78: subu        $t3, $t9, $t2
    ctx->r11 = SUB32(ctx->r25, ctx->r10);
    // 0x80052B7C: jal         0x8005BBFC
    // 0x80052B80: sh          $t3, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r11;
    Gfx_SetupRenderState(rdram, ctx);
        goto after_1;
    // 0x80052B80: sh          $t3, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r11;
    after_1:
    // 0x80052B84: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80052B88: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x80052B8C: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80052B90: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80052B94: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80052B98: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80052B9C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80052BA0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80052BA4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80052BA8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80052BAC: lh          $t0, 0x14($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X14);
    // 0x80052BB0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80052BB4: lh          $a3, 0x34($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X34);
    // 0x80052BB8: sra         $t1, $t0, 4
    ctx->r9 = S32(SIGNED(ctx->r8) >> 4);
    // 0x80052BBC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80052BC0: jal         0x80057460
    // 0x80052BC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_2;
    // 0x80052BC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80052BC8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80052BCC: jal         0x8005BE40
    // 0x80052BD0: nop

    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_3;
    // 0x80052BD0: nop

    after_3:
    // 0x80052BD4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80052BD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80052BDC: jr          $ra
    // 0x80052BE0: nop

    return;
    // 0x80052BE0: nop

;}

RECOMP_FUNC void gamefinish_InitResultSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052BE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80052BE8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80052BEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80052BF0: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80052BF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80052BF8: beq         $s0, $zero, L_80052C1C
    if (ctx->r16 == 0) {
        // 0x80052BFC: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_80052C1C;
    }
    // 0x80052BFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80052C00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052C04: beq         $s0, $at, L_80052C30
    if (ctx->r16 == ctx->r1) {
        // 0x80052C08: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80052C30;
    }
    // 0x80052C08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052C0C: beq         $s0, $at, L_80052C44
    if (ctx->r16 == ctx->r1) {
        // 0x80052C10: nop
    
            goto L_80052C44;
    }
    // 0x80052C10: nop

    // 0x80052C14: b           L_80052C58
    // 0x80052C18: nop

        goto L_80052C58;
    // 0x80052C18: nop

L_80052C1C:
    // 0x80052C1C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80052C20: lw          $t6, -0x80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X80);
    // 0x80052C24: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80052C28: b           L_80052C70
    // 0x80052C2C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
        goto L_80052C70;
    // 0x80052C2C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_80052C30:
    // 0x80052C30: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80052C34: lw          $t8, -0x7C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C);
    // 0x80052C38: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80052C3C: b           L_80052C70
    // 0x80052C40: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
        goto L_80052C70;
    // 0x80052C40: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_80052C44:
    // 0x80052C44: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80052C48: lw          $t0, -0x78($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X78);
    // 0x80052C4C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80052C50: b           L_80052C70
    // 0x80052C54: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
        goto L_80052C70;
    // 0x80052C54: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_80052C58:
    // 0x80052C58: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052C5C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80052C60: addiu       $a1, $a1, -0x3250
    ctx->r5 = ADD32(ctx->r5, -0X3250);
    // 0x80052C64: addiu       $a0, $a0, -0x3260
    ctx->r4 = ADD32(ctx->r4, -0X3260);
    // 0x80052C68: jal         0x8004A5A0
    // 0x80052C6C: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_0;
    // 0x80052C6C: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    after_0:
L_80052C70:
    // 0x80052C70: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80052C74: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80052C78: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80052C7C: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x80052C80: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80052C84: nop

    // 0x80052C88: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80052C8C: subu        $t7, $t3, $t6
    ctx->r15 = SUB32(ctx->r11, ctx->r14);
    // 0x80052C90: sh          $t7, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r15;
    // 0x80052C94: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80052C98: addiu       $t3, $zero, 0x3C00
    ctx->r11 = ADD32(0, 0X3C00);
    // 0x80052C9C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80052CA0: lh          $t9, 0xA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XA);
    // 0x80052CA4: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
    // 0x80052CA8: nop

    // 0x80052CAC: sra         $t4, $t1, 1
    ctx->r12 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80052CB0: subu        $t5, $t9, $t4
    ctx->r13 = SUB32(ctx->r25, ctx->r12);
    // 0x80052CB4: sh          $t5, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r13;
    // 0x80052CB8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80052CBC: addiu       $t4, $zero, 0x333
    ctx->r12 = ADD32(0, 0X333);
    // 0x80052CC0: sh          $t3, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r11;
    // 0x80052CC4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80052CC8: addiu       $t3, $zero, 0xCC
    ctx->r11 = ADD32(0, 0XCC);
    // 0x80052CCC: lh          $t2, 0x10($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X10);
    // 0x80052CD0: nop

    // 0x80052CD4: negu        $t0, $t2
    ctx->r8 = SUB32(0, ctx->r10);
    // 0x80052CD8: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80052CDC: mflo        $t1
    ctx->r9 = lo;
    // 0x80052CE0: sh          $t1, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r9;
    // 0x80052CE4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80052CE8: nop

    // 0x80052CEC: sh          $zero, 0xC($t9)
    MEM_H(0XC, ctx->r25) = 0;
    // 0x80052CF0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80052CF4: nop

    // 0x80052CF8: sh          $t4, 0xE($t5)
    MEM_H(0XE, ctx->r13) = ctx->r12;
    // 0x80052CFC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80052D00: nop

    // 0x80052D04: sh          $zero, 0x14($t8)
    MEM_H(0X14, ctx->r24) = 0;
    // 0x80052D08: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80052D0C: nop

    // 0x80052D10: sh          $t3, 0x16($t6)
    MEM_H(0X16, ctx->r14) = ctx->r11;
    // 0x80052D14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80052D18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80052D1C: jr          $ra
    // 0x80052D20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80052D20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void gamefinish_SetResultPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052D24: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80052D28: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x80052D2C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80052D30: nop

    // 0x80052D34: swl         $at, 0x8($a0)
    do_swl(rdram, 0X8, ctx->r4, ctx->r1);
    // 0x80052D38: jr          $ra
    // 0x80052D3C: swr         $at, 0xB($a0)
    do_swr(rdram, 0XB, ctx->r4, ctx->r1);
    return;
    // 0x80052D3C: swr         $at, 0xB($a0)
    do_swr(rdram, 0XB, ctx->r4, ctx->r1);
;}

RECOMP_FUNC void gamefinish_80052D40_doesnothing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052D40: jr          $ra
    // 0x80052D44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80052D44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

RECOMP_FUNC void gamefinish_SetPhase4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052D48: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80052D4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80052D50: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80052D54: jr          $ra
    // 0x80052D58: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    return;
    // 0x80052D58: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void gamefinish_SetPhase3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052D5C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80052D60: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x80052D64: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80052D68: jr          $ra
    // 0x80052D6C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    return;
    // 0x80052D6C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void gamefinish_SetPhase2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052D70: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80052D74: addiu       $t7, $zero, 0x13
    ctx->r15 = ADD32(0, 0X13);
    // 0x80052D78: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80052D7C: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80052D80: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80052D84: jr          $ra
    // 0x80052D88: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    return;
    // 0x80052D88: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
;}

RECOMP_FUNC void gamefinish_SetPhase1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052D8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80052D90: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80052D94: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80052D98: jr          $ra
    // 0x80052D9C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    return;
    // 0x80052D9C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void gamefinish_80052DA0_oneliner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052DA0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80052DA4: jr          $ra
    // 0x80052DA8: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    return;
    // 0x80052DA8: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
;}

RECOMP_FUNC void gamefinish_AnimateBoardClearRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052DAC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80052DB0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80052DB4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80052DB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80052DBC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80052DC0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80052DC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80052DC8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80052DCC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80052DD0: nop

    // 0x80052DD4: bltz        $t7, L_80052E44
    if (SIGNED(ctx->r15) < 0) {
        // 0x80052DD8: sw          $t7, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r15;
            goto L_80052E44;
    }
    // 0x80052DD8: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80052DDC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80052DE0: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80052DE4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80052DE8: lw          $t8, -0x430($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X430);
    // 0x80052DEC: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80052DF0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80052DF4: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80052DF8: addu        $s0, $t8, $t0
    ctx->r16 = ADD32(ctx->r24, ctx->r8);
    // 0x80052DFC: blez        $s1, L_80052E44
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80052E00: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80052E44;
    }
    // 0x80052E00: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80052E04:
    // 0x80052E04: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80052E08: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80052E0C: lbu         $t2, 0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1);
    // 0x80052E10: nop

    // 0x80052E14: beq         $t2, $at, L_80052E38
    if (ctx->r10 == ctx->r1) {
        // 0x80052E18: nop
    
            goto L_80052E38;
    }
    // 0x80052E18: nop

    // 0x80052E1C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80052E20: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80052E24: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x80052E28: addiu       $a1, $a1, -0x90
    ctx->r5 = ADD32(ctx->r5, -0X90);
    // 0x80052E2C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80052E30: jal         0x80070860
    // 0x80052E34: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_80070860_fortyliner(rdram, ctx);
        goto after_0;
    // 0x80052E34: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
L_80052E38:
    // 0x80052E38: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80052E3C: bgtz        $s1, L_80052E04
    if (SIGNED(ctx->r17) > 0) {
        // 0x80052E40: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80052E04;
    }
    // 0x80052E40: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80052E44:
    // 0x80052E44: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80052E48: nop

    // 0x80052E4C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80052E50: nop

    // 0x80052E54: addiu       $t6, $t5, 0x5
    ctx->r14 = ADD32(ctx->r13, 0X5);
    // 0x80052E58: bltz        $t6, L_80052EDC
    if (SIGNED(ctx->r14) < 0) {
        // 0x80052E5C: sw          $t6, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r14;
            goto L_80052EDC;
    }
    // 0x80052E5C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80052E60: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x80052E64: beq         $at, $zero, L_80052EDC
    if (ctx->r1 == 0) {
        // 0x80052E68: nop
    
            goto L_80052EDC;
    }
    // 0x80052E68: nop

    // 0x80052E6C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80052E70: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80052E74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80052E78: lw          $t7, -0x430($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X430);
    // 0x80052E7C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80052E80: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80052E84: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x80052E88: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x80052E8C: blez        $s3, L_80052EDC
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80052E90: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80052EDC;
    }
    // 0x80052E90: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80052E94:
    // 0x80052E94: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80052E98: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80052E9C: lbu         $t1, 0x1($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1);
    // 0x80052EA0: nop

    // 0x80052EA4: beq         $t1, $at, L_80052ED0
    if (ctx->r9 == ctx->r1) {
        // 0x80052EA8: nop
    
            goto L_80052ED0;
    }
    // 0x80052EA8: nop

    // 0x80052EAC: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80052EB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80052EB4: lw          $a0, 0xC($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XC);
    // 0x80052EB8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80052EBC: jal         0x800709EC
    // 0x80052EC0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_Mino_FadeBrightness(rdram, ctx);
        goto after_1;
    // 0x80052EC0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
    // 0x80052EC4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80052EC8: jal         0x8006D5BC
    // 0x80052ECC: nop

    BoardP_SeparateCell(rdram, ctx);
        goto after_2;
    // 0x80052ECC: nop

    after_2:
L_80052ED0:
    // 0x80052ED0: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80052ED4: bgtz        $s3, L_80052E94
    if (SIGNED(ctx->r19) > 0) {
        // 0x80052ED8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80052E94;
    }
    // 0x80052ED8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80052EDC:
    // 0x80052EDC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80052EE0: nop

    // 0x80052EE4: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80052EE8: nop

    // 0x80052EEC: slti        $at, $t4, -0x4
    ctx->r1 = SIGNED(ctx->r12) < -0X4 ? 1 : 0;
    // 0x80052EF0: beq         $at, $zero, L_80052F08
    if (ctx->r1 == 0) {
        // 0x80052EF4: nop
    
            goto L_80052F08;
    }
    // 0x80052EF4: nop

    // 0x80052EF8: jal         0x80052D5C
    // 0x80052EFC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    gamefinish_SetPhase3(rdram, ctx);
        goto after_3;
    // 0x80052EFC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_3:
    // 0x80052F00: b           L_80052F20
    // 0x80052F04: nop

        goto L_80052F20;
    // 0x80052F04: nop

L_80052F08:
    // 0x80052F08: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80052F0C: nop

    // 0x80052F10: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80052F14: nop

    // 0x80052F18: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80052F1C: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
L_80052F20:
    // 0x80052F20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80052F24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80052F28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80052F2C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80052F30: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80052F34: jr          $ra
    // 0x80052F38: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80052F38: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void gamefinish_UpdateClearPhase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052F3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80052F40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80052F44: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80052F48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80052F4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052F50: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80052F54: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80052F58: nop

    // 0x80052F5C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80052F60: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80052F64: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80052F68: nop

    // 0x80052F6C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80052F70: nop

    // 0x80052F74: bgtz        $t1, L_80052FB8
    if (SIGNED(ctx->r9) > 0) {
        // 0x80052F78: nop
    
            goto L_80052FB8;
    }
    // 0x80052F78: nop

L_80052F7C:
    // 0x80052F7C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80052F80: nop

    // 0x80052F84: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80052F88: nop

    // 0x80052F8C: addiu       $t4, $t3, 0x3
    ctx->r12 = ADD32(ctx->r11, 0X3);
    // 0x80052F90: sw          $t4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r12;
    // 0x80052F94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80052F98: jal         0x80052DAC
    // 0x80052F9C: nop

    gamefinish_AnimateBoardClearRow(rdram, ctx);
        goto after_0;
    // 0x80052F9C: nop

    after_0:
    // 0x80052FA0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80052FA4: nop

    // 0x80052FA8: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x80052FAC: nop

    // 0x80052FB0: blez        $t7, L_80052F7C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80052FB4: nop
    
            goto L_80052F7C;
    }
    // 0x80052FB4: nop

L_80052FB8:
    // 0x80052FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80052FC0: jr          $ra
    // 0x80052FC4: nop

    return;
    // 0x80052FC4: nop

;}

RECOMP_FUNC void gamefinish_UpdateWaitPhase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052FC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80052FCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80052FD0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80052FD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052FD8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80052FDC: lbu         $t7, 0x38($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X38);
    // 0x80052FE0: nop

    // 0x80052FE4: bne         $t7, $zero, L_80053030
    if (ctx->r15 != 0) {
        // 0x80052FE8: nop
    
            goto L_80053030;
    }
    // 0x80052FE8: nop

    // 0x80052FEC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80052FF0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80052FF4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80052FF8: nop

    // 0x80052FFC: sltu        $at, $t9, $t0
    ctx->r1 = ctx->r25 < ctx->r8 ? 1 : 0;
    // 0x80053000: beq         $at, $zero, L_80053018
    if (ctx->r1 == 0) {
        // 0x80053004: nop
    
            goto L_80053018;
    }
    // 0x80053004: nop

    // 0x80053008: jal         0x80052D48
    // 0x8005300C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    gamefinish_SetPhase4(rdram, ctx);
        goto after_0;
    // 0x8005300C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x80053010: b           L_80053030
    // 0x80053014: nop

        goto L_80053030;
    // 0x80053014: nop

L_80053018:
    // 0x80053018: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8005301C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80053020: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80053024: nop

    // 0x80053028: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x8005302C: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
L_80053030:
    // 0x80053030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053038: jr          $ra
    // 0x8005303C: nop

    return;
    // 0x8005303C: nop

;}

RECOMP_FUNC void gamefinish_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053040: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80053044: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80053048: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005304C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80053050: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80053054: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80053058: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005305C: lbu         $t7, 0x18($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X18);
    // 0x80053060: nop

    // 0x80053064: bne         $t7, $zero, L_80053074
    if (ctx->r15 != 0) {
        // 0x80053068: nop
    
            goto L_80053074;
    }
    // 0x80053068: nop

    // 0x8005306C: b           L_8005326C
    // 0x80053070: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8005326C;
    // 0x80053070: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80053074:
    // 0x80053074: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80053078: nop

    // 0x8005307C: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    // 0x80053080: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80053084: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80053088: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8005308C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x80053090: bgez        $t9, L_800530A8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80053094: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800530A8;
    }
    // 0x80053094: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80053098: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8005309C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800530A0: nop

    // 0x800530A4: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800530A8:
    // 0x800530A8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800530AC: jal         0x80060770
    // 0x800530B0: nop

    PFGFX_StepValueToTarget(rdram, ctx);
        goto after_0;
    // 0x800530B0: nop

    after_0:
    // 0x800530B4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800530B8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800530BC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800530C0: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x800530C4: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800530C8: nop

    // 0x800530CC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800530D0: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x800530D4: nop

    // 0x800530D8: andi        $at, $s0, 0x4
    ctx->r1 = ctx->r16 & 0X4;
    // 0x800530DC: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x800530E0: beq         $s0, $zero, L_80053130
    if (ctx->r16 == 0) {
        // 0x800530E4: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80053130;
    }
    // 0x800530E4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800530E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800530EC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800530F0: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800530F4: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x800530F8: nop

    // 0x800530FC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80053100: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x80053104: nop

    // 0x80053108: andi        $at, $s0, 0x4
    ctx->r1 = ctx->r16 & 0X4;
    // 0x8005310C: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x80053110: bne         $s0, $zero, L_80053128
    if (ctx->r16 != 0) {
        // 0x80053114: nop
    
            goto L_80053128;
    }
    // 0x80053114: nop

    // 0x80053118: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x8005311C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80053120: b           L_80053140
    // 0x80053124: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
        goto L_80053140;
    // 0x80053124: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
L_80053128:
    // 0x80053128: b           L_80053140
    // 0x8005312C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_80053140;
    // 0x8005312C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_80053130:
    // 0x80053130: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x80053134: nop

    // 0x80053138: bltz        $s0, L_80053128
    if (SIGNED(ctx->r16) < 0) {
        // 0x8005313C: nop
    
            goto L_80053128;
    }
    // 0x8005313C: nop

L_80053140:
    // 0x80053140: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80053144: lw          $t3, -0x490($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X490);
    // 0x80053148: andi        $t2, $s0, 0xFF
    ctx->r10 = ctx->r16 & 0XFF;
    // 0x8005314C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80053150: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80053154: sb          $s0, 0x14($t3)
    MEM_B(0X14, ctx->r11) = ctx->r16;
    // 0x80053158: lw          $t4, -0x480($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X480);
    // 0x8005315C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80053160: sb          $s0, 0x291A($t4)
    MEM_B(0X291A, ctx->r12) = ctx->r16;
    // 0x80053164: lw          $t5, -0xDD0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XDD0);
    // 0x80053168: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8005316C: sb          $s0, 0x5210($t5)
    MEM_B(0X5210, ctx->r13) = ctx->r16;
    // 0x80053170: lw          $t6, -0xDD0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XDD0);
    // 0x80053174: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80053178: sb          $s0, 0x5729($t6)
    MEM_B(0X5729, ctx->r14) = ctx->r16;
    // 0x8005317C: lw          $t7, -0xDD0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XDD0);
    // 0x80053180: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80053184: sb          $s0, 0x5C58($t7)
    MEM_B(0X5C58, ctx->r15) = ctx->r16;
    // 0x80053188: lw          $t8, -0xDD0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XDD0);
    // 0x8005318C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80053190: sb          $s0, 0x6171($t8)
    MEM_B(0X6171, ctx->r24) = ctx->r16;
    // 0x80053194: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80053198: lw          $a0, -0x400($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X400);
    // 0x8005319C: jal         0x8006F064
    // 0x800531A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    FallingCubes_SetAlpha(rdram, ctx);
        goto after_1;
    // 0x800531A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800531A4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800531A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800531AC: lbu         $s1, 0x0($t9)
    ctx->r17 = MEM_BU(ctx->r25, 0X0);
    // 0x800531B0: nop

    // 0x800531B4: beq         $s1, $at, L_800531DC
    if (ctx->r17 == ctx->r1) {
        // 0x800531B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800531DC;
    }
    // 0x800531B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800531BC: beq         $s1, $at, L_800531F4
    if (ctx->r17 == ctx->r1) {
        // 0x800531C0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800531F4;
    }
    // 0x800531C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800531C4: beq         $s1, $at, L_8005320C
    if (ctx->r17 == ctx->r1) {
        // 0x800531C8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005320C;
    }
    // 0x800531C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800531CC: beq         $s1, $at, L_80053224
    if (ctx->r17 == ctx->r1) {
        // 0x800531D0: nop
    
            goto L_80053224;
    }
    // 0x800531D0: nop

    // 0x800531D4: b           L_80053234
    // 0x800531D8: nop

        goto L_80053234;
    // 0x800531D8: nop

L_800531DC:
    // 0x800531DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800531E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800531E4: jal         0x80052DA0
    // 0x800531E8: nop

    gamefinish_80052DA0_oneliner(rdram, ctx);
        goto after_2;
    // 0x800531E8: nop

    after_2:
    // 0x800531EC: b           L_8005324C
    // 0x800531F0: nop

        goto L_8005324C;
    // 0x800531F0: nop

L_800531F4:
    // 0x800531F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800531F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800531FC: jal         0x80052F3C
    // 0x80053200: nop

    gamefinish_UpdateClearPhase(rdram, ctx);
        goto after_3;
    // 0x80053200: nop

    after_3:
    // 0x80053204: b           L_8005324C
    // 0x80053208: nop

        goto L_8005324C;
    // 0x80053208: nop

L_8005320C:
    // 0x8005320C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80053210: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80053214: jal         0x80052FC8
    // 0x80053218: nop

    gamefinish_UpdateWaitPhase(rdram, ctx);
        goto after_4;
    // 0x80053218: nop

    after_4:
    // 0x8005321C: b           L_8005324C
    // 0x80053220: nop

        goto L_8005324C;
    // 0x80053220: nop

L_80053224:
    // 0x80053224: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80053228: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005322C: b           L_8005324C
    // 0x80053230: sb          $t0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r8;
        goto L_8005324C;
    // 0x80053230: sb          $t0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r8;
L_80053234:
    // 0x80053234: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80053238: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005323C: addiu       $a1, $a1, -0x3230
    ctx->r5 = ADD32(ctx->r5, -0X3230);
    // 0x80053240: addiu       $a0, $a0, -0x3240
    ctx->r4 = ADD32(ctx->r4, -0X3240);
    // 0x80053244: jal         0x8004A5A0
    // 0x80053248: addiu       $a2, $zero, 0x17F
    ctx->r6 = ADD32(0, 0X17F);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_5;
    // 0x80053248: addiu       $a2, $zero, 0x17F
    ctx->r6 = ADD32(0, 0X17F);
    after_5:
L_8005324C:
    // 0x8005324C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80053250: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80053254: jal         0x80052AA0
    // 0x80053258: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    gamefinish_StepResultSprite(rdram, ctx);
        goto after_6;
    // 0x80053258: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_6:
    // 0x8005325C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80053260: nop

    // 0x80053264: lbu         $v0, 0x1($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X1);
    // 0x80053268: nop

L_8005326C:
    // 0x8005326C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80053270: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80053274: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80053278: jr          $ra
    // 0x8005327C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005327C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void gamefinish_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80053288: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8005328C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053290: lbu         $t7, 0x18($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X18);
    // 0x80053294: nop

    // 0x80053298: beq         $t7, $zero, L_800532CC
    if (ctx->r15 == 0) {
        // 0x8005329C: nop
    
            goto L_800532CC;
    }
    // 0x8005329C: nop

    // 0x800532A0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800532A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800532A8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800532AC: nop

    // 0x800532B0: beq         $t9, $at, L_800532CC
    if (ctx->r25 == ctx->r1) {
        // 0x800532B4: nop
    
            goto L_800532CC;
    }
    // 0x800532B4: nop

    // 0x800532B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800532BC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800532C0: addiu       $a1, $a1, 0x20C0
    ctx->r5 = ADD32(ctx->r5, 0X20C0);
    // 0x800532C4: jal         0x80052B30
    // 0x800532C8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    gamefinish_DrawResultSprite(rdram, ctx);
        goto after_0;
    // 0x800532C8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
L_800532CC:
    // 0x800532CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800532D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800532D4: jr          $ra
    // 0x800532D8: nop

    return;
    // 0x800532D8: nop

;}

RECOMP_FUNC void gamefinish_800532DC_nevercalled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800532DC: jr          $ra
    // 0x800532E0: sb          $zero, 0x38($a0)
    MEM_B(0X38, ctx->r4) = 0;
    return;
    // 0x800532E0: sb          $zero, 0x38($a0)
    MEM_B(0X38, ctx->r4) = 0;
;}

RECOMP_FUNC void gamefinish_Start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800532E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800532E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800532EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800532F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800532F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800532F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800532FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80053300: jal         0x80052BE4
    // 0x80053304: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    gamefinish_InitResultSprite(rdram, ctx);
        goto after_0;
    // 0x80053304: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x80053308: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8005330C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80053310: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80053314: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80053318: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x8005331C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80053320: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80053324: swc1        $f6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f6.u32l;
    // 0x80053328: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8005332C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80053330: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80053334: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80053338: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005333C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80053340: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80053344: swc1        $f4, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f4.u32l;
    // 0x80053348: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8005334C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80053350: nop

    // 0x80053354: sw          $t9, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r25;
    // 0x80053358: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005335C: nop

    // 0x80053360: sb          $t1, 0x18($t2)
    MEM_B(0X18, ctx->r10) = ctx->r9;
    // 0x80053364: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80053368: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x8005336C: nop

    // 0x80053370: sb          $t3, 0x38($t4)
    MEM_B(0X38, ctx->r12) = ctx->r11;
    // 0x80053374: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80053378: jal         0x80052D70
    // 0x8005337C: nop

    gamefinish_SetPhase2(rdram, ctx);
        goto after_1;
    // 0x8005337C: nop

    after_1:
    // 0x80053380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053388: jr          $ra
    // 0x8005338C: nop

    return;
    // 0x8005338C: nop

;}

RECOMP_FUNC void gamefinish_StopAtBoardCenter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053390: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80053394: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80053398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005339C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800533A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800533A4: jal         0x8006D344
    // 0x800533A8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    Board_GetCenter(rdram, ctx);
        goto after_0;
    // 0x800533A8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800533AC: lwl         $t6, 0x1C($sp)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r29, 0X1C);
    // 0x800533B0: lwr         $t6, 0x1F($sp)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r29, 0X1F);
    // 0x800533B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800533B8: swl         $t6, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r14);
    // 0x800533BC: swr         $t6, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r14);
    // 0x800533C0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x800533C4: jal         0x80052D24
    // 0x800533C8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    gamefinish_SetResultPos(rdram, ctx);
        goto after_1;
    // 0x800533C8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_1:
    // 0x800533CC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800533D0: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800533D4: sb          $zero, 0x18($t7)
    MEM_B(0X18, ctx->r15) = 0;
    // 0x800533D8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800533DC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800533E0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800533E4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800533E8: nop

    // 0x800533EC: sw          $t0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r8;
    // 0x800533F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800533F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800533F8: jr          $ra
    // 0x800533FC: nop

    return;
    // 0x800533FC: nop

;}

RECOMP_FUNC void gamefinish_Stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053404: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80053408: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005340C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053410: jal         0x80052D40
    // 0x80053414: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    gamefinish_80052D40_doesnothing(rdram, ctx);
        goto after_0;
    // 0x80053414: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x80053418: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8005341C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80053420: sb          $zero, 0x18($t6)
    MEM_B(0X18, ctx->r14) = 0;
    // 0x80053424: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80053428: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8005342C: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80053430: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80053434: nop

    // 0x80053438: sw          $t9, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r25;
    // 0x8005343C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053444: jr          $ra
    // 0x80053448: nop

    return;
    // 0x80053448: nop

;}

RECOMP_FUNC void gamefinish_LoadResultImages(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005344C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053450: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80053454: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x80053458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005345C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053460: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80053464: addiu       $a0, $a0, -0x78
    ctx->r4 = ADD32(ctx->r4, -0X78);
    // 0x80053468: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x8005346C: jal         0x8007FBB0
    // 0x80053470: sb          $t6, -0x84($at)
    MEM_B(-0X84, ctx->r1) = ctx->r14;
    gamefinish_LoadResultImage(rdram, ctx);
        goto after_0;
    // 0x80053470: sb          $t6, -0x84($at)
    MEM_B(-0X84, ctx->r1) = ctx->r14;
    after_0:
    // 0x80053474: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80053478: addiu       $a0, $a0, -0x80
    ctx->r4 = ADD32(ctx->r4, -0X80);
    // 0x8005347C: jal         0x8007FBB0
    // 0x80053480: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    gamefinish_LoadResultImage(rdram, ctx);
        goto after_1;
    // 0x80053480: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    after_1:
    // 0x80053484: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80053488: addiu       $a0, $a0, -0x7C
    ctx->r4 = ADD32(ctx->r4, -0X7C);
    // 0x8005348C: jal         0x8007FBB0
    // 0x80053490: addiu       $a1, $zero, 0x97
    ctx->r5 = ADD32(0, 0X97);
    gamefinish_LoadResultImage(rdram, ctx);
        goto after_2;
    // 0x80053490: addiu       $a1, $zero, 0x97
    ctx->r5 = ADD32(0, 0X97);
    after_2:
    // 0x80053494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005349C: jr          $ra
    // 0x800534A0: nop

    return;
    // 0x800534A0: nop

;}

RECOMP_FUNC void gamefinish_FreeResultImages(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800534A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800534A8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800534AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800534B0: lw          $a0, -0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78);
    // 0x800534B4: jal         0x8007E328
    // 0x800534B8: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800534B8: nop

    after_0:
    // 0x800534BC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800534C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800534C4: lw          $a0, -0x80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X80);
    // 0x800534C8: jal         0x8007E328
    // 0x800534CC: sw          $zero, -0x78($at)
    MEM_W(-0X78, ctx->r1) = 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x800534CC: sw          $zero, -0x78($at)
    MEM_W(-0X78, ctx->r1) = 0;
    after_1:
    // 0x800534D0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800534D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800534D8: lw          $a0, -0x7C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7C);
    // 0x800534DC: jal         0x8007E328
    // 0x800534E0: sw          $zero, -0x80($at)
    MEM_W(-0X80, ctx->r1) = 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_2;
    // 0x800534E0: sw          $zero, -0x80($at)
    MEM_W(-0X80, ctx->r1) = 0;
    after_2:
    // 0x800534E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800534E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800534EC: sw          $zero, -0x7C($at)
    MEM_W(-0X7C, ctx->r1) = 0;
    // 0x800534F0: jr          $ra
    // 0x800534F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800534F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800534F8: nop

    // 0x800534FC: nop

;}

RECOMP_FUNC void gamefinish_InitResultScreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053508: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005350C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053510: jal         0x8006093C
    // 0x80053514: sh          $t6, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r14;
    FUN_026900_8006093c_rounds_floors_loops_1024t(rdram, ctx);
        goto after_0;
    // 0x80053514: sh          $t6, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r14;
    after_0:
    // 0x80053518: jal         0x80075DF4
    // 0x8005351C: nop

    CubeTiles_InitColorTables(rdram, ctx);
        goto after_1;
    // 0x8005351C: nop

    after_1:
    // 0x80053520: jal         0x80054F5C
    // 0x80053524: nop

    initPieceColorsScale16(rdram, ctx);
        goto after_2;
    // 0x80053524: nop

    after_2:
    // 0x80053528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005352C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053530: jr          $ra
    // 0x80053534: nop

    return;
    // 0x80053534: nop

;}

RECOMP_FUNC void gamefinish_LoadResultImage(uint8_t* rdram, recomp_context* ctx) {
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

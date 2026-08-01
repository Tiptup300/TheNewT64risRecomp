#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void MultisquareGlow_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AF00: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8006AF04: nop

    // 0x8006AF08: beq         $t6, $zero, L_8006AF68
    if (ctx->r14 == 0) {
        // 0x8006AF0C: nop
    
            goto L_8006AF68;
    }
    // 0x8006AF0C: nop

    // 0x8006AF10: lbu         $t7, 0x6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X6);
    // 0x8006AF14: nop

    // 0x8006AF18: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8006AF1C: beq         $at, $zero, L_8006AF2C
    if (ctx->r1 == 0) {
        // 0x8006AF20: nop
    
            goto L_8006AF2C;
    }
    // 0x8006AF20: nop

    // 0x8006AF24: lbu         $a1, 0x6($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X6);
    // 0x8006AF28: nop

L_8006AF2C:
    // 0x8006AF2C: lbu         $t8, 0x6($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X6);
    // 0x8006AF30: nop

    // 0x8006AF34: subu        $t9, $t8, $a1
    ctx->r25 = SUB32(ctx->r24, ctx->r5);
    // 0x8006AF38: sb          $t9, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r25;
    // 0x8006AF3C: lbu         $t0, 0x6($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X6);
    // 0x8006AF40: nop

    // 0x8006AF44: bne         $t0, $zero, L_8006AF50
    if (ctx->r8 != 0) {
        // 0x8006AF48: nop
    
            goto L_8006AF50;
    }
    // 0x8006AF48: nop

    // 0x8006AF4C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_8006AF50:
    // 0x8006AF50: lhu         $t2, 0x4($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X4);
    // 0x8006AF54: lhu         $t1, 0x2($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X2);
    // 0x8006AF58: multu       $t2, $a1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AF5C: mflo        $t3
    ctx->r11 = lo;
    // 0x8006AF60: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8006AF64: sh          $t4, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r12;
L_8006AF68:
    // 0x8006AF68: jr          $ra
    // 0x8006AF6C: nop

    return;
    // 0x8006AF6C: nop

;}

RECOMP_FUNC void MultisquareGlow_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AF70: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006AF74: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8006AF78: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8006AF7C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006AF80: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8006AF84: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8006AF88: nop

    // 0x8006AF8C: beq         $t7, $zero, L_8006B040
    if (ctx->r15 == 0) {
        // 0x8006AF90: nop
    
            goto L_8006B040;
    }
    // 0x8006AF90: nop

    // 0x8006AF94: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8006AF98: nop

    // 0x8006AF9C: lhu         $a0, 0x2($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X2);
    // 0x8006AFA0: jal         0x800B8010
    // 0x8006AFA4: nop

    sins(rdram, ctx);
        goto after_0;
    // 0x8006AFA4: nop

    after_0:
    // 0x8006AFA8: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x8006AFAC: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x8006AFB0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8006AFB4: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x8006AFB8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8006AFBC: lbu         $t1, 0xC($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XC);
    // 0x8006AFC0: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8006AFC4: sra         $t9, $s0, 15
    ctx->r25 = S32(SIGNED(ctx->r16) >> 15);
    // 0x8006AFC8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006AFCC: beq         $t1, $at, L_8006AFE4
    if (ctx->r9 == ctx->r1) {
        // 0x8006AFD0: or          $s0, $t9, $zero
        ctx->r16 = ctx->r25 | 0;
            goto L_8006AFE4;
    }
    // 0x8006AFD0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8006AFD4: multu       $t1, $s0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AFD8: mflo        $s0
    ctx->r16 = lo;
    // 0x8006AFDC: sra         $t2, $s0, 8
    ctx->r10 = S32(SIGNED(ctx->r16) >> 8);
    // 0x8006AFE0: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8006AFE4:
    // 0x8006AFE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006AFE8: jal         0x8005BBFC
    // 0x8006AFEC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_1;
    // 0x8006AFEC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_1:
    // 0x8006AFF0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8006AFF4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006AFF8: lh          $t4, 0xA($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XA);
    // 0x8006AFFC: lh          $a3, 0x8($t3)
    ctx->r7 = MEM_H(ctx->r11, 0X8);
    // 0x8006B000: lw          $a1, -0x450($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X450);
    // 0x8006B004: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006B008: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8006B00C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8006B010: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8006B014: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8006B018: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8006B01C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8006B020: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x8006B024: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006B028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006B02C: jal         0x80057460
    // 0x8006B030: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_2;
    // 0x8006B030: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_2:
    // 0x8006B034: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006B038: jal         0x8005BE40
    // 0x8006B03C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_3;
    // 0x8006B03C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_3:
L_8006B040:
    // 0x8006B040: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006B044: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8006B048: jr          $ra
    // 0x8006B04C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8006B04C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void MultisquareGlow_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B050: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006B054: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006B058: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8006B05C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006B060: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006B064: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8006B068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006B06C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006B070: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8006B074: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8006B078: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x8006B07C: sb          $t8, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r24;
    // 0x8006B080: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8006B084: ori         $t3, $zero, 0x8000
    ctx->r11 = 0 | 0X8000;
    // 0x8006B088: sh          $zero, 0x2($t0)
    MEM_H(0X2, ctx->r8) = 0;
    // 0x8006B08C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8006B090: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8006B094: lbu         $t2, 0x6($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X6);
    // 0x8006B098: nop

    // 0x8006B09C: div         $zero, $t3, $t2
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r10)));
    // 0x8006B0A0: bne         $t2, $zero, L_8006B0AC
    if (ctx->r10 != 0) {
        // 0x8006B0A4: nop
    
            goto L_8006B0AC;
    }
    // 0x8006B0A4: nop

    // 0x8006B0A8: break       7
    do_break(2147922088);
L_8006B0AC:
    // 0x8006B0AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006B0B0: bne         $t2, $at, L_8006B0C4
    if (ctx->r10 != ctx->r1) {
        // 0x8006B0B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006B0C4;
    }
    // 0x8006B0B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006B0B8: bne         $t3, $at, L_8006B0C4
    if (ctx->r11 != ctx->r1) {
        // 0x8006B0BC: nop
    
            goto L_8006B0C4;
    }
    // 0x8006B0BC: nop

    // 0x8006B0C0: break       6
    do_break(2147922112);
L_8006B0C4:
    // 0x8006B0C4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006B0C8: mflo        $t4
    ctx->r12 = lo;
    // 0x8006B0CC: sh          $t4, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r12;
    // 0x8006B0D0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006B0D4: nop

    // 0x8006B0D8: sb          $t5, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r13;
    // 0x8006B0DC: lbu         $s0, 0x33($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X33);
    // 0x8006B0E0: nop

    // 0x8006B0E4: beq         $s0, $at, L_8006B1C0
    if (ctx->r16 == ctx->r1) {
        // 0x8006B0E8: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8006B1C0;
    }
    // 0x8006B0E8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8006B0EC: beq         $s0, $at, L_8006B15C
    if (ctx->r16 == ctx->r1) {
        // 0x8006B0F0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8006B15C;
    }
    // 0x8006B0F0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8006B0F4: bne         $s0, $at, L_8006B224
    if (ctx->r16 != ctx->r1) {
        // 0x8006B0F8: nop
    
            goto L_8006B224;
    }
    // 0x8006B0F8: nop

    // 0x8006B0FC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8006B100: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006B104: sb          $zero, 0x1($t7)
    MEM_B(0X1, ctx->r15) = 0;
    // 0x8006B108: lw          $t8, -0x450($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X450);
    // 0x8006B10C: lh          $t3, 0x2C($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2C);
    // 0x8006B110: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8006B114: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006B118: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    // 0x8006B11C: lhu         $t0, 0x2($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X2);
    // 0x8006B120: addiu       $t4, $t9, -0x2C
    ctx->r12 = ADD32(ctx->r25, -0X2C);
    // 0x8006B124: sra         $t1, $t4, 1
    ctx->r9 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8006B128: sra         $t2, $t3, 2
    ctx->r10 = S32(SIGNED(ctx->r11) >> 2);
    // 0x8006B12C: subu        $t5, $t2, $t1
    ctx->r13 = SUB32(ctx->r10, ctx->r9);
    // 0x8006B130: sh          $t0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r8;
    // 0x8006B134: sh          $t5, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r13;
    // 0x8006B138: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x8006B13C: lh          $t7, 0x2E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2E);
    // 0x8006B140: addiu       $t3, $t0, -0x2C
    ctx->r11 = ADD32(ctx->r8, -0X2C);
    // 0x8006B144: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8006B148: sra         $t9, $t3, 1
    ctx->r25 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8006B14C: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x8006B150: subu        $t4, $t8, $t9
    ctx->r12 = SUB32(ctx->r24, ctx->r25);
    // 0x8006B154: b           L_8006B238
    // 0x8006B158: sh          $t4, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r12;
        goto L_8006B238;
    // 0x8006B158: sh          $t4, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r12;
L_8006B15C:
    // 0x8006B15C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8006B160: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006B164: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B168: sb          $t1, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r9;
    // 0x8006B16C: lw          $t6, -0x450($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X450);
    // 0x8006B170: lh          $t3, 0x2C($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2C);
    // 0x8006B174: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8006B178: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8006B17C: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    // 0x8006B180: lhu         $t0, 0x2($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X2);
    // 0x8006B184: addiu       $t9, $t7, -0x28
    ctx->r25 = ADD32(ctx->r15, -0X28);
    // 0x8006B188: sra         $t4, $t9, 1
    ctx->r12 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8006B18C: sra         $t8, $t3, 2
    ctx->r24 = S32(SIGNED(ctx->r11) >> 2);
    // 0x8006B190: subu        $t2, $t8, $t4
    ctx->r10 = SUB32(ctx->r24, ctx->r12);
    // 0x8006B194: sh          $t0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r8;
    // 0x8006B198: sh          $t2, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r10;
    // 0x8006B19C: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x8006B1A0: lh          $t5, 0x2E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2E);
    // 0x8006B1A4: addiu       $t3, $t0, -0x28
    ctx->r11 = ADD32(ctx->r8, -0X28);
    // 0x8006B1A8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006B1AC: sra         $t7, $t3, 1
    ctx->r15 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8006B1B0: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x8006B1B4: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x8006B1B8: b           L_8006B238
    // 0x8006B1BC: sh          $t9, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r25;
        goto L_8006B238;
    // 0x8006B1BC: sh          $t9, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r25;
L_8006B1C0:
    // 0x8006B1C0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8006B1C4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8006B1C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006B1CC: sb          $t4, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r12;
    // 0x8006B1D0: lw          $t1, -0x450($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X450);
    // 0x8006B1D4: lh          $t3, 0x2C($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2C);
    // 0x8006B1D8: lhu         $t5, 0x0($t1)
    ctx->r13 = MEM_HU(ctx->r9, 0X0);
    // 0x8006B1DC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8006B1E0: sh          $t5, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r13;
    // 0x8006B1E4: lhu         $t0, 0x2($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X2);
    // 0x8006B1E8: addiu       $t7, $t5, -0x20
    ctx->r15 = ADD32(ctx->r13, -0X20);
    // 0x8006B1EC: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8006B1F0: sra         $t6, $t3, 2
    ctx->r14 = S32(SIGNED(ctx->r11) >> 2);
    // 0x8006B1F4: subu        $t8, $t6, $t9
    ctx->r24 = SUB32(ctx->r14, ctx->r25);
    // 0x8006B1F8: sh          $t0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r8;
    // 0x8006B1FC: sh          $t8, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r24;
    // 0x8006B200: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x8006B204: lh          $t2, 0x2E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2E);
    // 0x8006B208: addiu       $t3, $t0, -0x20
    ctx->r11 = ADD32(ctx->r8, -0X20);
    // 0x8006B20C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006B210: sra         $t5, $t3, 1
    ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8006B214: sra         $t1, $t2, 2
    ctx->r9 = S32(SIGNED(ctx->r10) >> 2);
    // 0x8006B218: subu        $t7, $t1, $t5
    ctx->r15 = SUB32(ctx->r9, ctx->r13);
    // 0x8006B21C: b           L_8006B238
    // 0x8006B220: sh          $t7, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r15;
        goto L_8006B238;
    // 0x8006B220: sh          $t7, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r15;
L_8006B224:
    // 0x8006B224: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006B228: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006B22C: addiu       $a1, $a1, -0x28EC
    ctx->r5 = ADD32(ctx->r5, -0X28EC);
    // 0x8006B230: jal         0x80083560
    // 0x8006B234: addiu       $a0, $a0, -0x2910
    ctx->r4 = ADD32(ctx->r4, -0X2910);
    debug_print_reason_routine(rdram, ctx);
        goto after_0;
    // 0x8006B234: addiu       $a0, $a0, -0x2910
    ctx->r4 = ADD32(ctx->r4, -0X2910);
    after_0:
L_8006B238:
    // 0x8006B238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B23C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006B240: jr          $ra
    // 0x8006B244: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006B244: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void MultisquareGlow_InitStaticMembers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B248: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006B24C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006B250: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006B254: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006B258: jal         0x8004A34C
    // 0x8006B25C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    Main_DrainMessageQueue(rdram, ctx);
        goto after_0;
    // 0x8006B25C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006B260: lbu         $s0, 0x2B($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X2B);
    // 0x8006B264: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006B268: beq         $s0, $at, L_8006B290
    if (ctx->r16 == ctx->r1) {
        // 0x8006B26C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006B290;
    }
    // 0x8006B26C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006B270: beq         $s0, $at, L_8006B2D4
    if (ctx->r16 == ctx->r1) {
        // 0x8006B274: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8006B2D4;
    }
    // 0x8006B274: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006B278: beq         $s0, $at, L_8006B318
    if (ctx->r16 == ctx->r1) {
        // 0x8006B27C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8006B318;
    }
    // 0x8006B27C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006B280: beq         $s0, $at, L_8006B318
    if (ctx->r16 == ctx->r1) {
        // 0x8006B284: nop
    
            goto L_8006B318;
    }
    // 0x8006B284: nop

    // 0x8006B288: b           L_8006B35C
    // 0x8006B28C: nop

        goto L_8006B35C;
    // 0x8006B28C: nop

L_8006B290:
    // 0x8006B290: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8006B294: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x8006B298: jal         0x80074888
    // 0x8006B29C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_1;
    // 0x8006B29C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_1:
    // 0x8006B2A0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8006B2A4: jal         0x8007E03C
    // 0x8006B2A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8006B2A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8006B2AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006B2B0: sw          $v0, -0x450($at)
    MEM_W(-0X450, ctx->r1) = ctx->r2;
    // 0x8006B2B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006B2B8: lw          $a1, -0x450($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X450);
    // 0x8006B2BC: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8006B2C0: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x8006B2C4: jal         0x800746C0
    // 0x8006B2C8: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_3;
    // 0x8006B2C8: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    after_3:
    // 0x8006B2CC: b           L_8006B370
    // 0x8006B2D0: nop

        goto L_8006B370;
    // 0x8006B2D0: nop

L_8006B2D4:
    // 0x8006B2D4: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8006B2D8: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x8006B2DC: jal         0x80074888
    // 0x8006B2E0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_4;
    // 0x8006B2E0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_4:
    // 0x8006B2E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8006B2E8: jal         0x8007E03C
    // 0x8006B2EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x8006B2EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8006B2F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006B2F4: sw          $v0, -0x450($at)
    MEM_W(-0X450, ctx->r1) = ctx->r2;
    // 0x8006B2F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006B2FC: lw          $a1, -0x450($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X450);
    // 0x8006B300: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8006B304: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x8006B308: jal         0x800746C0
    // 0x8006B30C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_6;
    // 0x8006B30C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_6:
    // 0x8006B310: b           L_8006B370
    // 0x8006B314: nop

        goto L_8006B370;
    // 0x8006B314: nop

L_8006B318:
    // 0x8006B318: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8006B31C: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x8006B320: jal         0x80074888
    // 0x8006B324: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_7;
    // 0x8006B324: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    after_7:
    // 0x8006B328: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8006B32C: jal         0x8007E03C
    // 0x8006B330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x8006B330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8006B334: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006B338: sw          $v0, -0x450($at)
    MEM_W(-0X450, ctx->r1) = ctx->r2;
    // 0x8006B33C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006B340: lw          $a1, -0x450($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X450);
    // 0x8006B344: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8006B348: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x8006B34C: jal         0x800746C0
    // 0x8006B350: addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_9;
    // 0x8006B350: addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
    after_9:
    // 0x8006B354: b           L_8006B370
    // 0x8006B358: nop

        goto L_8006B370;
    // 0x8006B358: nop

L_8006B35C:
    // 0x8006B35C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006B360: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006B364: addiu       $a1, $a1, -0x28AC
    ctx->r5 = ADD32(ctx->r5, -0X28AC);
    // 0x8006B368: jal         0x80083560
    // 0x8006B36C: addiu       $a0, $a0, -0x28D4
    ctx->r4 = ADD32(ctx->r4, -0X28D4);
    debug_print_reason_routine(rdram, ctx);
        goto after_10;
    // 0x8006B36C: addiu       $a0, $a0, -0x28D4
    ctx->r4 = ADD32(ctx->r4, -0X28D4);
    after_10:
L_8006B370:
    // 0x8006B370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B374: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006B378: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006B37C: jr          $ra
    // 0x8006B380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006B380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void MultisquareGlow_FreeStaticMembers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B388: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006B38C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B390: lw          $a0, -0x450($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X450);
    // 0x8006B394: jal         0x8007E328
    // 0x8006B398: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x8006B398: nop

    after_0:
    // 0x8006B39C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B3A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B3A4: jr          $ra
    // 0x8006B3A8: nop

    return;
    // 0x8006B3A8: nop

    // 0x8006B3AC: nop

;}

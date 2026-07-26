#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void SaveData_ProbeEepromAndAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AF0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003AF10: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8003AF14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8003AF18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003AF1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003AF20: jal         0x800B3460
    // 0x8003AF24: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    osEepromProbe_recomp(rdram, ctx);
        goto after_0;
    // 0x8003AF24: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    after_0:
    // 0x8003AF28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8003AF2C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8003AF30: nop

    // 0x8003AF34: beq         $t6, $zero, L_8003B084
    if (ctx->r14 == 0) {
        // 0x8003AF38: nop
    
            goto L_8003B084;
    }
    // 0x8003AF38: nop

    // 0x8003AF3C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8003AF40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003AF44: beq         $s0, $at, L_8003AF5C
    if (ctx->r16 == ctx->r1) {
        // 0x8003AF48: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003AF5C;
    }
    // 0x8003AF48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003AF4C: beq         $s0, $at, L_8003AF6C
    if (ctx->r16 == ctx->r1) {
        // 0x8003AF50: nop
    
            goto L_8003AF6C;
    }
    // 0x8003AF50: nop

    // 0x8003AF54: b           L_8003AF78
    // 0x8003AF58: nop

        goto L_8003AF78;
    // 0x8003AF58: nop

L_8003AF5C:
    // 0x8003AF5C: addiu       $t7, $zero, 0x200
    ctx->r15 = ADD32(0, 0X200);
    // 0x8003AF60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003AF64: b           L_8003AF78
    // 0x8003AF68: sw          $t7, 0x1F10($at)
    MEM_W(0X1F10, ctx->r1) = ctx->r15;
        goto L_8003AF78;
    // 0x8003AF68: sw          $t7, 0x1F10($at)
    MEM_W(0X1F10, ctx->r1) = ctx->r15;
L_8003AF6C:
    // 0x8003AF6C: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x8003AF70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003AF74: sw          $t8, 0x1F10($at)
    MEM_W(0X1F10, ctx->r1) = ctx->r24;
L_8003AF78:
    // 0x8003AF78: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003AF7C: lw          $a0, 0x1F10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F10);
    // 0x8003AF80: jal         0x8007E03C
    // 0x8003AF84: nop

    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8003AF84: nop

    after_1:
    // 0x8003AF88: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8003AF8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003AF90: sw          $v0, 0x25B0($t9)
    MEM_W(0X25B0, ctx->r25) = ctx->r2;
    // 0x8003AF94: lw          $a0, 0x1F10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F10);
    // 0x8003AF98: nop

    // 0x8003AF9C: bgez        $a0, L_8003AFAC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8003AFA0: sra         $t0, $a0, 3
        ctx->r8 = S32(SIGNED(ctx->r4) >> 3);
            goto L_8003AFAC;
    }
    // 0x8003AFA0: sra         $t0, $a0, 3
    ctx->r8 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8003AFA4: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x8003AFA8: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_8003AFAC:
    // 0x8003AFAC: jal         0x8007E03C
    // 0x8003AFB0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8003AFB0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
    // 0x8003AFB4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8003AFB8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8003AFBC: sw          $v0, 0x25B4($t1)
    MEM_W(0X25B4, ctx->r9) = ctx->r2;
    // 0x8003AFC0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8003AFC4: nop

    // 0x8003AFC8: lhu         $t3, 0x25AE($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X25AE);
    // 0x8003AFCC: nop

    // 0x8003AFD0: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x8003AFD4: sh          $t4, 0x25AE($t2)
    MEM_H(0X25AE, ctx->r10) = ctx->r12;
    // 0x8003AFD8: lw          $t5, 0x1F10($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F10);
    // 0x8003AFDC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8003AFE0: blez        $t5, L_8003B018
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8003AFE4: nop
    
            goto L_8003B018;
    }
    // 0x8003AFE4: nop

L_8003AFE8:
    // 0x8003AFE8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8003AFEC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8003AFF0: lw          $t7, 0x25B0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X25B0);
    // 0x8003AFF4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8003AFF8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8003AFFC: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8003B000: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8003B004: lw          $t3, 0x1F10($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F10);
    // 0x8003B008: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8003B00C: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8003B010: bne         $at, $zero, L_8003AFE8
    if (ctx->r1 != 0) {
        // 0x8003B014: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_8003AFE8;
    }
    // 0x8003B014: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_8003B018:
    // 0x8003B018: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8003B01C: lw          $t4, 0x1F10($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F10);
    // 0x8003B020: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8003B024: bgez        $t4, L_8003B034
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8003B028: sra         $t2, $t4, 3
        ctx->r10 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8003B034;
    }
    // 0x8003B028: sra         $t2, $t4, 3
    ctx->r10 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8003B02C: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8003B030: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_8003B034:
    // 0x8003B034: blez        $t2, L_8003B084
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8003B038: nop
    
            goto L_8003B084;
    }
    // 0x8003B038: nop

L_8003B03C:
    // 0x8003B03C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8003B040: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8003B044: lw          $t6, 0x25B4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X25B4);
    // 0x8003B048: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8003B04C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8003B050: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x8003B054: lw          $t1, 0x1F10($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1F10);
    // 0x8003B058: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8003B05C: nop

    // 0x8003B060: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8003B064: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8003B068: bgez        $t1, L_8003B078
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8003B06C: sra         $t3, $t1, 3
        ctx->r11 = S32(SIGNED(ctx->r9) >> 3);
            goto L_8003B078;
    }
    // 0x8003B06C: sra         $t3, $t1, 3
    ctx->r11 = S32(SIGNED(ctx->r9) >> 3);
    // 0x8003B070: addiu       $at, $t1, 0x7
    ctx->r1 = ADD32(ctx->r9, 0X7);
    // 0x8003B074: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8003B078:
    // 0x8003B078: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8003B07C: bne         $at, $zero, L_8003B03C
    if (ctx->r1 != 0) {
        // 0x8003B080: nop
    
            goto L_8003B03C;
    }
    // 0x8003B080: nop

L_8003B084:
    // 0x8003B084: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8003B088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B08C: lhu         $v0, 0x25AE($t4)
    ctx->r2 = MEM_HU(ctx->r12, 0X25AE);
    // 0x8003B090: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8003B094: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003B098: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x8003B09C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8003B0A0: jr          $ra
    // 0x8003B0A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003B0A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void SaveData_RequestEepromWrite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B0A8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8003B0AC: lw          $t6, 0x1F10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F10);
    // 0x8003B0B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003B0B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B0B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003B0BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003B0C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8003B0C4: bgez        $t6, L_8003B0D4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8003B0C8: sra         $t7, $t6, 3
        ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
            goto L_8003B0D4;
    }
    // 0x8003B0C8: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8003B0CC: addiu       $at, $t6, 0x7
    ctx->r1 = ADD32(ctx->r14, 0X7);
    // 0x8003B0D0: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_8003B0D4:
    // 0x8003B0D4: blez        $t7, L_8003B178
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8003B0D8: nop
    
            goto L_8003B178;
    }
    // 0x8003B0D8: nop

L_8003B0DC:
    // 0x8003B0DC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8003B0E0:
    // 0x8003B0E0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B0E4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B0E8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8003B0EC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8003B0F0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8003B0F4: lw          $t3, 0x25B0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X25B0);
    // 0x8003B0F8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8003B0FC: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x8003B100: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x8003B104: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8003B108: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x8003B10C: nop

    // 0x8003B110: beq         $t5, $t9, L_8003B12C
    if (ctx->r13 == ctx->r25) {
        // 0x8003B114: nop
    
            goto L_8003B12C;
    }
    // 0x8003B114: nop

    // 0x8003B118: lw          $t3, 0x25B4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X25B4);
    // 0x8003B11C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003B120: addu        $t4, $t3, $t8
    ctx->r12 = ADD32(ctx->r11, ctx->r24);
    // 0x8003B124: b           L_8003B144
    // 0x8003B128: sb          $t0, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r8;
        goto L_8003B144;
    // 0x8003B128: sb          $t0, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r8;
L_8003B12C:
    // 0x8003B12C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003B130: nop

    // 0x8003B134: addiu       $t1, $t6, 0x1
    ctx->r9 = ADD32(ctx->r14, 0X1);
    // 0x8003B138: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x8003B13C: bne         $at, $zero, L_8003B0E0
    if (ctx->r1 != 0) {
        // 0x8003B140: sw          $t1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r9;
            goto L_8003B0E0;
    }
    // 0x8003B140: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_8003B144:
    // 0x8003B144: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8003B148: lw          $t9, 0x1F10($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1F10);
    // 0x8003B14C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B150: nop

    // 0x8003B154: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x8003B158: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8003B15C: bgez        $t9, L_8003B16C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8003B160: sra         $t2, $t9, 3
        ctx->r10 = S32(SIGNED(ctx->r25) >> 3);
            goto L_8003B16C;
    }
    // 0x8003B160: sra         $t2, $t9, 3
    ctx->r10 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8003B164: addiu       $at, $t9, 0x7
    ctx->r1 = ADD32(ctx->r25, 0X7);
    // 0x8003B168: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_8003B16C:
    // 0x8003B16C: slt         $at, $t5, $t2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003B170: bne         $at, $zero, L_8003B0DC
    if (ctx->r1 != 0) {
        // 0x8003B174: nop
    
            goto L_8003B0DC;
    }
    // 0x8003B174: nop

L_8003B178:
    // 0x8003B178: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8003B17C: lw          $t3, 0x1F10($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F10);
    // 0x8003B180: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8003B184: blez        $t3, L_8003B1C8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8003B188: nop
    
            goto L_8003B1C8;
    }
    // 0x8003B188: nop

L_8003B18C:
    // 0x8003B18C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8003B190: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B194: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8003B198: addu        $t4, $t8, $t0
    ctx->r12 = ADD32(ctx->r24, ctx->r8);
    // 0x8003B19C: lw          $t7, 0x25B0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X25B0);
    // 0x8003B1A0: lbu         $t6, 0x0($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X0);
    // 0x8003B1A4: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8003B1A8: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x8003B1AC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B1B0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8003B1B4: lw          $t3, 0x1F10($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F10);
    // 0x8003B1B8: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x8003B1BC: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8003B1C0: bne         $at, $zero, L_8003B18C
    if (ctx->r1 != 0) {
        // 0x8003B1C4: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_8003B18C;
    }
    // 0x8003B1C4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_8003B1C8:
    // 0x8003B1C8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8003B1CC: nop

    // 0x8003B1D0: lhu         $t4, 0x25AE($t8)
    ctx->r12 = MEM_HU(ctx->r24, 0X25AE);
    // 0x8003B1D4: nop

    // 0x8003B1D8: andi        $t1, $t4, 0x10
    ctx->r9 = ctx->r12 & 0X10;
    // 0x8003B1DC: beq         $t1, $zero, L_8003B21C
    if (ctx->r9 == 0) {
        // 0x8003B1E0: nop
    
            goto L_8003B21C;
    }
    // 0x8003B1E0: nop

    // 0x8003B1E4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8003B1E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003B1EC: sw          $t7, 0x25BC($t8)
    MEM_W(0X25BC, ctx->r24) = ctx->r15;
    // 0x8003B1F0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8003B1F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003B1F8: sh          $t0, 0x2560($t6)
    MEM_H(0X2560, ctx->r14) = ctx->r8;
    // 0x8003B1FC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8003B200: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B204: sb          $t9, 0x25B9($t5)
    MEM_B(0X25B9, ctx->r13) = ctx->r25;
    // 0x8003B208: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8003B20C: nop

    // 0x8003B210: addiu       $a0, $t2, 0x1C8
    ctx->r4 = ADD32(ctx->r10, 0X1C8);
    // 0x8003B214: jal         0x800B34D0
    // 0x8003B218: addiu       $a1, $t2, 0x2560
    ctx->r5 = ADD32(ctx->r10, 0X2560);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B218: addiu       $a1, $t2, 0x2560
    ctx->r5 = ADD32(ctx->r10, 0X2560);
    after_0:
L_8003B21C:
    // 0x8003B21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B220: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003B224: jr          $ra
    // 0x8003B228: nop

    return;
    // 0x8003B228: nop

;}

RECOMP_FUNC void SaveData_RequestEepromRead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B22C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B234: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003B238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B23C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B240: lhu         $t7, 0x25AE($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X25AE);
    // 0x8003B244: nop

    // 0x8003B248: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8003B24C: beq         $t8, $zero, L_8003B28C
    if (ctx->r24 == 0) {
        // 0x8003B250: nop
    
            goto L_8003B28C;
    }
    // 0x8003B250: nop

    // 0x8003B254: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B258: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8003B25C: sw          $t9, 0x25BC($t6)
    MEM_W(0X25BC, ctx->r14) = ctx->r25;
    // 0x8003B260: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B264: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003B268: sh          $t0, 0x2560($t1)
    MEM_H(0X2560, ctx->r9) = ctx->r8;
    // 0x8003B26C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B270: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B274: sb          $t2, 0x25B8($t3)
    MEM_B(0X25B8, ctx->r11) = ctx->r10;
    // 0x8003B278: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003B27C: nop

    // 0x8003B280: addiu       $a0, $t4, 0x1C8
    ctx->r4 = ADD32(ctx->r12, 0X1C8);
    // 0x8003B284: jal         0x800B34D0
    // 0x8003B288: addiu       $a1, $t4, 0x2560
    ctx->r5 = ADD32(ctx->r12, 0X2560);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B288: addiu       $a1, $t4, 0x2560
    ctx->r5 = ADD32(ctx->r12, 0X2560);
    after_0:
L_8003B28C:
    // 0x8003B28C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B294: jr          $ra
    // 0x8003B298: nop

    return;
    // 0x8003B298: nop

;}

RECOMP_FUNC void FUN_001500_motorInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B29C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003B2A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B2A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003B2A8: sb          $zero, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = 0;
L_8003B2AC:
    // 0x8003B2AC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8003B2B0: lbu         $t8, 0x1B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1B);
    // 0x8003B2B4: lbu         $t7, 0x2360($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2360);
    // 0x8003B2B8: nop

    // 0x8003B2BC: srav        $t9, $t7, $t8
    ctx->r25 = S32(SIGNED(ctx->r15) >> (ctx->r24 & 31));
    // 0x8003B2C0: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8003B2C4: beq         $t0, $zero, L_8003B3B8
    if (ctx->r8 == 0) {
        // 0x8003B2C8: nop
    
            goto L_8003B3B8;
    }
    // 0x8003B2C8: nop

    // 0x8003B2CC: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8003B2D0: addu        $t2, $t6, $t1
    ctx->r10 = ADD32(ctx->r14, ctx->r9);
    // 0x8003B2D4: lhu         $t3, 0x2362($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2362);
    // 0x8003B2D8: nop

    // 0x8003B2DC: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x8003B2E0: sltu        $t5, $zero, $t4
    ctx->r13 = 0 < ctx->r12 ? 1 : 0;
    // 0x8003B2E4: beq         $t5, $zero, L_8003B3B8
    if (ctx->r13 == 0) {
        // 0x8003B2E8: nop
    
            goto L_8003B3B8;
    }
    // 0x8003B2E8: nop

    // 0x8003B2EC: beq         $t5, $zero, L_8003B3B8
    if (ctx->r13 == 0) {
        // 0x8003B2F0: nop
    
            goto L_8003B3B8;
    }
    // 0x8003B2F0: nop

    // 0x8003B2F4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8003B2F8: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8003B2FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8003B300: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8003B304: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8003B308: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8003B30C: addiu       $a1, $a1, 0x238C
    ctx->r5 = ADD32(ctx->r5, 0X238C);
    // 0x8003B310: addiu       $a0, $t6, 0x258
    ctx->r4 = ADD32(ctx->r14, 0X258);
    // 0x8003B314: jal         0x800B3620
    // 0x8003B318: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    osPfsInitPak_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B318: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_0:
    // 0x8003B31C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8003B320: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B324: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003B328: beq         $t9, $at, L_8003B338
    if (ctx->r25 == ctx->r1) {
        // 0x8003B32C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8003B338;
    }
    // 0x8003B32C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8003B330: bne         $t9, $at, L_8003B3B8
    if (ctx->r25 != ctx->r1) {
        // 0x8003B334: nop
    
            goto L_8003B3B8;
    }
    // 0x8003B334: nop

L_8003B338:
    // 0x8003B338: lbu         $t1, 0x1B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1B);
    // 0x8003B33C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8003B340: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8003B344: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8003B348: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8003B34C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8003B350: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8003B354: addu        $a1, $t0, $t2
    ctx->r5 = ADD32(ctx->r8, ctx->r10);
    // 0x8003B358: addiu       $a1, $a1, 0x238C
    ctx->r5 = ADD32(ctx->r5, 0X238C);
    // 0x8003B35C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8003B360: jal         0x800B3A84
    // 0x8003B364: addiu       $a0, $t0, 0x258
    ctx->r4 = ADD32(ctx->r8, 0X258);
    osMotorInit_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B364: addiu       $a0, $t0, 0x258
    ctx->r4 = ADD32(ctx->r8, 0X258);
    after_1:
    // 0x8003B368: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8003B36C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B370: nop

    // 0x8003B374: bne         $t3, $zero, L_8003B3B8
    if (ctx->r11 != 0) {
        // 0x8003B378: nop
    
            goto L_8003B3B8;
    }
    // 0x8003B378: nop

    // 0x8003B37C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8003B380: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x8003B384: lhu         $t5, 0x25AE($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X25AE);
    // 0x8003B388: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003B38C: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8003B390: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x8003B394: sh          $t9, 0x25AE($t4)
    MEM_H(0X25AE, ctx->r12) = ctx->r25;
    // 0x8003B398: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8003B39C: lbu         $a1, 0x1B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1B);
    // 0x8003B3A0: lhu         $a2, 0x25AE($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X25AE);
    // 0x8003B3A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003B3A8: andi        $t2, $a2, 0xF
    ctx->r10 = ctx->r6 & 0XF;
    // 0x8003B3AC: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x8003B3B0: jal         0x800B3BFC
    // 0x8003B3B4: addiu       $a0, $a0, -0x4C60
    ctx->r4 = ADD32(ctx->r4, -0X4C60);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003B3B4: addiu       $a0, $a0, -0x4C60
    ctx->r4 = ADD32(ctx->r4, -0X4C60);
    after_2:
L_8003B3B8:
    // 0x8003B3B8: lbu         $t1, 0x1B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1B);
    // 0x8003B3BC: nop

    // 0x8003B3C0: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8003B3C4: andi        $t7, $t3, 0xFF
    ctx->r15 = ctx->r11 & 0XFF;
    // 0x8003B3C8: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8003B3CC: bne         $at, $zero, L_8003B2AC
    if (ctx->r1 != 0) {
        // 0x8003B3D0: sb          $t3, 0x1B($sp)
        MEM_B(0X1B, ctx->r29) = ctx->r11;
            goto L_8003B2AC;
    }
    // 0x8003B3D0: sb          $t3, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r11;
    // 0x8003B3D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B3D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003B3DC: jr          $ra
    // 0x8003B3E0: nop

    return;
    // 0x8003B3E0: nop

;}

RECOMP_FUNC void SaveData_LoadOrInitBlock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BA84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007BA88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007BA8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007BA90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007BA94: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BA98: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8007BA9C: jal         0x8003B22C
    // 0x8007BAA0: nop

    SaveData_RequestEepromRead(rdram, ctx);
        goto after_0;
    // 0x8007BAA0: nop

    after_0:
    // 0x8007BAA4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BAA8: nop

    // 0x8007BAAC: lbu         $t7, 0x25B8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X25B8);
    // 0x8007BAB0: nop

    // 0x8007BAB4: beq         $t7, $zero, L_8007BAD4
    if (ctx->r15 == 0) {
        // 0x8007BAB8: nop
    
            goto L_8007BAD4;
    }
    // 0x8007BAB8: nop

L_8007BABC:
    // 0x8007BABC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BAC0: nop

    // 0x8007BAC4: lbu         $t9, 0x25B8($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X25B8);
    // 0x8007BAC8: nop

    // 0x8007BACC: bne         $t9, $zero, L_8007BABC
    if (ctx->r25 != 0) {
        // 0x8007BAD0: nop
    
            goto L_8007BABC;
    }
    // 0x8007BAD0: nop

L_8007BAD4:
    // 0x8007BAD4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8007BAD8: lw          $t0, 0x1F10($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F10);
    // 0x8007BADC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8007BAE0: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8007BAE4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8007BAE8: lbu         $t3, -0x2($t2)
    ctx->r11 = MEM_BU(ctx->r10, -0X2);
    // 0x8007BAEC: nop

    // 0x8007BAF0: beq         $t3, $at, L_8007BB04
    if (ctx->r11 == ctx->r1) {
        // 0x8007BAF4: nop
    
            goto L_8007BB04;
    }
    // 0x8007BAF4: nop

    // 0x8007BAF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BAFC: jal         0x8007BB54
    // 0x8007BB00: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    SaveData_InitBlock(rdram, ctx);
        goto after_1;
    // 0x8007BB00: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_1:
L_8007BB04:
    // 0x8007BB04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BB08: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8007BB0C: jal         0x8003B0A8
    // 0x8007BB10: nop

    SaveData_RequestEepromWrite(rdram, ctx);
        goto after_2;
    // 0x8007BB10: nop

    after_2:
    // 0x8007BB14: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BB18: nop

    // 0x8007BB1C: lbu         $t5, 0x25B9($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X25B9);
    // 0x8007BB20: nop

    // 0x8007BB24: beq         $t5, $zero, L_8007BB44
    if (ctx->r13 == 0) {
        // 0x8007BB28: nop
    
            goto L_8007BB44;
    }
    // 0x8007BB28: nop

L_8007BB2C:
    // 0x8007BB2C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BB30: nop

    // 0x8007BB34: lbu         $t7, 0x25B9($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X25B9);
    // 0x8007BB38: nop

    // 0x8007BB3C: bne         $t7, $zero, L_8007BB2C
    if (ctx->r15 != 0) {
        // 0x8007BB40: nop
    
            goto L_8007BB2C;
    }
    // 0x8007BB40: nop

L_8007BB44:
    // 0x8007BB44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007BB48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007BB4C: jr          $ra
    // 0x8007BB50: nop

    return;
    // 0x8007BB50: nop

;}

RECOMP_FUNC void SaveData_InitBlock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BB54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007BB58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007BB5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007BB60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BB64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007BB68: lw          $a1, 0x1F10($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1F10);
    // 0x8007BB6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BB70: jal         0x800B7450
    // 0x8007BB74: nop

    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x8007BB74: nop

    after_0:
    // 0x8007BB78: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007BB7C: lw          $t6, 0x1F10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F10);
    // 0x8007BB80: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8007BB84: blez        $t6, L_8007BBC0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8007BB88: nop
    
            goto L_8007BBC0;
    }
    // 0x8007BB88: nop

L_8007BB8C:
    // 0x8007BB8C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8007BB90: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BB94: lw          $t9, 0x25B0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X25B0);
    // 0x8007BB98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007BB9C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8007BBA0: sb          $t7, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r15;
    // 0x8007BBA4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BBA8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007BBAC: lw          $t4, 0x1F10($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F10);
    // 0x8007BBB0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007BBB4: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8007BBB8: bne         $at, $zero, L_8007BB8C
    if (ctx->r1 != 0) {
        // 0x8007BBBC: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_8007BB8C;
    }
    // 0x8007BBBC: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
L_8007BBC0:
    // 0x8007BBC0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007BBC4: lw          $t8, 0x1F10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F10);
    // 0x8007BBC8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007BBCC: addiu       $t5, $zero, 0x69
    ctx->r13 = ADD32(0, 0X69);
    // 0x8007BBD0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8007BBD4: sb          $t5, -0x2($t9)
    MEM_B(-0X2, ctx->r25) = ctx->r13;
    // 0x8007BBD8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007BBDC: lw          $t7, 0x1F10($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F10);
    // 0x8007BBE0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8007BBE4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8007BBE8: addu        $t1, $t0, $t7
    ctx->r9 = ADD32(ctx->r8, ctx->r15);
    // 0x8007BBEC: sb          $zero, -0x1($t1)
    MEM_B(-0X1, ctx->r9) = 0;
    // 0x8007BBF0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007BBF4: lw          $t3, 0x1F10($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F10);
    // 0x8007BBF8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007BBFC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8007BC00: sb          $zero, -0x3($t4)
    MEM_B(-0X3, ctx->r12) = 0;
    // 0x8007BC04: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007BC08: lw          $t8, 0x1F10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F10);
    // 0x8007BC0C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8007BC10: addu        $t5, $t6, $t8
    ctx->r13 = ADD32(ctx->r14, ctx->r24);
    // 0x8007BC14: sb          $zero, -0x4($t5)
    MEM_B(-0X4, ctx->r13) = 0;
    // 0x8007BC18: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8007BC1C: lw          $t0, 0x1F10($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F10);
    // 0x8007BC20: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007BC24: addu        $t7, $t9, $t0
    ctx->r15 = ADD32(ctx->r25, ctx->r8);
    // 0x8007BC28: sb          $zero, -0x5($t7)
    MEM_B(-0X5, ctx->r15) = 0;
    // 0x8007BC2C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007BC30: lw          $t2, 0x1F10($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1F10);
    // 0x8007BC34: nop

    // 0x8007BC38: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8007BC3C: sb          $zero, -0x6($t3)
    MEM_B(-0X6, ctx->r11) = 0;
    // 0x8007BC40: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8007BC44: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8007BC48: jal         0x8003B0A8
    // 0x8007BC4C: nop

    SaveData_RequestEepromWrite(rdram, ctx);
        goto after_1;
    // 0x8007BC4C: nop

    after_1:
    // 0x8007BC50: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007BC54: nop

    // 0x8007BC58: lbu         $t6, 0x25B9($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X25B9);
    // 0x8007BC5C: nop

    // 0x8007BC60: beq         $t6, $zero, L_8007BC80
    if (ctx->r14 == 0) {
        // 0x8007BC64: nop
    
            goto L_8007BC80;
    }
    // 0x8007BC64: nop

L_8007BC68:
    // 0x8007BC68: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8007BC6C: nop

    // 0x8007BC70: lbu         $t5, 0x25B9($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X25B9);
    // 0x8007BC74: nop

    // 0x8007BC78: bne         $t5, $zero, L_8007BC68
    if (ctx->r13 != 0) {
        // 0x8007BC7C: nop
    
            goto L_8007BC68;
    }
    // 0x8007BC7C: nop

L_8007BC80:
    // 0x8007BC80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007BC84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007BC88: jr          $ra
    // 0x8007BC8C: nop

    return;
    // 0x8007BC8C: nop

;}

RECOMP_FUNC void SaveData_SetTotalWonderLines(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BC90: lui         $at, 0xAAAA
    ctx->r1 = S32(0XAAAA << 16);
    // 0x8007BC94: ori         $at, $at, 0xAAAA
    ctx->r1 = ctx->r1 | 0XAAAA;
    // 0x8007BC98: and         $t6, $a1, $at
    ctx->r14 = ctx->r5 & ctx->r1;
    // 0x8007BC9C: lui         $at, 0x5555
    ctx->r1 = S32(0X5555 << 16);
    // 0x8007BCA0: ori         $at, $at, 0x5555
    ctx->r1 = ctx->r1 | 0X5555;
    // 0x8007BCA4: and         $t7, $a1, $at
    ctx->r15 = ctx->r5 & ctx->r1;
    // 0x8007BCA8: sw          $t6, 0xF04($a0)
    MEM_W(0XF04, ctx->r4) = ctx->r14;
    // 0x8007BCAC: jr          $ra
    // 0x8007BCB0: sw          $t7, 0xF08($a0)
    MEM_W(0XF08, ctx->r4) = ctx->r15;
    return;
    // 0x8007BCB0: sw          $t7, 0xF08($a0)
    MEM_W(0XF08, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void SaveData_GetTotalWonderLines(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BCB4: lw          $t6, 0xF04($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF04);
    // 0x8007BCB8: lw          $t7, 0xF08($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XF08);
    // 0x8007BCBC: jr          $ra
    // 0x8007BCC0: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    return;
    // 0x8007BCC0: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
;}

RECOMP_FUNC void SaveData_ComputeChecksum32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BCC4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007BCC8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x8007BCCC: beq         $a1, $zero, L_8007BD3C
    if (ctx->r5 == 0) {
        // 0x8007BCD0: sw          $zero, 0x0($sp)
        MEM_W(0X0, ctx->r29) = 0;
            goto L_8007BD3C;
    }
    // 0x8007BCD0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8007BCD4:
    // 0x8007BCD4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8007BCD8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007BCDC: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8007BCE0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8007BCE4: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x8007BCE8: xori        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 ^ 0X10;
    // 0x8007BCEC: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x8007BCF0: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8007BCF4: lbu         $t3, 0x2($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X2);
    // 0x8007BCF8: addu        $t5, $a0, $t7
    ctx->r13 = ADD32(ctx->r4, ctx->r15);
    // 0x8007BCFC: subu        $t4, $t1, $t3
    ctx->r12 = SUB32(ctx->r9, ctx->r11);
    // 0x8007BD00: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8007BD04: lbu         $t8, 0x1($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X1);
    // 0x8007BD08: addu        $t0, $a0, $t7
    ctx->r8 = ADD32(ctx->r4, ctx->r15);
    // 0x8007BD0C: xori        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 ^ 0X20;
    // 0x8007BD10: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8007BD14: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8007BD18: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8007BD1C: lbu         $t2, 0x3($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X3);
    // 0x8007BD20: addiu       $t8, $t5, 0x4
    ctx->r24 = ADD32(ctx->r13, 0X4);
    // 0x8007BD24: sll         $t1, $t2, 1
    ctx->r9 = S32(ctx->r10 << 1);
    // 0x8007BD28: sltu        $at, $t8, $a1
    ctx->r1 = ctx->r24 < ctx->r5 ? 1 : 0;
    // 0x8007BD2C: subu        $t3, $t6, $t1
    ctx->r11 = SUB32(ctx->r14, ctx->r9);
    // 0x8007BD30: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8007BD34: bne         $at, $zero, L_8007BCD4
    if (ctx->r1 != 0) {
        // 0x8007BD38: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_8007BCD4;
    }
    // 0x8007BD38: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_8007BD3C:
    // 0x8007BD3C: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8007BD40: jr          $ra
    // 0x8007BD44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007BD44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void SaveData_ComputeChecksum16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BD48: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007BD4C: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x8007BD50: beq         $a1, $zero, L_8007BDCC
    if (ctx->r5 == 0) {
        // 0x8007BD54: sw          $zero, 0x0($sp)
        MEM_W(0X0, ctx->r29) = 0;
            goto L_8007BDCC;
    }
    // 0x8007BD54: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8007BD58:
    // 0x8007BD58: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8007BD5C: lhu         $t6, 0x6($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X6);
    // 0x8007BD60: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8007BD64: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8007BD68: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x8007BD6C: xori        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 ^ 0X10;
    // 0x8007BD70: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x8007BD74: sh          $t1, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r9;
    // 0x8007BD78: lbu         $t3, 0x2($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X2);
    // 0x8007BD7C: andi        $t4, $t1, 0xFFFF
    ctx->r12 = ctx->r9 & 0XFFFF;
    // 0x8007BD80: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x8007BD84: sh          $t5, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r13;
    // 0x8007BD88: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8007BD8C: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x8007BD90: andi        $t0, $t5, 0xFFFF
    ctx->r8 = ctx->r13 & 0XFFFF;
    // 0x8007BD94: xori        $t6, $t9, 0x20
    ctx->r14 = ctx->r25 ^ 0X20;
    // 0x8007BD98: addu        $t2, $t0, $t6
    ctx->r10 = ADD32(ctx->r8, ctx->r14);
    // 0x8007BD9C: sh          $t2, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r10;
    // 0x8007BDA0: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x8007BDA4: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8007BDA8: lbu         $t4, 0x3($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X3);
    // 0x8007BDAC: andi        $t8, $t2, 0xFFFF
    ctx->r24 = ctx->r10 & 0XFFFF;
    // 0x8007BDB0: addiu       $t0, $t5, 0x4
    ctx->r8 = ADD32(ctx->r13, 0X4);
    // 0x8007BDB4: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x8007BDB8: sltu        $at, $t0, $a1
    ctx->r1 = ctx->r8 < ctx->r5 ? 1 : 0;
    // 0x8007BDBC: addu        $t9, $t8, $t3
    ctx->r25 = ADD32(ctx->r24, ctx->r11);
    // 0x8007BDC0: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x8007BDC4: bne         $at, $zero, L_8007BD58
    if (ctx->r1 != 0) {
        // 0x8007BDC8: sh          $t9, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r25;
            goto L_8007BD58;
    }
    // 0x8007BDC8: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
L_8007BDCC:
    // 0x8007BDCC: lhu         $v0, 0x6($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X6);
    // 0x8007BDD0: jr          $ra
    // 0x8007BDD4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007BDD4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void SaveData_InitDefaultScores(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BDD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007BDDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007BDE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BDE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007BDE8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BDEC: addiu       $a1, $a1, -0x21A0
    ctx->r5 = ADD32(ctx->r5, -0X21A0);
    // 0x8007BDF0: jal         0x800B62D4
    // 0x8007BDF4: addiu       $a0, $a0, 0xF0C
    ctx->r4 = ADD32(ctx->r4, 0XF0C);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007BDF4: addiu       $a0, $a0, 0xF0C
    ctx->r4 = ADD32(ctx->r4, 0XF0C);
    after_0:
    // 0x8007BDF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BDFC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BE00: addiu       $a1, $a1, -0x2198
    ctx->r5 = ADD32(ctx->r5, -0X2198);
    // 0x8007BE04: jal         0x800B62D4
    // 0x8007BE08: addiu       $a0, $a0, 0xF24
    ctx->r4 = ADD32(ctx->r4, 0XF24);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007BE08: addiu       $a0, $a0, 0xF24
    ctx->r4 = ADD32(ctx->r4, 0XF24);
    after_1:
    // 0x8007BE0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BE10: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BE14: addiu       $a1, $a1, -0x2190
    ctx->r5 = ADD32(ctx->r5, -0X2190);
    // 0x8007BE18: jal         0x800B62D4
    // 0x8007BE1C: addiu       $a0, $a0, 0xF3C
    ctx->r4 = ADD32(ctx->r4, 0XF3C);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007BE1C: addiu       $a0, $a0, 0xF3C
    ctx->r4 = ADD32(ctx->r4, 0XF3C);
    after_2:
    // 0x8007BE20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BE24: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BE28: addiu       $a1, $a1, -0x2188
    ctx->r5 = ADD32(ctx->r5, -0X2188);
    // 0x8007BE2C: jal         0x800B62D4
    // 0x8007BE30: addiu       $a0, $a0, 0xF54
    ctx->r4 = ADD32(ctx->r4, 0XF54);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8007BE30: addiu       $a0, $a0, 0xF54
    ctx->r4 = ADD32(ctx->r4, 0XF54);
    after_3:
    // 0x8007BE34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BE38: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BE3C: addiu       $a1, $a1, -0x2180
    ctx->r5 = ADD32(ctx->r5, -0X2180);
    // 0x8007BE40: jal         0x800B62D4
    // 0x8007BE44: addiu       $a0, $a0, 0xF6C
    ctx->r4 = ADD32(ctx->r4, 0XF6C);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x8007BE44: addiu       $a0, $a0, 0xF6C
    ctx->r4 = ADD32(ctx->r4, 0XF6C);
    after_4:
    // 0x8007BE48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BE4C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BE50: addiu       $a1, $a1, -0x2178
    ctx->r5 = ADD32(ctx->r5, -0X2178);
    // 0x8007BE54: jal         0x800B62D4
    // 0x8007BE58: addiu       $a0, $a0, 0xF84
    ctx->r4 = ADD32(ctx->r4, 0XF84);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x8007BE58: addiu       $a0, $a0, 0xF84
    ctx->r4 = ADD32(ctx->r4, 0XF84);
    after_5:
    // 0x8007BE5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BE60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BE64: addiu       $a1, $a1, -0x2170
    ctx->r5 = ADD32(ctx->r5, -0X2170);
    // 0x8007BE68: jal         0x800B62D4
    // 0x8007BE6C: addiu       $a0, $a0, 0xF9C
    ctx->r4 = ADD32(ctx->r4, 0XF9C);
    sprintf_recomp(rdram, ctx);
        goto after_6;
    // 0x8007BE6C: addiu       $a0, $a0, 0xF9C
    ctx->r4 = ADD32(ctx->r4, 0XF9C);
    after_6:
    // 0x8007BE70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BE74: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BE78: addiu       $a1, $a1, -0x2168
    ctx->r5 = ADD32(ctx->r5, -0X2168);
    // 0x8007BE7C: jal         0x800B62D4
    // 0x8007BE80: addiu       $a0, $a0, 0xFB4
    ctx->r4 = ADD32(ctx->r4, 0XFB4);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x8007BE80: addiu       $a0, $a0, 0xFB4
    ctx->r4 = ADD32(ctx->r4, 0XFB4);
    after_7:
    // 0x8007BE84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BE88: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BE8C: addiu       $a1, $a1, -0x215C
    ctx->r5 = ADD32(ctx->r5, -0X215C);
    // 0x8007BE90: jal         0x800B62D4
    // 0x8007BE94: addiu       $a0, $a0, 0xFCC
    ctx->r4 = ADD32(ctx->r4, 0XFCC);
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x8007BE94: addiu       $a0, $a0, 0xFCC
    ctx->r4 = ADD32(ctx->r4, 0XFCC);
    after_8:
    // 0x8007BE98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BE9C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BEA0: addiu       $a1, $a1, -0x2150
    ctx->r5 = ADD32(ctx->r5, -0X2150);
    // 0x8007BEA4: jal         0x800B62D4
    // 0x8007BEA8: addiu       $a0, $a0, 0xFE4
    ctx->r4 = ADD32(ctx->r4, 0XFE4);
    sprintf_recomp(rdram, ctx);
        goto after_9;
    // 0x8007BEA8: addiu       $a0, $a0, 0xFE4
    ctx->r4 = ADD32(ctx->r4, 0XFE4);
    after_9:
    // 0x8007BEAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BEB0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BEB4: addiu       $a1, $a1, -0x2148
    ctx->r5 = ADD32(ctx->r5, -0X2148);
    // 0x8007BEB8: jal         0x800B62D4
    // 0x8007BEBC: addiu       $a0, $a0, 0xFFC
    ctx->r4 = ADD32(ctx->r4, 0XFFC);
    sprintf_recomp(rdram, ctx);
        goto after_10;
    // 0x8007BEBC: addiu       $a0, $a0, 0xFFC
    ctx->r4 = ADD32(ctx->r4, 0XFFC);
    after_10:
    // 0x8007BEC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BEC4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BEC8: addiu       $a1, $a1, -0x2140
    ctx->r5 = ADD32(ctx->r5, -0X2140);
    // 0x8007BECC: jal         0x800B62D4
    // 0x8007BED0: addiu       $a0, $a0, 0x1014
    ctx->r4 = ADD32(ctx->r4, 0X1014);
    sprintf_recomp(rdram, ctx);
        goto after_11;
    // 0x8007BED0: addiu       $a0, $a0, 0x1014
    ctx->r4 = ADD32(ctx->r4, 0X1014);
    after_11:
    // 0x8007BED4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BED8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BEDC: addiu       $a1, $a1, -0x2138
    ctx->r5 = ADD32(ctx->r5, -0X2138);
    // 0x8007BEE0: jal         0x800B62D4
    // 0x8007BEE4: addiu       $a0, $a0, 0x102C
    ctx->r4 = ADD32(ctx->r4, 0X102C);
    sprintf_recomp(rdram, ctx);
        goto after_12;
    // 0x8007BEE4: addiu       $a0, $a0, 0x102C
    ctx->r4 = ADD32(ctx->r4, 0X102C);
    after_12:
    // 0x8007BEE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BEEC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BEF0: addiu       $a1, $a1, -0x2130
    ctx->r5 = ADD32(ctx->r5, -0X2130);
    // 0x8007BEF4: jal         0x800B62D4
    // 0x8007BEF8: addiu       $a0, $a0, 0x1044
    ctx->r4 = ADD32(ctx->r4, 0X1044);
    sprintf_recomp(rdram, ctx);
        goto after_13;
    // 0x8007BEF8: addiu       $a0, $a0, 0x1044
    ctx->r4 = ADD32(ctx->r4, 0X1044);
    after_13:
    // 0x8007BEFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007BF00: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007BF04: addiu       $a1, $a1, -0x2128
    ctx->r5 = ADD32(ctx->r5, -0X2128);
    // 0x8007BF08: jal         0x800B62D4
    // 0x8007BF0C: addiu       $a0, $a0, 0x105C
    ctx->r4 = ADD32(ctx->r4, 0X105C);
    sprintf_recomp(rdram, ctx);
        goto after_14;
    // 0x8007BF0C: addiu       $a0, $a0, 0x105C
    ctx->r4 = ADD32(ctx->r4, 0X105C);
    after_14:
    // 0x8007BF10: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8007BF14:
    // 0x8007BF14: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BF18: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007BF1C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007BF20: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8007BF24: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8007BF28: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8007BF2C: sb          $zero, 0xF16($t9)
    MEM_B(0XF16, ctx->r25) = 0;
    // 0x8007BF30: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BF34: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8007BF38: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8007BF3C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8007BF40: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8007BF44: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8007BF48: sb          $zero, 0xF17($t3)
    MEM_B(0XF17, ctx->r11) = 0;
    // 0x8007BF4C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BF50: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8007BF54: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8007BF58: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8007BF5C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007BF60: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x8007BF64: sb          $zero, 0xF8E($t6)
    MEM_B(0XF8E, ctx->r14) = 0;
    // 0x8007BF68: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BF6C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8007BF70: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8007BF74: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8007BF78: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8007BF7C: addu        $t0, $t8, $t1
    ctx->r8 = ADD32(ctx->r24, ctx->r9);
    // 0x8007BF80: sb          $zero, 0xF8F($t0)
    MEM_B(0XF8F, ctx->r8) = 0;
    // 0x8007BF84: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BF88: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007BF8C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8007BF90: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x8007BF94: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8007BF98: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x8007BF9C: sb          $zero, 0x1006($t4)
    MEM_B(0X1006, ctx->r12) = 0;
    // 0x8007BFA0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BFA4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8007BFA8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8007BFAC: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x8007BFB0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8007BFB4: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8007BFB8: sb          $zero, 0x1007($t8)
    MEM_B(0X1007, ctx->r24) = 0;
    // 0x8007BFBC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BFC0: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8007BFC4: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x8007BFC8: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x8007BFCC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007BFD0: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x8007BFD4: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x8007BFD8: lw          $t3, 0x2FC4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2FC4);
    // 0x8007BFDC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8007BFE0: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x8007BFE4: sw          $t3, 0xF18($t4)
    MEM_W(0XF18, ctx->r12) = ctx->r11;
    // 0x8007BFE8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BFEC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8007BFF0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007BFF4: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8007BFF8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8007BFFC: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8007C000: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x8007C004: lw          $t9, 0x2FD8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2FD8);
    // 0x8007C008: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8007C00C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8007C010: sw          $t9, 0xF90($t1)
    MEM_W(0XF90, ctx->r9) = ctx->r25;
    // 0x8007C014: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C018: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8007C01C: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8007C020: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8007C024: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8007C028: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x8007C02C: subu        $t7, $t7, $t2
    ctx->r15 = SUB32(ctx->r15, ctx->r10);
    // 0x8007C030: lw          $t3, 0x2FEC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2FEC);
    // 0x8007C034: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007C038: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x8007C03C: sw          $t3, 0x1008($t6)
    MEM_W(0X1008, ctx->r14) = ctx->r11;
    // 0x8007C040: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C044: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8007C048: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8007C04C: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8007C050: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007C054: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8007C058: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x8007C05C: lw          $t9, 0x3000($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3000);
    // 0x8007C060: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8007C064: addu        $t2, $t1, $t5
    ctx->r10 = ADD32(ctx->r9, ctx->r13);
    // 0x8007C068: sw          $t9, 0xF1C($t2)
    MEM_W(0XF1C, ctx->r10) = ctx->r25;
    // 0x8007C06C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C070: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8007C074: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8007C078: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x8007C07C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007C080: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x8007C084: subu        $t0, $t0, $t4
    ctx->r8 = SUB32(ctx->r8, ctx->r12);
    // 0x8007C088: lw          $t3, 0x3014($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3014);
    // 0x8007C08C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8007C090: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x8007C094: sw          $t3, 0xF94($t8)
    MEM_W(0XF94, ctx->r24) = ctx->r11;
    // 0x8007C098: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C09C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8007C0A0: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x8007C0A4: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8007C0A8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007C0AC: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8007C0B0: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x8007C0B4: lw          $t9, 0x3028($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3028);
    // 0x8007C0B8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007C0BC: addu        $t4, $t2, $t7
    ctx->r12 = ADD32(ctx->r10, ctx->r15);
    // 0x8007C0C0: sw          $t9, 0x100C($t4)
    MEM_W(0X100C, ctx->r12) = ctx->r25;
    // 0x8007C0C4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C0C8: nop

    // 0x8007C0CC: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8007C0D0: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x8007C0D4: bne         $at, $zero, L_8007BF14
    if (ctx->r1 != 0) {
        // 0x8007C0D8: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_8007BF14;
    }
    // 0x8007C0D8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8007C0DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C0E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007C0E4: jr          $ra
    // 0x8007C0E8: nop

    return;
    // 0x8007C0E8: nop

;}

RECOMP_FUNC void SaveData_Load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C0EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007C0F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007C0F4: lbu         $t6, 0x33($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X33);
    // 0x8007C0F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C0FC: bne         $t6, $zero, L_8007C130
    if (ctx->r14 != 0) {
        // 0x8007C100: nop
    
            goto L_8007C130;
    }
    // 0x8007C100: nop

    // 0x8007C104: jal         0x8007E03C
    // 0x8007C108: addiu       $a0, $zero, 0x1900
    ctx->r4 = ADD32(0, 0X1900);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8007C108: addiu       $a0, $zero, 0x1900
    ctx->r4 = ADD32(0, 0X1900);
    after_0:
    // 0x8007C10C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C110: sw          $v0, -0x310($at)
    MEM_W(-0X310, ctx->r1) = ctx->r2;
    // 0x8007C114: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007C118: lw          $t7, -0x310($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X310);
    // 0x8007C11C: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007C120: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    // 0x8007C124: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007C128: jal         0x800AC1A8
    // 0x8007C12C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    SaveData_SramRead(rdram, ctx);
        goto after_1;
    // 0x8007C12C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
L_8007C130:
    // 0x8007C130: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007C134: lw          $t8, -0x310($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X310);
    // 0x8007C138: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007C13C: addiu       $a1, $a1, -0x2120
    ctx->r5 = ADD32(ctx->r5, -0X2120);
    // 0x8007C140: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007C144: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007C148: jal         0x800B80B0
    // 0x8007C14C: addiu       $a0, $t8, 0x18F8
    ctx->r4 = ADD32(ctx->r24, 0X18F8);
    bcmp_recomp(rdram, ctx);
        goto after_2;
    // 0x8007C14C: addiu       $a0, $t8, 0x18F8
    ctx->r4 = ADD32(ctx->r24, 0X18F8);
    after_2:
    // 0x8007C150: bne         $v0, $zero, L_8007C168
    if (ctx->r2 != 0) {
        // 0x8007C154: nop
    
            goto L_8007C168;
    }
    // 0x8007C154: nop

    // 0x8007C158: lbu         $t9, 0x33($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X33);
    // 0x8007C15C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007C160: bne         $t9, $at, L_8007C2DC
    if (ctx->r25 != ctx->r1) {
        // 0x8007C164: nop
    
            goto L_8007C2DC;
    }
    // 0x8007C164: nop

L_8007C168:
    // 0x8007C168: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C16C: jal         0x800B7450
    // 0x8007C170: addiu       $a1, $zero, 0x1900
    ctx->r5 = ADD32(0, 0X1900);
    bzero_recomp(rdram, ctx);
        goto after_3;
    // 0x8007C170: addiu       $a1, $zero, 0x1900
    ctx->r5 = ADD32(0, 0X1900);
    after_3:
    // 0x8007C174: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C178: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x8007C17C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8007C180: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C184: addiu       $t3, $zero, 0x2E
    ctx->r11 = ADD32(0, 0X2E);
    // 0x8007C188: sb          $t1, 0x18F8($t2)
    MEM_B(0X18F8, ctx->r10) = ctx->r9;
    // 0x8007C18C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C190: addiu       $t5, $zero, 0x30
    ctx->r13 = ADD32(0, 0X30);
    // 0x8007C194: sb          $t3, 0x18F9($t4)
    MEM_B(0X18F9, ctx->r12) = ctx->r11;
    // 0x8007C198: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C19C: addiu       $t7, $zero, 0x62
    ctx->r15 = ADD32(0, 0X62);
    // 0x8007C1A0: sb          $t5, 0x18FA($t6)
    MEM_B(0X18FA, ctx->r14) = ctx->r13;
    // 0x8007C1A4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C1A8: addiu       $t9, $zero, 0x5B68
    ctx->r25 = ADD32(0, 0X5B68);
    // 0x8007C1AC: sb          $t7, 0x18FB($t8)
    MEM_B(0X18FB, ctx->r24) = ctx->r15;
    // 0x8007C1B0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C1B4: addiu       $t1, $zero, 0x7000
    ctx->r9 = ADD32(0, 0X7000);
    // 0x8007C1B8: sw          $t9, 0x18E4($t0)
    MEM_W(0X18E4, ctx->r8) = ctx->r25;
    // 0x8007C1BC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C1C0: nop

    // 0x8007C1C4: sw          $t1, 0x18E8($t2)
    MEM_W(0X18E8, ctx->r10) = ctx->r9;
    // 0x8007C1C8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C1CC: jal         0x800B6550
    // 0x8007C1D0: sw          $zero, 0x18EC($t3)
    MEM_W(0X18EC, ctx->r11) = 0;
    osGetTime_recomp(rdram, ctx);
        goto after_4;
    // 0x8007C1D0: sw          $zero, 0x18EC($t3)
    MEM_W(0X18EC, ctx->r11) = 0;
    after_4:
    // 0x8007C1D4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007C1D8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8007C1DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C1E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007C1E4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007C1E8: jal         0x800B7658
    // 0x8007C1EC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_5;
    // 0x8007C1EC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_5:
    // 0x8007C1F0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007C1F4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8007C1F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8007C1FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007C200: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007C204: jal         0x800B7558
    // 0x8007C208: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    __ull_div_recomp(rdram, ctx);
        goto after_6;
    // 0x8007C208: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x8007C20C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C210: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x8007C214: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007C218: sw          $t4, 0x18F4($t5)
    MEM_W(0X18F4, ctx->r13) = ctx->r12;
    // 0x8007C21C: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x8007C220: jal         0x8007BDD8
    // 0x8007C224: nop

    SaveData_InitDefaultScores(rdram, ctx);
        goto after_7;
    // 0x8007C224: nop

    after_7:
    // 0x8007C228: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C22C: jal         0x8007BCC4
    // 0x8007C230: addiu       $a1, $zero, 0x18FC
    ctx->r5 = ADD32(0, 0X18FC);
    SaveData_ComputeChecksum32(rdram, ctx);
        goto after_8;
    // 0x8007C230: addiu       $a1, $zero, 0x18FC
    ctx->r5 = ADD32(0, 0X18FC);
    after_8:
    // 0x8007C234: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C238: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007C23C: sw          $v0, 0x18FC($t6)
    MEM_W(0X18FC, ctx->r14) = ctx->r2;
    // 0x8007C240: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C244: jal         0x800AC22C
    // 0x8007C248: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    SaveData_SramWrite(rdram, ctx);
        goto after_9;
    // 0x8007C248: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    after_9:
    // 0x8007C24C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C250: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007C254: ori         $a1, $a1, 0x1900
    ctx->r5 = ctx->r5 | 0X1900;
    // 0x8007C258: jal         0x800AC22C
    // 0x8007C25C: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    SaveData_SramWrite(rdram, ctx);
        goto after_10;
    // 0x8007C25C: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    after_10:
    // 0x8007C260: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C264: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007C268: ori         $a1, $a1, 0x3200
    ctx->r5 = ctx->r5 | 0X3200;
    // 0x8007C26C: jal         0x800AC22C
    // 0x8007C270: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    SaveData_SramWrite(rdram, ctx);
        goto after_11;
    // 0x8007C270: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    after_11:
    // 0x8007C274: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C278: nop

    // 0x8007C27C: lw          $a0, 0x18E8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X18E8);
    // 0x8007C280: jal         0x80087618
    // 0x8007C284: nop

    Audio2_BuildVolumeTable(rdram, ctx);
        goto after_12;
    // 0x8007C284: nop

    after_12:
    // 0x8007C288: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C28C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007C290: lw          $a0, 0x18E4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X18E4);
    // 0x8007C294: jal         0x800875EC
    // 0x8007C298: addiu       $a1, $a1, 0xA70
    ctx->r5 = ADD32(ctx->r5, 0XA70);
    Audio2_SetGlobalPitch(rdram, ctx);
        goto after_13;
    // 0x8007C298: addiu       $a1, $a1, 0xA70
    ctx->r5 = ADD32(ctx->r5, 0XA70);
    after_13:
    // 0x8007C29C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C2A0: addiu       $at, $zero, 0x924
    ctx->r1 = ADD32(0, 0X924);
    // 0x8007C2A4: lw          $t0, 0x18E4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18E4);
    // 0x8007C2A8: nop

    // 0x8007C2AC: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x8007C2B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C2B4: mflo        $t1
    ctx->r9 = lo;
    // 0x8007C2B8: sb          $t1, 0x4914($at)
    MEM_B(0X4914, ctx->r1) = ctx->r9;
    // 0x8007C2BC: lw          $t2, 0x18E8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X18E8);
    // 0x8007C2C0: addiu       $at, $zero, 0x924
    ctx->r1 = ADD32(0, 0X924);
    // 0x8007C2C4: divu        $zero, $t2, $at
    lo = S32(U32(ctx->r10) / U32(ctx->r1)); hi = S32(U32(ctx->r10) % U32(ctx->r1));
    // 0x8007C2C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C2CC: mflo        $t3
    ctx->r11 = lo;
    // 0x8007C2D0: sb          $t3, 0x4CD8($at)
    MEM_B(0X4CD8, ctx->r1) = ctx->r11;
    // 0x8007C2D4: b           L_8007C5B0
    // 0x8007C2D8: nop

        goto L_8007C5B0;
    // 0x8007C2D8: nop

L_8007C2DC:
    // 0x8007C2DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C2E0: jal         0x8007BCC4
    // 0x8007C2E4: addiu       $a1, $zero, 0x18FC
    ctx->r5 = ADD32(0, 0X18FC);
    SaveData_ComputeChecksum32(rdram, ctx);
        goto after_14;
    // 0x8007C2E4: addiu       $a1, $zero, 0x18FC
    ctx->r5 = ADD32(0, 0X18FC);
    after_14:
    // 0x8007C2E8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C2EC: nop

    // 0x8007C2F0: lw          $t5, 0x18FC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18FC);
    // 0x8007C2F4: nop

    // 0x8007C2F8: beq         $v0, $t5, L_8007C538
    if (ctx->r2 == ctx->r13) {
        // 0x8007C2FC: nop
    
            goto L_8007C538;
    }
    // 0x8007C2FC: nop

    // 0x8007C300: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007C304: ori         $a1, $a1, 0x1900
    ctx->r5 = ctx->r5 | 0X1900;
    // 0x8007C308: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8007C30C: jal         0x800AC1A8
    // 0x8007C310: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    SaveData_SramRead(rdram, ctx);
        goto after_15;
    // 0x8007C310: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    after_15:
    // 0x8007C314: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C318: jal         0x8007BCC4
    // 0x8007C31C: addiu       $a1, $zero, 0x18FC
    ctx->r5 = ADD32(0, 0X18FC);
    SaveData_ComputeChecksum32(rdram, ctx);
        goto after_16;
    // 0x8007C31C: addiu       $a1, $zero, 0x18FC
    ctx->r5 = ADD32(0, 0X18FC);
    after_16:
    // 0x8007C320: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C324: nop

    // 0x8007C328: lw          $t7, 0x18FC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18FC);
    // 0x8007C32C: nop

    // 0x8007C330: beq         $v0, $t7, L_8007C538
    if (ctx->r2 == ctx->r15) {
        // 0x8007C334: nop
    
            goto L_8007C538;
    }
    // 0x8007C334: nop

    // 0x8007C338: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007C33C: ori         $a1, $a1, 0x3200
    ctx->r5 = ctx->r5 | 0X3200;
    // 0x8007C340: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8007C344: jal         0x800AC1A8
    // 0x8007C348: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    SaveData_SramRead(rdram, ctx);
        goto after_17;
    // 0x8007C348: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    after_17:
    // 0x8007C34C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C350: jal         0x8007BCC4
    // 0x8007C354: addiu       $a1, $zero, 0x18FC
    ctx->r5 = ADD32(0, 0X18FC);
    SaveData_ComputeChecksum32(rdram, ctx);
        goto after_18;
    // 0x8007C354: addiu       $a1, $zero, 0x18FC
    ctx->r5 = ADD32(0, 0X18FC);
    after_18:
    // 0x8007C358: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C35C: nop

    // 0x8007C360: lw          $t0, 0x18FC($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X18FC);
    // 0x8007C364: nop

    // 0x8007C368: beq         $v0, $t0, L_8007C538
    if (ctx->r2 == ctx->r8) {
        // 0x8007C36C: nop
    
            goto L_8007C538;
    }
    // 0x8007C36C: nop

    // 0x8007C370: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8007C374: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C378: jal         0x800B7450
    // 0x8007C37C: addiu       $a1, $zero, 0x1900
    ctx->r5 = ADD32(0, 0X1900);
    bzero_recomp(rdram, ctx);
        goto after_19;
    // 0x8007C37C: addiu       $a1, $zero, 0x1900
    ctx->r5 = ADD32(0, 0X1900);
    after_19:
    // 0x8007C380: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C384: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x8007C388: sb          $t1, 0x18F8($t9)
    MEM_B(0X18F8, ctx->r25) = ctx->r9;
    // 0x8007C38C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C390: addiu       $t2, $zero, 0x2E
    ctx->r10 = ADD32(0, 0X2E);
    // 0x8007C394: sb          $t2, 0x18F9($t3)
    MEM_B(0X18F9, ctx->r11) = ctx->r10;
    // 0x8007C398: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C39C: addiu       $t5, $zero, 0x30
    ctx->r13 = ADD32(0, 0X30);
    // 0x8007C3A0: sb          $t5, 0x18FA($t4)
    MEM_B(0X18FA, ctx->r12) = ctx->r13;
    // 0x8007C3A4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C3A8: addiu       $t7, $zero, 0x62
    ctx->r15 = ADD32(0, 0X62);
    // 0x8007C3AC: sb          $t7, 0x18FB($t6)
    MEM_B(0X18FB, ctx->r14) = ctx->r15;
    // 0x8007C3B0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C3B4: addiu       $t0, $zero, 0x5B68
    ctx->r8 = ADD32(0, 0X5B68);
    // 0x8007C3B8: sw          $t0, 0x18E4($t8)
    MEM_W(0X18E4, ctx->r24) = ctx->r8;
    // 0x8007C3BC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C3C0: addiu       $t1, $zero, 0x7000
    ctx->r9 = ADD32(0, 0X7000);
    // 0x8007C3C4: sw          $t1, 0x18E8($t9)
    MEM_W(0X18E8, ctx->r25) = ctx->r9;
    // 0x8007C3C8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C3CC: jal         0x800B6550
    // 0x8007C3D0: sw          $zero, 0x18EC($t2)
    MEM_W(0X18EC, ctx->r10) = 0;
    osGetTime_recomp(rdram, ctx);
        goto after_20;
    // 0x8007C3D0: sw          $zero, 0x18EC($t2)
    MEM_W(0X18EC, ctx->r10) = 0;
    after_20:
    // 0x8007C3D4: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8007C3D8: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x8007C3DC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8007C3E0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C3E4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007C3E8: or          $t7, $t3, $zero
    ctx->r15 = ctx->r11 | 0;
    // 0x8007C3EC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8007C3F0: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8007C3F4: addu        $t1, $t5, $t7
    ctx->r9 = ADD32(ctx->r13, ctx->r15);
    // 0x8007C3F8: lw          $t8, 0x30C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30C);
    // 0x8007C3FC: sltu        $at, $t1, $t7
    ctx->r1 = ctx->r9 < ctx->r15 ? 1 : 0;
    // 0x8007C400: sra         $t6, $t3, 31
    ctx->r14 = S32(SIGNED(ctx->r11) >> 31);
    // 0x8007C404: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C408: addu        $t0, $at, $t4
    ctx->r8 = ADD32(ctx->r1, ctx->r12);
    // 0x8007C40C: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8007C410: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
    // 0x8007C414: lw          $t6, 0x18FC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X18FC);
    // 0x8007C418: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x8007C41C: sltu        $at, $t5, $t3
    ctx->r1 = ctx->r13 < ctx->r11 ? 1 : 0;
    // 0x8007C420: addu        $t4, $at, $t0
    ctx->r12 = ADD32(ctx->r1, ctx->r8);
    // 0x8007C424: or          $t9, $t6, $zero
    ctx->r25 = ctx->r14 | 0;
    // 0x8007C428: addu        $a1, $t5, $t9
    ctx->r5 = ADD32(ctx->r13, ctx->r25);
    // 0x8007C42C: sra         $t2, $t8, 31
    ctx->r10 = S32(SIGNED(ctx->r24) >> 31);
    // 0x8007C430: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x8007C434: sltu        $at, $a1, $t9
    ctx->r1 = ctx->r5 < ctx->r25 ? 1 : 0;
    // 0x8007C438: addu        $a0, $at, $t4
    ctx->r4 = ADD32(ctx->r1, ctx->r12);
    // 0x8007C43C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8007C440: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8007C444: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007C448: jal         0x800B7658
    // 0x8007C44C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_21;
    // 0x8007C44C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_21:
    // 0x8007C450: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007C454: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8007C458: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8007C45C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007C460: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007C464: jal         0x800B7558
    // 0x8007C468: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    __ull_div_recomp(rdram, ctx);
        goto after_22;
    // 0x8007C468: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_22:
    // 0x8007C46C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C470: or          $t7, $v1, $zero
    ctx->r15 = ctx->r3 | 0;
    // 0x8007C474: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007C478: sw          $t7, 0x18F4($t0)
    MEM_W(0X18F4, ctx->r8) = ctx->r15;
    // 0x8007C47C: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x8007C480: jal         0x8007BDD8
    // 0x8007C484: nop

    SaveData_InitDefaultScores(rdram, ctx);
        goto after_23;
    // 0x8007C484: nop

    after_23:
    // 0x8007C488: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C48C: jal         0x8007BCC4
    // 0x8007C490: addiu       $a1, $zero, 0x18FC
    ctx->r5 = ADD32(0, 0X18FC);
    SaveData_ComputeChecksum32(rdram, ctx);
        goto after_24;
    // 0x8007C490: addiu       $a1, $zero, 0x18FC
    ctx->r5 = ADD32(0, 0X18FC);
    after_24:
    // 0x8007C494: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C498: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007C49C: sw          $v0, 0x18FC($t1)
    MEM_W(0X18FC, ctx->r9) = ctx->r2;
    // 0x8007C4A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C4A4: jal         0x800AC22C
    // 0x8007C4A8: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    SaveData_SramWrite(rdram, ctx);
        goto after_25;
    // 0x8007C4A8: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    after_25:
    // 0x8007C4AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C4B0: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007C4B4: ori         $a1, $a1, 0x1900
    ctx->r5 = ctx->r5 | 0X1900;
    // 0x8007C4B8: jal         0x800AC22C
    // 0x8007C4BC: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    SaveData_SramWrite(rdram, ctx);
        goto after_26;
    // 0x8007C4BC: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    after_26:
    // 0x8007C4C0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C4C4: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007C4C8: ori         $a1, $a1, 0x3200
    ctx->r5 = ctx->r5 | 0X3200;
    // 0x8007C4CC: jal         0x800AC22C
    // 0x8007C4D0: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    SaveData_SramWrite(rdram, ctx);
        goto after_27;
    // 0x8007C4D0: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    after_27:
    // 0x8007C4D4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C4D8: nop

    // 0x8007C4DC: lw          $a0, 0x18E8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X18E8);
    // 0x8007C4E0: jal         0x80087618
    // 0x8007C4E4: nop

    Audio2_BuildVolumeTable(rdram, ctx);
        goto after_28;
    // 0x8007C4E4: nop

    after_28:
    // 0x8007C4E8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C4EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007C4F0: lw          $a0, 0x18E4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X18E4);
    // 0x8007C4F4: jal         0x800875EC
    // 0x8007C4F8: addiu       $a1, $a1, 0xA70
    ctx->r5 = ADD32(ctx->r5, 0XA70);
    Audio2_SetGlobalPitch(rdram, ctx);
        goto after_29;
    // 0x8007C4F8: addiu       $a1, $a1, 0xA70
    ctx->r5 = ADD32(ctx->r5, 0XA70);
    after_29:
    // 0x8007C4FC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C500: addiu       $at, $zero, 0x924
    ctx->r1 = ADD32(0, 0X924);
    // 0x8007C504: lw          $t4, 0x18E4($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X18E4);
    // 0x8007C508: nop

    // 0x8007C50C: divu        $zero, $t4, $at
    lo = S32(U32(ctx->r12) / U32(ctx->r1)); hi = S32(U32(ctx->r12) % U32(ctx->r1));
    // 0x8007C510: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C514: mflo        $t5
    ctx->r13 = lo;
    // 0x8007C518: sb          $t5, 0x4914($at)
    MEM_B(0X4914, ctx->r1) = ctx->r13;
    // 0x8007C51C: lw          $t8, 0x18E8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18E8);
    // 0x8007C520: addiu       $at, $zero, 0x924
    ctx->r1 = ADD32(0, 0X924);
    // 0x8007C524: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x8007C528: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C52C: mflo        $t9
    ctx->r25 = lo;
    // 0x8007C530: sb          $t9, 0x4CD8($at)
    MEM_B(0X4CD8, ctx->r1) = ctx->r25;
    // 0x8007C534: nop

L_8007C538:
    // 0x8007C538: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C53C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007C540: lw          $a0, 0x18E4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X18E4);
    // 0x8007C544: jal         0x800875EC
    // 0x8007C548: addiu       $a1, $a1, 0xA70
    ctx->r5 = ADD32(ctx->r5, 0XA70);
    Audio2_SetGlobalPitch(rdram, ctx);
        goto after_30;
    // 0x8007C548: addiu       $a1, $a1, 0xA70
    ctx->r5 = ADD32(ctx->r5, 0XA70);
    after_30:
    // 0x8007C54C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C550: nop

    // 0x8007C554: lw          $a0, 0x18E8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X18E8);
    // 0x8007C558: jal         0x80087618
    // 0x8007C55C: nop

    Audio2_BuildVolumeTable(rdram, ctx);
        goto after_31;
    // 0x8007C55C: nop

    after_31:
    // 0x8007C560: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C564: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C568: lw          $t2, 0x18F0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18F0);
    // 0x8007C56C: jal         0x80045E50
    // 0x8007C570: sb          $t2, 0x4DD0($at)
    MEM_B(0X4DD0, ctx->r1) = ctx->r10;
    wonders2_InitWonderProgress(rdram, ctx);
        goto after_32;
    // 0x8007C570: sb          $t2, 0x4DD0($at)
    MEM_B(0X4DD0, ctx->r1) = ctx->r10;
    after_32:
    // 0x8007C574: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C578: addiu       $at, $zero, 0x924
    ctx->r1 = ADD32(0, 0X924);
    // 0x8007C57C: lw          $t4, 0x18E4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18E4);
    // 0x8007C580: nop

    // 0x8007C584: divu        $zero, $t4, $at
    lo = S32(U32(ctx->r12) / U32(ctx->r1)); hi = S32(U32(ctx->r12) % U32(ctx->r1));
    // 0x8007C588: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C58C: mflo        $t5
    ctx->r13 = lo;
    // 0x8007C590: sb          $t5, 0x4914($at)
    MEM_B(0X4914, ctx->r1) = ctx->r13;
    // 0x8007C594: lw          $t6, 0x18E8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X18E8);
    // 0x8007C598: addiu       $at, $zero, 0x924
    ctx->r1 = ADD32(0, 0X924);
    // 0x8007C59C: divu        $zero, $t6, $at
    lo = S32(U32(ctx->r14) / U32(ctx->r1)); hi = S32(U32(ctx->r14) % U32(ctx->r1));
    // 0x8007C5A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C5A4: mflo        $t8
    ctx->r24 = lo;
    // 0x8007C5A8: sb          $t8, 0x4CD8($at)
    MEM_B(0X4CD8, ctx->r1) = ctx->r24;
    // 0x8007C5AC: nop

L_8007C5B0:
    // 0x8007C5B0: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8007C5B4: lb          $t9, -0x7C8($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X7C8);
    // 0x8007C5B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C5BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C5C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007C5C4: jr          $ra
    // 0x8007C5C8: sb          $t9, -0x1108($at)
    MEM_B(-0X1108, ctx->r1) = ctx->r25;
    return;
    // 0x8007C5C8: sb          $t9, -0x1108($at)
    MEM_B(-0X1108, ctx->r1) = ctx->r25;
;}

RECOMP_FUNC void SaveData_Save(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C5CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007C5D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C5D4: jal         0x800B6550
    // 0x8007C5D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x8007C5D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007C5DC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8007C5E0: or          $t6, $v1, $zero
    ctx->r14 = ctx->r3 | 0;
    // 0x8007C5E4: sw          $t6, 0x18F4($t7)
    MEM_W(0X18F4, ctx->r15) = ctx->r14;
    // 0x8007C5E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007C5EC: jal         0x8007BCC4
    // 0x8007C5F0: addiu       $a1, $zero, 0x18FC
    ctx->r5 = ADD32(0, 0X18FC);
    SaveData_ComputeChecksum32(rdram, ctx);
        goto after_1;
    // 0x8007C5F0: addiu       $a1, $zero, 0x18FC
    ctx->r5 = ADD32(0, 0X18FC);
    after_1:
    // 0x8007C5F4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8007C5F8: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007C5FC: sw          $v0, 0x18FC($t8)
    MEM_W(0X18FC, ctx->r24) = ctx->r2;
    // 0x8007C600: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007C604: jal         0x800AC22C
    // 0x8007C608: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    SaveData_SramWrite(rdram, ctx);
        goto after_2;
    // 0x8007C608: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    after_2:
    // 0x8007C60C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007C610: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007C614: ori         $a1, $a1, 0x1900
    ctx->r5 = ctx->r5 | 0X1900;
    // 0x8007C618: jal         0x800AC22C
    // 0x8007C61C: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    SaveData_SramWrite(rdram, ctx);
        goto after_3;
    // 0x8007C61C: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    after_3:
    // 0x8007C620: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007C624: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007C628: ori         $a1, $a1, 0x3200
    ctx->r5 = ctx->r5 | 0X3200;
    // 0x8007C62C: jal         0x800AC22C
    // 0x8007C630: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    SaveData_SramWrite(rdram, ctx);
        goto after_4;
    // 0x8007C630: addiu       $a2, $zero, 0x1900
    ctx->r6 = ADD32(0, 0X1900);
    after_4:
    // 0x8007C634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007C63C: jr          $ra
    // 0x8007C640: nop

    return;
    // 0x8007C640: nop

    // 0x8007C644: nop

    // 0x8007C648: nop

    // 0x8007C64C: nop

;}

RECOMP_FUNC void SaveData_SramRead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC1A8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800AC1AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AC1B0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800AC1B4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800AC1B8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800AC1BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC1C0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800AC1C4: jal         0x800B3080
    // 0x800AC1C8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800AC1C8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x800AC1CC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800AC1D0: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800AC1D4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800AC1D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AC1DC: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x800AC1E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC1E4: sb          $t9, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r25;
    // 0x800AC1E8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800AC1EC: addiu       $a0, $a0, -0x35F0
    ctx->r4 = ADD32(ctx->r4, -0X35F0);
    // 0x800AC1F0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800AC1F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC1F8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800AC1FC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800AC200: jal         0x800B34D0
    // 0x800AC204: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800AC204: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_1:
    // 0x800AC208: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800AC20C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800AC210: jal         0x800B3C20
    // 0x800AC214: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800AC214: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800AC218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AC21C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800AC220: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800AC224: jr          $ra
    // 0x800AC228: nop

    return;
    // 0x800AC228: nop

;}

RECOMP_FUNC void SaveData_SramWrite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC22C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800AC230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AC234: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800AC238: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800AC23C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800AC240: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC244: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800AC248: jal         0x800B3080
    // 0x800AC24C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800AC24C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x800AC250: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800AC254: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800AC258: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800AC25C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800AC260: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x800AC264: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC268: sb          $t9, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r25;
    // 0x800AC26C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800AC270: addiu       $a0, $a0, -0x35F0
    ctx->r4 = ADD32(ctx->r4, -0X35F0);
    // 0x800AC274: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800AC278: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC27C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800AC280: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800AC284: jal         0x800B34D0
    // 0x800AC288: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800AC288: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_1:
    // 0x800AC28C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800AC290: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800AC294: jal         0x800B3C20
    // 0x800AC298: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800AC298: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800AC29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AC2A0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800AC2A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800AC2A8: jr          $ra
    // 0x800AC2AC: nop

    return;
    // 0x800AC2AC: nop

;}

RECOMP_FUNC void func_800AC2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC2B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800AC2B4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800AC2B8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800AC2BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AC2C0: beq         $v0, $zero, L_800AC2EC
    if (ctx->r2 == 0) {
        // 0x800AC2C4: nop
    
            goto L_800AC2EC;
    }
    // 0x800AC2C4: nop

    // 0x800AC2C8: beq         $t6, $v0, L_800AC2EC
    if (ctx->r14 == ctx->r2) {
        // 0x800AC2CC: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_800AC2EC;
    }
    // 0x800AC2CC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800AC2D0: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
L_800AC2D4:
    // 0x800AC2D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AC2D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AC2DC: beq         $v0, $zero, L_800AC2EC
    if (ctx->r2 == 0) {
        // 0x800AC2E0: nop
    
            goto L_800AC2EC;
    }
    // 0x800AC2E0: nop

    // 0x800AC2E4: bnel        $a2, $v0, L_800AC2D4
    if (ctx->r6 != ctx->r2) {
        // 0x800AC2E8: lbu         $v0, 0x1($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X1);
            goto L_800AC2D4;
    }
    goto skip_0;
    // 0x800AC2E8: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    skip_0:
L_800AC2EC:
    // 0x800AC2EC: beql        $v0, $zero, L_800AC300
    if (ctx->r2 == 0) {
        // 0x800AC2F0: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800AC300;
    }
    goto skip_1;
    // 0x800AC2F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x800AC2F4: jr          $ra
    // 0x800AC2F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800AC2F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800AC2FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AC300:
    // 0x800AC300: jr          $ra
    // 0x800AC304: nop

    return;
    // 0x800AC304: nop

;}

RECOMP_FUNC void func_800AC308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC308: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC30C: addiu       $v0, $v0, -0x3518
    ctx->r2 = ADD32(ctx->r2, -0X3518);
    // 0x800AC310: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800AC314: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC318: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800AC31C: sw          $a0, -0x3520($at)
    MEM_W(-0X3520, ctx->r1) = ctx->r4;
    // 0x800AC320: addiu       $v1, $v1, -0x3514
    ctx->r3 = ADD32(ctx->r3, -0X3514);
    // 0x800AC324: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800AC328: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC32C: jr          $ra
    // 0x800AC330: sw          $a1, -0x351C($at)
    MEM_W(-0X351C, ctx->r1) = ctx->r5;
    return;
    // 0x800AC330: sw          $a1, -0x351C($at)
    MEM_W(-0X351C, ctx->r1) = ctx->r5;
;}

RECOMP_FUNC void func_800AC334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC334: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC338: sw          $a0, -0x6F08($at)
    MEM_W(-0X6F08, ctx->r1) = ctx->r4;
    // 0x800AC33C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC340: sw          $a1, -0x6F04($at)
    MEM_W(-0X6F04, ctx->r1) = ctx->r5;
    // 0x800AC344: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC348: jr          $ra
    // 0x800AC34C: sw          $a2, -0x6F00($at)
    MEM_W(-0X6F00, ctx->r1) = ctx->r6;
    return;
    // 0x800AC34C: sw          $a2, -0x6F00($at)
    MEM_W(-0X6F00, ctx->r1) = ctx->r6;
;}

RECOMP_FUNC void func_800AC350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC350: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800AC354: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x800AC358: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AC35C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800AC360: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800AC364: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800AC368: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x800AC36C: addiu       $a3, $a0, 0x8
    ctx->r7 = ADD32(ctx->r4, 0X8);
    // 0x800AC370: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800AC374: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800AC378: lui         $t7, 0xFC11
    ctx->r15 = S32(0XFC11 << 16);
    // 0x800AC37C: lui         $t8, 0xFF2F
    ctx->r24 = S32(0XFF2F << 16);
    // 0x800AC380: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x800AC384: ori         $t7, $t7, 0x9623
    ctx->r15 = ctx->r15 | 0X9623;
    // 0x800AC388: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x800AC38C: lui         $v1, 0xE300
    ctx->r3 = S32(0XE300 << 16);
    // 0x800AC390: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800AC394: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800AC398: ori         $v1, $v1, 0xC00
    ctx->r3 = ctx->r3 | 0XC00;
    // 0x800AC39C: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x800AC3A0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800AC3A4: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800AC3A8: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800AC3AC: ori         $t9, $t9, 0xF00
    ctx->r25 = ctx->r25 | 0XF00;
    // 0x800AC3B0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800AC3B4: addiu       $a1, $t1, 0x8
    ctx->r5 = ADD32(ctx->r9, 0X8);
    // 0x800AC3B8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AC3BC: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x800AC3C0: ori         $t2, $t2, 0x1201
    ctx->r10 = ctx->r10 | 0X1201;
    // 0x800AC3C4: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800AC3C8: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x800AC3CC: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800AC3D0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800AC3D4: ori         $t3, $t3, 0x1402
    ctx->r11 = ctx->r11 | 0X1402;
    // 0x800AC3D8: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800AC3DC: addiu       $a0, $a2, 0x8
    ctx->r4 = ADD32(ctx->r6, 0X8);
    // 0x800AC3E0: addiu       $t4, $zero, 0xC00
    ctx->r12 = ADD32(0, 0XC00);
    // 0x800AC3E4: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x800AC3E8: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x800AC3EC: ori         $t5, $t5, 0x1001
    ctx->r13 = ctx->r13 | 0X1001;
    // 0x800AC3F0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800AC3F4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800AC3F8: addiu       $t0, $a0, 0x8
    ctx->r8 = ADD32(ctx->r4, 0X8);
    // 0x800AC3FC: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x800AC400: ori         $t6, $t6, 0x1E01
    ctx->r14 = ctx->r14 | 0X1E01;
    // 0x800AC404: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800AC408: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800AC40C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AC410: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800AC414: lui         $t8, 0xF900
    ctx->r24 = S32(0XF900 << 16);
    // 0x800AC418: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800AC41C: addiu       $a1, $t1, 0x8
    ctx->r5 = ADD32(ctx->r9, 0X8);
    // 0x800AC420: addiu       $t9, $zero, -0x100
    ctx->r25 = ADD32(0, -0X100);
    // 0x800AC424: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800AC428: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800AC42C: addiu       $t3, $t3, 0x7B98
    ctx->r11 = ADD32(ctx->r11, 0X7B98);
    // 0x800AC430: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800AC434: lui         $t2, 0xFD90
    ctx->r10 = S32(0XFD90 << 16);
    // 0x800AC438: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800AC43C: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x800AC440: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x800AC444: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x800AC448: lui         $t4, 0xF590
    ctx->r12 = S32(0XF590 << 16);
    // 0x800AC44C: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800AC450: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x800AC454: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800AC458: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800AC45C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800AC460: addiu       $a0, $a3, 0x8
    ctx->r4 = ADD32(ctx->r7, 0X8);
    // 0x800AC464: lui         $t8, 0x77F
    ctx->r24 = S32(0X77F << 16);
    // 0x800AC468: ori         $t8, $t8, 0xF200
    ctx->r24 = ctx->r24 | 0XF200;
    // 0x800AC46C: addiu       $t1, $a0, 0x8
    ctx->r9 = ADD32(ctx->r4, 0X8);
    // 0x800AC470: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800AC474: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800AC478: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800AC47C: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x800AC480: addiu       $a1, $t1, 0x8
    ctx->r5 = ADD32(ctx->r9, 0X8);
    // 0x800AC484: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AC488: lui         $t9, 0xF580
    ctx->r25 = S32(0XF580 << 16);
    // 0x800AC48C: ori         $t9, $t9, 0x800
    ctx->r25 = ctx->r25 | 0X800;
    // 0x800AC490: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800AC494: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800AC498: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800AC49C: lui         $t3, 0xF
    ctx->r11 = S32(0XF << 16);
    // 0x800AC4A0: ori         $t3, $t3, 0xC1FC
    ctx->r11 = ctx->r11 | 0XC1FC;
    // 0x800AC4A4: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x800AC4A8: lui         $t2, 0xF200
    ctx->r10 = S32(0XF200 << 16);
    // 0x800AC4AC: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x800AC4B0: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x800AC4B4: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x800AC4B8: lui         $t5, 0xC08
    ctx->r13 = S32(0XC08 << 16);
    // 0x800AC4BC: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x800AC4C0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800AC4C4: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x800AC4C8: ori         $t4, $t4, 0x1C
    ctx->r12 = ctx->r12 | 0X1C;
    // 0x800AC4CC: ori         $t5, $t5, 0x7008
    ctx->r13 = ctx->r13 | 0X7008;
    // 0x800AC4D0: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x800AC4D4: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800AC4D8: jr          $ra
    // 0x800AC4DC: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    return;
    // 0x800AC4DC: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
;}

RECOMP_FUNC void func_800AC4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC4E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800AC4E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AC4E8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800AC4EC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800AC4F0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AC4F4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AC4F8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AC4FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AC500: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AC504: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AC508: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AC50C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800AC510: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800AC514: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AC518: lw          $t0, -0x6F04($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6F04);
    // 0x800AC51C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AC520: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AC524: lw          $t4, -0x6F00($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6F00);
    // 0x800AC528: lw          $t8, -0x6F08($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X6F08);
    // 0x800AC52C: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800AC530: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x800AC534: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800AC538: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800AC53C: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x800AC540: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800AC544: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800AC548: ori         $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 | 0XFF;
    // 0x800AC54C: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
    // 0x800AC550: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800AC554: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800AC558: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800AC55C: lui         $t0, 0xD700
    ctx->r8 = S32(0XD700 << 16);
    // 0x800AC560: ori         $t0, $t0, 0x2
    ctx->r8 = ctx->r8 | 0X2;
    // 0x800AC564: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x800AC568: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800AC56C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800AC570: lbu         $a2, 0x0($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X0);
    // 0x800AC574: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800AC578: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AC57C: beq         $a2, $zero, L_800AC6D4
    if (ctx->r6 == 0) {
        // 0x800AC580: lui         $fp, 0xE400
        ctx->r30 = S32(0XE400 << 16);
            goto L_800AC6D4;
    }
    // 0x800AC580: lui         $fp, 0xE400
    ctx->r30 = S32(0XE400 << 16);
    // 0x800AC584: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800AC588: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AC58C: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800AC590: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800AC594: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800AC598: addiu       $s1, $s1, -0x3518
    ctx->r17 = ADD32(ctx->r17, -0X3518);
    // 0x800AC59C: addiu       $s2, $s2, -0x3514
    ctx->r18 = ADD32(ctx->r18, -0X3514);
    // 0x800AC5A0: addiu       $s4, $s4, -0x3520
    ctx->r20 = ADD32(ctx->r20, -0X3520);
    // 0x800AC5A4: addiu       $s5, $s5, -0x7468
    ctx->r21 = ADD32(ctx->r21, -0X7468);
    // 0x800AC5A8: addiu       $s7, $s7, -0x7414
    ctx->r23 = ADD32(ctx->r23, -0X7414);
    // 0x800AC5AC: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x800AC5B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800AC5B4:
    // 0x800AC5B4: jal         0x800AC2B0
    // 0x800AC5B8: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    func_800AC2B0(rdram, ctx);
        goto after_0;
    // 0x800AC5B8: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    after_0:
    // 0x800AC5BC: beq         $v0, $s6, L_800AC674
    if (ctx->r2 == ctx->r22) {
        // 0x800AC5C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800AC674;
    }
    // 0x800AC5C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AC5C4: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x800AC5C8: addu        $v1, $s7, $t9
    ctx->r3 = ADD32(ctx->r23, ctx->r25);
    // 0x800AC5CC: lh          $t2, 0xC($v1)
    ctx->r10 = MEM_H(ctx->r3, 0XC);
    // 0x800AC5D0: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x800AC5D4: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800AC5D8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800AC5DC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AC5E0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800AC5E4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800AC5E8: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x800AC5EC: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x800AC5F0: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x800AC5F4: andi        $t2, $t9, 0xFFF
    ctx->r10 = ctx->r25 & 0XFFF;
    // 0x800AC5F8: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x800AC5FC: or          $t7, $t6, $fp
    ctx->r15 = ctx->r14 | ctx->r30;
    // 0x800AC600: or          $t5, $t7, $t4
    ctx->r13 = ctx->r15 | ctx->r12;
    // 0x800AC604: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800AC608: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800AC60C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800AC610: lui         $t4, 0xE100
    ctx->r12 = S32(0XE100 << 16);
    // 0x800AC614: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800AC618: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800AC61C: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x800AC620: andi        $t2, $t9, 0xFFF
    ctx->r10 = ctx->r25 & 0XFFF;
    // 0x800AC624: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x800AC628: or          $t7, $t0, $t2
    ctx->r15 = ctx->r8 | ctx->r10;
    // 0x800AC62C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800AC630: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800AC634: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800AC638: lh          $t5, 0x6($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X6);
    // 0x800AC63C: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x800AC640: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AC644: sll         $t3, $t5, 5
    ctx->r11 = S32(ctx->r13 << 5);
    // 0x800AC648: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x800AC64C: sll         $t0, $t9, 21
    ctx->r8 = S32(ctx->r25 << 21);
    // 0x800AC650: or          $t2, $t6, $t0
    ctx->r10 = ctx->r14 | ctx->r8;
    // 0x800AC654: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800AC658: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x800AC65C: lui         $t4, 0x400
    ctx->r12 = S32(0X400 << 16);
    // 0x800AC660: ori         $t4, $t4, 0x400
    ctx->r12 = ctx->r12 | 0X400;
    // 0x800AC664: lui         $t7, 0xF100
    ctx->r15 = S32(0XF100 << 16);
    // 0x800AC668: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800AC66C: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x800AC670: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800AC674:
    // 0x800AC674: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    // 0x800AC678: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800AC67C: bnel        $t5, $at, L_800AC6A0
    if (ctx->r13 != ctx->r1) {
        // 0x800AC680: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_800AC6A0;
    }
    goto skip_0;
    // 0x800AC680: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x800AC684: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800AC688: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800AC68C: addiu       $t1, $t8, 0x10
    ctx->r9 = ADD32(ctx->r24, 0X10);
    // 0x800AC690: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x800AC694: b           L_800AC6C4
    // 0x800AC698: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
        goto L_800AC6C4;
    // 0x800AC698: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x800AC69C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
L_800AC6A0:
    // 0x800AC6A0: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800AC6A4: slti        $at, $t6, 0x130
    ctx->r1 = SIGNED(ctx->r14) < 0X130 ? 1 : 0;
    // 0x800AC6A8: bne         $at, $zero, L_800AC6C4
    if (ctx->r1 != 0) {
        // 0x800AC6AC: sw          $t6, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r14;
            goto L_800AC6C4;
    }
    // 0x800AC6AC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800AC6B0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AC6B4: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800AC6B8: addiu       $t4, $t7, 0x10
    ctx->r12 = ADD32(ctx->r15, 0X10);
    // 0x800AC6BC: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x800AC6C0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
L_800AC6C4:
    // 0x800AC6C4: lbu         $a2, 0x1($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X1);
    // 0x800AC6C8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800AC6CC: bnel        $a2, $zero, L_800AC5B4
    if (ctx->r6 != 0) {
        // 0x800AC6D0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800AC5B4;
    }
    goto skip_1;
    // 0x800AC6D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_1:
L_800AC6D4:
    // 0x800AC6D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AC6D8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AC6DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AC6E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC6E4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AC6E8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AC6EC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AC6F0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AC6F4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AC6F8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800AC6FC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800AC700: jr          $ra
    // 0x800AC704: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800AC704: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void func_800AC708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC708: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800AC70C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AC710: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AC714: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800AC718: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800AC71C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AC720: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800AC724: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800AC728: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AC72C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AC730: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AC734: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AC738: bgtz        $a2, L_800AC744
    if (SIGNED(ctx->r6) > 0) {
        // 0x800AC73C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800AC744;
    }
    // 0x800AC73C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AC740: addiu       $a2, $zero, 0x130
    ctx->r6 = ADD32(0, 0X130);
L_800AC744:
    // 0x800AC744: bgtz        $a3, L_800AC750
    if (SIGNED(ctx->r7) > 0) {
        // 0x800AC748: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_800AC750;
    }
    // 0x800AC748: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800AC74C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_800AC750:
    // 0x800AC750: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800AC754: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AC758: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AC75C: lw          $t0, -0x6F04($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6F04);
    // 0x800AC760: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AC764: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AC768: lw          $t4, -0x6F00($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6F00);
    // 0x800AC76C: lw          $t8, -0x6F08($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X6F08);
    // 0x800AC770: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800AC774: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x800AC778: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800AC77C: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800AC780: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x800AC784: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800AC788: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800AC78C: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x800AC790: or          $t0, $t7, $t8
    ctx->r8 = ctx->r15 | ctx->r24;
    // 0x800AC794: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800AC798: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800AC79C: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800AC7A0: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800AC7A4: lui         $t1, 0xD700
    ctx->r9 = S32(0XD700 << 16);
    // 0x800AC7A8: ori         $t1, $t1, 0x2
    ctx->r9 = ctx->r9 | 0X2;
    // 0x800AC7AC: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x800AC7B0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800AC7B4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800AC7B8: lbu         $a1, 0x0($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X0);
    // 0x800AC7BC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800AC7C0: lui         $fp, 0xE400
    ctx->r30 = S32(0XE400 << 16);
    // 0x800AC7C4: beq         $a1, $zero, L_800AC91C
    if (ctx->r5 == 0) {
        // 0x800AC7C8: lui         $s7, 0x800E
        ctx->r23 = S32(0X800E << 16);
            goto L_800AC91C;
    }
    // 0x800AC7C8: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800AC7CC: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AC7D0: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800AC7D4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800AC7D8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800AC7DC: addiu       $s0, $s0, -0x3518
    ctx->r16 = ADD32(ctx->r16, -0X3518);
    // 0x800AC7E0: addiu       $s1, $s1, -0x3514
    ctx->r17 = ADD32(ctx->r17, -0X3514);
    // 0x800AC7E4: addiu       $s4, $s4, -0x3520
    ctx->r20 = ADD32(ctx->r20, -0X3520);
    // 0x800AC7E8: addiu       $s5, $s5, -0x7468
    ctx->r21 = ADD32(ctx->r21, -0X7468);
    // 0x800AC7EC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800AC7F0: addiu       $s7, $s7, -0x7414
    ctx->r23 = ADD32(ctx->r23, -0X7414);
    // 0x800AC7F4: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_800AC7F8:
    // 0x800AC7F8: jal         0x800AC2B0
    // 0x800AC7FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800AC2B0(rdram, ctx);
        goto after_0;
    // 0x800AC7FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x800AC800: beq         $v0, $s6, L_800AC8B8
    if (ctx->r2 == ctx->r22) {
        // 0x800AC804: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800AC8B8;
    }
    // 0x800AC804: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AC808: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x800AC80C: addu        $v1, $s7, $t2
    ctx->r3 = ADD32(ctx->r23, ctx->r10);
    // 0x800AC810: lh          $t4, 0xC($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XC);
    // 0x800AC814: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x800AC818: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800AC81C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800AC820: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800AC824: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x800AC828: addu        $t9, $t0, $t1
    ctx->r25 = ADD32(ctx->r8, ctx->r9);
    // 0x800AC82C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800AC830: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800AC834: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800AC838: andi        $t4, $t2, 0xFFF
    ctx->r12 = ctx->r10 & 0XFFF;
    // 0x800AC83C: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x800AC840: or          $t8, $t7, $fp
    ctx->r24 = ctx->r15 | ctx->r30;
    // 0x800AC844: or          $t3, $t8, $t5
    ctx->r11 = ctx->r24 | ctx->r13;
    // 0x800AC848: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800AC84C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800AC850: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800AC854: lui         $t5, 0xE100
    ctx->r13 = S32(0XE100 << 16);
    // 0x800AC858: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AC85C: andi        $t0, $t7, 0xFFF
    ctx->r8 = ctx->r15 & 0XFFF;
    // 0x800AC860: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800AC864: andi        $t4, $t2, 0xFFF
    ctx->r12 = ctx->r10 & 0XFFF;
    // 0x800AC868: sll         $t1, $t0, 12
    ctx->r9 = S32(ctx->r8 << 12);
    // 0x800AC86C: or          $t8, $t1, $t4
    ctx->r24 = ctx->r9 | ctx->r12;
    // 0x800AC870: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800AC874: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800AC878: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800AC87C: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x800AC880: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x800AC884: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800AC888: sll         $t6, $t3, 5
    ctx->r14 = S32(ctx->r11 << 5);
    // 0x800AC88C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800AC890: sll         $t1, $t2, 21
    ctx->r9 = S32(ctx->r10 << 21);
    // 0x800AC894: or          $t4, $t7, $t1
    ctx->r12 = ctx->r15 | ctx->r9;
    // 0x800AC898: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800AC89C: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800AC8A0: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x800AC8A4: ori         $t5, $t5, 0x400
    ctx->r13 = ctx->r13 | 0X400;
    // 0x800AC8A8: lui         $t8, 0xF100
    ctx->r24 = S32(0XF100 << 16);
    // 0x800AC8AC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800AC8B0: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x800AC8B4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_800AC8B8:
    // 0x800AC8B8: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
    // 0x800AC8BC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800AC8C0: bnel        $t3, $at, L_800AC8E4
    if (ctx->r11 != ctx->r1) {
        // 0x800AC8C4: lw          $t2, 0x0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X0);
            goto L_800AC8E4;
    }
    goto skip_0;
    // 0x800AC8C4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800AC8C8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800AC8CC: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800AC8D0: addiu       $t9, $t0, 0x10
    ctx->r25 = ADD32(ctx->r8, 0X10);
    // 0x800AC8D4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800AC8D8: b           L_800AC90C
    // 0x800AC8DC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
        goto L_800AC90C;
    // 0x800AC8DC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AC8E0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_800AC8E4:
    // 0x800AC8E4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800AC8E8: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x800AC8EC: slt         $at, $t7, $t4
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800AC8F0: bne         $at, $zero, L_800AC90C
    if (ctx->r1 != 0) {
        // 0x800AC8F4: sw          $t7, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r15;
            goto L_800AC90C;
    }
    // 0x800AC8F4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800AC8F8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800AC8FC: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800AC900: addiu       $t3, $t5, 0x10
    ctx->r11 = ADD32(ctx->r13, 0X10);
    // 0x800AC904: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x800AC908: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_800AC90C:
    // 0x800AC90C: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
    // 0x800AC910: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800AC914: bne         $a1, $zero, L_800AC7F8
    if (ctx->r5 != 0) {
        // 0x800AC918: nop
    
            goto L_800AC7F8;
    }
    // 0x800AC918: nop

L_800AC91C:
    // 0x800AC91C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AC920: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800AC924: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AC928: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AC92C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC930: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AC934: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AC938: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AC93C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AC940: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800AC944: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800AC948: jr          $ra
    // 0x800AC94C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800AC94C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void func_800AC950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC950: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800AC954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AC958: addiu       $a2, $sp, 0x3F
    ctx->r6 = ADD32(ctx->r29, 0X3F);
    // 0x800AC95C: sb          $zero, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = 0;
    // 0x800AC960: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800AC964:
    // 0x800AC964: div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // 0x800AC968: mfhi        $t6
    ctx->r14 = hi;
    // 0x800AC96C: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x800AC970: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800AC974: bne         $v0, $zero, L_800AC980
    if (ctx->r2 != 0) {
        // 0x800AC978: nop
    
            goto L_800AC980;
    }
    // 0x800AC978: nop

    // 0x800AC97C: break       7
    do_break(2148190588);
L_800AC980:
    // 0x800AC980: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC984: bne         $v0, $at, L_800AC998
    if (ctx->r2 != ctx->r1) {
        // 0x800AC988: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC998;
    }
    // 0x800AC988: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC98C: bne         $a1, $at, L_800AC998
    if (ctx->r5 != ctx->r1) {
        // 0x800AC990: nop
    
            goto L_800AC998;
    }
    // 0x800AC990: nop

    // 0x800AC994: break       6
    do_break(2148190612);
L_800AC998:
    // 0x800AC998: mflo        $a1
    ctx->r5 = lo;
    // 0x800AC99C: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x800AC9A0: bne         $a1, $zero, L_800AC964
    if (ctx->r5 != 0) {
        // 0x800AC9A4: nop
    
            goto L_800AC964;
    }
    // 0x800AC9A4: nop

    // 0x800AC9A8: jal         0x800AC4E0
    // 0x800AC9AC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800AC4E0(rdram, ctx);
        goto after_0;
    // 0x800AC9AC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800AC9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AC9B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800AC9B8: jr          $ra
    // 0x800AC9BC: nop

    return;
    // 0x800AC9BC: nop

;}

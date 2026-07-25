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

RECOMP_FUNC void FUN_001050_8003b3e4_motor_sendrecvmsg_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B3E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B3E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B3EC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B3F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B3F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B3F8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8003B3FC: sh          $t6, 0x254C($t7)
    MEM_H(0X254C, ctx->r15) = ctx->r14;
    // 0x8003B400: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B404: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B408: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B40C: sw          $t8, 0x2550($t9)
    MEM_W(0X2550, ctx->r25) = ctx->r24;
    // 0x8003B410: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B414: nop

    // 0x8003B418: sw          $zero, 0x2554($t0)
    MEM_W(0X2554, ctx->r8) = 0;
    // 0x8003B41C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B420: nop

    // 0x8003B424: addiu       $t2, $t1, 0x240
    ctx->r10 = ADD32(ctx->r9, 0X240);
    // 0x8003B428: sw          $t2, 0x255C($t1)
    MEM_W(0X255C, ctx->r9) = ctx->r10;
    // 0x8003B42C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B430: nop

    // 0x8003B434: addiu       $a0, $t3, 0x1E0
    ctx->r4 = ADD32(ctx->r11, 0X1E0);
    // 0x8003B438: jal         0x800B34D0
    // 0x8003B43C: addiu       $a1, $t3, 0x254C
    ctx->r5 = ADD32(ctx->r11, 0X254C);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B43C: addiu       $a1, $t3, 0x254C
    ctx->r5 = ADD32(ctx->r11, 0X254C);
    after_0:
    // 0x8003B440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B448: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B44C: jal         0x800B3C20
    // 0x8003B450: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B450: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B454: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003B458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B45C: lw          $v0, 0x2554($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2554);
    // 0x8003B460: jr          $ra
    // 0x8003B464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003B464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_8003b468_motor_sendmsg_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B46C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B470: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003B474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B478: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B47C: lhu         $t7, 0x25AE($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X25AE);
    // 0x8003B480: nop

    // 0x8003B484: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8003B488: beq         $t8, $zero, L_8003B4C4
    if (ctx->r24 == 0) {
        // 0x8003B48C: nop
    
            goto L_8003B4C4;
    }
    // 0x8003B48C: nop

    // 0x8003B490: sh          $zero, 0x254C($t6)
    MEM_H(0X254C, ctx->r14) = 0;
    // 0x8003B494: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B498: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B49C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B4A0: sw          $t9, 0x2550($t0)
    MEM_W(0X2550, ctx->r8) = ctx->r25;
    // 0x8003B4A4: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B4A8: nop

    // 0x8003B4AC: sw          $zero, 0x2554($t1)
    MEM_W(0X2554, ctx->r9) = 0;
    // 0x8003B4B0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8003B4B4: nop

    // 0x8003B4B8: addiu       $a0, $t2, 0x1E0
    ctx->r4 = ADD32(ctx->r10, 0X1E0);
    // 0x8003B4BC: jal         0x800B34D0
    // 0x8003B4C0: addiu       $a1, $t2, 0x254C
    ctx->r5 = ADD32(ctx->r10, 0X254C);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B4C0: addiu       $a1, $t2, 0x254C
    ctx->r5 = ADD32(ctx->r10, 0X254C);
    after_0:
L_8003B4C4:
    // 0x8003B4C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B4C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B4CC: jr          $ra
    // 0x8003B4D0: nop

    return;
    // 0x8003B4D0: nop

;}

RECOMP_FUNC void FUN_001050_8003b4d4_motor_sendmsg_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B4D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B4D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B4DC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003B4E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B4E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B4E8: lhu         $t7, 0x25AE($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X25AE);
    // 0x8003B4EC: nop

    // 0x8003B4F0: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8003B4F4: beq         $t8, $zero, L_8003B534
    if (ctx->r24 == 0) {
        // 0x8003B4F8: nop
    
            goto L_8003B534;
    }
    // 0x8003B4F8: nop

    // 0x8003B4FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003B500: sh          $t9, 0x254C($t6)
    MEM_H(0X254C, ctx->r14) = ctx->r25;
    // 0x8003B504: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B508: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B50C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B510: sw          $t0, 0x2550($t1)
    MEM_W(0X2550, ctx->r9) = ctx->r8;
    // 0x8003B514: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8003B518: nop

    // 0x8003B51C: sw          $zero, 0x2554($t2)
    MEM_W(0X2554, ctx->r10) = 0;
    // 0x8003B520: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B524: nop

    // 0x8003B528: addiu       $a0, $t3, 0x1E0
    ctx->r4 = ADD32(ctx->r11, 0X1E0);
    // 0x8003B52C: jal         0x800B34D0
    // 0x8003B530: addiu       $a1, $t3, 0x254C
    ctx->r5 = ADD32(ctx->r11, 0X254C);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B530: addiu       $a1, $t3, 0x254C
    ctx->r5 = ADD32(ctx->r11, 0X254C);
    after_0:
L_8003B534:
    // 0x8003B534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B53C: jr          $ra
    // 0x8003B540: nop

    return;
    // 0x8003B540: nop

;}

RECOMP_FUNC void FUN_001050_8003b544_motor_sendmsg_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B544: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B548: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B54C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003B550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B554: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B558: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B55C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8003B560: lhu         $t7, 0x25AE($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X25AE);
    // 0x8003B564: nop

    // 0x8003B568: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8003B56C: beq         $t8, $zero, L_8003B5C0
    if (ctx->r24 == 0) {
        // 0x8003B570: nop
    
            goto L_8003B5C0;
    }
    // 0x8003B570: nop

    // 0x8003B574: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8003B578: sh          $t9, 0x254C($t6)
    MEM_H(0X254C, ctx->r14) = ctx->r25;
    // 0x8003B57C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B580: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B584: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B588: sw          $t0, 0x2550($t1)
    MEM_W(0X2550, ctx->r9) = ctx->r8;
    // 0x8003B58C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B590: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8003B594: nop

    // 0x8003B598: sw          $t2, 0x2554($t3)
    MEM_W(0X2554, ctx->r11) = ctx->r10;
    // 0x8003B59C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003B5A0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8003B5A4: nop

    // 0x8003B5A8: sw          $t4, 0x2558($t5)
    MEM_W(0X2558, ctx->r13) = ctx->r12;
    // 0x8003B5AC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B5B0: nop

    // 0x8003B5B4: addiu       $a0, $t7, 0x1E0
    ctx->r4 = ADD32(ctx->r15, 0X1E0);
    // 0x8003B5B8: jal         0x800B34D0
    // 0x8003B5BC: addiu       $a1, $t7, 0x254C
    ctx->r5 = ADD32(ctx->r15, 0X254C);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B5BC: addiu       $a1, $t7, 0x254C
    ctx->r5 = ADD32(ctx->r15, 0X254C);
    after_0:
L_8003B5C0:
    // 0x8003B5C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B5C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B5C8: jr          $ra
    // 0x8003B5CC: nop

    return;
    // 0x8003B5CC: nop

;}

RECOMP_FUNC void FUN_001050_8003b5d0_controller_sendrecvmsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B5D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B5D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B5D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003B5DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B5E0: sh          $zero, 0x2568($t6)
    MEM_H(0X2568, ctx->r14) = 0;
    // 0x8003B5E4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B5E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B5EC: addiu       $t8, $t7, 0x240
    ctx->r24 = ADD32(ctx->r15, 0X240);
    // 0x8003B5F0: sw          $t8, 0x2564($t7)
    MEM_W(0X2564, ctx->r15) = ctx->r24;
    // 0x8003B5F4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B5F8: nop

    // 0x8003B5FC: addiu       $t0, $t9, 0x2362
    ctx->r8 = ADD32(ctx->r25, 0X2362);
    // 0x8003B600: sw          $t0, 0x256C($t9)
    MEM_W(0X256C, ctx->r25) = ctx->r8;
    // 0x8003B604: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B608: nop

    // 0x8003B60C: addiu       $a0, $t1, 0x210
    ctx->r4 = ADD32(ctx->r9, 0X210);
    // 0x8003B610: jal         0x800B34D0
    // 0x8003B614: addiu       $a1, $t1, 0x2564
    ctx->r5 = ADD32(ctx->r9, 0X2564);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B614: addiu       $a1, $t1, 0x2564
    ctx->r5 = ADD32(ctx->r9, 0X2564);
    after_0:
    // 0x8003B618: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B61C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B620: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B624: jal         0x800B3C20
    // 0x8003B628: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B628: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B62C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B634: jr          $ra
    // 0x8003B638: nop

    return;
    // 0x8003B638: nop

;}

RECOMP_FUNC void FUN_001050_getControllerType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B63C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003B640: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8003B644: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8003B648: lhu         $v0, 0x2362($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X2362);
    // 0x8003B64C: jr          $ra
    // 0x8003B650: nop

    return;
    // 0x8003B650: nop

;}

RECOMP_FUNC void FUN_001050_getControllerStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B654: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003B658: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8003B65C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8003B660: lbu         $v0, 0x2364($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X2364);
    // 0x8003B664: jr          $ra
    // 0x8003B668: nop

    return;
    // 0x8003B668: nop

;}

RECOMP_FUNC void FUN_001050_getControllerErrNo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B66C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003B670: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8003B674: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8003B678: lbu         $v0, 0x2365($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X2365);
    // 0x8003B67C: jr          $ra
    // 0x8003B680: nop

    return;
    // 0x8003B680: nop

;}

RECOMP_FUNC void FUN_001050_cpakInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B688: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B68C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003B690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B694: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B698: sh          $zero, 0x2578($t6)
    MEM_H(0X2578, ctx->r14) = 0;
    // 0x8003B69C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8003B6A0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B6A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B6A8: sb          $t7, 0x2570($t8)
    MEM_B(0X2570, ctx->r24) = ctx->r15;
    // 0x8003B6AC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B6B0: nop

    // 0x8003B6B4: addiu       $a0, $t9, 0x1F8
    ctx->r4 = ADD32(ctx->r25, 0X1F8);
    // 0x8003B6B8: jal         0x800B34D0
    // 0x8003B6BC: addiu       $a1, $t9, 0x2570
    ctx->r5 = ADD32(ctx->r25, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B6BC: addiu       $a1, $t9, 0x2570
    ctx->r5 = ADD32(ctx->r25, 0X2570);
    after_0:
    // 0x8003B6C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B6C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B6C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B6CC: jal         0x800B3C20
    // 0x8003B6D0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B6D0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B6D4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B6DC: lw          $v0, 0x2580($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2580);
    // 0x8003B6E0: jr          $ra
    // 0x8003B6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003B6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_cpakRead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B6E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B6EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B6F0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B6F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B6FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B700: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8003B704: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003B708: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003B70C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B710: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x8003B714: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B718: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003B71C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B720: nop

    // 0x8003B724: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003B728: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003B72C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B730: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003B734: nop

    // 0x8003B738: sb          $t2, 0x2571($t3)
    MEM_B(0X2571, ctx->r11) = ctx->r10;
    // 0x8003B73C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003B740: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8003B744: nop

    // 0x8003B748: sw          $t4, 0x2580($t5)
    MEM_W(0X2580, ctx->r13) = ctx->r12;
    // 0x8003B74C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B750: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8003B754: nop

    // 0x8003B758: sw          $t6, 0x2574($t7)
    MEM_W(0X2574, ctx->r15) = ctx->r14;
    // 0x8003B75C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B760: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8003B764: nop

    // 0x8003B768: sw          $t8, 0x257C($t9)
    MEM_W(0X257C, ctx->r25) = ctx->r24;
    // 0x8003B76C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B770: nop

    // 0x8003B774: addiu       $a0, $t1, 0x1F8
    ctx->r4 = ADD32(ctx->r9, 0X1F8);
    // 0x8003B778: jal         0x800B34D0
    // 0x8003B77C: addiu       $a1, $t1, 0x2570
    ctx->r5 = ADD32(ctx->r9, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B77C: addiu       $a1, $t1, 0x2570
    ctx->r5 = ADD32(ctx->r9, 0X2570);
    after_0:
    // 0x8003B780: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B788: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B78C: jal         0x800B3C20
    // 0x8003B790: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B790: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B794: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B79C: lw          $v0, 0x2580($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2580);
    // 0x8003B7A0: jr          $ra
    // 0x8003B7A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003B7A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_cpakWrite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B7A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B7AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B7B0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B7B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B7B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B7BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B7C0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8003B7C4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003B7C8: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003B7CC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B7D0: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x8003B7D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B7D8: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003B7DC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B7E0: nop

    // 0x8003B7E4: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003B7E8: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003B7EC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B7F0: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003B7F4: nop

    // 0x8003B7F8: sb          $t2, 0x2571($t3)
    MEM_B(0X2571, ctx->r11) = ctx->r10;
    // 0x8003B7FC: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003B800: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8003B804: nop

    // 0x8003B808: sw          $t4, 0x2580($t5)
    MEM_W(0X2580, ctx->r13) = ctx->r12;
    // 0x8003B80C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B810: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8003B814: nop

    // 0x8003B818: sw          $t6, 0x2574($t7)
    MEM_W(0X2574, ctx->r15) = ctx->r14;
    // 0x8003B81C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B820: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8003B824: nop

    // 0x8003B828: sw          $t8, 0x257C($t9)
    MEM_W(0X257C, ctx->r25) = ctx->r24;
    // 0x8003B82C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003B830: nop

    // 0x8003B834: addiu       $a0, $t1, 0x1F8
    ctx->r4 = ADD32(ctx->r9, 0X1F8);
    // 0x8003B838: jal         0x800B34D0
    // 0x8003B83C: addiu       $a1, $t1, 0x2570
    ctx->r5 = ADD32(ctx->r9, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B83C: addiu       $a1, $t1, 0x2570
    ctx->r5 = ADD32(ctx->r9, 0X2570);
    after_0:
    // 0x8003B840: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B844: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B848: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B84C: jal         0x800B3C20
    // 0x8003B850: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B850: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B854: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B85C: lw          $v0, 0x2580($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2580);
    // 0x8003B860: jr          $ra
    // 0x8003B864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003B864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_cpakAllocFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B86C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B870: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B878: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B87C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B880: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8003B884: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003B888: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B88C: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x8003B890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B894: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003B898: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B89C: nop

    // 0x8003B8A0: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003B8A4: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003B8A8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B8AC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B8B0: nop

    // 0x8003B8B4: sw          $t2, 0x2588($t3)
    MEM_W(0X2588, ctx->r11) = ctx->r10;
    // 0x8003B8B8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003B8BC: nop

    // 0x8003B8C0: addiu       $a0, $t4, 0x1F8
    ctx->r4 = ADD32(ctx->r12, 0X1F8);
    // 0x8003B8C4: jal         0x800B34D0
    // 0x8003B8C8: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B8C8: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    after_0:
    // 0x8003B8CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B8D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B8D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B8D8: jal         0x800B3C20
    // 0x8003B8DC: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B8DC: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B8E0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003B8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B8E8: lw          $v0, 0x2580($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2580);
    // 0x8003B8EC: jr          $ra
    // 0x8003B8F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003B8F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_cpakFindFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B8F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B8F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B8FC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B900: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B904: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B908: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B90C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8003B910: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003B914: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B918: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x8003B91C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B920: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003B924: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B928: nop

    // 0x8003B92C: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003B930: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003B934: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B938: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B93C: nop

    // 0x8003B940: sw          $t2, 0x2588($t3)
    MEM_W(0X2588, ctx->r11) = ctx->r10;
    // 0x8003B944: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003B948: nop

    // 0x8003B94C: addiu       $a0, $t4, 0x1F8
    ctx->r4 = ADD32(ctx->r12, 0X1F8);
    // 0x8003B950: jal         0x800B34D0
    // 0x8003B954: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B954: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    after_0:
    // 0x8003B958: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B95C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B960: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B964: jal         0x800B3C20
    // 0x8003B968: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B968: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B96C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003B970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B974: lw          $v0, 0x2580($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2580);
    // 0x8003B978: jr          $ra
    // 0x8003B97C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003B97C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_cpakDeleteFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B988: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003B98C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B990: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B994: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B998: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8003B99C: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003B9A0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9A4: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x8003B9A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B9AC: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003B9B0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9B4: nop

    // 0x8003B9B8: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003B9BC: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003B9C0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9C4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B9C8: nop

    // 0x8003B9CC: sw          $t2, 0x2588($t3)
    MEM_W(0X2588, ctx->r11) = ctx->r10;
    // 0x8003B9D0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9D4: nop

    // 0x8003B9D8: addiu       $a0, $t4, 0x1F8
    ctx->r4 = ADD32(ctx->r12, 0X1F8);
    // 0x8003B9DC: jal         0x800B34D0
    // 0x8003B9E0: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003B9E0: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    after_0:
    // 0x8003B9E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003B9EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B9F0: jal         0x800B3C20
    // 0x8003B9F4: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B9F4: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003B9F8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BA00: lw          $v0, 0x2580($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2580);
    // 0x8003BA04: jr          $ra
    // 0x8003BA08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BA08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_cpakNumFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BA0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BA10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BA14: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BA1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BA20: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8003BA24: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003BA28: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA2C: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003BA30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BA34: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003BA38: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA3C: nop

    // 0x8003BA40: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003BA44: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003BA48: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA4C: nop

    // 0x8003BA50: addiu       $a0, $t2, 0x1F8
    ctx->r4 = ADD32(ctx->r10, 0X1F8);
    // 0x8003BA54: jal         0x800B34D0
    // 0x8003BA58: addiu       $a1, $t2, 0x2570
    ctx->r5 = ADD32(ctx->r10, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BA58: addiu       $a1, $t2, 0x2570
    ctx->r5 = ADD32(ctx->r10, 0X2570);
    after_0:
    // 0x8003BA5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BA64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BA68: jal         0x800B3C20
    // 0x8003BA6C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BA6C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BA70: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BA78: lw          $v0, 0x2580($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2580);
    // 0x8003BA7C: jr          $ra
    // 0x8003BA80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BA80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_cpakFileState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BA84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BA88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BA8C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BA90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BA94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BA98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003BA9C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8003BAA0: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8003BAA4: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003BAA8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BAAC: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x8003BAB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BAB4: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003BAB8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BABC: nop

    // 0x8003BAC0: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003BAC4: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003BAC8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BACC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BAD0: nop

    // 0x8003BAD4: sw          $t2, 0x2588($t3)
    MEM_W(0X2588, ctx->r11) = ctx->r10;
    // 0x8003BAD8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003BADC: lbu         $t4, 0x23($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X23);
    // 0x8003BAE0: nop

    // 0x8003BAE4: sb          $t4, 0x2571($t5)
    MEM_B(0X2571, ctx->r13) = ctx->r12;
    // 0x8003BAE8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003BAEC: nop

    // 0x8003BAF0: addiu       $a0, $t6, 0x1F8
    ctx->r4 = ADD32(ctx->r14, 0X1F8);
    // 0x8003BAF4: jal         0x800B34D0
    // 0x8003BAF8: addiu       $a1, $t6, 0x2570
    ctx->r5 = ADD32(ctx->r14, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BAF8: addiu       $a1, $t6, 0x2570
    ctx->r5 = ADD32(ctx->r14, 0X2570);
    after_0:
    // 0x8003BAFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BB04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BB08: jal         0x800B3C20
    // 0x8003BB0C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BB0C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BB10: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BB18: lw          $v0, 0x2580($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2580);
    // 0x8003BB1C: jr          $ra
    // 0x8003BB20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BB20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_cpakRepairId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BB24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BB28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BB2C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BB34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BB38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003BB3C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8003BB40: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003BB44: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB48: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x8003BB4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BB50: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003BB54: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB58: nop

    // 0x8003BB5C: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003BB60: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003BB64: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB68: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BB6C: nop

    // 0x8003BB70: sw          $t2, 0x2588($t3)
    MEM_W(0X2588, ctx->r11) = ctx->r10;
    // 0x8003BB74: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB78: nop

    // 0x8003BB7C: addiu       $a0, $t4, 0x1F8
    ctx->r4 = ADD32(ctx->r12, 0X1F8);
    // 0x8003BB80: jal         0x800B34D0
    // 0x8003BB84: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BB84: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    after_0:
    // 0x8003BB88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BB8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BB90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BB94: jal         0x800B3C20
    // 0x8003BB98: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BB98: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BB9C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003BBA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BBA4: lw          $v0, 0x2580($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2580);
    // 0x8003BBA8: jr          $ra
    // 0x8003BBAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BBAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_cpakFreeBlocks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BBB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BBB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BBB8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BBBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BBC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BBC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003BBC8: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8003BBCC: sh          $t6, 0x2578($t7)
    MEM_H(0X2578, ctx->r15) = ctx->r14;
    // 0x8003BBD0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BBD4: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x8003BBD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BBDC: sb          $t8, 0x2570($t9)
    MEM_B(0X2570, ctx->r25) = ctx->r24;
    // 0x8003BBE0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BBE4: nop

    // 0x8003BBE8: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003BBEC: sw          $t1, 0x2584($t0)
    MEM_W(0X2584, ctx->r8) = ctx->r9;
    // 0x8003BBF0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BBF4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BBF8: nop

    // 0x8003BBFC: sw          $t2, 0x2588($t3)
    MEM_W(0X2588, ctx->r11) = ctx->r10;
    // 0x8003BC00: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003BC04: nop

    // 0x8003BC08: addiu       $a0, $t4, 0x1F8
    ctx->r4 = ADD32(ctx->r12, 0X1F8);
    // 0x8003BC0C: jal         0x800B34D0
    // 0x8003BC10: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BC10: addiu       $a1, $t4, 0x2570
    ctx->r5 = ADD32(ctx->r12, 0X2570);
    after_0:
    // 0x8003BC14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BC18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BC1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BC20: jal         0x800B3C20
    // 0x8003BC24: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BC24: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BC28: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003BC2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BC30: lw          $v0, 0x2580($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2580);
    // 0x8003BC34: jr          $ra
    // 0x8003BC38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BC38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_gbpakInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BC3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BC40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BC44: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003BC48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BC4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BC50: sh          $zero, 0x2590($t6)
    MEM_H(0X2590, ctx->r14) = 0;
    // 0x8003BC54: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8003BC58: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003BC5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BC60: sb          $t7, 0x2592($t8)
    MEM_B(0X2592, ctx->r24) = ctx->r15;
    // 0x8003BC64: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BC68: nop

    // 0x8003BC6C: addiu       $t0, $t9, 0x240
    ctx->r8 = ADD32(ctx->r25, 0X240);
    // 0x8003BC70: sw          $t0, 0x25A4($t9)
    MEM_W(0X25A4, ctx->r25) = ctx->r8;
    // 0x8003BC74: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003BC78: nop

    // 0x8003BC7C: addiu       $a0, $t1, 0x228
    ctx->r4 = ADD32(ctx->r9, 0X228);
    // 0x8003BC80: jal         0x800B34D0
    // 0x8003BC84: addiu       $a1, $t1, 0x2590
    ctx->r5 = ADD32(ctx->r9, 0X2590);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BC84: addiu       $a1, $t1, 0x2590
    ctx->r5 = ADD32(ctx->r9, 0X2590);
    after_0:
    // 0x8003BC88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BC8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BC90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BC94: jal         0x800B3C20
    // 0x8003BC98: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BC98: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BC9C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8003BCA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BCA4: lw          $v0, 0x2594($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2594);
    // 0x8003BCA8: jr          $ra
    // 0x8003BCAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BCAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_gbpakReadId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BCB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BCB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BCB8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BCBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BCC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BCC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003BCC8: sh          $t6, 0x2590($t7)
    MEM_H(0X2590, ctx->r15) = ctx->r14;
    // 0x8003BCCC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BCD0: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003BCD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BCD8: sb          $t8, 0x2592($t9)
    MEM_B(0X2592, ctx->r25) = ctx->r24;
    // 0x8003BCDC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BCE0: nop

    // 0x8003BCE4: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003BCE8: sw          $t1, 0x25A4($t0)
    MEM_W(0X25A4, ctx->r8) = ctx->r9;
    // 0x8003BCEC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8003BCF0: nop

    // 0x8003BCF4: addiu       $a0, $t2, 0x228
    ctx->r4 = ADD32(ctx->r10, 0X228);
    // 0x8003BCF8: jal         0x800B34D0
    // 0x8003BCFC: addiu       $a1, $t2, 0x2590
    ctx->r5 = ADD32(ctx->r10, 0X2590);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BCFC: addiu       $a1, $t2, 0x2590
    ctx->r5 = ADD32(ctx->r10, 0X2590);
    after_0:
    // 0x8003BD00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BD04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BD08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BD0C: jal         0x800B3C20
    // 0x8003BD10: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BD10: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BD14: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BD18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BD1C: lw          $v0, 0x2594($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2594);
    // 0x8003BD20: jr          $ra
    // 0x8003BD24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BD24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_gbpakReadWrite_a(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BD28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BD2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BD30: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BD34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BD38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BD3C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003BD40: sh          $t6, 0x2590($t7)
    MEM_H(0X2590, ctx->r15) = ctx->r14;
    // 0x8003BD44: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BD48: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003BD4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BD50: sb          $t8, 0x2592($t9)
    MEM_B(0X2592, ctx->r25) = ctx->r24;
    // 0x8003BD54: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BD58: nop

    // 0x8003BD5C: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003BD60: sw          $t1, 0x25A4($t0)
    MEM_W(0X25A4, ctx->r8) = ctx->r9;
    // 0x8003BD64: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8003BD68: nop

    // 0x8003BD6C: addiu       $a0, $t2, 0x228
    ctx->r4 = ADD32(ctx->r10, 0X228);
    // 0x8003BD70: jal         0x800B34D0
    // 0x8003BD74: addiu       $a1, $t2, 0x2590
    ctx->r5 = ADD32(ctx->r10, 0X2590);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BD74: addiu       $a1, $t2, 0x2590
    ctx->r5 = ADD32(ctx->r10, 0X2590);
    after_0:
    // 0x8003BD78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BD7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BD80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BD84: jal         0x800B3C20
    // 0x8003BD88: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BD88: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BD8C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BD90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BD94: lw          $v0, 0x2594($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2594);
    // 0x8003BD98: jr          $ra
    // 0x8003BD9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BD9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_gbpakReadWrite_b(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BDA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BDA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BDA8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BDAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BDB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BDB4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8003BDB8: sh          $t6, 0x2590($t7)
    MEM_H(0X2590, ctx->r15) = ctx->r14;
    // 0x8003BDBC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BDC0: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003BDC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BDC8: sb          $t8, 0x2592($t9)
    MEM_B(0X2592, ctx->r25) = ctx->r24;
    // 0x8003BDCC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BDD0: nop

    // 0x8003BDD4: addiu       $t1, $t0, 0x240
    ctx->r9 = ADD32(ctx->r8, 0X240);
    // 0x8003BDD8: sw          $t1, 0x25A4($t0)
    MEM_W(0X25A4, ctx->r8) = ctx->r9;
    // 0x8003BDDC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8003BDE0: nop

    // 0x8003BDE4: addiu       $a0, $t2, 0x228
    ctx->r4 = ADD32(ctx->r10, 0X228);
    // 0x8003BDE8: jal         0x800B34D0
    // 0x8003BDEC: addiu       $a1, $t2, 0x2590
    ctx->r5 = ADD32(ctx->r10, 0X2590);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BDEC: addiu       $a1, $t2, 0x2590
    ctx->r5 = ADD32(ctx->r10, 0X2590);
    after_0:
    // 0x8003BDF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BDF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BDF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BDFC: jal         0x800B3C20
    // 0x8003BE00: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BE00: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BE04: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BE08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BE0C: lw          $v0, 0x2594($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2594);
    // 0x8003BE10: jr          $ra
    // 0x8003BE14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BE14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_gbpakReadWrite_c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BE18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BE20: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BE24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BE28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BE2C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003BE30: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8003BE34: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8003BE38: sh          $t6, 0x2590($t7)
    MEM_H(0X2590, ctx->r15) = ctx->r14;
    // 0x8003BE3C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BE40: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003BE44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BE48: sb          $t8, 0x2592($t9)
    MEM_B(0X2592, ctx->r25) = ctx->r24;
    // 0x8003BE4C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003BE50: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8003BE54: nop

    // 0x8003BE58: sw          $t0, 0x259C($t1)
    MEM_W(0X259C, ctx->r9) = ctx->r8;
    // 0x8003BE5C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BE60: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8003BE64: nop

    // 0x8003BE68: sw          $t2, 0x2598($t3)
    MEM_W(0X2598, ctx->r11) = ctx->r10;
    // 0x8003BE6C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003BE70: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8003BE74: nop

    // 0x8003BE78: sw          $t4, 0x2594($t5)
    MEM_W(0X2594, ctx->r13) = ctx->r12;
    // 0x8003BE7C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003BE80: nop

    // 0x8003BE84: sb          $zero, 0x25A0($t6)
    MEM_B(0X25A0, ctx->r14) = 0;
    // 0x8003BE88: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BE8C: nop

    // 0x8003BE90: addiu       $t8, $t7, 0x240
    ctx->r24 = ADD32(ctx->r15, 0X240);
    // 0x8003BE94: sw          $t8, 0x25A4($t7)
    MEM_W(0X25A4, ctx->r15) = ctx->r24;
    // 0x8003BE98: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BE9C: nop

    // 0x8003BEA0: addiu       $a0, $t9, 0x228
    ctx->r4 = ADD32(ctx->r25, 0X228);
    // 0x8003BEA4: jal         0x800B34D0
    // 0x8003BEA8: addiu       $a1, $t9, 0x2590
    ctx->r5 = ADD32(ctx->r25, 0X2590);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BEA8: addiu       $a1, $t9, 0x2590
    ctx->r5 = ADD32(ctx->r25, 0X2590);
    after_0:
    // 0x8003BEAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BEB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BEB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BEB8: jal         0x800B3C20
    // 0x8003BEBC: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BEBC: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BEC0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BEC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BEC8: lw          $v0, 0x2594($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2594);
    // 0x8003BECC: jr          $ra
    // 0x8003BED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void FUN_001050_gbpakReadWrite_d(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BED8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003BEDC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BEE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BEE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003BEE8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003BEEC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8003BEF0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8003BEF4: sh          $t6, 0x2590($t7)
    MEM_H(0X2590, ctx->r15) = ctx->r14;
    // 0x8003BEF8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8003BEFC: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003BF00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003BF04: sb          $t8, 0x2592($t9)
    MEM_B(0X2592, ctx->r25) = ctx->r24;
    // 0x8003BF08: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003BF0C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8003BF10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003BF14: sw          $t0, 0x259C($t1)
    MEM_W(0X259C, ctx->r9) = ctx->r8;
    // 0x8003BF18: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8003BF1C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8003BF20: nop

    // 0x8003BF24: sw          $t2, 0x2598($t3)
    MEM_W(0X2598, ctx->r11) = ctx->r10;
    // 0x8003BF28: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8003BF2C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8003BF30: nop

    // 0x8003BF34: sw          $t4, 0x2594($t5)
    MEM_W(0X2594, ctx->r13) = ctx->r12;
    // 0x8003BF38: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8003BF3C: nop

    // 0x8003BF40: sb          $t6, 0x25A0($t7)
    MEM_B(0X25A0, ctx->r15) = ctx->r14;
    // 0x8003BF44: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8003BF48: nop

    // 0x8003BF4C: addiu       $t9, $t8, 0x240
    ctx->r25 = ADD32(ctx->r24, 0X240);
    // 0x8003BF50: sw          $t9, 0x25A4($t8)
    MEM_W(0X25A4, ctx->r24) = ctx->r25;
    // 0x8003BF54: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8003BF58: nop

    // 0x8003BF5C: addiu       $a0, $t0, 0x228
    ctx->r4 = ADD32(ctx->r8, 0X228);
    // 0x8003BF60: jal         0x800B34D0
    // 0x8003BF64: addiu       $a1, $t0, 0x2590
    ctx->r5 = ADD32(ctx->r8, 0X2590);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8003BF64: addiu       $a1, $t0, 0x2590
    ctx->r5 = ADD32(ctx->r8, 0X2590);
    after_0:
    // 0x8003BF68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BF6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BF70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BF74: jal         0x800B3C20
    // 0x8003BF78: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BF78: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_1:
    // 0x8003BF7C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8003BF80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BF84: lw          $v0, 0x2594($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2594);
    // 0x8003BF88: jr          $ra
    // 0x8003BF8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003BF8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Controller_ServiceThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BF90: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8003BF94: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x8003BF98: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8003BF9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003BFA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003BFA4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003BFA8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003BFAC: sh          $zero, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = 0;
    // 0x8003BFB0: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
    // 0x8003BFB4: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x8003BFB8: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x8003BFBC: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x8003BFC0: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
    // 0x8003BFC4: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x8003BFC8: sb          $t6, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r14;
    // 0x8003BFCC: sw          $t7, 0x1F18($at)
    MEM_W(0X1F18, ctx->r1) = ctx->r15;
    // 0x8003BFD0: lw          $a0, 0x25A8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X25A8);
    // 0x8003BFD4: addiu       $a1, $t7, 0x354
    ctx->r5 = ADD32(ctx->r15, 0X354);
    // 0x8003BFD8: jal         0x8005ED58
    // 0x8003BFDC: addiu       $a2, $t7, 0x1B0
    ctx->r6 = ADD32(ctx->r15, 0X1B0);
    osScAddClient(rdram, ctx);
        goto after_0;
    // 0x8003BFDC: addiu       $a2, $t7, 0x1B0
    ctx->r6 = ADD32(ctx->r15, 0X1B0);
    after_0:
L_8003BFE0:
    // 0x8003BFE0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003BFE4: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003BFE8: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    // 0x8003BFEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BFF0: jal         0x800B3C20
    // 0x8003BFF4: addiu       $a0, $a0, 0x1B0
    ctx->r4 = ADD32(ctx->r4, 0X1B0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003BFF4: addiu       $a0, $a0, 0x1B0
    ctx->r4 = ADD32(ctx->r4, 0X1B0);
    after_1:
    // 0x8003BFF8: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8003BFFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003C000: lh          $s0, 0x0($t8)
    ctx->r16 = MEM_H(ctx->r24, 0X0);
    // 0x8003C004: nop

    // 0x8003C008: beq         $s0, $at, L_8003C020
    if (ctx->r16 == ctx->r1) {
        // 0x8003C00C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8003C020;
    }
    // 0x8003C00C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003C010: beq         $s0, $at, L_8003DB3C
    if (ctx->r16 == ctx->r1) {
        // 0x8003C014: nop
    
            goto L_8003DB3C;
    }
    // 0x8003C014: nop

    // 0x8003C018: b           L_8003BFE0
    // 0x8003C01C: nop

        goto L_8003BFE0;
    // 0x8003C01C: nop

L_8003C020:
    // 0x8003C020: lbu         $t9, 0x87($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X87);
    // 0x8003C024: nop

    // 0x8003C028: beq         $t9, $zero, L_8003BFE0
    if (ctx->r25 == 0) {
        // 0x8003C02C: nop
    
            goto L_8003BFE0;
    }
    // 0x8003C02C: nop

    // 0x8003C030: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C034: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C038: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
    // 0x8003C03C: jal         0x800B3D60
    // 0x8003C040: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    osContStartReadData_recomp(rdram, ctx);
        goto after_2;
    // 0x8003C040: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    after_2:
    // 0x8003C044: bne         $v0, $zero, L_8003C108
    if (ctx->r2 != 0) {
        // 0x8003C048: nop
    
            goto L_8003C108;
    }
    // 0x8003C048: nop

    // 0x8003C04C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003C050: lw          $t0, 0x1F18($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F18);
    // 0x8003C054: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C058: addiu       $a0, $t0, 0x258
    ctx->r4 = ADD32(ctx->r8, 0X258);
    // 0x8003C05C: jal         0x800B3C20
    // 0x8003C060: addiu       $a1, $t0, 0x334
    ctx->r5 = ADD32(ctx->r8, 0X334);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8003C060: addiu       $a1, $t0, 0x334
    ctx->r5 = ADD32(ctx->r8, 0X334);
    after_3:
    // 0x8003C064: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8003C068: lw          $t1, 0x1F18($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1F18);
    // 0x8003C06C: sh          $zero, 0x84($sp)
    MEM_H(0X84, ctx->r29) = 0;
    // 0x8003C070: lbu         $t2, 0x25AC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X25AC);
    // 0x8003C074: nop

    // 0x8003C078: blez        $t2, L_8003C108
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8003C07C: nop
    
            goto L_8003C108;
    }
    // 0x8003C07C: nop

L_8003C080:
    // 0x8003C080: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C084: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C088: jal         0x800B3DE4
    // 0x8003C08C: addiu       $a0, $a0, 0x2372
    ctx->r4 = ADD32(ctx->r4, 0X2372);
    osContGetReadData_recomp(rdram, ctx);
        goto after_4;
    // 0x8003C08C: addiu       $a0, $a0, 0x2372
    ctx->r4 = ADD32(ctx->r4, 0X2372);
    after_4:
    // 0x8003C090: lh          $t4, 0x84($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X84);
    // 0x8003C094: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8003C098: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8003C09C: lw          $t3, 0x1F18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F18);
    // 0x8003C0A0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8003C0A4: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8003C0A8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8003C0AC: addiu       $t7, $t6, 0x2372
    ctx->r15 = ADD32(ctx->r14, 0X2372);
    // 0x8003C0B0: sw          $t7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r15;
    // 0x8003C0B4: lw          $t8, 0x2610($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X2610);
    // 0x8003C0B8: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8003C0BC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8003C0C0: beq         $t0, $zero, L_8003C0DC
    if (ctx->r8 == 0) {
        // 0x8003C0C4: nop
    
            goto L_8003C0DC;
    }
    // 0x8003C0C4: nop

    // 0x8003C0C8: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x8003C0CC: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8003C0D0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8003C0D4: jal         0x800A3300
    // 0x8003C0D8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    FUN_069580_800A3300_nineliner_mod300(rdram, ctx);
        goto after_5;
    // 0x8003C0D8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_5:
L_8003C0DC:
    // 0x8003C0DC: lh          $t5, 0x84($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X84);
    // 0x8003C0E0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003C0E4: lw          $t0, 0x1F18($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F18);
    // 0x8003C0E8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8003C0EC: sh          $t6, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r14;
    // 0x8003C0F0: lbu         $t4, 0x25AC($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X25AC);
    // 0x8003C0F4: sll         $t3, $t6, 16
    ctx->r11 = S32(ctx->r14 << 16);
    // 0x8003C0F8: sra         $t9, $t3, 16
    ctx->r25 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8003C0FC: slt         $at, $t9, $t4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003C100: bne         $at, $zero, L_8003C080
    if (ctx->r1 != 0) {
        // 0x8003C104: nop
    
            goto L_8003C080;
    }
    // 0x8003C104: nop

L_8003C108:
    // 0x8003C108: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C10C: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C110: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x8003C114: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003C118: jal         0x800B3C20
    // 0x8003C11C: addiu       $a0, $a0, 0x210
    ctx->r4 = ADD32(ctx->r4, 0X210);
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x8003C11C: addiu       $a0, $a0, 0x210
    ctx->r4 = ADD32(ctx->r4, 0X210);
    after_6:
    // 0x8003C120: bne         $v0, $zero, L_8003C194
    if (ctx->r2 != 0) {
        // 0x8003C124: nop
    
            goto L_8003C194;
    }
    // 0x8003C124: nop

    // 0x8003C128: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x8003C12C: nop

    // 0x8003C130: lhu         $t1, 0x4($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X4);
    // 0x8003C134: nop

    // 0x8003C138: bne         $t1, $zero, L_8003C194
    if (ctx->r9 != 0) {
        // 0x8003C13C: nop
    
            goto L_8003C194;
    }
    // 0x8003C13C: nop

    // 0x8003C140: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C144: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C148: jal         0x800B3F40
    // 0x8003C14C: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    osContStartQuery_recomp(rdram, ctx);
        goto after_7;
    // 0x8003C14C: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    after_7:
    // 0x8003C150: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C154: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003C15C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C160: jal         0x800B3C20
    // 0x8003C164: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    osRecvMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x8003C164: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    after_8:
    // 0x8003C168: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x8003C16C: nop

    // 0x8003C170: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    // 0x8003C174: jal         0x800B3FC4
    // 0x8003C178: nop

    osContGetQuery_recomp(rdram, ctx);
        goto after_9;
    // 0x8003C178: nop

    after_9:
    // 0x8003C17C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C180: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C184: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003C188: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C18C: jal         0x800B34D0
    // 0x8003C190: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x8003C190: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_10:
L_8003C194:
    // 0x8003C194: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C198: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C19C: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x8003C1A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003C1A4: jal         0x800B3C20
    // 0x8003C1A8: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x8003C1A8: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    after_11:
    // 0x8003C1AC: bne         $v0, $zero, L_8003C3A8
    if (ctx->r2 != 0) {
        // 0x8003C1B0: nop
    
            goto L_8003C3A8;
    }
    // 0x8003C1B0: nop

    // 0x8003C1B4: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x8003C1B8: nop

    // 0x8003C1BC: lhu         $s0, 0x0($t7)
    ctx->r16 = MEM_HU(ctx->r15, 0X0);
    // 0x8003C1C0: nop

    // 0x8003C1C4: beq         $s0, $zero, L_8003C2F0
    if (ctx->r16 == 0) {
        // 0x8003C1C8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8003C2F0;
    }
    // 0x8003C1C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003C1CC: beq         $s0, $at, L_8003C270
    if (ctx->r16 == ctx->r1) {
        // 0x8003C1D0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003C270;
    }
    // 0x8003C1D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003C1D4: beq         $s0, $at, L_8003C36C
    if (ctx->r16 == ctx->r1) {
        // 0x8003C1D8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003C36C;
    }
    // 0x8003C1D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003C1DC: bne         $s0, $at, L_8003C3A8
    if (ctx->r16 != ctx->r1) {
        // 0x8003C1E0: nop
    
            goto L_8003C3A8;
    }
    // 0x8003C1E0: nop

    // 0x8003C1E4: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8003C1E8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8003C1EC: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x8003C1F0: lw          $t5, 0x1F18($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F18);
    // 0x8003C1F4: sll         $t0, $t3, 2
    ctx->r8 = S32(ctx->r11 << 2);
    // 0x8003C1F8: subu        $t0, $t0, $t3
    ctx->r8 = SUB32(ctx->r8, ctx->r11);
    // 0x8003C1FC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003C200: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x8003C204: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8003C208: addu        $a1, $t5, $t0
    ctx->r5 = ADD32(ctx->r13, ctx->r8);
    // 0x8003C20C: addiu       $a1, $a1, 0x238C
    ctx->r5 = ADD32(ctx->r5, 0X238C);
    // 0x8003C210: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8003C214: jal         0x800B3A84
    // 0x8003C218: addiu       $a0, $t5, 0x258
    ctx->r4 = ADD32(ctx->r13, 0X258);
    osMotorInit_recomp(rdram, ctx);
        goto after_12;
    // 0x8003C218: addiu       $a0, $t5, 0x258
    ctx->r4 = ADD32(ctx->r13, 0X258);
    after_12:
    // 0x8003C21C: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x8003C220: nop

    // 0x8003C224: sw          $v0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r2;
    // 0x8003C228: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x8003C22C: nop

    // 0x8003C230: lw          $t8, 0x8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X8);
    // 0x8003C234: nop

    // 0x8003C238: beq         $t8, $zero, L_8003C250
    if (ctx->r24 == 0) {
        // 0x8003C23C: nop
    
            goto L_8003C250;
    }
    // 0x8003C23C: nop

    // 0x8003C240: sll         $t1, $t8, 4
    ctx->r9 = S32(ctx->r24 << 4);
    // 0x8003C244: andi        $t2, $t1, 0xF0
    ctx->r10 = ctx->r9 & 0XF0;
    // 0x8003C248: ori         $t7, $t2, 0xF
    ctx->r15 = ctx->r10 | 0XF;
    // 0x8003C24C: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
L_8003C250:
    // 0x8003C250: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C254: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003C25C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C260: jal         0x800B34D0
    // 0x8003C264: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_13;
    // 0x8003C264: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_13:
    // 0x8003C268: b           L_8003C3A8
    // 0x8003C26C: nop

        goto L_8003C3A8;
    // 0x8003C26C: nop

L_8003C270:
    // 0x8003C270: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x8003C274: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8003C278: lw          $t0, 0x4($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X4);
    // 0x8003C27C: lw          $t6, 0x1F18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F18);
    // 0x8003C280: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8003C284: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x8003C288: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8003C28C: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x8003C290: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8003C294: addu        $a0, $t6, $t3
    ctx->r4 = ADD32(ctx->r14, ctx->r11);
    // 0x8003C298: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003C29C: jal         0x800B3810
    // 0x8003C2A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    __osMotorAccess_recomp(rdram, ctx);
        goto after_14;
    // 0x8003C2A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x8003C2A4: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x8003C2A8: sh          $v0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r2;
    // 0x8003C2AC: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8003C2B0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8003C2B4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8003C2B8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8003C2BC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8003C2C0: lw          $t9, 0x1F18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1F18);
    // 0x8003C2C4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8003C2C8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8003C2CC: addu        $a0, $t9, $t2
    ctx->r4 = ADD32(ctx->r25, ctx->r10);
    // 0x8003C2D0: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003C2D4: jal         0x800B3810
    // 0x8003C2D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    __osMotorAccess_recomp(rdram, ctx);
        goto after_15;
    // 0x8003C2D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x8003C2DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003C2E0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C2E4: sh          $v0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r2;
    // 0x8003C2E8: b           L_8003C3A8
    // 0x8003C2EC: sb          $t7, 0x5590($at)
    MEM_B(0X5590, ctx->r1) = ctx->r15;
        goto L_8003C3A8;
    // 0x8003C2EC: sb          $t7, 0x5590($at)
    MEM_B(0X5590, ctx->r1) = ctx->r15;
L_8003C2F0:
    // 0x8003C2F0: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x8003C2F4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C2F8: sb          $zero, 0x5590($at)
    MEM_B(0X5590, ctx->r1) = 0;
    // 0x8003C2FC: lw          $t0, 0x4($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X4);
    // 0x8003C300: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8003C304: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8003C308: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x8003C30C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003C310: lw          $t4, 0x1F18($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F18);
    // 0x8003C314: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x8003C318: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8003C31C: addu        $a0, $t4, $t6
    ctx->r4 = ADD32(ctx->r12, ctx->r14);
    // 0x8003C320: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003C324: jal         0x800B3810
    // 0x8003C328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_16;
    // 0x8003C328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x8003C32C: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x8003C330: sh          $v0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r2;
    // 0x8003C334: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8003C338: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8003C33C: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8003C340: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x8003C344: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8003C348: lw          $t3, 0x1F18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F18);
    // 0x8003C34C: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x8003C350: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8003C354: addu        $a0, $t3, $t9
    ctx->r4 = ADD32(ctx->r11, ctx->r25);
    // 0x8003C358: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003C35C: jal         0x800B3810
    // 0x8003C360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_17;
    // 0x8003C360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x8003C364: b           L_8003C3A8
    // 0x8003C368: sh          $v0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r2;
        goto L_8003C3A8;
    // 0x8003C368: sh          $v0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r2;
L_8003C36C:
    // 0x8003C36C: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x8003C370: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003C374: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8003C378: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C37C: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x8003C380: lw          $t5, 0x8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8);
    // 0x8003C384: nop

    // 0x8003C388: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x8003C38C: lw          $t0, 0xC($t2)
    ctx->r8 = MEM_W(ctx->r10, 0XC);
    // 0x8003C390: sb          $t4, 0x5590($at)
    MEM_B(0X5590, ctx->r1) = ctx->r12;
    // 0x8003C394: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C398: sb          $zero, 0x5598($at)
    MEM_B(0X5598, ctx->r1) = 0;
    // 0x8003C39C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C3A0: sb          $zero, 0x5594($at)
    MEM_B(0X5594, ctx->r1) = 0;
    // 0x8003C3A4: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
L_8003C3A8:
    // 0x8003C3A8: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8003C3AC: lbu         $t6, 0x5590($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5590);
    // 0x8003C3B0: nop

    // 0x8003C3B4: beq         $t6, $zero, L_8003C5E0
    if (ctx->r14 == 0) {
        // 0x8003C3B8: nop
    
            goto L_8003C5E0;
    }
    // 0x8003C3B8: nop

    // 0x8003C3BC: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8003C3C0: lbu         $t8, 0x5594($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5594);
    // 0x8003C3C4: nop

    // 0x8003C3C8: bne         $t8, $zero, L_8003C5CC
    if (ctx->r24 != 0) {
        // 0x8003C3CC: nop
    
            goto L_8003C5CC;
    }
    // 0x8003C3CC: nop

    // 0x8003C3D0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8003C3D4: lbu         $t1, 0x5598($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X5598);
    // 0x8003C3D8: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x8003C3DC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C3E0: addu        $t9, $t1, $t3
    ctx->r25 = ADD32(ctx->r9, ctx->r11);
    // 0x8003C3E4: lbu         $t7, 0x0($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X0);
    // 0x8003C3E8: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x8003C3EC: sb          $t7, 0x5594($at)
    MEM_B(0X5594, ctx->r1) = ctx->r15;
    // 0x8003C3F0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C3F4: addiu       $t5, $t1, 0x1
    ctx->r13 = ADD32(ctx->r9, 0X1);
    // 0x8003C3F8: beq         $t2, $zero, L_8003C430
    if (ctx->r10 == 0) {
        // 0x8003C3FC: sb          $t5, 0x5598($at)
        MEM_B(0X5598, ctx->r1) = ctx->r13;
            goto L_8003C430;
    }
    // 0x8003C3FC: sb          $t5, 0x5598($at)
    MEM_B(0X5598, ctx->r1) = ctx->r13;
    // 0x8003C400: andi        $t0, $t5, 0xFF
    ctx->r8 = ctx->r13 & 0XFF;
    // 0x8003C404: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8003C408: beq         $at, $zero, L_8003C4C8
    if (ctx->r1 == 0) {
        // 0x8003C40C: lui         $at, 0x800C
        ctx->r1 = S32(0X800C << 16);
            goto L_8003C4C8;
    }
    // 0x8003C40C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C410: sb          $zero, 0x5598($at)
    MEM_B(0X5598, ctx->r1) = 0;
    // 0x8003C414: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8003C418: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C41C: sb          $t4, 0x5594($at)
    MEM_B(0X5594, ctx->r1) = ctx->r12;
    // 0x8003C420: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C424: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003C428: b           L_8003C4C8
    // 0x8003C42C: sb          $t6, 0x5598($at)
    MEM_B(0X5598, ctx->r1) = ctx->r14;
        goto L_8003C4C8;
    // 0x8003C42C: sb          $t6, 0x5598($at)
    MEM_B(0X5598, ctx->r1) = ctx->r14;
L_8003C430:
    // 0x8003C430: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8003C434: lbu         $t8, 0x5594($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5594);
    // 0x8003C438: nop

    // 0x8003C43C: bne         $t8, $zero, L_8003C4C8
    if (ctx->r24 != 0) {
        // 0x8003C440: nop
    
            goto L_8003C4C8;
    }
    // 0x8003C440: nop

    // 0x8003C444: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8003C448: lbu         $t9, 0x5598($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X5598);
    // 0x8003C44C: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8003C450: nop

    // 0x8003C454: addu        $t1, $t9, $t7
    ctx->r9 = ADD32(ctx->r25, ctx->r15);
    // 0x8003C458: lbu         $t5, 0x0($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X0);
    // 0x8003C45C: nop

    // 0x8003C460: bne         $t5, $zero, L_8003C4A4
    if (ctx->r13 != 0) {
        // 0x8003C464: nop
    
            goto L_8003C4A4;
    }
    // 0x8003C464: nop

    // 0x8003C468: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x8003C46C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C470: sb          $zero, 0x5590($at)
    MEM_B(0X5590, ctx->r1) = 0;
    // 0x8003C474: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8003C478: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003C47C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8003C480: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8003C484: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8003C488: lw          $t0, 0x1F18($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F18);
    // 0x8003C48C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8003C490: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8003C494: addu        $a0, $t0, $t4
    ctx->r4 = ADD32(ctx->r8, ctx->r12);
    // 0x8003C498: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003C49C: jal         0x800B3810
    // 0x8003C4A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_18;
    // 0x8003C4A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
L_8003C4A4:
    // 0x8003C4A4: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8003C4A8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C4AC: sb          $zero, 0x5598($at)
    MEM_B(0X5598, ctx->r1) = 0;
    // 0x8003C4B0: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x8003C4B4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C4B8: sb          $t8, 0x5594($at)
    MEM_B(0X5594, ctx->r1) = ctx->r24;
    // 0x8003C4BC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C4C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003C4C4: sb          $t9, 0x5598($at)
    MEM_B(0X5598, ctx->r1) = ctx->r25;
L_8003C4C8:
    // 0x8003C4C8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8003C4CC: lbu         $t7, 0x5590($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X5590);
    // 0x8003C4D0: nop

    // 0x8003C4D4: beq         $t7, $zero, L_8003C5CC
    if (ctx->r15 == 0) {
        // 0x8003C4D8: nop
    
            goto L_8003C5CC;
    }
    // 0x8003C4D8: nop

    // 0x8003C4DC: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8003C4E0: lbu         $t1, 0x5598($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X5598);
    // 0x8003C4E4: nop

    // 0x8003C4E8: bgez        $t1, L_8003C4FC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8003C4EC: andi        $t5, $t1, 0x1
        ctx->r13 = ctx->r9 & 0X1;
            goto L_8003C4FC;
    }
    // 0x8003C4EC: andi        $t5, $t1, 0x1
    ctx->r13 = ctx->r9 & 0X1;
    // 0x8003C4F0: beq         $t5, $zero, L_8003C4FC
    if (ctx->r13 == 0) {
        // 0x8003C4F4: nop
    
            goto L_8003C4FC;
    }
    // 0x8003C4F4: nop

    // 0x8003C4F8: addiu       $t5, $t5, -0x2
    ctx->r13 = ADD32(ctx->r13, -0X2);
L_8003C4FC:
    // 0x8003C4FC: beq         $t5, $zero, L_8003C56C
    if (ctx->r13 == 0) {
        // 0x8003C500: nop
    
            goto L_8003C56C;
    }
    // 0x8003C500: nop

    // 0x8003C504: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8003C508: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8003C50C: sll         $t0, $t3, 2
    ctx->r8 = S32(ctx->r11 << 2);
    // 0x8003C510: subu        $t0, $t0, $t3
    ctx->r8 = SUB32(ctx->r8, ctx->r11);
    // 0x8003C514: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003C518: lw          $t2, 0x1F18($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1F18);
    // 0x8003C51C: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x8003C520: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8003C524: addu        $a0, $t2, $t0
    ctx->r4 = ADD32(ctx->r10, ctx->r8);
    // 0x8003C528: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003C52C: jal         0x800B3810
    // 0x8003C530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    __osMotorAccess_recomp(rdram, ctx);
        goto after_19;
    // 0x8003C530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x8003C534: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8003C538: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8003C53C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8003C540: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8003C544: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8003C548: lw          $t4, 0x1F18($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F18);
    // 0x8003C54C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8003C550: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8003C554: addu        $a0, $t4, $t8
    ctx->r4 = ADD32(ctx->r12, ctx->r24);
    // 0x8003C558: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003C55C: jal         0x800B3810
    // 0x8003C560: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    __osMotorAccess_recomp(rdram, ctx);
        goto after_20;
    // 0x8003C560: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x8003C564: b           L_8003C5CC
    // 0x8003C568: nop

        goto L_8003C5CC;
    // 0x8003C568: nop

L_8003C56C:
    // 0x8003C56C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8003C570: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8003C574: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x8003C578: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x8003C57C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8003C580: lw          $t9, 0x1F18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1F18);
    // 0x8003C584: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x8003C588: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8003C58C: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x8003C590: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003C594: jal         0x800B3810
    // 0x8003C598: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_21;
    // 0x8003C598: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x8003C59C: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8003C5A0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8003C5A4: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x8003C5A8: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8003C5AC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8003C5B0: lw          $t5, 0x1F18($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F18);
    // 0x8003C5B4: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x8003C5B8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8003C5BC: addu        $a0, $t5, $t2
    ctx->r4 = ADD32(ctx->r13, ctx->r10);
    // 0x8003C5C0: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003C5C4: jal         0x800B3810
    // 0x8003C5C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_22;
    // 0x8003C5C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
L_8003C5CC:
    // 0x8003C5CC: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8003C5D0: lbu         $t0, 0x5594($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X5594);
    // 0x8003C5D4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8003C5D8: addiu       $t6, $t0, -0x1
    ctx->r14 = ADD32(ctx->r8, -0X1);
    // 0x8003C5DC: sb          $t6, 0x5594($at)
    MEM_B(0X5594, ctx->r1) = ctx->r14;
L_8003C5E0:
    // 0x8003C5E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C5E4: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C5E8: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8003C5EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003C5F0: jal         0x800B3C20
    // 0x8003C5F4: addiu       $a0, $a0, 0x1C8
    ctx->r4 = ADD32(ctx->r4, 0X1C8);
    osRecvMesg_recomp(rdram, ctx);
        goto after_23;
    // 0x8003C5F4: addiu       $a0, $a0, 0x1C8
    ctx->r4 = ADD32(ctx->r4, 0X1C8);
    after_23:
    // 0x8003C5F8: bne         $v0, $zero, L_8003C800
    if (ctx->r2 != 0) {
        // 0x8003C5FC: nop
    
            goto L_8003C800;
    }
    // 0x8003C5FC: nop

    // 0x8003C600: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x8003C604: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003C608: lhu         $s0, 0x0($t4)
    ctx->r16 = MEM_HU(ctx->r12, 0X0);
    // 0x8003C60C: nop

    // 0x8003C610: beq         $s0, $at, L_8003C628
    if (ctx->r16 == ctx->r1) {
        // 0x8003C614: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003C628;
    }
    // 0x8003C614: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003C618: beq         $s0, $at, L_8003C700
    if (ctx->r16 == ctx->r1) {
        // 0x8003C61C: nop
    
            goto L_8003C700;
    }
    // 0x8003C61C: nop

    // 0x8003C620: b           L_8003C800
    // 0x8003C624: nop

        goto L_8003C800;
    // 0x8003C624: nop

L_8003C628:
    // 0x8003C628: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8003C62C: lw          $t8, 0x1F10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F10);
    // 0x8003C630: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8003C634: bgez        $t8, L_8003C644
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8003C638: sra         $t7, $t8, 3
        ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
            goto L_8003C644;
    }
    // 0x8003C638: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8003C63C: addiu       $at, $t8, 0x7
    ctx->r1 = ADD32(ctx->r24, 0X7);
    // 0x8003C640: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_8003C644:
    // 0x8003C644: blez        $t7, L_8003C6F0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8003C648: nop
    
            goto L_8003C6F0;
    }
    // 0x8003C648: nop

L_8003C64C:
    // 0x8003C64C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8003C650: lw          $t9, 0x1F18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1F18);
    // 0x8003C654: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8003C658: lw          $t1, 0x25B4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X25B4);
    // 0x8003C65C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003C660: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x8003C664: lbu         $t2, 0x0($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0X0);
    // 0x8003C668: nop

    // 0x8003C66C: bne         $t2, $at, L_8003C6BC
    if (ctx->r10 != ctx->r1) {
        // 0x8003C670: nop
    
            goto L_8003C6BC;
    }
    // 0x8003C670: nop

    // 0x8003C674: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x8003C678: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003C67C: lw          $t0, 0x1F18($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F18);
    // 0x8003C680: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8003C684: lw          $t4, 0x25BC($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X25BC);
    // 0x8003C688: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x8003C68C: addiu       $a0, $t0, 0x258
    ctx->r4 = ADD32(ctx->r8, 0X258);
    // 0x8003C690: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8003C694: jal         0x800B3FF0
    // 0x8003C698: addu        $a2, $t4, $t8
    ctx->r6 = ADD32(ctx->r12, ctx->r24);
    osEepromWrite_recomp(rdram, ctx);
        goto after_24;
    // 0x8003C698: addu        $a2, $t4, $t8
    ctx->r6 = ADD32(ctx->r12, ctx->r24);
    after_24:
    // 0x8003C69C: bne         $v0, $zero, L_8003C6F0
    if (ctx->r2 != 0) {
        // 0x8003C6A0: nop
    
            goto L_8003C6F0;
    }
    // 0x8003C6A0: nop

    // 0x8003C6A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C6A8: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C6AC: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8003C6B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C6B4: jal         0x800B3C20
    // 0x8003C6B8: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    osRecvMesg_recomp(rdram, ctx);
        goto after_25;
    // 0x8003C6B8: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    after_25:
L_8003C6BC:
    // 0x8003C6BC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8003C6C0: lw          $t1, 0x1F10($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1F10);
    // 0x8003C6C4: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8003C6C8: nop

    // 0x8003C6CC: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8003C6D0: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8003C6D4: bgez        $t1, L_8003C6E4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8003C6D8: sra         $t3, $t1, 3
        ctx->r11 = S32(SIGNED(ctx->r9) >> 3);
            goto L_8003C6E4;
    }
    // 0x8003C6D8: sra         $t3, $t1, 3
    ctx->r11 = S32(SIGNED(ctx->r9) >> 3);
    // 0x8003C6DC: addiu       $at, $t1, 0x7
    ctx->r1 = ADD32(ctx->r9, 0X7);
    // 0x8003C6E0: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8003C6E4:
    // 0x8003C6E4: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8003C6E8: bne         $at, $zero, L_8003C64C
    if (ctx->r1 != 0) {
        // 0x8003C6EC: nop
    
            goto L_8003C64C;
    }
    // 0x8003C6EC: nop

L_8003C6F0:
    // 0x8003C6F0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8003C6F4: lw          $t2, 0x1F18($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1F18);
    // 0x8003C6F8: b           L_8003C800
    // 0x8003C6FC: sb          $zero, 0x25B9($t2)
    MEM_B(0X25B9, ctx->r10) = 0;
        goto L_8003C800;
    // 0x8003C6FC: sb          $zero, 0x25B9($t2)
    MEM_B(0X25B9, ctx->r10) = 0;
L_8003C700:
    // 0x8003C700: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8003C704: lw          $t5, 0x1F10($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F10);
    // 0x8003C708: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8003C70C: bgez        $t5, L_8003C71C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8003C710: sra         $t0, $t5, 3
        ctx->r8 = S32(SIGNED(ctx->r13) >> 3);
            goto L_8003C71C;
    }
    // 0x8003C710: sra         $t0, $t5, 3
    ctx->r8 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8003C714: addiu       $at, $t5, 0x7
    ctx->r1 = ADD32(ctx->r13, 0X7);
    // 0x8003C718: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_8003C71C:
    // 0x8003C71C: blez        $t0, L_8003C79C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8003C720: nop
    
            goto L_8003C79C;
    }
    // 0x8003C720: nop

L_8003C724:
    // 0x8003C724: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8003C728: lw          $t6, 0x1F18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F18);
    // 0x8003C72C: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8003C730: lw          $t8, 0x25BC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X25BC);
    // 0x8003C734: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x8003C738: addiu       $a0, $t6, 0x258
    ctx->r4 = ADD32(ctx->r14, 0X258);
    // 0x8003C73C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x8003C740: jal         0x800B43C0
    // 0x8003C744: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    osEepromRead_recomp(rdram, ctx);
        goto after_26;
    // 0x8003C744: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    after_26:
    // 0x8003C748: bne         $v0, $zero, L_8003C79C
    if (ctx->r2 != 0) {
        // 0x8003C74C: nop
    
            goto L_8003C79C;
    }
    // 0x8003C74C: nop

    // 0x8003C750: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C754: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C758: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8003C75C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C760: jal         0x800B3C20
    // 0x8003C764: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    osRecvMesg_recomp(rdram, ctx);
        goto after_27;
    // 0x8003C764: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    after_27:
    // 0x8003C768: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8003C76C: lw          $t3, 0x1F10($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F10);
    // 0x8003C770: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8003C774: nop

    // 0x8003C778: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x8003C77C: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8003C780: bgez        $t3, L_8003C790
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8003C784: sra         $t2, $t3, 3
        ctx->r10 = S32(SIGNED(ctx->r11) >> 3);
            goto L_8003C790;
    }
    // 0x8003C784: sra         $t2, $t3, 3
    ctx->r10 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8003C788: addiu       $at, $t3, 0x7
    ctx->r1 = ADD32(ctx->r11, 0X7);
    // 0x8003C78C: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_8003C790:
    // 0x8003C790: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003C794: bne         $at, $zero, L_8003C724
    if (ctx->r1 != 0) {
        // 0x8003C798: nop
    
            goto L_8003C724;
    }
    // 0x8003C798: nop

L_8003C79C:
    // 0x8003C79C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8003C7A0: lw          $t5, 0x1F10($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F10);
    // 0x8003C7A4: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8003C7A8: blez        $t5, L_8003C7F0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8003C7AC: nop
    
            goto L_8003C7F0;
    }
    // 0x8003C7AC: nop

L_8003C7B0:
    // 0x8003C7B0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003C7B4: lw          $t0, 0x1F18($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F18);
    // 0x8003C7B8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8003C7BC: lw          $t6, 0x25BC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X25BC);
    // 0x8003C7C0: lw          $t1, 0x25B0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X25B0);
    // 0x8003C7C4: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x8003C7C8: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x8003C7CC: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x8003C7D0: sb          $t7, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r15;
    // 0x8003C7D4: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8003C7D8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8003C7DC: lw          $t5, 0x1F10($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F10);
    // 0x8003C7E0: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8003C7E4: slt         $at, $t2, $t5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8003C7E8: bne         $at, $zero, L_8003C7B0
    if (ctx->r1 != 0) {
        // 0x8003C7EC: sw          $t2, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r10;
            goto L_8003C7B0;
    }
    // 0x8003C7EC: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
L_8003C7F0:
    // 0x8003C7F0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8003C7F4: lw          $t6, 0x1F18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F18);
    // 0x8003C7F8: nop

    // 0x8003C7FC: sb          $zero, 0x25B8($t6)
    MEM_B(0X25B8, ctx->r14) = 0;
L_8003C800:
    // 0x8003C800: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C804: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C808: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x8003C80C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003C810: jal         0x800B3C20
    // 0x8003C814: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    osRecvMesg_recomp(rdram, ctx);
        goto after_28;
    // 0x8003C814: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    after_28:
    // 0x8003C818: bne         $v0, $zero, L_8003CEEC
    if (ctx->r2 != 0) {
        // 0x8003C81C: nop
    
            goto L_8003CEEC;
    }
    // 0x8003C81C: nop

    // 0x8003C820: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C824: nop

    // 0x8003C828: lhu         $t0, 0x8($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X8);
    // 0x8003C82C: nop

    // 0x8003C830: sltiu       $at, $t0, 0xA
    ctx->r1 = ctx->r8 < 0XA ? 1 : 0;
    // 0x8003C834: beq         $at, $zero, L_8003CEEC
    if (ctx->r1 == 0) {
        // 0x8003C838: nop
    
            goto L_8003CEEC;
    }
    // 0x8003C838: nop

    // 0x8003C83C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003C840: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003C844: addu        $at, $at, $t0
    gpr jr_addend_8003C850 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8003C848: lw          $t0, -0x4C34($at)
    ctx->r8 = ADD32(ctx->r1, -0X4C34);
    // 0x8003C84C: nop

    // 0x8003C850: jr          $t0
    // 0x8003C854: nop

    switch (jr_addend_8003C850 >> 2) {
        case 0: goto L_8003C858; break;
        case 1: goto L_8003C8E4; break;
        case 2: goto L_8003C9A0; break;
        case 3: goto L_8003CA5C; break;
        case 4: goto L_8003CB24; break;
        case 5: goto L_8003CBE4; break;
        case 6: goto L_8003CC9C; break;
        case 7: goto L_8003CD58; break;
        case 8: goto L_8003CE00; break;
        case 9: goto L_8003CEA0; break;
        default: switch_error(__func__, 0x8003C850, 0x800DB3CC);
    }
    // 0x8003C854: nop

L_8003C858:
    // 0x8003C858: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C85C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8003C860: lbu         $t7, 0x0($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X0);
    // 0x8003C864: lw          $t1, 0x1F18($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1F18);
    // 0x8003C868: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8003C86C: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x8003C870: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8003C874: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x8003C878: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8003C87C: addu        $a1, $t1, $t3
    ctx->r5 = ADD32(ctx->r9, ctx->r11);
    // 0x8003C880: addiu       $a1, $a1, 0x238C
    ctx->r5 = ADD32(ctx->r5, 0X238C);
    // 0x8003C884: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8003C888: jal         0x800B3620
    // 0x8003C88C: addiu       $a0, $t1, 0x258
    ctx->r4 = ADD32(ctx->r9, 0X258);
    osPfsInitPak_recomp(rdram, ctx);
        goto after_29;
    // 0x8003C88C: addiu       $a0, $t1, 0x258
    ctx->r4 = ADD32(ctx->r9, 0X258);
    after_29:
    // 0x8003C890: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C894: nop

    // 0x8003C898: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
    // 0x8003C89C: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C8A0: nop

    // 0x8003C8A4: lw          $t5, 0x10($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X10);
    // 0x8003C8A8: nop

    // 0x8003C8AC: beq         $t5, $zero, L_8003C8C4
    if (ctx->r13 == 0) {
        // 0x8003C8B0: nop
    
            goto L_8003C8C4;
    }
    // 0x8003C8B0: nop

    // 0x8003C8B4: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8003C8B8: andi        $t8, $t6, 0xF0
    ctx->r24 = ctx->r14 & 0XF0;
    // 0x8003C8BC: ori         $t0, $t8, 0xF
    ctx->r8 = ctx->r24 | 0XF;
    // 0x8003C8C0: sw          $t0, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r8;
L_8003C8C4:
    // 0x8003C8C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C8C8: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C8CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003C8D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C8D4: jal         0x800B34D0
    // 0x8003C8D8: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_30;
    // 0x8003C8D8: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_30:
    // 0x8003C8DC: b           L_8003CEEC
    // 0x8003C8E0: nop

        goto L_8003CEEC;
    // 0x8003C8E0: nop

L_8003C8E4:
    // 0x8003C8E4: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C8E8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8003C8EC: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8003C8F0: lw          $t9, 0x10($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X10);
    // 0x8003C8F4: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8003C8F8: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8003C8FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8003C900: lbu         $a1, 0x1($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X1);
    // 0x8003C904: lw          $a3, 0xC($t1)
    ctx->r7 = MEM_W(ctx->r9, 0XC);
    // 0x8003C908: lw          $t4, 0x1F18($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F18);
    // 0x8003C90C: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8003C910: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003C914: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x8003C918: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8003C91C: addu        $a0, $t4, $t7
    ctx->r4 = ADD32(ctx->r12, ctx->r15);
    // 0x8003C920: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003C924: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003C928: jal         0x800B46E4
    // 0x8003C92C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_31;
    // 0x8003C92C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_31:
    // 0x8003C930: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C934: nop

    // 0x8003C938: sw          $v0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r2;
    // 0x8003C93C: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C940: nop

    // 0x8003C944: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x8003C948: nop

    // 0x8003C94C: bne         $t0, $zero, L_8003C960
    if (ctx->r8 != 0) {
        // 0x8003C950: nop
    
            goto L_8003C960;
    }
    // 0x8003C950: nop

    // 0x8003C954: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8003C958: b           L_8003C980
    // 0x8003C95C: sw          $t2, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r10;
        goto L_8003C980;
    // 0x8003C95C: sw          $t2, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r10;
L_8003C960:
    // 0x8003C960: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C964: nop

    // 0x8003C968: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8003C96C: nop

    // 0x8003C970: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x8003C974: andi        $t9, $t7, 0xF0
    ctx->r25 = ctx->r15 & 0XF0;
    // 0x8003C978: ori         $t1, $t9, 0xF
    ctx->r9 = ctx->r25 | 0XF;
    // 0x8003C97C: sw          $t1, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r9;
L_8003C980:
    // 0x8003C980: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C984: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003C988: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003C98C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C990: jal         0x800B34D0
    // 0x8003C994: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_32;
    // 0x8003C994: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_32:
    // 0x8003C998: b           L_8003CEEC
    // 0x8003C99C: nop

        goto L_8003CEEC;
    // 0x8003C99C: nop

L_8003C9A0:
    // 0x8003C9A0: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C9A4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8003C9A8: lbu         $t0, 0x0($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X0);
    // 0x8003C9AC: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8003C9B0: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8003C9B4: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8003C9B8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8003C9BC: lbu         $a1, 0x1($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X1);
    // 0x8003C9C0: lw          $a3, 0xC($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XC);
    // 0x8003C9C4: lw          $t5, 0x1F18($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F18);
    // 0x8003C9C8: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8003C9CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003C9D0: lw          $t4, 0x4($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X4);
    // 0x8003C9D4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8003C9D8: addu        $a0, $t5, $t2
    ctx->r4 = ADD32(ctx->r13, ctx->r10);
    // 0x8003C9DC: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003C9E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C9E4: jal         0x800B46E4
    // 0x8003C9E8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_33;
    // 0x8003C9E8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_33:
    // 0x8003C9EC: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C9F0: nop

    // 0x8003C9F4: sw          $v0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r2;
    // 0x8003C9F8: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C9FC: nop

    // 0x8003CA00: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8003CA04: nop

    // 0x8003CA08: bne         $t1, $zero, L_8003CA1C
    if (ctx->r9 != 0) {
        // 0x8003CA0C: nop
    
            goto L_8003CA1C;
    }
    // 0x8003CA0C: nop

    // 0x8003CA10: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8003CA14: b           L_8003CA3C
    // 0x8003CA18: sw          $t3, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r11;
        goto L_8003CA3C;
    // 0x8003CA18: sw          $t3, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r11;
L_8003CA1C:
    // 0x8003CA1C: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CA20: nop

    // 0x8003CA24: lw          $t5, 0x10($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X10);
    // 0x8003CA28: nop

    // 0x8003CA2C: sll         $t2, $t5, 4
    ctx->r10 = S32(ctx->r13 << 4);
    // 0x8003CA30: andi        $t8, $t2, 0xF0
    ctx->r24 = ctx->r10 & 0XF0;
    // 0x8003CA34: ori         $t6, $t8, 0xF
    ctx->r14 = ctx->r24 | 0XF;
    // 0x8003CA38: sw          $t6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r14;
L_8003CA3C:
    // 0x8003CA3C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003CA40: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003CA44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003CA48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003CA4C: jal         0x800B34D0
    // 0x8003CA50: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_34;
    // 0x8003CA50: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_34:
    // 0x8003CA54: b           L_8003CEEC
    // 0x8003CA58: nop

        goto L_8003CEEC;
    // 0x8003CA58: nop

L_8003CA5C:
    // 0x8003CA5C: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CA60: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8003CA64: lbu         $t1, 0x0($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X0);
    // 0x8003CA68: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x8003CA6C: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8003CA70: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8003CA74: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8003CA78: lhu         $a1, 0x8($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X8);
    // 0x8003CA7C: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x8003CA80: addiu       $t5, $t9, 0xA
    ctx->r13 = ADD32(ctx->r25, 0XA);
    // 0x8003CA84: lw          $t4, 0x1F18($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F18);
    // 0x8003CA88: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003CA8C: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8003CA90: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8003CA94: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8003CA98: addiu       $t8, $sp, 0x64
    ctx->r24 = ADD32(ctx->r29, 0X64);
    // 0x8003CA9C: addu        $a0, $t4, $t3
    ctx->r4 = ADD32(ctx->r12, ctx->r11);
    // 0x8003CAA0: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003CAA4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8003CAA8: addiu       $a3, $t9, 0xE
    ctx->r7 = ADD32(ctx->r25, 0XE);
    // 0x8003CAAC: jal         0x800B4A60
    // 0x8003CAB0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    osPfsAllocateFile_recomp(rdram, ctx);
        goto after_35;
    // 0x8003CAB0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_35:
    // 0x8003CAB4: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CAB8: nop

    // 0x8003CABC: sw          $v0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r2;
    // 0x8003CAC0: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CAC4: nop

    // 0x8003CAC8: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x8003CACC: nop

    // 0x8003CAD0: bne         $t1, $zero, L_8003CAE4
    if (ctx->r9 != 0) {
        // 0x8003CAD4: nop
    
            goto L_8003CAE4;
    }
    // 0x8003CAD4: nop

    // 0x8003CAD8: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8003CADC: b           L_8003CB04
    // 0x8003CAE0: sw          $t4, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r12;
        goto L_8003CB04;
    // 0x8003CAE0: sw          $t4, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r12;
L_8003CAE4:
    // 0x8003CAE4: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CAE8: nop

    // 0x8003CAEC: lw          $t7, 0x10($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X10);
    // 0x8003CAF0: nop

    // 0x8003CAF4: sll         $t5, $t7, 4
    ctx->r13 = S32(ctx->r15 << 4);
    // 0x8003CAF8: andi        $t9, $t5, 0xF0
    ctx->r25 = ctx->r13 & 0XF0;
    // 0x8003CAFC: ori         $t2, $t9, 0xF
    ctx->r10 = ctx->r25 | 0XF;
    // 0x8003CB00: sw          $t2, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r10;
L_8003CB04:
    // 0x8003CB04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003CB08: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003CB0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003CB10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003CB14: jal         0x800B34D0
    // 0x8003CB18: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_36;
    // 0x8003CB18: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_36:
    // 0x8003CB1C: b           L_8003CEEC
    // 0x8003CB20: nop

        goto L_8003CEEC;
    // 0x8003CB20: nop

L_8003CB24:
    // 0x8003CB24: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CB28: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8003CB2C: lbu         $t1, 0x0($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X0);
    // 0x8003CB30: lw          $t0, 0x18($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X18);
    // 0x8003CB34: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8003CB38: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8003CB3C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8003CB40: lw          $t8, 0x1F18($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F18);
    // 0x8003CB44: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8003CB48: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8003CB4C: lhu         $a1, 0x8($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X8);
    // 0x8003CB50: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x8003CB54: addiu       $t5, $sp, 0x64
    ctx->r13 = ADD32(ctx->r29, 0X64);
    // 0x8003CB58: addiu       $t7, $t0, 0xA
    ctx->r15 = ADD32(ctx->r8, 0XA);
    // 0x8003CB5C: addu        $a0, $t8, $t4
    ctx->r4 = ADD32(ctx->r24, ctx->r12);
    // 0x8003CB60: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003CB64: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003CB68: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8003CB6C: jal         0x800B4EE0
    // 0x8003CB70: addiu       $a3, $t0, 0xE
    ctx->r7 = ADD32(ctx->r8, 0XE);
    osPfsFindFile_recomp(rdram, ctx);
        goto after_37;
    // 0x8003CB70: addiu       $a3, $t0, 0xE
    ctx->r7 = ADD32(ctx->r8, 0XE);
    after_37:
    // 0x8003CB74: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CB78: nop

    // 0x8003CB7C: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
    // 0x8003CB80: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CB84: nop

    // 0x8003CB88: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x8003CB8C: nop

    // 0x8003CB90: bne         $t3, $zero, L_8003CBA4
    if (ctx->r11 != 0) {
        // 0x8003CB94: nop
    
            goto L_8003CBA4;
    }
    // 0x8003CB94: nop

    // 0x8003CB98: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8003CB9C: b           L_8003CBC4
    // 0x8003CBA0: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
        goto L_8003CBC4;
    // 0x8003CBA0: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
L_8003CBA4:
    // 0x8003CBA4: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CBA8: nop

    // 0x8003CBAC: lw          $t4, 0x10($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X10);
    // 0x8003CBB0: nop

    // 0x8003CBB4: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x8003CBB8: andi        $t0, $t6, 0xF0
    ctx->r8 = ctx->r14 & 0XF0;
    // 0x8003CBBC: ori         $t7, $t0, 0xF
    ctx->r15 = ctx->r8 | 0XF;
    // 0x8003CBC0: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
L_8003CBC4:
    // 0x8003CBC4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003CBC8: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003CBCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003CBD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003CBD4: jal         0x800B34D0
    // 0x8003CBD8: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_38;
    // 0x8003CBD8: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_38:
    // 0x8003CBDC: b           L_8003CEEC
    // 0x8003CBE0: nop

        goto L_8003CEEC;
    // 0x8003CBE0: nop

L_8003CBE4:
    // 0x8003CBE4: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CBE8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8003CBEC: lbu         $t3, 0x0($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X0);
    // 0x8003CBF0: lw          $t2, 0x18($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X18);
    // 0x8003CBF4: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x8003CBF8: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x8003CBFC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8003CC00: lw          $t5, 0x1F18($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F18);
    // 0x8003CC04: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x8003CC08: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8003CC0C: lhu         $a1, 0x8($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X8);
    // 0x8003CC10: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x8003CC14: addiu       $t4, $t2, 0xA
    ctx->r12 = ADD32(ctx->r10, 0XA);
    // 0x8003CC18: addu        $a0, $t5, $t1
    ctx->r4 = ADD32(ctx->r13, ctx->r9);
    // 0x8003CC1C: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003CC20: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8003CC24: jal         0x800B5090
    // 0x8003CC28: addiu       $a3, $t2, 0xE
    ctx->r7 = ADD32(ctx->r10, 0XE);
    osPfsDeleteFile_recomp(rdram, ctx);
        goto after_39;
    // 0x8003CC28: addiu       $a3, $t2, 0xE
    ctx->r7 = ADD32(ctx->r10, 0XE);
    after_39:
    // 0x8003CC2C: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CC30: nop

    // 0x8003CC34: sw          $v0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r2;
    // 0x8003CC38: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CC3C: nop

    // 0x8003CC40: lw          $t7, 0x10($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X10);
    // 0x8003CC44: nop

    // 0x8003CC48: bne         $t7, $zero, L_8003CC5C
    if (ctx->r15 != 0) {
        // 0x8003CC4C: nop
    
            goto L_8003CC5C;
    }
    // 0x8003CC4C: nop

    // 0x8003CC50: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8003CC54: b           L_8003CC7C
    // 0x8003CC58: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
        goto L_8003CC7C;
    // 0x8003CC58: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
L_8003CC5C:
    // 0x8003CC5C: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CC60: nop

    // 0x8003CC64: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x8003CC68: nop

    // 0x8003CC6C: sll         $t1, $t5, 4
    ctx->r9 = S32(ctx->r13 << 4);
    // 0x8003CC70: andi        $t9, $t1, 0xF0
    ctx->r25 = ctx->r9 & 0XF0;
    // 0x8003CC74: ori         $t2, $t9, 0xF
    ctx->r10 = ctx->r25 | 0XF;
    // 0x8003CC78: sw          $t2, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r10;
L_8003CC7C:
    // 0x8003CC7C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003CC80: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003CC84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003CC88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003CC8C: jal         0x800B34D0
    // 0x8003CC90: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_40;
    // 0x8003CC90: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_40:
    // 0x8003CC94: b           L_8003CEEC
    // 0x8003CC98: nop

        goto L_8003CEEC;
    // 0x8003CC98: nop

L_8003CC9C:
    // 0x8003CC9C: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CCA0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8003CCA4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8003CCA8: lw          $t4, 0x1F18($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F18);
    // 0x8003CCAC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003CCB0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8003CCB4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8003CCB8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8003CCBC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8003CCC0: addu        $a0, $t4, $t8
    ctx->r4 = ADD32(ctx->r12, ctx->r24);
    // 0x8003CCC4: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003CCC8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8003CCCC: jal         0x800B5300
    // 0x8003CCD0: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_41;
    // 0x8003CCD0: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_41:
    // 0x8003CCD4: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CCD8: nop

    // 0x8003CCDC: sw          $v0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r2;
    // 0x8003CCE0: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CCE4: nop

    // 0x8003CCE8: lw          $t1, 0x10($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X10);
    // 0x8003CCEC: nop

    // 0x8003CCF0: bne         $t1, $zero, L_8003CD18
    if (ctx->r9 != 0) {
        // 0x8003CCF4: nop
    
            goto L_8003CD18;
    }
    // 0x8003CCF4: nop

    // 0x8003CCF8: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8003CCFC: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8003CD00: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x8003CD04: andi        $t3, $t2, 0xFF00
    ctx->r11 = ctx->r10 & 0XFF00;
    // 0x8003CD08: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8003CD0C: or          $t4, $t3, $t7
    ctx->r12 = ctx->r11 | ctx->r15;
    // 0x8003CD10: b           L_8003CD38
    // 0x8003CD14: sw          $t4, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r12;
        goto L_8003CD38;
    // 0x8003CD14: sw          $t4, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r12;
L_8003CD18:
    // 0x8003CD18: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CD1C: nop

    // 0x8003CD20: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x8003CD24: nop

    // 0x8003CD28: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8003CD2C: andi        $t9, $t1, 0xF0
    ctx->r25 = ctx->r9 & 0XF0;
    // 0x8003CD30: ori         $t2, $t9, 0xF
    ctx->r10 = ctx->r25 | 0XF;
    // 0x8003CD34: sw          $t2, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r10;
L_8003CD38:
    // 0x8003CD38: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003CD3C: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003CD40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003CD44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003CD48: jal         0x800B34D0
    // 0x8003CD4C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_42;
    // 0x8003CD4C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_42:
    // 0x8003CD50: b           L_8003CEEC
    // 0x8003CD54: nop

        goto L_8003CEEC;
    // 0x8003CD54: nop

L_8003CD58:
    // 0x8003CD58: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CD5C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8003CD60: lbu         $t7, 0x0($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X0);
    // 0x8003CD64: lw          $t6, 0x1F18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F18);
    // 0x8003CD68: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x8003CD6C: subu        $t4, $t4, $t7
    ctx->r12 = SUB32(ctx->r12, ctx->r15);
    // 0x8003CD70: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8003CD74: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x8003CD78: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8003CD7C: lbu         $a1, 0x1($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X1);
    // 0x8003CD80: lw          $a2, 0x18($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X18);
    // 0x8003CD84: addu        $a0, $t6, $t4
    ctx->r4 = ADD32(ctx->r14, ctx->r12);
    // 0x8003CD88: jal         0x800B5420
    // 0x8003CD8C: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    osPfsFileState_recomp(rdram, ctx);
        goto after_43;
    // 0x8003CD8C: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    after_43:
    // 0x8003CD90: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CD94: nop

    // 0x8003CD98: sw          $v0, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r2;
    // 0x8003CD9C: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CDA0: nop

    // 0x8003CDA4: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x8003CDA8: nop

    // 0x8003CDAC: bne         $t1, $zero, L_8003CDC0
    if (ctx->r9 != 0) {
        // 0x8003CDB0: nop
    
            goto L_8003CDC0;
    }
    // 0x8003CDB0: nop

    // 0x8003CDB4: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8003CDB8: b           L_8003CDE0
    // 0x8003CDBC: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
        goto L_8003CDE0;
    // 0x8003CDBC: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
L_8003CDC0:
    // 0x8003CDC0: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CDC4: nop

    // 0x8003CDC8: lw          $t8, 0x10($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X10);
    // 0x8003CDCC: nop

    // 0x8003CDD0: sll         $t7, $t8, 4
    ctx->r15 = S32(ctx->r24 << 4);
    // 0x8003CDD4: andi        $t6, $t7, 0xF0
    ctx->r14 = ctx->r15 & 0XF0;
    // 0x8003CDD8: ori         $t4, $t6, 0xF
    ctx->r12 = ctx->r14 | 0XF;
    // 0x8003CDDC: sw          $t4, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r12;
L_8003CDE0:
    // 0x8003CDE0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003CDE4: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003CDE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003CDEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003CDF0: jal         0x800B34D0
    // 0x8003CDF4: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_44;
    // 0x8003CDF4: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_44:
    // 0x8003CDF8: b           L_8003CEEC
    // 0x8003CDFC: nop

        goto L_8003CEEC;
    // 0x8003CDFC: nop

L_8003CE00:
    // 0x8003CE00: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CE04: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8003CE08: lbu         $t1, 0x0($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X0);
    // 0x8003CE0C: lw          $t3, 0x1F18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F18);
    // 0x8003CE10: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8003CE14: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x8003CE18: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8003CE1C: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x8003CE20: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8003CE24: addu        $a0, $t3, $t9
    ctx->r4 = ADD32(ctx->r11, ctx->r25);
    // 0x8003CE28: jal         0x800B5600
    // 0x8003CE2C: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    osPfsRepairId_recomp(rdram, ctx);
        goto after_45;
    // 0x8003CE2C: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    after_45:
    // 0x8003CE30: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CE34: nop

    // 0x8003CE38: sw          $v0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r2;
    // 0x8003CE3C: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CE40: nop

    // 0x8003CE44: lw          $t7, 0x10($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X10);
    // 0x8003CE48: nop

    // 0x8003CE4C: bne         $t7, $zero, L_8003CE60
    if (ctx->r15 != 0) {
        // 0x8003CE50: nop
    
            goto L_8003CE60;
    }
    // 0x8003CE50: nop

    // 0x8003CE54: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8003CE58: b           L_8003CE80
    // 0x8003CE5C: sw          $t6, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r14;
        goto L_8003CE80;
    // 0x8003CE5C: sw          $t6, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r14;
L_8003CE60:
    // 0x8003CE60: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CE64: nop

    // 0x8003CE68: lw          $t2, 0x10($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X10);
    // 0x8003CE6C: nop

    // 0x8003CE70: sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10 << 4);
    // 0x8003CE74: andi        $t1, $t5, 0xF0
    ctx->r9 = ctx->r13 & 0XF0;
    // 0x8003CE78: ori         $t3, $t1, 0xF
    ctx->r11 = ctx->r9 | 0XF;
    // 0x8003CE7C: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
L_8003CE80:
    // 0x8003CE80: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003CE84: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003CE88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003CE8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003CE90: jal         0x800B34D0
    // 0x8003CE94: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_46;
    // 0x8003CE94: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_46:
    // 0x8003CE98: b           L_8003CEEC
    // 0x8003CE9C: nop

        goto L_8003CEEC;
    // 0x8003CE9C: nop

L_8003CEA0:
    // 0x8003CEA0: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8003CEA4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8003CEA8: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x8003CEAC: lw          $t9, 0x1F18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1F18);
    // 0x8003CEB0: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8003CEB4: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8003CEB8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003CEBC: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8003CEC0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8003CEC4: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x8003CEC8: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003CECC: jal         0x800B5660
    // 0x8003CED0: addiu       $a1, $t0, 0x10
    ctx->r5 = ADD32(ctx->r8, 0X10);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_47;
    // 0x8003CED0: addiu       $a1, $t0, 0x10
    ctx->r5 = ADD32(ctx->r8, 0X10);
    after_47:
    // 0x8003CED4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003CED8: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003CEDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003CEE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003CEE4: jal         0x800B34D0
    // 0x8003CEE8: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_48;
    // 0x8003CEE8: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_48:
L_8003CEEC:
    // 0x8003CEEC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003CEF0: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003CEF4: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x8003CEF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003CEFC: jal         0x800B3C20
    // 0x8003CF00: addiu       $a0, $a0, 0x228
    ctx->r4 = ADD32(ctx->r4, 0X228);
    osRecvMesg_recomp(rdram, ctx);
        goto after_49;
    // 0x8003CF00: addiu       $a0, $a0, 0x228
    ctx->r4 = ADD32(ctx->r4, 0X228);
    after_49:
    // 0x8003CF04: bne         $v0, $zero, L_8003DB30
    if (ctx->r2 != 0) {
        // 0x8003CF08: nop
    
            goto L_8003DB30;
    }
    // 0x8003CF08: nop

    // 0x8003CF0C: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8003CF10: nop

    // 0x8003CF14: lhu         $t2, 0x0($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X0);
    // 0x8003CF18: nop

    // 0x8003CF1C: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x8003CF20: beq         $at, $zero, L_8003DB30
    if (ctx->r1 == 0) {
        // 0x8003CF24: nop
    
            goto L_8003DB30;
    }
    // 0x8003CF24: nop

    // 0x8003CF28: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8003CF2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003CF30: addu        $at, $at, $t2
    gpr jr_addend_8003CF3C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8003CF34: lw          $t2, -0x4C0C($at)
    ctx->r10 = ADD32(ctx->r1, -0X4C0C);
    // 0x8003CF38: nop

    // 0x8003CF3C: jr          $t2
    // 0x8003CF40: nop

    switch (jr_addend_8003CF3C >> 2) {
        case 0: goto L_8003CF44; break;
        case 1: goto L_8003CFDC; break;
        case 2: goto L_8003D09C; break;
        case 3: goto L_8003D6BC; break;
        case 4: goto L_8003D3AC; break;
        default: switch_error(__func__, 0x8003CF3C, 0x800DB3F4);
    }
    // 0x8003CF40: nop

L_8003CF44:
    // 0x8003CF44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003CF48: jal         0x800B3BFC
    // 0x8003CF4C: addiu       $a0, $a0, -0x4C44
    ctx->r4 = ADD32(ctx->r4, -0X4C44);
    rmonPrintf_recomp(rdram, ctx);
        goto after_50;
    // 0x8003CF4C: addiu       $a0, $a0, -0x4C44
    ctx->r4 = ADD32(ctx->r4, -0X4C44);
    after_50:
    // 0x8003CF50: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x8003CF54: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8003CF58: lbu         $t3, 0x2($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X2);
    // 0x8003CF5C: lw          $t5, 0x1F18($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F18);
    // 0x8003CF60: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8003CF64: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8003CF68: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8003CF6C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8003CF70: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8003CF74: addu        $a1, $t5, $t4
    ctx->r5 = ADD32(ctx->r13, ctx->r12);
    // 0x8003CF78: addiu       $a1, $a1, 0x238C
    ctx->r5 = ADD32(ctx->r5, 0X238C);
    // 0x8003CF7C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8003CF80: jal         0x800B5800
    // 0x8003CF84: addiu       $a0, $t5, 0x258
    ctx->r4 = ADD32(ctx->r13, 0X258);
    osGbpakInit(rdram, ctx);
        goto after_51;
    // 0x8003CF84: addiu       $a0, $t5, 0x258
    ctx->r4 = ADD32(ctx->r13, 0X258);
    after_51:
    // 0x8003CF88: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8003CF8C: nop

    // 0x8003CF90: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    // 0x8003CF94: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8003CF98: nop

    // 0x8003CF9C: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x8003CFA0: nop

    // 0x8003CFA4: beq         $t6, $zero, L_8003CFBC
    if (ctx->r14 == 0) {
        // 0x8003CFA8: nop
    
            goto L_8003CFBC;
    }
    // 0x8003CFA8: nop

    // 0x8003CFAC: sll         $t0, $t6, 4
    ctx->r8 = S32(ctx->r14 << 4);
    // 0x8003CFB0: andi        $t8, $t0, 0xF0
    ctx->r24 = ctx->r8 & 0XF0;
    // 0x8003CFB4: ori         $t2, $t8, 0xF
    ctx->r10 = ctx->r24 | 0XF;
    // 0x8003CFB8: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
L_8003CFBC:
    // 0x8003CFBC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003CFC0: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003CFC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003CFC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003CFCC: jal         0x800B34D0
    // 0x8003CFD0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_52;
    // 0x8003CFD0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_52:
    // 0x8003CFD4: b           L_8003DB30
    // 0x8003CFD8: nop

        goto L_8003DB30;
    // 0x8003CFD8: nop

L_8003CFDC:
    // 0x8003CFDC: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8003CFE0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8003CFE4: lbu         $t4, 0x2($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X2);
    // 0x8003CFE8: lw          $t1, 0x1F18($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1F18);
    // 0x8003CFEC: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8003CFF0: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x8003CFF4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8003CFF8: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x8003CFFC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8003D000: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    // 0x8003D004: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D008: jal         0x800B5A20
    // 0x8003D00C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    osGbpakPower(rdram, ctx);
        goto after_53;
    // 0x8003D00C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_53:
    // 0x8003D010: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x8003D014: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8003D018: lbu         $t0, 0x2($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X2);
    // 0x8003D01C: lw          $t7, 0x1F18($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F18);
    // 0x8003D020: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8003D024: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x8003D028: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8003D02C: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x8003D030: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8003D034: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8003D038: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D03C: addiu       $a2, $t6, 0x10
    ctx->r6 = ADD32(ctx->r14, 0X10);
    // 0x8003D040: jal         0x800B5B30
    // 0x8003D044: addiu       $a1, $t7, 0x25C0
    ctx->r5 = ADD32(ctx->r15, 0X25C0);
    osGbpakReadId(rdram, ctx);
        goto after_54;
    // 0x8003D044: addiu       $a1, $t7, 0x25C0
    ctx->r5 = ADD32(ctx->r15, 0X25C0);
    after_54:
    // 0x8003D048: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8003D04C: nop

    // 0x8003D050: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x8003D054: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8003D058: nop

    // 0x8003D05C: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8003D060: nop

    // 0x8003D064: beq         $t5, $zero, L_8003D07C
    if (ctx->r13 == 0) {
        // 0x8003D068: nop
    
            goto L_8003D07C;
    }
    // 0x8003D068: nop

    // 0x8003D06C: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
    // 0x8003D070: andi        $t1, $t4, 0xF0
    ctx->r9 = ctx->r12 & 0XF0;
    // 0x8003D074: ori         $t3, $t1, 0xF
    ctx->r11 = ctx->r9 | 0XF;
    // 0x8003D078: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
L_8003D07C:
    // 0x8003D07C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D080: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D088: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D08C: jal         0x800B34D0
    // 0x8003D090: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_55;
    // 0x8003D090: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_55:
    // 0x8003D094: b           L_8003DB30
    // 0x8003D098: nop

        goto L_8003DB30;
    // 0x8003D098: nop

L_8003D09C:
    // 0x8003D09C: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8003D0A0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003D0A4: lbu         $t7, 0x2($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X2);
    // 0x8003D0A8: lw          $t0, 0x1F18($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F18);
    // 0x8003D0AC: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8003D0B0: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8003D0B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003D0B8: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8003D0BC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8003D0C0: addu        $a0, $t0, $t6
    ctx->r4 = ADD32(ctx->r8, ctx->r14);
    // 0x8003D0C4: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D0C8: jal         0x800B5A20
    // 0x8003D0CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    osGbpakPower(rdram, ctx);
        goto after_56;
    // 0x8003D0CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_56:
    // 0x8003D0D0: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8003D0D4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8003D0D8: lbu         $t4, 0x2($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X2);
    // 0x8003D0DC: lw          $t2, 0x1F18($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1F18);
    // 0x8003D0E0: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x8003D0E4: subu        $t1, $t1, $t4
    ctx->r9 = SUB32(ctx->r9, ctx->r12);
    // 0x8003D0E8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8003D0EC: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x8003D0F0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8003D0F4: addu        $a0, $t2, $t1
    ctx->r4 = ADD32(ctx->r10, ctx->r9);
    // 0x8003D0F8: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D0FC: jal         0x800B5CF0
    // 0x8003D100: addiu       $a1, $t5, 0x10
    ctx->r5 = ADD32(ctx->r13, 0X10);
    osGbpakGetStatus(rdram, ctx);
        goto after_57;
    // 0x8003D100: addiu       $a1, $t5, 0x10
    ctx->r5 = ADD32(ctx->r13, 0X10);
    after_57:
    // 0x8003D104: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8003D108: nop

    // 0x8003D10C: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x8003D110: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8003D114: nop

    // 0x8003D118: lw          $t8, 0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X4);
    // 0x8003D11C: nop

    // 0x8003D120: beq         $t8, $zero, L_8003D158
    if (ctx->r24 == 0) {
        // 0x8003D124: nop
    
            goto L_8003D158;
    }
    // 0x8003D124: nop

    // 0x8003D128: sll         $t7, $t8, 4
    ctx->r15 = S32(ctx->r24 << 4);
    // 0x8003D12C: andi        $t0, $t7, 0xF0
    ctx->r8 = ctx->r15 & 0XF0;
    // 0x8003D130: ori         $t6, $t0, 0xF
    ctx->r14 = ctx->r8 | 0XF;
    // 0x8003D134: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8003D138: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D13C: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D140: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D144: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D148: jal         0x800B34D0
    // 0x8003D14C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_58;
    // 0x8003D14C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_58:
    // 0x8003D150: b           L_8003DB30
    // 0x8003D154: nop

        goto L_8003DB30;
    // 0x8003D154: nop

L_8003D158:
    // 0x8003D158: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_8003D15C:
    // 0x8003D15C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D160: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003D164: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x8003D168: sb          $t4, 0x38($t1)
    MEM_B(0X38, ctx->r9) = ctx->r12;
    // 0x8003D16C: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D170: nop

    // 0x8003D174: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x8003D178: slti        $at, $t3, 0x20
    ctx->r1 = SIGNED(ctx->r11) < 0X20 ? 1 : 0;
    // 0x8003D17C: bne         $at, $zero, L_8003D15C
    if (ctx->r1 != 0) {
        // 0x8003D180: sw          $t3, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r11;
            goto L_8003D15C;
    }
    // 0x8003D180: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x8003D184: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8003D188: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8003D18C: lbu         $t0, 0x2($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X2);
    // 0x8003D190: lw          $t8, 0x1F18($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F18);
    // 0x8003D194: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8003D198: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x8003D19C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003D1A0: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x8003D1A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8003D1A8: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8003D1AC: addu        $a0, $t8, $t6
    ctx->r4 = ADD32(ctx->r24, ctx->r14);
    // 0x8003D1B0: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D1B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003D1B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003D1BC: addiu       $a2, $zero, 0x6000
    ctx->r6 = ADD32(0, 0X6000);
    // 0x8003D1C0: jal         0x800B5E50
    // 0x8003D1C4: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    osGbpakReadWrite(rdram, ctx);
        goto after_59;
    // 0x8003D1C4: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_59:
    // 0x8003D1C8: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8003D1CC: nop

    // 0x8003D1D0: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x8003D1D4: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8003D1D8: nop

    // 0x8003D1DC: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x8003D1E0: nop

    // 0x8003D1E4: beq         $t1, $zero, L_8003D21C
    if (ctx->r9 == 0) {
        // 0x8003D1E8: nop
    
            goto L_8003D21C;
    }
    // 0x8003D1E8: nop

    // 0x8003D1EC: sll         $t5, $t1, 4
    ctx->r13 = S32(ctx->r9 << 4);
    // 0x8003D1F0: andi        $t3, $t5, 0xF0
    ctx->r11 = ctx->r13 & 0XF0;
    // 0x8003D1F4: ori         $t7, $t3, 0xF
    ctx->r15 = ctx->r11 | 0XF;
    // 0x8003D1F8: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8003D1FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D200: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D208: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D20C: jal         0x800B34D0
    // 0x8003D210: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_60;
    // 0x8003D210: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_60:
    // 0x8003D214: b           L_8003DB30
    // 0x8003D218: nop

        goto L_8003DB30;
    // 0x8003D218: nop

L_8003D21C:
    // 0x8003D21C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_8003D220:
    // 0x8003D220: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D224: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8003D228: addu        $t6, $sp, $t8
    ctx->r14 = ADD32(ctx->r29, ctx->r24);
    // 0x8003D22C: sb          $t0, 0x38($t6)
    MEM_B(0X38, ctx->r14) = ctx->r8;
    // 0x8003D230: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D234: nop

    // 0x8003D238: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x8003D23C: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x8003D240: bne         $at, $zero, L_8003D220
    if (ctx->r1 != 0) {
        // 0x8003D244: sw          $t4, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r12;
            goto L_8003D220;
    }
    // 0x8003D244: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x8003D248: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8003D24C: addiu       $t5, $sp, 0x38
    ctx->r13 = ADD32(ctx->r29, 0X38);
    // 0x8003D250: sb          $t1, 0x1F($t5)
    MEM_B(0X1F, ctx->r13) = ctx->r9;
    // 0x8003D254: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8003D258: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8003D25C: lbu         $t2, 0x2($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X2);
    // 0x8003D260: lw          $t3, 0x1F18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F18);
    // 0x8003D264: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8003D268: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8003D26C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003D270: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x8003D274: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8003D278: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8003D27C: addu        $a0, $t3, $t0
    ctx->r4 = ADD32(ctx->r11, ctx->r8);
    // 0x8003D280: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D284: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003D288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003D28C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003D290: jal         0x800B5E50
    // 0x8003D294: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    osGbpakReadWrite(rdram, ctx);
        goto after_61;
    // 0x8003D294: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_61:
    // 0x8003D298: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x8003D29C: nop

    // 0x8003D2A0: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    // 0x8003D2A4: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8003D2A8: nop

    // 0x8003D2AC: lw          $t4, 0x4($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X4);
    // 0x8003D2B0: nop

    // 0x8003D2B4: beq         $t4, $zero, L_8003D2EC
    if (ctx->r12 == 0) {
        // 0x8003D2B8: nop
    
            goto L_8003D2EC;
    }
    // 0x8003D2B8: nop

    // 0x8003D2BC: sll         $t1, $t4, 4
    ctx->r9 = S32(ctx->r12 << 4);
    // 0x8003D2C0: andi        $t5, $t1, 0xF0
    ctx->r13 = ctx->r9 & 0XF0;
    // 0x8003D2C4: ori         $t7, $t5, 0xF
    ctx->r15 = ctx->r13 | 0XF;
    // 0x8003D2C8: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8003D2CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D2D0: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D2D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D2D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D2DC: jal         0x800B34D0
    // 0x8003D2E0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_62;
    // 0x8003D2E0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_62:
    // 0x8003D2E4: b           L_8003DB30
    // 0x8003D2E8: nop

        goto L_8003DB30;
    // 0x8003D2E8: nop

L_8003D2EC:
    // 0x8003D2EC: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8003D2F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D2F4: lbu         $t0, 0x2($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0X2);
    // 0x8003D2F8: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x8003D2FC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8003D300: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8003D304: sb          $t2, 0x1F14($at)
    MEM_B(0X1F14, ctx->r1) = ctx->r10;
    // 0x8003D308: lbu         $t4, 0x2($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X2);
    // 0x8003D30C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8003D310: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x8003D314: subu        $t1, $t1, $t4
    ctx->r9 = SUB32(ctx->r9, ctx->r12);
    // 0x8003D318: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8003D31C: lw          $t8, 0x1F18($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F18);
    // 0x8003D320: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x8003D324: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8003D328: addu        $a0, $t8, $t1
    ctx->r4 = ADD32(ctx->r24, ctx->r9);
    // 0x8003D32C: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D330: jal         0x800B5CF0
    // 0x8003D334: addiu       $a1, $t6, 0x10
    ctx->r5 = ADD32(ctx->r14, 0X10);
    osGbpakGetStatus(rdram, ctx);
        goto after_63;
    // 0x8003D334: addiu       $a1, $t6, 0x10
    ctx->r5 = ADD32(ctx->r14, 0X10);
    after_63:
    // 0x8003D338: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8003D33C: nop

    // 0x8003D340: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x8003D344: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8003D348: nop

    // 0x8003D34C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8003D350: nop

    // 0x8003D354: beq         $t9, $zero, L_8003D38C
    if (ctx->r25 == 0) {
        // 0x8003D358: nop
    
            goto L_8003D38C;
    }
    // 0x8003D358: nop

    // 0x8003D35C: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x8003D360: andi        $t2, $t3, 0xF0
    ctx->r10 = ctx->r11 & 0XF0;
    // 0x8003D364: ori         $t0, $t2, 0xF
    ctx->r8 = ctx->r10 | 0XF;
    // 0x8003D368: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x8003D36C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D370: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D378: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D37C: jal         0x800B34D0
    // 0x8003D380: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_64;
    // 0x8003D380: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_64:
    // 0x8003D384: b           L_8003DB30
    // 0x8003D388: nop

        goto L_8003DB30;
    // 0x8003D388: nop

L_8003D38C:
    // 0x8003D38C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D390: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D398: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D39C: jal         0x800B34D0
    // 0x8003D3A0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_65;
    // 0x8003D3A0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_65:
    // 0x8003D3A4: b           L_8003DB30
    // 0x8003D3A8: nop

        goto L_8003DB30;
    // 0x8003D3A8: nop

L_8003D3AC:
    // 0x8003D3AC: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8003D3B0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8003D3B4: lbu         $t1, 0x2($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X2);
    // 0x8003D3B8: lw          $t4, 0x1F18($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F18);
    // 0x8003D3BC: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8003D3C0: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x8003D3C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003D3C8: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8003D3CC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8003D3D0: addu        $a0, $t4, $t6
    ctx->r4 = ADD32(ctx->r12, ctx->r14);
    // 0x8003D3D4: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D3D8: jal         0x800B5A20
    // 0x8003D3DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    osGbpakPower(rdram, ctx);
        goto after_66;
    // 0x8003D3DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_66:
    // 0x8003D3E0: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8003D3E4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8003D3E8: lbu         $t3, 0x2($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X2);
    // 0x8003D3EC: lw          $t5, 0x1F18($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F18);
    // 0x8003D3F0: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x8003D3F4: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8003D3F8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8003D3FC: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x8003D400: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8003D404: addu        $a0, $t5, $t2
    ctx->r4 = ADD32(ctx->r13, ctx->r10);
    // 0x8003D408: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D40C: jal         0x800B5CF0
    // 0x8003D410: addiu       $a1, $t9, 0x10
    ctx->r5 = ADD32(ctx->r25, 0X10);
    osGbpakGetStatus(rdram, ctx);
        goto after_67;
    // 0x8003D410: addiu       $a1, $t9, 0x10
    ctx->r5 = ADD32(ctx->r25, 0X10);
    after_67:
    // 0x8003D414: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x8003D418: nop

    // 0x8003D41C: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x8003D420: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8003D424: nop

    // 0x8003D428: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8003D42C: nop

    // 0x8003D430: beq         $t8, $zero, L_8003D468
    if (ctx->r24 == 0) {
        // 0x8003D434: nop
    
            goto L_8003D468;
    }
    // 0x8003D434: nop

    // 0x8003D438: sll         $t1, $t8, 4
    ctx->r9 = S32(ctx->r24 << 4);
    // 0x8003D43C: andi        $t4, $t1, 0xF0
    ctx->r12 = ctx->r9 & 0XF0;
    // 0x8003D440: ori         $t6, $t4, 0xF
    ctx->r14 = ctx->r12 | 0XF;
    // 0x8003D444: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8003D448: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D44C: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D454: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D458: jal         0x800B34D0
    // 0x8003D45C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_68;
    // 0x8003D45C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_68:
    // 0x8003D460: b           L_8003DB30
    // 0x8003D464: nop

        goto L_8003DB30;
    // 0x8003D464: nop

L_8003D468:
    // 0x8003D468: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_8003D46C:
    // 0x8003D46C: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D470: nop

    // 0x8003D474: addu        $t5, $sp, $t3
    ctx->r13 = ADD32(ctx->r29, ctx->r11);
    // 0x8003D478: sb          $zero, 0x38($t5)
    MEM_B(0X38, ctx->r13) = 0;
    // 0x8003D47C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D480: nop

    // 0x8003D484: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x8003D488: slti        $at, $t9, 0x20
    ctx->r1 = SIGNED(ctx->r25) < 0X20 ? 1 : 0;
    // 0x8003D48C: bne         $at, $zero, L_8003D46C
    if (ctx->r1 != 0) {
        // 0x8003D490: sw          $t9, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r25;
            goto L_8003D46C;
    }
    // 0x8003D490: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x8003D494: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8003D498: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003D49C: lbu         $t1, 0x2($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X2);
    // 0x8003D4A0: lw          $t0, 0x1F18($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F18);
    // 0x8003D4A4: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8003D4A8: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8003D4AC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8003D4B0: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8003D4B4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8003D4B8: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8003D4BC: addu        $a0, $t0, $t4
    ctx->r4 = ADD32(ctx->r8, ctx->r12);
    // 0x8003D4C0: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D4C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003D4C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003D4CC: addiu       $a2, $zero, 0x5000
    ctx->r6 = ADD32(0, 0X5000);
    // 0x8003D4D0: jal         0x800B5E50
    // 0x8003D4D4: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    osGbpakReadWrite(rdram, ctx);
        goto after_69;
    // 0x8003D4D4: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_69:
    // 0x8003D4D8: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8003D4DC: nop

    // 0x8003D4E0: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    // 0x8003D4E4: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8003D4E8: nop

    // 0x8003D4EC: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8003D4F0: nop

    // 0x8003D4F4: beq         $t5, $zero, L_8003D52C
    if (ctx->r13 == 0) {
        // 0x8003D4F8: nop
    
            goto L_8003D52C;
    }
    // 0x8003D4F8: nop

    // 0x8003D4FC: sll         $t2, $t5, 4
    ctx->r10 = S32(ctx->r13 << 4);
    // 0x8003D500: andi        $t9, $t2, 0xF0
    ctx->r25 = ctx->r10 & 0XF0;
    // 0x8003D504: ori         $t8, $t9, 0xF
    ctx->r24 = ctx->r25 | 0XF;
    // 0x8003D508: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8003D50C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D510: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D518: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D51C: jal         0x800B34D0
    // 0x8003D520: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_70;
    // 0x8003D520: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_70:
    // 0x8003D524: b           L_8003DB30
    // 0x8003D528: nop

        goto L_8003DB30;
    // 0x8003D528: nop

L_8003D52C:
    // 0x8003D52C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_8003D530:
    // 0x8003D530: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D534: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8003D538: addu        $t4, $sp, $t0
    ctx->r12 = ADD32(ctx->r29, ctx->r8);
    // 0x8003D53C: sb          $t1, 0x38($t4)
    MEM_B(0X38, ctx->r12) = ctx->r9;
    // 0x8003D540: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D544: nop

    // 0x8003D548: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8003D54C: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x8003D550: bne         $at, $zero, L_8003D530
    if (ctx->r1 != 0) {
        // 0x8003D554: sw          $t7, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r15;
            goto L_8003D530;
    }
    // 0x8003D554: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x8003D558: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8003D55C: addiu       $t2, $sp, 0x38
    ctx->r10 = ADD32(ctx->r29, 0X38);
    // 0x8003D560: sb          $t5, 0x1F($t2)
    MEM_B(0X1F, ctx->r10) = ctx->r13;
    // 0x8003D564: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8003D568: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8003D56C: lbu         $t3, 0x2($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X2);
    // 0x8003D570: lw          $t9, 0x1F18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1F18);
    // 0x8003D574: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x8003D578: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x8003D57C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8003D580: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x8003D584: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8003D588: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8003D58C: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x8003D590: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D594: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003D598: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003D59C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003D5A0: jal         0x800B5E50
    // 0x8003D5A4: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    osGbpakReadWrite(rdram, ctx);
        goto after_71;
    // 0x8003D5A4: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_71:
    // 0x8003D5A8: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8003D5AC: nop

    // 0x8003D5B0: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x8003D5B4: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x8003D5B8: nop

    // 0x8003D5BC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8003D5C0: nop

    // 0x8003D5C4: beq         $t7, $zero, L_8003D5FC
    if (ctx->r15 == 0) {
        // 0x8003D5C8: nop
    
            goto L_8003D5FC;
    }
    // 0x8003D5C8: nop

    // 0x8003D5CC: sll         $t5, $t7, 4
    ctx->r13 = S32(ctx->r15 << 4);
    // 0x8003D5D0: andi        $t2, $t5, 0xF0
    ctx->r10 = ctx->r13 & 0XF0;
    // 0x8003D5D4: ori         $t8, $t2, 0xF
    ctx->r24 = ctx->r10 | 0XF;
    // 0x8003D5D8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8003D5DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D5E0: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D5E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D5E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D5EC: jal         0x800B34D0
    // 0x8003D5F0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_72;
    // 0x8003D5F0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_72:
    // 0x8003D5F4: b           L_8003DB30
    // 0x8003D5F8: nop

        goto L_8003DB30;
    // 0x8003D5F8: nop

L_8003D5FC:
    // 0x8003D5FC: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8003D600: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D604: lbu         $t1, 0x2($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X2);
    // 0x8003D608: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8003D60C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8003D610: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8003D614: sb          $t3, 0x1F14($at)
    MEM_B(0X1F14, ctx->r1) = ctx->r11;
    // 0x8003D618: lbu         $t7, 0x2($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X2);
    // 0x8003D61C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003D620: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8003D624: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x8003D628: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8003D62C: lw          $t0, 0x1F18($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F18);
    // 0x8003D630: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8003D634: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8003D638: addu        $a0, $t0, $t5
    ctx->r4 = ADD32(ctx->r8, ctx->r13);
    // 0x8003D63C: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D640: jal         0x800B5CF0
    // 0x8003D644: addiu       $a1, $t4, 0x10
    ctx->r5 = ADD32(ctx->r12, 0X10);
    osGbpakGetStatus(rdram, ctx);
        goto after_73;
    // 0x8003D644: addiu       $a1, $t4, 0x10
    ctx->r5 = ADD32(ctx->r12, 0X10);
    after_73:
    // 0x8003D648: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8003D64C: nop

    // 0x8003D650: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x8003D654: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8003D658: nop

    // 0x8003D65C: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x8003D660: nop

    // 0x8003D664: beq         $t6, $zero, L_8003D69C
    if (ctx->r14 == 0) {
        // 0x8003D668: nop
    
            goto L_8003D69C;
    }
    // 0x8003D668: nop

    // 0x8003D66C: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x8003D670: andi        $t3, $t9, 0xF0
    ctx->r11 = ctx->r25 & 0XF0;
    // 0x8003D674: ori         $t1, $t3, 0xF
    ctx->r9 = ctx->r11 | 0XF;
    // 0x8003D678: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8003D67C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D680: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D688: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D68C: jal         0x800B34D0
    // 0x8003D690: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_74;
    // 0x8003D690: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_74:
    // 0x8003D694: b           L_8003DB30
    // 0x8003D698: nop

        goto L_8003DB30;
    // 0x8003D698: nop

L_8003D69C:
    // 0x8003D69C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D6A0: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D6A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D6A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D6AC: jal         0x800B34D0
    // 0x8003D6B0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_75;
    // 0x8003D6B0: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_75:
    // 0x8003D6B4: b           L_8003DB30
    // 0x8003D6B8: nop

        goto L_8003DB30;
    // 0x8003D6B8: nop

L_8003D6BC:
    // 0x8003D6BC: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x8003D6C0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8003D6C4: lbu         $t5, 0x2($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X2);
    // 0x8003D6C8: lw          $t7, 0x1F18($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F18);
    // 0x8003D6CC: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8003D6D0: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x8003D6D4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8003D6D8: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8003D6DC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8003D6E0: addu        $a0, $t7, $t4
    ctx->r4 = ADD32(ctx->r15, ctx->r12);
    // 0x8003D6E4: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D6E8: jal         0x800B5CF0
    // 0x8003D6EC: addiu       $a1, $t0, 0x10
    ctx->r5 = ADD32(ctx->r8, 0X10);
    osGbpakGetStatus(rdram, ctx);
        goto after_76;
    // 0x8003D6EC: addiu       $a1, $t0, 0x10
    ctx->r5 = ADD32(ctx->r8, 0X10);
    after_76:
    // 0x8003D6F0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8003D6F4: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D6F8: nop

    // 0x8003D6FC: beq         $t2, $zero, L_8003D738
    if (ctx->r10 == 0) {
        // 0x8003D700: nop
    
            goto L_8003D738;
    }
    // 0x8003D700: nop

    // 0x8003D704: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x8003D708: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x8003D70C: andi        $t9, $t6, 0xF0
    ctx->r25 = ctx->r14 & 0XF0;
    // 0x8003D710: ori         $t3, $t9, 0xF
    ctx->r11 = ctx->r25 | 0XF;
    // 0x8003D714: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D718: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8003D71C: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D724: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D728: jal         0x800B34D0
    // 0x8003D72C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_77;
    // 0x8003D72C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_77:
    // 0x8003D730: b           L_8003DB30
    // 0x8003D734: nop

        goto L_8003DB30;
    // 0x8003D734: nop

L_8003D738:
    // 0x8003D738: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8003D73C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003D740: lw          $t5, 0x8($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X8);
    // 0x8003D744: nop

    // 0x8003D748: srl         $t7, $t5, 13
    ctx->r15 = S32(U32(ctx->r13) >> 13);
    // 0x8003D74C: sb          $t7, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r15;
    // 0x8003D750: lbu         $t4, 0x2($t8)
    ctx->r12 = MEM_BU(ctx->r24, 0X2);
    // 0x8003D754: andi        $t2, $t7, 0xFF
    ctx->r10 = ctx->r15 & 0XFF;
    // 0x8003D758: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8003D75C: lbu         $t0, 0x1F14($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X1F14);
    // 0x8003D760: nop

    // 0x8003D764: beq         $t0, $t2, L_8003D83C
    if (ctx->r8 == ctx->r10) {
        // 0x8003D768: nop
    
            goto L_8003D83C;
    }
    // 0x8003D768: nop

    // 0x8003D76C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_8003D770:
    // 0x8003D770: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D774: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x8003D778: addu        $t3, $sp, $t9
    ctx->r11 = ADD32(ctx->r29, ctx->r25);
    // 0x8003D77C: sb          $t6, 0x38($t3)
    MEM_B(0X38, ctx->r11) = ctx->r14;
    // 0x8003D780: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D784: nop

    // 0x8003D788: addiu       $t5, $t1, 0x1
    ctx->r13 = ADD32(ctx->r9, 0X1);
    // 0x8003D78C: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x8003D790: bne         $at, $zero, L_8003D770
    if (ctx->r1 != 0) {
        // 0x8003D794: sw          $t5, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r13;
            goto L_8003D770;
    }
    // 0x8003D794: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x8003D798: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8003D79C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8003D7A0: lbu         $t7, 0x2($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X2);
    // 0x8003D7A4: lw          $t8, 0x1F18($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F18);
    // 0x8003D7A8: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8003D7AC: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
    // 0x8003D7B0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003D7B4: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8003D7B8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8003D7BC: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x8003D7C0: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    // 0x8003D7C4: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D7C8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003D7CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003D7D0: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    // 0x8003D7D4: jal         0x800B5E50
    // 0x8003D7D8: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    osGbpakReadWrite(rdram, ctx);
        goto after_78;
    // 0x8003D7D8: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_78:
    // 0x8003D7DC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8003D7E0: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D7E4: nop

    // 0x8003D7E8: beq         $t6, $zero, L_8003D824
    if (ctx->r14 == 0) {
        // 0x8003D7EC: nop
    
            goto L_8003D824;
    }
    // 0x8003D7EC: nop

    // 0x8003D7F0: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x8003D7F4: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8003D7F8: andi        $t3, $t9, 0xF0
    ctx->r11 = ctx->r25 & 0XF0;
    // 0x8003D7FC: ori         $t1, $t3, 0xF
    ctx->r9 = ctx->r11 | 0XF;
    // 0x8003D800: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D804: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x8003D808: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D80C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D810: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D814: jal         0x800B34D0
    // 0x8003D818: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_79;
    // 0x8003D818: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_79:
    // 0x8003D81C: b           L_8003DB30
    // 0x8003D820: nop

        goto L_8003DB30;
    // 0x8003D820: nop

L_8003D824:
    // 0x8003D824: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8003D828: lbu         $t4, 0x37($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X37);
    // 0x8003D82C: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x8003D830: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D834: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8003D838: sb          $t4, 0x1F14($at)
    MEM_B(0X1F14, ctx->r1) = ctx->r12;
L_8003D83C:
    // 0x8003D83C: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x8003D840: nop

    // 0x8003D844: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8003D848: nop

    // 0x8003D84C: andi        $t6, $t2, 0x1FFF
    ctx->r14 = ctx->r10 & 0X1FFF;
    // 0x8003D850: sw          $t6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r14;
    // 0x8003D854: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8003D858: nop

    // 0x8003D85C: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x8003D860: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8003D864: nop

    // 0x8003D868: addu        $t5, $t3, $t1
    ctx->r13 = ADD32(ctx->r11, ctx->r9);
    // 0x8003D86C: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
L_8003D870:
    // 0x8003D870: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8003D874: nop

    // 0x8003D878: slti        $at, $t7, 0x2001
    ctx->r1 = SIGNED(ctx->r15) < 0X2001 ? 1 : 0;
    // 0x8003D87C: bne         $at, $zero, L_8003DA04
    if (ctx->r1 != 0) {
        // 0x8003D880: nop
    
            goto L_8003DA04;
    }
    // 0x8003D880: nop

    // 0x8003D884: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8003D888: addiu       $t4, $t7, -0x2000
    ctx->r12 = ADD32(ctx->r15, -0X2000);
    // 0x8003D88C: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x8003D890: lbu         $t6, 0x2($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X2);
    // 0x8003D894: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8003D898: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8003D89C: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x8003D8A0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003D8A4: lw          $t8, 0x1F18($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F18);
    // 0x8003D8A8: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x8003D8AC: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8003D8B0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8003D8B4: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x8003D8B8: ori         $at, $zero, 0xA000
    ctx->r1 = 0 | 0XA000;
    // 0x8003D8BC: lw          $a3, 0xC($t2)
    ctx->r7 = MEM_W(ctx->r10, 0XC);
    // 0x8003D8C0: lbu         $a1, 0x10($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X10);
    // 0x8003D8C4: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    // 0x8003D8C8: subu        $t1, $t3, $t9
    ctx->r9 = SUB32(ctx->r11, ctx->r25);
    // 0x8003D8CC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8003D8D0: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D8D4: jal         0x800B5E50
    // 0x8003D8D8: addu        $a2, $t9, $at
    ctx->r6 = ADD32(ctx->r25, ctx->r1);
    osGbpakReadWrite(rdram, ctx);
        goto after_80;
    // 0x8003D8D8: addu        $a2, $t9, $at
    ctx->r6 = ADD32(ctx->r25, ctx->r1);
    after_80:
    // 0x8003D8DC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8003D8E0: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D8E4: nop

    // 0x8003D8E8: bne         $t5, $zero, L_8003DA90
    if (ctx->r13 != 0) {
        // 0x8003D8EC: nop
    
            goto L_8003DA90;
    }
    // 0x8003D8EC: nop

    // 0x8003D8F0: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8003D8F4: nop

    // 0x8003D8F8: lw          $t4, 0xC($t7)
    ctx->r12 = MEM_W(ctx->r15, 0XC);
    // 0x8003D8FC: lw          $t6, 0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X8);
    // 0x8003D900: nop

    // 0x8003D904: subu        $t8, $t4, $t6
    ctx->r24 = SUB32(ctx->r12, ctx->r14);
    // 0x8003D908: addiu       $t0, $t8, 0x2000
    ctx->r8 = ADD32(ctx->r24, 0X2000);
    // 0x8003D90C: sw          $t0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r8;
    // 0x8003D910: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x8003D914: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x8003D918: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8003D91C: sb          $t3, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r11;
L_8003D920:
    // 0x8003D920: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D924: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x8003D928: addu        $t5, $sp, $t1
    ctx->r13 = ADD32(ctx->r29, ctx->r9);
    // 0x8003D92C: sb          $t9, 0x38($t5)
    MEM_B(0X38, ctx->r13) = ctx->r25;
    // 0x8003D930: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D934: nop

    // 0x8003D938: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8003D93C: slti        $at, $t6, 0x20
    ctx->r1 = SIGNED(ctx->r14) < 0X20 ? 1 : 0;
    // 0x8003D940: bne         $at, $zero, L_8003D920
    if (ctx->r1 != 0) {
        // 0x8003D944: sw          $t6, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r14;
            goto L_8003D920;
    }
    // 0x8003D944: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x8003D948: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x8003D94C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8003D950: lbu         $t7, 0x2($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X2);
    // 0x8003D954: lw          $t8, 0x1F18($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F18);
    // 0x8003D958: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x8003D95C: subu        $t2, $t2, $t7
    ctx->r10 = SUB32(ctx->r10, ctx->r15);
    // 0x8003D960: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8003D964: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x8003D968: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8003D96C: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8003D970: addu        $a0, $t8, $t2
    ctx->r4 = ADD32(ctx->r24, ctx->r10);
    // 0x8003D974: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003D978: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003D97C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003D980: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    // 0x8003D984: jal         0x800B5E50
    // 0x8003D988: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    osGbpakReadWrite(rdram, ctx);
        goto after_81;
    // 0x8003D988: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_81:
    // 0x8003D98C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8003D990: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8003D994: nop

    // 0x8003D998: beq         $t9, $zero, L_8003D9D4
    if (ctx->r25 == 0) {
        // 0x8003D99C: nop
    
            goto L_8003D9D4;
    }
    // 0x8003D99C: nop

    // 0x8003D9A0: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x8003D9A4: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x8003D9A8: andi        $t5, $t1, 0xF0
    ctx->r13 = ctx->r9 & 0XF0;
    // 0x8003D9AC: ori         $t4, $t5, 0xF
    ctx->r12 = ctx->r13 | 0XF;
    // 0x8003D9B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003D9B4: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x8003D9B8: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003D9BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D9C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D9C4: jal         0x800B34D0
    // 0x8003D9C8: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_82;
    // 0x8003D9C8: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_82:
    // 0x8003D9CC: b           L_8003DA90
    // 0x8003D9D0: nop

        goto L_8003DA90;
    // 0x8003D9D0: nop

L_8003D9D4:
    // 0x8003D9D4: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8003D9D8: lbu         $t0, 0x37($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X37);
    // 0x8003D9DC: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x8003D9E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D9E4: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8003D9E8: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8003D9EC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8003D9F0: sb          $t0, 0x1F14($at)
    MEM_B(0X1F14, ctx->r1) = ctx->r8;
    // 0x8003D9F4: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8003D9F8: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8003D9FC: b           L_8003D870
    // 0x8003DA00: sw          $zero, 0x8($t9)
    MEM_W(0X8, ctx->r25) = 0;
        goto L_8003D870;
    // 0x8003DA00: sw          $zero, 0x8($t9)
    MEM_W(0X8, ctx->r25) = 0;
L_8003DA04:
    // 0x8003DA04: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8003DA08: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8003DA0C: lbu         $t4, 0x2($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X2);
    // 0x8003DA10: lw          $t1, 0x1F18($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1F18);
    // 0x8003DA14: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8003DA18: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x8003DA1C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003DA20: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8003DA24: lw          $a2, 0x8($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X8);
    // 0x8003DA28: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8003DA2C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8003DA30: ori         $at, $zero, 0xA000
    ctx->r1 = 0 | 0XA000;
    // 0x8003DA34: lbu         $a1, 0x10($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X10);
    // 0x8003DA38: lw          $a3, 0xC($t5)
    ctx->r7 = MEM_W(ctx->r13, 0XC);
    // 0x8003DA3C: addu        $a0, $t1, $t6
    ctx->r4 = ADD32(ctx->r9, ctx->r14);
    // 0x8003DA40: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003DA44: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x8003DA48: jal         0x800B5E50
    // 0x8003DA4C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    osGbpakReadWrite(rdram, ctx);
        goto after_83;
    // 0x8003DA4C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_83:
    // 0x8003DA50: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8003DA54: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003DA58: nop

    // 0x8003DA5C: beq         $t0, $zero, L_8003DA90
    if (ctx->r8 == 0) {
        // 0x8003DA60: nop
    
            goto L_8003DA90;
    }
    // 0x8003DA60: nop

    // 0x8003DA64: sll         $t8, $t0, 4
    ctx->r24 = S32(ctx->r8 << 4);
    // 0x8003DA68: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8003DA6C: andi        $t2, $t8, 0xF0
    ctx->r10 = ctx->r24 & 0XF0;
    // 0x8003DA70: ori         $t3, $t2, 0xF
    ctx->r11 = ctx->r10 | 0XF;
    // 0x8003DA74: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003DA78: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x8003DA7C: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003DA80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003DA84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003DA88: jal         0x800B34D0
    // 0x8003DA8C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_84;
    // 0x8003DA8C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_84:
L_8003DA90:
    // 0x8003DA90: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x8003DA94: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8003DA98: lbu         $t6, 0x2($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X2);
    // 0x8003DA9C: lw          $t4, 0x1F18($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F18);
    // 0x8003DAA0: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8003DAA4: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x8003DAA8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8003DAAC: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8003DAB0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8003DAB4: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x8003DAB8: addiu       $a0, $a0, 0x238C
    ctx->r4 = ADD32(ctx->r4, 0X238C);
    // 0x8003DABC: jal         0x800B5CF0
    // 0x8003DAC0: addiu       $a1, $t1, 0x10
    ctx->r5 = ADD32(ctx->r9, 0X10);
    osGbpakGetStatus(rdram, ctx);
        goto after_85;
    // 0x8003DAC0: addiu       $a1, $t1, 0x10
    ctx->r5 = ADD32(ctx->r9, 0X10);
    after_85:
    // 0x8003DAC4: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8003DAC8: nop

    // 0x8003DACC: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    // 0x8003DAD0: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x8003DAD4: nop

    // 0x8003DAD8: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x8003DADC: nop

    // 0x8003DAE0: beq         $t8, $zero, L_8003DB18
    if (ctx->r24 == 0) {
        // 0x8003DAE4: nop
    
            goto L_8003DB18;
    }
    // 0x8003DAE4: nop

    // 0x8003DAE8: sll         $t2, $t8, 4
    ctx->r10 = S32(ctx->r24 << 4);
    // 0x8003DAEC: andi        $t3, $t2, 0xF0
    ctx->r11 = ctx->r10 & 0XF0;
    // 0x8003DAF0: ori         $t9, $t3, 0xF
    ctx->r25 = ctx->r11 | 0XF;
    // 0x8003DAF4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8003DAF8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003DAFC: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003DB00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003DB04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003DB08: jal         0x800B34D0
    // 0x8003DB0C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_86;
    // 0x8003DB0C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_86:
    // 0x8003DB10: b           L_8003DB30
    // 0x8003DB14: nop

        goto L_8003DB30;
    // 0x8003DB14: nop

L_8003DB18:
    // 0x8003DB18: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003DB1C: lw          $a0, 0x1F18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F18);
    // 0x8003DB20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003DB24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003DB28: jal         0x800B34D0
    // 0x8003DB2C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    osSendMesg_recomp(rdram, ctx);
        goto after_87;
    // 0x8003DB2C: addiu       $a0, $a0, 0x240
    ctx->r4 = ADD32(ctx->r4, 0X240);
    after_87:
L_8003DB30:
    // 0x8003DB30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003DB34: b           L_8003BFE0
    // 0x8003DB38: sb          $t6, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r14;
        goto L_8003BFE0;
    // 0x8003DB38: sb          $t6, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r14;
L_8003DB3C:
    // 0x8003DB3C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003DB40: b           L_8003BFE0
    // 0x8003DB44: sh          $t4, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r12;
        goto L_8003BFE0;
    // 0x8003DB44: sh          $t4, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r12;
    // 0x8003DB48: nop

    // 0x8003DB4C: nop

    // 0x8003DB50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003DB54: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003DB58: jr          $ra
    // 0x8003DB5C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8003DB5C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}

RECOMP_FUNC void FUN_001050_Create_and_Start_ControllerThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DB60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DB64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003DB68: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8003DB6C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8003DB70: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8003DB74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003DB78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003DB7C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003DB80: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8003DB84: addiu       $t7, $t6, 0x2360
    ctx->r15 = ADD32(ctx->r14, 0X2360);
    // 0x8003DB88: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003DB8C: addiu       $a2, $a2, -0x4070
    ctx->r6 = ADD32(ctx->r6, -0X4070);
    // 0x8003DB90: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8003DB94: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8003DB98: jal         0x800B6010
    // 0x8003DB9C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x8003DB9C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x8003DBA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003DBA4: jal         0x800B6160
    // 0x8003DBA8: nop

    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x8003DBA8: nop

    after_1:
    // 0x8003DBAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DBB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003DBB4: jr          $ra
    // 0x8003DBB8: nop

    return;
    // 0x8003DBB8: nop

    // 0x8003DBBC: nop

;}

RECOMP_FUNC void FUN_003E40_8003dbc0_twentyliner_nested_loops(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DBC0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003DBC4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8003DBC8: lw          $t6, -0x490($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X490);
    // 0x8003DBCC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003DBD0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8003DBD4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003DBD8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8003DBDC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003DBE0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003DBE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003DBE8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8003DBEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003DBF0: beq         $t7, $at, L_8003DC00
    if (ctx->r15 == ctx->r1) {
        // 0x8003DBF4: nop
    
            goto L_8003DC00;
    }
    // 0x8003DBF4: nop

    // 0x8003DBF8: b           L_8003DD90
    // 0x8003DBFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003DD90;
    // 0x8003DBFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003DC00:
    // 0x8003DC00: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8003DC04: lw          $t9, -0x490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X490);
    // 0x8003DC08: sb          $zero, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = 0;
    // 0x8003DC0C: lb          $t8, 0x37($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X37);
    // 0x8003DC10: lb          $t0, 0x12($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X12);
    // 0x8003DC14: nop

    // 0x8003DC18: subu        $s2, $t8, $t0
    ctx->r18 = SUB32(ctx->r24, ctx->r8);
    // 0x8003DC1C: sll         $t1, $s2, 24
    ctx->r9 = S32(ctx->r18 << 24);
    // 0x8003DC20: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x8003DC24: sra         $t2, $s2, 24
    ctx->r10 = S32(SIGNED(ctx->r18) >> 24);
    // 0x8003DC28: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x8003DC2C: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x8003DC30: sll         $t3, $s1, 24
    ctx->r11 = S32(ctx->r17 << 24);
    // 0x8003DC34: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x8003DC38: sra         $t4, $s1, 24
    ctx->r12 = S32(SIGNED(ctx->r17) >> 24);
    // 0x8003DC3C: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x8003DC40: addiu       $t5, $s2, 0x2
    ctx->r13 = ADD32(ctx->r18, 0X2);
    // 0x8003DC44: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8003DC48: beq         $at, $zero, L_8003DD88
    if (ctx->r1 == 0) {
        // 0x8003DC4C: nop
    
            goto L_8003DD88;
    }
    // 0x8003DC4C: nop

L_8003DC50:
    // 0x8003DC50: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8003DC54: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x8003DC58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003DC5C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8003DC60: jal         0x80066D8C
    // 0x8003DC64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    CurrentPiece_TestTransform(rdram, ctx);
        goto after_0;
    // 0x8003DC64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8003DC68: beq         $v0, $zero, L_8003DD64
    if (ctx->r2 == 0) {
        // 0x8003DC6C: nop
    
            goto L_8003DD64;
    }
    // 0x8003DC6C: nop

    // 0x8003DC70: addiu       $s0, $zero, -0x2
    ctx->r16 = ADD32(0, -0X2);
    // 0x8003DC74: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8003DC78: beq         $at, $zero, L_8003DD54
    if (ctx->r1 == 0) {
        // 0x8003DC7C: nop
    
            goto L_8003DD54;
    }
    // 0x8003DC7C: nop

L_8003DC80:
    // 0x8003DC80: beq         $s0, $zero, L_8003DD34
    if (ctx->r16 == 0) {
        // 0x8003DC84: nop
    
            goto L_8003DD34;
    }
    // 0x8003DC84: nop

    // 0x8003DC88: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8003DC8C: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x8003DC90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003DC94: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8003DC98: jal         0x80066D8C
    // 0x8003DC9C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    CurrentPiece_TestTransform(rdram, ctx);
        goto after_1;
    // 0x8003DC9C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8003DCA0: beq         $v0, $zero, L_8003DD34
    if (ctx->r2 == 0) {
        // 0x8003DCA4: nop
    
            goto L_8003DD34;
    }
    // 0x8003DCA4: nop

    // 0x8003DCA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8003DCAC: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x8003DCB0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8003DCB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8003DCB8: jal         0x80066D8C
    // 0x8003DCBC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    CurrentPiece_TestTransform(rdram, ctx);
        goto after_2;
    // 0x8003DCBC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x8003DCC0: bne         $v0, $zero, L_8003DD34
    if (ctx->r2 != 0) {
        // 0x8003DCC4: nop
    
            goto L_8003DD34;
    }
    // 0x8003DCC4: nop

    // 0x8003DCC8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8003DCCC: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x8003DCD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003DCD4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8003DCD8: jal         0x80066D8C
    // 0x8003DCDC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    CurrentPiece_TestTransform(rdram, ctx);
        goto after_3;
    // 0x8003DCDC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x8003DCE0: bne         $v0, $zero, L_8003DD34
    if (ctx->r2 != 0) {
        // 0x8003DCE4: nop
    
            goto L_8003DD34;
    }
    // 0x8003DCE4: nop

    // 0x8003DCE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8003DCEC: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x8003DCF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003DCF4: addiu       $a2, $s1, -0x1
    ctx->r6 = ADD32(ctx->r17, -0X1);
    // 0x8003DCF8: jal         0x80066D8C
    // 0x8003DCFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    CurrentPiece_TestTransform(rdram, ctx);
        goto after_4;
    // 0x8003DCFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8003DD00: bne         $v0, $zero, L_8003DD34
    if (ctx->r2 != 0) {
        // 0x8003DD04: nop
    
            goto L_8003DD34;
    }
    // 0x8003DD04: nop

    // 0x8003DD08: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8003DD0C: lw          $a0, -0x490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X490);
    // 0x8003DD10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003DD14: addiu       $a2, $s1, 0x1
    ctx->r6 = ADD32(ctx->r17, 0X1);
    // 0x8003DD18: jal         0x80066D8C
    // 0x8003DD1C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    CurrentPiece_TestTransform(rdram, ctx);
        goto after_5;
    // 0x8003DD1C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_5:
    // 0x8003DD20: bne         $v0, $zero, L_8003DD34
    if (ctx->r2 != 0) {
        // 0x8003DD24: nop
    
            goto L_8003DD34;
    }
    // 0x8003DD24: nop

    // 0x8003DD28: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003DD2C: b           L_8003DD54
    // 0x8003DD30: sb          $t6, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r14;
        goto L_8003DD54;
    // 0x8003DD30: sb          $t6, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r14;
L_8003DD34:
    // 0x8003DD34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003DD38: sll         $t7, $s0, 24
    ctx->r15 = S32(ctx->r16 << 24);
    // 0x8003DD3C: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8003DD40: sra         $t9, $s0, 24
    ctx->r25 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8003DD44: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8003DD48: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8003DD4C: bne         $at, $zero, L_8003DC80
    if (ctx->r1 != 0) {
        // 0x8003DD50: nop
    
            goto L_8003DC80;
    }
    // 0x8003DD50: nop

L_8003DD54:
    // 0x8003DD54: lbu         $t8, 0x2C($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2C);
    // 0x8003DD58: nop

    // 0x8003DD5C: bne         $t8, $zero, L_8003DD88
    if (ctx->r24 != 0) {
        // 0x8003DD60: nop
    
            goto L_8003DD88;
    }
    // 0x8003DD60: nop

L_8003DD64:
    // 0x8003DD64: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003DD68: sll         $t0, $s1, 24
    ctx->r8 = S32(ctx->r17 << 24);
    // 0x8003DD6C: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x8003DD70: sra         $t1, $s1, 24
    ctx->r9 = S32(SIGNED(ctx->r17) >> 24);
    // 0x8003DD74: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8003DD78: addiu       $t2, $s2, 0x2
    ctx->r10 = ADD32(ctx->r18, 0X2);
    // 0x8003DD7C: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003DD80: bne         $at, $zero, L_8003DC50
    if (ctx->r1 != 0) {
        // 0x8003DD84: nop
    
            goto L_8003DC50;
    }
    // 0x8003DD84: nop

L_8003DD88:
    // 0x8003DD88: lbu         $v0, 0x2C($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2C);
    // 0x8003DD8C: nop

L_8003DD90:
    // 0x8003DD90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003DD94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003DD98: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DD9C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003DDA0: jr          $ra
    // 0x8003DDA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8003DDA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void FUN_003E40_8003dda8_twentyfiveliner_nested_loops(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DDA8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003DDAC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003DDB0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8003DDB4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8003DDB8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8003DDBC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8003DDC0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8003DDC4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003DDC8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003DDCC: jal         0x800412E0
    // 0x8003DDD0: addiu       $a0, $sp, 0x33
    ctx->r4 = ADD32(ctx->r29, 0X33);
    aisquarelist_BuildBoardModel(rdram, ctx);
        goto after_0;
    // 0x8003DDD0: addiu       $a0, $sp, 0x33
    ctx->r4 = ADD32(ctx->r29, 0X33);
    after_0:
    // 0x8003DDD4: lb          $t6, 0x3F($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X3F);
    // 0x8003DDD8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003DDDC: addiu       $s3, $t6, -0x1
    ctx->r19 = ADD32(ctx->r14, -0X1);
    // 0x8003DDE0: sll         $t7, $s3, 24
    ctx->r15 = S32(ctx->r19 << 24);
    // 0x8003DDE4: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
    // 0x8003DDE8: sra         $t8, $s3, 24
    ctx->r24 = S32(SIGNED(ctx->r19) >> 24);
    // 0x8003DDEC: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x8003DDF0: addiu       $t9, $t6, 0x4
    ctx->r25 = ADD32(ctx->r14, 0X4);
    // 0x8003DDF4: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003DDF8: beq         $at, $zero, L_8003DF80
    if (ctx->r1 == 0) {
        // 0x8003DDFC: nop
    
            goto L_8003DF80;
    }
    // 0x8003DDFC: nop

L_8003DE00:
    // 0x8003DE00: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x8003DE04: lbu         $a2, 0x43($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X43);
    // 0x8003DE08: jal         0x80041810
    // 0x8003DE0C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    aisquarelist_CanPieceMove(rdram, ctx);
        goto after_1;
    // 0x8003DE0C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x8003DE10: beq         $v0, $zero, L_8003DF58
    if (ctx->r2 == 0) {
        // 0x8003DE14: nop
    
            goto L_8003DF58;
    }
    // 0x8003DE14: nop

    // 0x8003DE18: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x8003DE1C: lbu         $a2, 0x43($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X43);
    // 0x8003DE20: jal         0x800416CC
    // 0x8003DE24: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    aisquarelist_TryPlacePiece(rdram, ctx);
        goto after_2;
    // 0x8003DE24: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x8003DE28: beq         $v0, $zero, L_8003DF58
    if (ctx->r2 == 0) {
        // 0x8003DE2C: nop
    
            goto L_8003DF58;
    }
    // 0x8003DE2C: nop

    // 0x8003DE30: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x8003DE34: lbu         $a2, 0x43($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X43);
    // 0x8003DE38: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8003DE3C: jal         0x800413C0
    // 0x8003DE40: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_3;
    // 0x8003DE40: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_3:
    // 0x8003DE44: addiu       $t0, $s3, -0x3
    ctx->r8 = ADD32(ctx->r19, -0X3);
    // 0x8003DE48: blez        $t0, L_8003DE68
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8003DE4C: nop
    
            goto L_8003DE68;
    }
    // 0x8003DE4C: nop

    // 0x8003DE50: addiu       $s1, $s3, -0x3
    ctx->r17 = ADD32(ctx->r19, -0X3);
    // 0x8003DE54: sll         $t1, $s1, 24
    ctx->r9 = S32(ctx->r17 << 24);
    // 0x8003DE58: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8003DE5C: sra         $t2, $s1, 24
    ctx->r10 = S32(SIGNED(ctx->r17) >> 24);
    // 0x8003DE60: b           L_8003DE6C
    // 0x8003DE64: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
        goto L_8003DE6C;
    // 0x8003DE64: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
L_8003DE68:
    // 0x8003DE68: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8003DE6C:
    // 0x8003DE6C: slt         $at, $s3, $s1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8003DE70: bne         $at, $zero, L_8003DF3C
    if (ctx->r1 != 0) {
        // 0x8003DE74: nop
    
            goto L_8003DF3C;
    }
    // 0x8003DE74: nop

L_8003DE78:
    // 0x8003DE78: lbu         $t3, 0x3B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3B);
    // 0x8003DE7C: nop

    // 0x8003DE80: addiu       $t4, $t3, -0x3
    ctx->r12 = ADD32(ctx->r11, -0X3);
    // 0x8003DE84: blez        $t4, L_8003DE9C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8003DE88: nop
    
            goto L_8003DE9C;
    }
    // 0x8003DE88: nop

    // 0x8003DE8C: sll         $s0, $t4, 24
    ctx->r16 = S32(ctx->r12 << 24);
    // 0x8003DE90: sra         $t5, $s0, 24
    ctx->r13 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8003DE94: b           L_8003DEA0
    // 0x8003DE98: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
        goto L_8003DEA0;
    // 0x8003DE98: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
L_8003DE9C:
    // 0x8003DE9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8003DEA0:
    // 0x8003DEA0: lbu         $t7, 0x3B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3B);
    // 0x8003DEA4: nop

    // 0x8003DEA8: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8003DEAC: bne         $at, $zero, L_8003DF14
    if (ctx->r1 != 0) {
        // 0x8003DEB0: nop
    
            goto L_8003DF14;
    }
    // 0x8003DEB0: nop

L_8003DEB4:
    // 0x8003DEB4: addiu       $t8, $sp, 0x31
    ctx->r24 = ADD32(ctx->r29, 0X31);
    // 0x8003DEB8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003DEBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003DEC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003DEC4: addiu       $a2, $sp, 0x33
    ctx->r6 = ADD32(ctx->r29, 0X33);
    // 0x8003DEC8: jal         0x80041B48
    // 0x8003DECC: addiu       $a3, $sp, 0x32
    ctx->r7 = ADD32(ctx->r29, 0X32);
    check_square_completion(rdram, ctx);
        goto after_4;
    // 0x8003DECC: addiu       $a3, $sp, 0x32
    ctx->r7 = ADD32(ctx->r29, 0X32);
    after_4:
    // 0x8003DED0: beq         $v0, $zero, L_8003DEF0
    if (ctx->r2 == 0) {
        // 0x8003DED4: nop
    
            goto L_8003DEF0;
    }
    // 0x8003DED4: nop

    // 0x8003DED8: lbu         $t6, 0x32($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X32);
    // 0x8003DEDC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003DEE0: bne         $t6, $at, L_8003DEF0
    if (ctx->r14 != ctx->r1) {
        // 0x8003DEE4: nop
    
            goto L_8003DEF0;
    }
    // 0x8003DEE4: nop

    // 0x8003DEE8: b           L_8003DF14
    // 0x8003DEEC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8003DF14;
    // 0x8003DEEC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8003DEF0:
    // 0x8003DEF0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003DEF4: sll         $t9, $s0, 24
    ctx->r25 = S32(ctx->r16 << 24);
    // 0x8003DEF8: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8003DEFC: lbu         $t1, 0x3B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3B);
    // 0x8003DF00: sra         $t0, $s0, 24
    ctx->r8 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8003DF04: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x8003DF08: slt         $at, $t1, $s0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8003DF0C: beq         $at, $zero, L_8003DEB4
    if (ctx->r1 == 0) {
        // 0x8003DF10: nop
    
            goto L_8003DEB4;
    }
    // 0x8003DF10: nop

L_8003DF14:
    // 0x8003DF14: bne         $s2, $zero, L_8003DF3C
    if (ctx->r18 != 0) {
        // 0x8003DF18: nop
    
            goto L_8003DF3C;
    }
    // 0x8003DF18: nop

    // 0x8003DF1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003DF20: sll         $t2, $s1, 24
    ctx->r10 = S32(ctx->r17 << 24);
    // 0x8003DF24: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x8003DF28: sra         $t3, $s1, 24
    ctx->r11 = S32(SIGNED(ctx->r17) >> 24);
    // 0x8003DF2C: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x8003DF30: slt         $at, $s3, $s1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8003DF34: beq         $at, $zero, L_8003DE78
    if (ctx->r1 == 0) {
        // 0x8003DF38: nop
    
            goto L_8003DE78;
    }
    // 0x8003DF38: nop

L_8003DF3C:
    // 0x8003DF3C: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x8003DF40: lbu         $a2, 0x43($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X43);
    // 0x8003DF44: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8003DF48: jal         0x800413C0
    // 0x8003DF4C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_5;
    // 0x8003DF4C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_5:
    // 0x8003DF50: bne         $s2, $zero, L_8003DF80
    if (ctx->r18 != 0) {
        // 0x8003DF54: nop
    
            goto L_8003DF80;
    }
    // 0x8003DF54: nop

L_8003DF58:
    // 0x8003DF58: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003DF5C: sll         $t4, $s3, 24
    ctx->r12 = S32(ctx->r19 << 24);
    // 0x8003DF60: lb          $t7, 0x3F($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X3F);
    // 0x8003DF64: or          $s3, $t4, $zero
    ctx->r19 = ctx->r12 | 0;
    // 0x8003DF68: sra         $t5, $s3, 24
    ctx->r13 = S32(SIGNED(ctx->r19) >> 24);
    // 0x8003DF6C: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x8003DF70: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8003DF74: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003DF78: bne         $at, $zero, L_8003DE00
    if (ctx->r1 != 0) {
        // 0x8003DF7C: nop
    
            goto L_8003DE00;
    }
    // 0x8003DF7C: nop

L_8003DF80:
    // 0x8003DF80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003DF84: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x8003DF88: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8003DF8C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF90: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003DF94: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8003DF98: jr          $ra
    // 0x8003DF9C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003DF9C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void FUN_004220_8003dfa0_sixliner_allocs_heap_x962(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DFA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003DFA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003DFA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003DFAC: jal         0x8007E03C
    // 0x8003DFB0: addiu       $a0, $zero, 0x962
    ctx->r4 = ADD32(0, 0X962);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8003DFB0: addiu       $a0, $zero, 0x962
    ctx->r4 = ADD32(0, 0X962);
    after_0:
    // 0x8003DFB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003DFB8: sw          $v0, 0x1F20($at)
    MEM_W(0X1F20, ctx->r1) = ctx->r2;
    // 0x8003DFBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003DFC0: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8003DFC4: beq         $at, $zero, L_8003DFF4
    if (ctx->r1 == 0) {
        // 0x8003DFC8: nop
    
            goto L_8003DFF4;
    }
    // 0x8003DFC8: nop

L_8003DFCC:
    // 0x8003DFCC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8003DFD0: lw          $t6, 0x1F20($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F20);
    // 0x8003DFD4: nop

    // 0x8003DFD8: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003DFDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003DFE0: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x8003DFE4: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8003DFE8: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8003DFEC: bne         $at, $zero, L_8003DFCC
    if (ctx->r1 != 0) {
        // 0x8003DFF0: sb          $zero, 0x0($t7)
        MEM_B(0X0, ctx->r15) = 0;
            goto L_8003DFCC;
    }
    // 0x8003DFF0: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
L_8003DFF4:
    // 0x8003DFF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DFF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003DFFC: jr          $ra
    // 0x8003E000: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003E000: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void FUN_004220_8003e004_threeliner_unallocs_heap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E004: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8003E008: lw          $t6, 0x1F20($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F20);
    // 0x8003E00C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E010: beq         $t6, $zero, L_8003E028
    if (ctx->r14 == 0) {
        // 0x8003E014: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8003E028;
    }
    // 0x8003E014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E018: jal         0x8007E328
    // 0x8003E01C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x8003E01C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8003E020: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E024: sw          $zero, 0x1F20($at)
    MEM_W(0X1F20, ctx->r1) = 0;
L_8003E028:
    // 0x8003E028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E02C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E030: jr          $ra
    // 0x8003E034: nop

    return;
    // 0x8003E034: nop

;}

RECOMP_FUNC void FUN_004220_8003e038_twentytwoliner_nested_loops(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E038: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003E03C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8003E040: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8003E044: lw          $t6, 0x1F20($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F20);
    // 0x8003E048: lbu         $t7, 0x3B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3B);
    // 0x8003E04C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003E050: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003E054: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003E058: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8003E05C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003E060: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003E064: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8003E068: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8003E06C: beq         $at, $zero, L_8003E1C0
    if (ctx->r1 == 0) {
        // 0x8003E070: sb          $zero, 0x0($t8)
        MEM_B(0X0, ctx->r24) = 0;
            goto L_8003E1C0;
    }
    // 0x8003E070: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
L_8003E074:
    // 0x8003E074: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003E078: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8003E07C: beq         $at, $zero, L_8003E1A8
    if (ctx->r1 == 0) {
        // 0x8003E080: nop
    
            goto L_8003E1A8;
    }
    // 0x8003E080: nop

L_8003E084:
    // 0x8003E084: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x8003E088: lbu         $a3, 0x3F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003E08C: sb          $t9, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r25;
    // 0x8003E090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E094: addiu       $a1, $sp, 0x2F
    ctx->r5 = ADD32(ctx->r29, 0X2F);
    // 0x8003E098: jal         0x8004199C
    // 0x8003E09C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    aisquarelist_DropPieceToRow(rdram, ctx);
        goto after_0;
    // 0x8003E09C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x8003E0A0: beq         $v0, $zero, L_8003E190
    if (ctx->r2 == 0) {
        // 0x8003E0A4: nop
    
            goto L_8003E190;
    }
    // 0x8003E0A4: nop

L_8003E0A8:
    // 0x8003E0A8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003E0AC: lw          $t0, 0x1F20($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F20);
    // 0x8003E0B0: lbu         $t1, 0x3B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3B);
    // 0x8003E0B4: nop

    // 0x8003E0B8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8003E0BC: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x8003E0C0: nop

    // 0x8003E0C4: slti        $at, $t3, 0x190
    ctx->r1 = SIGNED(ctx->r11) < 0X190 ? 1 : 0;
    // 0x8003E0C8: beq         $at, $zero, L_8003E1C0
    if (ctx->r1 == 0) {
        // 0x8003E0CC: nop
    
            goto L_8003E1C0;
    }
    // 0x8003E0CC: nop

    // 0x8003E0D0: lbu         $t5, 0x3B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X3B);
    // 0x8003E0D4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8003E0D8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8003E0DC: lw          $t4, 0x1F20($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F20);
    // 0x8003E0E0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8003E0E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003E0E8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8003E0EC: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x8003E0F0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8003E0F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003E0F8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8003E0FC: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8003E100: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8003E104: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8003E108: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8003E10C: addu        $s2, $t7, $t0
    ctx->r18 = ADD32(ctx->r15, ctx->r8);
    // 0x8003E110: sb          $s0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r16;
    // 0x8003E114: lbu         $t1, 0x2F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2F);
    // 0x8003E118: sb          $s1, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r17;
    // 0x8003E11C: sb          $t1, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r9;
    // 0x8003E120: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8003E124: lw          $t2, 0x1F20($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1F20);
    // 0x8003E128: lbu         $t3, 0x3B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3B);
    // 0x8003E12C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8003E130: addu        $t6, $t2, $t3
    ctx->r14 = ADD32(ctx->r10, ctx->r11);
    // 0x8003E134: lbu         $t4, 0x0($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X0);
    // 0x8003E138: nop

    // 0x8003E13C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8003E140: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x8003E144: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x8003E148: nop

    // 0x8003E14C: beq         $t8, $zero, L_8003E190
    if (ctx->r24 == 0) {
        // 0x8003E150: nop
    
            goto L_8003E190;
    }
    // 0x8003E150: nop

    // 0x8003E154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E158: jal         0x8004191C
    // 0x8003E15C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    aisquarelist_IsColumnClearToTop(rdram, ctx);
        goto after_1;
    // 0x8003E15C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_1:
    // 0x8003E160: bne         $v0, $zero, L_8003E190
    if (ctx->r2 != 0) {
        // 0x8003E164: nop
    
            goto L_8003E190;
    }
    // 0x8003E164: nop

    // 0x8003E168: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x8003E16C: lbu         $a3, 0x3F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003E170: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x8003E174: sb          $t7, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r15;
    // 0x8003E178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E17C: addiu       $a1, $sp, 0x2F
    ctx->r5 = ADD32(ctx->r29, 0X2F);
    // 0x8003E180: jal         0x8004199C
    // 0x8003E184: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    aisquarelist_DropPieceToRow(rdram, ctx);
        goto after_2;
    // 0x8003E184: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x8003E188: bne         $v0, $zero, L_8003E0A8
    if (ctx->r2 != 0) {
        // 0x8003E18C: nop
    
            goto L_8003E0A8;
    }
    // 0x8003E18C: nop

L_8003E190:
    // 0x8003E190: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003E194: andi        $t0, $s1, 0xFF
    ctx->r8 = ctx->r17 & 0XFF;
    // 0x8003E198: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x8003E19C: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8003E1A0: bne         $at, $zero, L_8003E084
    if (ctx->r1 != 0) {
        // 0x8003E1A4: nop
    
            goto L_8003E084;
    }
    // 0x8003E1A4: nop

L_8003E1A8:
    // 0x8003E1A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003E1AC: andi        $t1, $s0, 0xFF
    ctx->r9 = ctx->r16 & 0XFF;
    // 0x8003E1B0: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x8003E1B4: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8003E1B8: bne         $at, $zero, L_8003E074
    if (ctx->r1 != 0) {
        // 0x8003E1BC: nop
    
            goto L_8003E074;
    }
    // 0x8003E1BC: nop

L_8003E1C0:
    // 0x8003E1C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E1C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003E1C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E1CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003E1D0: jr          $ra
    // 0x8003E1D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003E1D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8003E1D8: nop

    // 0x8003E1DC: nop

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
    func_800875EC(rdram, ctx);
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
    func_800875EC(rdram, ctx);
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
    func_800875EC(rdram, ctx);
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
    wonders2_80045e50_sets_num_won_compl_q(rdram, ctx);
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

RECOMP_FUNC void func_8007C650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C650: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007C654: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C658: addiu       $t6, $t6, -0x2F0
    ctx->r14 = ADD32(ctx->r14, -0X2F0);
    // 0x8007C65C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C660: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8007C664: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8007C668:
    // 0x8007C668: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007C66C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8007C670: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8007C674: addiu       $t9, $t8, -0x10
    ctx->r25 = ADD32(ctx->r24, -0X10);
    // 0x8007C678: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8007C67C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007C680: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007C684: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8007C688: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007C68C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
L_8007C690:
    // 0x8007C690: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007C694: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8007C698: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8007C69C: addiu       $t2, $t1, -0x10
    ctx->r10 = ADD32(ctx->r9, -0X10);
    // 0x8007C6A0: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8007C6A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007C6A8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007C6AC: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007C6B0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007C6B4: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007C6B8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007C6BC: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8007C6C0: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8007C6C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007C6C8: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8007C6CC: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007C6D0: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007C6D4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8007C6D8: sub.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d - ctx->f4.d;
    // 0x8007C6DC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8007C6E0: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8007C6E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007C6E8: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8007C6EC: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8007C6F0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8007C6F4: bc1f        L_8007C708
    if (!c1cs) {
        // 0x8007C6F8: nop
    
            goto L_8007C708;
    }
    // 0x8007C6F8: nop

    // 0x8007C6FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007C700: nop

    // 0x8007C704: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
L_8007C708:
    // 0x8007C708: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8007C70C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007C710: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007C714: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C718: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8007C71C: lwc1        $f16, 0x30A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8007C720: jal         0x800B81D0
    // 0x8007C724: sub.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f16.fl;
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007C724: sub.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f16.fl;
    after_0:
    // 0x8007C728: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C72C: lwc1        $f7, -0x2110($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2110);
    // 0x8007C730: lwc1        $f6, -0x210C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X210C);
    // 0x8007C734: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8007C738: mul.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8007C73C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C740: lwc1        $f11, -0x2108($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2108);
    // 0x8007C744: lwc1        $f10, -0x2104($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2104);
    // 0x8007C748: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007C74C: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x8007C750: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C754: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8007C758: mul.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8007C75C: lwc1        $f16, -0x20FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X20FC);
    // 0x8007C760: lwc1        $f17, -0x2100($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X2100);
    // 0x8007C764: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007C768: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8007C76C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8007C770: mul.d       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8007C774: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8007C778: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8007C77C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8007C780: nop

    // 0x8007C784: cvt.w.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_D(ctx->f8.d);
    // 0x8007C788: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8007C78C: nop

    // 0x8007C790: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x8007C794: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8007C798: beq         $t4, $zero, L_8007C7EC
    if (ctx->r12 == 0) {
        // 0x8007C79C: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_8007C7EC;
    }
    // 0x8007C79C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8007C7A0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007C7A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007C7A8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007C7AC: sub.d       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f8.d - ctx->f18.d;
    // 0x8007C7B0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8007C7B4: nop

    // 0x8007C7B8: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x8007C7BC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8007C7C0: nop

    // 0x8007C7C4: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x8007C7C8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8007C7CC: bne         $t4, $zero, L_8007C7E4
    if (ctx->r12 != 0) {
        // 0x8007C7D0: nop
    
            goto L_8007C7E4;
    }
    // 0x8007C7D0: nop

    // 0x8007C7D4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8007C7D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C7DC: b           L_8007C7FC
    // 0x8007C7E0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8007C7FC;
    // 0x8007C7E0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8007C7E4:
    // 0x8007C7E4: b           L_8007C7FC
    // 0x8007C7E8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8007C7FC;
    // 0x8007C7E8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_8007C7EC:
    // 0x8007C7EC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8007C7F0: nop

    // 0x8007C7F4: bltz        $t4, L_8007C7E4
    if (SIGNED(ctx->r12) < 0) {
        // 0x8007C7F8: nop
    
            goto L_8007C7E4;
    }
    // 0x8007C7F8: nop

L_8007C7FC:
    // 0x8007C7FC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C800: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8007C804: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x8007C808: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8007C80C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C810: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007C814: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x8007C818: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8007C81C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8007C820: bne         $at, $zero, L_8007C690
    if (ctx->r1 != 0) {
        // 0x8007C824: sw          $t7, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r15;
            goto L_8007C690;
    }
    // 0x8007C824: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8007C828: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007C82C: nop

    // 0x8007C830: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007C834: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x8007C838: bne         $at, $zero, L_8007C668
    if (ctx->r1 != 0) {
        // 0x8007C83C: sw          $t1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r9;
            goto L_8007C668;
    }
    // 0x8007C83C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8007C840: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C844: lwc1        $f6, 0x30A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8007C848: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C84C: lwc1        $f11, -0x20F8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X20F8);
    // 0x8007C850: lwc1        $f10, -0x20F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X20F4);
    // 0x8007C854: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8007C858: add.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d + ctx->f10.d;
    // 0x8007C85C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C860: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8007C864: swc1        $f8, 0x30A8($at)
    MEM_W(0X30A8, ctx->r1) = ctx->f8.u32l;
    // 0x8007C868: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C86C: lwc1        $f7, -0x20F0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X20F0);
    // 0x8007C870: lwc1        $f6, -0x20EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X20EC);
    // 0x8007C874: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8007C878: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8007C87C: nop

    // 0x8007C880: bc1f        L_8007C8A0
    if (!c1cs) {
        // 0x8007C884: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007C8A0;
    }
    // 0x8007C884: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C888: lwc1        $f5, -0x20E8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X20E8);
    // 0x8007C88C: lwc1        $f4, -0x20E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X20E4);
    // 0x8007C890: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C894: sub.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f18.d - ctx->f4.d;
    // 0x8007C898: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8007C89C: swc1        $f16, 0x30A8($at)
    MEM_W(0X30A8, ctx->r1) = ctx->f16.u32l;
L_8007C8A0:
    // 0x8007C8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C8A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007C8A8: jr          $ra
    // 0x8007C8AC: nop

    return;
    // 0x8007C8AC: nop

;}

RECOMP_FUNC void func_8007C8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C8B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007C8B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007C8B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007C8BC: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8007C8C0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8007C8C4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8007C8C8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_8007C8CC:
    // 0x8007C8CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C8D0: lwc1        $f14, -0x20E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X20E0);
    // 0x8007C8D4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8007C8D8: jal         0x800A36F0
    // 0x8007C8DC: nop

    func_800A36F0(rdram, ctx);
        goto after_0;
    // 0x8007C8DC: nop

    after_0:
    // 0x8007C8E0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8007C8E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C8E8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8007C8EC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007C8F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007C8F4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007C8F8: swc1        $f0, -0x1EC($at)
    MEM_W(-0X1EC, ctx->r1) = ctx->f0.u32l;
    // 0x8007C8FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C900: lwc1        $f12, -0x20DC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X20DC);
    // 0x8007C904: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C908: lwc1        $f14, -0x20D8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X20D8);
    // 0x8007C90C: jal         0x800A36F0
    // 0x8007C910: nop

    func_800A36F0(rdram, ctx);
        goto after_1;
    // 0x8007C910: nop

    after_1:
    // 0x8007C914: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8007C918: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007C91C: jal         0x800A35EC
    // 0x8007C920: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A35EC(rdram, ctx);
        goto after_2;
    // 0x8007C920: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8007C924: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8007C928: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007C92C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8007C930: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007C934: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007C938: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8007C93C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8007C940: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8007C944: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007C948: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C94C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8007C950: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8007C954: swc1        $f10, -0x1E8($at)
    MEM_W(-0X1E8, ctx->r1) = ctx->f10.u32l;
    // 0x8007C958: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C95C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8007C960: lwc1        $f16, -0x20D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X20D4);
    // 0x8007C964: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007C968: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8007C96C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007C970: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C974: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8007C978: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8007C97C: swc1        $f16, -0x1F0($at)
    MEM_W(-0X1F0, ctx->r1) = ctx->f16.u32l;
    // 0x8007C980: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8007C984: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007C988: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C98C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8007C990: lwc1        $f12, -0x1EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1EC);
    // 0x8007C994: jal         0x800B81D0
    // 0x8007C998: nop

    cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8007C998: nop

    after_3:
    // 0x8007C99C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8007C9A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007C9A4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8007C9A8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007C9AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007C9B0: addiu       $t8, $t8, -0x1F0
    ctx->r24 = ADD32(ctx->r24, -0X1F0);
    // 0x8007C9B4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8007C9B8: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8007C9BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C9C0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8007C9C4: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x8007C9C8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007C9CC: nop

    // 0x8007C9D0: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8007C9D4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8007C9D8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007C9DC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8007C9E0: lwc1        $f12, -0x1EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1EC);
    // 0x8007C9E4: jal         0x800B7B40
    // 0x8007C9E8: nop

    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8007C9E8: nop

    after_4:
    // 0x8007C9EC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8007C9F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007C9F4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8007C9F8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8007C9FC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007CA00: addiu       $t4, $t4, -0x1F0
    ctx->r12 = ADD32(ctx->r12, -0X1F0);
    // 0x8007CA04: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8007CA08: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8007CA0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CA10: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007CA14: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8007CA18: swc1        $f8, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f8.u32l;
    // 0x8007CA1C: lwc1        $f14, -0x20D0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X20D0);
    // 0x8007CA20: jal         0x800A36F0
    // 0x8007CA24: nop

    func_800A36F0(rdram, ctx);
        goto after_5;
    // 0x8007CA24: nop

    after_5:
    // 0x8007CA28: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8007CA2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007CA30: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8007CA34: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007CA38: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007CA3C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007CA40: swc1        $f0, -0x1DC($at)
    MEM_W(-0X1DC, ctx->r1) = ctx->f0.u32l;
    // 0x8007CA44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CA48: lwc1        $f12, -0x20CC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X20CC);
    // 0x8007CA4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CA50: lwc1        $f14, -0x20C8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X20C8);
    // 0x8007CA54: jal         0x800A36F0
    // 0x8007CA58: nop

    func_800A36F0(rdram, ctx);
        goto after_6;
    // 0x8007CA58: nop

    after_6:
    // 0x8007CA5C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8007CA60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007CA64: jal         0x800A35EC
    // 0x8007CA68: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A35EC(rdram, ctx);
        goto after_7;
    // 0x8007CA68: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8007CA6C: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8007CA70: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007CA74: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8007CA78: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007CA7C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007CA80: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8007CA84: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8007CA88: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8007CA8C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8007CA90: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007CA94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007CA98: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8007CA9C: swc1        $f18, -0x1D8($at)
    MEM_W(-0X1D8, ctx->r1) = ctx->f18.u32l;
    // 0x8007CAA0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007CAA4: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x8007CAA8: bne         $at, $zero, L_8007C8CC
    if (ctx->r1 != 0) {
        // 0x8007CAAC: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_8007C8CC;
    }
    // 0x8007CAAC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8007CAB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CAB4: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8007CAB8: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8007CABC: jr          $ra
    // 0x8007CAC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007CAC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void func_8007CAC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CAC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007CAC8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CACC: addiu       $t6, $t6, -0x1F0
    ctx->r14 = ADD32(ctx->r14, -0X1F0);
    // 0x8007CAD0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8007CAD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007CAD8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8007CADC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8007CAE0:
    // 0x8007CAE0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8007CAE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CAE8: lwc1        $f4, 0x14($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8007CAEC: lwc1        $f6, 0x18($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X18);
    // 0x8007CAF0: nop

    // 0x8007CAF4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007CAF8: swc1        $f8, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f8.u32l;
    // 0x8007CAFC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8007CB00: lwc1        $f18, -0x20BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X20BC);
    // 0x8007CB04: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8007CB08: lwc1        $f19, -0x20C0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X20C0);
    // 0x8007CB0C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8007CB10: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8007CB14: nop

    // 0x8007CB18: bc1f        L_8007CB38
    if (!c1cs) {
        // 0x8007CB1C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007CB38;
    }
    // 0x8007CB1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CB20: lwc1        $f5, -0x20B8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X20B8);
    // 0x8007CB24: lwc1        $f4, -0x20B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X20B4);
    // 0x8007CB28: nop

    // 0x8007CB2C: sub.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d - ctx->f4.d;
    // 0x8007CB30: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8007CB34: swc1        $f8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f8.u32l;
L_8007CB38:
    // 0x8007CB38: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8007CB3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CB40: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8007CB44: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8007CB48: nop

    // 0x8007CB4C: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007CB50: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8007CB54: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8007CB58: lwc1        $f8, -0x20AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X20AC);
    // 0x8007CB5C: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8007CB60: lwc1        $f9, -0x20B0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X20B0);
    // 0x8007CB64: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007CB68: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8007CB6C: nop

    // 0x8007CB70: bc1f        L_8007CB90
    if (!c1cs) {
        // 0x8007CB74: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007CB90;
    }
    // 0x8007CB74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CB78: lwc1        $f11, -0x20A8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X20A8);
    // 0x8007CB7C: lwc1        $f10, -0x20A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X20A4);
    // 0x8007CB80: nop

    // 0x8007CB84: sub.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d - ctx->f10.d;
    // 0x8007CB88: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8007CB8C: swc1        $f16, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f16.u32l;
L_8007CB90:
    // 0x8007CB90: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8007CB94: nop

    // 0x8007CB98: lwc1        $f12, 0x4($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8007CB9C: jal         0x800B81D0
    // 0x8007CBA0: nop

    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007CBA0: nop

    after_0:
    // 0x8007CBA4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8007CBA8: nop

    // 0x8007CBAC: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8007CBB0: nop

    // 0x8007CBB4: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007CBB8: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x8007CBBC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8007CBC0: nop

    // 0x8007CBC4: lwc1        $f12, 0x4($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8007CBC8: jal         0x800B7B40
    // 0x8007CBCC: nop

    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007CBCC: nop

    after_1:
    // 0x8007CBD0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8007CBD4: nop

    // 0x8007CBD8: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8007CBDC: nop

    // 0x8007CBE0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007CBE4: swc1        $f10, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f10.u32l;
    // 0x8007CBE8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8007CBEC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CBF0: addiu       $t9, $t8, 0x1C
    ctx->r25 = ADD32(ctx->r24, 0X1C);
    // 0x8007CBF4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007CBF8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8007CBFC: bne         $t7, $zero, L_8007CAE0
    if (ctx->r15 != 0) {
        // 0x8007CC00: sw          $t9, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r25;
            goto L_8007CAE0;
    }
    // 0x8007CC00: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8007CC04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007CC08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007CC0C: jr          $ra
    // 0x8007CC10: nop

    return;
    // 0x8007CC10: nop

;}

RECOMP_FUNC void func_8007CC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CC14: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007CC18: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CC1C: addiu       $t6, $t6, -0x2F0
    ctx->r14 = ADD32(ctx->r14, -0X2F0);
    // 0x8007CC20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007CC24: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8007CC28: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8007CC2C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8007CC30: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_8007CC34:
    // 0x8007CC34: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8007CC38: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8007CC3C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8007CC40: addiu       $t9, $t8, -0x10
    ctx->r25 = ADD32(ctx->r24, -0X10);
    // 0x8007CC44: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8007CC48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007CC4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007CC50: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8007CC54: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007CC58: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
L_8007CC5C:
    // 0x8007CC5C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8007CC60: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8007CC64: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8007CC68: addiu       $t2, $t1, -0x10
    ctx->r10 = ADD32(ctx->r9, -0X10);
    // 0x8007CC6C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8007CC70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007CC74: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007CC78: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007CC7C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007CC80: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8007CC84: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8007CC88: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8007CC8C: jal         0x800B8340
    // 0x8007CC90: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007CC90: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    after_0:
    // 0x8007CC94: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8007CC98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CC9C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007CCA0: lwc1        $f7, -0x20A0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X20A0);
    // 0x8007CCA4: lwc1        $f6, -0x209C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X209C);
    // 0x8007CCA8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8007CCAC: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8007CCB0: nop

    // 0x8007CCB4: bc1f        L_8007CD1C
    if (!c1cs) {
        // 0x8007CCB8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007CD1C;
    }
    // 0x8007CCB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CCBC: lwc1        $f11, -0x2098($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2098);
    // 0x8007CCC0: lwc1        $f10, -0x2094($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2094);
    // 0x8007CCC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CCC8: sub.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d - ctx->f10.d;
    // 0x8007CCCC: lwc1        $f7, -0x2090($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2090);
    // 0x8007CCD0: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8007CCD4: lwc1        $f6, -0x208C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X208C);
    // 0x8007CCD8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8007CCDC: mul.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8007CCE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CCE4: lwc1        $f11, -0x2088($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2088);
    // 0x8007CCE8: lwc1        $f10, -0x2084($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2084);
    // 0x8007CCEC: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8007CCF0: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x8007CCF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CCF8: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8007CCFC: lwc1        $f7, -0x2080($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2080);
    // 0x8007CD00: lwc1        $f6, -0x207C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X207C);
    // 0x8007CD04: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8007CD08: mul.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8007CD0C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8007CD10: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8007CD14: b           L_8007CD58
    // 0x8007CD18: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
        goto L_8007CD58;
    // 0x8007CD18: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
L_8007CD1C:
    // 0x8007CD1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CD20: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007CD24: lwc1        $f19, -0x2078($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2078);
    // 0x8007CD28: lwc1        $f18, -0x2074($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2074);
    // 0x8007CD2C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8007CD30: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8007CD34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CD38: lwc1        $f9, -0x2070($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2070);
    // 0x8007CD3C: lwc1        $f8, -0x206C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X206C);
    // 0x8007CD40: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8007CD44: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8007CD48: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x8007CD4C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8007CD50: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8007CD54: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
L_8007CD58:
    // 0x8007CD58: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007CD5C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8007CD60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007CD64: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8007CD68: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x8007CD6C: nop

    // 0x8007CD70: bc1f        L_8007CD84
    if (!c1cs) {
        // 0x8007CD74: nop
    
            goto L_8007CD84;
    }
    // 0x8007CD74: nop

    // 0x8007CD78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007CD7C: nop

    // 0x8007CD80: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
L_8007CD84:
    // 0x8007CD84: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007CD88: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007CD8C: addiu       $t3, $t3, -0x1F0
    ctx->r11 = ADD32(ctx->r11, -0X1F0);
    // 0x8007CD90: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8007CD94: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8007CD98: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
L_8007CD9C:
    // 0x8007CD9C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8007CDA0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007CDA4: lwc1        $f18, 0xC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8007CDA8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007CDAC: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8007CDB0: lwc1        $f8, 0x10($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8007CDB4: lwc1        $f6, 0x14($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8007CDB8: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8007CDBC: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8007CDC0: jal         0x800B7B40
    // 0x8007CDC4: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007CDC4: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_1:
    // 0x8007CDC8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8007CDCC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8007CDD0: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007CDD4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8007CDD8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8007CDDC: add.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8007CDE0: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x8007CDE4: addiu       $t8, $t7, 0x1C
    ctx->r24 = ADD32(ctx->r15, 0X1C);
    // 0x8007CDE8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8007CDEC: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8007CDF0: bne         $at, $zero, L_8007CD9C
    if (ctx->r1 != 0) {
        // 0x8007CDF4: swc1        $f8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
            goto L_8007CD9C;
    }
    // 0x8007CDF4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8007CDF8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8007CDFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007CE00: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007CE04: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8007CE08: div.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8007CE0C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007CE10: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007CE14: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007CE18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CE1C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007CE20: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8007CE24: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8007CE28: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8007CE2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007CE30: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8007CE34: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007CE38: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8007CE3C: add.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f16.d + ctx->f18.d;
    // 0x8007CE40: lwc1        $f16, -0x2064($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2064);
    // 0x8007CE44: lwc1        $f17, -0x2068($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X2068);
    // 0x8007CE48: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8007CE4C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8007CE50: mul.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8007CE54: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8007CE58: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8007CE5C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007CE60: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8007CE64: nop

    // 0x8007CE68: cvt.w.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_D(ctx->f18.d);
    // 0x8007CE6C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8007CE70: nop

    // 0x8007CE74: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x8007CE78: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8007CE7C: beq         $t0, $zero, L_8007CED0
    if (ctx->r8 == 0) {
        // 0x8007CE80: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_8007CED0;
    }
    // 0x8007CE80: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8007CE84: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007CE88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CE8C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007CE90: sub.d       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f18.d - ctx->f6.d;
    // 0x8007CE94: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8007CE98: nop

    // 0x8007CE9C: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x8007CEA0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8007CEA4: nop

    // 0x8007CEA8: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x8007CEAC: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8007CEB0: bne         $t0, $zero, L_8007CEC8
    if (ctx->r8 != 0) {
        // 0x8007CEB4: nop
    
            goto L_8007CEC8;
    }
    // 0x8007CEB4: nop

    // 0x8007CEB8: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8007CEBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007CEC0: b           L_8007CEE0
    // 0x8007CEC4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8007CEE0;
    // 0x8007CEC4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8007CEC8:
    // 0x8007CEC8: b           L_8007CEE0
    // 0x8007CECC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8007CEE0;
    // 0x8007CECC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8007CED0:
    // 0x8007CED0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8007CED4: nop

    // 0x8007CED8: bltz        $t0, L_8007CEC8
    if (SIGNED(ctx->r8) < 0) {
        // 0x8007CEDC: nop
    
            goto L_8007CEC8;
    }
    // 0x8007CEDC: nop

L_8007CEE0:
    // 0x8007CEE0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8007CEE4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007CEE8: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x8007CEEC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8007CEF0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007CEF4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007CEF8: slti        $at, $t3, 0x10
    ctx->r1 = SIGNED(ctx->r11) < 0X10 ? 1 : 0;
    // 0x8007CEFC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007CF00: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8007CF04: bne         $at, $zero, L_8007CC5C
    if (ctx->r1 != 0) {
        // 0x8007CF08: sw          $t3, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r11;
            goto L_8007CC5C;
    }
    // 0x8007CF08: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8007CF0C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8007CF10: nop

    // 0x8007CF14: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8007CF18: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x8007CF1C: bne         $at, $zero, L_8007CC34
    if (ctx->r1 != 0) {
        // 0x8007CF20: sw          $t8, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r24;
            goto L_8007CC34;
    }
    // 0x8007CF20: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8007CF24: jal         0x8007CAC4
    // 0x8007CF28: nop

    func_8007CAC4(rdram, ctx);
        goto after_2;
    // 0x8007CF28: nop

    after_2:
    // 0x8007CF2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CF30: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8007CF34: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8007CF38: jr          $ra
    // 0x8007CF3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007CF3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void func_8007CF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CF40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007CF44: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8007CF48: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x8007CF4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007CF50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007CF54: jal         0x800AC9C0
    // 0x8007CF58: sw          $t6, 0x3040($at)
    MEM_W(0X3040, ctx->r1) = ctx->r14;
    func_800AC9C0(rdram, ctx);
        goto after_0;
    // 0x8007CF58: sw          $t6, 0x3040($at)
    MEM_W(0X3040, ctx->r1) = ctx->r14;
    after_0:
    // 0x8007CF5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007CF60: sw          $v0, -0x164($at)
    MEM_W(-0X164, ctx->r1) = ctx->r2;
    // 0x8007CF64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007CF68: lw          $a0, -0x164($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X164);
    // 0x8007CF6C: jal         0x800A4364
    // 0x8007CF70: lui         $a1, 0x42DC
    ctx->r5 = S32(0X42DC << 16);
    func_800A4364(rdram, ctx);
        goto after_1;
    // 0x8007CF70: lui         $a1, 0x42DC
    ctx->r5 = S32(0X42DC << 16);
    after_1:
    // 0x8007CF74: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007CF78: lw          $a0, -0x164($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X164);
    // 0x8007CF7C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x8007CF80: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x8007CF84: jal         0x800A43B0
    // 0x8007CF88: lui         $a2, 0x4280
    ctx->r6 = S32(0X4280 << 16);
    func_800A43B0(rdram, ctx);
        goto after_2;
    // 0x8007CF88: lui         $a2, 0x4280
    ctx->r6 = S32(0X4280 << 16);
    after_2:
    // 0x8007CF8C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007CF90: addiu       $a1, $a1, 0x3044
    ctx->r5 = ADD32(ctx->r5, 0X3044);
    // 0x8007CF94: jal         0x800ACEA0
    // 0x8007CF98: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800ACEA0(rdram, ctx);
        goto after_3;
    // 0x8007CF98: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_3:
    // 0x8007CF9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007CFA0: sw          $v0, -0x158($at)
    MEM_W(-0X158, ctx->r1) = ctx->r2;
    // 0x8007CFA4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007CFA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007CFAC: lw          $t7, -0x158($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X158);
    // 0x8007CFB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007CFB4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8007CFB8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007CFBC: swc1        $f4, 0x10C($t7)
    MEM_W(0X10C, ctx->r15) = ctx->f4.u32l;
    // 0x8007CFC0: lw          $t8, -0x158($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X158);
    // 0x8007CFC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007CFC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CFCC: swc1        $f6, 0x110($t8)
    MEM_W(0X110, ctx->r24) = ctx->f6.u32l;
    // 0x8007CFD0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007CFD4: lw          $t9, -0x158($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X158);
    // 0x8007CFD8: lwc1        $f8, -0x2060($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2060);
    // 0x8007CFDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007CFE0: swc1        $f8, 0x104($t9)
    MEM_W(0X104, ctx->r25) = ctx->f8.u32l;
    // 0x8007CFE4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007CFE8: lw          $t0, -0x158($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X158);
    // 0x8007CFEC: lwc1        $f10, -0x205C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X205C);
    // 0x8007CFF0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8007CFF4: swc1        $f10, 0x108($t0)
    MEM_W(0X108, ctx->r8) = ctx->f10.u32l;
    // 0x8007CFF8: lw          $t1, -0x158($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X158);
    // 0x8007CFFC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007D000: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007D004: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007D008: swc1        $f16, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = ctx->f16.u32l;
    // 0x8007D00C: lw          $t2, -0x158($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X158);
    // 0x8007D010: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007D014: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007D018: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007D01C: swc1        $f18, 0xDC($t2)
    MEM_W(0XDC, ctx->r10) = ctx->f18.u32l;
    // 0x8007D020: lw          $t3, -0x158($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X158);
    // 0x8007D024: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007D028: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007D02C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007D030: swc1        $f4, 0xE0($t3)
    MEM_W(0XE0, ctx->r11) = ctx->f4.u32l;
    // 0x8007D034: lw          $t4, -0x158($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X158);
    // 0x8007D038: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007D03C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007D040: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8007D044: swc1        $f6, 0xE8($t4)
    MEM_W(0XE8, ctx->r12) = ctx->f6.u32l;
    // 0x8007D048: lw          $t5, -0x158($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X158);
    // 0x8007D04C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007D050: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007D054: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007D058: swc1        $f8, 0xEC($t5)
    MEM_W(0XEC, ctx->r13) = ctx->f8.u32l;
    // 0x8007D05C: lw          $t6, -0x158($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X158);
    // 0x8007D060: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007D064: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007D068: swc1        $f10, 0xF0($t6)
    MEM_W(0XF0, ctx->r14) = ctx->f10.u32l;
    // 0x8007D06C: lw          $t8, -0x158($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X158);
    // 0x8007D070: addiu       $t7, $zero, 0x15E
    ctx->r15 = ADD32(0, 0X15E);
    // 0x8007D074: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007D078: sw          $t7, 0xD4($t8)
    MEM_W(0XD4, ctx->r24) = ctx->r15;
    // 0x8007D07C: lw          $t9, -0x158($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X158);
    // 0x8007D080: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007D084: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007D088: addiu       $t1, $t1, 0x3060
    ctx->r9 = ADD32(ctx->r9, 0X3060);
    // 0x8007D08C: swc1        $f16, 0x114($t9)
    MEM_W(0X114, ctx->r25) = ctx->f16.u32l;
    // 0x8007D090: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D094: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007D098: addiu       $t0, $t0, -0x2F0
    ctx->r8 = ADD32(ctx->r8, -0X2F0);
    // 0x8007D09C: sw          $t0, 0x3058($at)
    MEM_W(0X3058, ctx->r1) = ctx->r8;
    // 0x8007D0A0: sw          $t1, 0x3054($at)
    MEM_W(0X3054, ctx->r1) = ctx->r9;
    // 0x8007D0A4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x8007D0A8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007D0AC: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x8007D0B0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8007D0B4: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8007D0B8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007D0BC: lui         $t3, 0xFD90
    ctx->r11 = S32(0XFD90 << 16);
    // 0x8007D0C0: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8007D0C4: addiu       $t4, $t4, -0x2F0
    ctx->r12 = ADD32(ctx->r12, -0X2F0);
    // 0x8007D0C8: addiu       $t5, $t5, 0x3044
    ctx->r13 = ADD32(ctx->r13, 0X3044);
    // 0x8007D0CC: lui         $at, 0xAFF
    ctx->r1 = S32(0XAFF << 16);
    // 0x8007D0D0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007D0D4: ori         $at, $at, 0xFFF8
    ctx->r1 = ctx->r1 | 0XFFF8;
    // 0x8007D0D8: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x8007D0DC: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x8007D0E0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8007D0E4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8007D0E8: lui         $t2, 0xF590
    ctx->r10 = S32(0XF590 << 16);
    // 0x8007D0EC: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8007D0F0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D0F4: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8007D0F8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8007D0FC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8007D100: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D104: lui         $t1, 0x701
    ctx->r9 = S32(0X701 << 16);
    // 0x8007D108: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x8007D10C: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x8007D110: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8007D114: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8007D118: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8007D11C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007D120: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8007D124: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8007D128: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8007D12C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007D130: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x8007D134: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8007D138: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007D13C: lui         $t4, 0x707
    ctx->r12 = S32(0X707 << 16);
    // 0x8007D140: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8007D144: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8007D148: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x8007D14C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x8007D150: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8007D154: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007D158: ori         $t4, $t4, 0xF400
    ctx->r12 = ctx->r12 | 0XF400;
    // 0x8007D15C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8007D160: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8007D164: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007D168: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8007D16C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8007D170: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007D174: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8007D178: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007D17C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8007D180: lui         $t1, 0xF588
    ctx->r9 = S32(0XF588 << 16);
    // 0x8007D184: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007D188: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8007D18C: ori         $t1, $t1, 0x400
    ctx->r9 = ctx->r9 | 0X400;
    // 0x8007D190: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8007D194: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D198: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8007D19C: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8007D1A0: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x8007D1A4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D1A8: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x8007D1AC: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x8007D1B0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8007D1B4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8007D1B8: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007D1BC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8007D1C0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8007D1C4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8007D1C8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8007D1CC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007D1D0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8007D1D4: lui         $t2, 0x3
    ctx->r10 = S32(0X3 << 16);
    // 0x8007D1D8: ori         $t2, $t2, 0xC03C
    ctx->r10 = ctx->r10 | 0XC03C;
    // 0x8007D1DC: jal         0x8007C8B0
    // 0x8007D1E0: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    func_8007C8B0(rdram, ctx);
        goto after_4;
    // 0x8007D1E0: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    after_4:
    // 0x8007D1E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007D1E8: lw          $a0, -0x158($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X158);
    // 0x8007D1EC: jal         0x8007D458
    // 0x8007D1F0: nop

    func_8007D458(rdram, ctx);
        goto after_5;
    // 0x8007D1F0: nop

    after_5:
    // 0x8007D1F4: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    // 0x8007D1F8: jal         0x800ADE5C
    // 0x8007D1FC: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    func_800ADE5C(rdram, ctx);
        goto after_6;
    // 0x8007D1FC: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_6:
    // 0x8007D200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007D208: sw          $v0, -0x154($at)
    MEM_W(-0X154, ctx->r1) = ctx->r2;
    // 0x8007D20C: jr          $ra
    // 0x8007D210: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007D210: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void func_8007D214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007D218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D21C: jal         0x8004A34C
    // 0x8007D220: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x8007D220: nop

    after_0:
    // 0x8007D224: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007D228: lw          $a0, -0x158($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X158);
    // 0x8007D22C: jal         0x800AD120
    // 0x8007D230: nop

    func_800AD120(rdram, ctx);
        goto after_1;
    // 0x8007D230: nop

    after_1:
    // 0x8007D234: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D238: sb          $zero, 0x3CF0($at)
    MEM_B(0X3CF0, ctx->r1) = 0;
    // 0x8007D23C: jal         0x800905E8
    // 0x8007D240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800905E8(rdram, ctx);
        goto after_2;
    // 0x8007D240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8007D244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D248: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8007D24C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D250: sb          $t6, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r14;
    // 0x8007D254: jr          $ra
    // 0x8007D258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007D258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void func_8007D25C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D25C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007D260: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D264: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007D268: lwc1        $f9, -0x2058($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2058);
    // 0x8007D26C: lwc1        $f8, -0x2054($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2054);
    // 0x8007D270: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007D274: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8007D278: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8007D27C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8007D280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D284: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8007D288: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8007D28C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8007D290: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8007D294: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x8007D298: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x8007D29C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D2A0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8007D2A4: lwc1        $f19, -0x2050($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2050);
    // 0x8007D2A8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8007D2AC: lwc1        $f18, -0x204C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X204C);
    // 0x8007D2B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007D2B4: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
    // 0x8007D2B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D2BC: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8007D2C0: nop

    // 0x8007D2C4: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8007D2C8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007D2CC: lwc1        $f8, -0x2044($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2044);
    // 0x8007D2D0: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8007D2D4: lw          $t8, 0xC4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC4);
    // 0x8007D2D8: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x8007D2DC: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8007D2E0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x8007D2E4: lwc1        $f9, -0x2048($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2048);
    // 0x8007D2E8: lw          $t9, 0xC0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC0);
    // 0x8007D2EC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8007D2F0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8007D2F4: nop

    // 0x8007D2F8: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x8007D2FC: nop

    // 0x8007D300: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8007D304: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8007D308: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8007D30C: lw          $t0, 0xC0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0XC0);
    // 0x8007D310: nop

    // 0x8007D314: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x8007D318: beq         $t1, $zero, L_8007D448
    if (ctx->r9 == 0) {
        // 0x8007D31C: sh          $t0, 0x4A($sp)
        MEM_H(0X4A, ctx->r29) = ctx->r8;
            goto L_8007D448;
    }
    // 0x8007D31C: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
L_8007D320:
    // 0x8007D320: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007D324: jal         0x800B81D0
    // 0x8007D328: nop

    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007D328: nop

    after_0:
    // 0x8007D32C: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007D330: jal         0x800B7B40
    // 0x8007D334: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007D334: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8007D338: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007D33C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007D340: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8007D344: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8007D348: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007D34C: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007D350: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8007D354: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8007D358: jal         0x800B7B40
    // 0x8007D35C: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007D35C: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8007D360: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8007D364: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D368: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007D36C: lwc1        $f17, -0x2040($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X2040);
    // 0x8007D370: lwc1        $f16, -0x203C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X203C);
    // 0x8007D374: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007D378: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007D37C: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8007D380: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8007D384: jal         0x800B81D0
    // 0x8007D388: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8007D388: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8007D38C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8007D390: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007D394: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007D398: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007D39C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D3A0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8007D3A4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007D3A8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007D3AC: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007D3B0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8007D3B4: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8007D3B8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8007D3BC: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007D3C0: nop

    // 0x8007D3C4: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007D3C8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8007D3CC: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
    // 0x8007D3D0: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007D3D4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007D3D8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D3DC: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007D3E0: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x8007D3E4: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007D3E8: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007D3EC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D3F0: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007D3F4: swc1        $f4, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f4.u32l;
    // 0x8007D3F8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D3FC: lhu         $t5, 0x4A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X4A);
    // 0x8007D400: nop

    // 0x8007D404: sw          $t5, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r13;
    // 0x8007D408: lhu         $t8, 0x4A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X4A);
    // 0x8007D40C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007D410: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007D414: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007D418: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007D41C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D420: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007D424: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007D428: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x8007D42C: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007D430: addiu       $t0, $t6, 0x28
    ctx->r8 = ADD32(ctx->r14, 0X28);
    // 0x8007D434: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8007D438: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8007D43C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8007D440: bne         $t1, $zero, L_8007D320
    if (ctx->r9 != 0) {
        // 0x8007D444: sh          $t9, 0x4A($sp)
        MEM_H(0X4A, ctx->r29) = ctx->r25;
            goto L_8007D320;
    }
    // 0x8007D444: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
L_8007D448:
    // 0x8007D448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D44C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8007D450: jr          $ra
    // 0x8007D454: nop

    return;
    // 0x8007D454: nop

;}

RECOMP_FUNC void func_8007D458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D458: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007D45C: sw          $t6, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->r14;
    // 0x8007D460: lw          $t7, 0xC4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC4);
    // 0x8007D464: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8007D468: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D46C: lwc1        $f4, -0x2038($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2038);
    // 0x8007D470: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8007D474: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8007D478: swc1        $f4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f4.u32l;
    // 0x8007D47C: lw          $t8, 0xC0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC0);
    // 0x8007D480: nop

    // 0x8007D484: blez        $t8, L_8007D508
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8007D488: nop
    
            goto L_8007D508;
    }
    // 0x8007D488: nop

L_8007D48C:
    // 0x8007D48C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8007D490: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8007D494: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D498: sw          $t9, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r25;
    // 0x8007D49C: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8007D4A0: lwc1        $f10, -0x202C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X202C);
    // 0x8007D4A4: lwc1        $f11, -0x2030($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2030);
    // 0x8007D4A8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8007D4AC: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8007D4B0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8007D4B4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8007D4B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D4BC: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x8007D4C0: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8007D4C4: lwc1        $f8, -0x2024($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2024);
    // 0x8007D4C8: lwc1        $f9, -0x2028($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2028);
    // 0x8007D4CC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007D4D0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8007D4D4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8007D4D8: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8007D4DC: addiu       $t5, $t4, 0x28
    ctx->r13 = ADD32(ctx->r12, 0X28);
    // 0x8007D4E0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007D4E4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8007D4E8: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x8007D4EC: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8007D4F0: swc1        $f16, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f16.u32l;
    // 0x8007D4F4: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x8007D4F8: nop

    // 0x8007D4FC: slt         $at, $t3, $t6
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007D500: bne         $at, $zero, L_8007D48C
    if (ctx->r1 != 0) {
        // 0x8007D504: nop
    
            goto L_8007D48C;
    }
    // 0x8007D504: nop

L_8007D508:
    // 0x8007D508: jr          $ra
    // 0x8007D50C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007D50C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void func_8007D510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D510: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007D514: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8007D518: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007D51C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D520: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8007D524: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8007D528: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8007D52C: lw          $t7, 0xC4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC4);
    // 0x8007D530: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007D534: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007D538: lw          $t8, 0xC0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC0);
    // 0x8007D53C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8007D540: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8007D544: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007D548: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8007D54C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D550: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007D554: div.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x8007D558: lwc1        $f8, -0x201C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X201C);
    // 0x8007D55C: lwc1        $f9, -0x2020($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2020);
    // 0x8007D560: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8007D564: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007D568: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007D56C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8007D570: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8007D574: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8007D578: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8007D57C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8007D580: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007D584: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8007D588: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8007D58C: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8007D590: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8007D594: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8007D598: lw          $t9, 0xC0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC0);
    // 0x8007D59C: nop

    // 0x8007D5A0: blez        $t9, L_8007D698
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8007D5A4: nop
    
            goto L_8007D698;
    }
    // 0x8007D5A4: nop

L_8007D5A8:
    // 0x8007D5A8: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007D5AC: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007D5B0: nop

    // 0x8007D5B4: mul.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8007D5B8: jal         0x800B7B40
    // 0x8007D5BC: nop

    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007D5BC: nop

    after_0:
    // 0x8007D5C0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007D5C4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007D5C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007D5CC: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8007D5D0: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8007D5D4: add.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f18.d + ctx->f6.d;
    // 0x8007D5D8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007D5DC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8007D5E0: mul.d       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8007D5E4: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007D5E8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8007D5EC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8007D5F0: jal         0x800B81D0
    // 0x8007D5F4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007D5F4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x8007D5F8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007D5FC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007D600: mul.s       $f16, $f0, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007D604: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8007D608: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007D60C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007D610: nop

    // 0x8007D614: swc1        $f10, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f10.u32l;
    // 0x8007D618: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007D61C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007D620: jal         0x800B7B40
    // 0x8007D624: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007D624: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_2:
    // 0x8007D628: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007D62C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007D630: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8007D634: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007D638: swc1        $f4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
    // 0x8007D63C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007D640: lwc1        $f18, -0x2014($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2014);
    // 0x8007D644: lwc1        $f19, -0x2018($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2018);
    // 0x8007D648: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8007D64C: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8007D650: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007D654: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007D658: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007D65C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8007D660: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8007D664: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8007D668: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8007D66C: addiu       $t7, $t5, 0x28
    ctx->r15 = ADD32(ctx->r13, 0X28);
    // 0x8007D670: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007D674: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8007D678: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007D67C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8007D680: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x8007D684: lw          $t6, 0xC0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC0);
    // 0x8007D688: nop

    // 0x8007D68C: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007D690: bne         $at, $zero, L_8007D5A8
    if (ctx->r1 != 0) {
        // 0x8007D694: nop
    
            goto L_8007D5A8;
    }
    // 0x8007D694: nop

L_8007D698:
    // 0x8007D698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D69C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007D6A0: jr          $ra
    // 0x8007D6A4: nop

    return;
    // 0x8007D6A4: nop

;}

RECOMP_FUNC void func_8007D6A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D6A8: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8007D6AC: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x8007D6B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D6B4: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D6B8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007D6BC: jal         0x800A4B98
    // 0x8007D6C0: addiu       $a1, $a1, 0x3044
    ctx->r5 = ADD32(ctx->r5, 0X3044);
    func_800A4B98(rdram, ctx);
        goto after_0;
    // 0x8007D6C0: addiu       $a1, $a1, 0x3044
    ctx->r5 = ADD32(ctx->r5, 0X3044);
    after_0:
    // 0x8007D6C4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007D6C8: lw          $t6, 0x3128($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3128);
    // 0x8007D6CC: sw          $v0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r2;
    // 0x8007D6D0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007D6D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D6D8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007D6DC: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D6E0: sw          $t7, 0x3128($at)
    MEM_W(0X3128, ctx->r1) = ctx->r15;
    // 0x8007D6E4: sw          $t8, 0x3128($at)
    MEM_W(0X3128, ctx->r1) = ctx->r24;
    // 0x8007D6E8: andi        $t1, $t8, 0xFFF
    ctx->r9 = ctx->r24 & 0XFFF;
    // 0x8007D6EC: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x8007D6F0: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8007D6F4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8007D6F8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8007D6FC: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8007D700: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8007D704: sw          $t0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r8;
    // 0x8007D708: or          $t4, $t3, $t1
    ctx->r12 = ctx->r11 | ctx->r9;
    // 0x8007D70C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8007D710: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8007D714: lui         $t0, 0xE300
    ctx->r8 = S32(0XE300 << 16);
    // 0x8007D718: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8007D71C: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D720: ori         $t0, $t0, 0xC00
    ctx->r8 = ctx->r8 | 0XC00;
    // 0x8007D724: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8007D728: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8007D72C: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8007D730: sw          $t9, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r25;
    // 0x8007D734: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8007D738: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8007D73C: lui         $t2, 0x8
    ctx->r10 = S32(0X8 << 16);
    // 0x8007D740: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8007D744: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D748: lui         $t5, 0xD9D8
    ctx->r13 = S32(0XD9D8 << 16);
    // 0x8007D74C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8007D750: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007D754: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x8007D758: sw          $t4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r12;
    // 0x8007D75C: ori         $t5, $t5, 0xF9FA
    ctx->r13 = ctx->r13 | 0XF9FA;
    // 0x8007D760: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8007D764: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8007D768: lui         $t8, 0xD9FF
    ctx->r24 = S32(0XD9FF << 16);
    // 0x8007D76C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8007D770: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D774: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x8007D778: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8007D77C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8007D780: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8007D784: sw          $t0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r8;
    // 0x8007D788: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8007D78C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8007D790: lui         $t3, 0x20
    ctx->r11 = S32(0X20 << 16);
    // 0x8007D794: ori         $t3, $t3, 0x4
    ctx->r11 = ctx->r11 | 0X4;
    // 0x8007D798: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8007D79C: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D7A0: lui         $t6, 0xFC11
    ctx->r14 = S32(0XFC11 << 16);
    // 0x8007D7A4: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8007D7A8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007D7AC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8007D7B0: sw          $t5, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r13;
    // 0x8007D7B4: ori         $t6, $t6, 0x9623
    ctx->r14 = ctx->r14 | 0X9623;
    // 0x8007D7B8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8007D7BC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007D7C0: lui         $t9, 0xFF2F
    ctx->r25 = S32(0XFF2F << 16);
    // 0x8007D7C4: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8007D7C8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8007D7CC: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D7D0: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x8007D7D4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007D7D8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D7DC: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x8007D7E0: sw          $t2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r10;
    // 0x8007D7E4: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x8007D7E8: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8007D7EC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D7F0: lui         $t4, 0x50
    ctx->r12 = S32(0X50 << 16);
    // 0x8007D7F4: ori         $t4, $t4, 0x4240
    ctx->r12 = ctx->r12 | 0X4240;
    // 0x8007D7F8: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8007D7FC: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D800: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x8007D804: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8007D808: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007D80C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007D810: sw          $t7, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r15;
    // 0x8007D814: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x8007D818: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007D81C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007D820: lui         $t8, 0x10
    ctx->r24 = S32(0X10 << 16);
    // 0x8007D824: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8007D828: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D82C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8007D830: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8007D834: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007D838: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x8007D83C: sw          $t1, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r9;
    // 0x8007D840: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8007D844: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8007D848: addiu       $t6, $zero, -0x80
    ctx->r14 = ADD32(0, -0X80);
    // 0x8007D84C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8007D850: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8007D854: lw          $t9, 0x312C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X312C);
    // 0x8007D858: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x8007D85C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8007D860: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007D864: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007D868: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007D86C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8007D870: jal         0x800B04BC
    // 0x8007D874: nop

    mtx4_from_euler(rdram, ctx);
        goto after_1;
    // 0x8007D874: nop

    after_1:
    // 0x8007D878: addiu       $t8, $sp, 0xA0
    ctx->r24 = ADD32(ctx->r29, 0XA0);
    // 0x8007D87C: addiu       $t3, $t8, 0x3C
    ctx->r11 = ADD32(ctx->r24, 0X3C);
    // 0x8007D880: addiu       $t0, $sp, 0x60
    ctx->r8 = ADD32(ctx->r29, 0X60);
L_8007D884:
    // 0x8007D884: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8007D888: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8007D88C: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8007D890: lw          $at, -0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X8);
    // 0x8007D894: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8007D898: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x8007D89C: lw          $at, -0x4($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X4);
    // 0x8007D8A0: bne         $t8, $t3, L_8007D884
    if (ctx->r24 != ctx->r11) {
        // 0x8007D8A4: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_8007D884;
    }
    // 0x8007D8A4: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x8007D8A8: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8007D8AC: nop

    // 0x8007D8B0: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8007D8B4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8007D8B8:
    // 0x8007D8B8: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8007D8BC: lui         $at, 0x4030
    ctx->r1 = S32(0X4030 << 16);
    // 0x8007D8C0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8007D8C4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007D8C8: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8007D8CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007D8D0: lui         $at, 0xC050
    ctx->r1 = S32(0XC050 << 16);
    // 0x8007D8D4: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8007D8D8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007D8DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007D8E0: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
    // 0x8007D8E4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007D8E8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8007D8EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007D8F0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007D8F4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8007D8F8: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8007D8FC: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x8007D900: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8007D904: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    // 0x8007D908: jal         0x800AFBBC
    // 0x8007D90C: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    func_800AFBBC(rdram, ctx);
        goto after_2;
    // 0x8007D90C: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8007D910: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8007D914: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007D918: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8007D91C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007D920: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007D924: addiu       $t6, $t6, -0x150
    ctx->r14 = ADD32(ctx->r14, -0X150);
    // 0x8007D928: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x8007D92C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8007D930: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8007D934: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x8007D938: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x8007D93C: jal         0x800B78D0
    // 0x8007D940: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    guMtxF2L(rdram, ctx);
        goto after_3;
    // 0x8007D940: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8007D944: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D948: lui         $t2, 0xDA38
    ctx->r10 = S32(0XDA38 << 16);
    // 0x8007D94C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8007D950: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8007D954: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8007D958: sw          $t9, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r25;
    // 0x8007D95C: ori         $t2, $t2, 0x3
    ctx->r10 = ctx->r10 | 0X3;
    // 0x8007D960: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8007D964: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8007D968: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8007D96C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007D970: addiu       $t1, $t1, -0x150
    ctx->r9 = ADD32(ctx->r9, -0X150);
    // 0x8007D974: sll         $t0, $t8, 6
    ctx->r8 = S32(ctx->r24 << 6);
    // 0x8007D978: addu        $t4, $t0, $t1
    ctx->r12 = ADD32(ctx->r8, ctx->r9);
    // 0x8007D97C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8007D980: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D984: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x8007D988: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8007D98C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D990: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007D994: sw          $t7, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r15;
    // 0x8007D998: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007D99C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D9A0: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8007D9A4: addiu       $t3, $t3, 0x3108
    ctx->r11 = ADD32(ctx->r11, 0X3108);
    // 0x8007D9A8: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8007D9AC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8007D9B0: nop

    // 0x8007D9B4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007D9B8: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x8007D9BC: bne         $at, $zero, L_8007D8B8
    if (ctx->r1 != 0) {
        // 0x8007D9C0: sw          $t1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r9;
            goto L_8007D8B8;
    }
    // 0x8007D9C0: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8007D9C4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8007D9C8: lw          $t4, 0x312C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X312C);
    // 0x8007D9CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D9D0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007D9D4: sw          $t5, 0x312C($at)
    MEM_W(0X312C, ctx->r1) = ctx->r13;
    // 0x8007D9D8: slti        $at, $t5, 0x169
    ctx->r1 = SIGNED(ctx->r13) < 0X169 ? 1 : 0;
    // 0x8007D9DC: bne         $at, $zero, L_8007D9F0
    if (ctx->r1 != 0) {
        // 0x8007D9E0: nop
    
            goto L_8007D9F0;
    }
    // 0x8007D9E0: nop

    // 0x8007D9E4: addiu       $t6, $t5, -0x168
    ctx->r14 = ADD32(ctx->r13, -0X168);
    // 0x8007D9E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D9EC: sw          $t6, 0x312C($at)
    MEM_W(0X312C, ctx->r1) = ctx->r14;
L_8007D9F0:
    // 0x8007D9F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D9F4: lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D9F8: jr          $ra
    // 0x8007D9FC: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8007D9FC: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}

RECOMP_FUNC void func_8007DA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DA00: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007DA04: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007DA08: lw          $t6, 0x3040($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3040);
    // 0x8007DA0C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007DA10: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8007DA14: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8007DA18: beq         $t6, $zero, L_8007DAE0
    if (ctx->r14 == 0) {
        // 0x8007DA1C: swc1        $f20, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
            goto L_8007DAE0;
    }
    // 0x8007DA1C: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8007DA20: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8007DA24: addiu       $t8, $t8, 0x3150
    ctx->r24 = ADD32(ctx->r24, 0X3150);
    // 0x8007DA28: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8007DA2C: addiu       $t7, $sp, 0x38
    ctx->r15 = ADD32(ctx->r29, 0X38);
    // 0x8007DA30: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x8007DA34: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x8007DA38: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x8007DA3C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007DA40: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x8007DA44: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x8007DA48: lw          $a0, -0x154($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X154);
    // 0x8007DA4C: jal         0x800AE6E4
    // 0x8007DA50: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800AE6E4(rdram, ctx);
        goto after_0;
    // 0x8007DA50: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x8007DA54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007DA58: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007DA5C: lw          $a1, 0x3180($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3180);
    // 0x8007DA60: lw          $a0, -0x154($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X154);
    // 0x8007DA64: jal         0x800AE700
    // 0x8007DA68: nop

    func_800AE700(rdram, ctx);
        goto after_1;
    // 0x8007DA68: nop

    after_1:
    // 0x8007DA6C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007DA70: lhu         $t1, 0x20B0($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X20B0);
    // 0x8007DA74: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007DA78: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x8007DA7C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8007DA80: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8007DA84: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007DA88: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007DA8C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007DA90: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007DA94: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007DA98: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007DA9C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007DAA0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8007DAA4: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8007DAA8: addiu       $t4, $t4, -0x5300
    ctx->r12 = ADD32(ctx->r12, -0X5300);
    // 0x8007DAAC: sll         $t3, $t3, 7
    ctx->r11 = S32(ctx->r11 << 7);
    // 0x8007DAB0: lw          $a0, -0x154($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X154);
    // 0x8007DAB4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8007DAB8: addiu       $t5, $zero, 0xFA
    ctx->r13 = ADD32(0, 0XFA);
    // 0x8007DABC: addiu       $t6, $zero, 0xFA
    ctx->r14 = ADD32(0, 0XFA);
    // 0x8007DAC0: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x8007DAC4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8007DAC8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8007DACC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8007DAD0: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x8007DAD4: jal         0x800AE220
    // 0x8007DAD8: addiu       $a3, $zero, 0xFA
    ctx->r7 = ADD32(0, 0XFA);
    func_800AE220(rdram, ctx);
        goto after_2;
    // 0x8007DAD8: addiu       $a3, $zero, 0xFA
    ctx->r7 = ADD32(0, 0XFA);
    after_2:
    // 0x8007DADC: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
L_8007DAE0:
    // 0x8007DAE0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8007DAE4: lbu         $t7, -0x118($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X118);
    // 0x8007DAE8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8007DAEC: bne         $t7, $at, L_8007DB40
    if (ctx->r15 != ctx->r1) {
        // 0x8007DAF0: nop
    
            goto L_8007DB40;
    }
    // 0x8007DAF0: nop

    // 0x8007DAF4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007DAF8: addiu       $t8, $t8, -0x10D0
    ctx->r24 = ADD32(ctx->r24, -0X10D0);
    // 0x8007DAFC: lw          $t0, 0x1C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X1C);
    // 0x8007DB00: nop

    // 0x8007DB04: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8007DB08: nop

    // 0x8007DB0C: andi        $t2, $t1, 0x1000
    ctx->r10 = ctx->r9 & 0X1000;
    // 0x8007DB10: beq         $t2, $zero, L_8007DB40
    if (ctx->r10 == 0) {
        // 0x8007DB14: nop
    
            goto L_8007DB40;
    }
    // 0x8007DB14: nop

    // 0x8007DB18: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8007DB1C: nop

    // 0x8007DB20: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x8007DB24: bne         $t4, $zero, L_8007DB40
    if (ctx->r12 != 0) {
        // 0x8007DB28: nop
    
            goto L_8007DB40;
    }
    // 0x8007DB28: nop

    // 0x8007DB2C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8007DB30: lw          $t5, 0x3040($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3040);
    // 0x8007DB34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DB38: xori        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 ^ 0X1;
    // 0x8007DB3C: sw          $t6, 0x3040($at)
    MEM_W(0X3040, ctx->r1) = ctx->r14;
L_8007DB40:
    // 0x8007DB40: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007DB44: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007DB48: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007DB4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007DB50: lw          $a0, -0x164($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X164);
    // 0x8007DB54: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007DB58: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007DB5C: lui         $a3, 0xC0A0
    ctx->r7 = S32(0XC0A0 << 16);
    // 0x8007DB60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007DB64: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8007DB68: jal         0x800A4304
    // 0x8007DB6C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_800A4304(rdram, ctx);
        goto after_3;
    // 0x8007DB6C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8007DB70: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007DB74: lw          $a1, -0x164($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X164);
    // 0x8007DB78: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007DB7C: jal         0x800A724C
    // 0x8007DB80: nop

    func_800A724C(rdram, ctx);
        goto after_4;
    // 0x8007DB80: nop

    after_4:
    // 0x8007DB84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DB88: lwc1        $f12, 0x316C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X316C);
    // 0x8007DB8C: jal         0x800B7B40
    // 0x8007DB90: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x8007DB90: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_5:
    // 0x8007DB94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DB98: lwc1        $f10, 0x315C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X315C);
    // 0x8007DB9C: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8007DBA0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007DBA4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007DBA8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8007DBAC: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8007DBB0: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8007DBB4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007DBB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007DBBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DBC0: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8007DBC4: lwc1        $f4, -0x200C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X200C);
    // 0x8007DBC8: lwc1        $f5, -0x2010($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2010);
    // 0x8007DBCC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8007DBD0: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8007DBD4: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8007DBD8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007DBDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DBE0: lwc1        $f9, -0x2008($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2008);
    // 0x8007DBE4: lwc1        $f8, -0x2004($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2004);
    // 0x8007DBE8: lui         $at, 0x405E
    ctx->r1 = S32(0X405E << 16);
    // 0x8007DBEC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8007DBF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007DBF4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8007DBF8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8007DBFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007DC00: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x8007DC04: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8007DC08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007DC0C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007DC10: lw          $a0, -0x158($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X158);
    // 0x8007DC14: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8007DC18: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8007DC1C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8007DC20: lui         $a2, 0x40E0
    ctx->r6 = S32(0X40E0 << 16);
    // 0x8007DC24: jal         0x8007D510
    // 0x8007DC28: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_8007D510(rdram, ctx);
        goto after_6;
    // 0x8007DC28: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8007DC2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DC30: lwc1        $f12, 0x316C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X316C);
    // 0x8007DC34: jal         0x800B81D0
    // 0x8007DC38: nop

    cosf_recomp(rdram, ctx);
        goto after_7;
    // 0x8007DC38: nop

    after_7:
    // 0x8007DC3C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8007DC40: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007DC44: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007DC48: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8007DC4C: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x8007DC50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DC54: lwc1        $f12, 0x3174($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X3174);
    // 0x8007DC58: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007DC5C: jal         0x800B81D0
    // 0x8007DC60: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    cosf_recomp(rdram, ctx);
        goto after_8;
    // 0x8007DC60: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x8007DC64: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8007DC68: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007DC6C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007DC70: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8007DC74: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8007DC78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DC7C: lwc1        $f12, 0x316C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X316C);
    // 0x8007DC80: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8007DC84: jal         0x800B7B40
    // 0x8007DC88: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    sinf_recomp(rdram, ctx);
        goto after_9;
    // 0x8007DC88: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x8007DC8C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8007DC90: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007DC94: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007DC98: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8007DC9C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8007DCA0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8007DCA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007DCA8: addiu       $a1, $a1, 0xB0
    ctx->r5 = ADD32(ctx->r5, 0XB0);
    // 0x8007DCAC: addiu       $a0, $a0, 0x3130
    ctx->r4 = ADD32(ctx->r4, 0X3130);
    // 0x8007DCB0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007DCB4: jal         0x800B11C4
    // 0x8007DCB8: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    func_800B11C4(rdram, ctx);
        goto after_10;
    // 0x8007DCB8: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x8007DCBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DCC0: lwc1        $f18, 0x3130($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3130);
    // 0x8007DCC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DCC8: lwc1        $f5, -0x2000($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2000);
    // 0x8007DCCC: lwc1        $f4, -0x1FFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1FFC);
    // 0x8007DCD0: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8007DCD4: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x8007DCD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DCDC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8007DCE0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007DCE4: swc1        $f8, 0x3130($at)
    MEM_W(0X3130, ctx->r1) = ctx->f8.u32l;
    // 0x8007DCE8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007DCEC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007DCF0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007DCF4: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8007DCF8: nop

    // 0x8007DCFC: bc1f        L_8007DD1C
    if (!c1cs) {
        // 0x8007DD00: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_8007DD1C;
    }
    // 0x8007DD00: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007DD04: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007DD08: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007DD0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DD10: sub.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f10.d - ctx->f16.d;
    // 0x8007DD14: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007DD18: swc1        $f6, 0x3130($at)
    MEM_W(0X3130, ctx->r1) = ctx->f6.u32l;
L_8007DD1C:
    // 0x8007DD1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DD20: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007DD24: lw          $t9, -0x158($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X158);
    // 0x8007DD28: lwc1        $f8, 0x3178($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3178);
    // 0x8007DD2C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007DD30: swc1        $f8, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->f8.u32l;
    // 0x8007DD34: lwc1        $f18, 0x3178($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3178);
    // 0x8007DD38: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8007DD3C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007DD40: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8007DD44: add.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f10.d + ctx->f16.d;
    // 0x8007DD48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007DD4C: lw          $t7, -0x158($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X158);
    // 0x8007DD50: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007DD54: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007DD58: swc1        $f6, 0xE8($t7)
    MEM_W(0XE8, ctx->r15) = ctx->f6.u32l;
    // 0x8007DD5C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007DD60: lw          $a2, -0x164($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X164);
    // 0x8007DD64: lw          $a1, -0x158($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X158);
    // 0x8007DD68: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007DD6C: jal         0x800AD970
    // 0x8007DD70: nop

    func_800AD970(rdram, ctx);
        goto after_11;
    // 0x8007DD70: nop

    after_11:
    // 0x8007DD74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DD78: lwc1        $f8, 0x315C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X315C);
    // 0x8007DD7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DD80: lwc1        $f18, 0x3160($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3160);
    // 0x8007DD84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DD88: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8007DD8C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8007DD90: swc1        $f10, 0x315C($at)
    MEM_W(0X315C, ctx->r1) = ctx->f10.u32l;
    // 0x8007DD94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007DD98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007DD9C: nop

    // 0x8007DDA0: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8007DDA4: nop

    // 0x8007DDA8: bc1t        L_8007DDC4
    if (c1cs) {
        // 0x8007DDAC: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8007DDC4;
    }
    // 0x8007DDAC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8007DDB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007DDB4: nop

    // 0x8007DDB8: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8007DDBC: nop

    // 0x8007DDC0: bc1f        L_8007DE00
    if (!c1cs) {
        // 0x8007DDC4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8007DE00;
    }
L_8007DDC4:
    // 0x8007DDC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DDC8: lwc1        $f6, 0x315C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X315C);
    // 0x8007DDCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DDD0: lwc1        $f8, 0x3160($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3160);
    // 0x8007DDD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DDD8: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8007DDDC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007DDE0: swc1        $f18, 0x315C($at)
    MEM_W(0X315C, ctx->r1) = ctx->f18.u32l;
    // 0x8007DDE4: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8007DDE8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007DDEC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8007DDF0: mul.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x8007DDF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DDF8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007DDFC: swc1        $f6, 0x3160($at)
    MEM_W(0X3160, ctx->r1) = ctx->f6.u32l;
L_8007DE00:
    // 0x8007DE00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE04: lwc1        $f18, 0x3164($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3164);
    // 0x8007DE08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE0C: lwc1        $f8, 0x3168($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3168);
    // 0x8007DE10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE14: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8007DE18: swc1        $f16, 0x3164($at)
    MEM_W(0X3164, ctx->r1) = ctx->f16.u32l;
    // 0x8007DE1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DE20: lwc1        $f5, -0x1FF8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1FF8);
    // 0x8007DE24: lwc1        $f4, -0x1FF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1FF4);
    // 0x8007DE28: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8007DE2C: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x8007DE30: nop

    // 0x8007DE34: bc1t        L_8007DE54
    if (c1cs) {
        // 0x8007DE38: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007DE54;
    }
    // 0x8007DE38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DE3C: lwc1        $f7, -0x1FF0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1FF0);
    // 0x8007DE40: lwc1        $f6, -0x1FEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1FEC);
    // 0x8007DE44: nop

    // 0x8007DE48: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x8007DE4C: nop

    // 0x8007DE50: bc1f        L_8007DE90
    if (!c1cs) {
        // 0x8007DE54: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8007DE90;
    }
L_8007DE54:
    // 0x8007DE54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE58: lwc1        $f18, 0x3164($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3164);
    // 0x8007DE5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE60: lwc1        $f8, 0x3168($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3168);
    // 0x8007DE64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE68: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8007DE6C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007DE70: swc1        $f16, 0x3164($at)
    MEM_W(0X3164, ctx->r1) = ctx->f16.u32l;
    // 0x8007DE74: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8007DE78: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007DE7C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8007DE80: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x8007DE84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE88: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8007DE8C: swc1        $f18, 0x3168($at)
    MEM_W(0X3168, ctx->r1) = ctx->f18.u32l;
L_8007DE90:
    // 0x8007DE90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE94: lwc1        $f16, 0x316C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X316C);
    // 0x8007DE98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DE9C: lwc1        $f8, 0x3170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3170);
    // 0x8007DEA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DEA4: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8007DEA8: swc1        $f4, 0x316C($at)
    MEM_W(0X316C, ctx->r1) = ctx->f4.u32l;
    // 0x8007DEAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DEB0: lwc1        $f7, -0x1FE8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1FE8);
    // 0x8007DEB4: lwc1        $f6, -0x1FE4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1FE4);
    // 0x8007DEB8: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8007DEBC: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8007DEC0: nop

    // 0x8007DEC4: bc1f        L_8007DEE4
    if (!c1cs) {
        // 0x8007DEC8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007DEE4;
    }
    // 0x8007DEC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DECC: lwc1        $f19, -0x1FE0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1FE0);
    // 0x8007DED0: lwc1        $f18, -0x1FDC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1FDC);
    // 0x8007DED4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DED8: sub.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f10.d - ctx->f18.d;
    // 0x8007DEDC: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8007DEE0: swc1        $f8, 0x316C($at)
    MEM_W(0X316C, ctx->r1) = ctx->f8.u32l;
L_8007DEE4:
    // 0x8007DEE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DEE8: lwc1        $f4, 0x3174($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3174);
    // 0x8007DEEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DEF0: lwc1        $f11, -0x1FD8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1FD8);
    // 0x8007DEF4: lwc1        $f10, -0x1FD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1FD4);
    // 0x8007DEF8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007DEFC: add.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d + ctx->f10.d;
    // 0x8007DF00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DF04: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8007DF08: swc1        $f16, 0x3174($at)
    MEM_W(0X3174, ctx->r1) = ctx->f16.u32l;
    // 0x8007DF0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DF10: lwc1        $f5, -0x1FD0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1FD0);
    // 0x8007DF14: lwc1        $f4, -0x1FCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1FCC);
    // 0x8007DF18: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8007DF1C: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8007DF20: nop

    // 0x8007DF24: bc1f        L_8007DF44
    if (!c1cs) {
        // 0x8007DF28: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8007DF44;
    }
    // 0x8007DF28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007DF2C: lwc1        $f7, -0x1FC8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1FC8);
    // 0x8007DF30: lwc1        $f6, -0x1FC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1FC4);
    // 0x8007DF34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DF38: sub.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d - ctx->f6.d;
    // 0x8007DF3C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8007DF40: swc1        $f18, 0x3174($at)
    MEM_W(0X3174, ctx->r1) = ctx->f18.u32l;
L_8007DF44:
    // 0x8007DF44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DF48: lwc1        $f16, 0x3178($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3178);
    // 0x8007DF4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DF50: lwc1        $f4, 0x317C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X317C);
    // 0x8007DF54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DF58: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8007DF5C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007DF60: swc1        $f8, 0x3178($at)
    MEM_W(0X3178, ctx->r1) = ctx->f8.u32l;
    // 0x8007DF64: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007DF68: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007DF6C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8007DF70: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x8007DF74: nop

    // 0x8007DF78: bc1f        L_8007DF98
    if (!c1cs) {
        // 0x8007DF7C: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_8007DF98;
    }
    // 0x8007DF7C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8007DF80: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007DF84: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007DF88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DF8C: sub.d       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f6.d - ctx->f18.d;
    // 0x8007DF90: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8007DF94: swc1        $f4, 0x3178($at)
    MEM_W(0X3178, ctx->r1) = ctx->f4.u32l;
L_8007DF98:
    // 0x8007DF98: jal         0x8007CC14
    // 0x8007DF9C: nop

    func_8007CC14(rdram, ctx);
        goto after_12;
    // 0x8007DF9C: nop

    after_12:
    // 0x8007DFA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DFA4: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8007DFA8: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8007DFAC: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007DFB0: jr          $ra
    // 0x8007DFB4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007DFB4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8007DFB8: nop

    // 0x8007DFBC: nop

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

RECOMP_FUNC void func_800AC9C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC9C0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800AC9C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AC9C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AC9CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AC9D0: jal         0x8007E03C
    // 0x800AC9D4: addiu       $a0, $a0, 0x150C
    ctx->r4 = ADD32(ctx->r4, 0X150C);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800AC9D4: addiu       $a0, $a0, 0x150C
    ctx->r4 = ADD32(ctx->r4, 0X150C);
    after_0:
    // 0x800AC9D8: bne         $v0, $zero, L_800AC9E8
    if (ctx->r2 != 0) {
        // 0x800AC9DC: addiu       $t3, $v0, 0x80
        ctx->r11 = ADD32(ctx->r2, 0X80);
            goto L_800AC9E8;
    }
    // 0x800AC9DC: addiu       $t3, $v0, 0x80
    ctx->r11 = ADD32(ctx->r2, 0X80);
    // 0x800AC9E0: b           L_800ACCC8
    // 0x800AC9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ACCC8;
    // 0x800AC9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AC9E8:
    // 0x800AC9E8: addiu       $v1, $t3, 0x100
    ctx->r3 = ADD32(ctx->r11, 0X100);
    // 0x800AC9EC: addiu       $t5, $v1, 0x20
    ctx->r13 = ADD32(ctx->r3, 0X20);
    // 0x800AC9F0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800AC9F4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800AC9F8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800AC9FC: addiu       $a1, $t5, 0x1E8
    ctx->r5 = ADD32(ctx->r13, 0X1E8);
    // 0x800ACA00: addiu       $t6, $zero, 0x818
    ctx->r14 = ADD32(0, 0X818);
    // 0x800ACA04: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ACA08: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x800ACA0C: sb          $zero, 0x4($t5)
    MEM_B(0X4, ctx->r13) = 0;
    // 0x800ACA10: sb          $zero, 0x5($t5)
    MEM_B(0X5, ctx->r13) = 0;
    // 0x800ACA14: sh          $t7, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r15;
    // 0x800ACA18: sw          $a1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r5;
    // 0x800ACA1C: addiu       $a2, $a1, 0x4C
    ctx->r6 = ADD32(ctx->r5, 0X4C);
    // 0x800ACA20: addiu       $a3, $a2, 0x240
    ctx->r7 = ADD32(ctx->r6, 0X240);
    // 0x800ACA24: addiu       $t0, $a3, 0x30
    ctx->r8 = ADD32(ctx->r7, 0X30);
    // 0x800ACA28: addiu       $t2, $t0, 0xE0
    ctx->r10 = ADD32(ctx->r8, 0XE0);
    // 0x800ACA2C: addiu       $v1, $t2, 0x20
    ctx->r3 = ADD32(ctx->r10, 0X20);
    // 0x800ACA30: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x800ACA34: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800ACA38: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800ACA3C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800ACA40: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x800ACA44: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x800ACA48: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800ACA4C: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x800ACA50: jal         0x800B79D0
    // 0x800ACA54: addiu       $a0, $t5, 0xC
    ctx->r4 = ADD32(ctx->r13, 0XC);
    guMtxIdentF(rdram, ctx);
        goto after_1;
    // 0x800ACA54: addiu       $a0, $t5, 0xC
    ctx->r4 = ADD32(ctx->r13, 0XC);
    after_1:
    // 0x800ACA58: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800ACA5C: jal         0x800B79D0
    // 0x800ACA60: addiu       $a0, $t5, 0x4C
    ctx->r4 = ADD32(ctx->r13, 0X4C);
    guMtxIdentF(rdram, ctx);
        goto after_2;
    // 0x800ACA60: addiu       $a0, $t5, 0x4C
    ctx->r4 = ADD32(ctx->r13, 0X4C);
    after_2:
    // 0x800ACA64: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800ACA68: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800ACA6C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800ACA70: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800ACA74: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800ACA78: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800ACA7C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800ACA80: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800ACA84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ACA88: addiu       $t4, $zero, 0x320
    ctx->r12 = ADD32(0, 0X320);
    // 0x800ACA8C: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x800ACA90: sb          $zero, 0x1D4($t5)
    MEM_B(0X1D4, ctx->r13) = 0;
    // 0x800ACA94: sb          $zero, 0x1D5($t5)
    MEM_B(0X1D5, ctx->r13) = 0;
    // 0x800ACA98: sb          $zero, 0x1D6($t5)
    MEM_B(0X1D6, ctx->r13) = 0;
    // 0x800ACA9C: sb          $v0, 0x1D7($t5)
    MEM_B(0X1D7, ctx->r13) = ctx->r2;
    // 0x800ACAA0: sw          $t4, 0x1D8($t5)
    MEM_W(0X1D8, ctx->r13) = ctx->r12;
    // 0x800ACAA4: sw          $t8, 0x1DC($t5)
    MEM_W(0X1DC, ctx->r13) = ctx->r24;
    // 0x800ACAA8: sw          $zero, 0x1D0($t5)
    MEM_W(0X1D0, ctx->r13) = 0;
    // 0x800ACAAC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800ACAB0: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x800ACAB4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800ACAB8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800ACABC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800ACAC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ACAC4: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x800ACAC8: sw          $t7, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r15;
    // 0x800ACACC: sw          $zero, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = 0;
    // 0x800ACAD0: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x800ACAD4: sw          $zero, 0x24($a1)
    MEM_W(0X24, ctx->r5) = 0;
    // 0x800ACAD8: sw          $zero, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = 0;
    // 0x800ACADC: sw          $zero, 0x48($a1)
    MEM_W(0X48, ctx->r5) = 0;
    // 0x800ACAE0: sw          $a2, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r6;
    // 0x800ACAE4: sw          $a3, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r7;
    // 0x800ACAE8: sw          $t2, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->r10;
    // 0x800ACAEC: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800ACAF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ACAF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800ACAF8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800ACAFC: sb          $v0, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r2;
    // 0x800ACB00: addiu       $ra, $zero, 0x100
    ctx->r31 = ADD32(0, 0X100);
    // 0x800ACB04: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x800ACB08: sh          $ra, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r31;
    // 0x800ACB0C: sb          $zero, 0x3($a2)
    MEM_B(0X3, ctx->r6) = 0;
    // 0x800ACB10: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x800ACB14: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800ACB18: sw          $t1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r9;
    // 0x800ACB1C: swc1        $f0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f0.u32l;
    // 0x800ACB20: swc1        $f0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f0.u32l;
    // 0x800ACB24: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800ACB28: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x800ACB2C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800ACB30: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x800ACB34: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x800ACB38: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800ACB3C: beq         $at, $zero, L_800ACB64
    if (ctx->r1 == 0) {
        // 0x800ACB40: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_800ACB64;
    }
    // 0x800ACB40: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800ACB44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800ACB48: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800ACB4C: nop

L_800ACB50:
    // 0x800ACB50: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800ACB54: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x800ACB58: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x800ACB5C: bne         $at, $zero, L_800ACB50
    if (ctx->r1 != 0) {
        // 0x800ACB60: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800ACB50;
    }
    // 0x800ACB60: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800ACB64:
    // 0x800ACB64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800ACB68: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800ACB6C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800ACB70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ACB74: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x800ACB78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ACB7C: sw          $s0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r16;
    // 0x800ACB80: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800ACB84: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
    // 0x800ACB88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACB8C: swc1        $f2, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f2.u32l;
    // 0x800ACB90: swc1        $f2, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f2.u32l;
    // 0x800ACB94: swc1        $f4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f4.u32l;
    // 0x800ACB98: swc1        $f6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f6.u32l;
    // 0x800ACB9C: lwc1        $f8, 0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1170);
    // 0x800ACBA0: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x800ACBA4: addiu       $t1, $t1, 0x188
    ctx->r9 = ADD32(ctx->r9, 0X188);
    // 0x800ACBA8: swc1        $f8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f8.u32l;
    // 0x800ACBAC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800ACBB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800ACBB4: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x800ACBB8: sw          $t9, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r25;
    // 0x800ACBBC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800ACBC0: addiu       $v1, $zero, 0x258
    ctx->r3 = ADD32(0, 0X258);
    // 0x800ACBC4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800ACBC8: sw          $t6, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r14;
L_800ACBCC:
    // 0x800ACBCC: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800ACBD0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800ACBD4: sh          $t4, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r12;
    // 0x800ACBD8: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
    // 0x800ACBDC: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800ACBE0: sh          $v1, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r3;
    // 0x800ACBE4: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800ACBE8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800ACBEC: sh          $a0, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r4;
    // 0x800ACBF0: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
    // 0x800ACBF4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800ACBF8: sh          $zero, 0x6($t6)
    MEM_H(0X6, ctx->r14) = 0;
    // 0x800ACBFC: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800ACC00: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800ACC04: sh          $t4, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r12;
    // 0x800ACC08: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
    // 0x800ACC0C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800ACC10: sh          $v1, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r3;
    // 0x800ACC14: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800ACC18: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800ACC1C: sh          $zero, 0xC($t8)
    MEM_H(0XC, ctx->r24) = 0;
    // 0x800ACC20: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
    // 0x800ACC24: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800ACC28: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800ACC2C: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800ACC30: bne         $at, $zero, L_800ACBCC
    if (ctx->r1 != 0) {
        // 0x800ACC34: sh          $zero, 0xE($t6)
        MEM_H(0XE, ctx->r14) = 0;
            goto L_800ACBCC;
    }
    // 0x800ACC34: sh          $zero, 0xE($t6)
    MEM_H(0XE, ctx->r14) = 0;
    // 0x800ACC38: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x800ACC3C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800ACC40: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800ACC44: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_800ACC48:
    // 0x800ACC48: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800ACC4C: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x800ACC50: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800ACC54: swc1        $f2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f2.u32l;
    // 0x800ACC58: swc1        $f2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f2.u32l;
    // 0x800ACC5C: swc1        $f2, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f2.u32l;
    // 0x800ACC60: swc1        $f2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f2.u32l;
    // 0x800ACC64: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    // 0x800ACC68: sh          $ra, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r31;
    // 0x800ACC6C: sb          $a3, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r7;
    // 0x800ACC70: sb          $zero, 0x3($a2)
    MEM_B(0X3, ctx->r6) = 0;
    // 0x800ACC74: sw          $t1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r9;
    // 0x800ACC78: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x800ACC7C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800ACC80: swc1        $f0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f0.u32l;
    // 0x800ACC84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800ACC88: addiu       $v0, $a2, 0x4
    ctx->r2 = ADD32(ctx->r6, 0X4);
L_800ACC8C:
    // 0x800ACC8C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800ACC90: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x800ACC94: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x800ACC98: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x800ACC9C: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x800ACCA0: bne         $v1, $a0, L_800ACC8C
    if (ctx->r3 != ctx->r4) {
        // 0x800ACCA4: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_800ACC8C;
    }
    // 0x800ACCA4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800ACCA8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800ACCAC: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x800ACCB0: addiu       $t0, $t0, 0x1C
    ctx->r8 = ADD32(ctx->r8, 0X1C);
    // 0x800ACCB4: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800ACCB8: addiu       $t1, $t1, 0x188
    ctx->r9 = ADD32(ctx->r9, 0X188);
    // 0x800ACCBC: bne         $a1, $zero, L_800ACC48
    if (ctx->r5 != 0) {
        // 0x800ACCC0: addiu       $t3, $t3, 0x20
        ctx->r11 = ADD32(ctx->r11, 0X20);
            goto L_800ACC48;
    }
    // 0x800ACCC0: addiu       $t3, $t3, 0x20
    ctx->r11 = ADD32(ctx->r11, 0X20);
    // 0x800ACCC4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800ACCC8:
    // 0x800ACCC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACCCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800ACCD0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800ACCD4: jr          $ra
    // 0x800ACCD8: nop

    return;
    // 0x800ACCD8: nop

;}

RECOMP_FUNC void func_800ACCDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACCDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ACCE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ACCE4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ACCE8: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x800ACCEC: beql        $t7, $zero, L_800ACD04
    if (ctx->r15 == 0) {
        // 0x800ACCF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800ACD04;
    }
    goto skip_0;
    // 0x800ACCF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800ACCF4: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800ACCF8: jal         0x8007E328
    // 0x800ACCFC: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800ACCFC: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    after_0:
    // 0x800ACD00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800ACD04:
    // 0x800ACD04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800ACD08: jr          $ra
    // 0x800ACD0C: nop

    return;
    // 0x800ACD0C: nop

;}

RECOMP_FUNC void func_800ACD10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACD10: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ACD14: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x800ACD18: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x800ACD1C: beq         $t7, $zero, L_800ACD44
    if (ctx->r15 == 0) {
        // 0x800ACD20: nop
    
            goto L_800ACD44;
    }
    // 0x800ACD20: nop

    // 0x800ACD24: bnel        $at, $zero, L_800ACD34
    if (ctx->r1 != 0) {
        // 0x800ACD28: lw          $t9, 0x8($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X8);
            goto L_800ACD34;
    }
    goto skip_0;
    // 0x800ACD28: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x800ACD2C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800ACD30: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
L_800ACD34:
    // 0x800ACD34: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x800ACD38: sw          $t8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r24;
    // 0x800ACD3C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800ACD40: sw          $a1, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r5;
L_800ACD44:
    // 0x800ACD44: jr          $ra
    // 0x800ACD48: nop

    return;
    // 0x800ACD48: nop

;}

RECOMP_FUNC void func_800ACD4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACD4C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ACD50: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800ACD54: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800ACD58: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x800ACD5C: beq         $t7, $zero, L_800ACD8C
    if (ctx->r15 == 0) {
        // 0x800ACD60: nop
    
            goto L_800ACD8C;
    }
    // 0x800ACD60: nop

    // 0x800ACD64: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800ACD68: andi        $t8, $a1, 0x7
    ctx->r24 = ctx->r5 & 0X7;
    // 0x800ACD6C: addiu       $a1, $t8, 0x1
    ctx->r5 = ADD32(ctx->r24, 0X1);
    // 0x800ACD70: lw          $t0, 0x28($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X28);
    // 0x800ACD74: sll         $t1, $a1, 6
    ctx->r9 = S32(ctx->r5 << 6);
    // 0x800ACD78: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x800ACD7C: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    // 0x800ACD80: swc1        $f14, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f14.u32l;
    // 0x800ACD84: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800ACD88: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
L_800ACD8C:
    // 0x800ACD8C: jr          $ra
    // 0x800ACD90: nop

    return;
    // 0x800ACD90: nop

;}

RECOMP_FUNC void func_800ACD94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACD94: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ACD98: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800ACD9C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800ACDA0: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x800ACDA4: beq         $t7, $zero, L_800ACDDC
    if (ctx->r15 == 0) {
        // 0x800ACDA8: nop
    
            goto L_800ACDDC;
    }
    // 0x800ACDA8: nop

    // 0x800ACDAC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800ACDB0: andi        $t8, $a1, 0x7
    ctx->r24 = ctx->r5 & 0X7;
    // 0x800ACDB4: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x800ACDB8: lw          $t0, 0x38($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X38);
    // 0x800ACDBC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800ACDC0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800ACDC4: swc1        $f12, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f12.u32l;
    // 0x800ACDC8: swc1        $f14, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f14.u32l;
    // 0x800ACDCC: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800ACDD0: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x800ACDD4: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800ACDD8: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
L_800ACDDC:
    // 0x800ACDDC: jr          $ra
    // 0x800ACDE0: nop

    return;
    // 0x800ACDE0: nop

;}

RECOMP_FUNC void func_800ACDE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACDE4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800ACDE8: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800ACDEC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800ACDF0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ACDF4: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800ACDF8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800ACDFC: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x800ACE00: beql        $t7, $zero, L_800ACE8C
    if (ctx->r15 == 0) {
        // 0x800ACE04: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_800ACE8C;
    }
    goto skip_0;
    // 0x800ACE04: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_0:
    // 0x800ACE08: sub.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800ACE0C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800ACE10: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800ACE14: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800ACE18: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x800ACE1C: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x800ACE20: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x800ACE24: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800ACE28: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x800ACE2C: nop

    // 0x800ACE30: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x800ACE34: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800ACE38: sub.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800ACE3C: add.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800ACE40: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x800ACE44: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800ACE48: add.d       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f16.d + ctx->f16.d;
    // 0x800ACE4C: add.d       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f18.d + ctx->f18.d;
    // 0x800ACE50: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800ACE54: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x800ACE58: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800ACE5C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800ACE60: sh          $t3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r11;
    // 0x800ACE64: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800ACE68: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800ACE6C: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800ACE70: cvt.d.s     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f20.d = CVT_D_S(ctx->f10.fl);
    // 0x800ACE74: add.d       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = ctx->f20.d + ctx->f20.d;
    // 0x800ACE78: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x800ACE7C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800ACE80: nop

    // 0x800ACE84: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x800ACE88: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
L_800ACE8C:
    // 0x800ACE8C: jr          $ra
    // 0x800ACE90: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800ACE90: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800ACE94: nop

    // 0x800ACE98: nop

    // 0x800ACE9C: nop

;}

RECOMP_FUNC void func_800ACEA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACEA0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800ACEA4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800ACEA8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800ACEAC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800ACEB0: addiu       $v0, $v0, 0x12F
    ctx->r2 = ADD32(ctx->r2, 0X12F);
    // 0x800ACEB4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800ACEB8: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x800ACEBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ACEC0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800ACEC4: sll         $t7, $a0, 7
    ctx->r15 = S32(ctx->r4 << 7);
    // 0x800ACEC8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800ACECC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800ACED0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800ACED4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800ACED8: jal         0x8007E03C
    // 0x800ACEDC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800ACEDC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x800ACEE0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800ACEE4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800ACEE8: bne         $v0, $zero, L_800ACEF8
    if (ctx->r2 != 0) {
        // 0x800ACEEC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800ACEF8;
    }
    // 0x800ACEEC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800ACEF0: b           L_800AD110
    // 0x800ACEF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AD110;
    // 0x800ACEF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ACEF8:
    // 0x800ACEF8: addiu       $v1, $v0, 0x120
    ctx->r3 = ADD32(ctx->r2, 0X120);
    // 0x800ACEFC: sw          $a2, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->r6;
    // 0x800ACF00: sw          $v1, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->r3;
    // 0x800ACF04: sw          $zero, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = 0;
    // 0x800ACF08: sw          $v1, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->r3;
    // 0x800ACF0C: bne         $a0, $zero, L_800ACF28
    if (ctx->r4 != 0) {
        // 0x800ACF10: sw          $zero, 0x11C($v0)
        MEM_W(0X11C, ctx->r2) = 0;
            goto L_800ACF28;
    }
    // 0x800ACF10: sw          $zero, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = 0;
    // 0x800ACF14: jal         0x800B303C
    // 0x800ACF18: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800B303C(rdram, ctx);
        goto after_1;
    // 0x800ACF18: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_1:
    // 0x800ACF1C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800ACF20: b           L_800ACF2C
    // 0x800ACF24: sw          $v0, 0xD0($a3)
    MEM_W(0XD0, ctx->r7) = ctx->r2;
        goto L_800ACF2C;
    // 0x800ACF24: sw          $v0, 0xD0($a3)
    MEM_W(0XD0, ctx->r7) = ctx->r2;
L_800ACF28:
    // 0x800ACF28: sw          $a0, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->r4;
L_800ACF2C:
    // 0x800ACF2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800ACF30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800ACF34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800ACF38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800ACF3C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800ACF40: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800ACF44: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800ACF48: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x800ACF4C: sw          $t8, 0xD4($a3)
    MEM_W(0XD4, ctx->r7) = ctx->r24;
    // 0x800ACF50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACF54: swc1        $f0, 0xDC($a3)
    MEM_W(0XDC, ctx->r7) = ctx->f0.u32l;
    // 0x800ACF58: swc1        $f0, 0xEC($a3)
    MEM_W(0XEC, ctx->r7) = ctx->f0.u32l;
    // 0x800ACF5C: swc1        $f12, 0x104($a3)
    MEM_W(0X104, ctx->r7) = ctx->f12.u32l;
    // 0x800ACF60: swc1        $f12, 0x108($a3)
    MEM_W(0X108, ctx->r7) = ctx->f12.u32l;
    // 0x800ACF64: swc1        $f2, 0xD8($a3)
    MEM_W(0XD8, ctx->r7) = ctx->f2.u32l;
    // 0x800ACF68: swc1        $f2, 0xE0($a3)
    MEM_W(0XE0, ctx->r7) = ctx->f2.u32l;
    // 0x800ACF6C: swc1        $f2, 0xE8($a3)
    MEM_W(0XE8, ctx->r7) = ctx->f2.u32l;
    // 0x800ACF70: swc1        $f2, 0xF0($a3)
    MEM_W(0XF0, ctx->r7) = ctx->f2.u32l;
    // 0x800ACF74: swc1        $f14, 0x10C($a3)
    MEM_W(0X10C, ctx->r7) = ctx->f14.u32l;
    // 0x800ACF78: swc1        $f14, 0x110($a3)
    MEM_W(0X110, ctx->r7) = ctx->f14.u32l;
    // 0x800ACF7C: lwc1        $f4, 0x1180($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1180);
    // 0x800ACF80: lw          $v0, 0xD0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XD0);
    // 0x800ACF84: sw          $zero, 0x118($a3)
    MEM_W(0X118, ctx->r7) = 0;
    // 0x800ACF88: swc1        $f2, 0xF8($a3)
    MEM_W(0XF8, ctx->r7) = ctx->f2.u32l;
    // 0x800ACF8C: swc1        $f2, 0xFC($a3)
    MEM_W(0XFC, ctx->r7) = ctx->f2.u32l;
    // 0x800ACF90: swc1        $f2, 0x100($a3)
    MEM_W(0X100, ctx->r7) = ctx->f2.u32l;
    // 0x800ACF94: swc1        $f4, 0x114($a3)
    MEM_W(0X114, ctx->r7) = ctx->f4.u32l;
    // 0x800ACF98: lh          $t0, 0xA($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XA);
    // 0x800ACF9C: lh          $t1, 0xC($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XC);
    // 0x800ACFA0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFA4: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x800ACFA8: sll         $a0, $t0, 6
    ctx->r4 = S32(ctx->r8 << 6);
    // 0x800ACFAC: sh          $a0, 0x98($a3)
    MEM_H(0X98, ctx->r7) = ctx->r4;
    // 0x800ACFB0: sh          $a0, 0xA8($a3)
    MEM_H(0XA8, ctx->r7) = ctx->r4;
    // 0x800ACFB4: lw          $a0, 0xC0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XC0);
    // 0x800ACFB8: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // 0x800ACFBC: sh          $a1, 0x82($a3)
    MEM_H(0X82, ctx->r7) = ctx->r5;
    // 0x800ACFC0: sh          $a1, 0x90($a3)
    MEM_H(0X90, ctx->r7) = ctx->r5;
    // 0x800ACFC4: sh          $a1, 0x92($a3)
    MEM_H(0X92, ctx->r7) = ctx->r5;
    // 0x800ACFC8: sh          $a1, 0xA0($a3)
    MEM_H(0XA0, ctx->r7) = ctx->r5;
    // 0x800ACFCC: sll         $a1, $t1, 6
    ctx->r5 = S32(ctx->r9 << 6);
    // 0x800ACFD0: lw          $v0, 0xC4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC4);
    // 0x800ACFD4: sh          $a2, 0x80($a3)
    MEM_H(0X80, ctx->r7) = ctx->r6;
    // 0x800ACFD8: sh          $zero, 0x84($a3)
    MEM_H(0X84, ctx->r7) = 0;
    // 0x800ACFDC: sh          $zero, 0x86($a3)
    MEM_H(0X86, ctx->r7) = 0;
    // 0x800ACFE0: sh          $zero, 0x88($a3)
    MEM_H(0X88, ctx->r7) = 0;
    // 0x800ACFE4: sh          $zero, 0x8A($a3)
    MEM_H(0X8A, ctx->r7) = 0;
    // 0x800ACFE8: sh          $zero, 0x94($a3)
    MEM_H(0X94, ctx->r7) = 0;
    // 0x800ACFEC: sh          $zero, 0x96($a3)
    MEM_H(0X96, ctx->r7) = 0;
    // 0x800ACFF0: sh          $zero, 0x9A($a3)
    MEM_H(0X9A, ctx->r7) = 0;
    // 0x800ACFF4: sh          $a2, 0xA2($a3)
    MEM_H(0XA2, ctx->r7) = ctx->r6;
    // 0x800ACFF8: sh          $zero, 0xA4($a3)
    MEM_H(0XA4, ctx->r7) = 0;
    // 0x800ACFFC: sh          $zero, 0xA6($a3)
    MEM_H(0XA6, ctx->r7) = 0;
    // 0x800AD000: sh          $a1, 0xAA($a3)
    MEM_H(0XAA, ctx->r7) = ctx->r5;
    // 0x800AD004: sh          $a2, 0xB0($a3)
    MEM_H(0XB0, ctx->r7) = ctx->r6;
    // 0x800AD008: sh          $a2, 0xB2($a3)
    MEM_H(0XB2, ctx->r7) = ctx->r6;
    // 0x800AD00C: sh          $zero, 0xB4($a3)
    MEM_H(0XB4, ctx->r7) = 0;
    // 0x800AD010: sh          $zero, 0xB6($a3)
    MEM_H(0XB6, ctx->r7) = 0;
    // 0x800AD014: sh          $zero, 0xB8($a3)
    MEM_H(0XB8, ctx->r7) = 0;
    // 0x800AD018: sh          $a1, 0xBA($a3)
    MEM_H(0XBA, ctx->r7) = ctx->r5;
    // 0x800AD01C: beq         $a0, $zero, L_800AD0AC
    if (ctx->r4 == 0) {
        // 0x800AD020: addu        $v1, $t9, $a3
        ctx->r3 = ADD32(ctx->r25, ctx->r7);
            goto L_800AD0AC;
    }
    // 0x800AD020: addu        $v1, $t9, $a3
    ctx->r3 = ADD32(ctx->r25, ctx->r7);
    // 0x800AD024: andi        $t0, $a0, 0x3
    ctx->r8 = ctx->r4 & 0X3;
    // 0x800AD028: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x800AD02C: beq         $t0, $zero, L_800AD058
    if (ctx->r8 == 0) {
        // 0x800AD030: addu        $a2, $t0, $a0
        ctx->r6 = ADD32(ctx->r8, ctx->r4);
            goto L_800AD058;
    }
    // 0x800AD030: addu        $a2, $t0, $a0
    ctx->r6 = ADD32(ctx->r8, ctx->r4);
    // 0x800AD034: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_800AD038:
    // 0x800AD038: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x800AD03C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800AD040: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AD044: sw          $a1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r5;
    // 0x800AD048: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800AD04C: bne         $a2, $a0, L_800AD038
    if (ctx->r6 != ctx->r4) {
        // 0x800AD050: addiu       $v0, $v0, 0x28
        ctx->r2 = ADD32(ctx->r2, 0X28);
            goto L_800AD038;
    }
    // 0x800AD050: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800AD054: beq         $a0, $zero, L_800AD0A8
    if (ctx->r4 == 0) {
        // 0x800AD058: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800AD0A8;
    }
L_800AD058:
    // 0x800AD058: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_800AD05C:
    // 0x800AD05C: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x800AD060: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AD064: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x800AD068: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AD06C: sw          $v1, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r3;
    // 0x800AD070: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AD074: sw          $v1, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r3;
    // 0x800AD078: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800AD07C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AD080: sw          $a1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r5;
    // 0x800AD084: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x800AD088: sw          $a1, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r5;
    // 0x800AD08C: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x800AD090: sw          $a1, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r5;
    // 0x800AD094: swc1        $f0, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f0.u32l;
    // 0x800AD098: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, 0XA0);
    // 0x800AD09C: sw          $a1, -0x84($v0)
    MEM_W(-0X84, ctx->r2) = ctx->r5;
    // 0x800AD0A0: bne         $a0, $zero, L_800AD05C
    if (ctx->r4 != 0) {
        // 0x800AD0A4: swc1        $f0, -0xA0($v0)
        MEM_W(-0XA0, ctx->r2) = ctx->f0.u32l;
            goto L_800AD05C;
    }
    // 0x800AD0A4: swc1        $f0, -0xA0($v0)
    MEM_W(-0XA0, ctx->r2) = ctx->f0.u32l;
L_800AD0A8:
    // 0x800AD0A8: lw          $a0, 0xC0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XC0);
L_800AD0AC:
    // 0x800AD0AC: beq         $a0, $zero, L_800AD10C
    if (ctx->r4 == 0) {
        // 0x800AD0B0: lw          $v0, 0xC4($a3)
        ctx->r2 = MEM_W(ctx->r7, 0XC4);
            goto L_800AD10C;
    }
    // 0x800AD0B0: lw          $v0, 0xC4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC4);
    // 0x800AD0B4: andi        $t0, $a0, 0x3
    ctx->r8 = ctx->r4 & 0X3;
    // 0x800AD0B8: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x800AD0BC: beq         $t0, $zero, L_800AD0E0
    if (ctx->r8 == 0) {
        // 0x800AD0C0: addu        $a1, $t0, $a0
        ctx->r5 = ADD32(ctx->r8, ctx->r4);
            goto L_800AD0E0;
    }
    // 0x800AD0C0: addu        $a1, $t0, $a0
    ctx->r5 = ADD32(ctx->r8, ctx->r4);
L_800AD0C4:
    // 0x800AD0C4: sw          $v1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r3;
    // 0x800AD0C8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800AD0CC: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AD0D0: bne         $a1, $a0, L_800AD0C4
    if (ctx->r5 != ctx->r4) {
        // 0x800AD0D4: addiu       $v0, $v0, 0x28
        ctx->r2 = ADD32(ctx->r2, 0X28);
            goto L_800AD0C4;
    }
    // 0x800AD0D4: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800AD0D8: beql        $a0, $zero, L_800AD110
    if (ctx->r4 == 0) {
        // 0x800AD0DC: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_800AD110;
    }
    goto skip_0;
    // 0x800AD0DC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    skip_0:
L_800AD0E0:
    // 0x800AD0E0: sw          $v1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r3;
    // 0x800AD0E4: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AD0E8: sw          $v1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r3;
    // 0x800AD0EC: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AD0F0: sw          $v1, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r3;
    // 0x800AD0F4: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AD0F8: sw          $v1, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r3;
    // 0x800AD0FC: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800AD100: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AD104: bne         $a0, $zero, L_800AD0E0
    if (ctx->r4 != 0) {
        // 0x800AD108: addiu       $v0, $v0, 0xA0
        ctx->r2 = ADD32(ctx->r2, 0XA0);
            goto L_800AD0E0;
    }
    // 0x800AD108: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, 0XA0);
L_800AD10C:
    // 0x800AD10C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800AD110:
    // 0x800AD110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD114: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800AD118: jr          $ra
    // 0x800AD11C: nop

    return;
    // 0x800AD11C: nop

;}

RECOMP_FUNC void func_800AD120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AD124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD128: jal         0x8007E328
    // 0x800AD12C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AD12C: nop

    after_0:
    // 0x800AD130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AD138: jr          $ra
    // 0x800AD13C: nop

    return;
    // 0x800AD13C: nop

;}

RECOMP_FUNC void func_800AD140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD140: beq         $a2, $zero, L_800AD168
    if (ctx->r6 == 0) {
        // 0x800AD144: lw          $v0, 0xCC($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XCC);
            goto L_800AD168;
    }
    // 0x800AD144: lw          $v0, 0xCC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XCC);
    // 0x800AD148: lw          $at, 0x0($a2)
    ctx->r1 = MEM_W(ctx->r6, 0X0);
    // 0x800AD14C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AD150: sw          $at, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r1;
    // 0x800AD154: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x800AD158: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x800AD15C: lw          $at, 0x8($a2)
    ctx->r1 = MEM_W(ctx->r6, 0X8);
    // 0x800AD160: b           L_800AD17C
    // 0x800AD164: sw          $at, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r1;
        goto L_800AD17C;
    // 0x800AD164: sw          $at, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r1;
L_800AD168:
    // 0x800AD168: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AD16C: nop

    // 0x800AD170: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x800AD174: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x800AD178: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
L_800AD17C:
    // 0x800AD17C: beql        $a1, $zero, L_800AD1A4
    if (ctx->r5 == 0) {
        // 0x800AD180: swc1        $f0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
            goto L_800AD1A4;
    }
    goto skip_0;
    // 0x800AD180: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    skip_0:
    // 0x800AD184: lw          $at, 0x0($a1)
    ctx->r1 = MEM_W(ctx->r5, 0X0);
    // 0x800AD188: sw          $at, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r1;
    // 0x800AD18C: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800AD190: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x800AD194: lw          $at, 0x8($a1)
    ctx->r1 = MEM_W(ctx->r5, 0X8);
    // 0x800AD198: b           L_800AD1AC
    // 0x800AD19C: sw          $at, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r1;
        goto L_800AD1AC;
    // 0x800AD19C: sw          $at, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r1;
    // 0x800AD1A0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_800AD1A4:
    // 0x800AD1A4: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x800AD1A8: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
L_800AD1AC:
    // 0x800AD1AC: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800AD1B0: lw          $t0, 0xC8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC8);
    // 0x800AD1B4: lw          $t2, 0xCC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XCC);
    // 0x800AD1B8: lw          $t4, 0xC0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC0);
    // 0x800AD1BC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800AD1C0: addiu       $t3, $t2, 0x28
    ctx->r11 = ADD32(ctx->r10, 0X28);
    // 0x800AD1C4: sw          $t1, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->r9;
    // 0x800AD1C8: bne         $t4, $t1, L_800AD1DC
    if (ctx->r12 != ctx->r9) {
        // 0x800AD1CC: sw          $t3, 0xCC($a0)
        MEM_W(0XCC, ctx->r4) = ctx->r11;
            goto L_800AD1DC;
    }
    // 0x800AD1CC: sw          $t3, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r11;
    // 0x800AD1D0: lw          $t6, 0xC4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC4);
    // 0x800AD1D4: sw          $zero, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = 0;
    // 0x800AD1D8: sw          $t6, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r14;
L_800AD1DC:
    // 0x800AD1DC: jr          $ra
    // 0x800AD1E0: nop

    return;
    // 0x800AD1E0: nop

;}

RECOMP_FUNC void func_800AD1E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD1E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AD1E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AD1EC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800AD1F0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800AD1F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AD1F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800AD1FC: lw          $s2, 0xC0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0XC0);
    // 0x800AD200: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800AD204: lw          $s0, 0xC4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0XC4);
    // 0x800AD208: beq         $s2, $zero, L_800AD2E0
    if (ctx->r18 == 0) {
        // 0x800AD20C: addiu       $s3, $zero, -0x1
        ctx->r19 = ADD32(0, -0X1);
            goto L_800AD2E0;
    }
    // 0x800AD20C: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800AD210:
    // 0x800AD210: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800AD214: beq         $s3, $v0, L_800AD2D4
    if (ctx->r19 == ctx->r2) {
        // 0x800AD218: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_800AD2D4;
    }
    // 0x800AD218: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800AD21C: sw          $t6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r14;
    // 0x800AD220: lw          $t7, 0xD4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XD4);
    // 0x800AD224: bnel        $t7, $t6, L_800AD238
    if (ctx->r15 != ctx->r14) {
        // 0x800AD228: lwc1        $f0, 0x10($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
            goto L_800AD238;
    }
    goto skip_0;
    // 0x800AD228: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x800AD22C: b           L_800AD2D4
    // 0x800AD230: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
        goto L_800AD2D4;
    // 0x800AD230: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x800AD234: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
L_800AD238:
    // 0x800AD238: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800AD23C: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800AD240: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AD244: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800AD248: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AD24C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800AD250: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800AD254: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x800AD258: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800AD25C: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x800AD260: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x800AD264: lw          $v0, 0x11C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X11C);
    // 0x800AD268: beql        $v0, $zero, L_800AD284
    if (ctx->r2 == 0) {
        // 0x800AD26C: lwc1        $f4, 0xF8($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0XF8);
            goto L_800AD284;
    }
    goto skip_1;
    // 0x800AD26C: lwc1        $f4, 0xF8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XF8);
    skip_1:
    // 0x800AD270: jalr        $v0
    // 0x800AD274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800AD274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800AD278: b           L_800AD2A8
    // 0x800AD27C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
        goto L_800AD2A8;
    // 0x800AD27C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AD280: lwc1        $f4, 0xF8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XF8);
L_800AD284:
    // 0x800AD284: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800AD288: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800AD28C: lwc1        $f8, 0xFC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XFC);
    // 0x800AD290: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800AD294: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x800AD298: lwc1        $f16, 0x100($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X100);
    // 0x800AD29C: add.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x800AD2A0: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x800AD2A4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
L_800AD2A8:
    // 0x800AD2A8: lwc1        $f6, 0x114($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X114);
    // 0x800AD2AC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800AD2B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AD2B4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800AD2B8: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x800AD2BC: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
    // 0x800AD2C0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AD2C4: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x800AD2C8: lwc1        $f6, 0x114($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X114);
    // 0x800AD2CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AD2D0: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
L_800AD2D4:
    // 0x800AD2D4: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800AD2D8: bne         $s2, $zero, L_800AD210
    if (ctx->r18 != 0) {
        // 0x800AD2DC: addiu       $s0, $s0, 0x28
        ctx->r16 = ADD32(ctx->r16, 0X28);
            goto L_800AD210;
    }
    // 0x800AD2DC: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
L_800AD2E0:
    // 0x800AD2E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AD2E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AD2E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AD2EC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD2F0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800AD2F4: jr          $ra
    // 0x800AD2F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AD2F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800AD2FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD2FC: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x800AD300: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800AD304: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800AD308: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800AD30C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800AD310: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800AD314: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800AD318: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800AD31C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800AD320: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800AD324: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800AD328: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x800AD32C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x800AD330: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800AD334: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800AD338: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800AD33C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800AD340: sw          $a2, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r6;
    // 0x800AD344: lw          $t6, 0x118($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X118);
    // 0x800AD348: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AD34C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800AD350: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800AD354: beq         $t7, $zero, L_800AD364
    if (ctx->r15 == 0) {
        // 0x800AD358: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800AD364;
    }
    // 0x800AD358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD35C: b           L_800AD36C
    // 0x800AD360: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
        goto L_800AD36C;
    // 0x800AD360: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
L_800AD364:
    // 0x800AD364: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800AD368: sw          $t8, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r24;
L_800AD36C:
    // 0x800AD36C: jal         0x800A4B98
    // 0x800AD370: lw          $a1, 0xD0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XD0);
    func_800A4B98(rdram, ctx);
        goto after_0;
    // 0x800AD370: lw          $a1, 0xD0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XD0);
    after_0:
    // 0x800AD374: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x800AD378: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AD37C: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x800AD380: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x800AD384: addiu       $t7, $t7, -0x6DF8
    ctx->r15 = ADD32(ctx->r15, -0X6DF8);
    // 0x800AD388: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800AD38C: andi        $t3, $t2, 0x100
    ctx->r11 = ctx->r10 & 0X100;
    // 0x800AD390: beq         $t3, $zero, L_800AD3B0
    if (ctx->r11 == 0) {
        // 0x800AD394: lui         $t6, 0xDE00
        ctx->r14 = S32(0XDE00 << 16);
            goto L_800AD3B0;
    }
    // 0x800AD394: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x800AD398: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AD39C: addiu       $t5, $t5, -0x6DB8
    ctx->r13 = ADD32(ctx->r13, -0X6DB8);
    // 0x800AD3A0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800AD3A4: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800AD3A8: b           L_800AD3B8
    // 0x800AD3AC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_800AD3B8;
    // 0x800AD3AC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_800AD3B0:
    // 0x800AD3B0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AD3B4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_800AD3B8:
    // 0x800AD3B8: lw          $s6, 0xC0($s1)
    ctx->r22 = MEM_W(ctx->r17, 0XC0);
    // 0x800AD3BC: lw          $s2, 0xCC($s1)
    ctx->r18 = MEM_W(ctx->r17, 0XCC);
    // 0x800AD3C0: lw          $s4, 0xC8($s1)
    ctx->r20 = MEM_W(ctx->r17, 0XC8);
    // 0x800AD3C4: beq         $s6, $zero, L_800AD918
    if (ctx->r22 == 0) {
        // 0x800AD3C8: lui         $at, 0x3FB0
        ctx->r1 = S32(0X3FB0 << 16);
            goto L_800AD918;
    }
    // 0x800AD3C8: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x800AD3CC: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x800AD3D0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800AD3D4: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x800AD3D8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800AD3DC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800AD3E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD3E4: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x800AD3E8: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x800AD3EC: ldc1        $f24, 0x1188($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, 0X1188);
    // 0x800AD3F0: addiu       $fp, $zero, 0x28
    ctx->r30 = ADD32(0, 0X28);
    // 0x800AD3F4: addiu       $s7, $sp, 0xA8
    ctx->r23 = ADD32(ctx->r29, 0XA8);
L_800AD3F8:
    // 0x800AD3F8: bnel        $s4, $zero, L_800AD41C
    if (ctx->r20 != 0) {
        // 0x800AD3FC: lw          $v0, -0xC($s2)
        ctx->r2 = MEM_W(ctx->r18, -0XC);
            goto L_800AD41C;
    }
    goto skip_0;
    // 0x800AD3FC: lw          $v0, -0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, -0XC);
    skip_0:
    // 0x800AD400: lw          $s4, 0xC0($s1)
    ctx->r20 = MEM_W(ctx->r17, 0XC0);
    // 0x800AD404: lw          $t8, 0xC4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC4);
    // 0x800AD408: multu       $s4, $fp
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AD40C: mflo        $t9
    ctx->r25 = lo;
    // 0x800AD410: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
    // 0x800AD414: nop

    // 0x800AD418: lw          $v0, -0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, -0XC);
L_800AD41C:
    // 0x800AD41C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AD420: addiu       $s2, $s2, -0x28
    ctx->r18 = ADD32(ctx->r18, -0X28);
    // 0x800AD424: beq         $v0, $at, L_800AD90C
    if (ctx->r2 == ctx->r1) {
        // 0x800AD428: addiu       $s4, $s4, -0x1
        ctx->r20 = ADD32(ctx->r20, -0X1);
            goto L_800AD90C;
    }
    // 0x800AD428: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800AD42C: lw          $t2, 0xD4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XD4);
    // 0x800AD430: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800AD434: lw          $t3, 0x130($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X130);
    // 0x800AD438: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800AD43C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AD440: or          $t6, $s7, $zero
    ctx->r14 = ctx->r23 | 0;
    // 0x800AD444: addiu       $t5, $t3, 0x3C
    ctx->r13 = ADD32(ctx->r11, 0X3C);
    // 0x800AD448: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AD44C: div.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AD450: cvt.d.s     $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f16.d = CVT_D_S(ctx->f20.fl);
    // 0x800AD454: sub.d       $f18, $f28, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f28.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f28.d - ctx->f16.d;
    // 0x800AD458: cvt.s.d     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f22.fl = CVT_S_D(ctx->f18.d);
L_800AD45C:
    // 0x800AD45C: lw          $at, 0x4C($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X4C);
    // 0x800AD460: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800AD464: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800AD468: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x800AD46C: lw          $at, 0x44($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X44);
    // 0x800AD470: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x800AD474: lw          $at, 0x48($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X48);
    // 0x800AD478: bne         $t3, $t5, L_800AD45C
    if (ctx->r11 != ctx->r13) {
        // 0x800AD47C: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_800AD45C;
    }
    // 0x800AD47C: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x800AD480: lw          $at, 0x4C($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X4C);
    // 0x800AD484: addiu       $s5, $s1, 0x80
    ctx->r21 = ADD32(ctx->r17, 0X80);
    // 0x800AD488: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800AD48C: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800AD490: lw          $v1, 0x11C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X11C);
    // 0x800AD494: mul.s       $f8, $f4, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x800AD498: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800AD49C: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800AD4A0: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    // 0x800AD4A4: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800AD4A8: mul.s       $f10, $f6, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x800AD4AC: swc1        $f10, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f10.u32l;
    // 0x800AD4B0: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800AD4B4: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x800AD4B8: swc1        $f18, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f18.u32l;
    // 0x800AD4BC: lw          $t8, 0x118($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X118);
    // 0x800AD4C0: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800AD4C4: beql        $t9, $zero, L_800AD4D8
    if (ctx->r25 == 0) {
        // 0x800AD4C8: lwc1        $f4, 0x10C($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X10C);
            goto L_800AD4D8;
    }
    goto skip_1;
    // 0x800AD4C8: lwc1        $f4, 0x10C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10C);
    skip_1:
    // 0x800AD4CC: b           L_800AD4EC
    // 0x800AD4D0: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
        goto L_800AD4EC;
    // 0x800AD4D0: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800AD4D4: lwc1        $f4, 0x10C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10C);
L_800AD4D8:
    // 0x800AD4D8: lwc1        $f6, 0x110($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X110);
    // 0x800AD4DC: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800AD4E0: nop

    // 0x800AD4E4: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800AD4E8: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
L_800AD4EC:
    // 0x800AD4EC: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x800AD4F0: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800AD4F4: mul.d       $f18, $f16, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f30.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f30.d);
    // 0x800AD4F8: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800AD4FC: lwc1        $f16, 0xC8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800AD500: addu        $s3, $s2, $v1
    ctx->r19 = ADD32(ctx->r18, ctx->r3);
    // 0x800AD504: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800AD508: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x800AD50C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AD510: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800AD514: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800AD518: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800AD51C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800AD520: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x800AD524: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800AD528: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AD52C: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x800AD530: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800AD534: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800AD538: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    // 0x800AD53C: lwc1        $f8, 0xC0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800AD540: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800AD544: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    // 0x800AD548: lwc1        $f16, 0xD0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800AD54C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AD550: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x800AD554: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800AD558: swc1        $f18, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f18.u32l;
    // 0x800AD55C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800AD560: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    // 0x800AD564: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x800AD568: swc1        $f18, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f18.u32l;
    // 0x800AD56C: jal         0x800B78D0
    // 0x800AD570: lw          $a1, 0x20($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X20);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800AD570: lw          $a1, 0x20($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X20);
    after_1:
    // 0x800AD574: lwc1        $f4, 0xD8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x800AD578: lwc1        $f8, 0xE8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x800AD57C: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    // 0x800AD580: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800AD584: addiu       $a1, $sp, 0xE8
    ctx->r5 = ADD32(ctx->r29, 0XE8);
    // 0x800AD588: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AD58C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800AD590: swc1        $f16, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f16.u32l;
    // 0x800AD594: lwc1        $f18, 0xDC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x800AD598: lwc1        $f8, 0xEC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x800AD59C: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800AD5A0: nop

    // 0x800AD5A4: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AD5A8: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AD5AC: swc1        $f10, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f10.u32l;
    // 0x800AD5B0: lwc1        $f16, 0xE0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XE0);
    // 0x800AD5B4: lwc1        $f8, 0xF0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x800AD5B8: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x800AD5BC: nop

    // 0x800AD5C0: mul.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AD5C4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AD5C8: jal         0x800B11C4
    // 0x800AD5CC: swc1        $f6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f6.u32l;
    func_800B11C4(rdram, ctx);
        goto after_2;
    // 0x800AD5CC: swc1        $f6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800AD5D0: lwc1        $f10, 0x104($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X104);
    // 0x800AD5D4: lwc1        $f8, 0x108($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X108);
    // 0x800AD5D8: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800AD5DC: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800AD5E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800AD5E4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800AD5E8: mul.s       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AD5EC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AD5F0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AD5F4: mul.d       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f24.d);
    // 0x800AD5F8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800AD5FC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AD600: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800AD604: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800AD608: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800AD60C: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AD610: lui         $t8, 0xDA38
    ctx->r24 = S32(0XDA38 << 16);
    // 0x800AD614: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AD618: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AD61C: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x800AD620: nop

    // 0x800AD624: cvt.w.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_D(ctx->f10.d);
    // 0x800AD628: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x800AD62C: nop

    // 0x800AD630: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x800AD634: beql        $a3, $zero, L_800AD688
    if (ctx->r7 == 0) {
        // 0x800AD638: mfc1        $a3, $f8
        ctx->r7 = (int32_t)ctx->f8.u32l;
            goto L_800AD688;
    }
    goto skip_2;
    // 0x800AD638: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x800AD63C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800AD640: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AD644: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800AD648: sub.d       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f10.d - ctx->f8.d;
    // 0x800AD64C: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x800AD650: nop

    // 0x800AD654: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x800AD658: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x800AD65C: nop

    // 0x800AD660: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x800AD664: bne         $a3, $zero, L_800AD67C
    if (ctx->r7 != 0) {
        // 0x800AD668: nop
    
            goto L_800AD67C;
    }
    // 0x800AD668: nop

    // 0x800AD66C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800AD670: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AD674: b           L_800AD694
    // 0x800AD678: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_800AD694;
    // 0x800AD678: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_800AD67C:
    // 0x800AD67C: b           L_800AD694
    // 0x800AD680: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_800AD694;
    // 0x800AD680: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800AD684: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
L_800AD688:
    // 0x800AD688: nop

    // 0x800AD68C: bltz        $a3, L_800AD67C
    if (SIGNED(ctx->r7) < 0) {
        // 0x800AD690: nop
    
            goto L_800AD67C;
    }
    // 0x800AD690: nop

L_800AD694:
    // 0x800AD694: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AD698: lwc1        $f16, 0xEC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800AD69C: andi        $t4, $a3, 0xFF
    ctx->r12 = ctx->r7 & 0XFF;
    // 0x800AD6A0: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x800AD6A4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800AD6A8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800AD6AC: mul.d       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f24.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f24.d);
    // 0x800AD6B0: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x800AD6B4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AD6B8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AD6BC: nop

    // 0x800AD6C0: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800AD6C4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AD6C8: nop

    // 0x800AD6CC: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800AD6D0: beql        $t0, $zero, L_800AD724
    if (ctx->r8 == 0) {
        // 0x800AD6D4: mfc1        $t0, $f6
        ctx->r8 = (int32_t)ctx->f6.u32l;
            goto L_800AD724;
    }
    goto skip_3;
    // 0x800AD6D4: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x800AD6D8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800AD6DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AD6E0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800AD6E4: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x800AD6E8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AD6EC: nop

    // 0x800AD6F0: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800AD6F4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AD6F8: nop

    // 0x800AD6FC: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800AD700: bne         $t0, $zero, L_800AD718
    if (ctx->r8 != 0) {
        // 0x800AD704: nop
    
            goto L_800AD718;
    }
    // 0x800AD704: nop

    // 0x800AD708: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800AD70C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AD710: b           L_800AD730
    // 0x800AD714: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800AD730;
    // 0x800AD714: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800AD718:
    // 0x800AD718: b           L_800AD730
    // 0x800AD71C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800AD730;
    // 0x800AD71C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800AD720: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
L_800AD724:
    // 0x800AD724: nop

    // 0x800AD728: bltz        $t0, L_800AD718
    if (SIGNED(ctx->r8) < 0) {
        // 0x800AD72C: nop
    
            goto L_800AD718;
    }
    // 0x800AD72C: nop

L_800AD730:
    // 0x800AD730: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AD734: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800AD738: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AD73C: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x800AD740: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800AD744: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x800AD748: mul.d       $f16, $f8, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f24.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f24.d);
    // 0x800AD74C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800AD750: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AD754: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AD758: nop

    // 0x800AD75C: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x800AD760: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AD764: nop

    // 0x800AD768: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800AD76C: beql        $t1, $zero, L_800AD7C0
    if (ctx->r9 == 0) {
        // 0x800AD770: mfc1        $t1, $f18
        ctx->r9 = (int32_t)ctx->f18.u32l;
            goto L_800AD7C0;
    }
    goto skip_4;
    // 0x800AD770: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    skip_4:
    // 0x800AD774: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800AD778: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AD77C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AD780: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x800AD784: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AD788: nop

    // 0x800AD78C: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x800AD790: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AD794: nop

    // 0x800AD798: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800AD79C: bne         $t1, $zero, L_800AD7B4
    if (ctx->r9 != 0) {
        // 0x800AD7A0: nop
    
            goto L_800AD7B4;
    }
    // 0x800AD7A0: nop

    // 0x800AD7A4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800AD7A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AD7AC: b           L_800AD7CC
    // 0x800AD7B0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800AD7CC;
    // 0x800AD7B0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800AD7B4:
    // 0x800AD7B4: b           L_800AD7CC
    // 0x800AD7B8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800AD7CC;
    // 0x800AD7B8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800AD7BC: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
L_800AD7C0:
    // 0x800AD7C0: nop

    // 0x800AD7C4: bltz        $t1, L_800AD7B4
    if (SIGNED(ctx->r9) < 0) {
        // 0x800AD7C8: nop
    
            goto L_800AD7B4;
    }
    // 0x800AD7C8: nop

L_800AD7CC:
    // 0x800AD7CC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AD7D0: or          $t7, $t1, $zero
    ctx->r15 = ctx->r9 | 0;
    // 0x800AD7D4: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x800AD7D8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800AD7DC: andi        $t6, $t0, 0xFF
    ctx->r14 = ctx->r8 & 0XFF;
    // 0x800AD7E0: mul.d       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f24.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f24.d);
    // 0x800AD7E4: or          $t5, $a3, $zero
    ctx->r13 = ctx->r7 | 0;
    // 0x800AD7E8: sll         $t3, $t5, 24
    ctx->r11 = S32(ctx->r13 << 24);
    // 0x800AD7EC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800AD7F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AD7F4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AD7F8: lw          $t9, 0x20($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X20);
    // 0x800AD7FC: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800AD800: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AD804: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AD808: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800AD80C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800AD810: cvt.w.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_D(ctx->f6.d);
    // 0x800AD814: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800AD818: andi        $t9, $t1, 0xFF
    ctx->r25 = ctx->r9 & 0XFF;
    // 0x800AD81C: sll         $t2, $t9, 8
    ctx->r10 = S32(ctx->r25 << 8);
    // 0x800AD820: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AD824: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800AD828: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x800AD82C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800AD830: beq         $t6, $zero, L_800AD884
    if (ctx->r14 == 0) {
        // 0x800AD834: or          $t4, $t8, $t2
        ctx->r12 = ctx->r24 | ctx->r10;
            goto L_800AD884;
    }
    // 0x800AD834: or          $t4, $t8, $t2
    ctx->r12 = ctx->r24 | ctx->r10;
    // 0x800AD838: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800AD83C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800AD840: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AD844: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AD848: sub.d       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f6.d - ctx->f10.d;
    // 0x800AD84C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AD850: nop

    // 0x800AD854: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x800AD858: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AD85C: nop

    // 0x800AD860: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800AD864: bne         $t6, $zero, L_800AD87C
    if (ctx->r14 != 0) {
        // 0x800AD868: nop
    
            goto L_800AD87C;
    }
    // 0x800AD868: nop

    // 0x800AD86C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800AD870: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AD874: b           L_800AD894
    // 0x800AD878: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800AD894;
    // 0x800AD878: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800AD87C:
    // 0x800AD87C: b           L_800AD894
    // 0x800AD880: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800AD894;
    // 0x800AD880: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_800AD884:
    // 0x800AD884: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800AD888: nop

    // 0x800AD88C: bltz        $t6, L_800AD87C
    if (SIGNED(ctx->r14) < 0) {
        // 0x800AD890: nop
    
            goto L_800AD87C;
    }
    // 0x800AD890: nop

L_800AD894:
    // 0x800AD894: or          $t3, $t6, $zero
    ctx->r11 = ctx->r14 | 0;
    // 0x800AD898: andi        $t7, $t3, 0xFF
    ctx->r15 = ctx->r11 & 0XFF;
    // 0x800AD89C: or          $t9, $t4, $t7
    ctx->r25 = ctx->r12 | ctx->r15;
    // 0x800AD8A0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AD8A4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800AD8A8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AD8AC: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x800AD8B0: ori         $t8, $t8, 0x4008
    ctx->r24 = ctx->r24 | 0X4008;
    // 0x800AD8B4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800AD8B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AD8BC: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x800AD8C0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AD8C4: lui         $t2, 0x500
    ctx->r10 = S32(0X500 << 16);
    // 0x800AD8C8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AD8CC: ori         $t2, $t2, 0x204
    ctx->r10 = ctx->r10 | 0X204;
    // 0x800AD8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD8D4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800AD8D8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800AD8DC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AD8E0: lui         $t5, 0x504
    ctx->r13 = S32(0X504 << 16);
    // 0x800AD8E4: ori         $t5, $t5, 0x600
    ctx->r13 = ctx->r13 | 0X600;
    // 0x800AD8E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800AD8EC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800AD8F0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800AD8F4: lui         $t6, 0xD838
    ctx->r14 = S32(0XD838 << 16);
    // 0x800AD8F8: ori         $t6, $t6, 0x2
    ctx->r14 = ctx->r14 | 0X2;
    // 0x800AD8FC: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x800AD900: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x800AD904: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800AD908: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800AD90C:
    // 0x800AD90C: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800AD910: bne         $s6, $zero, L_800AD3F8
    if (ctx->r22 != 0) {
        // 0x800AD914: nop
    
            goto L_800AD3F8;
    }
    // 0x800AD914: nop

L_800AD918:
    // 0x800AD918: lw          $t4, 0x118($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X118);
    // 0x800AD91C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AD920: xori        $t7, $t4, 0x4
    ctx->r15 = ctx->r12 ^ 0X4;
    // 0x800AD924: sw          $t7, 0x118($s1)
    MEM_W(0X118, ctx->r17) = ctx->r15;
    // 0x800AD928: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800AD92C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800AD930: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800AD934: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800AD938: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800AD93C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800AD940: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800AD944: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800AD948: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800AD94C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800AD950: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x800AD954: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x800AD958: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800AD95C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800AD960: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800AD964: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800AD968: jr          $ra
    // 0x800AD96C: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x800AD96C: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}

RECOMP_FUNC void func_800AD970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AD974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD978: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800AD97C: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x800AD980: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AD984: addiu       $t7, $t7, -0x6EF0
    ctx->r15 = ADD32(ctx->r15, -0X6EF0);
    // 0x800AD988: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x800AD98C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AD990: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800AD994: jal         0x800AD2FC
    // 0x800AD998: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800AD2FC(rdram, ctx);
        goto after_0;
    // 0x800AD998: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x800AD99C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD9A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AD9A4: jr          $ra
    // 0x800AD9A8: nop

    return;
    // 0x800AD9A8: nop

;}

RECOMP_FUNC void func_800AD9AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD9AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AD9B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD9B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AD9B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800AD9BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800AD9C0: lw          $t7, 0x118($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X118);
    // 0x800AD9C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AD9C8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800AD9CC: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800AD9D0: beq         $t8, $zero, L_800AD9E0
    if (ctx->r24 == 0) {
        // 0x800AD9D4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800AD9E0;
    }
    // 0x800AD9D4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800AD9D8: b           L_800AD9E0
    // 0x800AD9DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800AD9E0;
    // 0x800AD9DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800AD9E0:
    // 0x800AD9E0: sll         $t0, $v1, 6
    ctx->r8 = S32(ctx->r3 << 6);
    // 0x800AD9E4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x800AD9E8: jal         0x800B78D0
    // 0x800AD9EC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    guMtxF2L(rdram, ctx);
        goto after_0;
    // 0x800AD9EC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800AD9F0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD9F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800AD9F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800AD9FC: lui         $t1, 0xDA38
    ctx->r9 = S32(0XDA38 << 16);
    // 0x800ADA00: sll         $t2, $v1, 6
    ctx->r10 = S32(ctx->r3 << 6);
    // 0x800ADA04: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800ADA08: ori         $t1, $t1, 0x3
    ctx->r9 = ctx->r9 | 0X3;
    // 0x800ADA0C: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x800ADA10: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800ADA14: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800ADA18: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800ADA1C: jal         0x800AD2FC
    // 0x800ADA20: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800AD2FC(rdram, ctx);
        goto after_1;
    // 0x800ADA20: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x800ADA24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ADA28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800ADA2C: jr          $ra
    // 0x800ADA30: nop

    return;
    // 0x800ADA30: nop

;}

RECOMP_FUNC void func_800ADA34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADA34: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800ADA38: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800ADA3C: swc1        $f12, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f12.u32l;
    // 0x800ADA40: jr          $ra
    // 0x800ADA44: swc1        $f14, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x800ADA44: swc1        $f14, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f14.u32l;
;}

RECOMP_FUNC void func_800ADA48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADA48: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800ADA4C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800ADA50: swc1        $f12, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->f12.u32l;
    // 0x800ADA54: jr          $ra
    // 0x800ADA58: swc1        $f14, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x800ADA58: swc1        $f14, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->f14.u32l;
;}

RECOMP_FUNC void func_800ADA5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADA5C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800ADA60: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800ADA64: swc1        $f12, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->f12.u32l;
    // 0x800ADA68: jr          $ra
    // 0x800ADA6C: swc1        $f14, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x800ADA6C: swc1        $f14, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f14.u32l;
;}

RECOMP_FUNC void func_800ADA70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADA70: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800ADA74: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800ADA78: swc1        $f12, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f12.u32l;
    // 0x800ADA7C: jr          $ra
    // 0x800ADA80: swc1        $f14, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x800ADA80: swc1        $f14, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f14.u32l;
;}

RECOMP_FUNC void func_800ADA84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADA84: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800ADA88: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800ADA8C: swc1        $f12, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f12.u32l;
    // 0x800ADA90: jr          $ra
    // 0x800ADA94: swc1        $f14, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x800ADA94: swc1        $f14, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f14.u32l;
;}

RECOMP_FUNC void func_800ADA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADA98: jr          $ra
    // 0x800ADA9C: sw          $a1, 0xD4($a0)
    MEM_W(0XD4, ctx->r4) = ctx->r5;
    return;
    // 0x800ADA9C: sw          $a1, 0xD4($a0)
    MEM_W(0XD4, ctx->r4) = ctx->r5;
;}

RECOMP_FUNC void func_800ADAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADAA0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800ADAA4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800ADAA8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800ADAAC: swc1        $f12, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f12.u32l;
    // 0x800ADAB0: swc1        $f14, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f14.u32l;
    // 0x800ADAB4: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800ADAB8: jr          $ra
    // 0x800ADABC: swc1        $f4, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800ADABC: swc1        $f4, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f4.u32l;
;}

RECOMP_FUNC void func_800ADAC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADAC0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800ADAC4: jr          $ra
    // 0x800ADAC8: swc1        $f12, 0x114($a0)
    MEM_W(0X114, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x800ADAC8: swc1        $f12, 0x114($a0)
    MEM_W(0X114, ctx->r4) = ctx->f12.u32l;
    // 0x800ADACC: nop

;}

RECOMP_FUNC void func_800ADAD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADAD0: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800ADAD4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800ADAD8: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800ADADC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800ADAE0: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x800ADAE4: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x800ADAE8: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x800ADAEC: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x800ADAF0: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x800ADAF4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800ADAF8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800ADAFC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800ADB00: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800ADB04: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800ADB08: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800ADB0C: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800ADB10: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x800ADB14: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800ADB18: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADB1C: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x800ADB20: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800ADB24: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800ADB28: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800ADB2C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800ADB30: ori         $t9, $t9, 0xC00
    ctx->r25 = ctx->r25 | 0XC00;
    // 0x800ADB34: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADB38: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800ADB3C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800ADB40: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800ADB44: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x800ADB48: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800ADB4C: ori         $t6, $t6, 0x1201
    ctx->r14 = ctx->r14 | 0X1201;
    // 0x800ADB50: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADB54: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800ADB58: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800ADB5C: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800ADB60: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800ADB64: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADB68: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x800ADB6C: ori         $t7, $t7, 0x1801
    ctx->r15 = ctx->r15 | 0X1801;
    // 0x800ADB70: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800ADB74: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800ADB78: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x800ADB7C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800ADB80: lui         $t9, 0xF900
    ctx->r25 = S32(0XF900 << 16);
    // 0x800ADB84: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800ADB88: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800ADB8C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADB90: lbu         $v1, 0xBF($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0XBF);
    // 0x800ADB94: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800ADB98: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x800ADB9C: ori         $t6, $t6, 0x1E01
    ctx->r14 = ctx->r14 | 0X1E01;
    // 0x800ADBA0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADBA4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800ADBA8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800ADBAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800ADBB0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADBB4: lui         $t7, 0xF800
    ctx->r15 = S32(0XF800 << 16);
    // 0x800ADBB8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800ADBBC: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800ADBC0: lui         $t6, 0xFF2F
    ctx->r14 = S32(0XFF2F << 16);
    // 0x800ADBC4: lui         $t9, 0xFC11
    ctx->r25 = S32(0XFC11 << 16);
    // 0x800ADBC8: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800ADBCC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800ADBD0: ori         $t9, $t9, 0x9623
    ctx->r25 = ctx->r25 | 0X9623;
    // 0x800ADBD4: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800ADBD8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800ADBDC: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x800ADBE0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800ADBE4: bne         $v1, $at, L_800ADC10
    if (ctx->r3 != ctx->r1) {
        // 0x800ADBE8: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_800ADC10;
    }
    // 0x800ADBE8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADBEC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800ADBF0: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x800ADBF4: lui         $t8, 0xF0A
    ctx->r24 = S32(0XF0A << 16);
    // 0x800ADBF8: ori         $t8, $t8, 0x4000
    ctx->r24 = ctx->r24 | 0X4000;
    // 0x800ADBFC: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x800ADC00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800ADC04: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800ADC08: b           L_800ADC30
    // 0x800ADC0C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_800ADC30;
    // 0x800ADC0C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800ADC10:
    // 0x800ADC10: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800ADC14: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800ADC18: lui         $t6, 0x440
    ctx->r14 = S32(0X440 << 16);
    // 0x800ADC1C: ori         $t6, $t6, 0x4340
    ctx->r14 = ctx->r14 | 0X4340;
    // 0x800ADC20: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800ADC24: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800ADC28: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800ADC2C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800ADC30:
    // 0x800ADC30: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800ADC34: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800ADC38: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800ADC3C: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800ADC40: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800ADC44: sll         $t9, $a2, 24
    ctx->r25 = S32(ctx->r6 << 24);
    // 0x800ADC48: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800ADC4C: lbu         $t9, 0xBB($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XBB);
    // 0x800ADC50: lui         $ra, 0x8
    ctx->r31 = S32(0X8 << 16);
    // 0x800ADC54: lui         $s4, 0x708
    ctx->r20 = S32(0X708 << 16);
    // 0x800ADC58: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x800ADC5C: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800ADC60: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x800ADC64: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800ADC68: lui         $s2, 0xFD10
    ctx->r18 = S32(0XFD10 << 16);
    // 0x800ADC6C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800ADC70: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADC74: ori         $s2, $s2, 0x13F
    ctx->r18 = ctx->r18 | 0X13F;
    // 0x800ADC78: ori         $s4, $s4, 0x200
    ctx->r20 = ctx->r20 | 0X200;
    // 0x800ADC7C: ori         $ra, $ra, 0x200
    ctx->r31 = ctx->r31 | 0X200;
    // 0x800ADC80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800ADC84: lui         $fp, 0xE700
    ctx->r30 = S32(0XE700 << 16);
    // 0x800ADC88: lui         $s7, 0x700
    ctx->r23 = S32(0X700 << 16);
    // 0x800ADC8C: lui         $s6, 0xF400
    ctx->r22 = S32(0XF400 << 16);
    // 0x800ADC90: lui         $s5, 0xE600
    ctx->r21 = S32(0XE600 << 16);
    // 0x800ADC94: lui         $s3, 0xF510
    ctx->r19 = S32(0XF510 << 16);
    // 0x800ADC98: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x800ADC9C: addiu       $v1, $v0, 0x1E
    ctx->r3 = ADD32(ctx->r2, 0X1E);
L_800ADCA0:
    // 0x800ADCA0: sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3 << 2);
    // 0x800ADCA4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800ADCA8: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x800ADCAC: addiu       $t4, $v0, 0x1D
    ctx->r12 = ADD32(ctx->r2, 0X1D);
    // 0x800ADCB0: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800ADCB4: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x800ADCB8: andi        $t8, $s1, 0xFFF
    ctx->r24 = ctx->r17 & 0XFFF;
    // 0x800ADCBC: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x800ADCC0: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x800ADCC4: andi        $t4, $t6, 0xFFF
    ctx->r12 = ctx->r14 & 0XFFF;
    // 0x800ADCC8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800ADCCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800ADCD0: addiu       $s0, $zero, 0x87
    ctx->r16 = ADD32(0, 0X87);
L_800ADCD4:
    // 0x800ADCD4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800ADCD8: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x800ADCDC: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800ADCE0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADCE4: sra         $t6, $s0, 3
    ctx->r14 = S32(SIGNED(ctx->r16) >> 3);
    // 0x800ADCE8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800ADCEC: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x800ADCF0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800ADCF4: sll         $t0, $a3, 2
    ctx->r8 = S32(ctx->r7 << 2);
    // 0x800ADCF8: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x800ADCFC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADD00: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x800ADD04: or          $t2, $t8, $s3
    ctx->r10 = ctx->r24 | ctx->r19;
    // 0x800ADD08: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800ADD0C: sll         $t0, $t7, 12
    ctx->r8 = S32(ctx->r15 << 12);
    // 0x800ADD10: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800ADD14: sw          $s4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r20;
    // 0x800ADD18: addiu       $v0, $a3, 0x3F
    ctx->r2 = ADD32(ctx->r7, 0X3F);
    // 0x800ADD1C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800ADD20: or          $t9, $t0, $s6
    ctx->r25 = ctx->r8 | ctx->r22;
    // 0x800ADD24: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADD28: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x800ADD2C: or          $t8, $t9, $t1
    ctx->r24 = ctx->r25 | ctx->r9;
    // 0x800ADD30: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x800ADD34: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800ADD38: sw          $s5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r21;
    // 0x800ADD3C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800ADD40: sll         $v0, $t6, 12
    ctx->r2 = S32(ctx->r14 << 12);
    // 0x800ADD44: or          $t8, $v0, $s7
    ctx->r24 = ctx->r2 | ctx->r23;
    // 0x800ADD48: or          $t7, $t8, $t4
    ctx->r15 = ctx->r24 | ctx->r12;
    // 0x800ADD4C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADD50: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800ADD54: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x800ADD58: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADD5C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800ADD60: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADD64: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800ADD68: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x800ADD6C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800ADD70: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800ADD74: or          $t6, $t0, $t5
    ctx->r14 = ctx->r8 | ctx->r13;
    // 0x800ADD78: or          $t9, $t6, $t1
    ctx->r25 = ctx->r14 | ctx->r9;
    // 0x800ADD7C: sw          $ra, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r31;
    // 0x800ADD80: or          $t8, $v0, $t4
    ctx->r24 = ctx->r2 | ctx->r12;
    // 0x800ADD84: addiu       $t2, $a3, 0x40
    ctx->r10 = ADD32(ctx->r7, 0X40);
    // 0x800ADD88: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800ADD8C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800ADD90: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADD94: lui         $t7, 0xF
    ctx->r15 = S32(0XF << 16);
    // 0x800ADD98: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x800ADD9C: ori         $t7, $t7, 0xF077
    ctx->r15 = ctx->r15 | 0XF077;
    // 0x800ADDA0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800ADDA4: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x800ADDA8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800ADDAC: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800ADDB0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADDB4: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x800ADDB8: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800ADDBC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800ADDC0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800ADDC4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800ADDC8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADDCC: or          $t9, $t6, $s1
    ctx->r25 = ctx->r14 | ctx->r17;
    // 0x800ADDD0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800ADDD4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800ADDD8: or          $t8, $t0, $t1
    ctx->r24 = ctx->r8 | ctx->r9;
    // 0x800ADDDC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800ADDE0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADDE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800ADDE8: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x800ADDEC: lui         $t7, 0xE100
    ctx->r15 = S32(0XE100 << 16);
    // 0x800ADDF0: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x800ADDF4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800ADDF8: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x800ADDFC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800ADE00: lui         $t6, 0xF100
    ctx->r14 = S32(0XF100 << 16);
    // 0x800ADE04: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x800ADE08: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800ADE0C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x800ADE10: bne         $t2, $at, L_800ADCD4
    if (ctx->r10 != ctx->r1) {
        // 0x800ADE14: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_800ADCD4;
    }
    // 0x800ADE14: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800ADE18: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800ADE1C: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x800ADE20: bnel        $v0, $at, L_800ADCA0
    if (ctx->r2 != ctx->r1) {
        // 0x800ADE24: addiu       $v1, $v0, 0x1E
        ctx->r3 = ADD32(ctx->r2, 0X1E);
            goto L_800ADCA0;
    }
    goto skip_0;
    // 0x800ADE24: addiu       $v1, $v0, 0x1E
    ctx->r3 = ADD32(ctx->r2, 0X1E);
    skip_0:
    // 0x800ADE28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800ADE2C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800ADE30: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800ADE34: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x800ADE38: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x800ADE3C: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x800ADE40: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADE44: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x800ADE48: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x800ADE4C: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x800ADE50: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x800ADE54: jr          $ra
    // 0x800ADE58: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800ADE58: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}

RECOMP_FUNC void func_800ADE5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADE5C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800ADE60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800ADE64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ADE68: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ADE6C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ADE70: bgez        $a2, L_800ADE84
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800ADE74: andi        $t6, $a2, 0x3F
        ctx->r14 = ctx->r6 & 0X3F;
            goto L_800ADE84;
    }
    // 0x800ADE74: andi        $t6, $a2, 0x3F
    ctx->r14 = ctx->r6 & 0X3F;
    // 0x800ADE78: beq         $t6, $zero, L_800ADE84
    if (ctx->r14 == 0) {
        // 0x800ADE7C: nop
    
            goto L_800ADE84;
    }
    // 0x800ADE7C: nop

    // 0x800ADE80: addiu       $t6, $t6, -0x40
    ctx->r14 = ADD32(ctx->r14, -0X40);
L_800ADE84:
    // 0x800ADE84: blez        $t6, L_800ADE94
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800ADE88: addiu       $a0, $zero, 0x1E
        ctx->r4 = ADD32(0, 0X1E);
            goto L_800ADE94;
    }
    // 0x800ADE88: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x800ADE8C: b           L_800ADE98
    // 0x800ADE90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800ADE98;
    // 0x800ADE90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ADE94:
    // 0x800ADE94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ADE98:
    // 0x800ADE98: div         $zero, $a1, $a0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r4)));
    // 0x800ADE9C: bgez        $a2, L_800ADEAC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800ADEA0: sra         $t7, $a2, 6
        ctx->r15 = S32(SIGNED(ctx->r6) >> 6);
            goto L_800ADEAC;
    }
    // 0x800ADEA0: sra         $t7, $a2, 6
    ctx->r15 = S32(SIGNED(ctx->r6) >> 6);
    // 0x800ADEA4: addiu       $at, $a2, 0x3F
    ctx->r1 = ADD32(ctx->r6, 0X3F);
    // 0x800ADEA8: sra         $t7, $at, 6
    ctx->r15 = S32(SIGNED(ctx->r1) >> 6);
L_800ADEAC:
    // 0x800ADEAC: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x800ADEB0: bne         $a0, $zero, L_800ADEBC
    if (ctx->r4 != 0) {
        // 0x800ADEB4: nop
    
            goto L_800ADEBC;
    }
    // 0x800ADEB4: nop

    // 0x800ADEB8: break       7
    do_break(2148196024);
L_800ADEBC:
    // 0x800ADEBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800ADEC0: bne         $a0, $at, L_800ADED4
    if (ctx->r4 != ctx->r1) {
        // 0x800ADEC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800ADED4;
    }
    // 0x800ADEC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ADEC8: bne         $a1, $at, L_800ADED4
    if (ctx->r5 != ctx->r1) {
        // 0x800ADECC: nop
    
            goto L_800ADED4;
    }
    // 0x800ADECC: nop

    // 0x800ADED0: break       6
    do_break(2148196048);
L_800ADED4:
    // 0x800ADED4: mflo        $v1
    ctx->r3 = lo;
    // 0x800ADED8: mfhi        $t8
    ctx->r24 = hi;
    // 0x800ADEDC: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800ADEE0: blez        $t8, L_800ADEF0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800ADEE4: sll         $t9, $t5, 6
        ctx->r25 = S32(ctx->r13 << 6);
            goto L_800ADEF0;
    }
    // 0x800ADEE4: sll         $t9, $t5, 6
    ctx->r25 = S32(ctx->r13 << 6);
    // 0x800ADEE8: b           L_800ADEF4
    // 0x800ADEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800ADEF4;
    // 0x800ADEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ADEF0:
    // 0x800ADEF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ADEF4:
    // 0x800ADEF4: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800ADEF8: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADEFC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800ADF00: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800ADF04: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800ADF08: mflo        $a0
    ctx->r4 = lo;
    // 0x800ADF0C: addiu       $a0, $a0, 0x148
    ctx->r4 = ADD32(ctx->r4, 0X148);
    // 0x800ADF10: jal         0x8007E03C
    // 0x800ADF14: nop

    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800ADF14: nop

    after_0:
    // 0x800ADF18: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800ADF1C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADF20: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800ADF24: sll         $a2, $t0, 1
    ctx->r6 = S32(ctx->r8 << 1);
    // 0x800ADF28: sll         $a3, $t1, 1
    ctx->r7 = S32(ctx->r9 << 1);
    // 0x800ADF2C: addiu       $t6, $zero, 0x3FF
    ctx->r14 = ADD32(0, 0X3FF);
    // 0x800ADF30: addiu       $a1, $v0, 0x148
    ctx->r5 = ADD32(ctx->r2, 0X148);
    // 0x800ADF34: sw          $s0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r16;
    // 0x800ADF38: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800ADF3C: sh          $a2, 0x118($v0)
    MEM_H(0X118, ctx->r2) = ctx->r6;
    // 0x800ADF40: sh          $a3, 0x11A($v0)
    MEM_H(0X11A, ctx->r2) = ctx->r7;
    // 0x800ADF44: sh          $t6, 0x11C($v0)
    MEM_H(0X11C, ctx->r2) = ctx->r14;
    // 0x800ADF48: sh          $zero, 0x11E($v0)
    MEM_H(0X11E, ctx->r2) = 0;
    // 0x800ADF4C: sh          $a2, 0x120($v0)
    MEM_H(0X120, ctx->r2) = ctx->r6;
    // 0x800ADF50: sh          $a3, 0x122($v0)
    MEM_H(0X122, ctx->r2) = ctx->r7;
    // 0x800ADF54: sh          $zero, 0x124($v0)
    MEM_H(0X124, ctx->r2) = 0;
    // 0x800ADF58: sh          $zero, 0x126($v0)
    MEM_H(0X126, ctx->r2) = 0;
    // 0x800ADF5C: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    // 0x800ADF60: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800ADF64: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800ADF68: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800ADF6C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800ADF70: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x800ADF74: jal         0x800B7A58
    // 0x800ADF78: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    guMtxIdent(rdram, ctx);
        goto after_1;
    // 0x800ADF78: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    after_1:
    // 0x800ADF7C: jal         0x800B7A58
    // 0x800ADF80: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    guMtxIdent(rdram, ctx);
        goto after_2;
    // 0x800ADF80: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_2:
    // 0x800ADF84: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800ADF88: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800ADF8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ADF90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800ADF94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800ADF98: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800ADF9C: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800ADFA0: swc1        $f0, 0x128($s1)
    MEM_W(0X128, ctx->r17) = ctx->f0.u32l;
    // 0x800ADFA4: swc1        $f0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->f0.u32l;
    // 0x800ADFA8: swc1        $f0, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->f0.u32l;
    // 0x800ADFAC: swc1        $f0, 0x140($s1)
    MEM_W(0X140, ctx->r17) = ctx->f0.u32l;
    // 0x800ADFB0: swc1        $f2, 0x134($s1)
    MEM_W(0X134, ctx->r17) = ctx->f2.u32l;
    // 0x800ADFB4: swc1        $f2, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->f2.u32l;
    // 0x800ADFB8: blez        $s0, L_800AE208
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800ADFBC: swc1        $f2, 0x13C($s1)
        MEM_W(0X13C, ctx->r17) = ctx->f2.u32l;
            goto L_800AE208;
    }
    // 0x800ADFBC: swc1        $f2, 0x13C($s1)
    MEM_W(0X13C, ctx->r17) = ctx->f2.u32l;
    // 0x800ADFC0: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x800ADFC4: addiu       $t2, $zero, 0x741
    ctx->r10 = ADD32(0, 0X741);
    // 0x800ADFC8: addiu       $t1, $zero, 0xFC1
    ctx->r9 = ADD32(0, 0XFC1);
    // 0x800ADFCC: addiu       $a3, $zero, -0x3F
    ctx->r7 = ADD32(0, -0X3F);
    // 0x800ADFD0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800ADFD4:
    // 0x800ADFD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800ADFD8: blez        $t5, L_800AE1FC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800ADFDC: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_800AE1FC;
    }
    // 0x800ADFDC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800ADFE0: andi        $a0, $t5, 0x1
    ctx->r4 = ctx->r13 & 0X1;
    // 0x800ADFE4: beq         $a0, $zero, L_800AE09C
    if (ctx->r4 == 0) {
        // 0x800ADFE8: addiu       $a1, $t0, 0x1E
        ctx->r5 = ADD32(ctx->r8, 0X1E);
            goto L_800AE09C;
    }
    // 0x800ADFE8: addiu       $a1, $t0, 0x1E
    ctx->r5 = ADD32(ctx->r8, 0X1E);
    // 0x800ADFEC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800ADFF0: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800ADFF4: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
    // 0x800ADFF8: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x800ADFFC: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x800AE000: sh          $a3, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r7;
    // 0x800AE004: sh          $a3, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r7;
    // 0x800AE008: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x800AE00C: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // 0x800AE010: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x800AE014: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    // 0x800AE018: sh          $t4, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r12;
    // 0x800AE01C: sh          $t0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r8;
    // 0x800AE020: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x800AE024: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x800AE028: sh          $t1, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r9;
    // 0x800AE02C: sh          $a3, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r7;
    // 0x800AE030: sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
    // 0x800AE034: sb          $v0, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r2;
    // 0x800AE038: sb          $v0, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r2;
    // 0x800AE03C: sb          $v0, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = ctx->r2;
    // 0x800AE040: sh          $t4, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r12;
    // 0x800AE044: sh          $a1, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r5;
    // 0x800AE048: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x800AE04C: sh          $zero, 0x26($v1)
    MEM_H(0X26, ctx->r3) = 0;
    // 0x800AE050: sh          $t1, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r9;
    // 0x800AE054: sh          $t2, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r10;
    // 0x800AE058: sb          $v0, 0x2C($v1)
    MEM_B(0X2C, ctx->r3) = ctx->r2;
    // 0x800AE05C: sb          $v0, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = ctx->r2;
    // 0x800AE060: sb          $v0, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = ctx->r2;
    // 0x800AE064: sb          $v0, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = ctx->r2;
    // 0x800AE068: sh          $zero, 0x30($v1)
    MEM_H(0X30, ctx->r3) = 0;
    // 0x800AE06C: sh          $a1, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r5;
    // 0x800AE070: sh          $zero, 0x34($v1)
    MEM_H(0X34, ctx->r3) = 0;
    // 0x800AE074: sh          $zero, 0x36($v1)
    MEM_H(0X36, ctx->r3) = 0;
    // 0x800AE078: sh          $a3, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r7;
    // 0x800AE07C: sh          $t2, 0x3A($v1)
    MEM_H(0X3A, ctx->r3) = ctx->r10;
    // 0x800AE080: sb          $v0, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = ctx->r2;
    // 0x800AE084: sb          $v0, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = ctx->r2;
    // 0x800AE088: sb          $v0, 0x3E($v1)
    MEM_B(0X3E, ctx->r3) = ctx->r2;
    // 0x800AE08C: sb          $v0, 0x3F($v1)
    MEM_B(0X3F, ctx->r3) = ctx->r2;
    // 0x800AE090: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AE094: beq         $t3, $t5, L_800AE1FC
    if (ctx->r11 == ctx->r13) {
        // 0x800AE098: or          $a2, $t4, $zero
        ctx->r6 = ctx->r12 | 0;
            goto L_800AE1FC;
    }
    // 0x800AE098: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
L_800AE09C:
    // 0x800AE09C: addiu       $a1, $t0, 0x1E
    ctx->r5 = ADD32(ctx->r8, 0X1E);
L_800AE0A0:
    // 0x800AE0A0: addiu       $a0, $a2, 0x40
    ctx->r4 = ADD32(ctx->r6, 0X40);
    // 0x800AE0A4: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x800AE0A8: sh          $a2, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r6;
    // 0x800AE0AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800AE0B0: sh          $a0, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r4;
    // 0x800AE0B4: sh          $a0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r4;
    // 0x800AE0B8: sh          $a0, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r4;
    // 0x800AE0BC: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x800AE0C0: sh          $a2, 0x70($v1)
    MEM_H(0X70, ctx->r3) = ctx->r6;
    // 0x800AE0C4: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    // 0x800AE0C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800AE0CC: sh          $a0, 0x50($v1)
    MEM_H(0X50, ctx->r3) = ctx->r4;
    // 0x800AE0D0: sh          $a0, 0x60($v1)
    MEM_H(0X60, ctx->r3) = ctx->r4;
    // 0x800AE0D4: sh          $t0, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r8;
    // 0x800AE0D8: sh          $zero, 0x44($v1)
    MEM_H(0X44, ctx->r3) = 0;
    // 0x800AE0DC: sh          $zero, 0x46($v1)
    MEM_H(0X46, ctx->r3) = 0;
    // 0x800AE0E0: sh          $a3, 0x48($v1)
    MEM_H(0X48, ctx->r3) = ctx->r7;
    // 0x800AE0E4: sh          $a3, 0x4A($v1)
    MEM_H(0X4A, ctx->r3) = ctx->r7;
    // 0x800AE0E8: sb          $v0, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r2;
    // 0x800AE0EC: sb          $v0, 0x4D($v1)
    MEM_B(0X4D, ctx->r3) = ctx->r2;
    // 0x800AE0F0: sb          $v0, 0x4E($v1)
    MEM_B(0X4E, ctx->r3) = ctx->r2;
    // 0x800AE0F4: sb          $v0, 0x4F($v1)
    MEM_B(0X4F, ctx->r3) = ctx->r2;
    // 0x800AE0F8: sh          $t0, 0x52($v1)
    MEM_H(0X52, ctx->r3) = ctx->r8;
    // 0x800AE0FC: sh          $zero, 0x54($v1)
    MEM_H(0X54, ctx->r3) = 0;
    // 0x800AE100: sh          $zero, 0x56($v1)
    MEM_H(0X56, ctx->r3) = 0;
    // 0x800AE104: sh          $t1, 0x58($v1)
    MEM_H(0X58, ctx->r3) = ctx->r9;
    // 0x800AE108: sh          $a3, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = ctx->r7;
    // 0x800AE10C: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
    // 0x800AE110: sb          $v0, 0x5D($v1)
    MEM_B(0X5D, ctx->r3) = ctx->r2;
    // 0x800AE114: sb          $v0, 0x5E($v1)
    MEM_B(0X5E, ctx->r3) = ctx->r2;
    // 0x800AE118: sb          $v0, 0x5F($v1)
    MEM_B(0X5F, ctx->r3) = ctx->r2;
    // 0x800AE11C: sh          $a1, 0x62($v1)
    MEM_H(0X62, ctx->r3) = ctx->r5;
    // 0x800AE120: sh          $zero, 0x64($v1)
    MEM_H(0X64, ctx->r3) = 0;
    // 0x800AE124: sh          $zero, 0x66($v1)
    MEM_H(0X66, ctx->r3) = 0;
    // 0x800AE128: sh          $t1, 0x68($v1)
    MEM_H(0X68, ctx->r3) = ctx->r9;
    // 0x800AE12C: sh          $t2, 0x6A($v1)
    MEM_H(0X6A, ctx->r3) = ctx->r10;
    // 0x800AE130: sb          $v0, 0x6C($v1)
    MEM_B(0X6C, ctx->r3) = ctx->r2;
    // 0x800AE134: sb          $v0, 0x6D($v1)
    MEM_B(0X6D, ctx->r3) = ctx->r2;
    // 0x800AE138: sb          $v0, 0x6E($v1)
    MEM_B(0X6E, ctx->r3) = ctx->r2;
    // 0x800AE13C: sb          $v0, 0x6F($v1)
    MEM_B(0X6F, ctx->r3) = ctx->r2;
    // 0x800AE140: sh          $a1, 0x72($v1)
    MEM_H(0X72, ctx->r3) = ctx->r5;
    // 0x800AE144: sh          $zero, 0x74($v1)
    MEM_H(0X74, ctx->r3) = 0;
    // 0x800AE148: sh          $zero, 0x76($v1)
    MEM_H(0X76, ctx->r3) = 0;
    // 0x800AE14C: sh          $a3, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r7;
    // 0x800AE150: sh          $t2, 0x7A($v1)
    MEM_H(0X7A, ctx->r3) = ctx->r10;
    // 0x800AE154: sb          $v0, 0x7C($v1)
    MEM_B(0X7C, ctx->r3) = ctx->r2;
    // 0x800AE158: sb          $v0, 0x7D($v1)
    MEM_B(0X7D, ctx->r3) = ctx->r2;
    // 0x800AE15C: sb          $v0, 0x7E($v1)
    MEM_B(0X7E, ctx->r3) = ctx->r2;
    // 0x800AE160: sb          $v0, 0x7F($v1)
    MEM_B(0X7F, ctx->r3) = ctx->r2;
    // 0x800AE164: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800AE168: sh          $t0, -0x7E($v1)
    MEM_H(-0X7E, ctx->r3) = ctx->r8;
    // 0x800AE16C: sh          $zero, -0x7C($v1)
    MEM_H(-0X7C, ctx->r3) = 0;
    // 0x800AE170: sh          $zero, -0x7A($v1)
    MEM_H(-0X7A, ctx->r3) = 0;
    // 0x800AE174: sh          $a3, -0x78($v1)
    MEM_H(-0X78, ctx->r3) = ctx->r7;
    // 0x800AE178: sh          $a3, -0x76($v1)
    MEM_H(-0X76, ctx->r3) = ctx->r7;
    // 0x800AE17C: sb          $v0, -0x74($v1)
    MEM_B(-0X74, ctx->r3) = ctx->r2;
    // 0x800AE180: sb          $v0, -0x73($v1)
    MEM_B(-0X73, ctx->r3) = ctx->r2;
    // 0x800AE184: sb          $v0, -0x72($v1)
    MEM_B(-0X72, ctx->r3) = ctx->r2;
    // 0x800AE188: sb          $v0, -0x71($v1)
    MEM_B(-0X71, ctx->r3) = ctx->r2;
    // 0x800AE18C: sh          $t0, -0x6E($v1)
    MEM_H(-0X6E, ctx->r3) = ctx->r8;
    // 0x800AE190: sh          $zero, -0x6C($v1)
    MEM_H(-0X6C, ctx->r3) = 0;
    // 0x800AE194: sh          $zero, -0x6A($v1)
    MEM_H(-0X6A, ctx->r3) = 0;
    // 0x800AE198: sh          $t1, -0x68($v1)
    MEM_H(-0X68, ctx->r3) = ctx->r9;
    // 0x800AE19C: sh          $a3, -0x66($v1)
    MEM_H(-0X66, ctx->r3) = ctx->r7;
    // 0x800AE1A0: sb          $v0, -0x64($v1)
    MEM_B(-0X64, ctx->r3) = ctx->r2;
    // 0x800AE1A4: sb          $v0, -0x63($v1)
    MEM_B(-0X63, ctx->r3) = ctx->r2;
    // 0x800AE1A8: sb          $v0, -0x62($v1)
    MEM_B(-0X62, ctx->r3) = ctx->r2;
    // 0x800AE1AC: sb          $v0, -0x61($v1)
    MEM_B(-0X61, ctx->r3) = ctx->r2;
    // 0x800AE1B0: sh          $a1, -0x5E($v1)
    MEM_H(-0X5E, ctx->r3) = ctx->r5;
    // 0x800AE1B4: sh          $zero, -0x5C($v1)
    MEM_H(-0X5C, ctx->r3) = 0;
    // 0x800AE1B8: sh          $zero, -0x5A($v1)
    MEM_H(-0X5A, ctx->r3) = 0;
    // 0x800AE1BC: sh          $t1, -0x58($v1)
    MEM_H(-0X58, ctx->r3) = ctx->r9;
    // 0x800AE1C0: sh          $t2, -0x56($v1)
    MEM_H(-0X56, ctx->r3) = ctx->r10;
    // 0x800AE1C4: sb          $v0, -0x54($v1)
    MEM_B(-0X54, ctx->r3) = ctx->r2;
    // 0x800AE1C8: sb          $v0, -0x53($v1)
    MEM_B(-0X53, ctx->r3) = ctx->r2;
    // 0x800AE1CC: sb          $v0, -0x52($v1)
    MEM_B(-0X52, ctx->r3) = ctx->r2;
    // 0x800AE1D0: sb          $v0, -0x51($v1)
    MEM_B(-0X51, ctx->r3) = ctx->r2;
    // 0x800AE1D4: sh          $a1, -0x4E($v1)
    MEM_H(-0X4E, ctx->r3) = ctx->r5;
    // 0x800AE1D8: sh          $zero, -0x4C($v1)
    MEM_H(-0X4C, ctx->r3) = 0;
    // 0x800AE1DC: sh          $zero, -0x4A($v1)
    MEM_H(-0X4A, ctx->r3) = 0;
    // 0x800AE1E0: sh          $a3, -0x48($v1)
    MEM_H(-0X48, ctx->r3) = ctx->r7;
    // 0x800AE1E4: sh          $t2, -0x46($v1)
    MEM_H(-0X46, ctx->r3) = ctx->r10;
    // 0x800AE1E8: sb          $v0, -0x44($v1)
    MEM_B(-0X44, ctx->r3) = ctx->r2;
    // 0x800AE1EC: sb          $v0, -0x43($v1)
    MEM_B(-0X43, ctx->r3) = ctx->r2;
    // 0x800AE1F0: sb          $v0, -0x42($v1)
    MEM_B(-0X42, ctx->r3) = ctx->r2;
    // 0x800AE1F4: bne         $t3, $t5, L_800AE0A0
    if (ctx->r11 != ctx->r13) {
        // 0x800AE1F8: sb          $v0, -0x41($v1)
        MEM_B(-0X41, ctx->r3) = ctx->r2;
            goto L_800AE0A0;
    }
    // 0x800AE1F8: sb          $v0, -0x41($v1)
    MEM_B(-0X41, ctx->r3) = ctx->r2;
L_800AE1FC:
    // 0x800AE1FC: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800AE200: bne         $ra, $s0, L_800ADFD4
    if (ctx->r31 != ctx->r16) {
        // 0x800AE204: addiu       $t0, $t0, 0x1E
        ctx->r8 = ADD32(ctx->r8, 0X1E);
            goto L_800ADFD4;
    }
    // 0x800AE204: addiu       $t0, $t0, 0x1E
    ctx->r8 = ADD32(ctx->r8, 0X1E);
L_800AE208:
    // 0x800AE208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE20C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800AE210: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AE214: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AE218: jr          $ra
    // 0x800AE21C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800AE21C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void func_800AE220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE220: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800AE224: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800AE228: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800AE22C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800AE230: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800AE234: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800AE238: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800AE23C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800AE240: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800AE244: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800AE248: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800AE24C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800AE250: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x800AE254: addiu       $s0, $a1, 0x8
    ctx->r16 = ADD32(ctx->r5, 0X8);
    // 0x800AE258: lui         $t6, 0xD9F9
    ctx->r14 = S32(0XD9F9 << 16);
    // 0x800AE25C: ori         $t6, $t6, 0xF9FA
    ctx->r14 = ctx->r14 | 0XF9FA;
    // 0x800AE260: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800AE264: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800AE268: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800AE26C: lui         $t7, 0xDC08
    ctx->r15 = S32(0XDC08 << 16);
    // 0x800AE270: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x800AE274: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE278: addiu       $t8, $a0, 0x118
    ctx->r24 = ADD32(ctx->r4, 0X118);
    // 0x800AE27C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800AE280: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800AE284: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x800AE288: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE28C: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800AE290: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x800AE294: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x800AE298: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800AE29C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800AE2A0: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800AE2A4: ori         $t6, $t6, 0xC00
    ctx->r14 = ctx->r14 | 0XC00;
    // 0x800AE2A8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE2AC: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x800AE2B0: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x800AE2B4: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800AE2B8: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800AE2BC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE2C0: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800AE2C4: ori         $t8, $t8, 0x1201
    ctx->r24 = ctx->r24 | 0X1201;
    // 0x800AE2C8: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x800AE2CC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AE2D0: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800AE2D4: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x800AE2D8: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800AE2DC: ori         $t6, $t6, 0x1801
    ctx->r14 = ctx->r14 | 0X1801;
    // 0x800AE2E0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE2E4: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800AE2E8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800AE2EC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AE2F0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800AE2F4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800AE2F8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE2FC: lui         $t8, 0xF900
    ctx->r24 = S32(0XF900 << 16);
    // 0x800AE300: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800AE304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AE308: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800AE30C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE310: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800AE314: ori         $t9, $t9, 0x1E01
    ctx->r25 = ctx->r25 | 0X1E01;
    // 0x800AE318: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800AE31C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800AE320: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800AE324: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE328: lui         $t6, 0xF800
    ctx->r14 = S32(0XF800 << 16);
    // 0x800AE32C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800AE330: lui         $t8, 0xFC11
    ctx->r24 = S32(0XFC11 << 16);
    // 0x800AE334: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800AE338: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800AE33C: ori         $t8, $t8, 0x9623
    ctx->r24 = ctx->r24 | 0X9623;
    // 0x800AE340: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800AE344: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800AE348: lbu         $v1, 0x83($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X83);
    // 0x800AE34C: lui         $t9, 0xFF2F
    ctx->r25 = S32(0XFF2F << 16);
    // 0x800AE350: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800AE354: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800AE358: andi        $s1, $a3, 0xFF
    ctx->r17 = ctx->r7 & 0XFF;
    // 0x800AE35C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x800AE360: bne         $v1, $at, L_800AE38C
    if (ctx->r3 != ctx->r1) {
        // 0x800AE364: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_800AE38C;
    }
    // 0x800AE364: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE368: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AE36C: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x800AE370: lui         $t7, 0xF0A
    ctx->r15 = S32(0XF0A << 16);
    // 0x800AE374: ori         $t7, $t7, 0x4000
    ctx->r15 = ctx->r15 | 0X4000;
    // 0x800AE378: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x800AE37C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AE380: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800AE384: b           L_800AE3AC
    // 0x800AE388: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800AE3AC;
    // 0x800AE388: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800AE38C:
    // 0x800AE38C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AE390: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x800AE394: lui         $t9, 0x440
    ctx->r25 = S32(0X440 << 16);
    // 0x800AE398: ori         $t9, $t9, 0x4340
    ctx->r25 = ctx->r25 | 0X4340;
    // 0x800AE39C: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x800AE3A0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AE3A4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800AE3A8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800AE3AC:
    // 0x800AE3AC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AE3B0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800AE3B4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AE3B8: lbu         $t6, 0x7B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7B);
    // 0x800AE3BC: sll         $t8, $s1, 24
    ctx->r24 = S32(ctx->r17 << 24);
    // 0x800AE3C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AE3C4: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800AE3C8: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800AE3CC: lbu         $t8, 0x7F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X7F);
    // 0x800AE3D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AE3D4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800AE3D8: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x800AE3DC: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x800AE3E0: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800AE3E4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800AE3E8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800AE3EC: lw          $t9, 0x4($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X4);
    // 0x800AE3F0: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800AE3F4: lw          $t7, 0x10($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X10);
    // 0x800AE3F8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800AE3FC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800AE400: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AE404: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AE408: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800AE40C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AE410: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AE414: sll         $t6, $t7, 6
    ctx->r14 = S32(ctx->r15 << 6);
    // 0x800AE418: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AE41C: addu        $a0, $s4, $t6
    ctx->r4 = ADD32(ctx->r20, ctx->r14);
    // 0x800AE420: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800AE424: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE428: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    // 0x800AE42C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800AE430: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800AE434: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800AE438: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x800AE43C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800AE440: jal         0x800BB464
    // 0x800AE444: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    guOrtho(rdram, ctx);
        goto after_0;
    // 0x800AE444: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800AE448: jal         0x800AE70C
    // 0x800AE44C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800AE70C(rdram, ctx);
        goto after_1;
    // 0x800AE44C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x800AE450: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x800AE454: ori         $t7, $t7, 0x7
    ctx->r15 = ctx->r15 | 0X7;
    // 0x800AE458: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800AE45C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800AE460: lw          $t6, 0x10($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X10);
    // 0x800AE464: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE468: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800AE46C: sll         $t8, $t6, 6
    ctx->r24 = S32(ctx->r14 << 6);
    // 0x800AE470: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x800AE474: addiu       $t7, $t9, 0x98
    ctx->r15 = ADD32(ctx->r25, 0X98);
    // 0x800AE478: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x800AE47C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800AE480: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x800AE484: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800AE488: lw          $t8, 0x10($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X10);
    // 0x800AE48C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE490: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AE494: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800AE498: addu        $t7, $s4, $t9
    ctx->r15 = ADD32(ctx->r20, ctx->r25);
    // 0x800AE49C: addiu       $t6, $t7, 0x18
    ctx->r14 = ADD32(ctx->r15, 0X18);
    // 0x800AE4A0: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800AE4A4: lw          $v0, 0xC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XC);
    // 0x800AE4A8: lw          $t5, 0x14($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X14);
    // 0x800AE4AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AE4B0: blez        $v0, L_800AE694
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AE4B4: lui         $fp, 0xF400
        ctx->r30 = S32(0XF400 << 16);
            goto L_800AE694;
    }
    // 0x800AE4B4: lui         $fp, 0xF400
    ctx->r30 = S32(0XF400 << 16);
    // 0x800AE4B8: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x800AE4BC: lui         $s7, 0xE600
    ctx->r23 = S32(0XE600 << 16);
    // 0x800AE4C0: lui         $s6, 0xF510
    ctx->r22 = S32(0XF510 << 16);
    // 0x800AE4C4: lui         $s5, 0xFD10
    ctx->r21 = S32(0XFD10 << 16);
    // 0x800AE4C8: lui         $s2, 0xF200
    ctx->r18 = S32(0XF200 << 16);
    // 0x800AE4CC: lui         $s1, 0xE700
    ctx->r17 = S32(0XE700 << 16);
    // 0x800AE4D0: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
L_800AE4D4:
    // 0x800AE4D4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800AE4D8: blez        $v1, L_800AE684
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800AE4DC: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_800AE684;
    }
    // 0x800AE4DC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800AE4E0: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x800AE4E4: addiu       $t3, $a2, 0x1D
    ctx->r11 = ADD32(ctx->r6, 0X1D);
    // 0x800AE4E8: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x800AE4EC: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x800AE4F0: or          $t2, $t8, $zero
    ctx->r10 = ctx->r24 | 0;
    // 0x800AE4F4: andi        $t3, $t9, 0xFFF
    ctx->r11 = ctx->r25 & 0XFFF;
    // 0x800AE4F8: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800AE4FC: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // 0x800AE500: addiu       $s3, $zero, 0x87
    ctx->r19 = ADD32(0, 0X87);
L_800AE504:
    // 0x800AE504: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800AE508: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AE50C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE510: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x800AE514: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800AE518: or          $t7, $t9, $s5
    ctx->r15 = ctx->r25 | ctx->r21;
    // 0x800AE51C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AE520: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800AE524: sra         $t8, $s3, 3
    ctx->r24 = S32(SIGNED(ctx->r19) >> 3);
    // 0x800AE528: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800AE52C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800AE530: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800AE534: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x800AE538: andi        $t6, $t0, 0xFFF
    ctx->r14 = ctx->r8 & 0XFFF;
    // 0x800AE53C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE540: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x800AE544: or          $a2, $t7, $s6
    ctx->r6 = ctx->r15 | ctx->r22;
    // 0x800AE548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AE54C: sll         $t0, $t6, 12
    ctx->r8 = S32(ctx->r14 << 12);
    // 0x800AE550: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800AE554: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x800AE558: addiu       $v0, $t1, 0x3F
    ctx->r2 = ADD32(ctx->r9, 0X3F);
    // 0x800AE55C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800AE560: or          $t9, $t0, $fp
    ctx->r25 = ctx->r8 | ctx->r30;
    // 0x800AE564: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE568: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800AE56C: or          $t7, $t9, $t2
    ctx->r15 = ctx->r25 | ctx->r10;
    // 0x800AE570: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800AE574: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800AE578: sw          $s7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r23;
    // 0x800AE57C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800AE580: sll         $v0, $t8, 12
    ctx->r2 = S32(ctx->r24 << 12);
    // 0x800AE584: or          $t7, $v0, $ra
    ctx->r15 = ctx->r2 | ctx->r31;
    // 0x800AE588: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x800AE58C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE590: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800AE594: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800AE598: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE59C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AE5A0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE5A4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800AE5A8: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    // 0x800AE5AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800AE5B0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800AE5B4: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800AE5B8: or          $t7, $v0, $t3
    ctx->r15 = ctx->r2 | ctx->r11;
    // 0x800AE5BC: or          $t8, $t0, $s2
    ctx->r24 = ctx->r8 | ctx->r18;
    // 0x800AE5C0: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x800AE5C4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE5C8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800AE5CC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800AE5D0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AE5D4: lui         $t6, 0x80
    ctx->r14 = S32(0X80 << 16);
    // 0x800AE5D8: ori         $t6, $t6, 0x3C0
    ctx->r14 = ctx->r14 | 0X3C0;
    // 0x800AE5DC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800AE5E0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE5E4: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x800AE5E8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800AE5EC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE5F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AE5F4: lui         $t8, 0xD700
    ctx->r24 = S32(0XD700 << 16);
    // 0x800AE5F8: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    // 0x800AE5FC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800AE600: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x800AE604: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE608: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800AE60C: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x800AE610: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800AE614: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800AE618: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800AE61C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE620: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x800AE624: ori         $t7, $t7, 0x4008
    ctx->r15 = ctx->r15 | 0X4008;
    // 0x800AE628: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800AE62C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800AE630: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x800AE634: lui         $t6, 0x500
    ctx->r14 = S32(0X500 << 16);
    // 0x800AE638: ori         $t6, $t6, 0x204
    ctx->r14 = ctx->r14 | 0X204;
    // 0x800AE63C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE640: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800AE644: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800AE648: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AE64C: lui         $t8, 0x500
    ctx->r24 = S32(0X500 << 16);
    // 0x800AE650: ori         $t8, $t8, 0x406
    ctx->r24 = ctx->r24 | 0X406;
    // 0x800AE654: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AE658: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AE65C: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x800AE660: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800AE664: addiu       $t5, $t5, 0x40
    ctx->r13 = ADD32(ctx->r13, 0X40);
    // 0x800AE668: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AE66C: addiu       $t1, $t1, 0x40
    ctx->r9 = ADD32(ctx->r9, 0X40);
    // 0x800AE670: bne         $at, $zero, L_800AE504
    if (ctx->r1 != 0) {
        // 0x800AE674: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_800AE504;
    }
    // 0x800AE674: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800AE678: lw          $v0, 0xC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XC);
    // 0x800AE67C: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800AE680: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_800AE684:
    // 0x800AE684: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AE688: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800AE68C: bne         $at, $zero, L_800AE4D4
    if (ctx->r1 != 0) {
        // 0x800AE690: addiu       $a2, $a2, 0x1E
        ctx->r6 = ADD32(ctx->r6, 0X1E);
            goto L_800AE4D4;
    }
    // 0x800AE690: addiu       $a2, $a2, 0x1E
    ctx->r6 = ADD32(ctx->r6, 0X1E);
L_800AE694:
    // 0x800AE694: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800AE698: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AE69C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AE6A0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800AE6A4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800AE6A8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800AE6AC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800AE6B0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE6B4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800AE6B8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800AE6BC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800AE6C0: jr          $ra
    // 0x800AE6C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800AE6C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}

RECOMP_FUNC void func_800AE6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE6C8: lw          $at, 0x0($a1)
    ctx->r1 = MEM_W(ctx->r5, 0X0);
    // 0x800AE6CC: sw          $at, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->r1;
    // 0x800AE6D0: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x800AE6D4: sw          $t8, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r24;
    // 0x800AE6D8: lw          $at, 0x8($a1)
    ctx->r1 = MEM_W(ctx->r5, 0X8);
    // 0x800AE6DC: jr          $ra
    // 0x800AE6E0: sw          $at, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r1;
    return;
    // 0x800AE6E0: sw          $at, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r1;
;}

RECOMP_FUNC void func_800AE6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE6E4: lw          $at, 0x0($a1)
    ctx->r1 = MEM_W(ctx->r5, 0X0);
    // 0x800AE6E8: sw          $at, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r1;
    // 0x800AE6EC: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x800AE6F0: sw          $t8, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r24;
    // 0x800AE6F4: lw          $at, 0x8($a1)
    ctx->r1 = MEM_W(ctx->r5, 0X8);
    // 0x800AE6F8: jr          $ra
    // 0x800AE6FC: sw          $at, 0x13C($a0)
    MEM_W(0X13C, ctx->r4) = ctx->r1;
    return;
    // 0x800AE6FC: sw          $at, 0x13C($a0)
    MEM_W(0X13C, ctx->r4) = ctx->r1;
;}

RECOMP_FUNC void func_800AE700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE700: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800AE704: jr          $ra
    // 0x800AE708: swc1        $f12, 0x140($a0)
    MEM_W(0X140, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x800AE708: swc1        $f12, 0x140($a0)
    MEM_W(0X140, ctx->r4) = ctx->f12.u32l;
;}

RECOMP_FUNC void func_800AE70C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE70C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800AE710: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AE714: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AE718: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AE71C: jal         0x800B81D0
    // 0x800AE720: lwc1        $f12, 0x140($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X140);
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x800AE720: lwc1        $f12, 0x140($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X140);
    after_0:
    // 0x800AE724: lwc1        $f12, 0x140($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X140);
    // 0x800AE728: jal         0x800B7B40
    // 0x800AE72C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800AE72C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800AE730: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800AE734: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800AE738: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800AE73C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800AE740: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800AE744: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AE748: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AE74C: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800AE750: lwc1        $f2, 0x134($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800AE754: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800AE758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AE75C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AE760: mul.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AE764: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AE768: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800AE76C: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AE770: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800AE774: mul.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800AE778: nop

    // 0x800AE77C: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800AE780: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x800AE784: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x800AE788: lwc1        $f12, 0x138($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800AE78C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x800AE790: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800AE794: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800AE798: nop

    // 0x800AE79C: mul.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800AE7A0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x800AE7A4: jal         0x800A8FC8
    // 0x800AE7A8: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    func_800A8FC8(rdram, ctx);
        goto after_2;
    // 0x800AE7A8: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x800AE7AC: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800AE7B0: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AE7B4: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800AE7B8: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x800AE7BC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800AE7C0: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800AE7C4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800AE7C8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800AE7CC: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AE7D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AE7D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800AE7D8: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800AE7DC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800AE7E0: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x800AE7E4: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x800AE7E8: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800AE7EC: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x800AE7F0: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    // 0x800AE7F4: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x800AE7F8: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800AE7FC: lwc1        $f8, 0x128($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X128);
    // 0x800AE800: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AE804: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800AE808: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AE80C: add.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800AE810: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800AE814: sub.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f8.d - ctx->f0.d;
    // 0x800AE818: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x800AE81C: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800AE820: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800AE824: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x800AE828: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AE82C: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AE830: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800AE834: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AE838: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800AE83C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800AE840: sub.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f8.d - ctx->f0.d;
    // 0x800AE844: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800AE848: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x800AE84C: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x800AE850: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800AE854: addu        $a1, $s0, $t9
    ctx->r5 = ADD32(ctx->r16, ctx->r25);
    // 0x800AE858: jal         0x800B78D0
    // 0x800AE85C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    guMtxF2L(rdram, ctx);
        goto after_3;
    // 0x800AE85C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_3:
    // 0x800AE860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE864: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AE868: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x800AE86C: jr          $ra
    // 0x800AE870: nop

    return;
    // 0x800AE870: nop

    // 0x800AE874: nop

    // 0x800AE878: nop

    // 0x800AE87C: nop

;}

RECOMP_FUNC void func_800AE880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE880: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AE884: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800AE888: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AE88C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800AE890: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800AE894: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AE898: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800AE89C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800AE8A0: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800AE8A4: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AE8A8: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AE8AC: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800AE8B0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AE8B4: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800AE8B8: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AE8BC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800AE8C0: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AE8C4: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800AE8C8: nop

    // 0x800AE8CC: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800AE8D0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AE8D4: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800AE8D8: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800AE8DC: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AE8E0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800AE8E4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AE8E8: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AE8EC: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800AE8F0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800AE8F4: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800AE8F8: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800AE8FC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800AE900: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800AE904: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800AE908: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800AE90C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800AE910: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800AE914: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800AE918: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AE91C: add.s       $f20, $f8, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AE920: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800AE924: div.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x800AE928: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AE92C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800AE930: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x800AE934: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x800AE938: div.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x800AE93C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AE940: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800AE944: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AE948: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x800AE94C: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x800AE950: div.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x800AE954: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800AE958: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x800AE95C: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800AE960: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
    // 0x800AE964: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800AE968: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x800AE96C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800AE970: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800AE974: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AE978: swc1        $f10, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f10.u32l;
    // 0x800AE97C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AE980: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800AE984: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x800AE988: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AE98C: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800AE990: swc1        $f10, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f10.u32l;
    // 0x800AE994: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AE998: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800AE99C: swc1        $f4, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f4.u32l;
    // 0x800AE9A0: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AE9A4: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800AE9A8: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    // 0x800AE9AC: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800AE9B0: mul.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AE9B4: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AE9B8: swc1        $f4, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f4.u32l;
    // 0x800AE9BC: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800AE9C0: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x800AE9C4: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AE9C8: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800AE9CC: swc1        $f10, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f10.u32l;
    // 0x800AE9D0: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800AE9D4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AE9D8: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800AE9DC: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800AE9E0: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AE9E4: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800AE9E8: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800AE9EC: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AE9F0: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AE9F4: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800AE9F8: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x800AE9FC: swc1        $f4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f4.u32l;
    // 0x800AEA00: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800AEA04: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AEA08: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AEA0C: lwc1        $f8, 0x34($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800AEA10: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800AEA14: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AEA18: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AEA1C: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800AEA20: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800AEA24: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AEA28: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800AEA2C: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x800AEA30: swc1        $f8, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f8.u32l;
    // 0x800AEA34: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800AEA38: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AEA3C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AEA40: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800AEA44: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AEA48: lwc1        $f10, 0x28($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AEA4C: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800AEA50: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800AEA54: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x800AEA58: swc1        $f0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f0.u32l;
    // 0x800AEA5C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800AEA60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AEA64: swc1        $f0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f0.u32l;
    // 0x800AEA68: swc1        $f8, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f8.u32l;
    // 0x800AEA6C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AEA70: swc1        $f10, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f10.u32l;
    // 0x800AEA74: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800AEA78: jr          $ra
    // 0x800AEA7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AEA7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void func_800AEA80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEA80: beq         $a1, $zero, L_800AEAA0
    if (ctx->r5 == 0) {
        // 0x800AEA84: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800AEAA0;
    }
    // 0x800AEA84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AEA88: beq         $a1, $v0, L_800AEB2C
    if (ctx->r5 == ctx->r2) {
        // 0x800AEA8C: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_800AEB2C;
    }
    // 0x800AEA8C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800AEA90: beq         $a1, $v1, L_800AEBC4
    if (ctx->r5 == ctx->r3) {
        // 0x800AEA94: nop
    
            goto L_800AEBC4;
    }
    // 0x800AEA94: nop

    // 0x800AEA98: jr          $ra
    // 0x800AEA9C: nop

    return;
    // 0x800AEA9C: nop

L_800AEAA0:
    // 0x800AEAA0: beq         $a2, $zero, L_800AEAC0
    if (ctx->r6 == 0) {
        // 0x800AEAA4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800AEAC0;
    }
    // 0x800AEAA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AEAA8: beq         $a2, $v0, L_800AEAE4
    if (ctx->r6 == ctx->r2) {
        // 0x800AEAAC: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_800AEAE4;
    }
    // 0x800AEAAC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800AEAB0: beql        $a2, $v1, L_800AEB0C
    if (ctx->r6 == ctx->r3) {
        // 0x800AEAB4: lwc1        $f4, 0xC($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
            goto L_800AEB0C;
    }
    goto skip_0;
    // 0x800AEAB4: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    skip_0:
    // 0x800AEAB8: b           L_800AEB2C
    // 0x800AEABC: nop

        goto L_800AEB2C;
    // 0x800AEABC: nop

L_800AEAC0:
    // 0x800AEAC0: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AEAC4: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AEAC8: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AEACC: lwc1        $f16, 0x1C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800AEAD0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AEAD4: nop

    // 0x800AEAD8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AEADC: jr          $ra
    // 0x800AEAE0: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
    return;
    // 0x800AEAE0: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
L_800AEAE4:
    // 0x800AEAE4: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AEAE8: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AEAEC: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800AEAF0: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AEAF4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AEAF8: nop

    // 0x800AEAFC: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800AEB00: jr          $ra
    // 0x800AEB04: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    return;
    // 0x800AEB04: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AEB08: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
L_800AEB0C:
    // 0x800AEB0C: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800AEB10: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AEB14: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AEB18: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AEB1C: nop

    // 0x800AEB20: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AEB24: jr          $ra
    // 0x800AEB28: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    return;
    // 0x800AEB28: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
L_800AEB2C:
    // 0x800AEB2C: beq         $a2, $zero, L_800AEB4C
    if (ctx->r6 == 0) {
        // 0x800AEB30: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_800AEB4C;
    }
    // 0x800AEB30: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800AEB34: beql        $a2, $v0, L_800AEB78
    if (ctx->r6 == ctx->r2) {
        // 0x800AEB38: lwc1        $f6, 0x8($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
            goto L_800AEB78;
    }
    goto skip_1;
    // 0x800AEB38: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x800AEB3C: beql        $a2, $v1, L_800AEBA0
    if (ctx->r6 == ctx->r3) {
        // 0x800AEB40: lwc1        $f8, 0x0($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800AEBA0;
    }
    goto skip_2;
    // 0x800AEB40: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x800AEB44: b           L_800AEBC4
    // 0x800AEB48: nop

        goto L_800AEBC4;
    // 0x800AEB48: nop

L_800AEB4C:
    // 0x800AEB4C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800AEB50: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AEB54: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800AEB58: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800AEB5C: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800AEB60: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AEB64: nop

    // 0x800AEB68: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AEB6C: jr          $ra
    // 0x800AEB70: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    return;
    // 0x800AEB70: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800AEB74: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
L_800AEB78:
    // 0x800AEB78: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AEB7C: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AEB80: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800AEB84: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AEB88: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AEB8C: nop

    // 0x800AEB90: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AEB94: jr          $ra
    // 0x800AEB98: add.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f6.fl;
    return;
    // 0x800AEB98: add.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800AEB9C: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
L_800AEBA0:
    // 0x800AEBA0: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800AEBA4: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800AEBA8: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x800AEBAC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AEBB0: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AEBB4: nop

    // 0x800AEBB8: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AEBBC: jr          $ra
    // 0x800AEBC0: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    return;
    // 0x800AEBC0: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
L_800AEBC4:
    // 0x800AEBC4: beql        $a2, $zero, L_800AEBE8
    if (ctx->r6 == 0) {
        // 0x800AEBC8: lwc1        $f16, 0x4($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
            goto L_800AEBE8;
    }
    goto skip_3;
    // 0x800AEBC8: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    skip_3:
    // 0x800AEBCC: beql        $a2, $v0, L_800AEC0C
    if (ctx->r6 == ctx->r2) {
        // 0x800AEBD0: lwc1        $f16, 0x8($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
            goto L_800AEC0C;
    }
    goto skip_4;
    // 0x800AEBD0: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    skip_4:
    // 0x800AEBD4: beql        $a2, $v1, L_800AEC30
    if (ctx->r6 == ctx->r3) {
        // 0x800AEBD8: lwc1        $f16, 0x0($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800AEC30;
    }
    goto skip_5;
    // 0x800AEBD8: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    skip_5:
    // 0x800AEBDC: jr          $ra
    // 0x800AEBE0: nop

    return;
    // 0x800AEBE0: nop

    // 0x800AEBE4: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
L_800AEBE8:
    // 0x800AEBE8: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AEBEC: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800AEBF0: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AEBF4: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AEBF8: nop

    // 0x800AEBFC: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AEC00: jr          $ra
    // 0x800AEC04: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    return;
    // 0x800AEC04: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800AEC08: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
L_800AEC0C:
    // 0x800AEC0C: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800AEC10: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AEC14: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AEC18: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AEC1C: nop

    // 0x800AEC20: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AEC24: jr          $ra
    // 0x800AEC28: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    return;
    // 0x800AEC28: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800AEC2C: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
L_800AEC30:
    // 0x800AEC30: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AEC34: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800AEC38: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800AEC3C: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AEC40: nop

    // 0x800AEC44: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AEC48: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800AEC4C: jr          $ra
    // 0x800AEC50: nop

    return;
    // 0x800AEC50: nop

;}

RECOMP_FUNC void func_800AEC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEC54: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AEC58: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AEC5C: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800AEC60: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AEC64: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800AEC68: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800AEC6C: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800AEC70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AEC74: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800AEC78: mul.s       $f2, $f4, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800AEC7C: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AEC80: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800AEC84: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x800AEC88: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800AEC8C: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AEC90: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800AEC94: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x800AEC98: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800AEC9C: nop

    // 0x800AECA0: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AECA4: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800AECA8: swc1        $f8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f8.u32l;
    // 0x800AECAC: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800AECB0: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800AECB4: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AECB8: nop

    // 0x800AECBC: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800AECC0: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800AECC4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800AECC8: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800AECCC: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800AECD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AECD4: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AECD8: nop

    // 0x800AECDC: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800AECE0: nop

    // 0x800AECE4: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800AECE8: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800AECEC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AECF0: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800AECF4: jr          $ra
    // 0x800AECF8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800AECF8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}

RECOMP_FUNC void func_800AECFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AECFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AED00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AED04: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800AED08: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800AED0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AED10: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800AED14: jal         0x800AEC54
    // 0x800AED18: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800AEC54(rdram, ctx);
        goto after_0;
    // 0x800AED18: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x800AED1C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800AED20: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800AED24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED28: ldc1        $f4, 0x12B8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X12B8);
    // 0x800AED2C: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x800AED30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AED34: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x800AED38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AED3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AED40: bc1tl       L_800AEE38
    if (c1cs) {
        // 0x800AED44: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800AEE38;
    }
    goto skip_0;
    // 0x800AED44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800AED48: jal         0x800AEA80
    // 0x800AED4C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_800AEA80(rdram, ctx);
        goto after_1;
    // 0x800AED4C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x800AED50: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AED54: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800AED58: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800AED5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AED60: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800AED64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AED68: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x800AED6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AED70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AED74: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x800AED78: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AED7C: jal         0x800AEA80
    // 0x800AED80: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    func_800AEA80(rdram, ctx);
        goto after_2;
    // 0x800AED80: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    after_2:
    // 0x800AED84: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AED88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AED8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AED90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AED94: jal         0x800AEA80
    // 0x800AED98: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    func_800AEA80(rdram, ctx);
        goto after_3;
    // 0x800AED98: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    after_3:
    // 0x800AED9C: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEDA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AEDA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AEDAC: jal         0x800AEA80
    // 0x800AEDB0: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    func_800AEA80(rdram, ctx);
        goto after_4;
    // 0x800AEDB0: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    after_4:
    // 0x800AEDB4: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEDB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEDBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AEDC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AEDC4: jal         0x800AEA80
    // 0x800AEDC8: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    func_800AEA80(rdram, ctx);
        goto after_5;
    // 0x800AEDC8: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    after_5:
    // 0x800AEDCC: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEDD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEDD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AEDD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AEDDC: jal         0x800AEA80
    // 0x800AEDE0: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
    func_800AEA80(rdram, ctx);
        goto after_6;
    // 0x800AEDE0: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
    after_6:
    // 0x800AEDE4: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEDE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEDEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AEDF0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800AEDF4: jal         0x800AEA80
    // 0x800AEDF8: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    func_800AEA80(rdram, ctx);
        goto after_7;
    // 0x800AEDF8: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    after_7:
    // 0x800AEDFC: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEE00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEE04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AEE08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800AEE0C: jal         0x800AEA80
    // 0x800AEE10: swc1        $f16, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f16.u32l;
    func_800AEA80(rdram, ctx);
        goto after_8;
    // 0x800AEE10: swc1        $f16, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f16.u32l;
    after_8:
    // 0x800AEE14: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEE18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AEE1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AEE20: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800AEE24: jal         0x800AEA80
    // 0x800AEE28: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    func_800AEA80(rdram, ctx);
        goto after_9;
    // 0x800AEE28: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    after_9:
    // 0x800AEE2C: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800AEE30: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x800AEE34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800AEE38:
    // 0x800AEE38: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800AEE3C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEE40: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800AEE44: jr          $ra
    // 0x800AEE48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AEE48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void func_800AEE4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEE4C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AEE50: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AEE54: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AEE58: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AEE5C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AEE60: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AEE64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AEE68: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AEE6C: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AEE70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AEE74: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AEE78: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AEE7C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AEE80: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800AEE84: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AEE88: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AEE8C: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AEE90: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AEE94: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AEE98: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AEE9C: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AEEA0: lwc1        $f4, 0x18($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AEEA4: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AEEA8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AEEAC: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AEEB0: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800AEEB4: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AEEB8: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AEEBC: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AEEC0: lwc1        $f18, 0x10($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AEEC4: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AEEC8: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AEECC: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AEED0: lwc1        $f18, 0x28($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AEED4: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AEED8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AEEDC: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AEEE0: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800AEEE4: lwc1        $f6, 0x30($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AEEE8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AEEEC: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AEEF0: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AEEF4: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AEEF8: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AEEFC: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AEF00: lwc1        $f8, 0x38($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AEF04: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AEF08: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AEF0C: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800AEF10: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AEF14: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AEF18: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x800AEF1C: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AEF20: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AEF24: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AEF28: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AEF2C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AEF30: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AEF34: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AEF38: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AEF3C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800AEF40: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800AEF44: add.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AEF48: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x800AEF4C: lwc1        $f10, 0x10($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AEF50: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AEF54: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AEF58: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AEF5C: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AEF60: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AEF64: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800AEF68: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AEF6C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800AEF70: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AEF74: add.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AEF78: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800AEF7C: lwc1        $f10, 0x20($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AEF80: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AEF84: lwc1        $f4, 0x24($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AEF88: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AEF8C: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AEF90: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AEF94: mul.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AEF98: lwc1        $f6, 0x28($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AEF9C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AEFA0: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AEFA4: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800AEFA8: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x800AEFAC: lwc1        $f10, 0x30($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AEFB0: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AEFB4: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AEFB8: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AEFBC: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800AEFC0: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AEFC4: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AEFC8: lwc1        $f16, 0x38($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AEFCC: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AEFD0: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AEFD4: lwc1        $f8, 0x34($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800AEFD8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AEFDC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AEFE0: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
    // 0x800AEFE4: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AEFE8: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AEFEC: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AEFF0: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AEFF4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AEFF8: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AEFFC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AF000: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF004: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF008: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AF00C: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800AF010: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800AF014: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF018: lwc1        $f18, 0x10($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF01C: lwc1        $f16, 0x18($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF020: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF024: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800AF028: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF02C: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800AF030: lwc1        $f16, 0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF034: mul.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF038: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AF03C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF040: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x800AF044: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF048: lwc1        $f18, 0x20($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF04C: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF050: lwc1        $f8, 0x24($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF054: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AF058: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF05C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800AF060: lwc1        $f10, 0x28($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF064: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800AF068: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800AF06C: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AF070: swc1        $f16, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f16.u32l;
    // 0x800AF074: lwc1        $f18, 0x30($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AF078: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF07C: lwc1        $f8, 0x34($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AF080: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF084: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AF088: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF08C: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800AF090: lwc1        $f4, 0x38($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AF094: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AF098: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AF09C: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF0A0: lwc1        $f16, 0x38($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800AF0A4: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800AF0A8: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x800AF0AC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AF0B0: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x800AF0B4: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x800AF0B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF0BC: jr          $ra
    // 0x800AF0C0: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800AF0C0: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
;}

RECOMP_FUNC void func_800AF0C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF0C4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF0C8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF0CC: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF0D0: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF0D4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF0D8: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF0DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AF0E0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF0E4: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF0E8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF0EC: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF0F0: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AF0F4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800AF0F8: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF0FC: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF100: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF104: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF108: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF10C: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF110: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AF114: lwc1        $f4, 0x18($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF118: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AF11C: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF120: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AF124: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800AF128: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF12C: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF130: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF134: lwc1        $f18, 0x10($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF138: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AF13C: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF140: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF144: lwc1        $f18, 0x28($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF148: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AF14C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AF150: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AF154: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800AF158: lwc1        $f6, 0x30($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AF15C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF160: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800AF164: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF168: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AF16C: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AF170: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AF174: lwc1        $f18, 0x1C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800AF178: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AF17C: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF180: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AF184: lwc1        $f6, 0x38($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AF188: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AF18C: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800AF190: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800AF194: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AF198: mul.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF19C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AF1A0: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800AF1A4: swc1        $f18, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f18.u32l;
    // 0x800AF1A8: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF1AC: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF1B0: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF1B4: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF1B8: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AF1BC: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF1C0: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AF1C4: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF1C8: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AF1CC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF1D0: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800AF1D4: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800AF1D8: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF1DC: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF1E0: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF1E4: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF1E8: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AF1EC: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF1F0: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AF1F4: lwc1        $f16, 0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF1F8: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AF1FC: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF200: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800AF204: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800AF208: lwc1        $f4, 0x20($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF20C: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF210: lwc1        $f6, 0x24($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF214: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF218: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800AF21C: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF220: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF224: lwc1        $f18, 0x28($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF228: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AF22C: add.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800AF230: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AF234: swc1        $f16, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f16.u32l;
    // 0x800AF238: lwc1        $f4, 0x30($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AF23C: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF240: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800AF244: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF248: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AF24C: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AF250: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AF254: lwc1        $f18, 0x1C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800AF258: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AF25C: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF260: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AF264: lwc1        $f4, 0x38($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AF268: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AF26C: lwc1        $f4, 0x34($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800AF270: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AF274: lwc1        $f6, 0x2C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AF278: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF27C: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800AF280: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800AF284: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x800AF288: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF28C: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF290: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF294: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF298: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800AF29C: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF2A0: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AF2A4: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF2A8: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AF2AC: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF2B0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AF2B4: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x800AF2B8: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF2BC: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF2C0: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF2C4: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF2C8: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF2CC: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF2D0: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AF2D4: lwc1        $f6, 0x18($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF2D8: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AF2DC: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF2E0: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AF2E4: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x800AF2E8: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF2EC: lwc1        $f16, 0x20($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF2F0: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF2F4: lwc1        $f4, 0x24($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF2F8: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AF2FC: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF300: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AF304: lwc1        $f18, 0x28($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF308: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AF30C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800AF310: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AF314: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x800AF318: lwc1        $f16, 0x30($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800AF31C: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF320: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800AF324: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF328: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF32C: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800AF330: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AF334: lwc1        $f18, 0x1C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800AF338: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF33C: lwc1        $f10, 0x28($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF340: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AF344: lwc1        $f16, 0x38($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800AF348: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF34C: lwc1        $f16, 0x38($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800AF350: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AF354: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AF358: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AF35C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AF360: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF364: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
    // 0x800AF368: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800AF36C: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800AF370: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF374: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x800AF378: lwc1        $f16, 0x1C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x800AF37C: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800AF380: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF384: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AF388: swc1        $f18, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f18.u32l;
    // 0x800AF38C: lwc1        $f6, 0x2C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x800AF390: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AF394: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x800AF398: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF39C: jr          $ra
    // 0x800AF3A0: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800AF3A0: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
;}

RECOMP_FUNC void func_800AF3A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF3A4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF3A8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF3AC: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF3B0: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF3B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF3B8: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF3BC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF3C0: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF3C4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF3C8: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF3CC: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AF3D0: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800AF3D4: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF3D8: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF3DC: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF3E0: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF3E4: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF3E8: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF3EC: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AF3F0: lwc1        $f4, 0x18($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF3F4: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AF3F8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF3FC: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AF400: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800AF404: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF408: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AF40C: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF410: lwc1        $f18, 0x10($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800AF414: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AF418: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800AF41C: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF420: lwc1        $f18, 0x28($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF424: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AF428: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AF42C: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AF430: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800AF434: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF438: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF43C: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF440: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF444: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AF448: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF44C: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AF450: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF454: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AF458: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AF45C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF460: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800AF464: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF468: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF46C: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF470: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF474: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF478: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF47C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF480: lwc1        $f10, 0x18($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF484: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF488: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF48C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AF490: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x800AF494: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF498: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AF49C: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF4A0: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800AF4A4: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800AF4A8: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AF4AC: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AF4B0: lwc1        $f4, 0x28($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF4B4: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AF4B8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AF4BC: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AF4C0: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x800AF4C4: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF4C8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800AF4CC: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF4D0: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800AF4D4: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AF4D8: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF4DC: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800AF4E0: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800AF4E4: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800AF4E8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AF4EC: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AF4F0: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800AF4F4: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF4F8: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800AF4FC: lwc1        $f8, 0x18($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF500: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800AF504: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AF508: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF50C: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800AF510: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800AF514: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AF518: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AF51C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AF520: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800AF524: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800AF528: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AF52C: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800AF530: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800AF534: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF538: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AF53C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AF540: lwc1        $f10, 0x28($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800AF544: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AF548: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800AF54C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800AF550: jr          $ra
    // 0x800AF554: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800AF554: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
;}

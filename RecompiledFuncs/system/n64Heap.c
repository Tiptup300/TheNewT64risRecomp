#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void n64HeapInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DFC0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007DFC4: addiu       $a2, $a2, 0xF
    ctx->r6 = ADD32(ctx->r6, 0XF);
    // 0x8007DFC8: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8007DFCC: and         $t6, $a2, $at
    ctx->r14 = ctx->r6 & ctx->r1;
    // 0x8007DFD0: addiu       $a1, $a1, 0xF
    ctx->r5 = ADD32(ctx->r5, 0XF);
    // 0x8007DFD4: and         $t7, $a1, $at
    ctx->r15 = ctx->r5 & ctx->r1;
    // 0x8007DFD8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007DFDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DFE0: sw          $a2, 0x3190($at)
    MEM_W(0X3190, ctx->r1) = ctx->r6;
    // 0x8007DFE4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8007DFE8: lw          $t8, 0x3190($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3190);
    // 0x8007DFEC: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8007DFF0: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8007DFF4: lw          $t0, 0x3190($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3190);
    // 0x8007DFF8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8007DFFC: addiu       $t9, $a1, -0x10
    ctx->r25 = ADD32(ctx->r5, -0X10);
    // 0x8007E000: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007E004: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8007E008: lw          $t1, 0x3190($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3190);
    // 0x8007E00C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8007E010: sw          $zero, 0x8($t1)
    MEM_W(0X8, ctx->r9) = 0;
    // 0x8007E014: lw          $t2, 0x3190($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3190);
    // 0x8007E018: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007E01C: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
    // 0x8007E020: sw          $a0, 0x1D0($at)
    MEM_W(0X1D0, ctx->r1) = ctx->r4;
    // 0x8007E024: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007E028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007E02C: addu        $t3, $a0, $a1
    ctx->r11 = ADD32(ctx->r4, ctx->r5);
    // 0x8007E030: sw          $t3, 0x1D4($at)
    MEM_W(0X1D4, ctx->r1) = ctx->r11;
    // 0x8007E034: jr          $ra
    // 0x8007E038: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007E038: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void n64HeapAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E03C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007E040: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007E044: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007E048: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8007E04C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8007E050: addiu       $t8, $t7, 0xF
    ctx->r24 = ADD32(ctx->r15, 0XF);
    // 0x8007E054: lw          $t0, 0x3198($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3198);
    // 0x8007E058: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007E05C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8007E060: lw          $t6, 0x3190($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3190);
    // 0x8007E064: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007E068: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x8007E06C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007E070: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8007E074: sw          $t1, 0x3198($at)
    MEM_W(0X3198, ctx->r1) = ctx->r9;
    // 0x8007E078: beq         $t6, $zero, L_8007E1A0
    if (ctx->r14 == 0) {
        // 0x8007E07C: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_8007E1A0;
    }
    // 0x8007E07C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_8007E080:
    // 0x8007E080: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E084: nop

    // 0x8007E088: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8007E08C: nop

    // 0x8007E090: bne         $t3, $zero, L_8007E17C
    if (ctx->r11 != 0) {
        // 0x8007E094: nop
    
            goto L_8007E17C;
    }
    // 0x8007E094: nop

    // 0x8007E098: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x8007E09C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007E0A0: nop

    // 0x8007E0A4: sltu        $at, $t4, $t5
    ctx->r1 = ctx->r12 < ctx->r13 ? 1 : 0;
    // 0x8007E0A8: bne         $at, $zero, L_8007E17C
    if (ctx->r1 != 0) {
        // 0x8007E0AC: nop
    
            goto L_8007E17C;
    }
    // 0x8007E0AC: nop

    // 0x8007E0B0: addiu       $t7, $t2, 0x10
    ctx->r15 = ADD32(ctx->r10, 0X10);
    // 0x8007E0B4: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8007E0B8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E0BC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007E0C0: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x8007E0C4: nop

    // 0x8007E0C8: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x8007E0CC: sltiu       $at, $t1, 0x11
    ctx->r1 = ctx->r9 < 0X11 ? 1 : 0;
    // 0x8007E0D0: bne         $at, $zero, L_8007E168
    if (ctx->r1 != 0) {
        // 0x8007E0D4: sw          $t1, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r9;
            goto L_8007E168;
    }
    // 0x8007E0D4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8007E0D8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E0DC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007E0E0: addiu       $t6, $t1, -0x10
    ctx->r14 = ADD32(ctx->r9, -0X10);
    // 0x8007E0E4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8007E0E8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8007E0EC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007E0F0: addiu       $t7, $t5, 0x10
    ctx->r15 = ADD32(ctx->r13, 0X10);
    // 0x8007E0F4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8007E0F8: sw          $t2, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r10;
    // 0x8007E0FC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8007E100: nop

    // 0x8007E104: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8007E108: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8007E10C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E110: nop

    // 0x8007E114: sw          $t0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r8;
    // 0x8007E118: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E11C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8007E120: lw          $t6, 0x8($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X8);
    // 0x8007E124: nop

    // 0x8007E128: sw          $t6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r14;
    // 0x8007E12C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8007E130: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E134: nop

    // 0x8007E138: sw          $t4, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r12;
    // 0x8007E13C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8007E140: nop

    // 0x8007E144: lw          $t5, 0x8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8);
    // 0x8007E148: nop

    // 0x8007E14C: beq         $t5, $zero, L_8007E158
    if (ctx->r13 == 0) {
        // 0x8007E150: nop
    
            goto L_8007E158;
    }
    // 0x8007E150: nop

    // 0x8007E154: sw          $t2, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r10;
L_8007E158:
    // 0x8007E158: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8007E15C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E160: nop

    // 0x8007E164: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
L_8007E168:
    // 0x8007E168: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E16C: nop

    // 0x8007E170: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8007E174: b           L_8007E1CC
    // 0x8007E178: nop

        goto L_8007E1CC;
    // 0x8007E178: nop

L_8007E17C:
    // 0x8007E17C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E180: nop

    // 0x8007E184: lw          $t6, 0x8($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X8);
    // 0x8007E188: nop

    // 0x8007E18C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8007E190: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E194: nop

    // 0x8007E198: bne         $t3, $zero, L_8007E080
    if (ctx->r11 != 0) {
        // 0x8007E19C: nop
    
            goto L_8007E080;
    }
    // 0x8007E19C: nop

L_8007E1A0:
    // 0x8007E1A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E1A4: jal         0x800B3BFC
    // 0x8007E1A8: addiu       $a0, $a0, -0x1FC0
    ctx->r4 = ADD32(ctx->r4, -0X1FC0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007E1A8: addiu       $a0, $a0, -0x1FC0
    ctx->r4 = ADD32(ctx->r4, -0X1FC0);
    after_0:
    // 0x8007E1AC: jal         0x8007E5D4
    // 0x8007E1B0: nop

    n64HeapStats(rdram, ctx);
        goto after_1;
    // 0x8007E1B0: nop

    after_1:
    // 0x8007E1B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E1B8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007E1BC: addiu       $a1, $a1, -0x1FA0
    ctx->r5 = ADD32(ctx->r5, -0X1FA0);
    // 0x8007E1C0: jal         0x80083560
    // 0x8007E1C4: addiu       $a0, $a0, -0x1FB0
    ctx->r4 = ADD32(ctx->r4, -0X1FB0);
    debug_print_reason_routine(rdram, ctx);
        goto after_2;
    // 0x8007E1C4: addiu       $a0, $a0, -0x1FB0
    ctx->r4 = ADD32(ctx->r4, -0X1FB0);
    after_2:
    // 0x8007E1C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007E1CC:
    // 0x8007E1CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007E1D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007E1D4: jr          $ra
    // 0x8007E1D8: nop

    return;
    // 0x8007E1D8: nop

;}

RECOMP_FUNC void n64HeapAllocAppend(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E1DC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007E1E0: addiu       $t7, $a0, 0xF
    ctx->r15 = ADD32(ctx->r4, 0XF);
    // 0x8007E1E4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8007E1E8: lw          $t6, 0x3190($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3190);
    // 0x8007E1EC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8007E1F0: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8007E1F4: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x8007E1F8: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x8007E1FC: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8007E200: beq         $t6, $zero, L_8007E230
    if (ctx->r14 == 0) {
        // 0x8007E204: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_8007E230;
    }
    // 0x8007E204: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_8007E208:
    // 0x8007E208: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8007E20C: nop

    // 0x8007E210: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x8007E214: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8007E218: nop

    // 0x8007E21C: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8007E220: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8007E224: nop

    // 0x8007E228: bne         $t2, $zero, L_8007E208
    if (ctx->r10 != 0) {
        // 0x8007E22C: nop
    
            goto L_8007E208;
    }
    // 0x8007E22C: nop

L_8007E230:
    // 0x8007E230: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8007E234: nop

    // 0x8007E238: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8007E23C: nop

    // 0x8007E240: beq         $t4, $zero, L_8007E250
    if (ctx->r12 == 0) {
        // 0x8007E244: nop
    
            goto L_8007E250;
    }
    // 0x8007E244: nop

    // 0x8007E248: b           L_8007E320
    // 0x8007E24C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007E320;
    // 0x8007E24C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007E250:
    // 0x8007E250: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8007E254: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8007E258: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8007E25C: nop

    // 0x8007E260: sltu        $at, $t8, $t5
    ctx->r1 = ctx->r24 < ctx->r13 ? 1 : 0;
    // 0x8007E264: beq         $at, $zero, L_8007E274
    if (ctx->r1 == 0) {
        // 0x8007E268: nop
    
            goto L_8007E274;
    }
    // 0x8007E268: nop

    // 0x8007E26C: b           L_8007E320
    // 0x8007E270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007E320;
    // 0x8007E270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007E274:
    // 0x8007E274: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8007E278: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8007E27C: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x8007E280: nop

    // 0x8007E284: bne         $t6, $t0, L_8007E2B4
    if (ctx->r14 != ctx->r8) {
        // 0x8007E288: nop
    
            goto L_8007E2B4;
    }
    // 0x8007E288: nop

    // 0x8007E28C: addiu       $t1, $t9, 0x10
    ctx->r9 = ADD32(ctx->r25, 0X10);
    // 0x8007E290: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8007E294: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8007E298: nop

    // 0x8007E29C: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x8007E2A0: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8007E2A4: nop

    // 0x8007E2A8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8007E2AC: b           L_8007E320
    // 0x8007E2B0: nop

        goto L_8007E320;
    // 0x8007E2B0: nop

L_8007E2B4:
    // 0x8007E2B4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007E2B8: lw          $t4, 0x1D4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1D4);
    // 0x8007E2BC: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8007E2C0: nop

    // 0x8007E2C4: subu        $t5, $t4, $t7
    ctx->r13 = SUB32(ctx->r12, ctx->r15);
    // 0x8007E2C8: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8007E2CC: addiu       $t8, $t5, 0x10
    ctx->r24 = ADD32(ctx->r13, 0X10);
    // 0x8007E2D0: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x8007E2D4: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8007E2D8: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8007E2DC: nop

    // 0x8007E2E0: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x8007E2E4: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8007E2E8: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8007E2EC: nop

    // 0x8007E2F0: sw          $t1, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r9;
    // 0x8007E2F4: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8007E2F8: nop

    // 0x8007E2FC: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x8007E300: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8007E304: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8007E308: nop

    // 0x8007E30C: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
    // 0x8007E310: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8007E314: nop

    // 0x8007E318: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8007E31C: nop

L_8007E320:
    // 0x8007E320: jr          $ra
    // 0x8007E324: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007E324: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void n64HeapUnalloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E328: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007E32C: lw          $a1, 0x3190($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3190);
    // 0x8007E330: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007E334: beq         $a1, $zero, L_8007E454
    if (ctx->r5 == 0) {
        // 0x8007E338: nop
    
            goto L_8007E454;
    }
    // 0x8007E338: nop

L_8007E33C:
    // 0x8007E33C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8007E340: nop

    // 0x8007E344: bne         $t6, $a0, L_8007E444
    if (ctx->r14 != ctx->r4) {
        // 0x8007E348: nop
    
            goto L_8007E444;
    }
    // 0x8007E348: nop

    // 0x8007E34C: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x8007E350: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8007E354: beq         $a2, $zero, L_8007E3C4
    if (ctx->r6 == 0) {
        // 0x8007E358: nop
    
            goto L_8007E3C4;
    }
    // 0x8007E358: nop

L_8007E35C:
    // 0x8007E35C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8007E360: nop

    // 0x8007E364: bne         $t7, $zero, L_8007E3C4
    if (ctx->r15 != 0) {
        // 0x8007E368: nop
    
            goto L_8007E3C4;
    }
    // 0x8007E368: nop

    // 0x8007E36C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8007E370: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x8007E374: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x8007E378: nop

    // 0x8007E37C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8007E380: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x8007E384: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x8007E388: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x8007E38C: nop

    // 0x8007E390: sw          $t2, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r10;
    // 0x8007E394: lw          $t3, 0x8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8);
    // 0x8007E398: nop

    // 0x8007E39C: beq         $t3, $zero, L_8007E3B0
    if (ctx->r11 == 0) {
        // 0x8007E3A0: nop
    
            goto L_8007E3B0;
    }
    // 0x8007E3A0: nop

    // 0x8007E3A4: lw          $t4, 0x8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X8);
    // 0x8007E3A8: nop

    // 0x8007E3AC: sw          $a2, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r6;
L_8007E3B0:
    // 0x8007E3B0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8007E3B4: lw          $a2, 0xC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0XC);
    // 0x8007E3B8: nop

    // 0x8007E3BC: bne         $a2, $zero, L_8007E35C
    if (ctx->r6 != 0) {
        // 0x8007E3C0: nop
    
            goto L_8007E35C;
    }
    // 0x8007E3C0: nop

L_8007E3C4:
    // 0x8007E3C4: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    // 0x8007E3C8: nop

    // 0x8007E3CC: beq         $a2, $zero, L_8007E454
    if (ctx->r6 == 0) {
        // 0x8007E3D0: nop
    
            goto L_8007E454;
    }
    // 0x8007E3D0: nop

L_8007E3D4:
    // 0x8007E3D4: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8007E3D8: nop

    // 0x8007E3DC: bne         $t5, $zero, L_8007E454
    if (ctx->r13 != 0) {
        // 0x8007E3E0: nop
    
            goto L_8007E454;
    }
    // 0x8007E3E0: nop

    // 0x8007E3E4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8007E3E8: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x8007E3EC: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x8007E3F0: nop

    // 0x8007E3F4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007E3F8: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x8007E3FC: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8007E400: lw          $t0, 0x8($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X8);
    // 0x8007E404: nop

    // 0x8007E408: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
    // 0x8007E40C: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x8007E410: nop

    // 0x8007E414: beq         $t1, $zero, L_8007E428
    if (ctx->r9 == 0) {
        // 0x8007E418: nop
    
            goto L_8007E428;
    }
    // 0x8007E418: nop

    // 0x8007E41C: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x8007E420: nop

    // 0x8007E424: sw          $a1, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r5;
L_8007E428:
    // 0x8007E428: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8007E42C: lw          $a2, 0x8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X8);
    // 0x8007E430: nop

    // 0x8007E434: bne         $a2, $zero, L_8007E3D4
    if (ctx->r6 != 0) {
        // 0x8007E438: nop
    
            goto L_8007E3D4;
    }
    // 0x8007E438: nop

    // 0x8007E43C: b           L_8007E454
    // 0x8007E440: nop

        goto L_8007E454;
    // 0x8007E440: nop

L_8007E444:
    // 0x8007E444: lw          $a1, 0x8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X8);
    // 0x8007E448: nop

    // 0x8007E44C: bne         $a1, $zero, L_8007E33C
    if (ctx->r5 != 0) {
        // 0x8007E450: nop
    
            goto L_8007E33C;
    }
    // 0x8007E450: nop

L_8007E454:
    // 0x8007E454: jr          $ra
    // 0x8007E458: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007E458: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void n64HeapGetTotalMemUsed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E45C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8007E460: lw          $a0, 0x3190($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3190);
    // 0x8007E464: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007E468: beq         $a0, $zero, L_8007E498
    if (ctx->r4 == 0) {
        // 0x8007E46C: sw          $zero, 0x0($sp)
        MEM_W(0X0, ctx->r29) = 0;
            goto L_8007E498;
    }
    // 0x8007E46C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8007E470:
    // 0x8007E470: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8007E474: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8007E478: nop

    // 0x8007E47C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007E480: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x8007E484: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x8007E488: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    // 0x8007E48C: nop

    // 0x8007E490: bne         $a0, $zero, L_8007E470
    if (ctx->r4 != 0) {
        // 0x8007E494: nop
    
            goto L_8007E470;
    }
    // 0x8007E494: nop

L_8007E498:
    // 0x8007E498: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8007E49C: jr          $ra
    // 0x8007E4A0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007E4A0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void n64HeapGetTotalMemFree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E4A4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8007E4A8: lw          $a0, 0x3190($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3190);
    // 0x8007E4AC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007E4B0: beq         $a0, $zero, L_8007E4E8
    if (ctx->r4 == 0) {
        // 0x8007E4B4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8007E4E8;
    }
    // 0x8007E4B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8007E4B8:
    // 0x8007E4B8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007E4BC: nop

    // 0x8007E4C0: bne         $t6, $zero, L_8007E4D8
    if (ctx->r14 != 0) {
        // 0x8007E4C4: nop
    
            goto L_8007E4D8;
    }
    // 0x8007E4C4: nop

    // 0x8007E4C8: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8007E4CC: nop

    // 0x8007E4D0: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8007E4D4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_8007E4D8:
    // 0x8007E4D8: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    // 0x8007E4DC: nop

    // 0x8007E4E0: bne         $a0, $zero, L_8007E4B8
    if (ctx->r4 != 0) {
        // 0x8007E4E4: nop
    
            goto L_8007E4B8;
    }
    // 0x8007E4E4: nop

L_8007E4E8:
    // 0x8007E4E8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8007E4EC: jr          $ra
    // 0x8007E4F0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007E4F0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void n64HeapGetMaxFreeBlockSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E4F4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007E4F8: lw          $a1, 0x3190($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3190);
    // 0x8007E4FC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007E500: beq         $a1, $zero, L_8007E544
    if (ctx->r5 == 0) {
        // 0x8007E504: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8007E544;
    }
    // 0x8007E504: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8007E508:
    // 0x8007E508: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8007E50C: nop

    // 0x8007E510: bne         $t6, $zero, L_8007E534
    if (ctx->r14 != 0) {
        // 0x8007E514: nop
    
            goto L_8007E534;
    }
    // 0x8007E514: nop

    // 0x8007E518: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8007E51C: nop

    // 0x8007E520: sltu        $at, $a0, $t7
    ctx->r1 = ctx->r4 < ctx->r15 ? 1 : 0;
    // 0x8007E524: beq         $at, $zero, L_8007E534
    if (ctx->r1 == 0) {
        // 0x8007E528: nop
    
            goto L_8007E534;
    }
    // 0x8007E528: nop

    // 0x8007E52C: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    // 0x8007E530: nop

L_8007E534:
    // 0x8007E534: lw          $a1, 0x8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X8);
    // 0x8007E538: nop

    // 0x8007E53C: bne         $a1, $zero, L_8007E508
    if (ctx->r5 != 0) {
        // 0x8007E540: nop
    
            goto L_8007E508;
    }
    // 0x8007E540: nop

L_8007E544:
    // 0x8007E544: addiu       $v0, $a0, -0x10
    ctx->r2 = ADD32(ctx->r4, -0X10);
    // 0x8007E548: jr          $ra
    // 0x8007E54C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007E54C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void n64HeapGetNumFragments(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E550: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007E554: lw          $a1, 0x3190($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3190);
    // 0x8007E558: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007E55C: beq         $a1, $zero, L_8007E598
    if (ctx->r5 == 0) {
        // 0x8007E560: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8007E598;
    }
    // 0x8007E560: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8007E564:
    // 0x8007E564: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8007E568: nop

    // 0x8007E56C: bne         $t6, $zero, L_8007E588
    if (ctx->r14 != 0) {
        // 0x8007E570: nop
    
            goto L_8007E588;
    }
    // 0x8007E570: nop

    // 0x8007E574: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x8007E578: nop

    // 0x8007E57C: beq         $t7, $zero, L_8007E588
    if (ctx->r15 == 0) {
        // 0x8007E580: nop
    
            goto L_8007E588;
    }
    // 0x8007E580: nop

    // 0x8007E584: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8007E588:
    // 0x8007E588: lw          $a1, 0x8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X8);
    // 0x8007E58C: nop

    // 0x8007E590: bne         $a1, $zero, L_8007E564
    if (ctx->r5 != 0) {
        // 0x8007E594: nop
    
            goto L_8007E564;
    }
    // 0x8007E594: nop

L_8007E598:
    // 0x8007E598: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007E59C: jr          $ra
    // 0x8007E5A0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007E5A0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void n64HeapGetTotalHandles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E5A4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007E5A8: lw          $a1, 0x3190($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3190);
    // 0x8007E5AC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007E5B0: beq         $a1, $zero, L_8007E5C8
    if (ctx->r5 == 0) {
        // 0x8007E5B4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8007E5C8;
    }
    // 0x8007E5B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8007E5B8:
    // 0x8007E5B8: lw          $a1, 0x8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X8);
    // 0x8007E5BC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007E5C0: bne         $a1, $zero, L_8007E5B8
    if (ctx->r5 != 0) {
        // 0x8007E5C4: nop
    
            goto L_8007E5B8;
    }
    // 0x8007E5C4: nop

L_8007E5C8:
    // 0x8007E5C8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007E5CC: jr          $ra
    // 0x8007E5D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007E5D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void n64HeapStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E5D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007E5D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007E5DC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8007E5E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007E5E4: lw          $s0, 0x3190($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X3190);
    // 0x8007E5E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E5EC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8007E5F0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8007E5F4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8007E5F8: jal         0x800B3BFC
    // 0x8007E5FC: addiu       $a0, $a0, -0x1F90
    ctx->r4 = ADD32(ctx->r4, -0X1F90);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007E5FC: addiu       $a0, $a0, -0x1F90
    ctx->r4 = ADD32(ctx->r4, -0X1F90);
    after_0:
    // 0x8007E600: beq         $s0, $zero, L_8007E680
    if (ctx->r16 == 0) {
        // 0x8007E604: nop
    
            goto L_8007E680;
    }
    // 0x8007E604: nop

L_8007E608:
    // 0x8007E608: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E60C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8007E610: jal         0x800B3BFC
    // 0x8007E614: addiu       $a0, $a0, -0x1F78
    ctx->r4 = ADD32(ctx->r4, -0X1F78);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007E614: addiu       $a0, $a0, -0x1F78
    ctx->r4 = ADD32(ctx->r4, -0X1F78);
    after_1:
    // 0x8007E618: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E61C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8007E620: jal         0x800B3BFC
    // 0x8007E624: addiu       $a0, $a0, -0x1F68
    ctx->r4 = ADD32(ctx->r4, -0X1F68);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007E624: addiu       $a0, $a0, -0x1F68
    ctx->r4 = ADD32(ctx->r4, -0X1F68);
    after_2:
    // 0x8007E628: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E62C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8007E630: jal         0x800B3BFC
    // 0x8007E634: addiu       $a0, $a0, -0x1F54
    ctx->r4 = ADD32(ctx->r4, -0X1F54);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8007E634: addiu       $a0, $a0, -0x1F54
    ctx->r4 = ADD32(ctx->r4, -0X1F54);
    after_3:
    // 0x8007E638: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E63C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8007E640: jal         0x800B3BFC
    // 0x8007E644: addiu       $a0, $a0, -0x1F40
    ctx->r4 = ADD32(ctx->r4, -0X1F40);
    rmonPrintf_recomp(rdram, ctx);
        goto after_4;
    // 0x8007E644: addiu       $a0, $a0, -0x1F40
    ctx->r4 = ADD32(ctx->r4, -0X1F40);
    after_4:
    // 0x8007E648: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8007E64C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007E650: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007E654: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007E658: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007E65C: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x8007E660: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8007E664: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007E668: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8007E66C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8007E670: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x8007E674: nop

    // 0x8007E678: bne         $s0, $zero, L_8007E608
    if (ctx->r16 != 0) {
        // 0x8007E67C: nop
    
            goto L_8007E608;
    }
    // 0x8007E67C: nop

L_8007E680:
    // 0x8007E680: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E684: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8007E688: jal         0x800B3BFC
    // 0x8007E68C: addiu       $a0, $a0, -0x1F2C
    ctx->r4 = ADD32(ctx->r4, -0X1F2C);
    rmonPrintf_recomp(rdram, ctx);
        goto after_5;
    // 0x8007E68C: addiu       $a0, $a0, -0x1F2C
    ctx->r4 = ADD32(ctx->r4, -0X1F2C);
    after_5:
    // 0x8007E690: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E694: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8007E698: jal         0x800B3BFC
    // 0x8007E69C: addiu       $a0, $a0, -0x1F18
    ctx->r4 = ADD32(ctx->r4, -0X1F18);
    rmonPrintf_recomp(rdram, ctx);
        goto after_6;
    // 0x8007E69C: addiu       $a0, $a0, -0x1F18
    ctx->r4 = ADD32(ctx->r4, -0X1F18);
    after_6:
    // 0x8007E6A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E6A4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8007E6A8: jal         0x800B3BFC
    // 0x8007E6AC: addiu       $a0, $a0, -0x1F04
    ctx->r4 = ADD32(ctx->r4, -0X1F04);
    rmonPrintf_recomp(rdram, ctx);
        goto after_7;
    // 0x8007E6AC: addiu       $a0, $a0, -0x1F04
    ctx->r4 = ADD32(ctx->r4, -0X1F04);
    after_7:
    // 0x8007E6B0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007E6B4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007E6B8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8007E6BC: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8007E6C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007E6C4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007E6C8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007E6CC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8007E6D0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8007E6D4: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8007E6D8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8007E6DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E6E0: addiu       $a0, $a0, -0x1EF0
    ctx->r4 = ADD32(ctx->r4, -0X1EF0);
    // 0x8007E6E4: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8007E6E8: nop

    // 0x8007E6EC: div.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x8007E6F0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8007E6F4: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x8007E6F8: jal         0x800B3BFC
    // 0x8007E6FC: nop

    rmonPrintf_recomp(rdram, ctx);
        goto after_8;
    // 0x8007E6FC: nop

    after_8:
    // 0x8007E700: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007E704: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8007E708: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E70C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007E710: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007E714: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8007E718: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8007E71C: jal         0x800B3BFC
    // 0x8007E720: addiu       $a0, $a0, -0x1ED8
    ctx->r4 = ADD32(ctx->r4, -0X1ED8);
    rmonPrintf_recomp(rdram, ctx);
        goto after_9;
    // 0x8007E720: addiu       $a0, $a0, -0x1ED8
    ctx->r4 = ADD32(ctx->r4, -0X1ED8);
    after_9:
    // 0x8007E724: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E728: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007E72C: jr          $ra
    // 0x8007E730: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007E730: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void n64HeapResetAllocCumulative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E734: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007E738: jr          $ra
    // 0x8007E73C: sw          $zero, 0x3198($at)
    MEM_W(0X3198, ctx->r1) = 0;
    return;
    // 0x8007E73C: sw          $zero, 0x3198($at)
    MEM_W(0X3198, ctx->r1) = 0;
;}

RECOMP_FUNC void n64HeapGetAllocCumulative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E740: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8007E744: lw          $v0, 0x3198($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3198);
    // 0x8007E748: jr          $ra
    // 0x8007E74C: nop

    return;
    // 0x8007E74C: nop

;}

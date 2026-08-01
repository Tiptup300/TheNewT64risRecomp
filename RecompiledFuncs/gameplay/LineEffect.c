#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void LineEffect_State2_SpawnColumnCubes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068FF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80068FF4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80068FF8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80068FFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80069000: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80069004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80069008: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x8006900C: nop

    // 0x80069010: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80069014: beq         $at, $zero, L_800690B0
    if (ctx->r1 == 0) {
        // 0x80069018: nop
    
            goto L_800690B0;
    }
    // 0x80069018: nop

    // 0x8006901C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80069020: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80069024: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80069028: lw          $a0, 0x18($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X18);
    // 0x8006902C: jal         0x8006D674
    // 0x80069030: nop

    BoardP_ConvertCellToFalling(rdram, ctx);
        goto after_0;
    // 0x80069030: nop

    after_0:
    // 0x80069034: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80069038: nop

    // 0x8006903C: lbu         $t2, 0x5($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5);
    // 0x80069040: nop

    // 0x80069044: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80069048: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8006904C: lw          $a0, 0x1C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X1C);
    // 0x80069050: jal         0x8006D674
    // 0x80069054: nop

    BoardP_ConvertCellToFalling(rdram, ctx);
        goto after_1;
    // 0x80069054: nop

    after_1:
    // 0x80069058: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8006905C: jal         0x800A35EC
    // 0x80069060: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    Scene_RandRange(rdram, ctx);
        goto after_2;
    // 0x80069060: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_2:
    // 0x80069064: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80069068: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006906C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069070: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80069074: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80069078: jal         0x8008A5C8
    // 0x8006907C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    Audio2_Play_SFX(rdram, ctx);
        goto after_3;
    // 0x8006907C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80069080: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80069084: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80069088: lbu         $t7, 0x5($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X5);
    // 0x8006908C: nop

    // 0x80069090: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80069094: sb          $t8, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r24;
    // 0x80069098: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8006909C: nop

    // 0x800690A0: sb          $t6, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r14;
    // 0x800690A4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800690A8: b           L_800690D4
    // 0x800690AC: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
        goto L_800690D4;
    // 0x800690AC: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
L_800690B0:
    // 0x800690B0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800690B4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800690B8: sb          $t2, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r10;
    // 0x800690BC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800690C0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800690C4: sb          $t3, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r11;
    // 0x800690C8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800690CC: nop

    // 0x800690D0: sb          $zero, 0x2($t7)
    MEM_B(0X2, ctx->r15) = 0;
L_800690D4:
    // 0x800690D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800690D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800690DC: jr          $ra
    // 0x800690E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800690E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void LineEffect_State3_SwapCubes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800690E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800690E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800690EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800690F0: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x800690F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800690F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800690FC: beq         $at, $zero, L_8006912C
    if (ctx->r1 == 0) {
        // 0x80069100: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_8006912C;
    }
    // 0x80069100: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
L_80069104:
    // 0x80069104: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80069108: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8006910C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80069110: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x80069114: jal         0x8006E288
    // 0x80069118: nop

    BoardP_RemoveCubeAndCollapseColumn(rdram, ctx);
        goto after_0;
    // 0x80069118: nop

    after_0:
    // 0x8006911C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80069120: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80069124: bne         $at, $zero, L_80069104
    if (ctx->r1 != 0) {
        // 0x80069128: nop
    
            goto L_80069104;
    }
    // 0x80069128: nop

L_8006912C:
    // 0x8006912C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80069130: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80069134: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
    // 0x80069138: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8006913C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80069140: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80069144: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80069148: nop

    // 0x8006914C: sb          $t2, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r10;
    // 0x80069150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80069154: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80069158: jr          $ra
    // 0x8006915C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006915C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void LineEffect_State4_DelayedClear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069160: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80069164: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80069168: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006916C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80069170: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80069174: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80069178: lbu         $t7, 0x4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4);
    // 0x8006917C: nop

    // 0x80069180: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80069184: beq         $at, $zero, L_80069198
    if (ctx->r1 == 0) {
        // 0x80069188: nop
    
            goto L_80069198;
    }
    // 0x80069188: nop

    // 0x8006918C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80069190: b           L_800692EC
    // 0x80069194: sb          $t8, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r24;
        goto L_800692EC;
    // 0x80069194: sb          $t8, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r24;
L_80069198:
    // 0x80069198: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8006919C: nop

    // 0x800691A0: sb          $zero, 0x4($t9)
    MEM_B(0X4, ctx->r25) = 0;
    // 0x800691A4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800691A8: nop

    // 0x800691AC: lbu         $t1, 0x5($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X5);
    // 0x800691B0: nop

    // 0x800691B4: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x800691B8: beq         $at, $zero, L_800692C8
    if (ctx->r1 == 0) {
        // 0x800691BC: nop
    
            goto L_800692C8;
    }
    // 0x800691BC: nop

    // 0x800691C0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800691C4: jal         0x800A35EC
    // 0x800691C8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    Scene_RandRange(rdram, ctx);
        goto after_0;
    // 0x800691C8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x800691CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800691D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800691D4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800691D8: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x800691DC: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x800691E0: jal         0x8008A5C8
    // 0x800691E4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    Audio2_Play_SFX(rdram, ctx);
        goto after_1;
    // 0x800691E4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800691E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800691EC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800691F0: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x800691F4: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x800691F8: jal         0x8008A5C8
    // 0x800691FC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Audio2_Play_SFX(rdram, ctx);
        goto after_2;
    // 0x800691FC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80069200: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80069204: nop

    // 0x80069208: lbu         $t3, 0x5($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X5);
    // 0x8006920C: nop

    // 0x80069210: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x80069214: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80069218: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x8006921C: lw          $a0, 0x18($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X18);
    // 0x80069220: jal         0x8006D674
    // 0x80069224: nop

    BoardP_ConvertCellToFalling(rdram, ctx);
        goto after_3;
    // 0x80069224: nop

    after_3:
    // 0x80069228: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006922C: nop

    // 0x80069230: lbu         $t6, 0x5($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X5);
    // 0x80069234: nop

    // 0x80069238: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8006923C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80069240: lw          $a0, 0x1C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X1C);
    // 0x80069244: jal         0x8006D674
    // 0x80069248: nop

    BoardP_ConvertCellToFalling(rdram, ctx);
        goto after_4;
    // 0x80069248: nop

    after_4:
    // 0x8006924C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80069250: nop

    // 0x80069254: lbu         $t3, 0x5($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X5);
    // 0x80069258: nop

    // 0x8006925C: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x80069260: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x80069264: addu        $t5, $t1, $t2
    ctx->r13 = ADD32(ctx->r9, ctx->r10);
    // 0x80069268: lw          $a0, 0x18($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X18);
    // 0x8006926C: jal         0x8006E288
    // 0x80069270: nop

    BoardP_RemoveCubeAndCollapseColumn(rdram, ctx);
        goto after_5;
    // 0x80069270: nop

    after_5:
    // 0x80069274: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80069278: nop

    // 0x8006927C: lbu         $t6, 0x5($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X5);
    // 0x80069280: nop

    // 0x80069284: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80069288: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006928C: lw          $a0, 0x1C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X1C);
    // 0x80069290: jal         0x8006E288
    // 0x80069294: nop

    BoardP_RemoveCubeAndCollapseColumn(rdram, ctx);
        goto after_6;
    // 0x80069294: nop

    after_6:
    // 0x80069298: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8006929C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800692A0: lbu         $t3, 0x5($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X5);
    // 0x800692A4: nop

    // 0x800692A8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800692AC: sb          $t4, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r12;
    // 0x800692B0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800692B4: nop

    // 0x800692B8: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
    // 0x800692BC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800692C0: b           L_800692EC
    // 0x800692C4: sb          $zero, 0x2($t5)
    MEM_B(0X2, ctx->r13) = 0;
        goto L_800692EC;
    // 0x800692C4: sb          $zero, 0x2($t5)
    MEM_B(0X2, ctx->r13) = 0;
L_800692C8:
    // 0x800692C8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800692CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800692D0: sb          $t6, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r14;
    // 0x800692D4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800692D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800692DC: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x800692E0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800692E4: nop

    // 0x800692E8: sb          $t9, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r25;
L_800692EC:
    // 0x800692EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800692F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800692F4: jr          $ra
    // 0x800692F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800692F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void LineEffect_State5_SetupFade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800692FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80069300: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80069304: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80069308: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006930C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80069310: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80069314: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80069318: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x8006931C: sb          $t6, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r14;
    // 0x80069320: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80069324: nop

    // 0x80069328: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x8006932C: jal         0x8006D5BC
    // 0x80069330: nop

    BoardP_SeparateCell(rdram, ctx);
        goto after_0;
    // 0x80069330: nop

    after_0:
    // 0x80069334: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80069338: slti        $at, $s1, 0xA
    ctx->r1 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x8006933C: beq         $at, $zero, L_80069388
    if (ctx->r1 == 0) {
        // 0x80069340: nop
    
            goto L_80069388;
    }
    // 0x80069340: nop

L_80069344:
    // 0x80069344: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80069348: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x8006934C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80069350: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    // 0x80069354: jal         0x8006D5BC
    // 0x80069358: nop

    BoardP_SeparateCell(rdram, ctx);
        goto after_1;
    // 0x80069358: nop

    after_1:
    // 0x8006935C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80069360: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80069364: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80069368: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x8006936C: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    // 0x80069370: jal         0x8006D450
    // 0x80069374: nop

    BoardP_MergeGroups(rdram, ctx);
        goto after_2;
    // 0x80069374: nop

    after_2:
    // 0x80069378: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006937C: slti        $at, $s1, 0xA
    ctx->r1 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x80069380: bne         $at, $zero, L_80069344
    if (ctx->r1 != 0) {
        // 0x80069384: nop
    
            goto L_80069344;
    }
    // 0x80069384: nop

L_80069388:
    // 0x80069388: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006938C: slti        $at, $s1, 0xA
    ctx->r1 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x80069390: beq         $at, $zero, L_800693F4
    if (ctx->r1 == 0) {
        // 0x80069394: nop
    
            goto L_800693F4;
    }
    // 0x80069394: nop

L_80069398:
    // 0x80069398: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8006939C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800693A0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800693A4: lw          $s0, 0x8($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X8);
    // 0x800693A8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800693AC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800693B0: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800693B4: lh          $t9, 0x48($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X48);
    // 0x800693B8: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x800693BC: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x800693C0: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x800693C4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800693C8: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800693CC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x800693D0: mflo        $t3
    ctx->r11 = lo;
    // 0x800693D4: sh          $t3, 0x4A($t4)
    MEM_H(0X4A, ctx->r12) = ctx->r11;
    // 0x800693D8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x800693DC: jal         0x80070860
    // 0x800693E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_Mino_StartSlide(rdram, ctx);
        goto after_3;
    // 0x800693E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x800693E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800693E8: slti        $at, $s1, 0xA
    ctx->r1 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x800693EC: bne         $at, $zero, L_80069398
    if (ctx->r1 != 0) {
        // 0x800693F0: nop
    
            goto L_80069398;
    }
    // 0x800693F0: nop

L_800693F4:
    // 0x800693F4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800693F8: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x800693FC: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x80069400: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80069404: nop

    // 0x80069408: sb          $zero, 0x3($t6)
    MEM_B(0X3, ctx->r14) = 0;
    // 0x8006940C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80069410: nop

    // 0x80069414: sb          $zero, 0x2($t7)
    MEM_B(0X2, ctx->r15) = 0;
    // 0x80069418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006941C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80069420: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80069424: jr          $ra
    // 0x80069428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80069428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void LineEffect_State6_HoldCountdown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006942C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80069434: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80069438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006943C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80069440: lbu         $t7, 0x4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4);
    // 0x80069444: nop

    // 0x80069448: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8006944C: sb          $t8, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r24;
    // 0x80069450: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80069454: nop

    // 0x80069458: lbu         $t0, 0x4($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X4);
    // 0x8006945C: nop

    // 0x80069460: bne         $t0, $zero, L_80069488
    if (ctx->r8 != 0) {
        // 0x80069464: nop
    
            goto L_80069488;
    }
    // 0x80069464: nop

    // 0x80069468: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8006946C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069470: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069474: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
    // 0x80069478: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x8006947C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80069480: jal         0x8008A5C8
    // 0x80069484: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    Audio2_Play_SFX(rdram, ctx);
        goto after_0;
    // 0x80069484: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
L_80069488:
    // 0x80069488: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8006948C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80069490: sb          $t2, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r10;
    // 0x80069494: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80069498: nop

    // 0x8006949C: sb          $zero, 0x2($t4)
    MEM_B(0X2, ctx->r12) = 0;
    // 0x800694A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800694A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800694A8: jr          $ra
    // 0x800694AC: nop

    return;
    // 0x800694AC: nop

;}

RECOMP_FUNC void LineEffect_State7_SwapCubes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800694B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800694B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800694B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800694BC: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x800694C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800694C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800694C8: beq         $at, $zero, L_800694F8
    if (ctx->r1 == 0) {
        // 0x800694CC: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_800694F8;
    }
    // 0x800694CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
L_800694D0:
    // 0x800694D0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800694D4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800694D8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800694DC: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x800694E0: jal         0x8006E288
    // 0x800694E4: nop

    BoardP_RemoveCubeAndCollapseColumn(rdram, ctx);
        goto after_0;
    // 0x800694E4: nop

    after_0:
    // 0x800694E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800694EC: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x800694F0: bne         $at, $zero, L_800694D0
    if (ctx->r1 != 0) {
        // 0x800694F4: nop
    
            goto L_800694D0;
    }
    // 0x800694F4: nop

L_800694F8:
    // 0x800694F8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800694FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80069500: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
    // 0x80069504: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80069508: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006950C: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80069510: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80069514: nop

    // 0x80069518: sb          $t2, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r10;
    // 0x8006951C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80069520: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80069524: jr          $ra
    // 0x80069528: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80069528: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void LineEffect_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006952C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80069538: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_8006953C:
    // 0x8006953C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80069540: nop

    // 0x80069544: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80069548: nop

    // 0x8006954C: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80069550: beq         $at, $zero, L_80069628
    if (ctx->r1 == 0) {
        // 0x80069554: nop
    
            goto L_80069628;
    }
    // 0x80069554: nop

    // 0x80069558: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8006955C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80069560: addu        $at, $at, $t7
    gpr jr_addend_8006956C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80069564: lw          $t7, -0x29FC($at)
    ctx->r15 = ADD32(ctx->r1, -0X29FC);
    // 0x80069568: nop

    // 0x8006956C: jr          $t7
    // 0x80069570: nop

    switch (jr_addend_8006956C >> 2) {
        case 0: goto L_80069574; break;
        case 1: goto L_80069574; break;
        case 2: goto L_80069598; break;
        case 3: goto L_800695B0; break;
        case 4: goto L_800695C8; break;
        case 5: goto L_800695E0; break;
        case 6: goto L_800695F8; break;
        case 7: goto L_80069610; break;
        default: switch_error(__func__, 0x8006956C, 0x800DD604);
    }
    // 0x80069570: nop

L_80069574:
    // 0x80069574: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80069578: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006957C: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x80069580: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80069584: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80069588: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
    // 0x8006958C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80069590: b           L_8006963C
    // 0x80069594: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
        goto L_8006963C;
    // 0x80069594: sb          $t1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r9;
L_80069598:
    // 0x80069598: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006959C: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x800695A0: jal         0x80068FF0
    // 0x800695A4: nop

    LineEffect_State2_SpawnColumnCubes(rdram, ctx);
        goto after_0;
    // 0x800695A4: nop

    after_0:
    // 0x800695A8: b           L_8006963C
    // 0x800695AC: nop

        goto L_8006963C;
    // 0x800695AC: nop

L_800695B0:
    // 0x800695B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800695B4: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x800695B8: jal         0x800690E4
    // 0x800695BC: nop

    LineEffect_State3_SwapCubes(rdram, ctx);
        goto after_1;
    // 0x800695BC: nop

    after_1:
    // 0x800695C0: b           L_8006963C
    // 0x800695C4: nop

        goto L_8006963C;
    // 0x800695C4: nop

L_800695C8:
    // 0x800695C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800695CC: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x800695D0: jal         0x80069160
    // 0x800695D4: nop

    LineEffect_State4_DelayedClear(rdram, ctx);
        goto after_2;
    // 0x800695D4: nop

    after_2:
    // 0x800695D8: b           L_8006963C
    // 0x800695DC: nop

        goto L_8006963C;
    // 0x800695DC: nop

L_800695E0:
    // 0x800695E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800695E4: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x800695E8: jal         0x800692FC
    // 0x800695EC: nop

    LineEffect_State5_SetupFade(rdram, ctx);
        goto after_3;
    // 0x800695EC: nop

    after_3:
    // 0x800695F0: b           L_8006963C
    // 0x800695F4: nop

        goto L_8006963C;
    // 0x800695F4: nop

L_800695F8:
    // 0x800695F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800695FC: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x80069600: jal         0x8006942C
    // 0x80069604: nop

    LineEffect_State6_HoldCountdown(rdram, ctx);
        goto after_4;
    // 0x80069604: nop

    after_4:
    // 0x80069608: b           L_8006963C
    // 0x8006960C: nop

        goto L_8006963C;
    // 0x8006960C: nop

L_80069610:
    // 0x80069610: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80069614: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x80069618: jal         0x800694B0
    // 0x8006961C: nop

    LineEffect_State7_SwapCubes(rdram, ctx);
        goto after_5;
    // 0x8006961C: nop

    after_5:
    // 0x80069620: b           L_8006963C
    // 0x80069624: nop

        goto L_8006963C;
    // 0x80069624: nop

L_80069628:
    // 0x80069628: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006962C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80069630: addiu       $a1, $a1, -0x2A50
    ctx->r5 = ADD32(ctx->r5, -0X2A50);
    // 0x80069634: jal         0x80083560
    // 0x80069638: addiu       $a0, $a0, -0x2A60
    ctx->r4 = ADD32(ctx->r4, -0X2A60);
    debug_print_reason_routine(rdram, ctx);
        goto after_6;
    // 0x80069638: addiu       $a0, $a0, -0x2A60
    ctx->r4 = ADD32(ctx->r4, -0X2A60);
    after_6:
L_8006963C:
    // 0x8006963C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80069640: nop

    // 0x80069644: lbu         $t4, 0x3($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X3);
    // 0x80069648: nop

    // 0x8006964C: beq         $t4, $zero, L_8006953C
    if (ctx->r12 == 0) {
        // 0x80069650: nop
    
            goto L_8006953C;
    }
    // 0x80069650: nop

    // 0x80069654: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80069658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006965C: lbu         $v0, 0x2($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X2);
    // 0x80069660: jr          $ra
    // 0x80069664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80069664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void LineEffect_ResetIdle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069668: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006966C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80069670: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80069674: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80069678: sb          $t6, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r14;
    // 0x8006967C: jr          $ra
    // 0x80069680: sb          $t7, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r15;
    return;
    // 0x80069680: sb          $t7, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void LineEffect_BeginState0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069684: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80069688: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006968C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80069690: sb          $t6, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r14;
    // 0x80069694: jr          $ra
    // 0x80069698: sb          $t7, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r15;
    return;
    // 0x80069698: sb          $t7, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void LineEffect_BeginState2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006969C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800696A0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800696A4: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800696A8: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x800696AC: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x800696B0: jr          $ra
    // 0x800696B4: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    return;
    // 0x800696B4: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
;}

RECOMP_FUNC void LineEffect_BeginState4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800696B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800696BC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800696C0: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800696C4: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x800696C8: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x800696CC: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    // 0x800696D0: jr          $ra
    // 0x800696D4: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    return;
    // 0x800696D4: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
;}

RECOMP_FUNC void LineEffect_BeginState5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800696D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800696DC: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800696E0: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800696E4: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x800696E8: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x800696EC: jr          $ra
    // 0x800696F0: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    return;
    // 0x800696F0: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
;}

RECOMP_FUNC void LineEffect_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800696F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800696F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800696FC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80069700: lbu         $t6, 0x33($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X33);
    // 0x80069704: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80069708: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006970C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80069710: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80069714: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80069718: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    // 0x8006971C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80069720: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069724: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80069728: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8006972C: lw          $t8, -0x430($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X430);
    // 0x80069730: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80069734: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80069738: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006973C: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80069740: addu        $s1, $t8, $t1
    ctx->r17 = ADD32(ctx->r24, ctx->r9);
    // 0x80069744: beq         $at, $zero, L_80069770
    if (ctx->r1 == 0) {
        // 0x80069748: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80069770;
    }
    // 0x80069748: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8006974C:
    // 0x8006974C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80069750: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80069754: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80069758: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006975C: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80069760: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80069764: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80069768: bne         $at, $zero, L_8006974C
    if (ctx->r1 != 0) {
        // 0x8006976C: sw          $t2, 0x8($t5)
        MEM_W(0X8, ctx->r13) = ctx->r10;
            goto L_8006974C;
    }
    // 0x8006976C: sw          $t2, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r10;
L_80069770:
    // 0x80069770: lbu         $t6, 0x33($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X33);
    // 0x80069774: nop

    // 0x80069778: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8006977C: beq         $at, $zero, L_800697FC
    if (ctx->r1 == 0) {
        // 0x80069780: nop
    
            goto L_800697FC;
    }
    // 0x80069780: nop

    // 0x80069784: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80069788: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006978C: addu        $at, $at, $t6
    gpr jr_addend_80069798 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80069790: lw          $t6, -0x29DC($at)
    ctx->r14 = ADD32(ctx->r1, -0X29DC);
    // 0x80069794: nop

    // 0x80069798: jr          $t6
    // 0x8006979C: nop

    switch (jr_addend_80069798 >> 2) {
        case 0: goto L_800697A0; break;
        case 1: goto L_800697B4; break;
        case 2: goto L_800697E4; break;
        case 3: goto L_800697E4; break;
        case 4: goto L_800697CC; break;
        default: switch_error(__func__, 0x80069798, 0x800DD624);
    }
    // 0x8006979C: nop

L_800697A0:
    // 0x800697A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800697A4: jal         0x80069684
    // 0x800697A8: nop

    LineEffect_BeginState0(rdram, ctx);
        goto after_0;
    // 0x800697A8: nop

    after_0:
    // 0x800697AC: b           L_80069810
    // 0x800697B0: nop

        goto L_80069810;
    // 0x800697B0: nop

L_800697B4:
    // 0x800697B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800697B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800697BC: jal         0x8006969C
    // 0x800697C0: nop

    LineEffect_BeginState2(rdram, ctx);
        goto after_1;
    // 0x800697C0: nop

    after_1:
    // 0x800697C4: b           L_80069810
    // 0x800697C8: nop

        goto L_80069810;
    // 0x800697C8: nop

L_800697CC:
    // 0x800697CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800697D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800697D4: jal         0x800696B8
    // 0x800697D8: nop

    LineEffect_BeginState4(rdram, ctx);
        goto after_2;
    // 0x800697D8: nop

    after_2:
    // 0x800697DC: b           L_80069810
    // 0x800697E0: nop

        goto L_80069810;
    // 0x800697E0: nop

L_800697E4:
    // 0x800697E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800697E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800697EC: jal         0x800696D8
    // 0x800697F0: nop

    LineEffect_BeginState5(rdram, ctx);
        goto after_3;
    // 0x800697F0: nop

    after_3:
    // 0x800697F4: b           L_80069810
    // 0x800697F8: nop

        goto L_80069810;
    // 0x800697F8: nop

L_800697FC:
    // 0x800697FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80069800: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80069804: addiu       $a1, $a1, -0x2A1C
    ctx->r5 = ADD32(ctx->r5, -0X2A1C);
    // 0x80069808: jal         0x80083560
    // 0x8006980C: addiu       $a0, $a0, -0x2A2C
    ctx->r4 = ADD32(ctx->r4, -0X2A2C);
    debug_print_reason_routine(rdram, ctx);
        goto after_4;
    // 0x8006980C: addiu       $a0, $a0, -0x2A2C
    ctx->r4 = ADD32(ctx->r4, -0X2A2C);
    after_4:
L_80069810:
    // 0x80069810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80069814: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80069818: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006981C: jr          $ra
    // 0x80069820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80069820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80069824: nop

    // 0x80069828: nop

    // 0x8006982C: nop

;}

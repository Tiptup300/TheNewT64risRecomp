#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void CubeTiles_CopyPartialTile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800758B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800758B4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800758B8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800758BC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800758C0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800758C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800758C8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800758CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800758D0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800758D4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800758D8: lbu         $t0, -0x348($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X348);
    // 0x800758DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800758E0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800758E4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800758E8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800758EC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800758F0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800758F4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800758F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800758FC: beq         $t0, $zero, L_80075914
    if (ctx->r8 == 0) {
        // 0x80075900: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80075914;
    }
    // 0x80075900: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80075904: ori         $t1, $s1, 0x1
    ctx->r9 = ctx->r17 | 0X1;
    // 0x80075908: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8007590C: andi        $t2, $s1, 0xFF
    ctx->r10 = ctx->r17 & 0XFF;
    // 0x80075910: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
L_80075914:
    // 0x80075914: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80075918: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8007591C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80075920: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80075924: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80075928: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8007592C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80075930: lbu         $t7, -0x347($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X347);
    // 0x80075934: nop

    // 0x80075938: beq         $t7, $zero, L_80075950
    if (ctx->r15 == 0) {
        // 0x8007593C: nop
    
            goto L_80075950;
    }
    // 0x8007593C: nop

    // 0x80075940: ori         $t8, $s1, 0x2
    ctx->r24 = ctx->r17 | 0X2;
    // 0x80075944: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x80075948: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
    // 0x8007594C: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
L_80075950:
    // 0x80075950: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80075954: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80075958: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8007595C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80075960: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80075964: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80075968: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8007596C: lbu         $t4, -0x345($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X345);
    // 0x80075970: nop

    // 0x80075974: beq         $t4, $zero, L_8007598C
    if (ctx->r12 == 0) {
        // 0x80075978: nop
    
            goto L_8007598C;
    }
    // 0x80075978: nop

    // 0x8007597C: ori         $t5, $s1, 0x4
    ctx->r13 = ctx->r17 | 0X4;
    // 0x80075980: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x80075984: andi        $t6, $s1, 0xFF
    ctx->r14 = ctx->r17 & 0XFF;
    // 0x80075988: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
L_8007598C:
    // 0x8007598C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80075990: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80075994: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80075998: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8007599C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800759A0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800759A4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800759A8: lbu         $t1, -0x344($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X344);
    // 0x800759AC: nop

    // 0x800759B0: beq         $t1, $zero, L_800759C8
    if (ctx->r9 == 0) {
        // 0x800759B4: nop
    
            goto L_800759C8;
    }
    // 0x800759B4: nop

    // 0x800759B8: ori         $t2, $s1, 0x8
    ctx->r10 = ctx->r17 | 0X8;
    // 0x800759BC: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x800759C0: andi        $t3, $s1, 0xFF
    ctx->r11 = ctx->r17 & 0XFF;
    // 0x800759C4: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
L_800759C8:
    // 0x800759C8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800759CC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800759D0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800759D4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800759D8: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x800759DC: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x800759E0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800759E4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800759E8: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x800759EC: lw          $s0, 0x830($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X830);
    // 0x800759F0: nop

    // 0x800759F4: bne         $s0, $zero, L_80075A10
    if (ctx->r16 != 0) {
        // 0x800759F8: nop
    
            goto L_80075A10;
    }
    // 0x800759F8: nop

    // 0x800759FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80075A00: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80075A04: addiu       $a1, $a1, -0x24A0
    ctx->r5 = ADD32(ctx->r5, -0X24A0);
    // 0x80075A08: jal         0x80083560
    // 0x80075A0C: addiu       $a0, $a0, -0x24C0
    ctx->r4 = ADD32(ctx->r4, -0X24C0);
    debug_print_reason_routine(rdram, ctx);
        goto after_0;
    // 0x80075A0C: addiu       $a0, $a0, -0x24C0
    ctx->r4 = ADD32(ctx->r4, -0X24C0);
    after_0:
L_80075A10:
    // 0x80075A10: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80075A14: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80075A18: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x80075A1C: beq         $at, $zero, L_80075A60
    if (ctx->r1 == 0) {
        // 0x80075A20: or          $s2, $s0, $zero
        ctx->r18 = ctx->r16 | 0;
            goto L_80075A60;
    }
    // 0x80075A20: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
L_80075A24:
    // 0x80075A24: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80075A28: slti        $at, $s4, 0x4
    ctx->r1 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
    // 0x80075A2C: beq         $at, $zero, L_80075A50
    if (ctx->r1 == 0) {
        // 0x80075A30: nop
    
            goto L_80075A50;
    }
    // 0x80075A30: nop

L_80075A34:
    // 0x80075A34: lhu         $t1, 0x0($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X0);
    // 0x80075A38: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80075A3C: slti        $at, $s4, 0x4
    ctx->r1 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
    // 0x80075A40: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80075A44: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80075A48: bne         $at, $zero, L_80075A34
    if (ctx->r1 != 0) {
        // 0x80075A4C: sh          $t1, -0x2($s3)
        MEM_H(-0X2, ctx->r19) = ctx->r9;
            goto L_80075A34;
    }
    // 0x80075A4C: sh          $t1, -0x2($s3)
    MEM_H(-0X2, ctx->r19) = ctx->r9;
L_80075A50:
    // 0x80075A50: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80075A54: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x80075A58: bne         $at, $zero, L_80075A24
    if (ctx->r1 != 0) {
        // 0x80075A5C: addiu       $s3, $s3, 0x8
        ctx->r19 = ADD32(ctx->r19, 0X8);
            goto L_80075A24;
    }
    // 0x80075A5C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
L_80075A60:
    // 0x80075A60: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80075A64: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80075A68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80075A6C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80075A70: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80075A74: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80075A78: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80075A7C: jr          $ra
    // 0x80075A80: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80075A80: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void CubeTiles_ApplyEdgeMask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075A84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075A88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80075A8C: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x80075A90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075A94: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x80075A98: beq         $t7, $zero, L_80075AB4
    if (ctx->r15 == 0) {
        // 0x80075A9C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80075AB4;
    }
    // 0x80075A9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80075AA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80075AA4: addiu       $t9, $t9, -0x348
    ctx->r25 = ADD32(ctx->r25, -0X348);
    // 0x80075AA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80075AAC: b           L_80075AC0
    // 0x80075AB0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
        goto L_80075AC0;
    // 0x80075AB0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_80075AB4:
    // 0x80075AB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80075AB8: addiu       $t0, $t0, -0x348
    ctx->r8 = ADD32(ctx->r8, -0X348);
    // 0x80075ABC: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_80075AC0:
    // 0x80075AC0: lbu         $t1, 0x1B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1B);
    // 0x80075AC4: nop

    // 0x80075AC8: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80075ACC: beq         $t2, $zero, L_80075AE8
    if (ctx->r10 == 0) {
        // 0x80075AD0: nop
    
            goto L_80075AE8;
    }
    // 0x80075AD0: nop

    // 0x80075AD4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80075AD8: addiu       $t4, $t4, -0x348
    ctx->r12 = ADD32(ctx->r12, -0X348);
    // 0x80075ADC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80075AE0: b           L_80075AF4
    // 0x80075AE4: sb          $t3, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r11;
        goto L_80075AF4;
    // 0x80075AE4: sb          $t3, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r11;
L_80075AE8:
    // 0x80075AE8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80075AEC: addiu       $t5, $t5, -0x348
    ctx->r13 = ADD32(ctx->r13, -0X348);
    // 0x80075AF0: sb          $zero, 0x1($t5)
    MEM_B(0X1, ctx->r13) = 0;
L_80075AF4:
    // 0x80075AF4: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x80075AF8: nop

    // 0x80075AFC: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80075B00: beq         $t7, $zero, L_80075B1C
    if (ctx->r15 == 0) {
        // 0x80075B04: nop
    
            goto L_80075B1C;
    }
    // 0x80075B04: nop

    // 0x80075B08: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80075B0C: addiu       $t9, $t9, -0x348
    ctx->r25 = ADD32(ctx->r25, -0X348);
    // 0x80075B10: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80075B14: b           L_80075B28
    // 0x80075B18: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
        goto L_80075B28;
    // 0x80075B18: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
L_80075B1C:
    // 0x80075B1C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80075B20: addiu       $t0, $t0, -0x348
    ctx->r8 = ADD32(ctx->r8, -0X348);
    // 0x80075B24: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
L_80075B28:
    // 0x80075B28: lbu         $t1, 0x1B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1B);
    // 0x80075B2C: nop

    // 0x80075B30: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x80075B34: beq         $t2, $zero, L_80075B50
    if (ctx->r10 == 0) {
        // 0x80075B38: nop
    
            goto L_80075B50;
    }
    // 0x80075B38: nop

    // 0x80075B3C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80075B40: addiu       $t4, $t4, -0x348
    ctx->r12 = ADD32(ctx->r12, -0X348);
    // 0x80075B44: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80075B48: b           L_80075B5C
    // 0x80075B4C: sb          $t3, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r11;
        goto L_80075B5C;
    // 0x80075B4C: sb          $t3, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r11;
L_80075B50:
    // 0x80075B50: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80075B54: addiu       $t5, $t5, -0x348
    ctx->r13 = ADD32(ctx->r13, -0X348);
    // 0x80075B58: sb          $zero, 0x3($t5)
    MEM_B(0X3, ctx->r13) = 0;
L_80075B5C:
    // 0x80075B5C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80075B60: addiu       $t7, $t7, -0x348
    ctx->r15 = ADD32(ctx->r15, -0X348);
    // 0x80075B64: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80075B68: sb          $t6, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r14;
    // 0x80075B6C: lbu         $t8, 0x1B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1B);
    // 0x80075B70: nop

    // 0x80075B74: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x80075B78: beq         $t9, $zero, L_80075B94
    if (ctx->r25 == 0) {
        // 0x80075B7C: nop
    
            goto L_80075B94;
    }
    // 0x80075B7C: nop

    // 0x80075B80: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80075B84: addiu       $t1, $t1, -0x348
    ctx->r9 = ADD32(ctx->r9, -0X348);
    // 0x80075B88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80075B8C: b           L_80075BA0
    // 0x80075B90: sb          $t0, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r8;
        goto L_80075BA0;
    // 0x80075B90: sb          $t0, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r8;
L_80075B94:
    // 0x80075B94: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80075B98: addiu       $t2, $t2, -0x348
    ctx->r10 = ADD32(ctx->r10, -0X348);
    // 0x80075B9C: sb          $zero, 0x5($t2)
    MEM_B(0X5, ctx->r10) = 0;
L_80075BA0:
    // 0x80075BA0: lbu         $t3, 0x1B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1B);
    // 0x80075BA4: nop

    // 0x80075BA8: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x80075BAC: beq         $t4, $zero, L_80075BC8
    if (ctx->r12 == 0) {
        // 0x80075BB0: nop
    
            goto L_80075BC8;
    }
    // 0x80075BB0: nop

    // 0x80075BB4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80075BB8: addiu       $t6, $t6, -0x348
    ctx->r14 = ADD32(ctx->r14, -0X348);
    // 0x80075BBC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80075BC0: b           L_80075BD4
    // 0x80075BC4: sb          $t5, 0x6($t6)
    MEM_B(0X6, ctx->r14) = ctx->r13;
        goto L_80075BD4;
    // 0x80075BC4: sb          $t5, 0x6($t6)
    MEM_B(0X6, ctx->r14) = ctx->r13;
L_80075BC8:
    // 0x80075BC8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80075BCC: addiu       $t7, $t7, -0x348
    ctx->r15 = ADD32(ctx->r15, -0X348);
    // 0x80075BD0: sb          $zero, 0x6($t7)
    MEM_B(0X6, ctx->r15) = 0;
L_80075BD4:
    // 0x80075BD4: lbu         $t8, 0x1B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1B);
    // 0x80075BD8: nop

    // 0x80075BDC: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x80075BE0: beq         $t9, $zero, L_80075BFC
    if (ctx->r25 == 0) {
        // 0x80075BE4: nop
    
            goto L_80075BFC;
    }
    // 0x80075BE4: nop

    // 0x80075BE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80075BEC: addiu       $t1, $t1, -0x348
    ctx->r9 = ADD32(ctx->r9, -0X348);
    // 0x80075BF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80075BF4: b           L_80075C08
    // 0x80075BF8: sb          $t0, 0x7($t1)
    MEM_B(0X7, ctx->r9) = ctx->r8;
        goto L_80075C08;
    // 0x80075BF8: sb          $t0, 0x7($t1)
    MEM_B(0X7, ctx->r9) = ctx->r8;
L_80075BFC:
    // 0x80075BFC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80075C00: addiu       $t2, $t2, -0x348
    ctx->r10 = ADD32(ctx->r10, -0X348);
    // 0x80075C04: sb          $zero, 0x7($t2)
    MEM_B(0X7, ctx->r10) = 0;
L_80075C08:
    // 0x80075C08: lbu         $t3, 0x1B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1B);
    // 0x80075C0C: nop

    // 0x80075C10: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x80075C14: beq         $t4, $zero, L_80075C30
    if (ctx->r12 == 0) {
        // 0x80075C18: nop
    
            goto L_80075C30;
    }
    // 0x80075C18: nop

    // 0x80075C1C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80075C20: addiu       $t6, $t6, -0x348
    ctx->r14 = ADD32(ctx->r14, -0X348);
    // 0x80075C24: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80075C28: b           L_80075C3C
    // 0x80075C2C: sb          $t5, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r13;
        goto L_80075C3C;
    // 0x80075C2C: sb          $t5, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r13;
L_80075C30:
    // 0x80075C30: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80075C34: addiu       $t7, $t7, -0x348
    ctx->r15 = ADD32(ctx->r15, -0X348);
    // 0x80075C38: sb          $zero, 0x8($t7)
    MEM_B(0X8, ctx->r15) = 0;
L_80075C3C:
    // 0x80075C3C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80075C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80075C44: jal         0x800758B0
    // 0x80075C48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    CubeTiles_CopyPartialTile(rdram, ctx);
        goto after_0;
    // 0x80075C48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80075C4C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80075C50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80075C54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80075C58: jal         0x800758B0
    // 0x80075C5C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    CubeTiles_CopyPartialTile(rdram, ctx);
        goto after_1;
    // 0x80075C5C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    after_1:
    // 0x80075C60: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80075C64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80075C68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80075C6C: jal         0x800758B0
    // 0x80075C70: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    CubeTiles_CopyPartialTile(rdram, ctx);
        goto after_2;
    // 0x80075C70: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    after_2:
    // 0x80075C74: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80075C78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80075C7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80075C80: jal         0x800758B0
    // 0x80075C84: addiu       $a2, $a2, 0x48
    ctx->r6 = ADD32(ctx->r6, 0X48);
    CubeTiles_CopyPartialTile(rdram, ctx);
        goto after_3;
    // 0x80075C84: addiu       $a2, $a2, 0x48
    ctx->r6 = ADD32(ctx->r6, 0X48);
    after_3:
    // 0x80075C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075C8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075C90: jr          $ra
    // 0x80075C94: nop

    return;
    // 0x80075C94: nop

;}

RECOMP_FUNC void CubeTiles_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075C98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80075C9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80075CA0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80075CA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80075CA8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80075CAC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80075CB0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80075CB4: slti        $at, $s1, 0x100
    ctx->r1 = SIGNED(ctx->r17) < 0X100 ? 1 : 0;
    // 0x80075CB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80075CBC: beq         $at, $zero, L_80075D7C
    if (ctx->r1 == 0) {
        // 0x80075CC0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80075D7C;
    }
    // 0x80075CC0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80075CC4:
    // 0x80075CC4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80075CC8: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80075CCC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80075CD0: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x80075CD4: andi        $t9, $s1, 0x80
    ctx->r25 = ctx->r17 & 0X80;
    // 0x80075CD8: beq         $t9, $zero, L_80075CEC
    if (ctx->r25 == 0) {
        // 0x80075CDC: sw          $t6, 0x5C01($at)
        MEM_W(0X5C01, ctx->r1) = ctx->r14;
            goto L_80075CEC;
    }
    // 0x80075CDC: sw          $t6, 0x5C01($at)
    MEM_W(0X5C01, ctx->r1) = ctx->r14;
    // 0x80075CE0: andi        $t0, $s1, 0x9
    ctx->r8 = ctx->r17 & 0X9;
    // 0x80075CE4: beq         $t0, $zero, L_80075D64
    if (ctx->r8 == 0) {
        // 0x80075CE8: nop
    
            goto L_80075D64;
    }
    // 0x80075CE8: nop

L_80075CEC:
    // 0x80075CEC: andi        $t1, $s1, 0x10
    ctx->r9 = ctx->r17 & 0X10;
    // 0x80075CF0: beq         $t1, $zero, L_80075D04
    if (ctx->r9 == 0) {
        // 0x80075CF4: nop
    
            goto L_80075D04;
    }
    // 0x80075CF4: nop

    // 0x80075CF8: andi        $t2, $s1, 0x3
    ctx->r10 = ctx->r17 & 0X3;
    // 0x80075CFC: beq         $t2, $zero, L_80075D64
    if (ctx->r10 == 0) {
        // 0x80075D00: nop
    
            goto L_80075D64;
    }
    // 0x80075D00: nop

L_80075D04:
    // 0x80075D04: andi        $t3, $s1, 0x40
    ctx->r11 = ctx->r17 & 0X40;
    // 0x80075D08: beq         $t3, $zero, L_80075D1C
    if (ctx->r11 == 0) {
        // 0x80075D0C: nop
    
            goto L_80075D1C;
    }
    // 0x80075D0C: nop

    // 0x80075D10: andi        $t4, $s1, 0xC
    ctx->r12 = ctx->r17 & 0XC;
    // 0x80075D14: beq         $t4, $zero, L_80075D64
    if (ctx->r12 == 0) {
        // 0x80075D18: nop
    
            goto L_80075D64;
    }
    // 0x80075D18: nop

L_80075D1C:
    // 0x80075D1C: andi        $t5, $s1, 0x20
    ctx->r13 = ctx->r17 & 0X20;
    // 0x80075D20: beq         $t5, $zero, L_80075D34
    if (ctx->r13 == 0) {
        // 0x80075D24: nop
    
            goto L_80075D34;
    }
    // 0x80075D24: nop

    // 0x80075D28: andi        $t7, $s1, 0x6
    ctx->r15 = ctx->r17 & 0X6;
    // 0x80075D2C: beq         $t7, $zero, L_80075D64
    if (ctx->r15 == 0) {
        // 0x80075D30: nop
    
            goto L_80075D64;
    }
    // 0x80075D30: nop

L_80075D34:
    // 0x80075D34: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80075D38: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80075D3C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80075D40: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80075D44: sw          $s0, 0x5C01($at)
    MEM_W(0X5C01, ctx->r1) = ctx->r16;
    // 0x80075D48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80075D4C: jal         0x80075A84
    // 0x80075D50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    CubeTiles_ApplyEdgeMask(rdram, ctx);
        goto after_0;
    // 0x80075D50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80075D54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80075D58: andi        $t0, $s2, 0xFFFF
    ctx->r8 = ctx->r18 & 0XFFFF;
    // 0x80075D5C: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x80075D60: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
L_80075D64:
    // 0x80075D64: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80075D68: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x80075D6C: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80075D70: slti        $at, $s1, 0x100
    ctx->r1 = SIGNED(ctx->r17) < 0X100 ? 1 : 0;
    // 0x80075D74: bne         $at, $zero, L_80075CC4
    if (ctx->r1 != 0) {
        // 0x80075D78: nop
    
            goto L_80075CC4;
    }
    // 0x80075D78: nop

L_80075D7C:
    // 0x80075D7C: slti        $at, $s2, 0xC9
    ctx->r1 = SIGNED(ctx->r18) < 0XC9 ? 1 : 0;
    // 0x80075D80: bne         $at, $zero, L_80075D9C
    if (ctx->r1 != 0) {
        // 0x80075D84: nop
    
            goto L_80075D9C;
    }
    // 0x80075D84: nop

    // 0x80075D88: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80075D8C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80075D90: addiu       $a1, $a1, -0x246C
    ctx->r5 = ADD32(ctx->r5, -0X246C);
    // 0x80075D94: jal         0x80083560
    // 0x80075D98: addiu       $a0, $a0, -0x2494
    ctx->r4 = ADD32(ctx->r4, -0X2494);
    debug_print_reason_routine(rdram, ctx);
        goto after_1;
    // 0x80075D98: addiu       $a0, $a0, -0x2494
    ctx->r4 = ADD32(ctx->r4, -0X2494);
    after_1:
L_80075D9C:
    // 0x80075D9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80075DA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80075DA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80075DA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80075DAC: jr          $ra
    // 0x80075DB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80075DB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void CubeTiles_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075DB4: jr          $ra
    // 0x80075DB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80075DB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

RECOMP_FUNC void CubeTiles_Expand4bitColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075DBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80075DC0: sltiu       $at, $a1, 0x20
    ctx->r1 = ctx->r5 < 0X20 ? 1 : 0;
    // 0x80075DC4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80075DC8: beq         $at, $zero, L_80075DEC
    if (ctx->r1 == 0) {
        // 0x80075DCC: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80075DEC;
    }
    // 0x80075DCC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_80075DD0:
    // 0x80075DD0: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80075DD4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80075DD8: sltiu       $at, $a1, 0x20
    ctx->r1 = ctx->r5 < 0X20 ? 1 : 0;
    // 0x80075DDC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80075DE0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80075DE4: bne         $at, $zero, L_80075DD0
    if (ctx->r1 != 0) {
        // 0x80075DE8: sb          $t7, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r15;
            goto L_80075DD0;
    }
    // 0x80075DE8: sb          $t7, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r15;
L_80075DEC:
    // 0x80075DEC: jr          $ra
    // 0x80075DF0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80075DF0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void CubeTiles_InitColorTables(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075DF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075DFC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E00: jal         0x80075DBC
    // 0x80075E04: addiu       $a0, $a0, 0x690
    ctx->r4 = ADD32(ctx->r4, 0X690);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_0;
    // 0x80075E04: addiu       $a0, $a0, 0x690
    ctx->r4 = ADD32(ctx->r4, 0X690);
    after_0:
    // 0x80075E08: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E0C: jal         0x80075DBC
    // 0x80075E10: addiu       $a0, $a0, 0x6B0
    ctx->r4 = ADD32(ctx->r4, 0X6B0);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_1;
    // 0x80075E10: addiu       $a0, $a0, 0x6B0
    ctx->r4 = ADD32(ctx->r4, 0X6B0);
    after_1:
    // 0x80075E14: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E18: jal         0x80075DBC
    // 0x80075E1C: addiu       $a0, $a0, 0x6F0
    ctx->r4 = ADD32(ctx->r4, 0X6F0);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_2;
    // 0x80075E1C: addiu       $a0, $a0, 0x6F0
    ctx->r4 = ADD32(ctx->r4, 0X6F0);
    after_2:
    // 0x80075E20: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E24: jal         0x80075DBC
    // 0x80075E28: addiu       $a0, $a0, 0x6D0
    ctx->r4 = ADD32(ctx->r4, 0X6D0);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_3;
    // 0x80075E28: addiu       $a0, $a0, 0x6D0
    ctx->r4 = ADD32(ctx->r4, 0X6D0);
    after_3:
    // 0x80075E2C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E30: jal         0x80075DBC
    // 0x80075E34: addiu       $a0, $a0, 0x710
    ctx->r4 = ADD32(ctx->r4, 0X710);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_4;
    // 0x80075E34: addiu       $a0, $a0, 0x710
    ctx->r4 = ADD32(ctx->r4, 0X710);
    after_4:
    // 0x80075E38: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E3C: jal         0x80075DBC
    // 0x80075E40: addiu       $a0, $a0, 0x730
    ctx->r4 = ADD32(ctx->r4, 0X730);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_5;
    // 0x80075E40: addiu       $a0, $a0, 0x730
    ctx->r4 = ADD32(ctx->r4, 0X730);
    after_5:
    // 0x80075E44: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E48: jal         0x80075DBC
    // 0x80075E4C: addiu       $a0, $a0, 0x750
    ctx->r4 = ADD32(ctx->r4, 0X750);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_6;
    // 0x80075E4C: addiu       $a0, $a0, 0x750
    ctx->r4 = ADD32(ctx->r4, 0X750);
    after_6:
    // 0x80075E50: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E54: jal         0x80075DBC
    // 0x80075E58: addiu       $a0, $a0, 0x770
    ctx->r4 = ADD32(ctx->r4, 0X770);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_7;
    // 0x80075E58: addiu       $a0, $a0, 0x770
    ctx->r4 = ADD32(ctx->r4, 0X770);
    after_7:
    // 0x80075E5C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E60: jal         0x80075DBC
    // 0x80075E64: addiu       $a0, $a0, 0x790
    ctx->r4 = ADD32(ctx->r4, 0X790);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_8;
    // 0x80075E64: addiu       $a0, $a0, 0x790
    ctx->r4 = ADD32(ctx->r4, 0X790);
    after_8:
    // 0x80075E68: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E6C: jal         0x80075DBC
    // 0x80075E70: addiu       $a0, $a0, 0x7F0
    ctx->r4 = ADD32(ctx->r4, 0X7F0);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_9;
    // 0x80075E70: addiu       $a0, $a0, 0x7F0
    ctx->r4 = ADD32(ctx->r4, 0X7F0);
    after_9:
    // 0x80075E74: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E78: jal         0x80075DBC
    // 0x80075E7C: addiu       $a0, $a0, 0x810
    ctx->r4 = ADD32(ctx->r4, 0X810);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_10;
    // 0x80075E7C: addiu       $a0, $a0, 0x810
    ctx->r4 = ADD32(ctx->r4, 0X810);
    after_10:
    // 0x80075E80: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E84: jal         0x80075DBC
    // 0x80075E88: addiu       $a0, $a0, 0x7B0
    ctx->r4 = ADD32(ctx->r4, 0X7B0);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_11;
    // 0x80075E88: addiu       $a0, $a0, 0x7B0
    ctx->r4 = ADD32(ctx->r4, 0X7B0);
    after_11:
    // 0x80075E8C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80075E90: jal         0x80075DBC
    // 0x80075E94: addiu       $a0, $a0, 0x7D0
    ctx->r4 = ADD32(ctx->r4, 0X7D0);
    CubeTiles_Expand4bitColors(rdram, ctx);
        goto after_12;
    // 0x80075E94: addiu       $a0, $a0, 0x7D0
    ctx->r4 = ADD32(ctx->r4, 0X7D0);
    after_12:
    // 0x80075E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075EA0: jr          $ra
    // 0x80075EA4: nop

    return;
    // 0x80075EA4: nop

    // 0x80075EA8: nop

    // 0x80075EAC: nop

;}

RECOMP_FUNC void CubeTiles_Alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075EB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80075EB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80075EB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80075EBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80075EC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80075EC4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80075EC8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80075ECC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80075ED0: jal         0x80075700
    // 0x80075ED4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    ImageRect_SetDims(rdram, ctx);
        goto after_0;
    // 0x80075ED4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_0:
    // 0x80075ED8: jal         0x8004A34C
    // 0x80075EDC: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_1;
    // 0x80075EDC: nop

    after_1:
    // 0x80075EE0: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80075EE4: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x80075EE8: jal         0x80074888
    // 0x80075EEC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_2;
    // 0x80075EEC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x80075EF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80075EF4: jal         0x8007E03C
    // 0x80075EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x80075EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80075EFC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80075F00: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80075F04: sw          $v0, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r2;
    // 0x80075F08: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80075F0C: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x80075F10: lw          $a1, 0x64($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X64);
    // 0x80075F14: jal         0x800746C0
    // 0x80075F18: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_4;
    // 0x80075F18: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_4:
    // 0x80075F1C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80075F20: jal         0x80075830
    // 0x80075F24: nop

    ImageRect_Init(rdram, ctx);
        goto after_5;
    // 0x80075F24: nop

    after_5:
    // 0x80075F28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80075F2C: jal         0x80075760
    // 0x80075F30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ImageRect_SetMode(rdram, ctx);
        goto after_6;
    // 0x80075F30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80075F34: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80075F38: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80075F3C: lw          $a1, 0x64($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X64);
    // 0x80075F40: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x80075F44: jal         0x800757BC
    // 0x80075F48: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    ImageRect_SetSource(rdram, ctx);
        goto after_7;
    // 0x80075F48: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_7:
    // 0x80075F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80075F50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80075F54: jr          $ra
    // 0x80075F58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80075F58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void CubeTiles_Free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075F5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075F60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80075F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075F68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80075F6C: jal         0x80075870
    // 0x80075F70: nop

    ImageRect_Reset(rdram, ctx);
        goto after_0;
    // 0x80075F70: nop

    after_0:
    // 0x80075F74: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80075F78: nop

    // 0x80075F7C: lw          $a0, 0x64($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X64);
    // 0x80075F80: jal         0x8007E328
    // 0x80075F84: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x80075F84: nop

    after_1:
    // 0x80075F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075F90: jr          $ra
    // 0x80075F94: nop

    return;
    // 0x80075F94: nop

    // 0x80075F98: nop

    // 0x80075F9C: nop

;}

RECOMP_FUNC void CubeTiles_ResetGridOffset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075FA0: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80075FA4: jr          $ra
    // 0x80075FA8: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    return;
    // 0x80075FA8: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
;}

RECOMP_FUNC void CubeTiles_RandomizeField(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075FAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80075FB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075FB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80075FB8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_80075FBC:
    // 0x80075FBC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80075FC0:
    // 0x80075FC0: jal         0x80060814
    // 0x80075FC4: nop

    Rand_Next(rdram, ctx);
        goto after_0;
    // 0x80075FC4: nop

    after_0:
    // 0x80075FC8: lui         $at, 0x1F
    ctx->r1 = S32(0X1F << 16);
    // 0x80075FCC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80075FD0: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x80075FD4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80075FD8: lui         $at, 0xFFF0
    ctx->r1 = S32(0XFFF0 << 16);
    // 0x80075FDC: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80075FE0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80075FE4: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80075FE8: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x80075FEC: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80075FF0: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80075FF4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80075FF8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80075FFC: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x80076000: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80076004: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80076008: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8007600C: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80076010: mflo        $t1
    ctx->r9 = lo;
    // 0x80076014: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x80076018: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8007601C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80076020: nop

    // 0x80076024: subu        $t1, $t2, $t7
    ctx->r9 = SUB32(ctx->r10, ctx->r15);
    // 0x80076028: bgez        $t1, L_80076038
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8007602C: sra         $t4, $t1, 5
        ctx->r12 = S32(SIGNED(ctx->r9) >> 5);
            goto L_80076038;
    }
    // 0x8007602C: sra         $t4, $t1, 5
    ctx->r12 = S32(SIGNED(ctx->r9) >> 5);
    // 0x80076030: addiu       $at, $t1, 0x1F
    ctx->r1 = ADD32(ctx->r9, 0X1F);
    // 0x80076034: sra         $t4, $at, 5
    ctx->r12 = S32(SIGNED(ctx->r1) >> 5);
L_80076038:
    // 0x80076038: jal         0x80060814
    // 0x8007603C: sw          $t4, 0xC00($t0)
    MEM_W(0XC00, ctx->r8) = ctx->r12;
    Rand_Next(rdram, ctx);
        goto after_1;
    // 0x8007603C: sw          $t4, 0xC00($t0)
    MEM_W(0XC00, ctx->r8) = ctx->r12;
    after_1:
    // 0x80076040: lui         $at, 0x1F
    ctx->r1 = S32(0X1F << 16);
    // 0x80076044: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80076048: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x8007604C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80076050: lui         $at, 0xFFF0
    ctx->r1 = S32(0XFFF0 << 16);
    // 0x80076054: addu        $t5, $t3, $at
    ctx->r13 = ADD32(ctx->r11, ctx->r1);
    // 0x80076058: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8007605C: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x80076060: addu        $t9, $t6, $at
    ctx->r25 = ADD32(ctx->r14, ctx->r1);
    // 0x80076064: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80076068: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8007606C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80076070: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80076074: sll         $t4, $t8, 6
    ctx->r12 = S32(ctx->r24 << 6);
    // 0x80076078: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8007607C: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80076080: addu        $t0, $t1, $t4
    ctx->r8 = ADD32(ctx->r9, ctx->r12);
    // 0x80076084: addu        $t9, $t0, $t6
    ctx->r25 = ADD32(ctx->r8, ctx->r14);
    // 0x80076088: mflo        $t2
    ctx->r10 = lo;
    // 0x8007608C: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x80076090: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80076094: lw          $t5, 0x600($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X600);
    // 0x80076098: nop

    // 0x8007609C: subu        $t2, $t7, $t5
    ctx->r10 = SUB32(ctx->r15, ctx->r13);
    // 0x800760A0: bgez        $t2, L_800760B0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800760A4: sra         $t8, $t2, 5
        ctx->r24 = S32(SIGNED(ctx->r10) >> 5);
            goto L_800760B0;
    }
    // 0x800760A4: sra         $t8, $t2, 5
    ctx->r24 = S32(SIGNED(ctx->r10) >> 5);
    // 0x800760A8: addiu       $at, $t2, 0x1F
    ctx->r1 = ADD32(ctx->r10, 0X1F);
    // 0x800760AC: sra         $t8, $at, 5
    ctx->r24 = S32(SIGNED(ctx->r1) >> 5);
L_800760B0:
    // 0x800760B0: sw          $t8, 0x1200($t9)
    MEM_W(0X1200, ctx->r25) = ctx->r24;
    // 0x800760B4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800760B8: nop

    // 0x800760BC: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x800760C0: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x800760C4: bne         $at, $zero, L_80075FC0
    if (ctx->r1 != 0) {
        // 0x800760C8: sw          $t4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r12;
            goto L_80075FC0;
    }
    // 0x800760C8: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800760CC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800760D0: nop

    // 0x800760D4: addiu       $t0, $t3, 0x1
    ctx->r8 = ADD32(ctx->r11, 0X1);
    // 0x800760D8: slti        $at, $t0, 0x18
    ctx->r1 = SIGNED(ctx->r8) < 0X18 ? 1 : 0;
    // 0x800760DC: bne         $at, $zero, L_80075FBC
    if (ctx->r1 != 0) {
        // 0x800760E0: sw          $t0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r8;
            goto L_80075FBC;
    }
    // 0x800760E0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800760E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800760E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800760EC: jr          $ra
    // 0x800760F0: nop

    return;
    // 0x800760F0: nop

;}

RECOMP_FUNC void CubeTiles_InitField(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800760F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800760F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800760FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80076100: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80076104:
    // 0x80076104: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80076108:
    // 0x80076108: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007610C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80076110: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80076114: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x80076118: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8007611C: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80076120: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80076124: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80076128: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x8007612C: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x80076130: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80076134: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80076138: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8007613C: mflo        $t9
    ctx->r25 = lo;
    // 0x80076140: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x80076144: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80076148: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8007614C: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x80076150: addu        $t1, $t8, $at
    ctx->r9 = ADD32(ctx->r24, ctx->r1);
    // 0x80076154: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80076158: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8007615C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80076160: sll         $t6, $t7, 6
    ctx->r14 = S32(ctx->r15 << 6);
    // 0x80076164: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80076168: addu        $t3, $t2, $t6
    ctx->r11 = ADD32(ctx->r10, ctx->r14);
    // 0x8007616C: addu        $t5, $t3, $t9
    ctx->r13 = ADD32(ctx->r11, ctx->r25);
    // 0x80076170: mflo        $t0
    ctx->r8 = lo;
    // 0x80076174: sw          $t0, 0x600($t5)
    MEM_W(0X600, ctx->r13) = ctx->r8;
    // 0x80076178: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007617C: nop

    // 0x80076180: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80076184: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x80076188: bne         $at, $zero, L_80076108
    if (ctx->r1 != 0) {
        // 0x8007618C: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_80076108;
    }
    // 0x8007618C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80076190: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80076194: nop

    // 0x80076198: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8007619C: slti        $at, $t2, 0x18
    ctx->r1 = SIGNED(ctx->r10) < 0X18 ? 1 : 0;
    // 0x800761A0: bne         $at, $zero, L_80076104
    if (ctx->r1 != 0) {
        // 0x800761A4: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_80076104;
    }
    // 0x800761A4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800761A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800761AC: jal         0x80075FAC
    // 0x800761B0: nop

    CubeTiles_RandomizeField(rdram, ctx);
        goto after_0;
    // 0x800761B0: nop

    after_0:
    // 0x800761B4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800761B8: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800761BC: sb          $t6, 0x1800($t4)
    MEM_B(0X1800, ctx->r12) = ctx->r14;
    // 0x800761C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800761C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800761C8: jr          $ra
    // 0x800761CC: nop

    return;
    // 0x800761CC: nop

;}

RECOMP_FUNC void CubeTiles_AdvanceField(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800761D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800761D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800761D8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800761DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800761E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800761E4: blez        $t6, L_800762DC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800761E8: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_800762DC;
    }
    // 0x800761E8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800761EC:
    // 0x800761EC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800761F0:
    // 0x800761F0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800761F4:
    // 0x800761F4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800761F8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800761FC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80076200: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x80076204: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80076208: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8007620C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80076210: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80076214: lw          $t5, 0xC00($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC00);
    // 0x80076218: nop

    // 0x8007621C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80076220: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80076224: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80076228: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007622C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80076230: sll         $t9, $t7, 6
    ctx->r25 = S32(ctx->r15 << 6);
    // 0x80076234: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80076238: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8007623C: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x80076240: lw          $t5, 0x600($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X600);
    // 0x80076244: lw          $t6, 0x1200($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X1200);
    // 0x80076248: nop

    // 0x8007624C: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x80076250: sw          $t3, 0x600($t4)
    MEM_W(0X600, ctx->r12) = ctx->r11;
    // 0x80076254: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80076258: nop

    // 0x8007625C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80076260: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x80076264: bne         $at, $zero, L_800761F4
    if (ctx->r1 != 0) {
        // 0x80076268: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_800761F4;
    }
    // 0x80076268: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8007626C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80076270: nop

    // 0x80076274: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80076278: slti        $at, $t0, 0x18
    ctx->r1 = SIGNED(ctx->r8) < 0X18 ? 1 : 0;
    // 0x8007627C: bne         $at, $zero, L_800761F0
    if (ctx->r1 != 0) {
        // 0x80076280: sw          $t0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r8;
            goto L_800761F0;
    }
    // 0x80076280: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80076284: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80076288: nop

    // 0x8007628C: lbu         $t2, 0x1800($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1800);
    // 0x80076290: nop

    // 0x80076294: addiu       $t5, $t2, -0x1
    ctx->r13 = ADD32(ctx->r10, -0X1);
    // 0x80076298: sb          $t5, 0x1800($t1)
    MEM_B(0X1800, ctx->r9) = ctx->r13;
    // 0x8007629C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800762A0: nop

    // 0x800762A4: lbu         $t3, 0x1800($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X1800);
    // 0x800762A8: nop

    // 0x800762AC: bne         $t3, $zero, L_800762C8
    if (ctx->r11 != 0) {
        // 0x800762B0: nop
    
            goto L_800762C8;
    }
    // 0x800762B0: nop

    // 0x800762B4: jal         0x80075FAC
    // 0x800762B8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    CubeTiles_RandomizeField(rdram, ctx);
        goto after_0;
    // 0x800762B8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x800762BC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800762C0: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x800762C4: sb          $t4, 0x1800($t7)
    MEM_B(0X1800, ctx->r15) = ctx->r12;
L_800762C8:
    // 0x800762C8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800762CC: nop

    // 0x800762D0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800762D4: bgtz        $t9, L_800761EC
    if (SIGNED(ctx->r25) > 0) {
        // 0x800762D8: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_800761EC;
    }
    // 0x800762D8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_800762DC:
    // 0x800762DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800762E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800762E4: jr          $ra
    // 0x800762E8: nop

    return;
    // 0x800762E8: nop

;}

RECOMP_FUNC void CubeTiles_SampleField(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800762EC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800762F0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800762F4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800762F8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800762FC: sra         $t8, $a2, 8
    ctx->r24 = S32(SIGNED(ctx->r6) >> 8);
    // 0x80076300: sra         $t6, $a1, 8
    ctx->r14 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80076304: addiu       $t9, $t8, 0xB
    ctx->r25 = ADD32(ctx->r24, 0XB);
    // 0x80076308: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007630C: addiu       $t7, $t6, 0x6
    ctx->r15 = ADD32(ctx->r14, 0X6);
    // 0x80076310: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x80076314: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x80076318: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x8007631C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80076320: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x80076324: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80076328: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8007632C: nop

    // 0x80076330: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80076334: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x80076338: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8007633C: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x80076340: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x80076344: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80076348: addu        $t7, $t8, $t0
    ctx->r15 = ADD32(ctx->r24, ctx->r8);
    // 0x8007634C: lw          $t1, 0x600($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X600);
    // 0x80076350: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80076354: jr          $ra
    // 0x80076358: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    return;
    // 0x80076358: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
;}

RECOMP_FUNC void CubeTiles_AllocGrid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007635C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076364: jal         0x8007E03C
    // 0x80076368: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80076368: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x8007636C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80076370: sw          $v0, -0x330($at)
    MEM_W(-0X330, ctx->r1) = ctx->r2;
    // 0x80076374: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076378: lw          $a0, -0x330($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X330);
    // 0x8007637C: jal         0x80075FA0
    // 0x80076380: nop

    CubeTiles_ResetGridOffset(rdram, ctx);
        goto after_1;
    // 0x80076380: nop

    after_1:
    // 0x80076384: jal         0x8007E03C
    // 0x80076388: addiu       $a0, $zero, 0x1804
    ctx->r4 = ADD32(0, 0X1804);
    n64HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80076388: addiu       $a0, $zero, 0x1804
    ctx->r4 = ADD32(0, 0X1804);
    after_2:
    // 0x8007638C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80076390: sw          $v0, -0x32C($at)
    MEM_W(-0X32C, ctx->r1) = ctx->r2;
    // 0x80076394: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076398: lw          $a0, -0x32C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X32C);
    // 0x8007639C: jal         0x800760F4
    // 0x800763A0: nop

    CubeTiles_InitField(rdram, ctx);
        goto after_3;
    // 0x800763A0: nop

    after_3:
    // 0x800763A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800763A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800763AC: jr          $ra
    // 0x800763B0: nop

    return;
    // 0x800763B0: nop

;}

RECOMP_FUNC void CubeTiles_FreeGrid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800763B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800763B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800763BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800763C0: lw          $a0, -0x330($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X330);
    // 0x800763C4: jal         0x8007E328
    // 0x800763C8: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800763C8: nop

    after_0:
    // 0x800763CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800763D0: lw          $a0, -0x32C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X32C);
    // 0x800763D4: jal         0x8007E328
    // 0x800763D8: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x800763D8: nop

    after_1:
    // 0x800763DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800763E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800763E4: jr          $ra
    // 0x800763E8: nop

    return;
    // 0x800763E8: nop

;}

RECOMP_FUNC void CubeTiles_UpdateGrid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800763EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800763F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800763F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800763F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800763FC: lw          $a0, -0x32C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X32C);
    // 0x80076400: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80076404: jal         0x800761D0
    // 0x80076408: nop

    CubeTiles_AdvanceField(rdram, ctx);
        goto after_0;
    // 0x80076408: nop

    after_0:
    // 0x8007640C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076414: jr          $ra
    // 0x80076418: nop

    return;
    // 0x80076418: nop

;}

RECOMP_FUNC void CubeTiles_TileCoordsToPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007641C: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80076420: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80076424: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80076428: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007642C: sll         $t7, $t7, 9
    ctx->r15 = S32(ctx->r15 << 9);
    // 0x80076430: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x80076434: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80076438: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8007643C: nop

    // 0x80076440: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80076444: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80076448: sll         $t0, $t0, 9
    ctx->r8 = S32(ctx->r8 << 9);
    // 0x8007644C: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x80076450: jr          $ra
    // 0x80076454: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    return;
    // 0x80076454: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
;}

RECOMP_FUNC void CubeTiles_SampleTile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076458: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007645C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80076460: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80076464: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80076468: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007646C: lw          $t6, -0x32C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X32C);
    // 0x80076470: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80076474: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80076478: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8007647C: lh          $a2, 0x2($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X2);
    // 0x80076480: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x80076484: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80076488: jal         0x800762EC
    // 0x8007648C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    CubeTiles_SampleField(rdram, ctx);
        goto after_0;
    // 0x8007648C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80076490: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80076494: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80076498: jr          $ra
    // 0x8007649C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007649C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void CubeTiles_CopyTileBuffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800764A0: lw          $t6, 0x80($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X80);
    // 0x800764A4: nop

    // 0x800764A8: sw          $t6, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r14;
    // 0x800764AC: lw          $t7, 0x84($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X84);
    // 0x800764B0: jr          $ra
    // 0x800764B4: sw          $t7, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r15;
    return;
    // 0x800764B4: sw          $t7, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void CubeTiles_LoadTiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800764B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800764BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800764C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800764C4: jal         0x8004A34C
    // 0x800764C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x800764C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800764CC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800764D0: nop

    // 0x800764D4: lbu         $a0, 0x78($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X78);
    // 0x800764D8: nop

    // 0x800764DC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800764E0: jal         0x8007E03C
    // 0x800764E4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800764E4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x800764E8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800764EC: nop

    // 0x800764F0: sw          $v0, 0x80($t8)
    MEM_W(0X80, ctx->r24) = ctx->r2;
    // 0x800764F4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800764F8: nop

    // 0x800764FC: lbu         $a0, 0x78($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X78);
    // 0x80076500: nop

    // 0x80076504: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80076508: jal         0x8007E03C
    // 0x8007650C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8007650C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
    // 0x80076510: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80076514: nop

    // 0x80076518: sw          $v0, 0x84($t1)
    MEM_W(0X84, ctx->r9) = ctx->r2;
    // 0x8007651C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80076520: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80076524: lbu         $t3, 0x78($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X78);
    // 0x80076528: nop

    // 0x8007652C: blez        $t3, L_80076650
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80076530: nop
    
            goto L_80076650;
    }
    // 0x80076530: nop

L_80076534:
    // 0x80076534: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80076538: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8007653C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80076540: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80076544: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x80076548: lui         $a0, 0x52
    ctx->r4 = S32(0X52 << 16);
    // 0x8007654C: jal         0x80074888
    // 0x80076550: addiu       $a0, $a0, 0x6B0
    ctx->r4 = ADD32(ctx->r4, 0X6B0);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_3;
    // 0x80076550: addiu       $a0, $a0, 0x6B0
    ctx->r4 = ADD32(ctx->r4, 0X6B0);
    after_3:
    // 0x80076554: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80076558: jal         0x8007E03C
    // 0x8007655C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x8007655C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80076560: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80076564: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80076568: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x8007656C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80076570: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80076574: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x80076578: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007657C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80076580: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80076584: lw          $t5, 0x80($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X80);
    // 0x80076588: sll         $t8, $t4, 1
    ctx->r24 = S32(ctx->r12 << 1);
    // 0x8007658C: addu        $t0, $t3, $t8
    ctx->r8 = ADD32(ctx->r11, ctx->r24);
    // 0x80076590: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80076594: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80076598: lhu         $a2, 0x0($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X0);
    // 0x8007659C: lui         $a0, 0x52
    ctx->r4 = S32(0X52 << 16);
    // 0x800765A0: jal         0x800746C0
    // 0x800765A4: addiu       $a0, $a0, 0x6B0
    ctx->r4 = ADD32(ctx->r4, 0X6B0);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_5;
    // 0x800765A4: addiu       $a0, $a0, 0x6B0
    ctx->r4 = ADD32(ctx->r4, 0X6B0);
    after_5:
    // 0x800765A8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800765AC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800765B0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800765B4: addu        $t5, $t9, $t2
    ctx->r13 = ADD32(ctx->r25, ctx->r10);
    // 0x800765B8: lhu         $t6, 0x3C($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X3C);
    // 0x800765BC: nop

    // 0x800765C0: beq         $t6, $zero, L_8007662C
    if (ctx->r14 == 0) {
        // 0x800765C4: nop
    
            goto L_8007662C;
    }
    // 0x800765C4: nop

    // 0x800765C8: lui         $a0, 0x52
    ctx->r4 = S32(0X52 << 16);
    // 0x800765CC: addiu       $a0, $a0, 0x6B0
    ctx->r4 = ADD32(ctx->r4, 0X6B0);
    // 0x800765D0: jal         0x80074888
    // 0x800765D4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_6;
    // 0x800765D4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_6:
    // 0x800765D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800765DC: jal         0x8007E03C
    // 0x800765E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x800765E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800765E4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800765E8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800765EC: lw          $t4, 0x84($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X84);
    // 0x800765F0: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x800765F4: addu        $t0, $t4, $t8
    ctx->r8 = ADD32(ctx->r12, ctx->r24);
    // 0x800765F8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800765FC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80076600: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80076604: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80076608: lw          $t9, 0x84($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X84);
    // 0x8007660C: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x80076610: addu        $t3, $t1, $t7
    ctx->r11 = ADD32(ctx->r9, ctx->r15);
    // 0x80076614: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80076618: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8007661C: lhu         $a2, 0x3C($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X3C);
    // 0x80076620: lui         $a0, 0x52
    ctx->r4 = S32(0X52 << 16);
    // 0x80076624: jal         0x800746C0
    // 0x80076628: addiu       $a0, $a0, 0x6B0
    ctx->r4 = ADD32(ctx->r4, 0X6B0);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_8;
    // 0x80076628: addiu       $a0, $a0, 0x6B0
    ctx->r4 = ADD32(ctx->r4, 0X6B0);
    after_8:
L_8007662C:
    // 0x8007662C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80076630: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80076634: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x80076638: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8007663C: lbu         $t9, 0x78($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X78);
    // 0x80076640: nop

    // 0x80076644: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80076648: bne         $at, $zero, L_80076534
    if (ctx->r1 != 0) {
        // 0x8007664C: nop
    
            goto L_80076534;
    }
    // 0x8007664C: nop

L_80076650:
    // 0x80076650: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80076654: nop

    // 0x80076658: lbu         $t6, 0x8C($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X8C);
    // 0x8007665C: nop

    // 0x80076660: beq         $t6, $zero, L_800766B8
    if (ctx->r14 == 0) {
        // 0x80076664: nop
    
            goto L_800766B8;
    }
    // 0x80076664: nop

    // 0x80076668: lbu         $t2, 0x78($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0X78);
    // 0x8007666C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80076670: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80076674: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80076678: bgez        $t2, L_80076688
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8007667C: sra         $t1, $t2, 1
        ctx->r9 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80076688;
    }
    // 0x8007667C: sra         $t1, $t2, 1
    ctx->r9 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80076680: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80076684: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80076688:
    // 0x80076688: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8007668C: nop

    // 0x80076690: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80076694: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80076698: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007669C: nop

    // 0x800766A0: div.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800766A4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800766A8: swc1        $f18, 0x90($t5)
    MEM_W(0X90, ctx->r13) = ctx->f18.u32l;
    // 0x800766AC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800766B0: nop

    // 0x800766B4: swc1        $f6, 0x94($t7)
    MEM_W(0X94, ctx->r15) = ctx->f6.u32l;
L_800766B8:
    // 0x800766B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800766BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800766C0: jr          $ra
    // 0x800766C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800766C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void CubeTiles_FreeTiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800766C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800766CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800766D0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800766D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800766D8: lbu         $t7, 0x78($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X78);
    // 0x800766DC: nop

    // 0x800766E0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800766E4: bltz        $t8, L_80076770
    if (SIGNED(ctx->r24) < 0) {
        // 0x800766E8: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_80076770;
    }
    // 0x800766E8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_800766EC:
    // 0x800766EC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800766F0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800766F4: lw          $t0, 0x80($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X80);
    // 0x800766F8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800766FC: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80076700: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80076704: nop

    // 0x80076708: beq         $t4, $zero, L_80076718
    if (ctx->r12 == 0) {
        // 0x8007670C: nop
    
            goto L_80076718;
    }
    // 0x8007670C: nop

    // 0x80076710: jal         0x8007E328
    // 0x80076714: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x80076714: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_0:
L_80076718:
    // 0x80076718: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007671C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80076720: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80076724: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80076728: lhu         $t9, 0x3C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X3C);
    // 0x8007672C: nop

    // 0x80076730: beq         $t9, $zero, L_8007675C
    if (ctx->r25 == 0) {
        // 0x80076734: nop
    
            goto L_8007675C;
    }
    // 0x80076734: nop

    // 0x80076738: lw          $t1, 0x84($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X84);
    // 0x8007673C: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80076740: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80076744: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80076748: nop

    // 0x8007674C: beq         $t3, $zero, L_8007675C
    if (ctx->r11 == 0) {
        // 0x80076750: nop
    
            goto L_8007675C;
    }
    // 0x80076750: nop

    // 0x80076754: jal         0x8007E328
    // 0x80076758: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x80076758: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_1:
L_8007675C:
    // 0x8007675C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80076760: nop

    // 0x80076764: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x80076768: bgez        $t7, L_800766EC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8007676C: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_800766EC;
    }
    // 0x8007676C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80076770:
    // 0x80076770: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80076774: nop

    // 0x80076778: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x8007677C: nop

    // 0x80076780: beq         $t9, $zero, L_80076790
    if (ctx->r25 == 0) {
        // 0x80076784: nop
    
            goto L_80076790;
    }
    // 0x80076784: nop

    // 0x80076788: jal         0x8007E328
    // 0x8007678C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_2;
    // 0x8007678C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_2:
L_80076790:
    // 0x80076790: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80076794: nop

    // 0x80076798: lw          $t6, 0x84($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X84);
    // 0x8007679C: nop

    // 0x800767A0: beq         $t6, $zero, L_800767B0
    if (ctx->r14 == 0) {
        // 0x800767A4: nop
    
            goto L_800767B0;
    }
    // 0x800767A4: nop

    // 0x800767A8: jal         0x8007E328
    // 0x800767AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_3;
    // 0x800767AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_3:
L_800767B0:
    // 0x800767B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800767B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800767B8: jr          $ra
    // 0x800767BC: nop

    return;
    // 0x800767BC: nop

;}

RECOMP_FUNC void CubeTiles_UpdateAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800767C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800767C4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800767C8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800767CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800767D0: lbu         $t7, 0x8A($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8A);
    // 0x800767D4: nop

    // 0x800767D8: beq         $t7, $zero, L_80076D34
    if (ctx->r15 == 0) {
        // 0x800767DC: nop
    
            goto L_80076D34;
    }
    // 0x800767DC: nop

    // 0x800767E0: lbu         $t8, 0x8B($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X8B);
    // 0x800767E4: nop

    // 0x800767E8: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800767EC: beq         $at, $zero, L_80076D18
    if (ctx->r1 == 0) {
        // 0x800767F0: nop
    
            goto L_80076D18;
    }
    // 0x800767F0: nop

    // 0x800767F4: lbu         $t9, 0x78($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X78);
    // 0x800767F8: nop

    // 0x800767FC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80076800: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80076804: beq         $at, $zero, L_80076814
    if (ctx->r1 == 0) {
        // 0x80076808: nop
    
            goto L_80076814;
    }
    // 0x80076808: nop

    // 0x8007680C: b           L_80076E8C
    // 0x80076810: sb          $zero, 0x8B($t6)
    MEM_B(0X8B, ctx->r14) = 0;
        goto L_80076E8C;
    // 0x80076810: sb          $zero, 0x8B($t6)
    MEM_B(0X8B, ctx->r14) = 0;
L_80076814:
    // 0x80076814: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80076818: nop

    // 0x8007681C: lbu         $t2, 0x88($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X88);
    // 0x80076820: nop

    // 0x80076824: beq         $t2, $zero, L_80076A78
    if (ctx->r10 == 0) {
        // 0x80076828: nop
    
            goto L_80076A78;
    }
    // 0x80076828: nop

    // 0x8007682C: lbu         $t3, 0x89($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X89);
    // 0x80076830: nop

    // 0x80076834: bne         $t3, $zero, L_80076A5C
    if (ctx->r11 != 0) {
        // 0x80076838: nop
    
            goto L_80076A5C;
    }
    // 0x80076838: nop

    // 0x8007683C: sb          $t2, 0x89($t1)
    MEM_B(0X89, ctx->r9) = ctx->r10;
    // 0x80076840: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80076844: nop

    // 0x80076848: lbu         $t5, 0x79($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X79);
    // 0x8007684C: lbu         $t9, 0x78($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X78);
    // 0x80076850: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80076854: div         $zero, $t7, $t9
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r25)));
    // 0x80076858: bne         $t9, $zero, L_80076864
    if (ctx->r25 != 0) {
        // 0x8007685C: nop
    
            goto L_80076864;
    }
    // 0x8007685C: nop

    // 0x80076860: break       7
    do_break(2147969120);
L_80076864:
    // 0x80076864: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80076868: bne         $t9, $at, L_8007687C
    if (ctx->r25 != ctx->r1) {
        // 0x8007686C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007687C;
    }
    // 0x8007686C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80076870: bne         $t7, $at, L_8007687C
    if (ctx->r15 != ctx->r1) {
        // 0x80076874: nop
    
            goto L_8007687C;
    }
    // 0x80076874: nop

    // 0x80076878: break       6
    do_break(2147969144);
L_8007687C:
    // 0x8007687C: mfhi        $t8
    ctx->r24 = hi;
    // 0x80076880: sb          $t8, 0x79($t4)
    MEM_B(0X79, ctx->r12) = ctx->r24;
    // 0x80076884: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80076888: nop

    // 0x8007688C: lbu         $t6, 0x8B($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X8B);
    // 0x80076890: nop

    // 0x80076894: addiu       $t3, $t6, 0x1
    ctx->r11 = ADD32(ctx->r14, 0X1);
    // 0x80076898: sb          $t3, 0x8B($t0)
    MEM_B(0X8B, ctx->r8) = ctx->r11;
    // 0x8007689C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800768A0: nop

    // 0x800768A4: lbu         $t1, 0x8C($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X8C);
    // 0x800768A8: nop

    // 0x800768AC: beq         $t1, $zero, L_80076C94
    if (ctx->r9 == 0) {
        // 0x800768B0: nop
    
            goto L_80076C94;
    }
    // 0x800768B0: nop

    // 0x800768B4: lwc1        $f4, 0x94($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X94);
    // 0x800768B8: lwc1        $f6, 0x90($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X90);
    // 0x800768BC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800768C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800768C4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800768C8: swc1        $f8, 0x94($t2)
    MEM_W(0X94, ctx->r10) = ctx->f8.u32l;
    // 0x800768CC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800768D0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800768D4: lwc1        $f10, 0x94($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X94);
    // 0x800768D8: nop

    // 0x800768DC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800768E0: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x800768E4: nop

    // 0x800768E8: bc1f        L_80076948
    if (!c1cs) {
        // 0x800768EC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80076948;
    }
    // 0x800768EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800768F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800768F4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800768F8: swc1        $f4, 0x94($t5)
    MEM_W(0X94, ctx->r13) = ctx->f4.u32l;
    // 0x800768FC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80076900: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80076904: lbu         $t9, 0x78($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X78);
    // 0x80076908: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007690C: bgez        $t9, L_8007691C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80076910: sra         $t8, $t9, 1
        ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
            goto L_8007691C;
    }
    // 0x80076910: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80076914: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x80076918: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8007691C:
    // 0x8007691C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80076920: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x80076924: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80076928: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8007692C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80076930: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80076934: nop

    // 0x80076938: div.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f6.d, ctx->f16.d);
    // 0x8007693C: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80076940: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80076944: swc1        $f10, 0x90($t7)
    MEM_W(0X90, ctx->r15) = ctx->f10.u32l;
L_80076948:
    // 0x80076948: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007694C: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80076950: lwc1        $f6, 0x94($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X94);
    // 0x80076954: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80076958: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8007695C: c.le.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d <= ctx->f18.d;
    // 0x80076960: nop

    // 0x80076964: bc1f        L_800769B8
    if (!c1cs) {
        // 0x80076968: nop
    
            goto L_800769B8;
    }
    // 0x80076968: nop

    // 0x8007696C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80076970: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80076974: swc1        $f4, 0x94($t4)
    MEM_W(0X94, ctx->r12) = ctx->f4.u32l;
    // 0x80076978: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007697C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80076980: lbu         $t3, 0x78($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X78);
    // 0x80076984: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80076988: bgez        $t3, L_80076998
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007698C: sra         $t0, $t3, 1
        ctx->r8 = S32(SIGNED(ctx->r11) >> 1);
            goto L_80076998;
    }
    // 0x8007698C: sra         $t0, $t3, 1
    ctx->r8 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80076990: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x80076994: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_80076998:
    // 0x80076998: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8007699C: nop

    // 0x800769A0: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800769A4: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x800769A8: nop

    // 0x800769AC: div.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f16.d);
    // 0x800769B0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800769B4: swc1        $f4, 0x90($t6)
    MEM_W(0X90, ctx->r14) = ctx->f4.u32l;
L_800769B8:
    // 0x800769B8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800769BC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800769C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800769C4: lwc1        $f10, 0x94($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X94);
    // 0x800769C8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800769CC: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800769D0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800769D4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800769D8: nop

    // 0x800769DC: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800769E0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800769E4: nop

    // 0x800769E8: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800769EC: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800769F0: beq         $t5, $zero, L_80076A40
    if (ctx->r13 == 0) {
        // 0x800769F4: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80076A40;
    }
    // 0x800769F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800769F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800769FC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80076A00: sub.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80076A04: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80076A08: nop

    // 0x80076A0C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80076A10: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80076A14: nop

    // 0x80076A18: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80076A1C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80076A20: bne         $t5, $zero, L_80076A38
    if (ctx->r13 != 0) {
        // 0x80076A24: nop
    
            goto L_80076A38;
    }
    // 0x80076A24: nop

    // 0x80076A28: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80076A2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80076A30: b           L_80076A50
    // 0x80076A34: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80076A50;
    // 0x80076A34: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80076A38:
    // 0x80076A38: b           L_80076A50
    // 0x80076A3C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80076A50;
    // 0x80076A3C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80076A40:
    // 0x80076A40: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80076A44: nop

    // 0x80076A48: bltz        $t5, L_80076A38
    if (SIGNED(ctx->r13) < 0) {
        // 0x80076A4C: nop
    
            goto L_80076A38;
    }
    // 0x80076A4C: nop

L_80076A50:
    // 0x80076A50: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80076A54: b           L_80076C94
    // 0x80076A58: sb          $t5, 0x9B($t1)
    MEM_B(0X9B, ctx->r9) = ctx->r13;
        goto L_80076C94;
    // 0x80076A58: sb          $t5, 0x9B($t1)
    MEM_B(0X9B, ctx->r9) = ctx->r13;
L_80076A5C:
    // 0x80076A5C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80076A60: nop

    // 0x80076A64: lbu         $t8, 0x89($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X89);
    // 0x80076A68: nop

    // 0x80076A6C: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80076A70: b           L_80076C94
    // 0x80076A74: sb          $t7, 0x89($t9)
    MEM_B(0X89, ctx->r25) = ctx->r15;
        goto L_80076C94;
    // 0x80076A74: sb          $t7, 0x89($t9)
    MEM_B(0X89, ctx->r25) = ctx->r15;
L_80076A78:
    // 0x80076A78: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80076A7C: nop

    // 0x80076A80: lbu         $t3, 0x8C($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0X8C);
    // 0x80076A84: nop

    // 0x80076A88: beq         $t3, $zero, L_80076C38
    if (ctx->r11 == 0) {
        // 0x80076A8C: nop
    
            goto L_80076C38;
    }
    // 0x80076A8C: nop

    // 0x80076A90: lwc1        $f18, 0x94($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X94);
    // 0x80076A94: lwc1        $f4, 0x90($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X90);
    // 0x80076A98: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80076A9C: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80076AA0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80076AA4: swc1        $f10, 0x94($t4)
    MEM_W(0X94, ctx->r12) = ctx->f10.u32l;
    // 0x80076AA8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80076AAC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80076AB0: lwc1        $f6, 0x94($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X94);
    // 0x80076AB4: nop

    // 0x80076AB8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80076ABC: c.le.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d <= ctx->f8.d;
    // 0x80076AC0: nop

    // 0x80076AC4: bc1f        L_80076B24
    if (!c1cs) {
        // 0x80076AC8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80076B24;
    }
    // 0x80076AC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80076ACC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80076AD0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80076AD4: swc1        $f18, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->f18.u32l;
    // 0x80076AD8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80076ADC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80076AE0: lbu         $t2, 0x78($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X78);
    // 0x80076AE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80076AE8: bgez        $t2, L_80076AF8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80076AEC: sra         $t5, $t2, 1
        ctx->r13 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80076AF8;
    }
    // 0x80076AEC: sra         $t5, $t2, 1
    ctx->r13 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80076AF0: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80076AF4: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_80076AF8:
    // 0x80076AF8: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80076AFC: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x80076B00: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80076B04: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80076B08: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80076B0C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80076B10: nop

    // 0x80076B14: div.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x80076B18: mul.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80076B1C: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80076B20: swc1        $f6, 0x90($t6)
    MEM_W(0X90, ctx->r14) = ctx->f6.u32l;
L_80076B24:
    // 0x80076B24: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80076B28: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80076B2C: lwc1        $f4, 0x94($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X94);
    // 0x80076B30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80076B34: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80076B38: c.le.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d <= ctx->f16.d;
    // 0x80076B3C: nop

    // 0x80076B40: bc1f        L_80076B94
    if (!c1cs) {
        // 0x80076B44: nop
    
            goto L_80076B94;
    }
    // 0x80076B44: nop

    // 0x80076B48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80076B4C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80076B50: swc1        $f18, 0x94($t1)
    MEM_W(0X94, ctx->r9) = ctx->f18.u32l;
    // 0x80076B54: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80076B58: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80076B5C: lbu         $t7, 0x78($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X78);
    // 0x80076B60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80076B64: bgez        $t7, L_80076B74
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80076B68: sra         $t9, $t7, 1
        ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
            goto L_80076B74;
    }
    // 0x80076B68: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80076B6C: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x80076B70: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80076B74:
    // 0x80076B74: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80076B78: nop

    // 0x80076B7C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80076B80: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80076B84: nop

    // 0x80076B88: div.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x80076B8C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80076B90: swc1        $f18, 0x90($t8)
    MEM_W(0X90, ctx->r24) = ctx->f18.u32l;
L_80076B94:
    // 0x80076B94: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80076B98: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80076B9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80076BA0: lwc1        $f6, 0x94($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X94);
    // 0x80076BA4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80076BA8: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80076BAC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80076BB0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80076BB4: nop

    // 0x80076BB8: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80076BBC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80076BC0: nop

    // 0x80076BC4: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x80076BC8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80076BCC: beq         $t0, $zero, L_80076C1C
    if (ctx->r8 == 0) {
        // 0x80076BD0: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80076C1C;
    }
    // 0x80076BD0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80076BD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80076BD8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80076BDC: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80076BE0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80076BE4: nop

    // 0x80076BE8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80076BEC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80076BF0: nop

    // 0x80076BF4: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x80076BF8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80076BFC: bne         $t0, $zero, L_80076C14
    if (ctx->r8 != 0) {
        // 0x80076C00: nop
    
            goto L_80076C14;
    }
    // 0x80076C00: nop

    // 0x80076C04: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80076C08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80076C0C: b           L_80076C2C
    // 0x80076C10: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80076C2C;
    // 0x80076C10: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80076C14:
    // 0x80076C14: b           L_80076C2C
    // 0x80076C18: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80076C2C;
    // 0x80076C18: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_80076C1C:
    // 0x80076C1C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80076C20: nop

    // 0x80076C24: bltz        $t0, L_80076C14
    if (SIGNED(ctx->r8) < 0) {
        // 0x80076C28: nop
    
            goto L_80076C14;
    }
    // 0x80076C28: nop

L_80076C2C:
    // 0x80076C2C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80076C30: sb          $t0, 0x9B($t3)
    MEM_B(0X9B, ctx->r11) = ctx->r8;
    // 0x80076C34: nop

L_80076C38:
    // 0x80076C38: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80076C3C: nop

    // 0x80076C40: lbu         $t5, 0x79($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X79);
    // 0x80076C44: lbu         $t1, 0x78($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X78);
    // 0x80076C48: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80076C4C: div         $zero, $t6, $t1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r9)));
    // 0x80076C50: bne         $t1, $zero, L_80076C5C
    if (ctx->r9 != 0) {
        // 0x80076C54: nop
    
            goto L_80076C5C;
    }
    // 0x80076C54: nop

    // 0x80076C58: break       7
    do_break(2147970136);
L_80076C5C:
    // 0x80076C5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80076C60: bne         $t1, $at, L_80076C74
    if (ctx->r9 != ctx->r1) {
        // 0x80076C64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80076C74;
    }
    // 0x80076C64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80076C68: bne         $t6, $at, L_80076C74
    if (ctx->r14 != ctx->r1) {
        // 0x80076C6C: nop
    
            goto L_80076C74;
    }
    // 0x80076C6C: nop

    // 0x80076C70: break       6
    do_break(2147970160);
L_80076C74:
    // 0x80076C74: mfhi        $t7
    ctx->r15 = hi;
    // 0x80076C78: sb          $t7, 0x79($t2)
    MEM_B(0X79, ctx->r10) = ctx->r15;
    // 0x80076C7C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80076C80: nop

    // 0x80076C84: lbu         $t8, 0x8B($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X8B);
    // 0x80076C88: nop

    // 0x80076C8C: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x80076C90: sb          $t4, 0x8B($t9)
    MEM_B(0X8B, ctx->r25) = ctx->r12;
L_80076C94:
    // 0x80076C94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80076C98: jal         0x8005BBFC
    // 0x80076C9C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_0;
    // 0x80076C9C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_0:
    // 0x80076CA0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80076CA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80076CA8: lbu         $t5, 0x79($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X79);
    // 0x80076CAC: lw          $t3, 0x80($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X80);
    // 0x80076CB0: lw          $t7, 0x84($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X84);
    // 0x80076CB4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80076CB8: lhu         $t8, 0x7C($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X7C);
    // 0x80076CBC: addu        $t1, $t3, $t6
    ctx->r9 = ADD32(ctx->r11, ctx->r14);
    // 0x80076CC0: addu        $t2, $t7, $t6
    ctx->r10 = ADD32(ctx->r15, ctx->r14);
    // 0x80076CC4: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80076CC8: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80076CCC: lhu         $a3, 0x7A($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X7A);
    // 0x80076CD0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80076CD4: lbu         $t4, 0x98($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X98);
    // 0x80076CD8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80076CDC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80076CE0: lbu         $t9, 0x99($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X99);
    // 0x80076CE4: nop

    // 0x80076CE8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80076CEC: lbu         $t5, 0x9A($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X9A);
    // 0x80076CF0: nop

    // 0x80076CF4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80076CF8: lbu         $t3, 0x9B($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X9B);
    // 0x80076CFC: jal         0x80057460
    // 0x80076D00: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_1;
    // 0x80076D00: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    after_1:
    // 0x80076D04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80076D08: jal         0x8005BE40
    // 0x80076D0C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_2;
    // 0x80076D0C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_2:
    // 0x80076D10: b           L_80076E8C
    // 0x80076D14: nop

        goto L_80076E8C;
    // 0x80076D14: nop

L_80076D18:
    // 0x80076D18: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80076D1C: nop

    // 0x80076D20: lbu         $t7, 0x8B($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X8B);
    // 0x80076D24: nop

    // 0x80076D28: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80076D2C: b           L_80076E8C
    // 0x80076D30: sb          $t6, 0x8B($t1)
    MEM_B(0X8B, ctx->r9) = ctx->r14;
        goto L_80076E8C;
    // 0x80076D30: sb          $t6, 0x8B($t1)
    MEM_B(0X8B, ctx->r9) = ctx->r14;
L_80076D34:
    // 0x80076D34: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80076D38: nop

    // 0x80076D3C: lbu         $t8, 0x88($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X88);
    // 0x80076D40: nop

    // 0x80076D44: beq         $t8, $zero, L_80076DC8
    if (ctx->r24 == 0) {
        // 0x80076D48: nop
    
            goto L_80076DC8;
    }
    // 0x80076D48: nop

    // 0x80076D4C: lbu         $t4, 0x89($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X89);
    // 0x80076D50: nop

    // 0x80076D54: bne         $t4, $zero, L_80076DAC
    if (ctx->r12 != 0) {
        // 0x80076D58: nop
    
            goto L_80076DAC;
    }
    // 0x80076D58: nop

    // 0x80076D5C: sb          $t8, 0x89($t2)
    MEM_B(0X89, ctx->r10) = ctx->r24;
    // 0x80076D60: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80076D64: nop

    // 0x80076D68: lbu         $t5, 0x79($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X79);
    // 0x80076D6C: lbu         $t3, 0x78($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X78);
    // 0x80076D70: addiu       $t0, $t5, 0x1
    ctx->r8 = ADD32(ctx->r13, 0X1);
    // 0x80076D74: div         $zero, $t0, $t3
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r11)));
    // 0x80076D78: bne         $t3, $zero, L_80076D84
    if (ctx->r11 != 0) {
        // 0x80076D7C: nop
    
            goto L_80076D84;
    }
    // 0x80076D7C: nop

    // 0x80076D80: break       7
    do_break(2147970432);
L_80076D84:
    // 0x80076D84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80076D88: bne         $t3, $at, L_80076D9C
    if (ctx->r11 != ctx->r1) {
        // 0x80076D8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80076D9C;
    }
    // 0x80076D8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80076D90: bne         $t0, $at, L_80076D9C
    if (ctx->r8 != ctx->r1) {
        // 0x80076D94: nop
    
            goto L_80076D9C;
    }
    // 0x80076D94: nop

    // 0x80076D98: break       6
    do_break(2147970456);
L_80076D9C:
    // 0x80076D9C: mfhi        $t7
    ctx->r15 = hi;
    // 0x80076DA0: sb          $t7, 0x79($t9)
    MEM_B(0X79, ctx->r25) = ctx->r15;
    // 0x80076DA4: b           L_80076E10
    // 0x80076DA8: nop

        goto L_80076E10;
    // 0x80076DA8: nop

L_80076DAC:
    // 0x80076DAC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80076DB0: nop

    // 0x80076DB4: lbu         $t1, 0x89($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X89);
    // 0x80076DB8: nop

    // 0x80076DBC: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x80076DC0: b           L_80076E10
    // 0x80076DC4: sb          $t4, 0x89($t6)
    MEM_B(0X89, ctx->r14) = ctx->r12;
        goto L_80076E10;
    // 0x80076DC4: sb          $t4, 0x89($t6)
    MEM_B(0X89, ctx->r14) = ctx->r12;
L_80076DC8:
    // 0x80076DC8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80076DCC: nop

    // 0x80076DD0: lbu         $t2, 0x79($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X79);
    // 0x80076DD4: lbu         $t0, 0x78($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X78);
    // 0x80076DD8: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x80076DDC: div         $zero, $t5, $t0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r8)));
    // 0x80076DE0: bne         $t0, $zero, L_80076DEC
    if (ctx->r8 != 0) {
        // 0x80076DE4: nop
    
            goto L_80076DEC;
    }
    // 0x80076DE4: nop

    // 0x80076DE8: break       7
    do_break(2147970536);
L_80076DEC:
    // 0x80076DEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80076DF0: bne         $t0, $at, L_80076E04
    if (ctx->r8 != ctx->r1) {
        // 0x80076DF4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80076E04;
    }
    // 0x80076DF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80076DF8: bne         $t5, $at, L_80076E04
    if (ctx->r13 != ctx->r1) {
        // 0x80076DFC: nop
    
            goto L_80076E04;
    }
    // 0x80076DFC: nop

    // 0x80076E00: break       6
    do_break(2147970560);
L_80076E04:
    // 0x80076E04: mfhi        $t3
    ctx->r11 = hi;
    // 0x80076E08: sb          $t3, 0x79($t8)
    MEM_B(0X79, ctx->r24) = ctx->r11;
    // 0x80076E0C: nop

L_80076E10:
    // 0x80076E10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80076E14: jal         0x8005BBFC
    // 0x80076E18: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Gfx_SetupRenderState(rdram, ctx);
        goto after_3;
    // 0x80076E18: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_3:
    // 0x80076E1C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80076E20: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80076E24: lbu         $t1, 0x79($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X79);
    // 0x80076E28: lw          $t9, 0x80($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X80);
    // 0x80076E2C: lw          $t2, 0x84($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X84);
    // 0x80076E30: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x80076E34: lhu         $t0, 0x7C($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X7C);
    // 0x80076E38: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x80076E3C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80076E40: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x80076E44: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80076E48: lhu         $a3, 0x7A($t7)
    ctx->r7 = MEM_HU(ctx->r15, 0X7A);
    // 0x80076E4C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80076E50: lbu         $t3, 0x98($t7)
    ctx->r11 = MEM_BU(ctx->r15, 0X98);
    // 0x80076E54: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80076E58: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80076E5C: lbu         $t8, 0x99($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X99);
    // 0x80076E60: nop

    // 0x80076E64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80076E68: lbu         $t1, 0x9A($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X9A);
    // 0x80076E6C: nop

    // 0x80076E70: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80076E74: lbu         $t9, 0x9B($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X9B);
    // 0x80076E78: jal         0x80057460
    // 0x80076E7C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_4;
    // 0x80076E7C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_4:
    // 0x80076E80: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80076E84: jal         0x8005BE40
    // 0x80076E88: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_5;
    // 0x80076E88: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_5:
L_80076E8C:
    // 0x80076E8C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80076E90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80076E94: jr          $ra
    // 0x80076E98: nop

    return;
    // 0x80076E98: nop

    // 0x80076E9C: nop

;}

RECOMP_FUNC void func_80076EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076EA0: jr          $ra
    // 0x80076EA4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80076EA4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

RECOMP_FUNC void func_80076EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076EA8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80076EAC: jr          $ra
    // 0x80076EB0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80076EB0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80076EB4: nop

    // 0x80076EB8: nop

    // 0x80076EBC: nop

;}

RECOMP_FUNC void CubeTiles_ObjCreate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076EC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80076EC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076ECC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80076ED0: jal         0x80076F20
    // 0x80076ED4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    CubeTiles_ObjInit(rdram, ctx);
        goto after_0;
    // 0x80076ED4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80076ED8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80076EDC: nop

    // 0x80076EE0: beq         $t6, $zero, L_80076F10
    if (ctx->r14 == 0) {
        // 0x80076EE4: nop
    
            goto L_80076F10;
    }
    // 0x80076EE4: nop

    // 0x80076EE8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80076EEC: nop

    // 0x80076EF0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80076EF4: jal         0x800A4590
    // 0x80076EF8: nop

    func_800A4590(rdram, ctx);
        goto after_1;
    // 0x80076EF8: nop

    after_1:
    // 0x80076EFC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80076F00: nop

    // 0x80076F04: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80076F08: jal         0x800A45D8
    // 0x80076F0C: nop

    func_800A45D8(rdram, ctx);
        goto after_2;
    // 0x80076F0C: nop

    after_2:
L_80076F10:
    // 0x80076F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076F18: jr          $ra
    // 0x80076F1C: nop

    return;
    // 0x80076F1C: nop

;}

RECOMP_FUNC void CubeTiles_ObjInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076F24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80076F28: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80076F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076F30: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x80076F34: nop

    // 0x80076F38: beq         $t7, $zero, L_80076F54
    if (ctx->r15 == 0) {
        // 0x80076F3C: nop
    
            goto L_80076F54;
    }
    // 0x80076F3C: nop

    // 0x80076F40: jal         0x800A6990
    // 0x80076F44: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800A6990(rdram, ctx);
        goto after_0;
    // 0x80076F44: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x80076F48: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80076F4C: nop

    // 0x80076F50: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
L_80076F54:
    // 0x80076F54: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80076F58: nop

    // 0x80076F5C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80076F60: nop

    // 0x80076F64: beq         $t0, $zero, L_80076FD0
    if (ctx->r8 == 0) {
        // 0x80076F68: nop
    
            goto L_80076FD0;
    }
    // 0x80076F68: nop

    // 0x80076F6C: jal         0x800A6A74
    // 0x80076F70: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800A6A74(rdram, ctx);
        goto after_1;
    // 0x80076F70: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x80076F74: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80076F78: nop

    // 0x80076F7C: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x80076F80: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80076F84: nop

    // 0x80076F88: lw          $t3, 0x28($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X28);
    // 0x80076F8C: nop

    // 0x80076F90: bne         $t3, $zero, L_80076FB8
    if (ctx->r11 != 0) {
        // 0x80076F94: nop
    
            goto L_80076FB8;
    }
    // 0x80076F94: nop

    // 0x80076F98: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x80076F9C: nop

    // 0x80076FA0: lw          $a0, 0x20($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X20);
    // 0x80076FA4: jal         0x800A6990
    // 0x80076FA8: nop

    func_800A6990(rdram, ctx);
        goto after_2;
    // 0x80076FA8: nop

    after_2:
    // 0x80076FAC: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80076FB0: nop

    // 0x80076FB4: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
L_80076FB8:
    // 0x80076FB8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80076FBC: nop

    // 0x80076FC0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80076FC4: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x80076FC8: jal         0x800A678C
    // 0x80076FCC: nop

    func_800A678C(rdram, ctx);
        goto after_3;
    // 0x80076FCC: nop

    after_3:
L_80076FD0:
    // 0x80076FD0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80076FD4: nop

    // 0x80076FD8: lbu         $t8, 0x20($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X20);
    // 0x80076FDC: nop

    // 0x80076FE0: bne         $t8, $zero, L_80076FF0
    if (ctx->r24 != 0) {
        // 0x80076FE4: nop
    
            goto L_80076FF0;
    }
    // 0x80076FE4: nop

    // 0x80076FE8: ori         $t9, $t8, 0x1B
    ctx->r25 = ctx->r24 | 0X1B;
    // 0x80076FEC: sb          $t9, 0x20($t7)
    MEM_B(0X20, ctx->r15) = ctx->r25;
L_80076FF0:
    // 0x80076FF0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80076FF4: nop

    // 0x80076FF8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80076FFC: jal         0x800B79D0
    // 0x80077000: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    guMtxIdentF(rdram, ctx);
        goto after_4;
    // 0x80077000: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_4:
    // 0x80077004: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80077008: nop

    // 0x8007700C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80077010: jal         0x800B79D0
    // 0x80077014: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    guMtxIdentF(rdram, ctx);
        goto after_5;
    // 0x80077014: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    after_5:
    // 0x80077018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007701C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077020: jr          $ra
    // 0x80077024: nop

    return;
    // 0x80077024: nop

;}

RECOMP_FUNC void CubeTiles_ObjFree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007702C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80077030: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80077034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077038: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8007703C: nop

    // 0x80077040: beq         $t7, $zero, L_8007705C
    if (ctx->r15 == 0) {
        // 0x80077044: nop
    
            goto L_8007705C;
    }
    // 0x80077044: nop

    // 0x80077048: jal         0x800A6AA8
    // 0x8007704C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800A6AA8(rdram, ctx);
        goto after_0;
    // 0x8007704C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x80077050: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80077054: nop

    // 0x80077058: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
L_8007705C:
    // 0x8007705C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80077060: nop

    // 0x80077064: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80077068: nop

    // 0x8007706C: beq         $t0, $zero, L_80077088
    if (ctx->r8 == 0) {
        // 0x80077070: nop
    
            goto L_80077088;
    }
    // 0x80077070: nop

    // 0x80077074: jal         0x800A6A2C
    // 0x80077078: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800A6A2C(rdram, ctx);
        goto after_1;
    // 0x80077078: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x8007707C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80077080: nop

    // 0x80077084: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_80077088:
    // 0x80077088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007708C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077090: jr          $ra
    // 0x80077094: nop

    return;
    // 0x80077094: nop

;}

RECOMP_FUNC void CubeTiles_ObjDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077098: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007709C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800770A0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800770A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800770A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800770AC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800770B0: nop

    // 0x800770B4: beq         $t7, $zero, L_80077394
    if (ctx->r15 == 0) {
        // 0x800770B8: nop
    
            goto L_80077394;
    }
    // 0x800770B8: nop

    // 0x800770BC: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800770C0: nop

    // 0x800770C4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x800770C8: nop

    // 0x800770CC: beq         $t9, $zero, L_800771A8
    if (ctx->r25 == 0) {
        // 0x800770D0: nop
    
            goto L_800771A8;
    }
    // 0x800770D0: nop

    // 0x800770D4: lbu         $t0, 0x20($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X20);
    // 0x800770D8: nop

    // 0x800770DC: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800770E0: beq         $t1, $zero, L_80077120
    if (ctx->r9 == 0) {
        // 0x800770E4: nop
    
            goto L_80077120;
    }
    // 0x800770E4: nop

    // 0x800770E8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800770EC: jal         0x800A4698
    // 0x800770F0: nop

    CubeTiles_ObjReset(rdram, ctx);
        goto after_0;
    // 0x800770F0: nop

    after_0:
    // 0x800770F4: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800770F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800770FC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80077100: jal         0x800A46C0
    // 0x80077104: nop

    CubeTiles_ObjSetState(rdram, ctx);
        goto after_1;
    // 0x80077104: nop

    after_1:
    // 0x80077108: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8007710C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80077110: lbu         $t4, 0x20($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X20);
    // 0x80077114: nop

    // 0x80077118: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8007711C: sb          $t5, 0x20($t3)
    MEM_B(0X20, ctx->r11) = ctx->r13;
L_80077120:
    // 0x80077120: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80077124: nop

    // 0x80077128: lbu         $t7, 0x20($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X20);
    // 0x8007712C: nop

    // 0x80077130: andi        $t9, $t7, 0x4
    ctx->r25 = ctx->r15 & 0X4;
    // 0x80077134: beq         $t9, $zero, L_80077144
    if (ctx->r25 == 0) {
        // 0x80077138: nop
    
            goto L_80077144;
    }
    // 0x80077138: nop

    // 0x8007713C: ori         $t0, $t7, 0x1
    ctx->r8 = ctx->r15 | 0X1;
    // 0x80077140: sb          $t0, 0x20($t6)
    MEM_B(0X20, ctx->r14) = ctx->r8;
L_80077144:
    // 0x80077144: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80077148: nop

    // 0x8007714C: lbu         $t8, 0x20($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X20);
    // 0x80077150: nop

    // 0x80077154: andi        $t2, $t8, 0x1
    ctx->r10 = ctx->r24 & 0X1;
    // 0x80077158: beq         $t2, $zero, L_80077170
    if (ctx->r10 == 0) {
        // 0x8007715C: nop
    
            goto L_80077170;
    }
    // 0x8007715C: nop

    // 0x80077160: jal         0x800A3AF0
    // 0x80077164: nop

    frametime_delta(rdram, ctx);
        goto after_2;
    // 0x80077164: nop

    after_2:
    // 0x80077168: b           L_80077174
    // 0x8007716C: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
        goto L_80077174;
    // 0x8007716C: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
L_80077170:
    // 0x80077170: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80077174:
    // 0x80077174: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80077178: nop

    // 0x8007717C: lbu         $t5, 0x20($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X20);
    // 0x80077180: nop

    // 0x80077184: andi        $t3, $t5, 0x4
    ctx->r11 = ctx->r13 & 0X4;
    // 0x80077188: beq         $t3, $zero, L_80077194
    if (ctx->r11 == 0) {
        // 0x8007718C: nop
    
            goto L_80077194;
    }
    // 0x8007718C: nop

    // 0x80077190: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_80077194:
    // 0x80077194: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80077198: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8007719C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x800771A0: jal         0x800A46C0
    // 0x800771A4: nop

    CubeTiles_ObjSetState(rdram, ctx);
        goto after_3;
    // 0x800771A4: nop

    after_3:
L_800771A8:
    // 0x800771A8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800771AC: nop

    // 0x800771B0: lbu         $t0, 0x20($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X20);
    // 0x800771B4: nop

    // 0x800771B8: andi        $t6, $t0, 0x10
    ctx->r14 = ctx->r8 & 0X10;
    // 0x800771BC: beq         $t6, $zero, L_800771DC
    if (ctx->r14 == 0) {
        // 0x800771C0: nop
    
            goto L_800771DC;
    }
    // 0x800771C0: nop

    // 0x800771C4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800771C8: lw          $a1, 0x14($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X14);
    // 0x800771CC: lw          $a2, 0x18($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X18);
    // 0x800771D0: lw          $a3, 0x1C($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X1C);
    // 0x800771D4: jal         0x800A3BF8
    // 0x800771D8: nop

    CubeTiles_ObjDrawRotate(rdram, ctx);
        goto after_4;
    // 0x800771D8: nop

    after_4:
L_800771DC:
    // 0x800771DC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800771E0: nop

    // 0x800771E4: lbu         $t8, 0x20($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X20);
    // 0x800771E8: nop

    // 0x800771EC: andi        $t2, $t8, 0x8
    ctx->r10 = ctx->r24 & 0X8;
    // 0x800771F0: beq         $t2, $zero, L_80077210
    if (ctx->r10 == 0) {
        // 0x800771F4: nop
    
            goto L_80077210;
    }
    // 0x800771F4: nop

    // 0x800771F8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800771FC: lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X8);
    // 0x80077200: lw          $a2, 0xC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XC);
    // 0x80077204: lw          $a3, 0x10($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X10);
    // 0x80077208: jal         0x800A3B00
    // 0x8007720C: nop

    CubeTiles_ObjSetVec3(rdram, ctx);
        goto after_5;
    // 0x8007720C: nop

    after_5:
L_80077210:
    // 0x80077210: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80077214: lw          $t4, 0x20C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20C0);
    // 0x80077218: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007721C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80077220: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80077224: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80077228: sw          $t5, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r13;
    // 0x8007722C: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80077230: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80077234: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80077238: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007723C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80077240: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80077244: lui         $t8, 0xED00
    ctx->r24 = S32(0XED00 << 16);
    // 0x80077248: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8007724C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80077250: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80077254: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x80077258: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8007725C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80077260: lui         $t1, 0x63
    ctx->r9 = S32(0X63 << 16);
    // 0x80077264: ori         $t1, $t1, 0xC4AC
    ctx->r9 = ctx->r9 | 0XC4AC;
    // 0x80077268: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007726C: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x80077270: lw          $t5, 0x20C0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20C0);
    // 0x80077274: lui         $t9, 0xDB04
    ctx->r25 = S32(0XDB04 << 16);
    // 0x80077278: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x8007727C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80077280: addiu       $t3, $t5, 0x8
    ctx->r11 = ADD32(ctx->r13, 0X8);
    // 0x80077284: sw          $t3, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r11;
    // 0x80077288: ori         $t9, $t9, 0x4
    ctx->r25 = ctx->r25 | 0X4;
    // 0x8007728C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80077290: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80077294: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80077298: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007729C: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800772A0: lw          $t8, 0x20C0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X20C0);
    // 0x800772A4: lui         $t1, 0xDB04
    ctx->r9 = S32(0XDB04 << 16);
    // 0x800772A8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800772AC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800772B0: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x800772B4: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x800772B8: ori         $t1, $t1, 0xC
    ctx->r9 = ctx->r9 | 0XC;
    // 0x800772BC: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x800772C0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800772C4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800772C8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800772CC: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800772D0: lw          $t9, 0x20C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20C0);
    // 0x800772D4: lui         $t6, 0xDB04
    ctx->r14 = S32(0XDB04 << 16);
    // 0x800772D8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800772DC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800772E0: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800772E4: sw          $t0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r8;
    // 0x800772E8: ori         $t6, $t6, 0x14
    ctx->r14 = ctx->r14 | 0X14;
    // 0x800772EC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800772F0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800772F4: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x800772F8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800772FC: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x80077300: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x80077304: lui         $t5, 0xDB04
    ctx->r13 = S32(0XDB04 << 16);
    // 0x80077308: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8007730C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80077310: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80077314: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x80077318: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8007731C: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80077320: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80077324: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x80077328: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8007732C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80077330: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80077334: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x80077338: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8007733C: jal         0x800A724C
    // 0x80077340: nop

    func_800A724C(rdram, ctx);
        goto after_6;
    // 0x80077340: nop

    after_6:
    // 0x80077344: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80077348: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007734C: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
    // 0x80077350: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80077354: nop

    // 0x80077358: beq         $t8, $zero, L_80077394
    if (ctx->r24 == 0) {
        // 0x8007735C: nop
    
            goto L_80077394;
    }
    // 0x8007735C: nop

    // 0x80077360: lbu         $t2, 0x20($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X20);
    // 0x80077364: nop

    // 0x80077368: andi        $t1, $t2, 0x4
    ctx->r9 = ctx->r10 & 0X4;
    // 0x8007736C: beq         $t1, $zero, L_80077394
    if (ctx->r9 == 0) {
        // 0x80077370: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80077394;
    }
    // 0x80077370: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80077374: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x80077378: sb          $t4, 0x20($t7)
    MEM_B(0X20, ctx->r15) = ctx->r12;
    // 0x8007737C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80077380: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80077384: lbu         $t3, 0x20($t5)
    ctx->r11 = MEM_BU(ctx->r13, 0X20);
    // 0x80077388: nop

    // 0x8007738C: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80077390: sb          $t9, 0x20($t5)
    MEM_B(0X20, ctx->r13) = ctx->r25;
L_80077394:
    // 0x80077394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80077398: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007739C: jr          $ra
    // 0x800773A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800773A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void CubeTiles_ObjSetAnimating(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800773A4: lbu         $t6, 0x20($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X20);
    // 0x800773A8: nop

    // 0x800773AC: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800773B0: jr          $ra
    // 0x800773B4: sb          $t7, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x800773B4: sb          $t7, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void CubeTiles_ObjClearAnimating(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800773B8: lbu         $t6, 0x20($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X20);
    // 0x800773BC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800773C0: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800773C4: jr          $ra
    // 0x800773C8: sb          $t7, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x800773C8: sb          $t7, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r15;
    // 0x800773CC: nop

;}

RECOMP_FUNC void CubeTiles_ObjSetVec3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3B00: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3B04: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A3B08: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800A3B0C: swc1        $f12, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f12.u32l;
    // 0x800A3B10: swc1        $f14, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f14.u32l;
    // 0x800A3B14: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800A3B18: jr          $ra
    // 0x800A3B1C: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800A3B1C: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
;}

RECOMP_FUNC void CubeTiles_ObjAddVec3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3B20: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800A3B24: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3B28: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A3B2C: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x800A3B30: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800A3B34: lwc1        $f16, 0x44($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800A3B38: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800A3B3C: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800A3B40: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x800A3B44: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x800A3B48: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800A3B4C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800A3B50: jr          $ra
    // 0x800A3B54: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800A3B54: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
;}

RECOMP_FUNC void CubeTiles_ObjAddVec3Rotated(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3B58: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800A3B5C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3B60: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800A3B64: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A3B68: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800A3B6C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800A3B70: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800A3B74: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800A3B78: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800A3B7C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A3B80: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A3B84: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x800A3B88: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800A3B8C: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800A3B90: mul.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800A3B94: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800A3B98: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800A3B9C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800A3BA0: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x800A3BA4: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800A3BA8: lwc1        $f18, 0x30($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800A3BAC: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800A3BB0: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A3BB4: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800A3BB8: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800A3BBC: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A3BC0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800A3BC4: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800A3BC8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800A3BCC: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800A3BD0: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x800A3BD4: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800A3BD8: lwc1        $f18, 0x34($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800A3BDC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A3BE0: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A3BE4: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800A3BE8: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800A3BEC: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800A3BF0: jr          $ra
    // 0x800A3BF4: swc1        $f18, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800A3BF4: swc1        $f18, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f18.u32l;
;}

RECOMP_FUNC void CubeTiles_ObjDrawRotate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3BF8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3BFC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A3C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3C08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A3C0C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800A3C10: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800A3C14: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800A3C18: jal         0x800B036C
    // 0x800A3C1C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    mtx4_rotate_euler(rdram, ctx);
        goto after_0;
    // 0x800A3C1C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800A3C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3C24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3C28: jr          $ra
    // 0x800A3C2C: nop

    return;
    // 0x800A3C2C: nop

;}

RECOMP_FUNC void func_800A3C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3C30: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3C34: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A3C38: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800A3C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3C40: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800A3C44: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800A3C48: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800A3C4C: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x800A3C50: jal         0x800B04BC
    // 0x800A3C54: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    mtx4_from_euler(rdram, ctx);
        goto after_0;
    // 0x800A3C54: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_0:
    // 0x800A3C58: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3C5C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800A3C60: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800A3C64: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x800A3C68: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x800A3C6C: addiu       $t8, $a0, 0x3C
    ctx->r24 = ADD32(ctx->r4, 0X3C);
L_800A3C70:
    // 0x800A3C70: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800A3C74: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800A3C78: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800A3C7C: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x800A3C80: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x800A3C84: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x800A3C88: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x800A3C8C: bne         $t9, $t8, L_800A3C70
    if (ctx->r25 != ctx->r24) {
        // 0x800A3C90: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_800A3C70;
    }
    // 0x800A3C90: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x800A3C94: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800A3C98: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x800A3C9C: jal         0x800AF558
    // 0x800A3CA0: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    mtx4_mult(rdram, ctx);
        goto after_1;
    // 0x800A3CA0: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    after_1:
    // 0x800A3CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3CA8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x800A3CAC: jr          $ra
    // 0x800A3CB0: nop

    return;
    // 0x800A3CB0: nop

;}

RECOMP_FUNC void func_800A3CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3CB4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800A3CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3CC0: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800A3CC4: jal         0x800B0140
    // 0x800A3CC8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    mtx4_rotate_axis(rdram, ctx);
        goto after_0;
    // 0x800A3CC8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800A3CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3CD4: jr          $ra
    // 0x800A3CD8: nop

    return;
    // 0x800A3CD8: nop

;}

RECOMP_FUNC void func_800A3CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3CDC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800A3CE0: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800A3CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3CE8: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800A3CEC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800A3CF0: jal         0x800B0140
    // 0x800A3CF4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    mtx4_rotate_axis(rdram, ctx);
        goto after_0;
    // 0x800A3CF4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_0:
    // 0x800A3CF8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3CFC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800A3D00: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800A3D04: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x800A3D08: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x800A3D0C: addiu       $t8, $a0, 0x3C
    ctx->r24 = ADD32(ctx->r4, 0X3C);
L_800A3D10:
    // 0x800A3D10: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800A3D14: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800A3D18: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800A3D1C: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x800A3D20: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x800A3D24: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x800A3D28: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x800A3D2C: bne         $t9, $t8, L_800A3D10
    if (ctx->r25 != ctx->r24) {
        // 0x800A3D30: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_800A3D10;
    }
    // 0x800A3D30: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x800A3D34: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800A3D38: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x800A3D3C: jal         0x800AF3A4
    // 0x800A3D40: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    func_800AF3A4(rdram, ctx);
        goto after_1;
    // 0x800A3D40: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    after_1:
    // 0x800A3D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3D48: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x800A3D4C: jr          $ra
    // 0x800A3D50: nop

    return;
    // 0x800A3D50: nop

;}

RECOMP_FUNC void func_800A3D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3D54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A3D58: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800A3D5C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A3D60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A3D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3D68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A3D6C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800A3D70: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x800A3D74: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x800A3D78: addiu       $a2, $a3, 0x14
    ctx->r6 = ADD32(ctx->r7, 0X14);
    // 0x800A3D7C: addiu       $a1, $a3, 0x10
    ctx->r5 = ADD32(ctx->r7, 0X10);
    // 0x800A3D80: jal         0x800BA660
    // 0x800A3D84: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    guNormalize(rdram, ctx);
        goto after_0;
    // 0x800A3D84: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A3D88: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800A3D8C: addiu       $a0, $a3, 0x1C
    ctx->r4 = ADD32(ctx->r7, 0X1C);
    // 0x800A3D90: addiu       $a1, $a3, 0x20
    ctx->r5 = ADD32(ctx->r7, 0X20);
    // 0x800A3D94: jal         0x800BA660
    // 0x800A3D98: addiu       $a2, $a3, 0x24
    ctx->r6 = ADD32(ctx->r7, 0X24);
    guNormalize(rdram, ctx);
        goto after_1;
    // 0x800A3D98: addiu       $a2, $a3, 0x24
    ctx->r6 = ADD32(ctx->r7, 0X24);
    after_1:
    // 0x800A3D9C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800A3DA0: addiu       $a0, $a3, 0x2C
    ctx->r4 = ADD32(ctx->r7, 0X2C);
    // 0x800A3DA4: addiu       $a1, $a3, 0x30
    ctx->r5 = ADD32(ctx->r7, 0X30);
    // 0x800A3DA8: jal         0x800BA660
    // 0x800A3DAC: addiu       $a2, $a3, 0x34
    ctx->r6 = ADD32(ctx->r7, 0X34);
    guNormalize(rdram, ctx);
        goto after_2;
    // 0x800A3DAC: addiu       $a2, $a3, 0x34
    ctx->r6 = ADD32(ctx->r7, 0X34);
    after_2:
    // 0x800A3DB0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A3DB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A3DB8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800A3DBC: jal         0x800B051C
    // 0x800A3DC0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    mtx4_scale(rdram, ctx);
        goto after_3;
    // 0x800A3DC0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800A3DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3DC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A3DCC: jr          $ra
    // 0x800A3DD0: nop

    return;
    // 0x800A3DD0: nop

;}

RECOMP_FUNC void func_800A3DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3DD4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3DD8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A3DDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3DE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A3DE8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800A3DEC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800A3DF0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800A3DF4: jal         0x800B051C
    // 0x800A3DF8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    mtx4_scale(rdram, ctx);
        goto after_0;
    // 0x800A3DF8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800A3DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3E04: jr          $ra
    // 0x800A3E08: nop

    return;
    // 0x800A3E08: nop

;}

RECOMP_FUNC void func_800A3E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3E0C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800A3E10: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3E14: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A3E18: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x800A3E1C: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800A3E20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A3E24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A3E28: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A3E2C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800A3E30: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800A3E34: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800A3E38: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x800A3E3C: jal         0x800BA6F0
    // 0x800A3E40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    guAlignF(rdram, ctx);
        goto after_0;
    // 0x800A3E40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800A3E44: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A3E48: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800A3E4C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A3E50: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x800A3E54: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A3E58: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x800A3E5C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A3E60: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x800A3E64: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A3E68: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x800A3E6C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800A3E70: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x800A3E74: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A3E78: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x800A3E7C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A3E80: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x800A3E84: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800A3E88: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x800A3E8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A3E90: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A3E94: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800A3E98: jr          $ra
    // 0x800A3E9C: nop

    return;
    // 0x800A3E9C: nop

;}

RECOMP_FUNC void func_800A3EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3EA0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3EA4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A3EA8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800A3EAC: swc1        $f12, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f12.u32l;
    // 0x800A3EB0: swc1        $f14, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->f14.u32l;
    // 0x800A3EB4: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800A3EB8: jr          $ra
    // 0x800A3EBC: swc1        $f4, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800A3EBC: swc1        $f4, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f4.u32l;
;}

RECOMP_FUNC void func_800A3EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3EC0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800A3EC4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3EC8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A3ECC: lwc1        $f4, 0x7C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x800A3ED0: lwc1        $f8, 0x80($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X80);
    // 0x800A3ED4: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800A3ED8: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800A3EDC: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800A3EE0: swc1        $f6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f6.u32l;
    // 0x800A3EE4: swc1        $f10, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->f10.u32l;
    // 0x800A3EE8: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800A3EEC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800A3EF0: jr          $ra
    // 0x800A3EF4: swc1        $f4, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800A3EF4: swc1        $f4, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f4.u32l;
;}

RECOMP_FUNC void func_800A3EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3EF8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800A3EFC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3F00: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800A3F04: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A3F08: lwc1        $f8, 0x5C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x800A3F0C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800A3F10: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800A3F14: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800A3F18: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800A3F1C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A3F20: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A3F24: lwc1        $f10, 0x7C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x800A3F28: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800A3F2C: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800A3F30: mul.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800A3F34: lwc1        $f8, 0x60($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800A3F38: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800A3F3C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800A3F40: swc1        $f18, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f18.u32l;
    // 0x800A3F44: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800A3F48: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800A3F4C: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800A3F50: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A3F54: lwc1        $f10, 0x80($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X80);
    // 0x800A3F58: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800A3F5C: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A3F60: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800A3F64: lwc1        $f8, 0x64($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X64);
    // 0x800A3F68: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800A3F6C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800A3F70: swc1        $f18, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->f18.u32l;
    // 0x800A3F74: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800A3F78: lwc1        $f18, 0x74($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800A3F7C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A3F80: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A3F84: lwc1        $f10, 0x84($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800A3F88: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800A3F8C: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800A3F90: jr          $ra
    // 0x800A3F94: swc1        $f18, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800A3F94: swc1        $f18, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f18.u32l;
;}

RECOMP_FUNC void func_800A3F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3F98: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3F9C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A3FA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3FA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A3FAC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800A3FB0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800A3FB4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800A3FB8: jal         0x800B036C
    // 0x800A3FBC: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    mtx4_rotate_euler(rdram, ctx);
        goto after_0;
    // 0x800A3FBC: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    after_0:
    // 0x800A3FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3FC8: jr          $ra
    // 0x800A3FCC: nop

    return;
    // 0x800A3FCC: nop

;}

RECOMP_FUNC void func_800A3FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3FD0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3FD4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A3FD8: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800A3FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3FE0: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800A3FE4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800A3FE8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800A3FEC: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x800A3FF0: jal         0x800B04BC
    // 0x800A3FF4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    mtx4_from_euler(rdram, ctx);
        goto after_0;
    // 0x800A3FF4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_0:
    // 0x800A3FF8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3FFC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800A4000: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800A4004: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    // 0x800A4008: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x800A400C: addiu       $t8, $a0, 0x3C
    ctx->r24 = ADD32(ctx->r4, 0X3C);
L_800A4010:
    // 0x800A4010: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800A4014: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800A4018: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800A401C: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x800A4020: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x800A4024: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x800A4028: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x800A402C: bne         $t9, $t8, L_800A4010
    if (ctx->r25 != ctx->r24) {
        // 0x800A4030: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_800A4010;
    }
    // 0x800A4030: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x800A4034: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800A4038: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x800A403C: jal         0x800AF558
    // 0x800A4040: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    mtx4_mult(rdram, ctx);
        goto after_1;
    // 0x800A4040: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    after_1:
    // 0x800A4044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4048: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x800A404C: jr          $ra
    // 0x800A4050: nop

    return;
    // 0x800A4050: nop

;}

RECOMP_FUNC void func_800A4054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4054: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x800A4058: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800A405C: addiu       $t8, $a1, 0x3C
    ctx->r24 = ADD32(ctx->r5, 0X3C);
L_800A4060:
    // 0x800A4060: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800A4064: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800A4068: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800A406C: sw          $at, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r1;
    // 0x800A4070: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x800A4074: sw          $at, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r1;
    // 0x800A4078: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x800A407C: bne         $t9, $t8, L_800A4060
    if (ctx->r25 != ctx->r24) {
        // 0x800A4080: sw          $at, 0x48($t0)
        MEM_W(0X48, ctx->r8) = ctx->r1;
            goto L_800A4060;
    }
    // 0x800A4080: sw          $at, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->r1;
    // 0x800A4084: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800A4088: jr          $ra
    // 0x800A408C: sw          $at, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->r1;
    return;
    // 0x800A408C: sw          $at, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->r1;
;}

RECOMP_FUNC void func_800A4090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4090: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4094: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x800A4098: jr          $ra
    // 0x800A409C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A409C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A40A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A40A0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A40A4: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800A40A8: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800A40AC: jr          $ra
    // 0x800A40B0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A40B0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A40B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A40B4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A40B8: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x800A40BC: jr          $ra
    // 0x800A40C0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A40C0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A40C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A40C4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A40C8: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800A40CC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800A40D0: jr          $ra
    // 0x800A40D4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A40D4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A40D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A40D8: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800A40DC: lw          $t6, 0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X34);
    // 0x800A40E0: bnel        $t6, $zero, L_800A40F4
    if (ctx->r14 != 0) {
        // 0x800A40E4: lw          $v0, 0x28($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X28);
            goto L_800A40F4;
    }
    goto skip_0;
    // 0x800A40E4: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    skip_0:
    // 0x800A40E8: jr          $ra
    // 0x800A40EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800A40EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A40F0: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
L_800A40F4:
    // 0x800A40F4: jr          $ra
    // 0x800A40F8: nop

    return;
    // 0x800A40F8: nop

;}

RECOMP_FUNC void func_800A40FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A40FC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A4100: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800A4104: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800A4108: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800A410C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800A4110: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800A4114: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800A4118: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800A411C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800A4120: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A4124: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800A4128: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800A412C: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800A4130: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800A4134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4138: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800A413C: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800A4140: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800A4144: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x800A4148: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800A414C: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800A4150: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x800A4154: jal         0x800BA660
    // 0x800A4158: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    guNormalize(rdram, ctx);
        goto after_0;
    // 0x800A4158: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x800A415C: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A4160: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A4164: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800A4168: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A416C: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800A4170: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800A4174: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800A4178: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800A417C: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A4180: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800A4184: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A4188: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800A418C: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800A4190: sub.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800A4194: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A4198: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800A419C: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x800A41A0: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800A41A4: sub.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800A41A8: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800A41AC: nop

    // 0x800A41B0: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800A41B4: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    // 0x800A41B8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800A41BC: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A41C0: jal         0x800B8340
    // 0x800A41C4: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A41C4: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_1:
    // 0x800A41C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A41CC: ldc1        $f6, 0x920($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X920);
    // 0x800A41D0: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800A41D4: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800A41D8: c.lt.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d < ctx->f6.d;
    // 0x800A41DC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800A41E0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A41E4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800A41E8: bc1f        L_800A4214
    if (!c1cs) {
        // 0x800A41EC: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_800A4214;
    }
    // 0x800A41EC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800A41F0: addiu       $t3, $t3, 0x61F0
    ctx->r11 = ADD32(ctx->r11, 0X61F0);
    // 0x800A41F4: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x800A41F8: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800A41FC: sw          $at, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r1;
    // 0x800A4200: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x800A4204: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x800A4208: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x800A420C: b           L_800A426C
    // 0x800A4210: sw          $at, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r1;
        goto L_800A426C;
    // 0x800A4210: sw          $at, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r1;
L_800A4214:
    // 0x800A4214: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A4218: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A421C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A4220: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800A4224: div.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f2.d);
    // 0x800A4228: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A422C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800A4230: addiu       $t7, $t7, 0x61F0
    ctx->r15 = ADD32(ctx->r15, 0X61F0);
    // 0x800A4234: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x800A4238: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800A423C: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A4240: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800A4244: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x800A4248: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800A424C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800A4250: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800A4254: lw          $at, 0x0($a2)
    ctx->r1 = MEM_W(ctx->r6, 0X0);
    // 0x800A4258: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x800A425C: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x800A4260: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x800A4264: lw          $at, 0x8($a2)
    ctx->r1 = MEM_W(ctx->r6, 0X8);
    // 0x800A4268: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
L_800A426C:
    // 0x800A426C: jal         0x800AFF34
    // 0x800A4270: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    vec3_cross(rdram, ctx);
        goto after_2;
    // 0x800A4270: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_2:
    // 0x800A4274: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800A4278: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A427C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A4280: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A4284: swc1        $f8, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->f8.u32l;
    // 0x800A4288: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A428C: swc1        $f4, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f4.u32l;
    // 0x800A4290: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A4294: swc1        $f10, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->f10.u32l;
    // 0x800A4298: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A429C: swc1        $f6, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->f6.u32l;
    // 0x800A42A0: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A42A4: swc1        $f8, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->f8.u32l;
    // 0x800A42A8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A42AC: swc1        $f4, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->f4.u32l;
    // 0x800A42B0: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A42B4: swc1        $f10, 0x6C($a3)
    MEM_W(0X6C, ctx->r7) = ctx->f10.u32l;
    // 0x800A42B8: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A42BC: swc1        $f6, 0x70($a3)
    MEM_W(0X70, ctx->r7) = ctx->f6.u32l;
    // 0x800A42C0: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A42C4: swc1        $f8, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f8.u32l;
    // 0x800A42C8: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800A42CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A42D0: swc1        $f4, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->f4.u32l;
    // 0x800A42D4: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800A42D8: swc1        $f10, 0x80($a3)
    MEM_W(0X80, ctx->r7) = ctx->f10.u32l;
    // 0x800A42DC: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800A42E0: swc1        $f0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->f0.u32l;
    // 0x800A42E4: swc1        $f0, 0x68($a3)
    MEM_W(0X68, ctx->r7) = ctx->f0.u32l;
    // 0x800A42E8: swc1        $f0, 0x78($a3)
    MEM_W(0X78, ctx->r7) = ctx->f0.u32l;
    // 0x800A42EC: swc1        $f8, 0x88($a3)
    MEM_W(0X88, ctx->r7) = ctx->f8.u32l;
    // 0x800A42F0: swc1        $f6, 0x84($a3)
    MEM_W(0X84, ctx->r7) = ctx->f6.u32l;
    // 0x800A42F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A42F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800A42FC: jr          $ra
    // 0x800A4300: nop

    return;
    // 0x800A4300: nop

;}

RECOMP_FUNC void func_800A4304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4304: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A4308: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A430C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A4310: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A4314: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A4318: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A431C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A4320: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A4324: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A4328: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A432C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800A4330: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800A4334: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800A4338: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A433C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800A4340: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800A4344: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x800A4348: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800A434C: jal         0x800A40FC
    // 0x800A4350: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_800A40FC(rdram, ctx);
        goto after_0;
    // 0x800A4350: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800A4354: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4358: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A435C: jr          $ra
    // 0x800A4360: nop

    return;
    // 0x800A4360: nop

;}

RECOMP_FUNC void func_800A4364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4364: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A4368: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A436C: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x800A4370: beq         $v0, $zero, L_800A437C
    if (ctx->r2 == 0) {
        // 0x800A4374: nop
    
            goto L_800A437C;
    }
    // 0x800A4374: nop

    // 0x800A4378: swc1        $f12, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f12.u32l;
L_800A437C:
    // 0x800A437C: jr          $ra
    // 0x800A4380: nop

    return;
    // 0x800A4380: nop

;}

RECOMP_FUNC void func_800A4384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4384: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A4388: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x800A438C: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x800A4390: bnel        $v0, $zero, L_800A43A8
    if (ctx->r2 != 0) {
        // 0x800A4394: lwc1        $f0, 0x14($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
            goto L_800A43A8;
    }
    goto skip_0;
    // 0x800A4394: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    skip_0:
    // 0x800A4398: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A439C: jr          $ra
    // 0x800A43A0: nop

    return;
    // 0x800A43A0: nop

    // 0x800A43A4: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
L_800A43A8:
    // 0x800A43A8: jr          $ra
    // 0x800A43AC: nop

    return;
    // 0x800A43AC: nop

;}

RECOMP_FUNC void func_800A43B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A43B0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A43B4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A43B8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A43BC: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x800A43C0: beq         $v0, $zero, L_800A43D8
    if (ctx->r2 == 0) {
        // 0x800A43C4: nop
    
            goto L_800A43D8;
    }
    // 0x800A43C4: nop

    // 0x800A43C8: swc1        $f12, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f12.u32l;
    // 0x800A43CC: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x800A43D0: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x800A43D4: swc1        $f14, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f14.u32l;
L_800A43D8:
    // 0x800A43D8: jr          $ra
    // 0x800A43DC: nop

    return;
    // 0x800A43DC: nop

;}

RECOMP_FUNC void func_800A43E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A43E0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A43E4: lui         $at, 0x467A
    ctx->r1 = S32(0X467A << 16);
    // 0x800A43E8: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x800A43EC: bnel        $v0, $zero, L_800A4404
    if (ctx->r2 != 0) {
        // 0x800A43F0: lwc1        $f0, 0x1C($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_800A4404;
    }
    goto skip_0;
    // 0x800A43F0: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    skip_0:
    // 0x800A43F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A43F8: jr          $ra
    // 0x800A43FC: nop

    return;
    // 0x800A43FC: nop

    // 0x800A4400: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
L_800A4404:
    // 0x800A4404: jr          $ra
    // 0x800A4408: nop

    return;
    // 0x800A4408: nop

;}

RECOMP_FUNC void func_800A440C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A440C: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A4410: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800A4414: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x800A4418: bnel        $v0, $zero, L_800A4430
    if (ctx->r2 != 0) {
        // 0x800A441C: lwc1        $f0, 0x18($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
            goto L_800A4430;
    }
    goto skip_0;
    // 0x800A441C: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    skip_0:
    // 0x800A4420: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A4424: jr          $ra
    // 0x800A4428: nop

    return;
    // 0x800A4428: nop

    // 0x800A442C: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
L_800A4430:
    // 0x800A4430: jr          $ra
    // 0x800A4434: nop

    return;
    // 0x800A4434: nop

;}

RECOMP_FUNC void func_800A4438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4438: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A443C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A4440: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x800A4444: beq         $v0, $zero, L_800A4450
    if (ctx->r2 == 0) {
        // 0x800A4448: nop
    
            goto L_800A4450;
    }
    // 0x800A4448: nop

    // 0x800A444C: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
L_800A4450:
    // 0x800A4450: jr          $ra
    // 0x800A4454: nop

    return;
    // 0x800A4454: nop

;}

RECOMP_FUNC void func_800A4458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4458: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A445C: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x800A4460: bnel        $v0, $zero, L_800A4478
    if (ctx->r2 != 0) {
        // 0x800A4464: lwc1        $f0, 0x10($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
            goto L_800A4478;
    }
    goto skip_0;
    // 0x800A4464: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x800A4468: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A446C: jr          $ra
    // 0x800A4470: nop

    return;
    // 0x800A4470: nop

    // 0x800A4474: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
L_800A4478:
    // 0x800A4478: jr          $ra
    // 0x800A447C: nop

    return;
    // 0x800A447C: nop

;}

RECOMP_FUNC void func_800A4480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4480: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A4484: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A4488: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x800A448C: beq         $v0, $zero, L_800A4498
    if (ctx->r2 == 0) {
        // 0x800A4490: nop
    
            goto L_800A4498;
    }
    // 0x800A4490: nop

    // 0x800A4494: swc1        $f12, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f12.u32l;
L_800A4498:
    // 0x800A4498: jr          $ra
    // 0x800A449C: nop

    return;
    // 0x800A449C: nop

;}

RECOMP_FUNC void func_800A44A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A44A0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A44A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A44A8: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x800A44AC: bnel        $v0, $zero, L_800A44C0
    if (ctx->r2 != 0) {
        // 0x800A44B0: lwc1        $f0, 0x24($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
            goto L_800A44C0;
    }
    goto skip_0;
    // 0x800A44B0: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    skip_0:
    // 0x800A44B4: jr          $ra
    // 0x800A44B8: lwc1        $f0, 0x928($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X928);
    return;
    // 0x800A44B8: lwc1        $f0, 0x928($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X928);
    // 0x800A44BC: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
L_800A44C0:
    // 0x800A44C0: jr          $ra
    // 0x800A44C4: nop

    return;
    // 0x800A44C4: nop

;}

RECOMP_FUNC void func_800A44C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A44C8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800A44CC: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800A44D0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800A44D4: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A44D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A44DC: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800A44E0: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x800A44E4: beql        $v0, $zero, L_800A4568
    if (ctx->r2 == 0) {
        // 0x800A44E8: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_800A4568;
    }
    goto skip_0;
    // 0x800A44E8: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_0:
    // 0x800A44EC: add.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800A44F0: lw          $v1, 0x28($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X28);
    // 0x800A44F4: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A44F8: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800A44FC: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x800A4500: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800A4504: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800A4508: nop

    // 0x800A450C: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x800A4510: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A4514: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800A4518: sub.s       $f10, $f14, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x800A451C: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x800A4520: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800A4524: add.d       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f16.d + ctx->f16.d;
    // 0x800A4528: add.d       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f18.d + ctx->f18.d;
    // 0x800A452C: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800A4530: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x800A4534: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800A4538: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800A453C: sh          $t0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r8;
    // 0x800A4540: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x800A4544: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A4548: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x800A454C: cvt.d.s     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f20.d = CVT_D_S(ctx->f10.fl);
    // 0x800A4550: add.d       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = ctx->f20.d + ctx->f20.d;
    // 0x800A4554: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x800A4558: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800A455C: nop

    // 0x800A4560: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
    // 0x800A4564: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
L_800A4568:
    // 0x800A4568: jr          $ra
    // 0x800A456C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800A456C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void func_800A4570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4570: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A4574: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A4578: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x800A457C: beq         $v0, $zero, L_800A4588
    if (ctx->r2 == 0) {
        // 0x800A4580: nop
    
            goto L_800A4588;
    }
    // 0x800A4580: nop

    // 0x800A4584: swc1        $f12, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f12.u32l;
L_800A4588:
    // 0x800A4588: jr          $ra
    // 0x800A458C: nop

    return;
    // 0x800A458C: nop

;}

RECOMP_FUNC void func_800A4590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4590: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4594: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x800A4598: jr          $ra
    // 0x800A459C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A459C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A45A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A45A0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A45A4: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800A45A8: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800A45AC: jr          $ra
    // 0x800A45B0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A45B0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A45B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A45B4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A45B8: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x800A45BC: jr          $ra
    // 0x800A45C0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A45C0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A45C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A45C4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A45C8: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800A45CC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800A45D0: jr          $ra
    // 0x800A45D4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A45D4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A45D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A45D8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A45DC: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x800A45E0: jr          $ra
    // 0x800A45E4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A45E4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A45E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A45E8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A45EC: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800A45F0: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800A45F4: jr          $ra
    // 0x800A45F8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A45F8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A45FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A45FC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4600: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x800A4604: jr          $ra
    // 0x800A4608: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A4608: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A460C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A460C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4610: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800A4614: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800A4618: jr          $ra
    // 0x800A461C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A461C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void CubeTiles_ObjReset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A469C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A46A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A46A4: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    // 0x800A46A8: jal         0x800A6DD8
    // 0x800A46AC: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    func_800A6DD8(rdram, ctx);
        goto after_0;
    // 0x800A46AC: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    after_0:
    // 0x800A46B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A46B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A46B8: jr          $ra
    // 0x800A46BC: nop

    return;
    // 0x800A46BC: nop

;}

RECOMP_FUNC void CubeTiles_ObjSetState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A46C0: jr          $ra
    // 0x800A46C4: sb          $a1, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r5;
    return;
    // 0x800A46C4: sb          $a1, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r5;
;}

RECOMP_FUNC void func_800A46C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A46C8: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A46CC: sll         $t8, $a1, 6
    ctx->r24 = S32(ctx->r5 << 6);
    // 0x800A46D0: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x800A46D4: jr          $ra
    // 0x800A46D8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x800A46D8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}

RECOMP_FUNC void func_800A46DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A46DC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A46E0: sll         $t8, $a2, 6
    ctx->r24 = S32(ctx->r6 << 6);
    // 0x800A46E4: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x800A46E8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800A46EC: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x800A46F0: lwc1        $f4, 0xF0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x800A46F4: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800A46F8: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x800A46FC: lwc1        $f6, 0xF4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XF4);
    // 0x800A4700: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800A4704: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x800A4708: lwc1        $f8, 0xF8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XF8);
    // 0x800A470C: jr          $ra
    // 0x800A4710: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    return;
    // 0x800A4710: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
;}

RECOMP_FUNC void func_800A4714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4714: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A4718: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A471C: sll         $t8, $a2, 6
    ctx->r24 = S32(ctx->r6 << 6);
    // 0x800A4720: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x800A4724: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800A4728: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x800A472C: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800A4730: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x800A4734: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800A4738: jr          $ra
    // 0x800A473C: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x800A473C: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
;}

RECOMP_FUNC void func_800A4740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4740: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A4744: nop

    // 0x800A4748: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800A474C: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800A4750: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x800A4754: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x800A4758: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x800A475C: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x800A4760: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x800A4764: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x800A4768: swc1        $f0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
    // 0x800A476C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800A4770: beq         $v0, $zero, L_800A4844
    if (ctx->r2 == 0) {
        // 0x800A4774: nop
    
            goto L_800A4844;
    }
    // 0x800A4774: nop

    // 0x800A4778: beq         $v0, $zero, L_800A4844
    if (ctx->r2 == 0) {
        // 0x800A477C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800A4844;
    }
    // 0x800A477C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800A4780: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
L_800A4784:
    // 0x800A4784: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800A4788: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800A478C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800A4790: lw          $t1, 0x1C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X1C);
    // 0x800A4794: lh          $t2, 0x16($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X16);
    // 0x800A4798: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800A479C: lwc1        $f0, 0x18($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X18);
L_800A47A0:
    // 0x800A47A0: andi        $t7, $t2, 0x1
    ctx->r15 = ctx->r10 & 0X1;
    // 0x800A47A4: beq         $t7, $zero, L_800A47B0
    if (ctx->r15 == 0) {
        // 0x800A47A8: sra         $t8, $t2, 1
        ctx->r24 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800A47B0;
    }
    // 0x800A47A8: sra         $t8, $t2, 1
    ctx->r24 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800A47AC: addiu       $t1, $t1, 0x14
    ctx->r9 = ADD32(ctx->r9, 0X14);
L_800A47B0:
    // 0x800A47B0: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x800A47B4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800A47B8: bne         $t3, $zero, L_800A47A0
    if (ctx->r11 != 0) {
        // 0x800A47BC: sra         $t2, $t9, 16
        ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
            goto L_800A47A0;
    }
    // 0x800A47BC: sra         $t2, $t9, 16
    ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800A47C0: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
L_800A47C4:
    // 0x800A47C4: andi        $t5, $t2, 0x1
    ctx->r13 = ctx->r10 & 0X1;
    // 0x800A47C8: beq         $t5, $zero, L_800A481C
    if (ctx->r13 == 0) {
        // 0x800A47CC: sra         $t9, $t2, 1
        ctx->r25 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800A481C;
    }
    // 0x800A47CC: sra         $t9, $t2, 1
    ctx->r25 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800A47D0: lw          $t6, 0x10($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X10);
    // 0x800A47D4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A47D8: addiu       $t1, $t1, 0x14
    ctx->r9 = ADD32(ctx->r9, 0X14);
    // 0x800A47DC: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800A47E0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A47E4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800A47E8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800A47EC: lw          $t7, -0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, -0X4);
    // 0x800A47F0: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A47F4: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800A47F8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800A47FC: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800A4800: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800A4804: lw          $t8, -0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, -0X4);
    // 0x800A4808: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800A480C: lwc1        $f10, 0x8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800A4810: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800A4814: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800A4818: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
L_800A481C:
    // 0x800A481C: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x800A4820: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x800A4824: sra         $t2, $t4, 16
    ctx->r10 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800A4828: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A482C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A4830: bne         $t3, $zero, L_800A47C4
    if (ctx->r11 != 0) {
        // 0x800A4834: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_800A47C4;
    }
    // 0x800A4834: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800A4838: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x800A483C: bnel        $v1, $zero, L_800A4784
    if (ctx->r3 != 0) {
        // 0x800A4840: lw          $t6, 0x20($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X20);
            goto L_800A4784;
    }
    goto skip_0;
    // 0x800A4840: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
    skip_0:
L_800A4844:
    // 0x800A4844: jr          $ra
    // 0x800A4848: nop

    return;
    // 0x800A4848: nop

;}

RECOMP_FUNC void func_800A484C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A484C: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A4850: sll         $t8, $a2, 6
    ctx->r24 = S32(ctx->r6 << 6);
    // 0x800A4854: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x800A4858: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800A485C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800A4860: bnel        $v1, $zero, L_800A4874
    if (ctx->r3 != 0) {
        // 0x800A4864: lw          $v0, 0x14($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X14);
            goto L_800A4874;
    }
    goto skip_0;
    // 0x800A4864: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    skip_0:
    // 0x800A4868: jr          $ra
    // 0x800A486C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    return;
    // 0x800A486C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800A4870: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
L_800A4874:
    // 0x800A4874: and         $t9, $v0, $a3
    ctx->r25 = ctx->r2 & ctx->r7;
    // 0x800A4878: bne         $t9, $zero, L_800A4888
    if (ctx->r25 != 0) {
        // 0x800A487C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A4888;
    }
    // 0x800A487C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A4880: jr          $ra
    // 0x800A4884: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    return;
    // 0x800A4884: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800A4888:
    // 0x800A4888: beq         $a3, $zero, L_800A48C4
    if (ctx->r7 == 0) {
        // 0x800A488C: lw          $a2, 0x1C($v1)
        ctx->r6 = MEM_W(ctx->r3, 0X1C);
            goto L_800A48C4;
    }
    // 0x800A488C: lw          $a2, 0x1C($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X1C);
L_800A4890:
    // 0x800A4890: andi        $t0, $a3, 0x1
    ctx->r8 = ctx->r7 & 0X1;
    // 0x800A4894: beq         $t0, $zero, L_800A48A8
    if (ctx->r8 == 0) {
        // 0x800A4898: sra         $t2, $a3, 1
        ctx->r10 = S32(SIGNED(ctx->r7) >> 1);
            goto L_800A48A8;
    }
    // 0x800A4898: sra         $t2, $a3, 1
    ctx->r10 = S32(SIGNED(ctx->r7) >> 1);
    // 0x800A489C: lh          $t1, 0x6($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X6);
    // 0x800A48A0: jr          $ra
    // 0x800A48A4: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    return;
    // 0x800A48A4: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_800A48A8:
    // 0x800A48A8: andi        $t3, $a0, 0x1
    ctx->r11 = ctx->r4 & 0X1;
    // 0x800A48AC: beq         $t3, $zero, L_800A48B8
    if (ctx->r11 == 0) {
        // 0x800A48B0: or          $a3, $t2, $zero
        ctx->r7 = ctx->r10 | 0;
            goto L_800A48B8;
    }
    // 0x800A48B0: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x800A48B4: addiu       $a2, $a2, 0x14
    ctx->r6 = ADD32(ctx->r6, 0X14);
L_800A48B8:
    // 0x800A48B8: sra         $t4, $a0, 1
    ctx->r12 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800A48BC: bne         $a3, $zero, L_800A4890
    if (ctx->r7 != 0) {
        // 0x800A48C0: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800A4890;
    }
    // 0x800A48C0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_800A48C4:
    // 0x800A48C4: jr          $ra
    // 0x800A48C8: nop

    return;
    // 0x800A48C8: nop

;}

RECOMP_FUNC void func_800A48CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A48CC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800A48D0: bltz        $a1, L_800A4900
    if (SIGNED(ctx->r5) < 0) {
        // 0x800A48D4: nop
    
            goto L_800A4900;
    }
    // 0x800A48D4: nop

    // 0x800A48D8: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800A48DC: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x800A48E0: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800A48E4: beq         $at, $zero, L_800A4900
    if (ctx->r1 == 0) {
        // 0x800A48E8: nop
    
            goto L_800A4900;
    }
    // 0x800A48E8: nop

    // 0x800A48EC: lw          $t7, 0x3C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X3C);
    // 0x800A48F0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800A48F4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A48F8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800A48FC: swc1        $f12, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f12.u32l;
L_800A4900:
    // 0x800A4900: jr          $ra
    // 0x800A4904: nop

    return;
    // 0x800A4904: nop

;}

RECOMP_FUNC void func_800A4908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4908: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A490C: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x800A4910: jr          $ra
    // 0x800A4914: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A4914: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A4918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4918: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A491C: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800A4920: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800A4924: jr          $ra
    // 0x800A4928: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A4928: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A492C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A492C: bgez        $a1, L_800A4938
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800A4930: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_800A4938;
    }
    // 0x800A4930: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800A4934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800A4938:
    // 0x800A4938: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x800A493C: bne         $at, $zero, L_800A4948
    if (ctx->r1 != 0) {
        // 0x800A4940: nop
    
            goto L_800A4948;
    }
    // 0x800A4940: nop

    // 0x800A4944: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_800A4948:
    // 0x800A4948: bgezl       $a2, L_800A4958
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800A494C: slti        $at, $a2, 0x100
        ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
            goto L_800A4958;
    }
    goto skip_0;
    // 0x800A494C: slti        $at, $a2, 0x100
    ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
    skip_0:
    // 0x800A4950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A4954: slti        $at, $a2, 0x100
    ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
L_800A4958:
    // 0x800A4958: bne         $at, $zero, L_800A4964
    if (ctx->r1 != 0) {
        // 0x800A495C: nop
    
            goto L_800A4964;
    }
    // 0x800A495C: nop

    // 0x800A4960: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_800A4964:
    // 0x800A4964: bgezl       $a3, L_800A4974
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800A4968: slti        $at, $a3, 0x100
        ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
            goto L_800A4974;
    }
    goto skip_1;
    // 0x800A4968: slti        $at, $a3, 0x100
    ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
    skip_1:
    // 0x800A496C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A4970: slti        $at, $a3, 0x100
    ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
L_800A4974:
    // 0x800A4974: bne         $at, $zero, L_800A4980
    if (ctx->r1 != 0) {
        // 0x800A4978: nop
    
            goto L_800A4980;
    }
    // 0x800A4978: nop

    // 0x800A497C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_800A4980:
    // 0x800A4980: bgezl       $v0, L_800A4990
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A4984: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_800A4990;
    }
    goto skip_2;
    // 0x800A4984: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    skip_2:
    // 0x800A4988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A498C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
L_800A4990:
    // 0x800A4990: bnel        $at, $zero, L_800A49A0
    if (ctx->r1 != 0) {
        // 0x800A4994: sb          $a1, 0x1D4($a0)
        MEM_B(0X1D4, ctx->r4) = ctx->r5;
            goto L_800A49A0;
    }
    goto skip_3;
    // 0x800A4994: sb          $a1, 0x1D4($a0)
    MEM_B(0X1D4, ctx->r4) = ctx->r5;
    skip_3:
    // 0x800A4998: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800A499C: sb          $a1, 0x1D4($a0)
    MEM_B(0X1D4, ctx->r4) = ctx->r5;
L_800A49A0:
    // 0x800A49A0: sb          $a2, 0x1D5($a0)
    MEM_B(0X1D5, ctx->r4) = ctx->r6;
    // 0x800A49A4: sb          $a3, 0x1D6($a0)
    MEM_B(0X1D6, ctx->r4) = ctx->r7;
    // 0x800A49A8: jr          $ra
    // 0x800A49AC: sb          $v0, 0x1D7($a0)
    MEM_B(0X1D7, ctx->r4) = ctx->r2;
    return;
    // 0x800A49AC: sb          $v0, 0x1D7($a0)
    MEM_B(0X1D7, ctx->r4) = ctx->r2;
;}

RECOMP_FUNC void func_800A49B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A49B0: bgez        $a1, L_800A49BC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800A49B4: lui         $t6, 0x1
        ctx->r14 = S32(0X1 << 16);
            goto L_800A49BC;
    }
    // 0x800A49B4: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800A49B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800A49BC:
    // 0x800A49BC: slti        $at, $a1, 0x3E9
    ctx->r1 = SIGNED(ctx->r5) < 0X3E9 ? 1 : 0;
    // 0x800A49C0: bne         $at, $zero, L_800A49CC
    if (ctx->r1 != 0) {
        // 0x800A49C4: ori         $t6, $t6, 0xF400
        ctx->r14 = ctx->r14 | 0XF400;
            goto L_800A49CC;
    }
    // 0x800A49C4: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800A49C8: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
L_800A49CC:
    // 0x800A49CC: bgezl       $a2, L_800A49DC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800A49D0: slti        $at, $a2, 0x3E9
        ctx->r1 = SIGNED(ctx->r6) < 0X3E9 ? 1 : 0;
            goto L_800A49DC;
    }
    goto skip_0;
    // 0x800A49D0: slti        $at, $a2, 0x3E9
    ctx->r1 = SIGNED(ctx->r6) < 0X3E9 ? 1 : 0;
    skip_0:
    // 0x800A49D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A49D8: slti        $at, $a2, 0x3E9
    ctx->r1 = SIGNED(ctx->r6) < 0X3E9 ? 1 : 0;
L_800A49DC:
    // 0x800A49DC: bne         $at, $zero, L_800A49E8
    if (ctx->r1 != 0) {
        // 0x800A49E0: nop
    
            goto L_800A49E8;
    }
    // 0x800A49E0: nop

    // 0x800A49E4: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
L_800A49E8:
    // 0x800A49E8: bnel        $a1, $a2, L_800A4A08
    if (ctx->r5 != ctx->r6) {
        // 0x800A49EC: subu        $v0, $a2, $a1
        ctx->r2 = SUB32(ctx->r6, ctx->r5);
            goto L_800A4A08;
    }
    goto skip_1;
    // 0x800A49EC: subu        $v0, $a2, $a1
    ctx->r2 = SUB32(ctx->r6, ctx->r5);
    skip_1:
    // 0x800A49F0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800A49F4: bgezl       $a1, L_800A4A08
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800A49F8: subu        $v0, $a2, $a1
        ctx->r2 = SUB32(ctx->r6, ctx->r5);
            goto L_800A4A08;
    }
    goto skip_2;
    // 0x800A49F8: subu        $v0, $a2, $a1
    ctx->r2 = SUB32(ctx->r6, ctx->r5);
    skip_2:
    // 0x800A49FC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A4A00: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800A4A04: subu        $v0, $a2, $a1
    ctx->r2 = SUB32(ctx->r6, ctx->r5);
L_800A4A08:
    // 0x800A4A08: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800A4A0C: negu        $t8, $a1
    ctx->r24 = SUB32(0, ctx->r5);
    // 0x800A4A10: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800A4A14: addu        $t0, $t9, $t6
    ctx->r8 = ADD32(ctx->r25, ctx->r14);
    // 0x800A4A18: mflo        $t7
    ctx->r15 = lo;
    // 0x800A4A1C: sw          $a1, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r5;
    // 0x800A4A20: sw          $a2, 0x1DC($a0)
    MEM_W(0X1DC, ctx->r4) = ctx->r6;
    // 0x800A4A24: div         $zero, $t0, $v0
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r2)));
    // 0x800A4A28: bne         $v0, $zero, L_800A4A34
    if (ctx->r2 != 0) {
        // 0x800A4A2C: nop
    
            goto L_800A4A34;
    }
    // 0x800A4A2C: nop

    // 0x800A4A30: break       7
    do_break(2148158000);
L_800A4A34:
    // 0x800A4A34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4A38: bne         $v0, $at, L_800A4A4C
    if (ctx->r2 != ctx->r1) {
        // 0x800A4A3C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A4A4C;
    }
    // 0x800A4A3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A4A40: bne         $t6, $at, L_800A4A4C
    if (ctx->r14 != ctx->r1) {
        // 0x800A4A44: nop
    
            goto L_800A4A4C;
    }
    // 0x800A4A44: nop

    // 0x800A4A48: break       6
    do_break(2148158024);
L_800A4A4C:
    // 0x800A4A4C: addu        $at, $t6, $zero
    ctx->r1 = ADD32(ctx->r14, 0);
    // 0x800A4A50: mflo        $t1
    ctx->r9 = lo;
    // 0x800A4A54: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x800A4A58: bne         $v0, $zero, L_800A4A64
    if (ctx->r2 != 0) {
        // 0x800A4A5C: nop
    
            goto L_800A4A64;
    }
    // 0x800A4A5C: nop

    // 0x800A4A60: break       7
    do_break(2148158048);
L_800A4A64:
    // 0x800A4A64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4A68: bne         $v0, $at, L_800A4A7C
    if (ctx->r2 != ctx->r1) {
        // 0x800A4A6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A4A7C;
    }
    // 0x800A4A6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A4A70: bne         $t0, $at, L_800A4A7C
    if (ctx->r8 != ctx->r1) {
        // 0x800A4A74: nop
    
            goto L_800A4A7C;
    }
    // 0x800A4A74: nop

    // 0x800A4A78: break       6
    do_break(2148158072);
L_800A4A7C:
    // 0x800A4A7C: sw          $t1, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r9;
    // 0x800A4A80: jr          $ra
    // 0x800A4A84: nop

    return;
    // 0x800A4A84: nop

;}

RECOMP_FUNC void func_800A4A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4A88: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A4A8C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800A4A90: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800A4A94: lw          $t7, 0x3C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3C);
    // 0x800A4A98: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x800A4A9C: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800A4AA0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A4AA4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800A4AA8: addu        $t2, $t2, $a2
    ctx->r10 = ADD32(ctx->r10, ctx->r6);
    // 0x800A4AAC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A4AB0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x800A4AB4: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x800A4AB8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A4ABC: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x800A4AC0: swl         $t3, 0x4($v0)
    do_swl(rdram, 0X4, ctx->r2, ctx->r11);
    // 0x800A4AC4: swr         $t3, 0x7($v0)
    do_swr(rdram, 0X7, ctx->r2, ctx->r11);
    // 0x800A4AC8: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800A4ACC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A4AD0: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800A4AD4: nop

    // 0x800A4AD8: swl         $t4, 0x8($v0)
    do_swl(rdram, 0X8, ctx->r2, ctx->r12);
    // 0x800A4ADC: swr         $t4, 0xB($v0)
    do_swr(rdram, 0XB, ctx->r2, ctx->r12);
    // 0x800A4AE0: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800A4AE4: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800A4AE8: nop

    // 0x800A4AEC: swl         $t5, 0xC($v0)
    do_swl(rdram, 0XC, ctx->r2, ctx->r13);
    // 0x800A4AF0: swr         $t5, 0xF($v0)
    do_swr(rdram, 0XF, ctx->r2, ctx->r13);
    // 0x800A4AF4: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A4AF8: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800A4AFC: c.eq.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d == ctx->f0.d;
    // 0x800A4B00: nop

    // 0x800A4B04: bc1fl       L_800A4B30
    if (!c1cs) {
        // 0x800A4B08: mtc1        $at, $f5
        ctx->f_odd[(5 - 1) * 2] = ctx->r1;
            goto L_800A4B30;
    }
    goto skip_0;
    // 0x800A4B08: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800A4B0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A4B10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A4B14: nop

    // 0x800A4B18: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800A4B1C: nop

    // 0x800A4B20: swl         $t6, 0x10($v0)
    do_swl(rdram, 0X10, ctx->r2, ctx->r14);
    // 0x800A4B24: jr          $ra
    // 0x800A4B28: swr         $t6, 0x13($v0)
    do_swr(rdram, 0X13, ctx->r2, ctx->r14);
    return;
    // 0x800A4B28: swr         $t6, 0x13($v0)
    do_swr(rdram, 0X13, ctx->r2, ctx->r14);
    // 0x800A4B2C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
L_800A4B30:
    // 0x800A4B30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A4B34: nop

    // 0x800A4B38: sub.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d - ctx->f0.d;
    // 0x800A4B3C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800A4B40: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800A4B44: nop

    // 0x800A4B48: swl         $t7, 0x10($v0)
    do_swl(rdram, 0X10, ctx->r2, ctx->r15);
    // 0x800A4B4C: swr         $t7, 0x13($v0)
    do_swr(rdram, 0X13, ctx->r2, ctx->r15);
    // 0x800A4B50: jr          $ra
    // 0x800A4B54: nop

    return;
    // 0x800A4B54: nop

;}

RECOMP_FUNC void func_800A4B58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4B58: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4B5C: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x800A4B60: jr          $ra
    // 0x800A4B64: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A4B64: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void func_800A4B68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4B68: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4B6C: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x800A4B70: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800A4B74: jr          $ra
    // 0x800A4B78: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800A4B78: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A4B7C: nop

;}

RECOMP_FUNC void func_800A4B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4B80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A4B84: jr          $ra
    // 0x800A4B88: sw          $zero, 0x6204($at)
    MEM_W(0X6204, ctx->r1) = 0;
    return;
    // 0x800A4B88: sw          $zero, 0x6204($at)
    MEM_W(0X6204, ctx->r1) = 0;
;}

RECOMP_FUNC void func_800A4B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4B8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A4B90: jr          $ra
    // 0x800A4B94: sw          $a0, 0x6200($at)
    MEM_W(0X6200, ctx->r1) = ctx->r4;
    return;
    // 0x800A4B94: sw          $a0, 0x6200($at)
    MEM_W(0X6200, ctx->r1) = ctx->r4;
;}

RECOMP_FUNC void func_800A4B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4B98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A4B9C: lui         $t6, 0xDB06
    ctx->r14 = S32(0XDB06 << 16);
    // 0x800A4BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4BA4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A4BA8: ori         $t6, $t6, 0x2C
    ctx->r14 = ctx->r14 | 0X2C;
    // 0x800A4BAC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A4BB0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800A4BB4: addiu       $a2, $a0, 0x8
    ctx->r6 = ADD32(ctx->r4, 0X8);
    // 0x800A4BB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A4BBC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A4BC0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800A4BC4: jal         0x800B87A0
    // 0x800A4BC8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800A4BC8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x800A4BCC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800A4BD0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A4BD4: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800A4BD8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800A4BDC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800A4BE0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A4BE4: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800A4BE8: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    // 0x800A4BEC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A4BF0: jal         0x800B87A0
    // 0x800A4BF4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800A4BF4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x800A4BF8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800A4BFC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800A4C00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A4C04: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800A4C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4C0C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800A4C10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A4C14: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800A4C18: jr          $ra
    // 0x800A4C1C: sw          $t9, 0x6204($at)
    MEM_W(0X6204, ctx->r1) = ctx->r25;
    return;
    // 0x800A4C1C: sw          $t9, 0x6204($at)
    MEM_W(0X6204, ctx->r1) = ctx->r25;
;}

RECOMP_FUNC void func_800A4C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4C20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A4C24: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A4C28: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A4C2C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A4C30: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A4C34: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A4C38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4C3C: lw          $t6, 0x28($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X28);
    // 0x800A4C40: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800A4C44: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800A4C48: beq         $t6, $zero, L_800A4C7C
    if (ctx->r14 == 0) {
        // 0x800A4C4C: or          $s0, $s3, $zero
        ctx->r16 = ctx->r19 | 0;
            goto L_800A4C7C;
    }
    // 0x800A4C4C: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800A4C50: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x800A4C54: ori         $t7, $t7, 0x28
    ctx->r15 = ctx->r15 | 0X28;
    // 0x800A4C58: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800A4C5C: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800A4C60: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A4C64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A4C68: addiu       $s3, $a0, 0x8
    ctx->r19 = ADD32(ctx->r4, 0X8);
    // 0x800A4C6C: jal         0x800B87A0
    // 0x800A4C70: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800A4C70: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    after_0:
    // 0x800A4C74: b           L_800A4C98
    // 0x800A4C78: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_800A4C98;
    // 0x800A4C78: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_800A4C7C:
    // 0x800A4C7C: lui         $t0, 0xDB06
    ctx->r8 = S32(0XDB06 << 16);
    // 0x800A4C80: ori         $t0, $t0, 0x28
    ctx->r8 = ctx->r8 | 0X28;
    // 0x800A4C84: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800A4C88: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    // 0x800A4C8C: jal         0x800B87A0
    // 0x800A4C90: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800A4C90: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    after_1:
    // 0x800A4C94: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_800A4C98:
    // 0x800A4C98: lw          $s0, 0x14($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X14);
    // 0x800A4C9C: lw          $s1, 0x1C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X1C);
    // 0x800A4CA0: lui         $s4, 0xDE00
    ctx->r20 = S32(0XDE00 << 16);
    // 0x800A4CA4: beq         $s0, $zero, L_800A4CCC
    if (ctx->r16 == 0) {
        // 0x800A4CA8: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_800A4CCC;
    }
L_800A4CA8:
    // 0x800A4CA8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x800A4CAC: sw          $s4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r20;
    // 0x800A4CB0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A4CB4: jal         0x800B87A0
    // 0x800A4CB8: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800A4CB8: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    after_2:
    // 0x800A4CBC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800A4CC0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800A4CC4: bne         $s0, $zero, L_800A4CA8
    if (ctx->r16 != 0) {
        // 0x800A4CC8: sw          $v0, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r2;
            goto L_800A4CA8;
    }
    // 0x800A4CC8: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_800A4CCC:
    // 0x800A4CCC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4CD0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800A4CD4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A4CD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4CDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A4CE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A4CE4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A4CE8: jr          $ra
    // 0x800A4CEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A4CEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void func_800A4CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4CF0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800A4CF4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A4CF8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800A4CFC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800A4D00: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800A4D04: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800A4D08: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800A4D0C: lwc1        $f20, 0x10($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800A4D10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4D14: ldc1        $f0, 0x9C8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X9C8);
    // 0x800A4D18: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x800A4D1C: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800A4D20: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800A4D24: lwc1        $f22, 0x18($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800A4D28: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x800A4D2C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800A4D30: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800A4D34: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x800A4D38: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800A4D3C: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x800A4D40: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800A4D44: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x800A4D48: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x800A4D4C: jal         0x800B7B40
    // 0x800A4D50: cvt.s.d     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f22.fl = CVT_S_D(ctx->f6.d);
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A4D50: cvt.s.d     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f22.fl = CVT_S_D(ctx->f6.d);
    after_0:
    // 0x800A4D54: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800A4D58: jal         0x800B81D0
    // 0x800A4D5C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A4D5C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800A4D60: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800A4D64: jal         0x800B7B40
    // 0x800A4D68: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800A4D68: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x800A4D6C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800A4D70: jal         0x800B81D0
    // 0x800A4D74: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x800A4D74: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800A4D78: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800A4D7C: jal         0x800B7B40
    // 0x800A4D80: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x800A4D80: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_4:
    // 0x800A4D84: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800A4D88: jal         0x800B81D0
    // 0x800A4D8C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x800A4D8C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800A4D90: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A4D94: lwc1        $f22, 0x4C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A4D98: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A4D9C: lwc1        $f8, 0x30($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800A4DA0: mul.s       $f12, $f14, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x800A4DA4: lwc1        $f16, 0x28($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800A4DA8: lwc1        $f18, 0x2C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800A4DAC: mul.s       $f10, $f20, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800A4DB0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800A4DB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A4DB8: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800A4DBC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800A4DC0: neg.s       $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = -ctx->f20.fl;
    // 0x800A4DC4: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800A4DC8: nop

    // 0x800A4DCC: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800A4DD0: nop

    // 0x800A4DD4: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800A4DD8: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x800A4DDC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A4DE0: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800A4DE4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x800A4DE8: mul.s       $f4, $f14, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x800A4DEC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A4DF0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A4DF4: nop

    // 0x800A4DF8: mul.s       $f10, $f24, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800A4DFC: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x800A4E00: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A4E04: neg.s       $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = -ctx->f22.fl;
    // 0x800A4E08: mul.s       $f6, $f24, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800A4E0C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800A4E10: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800A4E14: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800A4E18: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A4E1C: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
    // 0x800A4E20: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A4E24: nop

    // 0x800A4E28: mul.s       $f12, $f20, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800A4E2C: nop

    // 0x800A4E30: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A4E34: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800A4E38: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800A4E3C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800A4E40: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800A4E44: nop

    // 0x800A4E48: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800A4E4C: nop

    // 0x800A4E50: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800A4E54: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800A4E58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A4E5C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800A4E60: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800A4E64: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x800A4E68: mul.s       $f10, $f20, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800A4E6C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A4E70: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A4E74: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x800A4E78: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800A4E7C: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x800A4E80: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800A4E84: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x800A4E88: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800A4E8C: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800A4E90: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800A4E94: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x800A4E98: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x800A4E9C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x800A4EA0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A4EA4: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800A4EA8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4EAC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800A4EB0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800A4EB4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800A4EB8: jr          $ra
    // 0x800A4EBC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800A4EBC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}

RECOMP_FUNC void func_800A4EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4EC0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800A4EC4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A4EC8: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x800A4ECC: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x800A4ED0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x800A4ED4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800A4ED8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800A4EDC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800A4EE0: lwc1        $f20, 0x10($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800A4EE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4EE8: ldc1        $f0, 0x9D0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X9D0);
    // 0x800A4EEC: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x800A4EF0: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800A4EF4: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800A4EF8: lwc1        $f26, 0x18($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800A4EFC: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x800A4F00: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800A4F04: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800A4F08: cvt.d.s     $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f4.d = CVT_D_S(ctx->f26.fl);
    // 0x800A4F0C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800A4F10: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x800A4F14: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800A4F18: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x800A4F1C: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    // 0x800A4F20: jal         0x800B7B40
    // 0x800A4F24: cvt.s.d     $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f26.fl = CVT_S_D(ctx->f6.d);
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A4F24: cvt.s.d     $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f26.fl = CVT_S_D(ctx->f6.d);
    after_0:
    // 0x800A4F28: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800A4F2C: jal         0x800B81D0
    // 0x800A4F30: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A4F30: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_1:
    // 0x800A4F34: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800A4F38: jal         0x800B7B40
    // 0x800A4F3C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800A4F3C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x800A4F40: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800A4F44: jal         0x800B81D0
    // 0x800A4F48: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x800A4F48: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x800A4F4C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800A4F50: jal         0x800B7B40
    // 0x800A4F54: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x800A4F54: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_4:
    // 0x800A4F58: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x800A4F5C: jal         0x800B81D0
    // 0x800A4F60: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x800A4F60: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800A4F64: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800A4F68: lwc1        $f12, 0x28($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800A4F6C: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A4F70: lwc1        $f16, 0x2C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800A4F74: lwc1        $f18, 0x30($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800A4F78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A4F7C: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x800A4F80: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800A4F84: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800A4F88: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A4F8C: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800A4F90: nop

    // 0x800A4F94: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800A4F98: nop

    // 0x800A4F9C: mul.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800A4FA0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A4FA4: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800A4FA8: nop

    // 0x800A4FAC: mul.s       $f8, $f14, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x800A4FB0: nop

    // 0x800A4FB4: mul.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800A4FB8: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800A4FBC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A4FC0: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800A4FC4: nop

    // 0x800A4FC8: mul.s       $f8, $f14, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800A4FCC: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800A4FD0: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800A4FD4: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x800A4FD8: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A4FDC: mul.s       $f2, $f14, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800A4FE0: nop

    // 0x800A4FE4: mul.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800A4FE8: nop

    // 0x800A4FEC: mul.s       $f8, $f2, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800A4FF0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A4FF4: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x800A4FF8: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A4FFC: nop

    // 0x800A5000: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800A5004: nop

    // 0x800A5008: mul.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800A500C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x800A5010: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A5014: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800A5018: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800A501C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A5020: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800A5024: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800A5028: nop

    // 0x800A502C: mul.s       $f6, $f20, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800A5030: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x800A5034: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800A5038: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800A503C: nop

    // 0x800A5040: mul.s       $f10, $f20, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800A5044: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x800A5048: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800A504C: mul.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A5050: swc1        $f14, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f14.u32l;
    // 0x800A5054: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x800A5058: lwc1        $f2, 0x38($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X38);
    // 0x800A505C: lwc1        $f12, 0x3C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x800A5060: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A5064: nop

    // 0x800A5068: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800A506C: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800A5070: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A5074: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800A5078: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800A507C: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800A5080: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A5084: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800A5088: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800A508C: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800A5090: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800A5094: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800A5098: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800A509C: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A50A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A50A4: add.s       $f22, $f10, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800A50A8: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800A50AC: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800A50B0: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800A50B4: mul.s       $f10, $f14, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800A50B8: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800A50BC: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800A50C0: add.s       $f26, $f6, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A50C4: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x800A50C8: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800A50CC: sub.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x800A50D0: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x800A50D4: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800A50D8: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800A50DC: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800A50E0: sub.s       $f8, $f4, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x800A50E4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x800A50E8: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x800A50EC: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    // 0x800A50F0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A50F4: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800A50F8: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800A50FC: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x800A5100: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800A5104: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800A5108: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800A510C: jr          $ra
    // 0x800A5110: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800A5110: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}

RECOMP_FUNC void func_800A5114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5114: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A5118: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A511C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800A5120: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800A5124: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800A5128: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800A512C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800A5130: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A5134: ldc1        $f20, 0x9D8($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X9D8);
    // 0x800A5138: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A513C: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x800A5140: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A5144: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800A5148: mul.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x800A514C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800A5150: jal         0x800B7B40
    // 0x800A5154: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A5154: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_0:
    // 0x800A5158: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800A515C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800A5160: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800A5164: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A5168: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A516C: mul.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x800A5170: jal         0x800B81D0
    // 0x800A5174: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A5174: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_1:
    // 0x800A5178: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800A517C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800A5180: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800A5184: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A5188: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A518C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A5190: mul.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x800A5194: jal         0x800B7B40
    // 0x800A5198: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800A5198: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_2:
    // 0x800A519C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800A51A0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800A51A4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A51A8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A51AC: mul.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x800A51B0: jal         0x800B81D0
    // 0x800A51B4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x800A51B4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_3:
    // 0x800A51B8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800A51BC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A51C0: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800A51C4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A51C8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A51CC: mul.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x800A51D0: jal         0x800B7B40
    // 0x800A51D4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x800A51D4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_4:
    // 0x800A51D8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800A51DC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800A51E0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A51E4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A51E8: mul.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x800A51EC: jal         0x800B81D0
    // 0x800A51F0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x800A51F0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_5:
    // 0x800A51F4: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800A51F8: lwc1        $f20, 0x38($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A51FC: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A5200: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A5204: mul.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800A5208: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A520C: swc1        $f20, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f20.u32l;
    // 0x800A5210: mul.s       $f6, $f16, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800A5214: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x800A5218: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A521C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x800A5220: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800A5224: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A5228: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800A522C: nop

    // 0x800A5230: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800A5234: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    // 0x800A5238: neg.s       $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = -ctx->f16.fl;
    // 0x800A523C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A5240: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800A5244: nop

    // 0x800A5248: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800A524C: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x800A5250: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800A5254: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x800A5258: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800A525C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A5260: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A5264: nop

    // 0x800A5268: mul.s       $f6, $f18, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800A526C: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x800A5270: neg.s       $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = -ctx->f22.fl;
    // 0x800A5274: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A5278: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800A527C: nop

    // 0x800A5280: mul.s       $f6, $f22, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x800A5284: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    // 0x800A5288: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    // 0x800A528C: swc1        $f6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f6.u32l;
    // 0x800A5290: lwc1        $f8, -0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, -0X14);
    // 0x800A5294: swc1        $f8, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f8.u32l;
    // 0x800A5298: lwc1        $f10, -0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, -0X10);
    // 0x800A529C: swc1        $f10, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f10.u32l;
    // 0x800A52A0: lwc1        $f4, -0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0XC);
    // 0x800A52A4: swc1        $f4, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f4.u32l;
    // 0x800A52A8: lwc1        $f6, -0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, -0X8);
    // 0x800A52AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A52B0: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    // 0x800A52B4: lwc1        $f8, -0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, -0X4);
    // 0x800A52B8: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x800A52BC: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800A52C0: swc1        $f4, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f4.u32l;
    // 0x800A52C4: swc1        $f10, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f10.u32l;
    // 0x800A52C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A52CC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800A52D0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800A52D4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800A52D8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800A52DC: jr          $ra
    // 0x800A52E0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800A52E0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}

RECOMP_FUNC void func_800A52E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A52E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A52E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A52EC: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800A52F0: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x800A52F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A52F8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800A52FC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A5300: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800A5304: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800A5308: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800A530C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800A5310: c.eq.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d == ctx->f16.d;
    // 0x800A5314: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800A5318: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800A531C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800A5320: bc1f        L_800A5368
    if (!c1cs) {
        // 0x800A5324: swc1        $f8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
            goto L_800A5368;
    }
    // 0x800A5324: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800A5328: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A532C: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A5330: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800A5334: c.eq.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d == ctx->f4.d;
    // 0x800A5338: nop

    // 0x800A533C: bc1fl       L_800A536C
    if (!c1cs) {
        // 0x800A5340: addiu       $a2, $sp, 0x1C
        ctx->r6 = ADD32(ctx->r29, 0X1C);
            goto L_800A536C;
    }
    goto skip_0;
    // 0x800A5340: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    skip_0:
    // 0x800A5344: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A5348: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A534C: c.eq.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d == ctx->f8.d;
    // 0x800A5350: nop

    // 0x800A5354: bc1fl       L_800A536C
    if (!c1cs) {
        // 0x800A5358: addiu       $a2, $sp, 0x1C
        ctx->r6 = ADD32(ctx->r29, 0X1C);
            goto L_800A536C;
    }
    goto skip_1;
    // 0x800A5358: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    skip_1:
    // 0x800A535C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A5360: nop

    // 0x800A5364: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
L_800A5368:
    // 0x800A5368: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
L_800A536C:
    // 0x800A536C: jal         0x800BA660
    // 0x800A5370: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    guNormalize(rdram, ctx);
        goto after_0;
    // 0x800A5370: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A5374: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A5378: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A537C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A5380: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A5384: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x800A5388: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x800A538C: swc1        $f0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
    // 0x800A5390: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
    // 0x800A5394: swc1        $f0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f0.u32l;
    // 0x800A5398: swc1        $f0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f0.u32l;
    // 0x800A539C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A53A0: swc1        $f10, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f10.u32l;
    // 0x800A53A4: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A53A8: swc1        $f16, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f16.u32l;
    // 0x800A53AC: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A53B0: swc1        $f0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f0.u32l;
    // 0x800A53B4: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
    // 0x800A53B8: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
    // 0x800A53BC: swc1        $f2, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f2.u32l;
    // 0x800A53C0: swc1        $f2, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f2.u32l;
    // 0x800A53C4: swc1        $f2, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f2.u32l;
    // 0x800A53C8: swc1        $f2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f2.u32l;
    // 0x800A53CC: swc1        $f18, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f18.u32l;
    // 0x800A53D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A53D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A53D8: jr          $ra
    // 0x800A53DC: nop

    return;
    // 0x800A53DC: nop

;}

RECOMP_FUNC void func_800A53E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A53E0: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800A53E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A53E8: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x800A53EC: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800A53F0: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800A53F4: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800A53F8: lwc1        $f12, 0x18($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800A53FC: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x800A5400: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800A5404: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800A5408: mtc1        $zero, $f15
    ctx->f_odd[(15 - 1) * 2] = 0;
    // 0x800A540C: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x800A5410: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800A5414: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800A5418: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800A541C: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x800A5420: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800A5424: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800A5428: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x800A542C: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800A5430: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800A5434: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800A5438: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800A543C: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    // 0x800A5440: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x800A5444: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800A5448: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x800A544C: lwc1        $f2, 0x8C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800A5450: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800A5454: c.eq.d      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.d == ctx->f6.d;
    // 0x800A5458: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    // 0x800A545C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800A5460: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800A5464: bc1f        L_800A54A8
    if (!c1cs) {
        // 0x800A5468: swc1        $f12, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
            goto L_800A54A8;
    }
    // 0x800A5468: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    // 0x800A546C: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800A5470: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800A5474: c.eq.d      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.d == ctx->f8.d;
    // 0x800A5478: nop

    // 0x800A547C: bc1f        L_800A54A8
    if (!c1cs) {
        // 0x800A5480: nop
    
            goto L_800A54A8;
    }
    // 0x800A5480: nop

    // 0x800A5484: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800A5488: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800A548C: c.eq.d      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.d == ctx->f10.d;
    // 0x800A5490: nop

    // 0x800A5494: bc1f        L_800A54A8
    if (!c1cs) {
        // 0x800A5498: nop
    
            goto L_800A54A8;
    }
    // 0x800A5498: nop

    // 0x800A549C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A54A0: nop

    // 0x800A54A4: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
L_800A54A8:
    // 0x800A54A8: jal         0x800BA660
    // 0x800A54AC: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    guNormalize(rdram, ctx);
        goto after_0;
    // 0x800A54AC: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    after_0:
    // 0x800A54B0: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800A54B4: lwc1        $f14, 0x90($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800A54B8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A54BC: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800A54C0: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x800A54C4: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x800A54C8: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x800A54CC: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x800A54D0: swc1        $f14, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f14.u32l;
    // 0x800A54D4: jal         0x800BA660
    // 0x800A54D8: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    guNormalize(rdram, ctx);
        goto after_1;
    // 0x800A54D8: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x800A54DC: lwc1        $f2, 0x8C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800A54E0: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800A54E4: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800A54E8: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800A54EC: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800A54F0: lwc1        $f14, 0x7C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800A54F4: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800A54F8: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800A54FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A5500: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x800A5504: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x800A5508: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800A550C: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A5510: mul.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800A5514: nop

    // 0x800A5518: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A551C: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x800A5520: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800A5524: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A5528: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800A552C: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x800A5530: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A5534: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A5538: ldc1        $f8, 0x9E0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X9E0);
    // 0x800A553C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800A5540: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x800A5544: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800A5548: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x800A554C: jal         0x800B81D0
    // 0x800A5550: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x800A5550: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x800A5554: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A5558: jal         0x800B7B40
    // 0x800A555C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x800A555C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800A5560: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800A5564: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800A5568: lwc1        $f14, 0x70($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A556C: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800A5570: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800A5574: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800A5578: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800A557C: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800A5580: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A5584: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A5588: addiu       $t2, $sp, 0x2C
    ctx->r10 = ADD32(ctx->r29, 0X2C);
    // 0x800A558C: addiu       $t5, $t2, 0x3C
    ctx->r13 = ADD32(ctx->r10, 0X3C);
    // 0x800A5590: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x800A5594: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x800A5598: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A559C: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800A55A0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800A55A4: swc1        $f12, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f12.u32l;
    // 0x800A55A8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800A55AC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x800A55B0: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x800A55B4: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800A55B8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A55BC: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800A55C0: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800A55C4: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800A55C8: nop

    // 0x800A55CC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800A55D0: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800A55D4: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A55D8: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800A55DC: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x800A55E0: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A55E4: nop

    // 0x800A55E8: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800A55EC: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800A55F0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800A55F4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800A55F8: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A55FC: nop

    // 0x800A5600: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800A5604: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A5608: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800A560C: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800A5610: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A5614: nop

    // 0x800A5618: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800A561C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A5620: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
L_800A5624:
    // 0x800A5624: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800A5628: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x800A562C: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x800A5630: sw          $at, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r1;
    // 0x800A5634: lw          $at, -0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X8);
    // 0x800A5638: sw          $at, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r1;
    // 0x800A563C: lw          $at, -0x4($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X4);
    // 0x800A5640: bne         $t2, $t5, L_800A5624
    if (ctx->r10 != ctx->r13) {
        // 0x800A5644: sw          $at, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r1;
            goto L_800A5624;
    }
    // 0x800A5644: sw          $at, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r1;
    // 0x800A5648: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800A564C: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800A5650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5654: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x800A5658: jr          $ra
    // 0x800A565C: nop

    return;
    // 0x800A565C: nop

;}

RECOMP_FUNC void func_800A5660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5668: lbu         $t6, 0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2);
    // 0x800A566C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x800A5670: beq         $at, $zero, L_800A56D4
    if (ctx->r1 == 0) {
        // 0x800A5674: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800A56D4;
    }
    // 0x800A5674: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A5678: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A567C: addu        $at, $at, $t6
    gpr jr_addend_800A5684 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A5680: lw          $t6, 0x9E8($at)
    ctx->r14 = ADD32(ctx->r1, 0X9E8);
    // 0x800A5684: jr          $t6
    // 0x800A5688: nop

    switch (jr_addend_800A5684 >> 2) {
        case 0: goto L_800A568C; break;
        case 1: goto L_800A569C; break;
        case 2: goto L_800A56AC; break;
        case 3: goto L_800A56BC; break;
        case 4: goto L_800A56CC; break;
        default: switch_error(__func__, 0x800A5684, 0x800E09E8);
    }
    // 0x800A5688: nop

L_800A568C:
    // 0x800A568C: jal         0x800A4CF0
    // 0x800A5690: nop

    func_800A4CF0(rdram, ctx);
        goto after_0;
    // 0x800A5690: nop

    after_0:
    // 0x800A5694: b           L_800A56D8
    // 0x800A5698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A56D8;
    // 0x800A5698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A569C:
    // 0x800A569C: jal         0x800A4EC0
    // 0x800A56A0: nop

    func_800A4EC0(rdram, ctx);
        goto after_1;
    // 0x800A56A0: nop

    after_1:
    // 0x800A56A4: b           L_800A56D8
    // 0x800A56A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A56D8;
    // 0x800A56A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A56AC:
    // 0x800A56AC: jal         0x800A5114
    // 0x800A56B0: nop

    func_800A5114(rdram, ctx);
        goto after_2;
    // 0x800A56B0: nop

    after_2:
    // 0x800A56B4: b           L_800A56D8
    // 0x800A56B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A56D8;
    // 0x800A56B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A56BC:
    // 0x800A56BC: jal         0x800A52E4
    // 0x800A56C0: nop

    func_800A52E4(rdram, ctx);
        goto after_3;
    // 0x800A56C0: nop

    after_3:
    // 0x800A56C4: b           L_800A56D8
    // 0x800A56C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A56D8;
    // 0x800A56C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A56CC:
    // 0x800A56CC: jal         0x800A53E0
    // 0x800A56D0: nop

    func_800A53E0(rdram, ctx);
        goto after_4;
    // 0x800A56D0: nop

    after_4:
L_800A56D4:
    // 0x800A56D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A56D8:
    // 0x800A56D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A56DC: jr          $ra
    // 0x800A56E0: nop

    return;
    // 0x800A56E0: nop

;}

RECOMP_FUNC void func_800A56E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A56E4: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800A56E8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A56EC: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800A56F0: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800A56F4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800A56F8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A56FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A5700: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800A5704: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A5708: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800A570C: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x800A5710: swc1        $f12, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f12.u32l;
    // 0x800A5714: swc1        $f14, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f14.u32l;
    // 0x800A5718: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800A571C: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800A5720: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800A5724: lwc1        $f14, 0x18($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800A5728: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800A572C: nop

    // 0x800A5730: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800A5734: nop

    // 0x800A5738: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800A573C: swc1        $f2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f2.u32l;
    // 0x800A5740: swc1        $f12, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f12.u32l;
    // 0x800A5744: swc1        $f14, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f14.u32l;
    // 0x800A5748: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800A574C: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800A5750: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800A5754: lwc1        $f14, 0x28($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800A5758: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800A575C: nop

    // 0x800A5760: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800A5764: nop

    // 0x800A5768: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800A576C: swc1        $f2, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f2.u32l;
    // 0x800A5770: swc1        $f12, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f12.u32l;
    // 0x800A5774: swc1        $f14, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f14.u32l;
    // 0x800A5778: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800A577C: swc1        $f4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f4.u32l;
    // 0x800A5780: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800A5784: swc1        $f6, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f6.u32l;
    // 0x800A5788: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800A578C: swc1        $f16, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f16.u32l;
    // 0x800A5790: swc1        $f16, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f16.u32l;
    // 0x800A5794: swc1        $f16, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f16.u32l;
    // 0x800A5798: swc1        $f10, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f10.u32l;
    // 0x800A579C: jr          $ra
    // 0x800A57A0: swc1        $f8, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f8.u32l;
    return;
    // 0x800A57A0: swc1        $f8, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f8.u32l;
;}

RECOMP_FUNC void func_800A57A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A57A4: beq         $a1, $a0, L_800A57E0
    if (ctx->r5 == ctx->r4) {
        // 0x800A57A8: or          $t8, $a0, $zero
        ctx->r24 = ctx->r4 | 0;
            goto L_800A57E0;
    }
    // 0x800A57A8: or          $t8, $a0, $zero
    ctx->r24 = ctx->r4 | 0;
    // 0x800A57AC: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x800A57B0: addiu       $t7, $a0, 0x3C
    ctx->r15 = ADD32(ctx->r4, 0X3C);
L_800A57B4:
    // 0x800A57B4: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x800A57B8: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800A57BC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800A57C0: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x800A57C4: lw          $at, -0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X8);
    // 0x800A57C8: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x800A57CC: lw          $at, -0x4($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X4);
    // 0x800A57D0: bne         $t8, $t7, L_800A57B4
    if (ctx->r24 != ctx->r15) {
        // 0x800A57D4: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_800A57B4;
    }
    // 0x800A57D4: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x800A57D8: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x800A57DC: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
L_800A57E0:
    // 0x800A57E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A57E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A57E8: nop

    // 0x800A57EC: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x800A57F0: swc1        $f0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f0.u32l;
    // 0x800A57F4: jr          $ra
    // 0x800A57F8: swc1        $f0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f0.u32l;
    return;
    // 0x800A57F8: swc1        $f0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f0.u32l;
;}

RECOMP_FUNC void func_800A57FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A57FC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800A5800: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A5804: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800A5808: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A580C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800A5810: addiu       $s1, $s1, -0x6B80
    ctx->r17 = ADD32(ctx->r17, -0X6B80);
    // 0x800A5814: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A5818: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800A581C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800A5820: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A5824: jal         0x800A5660
    // 0x800A5828: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A5660(rdram, ctx);
        goto after_0;
    // 0x800A5828: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800A582C: addiu       $s3, $sp, 0x28
    ctx->r19 = ADD32(ctx->r29, 0X28);
    // 0x800A5830: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800A5834: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800A5838: jal         0x800AF0C4
    // 0x800A583C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800AF0C4(rdram, ctx);
        goto after_1;
    // 0x800A583C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x800A5840: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
    // 0x800A5844: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800A5848: jal         0x800A56E4
    // 0x800A584C: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    func_800A56E4(rdram, ctx);
        goto after_2;
    // 0x800A584C: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    after_2:
    // 0x800A5850: lhu         $t6, 0x0($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X0);
    // 0x800A5854: lbu         $s0, 0x3($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X3);
    // 0x800A5858: lw          $s1, 0x4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X4);
    // 0x800A585C: andi        $t8, $t6, 0xFFFD
    ctx->r24 = ctx->r14 & 0XFFFD;
    // 0x800A5860: sh          $t8, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r24;
    // 0x800A5864: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x800A5868: beq         $s0, $zero, L_800A5888
    if (ctx->r16 == 0) {
        // 0x800A586C: sh          $t9, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r25;
            goto L_800A5888;
    }
    // 0x800A586C: sh          $t9, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r25;
L_800A5870:
    // 0x800A5870: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A5874: jal         0x800A57FC
    // 0x800A5878: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800A57FC(rdram, ctx);
        goto after_3;
    // 0x800A5878: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x800A587C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800A5880: bne         $s0, $zero, L_800A5870
    if (ctx->r16 != 0) {
        // 0x800A5884: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800A5870;
    }
    // 0x800A5884: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800A5888:
    // 0x800A5888: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A588C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A5890: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A5894: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5898: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800A589C: jr          $ra
    // 0x800A58A0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800A58A0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}

RECOMP_FUNC void func_800A58A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A58A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A58A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A58AC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A58B0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800A58B4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A58B8: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800A58BC: beq         $t7, $zero, L_800A58FC
    if (ctx->r15 == 0) {
        // 0x800A58C0: addiu       $t8, $t8, -0x6B00
        ctx->r24 = ADD32(ctx->r24, -0X6B00);
            goto L_800A58FC;
    }
    // 0x800A58C0: addiu       $t8, $t8, -0x6B00
    ctx->r24 = ADD32(ctx->r24, -0X6B00);
    // 0x800A58C4: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800A58C8: addiu       $t1, $a0, 0x3C
    ctx->r9 = ADD32(ctx->r4, 0X3C);
L_800A58CC:
    // 0x800A58CC: lw          $at, 0xC($t2)
    ctx->r1 = MEM_W(ctx->r10, 0XC);
    // 0x800A58D0: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x800A58D4: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800A58D8: sw          $at, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r1;
    // 0x800A58DC: lw          $at, 0x4($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X4);
    // 0x800A58E0: sw          $at, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r1;
    // 0x800A58E4: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800A58E8: bne         $t2, $t1, L_800A58CC
    if (ctx->r10 != ctx->r9) {
        // 0x800A58EC: sw          $at, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r1;
            goto L_800A58CC;
    }
    // 0x800A58EC: sw          $at, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r1;
    // 0x800A58F0: lw          $at, 0xC($t2)
    ctx->r1 = MEM_W(ctx->r10, 0XC);
    // 0x800A58F4: b           L_800A5910
    // 0x800A58F8: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
        goto L_800A5910;
    // 0x800A58F8: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
L_800A58FC:
    // 0x800A58FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A5900: addiu       $a0, $a0, -0x6B00
    ctx->r4 = ADD32(ctx->r4, -0X6B00);
    // 0x800A5904: jal         0x800B79D0
    // 0x800A5908: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800A5908: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A590C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_800A5910:
    // 0x800A5910: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A5914: addiu       $a1, $a1, -0x6B00
    ctx->r5 = ADD32(ctx->r5, -0X6B00);
    // 0x800A5918: jal         0x800A59C0
    // 0x800A591C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800A59C0(rdram, ctx);
        goto after_1;
    // 0x800A591C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x800A5920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5928: jr          $ra
    // 0x800A592C: nop

    return;
    // 0x800A592C: nop

;}

RECOMP_FUNC void func_800A5930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5938: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A593C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800A5940: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A5944: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800A5948: beq         $t7, $zero, L_800A596C
    if (ctx->r15 == 0) {
        // 0x800A594C: addiu       $t8, $t8, -0x6AC0
        ctx->r24 = ADD32(ctx->r24, -0X6AC0);
            goto L_800A596C;
    }
    // 0x800A594C: addiu       $t8, $t8, -0x6AC0
    ctx->r24 = ADD32(ctx->r24, -0X6AC0);
    // 0x800A5950: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A5954: addiu       $a0, $a0, -0x6AC0
    ctx->r4 = ADD32(ctx->r4, -0X6AC0);
    // 0x800A5958: addiu       $a2, $a3, 0xC
    ctx->r6 = ADD32(ctx->r7, 0XC);
    // 0x800A595C: jal         0x800AEE4C
    // 0x800A5960: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800AEE4C(rdram, ctx);
        goto after_0;
    // 0x800A5960: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A5964: b           L_800A59A0
    // 0x800A5968: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_800A59A0;
    // 0x800A5968: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_800A596C:
    // 0x800A596C: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x800A5970: addiu       $t1, $a1, 0x3C
    ctx->r9 = ADD32(ctx->r5, 0X3C);
L_800A5974:
    // 0x800A5974: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800A5978: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x800A597C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800A5980: sw          $at, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r1;
    // 0x800A5984: lw          $at, -0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X8);
    // 0x800A5988: sw          $at, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r1;
    // 0x800A598C: lw          $at, -0x4($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X4);
    // 0x800A5990: bne         $t2, $t1, L_800A5974
    if (ctx->r10 != ctx->r9) {
        // 0x800A5994: sw          $at, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r1;
            goto L_800A5974;
    }
    // 0x800A5994: sw          $at, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r1;
    // 0x800A5998: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800A599C: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
L_800A59A0:
    // 0x800A59A0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A59A4: addiu       $a1, $a1, -0x6AC0
    ctx->r5 = ADD32(ctx->r5, -0X6AC0);
    // 0x800A59A8: jal         0x800A59C0
    // 0x800A59AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800A59C0(rdram, ctx);
        goto after_1;
    // 0x800A59AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x800A59B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A59B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A59B8: jr          $ra
    // 0x800A59BC: nop

    return;
    // 0x800A59BC: nop

;}

RECOMP_FUNC void func_800A59C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A59C0: addiu       $sp, $sp, -0x238
    ctx->r29 = ADD32(ctx->r29, -0X238);
    // 0x800A59C4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800A59C8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800A59CC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800A59D0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800A59D4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800A59D8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800A59DC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800A59E0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800A59E4: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A59E8: addiu       $s6, $sp, 0x1E0
    ctx->r22 = ADD32(ctx->r29, 0X1E0);
    // 0x800A59EC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800A59F0: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800A59F4: sw          $t7, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r15;
    // 0x800A59F8: or          $t2, $s6, $zero
    ctx->r10 = ctx->r22 | 0;
    // 0x800A59FC: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x800A5A00: addiu       $t0, $a1, 0x3C
    ctx->r8 = ADD32(ctx->r5, 0X3C);
L_800A5A04:
    // 0x800A5A04: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x800A5A08: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x800A5A0C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x800A5A10: sw          $at, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r1;
    // 0x800A5A14: lw          $at, -0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X8);
    // 0x800A5A18: sw          $at, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r1;
    // 0x800A5A1C: lw          $at, -0x4($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X4);
    // 0x800A5A20: bne         $t1, $t0, L_800A5A04
    if (ctx->r9 != ctx->r8) {
        // 0x800A5A24: sw          $at, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r1;
            goto L_800A5A04;
    }
    // 0x800A5A24: sw          $at, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r1;
    // 0x800A5A28: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x800A5A2C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800A5A30: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800A5A34: jal         0x800A57A4
    // 0x800A5A38: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    func_800A57A4(rdram, ctx);
        goto after_0;
    // 0x800A5A38: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    after_0:
    // 0x800A5A3C: lw          $v1, 0x220($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X220);
    // 0x800A5A40: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x800A5A44: lw          $s1, 0x18($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X18);
    // 0x800A5A48: lw          $s3, 0x0($v1)
    ctx->r19 = MEM_W(ctx->r3, 0X0);
    // 0x800A5A4C: beql        $t3, $zero, L_800A5D6C
    if (ctx->r11 == 0) {
        // 0x800A5A50: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_800A5D6C;
    }
    goto skip_0;
    // 0x800A5A50: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x800A5A54: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x800A5A58: andi        $t4, $v0, 0x40
    ctx->r12 = ctx->r2 & 0X40;
    // 0x800A5A5C: bne         $t4, $zero, L_800A5D60
    if (ctx->r12 != 0) {
        // 0x800A5A60: andi        $t5, $v0, 0x8
        ctx->r13 = ctx->r2 & 0X8;
            goto L_800A5D60;
    }
    // 0x800A5A60: andi        $t5, $v0, 0x8
    ctx->r13 = ctx->r2 & 0X8;
    // 0x800A5A64: beq         $t5, $zero, L_800A5AC4
    if (ctx->r13 == 0) {
        // 0x800A5A68: andi        $t6, $v0, 0x10
        ctx->r14 = ctx->r2 & 0X10;
            goto L_800A5AC4;
    }
    // 0x800A5A68: andi        $t6, $v0, 0x10
    ctx->r14 = ctx->r2 & 0X10;
    // 0x800A5A6C: beq         $t6, $zero, L_800A5A8C
    if (ctx->r14 == 0) {
        // 0x800A5A70: addiu       $s4, $sp, 0x160
        ctx->r20 = ADD32(ctx->r29, 0X160);
            goto L_800A5A8C;
    }
    // 0x800A5A70: addiu       $s4, $sp, 0x160
    ctx->r20 = ADD32(ctx->r29, 0X160);
    // 0x800A5A74: addiu       $s0, $s5, 0x4C
    ctx->r16 = ADD32(ctx->r21, 0X4C);
    // 0x800A5A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A5A7C: jal         0x800A57A4
    // 0x800A5A80: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    func_800A57A4(rdram, ctx);
        goto after_1;
    // 0x800A5A80: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    after_1:
    // 0x800A5A84: b           L_800A5B08
    // 0x800A5A88: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
        goto L_800A5B08;
    // 0x800A5A88: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
L_800A5A8C:
    // 0x800A5A8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A5A90: jal         0x800A5660
    // 0x800A5A94: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800A5660(rdram, ctx);
        goto after_2;
    // 0x800A5A94: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x800A5A98: addiu       $s2, $sp, 0x1A0
    ctx->r18 = ADD32(ctx->r29, 0X1A0);
    // 0x800A5A9C: addiu       $s0, $s5, 0x4C
    ctx->r16 = ADD32(ctx->r21, 0X4C);
    // 0x800A5AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A5AA4: jal         0x800A57A4
    // 0x800A5AA8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800A57A4(rdram, ctx);
        goto after_3;
    // 0x800A5AA8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x800A5AAC: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x800A5AB0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800A5AB4: jal         0x800AF0C4
    // 0x800A5AB8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800AF0C4(rdram, ctx);
        goto after_4;
    // 0x800A5AB8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_4:
    // 0x800A5ABC: b           L_800A5B08
    // 0x800A5AC0: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
        goto L_800A5B08;
    // 0x800A5AC0: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
L_800A5AC4:
    // 0x800A5AC4: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
    // 0x800A5AC8: beq         $t7, $zero, L_800A5AE4
    if (ctx->r15 == 0) {
        // 0x800A5ACC: addiu       $s4, $sp, 0x160
        ctx->r20 = ADD32(ctx->r29, 0X160);
            goto L_800A5AE4;
    }
    // 0x800A5ACC: addiu       $s4, $sp, 0x160
    ctx->r20 = ADD32(ctx->r29, 0X160);
    // 0x800A5AD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A5AD4: jal         0x800A5660
    // 0x800A5AD8: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    func_800A5660(rdram, ctx);
        goto after_5;
    // 0x800A5AD8: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    after_5:
    // 0x800A5ADC: b           L_800A5B04
    // 0x800A5AE0: addiu       $s0, $s5, 0x4C
    ctx->r16 = ADD32(ctx->r21, 0X4C);
        goto L_800A5B04;
    // 0x800A5AE0: addiu       $s0, $s5, 0x4C
    ctx->r16 = ADD32(ctx->r21, 0X4C);
L_800A5AE4:
    // 0x800A5AE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A5AE8: jal         0x800A5660
    // 0x800A5AEC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800A5660(rdram, ctx);
        goto after_6;
    // 0x800A5AEC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x800A5AF0: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x800A5AF4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800A5AF8: jal         0x800AF0C4
    // 0x800A5AFC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800AF0C4(rdram, ctx);
        goto after_7;
    // 0x800A5AFC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_7:
    // 0x800A5B00: addiu       $s0, $s5, 0x4C
    ctx->r16 = ADD32(ctx->r21, 0X4C);
L_800A5B04:
    // 0x800A5B04: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
L_800A5B08:
    // 0x800A5B08: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x800A5B0C: jal         0x800A56E4
    // 0x800A5B10: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    func_800A56E4(rdram, ctx);
        goto after_8;
    // 0x800A5B10: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    after_8:
    // 0x800A5B14: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x800A5B18: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // 0x800A5B1C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800A5B20: addiu       $t0, $t9, 0x3C
    ctx->r8 = ADD32(ctx->r25, 0X3C);
L_800A5B24:
    // 0x800A5B24: lw          $at, 0xC0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0XC0);
    // 0x800A5B28: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800A5B2C: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x800A5B30: sw          $at, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r1;
    // 0x800A5B34: lw          $at, 0xB8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0XB8);
    // 0x800A5B38: sw          $at, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r1;
    // 0x800A5B3C: lw          $at, 0xBC($t9)
    ctx->r1 = MEM_W(ctx->r25, 0XBC);
    // 0x800A5B40: bne         $t9, $t0, L_800A5B24
    if (ctx->r25 != ctx->r8) {
        // 0x800A5B44: sw          $at, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r1;
            goto L_800A5B24;
    }
    // 0x800A5B44: sw          $at, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r1;
    // 0x800A5B48: lw          $at, 0xC0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0XC0);
    // 0x800A5B4C: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x800A5B50: addiu       $t4, $v0, 0x3C
    ctx->r12 = ADD32(ctx->r2, 0X3C);
    // 0x800A5B54: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800A5B58: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
L_800A5B5C:
    // 0x800A5B5C: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x800A5B60: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x800A5B64: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x800A5B68: sw          $at, 0x74($t2)
    MEM_W(0X74, ctx->r10) = ctx->r1;
    // 0x800A5B6C: lw          $at, -0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, -0X8);
    // 0x800A5B70: sw          $at, 0x78($t2)
    MEM_W(0X78, ctx->r10) = ctx->r1;
    // 0x800A5B74: lw          $at, -0x4($t5)
    ctx->r1 = MEM_W(ctx->r13, -0X4);
    // 0x800A5B78: bne         $t5, $t4, L_800A5B5C
    if (ctx->r13 != ctx->r12) {
        // 0x800A5B7C: sw          $at, 0x7C($t2)
        MEM_W(0X7C, ctx->r10) = ctx->r1;
            goto L_800A5B5C;
    }
    // 0x800A5B7C: sw          $at, 0x7C($t2)
    MEM_W(0X7C, ctx->r10) = ctx->r1;
    // 0x800A5B80: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x800A5B84: or          $t8, $v0, $zero
    ctx->r24 = ctx->r2 | 0;
    // 0x800A5B88: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x800A5B8C: addiu       $t7, $v0, 0x3C
    ctx->r15 = ADD32(ctx->r2, 0X3C);
    // 0x800A5B90: sw          $at, 0x80($t2)
    MEM_W(0X80, ctx->r10) = ctx->r1;
L_800A5B94:
    // 0x800A5B94: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x800A5B98: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800A5B9C: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800A5BA0: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x800A5BA4: lw          $at, -0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X8);
    // 0x800A5BA8: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x800A5BAC: lw          $at, -0x4($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X4);
    // 0x800A5BB0: bne         $t8, $t7, L_800A5B94
    if (ctx->r24 != ctx->r15) {
        // 0x800A5BB4: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_800A5B94;
    }
    // 0x800A5BB4: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x800A5BB8: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x800A5BBC: addiu       $a1, $s5, 0x8C
    ctx->r5 = ADD32(ctx->r21, 0X8C);
    // 0x800A5BC0: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x800A5BC4: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x800A5BC8: jal         0x800AE880
    // 0x800A5BCC: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    func_800AE880(rdram, ctx);
        goto after_9;
    // 0x800A5BCC: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    after_9:
    // 0x800A5BD0: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800A5BD4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800A5BD8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A5BDC: lwc1        $f4, 0xB0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x800A5BE0: addiu       $a1, $s5, 0xCC
    ctx->r5 = ADD32(ctx->r21, 0XCC);
    // 0x800A5BE4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800A5BE8: swc1        $f6, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->f6.u32l;
    // 0x800A5BEC: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800A5BF0: lwc1        $f8, 0xB4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XB4);
    // 0x800A5BF4: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800A5BF8: swc1        $f10, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->f10.u32l;
    // 0x800A5BFC: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800A5C00: lwc1        $f18, 0xB8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB8);
    // 0x800A5C04: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800A5C08: swc1        $f4, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f4.u32l;
    // 0x800A5C0C: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x800A5C10: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x800A5C14: jal         0x800AE880
    // 0x800A5C18: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800AE880(rdram, ctx);
        goto after_10;
    // 0x800A5C18: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_10:
    // 0x800A5C1C: lhu         $t9, 0x0($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X0);
    // 0x800A5C20: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800A5C24: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A5C28: ori         $t1, $t9, 0x2
    ctx->r9 = ctx->r25 | 0X2;
    // 0x800A5C2C: sh          $t1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r9;
    // 0x800A5C30: lw          $t3, 0x220($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X220);
    // 0x800A5C34: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A5C38: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A5C3C: lw          $s0, 0x24($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X24);
    // 0x800A5C40: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A5C44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A5C48: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800A5C4C: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x800A5C50: mul.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800A5C54: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800A5C58: nop

    // 0x800A5C5C: bc1fl       L_800A5C6C
    if (!c1cs) {
        // 0x800A5C60: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_800A5C6C;
    }
    goto skip_1;
    // 0x800A5C60: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_1:
    // 0x800A5C64: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x800A5C68: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_800A5C6C:
    // 0x800A5C6C: nop

    // 0x800A5C70: bc1fl       L_800A5C80
    if (!c1cs) {
        // 0x800A5C74: lwc1        $f8, 0x1C($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_800A5C80;
    }
    goto skip_2;
    // 0x800A5C74: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    skip_2:
    // 0x800A5C78: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800A5C7C: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
L_800A5C80:
    // 0x800A5C80: lui         $at, 0x46FA
    ctx->r1 = S32(0X46FA << 16);
    // 0x800A5C84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A5C88: mul.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800A5C8C: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x800A5C90: nop

    // 0x800A5C94: bc1fl       L_800A5CA4
    if (!c1cs) {
        // 0x800A5C98: lbu         $t4, 0x4($s5)
        ctx->r12 = MEM_BU(ctx->r21, 0X4);
            goto L_800A5CA4;
    }
    goto skip_3;
    // 0x800A5C98: lbu         $t4, 0x4($s5)
    ctx->r12 = MEM_BU(ctx->r21, 0X4);
    skip_3:
    // 0x800A5C9C: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x800A5CA0: lbu         $t4, 0x4($s5)
    ctx->r12 = MEM_BU(ctx->r21, 0X4);
L_800A5CA4:
    // 0x800A5CA4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800A5CA8: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800A5CAC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800A5CB0: addu        $a1, $s0, $t5
    ctx->r5 = ADD32(ctx->r16, ctx->r13);
    // 0x800A5CB4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800A5CB8: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800A5CBC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800A5CC0: jal         0x800BA310
    // 0x800A5CC4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_11;
    // 0x800A5CC4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x800A5CC8: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x800A5CCC: addiu       $s2, $sp, 0x120
    ctx->r18 = ADD32(ctx->r29, 0X120);
    // 0x800A5CD0: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x800A5CD4: addiu       $t6, $a1, 0x3C
    ctx->r14 = ADD32(ctx->r5, 0X3C);
    // 0x800A5CD8: or          $t8, $s5, $zero
    ctx->r24 = ctx->r21 | 0;
L_800A5CDC:
    // 0x800A5CDC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800A5CE0: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800A5CE4: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800A5CE8: sw          $at, 0x100($t8)
    MEM_W(0X100, ctx->r24) = ctx->r1;
    // 0x800A5CEC: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x800A5CF0: sw          $at, 0x104($t8)
    MEM_W(0X104, ctx->r24) = ctx->r1;
    // 0x800A5CF4: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x800A5CF8: bne         $t7, $t6, L_800A5CDC
    if (ctx->r15 != ctx->r14) {
        // 0x800A5CFC: sw          $at, 0x108($t8)
        MEM_W(0X108, ctx->r24) = ctx->r1;
            goto L_800A5CDC;
    }
    // 0x800A5CFC: sw          $at, 0x108($t8)
    MEM_W(0X108, ctx->r24) = ctx->r1;
    // 0x800A5D00: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800A5D04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A5D08: sw          $at, 0x10C($t8)
    MEM_W(0X10C, ctx->r24) = ctx->r1;
    // 0x800A5D0C: jal         0x800AF558
    // 0x800A5D10: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    mtx4_mult(rdram, ctx);
        goto after_12;
    // 0x800A5D10: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_12:
    // 0x800A5D14: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x800A5D18: andi        $t9, $t0, 0x4000
    ctx->r25 = ctx->r8 & 0X4000;
    // 0x800A5D1C: beql        $t9, $zero, L_800A5D48
    if (ctx->r25 == 0) {
        // 0x800A5D20: lbu         $t2, 0x4($s5)
        ctx->r10 = MEM_BU(ctx->r21, 0X4);
            goto L_800A5D48;
    }
    goto skip_4;
    // 0x800A5D20: lbu         $t2, 0x4($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X4);
    skip_4:
    // 0x800A5D24: lbu         $t3, 0x4($s5)
    ctx->r11 = MEM_BU(ctx->r21, 0X4);
    // 0x800A5D28: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x800A5D2C: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x800A5D30: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x800A5D34: jal         0x800B78D0
    // 0x800A5D38: addu        $a1, $t1, $t4
    ctx->r5 = ADD32(ctx->r9, ctx->r12);
    guMtxF2L(rdram, ctx);
        goto after_13;
    // 0x800A5D38: addu        $a1, $t1, $t4
    ctx->r5 = ADD32(ctx->r9, ctx->r12);
    after_13:
    // 0x800A5D3C: b           L_800A5D60
    // 0x800A5D40: lw          $v1, 0x220($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X220);
        goto L_800A5D60;
    // 0x800A5D40: lw          $v1, 0x220($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X220);
    // 0x800A5D44: lbu         $t2, 0x4($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X4);
L_800A5D48:
    // 0x800A5D48: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x800A5D4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A5D50: sll         $t6, $t2, 6
    ctx->r14 = S32(ctx->r10 << 6);
    // 0x800A5D54: jal         0x800B78D0
    // 0x800A5D58: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    guMtxF2L(rdram, ctx);
        goto after_14;
    // 0x800A5D58: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_14:
    // 0x800A5D5C: lw          $v1, 0x220($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X220);
L_800A5D60:
    // 0x800A5D60: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x800A5D64: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800A5D68: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_800A5D6C:
    // 0x800A5D6C: addiu       $s2, $sp, 0x120
    ctx->r18 = ADD32(ctx->r29, 0X120);
    // 0x800A5D70: addiu       $s4, $sp, 0x160
    ctx->r20 = ADD32(ctx->r29, 0X160);
    // 0x800A5D74: beq         $v0, $zero, L_800A5E28
    if (ctx->r2 == 0) {
        // 0x800A5D78: addiu       $s0, $v0, -0x1
        ctx->r16 = ADD32(ctx->r2, -0X1);
            goto L_800A5E28;
    }
    // 0x800A5D78: addiu       $s0, $v0, -0x1
    ctx->r16 = ADD32(ctx->r2, -0X1);
    // 0x800A5D7C: beq         $s0, $zero, L_800A5E28
    if (ctx->r16 == 0) {
        // 0x800A5D80: nop
    
            goto L_800A5E28;
    }
    // 0x800A5D80: nop

L_800A5D84:
    // 0x800A5D84: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800A5D88: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800A5D8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A5D90: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x800A5D94: beq         $t8, $zero, L_800A5DAC
    if (ctx->r24 == 0) {
        // 0x800A5D98: nop
    
            goto L_800A5DAC;
    }
    // 0x800A5D98: nop

    // 0x800A5D9C: jal         0x800A5660
    // 0x800A5DA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A5660(rdram, ctx);
        goto after_15;
    // 0x800A5DA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x800A5DA4: b           L_800A5DC8
    // 0x800A5DA8: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
        goto L_800A5DC8;
    // 0x800A5DA8: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
L_800A5DAC:
    // 0x800A5DAC: jal         0x800A5660
    // 0x800A5DB0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800A5660(rdram, ctx);
        goto after_16;
    // 0x800A5DB0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_16:
    // 0x800A5DB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A5DB8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800A5DBC: jal         0x800AF0C4
    // 0x800A5DC0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800AF0C4(rdram, ctx);
        goto after_17;
    // 0x800A5DC0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_17:
    // 0x800A5DC4: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
L_800A5DC8:
    // 0x800A5DC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A5DCC: jal         0x800A56E4
    // 0x800A5DD0: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    func_800A56E4(rdram, ctx);
        goto after_18;
    // 0x800A5DD0: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    after_18:
    // 0x800A5DD4: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    // 0x800A5DD8: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
    // 0x800A5DDC: addiu       $t9, $t1, 0x3C
    ctx->r25 = ADD32(ctx->r9, 0X3C);
L_800A5DE0:
    // 0x800A5DE0: lw          $at, 0x80($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X80);
    // 0x800A5DE4: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800A5DE8: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x800A5DEC: sw          $at, 0xB4($t1)
    MEM_W(0XB4, ctx->r9) = ctx->r1;
    // 0x800A5DF0: lw          $at, 0x78($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X78);
    // 0x800A5DF4: sw          $at, 0xB8($t1)
    MEM_W(0XB8, ctx->r9) = ctx->r1;
    // 0x800A5DF8: lw          $at, 0x7C($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X7C);
    // 0x800A5DFC: bne         $t3, $t9, L_800A5DE0
    if (ctx->r11 != ctx->r25) {
        // 0x800A5E00: sw          $at, 0xBC($t1)
        MEM_W(0XBC, ctx->r9) = ctx->r1;
            goto L_800A5DE0;
    }
    // 0x800A5E00: sw          $at, 0xBC($t1)
    MEM_W(0XBC, ctx->r9) = ctx->r1;
    // 0x800A5E04: lw          $at, 0x80($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X80);
    // 0x800A5E08: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800A5E0C: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x800A5E10: sw          $at, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r1;
    // 0x800A5E14: lhu         $t4, -0x40($s1)
    ctx->r12 = MEM_HU(ctx->r17, -0X40);
    // 0x800A5E18: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800A5E1C: ori         $t2, $t4, 0x2
    ctx->r10 = ctx->r12 | 0X2;
    // 0x800A5E20: bne         $s0, $zero, L_800A5D84
    if (ctx->r16 != 0) {
        // 0x800A5E24: sh          $t2, -0x40($s1)
        MEM_H(-0X40, ctx->r17) = ctx->r10;
            goto L_800A5D84;
    }
    // 0x800A5E24: sh          $t2, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r10;
L_800A5E28:
    // 0x800A5E28: beq         $s3, $zero, L_800A5E58
    if (ctx->r19 == 0) {
        // 0x800A5E2C: or          $s0, $s3, $zero
        ctx->r16 = ctx->r19 | 0;
            goto L_800A5E58;
    }
    // 0x800A5E2C: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
L_800A5E30:
    // 0x800A5E30: lhu         $t5, 0x0($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X0);
    // 0x800A5E34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A5E38: andi        $t6, $t5, 0x100
    ctx->r14 = ctx->r13 & 0X100;
    // 0x800A5E3C: beql        $t6, $zero, L_800A5E50
    if (ctx->r14 == 0) {
        // 0x800A5E40: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800A5E50;
    }
    goto skip_5;
    // 0x800A5E40: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_5:
    // 0x800A5E44: jal         0x800A57FC
    // 0x800A5E48: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800A57FC(rdram, ctx);
        goto after_19;
    // 0x800A5E48: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_19:
    // 0x800A5E4C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_800A5E50:
    // 0x800A5E50: bne         $s0, $zero, L_800A5E30
    if (ctx->r16 != 0) {
        // 0x800A5E54: addiu       $s1, $s1, 0x40
        ctx->r17 = ADD32(ctx->r17, 0X40);
            goto L_800A5E30;
    }
    // 0x800A5E54: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
L_800A5E58:
    // 0x800A5E58: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800A5E5C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800A5E60: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800A5E64: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800A5E68: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800A5E6C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800A5E70: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800A5E74: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800A5E78: jr          $ra
    // 0x800A5E7C: addiu       $sp, $sp, 0x238
    ctx->r29 = ADD32(ctx->r29, 0X238);
    return;
    // 0x800A5E7C: addiu       $sp, $sp, 0x238
    ctx->r29 = ADD32(ctx->r29, 0X238);
;}

RECOMP_FUNC void func_800A5E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5E80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A5E84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A5E88: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A5E8C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800A5E90: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A5E94: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A5E98: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800A5E9C: lbu         $s3, 0x4($a0)
    ctx->r19 = MEM_BU(ctx->r4, 0X4);
    // 0x800A5EA0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A5EA4: lw          $s2, 0x10($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X10);
    // 0x800A5EA8: lw          $s0, 0x28($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X28);
    // 0x800A5EAC: blezl       $s2, L_800A5EE8
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800A5EB0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A5EE8;
    }
    goto skip_0;
    // 0x800A5EB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_800A5EB4:
    // 0x800A5EB4: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
    // 0x800A5EB8: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x800A5EBC: beql        $t7, $zero, L_800A5EDC
    if (ctx->r15 == 0) {
        // 0x800A5EC0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800A5EDC;
    }
    goto skip_1;
    // 0x800A5EC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x800A5EC4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800A5EC8: sll         $t8, $s3, 6
    ctx->r24 = S32(ctx->r19 << 6);
    // 0x800A5ECC: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    // 0x800A5ED0: jal         0x800B78D0
    // 0x800A5ED4: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    guMtxF2L(rdram, ctx);
        goto after_0;
    // 0x800A5ED4: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    after_0:
    // 0x800A5ED8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800A5EDC:
    // 0x800A5EDC: bne         $s1, $s2, L_800A5EB4
    if (ctx->r17 != ctx->r18) {
        // 0x800A5EE0: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_800A5EB4;
    }
    // 0x800A5EE0: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x800A5EE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A5EE8:
    // 0x800A5EE8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A5EEC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A5EF0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5EF4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800A5EF8: jr          $ra
    // 0x800A5EFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A5EFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800A5F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5F00: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800A5F04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A5F08: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x800A5F0C: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x800A5F10: blez        $a2, L_800A60F4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800A5F14: andi        $v1, $a2, 0x1
        ctx->r3 = ctx->r6 & 0X1;
            goto L_800A60F4;
    }
    // 0x800A5F14: andi        $v1, $a2, 0x1
    ctx->r3 = ctx->r6 & 0X1;
    // 0x800A5F18: beql        $v1, $zero, L_800A5FC4
    if (ctx->r3 == 0) {
        // 0x800A5F1C: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_800A5FC4;
    }
    goto skip_0;
    // 0x800A5F1C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    skip_0:
    // 0x800A5F20: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800A5F24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800A5F28: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x800A5F2C: beq         $t7, $zero, L_800A5FB8
    if (ctx->r15 == 0) {
        // 0x800A5F30: nop
    
            goto L_800A5FB8;
    }
    // 0x800A5F30: nop

    // 0x800A5F34: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800A5F38: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A5F3C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800A5F40: lwc1        $f4, 0xF0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A5F44: lwc1        $f10, 0xF4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A5F48: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A5F4C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A5F50: lwc1        $f4, 0xF8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A5F54: addiu       $v1, $v1, 0xC0
    ctx->r3 = ADD32(ctx->r3, 0XC0);
    // 0x800A5F58: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x800A5F5C: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800A5F60: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800A5F64: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x800A5F68: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800A5F6C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A5F70: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    // 0x800A5F74: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A5F78: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800A5F7C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800A5F80: lwc1        $f10, 0xB0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x800A5F84: lwc1        $f6, 0xB4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x800A5F88: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800A5F8C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800A5F90: lwc1        $f18, 0x38($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X38);
    // 0x800A5F94: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x800A5F98: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800A5F9C: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A5FA0: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800A5FA4: swc1        $f10, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f10.u32l;
    // 0x800A5FA8: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800A5FAC: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A5FB0: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800A5FB4: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
L_800A5FB8:
    // 0x800A5FB8: beq         $a3, $a2, L_800A60F4
    if (ctx->r7 == ctx->r6) {
        // 0x800A5FBC: addiu       $v0, $v0, 0x40
        ctx->r2 = ADD32(ctx->r2, 0X40);
            goto L_800A60F4;
    }
    // 0x800A5FBC: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800A5FC0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
L_800A5FC4:
    // 0x800A5FC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A5FC8: nop

L_800A5FCC:
    // 0x800A5FCC: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x800A5FD0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800A5FD4: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800A5FD8: beql        $t9, $zero, L_800A6060
    if (ctx->r25 == 0) {
        // 0x800A5FDC: lhu         $t0, 0x40($v0)
        ctx->r8 = MEM_HU(ctx->r2, 0X40);
            goto L_800A6060;
    }
    goto skip_1;
    // 0x800A5FDC: lhu         $t0, 0x40($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X40);
    skip_1:
    // 0x800A5FE0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800A5FE4: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A5FE8: lwc1        $f16, 0xF0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A5FEC: lwc1        $f18, 0xF4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A5FF0: addiu       $v1, $v1, 0xC0
    ctx->r3 = ADD32(ctx->r3, 0XC0);
    // 0x800A5FF4: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800A5FF8: lwc1        $f16, 0x38($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X38);
    // 0x800A5FFC: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x800A6000: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800A6004: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800A6008: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
    // 0x800A600C: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800A6010: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800A6014: swc1        $f4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f4.u32l;
    // 0x800A6018: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A601C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800A6020: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A6024: lwc1        $f18, 0xB0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x800A6028: lwc1        $f10, 0xB4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x800A602C: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800A6030: add.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800A6034: lwc1        $f6, 0x38($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X38);
    // 0x800A6038: swc1        $f16, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f16.u32l;
    // 0x800A603C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800A6040: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A6044: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800A6048: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x800A604C: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800A6050: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800A6054: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800A6058: swc1        $f10, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f10.u32l;
    // 0x800A605C: lhu         $t0, 0x40($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X40);
L_800A6060:
    // 0x800A6060: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800A6064: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800A6068: beq         $t1, $zero, L_800A60EC
    if (ctx->r9 == 0) {
        // 0x800A606C: nop
    
            goto L_800A60EC;
    }
    // 0x800A606C: nop

    // 0x800A6070: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800A6074: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A6078: lwc1        $f8, 0xF0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A607C: lwc1        $f6, 0xF4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A6080: addiu       $v1, $v1, 0xC0
    ctx->r3 = ADD32(ctx->r3, 0XC0);
    // 0x800A6084: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800A6088: lwc1        $f8, 0x38($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X38);
    // 0x800A608C: swc1        $f16, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f16.u32l;
    // 0x800A6090: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800A6094: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800A6098: swc1        $f10, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f10.u32l;
    // 0x800A609C: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800A60A0: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800A60A4: swc1        $f16, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f16.u32l;
    // 0x800A60A8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A60AC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800A60B0: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A60B4: lwc1        $f6, 0xB0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x800A60B8: lwc1        $f18, 0xB4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x800A60BC: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800A60C0: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A60C4: lwc1        $f10, 0x38($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X38);
    // 0x800A60C8: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x800A60CC: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800A60D0: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800A60D4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A60D8: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
    // 0x800A60DC: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800A60E0: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A60E4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800A60E8: swc1        $f18, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f18.u32l;
L_800A60EC:
    // 0x800A60EC: bne         $a3, $a2, L_800A5FCC
    if (ctx->r7 != ctx->r6) {
        // 0x800A60F0: addiu       $v0, $v0, 0x40
        ctx->r2 = ADD32(ctx->r2, 0X40);
            goto L_800A5FCC;
    }
    // 0x800A60F0: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
L_800A60F4:
    // 0x800A60F4: jr          $ra
    // 0x800A60F8: nop

    return;
    // 0x800A60F8: nop

;}

RECOMP_FUNC void func_800A60FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A60FC: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800A6100: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    // 0x800A6104: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x800A6108: beq         $a1, $zero, L_800A6358
    if (ctx->r5 == 0) {
        // 0x800A610C: andi        $v1, $a1, 0x3
        ctx->r3 = ctx->r5 & 0X3;
            goto L_800A6358;
    }
    // 0x800A610C: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800A6110: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x800A6114: beq         $v1, $zero, L_800A61A0
    if (ctx->r3 == 0) {
        // 0x800A6118: addu        $a0, $v1, $a1
        ctx->r4 = ADD32(ctx->r3, ctx->r5);
            goto L_800A61A0;
    }
    // 0x800A6118: addu        $a0, $v1, $a1
    ctx->r4 = ADD32(ctx->r3, ctx->r5);
    // 0x800A611C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800A6120: beq         $a0, $a1, L_800A6168
    if (ctx->r4 == ctx->r5) {
        // 0x800A6124: lw          $v1, 0xC($v0)
        ctx->r3 = MEM_W(ctx->r2, 0XC);
            goto L_800A6168;
    }
    // 0x800A6124: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
L_800A6128:
    // 0x800A6128: lwc1        $f18, 0xF0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A612C: lwc1        $f16, 0x170($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X170);
    // 0x800A6130: lwc1        $f14, 0xF4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A6134: lwc1        $f12, 0x174($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X174);
    // 0x800A6138: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800A613C: lwc1        $f18, 0xF8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A6140: lwc1        $f10, 0x178($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X178);
    // 0x800A6144: sub.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x800A6148: swc1        $f16, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f16.u32l;
    // 0x800A614C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800A6150: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800A6154: swc1        $f12, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f12.u32l;
    // 0x800A6158: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800A615C: swc1        $f10, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f10.u32l;
    // 0x800A6160: bne         $a0, $a1, L_800A6128
    if (ctx->r4 != ctx->r5) {
        // 0x800A6164: lw          $v1, 0xC($v0)
        ctx->r3 = MEM_W(ctx->r2, 0XC);
            goto L_800A6128;
    }
    // 0x800A6164: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
L_800A6168:
    // 0x800A6168: lwc1        $f18, 0xF0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A616C: lwc1        $f16, 0x170($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X170);
    // 0x800A6170: lwc1        $f14, 0xF4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A6174: lwc1        $f12, 0x174($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X174);
    // 0x800A6178: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800A617C: lwc1        $f18, 0xF8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A6180: lwc1        $f10, 0x178($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X178);
    // 0x800A6184: sub.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x800A6188: swc1        $f16, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f16.u32l;
    // 0x800A618C: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800A6190: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800A6194: swc1        $f12, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f12.u32l;
    // 0x800A6198: swc1        $f10, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f10.u32l;
    // 0x800A619C: beq         $a1, $zero, L_800A6358
    if (ctx->r5 == 0) {
        // 0x800A61A0: addiu       $a1, $a1, -0x4
        ctx->r5 = ADD32(ctx->r5, -0X4);
            goto L_800A6358;
    }
L_800A61A0:
    // 0x800A61A0: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800A61A4: beq         $a1, $zero, L_800A6288
    if (ctx->r5 == 0) {
        // 0x800A61A8: lw          $v1, 0xC($v0)
        ctx->r3 = MEM_W(ctx->r2, 0XC);
            goto L_800A6288;
    }
    // 0x800A61A8: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
L_800A61AC:
    // 0x800A61AC: lwc1        $f18, 0xF0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A61B0: lwc1        $f16, 0x170($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X170);
    // 0x800A61B4: lwc1        $f14, 0xF4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A61B8: lwc1        $f12, 0x174($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X174);
    // 0x800A61BC: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800A61C0: lwc1        $f18, 0xF8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A61C4: lwc1        $f10, 0x178($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X178);
    // 0x800A61C8: sub.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x800A61CC: swc1        $f16, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f16.u32l;
    // 0x800A61D0: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800A61D4: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800A61D8: swc1        $f12, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f12.u32l;
    // 0x800A61DC: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x800A61E0: swc1        $f10, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f10.u32l;
    // 0x800A61E4: lw          $v1, -0xB4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0XB4);
    // 0x800A61E8: lwc1        $f10, 0xF0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A61EC: lwc1        $f12, 0x170($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X170);
    // 0x800A61F0: lwc1        $f18, 0xF4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A61F4: lwc1        $f16, 0x174($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X174);
    // 0x800A61F8: sub.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A61FC: lwc1        $f10, 0xF8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A6200: lwc1        $f14, 0x178($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X178);
    // 0x800A6204: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800A6208: swc1        $f12, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f12.u32l;
    // 0x800A620C: sub.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x800A6210: swc1        $f16, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f16.u32l;
    // 0x800A6214: swc1        $f14, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f14.u32l;
    // 0x800A6218: lw          $v1, -0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X74);
    // 0x800A621C: lwc1        $f14, 0xF0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A6220: lwc1        $f16, 0x170($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X170);
    // 0x800A6224: lwc1        $f10, 0xF4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A6228: lwc1        $f12, 0x174($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X174);
    // 0x800A622C: sub.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800A6230: lwc1        $f14, 0xF8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A6234: lwc1        $f18, 0x178($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X178);
    // 0x800A6238: sub.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A623C: swc1        $f16, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f16.u32l;
    // 0x800A6240: sub.s       $f18, $f14, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x800A6244: swc1        $f12, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f12.u32l;
    // 0x800A6248: swc1        $f18, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f18.u32l;
    // 0x800A624C: lw          $v1, -0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X34);
    // 0x800A6250: lwc1        $f18, 0xF0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A6254: lwc1        $f12, 0x170($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X170);
    // 0x800A6258: lwc1        $f14, 0xF4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A625C: lwc1        $f16, 0x174($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X174);
    // 0x800A6260: sub.s       $f12, $f18, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x800A6264: lwc1        $f18, 0xF8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A6268: lwc1        $f10, 0x178($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X178);
    // 0x800A626C: sub.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800A6270: swc1        $f12, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f12.u32l;
    // 0x800A6274: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800A6278: swc1        $f16, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f16.u32l;
    // 0x800A627C: swc1        $f10, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f10.u32l;
    // 0x800A6280: bne         $a1, $zero, L_800A61AC
    if (ctx->r5 != 0) {
        // 0x800A6284: lw          $v1, 0xC($v0)
        ctx->r3 = MEM_W(ctx->r2, 0XC);
            goto L_800A61AC;
    }
    // 0x800A6284: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
L_800A6288:
    // 0x800A6288: lwc1        $f18, 0xF0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A628C: lwc1        $f16, 0x170($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X170);
    // 0x800A6290: lwc1        $f14, 0xF4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A6294: lwc1        $f12, 0x174($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X174);
    // 0x800A6298: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800A629C: lwc1        $f18, 0xF8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A62A0: lwc1        $f10, 0x178($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X178);
    // 0x800A62A4: sub.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x800A62A8: swc1        $f16, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f16.u32l;
    // 0x800A62AC: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x800A62B0: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800A62B4: swc1        $f12, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f12.u32l;
    // 0x800A62B8: swc1        $f10, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f10.u32l;
    // 0x800A62BC: lw          $v1, -0xB4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0XB4);
    // 0x800A62C0: lwc1        $f10, 0xF0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A62C4: lwc1        $f12, 0x170($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X170);
    // 0x800A62C8: lwc1        $f18, 0xF4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A62CC: lwc1        $f16, 0x174($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X174);
    // 0x800A62D0: sub.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A62D4: lwc1        $f10, 0xF8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A62D8: lwc1        $f14, 0x178($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X178);
    // 0x800A62DC: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800A62E0: swc1        $f12, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f12.u32l;
    // 0x800A62E4: sub.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x800A62E8: swc1        $f16, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f16.u32l;
    // 0x800A62EC: swc1        $f14, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f14.u32l;
    // 0x800A62F0: lw          $v1, -0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X74);
    // 0x800A62F4: lwc1        $f14, 0xF0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A62F8: lwc1        $f16, 0x170($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X170);
    // 0x800A62FC: lwc1        $f10, 0xF4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A6300: lwc1        $f12, 0x174($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X174);
    // 0x800A6304: sub.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800A6308: lwc1        $f14, 0xF8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A630C: lwc1        $f18, 0x178($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X178);
    // 0x800A6310: sub.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A6314: swc1        $f16, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f16.u32l;
    // 0x800A6318: sub.s       $f18, $f14, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x800A631C: swc1        $f12, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f12.u32l;
    // 0x800A6320: swc1        $f18, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f18.u32l;
    // 0x800A6324: lw          $v1, -0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X34);
    // 0x800A6328: lwc1        $f18, 0xF0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A632C: lwc1        $f12, 0x170($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X170);
    // 0x800A6330: lwc1        $f14, 0xF4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A6334: lwc1        $f16, 0x174($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X174);
    // 0x800A6338: sub.s       $f12, $f18, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x800A633C: lwc1        $f18, 0xF8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A6340: lwc1        $f10, 0x178($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X178);
    // 0x800A6344: sub.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800A6348: swc1        $f12, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f12.u32l;
    // 0x800A634C: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800A6350: swc1        $f16, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f16.u32l;
    // 0x800A6354: swc1        $f10, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f10.u32l;
L_800A6358:
    // 0x800A6358: jr          $ra
    // 0x800A635C: nop

    return;
    // 0x800A635C: nop

;}

RECOMP_FUNC void func_800A6360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6360: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800A6364: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    // 0x800A6368: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x800A636C: beq         $a1, $zero, L_800A6524
    if (ctx->r5 == 0) {
        // 0x800A6370: andi        $v1, $a1, 0x3
        ctx->r3 = ctx->r5 & 0X3;
            goto L_800A6524;
    }
    // 0x800A6370: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800A6374: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x800A6378: beql        $v1, $zero, L_800A63C8
    if (ctx->r3 == 0) {
        // 0x800A637C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800A63C8;
    }
    goto skip_0;
    // 0x800A637C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x800A6380: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A6384: addu        $a0, $v1, $a1
    ctx->r4 = ADD32(ctx->r3, ctx->r5);
L_800A6388:
    // 0x800A6388: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800A638C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800A6390: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800A6394: lwc1        $f4, 0xF0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A6398: lwc1        $f6, 0xF4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A639C: lwc1        $f8, 0xF8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A63A0: swc1        $f0, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f0.u32l;
    // 0x800A63A4: swc1        $f0, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f0.u32l;
    // 0x800A63A8: swc1        $f0, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f0.u32l;
    // 0x800A63AC: swc1        $f4, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->f4.u32l;
    // 0x800A63B0: swc1        $f6, 0x174($v1)
    MEM_W(0X174, ctx->r3) = ctx->f6.u32l;
    // 0x800A63B4: bne         $a0, $a1, L_800A6388
    if (ctx->r4 != ctx->r5) {
        // 0x800A63B8: swc1        $f8, 0x178($v1)
        MEM_W(0X178, ctx->r3) = ctx->f8.u32l;
            goto L_800A6388;
    }
    // 0x800A63B8: swc1        $f8, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->f8.u32l;
    // 0x800A63BC: beq         $a1, $zero, L_800A6524
    if (ctx->r5 == 0) {
        // 0x800A63C0: nop
    
            goto L_800A6524;
    }
    // 0x800A63C0: nop

    // 0x800A63C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800A63C8:
    // 0x800A63C8: nop

    // 0x800A63CC: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800A63D0: beq         $a1, $zero, L_800A6484
    if (ctx->r5 == 0) {
        // 0x800A63D4: lw          $v1, 0xC($v0)
        ctx->r3 = MEM_W(ctx->r2, 0XC);
            goto L_800A6484;
    }
    // 0x800A63D4: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
L_800A63D8:
    // 0x800A63D8: lwc1        $f18, 0xF0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A63DC: lwc1        $f16, 0xF4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A63E0: lwc1        $f14, 0xF8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A63E4: swc1        $f0, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f0.u32l;
    // 0x800A63E8: swc1        $f18, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->f18.u32l;
    // 0x800A63EC: swc1        $f0, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f0.u32l;
    // 0x800A63F0: swc1        $f0, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f0.u32l;
    // 0x800A63F4: swc1        $f16, 0x174($v1)
    MEM_W(0X174, ctx->r3) = ctx->f16.u32l;
    // 0x800A63F8: swc1        $f14, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->f14.u32l;
    // 0x800A63FC: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x800A6400: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800A6404: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x800A6408: lwc1        $f14, 0xF0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A640C: lwc1        $f16, 0xF4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A6410: lwc1        $f18, 0xF8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A6414: swc1        $f0, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f0.u32l;
    // 0x800A6418: swc1        $f14, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->f14.u32l;
    // 0x800A641C: swc1        $f0, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f0.u32l;
    // 0x800A6420: swc1        $f0, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f0.u32l;
    // 0x800A6424: swc1        $f16, 0x174($v1)
    MEM_W(0X174, ctx->r3) = ctx->f16.u32l;
    // 0x800A6428: swc1        $f18, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->f18.u32l;
    // 0x800A642C: lw          $v1, -0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X74);
    // 0x800A6430: lwc1        $f18, 0xF0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A6434: lwc1        $f16, 0xF4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A6438: lwc1        $f14, 0xF8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A643C: swc1        $f0, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f0.u32l;
    // 0x800A6440: swc1        $f18, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->f18.u32l;
    // 0x800A6444: swc1        $f0, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f0.u32l;
    // 0x800A6448: swc1        $f0, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f0.u32l;
    // 0x800A644C: swc1        $f16, 0x174($v1)
    MEM_W(0X174, ctx->r3) = ctx->f16.u32l;
    // 0x800A6450: swc1        $f14, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->f14.u32l;
    // 0x800A6454: lw          $v1, -0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X34);
    // 0x800A6458: lwc1        $f14, 0xF0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A645C: lwc1        $f16, 0xF4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A6460: lwc1        $f18, 0xF8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A6464: swc1        $f0, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f0.u32l;
    // 0x800A6468: swc1        $f14, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->f14.u32l;
    // 0x800A646C: swc1        $f0, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f0.u32l;
    // 0x800A6470: swc1        $f0, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f0.u32l;
    // 0x800A6474: swc1        $f16, 0x174($v1)
    MEM_W(0X174, ctx->r3) = ctx->f16.u32l;
    // 0x800A6478: swc1        $f18, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->f18.u32l;
    // 0x800A647C: bne         $a1, $zero, L_800A63D8
    if (ctx->r5 != 0) {
        // 0x800A6480: lw          $v1, 0xC($v0)
        ctx->r3 = MEM_W(ctx->r2, 0XC);
            goto L_800A63D8;
    }
    // 0x800A6480: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
L_800A6484:
    // 0x800A6484: lwc1        $f18, 0xF0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A6488: lwc1        $f16, 0xF4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A648C: lwc1        $f14, 0xF8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A6490: swc1        $f0, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f0.u32l;
    // 0x800A6494: swc1        $f0, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f0.u32l;
    // 0x800A6498: swc1        $f0, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f0.u32l;
    // 0x800A649C: swc1        $f18, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->f18.u32l;
    // 0x800A64A0: swc1        $f16, 0x174($v1)
    MEM_W(0X174, ctx->r3) = ctx->f16.u32l;
    // 0x800A64A4: swc1        $f14, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->f14.u32l;
    // 0x800A64A8: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x800A64AC: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x800A64B0: lwc1        $f14, 0xF0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A64B4: lwc1        $f16, 0xF4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A64B8: lwc1        $f18, 0xF8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A64BC: swc1        $f0, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f0.u32l;
    // 0x800A64C0: swc1        $f0, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f0.u32l;
    // 0x800A64C4: swc1        $f0, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f0.u32l;
    // 0x800A64C8: swc1        $f14, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->f14.u32l;
    // 0x800A64CC: swc1        $f16, 0x174($v1)
    MEM_W(0X174, ctx->r3) = ctx->f16.u32l;
    // 0x800A64D0: swc1        $f18, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->f18.u32l;
    // 0x800A64D4: lw          $v1, -0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X74);
    // 0x800A64D8: lwc1        $f18, 0xF0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A64DC: lwc1        $f16, 0xF4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A64E0: lwc1        $f14, 0xF8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A64E4: swc1        $f0, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f0.u32l;
    // 0x800A64E8: swc1        $f0, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f0.u32l;
    // 0x800A64EC: swc1        $f0, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f0.u32l;
    // 0x800A64F0: swc1        $f18, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->f18.u32l;
    // 0x800A64F4: swc1        $f16, 0x174($v1)
    MEM_W(0X174, ctx->r3) = ctx->f16.u32l;
    // 0x800A64F8: swc1        $f14, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->f14.u32l;
    // 0x800A64FC: lw          $v1, -0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X34);
    // 0x800A6500: lwc1        $f14, 0xF0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800A6504: lwc1        $f16, 0xF4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XF4);
    // 0x800A6508: lwc1        $f18, 0xF8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x800A650C: swc1        $f0, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f0.u32l;
    // 0x800A6510: swc1        $f0, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f0.u32l;
    // 0x800A6514: swc1        $f0, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f0.u32l;
    // 0x800A6518: swc1        $f14, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->f14.u32l;
    // 0x800A651C: swc1        $f16, 0x174($v1)
    MEM_W(0X174, ctx->r3) = ctx->f16.u32l;
    // 0x800A6520: swc1        $f18, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->f18.u32l;
L_800A6524:
    // 0x800A6524: jr          $ra
    // 0x800A6528: nop

    return;
    // 0x800A6528: nop

;}

RECOMP_FUNC void func_800A652C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A652C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A6530: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A6534: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800A6538: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A653C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800A6540: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800A6544: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800A6548: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800A654C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A6550: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A6554: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A6558: beq         $a1, $zero, L_800A6704
    if (ctx->r5 == 0) {
        // 0x800A655C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800A6704;
    }
    // 0x800A655C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A6560: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    // 0x800A6564: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800A6568: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800A656C: bnel        $t7, $zero, L_800A6708
    if (ctx->r15 != 0) {
        // 0x800A6570: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800A6708;
    }
    goto skip_0;
    // 0x800A6570: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x800A6574: lw          $s4, 0x24($a1)
    ctx->r20 = MEM_W(ctx->r5, 0X24);
    // 0x800A6578: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800A657C: sw          $a0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r4;
    // 0x800A6580: lw          $s0, 0x28($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X28);
    // 0x800A6584: blez        $s4, L_800A66F8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800A6588: sw          $t8, 0x20($a1)
        MEM_W(0X20, ctx->r5) = ctx->r24;
            goto L_800A66F8;
    }
    // 0x800A6588: sw          $t8, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r24;
    // 0x800A658C: addiu       $fp, $zero, 0x14
    ctx->r30 = ADD32(0, 0X14);
    // 0x800A6590: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x800A6594: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800A6598: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800A659C:
    // 0x800A659C: jal         0x800AA134
    // 0x800A65A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800AA134(rdram, ctx);
        goto after_0;
    // 0x800A65A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x800A65A4: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x800A65A8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800A65AC: beq         $v1, $zero, L_800A65D4
    if (ctx->r3 == 0) {
        // 0x800A65B0: nop
    
            goto L_800A65D4;
    }
    // 0x800A65B0: nop

    // 0x800A65B4: beql        $v1, $s5, L_800A6690
    if (ctx->r3 == ctx->r21) {
        // 0x800A65B8: lw          $t1, 0x20($s3)
        ctx->r9 = MEM_W(ctx->r19, 0X20);
            goto L_800A6690;
    }
    goto skip_1;
    // 0x800A65B8: lw          $t1, 0x20($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X20);
    skip_1:
    // 0x800A65BC: beql        $v1, $s6, L_800A66B0
    if (ctx->r3 == ctx->r22) {
        // 0x800A65C0: lw          $t6, 0x10($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X10);
            goto L_800A66B0;
    }
    goto skip_2;
    // 0x800A65C0: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    skip_2:
    // 0x800A65C4: beql        $v1, $s7, L_800A66D4
    if (ctx->r3 == ctx->r23) {
        // 0x800A65C8: lw          $t0, 0x20($s3)
        ctx->r8 = MEM_W(ctx->r19, 0X20);
            goto L_800A66D4;
    }
    goto skip_3;
    // 0x800A65C8: lw          $t0, 0x20($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X20);
    skip_3:
    // 0x800A65CC: b           L_800A66F0
    // 0x800A65D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_800A66F0;
    // 0x800A65D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800A65D4:
    // 0x800A65D4: jal         0x800AA038
    // 0x800A65D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800AA038(rdram, ctx);
        goto after_1;
    // 0x800A65D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x800A65DC: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x800A65E0: beq         $at, $zero, L_800A6684
    if (ctx->r1 == 0) {
        // 0x800A65E4: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_800A6684;
    }
    // 0x800A65E4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800A65E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A65EC: addu        $at, $at, $t9
    gpr jr_addend_800A65F4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800A65F0: lw          $t9, 0x9FC($at)
    ctx->r25 = ADD32(ctx->r1, 0X9FC);
    // 0x800A65F4: jr          $t9
    // 0x800A65F8: nop

    switch (jr_addend_800A65F4 >> 2) {
        case 0: goto L_800A65FC; break;
        case 1: goto L_800A6610; break;
        case 2: goto L_800A6624; break;
        case 3: goto L_800A6638; break;
        case 4: goto L_800A664C; break;
        case 5: goto L_800A6660; break;
        case 6: goto L_800A6674; break;
        default: switch_error(__func__, 0x800A65F4, 0x800E09FC);
    }
    // 0x800A65F8: nop

L_800A65FC:
    // 0x800A65FC: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    // 0x800A6600: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800A6604: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A6608: b           L_800A6684
    // 0x800A660C: sw          $t2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r10;
        goto L_800A6684;
    // 0x800A660C: sw          $t2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r10;
L_800A6610:
    // 0x800A6610: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x800A6614: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800A6618: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A661C: b           L_800A6684
    // 0x800A6620: sw          $t5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r13;
        goto L_800A6684;
    // 0x800A6620: sw          $t5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r13;
L_800A6624:
    // 0x800A6624: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x800A6628: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800A662C: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800A6630: b           L_800A6684
    // 0x800A6634: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
        goto L_800A6684;
    // 0x800A6634: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
L_800A6638:
    // 0x800A6638: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x800A663C: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x800A6640: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800A6644: b           L_800A6684
    // 0x800A6648: sw          $t1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r9;
        goto L_800A6684;
    // 0x800A6648: sw          $t1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r9;
L_800A664C:
    // 0x800A664C: lw          $t2, 0x10($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10);
    // 0x800A6650: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x800A6654: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A6658: b           L_800A6684
    // 0x800A665C: sw          $t4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r12;
        goto L_800A6684;
    // 0x800A665C: sw          $t4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r12;
L_800A6660:
    // 0x800A6660: lw          $t5, 0x10($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X10);
    // 0x800A6664: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800A6668: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800A666C: b           L_800A6684
    // 0x800A6670: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
        goto L_800A6684;
    // 0x800A6670: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_800A6674:
    // 0x800A6674: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x800A6678: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800A667C: addiu       $t0, $t9, 0x20
    ctx->r8 = ADD32(ctx->r25, 0X20);
    // 0x800A6680: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
L_800A6684:
    // 0x800A6684: b           L_800A66EC
    // 0x800A6688: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
        goto L_800A66EC;
    // 0x800A6688: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    // 0x800A668C: lw          $t1, 0x20($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X20);
L_800A6690:
    // 0x800A6690: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x800A6694: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x800A6698: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x800A669C: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x800A66A0: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x800A66A4: b           L_800A66EC
    // 0x800A66A8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
        goto L_800A66EC;
    // 0x800A66A8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800A66AC: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
L_800A66B0:
    // 0x800A66B0: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x800A66B4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800A66B8: multu       $t6, $fp
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A66BC: mflo        $t7
    ctx->r15 = lo;
    // 0x800A66C0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800A66C4: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800A66C8: b           L_800A66EC
    // 0x800A66CC: sw          $t9, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r25;
        goto L_800A66EC;
    // 0x800A66CC: sw          $t9, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r25;
    // 0x800A66D0: lw          $t0, 0x20($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X20);
L_800A66D4:
    // 0x800A66D4: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x800A66D8: lw          $t1, 0x44($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X44);
    // 0x800A66DC: sll         $t2, $t3, 3
    ctx->r10 = S32(ctx->r11 << 3);
    // 0x800A66E0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800A66E4: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x800A66E8: sw          $t4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r12;
L_800A66EC:
    // 0x800A66EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800A66F0:
    // 0x800A66F0: bne         $s2, $s4, L_800A659C
    if (ctx->r18 != ctx->r20) {
        // 0x800A66F4: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_800A659C;
    }
    // 0x800A66F4: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
L_800A66F8:
    // 0x800A66F8: lw          $t6, 0x14($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X14);
    // 0x800A66FC: ori         $t5, $t6, 0x1
    ctx->r13 = ctx->r14 | 0X1;
    // 0x800A6700: sw          $t5, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r13;
L_800A6704:
    // 0x800A6704: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800A6708:
    // 0x800A6708: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A670C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6710: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A6714: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A6718: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A671C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800A6720: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800A6724: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800A6728: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800A672C: jr          $ra
    // 0x800A6730: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800A6730: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void func_800A6734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6734: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6738: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A673C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A6740: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A6744: lw          $s0, 0x1D0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1D0);
    // 0x800A6748: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A674C: jal         0x800B3BFC
    // 0x800A6750: addiu       $a0, $a0, 0x930
    ctx->r4 = ADD32(ctx->r4, 0X930);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A6750: addiu       $a0, $a0, 0x930
    ctx->r4 = ADD32(ctx->r4, 0X930);
    after_0:
    // 0x800A6754: beq         $s0, $zero, L_800A6778
    if (ctx->r16 == 0) {
        // 0x800A6758: lui         $s1, 0x800E
        ctx->r17 = S32(0X800E << 16);
            goto L_800A6778;
    }
    // 0x800A6758: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800A675C: addiu       $s1, $s1, 0x940
    ctx->r17 = ADD32(ctx->r17, 0X940);
    // 0x800A6760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800A6764:
    // 0x800A6764: jal         0x800B3BFC
    // 0x800A6768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A6768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800A676C: lw          $s0, 0xC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XC);
    // 0x800A6770: bnel        $s0, $zero, L_800A6764
    if (ctx->r16 != 0) {
        // 0x800A6774: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800A6764;
    }
    goto skip_0;
    // 0x800A6774: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_800A6778:
    // 0x800A6778: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A677C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A6780: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A6784: jr          $ra
    // 0x800A6788: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A6788: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void func_800A678C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A678C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A6790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A6794: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    // 0x800A6798: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800A679C: bnel        $t7, $zero, L_800A67BC
    if (ctx->r15 != 0) {
        // 0x800A67A0: lw          $v0, 0x1D0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1D0);
            goto L_800A67BC;
    }
    goto skip_0;
    // 0x800A67A0: lw          $v0, 0x1D0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1D0);
    skip_0:
    // 0x800A67A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A67A8: jal         0x800A652C
    // 0x800A67AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A652C(rdram, ctx);
        goto after_0;
    // 0x800A67AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A67B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A67B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800A67B8: lw          $v0, 0x1D0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1D0);
L_800A67BC:
    // 0x800A67BC: bnel        $v0, $zero, L_800A67D0
    if (ctx->r2 != 0) {
        // 0x800A67C0: sw          $v0, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->r2;
            goto L_800A67D0;
    }
    goto skip_1;
    // 0x800A67C0: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    skip_1:
    // 0x800A67C4: b           L_800A67DC
    // 0x800A67C8: sw          $a1, 0x1D0($a0)
    MEM_W(0X1D0, ctx->r4) = ctx->r5;
        goto L_800A67DC;
    // 0x800A67C8: sw          $a1, 0x1D0($a0)
    MEM_W(0X1D0, ctx->r4) = ctx->r5;
    // 0x800A67CC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
L_800A67D0:
    // 0x800A67D0: lw          $t8, 0x1D0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1D0);
    // 0x800A67D4: sw          $a1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r5;
    // 0x800A67D8: sw          $a1, 0x1D0($a0)
    MEM_W(0X1D0, ctx->r4) = ctx->r5;
L_800A67DC:
    // 0x800A67DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A67E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A67E4: jr          $ra
    // 0x800A67E8: nop

    return;
    // 0x800A67E8: nop

;}

RECOMP_FUNC void func_800A67EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A67EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A67F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A67F4: bne         $a0, $zero, L_800A6810
    if (ctx->r4 != 0) {
        // 0x800A67F8: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800A6810;
    }
    // 0x800A67F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A67FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A6800: jal         0x800B3BFC
    // 0x800A6804: addiu       $a0, $a0, 0x950
    ctx->r4 = ADD32(ctx->r4, 0X950);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A6804: addiu       $a0, $a0, 0x950
    ctx->r4 = ADD32(ctx->r4, 0X950);
    after_0:
    // 0x800A6808: b           L_800A6890
    // 0x800A680C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A6890;
    // 0x800A680C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A6810:
    // 0x800A6810: lw          $v1, 0x10($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X10);
    // 0x800A6814: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A6818: addiu       $a0, $a0, 0x960
    ctx->r4 = ADD32(ctx->r4, 0X960);
    // 0x800A681C: bnel        $v1, $zero, L_800A684C
    if (ctx->r3 != 0) {
        // 0x800A6820: lw          $v0, 0x8($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X8);
            goto L_800A684C;
    }
    goto skip_0;
    // 0x800A6820: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    skip_0:
    // 0x800A6824: jal         0x800B3BFC
    // 0x800A6828: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A6828: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x800A682C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A6830: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A6834: addiu       $a0, $a0, 0x978
    ctx->r4 = ADD32(ctx->r4, 0X978);
    // 0x800A6838: jal         0x800B3BFC
    // 0x800A683C: lw          $a1, 0x10($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X10);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800A683C: lw          $a1, 0x10($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X10);
    after_2:
    // 0x800A6840: b           L_800A6890
    // 0x800A6844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A6890;
    // 0x800A6844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6848: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
L_800A684C:
    // 0x800A684C: beql        $v0, $zero, L_800A6860
    if (ctx->r2 == 0) {
        // 0x800A6850: lw          $v0, 0xC($a2)
        ctx->r2 = MEM_W(ctx->r6, 0XC);
            goto L_800A6860;
    }
    goto skip_1;
    // 0x800A6850: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    skip_1:
    // 0x800A6854: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x800A6858: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x800A685C: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
L_800A6860:
    // 0x800A6860: beql        $v0, $zero, L_800A6874
    if (ctx->r2 == 0) {
        // 0x800A6864: lw          $t8, 0x1D0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X1D0);
            goto L_800A6874;
    }
    goto skip_2;
    // 0x800A6864: lw          $t8, 0x1D0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1D0);
    skip_2:
    // 0x800A6868: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x800A686C: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800A6870: lw          $t8, 0x1D0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1D0);
L_800A6874:
    // 0x800A6874: bnel        $a2, $t8, L_800A6888
    if (ctx->r6 != ctx->r24) {
        // 0x800A6878: sw          $zero, 0xC($a2)
        MEM_W(0XC, ctx->r6) = 0;
            goto L_800A6888;
    }
    goto skip_3;
    // 0x800A6878: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    skip_3:
    // 0x800A687C: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x800A6880: sw          $t9, 0x1D0($v1)
    MEM_W(0X1D0, ctx->r3) = ctx->r25;
    // 0x800A6884: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
L_800A6888:
    // 0x800A6888: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x800A688C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A6890:
    // 0x800A6890: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A6894: jr          $ra
    // 0x800A6898: nop

    return;
    // 0x800A6898: nop

;}

RECOMP_FUNC void func_800A689C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A689C: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x800A68A0: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800A68A4: addu        $t6, $a1, $a3
    ctx->r14 = ADD32(ctx->r5, ctx->r7);
    // 0x800A68A8: beq         $v0, $zero, L_800A696C
    if (ctx->r2 == 0) {
        // 0x800A68AC: nop
    
            goto L_800A696C;
    }
    // 0x800A68AC: nop

    // 0x800A68B0: bgez        $t6, L_800A68C0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800A68B4: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_800A68C0;
    }
    // 0x800A68B4: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800A68B8: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x800A68BC: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800A68C0:
    // 0x800A68C0: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x800A68C4: addu        $t9, $a2, $v1
    ctx->r25 = ADD32(ctx->r6, ctx->r3);
    // 0x800A68C8: subu        $t5, $a1, $a3
    ctx->r13 = SUB32(ctx->r5, ctx->r7);
    // 0x800A68CC: sh          $t7, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r15;
    // 0x800A68D0: bgez        $t9, L_800A68E0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800A68D4: sra         $t0, $t9, 1
        ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
            goto L_800A68E0;
    }
    // 0x800A68D4: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800A68D8: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x800A68DC: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_800A68E0:
    // 0x800A68E0: lw          $t1, 0x28($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X28);
    // 0x800A68E4: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800A68E8: beq         $at, $zero, L_800A6910
    if (ctx->r1 == 0) {
        // 0x800A68EC: sh          $t0, 0xA($t1)
        MEM_H(0XA, ctx->r9) = ctx->r8;
            goto L_800A6910;
    }
    // 0x800A68EC: sh          $t0, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r8;
    // 0x800A68F0: subu        $t2, $a3, $a1
    ctx->r10 = SUB32(ctx->r7, ctx->r5);
    // 0x800A68F4: lw          $t4, 0x28($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X28);
    // 0x800A68F8: bgez        $t2, L_800A6908
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A68FC: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800A6908;
    }
    // 0x800A68FC: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800A6900: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800A6904: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800A6908:
    // 0x800A6908: b           L_800A6928
    // 0x800A690C: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
        goto L_800A6928;
    // 0x800A690C: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
L_800A6910:
    // 0x800A6910: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x800A6914: bgez        $t5, L_800A6924
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800A6918: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_800A6924;
    }
    // 0x800A6918: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800A691C: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x800A6920: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_800A6924:
    // 0x800A6924: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
L_800A6928:
    // 0x800A6928: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A692C: beq         $at, $zero, L_800A6954
    if (ctx->r1 == 0) {
        // 0x800A6930: subu        $t1, $a2, $v1
        ctx->r9 = SUB32(ctx->r6, ctx->r3);
            goto L_800A6954;
    }
    // 0x800A6930: subu        $t1, $a2, $v1
    ctx->r9 = SUB32(ctx->r6, ctx->r3);
    // 0x800A6934: subu        $t8, $v1, $a2
    ctx->r24 = SUB32(ctx->r3, ctx->r6);
    // 0x800A6938: lw          $t0, 0x28($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X28);
    // 0x800A693C: bgez        $t8, L_800A694C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A6940: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_800A694C;
    }
    // 0x800A6940: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800A6944: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x800A6948: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800A694C:
    // 0x800A694C: jr          $ra
    // 0x800A6950: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    return;
    // 0x800A6950: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
L_800A6954:
    // 0x800A6954: lw          $t3, 0x28($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X28);
    // 0x800A6958: bgez        $t1, L_800A6968
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800A695C: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_800A6968;
    }
    // 0x800A695C: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800A6960: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x800A6964: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_800A6968:
    // 0x800A6968: sh          $t2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r10;
L_800A696C:
    // 0x800A696C: jr          $ra
    // 0x800A6970: nop

    return;
    // 0x800A6970: nop

;}

RECOMP_FUNC void func_800A6974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6974: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A6978: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x800A697C: beq         $v0, $zero, L_800A6988
    if (ctx->r2 == 0) {
        // 0x800A6980: nop
    
            goto L_800A6988;
    }
    // 0x800A6980: nop

    // 0x800A6984: sw          $a1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r5;
L_800A6988:
    // 0x800A6988: jr          $ra
    // 0x800A698C: nop

    return;
    // 0x800A698C: nop

;}

RECOMP_FUNC void func_800A6990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6990: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6994: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6998: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A699C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A69A0: jal         0x8007E03C
    // 0x800A69A4: addiu       $a0, $zero, 0x1E8
    ctx->r4 = ADD32(0, 0X1E8);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800A69A4: addiu       $a0, $zero, 0x1E8
    ctx->r4 = ADD32(0, 0X1E8);
    after_0:
    // 0x800A69A8: bne         $v0, $zero, L_800A69B8
    if (ctx->r2 != 0) {
        // 0x800A69AC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800A69B8;
    }
    // 0x800A69AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A69B0: b           L_800A6A18
    // 0x800A69B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A6A18;
    // 0x800A69B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A69B8:
    // 0x800A69B8: jal         0x800A9D50
    // 0x800A69BC: nop

    func_800A9D50(rdram, ctx);
        goto after_1;
    // 0x800A69BC: nop

    after_1:
    // 0x800A69C0: jal         0x800AA14C
    // 0x800A69C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    CubeTiles_ObjInstantiate(rdram, ctx);
        goto after_2;
    // 0x800A69C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800A69C8: jal         0x800A9D60
    // 0x800A69CC: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    func_800A9D60(rdram, ctx);
        goto after_3;
    // 0x800A69CC: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    after_3:
    // 0x800A69D0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x800A69D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A69D8: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x800A69DC: bnel        $t6, $zero, L_800A69F8
    if (ctx->r14 != 0) {
        // 0x800A69E0: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_800A69F8;
    }
    goto skip_0;
    // 0x800A69E0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    skip_0:
    // 0x800A69E4: jal         0x8007E328
    // 0x800A69E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_4;
    // 0x800A69E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800A69EC: b           L_800A6A18
    // 0x800A69F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A6A18;
    // 0x800A69F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A69F4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800A69F8:
    // 0x800A69F8: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x800A69FC: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x800A6A00: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x800A6A04: jal         0x800B79D0
    // 0x800A6A08: sw          $zero, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = 0;
    guMtxIdentF(rdram, ctx);
        goto after_5;
    // 0x800A6A08: sw          $zero, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = 0;
    after_5:
    // 0x800A6A0C: jal         0x800B79D0
    // 0x800A6A10: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    guMtxIdentF(rdram, ctx);
        goto after_6;
    // 0x800A6A10: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    after_6:
    // 0x800A6A14: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800A6A18:
    // 0x800A6A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6A1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A6A20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A6A24: jr          $ra
    // 0x800A6A28: nop

    return;
    // 0x800A6A28: nop

;}

RECOMP_FUNC void func_800A6A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6A2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A6A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A6A34: bne         $a0, $zero, L_800A6A50
    if (ctx->r4 != 0) {
        // 0x800A6A38: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800A6A50;
    }
    // 0x800A6A38: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A6A3C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A6A40: jal         0x800B3BFC
    // 0x800A6A44: addiu       $a0, $a0, 0x994
    ctx->r4 = ADD32(ctx->r4, 0X994);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A6A44: addiu       $a0, $a0, 0x994
    ctx->r4 = ADD32(ctx->r4, 0X994);
    after_0:
    // 0x800A6A48: b           L_800A6A68
    // 0x800A6A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A6A68;
    // 0x800A6A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A6A50:
    // 0x800A6A50: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x800A6A54: jal         0x800AB5E0
    // 0x800A6A58: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800AB5E0(rdram, ctx);
        goto after_1;
    // 0x800A6A58: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x800A6A5C: jal         0x8007E328
    // 0x800A6A60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    n64HeapUnalloc(rdram, ctx);
        goto after_2;
    // 0x800A6A60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800A6A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A6A68:
    // 0x800A6A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A6A6C: jr          $ra
    // 0x800A6A70: nop

    return;
    // 0x800A6A70: nop

;}

RECOMP_FUNC void func_800A6A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6A74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A6A7C: jal         0x800A9D50
    // 0x800A6A80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800A9D50(rdram, ctx);
        goto after_0;
    // 0x800A6A80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A6A84: jal         0x800AA14C
    // 0x800A6A88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    CubeTiles_ObjInstantiate(rdram, ctx);
        goto after_1;
    // 0x800A6A88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800A6A8C: jal         0x800A9D60
    // 0x800A6A90: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800A9D60(rdram, ctx);
        goto after_2;
    // 0x800A6A90: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x800A6A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6A98: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6A9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A6AA0: jr          $ra
    // 0x800A6AA4: nop

    return;
    // 0x800A6AA4: nop

;}

RECOMP_FUNC void func_800A6AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A6AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A6AB0: jal         0x800AB934
    // 0x800A6AB4: nop

    func_800AB934(rdram, ctx);
        goto after_0;
    // 0x800A6AB4: nop

    after_0:
    // 0x800A6AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6ABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A6AC0: jr          $ra
    // 0x800A6AC4: nop

    return;
    // 0x800A6AC4: nop

;}

RECOMP_FUNC void func_800A6AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6AC8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800A6ACC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A6AD0: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    // 0x800A6AD4: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x800A6AD8: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x800A6ADC: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x800A6AE0: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800A6AE4: beq         $v1, $zero, L_800A6B0C
    if (ctx->r3 == 0) {
        // 0x800A6AE8: andi        $t7, $v1, 0x1
        ctx->r15 = ctx->r3 & 0X1;
            goto L_800A6B0C;
    }
L_800A6AE8:
    // 0x800A6AE8: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x800A6AEC: beq         $t7, $zero, L_800A6B00
    if (ctx->r15 == 0) {
        // 0x800A6AF0: sra         $t8, $v1, 1
        ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800A6B00;
    }
    // 0x800A6AF0: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800A6AF4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A6AF8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800A6AFC: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
L_800A6B00:
    // 0x800A6B00: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800A6B04: bne         $t8, $zero, L_800A6AE8
    if (ctx->r24 != 0) {
        // 0x800A6B08: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800A6AE8;
    }
    // 0x800A6B08: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800A6B0C:
    // 0x800A6B0C: jr          $ra
    // 0x800A6B10: nop

    return;
    // 0x800A6B10: nop

;}

RECOMP_FUNC void func_800A6B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6B14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A6B18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A6B1C: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800A6B20: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A6B24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A6B28: bnel        $t6, $at, L_800A6B48
    if (ctx->r14 != ctx->r1) {
        // 0x800A6B2C: mfc1        $a1, $f12
        ctx->r5 = (int32_t)ctx->f12.u32l;
            goto L_800A6B48;
    }
    goto skip_0;
    // 0x800A6B2C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    skip_0:
    // 0x800A6B30: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800A6B34: jal         0x800A6BB0
    // 0x800A6B38: nop

    func_800A6BB0(rdram, ctx);
        goto after_0;
    // 0x800A6B38: nop

    after_0:
    // 0x800A6B3C: b           L_800A6B54
    // 0x800A6B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A6B54;
    // 0x800A6B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6B44: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
L_800A6B48:
    // 0x800A6B48: jal         0x800A6B60
    // 0x800A6B4C: nop

    func_800A6B60(rdram, ctx);
        goto after_1;
    // 0x800A6B4C: nop

    after_1:
    // 0x800A6B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A6B54:
    // 0x800A6B54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A6B58: jr          $ra
    // 0x800A6B5C: nop

    return;
    // 0x800A6B5C: nop

;}

RECOMP_FUNC void func_800A6B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6B60: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x800A6B64: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A6B68: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800A6B6C: beq         $v1, $zero, L_800A6BA8
    if (ctx->r3 == 0) {
        // 0x800A6B70: lw          $a1, 0x10($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X10);
            goto L_800A6BA8;
    }
    // 0x800A6B70: lw          $a1, 0x10($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X10);
L_800A6B74:
    // 0x800A6B74: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x800A6B78: beq         $t6, $zero, L_800A6B9C
    if (ctx->r14 == 0) {
        // 0x800A6B7C: sra         $t8, $v1, 1
        ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800A6B9C;
    }
    // 0x800A6B7C: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800A6B80: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x800A6B84: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A6B88: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800A6B8C: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800A6B90: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800A6B94: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800A6B98: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_800A6B9C:
    // 0x800A6B9C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800A6BA0: bne         $t8, $zero, L_800A6B74
    if (ctx->r24 != 0) {
        // 0x800A6BA4: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800A6B74;
    }
    // 0x800A6BA4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800A6BA8:
    // 0x800A6BA8: jr          $ra
    // 0x800A6BAC: nop

    return;
    // 0x800A6BAC: nop

;}

RECOMP_FUNC void func_800A6BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6BB0: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800A6BB4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A6BB8: lw          $t0, 0x1C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C);
    // 0x800A6BBC: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x800A6BC0: lw          $t1, 0x14($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14);
    // 0x800A6BC4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800A6BC8: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800A6BCC: addiu       $a1, $a2, 0x158
    ctx->r5 = ADD32(ctx->r6, 0X158);
    // 0x800A6BD0: addiu       $a3, $a2, 0x164
    ctx->r7 = ADD32(ctx->r6, 0X164);
L_800A6BD4:
    // 0x800A6BD4: andi        $t6, $t1, 0x1
    ctx->r14 = ctx->r9 & 0X1;
    // 0x800A6BD8: beq         $t6, $zero, L_800A6C2C
    if (ctx->r14 == 0) {
        // 0x800A6BDC: addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
            goto L_800A6C2C;
    }
    // 0x800A6BDC: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800A6BE0: lw          $t7, 0x10($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X10);
    // 0x800A6BE4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A6BE8: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
    // 0x800A6BEC: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800A6BF0: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800A6BF4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800A6BF8: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x800A6BFC: lw          $t8, -0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, -0X4);
    // 0x800A6C00: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A6C04: lwc1        $f18, 0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800A6C08: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800A6C0C: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800A6C10: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800A6C14: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x800A6C18: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800A6C1C: lwc1        $f10, 0x8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800A6C20: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800A6C24: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800A6C28: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
L_800A6C2C:
    // 0x800A6C2C: sra         $t3, $t1, 1
    ctx->r11 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800A6C30: or          $t1, $t3, $zero
    ctx->r9 = ctx->r11 | 0;
    // 0x800A6C34: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A6C38: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800A6C3C: bne         $t2, $zero, L_800A6BD4
    if (ctx->r10 != 0) {
        // 0x800A6C40: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800A6BD4;
    }
    // 0x800A6C40: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800A6C44: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x800A6C48: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800A6C4C: addiu       $a1, $a2, 0x140
    ctx->r5 = ADD32(ctx->r6, 0X140);
    // 0x800A6C50: addiu       $a3, $a2, 0x14C
    ctx->r7 = ADD32(ctx->r6, 0X14C);
L_800A6C54:
    // 0x800A6C54: andi        $t4, $t1, 0x1
    ctx->r12 = ctx->r9 & 0X1;
    // 0x800A6C58: beq         $t4, $zero, L_800A6CAC
    if (ctx->r12 == 0) {
        // 0x800A6C5C: addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
            goto L_800A6CAC;
    }
    // 0x800A6C5C: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800A6C60: lw          $t5, 0x10($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X10);
    // 0x800A6C64: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A6C68: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
    // 0x800A6C6C: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800A6C70: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800A6C74: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A6C78: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x800A6C7C: lw          $t6, -0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, -0X4);
    // 0x800A6C80: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A6C84: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800A6C88: mul.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800A6C8C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A6C90: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x800A6C94: lw          $t7, -0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, -0X4);
    // 0x800A6C98: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800A6C9C: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800A6CA0: mul.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800A6CA4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800A6CA8: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_800A6CAC:
    // 0x800A6CAC: sra         $t8, $t1, 1
    ctx->r24 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800A6CB0: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800A6CB4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A6CB8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800A6CBC: bne         $t2, $zero, L_800A6C54
    if (ctx->r10 != 0) {
        // 0x800A6CC0: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800A6C54;
    }
    // 0x800A6CC0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800A6CC4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_800A6CC8:
    // 0x800A6CC8: andi        $t9, $t1, 0x1
    ctx->r25 = ctx->r9 & 0X1;
    // 0x800A6CCC: beq         $t9, $zero, L_800A6CF0
    if (ctx->r25 == 0) {
        // 0x800A6CD0: addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
            goto L_800A6CF0;
    }
    // 0x800A6CD0: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800A6CD4: lw          $t3, 0x10($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X10);
    // 0x800A6CD8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A6CDC: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
    // 0x800A6CE0: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800A6CE4: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800A6CE8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800A6CEC: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
L_800A6CF0:
    // 0x800A6CF0: sra         $t4, $t1, 1
    ctx->r12 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800A6CF4: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
    // 0x800A6CF8: bne         $t2, $zero, L_800A6CC8
    if (ctx->r10 != 0) {
        // 0x800A6CFC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800A6CC8;
    }
    // 0x800A6CFC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A6D00: jr          $ra
    // 0x800A6D04: nop

    return;
    // 0x800A6D04: nop

;}

RECOMP_FUNC void func_800A6D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6D08: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800A6D0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A6D10: bnel        $t6, $at, L_800A6D60
    if (ctx->r14 != ctx->r1) {
        // 0x800A6D14: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800A6D60;
    }
    goto skip_0;
    // 0x800A6D14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x800A6D18: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800A6D1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A6D20: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x800A6D24: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800A6D28: swc1        $f0, 0x16C($a1)
    MEM_W(0X16C, ctx->r5) = ctx->f0.u32l;
    // 0x800A6D2C: swc1        $f0, 0x168($a1)
    MEM_W(0X168, ctx->r5) = ctx->f0.u32l;
    // 0x800A6D30: swc1        $f0, 0x164($a1)
    MEM_W(0X164, ctx->r5) = ctx->f0.u32l;
    // 0x800A6D34: swc1        $f0, 0x160($a1)
    MEM_W(0X160, ctx->r5) = ctx->f0.u32l;
    // 0x800A6D38: swc1        $f0, 0x15C($a1)
    MEM_W(0X15C, ctx->r5) = ctx->f0.u32l;
    // 0x800A6D3C: swc1        $f0, 0x158($a1)
    MEM_W(0X158, ctx->r5) = ctx->f0.u32l;
    // 0x800A6D40: swc1        $f0, 0x154($a1)
    MEM_W(0X154, ctx->r5) = ctx->f0.u32l;
    // 0x800A6D44: swc1        $f0, 0x150($a1)
    MEM_W(0X150, ctx->r5) = ctx->f0.u32l;
    // 0x800A6D48: swc1        $f0, 0x14C($a1)
    MEM_W(0X14C, ctx->r5) = ctx->f0.u32l;
    // 0x800A6D4C: swc1        $f0, 0x148($a1)
    MEM_W(0X148, ctx->r5) = ctx->f0.u32l;
    // 0x800A6D50: swc1        $f0, 0x144($a1)
    MEM_W(0X144, ctx->r5) = ctx->f0.u32l;
    // 0x800A6D54: b           L_800A6D64
    // 0x800A6D58: swc1        $f0, 0x140($a1)
    MEM_W(0X140, ctx->r5) = ctx->f0.u32l;
        goto L_800A6D64;
    // 0x800A6D58: swc1        $f0, 0x140($a1)
    MEM_W(0X140, ctx->r5) = ctx->f0.u32l;
    // 0x800A6D5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800A6D60:
    // 0x800A6D60: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
L_800A6D64:
    // 0x800A6D64: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x800A6D68: beq         $v0, $zero, L_800A6D88
    if (ctx->r2 == 0) {
        // 0x800A6D6C: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_800A6D88;
    }
L_800A6D6C:
    // 0x800A6D6C: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800A6D70: beq         $t7, $zero, L_800A6D7C
    if (ctx->r15 == 0) {
        // 0x800A6D74: sra         $t8, $v0, 1
        ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800A6D7C;
    }
    // 0x800A6D74: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800A6D78: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_800A6D7C:
    // 0x800A6D7C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A6D80: bne         $t8, $zero, L_800A6D6C
    if (ctx->r24 != 0) {
        // 0x800A6D84: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800A6D6C;
    }
    // 0x800A6D84: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800A6D88:
    // 0x800A6D88: jr          $ra
    // 0x800A6D8C: nop

    return;
    // 0x800A6D8C: nop

;}

RECOMP_FUNC void func_800A6D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6D90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6D94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6D98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A6D9C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A6DA0: lw          $s0, 0x18($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X18);
    // 0x800A6DA4: lw          $s1, 0x1C($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1C);
    // 0x800A6DA8: beql        $s0, $zero, L_800A6DC8
    if (ctx->r16 == 0) {
        // 0x800A6DAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6DC8;
    }
    goto skip_0;
    // 0x800A6DAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_800A6DB0:
    // 0x800A6DB0: jal         0x800A6AC8
    // 0x800A6DB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A6AC8(rdram, ctx);
        goto after_0;
    // 0x800A6DB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800A6DB8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800A6DBC: bne         $s0, $zero, L_800A6DB0
    if (ctx->r16 != 0) {
        // 0x800A6DC0: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_800A6DB0;
    }
    // 0x800A6DC0: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x800A6DC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A6DC8:
    // 0x800A6DC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A6DCC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A6DD0: jr          $ra
    // 0x800A6DD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A6DD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void func_800A6DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6DD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A6DDC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A6DE0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A6DE4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A6DE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A6DEC: lw          $s2, 0x1D0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1D0);
    // 0x800A6DF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A6DF4: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    // 0x800A6DF8: beql        $s2, $zero, L_800A6E34
    if (ctx->r18 == 0) {
        // 0x800A6DFC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A6E34;
    }
    goto skip_0;
    // 0x800A6DFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800A6E00: lw          $s0, 0x24($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X24);
L_800A6E04:
    // 0x800A6E04: lw          $s1, 0x28($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X28);
    // 0x800A6E08: beql        $s0, $zero, L_800A6E28
    if (ctx->r16 == 0) {
        // 0x800A6E0C: lw          $s2, 0xC($s2)
        ctx->r18 = MEM_W(ctx->r18, 0XC);
            goto L_800A6E28;
    }
    goto skip_1;
    // 0x800A6E0C: lw          $s2, 0xC($s2)
    ctx->r18 = MEM_W(ctx->r18, 0XC);
    skip_1:
L_800A6E10:
    // 0x800A6E10: jal         0x800A6D90
    // 0x800A6E14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A6D90(rdram, ctx);
        goto after_0;
    // 0x800A6E14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800A6E18: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800A6E1C: bne         $s0, $zero, L_800A6E10
    if (ctx->r16 != 0) {
        // 0x800A6E20: addiu       $s1, $s1, 0x24
        ctx->r17 = ADD32(ctx->r17, 0X24);
            goto L_800A6E10;
    }
    // 0x800A6E20: addiu       $s1, $s1, 0x24
    ctx->r17 = ADD32(ctx->r17, 0X24);
    // 0x800A6E24: lw          $s2, 0xC($s2)
    ctx->r18 = MEM_W(ctx->r18, 0XC);
L_800A6E28:
    // 0x800A6E28: bnel        $s2, $zero, L_800A6E04
    if (ctx->r18 != 0) {
        // 0x800A6E2C: lw          $s0, 0x24($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X24);
            goto L_800A6E04;
    }
    goto skip_2;
    // 0x800A6E2C: lw          $s0, 0x24($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X24);
    skip_2:
    // 0x800A6E30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A6E34:
    // 0x800A6E34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A6E38: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6E3C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A6E40: jr          $ra
    // 0x800A6E44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A6E44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800A6E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6E48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A6E4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A6E50: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800A6E54: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800A6E58: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800A6E5C: lw          $s1, 0x18($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X18);
    // 0x800A6E60: lw          $s0, 0x1C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1C);
    // 0x800A6E64: beql        $s1, $zero, L_800A7094
    if (ctx->r17 == 0) {
        // 0x800A6E68: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A7094;
    }
    goto skip_0;
    // 0x800A6E68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800A6E6C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800A6E70: nop

L_800A6E74:
    // 0x800A6E74: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x800A6E78: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x800A6E7C: bnel        $t6, $v0, L_800A6EE0
    if (ctx->r14 != ctx->r2) {
        // 0x800A6E80: lw          $a2, 0x8($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X8);
            goto L_800A6EE0;
    }
    goto skip_1;
    // 0x800A6E80: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x800A6E84: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A6E88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A6E8C: beq         $v0, $zero, L_800A6EAC
    if (ctx->r2 == 0) {
        // 0x800A6E90: nop
    
            goto L_800A6EAC;
    }
    // 0x800A6E90: nop

    // 0x800A6E94: beq         $v0, $at, L_800A6EBC
    if (ctx->r2 == ctx->r1) {
        // 0x800A6E98: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A6EBC;
    }
    // 0x800A6E98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A6E9C: beq         $v0, $at, L_800A6ECC
    if (ctx->r2 == ctx->r1) {
        // 0x800A6EA0: nop
    
            goto L_800A6ECC;
    }
    // 0x800A6EA0: nop

    // 0x800A6EA4: b           L_800A7088
    // 0x800A6EA8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_800A7088;
    // 0x800A6EA8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_800A6EAC:
    // 0x800A6EAC: jal         0x800A6AC8
    // 0x800A6EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A6AC8(rdram, ctx);
        goto after_0;
    // 0x800A6EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800A6EB4: b           L_800A7088
    // 0x800A6EB8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_800A7088;
    // 0x800A6EB8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_800A6EBC:
    // 0x800A6EBC: jal         0x800A6AC8
    // 0x800A6EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A6AC8(rdram, ctx);
        goto after_1;
    // 0x800A6EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A6EC4: b           L_800A7088
    // 0x800A6EC8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_800A7088;
    // 0x800A6EC8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_800A6ECC:
    // 0x800A6ECC: jal         0x800A6AC8
    // 0x800A6ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A6AC8(rdram, ctx);
        goto after_2;
    // 0x800A6ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A6ED4: b           L_800A7088
    // 0x800A6ED8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_800A7088;
    // 0x800A6ED8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800A6EDC: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
L_800A6EE0:
    // 0x800A6EE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800A6EE4: lh          $t7, 0x8($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X8);
    // 0x800A6EE8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800A6EEC: bnel        $v0, $t7, L_800A7014
    if (ctx->r2 != ctx->r15) {
        // 0x800A6EF0: lw          $a2, 0x8($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X8);
            goto L_800A7014;
    }
    goto skip_2;
    // 0x800A6EF0: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x800A6EF4: sw          $a2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r6;
    // 0x800A6EF8: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800A6EFC: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800A6F00: lh          $v1, 0x2($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X2);
L_800A6F04:
    // 0x800A6F04: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x800A6F08: bne         $t8, $zero, L_800A6F20
    if (ctx->r24 != 0) {
        // 0x800A6F0C: sra         $t9, $v1, 1
        ctx->r25 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800A6F20;
    }
    // 0x800A6F0C: sra         $t9, $v1, 1
    ctx->r25 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800A6F10: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800A6F14: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A6F18: bne         $a1, $zero, L_800A6F04
    if (ctx->r5 != 0) {
        // 0x800A6F1C: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800A6F04;
    }
    // 0x800A6F1C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_800A6F20:
    // 0x800A6F20: beq         $a1, $zero, L_800A7010
    if (ctx->r5 == 0) {
        // 0x800A6F24: andi        $a3, $a1, 0x3
        ctx->r7 = ctx->r5 & 0X3;
            goto L_800A7010;
    }
    // 0x800A6F24: andi        $a3, $a1, 0x3
    ctx->r7 = ctx->r5 & 0X3;
    // 0x800A6F28: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x800A6F2C: beq         $a3, $zero, L_800A6F68
    if (ctx->r7 == 0) {
        // 0x800A6F30: addu        $a2, $a3, $a1
        ctx->r6 = ADD32(ctx->r7, ctx->r5);
            goto L_800A6F68;
    }
    // 0x800A6F30: addu        $a2, $a3, $a1
    ctx->r6 = ADD32(ctx->r7, ctx->r5);
L_800A6F34:
    // 0x800A6F34: andi        $t0, $v1, 0x1
    ctx->r8 = ctx->r3 & 0X1;
    // 0x800A6F38: beq         $t0, $zero, L_800A6F50
    if (ctx->r8 == 0) {
        // 0x800A6F3C: sra         $t1, $v1, 1
        ctx->r9 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800A6F50;
    }
    // 0x800A6F3C: sra         $t1, $v1, 1
    ctx->r9 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800A6F40: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A6F44: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A6F48: b           L_800A6F54
    // 0x800A6F4C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
        goto L_800A6F54;
    // 0x800A6F4C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_800A6F50:
    // 0x800A6F50: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
L_800A6F54:
    // 0x800A6F54: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800A6F58: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A6F5C: bne         $a2, $a1, L_800A6F34
    if (ctx->r6 != ctx->r5) {
        // 0x800A6F60: or          $v1, $t1, $zero
        ctx->r3 = ctx->r9 | 0;
            goto L_800A6F34;
    }
    // 0x800A6F60: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800A6F64: beq         $a1, $zero, L_800A7010
    if (ctx->r5 == 0) {
        // 0x800A6F68: andi        $t2, $v1, 0x1
        ctx->r10 = ctx->r3 & 0X1;
            goto L_800A7010;
    }
L_800A6F68:
    // 0x800A6F68: andi        $t2, $v1, 0x1
    ctx->r10 = ctx->r3 & 0X1;
    // 0x800A6F6C: beq         $t2, $zero, L_800A6F84
    if (ctx->r10 == 0) {
        // 0x800A6F70: sra         $t3, $v1, 1
        ctx->r11 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800A6F84;
    }
    // 0x800A6F70: sra         $t3, $v1, 1
    ctx->r11 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800A6F74: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A6F78: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A6F7C: b           L_800A6F88
    // 0x800A6F80: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_800A6F88;
    // 0x800A6F80: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_800A6F84:
    // 0x800A6F84: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
L_800A6F88:
    // 0x800A6F88: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800A6F8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A6F90: beq         $t4, $zero, L_800A6FA8
    if (ctx->r12 == 0) {
        // 0x800A6F94: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800A6FA8;
    }
    // 0x800A6F94: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800A6F98: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A6F9C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A6FA0: b           L_800A6FAC
    // 0x800A6FA4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
        goto L_800A6FAC;
    // 0x800A6FA4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_800A6FA8:
    // 0x800A6FA8: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
L_800A6FAC:
    // 0x800A6FAC: sra         $t5, $v1, 1
    ctx->r13 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800A6FB0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800A6FB4: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800A6FB8: beq         $t6, $zero, L_800A6FD0
    if (ctx->r14 == 0) {
        // 0x800A6FBC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800A6FD0;
    }
    // 0x800A6FBC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A6FC0: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A6FC4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A6FC8: b           L_800A6FD4
    // 0x800A6FCC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_800A6FD4;
    // 0x800A6FCC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_800A6FD0:
    // 0x800A6FD0: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
L_800A6FD4:
    // 0x800A6FD4: sra         $t7, $v1, 1
    ctx->r15 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800A6FD8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800A6FDC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800A6FE0: beq         $t8, $zero, L_800A6FF8
    if (ctx->r24 == 0) {
        // 0x800A6FE4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800A6FF8;
    }
    // 0x800A6FE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A6FE8: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A6FEC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A6FF0: b           L_800A6FFC
    // 0x800A6FF4: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
        goto L_800A6FFC;
    // 0x800A6FF4: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_800A6FF8:
    // 0x800A6FF8: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
L_800A6FFC:
    // 0x800A6FFC: sra         $t9, $v1, 1
    ctx->r25 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800A7000: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800A7004: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800A7008: bne         $a1, $zero, L_800A6F68
    if (ctx->r5 != 0) {
        // 0x800A700C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800A6F68;
    }
    // 0x800A700C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800A7010:
    // 0x800A7010: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
L_800A7014:
    // 0x800A7014: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800A7018: lh          $v1, 0x2($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X2);
    // 0x800A701C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x800A7020: andi        $t0, $v1, 0x2
    ctx->r8 = ctx->r3 & 0X2;
    // 0x800A7024: beql        $t0, $zero, L_800A707C
    if (ctx->r8 == 0) {
        // 0x800A7028: lh          $t3, 0x6($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X6);
            goto L_800A707C;
    }
    goto skip_3;
    // 0x800A7028: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    skip_3:
    // 0x800A702C: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A7030: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A7034: andi        $t1, $v1, 0x4
    ctx->r9 = ctx->r3 & 0X4;
    // 0x800A7038: addiu       $a0, $a1, 0x4
    ctx->r4 = ADD32(ctx->r5, 0X4);
    // 0x800A703C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A7040: beq         $t1, $zero, L_800A7078
    if (ctx->r9 == 0) {
        // 0x800A7044: swc1        $f6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
            goto L_800A7078;
    }
    // 0x800A7044: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x800A7048: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A704C: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A7050: andi        $t2, $v1, 0x8
    ctx->r10 = ctx->r3 & 0X8;
    // 0x800A7054: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x800A7058: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A705C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A7060: beq         $t2, $zero, L_800A7078
    if (ctx->r10 == 0) {
        // 0x800A7064: swc1        $f16, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
            goto L_800A7078;
    }
    // 0x800A7064: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x800A7068: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A706C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A7070: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A7074: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_800A7078:
    // 0x800A7078: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
L_800A707C:
    // 0x800A707C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800A7080: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x800A7084: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_800A7088:
    // 0x800A7088: bne         $s1, $zero, L_800A6E74
    if (ctx->r17 != 0) {
        // 0x800A708C: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800A6E74;
    }
    // 0x800A708C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800A7090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A7094:
    // 0x800A7094: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800A7098: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800A709C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800A70A0: jr          $ra
    // 0x800A70A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A70A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800A70A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A70A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A70AC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A70B0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800A70B4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800A70B8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800A70BC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800A70C0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800A70C4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800A70C8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800A70CC: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x800A70D0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800A70D4: beql        $t6, $zero, L_800A71B8
    if (ctx->r14 == 0) {
        // 0x800A70D8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800A71B8;
    }
    goto skip_0;
    // 0x800A70D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x800A70DC: lw          $v0, 0x1D0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1D0);
    // 0x800A70E0: beql        $v0, $zero, L_800A71B8
    if (ctx->r2 == 0) {
        // 0x800A70E4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800A71B8;
    }
    goto skip_1;
    // 0x800A70E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x800A70E8: beq         $v0, $zero, L_800A7144
    if (ctx->r2 == 0) {
        // 0x800A70EC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800A7144;
    }
    // 0x800A70EC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800A70F0: lw          $s2, 0x24($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X24);
L_800A70F4:
    // 0x800A70F4: lw          $s1, 0x28($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X28);
    // 0x800A70F8: beql        $s2, $zero, L_800A7138
    if (ctx->r18 == 0) {
        // 0x800A70FC: lw          $s3, 0xC($s3)
        ctx->r19 = MEM_W(ctx->r19, 0XC);
            goto L_800A7138;
    }
    goto skip_2;
    // 0x800A70FC: lw          $s3, 0xC($s3)
    ctx->r19 = MEM_W(ctx->r19, 0XC);
    skip_2:
L_800A7100:
    // 0x800A7100: lbu         $s0, 0x5($s4)
    ctx->r16 = MEM_BU(ctx->r20, 0X5);
    // 0x800A7104: beq         $s0, $zero, L_800A7120
    if (ctx->r16 == 0) {
        // 0x800A7108: nop
    
            goto L_800A7120;
    }
    // 0x800A7108: nop

L_800A710C:
    // 0x800A710C: jal         0x800A6E48
    // 0x800A7110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A6E48(rdram, ctx);
        goto after_0;
    // 0x800A7110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800A7114: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800A7118: bne         $s0, $zero, L_800A710C
    if (ctx->r16 != 0) {
        // 0x800A711C: nop
    
            goto L_800A710C;
    }
    // 0x800A711C: nop

L_800A7120:
    // 0x800A7120: jal         0x800A6D08
    // 0x800A7124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A6D08(rdram, ctx);
        goto after_1;
    // 0x800A7124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800A7128: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800A712C: bne         $s2, $zero, L_800A7100
    if (ctx->r18 != 0) {
        // 0x800A7130: addiu       $s1, $s1, 0x24
        ctx->r17 = ADD32(ctx->r17, 0X24);
            goto L_800A7100;
    }
    // 0x800A7130: addiu       $s1, $s1, 0x24
    ctx->r17 = ADD32(ctx->r17, 0X24);
    // 0x800A7134: lw          $s3, 0xC($s3)
    ctx->r19 = MEM_W(ctx->r19, 0XC);
L_800A7138:
    // 0x800A7138: bnel        $s3, $zero, L_800A70F4
    if (ctx->r19 != 0) {
        // 0x800A713C: lw          $s2, 0x24($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X24);
            goto L_800A70F4;
    }
    goto skip_3;
    // 0x800A713C: lw          $s2, 0x24($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X24);
    skip_3:
    // 0x800A7140: lw          $s3, 0x1D0($s4)
    ctx->r19 = MEM_W(ctx->r20, 0X1D0);
L_800A7144:
    // 0x800A7144: beql        $s3, $zero, L_800A71A8
    if (ctx->r19 == 0) {
        // 0x800A7148: lhu         $t7, 0x6($s4)
        ctx->r15 = MEM_HU(ctx->r20, 0X6);
            goto L_800A71A8;
    }
    goto skip_4;
    // 0x800A7148: lhu         $t7, 0x6($s4)
    ctx->r15 = MEM_HU(ctx->r20, 0X6);
    skip_4:
    // 0x800A714C: mtc1        $zero, $f23
    ctx->f_odd[(23 - 1) * 2] = 0;
    // 0x800A7150: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800A7154: nop

    // 0x800A7158: lwc1        $f20, 0x18($s3)
    ctx->f20.u32l = MEM_W(ctx->r19, 0X18);
L_800A715C:
    // 0x800A715C: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x800A7160: c.eq.d      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.d == ctx->f4.d;
    // 0x800A7164: nop

    // 0x800A7168: bc1tl       L_800A719C
    if (c1cs) {
        // 0x800A716C: lw          $s3, 0xC($s3)
        ctx->r19 = MEM_W(ctx->r19, 0XC);
            goto L_800A719C;
    }
    goto skip_5;
    // 0x800A716C: lw          $s3, 0xC($s3)
    ctx->r19 = MEM_W(ctx->r19, 0XC);
    skip_5:
    // 0x800A7170: lw          $s0, 0x24($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X24);
    // 0x800A7174: lw          $s1, 0x28($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X28);
    // 0x800A7178: beql        $s0, $zero, L_800A719C
    if (ctx->r16 == 0) {
        // 0x800A717C: lw          $s3, 0xC($s3)
        ctx->r19 = MEM_W(ctx->r19, 0XC);
            goto L_800A719C;
    }
    goto skip_6;
    // 0x800A717C: lw          $s3, 0xC($s3)
    ctx->r19 = MEM_W(ctx->r19, 0XC);
    skip_6:
L_800A7180:
    // 0x800A7180: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800A7184: jal         0x800A6B14
    // 0x800A7188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A6B14(rdram, ctx);
        goto after_2;
    // 0x800A7188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800A718C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800A7190: bne         $s0, $zero, L_800A7180
    if (ctx->r16 != 0) {
        // 0x800A7194: addiu       $s1, $s1, 0x24
        ctx->r17 = ADD32(ctx->r17, 0X24);
            goto L_800A7180;
    }
    // 0x800A7194: addiu       $s1, $s1, 0x24
    ctx->r17 = ADD32(ctx->r17, 0X24);
    // 0x800A7198: lw          $s3, 0xC($s3)
    ctx->r19 = MEM_W(ctx->r19, 0XC);
L_800A719C:
    // 0x800A719C: bnel        $s3, $zero, L_800A715C
    if (ctx->r19 != 0) {
        // 0x800A71A0: lwc1        $f20, 0x18($s3)
        ctx->f20.u32l = MEM_W(ctx->r19, 0X18);
            goto L_800A715C;
    }
    goto skip_7;
    // 0x800A71A0: lwc1        $f20, 0x18($s3)
    ctx->f20.u32l = MEM_W(ctx->r19, 0X18);
    skip_7:
    // 0x800A71A4: lhu         $t7, 0x6($s4)
    ctx->r15 = MEM_HU(ctx->r20, 0X6);
L_800A71A8:
    // 0x800A71A8: lbu         $t8, 0x5($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X5);
    // 0x800A71AC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A71B0: sh          $t9, 0x6($s4)
    MEM_H(0X6, ctx->r20) = ctx->r25;
    // 0x800A71B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800A71B8:
    // 0x800A71B8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800A71BC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800A71C0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800A71C4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800A71C8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800A71CC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800A71D0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800A71D4: jr          $ra
    // 0x800A71D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800A71D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void func_800A71DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A71DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A71E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A71E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A71E8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800A71EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A71F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A71F4: lw          $s2, 0x24($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X24);
    // 0x800A71F8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800A71FC: lw          $s1, 0x28($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X28);
    // 0x800A7200: beql        $s2, $zero, L_800A7234
    if (ctx->r18 == 0) {
        // 0x800A7204: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A7234;
    }
    goto skip_0;
    // 0x800A7204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_800A7208:
    // 0x800A7208: beq         $s3, $zero, L_800A7224
    if (ctx->r19 == 0) {
        // 0x800A720C: or          $s0, $s3, $zero
        ctx->r16 = ctx->r19 | 0;
            goto L_800A7224;
    }
    // 0x800A720C: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
L_800A7210:
    // 0x800A7210: jal         0x800A6E48
    // 0x800A7214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A6E48(rdram, ctx);
        goto after_0;
    // 0x800A7214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800A7218: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800A721C: bne         $s0, $zero, L_800A7210
    if (ctx->r16 != 0) {
        // 0x800A7220: nop
    
            goto L_800A7210;
    }
    // 0x800A7220: nop

L_800A7224:
    // 0x800A7224: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800A7228: bne         $s2, $zero, L_800A7208
    if (ctx->r18 != 0) {
        // 0x800A722C: nop
    
            goto L_800A7208;
    }
    // 0x800A722C: nop

    // 0x800A7230: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A7234:
    // 0x800A7234: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A7238: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A723C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7240: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800A7244: jr          $ra
    // 0x800A7248: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A7248: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800A724C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A724C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7254: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A7258: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A725C: jal         0x800A70A8
    // 0x800A7260: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800A70A8(rdram, ctx);
        goto after_0;
    // 0x800A7260: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800A7264: jal         0x800A58A4
    // 0x800A7268: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800A58A4(rdram, ctx);
        goto after_1;
    // 0x800A7268: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800A726C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A7270: jal         0x800A7EFC
    // 0x800A7274: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800A7EFC(rdram, ctx);
        goto after_2;
    // 0x800A7274: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800A7278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A727C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7280: jr          $ra
    // 0x800A7284: nop

    return;
    // 0x800A7284: nop

;}

RECOMP_FUNC void func_800A7288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A728C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7290: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A7294: sw          $a0, -0x6C10($at)
    MEM_W(-0X6C10, ctx->r1) = ctx->r4;
    // 0x800A7298: jal         0x800A70A8
    // 0x800A729C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A70A8(rdram, ctx);
        goto after_0;
    // 0x800A729C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A72A0: jal         0x800A58A4
    // 0x800A72A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A58A4(rdram, ctx);
        goto after_1;
    // 0x800A72A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A72A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A72AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A72B0: jr          $ra
    // 0x800A72B4: nop

    return;
    // 0x800A72B4: nop

;}

RECOMP_FUNC void func_800A72B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A72B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A72BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A72C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A72C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A72C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A72CC: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800A72D0: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800A72D4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800A72D8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800A72DC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A72E0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800A72E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A72E8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800A72EC: jal         0x800B3BFC
    // 0x800A72F0: addiu       $a0, $a0, 0x9B8
    ctx->r4 = ADD32(ctx->r4, 0X9B8);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A72F0: addiu       $a0, $a0, 0x9B8
    ctx->r4 = ADD32(ctx->r4, 0X9B8);
    after_0:
    // 0x800A72F4: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800A72F8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800A72FC: addiu       $s2, $s2, 0x9BC
    ctx->r18 = ADD32(ctx->r18, 0X9BC);
    // 0x800A7300: addiu       $s6, $s6, 0x9C4
    ctx->r22 = ADD32(ctx->r22, 0X9C4);
    // 0x800A7304: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800A7308: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x800A730C: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x800A7310: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
L_800A7314:
    // 0x800A7314: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A7318: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
L_800A731C:
    // 0x800A731C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A7320: jal         0x800B3BFC
    // 0x800A7324: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A7324: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x800A7328: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A732C: bne         $s0, $s3, L_800A731C
    if (ctx->r16 != ctx->r19) {
        // 0x800A7330: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800A731C;
    }
    // 0x800A7330: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800A7334: jal         0x800B3BFC
    // 0x800A7338: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800A7338: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x800A733C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800A7340: bne         $s4, $s7, L_800A7314
    if (ctx->r20 != ctx->r23) {
        // 0x800A7344: addiu       $s5, $s5, 0x10
        ctx->r21 = ADD32(ctx->r21, 0X10);
            goto L_800A7314;
    }
    // 0x800A7344: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x800A7348: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A734C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A7350: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A7354: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7358: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800A735C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800A7360: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800A7364: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800A7368: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800A736C: jr          $ra
    // 0x800A7370: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800A7370: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void func_800A7374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7374: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800A7378: addiu       $t0, $t0, -0x6C10
    ctx->r8 = ADD32(ctx->r8, -0X6C10);
    // 0x800A737C: lui         $t6, 0x22
    ctx->r14 = S32(0X22 << 16);
    // 0x800A7380: lui         $t7, 0xD
    ctx->r15 = S32(0XD << 16);
    // 0x800A7384: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A7388: ori         $t6, $t6, 0x405
    ctx->r14 = ctx->r14 | 0X405;
    // 0x800A738C: lui         $t8, 0x44
    ctx->r24 = S32(0X44 << 16);
    // 0x800A7390: lui         $t9, 0x11
    ctx->r25 = S32(0X11 << 16);
    // 0x800A7394: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A7398: nor         $t3, $t7, $zero
    ctx->r11 = ~(ctx->r15 | 0);
    // 0x800A739C: sw          $t6, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r14;
    // 0x800A73A0: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x800A73A4: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x800A73A8: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x800A73AC: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800A73B0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A73B4: sw          $t7, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r15;
    // 0x800A73B8: sw          $zero, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = 0;
    // 0x800A73BC: sb          $zero, 0x48($t0)
    MEM_B(0X48, ctx->r8) = 0;
    // 0x800A73C0: sb          $zero, 0x49($t0)
    MEM_B(0X49, ctx->r8) = 0;
    // 0x800A73C4: sb          $zero, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = 0;
    // 0x800A73C8: sb          $zero, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = 0;
    // 0x800A73CC: sw          $t8, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->r24;
    // 0x800A73D0: sw          $t9, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r25;
    // 0x800A73D4: sw          $t1, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r9;
    // 0x800A73D8: lui         $at, 0xD900
    ctx->r1 = S32(0XD900 << 16);
    // 0x800A73DC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800A73E0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A73E4: lui         $t6, 0xD9FF
    ctx->r14 = S32(0XD9FF << 16);
    // 0x800A73E8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800A73EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A73F0: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800A73F4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800A73F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800A73FC: lw          $t7, 0x3C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X3C);
    // 0x800A7400: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A7404: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800A7408: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x800A740C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A7410: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800A7414: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800A7418: lw          $t9, 0x4C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4C);
    // 0x800A741C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A7420: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A7424: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800A7428: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800A742C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x800A7430: lbu         $t6, 0x49($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X49);
    // 0x800A7434: lbu         $t3, 0x48($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X48);
    // 0x800A7438: lbu         $t1, 0x4A($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4A);
    // 0x800A743C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800A7440: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x800A7444: lbu         $t6, 0x4B($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X4B);
    // 0x800A7448: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800A744C: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800A7450: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x800A7454: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A7458: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x800A745C: or          $t4, $t3, $t6
    ctx->r12 = ctx->r11 | ctx->r14;
    // 0x800A7460: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x800A7464: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x800A7468: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A746C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800A7470: lw          $t1, 0x54($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X54);
    // 0x800A7474: lw          $t9, 0x50($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X50);
    // 0x800A7478: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A747C: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x800A7480: or          $t8, $t9, $t1
    ctx->r24 = ctx->r25 | ctx->r9;
    // 0x800A7484: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800A7488: ori         $t2, $t2, 0x1201
    ctx->r10 = ctx->r10 | 0X1201;
    // 0x800A748C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800A7490: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800A7494: lw          $t5, 0x44($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X44);
    // 0x800A7498: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800A749C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A74A0: addiu       $t3, $t3, -0x6C70
    ctx->r11 = ADD32(ctx->r11, -0X6C70);
    // 0x800A74A4: or          $t7, $t0, $zero
    ctx->r15 = ctx->r8 | 0;
    // 0x800A74A8: addiu       $t4, $t0, 0x60
    ctx->r12 = ADD32(ctx->r8, 0X60);
    // 0x800A74AC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
L_800A74B0:
    // 0x800A74B0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800A74B4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800A74B8: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800A74BC: sw          $at, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r1;
    // 0x800A74C0: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x800A74C4: sw          $at, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r1;
    // 0x800A74C8: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x800A74CC: bne         $t7, $t4, L_800A74B0
    if (ctx->r15 != ctx->r12) {
        // 0x800A74D0: sw          $at, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r1;
            goto L_800A74B0;
    }
    // 0x800A74D0: sw          $at, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r1;
    // 0x800A74D4: jr          $ra
    // 0x800A74D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800A74D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}

RECOMP_FUNC void func_800A74DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A74DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800A74E0: addiu       $v1, $v1, -0x6C10
    ctx->r3 = ADD32(ctx->r3, -0X6C10);
    // 0x800A74E4: lw          $t6, 0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14);
    // 0x800A74E8: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x800A74EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A74F0: lwl         $a2, 0x0($t6)
    ctx->r6 = do_lwl(rdram, ctx->r6, ctx->r14, 0X0);
    // 0x800A74F4: beq         $v0, $zero, L_800A75A0
    if (ctx->r2 == 0) {
        // 0x800A74F8: lwr         $a2, 0x3($t6)
        ctx->r6 = do_lwr(rdram, ctx->r6, ctx->r14, 0X3);
            goto L_800A75A0;
    }
    // 0x800A74F8: lwr         $a2, 0x3($t6)
    ctx->r6 = do_lwr(rdram, ctx->r6, ctx->r14, 0X3);
    // 0x800A74FC: andi        $t7, $a2, 0x1
    ctx->r15 = ctx->r6 & 0X1;
    // 0x800A7500: beq         $t7, $zero, L_800A7550
    if (ctx->r15 == 0) {
        // 0x800A7504: lui         $at, 0xD700
        ctx->r1 = S32(0XD700 << 16);
            goto L_800A7550;
    }
    // 0x800A7504: lui         $at, 0xD700
    ctx->r1 = S32(0XD700 << 16);
    // 0x800A7508: lbu         $t8, 0xF($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XF);
    // 0x800A750C: lui         $at, 0xD700
    ctx->r1 = S32(0XD700 << 16);
    // 0x800A7510: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A7514: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x800A7518: sll         $t6, $t9, 11
    ctx->r14 = S32(ctx->r25 << 11);
    // 0x800A751C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800A7520: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x800A7524: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800A7528: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x800A752C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A7530: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x800A7534: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    // 0x800A7538: sll         $t8, $t7, 22
    ctx->r24 = S32(ctx->r15 << 22);
    // 0x800A753C: sll         $t6, $t9, 6
    ctx->r14 = S32(ctx->r25 << 6);
    // 0x800A7540: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800A7544: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800A7548: b           L_800A75A0
    // 0x800A754C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
        goto L_800A75A0;
    // 0x800A754C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
L_800A7550:
    // 0x800A7550: lbu         $t6, 0xE($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XE);
    // 0x800A7554: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x800A7558: beql        $t8, $zero, L_800A7578
    if (ctx->r24 == 0) {
        // 0x800A755C: lbu         $a1, 0xF($v0)
        ctx->r5 = MEM_BU(ctx->r2, 0XF);
            goto L_800A7578;
    }
    goto skip_0;
    // 0x800A755C: lbu         $a1, 0xF($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XF);
    skip_0:
    // 0x800A7560: lbu         $a1, 0xF($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XF);
    // 0x800A7564: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800A7568: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x800A756C: b           L_800A7578
    // 0x800A7570: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_800A7578;
    // 0x800A7570: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800A7574: lbu         $a1, 0xF($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XF);
L_800A7578:
    // 0x800A7578: andi        $t9, $a1, 0x7
    ctx->r25 = ctx->r5 & 0X7;
    // 0x800A757C: sll         $t6, $t9, 11
    ctx->r14 = S32(ctx->r25 << 11);
    // 0x800A7580: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A7584: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800A7588: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800A758C: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x800A7590: ori         $t7, $t8, 0x2
    ctx->r15 = ctx->r24 | 0X2;
    // 0x800A7594: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800A7598: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A759C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800A75A0:
    // 0x800A75A0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A75A4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800A75A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A75AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A75B0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800A75B4: andi        $t2, $a2, 0x200
    ctx->r10 = ctx->r6 & 0X200;
    // 0x800A75B8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A75BC: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
    // 0x800A75C0: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
    // 0x800A75C4: beq         $t2, $zero, L_800A75D8
    if (ctx->r10 == 0) {
        // 0x800A75C8: andi        $t1, $a2, 0x1
        ctx->r9 = ctx->r6 & 0X1;
            goto L_800A75D8;
    }
    // 0x800A75C8: andi        $t1, $a2, 0x1
    ctx->r9 = ctx->r6 & 0X1;
    // 0x800A75CC: ori         $t9, $zero, 0x1
    ctx->r25 = 0 | 0X1;
    // 0x800A75D0: b           L_800A75E4
    // 0x800A75D4: sw          $t9, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r25;
        goto L_800A75E4;
    // 0x800A75D4: sw          $t9, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r25;
L_800A75D8:
    // 0x800A75D8: lw          $t6, 0x3C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X3C);
    // 0x800A75DC: ori         $t8, $t6, 0x1
    ctx->r24 = ctx->r14 | 0X1;
    // 0x800A75E0: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
L_800A75E4:
    // 0x800A75E4: andi        $t7, $a2, 0x10
    ctx->r15 = ctx->r6 & 0X10;
    // 0x800A75E8: beql        $t7, $zero, L_800A7608
    if (ctx->r15 == 0) {
        // 0x800A75EC: lw          $t8, 0x40($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X40);
            goto L_800A7608;
    }
    goto skip_1;
    // 0x800A75EC: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
    skip_1:
    // 0x800A75F0: lw          $t9, 0x3C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X3C);
    // 0x800A75F4: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x800A75F8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800A75FC: b           L_800A7614
    // 0x800A7600: sw          $t6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r14;
        goto L_800A7614;
    // 0x800A7600: sw          $t6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r14;
    // 0x800A7604: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
L_800A7608:
    // 0x800A7608: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x800A760C: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800A7610: sw          $t7, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r15;
L_800A7614:
    // 0x800A7614: andi        $t9, $a2, 0x4
    ctx->r25 = ctx->r6 & 0X4;
    // 0x800A7618: beql        $t9, $zero, L_800A7634
    if (ctx->r25 == 0) {
        // 0x800A761C: lw          $t7, 0x40($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X40);
            goto L_800A7634;
    }
    goto skip_2;
    // 0x800A761C: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    skip_2:
    // 0x800A7620: lw          $t6, 0x3C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X3C);
    // 0x800A7624: ori         $t8, $t6, 0x400
    ctx->r24 = ctx->r14 | 0X400;
    // 0x800A7628: b           L_800A763C
    // 0x800A762C: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
        goto L_800A763C;
    // 0x800A762C: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
    // 0x800A7630: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
L_800A7634:
    // 0x800A7634: ori         $t9, $t7, 0x400
    ctx->r25 = ctx->r15 | 0X400;
    // 0x800A7638: sw          $t9, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r25;
L_800A763C:
    // 0x800A763C: andi        $t6, $a2, 0x8
    ctx->r14 = ctx->r6 & 0X8;
    // 0x800A7640: beql        $t6, $zero, L_800A7660
    if (ctx->r14 == 0) {
        // 0x800A7644: lw          $t9, 0x3C($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X3C);
            goto L_800A7660;
    }
    goto skip_3;
    // 0x800A7644: lw          $t9, 0x3C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X3C);
    skip_3:
    // 0x800A7648: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
    // 0x800A764C: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800A7650: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800A7654: b           L_800A766C
    // 0x800A7658: sw          $t7, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r15;
        goto L_800A766C;
    // 0x800A7658: sw          $t7, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r15;
    // 0x800A765C: lw          $t9, 0x3C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X3C);
L_800A7660:
    // 0x800A7660: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800A7664: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800A7668: sw          $t6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r14;
L_800A766C:
    // 0x800A766C: beql        $t1, $zero, L_800A76B4
    if (ctx->r9 == 0) {
        // 0x800A7670: lw          $t6, 0x40($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X40);
            goto L_800A76B4;
    }
    goto skip_4;
    // 0x800A7670: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    skip_4:
    // 0x800A7674: lw          $t8, 0x3C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X3C);
    // 0x800A7678: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x800A767C: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
    // 0x800A7680: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800A7684: beq         $t9, $zero, L_800A769C
    if (ctx->r25 == 0) {
        // 0x800A7688: sw          $t7, 0x3C($v1)
        MEM_W(0X3C, ctx->r3) = ctx->r15;
            goto L_800A769C;
    }
    // 0x800A7688: sw          $t7, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r15;
    // 0x800A768C: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x800A7690: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800A7694: b           L_800A76C0
    // 0x800A7698: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
        goto L_800A76C0;
    // 0x800A7698: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
L_800A769C:
    // 0x800A769C: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x800A76A0: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x800A76A4: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800A76A8: b           L_800A76C0
    // 0x800A76AC: sw          $t9, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r25;
        goto L_800A76C0;
    // 0x800A76AC: sw          $t9, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r25;
    // 0x800A76B0: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
L_800A76B4:
    // 0x800A76B4: lui         $at, 0xC
    ctx->r1 = S32(0XC << 16);
    // 0x800A76B8: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800A76BC: sw          $t8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r24;
L_800A76C0:
    // 0x800A76C0: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x800A76C4: lw          $v0, 0x20($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X20);
    // 0x800A76C8: beq         $v0, $zero, L_800A7898
    if (ctx->r2 == 0) {
        // 0x800A76CC: andi        $t9, $a2, 0x400
        ctx->r25 = ctx->r6 & 0X400;
            goto L_800A7898;
    }
    // 0x800A76CC: andi        $t9, $a2, 0x400
    ctx->r25 = ctx->r6 & 0X400;
    // 0x800A76D0: bne         $t9, $zero, L_800A7898
    if (ctx->r25 != 0) {
        // 0x800A76D4: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_800A7898;
    }
    // 0x800A76D4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A76D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A76DC: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A76E0: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800A76E4: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800A76E8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A76EC: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800A76F0: lui         $t6, 0xF800
    ctx->r14 = S32(0XF800 << 16);
    // 0x800A76F4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800A76F8: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800A76FC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800A7700: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A7704: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800A7708: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A770C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800A7710: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800A7714: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800A7718: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A771C: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800A7720: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800A7724: bgezl       $a1, L_800A7734
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800A7728: slti        $at, $a1, 0x100
        ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
            goto L_800A7734;
    }
    goto skip_5;
    // 0x800A7728: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    skip_5:
    // 0x800A772C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A7730: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
L_800A7734:
    // 0x800A7734: bne         $at, $zero, L_800A7740
    if (ctx->r1 != 0) {
        // 0x800A7738: nop
    
            goto L_800A7740;
    }
    // 0x800A7738: nop

    // 0x800A773C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_800A7740:
    // 0x800A7740: bgez        $a3, L_800A774C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800A7744: sll         $t7, $a1, 24
        ctx->r15 = S32(ctx->r5 << 24);
            goto L_800A774C;
    }
    // 0x800A7744: sll         $t7, $a1, 24
    ctx->r15 = S32(ctx->r5 << 24);
    // 0x800A7748: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800A774C:
    // 0x800A774C: slti        $at, $a3, 0x100
    ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
    // 0x800A7750: bne         $at, $zero, L_800A775C
    if (ctx->r1 != 0) {
        // 0x800A7754: nop
    
            goto L_800A775C;
    }
    // 0x800A7754: nop

    // 0x800A7758: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_800A775C:
    // 0x800A775C: bgez        $t3, L_800A7768
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A7760: andi        $t9, $a3, 0xFF
        ctx->r25 = ctx->r7 & 0XFF;
            goto L_800A7768;
    }
    // 0x800A7760: andi        $t9, $a3, 0xFF
    ctx->r25 = ctx->r7 & 0XFF;
    // 0x800A7764: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800A7768:
    // 0x800A7768: slti        $at, $t3, 0x100
    ctx->r1 = SIGNED(ctx->r11) < 0X100 ? 1 : 0;
    // 0x800A776C: bne         $at, $zero, L_800A7778
    if (ctx->r1 != 0) {
        // 0x800A7770: nop
    
            goto L_800A7778;
    }
    // 0x800A7770: nop

    // 0x800A7774: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800A7778:
    // 0x800A7778: bgezl       $t4, L_800A7788
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800A777C: slti        $at, $t4, 0x100
        ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
            goto L_800A7788;
    }
    goto skip_6;
    // 0x800A777C: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    skip_6:
    // 0x800A7780: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800A7784: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
L_800A7788:
    // 0x800A7788: bnel        $at, $zero, L_800A7798
    if (ctx->r1 != 0) {
        // 0x800A778C: sw          $t6, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r14;
            goto L_800A7798;
    }
    goto skip_7;
    // 0x800A778C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    skip_7:
    // 0x800A7790: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A7794: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_800A7798:
    // 0x800A7798: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800A779C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800A77A0: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x800A77A4: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x800A77A8: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800A77AC: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x800A77B0: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800A77B4: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800A77B8: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x800A77BC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A77C0: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x800A77C4: lw          $v0, 0x20($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X20);
    // 0x800A77C8: lui         $t6, 0xDB08
    ctx->r14 = S32(0XDB08 << 16);
    // 0x800A77CC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A77D0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A77D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A77D8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A77DC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A77E0: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800A77E4: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800A77E8: nop

    // 0x800A77EC: beq         $t5, $t7, L_800A7884
    if (ctx->r13 == ctx->r15) {
        // 0x800A77F0: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800A7884;
    }
    // 0x800A77F0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800A77F4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A77F8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800A77FC: ori         $t8, $t8, 0xF400
    ctx->r24 = ctx->r24 | 0XF400;
    // 0x800A7800: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A7804: subu        $a1, $t9, $t5
    ctx->r5 = SUB32(ctx->r25, ctx->r13);
    // 0x800A7808: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x800A780C: bne         $a1, $zero, L_800A7818
    if (ctx->r5 != 0) {
        // 0x800A7810: nop
    
            goto L_800A7818;
    }
    // 0x800A7810: nop

    // 0x800A7814: break       7
    do_break(2148169748);
L_800A7818:
    // 0x800A7818: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A781C: bne         $a1, $at, L_800A7830
    if (ctx->r5 != ctx->r1) {
        // 0x800A7820: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A7830;
    }
    // 0x800A7820: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A7824: bne         $t8, $at, L_800A7830
    if (ctx->r24 != ctx->r1) {
        // 0x800A7828: nop
    
            goto L_800A7830;
    }
    // 0x800A7828: nop

    // 0x800A782C: break       6
    do_break(2148169772);
L_800A7830:
    // 0x800A7830: mflo        $t6
    ctx->r14 = lo;
    // 0x800A7834: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800A7838: negu        $t8, $t5
    ctx->r24 = SUB32(0, ctx->r13);
    // 0x800A783C: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x800A7840: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800A7844: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x800A7848: addu        $t6, $t7, $at
    ctx->r14 = ADD32(ctx->r15, ctx->r1);
    // 0x800A784C: div         $zero, $t6, $a1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r5)));
    // 0x800A7850: mflo        $t8
    ctx->r24 = lo;
    // 0x800A7854: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x800A7858: bne         $a1, $zero, L_800A7864
    if (ctx->r5 != 0) {
        // 0x800A785C: nop
    
            goto L_800A7864;
    }
    // 0x800A785C: nop

    // 0x800A7860: break       7
    do_break(2148169824);
L_800A7864:
    // 0x800A7864: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7868: bne         $a1, $at, L_800A787C
    if (ctx->r5 != ctx->r1) {
        // 0x800A786C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A787C;
    }
    // 0x800A786C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A7870: bne         $t6, $at, L_800A787C
    if (ctx->r14 != ctx->r1) {
        // 0x800A7874: nop
    
            goto L_800A787C;
    }
    // 0x800A7874: nop

    // 0x800A7878: break       6
    do_break(2148169848);
L_800A787C:
    // 0x800A787C: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x800A7880: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800A7884:
    // 0x800A7884: lw          $t8, 0x3C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X3C);
    // 0x800A7888: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800A788C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800A7890: b           L_800A78B0
    // 0x800A7894: sw          $t9, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r25;
        goto L_800A78B0;
    // 0x800A7894: sw          $t9, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r25;
L_800A7898:
    // 0x800A7898: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x800A789C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800A78A0: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800A78A4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A78A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A78AC: sw          $t6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r14;
L_800A78B0:
    // 0x800A78B0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800A78B4: addiu       $t0, $t0, -0x6C70
    ctx->r8 = ADD32(ctx->r8, -0X6C70);
    // 0x800A78B8: lw          $t8, 0x40($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X40);
    // 0x800A78BC: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    // 0x800A78C0: beq         $v0, $t8, L_800A78EC
    if (ctx->r2 == ctx->r24) {
        // 0x800A78C4: lui         $at, 0xFF
        ctx->r1 = S32(0XFF << 16);
            goto L_800A78EC;
    }
    // 0x800A78C4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A78C8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A78CC: nor         $t9, $v0, $zero
    ctx->r25 = ~(ctx->r2 | 0);
    // 0x800A78D0: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800A78D4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A78D8: lui         $at, 0xD900
    ctx->r1 = S32(0XD900 << 16);
    // 0x800A78DC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800A78E0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800A78E4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800A78E8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800A78EC:
    // 0x800A78EC: lw          $t8, 0x3C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X3C);
    // 0x800A78F0: lw          $t9, 0x3C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X3C);
    // 0x800A78F4: beq         $t8, $t9, L_800A7914
    if (ctx->r24 == ctx->r25) {
        // 0x800A78F8: lui         $t7, 0xD9FF
        ctx->r15 = S32(0XD9FF << 16);
            goto L_800A7914;
    }
    // 0x800A78F8: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x800A78FC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800A7900: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A7904: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800A7908: lw          $t6, 0x3C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X3C);
    // 0x800A790C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A7910: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800A7914:
    // 0x800A7914: andi        $t8, $a2, 0x80
    ctx->r24 = ctx->r6 & 0X80;
    // 0x800A7918: beql        $t8, $zero, L_800A792C
    if (ctx->r24 == 0) {
        // 0x800A791C: addiu       $t9, $zero, 0x2000
        ctx->r25 = ADD32(0, 0X2000);
            goto L_800A792C;
    }
    goto skip_8;
    // 0x800A791C: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    skip_8:
    // 0x800A7920: b           L_800A7930
    // 0x800A7924: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
        goto L_800A7930;
    // 0x800A7924: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x800A7928: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
L_800A792C:
    // 0x800A792C: sw          $t9, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r25;
L_800A7930:
    // 0x800A7930: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x800A7934: lw          $t6, 0x44($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X44);
    // 0x800A7938: beq         $t7, $t6, L_800A7958
    if (ctx->r15 == ctx->r14) {
        // 0x800A793C: lui         $t8, 0xE300
        ctx->r24 = S32(0XE300 << 16);
            goto L_800A7958;
    }
    // 0x800A793C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800A7940: ori         $t8, $t8, 0x1201
    ctx->r24 = ctx->r24 | 0X1201;
    // 0x800A7944: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A7948: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A794C: lw          $t9, 0x44($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X44);
    // 0x800A7950: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A7954: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800A7958:
    // 0x800A7958: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x800A795C: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800A7960: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A7964: lwl         $t7, 0x4($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X4);
    // 0x800A7968: lwr         $t7, 0x7($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X7);
    // 0x800A796C: lwl         $t8, 0x8($v0)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r2, 0X8);
    // 0x800A7970: lwr         $t8, 0xB($v0)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r2, 0XB);
    // 0x800A7974: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800A7978: lwl         $t7, 0xC($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0XC);
    // 0x800A797C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800A7980: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800A7984: lwr         $t7, 0xF($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0XF);
    // 0x800A7988: lwl         $t8, 0x10($v0)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r2, 0X10);
    // 0x800A798C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A7990: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800A7994: lwr         $t8, 0x13($v0)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r2, 0X13);
    // 0x800A7998: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A799C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800A79A0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800A79A4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800A79A8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800A79AC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A79B0: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800A79B4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800A79B8: lwc1        $f10, 0x10($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800A79BC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800A79C0: sub.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800A79C4: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800A79C8: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A79CC: nop

    // 0x800A79D0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800A79D4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A79D8: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800A79DC: bgez        $a1, L_800A79E8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800A79E0: nop
    
            goto L_800A79E8;
    }
    // 0x800A79E0: nop

    // 0x800A79E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800A79E8:
    // 0x800A79E8: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x800A79EC: bne         $at, $zero, L_800A79F8
    if (ctx->r1 != 0) {
        // 0x800A79F0: nop
    
            goto L_800A79F8;
    }
    // 0x800A79F0: nop

    // 0x800A79F4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_800A79F8:
    // 0x800A79F8: bgez        $a3, L_800A7A04
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800A79FC: andi        $t8, $a1, 0xFF
        ctx->r24 = ctx->r5 & 0XFF;
            goto L_800A7A04;
    }
    // 0x800A79FC: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x800A7A00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800A7A04:
    // 0x800A7A04: slti        $at, $a3, 0x100
    ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
    // 0x800A7A08: bne         $at, $zero, L_800A7A14
    if (ctx->r1 != 0) {
        // 0x800A7A0C: nop
    
            goto L_800A7A14;
    }
    // 0x800A7A0C: nop

    // 0x800A7A10: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_800A7A14:
    // 0x800A7A14: bgezl       $t3, L_800A7A24
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A7A18: slti        $at, $t3, 0x100
        ctx->r1 = SIGNED(ctx->r11) < 0X100 ? 1 : 0;
            goto L_800A7A24;
    }
    goto skip_9;
    // 0x800A7A18: slti        $at, $t3, 0x100
    ctx->r1 = SIGNED(ctx->r11) < 0X100 ? 1 : 0;
    skip_9:
    // 0x800A7A1C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800A7A20: slti        $at, $t3, 0x100
    ctx->r1 = SIGNED(ctx->r11) < 0X100 ? 1 : 0;
L_800A7A24:
    // 0x800A7A24: bne         $at, $zero, L_800A7A30
    if (ctx->r1 != 0) {
        // 0x800A7A28: addiu       $sp, $sp, 0x30
        ctx->r29 = ADD32(ctx->r29, 0X30);
            goto L_800A7A30;
    }
    // 0x800A7A28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A7A2C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800A7A30:
    // 0x800A7A30: bgezl       $t4, L_800A7A40
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800A7A34: slti        $at, $t4, 0x100
        ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
            goto L_800A7A40;
    }
    goto skip_10;
    // 0x800A7A34: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    skip_10:
    // 0x800A7A38: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800A7A3C: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
L_800A7A40:
    // 0x800A7A40: bnel        $at, $zero, L_800A7A50
    if (ctx->r1 != 0) {
        // 0x800A7A44: lbu         $t6, 0x48($t0)
        ctx->r14 = MEM_BU(ctx->r8, 0X48);
            goto L_800A7A50;
    }
    goto skip_11;
    // 0x800A7A44: lbu         $t6, 0x48($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X48);
    skip_11:
    // 0x800A7A48: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A7A4C: lbu         $t6, 0x48($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X48);
L_800A7A50:
    // 0x800A7A50: sb          $a1, 0x48($v1)
    MEM_B(0X48, ctx->r3) = ctx->r5;
    // 0x800A7A54: sb          $a3, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r7;
    // 0x800A7A58: sb          $t3, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r11;
    // 0x800A7A5C: bne         $t6, $t8, L_800A7A90
    if (ctx->r14 != ctx->r24) {
        // 0x800A7A60: sb          $t4, 0x4B($v1)
        MEM_B(0X4B, ctx->r3) = ctx->r12;
            goto L_800A7A90;
    }
    // 0x800A7A60: sb          $t4, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r12;
    // 0x800A7A64: lbu         $t9, 0x49($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X49);
    // 0x800A7A68: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x800A7A6C: bnel        $t9, $t7, L_800A7A94
    if (ctx->r25 != ctx->r15) {
        // 0x800A7A70: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800A7A94;
    }
    goto skip_12;
    // 0x800A7A70: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    skip_12:
    // 0x800A7A74: lbu         $t6, 0x4A($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X4A);
    // 0x800A7A78: andi        $t8, $t3, 0xFF
    ctx->r24 = ctx->r11 & 0XFF;
    // 0x800A7A7C: bnel        $t6, $t8, L_800A7A94
    if (ctx->r14 != ctx->r24) {
        // 0x800A7A80: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800A7A94;
    }
    goto skip_13;
    // 0x800A7A80: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    skip_13:
    // 0x800A7A84: lbu         $t9, 0x4B($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X4B);
    // 0x800A7A88: andi        $v0, $t4, 0xFF
    ctx->r2 = ctx->r12 & 0XFF;
    // 0x800A7A8C: beq         $t9, $v0, L_800A7AD0
    if (ctx->r25 == ctx->r2) {
        // 0x800A7A90: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800A7AD0;
    }
L_800A7A90:
    // 0x800A7A90: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_800A7A94:
    // 0x800A7A94: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800A7A98: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800A7A9C: lbu         $t8, 0x48($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X48);
    // 0x800A7AA0: lbu         $t6, 0x49($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X49);
    // 0x800A7AA4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A7AA8: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800A7AAC: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800A7AB0: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x800A7AB4: lbu         $t9, 0x4A($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4A);
    // 0x800A7AB8: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x800A7ABC: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800A7AC0: lbu         $t7, 0x4B($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4B);
    // 0x800A7AC4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800A7AC8: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800A7ACC: lbu         $v0, 0x4B($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4B);
L_800A7AD0:
    // 0x800A7AD0: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x800A7AD4: beq         $at, $zero, L_800A7B20
    if (ctx->r1 == 0) {
        // 0x800A7AD8: lw          $a3, 0x4($v1)
        ctx->r7 = MEM_W(ctx->r3, 0X4);
            goto L_800A7B20;
    }
    // 0x800A7AD8: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x800A7ADC: andi        $a1, $a2, 0x100
    ctx->r5 = ctx->r6 & 0X100;
    // 0x800A7AE0: beq         $a1, $zero, L_800A7B04
    if (ctx->r5 == 0) {
        // 0x800A7AE4: lui         $t7, 0x40
        ctx->r15 = S32(0X40 << 16);
            goto L_800A7B04;
    }
    // 0x800A7AE4: lui         $t7, 0x40
    ctx->r15 = S32(0X40 << 16);
    // 0x800A7AE8: lui         $t9, 0x40
    ctx->r25 = S32(0X40 << 16);
    // 0x800A7AEC: lui         $t6, 0x10
    ctx->r14 = S32(0X10 << 16);
    // 0x800A7AF0: ori         $t9, $t9, 0x4DD8
    ctx->r25 = ctx->r25 | 0X4DD8;
    // 0x800A7AF4: ori         $t6, $t6, 0x4DD8
    ctx->r14 = ctx->r14 | 0X4DD8;
    // 0x800A7AF8: sw          $t9, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r25;
    // 0x800A7AFC: b           L_800A7B18
    // 0x800A7B00: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
        goto L_800A7B18;
    // 0x800A7B00: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
L_800A7B04:
    // 0x800A7B04: lui         $t8, 0x10
    ctx->r24 = S32(0X10 << 16);
    // 0x800A7B08: ori         $t7, $t7, 0x49F8
    ctx->r15 = ctx->r15 | 0X49F8;
    // 0x800A7B0C: ori         $t8, $t8, 0x49F8
    ctx->r24 = ctx->r24 | 0X49F8;
    // 0x800A7B10: sw          $t7, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r15;
    // 0x800A7B14: sw          $t8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r24;
L_800A7B18:
    // 0x800A7B18: b           L_800A7C30
    // 0x800A7B1C: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
        goto L_800A7C30;
    // 0x800A7B1C: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
L_800A7B20:
    // 0x800A7B20: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x800A7B24: andi        $a1, $a2, 0x100
    ctx->r5 = ctx->r6 & 0X100;
    // 0x800A7B28: beq         $v0, $zero, L_800A7BF8
    if (ctx->r2 == 0) {
        // 0x800A7B2C: nop
    
            goto L_800A7BF8;
    }
    // 0x800A7B2C: nop

    // 0x800A7B30: lbu         $t9, 0xE($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XE);
    // 0x800A7B34: lh          $t3, 0x8($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X8);
    // 0x800A7B38: andi        $a1, $a2, 0x100
    ctx->r5 = ctx->r6 & 0X100;
    // 0x800A7B3C: andi        $t6, $t9, 0x20
    ctx->r14 = ctx->r25 & 0X20;
    // 0x800A7B40: beq         $t6, $zero, L_800A7BBC
    if (ctx->r14 == 0) {
        // 0x800A7B44: nop
    
            goto L_800A7BBC;
    }
    // 0x800A7B44: nop

    // 0x800A7B48: andi        $a1, $a2, 0x100
    ctx->r5 = ctx->r6 & 0X100;
    // 0x800A7B4C: beq         $a1, $zero, L_800A7B70
    if (ctx->r5 == 0) {
        // 0x800A7B50: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800A7B70;
    }
    // 0x800A7B50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7B54: lui         $t7, 0x40
    ctx->r15 = S32(0X40 << 16);
    // 0x800A7B58: lui         $t8, 0x10
    ctx->r24 = S32(0X10 << 16);
    // 0x800A7B5C: ori         $t7, $t7, 0x4DD8
    ctx->r15 = ctx->r15 | 0X4DD8;
    // 0x800A7B60: ori         $t8, $t8, 0x4DD8
    ctx->r24 = ctx->r24 | 0X4DD8;
    // 0x800A7B64: sw          $t7, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r15;
    // 0x800A7B68: b           L_800A7C30
    // 0x800A7B6C: sw          $t8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r24;
        goto L_800A7C30;
    // 0x800A7B6C: sw          $t8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r24;
L_800A7B70:
    // 0x800A7B70: beq         $t3, $at, L_800A7B8C
    if (ctx->r11 == ctx->r1) {
        // 0x800A7B74: lui         $t9, 0x40
        ctx->r25 = S32(0X40 << 16);
            goto L_800A7B8C;
    }
    // 0x800A7B74: lui         $t9, 0x40
    ctx->r25 = S32(0X40 << 16);
    // 0x800A7B78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A7B7C: beq         $t3, $at, L_800A7B8C
    if (ctx->r11 == ctx->r1) {
        // 0x800A7B80: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800A7B8C;
    }
    // 0x800A7B80: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A7B84: bne         $t3, $at, L_800A7BA4
    if (ctx->r11 != ctx->r1) {
        // 0x800A7B88: lui         $t7, 0x44
        ctx->r15 = S32(0X44 << 16);
            goto L_800A7BA4;
    }
    // 0x800A7B88: lui         $t7, 0x44
    ctx->r15 = S32(0X44 << 16);
L_800A7B8C:
    // 0x800A7B8C: lui         $t6, 0x10
    ctx->r14 = S32(0X10 << 16);
    // 0x800A7B90: ori         $t9, $t9, 0x49F8
    ctx->r25 = ctx->r25 | 0X49F8;
    // 0x800A7B94: ori         $t6, $t6, 0x49F8
    ctx->r14 = ctx->r14 | 0X49F8;
    // 0x800A7B98: sw          $t9, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r25;
    // 0x800A7B9C: b           L_800A7C30
    // 0x800A7BA0: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
        goto L_800A7C30;
    // 0x800A7BA0: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
L_800A7BA4:
    // 0x800A7BA4: lui         $t8, 0x11
    ctx->r24 = S32(0X11 << 16);
    // 0x800A7BA8: ori         $t7, $t7, 0x3078
    ctx->r15 = ctx->r15 | 0X3078;
    // 0x800A7BAC: ori         $t8, $t8, 0x3078
    ctx->r24 = ctx->r24 | 0X3078;
    // 0x800A7BB0: sw          $t7, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r15;
    // 0x800A7BB4: b           L_800A7C30
    // 0x800A7BB8: sw          $t8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r24;
        goto L_800A7C30;
    // 0x800A7BB8: sw          $t8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r24;
L_800A7BBC:
    // 0x800A7BBC: beq         $a1, $zero, L_800A7BE0
    if (ctx->r5 == 0) {
        // 0x800A7BC0: lui         $t7, 0x44
        ctx->r15 = S32(0X44 << 16);
            goto L_800A7BE0;
    }
    // 0x800A7BC0: lui         $t7, 0x44
    ctx->r15 = S32(0X44 << 16);
    // 0x800A7BC4: lui         $t9, 0x44
    ctx->r25 = S32(0X44 << 16);
    // 0x800A7BC8: lui         $t6, 0x11
    ctx->r14 = S32(0X11 << 16);
    // 0x800A7BCC: ori         $t9, $t9, 0x2D58
    ctx->r25 = ctx->r25 | 0X2D58;
    // 0x800A7BD0: ori         $t6, $t6, 0x2D58
    ctx->r14 = ctx->r14 | 0X2D58;
    // 0x800A7BD4: sw          $t9, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r25;
    // 0x800A7BD8: b           L_800A7C30
    // 0x800A7BDC: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
        goto L_800A7C30;
    // 0x800A7BDC: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
L_800A7BE0:
    // 0x800A7BE0: lui         $t8, 0x11
    ctx->r24 = S32(0X11 << 16);
    // 0x800A7BE4: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x800A7BE8: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x800A7BEC: sw          $t7, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r15;
    // 0x800A7BF0: b           L_800A7C30
    // 0x800A7BF4: sw          $t8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r24;
        goto L_800A7C30;
    // 0x800A7BF4: sw          $t8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r24;
L_800A7BF8:
    // 0x800A7BF8: beq         $a1, $zero, L_800A7C1C
    if (ctx->r5 == 0) {
        // 0x800A7BFC: lui         $t7, 0x44
        ctx->r15 = S32(0X44 << 16);
            goto L_800A7C1C;
    }
    // 0x800A7BFC: lui         $t7, 0x44
    ctx->r15 = S32(0X44 << 16);
    // 0x800A7C00: lui         $t9, 0x44
    ctx->r25 = S32(0X44 << 16);
    // 0x800A7C04: lui         $t6, 0x11
    ctx->r14 = S32(0X11 << 16);
    // 0x800A7C08: ori         $t9, $t9, 0x2D58
    ctx->r25 = ctx->r25 | 0X2D58;
    // 0x800A7C0C: ori         $t6, $t6, 0x2D58
    ctx->r14 = ctx->r14 | 0X2D58;
    // 0x800A7C10: sw          $t9, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r25;
    // 0x800A7C14: b           L_800A7C30
    // 0x800A7C18: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
        goto L_800A7C30;
    // 0x800A7C18: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
L_800A7C1C:
    // 0x800A7C1C: lui         $t8, 0x11
    ctx->r24 = S32(0X11 << 16);
    // 0x800A7C20: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x800A7C24: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x800A7C28: sw          $t7, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r15;
    // 0x800A7C2C: sw          $t8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r24;
L_800A7C30:
    // 0x800A7C30: andi        $t9, $a2, 0x40
    ctx->r25 = ctx->r6 & 0X40;
    // 0x800A7C34: bne         $t9, $zero, L_800A7C58
    if (ctx->r25 != 0) {
        // 0x800A7C38: nop
    
            goto L_800A7C58;
    }
    // 0x800A7C38: nop

    // 0x800A7C3C: lw          $t6, 0x50($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X50);
    // 0x800A7C40: lw          $t8, 0x54($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X54);
    // 0x800A7C44: addiu       $t3, $zero, -0x9
    ctx->r11 = ADD32(0, -0X9);
    // 0x800A7C48: and         $t7, $t6, $t3
    ctx->r15 = ctx->r14 & ctx->r11;
    // 0x800A7C4C: and         $t9, $t8, $t3
    ctx->r25 = ctx->r24 & ctx->r11;
    // 0x800A7C50: sw          $t7, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r15;
    // 0x800A7C54: sw          $t9, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r25;
L_800A7C58:
    // 0x800A7C58: beq         $t2, $zero, L_800A7C7C
    if (ctx->r10 == 0) {
        // 0x800A7C5C: nop
    
            goto L_800A7C7C;
    }
    // 0x800A7C5C: nop

    // 0x800A7C60: lw          $t6, 0x50($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X50);
    // 0x800A7C64: lw          $t8, 0x54($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X54);
    // 0x800A7C68: addiu       $t2, $zero, -0x31
    ctx->r10 = ADD32(0, -0X31);
    // 0x800A7C6C: and         $t7, $t6, $t2
    ctx->r15 = ctx->r14 & ctx->r10;
    // 0x800A7C70: and         $t9, $t8, $t2
    ctx->r25 = ctx->r24 & ctx->r10;
    // 0x800A7C74: sw          $t7, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r15;
    // 0x800A7C78: sw          $t9, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r25;
L_800A7C7C:
    // 0x800A7C7C: beq         $v0, $zero, L_800A7CC4
    if (ctx->r2 == 0) {
        // 0x800A7C80: sw          $zero, 0x4C($v1)
        MEM_W(0X4C, ctx->r3) = 0;
            goto L_800A7CC4;
    }
    // 0x800A7C80: sw          $zero, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = 0;
    // 0x800A7C84: lbu         $t6, 0xF($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF);
    // 0x800A7C88: lui         $t9, 0xC08
    ctx->r25 = S32(0XC08 << 16);
    // 0x800A7C8C: bnel        $t6, $zero, L_800A7CA4
    if (ctx->r14 != 0) {
        // 0x800A7C90: lui         $t6, 0x10
        ctx->r14 = S32(0X10 << 16);
            goto L_800A7CA4;
    }
    goto skip_14;
    // 0x800A7C90: lui         $t6, 0x10
    ctx->r14 = S32(0X10 << 16);
    skip_14:
    // 0x800A7C94: lbu         $t7, 0xE($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XE);
    // 0x800A7C98: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x800A7C9C: beq         $t8, $zero, L_800A7CB0
    if (ctx->r24 == 0) {
        // 0x800A7CA0: lui         $t6, 0x10
        ctx->r14 = S32(0X10 << 16);
            goto L_800A7CB0;
    }
    // 0x800A7CA0: lui         $t6, 0x10
    ctx->r14 = S32(0X10 << 16);
L_800A7CA4:
    // 0x800A7CA4: sw          $t9, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r25;
    // 0x800A7CA8: b           L_800A7CC4
    // 0x800A7CAC: sw          $t6, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r14;
        goto L_800A7CC4;
    // 0x800A7CAC: sw          $t6, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r14;
L_800A7CB0:
    // 0x800A7CB0: beq         $t1, $zero, L_800A7CC4
    if (ctx->r9 == 0) {
        // 0x800A7CB4: lui         $t7, 0xC08
        ctx->r15 = S32(0XC08 << 16);
            goto L_800A7CC4;
    }
    // 0x800A7CB4: lui         $t7, 0xC08
    ctx->r15 = S32(0XC08 << 16);
    // 0x800A7CB8: lui         $t8, 0x10
    ctx->r24 = S32(0X10 << 16);
    // 0x800A7CBC: sw          $t7, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r15;
    // 0x800A7CC0: sw          $t8, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r24;
L_800A7CC4:
    // 0x800A7CC4: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x800A7CC8: andi        $t6, $a2, 0x400
    ctx->r14 = ctx->r6 & 0X400;
    // 0x800A7CCC: beq         $t9, $zero, L_800A7CE8
    if (ctx->r25 == 0) {
        // 0x800A7CD0: nop
    
            goto L_800A7CE8;
    }
    // 0x800A7CD0: nop

    // 0x800A7CD4: bne         $t6, $zero, L_800A7CE8
    if (ctx->r14 != 0) {
        // 0x800A7CD8: lui         $t7, 0xC800
        ctx->r15 = S32(0XC800 << 16);
            goto L_800A7CE8;
    }
    // 0x800A7CD8: lui         $t7, 0xC800
    ctx->r15 = S32(0XC800 << 16);
    // 0x800A7CDC: lui         $t8, 0x10
    ctx->r24 = S32(0X10 << 16);
    // 0x800A7CE0: sw          $t7, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r15;
    // 0x800A7CE4: sw          $t8, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r24;
L_800A7CE8:
    // 0x800A7CE8: beql        $v0, $zero, L_800A7E30
    if (ctx->r2 == 0) {
        // 0x800A7CEC: lw          $t8, 0x20($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X20);
            goto L_800A7E30;
    }
    goto skip_15;
    // 0x800A7CEC: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    skip_15:
    // 0x800A7CF0: beq         $t1, $zero, L_800A7D18
    if (ctx->r9 == 0) {
        // 0x800A7CF4: lui         $t9, 0xFCFF
        ctx->r25 = S32(0XFCFF << 16);
            goto L_800A7D18;
    }
    // 0x800A7CF4: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800A7CF8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A7CFC: lui         $t6, 0xFF0C
    ctx->r14 = S32(0XFF0C << 16);
    // 0x800A7D00: ori         $t6, $t6, 0xF3FF
    ctx->r14 = ctx->r14 | 0XF3FF;
    // 0x800A7D04: ori         $t9, $t9, 0xFE04
    ctx->r25 = ctx->r25 | 0XFE04;
    // 0x800A7D08: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A7D0C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A7D10: b           L_800A7E84
    // 0x800A7D14: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_800A7E84;
    // 0x800A7D14: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800A7D18:
    // 0x800A7D18: lbu         $t7, 0xF($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF);
    // 0x800A7D1C: bne         $t7, $zero, L_800A7D34
    if (ctx->r15 != 0) {
        // 0x800A7D20: nop
    
            goto L_800A7D34;
    }
    // 0x800A7D20: nop

    // 0x800A7D24: lbu         $t8, 0xE($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XE);
    // 0x800A7D28: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x800A7D2C: beql        $t9, $zero, L_800A7D84
    if (ctx->r25 == 0) {
        // 0x800A7D30: lw          $t6, 0x20($a3)
        ctx->r14 = MEM_W(ctx->r7, 0X20);
            goto L_800A7D84;
    }
    goto skip_16;
    // 0x800A7D30: lw          $t6, 0x20($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X20);
    skip_16:
L_800A7D34:
    // 0x800A7D34: beq         $a1, $zero, L_800A7D60
    if (ctx->r5 == 0) {
        // 0x800A7D38: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800A7D60;
    }
    // 0x800A7D38: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A7D3C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A7D40: lui         $t6, 0xFC26
    ctx->r14 = S32(0XFC26 << 16);
    // 0x800A7D44: lui         $t7, 0x1F0C
    ctx->r15 = S32(0X1F0C << 16);
    // 0x800A7D48: ori         $t7, $t7, 0x93FF
    ctx->r15 = ctx->r15 | 0X93FF;
    // 0x800A7D4C: ori         $t6, $t6, 0xA004
    ctx->r14 = ctx->r14 | 0XA004;
    // 0x800A7D50: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A7D54: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A7D58: b           L_800A7E84
    // 0x800A7D5C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_800A7E84;
    // 0x800A7D5C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800A7D60:
    // 0x800A7D60: lui         $t8, 0xFC26
    ctx->r24 = S32(0XFC26 << 16);
    // 0x800A7D64: lui         $t9, 0x1F0C
    ctx->r25 = S32(0X1F0C << 16);
    // 0x800A7D68: ori         $t9, $t9, 0x93FF
    ctx->r25 = ctx->r25 | 0X93FF;
    // 0x800A7D6C: ori         $t8, $t8, 0xA004
    ctx->r24 = ctx->r24 | 0XA004;
    // 0x800A7D70: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A7D74: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A7D78: b           L_800A7E84
    // 0x800A7D7C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_800A7E84;
    // 0x800A7D7C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A7D80: lw          $t6, 0x20($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X20);
L_800A7D84:
    // 0x800A7D84: andi        $t7, $a2, 0x400
    ctx->r15 = ctx->r6 & 0X400;
    // 0x800A7D88: beq         $t6, $zero, L_800A7DE0
    if (ctx->r14 == 0) {
        // 0x800A7D8C: nop
    
            goto L_800A7DE0;
    }
    // 0x800A7D8C: nop

    // 0x800A7D90: bne         $t7, $zero, L_800A7DE0
    if (ctx->r15 != 0) {
        // 0x800A7D94: nop
    
            goto L_800A7DE0;
    }
    // 0x800A7D94: nop

    // 0x800A7D98: beq         $a1, $zero, L_800A7DC0
    if (ctx->r5 == 0) {
        // 0x800A7D9C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800A7DC0;
    }
    // 0x800A7D9C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A7DA0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A7DA4: lui         $t8, 0xFC12
    ctx->r24 = S32(0XFC12 << 16);
    // 0x800A7DA8: ori         $t8, $t8, 0x17FF
    ctx->r24 = ctx->r24 | 0X17FF;
    // 0x800A7DAC: addiu       $t9, $zero, -0x1C4
    ctx->r25 = ADD32(0, -0X1C4);
    // 0x800A7DB0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A7DB4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A7DB8: b           L_800A7E84
    // 0x800A7DBC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_800A7E84;
    // 0x800A7DBC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800A7DC0:
    // 0x800A7DC0: lui         $t6, 0xFC12
    ctx->r14 = S32(0XFC12 << 16);
    // 0x800A7DC4: lui         $t7, 0xFF0F
    ctx->r15 = S32(0XFF0F << 16);
    // 0x800A7DC8: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800A7DCC: ori         $t6, $t6, 0x1604
    ctx->r14 = ctx->r14 | 0X1604;
    // 0x800A7DD0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A7DD4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A7DD8: b           L_800A7E84
    // 0x800A7DDC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_800A7E84;
    // 0x800A7DDC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800A7DE0:
    // 0x800A7DE0: beq         $a1, $zero, L_800A7E0C
    if (ctx->r5 == 0) {
        // 0x800A7DE4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800A7E0C;
    }
    // 0x800A7DE4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A7DE8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A7DEC: lui         $t8, 0xFC12
    ctx->r24 = S32(0XFC12 << 16);
    // 0x800A7DF0: lui         $t9, 0xFF33
    ctx->r25 = S32(0XFF33 << 16);
    // 0x800A7DF4: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800A7DF8: ori         $t8, $t8, 0x1824
    ctx->r24 = ctx->r24 | 0X1824;
    // 0x800A7DFC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A7E00: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A7E04: b           L_800A7E84
    // 0x800A7E08: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_800A7E84;
    // 0x800A7E08: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800A7E0C:
    // 0x800A7E0C: lui         $t6, 0xFC12
    ctx->r14 = S32(0XFC12 << 16);
    // 0x800A7E10: lui         $t7, 0xFF2F
    ctx->r15 = S32(0XFF2F << 16);
    // 0x800A7E14: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800A7E18: ori         $t6, $t6, 0x1624
    ctx->r14 = ctx->r14 | 0X1624;
    // 0x800A7E1C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A7E20: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A7E24: b           L_800A7E84
    // 0x800A7E28: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_800A7E84;
    // 0x800A7E28: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A7E2C: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
L_800A7E30:
    // 0x800A7E30: andi        $t9, $a2, 0x400
    ctx->r25 = ctx->r6 & 0X400;
    // 0x800A7E34: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A7E38: beql        $t8, $zero, L_800A7E6C
    if (ctx->r24 == 0) {
        // 0x800A7E3C: lui         $t8, 0xFC32
        ctx->r24 = S32(0XFC32 << 16);
            goto L_800A7E6C;
    }
    goto skip_17;
    // 0x800A7E3C: lui         $t8, 0xFC32
    ctx->r24 = S32(0XFC32 << 16);
    skip_17:
    // 0x800A7E40: bne         $t9, $zero, L_800A7E68
    if (ctx->r25 != 0) {
        // 0x800A7E44: lui         $t6, 0xFCFF
        ctx->r14 = S32(0XFCFF << 16);
            goto L_800A7E68;
    }
    // 0x800A7E44: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x800A7E48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A7E4C: lui         $t7, 0xFF70
    ctx->r15 = S32(0XFF70 << 16);
    // 0x800A7E50: ori         $t7, $t7, 0x71FF
    ctx->r15 = ctx->r15 | 0X71FF;
    // 0x800A7E54: ori         $t6, $t6, 0xFE64
    ctx->r14 = ctx->r14 | 0XFE64;
    // 0x800A7E58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A7E5C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A7E60: b           L_800A7E84
    // 0x800A7E64: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_800A7E84;
    // 0x800A7E64: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800A7E68:
    // 0x800A7E68: lui         $t8, 0xFC32
    ctx->r24 = S32(0XFC32 << 16);
L_800A7E6C:
    // 0x800A7E6C: lui         $t9, 0xFF73
    ctx->r25 = S32(0XFF73 << 16);
    // 0x800A7E70: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800A7E74: ori         $t8, $t8, 0x3864
    ctx->r24 = ctx->r24 | 0X3864;
    // 0x800A7E78: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A7E7C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A7E80: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800A7E84:
    // 0x800A7E84: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800A7E88: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x800A7E8C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A7E90: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800A7E94: lw          $t7, 0x4C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4C);
    // 0x800A7E98: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A7E9C: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x800A7EA0: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x800A7EA4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A7EA8: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800A7EAC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800A7EB0: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x800A7EB4: lw          $t9, 0x50($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X50);
    // 0x800A7EB8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A7EBC: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800A7EC0: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x800A7EC4: or          $t7, $t0, $zero
    ctx->r15 = ctx->r8 | 0;
    // 0x800A7EC8: or          $t6, $v1, $zero
    ctx->r14 = ctx->r3 | 0;
    // 0x800A7ECC: addiu       $t9, $v1, 0x60
    ctx->r25 = ADD32(ctx->r3, 0X60);
L_800A7ED0:
    // 0x800A7ED0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800A7ED4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800A7ED8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800A7EDC: sw          $at, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r1;
    // 0x800A7EE0: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x800A7EE4: sw          $at, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r1;
    // 0x800A7EE8: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x800A7EEC: bne         $t6, $t9, L_800A7ED0
    if (ctx->r14 != ctx->r25) {
        // 0x800A7EF0: sw          $at, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r1;
            goto L_800A7ED0;
    }
    // 0x800A7EF0: sw          $at, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r1;
    // 0x800A7EF4: jr          $ra
    // 0x800A7EF8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800A7EF8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}

RECOMP_FUNC void func_800A7EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7EFC: addiu       $sp, $sp, -0x1D0
    ctx->r29 = ADD32(ctx->r29, -0X1D0);
    // 0x800A7F00: sw          $s3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r19;
    // 0x800A7F04: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800A7F08: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800A7F0C: sw          $s5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r21;
    // 0x800A7F10: sw          $s4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r20;
    // 0x800A7F14: sw          $s2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r18;
    // 0x800A7F18: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x800A7F1C: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x800A7F20: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800A7F24: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800A7F28: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800A7F2C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800A7F30: lbu         $s5, 0x4($a1)
    ctx->r21 = MEM_BU(ctx->r5, 0X4);
    // 0x800A7F34: addiu       $s3, $s3, -0x6C10
    ctx->r19 = ADD32(ctx->r19, -0X6C10);
    // 0x800A7F38: sw          $a1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r5;
    // 0x800A7F3C: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800A7F40: sw          $zero, 0xC($s3)
    MEM_W(0XC, ctx->r19) = 0;
    // 0x800A7F44: sw          $zero, 0x10($s3)
    MEM_W(0X10, ctx->r19) = 0;
    // 0x800A7F48: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800A7F4C: sw          $t8, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r24;
    // 0x800A7F50: sw          $zero, 0x14($s3)
    MEM_W(0X14, ctx->r19) = 0;
    // 0x800A7F54: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x800A7F58: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800A7F5C: andi        $t6, $s5, 0x1
    ctx->r14 = ctx->r21 & 0X1;
    // 0x800A7F60: lw          $a3, 0x28($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X28);
    // 0x800A7F64: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800A7F68: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800A7F6C: lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X4);
    // 0x800A7F70: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800A7F74: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
    // 0x800A7F78: lw          $t0, 0x24($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X24);
    // 0x800A7F7C: addiu       $s2, $a0, 0x8
    ctx->r18 = ADD32(ctx->r4, 0X8);
    // 0x800A7F80: beql        $t0, $zero, L_800A81B4
    if (ctx->r8 == 0) {
        // 0x800A7F84: lw          $a1, 0x28($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X28);
            goto L_800A81B4;
    }
    goto skip_0;
    // 0x800A7F84: lw          $a1, 0x28($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X28);
    skip_0:
    // 0x800A7F88: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800A7F8C: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x800A7F90: ori         $t8, $t8, 0x1E01
    ctx->r24 = ctx->r24 | 0X1E01;
    // 0x800A7F94: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800A7F98: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A7F9C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800A7FA0: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x800A7FA4: bne         $t7, $zero, L_800A81B0
    if (ctx->r15 != 0) {
        // 0x800A7FA8: addiu       $a3, $a3, 0x40
        ctx->r7 = ADD32(ctx->r7, 0X40);
            goto L_800A81B0;
    }
    // 0x800A7FA8: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x800A7FAC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A7FB0: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A7FB4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A7FB8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A7FBC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A7FC0: ori         $t9, $t9, 0x1D00
    ctx->r25 = ctx->r25 | 0X1D00;
    // 0x800A7FC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A7FC8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800A7FCC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A7FD0: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x800A7FD4: ori         $t4, $t4, 0x1A01
    ctx->r12 = ctx->r12 | 0X1A01;
    // 0x800A7FD8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A7FDC: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800A7FE0: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x800A7FE4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800A7FE8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800A7FEC: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800A7FF0: ori         $t6, $t6, 0x1801
    ctx->r14 = ctx->r14 | 0X1801;
    // 0x800A7FF4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A7FF8: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800A7FFC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800A8000: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800A8004: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8008: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A800C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800A8010: ori         $t8, $t8, 0x1700
    ctx->r24 = ctx->r24 | 0X1700;
    // 0x800A8014: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A8018: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800A801C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800A8020: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8024: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800A8028: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x800A802C: addiu       $t4, $zero, 0xC00
    ctx->r12 = ADD32(0, 0XC00);
    // 0x800A8030: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A8034: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A8038: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A803C: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x800A8040: ori         $t5, $t5, 0x1201
    ctx->r13 = ctx->r13 | 0X1201;
    // 0x800A8044: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8048: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x800A804C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800A8050: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800A8054: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A8058: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x800A805C: ori         $t7, $t7, 0xF00
    ctx->r15 = ctx->r15 | 0XF00;
    // 0x800A8060: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8064: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x800A8068: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800A806C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A8070: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800A8074: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800A8078: ori         $t9, $t9, 0x1001
    ctx->r25 = ctx->r25 | 0X1001;
    // 0x800A807C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8080: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800A8084: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8088: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800A808C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8090: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x800A8094: ori         $t4, $t4, 0xD01
    ctx->r12 = ctx->r12 | 0XD01;
    // 0x800A8098: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A809C: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800A80A0: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800A80A4: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x800A80A8: ori         $t5, $t5, 0xC00
    ctx->r13 = ctx->r13 | 0XC00;
    // 0x800A80AC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A80B0: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800A80B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A80B8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800A80BC: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A80C0: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x800A80C4: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x800A80C8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A80CC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800A80D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A80D4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A80D8: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x800A80DC: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x800A80E0: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x800A80E4: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x800A80E8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A80EC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800A80F0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800A80F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800A80F8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A80FC: addiu       $t5, $zero, -0x80
    ctx->r13 = ADD32(0, -0X80);
    // 0x800A8100: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800A8104: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8108: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800A810C: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x800A8110: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8114: lui         $t7, 0xFFFE
    ctx->r15 = S32(0XFFFE << 16);
    // 0x800A8118: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x800A811C: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800A8120: ori         $t7, $t7, 0x793C
    ctx->r15 = ctx->r15 | 0X793C;
    // 0x800A8124: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A8128: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x800A812C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800A8130: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800A8134: ori         $t8, $t8, 0x800
    ctx->r24 = ctx->r24 | 0X800;
    // 0x800A8138: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A813C: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800A8140: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A8144: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A8148: ori         $t9, $t9, 0x7
    ctx->r25 = ctx->r25 | 0X7;
    // 0x800A814C: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A8150: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800A8154: lw          $t4, 0x2C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X2C);
    // 0x800A8158: sll         $t5, $s5, 6
    ctx->r13 = S32(ctx->r21 << 6);
    // 0x800A815C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8160: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800A8164: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800A8168: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A816C: sll         $t8, $s5, 1
    ctx->r24 = S32(ctx->r21 << 1);
    // 0x800A8170: lui         $t7, 0xDB0E
    ctx->r15 = S32(0XDB0E << 16);
    // 0x800A8174: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A8178: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x800A817C: lhu         $t4, 0x8($t9)
    ctx->r12 = MEM_HU(ctx->r25, 0X8);
    // 0x800A8180: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8184: lui         $t5, 0xDC08
    ctx->r13 = S32(0XDC08 << 16);
    // 0x800A8188: ori         $t5, $t5, 0x8
    ctx->r13 = ctx->r13 | 0X8;
    // 0x800A818C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800A8190: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x800A8194: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800A8198: lw          $t6, 0x28($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X28);
    // 0x800A819C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A81A0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A81A4: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800A81A8: sw          $t0, -0x6A70($at)
    MEM_W(-0X6A70, ctx->r1) = ctx->r8;
    // 0x800A81AC: lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X4);
L_800A81B0:
    // 0x800A81B0: lw          $a1, 0x28($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X28);
L_800A81B4:
    // 0x800A81B4: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800A81B8: beql        $a1, $zero, L_800A88A4
    if (ctx->r5 == 0) {
        // 0x800A81BC: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_800A88A4;
    }
    goto skip_1;
    // 0x800A81BC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x800A81C0: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800A81C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800A81C8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800A81CC: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800A81D0: bnel        $t9, $zero, L_800A88A4
    if (ctx->r25 != 0) {
        // 0x800A81D4: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_800A88A4;
    }
    goto skip_2;
    // 0x800A81D4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_2:
    // 0x800A81D8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800A81DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A81E0: sw          $a3, -0x6A6C($at)
    MEM_W(-0X6A6C, ctx->r1) = ctx->r7;
    // 0x800A81E4: beq         $v0, $zero, L_800A8588
    if (ctx->r2 == 0) {
        // 0x800A81E8: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800A8588;
    }
    // 0x800A81E8: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800A81EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A81F0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800A81F4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800A81F8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800A81FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A8200: ldc1        $f18, 0xA18($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0XA18);
    // 0x800A8204: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A8208: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x800A820C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A8210: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800A8214: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x800A8218: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800A821C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A8220: addu        $t2, $s3, $t4
    ctx->r10 = ADD32(ctx->r19, ctx->r12);
    // 0x800A8224: sll         $t0, $s5, 4
    ctx->r8 = S32(ctx->r21 << 4);
    // 0x800A8228: sll         $a2, $s5, 4
    ctx->r6 = S32(ctx->r21 << 4);
L_800A822C:
    // 0x800A822C: lw          $v1, 0xC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XC);
    // 0x800A8230: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800A8234: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800A8238: lwc1        $f4, 0xE0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XE0);
    // 0x800A823C: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x800A8240: addiu       $v1, $v1, 0xC0
    ctx->r3 = ADD32(ctx->r3, 0XC0);
    // 0x800A8244: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800A8248: addu        $v0, $t6, $t0
    ctx->r2 = ADD32(ctx->r14, ctx->r8);
    // 0x800A824C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800A8250: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800A8254: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800A8258: nop

    // 0x800A825C: sb          $t8, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r24;
    // 0x800A8260: lwc1        $f10, 0x24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X24);
    // 0x800A8264: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800A8268: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A826C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800A8270: nop

    // 0x800A8274: sb          $t4, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r12;
    // 0x800A8278: lwc1        $f8, 0x28($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X28);
    // 0x800A827C: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x800A8280: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800A8284: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x800A8288: nop

    // 0x800A828C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800A8290: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800A8294: lwc1        $f14, 0xC($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800A8298: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x800A829C: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x800A82A0: nop

    // 0x800A82A4: bc1fl       L_800A82B8
    if (!c1cs) {
        // 0x800A82A8: c.lt.d      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
            goto L_800A82B8;
    }
    goto skip_3;
    // 0x800A82A8: c.lt.d      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
    skip_3:
    // 0x800A82AC: b           L_800A82C8
    // 0x800A82B0: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
        goto L_800A82C8;
    // 0x800A82B0: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x800A82B4: c.lt.d      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
L_800A82B8:
    // 0x800A82B8: nop

    // 0x800A82BC: bc1fl       L_800A82CC
    if (!c1cs) {
        // 0x800A82C0: lwc1        $f12, 0x10($a1)
        ctx->f12.u32l = MEM_W(ctx->r5, 0X10);
            goto L_800A82CC;
    }
    goto skip_4;
    // 0x800A82C0: lwc1        $f12, 0x10($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X10);
    skip_4:
    // 0x800A82C4: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
L_800A82C8:
    // 0x800A82C8: lwc1        $f12, 0x10($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X10);
L_800A82CC:
    // 0x800A82CC: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x800A82D0: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x800A82D4: nop

    // 0x800A82D8: bc1fl       L_800A82EC
    if (!c1cs) {
        // 0x800A82DC: c.lt.d      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
            goto L_800A82EC;
    }
    goto skip_5;
    // 0x800A82DC: c.lt.d      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
    skip_5:
    // 0x800A82E0: b           L_800A82FC
    // 0x800A82E4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
        goto L_800A82FC;
    // 0x800A82E4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x800A82E8: c.lt.d      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
L_800A82EC:
    // 0x800A82EC: nop

    // 0x800A82F0: bc1fl       L_800A8300
    if (!c1cs) {
        // 0x800A82F4: lwc1        $f2, 0x14($a1)
        ctx->f2.u32l = MEM_W(ctx->r5, 0X14);
            goto L_800A8300;
    }
    goto skip_6;
    // 0x800A82F4: lwc1        $f2, 0x14($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X14);
    skip_6:
    // 0x800A82F8: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
L_800A82FC:
    // 0x800A82FC: lwc1        $f2, 0x14($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X14);
L_800A8300:
    // 0x800A8300: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x800A8304: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x800A8308: nop

    // 0x800A830C: bc1fl       L_800A8320
    if (!c1cs) {
        // 0x800A8310: c.lt.d      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
            goto L_800A8320;
    }
    goto skip_7;
    // 0x800A8310: c.lt.d      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
    skip_7:
    // 0x800A8314: b           L_800A8330
    // 0x800A8318: mov.s       $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    ctx->f2.fl = ctx->f26.fl;
        goto L_800A8330;
    // 0x800A8318: mov.s       $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    ctx->f2.fl = ctx->f26.fl;
    // 0x800A831C: c.lt.d      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
L_800A8320:
    // 0x800A8320: nop

    // 0x800A8324: bc1fl       L_800A8334
    if (!c1cs) {
        // 0x800A8328: lwc1        $f6, 0x8($a1)
        ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
            goto L_800A8334;
    }
    goto skip_8;
    // 0x800A8328: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    skip_8:
    // 0x800A832C: mov.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    ctx->f2.fl = ctx->f24.fl;
L_800A8330:
    // 0x800A8330: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
L_800A8334:
    // 0x800A8334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A8338: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800A833C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800A8340: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800A8344: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A8348: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800A834C: nop

    // 0x800A8350: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800A8354: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800A8358: nop

    // 0x800A835C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800A8360: beql        $v0, $zero, L_800A83B4
    if (ctx->r2 == 0) {
        // 0x800A8364: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_800A83B4;
    }
    goto skip_9;
    // 0x800A8364: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_9:
    // 0x800A8368: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800A836C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A8370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A8374: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x800A8378: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800A837C: nop

    // 0x800A8380: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800A8384: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800A8388: nop

    // 0x800A838C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800A8390: bne         $v0, $zero, L_800A83A8
    if (ctx->r2 != 0) {
        // 0x800A8394: nop
    
            goto L_800A83A8;
    }
    // 0x800A8394: nop

    // 0x800A8398: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800A839C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A83A0: b           L_800A83C0
    // 0x800A83A4: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_800A83C0;
    // 0x800A83A4: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_800A83A8:
    // 0x800A83A8: b           L_800A83C0
    // 0x800A83AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A83C0;
    // 0x800A83AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800A83B0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_800A83B4:
    // 0x800A83B4: nop

    // 0x800A83B8: bltz        $v0, L_800A83A8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A83BC: nop
    
            goto L_800A83A8;
    }
    // 0x800A83BC: nop

L_800A83C0:
    // 0x800A83C0: lw          $t9, 0x18($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X18);
    // 0x800A83C4: or          $t8, $v0, $zero
    ctx->r24 = ctx->r2 | 0;
    // 0x800A83C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A83CC: addu        $t4, $t9, $a2
    ctx->r12 = ADD32(ctx->r25, ctx->r6);
    // 0x800A83D0: sb          $t8, 0x4($t4)
    MEM_B(0X4, ctx->r12) = ctx->r24;
    // 0x800A83D4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800A83D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A83DC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800A83E0: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x800A83E4: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800A83E8: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x800A83EC: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800A83F0: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800A83F4: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800A83F8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800A83FC: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x800A8400: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A8404: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800A8408: nop

    // 0x800A840C: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800A8410: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800A8414: nop

    // 0x800A8418: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800A841C: beql        $v0, $zero, L_800A8470
    if (ctx->r2 == 0) {
        // 0x800A8420: mfc1        $v0, $f8
        ctx->r2 = (int32_t)ctx->f8.u32l;
            goto L_800A8470;
    }
    goto skip_10;
    // 0x800A8420: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    skip_10:
    // 0x800A8424: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A8428: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A842C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A8430: sub.d       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f6.d - ctx->f8.d;
    // 0x800A8434: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800A8438: nop

    // 0x800A843C: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x800A8440: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800A8444: nop

    // 0x800A8448: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800A844C: bne         $v0, $zero, L_800A8464
    if (ctx->r2 != 0) {
        // 0x800A8450: nop
    
            goto L_800A8464;
    }
    // 0x800A8450: nop

    // 0x800A8454: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800A8458: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A845C: b           L_800A847C
    // 0x800A8460: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_800A847C;
    // 0x800A8460: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_800A8464:
    // 0x800A8464: b           L_800A847C
    // 0x800A8468: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A847C;
    // 0x800A8468: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800A846C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
L_800A8470:
    // 0x800A8470: nop

    // 0x800A8474: bltz        $v0, L_800A8464
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A8478: nop
    
            goto L_800A8464;
    }
    // 0x800A8478: nop

L_800A847C:
    // 0x800A847C: lw          $t4, 0x18($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X18);
    // 0x800A8480: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
    // 0x800A8484: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A8488: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800A848C: sb          $t9, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r25;
    // 0x800A8490: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A8494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A8498: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800A849C: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x800A84A0: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x800A84A4: sb          $t9, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r25;
    // 0x800A84A8: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800A84AC: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800A84B0: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800A84B4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800A84B8: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x800A84BC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A84C0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800A84C4: nop

    // 0x800A84C8: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800A84CC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800A84D0: nop

    // 0x800A84D4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800A84D8: beql        $v0, $zero, L_800A852C
    if (ctx->r2 == 0) {
        // 0x800A84DC: mfc1        $v0, $f10
        ctx->r2 = (int32_t)ctx->f10.u32l;
            goto L_800A852C;
    }
    goto skip_11;
    // 0x800A84DC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    skip_11:
    // 0x800A84E0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800A84E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800A84E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A84EC: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x800A84F0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800A84F4: nop

    // 0x800A84F8: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x800A84FC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800A8500: nop

    // 0x800A8504: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800A8508: bne         $v0, $zero, L_800A8520
    if (ctx->r2 != 0) {
        // 0x800A850C: nop
    
            goto L_800A8520;
    }
    // 0x800A850C: nop

    // 0x800A8510: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800A8514: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8518: b           L_800A8538
    // 0x800A851C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_800A8538;
    // 0x800A851C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_800A8520:
    // 0x800A8520: b           L_800A8538
    // 0x800A8524: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A8538;
    // 0x800A8524: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800A8528: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
L_800A852C:
    // 0x800A852C: nop

    // 0x800A8530: bltz        $v0, L_800A8520
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A8534: nop
    
            goto L_800A8520;
    }
    // 0x800A8534: nop

L_800A8538:
    // 0x800A8538: lw          $t5, 0x18($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X18);
    // 0x800A853C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A8540: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800A8544: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x800A8548: sb          $v0, 0x6($t6)
    MEM_B(0X6, ctx->r14) = ctx->r2;
    // 0x800A854C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A8550: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A8554: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x800A8558: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800A855C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800A8560: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800A8564: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x800A8568: sb          $v0, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r2;
    // 0x800A856C: lw          $t4, -0x4($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X4);
    // 0x800A8570: bne         $t1, $zero, L_800A822C
    if (ctx->r9 != 0) {
        // 0x800A8574: sw          $t4, 0x18($t2)
        MEM_W(0X18, ctx->r10) = ctx->r12;
            goto L_800A822C;
    }
    // 0x800A8574: sw          $t4, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r12;
    // 0x800A8578: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A857C: sw          $a3, -0x6A6C($at)
    MEM_W(-0X6A6C, ctx->r1) = ctx->r7;
    // 0x800A8580: lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X4);
    // 0x800A8584: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_800A8588:
    // 0x800A8588: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A858C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800A8590: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800A8594: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A8598: bne         $v0, $at, L_800A85F4
    if (ctx->r2 != ctx->r1) {
        // 0x800A859C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800A85F4;
    }
    // 0x800A859C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A85A0: lui         $t5, 0xDC08
    ctx->r13 = S32(0XDC08 << 16);
    // 0x800A85A4: ori         $t5, $t5, 0x90A
    ctx->r13 = ctx->r13 | 0X90A;
    // 0x800A85A8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A85AC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800A85B0: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x800A85B4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A85B8: sll         $t4, $s5, 4
    ctx->r12 = S32(ctx->r21 << 4);
    // 0x800A85BC: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x800A85C0: lui         $t6, 0xDC08
    ctx->r14 = S32(0XDC08 << 16);
    // 0x800A85C4: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A85C8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800A85CC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800A85D0: addiu       $t7, $t7, 0x6208
    ctx->r15 = ADD32(ctx->r15, 0X6208);
    // 0x800A85D4: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x800A85D8: ori         $t6, $t6, 0x60A
    ctx->r14 = ctx->r14 | 0X60A;
    // 0x800A85DC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A85E0: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x800A85E4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800A85E8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800A85EC: b           L_800A879C
    // 0x800A85F0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_800A879C;
    // 0x800A85F0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800A85F4:
    // 0x800A85F4: lw          $a0, 0x28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X28);
    // 0x800A85F8: beq         $v0, $zero, L_800A879C
    if (ctx->r2 == 0) {
        // 0x800A85FC: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800A879C;
    }
    // 0x800A85FC: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800A8600: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x800A8604: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x800A8608: beq         $v1, $zero, L_800A867C
    if (ctx->r3 == 0) {
        // 0x800A860C: sll         $t0, $s5, 4
        ctx->r8 = S32(ctx->r21 << 4);
            goto L_800A867C;
    }
    // 0x800A860C: sll         $t0, $s5, 4
    ctx->r8 = S32(ctx->r21 << 4);
    // 0x800A8610: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // 0x800A8614: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x800A8618: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800A861C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800A8620: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800A8624: lui         $a1, 0xDC08
    ctx->r5 = S32(0XDC08 << 16);
L_800A8628:
    // 0x800A8628: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A862C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800A8630: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8634: bgez        $v0, L_800A8644
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A8638: sra         $t8, $v0, 3
        ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
            goto L_800A8644;
    }
    // 0x800A8638: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800A863C: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x800A8640: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_800A8644:
    // 0x800A8644: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800A8648: sll         $t4, $t9, 8
    ctx->r12 = S32(ctx->r25 << 8);
    // 0x800A864C: or          $t5, $t4, $a1
    ctx->r13 = ctx->r12 | ctx->r5;
    // 0x800A8650: ori         $t6, $t5, 0xA
    ctx->r14 = ctx->r13 | 0XA;
    // 0x800A8654: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800A8658: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A865C: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800A8660: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800A8664: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800A8668: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A866C: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800A8670: bne         $a3, $t1, L_800A8628
    if (ctx->r7 != ctx->r9) {
        // 0x800A8674: sw          $t9, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r25;
            goto L_800A8628;
    }
    // 0x800A8674: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800A8678: beq         $t1, $zero, L_800A879C
    if (ctx->r9 == 0) {
        // 0x800A867C: sll         $v0, $a2, 2
        ctx->r2 = S32(ctx->r6 << 2);
            goto L_800A879C;
    }
L_800A867C:
    // 0x800A867C: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x800A8680: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800A8684: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800A8688: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800A868C: lui         $a1, 0xDC08
    ctx->r5 = S32(0XDC08 << 16);
L_800A8690:
    // 0x800A8690: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A8694: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8698: bgez        $v0, L_800A86A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A869C: sra         $t4, $v0, 3
        ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
            goto L_800A86A8;
    }
    // 0x800A869C: sra         $t4, $v0, 3
    ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800A86A0: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x800A86A4: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800A86A8:
    // 0x800A86A8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800A86AC: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800A86B0: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x800A86B4: ori         $t8, $t7, 0xA
    ctx->r24 = ctx->r15 | 0XA;
    // 0x800A86B8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800A86BC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800A86C0: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800A86C4: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800A86C8: lw          $t4, 0x18($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X18);
    // 0x800A86CC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A86D0: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x800A86D4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800A86D8: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A86DC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A86E0: bgez        $v0, L_800A86F0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A86E4: sra         $t6, $v0, 3
        ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
            goto L_800A86F0;
    }
    // 0x800A86E4: sra         $t6, $v0, 3
    ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800A86E8: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x800A86EC: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_800A86F0:
    // 0x800A86F0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800A86F4: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800A86F8: or          $t9, $t8, $a1
    ctx->r25 = ctx->r24 | ctx->r5;
    // 0x800A86FC: ori         $t4, $t9, 0xA
    ctx->r12 = ctx->r25 | 0XA;
    // 0x800A8700: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800A8704: lw          $t5, -0xC($a0)
    ctx->r13 = MEM_W(ctx->r4, -0XC);
    // 0x800A8708: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800A870C: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x800A8710: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800A8714: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800A8718: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A871C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8720: bgez        $v0, L_800A8730
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A8724: sra         $t8, $v0, 3
        ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
            goto L_800A8730;
    }
    // 0x800A8724: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800A8728: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x800A872C: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_800A8730:
    // 0x800A8730: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800A8734: sll         $t4, $t9, 8
    ctx->r12 = S32(ctx->r25 << 8);
    // 0x800A8738: or          $t5, $t4, $a1
    ctx->r13 = ctx->r12 | ctx->r5;
    // 0x800A873C: ori         $t6, $t5, 0xA
    ctx->r14 = ctx->r13 | 0XA;
    // 0x800A8740: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800A8744: lw          $t7, -0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, -0X8);
    // 0x800A8748: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800A874C: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800A8750: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800A8754: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800A8758: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A875C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8760: bgez        $v0, L_800A8770
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A8764: sra         $t4, $v0, 3
        ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
            goto L_800A8770;
    }
    // 0x800A8764: sra         $t4, $v0, 3
    ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800A8768: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x800A876C: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800A8770:
    // 0x800A8770: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800A8774: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800A8778: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x800A877C: ori         $t8, $t7, 0xA
    ctx->r24 = ctx->r15 | 0XA;
    // 0x800A8780: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800A8784: lw          $t9, -0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, -0X4);
    // 0x800A8788: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800A878C: lw          $t4, 0x18($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X18);
    // 0x800A8790: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x800A8794: bne         $t1, $zero, L_800A8690
    if (ctx->r9 != 0) {
        // 0x800A8798: sw          $t5, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r13;
            goto L_800A8690;
    }
    // 0x800A8798: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
L_800A879C:
    // 0x800A879C: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x800A87A0: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x800A87A4: beq         $at, $zero, L_800A88FC
    if (ctx->r1 == 0) {
        // 0x800A87A8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800A88FC;
    }
    // 0x800A87A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A87AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A87B0: addu        $at, $at, $t6
    gpr jr_addend_800A87B8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A87B4: lw          $t6, 0xA20($at)
    ctx->r14 = ADD32(ctx->r1, 0XA20);
    // 0x800A87B8: jr          $t6
    // 0x800A87BC: nop

    switch (jr_addend_800A87B8 >> 2) {
        case 0: goto L_800A87C0; break;
        case 1: goto L_800A87DC; break;
        case 2: goto L_800A87F8; break;
        case 3: goto L_800A8814; break;
        case 4: goto L_800A8830; break;
        case 5: goto L_800A884C; break;
        case 6: goto L_800A8868; break;
        case 7: goto L_800A8884; break;
        default: switch_error(__func__, 0x800A87B8, 0x800E0A20);
    }
    // 0x800A87BC: nop

L_800A87C0:
    // 0x800A87C0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A87C4: lui         $t7, 0xDB02
    ctx->r15 = S32(0XDB02 << 16);
    // 0x800A87C8: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x800A87CC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800A87D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800A87D4: b           L_800A88FC
    // 0x800A87D8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_800A88FC;
    // 0x800A87D8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_800A87DC:
    // 0x800A87DC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A87E0: lui         $t9, 0xDB02
    ctx->r25 = S32(0XDB02 << 16);
    // 0x800A87E4: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    // 0x800A87E8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A87EC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A87F0: b           L_800A88FC
    // 0x800A87F4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_800A88FC;
    // 0x800A87F4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_800A87F8:
    // 0x800A87F8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A87FC: lui         $t5, 0xDB02
    ctx->r13 = S32(0XDB02 << 16);
    // 0x800A8800: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800A8804: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A8808: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800A880C: b           L_800A88FC
    // 0x800A8810: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_800A88FC;
    // 0x800A8810: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_800A8814:
    // 0x800A8814: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A8818: lui         $t7, 0xDB02
    ctx->r15 = S32(0XDB02 << 16);
    // 0x800A881C: addiu       $t8, $zero, 0x48
    ctx->r24 = ADD32(0, 0X48);
    // 0x800A8820: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800A8824: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800A8828: b           L_800A88FC
    // 0x800A882C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_800A88FC;
    // 0x800A882C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_800A8830:
    // 0x800A8830: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A8834: lui         $t9, 0xDB02
    ctx->r25 = S32(0XDB02 << 16);
    // 0x800A8838: addiu       $t4, $zero, 0x60
    ctx->r12 = ADD32(0, 0X60);
    // 0x800A883C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A8840: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A8844: b           L_800A88FC
    // 0x800A8848: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_800A88FC;
    // 0x800A8848: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_800A884C:
    // 0x800A884C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A8850: lui         $t5, 0xDB02
    ctx->r13 = S32(0XDB02 << 16);
    // 0x800A8854: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x800A8858: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A885C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800A8860: b           L_800A88FC
    // 0x800A8864: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_800A88FC;
    // 0x800A8864: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_800A8868:
    // 0x800A8868: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A886C: lui         $t7, 0xDB02
    ctx->r15 = S32(0XDB02 << 16);
    // 0x800A8870: addiu       $t8, $zero, 0x90
    ctx->r24 = ADD32(0, 0X90);
    // 0x800A8874: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800A8878: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800A887C: b           L_800A88FC
    // 0x800A8880: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_800A88FC;
    // 0x800A8880: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_800A8884:
    // 0x800A8884: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A8888: lui         $t9, 0xDB02
    ctx->r25 = S32(0XDB02 << 16);
    // 0x800A888C: addiu       $t4, $zero, 0xA8
    ctx->r12 = ADD32(0, 0XA8);
    // 0x800A8890: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A8894: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A8898: b           L_800A88FC
    // 0x800A889C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_800A88FC;
    // 0x800A889C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A88A0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_800A88A4:
    // 0x800A88A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A88A8: sw          $a3, -0x6A6C($at)
    MEM_W(-0X6A6C, ctx->r1) = ctx->r7;
    // 0x800A88AC: beq         $v0, $zero, L_800A88FC
    if (ctx->r2 == 0) {
        // 0x800A88B0: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800A88FC;
    }
    // 0x800A88B0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800A88B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A88B8: beq         $v0, $zero, L_800A88FC
    if (ctx->r2 == 0) {
        // 0x800A88BC: sw          $a3, -0x6A6C($at)
        MEM_W(-0X6A6C, ctx->r1) = ctx->r7;
            goto L_800A88FC;
    }
    // 0x800A88BC: sw          $a3, -0x6A6C($at)
    MEM_W(-0X6A6C, ctx->r1) = ctx->r7;
    // 0x800A88C0: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x800A88C4: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x800A88C8: beq         $v1, $zero, L_800A88E8
    if (ctx->r3 == 0) {
        // 0x800A88CC: addu        $v0, $v1, $t1
        ctx->r2 = ADD32(ctx->r3, ctx->r9);
            goto L_800A88E8;
    }
    // 0x800A88CC: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
L_800A88D0:
    // 0x800A88D0: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800A88D4: bne         $v0, $t1, L_800A88D0
    if (ctx->r2 != ctx->r9) {
        // 0x800A88D8: addiu       $a3, $a3, 0x40
        ctx->r7 = ADD32(ctx->r7, 0X40);
            goto L_800A88D0;
    }
    // 0x800A88D8: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x800A88DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A88E0: beq         $t1, $zero, L_800A88FC
    if (ctx->r9 == 0) {
        // 0x800A88E4: sw          $a3, -0x6A6C($at)
        MEM_W(-0X6A6C, ctx->r1) = ctx->r7;
            goto L_800A88FC;
    }
    // 0x800A88E4: sw          $a3, -0x6A6C($at)
    MEM_W(-0X6A6C, ctx->r1) = ctx->r7;
L_800A88E8:
    // 0x800A88E8: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800A88EC: bne         $t1, $zero, L_800A88E8
    if (ctx->r9 != 0) {
        // 0x800A88F0: addiu       $a3, $a3, 0x100
        ctx->r7 = ADD32(ctx->r7, 0X100);
            goto L_800A88E8;
    }
    // 0x800A88F0: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
    // 0x800A88F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A88F8: sw          $a3, -0x6A6C($at)
    MEM_W(-0X6A6C, ctx->r1) = ctx->r7;
L_800A88FC:
    // 0x800A88FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A8900: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800A8904: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A8908: sw          $t3, -0x6A78($at)
    MEM_W(-0X6A78, ctx->r1) = ctx->r11;
    // 0x800A890C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800A8910: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x800A8914: beq         $at, $zero, L_800A8984
    if (ctx->r1 == 0) {
        // 0x800A8918: or          $t1, $t3, $zero
        ctx->r9 = ctx->r11 | 0;
            goto L_800A8984;
    }
    // 0x800A8918: or          $t1, $t3, $zero
    ctx->r9 = ctx->r11 | 0;
    // 0x800A891C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800A8920: subu        $a0, $a1, $t3
    ctx->r4 = SUB32(ctx->r5, ctx->r11);
    // 0x800A8924: andi        $t5, $a0, 0x3
    ctx->r13 = ctx->r4 & 0X3;
    // 0x800A8928: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A892C: beq         $t5, $zero, L_800A895C
    if (ctx->r13 == 0) {
        // 0x800A8930: sw          $t3, -0x6A78($at)
        MEM_W(-0X6A78, ctx->r1) = ctx->r11;
            goto L_800A895C;
    }
    // 0x800A8930: sw          $t3, -0x6A78($at)
    MEM_W(-0X6A78, ctx->r1) = ctx->r11;
    // 0x800A8934: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800A8938: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A893C: sw          $t3, -0x6A78($at)
    MEM_W(-0X6A78, ctx->r1) = ctx->r11;
    // 0x800A8940: addu        $v0, $s3, $t6
    ctx->r2 = ADD32(ctx->r19, ctx->r14);
    // 0x800A8944: addu        $v1, $t5, $t3
    ctx->r3 = ADD32(ctx->r13, ctx->r11);
L_800A8948:
    // 0x800A8948: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800A894C: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800A8950: bne         $v1, $t1, L_800A8948
    if (ctx->r3 != ctx->r9) {
        // 0x800A8954: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800A8948;
    }
    // 0x800A8954: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A8958: beq         $t1, $a1, L_800A8984
    if (ctx->r9 == ctx->r5) {
        // 0x800A895C: sll         $t7, $t1, 2
        ctx->r15 = S32(ctx->r9 << 2);
            goto L_800A8984;
    }
L_800A895C:
    // 0x800A895C: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x800A8960: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800A8964: addiu       $v1, $v1, -0x6BF0
    ctx->r3 = ADD32(ctx->r3, -0X6BF0);
    // 0x800A8968: addu        $v0, $s3, $t7
    ctx->r2 = ADD32(ctx->r19, ctx->r15);
L_800A896C:
    // 0x800A896C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800A8970: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800A8974: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800A8978: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x800A897C: bne         $v0, $v1, L_800A896C
    if (ctx->r2 != ctx->r3) {
        // 0x800A8980: sw          $zero, 0xC($v0)
        MEM_W(0XC, ctx->r2) = 0;
            goto L_800A896C;
    }
    // 0x800A8980: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
L_800A8984:
    // 0x800A8984: jal         0x800A7374
    // 0x800A8988: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800A7374(rdram, ctx);
        goto after_0;
    // 0x800A8988: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x800A898C: lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X4);
    // 0x800A8990: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A8994: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800A8998: lw          $t8, 0x38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X38);
    // 0x800A899C: lw          $t1, 0x14($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X14);
    // 0x800A89A0: sw          $t8, -0x6A24($at)
    MEM_W(-0X6A24, ctx->r1) = ctx->r24;
    // 0x800A89A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A89A8: beq         $t1, $zero, L_800A8F58
    if (ctx->r9 == 0) {
        // 0x800A89AC: sw          $t1, -0x6A80($at)
        MEM_W(-0X6A80, ctx->r1) = ctx->r9;
            goto L_800A8F58;
    }
    // 0x800A89AC: sw          $t1, -0x6A80($at)
    MEM_W(-0X6A80, ctx->r1) = ctx->r9;
    // 0x800A89B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A89B4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800A89B8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800A89BC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A89C0: nop

L_800A89C4:
    // 0x800A89C4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800A89C8: lw          $t9, -0x6A24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6A24);
    // 0x800A89CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A89D0: lh          $v0, 0x0($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X0);
    // 0x800A89D4: sw          $t1, -0x6A80($at)
    MEM_W(-0X6A80, ctx->r1) = ctx->r9;
    // 0x800A89D8: sra         $v1, $v0, 8
    ctx->r3 = S32(SIGNED(ctx->r2) >> 8);
    // 0x800A89DC: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x800A89E0: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x800A89E4: beq         $at, $zero, L_800A8F34
    if (ctx->r1 == 0) {
        // 0x800A89E8: andi        $s0, $v0, 0xFF
        ctx->r16 = ctx->r2 & 0XFF;
            goto L_800A8F34;
    }
    // 0x800A89E8: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800A89EC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A89F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A89F4: addu        $at, $at, $t4
    gpr jr_addend_800A89FC = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800A89F8: lw          $t4, 0xA40($at)
    ctx->r12 = ADD32(ctx->r1, 0XA40);
    // 0x800A89FC: jr          $t4
    // 0x800A8A00: nop

    switch (jr_addend_800A89FC >> 2) {
        case 0: goto L_800A8A4C; break;
        case 1: goto L_800A8AB0; break;
        case 2: goto L_800A8A04; break;
        case 3: goto L_800A8D88; break;
        case 4: goto L_800A8DD0; break;
        default: switch_error(__func__, 0x800A89FC, 0x800E0A40);
    }
    // 0x800A8A00: nop

L_800A8A04:
    // 0x800A8A04: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
    // 0x800A8A08: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x800A8A0C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800A8A10: lw          $v0, 0x34($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X34);
    // 0x800A8A14: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800A8A18: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800A8A1C: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800A8A20: addu        $a0, $v0, $t9
    ctx->r4 = ADD32(ctx->r2, ctx->r25);
    // 0x800A8A24: lh          $a1, 0x6($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X6);
    // 0x800A8A28: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A8A2C: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800A8A30: nop

    // 0x800A8A34: slt         $at, $a1, $s0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800A8A38: beql        $at, $zero, L_800A8A48
    if (ctx->r1 == 0) {
        // 0x800A8A3C: lh          $t4, 0x4($a0)
        ctx->r12 = MEM_H(ctx->r4, 0X4);
            goto L_800A8A48;
    }
    goto skip_12;
    // 0x800A8A3C: lh          $t4, 0x4($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4);
    skip_12:
    // 0x800A8A40: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800A8A44: lh          $t4, 0x4($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4);
L_800A8A48:
    // 0x800A8A48: addu        $s0, $s0, $t4
    ctx->r16 = ADD32(ctx->r16, ctx->r12);
L_800A8A4C:
    // 0x800A8A4C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800A8A50: bne         $s0, $at, L_800A8A78
    if (ctx->r16 != ctx->r1) {
        // 0x800A8A54: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_800A8A78;
    }
    // 0x800A8A54: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A8A58: sw          $zero, 0x10($s3)
    MEM_W(0X10, ctx->r19) = 0;
    // 0x800A8A5C: lui         $t5, 0xD700
    ctx->r13 = S32(0XD700 << 16);
    // 0x800A8A60: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800A8A64: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A8A68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A8A6C: sw          $t1, -0x6A80($at)
    MEM_W(-0X6A80, ctx->r1) = ctx->r9;
    // 0x800A8A70: b           L_800A8AA4
    // 0x800A8A74: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_800A8AA4;
    // 0x800A8A74: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_800A8A78:
    // 0x800A8A78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A8A7C: sw          $t1, -0x6A80($at)
    MEM_W(-0X6A80, ctx->r1) = ctx->r9;
    // 0x800A8A80: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x800A8A84: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x800A8A88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A8A8C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x800A8A90: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A8A94: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x800A8A98: jal         0x800A4B98
    // 0x800A8A9C: sw          $a1, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r5;
    func_800A4B98(rdram, ctx);
        goto after_1;
    // 0x800A8A9C: sw          $a1, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r5;
    after_1:
    // 0x800A8AA0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800A8AA4:
    // 0x800A8AA4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800A8AA8: b           L_800A8F34
    // 0x800A8AAC: lw          $t1, -0x6A80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6A80);
        goto L_800A8F34;
    // 0x800A8AAC: lw          $t1, -0x6A80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6A80);
L_800A8AB0:
    // 0x800A8AB0: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
    // 0x800A8AB4: sll         $t7, $s0, 6
    ctx->r15 = S32(ctx->r16 << 6);
    // 0x800A8AB8: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800A8ABC: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x800A8AC0: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x800A8AC4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A8AC8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A8ACC: sw          $t8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r24;
    // 0x800A8AD0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A8AD4: lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X8);
    // 0x800A8AD8: sll         $t6, $s5, 6
    ctx->r14 = S32(ctx->r21 << 6);
    // 0x800A8ADC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8AE0: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x800A8AE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A8AE8: sll         $t9, $s5, 6
    ctx->r25 = S32(ctx->r21 << 6);
    // 0x800A8AEC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800A8AF0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A8AF4: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x800A8AF8: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x800A8AFC: andi        $t8, $a1, 0x2
    ctx->r24 = ctx->r5 & 0X2;
    // 0x800A8B00: bne         $t8, $zero, L_800A8F34
    if (ctx->r24 != 0) {
        // 0x800A8B04: nop
    
            goto L_800A8F34;
    }
    // 0x800A8B04: nop

    // 0x800A8B08: sw          $t1, -0x6A80($at)
    MEM_W(-0X6A80, ctx->r1) = ctx->r9;
    // 0x800A8B0C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800A8B10: andi        $t4, $a1, 0x200
    ctx->r12 = ctx->r5 & 0X200;
    // 0x800A8B14: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x800A8B18: addiu       $a2, $v0, 0x80
    ctx->r6 = ADD32(ctx->r2, 0X80);
    // 0x800A8B1C: beq         $t4, $zero, L_800A8C80
    if (ctx->r12 == 0) {
        // 0x800A8B20: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800A8C80;
    }
    // 0x800A8B20: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800A8B24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A8B28: sw          $a0, -0x6A28($at)
    MEM_W(-0X6A28, ctx->r1) = ctx->r4;
    // 0x800A8B2C: addiu       $s0, $v0, 0xC0
    ctx->r16 = ADD32(ctx->r2, 0XC0);
    // 0x800A8B30: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800A8B34: lwc1        $f8, 0x7C($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X7C);
    // 0x800A8B38: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800A8B3C: addiu       $a0, $sp, 0x110
    ctx->r4 = ADD32(ctx->r29, 0X110);
    // 0x800A8B40: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A8B44: addiu       $a1, $sp, 0x114
    ctx->r5 = ADD32(ctx->r29, 0X114);
    // 0x800A8B48: addiu       $a2, $sp, 0x118
    ctx->r6 = ADD32(ctx->r29, 0X118);
    // 0x800A8B4C: swc1        $f4, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f4.u32l;
    // 0x800A8B50: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800A8B54: lwc1        $f6, 0x80($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X80);
    // 0x800A8B58: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A8B5C: swc1        $f10, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f10.u32l;
    // 0x800A8B60: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800A8B64: lwc1        $f4, 0x84($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X84);
    // 0x800A8B68: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A8B6C: jal         0x800BA660
    // 0x800A8B70: swc1        $f8, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f8.u32l;
    guNormalize(rdram, ctx);
        goto after_2;
    // 0x800A8B70: swc1        $f8, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x800A8B74: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800A8B78: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    // 0x800A8B7C: addiu       $a1, $sp, 0x104
    ctx->r5 = ADD32(ctx->r29, 0X104);
    // 0x800A8B80: swc1        $f10, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f10.u32l;
    // 0x800A8B84: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800A8B88: addiu       $a2, $sp, 0x110
    ctx->r6 = ADD32(ctx->r29, 0X110);
    // 0x800A8B8C: swc1        $f4, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f4.u32l;
    // 0x800A8B90: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800A8B94: jal         0x800AFF34
    // 0x800A8B98: swc1        $f6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f6.u32l;
    vec3_cross(rdram, ctx);
        goto after_3;
    // 0x800A8B98: swc1        $f6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x800A8B9C: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    // 0x800A8BA0: addiu       $a1, $sp, 0xFC
    ctx->r5 = ADD32(ctx->r29, 0XFC);
    // 0x800A8BA4: jal         0x800BA660
    // 0x800A8BA8: addiu       $a2, $sp, 0x100
    ctx->r6 = ADD32(ctx->r29, 0X100);
    guNormalize(rdram, ctx);
        goto after_4;
    // 0x800A8BA8: addiu       $a2, $sp, 0x100
    ctx->r6 = ADD32(ctx->r29, 0X100);
    after_4:
    // 0x800A8BAC: addiu       $a0, $sp, 0x110
    ctx->r4 = ADD32(ctx->r29, 0X110);
    // 0x800A8BB0: addiu       $a1, $sp, 0xF8
    ctx->r5 = ADD32(ctx->r29, 0XF8);
    // 0x800A8BB4: jal         0x800AFF34
    // 0x800A8BB8: addiu       $a2, $sp, 0x104
    ctx->r6 = ADD32(ctx->r29, 0X104);
    vec3_cross(rdram, ctx);
        goto after_5;
    // 0x800A8BB8: addiu       $a2, $sp, 0x104
    ctx->r6 = ADD32(ctx->r29, 0X104);
    after_5:
    // 0x800A8BBC: lwc1        $f8, 0x28($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800A8BC0: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800A8BC4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A8BC8: lw          $a0, -0x6A28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A28);
    // 0x800A8BCC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A8BD0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800A8BD4: lwc1        $f6, 0x28($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800A8BD8: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800A8BDC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A8BE0: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800A8BE4: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800A8BE8: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800A8BEC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A8BF0: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x800A8BF4: lwc1        $f10, 0x2C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800A8BF8: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800A8BFC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A8C00: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x800A8C04: lwc1        $f8, 0x2C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800A8C08: lwc1        $f10, 0x108($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800A8C0C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A8C10: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x800A8C14: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800A8C18: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800A8C1C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A8C20: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x800A8C24: lwc1        $f4, 0x30($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800A8C28: lwc1        $f6, 0x110($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800A8C2C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A8C30: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x800A8C34: lwc1        $f10, 0x30($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800A8C38: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800A8C3C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A8C40: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x800A8C44: lwc1        $f10, 0x118($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800A8C48: lwc1        $f8, 0x30($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800A8C4C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A8C50: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x800A8C54: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800A8C58: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x800A8C5C: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800A8C60: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x800A8C64: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800A8C68: swc1        $f26, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f26.u32l;
    // 0x800A8C6C: swc1        $f24, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f24.u32l;
    // 0x800A8C70: swc1        $f24, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f24.u32l;
    // 0x800A8C74: swc1        $f24, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f24.u32l;
    // 0x800A8C78: b           L_800A8CB8
    // 0x800A8C7C: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
        goto L_800A8CB8;
    // 0x800A8C7C: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
L_800A8C80:
    // 0x800A8C80: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x800A8C84: or          $t8, $a2, $zero
    ctx->r24 = ctx->r6 | 0;
    // 0x800A8C88: addiu       $t6, $v0, 0x3C
    ctx->r14 = ADD32(ctx->r2, 0X3C);
L_800A8C8C:
    // 0x800A8C8C: lw          $at, 0xC0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0XC0);
    // 0x800A8C90: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800A8C94: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800A8C98: sw          $at, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r1;
    // 0x800A8C9C: lw          $at, 0xB8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0XB8);
    // 0x800A8CA0: sw          $at, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r1;
    // 0x800A8CA4: lw          $at, 0xBC($t7)
    ctx->r1 = MEM_W(ctx->r15, 0XBC);
    // 0x800A8CA8: bne         $t7, $t6, L_800A8C8C
    if (ctx->r15 != ctx->r14) {
        // 0x800A8CAC: sw          $at, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r1;
            goto L_800A8C8C;
    }
    // 0x800A8CAC: sw          $at, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r1;
    // 0x800A8CB0: lw          $at, 0xC0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0XC0);
    // 0x800A8CB4: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
L_800A8CB8:
    // 0x800A8CB8: lw          $t9, 0xC($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XC);
    // 0x800A8CBC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A8CC0: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800A8CC4: lwc1        $f0, 0x18($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X18);
    // 0x800A8CC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A8CCC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A8CD0: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800A8CD4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A8CD8: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800A8CDC: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800A8CE0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A8CE4: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800A8CE8: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800A8CEC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A8CF0: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800A8CF4: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x800A8CF8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A8CFC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800A8D00: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800A8D04: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A8D08: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800A8D0C: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x800A8D10: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A8D14: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800A8D18: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x800A8D1C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A8D20: lwc1        $f8, 0x30($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800A8D24: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x800A8D28: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A8D2C: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800A8D30: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x800A8D34: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800A8D38: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800A8D3C: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x800A8D40: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800A8D44: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x800A8D48: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800A8D4C: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x800A8D50: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x800A8D54: lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X8);
    // 0x800A8D58: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800A8D5C: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x800A8D60: sw          $a0, -0x6A28($at)
    MEM_W(-0X6A28, ctx->r1) = ctx->r4;
    // 0x800A8D64: jal         0x800B78D0
    // 0x800A8D68: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    guMtxF2L(rdram, ctx);
        goto after_6;
    // 0x800A8D68: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_6:
    // 0x800A8D6C: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x800A8D70: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800A8D74: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x800A8D78: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x800A8D7C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x800A8D80: b           L_800A8F34
    // 0x800A8D84: lw          $t1, -0x6A80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6A80);
        goto L_800A8F34;
    // 0x800A8D84: lw          $t1, -0x6A80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6A80);
L_800A8D88:
    // 0x800A8D88: lw          $t9, 0x4($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X4);
    // 0x800A8D8C: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x800A8D90: lui         $t8, 0xDB06
    ctx->r24 = S32(0XDB06 << 16);
    // 0x800A8D94: lw          $t4, 0x2C($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X2C);
    // 0x800A8D98: ori         $t8, $t8, 0x28
    ctx->r24 = ctx->r24 | 0X28;
    // 0x800A8D9C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x800A8DA0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800A8DA4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800A8DA8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8DAC: sw          $t7, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r15;
    // 0x800A8DB0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800A8DB4: lw          $t9, 0xC($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XC);
    // 0x800A8DB8: jal         0x800B87A0
    // 0x800A8DBC: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_7;
    // 0x800A8DBC: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    after_7:
    // 0x800A8DC0: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x800A8DC4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800A8DC8: b           L_800A8F34
    // 0x800A8DCC: lw          $t1, -0x6A80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6A80);
        goto L_800A8F34;
    // 0x800A8DCC: lw          $t1, -0x6A80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6A80);
L_800A8DD0:
    // 0x800A8DD0: lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC);
    // 0x800A8DD4: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x800A8DD8: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x800A8DDC: lw          $t4, 0x2C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X2C);
    // 0x800A8DE0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A8DE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A8DE8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800A8DEC: sw          $t6, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r14;
    // 0x800A8DF0: beq         $t6, $zero, L_800A8F2C
    if (ctx->r14 == 0) {
        // 0x800A8DF4: sw          $t1, -0x6A80($at)
        MEM_W(-0X6A80, ctx->r1) = ctx->r9;
            goto L_800A8F2C;
    }
    // 0x800A8DF4: sw          $t1, -0x6A80($at)
    MEM_W(-0X6A80, ctx->r1) = ctx->r9;
    // 0x800A8DF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A8DFC: sw          $t1, -0x6A80($at)
    MEM_W(-0X6A80, ctx->r1) = ctx->r9;
    // 0x800A8E00: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800A8E04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A8E08: c.lt.s      $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f4.fl < ctx->f22.fl;
    // 0x800A8E0C: nop

    // 0x800A8E10: bc1f        L_800A8F2C
    if (!c1cs) {
        // 0x800A8E14: nop
    
            goto L_800A8F2C;
    }
    // 0x800A8E14: nop

    // 0x800A8E18: sw          $t1, -0x6A80($at)
    MEM_W(-0X6A80, ctx->r1) = ctx->r9;
    // 0x800A8E1C: lwl         $t7, 0x10($t6)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r14, 0X10);
    // 0x800A8E20: lwr         $t7, 0x13($t6)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r14, 0X13);
    // 0x800A8E24: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800A8E28: nop

    // 0x800A8E2C: c.lt.s      $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f6.fl < ctx->f22.fl;
    // 0x800A8E30: nop

    // 0x800A8E34: bc1f        L_800A8F2C
    if (!c1cs) {
        // 0x800A8E38: nop
    
            goto L_800A8F2C;
    }
    // 0x800A8E38: nop

    // 0x800A8E3C: jal         0x800A74DC
    // 0x800A8E40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800A74DC(rdram, ctx);
        goto after_8;
    // 0x800A8E40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x800A8E44: lw          $t8, 0x14($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X14);
    // 0x800A8E48: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800A8E4C: lwl         $t9, 0x0($t8)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r24, 0X0);
    // 0x800A8E50: lwr         $t9, 0x3($t8)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r24, 0X3);
    // 0x800A8E54: andi        $t4, $t9, 0x1
    ctx->r12 = ctx->r25 & 0X1;
    // 0x800A8E58: beql        $t4, $zero, L_800A8F04
    if (ctx->r12 == 0) {
        // 0x800A8E5C: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_800A8F04;
    }
    goto skip_13;
    // 0x800A8E5C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    skip_13:
    // 0x800A8E60: lw          $t5, 0xC($s3)
    ctx->r13 = MEM_W(ctx->r19, 0XC);
    // 0x800A8E64: lwc1        $f8, 0x84($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X84);
    // 0x800A8E68: lw          $t7, 0x8($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X8);
    // 0x800A8E6C: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x800A8E70: lw          $a2, 0x7C($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X7C);
    // 0x800A8E74: lw          $a3, 0x80($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X80);
    // 0x800A8E78: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800A8E7C: lw          $v0, 0xC($t7)
    ctx->r2 = MEM_W(ctx->r15, 0XC);
    // 0x800A8E80: sll         $s1, $s5, 5
    ctx->r17 = S32(ctx->r21 << 5);
    // 0x800A8E84: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x800A8E88: lwc1        $f10, 0xF0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x800A8E8C: addu        $a1, $t6, $s1
    ctx->r5 = ADD32(ctx->r14, ctx->r17);
    // 0x800A8E90: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800A8E94: lwc1        $f4, 0xF4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XF4);
    // 0x800A8E98: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800A8E9C: lwc1        $f6, 0xF8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XF8);
    // 0x800A8EA0: swc1        $f24, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f24.u32l;
    // 0x800A8EA4: swc1        $f26, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f26.u32l;
    // 0x800A8EA8: swc1        $f24, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f24.u32l;
    // 0x800A8EAC: jal         0x800BAD0C
    // 0x800A8EB0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    guLookAtReflect(rdram, ctx);
        goto after_9;
    // 0x800A8EB0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x800A8EB4: lui         $t8, 0xDC08
    ctx->r24 = S32(0XDC08 << 16);
    // 0x800A8EB8: ori         $t8, $t8, 0xA
    ctx->r24 = ctx->r24 | 0XA;
    // 0x800A8EBC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A8EC0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A8EC4: lw          $t9, 0xC($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XC);
    // 0x800A8EC8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8ECC: lui         $t6, 0xDC08
    ctx->r14 = S32(0XDC08 << 16);
    // 0x800A8ED0: lw          $t4, 0x8($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X8);
    // 0x800A8ED4: ori         $t6, $t6, 0x30A
    ctx->r14 = ctx->r14 | 0X30A;
    // 0x800A8ED8: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A8EDC: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x800A8EE0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800A8EE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800A8EE8: lw          $t7, 0xC($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XC);
    // 0x800A8EEC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8EF0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800A8EF4: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800A8EF8: addiu       $t4, $t9, 0x10
    ctx->r12 = ADD32(ctx->r25, 0X10);
    // 0x800A8EFC: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800A8F00: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_800A8F04:
    // 0x800A8F04: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x800A8F08: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800A8F0C: lw          $t6, 0xC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XC);
    // 0x800A8F10: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x800A8F14: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800A8F18: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x800A8F1C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A8F20: jal         0x800B87A0
    // 0x800A8F24: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_10;
    // 0x800A8F24: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_10:
    // 0x800A8F28: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
L_800A8F2C:
    // 0x800A8F2C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800A8F30: lw          $t1, -0x6A80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6A80);
L_800A8F34:
    // 0x800A8F34: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800A8F38: lw          $t4, -0x6A24($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6A24);
    // 0x800A8F3C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800A8F40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A8F44: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x800A8F48: bne         $t1, $zero, L_800A89C4
    if (ctx->r9 != 0) {
        // 0x800A8F4C: sw          $t5, -0x6A24($at)
        MEM_W(-0X6A24, ctx->r1) = ctx->r13;
            goto L_800A89C4;
    }
    // 0x800A8F4C: sw          $t5, -0x6A24($at)
    MEM_W(-0X6A24, ctx->r1) = ctx->r13;
    // 0x800A8F50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A8F54: sw          $t1, -0x6A80($at)
    MEM_W(-0X6A80, ctx->r1) = ctx->r9;
L_800A8F58:
    // 0x800A8F58: lbu         $t6, 0x4($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X4);
    // 0x800A8F5C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800A8F60: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x800A8F64: sb          $t7, 0x4($s4)
    MEM_B(0X4, ctx->r20) = ctx->r15;
    // 0x800A8F68: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800A8F6C: sw          $zero, 0x4($s3)
    MEM_W(0X4, ctx->r19) = 0;
    // 0x800A8F70: lw          $s3, 0x60($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X60);
    // 0x800A8F74: lw          $s5, 0x68($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X68);
    // 0x800A8F78: lw          $s4, 0x64($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X64);
    // 0x800A8F7C: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x800A8F80: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x800A8F84: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x800A8F88: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800A8F8C: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800A8F90: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800A8F94: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800A8F98: jr          $ra
    // 0x800A8F9C: addiu       $sp, $sp, 0x1D0
    ctx->r29 = ADD32(ctx->r29, 0X1D0);
    return;
    // 0x800A8F9C: addiu       $sp, $sp, 0x1D0
    ctx->r29 = ADD32(ctx->r29, 0X1D0);
;}

RECOMP_FUNC void func_800A8FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8FA0: beq         $a2, $zero, L_800A8FBC
    if (ctx->r6 == 0) {
        // 0x800A8FA4: add         $t0, $a2, $a1
        ctx->r8 = ADD32(ctx->r6, ctx->r5);
            goto L_800A8FBC;
    }
    // 0x800A8FA4: add         $t0, $a2, $a1
    ctx->r8 = ADD32(ctx->r6, ctx->r5);
L_800A8FA8:
    // 0x800A8FA8: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800A8FAC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800A8FB0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800A8FB4: bne         $a1, $t0, L_800A8FA8
    if (ctx->r5 != ctx->r8) {
        // 0x800A8FB8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A8FA8;
    }
    // 0x800A8FB8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800A8FBC:
    // 0x800A8FBC: add         $v0, $zero, $a0
    ctx->r2 = ADD32(0, ctx->r4);
    // 0x800A8FC0: jr          $ra
    // 0x800A8FC4: nop

    return;
    // 0x800A8FC4: nop

;}

RECOMP_FUNC void func_800A8FC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8FC8: beq         $a1, $zero, L_800A8FDC
    if (ctx->r5 == 0) {
        // 0x800A8FCC: sh          $a2, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r6;
            goto L_800A8FDC;
    }
L_800A8FCC:
    // 0x800A8FCC: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
    // 0x800A8FD0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800A8FD4: bne         $a1, $zero, L_800A8FCC
    if (ctx->r5 != 0) {
        // 0x800A8FD8: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800A8FCC;
    }
    // 0x800A8FD8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_800A8FDC:
    // 0x800A8FDC: add         $v0, $zero, $a0
    ctx->r2 = ADD32(0, ctx->r4);
    // 0x800A8FE0: jr          $ra
    // 0x800A8FE4: nop

    return;
    // 0x800A8FE4: nop

;}

RECOMP_FUNC void func_800A8FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8FE8: beq         $a2, $zero, L_800A8FFC
    if (ctx->r6 == 0) {
        // 0x800A8FEC: add         $t0, $a2, $a0
        ctx->r8 = ADD32(ctx->r6, ctx->r4);
            goto L_800A8FFC;
    }
    // 0x800A8FEC: add         $t0, $a2, $a0
    ctx->r8 = ADD32(ctx->r6, ctx->r4);
L_800A8FF0:
    // 0x800A8FF0: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x800A8FF4: bne         $a0, $t0, L_800A8FF0
    if (ctx->r4 != ctx->r8) {
        // 0x800A8FF8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800A8FF0;
    }
    // 0x800A8FF8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800A8FFC:
    // 0x800A8FFC: add         $v0, $zero, $a0
    ctx->r2 = ADD32(0, ctx->r4);
    // 0x800A9000: jr          $ra
    // 0x800A9004: nop

    return;
    // 0x800A9004: nop

    // 0x800A9008: nop

    // 0x800A900C: nop

;}

RECOMP_FUNC void CubeTiles_ObjInstantiate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA14C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800AA150: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AA154: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AA158: bltz        $a0, L_800AA17C
    if (SIGNED(ctx->r4) < 0) {
        // 0x800AA15C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800AA17C;
    }
    // 0x800AA15C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800AA160: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800AA164: lw          $t6, -0x69F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X69F8);
    // 0x800AA168: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
    // 0x800AA16C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800AA170: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AA174: bne         $at, $zero, L_800AA184
    if (ctx->r1 != 0) {
        // 0x800AA178: addiu       $a1, $sp, 0x48
        ctx->r5 = ADD32(ctx->r29, 0X48);
            goto L_800AA184;
    }
    // 0x800AA178: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
L_800AA17C:
    // 0x800AA17C: b           L_800AA3C8
    // 0x800AA180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AA3C8;
    // 0x800AA180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AA184:
    // 0x800AA184: lw          $t8, -0x6A00($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6A00);
    // 0x800AA188: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AA18C: sw          $a3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r7;
    // 0x800AA190: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800AA194: jal         0x800ABFF0
    // 0x800AA198: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    Main_RequestRomDma(rdram, ctx);
        goto after_0;
    // 0x800AA198: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x800AA19C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800AA1A0: lw          $t9, 0x7B04($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B04);
    // 0x800AA1A4: lh          $t0, 0x48($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X48);
    // 0x800AA1A8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800AA1AC: beq         $t9, $zero, L_800AA288
    if (ctx->r25 == 0) {
        // 0x800AA1B0: sll         $t1, $t0, 2
        ctx->r9 = S32(ctx->r8 << 2);
            goto L_800AA288;
    }
    // 0x800AA1B0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800AA1B4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800AA1B8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800AA1BC: lw          $t2, 0x7B70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B70);
    // 0x800AA1C0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800AA1C4: jal         0x8007E03C
    // 0x800AA1C8: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800AA1C8: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x800AA1CC: lh          $t6, 0x48($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X48);
    // 0x800AA1D0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800AA1D4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800AA1D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AA1DC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800AA1E0: lw          $t4, -0x69FC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X69FC);
    // 0x800AA1E4: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800AA1E8: lw          $t8, 0x7B70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B70);
    // 0x800AA1EC: lh          $t9, 0x4A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4A);
    // 0x800AA1F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800AA1F4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800AA1F8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800AA1FC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x800AA200: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    // 0x800AA204: jal         0x800A9F9C
    // 0x800AA208: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800A9F9C(rdram, ctx);
        goto after_2;
    // 0x800AA208: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_2:
    // 0x800AA20C: lh          $a0, 0x48($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X48);
    // 0x800AA210: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA214: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x800AA218: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800AA21C: lw          $v1, 0x7B08($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7B08);
    // 0x800AA220: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800AA224: beq         $v1, $zero, L_800AA240
    if (ctx->r3 == 0) {
        // 0x800AA228: nop
    
            goto L_800AA240;
    }
    // 0x800AA228: nop

    // 0x800AA22C: jalr        $v1
    // 0x800AA230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_3;
    // 0x800AA230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800AA234: lh          $a0, 0x48($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X48);
    // 0x800AA238: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x800AA23C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
L_800AA240:
    // 0x800AA240: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA244: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800AA248: lw          $v0, 0x7B3C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B3C);
    // 0x800AA24C: beql        $v0, $zero, L_800AA260
    if (ctx->r2 == 0) {
        // 0x800AA250: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_800AA260;
    }
    goto skip_0;
    // 0x800AA250: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    skip_0:
    // 0x800AA254: jalr        $v0
    // 0x800AA258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x800AA258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800AA25C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_800AA260:
    // 0x800AA260: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x800AA264: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800AA268: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x800AA26C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800AA270: lw          $t3, 0x7B00($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B00);
    // 0x800AA274: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800AA278: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AA27C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800AA280: b           L_800AA3C8
    // 0x800AA284: sw          $s0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r16;
        goto L_800AA3C8;
    // 0x800AA284: sw          $s0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r16;
L_800AA288:
    // 0x800AA288: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800AA28C: lw          $t9, 0x7B00($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B00);
    // 0x800AA290: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800AA294: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800AA298: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x800AA29C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800AA2A0: lh          $t6, 0x48($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X48);
    // 0x800AA2A4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800AA2A8: beq         $a0, $zero, L_800AA2F4
    if (ctx->r4 == 0) {
        // 0x800AA2AC: sll         $t7, $t6, 2
        ctx->r15 = S32(ctx->r14 << 2);
            goto L_800AA2F4;
    }
    // 0x800AA2AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AA2B0: addiu       $t0, $a0, 0x1
    ctx->r8 = ADD32(ctx->r4, 0X1);
    // 0x800AA2B4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800AA2B8: lh          $t1, 0x48($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X48);
    // 0x800AA2BC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA2C0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800AA2C4: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800AA2C8: lw          $v0, 0x7B3C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B3C);
    // 0x800AA2CC: beq         $v0, $zero, L_800AA2DC
    if (ctx->r2 == 0) {
        // 0x800AA2D0: nop
    
            goto L_800AA2DC;
    }
    // 0x800AA2D0: nop

    // 0x800AA2D4: jalr        $v0
    // 0x800AA2D8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x800AA2D8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_5:
L_800AA2DC:
    // 0x800AA2DC: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800AA2E0: lw          $t4, 0x7B00($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B00);
    // 0x800AA2E4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800AA2E8: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x800AA2EC: b           L_800AA3C8
    // 0x800AA2F0: lw          $v0, 0x4($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X4);
        goto L_800AA3C8;
    // 0x800AA2F0: lw          $v0, 0x4($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X4);
L_800AA2F4:
    // 0x800AA2F4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800AA2F8: lw          $t9, 0x7B70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B70);
    // 0x800AA2FC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800AA300: jal         0x8007E03C
    // 0x800AA304: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    n64HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x800AA304: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_6:
    // 0x800AA308: lh          $t2, 0x48($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X48);
    // 0x800AA30C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800AA310: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800AA314: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800AA318: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x800AA31C: lw          $t0, -0x69FC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X69FC);
    // 0x800AA320: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800AA324: lw          $t3, 0x7B70($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B70);
    // 0x800AA328: lh          $t5, 0x4A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X4A);
    // 0x800AA32C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800AA330: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800AA334: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800AA338: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x800AA33C: addu        $a2, $t3, $v0
    ctx->r6 = ADD32(ctx->r11, ctx->r2);
    // 0x800AA340: jal         0x800A9F9C
    // 0x800AA344: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800A9F9C(rdram, ctx);
        goto after_7;
    // 0x800AA344: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_7:
    // 0x800AA348: lh          $a0, 0x48($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X48);
    // 0x800AA34C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA350: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800AA354: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800AA358: lw          $v1, 0x7B08($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7B08);
    // 0x800AA35C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800AA360: beq         $v1, $zero, L_800AA37C
    if (ctx->r3 == 0) {
        // 0x800AA364: nop
    
            goto L_800AA37C;
    }
    // 0x800AA364: nop

    // 0x800AA368: jalr        $v1
    // 0x800AA36C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_8;
    // 0x800AA36C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800AA370: lh          $a0, 0x48($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X48);
    // 0x800AA374: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800AA378: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800AA37C:
    // 0x800AA37C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA380: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800AA384: lw          $v0, 0x7B3C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B3C);
    // 0x800AA388: beql        $v0, $zero, L_800AA39C
    if (ctx->r2 == 0) {
        // 0x800AA38C: lw          $t9, 0x60($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X60);
            goto L_800AA39C;
    }
    goto skip_1;
    // 0x800AA38C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x800AA390: jalr        $v0
    // 0x800AA394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_9;
    // 0x800AA394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800AA398: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
L_800AA39C:
    // 0x800AA39C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800AA3A0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800AA3A4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AA3A8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800AA3AC: lw          $t0, 0x7B00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7B00);
    // 0x800AA3B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800AA3B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AA3B8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800AA3BC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x800AA3C0: addu        $t4, $t0, $t1
    ctx->r12 = ADD32(ctx->r8, ctx->r9);
    // 0x800AA3C4: sw          $s0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r16;
L_800AA3C8:
    // 0x800AA3C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AA3CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800AA3D0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800AA3D4: jr          $ra
    // 0x800AA3D8: nop

    return;
    // 0x800AA3D8: nop

;}

RECOMP_FUNC void func_800AA3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA3DC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800AA3E0: lw          $t6, 0x7B00($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B00);
    // 0x800AA3E4: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800AA3E8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AA3EC: jr          $ra
    // 0x800AA3F0: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    return;
    // 0x800AA3F0: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
;}

RECOMP_FUNC void func_800AA3F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA3F4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800AA3F8: addiu       $a1, $a1, 0x7B00
    ctx->r5 = ADD32(ctx->r5, 0X7B00);
    // 0x800AA3FC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800AA400: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AA404: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x800AA408: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA40C: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x800AA410: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800AA414: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800AA418: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AA41C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800AA420: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x800AA424: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800AA428: beql        $t0, $zero, L_800AA43C
    if (ctx->r8 == 0) {
        // 0x800AA42C: lw          $a0, 0x4($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X4);
            goto L_800AA43C;
    }
    goto skip_0;
    // 0x800AA42C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x800AA430: b           L_800AA460
    // 0x800AA434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AA460;
    // 0x800AA434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AA438: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
L_800AA43C:
    // 0x800AA43C: jal         0x8007E328
    // 0x800AA440: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA440: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800AA444: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800AA448: addiu       $a1, $a1, 0x7B00
    ctx->r5 = ADD32(ctx->r5, 0X7B00);
    // 0x800AA44C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA450: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800AA454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AA458: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x800AA45C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_800AA460:
    // 0x800AA460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA464: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AA468: jr          $ra
    // 0x800AA46C: nop

    return;
    // 0x800AA46C: nop

;}

RECOMP_FUNC void func_800AA470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA470: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800AA474: lw          $t6, 0x7B00($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B00);
    // 0x800AA478: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AA47C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800AA480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA484: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800AA488: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AA48C: beql        $t8, $zero, L_800AA508
    if (ctx->r24 == 0) {
        // 0x800AA490: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AA508;
    }
    goto skip_0;
    // 0x800AA490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800AA494: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800AA498: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800AA49C: jal         0x800AA038
    // 0x800AA4A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800AA038(rdram, ctx);
        goto after_0;
    // 0x800AA4A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800AA4A4: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x800AA4A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800AA4AC: beq         $at, $zero, L_800AA504
    if (ctx->r1 == 0) {
        // 0x800AA4B0: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_800AA504;
    }
    // 0x800AA4B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA4B4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800AA4B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AA4BC: addu        $at, $at, $t9
    gpr jr_addend_800AA4C4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AA4C0: lw          $t9, 0x1128($at)
    ctx->r25 = ADD32(ctx->r1, 0X1128);
    // 0x800AA4C4: jr          $t9
    // 0x800AA4C8: nop

    switch (jr_addend_800AA4C4 >> 2) {
        case 0: goto L_800AA4CC; break;
        case 1: goto L_800AA4CC; break;
        case 2: goto L_800AA4DC; break;
        case 3: goto L_800AA4CC; break;
        case 4: goto L_800AA4CC; break;
        case 5: goto L_800AA4EC; break;
        case 6: goto L_800AA4FC; break;
        default: switch_error(__func__, 0x800AA4C4, 0x800E1128);
    }
    // 0x800AA4C8: nop

L_800AA4CC:
    // 0x800AA4CC: jal         0x800AA3F4
    // 0x800AA4D0: nop

    func_800AA3F4(rdram, ctx);
        goto after_1;
    // 0x800AA4D0: nop

    after_1:
    // 0x800AA4D4: b           L_800AA508
    // 0x800AA4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA508;
    // 0x800AA4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA4DC:
    // 0x800AA4DC: jal         0x800AA874
    // 0x800AA4E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA874(rdram, ctx);
        goto after_2;
    // 0x800AA4E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800AA4E4: b           L_800AA508
    // 0x800AA4E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA508;
    // 0x800AA4E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA4EC:
    // 0x800AA4EC: jal         0x800AB5E0
    // 0x800AA4F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AB5E0(rdram, ctx);
        goto after_3;
    // 0x800AA4F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x800AA4F4: b           L_800AA508
    // 0x800AA4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA508;
    // 0x800AA4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA4FC:
    // 0x800AA4FC: jal         0x800AB934
    // 0x800AA500: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AB934(rdram, ctx);
        goto after_4;
    // 0x800AA500: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
L_800AA504:
    // 0x800AA504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA508:
    // 0x800AA508: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AA50C: jr          $ra
    // 0x800AA510: nop

    return;
    // 0x800AA510: nop

;}

RECOMP_FUNC void func_800AA514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA514: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800AA518: lw          $v1, -0x69F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69F8);
    // 0x800AA51C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AA520: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AA524: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AA528: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AA52C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AA530: blez        $v1, L_800AA590
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800AA534: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800AA590;
    }
    // 0x800AA534: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800AA538: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800AA53C: addiu       $s1, $s1, 0x7B00
    ctx->r17 = ADD32(ctx->r17, 0X7B00);
    // 0x800AA540: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AA544:
    // 0x800AA544: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800AA548: addu        $v0, $t6, $s0
    ctx->r2 = ADD32(ctx->r14, ctx->r16);
    // 0x800AA54C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800AA550: beql        $t7, $zero, L_800AA584
    if (ctx->r15 == 0) {
        // 0x800AA554: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800AA584;
    }
    goto skip_0;
    // 0x800AA554: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800AA558: jal         0x8007E328
    // 0x800AA55C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA55C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_0:
    // 0x800AA560: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800AA564: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800AA568: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800AA56C: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800AA570: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800AA574: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x800AA578: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AA57C: lw          $v1, -0x69F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69F8);
    // 0x800AA580: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800AA584:
    // 0x800AA584: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AA588: bne         $at, $zero, L_800AA544
    if (ctx->r1 != 0) {
        // 0x800AA58C: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_800AA544;
    }
    // 0x800AA58C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800AA590:
    // 0x800AA590: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AA594: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AA598: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA59C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AA5A0: jr          $ra
    // 0x800AA5A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AA5A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800AA5A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA5A8: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800AA5AC: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800AA5B0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AA5B4: jr          $ra
    // 0x800AA5B8: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    return;
    // 0x800AA5B8: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
;}

RECOMP_FUNC void func_800AA5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA5BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AA5C0: jr          $ra
    // 0x800AA5C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AA5C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AA5C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA5C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA5CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA5D0: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800AA5D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA5D8: bne         $a1, $at, L_800AA5F0
    if (ctx->r5 != ctx->r1) {
        // 0x800AA5DC: nop
    
            goto L_800AA5F0;
    }
    // 0x800AA5DC: nop

    // 0x800AA5E0: jal         0x8007E328
    // 0x800AA5E4: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA5E4: nop

    after_0:
    // 0x800AA5E8: b           L_800AA5FC
    // 0x800AA5EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA5FC;
    // 0x800AA5EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA5F0:
    // 0x800AA5F0: jal         0x800AA3F4
    // 0x800AA5F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA3F4(rdram, ctx);
        goto after_1;
    // 0x800AA5F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800AA5F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA5FC:
    // 0x800AA5FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA600: jr          $ra
    // 0x800AA604: nop

    return;
    // 0x800AA604: nop

;}

RECOMP_FUNC void CubeTiles_ObjRelocatePtrs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA608: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800AA60C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800AA610: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800AA614: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x800AA618: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AA61C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800AA620: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x800AA624: jr          $ra
    // 0x800AA628: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    return;
    // 0x800AA628: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
;}

RECOMP_FUNC void func_800AA62C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA62C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AA630: jr          $ra
    // 0x800AA634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AA634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AA638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA63C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA640: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800AA644: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA648: bne         $a1, $at, L_800AA660
    if (ctx->r5 != ctx->r1) {
        // 0x800AA64C: nop
    
            goto L_800AA660;
    }
    // 0x800AA64C: nop

    // 0x800AA650: jal         0x8007E328
    // 0x800AA654: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA654: nop

    after_0:
    // 0x800AA658: b           L_800AA66C
    // 0x800AA65C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA66C;
    // 0x800AA65C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA660:
    // 0x800AA660: jal         0x800AA3F4
    // 0x800AA664: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA3F4(rdram, ctx);
        goto after_1;
    // 0x800AA664: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800AA668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA66C:
    // 0x800AA66C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA670: jr          $ra
    // 0x800AA674: nop

    return;
    // 0x800AA674: nop

;}

RECOMP_FUNC void CubeTiles_ObjRelocatePtrArray(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA678: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x800AA67C: lw          $t9, 0x20($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X20);
    // 0x800AA680: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x800AA684: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x800AA688: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800AA68C: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x800AA690: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x800AA694: addiu       $v0, $t7, 0x10
    ctx->r2 = ADD32(ctx->r15, 0X10);
    // 0x800AA698: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800AA69C: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x800AA6A0: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x800AA6A4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x800AA6A8: beq         $v1, $zero, L_800AA730
    if (ctx->r3 == 0) {
        // 0x800AA6AC: sw          $t4, 0x2C($a0)
        MEM_W(0X2C, ctx->r4) = ctx->r12;
            goto L_800AA730;
    }
    // 0x800AA6AC: sw          $t4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r12;
    // 0x800AA6B0: andi        $a2, $v1, 0x3
    ctx->r6 = ctx->r3 & 0X3;
    // 0x800AA6B4: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800AA6B8: beq         $a2, $zero, L_800AA6E4
    if (ctx->r6 == 0) {
        // 0x800AA6BC: addu        $a1, $a2, $v1
        ctx->r5 = ADD32(ctx->r6, ctx->r3);
            goto L_800AA6E4;
    }
    // 0x800AA6BC: addu        $a1, $a2, $v1
    ctx->r5 = ADD32(ctx->r6, ctx->r3);
L_800AA6C0:
    // 0x800AA6C0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800AA6C4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AA6C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AA6CC: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x800AA6D0: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800AA6D4: bne         $a1, $v1, L_800AA6C0
    if (ctx->r5 != ctx->r3) {
        // 0x800AA6D8: sw          $t7, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r15;
            goto L_800AA6C0;
    }
    // 0x800AA6D8: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x800AA6DC: beql        $v1, $zero, L_800AA734
    if (ctx->r3 == 0) {
        // 0x800AA6E0: lw          $t0, 0x28($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X28);
            goto L_800AA734;
    }
    goto skip_0;
    // 0x800AA6E0: lw          $t0, 0x28($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X28);
    skip_0:
L_800AA6E4:
    // 0x800AA6E4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AA6E8: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800AA6EC: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x800AA6F0: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800AA6F4: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x800AA6F8: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x800AA6FC: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x800AA700: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x800AA704: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800AA708: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800AA70C: addiu       $t6, $t5, 0x10
    ctx->r14 = ADD32(ctx->r13, 0X10);
    // 0x800AA710: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x800AA714: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800AA718: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800AA71C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x800AA720: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x800AA724: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800AA728: bne         $v1, $zero, L_800AA6E4
    if (ctx->r3 != 0) {
        // 0x800AA72C: sw          $t0, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->r8;
            goto L_800AA6E4;
    }
    // 0x800AA72C: sw          $t0, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r8;
L_800AA730:
    // 0x800AA730: lw          $t0, 0x28($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X28);
L_800AA734:
    // 0x800AA734: beq         $t0, $zero, L_800AA85C
    if (ctx->r8 == 0) {
        // 0x800AA738: nop
    
            goto L_800AA85C;
    }
    // 0x800AA738: nop

    // 0x800AA73C: lw          $t1, 0x28($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X28);
    // 0x800AA740: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x800AA744: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x800AA748: sw          $t3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r11;
    // 0x800AA74C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800AA750: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x800AA754: addiu       $t6, $t5, 0x10
    ctx->r14 = ADD32(ctx->r13, 0X10);
    // 0x800AA758: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x800AA75C: lw          $a1, 0x28($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X28);
    // 0x800AA760: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800AA764: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800AA768: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800AA76C: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800AA770: lw          $a1, 0x28($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X28);
    // 0x800AA774: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800AA778: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800AA77C: beq         $v1, $zero, L_800AA85C
    if (ctx->r3 == 0) {
        // 0x800AA780: andi        $a2, $v1, 0x3
        ctx->r6 = ctx->r3 & 0X3;
            goto L_800AA85C;
    }
    // 0x800AA780: andi        $a2, $v1, 0x3
    ctx->r6 = ctx->r3 & 0X3;
    // 0x800AA784: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800AA788: beq         $a2, $zero, L_800AA7C4
    if (ctx->r6 == 0) {
        // 0x800AA78C: addu        $a1, $a2, $v1
        ctx->r5 = ADD32(ctx->r6, ctx->r3);
            goto L_800AA7C4;
    }
    // 0x800AA78C: addu        $a1, $a2, $v1
    ctx->r5 = ADD32(ctx->r6, ctx->r3);
L_800AA790:
    // 0x800AA790: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800AA794: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AA798: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800AA79C: bne         $at, $zero, L_800AA7B4
    if (ctx->r1 != 0) {
        // 0x800AA7A0: nop
    
            goto L_800AA7B4;
    }
    // 0x800AA7A0: nop

    // 0x800AA7A4: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800AA7A8: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x800AA7AC: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x800AA7B0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
L_800AA7B4:
    // 0x800AA7B4: bne         $a1, $v1, L_800AA790
    if (ctx->r5 != ctx->r3) {
        // 0x800AA7B8: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800AA790;
    }
    // 0x800AA7B8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800AA7BC: beq         $v1, $zero, L_800AA85C
    if (ctx->r3 == 0) {
        // 0x800AA7C0: nop
    
            goto L_800AA85C;
    }
    // 0x800AA7C0: nop

L_800AA7C4:
    // 0x800AA7C4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800AA7C8: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800AA7CC: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x800AA7D0: bnel        $at, $zero, L_800AA7EC
    if (ctx->r1 != 0) {
        // 0x800AA7D4: lw          $t8, 0x8($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X8);
            goto L_800AA7EC;
    }
    goto skip_1;
    // 0x800AA7D4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    skip_1:
    // 0x800AA7D8: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x800AA7DC: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x800AA7E0: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800AA7E4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800AA7E8: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
L_800AA7EC:
    // 0x800AA7EC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800AA7F0: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x800AA7F4: bnel        $at, $zero, L_800AA810
    if (ctx->r1 != 0) {
        // 0x800AA7F8: lw          $t2, 0x8($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X8);
            goto L_800AA810;
    }
    goto skip_2;
    // 0x800AA7F8: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    skip_2:
    // 0x800AA7FC: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800AA800: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x800AA804: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800AA808: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800AA80C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
L_800AA810:
    // 0x800AA810: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800AA814: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800AA818: bnel        $at, $zero, L_800AA834
    if (ctx->r1 != 0) {
        // 0x800AA81C: lw          $t6, 0x8($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X8);
            goto L_800AA834;
    }
    goto skip_3;
    // 0x800AA81C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    skip_3:
    // 0x800AA820: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x800AA824: addu        $t4, $t3, $a0
    ctx->r12 = ADD32(ctx->r11, ctx->r4);
    // 0x800AA828: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x800AA82C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800AA830: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
L_800AA834:
    // 0x800AA834: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800AA838: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800AA83C: bne         $at, $zero, L_800AA854
    if (ctx->r1 != 0) {
        // 0x800AA840: nop
    
            goto L_800AA854;
    }
    // 0x800AA840: nop

    // 0x800AA844: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800AA848: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800AA84C: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800AA850: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800AA854:
    // 0x800AA854: bne         $v1, $zero, L_800AA7C4
    if (ctx->r3 != 0) {
        // 0x800AA858: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800AA7C4;
    }
    // 0x800AA858: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800AA85C:
    // 0x800AA85C: jr          $ra
    // 0x800AA860: nop

    return;
    // 0x800AA860: nop

;}

RECOMP_FUNC void CubeTiles_ObjClearState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA864: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800AA868: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800AA86C: jr          $ra
    // 0x800AA870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AA870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AA874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA87C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800AA880: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA884: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800AA888: bnel        $a1, $at, L_800AA8A4
    if (ctx->r5 != ctx->r1) {
        // 0x800AA88C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800AA8A4;
    }
    goto skip_0;
    // 0x800AA88C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x800AA890: jal         0x8007E328
    // 0x800AA894: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA894: nop

    after_0:
    // 0x800AA898: b           L_800AA8BC
    // 0x800AA89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA8BC;
    // 0x800AA89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA8A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800AA8A4:
    // 0x800AA8A4: jal         0x800AA3DC
    // 0x800AA8A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800AA3DC(rdram, ctx);
        goto after_1;
    // 0x800AA8A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x800AA8AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800AA8B0: jal         0x800AA3F4
    // 0x800AA8B4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    func_800AA3F4(rdram, ctx);
        goto after_2;
    // 0x800AA8B4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    after_2:
    // 0x800AA8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA8BC:
    // 0x800AA8BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA8C0: jr          $ra
    // 0x800AA8C4: nop

    return;
    // 0x800AA8C4: nop

;}

RECOMP_FUNC void func_800AA8C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA8C8: jr          $ra
    // 0x800AA8CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800AA8CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

RECOMP_FUNC void func_800AA8D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA8D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AA8D4: jr          $ra
    // 0x800AA8D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AA8D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AA8DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA8DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA8E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA8E4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800AA8E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA8EC: bne         $a1, $at, L_800AA904
    if (ctx->r5 != ctx->r1) {
        // 0x800AA8F0: nop
    
            goto L_800AA904;
    }
    // 0x800AA8F0: nop

    // 0x800AA8F4: jal         0x8007E328
    // 0x800AA8F8: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA8F8: nop

    after_0:
    // 0x800AA8FC: b           L_800AA910
    // 0x800AA900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA910;
    // 0x800AA900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA904:
    // 0x800AA904: jal         0x800AA3F4
    // 0x800AA908: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA3F4(rdram, ctx);
        goto after_1;
    // 0x800AA908: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800AA90C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA910:
    // 0x800AA910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA914: jr          $ra
    // 0x800AA918: nop

    return;
    // 0x800AA918: nop

;}

RECOMP_FUNC void CubeTiles_ObjRelocateOne(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA91C: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x800AA920: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800AA924: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800AA928: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800AA92C: jr          $ra
    // 0x800AA930: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    return;
    // 0x800AA930: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
;}

RECOMP_FUNC void func_800AA934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA934: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AA938: jr          $ra
    // 0x800AA93C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AA93C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AA940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA948: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800AA94C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA950: bne         $a1, $at, L_800AA968
    if (ctx->r5 != ctx->r1) {
        // 0x800AA954: nop
    
            goto L_800AA968;
    }
    // 0x800AA954: nop

    // 0x800AA958: jal         0x8007E328
    // 0x800AA95C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA95C: nop

    after_0:
    // 0x800AA960: b           L_800AA974
    // 0x800AA964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA974;
    // 0x800AA964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA968:
    // 0x800AA968: jal         0x800AA3F4
    // 0x800AA96C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA3F4(rdram, ctx);
        goto after_1;
    // 0x800AA96C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800AA970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA974:
    // 0x800AA974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA978: jr          $ra
    // 0x800AA97C: nop

    return;
    // 0x800AA97C: nop

;}

RECOMP_FUNC void CubeTiles_ObjRelocateDeep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA988: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x800AA98C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800AA990: beql        $t6, $zero, L_800AAA34
    if (ctx->r14 == 0) {
        // 0x800AA994: lw          $t5, 0x30($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X30);
            goto L_800AAA34;
    }
    goto skip_0;
    // 0x800AA994: lw          $t5, 0x30($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X30);
    skip_0:
    // 0x800AA998: lw          $t7, 0x28($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X28);
    // 0x800AA99C: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x800AA9A0: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800AA9A4: addiu       $v0, $t8, 0x10
    ctx->r2 = ADD32(ctx->r24, 0X10);
    // 0x800AA9A8: beq         $v1, $zero, L_800AAA30
    if (ctx->r3 == 0) {
        // 0x800AA9AC: sw          $v0, 0x28($a0)
        MEM_W(0X28, ctx->r4) = ctx->r2;
            goto L_800AAA30;
    }
    // 0x800AA9AC: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x800AA9B0: andi        $a1, $v1, 0x3
    ctx->r5 = ctx->r3 & 0X3;
    // 0x800AA9B4: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800AA9B8: beq         $a1, $zero, L_800AA9E4
    if (ctx->r5 == 0) {
        // 0x800AA9BC: addu        $a0, $a1, $v1
        ctx->r4 = ADD32(ctx->r5, ctx->r3);
            goto L_800AA9E4;
    }
    // 0x800AA9BC: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_800AA9C0:
    // 0x800AA9C0: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800AA9C4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AA9C8: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800AA9CC: addu        $t1, $t0, $a2
    ctx->r9 = ADD32(ctx->r8, ctx->r6);
    // 0x800AA9D0: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x800AA9D4: bne         $a0, $v1, L_800AA9C0
    if (ctx->r4 != ctx->r3) {
        // 0x800AA9D8: sw          $t2, -0x3C($v0)
        MEM_W(-0X3C, ctx->r2) = ctx->r10;
            goto L_800AA9C0;
    }
    // 0x800AA9D8: sw          $t2, -0x3C($v0)
    MEM_W(-0X3C, ctx->r2) = ctx->r10;
    // 0x800AA9DC: beql        $v1, $zero, L_800AAA34
    if (ctx->r3 == 0) {
        // 0x800AA9E0: lw          $t5, 0x30($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X30);
            goto L_800AAA34;
    }
    goto skip_1;
    // 0x800AA9E0: lw          $t5, 0x30($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X30);
    skip_1:
L_800AA9E4:
    // 0x800AA9E4: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x800AA9E8: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x800AA9EC: lw          $t9, 0x84($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84);
    // 0x800AA9F0: lw          $t2, 0xC4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC4);
    // 0x800AA9F4: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x800AA9F8: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x800AA9FC: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800AAA00: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x800AAA04: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x800AAA08: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x800AAA0C: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800AAA10: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800AAA14: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800AAA18: sw          $t8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r24;
    // 0x800AAA1C: sw          $t1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r9;
    // 0x800AAA20: sw          $t4, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->r12;
    // 0x800AAA24: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x800AAA28: bne         $v1, $zero, L_800AA9E4
    if (ctx->r3 != 0) {
        // 0x800AAA2C: sw          $t5, -0xFC($v0)
        MEM_W(-0XFC, ctx->r2) = ctx->r13;
            goto L_800AA9E4;
    }
    // 0x800AAA2C: sw          $t5, -0xFC($v0)
    MEM_W(-0XFC, ctx->r2) = ctx->r13;
L_800AAA30:
    // 0x800AAA30: lw          $t5, 0x30($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X30);
L_800AAA34:
    // 0x800AAA34: beql        $t5, $zero, L_800AAA50
    if (ctx->r13 == 0) {
        // 0x800AAA38: lw          $t9, 0x2C($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X2C);
            goto L_800AAA50;
    }
    goto skip_2;
    // 0x800AAA38: lw          $t9, 0x2C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X2C);
    skip_2:
    // 0x800AAA3C: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x800AAA40: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800AAA44: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800AAA48: sw          $t8, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r24;
    // 0x800AAA4C: lw          $t9, 0x2C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X2C);
L_800AAA50:
    // 0x800AAA50: beql        $t9, $zero, L_800AAA7C
    if (ctx->r25 == 0) {
        // 0x800AAA54: lw          $t3, 0x38($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X38);
            goto L_800AAA7C;
    }
    goto skip_3;
    // 0x800AAA54: lw          $t3, 0x38($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X38);
    skip_3:
    // 0x800AAA58: lw          $t0, 0x2C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X2C);
    // 0x800AAA5C: addiu       $a1, $a2, 0x10
    ctx->r5 = ADD32(ctx->r6, 0X10);
    // 0x800AAA60: addu        $t1, $t0, $a2
    ctx->r9 = ADD32(ctx->r8, ctx->r6);
    // 0x800AAA64: addiu       $a0, $t1, 0x10
    ctx->r4 = ADD32(ctx->r9, 0X10);
    // 0x800AAA68: sw          $a0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r4;
    // 0x800AAA6C: jal         0x800ABAB8
    // 0x800AAA70: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800ABAB8(rdram, ctx);
        goto after_0;
    // 0x800AAA70: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800AAA74: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800AAA78: lw          $t3, 0x38($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X38);
L_800AAA7C:
    // 0x800AAA7C: beql        $t3, $zero, L_800AAA98
    if (ctx->r11 == 0) {
        // 0x800AAA80: lw          $t7, 0x3C($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X3C);
            goto L_800AAA98;
    }
    goto skip_4;
    // 0x800AAA80: lw          $t7, 0x3C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X3C);
    skip_4:
    // 0x800AAA84: lw          $t4, 0x38($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X38);
    // 0x800AAA88: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800AAA8C: addiu       $t6, $t5, 0x10
    ctx->r14 = ADD32(ctx->r13, 0X10);
    // 0x800AAA90: sw          $t6, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->r14;
    // 0x800AAA94: lw          $t7, 0x3C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X3C);
L_800AAA98:
    // 0x800AAA98: beql        $t7, $zero, L_800AAAB4
    if (ctx->r15 == 0) {
        // 0x800AAA9C: lw          $t1, 0x40($a2)
        ctx->r9 = MEM_W(ctx->r6, 0X40);
            goto L_800AAAB4;
    }
    goto skip_5;
    // 0x800AAA9C: lw          $t1, 0x40($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X40);
    skip_5:
    // 0x800AAAA0: lw          $t8, 0x3C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X3C);
    // 0x800AAAA4: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x800AAAA8: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x800AAAAC: sw          $t0, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r8;
    // 0x800AAAB0: lw          $t1, 0x40($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X40);
L_800AAAB4:
    // 0x800AAAB4: beql        $t1, $zero, L_800AAAD0
    if (ctx->r9 == 0) {
        // 0x800AAAB8: lw          $t5, 0x44($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X44);
            goto L_800AAAD0;
    }
    goto skip_6;
    // 0x800AAAB8: lw          $t5, 0x44($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X44);
    skip_6:
    // 0x800AAABC: lw          $t2, 0x40($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X40);
    // 0x800AAAC0: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x800AAAC4: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x800AAAC8: sw          $t4, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r12;
    // 0x800AAACC: lw          $t5, 0x44($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X44);
L_800AAAD0:
    // 0x800AAAD0: beql        $t5, $zero, L_800AAAEC
    if (ctx->r13 == 0) {
        // 0x800AAAD4: lw          $t9, 0x48($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X48);
            goto L_800AAAEC;
    }
    goto skip_7;
    // 0x800AAAD4: lw          $t9, 0x48($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X48);
    skip_7:
    // 0x800AAAD8: lw          $t6, 0x44($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X44);
    // 0x800AAADC: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800AAAE0: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800AAAE4: sw          $t8, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r24;
    // 0x800AAAE8: lw          $t9, 0x48($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X48);
L_800AAAEC:
    // 0x800AAAEC: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800AAAF0: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x800AAAF4: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800AAAF8: sw          $t1, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->r9;
    // 0x800AAAFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AAB00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AAB04: jr          $ra
    // 0x800AAB08: nop

    return;
    // 0x800AAB08: nop

;}

RECOMP_FUNC void CubeTiles_ObjBuildChildren(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AAB0C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800AAB10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AAB14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AAB18: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x800AAB1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AAB20: lw          $v1, 0x28($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X28);
    // 0x800AAB24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AAB28: blez        $t0, L_800AABE0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800AAB2C: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_800AABE0;
    }
    // 0x800AAB2C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800AAB30:
    // 0x800AAB30: lbu         $a0, 0x3($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X3);
    // 0x800AAB34: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800AAB38: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800AAB3C: beq         $a0, $zero, L_800AABD8
    if (ctx->r4 == 0) {
        // 0x800AAB40: addiu       $a3, $a3, 0x188
        ctx->r7 = ADD32(ctx->r7, 0X188);
            goto L_800AABD8;
    }
    // 0x800AAB40: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AAB44: andi        $a2, $a0, 0x3
    ctx->r6 = ctx->r4 & 0X3;
    // 0x800AAB48: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800AAB4C: beq         $a2, $zero, L_800AAB7C
    if (ctx->r6 == 0) {
        // 0x800AAB50: addu        $a1, $a2, $a0
        ctx->r5 = ADD32(ctx->r6, ctx->r4);
            goto L_800AAB7C;
    }
    // 0x800AAB50: addu        $a1, $a2, $a0
    ctx->r5 = ADD32(ctx->r6, ctx->r4);
L_800AAB54:
    // 0x800AAB54: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800AAB58: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x800AAB5C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800AAB60: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800AAB64: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AAB68: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800AAB6C: bne         $a1, $a0, L_800AAB54
    if (ctx->r5 != ctx->r4) {
        // 0x800AAB70: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800AAB54;
    }
    // 0x800AAB70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AAB74: beq         $a0, $zero, L_800AABD8
    if (ctx->r4 == 0) {
        // 0x800AAB78: nop
    
            goto L_800AABD8;
    }
    // 0x800AAB78: nop

L_800AAB7C:
    // 0x800AAB7C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800AAB80: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x800AAB84: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800AAB88: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800AAB8C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AAB90: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AAB94: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x800AAB98: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800AAB9C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x800AABA0: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x800AABA4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800AABA8: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x800AABAC: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800AABB0: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800AABB4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AABB8: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x800AABBC: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x800AABC0: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800AABC4: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800AABC8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AABCC: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x800AABD0: bne         $a0, $zero, L_800AAB7C
    if (ctx->r4 != 0) {
        // 0x800AABD4: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_800AAB7C;
    }
    // 0x800AABD4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
L_800AABD8:
    // 0x800AABD8: bne         $t1, $t0, L_800AAB30
    if (ctx->r9 != ctx->r8) {
        // 0x800AABDC: addiu       $v1, $v1, 0x40
        ctx->r3 = ADD32(ctx->r3, 0X40);
            goto L_800AAB30;
    }
    // 0x800AABDC: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
L_800AABE0:
    // 0x800AABE0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x800AABE4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800AABE8: beql        $t3, $a0, L_800AAC0C
    if (ctx->r11 == ctx->r4) {
        // 0x800AABEC: sw          $zero, 0x34($s0)
        MEM_W(0X34, ctx->r16) = 0;
            goto L_800AAC0C;
    }
    goto skip_0;
    // 0x800AABEC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    skip_0:
    // 0x800AABF0: jal         0x800AA14C
    // 0x800AABF4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    CubeTiles_ObjInstantiate(rdram, ctx);
        goto after_0;
    // 0x800AABF4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x800AABF8: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800AABFC: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800AAC00: b           L_800AAC0C
    // 0x800AAC04: addiu       $a3, $a3, 0x80
    ctx->r7 = ADD32(ctx->r7, 0X80);
        goto L_800AAC0C;
    // 0x800AAC04: addiu       $a3, $a3, 0x80
    ctx->r7 = ADD32(ctx->r7, 0X80);
    // 0x800AAC08: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
L_800AAC0C:
    // 0x800AAC0C: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x800AAC10: beql        $a0, $zero, L_800AAC60
    if (ctx->r4 == 0) {
        // 0x800AAC14: lw          $v0, 0x3C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X3C);
            goto L_800AAC60;
    }
    goto skip_1;
    // 0x800AAC14: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    skip_1:
    // 0x800AAC18: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x800AAC1C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800AAC20: beql        $t1, $zero, L_800AAC60
    if (ctx->r9 == 0) {
        // 0x800AAC24: lw          $v0, 0x3C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X3C);
            goto L_800AAC60;
    }
    goto skip_2;
    // 0x800AAC24: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    skip_2:
L_800AAC28:
    // 0x800AAC28: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800AAC2C: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800AAC30: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800AAC34: jal         0x800AA14C
    // 0x800AAC38: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    CubeTiles_ObjInstantiate(rdram, ctx);
        goto after_1;
    // 0x800AAC38: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_1:
    // 0x800AAC3C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800AAC40: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800AAC44: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800AAC48: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AAC4C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AAC50: sw          $v0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r2;
    // 0x800AAC54: bne         $t1, $zero, L_800AAC28
    if (ctx->r9 != 0) {
        // 0x800AAC58: addiu       $a3, $a3, 0x20
        ctx->r7 = ADD32(ctx->r7, 0X20);
            goto L_800AAC28;
    }
    // 0x800AAC58: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800AAC5C: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
L_800AAC60:
    // 0x800AAC60: beql        $v0, $zero, L_800AADE0
    if (ctx->r2 == 0) {
        // 0x800AAC64: lw          $v0, 0x40($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X40);
            goto L_800AADE0;
    }
    goto skip_3;
    // 0x800AAC64: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    skip_3:
    // 0x800AAC68: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
    // 0x800AAC6C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800AAC70: beql        $t1, $zero, L_800AADE0
    if (ctx->r9 == 0) {
        // 0x800AAC74: lw          $v0, 0x40($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X40);
            goto L_800AADE0;
    }
    goto skip_4;
    // 0x800AAC74: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    skip_4:
L_800AAC78:
    // 0x800AAC78: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800AAC7C: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800AAC80: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800AAC84: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800AAC88: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x800AAC8C: jal         0x800AA14C
    // 0x800AAC90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    CubeTiles_ObjInstantiate(rdram, ctx);
        goto after_2;
    // 0x800AAC90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800AAC94: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800AAC98: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800AAC9C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800AACA0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800AACA4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800AACA8: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x800AACAC: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800AACB0: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AACB4: beql        $t8, $zero, L_800AACD4
    if (ctx->r24 == 0) {
        // 0x800AACB8: lw          $t2, 0x0($t0)
        ctx->r10 = MEM_W(ctx->r8, 0X0);
            goto L_800AACD4;
    }
    goto skip_5;
    // 0x800AACB8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    skip_5:
    // 0x800AACBC: lw          $t5, 0x24($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X24);
    // 0x800AACC0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    // 0x800AACC4: and         $t9, $a3, $at
    ctx->r25 = ctx->r7 & ctx->r1;
    // 0x800AACC8: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x800AACCC: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
    // 0x800AACD0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
L_800AACD4:
    // 0x800AACD4: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x800AACD8: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x800AACDC: beq         $a0, $zero, L_800AADA8
    if (ctx->r4 == 0) {
        // 0x800AACE0: andi        $a2, $a0, 0x3
        ctx->r6 = ctx->r4 & 0X3;
            goto L_800AADA8;
    }
    // 0x800AACE0: andi        $a2, $a0, 0x3
    ctx->r6 = ctx->r4 & 0X3;
    // 0x800AACE4: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800AACE8: beq         $a2, $zero, L_800AAD20
    if (ctx->r6 == 0) {
        // 0x800AACEC: addu        $v1, $a2, $a0
        ctx->r3 = ADD32(ctx->r6, ctx->r4);
            goto L_800AAD20;
    }
    // 0x800AACEC: addu        $v1, $a2, $a0
    ctx->r3 = ADD32(ctx->r6, ctx->r4);
L_800AACF0:
    // 0x800AACF0: lwl         $t7, 0x0($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X0);
    // 0x800AACF4: lwr         $t7, 0x3($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X3);
    // 0x800AACF8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800AACFC: ori         $t9, $a1, 0x1
    ctx->r25 = ctx->r5 | 0X1;
    // 0x800AAD00: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x800AAD04: beq         $t8, $zero, L_800AAD10
    if (ctx->r24 == 0) {
        // 0x800AAD08: nop
    
            goto L_800AAD10;
    }
    // 0x800AAD08: nop

    // 0x800AAD0C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_800AAD10:
    // 0x800AAD10: bne         $v1, $a0, L_800AACF0
    if (ctx->r3 != ctx->r4) {
        // 0x800AAD14: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800AACF0;
    }
    // 0x800AAD14: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800AAD18: beq         $a0, $zero, L_800AADA8
    if (ctx->r4 == 0) {
        // 0x800AAD1C: nop
    
            goto L_800AADA8;
    }
    // 0x800AAD1C: nop

L_800AAD20:
    // 0x800AAD20: lwl         $t4, 0x0($v0)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X0);
    // 0x800AAD24: lwr         $t4, 0x3($v0)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r2, 0X3);
    // 0x800AAD28: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800AAD2C: ori         $t6, $a1, 0x1
    ctx->r14 = ctx->r5 | 0X1;
    // 0x800AAD30: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800AAD34: beql        $t5, $zero, L_800AAD44
    if (ctx->r13 == 0) {
        // 0x800AAD38: lwl         $t7, 0x14($v0)
        ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X14);
            goto L_800AAD44;
    }
    goto skip_6;
    // 0x800AAD38: lwl         $t7, 0x14($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X14);
    skip_6:
    // 0x800AAD3C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800AAD40: lwl         $t7, 0x14($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X14);
L_800AAD44:
    // 0x800AAD44: lwr         $t7, 0x17($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X17);
    // 0x800AAD48: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800AAD4C: ori         $t9, $a1, 0x1
    ctx->r25 = ctx->r5 | 0X1;
    // 0x800AAD50: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x800AAD54: beql        $t8, $zero, L_800AAD64
    if (ctx->r24 == 0) {
        // 0x800AAD58: lwl         $t4, 0x14($v0)
        ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X14);
            goto L_800AAD64;
    }
    goto skip_7;
    // 0x800AAD58: lwl         $t4, 0x14($v0)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X14);
    skip_7:
    // 0x800AAD5C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800AAD60: lwl         $t4, 0x14($v0)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X14);
L_800AAD64:
    // 0x800AAD64: lwr         $t4, 0x17($v0)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r2, 0X17);
    // 0x800AAD68: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800AAD6C: ori         $t6, $a1, 0x1
    ctx->r14 = ctx->r5 | 0X1;
    // 0x800AAD70: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800AAD74: beql        $t5, $zero, L_800AAD84
    if (ctx->r13 == 0) {
        // 0x800AAD78: lwl         $t7, 0x14($v0)
        ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X14);
            goto L_800AAD84;
    }
    goto skip_8;
    // 0x800AAD78: lwl         $t7, 0x14($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X14);
    skip_8:
    // 0x800AAD7C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800AAD80: lwl         $t7, 0x14($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X14);
L_800AAD84:
    // 0x800AAD84: lwr         $t7, 0x17($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X17);
    // 0x800AAD88: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800AAD8C: ori         $t9, $a1, 0x1
    ctx->r25 = ctx->r5 | 0X1;
    // 0x800AAD90: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x800AAD94: beq         $t8, $zero, L_800AADA0
    if (ctx->r24 == 0) {
        // 0x800AAD98: nop
    
            goto L_800AADA0;
    }
    // 0x800AAD98: nop

    // 0x800AAD9C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_800AADA0:
    // 0x800AADA0: bne         $a0, $zero, L_800AAD20
    if (ctx->r4 != 0) {
        // 0x800AADA4: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800AAD20;
    }
    // 0x800AADA4: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
L_800AADA8:
    // 0x800AADA8: beq         $a1, $zero, L_800AADC8
    if (ctx->r5 == 0) {
        // 0x800AADAC: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_800AADC8;
    }
    // 0x800AADAC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800AADB0: sw          $t4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r12;
    // 0x800AADB4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800AADB8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800AADBC: addiu       $a3, $a3, 0x60
    ctx->r7 = ADD32(ctx->r7, 0X60);
    // 0x800AADC0: b           L_800AADD4
    // 0x800AADC4: sw          $t5, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r13;
        goto L_800AADD4;
    // 0x800AADC4: sw          $t5, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r13;
L_800AADC8:
    // 0x800AADC8: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x800AADCC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800AADD0: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
L_800AADD4:
    // 0x800AADD4: bne         $t1, $zero, L_800AAC78
    if (ctx->r9 != 0) {
        // 0x800AADD8: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_800AAC78;
    }
    // 0x800AADD8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800AADDC: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
L_800AADE0:
    // 0x800AADE0: beq         $v0, $zero, L_800AAE28
    if (ctx->r2 == 0) {
        // 0x800AADE4: nop
    
            goto L_800AAE28;
    }
    // 0x800AADE4: nop

    // 0x800AADE8: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x800AADEC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800AADF0: beq         $t1, $zero, L_800AAE28
    if (ctx->r9 == 0) {
        // 0x800AADF4: nop
    
            goto L_800AAE28;
    }
    // 0x800AADF4: nop

L_800AADF8:
    // 0x800AADF8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800AADFC: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800AAE00: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800AAE04: jal         0x800AA14C
    // 0x800AAE08: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    CubeTiles_ObjInstantiate(rdram, ctx);
        goto after_3;
    // 0x800AAE08: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x800AAE0C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800AAE10: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800AAE14: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800AAE18: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AAE1C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AAE20: bne         $t1, $zero, L_800AADF8
    if (ctx->r9 != 0) {
        // 0x800AAE24: sw          $v0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r2;
            goto L_800AADF8;
    }
    // 0x800AAE24: sw          $v0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r2;
L_800AAE28:
    // 0x800AAE28: jal         0x8007E03C
    // 0x800AAE2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800AAE2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x800AAE30: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x800AAE34: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x800AAE38: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x800AAE3C: beq         $t1, $zero, L_800AB2AC
    if (ctx->r9 == 0) {
        // 0x800AAE40: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800AB2AC;
    }
    // 0x800AAE40: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800AAE44: andi        $a1, $t1, 0x3
    ctx->r5 = ctx->r9 & 0X3;
    // 0x800AAE48: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800AAE4C: beql        $a1, $zero, L_800AAF50
    if (ctx->r5 == 0) {
        // 0x800AAE50: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800AAF50;
    }
    goto skip_9;
    // 0x800AAE50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_9:
    // 0x800AAE54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AAE58: addu        $v0, $a1, $t1
    ctx->r2 = ADD32(ctx->r5, ctx->r9);
    // 0x800AAE5C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AAE60: sw          $a3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r7;
    // 0x800AAE64: beq         $v0, $t1, L_800AAEE0
    if (ctx->r2 == ctx->r9) {
        // 0x800AAE68: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_800AAEE0;
    }
    // 0x800AAE68: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_800AAE6C:
    // 0x800AAE6C: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AAE70: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800AAE74: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AAE78: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AAE7C: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AAE80: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x800AAE84: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AAE88: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AAE8C: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AAE90: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AAE94: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AAE98: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AAE9C: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEA0: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AAEA4: lw          $t8, -0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEA8: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AAEAC: lw          $t9, -0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEB0: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AAEB4: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEB8: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AAEBC: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEC0: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AAEC4: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEC8: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AAECC: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AAED0: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AAED4: sw          $a3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r7;
    // 0x800AAED8: bne         $v0, $t1, L_800AAE6C
    if (ctx->r2 != ctx->r9) {
        // 0x800AAEDC: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_800AAE6C;
    }
    // 0x800AAEDC: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_800AAEE0:
    // 0x800AAEE0: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AAEE4: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800AAEE8: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AAEEC: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AAEF0: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AAEF4: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEF8: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AAEFC: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF00: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AAF04: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF08: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AAF0C: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF10: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AAF14: lw          $t8, -0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF18: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AAF1C: lw          $t9, -0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF20: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AAF24: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF28: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AAF2C: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF30: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AAF34: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF38: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AAF3C: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF40: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AAF44: beql        $t1, $zero, L_800AB2B0
    if (ctx->r9 == 0) {
        // 0x800AAF48: lw          $v0, 0x34($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X34);
            goto L_800AB2B0;
    }
    goto skip_10;
    // 0x800AAF48: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    skip_10:
    // 0x800AAF4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800AAF50:
    // 0x800AAF50: nop

    // 0x800AAF54: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800AAF58: sw          $a3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r7;
    // 0x800AAF5C: beq         $t1, $zero, L_800AB110
    if (ctx->r9 == 0) {
        // 0x800AAF60: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_800AB110;
    }
    // 0x800AAF60: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_800AAF64:
    // 0x800AAF64: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AAF68: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800AAF6C: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AAF70: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800AAF74: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AAF78: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x800AAF7C: addiu       $v1, $v1, 0x100
    ctx->r3 = ADD32(ctx->r3, 0X100);
    // 0x800AAF80: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AAF84: lw          $t5, -0xF4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAF88: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AAF8C: lw          $t6, -0xF4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAF90: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AAF94: lw          $t7, -0xF4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAF98: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AAF9C: lw          $t8, -0xF4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAFA0: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AAFA4: lw          $t9, -0xF4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAFA8: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AAFAC: lw          $t4, -0xF4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAFB0: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AAFB4: lw          $t5, -0xF4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAFB8: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AAFBC: lw          $t6, -0xF4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAFC0: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AAFC4: lw          $t7, -0xF4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAFC8: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AAFCC: sw          $a3, -0xB4($v1)
    MEM_W(-0XB4, ctx->r3) = ctx->r7;
    // 0x800AAFD0: lw          $t8, -0xB4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XB4);
    // 0x800AAFD4: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AAFD8: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AAFDC: lw          $t9, -0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XB4);
    // 0x800AAFE0: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AAFE4: lw          $t4, -0xB4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XB4);
    // 0x800AAFE8: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AAFEC: lw          $t5, -0xB4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XB4);
    // 0x800AAFF0: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AAFF4: lw          $t6, -0xB4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XB4);
    // 0x800AAFF8: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AAFFC: lw          $t7, -0xB4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB000: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB004: lw          $t8, -0xB4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB008: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB00C: lw          $t9, -0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB010: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB014: lw          $t4, -0xB4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB018: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB01C: lw          $t5, -0xB4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB020: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB024: lw          $t6, -0xB4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB028: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB02C: lw          $t7, -0xB4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB030: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AB034: sw          $a3, -0x74($v1)
    MEM_W(-0X74, ctx->r3) = ctx->r7;
    // 0x800AB038: lw          $t8, -0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X74);
    // 0x800AB03C: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AB040: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AB044: lw          $t9, -0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X74);
    // 0x800AB048: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AB04C: lw          $t4, -0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X74);
    // 0x800AB050: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AB054: lw          $t5, -0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X74);
    // 0x800AB058: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AB05C: lw          $t6, -0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X74);
    // 0x800AB060: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AB064: lw          $t7, -0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X74);
    // 0x800AB068: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB06C: lw          $t8, -0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X74);
    // 0x800AB070: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB074: lw          $t9, -0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X74);
    // 0x800AB078: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB07C: lw          $t4, -0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X74);
    // 0x800AB080: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB084: lw          $t5, -0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X74);
    // 0x800AB088: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB08C: lw          $t6, -0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X74);
    // 0x800AB090: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB094: lw          $t7, -0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X74);
    // 0x800AB098: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AB09C: sw          $a3, -0x34($v1)
    MEM_W(-0X34, ctx->r3) = ctx->r7;
    // 0x800AB0A0: lw          $t8, -0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0A4: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AB0A8: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AB0AC: lw          $t9, -0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0B0: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AB0B4: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0B8: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AB0BC: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0C0: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AB0C4: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0C8: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AB0CC: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0D0: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB0D4: lw          $t8, -0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0D8: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB0DC: lw          $t9, -0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0E0: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB0E4: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0E8: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB0EC: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0F0: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB0F4: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0F8: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB0FC: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AB100: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AB104: sw          $a3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r7;
    // 0x800AB108: bne         $t1, $zero, L_800AAF64
    if (ctx->r9 != 0) {
        // 0x800AB10C: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_800AAF64;
    }
    // 0x800AB10C: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_800AB110:
    // 0x800AB110: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AB114: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800AB118: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AB11C: addiu       $v1, $v1, 0x100
    ctx->r3 = ADD32(ctx->r3, 0X100);
    // 0x800AB120: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AB124: lw          $t4, -0xF4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB128: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AB12C: lw          $t5, -0xF4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB130: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AB134: lw          $t6, -0xF4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB138: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AB13C: lw          $t7, -0xF4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB140: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB144: lw          $t8, -0xF4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB148: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB14C: lw          $t9, -0xF4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB150: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB154: lw          $t4, -0xF4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB158: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB15C: lw          $t5, -0xF4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB160: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB164: lw          $t6, -0xF4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB168: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB16C: lw          $t7, -0xF4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB170: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AB174: sw          $a3, -0xB4($v1)
    MEM_W(-0XB4, ctx->r3) = ctx->r7;
    // 0x800AB178: lw          $t8, -0xB4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB17C: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AB180: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AB184: lw          $t9, -0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB188: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AB18C: lw          $t4, -0xB4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB190: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AB194: lw          $t5, -0xB4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB198: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AB19C: lw          $t6, -0xB4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1A0: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AB1A4: lw          $t7, -0xB4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1A8: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB1AC: lw          $t8, -0xB4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1B0: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB1B4: lw          $t9, -0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1B8: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB1BC: lw          $t4, -0xB4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1C0: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB1C4: lw          $t5, -0xB4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1C8: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB1CC: lw          $t6, -0xB4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1D0: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB1D4: lw          $t7, -0xB4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1D8: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AB1DC: sw          $a3, -0x74($v1)
    MEM_W(-0X74, ctx->r3) = ctx->r7;
    // 0x800AB1E0: lw          $t8, -0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X74);
    // 0x800AB1E4: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AB1E8: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AB1EC: lw          $t9, -0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X74);
    // 0x800AB1F0: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AB1F4: lw          $t4, -0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X74);
    // 0x800AB1F8: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AB1FC: lw          $t5, -0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X74);
    // 0x800AB200: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AB204: lw          $t6, -0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X74);
    // 0x800AB208: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AB20C: lw          $t7, -0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X74);
    // 0x800AB210: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB214: lw          $t8, -0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X74);
    // 0x800AB218: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB21C: lw          $t9, -0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X74);
    // 0x800AB220: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB224: lw          $t4, -0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X74);
    // 0x800AB228: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB22C: lw          $t5, -0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X74);
    // 0x800AB230: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB234: lw          $t6, -0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X74);
    // 0x800AB238: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB23C: lw          $t7, -0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X74);
    // 0x800AB240: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AB244: sw          $a3, -0x34($v1)
    MEM_W(-0X34, ctx->r3) = ctx->r7;
    // 0x800AB248: lw          $t8, -0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X34);
    // 0x800AB24C: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AB250: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AB254: lw          $t9, -0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X34);
    // 0x800AB258: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AB25C: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AB260: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AB264: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AB268: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AB26C: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AB270: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AB274: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AB278: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB27C: lw          $t8, -0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X34);
    // 0x800AB280: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB284: lw          $t9, -0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X34);
    // 0x800AB288: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB28C: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AB290: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB294: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AB298: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB29C: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AB2A0: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB2A4: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AB2A8: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
L_800AB2AC:
    // 0x800AB2AC: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
L_800AB2B0:
    // 0x800AB2B0: beql        $v0, $zero, L_800AB2C4
    if (ctx->r2 == 0) {
        // 0x800AB2B4: lw          $a0, 0x38($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X38);
            goto L_800AB2C4;
    }
    goto skip_11;
    // 0x800AB2B4: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    skip_11:
    // 0x800AB2B8: sw          $a3, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r7;
    // 0x800AB2BC: addiu       $a3, $a3, 0x80
    ctx->r7 = ADD32(ctx->r7, 0X80);
    // 0x800AB2C0: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
L_800AB2C4:
    // 0x800AB2C4: beql        $a0, $zero, L_800AB348
    if (ctx->r4 == 0) {
        // 0x800AB2C8: lw          $v0, 0x3C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X3C);
            goto L_800AB348;
    }
    goto skip_12;
    // 0x800AB2C8: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    skip_12:
    // 0x800AB2CC: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x800AB2D0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800AB2D4: beq         $t1, $zero, L_800AB344
    if (ctx->r9 == 0) {
        // 0x800AB2D8: andi        $a1, $t1, 0x3
        ctx->r5 = ctx->r9 & 0X3;
            goto L_800AB344;
    }
    // 0x800AB2D8: andi        $a1, $t1, 0x3
    ctx->r5 = ctx->r9 & 0X3;
    // 0x800AB2DC: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800AB2E0: beq         $a1, $zero, L_800AB308
    if (ctx->r5 == 0) {
        // 0x800AB2E4: addu        $v1, $a1, $t1
        ctx->r3 = ADD32(ctx->r5, ctx->r9);
            goto L_800AB308;
    }
    // 0x800AB2E4: addu        $v1, $a1, $t1
    ctx->r3 = ADD32(ctx->r5, ctx->r9);
L_800AB2E8:
    // 0x800AB2E8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AB2EC: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AB2F0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AB2F4: sw          $a3, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r7;
    // 0x800AB2F8: bne         $v1, $t1, L_800AB2E8
    if (ctx->r3 != ctx->r9) {
        // 0x800AB2FC: addiu       $a3, $a3, 0x20
        ctx->r7 = ADD32(ctx->r7, 0X20);
            goto L_800AB2E8;
    }
    // 0x800AB2FC: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800AB300: beql        $t1, $zero, L_800AB348
    if (ctx->r9 == 0) {
        // 0x800AB304: lw          $v0, 0x3C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X3C);
            goto L_800AB348;
    }
    goto skip_13;
    // 0x800AB304: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    skip_13:
L_800AB308:
    // 0x800AB308: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800AB30C: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800AB310: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800AB314: sw          $a3, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r7;
    // 0x800AB318: lw          $t4, -0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, -0XC);
    // 0x800AB31C: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800AB320: sw          $a3, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r7;
    // 0x800AB324: lw          $t5, -0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X8);
    // 0x800AB328: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800AB32C: sw          $a3, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r7;
    // 0x800AB330: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800AB334: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800AB338: sw          $a3, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r7;
    // 0x800AB33C: bne         $t1, $zero, L_800AB308
    if (ctx->r9 != 0) {
        // 0x800AB340: addiu       $a3, $a3, 0x20
        ctx->r7 = ADD32(ctx->r7, 0X20);
            goto L_800AB308;
    }
    // 0x800AB340: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
L_800AB344:
    // 0x800AB344: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
L_800AB348:
    // 0x800AB348: beql        $v0, $zero, L_800AB4B8
    if (ctx->r2 == 0) {
        // 0x800AB34C: lw          $a0, 0x2C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X2C);
            goto L_800AB4B8;
    }
    goto skip_14;
    // 0x800AB34C: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    skip_14:
    // 0x800AB350: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
    // 0x800AB354: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800AB358: beql        $t1, $zero, L_800AB4B8
    if (ctx->r9 == 0) {
        // 0x800AB35C: lw          $a0, 0x2C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X2C);
            goto L_800AB4B8;
    }
    goto skip_15;
    // 0x800AB35C: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    skip_15:
L_800AB360:
    // 0x800AB360: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800AB364: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AB368: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800AB36C: lw          $t7, 0x28($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X28);
    // 0x800AB370: beql        $t7, $zero, L_800AB484
    if (ctx->r15 == 0) {
        // 0x800AB374: lw          $t8, 0x8($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X8);
            goto L_800AB484;
    }
    goto skip_16;
    // 0x800AB374: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    skip_16:
    // 0x800AB378: lw          $a1, 0x24($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X24);
    // 0x800AB37C: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    // 0x800AB380: and         $v1, $a3, $at
    ctx->r3 = ctx->r7 & ctx->r1;
    // 0x800AB384: sw          $v1, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r3;
    // 0x800AB388: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800AB38C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800AB390: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800AB394: beq         $a1, $zero, L_800AB478
    if (ctx->r5 == 0) {
        // 0x800AB398: lw          $v0, 0x20($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X20);
            goto L_800AB478;
    }
    // 0x800AB398: lw          $v0, 0x20($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X20);
    // 0x800AB39C: andi        $t0, $a1, 0x3
    ctx->r8 = ctx->r5 & 0X3;
    // 0x800AB3A0: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x800AB3A4: beq         $t0, $zero, L_800AB3E4
    if (ctx->r8 == 0) {
        // 0x800AB3A8: addu        $a2, $t0, $a1
        ctx->r6 = ADD32(ctx->r8, ctx->r5);
            goto L_800AB3E4;
    }
    // 0x800AB3A8: addu        $a2, $t0, $a1
    ctx->r6 = ADD32(ctx->r8, ctx->r5);
L_800AB3AC:
    // 0x800AB3AC: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x800AB3B0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800AB3B4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800AB3B8: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x800AB3BC: lw          $t4, -0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, -0XC);
    // 0x800AB3C0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800AB3C4: sw          $t4, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r12;
    // 0x800AB3C8: lw          $at, -0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X8);
    // 0x800AB3CC: sw          $at, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r1;
    // 0x800AB3D0: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800AB3D4: bne         $a2, $a0, L_800AB3AC
    if (ctx->r6 != ctx->r4) {
        // 0x800AB3D8: sw          $t4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r12;
            goto L_800AB3AC;
    }
    // 0x800AB3D8: sw          $t4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r12;
    // 0x800AB3DC: beql        $a0, $zero, L_800AB478
    if (ctx->r4 == 0) {
        // 0x800AB3E0: lw          $a2, 0x0($t2)
        ctx->r6 = MEM_W(ctx->r10, 0X0);
            goto L_800AB478;
    }
    goto skip_17;
    // 0x800AB3E0: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    skip_17:
L_800AB3E4:
    // 0x800AB3E4: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x800AB3E8: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800AB3EC: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800AB3F0: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x800AB3F4: lw          $t6, -0x3C($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X3C);
    // 0x800AB3F8: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AB3FC: sw          $t6, -0x3C($v1)
    MEM_W(-0X3C, ctx->r3) = ctx->r14;
    // 0x800AB400: lw          $at, -0x38($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X38);
    // 0x800AB404: sw          $at, -0x38($v1)
    MEM_W(-0X38, ctx->r3) = ctx->r1;
    // 0x800AB408: lw          $t6, -0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X34);
    // 0x800AB40C: sw          $t6, -0x34($v1)
    MEM_W(-0X34, ctx->r3) = ctx->r14;
    // 0x800AB410: lw          $at, -0x30($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X30);
    // 0x800AB414: sw          $at, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = ctx->r1;
    // 0x800AB418: lw          $t8, -0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X2C);
    // 0x800AB41C: sw          $t8, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->r24;
    // 0x800AB420: lw          $at, -0x28($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X28);
    // 0x800AB424: sw          $at, -0x28($v1)
    MEM_W(-0X28, ctx->r3) = ctx->r1;
    // 0x800AB428: lw          $t8, -0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X24);
    // 0x800AB42C: sw          $t8, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = ctx->r24;
    // 0x800AB430: lw          $at, -0x20($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X20);
    // 0x800AB434: sw          $at, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->r1;
    // 0x800AB438: lw          $t4, -0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X1C);
    // 0x800AB43C: sw          $t4, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->r12;
    // 0x800AB440: lw          $at, -0x18($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X18);
    // 0x800AB444: sw          $at, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r1;
    // 0x800AB448: lw          $t4, -0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X14);
    // 0x800AB44C: sw          $t4, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->r12;
    // 0x800AB450: lw          $at, -0x10($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X10);
    // 0x800AB454: sw          $at, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r1;
    // 0x800AB458: lw          $t6, -0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, -0XC);
    // 0x800AB45C: sw          $t6, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r14;
    // 0x800AB460: lw          $at, -0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X8);
    // 0x800AB464: sw          $at, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r1;
    // 0x800AB468: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800AB46C: bne         $a0, $zero, L_800AB3E4
    if (ctx->r4 != 0) {
        // 0x800AB470: sw          $t6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r14;
            goto L_800AB3E4;
    }
    // 0x800AB470: sw          $t6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r14;
    // 0x800AB474: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
L_800AB478:
    // 0x800AB478: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x800AB47C: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800AB480: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
L_800AB484:
    // 0x800AB484: beql        $t8, $zero, L_800AB49C
    if (ctx->r24 == 0) {
        // 0x800AB488: lw          $t9, 0xC($a2)
        ctx->r25 = MEM_W(ctx->r6, 0XC);
            goto L_800AB49C;
    }
    goto skip_18;
    // 0x800AB488: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    skip_18:
    // 0x800AB48C: sw          $a3, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r7;
    // 0x800AB490: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800AB494: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x800AB498: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
L_800AB49C:
    // 0x800AB49C: beq         $t9, $zero, L_800AB4AC
    if (ctx->r25 == 0) {
        // 0x800AB4A0: nop
    
            goto L_800AB4AC;
    }
    // 0x800AB4A0: nop

    // 0x800AB4A4: sw          $a3, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r7;
    // 0x800AB4A8: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
L_800AB4AC:
    // 0x800AB4AC: bne         $t1, $zero, L_800AB360
    if (ctx->r9 != 0) {
        // 0x800AB4B0: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_800AB360;
    }
    // 0x800AB4B0: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800AB4B4: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
L_800AB4B8:
    // 0x800AB4B8: beql        $a0, $zero, L_800AB5D0
    if (ctx->r4 == 0) {
        // 0x800AB4BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800AB5D0;
    }
    goto skip_19;
    // 0x800AB4BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_19:
    // 0x800AB4C0: jal         0x800ABD64
    // 0x800AB4C4: nop

    func_800ABD64(rdram, ctx);
        goto after_5;
    // 0x800AB4C4: nop

    after_5:
    // 0x800AB4C8: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x800AB4CC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800AB4D0: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x800AB4D4: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x800AB4D8: beq         $t1, $zero, L_800AB5CC
    if (ctx->r9 == 0) {
        // 0x800AB4DC: andi        $a1, $t1, 0x3
        ctx->r5 = ctx->r9 & 0X3;
            goto L_800AB5CC;
    }
    // 0x800AB4DC: andi        $a1, $t1, 0x3
    ctx->r5 = ctx->r9 & 0X3;
    // 0x800AB4E0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800AB4E4: beq         $a1, $zero, L_800AB524
    if (ctx->r5 == 0) {
        // 0x800AB4E8: addu        $a0, $a1, $t1
        ctx->r4 = ADD32(ctx->r5, ctx->r9);
            goto L_800AB524;
    }
    // 0x800AB4E8: addu        $a0, $a1, $t1
    ctx->r4 = ADD32(ctx->r5, ctx->r9);
L_800AB4EC:
    // 0x800AB4EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AB4F0: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AB4F4: bnel        $t3, $v0, L_800AB508
    if (ctx->r11 != ctx->r2) {
        // 0x800AB4F8: lw          $t4, 0x28($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X28);
            goto L_800AB508;
    }
    goto skip_20;
    // 0x800AB4F8: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    skip_20:
    // 0x800AB4FC: b           L_800AB514
    // 0x800AB500: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800AB514;
    // 0x800AB500: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB504: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
L_800AB508:
    // 0x800AB508: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x800AB50C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AB510: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800AB514:
    // 0x800AB514: bne         $a0, $t1, L_800AB4EC
    if (ctx->r4 != ctx->r9) {
        // 0x800AB518: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800AB4EC;
    }
    // 0x800AB518: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800AB51C: beql        $t1, $zero, L_800AB5D0
    if (ctx->r9 == 0) {
        // 0x800AB520: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800AB5D0;
    }
    goto skip_21;
    // 0x800AB520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_21:
L_800AB524:
    // 0x800AB524: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AB528: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800AB52C: bnel        $t3, $v0, L_800AB540
    if (ctx->r11 != ctx->r2) {
        // 0x800AB530: lw          $t7, 0x28($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X28);
            goto L_800AB540;
    }
    goto skip_22;
    // 0x800AB530: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    skip_22:
    // 0x800AB534: b           L_800AB54C
    // 0x800AB538: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800AB54C;
    // 0x800AB538: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB53C: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
L_800AB540:
    // 0x800AB540: sll         $t8, $v0, 6
    ctx->r24 = S32(ctx->r2 << 6);
    // 0x800AB544: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AB548: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800AB54C:
    // 0x800AB54C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800AB550: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800AB554: bnel        $t3, $v0, L_800AB568
    if (ctx->r11 != ctx->r2) {
        // 0x800AB558: lw          $t4, 0x28($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X28);
            goto L_800AB568;
    }
    goto skip_23;
    // 0x800AB558: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    skip_23:
    // 0x800AB55C: b           L_800AB574
    // 0x800AB560: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800AB574;
    // 0x800AB560: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB564: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
L_800AB568:
    // 0x800AB568: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x800AB56C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AB570: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800AB574:
    // 0x800AB574: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800AB578: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800AB57C: bnel        $t3, $v0, L_800AB590
    if (ctx->r11 != ctx->r2) {
        // 0x800AB580: lw          $t7, 0x28($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X28);
            goto L_800AB590;
    }
    goto skip_24;
    // 0x800AB580: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    skip_24:
    // 0x800AB584: b           L_800AB59C
    // 0x800AB588: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800AB59C;
    // 0x800AB588: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB58C: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
L_800AB590:
    // 0x800AB590: sll         $t8, $v0, 6
    ctx->r24 = S32(ctx->r2 << 6);
    // 0x800AB594: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AB598: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800AB59C:
    // 0x800AB59C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800AB5A0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800AB5A4: bnel        $t3, $v0, L_800AB5B8
    if (ctx->r11 != ctx->r2) {
        // 0x800AB5A8: lw          $t4, 0x28($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X28);
            goto L_800AB5B8;
    }
    goto skip_25;
    // 0x800AB5A8: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    skip_25:
    // 0x800AB5AC: b           L_800AB5C4
    // 0x800AB5B0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800AB5C4;
    // 0x800AB5B0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB5B4: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
L_800AB5B8:
    // 0x800AB5B8: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x800AB5BC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AB5C0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800AB5C4:
    // 0x800AB5C4: bne         $t1, $zero, L_800AB524
    if (ctx->r9 != 0) {
        // 0x800AB5C8: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800AB524;
    }
    // 0x800AB5C8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800AB5CC:
    // 0x800AB5CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AB5D0:
    // 0x800AB5D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AB5D4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800AB5D8: jr          $ra
    // 0x800AB5DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AB5DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AB5E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB5E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AB5E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AB5E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AB5EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AB5F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AB5F4: lw          $a1, 0x34($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X34);
    // 0x800AB5F8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800AB5FC: beql        $a1, $zero, L_800AB610
    if (ctx->r5 == 0) {
        // 0x800AB600: lw          $v0, 0x38($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X38);
            goto L_800AB610;
    }
    goto skip_0;
    // 0x800AB600: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    skip_0:
    // 0x800AB604: jal         0x800AA940
    // 0x800AB608: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA940(rdram, ctx);
        goto after_0;
    // 0x800AB608: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800AB60C: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
L_800AB610:
    // 0x800AB610: beql        $v0, $zero, L_800AB640
    if (ctx->r2 == 0) {
        // 0x800AB614: lw          $v0, 0x3C($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X3C);
            goto L_800AB640;
    }
    goto skip_1;
    // 0x800AB614: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
    skip_1:
    // 0x800AB618: lw          $s0, 0x14($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X14);
    // 0x800AB61C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800AB620: beql        $s0, $zero, L_800AB640
    if (ctx->r16 == 0) {
        // 0x800AB624: lw          $v0, 0x3C($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X3C);
            goto L_800AB640;
    }
    goto skip_2;
    // 0x800AB624: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
    skip_2:
L_800AB628:
    // 0x800AB628: jal         0x800AA8DC
    // 0x800AB62C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800AA8DC(rdram, ctx);
        goto after_1;
    // 0x800AB62C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x800AB630: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800AB634: bne         $s0, $zero, L_800AB628
    if (ctx->r16 != 0) {
        // 0x800AB638: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800AB628;
    }
    // 0x800AB638: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800AB63C: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
L_800AB640:
    // 0x800AB640: beql        $v0, $zero, L_800AB670
    if (ctx->r2 == 0) {
        // 0x800AB644: lw          $v0, 0x40($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X40);
            goto L_800AB670;
    }
    goto skip_3;
    // 0x800AB644: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
    skip_3:
    // 0x800AB648: lw          $s0, 0x18($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X18);
    // 0x800AB64C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800AB650: beql        $s0, $zero, L_800AB670
    if (ctx->r16 == 0) {
        // 0x800AB654: lw          $v0, 0x40($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X40);
            goto L_800AB670;
    }
    goto skip_4;
    // 0x800AB654: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
    skip_4:
L_800AB658:
    // 0x800AB658: jal         0x800AA874
    // 0x800AB65C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800AA874(rdram, ctx);
        goto after_2;
    // 0x800AB65C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x800AB660: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800AB664: bne         $s0, $zero, L_800AB658
    if (ctx->r16 != 0) {
        // 0x800AB668: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800AB658;
    }
    // 0x800AB668: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800AB66C: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
L_800AB670:
    // 0x800AB670: beql        $v0, $zero, L_800AB6A0
    if (ctx->r2 == 0) {
        // 0x800AB674: lw          $a0, 0x0($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X0);
            goto L_800AB6A0;
    }
    goto skip_5;
    // 0x800AB674: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    skip_5:
    // 0x800AB678: lw          $s0, 0x1C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X1C);
    // 0x800AB67C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800AB680: beql        $s0, $zero, L_800AB6A0
    if (ctx->r16 == 0) {
        // 0x800AB684: lw          $a0, 0x0($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X0);
            goto L_800AB6A0;
    }
    goto skip_6;
    // 0x800AB684: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    skip_6:
L_800AB688:
    // 0x800AB688: jal         0x800AA638
    // 0x800AB68C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800AA638(rdram, ctx);
        goto after_3;
    // 0x800AB68C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x800AB690: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800AB694: bne         $s0, $zero, L_800AB688
    if (ctx->r16 != 0) {
        // 0x800AB698: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800AB688;
    }
    // 0x800AB698: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800AB69C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_800AB6A0:
    // 0x800AB6A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AB6A4: bne         $a0, $at, L_800AB6C4
    if (ctx->r4 != ctx->r1) {
        // 0x800AB6A8: nop
    
            goto L_800AB6C4;
    }
    // 0x800AB6A8: nop

    // 0x800AB6AC: jal         0x8007E328
    // 0x800AB6B0: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    n64HeapUnalloc(rdram, ctx);
        goto after_4;
    // 0x800AB6B0: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    after_4:
    // 0x800AB6B4: jal         0x8007E328
    // 0x800AB6B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_5;
    // 0x800AB6B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x800AB6BC: b           L_800AB6EC
    // 0x800AB6C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800AB6EC;
    // 0x800AB6C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800AB6C4:
    // 0x800AB6C4: jal         0x800AA3DC
    // 0x800AB6C8: nop

    func_800AA3DC(rdram, ctx);
        goto after_6;
    // 0x800AB6C8: nop

    after_6:
    // 0x800AB6CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AB6D0: bne         $v0, $at, L_800AB6E0
    if (ctx->r2 != ctx->r1) {
        // 0x800AB6D4: nop
    
            goto L_800AB6E0;
    }
    // 0x800AB6D4: nop

    // 0x800AB6D8: jal         0x8007E328
    // 0x800AB6DC: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    n64HeapUnalloc(rdram, ctx);
        goto after_7;
    // 0x800AB6DC: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    after_7:
L_800AB6E0:
    // 0x800AB6E0: jal         0x800AA3F4
    // 0x800AB6E4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    func_800AA3F4(rdram, ctx);
        goto after_8;
    // 0x800AB6E4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_8:
    // 0x800AB6E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800AB6EC:
    // 0x800AB6EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AB6F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AB6F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AB6F8: jr          $ra
    // 0x800AB6FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AB6FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void CubeTiles_ObjLinkHierarchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB700: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x800AB704: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x800AB708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AB70C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800AB710: addiu       $v1, $t7, 0x20
    ctx->r3 = ADD32(ctx->r15, 0X20);
    // 0x800AB714: blez        $v0, L_800AB78C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AB718: sw          $v1, 0x28($a0)
        MEM_W(0X28, ctx->r4) = ctx->r3;
            goto L_800AB78C;
    }
    // 0x800AB718: sw          $v1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r3;
L_800AB71C:
    // 0x800AB71C: lw          $t9, 0x1C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1C);
    // 0x800AB720: lw          $a2, 0x18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X18);
    // 0x800AB724: sw          $a0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r4;
    // 0x800AB728: addu        $t2, $t9, $a0
    ctx->r10 = ADD32(ctx->r25, ctx->r4);
    // 0x800AB72C: addiu       $a3, $t2, 0x20
    ctx->r7 = ADD32(ctx->r10, 0X20);
    // 0x800AB730: sw          $a3, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r7;
    // 0x800AB734: blez        $a2, L_800AB780
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800AB738: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800AB780;
    }
    // 0x800AB738: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800AB73C:
    // 0x800AB73C: lw          $t4, 0xC($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC);
    // 0x800AB740: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800AB744: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x800AB748: addiu       $t1, $t5, 0x20
    ctx->r9 = ADD32(ctx->r13, 0X20);
    // 0x800AB74C: sw          $t1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r9;
L_800AB750:
    // 0x800AB750: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x800AB754: lh          $t3, 0x0($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X0);
    // 0x800AB758: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800AB75C: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x800AB760: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800AB764: lh          $t2, 0x4($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X4);
    // 0x800AB768: beq         $t2, $t3, L_800AB778
    if (ctx->r10 == ctx->r11) {
        // 0x800AB76C: nop
    
            goto L_800AB778;
    }
    // 0x800AB76C: nop

    // 0x800AB770: b           L_800AB750
    // 0x800AB774: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800AB750;
    // 0x800AB774: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800AB778:
    // 0x800AB778: bne         $t0, $a2, L_800AB73C
    if (ctx->r8 != ctx->r6) {
        // 0x800AB77C: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_800AB73C;
    }
    // 0x800AB77C: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
L_800AB780:
    // 0x800AB780: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800AB784: bne         $a1, $v0, L_800AB71C
    if (ctx->r5 != ctx->r2) {
        // 0x800AB788: addiu       $v1, $v1, 0x24
        ctx->r3 = ADD32(ctx->r3, 0X24);
            goto L_800AB71C;
    }
    // 0x800AB788: addiu       $v1, $v1, 0x24
    ctx->r3 = ADD32(ctx->r3, 0X24);
L_800AB78C:
    // 0x800AB78C: jr          $ra
    // 0x800AB790: nop

    return;
    // 0x800AB790: nop

;}

RECOMP_FUNC void CubeTiles_ObjInitAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB794: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AB798: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AB79C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AB7A0: lw          $t4, 0x24($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X24);
    // 0x800AB7A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AB7A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AB7AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AB7B0: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800AB7B4: lw          $t2, 0x28($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X28);
    // 0x800AB7B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AB7BC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800AB7C0: blez        $t4, L_800AB828
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800AB7C4: swc1        $f4, 0x18($a0)
        MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
            goto L_800AB828;
    }
    // 0x800AB7C4: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x800AB7C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800AB7CC:
    // 0x800AB7CC: lw          $a0, 0x18($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X18);
    // 0x800AB7D0: sw          $s0, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r16;
    // 0x800AB7D4: lw          $a3, 0x1C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X1C);
    // 0x800AB7D8: blez        $a0, L_800AB814
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800AB7DC: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800AB814;
    }
    // 0x800AB7DC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800AB7E0:
    // 0x800AB7E0: lw          $v0, 0xC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC);
    // 0x800AB7E4: sh          $t1, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r9;
    // 0x800AB7E8: lh          $v1, 0x4($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X4);
    // 0x800AB7EC: sw          $v0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r2;
L_800AB7F0:
    // 0x800AB7F0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800AB7F4: beql        $v1, $t6, L_800AB808
    if (ctx->r3 == ctx->r14) {
        // 0x800AB7F8: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800AB808;
    }
    goto skip_0;
    // 0x800AB7F8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x800AB7FC: b           L_800AB7F0
    // 0x800AB800: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800AB7F0;
    // 0x800AB800: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800AB804: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800AB808:
    // 0x800AB808: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x800AB80C: bne         $t0, $a0, L_800AB7E0
    if (ctx->r8 != ctx->r4) {
        // 0x800AB810: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800AB7E0;
    }
    // 0x800AB810: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
L_800AB814:
    // 0x800AB814: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800AB818: addiu       $t2, $t2, 0x24
    ctx->r10 = ADD32(ctx->r10, 0X24);
    // 0x800AB81C: sw          $zero, -0x20($t2)
    MEM_W(-0X20, ctx->r10) = 0;
    // 0x800AB820: bne         $t3, $t4, L_800AB7CC
    if (ctx->r11 != ctx->r12) {
        // 0x800AB824: sw          $zero, -0x1C($t2)
        MEM_W(-0X1C, ctx->r10) = 0;
            goto L_800AB7CC;
    }
    // 0x800AB824: sw          $zero, -0x1C($t2)
    MEM_W(-0X1C, ctx->r10) = 0;
L_800AB828:
    // 0x800AB828: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800AB82C: jal         0x8007E03C
    // 0x800AB830: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800AB830: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_0:
    // 0x800AB834: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800AB838: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800AB83C: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x800AB840: beql        $t3, $zero, L_800AB91C
    if (ctx->r11 == 0) {
        // 0x800AB844: sw          $zero, 0x8($s0)
        MEM_W(0X8, ctx->r16) = 0;
            goto L_800AB91C;
    }
    goto skip_1;
    // 0x800AB844: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    skip_1:
    // 0x800AB848: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AB84C: nop

L_800AB850:
    // 0x800AB850: lw          $t0, 0x18($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X18);
    // 0x800AB854: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x800AB858: lw          $a3, 0x1C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X1C);
    // 0x800AB85C: beq         $t0, $zero, L_800AB910
    if (ctx->r8 == 0) {
        // 0x800AB860: nop
    
            goto L_800AB910;
    }
    // 0x800AB860: nop

L_800AB864:
    // 0x800AB864: lw          $a2, 0xC($a3)
    ctx->r6 = MEM_W(ctx->r7, 0XC);
    // 0x800AB868: sw          $a1, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r5;
    // 0x800AB86C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800AB870: lh          $v1, 0x2($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X2);
    // 0x800AB874: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x800AB878: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800AB87C: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x800AB880: beq         $t7, $zero, L_800AB898
    if (ctx->r15 == 0) {
        // 0x800AB884: sra         $t8, $v1, 1
        ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800AB898;
    }
    // 0x800AB884: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800AB888: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AB88C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AB890: b           L_800AB89C
    // 0x800AB894: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_800AB89C;
    // 0x800AB894: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_800AB898:
    // 0x800AB898: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_800AB89C:
    // 0x800AB89C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800AB8A0: beq         $t9, $zero, L_800AB8B8
    if (ctx->r25 == 0) {
        // 0x800AB8A4: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800AB8B8;
    }
    // 0x800AB8A4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800AB8A8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AB8AC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AB8B0: b           L_800AB8BC
    // 0x800AB8B4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
        goto L_800AB8BC;
    // 0x800AB8B4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_800AB8B8:
    // 0x800AB8B8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800AB8BC:
    // 0x800AB8BC: sra         $t5, $v1, 1
    ctx->r13 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800AB8C0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800AB8C4: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800AB8C8: beq         $t6, $zero, L_800AB8E0
    if (ctx->r14 == 0) {
        // 0x800AB8CC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800AB8E0;
    }
    // 0x800AB8CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AB8D0: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AB8D4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AB8D8: b           L_800AB8E4
    // 0x800AB8DC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_800AB8E4;
    // 0x800AB8DC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_800AB8E0:
    // 0x800AB8E0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800AB8E4:
    // 0x800AB8E4: sra         $t7, $v1, 1
    ctx->r15 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800AB8E8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800AB8EC: beq         $t8, $zero, L_800AB900
    if (ctx->r24 == 0) {
        // 0x800AB8F0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800AB900;
    }
    // 0x800AB8F0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AB8F4: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AB8F8: b           L_800AB904
    // 0x800AB8FC: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
        goto L_800AB904;
    // 0x800AB8FC: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_800AB900:
    // 0x800AB900: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800AB904:
    // 0x800AB904: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x800AB908: bne         $t0, $zero, L_800AB864
    if (ctx->r8 != 0) {
        // 0x800AB90C: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800AB864;
    }
    // 0x800AB90C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
L_800AB910:
    // 0x800AB910: bne         $t3, $zero, L_800AB850
    if (ctx->r11 != 0) {
        // 0x800AB914: addiu       $t2, $t2, 0x24
        ctx->r10 = ADD32(ctx->r10, 0X24);
            goto L_800AB850;
    }
    // 0x800AB914: addiu       $t2, $t2, 0x24
    ctx->r10 = ADD32(ctx->r10, 0X24);
    // 0x800AB918: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
L_800AB91C:
    // 0x800AB91C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800AB920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AB924: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AB928: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800AB92C: jr          $ra
    // 0x800AB930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AB930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AB934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB934: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AB938: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AB93C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AB940: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800AB944: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AB948: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AB94C: bne         $a1, $at, L_800AB974
    if (ctx->r5 != ctx->r1) {
        // 0x800AB950: nop
    
            goto L_800AB974;
    }
    // 0x800AB950: nop

    // 0x800AB954: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x800AB958: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x800AB95C: jal         0x8007E328
    // 0x800AB960: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AB960: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    after_0:
    // 0x800AB964: jal         0x8007E328
    // 0x800AB968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x800AB968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800AB96C: b           L_800AB9A4
    // 0x800AB970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800AB9A4;
    // 0x800AB970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AB974:
    // 0x800AB974: jal         0x800AA3DC
    // 0x800AB978: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA3DC(rdram, ctx);
        goto after_2;
    // 0x800AB978: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800AB97C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AB980: bne         $v0, $at, L_800AB998
    if (ctx->r2 != ctx->r1) {
        // 0x800AB984: nop
    
            goto L_800AB998;
    }
    // 0x800AB984: nop

    // 0x800AB988: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x800AB98C: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x800AB990: jal         0x8007E328
    // 0x800AB994: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    n64HeapUnalloc(rdram, ctx);
        goto after_3;
    // 0x800AB994: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    after_3:
L_800AB998:
    // 0x800AB998: jal         0x800AA3F4
    // 0x800AB99C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800AA3F4(rdram, ctx);
        goto after_4;
    // 0x800AB99C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x800AB9A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AB9A4:
    // 0x800AB9A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AB9A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AB9AC: jr          $ra
    // 0x800AB9B0: nop

    return;
    // 0x800AB9B0: nop

;}

RECOMP_FUNC void func_800AB9B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB9B4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800AB9B8: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800AB9BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AB9C0: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800AB9C4: beq         $t8, $zero, L_800AB9D8
    if (ctx->r24 == 0) {
        // 0x800AB9C8: sw          $t7, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r15;
            goto L_800AB9D8;
    }
    // 0x800AB9C8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800AB9CC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800AB9D0: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x800AB9D4: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
L_800AB9D8:
    // 0x800AB9D8: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800AB9DC: beql        $t1, $zero, L_800AB9F4
    if (ctx->r9 == 0) {
        // 0x800AB9E0: lh          $v0, 0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X2);
            goto L_800AB9F4;
    }
    goto skip_0;
    // 0x800AB9E0: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    skip_0:
    // 0x800AB9E4: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x800AB9E8: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x800AB9EC: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    // 0x800AB9F0: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
L_800AB9F4:
    // 0x800AB9F4: beql        $v0, $zero, L_800ABA10
    if (ctx->r2 == 0) {
        // 0x800AB9F8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800ABA10;
    }
    goto skip_1;
    // 0x800AB9F8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x800AB9FC: beql        $v0, $at, L_800ABA30
    if (ctx->r2 == ctx->r1) {
        // 0x800ABA00: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800ABA30;
    }
    goto skip_2;
    // 0x800ABA00: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_2:
    // 0x800ABA04: jr          $ra
    // 0x800ABA08: nop

    return;
    // 0x800ABA08: nop

    // 0x800ABA0C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800ABA10:
    // 0x800ABA10: lw          $t4, 0x10($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X10);
    // 0x800ABA14: beq         $t4, $zero, L_800ABAB0
    if (ctx->r12 == 0) {
        // 0x800ABA18: nop
    
            goto L_800ABAB0;
    }
    // 0x800ABA18: nop

    // 0x800ABA1C: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x800ABA20: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800ABA24: jr          $ra
    // 0x800ABA28: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    return;
    // 0x800ABA28: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    // 0x800ABA2C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800ABA30:
    // 0x800ABA30: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800ABA34: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800ABA38: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800ABA3C: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800ABA40: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800ABA44: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x800ABA48: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x800ABA4C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800ABA50: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800ABA54: beq         $t3, $zero, L_800ABA68
    if (ctx->r11 == 0) {
        // 0x800ABA58: sw          $t2, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r10;
            goto L_800ABA68;
    }
    // 0x800ABA58: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x800ABA5C: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800ABA60: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800ABA64: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
L_800ABA68:
    // 0x800ABA68: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800ABA6C: beql        $t6, $zero, L_800ABA84
    if (ctx->r14 == 0) {
        // 0x800ABA70: lw          $t9, 0x14($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X14);
            goto L_800ABA84;
    }
    goto skip_3;
    // 0x800ABA70: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    skip_3:
    // 0x800ABA74: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x800ABA78: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800ABA7C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x800ABA80: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
L_800ABA84:
    // 0x800ABA84: beql        $t9, $zero, L_800ABA9C
    if (ctx->r25 == 0) {
        // 0x800ABA88: lw          $t2, 0x24($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X24);
            goto L_800ABA9C;
    }
    goto skip_4;
    // 0x800ABA88: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    skip_4:
    // 0x800ABA8C: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x800ABA90: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x800ABA94: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
    // 0x800ABA98: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
L_800ABA9C:
    // 0x800ABA9C: beq         $t2, $zero, L_800ABAB0
    if (ctx->r10 == 0) {
        // 0x800ABAA0: nop
    
            goto L_800ABAB0;
    }
    // 0x800ABAA0: nop

    // 0x800ABAA4: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x800ABAA8: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800ABAAC: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
L_800ABAB0:
    // 0x800ABAB0: jr          $ra
    // 0x800ABAB4: nop

    return;
    // 0x800ABAB4: nop

;}

RECOMP_FUNC void func_800ABAB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABAB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ABABC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ABAC0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ABAC4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ABAC8: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800ABACC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800ABAD0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800ABAD4: beql        $t6, $zero, L_800ABAEC
    if (ctx->r14 == 0) {
        // 0x800ABAD8: lw          $t9, 0x14($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X14);
            goto L_800ABAEC;
    }
    goto skip_0;
    // 0x800ABAD8: lw          $t9, 0x14($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X14);
    skip_0:
    // 0x800ABADC: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x800ABAE0: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800ABAE4: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x800ABAE8: lw          $t9, 0x14($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X14);
L_800ABAEC:
    // 0x800ABAEC: beq         $t9, $zero, L_800ABAF8
    if (ctx->r25 == 0) {
        // 0x800ABAF0: addu        $t1, $t9, $s1
        ctx->r9 = ADD32(ctx->r25, ctx->r17);
            goto L_800ABAF8;
    }
    // 0x800ABAF0: addu        $t1, $t9, $s1
    ctx->r9 = ADD32(ctx->r25, ctx->r17);
    // 0x800ABAF4: sw          $t1, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r9;
L_800ABAF8:
    // 0x800ABAF8: lw          $t2, 0x18($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X18);
    // 0x800ABAFC: beq         $t2, $zero, L_800ABB08
    if (ctx->r10 == 0) {
        // 0x800ABB00: addu        $t4, $t2, $s1
        ctx->r12 = ADD32(ctx->r10, ctx->r17);
            goto L_800ABB08;
    }
    // 0x800ABB00: addu        $t4, $t2, $s1
    ctx->r12 = ADD32(ctx->r10, ctx->r17);
    // 0x800ABB04: sw          $t4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r12;
L_800ABB08:
    // 0x800ABB08: lw          $t5, 0x1C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X1C);
    // 0x800ABB0C: beq         $t5, $zero, L_800ABB18
    if (ctx->r13 == 0) {
        // 0x800ABB10: addu        $t7, $t5, $s1
        ctx->r15 = ADD32(ctx->r13, ctx->r17);
            goto L_800ABB18;
    }
    // 0x800ABB10: addu        $t7, $t5, $s1
    ctx->r15 = ADD32(ctx->r13, ctx->r17);
    // 0x800ABB14: sw          $t7, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r15;
L_800ABB18:
    // 0x800ABB18: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x800ABB1C: lw          $v0, 0x14($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X14);
    // 0x800ABB20: beq         $v1, $zero, L_800ABB90
    if (ctx->r3 == 0) {
        // 0x800ABB24: andi        $a1, $v1, 0x3
        ctx->r5 = ctx->r3 & 0X3;
            goto L_800ABB90;
    }
    // 0x800ABB24: andi        $a1, $v1, 0x3
    ctx->r5 = ctx->r3 & 0X3;
    // 0x800ABB28: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800ABB2C: beq         $a1, $zero, L_800ABB54
    if (ctx->r5 == 0) {
        // 0x800ABB30: addu        $a0, $a1, $v1
        ctx->r4 = ADD32(ctx->r5, ctx->r3);
            goto L_800ABB54;
    }
    // 0x800ABB30: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_800ABB34:
    // 0x800ABB34: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800ABB38: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800ABB3C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800ABB40: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800ABB44: bne         $a0, $v1, L_800ABB34
    if (ctx->r4 != ctx->r3) {
        // 0x800ABB48: sw          $t9, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r25;
            goto L_800ABB34;
    }
    // 0x800ABB48: sw          $t9, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r25;
    // 0x800ABB4C: beql        $v1, $zero, L_800ABB94
    if (ctx->r3 == 0) {
        // 0x800ABB50: lw          $v1, 0x0($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X0);
            goto L_800ABB94;
    }
    goto skip_1;
    // 0x800ABB50: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    skip_1:
L_800ABB54:
    // 0x800ABB54: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800ABB58: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    // 0x800ABB5C: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x800ABB60: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800ABB64: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800ABB68: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x800ABB6C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x800ABB70: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800ABB74: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800ABB78: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x800ABB7C: sw          $t5, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r13;
    // 0x800ABB80: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800ABB84: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800ABB88: bne         $v1, $zero, L_800ABB54
    if (ctx->r3 != 0) {
        // 0x800ABB8C: sw          $t1, -0x1C($v0)
        MEM_W(-0X1C, ctx->r2) = ctx->r9;
            goto L_800ABB54;
    }
    // 0x800ABB8C: sw          $t1, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->r9;
L_800ABB90:
    // 0x800ABB90: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_800ABB94:
    // 0x800ABB94: lw          $s0, 0x10($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X10);
    // 0x800ABB98: beq         $v1, $zero, L_800ABBC8
    if (ctx->r3 == 0) {
        // 0x800ABB9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800ABBC8;
    }
    // 0x800ABB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800ABBA0:
    // 0x800ABBA0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800ABBA4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800ABBA8: jal         0x800AB9B4
    // 0x800ABBAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800AB9B4(rdram, ctx);
        goto after_0;
    // 0x800ABBAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800ABBB0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800ABBB4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800ABBB8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800ABBBC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800ABBC0: bnel        $v1, $zero, L_800ABBA0
    if (ctx->r3 != 0) {
        // 0x800ABBC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800ABBA0;
    }
    goto skip_2;
    // 0x800ABBC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_800ABBC8:
    // 0x800ABBC8: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800ABBCC: lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X18);
    // 0x800ABBD0: beq         $v1, $zero, L_800ABC88
    if (ctx->r3 == 0) {
        // 0x800ABBD4: andi        $a1, $v1, 0x3
        ctx->r5 = ctx->r3 & 0X3;
            goto L_800ABC88;
    }
    // 0x800ABBD4: andi        $a1, $v1, 0x3
    ctx->r5 = ctx->r3 & 0X3;
    // 0x800ABBD8: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800ABBDC: beq         $a1, $zero, L_800ABC10
    if (ctx->r5 == 0) {
        // 0x800ABBE0: addu        $a0, $a1, $v1
        ctx->r4 = ADD32(ctx->r5, ctx->r3);
            goto L_800ABC10;
    }
    // 0x800ABBE0: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_800ABBE4:
    // 0x800ABBE4: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x800ABBE8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800ABBEC: beq         $t8, $zero, L_800ABC00
    if (ctx->r24 == 0) {
        // 0x800ABBF0: nop
    
            goto L_800ABC00;
    }
    // 0x800ABBF0: nop

    // 0x800ABBF4: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x800ABBF8: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x800ABBFC: sw          $t0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r8;
L_800ABC00:
    // 0x800ABC00: bne         $a0, $v1, L_800ABBE4
    if (ctx->r4 != ctx->r3) {
        // 0x800ABC04: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_800ABBE4;
    }
    // 0x800ABC04: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800ABC08: beql        $v1, $zero, L_800ABC8C
    if (ctx->r3 == 0) {
        // 0x800ABC0C: lw          $v1, 0xC($a2)
        ctx->r3 = MEM_W(ctx->r6, 0XC);
            goto L_800ABC8C;
    }
    goto skip_3;
    // 0x800ABC0C: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
    skip_3:
L_800ABC10:
    // 0x800ABC10: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x800ABC14: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800ABC18: beql        $t1, $zero, L_800ABC30
    if (ctx->r9 == 0) {
        // 0x800ABC1C: lw          $t4, 0x28($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X28);
            goto L_800ABC30;
    }
    goto skip_4;
    // 0x800ABC1C: lw          $t4, 0x28($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X28);
    skip_4:
    // 0x800ABC20: lw          $t2, 0x14($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14);
    // 0x800ABC24: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x800ABC28: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x800ABC2C: lw          $t4, 0x28($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X28);
L_800ABC30:
    // 0x800ABC30: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800ABC34: beql        $t4, $zero, L_800ABC4C
    if (ctx->r12 == 0) {
        // 0x800ABC38: lw          $t7, 0x28($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X28);
            goto L_800ABC4C;
    }
    goto skip_5;
    // 0x800ABC38: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    skip_5:
    // 0x800ABC3C: lw          $t5, 0x14($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X14);
    // 0x800ABC40: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800ABC44: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x800ABC48: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
L_800ABC4C:
    // 0x800ABC4C: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800ABC50: beql        $t7, $zero, L_800ABC68
    if (ctx->r15 == 0) {
        // 0x800ABC54: lw          $t0, 0x28($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X28);
            goto L_800ABC68;
    }
    goto skip_6;
    // 0x800ABC54: lw          $t0, 0x28($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X28);
    skip_6:
    // 0x800ABC58: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x800ABC5C: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800ABC60: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x800ABC64: lw          $t0, 0x28($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X28);
L_800ABC68:
    // 0x800ABC68: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800ABC6C: beq         $t0, $zero, L_800ABC80
    if (ctx->r8 == 0) {
        // 0x800ABC70: nop
    
            goto L_800ABC80;
    }
    // 0x800ABC70: nop

    // 0x800ABC74: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x800ABC78: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x800ABC7C: sw          $t2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r10;
L_800ABC80:
    // 0x800ABC80: bne         $v1, $zero, L_800ABC10
    if (ctx->r3 != 0) {
        // 0x800ABC84: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_800ABC10;
    }
    // 0x800ABC84: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
L_800ABC88:
    // 0x800ABC88: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
L_800ABC8C:
    // 0x800ABC8C: lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C);
    // 0x800ABC90: beq         $v1, $zero, L_800ABD50
    if (ctx->r3 == 0) {
        // 0x800ABC94: andi        $a1, $v1, 0x3
        ctx->r5 = ctx->r3 & 0X3;
            goto L_800ABD50;
    }
    // 0x800ABC94: andi        $a1, $v1, 0x3
    ctx->r5 = ctx->r3 & 0X3;
    // 0x800ABC98: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800ABC9C: beq         $a1, $zero, L_800ABCD4
    if (ctx->r5 == 0) {
        // 0x800ABCA0: addu        $a0, $a1, $v1
        ctx->r4 = ADD32(ctx->r5, ctx->r3);
            goto L_800ABCD4;
    }
    // 0x800ABCA0: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_800ABCA4:
    // 0x800ABCA4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800ABCA8: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x800ABCAC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800ABCB0: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800ABCB4: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800ABCB8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800ABCBC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800ABCC0: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800ABCC4: bne         $a0, $v1, L_800ABCA4
    if (ctx->r4 != ctx->r3) {
        // 0x800ABCC8: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800ABCA4;
    }
    // 0x800ABCC8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800ABCCC: beql        $v1, $zero, L_800ABD54
    if (ctx->r3 == 0) {
        // 0x800ABCD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800ABD54;
    }
    goto skip_7;
    // 0x800ABCD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
L_800ABCD4:
    // 0x800ABCD4: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x800ABCD8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800ABCDC: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800ABCE0: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x800ABCE4: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800ABCE8: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x800ABCEC: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x800ABCF0: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x800ABCF4: lw          $t1, 0x28($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X28);
    // 0x800ABCF8: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x800ABCFC: lw          $t5, 0x18($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X18);
    // 0x800ABD00: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800ABD04: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800ABD08: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800ABD0C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800ABD10: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x800ABD14: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800ABD18: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x800ABD1C: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800ABD20: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800ABD24: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x800ABD28: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    // 0x800ABD2C: sw          $t2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r10;
    // 0x800ABD30: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x800ABD34: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x800ABD38: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800ABD3C: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x800ABD40: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x800ABD44: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x800ABD48: bne         $v1, $zero, L_800ABCD4
    if (ctx->r3 != 0) {
        // 0x800ABD4C: sw          $zero, -0x28($v0)
        MEM_W(-0X28, ctx->r2) = 0;
            goto L_800ABCD4;
    }
    // 0x800ABD4C: sw          $zero, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = 0;
L_800ABD50:
    // 0x800ABD50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800ABD54:
    // 0x800ABD54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ABD58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ABD5C: jr          $ra
    // 0x800ABD60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ABD60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800ABD64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABD64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ABD68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800ABD6C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800ABD70: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800ABD74: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ABD78: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ABD7C: lw          $s3, 0x8($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X8);
    // 0x800ABD80: lw          $s2, 0x18($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X18);
    // 0x800ABD84: beql        $s3, $zero, L_800ABDC4
    if (ctx->r19 == 0) {
        // 0x800ABD88: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800ABDC4;
    }
    goto skip_0;
    // 0x800ABD88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_800ABD8C:
    // 0x800ABD8C: lw          $s1, 0x10($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X10);
    // 0x800ABD90: lw          $s0, 0x14($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X14);
    // 0x800ABD94: beql        $s1, $zero, L_800ABDB8
    if (ctx->r17 == 0) {
        // 0x800ABD98: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_800ABDB8;
    }
    goto skip_1;
    // 0x800ABD98: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_1:
L_800ABD9C:
    // 0x800ABD9C: jal         0x800AA14C
    // 0x800ABDA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    CubeTiles_ObjInstantiate(rdram, ctx);
        goto after_0;
    // 0x800ABDA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x800ABDA4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800ABDA8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800ABDAC: bne         $s1, $zero, L_800ABD9C
    if (ctx->r17 != 0) {
        // 0x800ABDB0: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_800ABD9C;
    }
    // 0x800ABDB0: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x800ABDB4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_800ABDB8:
    // 0x800ABDB8: bne         $s3, $zero, L_800ABD8C
    if (ctx->r19 != 0) {
        // 0x800ABDBC: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_800ABD8C;
    }
    // 0x800ABDBC: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x800ABDC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800ABDC4:
    // 0x800ABDC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ABDC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ABDCC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABDD0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800ABDD4: jr          $ra
    // 0x800ABDD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ABDD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800ABDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABDDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ABDE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ABDE4: jal         0x800AA14C
    // 0x800ABDE8: nop

    CubeTiles_ObjInstantiate(rdram, ctx);
        goto after_0;
    // 0x800ABDE8: nop

    after_0:
    // 0x800ABDEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ABDF0: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800ABDF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800ABDF8: jr          $ra
    // 0x800ABDFC: nop

    return;
    // 0x800ABDFC: nop

;}

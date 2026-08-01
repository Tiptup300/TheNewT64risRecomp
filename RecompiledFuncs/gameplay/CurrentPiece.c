#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void CurrentPiece_UpdateGhost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066920: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80066924: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80066928: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006692C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80066930: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80066934: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80066938: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006693C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066940: lh          $t7, 0x2E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2E);
    // 0x80066944: addiu       $a0, $t6, 0x540
    ctx->r4 = ADD32(ctx->r14, 0X540);
    // 0x80066948: sh          $t7, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r15;
    // 0x8006694C: lb          $t8, 0x12($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X12);
    // 0x80066950: nop

    // 0x80066954: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80066958: sh          $t9, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r25;
    // 0x8006695C: lh          $t0, 0x2A($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X2A);
    // 0x80066960: lwl         $t4, 0x30($sp)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r29, 0X30);
    // 0x80066964: sh          $t0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r8;
    // 0x80066968: lb          $t1, 0x10($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X10);
    // 0x8006696C: lwr         $t4, 0x33($sp)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r29, 0X33);
    // 0x80066970: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x80066974: addiu       $t3, $t2, 0x80
    ctx->r11 = ADD32(ctx->r10, 0X80);
    // 0x80066978: sh          $t3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r11;
    // 0x8006697C: lwl         $t5, 0x2C($sp)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r29, 0X2C);
    // 0x80066980: lwr         $t5, 0x2F($sp)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r29, 0X2F);
    // 0x80066984: swl         $t4, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r12);
    // 0x80066988: swl         $t5, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r13);
    // 0x8006698C: swr         $t4, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r12);
    // 0x80066990: swr         $t5, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r13);
    // 0x80066994: lbu         $a3, 0xA($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0XA);
    // 0x80066998: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8006699C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x800669A0: sll         $t7, $a3, 14
    ctx->r15 = S32(ctx->r7 << 14);
    // 0x800669A4: jal         0x800667DC
    // 0x800669A8: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    GhostPiece_Update(rdram, ctx);
        goto after_0;
    // 0x800669A8: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    after_0:
    // 0x800669AC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800669B0: nop

    // 0x800669B4: lh          $s0, 0x556($t8)
    ctx->r16 = MEM_H(ctx->r24, 0X556);
    // 0x800669B8: lh          $s1, 0x558($t8)
    ctx->r17 = MEM_H(ctx->r24, 0X558);
    // 0x800669BC: lhu         $s2, 0x550($t8)
    ctx->r18 = MEM_HU(ctx->r24, 0X550);
    // 0x800669C0: sra         $t9, $s0, 8
    ctx->r25 = S32(SIGNED(ctx->r16) >> 8);
    // 0x800669C4: sra         $t1, $s1, 8
    ctx->r9 = S32(SIGNED(ctx->r17) >> 8);
    // 0x800669C8: sra         $t3, $s2, 14
    ctx->r11 = S32(SIGNED(ctx->r18) >> 14);
    // 0x800669CC: lbu         $t5, 0xA6A($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0XA6A);
    // 0x800669D0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x800669D4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800669D8: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x800669DC: andi        $t0, $s0, 0xFF
    ctx->r8 = ctx->r16 & 0XFF;
    // 0x800669E0: andi        $t2, $s1, 0xFF
    ctx->r10 = ctx->r17 & 0XFF;
    // 0x800669E4: andi        $t4, $s2, 0xFF
    ctx->r12 = ctx->r18 & 0XFF;
    // 0x800669E8: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x800669EC: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x800669F0: beq         $t5, $zero, L_80066A48
    if (ctx->r13 == 0) {
        // 0x800669F4: or          $s2, $t4, $zero
        ctx->r18 = ctx->r12 | 0;
            goto L_80066A48;
    }
    // 0x800669F4: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
    // 0x800669F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800669FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80066A00: jal         0x8003DDA8
    // 0x80066A04: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    aisquarelist_PieceCanCompleteSquare(rdram, ctx);
        goto after_1;
    // 0x80066A04: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x80066A08: bne         $v0, $zero, L_80066A28
    if (ctx->r2 != 0) {
        // 0x80066A0C: nop
    
            goto L_80066A28;
    }
    // 0x80066A0C: nop

    // 0x80066A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066A14: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80066A18: jal         0x8003DBC0
    // 0x80066A1C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    Controller_TestPieceTransforms(rdram, ctx);
        goto after_2;
    // 0x80066A1C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x80066A20: beq         $v0, $zero, L_80066A3C
    if (ctx->r2 == 0) {
        // 0x80066A24: nop
    
            goto L_80066A3C;
    }
    // 0x80066A24: nop

L_80066A28:
    // 0x80066A28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80066A2C: jal         0x80065620
    // 0x80066A30: addiu       $a0, $a0, 0xA40
    ctx->r4 = ADD32(ctx->r4, 0XA40);
    MobilePiece_EnableAltColor(rdram, ctx);
        goto after_3;
    // 0x80066A30: addiu       $a0, $a0, 0xA40
    ctx->r4 = ADD32(ctx->r4, 0XA40);
    after_3:
    // 0x80066A34: b           L_80066A48
    // 0x80066A38: nop

        goto L_80066A48;
    // 0x80066A38: nop

L_80066A3C:
    // 0x80066A3C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80066A40: jal         0x8006567C
    // 0x80066A44: addiu       $a0, $a0, 0xA40
    ctx->r4 = ADD32(ctx->r4, 0XA40);
    MobilePiece_DisableAltColor(rdram, ctx);
        goto after_4;
    // 0x80066A44: addiu       $a0, $a0, 0xA40
    ctx->r4 = ADD32(ctx->r4, 0XA40);
    after_4:
L_80066A48:
    // 0x80066A48: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80066A4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80066A50: jal         0x80065154
    // 0x80066A54: addiu       $a0, $a0, 0x548
    ctx->r4 = ADD32(ctx->r4, 0X548);
    MobilePiece_AnyCubeAboveRow(rdram, ctx);
        goto after_5;
    // 0x80066A54: addiu       $a0, $a0, 0x548
    ctx->r4 = ADD32(ctx->r4, 0X548);
    after_5:
    // 0x80066A58: beq         $v0, $zero, L_80066A74
    if (ctx->r2 == 0) {
        // 0x80066A5C: nop
    
            goto L_80066A74;
    }
    // 0x80066A5C: nop

    // 0x80066A60: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80066A64: jal         0x80065620
    // 0x80066A68: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    MobilePiece_EnableAltColor(rdram, ctx);
        goto after_6;
    // 0x80066A68: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    after_6:
    // 0x80066A6C: b           L_80066A80
    // 0x80066A70: nop

        goto L_80066A80;
    // 0x80066A70: nop

L_80066A74:
    // 0x80066A74: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80066A78: jal         0x8006567C
    // 0x80066A7C: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    MobilePiece_DisableAltColor(rdram, ctx);
        goto after_7;
    // 0x80066A7C: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    after_7:
L_80066A80:
    // 0x80066A80: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80066A84: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80066A88: jal         0x800666D0
    // 0x80066A8C: addiu       $a0, $a0, 0x540
    ctx->r4 = ADD32(ctx->r4, 0X540);
    GhostPiece_MorphCubes(rdram, ctx);
        goto after_8;
    // 0x80066A8C: addiu       $a0, $a0, 0x540
    ctx->r4 = ADD32(ctx->r4, 0X540);
    after_8:
    // 0x80066A90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80066A94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066A98: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80066A9C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80066AA0: jr          $ra
    // 0x80066AA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80066AA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void getCurPieceSpawnPoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066AA8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80066AAC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80066AB0: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x80066AB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066AB8: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80066ABC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80066AC0: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x80066AC4: lw          $s0, 0x110($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X110);
    // 0x80066AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066ACC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80066AD0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80066AD4: jal         0x80054ED0
    // 0x80066AD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    getCurPieceSpawnOffsetAsPoint(rdram, ctx);
        goto after_0;
    // 0x80066AD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80066ADC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80066AE0: lh          $t9, 0x520($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X520);
    // 0x80066AE4: lh          $t8, 0x24($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X24);
    // 0x80066AE8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80066AEC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80066AF0: sh          $t0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r8;
    // 0x80066AF4: jal         0x80054ED0
    // 0x80066AF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    getCurPieceSpawnOffsetAsPoint(rdram, ctx);
        goto after_1;
    // 0x80066AF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80066AFC: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80066B00: lh          $t2, 0x522($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X522);
    // 0x80066B04: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x80066B08: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x80066B0C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80066B10: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
    // 0x80066B14: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x80066B18: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80066B1C: nop

    // 0x80066B20: swl         $at, 0x0($t4)
    do_swl(rdram, 0X0, ctx->r12, ctx->r1);
    // 0x80066B24: swr         $at, 0x3($t4)
    do_swr(rdram, 0X3, ctx->r12, ctx->r1);
    // 0x80066B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066B2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066B30: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80066B34: jr          $ra
    // 0x80066B38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80066B38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void getStartingOriginOfRotationPoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066B3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80066B40: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80066B44: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x80066B48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066B4C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80066B50: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80066B54: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x80066B58: lw          $s0, 0x110($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X110);
    // 0x80066B5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066B60: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80066B64: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80066B68: jal         0x80054F08
    // 0x80066B6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    getStartingRotOriginAsPoint(rdram, ctx);
        goto after_0;
    // 0x80066B6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80066B70: lh          $t8, 0x20($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X20);
    // 0x80066B74: lh          $t0, 0x22($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X22);
    // 0x80066B78: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x80066B7C: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x80066B80: sh          $t9, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r25;
    // 0x80066B84: sh          $t1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r9;
    // 0x80066B88: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x80066B8C: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80066B90: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80066B94: nop

    // 0x80066B98: swl         $at, 0x0($t2)
    do_swl(rdram, 0X0, ctx->r10, ctx->r1);
    // 0x80066B9C: swr         $at, 0x3($t2)
    do_swr(rdram, 0X3, ctx->r10, ctx->r1);
    // 0x80066BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066BA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066BA8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80066BAC: jr          $ra
    // 0x80066BB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80066BB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void getStartingRotationAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066BB4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80066BB8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066BBC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80066BC0: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80066BC4: lw          $a1, 0x110($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X110);
    // 0x80066BC8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80066BCC: lbu         $v0, 0x1E($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1E);
    // 0x80066BD0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80066BD4: sll         $t7, $v0, 14
    ctx->r15 = S32(ctx->r2 << 14);
    // 0x80066BD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066BDC: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x80066BE0: jr          $ra
    // 0x80066BE4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x80066BE4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}

RECOMP_FUNC void getStartingRotationState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066BE8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80066BEC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066BF0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80066BF4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80066BF8: lw          $t7, 0x110($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X110);
    // 0x80066BFC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80066C00: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80066C04: lbu         $v0, 0x1E($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1E);
    // 0x80066C08: jr          $ra
    // 0x80066C0C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80066C0C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void rotate_and_translate_mino(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C10: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80066C14: lw          $a2, -0x490($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X490);
    // 0x80066C18: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80066C1C: lbu         $t6, 0xA($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XA);
    // 0x80066C20: addiu       $t8, $t8, 0x260
    ctx->r24 = ADD32(ctx->r24, 0X260);
    // 0x80066C24: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80066C28: lbu         $t4, 0xA($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XA);
    // 0x80066C2C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80066C30: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80066C34: lw          $t7, 0x24($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X24);
    // 0x80066C38: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80066C3C: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80066C40: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80066C44: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x80066C48: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x80066C4C: lb          $t4, 0x1($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X1);
    // 0x80066C50: lb          $t5, 0xF($a2)
    ctx->r13 = MEM_B(ctx->r6, 0XF);
    // 0x80066C54: lw          $t2, 0x4($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X4);
    // 0x80066C58: subu        $a3, $t4, $t5
    ctx->r7 = SUB32(ctx->r12, ctx->r13);
    // 0x80066C5C: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066C60: lb          $t8, 0x2($t3)
    ctx->r24 = MEM_B(ctx->r11, 0X2);
    // 0x80066C64: lb          $t6, 0x10($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X10);
    // 0x80066C68: lb          $t5, 0x11($a2)
    ctx->r13 = MEM_B(ctx->r6, 0X11);
    // 0x80066C6C: subu        $t0, $t8, $t6
    ctx->r8 = SUB32(ctx->r24, ctx->r14);
    // 0x80066C70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066C74: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80066C78: mflo        $t7
    ctx->r15 = lo;
    // 0x80066C7C: nop

    // 0x80066C80: nop

    // 0x80066C84: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066C88: mflo        $t9
    ctx->r25 = lo;
    // 0x80066C8C: subu        $t4, $t7, $t9
    ctx->r12 = SUB32(ctx->r15, ctx->r25);
    // 0x80066C90: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x80066C94: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066C98: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x80066C9C: lb          $t4, 0x12($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X12);
    // 0x80066CA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066CA4: mflo        $t6
    ctx->r14 = lo;
    // 0x80066CA8: nop

    // 0x80066CAC: nop

    // 0x80066CB0: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066CB4: mflo        $t7
    ctx->r15 = lo;
    // 0x80066CB8: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80066CBC: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x80066CC0: jr          $ra
    // 0x80066CC4: sb          $t5, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r13;
    return;
    // 0x80066CC4: sb          $t5, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r13;
;}

RECOMP_FUNC void CurrentPiece_WriteMinosToBoard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066CC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80066CCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066CD0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80066CD4: lw          $s0, -0x490($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X490);
    // 0x80066CD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066CDC: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
    // 0x80066CE0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80066CE4: addiu       $t8, $s0, 0x15
    ctx->r24 = ADD32(ctx->r16, 0X15);
    // 0x80066CE8: sb          $t7, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r15;
    // 0x80066CEC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80066CF0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80066CF4: jal         0x8006DF38
    // 0x80066CF8: sb          $t6, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r14;
    BoardP_PlaceMultisquareCubes(rdram, ctx);
        goto after_0;
    // 0x80066CF8: sb          $t6, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x80066CFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066D00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066D04: jr          $ra
    // 0x80066D08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80066D08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void CurrentPiece_CanPlace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066D0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80066D10: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80066D14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80066D18: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80066D1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066D20: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80066D24: beq         $at, $zero, L_80066D74
    if (ctx->r1 == 0) {
        // 0x80066D28: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_80066D74;
    }
    // 0x80066D28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
L_80066D2C:
    // 0x80066D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066D30: jal         0x80066C10
    // 0x80066D34: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    rotate_and_translate_mino(rdram, ctx);
        goto after_0;
    // 0x80066D34: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80066D38: lb          $a0, 0x28($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X28);
    // 0x80066D3C: lb          $a1, 0x29($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X29);
    // 0x80066D40: jal         0x8006E5E0
    // 0x80066D44: nop

    BoardP_PlayfieldXYToLogicCell(rdram, ctx);
        goto after_1;
    // 0x80066D44: nop

    after_1:
    // 0x80066D48: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80066D4C: lbu         $t6, 0x1($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1);
    // 0x80066D50: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80066D54: beq         $t6, $at, L_80066D64
    if (ctx->r14 == ctx->r1) {
        // 0x80066D58: nop
    
            goto L_80066D64;
    }
    // 0x80066D58: nop

    // 0x80066D5C: b           L_80066D78
    // 0x80066D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80066D78;
    // 0x80066D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80066D64:
    // 0x80066D64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80066D68: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80066D6C: bne         $at, $zero, L_80066D2C
    if (ctx->r1 != 0) {
        // 0x80066D70: nop
    
            goto L_80066D2C;
    }
    // 0x80066D70: nop

L_80066D74:
    // 0x80066D74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80066D78:
    // 0x80066D78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066D7C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80066D80: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80066D84: jr          $ra
    // 0x80066D88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80066D88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void CurrentPiece_TestTransform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066D8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80066D90: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80066D94: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80066D98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066D9C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80066DA0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80066DA4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80066DA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80066DAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80066DB0: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x80066DB4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80066DB8: lb          $t9, 0x11($t6)
    ctx->r25 = MEM_B(ctx->r14, 0X11);
    // 0x80066DBC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80066DC0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80066DC4: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x80066DC8: lw          $s0, 0x110($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X110);
    // 0x80066DCC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80066DD0: sb          $t1, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r9;
    // 0x80066DD4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80066DD8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80066DDC: lb          $t3, 0x12($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X12);
    // 0x80066DE0: nop

    // 0x80066DE4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80066DE8: sb          $t5, 0x12($t2)
    MEM_B(0X12, ctx->r10) = ctx->r13;
    // 0x80066DEC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80066DF0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80066DF4: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x80066DF8: nop

    // 0x80066DFC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80066E00: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80066E04: sb          $t1, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r9;
    // 0x80066E08: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80066E0C: nop

    // 0x80066E10: lbu         $t3, 0xA($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0XA);
    // 0x80066E14: nop

    // 0x80066E18: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80066E1C: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x80066E20: lbu         $at, 0xE($t5)
    ctx->r1 = MEM_BU(ctx->r13, 0XE);
    // 0x80066E24: nop

    // 0x80066E28: sb          $at, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r1;
    // 0x80066E2C: lbu         $t8, 0xF($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0XF);
    // 0x80066E30: nop

    // 0x80066E34: sb          $t8, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r24;
    // 0x80066E38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80066E3C: jal         0x80066D0C
    // 0x80066E40: nop

    CurrentPiece_CanPlace(rdram, ctx);
        goto after_0;
    // 0x80066E40: nop

    after_0:
    // 0x80066E44: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80066E48: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80066E4C: lb          $t0, 0x11($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X11);
    // 0x80066E50: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x80066E54: subu        $t7, $t0, $t1
    ctx->r15 = SUB32(ctx->r8, ctx->r9);
    // 0x80066E58: sb          $t7, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r15;
    // 0x80066E5C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80066E60: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80066E64: lb          $t4, 0x12($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X12);
    // 0x80066E68: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80066E6C: subu        $t6, $t4, $t2
    ctx->r14 = SUB32(ctx->r12, ctx->r10);
    // 0x80066E70: sb          $t6, 0x12($t3)
    MEM_B(0X12, ctx->r11) = ctx->r14;
    // 0x80066E74: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80066E78: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80066E7C: lbu         $t8, 0xA($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0XA);
    // 0x80066E80: nop

    // 0x80066E84: subu        $t1, $t8, $t0
    ctx->r9 = SUB32(ctx->r24, ctx->r8);
    // 0x80066E88: andi        $t7, $t1, 0x3
    ctx->r15 = ctx->r9 & 0X3;
    // 0x80066E8C: sb          $t7, 0xA($t5)
    MEM_B(0XA, ctx->r13) = ctx->r15;
    // 0x80066E90: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80066E94: nop

    // 0x80066E98: lbu         $t4, 0xA($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0XA);
    // 0x80066E9C: nop

    // 0x80066EA0: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x80066EA4: addu        $t6, $s0, $t2
    ctx->r14 = ADD32(ctx->r16, ctx->r10);
    // 0x80066EA8: lbu         $at, 0xE($t6)
    ctx->r1 = MEM_BU(ctx->r14, 0XE);
    // 0x80066EAC: nop

    // 0x80066EB0: sb          $at, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r1;
    // 0x80066EB4: lbu         $t8, 0xF($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0XF);
    // 0x80066EB8: nop

    // 0x80066EBC: sb          $t8, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r24;
    // 0x80066EC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066EC4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80066EC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80066ECC: jr          $ra
    // 0x80066ED0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80066ED0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void CurrentPiece_TryTransform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066ED4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80066ED8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80066EDC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80066EE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066EE4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80066EE8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80066EEC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80066EF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066EF4: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x80066EF8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80066EFC: lb          $t9, 0x11($t6)
    ctx->r25 = MEM_B(ctx->r14, 0X11);
    // 0x80066F00: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80066F04: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80066F08: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x80066F0C: lw          $s0, 0x110($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X110);
    // 0x80066F10: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80066F14: sb          $t1, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r9;
    // 0x80066F18: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80066F1C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80066F20: lb          $t3, 0x12($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X12);
    // 0x80066F24: nop

    // 0x80066F28: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80066F2C: sb          $t5, 0x12($t2)
    MEM_B(0X12, ctx->r10) = ctx->r13;
    // 0x80066F30: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80066F34: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80066F38: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x80066F3C: nop

    // 0x80066F40: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80066F44: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80066F48: sb          $t1, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r9;
    // 0x80066F4C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80066F50: nop

    // 0x80066F54: lbu         $t3, 0xA($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0XA);
    // 0x80066F58: nop

    // 0x80066F5C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80066F60: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x80066F64: lbu         $at, 0xE($t5)
    ctx->r1 = MEM_BU(ctx->r13, 0XE);
    // 0x80066F68: nop

    // 0x80066F6C: sb          $at, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r1;
    // 0x80066F70: lbu         $t8, 0xF($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0XF);
    // 0x80066F74: nop

    // 0x80066F78: sb          $t8, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r24;
    // 0x80066F7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80066F80: jal         0x80066D0C
    // 0x80066F84: nop

    CurrentPiece_CanPlace(rdram, ctx);
        goto after_0;
    // 0x80066F84: nop

    after_0:
    // 0x80066F88: bne         $v0, $zero, L_8006700C
    if (ctx->r2 != 0) {
        // 0x80066F8C: nop
    
            goto L_8006700C;
    }
    // 0x80066F8C: nop

    // 0x80066F90: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80066F94: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80066F98: lb          $t0, 0x11($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X11);
    // 0x80066F9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80066FA0: subu        $t7, $t0, $t1
    ctx->r15 = SUB32(ctx->r8, ctx->r9);
    // 0x80066FA4: sb          $t7, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r15;
    // 0x80066FA8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80066FAC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80066FB0: lb          $t4, 0x12($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X12);
    // 0x80066FB4: nop

    // 0x80066FB8: subu        $t6, $t4, $t2
    ctx->r14 = SUB32(ctx->r12, ctx->r10);
    // 0x80066FBC: sb          $t6, 0x12($t3)
    MEM_B(0X12, ctx->r11) = ctx->r14;
    // 0x80066FC0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80066FC4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80066FC8: lbu         $t8, 0xA($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0XA);
    // 0x80066FCC: nop

    // 0x80066FD0: subu        $t1, $t8, $t0
    ctx->r9 = SUB32(ctx->r24, ctx->r8);
    // 0x80066FD4: andi        $t7, $t1, 0x3
    ctx->r15 = ctx->r9 & 0X3;
    // 0x80066FD8: sb          $t7, 0xA($t5)
    MEM_B(0XA, ctx->r13) = ctx->r15;
    // 0x80066FDC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80066FE0: nop

    // 0x80066FE4: lbu         $t4, 0xA($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0XA);
    // 0x80066FE8: nop

    // 0x80066FEC: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x80066FF0: addu        $t6, $s0, $t2
    ctx->r14 = ADD32(ctx->r16, ctx->r10);
    // 0x80066FF4: lbu         $at, 0xE($t6)
    ctx->r1 = MEM_BU(ctx->r14, 0XE);
    // 0x80066FF8: nop

    // 0x80066FFC: sb          $at, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r1;
    // 0x80067000: lbu         $t8, 0xF($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0XF);
    // 0x80067004: b           L_80067010
    // 0x80067008: sb          $t8, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r24;
        goto L_80067010;
    // 0x80067008: sb          $t8, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r24;
L_8006700C:
    // 0x8006700C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80067010:
    // 0x80067010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80067014: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80067018: jr          $ra
    // 0x8006701C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006701C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void CurrentPiece_IsAtLanding(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067020: lb          $t6, 0x11($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X11);
    // 0x80067024: lh          $t8, 0x2E($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2E);
    // 0x80067028: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8006702C: bne         $t7, $t8, L_80067048
    if (ctx->r15 != ctx->r24) {
        // 0x80067030: nop
    
            goto L_80067048;
    }
    // 0x80067030: nop

    // 0x80067034: lb          $t9, 0x12($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X12);
    // 0x80067038: lh          $t1, 0x30($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X30);
    // 0x8006703C: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x80067040: beq         $t0, $t1, L_80067050
    if (ctx->r8 == ctx->r9) {
        // 0x80067044: nop
    
            goto L_80067050;
    }
    // 0x80067044: nop

L_80067048:
    // 0x80067048: jr          $ra
    // 0x8006704C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006704C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80067050:
    // 0x80067050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80067054: jr          $ra
    // 0x80067058: nop

    return;
    // 0x80067058: nop

;}

RECOMP_FUNC void CurrentPiece_AdvanceFall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006705C: lh          $t6, 0x30($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X30);
    // 0x80067060: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x80067064: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80067068: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006706C: sh          $t8, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r24;
    // 0x80067070: jr          $ra
    // 0x80067074: sb          $t9, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r25;
    return;
    // 0x80067074: sb          $t9, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r25;
;}

RECOMP_FUNC void CurrentPiece_TryStepDown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006707C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067080: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80067084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067088: lb          $t8, 0x11($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X11);
    // 0x8006708C: lh          $t7, 0x2E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2E);
    // 0x80067090: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80067094: bne         $t7, $t9, L_800670B8
    if (ctx->r15 != ctx->r25) {
        // 0x80067098: nop
    
            goto L_800670B8;
    }
    // 0x80067098: nop

    // 0x8006709C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800670A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800670A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800670A8: jal         0x80066ED4
    // 0x800670AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    CurrentPiece_TryTransform(rdram, ctx);
        goto after_0;
    // 0x800670AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800670B0: b           L_8006714C
    // 0x800670B4: nop

        goto L_8006714C;
    // 0x800670B4: nop

L_800670B8:
    // 0x800670B8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800670BC: nop

    // 0x800670C0: lb          $t2, 0x11($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X11);
    // 0x800670C4: lh          $t1, 0x2E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2E);
    // 0x800670C8: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x800670CC: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800670D0: beq         $at, $zero, L_80067110
    if (ctx->r1 == 0) {
        // 0x800670D4: nop
    
            goto L_80067110;
    }
    // 0x800670D4: nop

    // 0x800670D8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800670DC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800670E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800670E4: jal         0x80066D8C
    // 0x800670E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    CurrentPiece_TestTransform(rdram, ctx);
        goto after_1;
    // 0x800670E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800670EC: beq         $v0, $zero, L_80067148
    if (ctx->r2 == 0) {
        // 0x800670F0: nop
    
            goto L_80067148;
    }
    // 0x800670F0: nop

    // 0x800670F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800670F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800670FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80067100: jal         0x80066ED4
    // 0x80067104: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    CurrentPiece_TryTransform(rdram, ctx);
        goto after_2;
    // 0x80067104: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80067108: b           L_8006714C
    // 0x8006710C: nop

        goto L_8006714C;
    // 0x8006710C: nop

L_80067110:
    // 0x80067110: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80067114: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80067118: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006711C: jal         0x80066D8C
    // 0x80067120: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    CurrentPiece_TestTransform(rdram, ctx);
        goto after_3;
    // 0x80067120: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80067124: beq         $v0, $zero, L_80067148
    if (ctx->r2 == 0) {
        // 0x80067128: nop
    
            goto L_80067148;
    }
    // 0x80067128: nop

    // 0x8006712C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80067130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80067134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80067138: jal         0x80066ED4
    // 0x8006713C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    CurrentPiece_TryTransform(rdram, ctx);
        goto after_4;
    // 0x8006713C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80067140: b           L_8006714C
    // 0x80067144: nop

        goto L_8006714C;
    // 0x80067144: nop

L_80067148:
    // 0x80067148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006714C:
    // 0x8006714C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067154: jr          $ra
    // 0x80067158: nop

    return;
    // 0x80067158: nop

;}

RECOMP_FUNC void CurrentPiece_MoveLeft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006715C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067160: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006716C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80067170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80067174: jal         0x80066D8C
    // 0x80067178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    CurrentPiece_TestTransform(rdram, ctx);
        goto after_0;
    // 0x80067178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8006717C: beq         $v0, $zero, L_80067244
    if (ctx->r2 == 0) {
        // 0x80067180: nop
    
            goto L_80067244;
    }
    // 0x80067180: nop

    // 0x80067184: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80067188: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006718C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80067190: jal         0x80066D8C
    // 0x80067194: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    CurrentPiece_TestTransform(rdram, ctx);
        goto after_1;
    // 0x80067194: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80067198: beq         $v0, $zero, L_800671E4
    if (ctx->r2 == 0) {
        // 0x8006719C: nop
    
            goto L_800671E4;
    }
    // 0x8006719C: nop

    // 0x800671A0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800671A4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800671A8: lb          $t7, 0x11($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X11);
    // 0x800671AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800671B0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800671B4: sb          $t8, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r24;
    // 0x800671B8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800671BC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800671C0: lbu         $t0, 0x2($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2);
    // 0x800671C4: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x800671C8: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800671CC: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x800671D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800671D4: jal         0x8008A5C8
    // 0x800671D8: sb          $t1, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r9;
    Audio2_Play_SFX(rdram, ctx);
        goto after_2;
    // 0x800671D8: sb          $t1, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r9;
    after_2:
    // 0x800671DC: b           L_80067244
    // 0x800671E0: nop

        goto L_80067244;
    // 0x800671E0: nop

L_800671E4:
    // 0x800671E4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800671E8: nop

    // 0x800671EC: lbu         $t3, 0x3($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3);
    // 0x800671F0: nop

    // 0x800671F4: beq         $t3, $zero, L_80067244
    if (ctx->r11 == 0) {
        // 0x800671F8: nop
    
            goto L_80067244;
    }
    // 0x800671F8: nop

    // 0x800671FC: lb          $t4, 0x12($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X12);
    // 0x80067200: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80067204: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x80067208: sh          $t5, 0x30($t2)
    MEM_H(0X30, ctx->r10) = ctx->r13;
    // 0x8006720C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80067210: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80067214: lb          $t8, 0x11($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X11);
    // 0x80067218: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006721C: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80067220: sb          $t6, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r14;
    // 0x80067224: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80067228: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x8006722C: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x80067230: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80067234: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x80067238: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006723C: jal         0x8008A5C8
    // 0x80067240: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
    Audio2_Play_SFX(rdram, ctx);
        goto after_3;
    // 0x80067240: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
    after_3:
L_80067244:
    // 0x80067244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006724C: jr          $ra
    // 0x80067250: nop

    return;
    // 0x80067250: nop

;}

RECOMP_FUNC void CurrentPiece_MoveRight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006725C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80067264: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80067268: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006726C: jal         0x80066D8C
    // 0x80067270: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    CurrentPiece_TestTransform(rdram, ctx);
        goto after_0;
    // 0x80067270: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80067274: beq         $v0, $zero, L_8006733C
    if (ctx->r2 == 0) {
        // 0x80067278: nop
    
            goto L_8006733C;
    }
    // 0x80067278: nop

    // 0x8006727C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80067280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80067284: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80067288: jal         0x80066D8C
    // 0x8006728C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    CurrentPiece_TestTransform(rdram, ctx);
        goto after_1;
    // 0x8006728C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80067290: beq         $v0, $zero, L_800672DC
    if (ctx->r2 == 0) {
        // 0x80067294: nop
    
            goto L_800672DC;
    }
    // 0x80067294: nop

    // 0x80067298: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006729C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800672A0: lb          $t7, 0x11($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X11);
    // 0x800672A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800672A8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800672AC: sb          $t8, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r24;
    // 0x800672B0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800672B4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800672B8: lbu         $t0, 0x2($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2);
    // 0x800672BC: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x800672C0: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800672C4: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x800672C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800672CC: jal         0x8008A5C8
    // 0x800672D0: sb          $t1, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r9;
    Audio2_Play_SFX(rdram, ctx);
        goto after_2;
    // 0x800672D0: sb          $t1, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r9;
    after_2:
    // 0x800672D4: b           L_8006733C
    // 0x800672D8: nop

        goto L_8006733C;
    // 0x800672D8: nop

L_800672DC:
    // 0x800672DC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800672E0: nop

    // 0x800672E4: lbu         $t3, 0x3($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3);
    // 0x800672E8: nop

    // 0x800672EC: beq         $t3, $zero, L_8006733C
    if (ctx->r11 == 0) {
        // 0x800672F0: nop
    
            goto L_8006733C;
    }
    // 0x800672F0: nop

    // 0x800672F4: lb          $t4, 0x12($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X12);
    // 0x800672F8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800672FC: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x80067300: sh          $t5, 0x30($t2)
    MEM_H(0X30, ctx->r10) = ctx->r13;
    // 0x80067304: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80067308: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006730C: lb          $t8, 0x11($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X11);
    // 0x80067310: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80067314: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80067318: sb          $t6, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r14;
    // 0x8006731C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80067320: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80067324: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x80067328: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8006732C: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x80067330: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80067334: jal         0x8008A5C8
    // 0x80067338: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
    Audio2_Play_SFX(rdram, ctx);
        goto after_3;
    // 0x80067338: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
    after_3:
L_8006733C:
    // 0x8006733C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067344: jr          $ra
    // 0x80067348: nop

    return;
    // 0x80067348: nop

;}

RECOMP_FUNC void CurrentPiece_TryRotate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006734C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80067350: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80067354: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80067358: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006735C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80067360: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80067364: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80067368: lbu         $t7, 0xE($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XE);
    // 0x8006736C: nop

    // 0x80067370: bne         $t7, $zero, L_80067594
    if (ctx->r15 != 0) {
        // 0x80067374: nop
    
            goto L_80067594;
    }
    // 0x80067374: nop

    // 0x80067378: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8006737C: lb          $a3, 0x2F($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X2F);
    // 0x80067380: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80067384: jal         0x80066ED4
    // 0x80067388: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    CurrentPiece_TryTransform(rdram, ctx);
        goto after_0;
    // 0x80067388: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006738C: lb          $t8, 0x2F($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X2F);
    // 0x80067390: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80067394: bne         $t8, $at, L_80067450
    if (ctx->r24 != ctx->r1) {
        // 0x80067398: andi        $s0, $v0, 0xFF
        ctx->r16 = ctx->r2 & 0XFF;
            goto L_80067450;
    }
    // 0x80067398: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x8006739C: bne         $s0, $zero, L_800673C8
    if (ctx->r16 != 0) {
        // 0x800673A0: nop
    
            goto L_800673C8;
    }
    // 0x800673A0: nop

    // 0x800673A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800673A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800673AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800673B0: jal         0x80066ED4
    // 0x800673B4: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    CurrentPiece_TryTransform(rdram, ctx);
        goto after_1;
    // 0x800673B4: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    after_1:
    // 0x800673B8: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x800673BC: or          $s0, $s0, $s1
    ctx->r16 = ctx->r16 | ctx->r17;
    // 0x800673C0: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x800673C4: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_800673C8:
    // 0x800673C8: bne         $s0, $zero, L_800673F4
    if (ctx->r16 != 0) {
        // 0x800673CC: nop
    
            goto L_800673F4;
    }
    // 0x800673CC: nop

    // 0x800673D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800673D4: lb          $a3, 0x2F($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X2F);
    // 0x800673D8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800673DC: jal         0x80066ED4
    // 0x800673E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    CurrentPiece_TryTransform(rdram, ctx);
        goto after_2;
    // 0x800673E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800673E4: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x800673E8: or          $s0, $s0, $s1
    ctx->r16 = ctx->r16 | ctx->r17;
    // 0x800673EC: andi        $t0, $s0, 0xFF
    ctx->r8 = ctx->r16 & 0XFF;
    // 0x800673F0: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_800673F4:
    // 0x800673F4: bne         $s0, $zero, L_80067420
    if (ctx->r16 != 0) {
        // 0x800673F8: nop
    
            goto L_80067420;
    }
    // 0x800673F8: nop

    // 0x800673FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80067400: lb          $a3, 0x2F($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X2F);
    // 0x80067404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80067408: jal         0x80066ED4
    // 0x8006740C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    CurrentPiece_TryTransform(rdram, ctx);
        goto after_3;
    // 0x8006740C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80067410: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x80067414: or          $s0, $s0, $s1
    ctx->r16 = ctx->r16 | ctx->r17;
    // 0x80067418: andi        $t1, $s0, 0xFF
    ctx->r9 = ctx->r16 & 0XFF;
    // 0x8006741C: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_80067420:
    // 0x80067420: bne         $s0, $zero, L_80067500
    if (ctx->r16 != 0) {
        // 0x80067424: nop
    
            goto L_80067500;
    }
    // 0x80067424: nop

    // 0x80067428: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8006742C: lb          $a3, 0x2F($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X2F);
    // 0x80067430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80067434: jal         0x80066ED4
    // 0x80067438: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    CurrentPiece_TryTransform(rdram, ctx);
        goto after_4;
    // 0x80067438: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_4:
    // 0x8006743C: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x80067440: or          $s0, $s0, $s1
    ctx->r16 = ctx->r16 | ctx->r17;
    // 0x80067444: andi        $t2, $s0, 0xFF
    ctx->r10 = ctx->r16 & 0XFF;
    // 0x80067448: b           L_80067500
    // 0x8006744C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
        goto L_80067500;
    // 0x8006744C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_80067450:
    // 0x80067450: bne         $s0, $zero, L_8006747C
    if (ctx->r16 != 0) {
        // 0x80067454: nop
    
            goto L_8006747C;
    }
    // 0x80067454: nop

    // 0x80067458: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8006745C: lb          $a3, 0x2F($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X2F);
    // 0x80067460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80067464: jal         0x80066ED4
    // 0x80067468: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    CurrentPiece_TryTransform(rdram, ctx);
        goto after_5;
    // 0x80067468: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8006746C: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x80067470: or          $s0, $s0, $s1
    ctx->r16 = ctx->r16 | ctx->r17;
    // 0x80067474: andi        $t3, $s0, 0xFF
    ctx->r11 = ctx->r16 & 0XFF;
    // 0x80067478: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
L_8006747C:
    // 0x8006747C: bne         $s0, $zero, L_800674A8
    if (ctx->r16 != 0) {
        // 0x80067480: nop
    
            goto L_800674A8;
    }
    // 0x80067480: nop

    // 0x80067484: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80067488: lb          $a3, 0x2F($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X2F);
    // 0x8006748C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80067490: jal         0x80066ED4
    // 0x80067494: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    CurrentPiece_TryTransform(rdram, ctx);
        goto after_6;
    // 0x80067494: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80067498: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x8006749C: or          $s0, $s0, $s1
    ctx->r16 = ctx->r16 | ctx->r17;
    // 0x800674A0: andi        $t4, $s0, 0xFF
    ctx->r12 = ctx->r16 & 0XFF;
    // 0x800674A4: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
L_800674A8:
    // 0x800674A8: bne         $s0, $zero, L_800674D4
    if (ctx->r16 != 0) {
        // 0x800674AC: nop
    
            goto L_800674D4;
    }
    // 0x800674AC: nop

    // 0x800674B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800674B4: lb          $a3, 0x2F($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X2F);
    // 0x800674B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800674BC: jal         0x80066ED4
    // 0x800674C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    CurrentPiece_TryTransform(rdram, ctx);
        goto after_7;
    // 0x800674C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x800674C4: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x800674C8: or          $s0, $s0, $s1
    ctx->r16 = ctx->r16 | ctx->r17;
    // 0x800674CC: andi        $t5, $s0, 0xFF
    ctx->r13 = ctx->r16 & 0XFF;
    // 0x800674D0: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
L_800674D4:
    // 0x800674D4: bne         $s0, $zero, L_80067500
    if (ctx->r16 != 0) {
        // 0x800674D8: nop
    
            goto L_80067500;
    }
    // 0x800674D8: nop

    // 0x800674DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800674E0: lb          $a3, 0x2F($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X2F);
    // 0x800674E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800674E8: jal         0x80066ED4
    // 0x800674EC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    CurrentPiece_TryTransform(rdram, ctx);
        goto after_8;
    // 0x800674EC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_8:
    // 0x800674F0: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x800674F4: or          $s0, $s0, $s1
    ctx->r16 = ctx->r16 | ctx->r17;
    // 0x800674F8: andi        $t6, $s0, 0xFF
    ctx->r14 = ctx->r16 & 0XFF;
    // 0x800674FC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_80067500:
    // 0x80067500: beq         $s0, $zero, L_80067594
    if (ctx->r16 == 0) {
        // 0x80067504: nop
    
            goto L_80067594;
    }
    // 0x80067504: nop

    // 0x80067508: lb          $t7, 0x2F($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X2F);
    // 0x8006750C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80067510: bne         $t7, $at, L_80067534
    if (ctx->r15 != ctx->r1) {
        // 0x80067514: nop
    
            goto L_80067534;
    }
    // 0x80067514: nop

    // 0x80067518: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8006751C: addiu       $t8, $zero, -0x1000
    ctx->r24 = ADD32(0, -0X1000);
    // 0x80067520: sh          $t8, 0xC($t9)
    MEM_H(0XC, ctx->r25) = ctx->r24;
    // 0x80067524: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80067528: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8006752C: b           L_8006754C
    // 0x80067530: sb          $t0, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r8;
        goto L_8006754C;
    // 0x80067530: sb          $t0, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r8;
L_80067534:
    // 0x80067534: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80067538: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x8006753C: sh          $t2, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r10;
    // 0x80067540: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80067544: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80067548: sb          $t4, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r12;
L_8006754C:
    // 0x8006754C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80067550: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80067554: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80067558: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8006755C: jal         0x8008A5C8
    // 0x80067560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio2_Play_SFX(rdram, ctx);
        goto after_9;
    // 0x80067560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80067564: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80067568: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8006756C: lbu         $t7, 0x2($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2);
    // 0x80067570: nop

    // 0x80067574: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80067578: sb          $t8, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r24;
    // 0x8006757C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80067580: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80067584: lbu         $t0, 0x2($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2);
    // 0x80067588: nop

    // 0x8006758C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80067590: sb          $t1, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r9;
L_80067594:
    // 0x80067594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80067598: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006759C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800675A0: jr          $ra
    // 0x800675A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800675A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void CurrentPiece_UpdateMinoCells(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800675A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800675AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800675B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800675B4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800675B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800675BC: lw          $s0, -0x490($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X490);
    // 0x800675C0: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x800675C4: beq         $at, $zero, L_800675F0
    if (ctx->r1 == 0) {
        // 0x800675C8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800675F0;
    }
    // 0x800675C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_800675CC:
    // 0x800675CC: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
    // 0x800675D0: addu        $a1, $s0, $t6
    ctx->r5 = ADD32(ctx->r16, ctx->r14);
    // 0x800675D4: addiu       $a1, $a1, 0x15
    ctx->r5 = ADD32(ctx->r5, 0X15);
    // 0x800675D8: jal         0x80066C10
    // 0x800675DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    rotate_and_translate_mino(rdram, ctx);
        goto after_0;
    // 0x800675DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800675E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800675E4: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x800675E8: bne         $at, $zero, L_800675CC
    if (ctx->r1 != 0) {
        // 0x800675EC: nop
    
            goto L_800675CC;
    }
    // 0x800675EC: nop

L_800675F0:
    // 0x800675F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800675F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800675F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800675FC: jr          $ra
    // 0x80067600: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80067600: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void CurrentPiece_Lock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067604: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80067608: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006760C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80067610: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80067614: lw          $s0, -0x490($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X490);
    // 0x80067618: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006761C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80067620: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80067624: addiu       $a1, $a1, 0x3A90
    ctx->r5 = ADD32(ctx->r5, 0X3A90);
    // 0x80067628: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8006762C: jal         0x8008A5C8
    // 0x80067630: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    Audio2_Play_SFX(rdram, ctx);
        goto after_0;
    // 0x80067630: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80067634: jal         0x800675A8
    // 0x80067638: nop

    CurrentPiece_UpdateMinoCells(rdram, ctx);
        goto after_1;
    // 0x80067638: nop

    after_1:
    // 0x8006763C: jal         0x80066CC8
    // 0x80067640: nop

    CurrentPiece_WriteMinosToBoard(rdram, ctx);
        goto after_2;
    // 0x80067640: nop

    after_2:
    // 0x80067644: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80067648: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006764C: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80067650: beq         $at, $zero, L_80067694
    if (ctx->r1 == 0) {
        // 0x80067654: sb          $t6, 0x1($s0)
        MEM_B(0X1, ctx->r16) = ctx->r14;
            goto L_80067694;
    }
    // 0x80067654: sb          $t6, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r14;
L_80067658:
    // 0x80067658: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x8006765C: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80067660: lb          $t9, 0x16($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X16);
    // 0x80067664: nop

    // 0x80067668: bgez        $t9, L_80067684
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8006766C: nop
    
            goto L_80067684;
    }
    // 0x8006766C: nop

    // 0x80067670: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80067674: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80067678: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
    // 0x8006767C: b           L_80067698
    // 0x80067680: sb          $t1, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r9;
        goto L_80067698;
    // 0x80067680: sb          $t1, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r9;
L_80067684:
    // 0x80067684: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80067688: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8006768C: bne         $at, $zero, L_80067658
    if (ctx->r1 != 0) {
        // 0x80067690: nop
    
            goto L_80067658;
    }
    // 0x80067690: nop

L_80067694:
    // 0x80067694: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80067698:
    // 0x80067698: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006769C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800676A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800676A4: jr          $ra
    // 0x800676A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800676A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void CurrentPiece_HardDrop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800676AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800676B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800676B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800676B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800676BC: jal         0x80067078
    // 0x800676C0: nop

    CurrentPiece_TryStepDown(rdram, ctx);
        goto after_0;
    // 0x800676C0: nop

    after_0:
    // 0x800676C4: beq         $v0, $zero, L_800676E0
    if (ctx->r2 == 0) {
        // 0x800676C8: nop
    
            goto L_800676E0;
    }
    // 0x800676C8: nop

L_800676CC:
    // 0x800676CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800676D0: jal         0x80067078
    // 0x800676D4: nop

    CurrentPiece_TryStepDown(rdram, ctx);
        goto after_1;
    // 0x800676D4: nop

    after_1:
    // 0x800676D8: bne         $v0, $zero, L_800676CC
    if (ctx->r2 != 0) {
        // 0x800676DC: nop
    
            goto L_800676CC;
    }
    // 0x800676DC: nop

L_800676E0:
    // 0x800676E0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800676E4: nop

    // 0x800676E8: lb          $t7, 0x12($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X12);
    // 0x800676EC: nop

    // 0x800676F0: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800676F4: sh          $t8, 0x30($t6)
    MEM_H(0X30, ctx->r14) = ctx->r24;
    // 0x800676F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800676FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067700: jr          $ra
    // 0x80067704: nop

    return;
    // 0x80067704: nop

;}

RECOMP_FUNC void CurrentPiece_HandleInput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067708: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006770C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067710: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80067714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067718: lbu         $t7, 0x2($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2);
    // 0x8006771C: nop

    // 0x80067720: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80067724: beq         $t8, $zero, L_80067734
    if (ctx->r24 == 0) {
        // 0x80067728: nop
    
            goto L_80067734;
    }
    // 0x80067728: nop

    // 0x8006772C: jal         0x8006715C
    // 0x80067730: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    CurrentPiece_MoveLeft(rdram, ctx);
        goto after_0;
    // 0x80067730: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
L_80067734:
    // 0x80067734: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80067738: nop

    // 0x8006773C: lbu         $t0, 0x2($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2);
    // 0x80067740: nop

    // 0x80067744: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80067748: beq         $t1, $zero, L_80067758
    if (ctx->r9 == 0) {
        // 0x8006774C: nop
    
            goto L_80067758;
    }
    // 0x8006774C: nop

    // 0x80067750: jal         0x80067254
    // 0x80067754: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    CurrentPiece_MoveRight(rdram, ctx);
        goto after_1;
    // 0x80067754: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
L_80067758:
    // 0x80067758: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8006775C: nop

    // 0x80067760: lbu         $t3, 0x2($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X2);
    // 0x80067764: nop

    // 0x80067768: andi        $t4, $t3, 0x8
    ctx->r12 = ctx->r11 & 0X8;
    // 0x8006776C: beq         $t4, $zero, L_80067780
    if (ctx->r12 == 0) {
        // 0x80067770: nop
    
            goto L_80067780;
    }
    // 0x80067770: nop

    // 0x80067774: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80067778: jal         0x8006734C
    // 0x8006777C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    CurrentPiece_TryRotate(rdram, ctx);
        goto after_2;
    // 0x8006777C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80067780:
    // 0x80067780: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80067784: nop

    // 0x80067788: lbu         $t7, 0x2($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X2);
    // 0x8006778C: nop

    // 0x80067790: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80067794: beq         $t8, $zero, L_800677A8
    if (ctx->r24 == 0) {
        // 0x80067798: nop
    
            goto L_800677A8;
    }
    // 0x80067798: nop

    // 0x8006779C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800677A0: jal         0x8006734C
    // 0x800677A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    CurrentPiece_TryRotate(rdram, ctx);
        goto after_3;
    // 0x800677A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
L_800677A8:
    // 0x800677A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800677AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800677B0: jr          $ra
    // 0x800677B4: nop

    return;
    // 0x800677B4: nop

;}

RECOMP_FUNC void CurrentPiece_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800677B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800677BC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800677C0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800677C4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800677C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800677CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800677D0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800677D4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800677D8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800677DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800677E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800677E4: addiu       $s0, $t6, 0x20
    ctx->r16 = ADD32(ctx->r14, 0X20);
    // 0x800677E8: jal         0x800655C4
    // 0x800677EC: addiu       $a0, $t6, 0x518
    ctx->r4 = ADD32(ctx->r14, 0X518);
    MobilePiece_UpdateAltColor(rdram, ctx);
        goto after_0;
    // 0x800677EC: addiu       $a0, $t6, 0x518
    ctx->r4 = ADD32(ctx->r14, 0X518);
    after_0:
    // 0x800677F0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800677F4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800677F8: jal         0x80064F54
    // 0x800677FC: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    MobilePiece_MorphCubes(rdram, ctx);
        goto after_1;
    // 0x800677FC: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_1:
    // 0x80067800: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80067804: nop

    // 0x80067808: beq         $t7, $zero, L_80067B74
    if (ctx->r15 == 0) {
        // 0x8006780C: nop
    
            goto L_80067B74;
    }
    // 0x8006780C: nop

L_80067810:
    // 0x80067810: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80067814: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80067818: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8006781C: nop

    // 0x80067820: bne         $t9, $at, L_80067B74
    if (ctx->r25 != ctx->r1) {
        // 0x80067824: nop
    
            goto L_80067B74;
    }
    // 0x80067824: nop

    // 0x80067828: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8006782C: nop

    // 0x80067830: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x80067834: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80067838: lh          $t6, 0x10($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X10);
    // 0x8006783C: lb          $t2, 0x12($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X12);
    // 0x80067840: lh          $t4, 0x6($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X6);
    // 0x80067844: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80067848: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8006784C: slt         $t7, $t6, $t5
    ctx->r15 = SIGNED(ctx->r14) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80067850: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067854: sb          $t7, 0x3($t1)
    MEM_B(0X3, ctx->r9) = ctx->r15;
    // 0x80067858: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8006785C: jal         0x80067708
    // 0x80067860: nop

    CurrentPiece_HandleInput(rdram, ctx);
        goto after_2;
    // 0x80067860: nop

    after_2:
    // 0x80067864: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80067868: lh          $t5, 0xA($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA);
    // 0x8006786C: lb          $s1, 0xF($t8)
    ctx->r17 = MEM_B(ctx->r24, 0XF);
    // 0x80067870: lb          $s2, 0x10($t8)
    ctx->r18 = MEM_B(ctx->r24, 0X10);
    // 0x80067874: sll         $t9, $s1, 8
    ctx->r25 = S32(ctx->r17 << 8);
    // 0x80067878: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8006787C: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x80067880: sll         $t3, $s2, 8
    ctx->r11 = S32(ctx->r18 << 8);
    // 0x80067884: sll         $t0, $s1, 16
    ctx->r8 = S32(ctx->r17 << 16);
    // 0x80067888: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x8006788C: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80067890: addiu       $s2, $s2, 0x80
    ctx->r18 = ADD32(ctx->r18, 0X80);
    // 0x80067894: sra         $t2, $s1, 16
    ctx->r10 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80067898: sll         $t4, $s2, 16
    ctx->r12 = S32(ctx->r18 << 16);
    // 0x8006789C: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x800678A0: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
    // 0x800678A4: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800678A8: slt         $at, $t5, $s1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800678AC: beq         $at, $zero, L_800678E0
    if (ctx->r1 == 0) {
        // 0x800678B0: or          $s2, $t6, $zero
        ctx->r18 = ctx->r14 | 0;
            goto L_800678E0;
    }
    // 0x800678B0: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x800678B4: lh          $t7, 0xA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XA);
    // 0x800678B8: addiu       $t1, $s1, -0x40
    ctx->r9 = ADD32(ctx->r17, -0X40);
    // 0x800678BC: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800678C0: beq         $at, $zero, L_800678DC
    if (ctx->r1 == 0) {
        // 0x800678C4: nop
    
            goto L_800678DC;
    }
    // 0x800678C4: nop

    // 0x800678C8: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x800678CC: nop

    // 0x800678D0: addiu       $t0, $t9, 0x40
    ctx->r8 = ADD32(ctx->r25, 0X40);
    // 0x800678D4: b           L_800678E0
    // 0x800678D8: sh          $t0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r8;
        goto L_800678E0;
    // 0x800678D8: sh          $t0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r8;
L_800678DC:
    // 0x800678DC: sh          $s1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r17;
L_800678E0:
    // 0x800678E0: lh          $t2, 0xC($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XC);
    // 0x800678E4: nop

    // 0x800678E8: slt         $at, $t2, $s2
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800678EC: beq         $at, $zero, L_80067920
    if (ctx->r1 == 0) {
        // 0x800678F0: nop
    
            goto L_80067920;
    }
    // 0x800678F0: nop

    // 0x800678F4: lh          $t8, 0xC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XC);
    // 0x800678F8: addiu       $t3, $s2, -0x40
    ctx->r11 = ADD32(ctx->r18, -0X40);
    // 0x800678FC: slt         $at, $t8, $t3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80067900: beq         $at, $zero, L_8006791C
    if (ctx->r1 == 0) {
        // 0x80067904: nop
    
            goto L_8006791C;
    }
    // 0x80067904: nop

    // 0x80067908: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x8006790C: nop

    // 0x80067910: addiu       $t6, $t4, 0x40
    ctx->r14 = ADD32(ctx->r12, 0X40);
    // 0x80067914: b           L_80067920
    // 0x80067918: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
        goto L_80067920;
    // 0x80067918: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
L_8006791C:
    // 0x8006791C: sh          $s2, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r18;
L_80067920:
    // 0x80067920: lh          $t5, 0xA($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA);
    // 0x80067924: nop

    // 0x80067928: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8006792C: beq         $at, $zero, L_80067960
    if (ctx->r1 == 0) {
        // 0x80067930: nop
    
            goto L_80067960;
    }
    // 0x80067930: nop

    // 0x80067934: lh          $t7, 0xA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XA);
    // 0x80067938: addiu       $t1, $s1, 0x40
    ctx->r9 = ADD32(ctx->r17, 0X40);
    // 0x8006793C: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80067940: beq         $at, $zero, L_8006795C
    if (ctx->r1 == 0) {
        // 0x80067944: nop
    
            goto L_8006795C;
    }
    // 0x80067944: nop

    // 0x80067948: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x8006794C: nop

    // 0x80067950: addiu       $t0, $t9, -0x40
    ctx->r8 = ADD32(ctx->r25, -0X40);
    // 0x80067954: b           L_80067960
    // 0x80067958: sh          $t0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r8;
        goto L_80067960;
    // 0x80067958: sh          $t0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r8;
L_8006795C:
    // 0x8006795C: sh          $s1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r17;
L_80067960:
    // 0x80067960: lh          $t2, 0xC($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XC);
    // 0x80067964: nop

    // 0x80067968: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8006796C: beq         $at, $zero, L_800679A0
    if (ctx->r1 == 0) {
        // 0x80067970: nop
    
            goto L_800679A0;
    }
    // 0x80067970: nop

    // 0x80067974: lh          $t8, 0xC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XC);
    // 0x80067978: addiu       $t3, $s2, 0x40
    ctx->r11 = ADD32(ctx->r18, 0X40);
    // 0x8006797C: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80067980: beq         $at, $zero, L_8006799C
    if (ctx->r1 == 0) {
        // 0x80067984: nop
    
            goto L_8006799C;
    }
    // 0x80067984: nop

    // 0x80067988: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x8006798C: nop

    // 0x80067990: addiu       $t6, $t4, -0x40
    ctx->r14 = ADD32(ctx->r12, -0X40);
    // 0x80067994: b           L_800679A0
    // 0x80067998: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
        goto L_800679A0;
    // 0x80067998: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
L_8006799C:
    // 0x8006799C: sh          $s2, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r18;
L_800679A0:
    // 0x800679A0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800679A4: lh          $t3, 0xE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XE);
    // 0x800679A8: lb          $s3, 0x11($t5)
    ctx->r19 = MEM_B(ctx->r13, 0X11);
    // 0x800679AC: lb          $s4, 0x12($t5)
    ctx->r20 = MEM_B(ctx->r13, 0X12);
    // 0x800679B0: sll         $t7, $s3, 8
    ctx->r15 = S32(ctx->r19 << 8);
    // 0x800679B4: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
    // 0x800679B8: sll         $t1, $s3, 16
    ctx->r9 = S32(ctx->r19 << 16);
    // 0x800679BC: sll         $t0, $s4, 8
    ctx->r8 = S32(ctx->r20 << 8);
    // 0x800679C0: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x800679C4: or          $s4, $t0, $zero
    ctx->r20 = ctx->r8 | 0;
    // 0x800679C8: sra         $t9, $s3, 16
    ctx->r25 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800679CC: sll         $t2, $s4, 16
    ctx->r10 = S32(ctx->r20 << 16);
    // 0x800679D0: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x800679D4: or          $s4, $t2, $zero
    ctx->r20 = ctx->r10 | 0;
    // 0x800679D8: sra         $t8, $s4, 16
    ctx->r24 = S32(SIGNED(ctx->r20) >> 16);
    // 0x800679DC: slt         $at, $s3, $t3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800679E0: beq         $at, $zero, L_80067A14
    if (ctx->r1 == 0) {
        // 0x800679E4: or          $s4, $t8, $zero
        ctx->r20 = ctx->r24 | 0;
            goto L_80067A14;
    }
    // 0x800679E4: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x800679E8: lh          $t4, 0xE($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XE);
    // 0x800679EC: addiu       $t6, $s3, 0x40
    ctx->r14 = ADD32(ctx->r19, 0X40);
    // 0x800679F0: slt         $at, $t6, $t4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800679F4: beq         $at, $zero, L_80067A10
    if (ctx->r1 == 0) {
        // 0x800679F8: nop
    
            goto L_80067A10;
    }
    // 0x800679F8: nop

    // 0x800679FC: lh          $t7, 0xE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE);
    // 0x80067A00: nop

    // 0x80067A04: addiu       $t1, $t7, -0x40
    ctx->r9 = ADD32(ctx->r15, -0X40);
    // 0x80067A08: b           L_80067A14
    // 0x80067A0C: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
        goto L_80067A14;
    // 0x80067A0C: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
L_80067A10:
    // 0x80067A10: sh          $s3, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r19;
L_80067A14:
    // 0x80067A14: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
    // 0x80067A18: nop

    // 0x80067A1C: slt         $at, $t9, $s3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80067A20: beq         $at, $zero, L_80067A54
    if (ctx->r1 == 0) {
        // 0x80067A24: nop
    
            goto L_80067A54;
    }
    // 0x80067A24: nop

    // 0x80067A28: lh          $t5, 0xE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE);
    // 0x80067A2C: addiu       $t0, $s3, -0x40
    ctx->r8 = ADD32(ctx->r19, -0X40);
    // 0x80067A30: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80067A34: beq         $at, $zero, L_80067A50
    if (ctx->r1 == 0) {
        // 0x80067A38: nop
    
            goto L_80067A50;
    }
    // 0x80067A38: nop

    // 0x80067A3C: lh          $t2, 0xE($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XE);
    // 0x80067A40: nop

    // 0x80067A44: addiu       $t8, $t2, 0x40
    ctx->r24 = ADD32(ctx->r10, 0X40);
    // 0x80067A48: b           L_80067A54
    // 0x80067A4C: sh          $t8, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r24;
        goto L_80067A54;
    // 0x80067A4C: sh          $t8, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r24;
L_80067A50:
    // 0x80067A50: sh          $s3, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r19;
L_80067A54:
    // 0x80067A54: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80067A58: nop

    // 0x80067A5C: lbu         $t4, 0xE($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XE);
    // 0x80067A60: nop

    // 0x80067A64: blez        $t4, L_80067A98
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80067A68: nop
    
            goto L_80067A98;
    }
    // 0x80067A68: nop

    // 0x80067A6C: lhu         $t6, 0x8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X8);
    // 0x80067A70: lh          $t7, 0xC($t3)
    ctx->r15 = MEM_H(ctx->r11, 0XC);
    // 0x80067A74: nop

    // 0x80067A78: addu        $t1, $t6, $t7
    ctx->r9 = ADD32(ctx->r14, ctx->r15);
    // 0x80067A7C: sh          $t1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r9;
    // 0x80067A80: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80067A84: nop

    // 0x80067A88: lbu         $t5, 0xE($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0XE);
    // 0x80067A8C: nop

    // 0x80067A90: addiu       $t0, $t5, -0x1
    ctx->r8 = ADD32(ctx->r13, -0X1);
    // 0x80067A94: sb          $t0, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r8;
L_80067A98:
    // 0x80067A98: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80067A9C: nop

    // 0x80067AA0: lbu         $t8, 0x3($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X3);
    // 0x80067AA4: nop

    // 0x80067AA8: bne         $t8, $zero, L_80067AC0
    if (ctx->r24 != 0) {
        // 0x80067AAC: nop
    
            goto L_80067AC0;
    }
    // 0x80067AAC: nop

    // 0x80067AB0: jal         0x8006705C
    // 0x80067AB4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    CurrentPiece_AdvanceFall(rdram, ctx);
        goto after_3;
    // 0x80067AB4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_3:
    // 0x80067AB8: b           L_80067B00
    // 0x80067ABC: nop

        goto L_80067B00;
    // 0x80067ABC: nop

L_80067AC0:
    // 0x80067AC0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80067AC4: jal         0x80067078
    // 0x80067AC8: nop

    CurrentPiece_TryStepDown(rdram, ctx);
        goto after_4;
    // 0x80067AC8: nop

    after_4:
    // 0x80067ACC: beq         $v0, $zero, L_80067AE8
    if (ctx->r2 == 0) {
        // 0x80067AD0: nop
    
            goto L_80067AE8;
    }
    // 0x80067AD0: nop

    // 0x80067AD4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80067AD8: jal         0x8006705C
    // 0x80067ADC: nop

    CurrentPiece_AdvanceFall(rdram, ctx);
        goto after_5;
    // 0x80067ADC: nop

    after_5:
    // 0x80067AE0: b           L_80067B00
    // 0x80067AE4: nop

        goto L_80067B00;
    // 0x80067AE4: nop

L_80067AE8:
    // 0x80067AE8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80067AEC: nop

    // 0x80067AF0: lb          $t3, 0x12($t4)
    ctx->r11 = MEM_B(ctx->r12, 0X12);
    // 0x80067AF4: nop

    // 0x80067AF8: sll         $t6, $t3, 8
    ctx->r14 = S32(ctx->r11 << 8);
    // 0x80067AFC: sh          $t6, 0x30($t4)
    MEM_H(0X30, ctx->r12) = ctx->r14;
L_80067B00:
    // 0x80067B00: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80067B04: jal         0x80067020
    // 0x80067B08: nop

    CurrentPiece_IsAtLanding(rdram, ctx);
        goto after_6;
    // 0x80067B08: nop

    after_6:
    // 0x80067B0C: beq         $v0, $zero, L_80067B54
    if (ctx->r2 == 0) {
        // 0x80067B10: nop
    
            goto L_80067B54;
    }
    // 0x80067B10: nop

    // 0x80067B14: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80067B18: nop

    // 0x80067B1C: lbu         $t1, 0x4($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X4);
    // 0x80067B20: nop

    // 0x80067B24: bne         $t1, $zero, L_80067B3C
    if (ctx->r9 != 0) {
        // 0x80067B28: nop
    
            goto L_80067B3C;
    }
    // 0x80067B28: nop

    // 0x80067B2C: jal         0x80067604
    // 0x80067B30: nop

    CurrentPiece_Lock(rdram, ctx);
        goto after_7;
    // 0x80067B30: nop

    after_7:
    // 0x80067B34: b           L_80067B54
    // 0x80067B38: nop

        goto L_80067B54;
    // 0x80067B38: nop

L_80067B3C:
    // 0x80067B3C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80067B40: nop

    // 0x80067B44: lbu         $t0, 0x4($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X4);
    // 0x80067B48: nop

    // 0x80067B4C: addiu       $t9, $t0, -0x1
    ctx->r25 = ADD32(ctx->r8, -0X1);
    // 0x80067B50: sb          $t9, 0x4($t5)
    MEM_B(0X4, ctx->r13) = ctx->r25;
L_80067B54:
    // 0x80067B54: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80067B58: nop

    // 0x80067B5C: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x80067B60: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80067B64: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80067B68: nop

    // 0x80067B6C: bne         $t3, $zero, L_80067810
    if (ctx->r11 != 0) {
        // 0x80067B70: nop
    
            goto L_80067810;
    }
    // 0x80067B70: nop

L_80067B74:
    // 0x80067B74: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80067B78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80067B7C: lbu         $t4, 0x0($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X0);
    // 0x80067B80: nop

    // 0x80067B84: bne         $t4, $at, L_80067B98
    if (ctx->r12 != ctx->r1) {
        // 0x80067B88: nop
    
            goto L_80067B98;
    }
    // 0x80067B88: nop

    // 0x80067B8C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80067B90: jal         0x80066920
    // 0x80067B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    CurrentPiece_UpdateGhost(rdram, ctx);
        goto after_8;
    // 0x80067B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_80067B98:
    // 0x80067B98: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80067B9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80067BA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80067BA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80067BA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80067BAC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80067BB0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80067BB4: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
    // 0x80067BB8: jr          $ra
    // 0x80067BBC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80067BBC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void CurrentPiece_GetTopMinoRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067BC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80067BC4: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80067BC8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80067BCC: beq         $at, $zero, L_80067C10
    if (ctx->r1 == 0) {
        // 0x80067BD0: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_80067C10;
    }
    // 0x80067BD0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_80067BD4:
    // 0x80067BD4: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x80067BD8: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80067BDC: lb          $t8, 0x16($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X16);
    // 0x80067BE0: nop

    // 0x80067BE4: slt         $at, $t8, $a1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80067BE8: beq         $at, $zero, L_80067C00
    if (ctx->r1 == 0) {
        // 0x80067BEC: nop
    
            goto L_80067C00;
    }
    // 0x80067BEC: nop

    // 0x80067BF0: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x80067BF4: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80067BF8: lb          $a1, 0x16($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X16);
    // 0x80067BFC: nop

L_80067C00:
    // 0x80067C00: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80067C04: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80067C08: bne         $at, $zero, L_80067BD4
    if (ctx->r1 != 0) {
        // 0x80067C0C: nop
    
            goto L_80067BD4;
    }
    // 0x80067C0C: nop

L_80067C10:
    // 0x80067C10: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80067C14: jr          $ra
    // 0x80067C18: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80067C18: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void CurrentPiece_GetMinoBounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C1C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80067C20: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80067C24: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80067C28: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80067C2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80067C30: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80067C34: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80067C38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80067C3C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80067C40: lb          $a2, 0x16($t6)
    ctx->r6 = MEM_B(ctx->r14, 0X16);
    // 0x80067C44: lb          $a1, 0x15($t6)
    ctx->r5 = MEM_B(ctx->r14, 0X15);
    // 0x80067C48: jal         0x8006073C
    // 0x80067C4C: nop

    PFGFX_InitBounds(rdram, ctx);
        goto after_0;
    // 0x80067C4C: nop

    after_0:
    // 0x80067C50: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80067C54: sltiu       $at, $s0, 0x4
    ctx->r1 = ctx->r16 < 0X4 ? 1 : 0;
    // 0x80067C58: beq         $at, $zero, L_80067D04
    if (ctx->r1 == 0) {
        // 0x80067C5C: nop
    
            goto L_80067D04;
    }
    // 0x80067C5C: nop

L_80067C60:
    // 0x80067C60: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80067C64: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80067C68: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x80067C6C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80067C70: lb          $s1, 0x15($t9)
    ctx->r17 = MEM_B(ctx->r25, 0X15);
    // 0x80067C74: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80067C78: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    // 0x80067C7C: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80067C80: lb          $s2, 0x16($t1)
    ctx->r18 = MEM_B(ctx->r9, 0X16);
    // 0x80067C84: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80067C88: beq         $at, $zero, L_80067C94
    if (ctx->r1 == 0) {
        // 0x80067C8C: nop
    
            goto L_80067C94;
    }
    // 0x80067C8C: nop

    // 0x80067C90: sh          $s1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r17;
L_80067C94:
    // 0x80067C94: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80067C98: nop

    // 0x80067C9C: lh          $t5, 0x4($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X4);
    // 0x80067CA0: nop

    // 0x80067CA4: slt         $at, $t5, $s1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80067CA8: beq         $at, $zero, L_80067CB4
    if (ctx->r1 == 0) {
        // 0x80067CAC: nop
    
            goto L_80067CB4;
    }
    // 0x80067CAC: nop

    // 0x80067CB0: sh          $s1, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r17;
L_80067CB4:
    // 0x80067CB4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80067CB8: nop

    // 0x80067CBC: lh          $t8, 0x2($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X2);
    // 0x80067CC0: nop

    // 0x80067CC4: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80067CC8: beq         $at, $zero, L_80067CD4
    if (ctx->r1 == 0) {
        // 0x80067CCC: nop
    
            goto L_80067CD4;
    }
    // 0x80067CCC: nop

    // 0x80067CD0: sh          $s2, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r18;
L_80067CD4:
    // 0x80067CD4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80067CD8: nop

    // 0x80067CDC: lh          $t7, 0x6($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X6);
    // 0x80067CE0: nop

    // 0x80067CE4: slt         $at, $t7, $s2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80067CE8: beq         $at, $zero, L_80067CF4
    if (ctx->r1 == 0) {
        // 0x80067CEC: nop
    
            goto L_80067CF4;
    }
    // 0x80067CEC: nop

    // 0x80067CF0: sh          $s2, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r18;
L_80067CF4:
    // 0x80067CF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80067CF8: sltiu       $at, $s0, 0x4
    ctx->r1 = ctx->r16 < 0X4 ? 1 : 0;
    // 0x80067CFC: bne         $at, $zero, L_80067C60
    if (ctx->r1 != 0) {
        // 0x80067D00: nop
    
            goto L_80067C60;
    }
    // 0x80067D00: nop

L_80067D04:
    // 0x80067D04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80067D08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80067D0C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80067D10: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80067D14: jr          $ra
    // 0x80067D18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80067D18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void CurrentPiece_GetHeight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067D20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80067D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067D28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80067D2C: jal         0x80067C1C
    // 0x80067D30: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    CurrentPiece_GetMinoBounds(rdram, ctx);
        goto after_0;
    // 0x80067D30: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80067D34: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x80067D38: lh          $t7, 0x1A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1A);
    // 0x80067D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067D40: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x80067D44: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80067D48: jr          $ra
    // 0x80067D4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80067D4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void CurrentPiece_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067D58: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80067D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067D60: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80067D64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80067D68: bne         $t7, $at, L_80067DC8
    if (ctx->r15 != ctx->r1) {
        // 0x80067D6C: nop
    
            goto L_80067DC8;
    }
    // 0x80067D6C: nop

    // 0x80067D70: jal         0x80070D00
    // 0x80067D74: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    Minos_SetScale(rdram, ctx);
        goto after_0;
    // 0x80067D74: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_0:
    // 0x80067D78: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80067D7C: nop

    // 0x80067D80: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x80067D84: nop

    // 0x80067D88: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80067D8C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80067D90: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80067D94: sra         $t1, $t0, 8
    ctx->r9 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80067D98: sb          $t1, 0x548($t8)
    MEM_B(0X548, ctx->r24) = ctx->r9;
    // 0x80067D9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80067DA0: jal         0x80066730
    // 0x80067DA4: addiu       $a0, $a0, 0x540
    ctx->r4 = ADD32(ctx->r4, 0X540);
    GhostPiece_Render(rdram, ctx);
        goto after_1;
    // 0x80067DA4: addiu       $a0, $a0, 0x540
    ctx->r4 = ADD32(ctx->r4, 0X540);
    after_1:
    // 0x80067DA8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80067DAC: nop

    // 0x80067DB0: lbu         $t3, 0x14($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X14);
    // 0x80067DB4: nop

    // 0x80067DB8: sb          $t3, 0x20($t2)
    MEM_B(0X20, ctx->r10) = ctx->r11;
    // 0x80067DBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80067DC0: jal         0x80064FB0
    // 0x80067DC4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    MobilePiece_Render(rdram, ctx);
        goto after_2;
    // 0x80067DC4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_2:
L_80067DC8:
    // 0x80067DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067DD0: jr          $ra
    // 0x80067DD4: nop

    return;
    // 0x80067DD4: nop

;}

RECOMP_FUNC void CurrentPiece_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067DD8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80067DDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80067DE0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80067DE4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80067DE8: lw          $s0, -0x490($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X490);
    // 0x80067DEC: lbu         $t6, 0x6B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X6B);
    // 0x80067DF0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80067DF4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80067DF8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80067DFC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80067E00: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80067E04: sb          $t6, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r14;
    // 0x80067E08: lbu         $a1, 0x6B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6B);
    // 0x80067E0C: jal         0x80066AA8
    // 0x80067E10: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    getCurPieceSpawnPoint(rdram, ctx);
        goto after_0;
    // 0x80067E10: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_0:
    // 0x80067E14: lh          $t7, 0x60($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X60);
    // 0x80067E18: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80067E1C: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80067E20: sb          $t8, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r24;
    // 0x80067E24: lh          $t9, 0x62($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X62);
    // 0x80067E28: nop

    // 0x80067E2C: sra         $t0, $t9, 8
    ctx->r8 = S32(SIGNED(ctx->r25) >> 8);
    // 0x80067E30: sb          $t0, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r8;
    // 0x80067E34: lbu         $a1, 0x6B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6B);
    // 0x80067E38: jal         0x80066B3C
    // 0x80067E3C: nop

    getStartingOriginOfRotationPoint(rdram, ctx);
        goto after_1;
    // 0x80067E3C: nop

    after_1:
    // 0x80067E40: lh          $t1, 0x60($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X60);
    // 0x80067E44: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80067E48: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x80067E4C: sb          $t2, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r10;
    // 0x80067E50: lh          $t3, 0x62($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X62);
    // 0x80067E54: sb          $t5, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r13;
    // 0x80067E58: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x80067E5C: sb          $t4, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r12;
    // 0x80067E60: lbu         $a0, 0x6B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X6B);
    // 0x80067E64: jal         0x80066BE8
    // 0x80067E68: nop

    getStartingRotationState(rdram, ctx);
        goto after_2;
    // 0x80067E68: nop

    after_2:
    // 0x80067E6C: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x80067E70: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80067E74: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80067E78: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    // 0x80067E7C: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // 0x80067E80: sb          $zero, 0xE($s0)
    MEM_B(0XE, ctx->r16) = 0;
    // 0x80067E84: sb          $t6, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r14;
    // 0x80067E88: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x80067E8C: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80067E90: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x80067E94: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x80067E98: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x80067E9C: lbu         $a1, 0x6B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6B);
    // 0x80067EA0: jal         0x80066AA8
    // 0x80067EA4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    getCurPieceSpawnPoint(rdram, ctx);
        goto after_3;
    // 0x80067EA4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x80067EA8: lbu         $a1, 0x6B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6B);
    // 0x80067EAC: jal         0x80066B3C
    // 0x80067EB0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    getStartingOriginOfRotationPoint(rdram, ctx);
        goto after_4;
    // 0x80067EB0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x80067EB4: lbu         $a0, 0x6B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X6B);
    // 0x80067EB8: jal         0x80066BB4
    // 0x80067EBC: nop

    getStartingRotationAngle(rdram, ctx);
        goto after_5;
    // 0x80067EBC: nop

    after_5:
    // 0x80067EC0: lwl         $t1, 0x3C($sp)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r29, 0X3C);
    // 0x80067EC4: lwl         $t2, 0x40($sp)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r29, 0X40);
    // 0x80067EC8: lbu         $t9, 0x6B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X6B);
    // 0x80067ECC: lwr         $t1, 0x3F($sp)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r29, 0X3F);
    // 0x80067ED0: lwr         $t2, 0x43($sp)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r29, 0X43);
    // 0x80067ED4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80067ED8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80067EDC: swl         $t1, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r9);
    // 0x80067EE0: swl         $t2, 0xC($sp)
    do_swl(rdram, 0XC, ctx->r29, ctx->r10);
    // 0x80067EE4: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80067EE8: swr         $t1, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r9);
    // 0x80067EEC: swr         $t2, 0xF($sp)
    do_swr(rdram, 0XF, ctx->r29, ctx->r10);
    // 0x80067EF0: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80067EF4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80067EF8: lw          $a1, 0x110($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X110);
    // 0x80067EFC: andi        $s4, $v0, 0xFFFF
    ctx->r20 = ctx->r2 & 0XFFFF;
    // 0x80067F00: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80067F04: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80067F08: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80067F0C: jal         0x800653E4
    // 0x80067F10: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    MobilePiece_Init(rdram, ctx);
        goto after_6;
    // 0x80067F10: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    after_6:
    // 0x80067F14: addiu       $a0, $s0, 0x518
    ctx->r4 = ADD32(ctx->r16, 0X518);
    // 0x80067F18: jal         0x8006553C
    // 0x80067F1C: addiu       $a1, $s0, 0x20
    ctx->r5 = ADD32(ctx->r16, 0X20);
    MobilePiece_InitFromPiece(rdram, ctx);
        goto after_7;
    // 0x80067F1C: addiu       $a1, $s0, 0x20
    ctx->r5 = ADD32(ctx->r16, 0X20);
    after_7:
    // 0x80067F20: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x80067F24: addiu       $t4, $sp, 0x54
    ctx->r12 = ADD32(ctx->r29, 0X54);
    // 0x80067F28: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x80067F2C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80067F30: lwl         $at, 0x0($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X0);
    // 0x80067F34: lwr         $at, 0x3($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X3);
    // 0x80067F38: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x80067F3C: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80067F40: lwl         $t9, 0x4($t6)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r14, 0X4);
    // 0x80067F44: lwr         $t9, 0x7($t6)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r14, 0X7);
    // 0x80067F48: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80067F4C: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x80067F50: lwl         $at, 0x8($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X8);
    // 0x80067F54: lwr         $at, 0xB($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XB);
    // 0x80067F58: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80067F5C: jal         0x80054DA0
    // 0x80067F60: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    Color_Blend(rdram, ctx);
        goto after_8;
    // 0x80067F60: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    after_8:
    // 0x80067F64: addiu       $a0, $s0, 0x518
    ctx->r4 = ADD32(ctx->r16, 0X518);
    // 0x80067F68: jal         0x800656CC
    // 0x80067F6C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    MobilePiece_SetAlternateColor(rdram, ctx);
        goto after_9;
    // 0x80067F6C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_9:
    // 0x80067F70: lbu         $t0, 0x13($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X13);
    // 0x80067F74: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80067F78: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80067F7C: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80067F80: lw          $a1, 0x110($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X110);
    // 0x80067F84: lbu         $a2, 0x538($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X538);
    // 0x80067F88: jal         0x800668EC
    // 0x80067F8C: addiu       $a0, $s0, 0x540
    ctx->r4 = ADD32(ctx->r16, 0X540);
    GhostPiece_Init(rdram, ctx);
        goto after_10;
    // 0x80067F8C: addiu       $a0, $s0, 0x540
    ctx->r4 = ADD32(ctx->r16, 0X540);
    after_10:
    // 0x80067F90: lh          $t2, 0x2E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2E);
    // 0x80067F94: addiu       $a0, $s0, 0x540
    ctx->r4 = ADD32(ctx->r16, 0X540);
    // 0x80067F98: sh          $t2, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r10;
    // 0x80067F9C: lb          $t3, 0x12($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X12);
    // 0x80067FA0: nop

    // 0x80067FA4: sll         $t5, $t3, 8
    ctx->r13 = S32(ctx->r11 << 8);
    // 0x80067FA8: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80067FAC: lh          $t8, 0x2A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2A);
    // 0x80067FB0: lwl         $t9, 0x50($sp)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r29, 0X50);
    // 0x80067FB4: sh          $t8, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r24;
    // 0x80067FB8: lb          $t7, 0x10($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X10);
    // 0x80067FBC: lwr         $t9, 0x53($sp)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r29, 0X53);
    // 0x80067FC0: sll         $t4, $t7, 8
    ctx->r12 = S32(ctx->r15 << 8);
    // 0x80067FC4: addiu       $t6, $t4, 0x80
    ctx->r14 = ADD32(ctx->r12, 0X80);
    // 0x80067FC8: sh          $t6, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r14;
    // 0x80067FCC: lwl         $t0, 0x4C($sp)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r29, 0X4C);
    // 0x80067FD0: lwr         $t0, 0x4F($sp)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r29, 0X4F);
    // 0x80067FD4: swl         $t9, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r25);
    // 0x80067FD8: swl         $t0, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r8);
    // 0x80067FDC: swr         $t9, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r25);
    // 0x80067FE0: swr         $t0, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r8);
    // 0x80067FE4: lbu         $a3, 0xA($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XA);
    // 0x80067FE8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80067FEC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80067FF0: sll         $t1, $a3, 14
    ctx->r9 = S32(ctx->r7 << 14);
    // 0x80067FF4: jal         0x800667DC
    // 0x80067FF8: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    GhostPiece_Update(rdram, ctx);
        goto after_11;
    // 0x80067FF8: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    after_11:
    // 0x80067FFC: lh          $s1, 0x556($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X556);
    // 0x80068000: lh          $s2, 0x558($s0)
    ctx->r18 = MEM_H(ctx->r16, 0X558);
    // 0x80068004: lhu         $s3, 0x550($s0)
    ctx->r19 = MEM_HU(ctx->r16, 0X550);
    // 0x80068008: sra         $t2, $s1, 8
    ctx->r10 = S32(SIGNED(ctx->r17) >> 8);
    // 0x8006800C: sra         $t5, $s2, 8
    ctx->r13 = S32(SIGNED(ctx->r18) >> 8);
    // 0x80068010: sra         $t7, $s3, 14
    ctx->r15 = S32(SIGNED(ctx->r19) >> 14);
    // 0x80068014: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x80068018: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x8006801C: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
    // 0x80068020: andi        $t3, $s1, 0xFF
    ctx->r11 = ctx->r17 & 0XFF;
    // 0x80068024: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x80068028: andi        $t4, $s3, 0xFF
    ctx->r12 = ctx->r19 & 0XFF;
    // 0x8006802C: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80068030: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x80068034: or          $s3, $t4, $zero
    ctx->r19 = ctx->r12 | 0;
    // 0x80068038: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8006803C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80068040: jal         0x8003DDA8
    // 0x80068044: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    aisquarelist_PieceCanCompleteSquare(rdram, ctx);
        goto after_12;
    // 0x80068044: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80068048: bne         $v0, $zero, L_80068068
    if (ctx->r2 != 0) {
        // 0x8006804C: nop
    
            goto L_80068068;
    }
    // 0x8006804C: nop

    // 0x80068050: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80068054: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80068058: jal         0x8003DBC0
    // 0x8006805C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    Controller_TestPieceTransforms(rdram, ctx);
        goto after_13;
    // 0x8006805C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_13:
    // 0x80068060: beq         $v0, $zero, L_80068070
    if (ctx->r2 == 0) {
        // 0x80068064: nop
    
            goto L_80068070;
    }
    // 0x80068064: nop

L_80068068:
    // 0x80068068: jal         0x80065620
    // 0x8006806C: addiu       $a0, $s0, 0xA40
    ctx->r4 = ADD32(ctx->r16, 0XA40);
    MobilePiece_EnableAltColor(rdram, ctx);
        goto after_14;
    // 0x8006806C: addiu       $a0, $s0, 0xA40
    ctx->r4 = ADD32(ctx->r16, 0XA40);
    after_14:
L_80068070:
    // 0x80068070: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80068074: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80068078: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8006807C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80068080: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80068084: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80068088: jr          $ra
    // 0x8006808C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8006808C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}

RECOMP_FUNC void CurrentPiece_EnableGhost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068090: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80068094: jr          $ra
    // 0x80068098: sb          $t6, 0x538($a0)
    MEM_B(0X538, ctx->r4) = ctx->r14;
    return;
    // 0x80068098: sb          $t6, 0x538($a0)
    MEM_B(0X538, ctx->r4) = ctx->r14;
    // 0x8006809C: nop

;}

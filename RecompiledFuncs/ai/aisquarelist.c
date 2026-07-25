#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void aisquarelist_PieceCanCompleteSquare(uint8_t* rdram, recomp_context* ctx) {
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
    aisquarelist_CheckSquareCompletion(rdram, ctx);
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

RECOMP_FUNC void aisquarelist_AllocSquareBuffer(uint8_t* rdram, recomp_context* ctx) {
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

RECOMP_FUNC void aisquarelist_FreeSquareBuffer(uint8_t* rdram, recomp_context* ctx) {
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

RECOMP_FUNC void aisquarelist_BuildDropTable(uint8_t* rdram, recomp_context* ctx) {
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

RECOMP_FUNC void aisquarelist_Reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E1E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003E1E4: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x8003E1E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8003E1EC: beq         $at, $zero, L_8003E224
    if (ctx->r1 == 0) {
        // 0x8003E1F0: sb          $zero, 0x0($a0)
        MEM_B(0X0, ctx->r4) = 0;
            goto L_8003E224;
    }
    // 0x8003E1F0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_8003E1F4:
    // 0x8003E1F4: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8003E1F8: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x8003E1FC: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8003E200: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003E204: andi        $t0, $a1, 0xFF
    ctx->r8 = ctx->r5 & 0XFF;
    // 0x8003E208: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8003E20C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8003E210: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x8003E214: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    // 0x8003E218: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8003E21C: bne         $at, $zero, L_8003E1F4
    if (ctx->r1 != 0) {
        // 0x8003E220: sb          $zero, 0x9($t9)
        MEM_B(0X9, ctx->r25) = 0;
            goto L_8003E1F4;
    }
    // 0x8003E220: sb          $zero, 0x9($t9)
    MEM_B(0X9, ctx->r25) = 0;
L_8003E224:
    // 0x8003E224: jr          $ra
    // 0x8003E228: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8003E228: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void aisquarelist_AddSquare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E22C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8003E230: slti        $at, $a3, 0x6
    ctx->r1 = SIGNED(ctx->r7) < 0X6 ? 1 : 0;
    // 0x8003E234: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8003E238: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003E23C: beq         $at, $zero, L_8003E278
    if (ctx->r1 == 0) {
        // 0x8003E240: andi        $a2, $a2, 0xFF
        ctx->r6 = ctx->r6 & 0XFF;
            goto L_8003E278;
    }
    // 0x8003E240: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_8003E244:
    // 0x8003E244: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8003E248: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x8003E24C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8003E250: lbu         $t8, 0x9($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X9);
    // 0x8003E254: nop

    // 0x8003E258: beq         $t8, $zero, L_8003E278
    if (ctx->r24 == 0) {
        // 0x8003E25C: nop
    
            goto L_8003E278;
    }
    // 0x8003E25C: nop

    // 0x8003E260: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8003E264: andi        $t9, $a3, 0xFF
    ctx->r25 = ctx->r7 & 0XFF;
    // 0x8003E268: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8003E26C: slti        $at, $a3, 0x6
    ctx->r1 = SIGNED(ctx->r7) < 0X6 ? 1 : 0;
    // 0x8003E270: bne         $at, $zero, L_8003E244
    if (ctx->r1 != 0) {
        // 0x8003E274: nop
    
            goto L_8003E244;
    }
    // 0x8003E274: nop

L_8003E278:
    // 0x8003E278: slti        $at, $a3, 0x6
    ctx->r1 = SIGNED(ctx->r7) < 0X6 ? 1 : 0;
    // 0x8003E27C: beq         $at, $zero, L_8003E2C0
    if (ctx->r1 == 0) {
        // 0x8003E280: nop
    
            goto L_8003E2C0;
    }
    // 0x8003E280: nop

    // 0x8003E284: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x8003E288: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x8003E28C: addu        $t0, $a0, $t1
    ctx->r8 = ADD32(ctx->r4, ctx->r9);
    // 0x8003E290: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003E294: sb          $t2, 0x9($t0)
    MEM_B(0X9, ctx->r8) = ctx->r10;
    // 0x8003E298: sb          $a1, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r5;
    // 0x8003E29C: sb          $a2, 0x8($t0)
    MEM_B(0X8, ctx->r8) = ctx->r6;
    // 0x8003E2A0: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
    // 0x8003E2A4: addiu       $t0, $t0, 0x7
    ctx->r8 = ADD32(ctx->r8, 0X7);
    // 0x8003E2A8: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8003E2AC: sb          $a3, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r7;
    // 0x8003E2B0: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x8003E2B4: nop

    // 0x8003E2B8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8003E2BC: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
L_8003E2C0:
    // 0x8003E2C0: jr          $ra
    // 0x8003E2C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8003E2C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void aisquarelist_RemoveAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E2C8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003E2CC: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x8003E2D0: lb          $t7, 0x1($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X1);
    // 0x8003E2D4: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x8003E2D8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003E2DC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8003E2E0: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8003E2E4: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x8003E2E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8003E2EC: beq         $at, $zero, L_8003E32C
    if (ctx->r1 == 0) {
        // 0x8003E2F0: sb          $zero, 0x9($t9)
        MEM_B(0X9, ctx->r25) = 0;
            goto L_8003E32C;
    }
    // 0x8003E2F0: sb          $zero, 0x9($t9)
    MEM_B(0X9, ctx->r25) = 0;
L_8003E2F4:
    // 0x8003E2F4: addu        $t0, $a0, $a2
    ctx->r8 = ADD32(ctx->r4, ctx->r6);
    // 0x8003E2F8: lb          $t1, 0x2($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X2);
    // 0x8003E2FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003E300: beq         $t1, $at, L_8003E32C
    if (ctx->r9 == ctx->r1) {
        // 0x8003E304: nop
    
            goto L_8003E32C;
    }
    // 0x8003E304: nop

    // 0x8003E308: addu        $t2, $a0, $a2
    ctx->r10 = ADD32(ctx->r4, ctx->r6);
    // 0x8003E30C: addu        $t4, $a0, $a2
    ctx->r12 = ADD32(ctx->r4, ctx->r6);
    // 0x8003E310: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8003E314: andi        $t5, $a2, 0xFF
    ctx->r13 = ctx->r6 & 0XFF;
    // 0x8003E318: lb          $t3, 0x2($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X2);
    // 0x8003E31C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8003E320: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x8003E324: bne         $at, $zero, L_8003E2F4
    if (ctx->r1 != 0) {
        // 0x8003E328: sb          $t3, 0x1($t4)
        MEM_B(0X1, ctx->r12) = ctx->r11;
            goto L_8003E2F4;
    }
    // 0x8003E328: sb          $t3, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r11;
L_8003E32C:
    // 0x8003E32C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8003E330: addu        $t7, $a0, $a2
    ctx->r15 = ADD32(ctx->r4, ctx->r6);
    // 0x8003E334: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    // 0x8003E338: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x8003E33C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8003E340: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8003E344: jr          $ra
    // 0x8003E348: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    return;
    // 0x8003E348: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
;}

RECOMP_FUNC void aisquarelist_OverlapsExisting(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E34C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8003E350: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8003E354: slt         $at, $a3, $t6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003E358: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8003E35C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003E360: beq         $at, $zero, L_8003E44C
    if (ctx->r1 == 0) {
        // 0x8003E364: andi        $a2, $a2, 0xFF
        ctx->r6 = ctx->r6 & 0XFF;
            goto L_8003E44C;
    }
    // 0x8003E364: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_8003E368:
    // 0x8003E368: addu        $t7, $a0, $a3
    ctx->r15 = ADD32(ctx->r4, ctx->r7);
    // 0x8003E36C: lb          $t8, 0x1($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X1);
    // 0x8003E370: nop

    // 0x8003E374: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003E378: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8003E37C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8003E380: lbu         $t1, 0x7($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X7);
    // 0x8003E384: addiu       $t0, $t0, 0x7
    ctx->r8 = ADD32(ctx->r8, 0X7);
    // 0x8003E388: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8003E38C: bne         $at, $zero, L_8003E3D8
    if (ctx->r1 != 0) {
        // 0x8003E390: nop
    
            goto L_8003E3D8;
    }
    // 0x8003E390: nop

    // 0x8003E394: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x8003E398: nop

    // 0x8003E39C: addiu       $t3, $t2, 0x3
    ctx->r11 = ADD32(ctx->r10, 0X3);
    // 0x8003E3A0: slt         $at, $t3, $a1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003E3A4: bne         $at, $zero, L_8003E3D8
    if (ctx->r1 != 0) {
        // 0x8003E3A8: nop
    
            goto L_8003E3D8;
    }
    // 0x8003E3A8: nop

    // 0x8003E3AC: lbu         $t4, 0x1($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X1);
    // 0x8003E3B0: nop

    // 0x8003E3B4: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003E3B8: bne         $at, $zero, L_8003E3D8
    if (ctx->r1 != 0) {
        // 0x8003E3BC: nop
    
            goto L_8003E3D8;
    }
    // 0x8003E3BC: nop

    // 0x8003E3C0: lbu         $t5, 0x1($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X1);
    // 0x8003E3C4: nop

    // 0x8003E3C8: addiu       $t6, $t5, 0x3
    ctx->r14 = ADD32(ctx->r13, 0X3);
    // 0x8003E3CC: slt         $at, $t6, $a2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8003E3D0: beq         $at, $zero, L_8003E428
    if (ctx->r1 == 0) {
        // 0x8003E3D4: nop
    
            goto L_8003E428;
    }
    // 0x8003E3D4: nop

L_8003E3D8:
    // 0x8003E3D8: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x8003E3DC: nop

    // 0x8003E3E0: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003E3E4: bne         $at, $zero, L_8003E430
    if (ctx->r1 != 0) {
        // 0x8003E3E8: nop
    
            goto L_8003E430;
    }
    // 0x8003E3E8: nop

    // 0x8003E3EC: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x8003E3F0: addiu       $t9, $a1, 0x3
    ctx->r25 = ADD32(ctx->r5, 0X3);
    // 0x8003E3F4: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003E3F8: bne         $at, $zero, L_8003E430
    if (ctx->r1 != 0) {
        // 0x8003E3FC: nop
    
            goto L_8003E430;
    }
    // 0x8003E3FC: nop

    // 0x8003E400: lbu         $t1, 0x1($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1);
    // 0x8003E404: nop

    // 0x8003E408: slt         $at, $t1, $a2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8003E40C: bne         $at, $zero, L_8003E430
    if (ctx->r1 != 0) {
        // 0x8003E410: nop
    
            goto L_8003E430;
    }
    // 0x8003E410: nop

    // 0x8003E414: lbu         $t2, 0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X1);
    // 0x8003E418: addiu       $t3, $a2, 0x3
    ctx->r11 = ADD32(ctx->r6, 0X3);
    // 0x8003E41C: slt         $at, $t3, $t2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003E420: bne         $at, $zero, L_8003E430
    if (ctx->r1 != 0) {
        // 0x8003E424: nop
    
            goto L_8003E430;
    }
    // 0x8003E424: nop

L_8003E428:
    // 0x8003E428: b           L_8003E450
    // 0x8003E42C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003E450;
    // 0x8003E42C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003E430:
    // 0x8003E430: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8003E434: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x8003E438: andi        $t4, $a3, 0xFF
    ctx->r12 = ctx->r7 & 0XFF;
    // 0x8003E43C: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x8003E440: slt         $at, $a3, $t5
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8003E444: bne         $at, $zero, L_8003E368
    if (ctx->r1 != 0) {
        // 0x8003E448: nop
    
            goto L_8003E368;
    }
    // 0x8003E448: nop

L_8003E44C:
    // 0x8003E44C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003E450:
    // 0x8003E450: jr          $ra
    // 0x8003E454: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8003E454: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void aisquarelist_FindSquarePlacement(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E458: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003E45C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003E460: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
    // 0x8003E464: slti        $at, $s1, 0x7
    ctx->r1 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x8003E468: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003E46C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8003E470: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003E474: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8003E478: bne         $at, $zero, L_8003E544
    if (ctx->r1 != 0) {
        // 0x8003E47C: sw          $s0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r16;
            goto L_8003E544;
    }
    // 0x8003E47C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
L_8003E480:
    // 0x8003E480: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003E484: slti        $at, $s0, 0x7
    ctx->r1 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
    // 0x8003E488: beq         $at, $zero, L_8003E524
    if (ctx->r1 == 0) {
        // 0x8003E48C: nop
    
            goto L_8003E524;
    }
    // 0x8003E48C: nop

L_8003E490:
    // 0x8003E490: addiu       $t6, $sp, 0x2B
    ctx->r14 = ADD32(ctx->r29, 0X2B);
    // 0x8003E494: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003E498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E49C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003E4A0: addiu       $a2, $sp, 0x2D
    ctx->r6 = ADD32(ctx->r29, 0X2D);
    // 0x8003E4A4: jal         0x80041B48
    // 0x8003E4A8: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    aisquarelist_CheckSquareCompletion(rdram, ctx);
        goto after_0;
    // 0x8003E4A8: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8003E4AC: beq         $v0, $zero, L_8003E50C
    if (ctx->r2 == 0) {
        // 0x8003E4B0: nop
    
            goto L_8003E50C;
    }
    // 0x8003E4B0: nop

    // 0x8003E4B4: lbu         $t7, 0x2C($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2C);
    // 0x8003E4B8: nop

    // 0x8003E4BC: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8003E4C0: beq         $at, $zero, L_8003E50C
    if (ctx->r1 == 0) {
        // 0x8003E4C4: nop
    
            goto L_8003E50C;
    }
    // 0x8003E4C4: nop

    // 0x8003E4C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E4CC: jal         0x80041AB4
    // 0x8003E4D0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    aisquarelist_IsRowSpanFilled(rdram, ctx);
        goto after_1;
    // 0x8003E4D0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_1:
    // 0x8003E4D4: beq         $v0, $zero, L_8003E50C
    if (ctx->r2 == 0) {
        // 0x8003E4D8: nop
    
            goto L_8003E50C;
    }
    // 0x8003E4D8: nop

    // 0x8003E4DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8003E4E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003E4E4: jal         0x8003E34C
    // 0x8003E4E8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    aisquarelist_OverlapsExisting(rdram, ctx);
        goto after_2;
    // 0x8003E4E8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x8003E4EC: bne         $v0, $zero, L_8003E50C
    if (ctx->r2 != 0) {
        // 0x8003E4F0: nop
    
            goto L_8003E50C;
    }
    // 0x8003E4F0: nop

    // 0x8003E4F4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8003E4F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003E4FC: sb          $s0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r16;
    // 0x8003E500: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8003E504: b           L_8003E548
    // 0x8003E508: sb          $s1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r17;
        goto L_8003E548;
    // 0x8003E508: sb          $s1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r17;
L_8003E50C:
    // 0x8003E50C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003E510: andi        $t0, $s0, 0xFF
    ctx->r8 = ctx->r16 & 0XFF;
    // 0x8003E514: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x8003E518: slti        $at, $s0, 0x7
    ctx->r1 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
    // 0x8003E51C: bne         $at, $zero, L_8003E490
    if (ctx->r1 != 0) {
        // 0x8003E520: nop
    
            goto L_8003E490;
    }
    // 0x8003E520: nop

L_8003E524:
    // 0x8003E524: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8003E528: sll         $t1, $s1, 24
    ctx->r9 = S32(ctx->r17 << 24);
    // 0x8003E52C: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8003E530: sra         $t2, $s1, 24
    ctx->r10 = S32(SIGNED(ctx->r17) >> 24);
    // 0x8003E534: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x8003E538: slti        $at, $s1, 0x7
    ctx->r1 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x8003E53C: beq         $at, $zero, L_8003E480
    if (ctx->r1 == 0) {
        // 0x8003E540: nop
    
            goto L_8003E480;
    }
    // 0x8003E540: nop

L_8003E544:
    // 0x8003E544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003E548:
    // 0x8003E548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E54C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E550: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003E554: jr          $ra
    // 0x8003E558: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8003E558: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void aisquarelist_AllSquaresComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E55C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003E560: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8003E564: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8003E568: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003E56C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003E570: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003E574: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8003E578: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003E57C: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8003E580: beq         $at, $zero, L_8003E5F0
    if (ctx->r1 == 0) {
        // 0x8003E584: nop
    
            goto L_8003E5F0;
    }
    // 0x8003E584: nop

L_8003E588:
    // 0x8003E588: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8003E58C: addiu       $t2, $sp, 0x2D
    ctx->r10 = ADD32(ctx->r29, 0X2D);
    // 0x8003E590: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8003E594: lb          $t0, 0x1($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X1);
    // 0x8003E598: addiu       $a2, $sp, 0x2F
    ctx->r6 = ADD32(ctx->r29, 0X2F);
    // 0x8003E59C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8003E5A0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8003E5A4: addu        $s1, $t8, $t1
    ctx->r17 = ADD32(ctx->r24, ctx->r9);
    // 0x8003E5A8: lbu         $a1, 0x8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X8);
    // 0x8003E5AC: lbu         $a0, 0x7($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X7);
    // 0x8003E5B0: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x8003E5B4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003E5B8: jal         0x80041B48
    // 0x8003E5BC: addiu       $a3, $sp, 0x2E
    ctx->r7 = ADD32(ctx->r29, 0X2E);
    aisquarelist_CheckSquareCompletion(rdram, ctx);
        goto after_0;
    // 0x8003E5BC: addiu       $a3, $sp, 0x2E
    ctx->r7 = ADD32(ctx->r29, 0X2E);
    after_0:
    // 0x8003E5C0: bne         $v0, $zero, L_8003E5D0
    if (ctx->r2 != 0) {
        // 0x8003E5C4: nop
    
            goto L_8003E5D0;
    }
    // 0x8003E5C4: nop

    // 0x8003E5C8: b           L_8003E5F4
    // 0x8003E5CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003E5F4;
    // 0x8003E5CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003E5D0:
    // 0x8003E5D0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8003E5D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003E5D8: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8003E5DC: andi        $t3, $s0, 0xFF
    ctx->r11 = ctx->r16 & 0XFF;
    // 0x8003E5E0: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x8003E5E4: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8003E5E8: bne         $at, $zero, L_8003E588
    if (ctx->r1 != 0) {
        // 0x8003E5EC: nop
    
            goto L_8003E588;
    }
    // 0x8003E5EC: nop

L_8003E5F0:
    // 0x8003E5F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003E5F4:
    // 0x8003E5F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E5F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E5FC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003E600: jr          $ra
    // 0x8003E604: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003E604: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void aisquarelist_ShiftSquaresDown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E608: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8003E60C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003E610: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003E614: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8003E618: beq         $at, $zero, L_8003E684
    if (ctx->r1 == 0) {
        // 0x8003E61C: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_8003E684;
    }
    // 0x8003E61C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_8003E620:
    // 0x8003E620: addu        $t7, $a0, $a2
    ctx->r15 = ADD32(ctx->r4, ctx->r6);
    // 0x8003E624: lb          $t8, 0x1($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X1);
    // 0x8003E628: nop

    // 0x8003E62C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003E630: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8003E634: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8003E638: lbu         $a3, 0x8($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X8);
    // 0x8003E63C: addiu       $t0, $t0, 0x7
    ctx->r8 = ADD32(ctx->r8, 0X7);
    // 0x8003E640: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    // 0x8003E644: andi        $t1, $a3, 0xFF
    ctx->r9 = ctx->r7 & 0XFF;
    // 0x8003E648: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8003E64C: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003E650: beq         $at, $zero, L_8003E668
    if (ctx->r1 == 0) {
        // 0x8003E654: nop
    
            goto L_8003E668;
    }
    // 0x8003E654: nop

    // 0x8003E658: lbu         $t2, 0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X1);
    // 0x8003E65C: nop

    // 0x8003E660: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8003E664: sb          $t3, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r11;
L_8003E668:
    // 0x8003E668: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8003E66C: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x8003E670: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x8003E674: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8003E678: slt         $at, $a2, $t5
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8003E67C: bne         $at, $zero, L_8003E620
    if (ctx->r1 != 0) {
        // 0x8003E680: nop
    
            goto L_8003E620;
    }
    // 0x8003E680: nop

L_8003E684:
    // 0x8003E684: jr          $ra
    // 0x8003E688: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8003E688: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void aisquarelist_SearchSquaresRecursive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E68C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8003E690: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8003E694: lbu         $t6, 0x73($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X73);
    // 0x8003E698: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003E69C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003E6A0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8003E6A4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8003E6A8: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8003E6AC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8003E6B0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8003E6B4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8003E6B8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8003E6BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8003E6C0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8003E6C4: beq         $t6, $at, L_8003E6D4
    if (ctx->r14 == ctx->r1) {
        // 0x8003E6C8: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_8003E6D4;
    }
    // 0x8003E6C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003E6CC: b           L_8003ED18
    // 0x8003E6D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003ED18;
    // 0x8003E6D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003E6D4:
    // 0x8003E6D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003E6D8: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8003E6DC: beq         $at, $zero, L_8003E734
    if (ctx->r1 == 0) {
        // 0x8003E6E0: nop
    
            goto L_8003E734;
    }
    // 0x8003E6E0: nop

L_8003E6E4:
    // 0x8003E6E4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8003E6E8: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x8003E6EC: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8003E6F0: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x8003E6F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8003E6F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8003E6FC: lw          $t7, -0x480($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X480);
    // 0x8003E700: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x8003E704: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8003E708: addu        $t3, $sp, $s0
    ctx->r11 = ADD32(ctx->r29, ctx->r16);
    // 0x8003E70C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003E710: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8003E714: lbu         $t0, 0x78($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X78);
    // 0x8003E718: andi        $t4, $s0, 0xFF
    ctx->r12 = ctx->r16 & 0XFF;
    // 0x8003E71C: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x8003E720: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003E724: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8003E728: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x8003E72C: bne         $at, $zero, L_8003E6E4
    if (ctx->r1 != 0) {
        // 0x8003E730: sb          $t2, 0x58($t3)
        MEM_B(0X58, ctx->r11) = ctx->r10;
            goto L_8003E6E4;
    }
    // 0x8003E730: sb          $t2, 0x58($t3)
    MEM_B(0X58, ctx->r11) = ctx->r10;
L_8003E734:
    // 0x8003E734: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8003E738: lw          $t5, -0x490($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X490);
    // 0x8003E73C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003E740: slti        $at, $s2, 0x7
    ctx->r1 = SIGNED(ctx->r18) < 0X7 ? 1 : 0;
    // 0x8003E744: lbu         $s1, 0x13($t5)
    ctx->r17 = MEM_BU(ctx->r13, 0X13);
    // 0x8003E748: beq         $at, $zero, L_8003ED04
    if (ctx->r1 == 0) {
        // 0x8003E74C: nop
    
            goto L_8003ED04;
    }
    // 0x8003E74C: nop

L_8003E750:
    // 0x8003E750: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003E754: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8003E758: beq         $at, $zero, L_8003E794
    if (ctx->r1 == 0) {
        // 0x8003E75C: nop
    
            goto L_8003E794;
    }
    // 0x8003E75C: nop

L_8003E760:
    // 0x8003E760: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8003E764: lbu         $t7, 0x77($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X77);
    // 0x8003E768: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x8003E76C: lbu         $t6, 0x55B0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X55B0);
    // 0x8003E770: or          $t8, $t7, $s2
    ctx->r24 = ctx->r15 | ctx->r18;
    // 0x8003E774: beq         $t6, $t8, L_8003E794
    if (ctx->r14 == ctx->r24) {
        // 0x8003E778: nop
    
            goto L_8003E794;
    }
    // 0x8003E778: nop

    // 0x8003E77C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003E780: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x8003E784: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8003E788: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8003E78C: bne         $at, $zero, L_8003E760
    if (ctx->r1 != 0) {
        // 0x8003E790: nop
    
            goto L_8003E760;
    }
    // 0x8003E790: nop

L_8003E794:
    // 0x8003E794: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003E798: bne         $s0, $at, L_8003E7E8
    if (ctx->r16 != ctx->r1) {
        // 0x8003E79C: nop
    
            goto L_8003E7E8;
    }
    // 0x8003E79C: nop

    // 0x8003E7A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003E7A4: slti        $at, $s0, 0x13
    ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
    // 0x8003E7A8: beq         $at, $zero, L_8003E7E8
    if (ctx->r1 == 0) {
        // 0x8003E7AC: nop
    
            goto L_8003E7E8;
    }
    // 0x8003E7AC: nop

L_8003E7B0:
    // 0x8003E7B0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8003E7B4: lbu         $t0, 0x77($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X77);
    // 0x8003E7B8: addu        $t1, $t1, $s0
    ctx->r9 = ADD32(ctx->r9, ctx->r16);
    // 0x8003E7BC: lbu         $t1, 0x55B0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X55B0);
    // 0x8003E7C0: or          $t2, $t0, $s2
    ctx->r10 = ctx->r8 | ctx->r18;
    // 0x8003E7C4: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8003E7C8: bne         $t3, $zero, L_8003E7E8
    if (ctx->r11 != 0) {
        // 0x8003E7CC: nop
    
            goto L_8003E7E8;
    }
    // 0x8003E7CC: nop

    // 0x8003E7D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003E7D4: andi        $t4, $s0, 0xFF
    ctx->r12 = ctx->r16 & 0XFF;
    // 0x8003E7D8: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x8003E7DC: slti        $at, $s0, 0x13
    ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
    // 0x8003E7E0: bne         $at, $zero, L_8003E7B0
    if (ctx->r1 != 0) {
        // 0x8003E7E4: nop
    
            goto L_8003E7B0;
    }
    // 0x8003E7E4: nop

L_8003E7E8:
    // 0x8003E7E8: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8003E7EC: beq         $s0, $at, L_8003ECEC
    if (ctx->r16 == ctx->r1) {
        // 0x8003E7F0: nop
    
            goto L_8003ECEC;
    }
    // 0x8003E7F0: nop

    // 0x8003E7F4: jal         0x80067DD8
    // 0x8003E7F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    CurrentPiece_Spawn(rdram, ctx);
        goto after_0;
    // 0x8003E7F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8003E7FC: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8003E800: nop

    // 0x8003E804: lbu         $t7, 0x0($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X0);
    // 0x8003E808: lbu         $s3, 0x0($t5)
    ctx->r19 = MEM_BU(ctx->r13, 0X0);
    // 0x8003E80C: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x8003E810: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003E814: beq         $at, $zero, L_8003ECEC
    if (ctx->r1 == 0) {
        // 0x8003E818: nop
    
            goto L_8003ECEC;
    }
    // 0x8003E818: nop

L_8003E81C:
    // 0x8003E81C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8003E820: slti        $at, $s4, 0x4
    ctx->r1 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
    // 0x8003E824: beq         $at, $zero, L_8003ECC8
    if (ctx->r1 == 0) {
        // 0x8003E828: nop
    
            goto L_8003ECC8;
    }
    // 0x8003E828: nop

L_8003E82C:
    // 0x8003E82C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8003E830: lbu         $a3, 0x7F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X7F);
    // 0x8003E834: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x8003E838: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003E83C: addiu       $t0, $t9, 0x3
    ctx->r8 = ADD32(ctx->r25, 0X3);
    // 0x8003E840: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    // 0x8003E844: addiu       $a1, $sp, 0x57
    ctx->r5 = ADD32(ctx->r29, 0X57);
    // 0x8003E848: jal         0x8004199C
    // 0x8003E84C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    aisquarelist_DropPieceToRow(rdram, ctx);
        goto after_1;
    // 0x8003E84C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_1:
    // 0x8003E850: beq         $v0, $zero, L_8003ECB0
    if (ctx->r2 == 0) {
        // 0x8003E854: nop
    
            goto L_8003ECB0;
    }
    // 0x8003E854: nop

    // 0x8003E858: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8003E85C: lbu         $t1, 0x57($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X57);
    // 0x8003E860: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x8003E864: nop

    // 0x8003E868: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8003E86C: bne         $at, $zero, L_8003ECB0
    if (ctx->r1 != 0) {
        // 0x8003E870: nop
    
            goto L_8003ECB0;
    }
    // 0x8003E870: nop

L_8003E874:
    // 0x8003E874: lbu         $a1, 0x57($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X57);
    // 0x8003E878: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003E87C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8003E880: jal         0x800413C0
    // 0x8003E884: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_2;
    // 0x8003E884: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x8003E888: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8003E88C: addiu       $t5, $sp, 0x54
    ctx->r13 = ADD32(ctx->r29, 0X54);
    // 0x8003E890: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x8003E894: lbu         $a1, 0x1($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0X1);
    // 0x8003E898: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003E89C: addiu       $a2, $sp, 0x56
    ctx->r6 = ADD32(ctx->r29, 0X56);
    // 0x8003E8A0: jal         0x80041B48
    // 0x8003E8A4: addiu       $a3, $sp, 0x55
    ctx->r7 = ADD32(ctx->r29, 0X55);
    aisquarelist_CheckSquareCompletion(rdram, ctx);
        goto after_3;
    // 0x8003E8A4: addiu       $a3, $sp, 0x55
    ctx->r7 = ADD32(ctx->r29, 0X55);
    after_3:
    // 0x8003E8A8: beq         $v0, $zero, L_8003EC34
    if (ctx->r2 == 0) {
        // 0x8003E8AC: nop
    
            goto L_8003EC34;
    }
    // 0x8003E8AC: nop

    // 0x8003E8B0: lbu         $t7, 0x56($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X56);
    // 0x8003E8B4: lbu         $t6, 0x6F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X6F);
    // 0x8003E8B8: nop

    // 0x8003E8BC: bne         $t7, $t6, L_8003EC34
    if (ctx->r15 != ctx->r14) {
        // 0x8003E8C0: nop
    
            goto L_8003EC34;
    }
    // 0x8003E8C0: nop

    // 0x8003E8C4: lbu         $t8, 0x73($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X73);
    // 0x8003E8C8: lbu         $t9, 0x55($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X55);
    // 0x8003E8CC: nop

    // 0x8003E8D0: beq         $t8, $t9, L_8003EC34
    if (ctx->r24 == ctx->r25) {
        // 0x8003E8D4: nop
    
            goto L_8003EC34;
    }
    // 0x8003E8D4: nop

    // 0x8003E8D8: lbu         $t0, 0x77($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X77);
    // 0x8003E8DC: lbu         $t2, 0x54($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X54);
    // 0x8003E8E0: nop

    // 0x8003E8E4: beq         $t0, $t2, L_8003EC34
    if (ctx->r8 == ctx->r10) {
        // 0x8003E8E8: nop
    
            goto L_8003EC34;
    }
    // 0x8003E8E8: nop

    // 0x8003E8EC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8003E8F0: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8003E8F4: beq         $at, $zero, L_8003E948
    if (ctx->r1 == 0) {
        // 0x8003E8F8: nop
    
            goto L_8003E948;
    }
    // 0x8003E8F8: nop

L_8003E8FC:
    // 0x8003E8FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003E900: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8003E904: beq         $at, $zero, L_8003E930
    if (ctx->r1 == 0) {
        // 0x8003E908: nop
    
            goto L_8003E930;
    }
    // 0x8003E908: nop

L_8003E90C:
    // 0x8003E90C: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x8003E910: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003E914: andi        $t5, $s0, 0xFF
    ctx->r13 = ctx->r16 & 0XFF;
    // 0x8003E918: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x8003E91C: addu        $t3, $t1, $s5
    ctx->r11 = ADD32(ctx->r9, ctx->r21);
    // 0x8003E920: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8003E924: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x8003E928: bne         $at, $zero, L_8003E90C
    if (ctx->r1 != 0) {
        // 0x8003E92C: sb          $zero, 0x44($t4)
        MEM_B(0X44, ctx->r12) = 0;
            goto L_8003E90C;
    }
    // 0x8003E92C: sb          $zero, 0x44($t4)
    MEM_B(0X44, ctx->r12) = 0;
L_8003E930:
    // 0x8003E930: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8003E934: andi        $t7, $s5, 0xFF
    ctx->r15 = ctx->r21 & 0XFF;
    // 0x8003E938: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
    // 0x8003E93C: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8003E940: bne         $at, $zero, L_8003E8FC
    if (ctx->r1 != 0) {
        // 0x8003E944: nop
    
            goto L_8003E8FC;
    }
    // 0x8003E944: nop

L_8003E948:
    // 0x8003E948: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8003E94C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8003E950: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x8003E954: lbu         $t9, 0x1($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X1);
    // 0x8003E958: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8003E95C: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8003E960: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8003E964: jal         0x8003F300
    // 0x8003E968: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    aisquarelist_FloodFillRegion(rdram, ctx);
        goto after_4;
    // 0x8003E968: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_4:
    // 0x8003E96C: bgez        $v0, L_8003E980
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003E970: andi        $t0, $v0, 0x3
        ctx->r8 = ctx->r2 & 0X3;
            goto L_8003E980;
    }
    // 0x8003E970: andi        $t0, $v0, 0x3
    ctx->r8 = ctx->r2 & 0X3;
    // 0x8003E974: beq         $t0, $zero, L_8003E980
    if (ctx->r8 == 0) {
        // 0x8003E978: nop
    
            goto L_8003E980;
    }
    // 0x8003E978: nop

    // 0x8003E97C: addiu       $t0, $t0, -0x4
    ctx->r8 = ADD32(ctx->r8, -0X4);
L_8003E980:
    // 0x8003E980: bne         $t0, $zero, L_8003EC34
    if (ctx->r8 != 0) {
        // 0x8003E984: nop
    
            goto L_8003EC34;
    }
    // 0x8003E984: nop

    // 0x8003E988: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8003E98C: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8003E990: beq         $at, $zero, L_8003EA4C
    if (ctx->r1 == 0) {
        // 0x8003E994: nop
    
            goto L_8003EA4C;
    }
    // 0x8003E994: nop

L_8003E998:
    // 0x8003E998: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003E99C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8003E9A0: beq         $at, $zero, L_8003EA34
    if (ctx->r1 == 0) {
        // 0x8003E9A4: nop
    
            goto L_8003EA34;
    }
    // 0x8003E9A4: nop

L_8003E9A8:
    // 0x8003E9A8: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8003E9AC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8003E9B0: lbu         $t4, 0x1($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X1);
    // 0x8003E9B4: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x8003E9B8: addu        $t5, $s5, $t4
    ctx->r13 = ADD32(ctx->r21, ctx->r12);
    // 0x8003E9BC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8003E9C0: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8003E9C4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8003E9C8: addu        $t3, $s0, $t1
    ctx->r11 = ADD32(ctx->r16, ctx->r9);
    // 0x8003E9CC: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x8003E9D0: lw          $t9, 0x1F30($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1F30);
    // 0x8003E9D4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8003E9D8: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8003E9DC: addu        $s6, $t9, $t8
    ctx->r22 = ADD32(ctx->r25, ctx->r24);
    // 0x8003E9E0: lbu         $t0, 0x0($s6)
    ctx->r8 = MEM_BU(ctx->r22, 0X0);
    // 0x8003E9E4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8003E9E8: bne         $t0, $at, L_8003EA08
    if (ctx->r8 != ctx->r1) {
        // 0x8003E9EC: nop
    
            goto L_8003EA08;
    }
    // 0x8003E9EC: nop

    // 0x8003E9F0: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8003E9F4: addu        $t4, $t2, $s5
    ctx->r12 = ADD32(ctx->r10, ctx->r21);
    // 0x8003E9F8: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x8003E9FC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8003EA00: b           L_8003EA1C
    // 0x8003EA04: sb          $t1, 0x44($t5)
    MEM_B(0X44, ctx->r13) = ctx->r9;
        goto L_8003EA1C;
    // 0x8003EA04: sb          $t1, 0x44($t5)
    MEM_B(0X44, ctx->r13) = ctx->r9;
L_8003EA08:
    // 0x8003EA08: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8003EA0C: lbu         $t3, 0x1($s6)
    ctx->r11 = MEM_BU(ctx->r22, 0X1);
    // 0x8003EA10: addu        $t6, $t7, $s5
    ctx->r14 = ADD32(ctx->r15, ctx->r21);
    // 0x8003EA14: addu        $t9, $sp, $t6
    ctx->r25 = ADD32(ctx->r29, ctx->r14);
    // 0x8003EA18: sb          $t3, 0x44($t9)
    MEM_B(0X44, ctx->r25) = ctx->r11;
L_8003EA1C:
    // 0x8003EA1C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003EA20: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x8003EA24: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8003EA28: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8003EA2C: bne         $at, $zero, L_8003E9A8
    if (ctx->r1 != 0) {
        // 0x8003EA30: nop
    
            goto L_8003E9A8;
    }
    // 0x8003EA30: nop

L_8003EA34:
    // 0x8003EA34: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8003EA38: andi        $t0, $s5, 0xFF
    ctx->r8 = ctx->r21 & 0XFF;
    // 0x8003EA3C: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
    // 0x8003EA40: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8003EA44: bne         $at, $zero, L_8003E998
    if (ctx->r1 != 0) {
        // 0x8003EA48: nop
    
            goto L_8003E998;
    }
    // 0x8003EA48: nop

L_8003EA4C:
    // 0x8003EA4C: lbu         $t2, 0x56($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X56);
    // 0x8003EA50: nop

    // 0x8003EA54: bne         $t2, $zero, L_8003EB48
    if (ctx->r10 != 0) {
        // 0x8003EA58: nop
    
            goto L_8003EB48;
    }
    // 0x8003EA58: nop

    // 0x8003EA5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003EA60: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8003EA64: beq         $at, $zero, L_8003EB48
    if (ctx->r1 == 0) {
        // 0x8003EA68: nop
    
            goto L_8003EB48;
    }
    // 0x8003EA68: nop

L_8003EA6C:
    // 0x8003EA6C: lbu         $a2, 0x54($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X54);
    // 0x8003EA70: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8003EA74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003EA78: jal         0x8003F4F4
    // 0x8003EA7C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    aisquarelist_MatchPattern4x4(rdram, ctx);
        goto after_5;
    // 0x8003EA7C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_5:
    // 0x8003EA80: beq         $v0, $zero, L_8003EB30
    if (ctx->r2 == 0) {
        // 0x8003EA84: nop
    
            goto L_8003EB30;
    }
    // 0x8003EA84: nop

    // 0x8003EA88: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8003EA8C: lbu         $t4, 0x7F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X7F);
    // 0x8003EA90: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8003EA94: lbu         $a1, 0x56($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X56);
    // 0x8003EA98: lbu         $a2, 0x55($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X55);
    // 0x8003EA9C: lbu         $a3, 0x54($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X54);
    // 0x8003EAA0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8003EAA4: jal         0x8003E68C
    // 0x8003EAA8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    aisquarelist_SearchSquaresRecursive(rdram, ctx);
        goto after_6;
    // 0x8003EAA8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_6:
    // 0x8003EAAC: beq         $v0, $zero, L_8003EB30
    if (ctx->r2 == 0) {
        // 0x8003EAB0: nop
    
            goto L_8003EB30;
    }
    // 0x8003EAB0: nop

    // 0x8003EAB4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8003EAB8: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8003EABC: beq         $at, $zero, L_8003EB0C
    if (ctx->r1 == 0) {
        // 0x8003EAC0: nop
    
            goto L_8003EB0C;
    }
    // 0x8003EAC0: nop

L_8003EAC4:
    // 0x8003EAC4: addu        $t5, $sp, $s5
    ctx->r13 = ADD32(ctx->r29, ctx->r21);
    // 0x8003EAC8: lbu         $t5, 0x58($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X58);
    // 0x8003EACC: nop

    // 0x8003EAD0: bne         $t5, $s2, L_8003EAF4
    if (ctx->r13 != ctx->r18) {
        // 0x8003EAD4: nop
    
            goto L_8003EAF4;
    }
    // 0x8003EAD4: nop

    // 0x8003EAD8: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8003EADC: nop

    // 0x8003EAE0: lh          $t3, 0x0($t7)
    ctx->r11 = MEM_H(ctx->r15, 0X0);
    // 0x8003EAE4: nop

    // 0x8003EAE8: addiu       $t6, $t3, 0x14
    ctx->r14 = ADD32(ctx->r11, 0X14);
    // 0x8003EAEC: b           L_8003EB0C
    // 0x8003EAF0: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
        goto L_8003EB0C;
    // 0x8003EAF0: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
L_8003EAF4:
    // 0x8003EAF4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8003EAF8: andi        $t9, $s5, 0xFF
    ctx->r25 = ctx->r21 & 0XFF;
    // 0x8003EAFC: or          $s5, $t9, $zero
    ctx->r21 = ctx->r25 | 0;
    // 0x8003EB00: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8003EB04: bne         $at, $zero, L_8003EAC4
    if (ctx->r1 != 0) {
        // 0x8003EB08: nop
    
            goto L_8003EAC4;
    }
    // 0x8003EB08: nop

L_8003EB0C:
    // 0x8003EB0C: lbu         $a1, 0x57($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X57);
    // 0x8003EB10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003EB14: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8003EB18: jal         0x800413C0
    // 0x8003EB1C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_7;
    // 0x8003EB1C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_7:
    // 0x8003EB20: jal         0x80067DD8
    // 0x8003EB24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    CurrentPiece_Spawn(rdram, ctx);
        goto after_8;
    // 0x8003EB24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8003EB28: b           L_8003ED18
    // 0x8003EB2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003ED18;
    // 0x8003EB2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003EB30:
    // 0x8003EB30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003EB34: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x8003EB38: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8003EB3C: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8003EB40: bne         $at, $zero, L_8003EA6C
    if (ctx->r1 != 0) {
        // 0x8003EB44: nop
    
            goto L_8003EA6C;
    }
    // 0x8003EB44: nop

L_8003EB48:
    // 0x8003EB48: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003EB4C: slti        $at, $s0, 0x13
    ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
    // 0x8003EB50: beq         $at, $zero, L_8003EC34
    if (ctx->r1 == 0) {
        // 0x8003EB54: nop
    
            goto L_8003EC34;
    }
    // 0x8003EB54: nop

L_8003EB58:
    // 0x8003EB58: lbu         $a2, 0x54($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X54);
    // 0x8003EB5C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8003EB60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003EB64: jal         0x8003F4F4
    // 0x8003EB68: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    aisquarelist_MatchPattern4x4(rdram, ctx);
        goto after_9;
    // 0x8003EB68: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_9:
    // 0x8003EB6C: beq         $v0, $zero, L_8003EC1C
    if (ctx->r2 == 0) {
        // 0x8003EB70: nop
    
            goto L_8003EC1C;
    }
    // 0x8003EB70: nop

    // 0x8003EB74: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8003EB78: lbu         $t2, 0x7F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X7F);
    // 0x8003EB7C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8003EB80: lbu         $a1, 0x56($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X56);
    // 0x8003EB84: lbu         $a2, 0x55($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X55);
    // 0x8003EB88: lbu         $a3, 0x54($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X54);
    // 0x8003EB8C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003EB90: jal         0x8003E68C
    // 0x8003EB94: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    aisquarelist_SearchSquaresRecursive(rdram, ctx);
        goto after_10;
    // 0x8003EB94: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_10:
    // 0x8003EB98: beq         $v0, $zero, L_8003EC1C
    if (ctx->r2 == 0) {
        // 0x8003EB9C: nop
    
            goto L_8003EC1C;
    }
    // 0x8003EB9C: nop

    // 0x8003EBA0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8003EBA4: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8003EBA8: beq         $at, $zero, L_8003EBF8
    if (ctx->r1 == 0) {
        // 0x8003EBAC: nop
    
            goto L_8003EBF8;
    }
    // 0x8003EBAC: nop

L_8003EBB0:
    // 0x8003EBB0: addu        $t1, $sp, $s5
    ctx->r9 = ADD32(ctx->r29, ctx->r21);
    // 0x8003EBB4: lbu         $t1, 0x58($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X58);
    // 0x8003EBB8: nop

    // 0x8003EBBC: bne         $t1, $s2, L_8003EBE0
    if (ctx->r9 != ctx->r18) {
        // 0x8003EBC0: nop
    
            goto L_8003EBE0;
    }
    // 0x8003EBC0: nop

    // 0x8003EBC4: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x8003EBC8: nop

    // 0x8003EBCC: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8003EBD0: nop

    // 0x8003EBD4: addiu       $t3, $t5, 0x14
    ctx->r11 = ADD32(ctx->r13, 0X14);
    // 0x8003EBD8: b           L_8003EBF8
    // 0x8003EBDC: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
        goto L_8003EBF8;
    // 0x8003EBDC: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
L_8003EBE0:
    // 0x8003EBE0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8003EBE4: andi        $t6, $s5, 0xFF
    ctx->r14 = ctx->r21 & 0XFF;
    // 0x8003EBE8: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
    // 0x8003EBEC: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8003EBF0: bne         $at, $zero, L_8003EBB0
    if (ctx->r1 != 0) {
        // 0x8003EBF4: nop
    
            goto L_8003EBB0;
    }
    // 0x8003EBF4: nop

L_8003EBF8:
    // 0x8003EBF8: lbu         $a1, 0x57($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X57);
    // 0x8003EBFC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003EC00: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8003EC04: jal         0x800413C0
    // 0x8003EC08: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_11;
    // 0x8003EC08: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_11:
    // 0x8003EC0C: jal         0x80067DD8
    // 0x8003EC10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    CurrentPiece_Spawn(rdram, ctx);
        goto after_12;
    // 0x8003EC10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8003EC14: b           L_8003ED18
    // 0x8003EC18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003ED18;
    // 0x8003EC18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003EC1C:
    // 0x8003EC1C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003EC20: andi        $t7, $s0, 0xFF
    ctx->r15 = ctx->r16 & 0XFF;
    // 0x8003EC24: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8003EC28: slti        $at, $s0, 0x13
    ctx->r1 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
    // 0x8003EC2C: bne         $at, $zero, L_8003EB58
    if (ctx->r1 != 0) {
        // 0x8003EC30: nop
    
            goto L_8003EB58;
    }
    // 0x8003EC30: nop

L_8003EC34:
    // 0x8003EC34: lbu         $a1, 0x57($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X57);
    // 0x8003EC38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003EC3C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8003EC40: jal         0x800413C0
    // 0x8003EC44: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_13;
    // 0x8003EC44: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_13:
    // 0x8003EC48: lbu         $t9, 0x57($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X57);
    // 0x8003EC4C: nop

    // 0x8003EC50: beq         $t9, $zero, L_8003ECB0
    if (ctx->r25 == 0) {
        // 0x8003EC54: nop
    
            goto L_8003ECB0;
    }
    // 0x8003EC54: nop

    // 0x8003EC58: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003EC5C: jal         0x8004191C
    // 0x8003EC60: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    aisquarelist_IsColumnClearToTop(rdram, ctx);
        goto after_14;
    // 0x8003EC60: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_14:
    // 0x8003EC64: bne         $v0, $zero, L_8003ECB0
    if (ctx->r2 != 0) {
        // 0x8003EC68: nop
    
            goto L_8003ECB0;
    }
    // 0x8003EC68: nop

    // 0x8003EC6C: lbu         $t8, 0x57($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X57);
    // 0x8003EC70: lbu         $a3, 0x7F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X7F);
    // 0x8003EC74: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8003EC78: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    // 0x8003EC7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003EC80: addiu       $a1, $sp, 0x57
    ctx->r5 = ADD32(ctx->r29, 0X57);
    // 0x8003EC84: jal         0x8004199C
    // 0x8003EC88: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    aisquarelist_DropPieceToRow(rdram, ctx);
        goto after_15;
    // 0x8003EC88: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_15:
    // 0x8003EC8C: beq         $v0, $zero, L_8003ECB0
    if (ctx->r2 == 0) {
        // 0x8003EC90: nop
    
            goto L_8003ECB0;
    }
    // 0x8003EC90: nop

    // 0x8003EC94: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8003EC98: lbu         $t2, 0x57($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X57);
    // 0x8003EC9C: lbu         $t5, 0x1($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X1);
    // 0x8003ECA0: nop

    // 0x8003ECA4: slt         $at, $t2, $t5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8003ECA8: beq         $at, $zero, L_8003E874
    if (ctx->r1 == 0) {
        // 0x8003ECAC: nop
    
            goto L_8003E874;
    }
    // 0x8003ECAC: nop

L_8003ECB0:
    // 0x8003ECB0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8003ECB4: andi        $t3, $s4, 0xFF
    ctx->r11 = ctx->r20 & 0XFF;
    // 0x8003ECB8: or          $s4, $t3, $zero
    ctx->r20 = ctx->r11 | 0;
    // 0x8003ECBC: slti        $at, $s4, 0x4
    ctx->r1 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
    // 0x8003ECC0: bne         $at, $zero, L_8003E82C
    if (ctx->r1 != 0) {
        // 0x8003ECC4: nop
    
            goto L_8003E82C;
    }
    // 0x8003ECC4: nop

L_8003ECC8:
    // 0x8003ECC8: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8003ECCC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003ECD0: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8003ECD4: andi        $t4, $s3, 0xFF
    ctx->r12 = ctx->r19 & 0XFF;
    // 0x8003ECD8: or          $s3, $t4, $zero
    ctx->r19 = ctx->r12 | 0;
    // 0x8003ECDC: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x8003ECE0: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003ECE4: bne         $at, $zero, L_8003E81C
    if (ctx->r1 != 0) {
        // 0x8003ECE8: nop
    
            goto L_8003E81C;
    }
    // 0x8003ECE8: nop

L_8003ECEC:
    // 0x8003ECEC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003ECF0: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x8003ECF4: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x8003ECF8: slti        $at, $s2, 0x7
    ctx->r1 = SIGNED(ctx->r18) < 0X7 ? 1 : 0;
    // 0x8003ECFC: bne         $at, $zero, L_8003E750
    if (ctx->r1 != 0) {
        // 0x8003ED00: nop
    
            goto L_8003E750;
    }
    // 0x8003ED00: nop

L_8003ED04:
    // 0x8003ED04: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8003ED08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003ED0C: jal         0x80067DD8
    // 0x8003ED10: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    CurrentPiece_Spawn(rdram, ctx);
        goto after_16;
    // 0x8003ED10: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    after_16:
    // 0x8003ED14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003ED18:
    // 0x8003ED18: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003ED1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003ED20: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003ED24: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8003ED28: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8003ED2C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8003ED30: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8003ED34: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8003ED38: jr          $ra
    // 0x8003ED3C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8003ED3C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}

RECOMP_FUNC void aisquarelist_EvaluatePlacementSquares(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ED40: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8003ED44: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8003ED48: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8003ED4C: lbu         $t8, 0x77($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X77);
    // 0x8003ED50: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8003ED54: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8003ED58: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8003ED5C: lw          $t2, 0x1F20($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1F20);
    // 0x8003ED60: lbu         $t3, 0x7F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X7F);
    // 0x8003ED64: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003ED68: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8003ED6C: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x8003ED70: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x8003ED74: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8003ED78: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8003ED7C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8003ED80: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8003ED84: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003ED88: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003ED8C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8003ED90: lb          $t0, 0x1($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X1);
    // 0x8003ED94: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8003ED98: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8003ED9C: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8003EDA0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8003EDA4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003EDA8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8003EDAC: addu        $s4, $t7, $t1
    ctx->r20 = ADD32(ctx->r15, ctx->r9);
    // 0x8003EDB0: lbu         $s0, 0x0($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0X0);
    // 0x8003EDB4: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8003EDB8: beq         $at, $zero, L_8003F2BC
    if (ctx->r1 == 0) {
        // 0x8003EDBC: addiu       $s4, $s4, 0x7
        ctx->r20 = ADD32(ctx->r20, 0X7);
            goto L_8003F2BC;
    }
    // 0x8003EDBC: addiu       $s4, $s4, 0x7
    ctx->r20 = ADD32(ctx->r20, 0X7);
L_8003EDC0:
    // 0x8003EDC0: slti        $at, $s0, 0xC8
    ctx->r1 = SIGNED(ctx->r16) < 0XC8 ? 1 : 0;
    // 0x8003EDC4: bne         $at, $zero, L_8003EDF4
    if (ctx->r1 != 0) {
        // 0x8003EDC8: nop
    
            goto L_8003EDF4;
    }
    // 0x8003EDC8: nop

    // 0x8003EDCC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003EDD0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8003EDD4: addiu       $a1, $a1, -0x4BD8
    ctx->r5 = ADD32(ctx->r5, -0X4BD8);
    // 0x8003EDD8: jal         0x80083560
    // 0x8003EDDC: addiu       $a0, $a0, -0x4BF0
    ctx->r4 = ADD32(ctx->r4, -0X4BF0);
    debug_print_reason_routine(rdram, ctx);
        goto after_0;
    // 0x8003EDDC: addiu       $a0, $a0, -0x4BF0
    ctx->r4 = ADD32(ctx->r4, -0X4BF0);
    after_0:
    // 0x8003EDE0: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8003EDE4: addiu       $s0, $zero, 0xC8
    ctx->r16 = ADD32(0, 0XC8);
    // 0x8003EDE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003EDEC: b           L_8003F2C8
    // 0x8003EDF0: sb          $s0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r16;
        goto L_8003F2C8;
    // 0x8003EDF0: sb          $s0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r16;
L_8003EDF4:
    // 0x8003EDF4: lbu         $t9, 0x7F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X7F);
    // 0x8003EDF8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8003EDFC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8003EE00: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8003EE04: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003EE08: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8003EE0C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003EE10: lw          $t8, 0x1F20($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F20);
    // 0x8003EE14: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8003EE18: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8003EE1C: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8003EE20: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x8003EE24: addu        $t7, $t8, $t0
    ctx->r15 = ADD32(ctx->r24, ctx->r8);
    // 0x8003EE28: addu        $s7, $t7, $t1
    ctx->r23 = ADD32(ctx->r15, ctx->r9);
    // 0x8003EE2C: lbu         $t2, 0x2($s7)
    ctx->r10 = MEM_BU(ctx->r23, 0X2);
    // 0x8003EE30: addiu       $s7, $s7, 0x2
    ctx->r23 = ADD32(ctx->r23, 0X2);
    // 0x8003EE34: sb          $t2, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r10;
    // 0x8003EE38: lb          $t3, 0x1($s7)
    ctx->r11 = MEM_B(ctx->r23, 0X1);
    // 0x8003EE3C: lbu         $t6, 0x5B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003EE40: sb          $t3, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r11;
    // 0x8003EE44: lbu         $t4, 0x2($s7)
    ctx->r12 = MEM_BU(ctx->r23, 0X2);
    // 0x8003EE48: nop

    // 0x8003EE4C: sb          $t4, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r12;
    // 0x8003EE50: lbu         $t5, 0x0($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X0);
    // 0x8003EE54: nop

    // 0x8003EE58: slt         $at, $t6, $t5
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8003EE5C: bne         $at, $zero, L_8003F290
    if (ctx->r1 != 0) {
        // 0x8003EE60: nop
    
            goto L_8003F290;
    }
    // 0x8003EE60: nop

    // 0x8003EE64: lbu         $t9, 0x0($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X0);
    // 0x8003EE68: nop

    // 0x8003EE6C: addiu       $t8, $t9, 0x3
    ctx->r24 = ADD32(ctx->r25, 0X3);
    // 0x8003EE70: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003EE74: bne         $at, $zero, L_8003F290
    if (ctx->r1 != 0) {
        // 0x8003EE78: nop
    
            goto L_8003F290;
    }
    // 0x8003EE78: nop

    // 0x8003EE7C: lbu         $t0, 0x1($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0X1);
    // 0x8003EE80: lbu         $t7, 0x5A($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X5A);
    // 0x8003EE84: nop

    // 0x8003EE88: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8003EE8C: bne         $at, $zero, L_8003F290
    if (ctx->r1 != 0) {
        // 0x8003EE90: nop
    
            goto L_8003F290;
    }
    // 0x8003EE90: nop

    // 0x8003EE94: lbu         $t1, 0x1($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X1);
    // 0x8003EE98: nop

    // 0x8003EE9C: addiu       $t2, $t1, 0x3
    ctx->r10 = ADD32(ctx->r9, 0X3);
    // 0x8003EEA0: slt         $at, $t2, $t7
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8003EEA4: bne         $at, $zero, L_8003F290
    if (ctx->r1 != 0) {
        // 0x8003EEA8: nop
    
            goto L_8003F290;
    }
    // 0x8003EEA8: nop

    // 0x8003EEAC: lbu         $a2, 0x59($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X59);
    // 0x8003EEB0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8003EEB4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8003EEB8: jal         0x800413C0
    // 0x8003EEBC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_1;
    // 0x8003EEBC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_1:
    // 0x8003EEC0: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x8003EEC4: lbu         $a1, 0x1($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0X1);
    // 0x8003EEC8: lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X0);
    // 0x8003EECC: addiu       $t3, $sp, 0x57
    ctx->r11 = ADD32(ctx->r29, 0X57);
    // 0x8003EED0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003EED4: addiu       $a2, $sp, 0x56
    ctx->r6 = ADD32(ctx->r29, 0X56);
    // 0x8003EED8: jal         0x80041B48
    // 0x8003EEDC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    aisquarelist_CheckSquareCompletion(rdram, ctx);
        goto after_2;
    // 0x8003EEDC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_2:
    // 0x8003EEE0: beq         $v0, $zero, L_8003F218
    if (ctx->r2 == 0) {
        // 0x8003EEE4: nop
    
            goto L_8003F218;
    }
    // 0x8003EEE4: nop

    // 0x8003EEE8: lbu         $t4, 0x58($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X58);
    // 0x8003EEEC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003EEF0: bne         $t4, $at, L_8003EF70
    if (ctx->r12 != ctx->r1) {
        // 0x8003EEF4: nop
    
            goto L_8003EF70;
    }
    // 0x8003EEF4: nop

    // 0x8003EEF8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8003EEFC: lw          $t5, 0x1F40($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F40);
    // 0x8003EF00: lbu         $t0, 0x5B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003EF04: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8003EF08: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x8003EF0C: addu        $s5, $t9, $t8
    ctx->r21 = ADD32(ctx->r25, ctx->r24);
    // 0x8003EF10: sb          $t0, 0x2($s5)
    MEM_B(0X2, ctx->r21) = ctx->r8;
    // 0x8003EF14: lbu         $t1, 0x5A($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X5A);
    // 0x8003EF18: addiu       $t6, $zero, 0x7FFF
    ctx->r14 = ADD32(0, 0X7FFF);
    // 0x8003EF1C: sb          $t1, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r9;
    // 0x8003EF20: lbu         $t2, 0x59($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X59);
    // 0x8003EF24: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
    // 0x8003EF28: addiu       $a0, $s5, 0x5
    ctx->r4 = ADD32(ctx->r21, 0X5);
    // 0x8003EF2C: addiu       $a3, $s5, 0x6
    ctx->r7 = ADD32(ctx->r21, 0X6);
    // 0x8003EF30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003EF34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003EF38: jal         0x80040784
    // 0x8003EF3C: sb          $t2, 0x4($s5)
    MEM_B(0X4, ctx->r21) = ctx->r10;
    aisquarelist_GetPieceBounds(rdram, ctx);
        goto after_3;
    // 0x8003EF3C: sb          $t2, 0x4($s5)
    MEM_B(0X4, ctx->r21) = ctx->r10;
    after_3:
    // 0x8003EF40: lbu         $a0, 0x5B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003EF44: lbu         $a1, 0x5A($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X5A);
    // 0x8003EF48: lbu         $a2, 0x59($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X59);
    // 0x8003EF4C: jal         0x800413C0
    // 0x8003EF50: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_4;
    // 0x8003EF50: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_4:
    // 0x8003EF54: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003EF58: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8003EF5C: andi        $t7, $s0, 0xFF
    ctx->r15 = ctx->r16 & 0XFF;
    // 0x8003EF60: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8003EF64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003EF68: b           L_8003F2C8
    // 0x8003EF6C: sb          $s0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r16;
        goto L_8003F2C8;
    // 0x8003EF6C: sb          $s0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r16;
L_8003EF70:
    // 0x8003EF70: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003EF74: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8003EF78: beq         $at, $zero, L_8003EFCC
    if (ctx->r1 == 0) {
        // 0x8003EF7C: nop
    
            goto L_8003EFCC;
    }
    // 0x8003EF7C: nop

L_8003EF80:
    // 0x8003EF80: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003EF84: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8003EF88: beq         $at, $zero, L_8003EFB4
    if (ctx->r1 == 0) {
        // 0x8003EF8C: nop
    
            goto L_8003EFB4;
    }
    // 0x8003EF8C: nop

L_8003EF90:
    // 0x8003EF90: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x8003EF94: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003EF98: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x8003EF9C: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x8003EFA0: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x8003EFA4: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8003EFA8: addu        $t9, $sp, $t5
    ctx->r25 = ADD32(ctx->r29, ctx->r13);
    // 0x8003EFAC: bne         $at, $zero, L_8003EF90
    if (ctx->r1 != 0) {
        // 0x8003EFB0: sb          $zero, 0x40($t9)
        MEM_B(0X40, ctx->r25) = 0;
            goto L_8003EF90;
    }
    // 0x8003EFB0: sb          $zero, 0x40($t9)
    MEM_B(0X40, ctx->r25) = 0;
L_8003EFB4:
    // 0x8003EFB4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003EFB8: andi        $t0, $s3, 0xFF
    ctx->r8 = ctx->r19 & 0XFF;
    // 0x8003EFBC: or          $s3, $t0, $zero
    ctx->r19 = ctx->r8 | 0;
    // 0x8003EFC0: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8003EFC4: bne         $at, $zero, L_8003EF80
    if (ctx->r1 != 0) {
        // 0x8003EFC8: nop
    
            goto L_8003EF80;
    }
    // 0x8003EFC8: nop

L_8003EFCC:
    // 0x8003EFCC: lbu         $t1, 0x1($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X1);
    // 0x8003EFD0: lbu         $a1, 0x0($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0X0);
    // 0x8003EFD4: lbu         $a2, 0x1($s4)
    ctx->r6 = MEM_BU(ctx->r20, 0X1);
    // 0x8003EFD8: lbu         $a3, 0x0($s4)
    ctx->r7 = MEM_BU(ctx->r20, 0X0);
    // 0x8003EFDC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8003EFE0: jal         0x8003F300
    // 0x8003EFE4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    aisquarelist_FloodFillRegion(rdram, ctx);
        goto after_5;
    // 0x8003EFE4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_5:
    // 0x8003EFE8: bgez        $v0, L_8003EFFC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003EFEC: andi        $t2, $v0, 0x3
        ctx->r10 = ctx->r2 & 0X3;
            goto L_8003EFFC;
    }
    // 0x8003EFEC: andi        $t2, $v0, 0x3
    ctx->r10 = ctx->r2 & 0X3;
    // 0x8003EFF0: beq         $t2, $zero, L_8003EFFC
    if (ctx->r10 == 0) {
        // 0x8003EFF4: nop
    
            goto L_8003EFFC;
    }
    // 0x8003EFF4: nop

    // 0x8003EFF8: addiu       $t2, $t2, -0x4
    ctx->r10 = ADD32(ctx->r10, -0X4);
L_8003EFFC:
    // 0x8003EFFC: bne         $t2, $zero, L_8003F218
    if (ctx->r10 != 0) {
        // 0x8003F000: nop
    
            goto L_8003F218;
    }
    // 0x8003F000: nop

    // 0x8003F004: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003F008: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8003F00C: beq         $at, $zero, L_8003F0C4
    if (ctx->r1 == 0) {
        // 0x8003F010: nop
    
            goto L_8003F0C4;
    }
    // 0x8003F010: nop

L_8003F014:
    // 0x8003F014: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003F018: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8003F01C: beq         $at, $zero, L_8003F0AC
    if (ctx->r1 == 0) {
        // 0x8003F020: nop
    
            goto L_8003F0AC;
    }
    // 0x8003F020: nop

L_8003F024:
    // 0x8003F024: lbu         $t3, 0x1($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X1);
    // 0x8003F028: lbu         $t6, 0x0($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X0);
    // 0x8003F02C: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x8003F030: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8003F034: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8003F038: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8003F03C: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x8003F040: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x8003F044: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003F048: lw          $t0, 0x1F30($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F30);
    // 0x8003F04C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8003F050: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x8003F054: addu        $s6, $t0, $t8
    ctx->r22 = ADD32(ctx->r8, ctx->r24);
    // 0x8003F058: lbu         $t1, 0x0($s6)
    ctx->r9 = MEM_BU(ctx->r22, 0X0);
    // 0x8003F05C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8003F060: bne         $t1, $at, L_8003F080
    if (ctx->r9 != ctx->r1) {
        // 0x8003F064: nop
    
            goto L_8003F080;
    }
    // 0x8003F064: nop

    // 0x8003F068: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x8003F06C: addu        $t3, $t6, $s3
    ctx->r11 = ADD32(ctx->r14, ctx->r19);
    // 0x8003F070: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x8003F074: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8003F078: b           L_8003F094
    // 0x8003F07C: sb          $t2, 0x40($t4)
    MEM_B(0X40, ctx->r12) = ctx->r10;
        goto L_8003F094;
    // 0x8003F07C: sb          $t2, 0x40($t4)
    MEM_B(0X40, ctx->r12) = ctx->r10;
L_8003F080:
    // 0x8003F080: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    // 0x8003F084: lbu         $t7, 0x1($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X1);
    // 0x8003F088: addu        $t9, $t5, $s3
    ctx->r25 = ADD32(ctx->r13, ctx->r19);
    // 0x8003F08C: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x8003F090: sb          $t7, 0x40($t0)
    MEM_B(0X40, ctx->r8) = ctx->r15;
L_8003F094:
    // 0x8003F094: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F098: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x8003F09C: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x8003F0A0: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8003F0A4: bne         $at, $zero, L_8003F024
    if (ctx->r1 != 0) {
        // 0x8003F0A8: nop
    
            goto L_8003F024;
    }
    // 0x8003F0A8: nop

L_8003F0AC:
    // 0x8003F0AC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003F0B0: andi        $t1, $s3, 0xFF
    ctx->r9 = ctx->r19 & 0XFF;
    // 0x8003F0B4: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x8003F0B8: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8003F0BC: bne         $at, $zero, L_8003F014
    if (ctx->r1 != 0) {
        // 0x8003F0C0: nop
    
            goto L_8003F014;
    }
    // 0x8003F0C0: nop

L_8003F0C4:
    // 0x8003F0C4: lbu         $t6, 0x56($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X56);
    // 0x8003F0C8: nop

    // 0x8003F0CC: bne         $t6, $zero, L_8003F154
    if (ctx->r14 != 0) {
        // 0x8003F0D0: nop
    
            goto L_8003F154;
    }
    // 0x8003F0D0: nop

    // 0x8003F0D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003F0D8: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x8003F0DC: beq         $at, $zero, L_8003F154
    if (ctx->r1 == 0) {
        // 0x8003F0E0: nop
    
            goto L_8003F154;
    }
    // 0x8003F0E0: nop

L_8003F0E4:
    // 0x8003F0E4: lbu         $a2, 0x57($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X57);
    // 0x8003F0E8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8003F0EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003F0F0: jal         0x8003F4F4
    // 0x8003F0F4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    aisquarelist_MatchPattern4x4(rdram, ctx);
        goto after_6;
    // 0x8003F0F4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_6:
    // 0x8003F0F8: beq         $v0, $zero, L_8003F13C
    if (ctx->r2 == 0) {
        // 0x8003F0FC: nop
    
            goto L_8003F13C;
    }
    // 0x8003F0FC: nop

    // 0x8003F100: lbu         $t3, 0x83($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X83);
    // 0x8003F104: lbu         $a2, 0x58($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X58);
    // 0x8003F108: lbu         $a3, 0x57($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X57);
    // 0x8003F10C: addiu       $t2, $sp, 0x52
    ctx->r10 = ADD32(ctx->r29, 0X52);
    // 0x8003F110: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003F114: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8003F118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003F11C: jal         0x8003E68C
    // 0x8003F120: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    aisquarelist_SearchSquaresRecursive(rdram, ctx);
        goto after_7;
    // 0x8003F120: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_7:
    // 0x8003F124: beq         $v0, $zero, L_8003F13C
    if (ctx->r2 == 0) {
        // 0x8003F128: nop
    
            goto L_8003F13C;
    }
    // 0x8003F128: nop

    // 0x8003F12C: lh          $t4, 0x52($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X52);
    // 0x8003F130: nop

    // 0x8003F134: addiu       $t5, $t4, 0x14
    ctx->r13 = ADD32(ctx->r12, 0X14);
    // 0x8003F138: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
L_8003F13C:
    // 0x8003F13C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F140: andi        $t7, $s2, 0xFF
    ctx->r15 = ctx->r18 & 0XFF;
    // 0x8003F144: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8003F148: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x8003F14C: bne         $at, $zero, L_8003F0E4
    if (ctx->r1 != 0) {
        // 0x8003F150: nop
    
            goto L_8003F0E4;
    }
    // 0x8003F150: nop

L_8003F154:
    // 0x8003F154: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003F158: slti        $at, $s2, 0x13
    ctx->r1 = SIGNED(ctx->r18) < 0X13 ? 1 : 0;
    // 0x8003F15C: beq         $at, $zero, L_8003F1EC
    if (ctx->r1 == 0) {
        // 0x8003F160: nop
    
            goto L_8003F1EC;
    }
    // 0x8003F160: nop

L_8003F164:
    // 0x8003F164: lbu         $a2, 0x57($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X57);
    // 0x8003F168: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8003F16C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003F170: jal         0x8003F4F4
    // 0x8003F174: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    aisquarelist_MatchPattern4x4(rdram, ctx);
        goto after_8;
    // 0x8003F174: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_8:
    // 0x8003F178: sb          $v0, 0x55($sp)
    MEM_B(0X55, ctx->r29) = ctx->r2;
    // 0x8003F17C: lbu         $t9, 0x55($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X55);
    // 0x8003F180: nop

    // 0x8003F184: beq         $t9, $zero, L_8003F1D4
    if (ctx->r25 == 0) {
        // 0x8003F188: nop
    
            goto L_8003F1D4;
    }
    // 0x8003F188: nop

    // 0x8003F18C: lbu         $t8, 0x83($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X83);
    // 0x8003F190: lbu         $a2, 0x58($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X58);
    // 0x8003F194: lbu         $a3, 0x57($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X57);
    // 0x8003F198: addiu       $t0, $sp, 0x52
    ctx->r8 = ADD32(ctx->r29, 0X52);
    // 0x8003F19C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003F1A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8003F1A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003F1A8: jal         0x8003E68C
    // 0x8003F1AC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    aisquarelist_SearchSquaresRecursive(rdram, ctx);
        goto after_9;
    // 0x8003F1AC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_9:
    // 0x8003F1B0: beq         $v0, $zero, L_8003F1D4
    if (ctx->r2 == 0) {
        // 0x8003F1B4: nop
    
            goto L_8003F1D4;
    }
    // 0x8003F1B4: nop

    // 0x8003F1B8: lbu         $t6, 0x55($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X55);
    // 0x8003F1BC: lh          $t1, 0x52($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X52);
    // 0x8003F1C0: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8003F1C4: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8003F1C8: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8003F1CC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8003F1D0: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
L_8003F1D4:
    // 0x8003F1D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F1D8: andi        $t4, $s2, 0xFF
    ctx->r12 = ctx->r18 & 0XFF;
    // 0x8003F1DC: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
    // 0x8003F1E0: slti        $at, $s2, 0x13
    ctx->r1 = SIGNED(ctx->r18) < 0X13 ? 1 : 0;
    // 0x8003F1E4: bne         $at, $zero, L_8003F164
    if (ctx->r1 != 0) {
        // 0x8003F1E8: nop
    
            goto L_8003F164;
    }
    // 0x8003F1E8: nop

L_8003F1EC:
    // 0x8003F1EC: lh          $t5, 0x52($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X52);
    // 0x8003F1F0: nop

    // 0x8003F1F4: beq         $t5, $zero, L_8003F218
    if (ctx->r13 == 0) {
        // 0x8003F1F8: nop
    
            goto L_8003F218;
    }
    // 0x8003F1F8: nop

    // 0x8003F1FC: lbu         $t7, 0x58($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X58);
    // 0x8003F200: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8003F204: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8003F208: lbu         $t9, 0x55A0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X55A0);
    // 0x8003F20C: nop

    // 0x8003F210: addu        $t0, $t5, $t9
    ctx->r8 = ADD32(ctx->r13, ctx->r25);
    // 0x8003F214: sh          $t0, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r8;
L_8003F218:
    // 0x8003F218: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x8003F21C: nop

    // 0x8003F220: beq         $t8, $zero, L_8003F27C
    if (ctx->r24 == 0) {
        // 0x8003F224: nop
    
            goto L_8003F27C;
    }
    // 0x8003F224: nop

    // 0x8003F228: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8003F22C: lw          $t6, 0x1F40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F40);
    // 0x8003F230: lbu         $t3, 0x5B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003F234: lw          $t1, 0x0($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X0);
    // 0x8003F238: sll         $t2, $s0, 3
    ctx->r10 = S32(ctx->r16 << 3);
    // 0x8003F23C: addu        $s5, $t1, $t2
    ctx->r21 = ADD32(ctx->r9, ctx->r10);
    // 0x8003F240: sb          $t3, 0x2($s5)
    MEM_B(0X2, ctx->r21) = ctx->r11;
    // 0x8003F244: lbu         $t4, 0x5A($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X5A);
    // 0x8003F248: addiu       $a0, $s5, 0x5
    ctx->r4 = ADD32(ctx->r21, 0X5);
    // 0x8003F24C: sb          $t4, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r12;
    // 0x8003F250: lbu         $t7, 0x59($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X59);
    // 0x8003F254: addiu       $a3, $s5, 0x6
    ctx->r7 = ADD32(ctx->r21, 0X6);
    // 0x8003F258: sb          $t7, 0x4($s5)
    MEM_B(0X4, ctx->r21) = ctx->r15;
    // 0x8003F25C: lh          $t5, 0x52($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X52);
    // 0x8003F260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003F264: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003F268: jal         0x80040784
    // 0x8003F26C: sh          $t5, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r13;
    aisquarelist_GetPieceBounds(rdram, ctx);
        goto after_10;
    // 0x8003F26C: sh          $t5, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r13;
    after_10:
    // 0x8003F270: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003F274: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x8003F278: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8003F27C:
    // 0x8003F27C: lbu         $a0, 0x5B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003F280: lbu         $a1, 0x5A($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X5A);
    // 0x8003F284: lbu         $a2, 0x59($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X59);
    // 0x8003F288: jal         0x800413C0
    // 0x8003F28C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_11;
    // 0x8003F28C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_11:
L_8003F290:
    // 0x8003F290: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8003F294: lw          $t8, 0x1F20($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F20);
    // 0x8003F298: lbu         $t6, 0x7F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7F);
    // 0x8003F29C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003F2A0: addu        $t1, $t8, $t6
    ctx->r9 = ADD32(ctx->r24, ctx->r14);
    // 0x8003F2A4: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x8003F2A8: andi        $t0, $s1, 0xFF
    ctx->r8 = ctx->r17 & 0XFF;
    // 0x8003F2AC: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x8003F2B0: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003F2B4: bne         $at, $zero, L_8003EDC0
    if (ctx->r1 != 0) {
        // 0x8003F2B8: nop
    
            goto L_8003EDC0;
    }
    // 0x8003F2B8: nop

L_8003F2BC:
    // 0x8003F2BC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8003F2C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003F2C4: sb          $s0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r16;
L_8003F2C8:
    // 0x8003F2C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003F2CC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003F2D0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003F2D4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8003F2D8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8003F2DC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F2E0: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8003F2E4: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x8003F2E8: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8003F2EC: jr          $ra
    // 0x8003F2F0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8003F2F0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8003F2F4: nop

    // 0x8003F2F8: nop

    // 0x8003F2FC: nop

;}

RECOMP_FUNC void aisquarelist_FloodFillRegion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F300: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003F304: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8003F308: lbu         $t6, 0x57($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X57);
    // 0x8003F30C: lbu         $t8, 0x5B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003F310: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8003F314: lbu         $t0, 0x4F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4F);
    // 0x8003F318: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8003F31C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8003F320: addiu       $s2, $t6, 0x3
    ctx->r18 = ADD32(ctx->r14, 0X3);
    // 0x8003F324: addiu       $s3, $t8, 0x3
    ctx->r19 = ADD32(ctx->r24, 0X3);
    // 0x8003F328: andi        $t7, $s2, 0xFF
    ctx->r15 = ctx->r18 & 0XFF;
    // 0x8003F32C: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x8003F330: slt         $at, $t0, $t6
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003F334: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003F338: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8003F33C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8003F340: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8003F344: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8003F348: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8003F34C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8003F350: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003F354: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8003F358: bne         $at, $zero, L_8003F388
    if (ctx->r1 != 0) {
        // 0x8003F35C: or          $s3, $t9, $zero
        ctx->r19 = ctx->r25 | 0;
            goto L_8003F388;
    }
    // 0x8003F35C: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x8003F360: slt         $at, $s2, $t0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8003F364: bne         $at, $zero, L_8003F388
    if (ctx->r1 != 0) {
        // 0x8003F368: nop
    
            goto L_8003F388;
    }
    // 0x8003F368: nop

    // 0x8003F36C: lbu         $t1, 0x53($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X53);
    // 0x8003F370: nop

    // 0x8003F374: slt         $at, $t1, $t8
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003F378: bne         $at, $zero, L_8003F388
    if (ctx->r1 != 0) {
        // 0x8003F37C: slt         $at, $s3, $t1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8003F388;
    }
    // 0x8003F37C: slt         $at, $s3, $t1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8003F380: beq         $at, $zero, L_8003F390
    if (ctx->r1 == 0) {
        // 0x8003F384: nop
    
            goto L_8003F390;
    }
    // 0x8003F384: nop

L_8003F388:
    // 0x8003F388: b           L_8003F4CC
    // 0x8003F38C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003F4CC;
    // 0x8003F38C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003F390:
    // 0x8003F390: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x8003F394: lbu         $t3, 0x57($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X57);
    // 0x8003F398: lbu         $t5, 0x53($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X53);
    // 0x8003F39C: lbu         $t7, 0x5B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003F3A0: subu        $s0, $t2, $t3
    ctx->r16 = SUB32(ctx->r10, ctx->r11);
    // 0x8003F3A4: andi        $t4, $s0, 0xFF
    ctx->r12 = ctx->r16 & 0XFF;
    // 0x8003F3A8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8003F3AC: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x8003F3B0: subu        $s1, $t5, $t7
    ctx->r17 = SUB32(ctx->r13, ctx->r15);
    // 0x8003F3B4: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
    // 0x8003F3B8: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x8003F3BC: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8003F3C0: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x8003F3C4: addu        $t1, $t8, $s1
    ctx->r9 = ADD32(ctx->r24, ctx->r17);
    // 0x8003F3C8: lb          $t3, 0x0($t1)
    ctx->r11 = MEM_B(ctx->r9, 0X0);
    // 0x8003F3CC: nop

    // 0x8003F3D0: bne         $t3, $zero, L_8003F4C8
    if (ctx->r11 != 0) {
        // 0x8003F3D4: nop
    
            goto L_8003F4C8;
    }
    // 0x8003F3D4: nop

    // 0x8003F3D8: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8003F3DC: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8003F3E0: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8003F3E4: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x8003F3E8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003F3EC: lw          $t0, 0x1F30($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F30);
    // 0x8003F3F0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8003F3F4: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8003F3F8: addu        $t8, $t0, $t9
    ctx->r24 = ADD32(ctx->r8, ctx->r25);
    // 0x8003F3FC: lbu         $t1, 0x0($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X0);
    // 0x8003F400: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8003F404: bne         $t1, $at, L_8003F4C8
    if (ctx->r9 != ctx->r1) {
        // 0x8003F408: nop
    
            goto L_8003F4C8;
    }
    // 0x8003F408: nop

    // 0x8003F40C: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8003F410: addu        $t2, $t6, $t5
    ctx->r10 = ADD32(ctx->r14, ctx->r13);
    // 0x8003F414: addu        $t4, $t2, $s1
    ctx->r12 = ADD32(ctx->r10, ctx->r17);
    // 0x8003F418: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003F41C: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
    // 0x8003F420: lbu         $t7, 0x5B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003F424: lbu         $a2, 0x53($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X53);
    // 0x8003F428: lbu         $a3, 0x57($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X57);
    // 0x8003F42C: lbu         $a1, 0x4F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X4F);
    // 0x8003F430: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8003F434: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003F438: jal         0x8003F300
    // 0x8003F43C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    aisquarelist_FloodFillRegion(rdram, ctx);
        goto after_0;
    // 0x8003F43C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x8003F440: lbu         $a1, 0x4F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X4F);
    // 0x8003F444: lbu         $t0, 0x5B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003F448: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8003F44C: lbu         $a2, 0x53($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X53);
    // 0x8003F450: lbu         $a3, 0x57($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X57);
    // 0x8003F454: andi        $s6, $v0, 0xFF
    ctx->r22 = ctx->r2 & 0XFF;
    // 0x8003F458: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003F45C: jal         0x8003F300
    // 0x8003F460: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    aisquarelist_FloodFillRegion(rdram, ctx);
        goto after_1;
    // 0x8003F460: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x8003F464: lbu         $a1, 0x4F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X4F);
    // 0x8003F468: lbu         $t9, 0x5B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003F46C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8003F470: lbu         $a2, 0x53($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X53);
    // 0x8003F474: lbu         $a3, 0x57($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X57);
    // 0x8003F478: andi        $s5, $v0, 0xFF
    ctx->r21 = ctx->r2 & 0XFF;
    // 0x8003F47C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8003F480: jal         0x8003F300
    // 0x8003F484: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    aisquarelist_FloodFillRegion(rdram, ctx);
        goto after_2;
    // 0x8003F484: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_2:
    // 0x8003F488: lbu         $a2, 0x53($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X53);
    // 0x8003F48C: lbu         $t8, 0x5B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003F490: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8003F494: lbu         $a1, 0x4F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X4F);
    // 0x8003F498: lbu         $a3, 0x57($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X57);
    // 0x8003F49C: andi        $s4, $v0, 0xFF
    ctx->r20 = ctx->r2 & 0XFF;
    // 0x8003F4A0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8003F4A4: jal         0x8003F300
    // 0x8003F4A8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    aisquarelist_FloodFillRegion(rdram, ctx);
        goto after_3;
    // 0x8003F4A8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_3:
    // 0x8003F4AC: addu        $t1, $s4, $s5
    ctx->r9 = ADD32(ctx->r20, ctx->r21);
    // 0x8003F4B0: addu        $t6, $t1, $s6
    ctx->r14 = ADD32(ctx->r9, ctx->r22);
    // 0x8003F4B4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8003F4B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003F4BC: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x8003F4C0: b           L_8003F4CC
    // 0x8003F4C4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_8003F4CC;
    // 0x8003F4C4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8003F4C8:
    // 0x8003F4C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003F4CC:
    // 0x8003F4CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003F4D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003F4D4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003F4D8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8003F4DC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F4E0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8003F4E4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8003F4E8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8003F4EC: jr          $ra
    // 0x8003F4F0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8003F4F0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void aisquarelist_MatchPattern4x4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F4F4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003F4F8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8003F4FC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8003F500: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8003F504: bne         $a1, $zero, L_8003F5D8
    if (ctx->r5 != 0) {
        // 0x8003F508: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_8003F5D8;
    }
    // 0x8003F508: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8003F50C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8003F510: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x8003F514: lbu         $t6, 0x55B0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X55B0);
    // 0x8003F518: nop

    // 0x8003F51C: bne         $t6, $a2, L_8003F714
    if (ctx->r14 != ctx->r6) {
        // 0x8003F520: nop
    
            goto L_8003F714;
    }
    // 0x8003F520: nop

    // 0x8003F524: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8003F528: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x8003F52C: beq         $at, $zero, L_8003F5D0
    if (ctx->r1 == 0) {
        // 0x8003F530: nop
    
            goto L_8003F5D0;
    }
    // 0x8003F530: nop

L_8003F534:
    // 0x8003F534: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8003F538: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8003F53C: beq         $at, $zero, L_8003F5B8
    if (ctx->r1 == 0) {
        // 0x8003F540: nop
    
            goto L_8003F5B8;
    }
    // 0x8003F540: nop

L_8003F544:
    // 0x8003F544: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8003F548: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8003F54C: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8003F550: lb          $t5, 0x0($t9)
    ctx->r13 = MEM_B(ctx->r25, 0X0);
    // 0x8003F554: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003F558: beq         $t5, $at, L_8003F5A0
    if (ctx->r13 == ctx->r1) {
        // 0x8003F55C: nop
    
            goto L_8003F5A0;
    }
    // 0x8003F55C: nop

    // 0x8003F560: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x8003F564: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8003F568: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8003F56C: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x8003F570: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8003F574: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8003F578: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8003F57C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8003F580: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8003F584: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x8003F588: lb          $t5, 0x55F4($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X55F4);
    // 0x8003F58C: nop

    // 0x8003F590: beq         $t5, $t9, L_8003F5A0
    if (ctx->r13 == ctx->r25) {
        // 0x8003F594: nop
    
            goto L_8003F5A0;
    }
    // 0x8003F594: nop

    // 0x8003F598: b           L_8003F718
    // 0x8003F59C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_8003F718;
    // 0x8003F59C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_8003F5A0:
    // 0x8003F5A0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8003F5A4: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x8003F5A8: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8003F5AC: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8003F5B0: bne         $at, $zero, L_8003F544
    if (ctx->r1 != 0) {
        // 0x8003F5B4: nop
    
            goto L_8003F544;
    }
    // 0x8003F5B4: nop

L_8003F5B8:
    // 0x8003F5B8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8003F5BC: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x8003F5C0: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x8003F5C4: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x8003F5C8: bne         $at, $zero, L_8003F534
    if (ctx->r1 != 0) {
        // 0x8003F5CC: nop
    
            goto L_8003F534;
    }
    // 0x8003F5CC: nop

L_8003F5D0:
    // 0x8003F5D0: b           L_8003F714
    // 0x8003F5D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8003F714;
    // 0x8003F5D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8003F5D8:
    // 0x8003F5D8: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8003F5DC: addu        $t8, $t8, $a3
    ctx->r24 = ADD32(ctx->r24, ctx->r7);
    // 0x8003F5E0: lbu         $t8, 0x55B8($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X55B8);
    // 0x8003F5E4: nop

    // 0x8003F5E8: and         $t5, $t8, $a2
    ctx->r13 = ctx->r24 & ctx->r6;
    // 0x8003F5EC: beq         $t5, $zero, L_8003F714
    if (ctx->r13 == 0) {
        // 0x8003F5F0: nop
    
            goto L_8003F714;
    }
    // 0x8003F5F0: nop

    // 0x8003F5F4: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8003F5F8: addiu       $t6, $t6, 0x55CC
    ctx->r14 = ADD32(ctx->r14, 0X55CC);
    // 0x8003F5FC: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x8003F600: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8003F604: sll         $t8, $a3, 1
    ctx->r24 = S32(ctx->r7 << 1);
    // 0x8003F608: addu        $t5, $t8, $t6
    ctx->r13 = ADD32(ctx->r24, ctx->r14);
    // 0x8003F60C: lbu         $t9, 0x1($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X1);
    // 0x8003F610: lbu         $t0, 0x0($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X0);
    // 0x8003F614: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8003F618: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8003F61C: bne         $at, $zero, L_8003F714
    if (ctx->r1 != 0) {
        // 0x8003F620: nop
    
            goto L_8003F714;
    }
    // 0x8003F620: nop

L_8003F624:
    // 0x8003F624: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8003F628: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x8003F62C: beq         $at, $zero, L_8003F6D8
    if (ctx->r1 == 0) {
        // 0x8003F630: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8003F6D8;
    }
    // 0x8003F630: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8003F634:
    // 0x8003F634: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8003F638: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8003F63C: beq         $at, $zero, L_8003F6B8
    if (ctx->r1 == 0) {
        // 0x8003F640: nop
    
            goto L_8003F6B8;
    }
    // 0x8003F640: nop

L_8003F644:
    // 0x8003F644: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8003F648: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8003F64C: addu        $t6, $t8, $t2
    ctx->r14 = ADD32(ctx->r24, ctx->r10);
    // 0x8003F650: lb          $t5, 0x0($t6)
    ctx->r13 = MEM_B(ctx->r14, 0X0);
    // 0x8003F654: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003F658: beq         $t5, $at, L_8003F6A0
    if (ctx->r13 == ctx->r1) {
        // 0x8003F65C: nop
    
            goto L_8003F6A0;
    }
    // 0x8003F65C: nop

    // 0x8003F660: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x8003F664: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8003F668: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8003F66C: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x8003F670: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8003F674: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8003F678: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8003F67C: addu        $t7, $a0, $t9
    ctx->r15 = ADD32(ctx->r4, ctx->r25);
    // 0x8003F680: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8003F684: lb          $t6, 0x0($t8)
    ctx->r14 = MEM_B(ctx->r24, 0X0);
    // 0x8003F688: lb          $t5, 0x5644($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X5644);
    // 0x8003F68C: nop

    // 0x8003F690: beq         $t5, $t6, L_8003F6A0
    if (ctx->r13 == ctx->r14) {
        // 0x8003F694: nop
    
            goto L_8003F6A0;
    }
    // 0x8003F694: nop

    // 0x8003F698: b           L_8003F6B8
    // 0x8003F69C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
        goto L_8003F6B8;
    // 0x8003F69C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_8003F6A0:
    // 0x8003F6A0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8003F6A4: andi        $t9, $t1, 0xFF
    ctx->r25 = ctx->r9 & 0XFF;
    // 0x8003F6A8: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8003F6AC: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8003F6B0: bne         $at, $zero, L_8003F644
    if (ctx->r1 != 0) {
        // 0x8003F6B4: nop
    
            goto L_8003F644;
    }
    // 0x8003F6B4: nop

L_8003F6B8:
    // 0x8003F6B8: beq         $t3, $zero, L_8003F6D8
    if (ctx->r11 == 0) {
        // 0x8003F6BC: nop
    
            goto L_8003F6D8;
    }
    // 0x8003F6BC: nop

    // 0x8003F6C0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8003F6C4: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x8003F6C8: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x8003F6CC: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x8003F6D0: bne         $at, $zero, L_8003F634
    if (ctx->r1 != 0) {
        // 0x8003F6D4: nop
    
            goto L_8003F634;
    }
    // 0x8003F6D4: nop

L_8003F6D8:
    // 0x8003F6D8: beq         $t3, $zero, L_8003F6EC
    if (ctx->r11 == 0) {
        // 0x8003F6DC: nop
    
            goto L_8003F6EC;
    }
    // 0x8003F6DC: nop

    // 0x8003F6E0: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8003F6E4: andi        $t8, $t4, 0xFF
    ctx->r24 = ctx->r12 & 0XFF;
    // 0x8003F6E8: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
L_8003F6EC:
    // 0x8003F6EC: sll         $t6, $a3, 1
    ctx->r14 = S32(ctx->r7 << 1);
    // 0x8003F6F0: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8003F6F4: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8003F6F8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8003F6FC: lbu         $t9, 0x55CD($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X55CD);
    // 0x8003F700: andi        $t5, $t0, 0xFF
    ctx->r13 = ctx->r8 & 0XFF;
    // 0x8003F704: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8003F708: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8003F70C: beq         $at, $zero, L_8003F624
    if (ctx->r1 == 0) {
        // 0x8003F710: nop
    
            goto L_8003F624;
    }
    // 0x8003F710: nop

L_8003F714:
    // 0x8003F714: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_8003F718:
    // 0x8003F718: jr          $ra
    // 0x8003F71C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8003F71C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void aisquarelist_SetMoveEntryFields(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F720: lb          $t6, 0x0($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X0);
    // 0x8003F724: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x8003F728: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8003F72C: addu        $t0, $a0, $t7
    ctx->r8 = ADD32(ctx->r4, ctx->r15);
    // 0x8003F730: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x8003F734: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003F738: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8003F73C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8003F740: sb          $a1, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r5;
    // 0x8003F744: sb          $a2, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r6;
    // 0x8003F748: sb          $a3, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r7;
    // 0x8003F74C: lbu         $t8, 0x1B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1B);
    // 0x8003F750: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8003F754: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8003F758: jr          $ra
    // 0x8003F75C: sb          $t8, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r24;
    return;
    // 0x8003F75C: sb          $t8, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r24;
;}

RECOMP_FUNC void aisquarelist_ResetMoveList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F760: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003F764: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003F768: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8003F76C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003F770: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003F774: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8003F778: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8003F77C: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8003F780: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x8003F784: lbu         $a3, 0x2F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2F);
    // 0x8003F788: lb          $a2, 0x2B($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X2B);
    // 0x8003F78C: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8003F790: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003F794: jal         0x8003F720
    // 0x8003F798: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    aisquarelist_SetMoveEntryFields(rdram, ctx);
        goto after_0;
    // 0x8003F798: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8003F79C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003F7A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003F7A4: jr          $ra
    // 0x8003F7A8: nop

    return;
    // 0x8003F7A8: nop

;}

RECOMP_FUNC void aisquarelist_ExploreMovesRecursive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F7AC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003F7B0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8003F7B4: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8003F7B8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003F7BC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8003F7C0: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8003F7C4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8003F7C8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8003F7CC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8003F7D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8003F7D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003F7D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003F7DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003F7E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003F7E4: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x8003F7E8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8003F7EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003F7F0: addu        $s5, $t6, $t8
    ctx->r21 = ADD32(ctx->r14, ctx->r24);
    // 0x8003F7F4: lbu         $t9, 0x1($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X1);
    // 0x8003F7F8: lw          $t0, -0x490($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X490);
    // 0x8003F7FC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8003F800: sb          $t9, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r25;
    // 0x8003F804: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x8003F808: lb          $t1, 0x2($s5)
    ctx->r9 = MEM_B(ctx->r21, 0X2);
    // 0x8003F80C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8003F810: sb          $t1, 0x12($t2)
    MEM_B(0X12, ctx->r10) = ctx->r9;
    // 0x8003F814: lw          $t4, -0x490($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X490);
    // 0x8003F818: lbu         $t3, 0x3($s5)
    ctx->r11 = MEM_BU(ctx->r21, 0X3);
    // 0x8003F81C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003F820: sb          $t3, 0xA($t4)
    MEM_B(0XA, ctx->r12) = ctx->r11;
    // 0x8003F824: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8003F828: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8003F82C: lb          $t7, 0x0($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X0);
    // 0x8003F830: addiu       $s5, $t5, 0x1
    ctx->r21 = ADD32(ctx->r13, 0X1);
    // 0x8003F834: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8003F838: beq         $at, $zero, L_8003F8AC
    if (ctx->r1 == 0) {
        // 0x8003F83C: nop
    
            goto L_8003F8AC;
    }
    // 0x8003F83C: nop

L_8003F840:
    // 0x8003F840: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8003F844: lw          $t6, -0x490($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X490);
    // 0x8003F848: lbu         $t9, 0x0($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X0);
    // 0x8003F84C: lb          $t8, 0x11($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X11);
    // 0x8003F850: nop

    // 0x8003F854: bne         $t8, $t9, L_8003F88C
    if (ctx->r24 != ctx->r25) {
        // 0x8003F858: nop
    
            goto L_8003F88C;
    }
    // 0x8003F858: nop

    // 0x8003F85C: lb          $t0, 0x12($t6)
    ctx->r8 = MEM_B(ctx->r14, 0X12);
    // 0x8003F860: lb          $t1, 0x1($s5)
    ctx->r9 = MEM_B(ctx->r21, 0X1);
    // 0x8003F864: nop

    // 0x8003F868: bne         $t0, $t1, L_8003F88C
    if (ctx->r8 != ctx->r9) {
        // 0x8003F86C: nop
    
            goto L_8003F88C;
    }
    // 0x8003F86C: nop

    // 0x8003F870: lbu         $t2, 0xA($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0XA);
    // 0x8003F874: lbu         $t3, 0x2($s5)
    ctx->r11 = MEM_BU(ctx->r21, 0X2);
    // 0x8003F878: nop

    // 0x8003F87C: bne         $t2, $t3, L_8003F88C
    if (ctx->r10 != ctx->r11) {
        // 0x8003F880: nop
    
            goto L_8003F88C;
    }
    // 0x8003F880: nop

    // 0x8003F884: b           L_800400D4
    // 0x8003F888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800400D4;
    // 0x8003F888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003F88C:
    // 0x8003F88C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8003F890: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003F894: lb          $t7, 0x0($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X0);
    // 0x8003F898: andi        $t4, $s1, 0xFF
    ctx->r12 = ctx->r17 & 0XFF;
    // 0x8003F89C: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x8003F8A0: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8003F8A4: bne         $at, $zero, L_8003F840
    if (ctx->r1 != 0) {
        // 0x8003F8A8: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8003F840;
    }
    // 0x8003F8A8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8003F8AC:
    // 0x8003F8AC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8003F8B0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8003F8B4: lw          $t1, -0x490($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X490);
    // 0x8003F8B8: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x8003F8BC: lb          $a0, 0x12($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X12);
    // 0x8003F8C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8003F8C4: addu        $s5, $t8, $t0
    ctx->r21 = ADD32(ctx->r24, ctx->r8);
    // 0x8003F8C8: lbu         $a1, 0xA($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0XA);
    // 0x8003F8CC: lbu         $a2, 0x13($t1)
    ctx->r6 = MEM_BU(ctx->r9, 0X13);
    // 0x8003F8D0: jal         0x800408B0
    // 0x8003F8D4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    aisquarelist_CellBelongsToSquare(rdram, ctx);
        goto after_0;
    // 0x8003F8D4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    after_0:
    // 0x8003F8D8: lbu         $t6, 0x57($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X57);
    // 0x8003F8DC: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x8003F8E0: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8003F8E4: beq         $at, $zero, L_8003FA9C
    if (ctx->r1 == 0) {
        // 0x8003F8E8: nop
    
            goto L_8003FA9C;
    }
    // 0x8003F8E8: nop

    // 0x8003F8EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003F8F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003F8F4: addu        $at, $at, $t6
    gpr jr_addend_8003F900 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8003F8F8: lw          $t6, -0x4BC0($at)
    ctx->r14 = ADD32(ctx->r1, -0X4BC0);
    // 0x8003F8FC: nop

    // 0x8003F900: jr          $t6
    // 0x8003F904: nop

    switch (jr_addend_8003F900 >> 2) {
        case 0: goto L_8003F908; break;
        case 1: goto L_8003F92C; break;
        case 2: goto L_8003F97C; break;
        case 3: goto L_8003F9CC; break;
        case 4: goto L_8003FA38; break;
        default: switch_error(__func__, 0x8003F900, 0x800DB440);
    }
    // 0x8003F904: nop

L_8003F908:
    // 0x8003F908: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003F90C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8003F910: jal         0x8004172C
    // 0x8003F914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_1;
    // 0x8003F914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8003F918: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x8003F91C: bne         $s1, $zero, L_8003F908
    if (ctx->r17 != 0) {
        // 0x8003F920: nop
    
            goto L_8003F908;
    }
    // 0x8003F920: nop

    // 0x8003F924: b           L_8003FA9C
    // 0x8003F928: nop

        goto L_8003FA9C;
    // 0x8003F928: nop

L_8003F92C:
    // 0x8003F92C: beq         $s0, $zero, L_8003F958
    if (ctx->r16 == 0) {
        // 0x8003F930: nop
    
            goto L_8003F958;
    }
    // 0x8003F930: nop

    // 0x8003F934: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8003F938: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x8003F93C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003F940: lb          $t3, 0x11($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X11);
    // 0x8003F944: nop

    // 0x8003F948: bne         $t3, $at, L_8003F958
    if (ctx->r11 != ctx->r1) {
        // 0x8003F94C: nop
    
            goto L_8003F958;
    }
    // 0x8003F94C: nop

    // 0x8003F950: b           L_8003F96C
    // 0x8003F954: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_8003F96C;
    // 0x8003F954: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8003F958:
    // 0x8003F958: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8003F95C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003F960: jal         0x8004172C
    // 0x8003F964: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_2;
    // 0x8003F964: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8003F968: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
L_8003F96C:
    // 0x8003F96C: bne         $s1, $zero, L_8003F92C
    if (ctx->r17 != 0) {
        // 0x8003F970: nop
    
            goto L_8003F92C;
    }
    // 0x8003F970: nop

    // 0x8003F974: b           L_8003FA9C
    // 0x8003F978: nop

        goto L_8003FA9C;
    // 0x8003F978: nop

L_8003F97C:
    // 0x8003F97C: beq         $s0, $zero, L_8003F9A8
    if (ctx->r16 == 0) {
        // 0x8003F980: nop
    
            goto L_8003F9A8;
    }
    // 0x8003F980: nop

    // 0x8003F984: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8003F988: lw          $t4, -0x490($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X490);
    // 0x8003F98C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003F990: lb          $t5, 0x11($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X11);
    // 0x8003F994: nop

    // 0x8003F998: bne         $t5, $at, L_8003F9A8
    if (ctx->r13 != ctx->r1) {
        // 0x8003F99C: nop
    
            goto L_8003F9A8;
    }
    // 0x8003F99C: nop

    // 0x8003F9A0: b           L_8003F9BC
    // 0x8003F9A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_8003F9BC;
    // 0x8003F9A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8003F9A8:
    // 0x8003F9A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003F9AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003F9B0: jal         0x8004172C
    // 0x8003F9B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_3;
    // 0x8003F9B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8003F9B8: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
L_8003F9BC:
    // 0x8003F9BC: bne         $s1, $zero, L_8003F97C
    if (ctx->r17 != 0) {
        // 0x8003F9C0: nop
    
            goto L_8003F97C;
    }
    // 0x8003F9C0: nop

    // 0x8003F9C4: b           L_8003FA9C
    // 0x8003F9C8: nop

        goto L_8003FA9C;
    // 0x8003F9C8: nop

L_8003F9CC:
    // 0x8003F9CC: beq         $s0, $zero, L_8003F9F8
    if (ctx->r16 == 0) {
        // 0x8003F9D0: nop
    
            goto L_8003F9F8;
    }
    // 0x8003F9D0: nop

    // 0x8003F9D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8003F9D8: lw          $t7, -0x490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X490);
    // 0x8003F9DC: lbu         $t8, 0x5B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003F9E0: lbu         $t9, 0xA($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0XA);
    // 0x8003F9E4: nop

    // 0x8003F9E8: bne         $t9, $t8, L_8003F9F8
    if (ctx->r25 != ctx->r24) {
        // 0x8003F9EC: nop
    
            goto L_8003F9F8;
    }
    // 0x8003F9EC: nop

    // 0x8003F9F0: b           L_8003FA28
    // 0x8003F9F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_8003FA28;
    // 0x8003F9F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8003F9F8:
    // 0x8003F9F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003F9FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003FA00: jal         0x8004172C
    // 0x8003FA04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_4;
    // 0x8003FA04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8003FA08: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8003FA0C: lw          $t0, -0x490($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X490);
    // 0x8003FA10: lbu         $t6, 0x2($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X2);
    // 0x8003FA14: lbu         $t1, 0xA($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XA);
    // 0x8003FA18: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x8003FA1C: bne         $t1, $t6, L_8003FA28
    if (ctx->r9 != ctx->r14) {
        // 0x8003FA20: nop
    
            goto L_8003FA28;
    }
    // 0x8003FA20: nop

    // 0x8003FA24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8003FA28:
    // 0x8003FA28: bne         $s1, $zero, L_8003F9CC
    if (ctx->r17 != 0) {
        // 0x8003FA2C: nop
    
            goto L_8003F9CC;
    }
    // 0x8003FA2C: nop

    // 0x8003FA30: b           L_8003FA9C
    // 0x8003FA34: nop

        goto L_8003FA9C;
    // 0x8003FA34: nop

L_8003FA38:
    // 0x8003FA38: beq         $s0, $zero, L_8003FA64
    if (ctx->r16 == 0) {
        // 0x8003FA3C: nop
    
            goto L_8003FA64;
    }
    // 0x8003FA3C: nop

    // 0x8003FA40: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8003FA44: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x8003FA48: lbu         $t4, 0x5B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FA4C: lbu         $t3, 0xA($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XA);
    // 0x8003FA50: nop

    // 0x8003FA54: bne         $t3, $t4, L_8003FA64
    if (ctx->r11 != ctx->r12) {
        // 0x8003FA58: nop
    
            goto L_8003FA64;
    }
    // 0x8003FA58: nop

    // 0x8003FA5C: b           L_8003FA94
    // 0x8003FA60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_8003FA94;
    // 0x8003FA60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8003FA64:
    // 0x8003FA64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003FA68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003FA6C: jal         0x8004172C
    // 0x8003FA70: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_5;
    // 0x8003FA70: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_5:
    // 0x8003FA74: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8003FA78: lw          $t5, -0x490($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X490);
    // 0x8003FA7C: lbu         $t9, 0x2($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X2);
    // 0x8003FA80: lbu         $t7, 0xA($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0XA);
    // 0x8003FA84: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x8003FA88: bne         $t7, $t9, L_8003FA94
    if (ctx->r15 != ctx->r25) {
        // 0x8003FA8C: nop
    
            goto L_8003FA94;
    }
    // 0x8003FA8C: nop

    // 0x8003FA90: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8003FA94:
    // 0x8003FA94: bne         $s1, $zero, L_8003FA38
    if (ctx->r17 != 0) {
        // 0x8003FA98: nop
    
            goto L_8003FA38;
    }
    // 0x8003FA98: nop

L_8003FA9C:
    // 0x8003FA9C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8003FAA0: lw          $t8, -0x490($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X490);
    // 0x8003FAA4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003FAA8: lb          $t0, 0x11($t8)
    ctx->r8 = MEM_B(ctx->r24, 0X11);
    // 0x8003FAAC: nop

    // 0x8003FAB0: bne         $t0, $at, L_8003FAE4
    if (ctx->r8 != ctx->r1) {
        // 0x8003FAB4: nop
    
            goto L_8003FAE4;
    }
    // 0x8003FAB4: nop

    // 0x8003FAB8: lb          $t1, 0x12($t8)
    ctx->r9 = MEM_B(ctx->r24, 0X12);
    // 0x8003FABC: nop

    // 0x8003FAC0: bne         $t1, $zero, L_8003FAE4
    if (ctx->r9 != 0) {
        // 0x8003FAC4: nop
    
            goto L_8003FAE4;
    }
    // 0x8003FAC4: nop

    // 0x8003FAC8: lbu         $t6, 0xA($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0XA);
    // 0x8003FACC: lbu         $t2, 0x5B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FAD0: nop

    // 0x8003FAD4: bne         $t6, $t2, L_8003FAE4
    if (ctx->r14 != ctx->r10) {
        // 0x8003FAD8: nop
    
            goto L_8003FAE4;
    }
    // 0x8003FAD8: nop

    // 0x8003FADC: b           L_800400D4
    // 0x8003FAE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800400D4;
    // 0x8003FAE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003FAE4:
    // 0x8003FAE4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8003FAE8: lw          $t3, -0x490($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X490);
    // 0x8003FAEC: lbu         $t5, 0x0($s5)
    ctx->r13 = MEM_BU(ctx->r21, 0X0);
    // 0x8003FAF0: lb          $t4, 0x11($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X11);
    // 0x8003FAF4: nop

    // 0x8003FAF8: bne         $t4, $t5, L_8003FBA0
    if (ctx->r12 != ctx->r13) {
        // 0x8003FAFC: nop
    
            goto L_8003FBA0;
    }
    // 0x8003FAFC: nop

    // 0x8003FB00: lb          $t7, 0x12($t3)
    ctx->r15 = MEM_B(ctx->r11, 0X12);
    // 0x8003FB04: lb          $t9, 0x1($s5)
    ctx->r25 = MEM_B(ctx->r21, 0X1);
    // 0x8003FB08: nop

    // 0x8003FB0C: bne         $t7, $t9, L_8003FBA0
    if (ctx->r15 != ctx->r25) {
        // 0x8003FB10: nop
    
            goto L_8003FBA0;
    }
    // 0x8003FB10: nop

    // 0x8003FB14: lbu         $t0, 0xA($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0XA);
    // 0x8003FB18: lbu         $t1, 0x2($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X2);
    // 0x8003FB1C: nop

    // 0x8003FB20: bne         $t0, $t1, L_8003FBA0
    if (ctx->r8 != ctx->r9) {
        // 0x8003FB24: nop
    
            goto L_8003FBA0;
    }
    // 0x8003FB24: nop

    // 0x8003FB28: lbu         $s6, 0x57($sp)
    ctx->r22 = MEM_BU(ctx->r29, 0X57);
    // 0x8003FB2C: nop

    // 0x8003FB30: beq         $s6, $zero, L_8003FB50
    if (ctx->r22 == 0) {
        // 0x8003FB34: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8003FB50;
    }
    // 0x8003FB34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003FB38: beq         $s6, $at, L_8003FB74
    if (ctx->r22 == ctx->r1) {
        // 0x8003FB3C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003FB74;
    }
    // 0x8003FB3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003FB40: beq         $s6, $at, L_8003FB98
    if (ctx->r22 == ctx->r1) {
        // 0x8003FB44: nop
    
            goto L_8003FB98;
    }
    // 0x8003FB44: nop

    // 0x8003FB48: b           L_800400D0
    // 0x8003FB4C: nop

        goto L_800400D0;
    // 0x8003FB4C: nop

L_8003FB50:
    // 0x8003FB50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003FB54: sb          $t8, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r24;
    // 0x8003FB58: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FB5C: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FB60: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FB64: jal         0x8003F7AC
    // 0x8003FB68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_6;
    // 0x8003FB68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8003FB6C: b           L_800400D4
    // 0x8003FB70: nop

        goto L_800400D4;
    // 0x8003FB70: nop

L_8003FB74:
    // 0x8003FB74: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003FB78: sb          $t6, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r14;
    // 0x8003FB7C: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FB80: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FB84: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FB88: jal         0x8003F7AC
    // 0x8003FB8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_7;
    // 0x8003FB8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8003FB90: b           L_800400D4
    // 0x8003FB94: nop

        goto L_800400D4;
    // 0x8003FB94: nop

L_8003FB98:
    // 0x8003FB98: b           L_800400D4
    // 0x8003FB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800400D4;
    // 0x8003FB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003FBA0:
    // 0x8003FBA0: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8003FBA4: nop

    // 0x8003FBA8: lb          $t4, 0x0($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X0);
    // 0x8003FBAC: nop

    // 0x8003FBB0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8003FBB4: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x8003FBB8: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8003FBBC: nop

    // 0x8003FBC0: lb          $t9, 0x0($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X0);
    // 0x8003FBC4: nop

    // 0x8003FBC8: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x8003FBCC: bne         $at, $zero, L_8003FBDC
    if (ctx->r1 != 0) {
        // 0x8003FBD0: nop
    
            goto L_8003FBDC;
    }
    // 0x8003FBD0: nop

    // 0x8003FBD4: b           L_800400D4
    // 0x8003FBD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800400D4;
    // 0x8003FBD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003FBDC:
    // 0x8003FBDC: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8003FBE0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8003FBE4: lw          $t8, -0x490($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X490);
    // 0x8003FBE8: lb          $t0, 0x0($t3)
    ctx->r8 = MEM_B(ctx->r11, 0X0);
    // 0x8003FBEC: lb          $t6, 0x11($t8)
    ctx->r14 = MEM_B(ctx->r24, 0X11);
    // 0x8003FBF0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8003FBF4: addu        $s5, $t3, $t1
    ctx->r21 = ADD32(ctx->r11, ctx->r9);
    // 0x8003FBF8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8003FBFC: sb          $t6, 0x1($s5)
    MEM_B(0X1, ctx->r21) = ctx->r14;
    // 0x8003FC00: lw          $t4, -0x490($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X490);
    // 0x8003FC04: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8003FC08: lb          $t5, 0x12($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X12);
    // 0x8003FC0C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8003FC10: sb          $t5, 0x2($s5)
    MEM_B(0X2, ctx->r21) = ctx->r13;
    // 0x8003FC14: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x8003FC18: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8003FC1C: lbu         $t7, 0xA($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0XA);
    // 0x8003FC20: nop

    // 0x8003FC24: sb          $t7, 0x2($s5)
    MEM_B(0X2, ctx->r21) = ctx->r15;
    // 0x8003FC28: lw          $t9, -0x490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X490);
    // 0x8003FC2C: nop

    // 0x8003FC30: lb          $a0, 0x12($t9)
    ctx->r4 = MEM_B(ctx->r25, 0X12);
    // 0x8003FC34: lbu         $a1, 0xA($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0XA);
    // 0x8003FC38: lbu         $a2, 0x13($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X13);
    // 0x8003FC3C: jal         0x800408B0
    // 0x8003FC40: nop

    aisquarelist_CellBelongsToSquare(rdram, ctx);
        goto after_8;
    // 0x8003FC40: nop

    after_8:
    // 0x8003FC44: beq         $v0, $zero, L_8003FEBC
    if (ctx->r2 == 0) {
        // 0x8003FC48: nop
    
            goto L_8003FEBC;
    }
    // 0x8003FC48: nop

    // 0x8003FC4C: lbu         $a0, 0x5B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FC50: addiu       $a1, $sp, 0x43
    ctx->r5 = ADD32(ctx->r29, 0X43);
    // 0x8003FC54: jal         0x800406B0
    // 0x8003FC58: addiu       $a2, $sp, 0x42
    ctx->r6 = ADD32(ctx->r29, 0X42);
    aisquarelist_GetRotationSteps(rdram, ctx);
        goto after_9;
    // 0x8003FC58: addiu       $a2, $sp, 0x42
    ctx->r6 = ADD32(ctx->r29, 0X42);
    after_9:
    // 0x8003FC5C: lbu         $t0, 0x5F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FC60: nop

    // 0x8003FC64: bne         $t0, $zero, L_8003FD94
    if (ctx->r8 != 0) {
        // 0x8003FC68: nop
    
            goto L_8003FD94;
    }
    // 0x8003FC68: nop

    // 0x8003FC6C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8003FC70: lw          $t3, -0x490($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X490);
    // 0x8003FC74: nop

    // 0x8003FC78: lb          $t1, 0x11($t3)
    ctx->r9 = MEM_B(ctx->r11, 0X11);
    // 0x8003FC7C: nop

    // 0x8003FC80: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8003FC84: beq         $at, $zero, L_8003FCB0
    if (ctx->r1 == 0) {
        // 0x8003FC88: nop
    
            goto L_8003FCB0;
    }
    // 0x8003FC88: nop

    // 0x8003FC8C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8003FC90: sb          $t8, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r24;
    // 0x8003FC94: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FC98: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FC9C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FCA0: jal         0x8003F7AC
    // 0x8003FCA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_10;
    // 0x8003FCA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x8003FCA8: b           L_800400D4
    // 0x8003FCAC: nop

        goto L_800400D4;
    // 0x8003FCAC: nop

L_8003FCB0:
    // 0x8003FCB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8003FCB4: lw          $t6, -0x490($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X490);
    // 0x8003FCB8: nop

    // 0x8003FCBC: lb          $t4, 0x11($t6)
    ctx->r12 = MEM_B(ctx->r14, 0X11);
    // 0x8003FCC0: nop

    // 0x8003FCC4: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x8003FCC8: bne         $at, $zero, L_8003FCF4
    if (ctx->r1 != 0) {
        // 0x8003FCCC: nop
    
            goto L_8003FCF4;
    }
    // 0x8003FCCC: nop

    // 0x8003FCD0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003FCD4: sb          $t5, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r13;
    // 0x8003FCD8: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FCDC: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FCE0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FCE4: jal         0x8003F7AC
    // 0x8003FCE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_11;
    // 0x8003FCE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x8003FCEC: b           L_800400D4
    // 0x8003FCF0: nop

        goto L_800400D4;
    // 0x8003FCF0: nop

L_8003FCF4:
    // 0x8003FCF4: lbu         $t2, 0x43($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X43);
    // 0x8003FCF8: nop

    // 0x8003FCFC: bne         $t2, $zero, L_8003FD14
    if (ctx->r10 != 0) {
        // 0x8003FD00: nop
    
            goto L_8003FD14;
    }
    // 0x8003FD00: nop

    // 0x8003FD04: lbu         $t7, 0x42($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X42);
    // 0x8003FD08: nop

    // 0x8003FD0C: beq         $t7, $zero, L_8003FD74
    if (ctx->r15 == 0) {
        // 0x8003FD10: nop
    
            goto L_8003FD74;
    }
    // 0x8003FD10: nop

L_8003FD14:
    // 0x8003FD14: lbu         $t9, 0x43($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X43);
    // 0x8003FD18: lbu         $t0, 0x42($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X42);
    // 0x8003FD1C: nop

    // 0x8003FD20: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003FD24: bne         $at, $zero, L_8003FD50
    if (ctx->r1 != 0) {
        // 0x8003FD28: nop
    
            goto L_8003FD50;
    }
    // 0x8003FD28: nop

    // 0x8003FD2C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8003FD30: sb          $t3, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r11;
    // 0x8003FD34: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FD38: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FD3C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FD40: jal         0x8003F7AC
    // 0x8003FD44: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_12;
    // 0x8003FD44: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x8003FD48: b           L_800400D4
    // 0x8003FD4C: nop

        goto L_800400D4;
    // 0x8003FD4C: nop

L_8003FD50:
    // 0x8003FD50: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8003FD54: sb          $t1, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r9;
    // 0x8003FD58: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FD5C: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FD60: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FD64: jal         0x8003F7AC
    // 0x8003FD68: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_13;
    // 0x8003FD68: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x8003FD6C: b           L_800400D4
    // 0x8003FD70: nop

        goto L_800400D4;
    // 0x8003FD70: nop

L_8003FD74:
    // 0x8003FD74: sb          $zero, 0x3($s5)
    MEM_B(0X3, ctx->r21) = 0;
    // 0x8003FD78: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FD7C: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FD80: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FD84: jal         0x8003F7AC
    // 0x8003FD88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_14;
    // 0x8003FD88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x8003FD8C: b           L_800400D4
    // 0x8003FD90: nop

        goto L_800400D4;
    // 0x8003FD90: nop

L_8003FD94:
    // 0x8003FD94: lbu         $t8, 0x43($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X43);
    // 0x8003FD98: nop

    // 0x8003FD9C: bne         $t8, $zero, L_8003FDB4
    if (ctx->r24 != 0) {
        // 0x8003FDA0: nop
    
            goto L_8003FDB4;
    }
    // 0x8003FDA0: nop

    // 0x8003FDA4: lbu         $t6, 0x42($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X42);
    // 0x8003FDA8: nop

    // 0x8003FDAC: beq         $t6, $zero, L_8003FE14
    if (ctx->r14 == 0) {
        // 0x8003FDB0: nop
    
            goto L_8003FE14;
    }
    // 0x8003FDB0: nop

L_8003FDB4:
    // 0x8003FDB4: lbu         $t4, 0x43($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X43);
    // 0x8003FDB8: lbu         $t5, 0x42($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X42);
    // 0x8003FDBC: nop

    // 0x8003FDC0: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003FDC4: bne         $at, $zero, L_8003FDF0
    if (ctx->r1 != 0) {
        // 0x8003FDC8: nop
    
            goto L_8003FDF0;
    }
    // 0x8003FDC8: nop

    // 0x8003FDCC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8003FDD0: sb          $t2, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r10;
    // 0x8003FDD4: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FDD8: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FDDC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FDE0: jal         0x8003F7AC
    // 0x8003FDE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_15;
    // 0x8003FDE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x8003FDE8: b           L_800400D4
    // 0x8003FDEC: nop

        goto L_800400D4;
    // 0x8003FDEC: nop

L_8003FDF0:
    // 0x8003FDF0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8003FDF4: sb          $t7, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r15;
    // 0x8003FDF8: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FDFC: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FE00: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FE04: jal         0x8003F7AC
    // 0x8003FE08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_16;
    // 0x8003FE08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x8003FE0C: b           L_800400D4
    // 0x8003FE10: nop

        goto L_800400D4;
    // 0x8003FE10: nop

L_8003FE14:
    // 0x8003FE14: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8003FE18: lw          $t9, -0x490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X490);
    // 0x8003FE1C: nop

    // 0x8003FE20: lb          $t0, 0x11($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X11);
    // 0x8003FE24: nop

    // 0x8003FE28: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x8003FE2C: beq         $at, $zero, L_8003FE58
    if (ctx->r1 == 0) {
        // 0x8003FE30: nop
    
            goto L_8003FE58;
    }
    // 0x8003FE30: nop

    // 0x8003FE34: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003FE38: sb          $t3, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r11;
    // 0x8003FE3C: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FE40: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FE44: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FE48: jal         0x8003F7AC
    // 0x8003FE4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_17;
    // 0x8003FE4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x8003FE50: b           L_800400D4
    // 0x8003FE54: nop

        goto L_800400D4;
    // 0x8003FE54: nop

L_8003FE58:
    // 0x8003FE58: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8003FE5C: lw          $t1, -0x490($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X490);
    // 0x8003FE60: nop

    // 0x8003FE64: lb          $t8, 0x11($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X11);
    // 0x8003FE68: nop

    // 0x8003FE6C: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x8003FE70: bne         $at, $zero, L_8003FE9C
    if (ctx->r1 != 0) {
        // 0x8003FE74: nop
    
            goto L_8003FE9C;
    }
    // 0x8003FE74: nop

    // 0x8003FE78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003FE7C: sb          $t6, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r14;
    // 0x8003FE80: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FE84: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FE88: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FE8C: jal         0x8003F7AC
    // 0x8003FE90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_18;
    // 0x8003FE90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x8003FE94: b           L_800400D4
    // 0x8003FE98: nop

        goto L_800400D4;
    // 0x8003FE98: nop

L_8003FE9C:
    // 0x8003FE9C: sb          $zero, 0x3($s5)
    MEM_B(0X3, ctx->r21) = 0;
    // 0x8003FEA0: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FEA4: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FEA8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FEAC: jal         0x8003F7AC
    // 0x8003FEB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_19;
    // 0x8003FEB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x8003FEB4: b           L_800400D4
    // 0x8003FEB8: nop

        goto L_800400D4;
    // 0x8003FEB8: nop

L_8003FEBC:
    // 0x8003FEBC: lbu         $t4, 0x57($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X57);
    // 0x8003FEC0: nop

    // 0x8003FEC4: beq         $t4, $zero, L_8003FF30
    if (ctx->r12 == 0) {
        // 0x8003FEC8: nop
    
            goto L_8003FF30;
    }
    // 0x8003FEC8: nop

    // 0x8003FECC: sb          $zero, 0x3($s5)
    MEM_B(0X3, ctx->r21) = 0;
    // 0x8003FED0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8003FED4: lw          $t5, -0x490($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X490);
    // 0x8003FED8: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FEDC: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FEE0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FEE4: lb          $s2, 0x11($t5)
    ctx->r18 = MEM_B(ctx->r13, 0X11);
    // 0x8003FEE8: lb          $s3, 0x12($t5)
    ctx->r19 = MEM_B(ctx->r13, 0X12);
    // 0x8003FEEC: lb          $s4, 0xA($t5)
    ctx->r20 = MEM_B(ctx->r13, 0XA);
    // 0x8003FEF0: jal         0x8003F7AC
    // 0x8003FEF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_20;
    // 0x8003FEF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x8003FEF8: beq         $v0, $zero, L_8003FF08
    if (ctx->r2 == 0) {
        // 0x8003FEFC: nop
    
            goto L_8003FF08;
    }
    // 0x8003FEFC: nop

    // 0x8003FF00: b           L_800400D4
    // 0x8003FF04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800400D4;
    // 0x8003FF04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003FF08:
    // 0x8003FF08: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8003FF0C: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x8003FF10: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8003FF14: sb          $s2, 0x11($t2)
    MEM_B(0X11, ctx->r10) = ctx->r18;
    // 0x8003FF18: lw          $t7, -0x490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X490);
    // 0x8003FF1C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8003FF20: sb          $s3, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r19;
    // 0x8003FF24: lw          $t9, -0x490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X490);
    // 0x8003FF28: nop

    // 0x8003FF2C: sb          $s4, 0xA($t9)
    MEM_B(0XA, ctx->r25) = ctx->r20;
L_8003FF30:
    // 0x8003FF30: lbu         $t0, 0x57($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X57);
    // 0x8003FF34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003FF38: beq         $t0, $at, L_80040000
    if (ctx->r8 == ctx->r1) {
        // 0x8003FF3C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80040000;
    }
    // 0x8003FF3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003FF40: beq         $t0, $at, L_80040000
    if (ctx->r8 == ctx->r1) {
        // 0x8003FF44: nop
    
            goto L_80040000;
    }
    // 0x8003FF44: nop

    // 0x8003FF48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003FF4C: sb          $t3, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r11;
    // 0x8003FF50: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8003FF54: lw          $t1, -0x490($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X490);
    // 0x8003FF58: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FF5C: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FF60: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FF64: lb          $s2, 0x11($t1)
    ctx->r18 = MEM_B(ctx->r9, 0X11);
    // 0x8003FF68: lb          $s3, 0x12($t1)
    ctx->r19 = MEM_B(ctx->r9, 0X12);
    // 0x8003FF6C: lb          $s4, 0xA($t1)
    ctx->r20 = MEM_B(ctx->r9, 0XA);
    // 0x8003FF70: jal         0x8003F7AC
    // 0x8003FF74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_21;
    // 0x8003FF74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x8003FF78: beq         $v0, $zero, L_8003FF88
    if (ctx->r2 == 0) {
        // 0x8003FF7C: nop
    
            goto L_8003FF88;
    }
    // 0x8003FF7C: nop

    // 0x8003FF80: b           L_800400D4
    // 0x8003FF84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800400D4;
    // 0x8003FF84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003FF88:
    // 0x8003FF88: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8003FF8C: lw          $t8, -0x490($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X490);
    // 0x8003FF90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8003FF94: sb          $s2, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r18;
    // 0x8003FF98: lw          $t6, -0x490($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X490);
    // 0x8003FF9C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8003FFA0: sb          $s3, 0x12($t6)
    MEM_B(0X12, ctx->r14) = ctx->r19;
    // 0x8003FFA4: lw          $t4, -0x490($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X490);
    // 0x8003FFA8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8003FFAC: sb          $s4, 0xA($t4)
    MEM_B(0XA, ctx->r12) = ctx->r20;
    // 0x8003FFB0: sb          $t5, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r13;
    // 0x8003FFB4: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8003FFB8: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8003FFBC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003FFC0: jal         0x8003F7AC
    // 0x8003FFC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_22;
    // 0x8003FFC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_22:
    // 0x8003FFC8: beq         $v0, $zero, L_8003FFD8
    if (ctx->r2 == 0) {
        // 0x8003FFCC: nop
    
            goto L_8003FFD8;
    }
    // 0x8003FFCC: nop

    // 0x8003FFD0: b           L_800400D4
    // 0x8003FFD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800400D4;
    // 0x8003FFD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003FFD8:
    // 0x8003FFD8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8003FFDC: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x8003FFE0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8003FFE4: sb          $s2, 0x11($t2)
    MEM_B(0X11, ctx->r10) = ctx->r18;
    // 0x8003FFE8: lw          $t7, -0x490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X490);
    // 0x8003FFEC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8003FFF0: sb          $s3, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r19;
    // 0x8003FFF4: lw          $t9, -0x490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X490);
    // 0x8003FFF8: nop

    // 0x8003FFFC: sb          $s4, 0xA($t9)
    MEM_B(0XA, ctx->r25) = ctx->r20;
L_80040000:
    // 0x80040000: lbu         $t0, 0x57($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X57);
    // 0x80040004: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80040008: beq         $t0, $at, L_800400D0
    if (ctx->r8 == ctx->r1) {
        // 0x8004000C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800400D0;
    }
    // 0x8004000C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80040010: beq         $t0, $at, L_800400D0
    if (ctx->r8 == ctx->r1) {
        // 0x80040014: nop
    
            goto L_800400D0;
    }
    // 0x80040014: nop

    // 0x80040018: lbu         $a0, 0x5B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X5B);
    // 0x8004001C: addiu       $a1, $sp, 0x43
    ctx->r5 = ADD32(ctx->r29, 0X43);
    // 0x80040020: jal         0x800406B0
    // 0x80040024: addiu       $a2, $sp, 0x42
    ctx->r6 = ADD32(ctx->r29, 0X42);
    aisquarelist_GetRotationSteps(rdram, ctx);
        goto after_23;
    // 0x80040024: addiu       $a2, $sp, 0x42
    ctx->r6 = ADD32(ctx->r29, 0X42);
    after_23:
    // 0x80040028: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004002C: lw          $t3, -0x490($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X490);
    // 0x80040030: lbu         $t1, 0x43($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X43);
    // 0x80040034: lbu         $t8, 0x42($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X42);
    // 0x80040038: lb          $s2, 0x11($t3)
    ctx->r18 = MEM_B(ctx->r11, 0X11);
    // 0x8004003C: lb          $s3, 0x12($t3)
    ctx->r19 = MEM_B(ctx->r11, 0X12);
    // 0x80040040: lb          $s4, 0xA($t3)
    ctx->r20 = MEM_B(ctx->r11, 0XA);
    // 0x80040044: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80040048: bne         $at, $zero, L_8004007C
    if (ctx->r1 != 0) {
        // 0x8004004C: nop
    
            goto L_8004007C;
    }
    // 0x8004004C: nop

    // 0x80040050: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80040054: sb          $t6, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r14;
    // 0x80040058: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x8004005C: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x80040060: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80040064: jal         0x8003F7AC
    // 0x80040068: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_24;
    // 0x80040068: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_24:
    // 0x8004006C: beq         $v0, $zero, L_800400A8
    if (ctx->r2 == 0) {
        // 0x80040070: nop
    
            goto L_800400A8;
    }
    // 0x80040070: nop

    // 0x80040074: b           L_800400D4
    // 0x80040078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800400D4;
    // 0x80040078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004007C:
    // 0x8004007C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80040080: sb          $t4, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r12;
    // 0x80040084: lbu         $a3, 0x5F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X5F);
    // 0x80040088: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    // 0x8004008C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80040090: jal         0x8003F7AC
    // 0x80040094: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_25;
    // 0x80040094: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_25:
    // 0x80040098: beq         $v0, $zero, L_800400A8
    if (ctx->r2 == 0) {
        // 0x8004009C: nop
    
            goto L_800400A8;
    }
    // 0x8004009C: nop

    // 0x800400A0: b           L_800400D4
    // 0x800400A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800400D4;
    // 0x800400A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800400A8:
    // 0x800400A8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800400AC: lw          $t5, -0x490($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X490);
    // 0x800400B0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800400B4: sb          $s2, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r18;
    // 0x800400B8: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x800400BC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800400C0: sb          $s3, 0x12($t2)
    MEM_B(0X12, ctx->r10) = ctx->r19;
    // 0x800400C4: lw          $t7, -0x490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X490);
    // 0x800400C8: nop

    // 0x800400CC: sb          $s4, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r20;
L_800400D0:
    // 0x800400D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800400D4:
    // 0x800400D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800400D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800400DC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800400E0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800400E4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800400E8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800400EC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800400F0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800400F4: jr          $ra
    // 0x800400F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800400F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}

RECOMP_FUNC void aisquarelist_FindReachableMoves(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800400FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80040100: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80040104: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80040108: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004010C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80040110: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80040114: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80040118: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8004011C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80040120: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80040124: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80040128: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x8004012C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80040130: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80040134: addu        $s5, $t6, $t8
    ctx->r21 = ADD32(ctx->r14, ctx->r24);
    // 0x80040138: lbu         $s1, 0x1($s5)
    ctx->r17 = MEM_BU(ctx->r21, 0X1);
    // 0x8004013C: lw          $t9, -0x490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X490);
    // 0x80040140: lbu         $s2, 0x2($s5)
    ctx->r18 = MEM_BU(ctx->r21, 0X2);
    // 0x80040144: lbu         $s3, 0x3($s5)
    ctx->r19 = MEM_BU(ctx->r21, 0X3);
    // 0x80040148: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004014C: sb          $s1, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r17;
    // 0x80040150: lw          $t0, -0x490($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X490);
    // 0x80040154: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80040158: sb          $s2, 0x12($t0)
    MEM_B(0X12, ctx->r8) = ctx->r18;
    // 0x8004015C: lw          $t1, -0x490($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X490);
    // 0x80040160: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80040164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80040168: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8004016C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80040170: jal         0x80041810
    // 0x80040174: sb          $s3, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r19;
    aisquarelist_CanPieceMove(rdram, ctx);
        goto after_0;
    // 0x80040174: sb          $s3, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r19;
    after_0:
    // 0x80040178: bne         $v0, $zero, L_80040188
    if (ctx->r2 != 0) {
        // 0x8004017C: nop
    
            goto L_80040188;
    }
    // 0x8004017C: nop

    // 0x80040180: b           L_800404D8
    // 0x80040184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800404D8;
    // 0x80040184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80040188:
    // 0x80040188: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8004018C: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x80040190: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80040194: lbu         $t3, 0x13($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X13);
    // 0x80040198: nop

    // 0x8004019C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800401A0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800401A4: lw          $t5, 0x110($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X110);
    // 0x800401A8: nop

    // 0x800401AC: lbu         $s4, 0x1E($t5)
    ctx->r20 = MEM_BU(ctx->r13, 0X1E);
    // 0x800401B0: nop

L_800401B4:
    // 0x800401B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800401B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800401BC: jal         0x8004172C
    // 0x800401C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_1;
    // 0x800401C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800401C4: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800401C8: bne         $s0, $zero, L_800401B4
    if (ctx->r16 != 0) {
        // 0x800401CC: nop
    
            goto L_800401B4;
    }
    // 0x800401CC: nop

    // 0x800401D0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800401D4: lw          $t7, -0x490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X490);
    // 0x800401D8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800401DC: lb          $a0, 0x12($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X12);
    // 0x800401E0: lbu         $a2, 0x13($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X13);
    // 0x800401E4: jal         0x800408B0
    // 0x800401E8: nop

    aisquarelist_CellBelongsToSquare(rdram, ctx);
        goto after_2;
    // 0x800401E8: nop

    after_2:
    // 0x800401EC: bne         $v0, $zero, L_80040220
    if (ctx->r2 != 0) {
        // 0x800401F0: nop
    
            goto L_80040220;
    }
    // 0x800401F0: nop

    // 0x800401F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800401F8: lbu         $a3, 0x47($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X47);
    // 0x800401FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80040200: jal         0x8003F7AC
    // 0x80040204: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    aisquarelist_ExploreMovesRecursive(rdram, ctx);
        goto after_3;
    // 0x80040204: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_3:
    // 0x80040208: beq         $v0, $zero, L_80040218
    if (ctx->r2 == 0) {
        // 0x8004020C: nop
    
            goto L_80040218;
    }
    // 0x8004020C: nop

    // 0x80040210: b           L_800404D8
    // 0x80040214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800404D8;
    // 0x80040214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80040218:
    // 0x80040218: b           L_800404D8
    // 0x8004021C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800404D8;
    // 0x8004021C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80040220:
    // 0x80040220: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80040224: sb          $t6, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r14;
    // 0x80040228: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8004022C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80040230: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x80040234: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80040238: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8004023C: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
    // 0x80040240: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80040244: nop

    // 0x80040248: lb          $t2, 0x0($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X0);
    // 0x8004024C: nop

    // 0x80040250: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80040254: addu        $s5, $t1, $t3
    ctx->r21 = ADD32(ctx->r9, ctx->r11);
    // 0x80040258: sb          $s1, 0x1($s5)
    MEM_B(0X1, ctx->r21) = ctx->r17;
    // 0x8004025C: lw          $t4, -0x490($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X490);
    // 0x80040260: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80040264: lb          $t5, 0x12($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X12);
    // 0x80040268: sb          $s3, 0x2($s5)
    MEM_B(0X2, ctx->r21) = ctx->r19;
    // 0x8004026C: sb          $t5, 0x1($s5)
    MEM_B(0X1, ctx->r21) = ctx->r13;
    // 0x80040270: lw          $t7, -0x490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X490);
    // 0x80040274: nop

    // 0x80040278: lb          $t6, 0x11($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X11);
    // 0x8004027C: nop

    // 0x80040280: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80040284: beq         $at, $zero, L_800402F4
    if (ctx->r1 == 0) {
        // 0x80040288: nop
    
            goto L_800402F4;
    }
    // 0x80040288: nop

    // 0x8004028C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80040290: sb          $t9, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r25;
L_80040294:
    // 0x80040294: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80040298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004029C: jal         0x8004172C
    // 0x800402A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_4;
    // 0x800402A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x800402A4: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800402A8: beq         $s0, $zero, L_800402D0
    if (ctx->r16 == 0) {
        // 0x800402AC: nop
    
            goto L_800402D0;
    }
    // 0x800402AC: nop

    // 0x800402B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800402B4: lw          $t0, -0x490($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X490);
    // 0x800402B8: nop

    // 0x800402BC: lb          $t8, 0x11($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X11);
    // 0x800402C0: nop

    // 0x800402C4: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x800402C8: bne         $at, $zero, L_80040294
    if (ctx->r1 != 0) {
        // 0x800402CC: nop
    
            goto L_80040294;
    }
    // 0x800402CC: nop

L_800402D0:
    // 0x800402D0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800402D4: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x800402D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800402DC: lb          $t1, 0x11($t2)
    ctx->r9 = MEM_B(ctx->r10, 0X11);
    // 0x800402E0: nop

    // 0x800402E4: beq         $t1, $at, L_8004037C
    if (ctx->r9 == ctx->r1) {
        // 0x800402E8: nop
    
            goto L_8004037C;
    }
    // 0x800402E8: nop

    // 0x800402EC: b           L_800404D8
    // 0x800402F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800404D8;
    // 0x800402F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800402F4:
    // 0x800402F4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800402F8: lw          $t3, -0x490($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X490);
    // 0x800402FC: nop

    // 0x80040300: lb          $t4, 0x11($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X11);
    // 0x80040304: nop

    // 0x80040308: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x8004030C: bne         $at, $zero, L_8004037C
    if (ctx->r1 != 0) {
        // 0x80040310: nop
    
            goto L_8004037C;
    }
    // 0x80040310: nop

    // 0x80040314: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80040318: sb          $t5, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r13;
L_8004031C:
    // 0x8004031C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80040320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80040324: jal         0x8004172C
    // 0x80040328: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_5;
    // 0x80040328: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8004032C: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x80040330: beq         $s0, $zero, L_80040358
    if (ctx->r16 == 0) {
        // 0x80040334: nop
    
            goto L_80040358;
    }
    // 0x80040334: nop

    // 0x80040338: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004033C: lw          $t7, -0x490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X490);
    // 0x80040340: nop

    // 0x80040344: lb          $t6, 0x11($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X11);
    // 0x80040348: nop

    // 0x8004034C: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x80040350: beq         $at, $zero, L_8004031C
    if (ctx->r1 == 0) {
        // 0x80040354: nop
    
            goto L_8004031C;
    }
    // 0x80040354: nop

L_80040358:
    // 0x80040358: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8004035C: lw          $t9, -0x490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X490);
    // 0x80040360: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80040364: lb          $t0, 0x11($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X11);
    // 0x80040368: nop

    // 0x8004036C: beq         $t0, $at, L_8004037C
    if (ctx->r8 == ctx->r1) {
        // 0x80040370: nop
    
            goto L_8004037C;
    }
    // 0x80040370: nop

    // 0x80040374: b           L_800404D8
    // 0x80040378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800404D8;
    // 0x80040378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004037C:
    // 0x8004037C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80040380: addiu       $a1, $sp, 0x33
    ctx->r5 = ADD32(ctx->r29, 0X33);
    // 0x80040384: jal         0x800406B0
    // 0x80040388: addiu       $a2, $sp, 0x32
    ctx->r6 = ADD32(ctx->r29, 0X32);
    aisquarelist_GetRotationSteps(rdram, ctx);
        goto after_6;
    // 0x80040388: addiu       $a2, $sp, 0x32
    ctx->r6 = ADD32(ctx->r29, 0X32);
    after_6:
    // 0x8004038C: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x80040390: nop

    // 0x80040394: bne         $t8, $zero, L_800403AC
    if (ctx->r24 != 0) {
        // 0x80040398: nop
    
            goto L_800403AC;
    }
    // 0x80040398: nop

    // 0x8004039C: lbu         $t2, 0x32($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X32);
    // 0x800403A0: nop

    // 0x800403A4: beq         $t2, $zero, L_800404D4
    if (ctx->r10 == 0) {
        // 0x800403A8: nop
    
            goto L_800404D4;
    }
    // 0x800403A8: nop

L_800403AC:
    // 0x800403AC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800403B0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800403B4: lb          $t3, 0x0($t1)
    ctx->r11 = MEM_B(ctx->r9, 0X0);
    // 0x800403B8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800403BC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800403C0: sb          $t4, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r12;
    // 0x800403C4: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800403C8: lw          $t9, -0x490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X490);
    // 0x800403CC: lb          $t7, 0x0($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X0);
    // 0x800403D0: lb          $t0, 0x11($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X11);
    // 0x800403D4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800403D8: addu        $s5, $t5, $t6
    ctx->r21 = ADD32(ctx->r13, ctx->r14);
    // 0x800403DC: sb          $t0, 0x1($s5)
    MEM_B(0X1, ctx->r21) = ctx->r8;
    // 0x800403E0: lw          $t8, -0x490($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X490);
    // 0x800403E4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800403E8: lb          $t2, 0x12($t8)
    ctx->r10 = MEM_B(ctx->r24, 0X12);
    // 0x800403EC: sb          $s3, 0x2($s5)
    MEM_B(0X2, ctx->r21) = ctx->r19;
    // 0x800403F0: sb          $t2, 0x1($s5)
    MEM_B(0X1, ctx->r21) = ctx->r10;
    // 0x800403F4: lbu         $t4, 0x32($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X32);
    // 0x800403F8: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x800403FC: nop

    // 0x80040400: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80040404: bne         $at, $zero, L_80040470
    if (ctx->r1 != 0) {
        // 0x80040408: nop
    
            goto L_80040470;
    }
    // 0x80040408: nop

    // 0x8004040C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80040410: sb          $t1, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r9;
L_80040414:
    // 0x80040414: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80040418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004041C: jal         0x8004172C
    // 0x80040420: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_7;
    // 0x80040420: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80040424: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x80040428: beq         $s0, $zero, L_8004044C
    if (ctx->r16 == 0) {
        // 0x8004042C: nop
    
            goto L_8004044C;
    }
    // 0x8004042C: nop

    // 0x80040430: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80040434: lw          $t7, -0x490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X490);
    // 0x80040438: nop

    // 0x8004043C: lbu         $t5, 0xA($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0XA);
    // 0x80040440: nop

    // 0x80040444: bne         $t5, $s4, L_80040414
    if (ctx->r13 != ctx->r20) {
        // 0x80040448: nop
    
            goto L_80040414;
    }
    // 0x80040448: nop

L_8004044C:
    // 0x8004044C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80040450: lw          $t6, -0x490($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X490);
    // 0x80040454: nop

    // 0x80040458: lbu         $t9, 0xA($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0XA);
    // 0x8004045C: nop

    // 0x80040460: beq         $t9, $s4, L_800404D4
    if (ctx->r25 == ctx->r20) {
        // 0x80040464: nop
    
            goto L_800404D4;
    }
    // 0x80040464: nop

    // 0x80040468: b           L_800404D8
    // 0x8004046C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800404D8;
    // 0x8004046C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80040470:
    // 0x80040470: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80040474: sb          $t0, 0x3($s5)
    MEM_B(0X3, ctx->r21) = ctx->r8;
L_80040478:
    // 0x80040478: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004047C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80040480: jal         0x8004172C
    // 0x80040484: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_8;
    // 0x80040484: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_8:
    // 0x80040488: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x8004048C: beq         $s0, $zero, L_800404B0
    if (ctx->r16 == 0) {
        // 0x80040490: nop
    
            goto L_800404B0;
    }
    // 0x80040490: nop

    // 0x80040494: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80040498: lw          $t8, -0x490($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X490);
    // 0x8004049C: nop

    // 0x800404A0: lbu         $t2, 0xA($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0XA);
    // 0x800404A4: nop

    // 0x800404A8: bne         $t2, $s4, L_80040478
    if (ctx->r10 != ctx->r20) {
        // 0x800404AC: nop
    
            goto L_80040478;
    }
    // 0x800404AC: nop

L_800404B0:
    // 0x800404B0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800404B4: lw          $t3, -0x490($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X490);
    // 0x800404B8: nop

    // 0x800404BC: lbu         $t4, 0xA($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XA);
    // 0x800404C0: nop

    // 0x800404C4: beq         $t4, $s4, L_800404D4
    if (ctx->r12 == ctx->r20) {
        // 0x800404C8: nop
    
            goto L_800404D4;
    }
    // 0x800404C8: nop

    // 0x800404CC: b           L_800404D8
    // 0x800404D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800404D8;
    // 0x800404D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800404D4:
    // 0x800404D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800404D8:
    // 0x800404D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800404DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800404E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800404E4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800404E8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800404EC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800404F0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800404F4: jr          $ra
    // 0x800404F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800404F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800404FC: nop

;}

RECOMP_FUNC void aisquarelist_EvaluateSquareMoves(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040500: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80040504: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80040508: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8004050C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80040510: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80040514: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80040518: jal         0x80041E88
    // 0x8004051C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    aisquarelist_ClearCandidates(rdram, ctx);
        goto after_0;
    // 0x8004051C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x80040520: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x80040524: lw          $s1, 0x5E04($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X5E04);
    // 0x80040528: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004052C: lbu         $t6, 0x2E($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X2E);
    // 0x80040530: addiu       $s1, $s1, 0x2E
    ctx->r17 = ADD32(ctx->r17, 0X2E);
    // 0x80040534: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80040538: beq         $at, $zero, L_800405A4
    if (ctx->r1 == 0) {
        // 0x8004053C: nop
    
            goto L_800405A4;
    }
    // 0x8004053C: nop

L_80040540:
    // 0x80040540: addu        $t7, $s1, $s0
    ctx->r15 = ADD32(ctx->r17, ctx->r16);
    // 0x80040544: lb          $t8, 0x1($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X1);
    // 0x80040548: addiu       $t0, $sp, 0x31
    ctx->r8 = ADD32(ctx->r29, 0X31);
    // 0x8004054C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80040550: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80040554: addu        $s2, $s1, $t9
    ctx->r18 = ADD32(ctx->r17, ctx->r25);
    // 0x80040558: lbu         $a1, 0x8($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X8);
    // 0x8004055C: lbu         $a0, 0x7($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X7);
    // 0x80040560: addiu       $s2, $s2, 0x7
    ctx->r18 = ADD32(ctx->r18, 0X7);
    // 0x80040564: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80040568: addiu       $a2, $sp, 0x33
    ctx->r6 = ADD32(ctx->r29, 0X33);
    // 0x8004056C: jal         0x80041B48
    // 0x80040570: addiu       $a3, $sp, 0x32
    ctx->r7 = ADD32(ctx->r29, 0X32);
    aisquarelist_CheckSquareCompletion(rdram, ctx);
        goto after_1;
    // 0x80040570: addiu       $a3, $sp, 0x32
    ctx->r7 = ADD32(ctx->r29, 0X32);
    after_1:
    // 0x80040574: bne         $v0, $zero, L_80040588
    if (ctx->r2 != 0) {
        // 0x80040578: nop
    
            goto L_80040588;
    }
    // 0x80040578: nop

    // 0x8004057C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80040580: jal         0x8003E2C8
    // 0x80040584: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    aisquarelist_RemoveAt(rdram, ctx);
        goto after_2;
    // 0x80040584: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
L_80040588:
    // 0x80040588: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004058C: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x80040590: andi        $t1, $s0, 0xFF
    ctx->r9 = ctx->r16 & 0XFF;
    // 0x80040594: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80040598: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8004059C: bne         $at, $zero, L_80040540
    if (ctx->r1 != 0) {
        // 0x800405A0: nop
    
            goto L_80040540;
    }
    // 0x800405A0: nop

L_800405A4:
    // 0x800405A4: sb          $zero, 0x31($sp)
    MEM_B(0X31, ctx->r29) = 0;
    // 0x800405A8: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    // 0x800405AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800405B0: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800405B4: beq         $at, $zero, L_80040610
    if (ctx->r1 == 0) {
        // 0x800405B8: nop
    
            goto L_80040610;
    }
    // 0x800405B8: nop

L_800405BC:
    // 0x800405BC: lbu         $t4, 0x47($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X47);
    // 0x800405C0: lbu         $a3, 0x43($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X43);
    // 0x800405C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800405C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800405CC: addiu       $a2, $sp, 0x31
    ctx->r6 = ADD32(ctx->r29, 0X31);
    // 0x800405D0: jal         0x8003ED40
    // 0x800405D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    aisquarelist_EvaluatePlacementSquares(rdram, ctx);
        goto after_3;
    // 0x800405D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x800405D8: beq         $v0, $zero, L_800405F4
    if (ctx->r2 == 0) {
        // 0x800405DC: nop
    
            goto L_800405F4;
    }
    // 0x800405DC: nop

    // 0x800405E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800405E4: jal         0x8003E2C8
    // 0x800405E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    aisquarelist_RemoveAt(rdram, ctx);
        goto after_4;
    // 0x800405E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800405EC: b           L_80040610
    // 0x800405F0: nop

        goto L_80040610;
    // 0x800405F0: nop

L_800405F4:
    // 0x800405F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800405F8: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x800405FC: andi        $t5, $s0, 0xFF
    ctx->r13 = ctx->r16 & 0XFF;
    // 0x80040600: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x80040604: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80040608: bne         $at, $zero, L_800405BC
    if (ctx->r1 != 0) {
        // 0x8004060C: nop
    
            goto L_800405BC;
    }
    // 0x8004060C: nop

L_80040610:
    // 0x80040610: lbu         $t7, 0x31($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X31);
    // 0x80040614: nop

    // 0x80040618: bne         $t7, $zero, L_80040684
    if (ctx->r15 != 0) {
        // 0x8004061C: nop
    
            goto L_80040684;
    }
    // 0x8004061C: nop

    // 0x80040620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80040624: addiu       $a1, $sp, 0x33
    ctx->r5 = ADD32(ctx->r29, 0X33);
    // 0x80040628: jal         0x8003E458
    // 0x8004062C: addiu       $a2, $sp, 0x32
    ctx->r6 = ADD32(ctx->r29, 0X32);
    aisquarelist_FindSquarePlacement(rdram, ctx);
        goto after_5;
    // 0x8004062C: addiu       $a2, $sp, 0x32
    ctx->r6 = ADD32(ctx->r29, 0X32);
    after_5:
    // 0x80040630: beq         $v0, $zero, L_8004067C
    if (ctx->r2 == 0) {
        // 0x80040634: nop
    
            goto L_8004067C;
    }
    // 0x80040634: nop

    // 0x80040638: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    // 0x8004063C: lbu         $a2, 0x32($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X32);
    // 0x80040640: jal         0x8003E22C
    // 0x80040644: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    aisquarelist_AddSquare(rdram, ctx);
        goto after_6;
    // 0x80040644: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80040648: lbu         $t8, 0x47($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X47);
    // 0x8004064C: lbu         $a3, 0x43($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X43);
    // 0x80040650: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80040654: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80040658: addiu       $a2, $sp, 0x31
    ctx->r6 = ADD32(ctx->r29, 0X31);
    // 0x8004065C: jal         0x8003ED40
    // 0x80040660: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    aisquarelist_EvaluatePlacementSquares(rdram, ctx);
        goto after_7;
    // 0x80040660: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_7:
    // 0x80040664: lbu         $t9, 0x31($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X31);
    // 0x80040668: nop

    // 0x8004066C: bne         $t9, $zero, L_80040684
    if (ctx->r25 != 0) {
        // 0x80040670: nop
    
            goto L_80040684;
    }
    // 0x80040670: nop

    // 0x80040674: b           L_80040694
    // 0x80040678: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80040694;
    // 0x80040678: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004067C:
    // 0x8004067C: b           L_80040694
    // 0x80040680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80040694;
    // 0x80040680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80040684:
    // 0x80040684: lbu         $a0, 0x31($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X31);
    // 0x80040688: jal         0x800423F0
    // 0x8004068C: nop

    aisquarelist_SortCandidates(rdram, ctx);
        goto after_8;
    // 0x8004068C: nop

    after_8:
    // 0x80040690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80040694:
    // 0x80040694: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80040698: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004069C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800406A0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800406A4: jr          $ra
    // 0x800406A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800406A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800406AC: nop

;}

RECOMP_FUNC void aisquarelist_GetRotationSteps(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800406B0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800406B4: lw          $t7, -0x490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X490);
    // 0x800406B8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800406BC: sll         $a3, $a0, 24
    ctx->r7 = S32(ctx->r4 << 24);
    // 0x800406C0: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x800406C4: sra         $t6, $a3, 24
    ctx->r14 = S32(SIGNED(ctx->r7) >> 24);
    // 0x800406C8: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800406CC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800406D0: beq         $a3, $t8, L_80040718
    if (ctx->r7 == ctx->r24) {
        // 0x800406D4: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80040718;
    }
    // 0x800406D4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800406D8:
    // 0x800406D8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800406DC: sll         $t9, $a3, 24
    ctx->r25 = S32(ctx->r7 << 24);
    // 0x800406E0: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800406E4: sra         $t2, $a3, 24
    ctx->r10 = S32(SIGNED(ctx->r7) >> 24);
    // 0x800406E8: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x800406EC: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x800406F0: bne         $at, $zero, L_800406FC
    if (ctx->r1 != 0) {
        // 0x800406F4: nop
    
            goto L_800406FC;
    }
    // 0x800406F4: nop

    // 0x800406F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800406FC:
    // 0x800406FC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80040700: lw          $t4, -0x490($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X490);
    // 0x80040704: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80040708: lbu         $t5, 0xA($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0XA);
    // 0x8004070C: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x80040710: bne         $a3, $t5, L_800406D8
    if (ctx->r7 != ctx->r13) {
        // 0x80040714: or          $t0, $t3, $zero
        ctx->r8 = ctx->r11 | 0;
            goto L_800406D8;
    }
    // 0x80040714: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
L_80040718:
    // 0x80040718: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004071C: lw          $t7, -0x490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X490);
    // 0x80040720: sll         $a3, $a0, 24
    ctx->r7 = S32(ctx->r4 << 24);
    // 0x80040724: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x80040728: sra         $t6, $a3, 24
    ctx->r14 = S32(SIGNED(ctx->r7) >> 24);
    // 0x8004072C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80040730: beq         $a3, $t8, L_80040774
    if (ctx->r7 == ctx->r24) {
        // 0x80040734: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80040774;
    }
    // 0x80040734: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80040738:
    // 0x80040738: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8004073C: sll         $t9, $a3, 24
    ctx->r25 = S32(ctx->r7 << 24);
    // 0x80040740: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80040744: sra         $t2, $a3, 24
    ctx->r10 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80040748: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8004074C: bgez        $a3, L_80040758
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80040750: nop
    
            goto L_80040758;
    }
    // 0x80040750: nop

    // 0x80040754: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_80040758:
    // 0x80040758: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004075C: lw          $t4, -0x490($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X490);
    // 0x80040760: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80040764: lbu         $t5, 0xA($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0XA);
    // 0x80040768: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x8004076C: bne         $a3, $t5, L_80040738
    if (ctx->r7 != ctx->r13) {
        // 0x80040770: or          $t1, $t3, $zero
        ctx->r9 = ctx->r11 | 0;
            goto L_80040738;
    }
    // 0x80040770: or          $t1, $t3, $zero
    ctx->r9 = ctx->r11 | 0;
L_80040774:
    // 0x80040774: sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
    // 0x80040778: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x8004077C: jr          $ra
    // 0x80040780: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80040780: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void aisquarelist_GetPieceBounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040784: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80040788: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8004078C: beq         $a1, $zero, L_80040798
    if (ctx->r5 == 0) {
        // 0x80040790: sb          $t6, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r14;
            goto L_80040798;
    }
    // 0x80040790: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80040794: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_80040798:
    // 0x80040798: beq         $a2, $zero, L_800407A8
    if (ctx->r6 == 0) {
        // 0x8004079C: nop
    
            goto L_800407A8;
    }
    // 0x8004079C: nop

    // 0x800407A0: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x800407A4: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
L_800407A8:
    // 0x800407A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800407AC: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x800407B0: beq         $at, $zero, L_8004089C
    if (ctx->r1 == 0) {
        // 0x800407B4: sb          $zero, 0x0($a3)
        MEM_B(0X0, ctx->r7) = 0;
            goto L_8004089C;
    }
    // 0x800407B4: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
L_800407B8:
    // 0x800407B8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800407BC: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x800407C0: beq         $at, $zero, L_80040884
    if (ctx->r1 == 0) {
        // 0x800407C4: nop
    
            goto L_80040884;
    }
    // 0x800407C4: nop

L_800407C8:
    // 0x800407C8: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x800407CC: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x800407D0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800407D4: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x800407D8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800407DC: lw          $t8, 0x1F30($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F30);
    // 0x800407E0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800407E4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800407E8: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800407EC: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800407F0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800407F4: bne         $t5, $at, L_8004086C
    if (ctx->r13 != ctx->r1) {
        // 0x800407F8: nop
    
            goto L_8004086C;
    }
    // 0x800407F8: nop

    // 0x800407FC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80040800: nop

    // 0x80040804: slt         $at, $t0, $t6
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80040808: beq         $at, $zero, L_80040814
    if (ctx->r1 == 0) {
        // 0x8004080C: nop
    
            goto L_80040814;
    }
    // 0x8004080C: nop

    // 0x80040810: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
L_80040814:
    // 0x80040814: beq         $a1, $zero, L_80040834
    if (ctx->r5 == 0) {
        // 0x80040818: nop
    
            goto L_80040834;
    }
    // 0x80040818: nop

    // 0x8004081C: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80040820: nop

    // 0x80040824: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80040828: beq         $at, $zero, L_80040834
    if (ctx->r1 == 0) {
        // 0x8004082C: nop
    
            goto L_80040834;
    }
    // 0x8004082C: nop

    // 0x80040830: sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
L_80040834:
    // 0x80040834: beq         $a2, $zero, L_80040854
    if (ctx->r6 == 0) {
        // 0x80040838: nop
    
            goto L_80040854;
    }
    // 0x80040838: nop

    // 0x8004083C: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x80040840: nop

    // 0x80040844: slt         $at, $t1, $t9
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80040848: beq         $at, $zero, L_80040854
    if (ctx->r1 == 0) {
        // 0x8004084C: nop
    
            goto L_80040854;
    }
    // 0x8004084C: nop

    // 0x80040850: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
L_80040854:
    // 0x80040854: lbu         $t2, 0x0($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X0);
    // 0x80040858: nop

    // 0x8004085C: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80040860: beq         $at, $zero, L_8004086C
    if (ctx->r1 == 0) {
        // 0x80040864: nop
    
            goto L_8004086C;
    }
    // 0x80040864: nop

    // 0x80040868: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
L_8004086C:
    // 0x8004086C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80040870: andi        $t8, $t1, 0xFF
    ctx->r24 = ctx->r9 & 0XFF;
    // 0x80040874: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x80040878: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x8004087C: bne         $at, $zero, L_800407C8
    if (ctx->r1 != 0) {
        // 0x80040880: nop
    
            goto L_800407C8;
    }
    // 0x80040880: nop

L_80040884:
    // 0x80040884: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80040888: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x8004088C: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x80040890: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x80040894: bne         $at, $zero, L_800407B8
    if (ctx->r1 != 0) {
        // 0x80040898: nop
    
            goto L_800407B8;
    }
    // 0x80040898: nop

L_8004089C:
    // 0x8004089C: jr          $ra
    // 0x800408A0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800408A0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800408A4: nop

    // 0x800408A8: nop

    // 0x800408AC: nop

;}

RECOMP_FUNC void aisquarelist_CellBelongsToSquare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800408B0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800408B4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800408B8: sll         $t6, $a2, 5
    ctx->r14 = S32(ctx->r6 << 5);
    // 0x800408BC: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x800408C0: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800408C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800408C8: addiu       $t9, $t9, 0x5CF0
    ctx->r25 = ADD32(ctx->r25, 0X5CF0);
    // 0x800408CC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800408D0: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x800408D4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800408D8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800408DC: beq         $at, $zero, L_8004091C
    if (ctx->r1 == 0) {
        // 0x800408E0: addu        $a3, $t8, $t9
        ctx->r7 = ADD32(ctx->r24, ctx->r25);
            goto L_8004091C;
    }
    // 0x800408E0: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
L_800408E4:
    // 0x800408E4: addu        $t1, $a3, $t0
    ctx->r9 = ADD32(ctx->r7, ctx->r8);
    // 0x800408E8: lb          $t2, 0x4($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X4);
    // 0x800408EC: nop

    // 0x800408F0: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x800408F4: bne         $t3, $zero, L_80040904
    if (ctx->r11 != 0) {
        // 0x800408F8: nop
    
            goto L_80040904;
    }
    // 0x800408F8: nop

    // 0x800408FC: b           L_80040920
    // 0x80040900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80040920;
    // 0x80040900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80040904:
    // 0x80040904: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80040908: andi        $t4, $t0, 0xFF
    ctx->r12 = ctx->r8 & 0XFF;
    // 0x8004090C: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x80040910: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80040914: bne         $at, $zero, L_800408E4
    if (ctx->r1 != 0) {
        // 0x80040918: nop
    
            goto L_800408E4;
    }
    // 0x80040918: nop

L_8004091C:
    // 0x8004091C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80040920:
    // 0x80040920: jr          $ra
    // 0x80040924: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80040924: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80040928: nop

    // 0x8004092C: nop

;}

RECOMP_FUNC void aisquarelist_ComputePlacementBounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040930: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80040934: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80040938: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8004093C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80040940: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80040944: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80040948: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8004094C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80040950: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80040954: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80040958: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8004095C: addiu       $a1, $sp, 0x36
    ctx->r5 = ADD32(ctx->r29, 0X36);
    // 0x80040960: addiu       $a0, $sp, 0x37
    ctx->r4 = ADD32(ctx->r29, 0X37);
    // 0x80040964: addiu       $a2, $sp, 0x35
    ctx->r6 = ADD32(ctx->r29, 0X35);
    // 0x80040968: jal         0x80040784
    // 0x8004096C: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    aisquarelist_GetPieceBounds(rdram, ctx);
        goto after_0;
    // 0x8004096C: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80040970: lbu         $t6, 0x34($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X34);
    // 0x80040974: nop

    // 0x80040978: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x8004097C: bne         $at, $zero, L_80040990
    if (ctx->r1 != 0) {
        // 0x80040980: nop
    
            goto L_80040990;
    }
    // 0x80040980: nop

    // 0x80040984: addiu       $t7, $t6, -0x3
    ctx->r15 = ADD32(ctx->r14, -0X3);
    // 0x80040988: b           L_80040994
    // 0x8004098C: sb          $t7, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r15;
        goto L_80040994;
    // 0x8004098C: sb          $t7, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r15;
L_80040990:
    // 0x80040990: sb          $zero, 0x35($sp)
    MEM_B(0X35, ctx->r29) = 0;
L_80040994:
    // 0x80040994: lbu         $t8, 0x35($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X35);
    // 0x80040998: nop

    // 0x8004099C: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800409A0: bne         $at, $zero, L_800409B8
    if (ctx->r1 != 0) {
        // 0x800409A4: nop
    
            goto L_800409B8;
    }
    // 0x800409A4: nop

    // 0x800409A8: addiu       $s2, $t8, -0x3
    ctx->r18 = ADD32(ctx->r24, -0X3);
    // 0x800409AC: andi        $t9, $s2, 0xFF
    ctx->r25 = ctx->r18 & 0XFF;
    // 0x800409B0: b           L_800409BC
    // 0x800409B4: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
        goto L_800409BC;
    // 0x800409B4: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_800409B8:
    // 0x800409B8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800409BC:
    // 0x800409BC: lbu         $t1, 0x35($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X35);
    // 0x800409C0: addiu       $t0, $s2, 0x3
    ctx->r8 = ADD32(ctx->r18, 0X3);
    // 0x800409C4: bne         $t0, $t1, L_80040A54
    if (ctx->r8 != ctx->r9) {
        // 0x800409C8: nop
    
            goto L_80040A54;
    }
    // 0x800409C8: nop

    // 0x800409CC: lbu         $s1, 0x37($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X37);
    // 0x800409D0: lbu         $t2, 0x36($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X36);
    // 0x800409D4: nop

    // 0x800409D8: slt         $at, $t2, $s1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800409DC: bne         $at, $zero, L_80040A48
    if (ctx->r1 != 0) {
        // 0x800409E0: nop
    
            goto L_80040A48;
    }
    // 0x800409E0: nop

L_800409E4:
    // 0x800409E4: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x800409E8: addu        $t4, $t4, $s2
    ctx->r12 = ADD32(ctx->r12, ctx->r18);
    // 0x800409EC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800409F0: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x800409F4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800409F8: lw          $t3, 0x1F30($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F30);
    // 0x800409FC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80040A00: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80040A04: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80040A08: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80040A0C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80040A10: bne         $t8, $at, L_80040A2C
    if (ctx->r24 != ctx->r1) {
        // 0x80040A14: nop
    
            goto L_80040A2C;
    }
    // 0x80040A14: nop

    // 0x80040A18: addiu       $s5, $s5, -0x4
    ctx->r21 = ADD32(ctx->r21, -0X4);
    // 0x80040A1C: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x80040A20: or          $s5, $t9, $zero
    ctx->r21 = ctx->r25 | 0;
    // 0x80040A24: sra         $t0, $s5, 16
    ctx->r8 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80040A28: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
L_80040A2C:
    // 0x80040A2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80040A30: lbu         $t2, 0x36($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X36);
    // 0x80040A34: andi        $t1, $s1, 0xFF
    ctx->r9 = ctx->r17 & 0XFF;
    // 0x80040A38: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80040A3C: slt         $at, $t2, $s1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80040A40: beq         $at, $zero, L_800409E4
    if (ctx->r1 == 0) {
        // 0x80040A44: nop
    
            goto L_800409E4;
    }
    // 0x80040A44: nop

L_80040A48:
    // 0x80040A48: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80040A4C: andi        $t4, $s2, 0xFF
    ctx->r12 = ctx->r18 & 0XFF;
    // 0x80040A50: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
L_80040A54:
    // 0x80040A54: sll         $s0, $s2, 24
    ctx->r16 = S32(ctx->r18 << 24);
    // 0x80040A58: lbu         $t3, 0x35($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X35);
    // 0x80040A5C: sra         $t5, $s0, 24
    ctx->r13 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80040A60: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x80040A64: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80040A68: beq         $at, $zero, L_80040B10
    if (ctx->r1 == 0) {
        // 0x80040A6C: nop
    
            goto L_80040B10;
    }
    // 0x80040A6C: nop

L_80040A70:
    // 0x80040A70: lbu         $s1, 0x37($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X37);
    // 0x80040A74: lbu         $t6, 0x36($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X36);
    // 0x80040A78: nop

    // 0x80040A7C: slt         $at, $t6, $s1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80040A80: bne         $at, $zero, L_80040AEC
    if (ctx->r1 != 0) {
        // 0x80040A84: nop
    
            goto L_80040AEC;
    }
    // 0x80040A84: nop

L_80040A88:
    // 0x80040A88: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80040A8C: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x80040A90: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80040A94: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x80040A98: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80040A9C: lw          $t7, 0x1F30($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F30);
    // 0x80040AA0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80040AA4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80040AA8: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80040AAC: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80040AB0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80040AB4: bne         $t2, $at, L_80040AD0
    if (ctx->r10 != ctx->r1) {
        // 0x80040AB8: nop
    
            goto L_80040AD0;
    }
    // 0x80040AB8: nop

    // 0x80040ABC: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80040AC0: sll         $t4, $s5, 16
    ctx->r12 = S32(ctx->r21 << 16);
    // 0x80040AC4: or          $s5, $t4, $zero
    ctx->r21 = ctx->r12 | 0;
    // 0x80040AC8: sra         $t5, $s5, 16
    ctx->r13 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80040ACC: or          $s5, $t5, $zero
    ctx->r21 = ctx->r13 | 0;
L_80040AD0:
    // 0x80040AD0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80040AD4: lbu         $t6, 0x36($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X36);
    // 0x80040AD8: andi        $t3, $s1, 0xFF
    ctx->r11 = ctx->r17 & 0XFF;
    // 0x80040ADC: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80040AE0: slt         $at, $t6, $s1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80040AE4: beq         $at, $zero, L_80040A88
    if (ctx->r1 == 0) {
        // 0x80040AE8: nop
    
            goto L_80040A88;
    }
    // 0x80040AE8: nop

L_80040AEC:
    // 0x80040AEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80040AF0: sll         $t8, $s0, 24
    ctx->r24 = S32(ctx->r16 << 24);
    // 0x80040AF4: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80040AF8: lbu         $t7, 0x35($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X35);
    // 0x80040AFC: sra         $t9, $s0, 24
    ctx->r25 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80040B00: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80040B04: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80040B08: bne         $at, $zero, L_80040A70
    if (ctx->r1 != 0) {
        // 0x80040B0C: nop
    
            goto L_80040A70;
    }
    // 0x80040B0C: nop

L_80040B10:
    // 0x80040B10: lb          $s0, 0x35($sp)
    ctx->r16 = MEM_B(ctx->r29, 0X35);
    // 0x80040B14: lbu         $t0, 0x34($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X34);
    // 0x80040B18: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80040B1C: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80040B20: bne         $at, $zero, L_80040DB0
    if (ctx->r1 != 0) {
        // 0x80040B24: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80040DB0;
    }
    // 0x80040B24: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80040B28:
    // 0x80040B28: lbu         $t2, 0x35($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X35);
    // 0x80040B2C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80040B30: subu        $t4, $s0, $t2
    ctx->r12 = SUB32(ctx->r16, ctx->r10);
    // 0x80040B34: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x80040B38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80040B3C: slti        $at, $s1, 0xA
    ctx->r1 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x80040B40: beq         $at, $zero, L_80040BAC
    if (ctx->r1 == 0) {
        // 0x80040B44: sb          $t1, 0x30($t5)
        MEM_B(0X30, ctx->r13) = ctx->r9;
            goto L_80040BAC;
    }
    // 0x80040B44: sb          $t1, 0x30($t5)
    MEM_B(0X30, ctx->r13) = ctx->r9;
L_80040B48:
    // 0x80040B48: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80040B4C: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x80040B50: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80040B54: addu        $t8, $s1, $t6
    ctx->r24 = ADD32(ctx->r17, ctx->r14);
    // 0x80040B58: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80040B5C: lw          $t3, 0x1F30($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F30);
    // 0x80040B60: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80040B64: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80040B68: addu        $t7, $t3, $t9
    ctx->r15 = ADD32(ctx->r11, ctx->r25);
    // 0x80040B6C: lbu         $t0, 0x0($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X0);
    // 0x80040B70: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80040B74: bne         $t0, $at, L_80040B94
    if (ctx->r8 != ctx->r1) {
        // 0x80040B78: nop
    
            goto L_80040B94;
    }
    // 0x80040B78: nop

    // 0x80040B7C: lbu         $t2, 0x35($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X35);
    // 0x80040B80: nop

    // 0x80040B84: subu        $t1, $s0, $t2
    ctx->r9 = SUB32(ctx->r16, ctx->r10);
    // 0x80040B88: addu        $t4, $sp, $t1
    ctx->r12 = ADD32(ctx->r29, ctx->r9);
    // 0x80040B8C: b           L_80040BAC
    // 0x80040B90: sb          $zero, 0x30($t4)
    MEM_B(0X30, ctx->r12) = 0;
        goto L_80040BAC;
    // 0x80040B90: sb          $zero, 0x30($t4)
    MEM_B(0X30, ctx->r12) = 0;
L_80040B94:
    // 0x80040B94: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80040B98: andi        $t5, $s1, 0xFF
    ctx->r13 = ctx->r17 & 0XFF;
    // 0x80040B9C: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x80040BA0: slti        $at, $s1, 0xA
    ctx->r1 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x80040BA4: bne         $at, $zero, L_80040B48
    if (ctx->r1 != 0) {
        // 0x80040BA8: nop
    
            goto L_80040B48;
    }
    // 0x80040BA8: nop

L_80040BAC:
    // 0x80040BAC: lbu         $t6, 0x35($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X35);
    // 0x80040BB0: nop

    // 0x80040BB4: subu        $t8, $s0, $t6
    ctx->r24 = SUB32(ctx->r16, ctx->r14);
    // 0x80040BB8: addu        $t3, $sp, $t8
    ctx->r11 = ADD32(ctx->r29, ctx->r24);
    // 0x80040BBC: lbu         $t3, 0x30($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X30);
    // 0x80040BC0: nop

    // 0x80040BC4: beq         $t3, $zero, L_80040BD8
    if (ctx->r11 == 0) {
        // 0x80040BC8: nop
    
            goto L_80040BD8;
    }
    // 0x80040BC8: nop

    // 0x80040BCC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80040BD0: andi        $t9, $s4, 0xFF
    ctx->r25 = ctx->r20 & 0XFF;
    // 0x80040BD4: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
L_80040BD8:
    // 0x80040BD8: lbu         $s1, 0x37($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X37);
    // 0x80040BDC: lbu         $t7, 0x36($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X36);
    // 0x80040BE0: nop

    // 0x80040BE4: slt         $at, $t7, $s1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80040BE8: bne         $at, $zero, L_80040D8C
    if (ctx->r1 != 0) {
        // 0x80040BEC: nop
    
            goto L_80040D8C;
    }
    // 0x80040BEC: nop

L_80040BF0:
    // 0x80040BF0: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80040BF4: addu        $t2, $t2, $s0
    ctx->r10 = ADD32(ctx->r10, ctx->r16);
    // 0x80040BF8: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80040BFC: addu        $t1, $s1, $t2
    ctx->r9 = ADD32(ctx->r17, ctx->r10);
    // 0x80040C00: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80040C04: lw          $t0, 0x1F30($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F30);
    // 0x80040C08: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x80040C0C: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x80040C10: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80040C14: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80040C18: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80040C1C: bne         $t6, $at, L_80040D70
    if (ctx->r14 != ctx->r1) {
        // 0x80040C20: nop
    
            goto L_80040D70;
    }
    // 0x80040C20: nop

    // 0x80040C24: lbu         $t8, 0x35($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X35);
    // 0x80040C28: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80040C2C: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80040C30: subu        $t3, $s0, $t8
    ctx->r11 = SUB32(ctx->r16, ctx->r24);
    // 0x80040C34: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x80040C38: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x80040C3C: lb          $t7, 0x5DDC($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X5DDC);
    // 0x80040C40: lbu         $t9, 0x5DD0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X5DD0);
    // 0x80040C44: lbu         $t4, 0x43($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X43);
    // 0x80040C48: addu        $t2, $t9, $t7
    ctx->r10 = ADD32(ctx->r25, ctx->r15);
    // 0x80040C4C: addu        $s5, $s5, $t2
    ctx->r21 = ADD32(ctx->r21, ctx->r10);
    // 0x80040C50: sll         $t1, $s5, 16
    ctx->r9 = S32(ctx->r21 << 16);
    // 0x80040C54: or          $s5, $t1, $zero
    ctx->r21 = ctx->r9 | 0;
    // 0x80040C58: sra         $t0, $s5, 16
    ctx->r8 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80040C5C: beq         $t4, $zero, L_80040C88
    if (ctx->r12 == 0) {
        // 0x80040C60: or          $s5, $t0, $zero
        ctx->r21 = ctx->r8 | 0;
            goto L_80040C88;
    }
    // 0x80040C60: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
    // 0x80040C64: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80040C68: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x80040C6C: lb          $t5, 0x5DDC($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X5DDC);
    // 0x80040C70: nop

    // 0x80040C74: addu        $s5, $s5, $t5
    ctx->r21 = ADD32(ctx->r21, ctx->r13);
    // 0x80040C78: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x80040C7C: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
    // 0x80040C80: sra         $t8, $s5, 16
    ctx->r24 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80040C84: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
L_80040C88:
    // 0x80040C88: lbu         $t3, 0x35($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X35);
    // 0x80040C8C: nop

    // 0x80040C90: subu        $t9, $s0, $t3
    ctx->r25 = SUB32(ctx->r16, ctx->r11);
    // 0x80040C94: addu        $t7, $sp, $t9
    ctx->r15 = ADD32(ctx->r29, ctx->r25);
    // 0x80040C98: lbu         $t7, 0x30($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X30);
    // 0x80040C9C: nop

    // 0x80040CA0: bne         $t7, $zero, L_80040D70
    if (ctx->r15 != 0) {
        // 0x80040CA4: nop
    
            goto L_80040D70;
    }
    // 0x80040CA4: nop

    // 0x80040CA8: addiu       $s2, $s0, 0x1
    ctx->r18 = ADD32(ctx->r16, 0X1);
    // 0x80040CAC: lbu         $t1, 0x34($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X34);
    // 0x80040CB0: andi        $t2, $s2, 0xFF
    ctx->r10 = ctx->r18 & 0XFF;
    // 0x80040CB4: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x80040CB8: slt         $at, $t1, $s2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80040CBC: bne         $at, $zero, L_80040D70
    if (ctx->r1 != 0) {
        // 0x80040CC0: nop
    
            goto L_80040D70;
    }
    // 0x80040CC0: nop

L_80040CC4:
    // 0x80040CC4: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x80040CC8: addu        $t4, $t4, $s2
    ctx->r12 = ADD32(ctx->r12, ctx->r18);
    // 0x80040CCC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80040CD0: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x80040CD4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80040CD8: lw          $t0, 0x1F30($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F30);
    // 0x80040CDC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80040CE0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80040CE4: addu        $t8, $t0, $t6
    ctx->r24 = ADD32(ctx->r8, ctx->r14);
    // 0x80040CE8: lbu         $t3, 0x0($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X0);
    // 0x80040CEC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80040CF0: bne         $t3, $at, L_80040D54
    if (ctx->r11 != ctx->r1) {
        // 0x80040CF4: nop
    
            goto L_80040D54;
    }
    // 0x80040CF4: nop

    // 0x80040CF8: lbu         $t9, 0x35($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X35);
    // 0x80040CFC: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80040D00: addiu       $t2, $t2, 0x5DD0
    ctx->r10 = ADD32(ctx->r10, 0X5DD0);
    // 0x80040D04: subu        $t7, $s2, $t9
    ctx->r15 = SUB32(ctx->r18, ctx->r25);
    // 0x80040D08: addu        $t1, $t7, $t2
    ctx->r9 = ADD32(ctx->r15, ctx->r10);
    // 0x80040D0C: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x80040D10: lb          $t6, 0x47($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X47);
    // 0x80040D14: subu        $s5, $s5, $t4
    ctx->r21 = SUB32(ctx->r21, ctx->r12);
    // 0x80040D18: sll         $t5, $s5, 16
    ctx->r13 = S32(ctx->r21 << 16);
    // 0x80040D1C: or          $s5, $t5, $zero
    ctx->r21 = ctx->r13 | 0;
    // 0x80040D20: sra         $t0, $s5, 16
    ctx->r8 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80040D24: bne         $s1, $t6, L_80040D50
    if (ctx->r17 != ctx->r14) {
        // 0x80040D28: or          $s5, $t0, $zero
        ctx->r21 = ctx->r8 | 0;
            goto L_80040D50;
    }
    // 0x80040D28: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
    // 0x80040D2C: subu        $t8, $s2, $t9
    ctx->r24 = SUB32(ctx->r18, ctx->r25);
    // 0x80040D30: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x80040D34: lbu         $t7, 0x0($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X0);
    // 0x80040D38: nop

    // 0x80040D3C: subu        $s5, $s5, $t7
    ctx->r21 = SUB32(ctx->r21, ctx->r15);
    // 0x80040D40: sll         $t1, $s5, 16
    ctx->r9 = S32(ctx->r21 << 16);
    // 0x80040D44: or          $s5, $t1, $zero
    ctx->r21 = ctx->r9 | 0;
    // 0x80040D48: sra         $t4, $s5, 16
    ctx->r12 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80040D4C: or          $s5, $t4, $zero
    ctx->r21 = ctx->r12 | 0;
L_80040D50:
    // 0x80040D50: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80040D54:
    // 0x80040D54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80040D58: lbu         $t0, 0x34($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X34);
    // 0x80040D5C: andi        $t5, $s2, 0xFF
    ctx->r13 = ctx->r18 & 0XFF;
    // 0x80040D60: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x80040D64: slt         $at, $t0, $s2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80040D68: beq         $at, $zero, L_80040CC4
    if (ctx->r1 == 0) {
        // 0x80040D6C: nop
    
            goto L_80040CC4;
    }
    // 0x80040D6C: nop

L_80040D70:
    // 0x80040D70: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80040D74: lbu         $t9, 0x36($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X36);
    // 0x80040D78: andi        $t6, $s1, 0xFF
    ctx->r14 = ctx->r17 & 0XFF;
    // 0x80040D7C: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80040D80: slt         $at, $t9, $s1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80040D84: beq         $at, $zero, L_80040BF0
    if (ctx->r1 == 0) {
        // 0x80040D88: nop
    
            goto L_80040BF0;
    }
    // 0x80040D88: nop

L_80040D8C:
    // 0x80040D8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80040D90: sll         $t8, $s0, 24
    ctx->r24 = S32(ctx->r16 << 24);
    // 0x80040D94: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80040D98: lbu         $t3, 0x34($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X34);
    // 0x80040D9C: sra         $t2, $s0, 24
    ctx->r10 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80040DA0: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80040DA4: slt         $at, $t3, $s0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80040DA8: beq         $at, $zero, L_80040B28
    if (ctx->r1 == 0) {
        // 0x80040DAC: nop
    
            goto L_80040B28;
    }
    // 0x80040DAC: nop

L_80040DB0:
    // 0x80040DB0: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80040DB4: addu        $t7, $t7, $s4
    ctx->r15 = ADD32(ctx->r15, ctx->r20);
    // 0x80040DB8: lb          $t7, 0x5DD4($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X5DD4);
    // 0x80040DBC: lbu         $t5, 0x43($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X43);
    // 0x80040DC0: addu        $s5, $s5, $t7
    ctx->r21 = ADD32(ctx->r21, ctx->r15);
    // 0x80040DC4: sll         $t1, $s5, 16
    ctx->r9 = S32(ctx->r21 << 16);
    // 0x80040DC8: or          $s5, $t1, $zero
    ctx->r21 = ctx->r9 | 0;
    // 0x80040DCC: sra         $t4, $s5, 16
    ctx->r12 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80040DD0: beq         $t5, $zero, L_80040DF0
    if (ctx->r13 == 0) {
        // 0x80040DD4: or          $s5, $t4, $zero
        ctx->r21 = ctx->r12 | 0;
            goto L_80040DF0;
    }
    // 0x80040DD4: or          $s5, $t4, $zero
    ctx->r21 = ctx->r12 | 0;
    // 0x80040DD8: sll         $t0, $s4, 4
    ctx->r8 = S32(ctx->r20 << 4);
    // 0x80040DDC: addu        $s5, $s5, $t0
    ctx->r21 = ADD32(ctx->r21, ctx->r8);
    // 0x80040DE0: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x80040DE4: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
    // 0x80040DE8: sra         $t9, $s5, 16
    ctx->r25 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80040DEC: or          $s5, $t9, $zero
    ctx->r21 = ctx->r25 | 0;
L_80040DF0:
    // 0x80040DF0: lbu         $s1, 0x37($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X37);
    // 0x80040DF4: lbu         $t8, 0x36($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X36);
    // 0x80040DF8: nop

    // 0x80040DFC: slt         $at, $t8, $s1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80040E00: bne         $at, $zero, L_80040F58
    if (ctx->r1 != 0) {
        // 0x80040E04: nop
    
            goto L_80040F58;
    }
    // 0x80040E04: nop

L_80040E08:
    // 0x80040E08: lb          $s0, 0x35($sp)
    ctx->r16 = MEM_B(ctx->r29, 0X35);
    // 0x80040E0C: lbu         $t2, 0x34($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X34);
    // 0x80040E10: nop

    // 0x80040E14: slt         $at, $t2, $s0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80040E18: bne         $at, $zero, L_80040F3C
    if (ctx->r1 != 0) {
        // 0x80040E1C: nop
    
            goto L_80040F3C;
    }
    // 0x80040E1C: nop

L_80040E20:
    // 0x80040E20: lbu         $t3, 0x35($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X35);
    // 0x80040E24: nop

    // 0x80040E28: subu        $t7, $s0, $t3
    ctx->r15 = SUB32(ctx->r16, ctx->r11);
    // 0x80040E2C: addu        $t1, $sp, $t7
    ctx->r9 = ADD32(ctx->r29, ctx->r15);
    // 0x80040E30: lbu         $t1, 0x30($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X30);
    // 0x80040E34: nop

    // 0x80040E38: bne         $t1, $zero, L_80040F18
    if (ctx->r9 != 0) {
        // 0x80040E3C: nop
    
            goto L_80040F18;
    }
    // 0x80040E3C: nop

    // 0x80040E40: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80040E44: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x80040E48: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80040E4C: addu        $t0, $s1, $t5
    ctx->r8 = ADD32(ctx->r17, ctx->r13);
    // 0x80040E50: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80040E54: lw          $t4, 0x1F30($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F30);
    // 0x80040E58: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80040E5C: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x80040E60: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x80040E64: lbu         $t8, 0x0($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X0);
    // 0x80040E68: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80040E6C: bne         $t8, $at, L_80040F18
    if (ctx->r24 != ctx->r1) {
        // 0x80040E70: nop
    
            goto L_80040F18;
    }
    // 0x80040E70: nop

    // 0x80040E74: lbu         $s2, 0x34($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X34);
    // 0x80040E78: nop

    // 0x80040E7C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80040E80: andi        $t2, $s2, 0xFF
    ctx->r10 = ctx->r18 & 0XFF;
    // 0x80040E84: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x80040E88: slti        $at, $s2, 0x14
    ctx->r1 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
    // 0x80040E8C: beq         $at, $zero, L_80040F3C
    if (ctx->r1 == 0) {
        // 0x80040E90: nop
    
            goto L_80040F3C;
    }
    // 0x80040E90: nop

L_80040E94:
    // 0x80040E94: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x80040E98: addu        $t7, $t7, $s2
    ctx->r15 = ADD32(ctx->r15, ctx->r18);
    // 0x80040E9C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80040EA0: addu        $t1, $s1, $t7
    ctx->r9 = ADD32(ctx->r17, ctx->r15);
    // 0x80040EA4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80040EA8: lw          $t3, 0x1F30($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F30);
    // 0x80040EAC: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x80040EB0: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x80040EB4: addu        $t0, $t3, $t5
    ctx->r8 = ADD32(ctx->r11, ctx->r13);
    // 0x80040EB8: lbu         $t4, 0x0($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X0);
    // 0x80040EBC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80040EC0: bne         $t4, $at, L_80040F3C
    if (ctx->r12 != ctx->r1) {
        // 0x80040EC4: nop
    
            goto L_80040F3C;
    }
    // 0x80040EC4: nop

    // 0x80040EC8: addiu       $s5, $s5, -0xC
    ctx->r21 = ADD32(ctx->r21, -0XC);
    // 0x80040ECC: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x80040ED0: lb          $t8, 0x47($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X47);
    // 0x80040ED4: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
    // 0x80040ED8: sra         $t9, $s5, 16
    ctx->r25 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80040EDC: bne         $s1, $t8, L_80040EF8
    if (ctx->r17 != ctx->r24) {
        // 0x80040EE0: or          $s5, $t9, $zero
        ctx->r21 = ctx->r25 | 0;
            goto L_80040EF8;
    }
    // 0x80040EE0: or          $s5, $t9, $zero
    ctx->r21 = ctx->r25 | 0;
    // 0x80040EE4: addiu       $s5, $s5, -0xC
    ctx->r21 = ADD32(ctx->r21, -0XC);
    // 0x80040EE8: sll         $t2, $s5, 16
    ctx->r10 = S32(ctx->r21 << 16);
    // 0x80040EEC: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
    // 0x80040EF0: sra         $t7, $s5, 16
    ctx->r15 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80040EF4: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
L_80040EF8:
    // 0x80040EF8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80040EFC: andi        $t1, $s2, 0xFF
    ctx->r9 = ctx->r18 & 0XFF;
    // 0x80040F00: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x80040F04: slti        $at, $s2, 0x14
    ctx->r1 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
    // 0x80040F08: bne         $at, $zero, L_80040E94
    if (ctx->r1 != 0) {
        // 0x80040F0C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80040E94;
    }
    // 0x80040F0C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80040F10: b           L_80040F3C
    // 0x80040F14: nop

        goto L_80040F3C;
    // 0x80040F14: nop

L_80040F18:
    // 0x80040F18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80040F1C: sll         $t3, $s0, 24
    ctx->r11 = S32(ctx->r16 << 24);
    // 0x80040F20: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80040F24: lbu         $t0, 0x34($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X34);
    // 0x80040F28: sra         $t5, $s0, 24
    ctx->r13 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80040F2C: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x80040F30: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80040F34: beq         $at, $zero, L_80040E20
    if (ctx->r1 == 0) {
        // 0x80040F38: nop
    
            goto L_80040E20;
    }
    // 0x80040F38: nop

L_80040F3C:
    // 0x80040F3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80040F40: lbu         $t6, 0x36($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X36);
    // 0x80040F44: andi        $t4, $s1, 0xFF
    ctx->r12 = ctx->r17 & 0XFF;
    // 0x80040F48: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x80040F4C: slt         $at, $t6, $s1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80040F50: beq         $at, $zero, L_80040E08
    if (ctx->r1 == 0) {
        // 0x80040F54: nop
    
            goto L_80040E08;
    }
    // 0x80040F54: nop

L_80040F58:
    // 0x80040F58: beq         $s3, $zero, L_80040F74
    if (ctx->r19 == 0) {
        // 0x80040F5C: nop
    
            goto L_80040F74;
    }
    // 0x80040F5C: nop

    // 0x80040F60: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x80040F64: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x80040F68: or          $s5, $t9, $zero
    ctx->r21 = ctx->r25 | 0;
    // 0x80040F6C: sra         $t8, $s5, 16
    ctx->r24 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80040F70: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
L_80040F74:
    // 0x80040F74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80040F78: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80040F7C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80040F80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80040F84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80040F88: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80040F8C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80040F90: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80040F94: jr          $ra
    // 0x80040F98: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80040F98: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void aisquarelist_BuildCandidateMoves(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040F9C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80040FA0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80040FA4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80040FA8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80040FAC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80040FB0: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80040FB4: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80040FB8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80040FBC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80040FC0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80040FC4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80040FC8: jal         0x80041E88
    // 0x80040FCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    aisquarelist_ClearCandidates(rdram, ctx);
        goto after_0;
    // 0x80040FCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80040FD0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80040FD4: lw          $t6, 0x1F20($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F20);
    // 0x80040FD8: lbu         $t7, 0x4F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4F);
    // 0x80040FDC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80040FE0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80040FE4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80040FE8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80040FEC: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80040FF0: beq         $at, $zero, L_80041134
    if (ctx->r1 == 0) {
        // 0x80040FF4: slti        $at, $s4, 0xC8
        ctx->r1 = SIGNED(ctx->r20) < 0XC8 ? 1 : 0;
            goto L_80041134;
    }
L_80040FF4:
    // 0x80040FF4: slti        $at, $s4, 0xC8
    ctx->r1 = SIGNED(ctx->r20) < 0XC8 ? 1 : 0;
    // 0x80040FF8: bne         $at, $zero, L_80041008
    if (ctx->r1 != 0) {
        // 0x80040FFC: nop
    
            goto L_80041008;
    }
    // 0x80040FFC: nop

    // 0x80041000: b           L_80041134
    // 0x80041004: addiu       $s4, $zero, 0xC8
    ctx->r20 = ADD32(0, 0XC8);
        goto L_80041134;
    // 0x80041004: addiu       $s4, $zero, 0xC8
    ctx->r20 = ADD32(0, 0XC8);
L_80041008:
    // 0x80041008: lbu         $t1, 0x4F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4F);
    // 0x8004100C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80041010: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80041014: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80041018: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8004101C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80041020: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80041024: lw          $t0, 0x1F20($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1F20);
    // 0x80041028: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8004102C: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80041030: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x80041034: subu        $t4, $t4, $s3
    ctx->r12 = SUB32(ctx->r12, ctx->r19);
    // 0x80041038: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8004103C: addu        $s7, $t3, $t4
    ctx->r23 = ADD32(ctx->r11, ctx->r12);
    // 0x80041040: lbu         $s0, 0x2($s7)
    ctx->r16 = MEM_BU(ctx->r23, 0X2);
    // 0x80041044: lbu         $s1, 0x3($s7)
    ctx->r17 = MEM_BU(ctx->r23, 0X3);
    // 0x80041048: lbu         $s2, 0x4($s7)
    ctx->r18 = MEM_BU(ctx->r23, 0X4);
    // 0x8004104C: addiu       $s7, $s7, 0x2
    ctx->r23 = ADD32(ctx->r23, 0X2);
    // 0x80041050: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80041054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80041058: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8004105C: jal         0x800413C0
    // 0x80041060: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_1;
    // 0x80041060: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x80041064: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80041068: lw          $t5, 0x1F40($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F40);
    // 0x8004106C: sll         $t7, $s4, 3
    ctx->r15 = S32(ctx->r20 << 3);
    // 0x80041070: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80041074: nop

    // 0x80041078: addu        $s6, $t6, $t7
    ctx->r22 = ADD32(ctx->r14, ctx->r15);
    // 0x8004107C: sb          $s0, 0x2($s6)
    MEM_B(0X2, ctx->r22) = ctx->r16;
    // 0x80041080: sb          $s1, 0x3($s6)
    MEM_B(0X3, ctx->r22) = ctx->r17;
    // 0x80041084: sb          $s2, 0x4($s6)
    MEM_B(0X4, ctx->r22) = ctx->r18;
    // 0x80041088: lb          $a1, 0x53($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X53);
    // 0x8004108C: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    // 0x80041090: jal         0x80040930
    // 0x80041094: nop

    aisquarelist_ComputePlacementBounds(rdram, ctx);
        goto after_2;
    // 0x80041094: nop

    after_2:
    // 0x80041098: sh          $v0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r2;
    // 0x8004109C: lbu         $t8, 0x4B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4B);
    // 0x800410A0: nop

    // 0x800410A4: bne         $t8, $zero, L_800410D4
    if (ctx->r24 != 0) {
        // 0x800410A8: nop
    
            goto L_800410D4;
    }
    // 0x800410A8: nop

    // 0x800410AC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800410B0: lw          $a0, 0x5E04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5E04);
    // 0x800410B4: jal         0x8003E55C
    // 0x800410B8: addiu       $a0, $a0, 0x2E
    ctx->r4 = ADD32(ctx->r4, 0X2E);
    aisquarelist_AllSquaresComplete(rdram, ctx);
        goto after_3;
    // 0x800410B8: addiu       $a0, $a0, 0x2E
    ctx->r4 = ADD32(ctx->r4, 0X2E);
    after_3:
    // 0x800410BC: bne         $v0, $zero, L_800410D4
    if (ctx->r2 != 0) {
        // 0x800410C0: nop
    
            goto L_800410D4;
    }
    // 0x800410C0: nop

    // 0x800410C4: lh          $t9, 0x0($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X0);
    // 0x800410C8: nop

    // 0x800410CC: addiu       $t1, $t9, -0x32
    ctx->r9 = ADD32(ctx->r25, -0X32);
    // 0x800410D0: sh          $t1, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r9;
L_800410D4:
    // 0x800410D4: addiu       $a0, $s6, 0x5
    ctx->r4 = ADD32(ctx->r22, 0X5);
    // 0x800410D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800410DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800410E0: jal         0x80040784
    // 0x800410E4: addiu       $a3, $s6, 0x6
    ctx->r7 = ADD32(ctx->r22, 0X6);
    aisquarelist_GetPieceBounds(rdram, ctx);
        goto after_4;
    // 0x800410E4: addiu       $a3, $s6, 0x6
    ctx->r7 = ADD32(ctx->r22, 0X6);
    after_4:
    // 0x800410E8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800410EC: andi        $t0, $s4, 0xFF
    ctx->r8 = ctx->r20 & 0XFF;
    // 0x800410F0: or          $s4, $t0, $zero
    ctx->r20 = ctx->r8 | 0;
    // 0x800410F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800410F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800410FC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80041100: jal         0x800413C0
    // 0x80041104: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_5;
    // 0x80041104: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_5:
    // 0x80041108: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8004110C: lw          $t3, 0x1F20($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1F20);
    // 0x80041110: lbu         $t4, 0x4F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4F);
    // 0x80041114: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80041118: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004111C: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80041120: andi        $t2, $s3, 0xFF
    ctx->r10 = ctx->r19 & 0XFF;
    // 0x80041124: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
    // 0x80041128: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8004112C: bne         $at, $zero, L_80040FF4
    if (ctx->r1 != 0) {
        // 0x80041130: nop
    
            goto L_80040FF4;
    }
    // 0x80041130: nop

L_80041134:
    // 0x80041134: jal         0x800423F0
    // 0x80041138: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    aisquarelist_SortCandidates(rdram, ctx);
        goto after_6;
    // 0x80041138: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x8004113C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80041140: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041144: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80041148: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004114C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80041150: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80041154: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80041158: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8004115C: jr          $ra
    // 0x80041160: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80041160: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80041164: nop

    // 0x80041168: nop

    // 0x8004116C: nop

;}

RECOMP_FUNC void aisquarelist_ClassifyCell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041170: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80041174: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80041178: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8004117C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80041180: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80041184: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80041188: beq         $t6, $zero, L_800411A4
    if (ctx->r14 == 0) {
        // 0x8004118C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800411A4;
    }
    // 0x8004118C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80041190: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80041194: lw          $t7, -0x430($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X430);
    // 0x80041198: nop

    // 0x8004119C: bne         $t7, $zero, L_800411AC
    if (ctx->r15 != 0) {
        // 0x800411A0: nop
    
            goto L_800411AC;
    }
    // 0x800411A0: nop

L_800411A4:
    // 0x800411A4: b           L_80041248
    // 0x800411A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80041248;
    // 0x800411A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800411AC:
    // 0x800411AC: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x800411B0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800411B4: lw          $t8, -0x430($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X430);
    // 0x800411B8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800411BC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800411C0: lw          $s1, 0x4($t1)
    ctx->r17 = MEM_W(ctx->r9, 0X4);
    // 0x800411C4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800411C8: lbu         $t2, 0x1($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1);
    // 0x800411CC: nop

    // 0x800411D0: bne         $t2, $at, L_800411F8
    if (ctx->r10 != ctx->r1) {
        // 0x800411D4: nop
    
            goto L_800411F8;
    }
    // 0x800411D4: nop

    // 0x800411D8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800411DC: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x800411E0: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
    // 0x800411E4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800411E8: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x800411EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800411F0: b           L_80041238
    // 0x800411F4: sb          $t5, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r13;
        goto L_80041238;
    // 0x800411F4: sb          $t5, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r13;
L_800411F8:
    // 0x800411F8: lbu         $a0, 0x3($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X3);
    // 0x800411FC: jal         0x8006AB84
    // 0x80041200: nop

    Multisquare_IsValidIndex(rdram, ctx);
        goto after_0;
    // 0x80041200: nop

    after_0:
    // 0x80041204: beq         $v0, $zero, L_8004121C
    if (ctx->r2 == 0) {
        // 0x80041208: nop
    
            goto L_8004121C;
    }
    // 0x80041208: nop

    // 0x8004120C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80041210: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80041214: b           L_80041228
    // 0x80041218: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
        goto L_80041228;
    // 0x80041218: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
L_8004121C:
    // 0x8004121C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80041220: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x80041224: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
L_80041228:
    // 0x80041228: lbu         $t1, 0x1($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X1);
    // 0x8004122C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80041230: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80041234: sb          $t1, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r9;
L_80041238:
    // 0x80041238: lbu         $t3, 0x2($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X2);
    // 0x8004123C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80041240: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80041244: sb          $t3, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r11;
L_80041248:
    // 0x80041248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004124C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80041250: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80041254: jr          $ra
    // 0x80041258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80041258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004125C: nop

;}

RECOMP_FUNC void aisquarelist_CreateState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041268: jal         0x8007E03C
    // 0x8004126C: addiu       $a0, $zero, 0x264
    ctx->r4 = ADD32(0, 0X264);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8004126C: addiu       $a0, $zero, 0x264
    ctx->r4 = ADD32(0, 0X264);
    after_0:
    // 0x80041270: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80041274: sw          $v0, 0x1F30($at)
    MEM_W(0X1F30, ctx->r1) = ctx->r2;
    // 0x80041278: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8004127C: lw          $a0, 0x1F30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F30);
    // 0x80041280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80041284: jal         0x80050650
    // 0x80041288: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    Ids_Init(rdram, ctx);
        goto after_1;
    // 0x80041288: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    after_1:
    // 0x8004128C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041294: jr          $ra
    // 0x80041298: nop

    return;
    // 0x80041298: nop

;}

RECOMP_FUNC void aisquarelist_DestroyState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004129C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800412A0: lw          $t6, 0x1F30($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F30);
    // 0x800412A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800412A8: beq         $t6, $zero, L_800412D0
    if (ctx->r14 == 0) {
        // 0x800412AC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800412D0;
    }
    // 0x800412AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800412B0: jal         0x800506D0
    // 0x800412B4: addiu       $a0, $t6, 0x258
    ctx->r4 = ADD32(ctx->r14, 0X258);
    Ids_Deinit(rdram, ctx);
        goto after_0;
    // 0x800412B4: addiu       $a0, $t6, 0x258
    ctx->r4 = ADD32(ctx->r14, 0X258);
    after_0:
    // 0x800412B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800412BC: lw          $a0, 0x1F30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F30);
    // 0x800412C0: jal         0x8007E328
    // 0x800412C4: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x800412C4: nop

    after_1:
    // 0x800412C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800412CC: sw          $zero, 0x1F30($at)
    MEM_W(0X1F30, ctx->r1) = 0;
L_800412D0:
    // 0x800412D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800412D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800412D8: jr          $ra
    // 0x800412DC: nop

    return;
    // 0x800412DC: nop

;}

RECOMP_FUNC void aisquarelist_BuildBoardModel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800412E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800412E4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800412E8: lw          $t6, 0x1F30($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F30);
    // 0x800412EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800412F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800412F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800412F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800412FC: beq         $t6, $zero, L_800413A8
    if (ctx->r14 == 0) {
        // 0x80041300: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800413A8;
    }
    // 0x80041300: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80041304: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80041308: slti        $at, $s1, 0xC8
    ctx->r1 = SIGNED(ctx->r17) < 0XC8 ? 1 : 0;
    // 0x8004130C: beq         $at, $zero, L_80041378
    if (ctx->r1 == 0) {
        // 0x80041310: nop
    
            goto L_80041378;
    }
    // 0x80041310: nop

L_80041314:
    // 0x80041314: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80041318: lw          $t7, 0x1F30($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F30);
    // 0x8004131C: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80041320: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80041324: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80041328: jal         0x80041170
    // 0x8004132C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    aisquarelist_ClassifyCell(rdram, ctx);
        goto after_0;
    // 0x8004132C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80041330: beq         $v0, $zero, L_80041360
    if (ctx->r2 == 0) {
        // 0x80041334: nop
    
            goto L_80041360;
    }
    // 0x80041334: nop

    // 0x80041338: bne         $s0, $zero, L_80041354
    if (ctx->r16 != 0) {
        // 0x8004133C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80041354;
    }
    // 0x8004133C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80041340: div         $zero, $s1, $at
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r1)));
    // 0x80041344: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80041348: mflo        $t9
    ctx->r25 = lo;
    // 0x8004134C: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x80041350: nop

L_80041354:
    // 0x80041354: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80041358: andi        $t1, $s0, 0xFF
    ctx->r9 = ctx->r16 & 0XFF;
    // 0x8004135C: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_80041360:
    // 0x80041360: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80041364: andi        $t2, $s1, 0xFF
    ctx->r10 = ctx->r17 & 0XFF;
    // 0x80041368: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x8004136C: slti        $at, $s1, 0xC8
    ctx->r1 = SIGNED(ctx->r17) < 0XC8 ? 1 : 0;
    // 0x80041370: bne         $at, $zero, L_80041314
    if (ctx->r1 != 0) {
        // 0x80041374: nop
    
            goto L_80041314;
    }
    // 0x80041374: nop

L_80041378:
    // 0x80041378: bne         $s0, $zero, L_8004138C
    if (ctx->r16 != 0) {
        // 0x8004137C: nop
    
            goto L_8004138C;
    }
    // 0x8004137C: nop

    // 0x80041380: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80041384: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80041388: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
L_8004138C:
    // 0x8004138C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80041390: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80041394: lw          $a1, -0x430($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X430);
    // 0x80041398: lw          $a0, 0x1F30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F30);
    // 0x8004139C: addiu       $a1, $a1, 0x1608
    ctx->r5 = ADD32(ctx->r5, 0X1608);
    // 0x800413A0: jal         0x800508EC
    // 0x800413A4: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    Ids_CopyFrom(rdram, ctx);
        goto after_1;
    // 0x800413A4: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    after_1:
L_800413A8:
    // 0x800413A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800413AC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800413B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800413B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800413B8: jr          $ra
    // 0x800413BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800413BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void aisquarelist_PlacePieceOnModel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800413C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800413C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800413C8: lw          $t6, -0x490($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X490);
    // 0x800413CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800413D0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800413D4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800413D8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800413DC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800413E0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800413E4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800413E8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800413EC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800413F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800413F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800413F8: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x800413FC: nop

    // 0x80041400: slti        $at, $t7, 0x7
    ctx->r1 = SIGNED(ctx->r15) < 0X7 ? 1 : 0;
    // 0x80041404: bne         $at, $zero, L_80041414
    if (ctx->r1 != 0) {
        // 0x80041408: nop
    
            goto L_80041414;
    }
    // 0x80041408: nop

    // 0x8004140C: b           L_800416A8
    // 0x80041410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800416A8;
    // 0x80041410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80041414:
    // 0x80041414: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80041418: lw          $t8, -0x490($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X490);
    // 0x8004141C: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
    // 0x80041420: lbu         $t9, 0x13($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X13);
    // 0x80041424: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80041428: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004142C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80041430: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80041434: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80041438: addiu       $t4, $t4, 0x5CF0
    ctx->r12 = ADD32(ctx->r12, 0X5CF0);
    // 0x8004143C: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80041440: beq         $at, $zero, L_8004151C
    if (ctx->r1 == 0) {
        // 0x80041444: addu        $s0, $t3, $t4
        ctx->r16 = ADD32(ctx->r11, ctx->r12);
            goto L_8004151C;
    }
    // 0x80041444: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
L_80041448:
    // 0x80041448: addu        $t5, $s0, $s1
    ctx->r13 = ADD32(ctx->r16, ctx->r17);
    // 0x8004144C: lb          $t6, 0x0($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X0);
    // 0x80041450: lbu         $t7, 0x43($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X43);
    // 0x80041454: addu        $t1, $s0, $s1
    ctx->r9 = ADD32(ctx->r16, ctx->r17);
    // 0x80041458: lb          $t0, 0x4($t1)
    ctx->r8 = MEM_B(ctx->r9, 0X4);
    // 0x8004145C: lbu         $t2, 0x47($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X47);
    // 0x80041460: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    // 0x80041464: sll         $t8, $s2, 24
    ctx->r24 = S32(ctx->r18 << 24);
    // 0x80041468: addu        $s3, $t0, $t2
    ctx->r19 = ADD32(ctx->r8, ctx->r10);
    // 0x8004146C: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x80041470: sll         $t3, $s3, 24
    ctx->r11 = S32(ctx->r19 << 24);
    // 0x80041474: sra         $t9, $s2, 24
    ctx->r25 = S32(SIGNED(ctx->r18) >> 24);
    // 0x80041478: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x8004147C: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x80041480: sra         $t4, $s3, 24
    ctx->r12 = S32(SIGNED(ctx->r19) >> 24);
    // 0x80041484: bltz        $s2, L_800414A8
    if (SIGNED(ctx->r18) < 0) {
        // 0x80041488: or          $s3, $t4, $zero
        ctx->r19 = ctx->r12 | 0;
            goto L_800414A8;
    }
    // 0x80041488: or          $s3, $t4, $zero
    ctx->r19 = ctx->r12 | 0;
    // 0x8004148C: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x80041490: beq         $at, $zero, L_800414A8
    if (ctx->r1 == 0) {
        // 0x80041494: nop
    
            goto L_800414A8;
    }
    // 0x80041494: nop

    // 0x80041498: bltz        $s3, L_800414A8
    if (SIGNED(ctx->r19) < 0) {
        // 0x8004149C: slti        $at, $s3, 0x14
        ctx->r1 = SIGNED(ctx->r19) < 0X14 ? 1 : 0;
            goto L_800414A8;
    }
    // 0x8004149C: slti        $at, $s3, 0x14
    ctx->r1 = SIGNED(ctx->r19) < 0X14 ? 1 : 0;
    // 0x800414A0: bne         $at, $zero, L_800414B0
    if (ctx->r1 != 0) {
        // 0x800414A4: nop
    
            goto L_800414B0;
    }
    // 0x800414A4: nop

L_800414A8:
    // 0x800414A8: b           L_800416A8
    // 0x800414AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800416A8;
    // 0x800414AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800414B0:
    // 0x800414B0: lbu         $t5, 0x4F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4F);
    // 0x800414B4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800414B8: bne         $t5, $at, L_800414FC
    if (ctx->r13 != ctx->r1) {
        // 0x800414BC: nop
    
            goto L_800414FC;
    }
    // 0x800414BC: nop

    // 0x800414C0: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x800414C4: addu        $t7, $t7, $s3
    ctx->r15 = ADD32(ctx->r15, ctx->r19);
    // 0x800414C8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800414CC: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x800414D0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800414D4: lw          $t6, 0x1F30($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F30);
    // 0x800414D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800414DC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800414E0: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x800414E4: lbu         $t0, 0x0($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X0);
    // 0x800414E8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800414EC: beq         $t0, $at, L_800414FC
    if (ctx->r8 == ctx->r1) {
        // 0x800414F0: nop
    
            goto L_800414FC;
    }
    // 0x800414F0: nop

    // 0x800414F4: b           L_800416A8
    // 0x800414F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800416A8;
    // 0x800414F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800414FC:
    // 0x800414FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80041500: sll         $t2, $s1, 24
    ctx->r10 = S32(ctx->r17 << 24);
    // 0x80041504: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x80041508: sra         $t3, $s1, 24
    ctx->r11 = S32(SIGNED(ctx->r17) >> 24);
    // 0x8004150C: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80041510: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80041514: bne         $at, $zero, L_80041448
    if (ctx->r1 != 0) {
        // 0x80041518: nop
    
            goto L_80041448;
    }
    // 0x80041518: nop

L_8004151C:
    // 0x8004151C: lbu         $t4, 0x4F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4F);
    // 0x80041520: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80041524: bne         $t4, $at, L_8004155C
    if (ctx->r12 != ctx->r1) {
        // 0x80041528: nop
    
            goto L_8004155C;
    }
    // 0x80041528: nop

    // 0x8004152C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80041530: lw          $a0, 0x1F30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F30);
    // 0x80041534: jal         0x80050714
    // 0x80041538: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    can_run_out_of_ids(rdram, ctx);
        goto after_0;
    // 0x80041538: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    after_0:
    // 0x8004153C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80041540: lw          $a0, 0x1F30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F30);
    // 0x80041544: andi        $s5, $v0, 0xFF
    ctx->r21 = ctx->r2 & 0XFF;
    // 0x80041548: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8004154C: jal         0x80050800
    // 0x80041550: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    Ids_IncRef(rdram, ctx);
        goto after_1;
    // 0x80041550: addiu       $a0, $a0, 0x258
    ctx->r4 = ADD32(ctx->r4, 0X258);
    after_1:
    // 0x80041554: b           L_800415D8
    // 0x80041558: nop

        goto L_800415D8;
    // 0x80041558: nop

L_8004155C:
    // 0x8004155C: lbu         $t5, 0x4F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4F);
    // 0x80041560: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80041564: bne         $t5, $at, L_800415D8
    if (ctx->r13 != ctx->r1) {
        // 0x80041568: nop
    
            goto L_800415D8;
    }
    // 0x80041568: nop

    // 0x8004156C: lb          $t1, 0x4($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X4);
    // 0x80041570: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x80041574: lb          $t7, 0x0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X0);
    // 0x80041578: addu        $s3, $t1, $t0
    ctx->r19 = ADD32(ctx->r9, ctx->r8);
    // 0x8004157C: lbu         $t8, 0x43($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X43);
    // 0x80041580: sll         $t2, $s3, 24
    ctx->r10 = S32(ctx->r19 << 24);
    // 0x80041584: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
    // 0x80041588: sra         $t3, $s3, 24
    ctx->r11 = S32(SIGNED(ctx->r19) >> 24);
    // 0x8004158C: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x80041590: sll         $t6, $s2, 24
    ctx->r14 = S32(ctx->r18 << 24);
    // 0x80041594: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x80041598: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x8004159C: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x800415A0: sra         $t9, $s2, 24
    ctx->r25 = S32(SIGNED(ctx->r18) >> 24);
    // 0x800415A4: addu        $t5, $t5, $s3
    ctx->r13 = ADD32(ctx->r13, ctx->r19);
    // 0x800415A8: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x800415AC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800415B0: addu        $t7, $s2, $t5
    ctx->r15 = ADD32(ctx->r18, ctx->r13);
    // 0x800415B4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800415B8: lw          $t4, 0x1F30($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F30);
    // 0x800415BC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800415C0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800415C4: addu        $s4, $t4, $t8
    ctx->r20 = ADD32(ctx->r12, ctx->r24);
    // 0x800415C8: lbu         $a1, 0x2($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0X2);
    // 0x800415CC: jal         0x80050840
    // 0x800415D0: addiu       $a0, $t4, 0x258
    ctx->r4 = ADD32(ctx->r12, 0X258);
    Ids_DecRef(rdram, ctx);
        goto after_2;
    // 0x800415D0: addiu       $a0, $t4, 0x258
    ctx->r4 = ADD32(ctx->r12, 0X258);
    after_2:
    // 0x800415D4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_800415D8:
    // 0x800415D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800415DC: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x800415E0: beq         $at, $zero, L_800416A4
    if (ctx->r1 == 0) {
        // 0x800415E4: nop
    
            goto L_800416A4;
    }
    // 0x800415E4: nop

L_800415E8:
    // 0x800415E8: addu        $t3, $s0, $s1
    ctx->r11 = ADD32(ctx->r16, ctx->r17);
    // 0x800415EC: lb          $t5, 0x4($t3)
    ctx->r13 = MEM_B(ctx->r11, 0X4);
    // 0x800415F0: lbu         $t7, 0x47($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X47);
    // 0x800415F4: addu        $t6, $s0, $s1
    ctx->r14 = ADD32(ctx->r16, ctx->r17);
    // 0x800415F8: lb          $t9, 0x0($t6)
    ctx->r25 = MEM_B(ctx->r14, 0X0);
    // 0x800415FC: lbu         $t1, 0x43($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X43);
    // 0x80041600: addu        $s3, $t5, $t7
    ctx->r19 = ADD32(ctx->r13, ctx->r15);
    // 0x80041604: sll         $t8, $s3, 24
    ctx->r24 = S32(ctx->r19 << 24);
    // 0x80041608: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x8004160C: addu        $s2, $t9, $t1
    ctx->r18 = ADD32(ctx->r25, ctx->r9);
    // 0x80041610: sra         $t4, $s3, 24
    ctx->r12 = S32(SIGNED(ctx->r19) >> 24);
    // 0x80041614: sll         $t0, $s2, 24
    ctx->r8 = S32(ctx->r18 << 24);
    // 0x80041618: or          $s3, $t4, $zero
    ctx->r19 = ctx->r12 | 0;
    // 0x8004161C: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
    // 0x80041620: sll         $t9, $s3, 2
    ctx->r25 = S32(ctx->r19 << 2);
    // 0x80041624: sra         $t2, $s2, 24
    ctx->r10 = S32(SIGNED(ctx->r18) >> 24);
    // 0x80041628: addu        $t9, $t9, $s3
    ctx->r25 = ADD32(ctx->r25, ctx->r19);
    // 0x8004162C: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x80041630: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80041634: addu        $t1, $s2, $t9
    ctx->r9 = ADD32(ctx->r18, ctx->r25);
    // 0x80041638: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8004163C: lw          $t6, 0x1F30($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F30);
    // 0x80041640: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80041644: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x80041648: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x8004164C: addu        $s4, $t6, $t0
    ctx->r20 = ADD32(ctx->r14, ctx->r8);
    // 0x80041650: sb          $t2, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r10;
    // 0x80041654: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x80041658: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8004165C: bne         $t3, $at, L_8004167C
    if (ctx->r11 != ctx->r1) {
        // 0x80041660: nop
    
            goto L_8004167C;
    }
    // 0x80041660: nop

    // 0x80041664: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80041668: lw          $t5, -0x490($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X490);
    // 0x8004166C: nop

    // 0x80041670: lbu         $t7, 0x13($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X13);
    // 0x80041674: b           L_80041684
    // 0x80041678: sb          $t7, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r15;
        goto L_80041684;
    // 0x80041678: sb          $t7, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r15;
L_8004167C:
    // 0x8004167C: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80041680: sb          $t8, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r24;
L_80041684:
    // 0x80041684: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80041688: sll         $t4, $s1, 24
    ctx->r12 = S32(ctx->r17 << 24);
    // 0x8004168C: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x80041690: sra         $t9, $s1, 24
    ctx->r25 = S32(SIGNED(ctx->r17) >> 24);
    // 0x80041694: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80041698: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8004169C: bne         $at, $zero, L_800415E8
    if (ctx->r1 != 0) {
        // 0x800416A0: sb          $s5, 0x2($s4)
        MEM_B(0X2, ctx->r20) = ctx->r21;
            goto L_800415E8;
    }
    // 0x800416A0: sb          $s5, 0x2($s4)
    MEM_B(0X2, ctx->r20) = ctx->r21;
L_800416A4:
    // 0x800416A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800416A8:
    // 0x800416A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800416AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800416B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800416B4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800416B8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800416BC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800416C0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800416C4: jr          $ra
    // 0x800416C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800416C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void aisquarelist_TryPlacePiece(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800416CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800416D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800416D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800416D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800416DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800416E0: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x800416E4: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x800416E8: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x800416EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800416F0: jal         0x800413C0
    // 0x800416F4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_0;
    // 0x800416F4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
    // 0x800416F8: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800416FC: beq         $s0, $zero, L_80041718
    if (ctx->r16 == 0) {
        // 0x80041700: nop
    
            goto L_80041718;
    }
    // 0x80041700: nop

    // 0x80041704: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x80041708: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x8004170C: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x80041710: jal         0x800413C0
    // 0x80041714: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    aisquarelist_PlacePieceOnModel(rdram, ctx);
        goto after_1;
    // 0x80041714: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_1:
L_80041718:
    // 0x80041718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004171C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80041720: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041724: jr          $ra
    // 0x80041728: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80041728: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void aisquarelist_TryShiftPiece(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004172C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80041730: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80041734: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80041738: lw          $s0, -0x490($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X490);
    // 0x8004173C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80041740: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80041744: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80041748: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8004174C: lb          $t7, 0x2B($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X2B);
    // 0x80041750: lb          $t6, 0x11($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X11);
    // 0x80041754: lb          $t9, 0x12($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X12);
    // 0x80041758: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8004175C: sb          $t8, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r24;
    // 0x80041760: lb          $t0, 0x2F($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X2F);
    // 0x80041764: lbu         $t2, 0xA($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XA);
    // 0x80041768: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8004176C: sb          $t1, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r9;
    // 0x80041770: lb          $t3, 0x33($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X33);
    // 0x80041774: lb          $a0, 0x12($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X12);
    // 0x80041778: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004177C: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x80041780: sb          $t5, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r13;
    // 0x80041784: lbu         $a1, 0xA($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XA);
    // 0x80041788: lbu         $a2, 0x13($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X13);
    // 0x8004178C: jal         0x800408B0
    // 0x80041790: nop

    aisquarelist_CellBelongsToSquare(rdram, ctx);
        goto after_0;
    // 0x80041790: nop

    after_0:
    // 0x80041794: beq         $v0, $zero, L_800417A4
    if (ctx->r2 == 0) {
        // 0x80041798: nop
    
            goto L_800417A4;
    }
    // 0x80041798: nop

    // 0x8004179C: b           L_80041800
    // 0x800417A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041800;
    // 0x800417A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800417A4:
    // 0x800417A4: lb          $a0, 0x11($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X11);
    // 0x800417A8: lb          $a1, 0x12($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X12);
    // 0x800417AC: lbu         $a2, 0xA($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0XA);
    // 0x800417B0: jal         0x800416CC
    // 0x800417B4: nop

    aisquarelist_TryPlacePiece(rdram, ctx);
        goto after_1;
    // 0x800417B4: nop

    after_1:
    // 0x800417B8: bne         $v0, $zero, L_800417FC
    if (ctx->r2 != 0) {
        // 0x800417BC: nop
    
            goto L_800417FC;
    }
    // 0x800417BC: nop

    // 0x800417C0: lb          $t6, 0x11($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X11);
    // 0x800417C4: lb          $t7, 0x2B($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X2B);
    // 0x800417C8: lb          $t9, 0x12($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X12);
    // 0x800417CC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800417D0: sb          $t8, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r24;
    // 0x800417D4: lb          $t0, 0x2F($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X2F);
    // 0x800417D8: lbu         $t2, 0xA($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XA);
    // 0x800417DC: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800417E0: sb          $t1, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r9;
    // 0x800417E4: lb          $t3, 0x33($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X33);
    // 0x800417E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800417EC: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800417F0: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800417F4: b           L_80041800
    // 0x800417F8: sb          $t5, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r13;
        goto L_80041800;
    // 0x800417F8: sb          $t5, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r13;
L_800417FC:
    // 0x800417FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041800:
    // 0x80041800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80041804: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041808: jr          $ra
    // 0x8004180C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004180C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void aisquarelist_CanPieceMove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041810: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80041814: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80041818: lw          $t6, -0x490($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X490);
    // 0x8004181C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80041820: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x80041824: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80041828: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004182C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80041830: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80041834: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80041838: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004183C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80041840: lb          $s0, 0x11($t6)
    ctx->r16 = MEM_B(ctx->r14, 0X11);
    // 0x80041844: sb          $t7, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r15;
    // 0x80041848: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8004184C: lw          $t9, -0x490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X490);
    // 0x80041850: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x80041854: lb          $s1, 0x12($t6)
    ctx->r17 = MEM_B(ctx->r14, 0X12);
    // 0x80041858: lb          $s2, 0xA($t6)
    ctx->r18 = MEM_B(ctx->r14, 0XA);
    // 0x8004185C: sb          $t8, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r24;
    // 0x80041860: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80041864: lw          $t1, -0x490($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X490);
    // 0x80041868: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x8004186C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80041870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80041874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80041878: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8004187C: jal         0x8004172C
    // 0x80041880: sb          $t0, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r8;
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_0;
    // 0x80041880: sb          $t0, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r8;
    after_0:
    // 0x80041884: bne         $v0, $zero, L_800418D4
    if (ctx->r2 != 0) {
        // 0x80041888: nop
    
            goto L_800418D4;
    }
    // 0x80041888: nop

    // 0x8004188C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80041890: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80041894: jal         0x8004172C
    // 0x80041898: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_1;
    // 0x80041898: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8004189C: bne         $v0, $zero, L_800418D4
    if (ctx->r2 != 0) {
        // 0x800418A0: nop
    
            goto L_800418D4;
    }
    // 0x800418A0: nop

    // 0x800418A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800418A8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800418AC: jal         0x8004172C
    // 0x800418B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_2;
    // 0x800418B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800418B4: bne         $v0, $zero, L_800418D4
    if (ctx->r2 != 0) {
        // 0x800418B8: nop
    
            goto L_800418D4;
    }
    // 0x800418B8: nop

    // 0x800418BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800418C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800418C4: jal         0x8004172C
    // 0x800418C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    aisquarelist_TryShiftPiece(rdram, ctx);
        goto after_3;
    // 0x800418C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800418CC: beq         $v0, $zero, L_800418D8
    if (ctx->r2 == 0) {
        // 0x800418D0: nop
    
            goto L_800418D8;
    }
    // 0x800418D0: nop

L_800418D4:
    // 0x800418D4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800418D8:
    // 0x800418D8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800418DC: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x800418E0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800418E4: sb          $s0, 0x11($t2)
    MEM_B(0X11, ctx->r10) = ctx->r16;
    // 0x800418E8: lw          $t3, -0x490($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X490);
    // 0x800418EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800418F0: sb          $s1, 0x12($t3)
    MEM_B(0X12, ctx->r11) = ctx->r17;
    // 0x800418F4: lw          $t4, -0x490($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X490);
    // 0x800418F8: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800418FC: sb          $s2, 0xA($t4)
    MEM_B(0XA, ctx->r12) = ctx->r18;
    // 0x80041900: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80041904: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80041908: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8004190C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80041910: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80041914: jr          $ra
    // 0x80041918: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80041918: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void aisquarelist_IsColumnClearToTop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004191C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80041920: sll         $a2, $a1, 24
    ctx->r6 = S32(ctx->r5 << 24);
    // 0x80041924: sra         $t6, $a2, 24
    ctx->r14 = S32(SIGNED(ctx->r6) >> 24);
    // 0x80041928: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8004192C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80041930: bltz        $a2, L_80041990
    if (SIGNED(ctx->r6) < 0) {
        // 0x80041934: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_80041990;
    }
    // 0x80041934: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
L_80041938:
    // 0x80041938: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8004193C: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x80041940: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80041944: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80041948: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004194C: lw          $t7, 0x1F30($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F30);
    // 0x80041950: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80041954: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80041958: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x8004195C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80041960: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80041964: beq         $t2, $at, L_80041974
    if (ctx->r10 == ctx->r1) {
        // 0x80041968: nop
    
            goto L_80041974;
    }
    // 0x80041968: nop

    // 0x8004196C: b           L_80041994
    // 0x80041970: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80041994;
    // 0x80041970: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80041974:
    // 0x80041974: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80041978: sll         $t3, $a2, 24
    ctx->r11 = S32(ctx->r6 << 24);
    // 0x8004197C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80041980: sra         $t4, $a2, 24
    ctx->r12 = S32(SIGNED(ctx->r6) >> 24);
    // 0x80041984: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80041988: bgez        $a2, L_80041938
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8004198C: nop
    
            goto L_80041938;
    }
    // 0x8004198C: nop

L_80041990:
    // 0x80041990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041994:
    // 0x80041994: jr          $ra
    // 0x80041998: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80041998: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void aisquarelist_DropPieceToRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004199C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800419A0: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800419A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800419A8: lw          $t6, -0x490($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X490);
    // 0x800419AC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800419B0: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800419B4: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x800419B8: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x800419BC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800419C0: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800419C4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800419C8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800419CC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800419D0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800419D4: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800419D8: lb          $s2, 0x11($t6)
    ctx->r18 = MEM_B(ctx->r14, 0X11);
    // 0x800419DC: lb          $s1, 0x0($t7)
    ctx->r17 = MEM_B(ctx->r15, 0X0);
    // 0x800419E0: lb          $s3, 0x12($t6)
    ctx->r19 = MEM_B(ctx->r14, 0X12);
    // 0x800419E4: lb          $s4, 0xA($t6)
    ctx->r20 = MEM_B(ctx->r14, 0XA);
    // 0x800419E8: bltz        $s1, L_80041A68
    if (SIGNED(ctx->r17) < 0) {
        // 0x800419EC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80041A68;
    }
    // 0x800419EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800419F0:
    // 0x800419F0: lbu         $a1, 0x73($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X73);
    // 0x800419F4: lbu         $a3, 0x7B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X7B);
    // 0x800419F8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800419FC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80041A00: jal         0x8003F760
    // 0x80041A04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    aisquarelist_ResetMoveList(rdram, ctx);
        goto after_0;
    // 0x80041A04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80041A08: lbu         $a0, 0x73($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X73);
    // 0x80041A0C: lbu         $a2, 0x7B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X7B);
    // 0x80041A10: jal         0x800416CC
    // 0x80041A14: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    aisquarelist_TryPlacePiece(rdram, ctx);
        goto after_1;
    // 0x80041A14: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80041A18: sltu        $s5, $zero, $v0
    ctx->r21 = 0 < ctx->r2 ? 1 : 0;
    // 0x80041A1C: beq         $s5, $zero, L_80041A34
    if (ctx->r21 == 0) {
        // 0x80041A20: nop
    
            goto L_80041A34;
    }
    // 0x80041A20: nop

    // 0x80041A24: lbu         $a1, 0x7F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X7F);
    // 0x80041A28: jal         0x800400FC
    // 0x80041A2C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    aisquarelist_FindReachableMoves(rdram, ctx);
        goto after_2;
    // 0x80041A2C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x80041A30: sltu        $s5, $zero, $v0
    ctx->r21 = 0 < ctx->r2 ? 1 : 0;
L_80041A34:
    // 0x80041A34: andi        $s0, $s5, 0xFF
    ctx->r16 = ctx->r21 & 0XFF;
    // 0x80041A38: beq         $s0, $zero, L_80041A4C
    if (ctx->r16 == 0) {
        // 0x80041A3C: nop
    
            goto L_80041A4C;
    }
    // 0x80041A3C: nop

    // 0x80041A40: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80041A44: b           L_80041A68
    // 0x80041A48: sb          $s1, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r17;
        goto L_80041A68;
    // 0x80041A48: sb          $s1, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r17;
L_80041A4C:
    // 0x80041A4C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80041A50: sll         $t9, $s1, 24
    ctx->r25 = S32(ctx->r17 << 24);
    // 0x80041A54: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80041A58: sra         $t0, $s1, 24
    ctx->r8 = S32(SIGNED(ctx->r17) >> 24);
    // 0x80041A5C: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80041A60: bgez        $s1, L_800419F0
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80041A64: nop
    
            goto L_800419F0;
    }
    // 0x80041A64: nop

L_80041A68:
    // 0x80041A68: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80041A6C: lw          $t1, -0x490($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X490);
    // 0x80041A70: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80041A74: sb          $s2, 0x11($t1)
    MEM_B(0X11, ctx->r9) = ctx->r18;
    // 0x80041A78: lw          $t2, -0x490($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X490);
    // 0x80041A7C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80041A80: sb          $s3, 0x12($t2)
    MEM_B(0X12, ctx->r10) = ctx->r19;
    // 0x80041A84: lw          $t3, -0x490($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X490);
    // 0x80041A88: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80041A8C: sb          $s4, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r20;
    // 0x80041A90: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80041A94: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80041A98: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80041A9C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80041AA0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80041AA4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80041AA8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80041AAC: jr          $ra
    // 0x80041AB0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80041AB0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}

RECOMP_FUNC void aisquarelist_IsRowSpanFilled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041AB4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80041AB8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80041ABC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80041AC0: bne         $a1, $at, L_80041AD0
    if (ctx->r5 != ctx->r1) {
        // 0x80041AC4: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_80041AD0;
    }
    // 0x80041AC4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80041AC8: b           L_80041B40
    // 0x80041ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041B40;
    // 0x80041ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041AD0:
    // 0x80041AD0: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80041AD4: addiu       $t6, $a0, 0x4
    ctx->r14 = ADD32(ctx->r4, 0X4);
    // 0x80041AD8: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80041ADC: beq         $at, $zero, L_80041B3C
    if (ctx->r1 == 0) {
        // 0x80041AE0: nop
    
            goto L_80041B3C;
    }
    // 0x80041AE0: nop

L_80041AE4:
    // 0x80041AE4: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80041AE8: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80041AEC: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80041AF0: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80041AF4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80041AF8: lw          $t7, 0x1F30($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F30);
    // 0x80041AFC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80041B00: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80041B04: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80041B08: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80041B0C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80041B10: bne         $t2, $at, L_80041B20
    if (ctx->r10 != ctx->r1) {
        // 0x80041B14: nop
    
            goto L_80041B20;
    }
    // 0x80041B14: nop

    // 0x80041B18: b           L_80041B40
    // 0x80041B1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80041B40;
    // 0x80041B1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80041B20:
    // 0x80041B20: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80041B24: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x80041B28: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80041B2C: addiu       $t4, $a0, 0x4
    ctx->r12 = ADD32(ctx->r4, 0X4);
    // 0x80041B30: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80041B34: bne         $at, $zero, L_80041AE4
    if (ctx->r1 != 0) {
        // 0x80041B38: nop
    
            goto L_80041AE4;
    }
    // 0x80041B38: nop

L_80041B3C:
    // 0x80041B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041B40:
    // 0x80041B40: jr          $ra
    // 0x80041B44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80041B44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void aisquarelist_CheckSquareCompletion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041B48: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80041B4C: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x80041B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041B54: beq         $at, $zero, L_80041B68
    if (ctx->r1 == 0) {
        // 0x80041B58: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_80041B68;
    }
    // 0x80041B58: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80041B5C: slti        $at, $a1, 0x11
    ctx->r1 = SIGNED(ctx->r5) < 0X11 ? 1 : 0;
    // 0x80041B60: bne         $at, $zero, L_80041B70
    if (ctx->r1 != 0) {
        // 0x80041B64: nop
    
            goto L_80041B70;
    }
    // 0x80041B64: nop

L_80041B68:
    // 0x80041B68: b           L_80041D98
    // 0x80041B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80041D98;
    // 0x80041B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80041B70:
    // 0x80041B70: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80041B74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80041B78: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80041B7C: sb          $t6, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r14;
    // 0x80041B80: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80041B84: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80041B88: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x80041B8C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80041B90: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80041B94: lw          $t7, 0x1F30($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F30);
    // 0x80041B98: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80041B9C: addiu       $t9, $a1, 0x4
    ctx->r25 = ADD32(ctx->r5, 0X4);
    // 0x80041BA0: andi        $t1, $a1, 0xFF
    ctx->r9 = ctx->r5 & 0XFF;
    // 0x80041BA4: slt         $at, $t1, $t9
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80041BA8: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80041BAC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80041BB0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80041BB4: beq         $at, $zero, L_80041D40
    if (ctx->r1 == 0) {
        // 0x80041BB8: sw          $t8, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r24;
            goto L_80041D40;
    }
    // 0x80041BB8: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
L_80041BBC:
    // 0x80041BBC: andi        $t0, $a0, 0xFF
    ctx->r8 = ctx->r4 & 0XFF;
    // 0x80041BC0: addiu       $t7, $a0, 0x4
    ctx->r15 = ADD32(ctx->r4, 0X4);
    // 0x80041BC4: slt         $at, $t0, $t7
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80041BC8: beq         $at, $zero, L_80041D1C
    if (ctx->r1 == 0) {
        // 0x80041BCC: nop
    
            goto L_80041D1C;
    }
    // 0x80041BCC: nop

L_80041BD0:
    // 0x80041BD0: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80041BD4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80041BD8: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x80041BDC: nop

    // 0x80041BE0: bne         $t8, $at, L_80041BF0
    if (ctx->r24 != ctx->r1) {
        // 0x80041BE4: nop
    
            goto L_80041BF0;
    }
    // 0x80041BE4: nop

    // 0x80041BE8: b           L_80041D98
    // 0x80041BEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80041D98;
    // 0x80041BEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80041BF0:
    // 0x80041BF0: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x80041BF4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80041BF8: lbu         $t7, 0x0($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X0);
    // 0x80041BFC: nop

    // 0x80041C00: beq         $t7, $at, L_80041CF8
    if (ctx->r15 == ctx->r1) {
        // 0x80041C04: nop
    
            goto L_80041CF8;
    }
    // 0x80041C04: nop

    // 0x80041C08: lbu         $t6, 0x3($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3);
    // 0x80041C0C: nop

    // 0x80041C10: bne         $t6, $zero, L_80041C30
    if (ctx->r14 != 0) {
        // 0x80041C14: nop
    
            goto L_80041C30;
    }
    // 0x80041C14: nop

    // 0x80041C18: lbu         $t8, 0x1($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X1);
    // 0x80041C1C: nop

    // 0x80041C20: beq         $t4, $t8, L_80041C30
    if (ctx->r12 == ctx->r24) {
        // 0x80041C24: nop
    
            goto L_80041C30;
    }
    // 0x80041C24: nop

    // 0x80041C28: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80041C2C: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
L_80041C30:
    // 0x80041C30: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80041C34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80041C38: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80041C3C: beq         $at, $zero, L_80041C94
    if (ctx->r1 == 0) {
        // 0x80041C40: sb          $t6, 0x2($sp)
        MEM_B(0X2, ctx->r29) = ctx->r14;
            goto L_80041C94;
    }
    // 0x80041C40: sb          $t6, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r14;
L_80041C44:
    // 0x80041C44: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80041C48: addu        $t9, $sp, $t2
    ctx->r25 = ADD32(ctx->r29, ctx->r10);
    // 0x80041C4C: lbu         $t9, 0x8($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X8);
    // 0x80041C50: lbu         $t7, 0x2($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X2);
    // 0x80041C54: nop

    // 0x80041C58: bne         $t9, $t7, L_80041C7C
    if (ctx->r25 != ctx->r15) {
        // 0x80041C5C: nop
    
            goto L_80041C7C;
    }
    // 0x80041C5C: nop

    // 0x80041C60: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x80041C64: addu        $t8, $t2, $t6
    ctx->r24 = ADD32(ctx->r10, ctx->r14);
    // 0x80041C68: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80041C6C: addu        $t8, $t2, $t6
    ctx->r24 = ADD32(ctx->r10, ctx->r14);
    // 0x80041C70: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80041C74: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80041C78: sb          $zero, 0x2($sp)
    MEM_B(0X2, ctx->r29) = 0;
L_80041C7C:
    // 0x80041C7C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80041C80: andi        $t9, $t2, 0xFF
    ctx->r25 = ctx->r10 & 0XFF;
    // 0x80041C84: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x80041C88: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80041C8C: bne         $at, $zero, L_80041C44
    if (ctx->r1 != 0) {
        // 0x80041C90: nop
    
            goto L_80041C44;
    }
    // 0x80041C90: nop

L_80041C94:
    // 0x80041C94: lbu         $t6, 0x2($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2);
    // 0x80041C98: nop

    // 0x80041C9C: beq         $t6, $zero, L_80041CF8
    if (ctx->r14 == 0) {
        // 0x80041CA0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80041CF8;
    }
    // 0x80041CA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80041CA4: bne         $t3, $at, L_80041CB4
    if (ctx->r11 != ctx->r1) {
        // 0x80041CA8: nop
    
            goto L_80041CB4;
    }
    // 0x80041CA8: nop

    // 0x80041CAC: b           L_80041D98
    // 0x80041CB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80041D98;
    // 0x80041CB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80041CB4:
    // 0x80041CB4: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80041CB8: addu        $t9, $sp, $t3
    ctx->r25 = ADD32(ctx->r29, ctx->r11);
    // 0x80041CBC: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x80041CC0: addu        $t7, $sp, $t3
    ctx->r15 = ADD32(ctx->r29, ctx->r11);
    // 0x80041CC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80041CC8: sb          $t8, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r24;
    // 0x80041CCC: sb          $t6, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r14;
    // 0x80041CD0: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x80041CD4: sb          $zero, 0x3($sp)
    MEM_B(0X3, ctx->r29) = 0;
    // 0x80041CD8: lbu         $t4, 0x1($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X1);
    // 0x80041CDC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80041CE0: andi        $t8, $t3, 0xFF
    ctx->r24 = ctx->r11 & 0XFF;
    // 0x80041CE4: sllv        $t7, $t6, $t4
    ctx->r15 = S32(ctx->r14 << (ctx->r12 & 31));
    // 0x80041CE8: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
    // 0x80041CEC: or          $t5, $t5, $t7
    ctx->r13 = ctx->r13 | ctx->r15;
    // 0x80041CF0: andi        $t8, $t5, 0xFF
    ctx->r24 = ctx->r13 & 0XFF;
    // 0x80041CF4: or          $t5, $t8, $zero
    ctx->r13 = ctx->r24 | 0;
L_80041CF8:
    // 0x80041CF8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80041CFC: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80041D00: andi        $t9, $t0, 0xFF
    ctx->r25 = ctx->r8 & 0XFF;
    // 0x80041D04: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x80041D08: addiu       $t8, $a0, 0x4
    ctx->r24 = ADD32(ctx->r4, 0X4);
    // 0x80041D0C: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80041D10: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x80041D14: bne         $at, $zero, L_80041BD0
    if (ctx->r1 != 0) {
        // 0x80041D18: sw          $t7, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r15;
            goto L_80041BD0;
    }
    // 0x80041D18: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_80041D1C:
    // 0x80041D1C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80041D20: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x80041D24: andi        $t7, $t1, 0xFF
    ctx->r15 = ctx->r9 & 0XFF;
    // 0x80041D28: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x80041D2C: addiu       $t8, $a1, 0x4
    ctx->r24 = ADD32(ctx->r5, 0X4);
    // 0x80041D30: slt         $at, $t1, $t8
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80041D34: addiu       $t6, $t9, 0x12
    ctx->r14 = ADD32(ctx->r25, 0X12);
    // 0x80041D38: bne         $at, $zero, L_80041BBC
    if (ctx->r1 != 0) {
        // 0x80041D3C: sw          $t6, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r14;
            goto L_80041BBC;
    }
    // 0x80041D3C: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
L_80041D40:
    // 0x80041D40: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80041D44: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80041D48: beq         $at, $zero, L_80041D88
    if (ctx->r1 == 0) {
        // 0x80041D4C: nop
    
            goto L_80041D88;
    }
    // 0x80041D4C: nop

L_80041D50:
    // 0x80041D50: addu        $t9, $sp, $t2
    ctx->r25 = ADD32(ctx->r29, ctx->r10);
    // 0x80041D54: lbu         $t9, 0x4($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4);
    // 0x80041D58: nop

    // 0x80041D5C: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80041D60: beq         $at, $zero, L_80041D70
    if (ctx->r1 == 0) {
        // 0x80041D64: nop
    
            goto L_80041D70;
    }
    // 0x80041D64: nop

    // 0x80041D68: b           L_80041D98
    // 0x80041D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80041D98;
    // 0x80041D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80041D70:
    // 0x80041D70: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80041D74: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x80041D78: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x80041D7C: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80041D80: bne         $at, $zero, L_80041D50
    if (ctx->r1 != 0) {
        // 0x80041D84: nop
    
            goto L_80041D50;
    }
    // 0x80041D84: nop

L_80041D88:
    // 0x80041D88: sb          $t3, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r11;
    // 0x80041D8C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80041D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80041D94: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
L_80041D98:
    // 0x80041D98: jr          $ra
    // 0x80041D9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80041D9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void aisquarelist_CopyEntry3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041DA0: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80041DA4: nop

    // 0x80041DA8: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80041DAC: lb          $t7, 0x1($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1);
    // 0x80041DB0: nop

    // 0x80041DB4: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x80041DB8: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x80041DBC: jr          $ra
    // 0x80041DC0: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
    return;
    // 0x80041DC0: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
    // 0x80041DC4: nop

    // 0x80041DC8: nop

    // 0x80041DCC: nop

;}

RECOMP_FUNC void aisquarelist_AllocList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041DD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041DD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041DD8: jal         0x8007E03C
    // 0x80041DDC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80041DDC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80041DE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80041DE4: sw          $v0, 0x1F40($at)
    MEM_W(0X1F40, ctx->r1) = ctx->r2;
    // 0x80041DE8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80041DEC: lw          $t6, 0x1F40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F40);
    // 0x80041DF0: nop

    // 0x80041DF4: beq         $t6, $zero, L_80041E14
    if (ctx->r14 == 0) {
        // 0x80041DF8: nop
    
            goto L_80041E14;
    }
    // 0x80041DF8: nop

    // 0x80041DFC: jal         0x8007E03C
    // 0x80041E00: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80041E00: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_1:
    // 0x80041E04: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80041E08: lw          $t7, 0x1F40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F40);
    // 0x80041E0C: nop

    // 0x80041E10: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
L_80041E14:
    // 0x80041E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041E18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041E1C: jr          $ra
    // 0x80041E20: nop

    return;
    // 0x80041E20: nop

;}

RECOMP_FUNC void aisquarelist_FreeList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041E24: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80041E28: lw          $t6, 0x1F40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F40);
    // 0x80041E2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041E30: beq         $t6, $zero, L_80041E78
    if (ctx->r14 == 0) {
        // 0x80041E34: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80041E78;
    }
    // 0x80041E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041E38: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80041E3C: nop

    // 0x80041E40: beq         $t7, $zero, L_80041E60
    if (ctx->r15 == 0) {
        // 0x80041E44: nop
    
            goto L_80041E60;
    }
    // 0x80041E44: nop

    // 0x80041E48: jal         0x8007E328
    // 0x80041E4C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x80041E4C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x80041E50: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80041E54: lw          $t8, 0x1F40($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F40);
    // 0x80041E58: nop

    // 0x80041E5C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_80041E60:
    // 0x80041E60: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80041E64: lw          $a0, 0x1F40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F40);
    // 0x80041E68: jal         0x8007E328
    // 0x80041E6C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x80041E6C: nop

    after_1:
    // 0x80041E70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80041E74: sw          $zero, 0x1F40($at)
    MEM_W(0X1F40, ctx->r1) = 0;
L_80041E78:
    // 0x80041E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041E7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041E80: jr          $ra
    // 0x80041E84: nop

    return;
    // 0x80041E84: nop

;}

RECOMP_FUNC void aisquarelist_ClearCandidates(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041E88: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80041E8C: lw          $t6, 0x1F40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F40);
    // 0x80041E90: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80041E94: beq         $t6, $zero, L_80041EE8
    if (ctx->r14 == 0) {
        // 0x80041E98: nop
    
            goto L_80041EE8;
    }
    // 0x80041E98: nop

    // 0x80041E9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80041EA0: slti        $at, $a0, 0xC8
    ctx->r1 = SIGNED(ctx->r4) < 0XC8 ? 1 : 0;
    // 0x80041EA4: beq         $at, $zero, L_80041EE8
    if (ctx->r1 == 0) {
        // 0x80041EA8: nop
    
            goto L_80041EE8;
    }
    // 0x80041EA8: nop

L_80041EAC:
    // 0x80041EAC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80041EB0: lw          $t7, 0x1F40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F40);
    // 0x80041EB4: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x80041EB8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80041EBC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80041EC0: andi        $t1, $a0, 0xFF
    ctx->r9 = ctx->r4 & 0XFF;
    // 0x80041EC4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x80041EC8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80041ECC: slti        $at, $a0, 0xC8
    ctx->r1 = SIGNED(ctx->r4) < 0XC8 ? 1 : 0;
    // 0x80041ED0: addiu       $t0, $zero, -0x8000
    ctx->r8 = ADD32(0, -0X8000);
    // 0x80041ED4: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x80041ED8: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x80041EDC: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
    // 0x80041EE0: bne         $at, $zero, L_80041EAC
    if (ctx->r1 != 0) {
        // 0x80041EE4: sb          $zero, 0x4($a1)
        MEM_B(0X4, ctx->r5) = 0;
            goto L_80041EAC;
    }
    // 0x80041EE4: sb          $zero, 0x4($a1)
    MEM_B(0X4, ctx->r5) = 0;
L_80041EE8:
    // 0x80041EE8: jr          $ra
    // 0x80041EEC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80041EEC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void aisquarelist_SwapEntries(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041EF0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80041EF4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80041EF8: sh          $t6, 0x0($sp)
    MEM_H(0X0, ctx->r29) = ctx->r14;
    // 0x80041EFC: lbu         $t7, 0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2);
    // 0x80041F00: nop

    // 0x80041F04: sb          $t7, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r15;
    // 0x80041F08: lb          $t8, 0x3($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X3);
    // 0x80041F0C: nop

    // 0x80041F10: sb          $t8, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r24;
    // 0x80041F14: lbu         $t9, 0x4($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X4);
    // 0x80041F18: nop

    // 0x80041F1C: sb          $t9, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r25;
    // 0x80041F20: lbu         $t0, 0x5($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X5);
    // 0x80041F24: nop

    // 0x80041F28: sb          $t0, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r8;
    // 0x80041F2C: lbu         $t1, 0x6($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X6);
    // 0x80041F30: nop

    // 0x80041F34: sb          $t1, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r9;
    // 0x80041F38: lh          $t2, 0x0($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X0);
    // 0x80041F3C: nop

    // 0x80041F40: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // 0x80041F44: lbu         $t3, 0x2($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X2);
    // 0x80041F48: nop

    // 0x80041F4C: sb          $t3, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r11;
    // 0x80041F50: lb          $t4, 0x3($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X3);
    // 0x80041F54: nop

    // 0x80041F58: sb          $t4, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r12;
    // 0x80041F5C: lbu         $t5, 0x4($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X4);
    // 0x80041F60: nop

    // 0x80041F64: sb          $t5, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r13;
    // 0x80041F68: lbu         $t6, 0x5($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X5);
    // 0x80041F6C: nop

    // 0x80041F70: sb          $t6, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r14;
    // 0x80041F74: lbu         $t7, 0x6($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X6);
    // 0x80041F78: nop

    // 0x80041F7C: sb          $t7, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r15;
    // 0x80041F80: lh          $t8, 0x0($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X0);
    // 0x80041F84: nop

    // 0x80041F88: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80041F8C: lbu         $t9, 0x2($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2);
    // 0x80041F90: nop

    // 0x80041F94: sb          $t9, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r25;
    // 0x80041F98: lb          $t0, 0x3($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X3);
    // 0x80041F9C: nop

    // 0x80041FA0: sb          $t0, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r8;
    // 0x80041FA4: lbu         $t1, 0x4($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4);
    // 0x80041FA8: nop

    // 0x80041FAC: sb          $t1, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r9;
    // 0x80041FB0: lbu         $t2, 0x5($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X5);
    // 0x80041FB4: nop

    // 0x80041FB8: sb          $t2, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r10;
    // 0x80041FBC: lbu         $t3, 0x6($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X6);
    // 0x80041FC0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80041FC4: jr          $ra
    // 0x80041FC8: sb          $t3, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r11;
    return;
    // 0x80041FC8: sb          $t3, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r11;
;}

RECOMP_FUNC void aisquarelist_GetSortMetric(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041FCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80041FD0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80041FD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80041FD8: lbu         $s1, 0x2F($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X2F);
    // 0x80041FDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80041FE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80041FE4: beq         $s1, $zero, L_80042010
    if (ctx->r17 == 0) {
        // 0x80041FE8: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80042010;
    }
    // 0x80041FE8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80041FEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80041FF0: beq         $s1, $at, L_80042024
    if (ctx->r17 == ctx->r1) {
        // 0x80041FF4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80042024;
    }
    // 0x80041FF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80041FF8: beq         $s1, $at, L_80042038
    if (ctx->r17 == ctx->r1) {
        // 0x80041FFC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80042038;
    }
    // 0x80041FFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80042000: beq         $s1, $at, L_80042084
    if (ctx->r17 == ctx->r1) {
        // 0x80042004: nop
    
            goto L_80042084;
    }
    // 0x80042004: nop

    // 0x80042008: b           L_800420C0
    // 0x8004200C: nop

        goto L_800420C0;
    // 0x8004200C: nop

L_80042010:
    // 0x80042010: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80042014: nop

    // 0x80042018: lh          $s0, 0x0($t6)
    ctx->r16 = MEM_H(ctx->r14, 0X0);
    // 0x8004201C: b           L_800420C0
    // 0x80042020: nop

        goto L_800420C0;
    // 0x80042020: nop

L_80042024:
    // 0x80042024: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80042028: nop

    // 0x8004202C: lbu         $s0, 0x6($t7)
    ctx->r16 = MEM_BU(ctx->r15, 0X6);
    // 0x80042030: b           L_800420C0
    // 0x80042034: nop

        goto L_800420C0;
    // 0x80042034: nop

L_80042038:
    // 0x80042038: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8004203C: nop

    // 0x80042040: lbu         $t9, 0x5($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X5);
    // 0x80042044: nop

    // 0x80042048: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x8004204C: beq         $at, $zero, L_8004205C
    if (ctx->r1 == 0) {
        // 0x80042050: nop
    
            goto L_8004205C;
    }
    // 0x80042050: nop

    // 0x80042054: b           L_800420C0
    // 0x80042058: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
        goto L_800420C0;
    // 0x80042058: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8004205C:
    // 0x8004205C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80042060: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80042064: lbu         $t1, 0x5($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X5);
    // 0x80042068: nop

    // 0x8004206C: subu        $s0, $t2, $t1
    ctx->r16 = SUB32(ctx->r10, ctx->r9);
    // 0x80042070: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x80042074: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80042078: sra         $t4, $s0, 16
    ctx->r12 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8004207C: b           L_800420C0
    // 0x80042080: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
        goto L_800420C0;
    // 0x80042080: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
L_80042084:
    // 0x80042084: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80042088: addiu       $a1, $sp, 0x25
    ctx->r5 = ADD32(ctx->r29, 0X25);
    // 0x8004208C: lbu         $a0, 0x4($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X4);
    // 0x80042090: jal         0x800406B0
    // 0x80042094: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    aisquarelist_GetRotationSteps(rdram, ctx);
        goto after_0;
    // 0x80042094: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80042098: lbu         $t6, 0x25($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X25);
    // 0x8004209C: lbu         $t7, 0x24($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X24);
    // 0x800420A0: nop

    // 0x800420A4: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800420A8: beq         $at, $zero, L_800420B8
    if (ctx->r1 == 0) {
        // 0x800420AC: nop
    
            goto L_800420B8;
    }
    // 0x800420AC: nop

    // 0x800420B0: b           L_800420C0
    // 0x800420B4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_800420C0;
    // 0x800420B4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_800420B8:
    // 0x800420B8: lbu         $s0, 0x24($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X24);
    // 0x800420BC: nop

L_800420C0:
    // 0x800420C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800420C4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800420C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800420CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800420D0: jr          $ra
    // 0x800420D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800420D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void aisquarelist_CompareKeys(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800420D8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800420DC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800420E0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800420E4: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x800420E8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800420EC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800420F0: beq         $t1, $zero, L_8004211C
    if (ctx->r9 == 0) {
        // 0x800420F4: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_8004211C;
    }
    // 0x800420F4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800420F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800420FC: beq         $t1, $at, L_8004211C
    if (ctx->r9 == ctx->r1) {
        // 0x80042100: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004211C;
    }
    // 0x80042100: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80042104: beq         $t1, $at, L_8004211C
    if (ctx->r9 == ctx->r1) {
        // 0x80042108: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004211C;
    }
    // 0x80042108: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004210C: beq         $t1, $at, L_8004214C
    if (ctx->r9 == ctx->r1) {
        // 0x80042110: nop
    
            goto L_8004214C;
    }
    // 0x80042110: nop

    // 0x80042114: b           L_80042178
    // 0x80042118: nop

        goto L_80042178;
    // 0x80042118: nop

L_8004211C:
    // 0x8004211C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80042120: beq         $at, $zero, L_80042130
    if (ctx->r1 == 0) {
        // 0x80042124: nop
    
            goto L_80042130;
    }
    // 0x80042124: nop

    // 0x80042128: b           L_80042178
    // 0x8004212C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_80042178;
    // 0x8004212C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80042130:
    // 0x80042130: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80042134: beq         $at, $zero, L_80042144
    if (ctx->r1 == 0) {
        // 0x80042138: nop
    
            goto L_80042144;
    }
    // 0x80042138: nop

    // 0x8004213C: b           L_80042178
    // 0x80042140: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80042178;
    // 0x80042140: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80042144:
    // 0x80042144: b           L_80042178
    // 0x80042148: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80042178;
    // 0x80042148: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8004214C:
    // 0x8004214C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80042150: beq         $at, $zero, L_80042160
    if (ctx->r1 == 0) {
        // 0x80042154: nop
    
            goto L_80042160;
    }
    // 0x80042154: nop

    // 0x80042158: b           L_80042178
    // 0x8004215C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_80042178;
    // 0x8004215C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80042160:
    // 0x80042160: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80042164: beq         $at, $zero, L_80042174
    if (ctx->r1 == 0) {
        // 0x80042168: nop
    
            goto L_80042174;
    }
    // 0x80042168: nop

    // 0x8004216C: b           L_80042178
    // 0x80042170: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80042178;
    // 0x80042170: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80042174:
    // 0x80042174: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80042178:
    // 0x80042178: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8004217C: jr          $ra
    // 0x80042180: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80042180: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void aisquarelist_PartitionByKey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042184: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80042188: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004218C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80042190: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80042194: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x80042198: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004219C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800421A0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800421A4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800421A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800421AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800421B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800421B4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800421B8: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x800421BC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800421C0: jal         0x80041FCC
    // 0x800421C4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    aisquarelist_GetSortMetric(rdram, ctx);
        goto after_0;
    // 0x800421C4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x800421C8: lbu         $s1, 0x37($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X37);
    // 0x800421CC: lbu         $s2, 0x3B($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X3B);
    // 0x800421D0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800421D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800421D8: sll         $t1, $s1, 16
    ctx->r9 = S32(ctx->r17 << 16);
    // 0x800421DC: sll         $t3, $s2, 16
    ctx->r11 = S32(ctx->r18 << 16);
    // 0x800421E0: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800421E4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800421E8: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x800421EC: sra         $t0, $s0, 16
    ctx->r8 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800421F0: sra         $t2, $s1, 16
    ctx->r10 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800421F4: sra         $t4, $s2, 16
    ctx->r12 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800421F8: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x800421FC: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x80042200: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
L_80042204:
    // 0x80042204: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80042208: sll         $t5, $s2, 16
    ctx->r13 = S32(ctx->r18 << 16);
    // 0x8004220C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80042210: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x80042214: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80042218: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8004221C: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x80042220: sll         $t9, $s2, 3
    ctx->r25 = S32(ctx->r18 << 3);
    // 0x80042224: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x80042228: jal         0x80041FCC
    // 0x8004222C: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    aisquarelist_GetSortMetric(rdram, ctx);
        goto after_1;
    // 0x8004222C: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x80042230: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80042234: sra         $t0, $s3, 16
    ctx->r8 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80042238: or          $s3, $t0, $zero
    ctx->r19 = ctx->r8 | 0;
    // 0x8004223C: lbu         $a2, 0x3F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3F);
    // 0x80042240: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80042244: jal         0x800420D8
    // 0x80042248: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    aisquarelist_CompareKeys(rdram, ctx);
        goto after_2;
    // 0x80042248: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8004224C: bltz        $v0, L_80042204
    if (SIGNED(ctx->r2) < 0) {
        // 0x80042250: nop
    
            goto L_80042204;
    }
    // 0x80042250: nop

L_80042254:
    // 0x80042254: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80042258: sll         $t1, $s1, 16
    ctx->r9 = S32(ctx->r17 << 16);
    // 0x8004225C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80042260: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80042264: sra         $t2, $s1, 16
    ctx->r10 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80042268: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8004226C: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x80042270: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
    // 0x80042274: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x80042278: jal         0x80041FCC
    // 0x8004227C: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    aisquarelist_GetSortMetric(rdram, ctx);
        goto after_3;
    // 0x8004227C: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_3:
    // 0x80042280: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80042284: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80042288: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x8004228C: lbu         $a2, 0x3F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3F);
    // 0x80042290: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80042294: jal         0x800420D8
    // 0x80042298: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    aisquarelist_CompareKeys(rdram, ctx);
        goto after_4;
    // 0x80042298: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8004229C: bgtz        $v0, L_80042254
    if (SIGNED(ctx->r2) > 0) {
        // 0x800422A0: nop
    
            goto L_80042254;
    }
    // 0x800422A0: nop

    // 0x800422A4: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800422A8: beq         $at, $zero, L_800422D4
    if (ctx->r1 == 0) {
        // 0x800422AC: nop
    
            goto L_800422D4;
    }
    // 0x800422AC: nop

    // 0x800422B0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800422B4: sll         $t9, $s1, 3
    ctx->r25 = S32(ctx->r17 << 3);
    // 0x800422B8: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800422BC: sll         $t0, $s2, 3
    ctx->r8 = S32(ctx->r18 << 3);
    // 0x800422C0: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    // 0x800422C4: jal         0x80041EF0
    // 0x800422C8: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    aisquarelist_SwapEntries(rdram, ctx);
        goto after_5;
    // 0x800422C8: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_5:
    // 0x800422CC: b           L_80042204
    // 0x800422D0: nop

        goto L_80042204;
    // 0x800422D0: nop

L_800422D4:
    // 0x800422D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800422D8: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800422DC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800422E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800422E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800422E8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800422EC: jr          $ra
    // 0x800422F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800422F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void aisquarelist_PartitionRandomPivot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800422F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800422F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800422FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80042300: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80042304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042308: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    // 0x8004230C: lbu         $a0, 0x2F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2F);
    // 0x80042310: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80042314: jal         0x800A35EC
    // 0x80042318: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    Scene_RandRange(rdram, ctx);
        goto after_0;
    // 0x80042318: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8004231C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80042320: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x80042324: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80042328: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x8004232C: sll         $t0, $s0, 3
    ctx->r8 = S32(ctx->r16 << 3);
    // 0x80042330: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80042334: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x80042338: jal         0x80041EF0
    // 0x8004233C: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    aisquarelist_SwapEntries(rdram, ctx);
        goto after_1;
    // 0x8004233C: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    after_1:
    // 0x80042340: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80042344: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x80042348: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x8004234C: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x80042350: jal         0x80042184
    // 0x80042354: nop

    aisquarelist_PartitionByKey(rdram, ctx);
        goto after_2;
    // 0x80042354: nop

    after_2:
    // 0x80042358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004235C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80042360: jr          $ra
    // 0x80042364: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80042364: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void aisquarelist_QuickSort(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042368: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004236C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80042370: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80042374: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x80042378: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x8004237C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042380: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80042384: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80042388: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8004238C: beq         $at, $zero, L_800423E0
    if (ctx->r1 == 0) {
        // 0x80042390: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800423E0;
    }
    // 0x80042390: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80042394: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80042398: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x8004239C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800423A0: jal         0x800422F4
    // 0x800423A4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    aisquarelist_PartitionRandomPivot(rdram, ctx);
        goto after_0;
    // 0x800423A4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    after_0:
    // 0x800423A8: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800423AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800423B0: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x800423B4: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x800423B8: jal         0x80042368
    // 0x800423BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    aisquarelist_QuickSort(rdram, ctx);
        goto after_1;
    // 0x800423BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800423C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800423C4: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x800423C8: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800423CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800423D0: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x800423D4: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x800423D8: jal         0x80042368
    // 0x800423DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    aisquarelist_QuickSort(rdram, ctx);
        goto after_2;
    // 0x800423DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
L_800423E0:
    // 0x800423E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800423E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800423E8: jr          $ra
    // 0x800423EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800423EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void aisquarelist_SortCandidates(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800423F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800423F4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800423F8: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x800423FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80042400: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80042404: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80042408: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004240C: beq         $t6, $zero, L_8004271C
    if (ctx->r14 == 0) {
        // 0x80042410: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8004271C;
    }
    // 0x80042410: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80042414: slti        $at, $t6, 0xC9
    ctx->r1 = SIGNED(ctx->r14) < 0XC9 ? 1 : 0;
    // 0x80042418: beq         $at, $zero, L_8004271C
    if (ctx->r1 == 0) {
        // 0x8004241C: nop
    
            goto L_8004271C;
    }
    // 0x8004241C: nop

    // 0x80042420: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80042424: lw          $t7, 0x1F40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F40);
    // 0x80042428: nop

    // 0x8004242C: beq         $t7, $zero, L_8004271C
    if (ctx->r15 == 0) {
        // 0x80042430: nop
    
            goto L_8004271C;
    }
    // 0x80042430: nop

    // 0x80042434: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    // 0x80042438: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8004243C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042440: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80042444: jal         0x80042368
    // 0x80042448: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    aisquarelist_QuickSort(rdram, ctx);
        goto after_0;
    // 0x80042448: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x8004244C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80042450:
    // 0x80042450: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80042454: lw          $t8, 0x1F40($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1F40);
    // 0x80042458: lbu         $t3, 0x3B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3B);
    // 0x8004245C: andi        $s1, $s0, 0xFF
    ctx->r17 = ctx->r16 & 0XFF;
    // 0x80042460: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80042464: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x80042468: sll         $t0, $s0, 3
    ctx->r8 = S32(ctx->r16 << 3);
    // 0x8004246C: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
    // 0x80042470: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80042474: addu        $s2, $t9, $t0
    ctx->r18 = ADD32(ctx->r25, ctx->r8);
    // 0x80042478: beq         $at, $zero, L_800424D4
    if (ctx->r1 == 0) {
        // 0x8004247C: addu        $s3, $t1, $t2
        ctx->r19 = ADD32(ctx->r9, ctx->r10);
            goto L_800424D4;
    }
    // 0x8004247C: addu        $s3, $t1, $t2
    ctx->r19 = ADD32(ctx->r9, ctx->r10);
    // 0x80042480: lh          $t4, 0x0($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X0);
    // 0x80042484: lh          $t5, 0x0($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X0);
    // 0x80042488: nop

    // 0x8004248C: bne         $t4, $t5, L_800424D4
    if (ctx->r12 != ctx->r13) {
        // 0x80042490: nop
    
            goto L_800424D4;
    }
    // 0x80042490: nop

L_80042494:
    // 0x80042494: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80042498: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004249C: lw          $t7, 0x1F40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F40);
    // 0x800424A0: andi        $t6, $s1, 0xFF
    ctx->r14 = ctx->r17 & 0XFF;
    // 0x800424A4: lbu         $t8, 0x3B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3B);
    // 0x800424A8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800424AC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800424B0: sll         $t0, $s1, 3
    ctx->r8 = S32(ctx->r17 << 3);
    // 0x800424B4: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800424B8: beq         $at, $zero, L_800424D4
    if (ctx->r1 == 0) {
        // 0x800424BC: addu        $s3, $t9, $t0
        ctx->r19 = ADD32(ctx->r25, ctx->r8);
            goto L_800424D4;
    }
    // 0x800424BC: addu        $s3, $t9, $t0
    ctx->r19 = ADD32(ctx->r25, ctx->r8);
    // 0x800424C0: lh          $t1, 0x0($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X0);
    // 0x800424C4: lh          $t2, 0x0($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X0);
    // 0x800424C8: nop

    // 0x800424CC: beq         $t1, $t2, L_80042494
    if (ctx->r9 == ctx->r10) {
        // 0x800424D0: nop
    
            goto L_80042494;
    }
    // 0x800424D0: nop

L_800424D4:
    // 0x800424D4: beq         $s0, $s1, L_800424FC
    if (ctx->r16 == ctx->r17) {
        // 0x800424D8: nop
    
            goto L_800424FC;
    }
    // 0x800424D8: nop

    // 0x800424DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800424E0: lw          $a0, 0x1F40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F40);
    // 0x800424E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800424E8: addiu       $a2, $s1, -0x1
    ctx->r6 = ADD32(ctx->r17, -0X1);
    // 0x800424EC: jal         0x80042368
    // 0x800424F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    aisquarelist_QuickSort(rdram, ctx);
        goto after_1;
    // 0x800424F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800424F4: b           L_80042508
    // 0x800424F8: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
        goto L_80042508;
    // 0x800424F8: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
L_800424FC:
    // 0x800424FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80042500: andi        $t3, $s0, 0xFF
    ctx->r11 = ctx->r16 & 0XFF;
    // 0x80042504: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
L_80042508:
    // 0x80042508: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8004250C: bne         $at, $zero, L_80042450
    if (ctx->r1 != 0) {
        // 0x80042510: nop
    
            goto L_80042450;
    }
    // 0x80042510: nop

    // 0x80042514: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80042518:
    // 0x80042518: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8004251C: lw          $t4, 0x1F40($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1F40);
    // 0x80042520: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x80042524: andi        $s1, $s0, 0xFF
    ctx->r17 = ctx->r16 & 0XFF;
    // 0x80042528: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8004252C: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x80042530: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x80042534: sll         $t9, $s1, 3
    ctx->r25 = S32(ctx->r17 << 3);
    // 0x80042538: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004253C: addu        $s2, $t5, $t6
    ctx->r18 = ADD32(ctx->r13, ctx->r14);
    // 0x80042540: beq         $at, $zero, L_800425C4
    if (ctx->r1 == 0) {
        // 0x80042544: addu        $s3, $t7, $t9
        ctx->r19 = ADD32(ctx->r15, ctx->r25);
            goto L_800425C4;
    }
    // 0x80042544: addu        $s3, $t7, $t9
    ctx->r19 = ADD32(ctx->r15, ctx->r25);
    // 0x80042548: lh          $t8, 0x0($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X0);
    // 0x8004254C: lh          $t1, 0x0($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X0);
    // 0x80042550: nop

    // 0x80042554: bne         $t8, $t1, L_800425C4
    if (ctx->r24 != ctx->r9) {
        // 0x80042558: nop
    
            goto L_800425C4;
    }
    // 0x80042558: nop

    // 0x8004255C: lbu         $t2, 0x6($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X6);
    // 0x80042560: lbu         $t3, 0x6($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X6);
    // 0x80042564: nop

    // 0x80042568: bne         $t2, $t3, L_800425C4
    if (ctx->r10 != ctx->r11) {
        // 0x8004256C: nop
    
            goto L_800425C4;
    }
    // 0x8004256C: nop

L_80042570:
    // 0x80042570: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80042574: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80042578: lw          $t6, 0x1F40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F40);
    // 0x8004257C: andi        $t5, $s1, 0xFF
    ctx->r13 = ctx->r17 & 0XFF;
    // 0x80042580: lbu         $t9, 0x3B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3B);
    // 0x80042584: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x80042588: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x8004258C: sll         $t7, $s1, 3
    ctx->r15 = S32(ctx->r17 << 3);
    // 0x80042590: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80042594: beq         $at, $zero, L_800425C4
    if (ctx->r1 == 0) {
        // 0x80042598: addu        $s3, $t4, $t7
        ctx->r19 = ADD32(ctx->r12, ctx->r15);
            goto L_800425C4;
    }
    // 0x80042598: addu        $s3, $t4, $t7
    ctx->r19 = ADD32(ctx->r12, ctx->r15);
    // 0x8004259C: lh          $t0, 0x0($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X0);
    // 0x800425A0: lh          $t8, 0x0($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X0);
    // 0x800425A4: nop

    // 0x800425A8: bne         $t0, $t8, L_800425C4
    if (ctx->r8 != ctx->r24) {
        // 0x800425AC: nop
    
            goto L_800425C4;
    }
    // 0x800425AC: nop

    // 0x800425B0: lbu         $t1, 0x6($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X6);
    // 0x800425B4: lbu         $t2, 0x6($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X6);
    // 0x800425B8: nop

    // 0x800425BC: beq         $t1, $t2, L_80042570
    if (ctx->r9 == ctx->r10) {
        // 0x800425C0: nop
    
            goto L_80042570;
    }
    // 0x800425C0: nop

L_800425C4:
    // 0x800425C4: beq         $s0, $s1, L_800425EC
    if (ctx->r16 == ctx->r17) {
        // 0x800425C8: nop
    
            goto L_800425EC;
    }
    // 0x800425C8: nop

    // 0x800425CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800425D0: lw          $a0, 0x1F40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F40);
    // 0x800425D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800425D8: addiu       $a2, $s1, -0x1
    ctx->r6 = ADD32(ctx->r17, -0X1);
    // 0x800425DC: jal         0x80042368
    // 0x800425E0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    aisquarelist_QuickSort(rdram, ctx);
        goto after_2;
    // 0x800425E0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x800425E4: b           L_800425F8
    // 0x800425E8: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
        goto L_800425F8;
    // 0x800425E8: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
L_800425EC:
    // 0x800425EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800425F0: andi        $t3, $s0, 0xFF
    ctx->r11 = ctx->r16 & 0XFF;
    // 0x800425F4: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
L_800425F8:
    // 0x800425F8: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x800425FC: bne         $at, $zero, L_80042518
    if (ctx->r1 != 0) {
        // 0x80042600: nop
    
            goto L_80042518;
    }
    // 0x80042600: nop

    // 0x80042604: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80042608:
    // 0x80042608: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8004260C: lw          $t5, 0x1F40($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1F40);
    // 0x80042610: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x80042614: andi        $s1, $s0, 0xFF
    ctx->r17 = ctx->r16 & 0XFF;
    // 0x80042618: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8004261C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80042620: sll         $t4, $s0, 3
    ctx->r12 = S32(ctx->r16 << 3);
    // 0x80042624: sll         $t9, $s1, 3
    ctx->r25 = S32(ctx->r17 << 3);
    // 0x80042628: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004262C: addu        $s2, $t6, $t4
    ctx->r18 = ADD32(ctx->r14, ctx->r12);
    // 0x80042630: beq         $at, $zero, L_800426DC
    if (ctx->r1 == 0) {
        // 0x80042634: addu        $s3, $t7, $t9
        ctx->r19 = ADD32(ctx->r15, ctx->r25);
            goto L_800426DC;
    }
    // 0x80042634: addu        $s3, $t7, $t9
    ctx->r19 = ADD32(ctx->r15, ctx->r25);
    // 0x80042638: lh          $t8, 0x0($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X0);
    // 0x8004263C: lh          $t1, 0x0($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X0);
    // 0x80042640: nop

    // 0x80042644: bne         $t8, $t1, L_800426DC
    if (ctx->r24 != ctx->r9) {
        // 0x80042648: nop
    
            goto L_800426DC;
    }
    // 0x80042648: nop

    // 0x8004264C: lbu         $t2, 0x6($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X6);
    // 0x80042650: lbu         $t3, 0x6($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X6);
    // 0x80042654: nop

    // 0x80042658: bne         $t2, $t3, L_800426DC
    if (ctx->r10 != ctx->r11) {
        // 0x8004265C: nop
    
            goto L_800426DC;
    }
    // 0x8004265C: nop

    // 0x80042660: lbu         $t6, 0x5($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X5);
    // 0x80042664: lbu         $t4, 0x5($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X5);
    // 0x80042668: nop

    // 0x8004266C: bne         $t6, $t4, L_800426DC
    if (ctx->r14 != ctx->r12) {
        // 0x80042670: nop
    
            goto L_800426DC;
    }
    // 0x80042670: nop

L_80042674:
    // 0x80042674: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80042678: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004267C: lw          $t7, 0x1F40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F40);
    // 0x80042680: andi        $t5, $s1, 0xFF
    ctx->r13 = ctx->r17 & 0XFF;
    // 0x80042684: lbu         $t8, 0x3B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3B);
    // 0x80042688: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x8004268C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80042690: sll         $t0, $s1, 3
    ctx->r8 = S32(ctx->r17 << 3);
    // 0x80042694: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80042698: beq         $at, $zero, L_800426DC
    if (ctx->r1 == 0) {
        // 0x8004269C: addu        $s3, $t9, $t0
        ctx->r19 = ADD32(ctx->r25, ctx->r8);
            goto L_800426DC;
    }
    // 0x8004269C: addu        $s3, $t9, $t0
    ctx->r19 = ADD32(ctx->r25, ctx->r8);
    // 0x800426A0: lh          $t1, 0x0($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X0);
    // 0x800426A4: lh          $t2, 0x0($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X0);
    // 0x800426A8: nop

    // 0x800426AC: bne         $t1, $t2, L_800426DC
    if (ctx->r9 != ctx->r10) {
        // 0x800426B0: nop
    
            goto L_800426DC;
    }
    // 0x800426B0: nop

    // 0x800426B4: lbu         $t3, 0x6($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X6);
    // 0x800426B8: lbu         $t6, 0x6($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X6);
    // 0x800426BC: nop

    // 0x800426C0: bne         $t3, $t6, L_800426DC
    if (ctx->r11 != ctx->r14) {
        // 0x800426C4: nop
    
            goto L_800426DC;
    }
    // 0x800426C4: nop

    // 0x800426C8: lbu         $t4, 0x5($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X5);
    // 0x800426CC: lbu         $t5, 0x5($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X5);
    // 0x800426D0: nop

    // 0x800426D4: beq         $t4, $t5, L_80042674
    if (ctx->r12 == ctx->r13) {
        // 0x800426D8: nop
    
            goto L_80042674;
    }
    // 0x800426D8: nop

L_800426DC:
    // 0x800426DC: beq         $s0, $s1, L_80042704
    if (ctx->r16 == ctx->r17) {
        // 0x800426E0: nop
    
            goto L_80042704;
    }
    // 0x800426E0: nop

    // 0x800426E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800426E8: lw          $a0, 0x1F40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F40);
    // 0x800426EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800426F0: addiu       $a2, $s1, -0x1
    ctx->r6 = ADD32(ctx->r17, -0X1);
    // 0x800426F4: jal         0x80042368
    // 0x800426F8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    aisquarelist_QuickSort(rdram, ctx);
        goto after_3;
    // 0x800426F8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x800426FC: b           L_80042710
    // 0x80042700: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
        goto L_80042710;
    // 0x80042700: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
L_80042704:
    // 0x80042704: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80042708: andi        $t7, $s0, 0xFF
    ctx->r15 = ctx->r16 & 0XFF;
    // 0x8004270C: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_80042710:
    // 0x80042710: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80042714: bne         $at, $zero, L_80042608
    if (ctx->r1 != 0) {
        // 0x80042718: nop
    
            goto L_80042608;
    }
    // 0x80042718: nop

L_8004271C:
    // 0x8004271C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80042720: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80042724: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80042728: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8004272C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80042730: jr          $ra
    // 0x80042734: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80042734: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void aisquarelist_CopyTop3Moves(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042738: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8004273C: lw          $t6, 0x1F40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F40);
    // 0x80042740: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80042744: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042748: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004274C: beq         $t6, $zero, L_800427A8
    if (ctx->r14 == 0) {
        // 0x80042750: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800427A8;
    }
    // 0x80042750: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80042754: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80042758: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8004275C: beq         $at, $zero, L_800427A8
    if (ctx->r1 == 0) {
        // 0x80042760: nop
    
            goto L_800427A8;
    }
    // 0x80042760: nop

L_80042764:
    // 0x80042764: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80042768: lw          $t9, 0x1F40($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1F40);
    // 0x8004276C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80042770: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80042774: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80042778: sll         $t1, $s0, 3
    ctx->r9 = S32(ctx->r16 << 3);
    // 0x8004277C: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80042780: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x80042784: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80042788: jal         0x80041DA0
    // 0x8004278C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    aisquarelist_CopyEntry3(rdram, ctx);
        goto after_0;
    // 0x8004278C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80042790: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80042794: andi        $t2, $s0, 0xFF
    ctx->r10 = ctx->r16 & 0XFF;
    // 0x80042798: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x8004279C: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x800427A0: bne         $at, $zero, L_80042764
    if (ctx->r1 != 0) {
        // 0x800427A4: nop
    
            goto L_80042764;
    }
    // 0x800427A4: nop

L_800427A8:
    // 0x800427A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800427AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800427B0: jr          $ra
    // 0x800427B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800427B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void aisquarelist_CopyMoveAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800427B8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800427BC: lw          $t6, 0x1F40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1F40);
    // 0x800427C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800427C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800427C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800427CC: beq         $t6, $zero, L_800427F0
    if (ctx->r14 == 0) {
        // 0x800427D0: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800427F0;
    }
    // 0x800427D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800427D4: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x800427D8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800427DC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800427E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800427E4: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    // 0x800427E8: jal         0x80041DA0
    // 0x800427EC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    aisquarelist_CopyEntry3(rdram, ctx);
        goto after_0;
    // 0x800427EC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_0:
L_800427F0:
    // 0x800427F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800427F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800427F8: jr          $ra
    // 0x800427FC: nop

    return;
    // 0x800427FC: nop

;}

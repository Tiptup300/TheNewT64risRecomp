#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Controller_SendRecvMsg(uint8_t* rdram, recomp_context* ctx) {
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

RECOMP_FUNC void Controller_GetType(uint8_t* rdram, recomp_context* ctx) {
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

RECOMP_FUNC void Controller_GetStatus(uint8_t* rdram, recomp_context* ctx) {
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

RECOMP_FUNC void Controller_GetErrNo(uint8_t* rdram, recomp_context* ctx) {
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

RECOMP_FUNC void Controller_CreateThread(uint8_t* rdram, recomp_context* ctx) {
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

RECOMP_FUNC void Controller_DetectAccessory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A06D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A06D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A06D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A06DC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800A06E0: jal         0x8003B5D0
    // 0x800A06E4: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    Controller_SendRecvMsg(rdram, ctx);
        goto after_0;
    // 0x800A06E4: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_0:
    // 0x800A06E8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800A06EC: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    // 0x800A06F0: jal         0x8003B654
    // 0x800A06F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Controller_GetStatus(rdram, ctx);
        goto after_1;
    // 0x800A06F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800A06F8: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x800A06FC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x800A0700: nop

    // 0x800A0704: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800A0708: beq         $t7, $zero, L_800A0858
    if (ctx->r15 == 0) {
        // 0x800A070C: nop
    
            goto L_800A0858;
    }
    // 0x800A070C: nop

    // 0x800A0710: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800A0714: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    // 0x800A0718: jal         0x8003B684
    // 0x800A071C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Pfs_InitPak(rdram, ctx);
        goto after_2;
    // 0x800A071C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800A0720: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x800A0724: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x800A0728: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A072C: sra         $t9, $t8, 4
    ctx->r25 = S32(SIGNED(ctx->r24) >> 4);
    // 0x800A0730: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x800A0734: beq         $t0, $at, L_800A0754
    if (ctx->r8 == ctx->r1) {
        // 0x800A0738: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800A0754;
    }
    // 0x800A0738: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800A073C: beq         $t0, $at, L_800A0754
    if (ctx->r8 == ctx->r1) {
        // 0x800A0740: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800A0754;
    }
    // 0x800A0740: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0744: beq         $t0, $at, L_800A0754
    if (ctx->r8 == ctx->r1) {
        // 0x800A0748: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A0754;
    }
    // 0x800A0748: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A074C: bne         $t0, $at, L_800A0804
    if (ctx->r8 != ctx->r1) {
        // 0x800A0750: nop
    
            goto L_800A0804;
    }
    // 0x800A0750: nop

L_800A0754:
    // 0x800A0754: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800A0758: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x800A075C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800A0760: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800A0764: addiu       $t3, $t3, 0x3D10
    ctx->r11 = ADD32(ctx->r11, 0X3D10);
    // 0x800A0768: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A076C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800A0770: addiu       $t4, $zero, 0xFB
    ctx->r12 = ADD32(0, 0XFB);
    // 0x800A0774: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800A0778: addiu       $t7, $t7, 0x42B4
    ctx->r15 = ADD32(ctx->r15, 0X42B4);
    // 0x800A077C: addiu       $t6, $zero, 0x201
    ctx->r14 = ADD32(0, 0X201);
    // 0x800A0780: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800A0784: sb          $t4, 0x60($t5)
    MEM_B(0X60, ctx->r13) = ctx->r12;
    // 0x800A0788: sh          $t6, 0x1E4($t7)
    MEM_H(0X1E4, ctx->r15) = ctx->r14;
    // 0x800A078C: addiu       $t9, $t9, 0x3D00
    ctx->r25 = ADD32(ctx->r25, 0X3D00);
    // 0x800A0790: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x800A0794: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800A0798: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A079C: jal         0x8003B5D0
    // 0x800A07A0: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    Controller_SendRecvMsg(rdram, ctx);
        goto after_3;
    // 0x800A07A0: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_3:
    // 0x800A07A4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800A07A8: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    // 0x800A07AC: jal         0x8003B3E4
    // 0x800A07B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Motor_SendRecvMsg3(rdram, ctx);
        goto after_4;
    // 0x800A07B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800A07B4: bne         $v0, $zero, L_800A07CC
    if (ctx->r2 != 0) {
        // 0x800A07B8: nop
    
            goto L_800A07CC;
    }
    // 0x800A07B8: nop

    // 0x800A07BC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800A07C0: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x800A07C4: b           L_800A0890
    // 0x800A07C8: sb          $t0, 0x5D($t1)
    MEM_B(0X5D, ctx->r9) = ctx->r8;
        goto L_800A0890;
    // 0x800A07C8: sb          $t0, 0x5D($t1)
    MEM_B(0X5D, ctx->r9) = ctx->r8;
L_800A07CC:
    // 0x800A07CC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800A07D0: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    // 0x800A07D4: jal         0x8003BC3C
    // 0x800A07D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Gbpak_Init(rdram, ctx);
        goto after_5;
    // 0x800A07D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x800A07DC: bne         $v0, $zero, L_800A07F4
    if (ctx->r2 != 0) {
        // 0x800A07E0: nop
    
            goto L_800A07F4;
    }
    // 0x800A07E0: nop

    // 0x800A07E4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800A07E8: addiu       $t2, $zero, 0xF0
    ctx->r10 = ADD32(0, 0XF0);
    // 0x800A07EC: b           L_800A0890
    // 0x800A07F0: sb          $t2, 0x5D($t3)
    MEM_B(0X5D, ctx->r11) = ctx->r10;
        goto L_800A0890;
    // 0x800A07F0: sb          $t2, 0x5D($t3)
    MEM_B(0X5D, ctx->r11) = ctx->r10;
L_800A07F4:
    // 0x800A07F4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800A07F8: addiu       $t4, $zero, 0xED
    ctx->r12 = ADD32(0, 0XED);
    // 0x800A07FC: b           L_800A0890
    // 0x800A0800: sb          $t4, 0x5D($t5)
    MEM_B(0X5D, ctx->r13) = ctx->r12;
        goto L_800A0890;
    // 0x800A0800: sb          $t4, 0x5D($t5)
    MEM_B(0X5D, ctx->r13) = ctx->r12;
L_800A0804:
    // 0x800A0804: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800A0808: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x800A080C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800A0810: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800A0814: addiu       $t8, $t8, 0x3D10
    ctx->r24 = ADD32(ctx->r24, 0X3D10);
    // 0x800A0818: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A081C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A0820: addiu       $t9, $zero, 0xFB
    ctx->r25 = ADD32(0, 0XFB);
    // 0x800A0824: sb          $t9, 0x60($t0)
    MEM_B(0X60, ctx->r8) = ctx->r25;
    // 0x800A0828: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800A082C: addiu       $t1, $zero, 0xFE
    ctx->r9 = ADD32(0, 0XFE);
    // 0x800A0830: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800A0834: addiu       $t4, $t4, 0x42B4
    ctx->r12 = ADD32(ctx->r12, 0X42B4);
    // 0x800A0838: addiu       $t3, $zero, 0x201
    ctx->r11 = ADD32(0, 0X201);
    // 0x800A083C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800A0840: sb          $t1, 0x5D($t2)
    MEM_B(0X5D, ctx->r10) = ctx->r9;
    // 0x800A0844: sh          $t3, 0x1E4($t4)
    MEM_H(0X1E4, ctx->r12) = ctx->r11;
    // 0x800A0848: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x800A084C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800A0850: b           L_800A0890
    // 0x800A0854: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
        goto L_800A0890;
    // 0x800A0854: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_800A0858:
    // 0x800A0858: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A085C: addiu       $t7, $zero, 0xFB
    ctx->r15 = ADD32(0, 0XFB);
    // 0x800A0860: sb          $t7, 0x60($t8)
    MEM_B(0X60, ctx->r24) = ctx->r15;
    // 0x800A0864: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A0868: addiu       $t9, $zero, 0xF0
    ctx->r25 = ADD32(0, 0XF0);
    // 0x800A086C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800A0870: addiu       $t2, $t2, 0x42B4
    ctx->r10 = ADD32(ctx->r10, 0X42B4);
    // 0x800A0874: addiu       $t1, $zero, 0x201
    ctx->r9 = ADD32(0, 0X201);
    // 0x800A0878: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800A087C: sb          $t9, 0x5D($t0)
    MEM_B(0X5D, ctx->r8) = ctx->r25;
    // 0x800A0880: sh          $t1, 0x1E4($t2)
    MEM_H(0X1E4, ctx->r10) = ctx->r9;
    // 0x800A0884: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x800A0888: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800A088C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_800A0890:
    // 0x800A0890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0894: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A0898: jr          $ra
    // 0x800A089C: nop

    return;
    // 0x800A089C: nop

;}

RECOMP_FUNC void func_800A08A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A08A0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800A08A4: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x800A08A8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800A08AC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800A08B0: addiu       $t8, $t8, 0x3D10
    ctx->r24 = ADD32(ctx->r24, 0X3D10);
    // 0x800A08B4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A08B8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A08BC: addiu       $t0, $zero, 0xFE
    ctx->r8 = ADD32(0, 0XFE);
    // 0x800A08C0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800A08C4: sb          $t9, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r25;
    // 0x800A08C8: sb          $t0, 0x5D($a0)
    MEM_B(0X5D, ctx->r4) = ctx->r8;
    // 0x800A08CC: addiu       $t2, $t2, 0x42B4
    ctx->r10 = ADD32(ctx->r10, 0X42B4);
    // 0x800A08D0: addiu       $t1, $zero, 0x201
    ctx->r9 = ADD32(0, 0X201);
    // 0x800A08D4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800A08D8: sh          $t1, 0x1E4($t2)
    MEM_H(0X1E4, ctx->r10) = ctx->r9;
    // 0x800A08DC: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x800A08E0: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800A08E4: jr          $ra
    // 0x800A08E8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    return;
    // 0x800A08E8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
;}

RECOMP_FUNC void func_800A08EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A08EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A08F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A08F4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A08F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A08FC: lbu         $a0, 0x3B0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X3B0);
    // 0x800A0900: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A0904: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800A0908: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A090C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A0910: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A0914: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A0918: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A091C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A0920: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A0924: jal         0x800875EC
    // 0x800A0928: addiu       $a1, $a1, 0xA70
    ctx->r5 = ADD32(ctx->r5, 0XA70);
    Audio2_SetGlobalPitch(rdram, ctx);
        goto after_0;
    // 0x800A0928: addiu       $a1, $a1, 0xA70
    ctx->r5 = ADD32(ctx->r5, 0XA70);
    after_0:
    // 0x800A092C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800A0930: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A0934: lbu         $t9, 0x3B0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3B0);
    // 0x800A0938: lw          $t1, -0x310($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X310);
    // 0x800A093C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800A0940: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800A0944: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800A0948: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800A094C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800A0950: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800A0954: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800A0958: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A095C: sw          $t0, 0x18E4($t1)
    MEM_W(0X18E4, ctx->r9) = ctx->r8;
    // 0x800A0960: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x800A0964: jal         0x8007C5CC
    // 0x800A0968: nop

    SaveData_Save(rdram, ctx);
        goto after_1;
    // 0x800A0968: nop

    after_1:
    // 0x800A096C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A0974: jr          $ra
    // 0x800A0978: nop

    return;
    // 0x800A0978: nop

;}

RECOMP_FUNC void func_800A097C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A097C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A0980: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A0984: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A0988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A098C: lbu         $a0, 0x3B0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X3B0);
    // 0x800A0990: nop

    // 0x800A0994: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800A0998: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A099C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A09A0: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A09A4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A09A8: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A09AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A09B0: jal         0x80087618
    // 0x800A09B4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    Audio2_BuildVolumeTable(rdram, ctx);
        goto after_0;
    // 0x800A09B4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x800A09B8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800A09BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A09C0: lbu         $t9, 0x3B0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3B0);
    // 0x800A09C4: lw          $t1, -0x310($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X310);
    // 0x800A09C8: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800A09CC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800A09D0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800A09D4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800A09D8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800A09DC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800A09E0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800A09E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A09E8: sw          $t0, 0x18E8($t1)
    MEM_W(0X18E8, ctx->r9) = ctx->r8;
    // 0x800A09EC: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x800A09F0: jal         0x8007C5CC
    // 0x800A09F4: nop

    SaveData_Save(rdram, ctx);
        goto after_1;
    // 0x800A09F4: nop

    after_1:
    // 0x800A09F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A09FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A0A00: jr          $ra
    // 0x800A0A04: nop

    return;
    // 0x800A0A04: nop

;}

RECOMP_FUNC void func_800A0A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0A08: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800A0A0C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A0A10: lw          $t7, -0x310($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X310);
    // 0x800A0A14: lbu         $t6, 0x4DD0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4DD0);
    // 0x800A0A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A0A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A0A20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0A24: sw          $t6, 0x18F0($t7)
    MEM_W(0X18F0, ctx->r15) = ctx->r14;
    // 0x800A0A28: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x800A0A2C: jal         0x8007C5CC
    // 0x800A0A30: nop

    SaveData_Save(rdram, ctx);
        goto after_0;
    // 0x800A0A30: nop

    after_0:
    // 0x800A0A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0A38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A0A3C: jr          $ra
    // 0x800A0A40: nop

    return;
    // 0x800A0A40: nop

;}

RECOMP_FUNC void func_800A0A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0A44: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800A0A48: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x800A0A4C: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A0A50: addiu       $t6, $zero, 0x98
    ctx->r14 = ADD32(0, 0X98);
    // 0x800A0A54: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x800A0A58: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A0A5C: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x800A0A60: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800A0A64: sh          $t6, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r14;
    // 0x800A0A68: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x800A0A6C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800A0A70: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800A0A74: lbu         $t0, 0xB($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XB);
    // 0x800A0A78: nop

    // 0x800A0A7C: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x800A0A80: bne         $t1, $at, L_800A0D3C
    if (ctx->r9 != ctx->r1) {
        // 0x800A0A84: nop
    
            goto L_800A0D3C;
    }
    // 0x800A0A84: nop

    // 0x800A0A88: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_800A0A8C:
    // 0x800A0A8C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0A90: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A0A94: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800A0A98: lw          $t2, -0x310($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X310);
    // 0x800A0A9C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800A0AA0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800A0AA4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800A0AA8: addiu       $t6, $t5, 0xF0C
    ctx->r14 = ADD32(ctx->r13, 0XF0C);
    // 0x800A0AAC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800A0AB0: lw          $t7, 0xF18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XF18);
    // 0x800A0AB4: nop

    // 0x800A0AB8: beq         $t7, $zero, L_800A0D1C
    if (ctx->r15 == 0) {
        // 0x800A0ABC: nop
    
            goto L_800A0D1C;
    }
    // 0x800A0ABC: nop

    // 0x800A0AC0: lw          $t8, 0xF1C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XF1C);
    // 0x800A0AC4: nop

    // 0x800A0AC8: beq         $t8, $zero, L_800A0D1C
    if (ctx->r24 == 0) {
        // 0x800A0ACC: nop
    
            goto L_800A0D1C;
    }
    // 0x800A0ACC: nop

    // 0x800A0AD0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A0AD4: addiu       $a1, $a1, 0x4F0
    ctx->r5 = ADD32(ctx->r5, 0X4F0);
    // 0x800A0AD8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800A0ADC: jal         0x800B62D4
    // 0x800A0AE0: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A0AE0: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_0:
    // 0x800A0AE4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A0AE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A0AEC: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A0AF0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A0AF4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A0AF8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A0AFC: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A0B00: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A0B04: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A0B08: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x800A0B0C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A0B10: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A0B14: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A0B18: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A0B1C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A0B20: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A0B24: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A0B28: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A0B2C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A0B30: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800A0B34: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800A0B38: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800A0B3C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800A0B40: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A0B44: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A0B48: jal         0x80077960
    // 0x800A0B4C: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_1;
    // 0x800A0B4C: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_1:
    // 0x800A0B50: lhu         $t7, 0x40($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X40);
    // 0x800A0B54: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800A0B58: addiu       $t5, $t7, 0x50
    ctx->r13 = ADD32(ctx->r15, 0X50);
    // 0x800A0B5C: sh          $t5, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r13;
    // 0x800A0B60: lhu         $a1, 0x16($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X16);
    // 0x800A0B64: lhu         $a0, 0x14($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X14);
    // 0x800A0B68: jal         0x80078424
    // 0x800A0B6C: nop

    FUN_SRAM_80078424_twelveliner_div60_loop_30t_b(rdram, ctx);
        goto after_2;
    // 0x800A0B6C: nop

    after_2:
    // 0x800A0B70: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800A0B74: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A0B78: addiu       $a1, $a1, 0x4F4
    ctx->r5 = ADD32(ctx->r5, 0X4F4);
    // 0x800A0B7C: addiu       $a2, $s0, 0x1
    ctx->r6 = ADD32(ctx->r16, 0X1);
    // 0x800A0B80: jal         0x800B62D4
    // 0x800A0B84: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x800A0B84: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x800A0B88: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A0B8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A0B90: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A0B94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A0B98: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A0B9C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A0BA0: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A0BA4: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A0BA8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A0BAC: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x800A0BB0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A0BB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A0BB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A0BBC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A0BC0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A0BC4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A0BC8: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800A0BCC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A0BD0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A0BD4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800A0BD8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800A0BDC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800A0BE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A0BE4: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A0BE8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A0BEC: jal         0x80077960
    // 0x800A0BF0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_4;
    // 0x800A0BF0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_4:
    // 0x800A0BF4: lhu         $t4, 0x40($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X40);
    // 0x800A0BF8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800A0BFC: addiu       $t7, $t4, 0x46
    ctx->r15 = ADD32(ctx->r12, 0X46);
    // 0x800A0C00: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x800A0C04: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A0C08: lw          $a2, 0xC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XC);
    // 0x800A0C0C: addiu       $a1, $a1, 0x4F8
    ctx->r5 = ADD32(ctx->r5, 0X4F8);
    // 0x800A0C10: jal         0x800B62D4
    // 0x800A0C14: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x800A0C14: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x800A0C18: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A0C1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A0C20: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A0C24: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A0C28: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A0C2C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A0C30: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A0C34: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A0C38: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A0C3C: addiu       $t8, $sp, 0x48
    ctx->r24 = ADD32(ctx->r29, 0X48);
    // 0x800A0C40: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A0C44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A0C48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A0C4C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A0C50: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A0C54: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A0C58: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800A0C5C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A0C60: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A0C64: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800A0C68: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A0C6C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A0C70: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A0C74: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A0C78: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A0C7C: jal         0x80077960
    // 0x800A0C80: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_6;
    // 0x800A0C80: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    after_6:
    // 0x800A0C84: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A0C88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A0C8C: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A0C90: lhu         $t2, 0x40($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X40);
    // 0x800A0C94: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A0C98: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A0C9C: addiu       $t4, $t2, 0x50
    ctx->r12 = ADD32(ctx->r10, 0X50);
    // 0x800A0CA0: sh          $t4, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r12;
    // 0x800A0CA4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A0CA8: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    // 0x800A0CAC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800A0CB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A0CB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A0CB8: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x800A0CBC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A0CC0: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800A0CC4: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800A0CC8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A0CCC: andi        $a2, $t4, 0xFFFF
    ctx->r6 = ctx->r12 & 0XFFFF;
    // 0x800A0CD0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A0CD4: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A0CD8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A0CDC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A0CE0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A0CE4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A0CE8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A0CEC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A0CF0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A0CF4: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A0CF8: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x800A0CFC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800A0D00: jal         0x80071480
    // 0x800A0D04: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    displayTimeFormatted_XY_RGBA(rdram, ctx);
        goto after_7;
    // 0x800A0D04: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_7:
    // 0x800A0D08: lhu         $t3, 0x42($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X42);
    // 0x800A0D0C: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x800A0D10: addiu       $t2, $t3, 0x12
    ctx->r10 = ADD32(ctx->r11, 0X12);
    // 0x800A0D14: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x800A0D18: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
L_800A0D1C:
    // 0x800A0D1C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0D20: nop

    // 0x800A0D24: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800A0D28: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x800A0D2C: bne         $at, $zero, L_800A0A8C
    if (ctx->r1 != 0) {
        // 0x800A0D30: sw          $t4, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r12;
            goto L_800A0A8C;
    }
    // 0x800A0D30: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x800A0D34: b           L_800A1050
    // 0x800A0D38: nop

        goto L_800A1050;
    // 0x800A0D38: nop

L_800A0D3C:
    // 0x800A0D3C: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A0D40: nop

    // 0x800A0D44: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x800A0D48: nop

    // 0x800A0D4C: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x800A0D50: nop

    // 0x800A0D54: beq         $t9, $zero, L_800A1050
    if (ctx->r25 == 0) {
        // 0x800A0D58: nop
    
            goto L_800A1050;
    }
    // 0x800A0D58: nop

    // 0x800A0D5C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_800A0D60:
    // 0x800A0D60: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x800A0D64: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0D68: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800A0D6C: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800A0D70: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x800A0D74: nop

    // 0x800A0D78: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x800A0D7C: lw          $t4, 0x20($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X20);
    // 0x800A0D80: lw          $t8, 0xC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC);
    // 0x800A0D84: nop

    // 0x800A0D88: addu        $t6, $t4, $t8
    ctx->r14 = ADD32(ctx->r12, ctx->r24);
    // 0x800A0D8C: beq         $t6, $zero, L_800A1038
    if (ctx->r14 == 0) {
        // 0x800A0D90: nop
    
            goto L_800A1038;
    }
    // 0x800A0D90: nop

    // 0x800A0D94: lw          $t9, 0x34($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X34);
    // 0x800A0D98: nop

    // 0x800A0D9C: beq         $t9, $zero, L_800A1038
    if (ctx->r25 == 0) {
        // 0x800A0DA0: nop
    
            goto L_800A1038;
    }
    // 0x800A0DA0: nop

    // 0x800A0DA4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A0DA8: addiu       $a1, $a1, 0x4FC
    ctx->r5 = ADD32(ctx->r5, 0X4FC);
    // 0x800A0DAC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800A0DB0: jal         0x800B62D4
    // 0x800A0DB4: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x800A0DB4: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_8:
    // 0x800A0DB8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A0DBC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A0DC0: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A0DC4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A0DC8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A0DCC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A0DD0: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A0DD4: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A0DD8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A0DDC: addiu       $t0, $sp, 0x48
    ctx->r8 = ADD32(ctx->r29, 0X48);
    // 0x800A0DE0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A0DE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A0DE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A0DEC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A0DF0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A0DF4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A0DF8: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800A0DFC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A0E00: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A0E04: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A0E08: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800A0E0C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800A0E10: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800A0E14: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A0E18: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A0E1C: jal         0x80077960
    // 0x800A0E20: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_9;
    // 0x800A0E20: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_9:
    // 0x800A0E24: lhu         $t6, 0x40($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X40);
    // 0x800A0E28: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x800A0E2C: addiu       $t5, $t6, 0x50
    ctx->r13 = ADD32(ctx->r14, 0X50);
    // 0x800A0E30: sh          $t5, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r13;
    // 0x800A0E34: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x800A0E38: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0E3C: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x800A0E40: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A0E44: addu        $t7, $t0, $t2
    ctx->r15 = ADD32(ctx->r8, ctx->r10);
    // 0x800A0E48: lw          $t4, 0x20($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X20);
    // 0x800A0E4C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800A0E50: lw          $a0, 0x34($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X34);
    // 0x800A0E54: jal         0x80078424
    // 0x800A0E58: addu        $a1, $t4, $t8
    ctx->r5 = ADD32(ctx->r12, ctx->r24);
    FUN_SRAM_80078424_twelveliner_div60_loop_30t_b(rdram, ctx);
        goto after_10;
    // 0x800A0E58: addu        $a1, $t4, $t8
    ctx->r5 = ADD32(ctx->r12, ctx->r24);
    after_10:
    // 0x800A0E5C: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800A0E60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A0E64: addiu       $a1, $a1, 0x500
    ctx->r5 = ADD32(ctx->r5, 0X500);
    // 0x800A0E68: addiu       $a2, $s0, 0x1
    ctx->r6 = ADD32(ctx->r16, 0X1);
    // 0x800A0E6C: jal         0x800B62D4
    // 0x800A0E70: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_11;
    // 0x800A0E70: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_11:
    // 0x800A0E74: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A0E78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A0E7C: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A0E80: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A0E84: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A0E88: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A0E8C: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A0E90: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A0E94: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A0E98: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x800A0E9C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A0EA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A0EA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A0EA8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A0EAC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A0EB0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A0EB4: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800A0EB8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A0EBC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A0EC0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800A0EC4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A0EC8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800A0ECC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A0ED0: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A0ED4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A0ED8: jal         0x80077960
    // 0x800A0EDC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_12;
    // 0x800A0EDC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_12:
    // 0x800A0EE0: lhu         $t2, 0x40($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X40);
    // 0x800A0EE4: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x800A0EE8: addiu       $t7, $t2, 0x46
    ctx->r15 = ADD32(ctx->r10, 0X46);
    // 0x800A0EEC: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x800A0EF0: lw          $t8, 0x8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X8);
    // 0x800A0EF4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0EF8: lw          $t6, 0xC($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC);
    // 0x800A0EFC: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800A0F00: addu        $t3, $t6, $t9
    ctx->r11 = ADD32(ctx->r14, ctx->r25);
    // 0x800A0F04: lw          $t1, 0x20($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X20);
    // 0x800A0F08: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x800A0F0C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A0F10: addiu       $a1, $a1, 0x504
    ctx->r5 = ADD32(ctx->r5, 0X504);
    // 0x800A0F14: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800A0F18: jal         0x800B62D4
    // 0x800A0F1C: addu        $a2, $t1, $t0
    ctx->r6 = ADD32(ctx->r9, ctx->r8);
    sprintf_recomp(rdram, ctx);
        goto after_13;
    // 0x800A0F1C: addu        $a2, $t1, $t0
    ctx->r6 = ADD32(ctx->r9, ctx->r8);
    after_13:
    // 0x800A0F20: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A0F24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A0F28: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A0F2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A0F30: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A0F34: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A0F38: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A0F3C: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A0F40: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A0F44: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x800A0F48: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A0F4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A0F50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A0F54: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A0F58: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A0F5C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A0F60: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800A0F64: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A0F68: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A0F6C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800A0F70: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800A0F74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A0F78: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A0F7C: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A0F80: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A0F84: jal         0x80077960
    // 0x800A0F88: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_14;
    // 0x800A0F88: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_14:
    // 0x800A0F8C: lhu         $t9, 0x40($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X40);
    // 0x800A0F90: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A0F94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A0F98: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A0F9C: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x800A0FA0: addiu       $t3, $t9, 0x50
    ctx->r11 = ADD32(ctx->r25, 0X50);
    // 0x800A0FA4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A0FA8: sh          $t3, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r11;
    // 0x800A0FAC: lw          $t0, 0x8($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X8);
    // 0x800A0FB0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0FB4: lw          $t2, 0xC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC);
    // 0x800A0FB8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A0FBC: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x800A0FC0: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x800A0FC4: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800A0FC8: lw          $a0, 0x34($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X34);
    // 0x800A0FCC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A0FD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A0FD4: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x800A0FD8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A0FDC: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800A0FE0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A0FE4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A0FE8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A0FEC: andi        $a2, $t3, 0xFFFF
    ctx->r6 = ctx->r11 & 0XFFFF;
    // 0x800A0FF0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A0FF4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A0FF8: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A0FFC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A1000: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A1004: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A1008: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A100C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800A1010: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x800A1014: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800A1018: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800A101C: jal         0x80071480
    // 0x800A1020: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    displayTimeFormatted_XY_RGBA(rdram, ctx);
        goto after_15;
    // 0x800A1020: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_15:
    // 0x800A1024: lhu         $t2, 0x42($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1028: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x800A102C: addiu       $t4, $t2, 0x12
    ctx->r12 = ADD32(ctx->r10, 0X12);
    // 0x800A1030: sh          $t4, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r12;
    // 0x800A1034: sh          $t8, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r24;
L_800A1038:
    // 0x800A1038: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A103C: nop

    // 0x800A1040: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x800A1044: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x800A1048: bne         $at, $zero, L_800A0D60
    if (ctx->r1 != 0) {
        // 0x800A104C: sw          $t3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r11;
            goto L_800A0D60;
    }
    // 0x800A104C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
L_800A1050:
    // 0x800A1050: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A1054: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800A1058: jr          $ra
    // 0x800A105C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800A105C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}

RECOMP_FUNC void func_800A1060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1060: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800A1064: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x800A1068: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A106C: addiu       $t6, $zero, 0x98
    ctx->r14 = ADD32(0, 0X98);
    // 0x800A1070: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x800A1074: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A1078: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x800A107C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800A1080: sh          $t6, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r14;
    // 0x800A1084: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x800A1088: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800A108C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800A1090: lbu         $t0, 0xB($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XB);
    // 0x800A1094: nop

    // 0x800A1098: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x800A109C: bne         $t1, $at, L_800A1358
    if (ctx->r9 != ctx->r1) {
        // 0x800A10A0: nop
    
            goto L_800A1358;
    }
    // 0x800A10A0: nop

    // 0x800A10A4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_800A10A8:
    // 0x800A10A8: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800A10AC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A10B0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800A10B4: lw          $t2, -0x310($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X310);
    // 0x800A10B8: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800A10BC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800A10C0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800A10C4: addiu       $t6, $t5, 0xFFC
    ctx->r14 = ADD32(ctx->r13, 0XFFC);
    // 0x800A10C8: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800A10CC: lw          $t7, 0x1008($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X1008);
    // 0x800A10D0: nop

    // 0x800A10D4: beq         $t7, $zero, L_800A1338
    if (ctx->r15 == 0) {
        // 0x800A10D8: nop
    
            goto L_800A1338;
    }
    // 0x800A10D8: nop

    // 0x800A10DC: lw          $t8, 0x100C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X100C);
    // 0x800A10E0: nop

    // 0x800A10E4: beq         $t8, $zero, L_800A1338
    if (ctx->r24 == 0) {
        // 0x800A10E8: nop
    
            goto L_800A1338;
    }
    // 0x800A10E8: nop

    // 0x800A10EC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A10F0: addiu       $a1, $a1, 0x508
    ctx->r5 = ADD32(ctx->r5, 0X508);
    // 0x800A10F4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800A10F8: jal         0x800B62D4
    // 0x800A10FC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A10FC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_0:
    // 0x800A1100: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1104: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A1108: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A110C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1110: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A1114: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1118: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A111C: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1120: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A1124: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x800A1128: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A112C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1130: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1134: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A1138: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A113C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A1140: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A1144: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A1148: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A114C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800A1150: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800A1154: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800A1158: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800A115C: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1160: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1164: jal         0x80077960
    // 0x800A1168: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_1;
    // 0x800A1168: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_1:
    // 0x800A116C: lhu         $t7, 0x40($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1170: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800A1174: addiu       $t5, $t7, 0x50
    ctx->r13 = ADD32(ctx->r15, 0X50);
    // 0x800A1178: sh          $t5, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r13;
    // 0x800A117C: lhu         $a1, 0x16($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X16);
    // 0x800A1180: lhu         $a0, 0x14($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X14);
    // 0x800A1184: jal         0x80078424
    // 0x800A1188: nop

    FUN_SRAM_80078424_twelveliner_div60_loop_30t_b(rdram, ctx);
        goto after_2;
    // 0x800A1188: nop

    after_2:
    // 0x800A118C: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800A1190: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A1194: addiu       $a1, $a1, 0x50C
    ctx->r5 = ADD32(ctx->r5, 0X50C);
    // 0x800A1198: addiu       $a2, $s0, 0x1
    ctx->r6 = ADD32(ctx->r16, 0X1);
    // 0x800A119C: jal         0x800B62D4
    // 0x800A11A0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x800A11A0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x800A11A4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A11A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A11AC: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A11B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A11B4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A11B8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A11BC: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A11C0: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A11C4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A11C8: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x800A11CC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A11D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A11D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A11D8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A11DC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A11E0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A11E4: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800A11E8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A11EC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A11F0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800A11F4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800A11F8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800A11FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A1200: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1204: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1208: jal         0x80077960
    // 0x800A120C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_4;
    // 0x800A120C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_4:
    // 0x800A1210: lhu         $t4, 0x40($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1214: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800A1218: addiu       $t7, $t4, 0x46
    ctx->r15 = ADD32(ctx->r12, 0X46);
    // 0x800A121C: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x800A1220: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A1224: lw          $a2, 0xC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XC);
    // 0x800A1228: addiu       $a1, $a1, 0x510
    ctx->r5 = ADD32(ctx->r5, 0X510);
    // 0x800A122C: jal         0x800B62D4
    // 0x800A1230: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x800A1230: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x800A1234: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1238: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A123C: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A1240: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1244: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A1248: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A124C: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1250: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1254: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A1258: addiu       $t8, $sp, 0x48
    ctx->r24 = ADD32(ctx->r29, 0X48);
    // 0x800A125C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A1260: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1264: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1268: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A126C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A1270: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A1274: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800A1278: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A127C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A1280: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800A1284: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A1288: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A128C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A1290: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1294: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1298: jal         0x80077960
    // 0x800A129C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_6;
    // 0x800A129C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    after_6:
    // 0x800A12A0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A12A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A12A8: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A12AC: lhu         $t2, 0x40($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X40);
    // 0x800A12B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A12B4: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A12B8: addiu       $t4, $t2, 0x50
    ctx->r12 = ADD32(ctx->r10, 0X50);
    // 0x800A12BC: sh          $t4, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r12;
    // 0x800A12C0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A12C4: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    // 0x800A12C8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800A12CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A12D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A12D4: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x800A12D8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A12DC: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800A12E0: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800A12E4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A12E8: andi        $a2, $t4, 0xFFFF
    ctx->r6 = ctx->r12 & 0XFFFF;
    // 0x800A12EC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A12F0: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A12F4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A12F8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A12FC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A1300: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A1304: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A1308: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A130C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A1310: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1314: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x800A1318: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800A131C: jal         0x80071480
    // 0x800A1320: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    displayTimeFormatted_XY_RGBA(rdram, ctx);
        goto after_7;
    // 0x800A1320: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_7:
    // 0x800A1324: lhu         $t3, 0x42($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1328: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x800A132C: addiu       $t2, $t3, 0x12
    ctx->r10 = ADD32(ctx->r11, 0X12);
    // 0x800A1330: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x800A1334: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
L_800A1338:
    // 0x800A1338: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A133C: nop

    // 0x800A1340: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800A1344: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x800A1348: bne         $at, $zero, L_800A10A8
    if (ctx->r1 != 0) {
        // 0x800A134C: sw          $t4, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r12;
            goto L_800A10A8;
    }
    // 0x800A134C: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x800A1350: b           L_800A166C
    // 0x800A1354: nop

        goto L_800A166C;
    // 0x800A1354: nop

L_800A1358:
    // 0x800A1358: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A135C: nop

    // 0x800A1360: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x800A1364: nop

    // 0x800A1368: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x800A136C: nop

    // 0x800A1370: beq         $t9, $zero, L_800A166C
    if (ctx->r25 == 0) {
        // 0x800A1374: nop
    
            goto L_800A166C;
    }
    // 0x800A1374: nop

    // 0x800A1378: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_800A137C:
    // 0x800A137C: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x800A1380: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1384: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800A1388: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800A138C: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x800A1390: nop

    // 0x800A1394: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x800A1398: lw          $t4, 0x98($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X98);
    // 0x800A139C: lw          $t8, 0x84($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X84);
    // 0x800A13A0: nop

    // 0x800A13A4: addu        $t6, $t4, $t8
    ctx->r14 = ADD32(ctx->r12, ctx->r24);
    // 0x800A13A8: beq         $t6, $zero, L_800A1654
    if (ctx->r14 == 0) {
        // 0x800A13AC: nop
    
            goto L_800A1654;
    }
    // 0x800A13AC: nop

    // 0x800A13B0: lw          $t9, 0xAC($t5)
    ctx->r25 = MEM_W(ctx->r13, 0XAC);
    // 0x800A13B4: nop

    // 0x800A13B8: beq         $t9, $zero, L_800A1654
    if (ctx->r25 == 0) {
        // 0x800A13BC: nop
    
            goto L_800A1654;
    }
    // 0x800A13BC: nop

    // 0x800A13C0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A13C4: addiu       $a1, $a1, 0x514
    ctx->r5 = ADD32(ctx->r5, 0X514);
    // 0x800A13C8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800A13CC: jal         0x800B62D4
    // 0x800A13D0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x800A13D0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_8:
    // 0x800A13D4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A13D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A13DC: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A13E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A13E4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A13E8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A13EC: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A13F0: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A13F4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A13F8: addiu       $t0, $sp, 0x48
    ctx->r8 = ADD32(ctx->r29, 0X48);
    // 0x800A13FC: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A1400: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1404: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1408: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A140C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1410: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A1414: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800A1418: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A141C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A1420: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A1424: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800A1428: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800A142C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800A1430: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1434: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1438: jal         0x80077960
    // 0x800A143C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_9;
    // 0x800A143C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_9:
    // 0x800A1440: lhu         $t6, 0x40($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1444: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x800A1448: addiu       $t5, $t6, 0x50
    ctx->r13 = ADD32(ctx->r14, 0X50);
    // 0x800A144C: sh          $t5, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r13;
    // 0x800A1450: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x800A1454: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1458: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x800A145C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A1460: addu        $t7, $t0, $t2
    ctx->r15 = ADD32(ctx->r8, ctx->r10);
    // 0x800A1464: lw          $t4, 0x98($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X98);
    // 0x800A1468: lw          $t8, 0x84($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X84);
    // 0x800A146C: lw          $a0, 0xAC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XAC);
    // 0x800A1470: jal         0x80078424
    // 0x800A1474: addu        $a1, $t4, $t8
    ctx->r5 = ADD32(ctx->r12, ctx->r24);
    FUN_SRAM_80078424_twelveliner_div60_loop_30t_b(rdram, ctx);
        goto after_10;
    // 0x800A1474: addu        $a1, $t4, $t8
    ctx->r5 = ADD32(ctx->r12, ctx->r24);
    after_10:
    // 0x800A1478: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800A147C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A1480: addiu       $a1, $a1, 0x518
    ctx->r5 = ADD32(ctx->r5, 0X518);
    // 0x800A1484: addiu       $a2, $s0, 0x1
    ctx->r6 = ADD32(ctx->r16, 0X1);
    // 0x800A1488: jal         0x800B62D4
    // 0x800A148C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_11;
    // 0x800A148C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_11:
    // 0x800A1490: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1494: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A1498: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A149C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A14A0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A14A4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A14A8: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A14AC: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A14B0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A14B4: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x800A14B8: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A14BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A14C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A14C4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A14C8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A14CC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A14D0: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800A14D4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A14D8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A14DC: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800A14E0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A14E4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800A14E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A14EC: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A14F0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A14F4: jal         0x80077960
    // 0x800A14F8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_12;
    // 0x800A14F8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_12:
    // 0x800A14FC: lhu         $t2, 0x40($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1500: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x800A1504: addiu       $t7, $t2, 0x46
    ctx->r15 = ADD32(ctx->r10, 0X46);
    // 0x800A1508: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x800A150C: lw          $t8, 0x8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X8);
    // 0x800A1510: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1514: lw          $t6, 0xC($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC);
    // 0x800A1518: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800A151C: addu        $t3, $t6, $t9
    ctx->r11 = ADD32(ctx->r14, ctx->r25);
    // 0x800A1520: lw          $t1, 0x98($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X98);
    // 0x800A1524: lw          $t0, 0x84($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X84);
    // 0x800A1528: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A152C: addiu       $a1, $a1, 0x51C
    ctx->r5 = ADD32(ctx->r5, 0X51C);
    // 0x800A1530: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800A1534: jal         0x800B62D4
    // 0x800A1538: addu        $a2, $t1, $t0
    ctx->r6 = ADD32(ctx->r9, ctx->r8);
    sprintf_recomp(rdram, ctx);
        goto after_13;
    // 0x800A1538: addu        $a2, $t1, $t0
    ctx->r6 = ADD32(ctx->r9, ctx->r8);
    after_13:
    // 0x800A153C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1540: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A1544: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A1548: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A154C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A1550: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1554: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1558: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A155C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A1560: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x800A1564: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A1568: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A156C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1570: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A1574: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A1578: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A157C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800A1580: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A1584: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A1588: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800A158C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800A1590: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A1594: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A1598: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A159C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A15A0: jal         0x80077960
    // 0x800A15A4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_14;
    // 0x800A15A4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_14:
    // 0x800A15A8: lhu         $t9, 0x40($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X40);
    // 0x800A15AC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A15B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A15B4: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A15B8: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x800A15BC: addiu       $t3, $t9, 0x50
    ctx->r11 = ADD32(ctx->r25, 0X50);
    // 0x800A15C0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A15C4: sh          $t3, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r11;
    // 0x800A15C8: lw          $t0, 0x8($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X8);
    // 0x800A15CC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A15D0: lw          $t2, 0xC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC);
    // 0x800A15D4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A15D8: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x800A15DC: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x800A15E0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800A15E4: lw          $a0, 0xAC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XAC);
    // 0x800A15E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A15EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A15F0: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x800A15F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A15F8: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800A15FC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A1600: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A1604: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A1608: andi        $a2, $t3, 0xFFFF
    ctx->r6 = ctx->r11 & 0XFFFF;
    // 0x800A160C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A1610: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1614: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1618: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A161C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A1620: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A1624: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1628: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800A162C: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x800A1630: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800A1634: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800A1638: jal         0x80071480
    // 0x800A163C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    displayTimeFormatted_XY_RGBA(rdram, ctx);
        goto after_15;
    // 0x800A163C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_15:
    // 0x800A1640: lhu         $t2, 0x42($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1644: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x800A1648: addiu       $t4, $t2, 0x12
    ctx->r12 = ADD32(ctx->r10, 0X12);
    // 0x800A164C: sh          $t4, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r12;
    // 0x800A1650: sh          $t8, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r24;
L_800A1654:
    // 0x800A1654: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1658: nop

    // 0x800A165C: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x800A1660: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x800A1664: bne         $at, $zero, L_800A137C
    if (ctx->r1 != 0) {
        // 0x800A1668: sw          $t3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r11;
            goto L_800A137C;
    }
    // 0x800A1668: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
L_800A166C:
    // 0x800A166C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A1670: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800A1674: jr          $ra
    // 0x800A1678: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800A1678: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}

RECOMP_FUNC void func_800A167C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A167C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800A1680: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x800A1684: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A1688: addiu       $t6, $zero, 0x98
    ctx->r14 = ADD32(0, 0X98);
    // 0x800A168C: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x800A1690: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A1694: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x800A1698: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800A169C: sh          $t6, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r14;
    // 0x800A16A0: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x800A16A4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800A16A8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800A16AC: lbu         $t0, 0xB($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XB);
    // 0x800A16B0: nop

    // 0x800A16B4: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x800A16B8: bne         $t1, $at, L_800A1974
    if (ctx->r9 != ctx->r1) {
        // 0x800A16BC: nop
    
            goto L_800A1974;
    }
    // 0x800A16BC: nop

    // 0x800A16C0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_800A16C4:
    // 0x800A16C4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800A16C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A16CC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800A16D0: lw          $t2, -0x310($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X310);
    // 0x800A16D4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800A16D8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800A16DC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800A16E0: addiu       $t6, $t5, 0xF84
    ctx->r14 = ADD32(ctx->r13, 0XF84);
    // 0x800A16E4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800A16E8: lw          $t7, 0xF90($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XF90);
    // 0x800A16EC: nop

    // 0x800A16F0: beq         $t7, $zero, L_800A1954
    if (ctx->r15 == 0) {
        // 0x800A16F4: nop
    
            goto L_800A1954;
    }
    // 0x800A16F4: nop

    // 0x800A16F8: lw          $t8, 0xF94($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XF94);
    // 0x800A16FC: nop

    // 0x800A1700: beq         $t8, $zero, L_800A1954
    if (ctx->r24 == 0) {
        // 0x800A1704: nop
    
            goto L_800A1954;
    }
    // 0x800A1704: nop

    // 0x800A1708: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A170C: addiu       $a1, $a1, 0x520
    ctx->r5 = ADD32(ctx->r5, 0X520);
    // 0x800A1710: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800A1714: jal         0x800B62D4
    // 0x800A1718: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800A1718: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_0:
    // 0x800A171C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1720: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A1724: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A1728: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A172C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A1730: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1734: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1738: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A173C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A1740: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x800A1744: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A1748: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A174C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1750: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A1754: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A1758: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A175C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A1760: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A1764: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A1768: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800A176C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800A1770: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800A1774: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800A1778: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A177C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1780: jal         0x80077960
    // 0x800A1784: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_1;
    // 0x800A1784: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_1:
    // 0x800A1788: lhu         $t7, 0x40($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X40);
    // 0x800A178C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800A1790: addiu       $t5, $t7, 0x5A
    ctx->r13 = ADD32(ctx->r15, 0X5A);
    // 0x800A1794: sh          $t5, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r13;
    // 0x800A1798: lhu         $a1, 0x16($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X16);
    // 0x800A179C: lhu         $a0, 0x14($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X14);
    // 0x800A17A0: jal         0x80078424
    // 0x800A17A4: nop

    FUN_SRAM_80078424_twelveliner_div60_loop_30t_b(rdram, ctx);
        goto after_2;
    // 0x800A17A4: nop

    after_2:
    // 0x800A17A8: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800A17AC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A17B0: addiu       $a1, $a1, 0x524
    ctx->r5 = ADD32(ctx->r5, 0X524);
    // 0x800A17B4: addiu       $a2, $s0, 0x1
    ctx->r6 = ADD32(ctx->r16, 0X1);
    // 0x800A17B8: jal         0x800B62D4
    // 0x800A17BC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x800A17BC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x800A17C0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A17C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A17C8: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A17CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A17D0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A17D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A17D8: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A17DC: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A17E0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A17E4: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x800A17E8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A17EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A17F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A17F4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A17F8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A17FC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A1800: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800A1804: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A1808: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A180C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800A1810: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800A1814: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800A1818: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A181C: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1820: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1824: jal         0x80077960
    // 0x800A1828: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_4;
    // 0x800A1828: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_4:
    // 0x800A182C: lhu         $t4, 0x40($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1830: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800A1834: addiu       $t7, $t4, 0x46
    ctx->r15 = ADD32(ctx->r12, 0X46);
    // 0x800A1838: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x800A183C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A1840: lw          $a2, 0xC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XC);
    // 0x800A1844: addiu       $a1, $a1, 0x528
    ctx->r5 = ADD32(ctx->r5, 0X528);
    // 0x800A1848: jal         0x800B62D4
    // 0x800A184C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x800A184C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x800A1850: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1854: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A1858: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A185C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1860: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A1864: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1868: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A186C: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1870: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A1874: addiu       $t8, $sp, 0x48
    ctx->r24 = ADD32(ctx->r29, 0X48);
    // 0x800A1878: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A187C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1880: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1884: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A1888: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A188C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A1890: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800A1894: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A1898: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A189C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800A18A0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A18A4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A18A8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A18AC: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A18B0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A18B4: jal         0x80077960
    // 0x800A18B8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_6;
    // 0x800A18B8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    after_6:
    // 0x800A18BC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A18C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A18C4: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A18C8: lhu         $t2, 0x40($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X40);
    // 0x800A18CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A18D0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A18D4: addiu       $t4, $t2, 0x50
    ctx->r12 = ADD32(ctx->r10, 0X50);
    // 0x800A18D8: sh          $t4, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r12;
    // 0x800A18DC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A18E0: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    // 0x800A18E4: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800A18E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A18EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A18F0: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x800A18F4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A18F8: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800A18FC: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800A1900: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A1904: andi        $a2, $t4, 0xFFFF
    ctx->r6 = ctx->r12 & 0XFFFF;
    // 0x800A1908: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A190C: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1910: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A1914: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A1918: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A191C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A1920: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A1924: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A1928: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A192C: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1930: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x800A1934: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800A1938: jal         0x80071480
    // 0x800A193C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    displayTimeFormatted_XY_RGBA(rdram, ctx);
        goto after_7;
    // 0x800A193C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_7:
    // 0x800A1940: lhu         $t3, 0x42($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1944: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x800A1948: addiu       $t2, $t3, 0x12
    ctx->r10 = ADD32(ctx->r11, 0X12);
    // 0x800A194C: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x800A1950: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
L_800A1954:
    // 0x800A1954: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1958: nop

    // 0x800A195C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800A1960: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x800A1964: bne         $at, $zero, L_800A16C4
    if (ctx->r1 != 0) {
        // 0x800A1968: sw          $t4, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r12;
            goto L_800A16C4;
    }
    // 0x800A1968: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x800A196C: b           L_800A1C88
    // 0x800A1970: nop

        goto L_800A1C88;
    // 0x800A1970: nop

L_800A1974:
    // 0x800A1974: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A1978: nop

    // 0x800A197C: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x800A1980: nop

    // 0x800A1984: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x800A1988: nop

    // 0x800A198C: beq         $t9, $zero, L_800A1C88
    if (ctx->r25 == 0) {
        // 0x800A1990: nop
    
            goto L_800A1C88;
    }
    // 0x800A1990: nop

    // 0x800A1994: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_800A1998:
    // 0x800A1998: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x800A199C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800A19A0: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800A19A4: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800A19A8: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x800A19AC: nop

    // 0x800A19B0: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x800A19B4: lw          $t4, 0x5C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X5C);
    // 0x800A19B8: lw          $t8, 0x48($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X48);
    // 0x800A19BC: nop

    // 0x800A19C0: addu        $t6, $t4, $t8
    ctx->r14 = ADD32(ctx->r12, ctx->r24);
    // 0x800A19C4: beq         $t6, $zero, L_800A1C70
    if (ctx->r14 == 0) {
        // 0x800A19C8: nop
    
            goto L_800A1C70;
    }
    // 0x800A19C8: nop

    // 0x800A19CC: lw          $t9, 0x70($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X70);
    // 0x800A19D0: nop

    // 0x800A19D4: beq         $t9, $zero, L_800A1C70
    if (ctx->r25 == 0) {
        // 0x800A19D8: nop
    
            goto L_800A1C70;
    }
    // 0x800A19D8: nop

    // 0x800A19DC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A19E0: addiu       $a1, $a1, 0x52C
    ctx->r5 = ADD32(ctx->r5, 0X52C);
    // 0x800A19E4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800A19E8: jal         0x800B62D4
    // 0x800A19EC: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x800A19EC: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_8:
    // 0x800A19F0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A19F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A19F8: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A19FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1A00: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A1A04: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1A08: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1A0C: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1A10: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A1A14: addiu       $t0, $sp, 0x48
    ctx->r8 = ADD32(ctx->r29, 0X48);
    // 0x800A1A18: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A1A1C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1A20: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1A24: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A1A28: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1A2C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A1A30: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800A1A34: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A1A38: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A1A3C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A1A40: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800A1A44: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800A1A48: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800A1A4C: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1A50: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1A54: jal         0x80077960
    // 0x800A1A58: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_9;
    // 0x800A1A58: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_9:
    // 0x800A1A5C: lhu         $t6, 0x40($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1A60: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x800A1A64: addiu       $t5, $t6, 0x5A
    ctx->r13 = ADD32(ctx->r14, 0X5A);
    // 0x800A1A68: sh          $t5, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r13;
    // 0x800A1A6C: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x800A1A70: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1A74: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x800A1A78: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A1A7C: addu        $t7, $t0, $t2
    ctx->r15 = ADD32(ctx->r8, ctx->r10);
    // 0x800A1A80: lw          $t4, 0x5C($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X5C);
    // 0x800A1A84: lw          $t8, 0x48($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X48);
    // 0x800A1A88: lw          $a0, 0x70($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X70);
    // 0x800A1A8C: jal         0x80078424
    // 0x800A1A90: addu        $a1, $t4, $t8
    ctx->r5 = ADD32(ctx->r12, ctx->r24);
    FUN_SRAM_80078424_twelveliner_div60_loop_30t_b(rdram, ctx);
        goto after_10;
    // 0x800A1A90: addu        $a1, $t4, $t8
    ctx->r5 = ADD32(ctx->r12, ctx->r24);
    after_10:
    // 0x800A1A94: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800A1A98: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A1A9C: addiu       $a1, $a1, 0x530
    ctx->r5 = ADD32(ctx->r5, 0X530);
    // 0x800A1AA0: addiu       $a2, $s0, 0x1
    ctx->r6 = ADD32(ctx->r16, 0X1);
    // 0x800A1AA4: jal         0x800B62D4
    // 0x800A1AA8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_11;
    // 0x800A1AA8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_11:
    // 0x800A1AAC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1AB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A1AB4: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A1AB8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1ABC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A1AC0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1AC4: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1AC8: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1ACC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A1AD0: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x800A1AD4: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A1AD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1ADC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1AE0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A1AE4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A1AE8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A1AEC: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800A1AF0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A1AF4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A1AF8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800A1AFC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A1B00: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800A1B04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A1B08: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1B0C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1B10: jal         0x80077960
    // 0x800A1B14: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_12;
    // 0x800A1B14: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_12:
    // 0x800A1B18: lhu         $t2, 0x40($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1B1C: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x800A1B20: addiu       $t7, $t2, 0x46
    ctx->r15 = ADD32(ctx->r10, 0X46);
    // 0x800A1B24: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x800A1B28: lw          $t8, 0x8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X8);
    // 0x800A1B2C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1B30: lw          $t6, 0xC($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC);
    // 0x800A1B34: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800A1B38: addu        $t3, $t6, $t9
    ctx->r11 = ADD32(ctx->r14, ctx->r25);
    // 0x800A1B3C: lw          $t1, 0x5C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X5C);
    // 0x800A1B40: lw          $t0, 0x48($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X48);
    // 0x800A1B44: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A1B48: addiu       $a1, $a1, 0x534
    ctx->r5 = ADD32(ctx->r5, 0X534);
    // 0x800A1B4C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800A1B50: jal         0x800B62D4
    // 0x800A1B54: addu        $a2, $t1, $t0
    ctx->r6 = ADD32(ctx->r9, ctx->r8);
    sprintf_recomp(rdram, ctx);
        goto after_13;
    // 0x800A1B54: addu        $a2, $t1, $t0
    ctx->r6 = ADD32(ctx->r9, ctx->r8);
    after_13:
    // 0x800A1B58: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1B5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A1B60: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A1B64: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1B68: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A1B6C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1B70: lhu         $a2, 0x40($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1B74: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1B78: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A1B7C: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x800A1B80: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A1B84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1B88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1B8C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A1B90: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A1B94: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A1B98: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800A1B9C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A1BA0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A1BA4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800A1BA8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800A1BAC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A1BB0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A1BB4: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1BB8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1BBC: jal         0x80077960
    // 0x800A1BC0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_14;
    // 0x800A1BC0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_14:
    // 0x800A1BC4: lhu         $t9, 0x40($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X40);
    // 0x800A1BC8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1BCC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A1BD0: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A1BD4: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x800A1BD8: addiu       $t3, $t9, 0x50
    ctx->r11 = ADD32(ctx->r25, 0X50);
    // 0x800A1BDC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A1BE0: sh          $t3, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r11;
    // 0x800A1BE4: lw          $t0, 0x8($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X8);
    // 0x800A1BE8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1BEC: lw          $t2, 0xC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC);
    // 0x800A1BF0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A1BF4: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x800A1BF8: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x800A1BFC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800A1C00: lw          $a0, 0x70($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X70);
    // 0x800A1C04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1C08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1C0C: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x800A1C10: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1C14: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800A1C18: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A1C1C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A1C20: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A1C24: andi        $a2, $t3, 0xFFFF
    ctx->r6 = ctx->r11 & 0XFFFF;
    // 0x800A1C28: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A1C2C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1C30: lhu         $a3, 0x42($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1C34: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A1C38: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A1C3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A1C40: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1C44: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800A1C48: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x800A1C4C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800A1C50: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800A1C54: jal         0x80071480
    // 0x800A1C58: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    displayTimeFormatted_XY_RGBA(rdram, ctx);
        goto after_15;
    // 0x800A1C58: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_15:
    // 0x800A1C5C: lhu         $t2, 0x42($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X42);
    // 0x800A1C60: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x800A1C64: addiu       $t4, $t2, 0x12
    ctx->r12 = ADD32(ctx->r10, 0X12);
    // 0x800A1C68: sh          $t4, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r12;
    // 0x800A1C6C: sh          $t8, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r24;
L_800A1C70:
    // 0x800A1C70: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1C74: nop

    // 0x800A1C78: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x800A1C7C: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x800A1C80: bne         $at, $zero, L_800A1998
    if (ctx->r1 != 0) {
        // 0x800A1C84: sw          $t3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r11;
            goto L_800A1998;
    }
    // 0x800A1C84: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
L_800A1C88:
    // 0x800A1C88: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A1C8C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800A1C90: jr          $ra
    // 0x800A1C94: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800A1C94: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}

RECOMP_FUNC void func_800A1C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1C98: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800A1C9C: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x800A1CA0: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A1CA4: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x800A1CA8: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x800A1CAC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A1CB0: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x800A1CB4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800A1CB8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800A1CBC: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
    // 0x800A1CC0: sh          $t7, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r15;
    // 0x800A1CC4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800A1CC8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800A1CCC: lbu         $t0, 0xB($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XB);
    // 0x800A1CD0: nop

    // 0x800A1CD4: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x800A1CD8: bne         $t1, $at, L_800A1D88
    if (ctx->r9 != ctx->r1) {
        // 0x800A1CDC: nop
    
            goto L_800A1D88;
    }
    // 0x800A1CDC: nop

    // 0x800A1CE0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A1CE4: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x800A1CE8: jal         0x8007BCB4
    // 0x800A1CEC: nop

    SaveData_GetTotalWonderLines(rdram, ctx);
        goto after_0;
    // 0x800A1CEC: nop

    after_0:
    // 0x800A1CF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A1CF4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A1CF8: addiu       $a1, $a1, 0x538
    ctx->r5 = ADD32(ctx->r5, 0X538);
    // 0x800A1CFC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800A1D00: jal         0x800B62D4
    // 0x800A1D04: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A1D04: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_1:
    // 0x800A1D08: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1D0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A1D10: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A1D14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1D18: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A1D1C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1D20: lhu         $a2, 0x44($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X44);
    // 0x800A1D24: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x800A1D28: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A1D2C: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x800A1D30: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A1D34: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1D38: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1D3C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A1D40: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A1D44: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A1D48: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800A1D4C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A1D50: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A1D54: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800A1D58: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800A1D5C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800A1D60: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A1D64: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1D68: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1D6C: jal         0x80077960
    // 0x800A1D70: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_2;
    // 0x800A1D70: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_2:
    // 0x800A1D74: lhu         $t8, 0x46($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X46);
    // 0x800A1D78: nop

    // 0x800A1D7C: addiu       $t9, $t8, 0xF
    ctx->r25 = ADD32(ctx->r24, 0XF);
    // 0x800A1D80: b           L_800A2134
    // 0x800A1D84: sh          $t9, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r25;
        goto L_800A2134;
    // 0x800A1D84: sh          $t9, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r25;
L_800A1D88:
    // 0x800A1D88: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x800A1D8C: nop

    // 0x800A1D90: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800A1D94: nop

    // 0x800A1D98: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800A1D9C: nop

    // 0x800A1DA0: beq         $t2, $zero, L_800A2134
    if (ctx->r10 == 0) {
        // 0x800A1DA4: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_800A2134;
    }
    // 0x800A1DA4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1DA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A1DAC: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A1DB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1DB4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A1DB8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1DBC: lhu         $a2, 0x44($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X44);
    // 0x800A1DC0: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x800A1DC4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A1DC8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A1DCC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A1DD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1DD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1DD8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A1DDC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1DE0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A1DE4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A1DE8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A1DEC: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800A1DF0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800A1DF4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800A1DF8: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1DFC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1E00: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A1E04: jal         0x80077960
    // 0x800A1E08: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_3;
    // 0x800A1E08: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_3:
    // 0x800A1E0C: lhu         $t8, 0x44($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X44);
    // 0x800A1E10: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x800A1E14: addiu       $t9, $t8, 0x50
    ctx->r25 = ADD32(ctx->r24, 0X50);
    // 0x800A1E18: sh          $t9, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r25;
    // 0x800A1E1C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800A1E20: nop

    // 0x800A1E24: lw          $a0, 0xC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XC);
    // 0x800A1E28: jal         0x80078300
    // 0x800A1E2C: nop

    FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(rdram, ctx);
        goto after_4;
    // 0x800A1E2C: nop

    after_4:
    // 0x800A1E30: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x800A1E34: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A1E38: addiu       $a1, $a1, 0x550
    ctx->r5 = ADD32(ctx->r5, 0X550);
    // 0x800A1E3C: addiu       $a2, $s1, 0x1
    ctx->r6 = ADD32(ctx->r17, 0X1);
    // 0x800A1E40: jal         0x800B62D4
    // 0x800A1E44: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x800A1E44: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x800A1E48: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1E4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A1E50: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A1E54: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1E58: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A1E5C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1E60: lhu         $a2, 0x44($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X44);
    // 0x800A1E64: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x800A1E68: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A1E6C: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x800A1E70: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A1E74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1E78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1E7C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A1E80: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A1E84: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A1E88: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800A1E8C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A1E90: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A1E94: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800A1E98: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800A1E9C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800A1EA0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A1EA4: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1EA8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1EAC: jal         0x80077960
    // 0x800A1EB0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_6;
    // 0x800A1EB0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_6:
    // 0x800A1EB4: lhu         $t8, 0x46($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X46);
    // 0x800A1EB8: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x800A1EBC: addiu       $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
    // 0x800A1EC0: addiu       $t9, $t8, 0x13
    ctx->r25 = ADD32(ctx->r24, 0X13);
    // 0x800A1EC4: sh          $t9, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r25;
    // 0x800A1EC8: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x800A1ECC: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800A1ED0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A1ED4: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x800A1ED8: addiu       $a1, $a1, 0x554
    ctx->r5 = ADD32(ctx->r5, 0X554);
    // 0x800A1EDC: lw          $a2, 0xC4($t3)
    ctx->r6 = MEM_W(ctx->r11, 0XC4);
    // 0x800A1EE0: jal         0x800B62D4
    // 0x800A1EE4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x800A1EE4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_7:
    // 0x800A1EE8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1EEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A1EF0: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A1EF4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1EF8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A1EFC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1F00: lhu         $a2, 0x44($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X44);
    // 0x800A1F04: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x800A1F08: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A1F0C: addiu       $t4, $sp, 0x48
    ctx->r12 = ADD32(ctx->r29, 0X48);
    // 0x800A1F10: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A1F14: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1F18: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1F1C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A1F20: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A1F24: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A1F28: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800A1F2C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A1F30: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A1F34: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A1F38: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800A1F3C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800A1F40: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800A1F44: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1F48: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1F4C: jal         0x80077960
    // 0x800A1F50: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_8;
    // 0x800A1F50: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_8:
    // 0x800A1F54: lhu         $t0, 0x46($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X46);
    // 0x800A1F58: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800A1F5C: addiu       $t1, $t0, 0xF
    ctx->r9 = ADD32(ctx->r8, 0XF);
    // 0x800A1F60: sh          $t1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r9;
    // 0x800A1F64: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800A1F68: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A1F6C: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x800A1F70: addiu       $a1, $a1, 0x568
    ctx->r5 = ADD32(ctx->r5, 0X568);
    // 0x800A1F74: lw          $a2, 0xC8($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XC8);
    // 0x800A1F78: jal         0x800B62D4
    // 0x800A1F7C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_9;
    // 0x800A1F7C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_9:
    // 0x800A1F80: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1F84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A1F88: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A1F8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1F90: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A1F94: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A1F98: lhu         $a2, 0x44($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X44);
    // 0x800A1F9C: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x800A1FA0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A1FA4: addiu       $t5, $sp, 0x48
    ctx->r13 = ADD32(ctx->r29, 0X48);
    // 0x800A1FA8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A1FAC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1FB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1FB4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A1FB8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1FBC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A1FC0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800A1FC4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A1FC8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A1FCC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800A1FD0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800A1FD4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A1FD8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800A1FDC: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A1FE0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A1FE4: jal         0x80077960
    // 0x800A1FE8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_10;
    // 0x800A1FE8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_10:
    // 0x800A1FEC: lhu         $t1, 0x46($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X46);
    // 0x800A1FF0: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x800A1FF4: addiu       $t2, $t1, 0xF
    ctx->r10 = ADD32(ctx->r9, 0XF);
    // 0x800A1FF8: sh          $t2, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r10;
    // 0x800A1FFC: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x800A2000: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A2004: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x800A2008: addiu       $a1, $a1, 0x584
    ctx->r5 = ADD32(ctx->r5, 0X584);
    // 0x800A200C: lw          $a2, 0xCC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XCC);
    // 0x800A2010: jal         0x800B62D4
    // 0x800A2014: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_11;
    // 0x800A2014: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_11:
    // 0x800A2018: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A201C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A2020: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A2024: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A2028: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A202C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A2030: lhu         $a2, 0x44($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X44);
    // 0x800A2034: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x800A2038: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A203C: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x800A2040: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800A2044: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2048: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A204C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A2050: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A2054: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A2058: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800A205C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A2060: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A2064: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800A2068: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800A206C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A2070: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A2074: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A2078: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A207C: jal         0x80077960
    // 0x800A2080: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_12;
    // 0x800A2080: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_12:
    // 0x800A2084: lhu         $t2, 0x46($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X46);
    // 0x800A2088: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x800A208C: addiu       $t3, $t2, 0xF
    ctx->r11 = ADD32(ctx->r10, 0XF);
    // 0x800A2090: sh          $t3, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r11;
    // 0x800A2094: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800A2098: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A209C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x800A20A0: addiu       $a1, $a1, 0x59C
    ctx->r5 = ADD32(ctx->r5, 0X59C);
    // 0x800A20A4: lw          $t7, 0xC8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC8);
    // 0x800A20A8: lw          $t8, 0xCC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XCC);
    // 0x800A20AC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800A20B0: jal         0x800B62D4
    // 0x800A20B4: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    sprintf_recomp(rdram, ctx);
        goto after_13;
    // 0x800A20B4: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    after_13:
    // 0x800A20B8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A20BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A20C0: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800A20C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A20C8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A20CC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A20D0: lhu         $a2, 0x44($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X44);
    // 0x800A20D4: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x800A20D8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A20DC: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x800A20E0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A20E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A20E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A20EC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A20F0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A20F4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A20F8: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A20FC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A2100: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A2104: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A2108: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800A210C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800A2110: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800A2114: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A2118: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A211C: jal         0x80077960
    // 0x800A2120: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_14;
    // 0x800A2120: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_14:
    // 0x800A2124: lhu         $t5, 0x46($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X46);
    // 0x800A2128: nop

    // 0x800A212C: addiu       $t6, $t5, 0xF
    ctx->r14 = ADD32(ctx->r13, 0XF);
    // 0x800A2130: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
L_800A2134:
    // 0x800A2134: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A2138: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800A213C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800A2140: jr          $ra
    // 0x800A2144: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800A2144: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}

RECOMP_FUNC void func_800A2148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2148: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800A214C: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x800A2150: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800A2154: addiu       $t6, $zero, 0x98
    ctx->r14 = ADD32(0, 0X98);
    // 0x800A2158: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x800A215C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A2160: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x800A2164: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800A2168: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x800A216C: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x800A2170: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800A2174: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800A2178: lbu         $t0, 0xB($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XB);
    // 0x800A217C: nop

    // 0x800A2180: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x800A2184: bne         $t1, $at, L_800A2490
    if (ctx->r9 != ctx->r1) {
        // 0x800A2188: nop
    
            goto L_800A2490;
    }
    // 0x800A2188: nop

    // 0x800A218C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800A2190: addiu       $t2, $t2, 0x5AC
    ctx->r10 = ADD32(ctx->r10, 0X5AC);
    // 0x800A2194: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A2198: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A219C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A21A0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A21A4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A21A8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A21AC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800A21B0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800A21B4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800A21B8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800A21BC: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A21C0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A21C4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A21C8: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x800A21CC: jal         0x80077960
    // 0x800A21D0: addiu       $a3, $zero, 0x98
    ctx->r7 = ADD32(0, 0X98);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_0;
    // 0x800A21D0: addiu       $a3, $zero, 0x98
    ctx->r7 = ADD32(0, 0X98);
    after_0:
    // 0x800A21D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A21D8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A21DC: addiu       $a1, $a1, 0x5B4
    ctx->r5 = ADD32(ctx->r5, 0X5B4);
    // 0x800A21E0: jal         0x80077D88
    // 0x800A21E4: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    Font_GetTextWidth(rdram, ctx);
        goto after_1;
    // 0x800A21E4: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    after_1:
    // 0x800A21E8: lhu         $t7, 0x3C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A21EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A21F0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A21F4: addiu       $t9, $t9, 0x5BC
    ctx->r25 = ADD32(ctx->r25, 0X5BC);
    // 0x800A21F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A21FC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A2200: lhu         $a3, 0x3E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A2204: addiu       $t0, $zero, 0x5A
    ctx->r8 = ADD32(0, 0X5A);
    // 0x800A2208: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x800A220C: addiu       $t2, $zero, 0xB9
    ctx->r10 = ADD32(0, 0XB9);
    // 0x800A2210: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A2214: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800A2218: sh          $t8, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r24;
    // 0x800A221C: andi        $a2, $t8, 0xFFFF
    ctx->r6 = ctx->r24 & 0XFFFF;
    // 0x800A2220: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800A2224: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A2228: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800A222C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800A2230: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A2234: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A2238: jal         0x80077960
    // 0x800A223C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_2;
    // 0x800A223C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_2:
    // 0x800A2240: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A2244: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A2248: addiu       $a1, $a1, 0x5C0
    ctx->r5 = ADD32(ctx->r5, 0X5C0);
    // 0x800A224C: jal         0x80077D88
    // 0x800A2250: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    Font_GetTextWidth(rdram, ctx);
        goto after_3;
    // 0x800A2250: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    after_3:
    // 0x800A2254: lhu         $t4, 0x3C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A2258: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A225C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A2260: addiu       $t6, $t6, 0x5C4
    ctx->r14 = ADD32(ctx->r14, 0X5C4);
    // 0x800A2264: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A2268: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A226C: lhu         $a3, 0x3E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A2270: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A2274: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A2278: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A227C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A2280: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x800A2284: sh          $t5, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r13;
    // 0x800A2288: andi        $a2, $t5, 0xFFFF
    ctx->r6 = ctx->r13 & 0XFFFF;
    // 0x800A228C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800A2290: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800A2294: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800A2298: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A229C: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A22A0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A22A4: jal         0x80077960
    // 0x800A22A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_4;
    // 0x800A22A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_4:
    // 0x800A22AC: lhu         $t1, 0x3E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A22B0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800A22B4: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x800A22B8: addiu       $t4, $t4, 0x5E0
    ctx->r12 = ADD32(ctx->r12, 0X5E0);
    // 0x800A22BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A22C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A22C4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A22C8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A22CC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A22D0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A22D4: addiu       $t2, $t1, 0xF
    ctx->r10 = ADD32(ctx->r9, 0XF);
    // 0x800A22D8: sh          $t2, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r10;
    // 0x800A22DC: sh          $t3, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r11;
    // 0x800A22E0: andi        $a3, $t2, 0xFFFF
    ctx->r7 = ctx->r10 & 0XFFFF;
    // 0x800A22E4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800A22E8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A22EC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800A22F0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800A22F4: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A22F8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A22FC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800A2300: jal         0x80077960
    // 0x800A2304: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_5;
    // 0x800A2304: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_5:
    // 0x800A2308: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A230C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800A2310: addiu       $t1, $t1, 0x600
    ctx->r9 = ADD32(ctx->r9, 0X600);
    // 0x800A2314: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A2318: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A231C: lhu         $a2, 0x3C($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A2320: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A2324: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A2328: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A232C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A2330: addiu       $t0, $t9, 0xF
    ctx->r8 = ADD32(ctx->r25, 0XF);
    // 0x800A2334: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
    // 0x800A2338: andi        $a3, $t0, 0xFFFF
    ctx->r7 = ctx->r8 & 0XFFFF;
    // 0x800A233C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800A2340: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800A2344: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800A2348: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800A234C: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A2350: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A2354: jal         0x80077960
    // 0x800A2358: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_6;
    // 0x800A2358: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_6:
    // 0x800A235C: lhu         $t6, 0x3E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A2360: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800A2364: addiu       $t8, $t8, 0x614
    ctx->r24 = ADD32(ctx->r24, 0X614);
    // 0x800A2368: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A236C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A2370: lhu         $a2, 0x3C($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A2374: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A2378: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A237C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A2380: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A2384: addiu       $t7, $t6, 0xF
    ctx->r15 = ADD32(ctx->r14, 0XF);
    // 0x800A2388: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
    // 0x800A238C: andi        $a3, $t7, 0xFFFF
    ctx->r7 = ctx->r15 & 0XFFFF;
    // 0x800A2390: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800A2394: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800A2398: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800A239C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800A23A0: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A23A4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A23A8: jal         0x80077960
    // 0x800A23AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_7;
    // 0x800A23AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_7:
    // 0x800A23B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A23B4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A23B8: addiu       $a1, $a1, 0x620
    ctx->r5 = ADD32(ctx->r5, 0X620);
    // 0x800A23BC: jal         0x80077D88
    // 0x800A23C0: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    Font_GetTextWidth(rdram, ctx);
        goto after_8;
    // 0x800A23C0: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    after_8:
    // 0x800A23C4: lhu         $t2, 0x3C($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A23C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A23CC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800A23D0: addiu       $t5, $t5, 0x62C
    ctx->r13 = ADD32(ctx->r13, 0X62C);
    // 0x800A23D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A23D8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A23DC: lhu         $a3, 0x3E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A23E0: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x800A23E4: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x800A23E8: addiu       $t8, $zero, 0xB9
    ctx->r24 = ADD32(0, 0XB9);
    // 0x800A23EC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A23F0: addu        $t4, $t2, $s0
    ctx->r12 = ADD32(ctx->r10, ctx->r16);
    // 0x800A23F4: sh          $t4, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r12;
    // 0x800A23F8: andi        $a2, $t4, 0xFFFF
    ctx->r6 = ctx->r12 & 0XFFFF;
    // 0x800A23FC: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800A2400: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800A2404: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800A2408: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A240C: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A2410: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A2414: jal         0x80077960
    // 0x800A2418: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_9;
    // 0x800A2418: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_9:
    // 0x800A241C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A2420: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A2424: addiu       $a1, $a1, 0x630
    ctx->r5 = ADD32(ctx->r5, 0X630);
    // 0x800A2428: jal         0x80077D88
    // 0x800A242C: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    Font_GetTextWidth(rdram, ctx);
        goto after_10;
    // 0x800A242C: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    after_10:
    // 0x800A2430: lhu         $t0, 0x3C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A2434: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A2438: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800A243C: addiu       $t3, $t3, 0x634
    ctx->r11 = ADD32(ctx->r11, 0X634);
    // 0x800A2440: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A2444: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A2448: lhu         $a3, 0x3E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A244C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A2450: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A2454: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A2458: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A245C: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x800A2460: sh          $t1, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r9;
    // 0x800A2464: andi        $a2, $t1, 0xFFFF
    ctx->r6 = ctx->r9 & 0XFFFF;
    // 0x800A2468: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800A246C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800A2470: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800A2474: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800A2478: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A247C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A2480: jal         0x80077960
    // 0x800A2484: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_11;
    // 0x800A2484: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_11:
    // 0x800A2488: b           L_800A27AC
    // 0x800A248C: nop

        goto L_800A27AC;
    // 0x800A248C: nop

L_800A2490:
    // 0x800A2490: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x800A2494: nop

    // 0x800A2498: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800A249C: nop

    // 0x800A24A0: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800A24A4: nop

    // 0x800A24A8: beq         $t9, $zero, L_800A27AC
    if (ctx->r25 == 0) {
        // 0x800A24AC: nop
    
            goto L_800A27AC;
    }
    // 0x800A24AC: nop

    // 0x800A24B0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800A24B4: addiu       $t0, $t0, 0x648
    ctx->r8 = ADD32(ctx->r8, 0X648);
    // 0x800A24B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A24BC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A24C0: lhu         $a2, 0x3C($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A24C4: lhu         $a3, 0x3E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A24C8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A24CC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A24D0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A24D4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A24D8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800A24DC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A24E0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800A24E4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800A24E8: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A24EC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A24F0: jal         0x80077960
    // 0x800A24F4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_12;
    // 0x800A24F4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_12:
    // 0x800A24F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A24FC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A2500: addiu       $a1, $a1, 0x650
    ctx->r5 = ADD32(ctx->r5, 0X650);
    // 0x800A2504: jal         0x80077D88
    // 0x800A2508: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    Font_GetTextWidth(rdram, ctx);
        goto after_13;
    // 0x800A2508: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    after_13:
    // 0x800A250C: lhu         $t5, 0x3C($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A2510: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A2514: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800A2518: addiu       $t7, $t7, 0x658
    ctx->r15 = ADD32(ctx->r15, 0X658);
    // 0x800A251C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A2520: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A2524: lhu         $a3, 0x3E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A2528: addiu       $t8, $zero, 0x5A
    ctx->r24 = ADD32(0, 0X5A);
    // 0x800A252C: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x800A2530: addiu       $t0, $zero, 0xB9
    ctx->r8 = ADD32(0, 0XB9);
    // 0x800A2534: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A2538: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800A253C: sh          $t6, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r14;
    // 0x800A2540: andi        $a2, $t6, 0xFFFF
    ctx->r6 = ctx->r14 & 0XFFFF;
    // 0x800A2544: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800A2548: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800A254C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A2550: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800A2554: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A2558: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A255C: jal         0x80077960
    // 0x800A2560: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_14;
    // 0x800A2560: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_14:
    // 0x800A2564: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A2568: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A256C: addiu       $a1, $a1, 0x65C
    ctx->r5 = ADD32(ctx->r5, 0X65C);
    // 0x800A2570: jal         0x80077D88
    // 0x800A2574: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    Font_GetTextWidth(rdram, ctx);
        goto after_15;
    // 0x800A2574: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    after_15:
    // 0x800A2578: lhu         $t3, 0x3C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A257C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A2580: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800A2584: addiu       $t4, $t4, 0x660
    ctx->r12 = ADD32(ctx->r12, 0X660);
    // 0x800A2588: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A258C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A2590: lhu         $a3, 0x3E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A2594: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A2598: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A259C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A25A0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A25A4: addu        $t2, $t3, $s0
    ctx->r10 = ADD32(ctx->r11, ctx->r16);
    // 0x800A25A8: sh          $t2, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r10;
    // 0x800A25AC: andi        $a2, $t2, 0xFFFF
    ctx->r6 = ctx->r10 & 0XFFFF;
    // 0x800A25B0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800A25B4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A25B8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800A25BC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800A25C0: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A25C4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A25C8: jal         0x80077960
    // 0x800A25CC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_16;
    // 0x800A25CC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_16:
    // 0x800A25D0: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A25D4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800A25D8: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x800A25DC: addiu       $t3, $t3, 0x67C
    ctx->r11 = ADD32(ctx->r11, 0X67C);
    // 0x800A25E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A25E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A25E8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A25EC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A25F0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A25F4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A25F8: addiu       $t0, $t9, 0xF
    ctx->r8 = ADD32(ctx->r25, 0XF);
    // 0x800A25FC: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
    // 0x800A2600: sh          $t1, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r9;
    // 0x800A2604: andi        $a3, $t0, 0xFFFF
    ctx->r7 = ctx->r8 & 0XFFFF;
    // 0x800A2608: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800A260C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800A2610: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800A2614: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800A2618: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A261C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A2620: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A2624: jal         0x80077960
    // 0x800A2628: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_17;
    // 0x800A2628: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_17:
    // 0x800A262C: lhu         $t7, 0x3E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A2630: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A2634: addiu       $t9, $t9, 0x69C
    ctx->r25 = ADD32(ctx->r25, 0X69C);
    // 0x800A2638: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A263C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A2640: lhu         $a2, 0x3C($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A2644: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A2648: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A264C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A2650: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A2654: addiu       $t8, $t7, 0xF
    ctx->r24 = ADD32(ctx->r15, 0XF);
    // 0x800A2658: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    // 0x800A265C: andi        $a3, $t8, 0xFFFF
    ctx->r7 = ctx->r24 & 0XFFFF;
    // 0x800A2660: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800A2664: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800A2668: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800A266C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800A2670: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A2674: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A2678: jal         0x80077960
    // 0x800A267C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_18;
    // 0x800A267C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_18:
    // 0x800A2680: lhu         $t4, 0x3E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A2684: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A2688: addiu       $t6, $t6, 0x6B0
    ctx->r14 = ADD32(ctx->r14, 0X6B0);
    // 0x800A268C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A2690: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A2694: lhu         $a2, 0x3C($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A2698: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A269C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A26A0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A26A4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A26A8: addiu       $t5, $t4, 0xF
    ctx->r13 = ADD32(ctx->r12, 0XF);
    // 0x800A26AC: sh          $t5, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r13;
    // 0x800A26B0: andi        $a3, $t5, 0xFFFF
    ctx->r7 = ctx->r13 & 0XFFFF;
    // 0x800A26B4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800A26B8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800A26BC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800A26C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A26C4: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A26C8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A26CC: jal         0x80077960
    // 0x800A26D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_19;
    // 0x800A26D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_19:
    // 0x800A26D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A26D8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A26DC: addiu       $a1, $a1, 0x6BC
    ctx->r5 = ADD32(ctx->r5, 0X6BC);
    // 0x800A26E0: jal         0x80077D88
    // 0x800A26E4: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    Font_GetTextWidth(rdram, ctx);
        goto after_20;
    // 0x800A26E4: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    after_20:
    // 0x800A26E8: lhu         $t0, 0x3C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A26EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A26F0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800A26F4: addiu       $t2, $t2, 0x6C8
    ctx->r10 = ADD32(ctx->r10, 0X6C8);
    // 0x800A26F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A26FC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A2700: lhu         $a3, 0x3E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A2704: addiu       $t4, $zero, 0x5A
    ctx->r12 = ADD32(0, 0X5A);
    // 0x800A2708: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x800A270C: addiu       $t6, $zero, 0xB9
    ctx->r14 = ADD32(0, 0XB9);
    // 0x800A2710: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A2714: addu        $t3, $t0, $s0
    ctx->r11 = ADD32(ctx->r8, ctx->r16);
    // 0x800A2718: sh          $t3, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r11;
    // 0x800A271C: andi        $a2, $t3, 0xFFFF
    ctx->r6 = ctx->r11 & 0XFFFF;
    // 0x800A2720: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800A2724: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800A2728: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800A272C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800A2730: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A2734: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A2738: jal         0x80077960
    // 0x800A273C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_21;
    // 0x800A273C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_21:
    // 0x800A2740: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A2744: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A2748: addiu       $a1, $a1, 0x6CC
    ctx->r5 = ADD32(ctx->r5, 0X6CC);
    // 0x800A274C: jal         0x80077D88
    // 0x800A2750: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    Font_GetTextWidth(rdram, ctx);
        goto after_22;
    // 0x800A2750: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    after_22:
    // 0x800A2754: lhu         $t8, 0x3C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X3C);
    // 0x800A2758: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A275C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800A2760: addiu       $t1, $t1, 0x6D0
    ctx->r9 = ADD32(ctx->r9, 0X6D0);
    // 0x800A2764: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A2768: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A276C: lhu         $a3, 0x3E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X3E);
    // 0x800A2770: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A2774: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A2778: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A277C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A2780: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800A2784: sh          $t9, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r25;
    // 0x800A2788: andi        $a2, $t9, 0xFFFF
    ctx->r6 = ctx->r25 & 0XFFFF;
    // 0x800A278C: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800A2790: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A2794: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800A2798: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800A279C: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800A27A0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800A27A4: jal         0x80077960
    // 0x800A27A8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_23;
    // 0x800A27A8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_23:
L_800A27AC:
    // 0x800A27AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A27B0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800A27B4: jr          $ra
    // 0x800A27B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800A27B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}

RECOMP_FUNC void func_800A27BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A27BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A27C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800A27C4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800A27C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A27CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800A27D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A27D4: lbu         $s0, 0xC($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0XC);
    // 0x800A27D8: nop

    // 0x800A27DC: beq         $s0, $zero, L_800A2804
    if (ctx->r16 == 0) {
        // 0x800A27E0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800A2804;
    }
    // 0x800A27E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A27E4: beq         $s0, $at, L_800A281C
    if (ctx->r16 == ctx->r1) {
        // 0x800A27E8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A281C;
    }
    // 0x800A27E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A27EC: beq         $s0, $at, L_800A2834
    if (ctx->r16 == ctx->r1) {
        // 0x800A27F0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A2834;
    }
    // 0x800A27F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A27F4: beq         $s0, $at, L_800A284C
    if (ctx->r16 == ctx->r1) {
        // 0x800A27F8: nop
    
            goto L_800A284C;
    }
    // 0x800A27F8: nop

    // 0x800A27FC: b           L_800A285C
    // 0x800A2800: nop

        goto L_800A285C;
    // 0x800A2800: nop

L_800A2804:
    // 0x800A2804: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A2808: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800A280C: jal         0x800A1C98
    // 0x800A2810: addiu       $a0, $a0, 0x5014
    ctx->r4 = ADD32(ctx->r4, 0X5014);
    func_800A1C98(rdram, ctx);
        goto after_0;
    // 0x800A2810: addiu       $a0, $a0, 0x5014
    ctx->r4 = ADD32(ctx->r4, 0X5014);
    after_0:
    // 0x800A2814: b           L_800A285C
    // 0x800A2818: nop

        goto L_800A285C;
    // 0x800A2818: nop

L_800A281C:
    // 0x800A281C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A2820: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800A2824: jal         0x800A0A44
    // 0x800A2828: addiu       $a0, $a0, 0x5014
    ctx->r4 = ADD32(ctx->r4, 0X5014);
    func_800A0A44(rdram, ctx);
        goto after_1;
    // 0x800A2828: addiu       $a0, $a0, 0x5014
    ctx->r4 = ADD32(ctx->r4, 0X5014);
    after_1:
    // 0x800A282C: b           L_800A285C
    // 0x800A2830: nop

        goto L_800A285C;
    // 0x800A2830: nop

L_800A2834:
    // 0x800A2834: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A2838: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800A283C: jal         0x800A1060
    // 0x800A2840: addiu       $a0, $a0, 0x5014
    ctx->r4 = ADD32(ctx->r4, 0X5014);
    func_800A1060(rdram, ctx);
        goto after_2;
    // 0x800A2840: addiu       $a0, $a0, 0x5014
    ctx->r4 = ADD32(ctx->r4, 0X5014);
    after_2:
    // 0x800A2844: b           L_800A285C
    // 0x800A2848: nop

        goto L_800A285C;
    // 0x800A2848: nop

L_800A284C:
    // 0x800A284C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A2850: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800A2854: jal         0x800A167C
    // 0x800A2858: addiu       $a0, $a0, 0x5014
    ctx->r4 = ADD32(ctx->r4, 0X5014);
    func_800A167C(rdram, ctx);
        goto after_3;
    // 0x800A2858: addiu       $a0, $a0, 0x5014
    ctx->r4 = ADD32(ctx->r4, 0X5014);
    after_3:
L_800A285C:
    // 0x800A285C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2860: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A2864: jr          $ra
    // 0x800A2868: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A2868: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800A286C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A286C: lbu         $t6, 0xC($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XC);
    // 0x800A2870: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2874: jr          $ra
    // 0x800A2878: sb          $t6, -0x1114($at)
    MEM_B(-0X1114, ctx->r1) = ctx->r14;
    return;
    // 0x800A2878: sb          $t6, -0x1114($at)
    MEM_B(-0X1114, ctx->r1) = ctx->r14;
;}

RECOMP_FUNC void func_800A287C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A287C: jr          $ra
    // 0x800A2880: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800A2880: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

RECOMP_FUNC void func_800A2884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2884: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2888: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A288C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A2890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2894: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800A2898: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800A289C: addiu       $t8, $t8, 0x2D98
    ctx->r24 = ADD32(ctx->r24, 0X2D98);
    // 0x800A28A0: beq         $t7, $t8, L_800A2A84
    if (ctx->r15 == ctx->r24) {
        // 0x800A28A4: nop
    
            goto L_800A2A84;
    }
    // 0x800A28A4: nop

    // 0x800A28A8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800A28AC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800A28B0: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800A28B4: nop

    // 0x800A28B8: lbu         $t1, 0xB($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XB);
    // 0x800A28BC: nop

    // 0x800A28C0: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x800A28C4: bne         $t2, $at, L_800A2A84
    if (ctx->r10 != ctx->r1) {
        // 0x800A28C8: nop
    
            goto L_800A2A84;
    }
    // 0x800A28C8: nop

    // 0x800A28CC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800A28D0:
    // 0x800A28D0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800A28D4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800A28D8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800A28DC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800A28E0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A28E4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800A28E8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800A28EC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800A28F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A28F4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A28F8: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800A28FC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A2900: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A2904: sb          $t3, -0x14BB($at)
    MEM_B(-0X14BB, ctx->r1) = ctx->r11;
    // 0x800A2908: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A290C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2910: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A2914: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2918: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800A291C: sb          $zero, -0x14BA($at)
    MEM_B(-0X14BA, ctx->r1) = 0;
    // 0x800A2920: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800A2924: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x800A2928: bne         $at, $zero, L_800A28D0
    if (ctx->r1 != 0) {
        // 0x800A292C: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_800A28D0;
    }
    // 0x800A292C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800A2930: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A2934: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2938: sh          $zero, 0x2E1C($at)
    MEM_H(0X2E1C, ctx->r1) = 0;
    // 0x800A293C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800A2940: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800A2944: addiu       $t2, $t2, 0x2D80
    ctx->r10 = ADD32(ctx->r10, 0X2D80);
    // 0x800A2948: bne         $t1, $t2, L_800A2958
    if (ctx->r9 != ctx->r10) {
        // 0x800A294C: nop
    
            goto L_800A2958;
    }
    // 0x800A294C: nop

    // 0x800A2950: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x800A2954: sb          $t4, 0xB($t1)
    MEM_B(0XB, ctx->r9) = ctx->r12;
L_800A2958:
    // 0x800A2958: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800A295C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A2960: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x800A2964: jal         0x8007A078
    // 0x800A2968: nop

    displayText_SaveSlot(rdram, ctx);
        goto after_0;
    // 0x800A2968: nop

    after_0:
    // 0x800A296C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800A2970: lbu         $t5, 0x57A0($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X57A0);
    // 0x800A2974: nop

    // 0x800A2978: beq         $t5, $zero, L_800A29DC
    if (ctx->r13 == 0) {
        // 0x800A297C: nop
    
            goto L_800A29DC;
    }
    // 0x800A297C: nop

    // 0x800A2980: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A2984: addiu       $a0, $a0, 0x2D80
    ctx->r4 = ADD32(ctx->r4, 0X2D80);
    // 0x800A2988: jal         0x8007A078
    // 0x800A298C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    displayText_SaveSlot(rdram, ctx);
        goto after_1;
    // 0x800A298C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800A2990: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800A2994: lbu         $a2, 0x57A0($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X57A0);
    // 0x800A2998: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800A299C: lbu         $a1, 0x5688($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X5688);
    // 0x800A29A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800A29A4: jal         0x80042800
    // 0x800A29A8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    OpponentPlayer_Init(rdram, ctx);
        goto after_2;
    // 0x800A29A8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_2:
    // 0x800A29AC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800A29B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A29B4: sh          $t6, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r14;
    // 0x800A29B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A29BC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800A29C0: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800A29C4: sb          $t7, -0x1513($at)
    MEM_B(-0X1513, ctx->r1) = ctx->r15;
    // 0x800A29C8: addiu       $t9, $t9, 0xA00
    ctx->r25 = ADD32(ctx->r25, 0XA00);
    // 0x800A29CC: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x800A29D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A29D4: b           L_800A29F0
    // 0x800A29D8: sb          $t8, 0x62E5($at)
    MEM_B(0X62E5, ctx->r1) = ctx->r24;
        goto L_800A29F0;
    // 0x800A29D8: sb          $t8, 0x62E5($at)
    MEM_B(0X62E5, ctx->r1) = ctx->r24;
L_800A29DC:
    // 0x800A29DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A29E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A29E4: sh          $t0, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r8;
    // 0x800A29E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A29EC: sb          $zero, -0x1513($at)
    MEM_B(-0X1513, ctx->r1) = 0;
L_800A29F0:
    // 0x800A29F0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A29F4: jal         0x800785E0
    // 0x800A29F8: addiu       $a0, $a0, 0x2D80
    ctx->r4 = ADD32(ctx->r4, 0X2D80);
    FUN_SRAM_800785e0_sixliner_loop_arg0_t(rdram, ctx);
        goto after_3;
    // 0x800A29F8: addiu       $a0, $a0, 0x2D80
    ctx->r4 = ADD32(ctx->r4, 0X2D80);
    after_3:
    // 0x800A29FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A2A00: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800A2A04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2A08: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x800A2A0C: sb          $t2, 0x3CF0($at)
    MEM_B(0X3CF0, ctx->r1) = ctx->r10;
    // 0x800A2A10: jal         0x80048934
    // 0x800A2A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    wonders4_BuildFillRectDL(rdram, ctx);
        goto after_4;
    // 0x800A2A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800A2A18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A2A1C: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
    // 0x800A2A20: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A2A24: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x800A2A28: jal         0x80048934
    // 0x800A2A2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wonders4_BuildFillRectDL(rdram, ctx);
        goto after_5;
    // 0x800A2A2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x800A2A30: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800A2A34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A2A38: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
    // 0x800A2A3C: addiu       $t4, $zero, 0xFE
    ctx->r12 = ADD32(0, 0XFE);
    // 0x800A2A40: sb          $t4, 0x5D($t1)
    MEM_B(0X5D, ctx->r9) = ctx->r12;
    // 0x800A2A44: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800A2A48: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800A2A4C: addiu       $t3, $t3, 0x2D80
    ctx->r11 = ADD32(ctx->r11, 0X2D80);
    // 0x800A2A50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2A54: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800A2A58: sw          $t3, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r11;
    // 0x800A2A5C: sb          $t6, 0x2DA3($at)
    MEM_B(0X2DA3, ctx->r1) = ctx->r14;
    // 0x800A2A60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2A64: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x800A2A68: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800A2A6C: lbu         $t8, 0x5688($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5688);
    // 0x800A2A70: sb          $t7, 0x2D8B($at)
    MEM_B(0X2D8B, ctx->r1) = ctx->r15;
    // 0x800A2A74: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800A2A78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2A7C: sb          $t8, -0x1114($at)
    MEM_B(-0X1114, ctx->r1) = ctx->r24;
    // 0x800A2A80: sb          $zero, 0x61($t9)
    MEM_B(0X61, ctx->r25) = 0;
L_800A2A84:
    // 0x800A2A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A2A88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A2A8C: jr          $ra
    // 0x800A2A90: nop

    return;
    // 0x800A2A90: nop

;}

RECOMP_FUNC void func_800A2A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2A94: lbu         $t6, 0xC($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XC);
    // 0x800A2A98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2A9C: jr          $ra
    // 0x800A2AA0: sb          $t6, -0x1513($at)
    MEM_B(-0X1513, ctx->r1) = ctx->r14;
    return;
    // 0x800A2AA0: sb          $t6, -0x1513($at)
    MEM_B(-0X1513, ctx->r1) = ctx->r14;
;}

RECOMP_FUNC void func_800A2AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2AA4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800A2AA8: lbu         $t6, 0x3D34($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3D34);
    // 0x800A2AAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A2AB0: beq         $t6, $zero, L_800A2E1C
    if (ctx->r14 == 0) {
        // 0x800A2AB4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800A2E1C;
    }
    // 0x800A2AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2AB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2ABC: sh          $zero, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = 0;
    // 0x800A2AC0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800A2AC4: lw          $t7, 0x5ACC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5ACC);
    // 0x800A2AC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2ACC: sh          $zero, 0x2E1C($at)
    MEM_H(0X2E1C, ctx->r1) = 0;
    // 0x800A2AD0: lbu         $t8, 0xB($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XB);
    // 0x800A2AD4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800A2AD8: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x800A2ADC: beq         $t9, $at, L_800A2AEC
    if (ctx->r25 == ctx->r1) {
        // 0x800A2AE0: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_800A2AEC;
    }
    // 0x800A2AE0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800A2AE4: bne         $t9, $at, L_800A2B38
    if (ctx->r25 != ctx->r1) {
        // 0x800A2AE8: nop
    
            goto L_800A2B38;
    }
    // 0x800A2AE8: nop

L_800A2AEC:
    // 0x800A2AEC: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800A2AF0: lw          $t0, 0x5ACC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5ACC);
    // 0x800A2AF4: nop

    // 0x800A2AF8: lbu         $t1, 0xB($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XB);
    // 0x800A2AFC: nop

    // 0x800A2B00: sra         $t2, $t1, 4
    ctx->r10 = S32(SIGNED(ctx->r9) >> 4);
    // 0x800A2B04: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x800A2B08: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800A2B0C: beq         $t4, $zero, L_800A2B80
    if (ctx->r12 == 0) {
        // 0x800A2B10: nop
    
            goto L_800A2B80;
    }
    // 0x800A2B10: nop

    // 0x800A2B14: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800A2B18: jal         0x8007A078
    // 0x800A2B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    displayText_SaveSlot(rdram, ctx);
        goto after_0;
    // 0x800A2B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800A2B20: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800A2B24: lh          $t5, -0x12C($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X12C);
    // 0x800A2B28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2B2C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800A2B30: b           L_800A2B80
    // 0x800A2B34: sh          $t6, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r14;
        goto L_800A2B80;
    // 0x800A2B34: sh          $t6, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r14;
L_800A2B38:
    // 0x800A2B38: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800A2B3C: lw          $t7, 0x5ACC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5ACC);
    // 0x800A2B40: nop

    // 0x800A2B44: lbu         $t8, 0xB($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XB);
    // 0x800A2B48: nop

    // 0x800A2B4C: sra         $t9, $t8, 4
    ctx->r25 = S32(SIGNED(ctx->r24) >> 4);
    // 0x800A2B50: andi        $t1, $t9, 0xF
    ctx->r9 = ctx->r25 & 0XF;
    // 0x800A2B54: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800A2B58: beq         $t2, $zero, L_800A2B80
    if (ctx->r10 == 0) {
        // 0x800A2B5C: nop
    
            goto L_800A2B80;
    }
    // 0x800A2B5C: nop

    // 0x800A2B60: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A2B64: jal         0x8007A078
    // 0x800A2B68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    displayText_SaveSlot(rdram, ctx);
        goto after_1;
    // 0x800A2B68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800A2B6C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800A2B70: lh          $t3, -0x12C($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X12C);
    // 0x800A2B74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2B78: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800A2B7C: sh          $t4, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r12;
L_800A2B80:
    // 0x800A2B80: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800A2B84: lw          $t0, 0x5B30($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5B30);
    // 0x800A2B88: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800A2B8C: lbu         $t5, 0xB($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XB);
    // 0x800A2B90: nop

    // 0x800A2B94: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x800A2B98: beq         $t6, $at, L_800A2BA8
    if (ctx->r14 == ctx->r1) {
        // 0x800A2B9C: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_800A2BA8;
    }
    // 0x800A2B9C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800A2BA0: bne         $t6, $at, L_800A2BF4
    if (ctx->r14 != ctx->r1) {
        // 0x800A2BA4: nop
    
            goto L_800A2BF4;
    }
    // 0x800A2BA4: nop

L_800A2BA8:
    // 0x800A2BA8: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800A2BAC: lw          $t8, 0x5B30($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5B30);
    // 0x800A2BB0: nop

    // 0x800A2BB4: lbu         $t9, 0xB($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XB);
    // 0x800A2BB8: nop

    // 0x800A2BBC: sra         $t1, $t9, 4
    ctx->r9 = S32(SIGNED(ctx->r25) >> 4);
    // 0x800A2BC0: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x800A2BC4: andi        $t7, $t2, 0x2
    ctx->r15 = ctx->r10 & 0X2;
    // 0x800A2BC8: beq         $t7, $zero, L_800A2C3C
    if (ctx->r15 == 0) {
        // 0x800A2BCC: nop
    
            goto L_800A2C3C;
    }
    // 0x800A2BCC: nop

    // 0x800A2BD0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800A2BD4: jal         0x8007A078
    // 0x800A2BD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    displayText_SaveSlot(rdram, ctx);
        goto after_2;
    // 0x800A2BD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x800A2BDC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800A2BE0: lh          $t3, -0x12C($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X12C);
    // 0x800A2BE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2BE8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800A2BEC: b           L_800A2C3C
    // 0x800A2BF0: sh          $t4, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r12;
        goto L_800A2C3C;
    // 0x800A2BF0: sh          $t4, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r12;
L_800A2BF4:
    // 0x800A2BF4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800A2BF8: lw          $t0, 0x5B30($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5B30);
    // 0x800A2BFC: nop

    // 0x800A2C00: lbu         $t5, 0xB($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XB);
    // 0x800A2C04: nop

    // 0x800A2C08: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800A2C0C: andi        $t9, $t6, 0xF
    ctx->r25 = ctx->r14 & 0XF;
    // 0x800A2C10: andi        $t1, $t9, 0x2
    ctx->r9 = ctx->r25 & 0X2;
    // 0x800A2C14: beq         $t1, $zero, L_800A2C3C
    if (ctx->r9 == 0) {
        // 0x800A2C18: nop
    
            goto L_800A2C3C;
    }
    // 0x800A2C18: nop

    // 0x800A2C1C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800A2C20: jal         0x8007A078
    // 0x800A2C24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    displayText_SaveSlot(rdram, ctx);
        goto after_3;
    // 0x800A2C24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x800A2C28: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800A2C2C: lh          $t2, -0x12C($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X12C);
    // 0x800A2C30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2C34: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x800A2C38: sh          $t7, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r15;
L_800A2C3C:
    // 0x800A2C3C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800A2C40: lw          $t8, 0x5B94($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5B94);
    // 0x800A2C44: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800A2C48: lbu         $t3, 0xB($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0XB);
    // 0x800A2C4C: nop

    // 0x800A2C50: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x800A2C54: beq         $t4, $at, L_800A2C64
    if (ctx->r12 == ctx->r1) {
        // 0x800A2C58: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_800A2C64;
    }
    // 0x800A2C58: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800A2C5C: bne         $t4, $at, L_800A2CB0
    if (ctx->r12 != ctx->r1) {
        // 0x800A2C60: nop
    
            goto L_800A2CB0;
    }
    // 0x800A2C60: nop

L_800A2C64:
    // 0x800A2C64: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800A2C68: lw          $t5, 0x5B94($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5B94);
    // 0x800A2C6C: nop

    // 0x800A2C70: lbu         $t6, 0xB($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XB);
    // 0x800A2C74: nop

    // 0x800A2C78: sra         $t9, $t6, 4
    ctx->r25 = S32(SIGNED(ctx->r14) >> 4);
    // 0x800A2C7C: andi        $t1, $t9, 0xF
    ctx->r9 = ctx->r25 & 0XF;
    // 0x800A2C80: andi        $t0, $t1, 0x4
    ctx->r8 = ctx->r9 & 0X4;
    // 0x800A2C84: beq         $t0, $zero, L_800A2CF8
    if (ctx->r8 == 0) {
        // 0x800A2C88: nop
    
            goto L_800A2CF8;
    }
    // 0x800A2C88: nop

    // 0x800A2C8C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800A2C90: jal         0x8007A078
    // 0x800A2C94: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    displayText_SaveSlot(rdram, ctx);
        goto after_4;
    // 0x800A2C94: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x800A2C98: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800A2C9C: lh          $t2, -0x12C($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X12C);
    // 0x800A2CA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2CA4: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x800A2CA8: b           L_800A2CF8
    // 0x800A2CAC: sh          $t7, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r15;
        goto L_800A2CF8;
    // 0x800A2CAC: sh          $t7, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r15;
L_800A2CB0:
    // 0x800A2CB0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800A2CB4: lw          $t8, 0x5B94($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5B94);
    // 0x800A2CB8: nop

    // 0x800A2CBC: lbu         $t3, 0xB($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0XB);
    // 0x800A2CC0: nop

    // 0x800A2CC4: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x800A2CC8: andi        $t6, $t4, 0xF
    ctx->r14 = ctx->r12 & 0XF;
    // 0x800A2CCC: andi        $t9, $t6, 0x4
    ctx->r25 = ctx->r14 & 0X4;
    // 0x800A2CD0: beq         $t9, $zero, L_800A2CF8
    if (ctx->r25 == 0) {
        // 0x800A2CD4: nop
    
            goto L_800A2CF8;
    }
    // 0x800A2CD4: nop

    // 0x800A2CD8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800A2CDC: jal         0x8007A078
    // 0x800A2CE0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    displayText_SaveSlot(rdram, ctx);
        goto after_5;
    // 0x800A2CE0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x800A2CE4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800A2CE8: lh          $t1, -0x12C($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X12C);
    // 0x800A2CEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2CF0: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x800A2CF4: sh          $t0, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r8;
L_800A2CF8:
    // 0x800A2CF8: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800A2CFC: lw          $t5, 0x5BF8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5BF8);
    // 0x800A2D00: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800A2D04: lbu         $t2, 0xB($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0XB);
    // 0x800A2D08: nop

    // 0x800A2D0C: andi        $t7, $t2, 0xF
    ctx->r15 = ctx->r10 & 0XF;
    // 0x800A2D10: beq         $t7, $at, L_800A2D20
    if (ctx->r15 == ctx->r1) {
        // 0x800A2D14: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_800A2D20;
    }
    // 0x800A2D14: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800A2D18: bne         $t7, $at, L_800A2D6C
    if (ctx->r15 != ctx->r1) {
        // 0x800A2D1C: nop
    
            goto L_800A2D6C;
    }
    // 0x800A2D1C: nop

L_800A2D20:
    // 0x800A2D20: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800A2D24: lw          $t3, 0x5BF8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5BF8);
    // 0x800A2D28: nop

    // 0x800A2D2C: lbu         $t4, 0xB($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XB);
    // 0x800A2D30: nop

    // 0x800A2D34: sra         $t6, $t4, 4
    ctx->r14 = S32(SIGNED(ctx->r12) >> 4);
    // 0x800A2D38: andi        $t9, $t6, 0xF
    ctx->r25 = ctx->r14 & 0XF;
    // 0x800A2D3C: andi        $t8, $t9, 0x8
    ctx->r24 = ctx->r25 & 0X8;
    // 0x800A2D40: beq         $t8, $zero, L_800A2DB4
    if (ctx->r24 == 0) {
        // 0x800A2D44: nop
    
            goto L_800A2DB4;
    }
    // 0x800A2D44: nop

    // 0x800A2D48: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800A2D4C: jal         0x8007A078
    // 0x800A2D50: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    displayText_SaveSlot(rdram, ctx);
        goto after_6;
    // 0x800A2D50: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x800A2D54: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800A2D58: lh          $t1, -0x12C($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X12C);
    // 0x800A2D5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2D60: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x800A2D64: b           L_800A2DB4
    // 0x800A2D68: sh          $t0, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r8;
        goto L_800A2DB4;
    // 0x800A2D68: sh          $t0, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r8;
L_800A2D6C:
    // 0x800A2D6C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800A2D70: lw          $t5, 0x5BF8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5BF8);
    // 0x800A2D74: nop

    // 0x800A2D78: lbu         $t2, 0xB($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0XB);
    // 0x800A2D7C: nop

    // 0x800A2D80: sra         $t7, $t2, 4
    ctx->r15 = S32(SIGNED(ctx->r10) >> 4);
    // 0x800A2D84: andi        $t4, $t7, 0xF
    ctx->r12 = ctx->r15 & 0XF;
    // 0x800A2D88: andi        $t6, $t4, 0x8
    ctx->r14 = ctx->r12 & 0X8;
    // 0x800A2D8C: beq         $t6, $zero, L_800A2DB4
    if (ctx->r14 == 0) {
        // 0x800A2D90: nop
    
            goto L_800A2DB4;
    }
    // 0x800A2D90: nop

    // 0x800A2D94: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800A2D98: jal         0x8007A078
    // 0x800A2D9C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    displayText_SaveSlot(rdram, ctx);
        goto after_7;
    // 0x800A2D9C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x800A2DA0: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800A2DA4: lh          $t9, -0x12C($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X12C);
    // 0x800A2DA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2DAC: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x800A2DB0: sh          $t8, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r24;
L_800A2DB4:
    // 0x800A2DB4: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800A2DB8: lh          $t3, -0x12C($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X12C);
    // 0x800A2DBC: nop

    // 0x800A2DC0: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800A2DC4: beq         $at, $zero, L_800A2DE0
    if (ctx->r1 == 0) {
        // 0x800A2DC8: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800A2DE0;
    }
    // 0x800A2DC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2DCC: sb          $zero, 0x3D34($at)
    MEM_B(0X3D34, ctx->r1) = 0;
    // 0x800A2DD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2DD4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800A2DD8: b           L_800A2E1C
    // 0x800A2DDC: sh          $t1, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r9;
        goto L_800A2E1C;
    // 0x800A2DDC: sh          $t1, -0x12C($at)
    MEM_H(-0X12C, ctx->r1) = ctx->r9;
L_800A2DE0:
    // 0x800A2DE0: addiu       $t0, $zero, 0xFE
    ctx->r8 = ADD32(0, 0XFE);
    // 0x800A2DE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2DE8: jal         0x800A2E2C
    // 0x800A2DEC: sb          $t0, 0x5B21($at)
    MEM_B(0X5B21, ctx->r1) = ctx->r8;
    func_800A2E2C(rdram, ctx);
        goto after_8;
    // 0x800A2DEC: sb          $t0, 0x5B21($at)
    MEM_B(0X5B21, ctx->r1) = ctx->r8;
    after_8:
    // 0x800A2DF0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800A2DF4: lbu         $t2, 0x5AC0($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X5AC0);
    // 0x800A2DF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2DFC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800A2E00: lbu         $t7, 0x5CE4($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X5CE4);
    // 0x800A2E04: sb          $t2, -0x1114($at)
    MEM_B(-0X1114, ctx->r1) = ctx->r10;
    // 0x800A2E08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2E0C: sb          $t7, -0x1513($at)
    MEM_B(-0X1513, ctx->r1) = ctx->r15;
    // 0x800A2E10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E14: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A2E18: sb          $t4, 0x3CF0($at)
    MEM_B(0X3CF0, ctx->r1) = ctx->r12;
L_800A2E1C:
    // 0x800A2E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A2E20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A2E24: jr          $ra
    // 0x800A2E28: nop

    return;
    // 0x800A2E28: nop

;}

RECOMP_FUNC void func_800A2E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2E2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E30: addiu       $t6, $zero, 0xFE
    ctx->r14 = ADD32(0, 0XFE);
    // 0x800A2E34: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A2E38: sb          $t6, 0x5B21($at)
    MEM_B(0X5B21, ctx->r1) = ctx->r14;
    // 0x800A2E3C: sb          $t7, 0x5B20($at)
    MEM_B(0X5B20, ctx->r1) = ctx->r15;
    // 0x800A2E40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E44: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A2E48: sb          $t8, 0x5B84($at)
    MEM_B(0X5B84, ctx->r1) = ctx->r24;
    // 0x800A2E4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E50: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800A2E54: sb          $t9, 0x5BE8($at)
    MEM_B(0X5BE8, ctx->r1) = ctx->r25;
    // 0x800A2E58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E5C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800A2E60: sb          $t0, 0x5C4C($at)
    MEM_B(0X5C4C, ctx->r1) = ctx->r8;
    // 0x800A2E64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E68: sb          $zero, 0x5B25($at)
    MEM_B(0X5B25, ctx->r1) = 0;
    // 0x800A2E6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E70: sb          $zero, 0x5B89($at)
    MEM_B(0X5B89, ctx->r1) = 0;
    // 0x800A2E74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E78: sb          $zero, 0x5BED($at)
    MEM_B(0X5BED, ctx->r1) = 0;
    // 0x800A2E7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E80: sb          $zero, 0x5C51($at)
    MEM_B(0X5C51, ctx->r1) = 0;
    // 0x800A2E84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E88: sb          $zero, 0x5B26($at)
    MEM_B(0X5B26, ctx->r1) = 0;
    // 0x800A2E8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E90: sb          $zero, 0x5B8A($at)
    MEM_B(0X5B8A, ctx->r1) = 0;
    // 0x800A2E94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E98: sb          $zero, 0x5BEE($at)
    MEM_B(0X5BEE, ctx->r1) = 0;
    // 0x800A2E9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2EA0: sb          $zero, 0x5C52($at)
    MEM_B(0X5C52, ctx->r1) = 0;
    // 0x800A2EA4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800A2EA8: addiu       $t1, $t1, 0x2D80
    ctx->r9 = ADD32(ctx->r9, 0X2D80);
    // 0x800A2EAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2EB0: sw          $t1, 0x5ACC($at)
    MEM_W(0X5ACC, ctx->r1) = ctx->r9;
    // 0x800A2EB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2EB8: sw          $t1, 0x5B30($at)
    MEM_W(0X5B30, ctx->r1) = ctx->r9;
    // 0x800A2EBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2EC0: sw          $t1, 0x5B94($at)
    MEM_W(0X5B94, ctx->r1) = ctx->r9;
    // 0x800A2EC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2EC8: sw          $t1, 0x5BF8($at)
    MEM_W(0X5BF8, ctx->r1) = ctx->r9;
    // 0x800A2ECC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2ED0: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800A2ED4: sb          $t2, 0x2DA3($at)
    MEM_B(0X2DA3, ctx->r1) = ctx->r10;
    // 0x800A2ED8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2EDC: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x800A2EE0: sb          $t3, 0x2D8B($at)
    MEM_B(0X2D8B, ctx->r1) = ctx->r11;
    // 0x800A2EE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2EE8: jr          $ra
    // 0x800A2EEC: sb          $zero, 0x3DD8($at)
    MEM_B(0X3DD8, ctx->r1) = 0;
    return;
    // 0x800A2EEC: sb          $zero, 0x3DD8($at)
    MEM_B(0X3DD8, ctx->r1) = 0;
;}

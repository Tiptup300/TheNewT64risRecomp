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

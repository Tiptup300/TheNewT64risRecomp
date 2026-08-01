#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Gbpak_Init(uint8_t* rdram, recomp_context* ctx) {
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

RECOMP_FUNC void Gbpak_ReadId(uint8_t* rdram, recomp_context* ctx) {
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

RECOMP_FUNC void Gbpak_Read(uint8_t* rdram, recomp_context* ctx) {
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

RECOMP_FUNC void Gbpak_Write(uint8_t* rdram, recomp_context* ctx) {
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

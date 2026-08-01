#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Sprite_InitWhite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057080: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80057084: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80057088: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8005708C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80057090: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80057094: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x80057098: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x8005709C: sb          $t9, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r25;
    // 0x800570A0: sb          $t8, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r24;
    // 0x800570A4: sb          $t7, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r15;
    // 0x800570A8: jr          $ra
    // 0x800570AC: sb          $t6, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r14;
    return;
    // 0x800570AC: sb          $t6, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r14;
;}

RECOMP_FUNC void Sprite_LoadImage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800570B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800570B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800570B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800570BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800570C0: jal         0x8004A34C
    // 0x800570C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    Main_DrainMessageQueue(rdram, ctx);
        goto after_0;
    // 0x800570C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800570C8: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x800570CC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800570D0: jal         0x80074888
    // 0x800570D4: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_1;
    // 0x800570D4: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_1:
    // 0x800570D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800570DC: jal         0x8007E03C
    // 0x800570E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x800570E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800570E4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800570E8: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x800570EC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x800570F0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800570F4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800570F8: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800570FC: jal         0x800746C0
    // 0x80057100: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_3;
    // 0x80057100: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_3:
    // 0x80057104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80057108: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005710C: jr          $ra
    // 0x80057110: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80057110: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Sprite_FreeImage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80057118: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005711C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80057120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057124: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80057128: jal         0x8007E328
    // 0x8005712C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x8005712C: nop

    after_0:
    // 0x80057130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80057138: jr          $ra
    // 0x8005713C: nop

    return;
    // 0x8005713C: nop

;}

RECOMP_FUNC void Sprite_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057140: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80057144: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80057148: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005714C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80057150: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80057154: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057158: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005715C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80057160: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80057164: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x80057168: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8005716C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80057170: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80057174: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80057178: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8005717C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80057180: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80057184: lh          $t2, 0x6($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X6);
    // 0x80057188: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8005718C: lh          $a3, 0x4($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X4);
    // 0x80057190: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80057194: lbu         $t3, 0x8($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X8);
    // 0x80057198: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005719C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800571A0: lbu         $t4, 0x9($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X9);
    // 0x800571A4: nop

    // 0x800571A8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800571AC: lbu         $t5, 0xA($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0XA);
    // 0x800571B0: nop

    // 0x800571B4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800571B8: lbu         $t6, 0xB($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XB);
    // 0x800571BC: jal         0x80057460
    // 0x800571C0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_0;
    // 0x800571C0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x800571C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800571C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800571CC: jr          $ra
    // 0x800571D0: nop

    return;
    // 0x800571D0: nop

;}

RECOMP_FUNC void Sprite_LoadImagePair(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800571D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800571D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800571DC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800571E0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800571E4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800571E8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800571EC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800571F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800571F4: jal         0x8004A34C
    // 0x800571F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    Main_DrainMessageQueue(rdram, ctx);
        goto after_0;
    // 0x800571F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800571FC: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80057200: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80057204: jal         0x80074888
    // 0x80057208: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_1;
    // 0x80057208: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_1:
    // 0x8005720C: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80057210: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80057214: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80057218: jal         0x80074888
    // 0x8005721C: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_2;
    // 0x8005721C: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_2:
    // 0x80057220: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80057224: jal         0x8007E03C
    // 0x80057228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x80057228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8005722C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80057230: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80057234: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x80057238: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005723C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057240: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80057244: jal         0x800746C0
    // 0x80057248: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_4;
    // 0x80057248: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_4:
    // 0x8005724C: jal         0x8007E03C
    // 0x80057250: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x80057250: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80057254: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80057258: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8005725C: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x80057260: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80057264: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80057268: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    // 0x8005726C: jal         0x800746C0
    // 0x80057270: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_6;
    // 0x80057270: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_6:
    // 0x80057274: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80057278: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x8005727C: sh          $zero, 0x8($t0)
    MEM_H(0X8, ctx->r8) = 0;
    // 0x80057280: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80057284: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x80057288: sh          $zero, 0xA($t1)
    MEM_H(0XA, ctx->r9) = 0;
    // 0x8005728C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80057290: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80057294: sh          $t2, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r10;
    // 0x80057298: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8005729C: nop

    // 0x800572A0: sh          $t4, 0xE($t5)
    MEM_H(0XE, ctx->r13) = ctx->r12;
    // 0x800572A4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800572A8: nop

    // 0x800572AC: sb          $t6, 0x13($t7)
    MEM_B(0X13, ctx->r15) = ctx->r14;
    // 0x800572B0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800572B4: nop

    // 0x800572B8: lbu         $s3, 0x13($t8)
    ctx->r19 = MEM_BU(ctx->r24, 0X13);
    // 0x800572BC: nop

    // 0x800572C0: sb          $s3, 0x12($t8)
    MEM_B(0X12, ctx->r24) = ctx->r19;
    // 0x800572C4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800572C8: andi        $s2, $s3, 0xFF
    ctx->r18 = ctx->r19 & 0XFF;
    // 0x800572CC: sb          $s2, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r18;
    // 0x800572D0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800572D4: nop

    // 0x800572D8: sb          $s2, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r18;
    // 0x800572DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800572E0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800572E4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800572E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800572EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800572F0: jr          $ra
    // 0x800572F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800572F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Sprite_FreeImagePair(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800572F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800572FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80057300: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80057304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057308: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8005730C: jal         0x8007E328
    // 0x80057310: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x80057310: nop

    after_0:
    // 0x80057314: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80057318: nop

    // 0x8005731C: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x80057320: jal         0x8007E328
    // 0x80057324: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x80057324: nop

    after_1:
    // 0x80057328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005732C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80057330: jr          $ra
    // 0x80057334: nop

    return;
    // 0x80057334: nop

;}

RECOMP_FUNC void Sprite_DrawScaled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057338: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005733C: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80057340: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80057344: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80057348: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8005734C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057350: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80057354: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80057358: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005735C: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x80057360: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80057364: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80057368: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8005736C: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x80057370: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80057374: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80057378: nop

    // 0x8005737C: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x80057380: nop

    // 0x80057384: bne         $t2, $at, L_800573E8
    if (ctx->r10 != ctx->r1) {
        // 0x80057388: nop
    
            goto L_800573E8;
    }
    // 0x80057388: nop

    // 0x8005738C: lh          $t3, 0xE($t1)
    ctx->r11 = MEM_H(ctx->r9, 0XE);
    // 0x80057390: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x80057394: bne         $t3, $at, L_800573E8
    if (ctx->r11 != ctx->r1) {
        // 0x80057398: nop
    
            goto L_800573E8;
    }
    // 0x80057398: nop

    // 0x8005739C: lh          $t4, 0xA($t1)
    ctx->r12 = MEM_H(ctx->r9, 0XA);
    // 0x800573A0: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800573A4: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x800573A8: lh          $a3, 0x8($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X8);
    // 0x800573AC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800573B0: lbu         $t5, 0x10($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X10);
    // 0x800573B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800573B8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800573BC: lbu         $t6, 0x11($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X11);
    // 0x800573C0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800573C4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800573C8: lbu         $t7, 0x12($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X12);
    // 0x800573CC: nop

    // 0x800573D0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800573D4: lbu         $t8, 0x13($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X13);
    // 0x800573D8: jal         0x80057460
    // 0x800573DC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_0;
    // 0x800573DC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_0:
    // 0x800573E0: b           L_8005744C
    // 0x800573E4: nop

        goto L_8005744C;
    // 0x800573E4: nop

L_800573E8:
    // 0x800573E8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800573EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800573F0: lh          $t0, 0xA($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XA);
    // 0x800573F4: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x800573F8: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x800573FC: lh          $a3, 0x8($t9)
    ctx->r7 = MEM_H(ctx->r25, 0X8);
    // 0x80057400: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80057404: lbu         $t2, 0x10($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X10);
    // 0x80057408: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x8005740C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80057410: lbu         $t3, 0x11($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X11);
    // 0x80057414: nop

    // 0x80057418: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8005741C: lbu         $t4, 0x12($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X12);
    // 0x80057420: nop

    // 0x80057424: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80057428: lbu         $t5, 0x13($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X13);
    // 0x8005742C: nop

    // 0x80057430: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80057434: lh          $t6, 0xC($t9)
    ctx->r14 = MEM_H(ctx->r25, 0XC);
    // 0x80057438: nop

    // 0x8005743C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80057440: lh          $t7, 0xE($t9)
    ctx->r15 = MEM_H(ctx->r25, 0XE);
    // 0x80057444: jal         0x8005DB90
    // 0x80057448: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    Color_DrawTexRect(rdram, ctx);
        goto after_1;
    // 0x80057448: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_1:
L_8005744C:
    // 0x8005744C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80057450: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80057454: jr          $ra
    // 0x80057458: nop

    return;
    // 0x80057458: nop

    // 0x8005745C: nop

;}

RECOMP_FUNC void weird_lots_of_magic_number_setting_66xrefs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057460: beq         $a1, $zero, L_80059040
    if (ctx->r5 == 0) {
        // 0x80057464: addiu       $sp, $sp, -0x168
        ctx->r29 = ADD32(ctx->r29, -0X168);
            goto L_80059040;
    }
    // 0x80057464: addiu       $sp, $sp, -0x168
    ctx->r29 = ADD32(ctx->r29, -0X168);
    // 0x80057468: lw          $t6, 0x188($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X188);
    // 0x8005746C: nop

    // 0x80057470: beq         $t6, $zero, L_80059040
    if (ctx->r14 == 0) {
        // 0x80057474: nop
    
            goto L_80059040;
    }
    // 0x80057474: nop

    // 0x80057478: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x8005747C: nop

    // 0x80057480: sw          $t7, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r15;
    // 0x80057484: lhu         $t8, 0x2($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X2);
    // 0x80057488: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x8005748C: sw          $t8, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r24;
    // 0x80057490: lhu         $t9, 0x4($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X4);
    // 0x80057494: blez        $t1, L_80059040
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80057498: sw          $t9, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r25;
            goto L_80059040;
    }
    // 0x80057498: sw          $t9, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r25;
    // 0x8005749C: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x800574A0: nop

    // 0x800574A4: blez        $t2, L_80059040
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800574A8: nop
    
            goto L_80059040;
    }
    // 0x800574A8: nop

    // 0x800574AC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800574B0: lh          $t3, 0x164($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X164);
    // 0x800574B4: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x800574B8: nop

    // 0x800574BC: beq         $t3, $t4, L_80057728
    if (ctx->r11 == ctx->r12) {
        // 0x800574C0: nop
    
            goto L_80057728;
    }
    // 0x800574C0: nop

    // 0x800574C4: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x800574C8: beq         $t0, $zero, L_800574F0
    if (ctx->r8 == 0) {
        // 0x800574CC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800574F0;
    }
    // 0x800574CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800574D0: beq         $t0, $at, L_80057570
    if (ctx->r8 == ctx->r1) {
        // 0x800574D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80057570;
    }
    // 0x800574D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800574D8: beq         $t0, $at, L_80057530
    if (ctx->r8 == ctx->r1) {
        // 0x800574DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80057530;
    }
    // 0x800574DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800574E0: beq         $t0, $at, L_800575B0
    if (ctx->r8 == ctx->r1) {
        // 0x800574E4: nop
    
            goto L_800575B0;
    }
    // 0x800574E4: nop

    // 0x800574E8: b           L_80059040
    // 0x800574EC: nop

        goto L_80059040;
    // 0x800574EC: nop

L_800574F0:
    // 0x800574F0: addiu       $t5, $zero, 0x800
    ctx->r13 = ADD32(0, 0X800);
    // 0x800574F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800574F8: sw          $t5, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r13;
    // 0x800574FC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80057500: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80057504: sw          $t6, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r14;
    // 0x80057508: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005750C: ori         $t9, $t9, 0x1001
    ctx->r25 = ctx->r25 | 0X1001;
    // 0x80057510: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80057514: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80057518: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x8005751C: nop

    // 0x80057520: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80057524: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x80057528: b           L_80057870
    // 0x8005752C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
        goto L_80057870;
    // 0x8005752C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_80057530:
    // 0x80057530: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x80057534: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057538: sw          $t3, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r11;
    // 0x8005753C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80057540: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80057544: sw          $t4, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r12;
    // 0x80057548: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005754C: ori         $t7, $t7, 0x1001
    ctx->r15 = ctx->r15 | 0X1001;
    // 0x80057550: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80057554: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80057558: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x8005755C: nop

    // 0x80057560: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80057564: lw          $t9, 0x14C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14C);
    // 0x80057568: b           L_80057870
    // 0x8005756C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
        goto L_80057870;
    // 0x8005756C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
L_80057570:
    // 0x80057570: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x80057574: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057578: sw          $t1, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r9;
    // 0x8005757C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80057580: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x80057584: sw          $t2, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r10;
    // 0x80057588: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005758C: ori         $t5, $t5, 0x1001
    ctx->r13 = ctx->r13 | 0X1001;
    // 0x80057590: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80057594: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80057598: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x8005759C: nop

    // 0x800575A0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800575A4: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x800575A8: b           L_80057870
    // 0x800575AC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
        goto L_80057870;
    // 0x800575AC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
L_800575B0:
    // 0x800575B0: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x800575B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800575B8: sw          $t8, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r24;
    // 0x800575BC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800575C0: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x800575C4: sw          $t9, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r25;
    // 0x800575C8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800575CC: ori         $t3, $t3, 0x1001
    ctx->r11 = ctx->r11 | 0X1001;
    // 0x800575D0: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800575D4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800575D8: lw          $t4, 0x144($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X144);
    // 0x800575DC: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x800575E0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800575E4: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x800575E8: lui         $t1, 0xFD10
    ctx->r9 = S32(0XFD10 << 16);
    // 0x800575EC: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800575F0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800575F4: nop

    // 0x800575F8: sw          $t7, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r15;
    // 0x800575FC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80057600: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x80057604: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80057608: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005760C: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x80057610: nop

    // 0x80057614: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80057618: lw          $t3, 0x140($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X140);
    // 0x8005761C: nop

    // 0x80057620: sw          $a2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r6;
    // 0x80057624: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80057628: nop

    // 0x8005762C: sw          $t4, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r12;
    // 0x80057630: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80057634: lui         $t4, 0xF500
    ctx->r12 = S32(0XF500 << 16);
    // 0x80057638: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8005763C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80057640: lw          $t8, 0x13C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X13C);
    // 0x80057644: ori         $t4, $t4, 0x100
    ctx->r12 = ctx->r12 | 0X100;
    // 0x80057648: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005764C: lw          $t9, 0x13C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X13C);
    // 0x80057650: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80057654: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80057658: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005765C: nop

    // 0x80057660: sw          $t1, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r9;
    // 0x80057664: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80057668: nop

    // 0x8005766C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80057670: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80057674: lw          $t5, 0x138($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X138);
    // 0x80057678: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8005767C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80057680: lw          $t7, 0x138($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X138);
    // 0x80057684: nop

    // 0x80057688: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8005768C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80057690: nop

    // 0x80057694: sw          $t8, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r24;
    // 0x80057698: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005769C: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x800576A0: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x800576A4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800576A8: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x800576AC: lui         $t1, 0x73F
    ctx->r9 = S32(0X73F << 16);
    // 0x800576B0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800576B4: lw          $t4, 0x134($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X134);
    // 0x800576B8: ori         $t1, $t1, 0xC000
    ctx->r9 = ctx->r9 | 0XC000;
    // 0x800576BC: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800576C0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800576C4: nop

    // 0x800576C8: sw          $t5, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r13;
    // 0x800576CC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800576D0: nop

    // 0x800576D4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800576D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800576DC: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x800576E0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800576E4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800576E8: lw          $t2, 0x130($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X130);
    // 0x800576EC: nop

    // 0x800576F0: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800576F4: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800576F8: nop

    // 0x800576FC: sw          $t3, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r11;
    // 0x80057700: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80057704: nop

    // 0x80057708: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8005770C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80057710: lw          $t7, 0x12C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X12C);
    // 0x80057714: nop

    // 0x80057718: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8005771C: lw          $t8, 0x12C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X12C);
    // 0x80057720: b           L_80057870
    // 0x80057724: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
        goto L_80057870;
    // 0x80057724: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
L_80057728:
    // 0x80057728: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x8005772C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80057730: bne         $t9, $at, L_80057870
    if (ctx->r25 != ctx->r1) {
        // 0x80057734: nop
    
            goto L_80057870;
    }
    // 0x80057734: nop

    // 0x80057738: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005773C: lui         $t4, 0xFD10
    ctx->r12 = S32(0XFD10 << 16);
    // 0x80057740: sw          $t1, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r9;
    // 0x80057744: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80057748: lui         $t1, 0xE800
    ctx->r9 = S32(0XE800 << 16);
    // 0x8005774C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80057750: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80057754: lw          $t5, 0x128($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X128);
    // 0x80057758: nop

    // 0x8005775C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80057760: lw          $t6, 0x128($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X128);
    // 0x80057764: nop

    // 0x80057768: sw          $a2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r6;
    // 0x8005776C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80057770: nop

    // 0x80057774: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
    // 0x80057778: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005777C: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x80057780: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80057784: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80057788: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x8005778C: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x80057790: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80057794: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x80057798: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8005779C: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800577A0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800577A4: nop

    // 0x800577A8: sw          $t4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r12;
    // 0x800577AC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800577B0: nop

    // 0x800577B4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800577B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800577BC: lw          $t8, 0x120($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X120);
    // 0x800577C0: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x800577C4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800577C8: lw          $t1, 0x120($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X120);
    // 0x800577CC: nop

    // 0x800577D0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800577D4: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800577D8: nop

    // 0x800577DC: sw          $t2, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r10;
    // 0x800577E0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800577E4: lui         $t2, 0xF000
    ctx->r10 = S32(0XF000 << 16);
    // 0x800577E8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800577EC: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800577F0: lw          $t6, 0x11C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X11C);
    // 0x800577F4: lui         $t4, 0x73F
    ctx->r12 = S32(0X73F << 16);
    // 0x800577F8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800577FC: lw          $t7, 0x11C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X11C);
    // 0x80057800: ori         $t4, $t4, 0xC000
    ctx->r12 = ctx->r12 | 0XC000;
    // 0x80057804: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80057808: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005780C: nop

    // 0x80057810: sw          $t8, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r24;
    // 0x80057814: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80057818: nop

    // 0x8005781C: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x80057820: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80057824: lw          $t3, 0x118($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X118);
    // 0x80057828: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8005782C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80057830: lw          $t5, 0x118($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X118);
    // 0x80057834: nop

    // 0x80057838: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8005783C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80057840: nop

    // 0x80057844: sw          $t6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r14;
    // 0x80057848: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005784C: nop

    // 0x80057850: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80057854: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80057858: lw          $t1, 0x114($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X114);
    // 0x8005785C: nop

    // 0x80057860: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80057864: lw          $t2, 0x114($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X114);
    // 0x80057868: nop

    // 0x8005786C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_80057870:
    // 0x80057870: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x80057874: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80057878: lw          $t3, 0x160($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X160);
    // 0x8005787C: addiu       $t5, $t4, 0x3
    ctx->r13 = ADD32(ctx->r12, 0X3);
    // 0x80057880: andi        $t6, $t5, 0xFFFC
    ctx->r14 = ctx->r13 & 0XFFFC;
    // 0x80057884: div         $zero, $t3, $t6
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r14)));
    // 0x80057888: bne         $t6, $zero, L_80057894
    if (ctx->r14 != 0) {
        // 0x8005788C: nop
    
            goto L_80057894;
    }
    // 0x8005788C: nop

    // 0x80057890: break       7
    do_break(2147842192);
L_80057894:
    // 0x80057894: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80057898: bne         $t6, $at, L_800578AC
    if (ctx->r14 != ctx->r1) {
        // 0x8005789C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800578AC;
    }
    // 0x8005789C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800578A0: bne         $t3, $at, L_800578AC
    if (ctx->r11 != ctx->r1) {
        // 0x800578A4: nop
    
            goto L_800578AC;
    }
    // 0x800578A4: nop

    // 0x800578A8: break       6
    do_break(2147842216);
L_800578AC:
    // 0x800578AC: mflo        $t7
    ctx->r15 = lo;
    // 0x800578B0: sw          $t7, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r15;
    // 0x800578B4: blez        $t7, L_80059040
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800578B8: nop
    
            goto L_80059040;
    }
    // 0x800578B8: nop

    // 0x800578BC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800578C0: lbu         $t8, 0x168($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X168);
    // 0x800578C4: lw          $t9, 0x17C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X17C);
    // 0x800578C8: nop

    // 0x800578CC: bne         $t8, $t9, L_80057934
    if (ctx->r24 != ctx->r25) {
        // 0x800578D0: nop
    
            goto L_80057934;
    }
    // 0x800578D0: nop

    // 0x800578D4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800578D8: lbu         $t1, 0x16C($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X16C);
    // 0x800578DC: lw          $t2, 0x180($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X180);
    // 0x800578E0: nop

    // 0x800578E4: bne         $t1, $t2, L_80057934
    if (ctx->r9 != ctx->r10) {
        // 0x800578E8: nop
    
            goto L_80057934;
    }
    // 0x800578E8: nop

    // 0x800578EC: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800578F0: lbu         $t4, 0x170($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X170);
    // 0x800578F4: lw          $t5, 0x184($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X184);
    // 0x800578F8: nop

    // 0x800578FC: bne         $t4, $t5, L_80057934
    if (ctx->r12 != ctx->r13) {
        // 0x80057900: nop
    
            goto L_80057934;
    }
    // 0x80057900: nop

    // 0x80057904: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80057908: lbu         $t3, 0x174($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X174);
    // 0x8005790C: lw          $t6, 0x188($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X188);
    // 0x80057910: nop

    // 0x80057914: bne         $t3, $t6, L_80057934
    if (ctx->r11 != ctx->r14) {
        // 0x80057918: nop
    
            goto L_80057934;
    }
    // 0x80057918: nop

    // 0x8005791C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80057920: lh          $t7, 0x164($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X164);
    // 0x80057924: lw          $t8, 0x154($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X154);
    // 0x80057928: nop

    // 0x8005792C: beq         $t7, $t8, L_80057AE0
    if (ctx->r15 == ctx->r24) {
        // 0x80057930: nop
    
            goto L_80057AE0;
    }
    // 0x80057930: nop

L_80057934:
    // 0x80057934: lw          $t9, 0x188($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X188);
    // 0x80057938: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005793C: bne         $t9, $at, L_800579AC
    if (ctx->r25 != ctx->r1) {
        // 0x80057940: nop
    
            goto L_800579AC;
    }
    // 0x80057940: nop

    // 0x80057944: lw          $t1, 0x17C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X17C);
    // 0x80057948: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005794C: bne         $t1, $at, L_800579AC
    if (ctx->r9 != ctx->r1) {
        // 0x80057950: nop
    
            goto L_800579AC;
    }
    // 0x80057950: nop

    // 0x80057954: lw          $t2, 0x180($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X180);
    // 0x80057958: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005795C: bne         $t2, $at, L_800579AC
    if (ctx->r10 != ctx->r1) {
        // 0x80057960: nop
    
            goto L_800579AC;
    }
    // 0x80057960: nop

    // 0x80057964: lw          $t4, 0x184($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X184);
    // 0x80057968: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005796C: bne         $t4, $at, L_800579AC
    if (ctx->r12 != ctx->r1) {
        // 0x80057970: nop
    
            goto L_800579AC;
    }
    // 0x80057970: nop

    // 0x80057974: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80057978: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x8005797C: sw          $t5, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r13;
    // 0x80057980: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80057984: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80057988: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8005798C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80057990: lw          $t8, 0x110($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X110);
    // 0x80057994: lui         $t9, 0xFFFC
    ctx->r25 = S32(0XFFFC << 16);
    // 0x80057998: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005799C: lw          $t1, 0x110($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X110);
    // 0x800579A0: ori         $t9, $t9, 0xF279
    ctx->r25 = ctx->r25 | 0XF279;
    // 0x800579A4: b           L_80057AB0
    // 0x800579A8: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
        goto L_80057AB0;
    // 0x800579A8: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
L_800579AC:
    // 0x800579AC: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800579B0: lbu         $t2, 0x168($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X168);
    // 0x800579B4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800579B8: bne         $t2, $at, L_800579FC
    if (ctx->r10 != ctx->r1) {
        // 0x800579BC: nop
    
            goto L_800579FC;
    }
    // 0x800579BC: nop

    // 0x800579C0: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800579C4: lbu         $t4, 0x16C($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X16C);
    // 0x800579C8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800579CC: bne         $t4, $at, L_800579FC
    if (ctx->r12 != ctx->r1) {
        // 0x800579D0: nop
    
            goto L_800579FC;
    }
    // 0x800579D0: nop

    // 0x800579D4: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800579D8: lbu         $t5, 0x170($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X170);
    // 0x800579DC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800579E0: bne         $t5, $at, L_800579FC
    if (ctx->r13 != ctx->r1) {
        // 0x800579E4: nop
    
            goto L_800579FC;
    }
    // 0x800579E4: nop

    // 0x800579E8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800579EC: lbu         $t3, 0x174($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X174);
    // 0x800579F0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800579F4: beq         $t3, $at, L_80057A14
    if (ctx->r11 == ctx->r1) {
        // 0x800579F8: nop
    
            goto L_80057A14;
    }
    // 0x800579F8: nop

L_800579FC:
    // 0x800579FC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80057A00: lh          $t6, 0x164($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X164);
    // 0x80057A04: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x80057A08: nop

    // 0x80057A0C: beq         $t6, $t7, L_80057A48
    if (ctx->r14 == ctx->r15) {
        // 0x80057A10: nop
    
            goto L_80057A48;
    }
    // 0x80057A10: nop

L_80057A14:
    // 0x80057A14: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80057A18: lui         $t2, 0xFC11
    ctx->r10 = S32(0XFC11 << 16);
    // 0x80057A1C: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
    // 0x80057A20: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80057A24: ori         $t2, $t2, 0x9623
    ctx->r10 = ctx->r10 | 0X9623;
    // 0x80057A28: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x80057A2C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80057A30: lw          $t4, 0x10C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10C);
    // 0x80057A34: lui         $t5, 0xFF2F
    ctx->r13 = S32(0XFF2F << 16);
    // 0x80057A38: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x80057A3C: lw          $t3, 0x10C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10C);
    // 0x80057A40: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x80057A44: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
L_80057A48:
    // 0x80057A48: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80057A4C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80057A50: sw          $t6, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r14;
    // 0x80057A54: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80057A58: nop

    // 0x80057A5C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80057A60: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80057A64: lw          $t1, 0x108($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X108);
    // 0x80057A68: nop

    // 0x80057A6C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80057A70: lw          $t3, 0x180($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X180);
    // 0x80057A74: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x80057A78: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x80057A7C: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x80057A80: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x80057A84: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x80057A88: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80057A8C: lw          $t3, 0x188($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X188);
    // 0x80057A90: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80057A94: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x80057A98: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x80057A9C: lw          $t7, 0x108($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X108);
    // 0x80057AA0: or          $t4, $t8, $t2
    ctx->r12 = ctx->r24 | ctx->r10;
    // 0x80057AA4: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x80057AA8: or          $t5, $t4, $t6
    ctx->r13 = ctx->r12 | ctx->r14;
    // 0x80057AAC: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
L_80057AB0:
    // 0x80057AB0: lw          $t9, 0x17C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X17C);
    // 0x80057AB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057AB8: lw          $t1, 0x180($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X180);
    // 0x80057ABC: sb          $t9, 0x168($at)
    MEM_B(0X168, ctx->r1) = ctx->r25;
    // 0x80057AC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057AC4: lw          $t8, 0x184($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X184);
    // 0x80057AC8: sb          $t1, 0x16C($at)
    MEM_B(0X16C, ctx->r1) = ctx->r9;
    // 0x80057ACC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057AD0: lw          $t2, 0x188($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X188);
    // 0x80057AD4: sb          $t8, 0x170($at)
    MEM_B(0X170, ctx->r1) = ctx->r24;
    // 0x80057AD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057ADC: sb          $t2, 0x174($at)
    MEM_B(0X174, ctx->r1) = ctx->r10;
L_80057AE0:
    // 0x80057AE0: lw          $t3, 0x154($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X154);
    // 0x80057AE4: lw          $t4, 0x158($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X158);
    // 0x80057AE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057AEC: sh          $t3, 0x164($at)
    MEM_H(0X164, ctx->r1) = ctx->r11;
    // 0x80057AF0: beq         $t4, $zero, L_8005900C
    if (ctx->r12 == 0) {
        // 0x80057AF4: sw          $t4, 0x160($sp)
        MEM_W(0X160, ctx->r29) = ctx->r12;
            goto L_8005900C;
    }
    // 0x80057AF4: sw          $t4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r12;
L_80057AF8:
    // 0x80057AF8: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x80057AFC: lw          $t5, 0x164($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X164);
    // 0x80057B00: nop

    // 0x80057B04: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80057B08: beq         $at, $zero, L_800585D8
    if (ctx->r1 == 0) {
        // 0x80057B0C: nop
    
            goto L_800585D8;
    }
    // 0x80057B0C: nop

    // 0x80057B10: lw          $t0, 0x154($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X154);
    // 0x80057B14: nop

    // 0x80057B18: beq         $t0, $zero, L_80057B40
    if (ctx->r8 == 0) {
        // 0x80057B1C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80057B40;
    }
    // 0x80057B1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80057B20: beq         $t0, $at, L_80057D8C
    if (ctx->r8 == ctx->r1) {
        // 0x80057B24: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80057D8C;
    }
    // 0x80057B24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80057B28: beq         $t0, $at, L_80057FDC
    if (ctx->r8 == ctx->r1) {
        // 0x80057B2C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80057FDC;
    }
    // 0x80057B2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80057B30: beq         $t0, $at, L_80058220
    if (ctx->r8 == ctx->r1) {
        // 0x80057B34: nop
    
            goto L_80058220;
    }
    // 0x80057B34: nop

    // 0x80057B38: b           L_80058460
    // 0x80057B3C: nop

        goto L_80058460;
    // 0x80057B3C: nop

L_80057B40:
    // 0x80057B40: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80057B44: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x80057B48: sw          $t7, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r15;
    // 0x80057B4C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80057B50: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
    // 0x80057B54: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x80057B58: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80057B5C: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x80057B60: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x80057B64: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x80057B68: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x80057B6C: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80057B70: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80057B74: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x80057B78: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80057B7C: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x80057B80: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80057B84: nop

    // 0x80057B88: sw          $t9, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r25;
    // 0x80057B8C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80057B90: nop

    // 0x80057B94: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x80057B98: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80057B9C: lw          $t2, 0x15C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X15C);
    // 0x80057BA0: lw          $t1, 0x100($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X100);
    // 0x80057BA4: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80057BA8: addiu       $t4, $t3, 0x7
    ctx->r12 = ADD32(ctx->r11, 0X7);
    // 0x80057BAC: sra         $t6, $t4, 3
    ctx->r14 = S32(SIGNED(ctx->r12) >> 3);
    // 0x80057BB0: andi        $t5, $t6, 0x1FF
    ctx->r13 = ctx->r14 & 0X1FF;
    // 0x80057BB4: sll         $t7, $t5, 9
    ctx->r15 = S32(ctx->r13 << 9);
    // 0x80057BB8: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80057BBC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80057BC0: lw          $t2, 0x100($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X100);
    // 0x80057BC4: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x80057BC8: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80057BCC: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x80057BD0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80057BD4: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x80057BD8: sw          $t3, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r11;
    // 0x80057BDC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80057BE0: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80057BE4: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80057BE8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80057BEC: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x80057BF0: nop

    // 0x80057BF4: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80057BF8: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x80057BFC: nop

    // 0x80057C00: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80057C04: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80057C08: nop

    // 0x80057C0C: sw          $t1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r9;
    // 0x80057C10: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80057C14: nop

    // 0x80057C18: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x80057C1C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80057C20: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x80057C24: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x80057C28: lw          $t1, 0xF8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF8);
    // 0x80057C2C: subu        $t6, $t3, $t4
    ctx->r14 = SUB32(ctx->r11, ctx->r12);
    // 0x80057C30: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80057C34: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x80057C38: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80057C3C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80057C40: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x80057C44: lw          $t8, 0x158($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X158);
    // 0x80057C48: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x80057C4C: lw          $t4, 0x164($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X164);
    // 0x80057C50: subu        $t3, $t8, $t2
    ctx->r11 = SUB32(ctx->r24, ctx->r10);
    // 0x80057C54: addiu       $t8, $t1, -0x1
    ctx->r24 = ADD32(ctx->r9, -0X1);
    // 0x80057C58: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x80057C5C: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x80057C60: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80057C64: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x80057C68: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80057C6C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80057C70: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x80057C74: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80057C78: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x80057C7C: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x80057C80: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x80057C84: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x80057C88: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80057C8C: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80057C90: sw          $t1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r9;
    // 0x80057C94: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80057C98: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80057C9C: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x80057CA0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80057CA4: lw          $t4, 0xF4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF4);
    // 0x80057CA8: nop

    // 0x80057CAC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80057CB0: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x80057CB4: nop

    // 0x80057CB8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80057CBC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80057CC0: nop

    // 0x80057CC4: sw          $t9, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r25;
    // 0x80057CC8: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80057CCC: nop

    // 0x80057CD0: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x80057CD4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80057CD8: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x80057CDC: lw          $t5, 0xF0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF0);
    // 0x80057CE0: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x80057CE4: addiu       $t2, $t8, 0x7
    ctx->r10 = ADD32(ctx->r24, 0X7);
    // 0x80057CE8: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x80057CEC: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x80057CF0: sll         $t6, $t4, 9
    ctx->r14 = S32(ctx->r12 << 9);
    // 0x80057CF4: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80057CF8: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x80057CFC: lw          $t1, 0xF0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF0);
    // 0x80057D00: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x80057D04: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80057D08: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x80057D0C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80057D10: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80057D14: sw          $t8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r24;
    // 0x80057D18: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80057D1C: nop

    // 0x80057D20: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80057D24: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80057D28: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x80057D2C: lw          $t4, 0x158($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X158);
    // 0x80057D30: lw          $t8, 0xEC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XEC);
    // 0x80057D34: subu        $t9, $t4, $t6
    ctx->r25 = SUB32(ctx->r12, ctx->r14);
    // 0x80057D38: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80057D3C: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x80057D40: or          $t1, $t7, $at
    ctx->r9 = ctx->r15 | ctx->r1;
    // 0x80057D44: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80057D48: lw          $t3, 0x160($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X160);
    // 0x80057D4C: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x80057D50: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x80057D54: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x80057D58: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80057D5C: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x80057D60: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x80057D64: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x80057D68: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80057D6C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80057D70: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x80057D74: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
    // 0x80057D78: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x80057D7C: andi        $t1, $t7, 0xFFF
    ctx->r9 = ctx->r15 & 0XFFF;
    // 0x80057D80: or          $t9, $t6, $t1
    ctx->r25 = ctx->r14 | ctx->r9;
    // 0x80057D84: b           L_80058460
    // 0x80057D88: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
        goto L_80058460;
    // 0x80057D88: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
L_80057D8C:
    // 0x80057D8C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80057D90: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x80057D94: sw          $t7, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r15;
    // 0x80057D98: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80057D9C: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80057DA0: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x80057DA4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80057DA8: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80057DAC: lw          $t5, 0xE8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE8);
    // 0x80057DB0: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80057DB4: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80057DB8: andi        $t1, $t6, 0xFFF
    ctx->r9 = ctx->r14 & 0XFFF;
    // 0x80057DBC: or          $t9, $t1, $at
    ctx->r25 = ctx->r9 | ctx->r1;
    // 0x80057DC0: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x80057DC4: lw          $t8, 0xE8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE8);
    // 0x80057DC8: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x80057DCC: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80057DD0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80057DD4: nop

    // 0x80057DD8: sw          $t2, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r10;
    // 0x80057DDC: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80057DE0: nop

    // 0x80057DE4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80057DE8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80057DEC: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x80057DF0: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x80057DF4: sra         $t1, $t6, 1
    ctx->r9 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80057DF8: addiu       $t9, $t1, 0x7
    ctx->r25 = ADD32(ctx->r9, 0X7);
    // 0x80057DFC: sra         $t5, $t9, 3
    ctx->r13 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80057E00: andi        $t7, $t5, 0x1FF
    ctx->r15 = ctx->r13 & 0X1FF;
    // 0x80057E04: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x80057E08: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x80057E0C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80057E10: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80057E14: lui         $t4, 0x708
    ctx->r12 = S32(0X708 << 16);
    // 0x80057E18: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x80057E1C: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x80057E20: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80057E24: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80057E28: sw          $t1, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r9;
    // 0x80057E2C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80057E30: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80057E34: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x80057E38: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80057E3C: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x80057E40: nop

    // 0x80057E44: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80057E48: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x80057E4C: nop

    // 0x80057E50: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80057E54: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80057E58: nop

    // 0x80057E5C: sw          $t3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r11;
    // 0x80057E60: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80057E64: nop

    // 0x80057E68: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80057E6C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80057E70: lw          $t9, 0x160($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X160);
    // 0x80057E74: lw          $t1, 0x158($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X158);
    // 0x80057E78: lw          $t3, 0xDC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XDC);
    // 0x80057E7C: subu        $t5, $t1, $t9
    ctx->r13 = SUB32(ctx->r9, ctx->r25);
    // 0x80057E80: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80057E84: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80057E88: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x80057E8C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80057E90: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x80057E94: lw          $t4, 0x158($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X158);
    // 0x80057E98: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80057E9C: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x80057EA0: subu        $t1, $t4, $t6
    ctx->r9 = SUB32(ctx->r12, ctx->r14);
    // 0x80057EA4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80057EA8: addu        $t5, $t1, $t9
    ctx->r13 = ADD32(ctx->r9, ctx->r25);
    // 0x80057EAC: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x80057EB0: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80057EB4: andi        $t1, $t6, 0xFFF
    ctx->r9 = ctx->r14 & 0XFFF;
    // 0x80057EB8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80057EBC: andi        $t2, $t8, 0xFFF
    ctx->r10 = ctx->r24 & 0XFFF;
    // 0x80057EC0: sll         $t9, $t1, 12
    ctx->r25 = S32(ctx->r9 << 12);
    // 0x80057EC4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80057EC8: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x80057ECC: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x80057ED0: or          $t7, $t5, $t2
    ctx->r15 = ctx->r13 | ctx->r10;
    // 0x80057ED4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80057ED8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80057EDC: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80057EE0: sw          $t3, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r11;
    // 0x80057EE4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80057EE8: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x80057EEC: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80057EF0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80057EF4: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x80057EF8: nop

    // 0x80057EFC: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x80057F00: lw          $t5, 0xD8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD8);
    // 0x80057F04: nop

    // 0x80057F08: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80057F0C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80057F10: nop

    // 0x80057F14: sw          $t2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r10;
    // 0x80057F18: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80057F1C: nop

    // 0x80057F20: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80057F24: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80057F28: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80057F2C: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x80057F30: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80057F34: addiu       $t6, $t4, 0x7
    ctx->r14 = ADD32(ctx->r12, 0X7);
    // 0x80057F38: sra         $t1, $t6, 3
    ctx->r9 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80057F3C: andi        $t9, $t1, 0x1FF
    ctx->r25 = ctx->r9 & 0X1FF;
    // 0x80057F40: sll         $t5, $t9, 9
    ctx->r13 = S32(ctx->r25 << 9);
    // 0x80057F44: or          $t2, $t5, $at
    ctx->r10 = ctx->r13 | ctx->r1;
    // 0x80057F48: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x80057F4C: lw          $t3, 0xD4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD4);
    // 0x80057F50: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x80057F54: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80057F58: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x80057F5C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80057F60: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80057F64: sw          $t4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r12;
    // 0x80057F68: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80057F6C: nop

    // 0x80057F70: addiu       $t1, $t6, 0x8
    ctx->r9 = ADD32(ctx->r14, 0X8);
    // 0x80057F74: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80057F78: lw          $t5, 0x160($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X160);
    // 0x80057F7C: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x80057F80: lw          $t4, 0xD0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD0);
    // 0x80057F84: subu        $t2, $t9, $t5
    ctx->r10 = SUB32(ctx->r25, ctx->r13);
    // 0x80057F88: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x80057F8C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80057F90: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x80057F94: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80057F98: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x80057F9C: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x80057FA0: lw          $t5, 0x164($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X164);
    // 0x80057FA4: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x80057FA8: subu        $t9, $t6, $t1
    ctx->r25 = SUB32(ctx->r14, ctx->r9);
    // 0x80057FAC: addu        $t2, $t9, $t5
    ctx->r10 = ADD32(ctx->r25, ctx->r13);
    // 0x80057FB0: addiu       $t7, $t2, -0x1
    ctx->r15 = ADD32(ctx->r10, -0X1);
    // 0x80057FB4: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80057FB8: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80057FBC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80057FC0: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x80057FC4: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x80057FC8: sll         $t5, $t9, 12
    ctx->r13 = S32(ctx->r25 << 12);
    // 0x80057FCC: andi        $t3, $t8, 0xFFF
    ctx->r11 = ctx->r24 & 0XFFF;
    // 0x80057FD0: or          $t2, $t5, $t3
    ctx->r10 = ctx->r13 | ctx->r11;
    // 0x80057FD4: b           L_80058460
    // 0x80057FD8: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
        goto L_80058460;
    // 0x80057FD8: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
L_80057FDC:
    // 0x80057FDC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80057FE0: lui         $at, 0xFD68
    ctx->r1 = S32(0XFD68 << 16);
    // 0x80057FE4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
    // 0x80057FE8: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80057FEC: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80057FF0: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80057FF4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80057FF8: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x80057FFC: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x80058000: addiu       $t9, $t1, -0x1
    ctx->r25 = ADD32(ctx->r9, -0X1);
    // 0x80058004: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x80058008: or          $t3, $t5, $at
    ctx->r11 = ctx->r13 | ctx->r1;
    // 0x8005800C: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x80058010: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x80058014: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x80058018: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8005801C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80058020: nop

    // 0x80058024: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x80058028: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005802C: nop

    // 0x80058030: addiu       $t1, $t6, 0x8
    ctx->r9 = ADD32(ctx->r14, 0X8);
    // 0x80058034: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80058038: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x8005803C: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x80058040: addiu       $t5, $t9, 0x7
    ctx->r13 = ADD32(ctx->r25, 0X7);
    // 0x80058044: sra         $t3, $t5, 3
    ctx->r11 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80058048: andi        $t2, $t3, 0x1FF
    ctx->r10 = ctx->r11 & 0X1FF;
    // 0x8005804C: sll         $t7, $t2, 9
    ctx->r15 = S32(ctx->r10 << 9);
    // 0x80058050: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80058054: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80058058: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8005805C: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x80058060: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80058064: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80058068: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005806C: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x80058070: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x80058074: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80058078: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005807C: addiu       $t3, $t5, 0x8
    ctx->r11 = ADD32(ctx->r13, 0X8);
    // 0x80058080: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80058084: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x80058088: nop

    // 0x8005808C: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x80058090: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x80058094: nop

    // 0x80058098: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8005809C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800580A0: nop

    // 0x800580A4: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x800580A8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800580AC: nop

    // 0x800580B0: addiu       $t1, $t6, 0x8
    ctx->r9 = ADD32(ctx->r14, 0X8);
    // 0x800580B4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800580B8: lw          $t5, 0x160($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X160);
    // 0x800580BC: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x800580C0: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x800580C4: subu        $t3, $t9, $t5
    ctx->r11 = SUB32(ctx->r25, ctx->r13);
    // 0x800580C8: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x800580CC: andi        $t7, $t2, 0xFFF
    ctx->r15 = ctx->r10 & 0XFFF;
    // 0x800580D0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800580D4: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x800580D8: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x800580DC: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x800580E0: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x800580E4: lw          $t5, 0x164($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X164);
    // 0x800580E8: subu        $t9, $t6, $t1
    ctx->r25 = SUB32(ctx->r14, ctx->r9);
    // 0x800580EC: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x800580F0: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x800580F4: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x800580F8: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x800580FC: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x80058100: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x80058104: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80058108: sll         $t5, $t9, 12
    ctx->r13 = S32(ctx->r25 << 12);
    // 0x8005810C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80058110: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x80058114: or          $t3, $t5, $at
    ctx->r11 = ctx->r13 | ctx->r1;
    // 0x80058118: or          $t2, $t3, $t8
    ctx->r10 = ctx->r11 | ctx->r24;
    // 0x8005811C: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x80058120: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80058124: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80058128: sw          $t4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r12;
    // 0x8005812C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80058130: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x80058134: addiu       $t1, $t6, 0x8
    ctx->r9 = ADD32(ctx->r14, 0X8);
    // 0x80058138: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005813C: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x80058140: nop

    // 0x80058144: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x80058148: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x8005814C: nop

    // 0x80058150: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80058154: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80058158: nop

    // 0x8005815C: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x80058160: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80058164: nop

    // 0x80058168: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x8005816C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80058170: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x80058174: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x80058178: addiu       $t6, $t4, 0x7
    ctx->r14 = ADD32(ctx->r12, 0X7);
    // 0x8005817C: sra         $t1, $t6, 3
    ctx->r9 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80058180: andi        $t9, $t1, 0x1FF
    ctx->r25 = ctx->r9 & 0X1FF;
    // 0x80058184: sll         $t5, $t9, 9
    ctx->r13 = S32(ctx->r25 << 9);
    // 0x80058188: or          $t3, $t5, $at
    ctx->r11 = ctx->r13 | ctx->r1;
    // 0x8005818C: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80058190: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x80058194: lui         $t2, 0x8
    ctx->r10 = S32(0X8 << 16);
    // 0x80058198: ori         $t2, $t2, 0x200
    ctx->r10 = ctx->r10 | 0X200;
    // 0x8005819C: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x800581A0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800581A4: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x800581A8: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    // 0x800581AC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800581B0: nop

    // 0x800581B4: addiu       $t1, $t6, 0x8
    ctx->r9 = ADD32(ctx->r14, 0X8);
    // 0x800581B8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800581BC: lw          $t5, 0x160($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X160);
    // 0x800581C0: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x800581C4: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x800581C8: subu        $t3, $t9, $t5
    ctx->r11 = SUB32(ctx->r25, ctx->r13);
    // 0x800581CC: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x800581D0: andi        $t2, $t8, 0xFFF
    ctx->r10 = ctx->r24 & 0XFFF;
    // 0x800581D4: or          $t7, $t2, $at
    ctx->r15 = ctx->r10 | ctx->r1;
    // 0x800581D8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x800581DC: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x800581E0: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x800581E4: lw          $t5, 0x164($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X164);
    // 0x800581E8: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x800581EC: subu        $t9, $t6, $t1
    ctx->r25 = SUB32(ctx->r14, ctx->r9);
    // 0x800581F0: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x800581F4: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x800581F8: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x800581FC: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80058200: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80058204: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x80058208: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x8005820C: sll         $t5, $t9, 12
    ctx->r13 = S32(ctx->r25 << 12);
    // 0x80058210: andi        $t7, $t2, 0xFFF
    ctx->r15 = ctx->r10 & 0XFFF;
    // 0x80058214: or          $t3, $t5, $t7
    ctx->r11 = ctx->r13 | ctx->r15;
    // 0x80058218: b           L_80058460
    // 0x8005821C: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
        goto L_80058460;
    // 0x8005821C: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
L_80058220:
    // 0x80058220: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80058224: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x80058228: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    // 0x8005822C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80058230: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80058234: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80058238: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005823C: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x80058240: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x80058244: addiu       $t9, $t1, -0x1
    ctx->r25 = ADD32(ctx->r9, -0X1);
    // 0x80058248: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x8005824C: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x80058250: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80058254: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80058258: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005825C: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x80058260: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80058264: nop

    // 0x80058268: sw          $t4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r12;
    // 0x8005826C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80058270: nop

    // 0x80058274: addiu       $t1, $t6, 0x8
    ctx->r9 = ADD32(ctx->r14, 0X8);
    // 0x80058278: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005827C: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x80058280: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x80058284: addiu       $t5, $t9, 0x7
    ctx->r13 = ADD32(ctx->r25, 0X7);
    // 0x80058288: sra         $t7, $t5, 3
    ctx->r15 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8005828C: andi        $t3, $t7, 0x1FF
    ctx->r11 = ctx->r15 & 0X1FF;
    // 0x80058290: sll         $t8, $t3, 9
    ctx->r24 = S32(ctx->r11 << 9);
    // 0x80058294: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x80058298: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8005829C: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x800582A0: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x800582A4: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800582A8: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x800582AC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800582B0: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x800582B4: sw          $t9, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r25;
    // 0x800582B8: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800582BC: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x800582C0: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x800582C4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800582C8: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x800582CC: nop

    // 0x800582D0: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800582D4: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x800582D8: nop

    // 0x800582DC: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800582E0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800582E4: nop

    // 0x800582E8: sw          $t4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r12;
    // 0x800582EC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800582F0: nop

    // 0x800582F4: addiu       $t1, $t6, 0x8
    ctx->r9 = ADD32(ctx->r14, 0X8);
    // 0x800582F8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800582FC: lw          $t5, 0x160($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X160);
    // 0x80058300: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x80058304: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x80058308: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x8005830C: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x80058310: andi        $t8, $t3, 0xFFF
    ctx->r24 = ctx->r11 & 0XFFF;
    // 0x80058314: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x80058318: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8005831C: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x80058320: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x80058324: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x80058328: lw          $t5, 0x164($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X164);
    // 0x8005832C: subu        $t9, $t6, $t1
    ctx->r25 = SUB32(ctx->r14, ctx->r9);
    // 0x80058330: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80058334: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x80058338: addiu       $t3, $t7, -0x1
    ctx->r11 = ADD32(ctx->r15, -0X1);
    // 0x8005833C: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80058340: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x80058344: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80058348: andi        $t2, $t8, 0xFFF
    ctx->r10 = ctx->r24 & 0XFFF;
    // 0x8005834C: sll         $t5, $t9, 12
    ctx->r13 = S32(ctx->r25 << 12);
    // 0x80058350: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80058354: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x80058358: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x8005835C: or          $t3, $t7, $t2
    ctx->r11 = ctx->r15 | ctx->r10;
    // 0x80058360: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80058364: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80058368: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8005836C: sw          $t4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r12;
    // 0x80058370: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80058374: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80058378: addiu       $t1, $t6, 0x8
    ctx->r9 = ADD32(ctx->r14, 0X8);
    // 0x8005837C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80058380: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x80058384: nop

    // 0x80058388: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x8005838C: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80058390: nop

    // 0x80058394: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80058398: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005839C: nop

    // 0x800583A0: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    // 0x800583A4: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800583A8: nop

    // 0x800583AC: addiu       $t8, $t3, 0x8
    ctx->r24 = ADD32(ctx->r11, 0X8);
    // 0x800583B0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800583B4: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x800583B8: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x800583BC: addiu       $t6, $t4, 0x7
    ctx->r14 = ADD32(ctx->r12, 0X7);
    // 0x800583C0: sra         $t1, $t6, 3
    ctx->r9 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800583C4: andi        $t9, $t1, 0x1FF
    ctx->r25 = ctx->r9 & 0X1FF;
    // 0x800583C8: sll         $t5, $t9, 9
    ctx->r13 = S32(ctx->r25 << 9);
    // 0x800583CC: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x800583D0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x800583D4: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x800583D8: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x800583DC: ori         $t3, $t3, 0x200
    ctx->r11 = ctx->r11 | 0X200;
    // 0x800583E0: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x800583E4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800583E8: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x800583EC: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x800583F0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800583F4: nop

    // 0x800583F8: addiu       $t1, $t6, 0x8
    ctx->r9 = ADD32(ctx->r14, 0X8);
    // 0x800583FC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80058400: lw          $t5, 0x160($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X160);
    // 0x80058404: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x80058408: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x8005840C: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x80058410: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x80058414: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x80058418: or          $t8, $t3, $at
    ctx->r24 = ctx->r11 | ctx->r1;
    // 0x8005841C: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80058420: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x80058424: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x80058428: lw          $t5, 0x164($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X164);
    // 0x8005842C: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x80058430: subu        $t9, $t6, $t1
    ctx->r25 = SUB32(ctx->r14, ctx->r9);
    // 0x80058434: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x80058438: addiu       $t2, $t7, -0x1
    ctx->r10 = ADD32(ctx->r15, -0X1);
    // 0x8005843C: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80058440: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80058444: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80058448: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x8005844C: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x80058450: sll         $t5, $t9, 12
    ctx->r13 = S32(ctx->r25 << 12);
    // 0x80058454: andi        $t8, $t3, 0xFFF
    ctx->r24 = ctx->r11 & 0XFFF;
    // 0x80058458: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x8005845C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
L_80058460:
    // 0x80058460: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80058464: lui         $t1, 0xF200
    ctx->r9 = S32(0XF200 << 16);
    // 0x80058468: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x8005846C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80058470: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80058474: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80058478: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005847C: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x80058480: nop

    // 0x80058484: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x80058488: lw          $t5, 0x15C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X15C);
    // 0x8005848C: lw          $t4, 0x164($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X164);
    // 0x80058490: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80058494: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80058498: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8005849C: addiu       $t1, $t6, -0x1
    ctx->r9 = ADD32(ctx->r14, -0X1);
    // 0x800584A0: andi        $t2, $t7, 0xFFF
    ctx->r10 = ctx->r15 & 0XFFF;
    // 0x800584A4: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x800584A8: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x800584AC: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x800584B0: or          $t5, $t3, $t9
    ctx->r13 = ctx->r11 | ctx->r25;
    // 0x800584B4: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x800584B8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800584BC: nop

    // 0x800584C0: sw          $t7, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r15;
    // 0x800584C4: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800584C8: nop

    // 0x800584CC: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x800584D0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800584D4: lw          $t1, 0x158($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X158);
    // 0x800584D8: lw          $t6, 0x178($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X178);
    // 0x800584DC: lw          $t9, 0x160($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X160);
    // 0x800584E0: addu        $t3, $t6, $t1
    ctx->r11 = ADD32(ctx->r14, ctx->r9);
    // 0x800584E4: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x800584E8: lw          $t8, 0x164($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X164);
    // 0x800584EC: subu        $t5, $t3, $t9
    ctx->r13 = SUB32(ctx->r11, ctx->r25);
    // 0x800584F0: addu        $t3, $a3, $t1
    ctx->r11 = ADD32(ctx->r7, ctx->r9);
    // 0x800584F4: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800584F8: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x800584FC: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x80058500: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x80058504: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x80058508: andi        $t8, $t5, 0xFFF
    ctx->r24 = ctx->r13 & 0XFFF;
    // 0x8005850C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80058510: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x80058514: or          $t2, $t7, $at
    ctx->r10 = ctx->r15 | ctx->r1;
    // 0x80058518: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x8005851C: or          $t4, $t2, $t6
    ctx->r12 = ctx->r10 | ctx->r14;
    // 0x80058520: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80058524: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x80058528: lw          $t3, 0x178($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X178);
    // 0x8005852C: lw          $t8, 0x160($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X160);
    // 0x80058530: addu        $t5, $t3, $t9
    ctx->r13 = ADD32(ctx->r11, ctx->r25);
    // 0x80058534: sll         $t4, $a3, 2
    ctx->r12 = S32(ctx->r7 << 2);
    // 0x80058538: subu        $t7, $t5, $t8
    ctx->r15 = SUB32(ctx->r13, ctx->r24);
    // 0x8005853C: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x80058540: andi        $t1, $t4, 0xFFF
    ctx->r9 = ctx->r12 & 0XFFF;
    // 0x80058544: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x80058548: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x8005854C: andi        $t6, $t2, 0xFFF
    ctx->r14 = ctx->r10 & 0XFFF;
    // 0x80058550: or          $t9, $t3, $t6
    ctx->r25 = ctx->r11 | ctx->r14;
    // 0x80058554: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80058558: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005855C: lui         $t4, 0xE100
    ctx->r12 = S32(0XE100 << 16);
    // 0x80058560: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x80058564: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80058568: lui         $t8, 0xF100
    ctx->r24 = S32(0XF100 << 16);
    // 0x8005856C: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x80058570: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80058574: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x80058578: lui         $t2, 0x400
    ctx->r10 = S32(0X400 << 16);
    // 0x8005857C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80058580: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x80058584: ori         $t2, $t2, 0x400
    ctx->r10 = ctx->r10 | 0X400;
    // 0x80058588: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005858C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80058590: nop

    // 0x80058594: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
    // 0x80058598: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005859C: nop

    // 0x800585A0: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800585A4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800585A8: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x800585AC: nop

    // 0x800585B0: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800585B4: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800585B8: nop

    // 0x800585BC: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800585C0: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x800585C4: lw          $t3, 0x164($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X164);
    // 0x800585C8: nop

    // 0x800585CC: subu        $t6, $t1, $t3
    ctx->r14 = SUB32(ctx->r9, ctx->r11);
    // 0x800585D0: b           L_80058FFC
    // 0x800585D4: sw          $t6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r14;
        goto L_80058FFC;
    // 0x800585D4: sw          $t6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r14;
L_800585D8:
    // 0x800585D8: lw          $t0, 0x154($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X154);
    // 0x800585DC: nop

    // 0x800585E0: beq         $t0, $zero, L_80058608
    if (ctx->r8 == 0) {
        // 0x800585E4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80058608;
    }
    // 0x800585E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800585E8: beq         $t0, $at, L_80058834
    if (ctx->r8 == ctx->r1) {
        // 0x800585EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80058834;
    }
    // 0x800585EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800585F0: beq         $t0, $at, L_80058A64
    if (ctx->r8 == ctx->r1) {
        // 0x800585F4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80058A64;
    }
    // 0x800585F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800585F8: beq         $t0, $at, L_80058C88
    if (ctx->r8 == ctx->r1) {
        // 0x800585FC: nop
    
            goto L_80058C88;
    }
    // 0x800585FC: nop

    // 0x80058600: b           L_80058EA8
    // 0x80058604: nop

        goto L_80058EA8;
    // 0x80058604: nop

L_80058608:
    // 0x80058608: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005860C: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x80058610: sw          $t9, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r25;
    // 0x80058614: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80058618: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8005861C: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x80058620: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80058624: lw          $t7, 0x15C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X15C);
    // 0x80058628: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x8005862C: addiu       $t2, $t7, -0x1
    ctx->r10 = ADD32(ctx->r15, -0X1);
    // 0x80058630: andi        $t4, $t2, 0xFFF
    ctx->r12 = ctx->r10 & 0XFFF;
    // 0x80058634: or          $t1, $t4, $at
    ctx->r9 = ctx->r12 | ctx->r1;
    // 0x80058638: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x8005863C: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80058640: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80058644: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80058648: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005864C: nop

    // 0x80058650: sw          $t5, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r13;
    // 0x80058654: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80058658: nop

    // 0x8005865C: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x80058660: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80058664: lw          $t2, 0x15C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X15C);
    // 0x80058668: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8005866C: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80058670: addiu       $t1, $t4, 0x7
    ctx->r9 = ADD32(ctx->r12, 0X7);
    // 0x80058674: sra         $t3, $t1, 3
    ctx->r11 = S32(SIGNED(ctx->r9) >> 3);
    // 0x80058678: andi        $t6, $t3, 0x1FF
    ctx->r14 = ctx->r11 & 0X1FF;
    // 0x8005867C: sll         $t9, $t6, 9
    ctx->r25 = S32(ctx->r14 << 9);
    // 0x80058680: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x80058684: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x80058688: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x8005868C: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x80058690: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80058694: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80058698: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005869C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800586A0: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x800586A4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800586A8: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x800586AC: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800586B0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800586B4: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800586B8: nop

    // 0x800586BC: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800586C0: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800586C4: nop

    // 0x800586C8: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800586CC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800586D0: nop

    // 0x800586D4: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x800586D8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800586DC: nop

    // 0x800586E0: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x800586E4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800586E8: lw          $t4, 0x158($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X158);
    // 0x800586EC: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x800586F0: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800586F4: subu        $t3, $t4, $t1
    ctx->r11 = SUB32(ctx->r12, ctx->r9);
    // 0x800586F8: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800586FC: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80058700: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x80058704: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x80058708: lw          $t7, 0x15C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X15C);
    // 0x8005870C: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x80058710: addiu       $t2, $t7, -0x1
    ctx->r10 = ADD32(ctx->r15, -0X1);
    // 0x80058714: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80058718: andi        $t1, $t4, 0xFFF
    ctx->r9 = ctx->r12 & 0XFFF;
    // 0x8005871C: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x80058720: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80058724: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x80058728: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005872C: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80058730: or          $t6, $t3, $at
    ctx->r14 = ctx->r11 | ctx->r1;
    // 0x80058734: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80058738: or          $t2, $t6, $t7
    ctx->r10 = ctx->r14 | ctx->r15;
    // 0x8005873C: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x80058740: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80058744: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80058748: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x8005874C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80058750: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80058754: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x80058758: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005875C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80058760: nop

    // 0x80058764: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x80058768: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8005876C: nop

    // 0x80058770: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80058774: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80058778: nop

    // 0x8005877C: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x80058780: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80058784: nop

    // 0x80058788: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8005878C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80058790: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x80058794: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80058798: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x8005879C: addiu       $t9, $t3, 0x7
    ctx->r25 = ADD32(ctx->r11, 0X7);
    // 0x800587A0: sra         $t5, $t9, 3
    ctx->r13 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800587A4: andi        $t8, $t5, 0x1FF
    ctx->r24 = ctx->r13 & 0X1FF;
    // 0x800587A8: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x800587AC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800587B0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x800587B4: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800587B8: lui         $t4, 0x8
    ctx->r12 = S32(0X8 << 16);
    // 0x800587BC: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x800587C0: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x800587C4: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800587C8: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x800587CC: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x800587D0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800587D4: nop

    // 0x800587D8: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800587DC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800587E0: lw          $t8, 0x158($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X158);
    // 0x800587E4: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x800587E8: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x800587EC: subu        $t7, $t8, $t6
    ctx->r15 = SUB32(ctx->r24, ctx->r14);
    // 0x800587F0: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x800587F4: andi        $t4, $t2, 0xFFF
    ctx->r12 = ctx->r10 & 0XFFF;
    // 0x800587F8: or          $t1, $t4, $at
    ctx->r9 = ctx->r12 | ctx->r1;
    // 0x800587FC: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x80058800: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x80058804: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x80058808: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x8005880C: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80058810: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x80058814: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x80058818: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8005881C: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80058820: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80058824: andi        $t3, $t1, 0xFFF
    ctx->r11 = ctx->r9 & 0XFFF;
    // 0x80058828: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x8005882C: b           L_80058EA8
    // 0x80058830: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
        goto L_80058EA8;
    // 0x80058830: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
L_80058834:
    // 0x80058834: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80058838: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x8005883C: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x80058840: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80058844: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80058848: addiu       $t2, $t6, 0x8
    ctx->r10 = ADD32(ctx->r14, 0X8);
    // 0x8005884C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80058850: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x80058854: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x80058858: sra         $t1, $t4, 1
    ctx->r9 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8005885C: addiu       $t7, $t1, -0x1
    ctx->r15 = ADD32(ctx->r9, -0X1);
    // 0x80058860: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x80058864: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x80058868: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x8005886C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80058870: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x80058874: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80058878: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005887C: nop

    // 0x80058880: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x80058884: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80058888: nop

    // 0x8005888C: addiu       $t1, $t4, 0x8
    ctx->r9 = ADD32(ctx->r12, 0X8);
    // 0x80058890: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80058894: lw          $t7, 0x15C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X15C);
    // 0x80058898: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8005889C: sra         $t3, $t7, 1
    ctx->r11 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800588A0: addiu       $t9, $t3, 0x7
    ctx->r25 = ADD32(ctx->r11, 0X7);
    // 0x800588A4: sra         $t5, $t9, 3
    ctx->r13 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800588A8: andi        $t8, $t5, 0x1FF
    ctx->r24 = ctx->r13 & 0X1FF;
    // 0x800588AC: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x800588B0: or          $t2, $t6, $at
    ctx->r10 = ctx->r14 | ctx->r1;
    // 0x800588B4: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800588B8: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800588BC: lui         $t1, 0x708
    ctx->r9 = S32(0X708 << 16);
    // 0x800588C0: ori         $t1, $t1, 0x200
    ctx->r9 = ctx->r9 | 0X200;
    // 0x800588C4: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x800588C8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800588CC: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800588D0: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x800588D4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800588D8: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x800588DC: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800588E0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800588E4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800588E8: nop

    // 0x800588EC: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800588F0: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800588F4: nop

    // 0x800588F8: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800588FC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80058900: nop

    // 0x80058904: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x80058908: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005890C: nop

    // 0x80058910: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x80058914: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80058918: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x8005891C: lw          $t9, 0x160($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X160);
    // 0x80058920: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80058924: subu        $t5, $t3, $t9
    ctx->r13 = SUB32(ctx->r11, ctx->r25);
    // 0x80058928: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8005892C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80058930: or          $t2, $t6, $at
    ctx->r10 = ctx->r14 | ctx->r1;
    // 0x80058934: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x80058938: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x8005893C: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x80058940: addiu       $t7, $t1, -0x1
    ctx->r15 = ADD32(ctx->r9, -0X1);
    // 0x80058944: sll         $t3, $t7, 1
    ctx->r11 = S32(ctx->r15 << 1);
    // 0x80058948: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x8005894C: addiu       $t2, $t6, -0x1
    ctx->r10 = ADD32(ctx->r14, -0X1);
    // 0x80058950: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80058954: sll         $t5, $t9, 12
    ctx->r13 = S32(ctx->r25 << 12);
    // 0x80058958: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005895C: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80058960: or          $t8, $t5, $at
    ctx->r24 = ctx->r13 | ctx->r1;
    // 0x80058964: andi        $t1, $t4, 0xFFF
    ctx->r9 = ctx->r12 & 0XFFF;
    // 0x80058968: or          $t7, $t8, $t1
    ctx->r15 = ctx->r24 | ctx->r9;
    // 0x8005896C: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x80058970: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80058974: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80058978: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8005897C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80058980: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x80058984: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80058988: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005898C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80058990: nop

    // 0x80058994: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x80058998: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8005899C: nop

    // 0x800589A0: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800589A4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800589A8: nop

    // 0x800589AC: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800589B0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800589B4: nop

    // 0x800589B8: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x800589BC: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800589C0: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x800589C4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800589C8: sra         $t5, $t9, 1
    ctx->r13 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800589CC: addiu       $t6, $t5, 0x7
    ctx->r14 = ADD32(ctx->r13, 0X7);
    // 0x800589D0: sra         $t2, $t6, 3
    ctx->r10 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800589D4: andi        $t4, $t2, 0x1FF
    ctx->r12 = ctx->r10 & 0X1FF;
    // 0x800589D8: sll         $t8, $t4, 9
    ctx->r24 = S32(ctx->r12 << 9);
    // 0x800589DC: or          $t1, $t8, $at
    ctx->r9 = ctx->r24 | ctx->r1;
    // 0x800589E0: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x800589E4: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800589E8: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x800589EC: ori         $t3, $t3, 0x200
    ctx->r11 = ctx->r11 | 0X200;
    // 0x800589F0: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x800589F4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800589F8: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x800589FC: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x80058A00: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80058A04: nop

    // 0x80058A08: addiu       $t2, $t6, 0x8
    ctx->r10 = ADD32(ctx->r14, 0X8);
    // 0x80058A0C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80058A10: lw          $t4, 0x158($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X158);
    // 0x80058A14: lw          $t8, 0x160($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X160);
    // 0x80058A18: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80058A1C: subu        $t1, $t4, $t8
    ctx->r9 = SUB32(ctx->r12, ctx->r24);
    // 0x80058A20: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x80058A24: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x80058A28: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x80058A2C: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x80058A30: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x80058A34: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x80058A38: addiu       $t2, $t6, -0x1
    ctx->r10 = ADD32(ctx->r14, -0X1);
    // 0x80058A3C: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80058A40: addiu       $t3, $t7, -0x1
    ctx->r11 = ADD32(ctx->r15, -0X1);
    // 0x80058A44: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80058A48: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x80058A4C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80058A50: sll         $t1, $t8, 12
    ctx->r9 = S32(ctx->r24 << 12);
    // 0x80058A54: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x80058A58: or          $t6, $t1, $t5
    ctx->r14 = ctx->r9 | ctx->r13;
    // 0x80058A5C: b           L_80058EA8
    // 0x80058A60: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
        goto L_80058EA8;
    // 0x80058A60: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
L_80058A64:
    // 0x80058A64: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80058A68: lui         $at, 0xFD68
    ctx->r1 = S32(0XFD68 << 16);
    // 0x80058A6C: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x80058A70: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80058A74: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x80058A78: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x80058A7C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80058A80: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80058A84: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80058A88: addiu       $t9, $t3, -0x1
    ctx->r25 = ADD32(ctx->r11, -0X1);
    // 0x80058A8C: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x80058A90: or          $t5, $t1, $at
    ctx->r13 = ctx->r9 | ctx->r1;
    // 0x80058A94: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80058A98: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80058A9C: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x80058AA0: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x80058AA4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80058AA8: nop

    // 0x80058AAC: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80058AB0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80058AB4: nop

    // 0x80058AB8: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x80058ABC: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80058AC0: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x80058AC4: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80058AC8: addiu       $t1, $t9, 0x7
    ctx->r9 = ADD32(ctx->r25, 0X7);
    // 0x80058ACC: sra         $t5, $t1, 3
    ctx->r13 = S32(SIGNED(ctx->r9) >> 3);
    // 0x80058AD0: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80058AD4: sll         $t2, $t6, 9
    ctx->r10 = S32(ctx->r14 << 9);
    // 0x80058AD8: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x80058ADC: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80058AE0: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80058AE4: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x80058AE8: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80058AEC: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x80058AF0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80058AF4: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80058AF8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80058AFC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80058B00: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80058B04: addiu       $t5, $t1, 0x8
    ctx->r13 = ADD32(ctx->r9, 0X8);
    // 0x80058B08: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80058B0C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80058B10: nop

    // 0x80058B14: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80058B18: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80058B1C: nop

    // 0x80058B20: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80058B24: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80058B28: nop

    // 0x80058B2C: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80058B30: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80058B34: nop

    // 0x80058B38: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x80058B3C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80058B40: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x80058B44: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x80058B48: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80058B4C: subu        $t5, $t9, $t1
    ctx->r13 = SUB32(ctx->r25, ctx->r9);
    // 0x80058B50: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80058B54: andi        $t2, $t6, 0xFFF
    ctx->r10 = ctx->r14 & 0XFFF;
    // 0x80058B58: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x80058B5C: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80058B60: lw          $t7, 0x15C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X15C);
    // 0x80058B64: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x80058B68: addiu       $t3, $t7, -0x1
    ctx->r11 = ADD32(ctx->r15, -0X1);
    // 0x80058B6C: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80058B70: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x80058B74: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x80058B78: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80058B7C: sll         $t5, $t1, 12
    ctx->r13 = S32(ctx->r9 << 12);
    // 0x80058B80: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80058B84: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80058B88: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80058B8C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80058B90: or          $t3, $t6, $t7
    ctx->r11 = ctx->r14 | ctx->r15;
    // 0x80058B94: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x80058B98: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80058B9C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80058BA0: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80058BA4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80058BA8: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x80058BAC: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x80058BB0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80058BB4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80058BB8: nop

    // 0x80058BBC: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80058BC0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80058BC4: nop

    // 0x80058BC8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80058BCC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80058BD0: nop

    // 0x80058BD4: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80058BD8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80058BDC: nop

    // 0x80058BE0: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x80058BE4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80058BE8: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x80058BEC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80058BF0: addiu       $t5, $t1, 0x7
    ctx->r13 = ADD32(ctx->r9, 0X7);
    // 0x80058BF4: sra         $t2, $t5, 3
    ctx->r10 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80058BF8: andi        $t4, $t2, 0x1FF
    ctx->r12 = ctx->r10 & 0X1FF;
    // 0x80058BFC: sll         $t8, $t4, 9
    ctx->r24 = S32(ctx->r12 << 9);
    // 0x80058C00: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80058C04: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80058C08: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80058C0C: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x80058C10: ori         $t3, $t3, 0x200
    ctx->r11 = ctx->r11 | 0X200;
    // 0x80058C14: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x80058C18: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80058C1C: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80058C20: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80058C24: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80058C28: nop

    // 0x80058C2C: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x80058C30: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80058C34: lw          $t4, 0x158($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X158);
    // 0x80058C38: lw          $t8, 0x160($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X160);
    // 0x80058C3C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80058C40: subu        $t6, $t4, $t8
    ctx->r14 = SUB32(ctx->r12, ctx->r24);
    // 0x80058C44: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80058C48: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x80058C4C: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x80058C50: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80058C54: lw          $t5, 0x15C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X15C);
    // 0x80058C58: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x80058C5C: addiu       $t2, $t5, -0x1
    ctx->r10 = ADD32(ctx->r13, -0X1);
    // 0x80058C60: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80058C64: addiu       $t3, $t7, -0x1
    ctx->r11 = ADD32(ctx->r15, -0X1);
    // 0x80058C68: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80058C6C: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x80058C70: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80058C74: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80058C78: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x80058C7C: or          $t5, $t6, $t1
    ctx->r13 = ctx->r14 | ctx->r9;
    // 0x80058C80: b           L_80058EA8
    // 0x80058C84: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
        goto L_80058EA8;
    // 0x80058C84: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
L_80058C88:
    // 0x80058C88: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80058C8C: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x80058C90: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80058C94: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80058C98: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x80058C9C: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x80058CA0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80058CA4: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80058CA8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80058CAC: addiu       $t9, $t3, -0x1
    ctx->r25 = ADD32(ctx->r11, -0X1);
    // 0x80058CB0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80058CB4: or          $t1, $t6, $at
    ctx->r9 = ctx->r14 | ctx->r1;
    // 0x80058CB8: sw          $t1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r9;
    // 0x80058CBC: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80058CC0: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80058CC4: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x80058CC8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80058CCC: nop

    // 0x80058CD0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80058CD4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80058CD8: nop

    // 0x80058CDC: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x80058CE0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80058CE4: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x80058CE8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80058CEC: addiu       $t6, $t9, 0x7
    ctx->r14 = ADD32(ctx->r25, 0X7);
    // 0x80058CF0: sra         $t1, $t6, 3
    ctx->r9 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80058CF4: andi        $t5, $t1, 0x1FF
    ctx->r13 = ctx->r9 & 0X1FF;
    // 0x80058CF8: sll         $t2, $t5, 9
    ctx->r10 = S32(ctx->r13 << 9);
    // 0x80058CFC: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x80058D00: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80058D04: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80058D08: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x80058D0C: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80058D10: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x80058D14: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80058D18: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x80058D1C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80058D20: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80058D24: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80058D28: addiu       $t1, $t6, 0x8
    ctx->r9 = ADD32(ctx->r14, 0X8);
    // 0x80058D2C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80058D30: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80058D34: nop

    // 0x80058D38: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x80058D3C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80058D40: nop

    // 0x80058D44: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80058D48: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80058D4C: nop

    // 0x80058D50: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80058D54: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80058D58: nop

    // 0x80058D5C: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x80058D60: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80058D64: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x80058D68: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x80058D6C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80058D70: subu        $t1, $t9, $t6
    ctx->r9 = SUB32(ctx->r25, ctx->r14);
    // 0x80058D74: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x80058D78: andi        $t2, $t5, 0xFFF
    ctx->r10 = ctx->r13 & 0XFFF;
    // 0x80058D7C: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x80058D80: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80058D84: lw          $t7, 0x15C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X15C);
    // 0x80058D88: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x80058D8C: addiu       $t3, $t7, -0x1
    ctx->r11 = ADD32(ctx->r15, -0X1);
    // 0x80058D90: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80058D94: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80058D98: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x80058D9C: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80058DA0: sll         $t1, $t6, 12
    ctx->r9 = S32(ctx->r14 << 12);
    // 0x80058DA4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80058DA8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80058DAC: or          $t5, $t1, $at
    ctx->r13 = ctx->r9 | ctx->r1;
    // 0x80058DB0: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80058DB4: or          $t3, $t5, $t7
    ctx->r11 = ctx->r13 | ctx->r15;
    // 0x80058DB8: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x80058DBC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80058DC0: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80058DC4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80058DC8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80058DCC: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80058DD0: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80058DD4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80058DD8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80058DDC: nop

    // 0x80058DE0: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80058DE4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80058DE8: nop

    // 0x80058DEC: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80058DF0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80058DF4: nop

    // 0x80058DF8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80058DFC: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80058E00: nop

    // 0x80058E04: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x80058E08: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80058E0C: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x80058E10: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80058E14: addiu       $t1, $t6, 0x7
    ctx->r9 = ADD32(ctx->r14, 0X7);
    // 0x80058E18: sra         $t2, $t1, 3
    ctx->r10 = S32(SIGNED(ctx->r9) >> 3);
    // 0x80058E1C: andi        $t4, $t2, 0x1FF
    ctx->r12 = ctx->r10 & 0X1FF;
    // 0x80058E20: sll         $t8, $t4, 9
    ctx->r24 = S32(ctx->r12 << 9);
    // 0x80058E24: or          $t5, $t8, $at
    ctx->r13 = ctx->r24 | ctx->r1;
    // 0x80058E28: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80058E2C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80058E30: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x80058E34: ori         $t3, $t3, 0x200
    ctx->r11 = ctx->r11 | 0X200;
    // 0x80058E38: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x80058E3C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80058E40: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80058E44: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80058E48: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80058E4C: nop

    // 0x80058E50: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80058E54: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80058E58: lw          $t4, 0x158($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X158);
    // 0x80058E5C: lw          $t8, 0x160($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X160);
    // 0x80058E60: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80058E64: subu        $t5, $t4, $t8
    ctx->r13 = SUB32(ctx->r12, ctx->r24);
    // 0x80058E68: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80058E6C: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x80058E70: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x80058E74: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80058E78: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x80058E7C: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x80058E80: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80058E84: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80058E88: addiu       $t3, $t7, -0x1
    ctx->r11 = ADD32(ctx->r15, -0X1);
    // 0x80058E8C: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80058E90: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x80058E94: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80058E98: sll         $t5, $t8, 12
    ctx->r13 = S32(ctx->r24 << 12);
    // 0x80058E9C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80058EA0: or          $t1, $t5, $t6
    ctx->r9 = ctx->r13 | ctx->r14;
    // 0x80058EA4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_80058EA8:
    // 0x80058EA8: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80058EAC: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x80058EB0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80058EB4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80058EB8: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80058EBC: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x80058EC0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80058EC4: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80058EC8: nop

    // 0x80058ECC: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80058ED0: lw          $t5, 0x15C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X15C);
    // 0x80058ED4: lw          $t8, 0x160($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X160);
    // 0x80058ED8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80058EDC: addiu       $t1, $t6, -0x1
    ctx->r9 = ADD32(ctx->r14, -0X1);
    // 0x80058EE0: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80058EE4: addiu       $t3, $t7, -0x1
    ctx->r11 = ADD32(ctx->r15, -0X1);
    // 0x80058EE8: andi        $t2, $t1, 0xFFF
    ctx->r10 = ctx->r9 & 0XFFF;
    // 0x80058EEC: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80058EF0: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x80058EF4: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x80058EF8: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x80058EFC: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80058F00: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80058F04: nop

    // 0x80058F08: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80058F0C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80058F10: nop

    // 0x80058F14: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x80058F18: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80058F1C: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x80058F20: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x80058F24: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x80058F28: addu        $t4, $t7, $t3
    ctx->r12 = ADD32(ctx->r15, ctx->r11);
    // 0x80058F2C: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x80058F30: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x80058F34: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80058F38: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80058F3C: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x80058F40: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x80058F44: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x80058F48: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x80058F4C: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x80058F50: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x80058F54: or          $t5, $t9, $t6
    ctx->r13 = ctx->r25 | ctx->r14;
    // 0x80058F58: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80058F5C: lw          $t8, 0x158($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X158);
    // 0x80058F60: lw          $t2, 0x178($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X178);
    // 0x80058F64: lw          $t3, 0x160($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X160);
    // 0x80058F68: addu        $t7, $t2, $t8
    ctx->r15 = ADD32(ctx->r10, ctx->r24);
    // 0x80058F6C: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x80058F70: subu        $t4, $t7, $t3
    ctx->r12 = SUB32(ctx->r15, ctx->r11);
    // 0x80058F74: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80058F78: andi        $t1, $t5, 0xFFF
    ctx->r9 = ctx->r13 & 0XFFF;
    // 0x80058F7C: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x80058F80: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x80058F84: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80058F88: or          $t8, $t2, $t6
    ctx->r24 = ctx->r10 | ctx->r14;
    // 0x80058F8C: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x80058F90: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80058F94: lui         $t5, 0xE100
    ctx->r13 = S32(0XE100 << 16);
    // 0x80058F98: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x80058F9C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80058FA0: lui         $t3, 0xF100
    ctx->r11 = S32(0XF100 << 16);
    // 0x80058FA4: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x80058FA8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80058FAC: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x80058FB0: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80058FB4: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80058FB8: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x80058FBC: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x80058FC0: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80058FC4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80058FC8: nop

    // 0x80058FCC: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x80058FD0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80058FD4: nop

    // 0x80058FD8: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x80058FDC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80058FE0: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x80058FE4: nop

    // 0x80058FE8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80058FEC: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x80058FF0: nop

    // 0x80058FF4: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80058FF8: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
L_80058FFC:
    // 0x80058FFC: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x80059000: nop

    // 0x80059004: bne         $t1, $zero, L_80057AF8
    if (ctx->r9 != 0) {
        // 0x80059008: nop
    
            goto L_80057AF8;
    }
    // 0x80059008: nop

L_8005900C:
    // 0x8005900C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80059010: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80059014: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x80059018: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005901C: nop

    // 0x80059020: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x80059024: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80059028: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005902C: nop

    // 0x80059030: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80059034: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80059038: nop

    // 0x8005903C: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
L_80059040:
    // 0x80059040: jr          $ra
    // 0x80059044: addiu       $sp, $sp, 0x168
    ctx->r29 = ADD32(ctx->r29, 0X168);
    return;
    // 0x80059044: addiu       $sp, $sp, 0x168
    ctx->r29 = ADD32(ctx->r29, 0X168);
;}

RECOMP_FUNC void display_one_text_character_rgb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059048: beq         $a1, $zero, L_8005AA94
    if (ctx->r5 == 0) {
        // 0x8005904C: addiu       $sp, $sp, -0x138
        ctx->r29 = ADD32(ctx->r29, -0X138);
            goto L_8005AA94;
    }
    // 0x8005904C: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x80059050: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x80059054: nop

    // 0x80059058: beq         $t6, $zero, L_8005AA94
    if (ctx->r14 == 0) {
        // 0x8005905C: nop
    
            goto L_8005AA94;
    }
    // 0x8005905C: nop

    // 0x80059060: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80059064: nop

    // 0x80059068: sw          $t7, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r15;
    // 0x8005906C: lhu         $t8, 0x2($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X2);
    // 0x80059070: lw          $t1, 0x12C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X12C);
    // 0x80059074: sw          $t8, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r24;
    // 0x80059078: lhu         $t9, 0x4($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X4);
    // 0x8005907C: blez        $t1, L_8005AA94
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80059080: sw          $t9, 0x124($sp)
        MEM_W(0X124, ctx->r29) = ctx->r25;
            goto L_8005AA94;
    }
    // 0x80059080: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x80059084: lw          $t2, 0x128($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X128);
    // 0x80059088: nop

    // 0x8005908C: blez        $t2, L_8005AA94
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80059090: nop
    
            goto L_8005AA94;
    }
    // 0x80059090: nop

    // 0x80059094: lw          $t3, 0x148($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X148);
    // 0x80059098: nop

    // 0x8005909C: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800590A0: bne         $at, $zero, L_8005AA94
    if (ctx->r1 != 0) {
        // 0x800590A4: nop
    
            goto L_8005AA94;
    }
    // 0x800590A4: nop

    // 0x800590A8: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800590AC: nop

    // 0x800590B0: slt         $at, $t4, $a3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800590B4: bne         $at, $zero, L_8005AA94
    if (ctx->r1 != 0) {
        // 0x800590B8: nop
    
            goto L_8005AA94;
    }
    // 0x800590B8: nop

    // 0x800590BC: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800590C0: lh          $t5, 0x164($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X164);
    // 0x800590C4: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x800590C8: nop

    // 0x800590CC: beq         $t5, $t6, L_800591CC
    if (ctx->r13 == ctx->r14) {
        // 0x800590D0: nop
    
            goto L_800591CC;
    }
    // 0x800590D0: nop

    // 0x800590D4: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x800590D8: beq         $t0, $zero, L_80059100
    if (ctx->r8 == 0) {
        // 0x800590DC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80059100;
    }
    // 0x800590DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800590E0: beq         $t0, $at, L_80059180
    if (ctx->r8 == ctx->r1) {
        // 0x800590E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80059180;
    }
    // 0x800590E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800590E8: beq         $t0, $at, L_80059140
    if (ctx->r8 == ctx->r1) {
        // 0x800590EC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80059140;
    }
    // 0x800590EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800590F0: beq         $t0, $at, L_800591C0
    if (ctx->r8 == ctx->r1) {
        // 0x800590F4: nop
    
            goto L_800591C0;
    }
    // 0x800590F4: nop

    // 0x800590F8: b           L_8005AA94
    // 0x800590FC: nop

        goto L_8005AA94;
    // 0x800590FC: nop

L_80059100:
    // 0x80059100: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x80059104: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059108: sw          $t7, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r15;
    // 0x8005910C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80059110: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x80059114: sw          $t8, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r24;
    // 0x80059118: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005911C: ori         $t2, $t2, 0x1001
    ctx->r10 = ctx->r10 | 0X1001;
    // 0x80059120: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x80059124: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80059128: lw          $t3, 0x120($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X120);
    // 0x8005912C: nop

    // 0x80059130: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80059134: lw          $t4, 0x120($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X120);
    // 0x80059138: b           L_800591CC
    // 0x8005913C: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
        goto L_800591CC;
    // 0x8005913C: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
L_80059140:
    // 0x80059140: addiu       $t5, $zero, 0x800
    ctx->r13 = ADD32(0, 0X800);
    // 0x80059144: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059148: sw          $t5, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r13;
    // 0x8005914C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80059150: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80059154: sw          $t6, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r14;
    // 0x80059158: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005915C: ori         $t9, $t9, 0x1001
    ctx->r25 = ctx->r25 | 0X1001;
    // 0x80059160: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80059164: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80059168: lw          $t1, 0x11C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X11C);
    // 0x8005916C: nop

    // 0x80059170: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80059174: lw          $t2, 0x11C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X11C);
    // 0x80059178: b           L_800591CC
    // 0x8005917C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
        goto L_800591CC;
    // 0x8005917C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_80059180:
    // 0x80059180: addiu       $t3, $zero, 0x1000
    ctx->r11 = ADD32(0, 0X1000);
    // 0x80059184: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059188: sw          $t3, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r11;
    // 0x8005918C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80059190: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80059194: sw          $t4, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r12;
    // 0x80059198: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005919C: ori         $t7, $t7, 0x1001
    ctx->r15 = ctx->r15 | 0X1001;
    // 0x800591A0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800591A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800591A8: lw          $t8, 0x118($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X118);
    // 0x800591AC: nop

    // 0x800591B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800591B4: lw          $t9, 0x118($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X118);
    // 0x800591B8: b           L_800591CC
    // 0x800591BC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
        goto L_800591CC;
    // 0x800591BC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
L_800591C0:
    // 0x800591C0: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x800591C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800591C8: sw          $t1, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r9;
L_800591CC:
    // 0x800591CC: lw          $t3, 0x148($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X148);
    // 0x800591D0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800591D4: subu        $t4, $t3, $a2
    ctx->r12 = SUB32(ctx->r11, ctx->r6);
    // 0x800591D8: lw          $t2, 0x160($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X160);
    // 0x800591DC: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800591E0: andi        $t6, $t5, 0xFFFC
    ctx->r14 = ctx->r13 & 0XFFFC;
    // 0x800591E4: div         $zero, $t2, $t6
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r14)));
    // 0x800591E8: bne         $t6, $zero, L_800591F4
    if (ctx->r14 != 0) {
        // 0x800591EC: nop
    
            goto L_800591F4;
    }
    // 0x800591EC: nop

    // 0x800591F0: break       7
    do_break(2147848688);
L_800591F4:
    // 0x800591F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800591F8: bne         $t6, $at, L_8005920C
    if (ctx->r14 != ctx->r1) {
        // 0x800591FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005920C;
    }
    // 0x800591FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80059200: bne         $t2, $at, L_8005920C
    if (ctx->r10 != ctx->r1) {
        // 0x80059204: nop
    
            goto L_8005920C;
    }
    // 0x80059204: nop

    // 0x80059208: break       6
    do_break(2147848712);
L_8005920C:
    // 0x8005920C: mflo        $t7
    ctx->r15 = lo;
    // 0x80059210: sw          $t7, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r15;
    // 0x80059214: blez        $t7, L_8005AA94
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80059218: nop
    
            goto L_8005AA94;
    }
    // 0x80059218: nop

    // 0x8005921C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80059220: lbu         $t8, 0x168($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X168);
    // 0x80059224: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x80059228: nop

    // 0x8005922C: bne         $t8, $t9, L_80059294
    if (ctx->r24 != ctx->r25) {
        // 0x80059230: nop
    
            goto L_80059294;
    }
    // 0x80059230: nop

    // 0x80059234: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80059238: lbu         $t1, 0x16C($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X16C);
    // 0x8005923C: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80059240: nop

    // 0x80059244: bne         $t1, $t3, L_80059294
    if (ctx->r9 != ctx->r11) {
        // 0x80059248: nop
    
            goto L_80059294;
    }
    // 0x80059248: nop

    // 0x8005924C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80059250: lbu         $t4, 0x170($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X170);
    // 0x80059254: lw          $t5, 0x160($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X160);
    // 0x80059258: nop

    // 0x8005925C: bne         $t4, $t5, L_80059294
    if (ctx->r12 != ctx->r13) {
        // 0x80059260: nop
    
            goto L_80059294;
    }
    // 0x80059260: nop

    // 0x80059264: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80059268: lbu         $t2, 0x174($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X174);
    // 0x8005926C: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x80059270: nop

    // 0x80059274: bne         $t2, $t6, L_80059294
    if (ctx->r10 != ctx->r14) {
        // 0x80059278: nop
    
            goto L_80059294;
    }
    // 0x80059278: nop

    // 0x8005927C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80059280: lh          $t7, 0x164($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X164);
    // 0x80059284: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x80059288: nop

    // 0x8005928C: beq         $t7, $t8, L_80059440
    if (ctx->r15 == ctx->r24) {
        // 0x80059290: nop
    
            goto L_80059440;
    }
    // 0x80059290: nop

L_80059294:
    // 0x80059294: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x80059298: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005929C: bne         $t9, $at, L_8005930C
    if (ctx->r25 != ctx->r1) {
        // 0x800592A0: nop
    
            goto L_8005930C;
    }
    // 0x800592A0: nop

    // 0x800592A4: lw          $t1, 0x158($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X158);
    // 0x800592A8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800592AC: bne         $t1, $at, L_8005930C
    if (ctx->r9 != ctx->r1) {
        // 0x800592B0: nop
    
            goto L_8005930C;
    }
    // 0x800592B0: nop

    // 0x800592B4: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x800592B8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800592BC: bne         $t3, $at, L_8005930C
    if (ctx->r11 != ctx->r1) {
        // 0x800592C0: nop
    
            goto L_8005930C;
    }
    // 0x800592C0: nop

    // 0x800592C4: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x800592C8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800592CC: bne         $t4, $at, L_8005930C
    if (ctx->r12 != ctx->r1) {
        // 0x800592D0: nop
    
            goto L_8005930C;
    }
    // 0x800592D0: nop

    // 0x800592D4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800592D8: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x800592DC: sw          $t5, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r13;
    // 0x800592E0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800592E4: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800592E8: addiu       $t6, $t2, 0x8
    ctx->r14 = ADD32(ctx->r10, 0X8);
    // 0x800592EC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800592F0: lw          $t8, 0x114($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X114);
    // 0x800592F4: lui         $t9, 0xFFFC
    ctx->r25 = S32(0XFFFC << 16);
    // 0x800592F8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800592FC: lw          $t1, 0x114($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X114);
    // 0x80059300: ori         $t9, $t9, 0xF279
    ctx->r25 = ctx->r25 | 0XF279;
    // 0x80059304: b           L_80059410
    // 0x80059308: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
        goto L_80059410;
    // 0x80059308: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
L_8005930C:
    // 0x8005930C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80059310: lbu         $t3, 0x168($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X168);
    // 0x80059314: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80059318: bne         $t3, $at, L_8005935C
    if (ctx->r11 != ctx->r1) {
        // 0x8005931C: nop
    
            goto L_8005935C;
    }
    // 0x8005931C: nop

    // 0x80059320: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80059324: lbu         $t4, 0x16C($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X16C);
    // 0x80059328: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005932C: bne         $t4, $at, L_8005935C
    if (ctx->r12 != ctx->r1) {
        // 0x80059330: nop
    
            goto L_8005935C;
    }
    // 0x80059330: nop

    // 0x80059334: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80059338: lbu         $t5, 0x170($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X170);
    // 0x8005933C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80059340: bne         $t5, $at, L_8005935C
    if (ctx->r13 != ctx->r1) {
        // 0x80059344: nop
    
            goto L_8005935C;
    }
    // 0x80059344: nop

    // 0x80059348: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8005934C: lbu         $t2, 0x174($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X174);
    // 0x80059350: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80059354: beq         $t2, $at, L_80059374
    if (ctx->r10 == ctx->r1) {
        // 0x80059358: nop
    
            goto L_80059374;
    }
    // 0x80059358: nop

L_8005935C:
    // 0x8005935C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80059360: lh          $t6, 0x164($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X164);
    // 0x80059364: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x80059368: nop

    // 0x8005936C: beq         $t6, $t7, L_800593A8
    if (ctx->r14 == ctx->r15) {
        // 0x80059370: nop
    
            goto L_800593A8;
    }
    // 0x80059370: nop

L_80059374:
    // 0x80059374: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80059378: lui         $t3, 0xFC11
    ctx->r11 = S32(0XFC11 << 16);
    // 0x8005937C: sw          $t8, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r24;
    // 0x80059380: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80059384: ori         $t3, $t3, 0x9623
    ctx->r11 = ctx->r11 | 0X9623;
    // 0x80059388: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8005938C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80059390: lw          $t4, 0x110($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X110);
    // 0x80059394: lui         $t5, 0xFF2F
    ctx->r13 = S32(0XFF2F << 16);
    // 0x80059398: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8005939C: lw          $t2, 0x110($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X110);
    // 0x800593A0: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x800593A4: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
L_800593A8:
    // 0x800593A8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800593AC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800593B0: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
    // 0x800593B4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800593B8: nop

    // 0x800593BC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800593C0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800593C4: lw          $t1, 0x10C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10C);
    // 0x800593C8: nop

    // 0x800593CC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800593D0: lw          $t2, 0x15C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X15C);
    // 0x800593D4: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x800593D8: lw          $t9, 0x160($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X160);
    // 0x800593DC: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x800593E0: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800593E4: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x800593E8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800593EC: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x800593F0: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800593F4: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x800593F8: sll         $t3, $t1, 8
    ctx->r11 = S32(ctx->r9 << 8);
    // 0x800593FC: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x80059400: or          $t4, $t8, $t3
    ctx->r12 = ctx->r24 | ctx->r11;
    // 0x80059404: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x80059408: or          $t5, $t4, $t6
    ctx->r13 = ctx->r12 | ctx->r14;
    // 0x8005940C: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
L_80059410:
    // 0x80059410: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x80059414: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059418: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x8005941C: sb          $t9, 0x168($at)
    MEM_B(0X168, ctx->r1) = ctx->r25;
    // 0x80059420: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059424: lw          $t8, 0x160($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X160);
    // 0x80059428: sb          $t1, 0x16C($at)
    MEM_B(0X16C, ctx->r1) = ctx->r9;
    // 0x8005942C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059430: lw          $t3, 0x164($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X164);
    // 0x80059434: sb          $t8, 0x170($at)
    MEM_B(0X170, ctx->r1) = ctx->r24;
    // 0x80059438: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005943C: sb          $t3, 0x174($at)
    MEM_B(0X174, ctx->r1) = ctx->r11;
L_80059440:
    // 0x80059440: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x80059444: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80059448: subu        $t6, $t4, $a3
    ctx->r14 = SUB32(ctx->r12, ctx->r7);
    // 0x8005944C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059450: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x80059454: sw          $t5, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r13;
    // 0x80059458: beq         $t5, $zero, L_8005AA60
    if (ctx->r13 == 0) {
        // 0x8005945C: sh          $t2, 0x164($at)
        MEM_H(0X164, ctx->r1) = ctx->r10;
            goto L_8005AA60;
    }
    // 0x8005945C: sh          $t2, 0x164($at)
    MEM_H(0X164, ctx->r1) = ctx->r10;
L_80059460:
    // 0x80059460: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x80059464: lw          $t9, 0x134($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X134);
    // 0x80059468: nop

    // 0x8005946C: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80059470: beq         $at, $zero, L_80059FB8
    if (ctx->r1 == 0) {
        // 0x80059474: nop
    
            goto L_80059FB8;
    }
    // 0x80059474: nop

    // 0x80059478: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x8005947C: nop

    // 0x80059480: beq         $t0, $zero, L_800594A8
    if (ctx->r8 == 0) {
        // 0x80059484: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800594A8;
    }
    // 0x80059484: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80059488: beq         $t0, $at, L_8005970C
    if (ctx->r8 == ctx->r1) {
        // 0x8005948C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005970C;
    }
    // 0x8005948C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80059490: beq         $t0, $at, L_80059984
    if (ctx->r8 == ctx->r1) {
        // 0x80059494: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80059984;
    }
    // 0x80059494: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80059498: beq         $t0, $at, L_80059BE0
    if (ctx->r8 == ctx->r1) {
        // 0x8005949C: nop
    
            goto L_80059BE0;
    }
    // 0x8005949C: nop

    // 0x800594A0: b           L_80059E38
    // 0x800594A4: nop

        goto L_80059E38;
    // 0x800594A4: nop

L_800594A8:
    // 0x800594A8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800594AC: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x800594B0: sw          $t1, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r9;
    // 0x800594B4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800594B8: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x800594BC: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x800594C0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800594C4: lw          $t2, 0x12C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X12C);
    // 0x800594C8: lw          $t7, 0x108($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X108);
    // 0x800594CC: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x800594D0: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x800594D4: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x800594D8: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x800594DC: lw          $t1, 0x108($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X108);
    // 0x800594E0: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800594E4: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800594E8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800594EC: nop

    // 0x800594F0: sw          $t8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r24;
    // 0x800594F4: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800594F8: nop

    // 0x800594FC: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x80059500: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80059504: lw          $t4, 0x148($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X148);
    // 0x80059508: lw          $t2, 0x104($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X104);
    // 0x8005950C: subu        $t6, $t4, $a2
    ctx->r14 = SUB32(ctx->r12, ctx->r6);
    // 0x80059510: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x80059514: addiu       $t7, $t5, 0x9
    ctx->r15 = ADD32(ctx->r13, 0X9);
    // 0x80059518: sra         $t9, $t7, 3
    ctx->r25 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8005951C: andi        $t1, $t9, 0x1FF
    ctx->r9 = ctx->r25 & 0X1FF;
    // 0x80059520: sll         $t8, $t1, 9
    ctx->r24 = S32(ctx->r9 << 9);
    // 0x80059524: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x80059528: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x8005952C: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x80059530: lui         $t4, 0x708
    ctx->r12 = S32(0X708 << 16);
    // 0x80059534: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x80059538: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x8005953C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80059540: lui         $t1, 0xE600
    ctx->r9 = S32(0XE600 << 16);
    // 0x80059544: sw          $t5, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r13;
    // 0x80059548: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005954C: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80059550: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80059554: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80059558: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x8005955C: nop

    // 0x80059560: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80059564: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x80059568: nop

    // 0x8005956C: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80059570: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80059574: nop

    // 0x80059578: sw          $t2, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r10;
    // 0x8005957C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80059580: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80059584: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80059588: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005958C: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x80059590: lw          $t5, 0x14C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14C);
    // 0x80059594: andi        $t4, $t2, 0xFFF
    ctx->r12 = ctx->r10 & 0XFFF;
    // 0x80059598: subu        $t9, $t5, $t7
    ctx->r25 = SUB32(ctx->r13, ctx->r15);
    // 0x8005959C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800595A0: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x800595A4: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x800595A8: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x800595AC: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x800595B0: andi        $t3, $t8, 0xFFF
    ctx->r11 = ctx->r24 & 0XFFF;
    // 0x800595B4: or          $t7, $t5, $t3
    ctx->r15 = ctx->r13 | ctx->r11;
    // 0x800595B8: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800595BC: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x800595C0: lw          $t1, 0x14C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14C);
    // 0x800595C4: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x800595C8: lw          $t4, 0x134($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X134);
    // 0x800595CC: subu        $t2, $t1, $t8
    ctx->r10 = SUB32(ctx->r9, ctx->r24);
    // 0x800595D0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800595D4: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x800595D8: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x800595DC: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x800595E0: sll         $t8, $t1, 12
    ctx->r24 = S32(ctx->r9 << 12);
    // 0x800595E4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800595E8: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x800595EC: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x800595F0: andi        $t3, $t5, 0xFFF
    ctx->r11 = ctx->r13 & 0XFFF;
    // 0x800595F4: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x800595F8: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x800595FC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80059600: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80059604: sw          $t5, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r13;
    // 0x80059608: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005960C: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80059610: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80059614: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80059618: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x8005961C: nop

    // 0x80059620: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80059624: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x80059628: nop

    // 0x8005962C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80059630: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80059634: nop

    // 0x80059638: sw          $t3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r11;
    // 0x8005963C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80059640: nop

    // 0x80059644: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80059648: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005964C: lw          $t5, 0x148($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X148);
    // 0x80059650: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x80059654: subu        $t7, $t5, $a2
    ctx->r15 = SUB32(ctx->r13, ctx->r6);
    // 0x80059658: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8005965C: addiu       $t1, $t9, 0x9
    ctx->r9 = ADD32(ctx->r25, 0X9);
    // 0x80059660: sra         $t8, $t1, 3
    ctx->r24 = S32(SIGNED(ctx->r9) >> 3);
    // 0x80059664: andi        $t2, $t8, 0x1FF
    ctx->r10 = ctx->r24 & 0X1FF;
    // 0x80059668: sll         $t3, $t2, 9
    ctx->r11 = S32(ctx->r10 << 9);
    // 0x8005966C: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80059670: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80059674: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
    // 0x80059678: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x8005967C: ori         $t5, $t5, 0x200
    ctx->r13 = ctx->r13 | 0X200;
    // 0x80059680: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x80059684: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80059688: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005968C: sw          $t9, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r25;
    // 0x80059690: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80059694: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80059698: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x8005969C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800596A0: lw          $t3, 0x130($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X130);
    // 0x800596A4: lw          $t2, 0x14C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14C);
    // 0x800596A8: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x800596AC: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800596B0: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800596B4: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x800596B8: sll         $t8, $t1, 12
    ctx->r24 = S32(ctx->r9 << 12);
    // 0x800596BC: lw          $t4, 0xF0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF0);
    // 0x800596C0: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x800596C4: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x800596C8: or          $t3, $t2, $t7
    ctx->r11 = ctx->r10 | ctx->r15;
    // 0x800596CC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800596D0: lw          $t5, 0x130($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X130);
    // 0x800596D4: lw          $t6, 0x14C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14C);
    // 0x800596D8: lw          $t3, 0x148($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X148);
    // 0x800596DC: lw          $t1, 0x134($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X134);
    // 0x800596E0: subu        $t9, $t6, $t5
    ctx->r25 = SUB32(ctx->r14, ctx->r13);
    // 0x800596E4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800596E8: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x800596EC: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x800596F0: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x800596F4: lw          $t1, 0xF0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF0);
    // 0x800596F8: sll         $t5, $t6, 12
    ctx->r13 = S32(ctx->r14 << 12);
    // 0x800596FC: andi        $t7, $t2, 0xFFF
    ctx->r15 = ctx->r10 & 0XFFF;
    // 0x80059700: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x80059704: b           L_80059E38
    // 0x80059708: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
        goto L_80059E38;
    // 0x80059708: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
L_8005970C:
    // 0x8005970C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80059710: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x80059714: sw          $t8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r24;
    // 0x80059718: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005971C: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80059720: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80059724: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80059728: lw          $t4, 0x12C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X12C);
    // 0x8005972C: lw          $t1, 0xEC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XEC);
    // 0x80059730: sra         $t6, $t4, 1
    ctx->r14 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80059734: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x80059738: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x8005973C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80059740: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80059744: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x80059748: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8005974C: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x80059750: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80059754: nop

    // 0x80059758: sw          $t3, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r11;
    // 0x8005975C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80059760: nop

    // 0x80059764: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80059768: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005976C: lw          $t5, 0x148($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X148);
    // 0x80059770: nop

    // 0x80059774: subu        $t7, $t5, $a2
    ctx->r15 = SUB32(ctx->r13, ctx->r6);
    // 0x80059778: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8005977C: sra         $t1, $t9, 1
    ctx->r9 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80059780: addiu       $t8, $t1, 0x7
    ctx->r24 = ADD32(ctx->r9, 0X7);
    // 0x80059784: sra         $t2, $t8, 3
    ctx->r10 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80059788: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x8005978C: lw          $t5, 0xE8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE8);
    // 0x80059790: sll         $t4, $t3, 9
    ctx->r12 = S32(ctx->r11 << 9);
    // 0x80059794: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x80059798: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8005979C: lw          $t9, 0xE8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE8);
    // 0x800597A0: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x800597A4: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800597A8: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800597AC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800597B0: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x800597B4: sw          $t1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r9;
    // 0x800597B8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800597BC: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x800597C0: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x800597C4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800597C8: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x800597CC: nop

    // 0x800597D0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800597D4: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x800597D8: nop

    // 0x800597DC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800597E0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800597E4: nop

    // 0x800597E8: sw          $t5, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r13;
    // 0x800597EC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800597F0: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x800597F4: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800597F8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800597FC: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x80059800: lw          $t1, 0x14C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14C);
    // 0x80059804: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x80059808: subu        $t2, $t1, $t8
    ctx->r10 = SUB32(ctx->r9, ctx->r24);
    // 0x8005980C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80059810: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80059814: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80059818: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x8005981C: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x80059820: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x80059824: or          $t8, $t1, $t6
    ctx->r24 = ctx->r9 | ctx->r14;
    // 0x80059828: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8005982C: lw          $t4, 0x130($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X130);
    // 0x80059830: lw          $t3, 0x14C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14C);
    // 0x80059834: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x80059838: lw          $t7, 0x134($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X134);
    // 0x8005983C: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80059840: sll         $t2, $t8, 1
    ctx->r10 = S32(ctx->r24 << 1);
    // 0x80059844: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x80059848: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8005984C: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x80059850: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x80059854: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80059858: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8005985C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80059860: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x80059864: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80059868: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8005986C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80059870: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80059874: sw          $t1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r9;
    // 0x80059878: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005987C: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x80059880: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x80059884: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80059888: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x8005988C: nop

    // 0x80059890: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80059894: lw          $t5, 0xDC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XDC);
    // 0x80059898: nop

    // 0x8005989C: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800598A0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800598A4: nop

    // 0x800598A8: sw          $t6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r14;
    // 0x800598AC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800598B0: nop

    // 0x800598B4: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800598B8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800598BC: lw          $t1, 0x148($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X148);
    // 0x800598C0: nop

    // 0x800598C4: subu        $t8, $t1, $a2
    ctx->r24 = SUB32(ctx->r9, ctx->r6);
    // 0x800598C8: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x800598CC: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800598D0: addiu       $t4, $t3, 0x7
    ctx->r12 = ADD32(ctx->r11, 0X7);
    // 0x800598D4: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x800598D8: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x800598DC: lw          $t1, 0xD8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD8);
    // 0x800598E0: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x800598E4: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800598E8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800598EC: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
    // 0x800598F0: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x800598F4: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800598F8: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x800598FC: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80059900: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80059904: sw          $t3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r11;
    // 0x80059908: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005990C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80059910: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80059914: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80059918: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x8005991C: lw          $t6, 0x14C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14C);
    // 0x80059920: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x80059924: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x80059928: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8005992C: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80059930: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x80059934: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x80059938: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8005993C: andi        $t2, $t8, 0xFFF
    ctx->r10 = ctx->r24 & 0XFFF;
    // 0x80059940: or          $t7, $t6, $t2
    ctx->r15 = ctx->r14 | ctx->r10;
    // 0x80059944: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x80059948: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x8005994C: lw          $t1, 0x14C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14C);
    // 0x80059950: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x80059954: lw          $t4, 0x134($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X134);
    // 0x80059958: subu        $t3, $t1, $t8
    ctx->r11 = SUB32(ctx->r9, ctx->r24);
    // 0x8005995C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80059960: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80059964: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80059968: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x8005996C: lw          $t4, 0xD4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD4);
    // 0x80059970: sll         $t8, $t1, 12
    ctx->r24 = S32(ctx->r9 << 12);
    // 0x80059974: andi        $t2, $t6, 0xFFF
    ctx->r10 = ctx->r14 & 0XFFF;
    // 0x80059978: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x8005997C: b           L_80059E38
    // 0x80059980: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
        goto L_80059E38;
    // 0x80059980: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_80059984:
    // 0x80059984: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80059988: lui         $at, 0xFD68
    ctx->r1 = S32(0XFD68 << 16);
    // 0x8005998C: sw          $t5, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r13;
    // 0x80059990: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80059994: addiu       $t4, $a1, 0x8
    ctx->r12 = ADD32(ctx->r5, 0X8);
    // 0x80059998: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005999C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800599A0: lw          $t9, 0x12C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X12C);
    // 0x800599A4: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    // 0x800599A8: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x800599AC: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x800599B0: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x800599B4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800599B8: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x800599BC: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x800599C0: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800599C4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800599C8: nop

    // 0x800599CC: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800599D0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800599D4: nop

    // 0x800599D8: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800599DC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800599E0: lw          $t1, 0x148($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X148);
    // 0x800599E4: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800599E8: subu        $t8, $t1, $a2
    ctx->r24 = SUB32(ctx->r9, ctx->r6);
    // 0x800599EC: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x800599F0: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x800599F4: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x800599F8: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x800599FC: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80059A00: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80059A04: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
    // 0x80059A08: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x80059A0C: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80059A10: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80059A14: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80059A18: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x80059A1C: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80059A20: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80059A24: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80059A28: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80059A2C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80059A30: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x80059A34: nop

    // 0x80059A38: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80059A3C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80059A40: nop

    // 0x80059A44: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80059A48: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80059A4C: nop

    // 0x80059A50: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x80059A54: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80059A58: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80059A5C: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x80059A60: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80059A64: lw          $t2, 0x130($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X130);
    // 0x80059A68: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x80059A6C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80059A70: subu        $t3, $t8, $t2
    ctx->r11 = SUB32(ctx->r24, ctx->r10);
    // 0x80059A74: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80059A78: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80059A7C: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x80059A80: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x80059A84: or          $t8, $t1, $at
    ctx->r24 = ctx->r9 | ctx->r1;
    // 0x80059A88: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x80059A8C: or          $t2, $t8, $t6
    ctx->r10 = ctx->r24 | ctx->r14;
    // 0x80059A90: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80059A94: lw          $t5, 0x130($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X130);
    // 0x80059A98: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x80059A9C: lw          $t2, 0x148($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X148);
    // 0x80059AA0: lw          $t9, 0x134($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X134);
    // 0x80059AA4: subu        $t7, $t4, $t5
    ctx->r15 = SUB32(ctx->r12, ctx->r13);
    // 0x80059AA8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80059AAC: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x80059AB0: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80059AB4: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x80059AB8: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x80059ABC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80059AC0: lw          $t1, 0xC4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC4);
    // 0x80059AC4: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x80059AC8: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80059ACC: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80059AD0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80059AD4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80059AD8: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80059ADC: sw          $t8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r24;
    // 0x80059AE0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80059AE4: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x80059AE8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80059AEC: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80059AF0: lw          $t5, 0xC0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC0);
    // 0x80059AF4: nop

    // 0x80059AF8: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80059AFC: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x80059B00: nop

    // 0x80059B04: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80059B08: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80059B0C: nop

    // 0x80059B10: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80059B14: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80059B18: nop

    // 0x80059B1C: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x80059B20: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80059B24: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x80059B28: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x80059B2C: subu        $t2, $t8, $a2
    ctx->r10 = SUB32(ctx->r24, ctx->r6);
    // 0x80059B30: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80059B34: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80059B38: andi        $t5, $t4, 0x1FF
    ctx->r13 = ctx->r12 & 0X1FF;
    // 0x80059B3C: sll         $t7, $t5, 9
    ctx->r15 = S32(ctx->r13 << 9);
    // 0x80059B40: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x80059B44: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x80059B48: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x80059B4C: lui         $t1, 0x8
    ctx->r9 = S32(0X8 << 16);
    // 0x80059B50: ori         $t1, $t1, 0x200
    ctx->r9 = ctx->r9 | 0X200;
    // 0x80059B54: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x80059B58: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80059B5C: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80059B60: sw          $t2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r10;
    // 0x80059B64: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80059B68: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80059B6C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80059B70: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80059B74: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x80059B78: lw          $t5, 0x14C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14C);
    // 0x80059B7C: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x80059B80: subu        $t6, $t5, $t7
    ctx->r14 = SUB32(ctx->r13, ctx->r15);
    // 0x80059B84: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80059B88: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80059B8C: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x80059B90: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x80059B94: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80059B98: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x80059B9C: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x80059BA0: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80059BA4: lw          $t1, 0x130($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X130);
    // 0x80059BA8: lw          $t9, 0x14C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14C);
    // 0x80059BAC: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x80059BB0: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x80059BB4: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x80059BB8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80059BBC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80059BC0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80059BC4: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80059BC8: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x80059BCC: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x80059BD0: andi        $t8, $t5, 0xFFF
    ctx->r24 = ctx->r13 & 0XFFF;
    // 0x80059BD4: or          $t2, $t1, $t8
    ctx->r10 = ctx->r9 | ctx->r24;
    // 0x80059BD8: b           L_80059E38
    // 0x80059BDC: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
        goto L_80059E38;
    // 0x80059BDC: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
L_80059BE0:
    // 0x80059BE0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80059BE4: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x80059BE8: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    // 0x80059BEC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80059BF0: addiu       $t3, $a1, 0x8
    ctx->r11 = ADD32(ctx->r5, 0X8);
    // 0x80059BF4: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x80059BF8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80059BFC: lw          $t6, 0x12C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X12C);
    // 0x80059C00: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x80059C04: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80059C08: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x80059C0C: or          $t8, $t1, $at
    ctx->r24 = ctx->r9 | ctx->r1;
    // 0x80059C10: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80059C14: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x80059C18: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80059C1C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80059C20: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80059C24: nop

    // 0x80059C28: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
    // 0x80059C2C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80059C30: nop

    // 0x80059C34: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x80059C38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80059C3C: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x80059C40: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x80059C44: subu        $t1, $t9, $a2
    ctx->r9 = SUB32(ctx->r25, ctx->r6);
    // 0x80059C48: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x80059C4C: sra         $t2, $t8, 3
    ctx->r10 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80059C50: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x80059C54: sll         $t4, $t3, 9
    ctx->r12 = S32(ctx->r11 << 9);
    // 0x80059C58: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80059C5C: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80059C60: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x80059C64: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x80059C68: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80059C6C: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80059C70: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80059C74: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x80059C78: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    // 0x80059C7C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80059C80: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80059C84: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x80059C88: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80059C8C: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x80059C90: nop

    // 0x80059C94: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80059C98: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x80059C9C: nop

    // 0x80059CA0: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80059CA4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80059CA8: nop

    // 0x80059CAC: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
    // 0x80059CB0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80059CB4: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80059CB8: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80059CBC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80059CC0: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x80059CC4: lw          $t1, 0x14C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14C);
    // 0x80059CC8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80059CCC: subu        $t2, $t1, $t8
    ctx->r10 = SUB32(ctx->r9, ctx->r24);
    // 0x80059CD0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80059CD4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80059CD8: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80059CDC: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x80059CE0: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x80059CE4: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x80059CE8: or          $t8, $t1, $t5
    ctx->r24 = ctx->r9 | ctx->r13;
    // 0x80059CEC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80059CF0: lw          $t4, 0x130($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X130);
    // 0x80059CF4: lw          $t3, 0x14C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14C);
    // 0x80059CF8: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x80059CFC: lw          $t6, 0x134($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X134);
    // 0x80059D00: subu        $t7, $t3, $t4
    ctx->r15 = SUB32(ctx->r11, ctx->r12);
    // 0x80059D04: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80059D08: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80059D0C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80059D10: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x80059D14: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x80059D18: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80059D1C: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80059D20: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x80059D24: andi        $t5, $t1, 0xFFF
    ctx->r13 = ctx->r9 & 0XFFF;
    // 0x80059D28: or          $t6, $t7, $t5
    ctx->r14 = ctx->r15 | ctx->r13;
    // 0x80059D2C: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80059D30: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80059D34: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80059D38: sw          $t1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r9;
    // 0x80059D3C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80059D40: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80059D44: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x80059D48: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80059D4C: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x80059D50: nop

    // 0x80059D54: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80059D58: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x80059D5C: nop

    // 0x80059D60: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80059D64: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80059D68: nop

    // 0x80059D6C: sw          $t5, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r13;
    // 0x80059D70: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80059D74: nop

    // 0x80059D78: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80059D7C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80059D80: lw          $t1, 0x148($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X148);
    // 0x80059D84: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x80059D88: subu        $t8, $t1, $a2
    ctx->r24 = SUB32(ctx->r9, ctx->r6);
    // 0x80059D8C: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x80059D90: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x80059D94: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x80059D98: sll         $t7, $t4, 9
    ctx->r15 = S32(ctx->r12 << 9);
    // 0x80059D9C: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x80059DA0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80059DA4: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80059DA8: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80059DAC: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80059DB0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80059DB4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80059DB8: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80059DBC: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x80059DC0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80059DC4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80059DC8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80059DCC: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80059DD0: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x80059DD4: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x80059DD8: andi        $t2, $t8, 0xFFF
    ctx->r10 = ctx->r24 & 0XFFF;
    // 0x80059DDC: subu        $t5, $t4, $t7
    ctx->r13 = SUB32(ctx->r12, ctx->r15);
    // 0x80059DE0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80059DE4: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80059DE8: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x80059DEC: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x80059DF0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80059DF4: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x80059DF8: or          $t7, $t4, $t1
    ctx->r15 = ctx->r12 | ctx->r9;
    // 0x80059DFC: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80059E00: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x80059E04: lw          $t6, 0x14C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14C);
    // 0x80059E08: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x80059E0C: lw          $t2, 0x134($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X134);
    // 0x80059E10: subu        $t8, $t6, $t9
    ctx->r24 = SUB32(ctx->r14, ctx->r25);
    // 0x80059E14: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x80059E18: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x80059E1C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80059E20: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x80059E24: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x80059E28: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80059E2C: andi        $t1, $t4, 0xFFF
    ctx->r9 = ctx->r12 & 0XFFF;
    // 0x80059E30: or          $t8, $t9, $t1
    ctx->r24 = ctx->r25 | ctx->r9;
    // 0x80059E34: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
L_80059E38:
    // 0x80059E38: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80059E3C: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x80059E40: sw          $t3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r11;
    // 0x80059E44: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80059E48: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80059E4C: addiu       $t7, $t4, 0x8
    ctx->r15 = ADD32(ctx->r12, 0X8);
    // 0x80059E50: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80059E54: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x80059E58: nop

    // 0x80059E5C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80059E60: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x80059E64: lw          $t5, 0x134($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X134);
    // 0x80059E68: subu        $t1, $t9, $a2
    ctx->r9 = SUB32(ctx->r25, ctx->r6);
    // 0x80059E6C: addiu       $t8, $t1, 0x1
    ctx->r24 = ADD32(ctx->r9, 0X1);
    // 0x80059E70: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80059E74: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80059E78: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80059E7C: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80059E80: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x80059E84: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x80059E88: sll         $t7, $t4, 12
    ctx->r15 = S32(ctx->r12 << 12);
    // 0x80059E8C: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x80059E90: or          $t8, $t7, $t1
    ctx->r24 = ctx->r15 | ctx->r9;
    // 0x80059E94: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x80059E98: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80059E9C: nop

    // 0x80059EA0: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x80059EA4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80059EA8: nop

    // 0x80059EAC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80059EB0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80059EB4: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x80059EB8: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x80059EBC: nop

    // 0x80059EC0: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80059EC4: subu        $t1, $t7, $a2
    ctx->r9 = SUB32(ctx->r15, ctx->r6);
    // 0x80059EC8: lw          $t9, 0x134($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X134);
    // 0x80059ECC: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x80059ED0: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80059ED4: addiu       $t2, $t8, 0x3
    ctx->r10 = ADD32(ctx->r24, 0X3);
    // 0x80059ED8: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x80059EDC: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80059EE0: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80059EE4: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x80059EE8: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80059EEC: addiu       $t8, $t1, -0x1
    ctx->r24 = ADD32(ctx->r9, -0X1);
    // 0x80059EF0: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x80059EF4: andi        $t2, $t8, 0xFFF
    ctx->r10 = ctx->r24 & 0XFFF;
    // 0x80059EF8: or          $t3, $t5, $t2
    ctx->r11 = ctx->r13 | ctx->r10;
    // 0x80059EFC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80059F00: lw          $t8, 0x154($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X154);
    // 0x80059F04: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x80059F08: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80059F0C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80059F10: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80059F14: addiu       $t2, $t5, 0x3
    ctx->r10 = ADD32(ctx->r13, 0X3);
    // 0x80059F18: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x80059F1C: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x80059F20: sll         $t1, $t7, 12
    ctx->r9 = S32(ctx->r15 << 12);
    // 0x80059F24: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80059F28: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x80059F2C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80059F30: lui         $t5, 0xE100
    ctx->r13 = S32(0XE100 << 16);
    // 0x80059F34: sw          $t9, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r25;
    // 0x80059F38: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80059F3C: lui         $t9, 0xF100
    ctx->r25 = S32(0XF100 << 16);
    // 0x80059F40: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80059F44: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80059F48: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x80059F4C: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80059F50: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x80059F54: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x80059F58: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80059F5C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80059F60: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80059F64: nop

    // 0x80059F68: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x80059F6C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80059F70: nop

    // 0x80059F74: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80059F78: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80059F7C: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x80059F80: nop

    // 0x80059F84: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80059F88: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80059F8C: nop

    // 0x80059F90: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80059F94: lw          $t1, 0x134($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X134);
    // 0x80059F98: lw          $t2, 0x130($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X130);
    // 0x80059F9C: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x80059FA0: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x80059FA4: addu        $t6, $t4, $t1
    ctx->r14 = ADD32(ctx->r12, ctx->r9);
    // 0x80059FA8: sw          $t3, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r11;
    // 0x80059FAC: sw          $t6, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r14;
    // 0x80059FB0: b           L_8005AA50
    // 0x80059FB4: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
        goto L_8005AA50;
    // 0x80059FB4: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
L_80059FB8:
    // 0x80059FB8: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x80059FBC: nop

    // 0x80059FC0: beq         $t0, $zero, L_80059FE8
    if (ctx->r8 == 0) {
        // 0x80059FC4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80059FE8;
    }
    // 0x80059FC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80059FC8: beq         $t0, $at, L_8005A22C
    if (ctx->r8 == ctx->r1) {
        // 0x80059FCC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005A22C;
    }
    // 0x80059FCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80059FD0: beq         $t0, $at, L_8005A484
    if (ctx->r8 == ctx->r1) {
        // 0x80059FD4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005A484;
    }
    // 0x80059FD4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80059FD8: beq         $t0, $at, L_8005A6C0
    if (ctx->r8 == ctx->r1) {
        // 0x80059FDC: nop
    
            goto L_8005A6C0;
    }
    // 0x80059FDC: nop

    // 0x80059FE0: b           L_8005A8F8
    // 0x80059FE4: nop

        goto L_8005A8F8;
    // 0x80059FE4: nop

L_80059FE8:
    // 0x80059FE8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80059FEC: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x80059FF0: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x80059FF4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80059FF8: addiu       $t1, $a1, 0x8
    ctx->r9 = ADD32(ctx->r5, 0X8);
    // 0x80059FFC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8005A000: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005A004: lw          $t5, 0x12C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X12C);
    // 0x8005A008: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x8005A00C: addiu       $t2, $t5, -0x1
    ctx->r10 = ADD32(ctx->r13, -0X1);
    // 0x8005A010: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x8005A014: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8005A018: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x8005A01C: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8005A020: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8005A024: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8005A028: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005A02C: nop

    // 0x8005A030: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
    // 0x8005A034: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005A038: nop

    // 0x8005A03C: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x8005A040: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005A044: lw          $t2, 0x148($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X148);
    // 0x8005A048: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x8005A04C: subu        $t3, $t2, $a2
    ctx->r11 = SUB32(ctx->r10, ctx->r6);
    // 0x8005A050: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8005A054: addiu       $t6, $t4, 0x9
    ctx->r14 = ADD32(ctx->r12, 0X9);
    // 0x8005A058: sra         $t1, $t6, 3
    ctx->r9 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8005A05C: andi        $t9, $t1, 0x1FF
    ctx->r25 = ctx->r9 & 0X1FF;
    // 0x8005A060: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8005A064: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8005A068: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x8005A06C: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x8005A070: lui         $t2, 0x708
    ctx->r10 = S32(0X708 << 16);
    // 0x8005A074: ori         $t2, $t2, 0x200
    ctx->r10 = ctx->r10 | 0X200;
    // 0x8005A078: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8005A07C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005A080: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8005A084: sw          $t4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r12;
    // 0x8005A088: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005A08C: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005A090: addiu       $t1, $t6, 0x8
    ctx->r9 = ADD32(ctx->r14, 0X8);
    // 0x8005A094: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005A098: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x8005A09C: nop

    // 0x8005A0A0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8005A0A4: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8005A0A8: nop

    // 0x8005A0AC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8005A0B0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005A0B4: nop

    // 0x8005A0B8: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x8005A0BC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005A0C0: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x8005A0C4: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8005A0C8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005A0CC: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A0D0: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x8005A0D4: andi        $t2, $t5, 0xFFF
    ctx->r10 = ctx->r13 & 0XFFF;
    // 0x8005A0D8: subu        $t1, $t4, $t6
    ctx->r9 = SUB32(ctx->r12, ctx->r14);
    // 0x8005A0DC: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x8005A0E0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8005A0E4: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x8005A0E8: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8005A0EC: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8005A0F0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8005A0F4: or          $t6, $t4, $t8
    ctx->r14 = ctx->r12 | ctx->r24;
    // 0x8005A0F8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005A0FC: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x8005A100: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A104: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8005A108: andi        $t5, $t7, 0xFFF
    ctx->r13 = ctx->r15 & 0XFFF;
    // 0x8005A10C: sll         $t2, $t5, 12
    ctx->r10 = S32(ctx->r13 << 12);
    // 0x8005A110: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005A114: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8005A118: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x8005A11C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8005A120: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8005A124: or          $t1, $t3, $t6
    ctx->r9 = ctx->r11 | ctx->r14;
    // 0x8005A128: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8005A12C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005A130: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8005A134: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x8005A138: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005A13C: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8005A140: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x8005A144: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005A148: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8005A14C: nop

    // 0x8005A150: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8005A154: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8005A158: nop

    // 0x8005A15C: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005A160: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005A164: nop

    // 0x8005A168: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x8005A16C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005A170: nop

    // 0x8005A174: addiu       $t9, $t1, 0x8
    ctx->r25 = ADD32(ctx->r9, 0X8);
    // 0x8005A178: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005A17C: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x8005A180: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x8005A184: subu        $t5, $t7, $a2
    ctx->r13 = SUB32(ctx->r15, ctx->r6);
    // 0x8005A188: sll         $t2, $t5, 1
    ctx->r10 = S32(ctx->r13 << 1);
    // 0x8005A18C: addiu       $t4, $t2, 0x9
    ctx->r12 = ADD32(ctx->r10, 0X9);
    // 0x8005A190: sra         $t8, $t4, 3
    ctx->r24 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8005A194: andi        $t3, $t8, 0x1FF
    ctx->r11 = ctx->r24 & 0X1FF;
    // 0x8005A198: sll         $t6, $t3, 9
    ctx->r14 = S32(ctx->r11 << 9);
    // 0x8005A19C: or          $t1, $t6, $at
    ctx->r9 = ctx->r14 | ctx->r1;
    // 0x8005A1A0: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8005A1A4: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8005A1A8: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8005A1AC: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8005A1B0: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8005A1B4: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005A1B8: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005A1BC: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x8005A1C0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005A1C4: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8005A1C8: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x8005A1CC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005A1D0: lw          $t3, 0x14C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A1D4: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x8005A1D8: andi        $t4, $t2, 0xFFF
    ctx->r12 = ctx->r10 & 0XFFF;
    // 0x8005A1DC: subu        $t1, $t3, $t6
    ctx->r9 = SUB32(ctx->r11, ctx->r14);
    // 0x8005A1E0: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x8005A1E4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8005A1E8: sll         $t8, $t4, 12
    ctx->r24 = S32(ctx->r12 << 12);
    // 0x8005A1EC: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005A1F0: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x8005A1F4: andi        $t5, $t7, 0xFFF
    ctx->r13 = ctx->r15 & 0XFFF;
    // 0x8005A1F8: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x8005A1FC: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005A200: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x8005A204: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A208: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8005A20C: andi        $t2, $t7, 0xFFF
    ctx->r10 = ctx->r15 & 0XFFF;
    // 0x8005A210: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8005A214: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005A218: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x8005A21C: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x8005A220: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x8005A224: b           L_8005A8F8
    // 0x8005A228: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
        goto L_8005A8F8;
    // 0x8005A228: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
L_8005A22C:
    // 0x8005A22C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005A230: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x8005A234: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x8005A238: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005A23C: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x8005A240: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x8005A244: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005A248: lw          $t8, 0x12C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X12C);
    // 0x8005A24C: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8005A250: sra         $t3, $t8, 1
    ctx->r11 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8005A254: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8005A258: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x8005A25C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8005A260: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005A264: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8005A268: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8005A26C: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8005A270: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005A274: nop

    // 0x8005A278: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x8005A27C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005A280: nop

    // 0x8005A284: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x8005A288: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005A28C: lw          $t4, 0x148($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X148);
    // 0x8005A290: nop

    // 0x8005A294: subu        $t5, $t4, $a2
    ctx->r13 = SUB32(ctx->r12, ctx->r6);
    // 0x8005A298: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8005A29C: sra         $t1, $t6, 1
    ctx->r9 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8005A2A0: addiu       $t9, $t1, 0x7
    ctx->r25 = ADD32(ctx->r9, 0X7);
    // 0x8005A2A4: sra         $t7, $t9, 3
    ctx->r15 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8005A2A8: andi        $t2, $t7, 0x1FF
    ctx->r10 = ctx->r15 & 0X1FF;
    // 0x8005A2AC: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8005A2B0: sll         $t8, $t2, 9
    ctx->r24 = S32(ctx->r10 << 9);
    // 0x8005A2B4: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x8005A2B8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8005A2BC: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8005A2C0: lui         $t5, 0x708
    ctx->r13 = S32(0X708 << 16);
    // 0x8005A2C4: ori         $t5, $t5, 0x200
    ctx->r13 = ctx->r13 | 0X200;
    // 0x8005A2C8: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8005A2CC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005A2D0: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8005A2D4: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8005A2D8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005A2DC: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005A2E0: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8005A2E4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005A2E8: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8005A2EC: nop

    // 0x8005A2F0: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8005A2F4: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8005A2F8: nop

    // 0x8005A2FC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005A300: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005A304: nop

    // 0x8005A308: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8005A30C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005A310: sll         $t4, $a2, 1
    ctx->r12 = S32(ctx->r6 << 1);
    // 0x8005A314: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8005A318: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005A31C: lw          $t1, 0x14C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A320: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x8005A324: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x8005A328: subu        $t7, $t1, $t9
    ctx->r15 = SUB32(ctx->r9, ctx->r25);
    // 0x8005A32C: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8005A330: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8005A334: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x8005A338: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8005A33C: or          $t1, $t6, $at
    ctx->r9 = ctx->r14 | ctx->r1;
    // 0x8005A340: andi        $t3, $t8, 0xFFF
    ctx->r11 = ctx->r24 & 0XFFF;
    // 0x8005A344: or          $t9, $t1, $t3
    ctx->r25 = ctx->r9 | ctx->r11;
    // 0x8005A348: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8005A34C: lw          $t2, 0x148($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X148);
    // 0x8005A350: lw          $t1, 0x14C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A354: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x8005A358: andi        $t4, $t8, 0xFFF
    ctx->r12 = ctx->r24 & 0XFFF;
    // 0x8005A35C: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x8005A360: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005A364: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8005A368: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8005A36C: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x8005A370: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8005A374: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8005A378: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8005A37C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005A380: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x8005A384: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x8005A388: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005A38C: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8005A390: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8005A394: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005A398: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8005A39C: nop

    // 0x8005A3A0: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x8005A3A4: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8005A3A8: nop

    // 0x8005A3AC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8005A3B0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005A3B4: nop

    // 0x8005A3B8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8005A3BC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005A3C0: nop

    // 0x8005A3C4: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x8005A3C8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005A3CC: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x8005A3D0: nop

    // 0x8005A3D4: subu        $t4, $t8, $a2
    ctx->r12 = SUB32(ctx->r24, ctx->r6);
    // 0x8005A3D8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8005A3DC: sra         $t1, $t5, 1
    ctx->r9 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8005A3E0: addiu       $t3, $t1, 0x7
    ctx->r11 = ADD32(ctx->r9, 0X7);
    // 0x8005A3E4: sra         $t6, $t3, 3
    ctx->r14 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8005A3E8: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8005A3EC: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8005A3F0: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8005A3F4: or          $t2, $t7, $at
    ctx->r10 = ctx->r15 | ctx->r1;
    // 0x8005A3F8: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8005A3FC: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8005A400: lui         $t4, 0x8
    ctx->r12 = S32(0X8 << 16);
    // 0x8005A404: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x8005A408: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8005A40C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005A410: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005A414: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x8005A418: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005A41C: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x8005A420: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8005A424: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005A428: lw          $t9, 0x14C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A42C: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x8005A430: andi        $t3, $t1, 0xFFF
    ctx->r11 = ctx->r9 & 0XFFF;
    // 0x8005A434: subu        $t2, $t9, $t7
    ctx->r10 = SUB32(ctx->r25, ctx->r15);
    // 0x8005A438: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8005A43C: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8005A440: sll         $t6, $t3, 12
    ctx->r14 = S32(ctx->r11 << 12);
    // 0x8005A444: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8005A448: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8005A44C: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x8005A450: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x8005A454: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8005A458: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x8005A45C: lw          $t6, 0x14C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A460: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8005A464: andi        $t1, $t4, 0xFFF
    ctx->r9 = ctx->r12 & 0XFFF;
    // 0x8005A468: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8005A46C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8005A470: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x8005A474: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x8005A478: or          $t7, $t3, $t5
    ctx->r15 = ctx->r11 | ctx->r13;
    // 0x8005A47C: b           L_8005A8F8
    // 0x8005A480: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
        goto L_8005A8F8;
    // 0x8005A480: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
L_8005A484:
    // 0x8005A484: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005A488: lui         $at, 0xFD68
    ctx->r1 = S32(0XFD68 << 16);
    // 0x8005A48C: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x8005A490: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005A494: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x8005A498: addiu       $t1, $t4, 0x8
    ctx->r9 = ADD32(ctx->r12, 0X8);
    // 0x8005A49C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005A4A0: lw          $t6, 0x12C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X12C);
    // 0x8005A4A4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8005A4A8: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x8005A4AC: andi        $t3, $t9, 0xFFF
    ctx->r11 = ctx->r25 & 0XFFF;
    // 0x8005A4B0: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x8005A4B4: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8005A4B8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8005A4BC: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8005A4C0: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x8005A4C4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005A4C8: nop

    // 0x8005A4CC: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x8005A4D0: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005A4D4: nop

    // 0x8005A4D8: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x8005A4DC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005A4E0: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x8005A4E4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8005A4E8: subu        $t3, $t9, $a2
    ctx->r11 = SUB32(ctx->r25, ctx->r6);
    // 0x8005A4EC: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x8005A4F0: sra         $t7, $t5, 3
    ctx->r15 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8005A4F4: andi        $t2, $t7, 0x1FF
    ctx->r10 = ctx->r15 & 0X1FF;
    // 0x8005A4F8: sll         $t8, $t2, 9
    ctx->r24 = S32(ctx->r10 << 9);
    // 0x8005A4FC: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x8005A500: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8005A504: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8005A508: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x8005A50C: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8005A510: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8005A514: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005A518: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8005A51C: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x8005A520: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005A524: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005A528: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x8005A52C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005A530: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8005A534: nop

    // 0x8005A538: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8005A53C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8005A540: nop

    // 0x8005A544: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8005A548: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005A54C: nop

    // 0x8005A550: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8005A554: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005A558: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x8005A55C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8005A560: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005A564: lw          $t3, 0x14C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A568: lw          $t5, 0x130($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X130);
    // 0x8005A56C: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x8005A570: subu        $t7, $t3, $t5
    ctx->r15 = SUB32(ctx->r11, ctx->r13);
    // 0x8005A574: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8005A578: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8005A57C: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8005A580: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8005A584: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x8005A588: andi        $t4, $t8, 0xFFF
    ctx->r12 = ctx->r24 & 0XFFF;
    // 0x8005A58C: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8005A590: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8005A594: lw          $t2, 0x148($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X148);
    // 0x8005A598: lw          $t3, 0x14C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A59C: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8005A5A0: andi        $t1, $t8, 0xFFF
    ctx->r9 = ctx->r24 & 0XFFF;
    // 0x8005A5A4: sll         $t6, $t1, 12
    ctx->r14 = S32(ctx->r9 << 12);
    // 0x8005A5A8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005A5AC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005A5B0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005A5B4: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x8005A5B8: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8005A5BC: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x8005A5C0: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8005A5C4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005A5C8: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8005A5CC: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8005A5D0: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005A5D4: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8005A5D8: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x8005A5DC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005A5E0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8005A5E4: nop

    // 0x8005A5E8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8005A5EC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8005A5F0: nop

    // 0x8005A5F4: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8005A5F8: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005A5FC: nop

    // 0x8005A600: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8005A604: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005A608: nop

    // 0x8005A60C: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x8005A610: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005A614: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x8005A618: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8005A61C: subu        $t1, $t8, $a2
    ctx->r9 = SUB32(ctx->r24, ctx->r6);
    // 0x8005A620: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x8005A624: sra         $t3, $t6, 3
    ctx->r11 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8005A628: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x8005A62C: sll         $t9, $t4, 9
    ctx->r25 = S32(ctx->r12 << 9);
    // 0x8005A630: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x8005A634: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8005A638: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005A63C: lui         $t2, 0x8
    ctx->r10 = S32(0X8 << 16);
    // 0x8005A640: ori         $t2, $t2, 0x200
    ctx->r10 = ctx->r10 | 0X200;
    // 0x8005A644: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x8005A648: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005A64C: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005A650: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8005A654: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005A658: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x8005A65C: addiu       $t3, $t6, 0x8
    ctx->r11 = ADD32(ctx->r14, 0X8);
    // 0x8005A660: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005A664: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A668: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x8005A66C: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x8005A670: subu        $t5, $t4, $t9
    ctx->r13 = SUB32(ctx->r12, ctx->r25);
    // 0x8005A674: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8005A678: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x8005A67C: sll         $t3, $t6, 12
    ctx->r11 = S32(ctx->r14 << 12);
    // 0x8005A680: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8005A684: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8005A688: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x8005A68C: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x8005A690: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x8005A694: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x8005A698: lw          $t3, 0x14C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A69C: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x8005A6A0: andi        $t1, $t2, 0xFFF
    ctx->r9 = ctx->r10 & 0XFFF;
    // 0x8005A6A4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005A6A8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8005A6AC: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x8005A6B0: sll         $t6, $t1, 12
    ctx->r14 = S32(ctx->r9 << 12);
    // 0x8005A6B4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8005A6B8: b           L_8005A8F8
    // 0x8005A6BC: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
        goto L_8005A8F8;
    // 0x8005A6BC: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
L_8005A6C0:
    // 0x8005A6C0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005A6C4: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x8005A6C8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8005A6CC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005A6D0: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
    // 0x8005A6D4: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x8005A6D8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005A6DC: lw          $t3, 0x12C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X12C);
    // 0x8005A6E0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005A6E4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8005A6E8: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x8005A6EC: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8005A6F0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8005A6F4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005A6F8: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005A6FC: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8005A700: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005A704: nop

    // 0x8005A708: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8005A70C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005A710: nop

    // 0x8005A714: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x8005A718: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005A71C: lw          $t4, 0x148($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X148);
    // 0x8005A720: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005A724: subu        $t6, $t4, $a2
    ctx->r14 = SUB32(ctx->r12, ctx->r6);
    // 0x8005A728: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8005A72C: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8005A730: andi        $t5, $t9, 0x1FF
    ctx->r13 = ctx->r25 & 0X1FF;
    // 0x8005A734: sll         $t7, $t5, 9
    ctx->r15 = S32(ctx->r13 << 9);
    // 0x8005A738: or          $t2, $t7, $at
    ctx->r10 = ctx->r15 | ctx->r1;
    // 0x8005A73C: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x8005A740: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8005A744: lui         $t3, 0x708
    ctx->r11 = S32(0X708 << 16);
    // 0x8005A748: ori         $t3, $t3, 0x200
    ctx->r11 = ctx->r11 | 0X200;
    // 0x8005A74C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8005A750: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005A754: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x8005A758: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8005A75C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005A760: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005A764: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8005A768: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005A76C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8005A770: nop

    // 0x8005A774: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8005A778: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005A77C: nop

    // 0x8005A780: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8005A784: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005A788: nop

    // 0x8005A78C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8005A790: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005A794: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x8005A798: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8005A79C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005A7A0: lw          $t6, 0x14C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A7A4: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x8005A7A8: andi        $t3, $t1, 0xFFF
    ctx->r11 = ctx->r9 & 0XFFF;
    // 0x8005A7AC: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x8005A7B0: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8005A7B4: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8005A7B8: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x8005A7BC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005A7C0: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x8005A7C4: andi        $t2, $t7, 0xFFF
    ctx->r10 = ctx->r15 & 0XFFF;
    // 0x8005A7C8: or          $t8, $t6, $t2
    ctx->r24 = ctx->r14 | ctx->r10;
    // 0x8005A7CC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8005A7D0: lw          $t5, 0x148($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X148);
    // 0x8005A7D4: lw          $t6, 0x14C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A7D8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8005A7DC: andi        $t1, $t7, 0xFFF
    ctx->r9 = ctx->r15 & 0XFFF;
    // 0x8005A7E0: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x8005A7E4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005A7E8: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8005A7EC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8005A7F0: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x8005A7F4: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8005A7F8: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x8005A7FC: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8005A800: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005A804: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005A808: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8005A80C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005A810: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005A814: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x8005A818: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005A81C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8005A820: nop

    // 0x8005A824: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8005A828: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8005A82C: nop

    // 0x8005A830: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8005A834: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005A838: nop

    // 0x8005A83C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8005A840: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005A844: nop

    // 0x8005A848: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x8005A84C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005A850: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x8005A854: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8005A858: subu        $t1, $t7, $a2
    ctx->r9 = SUB32(ctx->r15, ctx->r6);
    // 0x8005A85C: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x8005A860: sra         $t6, $t3, 3
    ctx->r14 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8005A864: andi        $t2, $t6, 0x1FF
    ctx->r10 = ctx->r14 & 0X1FF;
    // 0x8005A868: sll         $t4, $t2, 9
    ctx->r12 = S32(ctx->r10 << 9);
    // 0x8005A86C: or          $t8, $t4, $at
    ctx->r24 = ctx->r12 | ctx->r1;
    // 0x8005A870: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8005A874: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005A878: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x8005A87C: ori         $t5, $t5, 0x200
    ctx->r13 = ctx->r13 | 0X200;
    // 0x8005A880: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8005A884: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005A888: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005A88C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8005A890: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005A894: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x8005A898: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8005A89C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005A8A0: lw          $t2, 0x14C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A8A4: lw          $t4, 0x130($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X130);
    // 0x8005A8A8: andi        $t3, $t1, 0xFFF
    ctx->r11 = ctx->r9 & 0XFFF;
    // 0x8005A8AC: subu        $t8, $t2, $t4
    ctx->r24 = SUB32(ctx->r10, ctx->r12);
    // 0x8005A8B0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8005A8B4: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8005A8B8: sll         $t6, $t3, 12
    ctx->r14 = S32(ctx->r11 << 12);
    // 0x8005A8BC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A8C0: or          $t2, $t6, $at
    ctx->r10 = ctx->r14 | ctx->r1;
    // 0x8005A8C4: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x8005A8C8: or          $t4, $t2, $t7
    ctx->r12 = ctx->r10 | ctx->r15;
    // 0x8005A8CC: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8005A8D0: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x8005A8D4: lw          $t6, 0x14C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14C);
    // 0x8005A8D8: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8005A8DC: andi        $t1, $t5, 0xFFF
    ctx->r9 = ctx->r13 & 0XFFF;
    // 0x8005A8E0: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8005A8E4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A8E8: andi        $t7, $t2, 0xFFF
    ctx->r15 = ctx->r10 & 0XFFF;
    // 0x8005A8EC: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x8005A8F0: or          $t4, $t3, $t7
    ctx->r12 = ctx->r11 | ctx->r15;
    // 0x8005A8F4: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
L_8005A8F8:
    // 0x8005A8F8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005A8FC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8005A900: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8005A904: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005A908: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8005A90C: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x8005A910: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005A914: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005A918: nop

    // 0x8005A91C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8005A920: lw          $t3, 0x148($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X148);
    // 0x8005A924: lw          $t1, 0x130($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X130);
    // 0x8005A928: subu        $t7, $t3, $a2
    ctx->r15 = SUB32(ctx->r11, ctx->r6);
    // 0x8005A92C: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x8005A930: addiu       $t8, $t4, 0x3
    ctx->r24 = ADD32(ctx->r12, 0X3);
    // 0x8005A934: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8005A938: addiu       $t2, $t6, -0x1
    ctx->r10 = ADD32(ctx->r14, -0X1);
    // 0x8005A93C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8005A940: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8005A944: sll         $t5, $t9, 12
    ctx->r13 = S32(ctx->r25 << 12);
    // 0x8005A948: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x8005A94C: or          $t7, $t5, $t3
    ctx->r15 = ctx->r13 | ctx->r11;
    // 0x8005A950: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8005A954: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005A958: nop

    // 0x8005A95C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8005A960: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005A964: nop

    // 0x8005A968: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8005A96C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005A970: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x8005A974: lw          $t2, 0x148($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X148);
    // 0x8005A978: nop

    // 0x8005A97C: addu        $t5, $t6, $t2
    ctx->r13 = ADD32(ctx->r14, ctx->r10);
    // 0x8005A980: subu        $t3, $t5, $a2
    ctx->r11 = SUB32(ctx->r13, ctx->r6);
    // 0x8005A984: lw          $t2, 0x130($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X130);
    // 0x8005A988: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x8005A98C: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8005A990: addiu       $t4, $t7, 0x3
    ctx->r12 = ADD32(ctx->r15, 0X3);
    // 0x8005A994: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x8005A998: addu        $t5, $t6, $t2
    ctx->r13 = ADD32(ctx->r14, ctx->r10);
    // 0x8005A99C: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8005A9A0: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8005A9A4: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x8005A9A8: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x8005A9AC: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8005A9B0: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x8005A9B4: or          $t8, $t1, $t4
    ctx->r24 = ctx->r9 | ctx->r12;
    // 0x8005A9B8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8005A9BC: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x8005A9C0: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x8005A9C4: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8005A9C8: andi        $t5, $t2, 0xFFF
    ctx->r13 = ctx->r10 & 0XFFF;
    // 0x8005A9CC: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x8005A9D0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8005A9D4: andi        $t4, $t1, 0xFFF
    ctx->r12 = ctx->r9 & 0XFFF;
    // 0x8005A9D8: sll         $t3, $t5, 12
    ctx->r11 = S32(ctx->r13 << 12);
    // 0x8005A9DC: or          $t8, $t3, $t4
    ctx->r24 = ctx->r11 | ctx->r12;
    // 0x8005A9E0: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8005A9E4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005A9E8: lui         $t7, 0xE100
    ctx->r15 = S32(0XE100 << 16);
    // 0x8005A9EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005A9F0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005A9F4: lui         $t6, 0xF100
    ctx->r14 = S32(0XF100 << 16);
    // 0x8005A9F8: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x8005A9FC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005AA00: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x8005AA04: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x8005AA08: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005AA0C: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x8005AA10: ori         $t5, $t5, 0x400
    ctx->r13 = ctx->r13 | 0X400;
    // 0x8005AA14: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005AA18: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005AA1C: nop

    // 0x8005AA20: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x8005AA24: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005AA28: nop

    // 0x8005AA2C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8005AA30: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005AA34: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8005AA38: nop

    // 0x8005AA3C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8005AA40: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8005AA44: nop

    // 0x8005AA48: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8005AA4C: sw          $zero, 0x130($sp)
    MEM_W(0X130, ctx->r29) = 0;
L_8005AA50:
    // 0x8005AA50: lw          $t1, 0x130($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X130);
    // 0x8005AA54: nop

    // 0x8005AA58: bne         $t1, $zero, L_80059460
    if (ctx->r9 != 0) {
        // 0x8005AA5C: nop
    
            goto L_80059460;
    }
    // 0x8005AA5C: nop

L_8005AA60:
    // 0x8005AA60: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005AA64: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8005AA68: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x8005AA6C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005AA70: nop

    // 0x8005AA74: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x8005AA78: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005AA7C: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8005AA80: nop

    // 0x8005AA84: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8005AA88: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8005AA8C: nop

    // 0x8005AA90: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_8005AA94:
    // 0x8005AA94: jr          $ra
    // 0x8005AA98: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    return;
    // 0x8005AA98: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
;}

RECOMP_FUNC void Sprite_DrawScaledRGB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AA9C: beq         $a1, $zero, L_8005BBF4
    if (ctx->r5 == 0) {
        // 0x8005AAA0: addiu       $sp, $sp, -0xE8
        ctx->r29 = ADD32(ctx->r29, -0XE8);
            goto L_8005BBF4;
    }
    // 0x8005AAA0: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8005AAA4: lw          $t6, 0x118($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X118);
    // 0x8005AAA8: nop

    // 0x8005AAAC: beq         $t6, $zero, L_8005BBF4
    if (ctx->r14 == 0) {
        // 0x8005AAB0: nop
    
            goto L_8005BBF4;
    }
    // 0x8005AAB0: nop

    // 0x8005AAB4: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x8005AAB8: lw          $t6, 0x11C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X11C);
    // 0x8005AABC: subu        $t2, $t1, $a3
    ctx->r10 = SUB32(ctx->r9, ctx->r7);
    // 0x8005AAC0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8005AAC4: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x8005AAC8: addiu       $t5, $t4, 0xFFF
    ctx->r13 = ADD32(ctx->r12, 0XFFF);
    // 0x8005AACC: div         $zero, $t5, $t6
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r14)));
    // 0x8005AAD0: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x8005AAD4: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x8005AAD8: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x8005AADC: lhu         $t8, 0x2($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X2);
    // 0x8005AAE0: nop

    // 0x8005AAE4: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    // 0x8005AAE8: lhu         $t9, 0x4($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X4);
    // 0x8005AAEC: nop

    // 0x8005AAF0: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x8005AAF4: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x8005AAF8: bne         $t6, $zero, L_8005AB04
    if (ctx->r14 != 0) {
        // 0x8005AAFC: nop
    
            goto L_8005AB04;
    }
    // 0x8005AAFC: nop

    // 0x8005AB00: break       7
    do_break(2147855104);
L_8005AB04:
    // 0x8005AB04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005AB08: bne         $t6, $at, L_8005AB1C
    if (ctx->r14 != ctx->r1) {
        // 0x8005AB0C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005AB1C;
    }
    // 0x8005AB0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005AB10: bne         $t5, $at, L_8005AB1C
    if (ctx->r13 != ctx->r1) {
        // 0x8005AB14: nop
    
            goto L_8005AB1C;
    }
    // 0x8005AB14: nop

    // 0x8005AB18: break       6
    do_break(2147855128);
L_8005AB1C:
    // 0x8005AB1C: subu        $t3, $t9, $t2
    ctx->r11 = SUB32(ctx->r25, ctx->r10);
    // 0x8005AB20: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x8005AB24: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x8005AB28: addiu       $t6, $t5, 0xFFF
    ctx->r14 = ADD32(ctx->r13, 0XFFF);
    // 0x8005AB2C: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x8005AB30: mflo        $t7
    ctx->r15 = lo;
    // 0x8005AB34: addiu       $t8, $t7, -0x5
    ctx->r24 = ADD32(ctx->r15, -0X5);
    // 0x8005AB38: lw          $t7, 0x120($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X120);
    // 0x8005AB3C: sw          $t8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r24;
    // 0x8005AB40: div         $zero, $t6, $t7
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r15)));
    // 0x8005AB44: bne         $t7, $zero, L_8005AB50
    if (ctx->r15 != 0) {
        // 0x8005AB48: nop
    
            goto L_8005AB50;
    }
    // 0x8005AB48: nop

    // 0x8005AB4C: break       7
    do_break(2147855180);
L_8005AB50:
    // 0x8005AB50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005AB54: bne         $t7, $at, L_8005AB68
    if (ctx->r15 != ctx->r1) {
        // 0x8005AB58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005AB68;
    }
    // 0x8005AB58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005AB5C: bne         $t6, $at, L_8005AB68
    if (ctx->r14 != ctx->r1) {
        // 0x8005AB60: nop
    
            goto L_8005AB68;
    }
    // 0x8005AB60: nop

    // 0x8005AB64: break       6
    do_break(2147855204);
L_8005AB68:
    // 0x8005AB68: mflo        $t8
    ctx->r24 = lo;
    // 0x8005AB6C: addiu       $t3, $t8, -0x9
    ctx->r11 = ADD32(ctx->r24, -0X9);
    // 0x8005AB70: blez        $t4, L_8005BBF4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8005AB74: sw          $t3, 0xD4($sp)
        MEM_W(0XD4, ctx->r29) = ctx->r11;
            goto L_8005BBF4;
    }
    // 0x8005AB74: sw          $t3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r11;
    // 0x8005AB78: lw          $t5, 0xE0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE0);
    // 0x8005AB7C: nop

    // 0x8005AB80: blez        $t5, L_8005BBF4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8005AB84: slt         $at, $t1, $a3
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8005BBF4;
    }
    // 0x8005AB84: slt         $at, $t1, $a3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005AB88: bne         $at, $zero, L_8005BBF4
    if (ctx->r1 != 0) {
        // 0x8005AB8C: slt         $at, $t9, $t2
        ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8005BBF4;
    }
    // 0x8005AB8C: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8005AB90: bne         $at, $zero, L_8005BBF4
    if (ctx->r1 != 0) {
        // 0x8005AB94: nop
    
            goto L_8005BBF4;
    }
    // 0x8005AB94: nop

    // 0x8005AB98: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8005AB9C: lh          $t6, 0x164($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X164);
    // 0x8005ABA0: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x8005ABA4: nop

    // 0x8005ABA8: beq         $t6, $t7, L_8005AE14
    if (ctx->r14 == ctx->r15) {
        // 0x8005ABAC: nop
    
            goto L_8005AE14;
    }
    // 0x8005ABAC: nop

    // 0x8005ABB0: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x8005ABB4: beq         $t0, $zero, L_8005ABDC
    if (ctx->r8 == 0) {
        // 0x8005ABB8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005ABDC;
    }
    // 0x8005ABB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005ABBC: beq         $t0, $at, L_8005AC5C
    if (ctx->r8 == ctx->r1) {
        // 0x8005ABC0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005AC5C;
    }
    // 0x8005ABC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005ABC4: beq         $t0, $at, L_8005AC1C
    if (ctx->r8 == ctx->r1) {
        // 0x8005ABC8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005AC1C;
    }
    // 0x8005ABC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005ABCC: beq         $t0, $at, L_8005AC9C
    if (ctx->r8 == ctx->r1) {
        // 0x8005ABD0: nop
    
            goto L_8005AC9C;
    }
    // 0x8005ABD0: nop

    // 0x8005ABD4: b           L_8005BBF4
    // 0x8005ABD8: nop

        goto L_8005BBF4;
    // 0x8005ABD8: nop

L_8005ABDC:
    // 0x8005ABDC: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x8005ABE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005ABE4: sw          $t8, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r24;
    // 0x8005ABE8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005ABEC: lui         $t1, 0xE300
    ctx->r9 = S32(0XE300 << 16);
    // 0x8005ABF0: sw          $t3, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r11;
    // 0x8005ABF4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005ABF8: ori         $t1, $t1, 0x1001
    ctx->r9 = ctx->r9 | 0X1001;
    // 0x8005ABFC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8005AC00: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005AC04: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x8005AC08: nop

    // 0x8005AC0C: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8005AC10: lw          $t2, 0xD0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD0);
    // 0x8005AC14: b           L_8005AF4C
    // 0x8005AC18: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
        goto L_8005AF4C;
    // 0x8005AC18: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_8005AC1C:
    // 0x8005AC1C: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x8005AC20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005AC24: sw          $t6, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r14;
    // 0x8005AC28: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005AC2C: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x8005AC30: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    // 0x8005AC34: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005AC38: ori         $t4, $t4, 0x1001
    ctx->r12 = ctx->r12 | 0X1001;
    // 0x8005AC3C: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x8005AC40: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005AC44: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x8005AC48: nop

    // 0x8005AC4C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8005AC50: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
    // 0x8005AC54: b           L_8005AF4C
    // 0x8005AC58: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
        goto L_8005AF4C;
    // 0x8005AC58: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
L_8005AC5C:
    // 0x8005AC5C: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x8005AC60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005AC64: sw          $t9, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r25;
    // 0x8005AC68: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005AC6C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8005AC70: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x8005AC74: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005AC78: ori         $t8, $t8, 0x1001
    ctx->r24 = ctx->r24 | 0X1001;
    // 0x8005AC7C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005AC80: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005AC84: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8005AC88: nop

    // 0x8005AC8C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8005AC90: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8005AC94: b           L_8005AF4C
    // 0x8005AC98: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
        goto L_8005AF4C;
    // 0x8005AC98: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
L_8005AC9C:
    // 0x8005AC9C: addiu       $t5, $zero, 0x800
    ctx->r13 = ADD32(0, 0X800);
    // 0x8005ACA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005ACA4: sw          $t5, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r13;
    // 0x8005ACA8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005ACAC: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x8005ACB0: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x8005ACB4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005ACB8: ori         $t6, $t6, 0x1001
    ctx->r14 = ctx->r14 | 0X1001;
    // 0x8005ACBC: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x8005ACC0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005ACC4: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x8005ACC8: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x8005ACCC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8005ACD0: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x8005ACD4: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8005ACD8: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8005ACDC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005ACE0: nop

    // 0x8005ACE4: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x8005ACE8: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005ACEC: lui         $t4, 0xE800
    ctx->r12 = S32(0XE800 << 16);
    // 0x8005ACF0: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x8005ACF4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005ACF8: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x8005ACFC: nop

    // 0x8005AD00: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8005AD04: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x8005AD08: nop

    // 0x8005AD0C: sw          $a2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r6;
    // 0x8005AD10: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005AD14: nop

    // 0x8005AD18: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x8005AD1C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005AD20: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8005AD24: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x8005AD28: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005AD2C: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x8005AD30: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8005AD34: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8005AD38: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x8005AD3C: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x8005AD40: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8005AD44: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005AD48: nop

    // 0x8005AD4C: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
    // 0x8005AD50: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005AD54: nop

    // 0x8005AD58: addiu       $t6, $t2, 0x8
    ctx->r14 = ADD32(ctx->r10, 0X8);
    // 0x8005AD5C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005AD60: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x8005AD64: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8005AD68: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005AD6C: lw          $t4, 0xB8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB8);
    // 0x8005AD70: nop

    // 0x8005AD74: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8005AD78: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005AD7C: nop

    // 0x8005AD80: sw          $t5, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r13;
    // 0x8005AD84: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005AD88: lui         $t5, 0xF000
    ctx->r13 = S32(0XF000 << 16);
    // 0x8005AD8C: addiu       $t9, $t1, 0x8
    ctx->r25 = ADD32(ctx->r9, 0X8);
    // 0x8005AD90: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005AD94: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8005AD98: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x8005AD9C: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8005ADA0: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8005ADA4: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8005ADA8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8005ADAC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005ADB0: nop

    // 0x8005ADB4: sw          $t8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r24;
    // 0x8005ADB8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005ADBC: nop

    // 0x8005ADC0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8005ADC4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005ADC8: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8005ADCC: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8005ADD0: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x8005ADD4: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x8005ADD8: nop

    // 0x8005ADDC: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8005ADE0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005ADE4: nop

    // 0x8005ADE8: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x8005ADEC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005ADF0: nop

    // 0x8005ADF4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8005ADF8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005ADFC: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x8005AE00: nop

    // 0x8005AE04: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8005AE08: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x8005AE0C: b           L_8005AF4C
    // 0x8005AE10: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
        goto L_8005AF4C;
    // 0x8005AE10: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
L_8005AE14:
    // 0x8005AE14: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005AE18: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8005AE1C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x8005AE20: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005AE24: lui         $t1, 0xE800
    ctx->r9 = S32(0XE800 << 16);
    // 0x8005AE28: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x8005AE2C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005AE30: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8005AE34: nop

    // 0x8005AE38: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8005AE3C: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x8005AE40: nop

    // 0x8005AE44: sw          $a2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r6;
    // 0x8005AE48: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005AE4C: nop

    // 0x8005AE50: sw          $t3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r11;
    // 0x8005AE54: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005AE58: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x8005AE5C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8005AE60: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005AE64: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x8005AE68: ori         $t3, $t3, 0x100
    ctx->r11 = ctx->r11 | 0X100;
    // 0x8005AE6C: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8005AE70: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x8005AE74: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x8005AE78: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8005AE7C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005AE80: nop

    // 0x8005AE84: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
    // 0x8005AE88: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005AE8C: nop

    // 0x8005AE90: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8005AE94: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005AE98: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AE9C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8005AEA0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8005AEA4: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AEA8: nop

    // 0x8005AEAC: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8005AEB0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005AEB4: nop

    // 0x8005AEB8: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8005AEBC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005AEC0: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x8005AEC4: addiu       $t6, $t2, 0x8
    ctx->r14 = ADD32(ctx->r10, 0X8);
    // 0x8005AEC8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005AECC: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8005AED0: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x8005AED4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005AED8: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x8005AEDC: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x8005AEE0: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005AEE4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005AEE8: nop

    // 0x8005AEEC: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x8005AEF0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005AEF4: nop

    // 0x8005AEF8: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x8005AEFC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005AF00: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x8005AF04: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8005AF08: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8005AF0C: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x8005AF10: nop

    // 0x8005AF14: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8005AF18: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005AF1C: nop

    // 0x8005AF20: sw          $t8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r24;
    // 0x8005AF24: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005AF28: nop

    // 0x8005AF2C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8005AF30: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005AF34: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8005AF38: nop

    // 0x8005AF3C: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x8005AF40: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x8005AF44: nop

    // 0x8005AF48: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
L_8005AF4C:
    // 0x8005AF4C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8005AF50: lbu         $t2, 0x168($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X168);
    // 0x8005AF54: lw          $t6, 0x10C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10C);
    // 0x8005AF58: nop

    // 0x8005AF5C: bne         $t2, $t6, L_8005AFC4
    if (ctx->r10 != ctx->r14) {
        // 0x8005AF60: nop
    
            goto L_8005AFC4;
    }
    // 0x8005AF60: nop

    // 0x8005AF64: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8005AF68: lbu         $t7, 0x16C($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X16C);
    // 0x8005AF6C: lw          $t8, 0x110($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X110);
    // 0x8005AF70: nop

    // 0x8005AF74: bne         $t7, $t8, L_8005AFC4
    if (ctx->r15 != ctx->r24) {
        // 0x8005AF78: nop
    
            goto L_8005AFC4;
    }
    // 0x8005AF78: nop

    // 0x8005AF7C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8005AF80: lbu         $t3, 0x170($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X170);
    // 0x8005AF84: lw          $t4, 0x114($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X114);
    // 0x8005AF88: nop

    // 0x8005AF8C: bne         $t3, $t4, L_8005AFC4
    if (ctx->r11 != ctx->r12) {
        // 0x8005AF90: nop
    
            goto L_8005AFC4;
    }
    // 0x8005AF90: nop

    // 0x8005AF94: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8005AF98: lbu         $t5, 0x174($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X174);
    // 0x8005AF9C: lw          $t1, 0x118($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X118);
    // 0x8005AFA0: nop

    // 0x8005AFA4: bne         $t5, $t1, L_8005AFC4
    if (ctx->r13 != ctx->r9) {
        // 0x8005AFA8: nop
    
            goto L_8005AFC4;
    }
    // 0x8005AFA8: nop

    // 0x8005AFAC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8005AFB0: lh          $t9, 0x164($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X164);
    // 0x8005AFB4: lw          $t2, 0xDC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XDC);
    // 0x8005AFB8: nop

    // 0x8005AFBC: beq         $t9, $t2, L_8005B170
    if (ctx->r25 == ctx->r10) {
        // 0x8005AFC0: nop
    
            goto L_8005B170;
    }
    // 0x8005AFC0: nop

L_8005AFC4:
    // 0x8005AFC4: lw          $t6, 0x118($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X118);
    // 0x8005AFC8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005AFCC: bne         $t6, $at, L_8005B03C
    if (ctx->r14 != ctx->r1) {
        // 0x8005AFD0: nop
    
            goto L_8005B03C;
    }
    // 0x8005AFD0: nop

    // 0x8005AFD4: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x8005AFD8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005AFDC: bne         $t7, $at, L_8005B03C
    if (ctx->r15 != ctx->r1) {
        // 0x8005AFE0: nop
    
            goto L_8005B03C;
    }
    // 0x8005AFE0: nop

    // 0x8005AFE4: lw          $t8, 0x110($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X110);
    // 0x8005AFE8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005AFEC: bne         $t8, $at, L_8005B03C
    if (ctx->r24 != ctx->r1) {
        // 0x8005AFF0: nop
    
            goto L_8005B03C;
    }
    // 0x8005AFF0: nop

    // 0x8005AFF4: lw          $t3, 0x114($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X114);
    // 0x8005AFF8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005AFFC: bne         $t3, $at, L_8005B03C
    if (ctx->r11 != ctx->r1) {
        // 0x8005B000: nop
    
            goto L_8005B03C;
    }
    // 0x8005B000: nop

    // 0x8005B004: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005B008: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8005B00C: sw          $t4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r12;
    // 0x8005B010: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005B014: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8005B018: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x8005B01C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005B020: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x8005B024: lui         $t6, 0xFFFC
    ctx->r14 = S32(0XFFFC << 16);
    // 0x8005B028: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8005B02C: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x8005B030: ori         $t6, $t6, 0xF279
    ctx->r14 = ctx->r14 | 0XF279;
    // 0x8005B034: b           L_8005B140
    // 0x8005B038: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
        goto L_8005B140;
    // 0x8005B038: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
L_8005B03C:
    // 0x8005B03C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8005B040: lbu         $t8, 0x168($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X168);
    // 0x8005B044: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005B048: bne         $t8, $at, L_8005B08C
    if (ctx->r24 != ctx->r1) {
        // 0x8005B04C: nop
    
            goto L_8005B08C;
    }
    // 0x8005B04C: nop

    // 0x8005B050: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8005B054: lbu         $t3, 0x16C($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X16C);
    // 0x8005B058: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005B05C: bne         $t3, $at, L_8005B08C
    if (ctx->r11 != ctx->r1) {
        // 0x8005B060: nop
    
            goto L_8005B08C;
    }
    // 0x8005B060: nop

    // 0x8005B064: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8005B068: lbu         $t4, 0x170($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X170);
    // 0x8005B06C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005B070: bne         $t4, $at, L_8005B08C
    if (ctx->r12 != ctx->r1) {
        // 0x8005B074: nop
    
            goto L_8005B08C;
    }
    // 0x8005B074: nop

    // 0x8005B078: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8005B07C: lbu         $t5, 0x174($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X174);
    // 0x8005B080: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005B084: beq         $t5, $at, L_8005B0A4
    if (ctx->r13 == ctx->r1) {
        // 0x8005B088: nop
    
            goto L_8005B0A4;
    }
    // 0x8005B088: nop

L_8005B08C:
    // 0x8005B08C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8005B090: lh          $t1, 0x164($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X164);
    // 0x8005B094: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x8005B098: nop

    // 0x8005B09C: beq         $t1, $t9, L_8005B0D8
    if (ctx->r9 == ctx->r25) {
        // 0x8005B0A0: nop
    
            goto L_8005B0D8;
    }
    // 0x8005B0A0: nop

L_8005B0A4:
    // 0x8005B0A4: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005B0A8: lui         $t8, 0xFC11
    ctx->r24 = S32(0XFC11 << 16);
    // 0x8005B0AC: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    // 0x8005B0B0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005B0B4: ori         $t8, $t8, 0x9623
    ctx->r24 = ctx->r24 | 0X9623;
    // 0x8005B0B8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005B0BC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005B0C0: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x8005B0C4: lui         $t4, 0xFF2F
    ctx->r12 = S32(0XFF2F << 16);
    // 0x8005B0C8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8005B0CC: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x8005B0D0: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x8005B0D4: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
L_8005B0D8:
    // 0x8005B0D8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005B0DC: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8005B0E0: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x8005B0E4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005B0E8: nop

    // 0x8005B0EC: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x8005B0F0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005B0F4: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8005B0F8: nop

    // 0x8005B0FC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8005B100: lw          $t5, 0x110($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X110);
    // 0x8005B104: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
    // 0x8005B108: lw          $t6, 0x114($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X114);
    // 0x8005B10C: andi        $t1, $t5, 0xFF
    ctx->r9 = ctx->r13 & 0XFF;
    // 0x8005B110: andi        $t3, $t8, 0xFF
    ctx->r11 = ctx->r24 & 0XFF;
    // 0x8005B114: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x8005B118: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8005B11C: lw          $t5, 0x118($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X118);
    // 0x8005B120: or          $t2, $t4, $t9
    ctx->r10 = ctx->r12 | ctx->r25;
    // 0x8005B124: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8005B128: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8005B12C: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8005B130: or          $t3, $t2, $t8
    ctx->r11 = ctx->r10 | ctx->r24;
    // 0x8005B134: andi        $t1, $t5, 0xFF
    ctx->r9 = ctx->r13 & 0XFF;
    // 0x8005B138: or          $t4, $t3, $t1
    ctx->r12 = ctx->r11 | ctx->r9;
    // 0x8005B13C: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
L_8005B140:
    // 0x8005B140: lw          $t6, 0x10C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10C);
    // 0x8005B144: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005B148: lw          $t7, 0x110($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X110);
    // 0x8005B14C: sb          $t6, 0x168($at)
    MEM_B(0X168, ctx->r1) = ctx->r14;
    // 0x8005B150: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005B154: lw          $t2, 0x114($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X114);
    // 0x8005B158: sb          $t7, 0x16C($at)
    MEM_B(0X16C, ctx->r1) = ctx->r15;
    // 0x8005B15C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005B160: lw          $t8, 0x118($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X118);
    // 0x8005B164: sb          $t2, 0x170($at)
    MEM_B(0X170, ctx->r1) = ctx->r10;
    // 0x8005B168: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005B16C: sb          $t8, 0x174($at)
    MEM_B(0X174, ctx->r1) = ctx->r24;
L_8005B170:
    // 0x8005B170: lw          $t5, 0xDC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XDC);
    // 0x8005B174: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005B178: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8005B17C: beq         $t0, $zero, L_8005B1A8
    if (ctx->r8 == 0) {
        // 0x8005B180: sh          $t5, 0x164($at)
        MEM_H(0X164, ctx->r1) = ctx->r13;
            goto L_8005B1A8;
    }
    // 0x8005B180: sh          $t5, 0x164($at)
    MEM_H(0X164, ctx->r1) = ctx->r13;
    // 0x8005B184: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B188: beq         $t0, $at, L_8005B3D8
    if (ctx->r8 == ctx->r1) {
        // 0x8005B18C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005B3D8;
    }
    // 0x8005B18C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005B190: beq         $t0, $at, L_8005B61C
    if (ctx->r8 == ctx->r1) {
        // 0x8005B194: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005B61C;
    }
    // 0x8005B194: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005B198: beq         $t0, $at, L_8005B844
    if (ctx->r8 == ctx->r1) {
        // 0x8005B19C: nop
    
            goto L_8005B844;
    }
    // 0x8005B19C: nop

    // 0x8005B1A0: b           L_8005BA68
    // 0x8005B1A4: nop

        goto L_8005BA68;
    // 0x8005B1A4: nop

L_8005B1A8:
    // 0x8005B1A8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005B1AC: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x8005B1B0: sw          $t3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r11;
    // 0x8005B1B4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005B1B8: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
    // 0x8005B1BC: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x8005B1C0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005B1C4: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x8005B1C8: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8005B1CC: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8005B1D0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8005B1D4: or          $t2, $t7, $at
    ctx->r10 = ctx->r15 | ctx->r1;
    // 0x8005B1D8: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8005B1DC: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x8005B1E0: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8005B1E4: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8005B1E8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005B1EC: nop

    // 0x8005B1F0: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x8005B1F4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005B1F8: nop

    // 0x8005B1FC: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x8005B200: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005B204: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B208: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8005B20C: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x8005B210: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x8005B214: addiu       $t8, $t2, 0xB
    ctx->r24 = ADD32(ctx->r10, 0XB);
    // 0x8005B218: sra         $t5, $t8, 3
    ctx->r13 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8005B21C: andi        $t3, $t5, 0x1FF
    ctx->r11 = ctx->r13 & 0X1FF;
    // 0x8005B220: sll         $t1, $t3, 9
    ctx->r9 = S32(ctx->r11 << 9);
    // 0x8005B224: or          $t4, $t1, $at
    ctx->r12 = ctx->r9 | ctx->r1;
    // 0x8005B228: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x8005B22C: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x8005B230: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x8005B234: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8005B238: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8005B23C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005B240: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x8005B244: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x8005B248: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005B24C: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x8005B250: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x8005B254: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005B258: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8005B25C: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x8005B260: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8005B264: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8005B268: sll         $t5, $t8, 12
    ctx->r13 = S32(ctx->r24 << 12);
    // 0x8005B26C: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8005B270: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005B274: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005B278: sw          $t9, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r25;
    // 0x8005B27C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005B280: or          $t3, $t5, $at
    ctx->r11 = ctx->r13 | ctx->r1;
    // 0x8005B284: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005B288: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005B28C: lw          $t1, 0xF8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF8);
    // 0x8005B290: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8005B294: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8005B298: andi        $t9, $t4, 0xFFF
    ctx->r25 = ctx->r12 & 0XFFF;
    // 0x8005B29C: or          $t6, $t3, $t9
    ctx->r14 = ctx->r11 | ctx->r25;
    // 0x8005B2A0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8005B2A4: lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B2A8: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x8005B2AC: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8005B2B0: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8005B2B4: andi        $t1, $t5, 0xFFF
    ctx->r9 = ctx->r13 & 0XFFF;
    // 0x8005B2B8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8005B2BC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005B2C0: sll         $t4, $t1, 12
    ctx->r12 = S32(ctx->r9 << 12);
    // 0x8005B2C4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005B2C8: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8005B2CC: or          $t3, $t4, $at
    ctx->r11 = ctx->r12 | ctx->r1;
    // 0x8005B2D0: andi        $t2, $t7, 0xFFF
    ctx->r10 = ctx->r15 & 0XFFF;
    // 0x8005B2D4: or          $t8, $t3, $t2
    ctx->r24 = ctx->r11 | ctx->r10;
    // 0x8005B2D8: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x8005B2DC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005B2E0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005B2E4: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x8005B2E8: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005B2EC: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8005B2F0: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x8005B2F4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005B2F8: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8005B2FC: nop

    // 0x8005B300: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8005B304: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8005B308: nop

    // 0x8005B30C: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005B310: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005B314: nop

    // 0x8005B318: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x8005B31C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005B320: nop

    // 0x8005B324: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x8005B328: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005B32C: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B330: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8005B334: subu        $t4, $t1, $a3
    ctx->r12 = SUB32(ctx->r9, ctx->r7);
    // 0x8005B338: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x8005B33C: addiu       $t6, $t9, 0xB
    ctx->r14 = ADD32(ctx->r25, 0XB);
    // 0x8005B340: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8005B344: andi        $t3, $t7, 0x1FF
    ctx->r11 = ctx->r15 & 0X1FF;
    // 0x8005B348: sll         $t2, $t3, 9
    ctx->r10 = S32(ctx->r11 << 9);
    // 0x8005B34C: or          $t8, $t2, $at
    ctx->r24 = ctx->r10 | ctx->r1;
    // 0x8005B350: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x8005B354: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8005B358: lui         $t1, 0x8
    ctx->r9 = S32(0X8 << 16);
    // 0x8005B35C: ori         $t1, $t1, 0x200
    ctx->r9 = ctx->r9 | 0X200;
    // 0x8005B360: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x8005B364: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005B368: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x8005B36C: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x8005B370: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005B374: andi        $t2, $t3, 0xFFF
    ctx->r10 = ctx->r11 & 0XFFF;
    // 0x8005B378: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005B37C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005B380: lw          $t1, 0xF8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF8);
    // 0x8005B384: sll         $t8, $t2, 12
    ctx->r24 = S32(ctx->r10 << 12);
    // 0x8005B388: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005B38C: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8005B390: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8005B394: andi        $t9, $t4, 0xFFF
    ctx->r25 = ctx->r12 & 0XFFF;
    // 0x8005B398: or          $t5, $t8, $at
    ctx->r13 = ctx->r24 | ctx->r1;
    // 0x8005B39C: or          $t6, $t5, $t9
    ctx->r14 = ctx->r13 | ctx->r25;
    // 0x8005B3A0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8005B3A4: lw          $t3, 0xFC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B3A8: lw          $t5, 0x100($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X100);
    // 0x8005B3AC: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x8005B3B0: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8005B3B4: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x8005B3B8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8005B3BC: andi        $t1, $t8, 0xFFF
    ctx->r9 = ctx->r24 & 0XFFF;
    // 0x8005B3C0: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8005B3C4: sll         $t4, $t1, 12
    ctx->r12 = S32(ctx->r9 << 12);
    // 0x8005B3C8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8005B3CC: or          $t3, $t4, $t7
    ctx->r11 = ctx->r12 | ctx->r15;
    // 0x8005B3D0: b           L_8005BA68
    // 0x8005B3D4: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
        goto L_8005BA68;
    // 0x8005B3D4: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
L_8005B3D8:
    // 0x8005B3D8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005B3DC: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x8005B3E0: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8005B3E4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005B3E8: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x8005B3EC: addiu       $t5, $t1, 0x8
    ctx->r13 = ADD32(ctx->r9, 0X8);
    // 0x8005B3F0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005B3F4: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x8005B3F8: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8005B3FC: sra         $t6, $t9, 1
    ctx->r14 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8005B400: addiu       $t4, $t6, -0x1
    ctx->r12 = ADD32(ctx->r14, -0X1);
    // 0x8005B404: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x8005B408: or          $t3, $t7, $at
    ctx->r11 = ctx->r15 | ctx->r1;
    // 0x8005B40C: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x8005B410: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8005B414: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8005B418: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8005B41C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005B420: nop

    // 0x8005B424: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x8005B428: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005B42C: nop

    // 0x8005B430: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8005B434: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005B438: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B43C: nop

    // 0x8005B440: subu        $t7, $t4, $a3
    ctx->r15 = SUB32(ctx->r12, ctx->r7);
    // 0x8005B444: addiu       $t3, $t7, 0x2
    ctx->r11 = ADD32(ctx->r15, 0X2);
    // 0x8005B448: sra         $t2, $t3, 1
    ctx->r10 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8005B44C: addiu       $t8, $t2, 0x7
    ctx->r24 = ADD32(ctx->r10, 0X7);
    // 0x8005B450: sra         $t1, $t8, 3
    ctx->r9 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8005B454: andi        $t5, $t1, 0x1FF
    ctx->r13 = ctx->r9 & 0X1FF;
    // 0x8005B458: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8005B45C: sll         $t9, $t5, 9
    ctx->r25 = S32(ctx->r13 << 9);
    // 0x8005B460: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8005B464: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8005B468: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8005B46C: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x8005B470: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8005B474: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8005B478: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005B47C: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x8005B480: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x8005B484: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005B488: sll         $t2, $a3, 1
    ctx->r10 = S32(ctx->r7 << 1);
    // 0x8005B48C: addiu       $t1, $t8, 0x8
    ctx->r9 = ADD32(ctx->r24, 0X8);
    // 0x8005B490: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005B494: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8005B498: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x8005B49C: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x8005B4A0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8005B4A4: sll         $t1, $t8, 12
    ctx->r9 = S32(ctx->r24 << 12);
    // 0x8005B4A8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8005B4AC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005B4B0: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005B4B4: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x8005B4B8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005B4BC: or          $t5, $t1, $at
    ctx->r13 = ctx->r9 | ctx->r1;
    // 0x8005B4C0: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x8005B4C4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005B4C8: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8005B4CC: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8005B4D0: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8005B4D4: andi        $t4, $t6, 0xFFF
    ctx->r12 = ctx->r14 & 0XFFF;
    // 0x8005B4D8: or          $t7, $t5, $t4
    ctx->r15 = ctx->r13 | ctx->r12;
    // 0x8005B4DC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8005B4E0: lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B4E4: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x8005B4E8: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8005B4EC: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x8005B4F0: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x8005B4F4: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x8005B4F8: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8005B4FC: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8005B500: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005B504: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8005B508: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x8005B50C: andi        $t2, $t3, 0xFFF
    ctx->r10 = ctx->r11 & 0XFFF;
    // 0x8005B510: or          $t8, $t5, $t2
    ctx->r24 = ctx->r13 | ctx->r10;
    // 0x8005B514: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8005B518: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005B51C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8005B520: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8005B524: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005B528: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8005B52C: addiu       $t4, $t6, 0x8
    ctx->r12 = ADD32(ctx->r14, 0X8);
    // 0x8005B530: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005B534: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8005B538: nop

    // 0x8005B53C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8005B540: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8005B544: nop

    // 0x8005B548: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8005B54C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005B550: nop

    // 0x8005B554: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8005B558: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005B55C: nop

    // 0x8005B560: addiu       $t1, $t8, 0x8
    ctx->r9 = ADD32(ctx->r24, 0X8);
    // 0x8005B564: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005B568: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B56C: nop

    // 0x8005B570: subu        $t6, $t9, $a3
    ctx->r14 = SUB32(ctx->r25, ctx->r7);
    // 0x8005B574: addiu       $t4, $t6, 0x2
    ctx->r12 = ADD32(ctx->r14, 0X2);
    // 0x8005B578: sra         $t7, $t4, 1
    ctx->r15 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8005B57C: addiu       $t3, $t7, 0x7
    ctx->r11 = ADD32(ctx->r15, 0X7);
    // 0x8005B580: sra         $t5, $t3, 3
    ctx->r13 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8005B584: andi        $t2, $t5, 0x1FF
    ctx->r10 = ctx->r13 & 0X1FF;
    // 0x8005B588: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8005B58C: sll         $t8, $t2, 9
    ctx->r24 = S32(ctx->r10 << 9);
    // 0x8005B590: or          $t1, $t8, $at
    ctx->r9 = ctx->r24 | ctx->r1;
    // 0x8005B594: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8005B598: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8005B59C: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x8005B5A0: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8005B5A4: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8005B5A8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005B5AC: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x8005B5B0: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8005B5B4: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005B5B8: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x8005B5BC: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x8005B5C0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005B5C4: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
    // 0x8005B5C8: sll         $t1, $t8, 12
    ctx->r9 = S32(ctx->r24 << 12);
    // 0x8005B5CC: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005B5D0: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x8005B5D4: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8005B5D8: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x8005B5DC: or          $t9, $t1, $at
    ctx->r25 = ctx->r9 | ctx->r1;
    // 0x8005B5E0: or          $t3, $t9, $t7
    ctx->r11 = ctx->r25 | ctx->r15;
    // 0x8005B5E4: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x8005B5E8: lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B5EC: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x8005B5F0: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8005B5F4: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8005B5F8: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005B5FC: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8005B600: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x8005B604: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8005B608: sll         $t4, $t6, 12
    ctx->r12 = S32(ctx->r14 << 12);
    // 0x8005B60C: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x8005B610: or          $t2, $t4, $t5
    ctx->r10 = ctx->r12 | ctx->r13;
    // 0x8005B614: b           L_8005BA68
    // 0x8005B618: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
        goto L_8005BA68;
    // 0x8005B618: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
L_8005B61C:
    // 0x8005B61C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005B620: lui         $at, 0xFD68
    ctx->r1 = S32(0XFD68 << 16);
    // 0x8005B624: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x8005B628: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005B62C: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x8005B630: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8005B634: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005B638: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x8005B63C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8005B640: addiu       $t3, $t7, -0x1
    ctx->r11 = ADD32(ctx->r15, -0X1);
    // 0x8005B644: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x8005B648: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8005B64C: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x8005B650: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8005B654: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8005B658: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8005B65C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005B660: nop

    // 0x8005B664: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8005B668: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005B66C: nop

    // 0x8005B670: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8005B674: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005B678: lw          $t3, 0xFC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B67C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8005B680: subu        $t4, $t3, $a3
    ctx->r12 = SUB32(ctx->r11, ctx->r7);
    // 0x8005B684: addiu       $t5, $t4, 0x9
    ctx->r13 = ADD32(ctx->r12, 0X9);
    // 0x8005B688: sra         $t2, $t5, 3
    ctx->r10 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8005B68C: andi        $t8, $t2, 0x1FF
    ctx->r24 = ctx->r10 & 0X1FF;
    // 0x8005B690: sll         $t1, $t8, 9
    ctx->r9 = S32(ctx->r24 << 9);
    // 0x8005B694: or          $t6, $t1, $at
    ctx->r14 = ctx->r9 | ctx->r1;
    // 0x8005B698: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8005B69C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8005B6A0: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x8005B6A4: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8005B6A8: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8005B6AC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005B6B0: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8005B6B4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x8005B6B8: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005B6BC: sll         $t4, $a3, 2
    ctx->r12 = S32(ctx->r7 << 2);
    // 0x8005B6C0: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x8005B6C4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005B6C8: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8005B6CC: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x8005B6D0: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005B6D4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8005B6D8: sll         $t2, $t5, 12
    ctx->r10 = S32(ctx->r13 << 12);
    // 0x8005B6DC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8005B6E0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005B6E4: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005B6E8: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8005B6EC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005B6F0: or          $t8, $t2, $at
    ctx->r24 = ctx->r10 | ctx->r1;
    // 0x8005B6F4: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x8005B6F8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005B6FC: lw          $t1, 0xF8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF8);
    // 0x8005B700: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8005B704: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8005B708: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8005B70C: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8005B710: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8005B714: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B718: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x8005B71C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8005B720: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x8005B724: andi        $t1, $t2, 0xFFF
    ctx->r9 = ctx->r10 & 0XFFF;
    // 0x8005B728: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005B72C: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8005B730: sll         $t6, $t1, 12
    ctx->r14 = S32(ctx->r9 << 12);
    // 0x8005B734: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005B738: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8005B73C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8005B740: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x8005B744: or          $t5, $t8, $t4
    ctx->r13 = ctx->r24 | ctx->r12;
    // 0x8005B748: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8005B74C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005B750: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8005B754: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8005B758: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005B75C: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8005B760: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8005B764: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005B768: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B76C: nop

    // 0x8005B770: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8005B774: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B778: nop

    // 0x8005B77C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8005B780: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005B784: nop

    // 0x8005B788: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8005B78C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005B790: nop

    // 0x8005B794: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x8005B798: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005B79C: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B7A0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8005B7A4: subu        $t6, $t1, $a3
    ctx->r14 = SUB32(ctx->r9, ctx->r7);
    // 0x8005B7A8: addiu       $t9, $t6, 0x9
    ctx->r25 = ADD32(ctx->r14, 0X9);
    // 0x8005B7AC: sra         $t7, $t9, 3
    ctx->r15 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8005B7B0: andi        $t3, $t7, 0x1FF
    ctx->r11 = ctx->r15 & 0X1FF;
    // 0x8005B7B4: sll         $t8, $t3, 9
    ctx->r24 = S32(ctx->r11 << 9);
    // 0x8005B7B8: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x8005B7BC: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8005B7C0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005B7C4: lui         $t2, 0x8
    ctx->r10 = S32(0X8 << 16);
    // 0x8005B7C8: ori         $t2, $t2, 0x200
    ctx->r10 = ctx->r10 | 0X200;
    // 0x8005B7CC: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x8005B7D0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005B7D4: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x8005B7D8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8005B7DC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005B7E0: andi        $t8, $t3, 0xFFF
    ctx->r24 = ctx->r11 & 0XFFF;
    // 0x8005B7E4: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8005B7E8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005B7EC: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x8005B7F0: sll         $t4, $t8, 12
    ctx->r12 = S32(ctx->r24 << 12);
    // 0x8005B7F4: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005B7F8: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x8005B7FC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005B800: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x8005B804: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8005B808: or          $t9, $t5, $t6
    ctx->r25 = ctx->r13 | ctx->r14;
    // 0x8005B80C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8005B810: lw          $t3, 0xFC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B814: lw          $t5, 0x100($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X100);
    // 0x8005B818: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x8005B81C: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8005B820: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8005B824: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8005B828: andi        $t2, $t4, 0xFFF
    ctx->r10 = ctx->r12 & 0XFFF;
    // 0x8005B82C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005B830: sll         $t1, $t2, 12
    ctx->r9 = S32(ctx->r10 << 12);
    // 0x8005B834: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8005B838: or          $t3, $t1, $t7
    ctx->r11 = ctx->r9 | ctx->r15;
    // 0x8005B83C: b           L_8005BA68
    // 0x8005B840: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
        goto L_8005BA68;
    // 0x8005B840: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
L_8005B844:
    // 0x8005B844: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005B848: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x8005B84C: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8005B850: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005B854: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x8005B858: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x8005B85C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005B860: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8005B864: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005B868: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x8005B86C: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x8005B870: or          $t7, $t1, $at
    ctx->r15 = ctx->r9 | ctx->r1;
    // 0x8005B874: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8005B878: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8005B87C: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005B880: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x8005B884: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005B888: nop

    // 0x8005B88C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8005B890: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005B894: nop

    // 0x8005B898: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8005B89C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005B8A0: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B8A4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B8A8: subu        $t1, $t9, $a3
    ctx->r9 = SUB32(ctx->r25, ctx->r7);
    // 0x8005B8AC: addiu       $t7, $t1, 0x9
    ctx->r15 = ADD32(ctx->r9, 0X9);
    // 0x8005B8B0: sra         $t3, $t7, 3
    ctx->r11 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8005B8B4: andi        $t8, $t3, 0x1FF
    ctx->r24 = ctx->r11 & 0X1FF;
    // 0x8005B8B8: sll         $t4, $t8, 9
    ctx->r12 = S32(ctx->r24 << 9);
    // 0x8005B8BC: or          $t2, $t4, $at
    ctx->r10 = ctx->r12 | ctx->r1;
    // 0x8005B8C0: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x8005B8C4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B8C8: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x8005B8CC: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8005B8D0: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8005B8D4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005B8D8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8005B8DC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8005B8E0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005B8E4: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x8005B8E8: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x8005B8EC: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005B8F0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8005B8F4: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x8005B8F8: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8005B8FC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8005B900: sll         $t3, $t7, 12
    ctx->r11 = S32(ctx->r15 << 12);
    // 0x8005B904: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8005B908: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005B90C: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005B910: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8005B914: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005B918: or          $t8, $t3, $at
    ctx->r24 = ctx->r11 | ctx->r1;
    // 0x8005B91C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8005B920: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005B924: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x8005B928: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8005B92C: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8005B930: andi        $t5, $t2, 0xFFF
    ctx->r13 = ctx->r10 & 0XFFF;
    // 0x8005B934: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8005B938: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8005B93C: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B940: lw          $t5, 0x100($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X100);
    // 0x8005B944: addiu       $t7, $t1, 0x1
    ctx->r15 = ADD32(ctx->r9, 0X1);
    // 0x8005B948: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8005B94C: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x8005B950: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8005B954: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8005B958: sll         $t2, $t4, 12
    ctx->r10 = S32(ctx->r12 << 12);
    // 0x8005B95C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005B960: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8005B964: or          $t8, $t2, $at
    ctx->r24 = ctx->r10 | ctx->r1;
    // 0x8005B968: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x8005B96C: or          $t7, $t8, $t1
    ctx->r15 = ctx->r24 | ctx->r9;
    // 0x8005B970: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8005B974: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005B978: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005B97C: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8005B980: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005B984: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005B988: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x8005B98C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005B990: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8005B994: nop

    // 0x8005B998: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8005B99C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005B9A0: nop

    // 0x8005B9A4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8005B9A8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005B9AC: nop

    // 0x8005B9B0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8005B9B4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005B9B8: nop

    // 0x8005B9BC: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x8005B9C0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005B9C4: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x8005B9C8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B9CC: subu        $t2, $t4, $a3
    ctx->r10 = SUB32(ctx->r12, ctx->r7);
    // 0x8005B9D0: addiu       $t5, $t2, 0x9
    ctx->r13 = ADD32(ctx->r10, 0X9);
    // 0x8005B9D4: sra         $t6, $t5, 3
    ctx->r14 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8005B9D8: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8005B9DC: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x8005B9E0: or          $t1, $t8, $at
    ctx->r9 = ctx->r24 | ctx->r1;
    // 0x8005B9E4: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x8005B9E8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B9EC: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x8005B9F0: ori         $t3, $t3, 0x200
    ctx->r11 = ctx->r11 | 0X200;
    // 0x8005B9F4: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8005B9F8: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005B9FC: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8005BA00: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8005BA04: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005BA08: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8005BA0C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8005BA10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005BA14: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8005BA18: sll         $t1, $t8, 12
    ctx->r9 = S32(ctx->r24 << 12);
    // 0x8005BA1C: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005BA20: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005BA24: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8005BA28: andi        $t2, $t4, 0xFFF
    ctx->r10 = ctx->r12 & 0XFFF;
    // 0x8005BA2C: or          $t7, $t1, $at
    ctx->r15 = ctx->r9 | ctx->r1;
    // 0x8005BA30: or          $t5, $t7, $t2
    ctx->r13 = ctx->r15 | ctx->r10;
    // 0x8005BA34: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8005BA38: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x8005BA3C: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x8005BA40: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8005BA44: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8005BA48: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8005BA4C: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8005BA50: andi        $t3, $t1, 0xFFF
    ctx->r11 = ctx->r9 & 0XFFF;
    // 0x8005BA54: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8005BA58: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x8005BA5C: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x8005BA60: or          $t9, $t4, $t6
    ctx->r25 = ctx->r12 | ctx->r14;
    // 0x8005BA64: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
L_8005BA68:
    // 0x8005BA68: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005BA6C: lui         $t2, 0xF200
    ctx->r10 = S32(0XF200 << 16);
    // 0x8005BA70: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8005BA74: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005BA78: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8005BA7C: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x8005BA80: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005BA84: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x8005BA88: nop

    // 0x8005BA8C: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x8005BA90: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
    // 0x8005BA94: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x8005BA98: lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XFC);
    // 0x8005BA9C: subu        $t9, $t4, $t6
    ctx->r25 = SUB32(ctx->r12, ctx->r14);
    // 0x8005BAA0: subu        $t5, $t2, $a3
    ctx->r13 = SUB32(ctx->r10, ctx->r7);
    // 0x8005BAA4: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8005BAA8: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8005BAAC: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8005BAB0: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8005BAB4: addiu       $t9, $t6, 0x3
    ctx->r25 = ADD32(ctx->r14, 0X3);
    // 0x8005BAB8: addiu       $t3, $t1, 0x3
    ctx->r11 = ADD32(ctx->r9, 0X3);
    // 0x8005BABC: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8005BAC0: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8005BAC4: sll         $t1, $t8, 12
    ctx->r9 = S32(ctx->r24 << 12);
    // 0x8005BAC8: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x8005BACC: or          $t3, $t1, $t7
    ctx->r11 = ctx->r9 | ctx->r15;
    // 0x8005BAD0: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x8005BAD4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005BAD8: nop

    // 0x8005BADC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005BAE0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005BAE4: nop

    // 0x8005BAE8: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x8005BAEC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005BAF0: lw          $t9, 0x104($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X104);
    // 0x8005BAF4: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x8005BAF8: lw          $t5, 0x108($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X108);
    // 0x8005BAFC: lw          $t4, 0xD4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD4);
    // 0x8005BB00: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x8005BB04: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x8005BB08: sll         $t3, $t7, 12
    ctx->r11 = S32(ctx->r15 << 12);
    // 0x8005BB0C: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x8005BB10: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x8005BB14: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8005BB18: or          $t2, $t3, $at
    ctx->r10 = ctx->r11 | ctx->r1;
    // 0x8005BB1C: or          $t8, $t2, $t9
    ctx->r24 = ctx->r10 | ctx->r25;
    // 0x8005BB20: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005BB24: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x8005BB28: lw          $t4, 0x108($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X108);
    // 0x8005BB2C: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x8005BB30: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x8005BB34: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x8005BB38: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x8005BB3C: or          $t2, $t5, $t6
    ctx->r10 = ctx->r13 | ctx->r14;
    // 0x8005BB40: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x8005BB44: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005BB48: lui         $t3, 0xE100
    ctx->r11 = S32(0XE100 << 16);
    // 0x8005BB4C: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x8005BB50: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005BB54: lui         $t8, 0xF100
    ctx->r24 = S32(0XF100 << 16);
    // 0x8005BB58: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x8005BB5C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005BB60: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8005BB64: nop

    // 0x8005BB68: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8005BB6C: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8005BB70: nop

    // 0x8005BB74: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8005BB78: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005BB7C: nop

    // 0x8005BB80: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8005BB84: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005BB88: nop

    // 0x8005BB8C: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x8005BB90: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005BB94: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8005BB98: nop

    // 0x8005BB9C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005BBA0: lw          $t7, 0x11C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X11C);
    // 0x8005BBA4: lw          $t5, 0x120($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X120);
    // 0x8005BBA8: andi        $t3, $t7, 0xFFFF
    ctx->r11 = ctx->r15 & 0XFFFF;
    // 0x8005BBAC: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8005BBB0: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8005BBB4: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8005BBB8: or          $t2, $t4, $t6
    ctx->r10 = ctx->r12 | ctx->r14;
    // 0x8005BBBC: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x8005BBC0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005BBC4: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8005BBC8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8005BBCC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005BBD0: nop

    // 0x8005BBD4: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x8005BBD8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005BBDC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005BBE0: nop

    // 0x8005BBE4: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x8005BBE8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8005BBEC: nop

    // 0x8005BBF0: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
L_8005BBF4:
    // 0x8005BBF4: jr          $ra
    // 0x8005BBF8: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8005BBF8: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}

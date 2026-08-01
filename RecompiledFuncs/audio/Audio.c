#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Audio_InitAudio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084700: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80084704: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x80084708: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008470C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80084710: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80084714: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80084718: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8008471C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80084720: sh          $t6, -0x7228($at)
    MEM_H(-0X7228, ctx->r1) = ctx->r14;
    // 0x80084724: addiu       $t7, $t7, 0x6778
    ctx->r15 = ADD32(ctx->r15, 0X6778);
    // 0x80084728: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8008472C: lui         $t0, 0x8035
    ctx->r8 = S32(0X8035 << 16);
    // 0x80084730: sw          $at, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r1;
    // 0x80084734: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80084738: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8008473C: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80084740: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80084744: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80084748: sw          $at, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r1;
    // 0x8008474C: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x80084750: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80084754: addiu       $t0, $t0, -0x5300
    ctx->r8 = ADD32(ctx->r8, -0X5300);
    // 0x80084758: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008475C: lui         $t1, 0x4
    ctx->r9 = S32(0X4 << 16);
    // 0x80084760: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80084764: addiu       $a0, $a0, -0xED0
    ctx->r4 = ADD32(ctx->r4, -0XED0);
    // 0x80084768: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8008476C: jal         0x800B3BFC
    // 0x80084770: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80084770: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x80084774: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80084778: lui         $a1, 0x8035
    ctx->r5 = S32(0X8035 << 16);
    // 0x8008477C: addiu       $a1, $a1, -0x5300
    ctx->r5 = ADD32(ctx->r5, -0X5300);
    // 0x80084780: addiu       $a0, $a0, 0x6778
    ctx->r4 = ADD32(ctx->r4, 0X6778);
    // 0x80084784: jal         0x800B84F0
    // 0x80084788: lui         $a2, 0x4
    ctx->r6 = S32(0X4 << 16);
    alHeapInit(rdram, ctx);
        goto after_1;
    // 0x80084788: lui         $a2, 0x4
    ctx->r6 = S32(0X4 << 16);
    after_1:
    // 0x8008478C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084790: lui         $a1, 0x8035
    ctx->r5 = S32(0X8035 << 16);
    // 0x80084794: addiu       $a1, $a1, -0x5300
    ctx->r5 = ADD32(ctx->r5, -0X5300);
    // 0x80084798: jal         0x800B3BFC
    // 0x8008479C: addiu       $a0, $a0, -0xEC4
    ctx->r4 = ADD32(ctx->r4, -0XEC4);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8008479C: addiu       $a0, $a0, -0xEC4
    ctx->r4 = ADD32(ctx->r4, -0XEC4);
    after_2:
    // 0x800847A0: lui         $t2, 0x8035
    ctx->r10 = S32(0X8035 << 16);
    // 0x800847A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800847A8: addiu       $t2, $t2, -0x5300
    ctx->r10 = ADD32(ctx->r10, -0X5300);
    // 0x800847AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800847B0: addiu       $t3, $zero, 0x30
    ctx->r11 = ADD32(0, 0X30);
    // 0x800847B4: addiu       $t4, $zero, 0x60
    ctx->r12 = ADD32(0, 0X60);
    // 0x800847B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800847BC: addiu       $t6, $t6, 0x6778
    ctx->r14 = ADD32(ctx->r14, 0X6778);
    // 0x800847C0: ori         $t8, $zero, 0x8CA0
    ctx->r24 = 0 | 0X8CA0;
    // 0x800847C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800847C8: addiu       $t9, $zero, 0x1400
    ctx->r25 = ADD32(0, 0X1400);
    // 0x800847CC: sw          $t2, 0x6798($at)
    MEM_W(0X6798, ctx->r1) = ctx->r10;
    // 0x800847D0: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x800847D4: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x800847D8: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x800847DC: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x800847E0: sb          $t5, 0x78($sp)
    MEM_B(0X78, ctx->r29) = ctx->r13;
    // 0x800847E4: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x800847E8: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x800847EC: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800847F0: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800847F4: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x800847F8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800847FC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80084800: jal         0x80085430
    // 0x80084804: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    Audio_ALManager(rdram, ctx);
        goto after_3;
    // 0x80084804: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_3:
    // 0x80084808: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008480C: lw          $t0, 0x6798($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6798);
    // 0x80084810: lui         $t1, 0x8035
    ctx->r9 = S32(0X8035 << 16);
    // 0x80084814: addiu       $t1, $t1, -0x5300
    ctx->r9 = ADD32(ctx->r9, -0X5300);
    // 0x80084818: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008481C: addiu       $a0, $a0, -0xEB0
    ctx->r4 = ADD32(ctx->r4, -0XEB0);
    // 0x80084820: jal         0x800B3BFC
    // 0x80084824: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    rmonPrintf_recomp(rdram, ctx);
        goto after_4;
    // 0x80084824: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    after_4:
    // 0x80084828: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008482C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80084830: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80084834: addiu       $a2, $a2, 0x6778
    ctx->r6 = ADD32(ctx->r6, 0X6778);
    // 0x80084838: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008483C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084840: jal         0x800B8530
    // 0x80084844: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x80084844: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80084848: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008484C: sw          $v0, 0x6788($at)
    MEM_W(0X6788, ctx->r1) = ctx->r2;
    // 0x80084850: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80084854: lw          $t3, 0x6788($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6788);
    // 0x80084858: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008485C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80084860: lhu         $t4, -0x7228($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X7228);
    // 0x80084864: sw          $t3, 0x678C($at)
    MEM_W(0X678C, ctx->r1) = ctx->r11;
    // 0x80084868: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008486C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80084870: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084874: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80084878: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8008487C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80084880: addiu       $a2, $a2, 0x4678
    ctx->r6 = ADD32(ctx->r6, 0X4678);
    // 0x80084884: addiu       $a1, $a1, 0x3A18
    ctx->r5 = ADD32(ctx->r5, 0X3A18);
    // 0x80084888: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    // 0x8008488C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80084890: sw          $t3, 0x2000($at)
    MEM_W(0X2000, ctx->r1) = ctx->r11;
    // 0x80084894: jal         0x80085D50
    // 0x80084898: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    Dcm_Init(rdram, ctx);
        goto after_6;
    // 0x80084898: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_6:
    // 0x8008489C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800848A0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800848A4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800848A8: addiu       $t6, $zero, 0x7FFF
    ctx->r14 = ADD32(0, 0X7FFF);
    // 0x800848AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800848B0: addiu       $a2, $a2, 0x64B8
    ctx->r6 = ADD32(ctx->r6, 0X64B8);
    // 0x800848B4: addiu       $a1, $a1, 0x5858
    ctx->r5 = ADD32(ctx->r5, 0X5858);
    // 0x800848B8: addiu       $a0, $a0, 0x2010
    ctx->r4 = ADD32(ctx->r4, 0X2010);
    // 0x800848BC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800848C0: jal         0x80085D50
    // 0x800848C4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    Dcm_Init(rdram, ctx);
        goto after_7;
    // 0x800848C4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x800848C8: lui         $a0, 0xB
    ctx->r4 = S32(0XB << 16);
    // 0x800848CC: jal         0x8007E03C
    // 0x800848D0: ori         $a0, $a0, 0xCF20
    ctx->r4 = ctx->r4 | 0XCF20;
    n64HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x800848D0: ori         $a0, $a0, 0xCF20
    ctx->r4 = ctx->r4 | 0XCF20;
    after_8:
    // 0x800848D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800848D8: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x800848DC: sw          $v0, 0x2000($at)
    MEM_W(0X2000, ctx->r1) = ctx->r2;
    // 0x800848E0: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    // 0x800848E4: jal         0x80074888
    // 0x800848E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_9;
    // 0x800848E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x800848EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800848F0: jal         0x8007E03C
    // 0x800848F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_10;
    // 0x800848F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800848F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800848FC: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x80084900: sw          $v0, 0x6790($at)
    MEM_W(0X6790, ctx->r1) = ctx->r2;
    // 0x80084904: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    // 0x80084908: jal         0x80074888
    // 0x8008490C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_11;
    // 0x8008490C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80084910: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x80084914: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    // 0x80084918: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8008491C: jal         0x80074888
    // 0x80084920: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_12;
    // 0x80084920: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80084924: jal         0x8007E4A4
    // 0x80084928: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_13;
    // 0x80084928: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_13:
    // 0x8008492C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80084930: lw          $t8, 0x6790($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6790);
    // 0x80084934: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80084938: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008493C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80084940: addiu       $a1, $a1, -0xE60
    ctx->r5 = ADD32(ctx->r5, -0XE60);
    // 0x80084944: addiu       $a0, $a0, -0xE9C
    ctx->r4 = ADD32(ctx->r4, -0XE9C);
    // 0x80084948: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008494C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80084950: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80084954: jal         0x800B3BFC
    // 0x80084958: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    rmonPrintf_recomp(rdram, ctx);
        goto after_14;
    // 0x80084958: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_14:
    // 0x8008495C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084960: lw          $a1, 0x6790($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6790);
    // 0x80084964: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x80084968: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    // 0x8008496C: jal         0x800746C0
    // 0x80084970: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_15;
    // 0x80084970: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80084974: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084978: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008497C: lw          $a2, 0x6794($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6794);
    // 0x80084980: lw          $a1, 0x6790($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6790);
    // 0x80084984: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80084988: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    // 0x8008498C: jal         0x80086138
    // 0x80084990: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Audio2_InitSongPlayer(rdram, ctx);
        goto after_16;
    // 0x80084990: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_16:
    // 0x80084994: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084998: sw          $v0, 0x6788($at)
    MEM_W(0X6788, ctx->r1) = ctx->r2;
    // 0x8008499C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800849A0: sh          $zero, 0x1FF0($at)
    MEM_H(0X1FF0, ctx->r1) = 0;
    // 0x800849A4: sh          $zero, 0x1FF2($at)
    MEM_H(0X1FF2, ctx->r1) = 0;
    // 0x800849A8: sb          $zero, 0x1FF4($at)
    MEM_B(0X1FF4, ctx->r1) = 0;
    // 0x800849AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800849B0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800849B4: jal         0x8004A34C
    // 0x800849B8: sw          $t7, -0x7224($at)
    MEM_W(-0X7224, ctx->r1) = ctx->r15;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_17;
    // 0x800849B8: sw          $t7, -0x7224($at)
    MEM_W(-0X7224, ctx->r1) = ctx->r15;
    after_17:
    // 0x800849BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800849C0: lbu         $t9, 0x1FF4($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1FF4);
    // 0x800849C4: nop

    // 0x800849C8: bne         $t9, $zero, L_800849F0
    if (ctx->r25 != 0) {
        // 0x800849CC: nop
    
            goto L_800849F0;
    }
    // 0x800849CC: nop

L_800849D0:
    // 0x800849D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800849D4: jal         0x80085408
    // 0x800849D8: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    Audio_AllocDcmScratch8(rdram, ctx);
        goto after_18;
    // 0x800849D8: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    after_18:
    // 0x800849DC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800849E0: lbu         $t1, 0x1FF4($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1FF4);
    // 0x800849E4: nop

    // 0x800849E8: beq         $t1, $zero, L_800849D0
    if (ctx->r9 == 0) {
        // 0x800849EC: nop
    
            goto L_800849D0;
    }
    // 0x800849EC: nop

L_800849F0:
    // 0x800849F0: jal         0x8007E4A4
    // 0x800849F4: nop

    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_19;
    // 0x800849F4: nop

    after_19:
    // 0x800849F8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800849FC: lw          $a2, 0x6790($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6790);
    // 0x80084A00: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80084A04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084A08: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80084A0C: addiu       $a1, $a1, -0xE24
    ctx->r5 = ADD32(ctx->r5, -0XE24);
    // 0x80084A10: addiu       $a0, $a0, -0xE54
    ctx->r4 = ADD32(ctx->r4, -0XE54);
    // 0x80084A14: jal         0x800B3BFC
    // 0x80084A18: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_20;
    // 0x80084A18: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_20:
    // 0x80084A1C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80084A20: lw          $a0, 0x6790($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6790);
    // 0x80084A24: jal         0x8007E328
    // 0x80084A28: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_21;
    // 0x80084A28: nop

    after_21:
    // 0x80084A2C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80084A30: lw          $t0, 0x3990($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3990);
    // 0x80084A34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084A38: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80084A3C: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80084A40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084A44: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80084A48: sw          $t0, 0x6788($at)
    MEM_W(0X6788, ctx->r1) = ctx->r8;
    // 0x80084A4C: jal         0x80088C84
    // 0x80084A50: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    Audio2_InitSFXPlayer(rdram, ctx);
        goto after_22;
    // 0x80084A50: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    after_22:
    // 0x80084A54: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80084A58: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80084A5C: sw          $zero, -0x752C($at)
    MEM_W(-0X752C, ctx->r1) = 0;
    // 0x80084A60: jal         0x80085030
    // 0x80084A64: addiu       $a0, $a0, 0x3B28
    ctx->r4 = ADD32(ctx->r4, 0X3B28);
    Audio_LoadSFX(rdram, ctx);
        goto after_23;
    // 0x80084A64: addiu       $a0, $a0, 0x3B28
    ctx->r4 = ADD32(ctx->r4, 0X3B28);
    after_23:
    // 0x80084A68: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80084A6C: lw          $t2, 0x6788($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6788);
    // 0x80084A70: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80084A74: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084A78: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80084A7C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80084A80: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80084A84: addiu       $a0, $a0, -0xE18
    ctx->r4 = ADD32(ctx->r4, -0XE18);
    // 0x80084A88: jal         0x800B3BFC
    // 0x80084A8C: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_24;
    // 0x80084A8C: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    after_24:
    // 0x80084A90: jal         0x800B6650
    // 0x80084A94: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_25;
    // 0x80084A94: nop

    after_25:
    // 0x80084A98: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80084A9C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80084AA0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80084AA4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80084AA8: jr          $ra
    // 0x80084AAC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80084AAC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}

RECOMP_FUNC void Audio_ChangeSong(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AB0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80084AB4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80084AB8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80084ABC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80084AC0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80084AC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80084AC8: lw          $a2, -0x7224($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7224);
    // 0x80084ACC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80084AD0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084AD4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80084AD8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80084ADC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80084AE0: sh          $zero, -0x7240($at)
    MEM_H(-0X7240, ctx->r1) = 0;
    // 0x80084AE4: jal         0x800B3BFC
    // 0x80084AE8: addiu       $a0, $a0, -0xDFC
    ctx->r4 = ADD32(ctx->r4, -0XDFC);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80084AE8: addiu       $a0, $a0, -0xDFC
    ctx->r4 = ADD32(ctx->r4, -0XDFC);
    after_0:
    // 0x80084AEC: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x80084AF0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80084AF4: jal         0x80074888
    // 0x80084AF8: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_1;
    // 0x80084AF8: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    after_1:
    // 0x80084AFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80084B00: jal         0x8007E03C
    // 0x80084B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80084B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80084B08: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x80084B0C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80084B10: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80084B14: jal         0x80074888
    // 0x80084B18: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_3;
    // 0x80084B18: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    after_3:
    // 0x80084B1C: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x80084B20: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80084B24: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    // 0x80084B28: jal         0x80074888
    // 0x80084B2C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_4;
    // 0x80084B2C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_4:
    // 0x80084B30: jal         0x8007E4A4
    // 0x80084B34: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_5;
    // 0x80084B34: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_5:
    // 0x80084B38: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80084B3C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80084B40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084B44: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80084B48: addiu       $a1, $a1, -0xD9C
    ctx->r5 = ADD32(ctx->r5, -0XD9C);
    // 0x80084B4C: addiu       $a0, $a0, -0xDD8
    ctx->r4 = ADD32(ctx->r4, -0XDD8);
    // 0x80084B50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80084B54: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80084B58: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80084B5C: jal         0x800B3BFC
    // 0x80084B60: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    rmonPrintf_recomp(rdram, ctx);
        goto after_6;
    // 0x80084B60: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_6:
    // 0x80084B64: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x80084B68: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80084B6C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80084B70: jal         0x800746C0
    // 0x80084B74: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_7;
    // 0x80084B74: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    after_7:
    // 0x80084B78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80084B7C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80084B80: jal         0x80085F8C
    // 0x80084B84: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    Audio2_AllocDcmHeader(rdram, ctx);
        goto after_8;
    // 0x80084B84: addiu       $a0, $a0, 0xA70
    ctx->r4 = ADD32(ctx->r4, 0XA70);
    after_8:
    // 0x80084B88: jal         0x8007E4A4
    // 0x80084B8C: nop

    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_9;
    // 0x80084B8C: nop

    after_9:
    // 0x80084B90: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80084B94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084B98: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80084B9C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80084BA0: addiu       $a1, $a1, -0xD5C
    ctx->r5 = ADD32(ctx->r5, -0XD5C);
    // 0x80084BA4: addiu       $a0, $a0, -0xD8C
    ctx->r4 = ADD32(ctx->r4, -0XD8C);
    // 0x80084BA8: jal         0x800B3BFC
    // 0x80084BAC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_10;
    // 0x80084BAC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_10:
    // 0x80084BB0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80084BB4: jal         0x8007E328
    // 0x80084BB8: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_11;
    // 0x80084BB8: nop

    after_11:
    // 0x80084BBC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80084BC0: nop

    // 0x80084BC4: lw          $t8, 0x444($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X444);
    // 0x80084BC8: nop

    // 0x80084BCC: beq         $t8, $zero, L_80084C20
    if (ctx->r24 == 0) {
        // 0x80084BD0: nop
    
            goto L_80084C20;
    }
    // 0x80084BD0: nop

    // 0x80084BD4: jal         0x8007E4A4
    // 0x80084BD8: nop

    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_12;
    // 0x80084BD8: nop

    after_12:
    // 0x80084BDC: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80084BE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80084BE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084BE8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80084BEC: lw          $a2, 0x444($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X444);
    // 0x80084BF0: addiu       $a1, $a1, -0xD1C
    ctx->r5 = ADD32(ctx->r5, -0XD1C);
    // 0x80084BF4: addiu       $a0, $a0, -0xD4C
    ctx->r4 = ADD32(ctx->r4, -0XD4C);
    // 0x80084BF8: jal         0x800B3BFC
    // 0x80084BFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_13;
    // 0x80084BFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_13:
    // 0x80084C00: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80084C04: nop

    // 0x80084C08: lw          $a0, 0x444($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X444);
    // 0x80084C0C: jal         0x8007E328
    // 0x80084C10: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_14;
    // 0x80084C10: nop

    after_14:
    // 0x80084C14: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80084C18: nop

    // 0x80084C1C: sw          $zero, 0x444($t1)
    MEM_W(0X444, ctx->r9) = 0;
L_80084C20:
    // 0x80084C20: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80084C24: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80084C28: lw          $t3, 0x44C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X44C);
    // 0x80084C2C: nop

    // 0x80084C30: sw          $t3, 0x444($t2)
    MEM_W(0X444, ctx->r10) = ctx->r11;
    // 0x80084C34: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80084C38: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80084C3C: nop

    // 0x80084C40: sh          $t4, 0x1580($t5)
    MEM_H(0X1580, ctx->r13) = ctx->r12;
    // 0x80084C44: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80084C48: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80084C4C: nop

    // 0x80084C50: sh          $t6, 0x1582($t7)
    MEM_H(0X1582, ctx->r15) = ctx->r14;
    // 0x80084C54: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80084C58: nop

    // 0x80084C5C: sb          $t8, 0x1584($t9)
    MEM_B(0X1584, ctx->r25) = ctx->r24;
    // 0x80084C60: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80084C64: jal         0x8008777C
    // 0x80084C68: nop

    Audio2_ClearBusyFlag(rdram, ctx);
        goto after_15;
    // 0x80084C68: nop

    after_15:
    // 0x80084C6C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80084C70: jal         0x80087784
    // 0x80084C74: nop

    Audio2_GFXDone_SendPlayMessage(rdram, ctx);
        goto after_16;
    // 0x80084C74: nop

    after_16:
    // 0x80084C78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80084C7C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80084C80: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80084C84: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80084C88: jr          $ra
    // 0x80084C8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80084C8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void Audio_SetSongId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C90: jr          $ra
    // 0x80084C94: sh          $a0, 0x1582($a1)
    MEM_H(0X1582, ctx->r5) = ctx->r4;
    return;
    // 0x80084C94: sh          $a0, 0x1582($a1)
    MEM_H(0X1582, ctx->r5) = ctx->r4;
;}

RECOMP_FUNC void Audio_FreeAudio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80084C9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80084CA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80084CA4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80084CA8: jal         0x8008780C
    // 0x80084CAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    Audio2_GFXDone_SendSyncMessage(rdram, ctx);
        goto after_0;
    // 0x80084CAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80084CB0: jal         0x8004A34C
    // 0x80084CB4: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_1;
    // 0x80084CB4: nop

    after_1:
    // 0x80084CB8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80084CBC: nop

    // 0x80084CC0: lw          $t7, 0x444($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X444);
    // 0x80084CC4: nop

    // 0x80084CC8: beq         $t7, $zero, L_80084D1C
    if (ctx->r15 == 0) {
        // 0x80084CCC: nop
    
            goto L_80084D1C;
    }
    // 0x80084CCC: nop

    // 0x80084CD0: jal         0x8007E4A4
    // 0x80084CD4: nop

    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_2;
    // 0x80084CD4: nop

    after_2:
    // 0x80084CD8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80084CDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80084CE0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084CE4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80084CE8: lw          $a2, 0x444($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X444);
    // 0x80084CEC: addiu       $a1, $a1, -0xCDC
    ctx->r5 = ADD32(ctx->r5, -0XCDC);
    // 0x80084CF0: addiu       $a0, $a0, -0xD0C
    ctx->r4 = ADD32(ctx->r4, -0XD0C);
    // 0x80084CF4: jal         0x800B3BFC
    // 0x80084CF8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x80084CF8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x80084CFC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80084D00: nop

    // 0x80084D04: lw          $a0, 0x444($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X444);
    // 0x80084D08: jal         0x8007E328
    // 0x80084D0C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_4;
    // 0x80084D0C: nop

    after_4:
    // 0x80084D10: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80084D14: nop

    // 0x80084D18: sw          $zero, 0x444($t0)
    MEM_W(0X444, ctx->r8) = 0;
L_80084D1C:
    // 0x80084D1C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80084D20: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80084D24: lbu         $t2, 0x41D($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X41D);
    // 0x80084D28: nop

    // 0x80084D2C: blez        $t2, L_80084E10
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80084D30: nop
    
            goto L_80084E10;
    }
    // 0x80084D30: nop

L_80084D34:
    // 0x80084D34: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80084D38: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80084D3C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80084D40: lw          $t4, 0x438($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X438);
    // 0x80084D44: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80084D48: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80084D4C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80084D50: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80084D54: nop

    // 0x80084D58: beq         $t8, $zero, L_80084DEC
    if (ctx->r24 == 0) {
        // 0x80084D5C: nop
    
            goto L_80084DEC;
    }
    // 0x80084D5C: nop

    // 0x80084D60: jal         0x8007E4A4
    // 0x80084D64: nop

    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_5;
    // 0x80084D64: nop

    after_5:
    // 0x80084D68: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80084D6C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80084D70: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80084D74: lw          $t0, 0x438($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X438);
    // 0x80084D78: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80084D7C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80084D80: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80084D84: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x80084D88: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80084D8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084D90: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80084D94: addiu       $a1, $a1, -0xC90
    ctx->r5 = ADD32(ctx->r5, -0XC90);
    // 0x80084D98: addiu       $a0, $a0, -0xCC0
    ctx->r4 = ADD32(ctx->r4, -0XCC0);
    // 0x80084D9C: jal         0x800B3BFC
    // 0x80084DA0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_6;
    // 0x80084DA0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x80084DA4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80084DA8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80084DAC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80084DB0: lw          $t4, 0x438($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X438);
    // 0x80084DB4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80084DB8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80084DBC: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x80084DC0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80084DC4: jal         0x8007E328
    // 0x80084DC8: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_7;
    // 0x80084DC8: nop

    after_7:
    // 0x80084DCC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80084DD0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80084DD4: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80084DD8: lw          $t1, 0x438($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X438);
    // 0x80084DDC: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80084DE0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80084DE4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80084DE8: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_80084DEC:
    // 0x80084DEC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80084DF0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80084DF4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80084DF8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80084DFC: lbu         $t7, 0x41D($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X41D);
    // 0x80084E00: nop

    // 0x80084E04: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80084E08: bne         $at, $zero, L_80084D34
    if (ctx->r1 != 0) {
        // 0x80084E0C: nop
    
            goto L_80084D34;
    }
    // 0x80084E0C: nop

L_80084E10:
    // 0x80084E10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80084E14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80084E18: jr          $ra
    // 0x80084E1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80084E1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Audio_StartSong(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80084E24: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80084E28: lbu         $t6, -0x118($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X118);
    // 0x80084E2C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80084E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084E34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80084E38: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80084E3C: beq         $t6, $at, L_80084F70
    if (ctx->r14 == ctx->r1) {
        // 0x80084E40: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80084F70;
    }
    // 0x80084E40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80084E44: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80084E48: jal         0x8008780C
    // 0x80084E4C: nop

    Audio2_GFXDone_SendSyncMessage(rdram, ctx);
        goto after_0;
    // 0x80084E4C: nop

    after_0:
    // 0x80084E50: lbu         $t7, 0x2B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2B);
    // 0x80084E54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80084E58: beq         $t7, $at, L_80084E74
    if (ctx->r15 == ctx->r1) {
        // 0x80084E5C: nop
    
            goto L_80084E74;
    }
    // 0x80084E5C: nop

    // 0x80084E60: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80084E64: lw          $t9, -0x310($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X310);
    // 0x80084E68: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80084E6C: nop

    // 0x80084E70: sw          $t8, 0x18EC($t9)
    MEM_W(0X18EC, ctx->r25) = ctx->r24;
L_80084E74:
    // 0x80084E74: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80084E78: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80084E7C: nop

    // 0x80084E80: sh          $t0, 0x1580($t1)
    MEM_H(0X1580, ctx->r9) = ctx->r8;
    // 0x80084E84: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80084E88: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80084E8C: jal         0x8004A34C
    // 0x80084E90: sh          $t2, 0x1582($t3)
    MEM_H(0X1582, ctx->r11) = ctx->r10;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_1;
    // 0x80084E90: sh          $t2, 0x1582($t3)
    MEM_H(0X1582, ctx->r11) = ctx->r10;
    after_1:
    // 0x80084E94: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80084E98: jal         0x8004A34C
    // 0x80084E9C: sb          $zero, 0x1598($t4)
    MEM_B(0X1598, ctx->r12) = 0;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_2;
    // 0x80084E9C: sb          $zero, 0x1598($t4)
    MEM_B(0X1598, ctx->r12) = 0;
    after_2:
    // 0x80084EA0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80084EA4: lhu         $t5, 0x20B0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X20B0);
    // 0x80084EA8: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80084EAC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80084EB0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80084EB4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80084EB8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80084EBC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80084EC0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80084EC4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80084EC8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80084ECC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80084ED0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80084ED4: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x80084ED8: addiu       $t7, $t7, -0x5300
    ctx->r15 = ADD32(ctx->r15, -0X5300);
    // 0x80084EDC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80084EE0: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x80084EE4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80084EE8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80084EEC: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    // 0x80084EF0: jal         0x800746C0
    // 0x80084EF4: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_3;
    // 0x80084EF4: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_3:
    // 0x80084EF8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80084EFC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80084F00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084F04: jal         0x80086138
    // 0x80084F08: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    Audio2_InitSongPlayer(rdram, ctx);
        goto after_4;
    // 0x80084F08: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_4:
    // 0x80084F0C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80084F10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084F14: sw          $v0, 0x6788($at)
    MEM_W(0X6788, ctx->r1) = ctx->r2;
    // 0x80084F18: sh          $zero, 0x157E($t9)
    MEM_H(0X157E, ctx->r25) = 0;
    // 0x80084F1C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80084F20: nop

    // 0x80084F24: sb          $zero, 0x1584($t0)
    MEM_B(0X1584, ctx->r8) = 0;
    // 0x80084F28: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80084F2C: nop

    // 0x80084F30: lbu         $t2, 0x1584($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1584);
    // 0x80084F34: nop

    // 0x80084F38: bne         $t2, $zero, L_80084F64
    if (ctx->r10 != 0) {
        // 0x80084F3C: nop
    
            goto L_80084F64;
    }
    // 0x80084F3C: nop

L_80084F40:
    // 0x80084F40: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80084F44: jal         0x80085408
    // 0x80084F48: nop

    Audio_AllocDcmScratch8(rdram, ctx);
        goto after_5;
    // 0x80084F48: nop

    after_5:
    // 0x80084F4C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80084F50: nop

    // 0x80084F54: lbu         $t4, 0x1584($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1584);
    // 0x80084F58: nop

    // 0x80084F5C: beq         $t4, $zero, L_80084F40
    if (ctx->r12 == 0) {
        // 0x80084F60: nop
    
            goto L_80084F40;
    }
    // 0x80084F60: nop

L_80084F64:
    // 0x80084F64: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80084F68: jal         0x8008777C
    // 0x80084F6C: nop

    Audio2_ClearBusyFlag(rdram, ctx);
        goto after_6;
    // 0x80084F6C: nop

    after_6:
L_80084F70:
    // 0x80084F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084F74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80084F78: jr          $ra
    // 0x80084F7C: nop

    return;
    // 0x80084F7C: nop

;}

RECOMP_FUNC void Audio_UnloadSFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F80: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80084F84: lw          $t6, -0x752C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X752C);
    // 0x80084F88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80084F8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80084F90: beq         $t6, $zero, L_80085018
    if (ctx->r14 == 0) {
        // 0x80084F94: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80085018;
    }
    // 0x80084F94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80084F98: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80084F9C: nop

    // 0x80084FA0: beq         $t7, $zero, L_80085018
    if (ctx->r15 == 0) {
        // 0x80084FA4: nop
    
            goto L_80085018;
    }
    // 0x80084FA4: nop

    // 0x80084FA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80084FAC: jal         0x80089D5C
    // 0x80084FB0: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    Audio2_StopAllSFX(rdram, ctx);
        goto after_0;
    // 0x80084FB0: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    after_0:
    // 0x80084FB4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80084FB8: jal         0x80088C14
    // 0x80084FBC: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    Audio2_GFXDone_SendStopMessage(rdram, ctx);
        goto after_1;
    // 0x80084FBC: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    after_1:
    // 0x80084FC0: jal         0x8007E4A4
    // 0x80084FC4: nop

    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_2;
    // 0x80084FC4: nop

    after_2:
    // 0x80084FC8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80084FCC: lw          $t8, -0x752C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X752C);
    // 0x80084FD0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80084FD4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084FD8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80084FDC: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    // 0x80084FE0: addiu       $a1, $a1, -0xC44
    ctx->r5 = ADD32(ctx->r5, -0XC44);
    // 0x80084FE4: addiu       $a0, $a0, -0xC74
    ctx->r4 = ADD32(ctx->r4, -0XC74);
    // 0x80084FE8: jal         0x800B3BFC
    // 0x80084FEC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x80084FEC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x80084FF0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80084FF4: lw          $t9, -0x752C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X752C);
    // 0x80084FF8: nop

    // 0x80084FFC: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x80085000: jal         0x8007E328
    // 0x80085004: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_4;
    // 0x80085004: nop

    after_4:
    // 0x80085008: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8008500C: lw          $t0, -0x752C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X752C);
    // 0x80085010: nop

    // 0x80085014: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
L_80085018:
    // 0x80085018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008501C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80085020: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80085024: sw          $zero, -0x752C($at)
    MEM_W(-0X752C, ctx->r1) = 0;
    // 0x80085028: jr          $ra
    // 0x8008502C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8008502C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Audio_LoadSFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085030: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80085034: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80085038: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8008503C: lw          $t6, -0x752C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X752C);
    // 0x80085040: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80085044: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80085048: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8008504C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80085050: bne         $t6, $t7, L_8008506C
    if (ctx->r14 != ctx->r15) {
        // 0x80085054: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_8008506C;
    }
    // 0x80085054: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80085058: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008505C: jal         0x800B3BFC
    // 0x80085060: addiu       $a0, $a0, -0xC30
    ctx->r4 = ADD32(ctx->r4, -0XC30);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80085060: addiu       $a0, $a0, -0xC30
    ctx->r4 = ADD32(ctx->r4, -0XC30);
    after_0:
    // 0x80085064: b           L_800853F0
    // 0x80085068: nop

        goto L_800853F0;
    // 0x80085068: nop

L_8008506C:
    // 0x8008506C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085070: jal         0x80089D5C
    // 0x80085074: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    Audio2_StopAllSFX(rdram, ctx);
        goto after_1;
    // 0x80085074: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    after_1:
    // 0x80085078: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008507C: jal         0x80088C14
    // 0x80085080: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    Audio2_GFXDone_SendStopMessage(rdram, ctx);
        goto after_2;
    // 0x80085080: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    after_2:
    // 0x80085084: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80085088: lw          $t8, -0x752C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X752C);
    // 0x8008508C: nop

    // 0x80085090: beq         $t8, $zero, L_80085100
    if (ctx->r24 == 0) {
        // 0x80085094: nop
    
            goto L_80085100;
    }
    // 0x80085094: nop

    // 0x80085098: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8008509C: nop

    // 0x800850A0: beq         $t9, $zero, L_80085100
    if (ctx->r25 == 0) {
        // 0x800850A4: nop
    
            goto L_80085100;
    }
    // 0x800850A4: nop

    // 0x800850A8: jal         0x8007E4A4
    // 0x800850AC: nop

    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_3;
    // 0x800850AC: nop

    after_3:
    // 0x800850B0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800850B4: lw          $t0, -0x752C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X752C);
    // 0x800850B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800850BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800850C0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800850C4: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x800850C8: addiu       $a1, $a1, -0xBE8
    ctx->r5 = ADD32(ctx->r5, -0XBE8);
    // 0x800850CC: addiu       $a0, $a0, -0xC18
    ctx->r4 = ADD32(ctx->r4, -0XC18);
    // 0x800850D0: jal         0x800B3BFC
    // 0x800850D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_4;
    // 0x800850D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x800850D8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800850DC: lw          $t1, -0x752C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X752C);
    // 0x800850E0: nop

    // 0x800850E4: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    // 0x800850E8: jal         0x8007E328
    // 0x800850EC: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_5;
    // 0x800850EC: nop

    after_5:
    // 0x800850F0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800850F4: lw          $t2, -0x752C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X752C);
    // 0x800850F8: nop

    // 0x800850FC: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
L_80085100:
    // 0x80085100: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80085104: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80085108: sw          $zero, -0x752C($at)
    MEM_W(-0X752C, ctx->r1) = 0;
    // 0x8008510C: lhu         $t4, 0xC($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XC);
    // 0x80085110: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085114: sh          $t4, 0x3B50($at)
    MEM_H(0X3B50, ctx->r1) = ctx->r12;
    // 0x80085118: lhu         $t5, 0x6($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X6);
    // 0x8008511C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085120: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80085124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80085128: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8008512C: jal         0x80088C84
    // 0x80085130: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    Audio2_InitSFXPlayer(rdram, ctx);
        goto after_6;
    // 0x80085130: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    after_6:
    // 0x80085134: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80085138: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008513C: lhu         $a3, 0x1FF0($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X1FF0);
    // 0x80085140: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085144: lw          $a1, 0x10($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X10);
    // 0x80085148: addiu       $a0, $a0, -0xBD8
    ctx->r4 = ADD32(ctx->r4, -0XBD8);
    // 0x8008514C: jal         0x800B3BFC
    // 0x80085150: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_7;
    // 0x80085150: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_7:
    // 0x80085154: jal         0x8007E4F4
    // 0x80085158: nop

    n64HeapGetMaxFreeBlockSize(rdram, ctx);
        goto after_8;
    // 0x80085158: nop

    after_8:
    // 0x8008515C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80085160: nop

    // 0x80085164: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80085168: nop

    // 0x8008516C: sltu        $at, $v0, $t8
    ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
    // 0x80085170: beq         $at, $zero, L_800851A0
    if (ctx->r1 == 0) {
        // 0x80085174: nop
    
            goto L_800851A0;
    }
    // 0x80085174: nop

    // 0x80085178: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008517C: jal         0x800B3BFC
    // 0x80085180: addiu       $a0, $a0, -0xBB0
    ctx->r4 = ADD32(ctx->r4, -0XBB0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_9;
    // 0x80085180: addiu       $a0, $a0, -0xBB0
    ctx->r4 = ADD32(ctx->r4, -0XBB0);
    after_9:
    // 0x80085184: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085188: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008518C: addiu       $a1, $a1, -0xB78
    ctx->r5 = ADD32(ctx->r5, -0XB78);
    // 0x80085190: jal         0x80083560
    // 0x80085194: addiu       $a0, $a0, -0xB90
    ctx->r4 = ADD32(ctx->r4, -0XB90);
    debug_print_reason_routine(rdram, ctx);
        goto after_10;
    // 0x80085194: addiu       $a0, $a0, -0xB90
    ctx->r4 = ADD32(ctx->r4, -0XB90);
    after_10:
    // 0x80085198: b           L_800853F0
    // 0x8008519C: nop

        goto L_800853F0;
    // 0x8008519C: nop

L_800851A0:
    // 0x800851A0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800851A4: nop

    // 0x800851A8: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    // 0x800851AC: jal         0x8007E03C
    // 0x800851B0: nop

    n64HeapAlloc(rdram, ctx);
        goto after_11;
    // 0x800851B0: nop

    after_11:
    // 0x800851B4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800851B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800851BC: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x800851C0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800851C4: addiu       $a0, $a0, -0xB70
    ctx->r4 = ADD32(ctx->r4, -0XB70);
    // 0x800851C8: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x800851CC: jal         0x800B3BFC
    // 0x800851D0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_12;
    // 0x800851D0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_12:
    // 0x800851D4: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800851D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800851DC: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x800851E0: jal         0x8007E4A4
    // 0x800851E4: sw          $t4, 0x6788($at)
    MEM_W(0X6788, ctx->r1) = ctx->r12;
    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_13;
    // 0x800851E4: sw          $t4, 0x6788($at)
    MEM_W(0X6788, ctx->r1) = ctx->r12;
    after_13:
    // 0x800851E8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800851EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800851F0: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x800851F4: lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8);
    // 0x800851F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800851FC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80085200: addiu       $a1, $a1, -0xB18
    ctx->r5 = ADD32(ctx->r5, -0XB18);
    // 0x80085204: addiu       $a0, $a0, -0xB54
    ctx->r4 = ADD32(ctx->r4, -0XB54);
    // 0x80085208: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008520C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80085210: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x80085214: jal         0x800B3BFC
    // 0x80085218: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    rmonPrintf_recomp(rdram, ctx);
        goto after_14;
    // 0x80085218: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_14:
    // 0x8008521C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80085220: lw          $t7, 0x6788($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6788);
    // 0x80085224: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80085228: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008522C: sw          $t7, 0x3900($at)
    MEM_W(0X3900, ctx->r1) = ctx->r15;
    // 0x80085230: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x80085234: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085238: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008523C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80085240: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80085244: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80085248: sw          $t1, 0x6788($at)
    MEM_W(0X6788, ctx->r1) = ctx->r9;
    // 0x8008524C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80085250: lhu         $t2, 0x4($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X4);
    // 0x80085254: nop

    // 0x80085258: blez        $t2, L_80085370
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8008525C: nop
    
            goto L_80085370;
    }
    // 0x8008525C: nop

L_80085260:
    // 0x80085260: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x80085264: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80085268: jal         0x80074888
    // 0x8008526C: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_15;
    // 0x8008526C: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    after_15:
    // 0x80085270: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80085274: jal         0x8007E03C
    // 0x80085278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_16;
    // 0x80085278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8008527C: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x80085280: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80085284: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80085288: jal         0x80074888
    // 0x8008528C: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_17;
    // 0x8008528C: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    after_17:
    // 0x80085290: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x80085294: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80085298: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    // 0x8008529C: jal         0x80074888
    // 0x800852A0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_18;
    // 0x800852A0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_18:
    // 0x800852A4: jal         0x8007E4A4
    // 0x800852A8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_19;
    // 0x800852A8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_19:
    // 0x800852AC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800852B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800852B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800852B8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800852BC: addiu       $a1, $a1, -0xACC
    ctx->r5 = ADD32(ctx->r5, -0XACC);
    // 0x800852C0: addiu       $a0, $a0, -0xB08
    ctx->r4 = ADD32(ctx->r4, -0XB08);
    // 0x800852C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800852C8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800852CC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800852D0: jal         0x800B3BFC
    // 0x800852D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    rmonPrintf_recomp(rdram, ctx);
        goto after_20;
    // 0x800852D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_20:
    // 0x800852D8: lui         $a0, 0x5C
    ctx->r4 = S32(0X5C << 16);
    // 0x800852DC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800852E0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800852E4: jal         0x800746C0
    // 0x800852E8: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_21;
    // 0x800852E8: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    after_21:
    // 0x800852EC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800852F0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800852F4: lw          $a2, 0x6788($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6788);
    // 0x800852F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800852FC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80085300: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x80085304: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80085308: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x8008530C: jal         0x80089030
    // 0x80085310: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    Audio2_SetupSFXChannel(rdram, ctx);
        goto after_22;
    // 0x80085310: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_22:
    // 0x80085314: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085318: jal         0x8007E4A4
    // 0x8008531C: sw          $v0, 0x6788($at)
    MEM_W(0X6788, ctx->r1) = ctx->r2;
    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_23;
    // 0x8008531C: sw          $v0, 0x6788($at)
    MEM_W(0X6788, ctx->r1) = ctx->r2;
    after_23:
    // 0x80085320: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80085324: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085328: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008532C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80085330: addiu       $a1, $a1, -0xA94
    ctx->r5 = ADD32(ctx->r5, -0XA94);
    // 0x80085334: addiu       $a0, $a0, -0xAC4
    ctx->r4 = ADD32(ctx->r4, -0XAC4);
    // 0x80085338: jal         0x800B3BFC
    // 0x8008533C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_24;
    // 0x8008533C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_24:
    // 0x80085340: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80085344: jal         0x8007E328
    // 0x80085348: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_25;
    // 0x80085348: nop

    after_25:
    // 0x8008534C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80085350: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80085354: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80085358: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x8008535C: lhu         $t0, 0x4($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X4);
    // 0x80085360: nop

    // 0x80085364: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80085368: bne         $at, $zero, L_80085260
    if (ctx->r1 != 0) {
        // 0x8008536C: nop
    
            goto L_80085260;
    }
    // 0x8008536C: nop

L_80085370:
    // 0x80085370: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80085374: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80085378: lw          $t1, 0x6788($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6788);
    // 0x8008537C: lw          $t2, 0x8($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X8);
    // 0x80085380: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085384: addiu       $a0, $a0, -0xA8C
    ctx->r4 = ADD32(ctx->r4, -0XA8C);
    // 0x80085388: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8008538C: jal         0x800B3BFC
    // 0x80085390: subu        $a2, $t1, $t2
    ctx->r6 = SUB32(ctx->r9, ctx->r10);
    rmonPrintf_recomp(rdram, ctx);
        goto after_26;
    // 0x80085390: subu        $a2, $t1, $t2
    ctx->r6 = SUB32(ctx->r9, ctx->r10);
    after_26:
    // 0x80085394: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80085398: lw          $t4, 0x6788($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6788);
    // 0x8008539C: lui         $at, 0x8038
    ctx->r1 = S32(0X8038 << 16);
    // 0x800853A0: ori         $at, $at, 0xAD01
    ctx->r1 = ctx->r1 | 0XAD01;
    // 0x800853A4: sltu        $at, $t4, $at
    ctx->r1 = ctx->r12 < ctx->r1 ? 1 : 0;
    // 0x800853A8: bne         $at, $zero, L_800853C4
    if (ctx->r1 != 0) {
        // 0x800853AC: nop
    
            goto L_800853C4;
    }
    // 0x800853AC: nop

    // 0x800853B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800853B4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800853B8: addiu       $a1, $a1, -0xA4C
    ctx->r5 = ADD32(ctx->r5, -0XA4C);
    // 0x800853BC: jal         0x80083560
    // 0x800853C0: addiu       $a0, $a0, -0xA64
    ctx->r4 = ADD32(ctx->r4, -0XA64);
    debug_print_reason_routine(rdram, ctx);
        goto after_27;
    // 0x800853C0: addiu       $a0, $a0, -0xA64
    ctx->r4 = ADD32(ctx->r4, -0XA64);
    after_27:
L_800853C4:
    // 0x800853C4: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800853C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800853CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800853D0: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x800853D4: jal         0x80088BA4
    // 0x800853D8: sw          $t5, -0x752C($at)
    MEM_W(-0X752C, ctx->r1) = ctx->r13;
    Audio2_GFXDone_SendStartMessage(rdram, ctx);
        goto after_28;
    // 0x800853D8: sw          $t5, -0x752C($at)
    MEM_W(-0X752C, ctx->r1) = ctx->r13;
    after_28:
    // 0x800853DC: jal         0x800B6650
    // 0x800853E0: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_29;
    // 0x800853E0: nop

    after_29:
    // 0x800853E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800853E8: jal         0x800B3BFC
    // 0x800853EC: addiu       $a0, $a0, -0xA40
    ctx->r4 = ADD32(ctx->r4, -0XA40);
    rmonPrintf_recomp(rdram, ctx);
        goto after_30;
    // 0x800853EC: addiu       $a0, $a0, -0xA40
    ctx->r4 = ADD32(ctx->r4, -0XA40);
    after_30:
L_800853F0:
    // 0x800853F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800853F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800853F8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800853FC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80085400: jr          $ra
    // 0x80085404: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80085404: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}

RECOMP_FUNC void Audio_AllocDcmScratch8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085408: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008540C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80085410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085414: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80085418: jal         0x800864B4
    // 0x8008541C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    Audio2_AllocDcmScratch8(rdram, ctx);
        goto after_0;
    // 0x8008541C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80085420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80085428: jr          $ra
    // 0x8008542C: nop

    return;
    // 0x8008542C: nop

;}

RECOMP_FUNC void Audio_ALManager(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085430: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80085434: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80085438: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008543C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80085440: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80085444: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80085448: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
    // 0x8008544C: jal         0x8005EE84
    // 0x80085450: addiu       $a0, $a0, -0x4460
    ctx->r4 = ADD32(ctx->r4, -0X4460);
    osScGetCmdQ(rdram, ctx);
        goto after_0;
    // 0x80085450: addiu       $a0, $a0, -0x4460
    ctx->r4 = ADD32(ctx->r4, -0X4460);
    after_0:
    // 0x80085454: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80085458: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008545C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80085460: sw          $v0, 0x67A0($at)
    MEM_W(0X67A0, ctx->r1) = ctx->r2;
    // 0x80085464: addiu       $t6, $t6, 0x5CF4
    ctx->r14 = ADD32(ctx->r14, 0X5CF4);
    // 0x80085468: sw          $t6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r14;
    // 0x8008546C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80085470: nop

    // 0x80085474: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80085478: jal         0x800B8590
    // 0x8008547C: nop

    osAiSetFrequency_recomp(rdram, ctx);
        goto after_1;
    // 0x8008547C: nop

    after_1:
    // 0x80085480: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80085484: nop

    // 0x80085488: sw          $v0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r2;
    // 0x8008548C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80085490: nop

    // 0x80085494: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80085498: nop

    // 0x8008549C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800854A0: bgez        $t1, L_800854B8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800854A4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800854B8;
    }
    // 0x800854A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800854A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800854AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800854B0: nop

    // 0x800854B4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800854B8:
    // 0x800854B8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800854BC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800854C0: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x800854C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800854C8: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800854CC: nop

    // 0x800854D0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800854D4: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800854D8: nop

    // 0x800854DC: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800854E0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800854E4: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800854E8: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800854EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800854F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800854F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800854F8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800854FC: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80085500: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80085504: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80085508: sw          $t5, -0x75A8($at)
    MEM_W(-0X75A8, ctx->r1) = ctx->r13;
    // 0x8008550C: bgez        $t5, L_80085524
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80085510: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80085524;
    }
    // 0x80085510: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80085514: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80085518: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008551C: nop

    // 0x80085520: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80085524:
    // 0x80085524: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x80085528: nop

    // 0x8008552C: bc1f        L_80085540
    if (!c1cs) {
        // 0x80085530: nop
    
            goto L_80085540;
    }
    // 0x80085530: nop

    // 0x80085534: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80085538: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008553C: sw          $t6, -0x75A8($at)
    MEM_W(-0X75A8, ctx->r1) = ctx->r14;
L_80085540:
    // 0x80085540: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80085544: lw          $t7, -0x75A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X75A8);
    // 0x80085548: nop

    // 0x8008554C: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80085550: beq         $t8, $zero, L_80085568
    if (ctx->r24 == 0) {
        // 0x80085554: addiu       $at, $zero, -0x10
        ctx->r1 = ADD32(0, -0X10);
            goto L_80085568;
    }
    // 0x80085554: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80085558: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8008555C: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80085560: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80085564: sw          $t0, -0x75A8($at)
    MEM_W(-0X75A8, ctx->r1) = ctx->r8;
L_80085568:
    // 0x80085568: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8008556C: lw          $t1, -0x75A8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X75A8);
    // 0x80085570: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80085574: addiu       $t2, $t1, -0x10
    ctx->r10 = ADD32(ctx->r9, -0X10);
    // 0x80085578: sw          $t2, -0x75AC($at)
    MEM_W(-0X75AC, ctx->r1) = ctx->r10;
    // 0x8008557C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085580: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80085584: addiu       $a0, $a0, 0x67A8
    ctx->r4 = ADD32(ctx->r4, 0X67A8);
    // 0x80085588: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8008558C: addiu       $t3, $t1, 0x60
    ctx->r11 = ADD32(ctx->r9, 0X60);
    // 0x80085590: sw          $t3, -0x75A4($at)
    MEM_W(-0X75A4, ctx->r1) = ctx->r11;
    // 0x80085594: jal         0x800B876C
    // 0x80085598: addiu       $a0, $a0, 0x238
    ctx->r4 = ADD32(ctx->r4, 0X238);
    alInit(rdram, ctx);
        goto after_2;
    // 0x80085598: addiu       $a0, $a0, 0x238
    ctx->r4 = ADD32(ctx->r4, 0X238);
    after_2:
    // 0x8008559C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800855A0:
    // 0x800855A0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800855A4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800855A8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x800855AC: lw          $a2, 0x14($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X14);
    // 0x800855B0: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800855B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800855B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800855BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800855C0: jal         0x800B8530
    // 0x800855C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800855C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x800855C8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800855CC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800855D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800855D4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800855D8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800855DC: sw          $v0, 0x67A8($at)
    MEM_W(0X67A8, ctx->r1) = ctx->r2;
    // 0x800855E0: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800855E4: sltiu       $at, $t2, 0x2
    ctx->r1 = ctx->r10 < 0X2 ? 1 : 0;
    // 0x800855E8: bne         $at, $zero, L_800855A0
    if (ctx->r1 != 0) {
        // 0x800855EC: sw          $t2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r10;
            goto L_800855A0;
    }
    // 0x800855EC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800855F0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800855F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800855F8: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x800855FC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80085600: sw          $t3, -0x75A0($at)
    MEM_W(-0X75A0, ctx->r1) = ctx->r11;
L_80085604:
    // 0x80085604: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80085608: addiu       $t5, $zero, 0x90
    ctx->r13 = ADD32(0, 0X90);
    // 0x8008560C: lw          $a2, 0x14($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X14);
    // 0x80085610: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80085614: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80085618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008561C: jal         0x800B8530
    // 0x80085620: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x80085620: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80085624: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80085628: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8008562C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085630: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80085634: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80085638: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008563C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80085640: sw          $v0, 0x67B0($at)
    MEM_W(0X67B0, ctx->r1) = ctx->r2;
    // 0x80085644: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80085648: lw          $t2, 0x67B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X67B0);
    // 0x8008564C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80085650: sh          $t7, 0x70($t2)
    MEM_H(0X70, ctx->r10) = ctx->r15;
    // 0x80085654: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80085658: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008565C: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80085660: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80085664: lw          $t4, 0x67B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X67B0);
    // 0x80085668: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8008566C: sw          $t4, 0x74($t4)
    MEM_W(0X74, ctx->r12) = ctx->r12;
    // 0x80085670: lw          $t6, -0x75A4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X75A4);
    // 0x80085674: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80085678: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8008567C: lw          $a2, 0x14($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X14);
    // 0x80085680: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80085684: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80085688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008568C: jal         0x800B8530
    // 0x80085690: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x80085690: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80085694: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80085698: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008569C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800856A0: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x800856A4: lw          $t7, 0x67B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X67B0);
    // 0x800856A8: nop

    // 0x800856AC: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800856B0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800856B4: nop

    // 0x800856B8: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x800856BC: sltiu       $at, $t1, 0x3
    ctx->r1 = ctx->r9 < 0X3 ? 1 : 0;
    // 0x800856C0: bne         $at, $zero, L_80085604
    if (ctx->r1 != 0) {
        // 0x800856C4: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_80085604;
    }
    // 0x800856C4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800856C8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800856CC: ori         $t4, $zero, 0xFFFF
    ctx->r12 = 0 | 0XFFFF;
    // 0x800856D0: lw          $a2, 0x14($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X14);
    // 0x800856D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800856D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800856DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800856E0: jal         0x800B8530
    // 0x800856E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x800856E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x800856E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800856EC: sw          $v0, -0x7564($at)
    MEM_W(-0X7564, ctx->r1) = ctx->r2;
    // 0x800856F0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800856F4: lw          $t5, -0x7564($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7564);
    // 0x800856F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800856FC: sw          $t5, -0x7560($at)
    MEM_W(-0X7560, ctx->r1) = ctx->r13;
    // 0x80085700: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80085704: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x80085708: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008570C: addiu       $a0, $a0, -0xA30
    ctx->r4 = ADD32(ctx->r4, -0XA30);
    // 0x80085710: jal         0x800B3BFC
    // 0x80085714: addu        $a1, $t5, $at
    ctx->r5 = ADD32(ctx->r13, ctx->r1);
    rmonPrintf_recomp(rdram, ctx);
        goto after_7;
    // 0x80085714: addu        $a1, $t5, $at
    ctx->r5 = ADD32(ctx->r13, ctx->r1);
    after_7:
    // 0x80085718: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008571C: addiu       $t6, $t6, 0x67A8
    ctx->r14 = ADD32(ctx->r14, 0X67A8);
    // 0x80085720: addiu       $a0, $t6, 0x200
    ctx->r4 = ADD32(ctx->r14, 0X200);
    // 0x80085724: addiu       $a1, $t6, 0x218
    ctx->r5 = ADD32(ctx->r14, 0X218);
    // 0x80085728: jal         0x800B3080
    // 0x8008572C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_8;
    // 0x8008572C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_8:
    // 0x80085730: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80085734: addiu       $t8, $t8, 0x67A8
    ctx->r24 = ADD32(ctx->r24, 0X67A8);
    // 0x80085738: addiu       $a0, $t8, 0x1C8
    ctx->r4 = ADD32(ctx->r24, 0X1C8);
    // 0x8008573C: addiu       $a1, $t8, 0x1E0
    ctx->r5 = ADD32(ctx->r24, 0X1E0);
    // 0x80085740: jal         0x800B3080
    // 0x80085744: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_9;
    // 0x80085744: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_9:
    // 0x80085748: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008574C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80085750: addiu       $a1, $a1, -0x7568
    ctx->r5 = ADD32(ctx->r5, -0X7568);
    // 0x80085754: addiu       $a0, $a0, -0x7580
    ctx->r4 = ADD32(ctx->r4, -0X7580);
    // 0x80085758: jal         0x800B3080
    // 0x8008575C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_10;
    // 0x8008575C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x80085760: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80085764: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80085768: addiu       $t9, $t9, 0x6A30
    ctx->r25 = ADD32(ctx->r25, 0X6A30);
    // 0x8008576C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085770: addiu       $a0, $a0, 0x67A8
    ctx->r4 = ADD32(ctx->r4, 0X67A8);
    // 0x80085774: addiu       $t0, $t9, 0x2000
    ctx->r8 = ADD32(ctx->r25, 0X2000);
    // 0x80085778: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8008577C: addiu       $a2, $a2, 0x57B8
    ctx->r6 = ADD32(ctx->r6, 0X57B8);
    // 0x80085780: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80085784: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80085788: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008578C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80085790: jal         0x800B6010
    // 0x80085794: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    osCreateThread_recomp(rdram, ctx);
        goto after_11;
    // 0x80085794: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_11:
    // 0x80085798: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008579C: addiu       $a0, $a0, 0x67A8
    ctx->r4 = ADD32(ctx->r4, 0X67A8);
    // 0x800857A0: jal         0x800B6160
    // 0x800857A4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    osStartThread_recomp(rdram, ctx);
        goto after_12;
    // 0x800857A4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_12:
    // 0x800857A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800857AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800857B0: jr          $ra
    // 0x800857B4: nop

    return;
    // 0x800857B4: nop

;}

RECOMP_FUNC void Audio_PreNmiAudio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800857BC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800857C0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800857C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800857C8: addiu       $a2, $a2, 0x67A8
    ctx->r6 = ADD32(ctx->r6, 0X67A8);
    // 0x800857CC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800857D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800857D4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800857D8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800857DC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800857E0: addiu       $a0, $a0, -0x4460
    ctx->r4 = ADD32(ctx->r4, -0X4460);
    // 0x800857E4: addiu       $a2, $a2, 0x1C8
    ctx->r6 = ADD32(ctx->r6, 0X1C8);
    // 0x800857E8: jal         0x8005ED58
    // 0x800857EC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    osScAddClient(rdram, ctx);
        goto after_0;
    // 0x800857EC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800857F0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800857F4: nop

    // 0x800857F8: bne         $t6, $zero, L_80085904
    if (ctx->r14 != 0) {
        // 0x800857FC: nop
    
            goto L_80085904;
    }
    // 0x800857FC: nop

L_80085800:
    // 0x80085800: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085804: addiu       $a0, $a0, 0x67A8
    ctx->r4 = ADD32(ctx->r4, 0X67A8);
    // 0x80085808: addiu       $a0, $a0, 0x1C8
    ctx->r4 = ADD32(ctx->r4, 0X1C8);
    // 0x8008580C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80085810: jal         0x800B3C20
    // 0x80085814: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80085814: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80085818: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8008581C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80085820: lh          $s0, 0x0($t7)
    ctx->r16 = MEM_H(ctx->r15, 0X0);
    // 0x80085824: nop

    // 0x80085828: beq         $s0, $at, L_80085848
    if (ctx->r16 == ctx->r1) {
        // 0x8008582C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80085848;
    }
    // 0x8008582C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80085830: beq         $s0, $at, L_800858D0
    if (ctx->r16 == ctx->r1) {
        // 0x80085834: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800858D0;
    }
    // 0x80085834: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80085838: beq         $s0, $at, L_800858EC
    if (ctx->r16 == ctx->r1) {
        // 0x8008583C: nop
    
            goto L_800858EC;
    }
    // 0x8008583C: nop

    // 0x80085840: b           L_800858F4
    // 0x80085844: nop

        goto L_800858F4;
    // 0x80085844: nop

L_80085848:
    // 0x80085848: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8008584C: lw          $t8, 0x3910($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3910);
    // 0x80085850: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085854: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x80085858: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008585C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80085860: lw          $a1, 0x391C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X391C);
    // 0x80085864: mfhi        $t9
    ctx->r25 = hi;
    // 0x80085868: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008586C: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80085870: lw          $a0, 0x67B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X67B0);
    // 0x80085874: jal         0x80085924
    // 0x80085878: nop

    Audio_CreateTask(rdram, ctx);
        goto after_2;
    // 0x80085878: nop

    after_2:
    // 0x8008587C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80085880: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80085884: nop

    // 0x80085888: beq         $t1, $zero, L_800858F4
    if (ctx->r9 == 0) {
        // 0x8008588C: nop
    
            goto L_800858F4;
    }
    // 0x8008588C: nop

    // 0x80085890: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085894: addiu       $a0, $a0, 0x67A8
    ctx->r4 = ADD32(ctx->r4, 0X67A8);
    // 0x80085898: addiu       $a0, $a0, 0x200
    ctx->r4 = ADD32(ctx->r4, 0X200);
    // 0x8008589C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800858A0: jal         0x800B3C20
    // 0x800858A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800858A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800858A8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800858AC: nop

    // 0x800858B0: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    // 0x800858B4: jal         0x80085B9C
    // 0x800858B8: nop

    Audio_CheckAiDrained(rdram, ctx);
        goto after_4;
    // 0x800858B8: nop

    after_4:
    // 0x800858BC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800858C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800858C4: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800858C8: b           L_800858F4
    // 0x800858CC: sw          $t4, 0x391C($at)
    MEM_W(0X391C, ctx->r1) = ctx->r12;
        goto L_800858F4;
    // 0x800858CC: sw          $t4, 0x391C($at)
    MEM_W(0X391C, ctx->r1) = ctx->r12;
L_800858D0:
    // 0x800858D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800858D4: jal         0x800B3BFC
    // 0x800858D8: addiu       $a0, $a0, -0xA1C
    ctx->r4 = ADD32(ctx->r4, -0XA1C);
    rmonPrintf_recomp(rdram, ctx);
        goto after_5;
    // 0x800858D8: addiu       $a0, $a0, -0xA1C
    ctx->r4 = ADD32(ctx->r4, -0XA1C);
    after_5:
    // 0x800858DC: jal         0x80061198
    // 0x800858E0: nop

    Vi_ApplyModeBank(rdram, ctx);
        goto after_6;
    // 0x800858E0: nop

    after_6:
    // 0x800858E4: b           L_800858F4
    // 0x800858E8: nop

        goto L_800858F4;
    // 0x800858E8: nop

L_800858EC:
    // 0x800858EC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800858F0: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
L_800858F4:
    // 0x800858F4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800858F8: nop

    // 0x800858FC: beq         $t6, $zero, L_80085800
    if (ctx->r14 == 0) {
        // 0x80085900: nop
    
            goto L_80085800;
    }
    // 0x80085900: nop

L_80085904:
    // 0x80085904: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085908: addiu       $a0, $a0, 0x67A8
    ctx->r4 = ADD32(ctx->r4, 0X67A8);
    // 0x8008590C: jal         0x800B8734
    // 0x80085910: addiu       $a0, $a0, 0x238
    ctx->r4 = ADD32(ctx->r4, 0X238);
    alClose(rdram, ctx);
        goto after_7;
    // 0x80085910: addiu       $a0, $a0, 0x238
    ctx->r4 = ADD32(ctx->r4, 0X238);
    after_7:
    // 0x80085914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80085918: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008591C: jr          $ra
    // 0x80085920: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80085920: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Audio_CreateTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085924: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80085928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008592C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80085930: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80085934: jal         0x80085D04
    // 0x80085938: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    Audio_Wrap(rdram, ctx);
        goto after_0;
    // 0x80085938: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_0:
    // 0x8008593C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80085940: nop

    // 0x80085944: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80085948: jal         0x800B87A0
    // 0x8008594C: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x8008594C: nop

    after_1:
    // 0x80085950: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80085954: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80085958: beq         $t7, $zero, L_80085974
    if (ctx->r15 == 0) {
        // 0x8008595C: nop
    
            goto L_80085974;
    }
    // 0x8008595C: nop

    // 0x80085960: lh          $a1, 0x4($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X4);
    // 0x80085964: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80085968: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8008596C: jal         0x800B8820
    // 0x80085970: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x80085970: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_2:
L_80085974:
    // 0x80085974: jal         0x800B88D0
    // 0x80085978: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_3;
    // 0x80085978: nop

    after_3:
    // 0x8008597C: srl         $t9, $v0, 2
    ctx->r25 = S32(U32(ctx->r2) >> 2);
    // 0x80085980: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80085984: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80085988: lw          $t0, -0x75A8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X75A8);
    // 0x8008598C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80085990: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80085994: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80085998: addiu       $t3, $t2, 0x60
    ctx->r11 = ADD32(ctx->r10, 0X60);
    // 0x8008599C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800859A0: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800859A4: sh          $t4, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r12;
    // 0x800859A8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800859AC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800859B0: lw          $t8, -0x75AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X75AC);
    // 0x800859B4: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x800859B8: nop

    // 0x800859BC: sltu        $at, $t7, $t8
    ctx->r1 = ctx->r15 < ctx->r24 ? 1 : 0;
    // 0x800859C0: beq         $at, $zero, L_800859CC
    if (ctx->r1 == 0) {
        // 0x800859C4: nop
    
            goto L_800859CC;
    }
    // 0x800859C4: nop

    // 0x800859C8: sh          $t8, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r24;
L_800859CC:
    // 0x800859CC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800859D0: lw          $t9, 0x3918($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3918);
    // 0x800859D4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800859D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800859DC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800859E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800859E4: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x800859E8: lw          $a0, 0x67A8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X67A8);
    // 0x800859EC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800859F0: lh          $a3, 0x4($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X4);
    // 0x800859F4: jal         0x8008EAAC
    // 0x800859F8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    alAudioFrame(rdram, ctx);
        goto after_4;
    // 0x800859F8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x800859FC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80085A00: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80085A04: bne         $t2, $zero, L_80085A14
    if (ctx->r10 != 0) {
        // 0x80085A08: nop
    
            goto L_80085A14;
    }
    // 0x80085A08: nop

    // 0x80085A0C: b           L_80085B8C
    // 0x80085A10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80085B8C;
    // 0x80085A10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80085A14:
    // 0x80085A14: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80085A18: nop

    // 0x80085A1C: bne         $t3, $zero, L_80085A2C
    if (ctx->r11 != 0) {
        // 0x80085A20: nop
    
            goto L_80085A2C;
    }
    // 0x80085A20: nop

    // 0x80085A24: b           L_80085B8C
    // 0x80085A28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80085B8C;
    // 0x80085A28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80085A2C:
    // 0x80085A2C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80085A30: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80085A34: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80085A38: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80085A3C: sw          $zero, 0x8($t4)
    MEM_W(0X8, ctx->r12) = 0;
    // 0x80085A40: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80085A44: addiu       $t7, $t7, 0x67A8
    ctx->r15 = ADD32(ctx->r15, 0X67A8);
    // 0x80085A48: addiu       $t8, $t7, 0x200
    ctx->r24 = ADD32(ctx->r15, 0X200);
    // 0x80085A4C: sw          $t8, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->r24;
    // 0x80085A50: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80085A54: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80085A58: addiu       $t0, $t9, 0x70
    ctx->r8 = ADD32(ctx->r25, 0X70);
    // 0x80085A5C: sw          $t0, 0x54($t1)
    MEM_W(0X54, ctx->r9) = ctx->r8;
    // 0x80085A60: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80085A64: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80085A68: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80085A6C: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x80085A70: lw          $t5, 0x3918($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3918);
    // 0x80085A74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80085A78: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80085A7C: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x80085A80: lw          $t7, 0x67A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X67A8);
    // 0x80085A84: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80085A88: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80085A8C: sw          $t7, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->r15;
    // 0x80085A90: lw          $t9, 0x3918($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3918);
    // 0x80085A94: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80085A98: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80085A9C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80085AA0: lw          $t1, 0x67A8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X67A8);
    // 0x80085AA4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80085AA8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80085AAC: subu        $t2, $t6, $t1
    ctx->r10 = SUB32(ctx->r14, ctx->r9);
    // 0x80085AB0: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x80085AB4: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x80085AB8: sw          $t5, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->r13;
    // 0x80085ABC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80085AC0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80085AC4: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x80085AC8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80085ACC: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80085AD0: addiu       $t9, $t9, 0x3310
    ctx->r25 = ADD32(ctx->r25, 0X3310);
    // 0x80085AD4: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80085AD8: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80085ADC: sw          $t9, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r25;
    // 0x80085AE0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80085AE4: addiu       $t6, $t6, 0x33E0
    ctx->r14 = ADD32(ctx->r14, 0X33E0);
    // 0x80085AE8: addiu       $t1, $t1, 0x3310
    ctx->r9 = ADD32(ctx->r9, 0X3310);
    // 0x80085AEC: subu        $t2, $t6, $t1
    ctx->r10 = SUB32(ctx->r14, ctx->r9);
    // 0x80085AF0: sw          $t2, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r10;
    // 0x80085AF4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80085AF8: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80085AFC: sw          $zero, 0x14($t5)
    MEM_W(0X14, ctx->r13) = 0;
    // 0x80085B00: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80085B04: addiu       $t4, $t4, 0x4770
    ctx->r12 = ADD32(ctx->r12, 0X4770);
    // 0x80085B08: sw          $t4, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r12;
    // 0x80085B0C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80085B10: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80085B14: addiu       $t8, $t8, 0x1C50
    ctx->r24 = ADD32(ctx->r24, 0X1C50);
    // 0x80085B18: sw          $t8, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r24;
    // 0x80085B1C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80085B20: addiu       $t0, $zero, 0x800
    ctx->r8 = ADD32(0, 0X800);
    // 0x80085B24: sw          $t0, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r8;
    // 0x80085B28: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80085B2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085B30: sw          $zero, 0x30($t1)
    MEM_W(0X30, ctx->r9) = 0;
    // 0x80085B34: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80085B38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80085B3C: sw          $zero, 0x38($t2)
    MEM_W(0X38, ctx->r10) = 0;
    // 0x80085B40: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80085B44: nop

    // 0x80085B48: sw          $zero, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = 0;
    // 0x80085B4C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80085B50: nop

    // 0x80085B54: sw          $zero, 0x48($t5)
    MEM_W(0X48, ctx->r13) = 0;
    // 0x80085B58: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80085B5C: nop

    // 0x80085B60: sw          $zero, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = 0;
    // 0x80085B64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80085B68: lw          $a0, 0x67A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X67A0);
    // 0x80085B6C: jal         0x800B34D0
    // 0x80085B70: nop

    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80085B70: nop

    after_5:
    // 0x80085B74: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80085B78: lw          $t7, 0x3918($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3918);
    // 0x80085B7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085B80: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x80085B84: sw          $t8, 0x3918($at)
    MEM_W(0X3918, ctx->r1) = ctx->r24;
    // 0x80085B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80085B8C:
    // 0x80085B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085B90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80085B94: jr          $ra
    // 0x80085B98: nop

    return;
    // 0x80085B98: nop

;}

RECOMP_FUNC void Audio_CheckAiDrained(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80085BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085BA4: jal         0x800B88D0
    // 0x80085BA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    osAiGetLength_recomp(rdram, ctx);
        goto after_0;
    // 0x80085BA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80085BAC: srl         $t6, $v0, 2
    ctx->r14 = S32(U32(ctx->r2) >> 2);
    // 0x80085BB0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80085BB4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80085BB8: nop

    // 0x80085BBC: bne         $t7, $zero, L_80085BDC
    if (ctx->r15 != 0) {
        // 0x80085BC0: nop
    
            goto L_80085BDC;
    }
    // 0x80085BC0: nop

    // 0x80085BC4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80085BC8: lw          $t8, 0x3920($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3920);
    // 0x80085BCC: nop

    // 0x80085BD0: bne         $t8, $zero, L_80085BDC
    if (ctx->r24 != 0) {
        // 0x80085BD4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80085BDC;
    }
    // 0x80085BD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085BD8: sw          $zero, 0x3920($at)
    MEM_W(0X3920, ctx->r1) = 0;
L_80085BDC:
    // 0x80085BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085BE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80085BE4: jr          $ra
    // 0x80085BE8: nop

    return;
    // 0x80085BE8: nop

;}

RECOMP_FUNC void Audio_DmaCallback(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80085BF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80085BF4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80085BF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80085BFC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80085C00: sltu        $at, $t6, $at
    ctx->r1 = ctx->r14 < ctx->r1 ? 1 : 0;
    // 0x80085C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085C08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80085C0C: bne         $at, $zero, L_80085C24
    if (ctx->r1 != 0) {
        // 0x80085C10: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80085C24;
    }
    // 0x80085C10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80085C14: lui         $at, 0x8040
    ctx->r1 = S32(0X8040 << 16);
    // 0x80085C18: sltu        $at, $t6, $at
    ctx->r1 = ctx->r14 < ctx->r1 ? 1 : 0;
    // 0x80085C1C: bne         $at, $zero, L_80085C30
    if (ctx->r1 != 0) {
        // 0x80085C20: nop
    
            goto L_80085C30;
    }
    // 0x80085C20: nop

L_80085C24:
    // 0x80085C24: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80085C28: b           L_80085CE4
    // 0x80085C2C: nop

        goto L_80085CE4;
    // 0x80085C2C: nop

L_80085C30:
    // 0x80085C30: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80085C34: lw          $t7, -0x7564($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7564);
    // 0x80085C38: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80085C3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80085C40: sw          $t7, -0x755C($at)
    MEM_W(-0X755C, ctx->r1) = ctx->r15;
    // 0x80085C44: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80085C48: addiu       $t9, $t8, 0xF
    ctx->r25 = ADD32(ctx->r24, 0XF);
    // 0x80085C4C: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80085C50: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80085C54: slt         $at, $t0, $at
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085C58: bne         $at, $zero, L_80085C68
    if (ctx->r1 != 0) {
        // 0x80085C5C: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_80085C68;
    }
    // 0x80085C5C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80085C60: b           L_80085CE4
    // 0x80085C64: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80085CE4;
    // 0x80085C64: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80085C68:
    // 0x80085C68: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80085C6C: lw          $t3, -0x7564($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7564);
    // 0x80085C70: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80085C74: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80085C78: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x80085C7C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80085C80: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80085C84: addu        $t5, $t3, $at
    ctx->r13 = ADD32(ctx->r11, ctx->r1);
    // 0x80085C88: sltu        $at, $t5, $t4
    ctx->r1 = ctx->r13 < ctx->r12 ? 1 : 0;
    // 0x80085C8C: beq         $at, $zero, L_80085C9C
    if (ctx->r1 == 0) {
        // 0x80085C90: nop
    
            goto L_80085C9C;
    }
    // 0x80085C90: nop

    // 0x80085C94: b           L_80085CE4
    // 0x80085C98: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_80085CE4;
    // 0x80085C98: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80085C9C:
    // 0x80085C9C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80085CA0: lw          $a1, -0x7564($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7564);
    // 0x80085CA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085CA8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80085CAC: jal         0x800A2F00
    // 0x80085CB0: nop

    Scene_ExpandBytesToHalfwords(rdram, ctx);
        goto after_0;
    // 0x80085CB0: nop

    after_0:
    // 0x80085CB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80085CB8: sw          $v0, -0x7564($at)
    MEM_W(-0X7564, ctx->r1) = ctx->r2;
    // 0x80085CBC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80085CC0: lw          $t6, -0x7564($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7564);
    // 0x80085CC4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80085CC8: addiu       $t8, $t6, 0xF
    ctx->r24 = ADD32(ctx->r14, 0XF);
    // 0x80085CCC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80085CD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80085CD4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80085CD8: lw          $a0, -0x755C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X755C);
    // 0x80085CDC: jal         0x800B87A0
    // 0x80085CE0: sw          $t9, -0x7564($at)
    MEM_W(-0X7564, ctx->r1) = ctx->r25;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80085CE0: sw          $t9, -0x7564($at)
    MEM_W(-0X7564, ctx->r1) = ctx->r25;
    after_1:
L_80085CE4:
    // 0x80085CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80085CEC: jr          $ra
    // 0x80085CF0: nop

    return;
    // 0x80085CF0: nop

;}

RECOMP_FUNC void Audio_DmaNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CF4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80085CF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80085CFC: jr          $ra
    // 0x80085D00: addiu       $v0, $v0, 0x5BEC
    ctx->r2 = ADD32(ctx->r2, 0X5BEC);
    return;
    // 0x80085D00: addiu       $v0, $v0, 0x5BEC
    ctx->r2 = ADD32(ctx->r2, 0X5BEC);
;}

RECOMP_FUNC void Audio_Wrap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D04: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80085D08: lw          $t6, 0x3910($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3910);
    // 0x80085D0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80085D10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085D14: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80085D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085D1C: bne         $t7, $zero, L_80085D30
    if (ctx->r15 != 0) {
        // 0x80085D20: sw          $t7, 0x3910($at)
        MEM_W(0X3910, ctx->r1) = ctx->r15;
            goto L_80085D30;
    }
    // 0x80085D20: sw          $t7, 0x3910($at)
    MEM_W(0X3910, ctx->r1) = ctx->r15;
    // 0x80085D24: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085D28: jal         0x800B3BFC
    // 0x80085D2C: addiu       $a0, $a0, -0x9D0
    ctx->r4 = ADD32(ctx->r4, -0X9D0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80085D2C: addiu       $a0, $a0, -0x9D0
    ctx->r4 = ADD32(ctx->r4, -0X9D0);
    after_0:
L_80085D30:
    // 0x80085D30: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80085D34: lw          $t8, -0x7560($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7560);
    // 0x80085D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085D3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80085D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80085D44: jr          $ra
    // 0x80085D48: sw          $t8, -0x7564($at)
    MEM_W(-0X7564, ctx->r1) = ctx->r24;
    return;
    // 0x80085D48: sw          $t8, -0x7564($at)
    MEM_W(-0X7564, ctx->r1) = ctx->r24;
    // 0x80085D4C: nop

;}

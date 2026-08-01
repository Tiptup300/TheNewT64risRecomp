#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Audio2_AllocDcmHeader(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F8C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80085F90: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80085F94: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80085F98: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80085F9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80085FA0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80085FA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80085FA8: jal         0x8008BF58
    // 0x80085FAC: addiu       $a1, $a1, 0x418
    ctx->r5 = ADD32(ctx->r5, 0X418);
    Audio2_ParseSFXHeader(rdram, ctx);
        goto after_0;
    // 0x80085FAC: addiu       $a1, $a1, 0x418
    ctx->r5 = ADD32(ctx->r5, 0X418);
    after_0:
    // 0x80085FB0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80085FB4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80085FB8: addiu       $t7, $t6, 0xE
    ctx->r15 = ADD32(ctx->r14, 0XE);
    // 0x80085FBC: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80085FC0: lbu         $t9, 0x41C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X41C);
    // 0x80085FC4: nop

    // 0x80085FC8: sw          $t9, 0x440($t8)
    MEM_W(0X440, ctx->r24) = ctx->r25;
    // 0x80085FCC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80085FD0: nop

    // 0x80085FD4: lw          $a0, 0x420($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X420);
    // 0x80085FD8: jal         0x8007E03C
    // 0x80085FDC: nop

    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80085FDC: nop

    after_1:
    // 0x80085FE0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80085FE4: jal         0x8007E4A4
    // 0x80085FE8: sw          $v0, 0x44C($t1)
    MEM_W(0X44C, ctx->r9) = ctx->r2;
    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_2;
    // 0x80085FE8: sw          $v0, 0x44C($t1)
    MEM_W(0X44C, ctx->r9) = ctx->r2;
    after_2:
    // 0x80085FEC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80085FF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80085FF4: lw          $t3, 0x420($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X420);
    // 0x80085FF8: lw          $t4, 0x44C($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X44C);
    // 0x80085FFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80086000: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80086004: addiu       $a1, $a1, -0x974
    ctx->r5 = ADD32(ctx->r5, -0X974);
    // 0x80086008: addiu       $a0, $a0, -0x9B0
    ctx->r4 = ADD32(ctx->r4, -0X9B0);
    // 0x8008600C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80086010: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80086014: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x80086018: jal         0x800B3BFC
    // 0x8008601C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8008601C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x80086020: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80086024: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80086028: lw          $t6, 0x44C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X44C);
    // 0x8008602C: addiu       $a0, $a0, -0x964
    ctx->r4 = ADD32(ctx->r4, -0X964);
    // 0x80086030: sw          $t6, 0x448($t5)
    MEM_W(0X448, ctx->r13) = ctx->r14;
    // 0x80086034: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80086038: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8008603C: lbu         $t9, 0x41D($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X41D);
    // 0x80086040: nop

    // 0x80086044: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x80086048: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8008604C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80086050: lbu         $t2, 0x2($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2);
    // 0x80086054: lbu         $t5, 0x1($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X1);
    // 0x80086058: lbu         $t3, 0x3($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X3);
    // 0x8008605C: lbu         $t0, 0x0($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X0);
    // 0x80086060: sll         $t4, $t2, 8
    ctx->r12 = S32(ctx->r10 << 8);
    // 0x80086064: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x80086068: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8008606C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80086070: sll         $t2, $t0, 24
    ctx->r10 = S32(ctx->r8 << 24);
    // 0x80086074: addu        $t3, $t2, $t8
    ctx->r11 = ADD32(ctx->r10, ctx->r24);
    // 0x80086078: sw          $t3, 0x450($t7)
    MEM_W(0X450, ctx->r15) = ctx->r11;
    // 0x8008607C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80086080: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80086084: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x80086088: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8008608C: lw          $t9, 0x44C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X44C);
    // 0x80086090: nop

    // 0x80086094: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80086098: lw          $t1, 0x420($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X420);
    // 0x8008609C: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800860A0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800860A4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800860A8: jal         0x800B3BFC
    // 0x800860AC: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_4;
    // 0x800860AC: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_4:
    // 0x800860B0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800860B4: nop

    // 0x800860B8: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x800860BC: addiu       $t2, $t0, -0x1
    ctx->r10 = ADD32(ctx->r8, -0X1);
    // 0x800860C0: beq         $s0, $zero, L_80086108
    if (ctx->r16 == 0) {
        // 0x800860C4: sw          $t2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r10;
            goto L_80086108;
    }
    // 0x800860C4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_800860C8:
    // 0x800860C8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800860CC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800860D0: lb          $t3, 0x0($t8)
    ctx->r11 = MEM_B(ctx->r24, 0X0);
    // 0x800860D4: nop

    // 0x800860D8: sb          $t3, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r11;
    // 0x800860DC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800860E0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800860E4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800860E8: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x800860EC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800860F0: addiu       $t1, $t6, 0x1
    ctx->r9 = ADD32(ctx->r14, 0X1);
    // 0x800860F4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800860F8: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800860FC: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80086100: bne         $s0, $zero, L_800860C8
    if (ctx->r16 != 0) {
        // 0x80086104: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_800860C8;
    }
    // 0x80086104: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80086108:
    // 0x80086108: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8008610C: nop

    // 0x80086110: lw          $a0, 0x44C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X44C);
    // 0x80086114: jal         0x8008EFA0
    // 0x80086118: addiu       $a1, $t2, 0x458
    ctx->r5 = ADD32(ctx->r10, 0X458);
    Dcm_InitDecoder(rdram, ctx);
        goto after_5;
    // 0x80086118: addiu       $a1, $t2, 0x458
    ctx->r5 = ADD32(ctx->r10, 0X458);
    after_5:
    // 0x8008611C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80086120: jal         0x8008756C
    // 0x80086124: nop

    Audio2_FillDecodeBuffer(rdram, ctx);
        goto after_6;
    // 0x80086124: nop

    after_6:
    // 0x80086128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008612C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80086130: jr          $ra
    // 0x80086134: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80086134: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Audio2_InitSongPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086138: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008613C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80086140: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80086144: lbu         $t7, 0x4F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4F);
    // 0x80086148: sw          $zero, 0x3B3C($at)
    MEM_W(0X3B3C, ctx->r1) = 0;
    // 0x8008614C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80086150: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80086154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80086158: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8008615C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80086160: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80086164: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80086168: sh          $t6, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r14;
    // 0x8008616C: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
    // 0x80086170: bne         $t7, $at, L_800861E4
    if (ctx->r15 != ctx->r1) {
        // 0x80086174: sb          $zero, 0x2C($sp)
        MEM_B(0X2C, ctx->r29) = 0;
            goto L_800861E4;
    }
    // 0x80086174: sb          $zero, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = 0;
    // 0x80086178: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_8008617C:
    // 0x8008617C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80086180: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80086184: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80086188: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8008618C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80086190: lw          $t9, 0x43C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X43C);
    // 0x80086194: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80086198: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008619C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800861A0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800861A4: lbu         $t3, 0x27($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X27);
    // 0x800861A8: nop

    // 0x800861AC: beq         $t3, $zero, L_800861CC
    if (ctx->r11 == 0) {
        // 0x800861B0: nop
    
            goto L_800861CC;
    }
    // 0x800861B0: nop

    // 0x800861B4: sb          $zero, 0x27($t2)
    MEM_B(0X27, ctx->r10) = 0;
    // 0x800861B8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800861BC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800861C0: lw          $a0, 0x14($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X14);
    // 0x800861C4: jal         0x800B8B60
    // 0x800861C8: nop

    alSynStopVoice(rdram, ctx);
        goto after_0;
    // 0x800861C8: nop

    after_0:
L_800861CC:
    // 0x800861CC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800861D0: nop

    // 0x800861D4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800861D8: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x800861DC: bne         $at, $zero, L_8008617C
    if (ctx->r1 != 0) {
        // 0x800861E0: sw          $t6, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r14;
            goto L_8008617C;
    }
    // 0x800861E0: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_800861E4:
    // 0x800861E4: lbu         $t7, 0x4F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4F);
    // 0x800861E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800861EC: bne         $t7, $at, L_80086254
    if (ctx->r15 != ctx->r1) {
        // 0x800861F0: nop
    
            goto L_80086254;
    }
    // 0x800861F0: nop

    // 0x800861F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800861F8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800861FC: addiu       $a1, $a1, -0x7308
    ctx->r5 = ADD32(ctx->r5, -0X7308);
    // 0x80086200: addiu       $a0, $a0, -0x7320
    ctx->r4 = ADD32(ctx->r4, -0X7320);
    // 0x80086204: jal         0x800B3080
    // 0x80086208: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80086208: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x8008620C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80086210: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80086214: addiu       $a1, $a1, -0x72D0
    ctx->r5 = ADD32(ctx->r5, -0X72D0);
    // 0x80086218: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x8008621C: jal         0x800B3080
    // 0x80086220: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80086220: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80086224: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80086228: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8008622C: addiu       $a1, $a1, -0x7308
    ctx->r5 = ADD32(ctx->r5, -0X7308);
    // 0x80086230: addiu       $a0, $a0, -0x72B0
    ctx->r4 = ADD32(ctx->r4, -0X72B0);
    // 0x80086234: jal         0x800B3080
    // 0x80086238: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x80086238: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x8008623C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80086240: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80086244: addiu       $a1, $a1, -0x72D0
    ctx->r5 = ADD32(ctx->r5, -0X72D0);
    // 0x80086248: addiu       $a0, $a0, -0x7278
    ctx->r4 = ADD32(ctx->r4, -0X7278);
    // 0x8008624C: jal         0x800B3080
    // 0x80086250: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x80086250: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
L_80086254:
    // 0x80086254: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80086258: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8008625C: jal         0x8008BF58
    // 0x80086260: addiu       $a1, $a1, 0x418
    ctx->r5 = ADD32(ctx->r5, 0X418);
    Audio2_ParseSFXHeader(rdram, ctx);
        goto after_5;
    // 0x80086260: addiu       $a1, $a1, 0x418
    ctx->r5 = ADD32(ctx->r5, 0X418);
    after_5:
    // 0x80086264: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80086268: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008626C: addiu       $t0, $t8, 0xE
    ctx->r8 = ADD32(ctx->r24, 0XE);
    // 0x80086270: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80086274: lbu         $t1, 0x41C($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X41C);
    // 0x80086278: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008627C: sw          $t1, 0x440($t9)
    MEM_W(0X440, ctx->r25) = ctx->r9;
    // 0x80086280: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80086284: addiu       $a0, $a0, -0x940
    ctx->r4 = ADD32(ctx->r4, -0X940);
    // 0x80086288: lbu         $a1, 0x41C($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X41C);
    // 0x8008628C: jal         0x800B3BFC
    // 0x80086290: nop

    rmonPrintf_recomp(rdram, ctx);
        goto after_6;
    // 0x80086290: nop

    after_6:
    // 0x80086294: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80086298: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8008629C: lw          $t4, 0x1590($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X1590);
    // 0x800862A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800862A4: sw          $t4, 0x1574($t2)
    MEM_W(0X1574, ctx->r10) = ctx->r12;
    // 0x800862A8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800862AC: addiu       $a0, $a0, -0x924
    ctx->r4 = ADD32(ctx->r4, -0X924);
    // 0x800862B0: lw          $t6, 0x1574($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1574);
    // 0x800862B4: nop

    // 0x800862B8: sw          $t6, 0x444($t5)
    MEM_W(0X444, ctx->r13) = ctx->r14;
    // 0x800862BC: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800862C0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800862C4: lw          $t8, 0x444($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X444);
    // 0x800862C8: nop

    // 0x800862CC: sw          $t8, 0x448($t7)
    MEM_W(0X448, ctx->r15) = ctx->r24;
    // 0x800862D0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800862D4: nop

    // 0x800862D8: lw          $t9, 0x420($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X420);
    // 0x800862DC: lw          $t1, 0x1574($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1574);
    // 0x800862E0: addiu       $t3, $t9, 0xF
    ctx->r11 = ADD32(ctx->r25, 0XF);
    // 0x800862E4: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800862E8: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x800862EC: sw          $t2, 0x1574($t0)
    MEM_W(0X1574, ctx->r8) = ctx->r10;
    // 0x800862F0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800862F4: lw          $t6, 0x3B3C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3B3C);
    // 0x800862F8: lw          $t8, 0x420($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X420);
    // 0x800862FC: nop

    // 0x80086300: addiu       $t7, $t8, 0xF
    ctx->r15 = ADD32(ctx->r24, 0XF);
    // 0x80086304: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80086308: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008630C: addu        $t3, $t6, $t9
    ctx->r11 = ADD32(ctx->r14, ctx->r25);
    // 0x80086310: sw          $t3, 0x3B3C($at)
    MEM_W(0X3B3C, ctx->r1) = ctx->r11;
    // 0x80086314: lw          $t1, 0x420($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X420);
    // 0x80086318: nop

    // 0x8008631C: addiu       $t4, $t1, -0x4
    ctx->r12 = ADD32(ctx->r9, -0X4);
    // 0x80086320: sw          $t4, 0x420($t5)
    MEM_W(0X420, ctx->r13) = ctx->r12;
    // 0x80086324: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80086328: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8008632C: lbu         $t0, 0x41D($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X41D);
    // 0x80086330: nop

    // 0x80086334: sll         $t8, $t0, 4
    ctx->r24 = S32(ctx->r8 << 4);
    // 0x80086338: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8008633C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80086340: lbu         $t3, 0x2($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X2);
    // 0x80086344: lbu         $t5, 0x1($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X1);
    // 0x80086348: lbu         $t9, 0x3($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X3);
    // 0x8008634C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80086350: sll         $t1, $t3, 8
    ctx->r9 = S32(ctx->r11 << 8);
    // 0x80086354: sll         $t0, $t5, 16
    ctx->r8 = S32(ctx->r13 << 16);
    // 0x80086358: addu        $t4, $t9, $t1
    ctx->r12 = ADD32(ctx->r25, ctx->r9);
    // 0x8008635C: addu        $t8, $t4, $t0
    ctx->r24 = ADD32(ctx->r12, ctx->r8);
    // 0x80086360: sll         $t3, $t7, 24
    ctx->r11 = S32(ctx->r15 << 24);
    // 0x80086364: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x80086368: sw          $t9, 0x450($t2)
    MEM_W(0X450, ctx->r10) = ctx->r25;
    // 0x8008636C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80086370: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80086374: addiu       $t5, $t1, 0x4
    ctx->r13 = ADD32(ctx->r9, 0X4);
    // 0x80086378: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8008637C: lw          $t0, 0x444($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X444);
    // 0x80086380: nop

    // 0x80086384: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80086388: lw          $t6, 0x420($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X420);
    // 0x8008638C: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x80086390: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80086394: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80086398: jal         0x800B3BFC
    // 0x8008639C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_7;
    // 0x8008639C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_7:
    // 0x800863A0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800863A4: nop

    // 0x800863A8: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800863AC: addiu       $t3, $t7, -0x1
    ctx->r11 = ADD32(ctx->r15, -0X1);
    // 0x800863B0: beq         $s0, $zero, L_800863F8
    if (ctx->r16 == 0) {
        // 0x800863B4: sw          $t3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r11;
            goto L_800863F8;
    }
    // 0x800863B4: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
L_800863B8:
    // 0x800863B8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800863BC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800863C0: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x800863C4: nop

    // 0x800863C8: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    // 0x800863CC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800863D0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800863D4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800863D8: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x800863DC: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x800863E0: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800863E4: addiu       $t5, $t1, 0x1
    ctx->r13 = ADD32(ctx->r9, 0X1);
    // 0x800863E8: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x800863EC: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800863F0: bne         $s0, $zero, L_800863B8
    if (ctx->r16 != 0) {
        // 0x800863F4: sw          $t7, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r15;
            goto L_800863B8;
    }
    // 0x800863F4: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
L_800863F8:
    // 0x800863F8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800863FC: nop

    // 0x80086400: lw          $a0, 0x444($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X444);
    // 0x80086404: jal         0x8008EFA0
    // 0x80086408: addiu       $a1, $t3, 0x458
    ctx->r5 = ADD32(ctx->r11, 0X458);
    Dcm_InitDecoder(rdram, ctx);
        goto after_8;
    // 0x80086408: addiu       $a1, $t3, 0x458
    ctx->r5 = ADD32(ctx->r11, 0X458);
    after_8:
    // 0x8008640C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80086410: jal         0x8008756C
    // 0x80086414: nop

    Audio2_FillDecodeBuffer(rdram, ctx);
        goto after_9;
    // 0x80086414: nop

    after_9:
    // 0x80086418: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008641C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80086420: lbu         $t9, 0x41D($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X41D);
    // 0x80086424: nop

    // 0x80086428: blez        $t9, L_8008647C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8008642C: nop
    
            goto L_8008647C;
    }
    // 0x8008642C: nop

L_80086430:
    // 0x80086430: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80086434: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80086438: sll         $t5, $t1, 4
    ctx->r13 = S32(ctx->r9 << 4);
    // 0x8008643C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80086440: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    // 0x80086444: jal         0x8008C014
    // 0x80086448: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    Audio2_ParseSoundRecord(rdram, ctx);
        goto after_10;
    // 0x80086448: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_10:
    // 0x8008644C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80086450: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80086454: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80086458: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x8008645C: addiu       $t6, $t4, 0x10
    ctx->r14 = ADD32(ctx->r12, 0X10);
    // 0x80086460: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80086464: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80086468: lbu         $t8, 0x41D($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X41D);
    // 0x8008646C: nop

    // 0x80086470: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80086474: bne         $at, $zero, L_80086430
    if (ctx->r1 != 0) {
        // 0x80086478: nop
    
            goto L_80086430;
    }
    // 0x80086478: nop

L_8008647C:
    // 0x8008647C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80086480: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80086484: sb          $zero, 0x1572($t9)
    MEM_B(0X1572, ctx->r25) = 0;
    // 0x80086488: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8008648C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80086490: sb          $t1, 0x1570($t2)
    MEM_B(0X1570, ctx->r10) = ctx->r9;
    // 0x80086494: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80086498: nop

    // 0x8008649C: sb          $t5, 0x1571($t4)
    MEM_B(0X1571, ctx->r12) = ctx->r13;
    // 0x800864A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800864A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800864A8: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x800864AC: jr          $ra
    // 0x800864B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800864B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

RECOMP_FUNC void Audio2_AllocDcmScratch8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864B4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800864B8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800864BC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800864C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800864C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800864C8: lbu         $t7, 0x1570($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1570);
    // 0x800864CC: nop

    // 0x800864D0: beq         $t7, $zero, L_80087468
    if (ctx->r15 == 0) {
        // 0x800864D4: nop
    
            goto L_80087468;
    }
    // 0x800864D4: nop

    // 0x800864D8: lbu         $t8, 0x1571($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1571);
    // 0x800864DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800864E0: beq         $t8, $at, L_800864F4
    if (ctx->r24 == ctx->r1) {
        // 0x800864E4: nop
    
            goto L_800864F4;
    }
    // 0x800864E4: nop

    // 0x800864E8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800864EC: b           L_80087468
    // 0x800864F0: sb          $t9, 0x1571($t6)
    MEM_B(0X1571, ctx->r14) = ctx->r25;
        goto L_80087468;
    // 0x800864F0: sb          $t9, 0x1571($t6)
    MEM_B(0X1571, ctx->r14) = ctx->r25;
L_800864F4:
    // 0x800864F4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800864F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800864FC: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80086500: sb          $t0, 0x1571($t1)
    MEM_B(0X1571, ctx->r9) = ctx->r8;
    // 0x80086504: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80086508: ori         $t2, $t2, 0x400
    ctx->r10 = ctx->r10 | 0X400;
    // 0x8008650C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80086510: lbu         $t4, 0x1572($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1572);
    // 0x80086514: nop

    // 0x80086518: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8008651C: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80086520: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x80086524: lhu         $t8, 0x24($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X24);
    // 0x80086528: nop

    // 0x8008652C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80086530: beq         $t9, $zero, L_80086B8C
    if (ctx->r25 == 0) {
        // 0x80086534: nop
    
            goto L_80086B8C;
    }
    // 0x80086534: nop

    // 0x80086538: lw          $a0, 0x18($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X18);
    // 0x8008653C: nop

    // 0x80086540: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80086544: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80086548: jal         0x8007E03C
    // 0x8008654C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8008654C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x80086550: jal         0x8007E4A4
    // 0x80086554: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_1;
    // 0x80086554: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x80086558: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8008655C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80086560: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80086564: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x80086568: lw          $t3, 0x18($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X18);
    // 0x8008656C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80086570: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80086574: addiu       $t8, $t5, 0x20
    ctx->r24 = ADD32(ctx->r13, 0X20);
    // 0x80086578: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008657C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80086580: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80086584: addiu       $a1, $a1, -0x8C4
    ctx->r5 = ADD32(ctx->r5, -0X8C4);
    // 0x80086588: addiu       $a0, $a0, -0x900
    ctx->r4 = ADD32(ctx->r4, -0X900);
    // 0x8008658C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80086590: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80086594: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80086598: jal         0x800B3BFC
    // 0x8008659C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8008659C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_2:
    // 0x800865A0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800865A4: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800865A8: sll         $t1, $t6, 4
    ctx->r9 = S32(ctx->r14 << 4);
    // 0x800865AC: addu        $t0, $t7, $t1
    ctx->r8 = ADD32(ctx->r15, ctx->r9);
    // 0x800865B0: lhu         $a1, 0x26($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X26);
    // 0x800865B4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800865B8: jal         0x80087478
    // 0x800865BC: nop

    Audio2_DecodeFixedSprite(rdram, ctx);
        goto after_3;
    // 0x800865BC: nop

    after_3:
    // 0x800865C0: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800865C4: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800865C8: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800865CC: lw          $t3, 0x438($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X438);
    // 0x800865D0: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x800865D4: lw          $t4, 0x1574($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X1574);
    // 0x800865D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800865DC: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x800865E0: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x800865E4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800865E8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800865EC: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x800865F0: lw          $t7, 0x438($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X438);
    // 0x800865F4: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800865F8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800865FC: addu        $t2, $t7, $t0
    ctx->r10 = ADD32(ctx->r15, ctx->r8);
    // 0x80086600: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80086604: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80086608: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x8008660C: sw          $t5, 0x528($t8)
    MEM_W(0X528, ctx->r24) = ctx->r13;
    // 0x80086610: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80086614: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80086618: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8008661C: addu        $t0, $t4, $t6
    ctx->r8 = ADD32(ctx->r12, ctx->r14);
    // 0x80086620: lhu         $t2, 0x24($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X24);
    // 0x80086624: nop

    // 0x80086628: andi        $t1, $t2, 0x4
    ctx->r9 = ctx->r10 & 0X4;
    // 0x8008662C: beq         $t1, $zero, L_8008668C
    if (ctx->r9 == 0) {
        // 0x80086630: nop
    
            goto L_8008668C;
    }
    // 0x80086630: nop

    // 0x80086634: lw          $t7, 0x18($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X18);
    // 0x80086638: lw          $t9, 0x1574($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X1574);
    // 0x8008663C: sll         $t3, $t7, 1
    ctx->r11 = S32(ctx->r15 << 1);
    // 0x80086640: addiu       $t5, $t3, 0x2F
    ctx->r13 = ADD32(ctx->r11, 0X2F);
    // 0x80086644: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80086648: and         $t8, $t5, $at
    ctx->r24 = ctx->r13 & ctx->r1;
    // 0x8008664C: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80086650: sw          $t6, 0x1574($t4)
    MEM_W(0X1574, ctx->r12) = ctx->r14;
    // 0x80086654: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80086658: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8008665C: sll         $t0, $t1, 4
    ctx->r8 = S32(ctx->r9 << 4);
    // 0x80086660: addu        $t7, $t2, $t0
    ctx->r15 = ADD32(ctx->r10, ctx->r8);
    // 0x80086664: lw          $t3, 0x18($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X18);
    // 0x80086668: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8008666C: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80086670: addiu       $t9, $t5, 0x2F
    ctx->r25 = ADD32(ctx->r13, 0X2F);
    // 0x80086674: lw          $t6, 0x3B3C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3B3C);
    // 0x80086678: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8008667C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80086680: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x80086684: b           L_800866E8
    // 0x80086688: sw          $t4, 0x3B3C($at)
    MEM_W(0X3B3C, ctx->r1) = ctx->r12;
        goto L_800866E8;
    // 0x80086688: sw          $t4, 0x3B3C($at)
    MEM_W(0X3B3C, ctx->r1) = ctx->r12;
L_8008668C:
    // 0x8008668C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80086690: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80086694: sll         $t0, $t2, 4
    ctx->r8 = S32(ctx->r10 << 4);
    // 0x80086698: addu        $t7, $t1, $t0
    ctx->r15 = ADD32(ctx->r9, ctx->r8);
    // 0x8008669C: lw          $t3, 0x18($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X18);
    // 0x800866A0: lw          $t6, 0x1574($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X1574);
    // 0x800866A4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800866A8: addiu       $t5, $t3, 0x2F
    ctx->r13 = ADD32(ctx->r11, 0X2F);
    // 0x800866AC: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x800866B0: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800866B4: sw          $t8, 0x1574($t1)
    MEM_W(0X1574, ctx->r9) = ctx->r24;
    // 0x800866B8: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800866BC: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800866C0: sll         $t0, $t2, 4
    ctx->r8 = S32(ctx->r10 << 4);
    // 0x800866C4: addu        $t7, $t4, $t0
    ctx->r15 = ADD32(ctx->r12, ctx->r8);
    // 0x800866C8: lw          $t3, 0x18($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X18);
    // 0x800866CC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800866D0: addiu       $t5, $t3, 0x2F
    ctx->r13 = ADD32(ctx->r11, 0X2F);
    // 0x800866D4: lw          $t9, 0x3B3C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3B3C);
    // 0x800866D8: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800866DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800866E0: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800866E4: sw          $t8, 0x3B3C($at)
    MEM_W(0X3B3C, ctx->r1) = ctx->r24;
L_800866E8:
    // 0x800866E8: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800866EC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800866F0: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x800866F4: addu        $t0, $t1, $t4
    ctx->r8 = ADD32(ctx->r9, ctx->r12);
    // 0x800866F8: lhu         $t7, 0x24($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X24);
    // 0x800866FC: nop

    // 0x80086700: andi        $t3, $t7, 0x4
    ctx->r11 = ctx->r15 & 0X4;
    // 0x80086704: beq         $t3, $zero, L_8008697C
    if (ctx->r11 == 0) {
        // 0x80086708: nop
    
            goto L_8008697C;
    }
    // 0x80086708: nop

    // 0x8008670C: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x80086710: lw          $t5, 0x18($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X18);
    // 0x80086714: lw          $t6, 0x438($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X438);
    // 0x80086718: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8008671C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086720: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x80086724: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x80086728: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8008672C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80086730: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80086734: sll         $t0, $t3, 4
    ctx->r8 = S32(ctx->r11 << 4);
    // 0x80086738: addu        $t5, $t7, $t0
    ctx->r13 = ADD32(ctx->r15, ctx->r8);
    // 0x8008673C: lw          $t1, 0x18($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X18);
    // 0x80086740: lw          $t6, 0x438($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X438);
    // 0x80086744: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80086748: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8008674C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80086750: sw          $t2, 0x630($t9)
    MEM_W(0X630, ctx->r25) = ctx->r10;
    // 0x80086754: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80086758: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8008675C: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x80086760: lw          $t5, 0x438($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X438);
    // 0x80086764: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x80086768: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008676C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80086770: addu        $t3, $t5, $t7
    ctx->r11 = ADD32(ctx->r13, ctx->r15);
    // 0x80086774: sb          $t4, 0x8($t3)
    MEM_B(0X8, ctx->r11) = ctx->r12;
    // 0x80086778: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8008677C: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80086780: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80086784: lw          $t2, 0x438($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X438);
    // 0x80086788: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8008678C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80086790: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80086794: addu        $t1, $t2, $t0
    ctx->r9 = ADD32(ctx->r10, ctx->r8);
    // 0x80086798: sb          $t6, 0x9($t1)
    MEM_B(0X9, ctx->r9) = ctx->r14;
    // 0x8008679C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800867A0: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800867A4: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800867A8: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800867AC: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x800867B0: lw          $t4, 0x438($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X438);
    // 0x800867B4: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x800867B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800867BC: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800867C0: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x800867C4: sll         $t0, $t3, 4
    ctx->r8 = S32(ctx->r11 << 4);
    // 0x800867C8: addu        $t6, $t7, $t0
    ctx->r14 = ADD32(ctx->r15, ctx->r8);
    // 0x800867CC: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800867D0: lw          $t1, 0x18($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X18);
    // 0x800867D4: nop

    // 0x800867D8: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x800867DC: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x800867E0: addiu       $t5, $t1, -0x1
    ctx->r13 = ADD32(ctx->r9, -0X1);
    // 0x800867E4: beq         $s0, $zero, L_8008683C
    if (ctx->r16 == 0) {
        // 0x800867E8: sw          $t5, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r13;
            goto L_8008683C;
    }
    // 0x800867E8: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
L_800867EC:
    // 0x800867EC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800867F0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800867F4: lb          $t2, 0x1($t4)
    ctx->r10 = MEM_B(ctx->r12, 0X1);
    // 0x800867F8: lb          $t8, 0x0($t4)
    ctx->r24 = MEM_B(ctx->r12, 0X0);
    // 0x800867FC: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80086800: andi        $t7, $t3, 0xFF00
    ctx->r15 = ctx->r11 & 0XFF00;
    // 0x80086804: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80086808: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x8008680C: sh          $t0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r8;
    // 0x80086810: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80086814: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80086818: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8008681C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80086820: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80086824: addiu       $t5, $t1, 0x2
    ctx->r13 = ADD32(ctx->r9, 0X2);
    // 0x80086828: addiu       $t4, $t8, 0x2
    ctx->r12 = ADD32(ctx->r24, 0X2);
    // 0x8008682C: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80086830: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x80086834: bne         $s0, $zero, L_800867EC
    if (ctx->r16 != 0) {
        // 0x80086838: sw          $t3, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r11;
            goto L_800867EC;
    }
    // 0x80086838: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
L_8008683C:
    // 0x8008683C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80086840: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80086844: sll         $t0, $t7, 4
    ctx->r8 = S32(ctx->r15 << 4);
    // 0x80086848: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x8008684C: lhu         $t1, 0x24($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X24);
    // 0x80086850: nop

    // 0x80086854: andi        $t5, $t1, 0x4
    ctx->r13 = ctx->r9 & 0X4;
    // 0x80086858: beq         $t5, $zero, L_80086B50
    if (ctx->r13 == 0) {
        // 0x8008685C: nop
    
            goto L_80086B50;
    }
    // 0x8008685C: nop

    // 0x80086860: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80086864: lw          $t8, 0x438($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X438);
    // 0x80086868: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x8008686C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80086870: addu        $t2, $t8, $t4
    ctx->r10 = ADD32(ctx->r24, ctx->r12);
    // 0x80086874: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80086878: nop

    // 0x8008687C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80086880: lw          $t0, 0x438($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X438);
    // 0x80086884: nop

    // 0x80086888: addu        $t1, $t0, $t4
    ctx->r9 = ADD32(ctx->r8, ctx->r12);
    // 0x8008688C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80086890: nop

    // 0x80086894: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80086898: lhu         $t7, 0x24($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X24);
    // 0x8008689C: nop

    // 0x800868A0: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x800868A4: beq         $t8, $zero, L_80086914
    if (ctx->r24 == 0) {
        // 0x800868A8: nop
    
            goto L_80086914;
    }
    // 0x800868A8: nop

    // 0x800868AC: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_800868B0:
    // 0x800868B0: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800868B4: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800868B8: sll         $t9, $t3, 4
    ctx->r25 = S32(ctx->r11 << 4);
    // 0x800868BC: addu        $t0, $t2, $t9
    ctx->r8 = ADD32(ctx->r10, ctx->r25);
    // 0x800868C0: lw          $t4, 0x1C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X1C);
    // 0x800868C4: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800868C8: lw          $t2, 0x20($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X20);
    // 0x800868CC: subu        $t5, $t4, $t1
    ctx->r13 = SUB32(ctx->r12, ctx->r9);
    // 0x800868D0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800868D4: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800868D8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800868DC: addu        $t9, $t2, $t1
    ctx->r25 = ADD32(ctx->r10, ctx->r9);
    // 0x800868E0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800868E4: lh          $t3, -0x2($t8)
    ctx->r11 = MEM_H(ctx->r24, -0X2);
    // 0x800868E8: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800868EC: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x800868F0: sh          $t3, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r11;
    // 0x800868F4: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800868F8: nop

    // 0x800868FC: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80086900: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x80086904: bne         $at, $zero, L_800868B0
    if (ctx->r1 != 0) {
        // 0x80086908: sw          $t8, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r24;
            goto L_800868B0;
    }
    // 0x80086908: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x8008690C: b           L_80086B50
    // 0x80086910: nop

        goto L_80086B50;
    // 0x80086910: nop

L_80086914:
    // 0x80086914: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_80086918:
    // 0x80086918: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8008691C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80086920: sll         $t1, $t2, 4
    ctx->r9 = S32(ctx->r10 << 4);
    // 0x80086924: addu        $t9, $t0, $t1
    ctx->r25 = ADD32(ctx->r8, ctx->r9);
    // 0x80086928: lw          $t5, 0x1C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X1C);
    // 0x8008692C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80086930: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x80086934: addu        $t3, $t5, $t4
    ctx->r11 = ADD32(ctx->r13, ctx->r12);
    // 0x80086938: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8008693C: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x80086940: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80086944: addu        $t1, $t0, $t4
    ctx->r9 = ADD32(ctx->r8, ctx->r12);
    // 0x80086948: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8008694C: lh          $t2, 0x0($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X0);
    // 0x80086950: sll         $t5, $t1, 1
    ctx->r13 = S32(ctx->r9 << 1);
    // 0x80086954: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80086958: sh          $t2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r10;
    // 0x8008695C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80086960: nop

    // 0x80086964: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80086968: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x8008696C: bne         $at, $zero, L_80086918
    if (ctx->r1 != 0) {
        // 0x80086970: sw          $t8, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r24;
            goto L_80086918;
    }
    // 0x80086970: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x80086974: b           L_80086B50
    // 0x80086978: nop

        goto L_80086B50;
    // 0x80086978: nop

L_8008697C:
    // 0x8008697C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80086980: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80086984: sll         $t4, $t0, 4
    ctx->r12 = S32(ctx->r8 << 4);
    // 0x80086988: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8008698C: lw          $t5, 0x438($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X438);
    // 0x80086990: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80086994: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x80086998: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x8008699C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800869A0: addu        $t6, $t5, $t2
    ctx->r14 = ADD32(ctx->r13, ctx->r10);
    // 0x800869A4: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x800869A8: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800869AC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800869B0: sll         $t4, $t8, 4
    ctx->r12 = S32(ctx->r24 << 4);
    // 0x800869B4: lw          $t0, 0x438($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X438);
    // 0x800869B8: addu        $t1, $t7, $t4
    ctx->r9 = ADD32(ctx->r15, ctx->r12);
    // 0x800869BC: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x800869C0: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x800869C4: addu        $t2, $t0, $t5
    ctx->r10 = ADD32(ctx->r8, ctx->r13);
    // 0x800869C8: sw          $t9, 0x630($t2)
    MEM_W(0X630, ctx->r10) = ctx->r25;
    // 0x800869CC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800869D0: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800869D4: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x800869D8: lw          $t4, 0x438($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X438);
    // 0x800869DC: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x800869E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800869E4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800869E8: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x800869EC: sb          $t3, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r11;
    // 0x800869F0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800869F4: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800869F8: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x800869FC: lw          $t9, 0x438($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X438);
    // 0x80086A00: addu        $t6, $t6, $t2
    ctx->r14 = ADD32(ctx->r14, ctx->r10);
    // 0x80086A04: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80086A08: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80086A0C: addu        $t1, $t9, $t6
    ctx->r9 = ADD32(ctx->r25, ctx->r14);
    // 0x80086A10: sb          $t0, 0x9($t1)
    MEM_B(0X9, ctx->r9) = ctx->r8;
    // 0x80086A14: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80086A18: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80086A1C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80086A20: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x80086A24: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80086A28: lw          $t3, 0x438($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X438);
    // 0x80086A2C: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x80086A30: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80086A34: addu        $t2, $t3, $t5
    ctx->r10 = ADD32(ctx->r11, ctx->r13);
    // 0x80086A38: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80086A3C: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x80086A40: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x80086A44: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80086A48: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x80086A4C: nop

    // 0x80086A50: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80086A54: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80086A58: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x80086A5C: beq         $s0, $zero, L_80086AA8
    if (ctx->r16 == 0) {
        // 0x80086A60: sw          $t4, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r12;
            goto L_80086AA8;
    }
    // 0x80086A60: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
L_80086A64:
    // 0x80086A64: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80086A68: jal         0x8008C0E0
    // 0x80086A6C: nop

    Audio2_ReadS16LE(rdram, ctx);
        goto after_4;
    // 0x80086A6C: nop

    after_4:
    // 0x80086A70: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80086A74: sra         $t3, $v0, 8
    ctx->r11 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80086A78: sb          $t3, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r11;
    // 0x80086A7C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80086A80: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80086A84: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80086A88: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80086A8C: addiu       $t0, $t6, -0x1
    ctx->r8 = ADD32(ctx->r14, -0X1);
    // 0x80086A90: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x80086A94: addiu       $t7, $t8, 0x2
    ctx->r15 = ADD32(ctx->r24, 0X2);
    // 0x80086A98: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80086A9C: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80086AA0: bne         $s0, $zero, L_80086A64
    if (ctx->r16 != 0) {
        // 0x80086AA4: sw          $t0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r8;
            goto L_80086A64;
    }
    // 0x80086AA4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
L_80086AA8:
    // 0x80086AA8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80086AAC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80086AB0: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80086AB4: lw          $t4, 0x438($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X438);
    // 0x80086AB8: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80086ABC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80086AC0: addu        $t2, $t4, $t5
    ctx->r10 = ADD32(ctx->r12, ctx->r13);
    // 0x80086AC4: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80086AC8: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x80086ACC: addu        $t7, $t1, $t8
    ctx->r15 = ADD32(ctx->r9, ctx->r24);
    // 0x80086AD0: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80086AD4: lw          $t6, 0x18($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X18);
    // 0x80086AD8: nop

    // 0x80086ADC: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80086AE0: lb          $t4, 0x0($t0)
    ctx->r12 = MEM_B(ctx->r8, 0X0);
    // 0x80086AE4: sb          $zero, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = 0;
    // 0x80086AE8: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x80086AEC: sb          $t5, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r13;
    // 0x80086AF0: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_80086AF4:
    // 0x80086AF4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80086AF8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80086AFC: sll         $t1, $t3, 4
    ctx->r9 = S32(ctx->r11 << 4);
    // 0x80086B00: addu        $t8, $t2, $t1
    ctx->r24 = ADD32(ctx->r10, ctx->r9);
    // 0x80086B04: lw          $t7, 0x18($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X18);
    // 0x80086B08: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80086B0C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80086B10: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80086B14: lb          $t0, 0x0($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X0);
    // 0x80086B18: lbu         $t4, 0x2F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2F);
    // 0x80086B1C: addu        $t2, $t3, $t7
    ctx->r10 = ADD32(ctx->r11, ctx->r15);
    // 0x80086B20: addu        $t1, $t6, $t2
    ctx->r9 = ADD32(ctx->r14, ctx->r10);
    // 0x80086B24: subu        $t5, $t0, $t4
    ctx->r13 = SUB32(ctx->r8, ctx->r12);
    // 0x80086B28: sb          $t5, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r13;
    // 0x80086B2C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80086B30: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x80086B34: lbu         $t9, 0x2E($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2E);
    // 0x80086B38: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80086B3C: slti        $at, $t3, 0x10
    ctx->r1 = SIGNED(ctx->r11) < 0X10 ? 1 : 0;
    // 0x80086B40: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80086B44: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x80086B48: bne         $at, $zero, L_80086AF4
    if (ctx->r1 != 0) {
        // 0x80086B4C: sb          $t0, 0x2F($sp)
        MEM_B(0X2F, ctx->r29) = ctx->r8;
            goto L_80086AF4;
    }
    // 0x80086B4C: sb          $t0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r8;
L_80086B50:
    // 0x80086B50: jal         0x8007E4A4
    // 0x80086B54: nop

    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_5;
    // 0x80086B54: nop

    after_5:
    // 0x80086B58: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80086B5C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80086B60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80086B64: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80086B68: addiu       $a1, $a1, -0x880
    ctx->r5 = ADD32(ctx->r5, -0X880);
    // 0x80086B6C: addiu       $a0, $a0, -0x8B0
    ctx->r4 = ADD32(ctx->r4, -0X8B0);
    // 0x80086B70: jal         0x800B3BFC
    // 0x80086B74: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_6;
    // 0x80086B74: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x80086B78: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80086B7C: jal         0x8007E328
    // 0x80086B80: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_7;
    // 0x80086B80: nop

    after_7:
    // 0x80086B84: b           L_800871AC
    // 0x80086B88: nop

        goto L_800871AC;
    // 0x80086B88: nop

L_80086B8C:
    // 0x80086B8C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80086B90: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80086B94: sll         $t2, $t6, 4
    ctx->r10 = S32(ctx->r14 << 4);
    // 0x80086B98: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x80086B9C: lw          $a0, 0x18($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X18);
    // 0x80086BA0: jal         0x8007E03C
    // 0x80086BA4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    n64HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x80086BA4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_8:
    // 0x80086BA8: jal         0x8007E4A4
    // 0x80086BAC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_9;
    // 0x80086BAC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_9:
    // 0x80086BB0: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80086BB4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80086BB8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80086BBC: addu        $t0, $t1, $t9
    ctx->r8 = ADD32(ctx->r9, ctx->r25);
    // 0x80086BC0: lw          $t4, 0x18($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X18);
    // 0x80086BC4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80086BC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80086BCC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80086BD0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80086BD4: addiu       $t3, $t4, 0x20
    ctx->r11 = ADD32(ctx->r12, 0X20);
    // 0x80086BD8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80086BDC: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x80086BE0: addiu       $a1, $a1, -0x830
    ctx->r5 = ADD32(ctx->r5, -0X830);
    // 0x80086BE4: addiu       $a0, $a0, -0x86C
    ctx->r4 = ADD32(ctx->r4, -0X86C);
    // 0x80086BE8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80086BEC: jal         0x800B3BFC
    // 0x80086BF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    rmonPrintf_recomp(rdram, ctx);
        goto after_10;
    // 0x80086BF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_10:
    // 0x80086BF4: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80086BF8: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80086BFC: sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10 << 4);
    // 0x80086C00: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x80086C04: lhu         $a1, 0x26($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X26);
    // 0x80086C08: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80086C0C: jal         0x80087478
    // 0x80086C10: nop

    Audio2_DecodeFixedSprite(rdram, ctx);
        goto after_11;
    // 0x80086C10: nop

    after_11:
    // 0x80086C14: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80086C18: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80086C1C: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80086C20: lw          $t0, 0x438($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X438);
    // 0x80086C24: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x80086C28: lw          $t9, 0x1574($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X1574);
    // 0x80086C2C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80086C30: addu        $t6, $t0, $t3
    ctx->r14 = ADD32(ctx->r8, ctx->r11);
    // 0x80086C34: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80086C38: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80086C3C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80086C40: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80086C44: lw          $t7, 0x438($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X438);
    // 0x80086C48: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x80086C4C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086C50: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x80086C54: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80086C58: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x80086C5C: addu        $t3, $t7, $t0
    ctx->r11 = ADD32(ctx->r15, ctx->r8);
    // 0x80086C60: sw          $t4, 0x528($t3)
    MEM_W(0X528, ctx->r11) = ctx->r12;
    // 0x80086C64: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80086C68: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80086C6C: sll         $t2, $t6, 4
    ctx->r10 = S32(ctx->r14 << 4);
    // 0x80086C70: addu        $t8, $t9, $t2
    ctx->r24 = ADD32(ctx->r25, ctx->r10);
    // 0x80086C74: lhu         $t1, 0x24($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X24);
    // 0x80086C78: nop

    // 0x80086C7C: andi        $t5, $t1, 0x4
    ctx->r13 = ctx->r9 & 0X4;
    // 0x80086C80: beq         $t5, $zero, L_80086CE0
    if (ctx->r13 == 0) {
        // 0x80086C84: nop
    
            goto L_80086CE0;
    }
    // 0x80086C84: nop

    // 0x80086C88: lw          $t7, 0x18($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X18);
    // 0x80086C8C: lw          $t6, 0x1574($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X1574);
    // 0x80086C90: sll         $t0, $t7, 1
    ctx->r8 = S32(ctx->r15 << 1);
    // 0x80086C94: addiu       $t4, $t0, 0x2F
    ctx->r12 = ADD32(ctx->r8, 0X2F);
    // 0x80086C98: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80086C9C: and         $t3, $t4, $at
    ctx->r11 = ctx->r12 & ctx->r1;
    // 0x80086CA0: addu        $t2, $t6, $t3
    ctx->r10 = ADD32(ctx->r14, ctx->r11);
    // 0x80086CA4: sw          $t2, 0x1574($t9)
    MEM_W(0X1574, ctx->r25) = ctx->r10;
    // 0x80086CA8: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80086CAC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80086CB0: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x80086CB4: addu        $t7, $t1, $t8
    ctx->r15 = ADD32(ctx->r9, ctx->r24);
    // 0x80086CB8: lw          $t0, 0x18($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X18);
    // 0x80086CBC: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80086CC0: sll         $t4, $t0, 1
    ctx->r12 = S32(ctx->r8 << 1);
    // 0x80086CC4: addiu       $t6, $t4, 0x2F
    ctx->r14 = ADD32(ctx->r12, 0X2F);
    // 0x80086CC8: lw          $t2, 0x3B3C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3B3C);
    // 0x80086CCC: and         $t3, $t6, $at
    ctx->r11 = ctx->r14 & ctx->r1;
    // 0x80086CD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80086CD4: addu        $t9, $t2, $t3
    ctx->r25 = ADD32(ctx->r10, ctx->r11);
    // 0x80086CD8: b           L_80086D3C
    // 0x80086CDC: sw          $t9, 0x3B3C($at)
    MEM_W(0X3B3C, ctx->r1) = ctx->r25;
        goto L_80086D3C;
    // 0x80086CDC: sw          $t9, 0x3B3C($at)
    MEM_W(0X3B3C, ctx->r1) = ctx->r25;
L_80086CE0:
    // 0x80086CE0: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80086CE4: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80086CE8: sll         $t8, $t1, 4
    ctx->r24 = S32(ctx->r9 << 4);
    // 0x80086CEC: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x80086CF0: lw          $t0, 0x18($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X18);
    // 0x80086CF4: lw          $t2, 0x1574($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X1574);
    // 0x80086CF8: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80086CFC: addiu       $t4, $t0, 0x2F
    ctx->r12 = ADD32(ctx->r8, 0X2F);
    // 0x80086D00: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80086D04: addu        $t3, $t2, $t6
    ctx->r11 = ADD32(ctx->r10, ctx->r14);
    // 0x80086D08: sw          $t3, 0x1574($t5)
    MEM_W(0X1574, ctx->r13) = ctx->r11;
    // 0x80086D0C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80086D10: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80086D14: sll         $t8, $t1, 4
    ctx->r24 = S32(ctx->r9 << 4);
    // 0x80086D18: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x80086D1C: lw          $t0, 0x18($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X18);
    // 0x80086D20: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80086D24: addiu       $t4, $t0, 0x2F
    ctx->r12 = ADD32(ctx->r8, 0X2F);
    // 0x80086D28: lw          $t6, 0x3B3C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3B3C);
    // 0x80086D2C: and         $t2, $t4, $at
    ctx->r10 = ctx->r12 & ctx->r1;
    // 0x80086D30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80086D34: addu        $t3, $t6, $t2
    ctx->r11 = ADD32(ctx->r14, ctx->r10);
    // 0x80086D38: sw          $t3, 0x3B3C($at)
    MEM_W(0X3B3C, ctx->r1) = ctx->r11;
L_80086D3C:
    // 0x80086D3C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80086D40: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80086D44: sll         $t9, $t1, 4
    ctx->r25 = S32(ctx->r9 << 4);
    // 0x80086D48: addu        $t8, $t5, $t9
    ctx->r24 = ADD32(ctx->r13, ctx->r25);
    // 0x80086D4C: lhu         $t7, 0x24($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X24);
    // 0x80086D50: nop

    // 0x80086D54: andi        $t0, $t7, 0x4
    ctx->r8 = ctx->r15 & 0X4;
    // 0x80086D58: beq         $t0, $zero, L_80086FA8
    if (ctx->r8 == 0) {
        // 0x80086D5C: nop
    
            goto L_80086FA8;
    }
    // 0x80086D5C: nop

    // 0x80086D60: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80086D64: lw          $t4, 0x18($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X18);
    // 0x80086D68: lw          $t2, 0x438($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X438);
    // 0x80086D6C: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80086D70: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80086D74: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80086D78: addu        $t9, $t2, $t3
    ctx->r25 = ADD32(ctx->r10, ctx->r11);
    // 0x80086D7C: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80086D80: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80086D84: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80086D88: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80086D8C: lw          $t8, 0x438($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X438);
    // 0x80086D90: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80086D94: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80086D98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80086D9C: addu        $t1, $t8, $t5
    ctx->r9 = ADD32(ctx->r24, ctx->r13);
    // 0x80086DA0: sb          $t7, 0x8($t1)
    MEM_B(0X8, ctx->r9) = ctx->r15;
    // 0x80086DA4: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80086DA8: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80086DAC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80086DB0: lw          $t6, 0x438($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X438);
    // 0x80086DB4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80086DB8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80086DBC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80086DC0: addu        $t4, $t6, $t0
    ctx->r12 = ADD32(ctx->r14, ctx->r8);
    // 0x80086DC4: sb          $t2, 0x9($t4)
    MEM_B(0X9, ctx->r12) = ctx->r10;
    // 0x80086DC8: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80086DCC: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80086DD0: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x80086DD4: addu        $t1, $t8, $t7
    ctx->r9 = ADD32(ctx->r24, ctx->r15);
    // 0x80086DD8: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x80086DDC: lw          $t6, 0x438($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X438);
    // 0x80086DE0: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x80086DE4: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x80086DE8: addu        $t2, $t6, $t0
    ctx->r10 = ADD32(ctx->r14, ctx->r8);
    // 0x80086DEC: sw          $t9, 0x630($t2)
    MEM_W(0X630, ctx->r10) = ctx->r25;
    // 0x80086DF0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80086DF4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80086DF8: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80086DFC: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x80086E00: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80086E04: lw          $t1, 0x438($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X438);
    // 0x80086E08: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x80086E0C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086E10: addu        $t5, $t1, $t8
    ctx->r13 = ADD32(ctx->r9, ctx->r24);
    // 0x80086E14: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80086E18: sll         $t0, $t3, 4
    ctx->r8 = S32(ctx->r11 << 4);
    // 0x80086E1C: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x80086E20: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80086E24: lw          $t2, 0x18($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X18);
    // 0x80086E28: nop

    // 0x80086E2C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80086E30: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80086E34: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x80086E38: beq         $s0, $zero, L_80086E84
    if (ctx->r16 == 0) {
        // 0x80086E3C: sw          $t4, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r12;
            goto L_80086E84;
    }
    // 0x80086E3C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
L_80086E40:
    // 0x80086E40: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80086E44: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80086E48: lb          $t8, 0x0($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X0);
    // 0x80086E4C: nop

    // 0x80086E50: sll         $t5, $t8, 8
    ctx->r13 = S32(ctx->r24 << 8);
    // 0x80086E54: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x80086E58: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80086E5C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80086E60: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80086E64: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80086E68: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x80086E6C: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x80086E70: addiu       $t7, $t3, 0x2
    ctx->r15 = ADD32(ctx->r11, 0X2);
    // 0x80086E74: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80086E78: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x80086E7C: bne         $s0, $zero, L_80086E40
    if (ctx->r16 != 0) {
        // 0x80086E80: sw          $t4, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r12;
            goto L_80086E40;
    }
    // 0x80086E80: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
L_80086E84:
    // 0x80086E84: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80086E88: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80086E8C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80086E90: lw          $t8, 0x438($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X438);
    // 0x80086E94: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80086E98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80086E9C: addu        $t3, $t8, $t6
    ctx->r11 = ADD32(ctx->r24, ctx->r14);
    // 0x80086EA0: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x80086EA4: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
    // 0x80086EA8: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80086EAC: lw          $t0, 0x438($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X438);
    // 0x80086EB0: addu        $t8, $t1, $t4
    ctx->r24 = ADD32(ctx->r9, ctx->r12);
    // 0x80086EB4: addu        $t9, $t0, $t6
    ctx->r25 = ADD32(ctx->r8, ctx->r14);
    // 0x80086EB8: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80086EBC: nop

    // 0x80086EC0: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80086EC4: lhu         $t3, 0x24($t8)
    ctx->r11 = MEM_HU(ctx->r24, 0X24);
    // 0x80086EC8: nop

    // 0x80086ECC: andi        $t7, $t3, 0x8
    ctx->r15 = ctx->r11 & 0X8;
    // 0x80086ED0: beq         $t7, $zero, L_80086F40
    if (ctx->r15 == 0) {
        // 0x80086ED4: nop
    
            goto L_80086F40;
    }
    // 0x80086ED4: nop

    // 0x80086ED8: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_80086EDC:
    // 0x80086EDC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80086EE0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80086EE4: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x80086EE8: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x80086EEC: lw          $t5, 0x1C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X1C);
    // 0x80086EF0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80086EF4: lw          $t0, 0x20($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X20);
    // 0x80086EF8: subu        $t4, $t5, $t1
    ctx->r12 = SUB32(ctx->r13, ctx->r9);
    // 0x80086EFC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80086F00: sll         $t8, $t4, 1
    ctx->r24 = S32(ctx->r12 << 1);
    // 0x80086F04: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80086F08: addu        $t9, $t0, $t1
    ctx->r25 = ADD32(ctx->r8, ctx->r9);
    // 0x80086F0C: addu        $t7, $t3, $t8
    ctx->r15 = ADD32(ctx->r11, ctx->r24);
    // 0x80086F10: lh          $t6, -0x2($t7)
    ctx->r14 = MEM_H(ctx->r15, -0X2);
    // 0x80086F14: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x80086F18: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x80086F1C: sh          $t6, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r14;
    // 0x80086F20: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80086F24: nop

    // 0x80086F28: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80086F2C: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x80086F30: bne         $at, $zero, L_80086EDC
    if (ctx->r1 != 0) {
        // 0x80086F34: sw          $t7, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r15;
            goto L_80086EDC;
    }
    // 0x80086F34: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80086F38: b           L_80087178
    // 0x80086F3C: nop

        goto L_80087178;
    // 0x80086F3C: nop

L_80086F40:
    // 0x80086F40: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_80086F44:
    // 0x80086F44: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80086F48: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80086F4C: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80086F50: addu        $t9, $t2, $t1
    ctx->r25 = ADD32(ctx->r10, ctx->r9);
    // 0x80086F54: lw          $t4, 0x1C($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X1C);
    // 0x80086F58: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80086F5C: lw          $t2, 0x20($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X20);
    // 0x80086F60: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80086F64: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80086F68: sll         $t3, $t6, 1
    ctx->r11 = S32(ctx->r14 << 1);
    // 0x80086F6C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80086F70: addu        $t1, $t2, $t5
    ctx->r9 = ADD32(ctx->r10, ctx->r13);
    // 0x80086F74: addu        $t7, $t8, $t3
    ctx->r15 = ADD32(ctx->r24, ctx->r11);
    // 0x80086F78: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x80086F7C: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x80086F80: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x80086F84: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
    // 0x80086F88: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80086F8C: nop

    // 0x80086F90: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x80086F94: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x80086F98: bne         $at, $zero, L_80086F44
    if (ctx->r1 != 0) {
        // 0x80086F9C: sw          $t7, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r15;
            goto L_80086F44;
    }
    // 0x80086F9C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80086FA0: b           L_80087178
    // 0x80086FA4: nop

        goto L_80087178;
    // 0x80086FA4: nop

L_80086FA8:
    // 0x80086FA8: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80086FAC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80086FB0: sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10 << 4);
    // 0x80086FB4: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x80086FB8: lw          $t4, 0x438($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X438);
    // 0x80086FBC: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80086FC0: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x80086FC4: lw          $t6, 0x18($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X18);
    // 0x80086FC8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80086FCC: addu        $t8, $t4, $t0
    ctx->r24 = ADD32(ctx->r12, ctx->r8);
    // 0x80086FD0: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x80086FD4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80086FD8: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80086FDC: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x80086FE0: lw          $t5, 0x438($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X438);
    // 0x80086FE4: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x80086FE8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80086FEC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80086FF0: addu        $t2, $t5, $t9
    ctx->r10 = ADD32(ctx->r13, ctx->r25);
    // 0x80086FF4: sb          $t3, 0x8($t2)
    MEM_B(0X8, ctx->r10) = ctx->r11;
    // 0x80086FF8: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80086FFC: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80087000: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80087004: lw          $t6, 0x438($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X438);
    // 0x80087008: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8008700C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80087010: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80087014: addu        $t1, $t6, $t7
    ctx->r9 = ADD32(ctx->r14, ctx->r15);
    // 0x80087018: sb          $t4, 0x9($t1)
    MEM_B(0X9, ctx->r9) = ctx->r12;
    // 0x8008701C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80087020: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80087024: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x80087028: lw          $t8, 0x438($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X438);
    // 0x8008702C: addu        $t2, $t5, $t3
    ctx->r10 = ADD32(ctx->r13, ctx->r11);
    // 0x80087030: lw          $t0, 0x18($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X18);
    // 0x80087034: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80087038: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8008703C: sw          $t0, 0x630($t7)
    MEM_W(0X630, ctx->r15) = ctx->r8;
    // 0x80087040: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80087044: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80087048: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8008704C: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x80087050: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80087054: lw          $t3, 0x438($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X438);
    // 0x80087058: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x8008705C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80087060: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x80087064: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80087068: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x8008706C: addu        $t0, $t1, $t6
    ctx->r8 = ADD32(ctx->r9, ctx->r14);
    // 0x80087070: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80087074: lw          $t7, 0x18($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X18);
    // 0x80087078: nop

    // 0x8008707C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80087080: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80087084: addiu       $t4, $t7, -0x1
    ctx->r12 = ADD32(ctx->r15, -0X1);
    // 0x80087088: beq         $s0, $zero, L_800870D0
    if (ctx->r16 == 0) {
        // 0x8008708C: sw          $t4, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r12;
            goto L_800870D0;
    }
    // 0x8008708C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
L_80087090:
    // 0x80087090: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80087094: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80087098: lb          $t5, 0x0($t3)
    ctx->r13 = MEM_B(ctx->r11, 0X0);
    // 0x8008709C: nop

    // 0x800870A0: sb          $t5, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r13;
    // 0x800870A4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800870A8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800870AC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800870B0: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x800870B4: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x800870B8: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x800870BC: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x800870C0: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x800870C4: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800870C8: bne         $s0, $zero, L_80087090
    if (ctx->r16 != 0) {
        // 0x800870CC: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_80087090;
    }
    // 0x800870CC: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_800870D0:
    // 0x800870D0: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800870D4: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800870D8: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800870DC: lw          $t3, 0x438($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X438);
    // 0x800870E0: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x800870E4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800870E8: addu        $t8, $t3, $t9
    ctx->r24 = ADD32(ctx->r11, ctx->r25);
    // 0x800870EC: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x800870F0: sll         $t1, $t5, 4
    ctx->r9 = S32(ctx->r13 << 4);
    // 0x800870F4: addu        $t6, $t4, $t1
    ctx->r14 = ADD32(ctx->r12, ctx->r9);
    // 0x800870F8: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x800870FC: lw          $t0, 0x18($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X18);
    // 0x80087100: nop

    // 0x80087104: addu        $t7, $t0, $t2
    ctx->r15 = ADD32(ctx->r8, ctx->r10);
    // 0x80087108: lb          $t3, 0x0($t7)
    ctx->r11 = MEM_B(ctx->r15, 0X0);
    // 0x8008710C: sb          $zero, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = 0;
    // 0x80087110: sra         $t9, $t3, 4
    ctx->r25 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80087114: sb          $t9, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r25;
    // 0x80087118: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_8008711C:
    // 0x8008711C: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80087120: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80087124: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
    // 0x80087128: addu        $t1, $t8, $t4
    ctx->r9 = ADD32(ctx->r24, ctx->r12);
    // 0x8008712C: lw          $t6, 0x18($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X18);
    // 0x80087130: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80087134: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80087138: addu        $t2, $t6, $t0
    ctx->r10 = ADD32(ctx->r14, ctx->r8);
    // 0x8008713C: lb          $t7, 0x0($t2)
    ctx->r15 = MEM_B(ctx->r10, 0X0);
    // 0x80087140: lbu         $t3, 0x2D($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X2D);
    // 0x80087144: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x80087148: addu        $t4, $t0, $t8
    ctx->r12 = ADD32(ctx->r8, ctx->r24);
    // 0x8008714C: subu        $t9, $t7, $t3
    ctx->r25 = SUB32(ctx->r15, ctx->r11);
    // 0x80087150: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
    // 0x80087154: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80087158: lbu         $t1, 0x2D($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2D);
    // 0x8008715C: lbu         $t2, 0x2C($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2C);
    // 0x80087160: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80087164: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x80087168: addu        $t7, $t1, $t2
    ctx->r15 = ADD32(ctx->r9, ctx->r10);
    // 0x8008716C: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x80087170: bne         $at, $zero, L_8008711C
    if (ctx->r1 != 0) {
        // 0x80087174: sb          $t7, 0x2D($sp)
        MEM_B(0X2D, ctx->r29) = ctx->r15;
            goto L_8008711C;
    }
    // 0x80087174: sb          $t7, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r15;
L_80087178:
    // 0x80087178: jal         0x8007E4A4
    // 0x8008717C: nop

    n64HeapGetTotalMemFree(rdram, ctx);
        goto after_12;
    // 0x8008717C: nop

    after_12:
    // 0x80087180: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80087184: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087188: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008718C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80087190: addiu       $a1, $a1, -0x7EC
    ctx->r5 = ADD32(ctx->r5, -0X7EC);
    // 0x80087194: addiu       $a0, $a0, -0x81C
    ctx->r4 = ADD32(ctx->r4, -0X81C);
    // 0x80087198: jal         0x800B3BFC
    // 0x8008719C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_13;
    // 0x8008719C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_13:
    // 0x800871A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800871A4: jal         0x8007E328
    // 0x800871A8: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_14;
    // 0x800871A8: nop

    after_14:
L_800871AC:
    // 0x800871AC: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800871B0: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800871B4: sll         $t8, $t0, 4
    ctx->r24 = S32(ctx->r8 << 4);
    // 0x800871B8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800871BC: lhu         $t4, 0x24($t9)
    ctx->r12 = MEM_HU(ctx->r25, 0X24);
    // 0x800871C0: nop

    // 0x800871C4: andi        $t1, $t4, 0x4
    ctx->r9 = ctx->r12 & 0X4;
    // 0x800871C8: beq         $t1, $zero, L_800872C4
    if (ctx->r9 == 0) {
        // 0x800871CC: nop
    
            goto L_800872C4;
    }
    // 0x800871CC: nop

    // 0x800871D0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800871D4: lw          $t2, 0x438($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X438);
    // 0x800871D8: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x800871DC: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800871E0: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x800871E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800871E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800871EC: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x800871F0: addiu       $t5, $t3, 0x948
    ctx->r13 = ADD32(ctx->r11, 0X948);
    // 0x800871F4: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x800871F8: sw          $t5, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r13;
    // 0x800871FC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80087200: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80087204: sll         $t6, $t1, 4
    ctx->r14 = S32(ctx->r9 << 4);
    // 0x80087208: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8008720C: lw          $t0, 0x438($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X438);
    // 0x80087210: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80087214: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80087218: lw          $t3, 0x1C($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X1C);
    // 0x8008721C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80087220: addu        $t8, $t0, $t2
    ctx->r24 = ADD32(ctx->r8, ctx->r10);
    // 0x80087224: sw          $t3, 0x948($t8)
    MEM_W(0X948, ctx->r24) = ctx->r11;
    // 0x80087228: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8008722C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80087230: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x80087234: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80087238: lw          $t1, 0x438($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X438);
    // 0x8008723C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80087240: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80087244: lw          $t4, 0x20($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X20);
    // 0x80087248: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8008724C: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80087250: sw          $t4, 0x94C($t2)
    MEM_W(0X94C, ctx->r10) = ctx->r12;
    // 0x80087254: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80087258: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8008725C: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x80087260: lw          $t9, 0x438($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X438);
    // 0x80087264: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80087268: lw          $t5, 0x1C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X1C);
    // 0x8008726C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80087270: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x80087274: sw          $t5, 0x738($t0)
    MEM_W(0X738, ctx->r8) = ctx->r13;
    // 0x80087278: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8008727C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80087280: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x80087284: lw          $t8, 0x438($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X438);
    // 0x80087288: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8008728C: lw          $t3, 0x20($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X20);
    // 0x80087290: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x80087294: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80087298: sw          $t3, 0x840($t1)
    MEM_W(0X840, ctx->r9) = ctx->r11;
    // 0x8008729C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800872A0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800872A4: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x800872A8: lw          $t6, 0x438($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X438);
    // 0x800872AC: subu        $t4, $t4, $t7
    ctx->r12 = SUB32(ctx->r12, ctx->r15);
    // 0x800872B0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800872B4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800872B8: addu        $t2, $t6, $t4
    ctx->r10 = ADD32(ctx->r14, ctx->r12);
    // 0x800872BC: b           L_80087304
    // 0x800872C0: sw          $t5, 0x950($t2)
    MEM_W(0X950, ctx->r10) = ctx->r13;
        goto L_80087304;
    // 0x800872C0: sw          $t5, 0x950($t2)
    MEM_W(0X950, ctx->r10) = ctx->r13;
L_800872C4:
    // 0x800872C4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800872C8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800872CC: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x800872D0: lw          $t9, 0x438($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X438);
    // 0x800872D4: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x800872D8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800872DC: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x800872E0: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x800872E4: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800872E8: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800872EC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800872F0: lw          $t6, 0x438($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X438);
    // 0x800872F4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800872F8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800872FC: addu        $t2, $t6, $t5
    ctx->r10 = ADD32(ctx->r14, ctx->r13);
    // 0x80087300: sw          $zero, 0x950($t2)
    MEM_W(0X950, ctx->r10) = 0;
L_80087304:
    // 0x80087304: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80087308: nop

    // 0x8008730C: lbu         $t3, 0x1572($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X1572);
    // 0x80087310: nop

    // 0x80087314: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x80087318: sb          $t9, 0x1572($t8)
    MEM_B(0X1572, ctx->r24) = ctx->r25;
    // 0x8008731C: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80087320: nop

    // 0x80087324: lbu         $t0, 0x1572($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X1572);
    // 0x80087328: lbu         $t7, 0x41D($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X41D);
    // 0x8008732C: nop

    // 0x80087330: bne         $t0, $t7, L_80087468
    if (ctx->r8 != ctx->r15) {
        // 0x80087334: nop
    
            goto L_80087468;
    }
    // 0x80087334: nop

    // 0x80087338: sb          $zero, 0x1570($t1)
    MEM_B(0X1570, ctx->r9) = 0;
    // 0x8008733C: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
L_80087340:
    // 0x80087340: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80087344: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80087348: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8008734C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80087350: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80087354: lw          $t5, 0x43C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X43C);
    // 0x80087358: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8008735C: lw          $t6, 0x438($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X438);
    // 0x80087360: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80087364: addu        $t9, $t5, $t3
    ctx->r25 = ADD32(ctx->r13, ctx->r11);
    // 0x80087368: sw          $t6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r14;
    // 0x8008736C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80087370: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80087374: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80087378: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x8008737C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80087380: lw          $t0, 0x43C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X43C);
    // 0x80087384: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80087388: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x8008738C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80087390: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80087394: addu        $t4, $t0, $t1
    ctx->r12 = ADD32(ctx->r8, ctx->r9);
    // 0x80087398: swc1        $f4, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f4.u32l;
    // 0x8008739C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800873A0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800873A4: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800873A8: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x800873AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800873B0: lw          $t5, 0x43C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X43C);
    // 0x800873B4: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x800873B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800873BC: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x800873C0: sh          $zero, 0x24($t9)
    MEM_H(0X24, ctx->r25) = 0;
    // 0x800873C4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800873C8: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800873CC: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800873D0: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x800873D4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800873D8: lw          $t0, 0x43C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X43C);
    // 0x800873DC: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x800873E0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800873E4: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800873E8: addu        $t2, $t0, $t4
    ctx->r10 = ADD32(ctx->r8, ctx->r12);
    // 0x800873EC: sb          $t8, 0x26($t2)
    MEM_B(0X26, ctx->r10) = ctx->r24;
    // 0x800873F0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800873F4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800873F8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800873FC: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80087400: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80087404: lw          $t5, 0x43C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X43C);
    // 0x80087408: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x8008740C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80087410: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x80087414: sb          $zero, 0x27($t7)
    MEM_B(0X27, ctx->r15) = 0;
    // 0x80087418: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8008741C: nop

    // 0x80087420: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x80087424: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x80087428: bne         $at, $zero, L_80087340
    if (ctx->r1 != 0) {
        // 0x8008742C: sw          $t0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r8;
            goto L_80087340;
    }
    // 0x8008742C: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x80087430: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80087434: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80087438: sb          $t4, 0x1584($t8)
    MEM_B(0X1584, ctx->r24) = ctx->r12;
    // 0x8008743C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80087440: lw          $t3, 0x3B3C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3B3C);
    // 0x80087444: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80087448: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008744C: lw          $a1, 0x1574($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X1574);
    // 0x80087450: addiu       $a0, $a0, -0x7D8
    ctx->r4 = ADD32(ctx->r4, -0X7D8);
    // 0x80087454: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80087458: jal         0x800B3BFC
    // 0x8008745C: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_15;
    // 0x8008745C: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    after_15:
    // 0x80087460: jal         0x800B6650
    // 0x80087464: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_16;
    // 0x80087464: nop

    after_16:
L_80087468:
    // 0x80087468: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008746C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80087470: jr          $ra
    // 0x80087474: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80087474: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}

RECOMP_FUNC void Audio2_DecodeFixedSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008747C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80087480: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80087484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087488: lhu         $a2, 0x1E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1E);
    // 0x8008748C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80087490: lui         $a0, 0x7C
    ctx->r4 = S32(0X7C << 16);
    // 0x80087494: jal         0x800746C0
    // 0x80087498: addiu       $a0, $a0, 0x1960
    ctx->r4 = ADD32(ctx->r4, 0X1960);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_0;
    // 0x80087498: addiu       $a0, $a0, 0x1960
    ctx->r4 = ADD32(ctx->r4, 0X1960);
    after_0:
    // 0x8008749C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800874A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800874A4: jr          $ra
    // 0x800874A8: nop

    return;
    // 0x800874A8: nop

;}

RECOMP_FUNC void Audio2_RefillDecodeBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800874B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800874B4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800874B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800874BC: lhu         $t7, 0x1568($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X1568);
    // 0x800874C0: nop

    // 0x800874C4: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800874C8: sh          $t8, 0x1568($t6)
    MEM_H(0X1568, ctx->r14) = ctx->r24;
    // 0x800874CC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800874D0: nop

    // 0x800874D4: lhu         $t0, 0x156A($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X156A);
    // 0x800874D8: nop

    // 0x800874DC: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800874E0: sh          $t1, 0x156A($t9)
    MEM_H(0X156A, ctx->r25) = ctx->r9;
    // 0x800874E4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800874E8: nop

    // 0x800874EC: lbu         $t3, 0x156B($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X156B);
    // 0x800874F0: lbu         $t4, 0x1569($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X1569);
    // 0x800874F4: nop

    // 0x800874F8: beq         $t3, $t4, L_8008755C
    if (ctx->r11 == ctx->r12) {
        // 0x800874FC: nop
    
            goto L_8008755C;
    }
    // 0x800874FC: nop

L_80087500:
    // 0x80087500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087504: jal         0x8008F0D0
    // 0x80087508: addiu       $a0, $a0, 0x458
    ctx->r4 = ADD32(ctx->r4, 0X458);
    Dcm_DecodeSample(rdram, ctx);
        goto after_0;
    // 0x80087508: addiu       $a0, $a0, 0x458
    ctx->r4 = ADD32(ctx->r4, 0X458);
    after_0:
    // 0x8008750C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80087510: nop

    // 0x80087514: lbu         $t7, 0x156B($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X156B);
    // 0x80087518: nop

    // 0x8008751C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80087520: sb          $v0, 0x1468($t8)
    MEM_B(0X1468, ctx->r24) = ctx->r2;
    // 0x80087524: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80087528: nop

    // 0x8008752C: lhu         $t0, 0x156A($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X156A);
    // 0x80087530: nop

    // 0x80087534: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80087538: andi        $t9, $t1, 0xFF
    ctx->r25 = ctx->r9 & 0XFF;
    // 0x8008753C: sh          $t9, 0x156A($t6)
    MEM_H(0X156A, ctx->r14) = ctx->r25;
    // 0x80087540: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80087544: nop

    // 0x80087548: lbu         $t3, 0x156B($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X156B);
    // 0x8008754C: lbu         $t4, 0x1569($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X1569);
    // 0x80087550: nop

    // 0x80087554: bne         $t3, $t4, L_80087500
    if (ctx->r11 != ctx->r12) {
        // 0x80087558: nop
    
            goto L_80087500;
    }
    // 0x80087558: nop

L_8008755C:
    // 0x8008755C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087560: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087564: jr          $ra
    // 0x80087568: nop

    return;
    // 0x80087568: nop

;}

RECOMP_FUNC void Audio2_FillDecodeBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008756C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80087570: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80087574: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80087578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008757C: sh          $zero, 0x1568($t6)
    MEM_H(0X1568, ctx->r14) = 0;
    // 0x80087580: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80087584: nop

    // 0x80087588: sh          $zero, 0x156A($t7)
    MEM_H(0X156A, ctx->r15) = 0;
    // 0x8008758C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80087590: nop

    // 0x80087594: sw          $zero, 0x156C($t8)
    MEM_W(0X156C, ctx->r24) = 0;
    // 0x80087598: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8008759C:
    // 0x8008759C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800875A0: jal         0x8008F0D0
    // 0x800875A4: addiu       $a0, $a0, 0x458
    ctx->r4 = ADD32(ctx->r4, 0X458);
    Dcm_DecodeSample(rdram, ctx);
        goto after_0;
    // 0x800875A4: addiu       $a0, $a0, 0x458
    ctx->r4 = ADD32(ctx->r4, 0X458);
    after_0:
    // 0x800875A8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800875AC: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x800875B0: nop

    // 0x800875B4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800875B8: sb          $v0, 0x1468($t1)
    MEM_B(0X1468, ctx->r9) = ctx->r2;
    // 0x800875BC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800875C0: nop

    // 0x800875C4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800875C8: slti        $at, $t3, 0x100
    ctx->r1 = SIGNED(ctx->r11) < 0X100 ? 1 : 0;
    // 0x800875CC: bne         $at, $zero, L_8008759C
    if (ctx->r1 != 0) {
        // 0x800875D0: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_8008759C;
    }
    // 0x800875D0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800875D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800875D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800875DC: jr          $ra
    // 0x800875E0: nop

    return;
    // 0x800875E0: nop

;}

RECOMP_FUNC void Audio2_Noop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875E4: jr          $ra
    // 0x800875E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800875E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

RECOMP_FUNC void Audio2_SetGlobalPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875EC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800875F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800875F4: sh          $a0, 0x157C($a1)
    MEM_H(0X157C, ctx->r5) = ctx->r4;
    // 0x800875F8: jr          $ra
    // 0x800875FC: sb          $t6, 0x1587($a1)
    MEM_B(0X1587, ctx->r5) = ctx->r14;
    return;
    // 0x800875FC: sb          $t6, 0x1587($a1)
    MEM_B(0X1587, ctx->r5) = ctx->r14;
;}

RECOMP_FUNC void Audio2_SetGlobalPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087600: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80087604: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80087608: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008760C: sb          $a0, 0x158D($a1)
    MEM_B(0X158D, ctx->r5) = ctx->r4;
    // 0x80087610: jr          $ra
    // 0x80087614: sb          $t6, 0x158C($a1)
    MEM_B(0X158C, ctx->r5) = ctx->r14;
    return;
    // 0x80087614: sb          $t6, 0x158C($a1)
    MEM_B(0X158C, ctx->r5) = ctx->r14;
;}

RECOMP_FUNC void Audio2_BuildVolumeTable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087618: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008761C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80087620: lhu         $t6, 0x22($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X22);
    // 0x80087624: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80087628: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8008762C: bne         $at, $zero, L_8008763C
    if (ctx->r1 != 0) {
        // 0x80087630: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8008763C;
    }
    // 0x80087630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087634: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x80087638: sh          $t7, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r15;
L_8008763C:
    // 0x8008763C: lhu         $t8, 0x22($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X22);
    // 0x80087640: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80087644: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
    // 0x80087648: sh          $t8, -0x7328($at)
    MEM_H(-0X7328, ctx->r1) = ctx->r24;
L_8008764C:
    // 0x8008764C: lhu         $t9, 0x1E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X1E);
    // 0x80087650: nop

    // 0x80087654: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80087658: bgez        $t9, L_80087670
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8008765C: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80087670;
    }
    // 0x8008765C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80087660: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80087664: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80087668: nop

    // 0x8008766C: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_80087670:
    // 0x80087670: jal         0x800B8340
    // 0x80087674: nop

    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80087674: nop

    after_0:
    // 0x80087678: lhu         $t0, 0x22($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X22);
    // 0x8008767C: nop

    // 0x80087680: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80087684: bgez        $t0, L_8008769C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80087688: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8008769C;
    }
    // 0x80087688: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008768C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80087690: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80087694: nop

    // 0x80087698: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8008769C:
    // 0x8008769C: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800876A0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800876A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800876A8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800876AC: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800876B0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800876B4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800876B8: nop

    // 0x800876BC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800876C0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800876C4: nop

    // 0x800876C8: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x800876CC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800876D0: beq         $t2, $zero, L_80087720
    if (ctx->r10 == 0) {
        // 0x800876D4: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80087720;
    }
    // 0x800876D4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800876D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800876DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800876E0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800876E4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800876E8: nop

    // 0x800876EC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800876F0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800876F4: nop

    // 0x800876F8: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x800876FC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80087700: bne         $t2, $zero, L_80087718
    if (ctx->r10 != 0) {
        // 0x80087704: nop
    
            goto L_80087718;
    }
    // 0x80087704: nop

    // 0x80087708: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x8008770C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80087710: b           L_80087730
    // 0x80087714: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80087730;
    // 0x80087714: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80087718:
    // 0x80087718: b           L_80087730
    // 0x8008771C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80087730;
    // 0x8008771C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_80087720:
    // 0x80087720: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80087724: nop

    // 0x80087728: bltz        $t2, L_80087718
    if (SIGNED(ctx->r10) < 0) {
        // 0x8008772C: nop
    
            goto L_80087718;
    }
    // 0x8008772C: nop

L_80087730:
    // 0x80087730: lhu         $t3, 0x1E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X1E);
    // 0x80087734: lhu         $t5, 0x1E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X1E);
    // 0x80087738: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008773C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80087740: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80087744: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80087748: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8008774C: sh          $t2, -0x7528($at)
    MEM_H(-0X7528, ctx->r1) = ctx->r10;
    // 0x80087750: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80087754: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80087758: bne         $at, $zero, L_8008764C
    if (ctx->r1 != 0) {
        // 0x8008775C: sh          $t6, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r14;
            goto L_8008764C;
    }
    // 0x8008775C: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    // 0x80087760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087764: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80087768: jr          $ra
    // 0x8008776C: nop

    return;
    // 0x8008776C: nop

;}

RECOMP_FUNC void Audio2_SetBusyFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087770: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80087774: jr          $ra
    // 0x80087778: sb          $t6, 0x1599($a0)
    MEM_B(0X1599, ctx->r4) = ctx->r14;
    return;
    // 0x80087778: sb          $t6, 0x1599($a0)
    MEM_B(0X1599, ctx->r4) = ctx->r14;
;}

RECOMP_FUNC void Audio2_ClearBusyFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008777C: jr          $ra
    // 0x80087780: sb          $zero, 0x1599($a0)
    MEM_B(0X1599, ctx->r4) = 0;
    return;
    // 0x80087780: sb          $zero, 0x1599($a0)
    MEM_B(0X1599, ctx->r4) = 0;
;}

RECOMP_FUNC void Audio2_GFXDone_SendPlayMessage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087784: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80087788: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008778C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80087790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087794: lbu         $t7, 0x1599($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1599);
    // 0x80087798: nop

    // 0x8008779C: bne         $t7, $zero, L_800877FC
    if (ctx->r15 != 0) {
        // 0x800877A0: nop
    
            goto L_800877FC;
    }
    // 0x800877A0: nop

    // 0x800877A4: lbu         $t8, 0x454($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X454);
    // 0x800877A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800877AC: beq         $t8, $at, L_800877FC
    if (ctx->r24 == ctx->r1) {
        // 0x800877B0: nop
    
            goto L_800877FC;
    }
    // 0x800877B0: nop

    // 0x800877B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800877B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800877BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800877C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800877C4: sh          $t9, -0x7240($at)
    MEM_H(-0X7240, ctx->r1) = ctx->r25;
    // 0x800877C8: sw          $t6, -0x723C($at)
    MEM_W(-0X723C, ctx->r1) = ctx->r14;
    // 0x800877CC: addiu       $a1, $a1, -0x7240
    ctx->r5 = ADD32(ctx->r5, -0X7240);
    // 0x800877D0: addiu       $a0, $a0, -0x7320
    ctx->r4 = ADD32(ctx->r4, -0X7320);
    // 0x800877D4: jal         0x800B8BE0
    // 0x800877D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osJamMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800877D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800877DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800877E0: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x800877E4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800877E8: jal         0x800B3C20
    // 0x800877EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800877EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800877F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800877F4: jal         0x800B3BFC
    // 0x800877F8: addiu       $a0, $a0, -0x7B0
    ctx->r4 = ADD32(ctx->r4, -0X7B0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800877F8: addiu       $a0, $a0, -0x7B0
    ctx->r4 = ADD32(ctx->r4, -0X7B0);
    after_2:
L_800877FC:
    // 0x800877FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087800: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80087804: jr          $ra
    // 0x80087808: nop

    return;
    // 0x80087808: nop

;}

RECOMP_FUNC void Audio2_GFXDone_SendSyncMessage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008780C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80087810: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80087814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087818: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008781C: jal         0x80087770
    // 0x80087820: nop

    Audio2_SetBusyFlag(rdram, ctx);
        goto after_0;
    // 0x80087820: nop

    after_0:
    // 0x80087824: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80087828: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008782C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80087830: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80087834: sh          $zero, -0x7240($at)
    MEM_H(-0X7240, ctx->r1) = 0;
    // 0x80087838: addiu       $a1, $a1, -0x7240
    ctx->r5 = ADD32(ctx->r5, -0X7240);
    // 0x8008783C: addiu       $a0, $a0, -0x7320
    ctx->r4 = ADD32(ctx->r4, -0X7320);
    // 0x80087840: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087844: jal         0x800B8BE0
    // 0x80087848: sw          $t6, -0x723C($at)
    MEM_W(-0X723C, ctx->r1) = ctx->r14;
    osJamMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80087848: sw          $t6, -0x723C($at)
    MEM_W(-0X723C, ctx->r1) = ctx->r14;
    after_1:
    // 0x8008784C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80087850: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x80087854: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80087858: jal         0x800B3C20
    // 0x8008785C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8008785C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80087860: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80087864: jal         0x8008777C
    // 0x80087868: nop

    Audio2_ClearBusyFlag(rdram, ctx);
        goto after_3;
    // 0x80087868: nop

    after_3:
    // 0x8008786C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087870: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80087874: jr          $ra
    // 0x80087878: nop

    return;
    // 0x80087878: nop

;}

RECOMP_FUNC void Audio2_GFXDone_SendCmd4Message(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008787C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80087880: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80087884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087888: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008788C: jal         0x8008780C
    // 0x80087890: nop

    Audio2_GFXDone_SendSyncMessage(rdram, ctx);
        goto after_0;
    // 0x80087890: nop

    after_0:
    // 0x80087894: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80087898: jal         0x8008777C
    // 0x8008789C: nop

    Audio2_ClearBusyFlag(rdram, ctx);
        goto after_1;
    // 0x8008789C: nop

    after_1:
    // 0x800878A0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800878A4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800878A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800878AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800878B0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800878B4: sh          $t6, -0x7240($at)
    MEM_H(-0X7240, ctx->r1) = ctx->r14;
    // 0x800878B8: addiu       $a1, $a1, -0x7240
    ctx->r5 = ADD32(ctx->r5, -0X7240);
    // 0x800878BC: addiu       $a0, $a0, -0x7320
    ctx->r4 = ADD32(ctx->r4, -0X7320);
    // 0x800878C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800878C4: jal         0x800B8BE0
    // 0x800878C8: sw          $t7, -0x723C($at)
    MEM_W(-0X723C, ctx->r1) = ctx->r15;
    osJamMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800878C8: sw          $t7, -0x723C($at)
    MEM_W(-0X723C, ctx->r1) = ctx->r15;
    after_2:
    // 0x800878CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800878D0: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x800878D4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800878D8: jal         0x800B3C20
    // 0x800878DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800878DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800878E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800878E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800878E8: jr          $ra
    // 0x800878EC: nop

    return;
    // 0x800878EC: nop

;}

RECOMP_FUNC void Audio2_GFXDone_SendStartMessage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80088BA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80088BAC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80088BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088BB4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80088BB8: lw          $t7, 0x88($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X88);
    // 0x80088BBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088BC0: beq         $t7, $at, L_80088C04
    if (ctx->r15 == ctx->r1) {
        // 0x80088BC4: nop
    
            goto L_80088C04;
    }
    // 0x80088BC4: nop

    // 0x80088BC8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80088BCC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80088BD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80088BD4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80088BD8: sh          $t8, -0x7238($at)
    MEM_H(-0X7238, ctx->r1) = ctx->r24;
    // 0x80088BDC: sw          $t6, -0x7234($at)
    MEM_W(-0X7234, ctx->r1) = ctx->r14;
    // 0x80088BE0: addiu       $a1, $a1, -0x7238
    ctx->r5 = ADD32(ctx->r5, -0X7238);
    // 0x80088BE4: addiu       $a0, $a0, -0x72B0
    ctx->r4 = ADD32(ctx->r4, -0X72B0);
    // 0x80088BE8: jal         0x800B8BE0
    // 0x80088BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osJamMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80088BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80088BF0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80088BF4: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x80088BF8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80088BFC: jal         0x800B3C20
    // 0x80088C00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80088C00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80088C04:
    // 0x80088C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088C08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80088C0C: jr          $ra
    // 0x80088C10: nop

    return;
    // 0x80088C10: nop

;}

RECOMP_FUNC void Audio2_GFXDone_SendStopMessage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80088C18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80088C1C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80088C20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088C24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80088C28: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088C2C: sh          $zero, -0x7238($at)
    MEM_H(-0X7238, ctx->r1) = 0;
    // 0x80088C30: addiu       $a0, $a0, -0x778
    ctx->r4 = ADD32(ctx->r4, -0X778);
    // 0x80088C34: jal         0x800B3BFC
    // 0x80088C38: sw          $t6, -0x7234($at)
    MEM_W(-0X7234, ctx->r1) = ctx->r14;
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80088C38: sw          $t6, -0x7234($at)
    MEM_W(-0X7234, ctx->r1) = ctx->r14;
    after_0:
    // 0x80088C3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80088C40: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80088C44: addiu       $a1, $a1, -0x7238
    ctx->r5 = ADD32(ctx->r5, -0X7238);
    // 0x80088C48: addiu       $a0, $a0, -0x72B0
    ctx->r4 = ADD32(ctx->r4, -0X72B0);
    // 0x80088C4C: jal         0x800B8BE0
    // 0x80088C50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osJamMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80088C50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80088C54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80088C58: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x80088C5C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80088C60: jal         0x800B3C20
    // 0x80088C64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80088C64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80088C68: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088C6C: jal         0x800B3BFC
    // 0x80088C70: addiu       $a0, $a0, -0x754
    ctx->r4 = ADD32(ctx->r4, -0X754);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x80088C70: addiu       $a0, $a0, -0x754
    ctx->r4 = ADD32(ctx->r4, -0X754);
    after_3:
    // 0x80088C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088C78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80088C7C: jr          $ra
    // 0x80088C80: nop

    return;
    // 0x80088C80: nop

;}

RECOMP_FUNC void Audio2_InitSFXPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80088C88: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80088C8C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80088C90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088C94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80088C98: bne         $t6, $zero, L_80088E88
    if (ctx->r14 != 0) {
        // 0x80088C9C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80088E88;
    }
    // 0x80088C9C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80088CA0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80088CA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80088CA8: addiu       $t7, $t7, 0x4938
    ctx->r15 = ADD32(ctx->r15, 0X4938);
    // 0x80088CAC: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    // 0x80088CB0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80088CB4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80088CB8: addiu       $t9, $t9, 0x5598
    ctx->r25 = ADD32(ctx->r25, 0X5598);
    // 0x80088CBC: sw          $t9, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r25;
    // 0x80088CC0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80088CC4: lw          $t1, -0x4FB0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4FB0);
    // 0x80088CC8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80088CCC: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80088CD0: sw          $t1, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r9;
    // 0x80088CD4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80088CD8: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x80088CDC: addiu       $t6, $t6, -0x57F4
    ctx->r14 = ADD32(ctx->r14, -0X57F4);
    // 0x80088CE0: sw          $t3, 0x8C($t4)
    MEM_W(0X8C, ctx->r12) = ctx->r11;
    // 0x80088CE4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80088CE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088CEC: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x80088CF0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80088CF4: nop

    // 0x80088CF8: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x80088CFC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80088D00: nop

    // 0x80088D04: sw          $t8, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r24;
    // 0x80088D08: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80088D0C: nop

    // 0x80088D10: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
    // 0x80088D14: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80088D18: lw          $a0, -0x4FB0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4FB0);
    // 0x80088D1C: jal         0x800B88E0
    // 0x80088D20: nop

    alSynAddPlayer(rdram, ctx);
        goto after_0;
    // 0x80088D20: nop

    after_0:
    // 0x80088D24: lbu         $t1, 0x33($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X33);
    // 0x80088D28: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80088D2C: sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    // 0x80088D30: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
    // 0x80088D34: sb          $zero, 0x20($sp)
    MEM_B(0X20, ctx->r29) = 0;
    // 0x80088D38: blez        $t1, L_80088D88
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80088D3C: sw          $zero, 0x24($sp)
        MEM_W(0X24, ctx->r29) = 0;
            goto L_80088D88;
    }
    // 0x80088D3C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80088D40:
    // 0x80088D40: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80088D44: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80088D48: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80088D4C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80088D50: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80088D54: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x80088D58: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80088D5C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80088D60: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x80088D64: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80088D68: jal         0x800B8A18
    // 0x80088D6C: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    alSynAllocVoice(rdram, ctx);
        goto after_1;
    // 0x80088D6C: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    after_1:
    // 0x80088D70: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80088D74: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x80088D78: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80088D7C: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80088D80: bne         $at, $zero, L_80088D40
    if (ctx->r1 != 0) {
        // 0x80088D84: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_80088D40;
    }
    // 0x80088D84: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80088D88:
    // 0x80088D88: lbu         $t9, 0x33($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X33);
    // 0x80088D8C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80088D90: blez        $t9, L_80088E88
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80088D94: nop
    
            goto L_80088E88;
    }
    // 0x80088D94: nop

L_80088D98:
    // 0x80088D98: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80088D9C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80088DA0: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80088DA4: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x80088DA8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80088DAC: lw          $t2, 0x1C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X1C);
    // 0x80088DB0: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x80088DB4: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x80088DB8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80088DBC: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80088DC0: sw          $t1, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r9;
    // 0x80088DC4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80088DC8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80088DCC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80088DD0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80088DD4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80088DD8: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x80088DDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80088DE0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80088DE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80088DE8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80088DEC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80088DF0: swc1        $f4, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f4.u32l;
    // 0x80088DF4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80088DF8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80088DFC: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x80088E00: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x80088E04: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80088E08: lw          $t2, 0x1C($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X1C);
    // 0x80088E0C: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x80088E10: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80088E14: addu        $t5, $t2, $t1
    ctx->r13 = ADD32(ctx->r10, ctx->r9);
    // 0x80088E18: sh          $zero, 0x24($t5)
    MEM_H(0X24, ctx->r13) = 0;
    // 0x80088E1C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80088E20: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80088E24: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80088E28: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80088E2C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80088E30: lw          $t7, 0x1C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X1C);
    // 0x80088E34: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80088E38: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80088E3C: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80088E40: addu        $t4, $t7, $t0
    ctx->r12 = ADD32(ctx->r15, ctx->r8);
    // 0x80088E44: sb          $t6, 0x26($t4)
    MEM_B(0X26, ctx->r12) = ctx->r14;
    // 0x80088E48: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80088E4C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80088E50: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x80088E54: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x80088E58: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80088E5C: lw          $t2, 0x1C($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X1C);
    // 0x80088E60: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x80088E64: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80088E68: addu        $t8, $t2, $t5
    ctx->r24 = ADD32(ctx->r10, ctx->r13);
    // 0x80088E6C: sb          $zero, 0x27($t8)
    MEM_B(0X27, ctx->r24) = 0;
    // 0x80088E70: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80088E74: lbu         $t0, 0x33($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X33);
    // 0x80088E78: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80088E7C: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80088E80: bne         $at, $zero, L_80088D98
    if (ctx->r1 != 0) {
        // 0x80088E84: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_80088D98;
    }
    // 0x80088E84: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80088E88:
    // 0x80088E88: lbu         $t6, 0x33($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X33);
    // 0x80088E8C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80088E90: blez        $t6, L_80088F94
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80088E94: nop
    
            goto L_80088F94;
    }
    // 0x80088E94: nop

L_80088E98:
    // 0x80088E98: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80088E9C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80088EA0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80088EA4: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80088EA8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80088EAC: lw          $t3, 0x1C($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X1C);
    // 0x80088EB0: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80088EB4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80088EB8: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80088EBC: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x80088EC0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80088EC4: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x80088EC8: sw          $zero, 0x20($t9)
    MEM_W(0X20, ctx->r25) = 0;
    // 0x80088ECC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80088ED0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80088ED4: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x80088ED8: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x80088EDC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80088EE0: addu        $t3, $t7, $t6
    ctx->r11 = ADD32(ctx->r15, ctx->r14);
    // 0x80088EE4: addiu       $t2, $t3, 0x114
    ctx->r10 = ADD32(ctx->r11, 0X114);
    // 0x80088EE8: sw          $t2, 0x110($t3)
    MEM_W(0X110, ctx->r11) = ctx->r10;
    // 0x80088EEC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80088EF0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80088EF4: sll         $t4, $t1, 3
    ctx->r12 = S32(ctx->r9 << 3);
    // 0x80088EF8: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x80088EFC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80088F00: addu        $t8, $t5, $t4
    ctx->r24 = ADD32(ctx->r13, ctx->r12);
    // 0x80088F04: lw          $t9, 0x110($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X110);
    // 0x80088F08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088F0C: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x80088F10: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80088F14: nop

    // 0x80088F18: lbu         $t7, 0x27($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X27);
    // 0x80088F1C: nop

    // 0x80088F20: bne         $t7, $at, L_80088F40
    if (ctx->r15 != ctx->r1) {
        // 0x80088F24: nop
    
            goto L_80088F40;
    }
    // 0x80088F24: nop

    // 0x80088F28: sb          $zero, 0x27($t0)
    MEM_B(0X27, ctx->r8) = 0;
    // 0x80088F2C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80088F30: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80088F34: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x80088F38: jal         0x800B8B60
    // 0x80088F3C: nop

    alSynStopVoice(rdram, ctx);
        goto after_2;
    // 0x80088F3C: nop

    after_2:
L_80088F40:
    // 0x80088F40: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80088F44: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80088F48: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x80088F4C: addu        $t5, $t2, $t1
    ctx->r13 = ADD32(ctx->r10, ctx->r9);
    // 0x80088F50: sw          $zero, 0x20($t5)
    MEM_W(0X20, ctx->r13) = 0;
    // 0x80088F54: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80088F58: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80088F5C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80088F60: addu        $t7, $t4, $t9
    ctx->r15 = ADD32(ctx->r12, ctx->r25);
    // 0x80088F64: sw          $zero, 0x90($t7)
    MEM_W(0X90, ctx->r15) = 0;
    // 0x80088F68: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80088F6C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80088F70: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80088F74: addu        $t2, $t0, $t3
    ctx->r10 = ADD32(ctx->r8, ctx->r11);
    // 0x80088F78: sw          $zero, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = 0;
    // 0x80088F7C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80088F80: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x80088F84: addiu       $t5, $t1, 0x1
    ctx->r13 = ADD32(ctx->r9, 0X1);
    // 0x80088F88: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80088F8C: bne         $at, $zero, L_80088E98
    if (ctx->r1 != 0) {
        // 0x80088F90: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80088E98;
    }
    // 0x80088F90: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_80088F94:
    // 0x80088F94: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80088F98:
    // 0x80088F98: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80088F9C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80088FA0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80088FA4: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x80088FA8: sb          $t4, 0x364($t6)
    MEM_B(0X364, ctx->r14) = ctx->r12;
    // 0x80088FAC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80088FB0: nop

    // 0x80088FB4: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x80088FB8: slti        $at, $t3, 0xFF
    ctx->r1 = SIGNED(ctx->r11) < 0XFF ? 1 : 0;
    // 0x80088FBC: bne         $at, $zero, L_80088F98
    if (ctx->r1 != 0) {
        // 0x80088FC0: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_80088F98;
    }
    // 0x80088FC0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80088FC4: lbu         $t2, 0x33($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X33);
    // 0x80088FC8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80088FCC: sra         $t1, $t2, 1
    ctx->r9 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80088FD0: blez        $t1, L_80089008
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80088FD4: nop
    
            goto L_80089008;
    }
    // 0x80088FD4: nop

L_80088FD8:
    // 0x80088FD8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80088FDC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80088FE0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80088FE4: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x80088FE8: sw          $zero, 0x60($t7)
    MEM_W(0X60, ctx->r15) = 0;
    // 0x80088FEC: lbu         $t0, 0x33($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X33);
    // 0x80088FF0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80088FF4: sra         $t3, $t0, 1
    ctx->r11 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80088FF8: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80088FFC: slt         $at, $t6, $t3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80089000: bne         $at, $zero, L_80088FD8
    if (ctx->r1 != 0) {
        // 0x80089004: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_80088FD8;
    }
    // 0x80089004: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80089008:
    // 0x80089008: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008900C: nop

    // 0x80089010: sw          $zero, 0x80($t2)
    MEM_W(0X80, ctx->r10) = 0;
    // 0x80089014: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80089018: nop

    // 0x8008901C: sw          $zero, 0x84($t1)
    MEM_W(0X84, ctx->r9) = 0;
    // 0x80089020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80089024: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80089028: jr          $ra
    // 0x8008902C: nop

    return;
    // 0x8008902C: nop

;}

RECOMP_FUNC void Audio2_SetupSFXChannel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089030: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80089034: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80089038: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8008903C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80089040: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80089044: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x80089048: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8008904C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80089050: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x80089054: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80089058: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8008905C: jal         0x8008BF58
    // 0x80089060: sh          $t7, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r15;
    Audio2_ParseSFXHeader(rdram, ctx);
        goto after_0;
    // 0x80089060: sh          $t7, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r15;
    after_0:
    // 0x80089064: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80089068: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8008906C: addiu       $t9, $t8, 0xE
    ctx->r25 = ADD32(ctx->r24, 0XE);
    // 0x80089070: lhu         $t3, 0x2E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2E);
    // 0x80089074: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x80089078: lw          $t2, 0x350($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X350);
    // 0x8008907C: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80089080: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80089084: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80089088: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x8008908C: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80089090: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80089094: addiu       $t7, $t6, 0x18
    ctx->r15 = ADD32(ctx->r14, 0X18);
    // 0x80089098: addiu       $t8, $t7, 0xF
    ctx->r24 = ADD32(ctx->r15, 0XF);
    // 0x8008909C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800890A0: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x800890A4: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800890A8: lhu         $t4, 0x2E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2E);
    // 0x800890AC: sw          $t9, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r25;
    // 0x800890B0: lw          $t2, 0x350($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X350);
    // 0x800890B4: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x800890B8: addu        $t5, $t2, $t0
    ctx->r13 = ADD32(ctx->r10, ctx->r8);
    // 0x800890BC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800890C0: lbu         $t1, 0x64($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X64);
    // 0x800890C4: nop

    // 0x800890C8: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x800890CC: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800890D0: lhu         $t3, 0x2E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2E);
    // 0x800890D4: lw          $t9, 0x350($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X350);
    // 0x800890D8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800890DC: addu        $t2, $t9, $t4
    ctx->r10 = ADD32(ctx->r25, ctx->r12);
    // 0x800890E0: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x800890E4: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800890E8: nop

    // 0x800890EC: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800890F0: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800890F4: lhu         $t8, 0x2E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2E);
    // 0x800890F8: lw          $t6, 0x350($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X350);
    // 0x800890FC: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80089100: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x80089104: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80089108: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8008910C: nop

    // 0x80089110: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x80089114: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80089118: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8008911C: lbu         $t6, 0x65($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X65);
    // 0x80089120: addu        $t0, $t2, $t7
    ctx->r8 = ADD32(ctx->r10, ctx->r15);
    // 0x80089124: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80089128: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    // 0x8008912C: addiu       $t1, $t0, 0xF
    ctx->r9 = ADD32(ctx->r8, 0XF);
    // 0x80089130: sll         $t3, $t6, 4
    ctx->r11 = S32(ctx->r14 << 4);
    // 0x80089134: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80089138: and         $t8, $t1, $at
    ctx->r24 = ctx->r9 & ctx->r1;
    // 0x8008913C: addu        $t5, $t3, $t9
    ctx->r13 = ADD32(ctx->r11, ctx->r25);
    // 0x80089140: lhu         $t0, 0x2E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2E);
    // 0x80089144: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x80089148: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x8008914C: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80089150: lw          $t2, 0x350($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X350);
    // 0x80089154: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80089158: addu        $t8, $t2, $t1
    ctx->r24 = ADD32(ctx->r10, ctx->r9);
    // 0x8008915C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80089160: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80089164: lw          $t3, 0x0($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X0);
    // 0x80089168: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8008916C: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x80089170: beq         $s0, $zero, L_800891B8
    if (ctx->r16 == 0) {
        // 0x80089174: sw          $t3, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r11;
            goto L_800891B8;
    }
    // 0x80089174: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
L_80089178:
    // 0x80089178: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8008917C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80089180: lb          $t4, 0x0($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X0);
    // 0x80089184: nop

    // 0x80089188: sb          $t4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r12;
    // 0x8008918C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80089190: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80089194: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80089198: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x8008919C: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x800891A0: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800891A4: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x800891A8: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x800891AC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800891B0: bne         $s0, $zero, L_80089178
    if (ctx->r16 != 0) {
        // 0x800891B4: sw          $t7, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r15;
            goto L_80089178;
    }
    // 0x800891B4: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_800891B8:
    // 0x800891B8: lbu         $t9, 0x65($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X65);
    // 0x800891BC: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800891C0: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800891C4: sll         $t5, $t9, 4
    ctx->r13 = S32(ctx->r25 << 4);
    // 0x800891C8: addu        $t0, $t5, $t4
    ctx->r8 = ADD32(ctx->r13, ctx->r12);
    // 0x800891CC: addu        $t1, $t0, $t2
    ctx->r9 = ADD32(ctx->r8, ctx->r10);
    // 0x800891D0: lbu         $t3, 0x64($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X64);
    // 0x800891D4: addiu       $t8, $t1, 0xF
    ctx->r24 = ADD32(ctx->r9, 0XF);
    // 0x800891D8: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800891DC: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800891E0: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x800891E4: bne         $at, $zero, L_800891F8
    if (ctx->r1 != 0) {
        // 0x800891E8: sw          $t6, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r14;
            goto L_800891F8;
    }
    // 0x800891E8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x800891EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800891F0: jal         0x800B3BFC
    // 0x800891F4: addiu       $a0, $a0, -0x728
    ctx->r4 = ADD32(ctx->r4, -0X728);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800891F4: addiu       $a0, $a0, -0x728
    ctx->r4 = ADD32(ctx->r4, -0X728);
    after_1:
L_800891F8:
    // 0x800891F8: lbu         $t7, 0x65($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X65);
    // 0x800891FC: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80089200: blez        $t7, L_80089D30
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80089204: nop
    
            goto L_80089D30;
    }
    // 0x80089204: nop

L_80089208:
    // 0x80089208: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x8008920C: jal         0x8008C014
    // 0x80089210: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    Audio2_ParseSoundRecord(rdram, ctx);
        goto after_2;
    // 0x80089210: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_2:
    // 0x80089214: jal         0x800B6650
    // 0x80089218: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_3;
    // 0x80089218: nop

    after_3:
    // 0x8008921C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80089220: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80089224: sh          $zero, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = 0;
L_80089228:
    // 0x80089228: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8008922C: lhu         $t4, 0x2C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2C);
    // 0x80089230: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80089234: lhu         $t8, 0x3B50($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X3B50);
    // 0x80089238: lhu         $t1, 0x5E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X5E);
    // 0x8008923C: addu        $t0, $t5, $t4
    ctx->r8 = ADD32(ctx->r13, ctx->r12);
    // 0x80089240: lbu         $t2, 0x364($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X364);
    // 0x80089244: subu        $t6, $t1, $t8
    ctx->r14 = SUB32(ctx->r9, ctx->r24);
    // 0x80089248: bne         $t2, $t6, L_8008927C
    if (ctx->r10 != ctx->r14) {
        // 0x8008924C: nop
    
            goto L_8008927C;
    }
    // 0x8008924C: nop

    // 0x80089250: lhu         $t7, 0x2E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2E);
    // 0x80089254: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80089258: lw          $t3, 0x350($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X350);
    // 0x8008925C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80089260: addu        $t0, $t3, $t9
    ctx->r8 = ADD32(ctx->r11, ctx->r25);
    // 0x80089264: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80089268: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8008926C: nop

    // 0x80089270: addu        $t2, $t1, $t8
    ctx->r10 = ADD32(ctx->r9, ctx->r24);
    // 0x80089274: b           L_80089298
    // 0x80089278: sb          $t4, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r12;
        goto L_80089298;
    // 0x80089278: sb          $t4, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r12;
L_8008927C:
    // 0x8008927C: lhu         $t6, 0x2C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2C);
    // 0x80089280: nop

    // 0x80089284: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x80089288: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x8008928C: slti        $at, $t7, 0xFF
    ctx->r1 = SIGNED(ctx->r15) < 0XFF ? 1 : 0;
    // 0x80089290: bne         $at, $zero, L_80089228
    if (ctx->r1 != 0) {
        // 0x80089294: sh          $t5, 0x2C($sp)
        MEM_H(0X2C, ctx->r29) = ctx->r13;
            goto L_80089228;
    }
    // 0x80089294: sh          $t5, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r13;
L_80089298:
    // 0x80089298: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8008929C: nop

    // 0x800892A0: beq         $t3, $zero, L_80089D0C
    if (ctx->r11 == 0) {
        // 0x800892A4: nop
    
            goto L_80089D0C;
    }
    // 0x800892A4: nop

    // 0x800892A8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800892AC: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800892B0: lhu         $t0, 0x3B50($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X3B50);
    // 0x800892B4: lhu         $t9, 0x5E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X5E);
    // 0x800892B8: lw          $t4, 0x80($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X80);
    // 0x800892BC: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800892C0: addu        $t2, $t8, $t4
    ctx->r10 = ADD32(ctx->r24, ctx->r12);
    // 0x800892C4: sb          $t1, 0x364($t2)
    MEM_B(0X364, ctx->r10) = ctx->r9;
    // 0x800892C8: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800892CC: lhu         $t3, 0x2E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2E);
    // 0x800892D0: lw          $t7, 0x350($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X350);
    // 0x800892D4: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x800892D8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800892DC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800892E0: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800892E4: lw          $t5, 0x80($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X80);
    // 0x800892E8: addu        $t1, $t8, $t4
    ctx->r9 = ADD32(ctx->r24, ctx->r12);
    // 0x800892EC: sb          $t5, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r13;
    // 0x800892F0: lhu         $t2, 0x5C($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X5C);
    // 0x800892F4: nop

    // 0x800892F8: andi        $t6, $t2, 0x1
    ctx->r14 = ctx->r10 & 0X1;
    // 0x800892FC: beq         $t6, $zero, L_800899C4
    if (ctx->r14 == 0) {
        // 0x80089300: nop
    
            goto L_800899C4;
    }
    // 0x80089300: nop

    // 0x80089304: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x80089308: beq         $t3, $zero, L_80089660
    if (ctx->r11 == 0) {
        // 0x8008930C: nop
    
            goto L_80089660;
    }
    // 0x8008930C: nop

    // 0x80089310: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80089314: lhu         $a1, 0x5E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X5E);
    // 0x80089318: jal         0x80087478
    // 0x8008931C: nop

    Audio2_DecodeFixedSprite(rdram, ctx);
        goto after_4;
    // 0x8008931C: nop

    after_4:
    // 0x80089320: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80089324: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80089328: lw          $t8, 0x80($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X80);
    // 0x8008932C: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x80089330: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x80089334: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x80089338: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008933C: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80089340: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80089344: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80089348: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8008934C: lw          $t3, 0x80($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X80);
    // 0x80089350: lw          $t2, 0x18($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X18);
    // 0x80089354: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80089358: addu        $t8, $t2, $t9
    ctx->r24 = ADD32(ctx->r10, ctx->r25);
    // 0x8008935C: sw          $t1, 0x528($t8)
    MEM_W(0X528, ctx->r24) = ctx->r9;
    // 0x80089360: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80089364: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80089368: lw          $t6, 0x80($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X80);
    // 0x8008936C: lw          $t5, 0x18($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X18);
    // 0x80089370: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80089374: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x80089378: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008937C: sll         $t4, $t0, 1
    ctx->r12 = S32(ctx->r8 << 1);
    // 0x80089380: addu        $t2, $t5, $t3
    ctx->r10 = ADD32(ctx->r13, ctx->r11);
    // 0x80089384: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80089388: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8008938C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80089390: lw          $t7, 0x80($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X80);
    // 0x80089394: lw          $t0, 0x18($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X18);
    // 0x80089398: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8008939C: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x800893A0: addu        $t5, $t0, $t6
    ctx->r13 = ADD32(ctx->r8, ctx->r14);
    // 0x800893A4: sw          $t1, 0x630($t5)
    MEM_W(0X630, ctx->r13) = ctx->r9;
    // 0x800893A8: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800893AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800893B0: lw          $t9, 0x80($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X80);
    // 0x800893B4: lw          $t2, 0x18($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X18);
    // 0x800893B8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800893BC: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800893C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800893C4: addu        $t7, $t2, $t8
    ctx->r15 = ADD32(ctx->r10, ctx->r24);
    // 0x800893C8: sb          $t3, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r11;
    // 0x800893CC: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800893D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800893D4: lw          $t5, 0x80($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X80);
    // 0x800893D8: lw          $t1, 0x18($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X18);
    // 0x800893DC: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800893E0: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x800893E4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800893E8: addu        $t9, $t1, $t4
    ctx->r25 = ADD32(ctx->r9, ctx->r12);
    // 0x800893EC: sb          $t0, 0x9($t9)
    MEM_B(0X9, ctx->r25) = ctx->r8;
    // 0x800893F0: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x800893F4: nop

    // 0x800893F8: lw          $t3, 0x80($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X80);
    // 0x800893FC: lw          $t8, 0x18($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X18);
    // 0x80089400: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80089404: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x80089408: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008940C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80089410: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x80089414: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80089418: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x8008941C: lw          $t4, 0x80($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X80);
    // 0x80089420: lw          $t1, 0x18($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X18);
    // 0x80089424: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x80089428: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8008942C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80089430: addu        $t9, $t1, $t0
    ctx->r25 = ADD32(ctx->r9, ctx->r8);
    // 0x80089434: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80089438: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8008943C: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80089440: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80089444: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80089448: beq         $s0, $zero, L_800894A0
    if (ctx->r16 == 0) {
        // 0x8008944C: sw          $t3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r11;
            goto L_800894A0;
    }
    // 0x8008944C: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80089450:
    // 0x80089450: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80089454: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80089458: lb          $t4, 0x1($t6)
    ctx->r12 = MEM_B(ctx->r14, 0X1);
    // 0x8008945C: lb          $t5, 0x0($t6)
    ctx->r13 = MEM_B(ctx->r14, 0X0);
    // 0x80089460: sll         $t1, $t4, 8
    ctx->r9 = S32(ctx->r12 << 8);
    // 0x80089464: andi        $t0, $t1, 0xFF00
    ctx->r8 = ctx->r9 & 0XFF00;
    // 0x80089468: andi        $t2, $t5, 0xFF
    ctx->r10 = ctx->r13 & 0XFF;
    // 0x8008946C: addu        $t9, $t2, $t0
    ctx->r25 = ADD32(ctx->r10, ctx->r8);
    // 0x80089470: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
    // 0x80089474: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80089478: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8008947C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80089480: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x80089484: addiu       $t1, $t4, -0x1
    ctx->r9 = ADD32(ctx->r12, -0X1);
    // 0x80089488: addiu       $t7, $t8, 0x2
    ctx->r15 = ADD32(ctx->r24, 0X2);
    // 0x8008948C: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x80089490: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80089494: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80089498: bne         $s0, $zero, L_80089450
    if (ctx->r16 != 0) {
        // 0x8008949C: sw          $t1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r9;
            goto L_80089450;
    }
    // 0x8008949C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_800894A0:
    // 0x800894A0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800894A4: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x800894A8: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x800894AC: lhu         $t5, 0x5C($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X5C);
    // 0x800894B0: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x800894B4: addiu       $t8, $t3, 0x1F
    ctx->r24 = ADD32(ctx->r11, 0X1F);
    // 0x800894B8: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800894BC: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x800894C0: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x800894C4: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x800894C8: beq         $t6, $zero, L_800895D0
    if (ctx->r14 == 0) {
        // 0x800894CC: sw          $t7, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r15;
            goto L_800895D0;
    }
    // 0x800894CC: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x800894D0: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800894D4: nop

    // 0x800894D8: lw          $t0, 0x80($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X80);
    // 0x800894DC: lw          $t1, 0x18($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X18);
    // 0x800894E0: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x800894E4: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x800894E8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800894EC: addu        $t9, $t1, $t2
    ctx->r25 = ADD32(ctx->r9, ctx->r10);
    // 0x800894F0: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x800894F4: andi        $t2, $t5, 0x8
    ctx->r10 = ctx->r13 & 0X8;
    // 0x800894F8: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x800894FC: lw          $t7, 0x80($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X80);
    // 0x80089500: lw          $t8, 0x18($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X18);
    // 0x80089504: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80089508: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8008950C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80089510: addu        $t0, $t8, $t6
    ctx->r8 = ADD32(ctx->r24, ctx->r14);
    // 0x80089514: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80089518: beq         $t2, $zero, L_80089578
    if (ctx->r10 == 0) {
        // 0x8008951C: sw          $t1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r9;
            goto L_80089578;
    }
    // 0x8008951C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80089520: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
L_80089524:
    // 0x80089524: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80089528: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8008952C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80089530: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80089534: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x80089538: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x8008953C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80089540: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80089544: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80089548: lh          $t0, -0x2($t6)
    ctx->r8 = MEM_H(ctx->r14, -0X2);
    // 0x8008954C: sll         $t2, $t5, 1
    ctx->r10 = S32(ctx->r13 << 1);
    // 0x80089550: addu        $t4, $t9, $t2
    ctx->r12 = ADD32(ctx->r25, ctx->r10);
    // 0x80089554: sh          $t0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r8;
    // 0x80089558: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8008955C: nop

    // 0x80089560: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80089564: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x80089568: bne         $at, $zero, L_80089524
    if (ctx->r1 != 0) {
        // 0x8008956C: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_80089524;
    }
    // 0x8008956C: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x80089570: b           L_80089C14
    // 0x80089574: nop

        goto L_80089C14;
    // 0x80089574: nop

L_80089578:
    // 0x80089578: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
L_8008957C:
    // 0x8008957C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80089580: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80089584: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80089588: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8008958C: addu        $t3, $t6, $t1
    ctx->r11 = ADD32(ctx->r14, ctx->r9);
    // 0x80089590: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80089594: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80089598: addu        $t2, $t9, $t5
    ctx->r10 = ADD32(ctx->r25, ctx->r13);
    // 0x8008959C: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x800895A0: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x800895A4: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800895A8: addu        $t3, $t1, $t7
    ctx->r11 = ADD32(ctx->r9, ctx->r15);
    // 0x800895AC: sh          $t0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r8;
    // 0x800895B0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800895B4: nop

    // 0x800895B8: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x800895BC: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x800895C0: bne         $at, $zero, L_8008957C
    if (ctx->r1 != 0) {
        // 0x800895C4: sw          $t5, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r13;
            goto L_8008957C;
    }
    // 0x800895C4: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x800895C8: b           L_80089C14
    // 0x800895CC: nop

        goto L_80089C14;
    // 0x800895CC: nop

L_800895D0:
    // 0x800895D0: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x800895D4: nop

    // 0x800895D8: lw          $t6, 0x80($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X80);
    // 0x800895DC: lw          $t4, 0x18($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X18);
    // 0x800895E0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800895E4: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800895E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800895EC: addu        $t1, $t4, $t8
    ctx->r9 = ADD32(ctx->r12, ctx->r24);
    // 0x800895F0: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800895F4: nop

    // 0x800895F8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800895FC: lw          $t3, 0x80($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X80);
    // 0x80089600: lw          $t0, 0x18($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X18);
    // 0x80089604: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80089608: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x8008960C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80089610: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
    // 0x80089614: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80089618: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8008961C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_80089620:
    // 0x80089620: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80089624: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80089628: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8008962C: addu        $t1, $t4, $t8
    ctx->r9 = ADD32(ctx->r12, ctx->r24);
    // 0x80089630: sll         $t7, $t1, 1
    ctx->r15 = S32(ctx->r9 << 1);
    // 0x80089634: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x80089638: addu        $t0, $t3, $t2
    ctx->r8 = ADD32(ctx->r11, ctx->r10);
    // 0x8008963C: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x80089640: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80089644: nop

    // 0x80089648: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8008964C: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x80089650: bne         $at, $zero, L_80089620
    if (ctx->r1 != 0) {
        // 0x80089654: sw          $t5, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r13;
            goto L_80089620;
    }
    // 0x80089654: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x80089658: b           L_80089C14
    // 0x8008965C: nop

        goto L_80089C14;
    // 0x8008965C: nop

L_80089660:
    // 0x80089660: lhu         $t6, 0x5C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X5C);
    // 0x80089664: nop

    // 0x80089668: andi        $t4, $t6, 0x4
    ctx->r12 = ctx->r14 & 0X4;
    // 0x8008966C: beq         $t4, $zero, L_80089818
    if (ctx->r12 == 0) {
        // 0x80089670: nop
    
            goto L_80089818;
    }
    // 0x80089670: nop

    // 0x80089674: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80089678: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8008967C: lhu         $a1, 0x5E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X5E);
    // 0x80089680: jal         0x80087478
    // 0x80089684: addu        $a0, $t8, $t1
    ctx->r4 = ADD32(ctx->r24, ctx->r9);
    Audio2_DecodeFixedSprite(rdram, ctx);
        goto after_5;
    // 0x80089684: addu        $a0, $t8, $t1
    ctx->r4 = ADD32(ctx->r24, ctx->r9);
    after_5:
    // 0x80089688: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8008968C: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80089690: lw          $t0, 0x80($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X80);
    // 0x80089694: lw          $t2, 0x18($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X18);
    // 0x80089698: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8008969C: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x800896A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800896A4: addu        $t5, $t2, $t9
    ctx->r13 = ADD32(ctx->r10, ctx->r25);
    // 0x800896A8: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800896AC: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800896B0: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800896B4: lw          $t1, 0x80($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X80);
    // 0x800896B8: lw          $t8, 0x18($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X18);
    // 0x800896BC: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800896C0: addu        $t0, $t8, $t3
    ctx->r8 = ADD32(ctx->r24, ctx->r11);
    // 0x800896C4: sw          $t6, 0x528($t0)
    MEM_W(0X528, ctx->r8) = ctx->r14;
    // 0x800896C8: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800896CC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800896D0: lw          $t5, 0x80($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X80);
    // 0x800896D4: lw          $t7, 0x18($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X18);
    // 0x800896D8: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800896DC: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x800896E0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800896E4: addu        $t1, $t7, $t4
    ctx->r9 = ADD32(ctx->r15, ctx->r12);
    // 0x800896E8: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x800896EC: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800896F0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800896F4: lw          $t0, 0x80($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X80);
    // 0x800896F8: lw          $t6, 0x18($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X18);
    // 0x800896FC: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80089700: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x80089704: sw          $t8, 0x630($t5)
    MEM_W(0X630, ctx->r13) = ctx->r24;
    // 0x80089708: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8008970C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80089710: lw          $t1, 0x80($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X80);
    // 0x80089714: lw          $t2, 0x18($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X18);
    // 0x80089718: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8008971C: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80089720: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80089724: addu        $t0, $t2, $t3
    ctx->r8 = ADD32(ctx->r10, ctx->r11);
    // 0x80089728: sb          $t7, 0x8($t0)
    MEM_B(0X8, ctx->r8) = ctx->r15;
    // 0x8008972C: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80089730: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80089734: lw          $t5, 0x80($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X80);
    // 0x80089738: lw          $t8, 0x18($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X18);
    // 0x8008973C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80089740: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x80089744: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80089748: addu        $t1, $t8, $t4
    ctx->r9 = ADD32(ctx->r24, ctx->r12);
    // 0x8008974C: sb          $t6, 0x9($t1)
    MEM_B(0X9, ctx->r9) = ctx->r14;
    // 0x80089750: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80089754: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80089758: lw          $t7, 0x80($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X80);
    // 0x8008975C: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x80089760: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80089764: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80089768: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8008976C: addu        $t9, $t3, $t0
    ctx->r25 = ADD32(ctx->r11, ctx->r8);
    // 0x80089770: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x80089774: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80089778: addu        $t4, $t5, $t8
    ctx->r12 = ADD32(ctx->r13, ctx->r24);
    // 0x8008977C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x80089780: lw          $t1, 0x80($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X80);
    // 0x80089784: lw          $t6, 0x18($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X18);
    // 0x80089788: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8008978C: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x80089790: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80089794: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
    // 0x80089798: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8008979C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800897A0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800897A4: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800897A8: beq         $s0, $zero, L_800897F4
    if (ctx->r16 == 0) {
        // 0x800897AC: sw          $t0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r8;
            goto L_800897F4;
    }
    // 0x800897AC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_800897B0:
    // 0x800897B0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800897B4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800897B8: lb          $t4, 0x0($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X0);
    // 0x800897BC: nop

    // 0x800897C0: sll         $t2, $t4, 8
    ctx->r10 = S32(ctx->r12 << 8);
    // 0x800897C4: sh          $t2, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r10;
    // 0x800897C8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800897CC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800897D0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800897D4: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800897D8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800897DC: addiu       $t0, $t3, 0x1
    ctx->r8 = ADD32(ctx->r11, 0X1);
    // 0x800897E0: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800897E4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800897E8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x800897EC: bne         $s0, $zero, L_800897B0
    if (ctx->r16 != 0) {
        // 0x800897F0: sw          $t9, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r25;
            goto L_800897B0;
    }
    // 0x800897F0: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
L_800897F4:
    // 0x800897F4: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800897F8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800897FC: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80089800: addu        $t2, $t5, $t4
    ctx->r10 = ADD32(ctx->r13, ctx->r12);
    // 0x80089804: addiu       $t1, $t2, 0x1F
    ctx->r9 = ADD32(ctx->r10, 0X1F);
    // 0x80089808: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x8008980C: and         $t6, $t1, $at
    ctx->r14 = ctx->r9 & ctx->r1;
    // 0x80089810: b           L_80089C14
    // 0x80089814: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
        goto L_80089C14;
    // 0x80089814: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
L_80089818:
    // 0x80089818: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8008981C: lhu         $a1, 0x5E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X5E);
    // 0x80089820: jal         0x80087478
    // 0x80089824: nop

    Audio2_DecodeFixedSprite(rdram, ctx);
        goto after_6;
    // 0x80089824: nop

    after_6:
    // 0x80089828: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8008982C: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80089830: lw          $t8, 0x80($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X80);
    // 0x80089834: lw          $t0, 0x18($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X18);
    // 0x80089838: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8008983C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80089840: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80089844: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
    // 0x80089848: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8008984C: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80089850: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80089854: lw          $t6, 0x80($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X80);
    // 0x80089858: lw          $t1, 0x18($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X18);
    // 0x8008985C: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80089860: addu        $t8, $t1, $t3
    ctx->r24 = ADD32(ctx->r9, ctx->r11);
    // 0x80089864: sw          $t4, 0x528($t8)
    MEM_W(0X528, ctx->r24) = ctx->r12;
    // 0x80089868: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8008986C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80089870: lw          $t5, 0x80($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X80);
    // 0x80089874: lw          $t7, 0x18($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X18);
    // 0x80089878: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x8008987C: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x80089880: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80089884: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x80089888: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8008988C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80089890: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80089894: lw          $t8, 0x80($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X80);
    // 0x80089898: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x8008989C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800898A0: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x800898A4: sw          $t1, 0x630($t5)
    MEM_W(0X630, ctx->r13) = ctx->r9;
    // 0x800898A8: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x800898AC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800898B0: lw          $t6, 0x80($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X80);
    // 0x800898B4: lw          $t0, 0x18($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X18);
    // 0x800898B8: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x800898BC: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x800898C0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800898C4: addu        $t8, $t0, $t3
    ctx->r24 = ADD32(ctx->r8, ctx->r11);
    // 0x800898C8: sb          $t7, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r15;
    // 0x800898CC: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800898D0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800898D4: lw          $t5, 0x80($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X80);
    // 0x800898D8: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x800898DC: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x800898E0: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x800898E4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800898E8: addu        $t6, $t1, $t2
    ctx->r14 = ADD32(ctx->r9, ctx->r10);
    // 0x800898EC: sb          $t4, 0x9($t6)
    MEM_B(0X9, ctx->r14) = ctx->r12;
    // 0x800898F0: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800898F4: nop

    // 0x800898F8: lw          $t7, 0x80($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X80);
    // 0x800898FC: lw          $t3, 0x18($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X18);
    // 0x80089900: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80089904: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80089908: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008990C: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x80089910: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x80089914: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80089918: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x8008991C: lw          $t2, 0x80($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X80);
    // 0x80089920: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x80089924: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80089928: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x8008992C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80089930: addu        $t6, $t1, $t4
    ctx->r14 = ADD32(ctx->r9, ctx->r12);
    // 0x80089934: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80089938: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8008993C: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80089940: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x80089944: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80089948: beq         $s0, $zero, L_8008999C
    if (ctx->r16 == 0) {
        // 0x8008994C: sw          $t7, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r15;
            goto L_8008999C;
    }
    // 0x8008994C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
L_80089950:
    // 0x80089950: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80089954: jal         0x8008C0E0
    // 0x80089958: nop

    Audio2_ReadS16LE(rdram, ctx);
        goto after_7;
    // 0x80089958: nop

    after_7:
    // 0x8008995C: sra         $t9, $v0, 8
    ctx->r25 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80089960: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80089964: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x80089968: sra         $t0, $t5, 16
    ctx->r8 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8008996C: sb          $t0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r8;
    // 0x80089970: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80089974: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80089978: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8008997C: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80089980: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x80089984: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x80089988: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x8008998C: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80089990: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80089994: bne         $s0, $zero, L_80089950
    if (ctx->r16 != 0) {
        // 0x80089998: sw          $t8, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r24;
            goto L_80089950;
    }
    // 0x80089998: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_8008999C:
    // 0x8008999C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800899A0: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x800899A4: sll         $t0, $t5, 1
    ctx->r8 = S32(ctx->r13 << 1);
    // 0x800899A8: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x800899AC: addiu       $t1, $t2, 0x1F
    ctx->r9 = ADD32(ctx->r10, 0X1F);
    // 0x800899B0: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800899B4: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x800899B8: and         $t4, $t1, $at
    ctx->r12 = ctx->r9 & ctx->r1;
    // 0x800899BC: b           L_80089C14
    // 0x800899C0: sw          $t4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r12;
        goto L_80089C14;
    // 0x800899C0: sw          $t4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r12;
L_800899C4:
    // 0x800899C4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800899C8: lhu         $a1, 0x5E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X5E);
    // 0x800899CC: jal         0x80087478
    // 0x800899D0: nop

    Audio2_DecodeFixedSprite(rdram, ctx);
        goto after_8;
    // 0x800899D0: nop

    after_8:
    // 0x800899D4: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800899D8: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800899DC: lw          $t8, 0x80($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X80);
    // 0x800899E0: lw          $t3, 0x18($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X18);
    // 0x800899E4: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x800899E8: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x800899EC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800899F0: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x800899F4: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800899F8: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x800899FC: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80089A00: lw          $t4, 0x80($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X80);
    // 0x80089A04: lw          $t1, 0x18($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X18);
    // 0x80089A08: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80089A0C: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x80089A10: sw          $t0, 0x528($t8)
    MEM_W(0X528, ctx->r24) = ctx->r8;
    // 0x80089A14: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80089A18: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80089A1C: lw          $t9, 0x80($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X80);
    // 0x80089A20: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x80089A24: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80089A28: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80089A2C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80089A30: addu        $t4, $t6, $t2
    ctx->r12 = ADD32(ctx->r14, ctx->r10);
    // 0x80089A34: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80089A38: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80089A3C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80089A40: lw          $t8, 0x80($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X80);
    // 0x80089A44: lw          $t0, 0x18($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X18);
    // 0x80089A48: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80089A4C: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x80089A50: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80089A54: addu        $t9, $t0, $t5
    ctx->r25 = ADD32(ctx->r8, ctx->r13);
    // 0x80089A58: sb          $t1, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r9;
    // 0x80089A5C: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80089A60: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80089A64: lw          $t4, 0x80($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X80);
    // 0x80089A68: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x80089A6C: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80089A70: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x80089A74: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80089A78: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80089A7C: sb          $t6, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r14;
    // 0x80089A80: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80089A84: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80089A88: lw          $t9, 0x80($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X80);
    // 0x80089A8C: lw          $t1, 0x18($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X18);
    // 0x80089A90: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80089A94: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x80089A98: sw          $t0, 0x630($t4)
    MEM_W(0X630, ctx->r12) = ctx->r8;
    // 0x80089A9C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80089AA0: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80089AA4: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80089AA8: lw          $t8, 0x80($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X80);
    // 0x80089AAC: lw          $t6, 0x18($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X18);
    // 0x80089AB0: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80089AB4: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x80089AB8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80089ABC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80089AC0: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80089AC4: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x80089AC8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80089ACC: lhu         $t6, 0x5C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X5C);
    // 0x80089AD0: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x80089AD4: addiu       $t3, $t4, 0x1F
    ctx->r11 = ADD32(ctx->r12, 0X1F);
    // 0x80089AD8: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80089ADC: sw          $t4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r12;
    // 0x80089AE0: and         $t8, $t3, $at
    ctx->r24 = ctx->r11 & ctx->r1;
    // 0x80089AE4: andi        $t5, $t6, 0x4
    ctx->r13 = ctx->r14 & 0X4;
    // 0x80089AE8: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x80089AEC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80089AF0: beq         $t5, $zero, L_80089BB8
    if (ctx->r13 == 0) {
        // 0x80089AF4: sw          $t1, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r9;
            goto L_80089BB8;
    }
    // 0x80089AF4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80089AF8: lw          $t1, 0x80($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X80);
    // 0x80089AFC: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80089B00: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80089B04: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80089B08: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80089B0C: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80089B10: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80089B14: andi        $t3, $t6, 0x8
    ctx->r11 = ctx->r14 & 0X8;
    // 0x80089B18: beq         $t3, $zero, L_80089B6C
    if (ctx->r11 == 0) {
        // 0x80089B1C: sw          $t4, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r12;
            goto L_80089B6C;
    }
    // 0x80089B1C: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80089B20: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
L_80089B24:
    // 0x80089B24: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80089B28: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80089B2C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80089B30: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80089B34: subu        $t7, $t8, $t5
    ctx->r15 = SUB32(ctx->r24, ctx->r13);
    // 0x80089B38: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x80089B3C: lb          $t0, -0x1($t9)
    ctx->r8 = MEM_B(ctx->r25, -0X1);
    // 0x80089B40: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x80089B44: addu        $t6, $t1, $t4
    ctx->r14 = ADD32(ctx->r9, ctx->r12);
    // 0x80089B48: sb          $t0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r8;
    // 0x80089B4C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80089B50: nop

    // 0x80089B54: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x80089B58: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x80089B5C: bne         $at, $zero, L_80089B24
    if (ctx->r1 != 0) {
        // 0x80089B60: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_80089B24;
    }
    // 0x80089B60: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80089B64: b           L_80089C14
    // 0x80089B68: nop

        goto L_80089C14;
    // 0x80089B68: nop

L_80089B6C:
    // 0x80089B6C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
L_80089B70:
    // 0x80089B70: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80089B74: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80089B78: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80089B7C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80089B80: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x80089B84: addu        $t1, $t2, $t5
    ctx->r9 = ADD32(ctx->r10, ctx->r13);
    // 0x80089B88: lb          $t4, 0x0($t1)
    ctx->r12 = MEM_B(ctx->r9, 0X0);
    // 0x80089B8C: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x80089B90: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x80089B94: sb          $t4, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r12;
    // 0x80089B98: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80089B9C: nop

    // 0x80089BA0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80089BA4: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x80089BA8: bne         $at, $zero, L_80089B70
    if (ctx->r1 != 0) {
        // 0x80089BAC: sw          $t9, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r25;
            goto L_80089B70;
    }
    // 0x80089BAC: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80089BB0: b           L_80089C14
    // 0x80089BB4: nop

        goto L_80089C14;
    // 0x80089BB4: nop

L_80089BB8:
    // 0x80089BB8: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80089BBC: nop

    // 0x80089BC0: lw          $t0, 0x80($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X80);
    // 0x80089BC4: lw          $t1, 0x18($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X18);
    // 0x80089BC8: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80089BCC: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80089BD0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80089BD4: addu        $t5, $t1, $t7
    ctx->r13 = ADD32(ctx->r9, ctx->r15);
    // 0x80089BD8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80089BDC: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80089BE0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
L_80089BE4:
    // 0x80089BE4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80089BE8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80089BEC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80089BF0: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x80089BF4: addu        $t2, $t9, $t8
    ctx->r10 = ADD32(ctx->r25, ctx->r24);
    // 0x80089BF8: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x80089BFC: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80089C00: nop

    // 0x80089C04: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80089C08: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x80089C0C: bne         $at, $zero, L_80089BE4
    if (ctx->r1 != 0) {
        // 0x80089C10: sw          $t1, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r9;
            goto L_80089BE4;
    }
    // 0x80089C10: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
L_80089C14:
    // 0x80089C14: lhu         $t7, 0x5C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X5C);
    // 0x80089C18: nop

    // 0x80089C1C: andi        $t5, $t7, 0x4
    ctx->r13 = ctx->r15 & 0X4;
    // 0x80089C20: beq         $t5, $zero, L_80089CD0
    if (ctx->r13 == 0) {
        // 0x80089C24: nop
    
            goto L_80089CD0;
    }
    // 0x80089C24: nop

    // 0x80089C28: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80089C2C: nop

    // 0x80089C30: lw          $t3, 0x80($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X80);
    // 0x80089C34: lw          $t4, 0x18($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X18);
    // 0x80089C38: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80089C3C: subu        $t9, $t9, $t3
    ctx->r25 = SUB32(ctx->r25, ctx->r11);
    // 0x80089C40: sll         $t0, $t3, 2
    ctx->r8 = S32(ctx->r11 << 2);
    // 0x80089C44: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80089C48: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x80089C4C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80089C50: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x80089C54: addiu       $t2, $t8, 0x948
    ctx->r10 = ADD32(ctx->r24, 0X948);
    // 0x80089C58: addu        $t1, $t4, $t0
    ctx->r9 = ADD32(ctx->r12, ctx->r8);
    // 0x80089C5C: sw          $t2, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r10;
    // 0x80089C60: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80089C64: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80089C68: lw          $t9, 0x80($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X80);
    // 0x80089C6C: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x80089C70: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80089C74: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80089C78: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80089C7C: addu        $t3, $t6, $t8
    ctx->r11 = ADD32(ctx->r14, ctx->r24);
    // 0x80089C80: sw          $t7, 0x948($t3)
    MEM_W(0X948, ctx->r11) = ctx->r15;
    // 0x80089C84: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80089C88: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80089C8C: lw          $t1, 0x80($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X80);
    // 0x80089C90: lw          $t2, 0x18($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X18);
    // 0x80089C94: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x80089C98: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x80089C9C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80089CA0: addu        $t9, $t2, $t5
    ctx->r25 = ADD32(ctx->r10, ctx->r13);
    // 0x80089CA4: sw          $t4, 0x94C($t9)
    MEM_W(0X94C, ctx->r25) = ctx->r12;
    // 0x80089CA8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80089CAC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80089CB0: lw          $t3, 0x80($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X80);
    // 0x80089CB4: lw          $t7, 0x18($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X18);
    // 0x80089CB8: sll         $t0, $t3, 2
    ctx->r8 = S32(ctx->r11 << 2);
    // 0x80089CBC: subu        $t0, $t0, $t3
    ctx->r8 = SUB32(ctx->r8, ctx->r11);
    // 0x80089CC0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80089CC4: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80089CC8: b           L_80089CF4
    // 0x80089CCC: sw          $t6, 0x950($t1)
    MEM_W(0X950, ctx->r9) = ctx->r14;
        goto L_80089CF4;
    // 0x80089CCC: sw          $t6, 0x950($t1)
    MEM_W(0X950, ctx->r9) = ctx->r14;
L_80089CD0:
    // 0x80089CD0: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80089CD4: nop

    // 0x80089CD8: lw          $t4, 0x80($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X80);
    // 0x80089CDC: lw          $t5, 0x18($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X18);
    // 0x80089CE0: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80089CE4: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x80089CE8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80089CEC: addu        $t8, $t5, $t9
    ctx->r24 = ADD32(ctx->r13, ctx->r25);
    // 0x80089CF0: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
L_80089CF4:
    // 0x80089CF4: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80089CF8: nop

    // 0x80089CFC: lw          $t7, 0x80($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X80);
    // 0x80089D00: nop

    // 0x80089D04: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x80089D08: sw          $t0, 0x80($t3)
    MEM_W(0X80, ctx->r11) = ctx->r8;
L_80089D0C:
    // 0x80089D0C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80089D10: lbu         $t5, 0x65($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X65);
    // 0x80089D14: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80089D18: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80089D1C: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80089D20: addiu       $t1, $t6, 0x10
    ctx->r9 = ADD32(ctx->r14, 0X10);
    // 0x80089D24: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x80089D28: bne         $at, $zero, L_80089208
    if (ctx->r1 != 0) {
        // 0x80089D2C: sw          $t1, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r9;
            goto L_80089208;
    }
    // 0x80089D2C: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
L_80089D30:
    // 0x80089D30: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80089D34: nop

    // 0x80089D38: lw          $t8, 0x84($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X84);
    // 0x80089D3C: nop

    // 0x80089D40: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80089D44: sw          $t7, 0x84($t9)
    MEM_W(0X84, ctx->r25) = ctx->r15;
    // 0x80089D48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80089D4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80089D50: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x80089D54: jr          $ra
    // 0x80089D58: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80089D58: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}

RECOMP_FUNC void Audio2_StopAllSFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80089D60: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80089D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80089D68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80089D6C: jal         0x80088C14
    // 0x80089D70: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    Audio2_GFXDone_SendStopMessage(rdram, ctx);
        goto after_0;
    // 0x80089D70: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80089D74: jal         0x8008A7C0
    // 0x80089D78: nop

    Audio2_ClearScheduledSFX(rdram, ctx);
        goto after_1;
    // 0x80089D78: nop

    after_1:
    // 0x80089D7C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80089D80: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80089D84: lw          $t7, 0x8C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8C);
    // 0x80089D88: nop

    // 0x80089D8C: beq         $t7, $zero, L_80089E54
    if (ctx->r15 == 0) {
        // 0x80089D90: nop
    
            goto L_80089E54;
    }
    // 0x80089D90: nop

L_80089D94:
    // 0x80089D94: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80089D98: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80089D9C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80089DA0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80089DA4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80089DA8: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x80089DAC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80089DB0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80089DB4: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80089DB8: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80089DBC: lbu         $t3, 0x27($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X27);
    // 0x80089DC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089DC4: bne         $t3, $at, L_80089DE4
    if (ctx->r11 != ctx->r1) {
        // 0x80089DC8: nop
    
            goto L_80089DE4;
    }
    // 0x80089DC8: nop

    // 0x80089DCC: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x80089DD0: jal         0x800B8B60
    // 0x80089DD4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_2;
    // 0x80089DD4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_2:
    // 0x80089DD8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80089DDC: nop

    // 0x80089DE0: sb          $zero, 0x27($t4)
    MEM_B(0X27, ctx->r12) = 0;
L_80089DE4:
    // 0x80089DE4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80089DE8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80089DEC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80089DF0: addu        $t0, $t5, $t7
    ctx->r8 = ADD32(ctx->r13, ctx->r15);
    // 0x80089DF4: sw          $zero, 0x20($t0)
    MEM_W(0X20, ctx->r8) = 0;
    // 0x80089DF8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80089DFC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80089E00: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x80089E04: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80089E08: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80089E0C: addu        $t8, $t9, $t3
    ctx->r24 = ADD32(ctx->r25, ctx->r11);
    // 0x80089E10: lw          $t2, 0x110($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X110);
    // 0x80089E14: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80089E18: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x80089E1C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80089E20: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80089E24: nop

    // 0x80089E28: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x80089E2C: sb          $t4, 0x354($t7)
    MEM_B(0X354, ctx->r15) = ctx->r12;
    // 0x80089E30: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80089E34: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80089E38: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80089E3C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80089E40: lw          $t3, 0x8C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8C);
    // 0x80089E44: nop

    // 0x80089E48: sltu        $at, $t1, $t3
    ctx->r1 = ctx->r9 < ctx->r11 ? 1 : 0;
    // 0x80089E4C: bne         $at, $zero, L_80089D94
    if (ctx->r1 != 0) {
        // 0x80089E50: nop
    
            goto L_80089D94;
    }
    // 0x80089E50: nop

L_80089E54:
    // 0x80089E54: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80089E58: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80089E5C: lw          $t2, 0x8C($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X8C);
    // 0x80089E60: nop

    // 0x80089E64: srl         $t6, $t2, 1
    ctx->r14 = S32(U32(ctx->r10) >> 1);
    // 0x80089E68: beq         $t6, $zero, L_80089EC0
    if (ctx->r14 == 0) {
        // 0x80089E6C: nop
    
            goto L_80089EC0;
    }
    // 0x80089E6C: nop

L_80089E70:
    // 0x80089E70: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80089E74: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80089E78: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80089E7C: addu        $t0, $t5, $t7
    ctx->r8 = ADD32(ctx->r13, ctx->r15);
    // 0x80089E80: sw          $zero, 0x60($t0)
    MEM_W(0X60, ctx->r8) = 0;
    // 0x80089E84: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80089E88: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80089E8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80089E90: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80089E94: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80089E98: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x80089E9C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80089EA0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80089EA4: sb          $t9, -0x7220($at)
    MEM_B(-0X7220, ctx->r1) = ctx->r25;
    // 0x80089EA8: lw          $t6, 0x8C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X8C);
    // 0x80089EAC: nop

    // 0x80089EB0: srl         $t4, $t6, 1
    ctx->r12 = S32(U32(ctx->r14) >> 1);
    // 0x80089EB4: sltu        $at, $t8, $t4
    ctx->r1 = ctx->r24 < ctx->r12 ? 1 : 0;
    // 0x80089EB8: bne         $at, $zero, L_80089E70
    if (ctx->r1 != 0) {
        // 0x80089EBC: nop
    
            goto L_80089E70;
    }
    // 0x80089EBC: nop

L_80089EC0:
    // 0x80089EC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80089EC4: jal         0x80088BA4
    // 0x80089EC8: nop

    Audio2_GFXDone_SendStartMessage(rdram, ctx);
        goto after_3;
    // 0x80089EC8: nop

    after_3:
    // 0x80089ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80089ED0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80089ED4: jr          $ra
    // 0x80089ED8: nop

    return;
    // 0x80089ED8: nop

;}

RECOMP_FUNC void Audio2_FindSFXChannel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EDC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80089EE0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80089EE4: addiu       $t7, $t7, 0x3B54
    ctx->r15 = ADD32(ctx->r15, 0X3B54);
    // 0x80089EE8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80089EEC: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x80089EF0: addiu       $t6, $sp, 0x8
    ctx->r14 = ADD32(ctx->r29, 0X8);
L_80089EF4:
    // 0x80089EF4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80089EF8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80089EFC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80089F00: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x80089F04: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80089F08: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x80089F0C: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80089F10: bne         $t7, $t0, L_80089EF4
    if (ctx->r15 != ctx->r8) {
        // 0x80089F14: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_80089EF4;
    }
    // 0x80089F14: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x80089F18: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80089F1C: nop

    // 0x80089F20: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80089F24: sb          $zero, 0x7($sp)
    MEM_B(0X7, ctx->r29) = 0;
    // 0x80089F28: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80089F2C: sb          $zero, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = 0;
    // 0x80089F30: lw          $t1, 0x8C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8C);
    // 0x80089F34: nop

    // 0x80089F38: srl         $t2, $t1, 1
    ctx->r10 = S32(U32(ctx->r9) >> 1);
    // 0x80089F3C: beq         $t2, $zero, L_80089FF0
    if (ctx->r10 == 0) {
        // 0x80089F40: nop
    
            goto L_80089FF0;
    }
    // 0x80089F40: nop

L_80089F44:
    // 0x80089F44: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x80089F48: nop

    // 0x80089F4C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80089F50: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80089F54: lw          $t9, 0x20($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X20);
    // 0x80089F58: nop

    // 0x80089F5C: bne         $t9, $zero, L_80089F6C
    if (ctx->r25 != 0) {
        // 0x80089F60: nop
    
            goto L_80089F6C;
    }
    // 0x80089F60: nop

    // 0x80089F64: b           L_8008A080
    // 0x80089F68: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_8008A080;
    // 0x80089F68: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80089F6C:
    // 0x80089F6C: lbu         $t8, 0x4F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4F);
    // 0x80089F70: nop

    // 0x80089F74: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80089F78: addu        $t7, $a0, $t0
    ctx->r15 = ADD32(ctx->r4, ctx->r8);
    // 0x80089F7C: lw          $t6, 0x20($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X20);
    // 0x80089F80: nop

    // 0x80089F84: sltu        $at, $a1, $t6
    ctx->r1 = ctx->r5 < ctx->r14 ? 1 : 0;
    // 0x80089F88: bne         $at, $zero, L_80089FB4
    if (ctx->r1 != 0) {
        // 0x80089F8C: nop
    
            goto L_80089FB4;
    }
    // 0x80089F8C: nop

    // 0x80089F90: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x80089F94: lw          $t2, 0x60($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X60);
    // 0x80089F98: addu        $t4, $sp, $t0
    ctx->r12 = ADD32(ctx->r29, ctx->r8);
    // 0x80089F9C: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x80089FA0: lbu         $t5, 0x7($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X7);
    // 0x80089FA4: nop

    // 0x80089FA8: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x80089FAC: b           L_80089FC8
    // 0x80089FB0: sb          $t9, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r25;
        goto L_80089FC8;
    // 0x80089FB0: sb          $t9, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r25;
L_80089FB4:
    // 0x80089FB4: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x80089FB8: nop

    // 0x80089FBC: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80089FC0: addu        $t7, $sp, $t8
    ctx->r15 = ADD32(ctx->r29, ctx->r24);
    // 0x80089FC4: sw          $zero, 0x8($t7)
    MEM_W(0X8, ctx->r15) = 0;
L_80089FC8:
    // 0x80089FC8: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x80089FCC: nop

    // 0x80089FD0: addiu       $t1, $t6, 0x1
    ctx->r9 = ADD32(ctx->r14, 0X1);
    // 0x80089FD4: sb          $t1, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r9;
    // 0x80089FD8: lw          $t0, 0x8C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8C);
    // 0x80089FDC: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80089FE0: srl         $t4, $t0, 1
    ctx->r12 = S32(U32(ctx->r8) >> 1);
    // 0x80089FE4: sltu        $at, $t2, $t4
    ctx->r1 = ctx->r10 < ctx->r12 ? 1 : 0;
    // 0x80089FE8: bne         $at, $zero, L_80089F44
    if (ctx->r1 != 0) {
        // 0x80089FEC: nop
    
            goto L_80089F44;
    }
    // 0x80089FEC: nop

L_80089FF0:
    // 0x80089FF0: lbu         $t5, 0x7($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X7);
    // 0x80089FF4: nop

    // 0x80089FF8: bne         $t5, $zero, L_8008A008
    if (ctx->r13 != 0) {
        // 0x80089FFC: nop
    
            goto L_8008A008;
    }
    // 0x80089FFC: nop

    // 0x8008A000: b           L_8008A080
    // 0x8008A004: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8008A080;
    // 0x8008A004: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8008A008:
    // 0x8008A008: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8008A00C: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x8008A010: sb          $zero, 0x4E($sp)
    MEM_B(0X4E, ctx->r29) = 0;
    // 0x8008A014: sb          $zero, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = 0;
L_8008A018:
    // 0x8008A018: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x8008A01C: addiu       $t7, $sp, 0x8
    ctx->r15 = ADD32(ctx->r29, 0X8);
    // 0x8008A020: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8008A024: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8008A028: lw          $t1, 0x0($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X0);
    // 0x8008A02C: nop

    // 0x8008A030: beq         $t1, $zero, L_8008A05C
    if (ctx->r9 == 0) {
        // 0x8008A034: nop
    
            goto L_8008A05C;
    }
    // 0x8008A034: nop

    // 0x8008A038: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8008A03C: nop

    // 0x8008A040: sltu        $at, $t1, $t0
    ctx->r1 = ctx->r9 < ctx->r8 ? 1 : 0;
    // 0x8008A044: beq         $at, $zero, L_8008A05C
    if (ctx->r1 == 0) {
        // 0x8008A048: nop
    
            goto L_8008A05C;
    }
    // 0x8008A048: nop

    // 0x8008A04C: sb          $t3, 0x4E($sp)
    MEM_B(0X4E, ctx->r29) = ctx->r11;
    // 0x8008A050: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x8008A054: nop

    // 0x8008A058: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
L_8008A05C:
    // 0x8008A05C: lbu         $t4, 0x4F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4F);
    // 0x8008A060: nop

    // 0x8008A064: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8008A068: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x8008A06C: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x8008A070: bne         $at, $zero, L_8008A018
    if (ctx->r1 != 0) {
        // 0x8008A074: sb          $t5, 0x4F($sp)
        MEM_B(0X4F, ctx->r29) = ctx->r13;
            goto L_8008A018;
    }
    // 0x8008A074: sb          $t5, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r13;
    // 0x8008A078: lbu         $v0, 0x4E($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X4E);
    // 0x8008A07C: nop

L_8008A080:
    // 0x8008A080: jr          $ra
    // 0x8008A084: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8008A084: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}

RECOMP_FUNC void Audio2_Play_SFX_Bank_Channel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A088: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008A08C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8008A090: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8008A094: lw          $t6, -0x752C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X752C);
    // 0x8008A098: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A09C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A0A0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8008A0A4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8008A0A8: beq         $t6, $t7, L_8008A0C8
    if (ctx->r14 == ctx->r15) {
        // 0x8008A0AC: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_8008A0C8;
    }
    // 0x8008A0AC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8008A0B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008A0B4: jal         0x800B3BFC
    // 0x8008A0B8: addiu       $a0, $a0, -0x6F8
    ctx->r4 = ADD32(ctx->r4, -0X6F8);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8008A0B8: addiu       $a0, $a0, -0x6F8
    ctx->r4 = ADD32(ctx->r4, -0X6F8);
    after_0:
    // 0x8008A0BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8008A0C0: b           L_8008A5B8
    // 0x8008A0C4: addiu       $v0, $v0, -0x7550
    ctx->r2 = ADD32(ctx->r2, -0X7550);
        goto L_8008A5B8;
    // 0x8008A0C4: addiu       $v0, $v0, -0x7550
    ctx->r2 = ADD32(ctx->r2, -0X7550);
L_8008A0C8:
    // 0x8008A0C8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008A0CC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8008A0D0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8008A0D4:
    // 0x8008A0D4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8008A0D8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8008A0DC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8008A0E0: lbu         $t0, -0x7220($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X7220);
    // 0x8008A0E4: lbu         $t1, 0x43($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X43);
    // 0x8008A0E8: nop

    // 0x8008A0EC: bne         $t0, $t1, L_8008A12C
    if (ctx->r8 != ctx->r9) {
        // 0x8008A0F0: nop
    
            goto L_8008A12C;
    }
    // 0x8008A0F0: nop

    // 0x8008A0F4: sll         $t4, $t9, 3
    ctx->r12 = S32(ctx->r25 << 3);
    // 0x8008A0F8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008A0FC: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x8008A100: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008A104: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008A108: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8008A10C: sb          $t2, 0x124($t5)
    MEM_B(0X124, ctx->r13) = ctx->r10;
    // 0x8008A110: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008A114: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008A118: bne         $t6, $at, L_8008A12C
    if (ctx->r14 != ctx->r1) {
        // 0x8008A11C: nop
    
            goto L_8008A12C;
    }
    // 0x8008A11C: nop

    // 0x8008A120: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8008A124: nop

    // 0x8008A128: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8008A12C:
    // 0x8008A12C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008A130: nop

    // 0x8008A134: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8008A138: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x8008A13C: bne         $at, $zero, L_8008A0D4
    if (ctx->r1 != 0) {
        // 0x8008A140: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_8008A0D4;
    }
    // 0x8008A140: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8008A144: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8008A148: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008A14C: beq         $t1, $at, L_8008A170
    if (ctx->r9 == ctx->r1) {
        // 0x8008A150: nop
    
            goto L_8008A170;
    }
    // 0x8008A150: nop

    // 0x8008A154: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x8008A158: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8008A15C: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8008A160: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008A164: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
    // 0x8008A168: b           L_8008A5B8
    // 0x8008A16C: addiu       $v0, $v0, 0x110
    ctx->r2 = ADD32(ctx->r2, 0X110);
        goto L_8008A5B8;
    // 0x8008A16C: addiu       $v0, $v0, 0x110
    ctx->r2 = ADD32(ctx->r2, 0X110);
L_8008A170:
    // 0x8008A170: lbu         $t5, 0x43($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X43);
    // 0x8008A174: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A178: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8008A17C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8008A180: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8008A184: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008A188: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8008A18C: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8008A190: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x8008A194: nop

    // 0x8008A198: sb          $t8, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r24;
    // 0x8008A19C: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x8008A1A0: nop

    // 0x8008A1A4: addu        $t1, $t0, $t6
    ctx->r9 = ADD32(ctx->r8, ctx->r14);
    // 0x8008A1A8: lbu         $t9, 0x1($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X1);
    // 0x8008A1AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8008A1B0: sb          $t9, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r25;
    // 0x8008A1B4: lbu         $t3, 0x35($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X35);
    // 0x8008A1B8: nop

    // 0x8008A1BC: blez        $t3, L_8008A210
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8008A1C0: nop
    
            goto L_8008A210;
    }
    // 0x8008A1C0: nop

L_8008A1C4:
    // 0x8008A1C4: lbu         $t7, 0x43($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X43);
    // 0x8008A1C8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A1CC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008A1D0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008A1D4: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8008A1D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008A1DC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8008A1E0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008A1E4: addu        $t4, $t2, $t8
    ctx->r12 = ADD32(ctx->r10, ctx->r24);
    // 0x8008A1E8: addu        $t6, $t4, $t0
    ctx->r14 = ADD32(ctx->r12, ctx->r8);
    // 0x8008A1EC: lbu         $t1, 0x3($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X3);
    // 0x8008A1F0: addu        $t9, $sp, $t0
    ctx->r25 = ADD32(ctx->r29, ctx->r8);
    // 0x8008A1F4: sb          $t1, 0x28($t9)
    MEM_B(0X28, ctx->r25) = ctx->r9;
    // 0x8008A1F8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008A1FC: lbu         $t7, 0x35($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X35);
    // 0x8008A200: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x8008A204: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008A208: bne         $at, $zero, L_8008A1C4
    if (ctx->r1 != 0) {
        // 0x8008A20C: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_8008A1C4;
    }
    // 0x8008A20C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8008A210:
    // 0x8008A210: lbu         $t8, 0x35($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X35);
    // 0x8008A214: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008A218: sb          $t2, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r10;
    // 0x8008A21C: blez        $t8, L_8008A59C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8008A220: sw          $zero, 0x24($sp)
        MEM_W(0X24, ctx->r29) = 0;
            goto L_8008A59C;
    }
    // 0x8008A220: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8008A224:
    // 0x8008A224: lbu         $t4, 0x36($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X36);
    // 0x8008A228: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8008A22C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008A230: jal         0x80089EDC
    // 0x8008A234: subu        $a1, $t4, $t6
    ctx->r5 = SUB32(ctx->r12, ctx->r14);
    Audio2_FindSFXChannel(rdram, ctx);
        goto after_1;
    // 0x8008A234: subu        $a1, $t4, $t6
    ctx->r5 = SUB32(ctx->r12, ctx->r14);
    after_1:
    // 0x8008A238: sb          $v0, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r2;
    // 0x8008A23C: lbu         $t1, 0x37($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A240: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008A244: bne         $t1, $at, L_8008A284
    if (ctx->r9 != ctx->r1) {
        // 0x8008A248: nop
    
            goto L_8008A284;
    }
    // 0x8008A248: nop

    // 0x8008A24C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008A250: jal         0x80089EDC
    // 0x8008A254: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    Audio2_FindSFXChannel(rdram, ctx);
        goto after_2;
    // 0x8008A254: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    after_2:
    // 0x8008A258: sb          $v0, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r2;
    // 0x8008A25C: lbu         $t0, 0x37($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A260: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008A264: bne         $t0, $at, L_8008A284
    if (ctx->r8 != ctx->r1) {
        // 0x8008A268: nop
    
            goto L_8008A284;
    }
    // 0x8008A268: nop

    // 0x8008A26C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008A270: jal         0x800B3BFC
    // 0x8008A274: addiu       $a0, $a0, -0x684
    ctx->r4 = ADD32(ctx->r4, -0X684);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8008A274: addiu       $a0, $a0, -0x684
    ctx->r4 = ADD32(ctx->r4, -0X684);
    after_3:
    // 0x8008A278: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8008A27C: b           L_8008A5B8
    // 0x8008A280: addiu       $v0, $v0, -0x7550
    ctx->r2 = ADD32(ctx->r2, -0X7550);
        goto L_8008A5B8;
    // 0x8008A280: addiu       $v0, $v0, -0x7550
    ctx->r2 = ADD32(ctx->r2, -0X7550);
L_8008A284:
    // 0x8008A284: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x8008A288: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A28C: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x8008A290: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8008A294: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8008A298: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x8008A29C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008A2A0: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x8008A2A4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008A2A8: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x8008A2AC: addiu       $t2, $t7, 0x114
    ctx->r10 = ADD32(ctx->r15, 0X114);
    // 0x8008A2B0: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x8008A2B4: sw          $t2, 0x110($t6)
    MEM_W(0X110, ctx->r14) = ctx->r10;
    // 0x8008A2B8: lbu         $t3, 0x37($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A2BC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8008A2C0: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x8008A2C4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8008A2C8: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x8008A2CC: sb          $t1, 0x354($t7)
    MEM_B(0X354, ctx->r15) = ctx->r9;
    // 0x8008A2D0: lbu         $t4, 0x37($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A2D4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8008A2D8: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8008A2DC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8008A2E0: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8008A2E4: sb          $t8, 0x355($t6)
    MEM_B(0X355, ctx->r14) = ctx->r24;
    // 0x8008A2E8: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x8008A2EC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008A2F0: bne         $t3, $at, L_8008A304
    if (ctx->r11 != ctx->r1) {
        // 0x8008A2F4: nop
    
            goto L_8008A304;
    }
    // 0x8008A2F4: nop

    // 0x8008A2F8: lbu         $t0, 0x37($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A2FC: nop

    // 0x8008A300: sb          $t0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r8;
L_8008A304:
    // 0x8008A304: sb          $zero, 0x34($sp)
    MEM_B(0X34, ctx->r29) = 0;
L_8008A308:
    // 0x8008A308: lbu         $t1, 0x37($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A30C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008A310: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8008A314: addu        $t4, $t5, $t7
    ctx->r12 = ADD32(ctx->r13, ctx->r15);
    // 0x8008A318: sw          $zero, 0x20($t4)
    MEM_W(0X20, ctx->r12) = 0;
    // 0x8008A31C: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A320: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8008A324: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8008A328: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x8008A32C: sw          $zero, 0x60($t6)
    MEM_W(0X60, ctx->r14) = 0;
    // 0x8008A330: lbu         $t3, 0x34($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X34);
    // 0x8008A334: nop

    // 0x8008A338: addiu       $t0, $t3, 0x1
    ctx->r8 = ADD32(ctx->r11, 0X1);
    // 0x8008A33C: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8008A340: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x8008A344: bne         $at, $zero, L_8008A308
    if (ctx->r1 != 0) {
        // 0x8008A348: sb          $t0, 0x34($sp)
        MEM_B(0X34, ctx->r29) = ctx->r8;
            goto L_8008A308;
    }
    // 0x8008A348: sb          $t0, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r8;
    // 0x8008A34C: lbu         $t5, 0x47($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X47);
    // 0x8008A350: nop

    // 0x8008A354: beq         $t5, $zero, L_8008A3A4
    if (ctx->r13 == 0) {
        // 0x8008A358: nop
    
            goto L_8008A3A4;
    }
    // 0x8008A358: nop

    // 0x8008A35C: lbu         $t4, 0x37($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A360: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8008A364: sll         $t2, $t4, 3
    ctx->r10 = S32(ctx->r12 << 3);
    // 0x8008A368: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8008A36C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008A370: addu        $t9, $t7, $t2
    ctx->r25 = ADD32(ctx->r15, ctx->r10);
    // 0x8008A374: lw          $t8, 0x110($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X110);
    // 0x8008A378: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008A37C: sb          $t5, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r13;
    // 0x8008A380: lbu         $t0, 0x37($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A384: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008A388: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8008A38C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8008A390: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008A394: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x8008A398: lw          $t7, 0x110($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X110);
    // 0x8008A39C: b           L_8008A3EC
    // 0x8008A3A0: sb          $t6, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r14;
        goto L_8008A3EC;
    // 0x8008A3A0: sb          $t6, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r14;
L_8008A3A4:
    // 0x8008A3A4: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A3A8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8008A3AC: sll         $t5, $t9, 3
    ctx->r13 = S32(ctx->r25 << 3);
    // 0x8008A3B0: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8008A3B4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008A3B8: addu        $t8, $t2, $t5
    ctx->r24 = ADD32(ctx->r10, ctx->r13);
    // 0x8008A3BC: lw          $t0, 0x110($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X110);
    // 0x8008A3C0: nop

    // 0x8008A3C4: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x8008A3C8: lbu         $t1, 0x37($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A3CC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008A3D0: sll         $t4, $t1, 3
    ctx->r12 = S32(ctx->r9 << 3);
    // 0x8008A3D4: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8008A3D8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008A3DC: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8008A3E0: lw          $t7, 0x110($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X110);
    // 0x8008A3E4: nop

    // 0x8008A3E8: sb          $zero, 0x2($t7)
    MEM_B(0X2, ctx->r15) = 0;
L_8008A3EC:
    // 0x8008A3EC: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A3F0: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A3F4: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x8008A3F8: lbu         $t9, 0x43($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X43);
    // 0x8008A3FC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008A400: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008A404: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8008A408: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8008A40C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8008A410: sb          $t9, -0x7220($at)
    MEM_B(-0X7220, ctx->r1) = ctx->r25;
    // 0x8008A414: addu        $t1, $t5, $t0
    ctx->r9 = ADD32(ctx->r13, ctx->r8);
    // 0x8008A418: sb          $zero, 0x124($t1)
    MEM_B(0X124, ctx->r9) = 0;
    // 0x8008A41C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8008A420: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008A424: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x8008A428: lbu         $t7, 0x28($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X28);
    // 0x8008A42C: lw          $t4, 0x350($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X350);
    // 0x8008A430: lbu         $t0, 0x37($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A434: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8008A438: addu        $t2, $t4, $t9
    ctx->r10 = ADD32(ctx->r12, ctx->r25);
    // 0x8008A43C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8008A440: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8008A444: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8008A448: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x8008A44C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008A450: addu        $t6, $t3, $t1
    ctx->r14 = ADD32(ctx->r11, ctx->r9);
    // 0x8008A454: sw          $t5, 0x118($t6)
    MEM_W(0X118, ctx->r14) = ctx->r13;
    // 0x8008A458: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8008A45C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8008A460: addu        $t2, $sp, $t9
    ctx->r10 = ADD32(ctx->r29, ctx->r25);
    // 0x8008A464: lbu         $t2, 0x28($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X28);
    // 0x8008A468: lbu         $t5, 0x37($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A46C: lw          $t4, 0x350($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X350);
    // 0x8008A470: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8008A474: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8008A478: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8008A47C: addu        $t0, $t4, $t8
    ctx->r8 = ADD32(ctx->r12, ctx->r24);
    // 0x8008A480: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8008A484: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008A488: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8008A48C: lw          $t2, 0x118($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X118);
    // 0x8008A490: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8008A494: nop

    // 0x8008A498: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8008A49C: sw          $t4, 0x11C($t9)
    MEM_W(0X11C, ctx->r25) = ctx->r12;
    // 0x8008A4A0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008A4A4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8008A4A8: addu        $t5, $sp, $t3
    ctx->r13 = ADD32(ctx->r29, ctx->r11);
    // 0x8008A4AC: lbu         $t5, 0x28($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X28);
    // 0x8008A4B0: lw          $t0, 0x350($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X350);
    // 0x8008A4B4: lbu         $t4, 0x37($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A4B8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8008A4BC: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x8008A4C0: lw          $t1, 0x0($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X0);
    // 0x8008A4C4: sll         $t9, $t4, 3
    ctx->r25 = S32(ctx->r12 << 3);
    // 0x8008A4C8: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8008A4CC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8008A4D0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008A4D4: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8008A4D8: sw          $t2, 0x128($t3)
    MEM_W(0X128, ctx->r11) = ctx->r10;
    // 0x8008A4DC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_8008A4E0:
    // 0x8008A4E0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8008A4E4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008A4E8: addu        $t6, $sp, $t7
    ctx->r14 = ADD32(ctx->r29, ctx->r15);
    // 0x8008A4EC: lbu         $t6, 0x28($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X28);
    // 0x8008A4F0: lw          $t0, 0x350($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X350);
    // 0x8008A4F4: lbu         $t7, 0x37($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A4F8: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x8008A4FC: addu        $t4, $t0, $t1
    ctx->r12 = ADD32(ctx->r8, ctx->r9);
    // 0x8008A500: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8008A504: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8008A508: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x8008A50C: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8008A510: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008A514: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x8008A518: lbu         $t3, 0x10($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X10);
    // 0x8008A51C: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x8008A520: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x8008A524: sb          $t3, 0x12C($t1)
    MEM_B(0X12C, ctx->r9) = ctx->r11;
    // 0x8008A528: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8008A52C: nop

    // 0x8008A530: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x8008A534: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x8008A538: bne         $at, $zero, L_8008A4E0
    if (ctx->r1 != 0) {
        // 0x8008A53C: sw          $t8, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r24;
            goto L_8008A4E0;
    }
    // 0x8008A53C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8008A540: lbu         $t0, 0x37($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A544: lbu         $t2, 0x36($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X36);
    // 0x8008A548: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8008A54C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8008A550: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8008A554: subu        $t5, $t2, $t7
    ctx->r13 = SUB32(ctx->r10, ctx->r15);
    // 0x8008A558: addu        $t3, $t6, $t9
    ctx->r11 = ADD32(ctx->r14, ctx->r25);
    // 0x8008A55C: sw          $t5, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->r13;
    // 0x8008A560: lbu         $t7, 0x37($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X37);
    // 0x8008A564: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008A568: lw          $t1, 0x3910($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3910);
    // 0x8008A56C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8008A570: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8008A574: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8008A578: subu        $t8, $t1, $t4
    ctx->r24 = SUB32(ctx->r9, ctx->r12);
    // 0x8008A57C: addu        $t6, $t2, $t0
    ctx->r14 = ADD32(ctx->r10, ctx->r8);
    // 0x8008A580: sw          $t8, 0x60($t6)
    MEM_W(0X60, ctx->r14) = ctx->r24;
    // 0x8008A584: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8008A588: lbu         $t3, 0x35($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X35);
    // 0x8008A58C: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8008A590: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8008A594: bne         $at, $zero, L_8008A224
    if (ctx->r1 != 0) {
        // 0x8008A598: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_8008A224;
    }
    // 0x8008A598: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8008A59C:
    // 0x8008A59C: lbu         $t4, 0x33($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X33);
    // 0x8008A5A0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8008A5A4: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x8008A5A8: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x8008A5AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008A5B0: addu        $v0, $t1, $t7
    ctx->r2 = ADD32(ctx->r9, ctx->r15);
    // 0x8008A5B4: addiu       $v0, $v0, 0x110
    ctx->r2 = ADD32(ctx->r2, 0X110);
L_8008A5B8:
    // 0x8008A5B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A5BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008A5C0: jr          $ra
    // 0x8008A5C4: nop

    return;
    // 0x8008A5C4: nop

;}

RECOMP_FUNC void Audio2_Play_SFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A5CC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8008A5D0: lw          $t6, -0x752C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X752C);
    // 0x8008A5D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A5D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008A5DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008A5E0: beq         $t6, $zero, L_8008A604
    if (ctx->r14 == 0) {
        // 0x8008A5E4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8008A604;
    }
    // 0x8008A5E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008A5E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008A5EC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8008A5F0: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x8008A5F4: jal         0x8008A088
    // 0x8008A5F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Audio2_Play_SFX_Bank_Channel(rdram, ctx);
        goto after_0;
    // 0x8008A5F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8008A5FC: b           L_8008A60C
    // 0x8008A600: nop

        goto L_8008A60C;
    // 0x8008A600: nop

L_8008A604:
    // 0x8008A604: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8008A608: addiu       $v0, $v0, -0x7550
    ctx->r2 = ADD32(ctx->r2, -0X7550);
L_8008A60C:
    // 0x8008A60C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A614: jr          $ra
    // 0x8008A618: nop

    return;
    // 0x8008A618: nop

;}

RECOMP_FUNC void Audio2_UpdateScheduledSFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A61C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008A620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A624: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
L_8008A628:
    // 0x8008A628: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x8008A62C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8008A630: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008A634: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008A638: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008A63C: addiu       $t8, $t8, -0x7218
    ctx->r24 = ADD32(ctx->r24, -0X7218);
    // 0x8008A640: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8008A644: lh          $t0, 0xA($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XA);
    // 0x8008A648: addiu       $at, $zero, 0x7D00
    ctx->r1 = ADD32(0, 0X7D00);
    // 0x8008A64C: beq         $t0, $at, L_8008A6BC
    if (ctx->r8 == ctx->r1) {
        // 0x8008A650: nop
    
            goto L_8008A6BC;
    }
    // 0x8008A650: nop

    // 0x8008A654: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8008A658: sh          $t1, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r9;
    // 0x8008A65C: lh          $t2, 0x1E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1E);
    // 0x8008A660: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8008A664: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8008A668: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8008A66C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008A670: addiu       $t4, $t4, -0x7218
    ctx->r12 = ADD32(ctx->r12, -0X7218);
    // 0x8008A674: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8008A678: lh          $t6, 0xA($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XA);
    // 0x8008A67C: nop

    // 0x8008A680: bgtz        $t6, L_8008A6BC
    if (SIGNED(ctx->r14) > 0) {
        // 0x8008A684: nop
    
            goto L_8008A6BC;
    }
    // 0x8008A684: nop

    // 0x8008A688: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8008A68C: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    // 0x8008A690: lbu         $a2, 0x8($t5)
    ctx->r6 = MEM_BU(ctx->r13, 0X8);
    // 0x8008A694: jal         0x8008A5C8
    // 0x8008A698: nop

    Audio2_Play_SFX(rdram, ctx);
        goto after_0;
    // 0x8008A698: nop

    after_0:
    // 0x8008A69C: lh          $t8, 0x1E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X1E);
    // 0x8008A6A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008A6A4: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8008A6A8: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x8008A6AC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8008A6B0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8008A6B4: addiu       $t7, $zero, 0x7D00
    ctx->r15 = ADD32(0, 0X7D00);
    // 0x8008A6B8: sh          $t7, -0x720E($at)
    MEM_H(-0X720E, ctx->r1) = ctx->r15;
L_8008A6BC:
    // 0x8008A6BC: lh          $t1, 0x1E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X1E);
    // 0x8008A6C0: nop

    // 0x8008A6C4: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x8008A6C8: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x8008A6CC: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8008A6D0: slti        $at, $t3, 0x10
    ctx->r1 = SIGNED(ctx->r11) < 0X10 ? 1 : 0;
    // 0x8008A6D4: bne         $at, $zero, L_8008A628
    if (ctx->r1 != 0) {
        // 0x8008A6D8: sh          $t9, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r25;
            goto L_8008A628;
    }
    // 0x8008A6D8: sh          $t9, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r25;
    // 0x8008A6DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A6E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008A6E4: jr          $ra
    // 0x8008A6E8: nop

    return;
    // 0x8008A6E8: nop

;}

RECOMP_FUNC void Audio2_ScheduleDelayedSFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6EC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008A6F0: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8008A6F4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8008A6F8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8008A6FC: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
L_8008A700:
    // 0x8008A700: lh          $t6, 0x6($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6);
    // 0x8008A704: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8008A708: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008A70C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008A710: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008A714: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8008A718: lh          $t8, -0x720E($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X720E);
    // 0x8008A71C: addiu       $at, $zero, 0x7D00
    ctx->r1 = ADD32(0, 0X7D00);
    // 0x8008A720: beq         $t8, $at, L_8008A748
    if (ctx->r24 == ctx->r1) {
        // 0x8008A724: nop
    
            goto L_8008A748;
    }
    // 0x8008A724: nop

    // 0x8008A728: lh          $t9, 0x6($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6);
    // 0x8008A72C: nop

    // 0x8008A730: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008A734: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8008A738: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8008A73C: slti        $at, $t2, 0x10
    ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
    // 0x8008A740: bne         $at, $zero, L_8008A700
    if (ctx->r1 != 0) {
        // 0x8008A744: sh          $t0, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r8;
            goto L_8008A700;
    }
    // 0x8008A744: sh          $t0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r8;
L_8008A748:
    // 0x8008A748: lh          $t3, 0x6($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X6);
    // 0x8008A74C: lh          $t5, 0x6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6);
    // 0x8008A750: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8008A754: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008A758: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008A75C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008A760: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8008A764: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8008A768: lh          $t7, 0x6($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6);
    // 0x8008A76C: sw          $a0, -0x7218($at)
    MEM_W(-0X7218, ctx->r1) = ctx->r4;
    // 0x8008A770: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8008A774: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008A778: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008A77C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008A780: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008A784: lh          $t9, 0x6($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6);
    // 0x8008A788: sw          $a1, -0x7214($at)
    MEM_W(-0X7214, ctx->r1) = ctx->r5;
    // 0x8008A78C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008A790: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008A794: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008A798: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8008A79C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008A7A0: sb          $a2, -0x7210($at)
    MEM_B(-0X7210, ctx->r1) = ctx->r6;
    // 0x8008A7A4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8008A7A8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8008A7AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008A7B0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8008A7B4: sh          $a3, -0x720E($at)
    MEM_H(-0X720E, ctx->r1) = ctx->r7;
    // 0x8008A7B8: jr          $ra
    // 0x8008A7BC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008A7BC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Audio2_ClearScheduledSFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7C0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008A7C4: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
L_8008A7C8:
    // 0x8008A7C8: lh          $t7, 0x6($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6);
    // 0x8008A7CC: lh          $t9, 0x6($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6);
    // 0x8008A7D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008A7D4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008A7D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008A7DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008A7E0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008A7E4: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8008A7E8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8008A7EC: addiu       $t6, $zero, 0x7D00
    ctx->r14 = ADD32(0, 0X7D00);
    // 0x8008A7F0: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8008A7F4: sh          $t6, -0x720E($at)
    MEM_H(-0X720E, ctx->r1) = ctx->r14;
    // 0x8008A7F8: slti        $at, $t2, 0x10
    ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
    // 0x8008A7FC: bne         $at, $zero, L_8008A7C8
    if (ctx->r1 != 0) {
        // 0x8008A800: sh          $t0, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r8;
            goto L_8008A7C8;
    }
    // 0x8008A800: sh          $t0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r8;
    // 0x8008A804: jr          $ra
    // 0x8008A808: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008A808: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Audio2_ParseSFXHeader(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BF58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008BF5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008BF60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BF64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008BF68: jal         0x8008C130
    // 0x8008BF6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    Audio2_ReadU32BE(rdram, ctx);
        goto after_0;
    // 0x8008BF6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008BF70: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BF74: nop

    // 0x8008BF78: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8008BF7C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008BF80: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BF84: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8008BF88: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8008BF8C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8008BF90: nop

    // 0x8008BF94: sb          $t9, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r25;
    // 0x8008BF98: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8008BF9C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BFA0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008BFA4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8008BFA8: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x8008BFAC: nop

    // 0x8008BFB0: sb          $t3, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r11;
    // 0x8008BFB4: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8008BFB8: nop

    // 0x8008BFBC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8008BFC0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8008BFC4: jal         0x8008C104
    // 0x8008BFC8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    Audio2_ReadU32LE(rdram, ctx);
        goto after_1;
    // 0x8008BFC8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x8008BFCC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BFD0: nop

    // 0x8008BFD4: sw          $v0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r2;
    // 0x8008BFD8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008BFDC: nop

    // 0x8008BFE0: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x8008BFE4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8008BFE8: jal         0x8008C104
    // 0x8008BFEC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    Audio2_ReadU32LE(rdram, ctx);
        goto after_2;
    // 0x8008BFEC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_2:
    // 0x8008BFF0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BFF4: nop

    // 0x8008BFF8: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x8008BFFC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8008C000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C004: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x8008C008: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8008C00C: jr          $ra
    // 0x8008C010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008C010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Audio2_ParseSoundRecord(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008C01C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008C024: jal         0x8008C104
    // 0x8008C028: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    Audio2_ReadU32LE(rdram, ctx);
        goto after_0;
    // 0x8008C028: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008C02C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C030: nop

    // 0x8008C034: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8008C038: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008C03C: nop

    // 0x8008C040: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8008C044: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8008C048: jal         0x8008C104
    // 0x8008C04C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    Audio2_ReadU32LE(rdram, ctx);
        goto after_1;
    // 0x8008C04C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x8008C050: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C054: nop

    // 0x8008C058: sw          $v0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r2;
    // 0x8008C05C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008C060: nop

    // 0x8008C064: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x8008C068: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8008C06C: jal         0x8008C104
    // 0x8008C070: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    Audio2_ReadU32LE(rdram, ctx);
        goto after_2;
    // 0x8008C070: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_2:
    // 0x8008C074: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C078: nop

    // 0x8008C07C: sw          $v0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r2;
    // 0x8008C080: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008C084: nop

    // 0x8008C088: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x8008C08C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8008C090: jal         0x8008C0E0
    // 0x8008C094: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    Audio2_ReadS16LE(rdram, ctx);
        goto after_3;
    // 0x8008C094: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_3:
    // 0x8008C098: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C09C: nop

    // 0x8008C0A0: sh          $v0, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r2;
    // 0x8008C0A4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008C0A8: nop

    // 0x8008C0AC: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x8008C0B0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8008C0B4: jal         0x8008C0E0
    // 0x8008C0B8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    Audio2_ReadS16LE(rdram, ctx);
        goto after_4;
    // 0x8008C0B8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x8008C0BC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C0C0: nop

    // 0x8008C0C4: sh          $v0, 0xE($t8)
    MEM_H(0XE, ctx->r24) = ctx->r2;
    // 0x8008C0C8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008C0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C0D0: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x8008C0D4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8008C0D8: jr          $ra
    // 0x8008C0DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008C0DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void Audio2_ReadS16LE(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C0E0: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x8008C0E4: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x8008C0E8: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8008C0EC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8008C0F0: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8008C0F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8008C0F8: sra         $t0, $v0, 16
    ctx->r8 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8008C0FC: jr          $ra
    // 0x8008C100: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8008C100: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}

RECOMP_FUNC void Audio2_ReadU32LE(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C104: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x8008C108: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8008C10C: lbu         $t0, 0x2($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X2);
    // 0x8008C110: lbu         $t3, 0x3($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X3);
    // 0x8008C114: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8008C118: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8008C11C: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8008C120: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8008C124: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x8008C128: jr          $ra
    // 0x8008C12C: addu        $v0, $t4, $t2
    ctx->r2 = ADD32(ctx->r12, ctx->r10);
    return;
    // 0x8008C12C: addu        $v0, $t4, $t2
    ctx->r2 = ADD32(ctx->r12, ctx->r10);
;}

RECOMP_FUNC void Audio2_ReadU32BE(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C130: lbu         $t7, 0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2);
    // 0x8008C134: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x8008C138: lbu         $t0, 0x1($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1);
    // 0x8008C13C: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
    // 0x8008C140: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8008C144: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8008C148: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8008C14C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8008C150: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x8008C154: jr          $ra
    // 0x8008C158: addu        $v0, $t4, $t2
    ctx->r2 = ADD32(ctx->r12, ctx->r10);
    return;
    // 0x8008C158: addu        $v0, $t4, $t2
    ctx->r2 = ADD32(ctx->r12, ctx->r10);
;}

RECOMP_FUNC void Audio2_SFX_Debug_Print(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C15C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C160: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008C164: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008C168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C16C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C170: lhu         $a1, 0xC($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0XC);
    // 0x8008C174: jal         0x800B3BFC
    // 0x8008C178: addiu       $a0, $a0, -0x5D0
    ctx->r4 = ADD32(ctx->r4, -0X5D0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8008C178: addiu       $a0, $a0, -0x5D0
    ctx->r4 = ADD32(ctx->r4, -0X5D0);
    after_0:
    // 0x8008C17C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008C180: nop

    // 0x8008C184: lhu         $t8, 0xC($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XC);
    // 0x8008C188: nop

    // 0x8008C18C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8008C190: beq         $t9, $zero, L_8008C1AC
    if (ctx->r25 == 0) {
        // 0x8008C194: nop
    
            goto L_8008C1AC;
    }
    // 0x8008C194: nop

    // 0x8008C198: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C19C: jal         0x800B3BFC
    // 0x8008C1A0: addiu       $a0, $a0, -0x5C4
    ctx->r4 = ADD32(ctx->r4, -0X5C4);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8008C1A0: addiu       $a0, $a0, -0x5C4
    ctx->r4 = ADD32(ctx->r4, -0X5C4);
    after_1:
    // 0x8008C1A4: b           L_8008C1B8
    // 0x8008C1A8: nop

        goto L_8008C1B8;
    // 0x8008C1A8: nop

L_8008C1AC:
    // 0x8008C1AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C1B0: jal         0x800B3BFC
    // 0x8008C1B4: addiu       $a0, $a0, -0x5BC
    ctx->r4 = ADD32(ctx->r4, -0X5BC);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8008C1B4: addiu       $a0, $a0, -0x5BC
    ctx->r4 = ADD32(ctx->r4, -0X5BC);
    after_2:
L_8008C1B8:
    // 0x8008C1B8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008C1BC: nop

    // 0x8008C1C0: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
    // 0x8008C1C4: nop

    // 0x8008C1C8: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8008C1CC: beq         $t2, $zero, L_8008C1E8
    if (ctx->r10 == 0) {
        // 0x8008C1D0: nop
    
            goto L_8008C1E8;
    }
    // 0x8008C1D0: nop

    // 0x8008C1D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C1D8: jal         0x800B3BFC
    // 0x8008C1DC: addiu       $a0, $a0, -0x5B4
    ctx->r4 = ADD32(ctx->r4, -0X5B4);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8008C1DC: addiu       $a0, $a0, -0x5B4
    ctx->r4 = ADD32(ctx->r4, -0X5B4);
    after_3:
    // 0x8008C1E0: b           L_8008C1F4
    // 0x8008C1E4: nop

        goto L_8008C1F4;
    // 0x8008C1E4: nop

L_8008C1E8:
    // 0x8008C1E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C1EC: jal         0x800B3BFC
    // 0x8008C1F0: addiu       $a0, $a0, -0x5AC
    ctx->r4 = ADD32(ctx->r4, -0X5AC);
    rmonPrintf_recomp(rdram, ctx);
        goto after_4;
    // 0x8008C1F0: addiu       $a0, $a0, -0x5AC
    ctx->r4 = ADD32(ctx->r4, -0X5AC);
    after_4:
L_8008C1F4:
    // 0x8008C1F4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008C1F8: nop

    // 0x8008C1FC: lhu         $t4, 0xC($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XC);
    // 0x8008C200: nop

    // 0x8008C204: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x8008C208: beq         $t5, $zero, L_8008C224
    if (ctx->r13 == 0) {
        // 0x8008C20C: nop
    
            goto L_8008C224;
    }
    // 0x8008C20C: nop

    // 0x8008C210: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C214: jal         0x800B3BFC
    // 0x8008C218: addiu       $a0, $a0, -0x5A0
    ctx->r4 = ADD32(ctx->r4, -0X5A0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_5;
    // 0x8008C218: addiu       $a0, $a0, -0x5A0
    ctx->r4 = ADD32(ctx->r4, -0X5A0);
    after_5:
    // 0x8008C21C: b           L_8008C230
    // 0x8008C220: nop

        goto L_8008C230;
    // 0x8008C220: nop

L_8008C224:
    // 0x8008C224: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C228: jal         0x800B3BFC
    // 0x8008C22C: addiu       $a0, $a0, -0x598
    ctx->r4 = ADD32(ctx->r4, -0X598);
    rmonPrintf_recomp(rdram, ctx);
        goto after_6;
    // 0x8008C22C: addiu       $a0, $a0, -0x598
    ctx->r4 = ADD32(ctx->r4, -0X598);
    after_6:
L_8008C230:
    // 0x8008C230: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008C234: nop

    // 0x8008C238: lhu         $t7, 0xC($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC);
    // 0x8008C23C: nop

    // 0x8008C240: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8008C244: beq         $t8, $zero, L_8008C260
    if (ctx->r24 == 0) {
        // 0x8008C248: nop
    
            goto L_8008C260;
    }
    // 0x8008C248: nop

    // 0x8008C24C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C250: jal         0x800B3BFC
    // 0x8008C254: addiu       $a0, $a0, -0x58C
    ctx->r4 = ADD32(ctx->r4, -0X58C);
    rmonPrintf_recomp(rdram, ctx);
        goto after_7;
    // 0x8008C254: addiu       $a0, $a0, -0x58C
    ctx->r4 = ADD32(ctx->r4, -0X58C);
    after_7:
    // 0x8008C258: b           L_8008C26C
    // 0x8008C25C: nop

        goto L_8008C26C;
    // 0x8008C25C: nop

L_8008C260:
    // 0x8008C260: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C264: jal         0x800B3BFC
    // 0x8008C268: addiu       $a0, $a0, -0x580
    ctx->r4 = ADD32(ctx->r4, -0X580);
    rmonPrintf_recomp(rdram, ctx);
        goto after_8;
    // 0x8008C268: addiu       $a0, $a0, -0x580
    ctx->r4 = ADD32(ctx->r4, -0X580);
    after_8:
L_8008C26C:
    // 0x8008C26C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C270: jal         0x800B3BFC
    // 0x8008C274: addiu       $a0, $a0, -0x574
    ctx->r4 = ADD32(ctx->r4, -0X574);
    rmonPrintf_recomp(rdram, ctx);
        goto after_9;
    // 0x8008C274: addiu       $a0, $a0, -0x574
    ctx->r4 = ADD32(ctx->r4, -0X574);
    after_9:
    // 0x8008C278: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008C27C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C280: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8008C284: addiu       $a0, $a0, -0x570
    ctx->r4 = ADD32(ctx->r4, -0X570);
    // 0x8008C288: sll         $a1, $t0, 1
    ctx->r5 = S32(ctx->r8 << 1);
    // 0x8008C28C: jal         0x800B3BFC
    // 0x8008C290: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_10;
    // 0x8008C290: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_10:
    // 0x8008C294: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8008C298: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C29C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8008C2A0: addiu       $a0, $a0, -0x554
    ctx->r4 = ADD32(ctx->r4, -0X554);
    // 0x8008C2A4: sll         $a1, $t2, 1
    ctx->r5 = S32(ctx->r10 << 1);
    // 0x8008C2A8: jal         0x800B3BFC
    // 0x8008C2AC: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_11;
    // 0x8008C2AC: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_11:
    // 0x8008C2B0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008C2B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C2B8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8008C2BC: addiu       $a0, $a0, -0x538
    ctx->r4 = ADD32(ctx->r4, -0X538);
    // 0x8008C2C0: sll         $a1, $t4, 1
    ctx->r5 = S32(ctx->r12 << 1);
    // 0x8008C2C4: jal         0x800B3BFC
    // 0x8008C2C8: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_12;
    // 0x8008C2C8: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_12:
    // 0x8008C2CC: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8008C2D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C2D4: lhu         $a1, 0xE($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0XE);
    // 0x8008C2D8: jal         0x800B3BFC
    // 0x8008C2DC: addiu       $a0, $a0, -0x520
    ctx->r4 = ADD32(ctx->r4, -0X520);
    rmonPrintf_recomp(rdram, ctx);
        goto after_13;
    // 0x8008C2DC: addiu       $a0, $a0, -0x520
    ctx->r4 = ADD32(ctx->r4, -0X520);
    after_13:
    // 0x8008C2E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C2E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C2E8: jr          $ra
    // 0x8008C2EC: nop

    return;
    // 0x8008C2EC: nop

;}

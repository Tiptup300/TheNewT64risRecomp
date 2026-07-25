#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Minos_SetTilePositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F260: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F264: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006F268: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006F26C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006F270: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8006F274: lw          $s1, -0x3C0($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X3C0);
    // 0x8006F278: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006F27C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006F280: addiu       $t7, $t6, 0x24
    ctx->r15 = ADD32(ctx->r14, 0X24);
    // 0x8006F284: sw          $t7, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r15;
    // 0x8006F288: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006F28C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006F290: addiu       $s0, $s0, -0x3E8
    ctx->r16 = ADD32(ctx->r16, -0X3E8);
    // 0x8006F294: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x8006F298: addiu       $t9, $t8, 0xB0
    ctx->r25 = ADD32(ctx->r24, 0XB0);
    // 0x8006F29C: addiu       $a1, $s1, 0x24
    ctx->r5 = ADD32(ctx->r17, 0X24);
    // 0x8006F2A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006F2A4: jal         0x8007641C
    // 0x8006F2A8: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    CubeTiles_TileCoordsToPos(rdram, ctx);
        goto after_0;
    // 0x8006F2A8: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    after_0:
    // 0x8006F2AC: addiu       $a0, $s0, 0xA
    ctx->r4 = ADD32(ctx->r16, 0XA);
    // 0x8006F2B0: jal         0x8007641C
    // 0x8006F2B4: addiu       $a1, $s1, 0x2C
    ctx->r5 = ADD32(ctx->r17, 0X2C);
    CubeTiles_TileCoordsToPos(rdram, ctx);
        goto after_1;
    // 0x8006F2B4: addiu       $a1, $s1, 0x2C
    ctx->r5 = ADD32(ctx->r17, 0X2C);
    after_1:
    // 0x8006F2B8: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x8006F2BC: jal         0x8007641C
    // 0x8006F2C0: addiu       $a1, $s1, 0x34
    ctx->r5 = ADD32(ctx->r17, 0X34);
    CubeTiles_TileCoordsToPos(rdram, ctx);
        goto after_2;
    // 0x8006F2C0: addiu       $a1, $s1, 0x34
    ctx->r5 = ADD32(ctx->r17, 0X34);
    after_2:
    // 0x8006F2C4: addiu       $a0, $s0, 0x1E
    ctx->r4 = ADD32(ctx->r16, 0X1E);
    // 0x8006F2C8: jal         0x8007641C
    // 0x8006F2CC: addiu       $a1, $s1, 0x3C
    ctx->r5 = ADD32(ctx->r17, 0X3C);
    CubeTiles_TileCoordsToPos(rdram, ctx);
        goto after_3;
    // 0x8006F2CC: addiu       $a1, $s1, 0x3C
    ctx->r5 = ADD32(ctx->r17, 0X3C);
    after_3:
    // 0x8006F2D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006F2D4: lw          $t0, -0x3C0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3C0);
    // 0x8006F2D8: nop

    // 0x8006F2DC: lw          $t9, 0x58($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X58);
    // 0x8006F2E0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8006F2E4: jalr        $t9
    // 0x8006F2E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8006F2E8: nop

    after_4:
    // 0x8006F2EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F2F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006F2F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006F2F8: jr          $ra
    // 0x8006F2FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006F2FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Minos_SampleTiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F300: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F304: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006F308: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006F30C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006F310: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8006F314: lw          $s1, -0x3C0($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X3C0);
    // 0x8006F318: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006F31C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006F320: addiu       $t7, $t6, 0x24
    ctx->r15 = ADD32(ctx->r14, 0X24);
    // 0x8006F324: sw          $t7, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r15;
    // 0x8006F328: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006F32C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006F330: addiu       $s0, $s0, -0x3E8
    ctx->r16 = ADD32(ctx->r16, -0X3E8);
    // 0x8006F334: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x8006F338: addiu       $t9, $t8, 0xF0
    ctx->r25 = ADD32(ctx->r24, 0XF0);
    // 0x8006F33C: addiu       $a1, $s1, 0x24
    ctx->r5 = ADD32(ctx->r17, 0X24);
    // 0x8006F340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006F344: jal         0x80076458
    // 0x8006F348: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    CubeTiles_SampleTile(rdram, ctx);
        goto after_0;
    // 0x8006F348: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    after_0:
    // 0x8006F34C: addiu       $a0, $s0, 0xA
    ctx->r4 = ADD32(ctx->r16, 0XA);
    // 0x8006F350: jal         0x80076458
    // 0x8006F354: addiu       $a1, $s1, 0x2C
    ctx->r5 = ADD32(ctx->r17, 0X2C);
    CubeTiles_SampleTile(rdram, ctx);
        goto after_1;
    // 0x8006F354: addiu       $a1, $s1, 0x2C
    ctx->r5 = ADD32(ctx->r17, 0X2C);
    after_1:
    // 0x8006F358: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x8006F35C: jal         0x80076458
    // 0x8006F360: addiu       $a1, $s1, 0x34
    ctx->r5 = ADD32(ctx->r17, 0X34);
    CubeTiles_SampleTile(rdram, ctx);
        goto after_2;
    // 0x8006F360: addiu       $a1, $s1, 0x34
    ctx->r5 = ADD32(ctx->r17, 0X34);
    after_2:
    // 0x8006F364: addiu       $a0, $s0, 0x1E
    ctx->r4 = ADD32(ctx->r16, 0X1E);
    // 0x8006F368: jal         0x80076458
    // 0x8006F36C: addiu       $a1, $s1, 0x3C
    ctx->r5 = ADD32(ctx->r17, 0X3C);
    CubeTiles_SampleTile(rdram, ctx);
        goto after_3;
    // 0x8006F36C: addiu       $a1, $s1, 0x3C
    ctx->r5 = ADD32(ctx->r17, 0X3C);
    after_3:
    // 0x8006F370: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
    // 0x8006F374: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x8006F378: lw          $t9, 0x58($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X58);
    // 0x8006F37C: nop

    // 0x8006F380: jalr        $t9
    // 0x8006F384: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8006F384: nop

    after_4:
    // 0x8006F388: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F38C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006F390: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006F394: jr          $ra
    // 0x8006F398: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006F398: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Minos_TransformVtx_Flat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F39C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006F3A0: addiu       $t6, $t6, -0x3E8
    ctx->r14 = ADD32(ctx->r14, -0X3E8);
    // 0x8006F3A4: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8006F3A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006F3AC: sb          $t7, 0x2C($t0)
    MEM_B(0X2C, ctx->r8) = ctx->r15;
    // 0x8006F3B0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006F3B4: lw          $t8, -0x3F0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3F0);
    // 0x8006F3B8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8006F3BC: lh          $t9, 0xA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XA);
    // 0x8006F3C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006F3C4: sh          $t9, 0x2E($t0)
    MEM_H(0X2E, ctx->r8) = ctx->r25;
    // 0x8006F3C8: lw          $t6, -0x3F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3F0);
    // 0x8006F3CC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006F3D0: lh          $t7, 0xC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XC);
    // 0x8006F3D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F3D8: sh          $t7, 0x30($t0)
    MEM_H(0X30, ctx->r8) = ctx->r15;
    // 0x8006F3DC: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8006F3E0: lh          $t9, 0x6($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X6);
    // 0x8006F3E4: lw          $t8, -0x3F0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3F0);
    // 0x8006F3E8: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8006F3EC: lh          $t9, 0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XE);
    // 0x8006F3F0: lhu         $t1, 0x8($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X8);
    // 0x8006F3F4: subu        $a2, $t7, $t9
    ctx->r6 = SUB32(ctx->r15, ctx->r25);
    // 0x8006F3F8: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x8006F3FC: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x8006F400: nop

    // 0x8006F404: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8006F408: lh          $t6, 0x10($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X10);
    // 0x8006F40C: subu        $t7, $a2, $t1
    ctx->r15 = SUB32(ctx->r6, ctx->r9);
    // 0x8006F410: subu        $a3, $t9, $t6
    ctx->r7 = SUB32(ctx->r25, ctx->r14);
    // 0x8006F414: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8006F418: subu        $t8, $a3, $t1
    ctx->r24 = SUB32(ctx->r7, ctx->r9);
    // 0x8006F41C: subu        $t6, $a3, $t1
    ctx->r14 = SUB32(ctx->r7, ctx->r9);
    // 0x8006F420: addu        $t9, $a2, $t1
    ctx->r25 = ADD32(ctx->r6, ctx->r9);
    // 0x8006F424: sh          $t8, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r24;
    // 0x8006F428: sh          $t9, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r25;
    // 0x8006F42C: sh          $t6, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r14;
    // 0x8006F430: subu        $t7, $a2, $t1
    ctx->r15 = SUB32(ctx->r6, ctx->r9);
    // 0x8006F434: sh          $t7, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r15;
    // 0x8006F438: addu        $t8, $a3, $t1
    ctx->r24 = ADD32(ctx->r7, ctx->r9);
    // 0x8006F43C: addu        $t6, $a3, $t1
    ctx->r14 = ADD32(ctx->r7, ctx->r9);
    // 0x8006F440: addu        $t9, $a2, $t1
    ctx->r25 = ADD32(ctx->r6, ctx->r9);
    // 0x8006F444: sh          $t8, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r24;
    // 0x8006F448: sh          $t9, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r25;
    // 0x8006F44C: sh          $t6, 0x20($a1)
    MEM_H(0X20, ctx->r5) = ctx->r14;
    // 0x8006F450: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006F454: lw          $t7, -0x3F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3F0);
    // 0x8006F458: nop

    // 0x8006F45C: lhu         $t2, 0x2($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X2);
    // 0x8006F460: lh          $t6, 0x12($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X12);
    // 0x8006F464: multu       $a2, $t2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F468: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x8006F46C: mflo        $t8
    ctx->r24 = lo;
    // 0x8006F470: srl         $t9, $t8, 14
    ctx->r25 = S32(U32(ctx->r24) >> 14);
    // 0x8006F474: addu        $t4, $t9, $t6
    ctx->r12 = ADD32(ctx->r25, ctx->r14);
    // 0x8006F478: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F47C: lh          $t6, 0x14($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X14);
    // 0x8006F480: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006F484: mflo        $t8
    ctx->r24 = lo;
    // 0x8006F488: srl         $t9, $t8, 14
    ctx->r25 = S32(U32(ctx->r24) >> 14);
    // 0x8006F48C: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x8006F490: subu        $t8, $t4, $t3
    ctx->r24 = SUB32(ctx->r12, ctx->r11);
    // 0x8006F494: subu        $t7, $t5, $t3
    ctx->r15 = SUB32(ctx->r13, ctx->r11);
    // 0x8006F498: addu        $t9, $t4, $t3
    ctx->r25 = ADD32(ctx->r12, ctx->r11);
    // 0x8006F49C: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x8006F4A0: sh          $t8, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r24;
    // 0x8006F4A4: sh          $t7, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r15;
    // 0x8006F4A8: sh          $t9, 0x24($a1)
    MEM_H(0X24, ctx->r5) = ctx->r25;
    // 0x8006F4AC: jr          $ra
    // 0x8006F4B0: sh          $t6, 0x26($a1)
    MEM_H(0X26, ctx->r5) = ctx->r14;
    return;
    // 0x8006F4B0: sh          $t6, 0x26($a1)
    MEM_H(0X26, ctx->r5) = ctx->r14;
;}

RECOMP_FUNC void Minos_TransformVtx_Rotate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F4B4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006F4B8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8006F4BC: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8006F4C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006F4C4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8006F4C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F4CC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006F4D0: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8006F4D4: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8006F4D8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8006F4DC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8006F4E0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006F4E4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006F4E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006F4EC: sb          $t6, -0x3BC($at)
    MEM_B(-0X3BC, ctx->r1) = ctx->r14;
    // 0x8006F4F0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006F4F4: lhu         $a0, 0x10($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X10);
    // 0x8006F4F8: jal         0x800B8010
    // 0x8006F4FC: addiu       $s0, $s0, -0x3E8
    ctx->r16 = ADD32(ctx->r16, -0X3E8);
    sins(rdram, ctx);
        goto after_0;
    // 0x8006F4FC: addiu       $s0, $s0, -0x3E8
    ctx->r16 = ADD32(ctx->r16, -0X3E8);
    after_0:
    // 0x8006F500: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006F504: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8006F508: lhu         $a0, 0x10($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X10);
    // 0x8006F50C: jal         0x800B8080
    // 0x8006F510: nop

    coss(rdram, ctx);
        goto after_1;
    // 0x8006F510: nop

    after_1:
    // 0x8006F514: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006F518: lw          $t9, -0x3F0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3F0);
    // 0x8006F51C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8006F520: lh          $t2, 0xE($t9)
    ctx->r10 = MEM_H(ctx->r25, 0XE);
    // 0x8006F524: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x8006F528: lhu         $s5, 0x6($t9)
    ctx->r21 = MEM_HU(ctx->r25, 0X6);
    // 0x8006F52C: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8006F530: sh          $t3, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r11;
    // 0x8006F534: lh          $t5, 0x10($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X10);
    // 0x8006F538: lh          $t4, 0x8($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X8);
    // 0x8006F53C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8006F540: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x8006F544: sh          $t6, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r14;
    // 0x8006F548: lhu         $t8, 0x8($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X8);
    // 0x8006F54C: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x8006F550: lhu         $t2, 0x8($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X8);
    // 0x8006F554: subu        $s3, $t7, $t8
    ctx->r19 = SUB32(ctx->r15, ctx->r24);
    // 0x8006F558: multu       $s3, $s2
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F55C: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x8006F560: sll         $t8, $t3, 16
    ctx->r24 = S32(ctx->r11 << 16);
    // 0x8006F564: subu        $s4, $t1, $t2
    ctx->r20 = SUB32(ctx->r9, ctx->r10);
    // 0x8006F568: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8006F56C: mflo        $t4
    ctx->r12 = lo;
    // 0x8006F570: nop

    // 0x8006F574: nop

    // 0x8006F578: multu       $s4, $s1
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F57C: mflo        $t5
    ctx->r13 = lo;
    // 0x8006F580: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x8006F584: sra         $t7, $t6, 15
    ctx->r15 = S32(SIGNED(ctx->r14) >> 15);
    // 0x8006F588: multu       $s3, $s1
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F58C: addu        $s3, $s3, $s5
    ctx->r19 = ADD32(ctx->r19, ctx->r21);
    // 0x8006F590: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8006F594: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x8006F598: lh          $t6, 0x42($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X42);
    // 0x8006F59C: mflo        $t1
    ctx->r9 = lo;
    // 0x8006F5A0: nop

    // 0x8006F5A4: nop

    // 0x8006F5A8: multu       $s4, $s2
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F5AC: mflo        $t2
    ctx->r10 = lo;
    // 0x8006F5B0: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8006F5B4: sra         $t5, $t4, 15
    ctx->r13 = S32(SIGNED(ctx->r12) >> 15);
    // 0x8006F5B8: multu       $s3, $s2
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F5BC: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x8006F5C0: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x8006F5C4: lh          $t1, 0x40($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X40);
    // 0x8006F5C8: mflo        $t8
    ctx->r24 = lo;
    // 0x8006F5CC: nop

    // 0x8006F5D0: nop

    // 0x8006F5D4: multu       $s4, $s1
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F5D8: mflo        $t7
    ctx->r15 = lo;
    // 0x8006F5DC: subu        $t0, $t8, $t7
    ctx->r8 = SUB32(ctx->r24, ctx->r15);
    // 0x8006F5E0: sra         $t9, $t0, 15
    ctx->r25 = S32(SIGNED(ctx->r8) >> 15);
    // 0x8006F5E4: multu       $s3, $s1
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F5E8: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8006F5EC: sh          $t2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r10;
    // 0x8006F5F0: lh          $t8, 0x42($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X42);
    // 0x8006F5F4: mflo        $t4
    ctx->r12 = lo;
    // 0x8006F5F8: nop

    // 0x8006F5FC: nop

    // 0x8006F600: multu       $s4, $s2
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F604: addu        $s4, $s4, $s5
    ctx->r20 = ADD32(ctx->r20, ctx->r21);
    // 0x8006F608: mflo        $t5
    ctx->r13 = lo;
    // 0x8006F60C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8006F610: sra         $t3, $t6, 15
    ctx->r11 = S32(SIGNED(ctx->r14) >> 15);
    // 0x8006F614: multu       $s3, $s2
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F618: addu        $t7, $t3, $t8
    ctx->r15 = ADD32(ctx->r11, ctx->r24);
    // 0x8006F61C: sh          $t7, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r15;
    // 0x8006F620: lh          $t4, 0x40($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X40);
    // 0x8006F624: mflo        $t0
    ctx->r8 = lo;
    // 0x8006F628: nop

    // 0x8006F62C: nop

    // 0x8006F630: multu       $s4, $s1
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F634: mflo        $t9
    ctx->r25 = lo;
    // 0x8006F638: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x8006F63C: sra         $t2, $t1, 15
    ctx->r10 = S32(SIGNED(ctx->r9) >> 15);
    // 0x8006F640: multu       $s3, $s1
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F644: subu        $s3, $s3, $s5
    ctx->r19 = SUB32(ctx->r19, ctx->r21);
    // 0x8006F648: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8006F64C: sh          $t5, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r13;
    // 0x8006F650: lh          $t0, 0x42($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X42);
    // 0x8006F654: mflo        $t6
    ctx->r14 = lo;
    // 0x8006F658: nop

    // 0x8006F65C: nop

    // 0x8006F660: multu       $s4, $s2
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F664: mflo        $t3
    ctx->r11 = lo;
    // 0x8006F668: addu        $t8, $t6, $t3
    ctx->r24 = ADD32(ctx->r14, ctx->r11);
    // 0x8006F66C: sra         $t7, $t8, 15
    ctx->r15 = S32(SIGNED(ctx->r24) >> 15);
    // 0x8006F670: multu       $s3, $s2
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F674: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8006F678: sh          $t9, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r25;
    // 0x8006F67C: lh          $t6, 0x40($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X40);
    // 0x8006F680: mflo        $t1
    ctx->r9 = lo;
    // 0x8006F684: nop

    // 0x8006F688: nop

    // 0x8006F68C: multu       $s4, $s1
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F690: mflo        $t2
    ctx->r10 = lo;
    // 0x8006F694: subu        $t4, $t1, $t2
    ctx->r12 = SUB32(ctx->r9, ctx->r10);
    // 0x8006F698: sra         $t5, $t4, 15
    ctx->r13 = S32(SIGNED(ctx->r12) >> 15);
    // 0x8006F69C: multu       $s3, $s1
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F6A0: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x8006F6A4: sh          $t3, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r11;
    // 0x8006F6A8: lh          $t1, 0x42($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X42);
    // 0x8006F6AC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006F6B0: mflo        $t8
    ctx->r24 = lo;
    // 0x8006F6B4: nop

    // 0x8006F6B8: nop

    // 0x8006F6BC: multu       $s4, $s2
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F6C0: mflo        $t7
    ctx->r15 = lo;
    // 0x8006F6C4: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x8006F6C8: sra         $t9, $t0, 15
    ctx->r25 = S32(SIGNED(ctx->r8) >> 15);
    // 0x8006F6CC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8006F6D0: sh          $t2, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r10;
    // 0x8006F6D4: lw          $t4, -0x3F0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3F0);
    // 0x8006F6D8: nop

    // 0x8006F6DC: lh          $t5, 0x14($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X14);
    // 0x8006F6E0: lhu         $s6, 0x2($t4)
    ctx->r22 = MEM_HU(ctx->r12, 0X2);
    // 0x8006F6E4: lh          $s7, 0x12($t4)
    ctx->r23 = MEM_H(ctx->r12, 0X12);
    // 0x8006F6E8: sh          $t5, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r13;
    // 0x8006F6EC: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8006F6F0: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x8006F6F4: multu       $t6, $s6
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F6F8: lh          $t5, 0xA($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA);
    // 0x8006F6FC: mflo        $t3
    ctx->r11 = lo;
    // 0x8006F700: srl         $t8, $t3, 14
    ctx->r24 = S32(U32(ctx->r11) >> 14);
    // 0x8006F704: addu        $t7, $t8, $s7
    ctx->r15 = ADD32(ctx->r24, ctx->r23);
    // 0x8006F708: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F70C: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x8006F710: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x8006F714: lh          $t2, 0x38($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X38);
    // 0x8006F718: mflo        $t9
    ctx->r25 = lo;
    // 0x8006F71C: srl         $t1, $t9, 14
    ctx->r9 = S32(U32(ctx->r25) >> 14);
    // 0x8006F720: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8006F724: multu       $t5, $s6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F728: sh          $t4, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r12;
    // 0x8006F72C: lh          $t4, 0x14($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X14);
    // 0x8006F730: mflo        $t6
    ctx->r14 = lo;
    // 0x8006F734: srl         $t3, $t6, 14
    ctx->r11 = S32(U32(ctx->r14) >> 14);
    // 0x8006F738: addu        $t8, $t3, $s7
    ctx->r24 = ADD32(ctx->r11, ctx->r23);
    // 0x8006F73C: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F740: sh          $t8, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r24;
    // 0x8006F744: lh          $t8, 0x16($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X16);
    // 0x8006F748: lh          $t1, 0x38($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X38);
    // 0x8006F74C: mflo        $t0
    ctx->r8 = lo;
    // 0x8006F750: srl         $t9, $t0, 14
    ctx->r25 = S32(U32(ctx->r8) >> 14);
    // 0x8006F754: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8006F758: multu       $t4, $s6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F75C: sh          $t2, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r10;
    // 0x8006F760: lh          $t2, 0x1E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1E);
    // 0x8006F764: mflo        $t5
    ctx->r13 = lo;
    // 0x8006F768: srl         $t6, $t5, 14
    ctx->r14 = S32(U32(ctx->r13) >> 14);
    // 0x8006F76C: addu        $t3, $t6, $s7
    ctx->r11 = ADD32(ctx->r14, ctx->r23);
    // 0x8006F770: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F774: sh          $t3, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r11;
    // 0x8006F778: lh          $t3, 0x20($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X20);
    // 0x8006F77C: lh          $t9, 0x38($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X38);
    // 0x8006F780: mflo        $t7
    ctx->r15 = lo;
    // 0x8006F784: srl         $t0, $t7, 14
    ctx->r8 = S32(U32(ctx->r15) >> 14);
    // 0x8006F788: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x8006F78C: multu       $t2, $s6
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F790: sh          $t1, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r9;
    // 0x8006F794: mflo        $t4
    ctx->r12 = lo;
    // 0x8006F798: srl         $t5, $t4, 14
    ctx->r13 = S32(U32(ctx->r12) >> 14);
    // 0x8006F79C: addu        $t6, $t5, $s7
    ctx->r14 = ADD32(ctx->r13, ctx->r23);
    // 0x8006F7A0: multu       $t3, $s6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F7A4: sh          $t6, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r14;
    // 0x8006F7A8: lh          $t0, 0x38($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X38);
    // 0x8006F7AC: mflo        $t8
    ctx->r24 = lo;
    // 0x8006F7B0: srl         $t7, $t8, 14
    ctx->r15 = S32(U32(ctx->r24) >> 14);
    // 0x8006F7B4: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8006F7B8: sh          $t9, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r25;
    // 0x8006F7BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006F7C0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8006F7C4: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8006F7C8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8006F7CC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8006F7D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006F7D4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F7D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006F7DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006F7E0: jr          $ra
    // 0x8006F7E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006F7E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}

RECOMP_FUNC void Minos_TransformVtx_None(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F7E8: jr          $ra
    // 0x8006F7EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006F7EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

RECOMP_FUNC void Minos_8006f7f0_sets_struct_0_to_0x11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F7F0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006F7F4: lw          $a1, 0x20C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X20C0);
    // 0x8006F7F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F7FC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8006F800: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8006F804: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8006F808: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8006F80C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8006F810: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006F814: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8006F818: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006F81C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F820: lui         $t9, 0xF590
    ctx->r25 = S32(0XF590 << 16);
    // 0x8006F824: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8006F828: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F82C: lui         $t1, 0x700
    ctx->r9 = S32(0X700 << 16);
    // 0x8006F830: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006F834: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8006F838: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8006F83C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8006F840: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x8006F844: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8006F848: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8006F84C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006F850: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8006F854: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x8006F858: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x8006F85C: lui         $t6, 0xFD90
    ctx->r14 = S32(0XFD90 << 16);
    // 0x8006F860: ori         $t6, $t6, 0xFFF
    ctx->r14 = ctx->r14 | 0XFFF;
    // 0x8006F864: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8006F868: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x8006F86C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006F870: sw          $a0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r4;
    // 0x8006F874: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x8006F878: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x8006F87C: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8006F880: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8006F884: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x8006F888: lui         $t1, 0x701
    ctx->r9 = S32(0X701 << 16);
    // 0x8006F88C: ori         $t1, $t1, 0xF800
    ctx->r9 = ctx->r9 | 0XF800;
    // 0x8006F890: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8006F894: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8006F898: lbu         $t3, 0x560($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X560);
    // 0x8006F89C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006F8A0: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x8006F8A4: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x8006F8A8: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8006F8AC: lui         $at, 0xD700
    ctx->r1 = S32(0XD700 << 16);
    // 0x8006F8B0: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8006F8B4: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8006F8B8: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8006F8BC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8006F8C0: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8006F8C4: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8006F8C8: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x8006F8CC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006F8D0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8006F8D4: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
    // 0x8006F8D8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8006F8DC: lui         $t1, 0xE800
    ctx->r9 = S32(0XE800 << 16);
    // 0x8006F8E0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8006F8E4: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x8006F8E8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006F8EC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8006F8F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006F8F4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8006F8F8: lui         $t4, 0xF588
    ctx->r12 = S32(0XF588 << 16);
    // 0x8006F8FC: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x8006F900: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006F904: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8006F908: lbu         $t6, 0x560($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X560);
    // 0x8006F90C: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8006F910: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8006F914: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8006F918: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8006F91C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8006F920: ori         $t0, $t9, 0x200
    ctx->r8 = ctx->r25 | 0X200;
    // 0x8006F924: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006F928: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8006F92C: sw          $a1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r5;
    // 0x8006F930: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8006F934: lui         $t2, 0xF200
    ctx->r10 = S32(0XF200 << 16);
    // 0x8006F938: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8006F93C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8006F940: lbu         $t4, 0x560($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X560);
    // 0x8006F944: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8006F948: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x8006F94C: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x8006F950: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8006F954: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8006F958: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8006F95C: ori         $t8, $t7, 0x1C
    ctx->r24 = ctx->r15 | 0X1C;
    // 0x8006F960: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006F964: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8006F968: lbu         $t0, 0x560($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X560);
    // 0x8006F96C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F970: sb          $t0, -0x3AC($at)
    MEM_B(-0X3AC, ctx->r1) = ctx->r8;
    // 0x8006F974: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006F978: xori        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 ^ 0X2;
    // 0x8006F97C: sb          $t1, 0x560($at)
    MEM_B(0X560, ctx->r1) = ctx->r9;
    // 0x8006F980: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006F984: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F988: sw          $a1, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r5;
    // 0x8006F98C: jr          $ra
    // 0x8006F990: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006F990: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Minos_8006f994_sets_struct_0_to_0x23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F994: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8006F998: lw          $a2, 0x20C0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X20C0);
    // 0x8006F99C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006F9A0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8006F9A4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8006F9A8: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8006F9AC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8006F9B0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8006F9B4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006F9B8: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8006F9BC: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x8006F9C0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8006F9C4: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8006F9C8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8006F9CC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8006F9D0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006F9D4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8006F9D8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8006F9DC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8006F9E0: lui         $t2, 0xF590
    ctx->r10 = S32(0XF590 << 16);
    // 0x8006F9E4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8006F9E8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8006F9EC: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x8006F9F0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006F9F4: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8006F9F8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x8006F9FC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8006FA00: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FA04: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8006FA08: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8006FA0C: lui         $t9, 0xFD90
    ctx->r25 = S32(0XFD90 << 16);
    // 0x8006FA10: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8006FA14: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8006FA18: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006FA1C: ori         $t9, $t9, 0xFFF
    ctx->r25 = ctx->r25 | 0XFFF;
    // 0x8006FA20: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8006FA24: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8006FA28: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FA2C: sw          $a0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r4;
    // 0x8006FA30: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8006FA34: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8006FA38: lui         $t2, 0xF300
    ctx->r10 = S32(0XF300 << 16);
    // 0x8006FA3C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8006FA40: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8006FA44: lui         $t4, 0x701
    ctx->r12 = S32(0X701 << 16);
    // 0x8006FA48: ori         $t4, $t4, 0xF800
    ctx->r12 = ctx->r12 | 0XF800;
    // 0x8006FA4C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FA50: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8006FA54: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8006FA58: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8006FA5C: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8006FA60: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8006FA64: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8006FA68: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FA6C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8006FA70: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8006FA74: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8006FA78: lui         $t9, 0xF590
    ctx->r25 = S32(0XF590 << 16);
    // 0x8006FA7C: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x8006FA80: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8006FA84: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8006FA88: lui         $t1, 0x700
    ctx->r9 = S32(0X700 << 16);
    // 0x8006FA8C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FA90: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8006FA94: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006FA98: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8006FA9C: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x8006FAA0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8006FAA4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8006FAA8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FAAC: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8006FAB0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8006FAB4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8006FAB8: lui         $t6, 0xFD90
    ctx->r14 = S32(0XFD90 << 16);
    // 0x8006FABC: ori         $t6, $t6, 0xFFF
    ctx->r14 = ctx->r14 | 0XFFF;
    // 0x8006FAC0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8006FAC4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8006FAC8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FACC: sw          $a1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r5;
    // 0x8006FAD0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006FAD4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006FAD8: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8006FADC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8006FAE0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8006FAE4: lui         $t1, 0x701
    ctx->r9 = S32(0X701 << 16);
    // 0x8006FAE8: ori         $t1, $t1, 0xF800
    ctx->r9 = ctx->r9 | 0XF800;
    // 0x8006FAEC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8006FAF0: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8006FAF4: lbu         $t3, 0x560($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X560);
    // 0x8006FAF8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FAFC: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x8006FB00: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x8006FB04: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8006FB08: lui         $at, 0xD700
    ctx->r1 = S32(0XD700 << 16);
    // 0x8006FB0C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8006FB10: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8006FB14: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8006FB18: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8006FB1C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8006FB20: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8006FB24: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x8006FB28: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FB2C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8006FB30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8006FB34: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8006FB38: lui         $t1, 0xE800
    ctx->r9 = S32(0XE800 << 16);
    // 0x8006FB3C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8006FB40: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8006FB44: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FB48: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8006FB4C: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x8006FB50: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x8006FB54: lui         $t4, 0xF588
    ctx->r12 = S32(0XF588 << 16);
    // 0x8006FB58: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x8006FB5C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006FB60: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8006FB64: lbu         $t6, 0x560($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X560);
    // 0x8006FB68: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8006FB6C: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8006FB70: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8006FB74: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x8006FB78: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8006FB7C: ori         $t0, $t9, 0x200
    ctx->r8 = ctx->r25 | 0X200;
    // 0x8006FB80: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FB84: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8006FB88: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8006FB8C: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x8006FB90: lui         $t2, 0xF200
    ctx->r10 = S32(0XF200 << 16);
    // 0x8006FB94: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8006FB98: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8006FB9C: lbu         $t4, 0x560($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X560);
    // 0x8006FBA0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8006FBA4: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x8006FBA8: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x8006FBAC: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8006FBB0: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x8006FBB4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8006FBB8: ori         $t8, $t7, 0x1C
    ctx->r24 = ctx->r15 | 0X1C;
    // 0x8006FBBC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FBC0: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8006FBC4: sw          $a2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r6;
    // 0x8006FBC8: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8006FBCC: lui         $t0, 0xE800
    ctx->r8 = S32(0XE800 << 16);
    // 0x8006FBD0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8006FBD4: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8006FBD8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FBDC: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8006FBE0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006FBE4: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x8006FBE8: lui         $t3, 0xF588
    ctx->r11 = S32(0XF588 << 16);
    // 0x8006FBEC: ori         $t3, $t3, 0x208
    ctx->r11 = ctx->r11 | 0X208;
    // 0x8006FBF0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8006FBF4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8006FBF8: lbu         $t5, 0x560($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X560);
    // 0x8006FBFC: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8006FC00: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8006FC04: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8006FC08: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8006FC0C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8006FC10: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8006FC14: ori         $t0, $t9, 0x200
    ctx->r8 = ctx->r25 | 0X200;
    // 0x8006FC18: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FC1C: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8006FC20: sw          $a2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r6;
    // 0x8006FC24: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8006FC28: lui         $t2, 0xF200
    ctx->r10 = S32(0XF200 << 16);
    // 0x8006FC2C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8006FC30: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8006FC34: lbu         $t4, 0x560($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X560);
    // 0x8006FC38: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8006FC3C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8006FC40: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x8006FC44: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8006FC48: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8006FC4C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8006FC50: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8006FC54: ori         $t9, $t8, 0x1C
    ctx->r25 = ctx->r24 | 0X1C;
    // 0x8006FC58: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8006FC5C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8006FC60: lbu         $t1, 0x560($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X560);
    // 0x8006FC64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006FC68: sb          $t1, -0x3AC($at)
    MEM_B(-0X3AC, ctx->r1) = ctx->r9;
    // 0x8006FC6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006FC70: xori        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 ^ 0X2;
    // 0x8006FC74: sb          $t2, 0x560($at)
    MEM_B(0X560, ctx->r1) = ctx->r10;
    // 0x8006FC78: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FC7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006FC80: sw          $a2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r6;
    // 0x8006FC84: jr          $ra
    // 0x8006FC88: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8006FC88: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}

RECOMP_FUNC void Minos_8006fc8c_twentyfive_liner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FC8C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006FC90: lbu         $t6, -0x3B0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3B0);
    // 0x8006FC94: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8006FC98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006FC9C: bne         $a0, $t6, L_8006FCB8
    if (ctx->r4 != ctx->r14) {
        // 0x8006FCA0: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_8006FCB8;
    }
    // 0x8006FCA0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8006FCA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006FCA8: lbu         $t7, -0x3AF($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3AF);
    // 0x8006FCAC: nop

    // 0x8006FCB0: beq         $a1, $t7, L_8006FE30
    if (ctx->r5 == ctx->r15) {
        // 0x8006FCB4: nop
    
            goto L_8006FE30;
    }
    // 0x8006FCB4: nop

L_8006FCB8:
    // 0x8006FCB8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8006FCBC: lw          $a2, 0x20C0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X20C0);
    // 0x8006FCC0: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8006FCC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006FCC8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8006FCCC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006FCD0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8006FCD4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006FCD8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FCDC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8006FCE0: lbu         $t1, -0x3B0($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X3B0);
    // 0x8006FCE4: nop

    // 0x8006FCE8: beq         $a0, $t1, L_8006FDB0
    if (ctx->r4 == ctx->r9) {
        // 0x8006FCEC: nop
    
            goto L_8006FDB0;
    }
    // 0x8006FCEC: nop

    // 0x8006FCF0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006FCF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006FCF8: beq         $a3, $at, L_8006FD10
    if (ctx->r7 == ctx->r1) {
        // 0x8006FCFC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006FD10;
    }
    // 0x8006FCFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006FD00: beq         $a3, $at, L_8006FD5C
    if (ctx->r7 == ctx->r1) {
        // 0x8006FD04: nop
    
            goto L_8006FD5C;
    }
    // 0x8006FD04: nop

    // 0x8006FD08: b           L_8006FDA8
    // 0x8006FD0C: nop

        goto L_8006FDA8;
    // 0x8006FD0C: nop

L_8006FD10:
    // 0x8006FD10: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8006FD14: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8006FD18: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x8006FD1C: ori         $t2, $t2, 0xA01
    ctx->r10 = ctx->r10 | 0XA01;
    // 0x8006FD20: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8006FD24: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006FD28: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FD2C: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8006FD30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8006FD34: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006FD38: lui         $t5, 0xFC50
    ctx->r13 = S32(0XFC50 << 16);
    // 0x8006FD3C: ori         $t5, $t5, 0xFEA1
    ctx->r13 = ctx->r13 | 0XFEA1;
    // 0x8006FD40: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8006FD44: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006FD48: lui         $t7, 0x33FD
    ctx->r15 = S32(0X33FD << 16);
    // 0x8006FD4C: ori         $t7, $t7, 0xF6FB
    ctx->r15 = ctx->r15 | 0XF6FB;
    // 0x8006FD50: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FD54: b           L_8006FDA8
    // 0x8006FD58: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
        goto L_8006FDA8;
    // 0x8006FD58: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_8006FD5C:
    // 0x8006FD5C: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x8006FD60: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x8006FD64: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x8006FD68: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x8006FD6C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8006FD70: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8006FD74: lui         $t1, 0x10
    ctx->r9 = S32(0X10 << 16);
    // 0x8006FD78: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FD7C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8006FD80: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8006FD84: lw          $t4, 0x10($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10);
    // 0x8006FD88: lui         $t3, 0xFC26
    ctx->r11 = S32(0XFC26 << 16);
    // 0x8006FD8C: ori         $t3, $t3, 0x7EA0
    ctx->r11 = ctx->r11 | 0X7EA0;
    // 0x8006FD90: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8006FD94: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8006FD98: lui         $t5, 0x13FC
    ctx->r13 = S32(0X13FC << 16);
    // 0x8006FD9C: ori         $t5, $t5, 0xF8FB
    ctx->r13 = ctx->r13 | 0XF8FB;
    // 0x8006FDA0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FDA4: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
L_8006FDA8:
    // 0x8006FDA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006FDAC: sb          $a0, -0x3B0($at)
    MEM_B(-0X3B0, ctx->r1) = ctx->r4;
L_8006FDB0:
    // 0x8006FDB0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006FDB4: lbu         $t7, -0x3AF($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3AF);
    // 0x8006FDB8: nop

    // 0x8006FDBC: beq         $a1, $t7, L_8006FE28
    if (ctx->r5 == ctx->r15) {
        // 0x8006FDC0: nop
    
            goto L_8006FE28;
    }
    // 0x8006FDC0: nop

    // 0x8006FDC4: beq         $a1, $zero, L_8006FDF8
    if (ctx->r5 == 0) {
        // 0x8006FDC8: nop
    
            goto L_8006FDF8;
    }
    // 0x8006FDC8: nop

    // 0x8006FDCC: sw          $a2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r6;
    // 0x8006FDD0: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8006FDD4: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x8006FDD8: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x8006FDDC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8006FDE0: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8006FDE4: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x8006FDE8: ori         $t0, $t0, 0x41C8
    ctx->r8 = ctx->r8 | 0X41C8;
    // 0x8006FDEC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FDF0: b           L_8006FE20
    // 0x8006FDF4: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
        goto L_8006FE20;
    // 0x8006FDF4: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
L_8006FDF8:
    // 0x8006FDF8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006FDFC: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x8006FE00: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x8006FE04: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x8006FE08: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8006FE0C: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8006FE10: lui         $t4, 0x55
    ctx->r12 = S32(0X55 << 16);
    // 0x8006FE14: ori         $t4, $t4, 0x2048
    ctx->r12 = ctx->r12 | 0X2048;
    // 0x8006FE18: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8006FE1C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
L_8006FE20:
    // 0x8006FE20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006FE24: sb          $a1, -0x3AF($at)
    MEM_B(-0X3AF, ctx->r1) = ctx->r5;
L_8006FE28:
    // 0x8006FE28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006FE2C: sw          $a2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r6;
L_8006FE30:
    // 0x8006FE30: jr          $ra
    // 0x8006FE34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006FE34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Minos_Mino_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FE38: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8006FE3C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8006FE40: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8006FE44: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006FE48: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8006FE4C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8006FE50: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8006FE54: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8006FE58: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006FE5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006FE60: lbu         $t7, 0x1C($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1C);
    // 0x8006FE64: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006FE68: lbu         $s0, 0x21($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0X21);
    // 0x8006FE6C: bne         $t7, $at, L_8006FE84
    if (ctx->r15 != ctx->r1) {
        // 0x8006FE70: nop
    
            goto L_8006FE84;
    }
    // 0x8006FE70: nop

    // 0x8006FE74: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8006FE78: lbu         $s1, -0x3AE($s1)
    ctx->r17 = MEM_BU(ctx->r17, -0X3AE);
    // 0x8006FE7C: b           L_8006FED8
    // 0x8006FE80: nop

        goto L_8006FED8;
    // 0x8006FE80: nop

L_8006FE84:
    // 0x8006FE84: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006FE88: lbu         $t8, -0x3AE($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X3AE);
    // 0x8006FE8C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006FE90: bne         $t8, $at, L_8006FEAC
    if (ctx->r24 != ctx->r1) {
        // 0x8006FE94: nop
    
            goto L_8006FEAC;
    }
    // 0x8006FE94: nop

    // 0x8006FE98: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8006FE9C: nop

    // 0x8006FEA0: lbu         $s1, 0x1C($t9)
    ctx->r17 = MEM_BU(ctx->r25, 0X1C);
    // 0x8006FEA4: b           L_8006FED8
    // 0x8006FEA8: nop

        goto L_8006FED8;
    // 0x8006FEA8: nop

L_8006FEAC:
    // 0x8006FEAC: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8006FEB0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006FEB4: lbu         $t2, -0x3AE($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X3AE);
    // 0x8006FEB8: lbu         $t1, 0x1C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1C);
    // 0x8006FEBC: nop

    // 0x8006FEC0: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FEC4: mflo        $s1
    ctx->r17 = lo;
    // 0x8006FEC8: srl         $t3, $s1, 8
    ctx->r11 = S32(U32(ctx->r17) >> 8);
    // 0x8006FECC: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x8006FED0: andi        $t4, $s1, 0xFF
    ctx->r12 = ctx->r17 & 0XFF;
    // 0x8006FED4: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
L_8006FED8:
    // 0x8006FED8: beq         $s1, $zero, L_800702C4
    if (ctx->r17 == 0) {
        // 0x8006FEDC: nop
    
            goto L_800702C4;
    }
    // 0x8006FEDC: nop

    // 0x8006FEE0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006FEE4: lw          $t9, -0x3B4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3B4);
    // 0x8006FEE8: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8006FEEC: jalr        $t9
    // 0x8006FEF0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8006FEF0: nop

    after_0:
    // 0x8006FEF4: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8006FEF8: nop

    // 0x8006FEFC: lbu         $t6, 0x1($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X1);
    // 0x8006FF00: nop

    // 0x8006FF04: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8006FF08: bne         $t7, $zero, L_8006FF14
    if (ctx->r15 != 0) {
        // 0x8006FF0C: nop
    
            goto L_8006FF14;
    }
    // 0x8006FF0C: nop

    // 0x8006FF10: blez        $s0, L_8006FF58
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8006FF14: slti        $at, $s0, 0xFF
        ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
            goto L_8006FF58;
    }
L_8006FF14:
    // 0x8006FF14: slti        $at, $s0, 0xFF
    ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
    // 0x8006FF18: beq         $at, $zero, L_8006FF2C
    if (ctx->r1 == 0) {
        // 0x8006FF1C: nop
    
            goto L_8006FF2C;
    }
    // 0x8006FF1C: nop

    // 0x8006FF20: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8006FF24: jal         0x8006F260
    // 0x8006FF28: nop

    Minos_SetTilePositions(rdram, ctx);
        goto after_1;
    // 0x8006FF28: nop

    after_1:
L_8006FF2C:
    // 0x8006FF2C: blez        $s0, L_8006FF40
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8006FF30: nop
    
            goto L_8006FF40;
    }
    // 0x8006FF30: nop

    // 0x8006FF34: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8006FF38: jal         0x8006F300
    // 0x8006FF3C: nop

    Minos_SampleTiles(rdram, ctx);
        goto after_2;
    // 0x8006FF3C: nop

    after_2:
L_8006FF40:
    // 0x8006FF40: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8006FF44: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8006FF48: lbu         $t0, 0x1($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X1);
    // 0x8006FF4C: nop

    // 0x8006FF50: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8006FF54: sb          $t1, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r9;
L_8006FF58:
    // 0x8006FF58: bne         $s0, $zero, L_8006FF74
    if (ctx->r16 != 0) {
        // 0x8006FF5C: nop
    
            goto L_8006FF74;
    }
    // 0x8006FF5C: nop

    // 0x8006FF60: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8006FF64: jal         0x8006F7F0
    // 0x8006FF68: addiu       $a0, $a0, 0xB0
    ctx->r4 = ADD32(ctx->r4, 0XB0);
    Minos_8006f7f0_sets_struct_0_to_0x11(rdram, ctx);
        goto after_3;
    // 0x8006FF68: addiu       $a0, $a0, 0xB0
    ctx->r4 = ADD32(ctx->r4, 0XB0);
    after_3:
    // 0x8006FF6C: b           L_8006FFA8
    // 0x8006FF70: nop

        goto L_8006FFA8;
    // 0x8006FF70: nop

L_8006FF74:
    // 0x8006FF74: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006FF78: bne         $s0, $at, L_8006FF94
    if (ctx->r16 != ctx->r1) {
        // 0x8006FF7C: nop
    
            goto L_8006FF94;
    }
    // 0x8006FF7C: nop

    // 0x8006FF80: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8006FF84: jal         0x8006F7F0
    // 0x8006FF88: addiu       $a0, $a0, 0xF0
    ctx->r4 = ADD32(ctx->r4, 0XF0);
    Minos_8006f7f0_sets_struct_0_to_0x11(rdram, ctx);
        goto after_4;
    // 0x8006FF88: addiu       $a0, $a0, 0xF0
    ctx->r4 = ADD32(ctx->r4, 0XF0);
    after_4:
    // 0x8006FF8C: b           L_8006FFA8
    // 0x8006FF90: nop

        goto L_8006FFA8;
    // 0x8006FF90: nop

L_8006FF94:
    // 0x8006FF94: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x8006FF98: nop

    // 0x8006FF9C: addiu       $a0, $t2, 0xB0
    ctx->r4 = ADD32(ctx->r10, 0XB0);
    // 0x8006FFA0: jal         0x8006F994
    // 0x8006FFA4: addiu       $a1, $t2, 0xF0
    ctx->r5 = ADD32(ctx->r10, 0XF0);
    Minos_8006f994_sets_struct_0_to_0x23(rdram, ctx);
        goto after_5;
    // 0x8006FFA4: addiu       $a1, $t2, 0xF0
    ctx->r5 = ADD32(ctx->r10, 0XF0);
    after_5:
L_8006FFA8:
    // 0x8006FFA8: beq         $s0, $zero, L_8006FFB4
    if (ctx->r16 == 0) {
        // 0x8006FFAC: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8006FFB4;
    }
    // 0x8006FFAC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006FFB0: bne         $s0, $at, L_8006FFE8
    if (ctx->r16 != ctx->r1) {
        // 0x8006FFB4: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8006FFE8;
    }
L_8006FFB4:
    // 0x8006FFB4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006FFB8: bne         $s1, $at, L_8006FFD4
    if (ctx->r17 != ctx->r1) {
        // 0x8006FFBC: nop
    
            goto L_8006FFD4;
    }
    // 0x8006FFBC: nop

    // 0x8006FFC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006FFC4: jal         0x8006FC8C
    // 0x8006FFC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Minos_8006fc8c_twentyfive_liner(rdram, ctx);
        goto after_6;
    // 0x8006FFC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8006FFCC: b           L_80070014
    // 0x8006FFD0: nop

        goto L_80070014;
    // 0x8006FFD0: nop

L_8006FFD4:
    // 0x8006FFD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006FFD8: jal         0x8006FC8C
    // 0x8006FFDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Minos_8006fc8c_twentyfive_liner(rdram, ctx);
        goto after_7;
    // 0x8006FFDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8006FFE0: b           L_80070014
    // 0x8006FFE4: nop

        goto L_80070014;
    // 0x8006FFE4: nop

L_8006FFE8:
    // 0x8006FFE8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006FFEC: bne         $s1, $at, L_80070008
    if (ctx->r17 != ctx->r1) {
        // 0x8006FFF0: nop
    
            goto L_80070008;
    }
    // 0x8006FFF0: nop

    // 0x8006FFF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8006FFF8: jal         0x8006FC8C
    // 0x8006FFFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Minos_8006fc8c_twentyfive_liner(rdram, ctx);
        goto after_8;
    // 0x8006FFFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80070000: b           L_80070014
    // 0x80070004: nop

        goto L_80070014;
    // 0x80070004: nop

L_80070008:
    // 0x80070008: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8007000C: jal         0x8006FC8C
    // 0x80070010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Minos_8006fc8c_twentyfive_liner(rdram, ctx);
        goto after_9;
    // 0x80070010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_80070014:
    // 0x80070014: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x80070018: lw          $s5, 0x20C0($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X20C0);
    // 0x8007001C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80070020: sw          $s5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r21;
    // 0x80070024: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80070028: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x8007002C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80070030: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80070034: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80070038: lh          $t5, 0x4($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X4);
    // 0x8007003C: lh          $t1, 0x6($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X6);
    // 0x80070040: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x80070044: lh          $t5, 0x8($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X8);
    // 0x80070048: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8007004C: sra         $t8, $t1, 4
    ctx->r24 = S32(SIGNED(ctx->r9) >> 4);
    // 0x80070050: andi        $t2, $t8, 0xFF
    ctx->r10 = ctx->r24 & 0XFF;
    // 0x80070054: sll         $t0, $t7, 24
    ctx->r8 = S32(ctx->r15 << 24);
    // 0x80070058: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8007005C: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x80070060: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80070064: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x80070068: sll         $t1, $t7, 8
    ctx->r9 = S32(ctx->r15 << 8);
    // 0x8007006C: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80070070: or          $t8, $t4, $t1
    ctx->r24 = ctx->r12 | ctx->r9;
    // 0x80070074: andi        $t2, $s1, 0xFF
    ctx->r10 = ctx->r17 & 0XFF;
    // 0x80070078: or          $t0, $t8, $t2
    ctx->r8 = ctx->r24 | ctx->r10;
    // 0x8007007C: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x80070080: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80070084: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80070088: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8007008C: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x80070090: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80070094: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80070098: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x8007009C: lh          $t2, 0xC($t6)
    ctx->r10 = MEM_H(ctx->r14, 0XC);
    // 0x800700A0: sra         $t4, $t7, 4
    ctx->r12 = S32(SIGNED(ctx->r15) >> 4);
    // 0x800700A4: lh          $t7, 0xE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE);
    // 0x800700A8: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x800700AC: sra         $t0, $t2, 4
    ctx->r8 = S32(SIGNED(ctx->r10) >> 4);
    // 0x800700B0: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x800700B4: sll         $t8, $t1, 24
    ctx->r24 = S32(ctx->r9 << 24);
    // 0x800700B8: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x800700BC: sra         $t4, $t7, 4
    ctx->r12 = S32(SIGNED(ctx->r15) >> 4);
    // 0x800700C0: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x800700C4: or          $t5, $t8, $t9
    ctx->r13 = ctx->r24 | ctx->r25;
    // 0x800700C8: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800700CC: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800700D0: or          $t0, $t5, $t2
    ctx->r8 = ctx->r13 | ctx->r10;
    // 0x800700D4: andi        $t3, $s0, 0xFF
    ctx->r11 = ctx->r16 & 0XFF;
    // 0x800700D8: or          $t8, $t0, $t3
    ctx->r24 = ctx->r8 | ctx->r11;
    // 0x800700DC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800700E0: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x800700E4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800700E8: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800700EC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800700F0: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x800700F4: addiu       $s6, $s6, -0x3E8
    ctx->r22 = ADD32(ctx->r22, -0X3E8);
    // 0x800700F8: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800700FC: lbu         $s7, 0x2C($s6)
    ctx->r23 = MEM_BU(ctx->r22, 0X2C);
    // 0x80070100: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80070104: beq         $s7, $at, L_80070120
    if (ctx->r23 == ctx->r1) {
        // 0x80070108: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_80070120;
    }
    // 0x80070108: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x8007010C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80070110: beq         $s7, $at, L_800701D8
    if (ctx->r23 == ctx->r1) {
        // 0x80070114: nop
    
            goto L_800701D8;
    }
    // 0x80070114: nop

    // 0x80070118: b           L_800702BC
    // 0x8007011C: nop

        goto L_800702BC;
    // 0x8007011C: nop

L_80070120:
    // 0x80070120: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80070124: lh          $t2, 0x24($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X24);
    // 0x80070128: lh          $t1, 0x26($s6)
    ctx->r9 = MEM_H(ctx->r22, 0X26);
    // 0x8007012C: andi        $t0, $t2, 0xFFF
    ctx->r8 = ctx->r10 & 0XFFF;
    // 0x80070130: sll         $t3, $t0, 12
    ctx->r11 = S32(ctx->r8 << 12);
    // 0x80070134: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80070138: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8007013C: or          $t8, $t3, $at
    ctx->r24 = ctx->r11 | ctx->r1;
    // 0x80070140: andi        $t5, $t1, 0xFFF
    ctx->r13 = ctx->r9 & 0XFFF;
    // 0x80070144: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x80070148: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8007014C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80070150: lbu         $t7, -0x3AC($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3AC);
    // 0x80070154: lh          $t2, 0x6($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X6);
    // 0x80070158: lh          $t8, 0x8($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X8);
    // 0x8007015C: andi        $t4, $t7, 0x7
    ctx->r12 = ctx->r15 & 0X7;
    // 0x80070160: andi        $t0, $t2, 0xFFF
    ctx->r8 = ctx->r10 & 0XFFF;
    // 0x80070164: sll         $t3, $t0, 12
    ctx->r11 = S32(ctx->r8 << 12);
    // 0x80070168: sll         $t1, $t4, 24
    ctx->r9 = S32(ctx->r12 << 24);
    // 0x8007016C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80070170: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x80070174: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80070178: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8007017C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80070180: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80070184: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80070188: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8007018C: lui         $t4, 0xE100
    ctx->r12 = S32(0XE100 << 16);
    // 0x80070190: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80070194: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80070198: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x8007019C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800701A0: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x800701A4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800701A8: lui         $t1, 0xF100
    ctx->r9 = S32(0XF100 << 16);
    // 0x800701AC: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800701B0: lh          $t8, 0x2E($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X2E);
    // 0x800701B4: lh          $t6, 0x30($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X30);
    // 0x800701B8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800701BC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800701C0: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x800701C4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800701C8: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800701CC: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800701D0: b           L_800702BC
    // 0x800701D4: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
        goto L_800702BC;
    // 0x800701D4: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
L_800701D8:
    // 0x800701D8: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800701DC: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800701E0: lui         $t0, 0x218
    ctx->r8 = S32(0X218 << 16);
    // 0x800701E4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800701E8: lh          $t8, 0x6($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X6);
    // 0x800701EC: lh          $t3, 0x8($s6)
    ctx->r11 = MEM_H(ctx->r22, 0X8);
    // 0x800701F0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800701F4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800701F8: or          $t6, $t3, $t9
    ctx->r14 = ctx->r11 | ctx->r25;
    // 0x800701FC: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80070200: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x80070204: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80070208: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8007020C: lui         $t7, 0x218
    ctx->r15 = S32(0X218 << 16);
    // 0x80070210: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x80070214: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80070218: lh          $t0, 0x10($s6)
    ctx->r8 = MEM_H(ctx->r22, 0X10);
    // 0x8007021C: lh          $t2, 0x12($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X12);
    // 0x80070220: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80070224: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80070228: or          $t8, $t2, $t1
    ctx->r24 = ctx->r10 | ctx->r9;
    // 0x8007022C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80070230: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x80070234: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80070238: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8007023C: lui         $t9, 0x218
    ctx->r25 = S32(0X218 << 16);
    // 0x80070240: ori         $t9, $t9, 0x4
    ctx->r25 = ctx->r25 | 0X4;
    // 0x80070244: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80070248: lh          $t7, 0x1A($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X1A);
    // 0x8007024C: lh          $t5, 0x1C($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X1C);
    // 0x80070250: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80070254: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x80070258: or          $t0, $t5, $t4
    ctx->r8 = ctx->r13 | ctx->r12;
    // 0x8007025C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80070260: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    // 0x80070264: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80070268: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8007026C: lui         $t1, 0x218
    ctx->r9 = S32(0X218 << 16);
    // 0x80070270: ori         $t1, $t1, 0x6
    ctx->r9 = ctx->r9 | 0X6;
    // 0x80070274: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80070278: lh          $t9, 0x24($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X24);
    // 0x8007027C: lh          $t3, 0x26($s6)
    ctx->r11 = MEM_H(ctx->r22, 0X26);
    // 0x80070280: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80070284: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80070288: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x8007028C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80070290: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80070294: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80070298: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8007029C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800702A0: ori         $t4, $t4, 0x204
    ctx->r12 = ctx->r12 | 0X204;
    // 0x800702A4: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800702A8: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800702AC: lui         $t2, 0x2
    ctx->r10 = S32(0X2 << 16);
    // 0x800702B0: ori         $t2, $t2, 0x604
    ctx->r10 = ctx->r10 | 0X604;
    // 0x800702B4: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800702B8: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
L_800702BC:
    // 0x800702BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800702C0: sw          $s5, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r21;
L_800702C4:
    // 0x800702C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800702C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800702CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800702D0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800702D4: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800702D8: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800702DC: jr          $ra
    // 0x800702E0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800702E0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}

RECOMP_FUNC void Minos_ApplyPendingParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80070A38: lw          $a0, -0x3F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3F0);
    // 0x80070A3C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070A40: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80070A44: nop

    // 0x80070A48: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80070A4C: beq         $t7, $zero, L_80070A68
    if (ctx->r15 == 0) {
        // 0x80070A50: nop
    
            goto L_80070A68;
    }
    // 0x80070A50: nop

    // 0x80070A54: lwl         $at, 0x16($a0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r4, 0X16);
    // 0x80070A58: lwr         $at, 0x19($a0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r4, 0X19);
    // 0x80070A5C: nop

    // 0x80070A60: swl         $at, 0xE($a0)
    do_swl(rdram, 0XE, ctx->r4, ctx->r1);
    // 0x80070A64: swr         $at, 0x11($a0)
    do_swr(rdram, 0X11, ctx->r4, ctx->r1);
L_80070A68:
    // 0x80070A68: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x80070A6C: nop

    // 0x80070A70: andi        $t1, $t0, 0xD
    ctx->r9 = ctx->r8 & 0XD;
    // 0x80070A74: beq         $t1, $zero, L_80070AD8
    if (ctx->r9 == 0) {
        // 0x80070A78: nop
    
            goto L_80070AD8;
    }
    // 0x80070A78: nop

    // 0x80070A7C: lh          $t2, 0xE($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XE);
    // 0x80070A80: lhu         $t3, 0x2($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X2);
    // 0x80070A84: lh          $t1, 0x10($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X10);
    // 0x80070A88: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070A8C: lhu         $t2, 0x2($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X2);
    // 0x80070A90: lh          $t6, 0x1A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1A);
    // 0x80070A94: lhu         $t8, 0x2($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X2);
    // 0x80070A98: nop

    // 0x80070A9C: sra         $t9, $t8, 7
    ctx->r25 = S32(SIGNED(ctx->r24) >> 7);
    // 0x80070AA0: lhu         $t8, 0x2($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X2);
    // 0x80070AA4: mflo        $t4
    ctx->r12 = lo;
    // 0x80070AA8: sra         $t5, $t4, 14
    ctx->r13 = S32(SIGNED(ctx->r12) >> 14);
    // 0x80070AAC: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x80070AB0: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070AB4: lh          $t6, 0x1C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1C);
    // 0x80070AB8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80070ABC: sra         $t7, $t8, 7
    ctx->r15 = S32(SIGNED(ctx->r24) >> 7);
    // 0x80070AC0: sh          $t0, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r8;
    // 0x80070AC4: mflo        $t3
    ctx->r11 = lo;
    // 0x80070AC8: sra         $t4, $t3, 14
    ctx->r12 = S32(SIGNED(ctx->r11) >> 14);
    // 0x80070ACC: addu        $t5, $t6, $t4
    ctx->r13 = ADD32(ctx->r14, ctx->r12);
    // 0x80070AD0: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x80070AD4: sh          $t9, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r25;
L_80070AD8:
    // 0x80070AD8: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x80070ADC: nop

    // 0x80070AE0: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80070AE4: beq         $t1, $zero, L_80070BB8
    if (ctx->r9 == 0) {
        // 0x80070AE8: nop
    
            goto L_80070BB8;
    }
    // 0x80070AE8: nop

    // 0x80070AEC: lhu         $t2, 0x2($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X2);
    // 0x80070AF0: lui         $at, 0x4B80
    ctx->r1 = S32(0X4B80 << 16);
    // 0x80070AF4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80070AF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80070AFC: bgez        $t2, L_80070B14
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80070B00: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80070B14;
    }
    // 0x80070B00: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80070B04: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80070B08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80070B0C: nop

    // 0x80070B10: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80070B14:
    // 0x80070B14: nop

    // 0x80070B18: div.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80070B1C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80070B20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80070B24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80070B28: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070B2C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80070B30: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80070B34: nop

    // 0x80070B38: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80070B3C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80070B40: nop

    // 0x80070B44: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80070B48: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80070B4C: beq         $t6, $zero, L_80070B9C
    if (ctx->r14 == 0) {
        // 0x80070B50: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80070B9C;
    }
    // 0x80070B50: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80070B54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80070B58: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80070B5C: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80070B60: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80070B64: nop

    // 0x80070B68: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80070B6C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80070B70: nop

    // 0x80070B74: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80070B78: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80070B7C: bne         $t6, $zero, L_80070B94
    if (ctx->r14 != 0) {
        // 0x80070B80: nop
    
            goto L_80070B94;
    }
    // 0x80070B80: nop

    // 0x80070B84: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80070B88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070B8C: b           L_80070BAC
    // 0x80070B90: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80070BAC;
    // 0x80070B90: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80070B94:
    // 0x80070B94: b           L_80070BAC
    // 0x80070B98: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80070BAC;
    // 0x80070B98: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80070B9C:
    // 0x80070B9C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80070BA0: nop

    // 0x80070BA4: bltz        $t6, L_80070B94
    if (SIGNED(ctx->r14) < 0) {
        // 0x80070BA8: nop
    
            goto L_80070B94;
    }
    // 0x80070BA8: nop

L_80070BAC:
    // 0x80070BAC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80070BB0: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x80070BB4: nop

L_80070BB8:
    // 0x80070BB8: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x80070BBC: nop

    // 0x80070BC0: andi        $t8, $t4, 0x3
    ctx->r24 = ctx->r12 & 0X3;
    // 0x80070BC4: beq         $t8, $zero, L_80070C34
    if (ctx->r24 == 0) {
        // 0x80070BC8: nop
    
            goto L_80070C34;
    }
    // 0x80070BC8: nop

    // 0x80070BCC: lhu         $t5, 0x2($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2);
    // 0x80070BD0: lhu         $t7, 0x6($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X6);
    // 0x80070BD4: lui         $t2, 0x20
    ctx->r10 = S32(0X20 << 16);
    // 0x80070BD8: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070BDC: lui         $t6, 0x20
    ctx->r14 = S32(0X20 << 16);
    // 0x80070BE0: lhu         $t0, 0x6($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X6);
    // 0x80070BE4: nop

    // 0x80070BE8: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80070BEC: sh          $t1, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r9;
    // 0x80070BF0: mflo        $a1
    ctx->r5 = lo;
    // 0x80070BF4: srl         $t9, $a1, 8
    ctx->r25 = S32(U32(ctx->r5) >> 8);
    // 0x80070BF8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80070BFC: divu        $zero, $t2, $a1
    lo = S32(U32(ctx->r10) / U32(ctx->r5)); hi = S32(U32(ctx->r10) % U32(ctx->r5));
    // 0x80070C00: bne         $a1, $zero, L_80070C0C
    if (ctx->r5 != 0) {
        // 0x80070C04: nop
    
            goto L_80070C0C;
    }
    // 0x80070C04: nop

    // 0x80070C08: break       7
    do_break(2147945480);
L_80070C0C:
    // 0x80070C0C: mflo        $t3
    ctx->r11 = lo;
    // 0x80070C10: sh          $t3, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r11;
    // 0x80070C14: nop

    // 0x80070C18: divu        $zero, $t6, $a1
    lo = S32(U32(ctx->r14) / U32(ctx->r5)); hi = S32(U32(ctx->r14) % U32(ctx->r5));
    // 0x80070C1C: bne         $a1, $zero, L_80070C28
    if (ctx->r5 != 0) {
        // 0x80070C20: nop
    
            goto L_80070C28;
    }
    // 0x80070C20: nop

    // 0x80070C24: break       7
    do_break(2147945508);
L_80070C28:
    // 0x80070C28: mflo        $t4
    ctx->r12 = lo;
    // 0x80070C2C: sh          $t4, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r12;
    // 0x80070C30: nop

L_80070C34:
    // 0x80070C34: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80070C38: jr          $ra
    // 0x80070C3C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80070C3C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Minos_80070c40_twoliner_set_OR_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070C40: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80070C44: lw          $t6, -0x3F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3F0);
    // 0x80070C48: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80070C4C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80070C50: sh          $a0, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r4;
    // 0x80070C54: lw          $t7, -0x3F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3F0);
    // 0x80070C58: nop

    // 0x80070C5C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80070C60: nop

    // 0x80070C64: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80070C68: jr          $ra
    // 0x80070C6C: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    return;
    // 0x80070C6C: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
;}

RECOMP_FUNC void Minos_SetPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070C70: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80070C74: lw          $t6, -0x3F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3F0);
    // 0x80070C78: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80070C7C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80070C80: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80070C84: sh          $a0, 0x16($t6)
    MEM_H(0X16, ctx->r14) = ctx->r4;
    // 0x80070C88: lw          $t7, -0x3F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3F0);
    // 0x80070C8C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80070C90: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80070C94: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80070C98: sh          $a1, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r5;
    // 0x80070C9C: lw          $t8, -0x3F0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3F0);
    // 0x80070CA0: nop

    // 0x80070CA4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80070CA8: nop

    // 0x80070CAC: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x80070CB0: jr          $ra
    // 0x80070CB4: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
    return;
    // 0x80070CB4: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
;}

RECOMP_FUNC void Minos_80070cb8_threeliner_set_OR_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070CB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80070CBC: lw          $t6, -0x3F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3F0);
    // 0x80070CC0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80070CC4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80070CC8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80070CCC: sh          $a0, 0x1A($t6)
    MEM_H(0X1A, ctx->r14) = ctx->r4;
    // 0x80070CD0: lw          $t7, -0x3F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3F0);
    // 0x80070CD4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80070CD8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80070CDC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80070CE0: sh          $a1, 0x1C($t7)
    MEM_H(0X1C, ctx->r15) = ctx->r5;
    // 0x80070CE4: lw          $t8, -0x3F0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3F0);
    // 0x80070CE8: nop

    // 0x80070CEC: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80070CF0: nop

    // 0x80070CF4: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x80070CF8: jr          $ra
    // 0x80070CFC: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
    return;
    // 0x80070CFC: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
;}

RECOMP_FUNC void Minos_SetScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070D00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80070D04: lw          $t6, -0x3F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3F0);
    // 0x80070D08: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80070D0C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80070D10: sh          $a0, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r4;
    // 0x80070D14: lw          $t7, -0x3F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3F0);
    // 0x80070D18: nop

    // 0x80070D1C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80070D20: nop

    // 0x80070D24: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80070D28: jr          $ra
    // 0x80070D2C: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    return;
    // 0x80070D2C: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
;}

RECOMP_FUNC void Minos_SetAlpha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070D30: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80070D34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80070D38: jr          $ra
    // 0x80070D3C: sb          $a0, -0x3AE($at)
    MEM_B(-0X3AE, ctx->r1) = ctx->r4;
    return;
    // 0x80070D3C: sb          $a0, -0x3AE($at)
    MEM_B(-0X3AE, ctx->r1) = ctx->r4;
;}

RECOMP_FUNC void Minos_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070D40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070D44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80070D48: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80070D4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80070D50: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80070D54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80070D58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070D5C: sw          $t6, -0x3C0($at)
    MEM_W(-0X3C0, ctx->r1) = ctx->r14;
    // 0x80070D60: sh          $zero, 0x20($t7)
    MEM_H(0X20, ctx->r15) = 0;
    // 0x80070D64: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80070D68: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80070D6C: sh          $zero, 0x22($t8)
    MEM_H(0X22, ctx->r24) = 0;
    // 0x80070D70: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80070D74: nop

    // 0x80070D78: sh          $zero, 0x24($t9)
    MEM_H(0X24, ctx->r25) = 0;
    // 0x80070D7C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80070D80: nop

    // 0x80070D84: sh          $zero, 0x30($t0)
    MEM_H(0X30, ctx->r8) = 0;
    // 0x80070D88: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80070D8C: nop

    // 0x80070D90: sh          $zero, 0x32($t1)
    MEM_H(0X32, ctx->r9) = 0;
    // 0x80070D94: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80070D98: nop

    // 0x80070D9C: sh          $zero, 0x34($t2)
    MEM_H(0X34, ctx->r10) = 0;
    // 0x80070DA0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80070DA4: nop

    // 0x80070DA8: sh          $zero, 0x40($t3)
    MEM_H(0X40, ctx->r11) = 0;
    // 0x80070DAC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80070DB0: addiu       $t3, $zero, 0x380
    ctx->r11 = ADD32(0, 0X380);
    // 0x80070DB4: sh          $zero, 0x42($t4)
    MEM_H(0X42, ctx->r12) = 0;
    // 0x80070DB8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80070DBC: nop

    // 0x80070DC0: sh          $zero, 0x44($t5)
    MEM_H(0X44, ctx->r13) = 0;
    // 0x80070DC4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80070DC8: nop

    // 0x80070DCC: sh          $zero, 0x50($t6)
    MEM_H(0X50, ctx->r14) = 0;
    // 0x80070DD0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80070DD4: nop

    // 0x80070DD8: sh          $zero, 0x52($t7)
    MEM_H(0X52, ctx->r15) = 0;
    // 0x80070DDC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80070DE0: nop

    // 0x80070DE4: sh          $zero, 0x54($t8)
    MEM_H(0X54, ctx->r24) = 0;
    // 0x80070DE8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80070DEC: addiu       $t8, $zero, 0x380
    ctx->r24 = ADD32(0, 0X380);
    // 0x80070DF0: sh          $zero, 0x26($t9)
    MEM_H(0X26, ctx->r25) = 0;
    // 0x80070DF4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80070DF8: nop

    // 0x80070DFC: sh          $zero, 0x28($t0)
    MEM_H(0X28, ctx->r8) = 0;
    // 0x80070E00: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80070E04: nop

    // 0x80070E08: sh          $zero, 0x2A($t1)
    MEM_H(0X2A, ctx->r9) = 0;
    // 0x80070E0C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80070E10: addiu       $t1, $zero, 0x380
    ctx->r9 = ADD32(0, 0X380);
    // 0x80070E14: sh          $zero, 0x36($t2)
    MEM_H(0X36, ctx->r10) = 0;
    // 0x80070E18: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80070E1C: nop

    // 0x80070E20: sh          $t3, 0x38($t4)
    MEM_H(0X38, ctx->r12) = ctx->r11;
    // 0x80070E24: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80070E28: nop

    // 0x80070E2C: sh          $zero, 0x3A($t5)
    MEM_H(0X3A, ctx->r13) = 0;
    // 0x80070E30: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80070E34: nop

    // 0x80070E38: sh          $zero, 0x46($t6)
    MEM_H(0X46, ctx->r14) = 0;
    // 0x80070E3C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80070E40: nop

    // 0x80070E44: sh          $zero, 0x48($t7)
    MEM_H(0X48, ctx->r15) = 0;
    // 0x80070E48: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80070E4C: nop

    // 0x80070E50: sh          $t8, 0x4A($t9)
    MEM_H(0X4A, ctx->r25) = ctx->r24;
    // 0x80070E54: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80070E58: nop

    // 0x80070E5C: sh          $zero, 0x56($t0)
    MEM_H(0X56, ctx->r8) = 0;
    // 0x80070E60: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80070E64: nop

    // 0x80070E68: sh          $t1, 0x58($t2)
    MEM_H(0X58, ctx->r10) = ctx->r9;
    // 0x80070E6C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80070E70: jal         0x80070C40
    // 0x80070E74: sh          $t3, 0x5A($t4)
    MEM_H(0X5A, ctx->r12) = ctx->r11;
    Minos_80070c40_twoliner_set_OR_1(rdram, ctx);
        goto after_0;
    // 0x80070E74: sh          $t3, 0x5A($t4)
    MEM_H(0X5A, ctx->r12) = ctx->r11;
    after_0:
    // 0x80070E78: addiu       $a0, $zero, 0x500
    ctx->r4 = ADD32(0, 0X500);
    // 0x80070E7C: jal         0x80070C70
    // 0x80070E80: addiu       $a1, $zero, 0xA00
    ctx->r5 = ADD32(0, 0XA00);
    Minos_SetPosition(rdram, ctx);
        goto after_1;
    // 0x80070E80: addiu       $a1, $zero, 0xA00
    ctx->r5 = ADD32(0, 0XA00);
    after_1:
    // 0x80070E84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80070E88: jal         0x80070CB8
    // 0x80070E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Minos_80070cb8_threeliner_set_OR_4(rdram, ctx);
        goto after_2;
    // 0x80070E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80070E90: jal         0x80070D00
    // 0x80070E94: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    Minos_SetScale(rdram, ctx);
        goto after_3;
    // 0x80070E94: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_3:
    // 0x80070E98: jal         0x8007116C
    // 0x80070E9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Minos_SetVtxTransform(rdram, ctx);
        goto after_4;
    // 0x80070E9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80070EA0: jal         0x80070D30
    // 0x80070EA4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    Minos_SetAlpha(rdram, ctx);
        goto after_5;
    // 0x80070EA4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_5:
    // 0x80070EA8: jal         0x80070A34
    // 0x80070EAC: nop

    Minos_ApplyPendingParams(rdram, ctx);
        goto after_6;
    // 0x80070EAC: nop

    after_6:
    // 0x80070EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070EB8: jr          $ra
    // 0x80070EBC: nop

    return;
    // 0x80070EBC: nop

;}

RECOMP_FUNC void Minos_Deinit_doesnothing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070EC0: jr          $ra
    // 0x80070EC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80070EC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

RECOMP_FUNC void Minos_BeginRender(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070EC8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80070ECC: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80070ED0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80070ED4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80070ED8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80070EDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80070EE0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80070EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070EE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80070EEC: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x80070EF0: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x80070EF4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80070EF8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80070EFC: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80070F00: addiu       $t0, $t0, 0x568
    ctx->r8 = ADD32(ctx->r8, 0X568);
    // 0x80070F04: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80070F08: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80070F0C: lw          $t2, 0x20C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20C0);
    // 0x80070F10: lui         $t4, 0x100
    ctx->r12 = S32(0X100 << 16);
    // 0x80070F14: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80070F18: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80070F1C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80070F20: sw          $t3, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r11;
    // 0x80070F24: ori         $t4, $t4, 0x4008
    ctx->r12 = ctx->r12 | 0X4008;
    // 0x80070F28: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80070F2C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80070F30: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80070F34: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x80070F38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80070F3C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80070F40: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80070F44: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80070F48: sb          $t9, -0x3B0($at)
    MEM_B(-0X3B0, ctx->r1) = ctx->r25;
    // 0x80070F4C: sb          $t0, -0x3AF($at)
    MEM_B(-0X3AF, ctx->r1) = ctx->r8;
    // 0x80070F50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80070F54: jal         0x8006FC8C
    // 0x80070F58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Minos_8006fc8c_twentyfive_liner(rdram, ctx);
        goto after_0;
    // 0x80070F58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80070F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070F60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80070F64: sb          $zero, 0x560($at)
    MEM_B(0X560, ctx->r1) = 0;
    // 0x80070F68: jr          $ra
    // 0x80070F6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80070F6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void Minos_EndRender(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070F70: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80070F74: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80070F78: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070F7C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80070F80: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80070F84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80070F88: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80070F8C: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80070F90: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x80070F94: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80070F98: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80070F9C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80070FA0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80070FA4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80070FA8: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x80070FAC: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x80070FB0: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x80070FB4: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x80070FB8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80070FBC: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x80070FC0: ori         $t3, $t3, 0xA01
    ctx->r11 = ctx->r11 | 0XA01;
    // 0x80070FC4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80070FC8: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x80070FCC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070FD0: jr          $ra
    // 0x80070FD4: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    return;
    // 0x80070FD4: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
;}

RECOMP_FUNC void Minos_TransformVec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070FD8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80070FDC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80070FE0: lw          $a3, -0x3F0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X3F0);
    // 0x80070FE4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80070FE8: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80070FEC: lh          $t7, 0x12($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X12);
    // 0x80070FF0: lhu         $t2, 0x4($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X4);
    // 0x80070FF4: subu        $t0, $t6, $t7
    ctx->r8 = SUB32(ctx->r14, ctx->r15);
    // 0x80070FF8: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070FFC: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x80071000: lh          $t9, 0x14($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X14);
    // 0x80071004: lhu         $t4, 0x4($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X4);
    // 0x80071008: subu        $t1, $t8, $t9
    ctx->r9 = SUB32(ctx->r24, ctx->r25);
    // 0x8007100C: lh          $t6, 0xE($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XE);
    // 0x80071010: mflo        $t0
    ctx->r8 = lo;
    // 0x80071014: sra         $t3, $t0, 10
    ctx->r11 = S32(SIGNED(ctx->r8) >> 10);
    // 0x80071018: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x8007101C: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071020: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80071024: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80071028: lh          $t8, 0x10($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X10);
    // 0x8007102C: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x80071030: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80071034: mflo        $t1
    ctx->r9 = lo;
    // 0x80071038: sra         $t5, $t1, 10
    ctx->r13 = S32(SIGNED(ctx->r9) >> 10);
    // 0x8007103C: or          $t1, $t5, $zero
    ctx->r9 = ctx->r13 | 0;
    // 0x80071040: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x80071044: jr          $ra
    // 0x80071048: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    return;
    // 0x80071048: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
;}

RECOMP_FUNC void Minos_TransformCoords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007104C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80071050: lw          $a3, -0x3F0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X3F0);
    // 0x80071054: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80071058: lh          $t6, 0x12($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X12);
    // 0x8007105C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80071060: subu        $a1, $a1, $t6
    ctx->r5 = SUB32(ctx->r5, ctx->r14);
    // 0x80071064: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80071068: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8007106C: lhu         $t2, 0x4($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X4);
    // 0x80071070: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80071074: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80071078: multu       $a1, $t2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007107C: lh          $t9, 0x14($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X14);
    // 0x80071080: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80071084: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80071088: subu        $a2, $a2, $t9
    ctx->r6 = SUB32(ctx->r6, ctx->r25);
    // 0x8007108C: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x80071090: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80071094: lhu         $t6, 0x4($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X4);
    // 0x80071098: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8007109C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800710A0: lh          $t0, 0xE($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XE);
    // 0x800710A4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800710A8: mflo        $a1
    ctx->r5 = lo;
    // 0x800710AC: sra         $t3, $a1, 10
    ctx->r11 = S32(SIGNED(ctx->r5) >> 10);
    // 0x800710B0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800710B4: multu       $a2, $t6
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800710B8: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x800710BC: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800710C0: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800710C4: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800710C8: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x800710CC: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x800710D0: lh          $t2, 0x10($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X10);
    // 0x800710D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800710D8: mflo        $a2
    ctx->r6 = lo;
    // 0x800710DC: sra         $t7, $a2, 10
    ctx->r15 = S32(SIGNED(ctx->r6) >> 10);
    // 0x800710E0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800710E4: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800710E8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800710EC: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800710F0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800710F4: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x800710F8: jr          $ra
    // 0x800710FC: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
    return;
    // 0x800710FC: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
;}

RECOMP_FUNC void Minos_TransformVecRot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071100: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80071104: lw          $a2, -0x3F0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X3F0);
    // 0x80071108: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8007110C: lh          $t7, 0xE($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XE);
    // 0x80071110: lhu         $t1, 0x2($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X2);
    // 0x80071114: subu        $a3, $t6, $t7
    ctx->r7 = SUB32(ctx->r14, ctx->r15);
    // 0x80071118: multu       $t1, $a3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007111C: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x80071120: lh          $t9, 0x10($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X10);
    // 0x80071124: lhu         $t3, 0x2($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X2);
    // 0x80071128: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8007112C: lh          $t5, 0x12($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X12);
    // 0x80071130: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80071134: mflo        $a3
    ctx->r7 = lo;
    // 0x80071138: sra         $t2, $a3, 14
    ctx->r10 = S32(SIGNED(ctx->r7) >> 14);
    // 0x8007113C: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x80071140: multu       $t3, $t0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071144: addu        $t6, $t5, $a3
    ctx->r14 = ADD32(ctx->r13, ctx->r7);
    // 0x80071148: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x8007114C: lh          $t7, 0x14($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X14);
    // 0x80071150: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80071154: mflo        $t0
    ctx->r8 = lo;
    // 0x80071158: sra         $t4, $t0, 14
    ctx->r12 = S32(SIGNED(ctx->r8) >> 14);
    // 0x8007115C: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x80071160: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x80071164: jr          $ra
    // 0x80071168: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
    return;
    // 0x80071168: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
;}

RECOMP_FUNC void Minos_SetVtxTransform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007116C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80071170: lw          $t6, -0x3F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3F0);
    // 0x80071174: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80071178: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007117C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80071180: beq         $a1, $zero, L_8007119C
    if (ctx->r5 == 0) {
        // 0x80071184: sb          $a0, 0x1E($t6)
        MEM_B(0X1E, ctx->r14) = ctx->r4;
            goto L_8007119C;
    }
    // 0x80071184: sb          $a0, 0x1E($t6)
    MEM_B(0X1E, ctx->r14) = ctx->r4;
    // 0x80071188: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007118C: beq         $a1, $at, L_800711B0
    if (ctx->r5 == ctx->r1) {
        // 0x80071190: nop
    
            goto L_800711B0;
    }
    // 0x80071190: nop

    // 0x80071194: b           L_800711C4
    // 0x80071198: nop

        goto L_800711C4;
    // 0x80071198: nop

L_8007119C:
    // 0x8007119C: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x800711A0: addiu       $t7, $t7, -0xC64
    ctx->r15 = ADD32(ctx->r15, -0XC64);
    // 0x800711A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800711A8: b           L_800711D4
    // 0x800711AC: sw          $t7, -0x3B4($at)
    MEM_W(-0X3B4, ctx->r1) = ctx->r15;
        goto L_800711D4;
    // 0x800711AC: sw          $t7, -0x3B4($at)
    MEM_W(-0X3B4, ctx->r1) = ctx->r15;
L_800711B0:
    // 0x800711B0: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x800711B4: addiu       $t8, $t8, -0xB4C
    ctx->r24 = ADD32(ctx->r24, -0XB4C);
    // 0x800711B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800711BC: b           L_800711D4
    // 0x800711C0: sw          $t8, -0x3B4($at)
    MEM_W(-0X3B4, ctx->r1) = ctx->r24;
        goto L_800711D4;
    // 0x800711C0: sw          $t8, -0x3B4($at)
    MEM_W(-0X3B4, ctx->r1) = ctx->r24;
L_800711C4:
    // 0x800711C4: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x800711C8: addiu       $t9, $t9, -0x818
    ctx->r25 = ADD32(ctx->r25, -0X818);
    // 0x800711CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800711D0: sw          $t9, -0x3B4($at)
    MEM_W(-0X3B4, ctx->r1) = ctx->r25;
L_800711D4:
    // 0x800711D4: jr          $ra
    // 0x800711D8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800711D8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800711DC: nop

;}

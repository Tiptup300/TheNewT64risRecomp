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

RECOMP_FUNC void Minos_Mino_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800702E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800702E8: lw          $t6, -0x350($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X350);
    // 0x800702EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800702F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800702F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800702F8: addiu       $a1, $t6, 0x7FFF
    ctx->r5 = ADD32(ctx->r14, 0X7FFF);
    // 0x800702FC: lw          $a1, 0x5C01($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5C01);
    // 0x80070300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80070304: jal         0x80070818
    // 0x80070308: nop

    Minos_Mino_SetGraphicHandle(rdram, ctx);
        goto after_0;
    // 0x80070308: nop

    after_0:
    // 0x8007030C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80070310: nop

    // 0x80070314: lw          $a1, 0x130($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X130);
    // 0x80070318: jal         0x800A2F30
    // 0x8007031C: addiu       $a0, $t7, 0x24
    ctx->r4 = ADD32(ctx->r15, 0X24);
    Minos_CopyGrid(rdram, ctx);
        goto after_1;
    // 0x8007031C: addiu       $a0, $t7, 0x24
    ctx->r4 = ADD32(ctx->r15, 0X24);
    after_1:
    // 0x80070320: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80070324: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80070328: sb          $t8, 0x1C($t9)
    MEM_B(0X1C, ctx->r25) = ctx->r24;
    // 0x8007032C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80070330: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80070334: lbu         $t1, 0x1C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1C);
    // 0x80070338: nop

    // 0x8007033C: sb          $t1, 0x1E($t0)
    MEM_B(0X1E, ctx->r8) = ctx->r9;
    // 0x80070340: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80070344: nop

    // 0x80070348: sb          $zero, 0x1D($t2)
    MEM_B(0X1D, ctx->r10) = 0;
    // 0x8007034C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80070350: nop

    // 0x80070354: sh          $zero, 0x20($t3)
    MEM_H(0X20, ctx->r11) = 0;
    // 0x80070358: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8007035C: nop

    // 0x80070360: sh          $zero, 0x22($t4)
    MEM_H(0X22, ctx->r12) = 0;
    // 0x80070364: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80070368: nop

    // 0x8007036C: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x80070370: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80070374: nop

    // 0x80070378: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x8007037C: nop

    // 0x80070380: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80070384: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x80070388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007038C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070390: jr          $ra
    // 0x80070394: nop

    return;
    // 0x80070394: nop

;}

RECOMP_FUNC void Minos_Mino_MorphGrid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800704E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800704E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800704E8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800704EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800704F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800704F4: lw          $a0, 0x130($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X130);
    // 0x800704F8: jal         0x800A2F50
    // 0x800704FC: addiu       $a1, $t6, 0x24
    ctx->r5 = ADD32(ctx->r14, 0X24);
    Minos_StepBytesToward(rdram, ctx);
        goto after_0;
    // 0x800704FC: addiu       $a1, $t6, 0x24
    ctx->r5 = ADD32(ctx->r14, 0X24);
    after_0:
    // 0x80070500: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80070504: bne         $s0, $zero, L_80070518
    if (ctx->r16 != 0) {
        // 0x80070508: nop
    
            goto L_80070518;
    }
    // 0x80070508: nop

    // 0x8007050C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80070510: nop

    // 0x80070514: sw          $zero, 0x130($t7)
    MEM_W(0X130, ctx->r15) = 0;
L_80070518:
    // 0x80070518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007051C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80070520: jr          $ra
    // 0x80070524: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80070524: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Minos_Mino_Morph(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070528: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007052C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80070530: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80070534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80070538: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007053C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80070540: lw          $t7, 0x130($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X130);
    // 0x80070544: nop

    // 0x80070548: beq         $t7, $zero, L_800705E8
    if (ctx->r15 == 0) {
        // 0x8007054C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800705E8;
    }
    // 0x8007054C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070550: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80070554: sltu        $at, $t7, $at
    ctx->r1 = ctx->r15 < ctx->r1 ? 1 : 0;
    // 0x80070558: bne         $at, $zero, L_80070590
    if (ctx->r1 != 0) {
        // 0x8007055C: lui         $at, 0x8040
        ctx->r1 = S32(0X8040 << 16);
            goto L_80070590;
    }
    // 0x8007055C: lui         $at, 0x8040
    ctx->r1 = S32(0X8040 << 16);
    // 0x80070560: sltu        $at, $t7, $at
    ctx->r1 = ctx->r15 < ctx->r1 ? 1 : 0;
    // 0x80070564: beq         $at, $zero, L_80070590
    if (ctx->r1 == 0) {
        // 0x80070568: nop
    
            goto L_80070590;
    }
    // 0x80070568: nop

    // 0x8007056C: jal         0x800704E0
    // 0x80070570: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    Minos_Mino_MorphGrid(rdram, ctx);
        goto after_0;
    // 0x80070570: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80070574: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80070578: nop

    // 0x8007057C: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x80070580: nop

    // 0x80070584: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80070588: b           L_800705E8
    // 0x8007058C: sb          $t0, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r8;
        goto L_800705E8;
    // 0x8007058C: sb          $t0, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r8;
L_80070590:
    // 0x80070590: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80070594: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80070598: lw          $a1, 0x130($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X130);
    // 0x8007059C: addiu       $a0, $a0, -0x26E0
    ctx->r4 = ADD32(ctx->r4, -0X26E0);
    // 0x800705A0: jal         0x800B3BFC
    // 0x800705A4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800705A4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_1:
    // 0x800705A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800705AC: lw          $t2, -0x350($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X350);
    // 0x800705B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800705B4: addiu       $a1, $t2, 0x7FFF
    ctx->r5 = ADD32(ctx->r10, 0X7FFF);
    // 0x800705B8: lw          $a1, 0x5C3D($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5C3D);
    // 0x800705BC: jal         0x80070818
    // 0x800705C0: nop

    Minos_Mino_SetGraphicHandle(rdram, ctx);
        goto after_2;
    // 0x800705C0: nop

    after_2:
    // 0x800705C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800705C8: jal         0x800704E0
    // 0x800705CC: nop

    Minos_Mino_MorphGrid(rdram, ctx);
        goto after_3;
    // 0x800705CC: nop

    after_3:
    // 0x800705D0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800705D4: nop

    // 0x800705D8: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x800705DC: nop

    // 0x800705E0: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x800705E4: sb          $t5, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r13;
L_800705E8:
    // 0x800705E8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800705EC: nop

    // 0x800705F0: lbu         $t6, 0x2($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X2);
    // 0x800705F4: nop

    // 0x800705F8: beq         $t6, $zero, L_800706B8
    if (ctx->r14 == 0) {
        // 0x800705FC: nop
    
            goto L_800706B8;
    }
    // 0x800705FC: nop

    // 0x80070600: lh          $t9, 0x4($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X4);
    // 0x80070604: lh          $t0, 0x10($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X10);
    // 0x80070608: nop

    // 0x8007060C: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x80070610: sh          $t8, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r24;
    // 0x80070614: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80070618: nop

    // 0x8007061C: lh          $t2, 0x6($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X6);
    // 0x80070620: lh          $t4, 0x12($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X12);
    // 0x80070624: nop

    // 0x80070628: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8007062C: sh          $t5, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r13;
    // 0x80070630: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80070634: nop

    // 0x80070638: lh          $t6, 0x8($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X8);
    // 0x8007063C: lh          $t9, 0x14($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X14);
    // 0x80070640: nop

    // 0x80070644: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80070648: sh          $t0, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r8;
    // 0x8007064C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80070650: nop

    // 0x80070654: lh          $t7, 0xA($t8)
    ctx->r15 = MEM_H(ctx->r24, 0XA);
    // 0x80070658: lh          $t2, 0x16($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X16);
    // 0x8007065C: nop

    // 0x80070660: addu        $t4, $t7, $t2
    ctx->r12 = ADD32(ctx->r15, ctx->r10);
    // 0x80070664: sh          $t4, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r12;
    // 0x80070668: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8007066C: nop

    // 0x80070670: lh          $t1, 0xC($t5)
    ctx->r9 = MEM_H(ctx->r13, 0XC);
    // 0x80070674: lh          $t6, 0x18($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X18);
    // 0x80070678: nop

    // 0x8007067C: addu        $t9, $t1, $t6
    ctx->r25 = ADD32(ctx->r9, ctx->r14);
    // 0x80070680: sh          $t9, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r25;
    // 0x80070684: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80070688: nop

    // 0x8007068C: lh          $t3, 0xE($t0)
    ctx->r11 = MEM_H(ctx->r8, 0XE);
    // 0x80070690: lh          $t7, 0x1A($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X1A);
    // 0x80070694: nop

    // 0x80070698: addu        $t2, $t3, $t7
    ctx->r10 = ADD32(ctx->r11, ctx->r15);
    // 0x8007069C: sh          $t2, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r10;
    // 0x800706A0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800706A4: nop

    // 0x800706A8: lbu         $t8, 0x2($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X2);
    // 0x800706AC: nop

    // 0x800706B0: addiu       $t1, $t8, -0x1
    ctx->r9 = ADD32(ctx->r24, -0X1);
    // 0x800706B4: sb          $t1, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r9;
L_800706B8:
    // 0x800706B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800706BC: nop

    // 0x800706C0: lbu         $t9, 0x1C($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X1C);
    // 0x800706C4: lbu         $t5, 0x1E($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X1E);
    // 0x800706C8: nop

    // 0x800706CC: beq         $t9, $t5, L_80070784
    if (ctx->r25 == ctx->r13) {
        // 0x800706D0: nop
    
            goto L_80070784;
    }
    // 0x800706D0: nop

    // 0x800706D4: lb          $t3, 0x1D($t6)
    ctx->r11 = MEM_B(ctx->r14, 0X1D);
    // 0x800706D8: lbu         $s1, 0x1E($t6)
    ctx->r17 = MEM_BU(ctx->r14, 0X1E);
    // 0x800706DC: blez        $t3, L_80070728
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800706E0: or          $s0, $t9, $zero
        ctx->r16 = ctx->r25 | 0;
            goto L_80070728;
    }
    // 0x800706E0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x800706E4: addu        $t7, $t3, $s0
    ctx->r15 = ADD32(ctx->r11, ctx->r16);
    // 0x800706E8: slt         $at, $t7, $s1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800706EC: bne         $at, $zero, L_8007070C
    if (ctx->r1 != 0) {
        // 0x800706F0: nop
    
            goto L_8007070C;
    }
    // 0x800706F0: nop

    // 0x800706F4: lbu         $t2, 0x1E($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X1E);
    // 0x800706F8: nop

    // 0x800706FC: sb          $t2, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r10;
    // 0x80070700: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80070704: b           L_80070728
    // 0x80070708: sb          $zero, 0x1D($t0)
    MEM_B(0X1D, ctx->r8) = 0;
        goto L_80070728;
    // 0x80070708: sb          $zero, 0x1D($t0)
    MEM_B(0X1D, ctx->r8) = 0;
L_8007070C:
    // 0x8007070C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80070710: nop

    // 0x80070714: lbu         $t1, 0x1C($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X1C);
    // 0x80070718: lb          $t4, 0x1D($t8)
    ctx->r12 = MEM_B(ctx->r24, 0X1D);
    // 0x8007071C: nop

    // 0x80070720: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80070724: sb          $t5, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r13;
L_80070728:
    // 0x80070728: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007072C: nop

    // 0x80070730: lb          $t3, 0x1D($t9)
    ctx->r11 = MEM_B(ctx->r25, 0X1D);
    // 0x80070734: nop

    // 0x80070738: bgez        $t3, L_80070784
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007073C: nop
    
            goto L_80070784;
    }
    // 0x8007073C: nop

    // 0x80070740: addu        $t7, $t3, $s0
    ctx->r15 = ADD32(ctx->r11, ctx->r16);
    // 0x80070744: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80070748: bne         $at, $zero, L_80070768
    if (ctx->r1 != 0) {
        // 0x8007074C: nop
    
            goto L_80070768;
    }
    // 0x8007074C: nop

    // 0x80070750: lbu         $t2, 0x1E($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X1E);
    // 0x80070754: nop

    // 0x80070758: sb          $t2, 0x1C($t9)
    MEM_B(0X1C, ctx->r25) = ctx->r10;
    // 0x8007075C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80070760: b           L_80070784
    // 0x80070764: sb          $zero, 0x1D($t6)
    MEM_B(0X1D, ctx->r14) = 0;
        goto L_80070784;
    // 0x80070764: sb          $zero, 0x1D($t6)
    MEM_B(0X1D, ctx->r14) = 0;
L_80070768:
    // 0x80070768: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007076C: nop

    // 0x80070770: lbu         $t1, 0x1C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1C);
    // 0x80070774: lb          $t4, 0x1D($t0)
    ctx->r12 = MEM_B(ctx->r8, 0X1D);
    // 0x80070778: nop

    // 0x8007077C: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80070780: sb          $t5, 0x1C($t0)
    MEM_B(0X1C, ctx->r8) = ctx->r13;
L_80070784:
    // 0x80070784: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80070788: nop

    // 0x8007078C: lh          $t3, 0x22($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X22);
    // 0x80070790: nop

    // 0x80070794: beq         $t3, $zero, L_80070804
    if (ctx->r11 == 0) {
        // 0x80070798: nop
    
            goto L_80070804;
    }
    // 0x80070798: nop

    // 0x8007079C: lh          $t7, 0x20($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X20);
    // 0x800707A0: nop

    // 0x800707A4: addu        $t2, $t7, $t3
    ctx->r10 = ADD32(ctx->r15, ctx->r11);
    // 0x800707A8: sh          $t2, 0x20($t8)
    MEM_H(0X20, ctx->r24) = ctx->r10;
    // 0x800707AC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800707B0: nop

    // 0x800707B4: lh          $t6, 0x20($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X20);
    // 0x800707B8: nop

    // 0x800707BC: bgez        $t6, L_800707D4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800707C0: nop
    
            goto L_800707D4;
    }
    // 0x800707C0: nop

    // 0x800707C4: sh          $zero, 0x20($t9)
    MEM_H(0X20, ctx->r25) = 0;
    // 0x800707C8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800707CC: nop

    // 0x800707D0: sh          $zero, 0x22($t1)
    MEM_H(0X22, ctx->r9) = 0;
L_800707D4:
    // 0x800707D4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800707D8: nop

    // 0x800707DC: lh          $t5, 0x20($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X20);
    // 0x800707E0: nop

    // 0x800707E4: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x800707E8: bne         $at, $zero, L_80070804
    if (ctx->r1 != 0) {
        // 0x800707EC: nop
    
            goto L_80070804;
    }
    // 0x800707EC: nop

    // 0x800707F0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800707F4: sh          $t0, 0x20($t4)
    MEM_H(0X20, ctx->r12) = ctx->r8;
    // 0x800707F8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800707FC: nop

    // 0x80070800: sh          $zero, 0x22($t7)
    MEM_H(0X22, ctx->r15) = 0;
L_80070804:
    // 0x80070804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80070808: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007080C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80070810: jr          $ra
    // 0x80070814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80070814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Minos_Mino_SetPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070820: lwl         $at, 0x0($a1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r5, 0X0);
    // 0x80070824: lwr         $at, 0x3($a1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r5, 0X3);
    // 0x80070828: nop

    // 0x8007082C: swl         $at, 0x4($a0)
    do_swl(rdram, 0X4, ctx->r4, ctx->r1);
    // 0x80070830: swr         $at, 0x7($a0)
    do_swr(rdram, 0X7, ctx->r4, ctx->r1);
    // 0x80070834: lwl         $t8, 0x4($a1)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r5, 0X4);
    // 0x80070838: lwr         $t8, 0x7($a1)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r5, 0X7);
    // 0x8007083C: nop

    // 0x80070840: swl         $t8, 0x8($a0)
    do_swl(rdram, 0X8, ctx->r4, ctx->r24);
    // 0x80070844: swr         $t8, 0xB($a0)
    do_swr(rdram, 0XB, ctx->r4, ctx->r24);
    // 0x80070848: lwl         $at, 0x8($a1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r5, 0X8);
    // 0x8007084C: lwr         $at, 0xB($a1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r5, 0XB);
    // 0x80070850: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80070854: swl         $at, 0xC($a0)
    do_swl(rdram, 0XC, ctx->r4, ctx->r1);
    // 0x80070858: jr          $ra
    // 0x8007085C: swr         $at, 0xF($a0)
    do_swr(rdram, 0XF, ctx->r4, ctx->r1);
    return;
    // 0x8007085C: swr         $at, 0xF($a0)
    do_swr(rdram, 0XF, ctx->r4, ctx->r1);
;}

RECOMP_FUNC void Minos_Mino_StartSlide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070860: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80070864: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x80070868: lh          $t1, 0x6($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X6);
    // 0x8007086C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80070870: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x80070874: lh          $t5, 0x8($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X8);
    // 0x80070878: bne         $a2, $zero, L_80070884
    if (ctx->r6 != 0) {
        // 0x8007087C: nop
    
            goto L_80070884;
    }
    // 0x8007087C: nop

    // 0x80070880: break       7
    do_break(2147944576);
L_80070884:
    // 0x80070884: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80070888: bne         $a2, $at, L_8007089C
    if (ctx->r6 != ctx->r1) {
        // 0x8007088C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007089C;
    }
    // 0x8007088C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070890: bne         $t8, $at, L_8007089C
    if (ctx->r24 != ctx->r1) {
        // 0x80070894: nop
    
            goto L_8007089C;
    }
    // 0x80070894: nop

    // 0x80070898: break       6
    do_break(2147944600);
L_8007089C:
    // 0x8007089C: mflo        $t9
    ctx->r25 = lo;
    // 0x800708A0: sh          $t9, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r25;
    // 0x800708A4: lh          $t0, 0x2($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X2);
    // 0x800708A8: lh          $t9, 0xA($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XA);
    // 0x800708AC: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x800708B0: div         $zero, $t2, $a2
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r6)));
    // 0x800708B4: bne         $a2, $zero, L_800708C0
    if (ctx->r6 != 0) {
        // 0x800708B8: nop
    
            goto L_800708C0;
    }
    // 0x800708B8: nop

    // 0x800708BC: break       7
    do_break(2147944636);
L_800708C0:
    // 0x800708C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800708C4: bne         $a2, $at, L_800708D8
    if (ctx->r6 != ctx->r1) {
        // 0x800708C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800708D8;
    }
    // 0x800708C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800708CC: bne         $t2, $at, L_800708D8
    if (ctx->r10 != ctx->r1) {
        // 0x800708D0: nop
    
            goto L_800708D8;
    }
    // 0x800708D0: nop

    // 0x800708D4: break       6
    do_break(2147944660);
L_800708D8:
    // 0x800708D8: mflo        $t3
    ctx->r11 = lo;
    // 0x800708DC: sh          $t3, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r11;
    // 0x800708E0: lh          $t4, 0x4($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X4);
    // 0x800708E4: lh          $t3, 0xC($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XC);
    // 0x800708E8: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800708EC: div         $zero, $t6, $a2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r6)));
    // 0x800708F0: bne         $a2, $zero, L_800708FC
    if (ctx->r6 != 0) {
        // 0x800708F4: nop
    
            goto L_800708FC;
    }
    // 0x800708F4: nop

    // 0x800708F8: break       7
    do_break(2147944696);
L_800708FC:
    // 0x800708FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80070900: bne         $a2, $at, L_80070914
    if (ctx->r6 != ctx->r1) {
        // 0x80070904: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80070914;
    }
    // 0x80070904: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070908: bne         $t6, $at, L_80070914
    if (ctx->r14 != ctx->r1) {
        // 0x8007090C: nop
    
            goto L_80070914;
    }
    // 0x8007090C: nop

    // 0x80070910: break       6
    do_break(2147944720);
L_80070914:
    // 0x80070914: mflo        $t7
    ctx->r15 = lo;
    // 0x80070918: sh          $t7, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r15;
    // 0x8007091C: lh          $t8, 0x6($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X6);
    // 0x80070920: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x80070924: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80070928: div         $zero, $t0, $a2
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r6)));
    // 0x8007092C: bne         $a2, $zero, L_80070938
    if (ctx->r6 != 0) {
        // 0x80070930: nop
    
            goto L_80070938;
    }
    // 0x80070930: nop

    // 0x80070934: break       7
    do_break(2147944756);
L_80070938:
    // 0x80070938: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007093C: bne         $a2, $at, L_80070950
    if (ctx->r6 != ctx->r1) {
        // 0x80070940: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80070950;
    }
    // 0x80070940: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070944: bne         $t0, $at, L_80070950
    if (ctx->r8 != ctx->r1) {
        // 0x80070948: nop
    
            goto L_80070950;
    }
    // 0x80070948: nop

    // 0x8007094C: break       6
    do_break(2147944780);
L_80070950:
    // 0x80070950: mflo        $t1
    ctx->r9 = lo;
    // 0x80070954: sh          $t1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r9;
    // 0x80070958: lh          $t2, 0x8($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X8);
    // 0x8007095C: nop

    // 0x80070960: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80070964: div         $zero, $t4, $a2
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r6)));
    // 0x80070968: bne         $a2, $zero, L_80070974
    if (ctx->r6 != 0) {
        // 0x8007096C: nop
    
            goto L_80070974;
    }
    // 0x8007096C: nop

    // 0x80070970: break       7
    do_break(2147944816);
L_80070974:
    // 0x80070974: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80070978: bne         $a2, $at, L_8007098C
    if (ctx->r6 != ctx->r1) {
        // 0x8007097C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007098C;
    }
    // 0x8007097C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070980: bne         $t4, $at, L_8007098C
    if (ctx->r12 != ctx->r1) {
        // 0x80070984: nop
    
            goto L_8007098C;
    }
    // 0x80070984: nop

    // 0x80070988: break       6
    do_break(2147944840);
L_8007098C:
    // 0x8007098C: mflo        $t5
    ctx->r13 = lo;
    // 0x80070990: sh          $t5, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r13;
    // 0x80070994: lh          $t6, 0xA($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XA);
    // 0x80070998: sb          $a2, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r6;
    // 0x8007099C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800709A0: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x800709A4: bne         $a2, $zero, L_800709B0
    if (ctx->r6 != 0) {
        // 0x800709A8: nop
    
            goto L_800709B0;
    }
    // 0x800709A8: nop

    // 0x800709AC: break       7
    do_break(2147944876);
L_800709B0:
    // 0x800709B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800709B4: bne         $a2, $at, L_800709C8
    if (ctx->r6 != ctx->r1) {
        // 0x800709B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800709C8;
    }
    // 0x800709B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800709BC: bne         $t8, $at, L_800709C8
    if (ctx->r24 != ctx->r1) {
        // 0x800709C0: nop
    
            goto L_800709C8;
    }
    // 0x800709C0: nop

    // 0x800709C4: break       6
    do_break(2147944900);
L_800709C8:
    // 0x800709C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800709CC: sh          $t9, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r25;
    // 0x800709D0: jr          $ra
    // 0x800709D4: nop

    return;
    // 0x800709D4: nop

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

RECOMP_FUNC void Minos_CopyGrid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2F30: addiu       $t0, $a1, 0x80
    ctx->r8 = ADD32(ctx->r5, 0X80);
L_800A2F34:
    // 0x800A2F34: lh          $t1, 0x0($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X0);
    // 0x800A2F38: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800A2F3C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800A2F40: bne         $a1, $t0, L_800A2F34
    if (ctx->r5 != ctx->r8) {
        // 0x800A2F44: sh          $t1, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r9;
            goto L_800A2F34;
    }
    // 0x800A2F44: sh          $t1, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r9;
    // 0x800A2F48: jr          $ra
    // 0x800A2F4C: nop

    return;
    // 0x800A2F4C: nop

;}

RECOMP_FUNC void Minos_StepBytesToward(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2F50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A2F54: addiu       $t0, $a1, 0x80
    ctx->r8 = ADD32(ctx->r5, 0X80);
L_800A2F58:
    // 0x800A2F58: lb          $t2, 0x0($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X0);
L_800A2F5C:
    // 0x800A2F5C: lb          $t1, 0x0($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X0);
    // 0x800A2F60: addi        $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A2F64: beq         $t1, $t2, L_800A2FA0
    if (ctx->r9 == ctx->r10) {
        // 0x800A2F68: addi        $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800A2FA0;
    }
    // 0x800A2F68: addi        $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A2F6C: slt         $t3, $t1, $t2
    ctx->r11 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A2F70: bne         $t3, $zero, L_800A2F8C
    if (ctx->r11 != 0) {
        // 0x800A2F74: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800A2F8C;
    }
    // 0x800A2F74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A2F78: addi        $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800A2F7C: bnel        $a1, $t0, L_800A2F58
    if (ctx->r5 != ctx->r8) {
        // 0x800A2F80: sb          $t1, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r9;
            goto L_800A2F58;
    }
    goto skip_0;
    // 0x800A2F80: sb          $t1, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r9;
    skip_0:
    // 0x800A2F84: jr          $ra
    // 0x800A2F88: sb          $t1, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r9;
    return;
    // 0x800A2F88: sb          $t1, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r9;
L_800A2F8C:
    // 0x800A2F8C: addi        $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800A2F90: bnel        $a1, $t0, L_800A2F58
    if (ctx->r5 != ctx->r8) {
        // 0x800A2F94: sb          $t1, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r9;
            goto L_800A2F58;
    }
    goto skip_1;
    // 0x800A2F94: sb          $t1, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r9;
    skip_1:
    // 0x800A2F98: jr          $ra
    // 0x800A2F9C: sb          $t1, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r9;
    return;
    // 0x800A2F9C: sb          $t1, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r9;
L_800A2FA0:
    // 0x800A2FA0: bnel        $a1, $t0, L_800A2F5C
    if (ctx->r5 != ctx->r8) {
        // 0x800A2FA4: lb          $t2, 0x0($a0)
        ctx->r10 = MEM_B(ctx->r4, 0X0);
            goto L_800A2F5C;
    }
    goto skip_2;
    // 0x800A2FA4: lb          $t2, 0x0($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X0);
    skip_2:
    // 0x800A2FA8: jr          $ra
    // 0x800A2FAC: nop

    return;
    // 0x800A2FAC: nop

;}

RECOMP_FUNC void Minos_WarpSampleIndices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2FB0: addi        $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2FB4: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x800A2FB8: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x800A2FBC: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x800A2FC0: sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // 0x800A2FC4: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800A2FC8: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x800A2FCC: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x800A2FD0: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // 0x800A2FD4: lw          $s0, 0x38($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X38);
    // 0x800A2FD8: lw          $s1, 0x3C($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X3C);
    // 0x800A2FDC: lw          $s2, 0x40($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X40);
    // 0x800A2FE0: lw          $s3, 0x44($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X44);
    // 0x800A2FE4: lw          $s4, 0x48($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X48);
    // 0x800A2FE8: lw          $s5, 0x4C($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X4C);
    // 0x800A2FEC: lw          $s6, 0x50($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X50);
    // 0x800A2FF0: lw          $s7, 0x54($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X54);
    // 0x800A2FF4: lw          $a3, 0x18($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X18);
    // 0x800A2FF8: sub         $s4, $s4, $s0
    ctx->r20 = SUB32(ctx->r20, ctx->r16);
    // 0x800A2FFC: sub         $s5, $s5, $s1
    ctx->r21 = SUB32(ctx->r21, ctx->r17);
    // 0x800A3000: sub         $s6, $s6, $s2
    ctx->r22 = SUB32(ctx->r22, ctx->r18);
    // 0x800A3004: sub         $s7, $s7, $s3
    ctx->r23 = SUB32(ctx->r23, ctx->r19);
    // 0x800A3008: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800A300C: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x800A3010: sra         $s4, $s4, 3
    ctx->r20 = S32(SIGNED(ctx->r20) >> 3);
    // 0x800A3014: sra         $s5, $s5, 3
    ctx->r21 = S32(SIGNED(ctx->r21) >> 3);
    // 0x800A3018: sra         $s6, $s6, 3
    ctx->r22 = S32(SIGNED(ctx->r22) >> 3);
    // 0x800A301C: sra         $s7, $s7, 3
    ctx->r23 = S32(SIGNED(ctx->r23) >> 3);
    // 0x800A3020: addiu       $t0, $a3, 0x40
    ctx->r8 = ADD32(ctx->r7, 0X40);
L_800A3024:
    // 0x800A3024: sub         $t4, $s2, $s0
    ctx->r12 = SUB32(ctx->r18, ctx->r16);
    // 0x800A3028: sub         $t5, $s3, $s1
    ctx->r13 = SUB32(ctx->r19, ctx->r17);
    // 0x800A302C: addiu       $t1, $a3, 0x8
    ctx->r9 = ADD32(ctx->r7, 0X8);
    // 0x800A3030: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800A3034: or          $t3, $s1, $zero
    ctx->r11 = ctx->r17 | 0;
    // 0x800A3038: sra         $t4, $t4, 3
    ctx->r12 = S32(SIGNED(ctx->r12) >> 3);
    // 0x800A303C: sra         $t5, $t5, 3
    ctx->r13 = S32(SIGNED(ctx->r13) >> 3);
L_800A3040:
    // 0x800A3040: lb          $t8, 0x1($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X1);
    // 0x800A3044: lb          $t9, 0x0($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X0);
    // 0x800A3048: sra         $t6, $t2, 16
    ctx->r14 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800A304C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A3050: add         $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x800A3054: sra         $t7, $t3, 16
    ctx->r15 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800A3058: sra         $t8, $t6, 8
    ctx->r24 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800A305C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A3060: bne         $t8, $zero, L_800A3094
    if (ctx->r24 != 0) {
        // 0x800A3064: add         $t7, $t7, $t9
        ctx->r15 = ADD32(ctx->r15, ctx->r25);
            goto L_800A3094;
    }
    // 0x800A3064: add         $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800A3068: sra         $t9, $t7, 8
    ctx->r25 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800A306C: bne         $t9, $zero, L_800A3094
    if (ctx->r25 != 0) {
        // 0x800A3070: nop
    
            goto L_800A3094;
    }
    // 0x800A3070: nop

    // 0x800A3074: sra         $t6, $t6, 1
    ctx->r14 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800A3078: sra         $t7, $t7, 1
    ctx->r15 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800A307C: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x800A3080: or          $t6, $t6, $t7
    ctx->r14 = ctx->r14 | ctx->r15;
    // 0x800A3084: add         $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x800A3088: lb          $t9, 0x0($t6)
    ctx->r25 = MEM_B(ctx->r14, 0X0);
    // 0x800A308C: b           L_800A3098
    // 0x800A3090: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
        goto L_800A3098;
    // 0x800A3090: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
L_800A3094:
    // 0x800A3094: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
L_800A3098:
    // 0x800A3098: add         $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x800A309C: add         $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800A30A0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800A30A4: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800A30A8: bnel        $t1, $a3, L_800A3040
    if (ctx->r9 != ctx->r7) {
        // 0x800A30AC: nop
    
            goto L_800A3040;
    }
    goto skip_0;
    // 0x800A30AC: nop

    skip_0:
    // 0x800A30B0: add         $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
    // 0x800A30B4: add         $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
    // 0x800A30B8: add         $s2, $s2, $s6
    ctx->r18 = ADD32(ctx->r18, ctx->r22);
    // 0x800A30BC: add         $s3, $s3, $s7
    ctx->r19 = ADD32(ctx->r19, ctx->r23);
    // 0x800A30C0: bnel        $t0, $a3, L_800A3024
    if (ctx->r8 != ctx->r7) {
        // 0x800A30C4: nop
    
            goto L_800A3024;
    }
    goto skip_1;
    // 0x800A30C4: nop

    skip_1:
    // 0x800A30C8: lw          $s7, 0x1C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X1C);
    // 0x800A30CC: lw          $s6, 0x18($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X18);
    // 0x800A30D0: lw          $s5, 0x14($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X14);
    // 0x800A30D4: lw          $s4, 0x10($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X10);
    // 0x800A30D8: lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC);
    // 0x800A30DC: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x800A30E0: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x800A30E4: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x800A30E8: jr          $ra
    // 0x800A30EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A30EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void Minos_WarpSamplePixels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A30F0: addi        $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A30F4: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x800A30F8: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x800A30FC: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x800A3100: sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // 0x800A3104: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800A3108: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x800A310C: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x800A3110: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // 0x800A3114: lw          $s0, 0x38($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X38);
    // 0x800A3118: lw          $s4, 0x48($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X48);
    // 0x800A311C: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x800A3120: lw          $s1, 0x3C($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X3C);
    // 0x800A3124: sub         $s4, $s4, $s0
    ctx->r20 = SUB32(ctx->r20, ctx->r16);
    // 0x800A3128: mult        $s4, $t0
    result = S64(S32(ctx->r20)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A312C: lw          $s5, 0x4C($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X4C);
    // 0x800A3130: lw          $s2, 0x40($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X40);
    // 0x800A3134: lw          $s6, 0x50($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X50);
    // 0x800A3138: sub         $s5, $s5, $s1
    ctx->r21 = SUB32(ctx->r21, ctx->r17);
    // 0x800A313C: lw          $s3, 0x44($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X44);
    // 0x800A3140: sub         $s6, $s6, $s2
    ctx->r22 = SUB32(ctx->r22, ctx->r18);
    // 0x800A3144: lw          $s7, 0x54($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X54);
    // 0x800A3148: lw          $a1, 0x1C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1C);
    // 0x800A314C: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x800A3150: mfhi        $s4
    ctx->r20 = hi;
    // 0x800A3154: sub         $s7, $s7, $s3
    ctx->r23 = SUB32(ctx->r23, ctx->r19);
    // 0x800A3158: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x800A315C: mult        $s5, $t0
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A3160: mfhi        $s5
    ctx->r21 = hi;
    // 0x800A3164: nop

    // 0x800A3168: nop

    // 0x800A316C: mult        $s6, $t0
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A3170: mfhi        $s6
    ctx->r22 = hi;
    // 0x800A3174: nop

    // 0x800A3178: nop

    // 0x800A317C: mult        $s7, $t0
    result = S64(S32(ctx->r23)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A3180: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x800A3184: add         $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x800A3188: mfhi        $s7
    ctx->r23 = hi;
    // 0x800A318C: nop

    // 0x800A3190: nop

L_800A3194:
    // 0x800A3194: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x800A3198: sub         $t4, $s2, $s0
    ctx->r12 = SUB32(ctx->r18, ctx->r16);
    // 0x800A319C: sub         $t5, $s3, $s1
    ctx->r13 = SUB32(ctx->r19, ctx->r17);
    // 0x800A31A0: mult        $t4, $v0
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A31A4: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x800A31A8: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800A31AC: or          $t3, $s1, $zero
    ctx->r11 = ctx->r17 | 0;
    // 0x800A31B0: add         $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x800A31B4: mfhi        $t4
    ctx->r12 = hi;
    // 0x800A31B8: nop

    // 0x800A31BC: nop

    // 0x800A31C0: mult        $t5, $v0
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A31C4: mfhi        $t5
    ctx->r13 = hi;
    // 0x800A31C8: nop

    // 0x800A31CC: nop

L_800A31D0:
    // 0x800A31D0: lb          $t8, 0x1($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1);
    // 0x800A31D4: sra         $t6, $t2, 16
    ctx->r14 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800A31D8: lb          $t9, 0x0($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X0);
    // 0x800A31DC: add         $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x800A31E0: sra         $t7, $t3, 16
    ctx->r15 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800A31E4: sra         $at, $t6, 8
    ctx->r1 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800A31E8: bne         $at, $zero, L_800A321C
    if (ctx->r1 != 0) {
        // 0x800A31EC: add         $t7, $t7, $t9
        ctx->r15 = ADD32(ctx->r15, ctx->r25);
            goto L_800A321C;
    }
    // 0x800A31EC: add         $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800A31F0: sra         $at, $t7, 8
    ctx->r1 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800A31F4: bne         $at, $zero, L_800A321C
    if (ctx->r1 != 0) {
        // 0x800A31F8: nop
    
            goto L_800A321C;
    }
    // 0x800A31F8: nop

    // 0x800A31FC: lw          $at, 0x0($a0)
    ctx->r1 = MEM_W(ctx->r4, 0X0);
    // 0x800A3200: srl         $t6, $t6, 1
    ctx->r14 = S32(U32(ctx->r14) >> 1);
    // 0x800A3204: srl         $t7, $t7, 1
    ctx->r15 = S32(U32(ctx->r15) >> 1);
    // 0x800A3208: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x800A320C: or          $t6, $t6, $t7
    ctx->r14 = ctx->r14 | ctx->r15;
    // 0x800A3210: add         $t6, $t6, $at
    ctx->r14 = ADD32(ctx->r14, ctx->r1);
    // 0x800A3214: b           L_800A3224
    // 0x800A3218: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
        goto L_800A3224;
    // 0x800A3218: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
L_800A321C:
    // 0x800A321C: lw          $at, 0x0($a0)
    ctx->r1 = MEM_W(ctx->r4, 0X0);
    // 0x800A3220: lbu         $t9, 0x0($at)
    ctx->r25 = MEM_BU(ctx->r1, 0X0);
L_800A3224:
    // 0x800A3224: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800A3228: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800A322C: sll         $t9, $t9, 8
    ctx->r25 = S32(ctx->r25 << 8);
    // 0x800A3230: or          $t9, $t9, $t8
    ctx->r25 = ctx->r25 | ctx->r24;
    // 0x800A3234: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800A3238: add         $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800A323C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800A3240: add         $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x800A3244: add         $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800A3248: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A324C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800A3250: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800A3254: sh          $t8, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r24;
    // 0x800A3258: bnel        $t1, $a1, L_800A31D0
    if (ctx->r9 != ctx->r5) {
        // 0x800A325C: nop
    
            goto L_800A31D0;
    }
    goto skip_0;
    // 0x800A325C: nop

    skip_0:
    // 0x800A3260: add         $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
    // 0x800A3264: add         $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
    // 0x800A3268: add         $s2, $s2, $s6
    ctx->r18 = ADD32(ctx->r18, ctx->r22);
    // 0x800A326C: add         $s3, $s3, $s7
    ctx->r19 = ADD32(ctx->r19, ctx->r23);
    // 0x800A3270: bnel        $t0, $a1, L_800A3194
    if (ctx->r8 != ctx->r5) {
        // 0x800A3274: nop
    
            goto L_800A3194;
    }
    goto skip_1;
    // 0x800A3274: nop

    skip_1:
    // 0x800A3278: lw          $s7, 0x1C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X1C);
    // 0x800A327C: lw          $s6, 0x18($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X18);
    // 0x800A3280: lw          $s5, 0x14($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X14);
    // 0x800A3284: lw          $s4, 0x10($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X10);
    // 0x800A3288: lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC);
    // 0x800A328C: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x800A3290: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x800A3294: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x800A3298: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A329C: jr          $ra
    // 0x800A32A0: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x800A32A0: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    // 0x800A32A4: nop

    // 0x800A32A8: nop

    // 0x800A32AC: nop

;}

RECOMP_FUNC void func_800A32B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}

RECOMP_FUNC void func_800A32E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}

RECOMP_FUNC void Minos_QueuePush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3300: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x800A3304: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800A3308: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // 0x800A330C: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x800A3310: subu        $t7, $v1, $t6
    ctx->r15 = SUB32(ctx->r3, ctx->r14);
    // 0x800A3314: addiu       $t8, $t7, 0x12C
    ctx->r24 = ADD32(ctx->r15, 0X12C);
    // 0x800A3318: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x800A331C: mfhi        $v0
    ctx->r2 = hi;
    // 0x800A3320: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800A3324: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800A3328: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800A332C: bne         $a2, $zero, L_800A3338
    if (ctx->r6 != 0) {
        // 0x800A3330: nop
    
            goto L_800A3338;
    }
    // 0x800A3330: nop

    // 0x800A3334: break       7
    do_break(2148152116);
L_800A3338:
    // 0x800A3338: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A333C: bne         $a2, $at, L_800A3350
    if (ctx->r6 != ctx->r1) {
        // 0x800A3340: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A3350;
    }
    // 0x800A3340: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A3344: bne         $t8, $at, L_800A3350
    if (ctx->r24 != ctx->r1) {
        // 0x800A3348: nop
    
            goto L_800A3350;
    }
    // 0x800A3348: nop

    // 0x800A334C: break       6
    do_break(2148152140);
L_800A3350:
    // 0x800A3350: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800A3354: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A3358: ldc1        $f4, 0x908($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X908);
    // 0x800A335C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800A3360: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x800A3364: nop

    // 0x800A3368: bc1f        L_800A337C
    if (!c1cs) {
        // 0x800A336C: nop
    
            goto L_800A337C;
    }
    // 0x800A336C: nop

    // 0x800A3370: slti        $at, $v0, 0x12B
    ctx->r1 = SIGNED(ctx->r2) < 0X12B ? 1 : 0;
    // 0x800A3374: beq         $at, $zero, L_800A33DC
    if (ctx->r1 == 0) {
        // 0x800A3378: nop
    
            goto L_800A33DC;
    }
    // 0x800A3378: nop

L_800A337C:
    // 0x800A337C: div         $zero, $t4, $a2
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r6)));
    // 0x800A3380: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x800A3384: mfhi        $t5
    ctx->r13 = hi;
    // 0x800A3388: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800A338C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800A3390: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
    // 0x800A3394: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x800A3398: lhu         $t6, 0x0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X0);
    // 0x800A339C: sll         $t1, $v1, 3
    ctx->r9 = S32(ctx->r3 << 3);
    // 0x800A33A0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800A33A4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A33A8: lb          $t7, 0x2($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X2);
    // 0x800A33AC: bne         $a2, $zero, L_800A33B8
    if (ctx->r6 != 0) {
        // 0x800A33B0: nop
    
            goto L_800A33B8;
    }
    // 0x800A33B0: nop

    // 0x800A33B4: break       7
    do_break(2148152244);
L_800A33B8:
    // 0x800A33B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A33BC: bne         $a2, $at, L_800A33D0
    if (ctx->r6 != ctx->r1) {
        // 0x800A33C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A33D0;
    }
    // 0x800A33C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A33C4: bne         $t4, $at, L_800A33D0
    if (ctx->r12 != ctx->r1) {
        // 0x800A33C8: nop
    
            goto L_800A33D0;
    }
    // 0x800A33C8: nop

    // 0x800A33CC: break       6
    do_break(2148152268);
L_800A33D0:
    // 0x800A33D0: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x800A33D4: lb          $t8, 0x3($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X3);
    // 0x800A33D8: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
L_800A33DC:
    // 0x800A33DC: jr          $ra
    // 0x800A33E0: nop

    return;
    // 0x800A33E0: nop

;}

RECOMP_FUNC void Minos_QueuePop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A33E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A33E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A33EC: jal         0x800A3534
    // 0x800A33F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    Minos_QueueCount(rdram, ctx);
        goto after_0;
    // 0x800A33F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A33F4: blez        $v0, L_800A3450
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A33F8: lw          $a2, 0x30($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X30);
            goto L_800A3450;
    }
    // 0x800A33F8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800A33FC: lh          $v1, 0x2($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X2);
    // 0x800A3400: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    // 0x800A3404: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x800A3408: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x800A340C: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x800A3410: lw          $v0, 0x10($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X10);
    // 0x800A3414: mfhi        $t0
    ctx->r8 = hi;
    // 0x800A3418: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800A341C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800A3420: sw          $t8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r24;
    // 0x800A3424: sh          $t0, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r8;
    // 0x800A3428: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800A342C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800A3430: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800A3434: sh          $t1, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r9;
    // 0x800A3438: lh          $t2, 0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4);
    // 0x800A343C: sb          $t2, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r10;
    // 0x800A3440: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x800A3444: sb          $t3, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r11;
    // 0x800A3448: jal         0x800B1770
    // 0x800A344C: lw          $a0, 0x14($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X14);
    Minos_UpdateCellHistory(rdram, ctx);
        goto after_1;
    // 0x800A344C: lw          $a0, 0x14($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X14);
    after_1:
L_800A3450:
    // 0x800A3450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3454: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A3458: jr          $ra
    // 0x800A345C: nop

    return;
    // 0x800A345C: nop

;}

RECOMP_FUNC void Minos_Reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3468: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A346C: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x800A3470: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x800A3474: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800A3478: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800A347C: lh          $a1, 0x4($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X4);
    // 0x800A3480: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    // 0x800A3484: jal         0x800B7450
    // 0x800A3488: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x800A3488: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A348C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A3490: jal         0x800B1A7C
    // 0x800A3494: lw          $a0, 0x14($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X14);
    Minos_ResetQueueState(rdram, ctx);
        goto after_1;
    // 0x800A3494: lw          $a0, 0x14($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X14);
    after_1:
    // 0x800A3498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A349C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A34A0: jr          $ra
    // 0x800A34A4: nop

    return;
    // 0x800A34A4: nop

;}

RECOMP_FUNC void Minos_QueueInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A34A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A34AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A34B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A34B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A34B8: jal         0x800B7450
    // 0x800A34BC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x800A34BC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_0:
    // 0x800A34C0: jal         0x8007E03C
    // 0x800A34C4: addiu       $a0, $zero, 0x960
    ctx->r4 = ADD32(0, 0X960);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800A34C4: addiu       $a0, $zero, 0x960
    ctx->r4 = ADD32(0, 0X960);
    after_1:
    // 0x800A34C8: beq         $v0, $zero, L_800A3518
    if (ctx->r2 == 0) {
        // 0x800A34CC: sw          $v0, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r2;
            goto L_800A3518;
    }
    // 0x800A34CC: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x800A34D0: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800A34D4: sh          $t6, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r14;
    // 0x800A34D8: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x800A34DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A34E0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800A34E4: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x800A34E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A34EC: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800A34F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A34F4: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800A34F8: jal         0x800B7450
    // 0x800A34FC: sll         $a1, $t7, 2
    ctx->r5 = S32(ctx->r15 << 2);
    bzero_recomp(rdram, ctx);
        goto after_2;
    // 0x800A34FC: sll         $a1, $t7, 2
    ctx->r5 = S32(ctx->r15 << 2);
    after_2:
    // 0x800A3500: jal         0x8007E03C
    // 0x800A3504: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    n64HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x800A3504: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_3:
    // 0x800A3508: beq         $v0, $zero, L_800A3518
    if (ctx->r2 == 0) {
        // 0x800A350C: sw          $v0, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r2;
            goto L_800A3518;
    }
    // 0x800A350C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800A3510: jal         0x800B1A7C
    // 0x800A3514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    Minos_ResetQueueState(rdram, ctx);
        goto after_4;
    // 0x800A3514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
L_800A3518:
    // 0x800A3518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A351C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A3520: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A3524: jr          $ra
    // 0x800A3528: nop

    return;
    // 0x800A3528: nop

;}

RECOMP_FUNC void Minos_QueueGetRng(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A352C: jr          $ra
    // 0x800A3530: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    return;
    // 0x800A3530: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
;}

RECOMP_FUNC void Minos_QueueCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3534: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800A3538: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800A353C: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x800A3540: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800A3544: jr          $ra
    // 0x800A3548: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    return;
    // 0x800A3548: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800A354C: nop

;}

RECOMP_FUNC void Minos_UpdateCellHistory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1770: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800B1774: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B1778: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B177C: andi        $t0, $v0, 0x800
    ctx->r8 = ctx->r2 & 0X800;
    // 0x800B1780: xor         $t8, $t6, $at
    ctx->r24 = ctx->r14 ^ ctx->r1;
    // 0x800B1784: and         $t9, $t8, $v0
    ctx->r25 = ctx->r24 & ctx->r2;
    // 0x800B1788: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x800B178C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800B1790: beq         $t0, $zero, L_800B17A8
    if (ctx->r8 == 0) {
        // 0x800B1794: sw          $t6, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r14;
            goto L_800B17A8;
    }
    // 0x800B1794: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800B1798: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800B179C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B17A0: b           L_800B17AC
    // 0x800B17A4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
        goto L_800B17AC;
    // 0x800B17A4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
L_800B17A8:
    // 0x800B17A8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
L_800B17AC:
    // 0x800B17AC: andi        $t3, $v0, 0x400
    ctx->r11 = ctx->r2 & 0X400;
    // 0x800B17B0: beq         $t3, $zero, L_800B17C8
    if (ctx->r11 == 0) {
        // 0x800B17B4: andi        $t6, $v0, 0x100
        ctx->r14 = ctx->r2 & 0X100;
            goto L_800B17C8;
    }
    // 0x800B17B4: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x800B17B8: lw          $t4, 0x10($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X10);
    // 0x800B17BC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B17C0: b           L_800B17CC
    // 0x800B17C4: sw          $t5, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r13;
        goto L_800B17CC;
    // 0x800B17C4: sw          $t5, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r13;
L_800B17C8:
    // 0x800B17C8: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
L_800B17CC:
    // 0x800B17CC: beq         $t6, $zero, L_800B17E4
    if (ctx->r14 == 0) {
        // 0x800B17D0: andi        $t9, $v0, 0x200
        ctx->r25 = ctx->r2 & 0X200;
            goto L_800B17E4;
    }
    // 0x800B17D0: andi        $t9, $v0, 0x200
    ctx->r25 = ctx->r2 & 0X200;
    // 0x800B17D4: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x800B17D8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B17DC: b           L_800B17E8
    // 0x800B17E0: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
        goto L_800B17E8;
    // 0x800B17E0: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
L_800B17E4:
    // 0x800B17E4: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
L_800B17E8:
    // 0x800B17E8: beq         $t9, $zero, L_800B1800
    if (ctx->r25 == 0) {
        // 0x800B17EC: andi        $t2, $v0, 0x8
        ctx->r10 = ctx->r2 & 0X8;
            goto L_800B1800;
    }
    // 0x800B17EC: andi        $t2, $v0, 0x8
    ctx->r10 = ctx->r2 & 0X8;
    // 0x800B17F0: lw          $t0, 0x18($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X18);
    // 0x800B17F4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B17F8: b           L_800B1804
    // 0x800B17FC: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
        goto L_800B1804;
    // 0x800B17FC: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
L_800B1800:
    // 0x800B1800: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
L_800B1804:
    // 0x800B1804: beq         $t2, $zero, L_800B181C
    if (ctx->r10 == 0) {
        // 0x800B1808: andi        $t5, $v0, 0x4
        ctx->r13 = ctx->r2 & 0X4;
            goto L_800B181C;
    }
    // 0x800B1808: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x800B180C: lw          $t3, 0x1C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1C);
    // 0x800B1810: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B1814: b           L_800B1820
    // 0x800B1818: sw          $t4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r12;
        goto L_800B1820;
    // 0x800B1818: sw          $t4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r12;
L_800B181C:
    // 0x800B181C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
L_800B1820:
    // 0x800B1820: beq         $t5, $zero, L_800B1838
    if (ctx->r13 == 0) {
        // 0x800B1824: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_800B1838;
    }
    // 0x800B1824: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800B1828: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x800B182C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B1830: b           L_800B183C
    // 0x800B1834: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
        goto L_800B183C;
    // 0x800B1834: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
L_800B1838:
    // 0x800B1838: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
L_800B183C:
    // 0x800B183C: beq         $t8, $zero, L_800B1854
    if (ctx->r24 == 0) {
        // 0x800B1840: andi        $t1, $v0, 0x2
        ctx->r9 = ctx->r2 & 0X2;
            goto L_800B1854;
    }
    // 0x800B1840: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    // 0x800B1844: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x800B1848: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B184C: b           L_800B1858
    // 0x800B1850: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
        goto L_800B1858;
    // 0x800B1850: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
L_800B1854:
    // 0x800B1854: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
L_800B1858:
    // 0x800B1858: beq         $t1, $zero, L_800B1870
    if (ctx->r9 == 0) {
        // 0x800B185C: andi        $t4, $v0, 0x20
        ctx->r12 = ctx->r2 & 0X20;
            goto L_800B1870;
    }
    // 0x800B185C: andi        $t4, $v0, 0x20
    ctx->r12 = ctx->r2 & 0X20;
    // 0x800B1860: lw          $t2, 0x28($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X28);
    // 0x800B1864: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B1868: b           L_800B1874
    // 0x800B186C: sw          $t3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r11;
        goto L_800B1874;
    // 0x800B186C: sw          $t3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r11;
L_800B1870:
    // 0x800B1870: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
L_800B1874:
    // 0x800B1874: beq         $t4, $zero, L_800B188C
    if (ctx->r12 == 0) {
        // 0x800B1878: andi        $t7, $v0, 0x10
        ctx->r15 = ctx->r2 & 0X10;
            goto L_800B188C;
    }
    // 0x800B1878: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
    // 0x800B187C: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x800B1880: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800B1884: b           L_800B1890
    // 0x800B1888: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
        goto L_800B1890;
    // 0x800B1888: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
L_800B188C:
    // 0x800B188C: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
L_800B1890:
    // 0x800B1890: beq         $t7, $zero, L_800B18A8
    if (ctx->r15 == 0) {
        // 0x800B1894: andi        $t0, $v0, 0x2000
        ctx->r8 = ctx->r2 & 0X2000;
            goto L_800B18A8;
    }
    // 0x800B1894: andi        $t0, $v0, 0x2000
    ctx->r8 = ctx->r2 & 0X2000;
    // 0x800B1898: lw          $t8, 0x30($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X30);
    // 0x800B189C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B18A0: b           L_800B18AC
    // 0x800B18A4: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
        goto L_800B18AC;
    // 0x800B18A4: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
L_800B18A8:
    // 0x800B18A8: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
L_800B18AC:
    // 0x800B18AC: beq         $t0, $zero, L_800B18C4
    if (ctx->r8 == 0) {
        // 0x800B18B0: andi        $t3, $v0, 0x1000
        ctx->r11 = ctx->r2 & 0X1000;
            goto L_800B18C4;
    }
    // 0x800B18B0: andi        $t3, $v0, 0x1000
    ctx->r11 = ctx->r2 & 0X1000;
    // 0x800B18B4: lw          $t1, 0x34($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X34);
    // 0x800B18B8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B18BC: b           L_800B18C8
    // 0x800B18C0: sw          $t2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r10;
        goto L_800B18C8;
    // 0x800B18C0: sw          $t2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r10;
L_800B18C4:
    // 0x800B18C4: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
L_800B18C8:
    // 0x800B18C8: beq         $t3, $zero, L_800B18EC
    if (ctx->r11 == 0) {
        // 0x800B18CC: andi        $t8, $v0, 0x8000
        ctx->r24 = ctx->r2 & 0X8000;
            goto L_800B18EC;
    }
    // 0x800B18CC: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    // 0x800B18D0: lw          $t4, 0x38($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X38);
    // 0x800B18D4: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800B18D8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B18DC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B18E0: sw          $t5, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r13;
    // 0x800B18E4: b           L_800B18F4
    // 0x800B18E8: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
        goto L_800B18F4;
    // 0x800B18E8: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
L_800B18EC:
    // 0x800B18EC: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x800B18F0: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
L_800B18F4:
    // 0x800B18F4: beq         $t8, $zero, L_800B190C
    if (ctx->r24 == 0) {
        // 0x800B18F8: andi        $t1, $v0, 0x4000
        ctx->r9 = ctx->r2 & 0X4000;
            goto L_800B190C;
    }
    // 0x800B18F8: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x800B18FC: lw          $t9, 0x40($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X40);
    // 0x800B1900: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B1904: b           L_800B1910
    // 0x800B1908: sw          $t0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r8;
        goto L_800B1910;
    // 0x800B1908: sw          $t0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r8;
L_800B190C:
    // 0x800B190C: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
L_800B1910:
    // 0x800B1910: beql        $t1, $zero, L_800B192C
    if (ctx->r9 == 0) {
        // 0x800B1914: sw          $zero, 0x44($a0)
        MEM_W(0X44, ctx->r4) = 0;
            goto L_800B192C;
    }
    goto skip_0;
    // 0x800B1914: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
    skip_0:
    // 0x800B1918: lw          $t2, 0x44($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X44);
    // 0x800B191C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B1920: b           L_800B192C
    // 0x800B1924: sw          $t3, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r11;
        goto L_800B192C;
    // 0x800B1924: sw          $t3, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r11;
    // 0x800B1928: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
L_800B192C:
    // 0x800B192C: lb          $t4, 0x2($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X2);
    // 0x800B1930: sh          $t4, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r12;
    // 0x800B1934: lh          $v1, 0x4C($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4C);
    // 0x800B1938: lb          $t5, 0x3($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X3);
    // 0x800B193C: bltz        $v1, L_800B194C
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B1940: sh          $t5, 0x4E($a0)
        MEM_H(0X4E, ctx->r4) = ctx->r13;
            goto L_800B194C;
    }
    // 0x800B1940: sh          $t5, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r13;
    // 0x800B1944: b           L_800B1950
    // 0x800B1948: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B1950;
    // 0x800B1948: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B194C:
    // 0x800B194C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_800B1950:
    // 0x800B1950: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x800B1954: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B1958: beql        $at, $zero, L_800B1968
    if (ctx->r1 == 0) {
        // 0x800B195C: lh          $v1, 0x4E($a0)
        ctx->r3 = MEM_H(ctx->r4, 0X4E);
            goto L_800B1968;
    }
    goto skip_1;
    // 0x800B195C: lh          $v1, 0x4E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4E);
    skip_1:
    // 0x800B1960: sh          $zero, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = 0;
    // 0x800B1964: lh          $v1, 0x4E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4E);
L_800B1968:
    // 0x800B1968: bltz        $v1, L_800B1978
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B196C: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_800B1978;
    }
    // 0x800B196C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x800B1970: b           L_800B1978
    // 0x800B1974: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B1978;
    // 0x800B1974: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B1978:
    // 0x800B1978: lh          $t7, 0x4A($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4A);
    // 0x800B197C: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B1980: beq         $at, $zero, L_800B198C
    if (ctx->r1 == 0) {
        // 0x800B1984: addiu       $v0, $zero, 0x50
        ctx->r2 = ADD32(0, 0X50);
            goto L_800B198C;
    }
    // 0x800B1984: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800B1988: sh          $zero, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = 0;
L_800B198C:
    // 0x800B198C: lh          $t8, 0x4C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4C);
    // 0x800B1990: slti        $at, $t8, 0x51
    ctx->r1 = SIGNED(ctx->r24) < 0X51 ? 1 : 0;
    // 0x800B1994: bnel        $at, $zero, L_800B19A4
    if (ctx->r1 != 0) {
        // 0x800B1998: lh          $t9, 0x4E($a0)
        ctx->r25 = MEM_H(ctx->r4, 0X4E);
            goto L_800B19A4;
    }
    goto skip_2;
    // 0x800B1998: lh          $t9, 0x4E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4E);
    skip_2:
    // 0x800B199C: sh          $v0, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r2;
    // 0x800B19A0: lh          $t9, 0x4E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4E);
L_800B19A4:
    // 0x800B19A4: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800B19A8: slti        $at, $t9, 0x51
    ctx->r1 = SIGNED(ctx->r25) < 0X51 ? 1 : 0;
    // 0x800B19AC: bnel        $at, $zero, L_800B19BC
    if (ctx->r1 != 0) {
        // 0x800B19B0: lh          $t0, 0x4C($a0)
        ctx->r8 = MEM_H(ctx->r4, 0X4C);
            goto L_800B19BC;
    }
    goto skip_3;
    // 0x800B19B0: lh          $t0, 0x4C($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4C);
    skip_3:
    // 0x800B19B4: sh          $v0, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r2;
    // 0x800B19B8: lh          $t0, 0x4C($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4C);
L_800B19BC:
    // 0x800B19BC: slti        $at, $t0, -0x50
    ctx->r1 = SIGNED(ctx->r8) < -0X50 ? 1 : 0;
    // 0x800B19C0: beql        $at, $zero, L_800B19D4
    if (ctx->r1 == 0) {
        // 0x800B19C4: lh          $v1, 0x4E($a0)
        ctx->r3 = MEM_H(ctx->r4, 0X4E);
            goto L_800B19D4;
    }
    goto skip_4;
    // 0x800B19C4: lh          $v1, 0x4E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4E);
    skip_4:
    // 0x800B19C8: addiu       $t1, $zero, -0x50
    ctx->r9 = ADD32(0, -0X50);
    // 0x800B19CC: sh          $t1, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r9;
    // 0x800B19D0: lh          $v1, 0x4E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4E);
L_800B19D4:
    // 0x800B19D4: slti        $at, $v1, -0x50
    ctx->r1 = SIGNED(ctx->r3) < -0X50 ? 1 : 0;
    // 0x800B19D8: beql        $at, $zero, L_800B19F0
    if (ctx->r1 == 0) {
        // 0x800B19DC: lh          $t3, 0x4C($a0)
        ctx->r11 = MEM_H(ctx->r4, 0X4C);
            goto L_800B19F0;
    }
    goto skip_5;
    // 0x800B19DC: lh          $t3, 0x4C($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4C);
    skip_5:
    // 0x800B19E0: addiu       $t2, $zero, -0x50
    ctx->r10 = ADD32(0, -0X50);
    // 0x800B19E4: sh          $t2, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r10;
    // 0x800B19E8: lh          $v1, 0x4E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4E);
    // 0x800B19EC: lh          $t3, 0x4C($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4C);
L_800B19F0:
    // 0x800B19F0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800B19F4: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B19F8: mflo        $t4
    ctx->r12 = lo;
    // 0x800B19FC: nop

    // 0x800B1A00: nop

    // 0x800B1A04: div         $zero, $t4, $v0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r2)));
    // 0x800B1A08: mflo        $t5
    ctx->r13 = lo;
    // 0x800B1A0C: sh          $t5, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r13;
    // 0x800B1A10: bne         $v0, $zero, L_800B1A1C
    if (ctx->r2 != 0) {
        // 0x800B1A14: nop
    
            goto L_800B1A1C;
    }
    // 0x800B1A14: nop

    // 0x800B1A18: break       7
    do_break(2148211224);
L_800B1A1C:
    // 0x800B1A1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1A20: bne         $v0, $at, L_800B1A34
    if (ctx->r2 != ctx->r1) {
        // 0x800B1A24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B1A34;
    }
    // 0x800B1A24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1A28: bne         $t4, $at, L_800B1A34
    if (ctx->r12 != ctx->r1) {
        // 0x800B1A2C: nop
    
            goto L_800B1A34;
    }
    // 0x800B1A2C: nop

    // 0x800B1A30: break       6
    do_break(2148211248);
L_800B1A34:
    // 0x800B1A34: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1A38: mflo        $t6
    ctx->r14 = lo;
    // 0x800B1A3C: nop

    // 0x800B1A40: nop

    // 0x800B1A44: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800B1A48: mflo        $t7
    ctx->r15 = lo;
    // 0x800B1A4C: sh          $t7, 0x52($a0)
    MEM_H(0X52, ctx->r4) = ctx->r15;
    // 0x800B1A50: bne         $v0, $zero, L_800B1A5C
    if (ctx->r2 != 0) {
        // 0x800B1A54: nop
    
            goto L_800B1A5C;
    }
    // 0x800B1A54: nop

    // 0x800B1A58: break       7
    do_break(2148211288);
L_800B1A5C:
    // 0x800B1A5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1A60: bne         $v0, $at, L_800B1A74
    if (ctx->r2 != ctx->r1) {
        // 0x800B1A64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B1A74;
    }
    // 0x800B1A64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1A68: bne         $t6, $at, L_800B1A74
    if (ctx->r14 != ctx->r1) {
        // 0x800B1A6C: nop
    
            goto L_800B1A74;
    }
    // 0x800B1A6C: nop

    // 0x800B1A70: break       6
    do_break(2148211312);
L_800B1A74:
    // 0x800B1A74: jr          $ra
    // 0x800B1A78: nop

    return;
    // 0x800B1A78: nop

;}

RECOMP_FUNC void Minos_ResetQueueState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1A7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B1A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1A84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B1A88: jal         0x800B7450
    // 0x800B1A8C: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x800B1A8C: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    after_0:
    // 0x800B1A90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B1A94: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800B1A98: sh          $v0, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r2;
    // 0x800B1A9C: sh          $v0, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r2;
    // 0x800B1AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B1AA8: jr          $ra
    // 0x800B1AAC: nop

    return;
    // 0x800B1AAC: nop

;}

RECOMP_FUNC void func_800B1AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1AB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B1AB4: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800B1AB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B1ABC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B1AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1AC4: blez        $t6, L_800B1AD8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B1AC8: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800B1AD8;
    }
    // 0x800B1AC8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800B1ACC: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x800B1AD0: bne         $at, $zero, L_800B1AF8
    if (ctx->r1 != 0) {
        // 0x800B1AD4: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800B1AF8;
    }
    // 0x800B1AD4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
L_800B1AD8:
    // 0x800B1AD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B1ADC: jal         0x800B3BFC
    // 0x800B1AE0: addiu       $a0, $a0, 0x1340
    ctx->r4 = ADD32(ctx->r4, 0X1340);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B1AE0: addiu       $a0, $a0, 0x1340
    ctx->r4 = ADD32(ctx->r4, 0X1340);
    after_0:
    // 0x800B1AE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B1AE8: jal         0x800B3BFC
    // 0x800B1AEC: addiu       $a0, $a0, 0x138C
    ctx->r4 = ADD32(ctx->r4, 0X138C);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800B1AEC: addiu       $a0, $a0, 0x138C
    ctx->r4 = ADD32(ctx->r4, 0X138C);
    after_1:
    // 0x800B1AF0: b           L_800B1B58
    // 0x800B1AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B1B58;
    // 0x800B1AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B1AF8:
    // 0x800B1AF8: addiu       $v1, $v1, -0x6E70
    ctx->r3 = ADD32(ctx->r3, -0X6E70);
    // 0x800B1AFC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800B1B00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B1B04: beq         $v0, $at, L_800B1B30
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B08: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_800B1B30;
    }
    // 0x800B1B08: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x800B1B0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1B10: beq         $v0, $at, L_800B1B40
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B14: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B1B40;
    }
    // 0x800B1B14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B1B18: beq         $v0, $at, L_800B1B40
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B1C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800B1B40;
    }
    // 0x800B1B1C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B1B20: beq         $v0, $at, L_800B1B40
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B24: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800B1B40;
    }
    // 0x800B1B24: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B1B28: b           L_800B1B4C
    // 0x800B1B2C: nop

        goto L_800B1B4C;
    // 0x800B1B2C: nop

L_800B1B30:
    // 0x800B1B30: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800B1B34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1B38: b           L_800B1B54
    // 0x800B1B3C: sw          $t7, -0x6E6C($at)
    MEM_W(-0X6E6C, ctx->r1) = ctx->r15;
        goto L_800B1B54;
    // 0x800B1B3C: sw          $t7, -0x6E6C($at)
    MEM_W(-0X6E6C, ctx->r1) = ctx->r15;
L_800B1B40:
    // 0x800B1B40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1B44: b           L_800B1B54
    // 0x800B1B48: sw          $zero, -0x6E6C($at)
    MEM_W(-0X6E6C, ctx->r1) = 0;
        goto L_800B1B54;
    // 0x800B1B48: sw          $zero, -0x6E6C($at)
    MEM_W(-0X6E6C, ctx->r1) = 0;
L_800B1B4C:
    // 0x800B1B4C: jal         0x800B3BFC
    // 0x800B1B50: addiu       $a0, $a0, 0x13A0
    ctx->r4 = ADD32(ctx->r4, 0X13A0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800B1B50: addiu       $a0, $a0, 0x13A0
    ctx->r4 = ADD32(ctx->r4, 0X13A0);
    after_2:
L_800B1B54:
    // 0x800B1B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B1B58:
    // 0x800B1B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B1B5C: jr          $ra
    // 0x800B1B60: nop

    return;
    // 0x800B1B60: nop

;}

RECOMP_FUNC void func_800B1B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1B64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B1B68: lhu         $v0, -0x6E70($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6E70);
    // 0x800B1B6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B1B70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B1B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1B78: beq         $v0, $at, L_800B1BAC
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B7C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800B1BAC;
    }
    // 0x800B1B7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B1B80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1B84: beq         $v0, $at, L_800B1BBC
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B88: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800B1BBC;
    }
    // 0x800B1B88: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B1B8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B1B90: beq         $v0, $at, L_800B1BC8
    if (ctx->r2 == ctx->r1) {
        // 0x800B1B94: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_800B1BC8;
    }
    // 0x800B1B94: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B1B98: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B1B9C: beq         $v0, $at, L_800B1BD4
    if (ctx->r2 == ctx->r1) {
        // 0x800B1BA0: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800B1BD4;
    }
    // 0x800B1BA0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B1BA4: b           L_800B1BE0
    // 0x800B1BA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
        goto L_800B1BE0;
    // 0x800B1BA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
L_800B1BAC:
    // 0x800B1BAC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B1BB0: addiu       $t6, $t6, -0x6CF0
    ctx->r14 = ADD32(ctx->r14, -0X6CF0);
    // 0x800B1BB4: b           L_800B1BE8
    // 0x800B1BB8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
        goto L_800B1BE8;
    // 0x800B1BB8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800B1BBC:
    // 0x800B1BBC: addiu       $t7, $t7, -0x6C70
    ctx->r15 = ADD32(ctx->r15, -0X6C70);
    // 0x800B1BC0: b           L_800B1BE8
    // 0x800B1BC4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
        goto L_800B1BE8;
    // 0x800B1BC4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_800B1BC8:
    // 0x800B1BC8: addiu       $t8, $t8, -0x6BF0
    ctx->r24 = ADD32(ctx->r24, -0X6BF0);
    // 0x800B1BCC: b           L_800B1BE8
    // 0x800B1BD0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
        goto L_800B1BE8;
    // 0x800B1BD0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_800B1BD4:
    // 0x800B1BD4: addiu       $t9, $t9, -0x6B70
    ctx->r25 = ADD32(ctx->r25, -0X6B70);
    // 0x800B1BD8: b           L_800B1BE8
    // 0x800B1BDC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
        goto L_800B1BE8;
    // 0x800B1BDC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_800B1BE0:
    // 0x800B1BE0: jal         0x800B3BFC
    // 0x800B1BE4: addiu       $a0, $a0, 0x13F8
    ctx->r4 = ADD32(ctx->r4, 0X13F8);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B1BE4: addiu       $a0, $a0, 0x13F8
    ctx->r4 = ADD32(ctx->r4, 0X13F8);
    after_0:
L_800B1BE8:
    // 0x800B1BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1BEC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1BF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B1BF4: jr          $ra
    // 0x800B1BF8: nop

    return;
    // 0x800B1BF8: nop

;}

RECOMP_FUNC void func_800B1BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1BFC: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800B1C00: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x800B1C04: lhu         $t7, 0x10E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X10E);
    // 0x800B1C08: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x800B1C0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B1C10: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B1C14: divu        $zero, $t9, $t8
    lo = S32(U32(ctx->r25) / U32(ctx->r24)); hi = S32(U32(ctx->r25) % U32(ctx->r24));
    // 0x800B1C18: lhu         $s1, 0x112($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X112);
    // 0x800B1C1C: mflo        $v0
    ctx->r2 = lo;
    // 0x800B1C20: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x800B1C24: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800B1C28: div         $zero, $s1, $t0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r8)));
    // 0x800B1C2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B1C30: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800B1C34: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800B1C38: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800B1C3C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800B1C40: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800B1C44: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B1C48: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B1C4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B1C50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B1C54: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800B1C58: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    // 0x800B1C5C: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800B1C60: mflo        $v1
    ctx->r3 = lo;
    // 0x800B1C64: andi        $t1, $v1, 0xFFFF
    ctx->r9 = ctx->r3 & 0XFFFF;
    // 0x800B1C68: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
    // 0x800B1C6C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800B1C70: bne         $t8, $zero, L_800B1C7C
    if (ctx->r24 != 0) {
        // 0x800B1C74: nop
    
            goto L_800B1C7C;
    }
    // 0x800B1C74: nop

    // 0x800B1C78: break       7
    do_break(2148211832);
L_800B1C7C:
    // 0x800B1C7C: sh          $v0, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = ctx->r2;
    // 0x800B1C80: bne         $t0, $zero, L_800B1C8C
    if (ctx->r8 != 0) {
        // 0x800B1C84: nop
    
            goto L_800B1C8C;
    }
    // 0x800B1C84: nop

    // 0x800B1C88: break       7
    do_break(2148211848);
L_800B1C8C:
    // 0x800B1C8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1C90: bne         $t0, $at, L_800B1CA4
    if (ctx->r8 != ctx->r1) {
        // 0x800B1C94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B1CA4;
    }
    // 0x800B1C94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1C98: bne         $a1, $at, L_800B1CA4
    if (ctx->r5 != ctx->r1) {
        // 0x800B1C9C: nop
    
            goto L_800B1CA4;
    }
    // 0x800B1C9C: nop

    // 0x800B1CA0: break       6
    do_break(2148211872);
L_800B1CA4:
    // 0x800B1CA4: andi        $t2, $v1, 0xFFFF
    ctx->r10 = ctx->r3 & 0XFFFF;
    // 0x800B1CA8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800B1CAC: bne         $t1, $zero, L_800B1CC0
    if (ctx->r9 != 0) {
        // 0x800B1CB0: lui         $t7, 0xE700
        ctx->r15 = S32(0XE700 << 16);
            goto L_800B1CC0;
    }
    // 0x800B1CB0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B1CB4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1CB8: b           L_800B1CDC
    // 0x800B1CBC: sh          $s1, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = ctx->r17;
        goto L_800B1CDC;
    // 0x800B1CBC: sh          $s1, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = ctx->r17;
L_800B1CC0:
    // 0x800B1CC0: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1CC4: mflo        $v0
    ctx->r2 = lo;
    // 0x800B1CC8: beql        $a1, $v0, L_800B1CE0
    if (ctx->r5 == ctx->r2) {
        // 0x800B1CCC: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800B1CE0;
    }
    goto skip_0;
    // 0x800B1CCC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_0:
    // 0x800B1CD0: subu        $t3, $a1, $v0
    ctx->r11 = SUB32(ctx->r5, ctx->r2);
    // 0x800B1CD4: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x800B1CD8: or          $t3, $t6, $zero
    ctx->r11 = ctx->r14 | 0;
L_800B1CDC:
    // 0x800B1CDC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800B1CE0:
    // 0x800B1CE0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B1CE4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B1CE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B1CEC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B1CF0: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800B1CF4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B1CF8: lbu         $t6, 0x127($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X127);
    // 0x800B1CFC: lbu         $t8, 0x12B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X12B);
    // 0x800B1D00: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B1D04: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800B1D08: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800B1D0C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x800B1D10: lbu         $t7, 0x12F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X12F);
    // 0x800B1D14: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B1D18: or          $fp, $t2, $zero
    ctx->r30 = ctx->r10 | 0;
    // 0x800B1D1C: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800B1D20: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800B1D24: lbu         $t9, 0x133($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X133);
    // 0x800B1D28: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800B1D2C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800B1D30: blez        $t2, L_800B2250
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800B1D34: sh          $t3, 0xEA($sp)
        MEM_H(0XEA, ctx->r29) = ctx->r11;
            goto L_800B2250;
    }
    // 0x800B1D34: sh          $t3, 0xEA($sp)
    MEM_H(0XEA, ctx->r29) = ctx->r11;
    // 0x800B1D38: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800B1D3C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B1D40: lwc1        $f0, 0x114($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B1D44: sll         $s6, $v1, 1
    ctx->r22 = S32(ctx->r3 << 1);
    // 0x800B1D48: addiu       $s6, $s6, 0x7
    ctx->r22 = ADD32(ctx->r22, 0X7);
    // 0x800B1D4C: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x800B1D50: sll         $a2, $a0, 2
    ctx->r6 = S32(ctx->r4 << 2);
    // 0x800B1D54: sra         $t7, $s6, 3
    ctx->r15 = S32(SIGNED(ctx->r22) >> 3);
    // 0x800B1D58: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x800B1D5C: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x800B1D60: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800B1D64: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800B1D68: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B1D6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B1D70: lhu         $s1, 0xEC($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0XEC);
    // 0x800B1D74: sll         $s6, $t8, 9
    ctx->r22 = S32(ctx->r24 << 9);
    // 0x800B1D78: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B1D7C: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x800B1D80: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800B1D84: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B1D88: or          $t2, $t6, $t9
    ctx->r10 = ctx->r14 | ctx->r25;
    // 0x800B1D8C: or          $t3, $t7, $t9
    ctx->r11 = ctx->r15 | ctx->r25;
    // 0x800B1D90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B1D94: lhu         $s2, 0x11E($sp)
    ctx->r18 = MEM_HU(ctx->r29, 0X11E);
    // 0x800B1D98: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B1D9C: andi        $t1, $a0, 0xFFF
    ctx->r9 = ctx->r4 & 0XFFF;
    // 0x800B1DA0: sll         $ra, $s2, 2
    ctx->r31 = S32(ctx->r18 << 2);
    // 0x800B1DA4: andi        $t7, $ra, 0xFFF
    ctx->r15 = ctx->r31 & 0XFFF;
    // 0x800B1DA8: sll         $ra, $t7, 12
    ctx->r31 = S32(ctx->r15 << 12);
    // 0x800B1DAC: lwc1        $f2, 0x118($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800B1DB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B1DB4: lhu         $t0, 0x122($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X122);
    // 0x800B1DB8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B1DBC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B1DC0: nop

    // 0x800B1DC4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800B1DC8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B1DCC: nop

    // 0x800B1DD0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B1DD4: beql        $t6, $zero, L_800B1E24
    if (ctx->r14 == 0) {
        // 0x800B1DD8: mfc1        $t6, $f8
        ctx->r14 = (int32_t)ctx->f8.u32l;
            goto L_800B1E24;
    }
    goto skip_1;
    // 0x800B1DD8: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x800B1DDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B1DE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B1DE4: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800B1DE8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B1DEC: nop

    // 0x800B1DF0: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B1DF4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B1DF8: nop

    // 0x800B1DFC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B1E00: bne         $t6, $zero, L_800B1E18
    if (ctx->r14 != 0) {
        // 0x800B1E04: nop
    
            goto L_800B1E18;
    }
    // 0x800B1E04: nop

    // 0x800B1E08: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800B1E0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1E10: b           L_800B1E30
    // 0x800B1E14: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800B1E30;
    // 0x800B1E14: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800B1E18:
    // 0x800B1E18: b           L_800B1E30
    // 0x800B1E1C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800B1E30;
    // 0x800B1E1C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800B1E20: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
L_800B1E24:
    // 0x800B1E24: nop

    // 0x800B1E28: bltz        $t6, L_800B1E18
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B1E2C: nop
    
            goto L_800B1E18;
    }
    // 0x800B1E2C: nop

L_800B1E30:
    // 0x800B1E30: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B1E34: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B1E38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B1E3C: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x800B1E40: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B1E44: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800B1E48: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800B1E4C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B1E50: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B1E54: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B1E58: nop

    // 0x800B1E5C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B1E60: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B1E64: nop

    // 0x800B1E68: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B1E6C: beql        $t7, $zero, L_800B1EBC
    if (ctx->r15 == 0) {
        // 0x800B1E70: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_800B1EBC;
    }
    goto skip_2;
    // 0x800B1E70: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x800B1E74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B1E78: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B1E7C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B1E80: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B1E84: nop

    // 0x800B1E88: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B1E8C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B1E90: nop

    // 0x800B1E94: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B1E98: bne         $t7, $zero, L_800B1EB0
    if (ctx->r15 != 0) {
        // 0x800B1E9C: nop
    
            goto L_800B1EB0;
    }
    // 0x800B1E9C: nop

    // 0x800B1EA0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800B1EA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1EA8: b           L_800B1EC8
    // 0x800B1EAC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800B1EC8;
    // 0x800B1EAC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800B1EB0:
    // 0x800B1EB0: b           L_800B1EC8
    // 0x800B1EB4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800B1EC8;
    // 0x800B1EB4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B1EB8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_800B1EBC:
    // 0x800B1EBC: nop

    // 0x800B1EC0: bltz        $t7, L_800B1EB0
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B1EC4: nop
    
            goto L_800B1EB0;
    }
    // 0x800B1EC4: nop

L_800B1EC8:
    // 0x800B1EC8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B1ECC: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x800B1ED0: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x800B1ED4: lhu         $t8, 0x10E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X10E);
    // 0x800B1ED8: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800B1EDC: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800B1EE0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B1EE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B1EE8: bgez        $t8, L_800B1EFC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B1EEC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B1EFC;
    }
    // 0x800B1EEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B1EF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B1EF4: nop

    // 0x800B1EF8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800B1EFC:
    // 0x800B1EFC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B1F00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B1F04: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B1F08: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B1F0C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B1F10: nop

    // 0x800B1F14: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B1F18: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B1F1C: nop

    // 0x800B1F20: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B1F24: beql        $t6, $zero, L_800B1F74
    if (ctx->r14 == 0) {
        // 0x800B1F28: mfc1        $t6, $f16
        ctx->r14 = (int32_t)ctx->f16.u32l;
            goto L_800B1F74;
    }
    goto skip_3;
    // 0x800B1F28: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x800B1F2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B1F30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B1F34: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800B1F38: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B1F3C: nop

    // 0x800B1F40: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B1F44: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B1F48: nop

    // 0x800B1F4C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B1F50: bne         $t6, $zero, L_800B1F68
    if (ctx->r14 != 0) {
        // 0x800B1F54: nop
    
            goto L_800B1F68;
    }
    // 0x800B1F54: nop

    // 0x800B1F58: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800B1F5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1F60: b           L_800B1F80
    // 0x800B1F64: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800B1F80;
    // 0x800B1F64: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800B1F68:
    // 0x800B1F68: b           L_800B1F80
    // 0x800B1F6C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800B1F80;
    // 0x800B1F6C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800B1F70: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
L_800B1F74:
    // 0x800B1F74: nop

    // 0x800B1F78: bltz        $t6, L_800B1F68
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B1F7C: nop
    
            goto L_800B1F68;
    }
    // 0x800B1F7C: nop

L_800B1F80:
    // 0x800B1F80: or          $t7, $t6, $zero
    ctx->r15 = ctx->r14 | 0;
    // 0x800B1F84: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B1F88: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x800B1F8C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B1F90: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800B1F94: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B1F98: mtc1        $s1, $f18
    ctx->f18.u32l = ctx->r17;
    // 0x800B1F9C: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800B1FA0: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800B1FA4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800B1FA8: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800B1FAC: bgez        $s1, L_800B1FC4
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800B1FB0: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800B1FC4;
    }
    // 0x800B1FB0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B1FB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B1FB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B1FBC: nop

    // 0x800B1FC0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800B1FC4:
    // 0x800B1FC4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800B1FC8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B1FCC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B1FD0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B1FD4: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x800B1FD8: nop

    // 0x800B1FDC: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800B1FE0: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x800B1FE4: nop

    // 0x800B1FE8: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x800B1FEC: beql        $a3, $zero, L_800B203C
    if (ctx->r7 == 0) {
        // 0x800B1FF0: mfc1        $a3, $f10
        ctx->r7 = (int32_t)ctx->f10.u32l;
            goto L_800B203C;
    }
    goto skip_4;
    // 0x800B1FF0: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x800B1FF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B1FF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B1FFC: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800B2000: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x800B2004: nop

    // 0x800B2008: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B200C: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x800B2010: nop

    // 0x800B2014: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x800B2018: bne         $a3, $zero, L_800B2030
    if (ctx->r7 != 0) {
        // 0x800B201C: nop
    
            goto L_800B2030;
    }
    // 0x800B201C: nop

    // 0x800B2020: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800B2024: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2028: b           L_800B2048
    // 0x800B202C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_800B2048;
    // 0x800B202C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_800B2030:
    // 0x800B2030: b           L_800B2048
    // 0x800B2034: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_800B2048;
    // 0x800B2034: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800B2038: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
L_800B203C:
    // 0x800B203C: nop

    // 0x800B2040: bltz        $a3, L_800B2030
    if (SIGNED(ctx->r7) < 0) {
        // 0x800B2044: nop
    
            goto L_800B2030;
    }
    // 0x800B2044: nop

L_800B2048:
    // 0x800B2048: multu       $v1, $s1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B204C: andi        $t7, $a3, 0xFFFF
    ctx->r15 = ctx->r7 & 0XFFFF;
    // 0x800B2050: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2054: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800B2058: addiu       $s3, $s3, -0x6E6C
    ctx->r19 = ADD32(ctx->r19, -0X6E6C);
    // 0x800B205C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800B2060: addu        $t5, $t0, $t7
    ctx->r13 = ADD32(ctx->r8, ctx->r15);
    // 0x800B2064: lui         $s7, 0xF500
    ctx->r23 = S32(0XF500 << 16);
    // 0x800B2068: lui         $s4, 0x10
    ctx->r20 = S32(0X10 << 16);
    // 0x800B206C: mflo        $t4
    ctx->r12 = lo;
    // 0x800B2070: andi        $t8, $t4, 0xFFFF
    ctx->r24 = ctx->r12 & 0XFFFF;
    // 0x800B2074: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
L_800B2078:
    // 0x800B2078: multu       $a1, $a3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B207C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800B2080: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800B2084: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B2088: andi        $t6, $t9, 0x7
    ctx->r14 = ctx->r25 & 0X7;
    // 0x800B208C: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x800B2090: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B2094: or          $t9, $t8, $s4
    ctx->r25 = ctx->r24 | ctx->r20;
    // 0x800B2098: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x800B209C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B20A0: mflo        $s2
    ctx->r18 = lo;
    // 0x800B20A4: sh          $s2, 0xE8($sp)
    MEM_H(0XE8, ctx->r29) = ctx->r18;
    // 0x800B20A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B20AC: multu       $a1, $t4
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B20B0: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x800B20B4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B20B8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B20BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B20C0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B20C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800B20C8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B20CC: mflo        $t7
    ctx->r15 = lo;
    // 0x800B20D0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B20D4: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800B20D8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B20DC: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800B20E0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B20E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B20E8: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x800B20EC: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x800B20F0: or          $t6, $t9, $s7
    ctx->r14 = ctx->r25 | ctx->r23;
    // 0x800B20F4: or          $t7, $t6, $s4
    ctx->r15 = ctx->r14 | ctx->r20;
    // 0x800B20F8: or          $t8, $t7, $s6
    ctx->r24 = ctx->r15 | ctx->r22;
    // 0x800B20FC: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x800B2100: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800B2104: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800B2108: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800B210C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800B2110: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B2114: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800B2118: lui         $t7, 0xF400
    ctx->r15 = S32(0XF400 << 16);
    // 0x800B211C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B2120: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x800B2124: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800B2128: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B212C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B2130: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800B2134: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B2138: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B213C: andi        $t6, $t9, 0x7
    ctx->r14 = ctx->r25 & 0X7;
    // 0x800B2140: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x800B2144: or          $t8, $t7, $s7
    ctx->r24 = ctx->r15 | ctx->r23;
    // 0x800B2148: or          $t9, $t8, $s4
    ctx->r25 = ctx->r24 | ctx->r20;
    // 0x800B214C: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x800B2150: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800B2154: or          $t6, $t9, $s6
    ctx->r14 = ctx->r25 | ctx->r22;
    // 0x800B2158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B215C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800B2160: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800B2164: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800B2168: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B216C: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x800B2170: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2174: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800B2178: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x800B217C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800B2180: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800B2184: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B2188: lhu         $a0, -0x6E70($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6E70);
    // 0x800B218C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800B2190: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800B2194: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x800B2198: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800B219C: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x800B21A0: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x800B21A4: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x800B21A8: jal         0x800B1B64
    // 0x800B21AC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    func_800B1B64(rdram, ctx);
        goto after_0;
    // 0x800B21AC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x800B21B0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800B21B4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800B21B8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800B21BC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800B21C0: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800B21C4: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800B21C8: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800B21CC: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800B21D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800B21D4: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x800B21D8: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x800B21DC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800B21E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B21E4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B21E8: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800B21EC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800B21F0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B21F4: addu        $t9, $t0, $a1
    ctx->r25 = ADD32(ctx->r8, ctx->r5);
    // 0x800B21F8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B21FC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B2200: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800B2204: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B220C: or          $t8, $ra, $t7
    ctx->r24 = ctx->r31 | ctx->r15;
    // 0x800B2210: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B2214: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2218: lui         $t9, 0xE100
    ctx->r25 = S32(0XE100 << 16);
    // 0x800B221C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B2220: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800B2224: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800B2228: lui         $t6, 0xF100
    ctx->r14 = S32(0XF100 << 16);
    // 0x800B222C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800B2230: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800B2234: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800B2238: andi        $a1, $s5, 0xFFFF
    ctx->r5 = ctx->r21 & 0XFFFF;
    // 0x800B223C: slt         $at, $a1, $fp
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x800B2240: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800B2244: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2248: bne         $at, $zero, L_800B2078
    if (ctx->r1 != 0) {
        // 0x800B224C: sw          $t7, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r15;
            goto L_800B2078;
    }
    // 0x800B224C: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
L_800B2250:
    // 0x800B2250: lhu         $t3, 0xEA($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0XEA);
    // 0x800B2254: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800B2258: addiu       $s3, $s3, -0x6E6C
    ctx->r19 = ADD32(ctx->r19, -0X6E6C);
    // 0x800B225C: lui         $s4, 0x10
    ctx->r20 = S32(0X10 << 16);
    // 0x800B2260: beq         $t3, $zero, L_800B27D8
    if (ctx->r11 == 0) {
        // 0x800B2264: lui         $s7, 0xF500
        ctx->r23 = S32(0XF500 << 16);
            goto L_800B27D8;
    }
    // 0x800B2264: lui         $s7, 0xF500
    ctx->r23 = S32(0XF500 << 16);
    // 0x800B2268: lhu         $t4, 0xEC($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XEC);
    // 0x800B226C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x800B2270: lhu         $t3, 0x11E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X11E);
    // 0x800B2274: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800B2278: lwc1        $f4, 0x118($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800B227C: bgez        $t4, L_800B2294
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800B2280: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800B2294;
    }
    // 0x800B2280: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B2284: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B2288: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B228C: nop

    // 0x800B2290: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_800B2294:
    // 0x800B2294: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B2298: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B229C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B22A0: lhu         $t8, 0xE8($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XE8);
    // 0x800B22A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B22A8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B22AC: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x800B22B0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B22B4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B22B8: nop

    // 0x800B22BC: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800B22C0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B22C4: nop

    // 0x800B22C8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B22CC: beql        $t6, $zero, L_800B231C
    if (ctx->r14 == 0) {
        // 0x800B22D0: mfc1        $t6, $f10
        ctx->r14 = (int32_t)ctx->f10.u32l;
            goto L_800B231C;
    }
    goto skip_5;
    // 0x800B22D0: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    skip_5:
    // 0x800B22D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B22D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B22DC: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800B22E0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B22E4: nop

    // 0x800B22E8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B22EC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B22F0: nop

    // 0x800B22F4: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B22F8: bne         $t6, $zero, L_800B2310
    if (ctx->r14 != 0) {
        // 0x800B22FC: nop
    
            goto L_800B2310;
    }
    // 0x800B22FC: nop

    // 0x800B2300: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800B2304: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2308: b           L_800B2328
    // 0x800B230C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800B2328;
    // 0x800B230C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800B2310:
    // 0x800B2310: b           L_800B2328
    // 0x800B2314: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800B2328;
    // 0x800B2314: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800B2318: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
L_800B231C:
    // 0x800B231C: nop

    // 0x800B2320: bltz        $t6, L_800B2310
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B2324: nop
    
            goto L_800B2310;
    }
    // 0x800B2324: nop

L_800B2328:
    // 0x800B2328: multu       $a1, $t4
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B232C: or          $t7, $t6, $zero
    ctx->r15 = ctx->r14 | 0;
    // 0x800B2330: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2334: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800B2338: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800B233C: sh          $t9, 0xE8($sp)
    MEM_H(0XE8, ctx->r29) = ctx->r25;
    // 0x800B2340: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x800B2344: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800B2348: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800B234C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800B2350: or          $t6, $t9, $s4
    ctx->r14 = ctx->r25 | ctx->r20;
    // 0x800B2354: mflo        $t9
    ctx->r25 = lo;
    // 0x800B2358: andi        $t8, $a0, 0xFFF
    ctx->r24 = ctx->r4 & 0XFFF;
    // 0x800B235C: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800B2360: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800B2364: multu       $s5, $t6
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2368: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B236C: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x800B2370: sll         $s6, $a1, 1
    ctx->r22 = S32(ctx->r5 << 1);
    // 0x800B2374: addiu       $s6, $s6, 0x7
    ctx->r22 = ADD32(ctx->r22, 0X7);
    // 0x800B2378: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B237C: sll         $a2, $a0, 2
    ctx->r6 = S32(ctx->r4 << 2);
    // 0x800B2380: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2384: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B2388: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800B238C: mflo        $t8
    ctx->r24 = lo;
    // 0x800B2390: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800B2394: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800B2398: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B239C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800B23A0: sra         $t8, $s6, 3
    ctx->r24 = S32(SIGNED(ctx->r22) >> 3);
    // 0x800B23A4: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x800B23A8: sll         $s6, $t7, 9
    ctx->r22 = S32(ctx->r15 << 9);
    // 0x800B23AC: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x800B23B0: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800B23B4: or          $t9, $t7, $s7
    ctx->r25 = ctx->r15 | ctx->r23;
    // 0x800B23B8: or          $t6, $t9, $s4
    ctx->r14 = ctx->r25 | ctx->r20;
    // 0x800B23BC: or          $t8, $t6, $s6
    ctx->r24 = ctx->r14 | ctx->r22;
    // 0x800B23C0: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x800B23C4: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x800B23C8: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800B23CC: sll         $t2, $t6, 12
    ctx->r10 = S32(ctx->r14 << 12);
    // 0x800B23D0: or          $t1, $t2, $at
    ctx->r9 = ctx->r10 | ctx->r1;
    // 0x800B23D4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800B23D8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800B23DC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800B23E0: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800B23E4: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B23E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B23EC: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B23F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B23F4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B23F8: div.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800B23FC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B2400: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B2408: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B240C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B2410: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2414: sll         $ra, $t3, 2
    ctx->r31 = S32(ctx->r11 << 2);
    // 0x800B2418: andi        $t7, $ra, 0xFFF
    ctx->r15 = ctx->r31 & 0XFFF;
    // 0x800B241C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800B2420: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2424: sll         $ra, $t7, 12
    ctx->r31 = S32(ctx->r15 << 12);
    // 0x800B2428: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B242C: lhu         $t0, 0x122($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X122);
    // 0x800B2430: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2434: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2438: nop

    // 0x800B243C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B2440: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2444: nop

    // 0x800B2448: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800B244C: beql        $t8, $zero, L_800B249C
    if (ctx->r24 == 0) {
        // 0x800B2450: mfc1        $t8, $f4
        ctx->r24 = (int32_t)ctx->f4.u32l;
            goto L_800B249C;
    }
    goto skip_6;
    // 0x800B2450: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    skip_6:
    // 0x800B2454: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B2458: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B245C: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B2460: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2464: nop

    // 0x800B2468: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B246C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2470: nop

    // 0x800B2474: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800B2478: bne         $t8, $zero, L_800B2490
    if (ctx->r24 != 0) {
        // 0x800B247C: nop
    
            goto L_800B2490;
    }
    // 0x800B247C: nop

    // 0x800B2480: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800B2484: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2488: b           L_800B24A8
    // 0x800B248C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800B24A8;
    // 0x800B248C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800B2490:
    // 0x800B2490: b           L_800B24A8
    // 0x800B2494: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800B24A8;
    // 0x800B2494: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B2498: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
L_800B249C:
    // 0x800B249C: nop

    // 0x800B24A0: bltz        $t8, L_800B2490
    if (SIGNED(ctx->r24) < 0) {
        // 0x800B24A4: nop
    
            goto L_800B2490;
    }
    // 0x800B24A4: nop

L_800B24A8:
    // 0x800B24A8: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B24AC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B24B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B24B4: lwc1        $f10, 0x118($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800B24B8: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x800B24BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B24C0: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800B24C4: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800B24C8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B24CC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B24D0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B24D4: nop

    // 0x800B24D8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B24DC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B24E0: nop

    // 0x800B24E4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B24E8: beql        $t7, $zero, L_800B2538
    if (ctx->r15 == 0) {
        // 0x800B24EC: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_800B2538;
    }
    goto skip_7;
    // 0x800B24EC: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_7:
    // 0x800B24F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B24F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B24F8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B24FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2500: nop

    // 0x800B2504: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B2508: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B250C: nop

    // 0x800B2510: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2514: bne         $t7, $zero, L_800B252C
    if (ctx->r15 != 0) {
        // 0x800B2518: nop
    
            goto L_800B252C;
    }
    // 0x800B2518: nop

    // 0x800B251C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800B2520: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2524: b           L_800B2544
    // 0x800B2528: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800B2544;
    // 0x800B2528: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800B252C:
    // 0x800B252C: b           L_800B2544
    // 0x800B2530: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800B2544;
    // 0x800B2530: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B2534: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_800B2538:
    // 0x800B2538: nop

    // 0x800B253C: bltz        $t7, L_800B252C
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B2540: nop
    
            goto L_800B252C;
    }
    // 0x800B2540: nop

L_800B2544:
    // 0x800B2544: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2548: or          $t9, $t7, $zero
    ctx->r25 = ctx->r15 | 0;
    // 0x800B254C: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800B2550: lhu         $t9, 0x10E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X10E);
    // 0x800B2554: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800B2558: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800B255C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800B2560: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B2564: bgez        $t9, L_800B2578
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B2568: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B2578;
    }
    // 0x800B2568: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B256C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B2570: nop

    // 0x800B2574: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800B2578:
    // 0x800B2578: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B257C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B2580: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B2584: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2588: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B258C: nop

    // 0x800B2590: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2594: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2598: nop

    // 0x800B259C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800B25A0: beql        $t8, $zero, L_800B25F0
    if (ctx->r24 == 0) {
        // 0x800B25A4: mfc1        $t8, $f18
        ctx->r24 = (int32_t)ctx->f18.u32l;
            goto L_800B25F0;
    }
    goto skip_8;
    // 0x800B25A4: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    skip_8:
    // 0x800B25A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B25AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B25B0: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B25B4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B25B8: nop

    // 0x800B25BC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B25C0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B25C4: nop

    // 0x800B25C8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800B25CC: bne         $t8, $zero, L_800B25E4
    if (ctx->r24 != 0) {
        // 0x800B25D0: nop
    
            goto L_800B25E4;
    }
    // 0x800B25D0: nop

    // 0x800B25D4: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800B25D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B25DC: b           L_800B25FC
    // 0x800B25E0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800B25FC;
    // 0x800B25E0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800B25E4:
    // 0x800B25E4: b           L_800B25FC
    // 0x800B25E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800B25FC;
    // 0x800B25E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B25EC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
L_800B25F0:
    // 0x800B25F0: nop

    // 0x800B25F4: bltz        $t8, L_800B25E4
    if (SIGNED(ctx->r24) < 0) {
        // 0x800B25F8: nop
    
            goto L_800B25E4;
    }
    // 0x800B25F8: nop

L_800B25FC:
    // 0x800B25FC: or          $t7, $t8, $zero
    ctx->r15 = ctx->r24 | 0;
    // 0x800B2600: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x800B2604: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2608: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B260C: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x800B2610: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x800B2614: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800B2618: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800B261C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800B2620: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800B2624: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800B2628: lui         $t8, 0xF400
    ctx->r24 = S32(0XF400 << 16);
    // 0x800B262C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B2630: lhu         $v1, 0xEA($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0XEA);
    // 0x800B2634: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800B2638: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800B263C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800B2640: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800B2644: andi        $v1, $t7, 0xFFF
    ctx->r3 = ctx->r15 & 0XFFF;
    // 0x800B2648: or          $t6, $t1, $v1
    ctx->r14 = ctx->r9 | ctx->r3;
    // 0x800B264C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B2650: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800B2654: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B2658: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800B265C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B2660: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B2664: andi        $t9, $t7, 0x7
    ctx->r25 = ctx->r15 & 0X7;
    // 0x800B2668: sll         $t6, $t9, 21
    ctx->r14 = S32(ctx->r25 << 21);
    // 0x800B266C: or          $t8, $t6, $s7
    ctx->r24 = ctx->r14 | ctx->r23;
    // 0x800B2670: or          $t7, $t8, $s4
    ctx->r15 = ctx->r24 | ctx->r20;
    // 0x800B2674: or          $t9, $t7, $s6
    ctx->r25 = ctx->r15 | ctx->r22;
    // 0x800B2678: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800B267C: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B2680: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800B2684: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800B2688: or          $t7, $t2, $v1
    ctx->r15 = ctx->r10 | ctx->r3;
    // 0x800B268C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800B2690: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800B2694: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x800B2698: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x800B269C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800B26A0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800B26A4: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x800B26A8: jal         0x800B1B64
    // 0x800B26AC: lhu         $a0, -0x6E70($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6E70);
    func_800B1B64(rdram, ctx);
        goto after_1;
    // 0x800B26AC: lhu         $a0, -0x6E70($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6E70);
    after_1:
    // 0x800B26B0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800B26B4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800B26B8: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x800B26BC: lhu         $t6, 0xEA($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XEA);
    // 0x800B26C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B26C4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B26C8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B26CC: lhu         $v1, 0xE8($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0XE8);
    // 0x800B26D0: bgez        $t6, L_800B26E8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B26D4: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B26E8;
    }
    // 0x800B26D4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B26D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B26DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B26E0: nop

    // 0x800B26E4: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_800B26E8:
    // 0x800B26E8: lwc1        $f8, 0x118($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800B26EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B26F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B26F4: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800B26F8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B26FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800B2700: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B2704: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2708: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B270C: nop

    // 0x800B2710: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2714: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2718: nop

    // 0x800B271C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2720: beql        $t7, $zero, L_800B2770
    if (ctx->r15 == 0) {
        // 0x800B2724: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_800B2770;
    }
    goto skip_9;
    // 0x800B2724: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_9:
    // 0x800B2728: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B272C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2730: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B2734: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2738: nop

    // 0x800B273C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B2740: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2744: nop

    // 0x800B2748: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B274C: bne         $t7, $zero, L_800B2764
    if (ctx->r15 != 0) {
        // 0x800B2750: nop
    
            goto L_800B2764;
    }
    // 0x800B2750: nop

    // 0x800B2754: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800B2758: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B275C: b           L_800B277C
    // 0x800B2760: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800B277C;
    // 0x800B2760: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800B2764:
    // 0x800B2764: b           L_800B277C
    // 0x800B2768: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800B277C;
    // 0x800B2768: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B276C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_800B2770:
    // 0x800B2770: nop

    // 0x800B2774: bltz        $t7, L_800B2764
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B2778: nop
    
            goto L_800B2764;
    }
    // 0x800B2778: nop

L_800B277C:
    // 0x800B277C: or          $t9, $t7, $zero
    ctx->r25 = ctx->r15 | 0;
    // 0x800B2780: addu        $t6, $t0, $t9
    ctx->r14 = ADD32(ctx->r8, ctx->r25);
    // 0x800B2784: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2788: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800B278C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800B2790: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800B2794: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x800B2798: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800B279C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800B27A0: addu        $t9, $t0, $v1
    ctx->r25 = ADD32(ctx->r8, ctx->r3);
    // 0x800B27A4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800B27A8: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x800B27AC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B27B0: or          $t7, $ra, $t6
    ctx->r15 = ctx->r31 | ctx->r14;
    // 0x800B27B4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800B27B8: lui         $t9, 0xE100
    ctx->r25 = S32(0XE100 << 16);
    // 0x800B27BC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800B27C0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800B27C4: lui         $t8, 0xF100
    ctx->r24 = S32(0XF100 << 16);
    // 0x800B27C8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800B27CC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800B27D0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B27D4: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
L_800B27D8:
    // 0x800B27D8: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x800B27DC: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x800B27E0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800B27E4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800B27E8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800B27EC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800B27F0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800B27F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B27F8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B27FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B2800: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2804: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B2808: jr          $ra
    // 0x800B280C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x800B280C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}

RECOMP_FUNC void func_800B2810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2810: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B2814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2818: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B281C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B2820: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B2824: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B2828: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B282C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B2830: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800B2834: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B2838: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800B283C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B2840: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800B2844: lbu         $t6, 0x67($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X67);
    // 0x800B2848: lbu         $t9, 0x6B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X6B);
    // 0x800B284C: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x800B2850: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800B2854: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800B2858: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B285C: lbu         $t7, 0x6F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X6F);
    // 0x800B2860: addiu       $v1, $t2, 0x8
    ctx->r3 = ADD32(ctx->r10, 0X8);
    // 0x800B2864: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B2868: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800B286C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800B2870: lbu         $t8, 0x73($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X73);
    // 0x800B2874: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800B2878: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800B287C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800B2880: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x800B2884: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800B2888: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B288C: jal         0x800B1B64
    // 0x800B2890: lhu         $a0, -0x6E70($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6E70);
    func_800B1B64(rdram, ctx);
        goto after_0;
    // 0x800B2890: lhu         $a0, -0x6E70($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X6E70);
    after_0:
    // 0x800B2894: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2898: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B289C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B28A0: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x800B28A4: lhu         $t1, 0x52($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X52);
    // 0x800B28A8: lhu         $a3, 0x4E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X4E);
    // 0x800B28AC: addiu       $t5, $t5, -0x6E6C
    ctx->r13 = ADD32(ctx->r13, -0X6E6C);
    // 0x800B28B0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B28B4: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B28B8: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800B28BC: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x800B28C0: lui         $ra, 0x10
    ctx->r31 = S32(0X10 << 16);
    // 0x800B28C4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B28C8: sll         $t4, $a3, 4
    ctx->r12 = S32(ctx->r7 << 4);
    // 0x800B28CC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B28D0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800B28D4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B28D8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B28DC: mflo        $t0
    ctx->r8 = lo;
    // 0x800B28E0: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x800B28E4: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x800B28E8: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x800B28EC: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800B28F0: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x800B28F4: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800B28F8: or          $t6, $t8, $ra
    ctx->r14 = ctx->r24 | ctx->r31;
    // 0x800B28FC: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800B2900: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B2904: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800B2908: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B290C: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x800B2910: lw          $t6, 0x14($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X14);
    // 0x800B2914: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B2918: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B291C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800B2920: bgez        $t4, L_800B2930
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800B2924: sra         $t9, $t4, 6
        ctx->r25 = S32(SIGNED(ctx->r12) >> 6);
            goto L_800B2930;
    }
    // 0x800B2924: sra         $t9, $t4, 6
    ctx->r25 = S32(SIGNED(ctx->r12) >> 6);
    // 0x800B2928: addiu       $at, $t4, 0x3F
    ctx->r1 = ADD32(ctx->r12, 0X3F);
    // 0x800B292C: sra         $t9, $at, 6
    ctx->r25 = S32(SIGNED(ctx->r1) >> 6);
L_800B2930:
    // 0x800B2930: or          $t8, $t9, $zero
    ctx->r24 = ctx->r25 | 0;
    // 0x800B2934: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800B2938: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x800B293C: sll         $t4, $t7, 9
    ctx->r12 = S32(ctx->r15 << 9);
    // 0x800B2940: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x800B2944: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800B2948: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800B294C: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800B2950: or          $t9, $t6, $ra
    ctx->r25 = ctx->r14 | ctx->r31;
    // 0x800B2954: or          $t8, $t9, $t4
    ctx->r24 = ctx->r25 | ctx->r12;
    // 0x800B2958: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800B295C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800B2960: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800B2964: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B2968: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B296C: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800B2970: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x800B2974: beq         $at, $zero, L_800B2984
    if (ctx->r1 == 0) {
        // 0x800B2978: sw          $t6, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r14;
            goto L_800B2984;
    }
    // 0x800B2978: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B297C: b           L_800B2988
    // 0x800B2980: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
        goto L_800B2988;
    // 0x800B2980: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
L_800B2984:
    // 0x800B2984: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
L_800B2988:
    // 0x800B2988: andi        $t9, $t2, 0xFFF
    ctx->r25 = ctx->r10 & 0XFFF;
    // 0x800B298C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800B2990: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x800B2994: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B2998: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B299C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B29A0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B29A4: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800B29A8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B29AC: andi        $t9, $t6, 0x7
    ctx->r25 = ctx->r14 & 0X7;
    // 0x800B29B0: sll         $t8, $t9, 21
    ctx->r24 = S32(ctx->r25 << 21);
    // 0x800B29B4: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800B29B8: or          $t6, $t7, $ra
    ctx->r14 = ctx->r15 | ctx->r31;
    // 0x800B29BC: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x800B29C0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B29C4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B29C8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800B29CC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B29D0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800B29D4: lbu         $a2, 0xF($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0XF);
    // 0x800B29D8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B29DC: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x800B29E0: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x800B29E4: sll         $t6, $t7, 14
    ctx->r14 = S32(ctx->r15 << 14);
    // 0x800B29E8: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800B29EC: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800B29F0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800B29F4: addiu       $t6, $a3, -0x1
    ctx->r14 = ADD32(ctx->r7, -0X1);
    // 0x800B29F8: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800B29FC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800B2A00: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800B2A04: addiu       $t7, $t1, -0x1
    ctx->r15 = ADD32(ctx->r9, -0X1);
    // 0x800B2A08: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x800B2A0C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800B2A10: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800B2A14: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800B2A18: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800B2A1C: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B2A20: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800B2A24: lui         $t7, 0xD700
    ctx->r15 = S32(0XD700 << 16);
    // 0x800B2A28: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800B2A2C: ori         $t8, $t8, 0x8000
    ctx->r24 = ctx->r24 | 0X8000;
    // 0x800B2A30: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800B2A34: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800B2A38: lhu         $t6, 0x4E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4E);
    // 0x800B2A3C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B2A40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B2A44: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B2A48: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B2A4C: lhu         $a1, 0x62($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X62);
    // 0x800B2A50: lhu         $a0, 0x5E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X5E);
    // 0x800B2A54: bgez        $t6, L_800B2A6C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B2A58: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B2A6C;
    }
    // 0x800B2A58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2A5C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B2A60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B2A64: nop

    // 0x800B2A68: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800B2A6C:
    // 0x800B2A6C: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800B2A70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2A74: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B2A78: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2A7C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2A80: nop

    // 0x800B2A84: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B2A88: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2A8C: nop

    // 0x800B2A90: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2A94: beql        $t7, $zero, L_800B2AE4
    if (ctx->r15 == 0) {
        // 0x800B2A98: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_800B2AE4;
    }
    goto skip_0;
    // 0x800B2A98: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x800B2A9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B2AA0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2AA4: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800B2AA8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2AAC: nop

    // 0x800B2AB0: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2AB4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2AB8: nop

    // 0x800B2ABC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2AC0: bne         $t7, $zero, L_800B2AD8
    if (ctx->r15 != 0) {
        // 0x800B2AC4: nop
    
            goto L_800B2AD8;
    }
    // 0x800B2AC4: nop

    // 0x800B2AC8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800B2ACC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2AD0: b           L_800B2AF0
    // 0x800B2AD4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800B2AF0;
    // 0x800B2AD4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800B2AD8:
    // 0x800B2AD8: b           L_800B2AF0
    // 0x800B2ADC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800B2AF0;
    // 0x800B2ADC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B2AE0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_800B2AE4:
    // 0x800B2AE4: nop

    // 0x800B2AE8: bltz        $t7, L_800B2AD8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B2AEC: nop
    
            goto L_800B2AD8;
    }
    // 0x800B2AEC: nop

L_800B2AF0:
    // 0x800B2AF0: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x800B2AF4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2AF8: addu        $t6, $a0, $t8
    ctx->r14 = ADD32(ctx->r4, ctx->r24);
    // 0x800B2AFC: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800B2B00: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800B2B04: lhu         $t9, 0x52($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X52);
    // 0x800B2B08: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800B2B0C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800B2B10: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800B2B14: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800B2B18: bgez        $t9, L_800B2B30
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B2B1C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800B2B30;
    }
    // 0x800B2B1C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B2B20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B2B24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B2B28: nop

    // 0x800B2B2C: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800B2B30:
    // 0x800B2B30: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800B2B34: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B2B38: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B2B3C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2B40: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2B44: nop

    // 0x800B2B48: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800B2B4C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2B50: nop

    // 0x800B2B54: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800B2B58: beql        $t8, $zero, L_800B2BA8
    if (ctx->r24 == 0) {
        // 0x800B2B5C: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_800B2BA8;
    }
    goto skip_1;
    // 0x800B2B5C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x800B2B60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B2B64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B2B68: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800B2B6C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2B70: nop

    // 0x800B2B74: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B2B78: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2B7C: nop

    // 0x800B2B80: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800B2B84: bne         $t8, $zero, L_800B2B9C
    if (ctx->r24 != 0) {
        // 0x800B2B88: nop
    
            goto L_800B2B9C;
    }
    // 0x800B2B88: nop

    // 0x800B2B8C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800B2B90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2B94: b           L_800B2BB4
    // 0x800B2B98: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800B2BB4;
    // 0x800B2B98: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800B2B9C:
    // 0x800B2B9C: b           L_800B2BB4
    // 0x800B2BA0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800B2BB4;
    // 0x800B2BA0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B2BA4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_800B2BA8:
    // 0x800B2BA8: nop

    // 0x800B2BAC: bltz        $t8, L_800B2B9C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800B2BB0: nop
    
            goto L_800B2B9C;
    }
    // 0x800B2BB0: nop

L_800B2BB4:
    // 0x800B2BB4: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B2BB8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2BBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B2BC0: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x800B2BC4: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x800B2BC8: div.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B2BCC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B2BD0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B2BD4: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800B2BD8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800B2BDC: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x800B2BE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B2BE4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800B2BE8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B2BEC: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x800B2BF0: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800B2BF4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B2BF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B2BFC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B2C00: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B2C04: lui         $t7, 0xE100
    ctx->r15 = S32(0XE100 << 16);
    // 0x800B2C08: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B2C0C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B2C10: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B2C14: lui         $t9, 0xF100
    ctx->r25 = S32(0XF100 << 16);
    // 0x800B2C18: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800B2C1C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B2C20: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B2C24: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2C28: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2C2C: nop

    // 0x800B2C30: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2C34: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2C38: nop

    // 0x800B2C3C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B2C40: beql        $t6, $zero, L_800B2C90
    if (ctx->r14 == 0) {
        // 0x800B2C44: mfc1        $t6, $f18
        ctx->r14 = (int32_t)ctx->f18.u32l;
            goto L_800B2C90;
    }
    goto skip_2;
    // 0x800B2C44: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x800B2C48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B2C4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B2C50: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B2C54: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2C58: nop

    // 0x800B2C5C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800B2C60: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2C64: nop

    // 0x800B2C68: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800B2C6C: bne         $t6, $zero, L_800B2C84
    if (ctx->r14 != 0) {
        // 0x800B2C70: nop
    
            goto L_800B2C84;
    }
    // 0x800B2C70: nop

    // 0x800B2C74: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800B2C78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2C7C: b           L_800B2C9C
    // 0x800B2C80: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800B2C9C;
    // 0x800B2C80: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800B2C84:
    // 0x800B2C84: b           L_800B2C9C
    // 0x800B2C88: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800B2C9C;
    // 0x800B2C88: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800B2C8C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
L_800B2C90:
    // 0x800B2C90: nop

    // 0x800B2C94: bltz        $t6, L_800B2C84
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B2C98: nop
    
            goto L_800B2C84;
    }
    // 0x800B2C98: nop

L_800B2C9C:
    // 0x800B2C9C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2CA0: or          $t9, $t6, $zero
    ctx->r25 = ctx->r14 | 0;
    // 0x800B2CA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2CA8: div.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800B2CAC: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800B2CB0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B2CB4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2CB8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2CBC: nop

    // 0x800B2CC0: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B2CC4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2CC8: nop

    // 0x800B2CCC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2CD0: beql        $t7, $zero, L_800B2D20
    if (ctx->r15 == 0) {
        // 0x800B2CD4: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_800B2D20;
    }
    goto skip_3;
    // 0x800B2CD4: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_3:
    // 0x800B2CD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B2CDC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2CE0: sub.s       $f4, $f8, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800B2CE4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2CE8: nop

    // 0x800B2CEC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B2CF0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2CF4: nop

    // 0x800B2CF8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2CFC: bne         $t7, $zero, L_800B2D14
    if (ctx->r15 != 0) {
        // 0x800B2D00: nop
    
            goto L_800B2D14;
    }
    // 0x800B2D00: nop

    // 0x800B2D04: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800B2D08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2D0C: b           L_800B2D2C
    // 0x800B2D10: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800B2D2C;
    // 0x800B2D10: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800B2D14:
    // 0x800B2D14: b           L_800B2D2C
    // 0x800B2D18: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800B2D2C;
    // 0x800B2D18: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B2D1C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_800B2D20:
    // 0x800B2D20: nop

    // 0x800B2D24: bltz        $t7, L_800B2D14
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B2D28: nop
    
            goto L_800B2D14;
    }
    // 0x800B2D28: nop

L_800B2D2C:
    // 0x800B2D2C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2D30: or          $t9, $t7, $zero
    ctx->r25 = ctx->r15 | 0;
    // 0x800B2D34: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800B2D38: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800B2D3C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800B2D40: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B2D44: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    // 0x800B2D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2D4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800B2D50: jr          $ra
    // 0x800B2D54: nop

    return;
    // 0x800B2D54: nop

    // 0x800B2D58: nop

    // 0x800B2D5C: nop

;}

RECOMP_FUNC void func_800B2D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2D60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B2D64: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x800B2D68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2D6C: ldc1        $f24, 0x1450($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, 0X1450);
    // 0x800B2D70: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800B2D74: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800B2D78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B2D7C: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x800B2D80: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B2D84: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B2D88: addiu       $v0, $v0, -0x3480
    ctx->r2 = ADD32(ctx->r2, -0X3480);
    // 0x800B2D8C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800B2D90: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800B2D94: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B2D98: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x800B2D9C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B2DA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B2DA4: addiu       $a1, $zero, -0x10
    ctx->r5 = ADD32(0, -0X10);
    // 0x800B2DA8: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x800B2DAC: addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // 0x800B2DB0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
L_800B2DB4:
    // 0x800B2DB4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800B2DB8: addiu       $a2, $zero, -0x10
    ctx->r6 = ADD32(0, -0X10);
    // 0x800B2DBC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2DC0: addiu       $a3, $zero, -0xE
    ctx->r7 = ADD32(0, -0XE);
    // 0x800B2DC4: div.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B2DC8: mul.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B2DCC: nop

L_800B2DD0:
    // 0x800B2DD0: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800B2DD4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800B2DD8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800B2DDC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B2DE0: div.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800B2DE4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B2DE8: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800B2DEC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B2DF0: sub.d       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f16.d - ctx->f8.d;
    // 0x800B2DF4: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x800B2DF8: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800B2DFC: c.lt.d      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.d < ctx->f20.d;
    // 0x800B2E00: nop

    // 0x800B2E04: bc1fl       L_800B2E14
    if (!c1cs) {
        // 0x800B2E08: cvt.d.s     $f6, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
            goto L_800B2E14;
    }
    goto skip_0;
    // 0x800B2E08: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    skip_0:
    // 0x800B2E0C: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
    // 0x800B2E10: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
L_800B2E14:
    // 0x800B2E14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2E18: mul.d       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f24.d);
    // 0x800B2E1C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2E20: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2E24: nop

    // 0x800B2E28: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800B2E2C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2E30: nop

    // 0x800B2E34: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2E38: beql        $t7, $zero, L_800B2E8C
    if (ctx->r15 == 0) {
        // 0x800B2E3C: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_800B2E8C;
    }
    goto skip_1;
    // 0x800B2E3C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x800B2E40: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B2E44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B2E48: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2E4C: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x800B2E50: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B2E54: nop

    // 0x800B2E58: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x800B2E5C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B2E60: nop

    // 0x800B2E64: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800B2E68: bne         $t7, $zero, L_800B2E80
    if (ctx->r15 != 0) {
        // 0x800B2E6C: nop
    
            goto L_800B2E80;
    }
    // 0x800B2E6C: nop

    // 0x800B2E70: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800B2E74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2E78: b           L_800B2E98
    // 0x800B2E7C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800B2E98;
    // 0x800B2E7C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800B2E80:
    // 0x800B2E80: b           L_800B2E98
    // 0x800B2E84: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800B2E98;
    // 0x800B2E84: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B2E88: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_800B2E8C:
    // 0x800B2E8C: nop

    // 0x800B2E90: bltz        $t7, L_800B2E80
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B2E94: nop
    
            goto L_800B2E80;
    }
    // 0x800B2E94: nop

L_800B2E98:
    // 0x800B2E98: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800B2E9C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2EA0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800B2EA4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B2EA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2EAC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800B2EB0: sb          $t7, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r15;
    // 0x800B2EB4: div.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B2EB8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B2EBC: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800B2EC0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800B2EC4: sub.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d - ctx->f4.d;
    // 0x800B2EC8: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x800B2ECC: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800B2ED0: c.lt.d      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.d < ctx->f20.d;
    // 0x800B2ED4: nop

    // 0x800B2ED8: bc1fl       L_800B2EE8
    if (!c1cs) {
        // 0x800B2EDC: cvt.d.s     $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
            goto L_800B2EE8;
    }
    goto skip_2;
    // 0x800B2EDC: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    skip_2:
    // 0x800B2EE0: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
    // 0x800B2EE4: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
L_800B2EE8:
    // 0x800B2EE8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B2EEC: mul.d       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f24.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f24.d);
    // 0x800B2EF0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2EF4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2EF8: nop

    // 0x800B2EFC: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800B2F00: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2F04: nop

    // 0x800B2F08: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800B2F0C: beql        $t9, $zero, L_800B2F60
    if (ctx->r25 == 0) {
        // 0x800B2F10: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_800B2F60;
    }
    goto skip_3;
    // 0x800B2F10: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x800B2F14: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800B2F18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B2F1C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B2F20: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x800B2F24: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2F28: nop

    // 0x800B2F2C: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800B2F30: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2F34: nop

    // 0x800B2F38: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800B2F3C: bne         $t9, $zero, L_800B2F54
    if (ctx->r25 != 0) {
        // 0x800B2F40: nop
    
            goto L_800B2F54;
    }
    // 0x800B2F40: nop

    // 0x800B2F44: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800B2F48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2F4C: b           L_800B2F6C
    // 0x800B2F50: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800B2F6C;
    // 0x800B2F50: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800B2F54:
    // 0x800B2F54: b           L_800B2F6C
    // 0x800B2F58: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800B2F6C;
    // 0x800B2F58: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800B2F5C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_800B2F60:
    // 0x800B2F60: nop

    // 0x800B2F64: bltz        $t9, L_800B2F54
    if (SIGNED(ctx->r25) < 0) {
        // 0x800B2F68: nop
    
            goto L_800B2F54;
    }
    // 0x800B2F68: nop

L_800B2F6C:
    // 0x800B2F6C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2F70: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x800B2F74: bne         $a3, $t0, L_800B2DD0
    if (ctx->r7 != ctx->r8) {
        // 0x800B2F78: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B2DD0;
    }
    // 0x800B2F78: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B2F7C: bnel        $a1, $t1, L_800B2DB4
    if (ctx->r5 != ctx->r9) {
        // 0x800B2F80: mtc1        $a1, $f4
        ctx->f4.u32l = ctx->r5;
            goto L_800B2DB4;
    }
    goto skip_4;
    // 0x800B2F80: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    skip_4:
    // 0x800B2F84: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B2F88: addiu       $a0, $a0, -0x6E48
    ctx->r4 = ADD32(ctx->r4, -0X6E48);
    // 0x800B2F8C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B2F90: addiu       $t3, $t3, -0x6E58
    ctx->r11 = ADD32(ctx->r11, -0X6E58);
    // 0x800B2F94: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x800B2F98: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x800B2F9C: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800B2FA0: lui         $t7, 0x701
    ctx->r15 = S32(0X701 << 16);
    // 0x800B2FA4: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x800B2FA8: lui         $t2, 0xFD90
    ctx->r10 = S32(0XFD90 << 16);
    // 0x800B2FAC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800B2FB0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x800B2FB4: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x800B2FB8: lui         $t6, 0xF590
    ctx->r14 = S32(0XF590 << 16);
    // 0x800B2FBC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B2FC0: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800B2FC4: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x800B2FC8: lui         $t7, 0x3
    ctx->r15 = S32(0X3 << 16);
    // 0x800B2FCC: lui         $t2, 0x707
    ctx->r10 = S32(0X707 << 16);
    // 0x800B2FD0: lui         $t4, 0xF588
    ctx->r12 = S32(0XF588 << 16);
    // 0x800B2FD4: addiu       $v1, $v1, -0x6E60
    ctx->r3 = ADD32(ctx->r3, -0X6E60);
    // 0x800B2FD8: ori         $t4, $t4, 0x400
    ctx->r12 = ctx->r12 | 0X400;
    // 0x800B2FDC: ori         $t2, $t2, 0xF400
    ctx->r10 = ctx->r10 | 0XF400;
    // 0x800B2FE0: ori         $t7, $t7, 0xC03C
    ctx->r15 = ctx->r15 | 0XC03C;
    // 0x800B2FE4: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x800B2FE8: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800B2FEC: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800B2FF0: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800B2FF4: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x800B2FF8: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800B2FFC: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x800B3000: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x800B3004: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x800B3008: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x800B300C: sw          $t9, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r25;
    // 0x800B3010: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x800B3014: sw          $t3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r11;
    // 0x800B3018: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x800B301C: sw          $t5, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r13;
    // 0x800B3020: sw          $t7, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r15;
    // 0x800B3024: sw          $t2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r10;
    // 0x800B3028: sw          $t4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r12;
    // 0x800B302C: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800B3030: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x800B3034: jr          $ra
    // 0x800B3038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B3038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void func_800B303C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B303C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B3040: lw          $t6, -0x6E00($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6E00);
    // 0x800B3044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B304C: beql        $t6, $zero, L_800B3068
    if (ctx->r14 == 0) {
        // 0x800B3050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B3068;
    }
    goto skip_0;
    // 0x800B3050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B3054: jal         0x800B2D60
    // 0x800B3058: nop

    func_800B2D60(rdram, ctx);
        goto after_0;
    // 0x800B3058: nop

    after_0:
    // 0x800B305C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3060: sw          $zero, -0x6E00($at)
    MEM_W(-0X6E00, ctx->r1) = 0;
    // 0x800B3064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B3068:
    // 0x800B3068: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B306C: addiu       $v0, $v0, -0x6E60
    ctx->r2 = ADD32(ctx->r2, -0X6E60);
    // 0x800B3070: jr          $ra
    // 0x800B3074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B3074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3078: nop

    // 0x800B307C: nop

;}

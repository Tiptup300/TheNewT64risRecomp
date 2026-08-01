#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Font_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800773D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800773D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800773D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800773DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800773E0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800773E4: jal         0x8007E328
    // 0x800773E8: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800773E8: nop

    after_0:
    // 0x800773EC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800773F0: nop

    // 0x800773F4: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800773F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800773FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077400: jr          $ra
    // 0x80077404: nop

    return;
    // 0x80077404: nop

;}

RECOMP_FUNC void Font_Init46Char(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077408: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007740C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80077410: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80077414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80077418: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007741C: beq         $t6, $zero, L_80077600
    if (ctx->r14 == 0) {
        // 0x80077420: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80077600;
    }
    // 0x80077420: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80077424: jal         0x8004A34C
    // 0x80077428: nop

    Main_DrainMessageQueue(rdram, ctx);
        goto after_0;
    // 0x80077428: nop

    after_0:
    // 0x8007742C: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80077430: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80077434: jal         0x80074888
    // 0x80077438: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_1;
    // 0x80077438: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_1:
    // 0x8007743C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80077440: jal         0x8007E03C
    // 0x80077444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80077444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80077448: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007744C: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80077450: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80077454: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80077458: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8007745C: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80077460: jal         0x800746C0
    // 0x80077464: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_3;
    // 0x80077464: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_3:
    // 0x80077468: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007746C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80077470: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80077474: nop

    // 0x80077478: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8007747C: nop

    // 0x80077480: sh          $t1, 0x74($t9)
    MEM_H(0X74, ctx->r25) = ctx->r9;
    // 0x80077484: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80077488: nop

    // 0x8007748C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80077490: nop

    // 0x80077494: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x80077498: nop

    // 0x8007749C: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x800774A0: mflo        $t5
    ctx->r13 = lo;
    // 0x800774A4: sh          $t5, 0x76($t2)
    MEM_H(0X76, ctx->r10) = ctx->r13;
    // 0x800774A8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800774AC:
    // 0x800774AC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800774B0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800774B4: lh          $t7, 0x74($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X74);
    // 0x800774B8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800774BC: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x800774C0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800774C4: sh          $t8, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r24;
    // 0x800774C8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800774CC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800774D0: lh          $t0, 0x74($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X74);
    // 0x800774D4: lh          $t1, 0x76($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X76);
    // 0x800774D8: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800774DC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800774E0: addu        $t2, $t3, $t5
    ctx->r10 = ADD32(ctx->r11, ctx->r13);
    // 0x800774E4: lh          $t7, 0x4($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X4);
    // 0x800774E8: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800774EC: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x800774F0: mflo        $t6
    ctx->r14 = lo;
    // 0x800774F4: nop

    // 0x800774F8: nop

    // 0x800774FC: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077500: mflo        $t8
    ctx->r24 = lo;
    // 0x80077504: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80077508: addu        $t2, $t9, $t5
    ctx->r10 = ADD32(ctx->r25, ctx->r13);
    // 0x8007750C: lbu         $t4, 0x8($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X8);
    // 0x80077510: nop

    // 0x80077514: andi        $t0, $t4, 0xF0
    ctx->r8 = ctx->r12 & 0XF0;
    // 0x80077518: bne         $t0, $at, L_80077594
    if (ctx->r8 != ctx->r1) {
        // 0x8007751C: nop
    
            goto L_80077594;
    }
    // 0x8007751C: nop

L_80077520:
    // 0x80077520: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80077524: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80077528: sll         $t7, $t1, 1
    ctx->r15 = S32(ctx->r9 << 1);
    // 0x8007752C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80077530: lh          $t3, 0x4($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X4);
    // 0x80077534: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80077538: addiu       $t9, $t3, -0x1
    ctx->r25 = ADD32(ctx->r11, -0X1);
    // 0x8007753C: sh          $t9, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r25;
    // 0x80077540: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80077544: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80077548: lh          $t6, 0x74($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X74);
    // 0x8007754C: lh          $t3, 0x76($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X76);
    // 0x80077550: multu       $t2, $t6
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077554: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80077558: addu        $t0, $t5, $t4
    ctx->r8 = ADD32(ctx->r13, ctx->r12);
    // 0x8007755C: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80077560: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x80077564: mflo        $t7
    ctx->r15 = lo;
    // 0x80077568: nop

    // 0x8007756C: nop

    // 0x80077570: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077574: mflo        $t9
    ctx->r25 = lo;
    // 0x80077578: addu        $t8, $t1, $t9
    ctx->r24 = ADD32(ctx->r9, ctx->r25);
    // 0x8007757C: addu        $t0, $t8, $t4
    ctx->r8 = ADD32(ctx->r24, ctx->r12);
    // 0x80077580: lbu         $t2, 0x8($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X8);
    // 0x80077584: nop

    // 0x80077588: andi        $t6, $t2, 0xF0
    ctx->r14 = ctx->r10 & 0XF0;
    // 0x8007758C: beq         $t6, $at, L_80077520
    if (ctx->r14 == ctx->r1) {
        // 0x80077590: nop
    
            goto L_80077520;
    }
    // 0x80077590: nop

L_80077594:
    // 0x80077594: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80077598: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007759C: sll         $t1, $t3, 1
    ctx->r9 = S32(ctx->r11 << 1);
    // 0x800775A0: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x800775A4: lh          $t5, 0x4($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X4);
    // 0x800775A8: nop

    // 0x800775AC: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800775B0: sh          $t8, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r24;
    // 0x800775B4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800775B8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800775BC: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x800775C0: addu        $t6, $t4, $t2
    ctx->r14 = ADD32(ctx->r12, ctx->r10);
    // 0x800775C4: lh          $t3, 0x4($t6)
    ctx->r11 = MEM_H(ctx->r14, 0X4);
    // 0x800775C8: nop

    // 0x800775CC: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800775D0: beq         $at, $zero, L_800775E8
    if (ctx->r1 == 0) {
        // 0x800775D4: nop
    
            goto L_800775E8;
    }
    // 0x800775D4: nop

    // 0x800775D8: lh          $t7, 0x74($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X74);
    // 0x800775DC: nop

    // 0x800775E0: addiu       $t1, $t7, -0x1
    ctx->r9 = ADD32(ctx->r15, -0X1);
    // 0x800775E4: sh          $t1, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r9;
L_800775E8:
    // 0x800775E8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800775EC: nop

    // 0x800775F0: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800775F4: slti        $at, $t8, 0x2E
    ctx->r1 = SIGNED(ctx->r24) < 0X2E ? 1 : 0;
    // 0x800775F8: bne         $at, $zero, L_800774AC
    if (ctx->r1 != 0) {
        // 0x800775FC: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_800774AC;
    }
    // 0x800775FC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80077600:
    // 0x80077600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80077604: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80077608: jr          $ra
    // 0x8007760C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007760C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Font_Init51Char(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077610: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077614: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80077618: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007761C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80077620: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80077624: beq         $t6, $zero, L_80077808
    if (ctx->r14 == 0) {
        // 0x80077628: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80077808;
    }
    // 0x80077628: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007762C: jal         0x8004A34C
    // 0x80077630: nop

    Main_DrainMessageQueue(rdram, ctx);
        goto after_0;
    // 0x80077630: nop

    after_0:
    // 0x80077634: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80077638: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007763C: jal         0x80074888
    // 0x80077640: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_1;
    // 0x80077640: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_1:
    // 0x80077644: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80077648: jal         0x8007E03C
    // 0x8007764C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8007764C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80077650: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80077654: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80077658: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8007765C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80077660: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80077664: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80077668: jal         0x800746C0
    // 0x8007766C: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_3;
    // 0x8007766C: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_3:
    // 0x80077670: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80077674: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80077678: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8007767C: nop

    // 0x80077680: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80077684: nop

    // 0x80077688: sh          $t1, 0x74($t9)
    MEM_H(0X74, ctx->r25) = ctx->r9;
    // 0x8007768C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80077690: nop

    // 0x80077694: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80077698: nop

    // 0x8007769C: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x800776A0: nop

    // 0x800776A4: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x800776A8: mflo        $t5
    ctx->r13 = lo;
    // 0x800776AC: sh          $t5, 0x76($t2)
    MEM_H(0X76, ctx->r10) = ctx->r13;
    // 0x800776B0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800776B4:
    // 0x800776B4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800776B8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800776BC: lh          $t7, 0x74($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X74);
    // 0x800776C0: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800776C4: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x800776C8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800776CC: sh          $t8, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r24;
    // 0x800776D0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800776D4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800776D8: lh          $t0, 0x74($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X74);
    // 0x800776DC: lh          $t1, 0x76($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X76);
    // 0x800776E0: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800776E4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800776E8: addu        $t2, $t3, $t5
    ctx->r10 = ADD32(ctx->r11, ctx->r13);
    // 0x800776EC: lh          $t7, 0x4($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X4);
    // 0x800776F0: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800776F4: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x800776F8: mflo        $t6
    ctx->r14 = lo;
    // 0x800776FC: nop

    // 0x80077700: nop

    // 0x80077704: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077708: mflo        $t8
    ctx->r24 = lo;
    // 0x8007770C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80077710: addu        $t2, $t9, $t5
    ctx->r10 = ADD32(ctx->r25, ctx->r13);
    // 0x80077714: lbu         $t4, 0x8($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X8);
    // 0x80077718: nop

    // 0x8007771C: andi        $t0, $t4, 0xF0
    ctx->r8 = ctx->r12 & 0XF0;
    // 0x80077720: bne         $t0, $at, L_8007779C
    if (ctx->r8 != ctx->r1) {
        // 0x80077724: nop
    
            goto L_8007779C;
    }
    // 0x80077724: nop

L_80077728:
    // 0x80077728: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8007772C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80077730: sll         $t7, $t1, 1
    ctx->r15 = S32(ctx->r9 << 1);
    // 0x80077734: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80077738: lh          $t3, 0x4($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X4);
    // 0x8007773C: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80077740: addiu       $t9, $t3, -0x1
    ctx->r25 = ADD32(ctx->r11, -0X1);
    // 0x80077744: sh          $t9, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r25;
    // 0x80077748: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8007774C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80077750: lh          $t6, 0x74($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X74);
    // 0x80077754: lh          $t3, 0x76($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X76);
    // 0x80077758: multu       $t2, $t6
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007775C: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80077760: addu        $t0, $t5, $t4
    ctx->r8 = ADD32(ctx->r13, ctx->r12);
    // 0x80077764: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80077768: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8007776C: mflo        $t7
    ctx->r15 = lo;
    // 0x80077770: nop

    // 0x80077774: nop

    // 0x80077778: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007777C: mflo        $t9
    ctx->r25 = lo;
    // 0x80077780: addu        $t8, $t1, $t9
    ctx->r24 = ADD32(ctx->r9, ctx->r25);
    // 0x80077784: addu        $t0, $t8, $t4
    ctx->r8 = ADD32(ctx->r24, ctx->r12);
    // 0x80077788: lbu         $t2, 0x8($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X8);
    // 0x8007778C: nop

    // 0x80077790: andi        $t6, $t2, 0xF0
    ctx->r14 = ctx->r10 & 0XF0;
    // 0x80077794: beq         $t6, $at, L_80077728
    if (ctx->r14 == ctx->r1) {
        // 0x80077798: nop
    
            goto L_80077728;
    }
    // 0x80077798: nop

L_8007779C:
    // 0x8007779C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800777A0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800777A4: sll         $t1, $t3, 1
    ctx->r9 = S32(ctx->r11 << 1);
    // 0x800777A8: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x800777AC: lh          $t5, 0x4($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X4);
    // 0x800777B0: nop

    // 0x800777B4: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800777B8: sh          $t8, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r24;
    // 0x800777BC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800777C0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800777C4: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x800777C8: addu        $t6, $t4, $t2
    ctx->r14 = ADD32(ctx->r12, ctx->r10);
    // 0x800777CC: lh          $t3, 0x4($t6)
    ctx->r11 = MEM_H(ctx->r14, 0X4);
    // 0x800777D0: nop

    // 0x800777D4: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800777D8: beq         $at, $zero, L_800777F0
    if (ctx->r1 == 0) {
        // 0x800777DC: nop
    
            goto L_800777F0;
    }
    // 0x800777DC: nop

    // 0x800777E0: lh          $t7, 0x74($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X74);
    // 0x800777E4: nop

    // 0x800777E8: addiu       $t1, $t7, -0x1
    ctx->r9 = ADD32(ctx->r15, -0X1);
    // 0x800777EC: sh          $t1, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r9;
L_800777F0:
    // 0x800777F0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800777F4: nop

    // 0x800777F8: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800777FC: slti        $at, $t8, 0x33
    ctx->r1 = SIGNED(ctx->r24) < 0X33 ? 1 : 0;
    // 0x80077800: bne         $at, $zero, L_800776B4
    if (ctx->r1 != 0) {
        // 0x80077804: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_800776B4;
    }
    // 0x80077804: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80077808:
    // 0x80077808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007780C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80077810: jr          $ra
    // 0x80077814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80077814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Font_GetCharWidth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077D38: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80077D3C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80077D40: bne         $t6, $zero, L_80077D50
    if (ctx->r14 != 0) {
        // 0x80077D44: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_80077D50;
    }
    // 0x80077D44: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80077D48: b           L_80077D80
    // 0x80077D4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077D80;
    // 0x80077D4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077D50:
    // 0x80077D50: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80077D54: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x80077D58: lbu         $t7, 0x2CD0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X2CD0);
    // 0x80077D5C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80077D60: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80077D64: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x80077D68: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80077D6C: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x80077D70: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80077D74: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80077D78: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x80077D7C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80077D80:
    // 0x80077D80: jr          $ra
    // 0x80077D84: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80077D84: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Font_GetTextWidth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077D88: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80077D8C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80077D90: bne         $t6, $zero, L_80077DA0
    if (ctx->r14 != 0) {
        // 0x80077D94: nop
    
            goto L_80077DA0;
    }
    // 0x80077D94: nop

    // 0x80077D98: b           L_80077E10
    // 0x80077D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077E10;
    // 0x80077D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077DA0:
    // 0x80077DA0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80077DA4: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x80077DA8: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80077DAC: nop

    // 0x80077DB0: beq         $t7, $zero, L_80077E08
    if (ctx->r15 == 0) {
        // 0x80077DB4: nop
    
            goto L_80077E08;
    }
    // 0x80077DB4: nop

L_80077DB8:
    // 0x80077DB8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80077DBC: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80077DC0: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x80077DC4: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80077DC8: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80077DCC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80077DD0: lbu         $t2, 0x2CD0($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X2CD0);
    // 0x80077DD4: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80077DD8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80077DDC: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80077DE0: lh          $t5, 0x4($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X4);
    // 0x80077DE4: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80077DE8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80077DEC: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x80077DF0: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x80077DF4: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x80077DF8: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80077DFC: nop

    // 0x80077E00: bne         $t2, $zero, L_80077DB8
    if (ctx->r10 != 0) {
        // 0x80077E04: nop
    
            goto L_80077DB8;
    }
    // 0x80077E04: nop

L_80077E08:
    // 0x80077E08: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80077E0C: nop

L_80077E10:
    // 0x80077E10: jr          $ra
    // 0x80077E14: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80077E14: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Font_GetScaledTextWidth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077E18: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80077E1C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80077E20: bne         $t6, $zero, L_80077E30
    if (ctx->r14 != 0) {
        // 0x80077E24: nop
    
            goto L_80077E30;
    }
    // 0x80077E24: nop

    // 0x80077E28: b           L_80077ED8
    // 0x80077E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077ED8;
    // 0x80077E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077E30:
    // 0x80077E30: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80077E34: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x80077E38: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80077E3C: nop

    // 0x80077E40: beq         $t7, $zero, L_80077ED0
    if (ctx->r15 == 0) {
        // 0x80077E44: nop
    
            goto L_80077ED0;
    }
    // 0x80077E44: nop

L_80077E48:
    // 0x80077E48: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80077E4C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80077E50: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x80077E54: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80077E58: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80077E5C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80077E60: lbu         $t1, 0x2CD0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2CD0);
    // 0x80077E64: lh          $t6, 0x2D70($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2D70);
    // 0x80077E68: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80077E6C: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80077E70: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x80077E74: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80077E78: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x80077E7C: div         $zero, $t5, $t6
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r14)));
    // 0x80077E80: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80077E84: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80077E88: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80077E8C: bne         $t6, $zero, L_80077E98
    if (ctx->r14 != 0) {
        // 0x80077E90: nop
    
            goto L_80077E98;
    }
    // 0x80077E90: nop

    // 0x80077E94: break       7
    do_break(2147974804);
L_80077E98:
    // 0x80077E98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80077E9C: bne         $t6, $at, L_80077EB0
    if (ctx->r14 != ctx->r1) {
        // 0x80077EA0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80077EB0;
    }
    // 0x80077EA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80077EA4: bne         $t5, $at, L_80077EB0
    if (ctx->r13 != ctx->r1) {
        // 0x80077EA8: nop
    
            goto L_80077EB0;
    }
    // 0x80077EA8: nop

    // 0x80077EAC: break       6
    do_break(2147974828);
L_80077EB0:
    // 0x80077EB0: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x80077EB4: mflo        $t7
    ctx->r15 = lo;
    // 0x80077EB8: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x80077EBC: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x80077EC0: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80077EC4: nop

    // 0x80077EC8: bne         $t4, $zero, L_80077E48
    if (ctx->r12 != 0) {
        // 0x80077ECC: nop
    
            goto L_80077E48;
    }
    // 0x80077ECC: nop

L_80077ED0:
    // 0x80077ED0: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80077ED4: nop

L_80077ED8:
    // 0x80077ED8: jr          $ra
    // 0x80077EDC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80077EDC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Font_GetCharWidthUpper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007802C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80078030: slti        $at, $a1, 0x61
    ctx->r1 = SIGNED(ctx->r5) < 0X61 ? 1 : 0;
    // 0x80078034: bne         $at, $zero, L_80078050
    if (ctx->r1 != 0) {
        // 0x80078038: slti        $at, $a1, 0x7B
        ctx->r1 = SIGNED(ctx->r5) < 0X7B ? 1 : 0;
            goto L_80078050;
    }
    // 0x80078038: slti        $at, $a1, 0x7B
    ctx->r1 = SIGNED(ctx->r5) < 0X7B ? 1 : 0;
    // 0x8007803C: beq         $at, $zero, L_80078050
    if (ctx->r1 == 0) {
        // 0x80078040: nop
    
            goto L_80078050;
    }
    // 0x80078040: nop

    // 0x80078044: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x80078048: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8007804C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_80078050:
    // 0x80078050: slti        $at, $a1, 0x20
    ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x80078054: bne         $at, $zero, L_80078064
    if (ctx->r1 != 0) {
        // 0x80078058: slti        $at, $a1, 0x60
        ctx->r1 = SIGNED(ctx->r5) < 0X60 ? 1 : 0;
            goto L_80078064;
    }
    // 0x80078058: slti        $at, $a1, 0x60
    ctx->r1 = SIGNED(ctx->r5) < 0X60 ? 1 : 0;
    // 0x8007805C: bne         $at, $zero, L_8007806C
    if (ctx->r1 != 0) {
        // 0x80078060: nop
    
            goto L_8007806C;
    }
    // 0x80078060: nop

L_80078064:
    // 0x80078064: jr          $ra
    // 0x80078068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80078068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007806C:
    // 0x8007806C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80078070: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x80078074: lbu         $t7, 0x2CD0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X2CD0);
    // 0x80078078: nop

    // 0x8007807C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80078080: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80078084: lh          $v0, 0x4($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X4);
    // 0x80078088: nop

    // 0x8007808C: jr          $ra
    // 0x80078090: nop

    return;
    // 0x80078090: nop

;}

RECOMP_FUNC void Font_MeasureChars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800781A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800781AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800781B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800781B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800781B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800781BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800781C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800781C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800781C8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800781CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800781D0: bne         $t7, $zero, L_800781E0
    if (ctx->r15 != 0) {
        // 0x800781D4: nop
    
            goto L_800781E0;
    }
    // 0x800781D4: nop

    // 0x800781D8: b           L_80078230
    // 0x800781DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078230;
    // 0x800781DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800781E0:
    // 0x800781E0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800781E4: nop

    // 0x800781E8: blez        $t8, L_8007822C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800781EC: nop
    
            goto L_8007822C;
    }
    // 0x800781EC: nop

L_800781F0:
    // 0x800781F0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800781F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800781F8: lbu         $a1, 0x0($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X0);
    // 0x800781FC: jal         0x8007802C
    // 0x80078200: nop

    Font_GetCharWidthUpper(rdram, ctx);
        goto after_0;
    // 0x80078200: nop

    after_0:
    // 0x80078204: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80078208: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007820C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80078210: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80078214: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80078218: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8007821C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80078220: addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
    // 0x80078224: bgtz        $t4, L_800781F0
    if (SIGNED(ctx->r12) > 0) {
        // 0x80078228: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_800781F0;
    }
    // 0x80078228: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_8007822C:
    // 0x8007822C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80078230:
    // 0x80078230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80078234: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80078238: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007823C: jr          $ra
    // 0x80078240: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80078240: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

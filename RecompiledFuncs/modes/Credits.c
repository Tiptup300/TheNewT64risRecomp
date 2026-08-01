#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Credits_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083320: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80083324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80083328: jal         0x8004A34C
    // 0x8008332C: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x8008332C: nop

    after_0:
    // 0x80083330: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // 0x80083334: jal         0x8007E03C
    // 0x80083338: ori         $a0, $a0, 0xA988
    ctx->r4 = ctx->r4 | 0XA988;
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80083338: ori         $a0, $a0, 0xA988
    ctx->r4 = ctx->r4 | 0XA988;
    after_1:
    // 0x8008333C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083340: sw          $v0, 0x240($at)
    MEM_W(0X240, ctx->r1) = ctx->r2;
    // 0x80083344: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80083348: lw          $t7, 0x240($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X240);
    // 0x8008334C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80083350: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80083354: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80083358: lw          $t9, 0x240($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X240);
    // 0x8008335C: addiu       $t8, $zero, 0x90
    ctx->r24 = ADD32(0, 0X90);
    // 0x80083360: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80083364: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
    // 0x80083368: lw          $t1, 0x240($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X240);
    // 0x8008336C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80083370: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80083374: sb          $t0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r8;
    // 0x80083378: lw          $t3, 0x240($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X240);
    // 0x8008337C: addiu       $t2, $zero, 0x2C
    ctx->r10 = ADD32(0, 0X2C);
    // 0x80083380: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80083384: sb          $t2, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r10;
    // 0x80083388: lw          $t4, 0x240($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X240);
    // 0x8008338C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80083390: sb          $zero, 0x4($t4)
    MEM_B(0X4, ctx->r12) = 0;
    // 0x80083394: lw          $t5, 0x240($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X240);
    // 0x80083398: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008339C: sb          $zero, 0x5($t5)
    MEM_B(0X5, ctx->r13) = 0;
    // 0x800833A0: lw          $t6, 0x240($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X240);
    // 0x800833A4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800833A8: sb          $zero, 0x6($t6)
    MEM_B(0X6, ctx->r14) = 0;
    // 0x800833AC: lw          $t7, 0x240($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X240);
    // 0x800833B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800833B4: sb          $zero, 0x7($t7)
    MEM_B(0X7, ctx->r15) = 0;
    // 0x800833B8: lw          $a0, 0x240($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X240);
    // 0x800833BC: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x800833C0: ori         $a1, $a1, 0xD4C4
    ctx->r5 = ctx->r5 | 0XD4C4;
    // 0x800833C4: jal         0x800A8FC8
    // 0x800833C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    CubeTiles_FillHalfwords(rdram, ctx);
        goto after_2;
    // 0x800833C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800833CC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800833D0: lw          $t8, 0x240($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X240);
    // 0x800833D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800833D8: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    // 0x800833DC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800833E0: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x800833E4: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    // 0x800833E8: jal         0x8008F280
    // 0x800833EC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    Scene_LoadObjectSprite(rdram, ctx);
        goto after_3;
    // 0x800833EC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_3:
    // 0x800833F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800833F4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800833F8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800833FC: addiu       $a2, $a2, 0x6128
    ctx->r6 = ADD32(ctx->r6, 0X6128);
    // 0x80083400: addiu       $a1, $a1, 0x6138
    ctx->r5 = ADD32(ctx->r5, 0X6138);
    // 0x80083404: jal         0x8008F360
    // 0x80083408: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    func_8008F360(rdram, ctx);
        goto after_4;
    // 0x80083408: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    after_4:
    // 0x8008340C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083410: sw          $zero, 0x3CF4($at)
    MEM_W(0X3CF4, ctx->r1) = 0;
    // 0x80083414: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083418: sw          $zero, 0x3CF8($at)
    MEM_W(0X3CF8, ctx->r1) = 0;
    // 0x8008341C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083420: sw          $zero, 0x3CFC($at)
    MEM_W(0X3CFC, ctx->r1) = 0;
    // 0x80083424: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80083428: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008342C: lw          $a1, 0x31F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31F0);
    // 0x80083430: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80083434: sw          $zero, -0x6E1C($at)
    MEM_W(-0X6E1C, ctx->r1) = 0;
    // 0x80083438: jal         0x8007FFE4
    // 0x8008343C: addiu       $a0, $a0, 0x248
    ctx->r4 = ADD32(ctx->r4, 0X248);
    EndScroller_Init(rdram, ctx);
        goto after_5;
    // 0x8008343C: addiu       $a0, $a0, 0x248
    ctx->r4 = ADD32(ctx->r4, 0X248);
    after_5:
    // 0x80083440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80083444: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80083448: jr          $ra
    // 0x8008344C: nop

    return;
    // 0x8008344C: nop

;}

RECOMP_FUNC void Credits_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80083454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083458: jal         0x80090A44
    // 0x8008345C: nop

    Scene_FreeResources(rdram, ctx);
        goto after_0;
    // 0x8008345C: nop

    after_0:
    // 0x80083460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80083468: jr          $ra
    // 0x8008346C: nop

    return;
    // 0x8008346C: nop

;}

RECOMP_FUNC void Credits_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083470: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80083474: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80083478: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8008347C: lw          $s0, 0x3330($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X3330);
    // 0x80083480: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80083484: beq         $s0, $zero, L_800834A4
    if (ctx->r16 == 0) {
        // 0x80083488: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800834A4;
    }
    // 0x80083488: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008348C: beq         $s0, $at, L_800834BC
    if (ctx->r16 == ctx->r1) {
        // 0x80083490: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800834BC;
    }
    // 0x80083490: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80083494: beq         $s0, $at, L_80083504
    if (ctx->r16 == ctx->r1) {
        // 0x80083498: nop
    
            goto L_80083504;
    }
    // 0x80083498: nop

    // 0x8008349C: b           L_8008354C
    // 0x800834A0: nop

        goto L_8008354C;
    // 0x800834A0: nop

L_800834A4:
    // 0x800834A4: jal         0x80083320
    // 0x800834A8: nop

    Credits_Init(rdram, ctx);
        goto after_0;
    // 0x800834A8: nop

    after_0:
    // 0x800834AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800834B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800834B4: b           L_8008354C
    // 0x800834B8: sw          $t6, 0x3330($at)
    MEM_W(0X3330, ctx->r1) = ctx->r14;
        goto L_8008354C;
    // 0x800834B8: sw          $t6, 0x3330($at)
    MEM_W(0X3330, ctx->r1) = ctx->r14;
L_800834BC:
    // 0x800834BC: jal         0x8009D5E4
    // 0x800834C0: nop

    Scene_Init(rdram, ctx);
        goto after_1;
    // 0x800834C0: nop

    after_1:
    // 0x800834C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800834C8: addiu       $a0, $a0, 0x248
    ctx->r4 = ADD32(ctx->r4, 0X248);
    // 0x800834CC: jal         0x8008023C
    // 0x800834D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    EndScroller_Update(rdram, ctx);
        goto after_2;
    // 0x800834D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x800834D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800834D8: bne         $v0, $at, L_800834F0
    if (ctx->r2 != ctx->r1) {
        // 0x800834DC: nop
    
            goto L_800834F0;
    }
    // 0x800834DC: nop

    // 0x800834E0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800834E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800834E8: b           L_8008354C
    // 0x800834EC: sw          $t7, 0x3330($at)
    MEM_W(0X3330, ctx->r1) = ctx->r15;
        goto L_8008354C;
    // 0x800834EC: sw          $t7, 0x3330($at)
    MEM_W(0X3330, ctx->r1) = ctx->r15;
L_800834F0:
    // 0x800834F0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800834F4: jal         0x80080400
    // 0x800834F8: addiu       $a0, $a0, 0x248
    ctx->r4 = ADD32(ctx->r4, 0X248);
    EndScroller_Draw(rdram, ctx);
        goto after_3;
    // 0x800834F8: addiu       $a0, $a0, 0x248
    ctx->r4 = ADD32(ctx->r4, 0X248);
    after_3:
    // 0x800834FC: b           L_8008354C
    // 0x80083500: nop

        goto L_8008354C;
    // 0x80083500: nop

L_80083504:
    // 0x80083504: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80083508: jal         0x8008015C
    // 0x8008350C: addiu       $a0, $a0, 0x248
    ctx->r4 = ADD32(ctx->r4, 0X248);
    EndScroller_Deinit(rdram, ctx);
        goto after_4;
    // 0x8008350C: addiu       $a0, $a0, 0x248
    ctx->r4 = ADD32(ctx->r4, 0X248);
    after_4:
    // 0x80083510: jal         0x80083450
    // 0x80083514: nop

    Credits_Deinit(rdram, ctx);
        goto after_5;
    // 0x80083514: nop

    after_5:
    // 0x80083518: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8008351C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80083520: addiu       $a1, $a1, 0x5378
    ctx->r5 = ADD32(ctx->r5, 0X5378);
    // 0x80083524: jal         0x8009035C
    // 0x80083528: addiu       $a0, $a0, 0x53C8
    ctx->r4 = ADD32(ctx->r4, 0X53C8);
    func_8009035C(rdram, ctx);
        goto after_6;
    // 0x80083528: addiu       $a0, $a0, 0x53C8
    ctx->r4 = ADD32(ctx->r4, 0X53C8);
    after_6:
    // 0x8008352C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80083530: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083534: sb          $t8, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r24;
    // 0x80083538: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008353C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80083540: sb          $t9, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r25;
    // 0x80083544: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083548: sw          $zero, 0x3330($at)
    MEM_W(0X3330, ctx->r1) = 0;
L_8008354C:
    // 0x8008354C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80083550: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80083554: jr          $ra
    // 0x80083558: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80083558: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008355C: nop

;}

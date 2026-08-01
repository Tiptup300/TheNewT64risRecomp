#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Vi_ApplyModeBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061198: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8006119C: lbu         $t6, -0x1CC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X1CC);
    // 0x800611A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800611A4: beq         $t6, $zero, L_800611C4
    if (ctx->r14 == 0) {
        // 0x800611A8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800611C4;
    }
    // 0x800611A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800611AC: jal         0x800614A8
    // 0x800611B0: nop

    Vi_StoreModeBankForTvType(rdram, ctx);
        goto after_0;
    // 0x800611B0: nop

    after_0:
    // 0x800611B4: jal         0x80060D58
    // 0x800611B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    PFGFX_ApplyViXScale(rdram, ctx);
        goto after_1;
    // 0x800611B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800611BC: b           L_800611D0
    // 0x800611C0: nop

        goto L_800611D0;
    // 0x800611C0: nop

L_800611C4:
    // 0x800611C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800611C8: jal         0x800611E0
    // 0x800611CC: sw          $zero, 0x30C($at)
    MEM_W(0X30C, ctx->r1) = 0;
    Vi_LoadModeBankForTvType(rdram, ctx);
        goto after_2;
    // 0x800611CC: sw          $zero, 0x30C($at)
    MEM_W(0X30C, ctx->r1) = 0;
    after_2:
L_800611D0:
    // 0x800611D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800611D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800611D8: jr          $ra
    // 0x800611DC: nop

    return;
    // 0x800611DC: nop

;}

RECOMP_FUNC void Vi_LoadModeBankForTvType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800611E0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800611E4: lw          $t6, 0x30C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30C);
    // 0x800611E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800611EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800611F0: bne         $t6, $at, L_8006121C
    if (ctx->r14 != ctx->r1) {
        // 0x800611F4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006121C;
    }
    // 0x800611F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800611F8: jal         0x80061198
    // 0x800611FC: nop

    Vi_ApplyModeBank(rdram, ctx);
        goto after_0;
    // 0x800611FC: nop

    after_0:
    // 0x80061200: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80061204: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80061208: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006120C: bne         $t7, $at, L_80061498
    if (ctx->r15 != ctx->r1) {
        // 0x80061210: nop
    
            goto L_80061498;
    }
    // 0x80061210: nop

    // 0x80061214: b           L_80061498
    // 0x80061218: nop

        goto L_80061498;
    // 0x80061218: nop

L_8006121C:
    // 0x8006121C: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80061220: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x80061224: nop

    // 0x80061228: bne         $t8, $zero, L_800612F0
    if (ctx->r24 != 0) {
        // 0x8006122C: nop
    
            goto L_800612F0;
    }
    // 0x8006122C: nop

    // 0x80061230: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80061234: addiu       $t9, $t9, -0x6A90
    ctx->r25 = ADD32(ctx->r25, -0X6A90);
    // 0x80061238: lw          $t0, 0x508($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X508);
    // 0x8006123C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80061240: addiu       $t1, $t1, 0x31C
    ctx->r9 = ADD32(ctx->r9, 0X31C);
    // 0x80061244: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80061248: addiu       $t2, $t2, -0x6A90
    ctx->r10 = ADD32(ctx->r10, -0X6A90);
    // 0x8006124C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80061250: lw          $t3, 0x520($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X520);
    // 0x80061254: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80061258: addiu       $t4, $t4, 0x31C
    ctx->r12 = ADD32(ctx->r12, 0X31C);
    // 0x8006125C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80061260: addiu       $t5, $t5, -0x6A90
    ctx->r13 = ADD32(ctx->r13, -0X6A90);
    // 0x80061264: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80061268: lw          $t6, 0x530($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X530);
    // 0x8006126C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80061270: addiu       $t7, $t7, 0x31C
    ctx->r15 = ADD32(ctx->r15, 0X31C);
    // 0x80061274: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80061278: addiu       $t8, $t8, -0x6A90
    ctx->r24 = ADD32(ctx->r24, -0X6A90);
    // 0x8006127C: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x80061280: lw          $t9, 0x544($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X544);
    // 0x80061284: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80061288: addiu       $t0, $t0, 0x31C
    ctx->r8 = ADD32(ctx->r8, 0X31C);
    // 0x8006128C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80061290: addiu       $t1, $t1, -0x6A90
    ctx->r9 = ADD32(ctx->r9, -0X6A90);
    // 0x80061294: sw          $t9, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r25;
    // 0x80061298: lw          $t2, 0x528($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X528);
    // 0x8006129C: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800612A0: addiu       $t3, $t3, 0x31C
    ctx->r11 = ADD32(ctx->r11, 0X31C);
    // 0x800612A4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800612A8: addiu       $t4, $t4, -0x6A90
    ctx->r12 = ADD32(ctx->r12, -0X6A90);
    // 0x800612AC: sw          $t2, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r10;
    // 0x800612B0: lw          $t5, 0x53C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X53C);
    // 0x800612B4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800612B8: addiu       $t6, $t6, 0x31C
    ctx->r14 = ADD32(ctx->r14, 0X31C);
    // 0x800612BC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800612C0: addiu       $t7, $t7, -0x6A90
    ctx->r15 = ADD32(ctx->r15, -0X6A90);
    // 0x800612C4: sw          $t5, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r13;
    // 0x800612C8: lw          $t8, 0x52C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X52C);
    // 0x800612CC: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800612D0: addiu       $t9, $t9, 0x31C
    ctx->r25 = ADD32(ctx->r25, 0X31C);
    // 0x800612D4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800612D8: addiu       $t0, $t0, -0x6A90
    ctx->r8 = ADD32(ctx->r8, -0X6A90);
    // 0x800612DC: sw          $t8, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r24;
    // 0x800612E0: lw          $t1, 0x540($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X540);
    // 0x800612E4: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800612E8: addiu       $t2, $t2, 0x31C
    ctx->r10 = ADD32(ctx->r10, 0X31C);
    // 0x800612EC: sw          $t1, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r9;
L_800612F0:
    // 0x800612F0: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800612F4: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x800612F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800612FC: bne         $t3, $at, L_800613C4
    if (ctx->r11 != ctx->r1) {
        // 0x80061300: nop
    
            goto L_800613C4;
    }
    // 0x80061300: nop

    // 0x80061304: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80061308: addiu       $t4, $t4, -0x6A90
    ctx->r12 = ADD32(ctx->r12, -0X6A90);
    // 0x8006130C: lw          $t5, 0xA8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XA8);
    // 0x80061310: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80061314: addiu       $t6, $t6, 0x31C
    ctx->r14 = ADD32(ctx->r14, 0X31C);
    // 0x80061318: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8006131C: addiu       $t7, $t7, -0x6A90
    ctx->r15 = ADD32(ctx->r15, -0X6A90);
    // 0x80061320: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80061324: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x80061328: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8006132C: addiu       $t9, $t9, 0x31C
    ctx->r25 = ADD32(ctx->r25, 0X31C);
    // 0x80061330: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80061334: addiu       $t0, $t0, -0x6A90
    ctx->r8 = ADD32(ctx->r8, -0X6A90);
    // 0x80061338: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8006133C: lw          $t1, 0xD0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD0);
    // 0x80061340: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80061344: addiu       $t2, $t2, 0x31C
    ctx->r10 = ADD32(ctx->r10, 0X31C);
    // 0x80061348: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006134C: addiu       $t3, $t3, -0x6A90
    ctx->r11 = ADD32(ctx->r11, -0X6A90);
    // 0x80061350: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80061354: lw          $t4, 0xE4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XE4);
    // 0x80061358: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x8006135C: addiu       $t5, $t5, 0x31C
    ctx->r13 = ADD32(ctx->r13, 0X31C);
    // 0x80061360: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80061364: addiu       $t6, $t6, -0x6A90
    ctx->r14 = ADD32(ctx->r14, -0X6A90);
    // 0x80061368: sw          $t4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r12;
    // 0x8006136C: lw          $t7, 0xC8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC8);
    // 0x80061370: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80061374: addiu       $t8, $t8, 0x31C
    ctx->r24 = ADD32(ctx->r24, 0X31C);
    // 0x80061378: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006137C: addiu       $t9, $t9, -0x6A90
    ctx->r25 = ADD32(ctx->r25, -0X6A90);
    // 0x80061380: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x80061384: lw          $t0, 0xDC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XDC);
    // 0x80061388: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8006138C: addiu       $t1, $t1, 0x31C
    ctx->r9 = ADD32(ctx->r9, 0X31C);
    // 0x80061390: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80061394: addiu       $t2, $t2, -0x6A90
    ctx->r10 = ADD32(ctx->r10, -0X6A90);
    // 0x80061398: sw          $t0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r8;
    // 0x8006139C: lw          $t3, 0xCC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XCC);
    // 0x800613A0: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800613A4: addiu       $t4, $t4, 0x31C
    ctx->r12 = ADD32(ctx->r12, 0X31C);
    // 0x800613A8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800613AC: addiu       $t5, $t5, -0x6A90
    ctx->r13 = ADD32(ctx->r13, -0X6A90);
    // 0x800613B0: sw          $t3, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r11;
    // 0x800613B4: lw          $t6, 0xE0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XE0);
    // 0x800613B8: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800613BC: addiu       $t7, $t7, 0x31C
    ctx->r15 = ADD32(ctx->r15, 0X31C);
    // 0x800613C0: sw          $t6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r14;
L_800613C4:
    // 0x800613C4: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800613C8: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800613CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800613D0: bne         $t8, $at, L_80061498
    if (ctx->r24 != ctx->r1) {
        // 0x800613D4: nop
    
            goto L_80061498;
    }
    // 0x800613D4: nop

    // 0x800613D8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800613DC: addiu       $t9, $t9, -0x6A90
    ctx->r25 = ADD32(ctx->r25, -0X6A90);
    // 0x800613E0: lw          $t0, 0x968($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X968);
    // 0x800613E4: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800613E8: addiu       $t1, $t1, 0x31C
    ctx->r9 = ADD32(ctx->r9, 0X31C);
    // 0x800613EC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800613F0: addiu       $t2, $t2, -0x6A90
    ctx->r10 = ADD32(ctx->r10, -0X6A90);
    // 0x800613F4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800613F8: lw          $t3, 0x980($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X980);
    // 0x800613FC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80061400: addiu       $t4, $t4, 0x31C
    ctx->r12 = ADD32(ctx->r12, 0X31C);
    // 0x80061404: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80061408: addiu       $t5, $t5, -0x6A90
    ctx->r13 = ADD32(ctx->r13, -0X6A90);
    // 0x8006140C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80061410: lw          $t6, 0x990($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X990);
    // 0x80061414: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80061418: addiu       $t7, $t7, 0x31C
    ctx->r15 = ADD32(ctx->r15, 0X31C);
    // 0x8006141C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80061420: addiu       $t8, $t8, -0x6A90
    ctx->r24 = ADD32(ctx->r24, -0X6A90);
    // 0x80061424: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x80061428: lw          $t9, 0x9A4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X9A4);
    // 0x8006142C: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80061430: addiu       $t0, $t0, 0x31C
    ctx->r8 = ADD32(ctx->r8, 0X31C);
    // 0x80061434: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80061438: addiu       $t1, $t1, -0x6A90
    ctx->r9 = ADD32(ctx->r9, -0X6A90);
    // 0x8006143C: sw          $t9, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r25;
    // 0x80061440: lw          $t2, 0x988($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X988);
    // 0x80061444: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80061448: addiu       $t3, $t3, 0x31C
    ctx->r11 = ADD32(ctx->r11, 0X31C);
    // 0x8006144C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80061450: addiu       $t4, $t4, -0x6A90
    ctx->r12 = ADD32(ctx->r12, -0X6A90);
    // 0x80061454: sw          $t2, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r10;
    // 0x80061458: lw          $t5, 0x99C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X99C);
    // 0x8006145C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80061460: addiu       $t6, $t6, 0x31C
    ctx->r14 = ADD32(ctx->r14, 0X31C);
    // 0x80061464: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80061468: addiu       $t7, $t7, -0x6A90
    ctx->r15 = ADD32(ctx->r15, -0X6A90);
    // 0x8006146C: sw          $t5, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r13;
    // 0x80061470: lw          $t8, 0x98C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X98C);
    // 0x80061474: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80061478: addiu       $t9, $t9, 0x31C
    ctx->r25 = ADD32(ctx->r25, 0X31C);
    // 0x8006147C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80061480: addiu       $t0, $t0, -0x6A90
    ctx->r8 = ADD32(ctx->r8, -0X6A90);
    // 0x80061484: sw          $t8, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r24;
    // 0x80061488: lw          $t1, 0x9A0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X9A0);
    // 0x8006148C: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80061490: addiu       $t2, $t2, 0x31C
    ctx->r10 = ADD32(ctx->r10, 0X31C);
    // 0x80061494: sw          $t1, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r9;
L_80061498:
    // 0x80061498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006149C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800614A0: jr          $ra
    // 0x800614A4: nop

    return;
    // 0x800614A4: nop

;}

RECOMP_FUNC void Vi_StoreModeBankForTvType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800614A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800614AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800614B0: lui         $a0, 0x8
    ctx->r4 = S32(0X8 << 16);
    // 0x800614B4: jal         0x800B6A90
    // 0x800614B8: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800614B8: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    after_0:
    // 0x800614BC: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800614C0: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800614C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800614C8: bne         $t6, $zero, L_80061578
    if (ctx->r14 != 0) {
        // 0x800614CC: nop
    
            goto L_80061578;
    }
    // 0x800614CC: nop

    // 0x800614D0: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800614D4: addiu       $t7, $t7, 0x31C
    ctx->r15 = ADD32(ctx->r15, 0X31C);
    // 0x800614D8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800614DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800614E0: sw          $t8, -0x578($at)
    MEM_W(-0X578, ctx->r1) = ctx->r24;
    // 0x800614E4: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800614E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800614EC: sw          $t9, -0x560($at)
    MEM_W(-0X560, ctx->r1) = ctx->r25;
    // 0x800614F0: lw          $t0, 0x8($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X8);
    // 0x800614F4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800614F8: addiu       $t1, $t1, -0x580
    ctx->r9 = ADD32(ctx->r9, -0X580);
    // 0x800614FC: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80061500: addiu       $t2, $t2, 0x31C
    ctx->r10 = ADD32(ctx->r10, 0X31C);
    // 0x80061504: sw          $t0, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r8;
    // 0x80061508: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8006150C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80061510: addiu       $t4, $t4, -0x580
    ctx->r12 = ADD32(ctx->r12, -0X580);
    // 0x80061514: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80061518: addiu       $t5, $t5, 0x31C
    ctx->r13 = ADD32(ctx->r13, 0X31C);
    // 0x8006151C: sw          $t3, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->r11;
    // 0x80061520: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x80061524: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80061528: addiu       $t8, $t8, -0x580
    ctx->r24 = ADD32(ctx->r24, -0X580);
    // 0x8006152C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80061530: addiu       $t9, $t9, 0x31C
    ctx->r25 = ADD32(ctx->r25, 0X31C);
    // 0x80061534: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    // 0x80061538: lw          $t7, 0x14($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X14);
    // 0x8006153C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80061540: addiu       $t0, $t0, -0x580
    ctx->r8 = ADD32(ctx->r8, -0X580);
    // 0x80061544: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80061548: addiu       $t1, $t1, 0x31C
    ctx->r9 = ADD32(ctx->r9, 0X31C);
    // 0x8006154C: sw          $t7, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r15;
    // 0x80061550: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x80061554: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80061558: addiu       $t3, $t3, -0x580
    ctx->r11 = ADD32(ctx->r11, -0X580);
    // 0x8006155C: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80061560: addiu       $t4, $t4, 0x31C
    ctx->r12 = ADD32(ctx->r12, 0X31C);
    // 0x80061564: sw          $t2, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->r10;
    // 0x80061568: lw          $t5, 0x1C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C);
    // 0x8006156C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80061570: addiu       $t6, $t6, -0x580
    ctx->r14 = ADD32(ctx->r14, -0X580);
    // 0x80061574: sw          $t5, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r13;
L_80061578:
    // 0x80061578: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8006157C: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x80061580: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80061584: bne         $t8, $at, L_8006164C
    if (ctx->r24 != ctx->r1) {
        // 0x80061588: nop
    
            goto L_8006164C;
    }
    // 0x80061588: nop

    // 0x8006158C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80061590: addiu       $t9, $t9, 0x31C
    ctx->r25 = ADD32(ctx->r25, 0X31C);
    // 0x80061594: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80061598: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006159C: addiu       $t0, $t0, -0x6A90
    ctx->r8 = ADD32(ctx->r8, -0X6A90);
    // 0x800615A0: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800615A4: addiu       $t1, $t1, 0x31C
    ctx->r9 = ADD32(ctx->r9, 0X31C);
    // 0x800615A8: sw          $t7, 0xA8($t0)
    MEM_W(0XA8, ctx->r8) = ctx->r15;
    // 0x800615AC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800615B0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800615B4: addiu       $t3, $t3, -0x6A90
    ctx->r11 = ADD32(ctx->r11, -0X6A90);
    // 0x800615B8: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800615BC: addiu       $t4, $t4, 0x31C
    ctx->r12 = ADD32(ctx->r12, 0X31C);
    // 0x800615C0: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
    // 0x800615C4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800615C8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800615CC: addiu       $t6, $t6, -0x6A90
    ctx->r14 = ADD32(ctx->r14, -0X6A90);
    // 0x800615D0: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800615D4: addiu       $t8, $t8, 0x31C
    ctx->r24 = ADD32(ctx->r24, 0X31C);
    // 0x800615D8: sw          $t5, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->r13;
    // 0x800615DC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800615E0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800615E4: addiu       $t7, $t7, -0x6A90
    ctx->r15 = ADD32(ctx->r15, -0X6A90);
    // 0x800615E8: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800615EC: addiu       $t0, $t0, 0x31C
    ctx->r8 = ADD32(ctx->r8, 0X31C);
    // 0x800615F0: sw          $t9, 0xE4($t7)
    MEM_W(0XE4, ctx->r15) = ctx->r25;
    // 0x800615F4: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x800615F8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800615FC: addiu       $t2, $t2, -0x6A90
    ctx->r10 = ADD32(ctx->r10, -0X6A90);
    // 0x80061600: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80061604: addiu       $t3, $t3, 0x31C
    ctx->r11 = ADD32(ctx->r11, 0X31C);
    // 0x80061608: sw          $t1, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r9;
    // 0x8006160C: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x80061610: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80061614: addiu       $t5, $t5, -0x6A90
    ctx->r13 = ADD32(ctx->r13, -0X6A90);
    // 0x80061618: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8006161C: addiu       $t6, $t6, 0x31C
    ctx->r14 = ADD32(ctx->r14, 0X31C);
    // 0x80061620: sw          $t4, 0xDC($t5)
    MEM_W(0XDC, ctx->r13) = ctx->r12;
    // 0x80061624: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x80061628: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006162C: addiu       $t9, $t9, -0x6A90
    ctx->r25 = ADD32(ctx->r25, -0X6A90);
    // 0x80061630: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80061634: addiu       $t7, $t7, 0x31C
    ctx->r15 = ADD32(ctx->r15, 0X31C);
    // 0x80061638: sw          $t8, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->r24;
    // 0x8006163C: lw          $t0, 0x1C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X1C);
    // 0x80061640: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80061644: addiu       $t1, $t1, -0x6A90
    ctx->r9 = ADD32(ctx->r9, -0X6A90);
    // 0x80061648: sw          $t0, 0xE0($t1)
    MEM_W(0XE0, ctx->r9) = ctx->r8;
L_8006164C:
    // 0x8006164C: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80061650: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80061654: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80061658: bne         $t2, $at, L_80061720
    if (ctx->r10 != ctx->r1) {
        // 0x8006165C: nop
    
            goto L_80061720;
    }
    // 0x8006165C: nop

    // 0x80061660: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80061664: addiu       $t3, $t3, 0x31C
    ctx->r11 = ADD32(ctx->r11, 0X31C);
    // 0x80061668: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8006166C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80061670: addiu       $t5, $t5, -0x6A90
    ctx->r13 = ADD32(ctx->r13, -0X6A90);
    // 0x80061674: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80061678: addiu       $t6, $t6, 0x31C
    ctx->r14 = ADD32(ctx->r14, 0X31C);
    // 0x8006167C: sw          $t4, 0x968($t5)
    MEM_W(0X968, ctx->r13) = ctx->r12;
    // 0x80061680: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80061684: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80061688: addiu       $t9, $t9, -0x6A90
    ctx->r25 = ADD32(ctx->r25, -0X6A90);
    // 0x8006168C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80061690: addiu       $t7, $t7, 0x31C
    ctx->r15 = ADD32(ctx->r15, 0X31C);
    // 0x80061694: sw          $t8, 0x980($t9)
    MEM_W(0X980, ctx->r25) = ctx->r24;
    // 0x80061698: lw          $t0, 0x8($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X8);
    // 0x8006169C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800616A0: addiu       $t1, $t1, -0x6A90
    ctx->r9 = ADD32(ctx->r9, -0X6A90);
    // 0x800616A4: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800616A8: addiu       $t2, $t2, 0x31C
    ctx->r10 = ADD32(ctx->r10, 0X31C);
    // 0x800616AC: sw          $t0, 0x990($t1)
    MEM_W(0X990, ctx->r9) = ctx->r8;
    // 0x800616B0: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x800616B4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800616B8: addiu       $t4, $t4, -0x6A90
    ctx->r12 = ADD32(ctx->r12, -0X6A90);
    // 0x800616BC: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x800616C0: addiu       $t5, $t5, 0x31C
    ctx->r13 = ADD32(ctx->r13, 0X31C);
    // 0x800616C4: sw          $t3, 0x9A4($t4)
    MEM_W(0X9A4, ctx->r12) = ctx->r11;
    // 0x800616C8: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x800616CC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800616D0: addiu       $t8, $t8, -0x6A90
    ctx->r24 = ADD32(ctx->r24, -0X6A90);
    // 0x800616D4: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800616D8: addiu       $t9, $t9, 0x31C
    ctx->r25 = ADD32(ctx->r25, 0X31C);
    // 0x800616DC: sw          $t6, 0x988($t8)
    MEM_W(0X988, ctx->r24) = ctx->r14;
    // 0x800616E0: lw          $t7, 0x14($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X14);
    // 0x800616E4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800616E8: addiu       $t0, $t0, -0x6A90
    ctx->r8 = ADD32(ctx->r8, -0X6A90);
    // 0x800616EC: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800616F0: addiu       $t1, $t1, 0x31C
    ctx->r9 = ADD32(ctx->r9, 0X31C);
    // 0x800616F4: sw          $t7, 0x99C($t0)
    MEM_W(0X99C, ctx->r8) = ctx->r15;
    // 0x800616F8: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x800616FC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80061700: addiu       $t3, $t3, -0x6A90
    ctx->r11 = ADD32(ctx->r11, -0X6A90);
    // 0x80061704: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80061708: addiu       $t4, $t4, 0x31C
    ctx->r12 = ADD32(ctx->r12, 0X31C);
    // 0x8006170C: sw          $t2, 0x98C($t3)
    MEM_W(0X98C, ctx->r11) = ctx->r10;
    // 0x80061710: lw          $t5, 0x1C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C);
    // 0x80061714: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80061718: addiu       $t6, $t6, -0x6A90
    ctx->r14 = ADD32(ctx->r14, -0X6A90);
    // 0x8006171C: sw          $t5, 0x9A0($t6)
    MEM_W(0X9A0, ctx->r14) = ctx->r13;
L_80061720:
    // 0x80061720: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80061724: jal         0x800B6A90
    // 0x80061728: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80061728: nop

    after_1:
    // 0x8006172C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061730: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80061734: jr          $ra
    // 0x80061738: nop

    return;
    // 0x80061738: nop

    // 0x8006173C: nop

;}

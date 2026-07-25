#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void wonders4_SetupWonderTextBox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800476F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800476F4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800476F8: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x800476FC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80047700: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047704: lbu         $t7, 0x3F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3F);
    // 0x80047708: sb          $t6, 0x1F96($at)
    MEM_B(0X1F96, ctx->r1) = ctx->r14;
    // 0x8004770C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047710: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80047714: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80047718: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004771C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80047720: bne         $t7, $zero, L_80047778
    if (ctx->r15 != 0) {
        // 0x80047724: sb          $t7, 0x1F90($at)
        MEM_B(0X1F90, ctx->r1) = ctx->r15;
            goto L_80047778;
    }
    // 0x80047724: sb          $t7, 0x1F90($at)
    MEM_B(0X1F90, ctx->r1) = ctx->r15;
    // 0x80047728: addiu       $t8, $zero, 0x73
    ctx->r24 = ADD32(0, 0X73);
    // 0x8004772C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047730: sb          $t8, 0x1F94($at)
    MEM_B(0X1F94, ctx->r1) = ctx->r24;
    // 0x80047734: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80047738: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004773C: addiu       $t9, $zero, 0xC3
    ctx->r25 = ADD32(0, 0XC3);
    // 0x80047740: addiu       $t0, $t0, -0x4A0
    ctx->r8 = ADD32(ctx->r8, -0X4A0);
    // 0x80047744: sb          $t9, 0x1F95($at)
    MEM_B(0X1F95, ctx->r1) = ctx->r25;
    // 0x80047748: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x8004774C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80047750: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047754: addiu       $t3, $t2, -0x4
    ctx->r11 = ADD32(ctx->r10, -0X4);
    // 0x80047758: sb          $t3, 0x1F91($at)
    MEM_B(0X1F91, ctx->r1) = ctx->r11;
    // 0x8004775C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047760: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80047764: sb          $t4, 0x1F97($at)
    MEM_B(0X1F97, ctx->r1) = ctx->r12;
    // 0x80047768: lbu         $t5, 0x0($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X0);
    // 0x8004776C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047770: b           L_80047898
    // 0x80047774: sb          $t5, 0x1F98($at)
    MEM_B(0X1F98, ctx->r1) = ctx->r13;
        goto L_80047898;
    // 0x80047774: sb          $t5, 0x1F98($at)
    MEM_B(0X1F98, ctx->r1) = ctx->r13;
L_80047778:
    // 0x80047778: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004777C: lbu         $t7, 0x1F90($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1F90);
    // 0x80047780: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80047784: bne         $t7, $at, L_80047844
    if (ctx->r15 != ctx->r1) {
        // 0x80047788: nop
    
            goto L_80047844;
    }
    // 0x80047788: nop

    // 0x8004778C: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80047790: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047794: sb          $t8, 0x1F95($at)
    MEM_B(0X1F95, ctx->r1) = ctx->r24;
    // 0x80047798: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004779C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800477A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800477A4: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x800477A8: lbu         $a1, 0x1F96($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X1F96);
    // 0x800477AC: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x800477B0: jal         0x80079F74
    // 0x800477B4: sb          $t9, 0x1F97($at)
    MEM_B(0X1F97, ctx->r1) = ctx->r25;
    displayText_GetEntry(rdram, ctx);
        goto after_0;
    // 0x800477B4: sb          $t9, 0x1F97($at)
    MEM_B(0X1F97, ctx->r1) = ctx->r25;
    after_0:
    // 0x800477B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800477BC: slti        $at, $s1, 0xA
    ctx->r1 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x800477C0: beq         $at, $zero, L_80047820
    if (ctx->r1 == 0) {
        // 0x800477C4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80047820;
    }
    // 0x800477C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800477C8:
    // 0x800477C8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800477CC: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800477D0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800477D4: addu        $s0, $s2, $t6
    ctx->r16 = ADD32(ctx->r18, ctx->r14);
    // 0x800477D8: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x800477DC: nop

    // 0x800477E0: beq         $t0, $zero, L_80047820
    if (ctx->r8 == 0) {
        // 0x800477E4: nop
    
            goto L_80047820;
    }
    // 0x800477E4: nop

    // 0x800477E8: lbu         $t2, 0xA($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XA);
    // 0x800477EC: nop

    // 0x800477F0: beq         $t2, $zero, L_80047820
    if (ctx->r10 == 0) {
        // 0x800477F4: nop
    
            goto L_80047820;
    }
    // 0x800477F4: nop

    // 0x800477F8: lbu         $t3, 0xA($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XA);
    // 0x800477FC: nop

    // 0x80047800: beq         $t3, $zero, L_80047820
    if (ctx->r11 == 0) {
        // 0x80047804: nop
    
            goto L_80047820;
    }
    // 0x80047804: nop

    // 0x80047808: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004780C: andi        $t4, $s1, 0xFF
    ctx->r12 = ctx->r17 & 0XFF;
    // 0x80047810: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x80047814: slti        $at, $s1, 0xA
    ctx->r1 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x80047818: bne         $at, $zero, L_800477C8
    if (ctx->r1 != 0) {
        // 0x8004781C: nop
    
            goto L_800477C8;
    }
    // 0x8004781C: nop

L_80047820:
    // 0x80047820: sll         $t1, $s1, 1
    ctx->r9 = S32(ctx->r17 << 1);
    // 0x80047824: addiu       $t5, $t1, 0x13
    ctx->r13 = ADD32(ctx->r9, 0X13);
    // 0x80047828: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004782C: sb          $t5, 0x1F98($at)
    MEM_B(0X1F98, ctx->r1) = ctx->r13;
    // 0x80047830: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x80047834: addiu       $t8, $t7, -0xF
    ctx->r24 = ADD32(ctx->r15, -0XF);
    // 0x80047838: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004783C: b           L_80047898
    // 0x80047840: sb          $t8, 0x1F91($at)
    MEM_B(0X1F91, ctx->r1) = ctx->r24;
        goto L_80047898;
    // 0x80047840: sb          $t8, 0x1F91($at)
    MEM_B(0X1F91, ctx->r1) = ctx->r24;
L_80047844:
    // 0x80047844: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80047848: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004784C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80047850: lbu         $t0, 0x1F96($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X1F96);
    // 0x80047854: sb          $t9, 0x1F94($at)
    MEM_B(0X1F94, ctx->r1) = ctx->r25;
    // 0x80047858: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8004785C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047860: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80047864: addiu       $t2, $t2, -0x4A0
    ctx->r10 = ADD32(ctx->r10, -0X4A0);
    // 0x80047868: sb          $t6, 0x1F95($at)
    MEM_B(0X1F95, ctx->r1) = ctx->r14;
    // 0x8004786C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80047870: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80047874: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047878: addiu       $t1, $t4, -0x4
    ctx->r9 = ADD32(ctx->r12, -0X4);
    // 0x8004787C: sb          $t1, 0x1F91($at)
    MEM_B(0X1F91, ctx->r1) = ctx->r9;
    // 0x80047880: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047884: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80047888: sb          $t5, 0x1F97($at)
    MEM_B(0X1F97, ctx->r1) = ctx->r13;
    // 0x8004788C: lbu         $t7, 0x0($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X0);
    // 0x80047890: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047894: sb          $t7, 0x1F98($at)
    MEM_B(0X1F98, ctx->r1) = ctx->r15;
L_80047898:
    // 0x80047898: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004789C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800478A0: sb          $zero, 0x1F92($at)
    MEM_B(0X1F92, ctx->r1) = 0;
    // 0x800478A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800478A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800478AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800478B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800478B4: sb          $zero, 0x1F93($at)
    MEM_B(0X1F93, ctx->r1) = 0;
    // 0x800478B8: jr          $ra
    // 0x800478BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800478BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void wonders4_display_contributors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800478C0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800478C4: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800478C8: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800478CC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800478D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800478D4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800478D8: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x800478DC: lbu         $a1, 0x1F96($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X1F96);
    // 0x800478E0: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800478E4: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800478E8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800478EC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800478F0: jal         0x80079F74
    // 0x800478F4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    displayText_GetEntry(rdram, ctx);
        goto after_0;
    // 0x800478F4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    after_0:
    // 0x800478F8: lbu         $t6, 0x87($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X87);
    // 0x800478FC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80047900: bne         $t6, $zero, L_80047940
    if (ctx->r14 != 0) {
        // 0x80047904: nop
    
            goto L_80047940;
    }
    // 0x80047904: nop

    // 0x80047908: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004790C: addiu       $a1, $a1, -0x4970
    ctx->r5 = ADD32(ctx->r5, -0X4970);
    // 0x80047910: jal         0x800B62D4
    // 0x80047914: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x80047914: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    after_1:
    // 0x80047918: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004791C: addiu       $a1, $a1, -0x496C
    ctx->r5 = ADD32(ctx->r5, -0X496C);
    // 0x80047920: jal         0x800B62D4
    // 0x80047924: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x80047924: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_2:
    // 0x80047928: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004792C: addiu       $a1, $a1, -0x4958
    ctx->r5 = ADD32(ctx->r5, -0X4958);
    // 0x80047930: jal         0x800B62D4
    // 0x80047934: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x80047934: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x80047938: b           L_80047B34
    // 0x8004793C: nop

        goto L_80047B34;
    // 0x8004793C: nop

L_80047940:
    // 0x80047940: lbu         $t7, 0x87($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X87);
    // 0x80047944: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80047948: bne         $t7, $at, L_80047988
    if (ctx->r15 != ctx->r1) {
        // 0x8004794C: nop
    
            goto L_80047988;
    }
    // 0x8004794C: nop

    // 0x80047950: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047954: addiu       $a1, $a1, -0x4954
    ctx->r5 = ADD32(ctx->r5, -0X4954);
    // 0x80047958: jal         0x800B62D4
    // 0x8004795C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x8004795C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    after_4:
    // 0x80047960: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047964: addiu       $a1, $a1, -0x4950
    ctx->r5 = ADD32(ctx->r5, -0X4950);
    // 0x80047968: jal         0x800B62D4
    // 0x8004796C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x8004796C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_5:
    // 0x80047970: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047974: addiu       $a1, $a1, -0x4948
    ctx->r5 = ADD32(ctx->r5, -0X4948);
    // 0x80047978: jal         0x800B62D4
    // 0x8004797C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_6;
    // 0x8004797C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_6:
    // 0x80047980: b           L_80047B34
    // 0x80047984: nop

        goto L_80047B34;
    // 0x80047984: nop

L_80047988:
    // 0x80047988: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
    // 0x8004798C: nop

    // 0x80047990: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80047994: bne         $at, $zero, L_80047B04
    if (ctx->r1 != 0) {
        // 0x80047998: nop
    
            goto L_80047B04;
    }
    // 0x80047998: nop

    // 0x8004799C: addiu       $t9, $t8, -0x4
    ctx->r25 = ADD32(ctx->r24, -0X4);
    // 0x800479A0: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800479A4: sb          $t9, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r25;
    // 0x800479A8: bgez        $t0, L_800479BC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800479AC: andi        $t1, $t0, 0x1
        ctx->r9 = ctx->r8 & 0X1;
            goto L_800479BC;
    }
    // 0x800479AC: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800479B0: beq         $t1, $zero, L_800479BC
    if (ctx->r9 == 0) {
        // 0x800479B4: nop
    
            goto L_800479BC;
    }
    // 0x800479B4: nop

    // 0x800479B8: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
L_800479BC:
    // 0x800479BC: bne         $t1, $zero, L_80047ACC
    if (ctx->r9 != 0) {
        // 0x800479C0: nop
    
            goto L_80047ACC;
    }
    // 0x800479C0: nop

    // 0x800479C4: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x800479C8: bgez        $t2, L_800479D8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800479CC: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800479D8;
    }
    // 0x800479CC: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800479D0: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800479D4: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800479D8:
    // 0x800479D8: slti        $at, $t3, 0xA
    ctx->r1 = SIGNED(ctx->r11) < 0XA ? 1 : 0;
    // 0x800479DC: beq         $at, $zero, L_80047ACC
    if (ctx->r1 == 0) {
        // 0x800479E0: nop
    
            goto L_80047ACC;
    }
    // 0x800479E0: nop

    // 0x800479E4: andi        $t4, $t9, 0xFF
    ctx->r12 = ctx->r25 & 0XFF;
    // 0x800479E8: bgez        $t4, L_800479F8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800479EC: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_800479F8;
    }
    // 0x800479EC: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800479F0: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x800479F4: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800479F8:
    // 0x800479F8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800479FC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80047A00: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80047A04: addu        $s0, $s2, $t6
    ctx->r16 = ADD32(ctx->r18, ctx->r14);
    // 0x80047A08: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80047A0C: nop

    // 0x80047A10: beq         $t7, $zero, L_80047A38
    if (ctx->r15 == 0) {
        // 0x80047A14: nop
    
            goto L_80047A38;
    }
    // 0x80047A14: nop

    // 0x80047A18: lbu         $t8, 0xA($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XA);
    // 0x80047A1C: nop

    // 0x80047A20: beq         $t8, $zero, L_80047A38
    if (ctx->r24 == 0) {
        // 0x80047A24: nop
    
            goto L_80047A38;
    }
    // 0x80047A24: nop

    // 0x80047A28: lbu         $t0, 0xA($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XA);
    // 0x80047A2C: nop

    // 0x80047A30: bne         $t0, $zero, L_80047A70
    if (ctx->r8 != 0) {
        // 0x80047A34: nop
    
            goto L_80047A70;
    }
    // 0x80047A34: nop

L_80047A38:
    // 0x80047A38: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047A3C: addiu       $a1, $a1, -0x4940
    ctx->r5 = ADD32(ctx->r5, -0X4940);
    // 0x80047A40: jal         0x800B62D4
    // 0x80047A44: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x80047A44: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    after_7:
    // 0x80047A48: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047A4C: addiu       $a1, $a1, -0x493C
    ctx->r5 = ADD32(ctx->r5, -0X493C);
    // 0x80047A50: jal         0x800B62D4
    // 0x80047A54: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x80047A54: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_8:
    // 0x80047A58: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047A5C: addiu       $a1, $a1, -0x4938
    ctx->r5 = ADD32(ctx->r5, -0X4938);
    // 0x80047A60: jal         0x800B62D4
    // 0x80047A64: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_9;
    // 0x80047A64: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_9:
    // 0x80047A68: b           L_80047B34
    // 0x80047A6C: nop

        goto L_80047B34;
    // 0x80047A6C: nop

L_80047A70:
    // 0x80047A70: lbu         $a2, 0x87($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X87);
    // 0x80047A74: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047A78: addiu       $a1, $a1, -0x4934
    ctx->r5 = ADD32(ctx->r5, -0X4934);
    // 0x80047A7C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80047A80: bgez        $a2, L_80047A90
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80047A84: sra         $t1, $a2, 1
        ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80047A90;
    }
    // 0x80047A84: sra         $t1, $a2, 1
    ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80047A88: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x80047A8C: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80047A90:
    // 0x80047A90: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80047A94: jal         0x800B62D4
    // 0x80047A98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_10;
    // 0x80047A98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_10:
    // 0x80047A9C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047AA0: addiu       $a1, $a1, -0x4930
    ctx->r5 = ADD32(ctx->r5, -0X4930);
    // 0x80047AA4: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80047AA8: jal         0x800B62D4
    // 0x80047AAC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_11;
    // 0x80047AAC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x80047AB0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047AB4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80047AB8: addiu       $a1, $a1, -0x4928
    ctx->r5 = ADD32(ctx->r5, -0X4928);
    // 0x80047ABC: jal         0x800B62D4
    // 0x80047AC0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_12;
    // 0x80047AC0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_12:
    // 0x80047AC4: b           L_80047B34
    // 0x80047AC8: nop

        goto L_80047B34;
    // 0x80047AC8: nop

L_80047ACC:
    // 0x80047ACC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047AD0: addiu       $a1, $a1, -0x4920
    ctx->r5 = ADD32(ctx->r5, -0X4920);
    // 0x80047AD4: jal         0x800B62D4
    // 0x80047AD8: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    sprintf_recomp(rdram, ctx);
        goto after_13;
    // 0x80047AD8: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    after_13:
    // 0x80047ADC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047AE0: addiu       $a1, $a1, -0x491C
    ctx->r5 = ADD32(ctx->r5, -0X491C);
    // 0x80047AE4: jal         0x800B62D4
    // 0x80047AE8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    sprintf_recomp(rdram, ctx);
        goto after_14;
    // 0x80047AE8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_14:
    // 0x80047AEC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047AF0: addiu       $a1, $a1, -0x4918
    ctx->r5 = ADD32(ctx->r5, -0X4918);
    // 0x80047AF4: jal         0x800B62D4
    // 0x80047AF8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_15;
    // 0x80047AF8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_15:
    // 0x80047AFC: b           L_80047B34
    // 0x80047B00: nop

        goto L_80047B34;
    // 0x80047B00: nop

L_80047B04:
    // 0x80047B04: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047B08: addiu       $a1, $a1, -0x4914
    ctx->r5 = ADD32(ctx->r5, -0X4914);
    // 0x80047B0C: jal         0x800B62D4
    // 0x80047B10: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    sprintf_recomp(rdram, ctx);
        goto after_16;
    // 0x80047B10: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    after_16:
    // 0x80047B14: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047B18: addiu       $a1, $a1, -0x4910
    ctx->r5 = ADD32(ctx->r5, -0X4910);
    // 0x80047B1C: jal         0x800B62D4
    // 0x80047B20: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    sprintf_recomp(rdram, ctx);
        goto after_17;
    // 0x80047B20: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_17:
    // 0x80047B24: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047B28: addiu       $a1, $a1, -0x490C
    ctx->r5 = ADD32(ctx->r5, -0X490C);
    // 0x80047B2C: jal         0x800B62D4
    // 0x80047B30: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_18;
    // 0x80047B30: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_18:
L_80047B34:
    // 0x80047B34: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80047B38: jal         0x80077D88
    // 0x80047B3C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    Font_GetTextWidth(rdram, ctx);
        goto after_19;
    // 0x80047B3C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_19:
    // 0x80047B40: addiu       $t2, $zero, 0x14A
    ctx->r10 = ADD32(0, 0X14A);
    // 0x80047B44: lhu         $t8, 0x8E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X8E);
    // 0x80047B48: lhu         $t0, 0x92($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X92);
    // 0x80047B4C: subu        $s1, $t2, $v0
    ctx->r17 = SUB32(ctx->r10, ctx->r2);
    // 0x80047B50: andi        $t3, $s1, 0xFFFF
    ctx->r11 = ctx->r17 & 0XFFFF;
    // 0x80047B54: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047B58: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x80047B5C: lhu         $a3, 0x8A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X8A);
    // 0x80047B60: addiu       $t9, $sp, 0x70
    ctx->r25 = ADD32(ctx->r29, 0X70);
    // 0x80047B64: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80047B68: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80047B6C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80047B70: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80047B74: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80047B78: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80047B7C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80047B80: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80047B84: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80047B88: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80047B8C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80047B90: addiu       $a2, $zero, 0x39
    ctx->r6 = ADD32(0, 0X39);
    // 0x80047B94: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80047B98: jal         0x80077EE0
    // 0x80047B9C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    displayText_DrawString(rdram, ctx);
        goto after_20;
    // 0x80047B9C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_20:
    // 0x80047BA0: lhu         $t5, 0x8E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X8E);
    // 0x80047BA4: lhu         $t6, 0x92($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X92);
    // 0x80047BA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047BAC: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x80047BB0: lhu         $a3, 0x8A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X8A);
    // 0x80047BB4: addiu       $t1, $sp, 0x5C
    ctx->r9 = ADD32(ctx->r29, 0X5C);
    // 0x80047BB8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80047BBC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80047BC0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80047BC4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80047BC8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80047BCC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80047BD0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80047BD4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80047BD8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80047BDC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80047BE0: addiu       $a2, $zero, 0x55
    ctx->r6 = ADD32(0, 0X55);
    // 0x80047BE4: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80047BE8: jal         0x80077EE0
    // 0x80047BEC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    displayText_DrawString(rdram, ctx);
        goto after_21;
    // 0x80047BEC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_21:
    // 0x80047BF0: lhu         $t3, 0x8E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X8E);
    // 0x80047BF4: lhu         $t9, 0x92($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X92);
    // 0x80047BF8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047BFC: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x80047C00: lhu         $a3, 0x8A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X8A);
    // 0x80047C04: addiu       $t7, $sp, 0x48
    ctx->r15 = ADD32(ctx->r29, 0X48);
    // 0x80047C08: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80047C0C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80047C10: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80047C14: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80047C18: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80047C1C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80047C20: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80047C24: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80047C28: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80047C2C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80047C30: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80047C34: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80047C38: jal         0x80077EE0
    // 0x80047C3C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    displayText_DrawString(rdram, ctx);
        goto after_22;
    // 0x80047C3C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    after_22:
    // 0x80047C40: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80047C44: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80047C48: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80047C4C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80047C50: jr          $ra
    // 0x80047C54: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80047C54: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}

RECOMP_FUNC void wonders4_display_contribs_or_story(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047C58: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80047C5C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80047C60: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80047C64: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80047C68: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80047C6C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80047C70: lbu         $t7, 0x1F90($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1F90);
    // 0x80047C74: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80047C78: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80047C7C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80047C80: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80047C84: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80047C88: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80047C8C: lbu         $s1, 0x1F95($s1)
    ctx->r17 = MEM_BU(ctx->r17, 0X1F95);
    // 0x80047C90: lbu         $s3, 0x1F91($s3)
    ctx->r19 = MEM_BU(ctx->r19, 0X1F91);
    // 0x80047C94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80047C98: lbu         $s2, 0x77($t6)
    ctx->r18 = MEM_BU(ctx->r14, 0X77);
    // 0x80047C9C: bne         $t7, $at, L_80047CCC
    if (ctx->r15 != ctx->r1) {
        // 0x80047CA0: nop
    
            goto L_80047CCC;
    }
    // 0x80047CA0: nop

    // 0x80047CA4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80047CA8: lbu         $a3, 0x1F92($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X1F92);
    // 0x80047CAC: addiu       $t8, $s2, -0x1
    ctx->r24 = ADD32(ctx->r18, -0X1);
    // 0x80047CB0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80047CB4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80047CB8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80047CBC: jal         0x800478C0
    // 0x80047CC0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    wonders4_display_contributors(rdram, ctx);
        goto after_0;
    // 0x80047CC0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x80047CC4: b           L_80047D58
    // 0x80047CC8: nop

        goto L_80047D58;
    // 0x80047CC8: nop

L_80047CCC:
    // 0x80047CCC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80047CD0: lbu         $t9, 0x1F96($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1F96);
    // 0x80047CD4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80047CD8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80047CDC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80047CE0: lw          $t1, -0x2E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E8);
    // 0x80047CE4: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x80047CE8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80047CEC: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x80047CF0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047CF4: addiu       $a1, $a1, -0x4908
    ctx->r5 = ADD32(ctx->r5, -0X4908);
    // 0x80047CF8: jal         0x800B62D4
    // 0x80047CFC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x80047CFC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x80047D00: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80047D04: lbu         $t9, 0x1F92($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1F92);
    // 0x80047D08: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80047D0C: lbu         $a2, 0x1F94($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X1F94);
    // 0x80047D10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047D14: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80047D18: addiu       $t4, $sp, 0x54
    ctx->r12 = ADD32(ctx->r29, 0X54);
    // 0x80047D1C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80047D20: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80047D24: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80047D28: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80047D2C: addiu       $t0, $s2, -0x1
    ctx->r8 = ADD32(ctx->r18, -0X1);
    // 0x80047D30: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80047D34: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80047D38: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80047D3C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80047D40: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80047D44: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80047D48: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80047D4C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80047D50: jal         0x80077EE0
    // 0x80047D54: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    displayText_DrawString(rdram, ctx);
        goto after_2;
    // 0x80047D54: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_2:
L_80047D58:
    // 0x80047D58: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80047D5C: lbu         $t1, 0x1F92($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1F92);
    // 0x80047D60: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80047D64: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80047D68: subu        $t2, $s2, $t1
    ctx->r10 = SUB32(ctx->r18, ctx->r9);
    // 0x80047D6C: lbu         $t5, 0x1F98($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X1F98);
    // 0x80047D70: addu        $s1, $s1, $t2
    ctx->r17 = ADD32(ctx->r17, ctx->r10);
    // 0x80047D74: andi        $t4, $s3, 0xFF
    ctx->r12 = ctx->r19 & 0XFF;
    // 0x80047D78: andi        $t3, $s1, 0xFF
    ctx->r11 = ctx->r17 & 0XFF;
    // 0x80047D7C: or          $s3, $t4, $zero
    ctx->r19 = ctx->r12 | 0;
    // 0x80047D80: bne         $s3, $t5, L_80047D8C
    if (ctx->r19 != ctx->r13) {
        // 0x80047D84: or          $s1, $t3, $zero
        ctx->r17 = ctx->r11 | 0;
            goto L_80047D8C;
    }
    // 0x80047D84: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80047D88: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80047D8C:
    // 0x80047D8C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80047D90: lbu         $t7, 0x1F97($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1F97);
    // 0x80047D94: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80047D98: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80047D9C: beq         $at, $zero, L_80047E9C
    if (ctx->r1 == 0) {
        // 0x80047DA0: nop
    
            goto L_80047E9C;
    }
    // 0x80047DA0: nop

L_80047DA4:
    // 0x80047DA4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80047DA8: lbu         $t6, 0x1F90($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1F90);
    // 0x80047DAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80047DB0: bne         $t6, $at, L_80047DDC
    if (ctx->r14 != ctx->r1) {
        // 0x80047DB4: nop
    
            goto L_80047DDC;
    }
    // 0x80047DB4: nop

    // 0x80047DB8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80047DBC: addiu       $t8, $s2, -0x1
    ctx->r24 = ADD32(ctx->r18, -0X1);
    // 0x80047DC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80047DC4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80047DC8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80047DCC: jal         0x800478C0
    // 0x80047DD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    wonders4_display_contributors(rdram, ctx);
        goto after_3;
    // 0x80047DD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80047DD4: b           L_80047E54
    // 0x80047DD8: nop

        goto L_80047E54;
    // 0x80047DD8: nop

L_80047DDC:
    // 0x80047DDC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80047DE0: lbu         $t9, 0x1F96($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1F96);
    // 0x80047DE4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80047DE8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80047DEC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80047DF0: lw          $t1, -0x2E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E8);
    // 0x80047DF4: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x80047DF8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80047DFC: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x80047E00: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047E04: addiu       $a1, $a1, -0x4904
    ctx->r5 = ADD32(ctx->r5, -0X4904);
    // 0x80047E08: jal         0x800B62D4
    // 0x80047E0C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x80047E0C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_4:
    // 0x80047E10: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80047E14: lbu         $a2, 0x1F94($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X1F94);
    // 0x80047E18: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047E1C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80047E20: addiu       $t4, $sp, 0x54
    ctx->r12 = ADD32(ctx->r29, 0X54);
    // 0x80047E24: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80047E28: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80047E2C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80047E30: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80047E34: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80047E38: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80047E3C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80047E40: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80047E44: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80047E48: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80047E4C: jal         0x80077960
    // 0x80047E50: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_5;
    // 0x80047E50: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_5:
L_80047E54:
    // 0x80047E54: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80047E58: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80047E5C: lbu         $t1, 0x1F98($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1F98);
    // 0x80047E60: addu        $s1, $s1, $s2
    ctx->r17 = ADD32(ctx->r17, ctx->r18);
    // 0x80047E64: andi        $t0, $s3, 0xFF
    ctx->r8 = ctx->r19 & 0XFF;
    // 0x80047E68: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
    // 0x80047E6C: or          $s3, $t0, $zero
    ctx->r19 = ctx->r8 | 0;
    // 0x80047E70: bne         $s3, $t1, L_80047E7C
    if (ctx->r19 != ctx->r9) {
        // 0x80047E74: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80047E7C;
    }
    // 0x80047E74: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80047E78: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80047E7C:
    // 0x80047E7C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80047E80: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80047E84: lbu         $t3, 0x1F97($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X1F97);
    // 0x80047E88: andi        $t2, $s0, 0xFF
    ctx->r10 = ctx->r16 & 0XFF;
    // 0x80047E8C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80047E90: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80047E94: bne         $at, $zero, L_80047DA4
    if (ctx->r1 != 0) {
        // 0x80047E98: nop
    
            goto L_80047DA4;
    }
    // 0x80047E98: nop

L_80047E9C:
    // 0x80047E9C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80047EA0: lbu         $t4, 0x1F90($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X1F90);
    // 0x80047EA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80047EA8: bne         $t4, $at, L_80047ED8
    if (ctx->r12 != ctx->r1) {
        // 0x80047EAC: nop
    
            goto L_80047ED8;
    }
    // 0x80047EAC: nop

    // 0x80047EB0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80047EB4: lbu         $t5, 0x1F92($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X1F92);
    // 0x80047EB8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80047EBC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80047EC0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80047EC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80047EC8: jal         0x800478C0
    // 0x80047ECC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    wonders4_display_contributors(rdram, ctx);
        goto after_6;
    // 0x80047ECC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_6:
    // 0x80047ED0: b           L_80047F60
    // 0x80047ED4: nop

        goto L_80047F60;
    // 0x80047ED4: nop

L_80047ED8:
    // 0x80047ED8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80047EDC: lbu         $t7, 0x1F96($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1F96);
    // 0x80047EE0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80047EE4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80047EE8: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80047EEC: lw          $t8, -0x2E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E8);
    // 0x80047EF0: sll         $t9, $s3, 2
    ctx->r25 = S32(ctx->r19 << 2);
    // 0x80047EF4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80047EF8: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80047EFC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80047F00: addiu       $a1, $a1, -0x4900
    ctx->r5 = ADD32(ctx->r5, -0X4900);
    // 0x80047F04: jal         0x800B62D4
    // 0x80047F08: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x80047F08: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_7:
    // 0x80047F0C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80047F10: lbu         $t7, 0x1F92($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1F92);
    // 0x80047F14: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80047F18: lbu         $a2, 0x1F94($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X1F94);
    // 0x80047F1C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047F20: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80047F24: addiu       $t1, $sp, 0x54
    ctx->r9 = ADD32(ctx->r29, 0X54);
    // 0x80047F28: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80047F2C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80047F30: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80047F34: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80047F38: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80047F3C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80047F40: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80047F44: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80047F48: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80047F4C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80047F50: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80047F54: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80047F58: jal         0x80077EE0
    // 0x80047F5C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    displayText_DrawString(rdram, ctx);
        goto after_8;
    // 0x80047F5C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_8:
L_80047F60:
    // 0x80047F60: jal         0x800A3AF0
    // 0x80047F64: nop

    frametime_delta(rdram, ctx);
        goto after_9;
    // 0x80047F64: nop

    after_9:
    // 0x80047F68: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80047F6C: lbu         $t6, 0x1F93($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1F93);
    // 0x80047F70: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80047F74: addu        $t8, $t6, $s4
    ctx->r24 = ADD32(ctx->r14, ctx->r20);
    // 0x80047F78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047F7C: sb          $t8, 0x1F93($at)
    MEM_B(0X1F93, ctx->r1) = ctx->r24;
    // 0x80047F80: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80047F84: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x80047F88: bne         $at, $zero, L_80047FF8
    if (ctx->r1 != 0) {
        // 0x80047F8C: nop
    
            goto L_80047FF8;
    }
    // 0x80047F8C: nop

    // 0x80047F90: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80047F94: lbu         $t0, 0x1F92($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X1F92);
    // 0x80047F98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047F9C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80047FA0: sb          $t1, 0x1F92($at)
    MEM_B(0X1F92, ctx->r1) = ctx->r9;
    // 0x80047FA4: andi        $t2, $t8, 0xFF
    ctx->r10 = ctx->r24 & 0XFF;
    // 0x80047FA8: addiu       $t3, $t2, -0x8
    ctx->r11 = ADD32(ctx->r10, -0X8);
    // 0x80047FAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047FB0: sb          $t3, 0x1F93($at)
    MEM_B(0X1F93, ctx->r1) = ctx->r11;
    // 0x80047FB4: andi        $t4, $t1, 0xFF
    ctx->r12 = ctx->r9 & 0XFF;
    // 0x80047FB8: slt         $at, $t4, $s2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80047FBC: bne         $at, $zero, L_80047FF8
    if (ctx->r1 != 0) {
        // 0x80047FC0: nop
    
            goto L_80047FF8;
    }
    // 0x80047FC0: nop

    // 0x80047FC4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80047FC8: lbu         $t5, 0x1F91($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X1F91);
    // 0x80047FCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047FD0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80047FD4: lbu         $t9, 0x1F98($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1F98);
    // 0x80047FD8: sb          $zero, 0x1F92($at)
    MEM_B(0X1F92, ctx->r1) = 0;
    // 0x80047FDC: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80047FE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047FE4: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x80047FE8: bne         $t6, $t9, L_80047FF8
    if (ctx->r14 != ctx->r25) {
        // 0x80047FEC: sb          $t7, 0x1F91($at)
        MEM_B(0X1F91, ctx->r1) = ctx->r15;
            goto L_80047FF8;
    }
    // 0x80047FEC: sb          $t7, 0x1F91($at)
    MEM_B(0X1F91, ctx->r1) = ctx->r15;
    // 0x80047FF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047FF4: sb          $zero, 0x1F91($at)
    MEM_B(0X1F91, ctx->r1) = 0;
L_80047FF8:
    // 0x80047FF8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80047FFC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80048000: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80048004: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80048008: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8004800C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80048010: jr          $ra
    // 0x80048014: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80048014: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80048018: nop

    // 0x8004801C: nop

;}

RECOMP_FUNC void wonders4_UpdateMaxScroll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048020: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048024: lw          $t6, 0x20C4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C4);
    // 0x80048028: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8004802C: beq         $t6, $zero, L_80048078
    if (ctx->r14 == 0) {
        // 0x80048030: nop
    
            goto L_80048078;
    }
    // 0x80048030: nop

    // 0x80048034: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80048038: lhu         $t8, 0x20B0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X20B0);
    // 0x8004803C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048040: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80048044: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80048048: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004804C: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x80048050: lw          $t0, 0x20B8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X20B8);
    // 0x80048054: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80048058: subu        $a0, $t7, $t0
    ctx->r4 = SUB32(ctx->r15, ctx->r8);
    // 0x8004805C: lw          $t2, -0x2C0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2C0);
    // 0x80048060: sra         $t1, $a0, 3
    ctx->r9 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80048064: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80048068: sltu        $at, $t2, $a0
    ctx->r1 = ctx->r10 < ctx->r4 ? 1 : 0;
    // 0x8004806C: beq         $at, $zero, L_80048078
    if (ctx->r1 == 0) {
        // 0x80048070: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80048078;
    }
    // 0x80048070: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80048074: sw          $a0, -0x2C0($at)
    MEM_W(-0X2C0, ctx->r1) = ctx->r4;
L_80048078:
    // 0x80048078: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8004807C: lw          $t3, 0x20D4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20D4);
    // 0x80048080: nop

    // 0x80048084: beq         $t3, $zero, L_800480D0
    if (ctx->r11 == 0) {
        // 0x80048088: nop
    
            goto L_800480D0;
    }
    // 0x80048088: nop

    // 0x8004808C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80048090: lhu         $t5, 0x20B0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X20B0);
    // 0x80048094: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80048098: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8004809C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800480A0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800480A4: lw          $t4, 0x20D0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20D0);
    // 0x800480A8: lw          $t8, 0x20C8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X20C8);
    // 0x800480AC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800480B0: subu        $a0, $t4, $t8
    ctx->r4 = SUB32(ctx->r12, ctx->r24);
    // 0x800480B4: lw          $t7, -0x2BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BC);
    // 0x800480B8: sra         $t9, $a0, 4
    ctx->r25 = S32(SIGNED(ctx->r4) >> 4);
    // 0x800480BC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800480C0: sltu        $at, $t7, $a0
    ctx->r1 = ctx->r15 < ctx->r4 ? 1 : 0;
    // 0x800480C4: beq         $at, $zero, L_800480D0
    if (ctx->r1 == 0) {
        // 0x800480C8: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800480D0;
    }
    // 0x800480C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800480CC: sw          $a0, -0x2BC($at)
    MEM_W(-0X2BC, ctx->r1) = ctx->r4;
L_800480D0:
    // 0x800480D0: jr          $ra
    // 0x800480D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800480D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void func_800480D8_nevercalled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800480D8: jr          $ra
    // 0x800480DC: nop

    return;
    // 0x800480DC: nop

;}

RECOMP_FUNC void wonders4_DebugPrintGList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800480E0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800480E4: lhu         $t7, 0x20B0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X20B0);
    // 0x800480E8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800480EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800480F0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800480F4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800480F8: lw          $t0, 0x20C4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X20C4);
    // 0x800480FC: lw          $t9, 0x20B8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20B8);
    // 0x80048100: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048104: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80048108: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8004810C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80048110: sltu        $at, $t1, $t6
    ctx->r1 = ctx->r9 < ctx->r14 ? 1 : 0;
    // 0x80048114: beq         $at, $zero, L_80048140
    if (ctx->r1 == 0) {
        // 0x80048118: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80048140;
    }
    // 0x80048118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004811C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80048120: addiu       $a1, $a1, -0x3FE0
    ctx->r5 = ADD32(ctx->r5, -0X3FE0);
    // 0x80048124: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80048128: jal         0x800B62D4
    // 0x8004812C: srl         $a2, $t0, 3
    ctx->r6 = S32(U32(ctx->r8) >> 3);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8004812C: srl         $a2, $t0, 3
    ctx->r6 = S32(U32(ctx->r8) >> 3);
    after_0:
    // 0x80048130: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80048134: addiu       $a0, $a0, -0x3FD0
    ctx->r4 = ADD32(ctx->r4, -0X3FD0);
    // 0x80048138: jal         0x80083560
    // 0x8004813C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    debug_print_reason_routine(rdram, ctx);
        goto after_1;
    // 0x8004813C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
L_80048140:
    // 0x80048140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048144: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80048148: jr          $ra
    // 0x8004814C: nop

    return;
    // 0x8004814C: nop

;}

RECOMP_FUNC void wonders4_DebugPrintVList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048150: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80048154: lhu         $t7, 0x20B0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X20B0);
    // 0x80048158: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8004815C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80048160: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80048164: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048168: lw          $t0, 0x20D4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X20D4);
    // 0x8004816C: lw          $t9, 0x20C8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20C8);
    // 0x80048170: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048174: lw          $t6, 0x20D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20D0);
    // 0x80048178: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8004817C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80048180: sltu        $at, $t1, $t6
    ctx->r1 = ctx->r9 < ctx->r14 ? 1 : 0;
    // 0x80048184: beq         $at, $zero, L_800481B0
    if (ctx->r1 == 0) {
        // 0x80048188: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800481B0;
    }
    // 0x80048188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004818C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80048190: addiu       $a1, $a1, -0x3FC0
    ctx->r5 = ADD32(ctx->r5, -0X3FC0);
    // 0x80048194: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80048198: jal         0x800B62D4
    // 0x8004819C: srl         $a2, $t0, 4
    ctx->r6 = S32(U32(ctx->r8) >> 4);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8004819C: srl         $a2, $t0, 4
    ctx->r6 = S32(U32(ctx->r8) >> 4);
    after_0:
    // 0x800481A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800481A4: addiu       $a0, $a0, -0x3FB0
    ctx->r4 = ADD32(ctx->r4, -0X3FB0);
    // 0x800481A8: jal         0x80083560
    // 0x800481AC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    debug_print_reason_routine(rdram, ctx);
        goto after_1;
    // 0x800481AC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
L_800481B0:
    // 0x800481B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800481B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800481B8: jr          $ra
    // 0x800481BC: nop

    return;
    // 0x800481BC: nop

;}

RECOMP_FUNC void wonders4_AllocBuffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800481C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800481C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800481C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800481CC: sw          $zero, -0x2C0($at)
    MEM_W(-0X2C0, ctx->r1) = 0;
    // 0x800481D0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800481D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800481D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800481DC: sw          $zero, -0x2BC($at)
    MEM_W(-0X2BC, ctx->r1) = 0;
    // 0x800481E0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800481E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800481E8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800481EC: sw          $t7, 0x20C4($at)
    MEM_W(0X20C4, ctx->r1) = ctx->r15;
    // 0x800481F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800481F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800481F8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800481FC: jal         0x8004A34C
    // 0x80048200: sw          $t9, 0x20D4($at)
    MEM_W(0X20D4, ctx->r1) = ctx->r25;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x80048200: sw          $t9, 0x20D4($at)
    MEM_W(0X20D4, ctx->r1) = ctx->r25;
    after_0:
    // 0x80048204: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048208: addiu       $t0, $t0, 0x20B8
    ctx->r8 = ADD32(ctx->r8, 0X20B8);
    // 0x8004820C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80048210: jal         0x8007E328
    // 0x80048214: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x80048214: nop

    after_1:
    // 0x80048218: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8004821C: addiu       $t1, $t1, 0x20B8
    ctx->r9 = ADD32(ctx->r9, 0X20B8);
    // 0x80048220: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x80048224: jal         0x8007E328
    // 0x80048228: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_2;
    // 0x80048228: nop

    after_2:
    // 0x8004822C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048230: addiu       $t2, $t2, 0x20C8
    ctx->r10 = ADD32(ctx->r10, 0X20C8);
    // 0x80048234: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80048238: jal         0x8007E328
    // 0x8004823C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_3;
    // 0x8004823C: nop

    after_3:
    // 0x80048240: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80048244: addiu       $t3, $t3, 0x20C8
    ctx->r11 = ADD32(ctx->r11, 0X20C8);
    // 0x80048248: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x8004824C: jal         0x8007E328
    // 0x80048250: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_4;
    // 0x80048250: nop

    after_4:
    // 0x80048254: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80048258: lw          $t4, 0x20C4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20C4);
    // 0x8004825C: nop

    // 0x80048260: beq         $t4, $zero, L_80048298
    if (ctx->r12 == 0) {
        // 0x80048264: nop
    
            goto L_80048298;
    }
    // 0x80048264: nop

    // 0x80048268: jal         0x8007E03C
    // 0x8004826C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x8004826C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_5:
    // 0x80048270: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80048274: addiu       $t5, $t5, 0x20B8
    ctx->r13 = ADD32(ctx->r13, 0X20B8);
    // 0x80048278: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8004827C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80048280: lw          $a0, 0x20C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C4);
    // 0x80048284: jal         0x8007E03C
    // 0x80048288: nop

    n64HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x80048288: nop

    after_6:
    // 0x8004828C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048290: addiu       $t6, $t6, 0x20B8
    ctx->r14 = ADD32(ctx->r14, 0X20B8);
    // 0x80048294: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
L_80048298:
    // 0x80048298: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004829C: lw          $t7, 0x20D4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20D4);
    // 0x800482A0: nop

    // 0x800482A4: beq         $t7, $zero, L_800482DC
    if (ctx->r15 == 0) {
        // 0x800482A8: nop
    
            goto L_800482DC;
    }
    // 0x800482A8: nop

    // 0x800482AC: jal         0x8007E03C
    // 0x800482B0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x800482B0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_7:
    // 0x800482B4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800482B8: addiu       $t8, $t8, 0x20C8
    ctx->r24 = ADD32(ctx->r24, 0X20C8);
    // 0x800482BC: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x800482C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800482C4: lw          $a0, 0x20D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20D4);
    // 0x800482C8: jal         0x8007E03C
    // 0x800482CC: nop

    n64HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x800482CC: nop

    after_8:
    // 0x800482D0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800482D4: addiu       $t9, $t9, 0x20C8
    ctx->r25 = ADD32(ctx->r25, 0X20C8);
    // 0x800482D8: sw          $v0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r2;
L_800482DC:
    // 0x800482DC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800482E0: lhu         $t0, 0x20B0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X20B0);
    // 0x800482E4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800482E8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800482EC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800482F0: lw          $t2, 0x20B8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20B8);
    // 0x800482F4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800482F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800482FC: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80048300: lw          $t3, 0x20C8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20C8);
    // 0x80048304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048308: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x8004830C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048314: jr          $ra
    // 0x80048318: sw          $t3, 0x20D0($at)
    MEM_W(0X20D0, ctx->r1) = ctx->r11;
    return;
    // 0x80048318: sw          $t3, 0x20D0($at)
    MEM_W(0X20D0, ctx->r1) = ctx->r11;
;}

RECOMP_FUNC void wonders4_AllocBuffer8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004831C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048320: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80048324: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80048328: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004832C: sw          $zero, -0x2C0($at)
    MEM_W(-0X2C0, ctx->r1) = 0;
    // 0x80048330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048334: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048338: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8004833C: jal         0x8004A34C
    // 0x80048340: sw          $t7, 0x20C4($at)
    MEM_W(0X20C4, ctx->r1) = ctx->r15;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x80048340: sw          $t7, 0x20C4($at)
    MEM_W(0X20C4, ctx->r1) = ctx->r15;
    after_0:
    // 0x80048344: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80048348: addiu       $t8, $t8, 0x20B8
    ctx->r24 = ADD32(ctx->r24, 0X20B8);
    // 0x8004834C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80048350: jal         0x8007E328
    // 0x80048354: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x80048354: nop

    after_1:
    // 0x80048358: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8004835C: addiu       $t9, $t9, 0x20B8
    ctx->r25 = ADD32(ctx->r25, 0X20B8);
    // 0x80048360: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x80048364: jal         0x8007E328
    // 0x80048368: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_2;
    // 0x80048368: nop

    after_2:
    // 0x8004836C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048370: lw          $t0, 0x20C4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X20C4);
    // 0x80048374: nop

    // 0x80048378: beq         $t0, $zero, L_800483D8
    if (ctx->r8 == 0) {
        // 0x8004837C: nop
    
            goto L_800483D8;
    }
    // 0x8004837C: nop

    // 0x80048380: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80048384: lw          $a0, 0x20C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C4);
    // 0x80048388: jal         0x8007E03C
    // 0x8004838C: nop

    n64HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x8004838C: nop

    after_3:
    // 0x80048390: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80048394: addiu       $t1, $t1, 0x20B8
    ctx->r9 = ADD32(ctx->r9, 0X20B8);
    // 0x80048398: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8004839C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800483A0: lw          $a0, 0x20C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C4);
    // 0x800483A4: jal         0x8007E03C
    // 0x800483A8: nop

    n64HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800483A8: nop

    after_4:
    // 0x800483AC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800483B0: addiu       $t2, $t2, 0x20B8
    ctx->r10 = ADD32(ctx->r10, 0X20B8);
    // 0x800483B4: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x800483B8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800483BC: lhu         $t3, 0x20B0($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X20B0);
    // 0x800483C0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800483C4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800483C8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800483CC: lw          $t5, 0x20B8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20B8);
    // 0x800483D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800483D4: sw          $t5, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r13;
L_800483D8:
    // 0x800483D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800483DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800483E0: jr          $ra
    // 0x800483E4: nop

    return;
    // 0x800483E4: nop

;}

RECOMP_FUNC void wonders4_AllocBuffer16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800483E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800483EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800483F0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800483F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800483F8: sw          $zero, -0x2BC($at)
    MEM_W(-0X2BC, ctx->r1) = 0;
    // 0x800483FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048400: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048404: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80048408: jal         0x8004A34C
    // 0x8004840C: sw          $t7, 0x20D4($at)
    MEM_W(0X20D4, ctx->r1) = ctx->r15;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x8004840C: sw          $t7, 0x20D4($at)
    MEM_W(0X20D4, ctx->r1) = ctx->r15;
    after_0:
    // 0x80048410: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80048414: addiu       $t8, $t8, 0x20C8
    ctx->r24 = ADD32(ctx->r24, 0X20C8);
    // 0x80048418: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8004841C: jal         0x8007E328
    // 0x80048420: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x80048420: nop

    after_1:
    // 0x80048424: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048428: addiu       $t9, $t9, 0x20C8
    ctx->r25 = ADD32(ctx->r25, 0X20C8);
    // 0x8004842C: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x80048430: jal         0x8007E328
    // 0x80048434: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_2;
    // 0x80048434: nop

    after_2:
    // 0x80048438: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8004843C: lw          $t0, 0x20D4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X20D4);
    // 0x80048440: nop

    // 0x80048444: beq         $t0, $zero, L_800484A4
    if (ctx->r8 == 0) {
        // 0x80048448: nop
    
            goto L_800484A4;
    }
    // 0x80048448: nop

    // 0x8004844C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80048450: lw          $a0, 0x20D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20D4);
    // 0x80048454: jal         0x8007E03C
    // 0x80048458: nop

    n64HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x80048458: nop

    after_3:
    // 0x8004845C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80048460: addiu       $t1, $t1, 0x20C8
    ctx->r9 = ADD32(ctx->r9, 0X20C8);
    // 0x80048464: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x80048468: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8004846C: lw          $a0, 0x20D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20D4);
    // 0x80048470: jal         0x8007E03C
    // 0x80048474: nop

    n64HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x80048474: nop

    after_4:
    // 0x80048478: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8004847C: addiu       $t2, $t2, 0x20C8
    ctx->r10 = ADD32(ctx->r10, 0X20C8);
    // 0x80048480: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x80048484: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80048488: lhu         $t3, 0x20B0($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X20B0);
    // 0x8004848C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80048490: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80048494: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80048498: lw          $t5, 0x20C8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20C8);
    // 0x8004849C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800484A0: sw          $t5, 0x20D0($at)
    MEM_W(0X20D0, ctx->r1) = ctx->r13;
L_800484A4:
    // 0x800484A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800484A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800484AC: jr          $ra
    // 0x800484B0: nop

    return;
    // 0x800484B0: nop

;}

RECOMP_FUNC void inits_bunch_of_stuff_q_allocs_heap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800484B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800484B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800484BC: jal         0x8007E03C
    // 0x800484C0: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800484C0: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    after_0:
    // 0x800484C4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800484C8: addiu       $t6, $t6, 0x20B8
    ctx->r14 = ADD32(ctx->r14, 0X20B8);
    // 0x800484CC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x800484D0: jal         0x8007E03C
    // 0x800484D4: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800484D4: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    after_1:
    // 0x800484D8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800484DC: addiu       $t7, $t7, 0x20B8
    ctx->r15 = ADD32(ctx->r15, 0X20B8);
    // 0x800484E0: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    // 0x800484E4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800484E8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800484EC: lw          $t1, -0x2B0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2B0);
    // 0x800484F0: lw          $t0, -0x2AC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AC);
    // 0x800484F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800484F8: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800484FC: sw          $zero, -0x2C0($at)
    MEM_W(-0X2C0, ctx->r1) = 0;
    // 0x80048500: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048504: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80048508: sw          $t8, 0x20C4($at)
    MEM_W(0X20C4, ctx->r1) = ctx->r24;
    // 0x8004850C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80048510: sw          $zero, -0x2BC($at)
    MEM_W(-0X2BC, ctx->r1) = 0;
    // 0x80048514: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80048518: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004851C: addiu       $t9, $t9, -0x5300
    ctx->r25 = ADD32(ctx->r25, -0X5300);
    // 0x80048520: sw          $zero, 0x20D4($at)
    MEM_W(0X20D4, ctx->r1) = 0;
    // 0x80048524: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80048528: mflo        $t2
    ctx->r10 = lo;
    // 0x8004852C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80048530: beq         $t2, $zero, L_80048560
    if (ctx->r10 == 0) {
        // 0x80048534: nop
    
            goto L_80048560;
    }
    // 0x80048534: nop

L_80048538:
    // 0x80048538: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8004853C: nop

    // 0x80048540: sh          $zero, 0x0($t3)
    MEM_H(0X0, ctx->r11) = 0;
    // 0x80048544: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80048548: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8004854C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80048550: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80048554: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80048558: bne         $t7, $zero, L_80048538
    if (ctx->r15 != 0) {
        // 0x8004855C: sw          $t5, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r13;
            goto L_80048538;
    }
    // 0x8004855C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
L_80048560:
    // 0x80048560: jal         0x800B6330
    // 0x80048564: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_2;
    // 0x80048564: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_2:
    // 0x80048568: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8004856C: jal         0x800B64F0
    // 0x80048570: addiu       $a0, $a0, -0x5300
    ctx->r4 = ADD32(ctx->r4, -0X5300);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x80048570: addiu       $a0, $a0, -0x5300
    ctx->r4 = ADD32(ctx->r4, -0X5300);
    after_3:
    // 0x80048574: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048578: addiu       $t9, $t9, 0x2070
    ctx->r25 = ADD32(ctx->r25, 0X2070);
    // 0x8004857C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80048580: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x80048584: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048588: addiu       $t0, $t0, 0x2070
    ctx->r8 = ADD32(ctx->r8, 0X2070);
    // 0x8004858C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80048590: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048594: sh          $zero, 0x2($t0)
    MEM_H(0X2, ctx->r8) = 0;
    // 0x80048598: addiu       $t2, $t2, 0x2070
    ctx->r10 = ADD32(ctx->r10, 0X2070);
    // 0x8004859C: addiu       $t1, $t1, 0x1FA0
    ctx->r9 = ADD32(ctx->r9, 0X1FA0);
    // 0x800485A0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800485A4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800485A8: addiu       $t4, $t4, 0x2070
    ctx->r12 = ADD32(ctx->r12, 0X2070);
    // 0x800485AC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800485B0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800485B4: sh          $t3, 0x20($t4)
    MEM_H(0X20, ctx->r12) = ctx->r11;
    // 0x800485B8: addiu       $t6, $t6, 0x2070
    ctx->r14 = ADD32(ctx->r14, 0X2070);
    // 0x800485BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800485C0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800485C4: sh          $t5, 0x22($t6)
    MEM_H(0X22, ctx->r14) = ctx->r13;
    // 0x800485C8: addiu       $t7, $t7, 0x1FA0
    ctx->r15 = ADD32(ctx->r15, 0X1FA0);
    // 0x800485CC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800485D0: addiu       $t9, $t9, 0x2070
    ctx->r25 = ADD32(ctx->r25, 0X2070);
    // 0x800485D4: addiu       $t8, $t7, 0x68
    ctx->r24 = ADD32(ctx->r15, 0X68);
    // 0x800485D8: sw          $t8, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r24;
    // 0x800485DC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800485E0: addiu       $t0, $t0, 0x1FA0
    ctx->r8 = ADD32(ctx->r8, 0X1FA0);
    // 0x800485E4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800485E8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800485EC: addiu       $t1, $t1, 0x1FA0
    ctx->r9 = ADD32(ctx->r9, 0X1FA0);
    // 0x800485F0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800485F4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800485F8: addiu       $t3, $t3, 0x1FA0
    ctx->r11 = ADD32(ctx->r11, 0X1FA0);
    // 0x800485FC: addiu       $t2, $zero, 0x63
    ctx->r10 = ADD32(0, 0X63);
    // 0x80048600: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80048604: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x80048608: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x8004860C: addiu       $t4, $t4, -0x5300
    ctx->r12 = ADD32(ctx->r12, -0X5300);
    // 0x80048610: addiu       $t5, $t5, 0x1FA0
    ctx->r13 = ADD32(ctx->r13, 0X1FA0);
    // 0x80048614: sw          $t4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r12;
    // 0x80048618: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004861C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80048620: addiu       $t6, $t6, -0x44F8
    ctx->r14 = ADD32(ctx->r14, -0X44F8);
    // 0x80048624: addiu       $t7, $t7, 0x1FA0
    ctx->r15 = ADD32(ctx->r15, 0X1FA0);
    // 0x80048628: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8004862C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048630: sw          $t6, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r14;
    // 0x80048634: addiu       $t9, $t9, 0x1FA0
    ctx->r25 = ADD32(ctx->r25, 0X1FA0);
    // 0x80048638: addiu       $t8, $t8, 0x2070
    ctx->r24 = ADD32(ctx->r24, 0X2070);
    // 0x8004863C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80048640: sw          $t8, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->r24;
    // 0x80048644: addiu       $t1, $t1, 0x1FA0
    ctx->r9 = ADD32(ctx->r9, 0X1FA0);
    // 0x80048648: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8004864C: sw          $t0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r8;
    // 0x80048650: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048654: addiu       $t2, $t2, 0x1FA0
    ctx->r10 = ADD32(ctx->r10, 0X1FA0);
    // 0x80048658: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8004865C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80048660: sw          $zero, 0x14($t2)
    MEM_W(0X14, ctx->r10) = 0;
    // 0x80048664: addiu       $t3, $t3, 0x3310
    ctx->r11 = ADD32(ctx->r11, 0X3310);
    // 0x80048668: addiu       $t4, $t4, 0x1FA0
    ctx->r12 = ADD32(ctx->r12, 0X1FA0);
    // 0x8004866C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80048670: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80048674: sw          $t3, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r11;
    // 0x80048678: addiu       $t5, $t5, 0x33E0
    ctx->r13 = ADD32(ctx->r13, 0X33E0);
    // 0x8004867C: addiu       $t6, $t6, 0x3310
    ctx->r14 = ADD32(ctx->r14, 0X3310);
    // 0x80048680: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80048684: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x80048688: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8004868C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048690: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80048694: sw          $t7, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r15;
    // 0x80048698: addiu       $t9, $t9, 0x33E0
    ctx->r25 = ADD32(ctx->r25, 0X33E0);
    // 0x8004869C: addiu       $t0, $t0, 0x1FA0
    ctx->r8 = ADD32(ctx->r8, 0X1FA0);
    // 0x800486A0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800486A4: sw          $t9, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r25;
    // 0x800486A8: addiu       $t2, $t2, 0x1FA0
    ctx->r10 = ADD32(ctx->r10, 0X1FA0);
    // 0x800486AC: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x800486B0: sw          $t1, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r9;
    // 0x800486B4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800486B8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800486BC: addiu       $t4, $t4, 0x1FA0
    ctx->r12 = ADD32(ctx->r12, 0X1FA0);
    // 0x800486C0: addiu       $t3, $t3, 0x1830
    ctx->r11 = ADD32(ctx->r11, 0X1830);
    // 0x800486C4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800486C8: sw          $t3, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r11;
    // 0x800486CC: addiu       $t6, $t6, 0x1FA0
    ctx->r14 = ADD32(ctx->r14, 0X1FA0);
    // 0x800486D0: addiu       $t5, $zero, 0x800
    ctx->r13 = ADD32(0, 0X800);
    // 0x800486D4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800486D8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800486DC: sw          $t5, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r13;
    // 0x800486E0: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x800486E4: addiu       $t7, $t7, 0x21C0
    ctx->r15 = ADD32(ctx->r15, 0X21C0);
    // 0x800486E8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800486EC: sw          $t7, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r15;
    // 0x800486F0: addiu       $t0, $t0, 0x1FA0
    ctx->r8 = ADD32(ctx->r8, 0X1FA0);
    // 0x800486F4: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x800486F8: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x800486FC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80048700: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048704: addiu       $t2, $t2, 0x1FA0
    ctx->r10 = ADD32(ctx->r10, 0X1FA0);
    // 0x80048708: addiu       $t1, $t1, 0x31C0
    ctx->r9 = ADD32(ctx->r9, 0X31C0);
    // 0x8004870C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80048710: sw          $t1, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->r9;
    // 0x80048714: addiu       $t3, $t3, 0x31C0
    ctx->r11 = ADD32(ctx->r11, 0X31C0);
    // 0x80048718: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8004871C: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80048720: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80048724: addiu       $t5, $t5, 0x1FA0
    ctx->r13 = ADD32(ctx->r13, 0X1FA0);
    // 0x80048728: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004872C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048730: sw          $t4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r12;
    // 0x80048734: addiu       $t6, $t6, 0x25C0
    ctx->r14 = ADD32(ctx->r14, 0X25C0);
    // 0x80048738: addiu       $t7, $t7, 0x1FA0
    ctx->r15 = ADD32(ctx->r15, 0X1FA0);
    // 0x8004873C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048740: sw          $t6, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->r14;
    // 0x80048744: addiu       $t9, $t9, 0x1FA0
    ctx->r25 = ADD32(ctx->r25, 0X1FA0);
    // 0x80048748: addiu       $t8, $zero, 0xC00
    ctx->r24 = ADD32(0, 0XC00);
    // 0x8004874C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048750: sw          $t8, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->r24;
    // 0x80048754: addiu       $t0, $t0, 0x20B8
    ctx->r8 = ADD32(ctx->r8, 0X20B8);
    // 0x80048758: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8004875C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048760: addiu       $t2, $t2, 0x1FA0
    ctx->r10 = ADD32(ctx->r10, 0X1FA0);
    // 0x80048764: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80048768: sw          $t1, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->r9;
    // 0x8004876C: addiu       $t3, $t3, 0x1FA0
    ctx->r11 = ADD32(ctx->r11, 0X1FA0);
    // 0x80048770: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80048774: sw          $zero, 0x44($t3)
    MEM_W(0X44, ctx->r11) = 0;
    // 0x80048778: addiu       $t4, $t4, 0x1FA0
    ctx->r12 = ADD32(ctx->r12, 0X1FA0);
    // 0x8004877C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80048780: sw          $zero, 0x68($t4)
    MEM_W(0X68, ctx->r12) = 0;
    // 0x80048784: addiu       $t5, $t5, 0x1FA0
    ctx->r13 = ADD32(ctx->r13, 0X1FA0);
    // 0x80048788: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004878C: sw          $zero, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = 0;
    // 0x80048790: addiu       $t7, $t7, 0x1FA0
    ctx->r15 = ADD32(ctx->r15, 0X1FA0);
    // 0x80048794: addiu       $t6, $zero, 0x63
    ctx->r14 = ADD32(0, 0X63);
    // 0x80048798: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8004879C: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x800487A0: sw          $t6, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->r14;
    // 0x800487A4: ori         $at, $at, 0xA980
    ctx->r1 = ctx->r1 | 0XA980;
    // 0x800487A8: addiu       $t8, $t8, -0x5300
    ctx->r24 = ADD32(ctx->r24, -0X5300);
    // 0x800487AC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800487B0: addiu       $t0, $t0, 0x1FA0
    ctx->r8 = ADD32(ctx->r8, 0X1FA0);
    // 0x800487B4: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800487B8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800487BC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800487C0: sw          $t9, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r25;
    // 0x800487C4: addiu       $t2, $t2, 0x1FA0
    ctx->r10 = ADD32(ctx->r10, 0X1FA0);
    // 0x800487C8: addiu       $t1, $t1, -0x44F8
    ctx->r9 = ADD32(ctx->r9, -0X44F8);
    // 0x800487CC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800487D0: sw          $t1, 0xB8($t2)
    MEM_W(0XB8, ctx->r10) = ctx->r9;
    // 0x800487D4: addiu       $t3, $t3, 0x2070
    ctx->r11 = ADD32(ctx->r11, 0X2070);
    // 0x800487D8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800487DC: addiu       $t5, $t5, 0x1FA0
    ctx->r13 = ADD32(ctx->r13, 0X1FA0);
    // 0x800487E0: addiu       $t4, $t3, 0x20
    ctx->r12 = ADD32(ctx->r11, 0X20);
    // 0x800487E4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800487E8: sw          $t4, 0xBC($t5)
    MEM_W(0XBC, ctx->r13) = ctx->r12;
    // 0x800487EC: addiu       $t7, $t7, 0x1FA0
    ctx->r15 = ADD32(ctx->r15, 0X1FA0);
    // 0x800487F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800487F4: sw          $t6, 0x78($t7)
    MEM_W(0X78, ctx->r15) = ctx->r14;
    // 0x800487F8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800487FC: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x80048800: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80048804: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048808: sw          $zero, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = 0;
    // 0x8004880C: addiu       $t0, $t0, 0x1FA0
    ctx->r8 = ADD32(ctx->r8, 0X1FA0);
    // 0x80048810: addiu       $t9, $t9, 0x3310
    ctx->r25 = ADD32(ctx->r25, 0X3310);
    // 0x80048814: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80048818: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8004881C: sw          $t9, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->r25;
    // 0x80048820: addiu       $t2, $t2, 0x3310
    ctx->r10 = ADD32(ctx->r10, 0X3310);
    // 0x80048824: addiu       $t1, $t1, 0x33E0
    ctx->r9 = ADD32(ctx->r9, 0X33E0);
    // 0x80048828: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8004882C: addiu       $t4, $t4, 0x1FA0
    ctx->r12 = ADD32(ctx->r12, 0X1FA0);
    // 0x80048830: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80048834: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048838: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8004883C: sw          $t3, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->r11;
    // 0x80048840: addiu       $t5, $t5, 0x33E0
    ctx->r13 = ADD32(ctx->r13, 0X33E0);
    // 0x80048844: addiu       $t6, $t6, 0x1FA0
    ctx->r14 = ADD32(ctx->r14, 0X1FA0);
    // 0x80048848: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8004884C: sw          $t5, 0x88($t6)
    MEM_W(0X88, ctx->r14) = ctx->r13;
    // 0x80048850: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x80048854: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x80048858: sw          $t7, 0x8C($t8)
    MEM_W(0X8C, ctx->r24) = ctx->r15;
    // 0x8004885C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048860: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048864: addiu       $t0, $t0, 0x1FA0
    ctx->r8 = ADD32(ctx->r8, 0X1FA0);
    // 0x80048868: addiu       $t9, $t9, 0x1830
    ctx->r25 = ADD32(ctx->r25, 0X1830);
    // 0x8004886C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048870: sw          $t9, 0x90($t0)
    MEM_W(0X90, ctx->r8) = ctx->r25;
    // 0x80048874: addiu       $t2, $t2, 0x1FA0
    ctx->r10 = ADD32(ctx->r10, 0X1FA0);
    // 0x80048878: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x8004887C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80048880: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80048884: sw          $t1, 0x94($t2)
    MEM_W(0X94, ctx->r10) = ctx->r9;
    // 0x80048888: addiu       $t4, $t4, 0x1FA0
    ctx->r12 = ADD32(ctx->r12, 0X1FA0);
    // 0x8004888C: addiu       $t3, $t3, 0x21C0
    ctx->r11 = ADD32(ctx->r11, 0X21C0);
    // 0x80048890: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048894: sw          $t3, 0x98($t4)
    MEM_W(0X98, ctx->r12) = ctx->r11;
    // 0x80048898: addiu       $t6, $t6, 0x1FA0
    ctx->r14 = ADD32(ctx->r14, 0X1FA0);
    // 0x8004889C: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x800488A0: sw          $t5, 0x9C($t6)
    MEM_W(0X9C, ctx->r14) = ctx->r13;
    // 0x800488A4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800488A8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800488AC: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x800488B0: addiu       $t7, $t7, 0x31C0
    ctx->r15 = ADD32(ctx->r15, 0X31C0);
    // 0x800488B4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800488B8: sw          $t7, 0xA0($t8)
    MEM_W(0XA0, ctx->r24) = ctx->r15;
    // 0x800488BC: addiu       $t9, $t9, 0x31C0
    ctx->r25 = ADD32(ctx->r25, 0X31C0);
    // 0x800488C0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800488C4: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800488C8: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x800488CC: addiu       $t1, $t1, 0x1FA0
    ctx->r9 = ADD32(ctx->r9, 0X1FA0);
    // 0x800488D0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800488D4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800488D8: sw          $t0, 0xA4($t1)
    MEM_W(0XA4, ctx->r9) = ctx->r8;
    // 0x800488DC: addiu       $t2, $t2, 0x25C0
    ctx->r10 = ADD32(ctx->r10, 0X25C0);
    // 0x800488E0: addiu       $t3, $t3, 0x1FA0
    ctx->r11 = ADD32(ctx->r11, 0X1FA0);
    // 0x800488E4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800488E8: sw          $t2, 0xB0($t3)
    MEM_W(0XB0, ctx->r11) = ctx->r10;
    // 0x800488EC: addiu       $t5, $t5, 0x1FA0
    ctx->r13 = ADD32(ctx->r13, 0X1FA0);
    // 0x800488F0: addiu       $t4, $zero, 0xC00
    ctx->r12 = ADD32(0, 0XC00);
    // 0x800488F4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800488F8: sw          $t4, 0xB4($t5)
    MEM_W(0XB4, ctx->r13) = ctx->r12;
    // 0x800488FC: addiu       $t6, $t6, 0x20B8
    ctx->r14 = ADD32(ctx->r14, 0X20B8);
    // 0x80048900: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80048904: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80048908: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x8004890C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048910: addiu       $t9, $t9, 0x1FA0
    ctx->r25 = ADD32(ctx->r25, 0X1FA0);
    // 0x80048914: sw          $t7, 0xA8($t8)
    MEM_W(0XA8, ctx->r24) = ctx->r15;
    // 0x80048918: sw          $zero, 0xAC($t9)
    MEM_W(0XAC, ctx->r25) = 0;
    // 0x8004891C: jal         0x80076EA0
    // 0x80048920: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80076EA0(rdram, ctx);
        goto after_4;
    // 0x80048920: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80048924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048928: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004892C: jr          $ra
    // 0x80048930: nop

    return;
    // 0x80048930: nop

;}

RECOMP_FUNC void wonders4_BuildFillRectDL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048934: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80048938: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8004893C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80048940: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80048944: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80048948: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8004894C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80048950: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x80048954: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80048958: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8004895C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80048960: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80048964: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x80048968: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x8004896C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80048970: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80048974: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80048978: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8004897C: sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // 0x80048980: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80048984: lui         $t3, 0xED00
    ctx->r11 = S32(0XED00 << 16);
    // 0x80048988: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8004898C: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80048990: lui         $t5, 0x63
    ctx->r13 = S32(0X63 << 16);
    // 0x80048994: ori         $t5, $t5, 0xC4AC
    ctx->r13 = ctx->r13 | 0XC4AC;
    // 0x80048998: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8004899C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800489A0: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800489A4: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x800489A8: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800489AC: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x800489B0: lui         $t7, 0xF700
    ctx->r15 = S32(0XF700 << 16);
    // 0x800489B4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800489B8: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x800489BC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800489C0: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x800489C4: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x800489C8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800489CC: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x800489D0: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x800489D4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800489D8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800489DC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800489E0: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x800489E4: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x800489E8: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800489EC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800489F0: lui         $t1, 0xFF10
    ctx->r9 = S32(0XFF10 << 16);
    // 0x800489F4: ori         $t1, $t1, 0x18F
    ctx->r9 = ctx->r9 | 0X18F;
    // 0x800489F8: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x800489FC: sll         $t3, $t3, 7
    ctx->r11 = S32(ctx->r11 << 7);
    // 0x80048A00: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x80048A04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80048A08: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80048A0C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80048A10: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80048A14: addiu       $t5, $t5, -0x5300
    ctx->r13 = ADD32(ctx->r13, -0X5300);
    // 0x80048A18: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80048A1C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80048A20: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80048A24: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80048A28: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80048A2C: lui         $t8, 0xF663
    ctx->r24 = S32(0XF663 << 16);
    // 0x80048A30: ori         $t8, $t8, 0xC4AC
    ctx->r24 = ctx->r24 | 0XC4AC;
    // 0x80048A34: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80048A38: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x80048A3C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80048A40: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80048A44: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x80048A48: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80048A4C: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80048A50: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80048A54: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80048A58: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80048A5C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80048A60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80048A64: jr          $ra
    // 0x80048A68: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    return;
    // 0x80048A68: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
;}

RECOMP_FUNC void wonders4_BuildScissoredFillRectDL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048A6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048A70: sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // 0x80048A74: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80048A78: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80048A7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80048A80: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80048A84: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80048A88: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80048A8C: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x80048A90: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80048A94: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80048A98: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80048A9C: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x80048AA0: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x80048AA4: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x80048AA8: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80048AAC: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x80048AB0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80048AB4: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80048AB8: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x80048ABC: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x80048AC0: lui         $t3, 0xF700
    ctx->r11 = S32(0XF700 << 16);
    // 0x80048AC4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80048AC8: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80048ACC: lui         $t5, 0xFFFC
    ctx->r13 = S32(0XFFFC << 16);
    // 0x80048AD0: ori         $t5, $t5, 0xFFFC
    ctx->r13 = ctx->r13 | 0XFFFC;
    // 0x80048AD4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80048AD8: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80048ADC: lw          $t7, -0x2B0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B0);
    // 0x80048AE0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80048AE4: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80048AE8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80048AEC: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80048AF0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80048AF4: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x80048AF8: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x80048AFC: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80048B00: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80048B04: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x80048B08: addiu       $t2, $t2, 0x400
    ctx->r10 = ADD32(ctx->r10, 0X400);
    // 0x80048B0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80048B10: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x80048B14: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80048B18: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80048B1C: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x80048B20: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80048B24: lui         $t5, 0xF663
    ctx->r13 = S32(0XF663 << 16);
    // 0x80048B28: ori         $t5, $t5, 0xC4AC
    ctx->r13 = ctx->r13 | 0XC4AC;
    // 0x80048B2C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80048B30: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80048B34: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80048B38: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80048B3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80048B40: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80048B44: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80048B48: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80048B4C: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x80048B50: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80048B54: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80048B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048B5C: jr          $ra
    // 0x80048B60: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    return;
    // 0x80048B60: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
;}

RECOMP_FUNC void has_rounds_and_floors_large_liner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048B64: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80048B68: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80048B6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80048B70: lw          $a0, -0x41E4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X41E4);
    // 0x80048B74: jal         0x800A3A8C
    // 0x80048B78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    frametime_update(rdram, ctx);
        goto after_0;
    // 0x80048B78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80048B7C: jal         0x800B6540
    // 0x80048B80: nop

    osGetCount_recomp(rdram, ctx);
        goto after_1;
    // 0x80048B80: nop

    after_1:
    // 0x80048B84: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048B88: lhu         $t6, 0x20B0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X20B0);
    // 0x80048B8C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80048B90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80048B94: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80048B98: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80048B9C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80048BA0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80048BA4: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x80048BA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80048BAC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80048BB0: sw          $v0, -0x6A18($at)
    MEM_W(-0X6A18, ctx->r1) = ctx->r2;
    // 0x80048BB4: jal         0x800B6550
    // 0x80048BB8: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    osGetTime_recomp(rdram, ctx);
        goto after_2;
    // 0x80048BB8: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    after_2:
    // 0x80048BBC: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x80048BC0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048BC4: lw          $t1, 0x54($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X54);
    // 0x80048BC8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80048BCC: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x80048BD0: sw          $v1, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r3;
    // 0x80048BD4: lhu         $t2, 0x20B0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X20B0);
    // 0x80048BD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048BDC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80048BE0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80048BE4: lw          $t4, 0x20B8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20B8);
    // 0x80048BE8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80048BEC: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80048BF0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048BF4: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x80048BF8: lw          $t5, 0x20C8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20C8);
    // 0x80048BFC: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80048C00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048C04: sw          $t5, 0x20D0($at)
    MEM_W(0X20D0, ctx->r1) = ctx->r13;
    // 0x80048C08: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x80048C0C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80048C10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048C14: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80048C18: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x80048C1C: lui         $t8, 0xDB06
    ctx->r24 = S32(0XDB06 << 16);
    // 0x80048C20: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80048C24: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80048C28: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80048C2C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80048C30: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x80048C34: lui         $t4, 0xDB06
    ctx->r12 = S32(0XDB06 << 16);
    // 0x80048C38: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80048C3C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80048C40: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80048C44: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x80048C48: ori         $t4, $t4, 0x8
    ctx->r12 = ctx->r12 | 0X8;
    // 0x80048C4C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80048C50: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80048C54: lhu         $t5, 0x20B0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X20B0);
    // 0x80048C58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80048C5C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80048C60: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80048C64: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80048C68: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80048C6C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80048C70: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80048C74: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80048C78: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80048C7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80048C80: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80048C84: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x80048C88: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80048C8C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80048C90: addiu       $t8, $t8, -0x5300
    ctx->r24 = ADD32(ctx->r24, -0X5300);
    // 0x80048C94: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80048C98: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80048C9C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80048CA0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80048CA4: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x80048CA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048CAC: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // 0x80048CB0: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80048CB4: lui         $t4, 0xDB06
    ctx->r12 = S32(0XDB06 << 16);
    // 0x80048CB8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80048CBC: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x80048CC0: ori         $t4, $t4, 0xC
    ctx->r12 = ctx->r12 | 0XC;
    // 0x80048CC4: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80048CC8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80048CCC: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80048CD0: addiu       $t5, $t5, 0x400
    ctx->r13 = ADD32(ctx->r13, 0X400);
    // 0x80048CD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80048CD8: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80048CDC: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80048CE0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80048CE4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80048CE8: lhu         $a1, 0x20B0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X20B0);
    // 0x80048CEC: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x80048CF0: jal         0x80048A6C
    // 0x80048CF4: nop

    wonders4_BuildScissoredFillRectDL(rdram, ctx);
        goto after_3;
    // 0x80048CF4: nop

    after_3:
    // 0x80048CF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048CFC: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
    // 0x80048D00: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80048D04: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80048D08: lhu         $a1, 0x20B0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X20B0);
    // 0x80048D0C: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x80048D10: jal         0x80048934
    // 0x80048D14: nop

    wonders4_BuildFillRectDL(rdram, ctx);
        goto after_4;
    // 0x80048D14: nop

    after_4:
    // 0x80048D18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048D1C: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
    // 0x80048D20: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80048D24: lw          $t8, 0x20C0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X20C0);
    // 0x80048D28: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80048D2C: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x80048D30: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80048D34: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80048D38: sw          $t9, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r25;
    // 0x80048D3C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80048D40: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80048D44: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80048D48: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80048D4C: lw          $t4, 0x20C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20C0);
    // 0x80048D50: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80048D54: lw          $t5, -0x2B0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2B0);
    // 0x80048D58: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x80048D5C: sw          $t3, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r11;
    // 0x80048D60: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x80048D64: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80048D68: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80048D6C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80048D70: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x80048D74: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80048D78: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048D7C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80048D80: lhu         $t0, 0x20B0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X20B0);
    // 0x80048D84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80048D88: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80048D8C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80048D90: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80048D94: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80048D98: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80048D9C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80048DA0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80048DA4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80048DA8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80048DAC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80048DB0: sll         $t1, $t1, 7
    ctx->r9 = S32(ctx->r9 << 7);
    // 0x80048DB4: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x80048DB8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80048DBC: addiu       $t4, $t4, -0x5300
    ctx->r12 = ADD32(ctx->r12, -0X5300);
    // 0x80048DC0: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x80048DC4: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80048DC8: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80048DCC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80048DD0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80048DD4: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80048DD8: lw          $t8, -0x2A0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A0);
    // 0x80048DDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048DE0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80048DE4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80048DE8: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x80048DEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80048DF0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80048DF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80048DF8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80048DFC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80048E00: lw          $t3, -0x29C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X29C);
    // 0x80048E04: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80048E08: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80048E0C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80048E10: nop

    // 0x80048E14: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80048E18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048E1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80048E20: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80048E24: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80048E28: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80048E2C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80048E30: andi        $t1, $t0, 0xFFF
    ctx->r9 = ctx->r8 & 0XFFF;
    // 0x80048E34: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x80048E38: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x80048E3C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80048E40: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80048E44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048E48: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80048E4C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80048E50: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80048E54: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80048E58: nop

    // 0x80048E5C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80048E60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048E64: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80048E68: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80048E6C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80048E70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048E74: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80048E78: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80048E7C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80048E80: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80048E84: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80048E88: lw          $t0, -0x298($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X298);
    // 0x80048E8C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80048E90: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80048E94: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80048E98: lw          $t4, -0x294($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X294);
    // 0x80048E9C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80048EA0: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x80048EA4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80048EA8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80048EAC: lui         $t4, 0xFE00
    ctx->r12 = S32(0XFE00 << 16);
    // 0x80048EB0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80048EB4: nop

    // 0x80048EB8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80048EBC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048EC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80048EC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80048EC8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80048ECC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80048ED0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80048ED4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80048ED8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80048EDC: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x80048EE0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80048EE4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80048EE8: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x80048EEC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80048EF0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80048EF4: nop

    // 0x80048EF8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80048EFC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048F00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80048F04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048F08: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80048F0C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80048F10: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80048F14: andi        $t0, $t9, 0xFFF
    ctx->r8 = ctx->r25 & 0XFFF;
    // 0x80048F18: or          $t1, $t6, $t0
    ctx->r9 = ctx->r14 | ctx->r8;
    // 0x80048F1C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80048F20: lw          $t3, 0x20C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20C0);
    // 0x80048F24: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80048F28: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x80048F2C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80048F30: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x80048F34: sw          $t5, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r13;
    // 0x80048F38: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x80048F3C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80048F40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80048F44: addiu       $t8, $t8, 0x400
    ctx->r24 = ADD32(ctx->r24, 0X400);
    // 0x80048F48: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80048F4C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80048F50: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80048F54: lw          $t0, 0x20C0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X20C0);
    // 0x80048F58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048F5C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80048F60: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80048F64: lui         $t2, 0xDB04
    ctx->r10 = S32(0XDB04 << 16);
    // 0x80048F68: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80048F6C: sw          $t1, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r9;
    // 0x80048F70: ori         $t2, $t2, 0x4
    ctx->r10 = ctx->r10 | 0X4;
    // 0x80048F74: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80048F78: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80048F7C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80048F80: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80048F84: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x80048F88: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x80048F8C: lui         $t9, 0xDB04
    ctx->r25 = S32(0XDB04 << 16);
    // 0x80048F90: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x80048F94: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80048F98: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80048F9C: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x80048FA0: ori         $t9, $t9, 0xC
    ctx->r25 = ctx->r25 | 0XC;
    // 0x80048FA4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80048FA8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80048FAC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80048FB0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80048FB4: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80048FB8: lw          $t2, 0x20C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20C0);
    // 0x80048FBC: lui         $t5, 0xDB04
    ctx->r13 = S32(0XDB04 << 16);
    // 0x80048FC0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80048FC4: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80048FC8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80048FCC: sw          $t3, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r11;
    // 0x80048FD0: ori         $t5, $t5, 0x14
    ctx->r13 = ctx->r13 | 0X14;
    // 0x80048FD4: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x80048FD8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80048FDC: ori         $t7, $zero, 0xFFFD
    ctx->r15 = 0 | 0XFFFD;
    // 0x80048FE0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80048FE4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80048FE8: lw          $t9, 0x20C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20C0);
    // 0x80048FEC: lui         $t0, 0xDB04
    ctx->r8 = S32(0XDB04 << 16);
    // 0x80048FF0: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80048FF4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80048FF8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80048FFC: sw          $t6, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r14;
    // 0x80049000: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x80049004: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80049008: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8004900C: ori         $t2, $zero, 0xFFFD
    ctx->r10 = 0 | 0XFFFD;
    // 0x80049010: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80049014: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x80049018: lw          $t5, 0x20C0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20C0);
    // 0x8004901C: lui         $t7, 0xD9D0
    ctx->r15 = S32(0XD9D0 << 16);
    // 0x80049020: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80049024: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80049028: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x8004902C: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x80049030: ori         $t7, $t7, 0xF9FA
    ctx->r15 = ctx->r15 | 0XF9FA;
    // 0x80049034: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80049038: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8004903C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80049040: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80049044: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80049048: lui         $t1, 0xD9FF
    ctx->r9 = S32(0XD9FF << 16);
    // 0x8004904C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80049050: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80049054: addiu       $t0, $t6, 0x8
    ctx->r8 = ADD32(ctx->r14, 0X8);
    // 0x80049058: sw          $t0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r8;
    // 0x8004905C: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80049060: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80049064: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80049068: lui         $t3, 0x22
    ctx->r11 = S32(0X22 << 16);
    // 0x8004906C: ori         $t3, $t3, 0x5
    ctx->r11 = ctx->r11 | 0X5;
    // 0x80049070: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80049074: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80049078: lw          $t4, 0x20C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20C0);
    // 0x8004907C: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x80049080: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80049084: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80049088: addiu       $t7, $t4, 0x8
    ctx->r15 = ADD32(ctx->r12, 0X8);
    // 0x8004908C: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x80049090: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80049094: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80049098: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8004909C: addiu       $t6, $t6, -0x290
    ctx->r14 = ADD32(ctx->r14, -0X290);
    // 0x800490A0: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800490A4: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x800490A8: lbu         $t1, -0x1A4($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X1A4);
    // 0x800490AC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800490B0: beq         $t1, $zero, L_80049110
    if (ctx->r9 == 0) {
        // 0x800490B4: nop
    
            goto L_80049110;
    }
    // 0x800490B4: nop

    // 0x800490B8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800490BC:
    // 0x800490BC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800490C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800490C4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800490C8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800490CC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800490D0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800490D4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800490D8: addiu       $t5, $t5, -0x10D0
    ctx->r13 = ADD32(ctx->r13, -0X10D0);
    // 0x800490DC: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x800490E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800490E4: jal         0x8004A5F0
    // 0x800490E8: sw          $t4, -0xDF0($at)
    MEM_W(-0XDF0, ctx->r1) = ctx->r12;
    FUN_010870_interesting_stuff_large_liner(rdram, ctx);
        goto after_5;
    // 0x800490E8: sw          $t4, -0xDF0($at)
    MEM_W(-0XDF0, ctx->r1) = ctx->r12;
    after_5:
    // 0x800490EC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800490F0: nop

    // 0x800490F4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800490F8: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800490FC: bne         $at, $zero, L_800490BC
    if (ctx->r1 != 0) {
        // 0x80049100: sw          $t8, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r24;
            goto L_800490BC;
    }
    // 0x80049100: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80049104: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049108: b           L_80049170
    // 0x8004910C: sb          $zero, -0x1DC($at)
    MEM_B(-0X1DC, ctx->r1) = 0;
        goto L_80049170;
    // 0x8004910C: sb          $zero, -0x1DC($at)
    MEM_B(-0X1DC, ctx->r1) = 0;
L_80049110:
    // 0x80049110: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80049114: lh          $t9, -0x12C($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X12C);
    // 0x80049118: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8004911C: blez        $t9, L_80049170
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80049120: nop
    
            goto L_80049170;
    }
    // 0x80049120: nop

L_80049124:
    // 0x80049124: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80049128: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004912C: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80049130: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x80049134: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80049138: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x8004913C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80049140: addiu       $t1, $t1, -0x10D0
    ctx->r9 = ADD32(ctx->r9, -0X10D0);
    // 0x80049144: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80049148: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004914C: jal         0x8004A5F0
    // 0x80049150: sw          $t2, -0xDF0($at)
    MEM_W(-0XDF0, ctx->r1) = ctx->r10;
    FUN_010870_interesting_stuff_large_liner(rdram, ctx);
        goto after_6;
    // 0x80049150: sw          $t2, -0xDF0($at)
    MEM_W(-0XDF0, ctx->r1) = ctx->r10;
    after_6:
    // 0x80049154: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80049158: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8004915C: lh          $t4, -0x12C($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X12C);
    // 0x80049160: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80049164: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80049168: bne         $at, $zero, L_80049124
    if (ctx->r1 != 0) {
        // 0x8004916C: sw          $t5, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r13;
            goto L_80049124;
    }
    // 0x8004916C: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
L_80049170:
    // 0x80049170: jal         0x8006CF14
    // 0x80049174: nop

    FUN_032F00_MVC_control_menu_choice_process(rdram, ctx);
        goto after_7;
    // 0x80049174: nop

    after_7:
    // 0x80049178: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8004917C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80049180: lw          $t8, 0x60($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X60);
    // 0x80049184: lw          $t9, 0x64($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X64);
    // 0x80049188: sw          $t8, -0x6A10($at)
    MEM_W(-0X6A10, ctx->r1) = ctx->r24;
    // 0x8004918C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80049190: jal         0x800B6540
    // 0x80049194: sw          $t9, -0x6A0C($at)
    MEM_W(-0X6A0C, ctx->r1) = ctx->r25;
    osGetCount_recomp(rdram, ctx);
        goto after_8;
    // 0x80049194: sw          $t9, -0x6A0C($at)
    MEM_W(-0X6A0C, ctx->r1) = ctx->r25;
    after_8:
    // 0x80049198: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004919C: sw          $v0, -0x6A1C($at)
    MEM_W(-0X6A1C, ctx->r1) = ctx->r2;
    // 0x800491A0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800491A4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800491A8: lw          $t6, -0x6A1C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6A1C);
    // 0x800491AC: lbu         $t0, -0x120($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X120);
    // 0x800491B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800491B4: beq         $t0, $zero, L_800491C8
    if (ctx->r8 == 0) {
        // 0x800491B8: sw          $t6, -0x6A14($at)
        MEM_W(-0X6A14, ctx->r1) = ctx->r14;
            goto L_800491C8;
    }
    // 0x800491B8: sw          $t6, -0x6A14($at)
    MEM_W(-0X6A14, ctx->r1) = ctx->r14;
    // 0x800491BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800491C0: jal         0x800A9010
    // 0x800491C4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    func_800A9010(rdram, ctx);
        goto after_9;
    // 0x800491C4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_9:
L_800491C8:
    // 0x800491C8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800491CC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800491D0: lw          $t1, -0x6A1C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6A1C);
    // 0x800491D4: lw          $t2, 0x20C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20C0);
    // 0x800491D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800491DC: sw          $t1, -0x6A20($at)
    MEM_W(-0X6A20, ctx->r1) = ctx->r9;
    // 0x800491E0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800491E4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800491E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800491EC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800491F0: sw          $t3, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r11;
    // 0x800491F4: lui         $t5, 0xE900
    ctx->r13 = S32(0XE900 << 16);
    // 0x800491F8: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800491FC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80049200: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80049204: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80049208: lw          $t8, 0x20C0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X20C0);
    // 0x8004920C: lui         $t6, 0xDF00
    ctx->r14 = S32(0XDF00 << 16);
    // 0x80049210: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80049214: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80049218: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8004921C: sw          $t9, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r25;
    // 0x80049220: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80049224: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80049228: jal         0x80048020
    // 0x8004922C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    wonders4_UpdateMaxScroll(rdram, ctx);
        goto after_10;
    // 0x8004922C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_10:
    // 0x80049230: jal         0x800480E0
    // 0x80049234: nop

    wonders4_DebugPrintGList(rdram, ctx);
        goto after_11;
    // 0x80049234: nop

    after_11:
    // 0x80049238: jal         0x80048150
    // 0x8004923C: nop

    wonders4_DebugPrintVList(rdram, ctx);
        goto after_12;
    // 0x8004923C: nop

    after_12:
    // 0x80049240: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80049244: lhu         $t3, 0x20B0($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X20B0);
    // 0x80049248: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8004924C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80049250: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x80049254: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80049258: lw          $t2, 0x20C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20C0);
    // 0x8004925C: lw          $t4, 0x20B8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20B8);
    // 0x80049260: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80049264: subu        $t7, $t2, $t4
    ctx->r15 = SUB32(ctx->r10, ctx->r12);
    // 0x80049268: sw          $t7, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r15;
    // 0x8004926C: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80049270: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x80049274: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80049278: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8004927C: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80049280: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80049284: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80049288: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004928C: addiu       $a0, $a0, -0x4460
    ctx->r4 = ADD32(ctx->r4, -0X4460);
    // 0x80049290: sw          $t0, 0x60($t3)
    MEM_W(0X60, ctx->r11) = ctx->r8;
    // 0x80049294: jal         0x8005EE84
    // 0x80049298: sw          $t1, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->r9;
    osScGetCmdQ(rdram, ctx);
        goto after_13;
    // 0x80049298: sw          $t1, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->r9;
    after_13:
    // 0x8004929C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800492A0: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x800492A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800492A8: jal         0x800B34D0
    // 0x800492AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x800492AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x800492B0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800492B4: lw          $t5, -0x110($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X110);
    // 0x800492B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800492BC: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x800492C0: jal         0x800B6550
    // 0x800492C4: sw          $t2, -0x110($at)
    MEM_W(-0X110, ctx->r1) = ctx->r10;
    osGetTime_recomp(rdram, ctx);
        goto after_15;
    // 0x800492C4: sw          $t2, -0x110($at)
    MEM_W(-0X110, ctx->r1) = ctx->r10;
    after_15:
    // 0x800492C8: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x800492CC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800492D0: lw          $t7, 0x54($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X54);
    // 0x800492D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800492D8: sw          $v0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r2;
    // 0x800492DC: sw          $v1, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r3;
    // 0x800492E0: lw          $t8, -0x128($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X128);
    // 0x800492E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800492E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800492EC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800492F0: sw          $t9, -0x128($at)
    MEM_W(-0X128, ctx->r1) = ctx->r25;
    // 0x800492F4: jr          $ra
    // 0x800492F8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800492F8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}

RECOMP_FUNC void has_rounds_and_floors_2_large_liner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800492FC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80049300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049304: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049308: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004930C: addiu       $a1, $a1, 0x2120
    ctx->r5 = ADD32(ctx->r5, 0X2120);
    // 0x80049310: addiu       $a0, $a0, 0x20D8
    ctx->r4 = ADD32(ctx->r4, 0X20D8);
    // 0x80049314: jal         0x800B3080
    // 0x80049318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80049318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8004931C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80049320: addiu       $a1, $a1, 0x20D8
    ctx->r5 = ADD32(ctx->r5, 0X20D8);
    // 0x80049324: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80049328: jal         0x800B30B0
    // 0x8004932C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8004932C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80049330: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049334: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80049338: addiu       $a1, $a1, 0x2124
    ctx->r5 = ADD32(ctx->r5, 0X2124);
    // 0x8004933C: addiu       $a0, $a0, 0x20F0
    ctx->r4 = ADD32(ctx->r4, 0X20F0);
    // 0x80049340: jal         0x800B3080
    // 0x80049344: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80049344: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80049348: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004934C: addiu       $a1, $a1, 0x20F0
    ctx->r5 = ADD32(ctx->r5, 0X20F0);
    // 0x80049350: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80049354: jal         0x800B30B0
    // 0x80049358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80049358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8004935C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049360: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80049364: addiu       $a1, $a1, 0x2128
    ctx->r5 = ADD32(ctx->r5, 0X2128);
    // 0x80049368: addiu       $a0, $a0, 0x2108
    ctx->r4 = ADD32(ctx->r4, 0X2108);
    // 0x8004936C: jal         0x800B3080
    // 0x80049370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x80049370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80049374: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049378: addiu       $a0, $a0, 0x2108
    ctx->r4 = ADD32(ctx->r4, 0X2108);
    // 0x8004937C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049380: jal         0x800B65E0
    // 0x80049384: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osViSetEvent_recomp(rdram, ctx);
        goto after_5;
    // 0x80049384: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
L_80049388:
    // 0x80049388: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8004938C: lhu         $t6, 0x20B0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X20B0);
    // 0x80049390: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80049394: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80049398: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004939C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800493A0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800493A4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800493A8: addiu       $t8, $t8, 0x1FA0
    ctx->r24 = ADD32(ctx->r24, 0X1FA0);
    // 0x800493AC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800493B0: jal         0x800B6550
    // 0x800493B4: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    osGetTime_recomp(rdram, ctx);
        goto after_6;
    // 0x800493B4: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    after_6:
    // 0x800493B8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800493BC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800493C0: lw          $t1, 0x54($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X54);
    // 0x800493C4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800493C8: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x800493CC: sw          $v1, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r3;
    // 0x800493D0: lhu         $t2, 0x20B0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X20B0);
    // 0x800493D4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800493D8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800493DC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800493E0: lw          $t4, 0x20B8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20B8);
    // 0x800493E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800493E8: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x800493EC: lw          $t5, 0x20C8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20C8);
    // 0x800493F0: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x800493F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800493F8: sw          $t5, 0x20D0($at)
    MEM_W(0X20D0, ctx->r1) = ctx->r13;
    // 0x800493FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049400: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80049404: sw          $t6, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r14;
    // 0x80049408: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x8004940C: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x80049410: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80049414: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80049418: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8004941C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80049420: lw          $t9, 0x20C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20C0);
    // 0x80049424: lui         $t1, 0xDB06
    ctx->r9 = S32(0XDB06 << 16);
    // 0x80049428: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8004942C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80049430: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80049434: sw          $t0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r8;
    // 0x80049438: ori         $t1, $t1, 0x8
    ctx->r9 = ctx->r9 | 0X8;
    // 0x8004943C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80049440: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80049444: lhu         $t3, 0x20B0($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X20B0);
    // 0x80049448: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004944C: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x80049450: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80049454: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80049458: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8004945C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80049460: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80049464: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80049468: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8004946C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80049470: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80049474: sll         $t5, $t5, 7
    ctx->r13 = S32(ctx->r13 << 7);
    // 0x80049478: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8004947C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80049480: addiu       $t7, $t7, -0x5300
    ctx->r15 = ADD32(ctx->r15, -0X5300);
    // 0x80049484: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80049488: addu        $t4, $t6, $t7
    ctx->r12 = ADD32(ctx->r14, ctx->r15);
    // 0x8004948C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80049490: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x80049494: lw          $t9, 0x20C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20C0);
    // 0x80049498: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004949C: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x800494A0: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800494A4: lui         $t1, 0xDB06
    ctx->r9 = S32(0XDB06 << 16);
    // 0x800494A8: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800494AC: sw          $t0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r8;
    // 0x800494B0: ori         $t1, $t1, 0xC
    ctx->r9 = ctx->r9 | 0XC;
    // 0x800494B4: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800494B8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800494BC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800494C0: addiu       $t3, $t3, 0x400
    ctx->r11 = ADD32(ctx->r11, 0X400);
    // 0x800494C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800494C8: addu        $t5, $t3, $at
    ctx->r13 = ADD32(ctx->r11, ctx->r1);
    // 0x800494CC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800494D0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800494D4: lbu         $t7, -0x2B4($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2B4);
    // 0x800494D8: nop

    // 0x800494DC: beq         $t7, $zero, L_80049504
    if (ctx->r15 == 0) {
        // 0x800494E0: nop
    
            goto L_80049504;
    }
    // 0x800494E0: nop

    // 0x800494E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800494E8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800494EC: lhu         $a1, 0x20B0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X20B0);
    // 0x800494F0: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x800494F4: jal         0x80048A6C
    // 0x800494F8: nop

    wonders4_BuildScissoredFillRectDL(rdram, ctx);
        goto after_7;
    // 0x800494F8: nop

    after_7:
    // 0x800494FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049500: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
L_80049504:
    // 0x80049504: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80049508: lbu         $t4, -0x2B8($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2B8);
    // 0x8004950C: nop

    // 0x80049510: beq         $t4, $zero, L_80049538
    if (ctx->r12 == 0) {
        // 0x80049514: nop
    
            goto L_80049538;
    }
    // 0x80049514: nop

    // 0x80049518: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8004951C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80049520: lhu         $a1, 0x20B0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X20B0);
    // 0x80049524: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x80049528: jal         0x80048934
    // 0x8004952C: nop

    wonders4_BuildFillRectDL(rdram, ctx);
        goto after_8;
    // 0x8004952C: nop

    after_8:
    // 0x80049530: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049534: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
L_80049538:
    // 0x80049538: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8004953C: lw          $t8, 0x20C0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X20C0);
    // 0x80049540: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049544: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80049548: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8004954C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80049550: sw          $t9, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r25;
    // 0x80049554: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80049558: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8004955C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80049560: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80049564: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80049568: lw          $t3, 0x20C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20C0);
    // 0x8004956C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80049570: lw          $t6, -0x2B0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2B0);
    // 0x80049574: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x80049578: sw          $t5, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r13;
    // 0x8004957C: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80049580: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80049584: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80049588: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x8004958C: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x80049590: or          $t8, $t4, $at
    ctx->r24 = ctx->r12 | ctx->r1;
    // 0x80049594: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80049598: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8004959C: lhu         $t0, 0x20B0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X20B0);
    // 0x800495A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800495A4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800495A8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800495AC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800495B0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800495B4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800495B8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800495BC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800495C0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800495C4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800495C8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800495CC: sll         $t1, $t1, 7
    ctx->r9 = S32(ctx->r9 << 7);
    // 0x800495D0: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x800495D4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800495D8: addiu       $t3, $t3, -0x5300
    ctx->r11 = ADD32(ctx->r11, -0X5300);
    // 0x800495DC: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800495E0: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x800495E4: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800495E8: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800495EC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800495F0: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x800495F4: lw          $t8, -0x2A0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A0);
    // 0x800495F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800495FC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80049600: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x80049604: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x80049608: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004960C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80049610: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049614: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80049618: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004961C: lw          $t5, -0x29C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X29C);
    // 0x80049620: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80049624: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80049628: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8004962C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049630: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80049634: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80049638: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004963C: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80049640: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80049644: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80049648: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8004964C: andi        $t1, $t0, 0xFFF
    ctx->r9 = ctx->r8 & 0XFFF;
    // 0x80049650: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x80049654: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80049658: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8004965C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80049660: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80049664: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80049668: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004966C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80049670: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80049674: nop

    // 0x80049678: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8004967C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80049680: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80049684: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80049688: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8004968C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80049690: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80049694: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80049698: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x8004969C: or          $t8, $t3, $t4
    ctx->r24 = ctx->r11 | ctx->r12;
    // 0x800496A0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800496A4: lw          $t0, -0x298($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X298);
    // 0x800496A8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800496AC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800496B0: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800496B4: lw          $t3, -0x294($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X294);
    // 0x800496B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800496BC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800496C0: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800496C4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800496C8: lui         $t3, 0xFE00
    ctx->r11 = S32(0XFE00 << 16);
    // 0x800496CC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800496D0: nop

    // 0x800496D4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800496D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800496DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800496E0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800496E4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800496E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800496EC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800496F0: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800496F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800496F8: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x800496FC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80049700: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80049704: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80049708: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8004970C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80049710: nop

    // 0x80049714: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80049718: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004971C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80049720: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049724: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80049728: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8004972C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80049730: andi        $t0, $t9, 0xFFF
    ctx->r8 = ctx->r25 & 0XFFF;
    // 0x80049734: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80049738: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8004973C: lw          $t5, 0x20C0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20C0);
    // 0x80049740: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80049744: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80049748: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8004974C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80049750: sw          $t6, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r14;
    // 0x80049754: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80049758: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8004975C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80049760: addiu       $t8, $t8, 0x400
    ctx->r24 = ADD32(ctx->r24, 0X400);
    // 0x80049764: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80049768: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8004976C: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80049770: lw          $t0, 0x20C0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X20C0);
    // 0x80049774: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049778: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8004977C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80049780: lui         $t2, 0xDB04
    ctx->r10 = S32(0XDB04 << 16);
    // 0x80049784: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80049788: sw          $t1, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r9;
    // 0x8004978C: ori         $t2, $t2, 0x4
    ctx->r10 = ctx->r10 | 0X4;
    // 0x80049790: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x80049794: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80049798: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8004979C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800497A0: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x800497A4: lw          $t4, 0x20C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20C0);
    // 0x800497A8: lui         $t9, 0xDB04
    ctx->r25 = S32(0XDB04 << 16);
    // 0x800497AC: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800497B0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800497B4: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800497B8: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x800497BC: ori         $t9, $t9, 0xC
    ctx->r25 = ctx->r25 | 0XC;
    // 0x800497C0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800497C4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800497C8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800497CC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800497D0: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800497D4: lw          $t2, 0x20C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20C0);
    // 0x800497D8: lui         $t6, 0xDB04
    ctx->r14 = S32(0XDB04 << 16);
    // 0x800497DC: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x800497E0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800497E4: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800497E8: sw          $t5, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r13;
    // 0x800497EC: ori         $t6, $t6, 0x14
    ctx->r14 = ctx->r14 | 0X14;
    // 0x800497F0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800497F4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800497F8: ori         $t4, $zero, 0xFFFD
    ctx->r12 = 0 | 0XFFFD;
    // 0x800497FC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80049800: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x80049804: lw          $t9, 0x20C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20C0);
    // 0x80049808: lui         $t0, 0xDB04
    ctx->r8 = S32(0XDB04 << 16);
    // 0x8004980C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80049810: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80049814: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80049818: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x8004981C: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x80049820: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80049824: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80049828: ori         $t2, $zero, 0xFFFD
    ctx->r10 = 0 | 0XFFFD;
    // 0x8004982C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80049830: sw          $t2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r10;
    // 0x80049834: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80049838: lui         $t4, 0xD9D0
    ctx->r12 = S32(0XD9D0 << 16);
    // 0x8004983C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80049840: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80049844: addiu       $t3, $t6, 0x8
    ctx->r11 = ADD32(ctx->r14, 0X8);
    // 0x80049848: sw          $t3, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r11;
    // 0x8004984C: ori         $t4, $t4, 0xF9FA
    ctx->r12 = ctx->r12 | 0XF9FA;
    // 0x80049850: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80049854: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80049858: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004985C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80049860: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x80049864: lui         $t1, 0xD9FF
    ctx->r9 = S32(0XD9FF << 16);
    // 0x80049868: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8004986C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80049870: addiu       $t0, $t7, 0x8
    ctx->r8 = ADD32(ctx->r15, 0X8);
    // 0x80049874: sw          $t0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r8;
    // 0x80049878: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x8004987C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80049880: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80049884: lui         $t5, 0x22
    ctx->r13 = S32(0X22 << 16);
    // 0x80049888: ori         $t5, $t5, 0x5
    ctx->r13 = ctx->r13 | 0X5;
    // 0x8004988C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80049890: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80049894: lw          $t3, 0x20C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20C0);
    // 0x80049898: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x8004989C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800498A0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800498A4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800498A8: sw          $t4, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r12;
    // 0x800498AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800498B0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800498B4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800498B8: addiu       $t7, $t7, -0x290
    ctx->r15 = ADD32(ctx->r15, -0X290);
    // 0x800498BC: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800498C0: lw          $a0, 0x20C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20C0);
    // 0x800498C4: jal         0x8007DA00
    // 0x800498C8: nop

    func_8007DA00(rdram, ctx);
        goto after_9;
    // 0x800498C8: nop

    after_9:
    // 0x800498CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800498D0: sw          $v0, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r2;
    // 0x800498D4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800498D8: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x800498DC: lui         $t5, 0xE900
    ctx->r13 = S32(0XE900 << 16);
    // 0x800498E0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800498E4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800498E8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800498EC: sw          $t2, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r10;
    // 0x800498F0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800498F4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800498F8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800498FC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80049900: lw          $t4, 0x20C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20C0);
    // 0x80049904: lui         $t9, 0xDF00
    ctx->r25 = S32(0XDF00 << 16);
    // 0x80049908: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8004990C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80049910: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x80049914: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x80049918: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8004991C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80049920: jal         0x80048020
    // 0x80049924: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    wonders4_UpdateMaxScroll(rdram, ctx);
        goto after_10;
    // 0x80049924: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    after_10:
    // 0x80049928: jal         0x800480E0
    // 0x8004992C: nop

    wonders4_DebugPrintGList(rdram, ctx);
        goto after_11;
    // 0x8004992C: nop

    after_11:
    // 0x80049930: jal         0x80048150
    // 0x80049934: nop

    wonders4_DebugPrintVList(rdram, ctx);
        goto after_12;
    // 0x80049934: nop

    after_12:
    // 0x80049938: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8004993C: lhu         $t2, 0x20B0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X20B0);
    // 0x80049940: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80049944: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80049948: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8004994C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80049950: lw          $t1, 0x20C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X20C0);
    // 0x80049954: lw          $t6, 0x20B8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20B8);
    // 0x80049958: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8004995C: subu        $t3, $t1, $t6
    ctx->r11 = SUB32(ctx->r9, ctx->r14);
    // 0x80049960: sw          $t3, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->r11;
    // 0x80049964: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80049968: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x8004996C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80049970: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80049974: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x80049978: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8004997C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80049980: nop

    // 0x80049984: sw          $t0, 0x60($t7)
    MEM_W(0X60, ctx->r15) = ctx->r8;
    // 0x80049988: jal         0x800B6650
    // 0x8004998C: sw          $t1, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->r9;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_13;
    // 0x8004998C: sw          $t1, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->r9;
    after_13:
    // 0x80049990: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80049994: jal         0x800B679C
    // 0x80049998: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_14;
    // 0x80049998: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_14:
    // 0x8004999C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800499A0: jal         0x800B692C
    // 0x800499A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_15;
    // 0x800499A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_15:
    // 0x800499A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800499AC: addiu       $a0, $a0, 0x20D8
    ctx->r4 = ADD32(ctx->r4, 0X20D8);
    // 0x800499B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800499B4: jal         0x800B3C20
    // 0x800499B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_16;
    // 0x800499B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x800499BC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800499C0: addiu       $t2, $t2, 0x31C0
    ctx->r10 = ADD32(ctx->r10, 0X31C0);
    // 0x800499C4: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x800499C8: lw          $a3, 0xC($t2)
    ctx->r7 = MEM_W(ctx->r10, 0XC);
    // 0x800499CC: jal         0x800B6970
    // 0x800499D0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    osDpSetNextBuffer_recomp(rdram, ctx);
        goto after_17;
    // 0x800499D0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_17:
    // 0x800499D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800499D8: addiu       $a0, $a0, 0x20F0
    ctx->r4 = ADD32(ctx->r4, 0X20F0);
    // 0x800499DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800499E0: jal         0x800B3C20
    // 0x800499E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_18;
    // 0x800499E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_18:
    // 0x800499E8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800499EC: lhu         $t5, 0x20B0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X20B0);
    // 0x800499F0: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x800499F4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800499F8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800499FC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80049A00: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80049A04: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80049A08: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80049A0C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80049A10: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80049A14: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80049A18: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80049A1C: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x80049A20: addiu       $t3, $t3, -0x5300
    ctx->r11 = ADD32(ctx->r11, -0X5300);
    // 0x80049A24: jal         0x800B64F0
    // 0x80049A28: addu        $a0, $t6, $t3
    ctx->r4 = ADD32(ctx->r14, ctx->r11);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_19;
    // 0x80049A28: addu        $a0, $t6, $t3
    ctx->r4 = ADD32(ctx->r14, ctx->r11);
    after_19:
    // 0x80049A2C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80049A30: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80049A34: lw          $t8, 0x2118($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2118);
    // 0x80049A38: lw          $t4, 0x2110($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2110);
    // 0x80049A3C: nop

    // 0x80049A40: slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80049A44: bne         $at, $zero, L_80049A60
    if (ctx->r1 != 0) {
        // 0x80049A48: nop
    
            goto L_80049A60;
    }
    // 0x80049A48: nop

    // 0x80049A4C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049A50: addiu       $a0, $a0, 0x2108
    ctx->r4 = ADD32(ctx->r4, 0X2108);
    // 0x80049A54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049A58: jal         0x800B3C20
    // 0x80049A5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_20;
    // 0x80049A5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
L_80049A60:
    // 0x80049A60: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049A64: addiu       $a0, $a0, 0x2108
    ctx->r4 = ADD32(ctx->r4, 0X2108);
    // 0x80049A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049A6C: jal         0x800B3C20
    // 0x80049A70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_21;
    // 0x80049A70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_21:
    // 0x80049A74: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80049A78: lhu         $t9, 0x20B0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X20B0);
    // 0x80049A7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049A80: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x80049A84: jal         0x800B6550
    // 0x80049A88: sh          $t0, 0x20B0($at)
    MEM_H(0X20B0, ctx->r1) = ctx->r8;
    osGetTime_recomp(rdram, ctx);
        goto after_22;
    // 0x80049A88: sh          $t0, 0x20B0($at)
    MEM_H(0X20B0, ctx->r1) = ctx->r8;
    after_22:
    // 0x80049A8C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80049A90: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80049A94: lw          $t7, 0x54($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X54);
    // 0x80049A98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049A9C: sw          $v0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r2;
    // 0x80049AA0: sw          $v1, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r3;
    // 0x80049AA4: lw          $t2, -0x128($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X128);
    // 0x80049AA8: nop

    // 0x80049AAC: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x80049AB0: b           L_80049388
    // 0x80049AB4: sw          $t5, -0x128($at)
    MEM_W(-0X128, ctx->r1) = ctx->r13;
        goto L_80049388;
    // 0x80049AB4: sw          $t5, -0x128($at)
    MEM_W(-0X128, ctx->r1) = ctx->r13;
    // 0x80049AB8: nop

    // 0x80049ABC: nop

    // 0x80049AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049AC4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80049AC8: jr          $ra
    // 0x80049ACC: nop

    return;
    // 0x80049ACC: nop

;}

RECOMP_FUNC void four_arguments_get_debug_printed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049AD0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80049AD4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80049AD8: jal         0x800614A8
    // 0x80049ADC: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    func_800614A8(rdram, ctx);
        goto after_0;
    // 0x80049ADC: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    after_0:
    // 0x80049AE0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049AE4: jal         0x800B3BFC
    // 0x80049AE8: addiu       $a0, $a0, -0x3FA0
    ctx->r4 = ADD32(ctx->r4, -0X3FA0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x80049AE8: addiu       $a0, $a0, -0x3FA0
    ctx->r4 = ADD32(ctx->r4, -0X3FA0);
    after_1:
    // 0x80049AEC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049AF0: addiu       $a0, $a0, -0x6A90
    ctx->r4 = ADD32(ctx->r4, -0X6A90);
    // 0x80049AF4: jal         0x800B6A20
    // 0x80049AF8: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    osViSetMode_recomp(rdram, ctx);
        goto after_2;
    // 0x80049AF8: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_2:
    // 0x80049AFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049B00: jal         0x800B3BFC
    // 0x80049B04: addiu       $a0, $a0, -0x3F98
    ctx->r4 = ADD32(ctx->r4, -0X3F98);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x80049B04: addiu       $a0, $a0, -0x3F98
    ctx->r4 = ADD32(ctx->r4, -0X3F98);
    after_3:
    // 0x80049B08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80049B0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049B10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049B14: sb          $t6, -0x1E0($at)
    MEM_B(-0X1E0, ctx->r1) = ctx->r14;
    // 0x80049B18: jal         0x800B3BFC
    // 0x80049B1C: addiu       $a0, $a0, -0x3F90
    ctx->r4 = ADD32(ctx->r4, -0X3F90);
    rmonPrintf_recomp(rdram, ctx);
        goto after_4;
    // 0x80049B1C: addiu       $a0, $a0, -0x3F90
    ctx->r4 = ADD32(ctx->r4, -0X3F90);
    after_4:
    // 0x80049B20: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80049B24: lw          $t8, 0xEB4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XEB4);
    // 0x80049B28: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80049B2C: addiu       $t7, $t7, -0x830
    ctx->r15 = ADD32(ctx->r15, -0X830);
    // 0x80049B30: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80049B34: jal         0x8007DFC0
    // 0x80049B38: subu        $a1, $t8, $t7
    ctx->r5 = SUB32(ctx->r24, ctx->r15);
    n64HeapInit(rdram, ctx);
        goto after_5;
    // 0x80049B38: subu        $a1, $t8, $t7
    ctx->r5 = SUB32(ctx->r24, ctx->r15);
    after_5:
    // 0x80049B3C: lui         $a0, 0xB
    ctx->r4 = S32(0XB << 16);
    // 0x80049B40: lui         $a1, 0xB
    ctx->r5 = S32(0XB << 16);
    // 0x80049B44: addiu       $a1, $a1, -0x2520
    ctx->r5 = ADD32(ctx->r5, -0X2520);
    // 0x80049B48: jal         0x800A9E44
    // 0x80049B4C: addiu       $a0, $a0, -0x7E70
    ctx->r4 = ADD32(ctx->r4, -0X7E70);
    func_800A9E44(rdram, ctx);
        goto after_6;
    // 0x80049B4C: addiu       $a0, $a0, -0x7E70
    ctx->r4 = ADD32(ctx->r4, -0X7E70);
    after_6:
    // 0x80049B50: jal         0x8007CF40
    // 0x80049B54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8007CF40(rdram, ctx);
        goto after_7;
    // 0x80049B54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80049B58: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049B5C: jal         0x800B3BFC
    // 0x80049B60: addiu       $a0, $a0, -0x3F88
    ctx->r4 = ADD32(ctx->r4, -0X3F88);
    rmonPrintf_recomp(rdram, ctx);
        goto after_8;
    // 0x80049B60: addiu       $a0, $a0, -0x3F88
    ctx->r4 = ADD32(ctx->r4, -0X3F88);
    after_8:
    // 0x80049B64: jal         0x80061124
    // 0x80049B68: nop

    PFGFX_SetViModeRequest(rdram, ctx);
        goto after_9;
    // 0x80049B68: nop

    after_9:
    // 0x80049B6C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80049B70: addiu       $t9, $t9, -0x5910
    ctx->r25 = ADD32(ctx->r25, -0X5910);
    // 0x80049B74: addiu       $t1, $t9, 0x48
    ctx->r9 = ADD32(ctx->r25, 0X48);
    // 0x80049B78: or          $t2, $sp, $zero
    ctx->r10 = ctx->r29 | 0;
L_80049B7C:
    // 0x80049B7C: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80049B80: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80049B84: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80049B88: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x80049B8C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80049B90: sw          $at, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r1;
    // 0x80049B94: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x80049B98: bne         $t9, $t1, L_80049B7C
    if (ctx->r25 != ctx->r9) {
        // 0x80049B9C: sw          $at, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r1;
            goto L_80049B7C;
    }
    // 0x80049B9C: sw          $at, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r1;
    // 0x80049BA0: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80049BA4: nop

    // 0x80049BA8: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80049BAC: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80049BB0: nop

    // 0x80049BB4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80049BB8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80049BBC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80049BC0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80049BC4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x80049BC8: jal         0x80060D10
    // 0x80049BCC: nop

    func_80060D10(rdram, ctx);
        goto after_10;
    // 0x80049BCC: nop

    after_10:
    // 0x80049BD0: addiu       $t3, $zero, 0x190
    ctx->r11 = ADD32(0, 0X190);
    // 0x80049BD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049BD8: sw          $t3, -0x2B0($at)
    MEM_W(-0X2B0, ctx->r1) = ctx->r11;
    // 0x80049BDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049BE0: addiu       $t4, $zero, 0x12C
    ctx->r12 = ADD32(0, 0X12C);
    // 0x80049BE4: sw          $t4, -0x2AC($at)
    MEM_W(-0X2AC, ctx->r1) = ctx->r12;
    // 0x80049BE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049BEC: sw          $zero, -0x2A0($at)
    MEM_W(-0X2A0, ctx->r1) = 0;
    // 0x80049BF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049BF4: sw          $zero, -0x29C($at)
    MEM_W(-0X29C, ctx->r1) = 0;
    // 0x80049BF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049BFC: addiu       $t5, $zero, 0x190
    ctx->r13 = ADD32(0, 0X190);
    // 0x80049C00: sw          $t5, -0x298($at)
    MEM_W(-0X298, ctx->r1) = ctx->r13;
    // 0x80049C04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049C08: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x80049C0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049C10: sw          $t6, -0x294($at)
    MEM_W(-0X294, ctx->r1) = ctx->r14;
    // 0x80049C14: jal         0x800B3BFC
    // 0x80049C18: addiu       $a0, $a0, -0x3F80
    ctx->r4 = ADD32(ctx->r4, -0X3F80);
    rmonPrintf_recomp(rdram, ctx);
        goto after_11;
    // 0x80049C18: addiu       $a0, $a0, -0x3F80
    ctx->r4 = ADD32(ctx->r4, -0X3F80);
    after_11:
    // 0x80049C1C: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    // 0x80049C20: jal         0x8006110C
    // 0x80049C24: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    PFGFX_RequestViModeChange(rdram, ctx);
        goto after_12;
    // 0x80049C24: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_12:
    // 0x80049C28: jal         0x80060E30
    // 0x80049C2C: nop

    PFGFX_ApplyViMode(rdram, ctx);
        goto after_13;
    // 0x80049C2C: nop

    after_13:
L_80049C30:
    // 0x80049C30: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80049C34: addiu       $a0, $a0, -0x44F8
    ctx->r4 = ADD32(ctx->r4, -0X44F8);
    // 0x80049C38: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80049C3C: jal         0x800B3C20
    // 0x80049C40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x80049C40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x80049C44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80049C48: jal         0x800B3BFC
    // 0x80049C4C: addiu       $a0, $a0, -0x3F78
    ctx->r4 = ADD32(ctx->r4, -0X3F78);
    rmonPrintf_recomp(rdram, ctx);
        goto after_15;
    // 0x80049C4C: addiu       $a0, $a0, -0x3F78
    ctx->r4 = ADD32(ctx->r4, -0X3F78);
    after_15:
    // 0x80049C50: b           L_80049C30
    // 0x80049C54: nop

        goto L_80049C30;
    // 0x80049C54: nop

    // 0x80049C58: nop

    // 0x80049C5C: nop

    // 0x80049C60: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80049C64: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80049C68: jr          $ra
    // 0x80049C6C: nop

    return;
    // 0x80049C6C: nop

;}

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
    wonders4_ComputeClampedRatio(rdram, ctx);
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

RECOMP_FUNC void wonders4_ComputeClampedRatio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9010: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800A9014: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800A9018: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800A901C: lw          $t7, -0x6A20($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6A20);
    // 0x800A9020: lw          $t6, -0x6A1C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6A1C);
    // 0x800A9024: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A9028: lui         $at, 0x4390
    ctx->r1 = S32(0X4390 << 16);
    // 0x800A902C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A9030: addiu       $at, $zero, 0x2625
    ctx->r1 = ADD32(0, 0X2625);
    // 0x800A9034: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800A9038: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x800A903C: mflo        $t9
    ctx->r25 = lo;
    // 0x800A9040: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800A9044: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A9048: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A904C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800A9050: bgez        $t9, L_800A9068
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800A9054: cvt.s.w     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800A9068;
    }
    // 0x800A9054: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A9058: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A905C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A9060: nop

    // 0x800A9064: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_800A9068:
    // 0x800A9068: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x800A906C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x800A9070: bc1fl       L_800A9080
    if (!c1cs) {
        // 0x800A9074: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_800A9080;
    }
    goto skip_0;
    // 0x800A9074: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_0:
    // 0x800A9078: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800A907C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_800A9080:
    // 0x800A9080: nop

    // 0x800A9084: bc1f        L_800A90A8
    if (!c1cs) {
        // 0x800A9088: lui         $at, 0x4300
        ctx->r1 = S32(0X4300 << 16);
            goto L_800A90A8;
    }
    // 0x800A9088: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800A908C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A9090: nop

    // 0x800A9094: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x800A9098: nop

    // 0x800A909C: bc1fl       L_800A90AC
    if (!c1cs) {
        // 0x800A90A0: lui         $at, 0x4300
        ctx->r1 = S32(0X4300 << 16);
            goto L_800A90AC;
    }
    goto skip_1;
    // 0x800A90A0: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    skip_1:
    // 0x800A90A4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800A90A8:
    // 0x800A90A8: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
L_800A90AC:
    // 0x800A90AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A90B0: nop

    // 0x800A90B4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800A90B8: nop

    // 0x800A90BC: bc1f        L_800A90E0
    if (!c1cs) {
        // 0x800A90C0: lui         $at, 0x4340
        ctx->r1 = S32(0X4340 << 16);
            goto L_800A90E0;
    }
    // 0x800A90C0: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x800A90C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A90C8: nop

    // 0x800A90CC: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x800A90D0: nop

    // 0x800A90D4: bc1fl       L_800A90E4
    if (!c1cs) {
        // 0x800A90D8: lui         $at, 0x4340
        ctx->r1 = S32(0X4340 << 16);
            goto L_800A90E4;
    }
    goto skip_2;
    // 0x800A90D8: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    skip_2:
    // 0x800A90DC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800A90E0:
    // 0x800A90E0: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
L_800A90E4:
    // 0x800A90E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A90E8: nop

    // 0x800A90EC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800A90F0: nop

    // 0x800A90F4: bc1f        L_800A9118
    if (!c1cs) {
        // 0x800A90F8: lui         $at, 0x4380
        ctx->r1 = S32(0X4380 << 16);
            goto L_800A9118;
    }
    // 0x800A90F8: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800A90FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A9100: nop

    // 0x800A9104: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x800A9108: nop

    // 0x800A910C: bc1fl       L_800A911C
    if (!c1cs) {
        // 0x800A9110: div.s       $f8, $f0, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
            goto L_800A911C;
    }
    goto skip_3;
    // 0x800A9110: div.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
    skip_3:
    // 0x800A9114: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800A9118:
    // 0x800A9118: div.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
L_800A911C:
    // 0x800A911C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A9120: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9124: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800A9128: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800A912C: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x800A9130: addiu       $t2, $zero, 0xD2
    ctx->r10 = ADD32(0, 0XD2);
    // 0x800A9134: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A9138: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A913C: addiu       $t5, $zero, 0x85
    ctx->r13 = ADD32(0, 0X85);
    // 0x800A9140: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800A9144: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800A9148: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800A914C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800A9150: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800A9154: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800A9158: addiu       $a2, $a2, 0x7430
    ctx->r6 = ADD32(ctx->r6, 0X7430);
    // 0x800A915C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A9160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A9164: addiu       $a3, $zero, 0x120
    ctx->r7 = ADD32(0, 0X120);
    // 0x800A9168: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800A916C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800A9170: jal         0x800B1BFC
    // 0x800A9174: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1BFC(rdram, ctx);
        goto after_0;
    // 0x800A9174: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800A9178: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800A917C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800A9180: lw          $t7, -0x6A18($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6A18);
    // 0x800A9184: lw          $t6, -0x6A14($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6A14);
    // 0x800A9188: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A918C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A9190: addiu       $at, $zero, 0x2625
    ctx->r1 = ADD32(0, 0X2625);
    // 0x800A9194: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800A9198: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x800A919C: mflo        $t9
    ctx->r25 = lo;
    // 0x800A91A0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800A91A4: bgez        $t9, L_800A91BC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800A91A8: cvt.s.w     $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800A91BC;
    }
    // 0x800A91A8: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A91AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A91B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A91B4: nop

    // 0x800A91B8: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_800A91BC:
    // 0x800A91BC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800A91C0: lui         $at, 0x4390
    ctx->r1 = S32(0X4390 << 16);
    // 0x800A91C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A91C8: bc1fl       L_800A91D8
    if (!c1cs) {
        // 0x800A91CC: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800A91D8;
    }
    goto skip_4;
    // 0x800A91CC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_4:
    // 0x800A91D0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800A91D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800A91D8:
    // 0x800A91D8: nop

    // 0x800A91DC: bc1fl       L_800A91EC
    if (!c1cs) {
        // 0x800A91E0: div.s       $f4, $f2, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
            goto L_800A91EC;
    }
    goto skip_5;
    // 0x800A91E0: div.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    skip_5:
    // 0x800A91E4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800A91E8: div.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
L_800A91EC:
    // 0x800A91EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A91F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A91F4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800A91F8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800A91FC: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x800A9200: addiu       $t2, $zero, 0xD5
    ctx->r10 = ADD32(0, 0XD5);
    // 0x800A9204: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A9208: addiu       $t4, $zero, 0x85
    ctx->r12 = ADD32(0, 0X85);
    // 0x800A920C: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x800A9210: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800A9214: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800A9218: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800A921C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800A9220: addiu       $a2, $a2, 0x7430
    ctx->r6 = ADD32(ctx->r6, 0X7430);
    // 0x800A9224: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A9228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A922C: addiu       $a3, $zero, 0x120
    ctx->r7 = ADD32(0, 0X120);
    // 0x800A9230: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800A9234: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800A9238: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800A923C: jal         0x800B1BFC
    // 0x800A9240: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800B1BFC(rdram, ctx);
        goto after_1;
    // 0x800A9240: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800A9244: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A9248: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A924C: lw          $a1, -0x6A0C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6A0C);
    // 0x800A9250: lw          $a0, -0x6A10($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A10);
    // 0x800A9254: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A9258: jal         0x800B7658
    // 0x800A925C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_2;
    // 0x800A925C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_2:
    // 0x800A9260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A9264: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800A9268: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A926C: jal         0x800B7558
    // 0x800A9270: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    __ull_div_recomp(rdram, ctx);
        goto after_3;
    // 0x800A9270: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_3:
    // 0x800A9274: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A9278: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800A927C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A9280: jal         0x800B7558
    // 0x800A9284: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    __ull_div_recomp(rdram, ctx);
        goto after_4;
    // 0x800A9284: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    after_4:
    // 0x800A9288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A928C: jal         0x800BAF68
    // 0x800A9290: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_to_f_recomp(rdram, ctx);
        goto after_5;
    // 0x800A9290: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_5:
    // 0x800A9294: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A9298: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A929C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800A92A0: lui         $at, 0x4390
    ctx->r1 = S32(0X4390 << 16);
    // 0x800A92A4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800A92A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A92AC: bc1fl       L_800A92BC
    if (!c1cs) {
        // 0x800A92B0: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800A92BC;
    }
    goto skip_6;
    // 0x800A92B0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_6:
    // 0x800A92B4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800A92B8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800A92BC:
    // 0x800A92BC: nop

    // 0x800A92C0: bc1fl       L_800A92D0
    if (!c1cs) {
        // 0x800A92C4: div.s       $f8, $f2, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
            goto L_800A92D0;
    }
    goto skip_7;
    // 0x800A92C4: div.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    skip_7:
    // 0x800A92C8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800A92CC: div.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
L_800A92D0:
    // 0x800A92D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A92D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A92D8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800A92DC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800A92E0: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800A92E4: addiu       $t7, $zero, 0xD8
    ctx->r15 = ADD32(0, 0XD8);
    // 0x800A92E8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A92EC: addiu       $t9, $zero, 0x85
    ctx->r25 = ADD32(0, 0X85);
    // 0x800A92F0: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800A92F4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800A92F8: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800A92FC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800A9300: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800A9304: addiu       $a2, $a2, 0x7430
    ctx->r6 = ADD32(ctx->r6, 0X7430);
    // 0x800A9308: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A930C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A9310: addiu       $a3, $zero, 0x120
    ctx->r7 = ADD32(0, 0X120);
    // 0x800A9314: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800A9318: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800A931C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800A9320: jal         0x800B1BFC
    // 0x800A9324: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1BFC(rdram, ctx);
        goto after_6;
    // 0x800A9324: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x800A9328: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A932C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A9330: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A9334: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800A9338: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x800A933C: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x800A9340: addiu       $t2, $zero, 0xDB
    ctx->r10 = ADD32(0, 0XDB);
    // 0x800A9344: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A9348: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A934C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A9350: addiu       $t6, $zero, 0x85
    ctx->r14 = ADD32(0, 0X85);
    // 0x800A9354: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800A9358: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800A935C: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800A9360: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800A9364: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800A9368: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800A936C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800A9370: addiu       $a2, $a2, 0x6228
    ctx->r6 = ADD32(ctx->r6, 0X6228);
    // 0x800A9374: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A9378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A937C: addiu       $a3, $zero, 0x120
    ctx->r7 = ADD32(0, 0X120);
    // 0x800A9380: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x800A9384: jal         0x800B1BFC
    // 0x800A9388: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    func_800B1BFC(rdram, ctx);
        goto after_7;
    // 0x800A9388: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x800A938C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A9390: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800A9394: jr          $ra
    // 0x800A9398: nop

    return;
    // 0x800A9398: nop

;}

RECOMP_FUNC void func_800A939C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A939C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A93A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A93A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A93A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A93AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A93B0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800A93B4: jal         0x8007E03C
    // 0x800A93B8: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800A93B8: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    after_0:
    // 0x800A93BC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A93C0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800A93C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A93C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800A93CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A93D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800A93D4:
    // 0x800A93D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A93D8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800A93DC: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x800A93E0: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x800A93E4: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x800A93E8: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x800A93EC: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x800A93F0: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x800A93F4: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x800A93F8: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x800A93FC: sh          $zero, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = 0;
    // 0x800A9400: sw          $t9, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r25;
    // 0x800A9404: sw          $t8, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r24;
    // 0x800A9408: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800A940C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800A9410: sh          $zero, 0x28($v1)
    MEM_H(0X28, ctx->r3) = 0;
    // 0x800A9414: sw          $t3, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r11;
    // 0x800A9418: sw          $t2, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r10;
    // 0x800A941C: sw          $t5, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r13;
    // 0x800A9420: bne         $a0, $a1, L_800A93D4
    if (ctx->r4 != ctx->r5) {
        // 0x800A9424: sw          $t4, 0x38($v1)
        MEM_W(0X38, ctx->r3) = ctx->r12;
            goto L_800A93D4;
    }
    // 0x800A9424: sw          $t4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r12;
    // 0x800A9428: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x800A942C: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x800A9430: sb          $zero, 0x38($v0)
    MEM_B(0X38, ctx->r2) = 0;
    // 0x800A9434: sb          $zero, 0x39($v0)
    MEM_B(0X39, ctx->r2) = 0;
    // 0x800A9438: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x800A943C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800A9440: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A9444: sb          $t7, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r15;
    // 0x800A9448: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800A944C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800A9450: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800A9454: sb          $t6, 0x71($v0)
    MEM_B(0X71, ctx->r2) = ctx->r14;
    // 0x800A9458: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x800A945C: sb          $t8, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r24;
    // 0x800A9460: lw          $t9, 0x7AF0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7AF0);
    // 0x800A9464: bne         $t9, $zero, L_800A947C
    if (ctx->r25 != 0) {
        // 0x800A9468: nop
    
            goto L_800A947C;
    }
    // 0x800A9468: nop

    // 0x800A946C: sw          $v0, 0x7AF0($at)
    MEM_W(0X7AF0, ctx->r1) = ctx->r2;
    // 0x800A9470: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A9474: b           L_800A948C
    // 0x800A9478: sw          $v0, 0x7AF4($at)
    MEM_W(0X7AF4, ctx->r1) = ctx->r2;
        goto L_800A948C;
    // 0x800A9478: sw          $v0, 0x7AF4($at)
    MEM_W(0X7AF4, ctx->r1) = ctx->r2;
L_800A947C:
    // 0x800A947C: lw          $t0, 0x7AF4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7AF4);
    // 0x800A9480: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A9484: sw          $v0, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r2;
    // 0x800A9488: sw          $v0, 0x7AF4($at)
    MEM_W(0X7AF4, ctx->r1) = ctx->r2;
L_800A948C:
    // 0x800A948C: lw          $t1, 0x7AF4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7AF4);
    // 0x800A9490: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800A9494: sw          $zero, 0x74($t1)
    MEM_W(0X74, ctx->r9) = 0;
    // 0x800A9498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A949C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A94A0: jr          $ra
    // 0x800A94A4: nop

    return;
    // 0x800A94A4: nop

;}

RECOMP_FUNC void func_800A94A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A94A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A94AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A94B0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A94B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A94B8: bnel        $t6, $at, L_800A950C
    if (ctx->r14 != ctx->r1) {
        // 0x800A94BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A950C;
    }
    goto skip_0;
    // 0x800A94BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A94C0: jal         0x800B6540
    // 0x800A94C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x800A94C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A94C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A94CC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x800A94D0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800A94D4: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800A94D8: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A94DC: mflo        $t0
    ctx->r8 = lo;
    // 0x800A94E0: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800A94E4: sw          $t8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r24;
    // 0x800A94E8: sw          $v0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r2;
    // 0x800A94EC: lbu         $t2, 0x4($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X4);
    // 0x800A94F0: multu       $t2, $a1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A94F4: mflo        $t3
    ctx->r11 = lo;
    // 0x800A94F8: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
    // 0x800A94FC: lhu         $t4, 0x8($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X8);
    // 0x800A9500: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x800A9504: sh          $t5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r13;
    // 0x800A9508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A950C:
    // 0x800A950C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9510: jr          $ra
    // 0x800A9514: nop

    return;
    // 0x800A9514: nop

;}

RECOMP_FUNC void func_800A9518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A951C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9520: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A9524: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9528: bnel        $t6, $at, L_800A9580
    if (ctx->r14 != ctx->r1) {
        // 0x800A952C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A9580;
    }
    goto skip_0;
    // 0x800A952C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A9530: jal         0x800B6540
    // 0x800A9534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x800A9534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A9538: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A953C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x800A9540: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800A9544: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800A9548: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A954C: mflo        $t0
    ctx->r8 = lo;
    // 0x800A9550: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800A9554: sw          $t8, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r24;
    // 0x800A9558: sw          $v0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r2;
    // 0x800A955C: lbu         $t2, 0x4($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X4);
    // 0x800A9560: multu       $t2, $a1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9564: mflo        $t3
    ctx->r11 = lo;
    // 0x800A9568: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
    // 0x800A956C: lhu         $t4, 0x8($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X8);
    // 0x800A9570: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x800A9574: jal         0x800A9854
    // 0x800A9578: sh          $t5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r13;
    func_800A9854(rdram, ctx);
        goto after_1;
    // 0x800A9578: sh          $t5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r13;
    after_1:
    // 0x800A957C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9580:
    // 0x800A9580: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9584: jr          $ra
    // 0x800A9588: nop

    return;
    // 0x800A9588: nop

;}

RECOMP_FUNC void func_800A958C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A958C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A9590: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9594: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A9598: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A959C: bnel        $t6, $at, L_800A95EC
    if (ctx->r14 != ctx->r1) {
        // 0x800A95A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A95EC;
    }
    goto skip_0;
    // 0x800A95A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A95A4: jal         0x800B6550
    // 0x800A95A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x800A95A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A95AC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800A95B0: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x800A95B4: lbu         $t7, 0x4($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X4);
    // 0x800A95B8: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A95BC: mflo        $t8
    ctx->r24 = lo;
    // 0x800A95C0: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800A95C4: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
    // 0x800A95C8: sw          $v1, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r3;
    // 0x800A95CC: lbu         $t0, 0x4($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X4);
    // 0x800A95D0: multu       $t0, $a2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A95D4: mflo        $t1
    ctx->r9 = lo;
    // 0x800A95D8: addu        $a0, $a1, $t1
    ctx->r4 = ADD32(ctx->r5, ctx->r9);
    // 0x800A95DC: lhu         $t2, 0x8($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X8);
    // 0x800A95E0: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x800A95E4: sh          $t3, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r11;
    // 0x800A95E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A95EC:
    // 0x800A95EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A95F0: jr          $ra
    // 0x800A95F4: nop

    return;
    // 0x800A95F4: nop

;}

RECOMP_FUNC void func_800A95F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A95F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A95FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9600: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A9604: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9608: bnel        $t6, $at, L_800A965C
    if (ctx->r14 != ctx->r1) {
        // 0x800A960C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A965C;
    }
    goto skip_0;
    // 0x800A960C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A9610: jal         0x800B6550
    // 0x800A9614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x800A9614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A9618: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A961C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x800A9620: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800A9624: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9628: mflo        $t8
    ctx->r24 = lo;
    // 0x800A962C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800A9630: sw          $v0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r2;
    // 0x800A9634: sw          $v1, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r3;
    // 0x800A9638: lbu         $t0, 0x4($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X4);
    // 0x800A963C: multu       $t0, $a2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9640: mflo        $t1
    ctx->r9 = lo;
    // 0x800A9644: addu        $a1, $a0, $t1
    ctx->r5 = ADD32(ctx->r4, ctx->r9);
    // 0x800A9648: lhu         $t2, 0x8($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0X8);
    // 0x800A964C: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x800A9650: jal         0x800A9854
    // 0x800A9654: sh          $t3, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r11;
    func_800A9854(rdram, ctx);
        goto after_1;
    // 0x800A9654: sh          $t3, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r11;
    after_1:
    // 0x800A9658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A965C:
    // 0x800A965C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9660: jr          $ra
    // 0x800A9664: nop

    return;
    // 0x800A9664: nop

;}

RECOMP_FUNC void func_800A9668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9668: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A966C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9670: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A9674: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800A9678: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A967C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9680: bnel        $t6, $at, L_800A96E8
    if (ctx->r14 != ctx->r1) {
        // 0x800A9684: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A96E8;
    }
    goto skip_0;
    // 0x800A9684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A9688: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800A968C: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800A9690: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9694: mflo        $t0
    ctx->r8 = lo;
    // 0x800A9698: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800A969C: sw          $a2, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r6;
    // 0x800A96A0: sw          $a3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r7;
    // 0x800A96A4: lbu         $t4, 0x4($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X4);
    // 0x800A96A8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800A96AC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800A96B0: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A96B4: mflo        $t5
    ctx->r13 = lo;
    // 0x800A96B8: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x800A96BC: sw          $t3, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r11;
    // 0x800A96C0: sw          $t2, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r10;
    // 0x800A96C4: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800A96C8: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A96CC: mflo        $t0
    ctx->r8 = lo;
    // 0x800A96D0: addu        $v0, $a0, $t0
    ctx->r2 = ADD32(ctx->r4, ctx->r8);
    // 0x800A96D4: lhu         $t8, 0x8($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X8);
    // 0x800A96D8: ori         $t9, $t8, 0x3
    ctx->r25 = ctx->r24 | 0X3;
    // 0x800A96DC: jal         0x800A9854
    // 0x800A96E0: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    func_800A9854(rdram, ctx);
        goto after_0;
    // 0x800A96E0: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    after_0:
    // 0x800A96E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A96E8:
    // 0x800A96E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A96EC: jr          $ra
    // 0x800A96F0: nop

    return;
    // 0x800A96F0: nop

;}

RECOMP_FUNC void func_800A96F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A96F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A96F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A96FC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A9700: bnel        $t6, $zero, L_800A974C
    if (ctx->r14 != 0) {
        // 0x800A9704: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A974C;
    }
    goto skip_0;
    // 0x800A9704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A9708: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800A970C: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800A9710: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800A9714: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9718: mflo        $t0
    ctx->r8 = lo;
    // 0x800A971C: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800A9720: sw          $t8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r24;
    // 0x800A9724: sw          $a1, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r5;
    // 0x800A9728: lbu         $t2, 0x4($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X4);
    // 0x800A972C: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9730: mflo        $t3
    ctx->r11 = lo;
    // 0x800A9734: addu        $v0, $a0, $t3
    ctx->r2 = ADD32(ctx->r4, ctx->r11);
    // 0x800A9738: lhu         $t4, 0x8($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X8);
    // 0x800A973C: ori         $t5, $t4, 0x3
    ctx->r13 = ctx->r12 | 0X3;
    // 0x800A9740: jal         0x800A9854
    // 0x800A9744: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    func_800A9854(rdram, ctx);
        goto after_0;
    // 0x800A9744: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    after_0:
    // 0x800A9748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A974C:
    // 0x800A974C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9750: jr          $ra
    // 0x800A9754: nop

    return;
    // 0x800A9754: nop

;}

RECOMP_FUNC void func_800A9758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9758: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A975C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A9760: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800A9764: lw          $s0, 0x7AF0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7AF0);
    // 0x800A9768: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A976C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A9770: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800A9774: beq         $s0, $zero, L_800A9838
    if (ctx->r16 == 0) {
        // 0x800A9778: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_800A9838;
    }
    // 0x800A9778: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A977C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800A9780: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x800A9784: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // 0x800A9788: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
L_800A978C:
    // 0x800A978C: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9790: mflo        $t7
    ctx->r15 = lo;
    // 0x800A9794: addu        $v0, $s0, $t7
    ctx->r2 = ADD32(ctx->r16, ctx->r15);
    // 0x800A9798: lhu         $t8, 0x8($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X8);
    // 0x800A979C: bnel        $s2, $t8, L_800A9830
    if (ctx->r18 != ctx->r24) {
        // 0x800A97A0: lw          $s0, 0x74($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X74);
            goto L_800A9830;
    }
    goto skip_0;
    // 0x800A97A0: lw          $s0, 0x74($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x800A97A4: lbu         $t9, 0x38($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X38);
    // 0x800A97A8: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x800A97AC: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x800A97B0: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A97B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A97B8: mflo        $t2
    ctx->r10 = lo;
    // 0x800A97BC: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800A97C0: sw          $t0, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->r8;
    // 0x800A97C4: sw          $t1, 0x4C($t3)
    MEM_W(0X4C, ctx->r11) = ctx->r9;
    // 0x800A97C8: lbu         $t4, 0x5($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X5);
    // 0x800A97CC: lbu         $t7, 0x38($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X38);
    // 0x800A97D0: multu       $t4, $s1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A97D4: mflo        $t5
    ctx->r13 = lo;
    // 0x800A97D8: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800A97DC: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x800A97E0: multu       $t7, $s1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A97E4: lw          $t9, 0x1C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X1C);
    // 0x800A97E8: mflo        $t2
    ctx->r10 = lo;
    // 0x800A97EC: addu        $t0, $s0, $t2
    ctx->r8 = ADD32(ctx->r16, ctx->r10);
    // 0x800A97F0: sw          $t8, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->r24;
    // 0x800A97F4: sw          $t9, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r25;
    // 0x800A97F8: lbu         $t1, 0x5($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X5);
    // 0x800A97FC: multu       $t1, $s1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9800: mflo        $t3
    ctx->r11 = lo;
    // 0x800A9804: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x800A9808: sh          $zero, 0x8($t4)
    MEM_H(0X8, ctx->r12) = 0;
    // 0x800A980C: lbu         $t5, 0x38($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X38);
    // 0x800A9810: multu       $t5, $s1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9814: mflo        $t6
    ctx->r14 = lo;
    // 0x800A9818: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800A981C: jal         0x800A9878
    // 0x800A9820: sh          $s3, 0x40($t7)
    MEM_H(0X40, ctx->r15) = ctx->r19;
    func_800A9878(rdram, ctx);
        goto after_0;
    // 0x800A9820: sh          $s3, 0x40($t7)
    MEM_H(0X40, ctx->r15) = ctx->r19;
    after_0:
    // 0x800A9824: jal         0x800A989C
    // 0x800A9828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A989C(rdram, ctx);
        goto after_1;
    // 0x800A9828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A982C: lw          $s0, 0x74($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X74);
L_800A9830:
    // 0x800A9830: bnel        $s0, $zero, L_800A978C
    if (ctx->r16 != 0) {
        // 0x800A9834: lbu         $t6, 0x5($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X5);
            goto L_800A978C;
    }
    goto skip_1;
    // 0x800A9834: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
    skip_1:
L_800A9838:
    // 0x800A9838: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A983C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A9840: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A9844: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9848: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800A984C: jr          $ra
    // 0x800A9850: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A9850: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800A9854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9854: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x800A9858: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A985C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A9860: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800A9864: bne         $t8, $at, L_800A9870
    if (ctx->r24 != ctx->r1) {
        // 0x800A9868: sb          $t7, 0x4($a0)
        MEM_B(0X4, ctx->r4) = ctx->r15;
            goto L_800A9870;
    }
    // 0x800A9868: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
    // 0x800A986C: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
L_800A9870:
    // 0x800A9870: jr          $ra
    // 0x800A9874: nop

    return;
    // 0x800A9874: nop

;}

RECOMP_FUNC void func_800A9878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9878: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x800A987C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9880: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A9884: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800A9888: bne         $t8, $at, L_800A9894
    if (ctx->r24 != ctx->r1) {
        // 0x800A988C: sb          $t7, 0x5($a0)
        MEM_B(0X5, ctx->r4) = ctx->r15;
            goto L_800A9894;
    }
    // 0x800A988C: sb          $t7, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r15;
    // 0x800A9890: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
L_800A9894:
    // 0x800A9894: jr          $ra
    // 0x800A9898: nop

    return;
    // 0x800A9898: nop

;}

RECOMP_FUNC void func_800A989C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A989C: lbu         $t6, 0x38($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X38);
    // 0x800A98A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A98A4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A98A8: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800A98AC: bne         $t8, $at, L_800A98B8
    if (ctx->r24 != ctx->r1) {
        // 0x800A98B0: sb          $t7, 0x38($a0)
        MEM_B(0X38, ctx->r4) = ctx->r15;
            goto L_800A98B8;
    }
    // 0x800A98B0: sb          $t7, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r15;
    // 0x800A98B4: sb          $zero, 0x38($a0)
    MEM_B(0X38, ctx->r4) = 0;
L_800A98B8:
    // 0x800A98B8: jr          $ra
    // 0x800A98BC: nop

    return;
    // 0x800A98BC: nop

;}

RECOMP_FUNC void func_800A98C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A98C0: lbu         $t6, 0x39($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X39);
    // 0x800A98C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A98C8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A98CC: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800A98D0: bne         $t8, $at, L_800A98DC
    if (ctx->r24 != ctx->r1) {
        // 0x800A98D4: sb          $t7, 0x39($a0)
        MEM_B(0X39, ctx->r4) = ctx->r15;
            goto L_800A98DC;
    }
    // 0x800A98D4: sb          $t7, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r15;
    // 0x800A98D8: sb          $zero, 0x39($a0)
    MEM_B(0X39, ctx->r4) = 0;
L_800A98DC:
    // 0x800A98DC: jr          $ra
    // 0x800A98E0: nop

    return;
    // 0x800A98E0: nop

;}

RECOMP_FUNC void func_800A98E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A98E4: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x800A98E8: sdc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X58, ctx->r29);
    // 0x800A98EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A98F0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800A98F4: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800A98F8: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x800A98FC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800A9900: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800A9904: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800A9908: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x800A990C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A9910: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A9914: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A9918: addiu       $t2, $zero, 0x85
    ctx->r10 = ADD32(0, 0X85);
    // 0x800A991C: sw          $s5, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r21;
    // 0x800A9920: sw          $s4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r20;
    // 0x800A9924: sw          $s3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r19;
    // 0x800A9928: sw          $s2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r18;
    // 0x800A992C: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    // 0x800A9930: sw          $s0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r16;
    // 0x800A9934: sdc1        $f30, 0x60($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X60, ctx->r29);
    // 0x800A9938: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x800A993C: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x800A9940: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x800A9944: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800A9948: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800A994C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800A9950: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A9954: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800A9958: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800A995C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A9960: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A9964: addiu       $a2, $a2, 0x6228
    ctx->r6 = ADD32(ctx->r6, 0X6228);
    // 0x800A9968: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x800A996C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A9970: addiu       $a3, $zero, 0x120
    ctx->r7 = ADD32(0, 0X120);
    // 0x800A9974: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x800A9978: jal         0x800B1BFC
    // 0x800A997C: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    func_800B1BFC(rdram, ctx);
        goto after_0;
    // 0x800A997C: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    after_0:
    // 0x800A9980: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A9984: lw          $v1, 0x7AF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7AF0);
    // 0x800A9988: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800A998C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A9990: addiu       $s2, $zero, 0xD9
    ctx->r18 = ADD32(0, 0XD9);
    // 0x800A9994: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x800A9998: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x800A999C: beq         $v1, $zero, L_800A9A2C
    if (ctx->r3 == 0) {
        // 0x800A99A0: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_800A9A2C;
    }
    // 0x800A99A0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800A99A4: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800A99A8: addiu       $s3, $zero, 0x18
    ctx->r19 = ADD32(0, 0X18);
    // 0x800A99AC: lbu         $v0, 0x39($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X39);
L_800A99B0:
    // 0x800A99B0: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A99B4: mflo        $t3
    ctx->r11 = lo;
    // 0x800A99B8: addu        $s0, $s1, $t3
    ctx->r16 = ADD32(ctx->r17, ctx->r11);
    // 0x800A99BC: lhu         $t6, 0x40($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X40);
    // 0x800A99C0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800A99C4: beql        $t7, $zero, L_800A9A20
    if (ctx->r15 == 0) {
        // 0x800A99C8: lw          $s1, 0x74($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X74);
            goto L_800A9A20;
    }
    goto skip_0;
    // 0x800A99C8: lw          $s1, 0x74($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X74);
    skip_0:
    // 0x800A99CC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800A99D0: bnel        $s4, $t8, L_800A9A20
    if (ctx->r20 != ctx->r24) {
        // 0x800A99D4: lw          $s1, 0x74($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X74);
            goto L_800A9A20;
    }
    goto skip_1;
    // 0x800A99D4: lw          $s1, 0x74($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X74);
    skip_1:
    // 0x800A99D8: lw          $t0, 0x48($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X48);
    // 0x800A99DC: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x800A99E0: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x800A99E4: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A99E8: sltu        $at, $t4, $t0
    ctx->r1 = ctx->r12 < ctx->r8 ? 1 : 0;
    // 0x800A99EC: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    // 0x800A99F0: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x800A99F4: sw          $t1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r9;
    // 0x800A99F8: bne         $at, $zero, L_800A9A1C
    if (ctx->r1 != 0) {
        // 0x800A99FC: or          $t3, $t1, $zero
        ctx->r11 = ctx->r9 | 0;
            goto L_800A9A1C;
    }
    // 0x800A99FC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
    // 0x800A9A00: sltu        $at, $t0, $t4
    ctx->r1 = ctx->r8 < ctx->r12 ? 1 : 0;
    // 0x800A9A04: bne         $at, $zero, L_800A9A14
    if (ctx->r1 != 0) {
        // 0x800A9A08: sltu        $at, $t1, $t5
        ctx->r1 = ctx->r9 < ctx->r13 ? 1 : 0;
            goto L_800A9A14;
    }
    // 0x800A9A08: sltu        $at, $t1, $t5
    ctx->r1 = ctx->r9 < ctx->r13 ? 1 : 0;
    // 0x800A9A0C: beql        $at, $zero, L_800A9A20
    if (ctx->r1 == 0) {
        // 0x800A9A10: lw          $s1, 0x74($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X74);
            goto L_800A9A20;
    }
    goto skip_2;
    // 0x800A9A10: lw          $s1, 0x74($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X74);
    skip_2:
L_800A9A14:
    // 0x800A9A14: sw          $t2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r10;
    // 0x800A9A18: sw          $t3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r11;
L_800A9A1C:
    // 0x800A9A1C: lw          $s1, 0x74($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X74);
L_800A9A20:
    // 0x800A9A20: bnel        $s1, $zero, L_800A99B0
    if (ctx->r17 != 0) {
        // 0x800A9A24: lbu         $v0, 0x39($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X39);
            goto L_800A99B0;
    }
    goto skip_3;
    // 0x800A9A24: lbu         $v0, 0x39($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X39);
    skip_3:
    // 0x800A9A28: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800A9A2C:
    // 0x800A9A2C: addiu       $s3, $zero, 0x18
    ctx->r19 = ADD32(0, 0X18);
    // 0x800A9A30: beq         $s1, $zero, L_800A9D08
    if (ctx->r17 == 0) {
        // 0x800A9A34: addiu       $s4, $zero, 0x2
        ctx->r20 = ADD32(0, 0X2);
            goto L_800A9D08;
    }
    // 0x800A9A34: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800A9A38: beq         $s2, $zero, L_800A9D08
    if (ctx->r18 == 0) {
        // 0x800A9A3C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800A9D08;
    }
    // 0x800A9A3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A9A40: ldc1        $f30, 0xA60($at)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r1, 0XA60);
    // 0x800A9A44: lui         $at, 0x4390
    ctx->r1 = S32(0X4390 << 16);
    // 0x800A9A48: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800A9A4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A9A50: ldc1        $f24, 0xA68($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, 0XA68);
    // 0x800A9A54: lwc1        $f22, 0xB8($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800A9A58: lwc1        $f20, 0xBC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800A9A5C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800A9A60: lbu         $v0, 0x39($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X39);
L_800A9A64:
    // 0x800A9A64: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9A68: mflo        $t9
    ctx->r25 = lo;
    // 0x800A9A6C: addu        $s0, $s1, $t9
    ctx->r16 = ADD32(ctx->r17, ctx->r25);
    // 0x800A9A70: lhu         $t6, 0x40($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X40);
    // 0x800A9A74: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800A9A78: beql        $t7, $zero, L_800A9CF0
    if (ctx->r15 == 0) {
        // 0x800A9A7C: lw          $s1, 0x74($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X74);
            goto L_800A9CF0;
    }
    goto skip_4;
    // 0x800A9A7C: lw          $s1, 0x74($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X74);
    skip_4:
    // 0x800A9A80: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A9A84: beql        $v0, $zero, L_800A9AA8
    if (ctx->r2 == 0) {
        // 0x800A9A88: lw          $a0, 0x48($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X48);
            goto L_800A9AA8;
    }
    goto skip_5;
    // 0x800A9A88: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    skip_5:
    // 0x800A9A8C: beql        $v0, $s5, L_800A9AD0
    if (ctx->r2 == ctx->r21) {
        // 0x800A9A90: lw          $t8, 0x50($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X50);
            goto L_800A9AD0;
    }
    goto skip_6;
    // 0x800A9A90: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    skip_6:
    // 0x800A9A94: beq         $v0, $s4, L_800A9B24
    if (ctx->r2 == ctx->r20) {
        // 0x800A9A98: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_800A9B24;
    }
    // 0x800A9A98: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A9A9C: b           L_800A9BDC
    // 0x800A9AA0: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
        goto L_800A9BDC;
    // 0x800A9AA0: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    // 0x800A9AA4: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
L_800A9AA8:
    // 0x800A9AA8: jal         0x800BAF34
    // 0x800A9AAC: lw          $a1, 0x4C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4C);
    __ull_to_d_recomp(rdram, ctx);
        goto after_1;
    // 0x800A9AAC: lw          $a1, 0x4C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4C);
    after_1:
    // 0x800A9AB0: lui         $at, 0x4050
    ctx->r1 = S32(0X4050 << 16);
    // 0x800A9AB4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A9AB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A9ABC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800A9AC0: mul.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800A9AC4: b           L_800A9BD8
    // 0x800A9AC8: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
        goto L_800A9BD8;
    // 0x800A9AC8: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x800A9ACC: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
L_800A9AD0:
    // 0x800A9AD0: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x800A9AD4: lw          $t0, 0x48($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X48);
    // 0x800A9AD8: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x800A9ADC: subu        $t4, $t8, $t0
    ctx->r12 = SUB32(ctx->r24, ctx->r8);
    // 0x800A9AE0: sltu        $at, $t9, $t1
    ctx->r1 = ctx->r25 < ctx->r9 ? 1 : 0;
    // 0x800A9AE4: subu        $a0, $t4, $at
    ctx->r4 = SUB32(ctx->r12, ctx->r1);
    // 0x800A9AE8: subu        $a1, $t9, $t1
    ctx->r5 = SUB32(ctx->r25, ctx->r9);
    // 0x800A9AEC: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x800A9AF0: jal         0x800BAF68
    // 0x800A9AF4: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    __ull_to_f_recomp(rdram, ctx);
        goto after_2;
    // 0x800A9AF4: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    after_2:
    // 0x800A9AF8: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800A9AFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A9B00: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800A9B04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A9B08: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800A9B0C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800A9B10: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A9B14: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800A9B18: div.d       $f6, $f4, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f30.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f30.d);
    // 0x800A9B1C: b           L_800A9BD8
    // 0x800A9B20: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
        goto L_800A9BD8;
    // 0x800A9B20: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
L_800A9B24:
    // 0x800A9B24: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x800A9B28: lw          $t3, 0x54($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X54);
    // 0x800A9B2C: lw          $t6, 0x48($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X48);
    // 0x800A9B30: lw          $t7, 0x4C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4C);
    // 0x800A9B34: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x800A9B38: subu        $t8, $t2, $t6
    ctx->r24 = SUB32(ctx->r10, ctx->r14);
    // 0x800A9B3C: sltu        $at, $t3, $t7
    ctx->r1 = ctx->r11 < ctx->r15 ? 1 : 0;
    // 0x800A9B40: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x800A9B44: subu        $a1, $t3, $t7
    ctx->r5 = SUB32(ctx->r11, ctx->r15);
    // 0x800A9B48: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x800A9B4C: jal         0x800B7658
    // 0x800A9B50: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    __ll_mul_recomp(rdram, ctx);
        goto after_3;
    // 0x800A9B50: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    after_3:
    // 0x800A9B54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A9B58: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800A9B5C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A9B60: jal         0x800B7558
    // 0x800A9B64: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    __ull_div_recomp(rdram, ctx);
        goto after_4;
    // 0x800A9B64: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_4:
    // 0x800A9B68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A9B6C: jal         0x800BAF34
    // 0x800A9B70: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_to_d_recomp(rdram, ctx);
        goto after_5;
    // 0x800A9B70: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_5:
    // 0x800A9B74: mul.d       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f24.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f24.d);
    // 0x800A9B78: lw          $t0, 0x48($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X48);
    // 0x800A9B7C: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x800A9B80: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x800A9B84: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A9B88: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A9B8C: subu        $t2, $t0, $t4
    ctx->r10 = SUB32(ctx->r8, ctx->r12);
    // 0x800A9B90: sltu        $at, $t1, $t5
    ctx->r1 = ctx->r9 < ctx->r13 ? 1 : 0;
    // 0x800A9B94: subu        $a0, $t2, $at
    ctx->r4 = SUB32(ctx->r10, ctx->r1);
    // 0x800A9B98: subu        $a1, $t1, $t5
    ctx->r5 = SUB32(ctx->r9, ctx->r13);
    // 0x800A9B9C: cvt.s.d     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f20.fl = CVT_S_D(ctx->f8.d);
    // 0x800A9BA0: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x800A9BA4: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x800A9BA8: jal         0x800B7658
    // 0x800A9BAC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_6;
    // 0x800A9BAC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_6:
    // 0x800A9BB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A9BB4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800A9BB8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A9BBC: jal         0x800B7558
    // 0x800A9BC0: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    __ull_div_recomp(rdram, ctx);
        goto after_7;
    // 0x800A9BC0: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_7:
    // 0x800A9BC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A9BC8: jal         0x800BAF34
    // 0x800A9BCC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_to_d_recomp(rdram, ctx);
        goto after_8;
    // 0x800A9BCC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_8:
    // 0x800A9BD0: mul.d       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f24.d);
    // 0x800A9BD4: cvt.s.d     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f22.fl = CVT_S_D(ctx->f10.d);
L_800A9BD8:
    // 0x800A9BD8: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
L_800A9BDC:
    // 0x800A9BDC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800A9BE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A9BE4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800A9BE8: bc1f        L_800A9BF8
    if (!c1cs) {
        // 0x800A9BEC: add.s       $f22, $f22, $f16
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
            goto L_800A9BF8;
    }
    // 0x800A9BEC: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x800A9BF0: b           L_800A9C0C
    // 0x800A9BF4: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
        goto L_800A9C0C;
    // 0x800A9BF4: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
L_800A9BF8:
    // 0x800A9BF8: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    // 0x800A9BFC: nop

    // 0x800A9C00: bc1fl       L_800A9C10
    if (!c1cs) {
        // 0x800A9C04: div.s       $f18, $f20, $f26
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f26.fl);
            goto L_800A9C10;
    }
    goto skip_7;
    // 0x800A9C04: div.s       $f18, $f20, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f26.fl);
    skip_7:
    // 0x800A9C08: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
L_800A9C0C:
    // 0x800A9C0C: div.s       $f18, $f20, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f26.fl);
L_800A9C10:
    // 0x800A9C10: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A9C14: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800A9C18: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800A9C1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A9C20: addiu       $a2, $a2, 0x7430
    ctx->r6 = ADD32(ctx->r6, 0X7430);
    // 0x800A9C24: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x800A9C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A9C2C: addiu       $a3, $zero, 0x120
    ctx->r7 = ADD32(0, 0X120);
    // 0x800A9C30: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    // 0x800A9C34: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A9C38: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A9C3C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800A9C40: cvt.w.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    ctx->f4.u32l = CVT_W_S(ctx->f22.fl);
    // 0x800A9C44: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A9C48: nop

    // 0x800A9C4C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800A9C50: beql        $t8, $zero, L_800A9CA0
    if (ctx->r24 == 0) {
        // 0x800A9C54: mfc1        $t8, $f4
        ctx->r24 = (int32_t)ctx->f4.u32l;
            goto L_800A9CA0;
    }
    goto skip_8;
    // 0x800A9C54: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    skip_8:
    // 0x800A9C58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A9C5C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A9C60: sub.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f4.fl;
    // 0x800A9C64: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A9C68: nop

    // 0x800A9C6C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9C70: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A9C74: nop

    // 0x800A9C78: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800A9C7C: bne         $t8, $zero, L_800A9C94
    if (ctx->r24 != 0) {
        // 0x800A9C80: nop
    
            goto L_800A9C94;
    }
    // 0x800A9C80: nop

    // 0x800A9C84: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800A9C88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A9C8C: b           L_800A9CAC
    // 0x800A9C90: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800A9CAC;
    // 0x800A9C90: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800A9C94:
    // 0x800A9C94: b           L_800A9CAC
    // 0x800A9C98: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800A9CAC;
    // 0x800A9C98: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800A9C9C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
L_800A9CA0:
    // 0x800A9CA0: nop

    // 0x800A9CA4: bltz        $t8, L_800A9C94
    if (SIGNED(ctx->r24) < 0) {
        // 0x800A9CA8: nop
    
            goto L_800A9C94;
    }
    // 0x800A9CA8: nop

L_800A9CAC:
    // 0x800A9CAC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800A9CB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A9CB4: lbu         $t9, 0x70($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X70);
    // 0x800A9CB8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A9CBC: addiu       $t4, $zero, 0x85
    ctx->r12 = ADD32(0, 0X85);
    // 0x800A9CC0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800A9CC4: lbu         $t0, 0x71($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X71);
    // 0x800A9CC8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A9CCC: lbu         $t1, 0x72($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X72);
    // 0x800A9CD0: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x800A9CD4: jal         0x800B1BFC
    // 0x800A9CD8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    func_800B1BFC(rdram, ctx);
        goto after_9;
    // 0x800A9CD8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_9:
    // 0x800A9CDC: addiu       $s2, $s2, -0x3
    ctx->r18 = ADD32(ctx->r18, -0X3);
    // 0x800A9CE0: sh          $zero, 0x40($s0)
    MEM_H(0X40, ctx->r16) = 0;
    // 0x800A9CE4: jal         0x800A98C0
    // 0x800A9CE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A98C0(rdram, ctx);
        goto after_10;
    // 0x800A9CE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x800A9CEC: lw          $s1, 0x74($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X74);
L_800A9CF0:
    // 0x800A9CF0: beql        $s1, $zero, L_800A9D0C
    if (ctx->r17 == 0) {
        // 0x800A9CF4: lw          $ra, 0x84($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X84);
            goto L_800A9D0C;
    }
    goto skip_9;
    // 0x800A9CF4: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    skip_9:
    // 0x800A9CF8: bnel        $s2, $zero, L_800A9A64
    if (ctx->r18 != 0) {
        // 0x800A9CFC: lbu         $v0, 0x39($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X39);
            goto L_800A9A64;
    }
    goto skip_10;
    // 0x800A9CFC: lbu         $v0, 0x39($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X39);
    skip_10:
    // 0x800A9D00: swc1        $f22, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f22.u32l;
    // 0x800A9D04: swc1        $f20, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f20.u32l;
L_800A9D08:
    // 0x800A9D08: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
L_800A9D0C:
    // 0x800A9D0C: lw          $v0, 0xD8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD8);
    // 0x800A9D10: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800A9D14: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x800A9D18: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x800A9D1C: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x800A9D20: ldc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X58);
    // 0x800A9D24: ldc1        $f30, 0x60($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X60);
    // 0x800A9D28: lw          $s0, 0x6C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X6C);
    // 0x800A9D2C: lw          $s1, 0x70($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X70);
    // 0x800A9D30: lw          $s2, 0x74($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X74);
    // 0x800A9D34: lw          $s3, 0x78($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X78);
    // 0x800A9D38: lw          $s4, 0x7C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X7C);
    // 0x800A9D3C: lw          $s5, 0x80($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X80);
    // 0x800A9D40: jr          $ra
    // 0x800A9D44: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x800A9D44: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x800A9D48: nop

    // 0x800A9D4C: nop

;}

RECOMP_FUNC void func_800A9D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9D50: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A9D54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A9D58: jr          $ra
    // 0x800A9D5C: sw          $t6, 0x7B04($at)
    MEM_W(0X7B04, ctx->r1) = ctx->r14;
    return;
    // 0x800A9D5C: sw          $t6, 0x7B04($at)
    MEM_W(0X7B04, ctx->r1) = ctx->r14;
;}

RECOMP_FUNC void func_800A9D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9D60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A9D64: jr          $ra
    // 0x800A9D68: sw          $zero, 0x7B04($at)
    MEM_W(0X7B04, ctx->r1) = 0;
    return;
    // 0x800A9D68: sw          $zero, 0x7B04($at)
    MEM_W(0X7B04, ctx->r1) = 0;
;}

RECOMP_FUNC void func_800A9D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9D6C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A9D70: jr          $ra
    // 0x800A9D74: lw          $v0, -0x69F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X69F8);
    return;
    // 0x800A9D74: lw          $v0, -0x69F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X69F8);
;}

RECOMP_FUNC void func_800A9D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9D78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A9D7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A9D80: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800A9D84: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A9D88: addiu       $s1, $sp, 0x24
    ctx->r17 = ADD32(ctx->r29, 0X24);
    // 0x800A9D8C: addiu       $s0, $s0, -0x67B8
    ctx->r16 = ADD32(ctx->r16, -0X67B8);
    // 0x800A9D90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A9D94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800A9D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A9D9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A9DA0: jal         0x800B3C20
    // 0x800A9DA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800A9DA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800A9DA8: beq         $v0, $zero, L_800A9DC4
    if (ctx->r2 == 0) {
        // 0x800A9DAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A9DC4;
    }
    // 0x800A9DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A9DB0:
    // 0x800A9DB0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A9DB4: jal         0x800B3C20
    // 0x800A9DB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800A9DB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800A9DBC: bnel        $v0, $zero, L_800A9DB0
    if (ctx->r2 != 0) {
        // 0x800A9DC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A9DB0;
    }
    goto skip_0;
    // 0x800A9DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_800A9DC4:
    // 0x800A9DC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9DC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A9DCC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A9DD0: jr          $ra
    // 0x800A9DD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A9DD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800A9DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9DD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A9DDC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800A9DE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A9DE4: addiu       $t6, $t6, -0x6840
    ctx->r14 = ADD32(ctx->r14, -0X6840);
    // 0x800A9DE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A9DEC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800A9DF0: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x800A9DF4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A9DF8: addiu       $a2, $a2, -0x6288
    ctx->r6 = ADD32(ctx->r6, -0X6288);
    // 0x800A9DFC: addiu       $a0, $a0, -0x69F0
    ctx->r4 = ADD32(ctx->r4, -0X69F0);
    // 0x800A9E00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A9E04: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x800A9E08: jal         0x800B6010
    // 0x800A9E0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800A9E0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800A9E10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A9E14: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A9E18: addiu       $a1, $a1, -0x67A0
    ctx->r5 = ADD32(ctx->r5, -0X67A0);
    // 0x800A9E1C: addiu       $a0, $a0, -0x67B8
    ctx->r4 = ADD32(ctx->r4, -0X67B8);
    // 0x800A9E20: jal         0x800B3080
    // 0x800A9E24: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x800A9E24: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_1:
    // 0x800A9E28: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A9E2C: jal         0x800B6160
    // 0x800A9E30: addiu       $a0, $a0, -0x69F0
    ctx->r4 = ADD32(ctx->r4, -0X69F0);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800A9E30: addiu       $a0, $a0, -0x69F0
    ctx->r4 = ADD32(ctx->r4, -0X69F0);
    after_2:
    // 0x800A9E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9E38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A9E3C: jr          $ra
    // 0x800A9E40: nop

    return;
    // 0x800A9E40: nop

;}

RECOMP_FUNC void func_800A9E44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9E44: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A9E48: addiu       $v0, $v0, -0x6A00
    ctx->r2 = ADD32(ctx->r2, -0X6A00);
    // 0x800A9E4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A9E50: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800A9E54: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A9E58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9E5C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800A9E60: sw          $a1, -0x69FC($at)
    MEM_W(-0X69FC, ctx->r1) = ctx->r5;
    // 0x800A9E64: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A9E68: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800A9E6C: jal         0x800ABFF0
    // 0x800A9E70: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800ABFF0(rdram, ctx);
        goto after_0;
    // 0x800A9E70: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800A9E74: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800A9E78: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A9E7C: addiu       $a1, $a1, -0x69F8
    ctx->r5 = ADD32(ctx->r5, -0X69F8);
    // 0x800A9E80: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800A9E84: jal         0x8007E03C
    // 0x800A9E88: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800A9E88: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    after_1:
    // 0x800A9E8C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A9E90: addiu       $a1, $a1, -0x69F8
    ctx->r5 = ADD32(ctx->r5, -0X69F8);
    // 0x800A9E94: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A9E98: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A9E9C: addiu       $a0, $a0, 0x7B00
    ctx->r4 = ADD32(ctx->r4, 0X7B00);
    // 0x800A9EA0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800A9EA4: blez        $t7, L_800A9EE0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A9EA8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800A9EE0;
    }
    // 0x800A9EA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A9EAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A9EB0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
L_800A9EB4:
    // 0x800A9EB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A9EB8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800A9EBC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800A9EC0: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800A9EC4: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x800A9EC8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A9ECC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A9ED0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800A9ED4: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A9ED8: bnel        $at, $zero, L_800A9EB4
    if (ctx->r1 != 0) {
        // 0x800A9EDC: lw          $t8, 0x0($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X0);
            goto L_800A9EB4;
    }
    goto skip_0;
    // 0x800A9EDC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    skip_0:
L_800A9EE0:
    // 0x800A9EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9EE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A9EE8: jr          $ra
    // 0x800A9EEC: nop

    return;
    // 0x800A9EEC: nop

;}

RECOMP_FUNC void func_800A9EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9EF0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800A9EF4: addiu       $v0, $v0, -0x6A00
    ctx->r2 = ADD32(ctx->r2, -0X6A00);
    // 0x800A9EF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A9EFC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800A9F00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800A9F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9F08: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800A9F0C: sw          $a1, -0x69FC($at)
    MEM_W(-0X69FC, ctx->r1) = ctx->r5;
    // 0x800A9F10: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A9F14: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800A9F18: jal         0x800ABFF0
    // 0x800A9F1C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800ABFF0(rdram, ctx);
        goto after_0;
    // 0x800A9F1C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800A9F20: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800A9F24: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A9F28: addiu       $a1, $a1, -0x69F8
    ctx->r5 = ADD32(ctx->r5, -0X69F8);
    // 0x800A9F2C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800A9F30: jal         0x8007E03C
    // 0x800A9F34: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800A9F34: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    after_1:
    // 0x800A9F38: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800A9F3C: addiu       $a1, $a1, -0x69F8
    ctx->r5 = ADD32(ctx->r5, -0X69F8);
    // 0x800A9F40: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A9F44: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A9F48: addiu       $a0, $a0, 0x7B00
    ctx->r4 = ADD32(ctx->r4, 0X7B00);
    // 0x800A9F4C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800A9F50: blez        $t7, L_800A9F8C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A9F54: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800A9F8C;
    }
    // 0x800A9F54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A9F58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A9F5C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
L_800A9F60:
    // 0x800A9F60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A9F64: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800A9F68: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800A9F6C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800A9F70: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x800A9F74: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A9F78: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A9F7C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800A9F80: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A9F84: bnel        $at, $zero, L_800A9F60
    if (ctx->r1 != 0) {
        // 0x800A9F88: lw          $t8, 0x0($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X0);
            goto L_800A9F60;
    }
    goto skip_0;
    // 0x800A9F88: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    skip_0:
L_800A9F8C:
    // 0x800A9F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9F90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A9F94: jr          $ra
    // 0x800A9F98: nop

    return;
    // 0x800A9F98: nop

;}

RECOMP_FUNC void func_800A9F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9F9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A9FA0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800A9FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9FA8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A9FAC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800A9FB0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800A9FB4: beq         $t6, $zero, L_800A9FD0
    if (ctx->r14 == 0) {
        // 0x800A9FB8: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_800A9FD0;
    }
    // 0x800A9FB8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800A9FBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9FC0: beq         $t6, $at, L_800A9FE8
    if (ctx->r14 == ctx->r1) {
        // 0x800A9FC4: nop
    
            goto L_800A9FE8;
    }
    // 0x800A9FC4: nop

    // 0x800A9FC8: b           L_800AA02C
    // 0x800A9FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA02C;
    // 0x800A9FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9FD0:
    // 0x800A9FD0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A9FD4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800A9FD8: jal         0x800ABFF0
    // 0x800A9FDC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_800ABFF0(rdram, ctx);
        goto after_0;
    // 0x800A9FDC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x800A9FE0: b           L_800AA02C
    // 0x800A9FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA02C;
    // 0x800A9FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9FE8:
    // 0x800A9FE8: jal         0x8007E03C
    // 0x800A9FEC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800A9FEC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x800A9FF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800A9FF4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A9FF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800A9FFC: jal         0x800ABFF0
    // 0x800AA000: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_800ABFF0(rdram, ctx);
        goto after_2;
    // 0x800AA000: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x800AA004: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800AA008: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800AA00C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800AA010: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800AA014: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800AA018: jal         0x80080EC8
    // 0x800AA01C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    strutil_lzo_decompress(rdram, ctx);
        goto after_3;
    // 0x800AA01C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_3:
    // 0x800AA020: jal         0x8007E328
    // 0x800AA024: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    n64HeapUnalloc(rdram, ctx);
        goto after_4;
    // 0x800AA024: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x800AA028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA02C:
    // 0x800AA02C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AA030: jr          $ra
    // 0x800AA034: nop

    return;
    // 0x800AA034: nop

;}

RECOMP_FUNC void func_800AA038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA038: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AA03C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800AA040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA044: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AA048: lw          $a0, -0x6A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A00);
    // 0x800AA04C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800AA050: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800AA054: jal         0x800ABFF0
    // 0x800AA058: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800ABFF0(rdram, ctx);
        goto after_0;
    // 0x800AA058: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800AA05C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800AA060: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800AA064: bltz        $a3, L_800AA074
    if (SIGNED(ctx->r7) < 0) {
        // 0x800AA068: slt         $at, $a3, $t6
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_800AA074;
    }
    // 0x800AA068: slt         $at, $a3, $t6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AA06C: bne         $at, $zero, L_800AA07C
    if (ctx->r1 != 0) {
        // 0x800AA070: sll         $t7, $a3, 4
        ctx->r15 = S32(ctx->r7 << 4);
            goto L_800AA07C;
    }
    // 0x800AA070: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
L_800AA074:
    // 0x800AA074: b           L_800AA09C
    // 0x800AA078: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AA09C;
    // 0x800AA078: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AA07C:
    // 0x800AA07C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800AA080: lw          $t8, -0x6A00($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6A00);
    // 0x800AA084: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800AA088: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AA08C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800AA090: jal         0x800ABFF0
    // 0x800AA094: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800ABFF0(rdram, ctx);
        goto after_1;
    // 0x800AA094: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x800AA098: lh          $v0, 0x20($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X20);
L_800AA09C:
    // 0x800AA09C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA0A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AA0A4: jr          $ra
    // 0x800AA0A8: nop

    return;
    // 0x800AA0A8: nop

;}

RECOMP_FUNC void func_800AA0AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA0AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AA0B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AA0B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA0B8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800AA0BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AA0C0: lw          $a0, -0x6A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A00);
    // 0x800AA0C4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800AA0C8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800AA0CC: jal         0x800ABFF0
    // 0x800AA0D0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800ABFF0(rdram, ctx);
        goto after_0;
    // 0x800AA0D0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800AA0D4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800AA0D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800AA0DC: bltz        $a3, L_800AA0EC
    if (SIGNED(ctx->r7) < 0) {
        // 0x800AA0E0: slt         $at, $a3, $t6
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_800AA0EC;
    }
    // 0x800AA0E0: slt         $at, $a3, $t6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AA0E4: bne         $at, $zero, L_800AA0F4
    if (ctx->r1 != 0) {
        // 0x800AA0E8: sll         $t7, $a3, 4
        ctx->r15 = S32(ctx->r7 << 4);
            goto L_800AA0F4;
    }
    // 0x800AA0E8: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
L_800AA0EC:
    // 0x800AA0EC: b           L_800AA124
    // 0x800AA0F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AA124;
    // 0x800AA0F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AA0F4:
    // 0x800AA0F4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800AA0F8: lw          $t8, -0x6A00($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6A00);
    // 0x800AA0FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800AA100: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AA104: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800AA108: jal         0x800ABFF0
    // 0x800AA10C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800ABFF0(rdram, ctx);
        goto after_1;
    // 0x800AA10C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x800AA110: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800AA114: lb          $at, 0x0($t9)
    ctx->r1 = MEM_B(ctx->r25, 0X0);
    // 0x800AA118: lbu         $v0, 0x1($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X1);
    // 0x800AA11C: sll         $at, $at, 8
    ctx->r1 = S32(ctx->r1 << 8);
    // 0x800AA120: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_800AA124:
    // 0x800AA124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA128: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AA12C: jr          $ra
    // 0x800AA130: nop

    return;
    // 0x800AA130: nop

;}

RECOMP_FUNC void func_800AA134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA134: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800AA138: lw          $t6, 0x7B00($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B00);
    // 0x800AA13C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800AA140: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AA144: jr          $ra
    // 0x800AA148: lw          $v0, 0x4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X4);
    return;
    // 0x800AA148: lw          $v0, 0x4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X4);
;}

RECOMP_FUNC void func_800AA14C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA14C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800AA150: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AA154: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AA158: bltz        $a0, L_800AA17C
    if (SIGNED(ctx->r4) < 0) {
        // 0x800AA15C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800AA17C;
    }
    // 0x800AA15C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800AA160: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800AA164: lw          $t6, -0x69F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X69F8);
    // 0x800AA168: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
    // 0x800AA16C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800AA170: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AA174: bne         $at, $zero, L_800AA184
    if (ctx->r1 != 0) {
        // 0x800AA178: addiu       $a1, $sp, 0x48
        ctx->r5 = ADD32(ctx->r29, 0X48);
            goto L_800AA184;
    }
    // 0x800AA178: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
L_800AA17C:
    // 0x800AA17C: b           L_800AA3C8
    // 0x800AA180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AA3C8;
    // 0x800AA180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AA184:
    // 0x800AA184: lw          $t8, -0x6A00($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6A00);
    // 0x800AA188: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AA18C: sw          $a3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r7;
    // 0x800AA190: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800AA194: jal         0x800ABFF0
    // 0x800AA198: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800ABFF0(rdram, ctx);
        goto after_0;
    // 0x800AA198: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x800AA19C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800AA1A0: lw          $t9, 0x7B04($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B04);
    // 0x800AA1A4: lh          $t0, 0x48($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X48);
    // 0x800AA1A8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800AA1AC: beq         $t9, $zero, L_800AA288
    if (ctx->r25 == 0) {
        // 0x800AA1B0: sll         $t1, $t0, 2
        ctx->r9 = S32(ctx->r8 << 2);
            goto L_800AA288;
    }
    // 0x800AA1B0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800AA1B4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800AA1B8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800AA1BC: lw          $t2, 0x7B70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B70);
    // 0x800AA1C0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800AA1C4: jal         0x8007E03C
    // 0x800AA1C8: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800AA1C8: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x800AA1CC: lh          $t6, 0x48($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X48);
    // 0x800AA1D0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800AA1D4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800AA1D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AA1DC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800AA1E0: lw          $t4, -0x69FC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X69FC);
    // 0x800AA1E4: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800AA1E8: lw          $t8, 0x7B70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B70);
    // 0x800AA1EC: lh          $t9, 0x4A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4A);
    // 0x800AA1F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800AA1F4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800AA1F8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800AA1FC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x800AA200: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    // 0x800AA204: jal         0x800A9F9C
    // 0x800AA208: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800A9F9C(rdram, ctx);
        goto after_2;
    // 0x800AA208: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_2:
    // 0x800AA20C: lh          $a0, 0x48($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X48);
    // 0x800AA210: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA214: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x800AA218: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800AA21C: lw          $v1, 0x7B08($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7B08);
    // 0x800AA220: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800AA224: beq         $v1, $zero, L_800AA240
    if (ctx->r3 == 0) {
        // 0x800AA228: nop
    
            goto L_800AA240;
    }
    // 0x800AA228: nop

    // 0x800AA22C: jalr        $v1
    // 0x800AA230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_3;
    // 0x800AA230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800AA234: lh          $a0, 0x48($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X48);
    // 0x800AA238: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x800AA23C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
L_800AA240:
    // 0x800AA240: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA244: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800AA248: lw          $v0, 0x7B3C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B3C);
    // 0x800AA24C: beql        $v0, $zero, L_800AA260
    if (ctx->r2 == 0) {
        // 0x800AA250: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_800AA260;
    }
    goto skip_0;
    // 0x800AA250: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    skip_0:
    // 0x800AA254: jalr        $v0
    // 0x800AA258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x800AA258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800AA25C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_800AA260:
    // 0x800AA260: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x800AA264: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800AA268: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x800AA26C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800AA270: lw          $t3, 0x7B00($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B00);
    // 0x800AA274: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800AA278: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AA27C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800AA280: b           L_800AA3C8
    // 0x800AA284: sw          $s0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r16;
        goto L_800AA3C8;
    // 0x800AA284: sw          $s0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r16;
L_800AA288:
    // 0x800AA288: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800AA28C: lw          $t9, 0x7B00($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B00);
    // 0x800AA290: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800AA294: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800AA298: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x800AA29C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800AA2A0: lh          $t6, 0x48($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X48);
    // 0x800AA2A4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800AA2A8: beq         $a0, $zero, L_800AA2F4
    if (ctx->r4 == 0) {
        // 0x800AA2AC: sll         $t7, $t6, 2
        ctx->r15 = S32(ctx->r14 << 2);
            goto L_800AA2F4;
    }
    // 0x800AA2AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AA2B0: addiu       $t0, $a0, 0x1
    ctx->r8 = ADD32(ctx->r4, 0X1);
    // 0x800AA2B4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800AA2B8: lh          $t1, 0x48($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X48);
    // 0x800AA2BC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA2C0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800AA2C4: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800AA2C8: lw          $v0, 0x7B3C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B3C);
    // 0x800AA2CC: beq         $v0, $zero, L_800AA2DC
    if (ctx->r2 == 0) {
        // 0x800AA2D0: nop
    
            goto L_800AA2DC;
    }
    // 0x800AA2D0: nop

    // 0x800AA2D4: jalr        $v0
    // 0x800AA2D8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x800AA2D8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_5:
L_800AA2DC:
    // 0x800AA2DC: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800AA2E0: lw          $t4, 0x7B00($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B00);
    // 0x800AA2E4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800AA2E8: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x800AA2EC: b           L_800AA3C8
    // 0x800AA2F0: lw          $v0, 0x4($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X4);
        goto L_800AA3C8;
    // 0x800AA2F0: lw          $v0, 0x4($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X4);
L_800AA2F4:
    // 0x800AA2F4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800AA2F8: lw          $t9, 0x7B70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B70);
    // 0x800AA2FC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800AA300: jal         0x8007E03C
    // 0x800AA304: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    n64HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x800AA304: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_6:
    // 0x800AA308: lh          $t2, 0x48($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X48);
    // 0x800AA30C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800AA310: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800AA314: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800AA318: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x800AA31C: lw          $t0, -0x69FC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X69FC);
    // 0x800AA320: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800AA324: lw          $t3, 0x7B70($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B70);
    // 0x800AA328: lh          $t5, 0x4A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X4A);
    // 0x800AA32C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800AA330: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800AA334: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800AA338: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x800AA33C: addu        $a2, $t3, $v0
    ctx->r6 = ADD32(ctx->r11, ctx->r2);
    // 0x800AA340: jal         0x800A9F9C
    // 0x800AA344: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800A9F9C(rdram, ctx);
        goto after_7;
    // 0x800AA344: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_7:
    // 0x800AA348: lh          $a0, 0x48($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X48);
    // 0x800AA34C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800AA350: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800AA354: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800AA358: lw          $v1, 0x7B08($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7B08);
    // 0x800AA35C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800AA360: beq         $v1, $zero, L_800AA37C
    if (ctx->r3 == 0) {
        // 0x800AA364: nop
    
            goto L_800AA37C;
    }
    // 0x800AA364: nop

    // 0x800AA368: jalr        $v1
    // 0x800AA36C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_8;
    // 0x800AA36C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800AA370: lh          $a0, 0x48($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X48);
    // 0x800AA374: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800AA378: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800AA37C:
    // 0x800AA37C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AA380: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800AA384: lw          $v0, 0x7B3C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B3C);
    // 0x800AA388: beql        $v0, $zero, L_800AA39C
    if (ctx->r2 == 0) {
        // 0x800AA38C: lw          $t9, 0x60($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X60);
            goto L_800AA39C;
    }
    goto skip_1;
    // 0x800AA38C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x800AA390: jalr        $v0
    // 0x800AA394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_9;
    // 0x800AA394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800AA398: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
L_800AA39C:
    // 0x800AA39C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800AA3A0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800AA3A4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AA3A8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800AA3AC: lw          $t0, 0x7B00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7B00);
    // 0x800AA3B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800AA3B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800AA3B8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800AA3BC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x800AA3C0: addu        $t4, $t0, $t1
    ctx->r12 = ADD32(ctx->r8, ctx->r9);
    // 0x800AA3C4: sw          $s0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r16;
L_800AA3C8:
    // 0x800AA3C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AA3CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800AA3D0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800AA3D4: jr          $ra
    // 0x800AA3D8: nop

    return;
    // 0x800AA3D8: nop

;}

RECOMP_FUNC void func_800AA3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA3DC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800AA3E0: lw          $t6, 0x7B00($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B00);
    // 0x800AA3E4: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800AA3E8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AA3EC: jr          $ra
    // 0x800AA3F0: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    return;
    // 0x800AA3F0: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
;}

RECOMP_FUNC void func_800AA3F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA3F4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800AA3F8: addiu       $a1, $a1, 0x7B00
    ctx->r5 = ADD32(ctx->r5, 0X7B00);
    // 0x800AA3FC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800AA400: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AA404: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x800AA408: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA40C: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x800AA410: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800AA414: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800AA418: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AA41C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800AA420: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x800AA424: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800AA428: beql        $t0, $zero, L_800AA43C
    if (ctx->r8 == 0) {
        // 0x800AA42C: lw          $a0, 0x4($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X4);
            goto L_800AA43C;
    }
    goto skip_0;
    // 0x800AA42C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x800AA430: b           L_800AA460
    // 0x800AA434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AA460;
    // 0x800AA434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AA438: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
L_800AA43C:
    // 0x800AA43C: jal         0x8007E328
    // 0x800AA440: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA440: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800AA444: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800AA448: addiu       $a1, $a1, 0x7B00
    ctx->r5 = ADD32(ctx->r5, 0X7B00);
    // 0x800AA44C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA450: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800AA454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AA458: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x800AA45C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_800AA460:
    // 0x800AA460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA464: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AA468: jr          $ra
    // 0x800AA46C: nop

    return;
    // 0x800AA46C: nop

;}

RECOMP_FUNC void func_800AA470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA470: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800AA474: lw          $t6, 0x7B00($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B00);
    // 0x800AA478: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AA47C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800AA480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA484: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800AA488: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AA48C: beql        $t8, $zero, L_800AA508
    if (ctx->r24 == 0) {
        // 0x800AA490: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AA508;
    }
    goto skip_0;
    // 0x800AA490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800AA494: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800AA498: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800AA49C: jal         0x800AA038
    // 0x800AA4A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800AA038(rdram, ctx);
        goto after_0;
    // 0x800AA4A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800AA4A4: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x800AA4A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800AA4AC: beq         $at, $zero, L_800AA504
    if (ctx->r1 == 0) {
        // 0x800AA4B0: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_800AA504;
    }
    // 0x800AA4B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA4B4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800AA4B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AA4BC: addu        $at, $at, $t9
    gpr jr_addend_800AA4C4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AA4C0: lw          $t9, 0x1128($at)
    ctx->r25 = ADD32(ctx->r1, 0X1128);
    // 0x800AA4C4: jr          $t9
    // 0x800AA4C8: nop

    switch (jr_addend_800AA4C4 >> 2) {
        case 0: goto L_800AA4CC; break;
        case 1: goto L_800AA4CC; break;
        case 2: goto L_800AA4DC; break;
        case 3: goto L_800AA4CC; break;
        case 4: goto L_800AA4CC; break;
        case 5: goto L_800AA4EC; break;
        case 6: goto L_800AA4FC; break;
        default: switch_error(__func__, 0x800AA4C4, 0x800E1128);
    }
    // 0x800AA4C8: nop

L_800AA4CC:
    // 0x800AA4CC: jal         0x800AA3F4
    // 0x800AA4D0: nop

    func_800AA3F4(rdram, ctx);
        goto after_1;
    // 0x800AA4D0: nop

    after_1:
    // 0x800AA4D4: b           L_800AA508
    // 0x800AA4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA508;
    // 0x800AA4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA4DC:
    // 0x800AA4DC: jal         0x800AA874
    // 0x800AA4E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA874(rdram, ctx);
        goto after_2;
    // 0x800AA4E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800AA4E4: b           L_800AA508
    // 0x800AA4E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA508;
    // 0x800AA4E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA4EC:
    // 0x800AA4EC: jal         0x800AB5E0
    // 0x800AA4F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AB5E0(rdram, ctx);
        goto after_3;
    // 0x800AA4F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x800AA4F4: b           L_800AA508
    // 0x800AA4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA508;
    // 0x800AA4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA4FC:
    // 0x800AA4FC: jal         0x800AB934
    // 0x800AA500: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AB934(rdram, ctx);
        goto after_4;
    // 0x800AA500: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
L_800AA504:
    // 0x800AA504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA508:
    // 0x800AA508: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AA50C: jr          $ra
    // 0x800AA510: nop

    return;
    // 0x800AA510: nop

;}

RECOMP_FUNC void func_800AA514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA514: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800AA518: lw          $v1, -0x69F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69F8);
    // 0x800AA51C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AA520: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AA524: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AA528: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AA52C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AA530: blez        $v1, L_800AA590
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800AA534: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800AA590;
    }
    // 0x800AA534: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800AA538: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800AA53C: addiu       $s1, $s1, 0x7B00
    ctx->r17 = ADD32(ctx->r17, 0X7B00);
    // 0x800AA540: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AA544:
    // 0x800AA544: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800AA548: addu        $v0, $t6, $s0
    ctx->r2 = ADD32(ctx->r14, ctx->r16);
    // 0x800AA54C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800AA550: beql        $t7, $zero, L_800AA584
    if (ctx->r15 == 0) {
        // 0x800AA554: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800AA584;
    }
    goto skip_0;
    // 0x800AA554: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800AA558: jal         0x8007E328
    // 0x800AA55C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA55C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_0:
    // 0x800AA560: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800AA564: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800AA568: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800AA56C: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800AA570: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800AA574: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x800AA578: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AA57C: lw          $v1, -0x69F8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69F8);
    // 0x800AA580: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800AA584:
    // 0x800AA584: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AA588: bne         $at, $zero, L_800AA544
    if (ctx->r1 != 0) {
        // 0x800AA58C: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_800AA544;
    }
    // 0x800AA58C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800AA590:
    // 0x800AA590: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AA594: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AA598: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA59C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AA5A0: jr          $ra
    // 0x800AA5A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AA5A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800AA5A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA5A8: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800AA5AC: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800AA5B0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AA5B4: jr          $ra
    // 0x800AA5B8: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    return;
    // 0x800AA5B8: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
;}

RECOMP_FUNC void func_800AA5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA5BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AA5C0: jr          $ra
    // 0x800AA5C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AA5C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AA5C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA5C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA5CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA5D0: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800AA5D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA5D8: bne         $a1, $at, L_800AA5F0
    if (ctx->r5 != ctx->r1) {
        // 0x800AA5DC: nop
    
            goto L_800AA5F0;
    }
    // 0x800AA5DC: nop

    // 0x800AA5E0: jal         0x8007E328
    // 0x800AA5E4: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA5E4: nop

    after_0:
    // 0x800AA5E8: b           L_800AA5FC
    // 0x800AA5EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA5FC;
    // 0x800AA5EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA5F0:
    // 0x800AA5F0: jal         0x800AA3F4
    // 0x800AA5F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA3F4(rdram, ctx);
        goto after_1;
    // 0x800AA5F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800AA5F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA5FC:
    // 0x800AA5FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA600: jr          $ra
    // 0x800AA604: nop

    return;
    // 0x800AA604: nop

;}

RECOMP_FUNC void func_800AA608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA608: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800AA60C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800AA610: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800AA614: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x800AA618: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AA61C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800AA620: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x800AA624: jr          $ra
    // 0x800AA628: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    return;
    // 0x800AA628: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
;}

RECOMP_FUNC void func_800AA62C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA62C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AA630: jr          $ra
    // 0x800AA634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AA634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AA638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA63C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA640: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800AA644: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA648: bne         $a1, $at, L_800AA660
    if (ctx->r5 != ctx->r1) {
        // 0x800AA64C: nop
    
            goto L_800AA660;
    }
    // 0x800AA64C: nop

    // 0x800AA650: jal         0x8007E328
    // 0x800AA654: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA654: nop

    after_0:
    // 0x800AA658: b           L_800AA66C
    // 0x800AA65C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA66C;
    // 0x800AA65C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA660:
    // 0x800AA660: jal         0x800AA3F4
    // 0x800AA664: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA3F4(rdram, ctx);
        goto after_1;
    // 0x800AA664: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800AA668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA66C:
    // 0x800AA66C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA670: jr          $ra
    // 0x800AA674: nop

    return;
    // 0x800AA674: nop

;}

RECOMP_FUNC void func_800AA678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA678: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x800AA67C: lw          $t9, 0x20($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X20);
    // 0x800AA680: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x800AA684: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x800AA688: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800AA68C: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x800AA690: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x800AA694: addiu       $v0, $t7, 0x10
    ctx->r2 = ADD32(ctx->r15, 0X10);
    // 0x800AA698: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800AA69C: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x800AA6A0: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x800AA6A4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x800AA6A8: beq         $v1, $zero, L_800AA730
    if (ctx->r3 == 0) {
        // 0x800AA6AC: sw          $t4, 0x2C($a0)
        MEM_W(0X2C, ctx->r4) = ctx->r12;
            goto L_800AA730;
    }
    // 0x800AA6AC: sw          $t4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r12;
    // 0x800AA6B0: andi        $a2, $v1, 0x3
    ctx->r6 = ctx->r3 & 0X3;
    // 0x800AA6B4: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800AA6B8: beq         $a2, $zero, L_800AA6E4
    if (ctx->r6 == 0) {
        // 0x800AA6BC: addu        $a1, $a2, $v1
        ctx->r5 = ADD32(ctx->r6, ctx->r3);
            goto L_800AA6E4;
    }
    // 0x800AA6BC: addu        $a1, $a2, $v1
    ctx->r5 = ADD32(ctx->r6, ctx->r3);
L_800AA6C0:
    // 0x800AA6C0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800AA6C4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AA6C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AA6CC: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x800AA6D0: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800AA6D4: bne         $a1, $v1, L_800AA6C0
    if (ctx->r5 != ctx->r3) {
        // 0x800AA6D8: sw          $t7, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r15;
            goto L_800AA6C0;
    }
    // 0x800AA6D8: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x800AA6DC: beql        $v1, $zero, L_800AA734
    if (ctx->r3 == 0) {
        // 0x800AA6E0: lw          $t0, 0x28($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X28);
            goto L_800AA734;
    }
    goto skip_0;
    // 0x800AA6E0: lw          $t0, 0x28($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X28);
    skip_0:
L_800AA6E4:
    // 0x800AA6E4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AA6E8: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800AA6EC: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x800AA6F0: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800AA6F4: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x800AA6F8: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x800AA6FC: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x800AA700: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x800AA704: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800AA708: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800AA70C: addiu       $t6, $t5, 0x10
    ctx->r14 = ADD32(ctx->r13, 0X10);
    // 0x800AA710: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x800AA714: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800AA718: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800AA71C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x800AA720: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x800AA724: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800AA728: bne         $v1, $zero, L_800AA6E4
    if (ctx->r3 != 0) {
        // 0x800AA72C: sw          $t0, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->r8;
            goto L_800AA6E4;
    }
    // 0x800AA72C: sw          $t0, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r8;
L_800AA730:
    // 0x800AA730: lw          $t0, 0x28($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X28);
L_800AA734:
    // 0x800AA734: beq         $t0, $zero, L_800AA85C
    if (ctx->r8 == 0) {
        // 0x800AA738: nop
    
            goto L_800AA85C;
    }
    // 0x800AA738: nop

    // 0x800AA73C: lw          $t1, 0x28($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X28);
    // 0x800AA740: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x800AA744: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x800AA748: sw          $t3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r11;
    // 0x800AA74C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800AA750: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x800AA754: addiu       $t6, $t5, 0x10
    ctx->r14 = ADD32(ctx->r13, 0X10);
    // 0x800AA758: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x800AA75C: lw          $a1, 0x28($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X28);
    // 0x800AA760: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800AA764: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800AA768: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800AA76C: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800AA770: lw          $a1, 0x28($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X28);
    // 0x800AA774: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800AA778: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800AA77C: beq         $v1, $zero, L_800AA85C
    if (ctx->r3 == 0) {
        // 0x800AA780: andi        $a2, $v1, 0x3
        ctx->r6 = ctx->r3 & 0X3;
            goto L_800AA85C;
    }
    // 0x800AA780: andi        $a2, $v1, 0x3
    ctx->r6 = ctx->r3 & 0X3;
    // 0x800AA784: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800AA788: beq         $a2, $zero, L_800AA7C4
    if (ctx->r6 == 0) {
        // 0x800AA78C: addu        $a1, $a2, $v1
        ctx->r5 = ADD32(ctx->r6, ctx->r3);
            goto L_800AA7C4;
    }
    // 0x800AA78C: addu        $a1, $a2, $v1
    ctx->r5 = ADD32(ctx->r6, ctx->r3);
L_800AA790:
    // 0x800AA790: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800AA794: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AA798: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800AA79C: bne         $at, $zero, L_800AA7B4
    if (ctx->r1 != 0) {
        // 0x800AA7A0: nop
    
            goto L_800AA7B4;
    }
    // 0x800AA7A0: nop

    // 0x800AA7A4: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800AA7A8: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x800AA7AC: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x800AA7B0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
L_800AA7B4:
    // 0x800AA7B4: bne         $a1, $v1, L_800AA790
    if (ctx->r5 != ctx->r3) {
        // 0x800AA7B8: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800AA790;
    }
    // 0x800AA7B8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800AA7BC: beq         $v1, $zero, L_800AA85C
    if (ctx->r3 == 0) {
        // 0x800AA7C0: nop
    
            goto L_800AA85C;
    }
    // 0x800AA7C0: nop

L_800AA7C4:
    // 0x800AA7C4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800AA7C8: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800AA7CC: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x800AA7D0: bnel        $at, $zero, L_800AA7EC
    if (ctx->r1 != 0) {
        // 0x800AA7D4: lw          $t8, 0x8($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X8);
            goto L_800AA7EC;
    }
    goto skip_1;
    // 0x800AA7D4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    skip_1:
    // 0x800AA7D8: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x800AA7DC: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x800AA7E0: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800AA7E4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800AA7E8: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
L_800AA7EC:
    // 0x800AA7EC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800AA7F0: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x800AA7F4: bnel        $at, $zero, L_800AA810
    if (ctx->r1 != 0) {
        // 0x800AA7F8: lw          $t2, 0x8($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X8);
            goto L_800AA810;
    }
    goto skip_2;
    // 0x800AA7F8: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    skip_2:
    // 0x800AA7FC: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800AA800: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x800AA804: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800AA808: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800AA80C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
L_800AA810:
    // 0x800AA810: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800AA814: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800AA818: bnel        $at, $zero, L_800AA834
    if (ctx->r1 != 0) {
        // 0x800AA81C: lw          $t6, 0x8($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X8);
            goto L_800AA834;
    }
    goto skip_3;
    // 0x800AA81C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    skip_3:
    // 0x800AA820: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x800AA824: addu        $t4, $t3, $a0
    ctx->r12 = ADD32(ctx->r11, ctx->r4);
    // 0x800AA828: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x800AA82C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800AA830: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
L_800AA834:
    // 0x800AA834: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800AA838: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800AA83C: bne         $at, $zero, L_800AA854
    if (ctx->r1 != 0) {
        // 0x800AA840: nop
    
            goto L_800AA854;
    }
    // 0x800AA840: nop

    // 0x800AA844: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800AA848: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800AA84C: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800AA850: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800AA854:
    // 0x800AA854: bne         $v1, $zero, L_800AA7C4
    if (ctx->r3 != 0) {
        // 0x800AA858: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800AA7C4;
    }
    // 0x800AA858: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800AA85C:
    // 0x800AA85C: jr          $ra
    // 0x800AA860: nop

    return;
    // 0x800AA860: nop

;}

RECOMP_FUNC void func_800AA864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA864: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800AA868: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800AA86C: jr          $ra
    // 0x800AA870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AA870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AA874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA87C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800AA880: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA884: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800AA888: bnel        $a1, $at, L_800AA8A4
    if (ctx->r5 != ctx->r1) {
        // 0x800AA88C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800AA8A4;
    }
    goto skip_0;
    // 0x800AA88C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x800AA890: jal         0x8007E328
    // 0x800AA894: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA894: nop

    after_0:
    // 0x800AA898: b           L_800AA8BC
    // 0x800AA89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA8BC;
    // 0x800AA89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA8A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800AA8A4:
    // 0x800AA8A4: jal         0x800AA3DC
    // 0x800AA8A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800AA3DC(rdram, ctx);
        goto after_1;
    // 0x800AA8A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x800AA8AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800AA8B0: jal         0x800AA3F4
    // 0x800AA8B4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    func_800AA3F4(rdram, ctx);
        goto after_2;
    // 0x800AA8B4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    after_2:
    // 0x800AA8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA8BC:
    // 0x800AA8BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA8C0: jr          $ra
    // 0x800AA8C4: nop

    return;
    // 0x800AA8C4: nop

;}

RECOMP_FUNC void func_800AA8C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA8C8: jr          $ra
    // 0x800AA8CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800AA8CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

RECOMP_FUNC void func_800AA8D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA8D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AA8D4: jr          $ra
    // 0x800AA8D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AA8D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AA8DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA8DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA8E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA8E4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800AA8E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA8EC: bne         $a1, $at, L_800AA904
    if (ctx->r5 != ctx->r1) {
        // 0x800AA8F0: nop
    
            goto L_800AA904;
    }
    // 0x800AA8F0: nop

    // 0x800AA8F4: jal         0x8007E328
    // 0x800AA8F8: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA8F8: nop

    after_0:
    // 0x800AA8FC: b           L_800AA910
    // 0x800AA900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA910;
    // 0x800AA900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA904:
    // 0x800AA904: jal         0x800AA3F4
    // 0x800AA908: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA3F4(rdram, ctx);
        goto after_1;
    // 0x800AA908: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800AA90C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA910:
    // 0x800AA910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA914: jr          $ra
    // 0x800AA918: nop

    return;
    // 0x800AA918: nop

;}

RECOMP_FUNC void func_800AA91C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA91C: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x800AA920: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800AA924: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800AA928: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800AA92C: jr          $ra
    // 0x800AA930: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    return;
    // 0x800AA930: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
;}

RECOMP_FUNC void func_800AA934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA934: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AA938: jr          $ra
    // 0x800AA93C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AA93C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AA940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA948: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800AA94C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA950: bne         $a1, $at, L_800AA968
    if (ctx->r5 != ctx->r1) {
        // 0x800AA954: nop
    
            goto L_800AA968;
    }
    // 0x800AA954: nop

    // 0x800AA958: jal         0x8007E328
    // 0x800AA95C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AA95C: nop

    after_0:
    // 0x800AA960: b           L_800AA974
    // 0x800AA964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AA974;
    // 0x800AA964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA968:
    // 0x800AA968: jal         0x800AA3F4
    // 0x800AA96C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA3F4(rdram, ctx);
        goto after_1;
    // 0x800AA96C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800AA970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AA974:
    // 0x800AA974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA978: jr          $ra
    // 0x800AA97C: nop

    return;
    // 0x800AA97C: nop

;}

RECOMP_FUNC void func_800AA980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA988: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x800AA98C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800AA990: beql        $t6, $zero, L_800AAA34
    if (ctx->r14 == 0) {
        // 0x800AA994: lw          $t5, 0x30($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X30);
            goto L_800AAA34;
    }
    goto skip_0;
    // 0x800AA994: lw          $t5, 0x30($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X30);
    skip_0:
    // 0x800AA998: lw          $t7, 0x28($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X28);
    // 0x800AA99C: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x800AA9A0: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800AA9A4: addiu       $v0, $t8, 0x10
    ctx->r2 = ADD32(ctx->r24, 0X10);
    // 0x800AA9A8: beq         $v1, $zero, L_800AAA30
    if (ctx->r3 == 0) {
        // 0x800AA9AC: sw          $v0, 0x28($a0)
        MEM_W(0X28, ctx->r4) = ctx->r2;
            goto L_800AAA30;
    }
    // 0x800AA9AC: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x800AA9B0: andi        $a1, $v1, 0x3
    ctx->r5 = ctx->r3 & 0X3;
    // 0x800AA9B4: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800AA9B8: beq         $a1, $zero, L_800AA9E4
    if (ctx->r5 == 0) {
        // 0x800AA9BC: addu        $a0, $a1, $v1
        ctx->r4 = ADD32(ctx->r5, ctx->r3);
            goto L_800AA9E4;
    }
    // 0x800AA9BC: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_800AA9C0:
    // 0x800AA9C0: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800AA9C4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AA9C8: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800AA9CC: addu        $t1, $t0, $a2
    ctx->r9 = ADD32(ctx->r8, ctx->r6);
    // 0x800AA9D0: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x800AA9D4: bne         $a0, $v1, L_800AA9C0
    if (ctx->r4 != ctx->r3) {
        // 0x800AA9D8: sw          $t2, -0x3C($v0)
        MEM_W(-0X3C, ctx->r2) = ctx->r10;
            goto L_800AA9C0;
    }
    // 0x800AA9D8: sw          $t2, -0x3C($v0)
    MEM_W(-0X3C, ctx->r2) = ctx->r10;
    // 0x800AA9DC: beql        $v1, $zero, L_800AAA34
    if (ctx->r3 == 0) {
        // 0x800AA9E0: lw          $t5, 0x30($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X30);
            goto L_800AAA34;
    }
    goto skip_1;
    // 0x800AA9E0: lw          $t5, 0x30($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X30);
    skip_1:
L_800AA9E4:
    // 0x800AA9E4: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x800AA9E8: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x800AA9EC: lw          $t9, 0x84($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84);
    // 0x800AA9F0: lw          $t2, 0xC4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC4);
    // 0x800AA9F4: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x800AA9F8: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x800AA9FC: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800AAA00: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x800AAA04: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x800AAA08: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x800AAA0C: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800AAA10: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800AAA14: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800AAA18: sw          $t8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r24;
    // 0x800AAA1C: sw          $t1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r9;
    // 0x800AAA20: sw          $t4, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->r12;
    // 0x800AAA24: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x800AAA28: bne         $v1, $zero, L_800AA9E4
    if (ctx->r3 != 0) {
        // 0x800AAA2C: sw          $t5, -0xFC($v0)
        MEM_W(-0XFC, ctx->r2) = ctx->r13;
            goto L_800AA9E4;
    }
    // 0x800AAA2C: sw          $t5, -0xFC($v0)
    MEM_W(-0XFC, ctx->r2) = ctx->r13;
L_800AAA30:
    // 0x800AAA30: lw          $t5, 0x30($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X30);
L_800AAA34:
    // 0x800AAA34: beql        $t5, $zero, L_800AAA50
    if (ctx->r13 == 0) {
        // 0x800AAA38: lw          $t9, 0x2C($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X2C);
            goto L_800AAA50;
    }
    goto skip_2;
    // 0x800AAA38: lw          $t9, 0x2C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X2C);
    skip_2:
    // 0x800AAA3C: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x800AAA40: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800AAA44: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800AAA48: sw          $t8, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r24;
    // 0x800AAA4C: lw          $t9, 0x2C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X2C);
L_800AAA50:
    // 0x800AAA50: beql        $t9, $zero, L_800AAA7C
    if (ctx->r25 == 0) {
        // 0x800AAA54: lw          $t3, 0x38($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X38);
            goto L_800AAA7C;
    }
    goto skip_3;
    // 0x800AAA54: lw          $t3, 0x38($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X38);
    skip_3:
    // 0x800AAA58: lw          $t0, 0x2C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X2C);
    // 0x800AAA5C: addiu       $a1, $a2, 0x10
    ctx->r5 = ADD32(ctx->r6, 0X10);
    // 0x800AAA60: addu        $t1, $t0, $a2
    ctx->r9 = ADD32(ctx->r8, ctx->r6);
    // 0x800AAA64: addiu       $a0, $t1, 0x10
    ctx->r4 = ADD32(ctx->r9, 0X10);
    // 0x800AAA68: sw          $a0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r4;
    // 0x800AAA6C: jal         0x800ABAB8
    // 0x800AAA70: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800ABAB8(rdram, ctx);
        goto after_0;
    // 0x800AAA70: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800AAA74: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800AAA78: lw          $t3, 0x38($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X38);
L_800AAA7C:
    // 0x800AAA7C: beql        $t3, $zero, L_800AAA98
    if (ctx->r11 == 0) {
        // 0x800AAA80: lw          $t7, 0x3C($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X3C);
            goto L_800AAA98;
    }
    goto skip_4;
    // 0x800AAA80: lw          $t7, 0x3C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X3C);
    skip_4:
    // 0x800AAA84: lw          $t4, 0x38($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X38);
    // 0x800AAA88: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800AAA8C: addiu       $t6, $t5, 0x10
    ctx->r14 = ADD32(ctx->r13, 0X10);
    // 0x800AAA90: sw          $t6, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->r14;
    // 0x800AAA94: lw          $t7, 0x3C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X3C);
L_800AAA98:
    // 0x800AAA98: beql        $t7, $zero, L_800AAAB4
    if (ctx->r15 == 0) {
        // 0x800AAA9C: lw          $t1, 0x40($a2)
        ctx->r9 = MEM_W(ctx->r6, 0X40);
            goto L_800AAAB4;
    }
    goto skip_5;
    // 0x800AAA9C: lw          $t1, 0x40($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X40);
    skip_5:
    // 0x800AAAA0: lw          $t8, 0x3C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X3C);
    // 0x800AAAA4: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x800AAAA8: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x800AAAAC: sw          $t0, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r8;
    // 0x800AAAB0: lw          $t1, 0x40($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X40);
L_800AAAB4:
    // 0x800AAAB4: beql        $t1, $zero, L_800AAAD0
    if (ctx->r9 == 0) {
        // 0x800AAAB8: lw          $t5, 0x44($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X44);
            goto L_800AAAD0;
    }
    goto skip_6;
    // 0x800AAAB8: lw          $t5, 0x44($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X44);
    skip_6:
    // 0x800AAABC: lw          $t2, 0x40($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X40);
    // 0x800AAAC0: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x800AAAC4: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x800AAAC8: sw          $t4, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r12;
    // 0x800AAACC: lw          $t5, 0x44($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X44);
L_800AAAD0:
    // 0x800AAAD0: beql        $t5, $zero, L_800AAAEC
    if (ctx->r13 == 0) {
        // 0x800AAAD4: lw          $t9, 0x48($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X48);
            goto L_800AAAEC;
    }
    goto skip_7;
    // 0x800AAAD4: lw          $t9, 0x48($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X48);
    skip_7:
    // 0x800AAAD8: lw          $t6, 0x44($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X44);
    // 0x800AAADC: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800AAAE0: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800AAAE4: sw          $t8, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r24;
    // 0x800AAAE8: lw          $t9, 0x48($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X48);
L_800AAAEC:
    // 0x800AAAEC: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800AAAF0: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x800AAAF4: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800AAAF8: sw          $t1, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->r9;
    // 0x800AAAFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AAB00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AAB04: jr          $ra
    // 0x800AAB08: nop

    return;
    // 0x800AAB08: nop

;}

RECOMP_FUNC void func_800AAB0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AAB0C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800AAB10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AAB14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AAB18: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x800AAB1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AAB20: lw          $v1, 0x28($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X28);
    // 0x800AAB24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AAB28: blez        $t0, L_800AABE0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800AAB2C: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_800AABE0;
    }
    // 0x800AAB2C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800AAB30:
    // 0x800AAB30: lbu         $a0, 0x3($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X3);
    // 0x800AAB34: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800AAB38: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800AAB3C: beq         $a0, $zero, L_800AABD8
    if (ctx->r4 == 0) {
        // 0x800AAB40: addiu       $a3, $a3, 0x188
        ctx->r7 = ADD32(ctx->r7, 0X188);
            goto L_800AABD8;
    }
    // 0x800AAB40: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AAB44: andi        $a2, $a0, 0x3
    ctx->r6 = ctx->r4 & 0X3;
    // 0x800AAB48: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800AAB4C: beq         $a2, $zero, L_800AAB7C
    if (ctx->r6 == 0) {
        // 0x800AAB50: addu        $a1, $a2, $a0
        ctx->r5 = ADD32(ctx->r6, ctx->r4);
            goto L_800AAB7C;
    }
    // 0x800AAB50: addu        $a1, $a2, $a0
    ctx->r5 = ADD32(ctx->r6, ctx->r4);
L_800AAB54:
    // 0x800AAB54: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800AAB58: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x800AAB5C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800AAB60: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800AAB64: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AAB68: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800AAB6C: bne         $a1, $a0, L_800AAB54
    if (ctx->r5 != ctx->r4) {
        // 0x800AAB70: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800AAB54;
    }
    // 0x800AAB70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AAB74: beq         $a0, $zero, L_800AABD8
    if (ctx->r4 == 0) {
        // 0x800AAB78: nop
    
            goto L_800AABD8;
    }
    // 0x800AAB78: nop

L_800AAB7C:
    // 0x800AAB7C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800AAB80: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x800AAB84: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800AAB88: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800AAB8C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AAB90: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AAB94: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x800AAB98: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800AAB9C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x800AABA0: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x800AABA4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800AABA8: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x800AABAC: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800AABB0: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800AABB4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AABB8: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x800AABBC: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x800AABC0: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800AABC4: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800AABC8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AABCC: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x800AABD0: bne         $a0, $zero, L_800AAB7C
    if (ctx->r4 != 0) {
        // 0x800AABD4: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_800AAB7C;
    }
    // 0x800AABD4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
L_800AABD8:
    // 0x800AABD8: bne         $t1, $t0, L_800AAB30
    if (ctx->r9 != ctx->r8) {
        // 0x800AABDC: addiu       $v1, $v1, 0x40
        ctx->r3 = ADD32(ctx->r3, 0X40);
            goto L_800AAB30;
    }
    // 0x800AABDC: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
L_800AABE0:
    // 0x800AABE0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x800AABE4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800AABE8: beql        $t3, $a0, L_800AAC0C
    if (ctx->r11 == ctx->r4) {
        // 0x800AABEC: sw          $zero, 0x34($s0)
        MEM_W(0X34, ctx->r16) = 0;
            goto L_800AAC0C;
    }
    goto skip_0;
    // 0x800AABEC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    skip_0:
    // 0x800AABF0: jal         0x800AA14C
    // 0x800AABF4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_800AA14C(rdram, ctx);
        goto after_0;
    // 0x800AABF4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x800AABF8: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800AABFC: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800AAC00: b           L_800AAC0C
    // 0x800AAC04: addiu       $a3, $a3, 0x80
    ctx->r7 = ADD32(ctx->r7, 0X80);
        goto L_800AAC0C;
    // 0x800AAC04: addiu       $a3, $a3, 0x80
    ctx->r7 = ADD32(ctx->r7, 0X80);
    // 0x800AAC08: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
L_800AAC0C:
    // 0x800AAC0C: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x800AAC10: beql        $a0, $zero, L_800AAC60
    if (ctx->r4 == 0) {
        // 0x800AAC14: lw          $v0, 0x3C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X3C);
            goto L_800AAC60;
    }
    goto skip_1;
    // 0x800AAC14: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    skip_1:
    // 0x800AAC18: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x800AAC1C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800AAC20: beql        $t1, $zero, L_800AAC60
    if (ctx->r9 == 0) {
        // 0x800AAC24: lw          $v0, 0x3C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X3C);
            goto L_800AAC60;
    }
    goto skip_2;
    // 0x800AAC24: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    skip_2:
L_800AAC28:
    // 0x800AAC28: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800AAC2C: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800AAC30: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800AAC34: jal         0x800AA14C
    // 0x800AAC38: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_800AA14C(rdram, ctx);
        goto after_1;
    // 0x800AAC38: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_1:
    // 0x800AAC3C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800AAC40: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800AAC44: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800AAC48: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AAC4C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AAC50: sw          $v0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r2;
    // 0x800AAC54: bne         $t1, $zero, L_800AAC28
    if (ctx->r9 != 0) {
        // 0x800AAC58: addiu       $a3, $a3, 0x20
        ctx->r7 = ADD32(ctx->r7, 0X20);
            goto L_800AAC28;
    }
    // 0x800AAC58: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800AAC5C: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
L_800AAC60:
    // 0x800AAC60: beql        $v0, $zero, L_800AADE0
    if (ctx->r2 == 0) {
        // 0x800AAC64: lw          $v0, 0x40($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X40);
            goto L_800AADE0;
    }
    goto skip_3;
    // 0x800AAC64: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    skip_3:
    // 0x800AAC68: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
    // 0x800AAC6C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800AAC70: beql        $t1, $zero, L_800AADE0
    if (ctx->r9 == 0) {
        // 0x800AAC74: lw          $v0, 0x40($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X40);
            goto L_800AADE0;
    }
    goto skip_4;
    // 0x800AAC74: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    skip_4:
L_800AAC78:
    // 0x800AAC78: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800AAC7C: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800AAC80: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800AAC84: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800AAC88: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x800AAC8C: jal         0x800AA14C
    // 0x800AAC90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800AA14C(rdram, ctx);
        goto after_2;
    // 0x800AAC90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800AAC94: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800AAC98: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800AAC9C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800AACA0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800AACA4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800AACA8: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x800AACAC: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800AACB0: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AACB4: beql        $t8, $zero, L_800AACD4
    if (ctx->r24 == 0) {
        // 0x800AACB8: lw          $t2, 0x0($t0)
        ctx->r10 = MEM_W(ctx->r8, 0X0);
            goto L_800AACD4;
    }
    goto skip_5;
    // 0x800AACB8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    skip_5:
    // 0x800AACBC: lw          $t5, 0x24($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X24);
    // 0x800AACC0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    // 0x800AACC4: and         $t9, $a3, $at
    ctx->r25 = ctx->r7 & ctx->r1;
    // 0x800AACC8: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x800AACCC: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
    // 0x800AACD0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
L_800AACD4:
    // 0x800AACD4: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x800AACD8: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x800AACDC: beq         $a0, $zero, L_800AADA8
    if (ctx->r4 == 0) {
        // 0x800AACE0: andi        $a2, $a0, 0x3
        ctx->r6 = ctx->r4 & 0X3;
            goto L_800AADA8;
    }
    // 0x800AACE0: andi        $a2, $a0, 0x3
    ctx->r6 = ctx->r4 & 0X3;
    // 0x800AACE4: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800AACE8: beq         $a2, $zero, L_800AAD20
    if (ctx->r6 == 0) {
        // 0x800AACEC: addu        $v1, $a2, $a0
        ctx->r3 = ADD32(ctx->r6, ctx->r4);
            goto L_800AAD20;
    }
    // 0x800AACEC: addu        $v1, $a2, $a0
    ctx->r3 = ADD32(ctx->r6, ctx->r4);
L_800AACF0:
    // 0x800AACF0: lwl         $t7, 0x0($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X0);
    // 0x800AACF4: lwr         $t7, 0x3($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X3);
    // 0x800AACF8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800AACFC: ori         $t9, $a1, 0x1
    ctx->r25 = ctx->r5 | 0X1;
    // 0x800AAD00: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x800AAD04: beq         $t8, $zero, L_800AAD10
    if (ctx->r24 == 0) {
        // 0x800AAD08: nop
    
            goto L_800AAD10;
    }
    // 0x800AAD08: nop

    // 0x800AAD0C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_800AAD10:
    // 0x800AAD10: bne         $v1, $a0, L_800AACF0
    if (ctx->r3 != ctx->r4) {
        // 0x800AAD14: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800AACF0;
    }
    // 0x800AAD14: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800AAD18: beq         $a0, $zero, L_800AADA8
    if (ctx->r4 == 0) {
        // 0x800AAD1C: nop
    
            goto L_800AADA8;
    }
    // 0x800AAD1C: nop

L_800AAD20:
    // 0x800AAD20: lwl         $t4, 0x0($v0)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X0);
    // 0x800AAD24: lwr         $t4, 0x3($v0)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r2, 0X3);
    // 0x800AAD28: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800AAD2C: ori         $t6, $a1, 0x1
    ctx->r14 = ctx->r5 | 0X1;
    // 0x800AAD30: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800AAD34: beql        $t5, $zero, L_800AAD44
    if (ctx->r13 == 0) {
        // 0x800AAD38: lwl         $t7, 0x14($v0)
        ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X14);
            goto L_800AAD44;
    }
    goto skip_6;
    // 0x800AAD38: lwl         $t7, 0x14($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X14);
    skip_6:
    // 0x800AAD3C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800AAD40: lwl         $t7, 0x14($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X14);
L_800AAD44:
    // 0x800AAD44: lwr         $t7, 0x17($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X17);
    // 0x800AAD48: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800AAD4C: ori         $t9, $a1, 0x1
    ctx->r25 = ctx->r5 | 0X1;
    // 0x800AAD50: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x800AAD54: beql        $t8, $zero, L_800AAD64
    if (ctx->r24 == 0) {
        // 0x800AAD58: lwl         $t4, 0x14($v0)
        ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X14);
            goto L_800AAD64;
    }
    goto skip_7;
    // 0x800AAD58: lwl         $t4, 0x14($v0)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X14);
    skip_7:
    // 0x800AAD5C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800AAD60: lwl         $t4, 0x14($v0)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X14);
L_800AAD64:
    // 0x800AAD64: lwr         $t4, 0x17($v0)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r2, 0X17);
    // 0x800AAD68: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800AAD6C: ori         $t6, $a1, 0x1
    ctx->r14 = ctx->r5 | 0X1;
    // 0x800AAD70: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800AAD74: beql        $t5, $zero, L_800AAD84
    if (ctx->r13 == 0) {
        // 0x800AAD78: lwl         $t7, 0x14($v0)
        ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X14);
            goto L_800AAD84;
    }
    goto skip_8;
    // 0x800AAD78: lwl         $t7, 0x14($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X14);
    skip_8:
    // 0x800AAD7C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800AAD80: lwl         $t7, 0x14($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X14);
L_800AAD84:
    // 0x800AAD84: lwr         $t7, 0x17($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X17);
    // 0x800AAD88: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800AAD8C: ori         $t9, $a1, 0x1
    ctx->r25 = ctx->r5 | 0X1;
    // 0x800AAD90: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x800AAD94: beq         $t8, $zero, L_800AADA0
    if (ctx->r24 == 0) {
        // 0x800AAD98: nop
    
            goto L_800AADA0;
    }
    // 0x800AAD98: nop

    // 0x800AAD9C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_800AADA0:
    // 0x800AADA0: bne         $a0, $zero, L_800AAD20
    if (ctx->r4 != 0) {
        // 0x800AADA4: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800AAD20;
    }
    // 0x800AADA4: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
L_800AADA8:
    // 0x800AADA8: beq         $a1, $zero, L_800AADC8
    if (ctx->r5 == 0) {
        // 0x800AADAC: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_800AADC8;
    }
    // 0x800AADAC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800AADB0: sw          $t4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r12;
    // 0x800AADB4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800AADB8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800AADBC: addiu       $a3, $a3, 0x60
    ctx->r7 = ADD32(ctx->r7, 0X60);
    // 0x800AADC0: b           L_800AADD4
    // 0x800AADC4: sw          $t5, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r13;
        goto L_800AADD4;
    // 0x800AADC4: sw          $t5, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r13;
L_800AADC8:
    // 0x800AADC8: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x800AADCC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800AADD0: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
L_800AADD4:
    // 0x800AADD4: bne         $t1, $zero, L_800AAC78
    if (ctx->r9 != 0) {
        // 0x800AADD8: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_800AAC78;
    }
    // 0x800AADD8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800AADDC: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
L_800AADE0:
    // 0x800AADE0: beq         $v0, $zero, L_800AAE28
    if (ctx->r2 == 0) {
        // 0x800AADE4: nop
    
            goto L_800AAE28;
    }
    // 0x800AADE4: nop

    // 0x800AADE8: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x800AADEC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800AADF0: beq         $t1, $zero, L_800AAE28
    if (ctx->r9 == 0) {
        // 0x800AADF4: nop
    
            goto L_800AAE28;
    }
    // 0x800AADF4: nop

L_800AADF8:
    // 0x800AADF8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800AADFC: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800AAE00: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800AAE04: jal         0x800AA14C
    // 0x800AAE08: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800AA14C(rdram, ctx);
        goto after_3;
    // 0x800AAE08: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x800AAE0C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800AAE10: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800AAE14: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800AAE18: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AAE1C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AAE20: bne         $t1, $zero, L_800AADF8
    if (ctx->r9 != 0) {
        // 0x800AAE24: sw          $v0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r2;
            goto L_800AADF8;
    }
    // 0x800AAE24: sw          $v0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r2;
L_800AAE28:
    // 0x800AAE28: jal         0x8007E03C
    // 0x800AAE2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800AAE2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x800AAE30: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x800AAE34: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x800AAE38: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x800AAE3C: beq         $t1, $zero, L_800AB2AC
    if (ctx->r9 == 0) {
        // 0x800AAE40: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800AB2AC;
    }
    // 0x800AAE40: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800AAE44: andi        $a1, $t1, 0x3
    ctx->r5 = ctx->r9 & 0X3;
    // 0x800AAE48: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800AAE4C: beql        $a1, $zero, L_800AAF50
    if (ctx->r5 == 0) {
        // 0x800AAE50: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800AAF50;
    }
    goto skip_9;
    // 0x800AAE50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_9:
    // 0x800AAE54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AAE58: addu        $v0, $a1, $t1
    ctx->r2 = ADD32(ctx->r5, ctx->r9);
    // 0x800AAE5C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AAE60: sw          $a3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r7;
    // 0x800AAE64: beq         $v0, $t1, L_800AAEE0
    if (ctx->r2 == ctx->r9) {
        // 0x800AAE68: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_800AAEE0;
    }
    // 0x800AAE68: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_800AAE6C:
    // 0x800AAE6C: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AAE70: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800AAE74: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AAE78: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AAE7C: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AAE80: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x800AAE84: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AAE88: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AAE8C: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AAE90: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AAE94: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AAE98: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AAE9C: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEA0: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AAEA4: lw          $t8, -0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEA8: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AAEAC: lw          $t9, -0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEB0: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AAEB4: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEB8: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AAEBC: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEC0: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AAEC4: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEC8: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AAECC: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AAED0: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AAED4: sw          $a3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r7;
    // 0x800AAED8: bne         $v0, $t1, L_800AAE6C
    if (ctx->r2 != ctx->r9) {
        // 0x800AAEDC: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_800AAE6C;
    }
    // 0x800AAEDC: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_800AAEE0:
    // 0x800AAEE0: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AAEE4: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800AAEE8: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AAEEC: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AAEF0: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AAEF4: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AAEF8: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AAEFC: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF00: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AAF04: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF08: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AAF0C: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF10: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AAF14: lw          $t8, -0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF18: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AAF1C: lw          $t9, -0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF20: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AAF24: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF28: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AAF2C: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF30: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AAF34: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF38: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AAF3C: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AAF40: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AAF44: beql        $t1, $zero, L_800AB2B0
    if (ctx->r9 == 0) {
        // 0x800AAF48: lw          $v0, 0x34($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X34);
            goto L_800AB2B0;
    }
    goto skip_10;
    // 0x800AAF48: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    skip_10:
    // 0x800AAF4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800AAF50:
    // 0x800AAF50: nop

    // 0x800AAF54: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800AAF58: sw          $a3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r7;
    // 0x800AAF5C: beq         $t1, $zero, L_800AB110
    if (ctx->r9 == 0) {
        // 0x800AAF60: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_800AB110;
    }
    // 0x800AAF60: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_800AAF64:
    // 0x800AAF64: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AAF68: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800AAF6C: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AAF70: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800AAF74: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AAF78: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x800AAF7C: addiu       $v1, $v1, 0x100
    ctx->r3 = ADD32(ctx->r3, 0X100);
    // 0x800AAF80: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AAF84: lw          $t5, -0xF4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAF88: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AAF8C: lw          $t6, -0xF4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAF90: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AAF94: lw          $t7, -0xF4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAF98: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AAF9C: lw          $t8, -0xF4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAFA0: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AAFA4: lw          $t9, -0xF4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAFA8: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AAFAC: lw          $t4, -0xF4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAFB0: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AAFB4: lw          $t5, -0xF4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAFB8: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AAFBC: lw          $t6, -0xF4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAFC0: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AAFC4: lw          $t7, -0xF4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XF4);
    // 0x800AAFC8: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AAFCC: sw          $a3, -0xB4($v1)
    MEM_W(-0XB4, ctx->r3) = ctx->r7;
    // 0x800AAFD0: lw          $t8, -0xB4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XB4);
    // 0x800AAFD4: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AAFD8: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AAFDC: lw          $t9, -0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XB4);
    // 0x800AAFE0: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AAFE4: lw          $t4, -0xB4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XB4);
    // 0x800AAFE8: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AAFEC: lw          $t5, -0xB4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XB4);
    // 0x800AAFF0: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AAFF4: lw          $t6, -0xB4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XB4);
    // 0x800AAFF8: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AAFFC: lw          $t7, -0xB4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB000: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB004: lw          $t8, -0xB4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB008: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB00C: lw          $t9, -0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB010: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB014: lw          $t4, -0xB4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB018: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB01C: lw          $t5, -0xB4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB020: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB024: lw          $t6, -0xB4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB028: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB02C: lw          $t7, -0xB4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB030: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AB034: sw          $a3, -0x74($v1)
    MEM_W(-0X74, ctx->r3) = ctx->r7;
    // 0x800AB038: lw          $t8, -0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X74);
    // 0x800AB03C: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AB040: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AB044: lw          $t9, -0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X74);
    // 0x800AB048: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AB04C: lw          $t4, -0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X74);
    // 0x800AB050: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AB054: lw          $t5, -0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X74);
    // 0x800AB058: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AB05C: lw          $t6, -0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X74);
    // 0x800AB060: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AB064: lw          $t7, -0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X74);
    // 0x800AB068: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB06C: lw          $t8, -0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X74);
    // 0x800AB070: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB074: lw          $t9, -0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X74);
    // 0x800AB078: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB07C: lw          $t4, -0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X74);
    // 0x800AB080: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB084: lw          $t5, -0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X74);
    // 0x800AB088: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB08C: lw          $t6, -0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X74);
    // 0x800AB090: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB094: lw          $t7, -0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X74);
    // 0x800AB098: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AB09C: sw          $a3, -0x34($v1)
    MEM_W(-0X34, ctx->r3) = ctx->r7;
    // 0x800AB0A0: lw          $t8, -0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0A4: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AB0A8: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AB0AC: lw          $t9, -0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0B0: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AB0B4: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0B8: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AB0BC: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0C0: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AB0C4: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0C8: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AB0CC: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0D0: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB0D4: lw          $t8, -0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0D8: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB0DC: lw          $t9, -0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0E0: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB0E4: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0E8: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB0EC: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0F0: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB0F4: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AB0F8: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB0FC: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AB100: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AB104: sw          $a3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r7;
    // 0x800AB108: bne         $t1, $zero, L_800AAF64
    if (ctx->r9 != 0) {
        // 0x800AB10C: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_800AAF64;
    }
    // 0x800AB10C: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_800AB110:
    // 0x800AB110: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AB114: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800AB118: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AB11C: addiu       $v1, $v1, 0x100
    ctx->r3 = ADD32(ctx->r3, 0X100);
    // 0x800AB120: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AB124: lw          $t4, -0xF4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB128: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AB12C: lw          $t5, -0xF4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB130: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AB134: lw          $t6, -0xF4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB138: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AB13C: lw          $t7, -0xF4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB140: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB144: lw          $t8, -0xF4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB148: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB14C: lw          $t9, -0xF4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB150: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB154: lw          $t4, -0xF4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB158: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB15C: lw          $t5, -0xF4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB160: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB164: lw          $t6, -0xF4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB168: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB16C: lw          $t7, -0xF4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XF4);
    // 0x800AB170: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AB174: sw          $a3, -0xB4($v1)
    MEM_W(-0XB4, ctx->r3) = ctx->r7;
    // 0x800AB178: lw          $t8, -0xB4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB17C: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AB180: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AB184: lw          $t9, -0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB188: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AB18C: lw          $t4, -0xB4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB190: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AB194: lw          $t5, -0xB4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB198: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AB19C: lw          $t6, -0xB4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1A0: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AB1A4: lw          $t7, -0xB4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1A8: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB1AC: lw          $t8, -0xB4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1B0: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB1B4: lw          $t9, -0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1B8: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB1BC: lw          $t4, -0xB4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1C0: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB1C4: lw          $t5, -0xB4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1C8: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB1CC: lw          $t6, -0xB4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1D0: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB1D4: lw          $t7, -0xB4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XB4);
    // 0x800AB1D8: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AB1DC: sw          $a3, -0x74($v1)
    MEM_W(-0X74, ctx->r3) = ctx->r7;
    // 0x800AB1E0: lw          $t8, -0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X74);
    // 0x800AB1E4: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AB1E8: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AB1EC: lw          $t9, -0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X74);
    // 0x800AB1F0: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AB1F4: lw          $t4, -0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X74);
    // 0x800AB1F8: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AB1FC: lw          $t5, -0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X74);
    // 0x800AB200: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AB204: lw          $t6, -0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X74);
    // 0x800AB208: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AB20C: lw          $t7, -0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X74);
    // 0x800AB210: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB214: lw          $t8, -0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X74);
    // 0x800AB218: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB21C: lw          $t9, -0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X74);
    // 0x800AB220: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB224: lw          $t4, -0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X74);
    // 0x800AB228: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB22C: lw          $t5, -0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X74);
    // 0x800AB230: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB234: lw          $t6, -0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X74);
    // 0x800AB238: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB23C: lw          $t7, -0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X74);
    // 0x800AB240: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x800AB244: sw          $a3, -0x34($v1)
    MEM_W(-0X34, ctx->r3) = ctx->r7;
    // 0x800AB248: lw          $t8, -0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X34);
    // 0x800AB24C: addiu       $a3, $a3, 0x188
    ctx->r7 = ADD32(ctx->r7, 0X188);
    // 0x800AB250: swc1        $f0, 0x140($t8)
    MEM_W(0X140, ctx->r24) = ctx->f0.u32l;
    // 0x800AB254: lw          $t9, -0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X34);
    // 0x800AB258: swc1        $f0, 0x144($t9)
    MEM_W(0X144, ctx->r25) = ctx->f0.u32l;
    // 0x800AB25C: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AB260: swc1        $f0, 0x148($t4)
    MEM_W(0X148, ctx->r12) = ctx->f0.u32l;
    // 0x800AB264: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AB268: swc1        $f0, 0x14C($t5)
    MEM_W(0X14C, ctx->r13) = ctx->f0.u32l;
    // 0x800AB26C: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AB270: swc1        $f0, 0x150($t6)
    MEM_W(0X150, ctx->r14) = ctx->f0.u32l;
    // 0x800AB274: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AB278: swc1        $f0, 0x154($t7)
    MEM_W(0X154, ctx->r15) = ctx->f0.u32l;
    // 0x800AB27C: lw          $t8, -0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X34);
    // 0x800AB280: swc1        $f0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->f0.u32l;
    // 0x800AB284: lw          $t9, -0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X34);
    // 0x800AB288: swc1        $f0, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->f0.u32l;
    // 0x800AB28C: lw          $t4, -0x34($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X34);
    // 0x800AB290: swc1        $f0, 0x160($t4)
    MEM_W(0X160, ctx->r12) = ctx->f0.u32l;
    // 0x800AB294: lw          $t5, -0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X34);
    // 0x800AB298: swc1        $f0, 0x164($t5)
    MEM_W(0X164, ctx->r13) = ctx->f0.u32l;
    // 0x800AB29C: lw          $t6, -0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X34);
    // 0x800AB2A0: swc1        $f0, 0x168($t6)
    MEM_W(0X168, ctx->r14) = ctx->f0.u32l;
    // 0x800AB2A4: lw          $t7, -0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X34);
    // 0x800AB2A8: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
L_800AB2AC:
    // 0x800AB2AC: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
L_800AB2B0:
    // 0x800AB2B0: beql        $v0, $zero, L_800AB2C4
    if (ctx->r2 == 0) {
        // 0x800AB2B4: lw          $a0, 0x38($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X38);
            goto L_800AB2C4;
    }
    goto skip_11;
    // 0x800AB2B4: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    skip_11:
    // 0x800AB2B8: sw          $a3, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r7;
    // 0x800AB2BC: addiu       $a3, $a3, 0x80
    ctx->r7 = ADD32(ctx->r7, 0X80);
    // 0x800AB2C0: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
L_800AB2C4:
    // 0x800AB2C4: beql        $a0, $zero, L_800AB348
    if (ctx->r4 == 0) {
        // 0x800AB2C8: lw          $v0, 0x3C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X3C);
            goto L_800AB348;
    }
    goto skip_12;
    // 0x800AB2C8: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    skip_12:
    // 0x800AB2CC: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x800AB2D0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800AB2D4: beq         $t1, $zero, L_800AB344
    if (ctx->r9 == 0) {
        // 0x800AB2D8: andi        $a1, $t1, 0x3
        ctx->r5 = ctx->r9 & 0X3;
            goto L_800AB344;
    }
    // 0x800AB2D8: andi        $a1, $t1, 0x3
    ctx->r5 = ctx->r9 & 0X3;
    // 0x800AB2DC: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800AB2E0: beq         $a1, $zero, L_800AB308
    if (ctx->r5 == 0) {
        // 0x800AB2E4: addu        $v1, $a1, $t1
        ctx->r3 = ADD32(ctx->r5, ctx->r9);
            goto L_800AB308;
    }
    // 0x800AB2E4: addu        $v1, $a1, $t1
    ctx->r3 = ADD32(ctx->r5, ctx->r9);
L_800AB2E8:
    // 0x800AB2E8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AB2EC: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AB2F0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AB2F4: sw          $a3, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r7;
    // 0x800AB2F8: bne         $v1, $t1, L_800AB2E8
    if (ctx->r3 != ctx->r9) {
        // 0x800AB2FC: addiu       $a3, $a3, 0x20
        ctx->r7 = ADD32(ctx->r7, 0X20);
            goto L_800AB2E8;
    }
    // 0x800AB2FC: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800AB300: beql        $t1, $zero, L_800AB348
    if (ctx->r9 == 0) {
        // 0x800AB304: lw          $v0, 0x3C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X3C);
            goto L_800AB348;
    }
    goto skip_13;
    // 0x800AB304: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    skip_13:
L_800AB308:
    // 0x800AB308: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800AB30C: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800AB310: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800AB314: sw          $a3, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r7;
    // 0x800AB318: lw          $t4, -0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, -0XC);
    // 0x800AB31C: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800AB320: sw          $a3, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r7;
    // 0x800AB324: lw          $t5, -0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X8);
    // 0x800AB328: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800AB32C: sw          $a3, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r7;
    // 0x800AB330: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800AB334: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800AB338: sw          $a3, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r7;
    // 0x800AB33C: bne         $t1, $zero, L_800AB308
    if (ctx->r9 != 0) {
        // 0x800AB340: addiu       $a3, $a3, 0x20
        ctx->r7 = ADD32(ctx->r7, 0X20);
            goto L_800AB308;
    }
    // 0x800AB340: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
L_800AB344:
    // 0x800AB344: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
L_800AB348:
    // 0x800AB348: beql        $v0, $zero, L_800AB4B8
    if (ctx->r2 == 0) {
        // 0x800AB34C: lw          $a0, 0x2C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X2C);
            goto L_800AB4B8;
    }
    goto skip_14;
    // 0x800AB34C: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    skip_14:
    // 0x800AB350: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
    // 0x800AB354: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800AB358: beql        $t1, $zero, L_800AB4B8
    if (ctx->r9 == 0) {
        // 0x800AB35C: lw          $a0, 0x2C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X2C);
            goto L_800AB4B8;
    }
    goto skip_15;
    // 0x800AB35C: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    skip_15:
L_800AB360:
    // 0x800AB360: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800AB364: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AB368: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800AB36C: lw          $t7, 0x28($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X28);
    // 0x800AB370: beql        $t7, $zero, L_800AB484
    if (ctx->r15 == 0) {
        // 0x800AB374: lw          $t8, 0x8($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X8);
            goto L_800AB484;
    }
    goto skip_16;
    // 0x800AB374: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    skip_16:
    // 0x800AB378: lw          $a1, 0x24($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X24);
    // 0x800AB37C: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    // 0x800AB380: and         $v1, $a3, $at
    ctx->r3 = ctx->r7 & ctx->r1;
    // 0x800AB384: sw          $v1, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r3;
    // 0x800AB388: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800AB38C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800AB390: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800AB394: beq         $a1, $zero, L_800AB478
    if (ctx->r5 == 0) {
        // 0x800AB398: lw          $v0, 0x20($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X20);
            goto L_800AB478;
    }
    // 0x800AB398: lw          $v0, 0x20($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X20);
    // 0x800AB39C: andi        $t0, $a1, 0x3
    ctx->r8 = ctx->r5 & 0X3;
    // 0x800AB3A0: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x800AB3A4: beq         $t0, $zero, L_800AB3E4
    if (ctx->r8 == 0) {
        // 0x800AB3A8: addu        $a2, $t0, $a1
        ctx->r6 = ADD32(ctx->r8, ctx->r5);
            goto L_800AB3E4;
    }
    // 0x800AB3A8: addu        $a2, $t0, $a1
    ctx->r6 = ADD32(ctx->r8, ctx->r5);
L_800AB3AC:
    // 0x800AB3AC: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x800AB3B0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800AB3B4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800AB3B8: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x800AB3BC: lw          $t4, -0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, -0XC);
    // 0x800AB3C0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800AB3C4: sw          $t4, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r12;
    // 0x800AB3C8: lw          $at, -0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X8);
    // 0x800AB3CC: sw          $at, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r1;
    // 0x800AB3D0: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800AB3D4: bne         $a2, $a0, L_800AB3AC
    if (ctx->r6 != ctx->r4) {
        // 0x800AB3D8: sw          $t4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r12;
            goto L_800AB3AC;
    }
    // 0x800AB3D8: sw          $t4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r12;
    // 0x800AB3DC: beql        $a0, $zero, L_800AB478
    if (ctx->r4 == 0) {
        // 0x800AB3E0: lw          $a2, 0x0($t2)
        ctx->r6 = MEM_W(ctx->r10, 0X0);
            goto L_800AB478;
    }
    goto skip_17;
    // 0x800AB3E0: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    skip_17:
L_800AB3E4:
    // 0x800AB3E4: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x800AB3E8: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800AB3EC: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800AB3F0: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x800AB3F4: lw          $t6, -0x3C($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X3C);
    // 0x800AB3F8: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800AB3FC: sw          $t6, -0x3C($v1)
    MEM_W(-0X3C, ctx->r3) = ctx->r14;
    // 0x800AB400: lw          $at, -0x38($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X38);
    // 0x800AB404: sw          $at, -0x38($v1)
    MEM_W(-0X38, ctx->r3) = ctx->r1;
    // 0x800AB408: lw          $t6, -0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X34);
    // 0x800AB40C: sw          $t6, -0x34($v1)
    MEM_W(-0X34, ctx->r3) = ctx->r14;
    // 0x800AB410: lw          $at, -0x30($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X30);
    // 0x800AB414: sw          $at, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = ctx->r1;
    // 0x800AB418: lw          $t8, -0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X2C);
    // 0x800AB41C: sw          $t8, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->r24;
    // 0x800AB420: lw          $at, -0x28($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X28);
    // 0x800AB424: sw          $at, -0x28($v1)
    MEM_W(-0X28, ctx->r3) = ctx->r1;
    // 0x800AB428: lw          $t8, -0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X24);
    // 0x800AB42C: sw          $t8, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = ctx->r24;
    // 0x800AB430: lw          $at, -0x20($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X20);
    // 0x800AB434: sw          $at, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->r1;
    // 0x800AB438: lw          $t4, -0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X1C);
    // 0x800AB43C: sw          $t4, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->r12;
    // 0x800AB440: lw          $at, -0x18($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X18);
    // 0x800AB444: sw          $at, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r1;
    // 0x800AB448: lw          $t4, -0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X14);
    // 0x800AB44C: sw          $t4, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->r12;
    // 0x800AB450: lw          $at, -0x10($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X10);
    // 0x800AB454: sw          $at, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r1;
    // 0x800AB458: lw          $t6, -0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, -0XC);
    // 0x800AB45C: sw          $t6, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r14;
    // 0x800AB460: lw          $at, -0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X8);
    // 0x800AB464: sw          $at, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r1;
    // 0x800AB468: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800AB46C: bne         $a0, $zero, L_800AB3E4
    if (ctx->r4 != 0) {
        // 0x800AB470: sw          $t6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r14;
            goto L_800AB3E4;
    }
    // 0x800AB470: sw          $t6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r14;
    // 0x800AB474: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
L_800AB478:
    // 0x800AB478: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x800AB47C: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800AB480: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
L_800AB484:
    // 0x800AB484: beql        $t8, $zero, L_800AB49C
    if (ctx->r24 == 0) {
        // 0x800AB488: lw          $t9, 0xC($a2)
        ctx->r25 = MEM_W(ctx->r6, 0XC);
            goto L_800AB49C;
    }
    goto skip_18;
    // 0x800AB488: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    skip_18:
    // 0x800AB48C: sw          $a3, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r7;
    // 0x800AB490: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800AB494: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x800AB498: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
L_800AB49C:
    // 0x800AB49C: beq         $t9, $zero, L_800AB4AC
    if (ctx->r25 == 0) {
        // 0x800AB4A0: nop
    
            goto L_800AB4AC;
    }
    // 0x800AB4A0: nop

    // 0x800AB4A4: sw          $a3, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r7;
    // 0x800AB4A8: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
L_800AB4AC:
    // 0x800AB4AC: bne         $t1, $zero, L_800AB360
    if (ctx->r9 != 0) {
        // 0x800AB4B0: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_800AB360;
    }
    // 0x800AB4B0: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800AB4B4: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
L_800AB4B8:
    // 0x800AB4B8: beql        $a0, $zero, L_800AB5D0
    if (ctx->r4 == 0) {
        // 0x800AB4BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800AB5D0;
    }
    goto skip_19;
    // 0x800AB4BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_19:
    // 0x800AB4C0: jal         0x800ABD64
    // 0x800AB4C4: nop

    func_800ABD64(rdram, ctx);
        goto after_5;
    // 0x800AB4C4: nop

    after_5:
    // 0x800AB4C8: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x800AB4CC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800AB4D0: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x800AB4D4: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x800AB4D8: beq         $t1, $zero, L_800AB5CC
    if (ctx->r9 == 0) {
        // 0x800AB4DC: andi        $a1, $t1, 0x3
        ctx->r5 = ctx->r9 & 0X3;
            goto L_800AB5CC;
    }
    // 0x800AB4DC: andi        $a1, $t1, 0x3
    ctx->r5 = ctx->r9 & 0X3;
    // 0x800AB4E0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800AB4E4: beq         $a1, $zero, L_800AB524
    if (ctx->r5 == 0) {
        // 0x800AB4E8: addu        $a0, $a1, $t1
        ctx->r4 = ADD32(ctx->r5, ctx->r9);
            goto L_800AB524;
    }
    // 0x800AB4E8: addu        $a0, $a1, $t1
    ctx->r4 = ADD32(ctx->r5, ctx->r9);
L_800AB4EC:
    // 0x800AB4EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AB4F0: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800AB4F4: bnel        $t3, $v0, L_800AB508
    if (ctx->r11 != ctx->r2) {
        // 0x800AB4F8: lw          $t4, 0x28($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X28);
            goto L_800AB508;
    }
    goto skip_20;
    // 0x800AB4F8: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    skip_20:
    // 0x800AB4FC: b           L_800AB514
    // 0x800AB500: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800AB514;
    // 0x800AB500: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB504: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
L_800AB508:
    // 0x800AB508: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x800AB50C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AB510: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800AB514:
    // 0x800AB514: bne         $a0, $t1, L_800AB4EC
    if (ctx->r4 != ctx->r9) {
        // 0x800AB518: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800AB4EC;
    }
    // 0x800AB518: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800AB51C: beql        $t1, $zero, L_800AB5D0
    if (ctx->r9 == 0) {
        // 0x800AB520: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800AB5D0;
    }
    goto skip_21;
    // 0x800AB520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_21:
L_800AB524:
    // 0x800AB524: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AB528: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800AB52C: bnel        $t3, $v0, L_800AB540
    if (ctx->r11 != ctx->r2) {
        // 0x800AB530: lw          $t7, 0x28($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X28);
            goto L_800AB540;
    }
    goto skip_22;
    // 0x800AB530: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    skip_22:
    // 0x800AB534: b           L_800AB54C
    // 0x800AB538: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800AB54C;
    // 0x800AB538: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB53C: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
L_800AB540:
    // 0x800AB540: sll         $t8, $v0, 6
    ctx->r24 = S32(ctx->r2 << 6);
    // 0x800AB544: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AB548: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800AB54C:
    // 0x800AB54C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800AB550: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800AB554: bnel        $t3, $v0, L_800AB568
    if (ctx->r11 != ctx->r2) {
        // 0x800AB558: lw          $t4, 0x28($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X28);
            goto L_800AB568;
    }
    goto skip_23;
    // 0x800AB558: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    skip_23:
    // 0x800AB55C: b           L_800AB574
    // 0x800AB560: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800AB574;
    // 0x800AB560: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB564: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
L_800AB568:
    // 0x800AB568: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x800AB56C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AB570: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800AB574:
    // 0x800AB574: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800AB578: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800AB57C: bnel        $t3, $v0, L_800AB590
    if (ctx->r11 != ctx->r2) {
        // 0x800AB580: lw          $t7, 0x28($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X28);
            goto L_800AB590;
    }
    goto skip_24;
    // 0x800AB580: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    skip_24:
    // 0x800AB584: b           L_800AB59C
    // 0x800AB588: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800AB59C;
    // 0x800AB588: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB58C: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
L_800AB590:
    // 0x800AB590: sll         $t8, $v0, 6
    ctx->r24 = S32(ctx->r2 << 6);
    // 0x800AB594: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AB598: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800AB59C:
    // 0x800AB59C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800AB5A0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800AB5A4: bnel        $t3, $v0, L_800AB5B8
    if (ctx->r11 != ctx->r2) {
        // 0x800AB5A8: lw          $t4, 0x28($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X28);
            goto L_800AB5B8;
    }
    goto skip_25;
    // 0x800AB5A8: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    skip_25:
    // 0x800AB5AC: b           L_800AB5C4
    // 0x800AB5B0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800AB5C4;
    // 0x800AB5B0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB5B4: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
L_800AB5B8:
    // 0x800AB5B8: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x800AB5BC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AB5C0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800AB5C4:
    // 0x800AB5C4: bne         $t1, $zero, L_800AB524
    if (ctx->r9 != 0) {
        // 0x800AB5C8: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800AB524;
    }
    // 0x800AB5C8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800AB5CC:
    // 0x800AB5CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AB5D0:
    // 0x800AB5D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AB5D4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800AB5D8: jr          $ra
    // 0x800AB5DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AB5DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AB5E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB5E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AB5E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AB5E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AB5EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AB5F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AB5F4: lw          $a1, 0x34($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X34);
    // 0x800AB5F8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800AB5FC: beql        $a1, $zero, L_800AB610
    if (ctx->r5 == 0) {
        // 0x800AB600: lw          $v0, 0x38($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X38);
            goto L_800AB610;
    }
    goto skip_0;
    // 0x800AB600: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    skip_0:
    // 0x800AB604: jal         0x800AA940
    // 0x800AB608: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA940(rdram, ctx);
        goto after_0;
    // 0x800AB608: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800AB60C: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
L_800AB610:
    // 0x800AB610: beql        $v0, $zero, L_800AB640
    if (ctx->r2 == 0) {
        // 0x800AB614: lw          $v0, 0x3C($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X3C);
            goto L_800AB640;
    }
    goto skip_1;
    // 0x800AB614: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
    skip_1:
    // 0x800AB618: lw          $s0, 0x14($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X14);
    // 0x800AB61C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800AB620: beql        $s0, $zero, L_800AB640
    if (ctx->r16 == 0) {
        // 0x800AB624: lw          $v0, 0x3C($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X3C);
            goto L_800AB640;
    }
    goto skip_2;
    // 0x800AB624: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
    skip_2:
L_800AB628:
    // 0x800AB628: jal         0x800AA8DC
    // 0x800AB62C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800AA8DC(rdram, ctx);
        goto after_1;
    // 0x800AB62C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x800AB630: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800AB634: bne         $s0, $zero, L_800AB628
    if (ctx->r16 != 0) {
        // 0x800AB638: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800AB628;
    }
    // 0x800AB638: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800AB63C: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
L_800AB640:
    // 0x800AB640: beql        $v0, $zero, L_800AB670
    if (ctx->r2 == 0) {
        // 0x800AB644: lw          $v0, 0x40($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X40);
            goto L_800AB670;
    }
    goto skip_3;
    // 0x800AB644: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
    skip_3:
    // 0x800AB648: lw          $s0, 0x18($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X18);
    // 0x800AB64C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800AB650: beql        $s0, $zero, L_800AB670
    if (ctx->r16 == 0) {
        // 0x800AB654: lw          $v0, 0x40($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X40);
            goto L_800AB670;
    }
    goto skip_4;
    // 0x800AB654: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
    skip_4:
L_800AB658:
    // 0x800AB658: jal         0x800AA874
    // 0x800AB65C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800AA874(rdram, ctx);
        goto after_2;
    // 0x800AB65C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x800AB660: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800AB664: bne         $s0, $zero, L_800AB658
    if (ctx->r16 != 0) {
        // 0x800AB668: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800AB658;
    }
    // 0x800AB668: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800AB66C: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
L_800AB670:
    // 0x800AB670: beql        $v0, $zero, L_800AB6A0
    if (ctx->r2 == 0) {
        // 0x800AB674: lw          $a0, 0x0($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X0);
            goto L_800AB6A0;
    }
    goto skip_5;
    // 0x800AB674: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    skip_5:
    // 0x800AB678: lw          $s0, 0x1C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X1C);
    // 0x800AB67C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800AB680: beql        $s0, $zero, L_800AB6A0
    if (ctx->r16 == 0) {
        // 0x800AB684: lw          $a0, 0x0($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X0);
            goto L_800AB6A0;
    }
    goto skip_6;
    // 0x800AB684: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    skip_6:
L_800AB688:
    // 0x800AB688: jal         0x800AA638
    // 0x800AB68C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800AA638(rdram, ctx);
        goto after_3;
    // 0x800AB68C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x800AB690: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800AB694: bne         $s0, $zero, L_800AB688
    if (ctx->r16 != 0) {
        // 0x800AB698: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800AB688;
    }
    // 0x800AB698: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800AB69C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_800AB6A0:
    // 0x800AB6A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AB6A4: bne         $a0, $at, L_800AB6C4
    if (ctx->r4 != ctx->r1) {
        // 0x800AB6A8: nop
    
            goto L_800AB6C4;
    }
    // 0x800AB6A8: nop

    // 0x800AB6AC: jal         0x8007E328
    // 0x800AB6B0: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    n64HeapUnalloc(rdram, ctx);
        goto after_4;
    // 0x800AB6B0: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    after_4:
    // 0x800AB6B4: jal         0x8007E328
    // 0x800AB6B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_5;
    // 0x800AB6B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x800AB6BC: b           L_800AB6EC
    // 0x800AB6C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800AB6EC;
    // 0x800AB6C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800AB6C4:
    // 0x800AB6C4: jal         0x800AA3DC
    // 0x800AB6C8: nop

    func_800AA3DC(rdram, ctx);
        goto after_6;
    // 0x800AB6C8: nop

    after_6:
    // 0x800AB6CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AB6D0: bne         $v0, $at, L_800AB6E0
    if (ctx->r2 != ctx->r1) {
        // 0x800AB6D4: nop
    
            goto L_800AB6E0;
    }
    // 0x800AB6D4: nop

    // 0x800AB6D8: jal         0x8007E328
    // 0x800AB6DC: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    n64HeapUnalloc(rdram, ctx);
        goto after_7;
    // 0x800AB6DC: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    after_7:
L_800AB6E0:
    // 0x800AB6E0: jal         0x800AA3F4
    // 0x800AB6E4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    func_800AA3F4(rdram, ctx);
        goto after_8;
    // 0x800AB6E4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_8:
    // 0x800AB6E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800AB6EC:
    // 0x800AB6EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AB6F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AB6F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AB6F8: jr          $ra
    // 0x800AB6FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AB6FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800AB700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB700: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x800AB704: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x800AB708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AB70C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800AB710: addiu       $v1, $t7, 0x20
    ctx->r3 = ADD32(ctx->r15, 0X20);
    // 0x800AB714: blez        $v0, L_800AB78C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AB718: sw          $v1, 0x28($a0)
        MEM_W(0X28, ctx->r4) = ctx->r3;
            goto L_800AB78C;
    }
    // 0x800AB718: sw          $v1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r3;
L_800AB71C:
    // 0x800AB71C: lw          $t9, 0x1C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1C);
    // 0x800AB720: lw          $a2, 0x18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X18);
    // 0x800AB724: sw          $a0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r4;
    // 0x800AB728: addu        $t2, $t9, $a0
    ctx->r10 = ADD32(ctx->r25, ctx->r4);
    // 0x800AB72C: addiu       $a3, $t2, 0x20
    ctx->r7 = ADD32(ctx->r10, 0X20);
    // 0x800AB730: sw          $a3, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r7;
    // 0x800AB734: blez        $a2, L_800AB780
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800AB738: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800AB780;
    }
    // 0x800AB738: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800AB73C:
    // 0x800AB73C: lw          $t4, 0xC($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC);
    // 0x800AB740: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800AB744: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x800AB748: addiu       $t1, $t5, 0x20
    ctx->r9 = ADD32(ctx->r13, 0X20);
    // 0x800AB74C: sw          $t1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r9;
L_800AB750:
    // 0x800AB750: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x800AB754: lh          $t3, 0x0($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X0);
    // 0x800AB758: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800AB75C: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x800AB760: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800AB764: lh          $t2, 0x4($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X4);
    // 0x800AB768: beq         $t2, $t3, L_800AB778
    if (ctx->r10 == ctx->r11) {
        // 0x800AB76C: nop
    
            goto L_800AB778;
    }
    // 0x800AB76C: nop

    // 0x800AB770: b           L_800AB750
    // 0x800AB774: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800AB750;
    // 0x800AB774: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800AB778:
    // 0x800AB778: bne         $t0, $a2, L_800AB73C
    if (ctx->r8 != ctx->r6) {
        // 0x800AB77C: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_800AB73C;
    }
    // 0x800AB77C: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
L_800AB780:
    // 0x800AB780: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800AB784: bne         $a1, $v0, L_800AB71C
    if (ctx->r5 != ctx->r2) {
        // 0x800AB788: addiu       $v1, $v1, 0x24
        ctx->r3 = ADD32(ctx->r3, 0X24);
            goto L_800AB71C;
    }
    // 0x800AB788: addiu       $v1, $v1, 0x24
    ctx->r3 = ADD32(ctx->r3, 0X24);
L_800AB78C:
    // 0x800AB78C: jr          $ra
    // 0x800AB790: nop

    return;
    // 0x800AB790: nop

;}

RECOMP_FUNC void func_800AB794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB794: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AB798: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AB79C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AB7A0: lw          $t4, 0x24($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X24);
    // 0x800AB7A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AB7A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AB7AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AB7B0: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800AB7B4: lw          $t2, 0x28($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X28);
    // 0x800AB7B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AB7BC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800AB7C0: blez        $t4, L_800AB828
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800AB7C4: swc1        $f4, 0x18($a0)
        MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
            goto L_800AB828;
    }
    // 0x800AB7C4: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x800AB7C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800AB7CC:
    // 0x800AB7CC: lw          $a0, 0x18($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X18);
    // 0x800AB7D0: sw          $s0, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r16;
    // 0x800AB7D4: lw          $a3, 0x1C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X1C);
    // 0x800AB7D8: blez        $a0, L_800AB814
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800AB7DC: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800AB814;
    }
    // 0x800AB7DC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800AB7E0:
    // 0x800AB7E0: lw          $v0, 0xC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC);
    // 0x800AB7E4: sh          $t1, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r9;
    // 0x800AB7E8: lh          $v1, 0x4($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X4);
    // 0x800AB7EC: sw          $v0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r2;
L_800AB7F0:
    // 0x800AB7F0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800AB7F4: beql        $v1, $t6, L_800AB808
    if (ctx->r3 == ctx->r14) {
        // 0x800AB7F8: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800AB808;
    }
    goto skip_0;
    // 0x800AB7F8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x800AB7FC: b           L_800AB7F0
    // 0x800AB800: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800AB7F0;
    // 0x800AB800: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800AB804: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800AB808:
    // 0x800AB808: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x800AB80C: bne         $t0, $a0, L_800AB7E0
    if (ctx->r8 != ctx->r4) {
        // 0x800AB810: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800AB7E0;
    }
    // 0x800AB810: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
L_800AB814:
    // 0x800AB814: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800AB818: addiu       $t2, $t2, 0x24
    ctx->r10 = ADD32(ctx->r10, 0X24);
    // 0x800AB81C: sw          $zero, -0x20($t2)
    MEM_W(-0X20, ctx->r10) = 0;
    // 0x800AB820: bne         $t3, $t4, L_800AB7CC
    if (ctx->r11 != ctx->r12) {
        // 0x800AB824: sw          $zero, -0x1C($t2)
        MEM_W(-0X1C, ctx->r10) = 0;
            goto L_800AB7CC;
    }
    // 0x800AB824: sw          $zero, -0x1C($t2)
    MEM_W(-0X1C, ctx->r10) = 0;
L_800AB828:
    // 0x800AB828: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800AB82C: jal         0x8007E03C
    // 0x800AB830: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800AB830: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_0:
    // 0x800AB834: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800AB838: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800AB83C: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x800AB840: beql        $t3, $zero, L_800AB91C
    if (ctx->r11 == 0) {
        // 0x800AB844: sw          $zero, 0x8($s0)
        MEM_W(0X8, ctx->r16) = 0;
            goto L_800AB91C;
    }
    goto skip_1;
    // 0x800AB844: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    skip_1:
    // 0x800AB848: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AB84C: nop

L_800AB850:
    // 0x800AB850: lw          $t0, 0x18($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X18);
    // 0x800AB854: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x800AB858: lw          $a3, 0x1C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X1C);
    // 0x800AB85C: beq         $t0, $zero, L_800AB910
    if (ctx->r8 == 0) {
        // 0x800AB860: nop
    
            goto L_800AB910;
    }
    // 0x800AB860: nop

L_800AB864:
    // 0x800AB864: lw          $a2, 0xC($a3)
    ctx->r6 = MEM_W(ctx->r7, 0XC);
    // 0x800AB868: sw          $a1, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r5;
    // 0x800AB86C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800AB870: lh          $v1, 0x2($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X2);
    // 0x800AB874: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x800AB878: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800AB87C: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x800AB880: beq         $t7, $zero, L_800AB898
    if (ctx->r15 == 0) {
        // 0x800AB884: sra         $t8, $v1, 1
        ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800AB898;
    }
    // 0x800AB884: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800AB888: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AB88C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AB890: b           L_800AB89C
    // 0x800AB894: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_800AB89C;
    // 0x800AB894: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_800AB898:
    // 0x800AB898: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_800AB89C:
    // 0x800AB89C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800AB8A0: beq         $t9, $zero, L_800AB8B8
    if (ctx->r25 == 0) {
        // 0x800AB8A4: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800AB8B8;
    }
    // 0x800AB8A4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800AB8A8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AB8AC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AB8B0: b           L_800AB8BC
    // 0x800AB8B4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
        goto L_800AB8BC;
    // 0x800AB8B4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_800AB8B8:
    // 0x800AB8B8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800AB8BC:
    // 0x800AB8BC: sra         $t5, $v1, 1
    ctx->r13 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800AB8C0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800AB8C4: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800AB8C8: beq         $t6, $zero, L_800AB8E0
    if (ctx->r14 == 0) {
        // 0x800AB8CC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800AB8E0;
    }
    // 0x800AB8CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AB8D0: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AB8D4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AB8D8: b           L_800AB8E4
    // 0x800AB8DC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_800AB8E4;
    // 0x800AB8DC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_800AB8E0:
    // 0x800AB8E0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800AB8E4:
    // 0x800AB8E4: sra         $t7, $v1, 1
    ctx->r15 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800AB8E8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800AB8EC: beq         $t8, $zero, L_800AB900
    if (ctx->r24 == 0) {
        // 0x800AB8F0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800AB900;
    }
    // 0x800AB8F0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AB8F4: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AB8F8: b           L_800AB904
    // 0x800AB8FC: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
        goto L_800AB904;
    // 0x800AB8FC: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_800AB900:
    // 0x800AB900: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800AB904:
    // 0x800AB904: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x800AB908: bne         $t0, $zero, L_800AB864
    if (ctx->r8 != 0) {
        // 0x800AB90C: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800AB864;
    }
    // 0x800AB90C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
L_800AB910:
    // 0x800AB910: bne         $t3, $zero, L_800AB850
    if (ctx->r11 != 0) {
        // 0x800AB914: addiu       $t2, $t2, 0x24
        ctx->r10 = ADD32(ctx->r10, 0X24);
            goto L_800AB850;
    }
    // 0x800AB914: addiu       $t2, $t2, 0x24
    ctx->r10 = ADD32(ctx->r10, 0X24);
    // 0x800AB918: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
L_800AB91C:
    // 0x800AB91C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800AB920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AB924: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AB928: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800AB92C: jr          $ra
    // 0x800AB930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AB930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}

RECOMP_FUNC void func_800AB934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB934: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AB938: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AB93C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AB940: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800AB944: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AB948: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AB94C: bne         $a1, $at, L_800AB974
    if (ctx->r5 != ctx->r1) {
        // 0x800AB950: nop
    
            goto L_800AB974;
    }
    // 0x800AB950: nop

    // 0x800AB954: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x800AB958: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x800AB95C: jal         0x8007E328
    // 0x800AB960: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x800AB960: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    after_0:
    // 0x800AB964: jal         0x8007E328
    // 0x800AB968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x800AB968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800AB96C: b           L_800AB9A4
    // 0x800AB970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800AB9A4;
    // 0x800AB970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AB974:
    // 0x800AB974: jal         0x800AA3DC
    // 0x800AB978: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800AA3DC(rdram, ctx);
        goto after_2;
    // 0x800AB978: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800AB97C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AB980: bne         $v0, $at, L_800AB998
    if (ctx->r2 != ctx->r1) {
        // 0x800AB984: nop
    
            goto L_800AB998;
    }
    // 0x800AB984: nop

    // 0x800AB988: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x800AB98C: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x800AB990: jal         0x8007E328
    // 0x800AB994: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    n64HeapUnalloc(rdram, ctx);
        goto after_3;
    // 0x800AB994: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    after_3:
L_800AB998:
    // 0x800AB998: jal         0x800AA3F4
    // 0x800AB99C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800AA3F4(rdram, ctx);
        goto after_4;
    // 0x800AB99C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x800AB9A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AB9A4:
    // 0x800AB9A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AB9A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AB9AC: jr          $ra
    // 0x800AB9B0: nop

    return;
    // 0x800AB9B0: nop

;}

RECOMP_FUNC void func_800AB9B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB9B4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800AB9B8: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800AB9BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AB9C0: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800AB9C4: beq         $t8, $zero, L_800AB9D8
    if (ctx->r24 == 0) {
        // 0x800AB9C8: sw          $t7, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r15;
            goto L_800AB9D8;
    }
    // 0x800AB9C8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800AB9CC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800AB9D0: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x800AB9D4: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
L_800AB9D8:
    // 0x800AB9D8: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800AB9DC: beql        $t1, $zero, L_800AB9F4
    if (ctx->r9 == 0) {
        // 0x800AB9E0: lh          $v0, 0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X2);
            goto L_800AB9F4;
    }
    goto skip_0;
    // 0x800AB9E0: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    skip_0:
    // 0x800AB9E4: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x800AB9E8: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x800AB9EC: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    // 0x800AB9F0: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
L_800AB9F4:
    // 0x800AB9F4: beql        $v0, $zero, L_800ABA10
    if (ctx->r2 == 0) {
        // 0x800AB9F8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800ABA10;
    }
    goto skip_1;
    // 0x800AB9F8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x800AB9FC: beql        $v0, $at, L_800ABA30
    if (ctx->r2 == ctx->r1) {
        // 0x800ABA00: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800ABA30;
    }
    goto skip_2;
    // 0x800ABA00: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_2:
    // 0x800ABA04: jr          $ra
    // 0x800ABA08: nop

    return;
    // 0x800ABA08: nop

    // 0x800ABA0C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800ABA10:
    // 0x800ABA10: lw          $t4, 0x10($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X10);
    // 0x800ABA14: beq         $t4, $zero, L_800ABAB0
    if (ctx->r12 == 0) {
        // 0x800ABA18: nop
    
            goto L_800ABAB0;
    }
    // 0x800ABA18: nop

    // 0x800ABA1C: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x800ABA20: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800ABA24: jr          $ra
    // 0x800ABA28: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    return;
    // 0x800ABA28: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    // 0x800ABA2C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800ABA30:
    // 0x800ABA30: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800ABA34: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800ABA38: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800ABA3C: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800ABA40: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800ABA44: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x800ABA48: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x800ABA4C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800ABA50: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800ABA54: beq         $t3, $zero, L_800ABA68
    if (ctx->r11 == 0) {
        // 0x800ABA58: sw          $t2, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r10;
            goto L_800ABA68;
    }
    // 0x800ABA58: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x800ABA5C: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800ABA60: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800ABA64: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
L_800ABA68:
    // 0x800ABA68: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800ABA6C: beql        $t6, $zero, L_800ABA84
    if (ctx->r14 == 0) {
        // 0x800ABA70: lw          $t9, 0x14($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X14);
            goto L_800ABA84;
    }
    goto skip_3;
    // 0x800ABA70: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    skip_3:
    // 0x800ABA74: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x800ABA78: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800ABA7C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x800ABA80: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
L_800ABA84:
    // 0x800ABA84: beql        $t9, $zero, L_800ABA9C
    if (ctx->r25 == 0) {
        // 0x800ABA88: lw          $t2, 0x24($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X24);
            goto L_800ABA9C;
    }
    goto skip_4;
    // 0x800ABA88: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    skip_4:
    // 0x800ABA8C: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x800ABA90: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x800ABA94: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
    // 0x800ABA98: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
L_800ABA9C:
    // 0x800ABA9C: beq         $t2, $zero, L_800ABAB0
    if (ctx->r10 == 0) {
        // 0x800ABAA0: nop
    
            goto L_800ABAB0;
    }
    // 0x800ABAA0: nop

    // 0x800ABAA4: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x800ABAA8: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800ABAAC: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
L_800ABAB0:
    // 0x800ABAB0: jr          $ra
    // 0x800ABAB4: nop

    return;
    // 0x800ABAB4: nop

;}

RECOMP_FUNC void func_800ABAB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABAB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ABABC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ABAC0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ABAC4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ABAC8: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800ABACC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800ABAD0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800ABAD4: beql        $t6, $zero, L_800ABAEC
    if (ctx->r14 == 0) {
        // 0x800ABAD8: lw          $t9, 0x14($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X14);
            goto L_800ABAEC;
    }
    goto skip_0;
    // 0x800ABAD8: lw          $t9, 0x14($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X14);
    skip_0:
    // 0x800ABADC: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x800ABAE0: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800ABAE4: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x800ABAE8: lw          $t9, 0x14($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X14);
L_800ABAEC:
    // 0x800ABAEC: beq         $t9, $zero, L_800ABAF8
    if (ctx->r25 == 0) {
        // 0x800ABAF0: addu        $t1, $t9, $s1
        ctx->r9 = ADD32(ctx->r25, ctx->r17);
            goto L_800ABAF8;
    }
    // 0x800ABAF0: addu        $t1, $t9, $s1
    ctx->r9 = ADD32(ctx->r25, ctx->r17);
    // 0x800ABAF4: sw          $t1, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r9;
L_800ABAF8:
    // 0x800ABAF8: lw          $t2, 0x18($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X18);
    // 0x800ABAFC: beq         $t2, $zero, L_800ABB08
    if (ctx->r10 == 0) {
        // 0x800ABB00: addu        $t4, $t2, $s1
        ctx->r12 = ADD32(ctx->r10, ctx->r17);
            goto L_800ABB08;
    }
    // 0x800ABB00: addu        $t4, $t2, $s1
    ctx->r12 = ADD32(ctx->r10, ctx->r17);
    // 0x800ABB04: sw          $t4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r12;
L_800ABB08:
    // 0x800ABB08: lw          $t5, 0x1C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X1C);
    // 0x800ABB0C: beq         $t5, $zero, L_800ABB18
    if (ctx->r13 == 0) {
        // 0x800ABB10: addu        $t7, $t5, $s1
        ctx->r15 = ADD32(ctx->r13, ctx->r17);
            goto L_800ABB18;
    }
    // 0x800ABB10: addu        $t7, $t5, $s1
    ctx->r15 = ADD32(ctx->r13, ctx->r17);
    // 0x800ABB14: sw          $t7, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r15;
L_800ABB18:
    // 0x800ABB18: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x800ABB1C: lw          $v0, 0x14($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X14);
    // 0x800ABB20: beq         $v1, $zero, L_800ABB90
    if (ctx->r3 == 0) {
        // 0x800ABB24: andi        $a1, $v1, 0x3
        ctx->r5 = ctx->r3 & 0X3;
            goto L_800ABB90;
    }
    // 0x800ABB24: andi        $a1, $v1, 0x3
    ctx->r5 = ctx->r3 & 0X3;
    // 0x800ABB28: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800ABB2C: beq         $a1, $zero, L_800ABB54
    if (ctx->r5 == 0) {
        // 0x800ABB30: addu        $a0, $a1, $v1
        ctx->r4 = ADD32(ctx->r5, ctx->r3);
            goto L_800ABB54;
    }
    // 0x800ABB30: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_800ABB34:
    // 0x800ABB34: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800ABB38: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800ABB3C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800ABB40: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800ABB44: bne         $a0, $v1, L_800ABB34
    if (ctx->r4 != ctx->r3) {
        // 0x800ABB48: sw          $t9, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r25;
            goto L_800ABB34;
    }
    // 0x800ABB48: sw          $t9, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r25;
    // 0x800ABB4C: beql        $v1, $zero, L_800ABB94
    if (ctx->r3 == 0) {
        // 0x800ABB50: lw          $v1, 0x0($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X0);
            goto L_800ABB94;
    }
    goto skip_1;
    // 0x800ABB50: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    skip_1:
L_800ABB54:
    // 0x800ABB54: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800ABB58: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    // 0x800ABB5C: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x800ABB60: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800ABB64: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800ABB68: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x800ABB6C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x800ABB70: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800ABB74: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800ABB78: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x800ABB7C: sw          $t5, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r13;
    // 0x800ABB80: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800ABB84: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800ABB88: bne         $v1, $zero, L_800ABB54
    if (ctx->r3 != 0) {
        // 0x800ABB8C: sw          $t1, -0x1C($v0)
        MEM_W(-0X1C, ctx->r2) = ctx->r9;
            goto L_800ABB54;
    }
    // 0x800ABB8C: sw          $t1, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->r9;
L_800ABB90:
    // 0x800ABB90: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_800ABB94:
    // 0x800ABB94: lw          $s0, 0x10($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X10);
    // 0x800ABB98: beq         $v1, $zero, L_800ABBC8
    if (ctx->r3 == 0) {
        // 0x800ABB9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800ABBC8;
    }
    // 0x800ABB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800ABBA0:
    // 0x800ABBA0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800ABBA4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800ABBA8: jal         0x800AB9B4
    // 0x800ABBAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800AB9B4(rdram, ctx);
        goto after_0;
    // 0x800ABBAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800ABBB0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800ABBB4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800ABBB8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800ABBBC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800ABBC0: bnel        $v1, $zero, L_800ABBA0
    if (ctx->r3 != 0) {
        // 0x800ABBC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800ABBA0;
    }
    goto skip_2;
    // 0x800ABBC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_800ABBC8:
    // 0x800ABBC8: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800ABBCC: lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X18);
    // 0x800ABBD0: beq         $v1, $zero, L_800ABC88
    if (ctx->r3 == 0) {
        // 0x800ABBD4: andi        $a1, $v1, 0x3
        ctx->r5 = ctx->r3 & 0X3;
            goto L_800ABC88;
    }
    // 0x800ABBD4: andi        $a1, $v1, 0x3
    ctx->r5 = ctx->r3 & 0X3;
    // 0x800ABBD8: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800ABBDC: beq         $a1, $zero, L_800ABC10
    if (ctx->r5 == 0) {
        // 0x800ABBE0: addu        $a0, $a1, $v1
        ctx->r4 = ADD32(ctx->r5, ctx->r3);
            goto L_800ABC10;
    }
    // 0x800ABBE0: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_800ABBE4:
    // 0x800ABBE4: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x800ABBE8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800ABBEC: beq         $t8, $zero, L_800ABC00
    if (ctx->r24 == 0) {
        // 0x800ABBF0: nop
    
            goto L_800ABC00;
    }
    // 0x800ABBF0: nop

    // 0x800ABBF4: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x800ABBF8: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x800ABBFC: sw          $t0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r8;
L_800ABC00:
    // 0x800ABC00: bne         $a0, $v1, L_800ABBE4
    if (ctx->r4 != ctx->r3) {
        // 0x800ABC04: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_800ABBE4;
    }
    // 0x800ABC04: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800ABC08: beql        $v1, $zero, L_800ABC8C
    if (ctx->r3 == 0) {
        // 0x800ABC0C: lw          $v1, 0xC($a2)
        ctx->r3 = MEM_W(ctx->r6, 0XC);
            goto L_800ABC8C;
    }
    goto skip_3;
    // 0x800ABC0C: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
    skip_3:
L_800ABC10:
    // 0x800ABC10: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x800ABC14: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800ABC18: beql        $t1, $zero, L_800ABC30
    if (ctx->r9 == 0) {
        // 0x800ABC1C: lw          $t4, 0x28($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X28);
            goto L_800ABC30;
    }
    goto skip_4;
    // 0x800ABC1C: lw          $t4, 0x28($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X28);
    skip_4:
    // 0x800ABC20: lw          $t2, 0x14($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14);
    // 0x800ABC24: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x800ABC28: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x800ABC2C: lw          $t4, 0x28($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X28);
L_800ABC30:
    // 0x800ABC30: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800ABC34: beql        $t4, $zero, L_800ABC4C
    if (ctx->r12 == 0) {
        // 0x800ABC38: lw          $t7, 0x28($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X28);
            goto L_800ABC4C;
    }
    goto skip_5;
    // 0x800ABC38: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    skip_5:
    // 0x800ABC3C: lw          $t5, 0x14($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X14);
    // 0x800ABC40: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800ABC44: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x800ABC48: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
L_800ABC4C:
    // 0x800ABC4C: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800ABC50: beql        $t7, $zero, L_800ABC68
    if (ctx->r15 == 0) {
        // 0x800ABC54: lw          $t0, 0x28($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X28);
            goto L_800ABC68;
    }
    goto skip_6;
    // 0x800ABC54: lw          $t0, 0x28($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X28);
    skip_6:
    // 0x800ABC58: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x800ABC5C: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800ABC60: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x800ABC64: lw          $t0, 0x28($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X28);
L_800ABC68:
    // 0x800ABC68: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800ABC6C: beq         $t0, $zero, L_800ABC80
    if (ctx->r8 == 0) {
        // 0x800ABC70: nop
    
            goto L_800ABC80;
    }
    // 0x800ABC70: nop

    // 0x800ABC74: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x800ABC78: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x800ABC7C: sw          $t2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r10;
L_800ABC80:
    // 0x800ABC80: bne         $v1, $zero, L_800ABC10
    if (ctx->r3 != 0) {
        // 0x800ABC84: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_800ABC10;
    }
    // 0x800ABC84: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
L_800ABC88:
    // 0x800ABC88: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
L_800ABC8C:
    // 0x800ABC8C: lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C);
    // 0x800ABC90: beq         $v1, $zero, L_800ABD50
    if (ctx->r3 == 0) {
        // 0x800ABC94: andi        $a1, $v1, 0x3
        ctx->r5 = ctx->r3 & 0X3;
            goto L_800ABD50;
    }
    // 0x800ABC94: andi        $a1, $v1, 0x3
    ctx->r5 = ctx->r3 & 0X3;
    // 0x800ABC98: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800ABC9C: beq         $a1, $zero, L_800ABCD4
    if (ctx->r5 == 0) {
        // 0x800ABCA0: addu        $a0, $a1, $v1
        ctx->r4 = ADD32(ctx->r5, ctx->r3);
            goto L_800ABCD4;
    }
    // 0x800ABCA0: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_800ABCA4:
    // 0x800ABCA4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800ABCA8: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x800ABCAC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800ABCB0: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800ABCB4: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800ABCB8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800ABCBC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800ABCC0: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800ABCC4: bne         $a0, $v1, L_800ABCA4
    if (ctx->r4 != ctx->r3) {
        // 0x800ABCC8: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800ABCA4;
    }
    // 0x800ABCC8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800ABCCC: beql        $v1, $zero, L_800ABD54
    if (ctx->r3 == 0) {
        // 0x800ABCD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800ABD54;
    }
    goto skip_7;
    // 0x800ABCD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
L_800ABCD4:
    // 0x800ABCD4: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x800ABCD8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800ABCDC: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800ABCE0: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x800ABCE4: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800ABCE8: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x800ABCEC: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x800ABCF0: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x800ABCF4: lw          $t1, 0x28($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X28);
    // 0x800ABCF8: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x800ABCFC: lw          $t5, 0x18($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X18);
    // 0x800ABD00: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800ABD04: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800ABD08: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800ABD0C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800ABD10: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x800ABD14: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800ABD18: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x800ABD1C: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800ABD20: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800ABD24: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x800ABD28: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    // 0x800ABD2C: sw          $t2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r10;
    // 0x800ABD30: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x800ABD34: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x800ABD38: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800ABD3C: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x800ABD40: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x800ABD44: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x800ABD48: bne         $v1, $zero, L_800ABCD4
    if (ctx->r3 != 0) {
        // 0x800ABD4C: sw          $zero, -0x28($v0)
        MEM_W(-0X28, ctx->r2) = 0;
            goto L_800ABCD4;
    }
    // 0x800ABD4C: sw          $zero, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = 0;
L_800ABD50:
    // 0x800ABD50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800ABD54:
    // 0x800ABD54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ABD58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ABD5C: jr          $ra
    // 0x800ABD60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ABD60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800ABD64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABD64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ABD68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800ABD6C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800ABD70: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800ABD74: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ABD78: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ABD7C: lw          $s3, 0x8($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X8);
    // 0x800ABD80: lw          $s2, 0x18($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X18);
    // 0x800ABD84: beql        $s3, $zero, L_800ABDC4
    if (ctx->r19 == 0) {
        // 0x800ABD88: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800ABDC4;
    }
    goto skip_0;
    // 0x800ABD88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_800ABD8C:
    // 0x800ABD8C: lw          $s1, 0x10($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X10);
    // 0x800ABD90: lw          $s0, 0x14($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X14);
    // 0x800ABD94: beql        $s1, $zero, L_800ABDB8
    if (ctx->r17 == 0) {
        // 0x800ABD98: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_800ABDB8;
    }
    goto skip_1;
    // 0x800ABD98: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_1:
L_800ABD9C:
    // 0x800ABD9C: jal         0x800AA14C
    // 0x800ABDA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800AA14C(rdram, ctx);
        goto after_0;
    // 0x800ABDA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x800ABDA4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800ABDA8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800ABDAC: bne         $s1, $zero, L_800ABD9C
    if (ctx->r17 != 0) {
        // 0x800ABDB0: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_800ABD9C;
    }
    // 0x800ABDB0: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x800ABDB4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_800ABDB8:
    // 0x800ABDB8: bne         $s3, $zero, L_800ABD8C
    if (ctx->r19 != 0) {
        // 0x800ABDBC: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_800ABD8C;
    }
    // 0x800ABDBC: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x800ABDC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800ABDC4:
    // 0x800ABDC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ABDC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ABDCC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABDD0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800ABDD4: jr          $ra
    // 0x800ABDD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ABDD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800ABDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABDDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ABDE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ABDE4: jal         0x800AA14C
    // 0x800ABDE8: nop

    func_800AA14C(rdram, ctx);
        goto after_0;
    // 0x800ABDE8: nop

    after_0:
    // 0x800ABDEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ABDF0: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800ABDF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800ABDF8: jr          $ra
    // 0x800ABDFC: nop

    return;
    // 0x800ABDFC: nop

;}

RECOMP_FUNC void func_800ABE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABE00: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800ABE04: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800ABE08: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800ABE0C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800ABE10: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800ABE14: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800ABE18: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800ABE1C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800ABE20: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800ABE24: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800ABE28: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800ABE2C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800ABE30: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800ABE34: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800ABE38: addiu       $s3, $s3, -0x35F0
    ctx->r19 = ADD32(ctx->r19, -0X35F0);
    // 0x800ABE3C: addiu       $s1, $s1, -0x3524
    ctx->r17 = ADD32(ctx->r17, -0X3524);
    // 0x800ABE40: addiu       $s0, $s0, -0x35B8
    ctx->r16 = ADD32(ctx->r16, -0X35B8);
    // 0x800ABE44: addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
    // 0x800ABE48: addiu       $s4, $sp, 0x70
    ctx->r20 = ADD32(ctx->r29, 0X70);
    // 0x800ABE4C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800ABE50: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800ABE54: addiu       $s7, $sp, 0x78
    ctx->r23 = ADD32(ctx->r29, 0X78);
    // 0x800ABE58: addiu       $fp, $sp, 0x74
    ctx->r30 = ADD32(ctx->r29, 0X74);
    // 0x800ABE5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800ABE60:
    // 0x800ABE60: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800ABE64: jal         0x800B3C20
    // 0x800ABE68: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800ABE68: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
    // 0x800ABE6C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800ABE70: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800ABE74: lbu         $v1, 0xC($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XC);
    // 0x800ABE78: beql        $v1, $zero, L_800ABE9C
    if (ctx->r3 == 0) {
        // 0x800ABE7C: lw          $a0, 0x4($t7)
        ctx->r4 = MEM_W(ctx->r15, 0X4);
            goto L_800ABE9C;
    }
    goto skip_0;
    // 0x800ABE7C: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    skip_0:
    // 0x800ABE80: beq         $v1, $s5, L_800ABEE8
    if (ctx->r3 == ctx->r21) {
        // 0x800ABE84: lw          $t1, 0x70($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X70);
            goto L_800ABEE8;
    }
    // 0x800ABE84: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800ABE88: beq         $v1, $s6, L_800ABF48
    if (ctx->r3 == ctx->r22) {
        // 0x800ABE8C: lw          $t7, 0x70($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X70);
            goto L_800ABF48;
    }
    // 0x800ABE8C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800ABE90: b           L_800ABFA4
    // 0x800ABE94: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
        goto L_800ABFA4;
    // 0x800ABE94: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800ABE98: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
L_800ABE9C:
    // 0x800ABE9C: jal         0x800BAFA0
    // 0x800ABEA0: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x800ABEA0: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    after_1:
    // 0x800ABEA4: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800ABEA8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800ABEAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800ABEB0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800ABEB4: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x800ABEB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800ABEBC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800ABEC0: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x800ABEC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ABEC8: jal         0x800BB050
    // 0x800ABECC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    osPiStartDma_recomp(rdram, ctx);
        goto after_2;
    // 0x800ABECC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_2:
    // 0x800ABED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ABED4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800ABED8: jal         0x800B3C20
    // 0x800ABEDC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800ABEDC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x800ABEE0: b           L_800ABFA4
    // 0x800ABEE4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
        goto L_800ABFA4;
    // 0x800ABEE4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
L_800ABEE8:
    // 0x800ABEE8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800ABEEC: jal         0x800BB160
    // 0x800ABEF0: lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X8);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_4;
    // 0x800ABEF0: lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X8);
    after_4:
    // 0x800ABEF4: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x800ABEF8: sb          $zero, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = 0;
    // 0x800ABEFC: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
    // 0x800ABF00: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800ABF04: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ABF08: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800ABF0C: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x800ABF10: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x800ABF14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800ABF18: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x800ABF1C: lw          $t5, 0x8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8);
    // 0x800ABF20: jal         0x800BB1E0
    // 0x800ABF24: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    osEPiStartDma_recomp(rdram, ctx);
        goto after_5;
    // 0x800ABF24: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    after_5:
    // 0x800ABF28: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800ABF2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ABF30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800ABF34: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800ABF38: jal         0x800B3C20
    // 0x800ABF3C: sw          $v0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r2;
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800ABF3C: sw          $v0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r2;
    after_6:
    // 0x800ABF40: b           L_800ABFA4
    // 0x800ABF44: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
        goto L_800ABFA4;
    // 0x800ABF44: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
L_800ABF48:
    // 0x800ABF48: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800ABF4C: jal         0x800BB160
    // 0x800ABF50: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_7;
    // 0x800ABF50: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    after_7:
    // 0x800ABF54: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800ABF58: sb          $zero, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = 0;
    // 0x800ABF5C: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
    // 0x800ABF60: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800ABF64: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ABF68: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800ABF6C: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800ABF70: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800ABF74: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800ABF78: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x800ABF7C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x800ABF80: jal         0x800BB1E0
    // 0x800ABF84: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    osEPiStartDma_recomp(rdram, ctx);
        goto after_8;
    // 0x800ABF84: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    after_8:
    // 0x800ABF88: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800ABF8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ABF90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800ABF94: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800ABF98: jal         0x800B3C20
    // 0x800ABF9C: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    osRecvMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x800ABF9C: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    after_9:
    // 0x800ABFA0: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
L_800ABFA4:
    // 0x800ABFA4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800ABFA8: jal         0x800B34D0
    // 0x800ABFAC: lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X10);
    osSendMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x800ABFAC: lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X10);
    after_10:
    // 0x800ABFB0: b           L_800ABE60
    // 0x800ABFB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_800ABE60;
    // 0x800ABFB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800ABFB8: nop

    // 0x800ABFBC: nop

    // 0x800ABFC0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800ABFC4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800ABFC8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800ABFCC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800ABFD0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800ABFD4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800ABFD8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800ABFDC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800ABFE0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800ABFE4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800ABFE8: jr          $ra
    // 0x800ABFEC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800ABFEC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}

RECOMP_FUNC void func_800ABFF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABFF0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800ABFF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ABFF8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800ABFFC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800AC000: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800AC004: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC008: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800AC00C: jal         0x800B3080
    // 0x800AC010: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800AC010: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x800AC014: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800AC018: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800AC01C: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800AC020: addiu       $t9, $sp, 0x38
    ctx->r25 = ADD32(ctx->r29, 0X38);
    // 0x800AC024: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC028: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800AC02C: sb          $zero, 0x28($sp)
    MEM_B(0X28, ctx->r29) = 0;
    // 0x800AC030: addiu       $a0, $a0, -0x35F0
    ctx->r4 = ADD32(ctx->r4, -0X35F0);
    // 0x800AC034: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800AC038: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC03C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800AC040: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800AC044: jal         0x800B34D0
    // 0x800AC048: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800AC048: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_1:
    // 0x800AC04C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800AC050: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800AC054: jal         0x800B3C20
    // 0x800AC058: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800AC058: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800AC05C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AC060: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800AC064: jr          $ra
    // 0x800AC068: nop

    return;
    // 0x800AC068: nop

;}

RECOMP_FUNC void Main_StartRomDmaThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC06C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AC070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AC074: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800AC078: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AC07C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800AC080: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC084: addiu       $a0, $a0, -0x35B8
    ctx->r4 = ADD32(ctx->r4, -0X35B8);
    // 0x800AC088: addiu       $a1, $a1, -0x35A0
    ctx->r5 = ADD32(ctx->r5, -0X35A0);
    // 0x800AC08C: jal         0x800B3080
    // 0x800AC090: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800AC090: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800AC094: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC098: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800AC09C: addiu       $a1, $a1, -0x35D8
    ctx->r5 = ADD32(ctx->r5, -0X35D8);
    // 0x800AC0A0: addiu       $a0, $a0, -0x35F0
    ctx->r4 = ADD32(ctx->r4, -0X35F0);
    // 0x800AC0A4: jal         0x800B3080
    // 0x800AC0A8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x800AC0A8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800AC0AC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800AC0B0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800AC0B4: addiu       $t6, $t6, -0x51F0
    ctx->r14 = ADD32(ctx->r14, -0X51F0);
    // 0x800AC0B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC0BC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800AC0C0: addiu       $a2, $a2, -0x4200
    ctx->r6 = ADD32(ctx->r6, -0X4200);
    // 0x800AC0C4: addiu       $a0, $a0, -0x57A0
    ctx->r4 = ADD32(ctx->r4, -0X57A0);
    // 0x800AC0C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800AC0CC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800AC0D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AC0D4: jal         0x800B6010
    // 0x800AC0D8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    osCreateThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800AC0D8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x800AC0DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC0E0: jal         0x800B6160
    // 0x800AC0E4: addiu       $a0, $a0, -0x57A0
    ctx->r4 = ADD32(ctx->r4, -0X57A0);
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x800AC0E4: addiu       $a0, $a0, -0x57A0
    ctx->r4 = ADD32(ctx->r4, -0X57A0);
    after_3:
    // 0x800AC0E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC0EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AC0F0: jr          $ra
    // 0x800AC0F4: nop

    return;
    // 0x800AC0F4: nop

;}

RECOMP_FUNC void Main_InitCartPiHandle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC0F8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800AC0FC: addiu       $a2, $a2, -0x3598
    ctx->r6 = ADD32(ctx->r6, -0X3598);
    // 0x800AC100: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x800AC104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AC108: lui         $v0, 0xA800
    ctx->r2 = S32(0XA800 << 16);
    // 0x800AC10C: bne         $v0, $t6, L_800AC124
    if (ctx->r2 != ctx->r14) {
        // 0x800AC110: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AC124;
    }
    // 0x800AC110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AC114: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC118: addiu       $v0, $v0, -0x3524
    ctx->r2 = ADD32(ctx->r2, -0X3524);
    // 0x800AC11C: b           L_800AC198
    // 0x800AC120: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_800AC198;
    // 0x800AC120: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_800AC124:
    // 0x800AC124: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800AC128: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800AC12C: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x800AC130: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x800AC134: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800AC138: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AC13C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800AC140: sb          $t7, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r15;
    // 0x800AC144: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x800AC148: sb          $t8, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r24;
    // 0x800AC14C: sb          $t9, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r25;
    // 0x800AC150: sb          $t0, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r8;
    // 0x800AC154: sb          $t1, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r9;
    // 0x800AC158: sb          $t2, 0x9($a2)
    MEM_B(0X9, ctx->r6) = ctx->r10;
    // 0x800AC15C: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x800AC160: addiu       $a0, $a0, -0x3584
    ctx->r4 = ADD32(ctx->r4, -0X3584);
    // 0x800AC164: jal         0x800B7450
    // 0x800AC168: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x800AC168: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_0:
    // 0x800AC16C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800AC170: jal         0x800BB2C0
    // 0x800AC174: addiu       $a0, $a2, -0x3598
    ctx->r4 = ADD32(ctx->r6, -0X3598);
    osEPiLinkHandle(rdram, ctx);
        goto after_1;
    // 0x800AC174: addiu       $a0, $a2, -0x3598
    ctx->r4 = ADD32(ctx->r6, -0X3598);
    after_1:
    // 0x800AC178: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC17C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800AC180: addiu       $a1, $a2, -0x3598
    ctx->r5 = ADD32(ctx->r6, -0X3598);
    // 0x800AC184: addiu       $v0, $v0, -0x3524
    ctx->r2 = ADD32(ctx->r2, -0X3524);
    // 0x800AC188: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AC18C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x800AC190: jal         0x800B3BFC
    // 0x800AC194: addiu       $a0, $a0, 0x1150
    ctx->r4 = ADD32(ctx->r4, 0X1150);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800AC194: addiu       $a0, $a0, 0x1150
    ctx->r4 = ADD32(ctx->r4, 0X1150);
    after_2:
L_800AC198:
    // 0x800AC198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AC19C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AC1A0: jr          $ra
    // 0x800AC1A4: nop

    return;
    // 0x800AC1A4: nop

;}

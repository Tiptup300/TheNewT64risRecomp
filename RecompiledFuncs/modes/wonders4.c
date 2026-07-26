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

RECOMP_FUNC void wonders4_CreateThread(uint8_t* rdram, recomp_context* ctx) {
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

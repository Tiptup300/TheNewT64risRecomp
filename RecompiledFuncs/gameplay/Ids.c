#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Ids_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050650: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80050654: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80050658: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005065C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80050660: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80050664: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050668: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005066C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80050670: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80050674: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80050678: nop

    // 0x8005067C: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
    // 0x80050680: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80050684: jal         0x8007E03C
    // 0x80050688: nop

    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80050688: nop

    after_0:
    // 0x8005068C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80050690: nop

    // 0x80050694: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80050698: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8005069C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800506A0: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x800506A4: blez        $s1, L_800506BC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800506A8: nop
    
            goto L_800506BC;
    }
    // 0x800506A8: nop

L_800506AC:
    // 0x800506AC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800506B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800506B4: bgtz        $s1, L_800506AC
    if (SIGNED(ctx->r17) > 0) {
        // 0x800506B8: sb          $zero, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = 0;
            goto L_800506AC;
    }
    // 0x800506B8: sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
L_800506BC:
    // 0x800506BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800506C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800506C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800506C8: jr          $ra
    // 0x800506CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800506CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Ids_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800506D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800506D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800506D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800506DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800506E0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800506E4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800506E8: nop

    // 0x800506EC: sw          $zero, 0x8($t7)
    MEM_W(0X8, ctx->r15) = 0;
    // 0x800506F0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800506F4: nop

    // 0x800506F8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800506FC: jal         0x8007E328
    // 0x80050700: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x80050700: nop

    after_0:
    // 0x80050704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005070C: jr          $ra
    // 0x80050710: nop

    return;
    // 0x80050710: nop

;}

RECOMP_FUNC void can_run_out_of_ids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050714: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80050718: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8005071C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80050720: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80050724: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80050728: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005072C: lw          $s2, 0x8($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X8);
    // 0x80050730: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80050734: nop

    // 0x80050738: addu        $s0, $t7, $s2
    ctx->r16 = ADD32(ctx->r15, ctx->r18);
    // 0x8005073C: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x80050740: nop

    // 0x80050744: beq         $t8, $zero, L_800507A8
    if (ctx->r24 == 0) {
        // 0x80050748: nop
    
            goto L_800507A8;
    }
    // 0x80050748: nop

L_8005074C:
    // 0x8005074C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80050750: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80050754: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80050758: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005075C: bne         $t0, $s2, L_8005076C
    if (ctx->r8 != ctx->r18) {
        // 0x80050760: nop
    
            goto L_8005076C;
    }
    // 0x80050760: nop

    // 0x80050764: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x80050768: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8005076C:
    // 0x8005076C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80050770: nop

    // 0x80050774: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80050778: nop

    // 0x8005077C: bne         $t2, $s2, L_80050798
    if (ctx->r10 != ctx->r18) {
        // 0x80050780: nop
    
            goto L_80050798;
    }
    // 0x80050780: nop

    // 0x80050784: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80050788: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005078C: addiu       $a1, $a1, -0x3598
    ctx->r5 = ADD32(ctx->r5, -0X3598);
    // 0x80050790: jal         0x80083560
    // 0x80050794: addiu       $a0, $a0, -0x35A0
    ctx->r4 = ADD32(ctx->r4, -0X35A0);
    debug_print_reason_routine(rdram, ctx);
        goto after_0;
    // 0x80050794: addiu       $a0, $a0, -0x35A0
    ctx->r4 = ADD32(ctx->r4, -0X35A0);
    after_0:
L_80050798:
    // 0x80050798: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x8005079C: nop

    // 0x800507A0: bne         $t3, $zero, L_8005074C
    if (ctx->r11 != 0) {
        // 0x800507A4: nop
    
            goto L_8005074C;
    }
    // 0x800507A4: nop

L_800507A8:
    // 0x800507A8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800507AC: addiu       $t4, $s2, 0x1
    ctx->r12 = ADD32(ctx->r18, 0X1);
    // 0x800507B0: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x800507B4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800507B8: divu        $zero, $t4, $t6
    lo = S32(U32(ctx->r12) / U32(ctx->r14)); hi = S32(U32(ctx->r12) % U32(ctx->r14));
    // 0x800507BC: bne         $t6, $zero, L_800507C8
    if (ctx->r14 != 0) {
        // 0x800507C0: nop
    
            goto L_800507C8;
    }
    // 0x800507C0: nop

    // 0x800507C4: break       7
    do_break(2147813316);
L_800507C8:
    // 0x800507C8: mfhi        $t7
    ctx->r15 = hi;
    // 0x800507CC: sw          $t7, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r15;
    // 0x800507D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800507D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800507D8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800507DC: jr          $ra
    // 0x800507E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800507E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Ids_Release(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800507E4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800507E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800507EC: addu        $a2, $t6, $a1
    ctx->r6 = ADD32(ctx->r14, ctx->r5);
    // 0x800507F0: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x800507F4: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x800507F8: jr          $ra
    // 0x800507FC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800507FC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Ids_IncRef(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050800: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80050804: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80050808: addu        $a2, $t6, $a1
    ctx->r6 = ADD32(ctx->r14, ctx->r5);
    // 0x8005080C: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x80050810: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80050814: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80050818: jr          $ra
    // 0x8005081C: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    return;
    // 0x8005081C: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
;}

RECOMP_FUNC void Ids_AddRef(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050820: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80050824: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80050828: addu        $a3, $t6, $a1
    ctx->r7 = ADD32(ctx->r14, ctx->r5);
    // 0x8005082C: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x80050830: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80050834: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x80050838: jr          $ra
    // 0x8005083C: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
    return;
    // 0x8005083C: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
;}

RECOMP_FUNC void Ids_DecRef(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050840: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80050844: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80050848: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005084C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80050850: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050854: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050858: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005085C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80050860: nop

    // 0x80050864: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80050868: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x8005086C: nop

    // 0x80050870: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80050874: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
    // 0x80050878: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x8005087C: nop

    // 0x80050880: bne         $t1, $zero, L_80050898
    if (ctx->r9 != 0) {
        // 0x80050884: nop
    
            goto L_80050898;
    }
    // 0x80050884: nop

    // 0x80050888: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8005088C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80050890: jal         0x800507E4
    // 0x80050894: nop

    Ids_Release(rdram, ctx);
        goto after_0;
    // 0x80050894: nop

    after_0:
L_80050898:
    // 0x80050898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005089C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800508A0: jr          $ra
    // 0x800508A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800508A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Ids_SubRef(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800508A8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800508AC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800508B0: addu        $a3, $t6, $a1
    ctx->r7 = ADD32(ctx->r14, ctx->r5);
    // 0x800508B4: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x800508B8: nop

    // 0x800508BC: sltu        $at, $a2, $t7
    ctx->r1 = ctx->r6 < ctx->r15 ? 1 : 0;
    // 0x800508C0: bne         $at, $zero, L_800508D4
    if (ctx->r1 != 0) {
        // 0x800508C4: nop
    
            goto L_800508D4;
    }
    // 0x800508C4: nop

    // 0x800508C8: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    // 0x800508CC: b           L_800508E4
    // 0x800508D0: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
        goto L_800508E4;
    // 0x800508D0: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
L_800508D4:
    // 0x800508D4: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x800508D8: nop

    // 0x800508DC: subu        $t9, $t8, $a2
    ctx->r25 = SUB32(ctx->r24, ctx->r6);
    // 0x800508E0: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
L_800508E4:
    // 0x800508E4: jr          $ra
    // 0x800508E8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800508E8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Ids_CopyFrom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800508EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800508F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800508F4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800508F8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800508FC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80050900: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80050904: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80050908: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005090C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050910: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80050914: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80050918: nop

    // 0x8005091C: beq         $t7, $t9, L_80050970
    if (ctx->r15 == ctx->r25) {
        // 0x80050920: nop
    
            goto L_80050970;
    }
    // 0x80050920: nop

    // 0x80050924: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80050928: jal         0x8007E328
    // 0x8005092C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x8005092C: nop

    after_0:
    // 0x80050930: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80050934: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80050938: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8005093C: nop

    // 0x80050940: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80050944: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80050948: nop

    // 0x8005094C: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    // 0x80050950: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80050954: nop

    // 0x80050958: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x8005095C: jal         0x8007E03C
    // 0x80050960: nop

    n64HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80050960: nop

    after_1:
    // 0x80050964: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80050968: nop

    // 0x8005096C: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
L_80050970:
    // 0x80050970: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80050974: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80050978: lw          $s2, 0x4($t8)
    ctx->r18 = MEM_W(ctx->r24, 0X4);
    // 0x8005097C: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x80050980: lw          $s1, 0x0($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X0);
    // 0x80050984: blez        $s2, L_800509A4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80050988: nop
    
            goto L_800509A4;
    }
    // 0x80050988: nop

L_8005098C:
    // 0x8005098C: lbu         $at, 0x0($s1)
    ctx->r1 = MEM_BU(ctx->r17, 0X0);
    // 0x80050990: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80050994: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80050998: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005099C: bgtz        $s2, L_8005098C
    if (SIGNED(ctx->r18) > 0) {
        // 0x800509A0: sb          $at, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r1;
            goto L_8005098C;
    }
    // 0x800509A0: sb          $at, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r1;
L_800509A4:
    // 0x800509A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800509A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800509AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800509B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800509B4: jr          $ra
    // 0x800509B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800509B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800509BC: nop

;}

RECOMP_FUNC void setPlayerTopOutOrder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800509C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800509C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800509C8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800509CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800509D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800509D4: addiu       $t7, $t6, 0x7FFF
    ctx->r15 = ADD32(ctx->r14, 0X7FFF);
    // 0x800509D8: lbu         $t7, 0x6510($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X6510);
    // 0x800509DC: nop

    // 0x800509E0: bltz        $t7, L_80050A00
    if (SIGNED(ctx->r15) < 0) {
        // 0x800509E4: nop
    
            goto L_80050A00;
    }
    // 0x800509E4: nop

    // 0x800509E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800509EC: lbu         $t8, -0x10E0($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X10E0);
    // 0x800509F0: nop

    // 0x800509F4: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800509F8: bne         $at, $zero, L_80050A18
    if (ctx->r1 != 0) {
        // 0x800509FC: nop
    
            goto L_80050A18;
    }
    // 0x800509FC: nop

L_80050A00:
    // 0x80050A00: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80050A04: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80050A08: addiu       $a1, $a1, -0x3564
    ctx->r5 = ADD32(ctx->r5, -0X3564);
    // 0x80050A0C: addiu       $a0, $a0, -0x3580
    ctx->r4 = ADD32(ctx->r4, -0X3580);
    // 0x80050A10: jal         0x8004A5A0
    // 0x80050A14: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_0;
    // 0x80050A14: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_0:
L_80050A18:
    // 0x80050A18: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80050A1C: lbu         $t9, 0x1F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1F);
    // 0x80050A20: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x80050A24: lbu         $t1, 0x6510($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X6510);
    // 0x80050A28: nop

    // 0x80050A2C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80050A30: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x80050A34: sb          $t9, 0x650C($at)
    MEM_B(0X650C, ctx->r1) = ctx->r25;
    // 0x80050A38: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80050A3C: nop

    // 0x80050A40: addiu       $t4, $t3, 0x7FFF
    ctx->r12 = ADD32(ctx->r11, 0X7FFF);
    // 0x80050A44: lbu         $t4, 0x6510($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X6510);
    // 0x80050A48: addiu       $at, $t3, 0x7FFF
    ctx->r1 = ADD32(ctx->r11, 0X7FFF);
    // 0x80050A4C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80050A50: sb          $t5, 0x6510($at)
    MEM_B(0X6510, ctx->r1) = ctx->r13;
    // 0x80050A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050A5C: jr          $ra
    // 0x80050A60: nop

    return;
    // 0x80050A60: nop

;}

RECOMP_FUNC void hasPlayerToppedOut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050A64: addiu       $t6, $a0, 0x7FFF
    ctx->r14 = ADD32(ctx->r4, 0X7FFF);
    // 0x80050A68: lbu         $t6, 0x6510($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X6510);
    // 0x80050A6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80050A70: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80050A74: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80050A78: beq         $at, $zero, L_80050AB8
    if (ctx->r1 == 0) {
        // 0x80050A7C: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_80050AB8;
    }
    // 0x80050A7C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_80050A80:
    // 0x80050A80: addu        $t7, $a0, $a2
    ctx->r15 = ADD32(ctx->r4, ctx->r6);
    // 0x80050A84: addiu       $t8, $t7, 0x7FFF
    ctx->r24 = ADD32(ctx->r15, 0X7FFF);
    // 0x80050A88: lbu         $t8, 0x650C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X650C);
    // 0x80050A8C: nop

    // 0x80050A90: bne         $t8, $a1, L_80050AA0
    if (ctx->r24 != ctx->r5) {
        // 0x80050A94: nop
    
            goto L_80050AA0;
    }
    // 0x80050A94: nop

    // 0x80050A98: b           L_80050ABC
    // 0x80050A9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80050ABC;
    // 0x80050A9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80050AA0:
    // 0x80050AA0: addiu       $t9, $a0, 0x7FFF
    ctx->r25 = ADD32(ctx->r4, 0X7FFF);
    // 0x80050AA4: lbu         $t9, 0x6510($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X6510);
    // 0x80050AA8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80050AAC: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80050AB0: bne         $at, $zero, L_80050A80
    if (ctx->r1 != 0) {
        // 0x80050AB4: nop
    
            goto L_80050A80;
    }
    // 0x80050AB4: nop

L_80050AB8:
    // 0x80050AB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050ABC:
    // 0x80050ABC: jr          $ra
    // 0x80050AC0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80050AC0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

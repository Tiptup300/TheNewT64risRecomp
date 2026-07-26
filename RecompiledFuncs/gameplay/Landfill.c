#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Landfill_FlagIfCurrentPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072300: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80072304: lw          $a1, -0x390($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X390);
    // 0x80072308: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8007230C: lbu         $t6, 0x30($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X30);
    // 0x80072310: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80072314: bne         $t6, $a0, L_80072324
    if (ctx->r14 != ctx->r4) {
        // 0x80072318: nop
    
            goto L_80072324;
    }
    // 0x80072318: nop

    // 0x8007231C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80072320: sb          $t7, 0x31($a1)
    MEM_B(0X31, ctx->r5) = ctx->r15;
L_80072324:
    // 0x80072324: jr          $ra
    // 0x80072328: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80072328: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Landfill_CountActivePlayers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007232C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80072330: lbu         $t6, -0x10E0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X10E0);
    // 0x80072334: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007233C: lw          $a0, -0x390($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X390);
    // 0x80072340: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80072344: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80072348: beq         $at, $zero, L_80072398
    if (ctx->r1 == 0) {
        // 0x8007234C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80072398;
    }
    // 0x8007234C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80072350:
    // 0x80072350: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80072354: lw          $t7, -0x390($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X390);
    // 0x80072358: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x8007235C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80072360: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x80072364: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80072368: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8007236C: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80072370: nop

    // 0x80072374: beq         $t1, $zero, L_80072380
    if (ctx->r9 == 0) {
        // 0x80072378: nop
    
            goto L_80072380;
    }
    // 0x80072378: nop

    // 0x8007237C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80072380:
    // 0x80072380: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80072384: lbu         $t2, -0x10E0($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X10E0);
    // 0x80072388: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007238C: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80072390: bne         $at, $zero, L_80072350
    if (ctx->r1 != 0) {
        // 0x80072394: nop
    
            goto L_80072350;
    }
    // 0x80072394: nop

L_80072398:
    // 0x80072398: jr          $ra
    // 0x8007239C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007239C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void Landfill_SetCell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800723A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800723A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800723A8: lbu         $t8, 0x1B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1B);
    // 0x800723AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800723B0: lw          $t6, -0x390($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X390);
    // 0x800723B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800723B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800723BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800723C0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800723C4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800723C8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800723CC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800723D0: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x800723D4: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x800723D8: jal         0x80072CC8
    // 0x800723DC: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    Landfill_SetRowCell(rdram, ctx);
        goto after_0;
    // 0x800723DC: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x800723E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800723E4: lw          $a0, -0x390($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X390);
    // 0x800723E8: lbu         $a1, 0x1B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1B);
    // 0x800723EC: lbu         $a2, 0x1F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1F);
    // 0x800723F0: lbu         $a3, 0x23($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X23);
    // 0x800723F4: jal         0x80073690
    // 0x800723F8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    GarbageFx_SetBlockCell(rdram, ctx);
        goto after_1;
    // 0x800723F8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x800723FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072404: jr          $ra
    // 0x80072408: nop

    return;
    // 0x80072408: nop

;}

RECOMP_FUNC void Landfill_SetRowLength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007240C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80072410: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80072414: lbu         $t8, 0x2B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2B);
    // 0x80072418: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007241C: lw          $t6, -0x390($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X390);
    // 0x80072420: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072424: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80072428: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007242C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80072430: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80072434: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80072438: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007243C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80072440: addu        $s1, $t7, $t9
    ctx->r17 = ADD32(ctx->r15, ctx->r25);
    // 0x80072444: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
    // 0x80072448: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8007244C: beq         $t0, $zero, L_80072480
    if (ctx->r8 == 0) {
        // 0x80072450: nop
    
            goto L_80072480;
    }
    // 0x80072450: nop

    // 0x80072454: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x80072458: jal         0x80072E34
    // 0x8007245C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Garbage_SetColor(rdram, ctx);
        goto after_0;
    // 0x8007245C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80072460: lbu         $t3, 0x2B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X2B);
    // 0x80072464: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80072468: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007246C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80072470: lbu         $t1, 0x2F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2F);
    // 0x80072474: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80072478: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8007247C: sb          $t1, 0xA($t5)
    MEM_B(0XA, ctx->r13) = ctx->r9;
L_80072480:
    // 0x80072480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072484: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80072488: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007248C: jr          $ra
    // 0x80072490: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80072490: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Landfill_GetRowLength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072494: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80072498: lw          $t6, -0x390($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X390);
    // 0x8007249C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800724A0: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x800724A4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800724A8: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x800724AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800724B0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800724B4: lbu         $v0, 0x1D($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X1D);
    // 0x800724B8: jr          $ra
    // 0x800724BC: nop

    return;
    // 0x800724BC: nop

;}

RECOMP_FUNC void Landfill_GetCell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800724C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800724C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800724C8: lbu         $t8, 0x1B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1B);
    // 0x800724CC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800724D0: lw          $t6, -0x390($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X390);
    // 0x800724D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800724D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800724DC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800724E0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800724E4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800724E8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800724EC: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x800724F0: jal         0x80072D24
    // 0x800724F4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    Landfill_GetRowCell(rdram, ctx);
        goto after_0;
    // 0x800724F4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x800724F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800724FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072500: jr          $ra
    // 0x80072504: nop

    return;
    // 0x80072504: nop

;}

RECOMP_FUNC void Landfill_ShrinkRowToTopFilled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072508: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007250C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80072510: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072514: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x80072518: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007251C: jal         0x80072494
    // 0x80072520: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    Landfill_GetRowLength(rdram, ctx);
        goto after_0;
    // 0x80072520: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80072524: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80072528: blez        $s0, L_80072568
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8007252C: nop
    
            goto L_80072568;
    }
    // 0x8007252C: nop

    // 0x80072530: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80072534:
    // 0x80072534: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80072538: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x8007253C: jal         0x800724C0
    // 0x80072540: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    Landfill_GetCell(rdram, ctx);
        goto after_1;
    // 0x80072540: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80072544: bne         $v0, $zero, L_80072554
    if (ctx->r2 != 0) {
        // 0x80072548: nop
    
            goto L_80072554;
    }
    // 0x80072548: nop

    // 0x8007254C: bgez        $s1, L_80072534
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80072550: nop
    
            goto L_80072534;
    }
    // 0x80072550: nop

L_80072554:
    // 0x80072554: bltz        $s1, L_80072568
    if (SIGNED(ctx->r17) < 0) {
        // 0x80072558: nop
    
            goto L_80072568;
    }
    // 0x80072558: nop

    // 0x8007255C: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x80072560: jal         0x8007240C
    // 0x80072564: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    Landfill_SetRowLength(rdram, ctx);
        goto after_2;
    // 0x80072564: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
L_80072568:
    // 0x80072568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007256C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80072570: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80072574: jr          $ra
    // 0x80072578: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80072578: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Landfill_GrowRowToNextFilled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007257C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80072580: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80072584: lw          $t6, -0x390($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X390);
    // 0x80072588: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007258C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80072590: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80072594: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80072598: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007259C: lbu         $s0, 0x4($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0X4);
    // 0x800725A0: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x800725A4: jal         0x80072494
    // 0x800725A8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    Landfill_GetRowLength(rdram, ctx);
        goto after_0;
    // 0x800725A8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    after_0:
    // 0x800725AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800725B0: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800725B4: beq         $at, $zero, L_800725F8
    if (ctx->r1 == 0) {
        // 0x800725B8: nop
    
            goto L_800725F8;
    }
    // 0x800725B8: nop

    // 0x800725BC: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
L_800725C0:
    // 0x800725C0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800725C4: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x800725C8: jal         0x800724C0
    // 0x800725CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    Landfill_GetCell(rdram, ctx);
        goto after_1;
    // 0x800725CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800725D0: bne         $v0, $zero, L_800725E0
    if (ctx->r2 != 0) {
        // 0x800725D4: slt         $at, $s0, $s2
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800725E0;
    }
    // 0x800725D4: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800725D8: beq         $at, $zero, L_800725C0
    if (ctx->r1 == 0) {
        // 0x800725DC: nop
    
            goto L_800725C0;
    }
    // 0x800725DC: nop

L_800725E0:
    // 0x800725E0: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800725E4: bne         $at, $zero, L_800725F8
    if (ctx->r1 != 0) {
        // 0x800725E8: nop
    
            goto L_800725F8;
    }
    // 0x800725E8: nop

    // 0x800725EC: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x800725F0: jal         0x8007240C
    // 0x800725F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    Landfill_SetRowLength(rdram, ctx);
        goto after_2;
    // 0x800725F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_800725F8:
    // 0x800725F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800725FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80072600: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80072604: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80072608: jr          $ra
    // 0x8007260C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007260C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Landfill_CycleRowToNextFilled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072610: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80072614: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80072618: lw          $t6, -0x390($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X390);
    // 0x8007261C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80072620: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80072624: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80072628: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007262C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072630: lbu         $s0, 0x4($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0X4);
    // 0x80072634: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x80072638: jal         0x80072494
    // 0x8007263C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    Landfill_GetRowLength(rdram, ctx);
        goto after_0;
    // 0x8007263C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    after_0:
    // 0x80072640: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80072644: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
L_80072648:
    // 0x80072648: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007264C: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80072650: beq         $at, $zero, L_8007265C
    if (ctx->r1 == 0) {
        // 0x80072654: nop
    
            goto L_8007265C;
    }
    // 0x80072654: nop

    // 0x80072658: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8007265C:
    // 0x8007265C: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x80072660: jal         0x800724C0
    // 0x80072664: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    Landfill_GetCell(rdram, ctx);
        goto after_1;
    // 0x80072664: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80072668: bne         $v0, $zero, L_80072678
    if (ctx->r2 != 0) {
        // 0x8007266C: nop
    
            goto L_80072678;
    }
    // 0x8007266C: nop

    // 0x80072670: bne         $s2, $s1, L_80072648
    if (ctx->r18 != ctx->r17) {
        // 0x80072674: nop
    
            goto L_80072648;
    }
    // 0x80072674: nop

L_80072678:
    // 0x80072678: beq         $s2, $s1, L_8007268C
    if (ctx->r18 == ctx->r17) {
        // 0x8007267C: nop
    
            goto L_8007268C;
    }
    // 0x8007267C: nop

    // 0x80072680: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x80072684: jal         0x8007240C
    // 0x80072688: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    Landfill_SetRowLength(rdram, ctx);
        goto after_2;
    // 0x80072688: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_8007268C:
    // 0x8007268C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80072690: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80072694: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80072698: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007269C: jr          $ra
    // 0x800726A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800726A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Landfill_ClearColumn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800726A4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800726A8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800726AC: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x800726B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800726B4: lw          $t6, -0x390($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X390);
    // 0x800726B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800726BC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800726C0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800726C4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800726C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800726CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800726D0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800726D4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800726D8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800726DC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800726E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800726E4: jal         0x80072E2C
    // 0x800726E8: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    Garbage_SetActive(rdram, ctx);
        goto after_0;
    // 0x800726E8: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x800726EC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800726F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800726F4: lbu         $t1, 0x4($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4);
    // 0x800726F8: nop

    // 0x800726FC: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80072700: beq         $at, $zero, L_80072750
    if (ctx->r1 == 0) {
        // 0x80072704: nop
    
            goto L_80072750;
    }
    // 0x80072704: nop

L_80072708:
    // 0x80072708: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007270C: lw          $t2, -0x390($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X390);
    // 0x80072710: sll         $t4, $s0, 3
    ctx->r12 = S32(ctx->r16 << 3);
    // 0x80072714: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80072718: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x8007271C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80072720: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x80072724: addu        $s1, $t3, $t4
    ctx->r17 = ADD32(ctx->r11, ctx->r12);
    // 0x80072728: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8007272C: jal         0x80072CC8
    // 0x80072730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Landfill_SetRowCell(rdram, ctx);
        goto after_1;
    // 0x80072730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80072734: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80072738: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007273C: lbu         $t6, 0x4($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X4);
    // 0x80072740: nop

    // 0x80072744: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80072748: bne         $at, $zero, L_80072708
    if (ctx->r1 != 0) {
        // 0x8007274C: nop
    
            goto L_80072708;
    }
    // 0x8007274C: nop

L_80072750:
    // 0x80072750: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80072754: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x80072758: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007275C: jal         0x800736E0
    // 0x80072760: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    GarbageFx_ConfigBlocks(rdram, ctx);
        goto after_2;
    // 0x80072760: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_2:
    // 0x80072764: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80072768: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007276C: lbu         $s3, 0x5($t8)
    ctx->r19 = MEM_BU(ctx->r24, 0X5);
    // 0x80072770: nop

    // 0x80072774: beq         $s3, $at, L_8007278C
    if (ctx->r19 == ctx->r1) {
        // 0x80072778: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007278C;
    }
    // 0x80072778: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007277C: beq         $s3, $at, L_800727B0
    if (ctx->r19 == ctx->r1) {
        // 0x80072780: nop
    
            goto L_800727B0;
    }
    // 0x80072780: nop

    // 0x80072784: b           L_80072820
    // 0x80072788: nop

        goto L_80072820;
    // 0x80072788: nop

L_8007278C:
    // 0x8007278C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80072790: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x80072794: lbu         $t9, 0x30($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X30);
    // 0x80072798: nop

    // 0x8007279C: bne         $t9, $t0, L_80072820
    if (ctx->r25 != ctx->r8) {
        // 0x800727A0: nop
    
            goto L_80072820;
    }
    // 0x800727A0: nop

    // 0x800727A4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800727A8: b           L_80072820
    // 0x800727AC: sb          $t1, 0x31($t7)
    MEM_B(0X31, ctx->r15) = ctx->r9;
        goto L_80072820;
    // 0x800727AC: sb          $t1, 0x31($t7)
    MEM_B(0X31, ctx->r15) = ctx->r9;
L_800727B0:
    // 0x800727B0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800727B4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800727B8: lbu         $t3, 0x4($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X4);
    // 0x800727BC: nop

    // 0x800727C0: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800727C4: beq         $at, $zero, L_80072820
    if (ctx->r1 == 0) {
        // 0x800727C8: nop
    
            goto L_80072820;
    }
    // 0x800727C8: nop

L_800727CC:
    // 0x800727CC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800727D0: lw          $t4, -0x390($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X390);
    // 0x800727D4: sll         $t6, $s2, 3
    ctx->r14 = S32(ctx->r18 << 3);
    // 0x800727D8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800727DC: addu        $t6, $t6, $s2
    ctx->r14 = ADD32(ctx->r14, ctx->r18);
    // 0x800727E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800727E4: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x800727E8: lbu         $t9, 0x1D($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1D);
    // 0x800727EC: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x800727F0: nop

    // 0x800727F4: bne         $t9, $t0, L_80072804
    if (ctx->r25 != ctx->r8) {
        // 0x800727F8: nop
    
            goto L_80072804;
    }
    // 0x800727F8: nop

    // 0x800727FC: jal         0x80072610
    // 0x80072800: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Landfill_CycleRowToNextFilled(rdram, ctx);
        goto after_3;
    // 0x80072800: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
L_80072804:
    // 0x80072804: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80072808: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007280C: lbu         $t7, 0x4($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X4);
    // 0x80072810: nop

    // 0x80072814: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80072818: bne         $at, $zero, L_800727CC
    if (ctx->r1 != 0) {
        // 0x8007281C: nop
    
            goto L_800727CC;
    }
    // 0x8007281C: nop

L_80072820:
    // 0x80072820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80072824: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80072828: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007282C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80072830: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80072834: jr          $ra
    // 0x80072838: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80072838: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Landfill_AppendRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007283C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80072840: lw          $t6, -0x390($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X390);
    // 0x80072844: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80072848: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8007284C: lbu         $t8, 0x4($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X4);
    // 0x80072850: lbu         $t0, 0x4($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X4);
    // 0x80072854: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80072858: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8007285C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80072860: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80072864: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80072868: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    // 0x8007286C: sb          $t1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r9;
    // 0x80072870: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80072874: jr          $ra
    // 0x80072878: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80072878: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Landfill_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007287C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80072880: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80072884: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80072888: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007288C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072890: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072894: sb          $zero, 0x4($t6)
    MEM_B(0X4, ctx->r14) = 0;
    // 0x80072898: lbu         $a0, -0x10E0($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X10E0);
    // 0x8007289C: nop

    // 0x800728A0: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800728A4: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800728A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800728AC: jal         0x8007E03C
    // 0x800728B0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800728B0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x800728B4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800728B8: nop

    // 0x800728BC: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x800728C0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800728C4: nop

    // 0x800728C8: lbu         $s0, 0x5($t9)
    ctx->r16 = MEM_BU(ctx->r25, 0X5);
    // 0x800728CC: nop

    // 0x800728D0: beq         $s0, $zero, L_800728F0
    if (ctx->r16 == 0) {
        // 0x800728D4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800728F0;
    }
    // 0x800728D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800728D8: beq         $s0, $at, L_8007291C
    if (ctx->r16 == ctx->r1) {
        // 0x800728DC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007291C;
    }
    // 0x800728DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800728E0: beq         $s0, $at, L_80072944
    if (ctx->r16 == ctx->r1) {
        // 0x800728E4: nop
    
            goto L_80072944;
    }
    // 0x800728E4: nop

    // 0x800728E8: b           L_80072960
    // 0x800728EC: nop

        goto L_80072960;
    // 0x800728EC: nop

L_800728F0:
    // 0x800728F0: jal         0x80073B48
    // 0x800728F4: nop

    Garbage_LoadTexture(rdram, ctx);
        goto after_1;
    // 0x800728F4: nop

    after_1:
    // 0x800728F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800728FC: jal         0x80073940
    // 0x80072900: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    GarbageFx_Alloc(rdram, ctx);
        goto after_2;
    // 0x80072900: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_2:
    // 0x80072904: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80072908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007290C: jal         0x80073784
    // 0x80072910: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    GarbageFx_FillAllBlocks(rdram, ctx);
        goto after_3;
    // 0x80072910: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_3:
    // 0x80072914: b           L_80072978
    // 0x80072918: nop

        goto L_80072978;
    // 0x80072918: nop

L_8007291C:
    // 0x8007291C: jal         0x80073B48
    // 0x80072920: nop

    Garbage_LoadTexture(rdram, ctx);
        goto after_4;
    // 0x80072920: nop

    after_4:
    // 0x80072924: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80072928: jal         0x80073940
    // 0x8007292C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    GarbageFx_Alloc(rdram, ctx);
        goto after_5;
    // 0x8007292C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_5:
    // 0x80072930: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80072934: jal         0x800743F8
    // 0x80072938: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    GarbageFx_InitIndicator(rdram, ctx);
        goto after_6;
    // 0x80072938: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_6:
    // 0x8007293C: b           L_80072978
    // 0x80072940: nop

        goto L_80072978;
    // 0x80072940: nop

L_80072944:
    // 0x80072944: jal         0x80073B48
    // 0x80072948: nop

    Garbage_LoadTexture(rdram, ctx);
        goto after_7;
    // 0x80072948: nop

    after_7:
    // 0x8007294C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80072950: jal         0x80073940
    // 0x80072954: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    GarbageFx_Alloc(rdram, ctx);
        goto after_8;
    // 0x80072954: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_8:
    // 0x80072958: b           L_80072978
    // 0x8007295C: nop

        goto L_80072978;
    // 0x8007295C: nop

L_80072960:
    // 0x80072960: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072964: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80072968: addiu       $a1, $a1, -0x25F8
    ctx->r5 = ADD32(ctx->r5, -0X25F8);
    // 0x8007296C: addiu       $a0, $a0, -0x2610
    ctx->r4 = ADD32(ctx->r4, -0X2610);
    // 0x80072970: jal         0x8004A5A0
    // 0x80072974: addiu       $a2, $zero, 0x114
    ctx->r6 = ADD32(0, 0X114);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_9;
    // 0x80072974: addiu       $a2, $zero, 0x114
    ctx->r6 = ADD32(0, 0X114);
    after_9:
L_80072978:
    // 0x80072978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007297C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80072980: jr          $ra
    // 0x80072984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80072984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Landfill_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072988: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007298C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80072990: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80072994: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072998: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007299C: lbu         $s0, 0x5($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0X5);
    // 0x800729A0: nop

    // 0x800729A4: beq         $s0, $zero, L_800729C4
    if (ctx->r16 == 0) {
        // 0x800729A8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800729C4;
    }
    // 0x800729A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800729AC: beq         $s0, $at, L_800729E0
    if (ctx->r16 == ctx->r1) {
        // 0x800729B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800729E0;
    }
    // 0x800729B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800729B4: beq         $s0, $at, L_80072A08
    if (ctx->r16 == ctx->r1) {
        // 0x800729B8: nop
    
            goto L_80072A08;
    }
    // 0x800729B8: nop

    // 0x800729BC: b           L_80072A24
    // 0x800729C0: nop

        goto L_80072A24;
    // 0x800729C0: nop

L_800729C4:
    // 0x800729C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800729C8: jal         0x80073AC4
    // 0x800729CC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    GarbageFx_Free(rdram, ctx);
        goto after_0;
    // 0x800729CC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x800729D0: jal         0x80073BA4
    // 0x800729D4: nop

    Garbage_FreeTexture(rdram, ctx);
        goto after_1;
    // 0x800729D4: nop

    after_1:
    // 0x800729D8: b           L_80072A3C
    // 0x800729DC: nop

        goto L_80072A3C;
    // 0x800729DC: nop

L_800729E0:
    // 0x800729E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800729E4: jal         0x80073AC4
    // 0x800729E8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    GarbageFx_Free(rdram, ctx);
        goto after_2;
    // 0x800729E8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_2:
    // 0x800729EC: jal         0x80073BA4
    // 0x800729F0: nop

    Garbage_FreeTexture(rdram, ctx);
        goto after_3;
    // 0x800729F0: nop

    after_3:
    // 0x800729F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800729F8: jal         0x800744C0
    // 0x800729FC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_800744C0(rdram, ctx);
        goto after_4;
    // 0x800729FC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_4:
    // 0x80072A00: b           L_80072A3C
    // 0x80072A04: nop

        goto L_80072A3C;
    // 0x80072A04: nop

L_80072A08:
    // 0x80072A08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80072A0C: jal         0x80073AC4
    // 0x80072A10: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    GarbageFx_Free(rdram, ctx);
        goto after_5;
    // 0x80072A10: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_5:
    // 0x80072A14: jal         0x80073BA4
    // 0x80072A18: nop

    Garbage_FreeTexture(rdram, ctx);
        goto after_6;
    // 0x80072A18: nop

    after_6:
    // 0x80072A1C: b           L_80072A3C
    // 0x80072A20: nop

        goto L_80072A3C;
    // 0x80072A20: nop

L_80072A24:
    // 0x80072A24: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072A28: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80072A2C: addiu       $a1, $a1, -0x25D4
    ctx->r5 = ADD32(ctx->r5, -0X25D4);
    // 0x80072A30: addiu       $a0, $a0, -0x25EC
    ctx->r4 = ADD32(ctx->r4, -0X25EC);
    // 0x80072A34: jal         0x8004A5A0
    // 0x80072A38: addiu       $a2, $zero, 0x133
    ctx->r6 = ADD32(0, 0X133);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_7;
    // 0x80072A38: addiu       $a2, $zero, 0x133
    ctx->r6 = ADD32(0, 0X133);
    after_7:
L_80072A3C:
    // 0x80072A3C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80072A40: nop

    // 0x80072A44: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80072A48: jal         0x8007E328
    // 0x80072A4C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_8;
    // 0x80072A4C: nop

    after_8:
    // 0x80072A50: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80072A54: nop

    // 0x80072A58: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x80072A5C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80072A60: nop

    // 0x80072A64: sb          $zero, 0x4($t9)
    MEM_B(0X4, ctx->r25) = 0;
    // 0x80072A68: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80072A6C: nop

    // 0x80072A70: sb          $zero, 0x5($t0)
    MEM_B(0X5, ctx->r8) = 0;
    // 0x80072A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072A78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80072A7C: jr          $ra
    // 0x80072A80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80072A80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Landfill_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072A84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80072A88: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80072A8C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80072A90: lw          $s0, -0x390($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X390);
    // 0x80072A94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072A98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80072A9C: lbu         $s1, 0x5($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X5);
    // 0x80072AA0: nop

    // 0x80072AA4: beq         $s1, $zero, L_80072AC4
    if (ctx->r17 == 0) {
        // 0x80072AA8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80072AC4;
    }
    // 0x80072AA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80072AAC: beq         $s1, $at, L_80072AD4
    if (ctx->r17 == ctx->r1) {
        // 0x80072AB0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80072AD4;
    }
    // 0x80072AB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80072AB4: beq         $s1, $at, L_80072AEC
    if (ctx->r17 == ctx->r1) {
        // 0x80072AB8: nop
    
            goto L_80072AEC;
    }
    // 0x80072AB8: nop

    // 0x80072ABC: b           L_80072AFC
    // 0x80072AC0: nop

        goto L_80072AFC;
    // 0x80072AC0: nop

L_80072AC4:
    // 0x80072AC4: jal         0x800735D8
    // 0x80072AC8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    GarbageFx_DrawBlocks(rdram, ctx);
        goto after_0;
    // 0x80072AC8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x80072ACC: b           L_80072B10
    // 0x80072AD0: nop

        goto L_80072B10;
    // 0x80072AD0: nop

L_80072AD4:
    // 0x80072AD4: jal         0x8007434C
    // 0x80072AD8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    GarbageFx_Draw(rdram, ctx);
        goto after_1;
    // 0x80072AD8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_1:
    // 0x80072ADC: jal         0x800735D8
    // 0x80072AE0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    GarbageFx_DrawBlocks(rdram, ctx);
        goto after_2;
    // 0x80072AE0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_2:
    // 0x80072AE4: b           L_80072B10
    // 0x80072AE8: nop

        goto L_80072B10;
    // 0x80072AE8: nop

L_80072AEC:
    // 0x80072AEC: jal         0x800735D8
    // 0x80072AF0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    GarbageFx_DrawBlocks(rdram, ctx);
        goto after_3;
    // 0x80072AF0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_3:
    // 0x80072AF4: b           L_80072B10
    // 0x80072AF8: nop

        goto L_80072B10;
    // 0x80072AF8: nop

L_80072AFC:
    // 0x80072AFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072B00: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80072B04: addiu       $a1, $a1, -0x25A4
    ctx->r5 = ADD32(ctx->r5, -0X25A4);
    // 0x80072B08: jal         0x80083560
    // 0x80072B0C: addiu       $a0, $a0, -0x25C8
    ctx->r4 = ADD32(ctx->r4, -0X25C8);
    debug_print_reason_routine(rdram, ctx);
        goto after_4;
    // 0x80072B0C: addiu       $a0, $a0, -0x25C8
    ctx->r4 = ADD32(ctx->r4, -0X25C8);
    after_4:
L_80072B10:
    // 0x80072B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072B14: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80072B18: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80072B1C: jr          $ra
    // 0x80072B20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80072B20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80072B24: nop

    // 0x80072B28: nop

    // 0x80072B2C: nop

;}

RECOMP_FUNC void Landfill_InitHoleColumn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072B30: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80072B34: divu        $zero, $a1, $at
    lo = S32(U32(ctx->r5) / U32(ctx->r1)); hi = S32(U32(ctx->r5) % U32(ctx->r1));
    // 0x80072B38: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80072B3C: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80072B40: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80072B44: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80072B48: mfhi        $t7
    ctx->r15 = hi;
    // 0x80072B4C: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x80072B50: jr          $ra
    // 0x80072B54: nop

    return;
    // 0x80072B54: nop

;}

RECOMP_FUNC void Landfill_RandomizeHoleColumn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072B58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072B5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80072B60: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80072B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072B68: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x80072B6C: jal         0x8006089C
    // 0x80072B70: nop

    Rand_Hash(rdram, ctx);
        goto after_0;
    // 0x80072B70: nop

    after_0:
    // 0x80072B74: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80072B78: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80072B7C: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    // 0x80072B80: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80072B84: nop

    // 0x80072B88: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80072B8C: nop

    // 0x80072B90: divu        $zero, $t9, $at
    lo = S32(U32(ctx->r25) / U32(ctx->r1)); hi = S32(U32(ctx->r25) % U32(ctx->r1));
    // 0x80072B94: mfhi        $t0
    ctx->r8 = hi;
    // 0x80072B98: sb          $t0, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r8;
    // 0x80072B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072BA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072BA4: jr          $ra
    // 0x80072BA8: nop

    return;
    // 0x80072BA8: nop

;}

RECOMP_FUNC void Landfill_ScrollUp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072BAC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80072BB0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80072BB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80072BB8: slti        $at, $s1, 0x13
    ctx->r1 = SIGNED(ctx->r17) < 0X13 ? 1 : 0;
    // 0x80072BBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80072BC0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80072BC4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80072BC8: beq         $at, $zero, L_80072C14
    if (ctx->r1 == 0) {
        // 0x80072BCC: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80072C14;
    }
    // 0x80072BCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_80072BD0:
    // 0x80072BD0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80072BD4: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80072BD8: beq         $at, $zero, L_80072C04
    if (ctx->r1 == 0) {
        // 0x80072BDC: nop
    
            goto L_80072C04;
    }
    // 0x80072BDC: nop

L_80072BE0:
    // 0x80072BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80072BE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80072BE8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80072BEC: jal         0x8006E0E8
    // 0x80072BF0: addiu       $a3, $s1, 0x1
    ctx->r7 = ADD32(ctx->r17, 0X1);
    BoardPieces_SwapCubes(rdram, ctx);
        goto after_0;
    // 0x80072BF0: addiu       $a3, $s1, 0x1
    ctx->r7 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x80072BF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80072BF8: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80072BFC: bne         $at, $zero, L_80072BE0
    if (ctx->r1 != 0) {
        // 0x80072C00: nop
    
            goto L_80072BE0;
    }
    // 0x80072C00: nop

L_80072C04:
    // 0x80072C04: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80072C08: slti        $at, $s1, 0x13
    ctx->r1 = SIGNED(ctx->r17) < 0X13 ? 1 : 0;
    // 0x80072C0C: bne         $at, $zero, L_80072BD0
    if (ctx->r1 != 0) {
        // 0x80072C10: nop
    
            goto L_80072BD0;
    }
    // 0x80072C10: nop

L_80072C14:
    // 0x80072C14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80072C18: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80072C1C: beq         $at, $zero, L_80072C74
    if (ctx->r1 == 0) {
        // 0x80072C20: nop
    
            goto L_80072C74;
    }
    // 0x80072C20: nop

L_80072C24:
    // 0x80072C24: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80072C28: nop

    // 0x80072C2C: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x80072C30: nop

    // 0x80072C34: beq         $t7, $s0, L_80072C64
    if (ctx->r15 == ctx->r16) {
        // 0x80072C38: nop
    
            goto L_80072C64;
    }
    // 0x80072C38: nop

    // 0x80072C3C: jal         0x80060814
    // 0x80072C40: nop

    Rand_Next(rdram, ctx);
        goto after_1;
    // 0x80072C40: nop

    after_1:
    // 0x80072C44: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80072C48: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80072C4C: divu        $zero, $s2, $at
    lo = S32(U32(ctx->r18) / U32(ctx->r1)); hi = S32(U32(ctx->r18) % U32(ctx->r1));
    // 0x80072C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80072C54: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80072C58: mfhi        $a2
    ctx->r6 = hi;
    // 0x80072C5C: jal         0x8006DE40
    // 0x80072C60: nop

    BoardP_SetCubeAt(rdram, ctx);
        goto after_2;
    // 0x80072C60: nop

    after_2:
L_80072C64:
    // 0x80072C64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80072C68: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80072C6C: bne         $at, $zero, L_80072C24
    if (ctx->r1 != 0) {
        // 0x80072C70: nop
    
            goto L_80072C24;
    }
    // 0x80072C70: nop

L_80072C74:
    // 0x80072C74: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80072C78: nop

    // 0x80072C7C: lbu         $t9, 0x2($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2);
    // 0x80072C80: nop

    // 0x80072C84: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80072C88: sb          $t0, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r8;
    // 0x80072C8C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80072C90: nop

    // 0x80072C94: lbu         $t2, 0x2($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2);
    // 0x80072C98: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x80072C9C: nop

    // 0x80072CA0: bne         $t2, $t3, L_80072CB0
    if (ctx->r10 != ctx->r11) {
        // 0x80072CA4: nop
    
            goto L_80072CB0;
    }
    // 0x80072CA4: nop

    // 0x80072CA8: jal         0x80072B58
    // 0x80072CAC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    Landfill_RandomizeHoleColumn(rdram, ctx);
        goto after_3;
    // 0x80072CAC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
L_80072CB0:
    // 0x80072CB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80072CB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80072CB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80072CBC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80072CC0: jr          $ra
    // 0x80072CC4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80072CC4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void Landfill_SetRowCell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072CC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072CCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80072CD0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80072CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072CD8: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80072CDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80072CE0: bne         $at, $zero, L_80072D00
    if (ctx->r1 != 0) {
        // 0x80072CE4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80072D00;
    }
    // 0x80072CE4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80072CE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072CEC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80072CF0: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x80072CF4: addiu       $a0, $a0, -0x2580
    ctx->r4 = ADD32(ctx->r4, -0X2580);
    // 0x80072CF8: jal         0x8004A5A0
    // 0x80072CFC: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_0;
    // 0x80072CFC: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_0:
L_80072D00:
    // 0x80072D00: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80072D04: lbu         $t9, 0x1F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1F);
    // 0x80072D08: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
    // 0x80072D0C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80072D10: sb          $t7, 0x1E($t0)
    MEM_B(0X1E, ctx->r8) = ctx->r15;
    // 0x80072D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072D1C: jr          $ra
    // 0x80072D20: nop

    return;
    // 0x80072D20: nop

;}

RECOMP_FUNC void Landfill_GetRowCell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072D24: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80072D28: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x80072D2C: lbu         $v0, 0x1E($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1E);
    // 0x80072D30: jr          $ra
    // 0x80072D34: nop

    return;
    // 0x80072D34: nop

;}

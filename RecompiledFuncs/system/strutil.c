#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void strutil_nextline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080A70: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80080A74: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80080A78: beq         $t6, $a1, L_80080AB0
    if (ctx->r14 == ctx->r5) {
        // 0x80080A7C: nop
    
            goto L_80080AB0;
    }
    // 0x80080A7C: nop

    // 0x80080A80: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80080A84: nop

    // 0x80080A88: beq         $t7, $zero, L_80080AB0
    if (ctx->r15 == 0) {
        // 0x80080A8C: nop
    
            goto L_80080AB0;
    }
    // 0x80080A8C: nop

L_80080A90:
    // 0x80080A90: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x80080A94: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80080A98: beq         $t8, $a1, L_80080AB0
    if (ctx->r24 == ctx->r5) {
        // 0x80080A9C: nop
    
            goto L_80080AB0;
    }
    // 0x80080A9C: nop

    // 0x80080AA0: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80080AA4: nop

    // 0x80080AA8: bne         $t9, $zero, L_80080A90
    if (ctx->r25 != 0) {
        // 0x80080AAC: nop
    
            goto L_80080A90;
    }
    // 0x80080AAC: nop

L_80080AB0:
    // 0x80080AB0: jr          $ra
    // 0x80080AB4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80080AB4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}

RECOMP_FUNC void strutil_linelen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080AB8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80080ABC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80080AC0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80080AC4: beq         $t6, $a1, L_80080AFC
    if (ctx->r14 == ctx->r5) {
        // 0x80080AC8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80080AFC;
    }
    // 0x80080AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80080ACC: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80080AD0: nop

    // 0x80080AD4: beq         $t7, $zero, L_80080AFC
    if (ctx->r15 == 0) {
        // 0x80080AD8: nop
    
            goto L_80080AFC;
    }
    // 0x80080AD8: nop

L_80080ADC:
    // 0x80080ADC: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x80080AE0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80080AE4: beq         $t8, $a1, L_80080AFC
    if (ctx->r24 == ctx->r5) {
        // 0x80080AE8: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80080AFC;
    }
    // 0x80080AE8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80080AEC: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80080AF0: nop

    // 0x80080AF4: bne         $t9, $zero, L_80080ADC
    if (ctx->r25 != 0) {
        // 0x80080AF8: nop
    
            goto L_80080ADC;
    }
    // 0x80080AF8: nop

L_80080AFC:
    // 0x80080AFC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80080B00: jr          $ra
    // 0x80080B04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80080B04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void strutil_linecnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080B08: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80080B0C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80080B10: beq         $t6, $zero, L_80080B3C
    if (ctx->r14 == 0) {
        // 0x80080B14: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80080B3C;
    }
    // 0x80080B14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80080B18:
    // 0x80080B18: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80080B1C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80080B20: bne         $t7, $at, L_80080B2C
    if (ctx->r15 != ctx->r1) {
        // 0x80080B24: nop
    
            goto L_80080B2C;
    }
    // 0x80080B24: nop

    // 0x80080B28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80080B2C:
    // 0x80080B2C: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x80080B30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80080B34: bne         $t8, $zero, L_80080B18
    if (ctx->r24 != 0) {
        // 0x80080B38: nop
    
            goto L_80080B18;
    }
    // 0x80080B38: nop

L_80080B3C:
    // 0x80080B3C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80080B40: jr          $ra
    // 0x80080B44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80080B44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80080B48: nop

    // 0x80080B4C: nop

;}

RECOMP_FUNC void func_80080B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080B50: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80080B54: lw          $t6, 0x32C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X32C8);
    // 0x80080B58: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80080B5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80080B60: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80080B64: beq         $t6, $at, L_80080B80
    if (ctx->r14 == ctx->r1) {
        // 0x80080B68: sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
            goto L_80080B80;
    }
    // 0x80080B68: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80080B6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80080B70: beq         $t6, $at, L_80080B80
    if (ctx->r14 == ctx->r1) {
        // 0x80080B74: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80080B80;
    }
    // 0x80080B74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80080B78: bne         $t6, $at, L_80080BDC
    if (ctx->r14 != ctx->r1) {
        // 0x80080B7C: nop
    
            goto L_80080BDC;
    }
    // 0x80080B7C: nop

L_80080B80:
    // 0x80080B80: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080B84: jal         0x8005BBFC
    // 0x80080B88: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    func_8005BBFC(rdram, ctx);
        goto after_0;
    // 0x80080B88: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_0:
    // 0x80080B8C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80080B90: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80080B94: lw          $a2, 0x214($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X214);
    // 0x80080B98: lw          $a1, 0x210($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X210);
    // 0x80080B9C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080BA0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80080BA4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80080BA8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80080BAC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80080BB0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80080BB4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80080BB8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80080BBC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80080BC0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80080BC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80080BC8: jal         0x80057460
    // 0x80080BCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_1;
    // 0x80080BCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80080BD0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080BD4: jal         0x8005BE40
    // 0x80080BD8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_2;
    // 0x80080BD8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_2:
L_80080BDC:
    // 0x80080BDC: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80080BE0: lw          $t1, 0x32C8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X32C8);
    // 0x80080BE4: nop

    // 0x80080BE8: sltiu       $at, $t1, 0x5
    ctx->r1 = ctx->r9 < 0X5 ? 1 : 0;
    // 0x80080BEC: beq         $at, $zero, L_80080E30
    if (ctx->r1 == 0) {
        // 0x80080BF0: nop
    
            goto L_80080E30;
    }
    // 0x80080BF0: nop

    // 0x80080BF4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80080BF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080BFC: addu        $at, $at, $t1
    gpr jr_addend_80080C08 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80080C00: lw          $t1, -0x15F0($at)
    ctx->r9 = ADD32(ctx->r1, -0X15F0);
    // 0x80080C04: nop

    // 0x80080C08: jr          $t1
    // 0x80080C0C: nop

    switch (jr_addend_80080C08 >> 2) {
        case 0: goto L_80080C10; break;
        case 1: goto L_80080D10; break;
        case 2: goto L_80080D40; break;
        case 3: goto L_80080D98; break;
        case 4: goto L_80080E18; break;
        default: switch_error(__func__, 0x80080C08, 0x800DEA10);
    }
    // 0x80080C0C: nop

L_80080C10:
    // 0x80080C10: jal         0x8004A34C
    // 0x80080C14: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_3;
    // 0x80080C14: nop

    after_3:
    // 0x80080C18: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80080C1C: lw          $t2, 0x32CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X32CC);
    // 0x80080C20: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80080C24: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80080C28: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x80080C2C: lw          $a1, 0x32C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X32C0);
    // 0x80080C30: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80080C34: jal         0x80074888
    // 0x80080C38: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_4;
    // 0x80080C38: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_4:
    // 0x80080C3C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80080C40: jal         0x8007E03C
    // 0x80080C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x80080C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80080C48: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80080C4C: lw          $t4, 0x32CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X32CC);
    // 0x80080C50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80080C54: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80080C58: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80080C5C: sw          $v0, 0x210($at)
    MEM_W(0X210, ctx->r1) = ctx->r2;
    // 0x80080C60: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x80080C64: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80080C68: lw          $a1, 0x210($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X210);
    // 0x80080C6C: lw          $a2, 0x32C0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X32C0);
    // 0x80080C70: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80080C74: jal         0x800746C0
    // 0x80080C78: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_6;
    // 0x80080C78: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_6:
    // 0x80080C7C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80080C80: lw          $t6, 0x32CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X32CC);
    // 0x80080C84: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80080C88: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80080C8C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80080C90: lw          $t8, 0x32C4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X32C4);
    // 0x80080C94: nop

    // 0x80080C98: beq         $t8, $zero, L_80080CF0
    if (ctx->r24 == 0) {
        // 0x80080C9C: nop
    
            goto L_80080CF0;
    }
    // 0x80080C9C: nop

    // 0x80080CA0: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80080CA4: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x80080CA8: jal         0x80074888
    // 0x80080CAC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_7;
    // 0x80080CAC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_7:
    // 0x80080CB0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80080CB4: jal         0x8007E03C
    // 0x80080CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x80080CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80080CBC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80080CC0: lw          $t9, 0x32CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X32CC);
    // 0x80080CC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80080CC8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80080CCC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80080CD0: sw          $v0, 0x214($at)
    MEM_W(0X214, ctx->r1) = ctx->r2;
    // 0x80080CD4: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x80080CD8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80080CDC: lw          $a1, 0x214($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X214);
    // 0x80080CE0: lw          $a2, 0x32C4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X32C4);
    // 0x80080CE4: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x80080CE8: jal         0x800746C0
    // 0x80080CEC: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_9;
    // 0x80080CEC: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    after_9:
L_80080CF0:
    // 0x80080CF0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80080CF4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80080CF8: jal         0x8007ECC8
    // 0x80080CFC: nop

    func_8007ECC8(rdram, ctx);
        goto after_10;
    // 0x80080CFC: nop

    after_10:
    // 0x80080D00: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80080D04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080D08: b           L_80080E30
    // 0x80080D0C: sw          $t1, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r9;
        goto L_80080E30;
    // 0x80080D0C: sw          $t1, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r9;
L_80080D10:
    // 0x80080D10: jal         0x8007EA2C
    // 0x80080D14: nop

    Gfx_DrawScreenFade1(rdram, ctx);
        goto after_11;
    // 0x80080D14: nop

    after_11:
    // 0x80080D18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80080D1C: bne         $v0, $at, L_80080E30
    if (ctx->r2 != ctx->r1) {
        // 0x80080D20: nop
    
            goto L_80080E30;
    }
    // 0x80080D20: nop

    // 0x80080D24: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80080D28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080D2C: sw          $t2, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r10;
    // 0x80080D30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80080D34: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x80080D38: b           L_80080E30
    // 0x80080D3C: sw          $t3, 0x218($at)
    MEM_W(0X218, ctx->r1) = ctx->r11;
        goto L_80080E30;
    // 0x80080D3C: sw          $t3, 0x218($at)
    MEM_W(0X218, ctx->r1) = ctx->r11;
L_80080D40:
    // 0x80080D40: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80080D44: lw          $t4, 0x218($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X218);
    // 0x80080D48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80080D4C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80080D50: beq         $t5, $zero, L_80080D78
    if (ctx->r13 == 0) {
        // 0x80080D54: sw          $t5, 0x218($at)
        MEM_W(0X218, ctx->r1) = ctx->r13;
            goto L_80080D78;
    }
    // 0x80080D54: sw          $t5, 0x218($at)
    MEM_W(0X218, ctx->r1) = ctx->r13;
    // 0x80080D58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80080D5C: addiu       $t6, $t6, -0x10D0
    ctx->r14 = ADD32(ctx->r14, -0X10D0);
    // 0x80080D60: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80080D64: nop

    // 0x80080D68: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x80080D6C: beq         $t8, $zero, L_80080E30
    if (ctx->r24 == 0) {
        // 0x80080D70: slti        $at, $t5, 0xF0
        ctx->r1 = SIGNED(ctx->r13) < 0XF0 ? 1 : 0;
            goto L_80080E30;
    }
    // 0x80080D70: slti        $at, $t5, 0xF0
    ctx->r1 = SIGNED(ctx->r13) < 0XF0 ? 1 : 0;
    // 0x80080D74: beq         $at, $zero, L_80080E30
    if (ctx->r1 == 0) {
        // 0x80080D78: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80080E30;
    }
L_80080D78:
    // 0x80080D78: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80080D7C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80080D80: jal         0x8007E9F8
    // 0x80080D84: nop

    func_8007E9F8(rdram, ctx);
        goto after_12;
    // 0x80080D84: nop

    after_12:
    // 0x80080D88: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80080D8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080D90: b           L_80080E30
    // 0x80080D94: sw          $t9, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r25;
        goto L_80080E30;
    // 0x80080D94: sw          $t9, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r25;
L_80080D98:
    // 0x80080D98: jal         0x8007E750
    // 0x80080D9C: nop

    Gfx_DrawScreenFade0(rdram, ctx);
        goto after_13;
    // 0x80080D9C: nop

    after_13:
    // 0x80080DA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80080DA4: bne         $v0, $at, L_80080E30
    if (ctx->r2 != ctx->r1) {
        // 0x80080DA8: nop
    
            goto L_80080E30;
    }
    // 0x80080DA8: nop

    // 0x80080DAC: jal         0x8004A34C
    // 0x80080DB0: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_14;
    // 0x80080DB0: nop

    after_14:
    // 0x80080DB4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80080DB8: lw          $a0, 0x214($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X214);
    // 0x80080DBC: jal         0x8007E328
    // 0x80080DC0: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_15;
    // 0x80080DC0: nop

    after_15:
    // 0x80080DC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80080DC8: lw          $a0, 0x210($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X210);
    // 0x80080DCC: jal         0x8007E328
    // 0x80080DD0: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_16;
    // 0x80080DD0: nop

    after_16:
    // 0x80080DD4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80080DD8: lw          $t0, 0x32CC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X32CC);
    // 0x80080DDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080DE0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80080DE4: sw          $t1, 0x32CC($at)
    MEM_W(0X32CC, ctx->r1) = ctx->r9;
    // 0x80080DE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80080DEC: bne         $t1, $at, L_80080E0C
    if (ctx->r9 != ctx->r1) {
        // 0x80080DF0: nop
    
            goto L_80080E0C;
    }
    // 0x80080DF0: nop

    // 0x80080DF4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80080DF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080DFC: jal         0x8007E750
    // 0x80080E00: sw          $t2, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r10;
    Gfx_DrawScreenFade0(rdram, ctx);
        goto after_17;
    // 0x80080E00: sw          $t2, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = ctx->r10;
    after_17:
    // 0x80080E04: b           L_80080E30
    // 0x80080E08: nop

        goto L_80080E30;
    // 0x80080E08: nop

L_80080E0C:
    // 0x80080E0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080E10: b           L_80080E30
    // 0x80080E14: sw          $zero, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = 0;
        goto L_80080E30;
    // 0x80080E14: sw          $zero, 0x32C8($at)
    MEM_W(0X32C8, ctx->r1) = 0;
L_80080E18:
    // 0x80080E18: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80080E1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080E20: sb          $t3, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r11;
    // 0x80080E24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080E28: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80080E2C: sb          $t4, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r12;
L_80080E30:
    // 0x80080E30: jal         0x800722E0
    // 0x80080E34: nop

    func_800722E0(rdram, ctx);
        goto after_18;
    // 0x80080E34: nop

    after_18:
    // 0x80080E38: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80080E3C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80080E40: jr          $ra
    // 0x80080E44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80080E44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80080E48: nop

    // 0x80080E4C: nop

;}

RECOMP_FUNC void strutil_lzo_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080E50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80080E54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80080E58: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80080E5C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80080E60: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80080E64: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80080E68: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80080E6C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80080E70: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80080E74: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80080E78: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80080E7C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80080E80: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80080E84: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80080E88: addiu       $a0, $zero, 0x1040
    ctx->r4 = ADD32(0, 0X1040);
    // 0x80080E8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80080E90: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80080E94: jal         0x80081D1C
    // 0x80080E98: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    __lzo_init2(rdram, ctx);
        goto after_0;
    // 0x80080E98: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x80080E9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80080EA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80080EA4: jr          $ra
    // 0x80080EA8: nop

    return;
    // 0x80080EA8: nop

;}

RECOMP_FUNC void func_80080EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080EAC: jr          $ra
    // 0x80080EB0: nop

    return;
    // 0x80080EB0: nop

;}

RECOMP_FUNC void func_80080EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080EB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80080EB8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80080EBC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80080EC0: jr          $ra
    // 0x80080EC4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x80080EC4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}

RECOMP_FUNC void strutil_lzo_decompress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080EC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80080ECC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80080ED0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80080ED4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80080ED8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80080EDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80080EE0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80080EE4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80080EE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80080EEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80080EF0: jal         0x800827EC
    // 0x80080EF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    lzo1x_decompress(rdram, ctx);
        goto after_0;
    // 0x80080EF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80080EF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80080EFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80080F00: jr          $ra
    // 0x80080F04: nop

    return;
    // 0x80080F04: nop

;}

RECOMP_FUNC void strutil_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080F08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80080F0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80080F10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080F14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80080F18: jal         0x8007E03C
    // 0x80080F1C: nop

    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80080F1C: nop

    after_0:
    // 0x80080F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80080F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80080F28: jr          $ra
    // 0x80080F2C: nop

    return;
    // 0x80080F2C: nop

;}

RECOMP_FUNC void strutil_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80080F34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80080F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80080F40: jal         0x8007E328
    // 0x80080F44: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x80080F44: nop

    after_0:
    // 0x80080F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80080F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80080F50: jr          $ra
    // 0x80080F54: nop

    return;
    // 0x80080F54: nop

    // 0x80080F58: nop

    // 0x80080F5C: nop

;}

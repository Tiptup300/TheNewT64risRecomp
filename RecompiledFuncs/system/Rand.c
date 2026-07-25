#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Rand_Next(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060814: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80060818: lw          $t6, -0x590($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X590);
    // 0x8006081C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80060820: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80060824: sw          $t7, -0x590($at)
    MEM_W(-0X590, ctx->r1) = ctx->r15;
    // 0x80060828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006082C: slti        $at, $a1, 0x20
    ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x80060830: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80060834: beq         $at, $zero, L_8006087C
    if (ctx->r1 == 0) {
        // 0x80060838: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8006087C;
    }
    // 0x80060838: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8006083C:
    // 0x8006083C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80060840: lw          $t8, -0x590($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X590);
    // 0x80060844: lui         $at, 0x8050
    ctx->r1 = S32(0X8050 << 16);
    // 0x80060848: srl         $t0, $t8, 29
    ctx->r8 = S32(U32(ctx->r24) >> 29);
    // 0x8006084C: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x80060850: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80060854: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80060858: xor         $t3, $t2, $at
    ctx->r11 = ctx->r10 ^ ctx->r1;
    // 0x8006085C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80060860: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80060864: sllv        $t5, $t4, $a1
    ctx->r13 = S32(ctx->r12 << (ctx->r5 & 31));
    // 0x80060868: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006086C: sw          $t3, -0x590($at)
    MEM_W(-0X590, ctx->r1) = ctx->r11;
    // 0x80060870: slti        $at, $a1, 0x20
    ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x80060874: bne         $at, $zero, L_8006083C
    if (ctx->r1 != 0) {
        // 0x80060878: or          $a0, $a0, $t5
        ctx->r4 = ctx->r4 | ctx->r13;
            goto L_8006083C;
    }
    // 0x80060878: or          $a0, $a0, $t5
    ctx->r4 = ctx->r4 | ctx->r13;
L_8006087C:
    // 0x8006087C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80060880: sw          $a0, -0x590($at)
    MEM_W(-0X590, ctx->r1) = ctx->r4;
    // 0x80060884: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80060888: jr          $ra
    // 0x8006088C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006088C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Rand_SetSeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060890: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80060894: jr          $ra
    // 0x80060898: sw          $a0, -0x590($at)
    MEM_W(-0X590, ctx->r1) = ctx->r4;
    return;
    // 0x80060898: sw          $a0, -0x590($at)
    MEM_W(-0X590, ctx->r1) = ctx->r4;
;}

RECOMP_FUNC void Rand_Hash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006089C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800608A0: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800608A4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800608A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800608AC: beq         $at, $zero, L_800608E8
    if (ctx->r1 == 0) {
        // 0x800608B0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800608E8;
    }
    // 0x800608B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800608B4:
    // 0x800608B4: srl         $t7, $a0, 29
    ctx->r15 = S32(U32(ctx->r4) >> 29);
    // 0x800608B8: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x800608BC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800608C0: or          $a0, $t6, $t8
    ctx->r4 = ctx->r14 | ctx->r24;
    // 0x800608C4: lui         $at, 0x8050
    ctx->r1 = S32(0X8050 << 16);
    // 0x800608C8: xor         $t9, $a0, $at
    ctx->r25 = ctx->r4 ^ ctx->r1;
    // 0x800608CC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800608D0: andi        $t0, $a0, 0x1
    ctx->r8 = ctx->r4 & 0X1;
    // 0x800608D4: sllv        $t1, $t0, $a2
    ctx->r9 = S32(ctx->r8 << (ctx->r6 & 31));
    // 0x800608D8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800608DC: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800608E0: bne         $at, $zero, L_800608B4
    if (ctx->r1 != 0) {
        // 0x800608E4: or          $a1, $a1, $t1
        ctx->r5 = ctx->r5 | ctx->r9;
            goto L_800608B4;
    }
    // 0x800608E4: or          $a1, $a1, $t1
    ctx->r5 = ctx->r5 | ctx->r9;
L_800608E8:
    // 0x800608E8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800608EC: jr          $ra
    // 0x800608F0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800608F0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void FUN_026900_800608f4_oneliner_shift6_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800608F4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800608F8: sra         $t6, $a0, 6
    ctx->r14 = S32(SIGNED(ctx->r4) >> 6);
    // 0x800608FC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80060900: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80060904: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80060908: lh          $v0, -0xD90($v0)
    ctx->r2 = MEM_H(ctx->r2, -0XD90);
    // 0x8006090C: jr          $ra
    // 0x80060910: nop

    return;
    // 0x80060910: nop

;}

RECOMP_FUNC void FUN_026900_80060914_oneliner_shift6_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060914: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80060918: addiu       $t6, $a0, 0x4000
    ctx->r14 = ADD32(ctx->r4, 0X4000);
    // 0x8006091C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80060920: sra         $t8, $t7, 6
    ctx->r24 = S32(SIGNED(ctx->r15) >> 6);
    // 0x80060924: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80060928: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006092C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80060930: lh          $v0, -0xD90($v0)
    ctx->r2 = MEM_H(ctx->r2, -0XD90);
    // 0x80060934: jr          $ra
    // 0x80060938: nop

    return;
    // 0x80060938: nop

;}

RECOMP_FUNC void FUN_026900_8006093c_rounds_floors_loops_1024t(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006093C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80060940: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80060944: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80060948: sltiu       $at, $s0, 0x400
    ctx->r1 = ctx->r16 < 0X400 ? 1 : 0;
    // 0x8006094C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80060950: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80060954: beq         $at, $zero, L_800609E8
    if (ctx->r1 == 0) {
        // 0x80060958: swc1        $f20, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
            goto L_800609E8;
    }
    // 0x80060958: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
L_8006095C:
    // 0x8006095C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80060960: bgez        $s0, L_80060978
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80060964: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80060978;
    }
    // 0x80060964: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060968: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006096C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80060970: nop

    // 0x80060974: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80060978:
    // 0x80060978: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006097C: lwc1        $f10, -0x2D40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2D40);
    // 0x80060980: lui         $at, 0x4400
    ctx->r1 = S32(0X4400 << 16);
    // 0x80060984: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80060988: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006098C: nop

    // 0x80060990: div.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80060994: jal         0x800B7B40
    // 0x80060998: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80060998: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8006099C: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x800609A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800609A4: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x800609A8: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800609AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800609B0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800609B4: nop

    // 0x800609B8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800609BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800609C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800609C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800609C8: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800609CC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800609D0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800609D4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800609D8: sh          $t7, -0xD90($at)
    MEM_H(-0XD90, ctx->r1) = ctx->r15;
    // 0x800609DC: sltiu       $at, $s0, 0x400
    ctx->r1 = ctx->r16 < 0X400 ? 1 : 0;
    // 0x800609E0: bne         $at, $zero, L_8006095C
    if (ctx->r1 != 0) {
        // 0x800609E4: nop
    
            goto L_8006095C;
    }
    // 0x800609E4: nop

L_800609E8:
    // 0x800609E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800609EC: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800609F0: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800609F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800609F8: jr          $ra
    // 0x800609FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800609FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void FUN_026C80_80060a00_fourliner_sets_arg0_e0123(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060A00: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80060A04: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80060A08: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80060A0C: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80060A10: sb          $a1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r5;
    // 0x80060A14: jr          $ra
    // 0x80060A18: sb          $a2, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r6;
    return;
    // 0x80060A18: sb          $a2, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r6;
;}

RECOMP_FUNC void FUN_026C80_80060a1c_twoliner_sets_arg0_e01(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060A1C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80060A20: jr          $ra
    // 0x80060A24: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    return;
    // 0x80060A24: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
;}

RECOMP_FUNC void FUN_026C80_80060a28_twelveliner_retbool(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060A28: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80060A2C: nop

    // 0x80060A30: bne         $t6, $zero, L_80060A44
    if (ctx->r14 != 0) {
        // 0x80060A34: nop
    
            goto L_80060A44;
    }
    // 0x80060A34: nop

    // 0x80060A38: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x80060A3C: jr          $ra
    // 0x80060A40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80060A40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060A44:
    // 0x80060A44: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80060A48: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x80060A4C: nop

    // 0x80060A50: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80060A54: bne         $at, $zero, L_80060A88
    if (ctx->r1 != 0) {
        // 0x80060A58: nop
    
            goto L_80060A88;
    }
    // 0x80060A58: nop

    // 0x80060A5C: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80060A60: lbu         $t2, 0x2($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X2);
    // 0x80060A64: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x80060A68: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x80060A6C: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x80060A70: nop

    // 0x80060A74: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80060A78: beq         $at, $zero, L_80060A98
    if (ctx->r1 == 0) {
        // 0x80060A7C: nop
    
            goto L_80060A98;
    }
    // 0x80060A7C: nop

    // 0x80060A80: jr          $ra
    // 0x80060A84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80060A84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060A88:
    // 0x80060A88: lbu         $t3, 0x1($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X1);
    // 0x80060A8C: nop

    // 0x80060A90: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x80060A94: sb          $t4, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r12;
L_80060A98:
    // 0x80060A98: lbu         $t5, 0x1($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X1);
    // 0x80060A9C: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x80060AA0: nop

    // 0x80060AA4: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80060AA8: bne         $at, $zero, L_80060AC8
    if (ctx->r1 != 0) {
        // 0x80060AAC: nop
    
            goto L_80060AC8;
    }
    // 0x80060AAC: nop

    // 0x80060AB0: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x80060AB4: lbu         $t8, 0x3($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X3);
    // 0x80060AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060ABC: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80060AC0: jr          $ra
    // 0x80060AC4: sb          $t9, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r25;
    return;
    // 0x80060AC4: sb          $t9, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r25;
L_80060AC8:
    // 0x80060AC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060ACC: jr          $ra
    // 0x80060AD0: nop

    return;
    // 0x80060AD0: nop

;}

RECOMP_FUNC void FUN_026C80_80060ad4_oneliner_calls_fun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060AD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060AD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80060ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060AE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80060AE4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80060AE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80060AEC: jal         0x80060B04
    // 0x80060AF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    FUN_026C80_80060b04_twelveliner_loops_32t(rdram, ctx);
        goto after_0;
    // 0x80060AF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80060AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060AFC: jr          $ra
    // 0x80060B00: nop

    return;
    // 0x80060B00: nop

;}

RECOMP_FUNC void FUN_026C80_80060b04_twelveliner_loops_32t(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060B04: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80060B08: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80060B0C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80060B10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060B14: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80060B18: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80060B1C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80060B20: sltiu       $at, $s2, 0x20
    ctx->r1 = ctx->r18 < 0X20 ? 1 : 0;
    // 0x80060B24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80060B28: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80060B2C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80060B30: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80060B34: beq         $at, $zero, L_80060B78
    if (ctx->r1 == 0) {
        // 0x80060B38: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_80060B78;
    }
    // 0x80060B38: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80060B3C:
    // 0x80060B3C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80060B40: nop

    // 0x80060B44: and         $t7, $t6, $s1
    ctx->r15 = ctx->r14 & ctx->r17;
    // 0x80060B48: beq         $t7, $zero, L_80060B60
    if (ctx->r15 == 0) {
        // 0x80060B4C: nop
    
            goto L_80060B60;
    }
    // 0x80060B4C: nop

    // 0x80060B50: lbu         $a1, 0x43($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X43);
    // 0x80060B54: lbu         $a2, 0x47($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X47);
    // 0x80060B58: jal         0x80060A00
    // 0x80060B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    FUN_026C80_80060a00_fourliner_sets_arg0_e0123(rdram, ctx);
        goto after_0;
    // 0x80060B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_80060B60:
    // 0x80060B60: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80060B64: sltiu       $at, $s2, 0x20
    ctx->r1 = ctx->r18 < 0X20 ? 1 : 0;
    // 0x80060B68: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    // 0x80060B6C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80060B70: bne         $at, $zero, L_80060B3C
    if (ctx->r1 != 0) {
        // 0x80060B74: or          $s1, $t8, $zero
        ctx->r17 = ctx->r24 | 0;
            goto L_80060B3C;
    }
    // 0x80060B74: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
L_80060B78:
    // 0x80060B78: lbu         $t9, 0x47($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X47);
    // 0x80060B7C: nop

    // 0x80060B80: beq         $t9, $zero, L_80060BA4
    if (ctx->r25 == 0) {
        // 0x80060B84: nop
    
            goto L_80060BA4;
    }
    // 0x80060B84: nop

    // 0x80060B88: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80060B8C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80060B90: lw          $t1, 0x80($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X80);
    // 0x80060B94: nop

    // 0x80060B98: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x80060B9C: b           L_80060BBC
    // 0x80060BA0: sw          $t3, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->r11;
        goto L_80060BBC;
    // 0x80060BA0: sw          $t3, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->r11;
L_80060BA4:
    // 0x80060BA4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80060BA8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80060BAC: lw          $t5, 0x80($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X80);
    // 0x80060BB0: nor         $t7, $t6, $zero
    ctx->r15 = ~(ctx->r14 | 0);
    // 0x80060BB4: and         $t8, $t5, $t7
    ctx->r24 = ctx->r13 & ctx->r15;
    // 0x80060BB8: sw          $t8, 0x80($t4)
    MEM_W(0X80, ctx->r12) = ctx->r24;
L_80060BBC:
    // 0x80060BBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80060BC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060BC4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80060BC8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80060BCC: jr          $ra
    // 0x80060BD0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80060BD0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void FUN_026C80_GU_or_ControllerRepeat_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060BD4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80060BD8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80060BDC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80060BE0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80060BE4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80060BE8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80060BEC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80060BF0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80060BF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060BF8: sw          $zero, 0x84($t6)
    MEM_W(0X84, ctx->r14) = 0;
    // 0x80060BFC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80060C00: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80060C04: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x80060C08: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80060C0C: sltiu       $at, $s2, 0x20
    ctx->r1 = ctx->r18 < 0X20 ? 1 : 0;
    // 0x80060C10: and         $t0, $t7, $t9
    ctx->r8 = ctx->r15 & ctx->r25;
    // 0x80060C14: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80060C18: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80060C1C: beq         $at, $zero, L_80060C88
    if (ctx->r1 == 0) {
        // 0x80060C20: or          $s0, $t6, $zero
        ctx->r16 = ctx->r14 | 0;
            goto L_80060C88;
    }
    // 0x80060C20: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_80060C24:
    // 0x80060C24: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80060C28: nop

    // 0x80060C2C: and         $t2, $t1, $s1
    ctx->r10 = ctx->r9 & ctx->r17;
    // 0x80060C30: beq         $t2, $zero, L_80060C68
    if (ctx->r10 == 0) {
        // 0x80060C34: nop
    
            goto L_80060C68;
    }
    // 0x80060C34: nop

    // 0x80060C38: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80060C3C: jal         0x80060A28
    // 0x80060C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    FUN_026C80_80060a28_twelveliner_retbool(rdram, ctx);
        goto after_0;
    // 0x80060C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80060C44: beq         $v0, $zero, L_80060C70
    if (ctx->r2 == 0) {
        // 0x80060C48: nop
    
            goto L_80060C70;
    }
    // 0x80060C48: nop

    // 0x80060C4C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80060C50: nop

    // 0x80060C54: lw          $t4, 0x84($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X84);
    // 0x80060C58: nop

    // 0x80060C5C: or          $t5, $t4, $s1
    ctx->r13 = ctx->r12 | ctx->r17;
    // 0x80060C60: b           L_80060C70
    // 0x80060C64: sw          $t5, 0x84($t3)
    MEM_W(0X84, ctx->r11) = ctx->r13;
        goto L_80060C70;
    // 0x80060C64: sw          $t5, 0x84($t3)
    MEM_W(0X84, ctx->r11) = ctx->r13;
L_80060C68:
    // 0x80060C68: jal         0x80060A1C
    // 0x80060C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    FUN_026C80_80060a1c_twoliner_sets_arg0_e01(rdram, ctx);
        goto after_1;
    // 0x80060C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80060C70:
    // 0x80060C70: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80060C74: sltiu       $at, $s2, 0x20
    ctx->r1 = ctx->r18 < 0X20 ? 1 : 0;
    // 0x80060C78: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
    // 0x80060C7C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80060C80: bne         $at, $zero, L_80060C24
    if (ctx->r1 != 0) {
        // 0x80060C84: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_80060C24;
    }
    // 0x80060C84: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
L_80060C88:
    // 0x80060C88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80060C8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060C90: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80060C94: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80060C98: jr          $ra
    // 0x80060C9C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80060C9C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void FUN_026C80_nineliner_loops_32t(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060CA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80060CA4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80060CA8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80060CAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80060CB0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80060CB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060CB8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80060CBC: sltiu       $at, $s1, 0x20
    ctx->r1 = ctx->r17 < 0X20 ? 1 : 0;
    // 0x80060CC0: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80060CC4: beq         $at, $zero, L_80060CE4
    if (ctx->r1 == 0) {
        // 0x80060CC8: sw          $zero, 0x84($t6)
        MEM_W(0X84, ctx->r14) = 0;
            goto L_80060CE4;
    }
    // 0x80060CC8: sw          $zero, 0x84($t6)
    MEM_W(0X84, ctx->r14) = 0;
L_80060CCC:
    // 0x80060CCC: jal         0x80060A1C
    // 0x80060CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    FUN_026C80_80060a1c_twoliner_sets_arg0_e01(rdram, ctx);
        goto after_0;
    // 0x80060CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80060CD4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80060CD8: sltiu       $at, $s1, 0x20
    ctx->r1 = ctx->r17 < 0X20 ? 1 : 0;
    // 0x80060CDC: bne         $at, $zero, L_80060CCC
    if (ctx->r1 != 0) {
        // 0x80060CE0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80060CCC;
    }
    // 0x80060CE0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80060CE4:
    // 0x80060CE4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80060CE8: nop

    // 0x80060CEC: sw          $zero, 0x88($t7)
    MEM_W(0X88, ctx->r15) = 0;
    // 0x80060CF0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80060CF4: nop

    // 0x80060CF8: sw          $zero, 0x8C($t8)
    MEM_W(0X8C, ctx->r24) = 0;
    // 0x80060CFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060D00: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80060D04: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80060D08: jr          $ra
    // 0x80060D0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80060D0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_80060D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060D10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060D14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80060D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060D1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80060D20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80060D24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80060D28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80060D2C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80060D30: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80060D34: sw          $t6, 0x288($at)
    MEM_W(0X288, ctx->r1) = ctx->r14;
    // 0x80060D38: addiu       $a1, $a1, -0x580
    ctx->r5 = ADD32(ctx->r5, -0X580);
    // 0x80060D3C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80060D40: jal         0x800B7D00
    // 0x80060D44: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    bcopy_recomp(rdram, ctx);
        goto after_0;
    // 0x80060D44: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80060D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060D4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060D50: jr          $ra
    // 0x80060D54: nop

    return;
    // 0x80060D54: nop

;}

RECOMP_FUNC void func_80060D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060D58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060D5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80060D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060D64: lui         $a0, 0x8
    ctx->r4 = S32(0X8 << 16);
    // 0x80060D68: jal         0x800B6A90
    // 0x80060D6C: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80060D6C: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    after_0:
    // 0x80060D70: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80060D74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80060D78: bne         $t6, $at, L_80060DC4
    if (ctx->r14 != ctx->r1) {
        // 0x80060D7C: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80060DC4;
    }
    // 0x80060D7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80060D80: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80060D84: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80060D88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80060D8C: bne         $t7, $at, L_80060DA0
    if (ctx->r15 != ctx->r1) {
        // 0x80060D90: nop
    
            goto L_80060DA0;
    }
    // 0x80060D90: nop

    // 0x80060D94: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80060D98: addiu       $t8, $t8, -0x6A90
    ctx->r24 = ADD32(ctx->r24, -0X6A90);
    // 0x80060D9C: sw          $zero, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = 0;
L_80060DA0:
    // 0x80060DA0: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80060DA4: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x80060DA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80060DAC: bne         $t9, $at, L_80060E14
    if (ctx->r25 != ctx->r1) {
        // 0x80060DB0: nop
    
            goto L_80060E14;
    }
    // 0x80060DB0: nop

    // 0x80060DB4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80060DB8: addiu       $t0, $t0, -0x6A90
    ctx->r8 = ADD32(ctx->r8, -0X6A90);
    // 0x80060DBC: b           L_80060E14
    // 0x80060DC0: sw          $zero, 0x980($t0)
    MEM_W(0X980, ctx->r8) = 0;
        goto L_80060E14;
    // 0x80060DC0: sw          $zero, 0x980($t0)
    MEM_W(0X980, ctx->r8) = 0;
L_80060DC4:
    // 0x80060DC4: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80060DC8: lw          $t1, 0x300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X300);
    // 0x80060DCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80060DD0: bne         $t1, $at, L_80060DEC
    if (ctx->r9 != ctx->r1) {
        // 0x80060DD4: nop
    
            goto L_80060DEC;
    }
    // 0x80060DD4: nop

    // 0x80060DD8: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80060DDC: lw          $t2, 0x284($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X284);
    // 0x80060DE0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80060DE4: addiu       $t3, $t3, -0x6A90
    ctx->r11 = ADD32(ctx->r11, -0X6A90);
    // 0x80060DE8: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
L_80060DEC:
    // 0x80060DEC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80060DF0: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x80060DF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80060DF8: bne         $t4, $at, L_80060E14
    if (ctx->r12 != ctx->r1) {
        // 0x80060DFC: nop
    
            goto L_80060E14;
    }
    // 0x80060DFC: nop

    // 0x80060E00: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80060E04: lw          $t5, 0x284($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X284);
    // 0x80060E08: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80060E0C: addiu       $t6, $t6, -0x6A90
    ctx->r14 = ADD32(ctx->r14, -0X6A90);
    // 0x80060E10: sw          $t5, 0x980($t6)
    MEM_W(0X980, ctx->r14) = ctx->r13;
L_80060E14:
    // 0x80060E14: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80060E18: jal         0x800B6A90
    // 0x80060E1C: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80060E1C: nop

    after_1:
    // 0x80060E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060E24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060E28: jr          $ra
    // 0x80060E2C: nop

    return;
    // 0x80060E2C: nop

;}
